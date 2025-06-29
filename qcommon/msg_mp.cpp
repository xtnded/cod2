void __cdecl MSG_SetDefaultUserCmd(struct playerState_s *ps,
                                   struct usercmd_s *cmd)
{
  playerState_s *v2; // edx
  usercmd_s *v3;     // ecx
  int v4;            // edi
  uint32_t result;   // eax
  float v6;          // xmm0_4

  memset(a2, 0, 0x1Cu);
  a2->weapon = a1->weapon;
  a2->offHandIndex = a1->offHandIndex;
  v2 = a1;
  v3 = a2;
  v4 = 2;
    do {
      result = (unsigned __int16)((int)(float)(v2->viewangles[0] * 182.04445) -
                                  LOWORD(v2->delta_angles[0]));
      LODWORD(v3->angles[0]) = result;
      v2 = (playerState_s *)((char *)v2 + 4);
      v3 = (usercmd_s *)((char *)v3 + 4);
      --v4;
    }
  while (v4);
    if ((a1->pm_flags & 0x800000) != 0) {
      result = a1->eFlags;
        if ((result & 8) != 0) {
          a2->buttons |= 0x100u;
        }
        else if ((result & 4) != 0) {
          a2->buttons |= 0x200u;
          v6 = *(float *)&a1->leanf;
          if (v6 > 0.0)
            goto LABEL_7;
          goto LABEL_13;
        }
      v6 = *(float *)&a1->leanf;
        if (v6 > 0.0) {
        LABEL_7:
          a2->buttons |= 0x80u;
        LABEL_8:
          if (a1->fWeaponPosFrac != 0.0)
            a2->buttons |= 0x1000u;
          return result;
        }
    LABEL_13:
      if (v6 < 0.0)
        a2->buttons |= 0x40u;
      goto LABEL_8;
    }
  return result;
}

void __cdecl MSG_WriteReliableCommandToBuffer(char const *pszCommand,
                                              char *pszBuffer, int iBufferSize)
{
  unsigned int v3; // ecx
  unsigned int v4; // edi
  char *result;    // eax
  char v6;         // al
  char *v7;        // edi
  char *v8;        // ebx
  char v9;         // al
  char v10;        // dl

  v3 = strlen(a1) + 1;
  v4 = v3 - 1;
  if ((int)(v3 - 1) >= (int)a3)
    Com_Printf("WARNING: Reliable command is too long (%i/%i) and will be "
               "truncated: '%s'\n",
               v3 - 1, a3, a1);
  if (!v4)
    Com_Printf("WARNING: Empty reliable command\n");
    if ((int)a3 <= 0) {
    LABEL_6:
      result = a2;
      a3[(_DWORD)a2 - 1] = 0;
      return result;
    }
  v6 = *a1;
    if (*a1) {
      v7 = a2;
      v8 = 0;
        while (1) {
          v9 = I_CleanChar(v6);
          v10 = 46;
          if (v9 != 37)
            v10 = v9;
          *v7 = v10;
          ++v8;
          ++v7;
          if (a3 == v8)
            goto LABEL_6;
          v6 = v8[(_DWORD)a1];
            if (!v6) {
              result = v8;
              goto LABEL_9;
            }
        }
    }
  result = 0;
LABEL_9:
  result[(_DWORD)a2] = 0;
  return result;
}

void __cdecl MSG_ReadData(struct msg_t *msg, void *data, int len)
{
  uint32_t readcount; // eax
  uint32_t v4;        // esi
  void *result;       // eax

  readcount = a1->readcount;
  v4 = readcount + __n;
    if ((signed __int32)(readcount + __n) > (signed int)a1->cursize) {
      a1->overflowed = 1;
      return memset(__dst, -1, __n);
    }
    else {
      result = memcpy(__dst, (const void *)(a1->data + readcount), __n);
      a1->readcount = v4;
    }
  return result;
}

unsigned __int64 __cdecl MSG_ReadInt64(struct msg_t *)
{
  UNIMPLEMENTED();
}

int __cdecl MSG_ReadByte(struct msg_t *msg)
{
  signed int readcount; // edx
  int v2;               // ebx

  readcount = a1->readcount;
    if (readcount >= (signed int)a1->cursize) {
      a1->overflowed = 1;
      return -1;
    }
    else {
      v2 = *(unsigned __int8 *)(a1->data + readcount);
      a1->readcount = readcount + 1;
      return v2;
    }
}

void __cdecl MSG_WriteInt64(struct msg_t *, unsigned __int64)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteData(struct msg_t *buf, void const *data, int length)
{
  uint32_t result; // eax
  uint32_t v4;     // esi

  result = a1->cursize;
  v4 = result + __n;
    if ((signed __int32)(result + __n) <= (signed int)a1->maxsize) {
      result = (uint32_t)memcpy((void *)(a1->data + result), __src, __n);
      a1->cursize = v4;
    }
    else {
      a1->overflowed = 1;
    }
  return result;
}

void __cdecl MSG_WriteByte(struct msg_t *msg, int c)
{
  signed int cursize; // ecx
  int32_t result;     // eax

  cursize = a1->cursize;
    if (cursize >= (signed int)a1->maxsize) {
      a1->overflowed = 1;
    }
    else {
      result = a1->data;
      *(_BYTE *)(result + cursize) = a2;
      ++a1->cursize;
    }
  return result;
}

int __cdecl MSG_ReadBit(struct msg_t *msg)
{
  int32_t bit;          // edi
  char v2;              // si
  signed int readcount; // eax
  int v4;               // edx

  bit = a1->bit;
  v2 = bit & 7;
    if ((bit & 7) == 0) {
      readcount = a1->readcount;
        if (readcount >= (signed int)a1->cursize) {
          a1->overflowed = 1;
          return -1;
        }
      bit = 8 * readcount;
      a1->bit = 8 * readcount;
      a1->readcount = readcount + 1;
    }
  v4 = ((int)*(unsigned __int8 *)(a1->data + (bit >> 3)) >> v2) & 1;
  a1->bit = bit + 1;
  return v4;
}

int __cdecl MSG_ReadBits(struct msg_t *msg, int bits)
{
  int v3;               // esi
  char i;               // di
  int v5;               // edi
  signed int readcount; // eax
  int bit;              // [esp+0h] [ebp-14h]
  int v8;               // [esp+4h] [ebp-10h]

    if (a2 > 0) {
      v8 = 0;
      v3 = 0;
      bit = a1->bit;
        for (i = bit;; i = bit) {
          v5 = i & 7;
            if (!v5) {
              readcount = a1->readcount;
                if (readcount >= (signed int)a1->cursize) {
                  a1->overflowed = 1;
                  return -1;
                }
              bit = 8 * readcount;
              a1->bit = 8 * readcount;
              a1->readcount = readcount + 1;
            }
          v8 |= (((int)*(unsigned __int8 *)(a1->data + (bit++ >> 3)) >> v5) & 1)
                << v3;
          a1->bit = bit;
          if (a2 == ++v3)
            return v8;
        }
    }
  return 0;
}

void __cdecl MSG_WriteBit1(struct msg_t *msg)
{
  signed int cursize; // ebx
  int v2;             // esi
  _BYTE *v3;          // edx
  int result;         // eax
  _BYTE *v5;          // edx

  cursize = a1->cursize;
    if (cursize < (signed int)a1->maxsize) {
      v2 = a1->bit & 7;
        if (v2) {
          v3 = (_BYTE *)(a1->data + (a1->bit >> 3));
          result = 1 << v2;
          *v3 |= 1 << v2;
        }
        else {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          ++a1->cursize;
          v5 = (_BYTE *)(a1->data + (a1->bit >> 3));
          result = 1;
          *v5 |= 1u;
        }
      ++a1->bit;
    }
    else {
      a1->overflowed = 1;
    }
  return result;
}

void __cdecl MSG_WriteBit0(struct msg_t *msg)
{
  signed int cursize; // ecx
  int32_t bit;        // eax

  cursize = a1->cursize;
    if (cursize < (signed int)a1->maxsize) {
      bit = a1->bit;
        if ((bit & 7) == 0) {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          ++a1->cursize;
          bit = a1->bit;
        }
      a1->bit = bit + 1;
    }
    else {
      a1->overflowed = 1;
    }
}

void __cdecl MSG_WriteBits(struct msg_t *msg, int value, int bits)
{
  int32_t result;   // eax
  int v5;           // edi
  char i;           // dl
  int32_t v7;       // eax
  uint32_t cursize; // edx
  int32_t bit;      // [esp+0h] [ebp-14h]
  char v10;         // [esp+4h] [ebp-10h]

  result = a1->maxsize - a1->cursize;
    if (result > 3) {
      result = a3;
        if (a3) {
          v5 = 0;
          bit = a1->bit;
            for (i = bit;; i = result) {
              v10 = i & 7;
                if ((i & 7) == 0) {
                  cursize = a1->cursize;
                  a1->bit = 8 * cursize;
                  *(_BYTE *)(a1->data + cursize) = 0;
                  ++a1->cursize;
                  bit = a1->bit;
                }
                if ((a2 & 1) != 0) {
                  *(_BYTE *)(a1->data + (bit >> 3)) |= 1 << v10;
                  v7 = a1->bit;
                }
                else {
                  v7 = bit;
                }
              result = v7 + 1;
              bit = result;
              a1->bit = result;
              a2 >>= 1;
              if (a3 == ++v5)
                break;
            }
        }
    }
    else {
      a1->overflowed = 1;
    }
  return result;
}

int __cdecl MSG_GetUsedBitCount(struct msg_t const *)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_BeginReading(struct msg_t *msg)
{
  msg_t *result; // eax

  result = a1;
  a1->overflowed = 0;
  a1->readcount = 0;
  a1->bit = 0;
  return result;
}

int __cdecl MSG_ReadDeltaKeyByte(struct msg_t *, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaKeyByte(struct msg_t *, int, int, int)
{
  UNIMPLEMENTED();
}

int __cdecl MSG_ReadKey(struct msg_t *, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteKey(struct msg_t *, int, int, int)
{
  UNIMPLEMENTED();
}

int __cdecl MSG_ReadDeltaKey(struct msg_t *, int, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaKey(struct msg_t *, int, int, int, int)
{
  UNIMPLEMENTED();
}

char *__cdecl MSG_ReadStringLine(struct msg_t *msg)
{
  unsigned int v1;      // edi
  signed int readcount; // edx
  unsigned __int8 v3;   // cl
  int v4;               // ebx

  v1 = 0;
  readcount = a1->readcount;
  if (readcount >= (signed int)a1->cursize)
    goto LABEL_8;
LABEL_2:
  v3 = *(_BYTE *)(a1->data + readcount);
  v4 = v3;
  a1->readcount = readcount + 1;
    if (v3 == 37) {
      v4 = 46;
        while (v1 > 0x3FF) {
        LABEL_6:
          if (!v4)
            goto LABEL_12;
        LABEL_7:
          ++v1;
          readcount = a1->readcount;
          if (readcount < (signed int)a1->cursize)
            goto LABEL_2;
        LABEL_8:
          a1->overflowed = 1;
        LABEL_4:
          v4 = 0;
        }
    }
    else {
      if (v3 == 10 || v3 == -1)
        goto LABEL_4;
      if (v1 > 0x3FF)
        goto LABEL_6;
    }
  MSG_ReadStringLine(msg_t *)::string[v1] = I_CleanChar(v4);
  if (v4)
    goto LABEL_7;
LABEL_12:
  byte_F1105F = 0;
  return MSG_ReadStringLine(msg_t *)::string;
}

char *__cdecl MSG_ReadBigString(struct msg_t *msg)
{
  unsigned int i;       // edi
  unsigned __int8 v2;   // dl
  int v3;               // ebx
  signed int readcount; // ecx

    for (i = 0;; ++i) {
      readcount = a1->readcount;
      if (readcount >= (signed int)a1->cursize)
        break;
      v2 = *(_BYTE *)(a1->data + readcount);
      v3 = v2;
      a1->readcount = readcount + 1;
        if (v2 == 37) {
          v3 = 46;
        }
        else if (v2 == -1) {
          goto LABEL_9;
        }
      if (i <= 0x1FFF)
        goto LABEL_10;
    LABEL_5:
      if (!v3)
        goto LABEL_11;
    LABEL_6:;
    }
  a1->overflowed = 1;
LABEL_9:
  v3 = 0;
  if (i > 0x1FFF)
    goto LABEL_5;
LABEL_10:
  MSG_ReadBigString(msg_t *)::string[i] = I_CleanChar(v3);
  if (v3)
    goto LABEL_6;
LABEL_11:
  byte_F10C5F = 0;
  return MSG_ReadBigString(msg_t *)::string;
}

char *__cdecl MSG_ReadString(struct msg_t *msg)
{
  unsigned int i;       // edi
  int v2;               // ebx
  signed int readcount; // edx

    for (i = 0;; ++i) {
      readcount = a1->readcount;
      if (readcount < (signed int)a1->cursize)
        break;
      a1->overflowed = 1;
      v2 = 0;
      if (i <= 0x3FF)
        goto LABEL_9;
    LABEL_4:
      if (!v2)
        goto LABEL_10;
    LABEL_5:;
    }
  v2 = *(unsigned __int8 *)(a1->data + readcount);
  a1->readcount = readcount + 1;
  if (i > 0x3FF)
    goto LABEL_4;
LABEL_9:
  MSG_ReadString(msg_t *)::string[i] = I_CleanChar(v2);
  if (v2)
    goto LABEL_5;
LABEL_10:
  byte_F0EC5F = 0;
  return MSG_ReadString(msg_t *)::string;
}

int __cdecl MSG_ReadLong(struct msg_t *msg)
{
  uint32_t readcount; // ebx
  int result;         // eax

  readcount = a1->readcount;
    if ((signed int)(readcount + 4) > (signed int)a1->cursize) {
      a1->overflowed = 1;
      return -1;
    }
    else {
      result = *(_DWORD *)(a1->data + readcount);
      a1->readcount = readcount + 4;
    }
  return result;
}

int __cdecl MSG_ReadShort(struct msg_t *msg)
{
  uint32_t readcount; // ebx
  int result;         // eax

  readcount = a1->readcount;
    if ((signed int)(readcount + 2) > (signed int)a1->cursize) {
      a1->overflowed = 1;
      return -1;
    }
    else {
      result = *(__int16 *)(a1->data + readcount);
      a1->readcount = readcount + 2;
    }
  return result;
}

void __cdecl MSG_WriteAngle(struct msg_t *, float)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteString(struct msg_t *sb, char const *s)
{
  size_t v2;         // ecx
  int v3;            // ebx
  msg_t *result;     // eax
  uint32_t cursize;  // edx
  signed int v6;     // ebx
  int i;             // edi
  uint32_t v8;       // edx
  _BYTE __src[1048]; // [esp+10h] [ebp-418h] BYREF

  v2 = strlen(a2) + 1;
  v3 = v2 - 1;
    if ((int)(v2 - 1) > 1023) {
      Com_Printf("MSG_WriteString: MAX_STRING_CHARS");
      result = (msg_t *)a1->cursize;
      v8 = (uint32_t)&result->overflowed + 1;
        if ((int)&result->overflowed + 1 <= (signed int)a1->maxsize) {
          result = (msg_t *)((char *)result + a1->data);
          LOBYTE(result->overflowed) = 0;
          a1->cursize = v8;
        }
        else {
          a1->overflowed = 1;
        }
    }
    else {
        if (v3 > 0) {
          for (i = 0; i != v3; ++i)
            __src[i] = I_CleanChar(a2[i]);
          __src[v3] = 0;
          v2 = v3 + 1;
          result = a1;
          cursize = a1->cursize;
          v6 = v3 + 1 + cursize;
          if (v6 > (signed int)a1->maxsize)
            goto LABEL_4;
        }
        else {
          __src[0] = 0;
          result = a1;
          cursize = a1->cursize;
          v6 = v2 + cursize;
            if ((signed __int32)(v2 + cursize) > (signed int)a1->maxsize) {
            LABEL_4:
              result->overflowed = 1;
              return result;
            }
        }
      result = (msg_t *)memcpy((void *)(result->data + cursize), __src, v2);
      a1->cursize = v6;
    }
  return result;
}

void __cdecl MSG_WriteLong(struct msg_t *msg, int c)
{
  uint32_t cursize; // ebx
  int32_t result;   // eax

  cursize = a1->cursize;
    if ((signed int)(cursize + 4) > (signed int)a1->maxsize) {
      a1->overflowed = 1;
    }
    else {
      result = a1->data;
      *(_DWORD *)(result + cursize) = a2;
      a1->cursize = cursize + 4;
    }
  return result;
}

void __cdecl MSG_WriteShort(struct msg_t *msg, int c)
{
  uint32_t cursize; // ebx
  int32_t result;   // eax

  cursize = a1->cursize;
    if ((signed int)(cursize + 2) > (signed int)a1->maxsize) {
      a1->overflowed = 1;
    }
    else {
      result = a1->data;
      *(_WORD *)(result + cursize) = a2;
      a1->cursize = cursize + 2;
    }
  return result;
}

int __cdecl MSG_ReadDeltaKeyShort(struct msg_t *, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaKeyShort(struct msg_t *, int, int, int)
{
  UNIMPLEMENTED();
}

float __cdecl MSG_ReadAngle16(struct msg_t *)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteAngle16(struct msg_t *, float)
{
  UNIMPLEMENTED();
}

int __cdecl MSG_ReadBitsCompress(unsigned char *from, unsigned char *to,
                                 int size)
{
  unsigned __int8 *v4; // ebx
  int v5;              // [esp+18h] [ebp-20h] BYREF
  int v6[7];           // [esp+1Ch] [ebp-1Ch] BYREF

  v5 = 0;
  if (8 * a3 <= 0)
    return 0;
  v4 = a2;
    do {
      Huff_offsetReceive(*(nodetype **)&msgHuff.decompressor[8], v6, a1, &v5);
      *v4++ = v6[0];
    }
  while (8 * a3 > v5);
  return v4 - a2;
}

void __cdecl MSG_initHuffman(void)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_ReadDeltaUsercmdKey(struct msg_t *msg, int key,
                                     struct usercmd_s *from,
                                     struct usercmd_s *to)
{
  int32_t bit;          // ebx
  char v5;              // si
  signed int readcount; // edx
  int32_t data;         // ebx
  int v8;               // eax
  uint32_t serverTime;  // ecx
  int v10;              // eax
  char v11;             // bl
  signed int v12;       // eax
  int v13;              // edx
  int v14;              // edx
  int v15;              // eax
  int32_t v16;          // edx
  char v17;             // bl
  signed int v18;       // eax
  int v19;              // edx
  int v20;              // edx
  int32_t v21;          // ebx
  char v22;             // si
  int v23;              // edx
  int v24;              // edx
  float v25;            // esi
  char v26;             // bl
  signed int v27;       // edx
  uint32_t v28;         // ecx
  __int16 v29;          // ax
  float v30;            // esi
  char v31;             // bl
  signed int v32;       // edx
  uint32_t v33;         // ecx
  __int16 v34;          // ax
  int8_t v35;           // dl
  int8_t v36;           // al
  char v37;             // bl
  int32_t v38;          // eax
  char v39;             // si
  signed int v40;       // eax
  int v41;              // ebx
  char v42;             // si
  signed int v43;       // eax
  char v44;             // dl
  int8_t *v45;          // ecx
  int v46;              // eax
  int v47;              // eax
  uint32_t v48;         // edx
  uint32_t v49;         // eax
  int v50;              // eax
  int v51;              // eax
  int32_t buttons;      // ebx
  char v53;             // si
  int v54;              // edx
  int v55;              // edx
  float v56;            // esi
  char v57;             // bl
  signed int v58;       // edx
  uint32_t v59;         // ecx
  __int16 v60;          // ax
  float v61;            // esi
  char v62;             // bl
  signed int v63;       // edx
  uint32_t v64;         // ecx
  __int16 v65;          // ax
  int8_t rightmove;     // dl
  int8_t forwardmove;   // al
  char v68;             // bl
  int32_t v69;          // eax
  char v70;             // si
  signed int v71;       // eax
  int v72;              // ebx
  char v73;             // si
  signed int v74;       // eax
  char v75;             // al
  char v76;             // dl
  int8_t *p_rightmove;  // ecx
  float v78;            // esi
  char v79;             // bl
  signed int v80;       // edx
  uint32_t v81;         // ecx
  __int16 v82;          // ax
  int32_t v83;          // ebx
  char v84;             // si
  signed int v85;       // eax
  int v86;              // ebx
  char v87;             // si
  signed int v88;       // eax
  int v89;              // eax
  int8_t weapon;        // bl
  char v91;             // si
  signed int v92;       // eax
  int v93;              // ebx
  char v94;             // si
  signed int v95;       // eax
  char v96;             // al
  uint8_t offHandIndex; // bl
  int32_t v98;          // eax
  char v99;             // si
  signed int v100;      // eax
  int v101;             // ebx
  char v102;            // si
  signed int v103;      // eax
  char v104;            // al
  int v105;             // eax
  int v106;             // eax
  uint32_t v107;        // edx
  signed int v108;      // eax
  int v109;             // eax
  int v110;             // eax
  signed int v111;      // eax
  int v112;             // eax
  int32_t v113;         // eax
  int v114;             // eax
  int32_t v115;         // eax
  int v116;             // eax
  int32_t v118;         // [esp+0h] [ebp-30h]
  int32_t v119;         // [esp+0h] [ebp-30h]
  int v120;             // [esp+0h] [ebp-30h]
  int32_t v121;         // [esp+0h] [ebp-30h]
  int32_t v122;         // [esp+0h] [ebp-30h]
  int32_t v123;         // [esp+0h] [ebp-30h]
  int32_t v124;         // [esp+0h] [ebp-30h]
  int32_t v125;         // [esp+0h] [ebp-30h]
  int32_t v126;         // [esp+0h] [ebp-30h]
  int32_t v127;         // [esp+0h] [ebp-30h]
  int v128;             // [esp+0h] [ebp-30h]
  int v129;             // [esp+0h] [ebp-30h]
  int32_t v130;         // [esp+0h] [ebp-30h]
  int32_t v131;         // [esp+4h] [ebp-2Ch]
  int v132;             // [esp+8h] [ebp-28h]
  int v133;             // [esp+Ch] [ebp-24h]
  int v134;             // [esp+10h] [ebp-20h]
  int v135;             // [esp+14h] [ebp-1Ch]
  int v136;             // [esp+18h] [ebp-18h]
  uint32_t v137;        // [esp+1Ch] [ebp-14h]
  uint32_t v138;        // [esp+20h] [ebp-10h]

  a4->serverTime = a3->serverTime;
  a4->buttons = a3->buttons;
  *(_DWORD *)&a4->weapon = *(_DWORD *)&a3->weapon;
  a4->angles[0] = a3->angles[0];
  a4->angles[1] = a3->angles[1];
  a4->angles[2] = a3->angles[2];
  *(_DWORD *)&a4->forwardmove = *(_DWORD *)&a3->forwardmove;
  bit = a1->bit;
  v118 = bit;
  v5 = bit & 7;
    if ((bit & 7) != 0) {
      v46 = bit >> 3;
      data = a1->data;
      v47 = (int)*(unsigned __int8 *)(data + v46) >> v5;
      a1->bit = v118 + 1;
      if ((v47 & 1) != 0)
        goto LABEL_4;
    }
    else {
      readcount = a1->readcount;
        if (readcount >= (signed int)a1->cursize) {
          a1->overflowed = 1;
          serverTime = a3->serverTime;
          if (readcount < (signed int)a1->cursize)
            goto LABEL_5;
          goto LABEL_48;
        }
      a1->bit = 8 * readcount;
      a1->readcount = readcount + 1;
      data = a1->data;
      v8 = (int)*(unsigned __int8 *)(data + ((8 * readcount) >> 3)) >> v5;
      a1->bit = 8 * readcount + 1;
        if ((v8 & 1) != 0) {
        LABEL_4:
          readcount = a1->readcount;
          serverTime = a3->serverTime;
            if (readcount < (signed int)a1->cursize) {
            LABEL_5:
              v10 = *(unsigned __int8 *)(a1->data + readcount);
              a1->readcount = readcount + 1;
            LABEL_6:
              a4->serverTime = serverTime + v10;
              goto LABEL_7;
            }
        LABEL_48:
          a1->overflowed = 1;
          v10 = -1;
          goto LABEL_6;
        }
    }
  v48 = a1->readcount;
  v49 = v48 + 4;
    if ((signed int)(v48 + 4) <= (signed int)a1->cursize) {
      v107 = *(_DWORD *)(data + v48);
      a1->readcount = v49;
      a4->serverTime = v107;
    }
    else {
      a1->overflowed = 1;
      a4->serverTime = -1;
    }
LABEL_7:
  v119 = a1->bit;
  v11 = v119 & 7;
    if ((v119 & 7) != 0) {
    LABEL_10:
      v13 = (int)*(unsigned __int8 *)(a1->data + (v119 >> 3)) >> v11;
      a1->bit = v119 + 1;
      v14 = v13 & 1;
      goto LABEL_11;
    }
  v12 = a1->readcount;
    if (v12 < (signed int)a1->cursize) {
      v119 = 8 * v12;
      a1->bit = 8 * v12;
      a1->readcount = v12 + 1;
      goto LABEL_10;
    }
  a1->overflowed = 1;
  v14 = -1;
LABEL_11:
  LOBYTE(v15) = dword_312C04 & a2;
  if ((dword_312C04 & a2) == v14)
    return v15;
  a4->buttons &= ~1u;
  v16 = a1->bit;
  v120 = v16;
  v17 = v16 & 7;
  if ((v16 & 7) != 0)
    goto LABEL_15;
  v18 = a1->readcount;
    if (v18 < (signed int)a1->cursize) {
      v120 = 8 * v18;
      a1->bit = 8 * v18;
      a1->readcount = v18 + 1;
      v16 = 8 * v18;
    LABEL_15:
      v19 = (int)*(unsigned __int8 *)(a1->data + (v16 >> 3)) >> v17;
      a1->bit = ++v120;
      v20 = v19 & 1;
      goto LABEL_16;
    }
  a1->overflowed = 1;
  v20 = -1;
LABEL_16:
    if ((dword_312C04 & a2) != v20) {
      buttons = a4->buttons;
      v53 = v120 & 7;
        if ((v120 & 7) == 0) {
          v111 = a1->readcount;
            if (v111 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
              v55 = -1;
            LABEL_59:
              a4->buttons = v55 ^ dword_312C04 & a2 | buttons;
              v56 = a3->angles[0];
              v124 = a1->bit;
              v57 = v124 & 7;
                if ((v124 & 7) == 0) {
                  v58 = a1->readcount;
                    if (v58 >= (signed int)a1->cursize) {
                      a1->overflowed = 1;
                      v59 = v58 + 2;
                        if (v58 + 2 <= (signed int)a1->cursize) {
                        LABEL_62:
                          v60 = *(_WORD *)(a1->data + v58);
                          a1->readcount = v59;
                        LABEL_63:
                          LOWORD(v56) = a2 ^ v60;
                          goto LABEL_64;
                        }
                    LABEL_121:
                      a1->overflowed = 1;
                      v60 = -1;
                      goto LABEL_63;
                    }
                  v124 = 8 * v58;
                  a1->bit = 8 * v58;
                  a1->readcount = v58 + 1;
                }
              v105 = (int)*(unsigned __int8 *)(a1->data + (v124 >> 3)) >> v57;
              a1->bit = v124 + 1;
                if ((v105 & 1) == 0) {
                LABEL_64:
                  LODWORD(a4->angles[0]) = LOWORD(v56);
                  v61 = a3->angles[1];
                  v125 = a1->bit;
                  v62 = v125 & 7;
                    if ((v125 & 7) == 0) {
                      v63 = a1->readcount;
                        if (v63 >= (signed int)a1->cursize) {
                          a1->overflowed = 1;
                          v64 = v63 + 2;
                            if (v63 + 2 <= (signed int)a1->cursize) {
                            LABEL_67:
                              v65 = *(_WORD *)(a1->data + v63);
                              a1->readcount = v64;
                            LABEL_68:
                              LOWORD(v61) = a2 ^ v65;
                              goto LABEL_69;
                            }
                        LABEL_125:
                          a1->overflowed = 1;
                          v65 = -1;
                          goto LABEL_68;
                        }
                      v125 = 8 * v63;
                      a1->bit = 8 * v63;
                      a1->readcount = v63 + 1;
                    }
                  v106 =
                      (int)*(unsigned __int8 *)(a1->data + (v125 >> 3)) >> v62;
                  a1->bit = v125 + 1;
                    if ((v106 & 1) == 0) {
                    LABEL_69:
                      LODWORD(a4->angles[1]) = LOWORD(v61);
                      rightmove = a3->rightmove;
                      forwardmove = a3->forwardmove;
                        if (forwardmove <= 10) {
                          v68 = 2 * (forwardmove <= -11);
                            if (rightmove > 10) {
                            LABEL_71:
                              v68 |= 4u;
                              v69 = a1->bit;
                              v126 = v69;
                              v70 = v69 & 7;
                              if ((v69 & 7) != 0)
                                goto LABEL_133;
                            LABEL_72:
                              v71 = a1->readcount;
                                if (v71 >= (signed int)a1->cursize) {
                                  a1->overflowed = 1;
                                LABEL_74:
                                  v133 = 0;
                                  v72 = 0;
                                    while (1) {
                                      v73 = v126 & 7;
                                        if ((v126 & 7) == 0) {
                                          v74 = a1->readcount;
                                            if (v74 >=
                                                (signed int)a1->cursize) {
                                              a1->overflowed = 1;
                                              v75 = -1;
                                            LABEL_80:
                                              v76 = v75 ^ dword_312C10 & a2;
                                              p_rightmove = &a4->rightmove;
                                                if ((v76 & 1) != 0) {
                                                LABEL_81:
                                                  a4->forwardmove = 127;
                                                  if ((v76 & 4) != 0)
                                                    goto LABEL_82;
                                                LABEL_136:
                                                  *p_rightmove =
                                                      (v76 & 8) != 0 ? 0x81 : 0;
                                                  v137 = a4->serverTime ^ a2;
                                                  v78 = a3->angles[2];
                                                  v127 = a1->bit;
                                                  v79 = v127 & 7;
                                                  if ((v127 & 7) != 0)
                                                    goto LABEL_137;
                                                LABEL_83:
                                                  v80 = a1->readcount;
                                                    if (v80 < (signed int)
                                                                  a1->cursize) {
                                                      v127 = 8 * v80;
                                                      a1->bit = 8 * v80;
                                                      a1->readcount = v80 + 1;
                                                      goto LABEL_137;
                                                    }
                                                  a1->overflowed = 1;
                                                  v81 = v80 + 2;
                                                    if (v80 + 2 <=
                                                        (signed int)
                                                            a1->cursize) {
                                                    LABEL_85:
                                                      v82 =
                                                          *(_WORD *)(a1->data +
                                                                     v80);
                                                      a1->readcount = v81;
                                                      goto LABEL_86;
                                                    }
                                                LABEL_139:
                                                  a1->overflowed = 1;
                                                  v82 = -1;
                                                LABEL_86:
                                                  LOWORD(v78) = v137 ^ v82;
                                                  goto LABEL_87;
                                                }
                                            LABEL_135:
                                              a4->forwardmove =
                                                  (v76 & 2) != 0 ? 0x81 : 0;
                                              if ((v76 & 4) == 0)
                                                goto LABEL_136;
                                            LABEL_82:
                                              *p_rightmove = 127;
                                              v137 = a4->serverTime ^ a2;
                                              v78 = a3->angles[2];
                                              v127 = a1->bit;
                                              v79 = v127 & 7;
                                              if ((v127 & 7) == 0)
                                                goto LABEL_83;
                                            LABEL_137:
                                              v110 =
                                                  (int)*(unsigned __int8
                                                             *)(a1->data +
                                                                (v127 >> 3)) >>
                                                  v79;
                                              a1->bit = v127 + 1;
                                                if ((v110 & 1) != 0) {
                                                  v80 = a1->readcount;
                                                  v81 = v80 + 2;
                                                  if (v80 + 2 <=
                                                      (signed int)a1->cursize)
                                                    goto LABEL_85;
                                                  goto LABEL_139;
                                                }
                                            LABEL_87:
                                              LODWORD(a4->angles[2]) =
                                                  LOWORD(v78);
                                              v131 = a4->buttons & 1;
                                              a4->buttons = v131;
                                              v83 = a3->buttons >> 1;
                                              v128 = a1->bit;
                                              v84 = v128 & 7;
                                                if ((v128 & 7) != 0) {
                                                  v115 = a1->bit;
                                                }
                                                else {
                                                  v85 = a1->readcount;
                                                    if (v85 >= (signed int)a1
                                                                   ->cursize) {
                                                      a1->overflowed = 1;
                                                    LABEL_90:
                                                      v134 = 0;
                                                      v86 = 0;
                                                        while (1) {
                                                          v87 = v128 & 7;
                                                            if ((v128 & 7) ==
                                                                0) {
                                                              v88 =
                                                                  a1->readcount;
                                                                if (v88 >=
                                                                    (signed int)a1
                                                                        ->cursize) {
                                                                  a1->overflowed =
                                                                      1;
                                                                  v89 = -1;
                                                                LABEL_96:
                                                                  v83 =
                                                                      v89 ^
                                                                      dword_312C48 &
                                                                          v137;
                                                                LABEL_97:
                                                                  a4->buttons =
                                                                      (2 *
                                                                       v83) |
                                                                      v131;
                                                                  weapon =
                                                                      a3->weapon;
                                                                  v129 =
                                                                      a1->bit;
                                                                  v91 =
                                                                      v129 & 7;
                                                                    if ((v129 &
                                                                         7) !=
                                                                        0) {
                                                                      v113 =
                                                                          a1->bit;
                                                                    }
                                                                    else {
                                                                      v92 =
                                                                          a1->readcount;
                                                                        if (v92 >=
                                                                            (signed int)
                                                                                a1->cursize) {
                                                                          a1->overflowed =
                                                                              1;
                                                                        LABEL_100
                                                                            :
                                                                          v135 =
                                                                              0;
                                                                          v93 =
                                                                              0;
                                                                            while (
                                                                                1) {
                                                                              v94 =
                                                                                  v129 &
                                                                                  7;
                                                                                if ((v129 &
                                                                                     7) ==
                                                                                    0) {
                                                                                  v95 =
                                                                                      a1->readcount;
                                                                                    if (v95 >=
                                                                                        (signed int)
                                                                                            a1->cursize) {
                                                                                      a1->overflowed =
                                                                                          1;
                                                                                      v96 =
                                                                                          -1;
                                                                                    LABEL_106
                                                                                        :
                                                                                      weapon =
                                                                                          v96 ^
                                                                                          dword_312C1C &
                                                                                              v137;
                                                                                    LABEL_107
                                                                                        :
                                                                                      a4->weapon =
                                                                                          weapon;
                                                                                      offHandIndex =
                                                                                          a3->offHandIndex;
                                                                                      v98 =
                                                                                          a1->bit;
                                                                                      v130 =
                                                                                          v98;
                                                                                      v99 =
                                                                                          v98 &
                                                                                          7;
                                                                                        if ((v98 &
                                                                                             7) ==
                                                                                            0) {
                                                                                          v100 =
                                                                                              a1->readcount;
                                                                                            if (v100 >=
                                                                                                (signed int)
                                                                                                    a1->cursize) {
                                                                                              a1->overflowed =
                                                                                                  1;
                                                                                            LABEL_110
                                                                                                :
                                                                                              v136 =
                                                                                                  0;
                                                                                              v101 =
                                                                                                  0;
                                                                                                while (
                                                                                                    1) {
                                                                                                  v102 =
                                                                                                      v130 &
                                                                                                      7;
                                                                                                    if ((v130 &
                                                                                                         7) ==
                                                                                                        0) {
                                                                                                      v103 =
                                                                                                          a1->readcount;
                                                                                                        if (v103 >=
                                                                                                            (signed int)
                                                                                                                a1->cursize) {
                                                                                                          a1->overflowed =
                                                                                                              1;
                                                                                                          v104 =
                                                                                                              -1;
                                                                                                        LABEL_116
                                                                                                            :
                                                                                                          offHandIndex =
                                                                                                              v104 ^
                                                                                                              dword_312C1C &
                                                                                                                  v137;
                                                                                                        LABEL_117
                                                                                                            :
                                                                                                          LOBYTE(
                                                                                                              v15) =
                                                                                                              (_BYTE)
                                                                                                                  a4;
                                                                                                          a4->offHandIndex =
                                                                                                              offHandIndex;
                                                                                                          return v15;
                                                                                                        }
                                                                                                      v130 =
                                                                                                          8 *
                                                                                                          v103;
                                                                                                      a1->bit =
                                                                                                          8 *
                                                                                                          v103;
                                                                                                      a1->readcount =
                                                                                                          v103 +
                                                                                                          1;
                                                                                                    }
                                                                                                  v136 |=
                                                                                                      (((int)*(
                                                                                                            unsigned __int8
                                                                                                                *)(a1->data +
                                                                                                                   (v130++ >>
                                                                                                                    3)) >>
                                                                                                        v102) &
                                                                                                       1)
                                                                                                      << v101;
                                                                                                  a1->bit =
                                                                                                      v130;
                                                                                                    if (++v101 ==
                                                                                                        7) {
                                                                                                      v104 =
                                                                                                          v136;
                                                                                                      goto LABEL_116;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                          v130 =
                                                                                              8 *
                                                                                              v100;
                                                                                          a1->bit =
                                                                                              8 *
                                                                                              v100;
                                                                                          a1->readcount =
                                                                                              v100 +
                                                                                              1;
                                                                                          v98 =
                                                                                              8 *
                                                                                              v100;
                                                                                        }
                                                                                      v112 =
                                                                                          (int)*(
                                                                                              unsigned __int8
                                                                                                  *)(a1->data +
                                                                                                     (v98 >>
                                                                                                      3)) >>
                                                                                          v99;
                                                                                      a1->bit =
                                                                                          ++v130;
                                                                                      if ((v112 &
                                                                                           1) ==
                                                                                          0)
                                                                                        goto LABEL_117;
                                                                                      goto LABEL_110;
                                                                                    }
                                                                                  v129 =
                                                                                      8 *
                                                                                      v95;
                                                                                  a1->bit =
                                                                                      8 *
                                                                                      v95;
                                                                                  a1->readcount =
                                                                                      v95 +
                                                                                      1;
                                                                                }
                                                                              v135 |=
                                                                                  (((int)*(
                                                                                        unsigned __int8
                                                                                            *)(a1->data +
                                                                                               (v129++ >>
                                                                                                3)) >>
                                                                                    v94) &
                                                                                   1)
                                                                                  << v93;
                                                                              a1->bit =
                                                                                  v129;
                                                                                if (++v93 ==
                                                                                    7) {
                                                                                  v96 =
                                                                                      v135;
                                                                                  goto LABEL_106;
                                                                                }
                                                                            }
                                                                        }
                                                                      v129 =
                                                                          8 *
                                                                          v92;
                                                                      a1->bit =
                                                                          8 *
                                                                          v92;
                                                                      a1->readcount =
                                                                          v92 +
                                                                          1;
                                                                      v113 =
                                                                          8 *
                                                                          v92;
                                                                    }
                                                                  v114 =
                                                                      (int)*(
                                                                          unsigned __int8
                                                                              *)(a1->data +
                                                                                 (v113 >>
                                                                                  3)) >>
                                                                      v91;
                                                                  a1->bit =
                                                                      ++v129;
                                                                  if ((v114 &
                                                                       1) == 0)
                                                                    goto LABEL_107;
                                                                  goto LABEL_100;
                                                                }
                                                              v128 = 8 * v88;
                                                              a1->bit = 8 * v88;
                                                              a1->readcount =
                                                                  v88 + 1;
                                                            }
                                                          v134 |=
                                                              (((int)*(
                                                                    unsigned __int8
                                                                        *)(a1->data +
                                                                           (v128++ >>
                                                                            3)) >>
                                                                v87) &
                                                               1)
                                                              << v86;
                                                          a1->bit = v128;
                                                            if (++v86 == 18) {
                                                              v89 = v134;
                                                              goto LABEL_96;
                                                            }
                                                        }
                                                    }
                                                  v128 = 8 * v85;
                                                  a1->bit = 8 * v85;
                                                  a1->readcount = v85 + 1;
                                                  v115 = 8 * v85;
                                                }
                                              v116 =
                                                  (int)*(unsigned __int8
                                                             *)(a1->data +
                                                                (v115 >> 3)) >>
                                                  v84;
                                              a1->bit = ++v128;
                                              if ((v116 & 1) == 0)
                                                goto LABEL_97;
                                              goto LABEL_90;
                                            }
                                          v126 = 8 * v74;
                                          a1->bit = 8 * v74;
                                          a1->readcount = v74 + 1;
                                        }
                                      v133 |=
                                          (((int)*(unsigned __int8 *)(a1->data +
                                                                      (v126++ >>
                                                                       3)) >>
                                            v73) &
                                           1)
                                          << v72;
                                      a1->bit = v126;
                                        if (++v72 == 4) {
                                          v75 = v133;
                                          goto LABEL_80;
                                        }
                                    }
                                }
                              v126 = 8 * v71;
                              a1->bit = 8 * v71;
                              a1->readcount = v71 + 1;
                              v69 = 8 * v71;
                            LABEL_133:
                              v109 = (int)*(unsigned __int8 *)(a1->data +
                                                               (v69 >> 3)) >>
                                     v70;
                              a1->bit = ++v126;
                                if ((v109 & 1) == 0) {
                                  v76 = v68;
                                  p_rightmove = &a4->rightmove;
                                  if ((v68 & 1) != 0)
                                    goto LABEL_81;
                                  goto LABEL_135;
                                }
                              goto LABEL_74;
                            }
                        }
                        else {
                          v68 = 1;
                          if (rightmove > 10)
                            goto LABEL_71;
                        }
                      if (rightmove <= -11)
                        v68 |= 8u;
                      v69 = a1->bit;
                      v126 = v69;
                      v70 = v69 & 7;
                      if ((v69 & 7) != 0)
                        goto LABEL_133;
                      goto LABEL_72;
                    }
                  v63 = a1->readcount;
                  v64 = v63 + 2;
                  if (v63 + 2 <= (signed int)a1->cursize)
                    goto LABEL_67;
                  goto LABEL_125;
                }
              v58 = a1->readcount;
              v59 = v58 + 2;
              if (v58 + 2 <= (signed int)a1->cursize)
                goto LABEL_62;
              goto LABEL_121;
            }
          v120 = 8 * v111;
          a1->bit = 8 * v111;
          a1->readcount = v111 + 1;
        }
      v54 = (int)*(unsigned __int8 *)(a1->data + (v120 >> 3)) >> v53;
      a1->bit = v120 + 1;
      v55 = v54 & 1;
      goto LABEL_59;
    }
  v138 = a4->serverTime ^ a2;
  v21 = a4->buttons;
  v22 = v120 & 7;
    if ((v120 & 7) != 0) {
    LABEL_18:
      v23 = (int)*(unsigned __int8 *)(a1->data + (v120 >> 3)) >> v22;
      a1->bit = v120 + 1;
      v24 = v23 & 1;
      goto LABEL_19;
    }
  v108 = a1->readcount;
    if (v108 < (signed int)a1->cursize) {
      v120 = 8 * v108;
      a1->bit = 8 * v108;
      a1->readcount = v108 + 1;
      goto LABEL_18;
    }
  a1->overflowed = 1;
  v24 = -1;
LABEL_19:
  a4->buttons = dword_312C04 & v138 ^ v24 | v21;
  v25 = a3->angles[0];
  v121 = a1->bit;
  v26 = v121 & 7;
    if ((v121 & 7) == 0) {
      v27 = a1->readcount;
        if (v27 >= (signed int)a1->cursize) {
          a1->overflowed = 1;
          v28 = v27 + 2;
            if (v27 + 2 <= (signed int)a1->cursize) {
            LABEL_22:
              v29 = *(_WORD *)(a1->data + v27);
              a1->readcount = v28;
            LABEL_23:
              LOWORD(v25) = v138 ^ v29;
              goto LABEL_24;
            }
        LABEL_52:
          a1->overflowed = 1;
          v29 = -1;
          goto LABEL_23;
        }
      v121 = 8 * v27;
      a1->bit = 8 * v27;
      a1->readcount = v27 + 1;
    }
  v50 = (int)*(unsigned __int8 *)(a1->data + (v121 >> 3)) >> v26;
  a1->bit = v121 + 1;
    if ((v50 & 1) != 0) {
      v27 = a1->readcount;
      v28 = v27 + 2;
      if (v27 + 2 <= (signed int)a1->cursize)
        goto LABEL_22;
      goto LABEL_52;
    }
LABEL_24:
  LODWORD(a4->angles[0]) = LOWORD(v25);
  v30 = a3->angles[1];
  v122 = a1->bit;
  v31 = v122 & 7;
    if ((v122 & 7) == 0) {
      v32 = a1->readcount;
        if (v32 >= (signed int)a1->cursize) {
          a1->overflowed = 1;
          v33 = v32 + 2;
            if (v32 + 2 <= (signed int)a1->cursize) {
            LABEL_27:
              v34 = *(_WORD *)(a1->data + v32);
              a1->readcount = v33;
            LABEL_28:
              LOWORD(v30) = v138 ^ v34;
              goto LABEL_29;
            }
        LABEL_56:
          a1->overflowed = 1;
          v34 = -1;
          goto LABEL_28;
        }
      v122 = 8 * v32;
      a1->bit = 8 * v32;
      a1->readcount = v32 + 1;
    }
  v51 = (int)*(unsigned __int8 *)(a1->data + (v122 >> 3)) >> v31;
  a1->bit = v122 + 1;
    if ((v51 & 1) != 0) {
      v32 = a1->readcount;
      v33 = v32 + 2;
      if (v32 + 2 <= (signed int)a1->cursize)
        goto LABEL_27;
      goto LABEL_56;
    }
LABEL_29:
  LODWORD(a4->angles[1]) = LOWORD(v30);
  v35 = a3->rightmove;
  v36 = a3->forwardmove;
    if (v36 <= 10) {
      v37 = 2 * (v36 <= -11);
        if (v35 > 10) {
        LABEL_31:
          v37 |= 4u;
          v38 = a1->bit;
          v123 = v38;
          v39 = v38 & 7;
          if ((v38 & 7) != 0)
            goto LABEL_146;
          goto LABEL_32;
        }
    }
    else {
      v37 = 1;
      if (v35 > 10)
        goto LABEL_31;
    }
  if (v35 <= -11)
    v37 |= 8u;
  v38 = a1->bit;
  v123 = v38;
  v39 = v38 & 7;
    if ((v38 & 7) != 0) {
    LABEL_146:
      v15 = (int)*(unsigned __int8 *)(a1->data + (v38 >> 3)) >> v39;
      a1->bit = ++v123;
        if ((v15 & 1) == 0) {
          v44 = v37;
          v45 = &a4->rightmove;
          if ((v37 & 1) != 0)
            goto LABEL_41;
          goto LABEL_148;
        }
      goto LABEL_34;
    }
LABEL_32:
  v40 = a1->readcount;
    if (v40 < (signed int)a1->cursize) {
      v123 = 8 * v40;
      a1->bit = 8 * v40;
      a1->readcount = v40 + 1;
      v38 = 8 * v40;
      goto LABEL_146;
    }
  a1->overflowed = 1;
LABEL_34:
  v132 = 0;
  v41 = 0;
    while (1) {
      v42 = v123 & 7;
      if ((v123 & 7) == 0)
        break;
    LABEL_38:
      v132 |= (((int)*(unsigned __int8 *)(a1->data + (v123++ >> 3)) >> v42) & 1)
              << v41;
      a1->bit = v123;
        if (++v41 == 4) {
          LOBYTE(v15) = v132;
          goto LABEL_40;
        }
    }
  v43 = a1->readcount;
    if (v43 < (signed int)a1->cursize) {
      v123 = 8 * v43;
      a1->bit = 8 * v43;
      a1->readcount = v43 + 1;
      goto LABEL_38;
    }
  a1->overflowed = 1;
  LOBYTE(v15) = -1;
LABEL_40:
  v44 = v15 ^ dword_312C10 & v138;
  v45 = &a4->rightmove;
    if ((v44 & 1) != 0) {
    LABEL_41:
      a4->forwardmove = 127;
      if ((v44 & 4) != 0)
        goto LABEL_42;
    LABEL_149:
      LOBYTE(v15) = (v44 & 8) != 0 ? 0x81 : 0;
      *v45 = v15;
      return v15;
    }
LABEL_148:
  LOBYTE(v15) = (v44 & 2) != 0 ? 0x81 : 0;
  a4->forwardmove = v15;
  if ((v44 & 4) == 0)
    goto LABEL_149;
LABEL_42:
  *v45 = 127;
  return v15;
}

void __cdecl MSG_WriteDeltaUsercmdKey(struct msg_t *msg, int key,
                                      struct usercmd_s *from,
                                      struct usercmd_s *to)
{
  uint32_t v4;         // edx
  int cursize;         // esi
  msg_t *v6;           // ecx
  int8_t rightmove;    // dl
  int8_t forwardmove;  // al
  int v9;              // eax
  int8_t v10;          // dl
  int8_t v11;          // al
  int v12;             // edi
  int32_t buttons;     // ebx
  int32_t v14;         // ecx
  uint32_t v15;        // edx
  int v16;             // ebx
  float v17;           // edx
  __int16 v18;         // cx
  uint32_t v19;        // edx
  float v20;           // edx
  __int16 v21;         // cx
  uint32_t v22;        // edx
  int result;          // eax
  int v24;             // ebx
  msg_t *v25;          // edx
  int v26;             // esi
  char v27;            // di
  uint32_t v28;        // edx
  uint32_t serverTime; // ecx
  int v30;             // edx
  msg_t *v31;          // eax
  char v32;            // bl
  uint32_t maxsize;    // edx
  int v34;             // ebx
  float v35;           // edx
  __int16 v36;         // cx
  uint32_t v37;        // edx
  float v38;           // edx
  __int16 v39;         // cx
  int v40;             // edx
  msg_t *v41;          // ebx
  int v42;             // ebx
  msg_t *v43;          // edx
  float v44;           // edx
  __int16 v45;         // cx
  uint32_t v46;        // edx
  int32_t v47;         // edx
  int v48;             // ebx
  int weapon;          // edx
  int v50;             // ebx
  int offHandIndex;    // edx
  int v52;             // ebx
  char v53;            // bl
  char v54;            // dl
  msg_t *v55;          // eax
  char v56;            // dl
  char v57;            // dl
  char v58;            // bl
  int v59;             // esi
  char k;              // di
  int32_t v61;         // eax
  int v62;             // edi
  uint32_t v63;        // edx
  char v64;            // bl
  int v65;             // esi
  char j;              // di
  int v67;             // edi
  uint32_t v68;        // edx
  char v69;            // bl
  int v70;             // esi
  char i;              // di
  int v72;             // edi
  uint32_t v73;        // edx
  char v74;            // bl
  int v75;             // esi
  char v76;            // di
  uint32_t v77;        // edx
  char v78;            // dl
  _BYTE *v79;          // ebx
  _BYTE *v80;          // ebx
  char v81;            // dl
  char v82;            // dl
  char v83;            // dl
  char v84;            // dl
  char v85;            // bl
  char v86;            // bl
  char v87;            // dl
  int v88;             // [esp+0h] [ebp-1Ch]
  int32_t bit;         // [esp+0h] [ebp-1Ch]
  int32_t v90;         // [esp+0h] [ebp-1Ch]
  int32_t v91;         // [esp+0h] [ebp-1Ch]
  int32_t v92;         // [esp+0h] [ebp-1Ch]
  int32_t v93;         // [esp+0h] [ebp-1Ch]
  int32_t v94;         // [esp+0h] [ebp-1Ch]
  int32_t v95;         // [esp+0h] [ebp-1Ch]
  int32_t v96;         // [esp+0h] [ebp-1Ch]
  int32_t v97;         // [esp+0h] [ebp-1Ch]
  int32_t v98;         // [esp+0h] [ebp-1Ch]
  int32_t v99;         // [esp+0h] [ebp-1Ch]
  int32_t v100;        // [esp+0h] [ebp-1Ch]
  int32_t v101;        // [esp+0h] [ebp-1Ch]
  int32_t v102;        // [esp+0h] [ebp-1Ch]
  int32_t v103;        // [esp+0h] [ebp-1Ch]
  int32_t v104;        // [esp+0h] [ebp-1Ch]
  int32_t v105;        // [esp+0h] [ebp-1Ch]
  int32_t v106;        // [esp+0h] [ebp-1Ch]
  int32_t v107;        // [esp+0h] [ebp-1Ch]
  int32_t v108;        // [esp+0h] [ebp-1Ch]
  int32_t v109;        // [esp+0h] [ebp-1Ch]
  int32_t v110;        // [esp+0h] [ebp-1Ch]
  int32_t v111;        // [esp+0h] [ebp-1Ch]
  int32_t v112;        // [esp+0h] [ebp-1Ch]
  int32_t v113;        // [esp+0h] [ebp-1Ch]
  int32_t v114;        // [esp+0h] [ebp-1Ch]
  int32_t v115;        // [esp+0h] [ebp-1Ch]
  int32_t v116;        // [esp+0h] [ebp-1Ch]
  int32_t v117;        // [esp+0h] [ebp-1Ch]
  int32_t v118;        // [esp+0h] [ebp-1Ch]
  int32_t v119;        // [esp+0h] [ebp-1Ch]
  int32_t v120;        // [esp+0h] [ebp-1Ch]
  int v121;            // [esp+4h] [ebp-18h]
  int v122;            // [esp+4h] [ebp-18h]
  uint32_t v123;       // [esp+8h] [ebp-14h]
  uint32_t v124;       // [esp+Ch] [ebp-10h]

  v4 = a4->serverTime - a3->serverTime;
    if (v4 > 0xFF) {
      cursize = a1->cursize;
        if (cursize < (signed int)a1->maxsize) {
          bit = a1->bit;
            if ((bit & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              bit = a1->bit;
            }
          a1->bit = bit + 1;
          serverTime = a4->serverTime;
          v30 = cursize + 4;
          v31 = a1;
          if (cursize + 4 <= (signed int)a1->maxsize)
            goto LABEL_45;
        }
        else {
          a1->overflowed = 1;
          serverTime = a4->serverTime;
          v30 = cursize + 4;
          v31 = a1;
            if (cursize + 4 <= (signed int)a1->maxsize) {
            LABEL_45:
              *(_DWORD *)(v31->data + cursize) = serverTime;
              cursize = v30;
              v31->cursize = v30;
              goto LABEL_46;
            }
        }
      v31->overflowed = 1;
      goto LABEL_46;
    }
  cursize = a1->cursize;
    if (cursize < (signed int)a1->maxsize) {
      v90 = a1->bit;
      v53 = v90 & 7;
        if ((v90 & 7) == 0) {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          ++a1->cursize;
          v90 = a1->bit;
        }
      *(_BYTE *)(a1->data + (v90 >> 3)) |= 1 << v53;
      ++a1->bit;
      cursize = a1->cursize;
      v6 = a1;
        if (cursize < (signed int)a1->maxsize) {
        LABEL_4:
          *(_BYTE *)(v6->data + cursize) = v4;
          cursize = v6->cursize + 1;
          v6->cursize = cursize;
          rightmove = a4->rightmove;
          forwardmove = a4->forwardmove;
          if (forwardmove <= 10)
            goto LABEL_5;
          goto LABEL_47;
        }
    }
    else {
      a1->overflowed = 1;
      v6 = a1;
      if (cursize < (signed int)a1->maxsize)
        goto LABEL_4;
    }
  v6->overflowed = 1;
LABEL_46:
  rightmove = a4->rightmove;
  forwardmove = a4->forwardmove;
    if (forwardmove <= 10) {
    LABEL_5:
      v121 = 2 * (forwardmove <= -11);
      if (rightmove <= 10)
        goto LABEL_6;
    LABEL_48:
      v122 = v121 | 4;
      v10 = a3->rightmove;
      v11 = a3->forwardmove;
      if (v11 <= 10)
        goto LABEL_9;
      goto LABEL_49;
    }
LABEL_47:
  v121 = 1;
  if (rightmove > 10)
    goto LABEL_48;
LABEL_6:
  v9 = v121 | 8;
  if (rightmove > -11)
    v9 = v121;
  v122 = v9;
  v10 = a3->rightmove;
  v11 = a3->forwardmove;
    if (v11 <= 10) {
    LABEL_9:
      v12 = 2 * (v11 <= -11);
      if (v10 <= 10)
        goto LABEL_10;
    LABEL_50:
      v12 |= 4u;
      buttons = a3->buttons;
      v14 = a4->buttons;
      if (buttons >> 1 != v14 >> 1)
        goto LABEL_51;
      goto LABEL_13;
    }
LABEL_49:
  v12 = 1;
  if (v10 > 10)
    goto LABEL_50;
LABEL_10:
  if (v10 <= -11)
    v12 |= 8u;
  buttons = a3->buttons;
  v14 = a4->buttons;
    if (buttons >> 1 != v14 >> 1) {
    LABEL_51:
      v32 = a2 ^ 1;
      maxsize = a1->maxsize;
        if ((int)(maxsize - cursize) > 3) {
          v100 = a1->bit;
          v57 = v100 & 7;
            if ((v100 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              v100 = a1->bit;
            }
            if ((v32 & 1) != 0) {
              *(_BYTE *)(a1->data + (v100 >> 3)) |= 1 << v57;
              cursize = a1->cursize;
              v100 = a1->bit;
            }
          a1->bit = v100 + 1;
          maxsize = a1->maxsize;
        }
        else {
          a1->overflowed = 1;
        }
        if ((int)(maxsize - cursize) > 3) {
          v99 = a1->bit;
          v56 = v99 & 7;
            if ((v99 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              v99 = a1->bit;
            }
            if ((v32 & 1) != 0) {
              *(_BYTE *)(a1->data + (v99 >> 3)) |= 1 << v56;
              cursize = a1->cursize;
              v99 = a1->bit;
            }
          a1->bit = v99 + 1;
          maxsize = a1->maxsize;
        }
        else {
          a1->overflowed = 1;
        }
      v34 = a4->buttons ^ a2;
        if ((int)(maxsize - cursize) > 3) {
          v91 = a1->bit;
          v54 = v91 & 7;
            if ((v91 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              v91 = a1->bit;
            }
            if ((v34 & 1) != 0) {
              *(_BYTE *)(a1->data + (v91 >> 3)) |= 1 << v54;
              cursize = a1->cursize;
              v91 = a1->bit;
            }
          a1->bit = v91 + 1;
          v35 = a4->angles[0];
          if (LOWORD(a3->angles[0]) != LOWORD(v35))
            goto LABEL_57;
        }
        else {
          a1->overflowed = 1;
          v35 = a4->angles[0];
            if (LOWORD(a3->angles[0]) != LOWORD(v35)) {
            LABEL_57:
                if (cursize < (signed int)a1->maxsize) {
                  v102 = a1->bit;
                    if ((v102 & 7) != 0) {
                      *(_BYTE *)(a1->data + (v102 >> 3)) |= 1 << (v102 & 7);
                    }
                    else {
                      a1->bit = 8 * cursize;
                      *(_BYTE *)(a1->data + cursize) = 0;
                      ++a1->cursize;
                      v80 = (_BYTE *)(a1->data + (a1->bit >> 3));
                      *v80 |= 1u;
                    }
                  ++a1->bit;
                  cursize = a1->cursize;
                }
                else {
                  a1->overflowed = 1;
                }
              v36 = LOWORD(v35) ^ a2;
              v37 = cursize + 2;
                if (cursize + 2 > (signed int)a1->maxsize) {
                  a1->overflowed = 1;
                }
                else {
                  *(_WORD *)(a1->data + cursize) = v36;
                  cursize += 2;
                  a1->cursize = v37;
                }
              goto LABEL_61;
            }
        }
        if (cursize < (signed int)a1->maxsize) {
          v92 = a1->bit;
            if ((v92 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              v92 = a1->bit;
            }
          a1->bit = v92 + 1;
          v38 = a4->angles[1];
          if (LOWORD(a3->angles[1]) != LOWORD(v38))
            goto LABEL_62;
          goto LABEL_108;
        }
      a1->overflowed = 1;
    LABEL_61:
      v38 = a4->angles[1];
        if (LOWORD(a3->angles[1]) != LOWORD(v38)) {
        LABEL_62:
            if (cursize < (signed int)a1->maxsize) {
              v101 = a1->bit;
              v58 = v101 & 7;
                if ((v101 & 7) == 0) {
                  a1->bit = 8 * cursize;
                  *(_BYTE *)(a1->data + cursize) = 0;
                  ++a1->cursize;
                  v101 = a1->bit;
                }
              *(_BYTE *)(a1->data + (v101 >> 3)) |= 1 << v58;
              ++a1->bit;
              cursize = a1->cursize;
              v39 = LOWORD(v38) ^ a2;
              v40 = cursize + 2;
              v41 = a1;
              if (cursize + 2 <= (signed int)a1->maxsize)
                goto LABEL_64;
            }
            else {
              a1->overflowed = 1;
              v39 = LOWORD(v38) ^ a2;
              v40 = cursize + 2;
              v41 = a1;
                if (cursize + 2 <= (signed int)a1->maxsize) {
                LABEL_64:
                  *(_WORD *)(v41->data + cursize) = v39;
                  cursize = v40;
                  v41->cursize = v40;
                  goto LABEL_65;
                }
            }
          v55 = v41;
        LABEL_146:
          v55->overflowed = 1;
        LABEL_65:
          if (v122 != v12)
            goto LABEL_66;
          goto LABEL_112;
        }
    LABEL_108:
      v55 = a1;
        if (cursize < (signed int)a1->maxsize) {
          v93 = a1->bit;
            if ((v93 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              v93 = a1->bit;
            }
          a1->bit = v93 + 1;
            if (v122 != v12) {
            LABEL_66:
                if (cursize < (signed int)a1->maxsize) {
                  v111 = a1->bit;
                  v78 = v111 & 7;
                    if ((v111 & 7) == 0) {
                      a1->bit = 8 * cursize;
                      *(_BYTE *)(a1->data + cursize) = 0;
                      ++a1->cursize;
                      v111 = a1->bit;
                    }
                  *(_BYTE *)(a1->data + (v111 >> 3)) |= 1 << v78;
                  ++a1->bit;
                  cursize = a1->cursize;
                }
                else {
                  a1->overflowed = 1;
                }
              v42 = a2 ^ v122;
              v43 = a1;
                if ((signed int)(a1->maxsize - cursize) > 3) {
                  v110 = a1->bit;
                  v75 = 3;
                  v76 = v110 & 7;
                  if ((v110 & 7) != 0)
                    goto LABEL_190;
                LABEL_189:
                  v77 = a1->cursize;
                  a1->bit = 8 * v77;
                  *(_BYTE *)(a1->data + v77) = 0;
                  ++a1->cursize;
                  v110 = a1->bit;
                    while (1) {
                    LABEL_190:
                        if ((v42 & 1) != 0) {
                          *(_BYTE *)(a1->data + (v110 >> 3)) |= 1 << v76;
                          v110 = a1->bit;
                        }
                      a1->bit = ++v110;
                      v42 >>= 1;
                      if (!v75)
                        break;
                      --v75;
                      v76 = v110 & 7;
                      if ((v110 & 7) == 0)
                        goto LABEL_189;
                    }
                  cursize = a1->cursize;
                LABEL_70:
                  v123 = a4->serverTime ^ a2;
                  v44 = a4->angles[2];
                    if (LOWORD(a3->angles[2]) != LOWORD(v44)) {
                    LABEL_71:
                        if (cursize < (signed int)a1->maxsize) {
                          v109 = a1->bit;
                            if ((v109 & 7) != 0) {
                              *(_BYTE *)(a1->data + (v109 >> 3)) |=
                                  1 << (v109 & 7);
                            }
                            else {
                              a1->bit = 8 * cursize;
                              *(_BYTE *)(a1->data + cursize) = 0;
                              ++a1->cursize;
                              v79 = (_BYTE *)(a1->data + (a1->bit >> 3));
                              *v79 |= 1u;
                            }
                          ++a1->bit;
                          cursize = a1->cursize;
                        }
                        else {
                          a1->overflowed = 1;
                        }
                      v45 = LOWORD(v44) ^ v123;
                      v46 = cursize + 2;
                        if (cursize + 2 > (signed int)a1->maxsize) {
                          a1->overflowed = 1;
                        }
                        else {
                          *(_WORD *)(a1->data + cursize) = v45;
                          cursize += 2;
                          a1->cursize = v46;
                        }
                      goto LABEL_75;
                    }
                LABEL_116:
                    if (cursize < (signed int)a1->maxsize) {
                      v95 = a1->bit;
                        if ((v95 & 7) == 0) {
                          a1->bit = 8 * cursize;
                          *(_BYTE *)(a1->data + cursize) = 0;
                          cursize = a1->cursize + 1;
                          a1->cursize = cursize;
                          v95 = a1->bit;
                        }
                      a1->bit = v95 + 1;
                      v47 = a4->buttons >> 1;
                      if (v47 != a3->buttons >> 1)
                        goto LABEL_76;
                      goto LABEL_120;
                    }
                  a1->overflowed = 1;
                LABEL_75:
                  v47 = a4->buttons >> 1;
                    if (v47 != a3->buttons >> 1) {
                    LABEL_76:
                        if (cursize < (signed int)a1->maxsize) {
                          v108 = a1->bit;
                          v74 = v108 & 7;
                            if ((v108 & 7) == 0) {
                              a1->bit = 8 * cursize;
                              *(_BYTE *)(a1->data + cursize) = 0;
                              ++a1->cursize;
                              v108 = a1->bit;
                            }
                          *(_BYTE *)(a1->data + (v108 >> 3)) |= 1 << v74;
                          ++a1->bit;
                          cursize = a1->cursize;
                        }
                        else {
                          a1->overflowed = 1;
                        }
                      v48 = v123 ^ v47;
                        if ((signed int)(a1->maxsize - cursize) > 3) {
                          v70 = 18;
                          v107 = a1->bit;
                            for (i = v107;; i = v107) {
                              --v70;
                              v72 = i & 7;
                                if (!v72) {
                                  v73 = a1->cursize;
                                  a1->bit = 8 * v73;
                                  *(_BYTE *)(a1->data + v73) = 0;
                                  ++a1->cursize;
                                  v107 = a1->bit;
                                }
                                if ((v48 & 1) != 0) {
                                  *(_BYTE *)(a1->data + (v107 >> 3)) |= 1
                                                                        << v72;
                                  v107 = a1->bit;
                                }
                              a1->bit = ++v107;
                              v48 >>= 1;
                              if (!v70)
                                break;
                            }
                          cursize = a1->cursize;
                        }
                        else {
                          a1->overflowed = 1;
                        }
                      goto LABEL_80;
                    }
                LABEL_120:
                    if (cursize < (signed int)a1->maxsize) {
                      v96 = a1->bit;
                        if ((v96 & 7) == 0) {
                          a1->bit = 8 * cursize;
                          *(_BYTE *)(a1->data + cursize) = 0;
                          cursize = a1->cursize + 1;
                          a1->cursize = cursize;
                          v96 = a1->bit;
                        }
                      a1->bit = v96 + 1;
                      weapon = (unsigned __int8)a4->weapon;
                      if (weapon != (unsigned __int8)a3->weapon)
                        goto LABEL_81;
                      goto LABEL_124;
                    }
                  a1->overflowed = 1;
                LABEL_80:
                  weapon = (unsigned __int8)a4->weapon;
                    if (weapon != (unsigned __int8)a3->weapon) {
                    LABEL_81:
                        if (cursize < (signed int)a1->maxsize) {
                          v106 = a1->bit;
                          v69 = v106 & 7;
                            if ((v106 & 7) == 0) {
                              a1->bit = 8 * cursize;
                              *(_BYTE *)(a1->data + cursize) = 0;
                              ++a1->cursize;
                              v106 = a1->bit;
                            }
                          *(_BYTE *)(a1->data + (v106 >> 3)) |= 1 << v69;
                          ++a1->bit;
                          cursize = a1->cursize;
                        }
                        else {
                          a1->overflowed = 1;
                        }
                      v50 = weapon ^ v123;
                        if ((signed int)(a1->maxsize - cursize) > 3) {
                          v65 = 7;
                          v105 = a1->bit;
                            for (j = v105;; j = v105) {
                              --v65;
                              v67 = j & 7;
                                if (!v67) {
                                  v68 = a1->cursize;
                                  a1->bit = 8 * v68;
                                  *(_BYTE *)(a1->data + v68) = 0;
                                  ++a1->cursize;
                                  v105 = a1->bit;
                                }
                                if ((v50 & 1) != 0) {
                                  *(_BYTE *)(a1->data + (v105 >> 3)) |= 1
                                                                        << v67;
                                  v105 = a1->bit;
                                }
                              a1->bit = ++v105;
                              v50 >>= 1;
                              if (!v65)
                                break;
                            }
                          cursize = a1->cursize;
                        }
                        else {
                          a1->overflowed = 1;
                        }
                      goto LABEL_85;
                    }
                LABEL_124:
                    if (cursize < (signed int)a1->maxsize) {
                      v97 = a1->bit;
                        if ((v97 & 7) == 0) {
                          a1->bit = 8 * cursize;
                          *(_BYTE *)(a1->data + cursize) = 0;
                          cursize = a1->cursize + 1;
                          a1->cursize = cursize;
                          v97 = a1->bit;
                        }
                      a1->bit = v97 + 1;
                      offHandIndex = a4->offHandIndex;
                        if (offHandIndex != a3->offHandIndex) {
                        LABEL_86:
                            if (cursize < (signed int)a1->maxsize) {
                              v104 = a1->bit;
                              v64 = v104 & 7;
                                if ((v104 & 7) == 0) {
                                  a1->bit = 8 * cursize;
                                  *(_BYTE *)(a1->data + cursize) = 0;
                                  ++a1->cursize;
                                  v104 = a1->bit;
                                }
                              *(_BYTE *)(a1->data + (v104 >> 3)) |= 1 << v64;
                              ++a1->bit;
                              cursize = a1->cursize;
                            }
                            else {
                              a1->overflowed = 1;
                            }
                          v52 = offHandIndex ^ v123;
                          v25 = a1;
                          result = a1->maxsize - cursize;
                            if (result > 3) {
                              v59 = 7;
                              v103 = a1->bit;
                                for (k = v103;; k = result) {
                                  --v59;
                                  v62 = k & 7;
                                    if (!v62) {
                                      v63 = a1->cursize;
                                      a1->bit = 8 * v63;
                                      *(_BYTE *)(a1->data + v63) = 0;
                                      ++a1->cursize;
                                      v103 = a1->bit;
                                    }
                                    if ((v52 & 1) != 0) {
                                      *(_BYTE *)(a1->data + (v103 >> 3)) |=
                                          1 << v62;
                                      v61 = a1->bit;
                                    }
                                    else {
                                      v61 = v103;
                                    }
                                  result = v61 + 1;
                                  v103 = result;
                                  a1->bit = result;
                                  v52 >>= 1;
                                  if (!v59)
                                    break;
                                }
                              return result;
                            }
                        LABEL_89:
                          v25->overflowed = 1;
                          return result;
                        }
                    LABEL_128:
                      result = (int)a1;
                        if (cursize >= (signed int)a1->maxsize) {
                          a1->overflowed = 1;
                          return result;
                        }
                      v98 = a1->bit;
                        if ((v98 & 7) == 0) {
                          a1->bit = 8 * cursize;
                          *(_BYTE *)(a1->data + cursize) = 0;
                          ++a1->cursize;
                          result = a1->bit;
                          v98 = result;
                        }
                      goto LABEL_131;
                    }
                  a1->overflowed = 1;
                LABEL_85:
                  offHandIndex = a4->offHandIndex;
                  if (offHandIndex != a3->offHandIndex)
                    goto LABEL_86;
                  goto LABEL_128;
                }
            LABEL_69:
              v43->overflowed = 1;
              goto LABEL_70;
            }
        LABEL_112:
          v43 = a1;
            if (cursize < (signed int)a1->maxsize) {
              v94 = a1->bit;
                if ((v94 & 7) == 0) {
                  a1->bit = 8 * cursize;
                  *(_BYTE *)(a1->data + cursize) = 0;
                  cursize = a1->cursize + 1;
                  a1->cursize = cursize;
                  v94 = a1->bit;
                }
              a1->bit = v94 + 1;
              v123 = a4->serverTime ^ a2;
              v44 = a4->angles[2];
              if (LOWORD(a3->angles[2]) != LOWORD(v44))
                goto LABEL_71;
              goto LABEL_116;
            }
          goto LABEL_69;
        }
      goto LABEL_146;
    }
LABEL_13:
  if (*(_WORD *)&a3->weapon != *(_WORD *)&a4->weapon ||
      LODWORD(a3->angles[2]) != LODWORD(a4->angles[2]))
    goto LABEL_51;
    if (LODWORD(a3->angles[0]) == LODWORD(a4->angles[0]) &&
        LODWORD(a3->angles[1]) == LODWORD(a4->angles[1]) &&
        (buttons & 1) == (v14 & 1) && v122 == v12) {
      result = a1->maxsize - cursize;
        if (result <= 3) {
          a1->overflowed = 1;
          return result;
        }
      v98 = a1->bit;
      v87 = v98 & 7;
        if ((v98 & 7) == 0) {
          a1->bit = 8 * cursize;
          result = a1->data;
          *(_BYTE *)(result + cursize) = 0;
          ++a1->cursize;
          v98 = a1->bit;
        }
        if ((a2 & 1) != 0) {
          *(_BYTE *)(a1->data + (v98 >> 3)) |= 1 << v87;
          result = a1->bit;
          v98 = result;
        }
    LABEL_131:
      a1->bit = v98 + 1;
      return result;
    }
  v15 = a1->maxsize;
    if ((int)(v15 - cursize) > 3) {
      v114 = a1->bit;
      v83 = v114 & 7;
        if ((v114 & 7) == 0) {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          cursize = a1->cursize + 1;
          a1->cursize = cursize;
          v114 = a1->bit;
        }
        if ((((unsigned __int8)a2 ^ 1) & 1) != 0) {
          *(_BYTE *)(a1->data + (v114 >> 3)) |= 1 << v83;
          cursize = a1->cursize;
          v114 = a1->bit;
        }
      a1->bit = v114 + 1;
      v15 = a1->maxsize;
    }
    else {
      a1->overflowed = 1;
    }
    if ((int)(v15 - cursize) > 3) {
      v113 = a1->bit;
      v82 = v113 & 7;
        if ((v113 & 7) == 0) {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          cursize = a1->cursize + 1;
          a1->cursize = cursize;
          v113 = a1->bit;
        }
        if ((a2 & 1) != 0) {
          *(_BYTE *)(a1->data + (v113 >> 3)) |= 1 << v82;
          cursize = a1->cursize;
          v113 = a1->bit;
        }
      a1->bit = v113 + 1;
      v15 = a1->maxsize;
    }
    else {
      a1->overflowed = 1;
    }
  v124 = a4->serverTime ^ a2;
  v16 = a4->buttons ^ v124;
    if ((int)(v15 - cursize) > 3) {
      v112 = a1->bit;
      v81 = v112 & 7;
        if ((v112 & 7) == 0) {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          cursize = a1->cursize + 1;
          a1->cursize = cursize;
          v112 = a1->bit;
        }
        if ((v16 & 1) != 0) {
          *(_BYTE *)(a1->data + (v112 >> 3)) |= 1 << v81;
          cursize = a1->cursize;
          v112 = a1->bit;
        }
      a1->bit = v112 + 1;
    }
    else {
      a1->overflowed = 1;
    }
  v17 = a4->angles[0];
    if (LOWORD(a3->angles[0]) == LOWORD(v17)) {
        if (cursize < (signed int)a1->maxsize) {
          v120 = a1->bit;
            if ((v120 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              cursize = a1->cursize + 1;
              a1->cursize = cursize;
              v120 = a1->bit;
            }
          a1->bit = v120 + 1;
        }
        else {
          a1->overflowed = 1;
        }
    }
    else {
        if (cursize < (signed int)a1->maxsize) {
          v116 = a1->bit;
          v85 = v116 & 7;
            if ((v116 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              ++a1->cursize;
              v116 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v116 >> 3)) |= 1 << v85;
          ++a1->bit;
          cursize = a1->cursize;
        }
        else {
          a1->overflowed = 1;
        }
      v18 = LOWORD(v17) ^ v124;
      v19 = cursize + 2;
        if (cursize + 2 > (signed int)a1->maxsize) {
          a1->overflowed = 1;
        }
        else {
          *(_WORD *)(a1->data + cursize) = v18;
          cursize += 2;
          a1->cursize = v19;
        }
    }
  v20 = a4->angles[1];
    if (LOWORD(a3->angles[1]) != LOWORD(v20)) {
        if (cursize < (signed int)a1->maxsize) {
          v117 = a1->bit;
          v86 = v117 & 7;
            if ((v117 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              ++a1->cursize;
              v117 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v117 >> 3)) |= 1 << v86;
          ++a1->bit;
          cursize = a1->cursize;
        }
        else {
          a1->overflowed = 1;
        }
      v21 = LOWORD(v20) ^ v124;
      v22 = cursize + 2;
        if (cursize + 2 <= (signed int)a1->maxsize) {
          result = a1->data;
          *(_WORD *)(result + cursize) = v21;
          cursize += 2;
          a1->cursize = v22;
          goto LABEL_32;
        }
      result = (int)a1;
      goto LABEL_232;
    }
  result = (int)a1;
    if (cursize >= (signed int)a1->maxsize) {
    LABEL_232:
      *(_DWORD *)result = 1;
      goto LABEL_32;
    }
  v119 = a1->bit;
    if ((v119 & 7) == 0) {
      a1->bit = 8 * cursize;
      *(_BYTE *)(a1->data + cursize) = 0;
      cursize = a1->cursize + 1;
      a1->cursize = cursize;
      result = a1->bit;
      v119 = result;
    }
  a1->bit = v119 + 1;
LABEL_32:
    if (v122 == v12) {
      v25 = a1;
        if (cursize < (signed int)a1->maxsize) {
          v118 = a1->bit;
            if ((v118 & 7) == 0) {
              a1->bit = 8 * cursize;
              *(_BYTE *)(a1->data + cursize) = 0;
              ++a1->cursize;
              v118 = a1->bit;
            }
          result = v118 + 1;
          a1->bit = v118 + 1;
          return result;
        }
      goto LABEL_89;
    }
    if (cursize < (signed int)a1->maxsize) {
      v115 = a1->bit;
      v84 = v115 & 7;
        if ((v115 & 7) == 0) {
          a1->bit = 8 * cursize;
          *(_BYTE *)(a1->data + cursize) = 0;
          ++a1->cursize;
          v115 = a1->bit;
        }
      *(_BYTE *)(a1->data + (v115 >> 3)) |= 1 << v84;
      ++a1->bit;
      cursize = a1->cursize;
    }
    else {
      a1->overflowed = 1;
    }
  v24 = v124 ^ v122;
  v25 = a1;
  result = a1->maxsize - cursize;
  if (result <= 3)
    goto LABEL_89;
  v26 = 4;
  v88 = a1->bit;
  v27 = v88 & 7;
  if ((v88 & 7) != 0)
    goto LABEL_38;
LABEL_37:
  v28 = a1->cursize;
  a1->bit = 8 * v28;
  *(_BYTE *)(a1->data + v28) = 0;
  ++a1->cursize;
  v88 = a1->bit;
    while (1) {
    LABEL_38:
        if ((v24 & 1) != 0) {
          *(_BYTE *)(a1->data + (v88 >> 3)) |= 1 << v27;
          v88 = a1->bit;
        }
      ++v88;
      result = (int)a1;
      a1->bit = v88;
      v24 >>= 1;
      if (!--v26)
        return result;
      v27 = v88 & 7;
      if ((v88 & 7) == 0)
        goto LABEL_37;
    }
}

int __cdecl MSG_WriteBitsCompress(unsigned char *from, unsigned char *to,
                                  int size)
{
  unsigned __int8 *v4; // ebx
  int v5[7];           // [esp+1Ch] [ebp-1Ch] BYREF

  v5[0] = 0;
  if (!a3)
    return (v5[0] + 7) >> 3;
  v4 = a1;
  do
    Huff_offsetTransmit(&msgHuff.compressor, *v4++, a2, v5);
  while (v4 != &a1[a3]);
  return (v5[0] + 7) >> 3;
}

void __cdecl MSG_Init(struct msg_t *buf, unsigned char *data, int length)
{
  uint32_t result; // eax
  int *v4;         // esi
  int v5;          // edi
  int v6;          // [esp+1Ch] [ebp-1Ch]

    if (!msgInit) {
      msgInit = 1;
      Huff_Init(&msgHuff);
      v6 = 0;
      v4 = (int *)&msg_hData;
        do {
            if (*v4 > 0) {
              v5 = 0;
                do {
                  Huff_addRef(&msgHuff.compressor, v6);
                  Huff_addRef((huff_t *)msgHuff.decompressor, v6);
                  ++v5;
                }
              while (v5 < *v4);
            }
          ++v6;
          ++v4;
        }
      while (v6 != 256);
    }
  memset(a1, 0, sizeof(msg_t));
  a1->data = (int32_t)a2;
  result = a3;
  a1->maxsize = a3;
  return result;
}

void __cdecl MSG_WriteDeltaPlayerstate(struct msg_t *msg,
                                       struct playerState_s *from,
                                       struct playerState_s *to)
{
  int v3;              // esi
  _DWORD *v4;          // ecx
  signed int cursize;  // edx
  int *v6;             // edx
  int v7;              // eax
  int v8;              // eax
  int v9;              // ecx
  uint32_t v10;        // edx
  playerState_s *v11;  // edx
  int v12;             // esi
  uint32_t v13;        // edx
  uint32_t v14;        // edx
  uint32_t v15;        // edx
  int v16;             // esi
  int v17;             // edi
  char m;              // dl
  uint32_t v19;        // edx
  uint32_t v20;        // edx
  _DWORD *v21;         // edi
  char *v22;           // edx
  int n;               // esi
  uint32_t v24;        // edx
  _DWORD *v25;         // edx
  int v26;             // esi
  char *v27;           // edi
  char *v28;           // edx
  int v29;             // esi
  signed int v30;      // edx
  signed int v31;      // edx
  _DWORD *v32;         // edx
  int v33;             // esi
  int32_t result;      // eax
  char v35;            // si
  int v36;             // esi
  int v37;             // eax
  int v38;             // edi
  char i;              // dl
  uint32_t v40;        // edx
  char v41;            // si
  signed int v42;      // ecx
  char v43;            // dl
  int v44;             // esi
  int v45;             // edi
  char k;              // dl
  uint32_t v47;        // edx
  char v48;            // dl
  char v49;            // dl
  int v50;             // eax
  int ii;              // eax
  int v52;             // esi
  int32_t *p_data;     // ecx
  int v54;             // edi
  uint32_t v55;        // edx
  msg_t *v56;          // esi
  char v57;            // dl
  char v58;            // dl
  char v59;            // dl
  char v60;            // dl
  char v61;            // si
  int v62;             // esi
  int v63;             // edi
  char j;              // dl
  uint32_t v65;        // edx
  __int16 v66;         // cx
  uint32_t v67;        // edx
  playerState_s *v68;  // [esp+4Ch] [ebp-275Ch]
  int32_t v69;         // [esp+4Ch] [ebp-275Ch]
  char *v70;           // [esp+4Ch] [ebp-275Ch]
  uint32_t v71;        // [esp+4Ch] [ebp-275Ch]
  uint32_t v72;        // [esp+4Ch] [ebp-275Ch]
  int32_t v73;         // [esp+4Ch] [ebp-275Ch]
  int32_t v74;         // [esp+4Ch] [ebp-275Ch]
  int32_t bit;         // [esp+4Ch] [ebp-275Ch]
  int32_t v76;         // [esp+4Ch] [ebp-275Ch]
  int32_t v77;         // [esp+4Ch] [ebp-275Ch]
  int32_t v78;         // [esp+4Ch] [ebp-275Ch]
  int32_t v79;         // [esp+4Ch] [ebp-275Ch]
  int32_t v80;         // [esp+4Ch] [ebp-275Ch]
  int32_t v81;         // [esp+4Ch] [ebp-275Ch]
  int32_t v82;         // [esp+4Ch] [ebp-275Ch]
  int32_t v83;         // [esp+4Ch] [ebp-275Ch]
  int32_t v84;         // [esp+4Ch] [ebp-275Ch]
  int32_t v85;         // [esp+4Ch] [ebp-275Ch]
  int32_t v86;         // [esp+4Ch] [ebp-275Ch]
  int32_t v87;         // [esp+4Ch] [ebp-275Ch]
  int32_t v88;         // [esp+4Ch] [ebp-275Ch]
  int32_t v89;         // [esp+4Ch] [ebp-275Ch]
  int32_t v90;         // [esp+4Ch] [ebp-275Ch]
  int32_t v91;         // [esp+4Ch] [ebp-275Ch]
  int32_t v92;         // [esp+4Ch] [ebp-275Ch]
  int32_t v93;         // [esp+4Ch] [ebp-275Ch]
  int32_t v94;         // [esp+4Ch] [ebp-275Ch]
  int32_t v95;         // [esp+4Ch] [ebp-275Ch]
  int32_t v96;         // [esp+4Ch] [ebp-275Ch]
  uint8_t *v97;        // [esp+58h] [ebp-2750h]
  uint8_t *objective;  // [esp+5Ch] [ebp-274Ch]
  int v99;             // [esp+60h] [ebp-2748h]
  uint8_t *v100;       // [esp+64h] [ebp-2744h]
  int v101;            // [esp+68h] [ebp-2740h]
  uint8_t *v102;       // [esp+6Ch] [ebp-273Ch]
  signed int v103;     // [esp+70h] [ebp-2738h]
  int v104;            // [esp+80h] [ebp-2728h]
  int v105;            // [esp+84h] [ebp-2724h]
  int v106;            // [esp+88h] [ebp-2720h]
  int v107;            // [esp+8Ch] [ebp-271Ch]
  int v108;            // [esp+90h] [ebp-2718h]
  int v109;            // [esp+94h] [ebp-2714h]
  int v110;            // [esp+98h] [ebp-2710h]
  int v111;            // [esp+9Ch] [ebp-270Ch]
  char v112;           // [esp+A0h] [ebp-2708h]
  char v113;           // [esp+A4h] [ebp-2704h]
  char v114;           // [esp+A8h] [ebp-2700h]
  char v115;           // [esp+ACh] [ebp-26FCh]
  char v116;           // [esp+B0h] [ebp-26F8h]
  playerState_s *v117; // [esp+B4h] [ebp-26F4h]
  int v118;            // [esp+B8h] [ebp-26F0h]
  int v119;            // [esp+BCh] [ebp-26ECh]
  _DWORD *v120;        // [esp+C0h] [ebp-26E8h]
  int v121;            // [esp+C8h] [ebp-26E0h]
  int v122;            // [esp+CCh] [ebp-26DCh]
  _BYTE __b[9896];     // [esp+D8h] [ebp-26D0h] BYREF
  _DWORD v124[10];     // [esp+2780h] [ebp-28h] BYREF

    if (!a2) {
      memset(__b, 0, sizeof(__b));
      a2 = (playerState_s *)__b;
    }
  v107 = 0;
  v3 = 0;
  v4 = &unk_332604;
    do {
        while (*(_DWORD *)&a2->commandTime[*v4] !=
               *(_DWORD *)&a3->commandTime[*v4]) {
          v107 = ++v3;
          v4 += 3;
          if (v3 > 104)
            goto LABEL_7;
        }
      ++v3;
      v4 += 3;
    }
  while (v3 <= 104);
LABEL_7:
  cursize = a1->cursize;
  v103 = cursize;
    if (cursize >= (signed int)a1->maxsize) {
      a1->overflowed = 1;
    }
    else {
      *(_BYTE *)(a1->data + cursize) = v107;
      v103 = a1->cursize + 1;
      a1->cursize = v103;
    }
    if (v107 > 0) {
      v105 = 0;
      v120 = &unk_332604;
        while (1) {
          v6 = (int *)&a3->commandTime[*v120];
            if (*(_DWORD *)&a2->commandTime[*v120] == *v6) {
                if (v103 < (signed int)a1->maxsize) {
                  bit = a1->bit;
                    if ((bit & 7) == 0) {
                      a1->bit = 8 * v103;
                      *(_BYTE *)(a1->data + v103) = 0;
                      v103 = a1->cursize + 1;
                      a1->cursize = v103;
                      bit = a1->bit;
                    }
                  a1->bit = bit + 1;
                  goto LABEL_20;
                }
            LABEL_102:
              a1->overflowed = 1;
              goto LABEL_20;
            }
            if (v103 < (signed int)a1->maxsize) {
              v73 = a1->bit;
              v35 = v73 & 7;
                if ((v73 & 7) == 0) {
                  a1->bit = 8 * v103;
                  *(_BYTE *)(a1->data + v103) = 0;
                  ++a1->cursize;
                  v73 = a1->bit;
                }
              *(_BYTE *)(a1->data + (v73 >> 3)) |= 1 << v35;
              ++a1->bit;
              v103 = a1->cursize;
              v7 = v120[1];
                if (v7) {
                LABEL_106:
                    if (v7 != -100) {
                      v110 = *v6;
                      v36 = v7;
                      v37 = -v7;
                      if (v36 <= -1)
                        v36 = v37;
                      v111 = v36 & 7;
                        if ((v36 & 7) != 0) {
                            if ((signed int)(a1->maxsize - v103) <= 3) {
                              a1->overflowed = 1;
                              v36 -= v111;
                              v110 >>= v111;
                            }
                            else {
                              v38 = *v6;
                              v119 = 0;
                              v74 = a1->bit;
                                for (i = v74;; i = v74) {
                                  v113 = i & 7;
                                    if ((i & 7) == 0) {
                                      v40 = a1->cursize;
                                      a1->bit = 8 * v40;
                                      *(_BYTE *)(a1->data + v40) = 0;
                                      ++a1->cursize;
                                      v74 = a1->bit;
                                    }
                                    if ((v38 & 1) != 0) {
                                      *(_BYTE *)(a1->data + (v74 >> 3)) |=
                                          1 << v113;
                                      v74 = a1->bit;
                                    }
                                  a1->bit = ++v74;
                                  v38 >>= 1;
                                  if (v111 == ++v119)
                                    break;
                                }
                              v103 = a1->cursize;
                              v36 -= v111;
                              v110 >>= v111;
                            }
                        }
                        for (; v36; v36 -= 8) {
                            if (v103 < (signed int)a1->maxsize) {
                              *(_BYTE *)(a1->data + v103) = v110;
                              v103 = a1->cursize + 1;
                              a1->cursize = v103;
                            }
                            else {
                              a1->overflowed = 1;
                            }
                          v110 >>= 8;
                        }
                      goto LABEL_20;
                    }
                    if (*v6) {
                        if (v103 >= (signed int)a1->maxsize) {
                          a1->overflowed = 1;
                        }
                        else {
                          v92 = a1->bit;
                          v61 = v92 & 7;
                            if ((v92 & 7) == 0) {
                              a1->bit = 8 * v103;
                              *(_BYTE *)(a1->data + v103) = 0;
                              ++a1->cursize;
                              v92 = a1->bit;
                            }
                          *(_BYTE *)(a1->data + (v92 >> 3)) |= 1 << v61;
                          ++a1->bit;
                          v103 = a1->cursize;
                        }
                      v66 = (int)(float)(*(float *)v6 * 182.04445);
                      v67 = v103 + 2;
                        if (v103 + 2 <= (signed int)a1->maxsize) {
                          *(_WORD *)(a1->data + v103) = v66;
                          v103 += 2;
                          a1->cursize = v67;
                          goto LABEL_20;
                        }
                    }
                    else if (v103 < (signed int)a1->maxsize) {
                      v96 = a1->bit;
                        if ((v96 & 7) == 0) {
                          a1->bit = 8 * v103;
                          *(_BYTE *)(a1->data + v103) = 0;
                          v103 = a1->cursize + 1;
                          a1->cursize = v103;
                          v96 = a1->bit;
                        }
                      a1->bit = v96 + 1;
                      goto LABEL_20;
                    }
                  goto LABEL_102;
                }
            }
            else {
              a1->overflowed = 1;
              v7 = v120[1];
              if (v7)
                goto LABEL_106;
            }
            if (*(float *)v6 == (float)(int)*(float *)v6) {
              v8 = (int)*(float *)v6 + 4096;
              if ((unsigned int)v8 < 0x2000)
                break;
            }
            if (v103 < (signed int)a1->maxsize) {
              v76 = a1->bit;
              v41 = v76 & 7;
                if ((v76 & 7) == 0) {
                  a1->bit = 8 * v103;
                  *(_BYTE *)(a1->data + v103) = 0;
                  ++a1->cursize;
                  v76 = a1->bit;
                }
              *(_BYTE *)(a1->data + (v76 >> 3)) |= 1 << v41;
              ++a1->bit;
              v103 = a1->cursize;
            }
            else {
              a1->overflowed = 1;
            }
          v9 = *v6;
          v10 = v103 + 4;
          if (v103 + 4 > (signed int)a1->maxsize)
            goto LABEL_102;
          *(_DWORD *)(a1->data + v103) = v9;
          v103 += 4;
          a1->cursize = v10;
        LABEL_20:
          ++v105;
          v120 += 3;
          if (v107 == v105)
            goto LABEL_21;
        }
        if (v103 < (signed int)a1->maxsize) {
          v93 = a1->bit;
            if ((v93 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              v103 = a1->cursize + 1;
              a1->cursize = v103;
              v93 = a1->bit;
            }
          a1->bit = v93 + 1;
          if ((signed int)(a1->maxsize - v103) <= 3)
            goto LABEL_139;
        }
        else {
          a1->overflowed = 1;
            if ((signed int)(a1->maxsize - v103) <= 3) {
            LABEL_139:
              a1->overflowed = 1;
              v42 = v103;
              goto LABEL_140;
            }
        }
      v62 = v8;
      v63 = 5;
      v94 = a1->bit;
        for (j = v94;; j = v94) {
          --v63;
          v112 = j & 7;
            if ((j & 7) == 0) {
              v65 = a1->cursize;
              a1->bit = 8 * v65;
              *(_BYTE *)(a1->data + v65) = 0;
              ++a1->cursize;
              v94 = a1->bit;
            }
            if ((v62 & 1) != 0) {
              *(_BYTE *)(a1->data + (v94 >> 3)) |= 1 << v112;
              v94 = a1->bit;
            }
          a1->bit = ++v94;
          v62 >>= 1;
          if (!v63)
            break;
        }
      v103 = a1->cursize;
      v42 = v103;
    LABEL_140:
        if (v42 < (signed int)a1->maxsize) {
          *(_BYTE *)(a1->data + v42) = v8 >> 5;
          v103 = a1->cursize + 1;
          a1->cursize = v103;
          goto LABEL_20;
        }
      goto LABEL_102;
    }
LABEL_21:
  v68 = a3;
  v11 = a2;
  v12 = 0;
  v108 = 0;
    do {
      if (*(_DWORD *)v68->stats != *(_DWORD *)v11->stats)
        v108 |= 1 << v12;
      ++v12;
      v68 = (playerState_s *)((char *)v68 + 4);
      v11 = (playerState_s *)((char *)v11 + 4);
    }
  while (v12 != 6);
    if (v108) {
        if (v103 < (signed int)a1->maxsize) {
          v78 = a1->bit;
          v43 = v78 & 7;
            if ((v78 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              ++a1->cursize;
              v78 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v78 >> 3)) |= 1 << v43;
          ++a1->bit;
          v103 = a1->cursize;
          if ((signed int)(a1->maxsize - v103) <= 3)
            goto LABEL_28;
        }
        else {
          a1->overflowed = 1;
            if ((signed int)(a1->maxsize - v103) <= 3) {
            LABEL_28:
              a1->overflowed = 1;
              goto LABEL_29;
            }
        }
      v44 = v108;
      v45 = 6;
      v79 = a1->bit;
        for (k = v79;; k = v79) {
          --v45;
          v114 = k & 7;
            if ((k & 7) == 0) {
              v47 = a1->cursize;
              a1->bit = 8 * v47;
              *(_BYTE *)(a1->data + v47) = 0;
              ++a1->cursize;
              v79 = a1->bit;
            }
            if ((v44 & 1) != 0) {
              *(_BYTE *)(a1->data + (v79 >> 3)) |= 1 << v114;
              v79 = a1->bit;
            }
          a1->bit = ++v79;
          v44 >>= 1;
          if (!v45)
            break;
        }
      v103 = a1->cursize;
    LABEL_29:
        if ((v108 & 1) != 0) {
          v13 = v103 + 2;
            if (v103 + 2 <= (signed int)a1->maxsize) {
              *(_WORD *)(a1->data + v103) = *(_DWORD *)a3->stats;
              v103 += 2;
              a1->cursize = v13;
            }
            else {
              a1->overflowed = 1;
            }
        }
        if ((v108 & 2) != 0) {
          v14 = v103 + 2;
            if (v103 + 2 <= (signed int)a1->maxsize) {
              *(_WORD *)(a1->data + v103) = *(_DWORD *)&a3->stats[4];
              v103 += 2;
              a1->cursize = v14;
            }
            else {
              a1->overflowed = 1;
            }
        }
        if ((v108 & 4) != 0) {
          v15 = v103 + 2;
            if (v103 + 2 <= (signed int)a1->maxsize) {
              *(_WORD *)(a1->data + v103) = *(_DWORD *)&a3->stats[8];
              v103 += 2;
              a1->cursize = v15;
            }
            else {
              a1->overflowed = 1;
            }
        }
        if ((v108 & 8) != 0) {
          v16 = *(_DWORD *)&a3->stats[12];
            if ((signed int)(a1->maxsize - v103) <= 3) {
              a1->overflowed = 1;
            }
            else {
              v17 = 6;
              v69 = a1->bit;
                for (m = v69;; m = v69) {
                  --v17;
                  v115 = m & 7;
                    if ((m & 7) == 0) {
                      v19 = a1->cursize;
                      a1->bit = 8 * v19;
                      *(_BYTE *)(a1->data + v19) = 0;
                      ++a1->cursize;
                      v69 = a1->bit;
                    }
                    if ((v16 & 1) != 0) {
                      *(_BYTE *)(a1->data + (v69 >> 3)) |= 1 << v115;
                      v69 = a1->bit;
                    }
                  a1->bit = ++v69;
                  v16 >>= 1;
                  if (!v17)
                    break;
                }
              v103 = a1->cursize;
            }
        }
        if ((v108 & 0x10) != 0) {
          v20 = v103 + 2;
            if (v103 + 2 <= (signed int)a1->maxsize) {
              *(_WORD *)(a1->data + v103) = *(_DWORD *)&a3->stats[16];
              v103 += 2;
              a1->cursize = v20;
            }
            else {
              a1->overflowed = 1;
            }
        }
        if ((v108 & 0x20) != 0) {
            if (v103 < (signed int)a1->maxsize) {
              *(_BYTE *)(a1->data + v103) = *(_DWORD *)&a3->stats[20];
              v103 = a1->cursize + 1;
              a1->cursize = v103;
              goto LABEL_54;
            }
          goto LABEL_53;
        }
      goto LABEL_54;
    }
    if (v103 >= (signed int)a1->maxsize) {
    LABEL_53:
      a1->overflowed = 1;
      goto LABEL_54;
    }
  v77 = a1->bit;
    if ((v77 & 7) == 0) {
      a1->bit = 8 * v103;
      *(_BYTE *)(a1->data + v103) = 0;
      v103 = a1->cursize + 1;
      a1->cursize = v103;
      v77 = a1->bit;
    }
  a1->bit = v77 + 1;
LABEL_54:
  v106 = 0;
  v99 = 320;
  v21 = v124;
    do {
      *v21 = 0;
      v70 = &a3->commandTime[v99 + 4];
      v22 = &a2->commandTime[v99 + 4];
        for (n = 0; n != 16; ++n) {
          if (*(_DWORD *)v70 != *(_DWORD *)v22)
            *v21 |= 1 << n;
          v70 += 4;
          v22 += 4;
        }
      ++v106;
      ++v21;
      v99 += 64;
    }
  while (v106 != 4);
    if (v124[0] || v124[1] || v124[2] || v124[3]) {
        if (v103 < (signed int)a1->maxsize) {
          v87 = a1->bit;
          v58 = v87 & 7;
            if ((v87 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              ++a1->cursize;
              v87 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v87 >> 3)) |= 1 << v58;
          ++a1->bit;
          v103 = a1->cursize;
        }
        else {
          a1->overflowed = 1;
        }
      v122 = 0;
      v100 = &a3->stats[20];
        while (1) {
          v104 = v124[v122];
          if (v104)
            break;
            if (v103 < (signed int)a1->maxsize) {
              v82 = a1->bit;
                if ((v82 & 7) == 0) {
                  a1->bit = 8 * v103;
                  *(_BYTE *)(a1->data + v103) = 0;
                  v103 = a1->cursize + 1;
                  a1->cursize = v103;
                  v82 = a1->bit;
                }
              a1->bit = v82 + 1;
            }
            else {
              a1->overflowed = 1;
            }
        LABEL_76:
          ++v122;
          v100 += 64;
          if (v122 == 4)
            goto LABEL_77;
        }
        if (v103 < (signed int)a1->maxsize) {
          v83 = a1->bit;
          v49 = v83 & 7;
            if ((v83 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              ++a1->cursize;
              v83 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v83 >> 3)) |= 1 << v49;
          ++a1->bit;
          v103 = a1->cursize;
          v24 = v103 + 2;
          if (v103 + 2 <= (signed int)a1->maxsize)
            goto LABEL_69;
        }
        else {
          a1->overflowed = 1;
          v24 = v103 + 2;
            if (v103 + 2 <= (signed int)a1->maxsize) {
            LABEL_69:
              *(_WORD *)(a1->data + v103) = v104;
              v103 = v24;
              a1->cursize = v24;
            LABEL_70:
              v25 = v100 + 4;
              v26 = 0;
                while (1) {
                  if (((v104 >> v26) & 1) == 0)
                    goto LABEL_72;
                  v71 = v103 + 2;
                    if (v103 + 2 <= (signed int)a1->maxsize) {
                      *(_WORD *)(a1->data + v103) = *v25;
                      v103 += 2;
                      a1->cursize = v71;
                    LABEL_72:
                      ++v26;
                      ++v25;
                      if (v26 == 16)
                        goto LABEL_76;
                    }
                    else {
                      a1->overflowed = 1;
                      ++v26;
                      ++v25;
                      if (v26 == 16)
                        goto LABEL_76;
                    }
                }
            }
        }
      a1->overflowed = 1;
      goto LABEL_70;
    }
    if (v103 >= (signed int)a1->maxsize) {
      a1->overflowed = 1;
    }
    else {
      v95 = a1->bit;
        if ((v95 & 7) == 0) {
          a1->bit = 8 * v103;
          *(_BYTE *)(a1->data + v103) = 0;
          v103 = a1->cursize + 1;
          a1->cursize = v103;
          v95 = a1->bit;
        }
      a1->bit = v95 + 1;
    }
LABEL_77:
  v118 = 0;
  v102 = &a3->ammo[508];
  v101 = 832;
    do {
      v27 = &a3->commandTime[v101 + 4];
      v28 = &a2->commandTime[v101 + 4];
      v29 = 0;
      v109 = 0;
        do {
          if (*(_DWORD *)v27 != *(_DWORD *)v28)
            v109 |= 1 << v29;
          ++v29;
          v27 += 4;
          v28 += 4;
        }
      while (v29 != 16);
        if (v109) {
            if (v103 < (signed int)a1->maxsize) {
              v80 = a1->bit;
              v48 = v80 & 7;
                if ((v80 & 7) == 0) {
                  a1->bit = 8 * v103;
                  *(_BYTE *)(a1->data + v103) = 0;
                  ++a1->cursize;
                  v80 = a1->bit;
                }
              *(_BYTE *)(a1->data + (v80 >> 3)) |= 1 << v48;
              ++a1->bit;
              v103 = a1->cursize;
              v30 = v103;
            }
            else {
              a1->overflowed = 1;
              v30 = v103;
            }
          v31 = v30 + 2;
            if (v31 > (signed int)a1->maxsize) {
              a1->overflowed = 1;
            }
            else {
              *(_WORD *)(a1->data + v103) = v109;
              v103 = v31;
              a1->cursize = v31;
            }
          v32 = v102 + 4;
          v33 = 0;
            while (1) {
              if (((v109 >> v33) & 1) == 0)
                goto LABEL_89;
              v72 = v103 + 2;
                if (v103 + 2 <= (signed int)a1->maxsize) {
                  *(_WORD *)(a1->data + v103) = *v32;
                  v103 += 2;
                  a1->cursize = v72;
                LABEL_89:
                  ++v33;
                  ++v32;
                  if (v33 == 16)
                    goto LABEL_93;
                }
                else {
                  a1->overflowed = 1;
                  ++v33;
                  ++v32;
                  if (v33 == 16)
                    goto LABEL_93;
                }
            }
        }
        if (v103 < (signed int)a1->maxsize) {
          v81 = a1->bit;
            if ((v81 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              v103 = a1->cursize + 1;
              a1->cursize = v103;
              v81 = a1->bit;
            }
          a1->bit = v81 + 1;
        }
        else {
          a1->overflowed = 1;
        }
    LABEL_93:
      v118 += 16;
      v101 += 64;
      v102 += 64;
    }
  while (v118 != 64);
    if (!memcmp((const char *)a2->objective, (const char *)a3->objective,
                448)) {
        if (v103 < (signed int)a1->maxsize) {
          v89 = a1->bit;
            if ((v89 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              v103 = a1->cursize + 1;
              a1->cursize = v103;
              v89 = a1->bit;
            }
          a1->bit = v89 + 1;
        }
        else {
          a1->overflowed = 1;
        }
    }
    else {
        if (v103 < (signed int)a1->maxsize) {
          v91 = a1->bit;
          v60 = v91 & 7;
            if ((v91 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              ++a1->cursize;
              v91 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v91 >> 3)) |= 1 << v60;
          ++a1->bit;
          v103 = a1->cursize;
        }
        else {
          a1->overflowed = 1;
        }
      v117 = a3;
      v121 = 0;
      objective = a2->objective;
      v97 = a3->objective;
      v52 = *(_DWORD *)a3->objective;
      if ((signed int)(a1->maxsize - v103) > 3)
        goto LABEL_202;
    LABEL_194:
      a1->overflowed = 1;
        while (1) {
          p_data = &objectiveFields.data;
            while (*(_DWORD *)&objective[*p_data] == *(_DWORD *)&v97[*p_data]) {
              p_data += 3;
                if (p_data == (int32_t *)&unk_312BEC) {
                    if (v103 < (signed int)a1->maxsize) {
                      v85 = a1->bit;
                        if ((v85 & 7) == 0) {
                          a1->bit = 8 * v103;
                          *(_BYTE *)(a1->data + v103) = 0;
                          v103 = a1->cursize + 1;
                          a1->cursize = v103;
                          v85 = a1->bit;
                        }
                      a1->bit = v85 + 1;
                    }
                    else {
                      a1->overflowed = 1;
                    }
                  goto LABEL_200;
                }
            }
            if (v103 < (signed int)a1->maxsize) {
              v86 = a1->bit;
              v57 = v86 & 7;
                if ((v86 & 7) == 0) {
                  a1->bit = 8 * v103;
                  *(_BYTE *)(a1->data + v103) = 0;
                  ++a1->cursize;
                  v86 = a1->bit;
                }
              *(_BYTE *)(a1->data + (v86 >> 3)) |= 1 << v57;
              ++a1->bit;
            }
            else {
              a1->overflowed = 1;
            }
          v56 = &objectiveFields;
            do {
              MSG_WriteDeltaField(a1, (int)objective, (int)v97, v56);
              v56 = (msg_t *)((char *)v56 + 12);
            }
          while (v56 != (msg_t *)&unk_312BE8);
          v103 = a1->cursize;
        LABEL_200:
          ++v121;
          v97 += 28;
          objective += 28;
          v117 = (playerState_s *)((char *)v117 + 28);
          if (v121 == 16)
            break;
          v52 = *(_DWORD *)v117->objective;
          if ((signed int)(a1->maxsize - v103) <= 3)
            goto LABEL_194;
        LABEL_202:
          v54 = 3;
          v84 = a1->bit;
          v116 = v84 & 7;
          if ((v84 & 7) != 0)
            goto LABEL_204;
        LABEL_203:
          v55 = a1->cursize;
          a1->bit = 8 * v55;
          *(_BYTE *)(a1->data + v55) = 0;
          ++a1->cursize;
          v84 = a1->bit;
            while (1) {
            LABEL_204:
                if ((v52 & 1) != 0) {
                  *(_BYTE *)(a1->data + (v84 >> 3)) |= 1 << v116;
                  v84 = a1->bit;
                }
              a1->bit = ++v84;
              v52 >>= 1;
              if (!--v54)
                break;
              v116 = v84 & 7;
              if ((v84 & 7) == 0)
                goto LABEL_203;
            }
          v103 = a1->cursize;
        }
    }
  result = memcmp((const char *)&a2->hud, (const char *)&a3->hud, 7936);
    if (result) {
      v50 = 31;
      do
        --v50;
      while (v50);
      for (ii = 0; ii != 31; ++ii)
        ;
      LOBYTE(ii) = 0;
      do
        ++ii;
      while (ii != 31);
      LOBYTE(ii) = 0;
      do
        ++ii;
      while (ii != 31);
        if (v103 < (signed int)a1->maxsize) {
          v88 = a1->bit;
          v59 = v88 & 7;
            if ((v88 & 7) == 0) {
              a1->bit = 8 * v103;
              *(_BYTE *)(a1->data + v103) = 0;
              ++a1->cursize;
              v88 = a1->bit;
            }
          *(_BYTE *)(a1->data + (v88 >> 3)) |= 1 << v59;
          ++a1->bit;
        }
        else {
          a1->overflowed = 1;
        }
      MSG_WriteDeltaHudElems(a1, (int)a2->hud.archival, a3->hud.archival,
                             (msg_t *)0x1F);
      MSG_WriteDeltaHudElems(a1, (int)&a2->hud, a3->hud.current, (msg_t *)0x1F);
      for (result = 0; result != 31; ++result)
        ;
      LOBYTE(result) = 0;
      do
        ++result;
      while (result != 31);
      LOBYTE(result) = 0;
      do
        ++result;
      while (result != 31);
      LOBYTE(result) = 0;
      do
        ++result;
      while (result != 31);
    }
    else if (v103 < (signed int)a1->maxsize) {
      v90 = a1->bit;
        if ((v90 & 7) == 0) {
          a1->bit = 8 * v103;
          result = a1->data;
          *(_BYTE *)(result + v103) = 0;
          ++a1->cursize;
          v90 = a1->bit;
        }
      a1->bit = v90 + 1;
    }
    else {
      a1->overflowed = 1;
    }
  return result;
}

void __cdecl MSG_ReadDeltaField(struct msg_t *msg, unsigned char *from,
                                unsigned char *to, struct NetField const *field,
                                int print)
{
  unsigned __int8 *v5;  // edi
  int32_t bit;          // eax
  char v7;              // si
  signed int readcount; // edx
  int32_t bits;         // eax
  char v10;             // si
  signed int v11;       // edx
  char v12;             // si
  int v13;              // eax
  int v14;              // esi
  char v15;             // di
  int v16;              // eax
  int v17;              // eax
  int v18;              // eax
  const char *v19;      // eax
  int v20;              // eax
  char v21;             // si
  signed int v22;       // eax
  int32_t v23;          // edi
  int v24;              // esi
  int v25;              // edx
  signed int v26;       // ecx
  int v27;              // eax
  char v28;             // si
  int v29;              // eax
  char v30;             // si
  int v31;              // eax
  int v32;              // eax
  char v33;             // si
  signed int v34;       // edx
  int v35;              // eax
  float v36;            // xmm0_4
  int v37;              // eax
  int v38;              // eax
  int v39;              // esi
  char v40;             // di
  int v41;              // eax
  int v42;              // eax
  signed int v43;       // eax
  int32_t v44;          // [esp+0h] [ebp-38h]
  int32_t v45;          // [esp+0h] [ebp-38h]
  int32_t v46;          // [esp+0h] [ebp-38h]
  int32_t data;         // [esp+4h] [ebp-34h]
  int32_t v48;          // [esp+4h] [ebp-34h]
  float *v49;           // [esp+10h] [ebp-28h]
  int v50;              // [esp+14h] [ebp-24h]
  unsigned int v51;     // [esp+18h] [ebp-20h]
  int v52;              // [esp+1Ch] [ebp-1Ch]
  char v53;             // [esp+20h] [ebp-18h]
  int v54;              // [esp+24h] [ebp-14h]
  int v55;              // [esp+28h] [ebp-10h]
  unsigned __int8 *v56; // [esp+48h] [ebp+10h]

  v5 = &a2[a4->offset];
  v49 = (float *)&a3[a4->offset];
  bit = a1->bit;
  v44 = bit;
  v7 = bit & 7;
    if ((bit & 7) == 0) {
      readcount = a1->readcount;
        if (readcount >= (signed int)a1->cursize) {
          a1->overflowed = 1;
          goto LABEL_4;
        }
      v44 = 8 * readcount;
      a1->bit = 8 * readcount;
      a1->readcount = readcount + 1;
      bit = 8 * readcount;
    }
  v20 = (int)*(unsigned __int8 *)(a1->data + (bit >> 3)) >> v7;
  a1->bit = ++v44;
    if ((v20 & 1) == 0) {
      *v49 = *(float *)v5;
      return;
    }
LABEL_4:
  bits = a4->bits;
    switch (bits) {
    case 0:
      v10 = v44 & 7;
        if ((v44 & 7) == 0) {
          v11 = a1->readcount;
            if (v11 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
            LABEL_8:
              v12 = v44 & 7;
              if ((v44 & 7) != 0)
                goto LABEL_9;
                if (v11 < (signed int)a1->cursize) {
                  v44 = 8 * v11;
                  a1->bit = 8 * v11++;
                  a1->readcount = v11;
                LABEL_9:
                  data = a1->data;
                  v13 = (int)*(unsigned __int8 *)(data + (v44 >> 3)) >> v12;
                  v45 = v44 + 1;
                  a1->bit = v45;
                    if ((v13 & 1) == 0) {
                      v50 = 0;
                      v14 = 0;
                        while (1) {
                          v15 = v45 & 7;
                            if ((v45 & 7) == 0) {
                                if (v11 >= (signed int)a1->cursize) {
                                  a1->overflowed = 1;
                                  v50 = -1;
                                LABEL_15:
                                    if (v11 >= (signed int)a1->cursize) {
                                      a1->overflowed = 1;
                                      v17 = -32;
                                    }
                                    else {
                                      v16 = *(unsigned __int8 *)(data + v11);
                                      a1->readcount = v11 + 1;
                                      v17 = 32 * v16;
                                    }
                                  v18 = v50 + v17 - 4096;
                                LABEL_18:
                                  *v49 = (float)v18;
                                    if (a5) {
                                      v56 = (unsigned __int8 *)v18;
                                      v19 = *(const char **)a4->name;
                                      goto LABEL_20;
                                    }
                                  return;
                                }
                              v45 = 8 * v11;
                              a1->bit = 8 * v11++;
                              a1->readcount = v11;
                            }
                          v50 |= (((int)*(unsigned __int8 *)(data +
                                                             (v45++ >> 3)) >>
                                   v15) &
                                  1)
                                 << v14;
                          a1->bit = v45;
                          if (++v14 == 5)
                            goto LABEL_15;
                        }
                    }
                  goto LABEL_49;
                }
            LABEL_48:
              a1->overflowed = 1;
              goto LABEL_49;
            }
          v44 = 8 * v11;
          a1->bit = 8 * v11;
          a1->readcount = v11 + 1;
        }
      v27 = (int)*(unsigned __int8 *)(a1->data + (v44++ >> 3)) >> v10;
      a1->bit = v44;
        if ((v27 & 1) != 0) {
          v11 = a1->readcount;
          goto LABEL_8;
        }
    LABEL_42:
      *v49 = 0.0;
      return;
    case -99:
      v28 = v44 & 7;
        if ((v44 & 7) == 0) {
          v11 = a1->readcount;
            if (v11 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
              goto LABEL_46;
            }
          v44 = 8 * v11;
          a1->bit = 8 * v11;
          a1->readcount = v11 + 1;
        }
      v29 = (int)*(unsigned __int8 *)(a1->data + (v44++ >> 3)) >> v28;
      a1->bit = v44;
      if ((v29 & 1) == 0)
        goto LABEL_42;
      v11 = a1->readcount;
    LABEL_46:
      v30 = v44 & 7;
        if ((v44 & 7) == 0) {
          if (v11 >= (signed int)a1->cursize)
            goto LABEL_48;
          v44 = 8 * v11;
          a1->bit = 8 * v11++;
          a1->readcount = v11;
        }
      v48 = a1->data;
      v38 = (int)*(unsigned __int8 *)(v48 + (v44 >> 3)) >> v30;
      v46 = v44 + 1;
      a1->bit = v46;
        if ((v38 & 1) == 0) {
          v55 = 0;
          v39 = 0;
            while (1) {
              v40 = v46 & 7;
                if ((v46 & 7) == 0) {
                    if (v11 >= (signed int)a1->cursize) {
                      a1->overflowed = 1;
                      v55 = -1;
                    LABEL_84:
                        if (v11 >= (signed int)a1->cursize) {
                          a1->overflowed = 1;
                          v42 = -4;
                        }
                        else {
                          v41 = *(unsigned __int8 *)(v48 + v11);
                          a1->readcount = v11 + 1;
                          v42 = 4 * v41;
                        }
                      v18 = v55 + v42 - 512;
                      goto LABEL_18;
                    }
                  v46 = 8 * v11;
                  a1->bit = 8 * v11++;
                  a1->readcount = v11;
                }
              v55 |=
                  (((int)*(unsigned __int8 *)(v48 + (v46++ >> 3)) >> v40) & 1)
                  << v39;
              a1->bit = v46;
              if (++v39 == 2)
                goto LABEL_84;
            }
        }
    LABEL_49:
        if (v11 + 4 > (signed int)a1->cursize) {
          a1->overflowed = 1;
          v31 = -1;
        }
        else {
          v31 = *(_DWORD *)(a1->data + v11);
          a1->readcount = v11 + 4;
        }
      *(_DWORD *)v49 = v31;
      if (a5)
        Com_Printf("%s:%f ", *(const char **)a4->name, *v49);
      return;
    case -100:
      v33 = v44 & 7;
        if ((v44 & 7) == 0) {
          v34 = a1->readcount;
            if (v34 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
              goto LABEL_70;
            }
          v44 = 8 * v34;
          a1->bit = 8 * v34;
          a1->readcount = v34 + 1;
        }
      v37 = (int)*(unsigned __int8 *)(a1->data + (v44 >> 3)) >> v33;
      a1->bit = v44 + 1;
      if ((v37 & 1) == 0)
        goto LABEL_42;
      v34 = a1->readcount;
    LABEL_70:
        if (v34 + 2 > (signed int)a1->cursize) {
          a1->overflowed = 1;
          v36 = -1.0;
        }
        else {
          v35 = *(__int16 *)(a1->data + v34);
          a1->readcount = v34 + 2;
          v36 = (float)v35;
        }
      *v49 = v36 * 0.0054931641;
      return;
    }
  v21 = v44 & 7;
  if ((v44 & 7) != 0)
    goto LABEL_54;
  v22 = a1->readcount;
    if (v22 < (signed int)a1->cursize) {
      v44 = 8 * v22;
      a1->bit = 8 * v22;
      a1->readcount = v22 + 1;
    LABEL_54:
      v32 = (int)*(unsigned __int8 *)(a1->data + (v44++ >> 3)) >> v21;
      a1->bit = v44;
        if ((v32 & 1) == 0) {
          *v49 = 0.0;
          return;
        }
      goto LABEL_30;
    }
  a1->overflowed = 1;
LABEL_30:
  v23 = a4->bits;
    if (v23 == -98) {
      v51 = 0;
      v23 = 32;
      v24 = 0;
    LABEL_34:
      v52 = 0;
      goto LABEL_37;
    }
  v51 = (unsigned int)v23 >> 31;
  if (v23 < 0)
    v23 = -v23;
  v24 = v23 & 7;
  if ((v23 & 7) == 0)
    goto LABEL_34;
  v54 = 0;
  v52 = 0;
    while (1) {
      v53 = v44 & 7;
      if ((v44 & 7) != 0)
        goto LABEL_92;
      v43 = a1->readcount;
      if (v43 >= (signed int)a1->cursize)
        break;
      v44 = 8 * v43;
      a1->bit = 8 * v43;
      a1->readcount = v43 + 1;
    LABEL_92:
      v52 |= (((int)*(unsigned __int8 *)(a1->data + (v44++ >> 3)) >> v53) & 1)
             << v54;
      a1->bit = v44;
      if (v24 == ++v54)
        goto LABEL_37;
    }
  a1->overflowed = 1;
  v52 = -1;
LABEL_37:
    while (v23 > v24) {
      v26 = a1->readcount;
        if (v26 < (signed int)a1->cursize) {
          v25 = *(unsigned __int8 *)(a1->data + v26);
          a1->readcount = v26 + 1;
        }
        else {
          a1->overflowed = 1;
          v25 = -1;
        }
      v52 |= v25 << v24;
      v24 += 8;
    }
  if (v51 && ((v52 >> (v23 - 1)) & 1) != 0)
    v52 |= -1 << v23;
  *(_DWORD *)v49 = v52;
    if (a5) {
      v56 = (unsigned __int8 *)v52;
      v19 = *(const char **)a4->name;
    LABEL_20:
      Com_Printf("%s:%i ", v19, v56);
    }
}

void __cdecl MSG_WriteBigString(struct msg_t *sb, char const *s)
{
  unsigned int v2;  // kr04_4
  int v3;           // esi
  _BYTE *result;    // eax
  uint32_t v5;      // edx
  msg_t *v6;        // ecx
  size_t v7;        // edx
  uint32_t v8;      // ebx
  int i;            // edi
  char __src[8216]; // [esp+10h] [ebp-2018h] BYREF

  v2 = strlen(a2) + 1;
  v3 = v2 - 1;
    if ((int)(v2 - 1) <= 0x1FFF) {
      I_strncpyz(__src, a2, 0x2000);
        if (v3 > 0) {
          for (i = 0; i != v3; ++i)
            __src[i] = I_CleanChar(__src[i]);
          v7 = v2;
          v6 = a1;
          result = (_BYTE *)a1->cursize;
          v8 = (uint32_t)&result[v2];
          if ((int)&result[v2] > (signed int)a1->maxsize)
            goto LABEL_3;
        }
        else {
          v7 = v2;
          v6 = a1;
          result = (_BYTE *)a1->cursize;
          v8 = (uint32_t)&result[v2];
          if ((int)&result[v2] > (signed int)a1->maxsize)
            goto LABEL_3;
        }
      result = memcpy(&result[v6->data], __src, v7);
      a1->cursize = v8;
    }
    else {
      Com_Printf("MSG_WriteString: BIG_INFO_STRING");
      result = (_BYTE *)a1->cursize;
      v5 = (uint32_t)(result + 1);
      v6 = a1;
        if ((int)(result + 1) > (signed int)a1->maxsize) {
        LABEL_3:
          v6->overflowed = 1;
          return result;
        }
      result += a1->data;
      *result = 0;
      a1->cursize = v5;
    }
  return result;
}

void __cdecl MSG_WriteDeltaClient(struct msg_t *msg, struct clientState_s *from,
                                  struct clientState_s *to, int force)
{
  clientState_s *v4; // edx
  _BYTE __b[100];    // [esp+24h] [ebp-64h] BYREF

  v4 = a2;
    if (!a2) {
      memset(__b, 0, 0x5Cu);
      v4 = (clientState_s *)__b;
    }
  return MSG_WriteDeltaStruct(a1, (int *)v4, (int *)a3, a4,
                              (unsigned __int8 *)0x16, (unsigned __int8 *)6,
                              &clientStateFields, 1);
}

void __cdecl MSG_WriteDeltaArchivedEntity(struct msg_t *msg,
                                          struct archivedEntity_s *from,
                                          struct archivedEntity_s *to,
                                          int force)
{
  return MSG_WriteDeltaStruct(a1, (int *)a2, (int *)a3, a4,
                              (unsigned __int8 *)0x44, (unsigned __int8 *)0xA,
                              &archivedEntityFields, 0);
}

void __cdecl MSG_WriteDeltaEntity(struct msg_t *msg, struct entityState_s *from,
                                  struct entityState_s *to, int force)
{
  return MSG_WriteDeltaStruct(a1, (int *)a2, (int *)a3, a4,
                              (unsigned __int8 *)0x3B, (unsigned __int8 *)0xA,
                              &entityStateFields, 0);
}

void __cdecl MSG_ReadDeltaPlayerstate(struct msg_t *msg,
                                      struct playerState_s *from,
                                      struct playerState_s *to)
{
  playerState_s *v3;     // eax
  int v4;                // eax
  signed int readcount;  // edx
  int v6;                // eax
  float *v7;             // ebx
  int32_t bit;           // eax
  char v9;               // si
  signed int v10;        // edx
  int v11;               // esi
  char v12;              // si
  signed int v13;        // edx
  int v14;               // eax
  int v15;               // ecx
  int v16;               // ebx
  char *v17;             // esi
  int i;                 // ecx
  int32_t v19;           // eax
  char v20;              // si
  signed int v21;        // eax
  int v22;               // eax
  char v23;              // si
  int v24;               // esi
  signed int v25;        // eax
  char v26;              // si
  signed int v27;        // eax
  uint32_t v28;          // ecx
  int *v29;              // edx
  int m;                 // ebx
  uint32_t v31;          // esi
  int v32;               // eax
  char v33;              // si
  signed int v34;        // eax
  uint32_t v35;          // ecx
  int *v36;              // edx
  int n;                 // esi
  uint32_t v38;          // ebx
  int v39;               // eax
  char v40;              // si
  signed int v41;        // eax
  int v42;               // esi
  char v43;              // bl
  signed int v44;        // eax
  int v45;               // eax
  int v46;               // eax
  unsigned __int8 *v47;  // esi
  int32_t v48;           // eax
  char v49;              // bl
  signed int v50;        // eax
  const NetField *v51;   // ebx
  int v52;               // eax
  int v53;               // ecx
  int v54;               // eax
  signed int v55;        // edx
  int v56;               // eax
  int j;                 // esi
  char v58;              // bl
  signed int v59;        // eax
  int v60;               // esi
  char k;                // bl
  int v62;               // ebx
  signed int v63;        // eax
  int v64;               // eax
  int v65;               // eax
  int v66;               // esi
  char v67;              // bl
  signed int v68;        // edx
  int v69;               // eax
  int v70;               // eax
  int v71;               // ebx
  signed int v72;        // eax
  signed int v73;        // edx
  int v74;               // eax
  uint32_t v75;          // ecx
  int v76;               // eax
  uint32_t v77;          // ecx
  int v78;               // eax
  uint32_t v79;          // ecx
  int v80;               // eax
  uint32_t v81;          // ecx
  int v82;               // eax
  int v83;               // eax
  int32_t *p_data;       // ecx
  char v85;              // si
  int result;            // eax
  int v87;               // eax
  int v88;               // eax
  int v89;               // eax
  int v90;               // eax
  int v91;               // eax
  signed int v92;        // eax
  char v93;              // bl
  signed int v94;        // edx
  int v95;               // eax
  float v96;             // xmm0_4
  int v97;               // eax
  int32_t v98;           // [esp+2Ch] [ebp-272Ch]
  int v99;               // [esp+2Ch] [ebp-272Ch]
  int v100;              // [esp+2Ch] [ebp-272Ch]
  int v101;              // [esp+2Ch] [ebp-272Ch]
  int32_t v102;          // [esp+2Ch] [ebp-272Ch]
  int v103;              // [esp+2Ch] [ebp-272Ch]
  uint8_t *v104;         // [esp+30h] [ebp-2728h]
  uint8_t *v105;         // [esp+34h] [ebp-2724h]
  int32_t data;          // [esp+38h] [ebp-2720h]
  int v107;              // [esp+3Ch] [ebp-271Ch]
  int v108;              // [esp+40h] [ebp-2718h]
  int v109;              // [esp+44h] [ebp-2714h]
  int v110;              // [esp+48h] [ebp-2710h]
  unsigned int v111;     // [esp+4Ch] [ebp-270Ch]
  int v112;              // [esp+50h] [ebp-2708h]
  int v113;              // [esp+54h] [ebp-2704h]
  char v114;             // [esp+58h] [ebp-2700h]
  int v115;              // [esp+5Ch] [ebp-26FCh]
  int v116;              // [esp+60h] [ebp-26F8h]
  unsigned __int8 *v117; // [esp+64h] [ebp-26F4h]
  char v118;             // [esp+68h] [ebp-26F0h]
  playerState_s *v119;   // [esp+6Ch] [ebp-26ECh]
  int v120;              // [esp+70h] [ebp-26E8h]
  int v121;              // [esp+74h] [ebp-26E4h]
  _DWORD *v122;          // [esp+78h] [ebp-26E0h]
  float *v123;           // [esp+7Ch] [ebp-26DCh]
  int v124;              // [esp+80h] [ebp-26D8h]
  int v125;              // [esp+84h] [ebp-26D4h]
  int v126;              // [esp+88h] [ebp-26D0h]
  int v127;              // [esp+8Ch] [ebp-26CCh]
  _BYTE __b[9920];       // [esp+98h] [ebp-26C0h] BYREF

    if (__src) {
      v3 = __src;
    }
    else {
      memset(__b, 0, 0x26A8u);
      __src = (playerState_s *)__b;
      v3 = (playerState_s *)__b;
    }
  memcpy(__dst, v3, sizeof(playerState_s));
    if (cl_shownet &&
        ((v4 = *(_DWORD *)(cl_shownet + 8), v4 > 1) || v4 == -2)) {
      Com_Printf("%3i: playerstate ", a1->readcount);
      v109 = 1;
    }
    else {
      v109 = 0;
    }
  readcount = a1->readcount;
    if (readcount >= (signed int)a1->cursize) {
      a1->overflowed = 1;
      v108 = -1;
    }
    else {
      v6 = *(unsigned __int8 *)(a1->data + readcount);
      v108 = v6;
      a1->readcount = readcount + 1;
        if (v6) {
          v107 = 0;
          v122 = &unk_332604;
            while (1) {
              v7 = (float *)&__src->commandTime[*v122];
              v123 = (float *)&__dst->commandTime[*v122];
              bit = a1->bit;
              v98 = bit;
              v9 = bit & 7;
              if ((bit & 7) != 0)
                goto LABEL_84;
              v10 = a1->readcount;
              if (v10 < (signed int)a1->cursize)
                break;
              a1->overflowed = 1;
            LABEL_12:
              v11 = v122[1];
                if (v11) {
                    if (v11 == -100) {
                      v93 = v98 & 7;
                        if ((v98 & 7) == 0) {
                          v94 = a1->readcount;
                            if (v94 >= (signed int)a1->cursize) {
                              a1->overflowed = 1;
                            LABEL_210:
                                if (v94 + 2 > (signed int)a1->cursize) {
                                  a1->overflowed = 1;
                                  v96 = -1.0;
                                }
                                else {
                                  v95 = *(__int16 *)(a1->data + v94);
                                  a1->readcount = v94 + 2;
                                  v96 = (float)v95;
                                }
                              *v123 = v96 * 0.0054931641;
                              goto LABEL_86;
                            }
                          v98 = 8 * v94;
                          a1->bit = 8 * v94;
                          a1->readcount = v94 + 1;
                        }
                      v97 = (int)*(unsigned __int8 *)(a1->data + (v98 >> 3)) >>
                            v93;
                      a1->bit = v98 + 1;
                        if ((v97 & 1) == 0) {
                          *v123 = 0.0;
                          goto LABEL_86;
                        }
                      v94 = a1->readcount;
                      goto LABEL_210;
                    }
                  v111 = (unsigned int)v11 >> 31;
                  if (v11 < 0)
                    v11 = -v11;
                  v112 = v11 & 7;
                    if ((v11 & 7) == 0) {
                      v113 = 0;
                      goto LABEL_93;
                    }
                  v71 = 0;
                  v113 = 0;
                    while (1) {
                      v114 = v98 & 7;
                      if ((v98 & 7) != 0)
                        goto LABEL_145;
                      v72 = a1->readcount;
                      if (v72 >= (signed int)a1->cursize)
                        break;
                      v98 = 8 * v72;
                      a1->bit = 8 * v72;
                      a1->readcount = v72 + 1;
                    LABEL_145:
                      v113 |= (((int)*(unsigned __int8 *)(a1->data +
                                                          (v98++ >> 3)) >>
                                v114) &
                               1)
                              << v71;
                      a1->bit = v98;
                      if (v112 == ++v71)
                        goto LABEL_93;
                    }
                  a1->overflowed = 1;
                  v113 = -1;
                LABEL_93:
                    if (v11 > v112) {
                      v53 = v11 & 7;
                        do {
                            while (1) {
                              v55 = a1->readcount;
                              if (v55 >= (signed int)a1->cursize)
                                break;
                              v54 = *(unsigned __int8 *)(a1->data + v55);
                              a1->readcount = v55 + 1;
                              v113 |= v54 << v53;
                              v53 += 8;
                              if (v11 <= v53)
                                goto LABEL_98;
                            }
                          a1->overflowed = 1;
                          v113 |= -1 << v53;
                          v53 += 8;
                        }
                      while (v11 > v53);
                    }
                LABEL_98:
                    if (v111 && ((v113 >> (v11 - 1)) & 1) != 0) {
                      v56 = (-1 << v11) | v113;
                      *(_DWORD *)v123 = v56;
                      if (v109)
                        goto LABEL_137;
                    }
                    else {
                      v56 = v113;
                      *(_DWORD *)v123 = v113;
                      if (v109)
                        goto LABEL_137;
                    }
                LABEL_86:
                  ++v107;
                  v122 += 3;
                  v15 = v108;
                    if (v107 == v108) {
                    LABEL_20:
                      v16 = v15;
                      goto LABEL_21;
                    }
                }
                else {
                  v12 = v98 & 7;
                  if ((v98 & 7) != 0)
                    goto LABEL_127;
                  v13 = a1->readcount;
                    if (v13 < (signed int)a1->cursize) {
                      v98 = 8 * v13;
                      a1->bit = 8 * v13;
                      a1->readcount = v13 + 1;
                    LABEL_127:
                      data = a1->data;
                      v65 = (int)*(unsigned __int8 *)(data + (v98 >> 3)) >> v12;
                      v102 = v98 + 1;
                      a1->bit = v102;
                        if ((v65 & 1) == 0) {
                          v110 = 0;
                          v66 = 0;
                            while (1) {
                              v67 = v102 & 7;
                                if ((v102 & 7) == 0) {
                                  v68 = a1->readcount;
                                    if (v68 >= (signed int)a1->cursize) {
                                      a1->overflowed = 1;
                                      v110 = -1;
                                    LABEL_134:
                                        if (v68 >= (signed int)a1->cursize) {
                                          a1->overflowed = 1;
                                          v70 = -32;
                                        }
                                        else {
                                          v69 =
                                              *(unsigned __int8 *)(data + v68);
                                          a1->readcount = v68 + 1;
                                          v70 = 32 * v69;
                                        }
                                      v56 = v110 + v70 - 4096;
                                      *v123 = (float)v56;
                                      if (v109)
                                      LABEL_137:
                                        Com_Printf("%s:%i ",
                                                   (const char *)*(v122 - 1),
                                                   v56);
                                      goto LABEL_86;
                                    }
                                  v102 = 8 * v68;
                                  a1->bit = 8 * v68;
                                  a1->readcount = v68 + 1;
                                }
                              v110 |=
                                  (((int)*(unsigned __int8 *)(data +
                                                              (v102++ >> 3)) >>
                                    v67) &
                                   1)
                                  << v66;
                              a1->bit = v102;
                                if (++v66 == 5) {
                                  v68 = a1->readcount;
                                  goto LABEL_134;
                                }
                            }
                        }
                      v13 = a1->readcount;
                      goto LABEL_16;
                    }
                  a1->overflowed = 1;
                LABEL_16:
                    if (v13 + 4 > (signed int)a1->cursize) {
                      a1->overflowed = 1;
                      v14 = -1;
                    }
                    else {
                      v14 = *(_DWORD *)(a1->data + v13);
                      a1->readcount = v13 + 4;
                    }
                  *(_DWORD *)v123 = v14;
                  if (!v109)
                    goto LABEL_86;
                  Com_Printf("%s:%f ", (const char *)*(v122 - 1), *v123);
                  ++v107;
                  v122 += 3;
                  v15 = v108;
                  if (v107 == v108)
                    goto LABEL_20;
                }
            }
          v98 = 8 * v10;
          a1->bit = 8 * v10;
          a1->readcount = v10 + 1;
          bit = 8 * v10;
        LABEL_84:
          v52 = (int)*(unsigned __int8 *)(a1->data + (bit >> 3)) >> v9;
          a1->bit = ++v98;
            if ((v52 & 1) == 0) {
              *v123 = *v7;
              goto LABEL_86;
            }
          goto LABEL_12;
        }
    }
  v16 = v108;
LABEL_21:
  v17 = (char *)&playerStateFields + 12 * v16;
    if (v16 <= 104) {
        for (i = v16; i != 105; ++i) {
          *(_DWORD *)&__dst->commandTime[*((_DWORD *)v17 + 1)] =
              *(_DWORD *)&__src->commandTime[*((_DWORD *)v17 + 1)];
          v17 += 12;
        }
    }
  v19 = a1->bit;
  v99 = v19;
  v20 = v19 & 7;
  if ((v19 & 7) != 0)
    goto LABEL_27;
  v21 = a1->readcount;
    if (v21 < (signed int)a1->cursize) {
      v99 = 8 * v21;
      a1->bit = 8 * v21;
      a1->readcount = v21 + 1;
      v19 = 8 * v21;
    LABEL_27:
      v22 = (int)*(unsigned __int8 *)(a1->data + (v19 >> 3)) >> v20;
      a1->bit = ++v99;
        if ((v22 & 1) == 0) {
          v23 = v99;
          goto LABEL_29;
        }
      goto LABEL_102;
    }
  a1->overflowed = 1;
LABEL_102:
    if (cl_shownet && *(_DWORD *)(cl_shownet + 8) == 4) {
      Com_Printf("%s ", "PS_STATS");
      v99 = a1->bit;
    }
  v126 = 0;
    for (j = 0; j != 6; ++j) {
      v58 = v99 & 7;
        if ((v99 & 7) == 0) {
          v59 = a1->readcount;
            if (v59 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
              v118 = -1;
              goto LABEL_165;
            }
          v99 = 8 * v59;
          a1->bit = 8 * v59;
          a1->readcount = v59 + 1;
        }
      v126 |= (((int)*(unsigned __int8 *)(a1->data + (v99++ >> 3)) >> v58) & 1)
              << j;
      a1->bit = v99;
    }
  v118 = v126;
    if ((v126 & 1) == 0) {
      if ((v126 & 2) == 0)
        goto LABEL_112;
    LABEL_160:
      v79 = a1->readcount;
        if ((signed int)(v79 + 2) > (signed int)a1->cursize) {
          a1->overflowed = 1;
          v80 = -1;
        }
        else {
          v80 = *(__int16 *)(a1->data + v79);
          a1->readcount = v79 + 2;
        }
      *(_DWORD *)&__dst->stats[4] = v80;
      if ((v118 & 4) != 0)
        goto LABEL_156;
    LABEL_113:
      if ((v118 & 8) == 0)
        goto LABEL_121;
      goto LABEL_114;
    }
LABEL_165:
  v81 = a1->readcount;
    if ((signed int)(v81 + 2) > (signed int)a1->cursize) {
      a1->overflowed = 1;
      v82 = -1;
    }
    else {
      v82 = *(__int16 *)(a1->data + v81);
      a1->readcount = v81 + 2;
    }
  *(_DWORD *)__dst->stats = v82;
  if ((v118 & 2) != 0)
    goto LABEL_160;
LABEL_112:
  if ((v118 & 4) == 0)
    goto LABEL_113;
LABEL_156:
  v77 = a1->readcount;
    if ((signed int)(v77 + 2) > (signed int)a1->cursize) {
      a1->overflowed = 1;
      v78 = -1;
    }
    else {
      v78 = *(__int16 *)(a1->data + v77);
      a1->readcount = v77 + 2;
    }
  *(_DWORD *)&__dst->stats[8] = v78;
  if ((v118 & 8) == 0)
    goto LABEL_121;
LABEL_114:
  v115 = 0;
  v60 = 0;
  v101 = a1->bit;
    for (k = v101;; k = v101) {
      v62 = k & 7;
      if (v62)
        goto LABEL_119;
      v63 = a1->readcount;
      if (v63 >= (signed int)a1->cursize)
        break;
      v101 = 8 * v63;
      a1->bit = 8 * v63;
      a1->readcount = v63 + 1;
    LABEL_119:
      v115 |= (((int)*(unsigned __int8 *)(a1->data + (v101++ >> 3)) >> v62) & 1)
              << v60;
      a1->bit = v101;
      if (++v60 == 6)
        goto LABEL_120;
    }
  a1->overflowed = 1;
  v115 = -1;
LABEL_120:
  *(_DWORD *)&__dst->stats[12] = v115;
LABEL_121:
    if ((v118 & 0x10) != 0) {
      v75 = a1->readcount;
        if ((signed int)(v75 + 2) > (signed int)a1->cursize) {
          a1->overflowed = 1;
          v76 = -1;
        }
        else {
          v76 = *(__int16 *)(a1->data + v75);
          a1->readcount = v75 + 2;
        }
      *(_DWORD *)&__dst->stats[16] = v76;
      if ((v118 & 0x20) != 0)
        goto LABEL_149;
    LABEL_123:
      v99 = a1->bit;
      LOBYTE(v24) = v99 & 7;
      if ((v99 & 7) == 0)
        goto LABEL_30;
    }
    else {
      if ((v118 & 0x20) == 0)
        goto LABEL_123;
    LABEL_149:
      v73 = a1->readcount;
        if (v73 < (signed int)a1->cursize) {
          v74 = *(unsigned __int8 *)(a1->data + v73);
          a1->readcount = v73 + 1;
        }
        else {
          a1->overflowed = 1;
          v74 = -1;
        }
      *(_DWORD *)&__dst->stats[20] = v74;
      v99 = a1->bit;
      v23 = v99;
    LABEL_29:
      v24 = v23 & 7;
        if (!v24) {
        LABEL_30:
          v25 = a1->readcount;
            if (v25 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
              goto LABEL_32;
            }
          v99 = 8 * v25;
          a1->bit = 8 * v25;
          a1->readcount = v25 + 1;
        }
    }
  v64 = (int)*(unsigned __int8 *)(a1->data + (v99++ >> 3)) >> v24;
  a1->bit = v99;
    if ((v64 & 1) != 0) {
    LABEL_32:
      v121 = 0;
      v104 = &__dst->stats[20];
        do {
          v26 = v99 & 7;
            if ((v99 & 7) == 0) {
              v27 = a1->readcount;
                if (v27 >= (signed int)a1->cursize) {
                  a1->overflowed = 1;
                LABEL_36:
                  if (cl_shownet && *(_DWORD *)(cl_shownet + 8) == 4)
                    Com_Printf("%s ", "PS_AMMO");
                  v28 = a1->readcount;
                    if ((signed int)(v28 + 2) > (signed int)a1->cursize) {
                      a1->overflowed = 1;
                      v124 = -1;
                    }
                    else {
                      v124 = *(__int16 *)(a1->data + v28);
                      a1->readcount = v28 + 2;
                    }
                  v29 = (int *)(v104 + 4);
                    for (m = 0; m != 16; ++m) {
                        if (((v124 >> m) & 1) != 0) {
                          v31 = a1->readcount;
                            if ((signed int)(v31 + 2) >
                                (signed int)a1->cursize) {
                              a1->overflowed = 1;
                              v32 = -1;
                            }
                            else {
                              v32 = *(__int16 *)(a1->data + v31);
                              a1->readcount = v31 + 2;
                            }
                          *v29 = v32;
                        }
                      ++v29;
                    }
                  v99 = a1->bit;
                  goto LABEL_48;
                }
              v99 = 8 * v27;
              a1->bit = 8 * v27;
              a1->readcount = v27 + 1;
            }
          v90 = (int)*(unsigned __int8 *)(a1->data + (v99++ >> 3)) >> v26;
          a1->bit = v99;
          if ((v90 & 1) != 0)
            goto LABEL_36;
        LABEL_48:
          v121 += 16;
          v104 += 64;
        }
      while (v121 != 64);
    }
  v120 = 0;
  v105 = &__dst->ammo[508];
    do {
      v33 = v99 & 7;
      if ((v99 & 7) != 0)
        goto LABEL_192;
      v34 = a1->readcount;
        if (v34 < (signed int)a1->cursize) {
          v99 = 8 * v34;
          a1->bit = 8 * v34;
          a1->readcount = v34 + 1;
        LABEL_192:
          v89 = (int)*(unsigned __int8 *)(a1->data + (v99++ >> 3)) >> v33;
          a1->bit = v99;
          if ((v89 & 1) == 0)
            goto LABEL_65;
          goto LABEL_53;
        }
      a1->overflowed = 1;
    LABEL_53:
      if (cl_shownet && *(_DWORD *)(cl_shownet + 8) == 4)
        Com_Printf("%s ", "PS_AMMOCLIP");
      v35 = a1->readcount;
        if ((signed int)(v35 + 2) > (signed int)a1->cursize) {
          a1->overflowed = 1;
          v125 = -1;
        }
        else {
          v125 = *(__int16 *)(a1->data + v35);
          a1->readcount = v35 + 2;
        }
      v36 = (int *)(v105 + 4);
        for (n = 0; n != 16; ++n) {
            if (((v125 >> n) & 1) != 0) {
              v38 = a1->readcount;
                if ((signed int)(v38 + 2) > (signed int)a1->cursize) {
                  a1->overflowed = 1;
                  v39 = -1;
                }
                else {
                  v39 = *(__int16 *)(a1->data + v38);
                  a1->readcount = v38 + 2;
                }
              *v36 = v39;
            }
          ++v36;
        }
      v99 = a1->bit;
    LABEL_65:
      v120 += 16;
      v105 += 64;
    }
  while (v120 != 64);
  v40 = v99 & 7;
    if ((v99 & 7) == 0) {
      v41 = a1->readcount;
        if (v41 >= (signed int)a1->cursize) {
          a1->overflowed = 1;
          goto LABEL_69;
        }
      v99 = 8 * v41;
      a1->bit = 8 * v41;
      a1->readcount = v41 + 1;
    }
  v91 = (int)*(unsigned __int8 *)(a1->data + (v99++ >> 3)) >> v40;
  a1->bit = v99;
    if ((v91 & 1) == 0) {
      v85 = v99 & 7;
      if ((v99 & 7) != 0)
        goto LABEL_176;
      goto LABEL_202;
    }
LABEL_69:
  v119 = __dst;
  v127 = 0;
    while (2) {
      v116 = 0;
      v42 = 0;
        while (2) {
          v43 = v99 & 7;
            if ((v99 & 7) != 0) {
            LABEL_74:
              v116 |=
                  (((int)*(unsigned __int8 *)(a1->data + (v99++ >> 3)) >> v43) &
                   1)
                  << v42;
              a1->bit = v99;
                if (++v42 == 3) {
                  v45 = v116;
                  goto LABEL_76;
                }
              continue;
            }
          break;
        }
      v44 = a1->readcount;
        if (v44 < (signed int)a1->cursize) {
          v99 = 8 * v44;
          a1->bit = 8 * v44;
          a1->readcount = v44 + 1;
          goto LABEL_74;
        }
      a1->overflowed = 1;
      v45 = -1;
    LABEL_76:
      *(_DWORD *)v119->objective = v45;
      v46 = 28 * v127 + 1504;
      v117 = (unsigned __int8 *)&__dst->commandTime[v46 + 4];
      v47 = (unsigned __int8 *)&__src->commandTime[v46 + 4];
      v48 = a1->bit;
      v100 = v48;
      v49 = v48 & 7;
        if ((v48 & 7) == 0) {
          v50 = a1->readcount;
            if (v50 >= (signed int)a1->cursize) {
              a1->overflowed = 1;
              goto LABEL_79;
            }
          v100 = 8 * v50;
          a1->bit = 8 * v50;
          a1->readcount = v50 + 1;
          v48 = 8 * v50;
        }
      v83 = (int)*(unsigned __int8 *)(a1->data + (v48 >> 3)) >> v49;
      a1->bit = v100 + 1;
        if ((v83 & 1) != 0) {
        LABEL_79:
          v51 = (const NetField *)&objectiveFields;
          do
            MSG_ReadDeltaField(a1, v47, v117, v51++, 0);
          while (v51 != (const NetField *)&unk_312BE8);
          ++v127;
          v119 = (playerState_s *)((char *)v119 + 28);
          if (v127 != 16)
            goto LABEL_82;
        }
        else {
          p_data = &objectiveFields.data;
            do {
              *(_DWORD *)&v117[*p_data] = *(_DWORD *)&v47[*p_data];
              p_data += 3;
            }
          while (p_data != (int32_t *)&unk_312BEC);
          ++v127;
          v119 = (playerState_s *)((char *)v119 + 28);
            if (v127 != 16) {
            LABEL_82:
              v99 = a1->bit;
              continue;
            }
        }
      break;
    }
  v99 = a1->bit;
  v85 = v99 & 7;
    if ((v99 & 7) != 0) {
    LABEL_176:
      result = (int)*(unsigned __int8 *)(a1->data + (v99 >> 3)) >> v85;
      a1->bit = v99 + 1;
        if ((result & 1) != 0) {
        LABEL_177:
          v87 = 31;
          do
            --v87;
          while (v87);
          v88 = 31;
          do
            --v88;
          while (v88);
          MSG_ReadDeltaHudElems(a1, __src->hud.archival, __dst->hud.archival,
                                (msg_t *)0x1F);
          MSG_ReadDeltaHudElems(a1, __src->hud.current, __dst->hud.current,
                                (msg_t *)0x1F);
          for (result = 0; result != 31; ++result)
            ;
          LOBYTE(result) = 0;
          do
            ++result;
          while (result != 31);
          LOBYTE(result) = 0;
          do
            ++result;
          while (result != 31);
          LOBYTE(result) = 0;
          do
            ++result;
          while (result != 31);
        }
      return result;
    }
LABEL_202:
  v92 = a1->readcount;
    if (v92 >= (signed int)a1->cursize) {
      a1->overflowed = 1;
      goto LABEL_177;
    }
  v103 = 8 * v92;
  a1->bit = 8 * v92;
  a1->readcount = v92 + 1;
  result = (int)*(unsigned __int8 *)(a1->data + ((8 * v92) >> 3)) >> v85;
  a1->bit = v103 + 1;
  if ((result & 1) != 0)
    goto LABEL_177;
  return result;
}

int __cdecl MSG_ReadDeltaClient(struct msg_t *msg, struct clientState_s *from,
                                struct clientState_s *to, int number)
{
  char *v4;       // edx
  _BYTE __b[100]; // [esp+14h] [ebp-64h] BYREF

  v4 = (char *)a2;
    if (!a2) {
      memset(__b, 0, 0x5Cu);
      v4 = __b;
    }
  return MSG_ReadDeltaStruct(a1, v4, a3, a4, (unsigned __int8 *)0x16,
                             (unsigned __int8 *)6,
                             (NetField *)&clientStateFields);
}

int __cdecl MSG_ReadDeltaArchivedEntity(struct msg_t *msg,
                                        struct archivedEntity_s *from,
                                        struct archivedEntity_s *to, int number)
{
  return MSG_ReadDeltaStruct(a1, (char *)a2, a3, a4, (unsigned __int8 *)0x44,
                             (unsigned __int8 *)0xA,
                             (NetField *)&archivedEntityFields);
}

int __cdecl MSG_ReadDeltaEntity(struct msg_t *, struct entityState_s *,
                                struct entityState_s *, int)
{
  return MSG_ReadDeltaStruct(a1, (char *)a2, a3, a4, (unsigned __int8 *)0x3B,
                             (unsigned __int8 *)0xA,
                             (NetField *)&entityStateFields);
}

struct NetField *objectiveFields;
struct NetField *hudElemFields;
int *msg_hData;

short __cdecl LittleShort(short)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaField(struct msg_t *, unsigned char *,
                                 unsigned char *, struct NetField const *)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaHudElems(struct msg_t *, struct hudelem_s *const,
                                    struct hudelem_s *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaFields(struct msg_t *, unsigned char *,
                                  unsigned char *, int, int,
                                  struct NetField const *)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_WriteDeltaStruct(struct msg_t *, unsigned char *,
                                  unsigned char *, int, int, int,
                                  struct NetField const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_ReadDeltaHudElems(struct msg_t *, struct hudelem_s *const,
                                   struct hudelem_s *const, int)
{
  UNIMPLEMENTED();
}

int __cdecl MSG_ReadDeltaStruct(struct msg_t *, unsigned char *,
                                unsigned char *, unsigned int, int, int,
                                struct NetField const *)
{
  UNIMPLEMENTED();
}

void __cdecl MSG_ReadDeltaFields(struct msg_t *, unsigned char *,
                                 unsigned char *, int, struct NetField const *)
{
  UNIMPLEMENTED();
}
