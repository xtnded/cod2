void __cdecl LL_REMOVE<struct static_model_node_list_t>(
    struct static_model_node_list_t *) {
  UNIMPLEMENTED();
}

void __cdecl LL_REMOVE<struct static_model_tree_list_t>(
    struct static_model_tree_list_t *) {
  UNIMPLEMENTED();
}

void __cdecl LL_ADD<struct static_model_node_list_t>(
    struct static_model_node_list_t *, struct static_model_node_list_t *) {
  UNIMPLEMENTED();
}

void __cdecl LL_ADD<struct static_model_tree_list_t>(
    struct static_model_tree_list_t *, struct static_model_tree_list_t *) {
  UNIMPLEMENTED();
}

void __cdecl R_StaticModelCacheStats_f() {
  int result; // eax

  ri(0, "%.2f%% of cache is currently allocated.\n",
     (float)((float)((float)dword_C949B0 * 100.0) * 0.000015258789));
  result = dword_C949B0;
  if (dword_C949B0)
    return ri(
        0, "%.2f%% allocated cache vertices are used.\n",
        (float)((float)((float)dword_C949B4 * 100.0) / (float)dword_C949B0));
  return result;
}

void __cdecl R_InitStaticModelIndexCache() {
  int result; // eax

  result = (*(int(__cdecl **)(int)) & algn_11806C8[4])(786432);
  unk_1180668 = result;
  return result;
}

void __cdecl R_UsedCachedStaticModelSurface(
    struct GfxStaticModelSurfaceCached *surf) {
  int *v1;      // ecx
  int *v2;      // ebx
  int **result; // eax

  v1 = &s_cache[98 * (((char *)a1 - (char *)s_cache) / 0x188u)];
  v1[2] = *(_DWORD *)frontEndDataOut;
  v2 = (int *)v1[1];
  *v2 = *v1;
  *(_DWORD *)(*v1 + 4) = v2;
  *v1 = (int)&dword_C949A8;
  v1[1] = dword_C949AC;
  dword_C949AC = (int)v1;
  result = (int **)v1[1];
  *result = v1;
  return result;
}

void __cdecl R_FlushStaticModelCache() {
  int v0;      // ebx
  int v1;      // esi
  _DWORD *v2;  // eax
  int v3;      // eax
  _DWORD *v4;  // ecx
  _DWORD *v5;  // ecx
  int v6;      // edx
  int v7;      // edi
  int v8;      // eax
  int v9;      // ecx
  int *v10;    // edx
  char *v11;   // eax
  int v12;     // ebx
  _DWORD *v13; // ecx

  v0 = dword_C949AC;
  if (dword_C949AC) {
    while ((int *)v0 != &dword_C949A8) {
      if (*(_WORD *)(v0 + 12)) {
        *(_WORD *)(v0 + 12) = 0;
        if (*(_BYTE *)(v0 + 14)) {
          v1 = v0 + 136;
          v5 = *(_DWORD **)(v0 + 148);
          if (*v5 == v0 + 136) {
            v7 = 0;
          LABEL_12:
            v5[v7] = 0;
          } else {
            v6 = *(_DWORD *)(v0 + 148);
            v7 = 0;
            while (++v7 != 4) {
              v8 = *(_DWORD *)(v6 + 4);
              v6 += 4;
              if (v1 == v8)
                goto LABEL_12;
            }
          }
          dword_C949B0 -= 512;
          dword_C949B4 -= *(__int16 *)(*(_DWORD *)(v0 + 144) + 2);
          *(_BYTE *)(v0 + 14) = 0;
        } else {
          SMC_FreeCachedSurface_r((int)s_cache, v0, 1,
                                  (static_model_cache_t *)3);
          SMC_FreeCachedSurface_r((int)s_cache, v0, 2,
                                  (static_model_cache_t *)3);
          v1 = v0 + 136;
        }
      } else {
        v1 = v0 + 136;
        v2 = *(_DWORD **)(v0 + 140);
        *v2 = *(_DWORD *)(v0 + 136);
        *(_DWORD *)(*(_DWORD *)(v0 + 136) + 4) = v2;
      }
      v3 = dword_C949AC;
      v4 = *(_DWORD **)(dword_C949AC + 4);
      *v4 = *(_DWORD *)dword_C949AC;
      *(_DWORD *)(*(_DWORD *)v3 + 4) = v4;
      *(_DWORD *)(v0 + 136) = &unk_C94980;
      *(_DWORD *)(v1 + 4) = dword_C94984[0];
      dword_C94984[0] = v1;
      **(_DWORD **)(v1 + 4) = v1;
      v0 = dword_C949AC;
    }
    memset(s_cache, 0, 0xC438u);
    dword_C949A8 = (int)&dword_C949A8;
    dword_C949AC = (int)&dword_C949A8;
    v9 = 0;
    v10 = s_cache;
    v11 = (char *)&unk_C94980;
    do {
      v10[12544] = (int)v11;
      v10[12545] = (int)v11;
      ++v9;
      v11 += 8;
      v10 += 2;
    } while (v9 != 5);
    v12 = 0;
    v13 = &unk_C88600;
    do {
      v13[2] = &unk_C94980;
      v13[3] = dword_C94984[0];
      dword_C94984[0] = (int)(v13 + 2);
      *(_DWORD *)v13[3] = v13 + 2;
      ++v12;
      v13 += 98;
    } while (v12 != 128);
  }
}

void __cdecl R_StaticModelCacheFlush_f() {
  int v0;      // ebx
  int v1;      // esi
  _DWORD *v2;  // eax
  int v3;      // eax
  _DWORD *v4;  // ecx
  _DWORD *v5;  // ecx
  int v6;      // edx
  int v7;      // edi
  int v8;      // eax
  int v9;      // ecx
  int *v10;    // edx
  char *v11;   // eax
  int v12;     // ebx
  _DWORD *v13; // ecx

  v0 = dword_C949AC;
  if (dword_C949AC) {
    while ((int *)v0 != &dword_C949A8) {
      if (*(_WORD *)(v0 + 12)) {
        *(_WORD *)(v0 + 12) = 0;
        if (*(_BYTE *)(v0 + 14)) {
          v1 = v0 + 136;
          v5 = *(_DWORD **)(v0 + 148);
          if (*v5 == v0 + 136) {
            v7 = 0;
          LABEL_12:
            v5[v7] = 0;
          } else {
            v6 = *(_DWORD *)(v0 + 148);
            v7 = 0;
            while (++v7 != 4) {
              v8 = *(_DWORD *)(v6 + 4);
              v6 += 4;
              if (v1 == v8)
                goto LABEL_12;
            }
          }
          dword_C949B0 -= 512;
          dword_C949B4 -= *(__int16 *)(*(_DWORD *)(v0 + 144) + 2);
          *(_BYTE *)(v0 + 14) = 0;
        } else {
          SMC_FreeCachedSurface_r((int)s_cache, v0, 1,
                                  (static_model_cache_t *)3);
          SMC_FreeCachedSurface_r((int)s_cache, v0, 2,
                                  (static_model_cache_t *)3);
          v1 = v0 + 136;
        }
      } else {
        v1 = v0 + 136;
        v2 = *(_DWORD **)(v0 + 140);
        *v2 = *(_DWORD *)(v0 + 136);
        *(_DWORD *)(*(_DWORD *)(v0 + 136) + 4) = v2;
      }
      v3 = dword_C949AC;
      v4 = *(_DWORD **)(dword_C949AC + 4);
      *v4 = *(_DWORD *)dword_C949AC;
      *(_DWORD *)(*(_DWORD *)v3 + 4) = v4;
      *(_DWORD *)(v0 + 136) = &unk_C94980;
      *(_DWORD *)(v1 + 4) = dword_C94984[0];
      dword_C94984[0] = v1;
      **(_DWORD **)(v1 + 4) = v1;
      v0 = dword_C949AC;
    }
    memset(s_cache, 0, 0xC438u);
    dword_C949A8 = (int)&dword_C949A8;
    dword_C949AC = (int)&dword_C949A8;
    v9 = 0;
    v10 = s_cache;
    v11 = (char *)&unk_C94980;
    do {
      v10[12544] = (int)v11;
      v10[12545] = (int)v11;
      ++v9;
      v11 += 8;
      v10 += 2;
    } while (v9 != 5);
    v12 = 0;
    v13 = &unk_C88600;
    do {
      v13[2] = &unk_C94980;
      v13[3] = dword_C94984[0];
      dword_C94984[0] = (int)(v13 + 2);
      *(_DWORD *)v13[3] = v13 + 2;
      ++v12;
      v13 += 98;
    } while (v12 != 128);
  }
}

struct GfxStaticModelSurfaceCached *__cdecl R_CacheStaticModelSurface(
    struct GfxStaticSurface *, struct XSurface_s const *, int) {
  signed __int16 vertCount; // ax
  int v6;                   // edi
  int v7;                   // ebx
  char *v8;                 // ecx
  _DWORD *v9;               // edx
  unsigned int v10;         // edx
  int *v11;                 // esi
  int v12;                  // eax
  int *v13;                 // ebx
  int v14;                  // ecx
  int v15;                  // edi
  _DWORD *v16;              // esi
  _DWORD *v17;              // ebx
  int v18;                  // ecx
  int v19;                  // edx
  int v20;                  // [esp+8h] [ebp-50h]
  int v21;                  // [esp+1Ch] [ebp-3Ch]
  int v22;                  // [esp+24h] [ebp-34h]
  int *v23;                 // [esp+28h] [ebp-30h]
  unsigned int v24;         // [esp+2Ch] [ebp-2Ch]
  _DWORD v25[9];            // [esp+34h] [ebp-24h] BYREF

  if (byte_11805DC)
    return 0;
  vertCount = a2->vertCount;
  if (vertCount > 512)
    return 0;
  if (vertCount > 32) {
    v6 = 5;
    do
      v22 = 1 << ++v6;
    while (vertCount > 1 << v6);
    v7 = 9 - v6;
  } else {
    LOBYTE(v6) = 5;
    v22 = 32;
    v7 = 4;
  }
  if ((_UNKNOWN *)dword_C94984[2 * v7] ==
          (_UNKNOWN *)((char *)&unk_C94980 + 8 * v7) &&
      !(unsigned __int8)SMC_GetFreeBlockOfSize((int)s_cache, v7)) {
    return 0;
  }
  v8 = (char *)dword_C94984[2 * v7];
  v9 = (_DWORD *)*((_DWORD *)v8 + 1);
  *v9 = *(_DWORD *)v8;
  *(_DWORD *)(*(_DWORD *)v8 + 4) = v9;
  v10 = (v8 - (char *)s_cache) / 0x188u;
  v11 = &s_cache[98 * v10];
  if (!v7) {
    s_cache[98 * v10] = (int)&dword_C949A8;
    v11[1] = dword_C949AC;
    dword_C949AC = (int)&s_cache[98 * v10];
    *(_DWORD *)v11[1] = v11;
  }
  v24 = (unsigned int)(v8 - (char *)(v11 + 34)) >> 4;
  v21 = ((int)(v24 + 16) >> (4 - v7)) - 1;
  BYTE2(v11[v21 + 3]) = 1;
  if (v21 >= 0) {
    v12 = ((int)(v24 + 16) >> (4 - v7)) - 1;
    do {
      LOWORD(v11[v12 + 3]) += 1 << v6;
      v12 = (v21 - 1) >> 1;
      v21 = v12;
    } while (v12 >= 0);
  }
  v13 = &v11[4 * v24 + 32];
  v23 = &v11[4 * v24 + 34];
  v13[2] = 32 * (v24 + 16 * v10);
  dword_C949B0 += v22;
  dword_C949B4 += (__int16)a2->vertCount;
  v13[5] = (int)a1;
  v13[4] = (int)a2;
  v13[3] = a3;
  v25[0] = v23;
  v25[1] = a3;
  v25[2] = a4;
  R_AddFrontendCmd(5, v25, v20);
  v14 = v11[4 * v24 + 36];
  v15 = *v23 | (*v23 << 16);
  v16 = *(_DWORD **)(v14 + 8);
  v17 = (_DWORD *)(unk_1180668 + 12 * *v23);
  v18 = *(__int16 *)(v14 + 4) / 2;
  v19 = 0;
  do {
    *v17 = *v16 + v15;
    v17[1] = v16[1] + v15;
    v17[2] = v16[2] + v15;
    v17 += 3;
    v16 += 3;
    ++v19;
  } while (v18 != v19);
  return v23;
}

void __cdecl R_SkinStaticModelCachedCmd(
    struct SkinStaticModelCachedCmd *skinCmd, struct SkinBuffers *skinBuffers) {
  int v2;                         // ebx
  int(__cdecl * v3)(_DWORD, int); // esi
  int BoneOffset;                 // eax
  int v5;                         // eax
  float v6;                       // xmm3_4
  float v7;                       // xmm6_4
  float v8;                       // xmm1_4
  float v9;                       // xmm4_4
  float v10;                      // xmm5_4
  float v11;                      // xmm2_4
  float v12;                      // xmm7_4
  float v13;                      // xmm0_4
  float v14;                      // xmm3_4
  float v15;                      // xmm4_4
  float v16;                      // xmm6_4
  float v17;                      // xmm2_4
  int v18;                        // ecx
  int32_t verts;                  // edi
  float *v20;                     // ebx
  int v21;                        // edi
  int *result;                    // eax
  _DWORD *v23;                    // esi
  uint8_t *v24;                   // ebx
  int v25;                        // edx
  int v26;                        // ecx
  int v27;                        // edx
  int v28;                        // ecx
  int v29;                        // edx
  int v30;                        // edx
  int v31;                        // ecx
  int v32;                        // edx
  int v33;                        // ecx
  float *i;                       // ebx
  uint8_t v35;                    // bl
  uint8_t v36;                    // si
  $_3714 *v37;                    // esi
  _DWORD *v38;                    // ebx
  uint8_t *v39;                   // esi
  float *v40;                     // ebx
  float v41;                      // xmm3_4
  float v42;                      // xmm5_4
  float v43;                      // xmm4_4
  int v44;                        // edx
  uint8_t v45;                    // al
  int v46;                        // edx
  uint8_t v47;                    // al
  int v48;                        // edx
  uint8_t v49;                    // al
  int v50;                        // edx
  uint8_t v51;                    // al
  int v52;                        // edx
  float *v53;                     // eax
  float j;                        // xmm1_4
  float v55;                      // xmm1_4
  unsigned int k;                 // edi
  int v57;                        // edx
  int v58;                        // ecx
  int v59;                        // edx
  uint8_t v60;                    // [esp+2Fh] [ebp-4C9h]
  float v61;                      // [esp+40h] [ebp-4B8h]
  float v62;                      // [esp+5Ch] [ebp-49Ch]
  float v63;                      // [esp+60h] [ebp-498h]
  float v64;                      // [esp+64h] [ebp-494h]
  float v65;                      // [esp+68h] [ebp-490h]
  float v66;                      // [esp+6Ch] [ebp-48Ch]
  float v67;                      // [esp+70h] [ebp-488h]
  signed __int16 vertCount;       // [esp+76h] [ebp-482h]
  const XSurface_s *v69;          // [esp+78h] [ebp-480h]
  Format *cached;                 // [esp+7Ch] [ebp-47Ch]
  float v71;                      // [esp+80h] [ebp-478h]
  float v72;                      // [esp+84h] [ebp-474h]
  int v73;                        // [esp+8Ch] [ebp-46Ch]
  int *v74;                       // [esp+90h] [ebp-468h]
  int v75;                        // [esp+94h] [ebp-464h]
  Format v76;                     // [esp+A4h] [ebp-454h]
  int v77;                        // [esp+A8h] [ebp-450h]
  $_3714 *v78;                    // [esp+ACh] [ebp-44Ch]
  int *ColorConverter;            // [esp+B0h] [ebp-448h]
  unsigned int v80;               // [esp+B4h] [ebp-444h]
  float v81;                      // [esp+B8h] [ebp-440h]
  float v82;                      // [esp+BCh] [ebp-43Ch]
  $_3714 *p_verts;                // [esp+ECh] [ebp-40Ch]
  char __b[36];                   // [esp+F0h] [ebp-408h] BYREF
  char v85;                       // [esp+114h] [ebp-3E4h] BYREF
  DObjSkelMat_s v86;              // [esp+430h] [ebp-C8h] BYREF
  float v87[3];                   // [esp+47Ch] [ebp-7Ch] BYREF
  float v88;                      // [esp+488h] [ebp-70h] BYREF
  float v89;                      // [esp+48Ch] [ebp-6Ch]
  float v90;                      // [esp+490h] [ebp-68h]
  float v91;                      // [esp+494h] [ebp-64h] BYREF
  float v92;                      // [esp+498h] [ebp-60h]
  float v93;                      // [esp+49Ch] [ebp-5Ch]
  float v94;                      // [esp+4A0h] [ebp-58h]
  float v95;                      // [esp+4A4h] [ebp-54h]
  float v96;                      // [esp+4A8h] [ebp-50h]
  float v97[3];                   // [esp+4ACh] [ebp-4Ch] BYREF
  float v98[3];                   // [esp+4B8h] [ebp-40h] BYREF
  float v99[3];                   // [esp+4C4h] [ebp-34h] BYREF
  float v100[3];                  // [esp+4D0h] [ebp-28h] BYREF
  _DWORD v101[7];                 // [esp+4DCh] [ebp-1Ch] BYREF

  cached = (Format *)a1->cached;
  v69 = *(const XSurface_s **)(a1->cached + 8);
  v2 = *(_DWORD *)(dword_1184B9C + 248) + 96 * *(_DWORD *)a1->smodelIndex;
  v3 = (int(__cdecl *)(_DWORD, int))unk_1180864;
  BoneOffset = XSurfaceGetBoneOffset(v69);
  v5 = v3(*(_DWORD *)(v2 + 16), BoneOffset);
  v6 = *(float *)(v5 + 28) * *(float *)v5;
  v7 = *(float *)(v5 + 28) * *(float *)(v5 + 4);
  v8 = *(float *)(v5 + 28) * *(float *)(v5 + 8);
  v71 = v6 * *(float *)v5;
  v9 = *(float *)(v5 + 4);
  v10 = v6 * v9;
  v11 = *(float *)(v5 + 8);
  v12 = v6 * v11;
  v13 = *(float *)(v5 + 12);
  v14 = v6 * v13;
  v72 = v9 * v7;
  v15 = v7 * v11;
  v16 = v7 * v13;
  v17 = v11 * v8;
  v86.axis[0][0] = 1.0 - (float)(v72 + v17);
  v86.axis[0][1] = (float)(v8 * v13) + v10;
  v86.axis[0][2] = v12 - v16;
  v86.axis[1][0] = 0.0;
  v86.axis[1][1] = v10 - (float)(v8 * v13);
  v86.axis[1][2] = 1.0 - (float)(v17 + v71);
  v86.axis[2][0] = v14 + v15;
  v86.axis[2][1] = 0.0;
  v86.axis[2][2] = v12 + v16;
  v86.axis[3][0] = v15 - v14;
  v86.axis[3][1] = 1.0 - (float)(v71 + v72);
  v86.axis[3][2] = 0.0;
  *(_DWORD *)v86.origin = *(_DWORD *)(v5 + 16);
  *(_DWORD *)&v86.origin[4] = *(_DWORD *)(v5 + 20);
  *(_DWORD *)&v86.origin[8] = *(_DWORD *)(v5 + 24);
  *(_DWORD *)&v86.origin[12] = 1065353216;
  R_GetRigidTransform(&v86, (const float *)(v2 + 4),
                      (const float(*)[3])(v2 + 44), *(float *)(v2 + 80),
                      (float(*)[3])v87);
  Vec3NormalizeTo(v87, v97);
  Vec3NormalizeTo(&v88, v98);
  Vec3NormalizeTo(&v91, v99);
  v18 = *(_DWORD *)a1->smodelIndex;
  vertCount = v69->vertCount;
  v76 = *cached;
  verts = v69->verts;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2) {
    v20 = (float *)(*(_DWORD *)(dword_1184B9C + 248) + 96 * v18 + 84);
    v63 = floorf((float)(*v20 * 32768.0) + 0.5);
    v62 = floorf((float)(32768.0 * v20[1]) + 0.5);
    if (vertCount > 0) {
      p_verts = &a2->verts;
      v77 = 0;
      for (i = (float *)a2->verts.dx7;; i = (float *)p_verts) {
        *i = (float)((float)((float)(*(float *)(verts + 48) * v87[0]) +
                             (float)(*(float *)(verts + 52) * v88)) +
                     (float)(*(float *)(verts + 56) * v91)) +
             v94;
        i[1] = (float)((float)((float)(*(float *)(verts + 48) * v87[1]) +
                               (float)(*(float *)(verts + 52) * v89)) +
                       (float)(*(float *)(verts + 56) * v92)) +
               v95;
        i[2] = (float)((float)((float)(*(float *)(verts + 48) * v87[2]) +
                               (float)(*(float *)(verts + 52) * v90)) +
                       (float)(*(float *)(verts + 56) * v93)) +
               v96;
        AxisTransformVector(v97, *(float *)verts, *(float *)(verts + 4),
                            *(float *)(verts + 8), i + 3);
        v60 = *(_BYTE *)(verts + 12);
        v35 = *(_BYTE *)(verts + 13);
        v36 = *(_BYTE *)(verts + 14);
        p_verts->dx7[24] = *(_BYTE *)(verts + 15);
        p_verts->dx7[25] = v60;
        p_verts->dx7[26] = v35;
        p_verts->dx7[27] = v36;
        *(_DWORD *)&p_verts->dx9[28] = *(_DWORD *)(verts + 28);
        *(_DWORD *)&p_verts->dx9[32] = *(_DWORD *)(verts + 44);
        *(_WORD *)&p_verts->dx9[36] = (int)v63;
        *(_WORD *)&p_verts->dx9[38] = (int)v62;
        AxisTransformVector(v97, *(float *)(verts + 16), *(float *)(verts + 20),
                            *(float *)(verts + 24), (float *)&p_verts->dx9[40]);
        AxisTransformVector(v97, *(float *)(verts + 32), *(float *)(verts + 36),
                            *(float *)(verts + 40), (float *)&p_verts->dx9[52]);
        ++v77;
        verts += 64;
        p_verts = ($_3714 *)((char *)p_verts + 64);
        if (vertCount == v77)
          break;
      }
    }
    if ((*(int(__cdecl **)(_DWORD *, Format, int, _DWORD *, int))(
            *dword_1180664 + 44))(dword_1180664, v76 << 6, vertCount << 6, v101,
                                  4097) < 0)
      R_FatalLockError();
    v78 = &a2->verts;
    v21 = v101[0];
    ColorConverter = CColorConverter::GetColorConverter(0);
    if (!vertCount)
      goto LABEL_58;
    v80 = 0;
    v23 = (_DWORD *)(v21 + 52);
    v24 = &a2->verts.dx7[52];
    do {
      v25 = *((_DWORD *)v24 - 12);
      v26 = *((_DWORD *)v24 - 11);
      *(v23 - 13) = *((_DWORD *)v24 - 13);
      *(v23 - 12) = v25;
      *(v23 - 11) = v26;
      v27 = *((_DWORD *)v24 - 9);
      v28 = *((_DWORD *)v24 - 8);
      *(v23 - 10) = *((_DWORD *)v24 - 10);
      *(v23 - 9) = v27;
      *(v23 - 8) = v28;
      (*(void(__cdecl **)(int *, int, uint8_t *)) *
       ColorConverter)(ColorConverter, v21 + 24, &v78->dx7[24]);
      v29 = *((_DWORD *)v24 - 5);
      *(v23 - 6) = *((_DWORD *)v24 - 6);
      *(v23 - 5) = v29;
      *((_WORD *)v23 - 8) = *((_WORD *)v24 - 8);
      *((_WORD *)v23 - 7) = *((_WORD *)v24 - 7);
      v30 = *((_DWORD *)v24 - 2);
      v31 = *((_DWORD *)v24 - 1);
      *(v23 - 3) = *((_DWORD *)v24 - 3);
      *(v23 - 2) = v30;
      *(v23 - 1) = v31;
      v32 = *((_DWORD *)v24 + 1);
      v33 = *((_DWORD *)v24 + 2);
      *v23 = *(_DWORD *)v24;
      v23[1] = v32;
      v23[2] = v33;
      ++v80;
      v78 = ($_3714 *)((char *)v78 + 64);
      v24 += 64;
      v21 += 64;
      v23 += 16;
    } while (v80 < vertCount);
    (*(void(__cdecl **)(_DWORD *))(*dword_1180664 + 48))(dword_1180664);
    result = (int *)alwaysfails;
    if (alwaysfails) {
    LABEL_58:
      do {
        (*(void(__cdecl **)(_DWORD *))(*dword_1180664 + 48))(dword_1180664);
        result = (int *)alwaysfails;
      } while (alwaysfails);
    }
    return result;
  }
  v75 = RB_DeriveEntityLights(
      (float *)(*(_DWORD *)(dword_1184B9C + 300) + 96 * v18),
      *(_DWORD *)(*(_DWORD *)(dword_1184B9C + 304) + 4 * v18), a1->material,
      __b, 8);
  if (vertCount > 0) {
    v73 = 0;
    v39 = &a2->verts.dx7[12];
    v40 = (float *)(verts + 12);
    while (1) {
      *((float *)v39 - 3) =
          (float)((float)((float)(v40[9] * v87[0]) + (float)(v40[10] * v88)) +
                  (float)(v40[11] * v91)) +
          v94;
      *((float *)v39 - 2) =
          (float)((float)((float)(v40[9] * v87[1]) + (float)(v40[10] * v89)) +
                  (float)(v40[11] * v92)) +
          v95;
      *((float *)v39 - 1) =
          (float)((float)((float)(v40[9] * v87[2]) + (float)(v40[10] * v90)) +
                  (float)(v40[11] * v93)) +
          v96;
      *((float *)v39 + 1) = v40[4];
      *((float *)v39 + 2) = v40[8];
      AxisTransformVector(v97, *(v40 - 3), *(v40 - 2), *(v40 - 1), v100);
      if (v75 > 0) {
        v52 = 0;
        v41 = 0.0;
        v42 = 0.0;
        v43 = 0.0;
        v53 = (float *)&v85;
        for (j = v100[0];; j = v100[0]) {
          v43 = v43 + *v53;
          v42 = v42 + v53[1];
          v41 = v41 + v53[2];
          v55 = -(
              float)((float)((float)(j * v53[7]) + (float)(v100[1] * v53[8])) +
                     (float)(v100[2] * v53[9]));
          if (v55 > 0.0) {
            v43 = v43 + (float)(v55 * *(v53 - 8));
            v42 = v42 + (float)(v55 * *(v53 - 7));
            v41 = v41 + (float)(v55 * *(v53 - 6));
          }
          ++v52;
          v53 += 26;
          if (v75 == v52)
            break;
        }
      } else {
        v41 = 0.0;
        v42 = 0.0;
        v43 = 0.0;
      }
      v82 = 0.0039215689 * (float)(v42 * (float)*((unsigned __int8 *)v40 + 1));
      v81 = 0.0039215689 * (float)(v41 * (float)*(unsigned __int8 *)v40);
      v61 = (float)((float)*((unsigned __int8 *)v40 + 2) * v43) * 0.0039215689;
      v67 = floorf(
          (float)((float)((float)*((unsigned __int8 *)v40 + 3) * 0.0039215689) *
                  255.0) +
          0.5);
      v44 = (int)v67;
      if ((int)v67 - 255 >= 0)
        break;
      if (v44 > 0)
        goto LABEL_27;
      v45 = 0;
    LABEL_28:
      *v39 = v45;
      v66 = floorf((float)(v61 * 255.0) + 0.5);
      v46 = (int)v66;
      if ((int)v66 - 255 >= 0) {
        LOBYTE(v46) = -1;
      LABEL_30:
        v47 = v46;
        goto LABEL_31;
      }
      if (v46 > 0)
        goto LABEL_30;
      v47 = 0;
    LABEL_31:
      v39[1] = v47;
      v65 = floorf((float)(v82 * 255.0) + 0.5);
      v48 = (int)v65;
      if ((int)v65 - 255 >= 0) {
        LOBYTE(v48) = -1;
      LABEL_33:
        v49 = v48;
        goto LABEL_34;
      }
      if (v48 > 0)
        goto LABEL_33;
      v49 = 0;
    LABEL_34:
      v39[2] = v49;
      v64 = floorf((float)(v81 * 255.0) + 0.5);
      v50 = (int)v64;
      if ((int)v64 - 255 < 0) {
        if (v50 <= 0) {
          v51 = 0;
          goto LABEL_37;
        }
      } else {
        LOBYTE(v50) = -1;
      }
      v51 = v50;
    LABEL_37:
      v39[3] = v51;
      ++v73;
      v40 += 16;
      v39 += 24;
      if (vertCount == v73)
        goto LABEL_17;
    }
    LOBYTE(v44) = -1;
  LABEL_27:
    v45 = v44;
    goto LABEL_28;
  }
LABEL_17:
  if ((*(int(__cdecl **)(_DWORD *, __int32, int, _DWORD *, int))(
          *dword_1180664 + 44))(dword_1180664, 24 * v76, 24 * vertCount, v101,
                                4097) < 0)
    R_FatalLockError();
  v37 = &a2->verts;
  v38 = (_DWORD *)v101[0];
  v74 = CColorConverter::GetColorConverter(0);
  if (vertCount) {
    for (k = 0; k < vertCount; ++k) {
      v57 = *(_DWORD *)&v37->dx9[4];
      v58 = *(_DWORD *)&v37->dx9[8];
      *v38 = *(_DWORD *)v37->dx7;
      v38[1] = v57;
      v38[2] = v58;
      (*(void(__cdecl **)(int *, _DWORD *, uint8_t *)) * v74)(v74, v38 + 3,
                                                              &v37->dx7[12]);
      v59 = *(_DWORD *)&v37->dx9[20];
      v38[4] = *(_DWORD *)&v37->dx9[16];
      v38[5] = v59;
      v37 = ($_3714 *)((char *)v37 + 24);
      v38 += 6;
    }
  }
  do {
    (*(void(__cdecl **)(_DWORD *))(*dword_1180664 + 48))(dword_1180664);
    result = &alwaysfails;
  } while (alwaysfails);
  return result;
}

void __cdecl R_InitStaticModelCache() { UNIMPLEMENTED(); }

int marker_r_staticmodelcache;
void __cdecl SMC_ClearCache(void) { UNIMPLEMENTED(); }

void __cdecl R_CacheStaticModelIndices(
    struct GfxStaticModelSurfaceCached const *) {
  UNIMPLEMENTED();
}

void __cdecl SMC_FreeCachedSurface_r(struct static_model_cache_t *,
                                     struct static_model_tree_t *, int, int) {
  UNIMPLEMENTED();
}

bool __cdecl SMC_ForceFreeBlock(struct static_model_cache_t *) {
  UNIMPLEMENTED();
}

bool __cdecl SMC_GetFreeBlockOfSize(struct static_model_cache_t *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_SkinXSurfaceStaticVerts(float const (*const)[3],
                                       float const (*const)[3], int,
                                       struct GfxVertex const *, int,
                                       struct GfxSModelCachedVertex *) {
  UNIMPLEMENTED();
}

struct GfxStaticModelSurfaceCached *__cdecl SMC_Allocate(
    struct static_model_cache_t *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AllocStaticModelCache(void) { UNIMPLEMENTED(); }

R_ShutdownStaticModelCache() { UNIMPLEMENTED(); }
