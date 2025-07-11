/*
 * jcapimin.c
 *
 * Copyright (C) 1994-1995, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains application interface code for the compression half
 * of the JPEG library.  These are the "minimum" API routines that may be
 * needed in either the normal full-compression case or the transcoding-only
 * case.
 *
 * Most of the routines intended to be called directly by an application
 * are in this file or in jcapistd.c.  But also see jcparam.c for
 * parameter-setup helper routines, jcomapi.c for routines shared by
 * compression and decompression, and jctrans.c for the transcoding case.
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"

/*
 * Initialization of a JPEG compression object.
 * The error manager must already be set up (in case memory manager fails).
 */

GLOBAL void jpeg_create_compress(j_compress_ptr cinfo)
{
  int i;

  /* For debugging purposes, zero the whole master structure.
   * But error manager pointer is already there, so save and restore it.
   */
  {
    struct jpeg_error_mgr *err = cinfo->err;
    MEMZERO(cinfo, SIZEOF(struct jpeg_compress_struct));
    cinfo->err = err;
  }
  cinfo->is_decompressor = FALSE;

  /* Initialize a memory manager instance for this object */
  jinit_memory_mgr((j_common_ptr)cinfo);

  /* Zero out pointers to permanent structures. */
  cinfo->progress = NULL;
  cinfo->dest = NULL;

  cinfo->comp_info = NULL;

  for (i = 0; i < NUM_QUANT_TBLS; i++)
    cinfo->quant_tbl_ptrs[i] = NULL;

    for (i = 0; i < NUM_HUFF_TBLS; i++) {
      cinfo->dc_huff_tbl_ptrs[i] = NULL;
      cinfo->ac_huff_tbl_ptrs[i] = NULL;
    }

  cinfo->input_gamma = 1.0; /* in case application forgets */

  /* OK, I'm ready */
  cinfo->global_state = CSTATE_START;
}

/*
 * Destruction of a JPEG compression object
 */

GLOBAL void jpeg_destroy_compress(j_compress_ptr cinfo)
{
  jpeg_destroy((j_common_ptr)cinfo); /* use common routine */
}

/*
 * Abort processing of a JPEG compression operation,
 * but don't destroy the object itself.
 */

GLOBAL void jpeg_abort_compress(j_compress_ptr cinfo)
{
  jpeg_abort((j_common_ptr)cinfo); /* use common routine */
}

/*
 * Forcibly suppress or un-suppress all quantization and Huffman tables.
 * Marks all currently defined tables as already written (if suppress)
 * or not written (if !suppress).  This will control whether they get emitted
 * by a subsequent jpeg_start_compress call.
 *
 * This routine is exported for use by applications that want to produce
 * abbreviated JPEG datastreams.  It logically belongs in jcparam.c, but
 * since it is called by jpeg_start_compress, we put it here --- otherwise
 * jcparam.o would be linked whether the application used it or not.
 */

GLOBAL void jpeg_suppress_tables(j_compress_ptr cinfo, boolean suppress)
{
  int i;
  JQUANT_TBL *qtbl;
  JHUFF_TBL *htbl;

    for (i = 0; i < NUM_QUANT_TBLS; i++) {
      if ((qtbl = cinfo->quant_tbl_ptrs[i]) != NULL)
        qtbl->sent_table = suppress;
    }

    for (i = 0; i < NUM_HUFF_TBLS; i++) {
      if ((htbl = cinfo->dc_huff_tbl_ptrs[i]) != NULL)
        htbl->sent_table = suppress;
      if ((htbl = cinfo->ac_huff_tbl_ptrs[i]) != NULL)
        htbl->sent_table = suppress;
    }
}

/*
 * Finish JPEG compression.
 *
 * If a multipass operating mode was selected, this may do a great deal of
 * work including most of the actual output.
 */

GLOBAL void jpeg_finish_compress(j_compress_ptr cinfo)
{
  JDIMENSION iMCU_row;

    if (cinfo->global_state == CSTATE_SCANNING ||
        cinfo->global_state == CSTATE_RAW_OK) {
      /* Terminate first pass */
      if (cinfo->next_scanline < cinfo->image_height)
        ERREXIT(cinfo, JERR_TOO_LITTLE_DATA);
      (*cinfo->master->finish_pass)(cinfo);
    }
  else if (cinfo->global_state != CSTATE_WRCOEFS)
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);
    /* Perform any remaining passes */
    while (!cinfo->master->is_last_pass) {
      (*cinfo->master->prepare_for_pass)(cinfo);
        for (iMCU_row = 0; iMCU_row < cinfo->total_iMCU_rows; iMCU_row++) {
            if (cinfo->progress != NULL) {
              cinfo->progress->pass_counter = (long)iMCU_row;
              cinfo->progress->pass_limit = (long)cinfo->total_iMCU_rows;
              (*cinfo->progress->progress_monitor)((j_common_ptr)cinfo);
            }
          /* We bypass the main controller and invoke coef controller directly;
           * all work is being done from the coefficient buffer.
           */
          if (!(*cinfo->coef->compress_data)(cinfo, (JSAMPIMAGE)NULL))
            ERREXIT(cinfo, JERR_CANT_SUSPEND);
        }
      (*cinfo->master->finish_pass)(cinfo);
    }
  /* Write EOI, do final cleanup */
  (*cinfo->marker->write_file_trailer)(cinfo);
  (*cinfo->dest->term_destination)(cinfo);
  /* We can use jpeg_abort to release memory and reset global_state */
  jpeg_abort((j_common_ptr)cinfo);
}

/*
 * Write a special marker.
 * This is only recommended for writing COM or APPn markers.
 * Must be called after jpeg_start_compress() and before
 * first call to jpeg_write_scanlines() or jpeg_write_raw_data().
 */

GLOBAL void jpeg_write_marker(j_compress_ptr cinfo, int marker,
                              const JOCTET *dataptr, unsigned int datalen)
{
  if (cinfo->next_scanline != 0 || (cinfo->global_state != CSTATE_SCANNING &&
                                    cinfo->global_state != CSTATE_RAW_OK &&
                                    cinfo->global_state != CSTATE_WRCOEFS))
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

  (*cinfo->marker->write_any_marker)(cinfo, marker, dataptr, datalen);
}

/*
 * Alternate compression function: just write an abbreviated table file.
 * Before calling this, all parameters and a data destination must be set up.
 *
 * To produce a pair of files containing abbreviated tables and abbreviated
 * image data, one would proceed as follows:
 *
 *		initialize JPEG object
 *		set JPEG parameters
 *		set destination to table file
 *		jpeg_write_tables(cinfo);
 *		set destination to image file
 *		jpeg_start_compress(cinfo, FALSE);
 *		write data...
 *		jpeg_finish_compress(cinfo);
 *
 * jpeg_write_tables has the side effect of marking all tables written
 * (same as jpeg_suppress_tables(..., TRUE)).  Thus a subsequent start_compress
 * will not re-emit the tables unless it is passed write_all_tables=TRUE.
 */

GLOBAL void jpeg_write_tables(j_compress_ptr cinfo)
{
  if (cinfo->global_state != CSTATE_START)
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

  /* (Re)initialize error mgr and destination modules */
  (*cinfo->err->reset_error_mgr)((j_common_ptr)cinfo);
  (*cinfo->dest->init_destination)(cinfo);
  /* Initialize the marker writer ... bit of a crock to do it here. */
  jinit_marker_writer(cinfo);
  /* Write them tables! */
  (*cinfo->marker->write_tables_only)(cinfo);
  /* And clean up. */
  (*cinfo->dest->term_destination)(cinfo);
  /* We can use jpeg_abort to release memory. */
  jpeg_abort((j_common_ptr)cinfo);
}
