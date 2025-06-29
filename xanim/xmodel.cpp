void __cdecl LocalMatrixTransformVector(float const *const,
                                        float const (*const)[3], float *const)
{
  UNIMPLEMENTED();
}

void __cdecl LocalMatrixTransposeTransformVector(float const *const,
                                                 float const (*const)[3],
                                                 float *const)
{
  UNIMPLEMENTED();
}

bool __cdecl Com_ValidXModelName(char const *name)
{
  return !strnicmp(a1, "xmodel", 6u) && a1[6] == 47;
}

int __cdecl XModelGetMemUsage(struct XModel const *model)
{
  return a1->memUsage;
}

struct trXSkin_t const *__cdecl XModelGetSkins(struct XModel const *model)
{
  return a1->xskins;
}

int __cdecl XModelGetCollisionLod(struct XModel const *)
{
  UNIMPLEMENTED();
}

int __cdecl XModelGetContents(struct XModel const *model)
{
  return a1->contents;
}

char const *__cdecl XModelGetLodName(struct XModel const *model, int lod)
{
  return *(_DWORD *)&a1->lodInfo[20 * a2 + 4];
}

int __cdecl XModelGetBoneIndex(struct XModel const *model, unsigned int name)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // ecx
  int v5; // edx
  int v6; // eax

  v2 = **(_DWORD **)(a1->parts + 4);
  v3 = *(__int16 *)a1->parts - 1;
    if (v3 >= 0 && a2 != *(unsigned __int16 *)(v2 + 2 * v3)) {
      v4 = v2 + 2 * v3;
      v5 = 0;
        do {
          --v3;
          if (v5 == *(__int16 *)a1->parts - 1)
            break;
          v6 = *(unsigned __int16 *)(v4 - 2);
          ++v5;
          v4 -= 2;
        }
      while (a2 != v6);
    }
  return v3;
}

unsigned short *__cdecl XModelBoneNames(struct XModel *model)
{
  return **(_DWORD **)(a1->parts + 4);
}

void __cdecl XModelSetOptimize(int)
{
  UNIMPLEMENTED();
}

void __cdecl XModelGetBounds(struct XModel const *model, float *const mins,
                             float *const maxs)
{
  int result; // eax

  *a2 = a1->mins[0];
  a2[1] = a1->mins[1];
  a2[2] = a1->mins[2];
  *a3 = a1->maxs[0];
  a3[1] = a1->maxs[1];
  result = LODWORD(a1->maxs[2]);
  *((_DWORD *)a3 + 2) = result;
  return result;
}

int __cdecl XModelBad(struct XModel const *model)
{
  return (unsigned __int8)a1->bad;
}

int __cdecl XModelTraceLine(struct XModel const *model, struct trace_t *results,
                            struct DObjAnimMat_s const *boneMtxList,
                            float *const localStart, float *const localEnd,
                            int contentmask)
{
  int v6;           // edi
  const XModel *v7; // eax
  int v8;           // ebx
  float *quat;      // eax
  float v10;        // xmm2_4
  float v11;        // xmm7_4
  float v12;        // xmm1_4
  float v13;        // xmm0_4
  float v14;        // xmm3_4
  float v15;        // xmm6_4
  float v16;        // xmm1_4
  float v17;        // xmm4_4
  float v18;        // xmm5_4
  float v19;        // xmm2_4
  float v20;        // xmm0_4
  float v21;        // xmm3_4
  float v22;        // xmm6_4
  float v23;        // xmm2_4
  float v24;        // xmm1_4
  float v25;        // xmm4_4
  float v26;        // xmm5_4
  float v27;        // xmm2_4
  float v28;        // xmm6_4
  float v29;        // xmm7_4
  int v30;          // esi
  float *v31;       // edx
  float v32;        // xmm2_4
  float v33;        // xmm4_4
  float v34;        // xmm1_4
  float v35;        // xmm0_4
  float v36;        // xmm1_4
  float v37;        // xmm2_4
  float v38;        // xmm0_4
  float v39;        // xmm5_4
  float v40;        // xmm1_4
  float v41;        // xmm0_4
  float *v42;       // eax
  float v43;        // xmm5_4
  float v44;        // xmm7_4
  float v45;        // xmm4_4
  float v46;        // xmm2_4
  float v47;        // xmm3_4
  float v48;        // xmm1_4
  float v49;        // xmm6_4
  float v50;        // xmm0_4
  float v51;        // xmm5_4
  float v52;        // xmm7_4
  float v53;        // xmm4_4
  int v55;          // [esp+1Ch] [ebp-CCh]
  float v56;        // [esp+24h] [ebp-C4h]
  float v57;        // [esp+28h] [ebp-C0h]
  float v58;        // [esp+2Ch] [ebp-BCh]
  float v59;        // [esp+30h] [ebp-B8h]
  float v60;        // [esp+34h] [ebp-B4h]
  int v61;          // [esp+38h] [ebp-B0h]
  int v62;          // [esp+3Ch] [ebp-ACh]
  signed int v63;   // [esp+40h] [ebp-A8h]
  float v64;        // [esp+44h] [ebp-A4h]
  float v65;        // [esp+44h] [ebp-A4h]
  float v66;        // [esp+48h] [ebp-A0h]
  float v67;        // [esp+4Ch] [ebp-9Ch]
  float v68;        // [esp+50h] [ebp-98h]
  float v69;        // [esp+54h] [ebp-94h]
  float v70;        // [esp+58h] [ebp-90h]
  float v71;        // [esp+5Ch] [ebp-8Ch]
  float v72;        // [esp+60h] [ebp-88h]
  float v73;        // [esp+64h] [ebp-84h]
  float v74;        // [esp+68h] [ebp-80h]
  float v75;        // [esp+6Ch] [ebp-7Ch]
  float v76;        // [esp+70h] [ebp-78h]
  float v77;        // [esp+74h] [ebp-74h]
  float v78;        // [esp+78h] [ebp-70h]
  float v79;        // [esp+7Ch] [ebp-6Ch]
  float v80;        // [esp+80h] [ebp-68h]
  float v81;        // [esp+84h] [ebp-64h]
  float v82;        // [esp+88h] [ebp-60h]
  float v83;        // [esp+8Ch] [ebp-5Ch]
  float v84;        // [esp+98h] [ebp-50h]
  float v85;        // [esp+9Ch] [ebp-4Ch]
  TraceExtents v86; // [esp+ACh] [ebp-3Ch] BYREF

  XModelNumBones(a1);
  if ((int)a1->numCollSurfs <= 0)
    return -1;
  v63 = 0;
  v62 = -1;
  v6 = 0;
  v7 = a1;
    do {
        while (1) {
          v8 = v7->collSurfs + v6;
          if ((a6 & *(_DWORD *)(v8 + 36)) != 0)
            break;
          ++v63;
          v6 += 44;
          if ((signed int)v7->numCollSurfs <= v63)
            goto LABEL_18;
        }
      v61 = *(_DWORD *)(v8 + 32);
      quat = a3[v61].quat;
      v10 = quat[4];
      v11 = *a4 - v10;
      v12 = quat[5];
      v77 = a4[1] - v12;
      v13 = quat[6];
      v76 = a4[2] - v13;
      v80 = *a5 - v10;
      v79 = a5[1] - v12;
      v78 = a5[2] - v13;
      v14 = quat[7] * *quat;
      v15 = quat[7] * quat[1];
      v16 = quat[7] * quat[2];
      v64 = v14 * *quat;
      v17 = quat[1];
      v18 = v14 * v17;
      v19 = quat[2];
      v66 = v14 * v19;
      v20 = quat[3];
      v21 = v14 * v20;
      v67 = v17 * v15;
      v68 = v15 * v19;
      v22 = v15 * v20;
      v23 = v19 * v16;
      v24 = v16 * v20;
      v25 = 1.0 - (float)(v67 + v23);
      v85 = v18 + v24;
      v84 = v66 - v22;
      v26 = v18 - v24;
      v27 = 1.0 - (float)(v23 + v64);
      v28 = v22 + v66;
      v65 = v64 + v67;
      v86.start[0] =
          (float)((float)(v11 * v25) + (float)(v77 * v85)) + (float)(v76 * v84);
      v86.start[1] = (float)((float)(v11 * v26) + (float)(v77 * v27)) +
                     (float)(v76 * (float)(v68 + v21));
      v86.start[2] =
          (float)((float)(v11 * v28) + (float)(v77 * (float)(v68 - v21))) +
          (float)(v76 * (float)(1.0 - v65));
      v86.end[0] =
          (float)((float)(v25 * v80) + (float)(v79 * v85)) + (float)(v78 * v84);
      v86.end[1] = (float)((float)(v26 * v80) + (float)(v27 * v79)) +
                   (float)(v78 * (float)(v68 + v21));
      v86.end[2] =
          (float)((float)(v28 * v80) + (float)(v79 * (float)(v68 - v21))) +
          (float)((float)(1.0 - v65) * v78);
      CM_CalcTraceEntents(&v86);
        if (!CM_TraceBox(&v86, (const float *)(v8 + 8),
                         (const float *)(v8 + 20), LODWORD(a2->fraction))) {
          v59 = v86.end[0];
          v83 = v86.end[0] - v86.start[0];
          v60 = v86.end[1];
          v82 = v86.end[1] - v86.start[1];
          v29 = v86.end[2];
          v81 = v86.end[2] - v86.start[2];
            if (*(int *)(v8 + 4) > 0) {
              v30 = 0;
              v55 = 0;
              v58 = v86.start[0];
              v57 = v86.start[1];
              v56 = v86.start[2];
                do {
                  v31 = (float *)(*(_DWORD *)v8 + v55);
                  v32 = v31[1];
                  v33 = v31[3];
                  v34 = (float)((float)((float)(v59 * *v31) +
                                        (float)(v60 * v32)) +
                                (float)(v31[2] * v29)) -
                        v33;
                    if (v34 < 0.0) {
                      v35 = (float)((float)((float)(v58 * *v31) +
                                            (float)(v32 * v57)) +
                                    (float)(v31[2] * v56)) -
                            v33;
                        if (v35 > 0.0) {
                          v36 = v35 - v34;
                          v37 = fmaxf(0.0, (float)(v35 - 0.125) / v36);
                            if (v37 < a2->fraction) {
                              v38 = v35 / v36;
                              v39 = (float)(v83 * v38) + v58;
                              v40 =
                                  (float)((float)((float)(v39 * v31[4]) +
                                                  (float)((float)((float)(v82 *
                                                                          v38) +
                                                                  v57) *
                                                          v31[5])) +
                                          (float)((float)((float)(v81 * v38) +
                                                          v56) *
                                                  v31[6])) -
                                  v31[7];
                                if (v40 >= -0.001 && v40 <= 1.001) {
                                  v41 =
                                      (float)((float)((float)(v39 * v31[8]) +
                                                      (float)((float)((float)(v82 *
                                                                              v38) +
                                                                      v57) *
                                                              v31[9])) +
                                              (float)((float)((float)(v81 *
                                                                      v38) +
                                                              v56) *
                                                      v31[10])) -
                                      v31[11];
                                    if (v41 >= -0.001 &&
                                        (float)(v40 + v41) <= 1.001) {
                                      a2->startsolid = 0;
                                      a2->allsolid = 0;
                                      a2->fraction = v37;
                                      a2->surfaceFlags = *(_DWORD *)(v8 + 40);
                                      a2->contents = *(_DWORD *)(v8 + 36);
                                      a2->normal[0] = *v31;
                                      a2->normal[1] = v31[1];
                                      a2->normal[2] = v31[2];
                                      v62 = v61;
                                    }
                                }
                            }
                        }
                    }
                  ++v30;
                  v55 += 48;
                }
              while (*(_DWORD *)(v8 + 4) > v30);
            }
        }
      v7 = a1;
      ++v63;
      v6 += 44;
    }
  while ((signed int)a1->numCollSurfs > v63);
LABEL_18:
  if (v62 < 0)
    return -1;
  v42 = a3[v62].quat;
  v43 = v42[7] * *v42;
  v44 = v42[7] * v42[1];
  v45 = v42[7] * v42[2];
  v69 = v43 * *v42;
  v46 = v42[1];
  v47 = v43 * v46;
  v48 = v42[2];
  v49 = v43 * v48;
  v50 = v42[3];
  v51 = v43 * v50;
  v70 = v46 * v44;
  v71 = v44 * v48;
  v72 = v44 * v50;
  v52 = v45 * v48;
  v53 = v45 * v50;
  v73 = a2->normal[0];
  v74 = a2->normal[1];
  v75 = a2->normal[2];
  a2->normal[0] = (float)((float)((float)(1.0 - (float)(v70 + v52)) * v73) +
                          (float)((float)(v47 - v53) * v74)) +
                  (float)((float)(v72 + v49) * v75);
  a2->normal[1] = (float)((float)((float)(v47 + v53) * v73) +
                          (float)((float)(1.0 - (float)(v52 + v69)) * v74)) +
                  (float)((float)(v71 - v51) * v75);
  a2->normal[2] = (float)((float)((float)(v49 - v72) * v73) +
                          (float)((float)(v51 + v71) * v74)) +
                  (float)((float)(1.0 - (float)(v69 + v70)) * v75);
  return v62;
}

void __cdecl XModelFree(struct XModel *model)
{
  UNIMPLEMENTED();
}

void __cdecl XModelPartsFree(struct XModelParts_s *model)
{
  UNIMPLEMENTED();
}

struct XModel *__cdecl XModelPrecache(char const *, void *(__cdecl *)(int),
                                      void *(__cdecl *)(int))
{
  UNIMPLEMENTED();
}

struct XModel *__cdecl XModelFindExisting(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl ReplaceXModel(struct XModel *, struct XModel *)
{
  UNIMPLEMENTED();
}

int marker_xmodel;
struct XModelDefault g_default;

struct XModel *__cdecl XModelFindData(char const *)
{
  UNIMPLEMENTED();
}

XModelPartsFindData(char const *name)
{
  UNIMPLEMENTED();
}

XModelPartsSetData(char const* name,  XModelParts_s* modelParts,  void*  Alloc)(int))
{
  UNIMPLEMENTED();
}

XModelSurfsFindData(char const *name)
{
  UNIMPLEMENTED();
}

XModelSurfsSetData(char const* name,  XModelSurfs_s* modelSurfs,  void*  Alloc)(int))
{
  UNIMPLEMENTED();
}
