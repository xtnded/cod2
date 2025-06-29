void __cdecl Byte4Copy(unsigned char const *const, unsigned char *const)
{
  UNIMPLEMENTED();
}

void __cdecl Byte4PackNativeColor(float const *const, unsigned char *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_InitMarkPolys()
{
  UNIMPLEMENTED();
}

void __cdecl CG_AddMarks()
{
  UNIMPLEMENTED();
}

void __cdecl CG_FreeMarkPoly(struct MarkPoly *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ImpactMark(struct Material *markMaterial,
                           float const *const origin, float const *const dir,
                           float orientation, float const *const color,
                           float radius)
{
  void *result;          // eax
  int i;                 // esi
  int v8;                // edx
  const float *v9;       // eax
  float v10;             // xmm2_4
  float v11;             // xmm1_4
  int v12;               // edx
  char v13;              // al
  int v14;               // edx
  char v15;              // al
  int v16;               // edx
  char v17;              // al
  int v18;               // edx
  int v19;               // edi
  uint8_t *p_pointCount; // esi
  GfxWorldVertex *v21;   // eax
  int v22;               // ecx
  int v23;               // edx
  GfxColor v24;          // ebx
  int v25;               // ecx
  char *v26;             // edx
  int *v27;              // ebx
  int *v28;              // edx
  int v29;               // edx
  char *v30;             // [esp+8h] [ebp-12D0h]
  float v31;             // [esp+4Ch] [ebp-128Ch]
  float v32;             // [esp+50h] [ebp-1288h]
  float v33;             // [esp+54h] [ebp-1284h]
  float v34;             // [esp+58h] [ebp-1280h]
  int v35;               // [esp+5Ch] [ebp-127Ch]
  GfxMarkFragment v36;   // [esp+68h] [ebp-1270h] BYREF
  _BYTE v37[52];         // [esp+1264h] [ebp-74h] BYREF
  char v38[12];          // [esp+1298h] [ebp-40h] BYREF
  float v39[3];          // [esp+12A4h] [ebp-34h] BYREF
  float v40[3];          // [esp+12B0h] [ebp-28h] BYREF
  GfxColor v41;          // [esp+12BCh] [ebp-1Ch]

  result = (void *)cg_marks;
  if (!*(_BYTE *)(cg_marks + 8))
    return result;
  result = cg;
  if (*(_DWORD *)((char *)&loc_2BEE8 + (_DWORD)cg))
    return result;
  Vec3NormalizeTo(a3, (float *)v38);
  PerpendicularVector((float *)v38, v39);
  RotatePointAroundVector(v40, (float *)v38, v39, a4);
  Vec3Cross((float *)v38, v40, v39);
    for (i = 1; i != 4; ++i) {
      v8 = 4 * i;
      v9 = &a2[i];
      v10 = a6 * *(float *)&v37[4 * i + 60];
      v11 = a6 * *(float *)&v37[4 * i + 72];
      *(float *)&v37[v8] = (float)(*(v9 - 1) - v10) - v11;
      *(float *)&v37[4 * i + 12] = (float)(v10 + *(v9 - 1)) - v11;
      *(float *)&v37[4 * i + 24] = (float)(v10 + *(v9 - 1)) + v11;
      *(float *)&v37[v8 + 36] = v11 + (float)(*(v9 - 1) - v10);
    }
  v30 = v38;
  v35 = CL_MarkFragments();
  v34 = floorf((float)(*a5 * 255.0) + 0.5);
  v12 = (int)v34;
    if ((int)v34 - 255 >= 0) {
      LOBYTE(v12) = -1;
    LABEL_8:
      v13 = v12;
      goto LABEL_9;
    }
  if (v12 > 0)
    goto LABEL_8;
  v13 = 0;
LABEL_9:
  BYTE1(v41.packed) = v13;
  v33 = floorf((float)(a5[1] * 255.0) + 0.5);
  v14 = (int)v33;
    if ((int)v33 - 255 >= 0) {
      LOBYTE(v14) = -1;
    LABEL_11:
      v15 = v14;
      goto LABEL_12;
    }
  if (v14 > 0)
    goto LABEL_11;
  v15 = 0;
LABEL_12:
  BYTE2(v41.array) = v15;
  v32 = floorf((float)(a5[2] * 255.0) + 0.5);
  v16 = (int)v32;
    if ((int)v32 - 255 >= 0) {
      LOBYTE(v16) = -1;
    LABEL_14:
      v17 = v16;
      goto LABEL_15;
    }
  if (v16 > 0)
    goto LABEL_14;
  v17 = 0;
LABEL_15:
  HIBYTE(v41.array) = v17;
  v31 = floorf((float)(255.0 * a5[3]) + 0.5);
  v18 = (int)v31;
    if ((int)v31 - 255 >= 0) {
      v18 = 255;
    LABEL_17:
      result = (void *)v18;
      goto LABEL_18;
    }
  if (v18 > 0)
    goto LABEL_17;
  result = 0;
LABEL_18:
  LOBYTE(v41.packed) = (_BYTE)result;
    if (v35 > 0) {
      v19 = 0;
      p_pointCount = &v36.pointCount;
        do {
          v21 = &markVerts + *(_DWORD *)(p_pointCount + 2);
          v22 = *p_pointCount;
            if (*p_pointCount) {
              v23 = 0;
              v24.packed = v41.packed;
                do {
                  v21->color = v24;
                  ++v23;
                  ++v21;
                }
              while (v23 < v22);
            }
            if (cg_freeMarkPolys) {
              v25 = cg_freeMarkPolys;
            }
            else {
              v27 = (int *)*((_DWORD *)cg + 249285);
                if (v27 != (int *)((char *)cg + 997140)) {
                  v28 = (int *)*((_DWORD *)cg + 249285);
                    do {
                      if (v28[2] < v27[2])
                        v27 = v28;
                      v28 = (int *)*v28;
                    }
                  while (v28 != (int *)((char *)cg + 997140));
                }
              if (!*v27)
                Com_Error(1, "\x15CG_FreeLocalEntity: not active", (char)v30);
              v29 = *v27;
              *(_DWORD *)(v29 + 4) = v27[1];
              *(_DWORD *)v27[1] = v29;
              v27[1] = cg_freeMarkPolys;
              cg_freeMarkPolys = (int)v27;
              v25 = (int)v27;
            }
          cg_freeMarkPolys = *(_DWORD *)(v25 + 4);
          v26 = (char *)cg;
          *(_DWORD *)(v25 + 4) = *((_DWORD *)cg + 249286);
          *(_DWORD *)v25 = v26 + 997140;
          **((_DWORD **)v26 + 249286) = v25;
          *((_DWORD *)v26 + 249286) = v25;
          *(float *)(v25 + 12) = *a2;
          *(float *)(v25 + 16) = a2[1];
          *(float *)(v25 + 20) = a2[2];
          *(float *)(v25 + 24) = a6;
          *(_DWORD *)(v25 + 28) = *(_DWORD *)(p_pointCount - 6);
          *(_WORD *)(v25 + 32) = *((_WORD *)p_pointCount - 1);
          *(_BYTE *)(v25 + 34) = *p_pointCount;
          *(_DWORD *)(v25 + 8) = *(_DWORD *)v26;
          result = memcpy((void *)(v25 + 36),
                          &markVerts + *(_DWORD *)(p_pointCount + 2),
                          68 * *p_pointCount);
          ++v19;
          p_pointCount += 12;
        }
      while (v35 != v19);
    }
  return result;
}

struct MarkPoly *cg_freeMarkPolys;
struct MarkPoly *cg_markPolys;
struct GfxWorldVertex *markVerts;

struct MarkPoly *__cdecl CG_FindMarkPolyToFree(void)
{
  UNIMPLEMENTED();
}

struct MarkPoly *__cdecl CG_AllocMark(void)
{
  UNIMPLEMENTED();
}
