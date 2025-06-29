void __cdecl R_LocateDebugLines(struct trDebugLine_t *lines, int lineCount,
                                int maxLineCount) {
  void **result; // eax
  char *v4;      // ebx
  void *v5;      // edx
  int v6;        // eax

  result = &frontEndDataOut;
  v4 = (char *)frontEndDataOut + 2399512;
  if (__src) {
    if (*((_DWORD *)frontEndDataOut + 599893)) {
      v5 = (void *)*((_DWORD *)frontEndDataOut + 599893);
    } else {
      v6 = (*(int(__cdecl **)(int)) & algn_11806C8[12])(44 * a3);
      *((_DWORD *)v4 + 15) = v6;
      v5 = (void *)v6;
    }
    result = (void **)memcpy(v5, __src, 44 * a2);
  }
  *((_DWORD *)v4 + 16) = a2;
  return result;
}

void __cdecl R_LocateDebugStrings(struct trDebugString_t *strings,
                                  int stringCount, int maxStringCount) {
  void **result; // eax
  char *v4;      // ebx
  void *v5;      // edx
  int v6;        // eax

  result = &frontEndDataOut;
  v4 = (char *)frontEndDataOut + 2399512;
  if (__src) {
    if (*((_DWORD *)frontEndDataOut + 599887)) {
      v5 = (void *)*((_DWORD *)frontEndDataOut + 599887);
    } else {
      v6 = (*(int(__cdecl **)(int)) & algn_11806C8[12])(a3 << 7);
      *((_DWORD *)v4 + 9) = v6;
      v5 = (void *)v6;
    }
    result = (void **)memcpy(v5, __src, a2 << 7);
  }
  *((_DWORD *)v4 + 10) = a2;
  return result;
}

void __cdecl R_TransferDebugGlobals(struct DebugGlobals *debugGlobalsEntry) {
  signed int plumeCount; // edx
  int v2;                // esi
  int32_t plumes;        // ecx
  _DWORD *v4;            // ebx
  int v5;                // edx
  int v6;                // [esp+1Ch] [ebp-1Ch]

  v6 = 0;
  plumeCount = debugGlobals.plumeCount;
  v2 = 0;
  while (v6 < plumeCount) {
    while (1) {
      plumes = debugGlobals.plumes;
      v4 = (_DWORD *)(v2 + debugGlobals.plumes);
      if ((signed int)(stru_1155004.time -
                       *(_DWORD *)(v2 + debugGlobals.plumes + 32)) >= 0 &&
          (signed int)(stru_1155004.time -
                       *(_DWORD *)(v2 + debugGlobals.plumes + 32)) <= v4[9]) {
        break;
      }
      debugGlobals.plumeCount = plumeCount - 1;
      v5 = 40 * (plumeCount - 1);
      *v4 = *(_DWORD *)(v5 + debugGlobals.plumes);
      *(_DWORD *)(v2 + plumes + 4) = *(_DWORD *)(v5 + plumes + 4);
      *(_DWORD *)(v2 + plumes + 8) = *(_DWORD *)(v5 + plumes + 8);
      *(_DWORD *)(v2 + plumes + 12) = *(_DWORD *)(v5 + plumes + 12);
      *(_DWORD *)(v2 + plumes + 16) = *(_DWORD *)(v5 + plumes + 16);
      *(_DWORD *)(v2 + plumes + 20) = *(_DWORD *)(v5 + plumes + 20);
      *(_DWORD *)(v2 + plumes + 24) = *(_DWORD *)(v5 + plumes + 24);
      *(_DWORD *)(v2 + plumes + 28) = *(_DWORD *)(v5 + plumes + 28);
      *(_DWORD *)(v2 + plumes + 32) = *(_DWORD *)(v5 + plumes + 32);
      *(_DWORD *)(v2 + plumes + 36) = *(_DWORD *)(v5 + plumes + 36);
      plumeCount = debugGlobals.plumeCount;
      if (v6 >= (int)debugGlobals.plumeCount)
        goto LABEL_6;
    }
    ++v6;
    v2 += 40;
  }
LABEL_6:
  if (debugGlobals.plumes) {
    if (!a1->plumes) {
      a1->plumes = (*(int(__cdecl **)(int)) &
                    algn_11806C8[12])(40 * debugGlobals.plumeLimit);
      plumeCount = debugGlobals.plumeCount;
    }
    memcpy((void *)a1->plumes, (const void *)debugGlobals.plumes,
           40 * plumeCount);
    plumeCount = debugGlobals.plumeCount;
  }
  a1->plumeCount = plumeCount;
}

void __cdecl R_ShutdownDebugEntry(struct DebugGlobals *) {
  int32_t result; // eax

  if (a1->polys) {
    (*(void(__cdecl **)(int32_t)) & algn_11806C8[16])(a1->polys);
    a1->polys = 0;
  }
  if (a1->verts) {
    (*(void(__cdecl **)(int32_t)) & algn_11806C8[16])(a1->verts);
    a1->verts = 0;
  }
  if (*(_DWORD *)a1->strings) {
    (*(void(__cdecl **)(_DWORD)) & algn_11806C8[16])(*(_DWORD *)a1->strings);
    *(_DWORD *)a1->strings = 0;
  }
  if (*(_DWORD *)a1->externStrings) {
    (*(void(__cdecl **)(_DWORD)) &
     algn_11806C8[16])(*(_DWORD *)a1->externStrings);
    *(_DWORD *)a1->externStrings = 0;
  }
  if (a1->lines) {
    (*(void(__cdecl **)(int32_t)) & algn_11806C8[16])(a1->lines);
    a1->lines = 0;
  }
  if (a1->externLines) {
    (*(void(__cdecl **)(int32_t)) & algn_11806C8[16])(a1->externLines);
    a1->externLines = 0;
  }
  result = a1->plumes;
  if (result) {
    result = (*(int(__cdecl **)(int32_t)) & algn_11806C8[16])(a1->plumes);
    a1->plumes = 0;
  }
  return result;
}

void __cdecl R_InitDebugEntry(struct DebugGlobals *debugGlobalsEntry) {
  void *result; // eax

  result = memset(__b, 0, sizeof(DebugGlobals));
  __b->vertLimit = 4096;
  __b->polyLimit = 512;
  *(_DWORD *)__b->stringLimit = 4096;
  __b->lineLimit = 0x4000;
  __b->plumeLimit = 4096;
  return result;
}

void __cdecl R_AddPlume(float const *const origin, int score,
                        float const *const color, int duration) {
  uint32_t result; // eax
  float *v5;       // edx
  float *v6;       // ecx

  if (!debugGlobals.plumes) {
    debugGlobals.plumes = (*(int(__cdecl **)(int)) &
                           algn_11806C8[12])(40 * debugGlobals.plumeLimit);
    debugGlobals.plumeCount = 0;
  }
  result = debugGlobals.plumeCount;
  if (debugGlobals.plumeCount != debugGlobals.plumeLimit) {
    v5 = (float *)(debugGlobals.plumes + 40 * debugGlobals.plumeCount);
    *v5 = *a1;
    v5[1] = a1[1];
    v5[2] = a1[2];
    v6 = (float *)(debugGlobals.plumes + 40 * debugGlobals.plumeCount + 12);
    *v6 = *a3;
    v6[1] = a3[1];
    v6[2] = a3[2];
    *(_DWORD *)(debugGlobals.plumes + 40 * debugGlobals.plumeCount + 28) = a2;
    *(_DWORD *)(debugGlobals.plumes + 40 * debugGlobals.plumeCount + 32) =
        stru_1155004.time;
    result = 5 * debugGlobals.plumeCount;
    *(_DWORD *)(debugGlobals.plumes + 40 * debugGlobals.plumeCount++ + 36) = a4;
  }
  return result;
}

void __cdecl R_ShutdownDebug() { return R_ShutdownDebugEntry(&debugGlobals); }

void __cdecl R_InitDebug() { UNIMPLEMENTED(); }

void __cdecl R_AddDebugString(struct DebugGlobals *debugGlobalsEntry,
                              float const *const origin,
                              float const *const color, float scale,
                              char const *string) {
  int v5;       // ecx
  int v6;       // edx
  char *result; // eax
  int v8;       // ebx

  v5 = *(_DWORD *)a1->stringLimit;
  v6 = *(_DWORD *)a1->stringCount;
  result = (char *)(v6 + 1);
  if (v6 + 1 <= v5) {
    if (!*(_DWORD *)a1->strings) {
      *(_DWORD *)a1->strings =
          (*(int(__cdecl **)(int)) & algn_11806C8[12])(v5 << 7);
      v6 = *(_DWORD *)a1->stringCount;
    }
    v8 = *(_DWORD *)a1->strings + (v6 << 7);
    *(float *)v8 = *a2;
    *(float *)(v8 + 4) = a2[1];
    *(float *)(v8 + 8) = a2[2];
    *(float *)(v8 + 12) = *a3;
    *(float *)(v8 + 16) = a3[1];
    *(float *)(v8 + 20) = a3[2];
    *(float *)(v8 + 24) = a3[3];
    *(float *)(v8 + 28) = a4;
    result = strncpy((char *)(v8 + 32), __src, 0x5Fu);
    *(_BYTE *)(v8 + 127) = 0;
    ++*(_DWORD *)a1->stringCount;
  }
  return result;
}

void __cdecl R_AddDebugLine(struct DebugGlobals *debugGlobalsEntry,
                            float const *const start, float const *const end,
                            float const *const color) {
  int32_t lineLimit;  // edx
  uint32_t lineCount; // ecx
  uint32_t result;    // eax
  int lines;          // eax
  uint32_t v8;        // edx

  lineLimit = a1->lineLimit;
  lineCount = a1->lineCount;
  result = lineCount + 1;
  if ((int)(lineCount + 1) <= lineLimit) {
    if (a1->lines) {
      lines = a1->lines;
    } else {
      lines = (*(int(__cdecl **)(int)) & algn_11806C8[12])(44 * lineLimit);
      a1->lines = lines;
      lineCount = a1->lineCount;
    }
    v8 = lines + 44 * lineCount;
    *(float *)v8 = *a2;
    *(float *)(v8 + 4) = a2[1];
    *(float *)(v8 + 8) = a2[2];
    *(float *)(v8 + 12) = *a3;
    *(float *)(v8 + 16) = a3[1];
    *(float *)(v8 + 20) = a3[2];
    *(float *)(v8 + 24) = *a4;
    *(float *)(v8 + 28) = a4[1];
    *(float *)(v8 + 32) = a4[2];
    result = *((_DWORD *)a4 + 3);
    *(_DWORD *)(v8 + 36) = result;
    *(_DWORD *)(v8 + 40) = 0;
    ++a1->lineCount;
  }
  return result;
}

void __cdecl R_AddDebugPolygon(struct DebugGlobals * debugGlobalsEntry, float const * const color, int pointCount, float  points)[3])
{
  UNIMPLEMENTED();
}

void __cdecl R_AddScaledDebugString(struct DebugGlobals *debugGlobalsEntry,
                                    struct GfxViewParms const *viewParms,
                                    float const *const origin,
                                    float const *const color,
                                    char const *string) {
  float v5;     // xmm0_4
  float v6;     // xmm2_4
  int v7;       // ecx
  int v8;       // edx
  char *result; // eax
  int v10;      // ebx
  float v11;    // [esp+1Ch] [ebp-3Ch]
  float v12;    // [esp+34h] [ebp-24h] BYREF
  float v13;    // [esp+38h] [ebp-20h]
  float v14;    // [esp+3Ch] [ebp-1Ch]

  v12 = *a3 - a2->origin[0];
  v13 = a3[1] - a2->origin[1];
  v14 = a3[2] - a2->origin[2];
  v11 = Vec3Normalize(&v12);
  v5 = fmaxf(1.0, v11 * (float)((float)((float)((float)(v12 * a2->axis[0][0]) +
                                                (float)(v13 * a2->axis[0][1])) +
                                        (float)(v14 * a2->axis[0][2])) -
                                0.995));
  v6 = v5;
  v7 = *(_DWORD *)a1->stringLimit;
  v8 = *(_DWORD *)a1->stringCount;
  result = (char *)(v8 + 1);
  if (v8 + 1 <= v7) {
    if (!*(_DWORD *)a1->strings) {
      *(_DWORD *)a1->strings =
          (*(int(__cdecl **)(int)) & algn_11806C8[12])(v7 << 7);
      v8 = *(_DWORD *)a1->stringCount;
      v6 = v5;
    }
    v10 = *(_DWORD *)a1->strings + (v8 << 7);
    *(float *)v10 = *a3;
    *(float *)(v10 + 4) = a3[1];
    *(float *)(v10 + 8) = a3[2];
    *(float *)(v10 + 12) = *a4;
    *(float *)(v10 + 16) = a4[1];
    *(float *)(v10 + 20) = a4[2];
    *(float *)(v10 + 24) = a4[3];
    *(float *)(v10 + 28) = v6;
    result = strncpy((char *)(v10 + 32), __src, 0x5Fu);
    *(_BYTE *)(v10 + 127) = 0;
    ++*(_DWORD *)a1->stringCount;
  }
  return result;
}

void __cdecl R_AddDebugBox(struct DebugGlobals *debugGlobalsEntry,
                           float const *const mins, float const *const maxs,
                           float const *const color) {
  int v4;              // ebx
  int v5;              // esi
  float *v6;           // edx
  int i;               // ecx
  float v8;            // eax
  const DpvsPlane *v9; // edi
  uint32_t lineCount;  // ecx
  _DWORD *v11;         // ebx
  _DWORD *v12;         // esi
  int32_t lineLimit;   // edx
  uint32_t result;     // eax
  int v15;             // edx
  _BYTE v16[120];      // [esp+10h] [ebp-78h] BYREF

  v4 = 0;
  v5 = 0;
  do {
    v6 = (float *)&v16[v5];
    for (i = 0; i != 3; ++i) {
      if (((v4 >> i) & 1) != 0)
        v8 = a3[i];
      else
        v8 = a2[i];
      *v6++ = v8;
    }
    ++v4;
    v5 += 12;
  } while (v4 != 8);
  v9 = (const DpvsPlane *)&unk_2F2AC4;
  lineCount = a1->lineCount;
  do {
    v11 = &v16[12 * *(_DWORD *)v9[-1].side];
    v12 = &v16[12 * *(_DWORD *)v9->coeffs];
    lineLimit = a1->lineLimit;
    result = lineCount + 1;
    if ((int)(lineCount + 1) <= lineLimit) {
      if (!a1->lines) {
        a1->lines =
            (*(int(__cdecl **)(int)) & algn_11806C8[12])(44 * lineLimit);
        lineCount = a1->lineCount;
      }
      v15 = a1->lines + 44 * lineCount;
      *(_DWORD *)v15 = *v11;
      *(_DWORD *)(v15 + 4) = v11[1];
      *(_DWORD *)(v15 + 8) = v11[2];
      *(_DWORD *)(v15 + 12) = *v12;
      *(_DWORD *)(v15 + 16) = v12[1];
      *(_DWORD *)(v15 + 20) = v12[2];
      *(float *)(v15 + 24) = *a4;
      *(float *)(v15 + 28) = a4[1];
      *(float *)(v15 + 32) = a4[2];
      *(float *)(v15 + 36) = a4[3];
      *(_DWORD *)(v15 + 40) = 0;
      result = a1->lineCount + 1;
      lineCount = result;
      a1->lineCount = result;
    }
    v9 = (const DpvsPlane *)((char *)v9 + 8);
  } while (v9 != (const DpvsPlane *)&standardFrustumSidePlanes.coeffs[4]);
  return result;
}

int marker_r_debug;
