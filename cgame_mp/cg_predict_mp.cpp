void __cdecl CG_ClearSolidList()
{
  cg_numSolidEntities = 0;
  cg_numTriggerEntities = 0;
}

void __cdecl CG_BuildSolidList()
{
  int result; // eax
  int v1;     // edi
  int v2;     // eax
  char *v3;   // esi
  int v4;     // eax
  int v5;     // [esp+18h] [ebp-20h]
  int v6;     // [esp+1Ch] [ebp-1Ch]

  cg_numSolidEntities = 0;
  cg_numTriggerEntities = 0;
  result = *((_DWORD *)cg + 9);
  v6 = result;
    if (*(int *)(result + 9908) > 0) {
      v1 = *((_DWORD *)cg + 9);
      v5 = 0;
        while (1) {
          v3 = (char *)cg_entities + 548 * *(_DWORD *)(v1 + 9916);
          if (*((_UNKNOWN **)v3 + 99) != &unk_FFFFFF)
            break;
            if ((v3[248] & 1) != 0) {
            LABEL_6:
              ++v5;
              v1 += 240;
              result = v6;
              if (*(_DWORD *)(v6 + 9908) <= v5)
                return result;
            }
            else {
              if (CM_ContentsOfModel(*((_DWORD *)v3 + 95)))
                break;
              ++v5;
              v1 += 240;
              result = v6;
              if (*(_DWORD *)(v6 + 9908) <= v5)
                return result;
            }
        }
        if (*((_DWORD *)v3 + 61) == 3) {
          v4 = cg_numTriggerEntities;
          cg_triggerEntities[cg_numTriggerEntities] = (int)v3;
          cg_numTriggerEntities = v4 + 1;
        }
        else if (*((_DWORD *)v3 + 99)) {
          v2 = cg_numSolidEntities;
          cg_solidEntities[cg_numSolidEntities] = (int)v3;
          cg_numSolidEntities = v2 + 1;
        }
      goto LABEL_6;
    }
  return result;
}

int __cdecl CG_PointContents(float const *const point, int passEntityNum,
                             int contentmask)
{
  int v3;  // esi
  int *v4; // ebx
  int v5;  // ecx
  int v7;  // [esp+1Ch] [ebp-1Ch]

  v7 = CM_PointContents(a1, 0);
    if (cg_numSolidEntities > 0) {
      v3 = 0;
      v4 = &cg_solidEntities;
        do {
            while (1) {
                if (*(_DWORD *)(*v4 + 240) != a2 &&
                    *(_UNKNOWN **)(*v4 + 396) == &unk_FFFFFF) {
                  v5 = *(_DWORD *)(*v4 + 380);
                  if (v5)
                    break;
                }
              ++v3;
              ++v4;
              if (cg_numSolidEntities <= v3)
                return v7 & a3;
            }
          v7 |= CM_TransformedPointContents(a1, v5, (const float *)(*v4 + 492),
                                            (float *)(*v4 + 504));
          ++v3;
          ++v4;
        }
      while (cg_numSolidEntities > v3);
    }
  return v7 & a3;
}

void __cdecl CG_ClipMoveToEntities(float const *const start,
                                   float const *const mins,
                                   float const *const maxs,
                                   float const *const end, int skipNumber,
                                   int mask, int capsule, struct trace_t *tr)
{
  trace_t *result; // eax
  int *v9;         // edi
  int v10;         // ebx
  _DWORD *v11;     // esi
  void *v12;       // edx
  int v13;         // ecx
  float v14;       // xmm0_4
  float v15;       // xmm1_4
  float fraction;  // xmm1_4
  float v17;       // [esp+3Ch] [ebp-8Ch]
  int v18;         // [esp+48h] [ebp-80h]
  float *v19;      // [esp+4Ch] [ebp-7Ch]
  trace_t v20;     // [esp+50h] [ebp-78h] BYREF
  float v21;       // [esp+74h] [ebp-54h] BYREF
  float v22;       // [esp+78h] [ebp-50h]
  float v23;       // [esp+7Ch] [ebp-4Ch]
  float v24;       // [esp+80h] [ebp-48h]
  float v25;       // [esp+84h] [ebp-44h]
  float v26;       // [esp+88h] [ebp-40h]
  float v27;       // [esp+8Ch] [ebp-3Ch] BYREF
  int v28;         // [esp+90h] [ebp-38h]
  int v29;         // [esp+94h] [ebp-34h]
  float v30;       // [esp+98h] [ebp-30h] BYREF
  float v31;       // [esp+9Ch] [ebp-2Ch]
  float v32;       // [esp+A0h] [ebp-28h]
  float v33;       // [esp+A4h] [ebp-24h] BYREF
  float v34;       // [esp+A8h] [ebp-20h]
  float v35;       // [esp+ACh] [ebp-1Ch]

  Trace_CalcBounds(a1, a2, a3, a8->fraction, a4, &v21);
  result = (trace_t *)cg_numSolidEntities;
    if (cg_numSolidEntities > 0) {
      v18 = 0;
      v9 = &cg_solidEntities;
        do {
          v10 = *v9;
          v11 = (_DWORD *)(*v9 + 240);
            if (*v11 != a5) {
              v12 = *(void **)(*v9 + 396);
                if (v12 == &unk_FFFFFF) {
                  v19 = *(float **)(*v9 + 380);
                  if ((CM_ContentsOfModel((int)v19) & a6) == 0)
                    goto LABEL_10;
                  v17 = CM_RadiusOfModel((int)v19);
                    if ((float)(*(float *)(v10 + 492) - v17) >= v24 ||
                        (float)(*(float *)(v10 + 496) - v17) >= v25 ||
                        v21 >= (float)(*(float *)(v10 + 492) + v17) ||
                        v22 >= (float)(*(float *)(v10 + 496) + v17) ||
                        (float)(*(float *)(v10 + 500) - v17) >= v26 ||
                        v23 >= (float)(*(float *)(v10 + 500) + v17)) {
                      goto LABEL_10;
                    }
                  v27 = *(float *)(v10 + 504);
                  v28 = *(_DWORD *)(v10 + 508);
                  v29 = *(_DWORD *)(v10 + 512);
                }
                else {
                  v13 = 0x2000000;
                  if (*(_DWORD *)(*v9 + 244) != 1)
                    v13 = 1;
                  if ((v13 & a6) == 0)
                    goto LABEL_10;
                  v14 = (float)(unsigned __int8)v12;
                  v34 = 1.0 - v14;
                  v33 = 1.0 - v14;
                  v31 = v14 - 1.0;
                  v30 = v14 - 1.0;
                  v35 = 1.0 - (float)(BYTE1(v12) - 1);
                  v32 = (float)(BYTE2(v12) - 32) - 1.0;
                  if ((float)(*(float *)(v10 + 492) + (float)(1.0 - v14)) >=
                      v24)
                    goto LABEL_10;
                  if ((float)(*(float *)(v10 + 496) + v34) >= v25)
                    goto LABEL_10;
                  if (v21 >= (float)(*(float *)(v10 + 492) + v30))
                    goto LABEL_10;
                  if (v22 >= (float)(*(float *)(v10 + 496) + v31))
                    goto LABEL_10;
                  v15 = *(float *)(v10 + 500);
                    if ((float)((float)(1.0 - (float)(BYTE1(v12) - 1)) + v15) >=
                            v26 ||
                        v23 >= (float)(v15 + (float)((float)(BYTE2(v12) - 32) -
                                                     1.0))) {
                      goto LABEL_10;
                    }
                  v19 = (float *)CM_TempBoxModel(&v33, &v30, v13);
                  v27 = 0.0;
                  v28 = 0;
                  v29 = 0;
                }
              CM_TransformedBoxTraceExternal(&v20, a1, a4, a2, a3, v19,
                                             (float *)a6,
                                             (const float *)(v10 + 492), &v27);
              fraction = v20.fraction;
              result = a8;
                if (a8->fraction > v20.fraction) {
                  v20.entityNum = *v11;
                  *a8 = v20;
                  result = (trace_t *)Trace_CalcBounds(a1, a2, a3, fraction, a4,
                                                       &v21);
                }
                else if (v20.allsolid) {
                  v20.entityNum = *v11;
                  a8->fraction = v20.fraction;
                  a8->normal[0] = v20.normal[0];
                  a8->normal[1] = v20.normal[1];
                  a8->normal[2] = v20.normal[2];
                  a8->surfaceFlags = v20.surfaceFlags;
                  a8->contents = v20.contents;
                  a8->material = v20.material;
                  *(_DWORD *)&a8->entityNum = *(_DWORD *)&v20.entityNum;
                  result = *(trace_t **)&v20.partGroup;
                  *(_DWORD *)&a8->partGroup = *(_DWORD *)&v20.partGroup;
                }
                else if (v20.startsolid) {
                  result = a8;
                  a8->startsolid = 1;
                }
              if (a8->allsolid)
                return result;
            }
        LABEL_10:
          ++v18;
          ++v9;
          result = (trace_t *)v18;
        }
      while (v18 < cg_numSolidEntities);
    }
  return result;
}

void __cdecl CG_TraceCapsule(struct trace_t *result, float const *const start,
                             float const *const mins, float const *const maxs,
                             float const *const end, int skipNumber, int mask)
{
  uint16_t result; // ax

  CM_BoxTrace(a1, a2, a5, a3, a4, 0, a7);
  result = (a1->fraction == 1.0) + 1022;
  a1->entityNum = result;
  if (a1->fraction != 0.0)
    return (unsigned __int16)CG_ClipMoveToEntities(a2, &a3->fraction, a4, a5,
                                                   a6, (int)a7, 1, a1);
  return result;
}

void __cdecl CG_PredictPlayerState()
{
  UNIMPLEMENTED();
}

void __cdecl Trace_CalcBounds(float const *const, float const *const,
                              float const *const, float const *const, float,
                              float (*const)[3])
{
  UNIMPLEMENTED();
}

void __cdecl CG_InterpolatePlayerState(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_TouchItem(struct centity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_TouchTriggerPrediction(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_PredictPlayerState_Internal(void)
{
  UNIMPLEMENTED();
}
