/*
 * jdhuff.c
 *
 * Copyright (C) 1991-1995, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains Huffman entropy decoding routines.
 *
 * Much of the complexity here has to do with supporting input suspension.
 * If the data source module demands suspension, we want to be able to back
 * up to the start of the current MCU.  To do this, we copy state variables
 * into local working storage, and update them back to the permanent
 * storage only upon successful completion of an MCU.
 */

#define JPEG_INTERNALS
#include "jdhuff.h" /* Declarations shared with jdphuff.c */
#include "jinclude.h"
#include "jpeglib.h"

/*
 * Expanded entropy decoder object for Huffman decoding.
 *
 * The savable_state subrecord contains fields that change within an MCU,
 * but must not be updated permanently until we complete the MCU.
 */

typedef struct
{
  int last_dc_val[MAX_COMPS_IN_SCAN]; /* last DC coef for each component */
} savable_state;

/* This macro is to work around compilers with missing or broken
 * structure assignment.  You'll need to fix this code if you have
 * such a compiler and you change MAX_COMPS_IN_SCAN.
 */

#ifndef NO_STRUCT_ASSIGN
#define ASSIGN_STATE(dest, src) ((dest) = (src))
#else
#if MAX_COMPS_IN_SCAN == 4
#define ASSIGN_STATE(dest, src)                                                \
  ((dest).last_dc_val[0] = (src).last_dc_val[0],                               \
   (dest).last_dc_val[1] = (src).last_dc_val[1],                               \
   (dest).last_dc_val[2] = (src).last_dc_val[2],                               \
   (dest).last_dc_val[3] = (src).last_dc_val[3])
#endif
#endif

typedef struct
{
  struct jpeg_entropy_decoder pub; /* public fields */

  /* These fields are loaded into local variables at start of each MCU.
   * In case of suspension, we exit WITHOUT updating them.
   */
  bitread_perm_state bitstate; /* Bit buffer at start of MCU */
  savable_state saved;         /* Other state at start of MCU */

  /* These fields are NOT loaded into local working state. */
  unsigned int restarts_to_go; /* MCUs left in this restart interval */

  /* Pointers to derived tables (these workspaces have image lifespan) */
  d_derived_tbl *dc_derived_tbls[NUM_HUFF_TBLS];
  d_derived_tbl *ac_derived_tbls[NUM_HUFF_TBLS];
} huff_entropy_decoder;

typedef huff_entropy_decoder *huff_entropy_ptr;

/*
 * Initialize for a Huffman-compressed scan.
 */

METHODDEF void start_pass_huff_decoder(j_decompress_ptr cinfo)
{
  huff_entropy_ptr entropy = (huff_entropy_ptr)cinfo->entropy;
  int ci, dctbl, actbl;
  jpeg_component_info *compptr;

  /* Check that the scan parameters Ss, Se, Ah/Al are OK for sequential JPEG.
   * This ought to be an error condition, but we make it a warning because
   * there are some baseline files out there with all zeroes in these bytes.
   */
  if (cinfo->Ss != 0 || cinfo->Se != DCTSIZE2 - 1 || cinfo->Ah != 0 ||
      cinfo->Al != 0)
    WARNMS(cinfo, JWRN_NOT_SEQUENTIAL);

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
      compptr = cinfo->cur_comp_info[ci];
      dctbl = compptr->dc_tbl_no;
      actbl = compptr->ac_tbl_no;
      /* Make sure requested tables are present */
      if (dctbl < 0 || dctbl >= NUM_HUFF_TBLS ||
          cinfo->dc_huff_tbl_ptrs[dctbl] == NULL)
        ERREXIT1(cinfo, JERR_NO_HUFF_TABLE, dctbl);
      if (actbl < 0 || actbl >= NUM_HUFF_TBLS ||
          cinfo->ac_huff_tbl_ptrs[actbl] == NULL)
        ERREXIT1(cinfo, JERR_NO_HUFF_TABLE, actbl);
      /* Compute derived values for Huffman tables */
      /* We may do this more than once for a table, but it's not expensive */
      jpeg_make_d_derived_tbl(cinfo, cinfo->dc_huff_tbl_ptrs[dctbl],
                              &entropy->dc_derived_tbls[dctbl]);
      jpeg_make_d_derived_tbl(cinfo, cinfo->ac_huff_tbl_ptrs[actbl],
                              &entropy->ac_derived_tbls[actbl]);
      /* Initialize DC predictions to 0 */
      entropy->saved.last_dc_val[ci] = 0;
    }

  /* Initialize bitread state variables */
  entropy->bitstate.bits_left = 0;
  entropy->bitstate.get_buffer = 0; /* unnecessary, but keeps Purify quiet */
  entropy->bitstate.printed_eod = FALSE;

  /* Initialize restart counter */
  entropy->restarts_to_go = cinfo->restart_interval;
}

/*
 * Compute the derived values for a Huffman table.
 * Note this is also used by jdphuff.c.
 */

GLOBAL void jpeg_make_d_derived_tbl(j_decompress_ptr cinfo, JHUFF_TBL *htbl,
                                    d_derived_tbl **pdtbl)
{
  d_derived_tbl *dtbl;
  int p, i, l, si;
  int lookbits, ctr;
  char huffsize[257];
  unsigned int huffcode[257];
  unsigned int code;

  /* Allocate a workspace if we haven't already done so. */
  if (*pdtbl == NULL)
    *pdtbl = (d_derived_tbl *)(*cinfo->mem->alloc_small)(
        (j_common_ptr)cinfo, JPOOL_IMAGE, SIZEOF(d_derived_tbl));
  dtbl = *pdtbl;
  dtbl->pub = htbl; /* fill in back link */

  /* Figure C.1: make table of Huffman code length for each symbol */
  /* Note that this is in code-length order. */

  p = 0;
    for (l = 1; l <= 16; l++) {
      for (i = 1; i <= (int)htbl->bits[l]; i++)
        huffsize[p++] = (char)l;
    }
  huffsize[p] = 0;

  /* Figure C.2: generate the codes themselves */
  /* Note that this is in code-length order. */

  code = 0;
  si = huffsize[0];
  p = 0;
    while (huffsize[p]) {
        while (((int)huffsize[p]) == si) {
          huffcode[p++] = code;
          code++;
        }
      code <<= 1;
      si++;
    }

  /* Figure F.15: generate decoding tables for bit-sequential decoding */

  p = 0;
    for (l = 1; l <= 16; l++) {
        if (htbl->bits[l]) {
          dtbl->valptr[l] =
              p; /* huffval[] index of 1st symbol of code length l */
          dtbl->mincode[l] = huffcode[p]; /* minimum code of length l */
          p += htbl->bits[l];
          dtbl->maxcode[l] = huffcode[p - 1]; /* maximum code of length l */
        }
        else {
          dtbl->maxcode[l] = -1; /* -1 if no codes of this length */
        }
    }
  dtbl->maxcode[17] = 0xFFFFFL; /* ensures jpeg_huff_decode terminates */

  /* Compute lookahead tables to speed up decoding.
   * First we set all the table entries to 0, indicating "too long";
   * then we iterate through the Huffman codes that are short enough and
   * fill in all the entries that correspond to bit sequences starting
   * with that code.
   */

  MEMZERO(dtbl->look_nbits, SIZEOF(dtbl->look_nbits));

  p = 0;
    for (l = 1; l <= HUFF_LOOKAHEAD; l++) {
        for (i = 1; i <= (int)htbl->bits[l]; i++, p++) {
          /* l = current code's length, p = its index in huffcode[] & huffval[].
           */
          /* Generate left-justified code followed by all possible bit sequences
           */
          lookbits = huffcode[p] << (HUFF_LOOKAHEAD - l);
            for (ctr = 1 << (HUFF_LOOKAHEAD - l); ctr > 0; ctr--) {
              dtbl->look_nbits[lookbits] = l;
              dtbl->look_sym[lookbits] = htbl->huffval[p];
              lookbits++;
            }
        }
    }
}

/*
 * Out-of-line code for bit fetching (shared with jdphuff.c).
 * See jdhuff.h for info about usage.
 * Note: current values of get_buffer and bits_left are passed as parameters,
 * but are returned in the corresponding fields of the state struct.
 *
 * On most machines MIN_GET_BITS should be 25 to allow the full 32-bit width
 * of get_buffer to be used.  (On machines with wider words, an even larger
 * buffer could be used.)  However, on some machines 32-bit shifts are
 * quite slow and take time proportional to the number of places shifted.
 * (This is true with most PC compilers, for instance.)  In this case it may
 * be a win to set MIN_GET_BITS to the minimum value of 15.  This reduces the
 * average shift distance at the cost of more calls to jpeg_fill_bit_buffer.
 */

#ifdef SLOW_SHIFT_32
#define MIN_GET_BITS 15 /* minimum allowable value */
#else
#define MIN_GET_BITS (BIT_BUF_SIZE - 7)
#endif

GLOBAL boolean jpeg_fill_bit_buffer(bitread_working_state *state,
                                    register bit_buf_type get_buffer,
                                    register int bits_left, int nbits)
/* Load up the bit buffer to a depth of at least nbits */
{
  /* Copy heavily used state fields into locals (hopefully registers) */
  register const JOCTET *next_input_byte = state->next_input_byte;
  register size_t bytes_in_buffer = state->bytes_in_buffer;
  register int c;

  /* Attempt to load at least MIN_GET_BITS bits into get_buffer. */
  /* (It is assumed that no request will be for more than that many bits.) */

    while (bits_left < MIN_GET_BITS) {
      /* Attempt to read a byte */
      if (state->unread_marker != 0)
        goto no_more_data; /* can't advance past a marker */

        if (bytes_in_buffer == 0) {
          if (!(*state->cinfo->src->fill_input_buffer)(state->cinfo))
            return FALSE;
          next_input_byte = state->cinfo->src->next_input_byte;
          bytes_in_buffer = state->cinfo->src->bytes_in_buffer;
        }
      bytes_in_buffer--;
      c = GETJOCTET(*next_input_byte++);

        /* If it's 0xFF, check and discard stuffed zero byte */
        if (c == 0xFF) {
            do {
                if (bytes_in_buffer == 0) {
                  if (!(*state->cinfo->src->fill_input_buffer)(state->cinfo))
                    return FALSE;
                  next_input_byte = state->cinfo->src->next_input_byte;
                  bytes_in_buffer = state->cinfo->src->bytes_in_buffer;
                }
              bytes_in_buffer--;
              c = GETJOCTET(*next_input_byte++);
            }
          while (c == 0xFF);

            if (c == 0) {
              /* Found FF/00, which represents an FF data byte */
              c = 0xFF;
            }
            else {
              /* Oops, it's actually a marker indicating end of compressed data.
               */
              /* Better put it back for use later */
              state->unread_marker = c;

            no_more_data:
              /* There should be enough bits still left in the data segment; */
              /* if so, just break out of the outer while loop. */
              if (bits_left >= nbits)
                break;
                /* Uh-oh.  Report corrupted data to user and stuff zeroes into
                 * the data stream, so that we can produce some kind of image.
                 * Note that this code will be repeated for each byte demanded
                 * for the rest of the segment.  We use a nonvolatile flag to
                 * ensure that only one warning message appears.
                 */
                if (!*(state->printed_eod_ptr)) {
                  WARNMS(state->cinfo, JWRN_HIT_MARKER);
                  *(state->printed_eod_ptr) = TRUE;
                }
              c = 0; /* insert a zero byte into bit buffer */
            }
        }

      /* OK, load c into get_buffer */
      get_buffer = (get_buffer << 8) | c;
      bits_left += 8;
    }

  /* Unload the local registers */
  state->next_input_byte = next_input_byte;
  state->bytes_in_buffer = bytes_in_buffer;
  state->get_buffer = get_buffer;
  state->bits_left = bits_left;

  return TRUE;
}

/*
 * Out-of-line code for Huffman code decoding.
 * See jdhuff.h for info about usage.
 */

GLOBAL int jpeg_huff_decode(bitread_working_state *state,
                            register bit_buf_type get_buffer,
                            register int bits_left, d_derived_tbl *htbl,
                            int min_bits)
{
  register int l = min_bits;
  register INT32 code;

  /* HUFF_DECODE has determined that the code is at least min_bits */
  /* bits long, so fetch that many bits in one swoop. */

  CHECK_BIT_BUFFER(*state, l, return -1);
  code = GET_BITS(l);

  /* Collect the rest of the Huffman code one bit at a time. */
  /* This is per Figure F.16 in the JPEG spec. */

    while (code > htbl->maxcode[l]) {
      code <<= 1;
      CHECK_BIT_BUFFER(*state, 1, return -1);
      code |= GET_BITS(1);
      l++;
    }

  /* Unload the local registers */
  state->get_buffer = get_buffer;
  state->bits_left = bits_left;

  /* With garbage input we may reach the sentinel value l = 17. */

    if (l > 16) {
      WARNMS(state->cinfo, JWRN_HUFF_BAD_CODE);
      return 0; /* fake a zero as the safest result */
    }

  return htbl->pub->huffval[htbl->valptr[l] + ((int)(code - htbl->mincode[l]))];
}

/*
 * Figure F.12: extend sign bit.
 * On some machines, a shift and add will be faster than a table lookup.
 */

#ifdef AVOID_TABLES

#define HUFF_EXTEND(x, s)                                                      \
  ((x) < (1 << ((s)-1)) ? (x) + (((-1) << (s)) + 1) : (x))

#else

#define HUFF_EXTEND(x, s) ((x) < extend_test[s] ? (x) + extend_offset[s] : (x))

static const int extend_test[16] = /* entry n is 2**(n-1) */
    {0,      0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040,
     0x0080, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000};

static const int extend_offset[16] = /* entry n is (-1 << n) + 1 */
    {0,
     ((-1) << 1) + 1,
     ((-1) << 2) + 1,
     ((-1) << 3) + 1,
     ((-1) << 4) + 1,
     ((-1) << 5) + 1,
     ((-1) << 6) + 1,
     ((-1) << 7) + 1,
     ((-1) << 8) + 1,
     ((-1) << 9) + 1,
     ((-1) << 10) + 1,
     ((-1) << 11) + 1,
     ((-1) << 12) + 1,
     ((-1) << 13) + 1,
     ((-1) << 14) + 1,
     ((-1) << 15) + 1};

#endif /* AVOID_TABLES */

/*
 * Check for a restart marker & resynchronize decoder.
 * Returns FALSE if must suspend.
 */

LOCAL boolean process_restart(j_decompress_ptr cinfo)
{
  huff_entropy_ptr entropy = (huff_entropy_ptr)cinfo->entropy;
  int ci;

  /* Throw away any unused bits remaining in bit buffer; */
  /* include any full bytes in next_marker's count of discarded bytes */
  cinfo->marker->discarded_bytes += entropy->bitstate.bits_left / 8;
  entropy->bitstate.bits_left = 0;

  /* Advance past the RSTn marker */
  if (!(*cinfo->marker->read_restart_marker)(cinfo))
    return FALSE;

  /* Re-initialize DC predictions to 0 */
  for (ci = 0; ci < cinfo->comps_in_scan; ci++)
    entropy->saved.last_dc_val[ci] = 0;

  /* Reset restart counter */
  entropy->restarts_to_go = cinfo->restart_interval;

  /* Next segment can get another out-of-data warning */
  entropy->bitstate.printed_eod = FALSE;

  return TRUE;
}

/*
 * Decode and return one MCU's worth of Huffman-compressed coefficients.
 * The coefficients are reordered from zigzag order into natural array order,
 * but are not dequantized.
 *
 * The i'th block of the MCU is stored into the block pointed to by
 * MCU_data[i].  WE ASSUME THIS AREA HAS BEEN ZEROED BY THE CALLER.
 * (Wholesale zeroing is usually a little faster than retail...)
 *
 * Returns FALSE if data source requested suspension.  In that case no
 * changes have been made to permanent state.  (Exception: some output
 * coefficients may already have been assigned.  This is harmless for
 * this module, since we'll just re-assign them on the next call.)
 */

METHODDEF boolean decode_mcu(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
  huff_entropy_ptr entropy = (huff_entropy_ptr)cinfo->entropy;
  register int s, k, r;
  int blkn, ci;
  JBLOCKROW block;
  BITREAD_STATE_VARS;
  savable_state state;
  d_derived_tbl *dctbl;
  d_derived_tbl *actbl;
  jpeg_component_info *compptr;

    /* Process restart marker if needed; may have to suspend */
    if (cinfo->restart_interval) {
      if (entropy->restarts_to_go == 0)
        if (!process_restart(cinfo))
          return FALSE;
    }

  /* Load up working state */
  BITREAD_LOAD_STATE(cinfo, entropy->bitstate);
  ASSIGN_STATE(state, entropy->saved);

  /* Outer loop handles each block in the MCU */

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
      block = MCU_data[blkn];
      ci = cinfo->MCU_membership[blkn];
      compptr = cinfo->cur_comp_info[ci];
      dctbl = entropy->dc_derived_tbls[compptr->dc_tbl_no];
      actbl = entropy->ac_derived_tbls[compptr->ac_tbl_no];

      /* Decode a single block's worth of coefficients */

      /* Section F.2.2.1: decode the DC coefficient difference */
      HUFF_DECODE(s, br_state, dctbl, return FALSE, label1);
        if (s) {
          CHECK_BIT_BUFFER(br_state, s, return FALSE);
          r = GET_BITS(s);
          s = HUFF_EXTEND(r, s);
        }

      /* Shortcut if component's values are not interesting */
      if (!compptr->component_needed)
        goto skip_ACs;

      /* Convert DC difference to actual value, update last_dc_val */
      s += state.last_dc_val[ci];
      state.last_dc_val[ci] = s;
      /* Output the DC coefficient (assumes jpeg_natural_order[0] = 0) */
      (*block)[0] = (JCOEF)s;

        /* Do we need to decode the AC coefficients for this component? */
        if (compptr->DCT_scaled_size > 1) {

            /* Section F.2.2.2: decode the AC coefficients */
            /* Since zeroes are skipped, output area must be cleared beforehand
             */
            for (k = 1; k < DCTSIZE2; k++) {
              HUFF_DECODE(s, br_state, actbl, return FALSE, label2);

              r = s >> 4;
              s &= 15;

                if (s) {
                  k += r;
                  CHECK_BIT_BUFFER(br_state, s, return FALSE);
                  r = GET_BITS(s);
                  s = HUFF_EXTEND(r, s);
                  /* Output coefficient in natural (dezigzagged) order.
                   * Note: the extra entries in jpeg_natural_order[] will save
                   * us if k >= DCTSIZE2, which could happen if the data is
                   * corrupted.
                   */
                  (*block)[jpeg_natural_order[k]] = (JCOEF)s;
                }
                else {
                  if (r != 15)
                    break;
                  k += 15;
                }
            }
        }
        else {
        skip_ACs:

            /* Section F.2.2.2: decode the AC coefficients */
            /* In this path we just discard the values */
            for (k = 1; k < DCTSIZE2; k++) {
              HUFF_DECODE(s, br_state, actbl, return FALSE, label3);

              r = s >> 4;
              s &= 15;

                if (s) {
                  k += r;
                  CHECK_BIT_BUFFER(br_state, s, return FALSE);
                  DROP_BITS(s);
                }
                else {
                  if (r != 15)
                    break;
                  k += 15;
                }
            }
        }
    }

  /* Completed MCU, so update state */
  BITREAD_SAVE_STATE(cinfo, entropy->bitstate);
  ASSIGN_STATE(entropy->saved, state);

  /* Account for restart interval (no-op if not using restarts) */
  entropy->restarts_to_go--;

  return TRUE;
}

/*
 * Module initialization routine for Huffman entropy decoding.
 */

GLOBAL void jinit_huff_decoder(j_decompress_ptr cinfo)
{
  huff_entropy_ptr entropy;
  int i;

  entropy = (huff_entropy_ptr)(*cinfo->mem->alloc_small)(
      (j_common_ptr)cinfo, JPOOL_IMAGE, SIZEOF(huff_entropy_decoder));
  cinfo->entropy = (struct jpeg_entropy_decoder *)entropy;
  entropy->pub.start_pass = start_pass_huff_decoder;
  entropy->pub.decode_mcu = decode_mcu;

    /* Mark tables unallocated */
    for (i = 0; i < NUM_HUFF_TBLS; i++) {
      entropy->dc_derived_tbls[i] = entropy->ac_derived_tbls[i] = NULL;
    }
}
