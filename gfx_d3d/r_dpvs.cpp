void __cdecl R_SetDpvsPlaneSides(struct DpvsPlane *) { UNIMPLEMENTED(); }

void __cdecl R_SetDpvsPlaneDist(float const *const, float, struct DpvsPlane *) {
  UNIMPLEMENTED();
}

void __cdecl R_FinishBuildingDpvsPlane(float const *const, float,
                                       struct DpvsPlane *) {
  UNIMPLEMENTED();
}

float __cdecl R_DpvsPlaneDistToPoint(struct DpvsPlane const *,
                                     float const *const) {
  UNIMPLEMENTED();
}

float __cdecl R_DpvsPlaneMaxSignedDistToBox(struct DpvsPlane const *,
                                            float const *) {
  UNIMPLEMENTED();
}

float __cdecl R_DpvsPlaneMinSignedDistToBox(struct DpvsPlane const *,
                                            float const *) {
  UNIMPLEMENTED();
}

void __cdecl R_SetCullDist(float dist) {
  __m128 v1; // xmm0

  v1 = _mm_cmpgt_ss((__m128)a1, (__m128)0LL);
  dpvsConfig = _mm_andnot_ps(v1, (__m128)0LL).u32[0] | a1 & v1.i32[0];
}

float __cdecl R_GetFarPlaneDist() {
  float v0; // xmm1_4

  v0 = *(float *)(r_zfar + 8);
  if (v0 == 0.0 && unk_1181E0C && LOBYTE(dword_1181DC8[0]) && unk_1181DAC == 1)
    v0 = unk_1181DC0;
  return fmaxf(*(float *)&dpvsConfig, v0);
}

void __cdecl R_ClearDpvsScene() {
  int result; // eax
  int v1;     // ecx
  int v2;     // edx

  dword_CB6F00 = 0;
  result = dword_1184B9C;
  if (dword_1184B9C && *(int *)(dword_1184B9C + 252) > 0) {
    v1 = 0;
    v2 = 0;
    do {
      *(_DWORD *)(*(_DWORD *)(result + 256) + v2 + 56) = 0;
      ++v1;
      result = dword_1184B9C;
      v2 += 60;
    } while (*(_DWORD *)(dword_1184B9C + 252) > v1);
  }
  return result;
}

void __cdecl R_CullDLightsInFrustum(struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_XModelWorldBounds(int, float *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl R_FrustumClipPlanes(struct _D3DMATRIX const *,
                                 float const (*const)[4], int,
                                 struct DpvsPlane *const) {
  UNIMPLEMENTED();
}

int __cdecl R_CellForPoint(float const *const origin) {
  int i; // edx

  if (!dword_1184B9C)
    R_Error(ERR_DROP, "\x15R_CellForCamera: bad model");
  for (i = *(_DWORD *)(dword_1184B9C + 12); *(_DWORD *)i == -1;
       i = *(_DWORD *)(i + 20)) {
    while (
        (float)((float)((float)((float)(*a1 * **(float **)(i + 12)) +
                                (float)(a1[1] *
                                        *(float *)(*(_DWORD *)(i + 12) + 4))) +
                        (float)(a1[2] * *(float *)(*(_DWORD *)(i + 12) + 8))) -
                *(float *)(*(_DWORD *)(i + 12) + 12)) > 0.0) {
      i = *(_DWORD *)(i + 16);
      if (*(_DWORD *)i != -1)
        return *(_DWORD *)(i + 8);
    }
  }
  return *(_DWORD *)(i + 8);
}

void __cdecl R_DrawModel(int entIndex) {
  GfxEntity *v1; // ebx
  char *result;  // eax

  if (byte_C96E87) {
    v1 = (GfxEntity *)(stru_1155004.entities + 116 * a1);
    R_UpdateXModelBounds((GfxSceneEntity *)(&scene + 13 * a1 + 369), v1);
    R_SkinSceneEnt((GfxSceneEntity *)(&scene + 13 * a1 + 369), v1);
    *(&scene + 13 * a1 + 372) = 5;
    return R_AddXModelSurfaces(a1);
  }
  return result;
}

void __cdecl R_AddWorldSurfacesDpvs(struct GfxViewParms const *viewParms,
                                    int cameraCellIndex) {
  uint32_t Buf;         // ebx
  uint32_t v3;          // eax
  char v4;              // dl
  bool v5;              // al
  bool v6;              // al
  bool v7;              // al
  uint8_t v8;           // al
  uint8_t v9;           // al
  uint8_t v10;          // al
  float v11;            // xmm0_4
  float v12;            // xmm4_4
  char v13;             // al
  char v14;             // al
  char v15;             // al
  int *v16;             // edx
  uint8_t v17;          // al
  uint8_t v18;          // al
  uint8_t v19;          // al
  float *v20;           // ecx
  int v21;              // eax
  int v22;              // ebx
  int v23;              // edi
  int j;                // esi
  float v25;            // xmm1_4
  float v26;            // xmm2_4
  float v27;            // xmm3_4
  int v28;              // edi
  int v29;              // esi
  int v30;              // edx
  _BYTE *v31;           // ecx
  int v32;              // ebx
  _BYTE *v33;           // edx
  float v34;            // xmm0_4
  char *v35;            // ebx
  int v36;              // eax
  _BYTE *v37;           // ecx
  int v38;              // ebx
  _BYTE *v39;           // edx
  float v40;            // xmm0_4
  GfxModel v41;         // eax
  float v42;            // xmm1_4
  float v43;            // xmm1_4
  _BYTE *v44;           // ecx
  int v45;              // esi
  _BYTE *v46;           // edx
  float v47;            // xmm1_4
  int i;                // edx
  int v49;              // edi
  int v50;              // edx
  _BYTE *v51;           // ecx
  int v52;              // esi
  _BYTE *v53;           // edx
  float v54;            // xmm1_4
  int v55;              // ebx
  int *v56;             // esi
  int v57;              // ebx
  int v58;              // eax
  int v59;              // esi
  int v60;              // ebx
  int v61;              // [esp+24h] [ebp-E4h]
  uint32_t entityCount; // [esp+28h] [ebp-E0h]
  GfxSceneEntity *v63;  // [esp+2Ch] [ebp-DCh]
  int v64;              // [esp+30h] [ebp-D8h]
  int v65;              // [esp+34h] [ebp-D4h]
  int v66;              // [esp+3Ch] [ebp-CCh]
  GfxCell v67;          // [esp+40h] [ebp-C8h] BYREF
  int v68;              // [esp+90h] [ebp-78h]
  int v69;              // [esp+94h] [ebp-74h]
  int v70;              // [esp+98h] [ebp-70h]
  int v71;              // [esp+9Ch] [ebp-6Ch]
  int v72;              // [esp+A0h] [ebp-68h]
  mnode_info_t v73;     // [esp+B8h] [ebp-50h] BYREF
  mnode_t v74;          // [esp+C4h] [ebp-44h] BYREF
  float v75;            // [esp+DCh] [ebp-2Ch] BYREF
  float v76;            // [esp+E0h] [ebp-28h]
  float v77;            // [esp+E4h] [ebp-24h]
  LargeLocal v78;       // [esp+E8h] [ebp-20h] BYREF
  LargeLocal v79;       // [esp+ECh] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v78, 4096);
  Buf = LargeLocal::GetBuf(&v78);
  LargeLocal::LargeLocal(&v79, 122880);
  v3 = LargeLocal::GetBuf(&v79);
  dword_C96E5C = Buf;
  dword_C96E64 = v3;
  byte_C96E84 = *(_BYTE *)(r_drawWorld + 8);
  v4 = *(_BYTE *)(r_drawEntities + 8);
  byte_C96E85 = v4;
  v5 = *(_BYTE *)(r_drawBModels + 8) && v4;
  byte_C96E88 = v5;
  v6 = *(_BYTE *)(r_drawSModels + 8) && byte_C96E85;
  byte_C96E86 = v6;
  v7 = *(_BYTE *)(r_drawXModels + 8) && byte_C96E85;
  byte_C96E87 = v7;
  dword_C96E58 = 0;
  dword_C96E50 = (int)a1->viewProjectionMatrix;
  dword_C96E54 = (int)a1->inverseViewProjectionMatrix;
  R_FrustumClipPlanes(a1->viewProjectionMatrix,
                      (float *)standardFrustumSidePlanes.coeffs, 4, (int)&v67);
  if (a1->projectionMatrix[15] == 0.0) {
    *(float *)stru_C96E68.coeffs = a1->origin[0];
    *(float *)&stru_C96E68.coeffs[4] = a1->origin[1];
    *(float *)&stru_C96E68.coeffs[8] = a1->origin[2];
    *(_DWORD *)&stru_C96E68.coeffs[12] = 1065353216;
    *(_QWORD *)dpvsGlob.coeffs = *(_QWORD *)&a1->axis[0][0];
    *(float *)&dpvsGlob.coeffs[8] = a1->axis[0][2];
    *(float *)&dpvsGlob.coeffs[12] =
        0.1 - (float)((float)((float)(*(float *)dpvsGlob.coeffs *
                                      *(float *)stru_C96E68.coeffs) +
                              (float)(*(float *)&dpvsGlob.coeffs[4] *
                                      *(float *)&stru_C96E68.coeffs[4])) +
                      (float)(*(float *)&dpvsGlob.coeffs[8] *
                              *(float *)&stru_C96E68.coeffs[8]));
    v8 = 12;
    if (*(int *)dpvsGlob.coeffs <= 0)
      v8 = 0;
    dpvsGlob.side[0] = v8;
    v9 = 16;
    if (*(int *)&dpvsGlob.coeffs[4] <= 0)
      v9 = 4;
    dpvsGlob.side[1] = v9;
    v10 = 20;
    if (*(int *)&dpvsGlob.coeffs[8] <= 0)
      v10 = 8;
    dpvsGlob.side[2] = v10;
    dpvsGlob.u.frontal = -1;
    dword_C96E48 = (int)&dpvsGlob;
    v11 = *(float *)(r_zfar + 8);
    if (v11 == 0.0 && unk_1181E0C && LOBYTE(dword_1181DC8[0]) &&
        unk_1181DAC == 1)
      v11 = unk_1181DC0;
    v12 = fmaxf(*(float *)&dpvsConfig, v11);
    if (v12 > 0.0) {
      *(float *)&dword_C96E34 = -a1->axis[0][0];
      *(float *)&dword_C96E38 = -a1->axis[0][1];
      *(float *)&dword_C96E3C = -a1->axis[0][2];
      *(float *)&dword_C96E40 =
          v12 - (float)((float)((float)(*(float *)&dword_C96E34 *
                                        *(float *)stru_C96E68.coeffs) +
                                (float)(*(float *)&dword_C96E38 *
                                        *(float *)&stru_C96E68.coeffs[4])) +
                        (float)(*(float *)&dword_C96E3C *
                                *(float *)&stru_C96E68.coeffs[8]));
      v13 = 12;
      if (dword_C96E34 <= 0)
        v13 = 0;
      byte_C96E44 = v13;
      v14 = 16;
      if (dword_C96E38 <= 0)
        v14 = 4;
      byte_C96E45 = v14;
      v15 = 20;
      if (dword_C96E3C <= 0)
        v15 = 8;
      byte_C96E46 = v15;
      byte_C96E47 = -1;
      dword_C96E4C = (int)&dword_C96E34;
      v16 = (int *)dword_C96E48;
      if (!dword_C96E48)
        goto LABEL_26;
      goto LABEL_35;
    }
    dword_C96E4C = 0;
  } else {
    *(float *)stru_C96E68.coeffs = -a1->axis[0][0];
    *(float *)&stru_C96E68.coeffs[4] = -a1->axis[0][1];
    *(float *)&stru_C96E68.coeffs[8] = -a1->axis[0][2];
    *(_DWORD *)&stru_C96E68.coeffs[12] = 0;
    *(_QWORD *)dpvsGlob.coeffs = *(_QWORD *)&a1->axis[0][0];
    *(float *)&dpvsGlob.coeffs[8] = a1->axis[0][2];
    *(float *)&dpvsGlob.coeffs[12] =
        262144.0 - (float)((float)((float)(*(float *)dpvsGlob.coeffs *
                                           *(float *)stru_C96E68.coeffs) +
                                   (float)(*(float *)&dpvsGlob.coeffs[4] *
                                           *(float *)&stru_C96E68.coeffs[4])) +
                           (float)(*(float *)&dpvsGlob.coeffs[8] *
                                   *(float *)&stru_C96E68.coeffs[8]));
    v17 = 12;
    if (*(int *)dpvsGlob.coeffs <= 0)
      v17 = 0;
    dpvsGlob.side[0] = v17;
    v18 = 16;
    if (*(int *)&dpvsGlob.coeffs[4] <= 0)
      v18 = 4;
    dpvsGlob.side[1] = v18;
    v19 = 20;
    if (*(int *)&dpvsGlob.coeffs[8] <= 0)
      v19 = 8;
    dpvsGlob.side[2] = v19;
    dword_C96E48 = 0;
    dword_C96E4C = 0;
  }
  v16 = (int *)dword_C96E48;
  if (!dword_C96E48) {
  LABEL_26:
    v61 = 4;
    goto LABEL_36;
  }
LABEL_35:
  v68 = *v16;
  v69 = v16[1];
  v70 = v16[2];
  v71 = v16[3];
  v72 = v16[4];
  v61 = 5;
LABEL_36:
  v20 = (float *)dword_C96E4C;
  if (dword_C96E4C) {
    v21 = 5 * v61;
    *(uint32_t *)((char *)&v67.writable.markCount + v21 * 4) =
        *(_DWORD *)dword_C96E4C;
    v67.mins[v21] = v20[1];
    v67.maxs[v21 - 2] = v20[2];
    v67.maxs[v21 - 1] = v20[3];
    v67.maxs[v21] = v20[4];
    ++v61;
  }
  *(_DWORD *)&algn_1183A7C[20] = a1;
  entityCount = stru_1155004.entityCount;
  if ((int)stru_1155004.entityCount > 0) {
    v65 = 0;
    v66 = 0;
    do {
      v22 = stru_1155004.entities + v66;
      if (*(int *)(stru_1155004.entities + v66) <= 1) {
        v63 = (GfxSceneEntity *)(&scene + 13 * v65 + 369);
        v41.obj = R_GetGfxEntityDObj(v63, (GfxEntity *)v22).obj;
        ((void(__cdecl *)(_DWORD, _DWORD, _DWORD))unk_1180870)(
            (GfxModel)v41.obj, &v75, &v74.u);
        v42 = *(float *)(v22 + 56);
        *(float *)&v73.node.plane = (float)(v42 * v75) + *(float *)(v22 + 60);
        *((float *)&v73.leaf + 1) = (float)(v42 * v76) + *(float *)(v22 + 64);
        *((float *)&v73.leaf + 2) = (float)(v42 * v77) + *(float *)(v22 + 68);
        v43 = *(float *)(v22 + 56);
        *(float *)&v74.contents =
            (float)(v43 * *(float *)&v74.u.node.plane) + *(float *)(v22 + 60);
        *(float *)&v74.parent =
            (float)(v43 * *((float *)&v74.u.leaf + 1)) + *(float *)(v22 + 64);
        *(float *)&v74.cellIndex =
            (float)(v43 * *((float *)&v74.u.leaf + 2)) + *(float *)(v22 + 68);
        if (v61 <= 0)
          goto LABEL_83;
        HIBYTE(v67.maxs[0]) = -1;
        if ((float)((float)((float)(v67.mins[1] *
                                    *(float *)((char *)&v73.node.plane +
                                               BYTE2(v67.maxs[0]))) +
                            (float)((float)(*(float *)((char *)&v73.node.plane +
                                                       BYTE1(v67.maxs[0])) *
                                            v67.mins[0]) +
                                    (float)(*(float *)((char *)&v73.node.plane +
                                                       LOBYTE(v67.maxs[0])) *
                                            *(float *)&v67.writable
                                                 .markCount))) +
                    v67.mins[2]) > 0.0) {
          v44 = (char *)&v67.portals + 3;
          v45 = 1;
          while (v45 != v61) {
            *v44 = -1;
            v46 = v44;
            v47 = (float)((float)(*(float *)((char *)&v73.node.plane +
                                             (unsigned __int8)*(v44 - 2)) *
                                  *(float *)(v44 - 15)) +
                          (float)(*(float *)((char *)&v73.node.plane +
                                             (unsigned __int8)*(v44 - 3)) *
                                  *(float *)(v44 - 19))) +
                  (float)(*(float *)(v44 - 11) *
                          *(float *)((char *)&v73.node.plane +
                                     (unsigned __int8)*(v44 - 1)));
            ++v45;
            v44 += 20;
            if ((float)(v47 + *(float *)(v46 - 7)) <= 0.0)
              goto LABEL_40;
          }
        LABEL_83:
          if (dword_C96E58 > 0) {
            v64 = 0;
            for (i = 0;; i = v64) {
              v49 = *(_DWORD *)(dword_C96E5C + 4 * i);
              v50 = *(_DWORD *)(v49 + 32);
              if (*(int *)(v49 + 28) <= 0)
                break;
              *(_BYTE *)(v50 + 19) = -1;
              if ((float)((float)((float)((float)(*(float *)((char *)&v73.node
                                                                 .plane +
                                                             *(unsigned __int8
                                                                   *)(v50 +
                                                                      16)) *
                                                  *(float *)v50) +
                                          (float)(*(float *)(v50 + 4) *
                                                  *(float *)((char *)&v73.node
                                                                 .plane +
                                                             *(unsigned __int8
                                                                   *)(v50 +
                                                                      17)))) +
                                  (float)(*(float *)(v50 + 8) *
                                          *(float *)((char *)&v73.node.plane +
                                                     *(unsigned __int8
                                                           *)(v50 + 18)))) +
                          *(float *)(v50 + 12)) <= 0.0) {
                v51 = (_BYTE *)(v50 + 39);
                v52 = 0;
                while (++v52 < *(_DWORD *)(v49 + 28)) {
                  *v51 = -1;
                  v53 = v51;
                  v54 =
                      (float)((float)(*(float *)((char *)&v73.node.plane +
                                                 (unsigned __int8)*(v51 - 3)) *
                                      *(float *)(v51 - 19)) +
                              (float)(*(float *)((char *)&v73.node.plane +
                                                 (unsigned __int8)*(v51 - 2)) *
                                      *(float *)(v51 - 15))) +
                      (float)(*(float *)(v51 - 11) *
                              *(float *)((char *)&v73.node.plane +
                                         (unsigned __int8)*(v51 - 1)));
                  v51 += 20;
                  if ((float)(v54 + *(float *)(v53 - 7)) > 0.0)
                    goto LABEL_90;
                }
                goto LABEL_40;
              }
            LABEL_90:
              if (++v64 >= dword_C96E58)
                goto LABEL_99;
            }
            goto LABEL_40;
          }
        LABEL_99:
          if ((float)(*(float *)&v74.contents - *(float *)&v73.node.plane) <=
              1536.0) {
            if ((float)(*(float *)&v74.parent - *((float *)&v73.leaf + 1)) >
                1536.0)
              goto LABEL_107;
          } else {
            if ((float)(*(float *)&v74.parent - *((float *)&v73.leaf + 1)) >
                1536.0) {
            LABEL_101:
              R_UpdateXModelBounds(v63, (GfxEntity *)v22);
              CG_CullIn((const centity_s *)*(&scene + 13 * v65 + 371));
              R_SkinSceneEnt(v63, (GfxEntity *)v22);
              *(&scene + 13 * v65 + 372) = 5;
              R_AddXModelSurfaces(v65);
              goto LABEL_40;
            }
          LABEL_107:
            if ((float)(*(float *)&v74.cellIndex - *((float *)&v73.leaf + 2)) >
                1536.0)
              goto LABEL_101;
          }
          if (R_FilterEntityIntoCells_r(*(_DWORD *)(dword_1184B9C + 12), v65,
                                        &v73, &v74) != -1)
            goto LABEL_40;
          goto LABEL_101;
        }
      } else if (*(_DWORD *)(stru_1155004.entities + v66) == 3) {
        v23 = *(&scene + 13 * v65 + 370);
        ClearBounds(&v73, &v74);
        for (j = 0; j != 8; ++j) {
          v25 = *(float *)(v23 + 12 * (j & 1));
          v26 = *(float *)(v23 + 12 * ((j >> 1) & 1) + 4);
          v27 = *(float *)(v23 + 12 * ((j >> 2) & 1) + 8);
          v75 = *(float *)(v22 + 60);
          v76 = *(float *)(v22 + 64);
          v77 = *(float *)(v22 + 68);
          v75 = (float)(v25 * *(float *)(v22 + 20)) + v75;
          v76 = (float)(v25 * *(float *)(v22 + 24)) + v76;
          v77 = (float)(v25 * *(float *)(v22 + 28)) + v77;
          v75 = (float)(v26 * *(float *)(v22 + 32)) + v75;
          v76 = (float)(v26 * *(float *)(v22 + 36)) + v76;
          v77 = (float)(v26 * *(float *)(v22 + 40)) + v77;
          v75 = (float)(v27 * *(float *)(v22 + 44)) + v75;
          v76 = (float)(v27 * *(float *)(v22 + 48)) + v76;
          v77 = (float)(v27 * *(float *)(v22 + 52)) + v77;
          AddPointToBounds(&v75, (float *)&v73.node.plane,
                           (float *)&v74.contents);
        }
        if (v61 <= 0)
          goto LABEL_46;
        HIBYTE(v67.maxs[0]) = -1;
        if ((float)((float)((float)(*(float *)((char *)&v73.node.plane +
                                               BYTE2(v67.maxs[0])) *
                                    v67.mins[1]) +
                            (float)((float)(*(float *)&v67.writable.markCount *
                                            *(float *)((char *)&v73.node.plane +
                                                       LOBYTE(v67.maxs[0]))) +
                                    (float)(v67.mins[0] *
                                            *(float *)((char *)&v73.node.plane +
                                                       BYTE1(v67.maxs[0]))))) +
                    v67.mins[2]) > 0.0) {
          v37 = (char *)&v67.portals + 3;
          v38 = 1;
          while (v61 != v38) {
            *v37 = -1;
            v39 = v37;
            v40 = (float)(*(float *)((char *)&v73.node.plane +
                                     (unsigned __int8)*(v37 - 1)) *
                          *(float *)(v37 - 11)) +
                  (float)((float)(*(float *)((char *)&v73.node.plane +
                                             (unsigned __int8)*(v37 - 2)) *
                                  *(float *)(v37 - 15)) +
                          (float)(*(float *)((char *)&v73.node.plane +
                                             (unsigned __int8)*(v37 - 3)) *
                                  *(float *)(v37 - 19)));
            ++v38;
            v37 += 20;
            if ((float)(v40 + *(float *)(v39 - 7)) <= 0.0)
              goto LABEL_40;
          }
        LABEL_46:
          if (dword_C96E58 <= 0) {
          LABEL_54:
            if (R_FilterEntityIntoCells_r(*(_DWORD *)(dword_1184B9C + 12), v65,
                                          &v73, &v74) == -1)
              R_AddBModelSurfaces((GfxSceneEntity *)(&scene + 13 * v65 + 369),
                                  v65);
          } else {
            v28 = 0;
            while (1) {
              v29 = *(_DWORD *)(dword_C96E5C + 4 * v28);
              v30 = *(_DWORD *)(v29 + 32);
              if (*(int *)(v29 + 28) <= 0)
                break;
              *(_BYTE *)(v30 + 19) = -1;
              if ((float)((float)((float)(*(float *)(v30 + 8) *
                                          *(float *)((char *)&v73.node.plane +
                                                     *(unsigned __int8
                                                           *)(v30 + 18))) +
                                  (float)((float)(*(float *)((char *)&v73.node
                                                                 .plane +
                                                             *(unsigned __int8
                                                                   *)(v30 +
                                                                      17)) *
                                                  *(float *)(v30 + 4)) +
                                          (float)(*(float *)((char *)&v73.node
                                                                 .plane +
                                                             *(unsigned __int8
                                                                   *)(v30 +
                                                                      16)) *
                                                  *(float *)v30))) +
                          *(float *)(v30 + 12)) <= 0.0) {
                v31 = (_BYTE *)(v30 + 39);
                v32 = 0;
                while (++v32 < *(_DWORD *)(v29 + 28)) {
                  *v31 = -1;
                  v33 = v31;
                  v34 =
                      (float)(*(float *)((char *)&v73.node.plane +
                                         (unsigned __int8)*(v31 - 1)) *
                              *(float *)(v31 - 11)) +
                      (float)((float)(*(float *)((char *)&v73.node.plane +
                                                 (unsigned __int8)*(v31 - 2)) *
                                      *(float *)(v31 - 15)) +
                              (float)(*(float *)((char *)&v73.node.plane +
                                                 (unsigned __int8)*(v31 - 3)) *
                                      *(float *)(v31 - 19)));
                  v31 += 20;
                  if ((float)(v34 + *(float *)(v33 - 7)) > 0.0)
                    goto LABEL_53;
                }
                break;
              }
            LABEL_53:
              if (++v28 >= dword_C96E58)
                goto LABEL_54;
            }
          }
        }
      }
    LABEL_40:
      ++v65;
      v66 += 116;
    } while (entityCount != v65);
  }
  if (!*(_BYTE *)(r_skipPvs + 8)) {
    if (a2 < 0) {
      v58 = dword_1184B9C;
      if (*(int *)(dword_1184B9C + 252) > 0) {
        v59 = 0;
        v60 = 0;
        do {
          R_AddVisibleSurfacesInCell((char *)(v60 + *(_DWORD *)(v58 + 256)),
                                     (int)&v67, v61);
          ++v59;
          v58 = dword_1184B9C;
          v60 += 60;
        } while (*(_DWORD *)(dword_1184B9C + 252) > v59);
      }
    } else {
      v35 = (char *)(*(_DWORD *)(dword_1184B9C + 256) + 60 * a2);
      if (*(_BYTE *)(r_singleCell + 8)) {
        dword_C96E4C = 0;
        R_AddVisibleSurfacesInCell(v35, (int)&v67, v61);
      } else {
        R_VisitPortals((const GfxCell *)v35, &dpvsGlob, &v67, (GfxPortal *)v61);
      }
    }
  }
  if (dword_C96E4C) {
    v36 = dword_1184B9C;
    if (*(int *)(dword_1184B9C + 24) > 0) {
      v57 = 0;
      do {
        R_AddWorldSurfaceWithCull(
            *(_DWORD *)(*(_DWORD *)(v36 + 28) + 4 * v57++), (int)&v67, v61 - 1,
            0);
        v36 = dword_1184B9C;
      } while (v57 < *(_DWORD *)(dword_1184B9C + 24));
    }
  }
  if (dword_1155014 > 0) {
    v55 = 0;
    v56 = &scene;
    do {
      *((_BYTE *)v56 + 1432) =
          R_CullPointAndRadius((const float *)&scene + 11 * v55 + 7,
                               *((float *)&scene + 11 * v55 + 10),
                               (const DpvsPlane *)&v67, v61) == 2;
      ++v55;
      v56 = (int *)((char *)v56 + 1);
    } while (v55 < dword_1155014);
  }
  if (*(_DWORD *)(r_vc_makelog + 8))
    RB_ShowLightVisCachePoints(a1->origin, (const DpvsPlane *)&v67, v61);
  LargeLocal::~LargeLocal(&v79);
  LargeLocal::~LargeLocal(&v78);
}

int marker_r_dpvs;
void __cdecl R_SetAncestorListStatus(struct GfxPortal *, bool) {
  UNIMPLEMENTED();
}

int __cdecl R_AddCellToList(struct GfxCell const *,
                            struct GfxCell const **const, int) {
  UNIMPLEMENTED();
}

bool __cdecl R_IsCellInList(struct GfxCell const *,
                            struct GfxCell const **const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_FreeHullPoints(float (*)[2]) { UNIMPLEMENTED(); }

void __cdecl R_AssertValidQueue(void) { UNIMPLEMENTED(); }

int __cdecl R_FirstChildHeapIndex(int) { UNIMPLEMENTED(); }

int __cdecl R_ParentHeapIndex(int) { UNIMPLEMENTED(); }

bool __cdecl R_XModelIsHuge(float const *const, float const *const) {
  UNIMPLEMENTED();
}

int __cdecl R_AddNearAndFarClipPlanes(struct DpvsPlane *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_ClearRecursionAncestors(struct GfxPortal *) { UNIMPLEMENTED(); }

void __cdecl R_SetRecursionAncestors(struct GfxPortal *) { UNIMPLEMENTED(); }

struct GfxPortal *__cdecl R_NextQueuedPortal(void) {
  UNIMPLEMENTED();
}

void __cdecl R_BModelWorldBounds(struct GfxEntity const *,
                                 struct GfxBrushModel const *, float *const,
                                 float *const) {
  UNIMPLEMENTED();
}

void __cdecl R_AddEntityToCell(struct GfxCell *, int, float const *const,
                               float const *const) {
  UNIMPLEMENTED();
}

void __cdecl R_ProjectPortal(int, float const (*const)[3], float *const,
                             float *const, enum DpvsClipChildren *) {
  UNIMPLEMENTED();
}

void __cdecl R_AddWorldSurfaceNoCull(int) { UNIMPLEMENTED(); }

bool __cdecl R_BoxPartiallyInFrontOfPlane(float const *,
                                          struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

bool __cdecl R_BoxEntirelyInFrontOfPlane(float const *,
                                         struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

bool __cdecl R_BoxEntirelyBehindPlane(float const *, struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

void __cdecl R_GetSidePlaneNormals(float const (*const)[3], int,
                                   float (*const)[3]) {
  UNIMPLEMENTED();
}

float __cdecl R_DpvsPlaneDistToEye(struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

int __cdecl R_FilterEntityIntoCells_r(struct mnode_t *, int, float const *const,
                                      float const *const) {
  UNIMPLEMENTED();
}

float (*__cdecl R_ChopPortalWinding(float (*)[3], int *,
                                    struct DpvsPlane const *,
                                    float (*)[3]))[3] {
  UNIMPLEMENTED();
}

bool __cdecl R_PortalBehindPlane(struct GfxPortal const *,
                                 struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

bool __cdecl R_CullOccluderByPlane(struct GfxOccluder const *,
                                   struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

float __cdecl R_NearestPointOnWinding(float const (*const)[3], int,
                                      struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

float __cdecl R_FurthestPointOnWinding(float const (*const)[3], int,
                                       struct DpvsPlane const *) {
  UNIMPLEMENTED();
}

bool __cdecl R_ClipBoxDpvs(float const *, struct DpvsPlane const *const, int,
                           int) {
  UNIMPLEMENTED();
}

bool __cdecl R_CullBoxHierarchy(float const *, struct DpvsPlane const *const,
                                int, int) {
  UNIMPLEMENTED();
}

bool __cdecl R_CullBoxDpvs(float const *, struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

bool __cdecl R_CullBoxLeaf(float const *, struct DpvsPlane const *const, int,
                           int) {
  UNIMPLEMENTED();
}

void __cdecl R_SetupDpvsForDir(struct GfxViewParms const *) { UNIMPLEMENTED(); }

void __cdecl R_SetupDpvsForPoint(struct GfxViewParms const *) {
  UNIMPLEMENTED();
}

int __cdecl R_ChopPortal(struct GfxPortal *, struct DpvsPlane const *,
                         struct DpvsPlane const *const, int,
                         float (*const)[128][3], float (**)[3]) {
  UNIMPLEMENTED();
}

float (*__cdecl R_AllocHullPoints(void))[2] { UNIMPLEMENTED(); }

void __cdecl R_EnqueuePortal(struct GfxPortal *) { UNIMPLEMENTED(); }

void __cdecl R_AddCullGroupSurfaces(int, struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_FilterBModelIntoCells(int, struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddWorldSurfaceWithCull(int, struct DpvsPlane const *const, int,
                                       int) {
  UNIMPLEMENTED();
}

bool __cdecl R_PortalBehindAllPlanes(struct GfxPortal const *,
                                     struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

bool __cdecl R_PortalBehindAnyPlane(struct GfxPortal const *,
                                    struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

bool __cdecl R_CullOccluder(struct GfxOccluder const *,
                            struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

int __cdecl R_AddBevelPlanes(struct DpvsPlane *const, int,
                             float const (*const)[3], float const (*const)[3],
                             float const *const, float const *const,
                             enum DpvsForceBevels) {
  UNIMPLEMENTED();
}

void __cdecl R_DpvsPlaneFromEdge(float const *const, float const *const,
                                 struct DpvsPlane *) {
  UNIMPLEMENTED();
}

void __cdecl R_AddSkySurfacesDpvs(struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_SetupDpvs(struct GfxViewParms const *, float const (*const)[4],
                         int, struct DpvsPlane *const) {
  UNIMPLEMENTED();
}

void __cdecl R_AddVertToPortalHullPoints(struct GfxPortal *,
                                         float const *const) {
  UNIMPLEMENTED();
}

bool __cdecl R_PortalOccluded(struct GfxPortal const *) { UNIMPLEMENTED(); }

void __cdecl R_AddCellCullGroups(struct GfxCell const *,
                                 struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddCellOccluders(struct GfxCell const *,
                                struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

int __cdecl R_PortalClipPlanes(struct DpvsPlane *const, int,
                               float const (*const)[3], struct GfxCell *,
                               enum DpvsClipChildren *) {
  UNIMPLEMENTED();
}

bool __cdecl R_ChopPortalAndAddHullPoints(struct GfxPortal *,
                                          struct DpvsPlane const *,
                                          struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

bool __cdecl R_ShouldSkipPortal(struct GfxPortal const *,
                                struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

int __cdecl R_GetFurtherCellList_r(struct GfxCell const *,
                                   struct DpvsPlane const *,
                                   struct DpvsPlane const *const, int,
                                   float (*const)[128][3],
                                   struct GfxCell const **const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddStaticModelWithCull(int, struct DpvsPlane const *const, int,
                                      int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddStaticModelNoCull(int) { UNIMPLEMENTED(); }

void __cdecl R_FilterXModelIntoCells(int, struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_CullModels(struct GfxCell const *, struct DpvsPlane const *const,
                          int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddAabbTreeSurfaces_r(struct GfxAabbTree const *,
                                     struct DpvsPlane const *const, int, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddCellSurfaces(struct GfxCell const *,
                               struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_FilterEntitiesIntoCells(struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddVisibleSurfacesInCell(struct GfxCell const *,
                                        struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_VisitAllFurtherCells(struct GfxCell const *,
                                    struct DpvsPlane const *,
                                    struct DpvsPlane const *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_VisitPortalsForCell(struct GfxCell const *, struct GfxPortal *,
                                   struct DpvsPlane const *,
                                   struct DpvsPlane const *const, int,
                                   enum DpvsClipChildren) {
  UNIMPLEMENTED();
}

void __cdecl R_VisitPortals(struct GfxCell const *, struct DpvsPlane const *,
                            struct DpvsPlane const *const, int) {
  uint32_t Buf;    // eax
  int v5;          // ebx
  uint32_t *v6;    // ecx
  uint32_t v7;     // edx
  int v8;          // eax
  int v9;          // edx
  int v10;         // esi
  int v11;         // ebx
  int v12;         // eax
  int v13;         // edx
  int v14;         // edi
  _DWORD *v15;     // edx
  float v16;       // xmm0_4
  float v17;       // xmm4_4
  float v18;       // xmm3_4
  float v19;       // xmm2_4
  int v20;         // ecx
  int v21;         // edx
  float *v22;      // eax
  float v23;       // xmm1_4
  float v24;       // xmm1_4
  float v25;       // xmm6_4
  float v26;       // xmm7_4
  float v27;       // xmm0_4
  float v28;       // xmm1_4
  float *v29;      // esi
  float *v30;      // ecx
  float *v31;      // ebx
  float v32;       // xmm3_4
  float v33;       // xmm0_4
  float v34;       // xmm1_4
  char v35;        // al
  char v36;        // al
  char v37;        // al
  float *v38;      // edx
  float *v39;      // esi
  float v40;       // xmm7_4
  float v41;       // xmm6_4
  float v42;       // xmm5_4
  float v43;       // xmm4_4
  float v44;       // xmm3_4
  float v45;       // xmm2_4
  int v46;         // ecx
  float *v47;      // eax
  float v48;       // xmm2_4
  float *v49;      // ecx
  int v50;         // eax
  GfxPortal *v51;  // ecx
  int v52;         // edi
  int v53;         // ecx
  _DWORD *v54;     // eax
  int v55;         // edx
  int v56;         // ebx
  float *v57;      // edx
  float *v58;      // ecx
  float v59;       // xmm4_4
  float v60;       // xmm5_4
  float v61;       // xmm3_4
  float v62;       // xmm2_4
  float v63;       // xmm1_4
  GfxCell *v64;    // esi
  int j;           // edx
  float *v66;      // eax
  float v67;       // xmm2_4
  float v68;       // xmm4_4
  float v69;       // xmm3_4
  float v70;       // xmm5_4
  int v71;         // ebx
  int v72;         // ecx
  float *v73;      // edx
  float *v74;      // eax
  char v75;        // al
  char v76;        // al
  char v77;        // al
  float v78;       // xmm5_4
  float *v79;      // ecx
  float v80;       // xmm4_4
  float v81;       // xmm3_4
  float v82;       // xmm2_4
  int v83;         // eax
  int v84;         // ebx
  int v85;         // ecx
  float v86;       // xmm2_4
  float *v87;      // ecx
  float *v88;      // edx
  float v89;       // xmm1_4
  int v90;         // edx
  float v91;       // xmm2_4
  int v92;         // eax
  float v93;       // xmm1_4
  int v94;         // esi
  float *v95;      // ebx
  float v96;       // xmm2_4
  float v97;       // xmm1_4
  float *v98;      // eax
  float v99;       // xmm0_4
  float v100;      // xmm0_4
  int v101;        // edx
  int v102;        // esi
  int v103;        // ebx
  int v104;        // eax
  int v105;        // edx
  _DWORD *v106;    // edx
  int v107;        // eax
  int v108;        // edi
  int i;           // ecx
  _DWORD *v110;    // eax
  int v111;        // edx
  int v112;        // [esp+28h] [ebp-18F0h]
  int v113;        // [esp+2Ch] [ebp-18ECh]
  int v114;        // [esp+30h] [ebp-18E8h]
  _BOOL4 v115;     // [esp+34h] [ebp-18E4h]
  int v116;        // [esp+38h] [ebp-18E0h]
  bool v117;       // [esp+3Fh] [ebp-18D9h]
  int v118;        // [esp+40h] [ebp-18D8h]
  int v119;        // [esp+48h] [ebp-18D0h]
  float v120;      // [esp+4Ch] [ebp-18CCh]
  float v121;      // [esp+50h] [ebp-18C8h]
  int v122;        // [esp+54h] [ebp-18C4h]
  int v123;        // [esp+58h] [ebp-18C0h]
  int v124;        // [esp+5Ch] [ebp-18BCh]
  char v125;       // [esp+6Ch] [ebp-18ACh] BYREF
  float v126[384]; // [esp+86Ch] [ebp-10ACh] BYREF
  float v127;      // [esp+E6Ch] [ebp-AACh] BYREF
  float v128;      // [esp+E70h] [ebp-AA8h]
  float v129;      // [esp+E74h] [ebp-AA4h] BYREF
  float v130[261]; // [esp+E78h] [ebp-AA0h] BYREF
  float __src[3];  // [esp+128Ch] [ebp-68Ch] BYREF
  float v132;      // [esp+1298h] [ebp-680h]
  float v133;      // [esp+129Ch] [ebp-67Ch]
  float v134;      // [esp+12A0h] [ebp-678h]
  float v135[128]; // [esp+158Ch] [ebp-38Ch] BYREF
  GfxCell v136;    // [esp+178Ch] [ebp-18Ch] BYREF
  float v137[12];  // [esp+18CCh] [ebp-4Ch] BYREF
  LargeLocal v138; // [esp+18FCh] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v138, (int)&loc_20000);
  Buf = LargeLocal::GetBuf(&v138);
  v5 = 0;
  v6 = (uint32_t *)(Buf - 512);
  v7 = Buf;
  do {
    v5 += 64;
    v7 += 512;
    v6 += 128;
    *v6 = v7;
  } while (v5 != 16320);
  *(_DWORD *)(Buf + 130560) = 0;
  dword_C96E80 = Buf;
  dword_C96E7C = (int)&v125;
  *(_DWORD *)stru_C96E68.side = 0;
  R_VisitPortalsForCell((int)a1, 0, (float *)a2->coeffs, a3, a4,
                        (const DpvsPlane *)1);
  v114 = 0;
LABEL_4:
  if (!*(_DWORD *)stru_C96E68.side)
    goto LABEL_129;
  do {
    v112 = *(_DWORD *)dword_C96E7C;
    **(_BYTE **)dword_C96E7C = 0;
    v8 = *(_DWORD *)stru_C96E68.side - 1;
    *(_DWORD *)stru_C96E68.side = v8;
    if (v8 <= 0) {
      v9 = 8 * v8;
      v10 = 0;
      v11 = dword_C96E7C;
      goto LABEL_7;
    }
    v52 = 0;
    v53 = 1;
    v123 = 0;
    while (1) {
      if (v53 >= v8) {
        v10 = 8 * v53;
        v11 = dword_C96E7C;
      LABEL_55:
        v9 = 8 * v8;
        v54 = (_DWORD *)(v10 + v11);
        if (*(float *)(v10 + v11 + 4) >= *(float *)(v11 + v9 + 4))
          goto LABEL_61;
        goto LABEL_56;
      }
      v11 = dword_C96E7C;
      v10 = 8 * v53;
      if (*(float *)(dword_C96E7C + 8 * v53 + 4) <=
          *(float *)(dword_C96E7C + 8 * v53 + 12))
        goto LABEL_55;
      v53 = v52 + 2;
      v10 = 8 * (v52 + 2);
      v9 = 8 * v8;
      v54 = (_DWORD *)(v10 + dword_C96E7C);
      if (*(float *)(v10 + dword_C96E7C + 4) >=
          *(float *)(dword_C96E7C + v9 + 4)) {
      LABEL_61:
        v10 = 8 * v123;
        goto LABEL_7;
      }
    LABEL_56:
      v55 = v54[1];
      *(_DWORD *)(v11 + 8 * v123) = *v54;
      *(_DWORD *)(v11 + 8 * v123 + 4) = v55;
      v52 = 2 * v53;
      v8 = *(_DWORD *)stru_C96E68.side;
      if (*(int *)stru_C96E68.side < 2 * v53 + 1)
        break;
      v123 = v53;
      v53 = 2 * v53 + 1;
    }
    v9 = 8 * *(_DWORD *)stru_C96E68.side;
    v11 = dword_C96E7C;
  LABEL_7:
    v12 = *(_DWORD *)(v11 + v9);
    v13 = *(_DWORD *)(v11 + v9 + 4);
    *(_DWORD *)(v11 + v10) = v12;
    *(_DWORD *)(v11 + v10 + 4) = v13;
    v14 = Com_ConvexHull(*(float(**)[2])(v112 + 40),
                         *(unsigned __int8 *)(v112 + 37), (float(*)[2])v135);
    v15 = *(_DWORD **)(v112 + 40);
    *v15 = dword_C96E80;
    dword_C96E80 = (int)v15;
    *(_DWORD *)(v112 + 40) = 0;
    if (!v14)
      goto LABEL_4;
    if (++v114 == *(_DWORD *)(r_portalWalkLimit + 8)) {
      if (!*(_DWORD *)stru_C96E68.side)
        break;
    LABEL_118:
      v124 = *(_DWORD *)dword_C96E7C;
      **(_BYTE **)dword_C96E7C = 0;
      v107 = *(_DWORD *)stru_C96E68.side - 1;
      *(_DWORD *)stru_C96E68.side = v107;
      if (v107 <= 0) {
        v101 = 8 * v107;
        v102 = 0;
        v103 = dword_C96E7C;
        goto LABEL_117;
      }
      v116 = 0;
      v108 = 0;
      for (i = 1; v107 > i; i = 2 * i + 1) {
        v103 = dword_C96E7C;
        v102 = 8 * i;
        if (*(float *)(dword_C96E7C + 8 * i + 4) <=
            *(float *)(dword_C96E7C + 8 * i + 12))
          goto LABEL_121;
        i = v108 + 2;
        v102 = 8 * (v108 + 2);
        v101 = 8 * v107;
        v110 = (_DWORD *)(v102 + dword_C96E7C);
        if (*(float *)(v102 + dword_C96E7C + 4) >=
            *(float *)(dword_C96E7C + v101 + 4)) {
        LABEL_127:
          v102 = 8 * v116;
          goto LABEL_117;
        }
      LABEL_122:
        v111 = v110[1];
        *(_DWORD *)(v103 + 8 * v116) = *v110;
        *(_DWORD *)(v103 + 8 * v116 + 4) = v111;
        v108 = 2 * i;
        v107 = *(_DWORD *)stru_C96E68.side;
        if (2 * i + 1 > *(int *)stru_C96E68.side) {
          v101 = 8 * *(_DWORD *)stru_C96E68.side;
          v103 = dword_C96E7C;
        LABEL_117:
          v104 = *(_DWORD *)(v101 + v103);
          v105 = *(_DWORD *)(v101 + v103 + 4);
          *(_DWORD *)(v102 + v103) = v104;
          *(_DWORD *)(v102 + v103 + 4) = v105;
          v106 = *(_DWORD **)(v124 + 40);
          *v106 = dword_C96E80;
          dword_C96E80 = (int)v106;
          *(_DWORD *)(v124 + 40) = 0;
          if (!*(_DWORD *)stru_C96E68.side)
            goto LABEL_129;
          goto LABEL_118;
        }
        v116 = i;
      }
      v102 = 8 * i;
      v103 = dword_C96E7C;
    LABEL_121:
      v101 = 8 * v107;
      v110 = (_DWORD *)(v102 + v103);
      if (*(float *)(v102 + v103 + 4) >= *(float *)(v103 + v101 + 4))
        goto LABEL_127;
      goto LABEL_122;
    }
    v16 = -*(float *)(v112 + 20);
    v17 = v16 * *(float *)(v112 + 8);
    v18 = v16 * *(float *)(v112 + 12);
    v19 = v16 * *(float *)(v112 + 16);
    if (v14 > 0) {
      v20 = 0;
      v21 = 0;
      v22 = __src;
      do {
        v23 = v135[v21];
        *v22 = (float)(v23 * *(float *)(v112 + 44)) + v17;
        v22[1] = (float)(v23 * *(float *)(v112 + 48)) + v18;
        v22[2] = (float)(v23 * *(float *)(v112 + 52)) + v19;
        v24 = v135[v21 + 1];
        *v22 = (float)(v24 * *(float *)(v112 + 56)) + *v22;
        v22[1] = (float)(v24 * *(float *)(v112 + 60)) + v22[1];
        v22[2] = (float)(v24 * *(float *)(v112 + 64)) + v22[2];
        ++v20;
        v22 += 3;
        v21 += 2;
      } while (v14 != v20);
    }
    if (*(_DWORD *)(r_showPortals + 8) && !*(_BYTE *)(r_portalBevelsOnly + 8))
      R_AddDebugPolygon((DebugGlobals *)((char *)frontEndDataOut + 2399512),
                        (float *)&R_VisitPortals(GfxCell const *,
                                                 DpvsPlane const *,
                                                 DpvsPlane const *, int)::color,
                        v14, (float(*)[3])__src);
    if (v14 > 10 || *(_BYTE *)(r_portalBevelsOnly + 8)) {
      v117 = 1;
      v119 = 1;
    } else {
      v117 = *(float *)(r_portalBevels + 8) > 0.0;
      v119 = 0;
    }
    R_GetSidePlaneNormals(__src, v14, v126);
    if (!v117 && *(float *)(r_portalMinClipArea + 8) <= 0.0) {
      v113 = 0;
      v115 = 1;
      goto LABEL_26;
    }
    if (v14 <= 0) {
      v121 = 1.0;
      v120 = 1.0;
      v25 = -1.0;
      v26 = -1.0;
      v27 = -2.0;
      v28 = -2.0;
      goto LABEL_22;
    }
    v78 = __src[0];
    v79 = (float *)dword_C96E50;
    v80 = __src[1];
    v81 = __src[2];
    v82 = (float)((float)(__src[2] * *(float *)(dword_C96E50 + 44)) +
                  (float)((float)(__src[1] * *(float *)(dword_C96E50 + 28)) +
                          (float)(__src[0] * *(float *)(dword_C96E50 + 12)))) +
          *(float *)(dword_C96E50 + 60);
    if (v82 >= 0.125) {
      v94 = 0;
      v121 = 1.0;
      v120 = 1.0;
      v25 = -1.0;
      v26 = -1.0;
      v95 = __src;
      while (1) {
        v96 = 1.0 / v82;
        v97 = (float)((float)((float)((float)(v78 * v79[1]) +
                                      (float)(v80 * v79[5])) +
                              (float)(v81 * v79[9])) +
                      v79[13]) *
              v96;
        v98 = &v127 + 2 * v94;
        v99 = (float)((float)((float)((float)(v78 * *v79) +
                                      (float)(v80 * v79[4])) +
                              (float)(v81 * v79[8])) +
                      v79[12]) *
              v96;
        *v98 = v99;
        v98[1] = v97;
        v121 = fminf(v99, v121);
        v25 = fmaxf(v99, v25);
        v120 = fminf(*(&v128 + 2 * v94), v120);
        v100 = fmaxf(*(&v128 + 2 * v94), v26);
        v26 = v100;
        if (v14 == ++v94)
          break;
        v78 = v95[3];
        v80 = v95[4];
        v81 = v95[5];
        v82 = (float)((float)(v81 * v79[11]) +
                      (float)((float)(v80 * v79[7]) + (float)(v78 * v79[3]))) +
              v79[15];
        v95 += 3;
        if (v82 < 0.125)
          goto LABEL_91;
      }
      v28 = v25 - v121;
      v27 = v100 - v120;
    LABEL_22:
      if (*(float *)(r_portalMinClipArea + 8) <=
          (float)((float)(v28 * v27) * 0.25)) {
        v87 = &v127 + 2 * v14;
        *v87 = v127;
        v87[1] = v128;
        v88 = &v130[2 * v14 - 1];
        *v88 = v129;
        v88[1] = v130[0];
        v89 = 0.0;
        if (v14 > 0) {
          v90 = 1;
          v91 = 0.0;
          v92 = 2;
          do {
            v93 = *(float *)((char *)&v127 + v92 * 4);
            ++v90;
            v92 += 2;
            v91 = v91 +
                  (float)(v93 * (float)(*(float *)((char *)&v128 + v92 * 4) -
                                        v126[v92 + 381]));
          } while (v14 >= v90);
          v89 = v91 * 0.125;
        }
        v115 = *(float *)(r_portalMinClipArea + 8) <= v89;
      } else {
        v115 = 0;
      }
    } else {
    LABEL_91:
      v115 = 1;
      v120 = -1.0;
      v121 = -1.0;
      v25 = 1.0;
      v26 = 1.0;
    }
    if (v117) {
      v56 = 0;
      v57 = (float *)dword_C96E54;
    LABEL_64:
      v58 = &v127 + 3 * v56;
      v59 = v121;
      while (1) {
        v60 = (unsigned int)(v56 - 1) > 1 ? v26 : v120;
        v61 = (float)((float)(v59 * v57[1]) + (float)(v60 * v57[5])) + v57[13];
        v62 = (float)((float)(v59 * v57[2]) + (float)(v60 * v57[6])) + v57[14];
        v63 = 1.0 /
              (float)((float)((float)(v59 * v57[3]) + (float)(v60 * v57[7])) +
                      v57[15]);
        *v58 = (float)((float)((float)(v59 * *v57) + (float)(v60 * v57[4])) +
                       v57[12]) *
               v63;
        v58[1] = v61 * v63;
        v58[2] = v62 * v63;
        if (++v56 > 3)
          break;
        v58 += 3;
        v59 = v25;
        if (v56 <= 1)
          goto LABEL_64;
      }
      v130[9] = v127;
      v130[10] = v128;
      v130[11] = v129;
      R_GetSidePlaneNormals(&v127, 4, v137);
      v122 = 0;
      v113 = 0;
      v64 = &v136;
      for (j = 0;; j = v71) {
        v66 = &v137[3 * j];
        v67 = *v66;
        v64->writable.markCount = *(uint32_t *)v66;
        v68 = v66[1];
        v64->mins[0] = v68;
        v69 = v66[2];
        v64->mins[1] = v69;
        if (v119 || v14 <= 0)
          goto LABEL_81;
        v70 = *(float *)(r_portalBevels + 8);
        if ((float)((float)(v69 * v126[2]) +
                    (float)((float)(v67 * v126[0]) + (float)(v68 * v126[1]))) <=
            v70)
          break;
      LABEL_74:
        if ((*(_BYTE *)(r_showPortals + 8) & 2) == 0)
          goto LABEL_75;
        v71 = v122 + 1;
        R_AddDebugLine((DebugGlobals *)((char *)frontEndDataOut + 2399512),
                       &v127 + 3 * v122, &v127 + 3 * v122 + 3, colorMdCyan);
      LABEL_76:
        if (v71 > 3)
          goto LABEL_26;
        v122 = v71;
      }
      v72 = 0;
      v73 = v126;
      while (v14 != ++v72) {
        v74 = v73;
        v73 += 3;
        if ((float)((float)((float)(v68 * v74[4]) +
                            (float)(*(float *)&v64->writable.markCount *
                                    v74[3])) +
                    (float)(v69 * v74[5])) > v70)
          goto LABEL_74;
      }
    LABEL_81:
      if (*(_DWORD *)(r_showPortals + 8))
        R_AddDebugLine((DebugGlobals *)((char *)frontEndDataOut + 2399512),
                       &v127 + 3 * v122, &v130[3 * v122], colorLtCyan);
      v64->mins[2] =
          0.001 -
          (float)((float)((float)(*(float *)&v64->writable.markCount *
                                  *(&v127 + 3 * v122)) +
                          (float)(v64->mins[0] * *(&v127 + 3 * v122 + 1))) +
                  (float)(v64->mins[1] * v130[3 * v122 - 1]));
      v75 = 12;
      if ((int)v64->writable.markCount <= 0)
        v75 = 0;
      LOBYTE(v64->maxs[0]) = v75;
      v76 = 16;
      if (SLODWORD(v64->mins[0]) <= 0)
        v76 = 4;
      BYTE1(v64->maxs[0]) = v76;
      if (SLODWORD(v64->mins[1]) <= 0)
        v77 = 8;
      else
        v77 = 20;
      BYTE2(v64->maxs[0]) = v77;
      HIBYTE(v64->maxs[0]) = -1;
      ++v113;
      v64 = (GfxCell *)((char *)v64 + 20);
    LABEL_75:
      v71 = v122 + 1;
      goto LABEL_76;
    }
    v113 = 0;
  LABEL_26:
    if (v14 <= 10 && v14 > 0) {
      v118 = 0;
      v29 = __src;
      v30 = v126;
      v31 = (float *)(&v136.writable.markCount + 5 * v113);
      do {
        v32 = *v30;
        if ((float)((float)((float)(v32 * v32) + (float)(v30[1] * v30[1])) +
                    (float)(v30[2] * v30[2])) != 0.0) {
          *v31 = v32;
          v33 = v30[1];
          v31[1] = v33;
          v34 = v30[2];
          v31[2] = v34;
          v31[3] =
              0.001 -
              (float)((float)((float)(v32 * *v29) + (float)(v33 * v29[1])) +
                      (float)(v34 * v29[2]));
          v35 = 12;
          if (*(int *)v31 <= 0)
            v35 = 0;
          *((_BYTE *)v31 + 16) = v35;
          v36 = 16;
          if (*((int *)v31 + 1) <= 0)
            v36 = 4;
          *((_BYTE *)v31 + 17) = v36;
          v37 = 20;
          if (*((int *)v31 + 2) <= 0)
            v37 = 8;
          *((_BYTE *)v31 + 18) = v37;
          *((_BYTE *)v31 + 19) = -1;
          ++v113;
          v31 += 5;
        }
        ++v118;
        v30 += 3;
        v29 += 3;
      } while (v14 != v118);
    }
    v38 = (float *)dword_C96E48;
    if (dword_C96E48) {
      v39 = (float *)(&v136.writable.markCount + 5 * v113);
      *v39 = *(float *)dword_C96E48;
      v39[1] = v38[1];
      v39[2] = v38[2];
      v39[3] = v38[3];
      v39[4] = v38[4];
      v40 = *v39;
      v41 = v39[1];
      v42 = v39[2];
      v43 = v39[3];
      v44 =
          (float)((float)((float)(*v39 * __src[0]) + (float)(v41 * __src[1])) +
                  (float)(v42 * __src[2])) +
          v43;
      v45 = (float)((float)((float)(*v39 * __src[3 * v14 - 3]) +
                            (float)(v41 * __src[3 * v14 - 2])) +
                    (float)(v42 * __src[3 * v14 - 1])) +
            v43;
      if (v45 <= v44) {
        v83 = v14 - 2;
        if (v14 - 2 <= 0 ||
            (v44 = (float)((float)(v42 * __src[3 * v83 + 2]) +
                           (float)((float)(v41 * __src[3 * v83 + 1]) +
                                   (float)(v40 * __src[3 * v83]))) +
                   v43,
             v44 > v45)) {
          v44 = (float)((float)((float)(*v39 * __src[3 * v14 - 3]) +
                                (float)(v39[1] * __src[3 * v14 - 2])) +
                        (float)(v39[2] * __src[3 * v14 - 1])) +
                v43;
        } else {
          v84 = 12 * v83 - 12;
          v85 = 0;
          while (v14 - 3 != v85) {
            v86 =
                (float)((float)(v42 * *(float *)((char *)&__src[2] + v84)) +
                        (float)((float)(v40 * *(float *)((char *)__src + v84)) +
                                (float)(v41 *
                                        *(float *)((char *)&__src[1] + v84)))) +
                v43;
            ++v85;
            v84 -= 12;
            if (v86 > v44)
              break;
            v44 = v86;
          }
        }
      } else if (v14 - 1 > 1 && (float)((float)((float)((float)(v41 * v133) +
                                                        (float)(v40 * v132)) +
                                                (float)(v42 * v134)) +
                                        v43) <= v44) {
        v44 = (float)((float)((float)(v41 * v133) + (float)(v40 * v132)) +
                      (float)(v42 * v134)) +
              v43;
        v46 = 1;
        v47 = __src;
        while (++v46 != v14 - 1) {
          v48 =
              (float)((float)(v42 * v47[8]) +
                      (float)((float)(v41 * v47[7]) + (float)(v40 * v47[6]))) +
              v43;
          v47 += 3;
          if (v48 > v44)
            break;
          v44 = v48;
        }
      }
      if (v44 > 0.0)
        v39[3] = v43 - v44;
      ++v113;
    }
    v49 = (float *)dword_C96E4C;
    if (dword_C96E4C) {
      v50 = 5 * v113;
      *(uint32_t *)((char *)&v136.writable.markCount + v50 * 4) =
          *(_DWORD *)dword_C96E4C;
      v136.mins[v50] = v49[1];
      v136.maxs[v50 - 2] = v49[2];
      v136.maxs[v50 - 1] = v49[3];
      v136.maxs[v50] = v49[4];
      v51 = (GfxPortal *)(v113 + 1);
    } else {
      v51 = (GfxPortal *)v113;
    }
    R_VisitPortalsForCell(*(_DWORD *)(v112 + 28), v112, (float *)(v112 + 8),
                          &v136, v51, (const DpvsPlane *)v115);
  } while (*(_DWORD *)stru_C96E68.side);
LABEL_129:
  LargeLocal::~LargeLocal(&v138);
}

void __cdecl R_AddWorldSurfacesPortalWalk(int, struct DpvsPlane const *const,
                                          int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddWorldSurfacesInFrustum(int, struct DpvsPlane const *const,
                                         int) {
  UNIMPLEMENTED();
}
