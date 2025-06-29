void __cdecl Byte4UnpackRgba(unsigned char const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl Byte4UnpackNativeColor(unsigned char const *const, float *const) {
  UNIMPLEMENTED();
}

int __cdecl R_DecomposeSortEntityIndex(unsigned int) { UNIMPLEMENTED(); }

struct Material const *__cdecl R_DecomposeSortMaterial(unsigned int) {
  UNIMPLEMENTED();
}

bool __cdecl R_UsingAntialiasing(void) { UNIMPLEMENTED(); }

enum ShadowType __cdecl R_DynamicShadowType(
    struct GfxPostProcessParms const *) {
  UNIMPLEMENTED();
}

void __cdecl R_AddLightmappedDrawSurf(enum surfaceType_t const *, int,
                                      struct Material const *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_SetupViewProjectionMatrices(struct GfxViewParms *) {
  UNIMPLEMENTED();
}

void __cdecl R_DefaultVertexFrames(int vertCount,
                                   struct GfxWorldVertex *const verts) {
  int i; // ecx

  if (a1 > 0) {
    for (i = 0; i != a1; ++i) {
      a2->normal[0] = 0.0;
      a2->normal[1] = 0.0;
      a2->normal[2] = 1.0;
      a2->binormal[0] = 0.0;
      a2->binormal[1] = 1.0;
      a2->binormal[2] = 0.0;
      a2->tangent[0] = 1.0;
      a2->tangent[1] = 0.0;
      a2->tangent[2] = 0.0;
      ++a2;
    }
  }
}

void __cdecl R_InitSceneEntity(struct GfxSceneEntity *) { UNIMPLEMENTED(); }

void __cdecl R_GetClearColor(float *const) { UNIMPLEMENTED(); }

void __cdecl R_AddDrawSurfForSurface(struct GfxSurface *surf, int entIndex) {
  int lightmapIndex; // ebx
  int32_t material;  // edi
  int result;        // eax
  int *v5;           // esi
  int v6;            // eax
  _DWORD *main;      // [esp+0h] [ebp-10h]

  lightmapIndex = a1->lightmapIndex;
  material = a1->material;
  main = (_DWORD *)a1->unnamed_field.main;
  result = *((_DWORD *)frontEndDataOut + 1);
  if (result <= 0xFFFF) {
    v5 = (int *)((char *)frontEndDataOut + 8 * result + 8);
    if (*main == 2 && *(_BYTE *)(fx_sort + 8))
      v6 = 16 * lightmapIndex + (a2 << 19) +
           (*(unsigned __int16 *)(material + 10) << 9) - 2147483646;
    else
      v6 = (*(unsigned __int16 *)(material + 10) << 21) + 16 * a2 + *main +
           (lightmapIndex << 16);
    *v5 = v6;
    v5[1] = (int)main;
    ++dword_11555B8;
    result = (int)frontEndDataOut;
    ++*((_DWORD *)frontEndDataOut + 1);
  }
  return result;
}

void __cdecl R_AddDrawSurf(enum surfaceType_t const *, int,
                           struct Material const *) {
  UNIMPLEMENTED();
}

void __cdecl R_DecomposeSort(unsigned int, int *, struct Material const **,
                             int *) {
  unsigned int v4;         // edx
  const Material **result; // eax
  unsigned int v6;         // edx

  if ((a1 & 0x80000000) != 0) {
    v6 = (a1 >> 19) & 0xFFF;
    if (v6 >= 0x800)
      v6 = 2046;
    *a2 = v6;
    result = a3;
    *a3 = (const Material *)rgp[((a1 >> 9) & 0x3FF) + 2];
    *a4 = (a1 >> 4) & 0x1F;
  } else {
    v4 = (unsigned __int16)a1 >> 4;
    if (v4 >= 0x800)
      v4 = 2046;
    *a2 = v4;
    result = a3;
    *a3 = (const Material *)rgp[((a1 >> 21) & 0x3FF) + 2];
    *a4 = HIWORD(a1) & 0x1F;
  }
  return result;
}

void __cdecl R_AddLightToScene(float const *const org, float radius, float r,
                               float g, float b) {
  char *result; // eax
  int32_t *v6;  // eax
  float *v7;    // ecx
  int32_t *v8;  // ebx

  result = rg;
  if (rg[0] && dword_1184B9C && a2 > 0.0) {
    result = (char *)r_dlightLimit;
    if (dword_1155014 < *(_DWORD *)(r_dlightLimit + 8)) {
      v6 = &stru_1155004.entities + 11 * dword_1155014;
      v7 = (float *)(v6 + 2);
      ++dword_1155014;
      v6[2] = rgp[1034];
      v8 = v6 + 3;
      v6[3] = *(_DWORD *)a1;
      v6[4] = *((_DWORD *)a1 + 1);
      result = (char *)*((_DWORD *)a1 + 2);
      v8[2] = (int32_t)result;
      v7[4] = a2;
      v7[5] = a3;
      v7[6] = a4;
      v7[7] = a5;
    }
  }
  return result;
}

void __cdecl R_AddPolyToScene(struct Material *materialHandle,
                              unsigned short lmapIndex,
                              unsigned short vertCount,
                              struct GfxWorldVertex const *const verts) {
  Material *v4; // edi
  int result;   // eax
  char *v6;     // ecx
  int v7;       // ecx
  int v8;       // eax
  int *v9;      // esi
  int v10;      // edx
  int v11;      // eax
  char *v12;    // [esp+10h] [ebp-28h]
  char *v13;    // [esp+1Ch] [ebp-1Ch]

  v4 = a1;
  result = (int)rg;
  if (rg[0]) {
    if (!a1)
      v4 = (Material *)rgp[1035];
    result = *((_DWORD *)frontEndDataOut + 409373) + a3;
    if (result <= 0x2000) {
      result = *((_DWORD *)frontEndDataOut + 401180);
      if (result <= 2047) {
        v12 = (char *)frontEndDataOut + 16 * result + 1604720;
        v13 = (char *)frontEndDataOut + 16 * result + 1604724;
        *(_DWORD *)v13 = 1;
        *((_DWORD *)v13 + 1) = v4;
        *((_WORD *)v13 + 4) = a2;
        *((_WORD *)v13 + 5) = a3;
        v6 = (char *)frontEndDataOut +
             68 * *((_DWORD *)frontEndDataOut + 409373) + 1637496;
        *((_DWORD *)v13 + 3) = v6;
        memcpy(v6, __src, 68 * a3);
        v7 = dword_11555C0 % 2048 + 2048;
        v8 = *((_DWORD *)frontEndDataOut + 1);
        if (v8 <= 0xFFFF) {
          v9 = (int *)((char *)frontEndDataOut + 8 * v8 + 8);
          v10 = *((_DWORD *)v12 + 1);
          if (v10 == 2 && *(_BYTE *)(fx_sort + 8))
            v11 =
                16 * a2 + (v7 << 19) + (v4->info.sortedIndex << 9) - 2147483646;
          else
            v11 = (v4->info.sortedIndex << 21) + 16 * v7 + v10 + (a2 << 16);
          *v9 = v11;
          v9[1] = (int)v13;
          ++dword_11555B8;
          ++*((_DWORD *)frontEndDataOut + 1);
        }
        ++*((_DWORD *)frontEndDataOut + 401180);
        result = (int)frontEndDataOut;
        *((_DWORD *)frontEndDataOut + 409373) += a3;
        ++dword_11555C0;
      }
    }
  }
  return result;
}

int __cdecl R_AddStaticModelToScene(int smodelIndex) {
  signed int entityCount; // esi
  unsigned int v2;        // eax
  _DWORD *v3;             // ebx
  int *v4;                // edx
  _DWORD *v6;             // [esp+2Ch] [ebp-1Ch]

  if (!*(_BYTE *)(r_drawEntities + 8))
    return -1;
  entityCount = stru_1155004.entityCount;
  if (stru_1155004.entityCount > 0x7FD) {
    if (*(_DWORD *)frontEndDataOut != R_AllocSceneEntity(void)::warnCount) {
      R_AllocSceneEntity(void)::warnCount = *(_DWORD *)frontEndDataOut;
      ri(2, "too many scene entities (more than %i)\n", 2046);
    }
    return -1;
  }
  v2 = *((_DWORD *)frontEndDataOut + 163843);
  if (v2 > 0x1FF7) {
    if (*(_DWORD *)frontEndDataOut != R_AllocSceneEntity(void)::warnCount) {
      R_AllocSceneEntity(void)::warnCount = *(_DWORD *)frontEndDataOut;
      ri(2, (const char *)&stru_222D8C.mArgv, 8184);
    }
    return -1;
  }
  *((_DWORD *)frontEndDataOut + 163843) = v2 + 1;
  ++stru_1155004.entityCount;
  if (entityCount < 0)
    return -1;
  v3 = (_DWORD *)(stru_1155004.entities + 116 * entityCount);
  v6 = (_DWORD *)(96 * a1 + *(_DWORD *)(dword_1184B9C + 248));
  memset(v3, 0, 0x74u);
  *v3 = 2;
  v3[15] = v6[1];
  v3[16] = v6[2];
  v3[17] = v6[3];
  AxisCopy(v6 + 11, v3 + 5);
  v3[14] = v6[20];
  if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
    v3[2] = *(_DWORD *)(dword_1184B9C + 300) + 96 * a1;
    v3[3] = *(_DWORD *)(*(_DWORD *)(dword_1184B9C + 304) + 4 * a1);
  } else {
    v3[2] = v6[21];
    v3[3] = v6[22];
    v3[4] = v6[23];
  }
  v4 = &dword_11555C0[13 * entityCount];
  memset(v4 + 1, 0, 0x34u);
  v4[4] = 2;
  v4[2] = v6[4];
  v4[6] = v6[5];
  v4[7] = v6[6];
  v4[8] = v6[7];
  v4[9] = v6[8];
  v4[10] = v6[9];
  v4[11] = v6[10];
  return entityCount;
}

void __cdecl R_AddBModelSurfaces(struct GfxSceneEntity *sceneEnt,
                                 int entIndex) {
  int result;   // eax
  int v3;       // ebx
  int v4;       // eax
  int v5;       // eax
  int v6;       // ecx
  int v7;       // esi
  _DWORD *v8;   // edi
  int v9;       // eax
  GfxModel v10; // [esp+8h] [ebp-1Ch]
  int v11;      // [esp+Ch] [ebp-18h]
  int *v12;     // [esp+10h] [ebp-14h]

  a1->cullState = 5;
  result = r_drawBModels;
  if (*(_BYTE *)(r_drawBModels + 8)) {
    v10.obj = (int32_t)a1->u;
    result = *(_DWORD *)(v10.obj + 28);
    if (*(int *)(v10.obj + 24) > 0) {
      v3 = 12 * result;
      v11 = 0;
      do {
        v5 = v3 + *(_DWORD *)(dword_1184B9C + 20);
        v6 = *(unsigned __int16 *)(v5 + 4);
        v7 = *(_DWORD *)v5;
        v8 = *(_DWORD **)(v5 + 8);
        v9 = *((_DWORD *)frontEndDataOut + 1);
        if (v9 <= 0xFFFF) {
          v12 = (int *)((char *)frontEndDataOut + 8 * v9 + 8);
          if (*v8 == 2 && *(_BYTE *)(fx_sort + 8))
            v4 = 16 * v6 + (a2 << 19) - 2147483646 +
                 (*(unsigned __int16 *)(v7 + 10) << 9);
          else
            v4 = (*(unsigned __int16 *)(v7 + 10) << 21) + 16 * a2 + *v8 +
                 (v6 << 16);
          *v12 = v4;
          v12[1] = (int)v8;
          ++dword_11555B8;
          ++*((_DWORD *)frontEndDataOut + 1);
        }
        ++v11;
        v3 += 12;
        result = v10.obj;
      } while (*(_DWORD *)(v10.obj + 24) > v11);
    }
  }
  return result;
}

void __cdecl qsortDrawSurfs(struct GfxDrawSurf *drawSurfs, int drawSurfCount) {
  signed int result; // eax
  GfxDrawSurf *v3;   // eax
  GfxDrawSurf *v4;   // edi
  GfxDrawSurf *i;    // eax
  GfxDrawSurf *v6;   // esi
  int32_t sort;      // ecx
  int32_t surface;   // ebx
  int32_t v9;        // edx
  GfxDrawSurf *v10;  // edx
  GfxDrawSurf *v11;  // esi
  int32_t v12;       // ecx
  int32_t v13;       // ebx
  int32_t v14;       // edx
  GfxDrawSurf *v15;  // esi
  GfxDrawSurf *v16;  // edx
  unsigned int v17;  // eax
  int32_t v18;       // edx
  int32_t v19;       // ecx
  int32_t v20;       // ebx
  int32_t v21;       // edx
  GfxDrawSurf *v22;  // esi
  int32_t v23;       // [esp+8h] [ebp-140h]
  int32_t v24;       // [esp+Ch] [ebp-13Ch]
  GfxDrawSurf *v25;  // [esp+28h] [ebp-120h]
  GfxDrawSurf *v26;  // [esp+2Ch] [ebp-11Ch]
  GfxDrawSurf *v27;  // [esp+30h] [ebp-118h]
  int v28;           // [esp+34h] [ebp-114h]
  GfxDrawSurf *v29;  // [esp+38h] [ebp-110h]
  _DWORD v30[66];    // [esp+40h] [ebp-108h]

  result = a2;
  if (a2 > 1) {
    v3 = &a1[a2 - 1];
    v25 = v3;
    v4 = a1;
    v28 = 0;
  LABEL_3:
    result = ((unsigned int)(v3 - v4) >> 3) + 1;
    if (result <= 8) {
    LABEL_4:
      if (v4 < v25) {
        for (i = v4 + 1;; i = v4 + 1) {
          if (v25 < i) {
            v6 = v4;
          } else {
            v10 = i;
            v6 = v4;
            do {
              if (v10->sort > (unsigned int)v6->sort)
                v6 = v10;
              ++v10;
            } while (v25 >= v10);
          }
          sort = v6->sort;
          surface = v6->surface;
          v9 = v25->surface;
          v6->sort = v25->sort;
          v6->surface = v9;
          v25->sort = sort;
          v25->surface = surface;
          result = (signed int)&v25[-1];
          v25 = (GfxDrawSurf *)result;
          if ((unsigned int)v4 >= result)
            break;
        }
      }
      goto LABEL_15;
    }
    while (1) {
      v11 = &v4[result >> 1];
      v12 = v11->sort;
      v13 = v11->surface;
      v14 = v4->surface;
      v11->sort = v4->sort;
      v11->surface = v14;
      v4->sort = v12;
      v4->surface = v13;
      v27 = v25 + 1;
      v29 = v4 + 1;
      v26 = v4 + 1;
      if (v25 >= &v4[1]) {
        while (v29->sort <= (unsigned int)v4->sort) {
        LABEL_24:
          ++v29;
          if (v25 < ++v26)
            break;
        }
      }
      v15 = v27 - 1;
      v16 = v27 - 1;
      while (1) {
        v27 = v15;
        if (v4 >= v15)
          break;
        v17 = v16->sort;
        --v16;
        if (v17 < v4->sort)
          break;
        --v15;
      }
      if (v26 <= v15) {
        v23 = v29->sort;
        v24 = v29->surface;
        v18 = v15->surface;
        v26->sort = v15->sort;
        v26->surface = v18;
        v15->sort = v23;
        v15->surface = v24;
        goto LABEL_24;
      }
      v19 = v4->sort;
      v20 = v4->surface;
      v21 = v15->surface;
      v4->sort = v15->sort;
      v4->surface = v21;
      v15->sort = v19;
      v15->surface = v20;
      if (((char *)v15 - (char *)v4 - 8) >> 3 < v25 - v26) {
        result = (signed int)v26;
        if (v25 > v26) {
          v30[v28 + 30] = v26;
          v30[v28++] = v25;
        }
        v22 = v15 - 1;
        v25 = v22;
        if (v4 < v22) {
          v3 = v22;
          goto LABEL_3;
        }
      } else {
        result = (signed int)&v15[-1];
        if (v4 < &v15[-1]) {
          v30[v28 + 30] = v4;
          v30[v28++] = result;
        }
        if (v25 > v26) {
          v4 = v26;
          v3 = v25;
          goto LABEL_3;
        }
      }
    LABEL_15:
      if (--v28 < 0)
        return result;
      v4 = (GfxDrawSurf *)v30[v28 + 30];
      v25 = (GfxDrawSurf *)v30[v28];
      result = ((unsigned int)(v25 - v4) >> 3) + 1;
      if (result <= 8)
        goto LABEL_4;
    }
  }
  return result;
}

float __cdecl R_GetDefaultNearClip(void) { UNIMPLEMENTED(); }

void __cdecl R_AddXModelSurfaces(int entIndex) {
  GfxSceneEntity *v1; // edi
  int32_t surfs;      // esi
  int surfCount;      // edx
  int v4;             // ebx
  int v5;             // ecx
  int v6;             // eax
  int v7;             // eax
  char *result;       // eax
  char *v9;           // eax
  int v10;            // [esp+2Ch] [ebp-2Ch]
  int v11;            // [esp+30h] [ebp-28h]
  char v12[4];        // [esp+34h] [ebp-24h]
  int v13;            // [esp+38h] [ebp-20h]
  int *v14;           // [esp+3Ch] [ebp-1Ch]

  v1 = &stru_11555C4 + a1;
  v13 = stru_1155004.entities + 116 * a1;
  surfs = v1->surfs;
  surfCount = v1->surfCount;
  if (surfCount <= 0) {
    v11 = 0;
    *(_DWORD *)v12 = 0;
  } else {
    v10 = 0;
    v11 = 0;
    *(_DWORD *)v12 = 0;
    do {
      v4 = *(_DWORD *)(v1->materials + 4 * v10);
      if (v4) {
        v5 = 2047;
        if (*(_DWORD *)surfs != 5)
          v5 = a1;
        v6 = *((_DWORD *)frontEndDataOut + 1);
        if (v6 <= 0xFFFF) {
          v14 = (int *)((char *)frontEndDataOut + 8 * v6 + 8);
          if (*(_DWORD *)surfs == 2 && *(_BYTE *)(fx_sort + 8))
            v7 =
                (v5 << 19) + (*(unsigned __int16 *)(v4 + 10) << 9) - 2147483150;
          else
            v7 = 16 * v5 + *(_DWORD *)surfs +
                 (*(unsigned __int16 *)(v4 + 10) << 21) + 2031616;
          *v14 = v7;
          v14[1] = surfs;
          ++dword_11555B8;
          ++*((_DWORD *)frontEndDataOut + 1);
        }
        if (*(_BYTE *)(r_showTriCounts + 8)) {
          v11 += XSurfaceGetNumTris(*(const XSurface_s **)(surfs + 4));
        } else if (*(_BYTE *)(r_showVertCounts + 8)) {
          *(_DWORD *)v12 +=
              XSurfaceGetNumVerts(*(const XSurface_s **)(surfs + 4));
        }
        surfs += (unsigned __int8)s_XModelSurfaceSize[*(_DWORD *)surfs];
        surfCount = v1->surfCount;
      }
      ++v10;
    } while (v10 < surfCount);
  }
  if (*(_BYTE *)(r_showTriCounts + 8)) {
    v9 = va("%i", v11);
    return R_AddScaledDebugString(
        (DebugGlobals *)((char *)frontEndDataOut + 2399512),
        *(const GfxViewParms **)&algn_1183A7C[20], (const float *)(v13 + 60),
        colorCyan, v9);
  }
  if (*(_BYTE *)(r_showVertCounts + 8)) {
    v9 = va("%i", *(_DWORD *)v12);
    return R_AddScaledDebugString(
        (DebugGlobals *)((char *)frontEndDataOut + 2399512),
        *(const GfxViewParms **)&algn_1183A7C[20], (const float *)(v13 + 60),
        colorCyan, v9);
  }
  result = (char *)r_showSurfCounts;
  if (*(_BYTE *)(r_showSurfCounts + 8)) {
    v9 = va("%i", surfCount);
    return R_AddScaledDebugString(
        (DebugGlobals *)((char *)frontEndDataOut + 2399512),
        *(const GfxViewParms **)&algn_1183A7C[20], (const float *)(v13 + 60),
        colorCyan, v9);
  }
  return result;
}

void __cdecl R_SortDrawSurfs(struct GfxDrawSurf *, int) { UNIMPLEMENTED(); }

void __cdecl R_SetLodOrigin(struct refdef_s const *refdef) {
  int v1;         // eax
  float v2;       // xmm0_4
  float v3;       // xmm0_4
  long double v4; // [esp+0h] [ebp-28h]
  long double v5; // [esp+0h] [ebp-28h]
  double v6;      // [esp+18h] [ebp-10h]

  v1 = r_lockPvs;
  if (*(_BYTE *)(r_lockPvs + 7)) {
    unk_1180748(r_lockPvs);
    R_SetViewParmsForScene((int)a1, (float *)&lockPvsViewParms);
    v1 = r_lockPvs;
  }
  if (*(_BYTE *)(v1 + 8)) {
    *(_DWORD *)algn_1183A7C = lockPvsViewParms;
    *(_DWORD *)&algn_1183A7C[4] = dword_7F1C84;
    *(_DWORD *)&algn_1183A7C[8] = dword_7F1C88;
  } else {
    *(float *)algn_1183A7C = a1->vieworg[0];
    *(float *)&algn_1183A7C[4] = a1->vieworg[1];
    *(float *)&algn_1183A7C[8] = a1->vieworg[2];
  }
  *(_DWORD *)&algn_1183A7C[12] = *(_DWORD *)(r_lodScale + 8);
  *(_DWORD *)&algn_1183A7C[16] = *(_DWORD *)(r_lodBias + 8);
  v2 = *(float *)&a1->fov_x;
  if (v2 != 80.0) {
    *(double *)&v4 = (float)(v2 * 0.5) * 0.0174532925199433;
    v6 = tan(v4);
    *(_QWORD *)&v5 = 0x3FE657184AE74487LL;
    v3 = v6 / (double)tan(v5);
    *(float *)&algn_1183A7C[12] = v3 * *(float *)&algn_1183A7C[12];
    *(float *)&algn_1183A7C[16] = v3 * *(float *)&algn_1183A7C[16];
  }
}

void __cdecl R_UpdateGfxEntityBounds(struct GfxEntity *ent) {
  return R_UpdateXModelBounds(
      (GfxSceneEntity *)((char *)&stru_11555C4 +
                         592409284 * (((int)a1 - stru_1155004.entities) >> 2)),
      a1);
}

void __cdecl R_SkinGfxEntity(struct GfxEntity *) {
  GfxSceneEntity *v1; // ebx

  v1 = (GfxSceneEntity *)((char *)&stru_11555C4 +
                          592409284 * (((int)a1 - stru_1155004.entities) >> 2));
  R_UpdateXModelBounds(v1, a1);
  return R_SkinSceneDObj(v1, a1);
}

struct GfxEntity *__cdecl R_AddRefEntityToScene(struct GfxEntity const *refEnt,
                                                union GfxModel sceneModel,
                                                struct centity_s const *cent) {
  int32_t reType;         // eax
  unsigned int v4;        // ecx
  signed int v5;          // ebx
  _DWORD *v6;             // edi
  int32_t customMaterial; // ecx
  int v8;                 // eax
  int *v9;                // esi
  int v10;                // eax
  _DWORD *v12;            // ebx
  int v13;                // eax
  unsigned int v14;       // eax
  signed int entityCount; // [esp+14h] [ebp-24h]
  GfxSceneEntity *v16;    // [esp+18h] [ebp-20h]
  GfxSceneEntity *v17;    // [esp+1Ch] [ebp-1Ch]

  if (__src->reType <= 1) {
    if (*(_BYTE *)(r_drawEntities + 8)) {
      entityCount = stru_1155004.entityCount;
      if (stru_1155004.entityCount <= 0x7FD) {
        v14 = *((_DWORD *)frontEndDataOut + 163843);
        if (v14 > 0x1FF7) {
          if (*(_DWORD *)frontEndDataOut !=
              R_AllocSceneEntity(void)::warnCount) {
            R_AllocSceneEntity(void)::warnCount = *(_DWORD *)frontEndDataOut;
            ri(2, (const char *)&stru_222D8C.mArgv, 8184);
            return 0;
          }
        } else {
          *((_DWORD *)frontEndDataOut + 163843) = v14 + 1;
          ++stru_1155004.entityCount;
          if (entityCount >= 0) {
            v16 = &stru_11555C4 + entityCount;
            v12 = (_DWORD *)(stru_1155004.entities + 116 * entityCount);
            memcpy(v12, __src, 0x74u);
            if (*(float *)&__src->scale == 0.0)
              v12[14] = 1065353216;
            memset(v16, 0, sizeof(GfxSceneEntity));
            v16->u = a2;
            v16->cent = (int32_t)a3;
            if (__src->reType == 1)
              R_DrawModel(entityCount);
            return (int)v12;
          }
        }
        return 0;
      }
      v13 = *(_DWORD *)frontEndDataOut;
      if (*(_DWORD *)frontEndDataOut != R_AllocSceneEntity(void)::warnCount)
        goto LABEL_23;
    }
    return 0;
  }
  if (*(_BYTE *)(com_statmon + 8) &&
      *((_DWORD *)frontEndDataOut + 163843) > 0x1CC4u) {
    unk_11807E4(5, 3000, "gfx/2d/warning@models.jpg");
    reType = __src->reType;
    if (__src->reType <= 9u)
      goto LABEL_4;
  } else {
    reType = __src->reType;
    if (__src->reType <= 9u)
      goto LABEL_4;
  }
  R_Error(ERR_DROP, "\x15R_AddRefEntityToScene: bad reType %i", reType);
LABEL_4:
  v4 = *((_DWORD *)frontEndDataOut + 163843);
  if (v4 > 0x1FF7) {
    if (*(_DWORD *)frontEndDataOut !=
        R_AddRefEntityToScene(GfxEntity const *, GfxModel,
                              centity_s const *)::warnCount) {
      R_AddRefEntityToScene(GfxEntity const *, GfxModel,
                            centity_s const *)::warnCount =
          *(_DWORD *)frontEndDataOut;
      ri(2, "refEntity buffer exceeded - not drawing model\n");
      return 0;
    }
    return 0;
  }
  if (!*(_BYTE *)(r_drawEntities + 8))
    return 0;
  v5 = stru_1155004.entityCount;
  if (stru_1155004.entityCount > 0x7FD) {
    v13 = *(_DWORD *)frontEndDataOut;
    if (*(_DWORD *)frontEndDataOut == R_AllocSceneEntity(void)::warnCount)
      return 0;
  LABEL_23:
    R_AllocSceneEntity(void)::warnCount = v13;
    ri(2, "too many scene entities (more than %i)\n", 2046);
    return 0;
  }
  *((_DWORD *)frontEndDataOut + 163843) = v4 + 1;
  ++stru_1155004.entityCount;
  if (v5 < 0)
    return 0;
  v17 = &stru_11555C4 + v5;
  v6 = (_DWORD *)(stru_1155004.entities + 116 * v5);
  memcpy(v6, __src, 0x74u);
  if (*(float *)&__src->scale == 0.0)
    v6[14] = 1065353216;
  memset(v17, 0, sizeof(GfxSceneEntity));
  if (__src->reType <= 3) {
    v17->u = a2;
  } else {
    customMaterial = __src->customMaterial;
    v8 = *((_DWORD *)frontEndDataOut + 1);
    if (v8 <= 0xFFFF) {
      v9 = (int *)((char *)frontEndDataOut + 8 * v8 + 8);
      if (s_entitySurface == 2 && *(_BYTE *)(fx_sort + 8))
        v10 = (v5 << 19) + (*(unsigned __int16 *)(customMaterial + 10) << 9) -
              2147483150;
      else
        v10 = 16 * v5 + s_entitySurface +
              (*(unsigned __int16 *)(customMaterial + 10) << 21) + 2031616;
      *v9 = v10;
      v9[1] = (int)&s_entitySurface;
      ++dword_11555B8;
      ++*((_DWORD *)frontEndDataOut + 1);
    }
  }
  return stru_1155004.entities + 116 * v5;
}

void __cdecl R_ClearScene() {
  ++scene;
  dword_1155014 = 0;
  dword_11555B8 = 0;
  dword_11555BC = (GfxDrawSurf *)((char *)frontEndDataOut +
                                  8 * *((_DWORD *)frontEndDataOut + 1) + 8);
  dword_11555C0 = 0;
  stru_1155004.entityCount = 0;
  stru_1155004.entities = (int32_t)frontEndDataOut +
                          116 * *((_DWORD *)frontEndDataOut + 163843) + 655376;
  dword_116F55C = 0;
  return R_ClearDpvsScene();
}

void __cdecl R_GenerateDrawSurfsForView(struct GfxViewParms const *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_RenderScene(struct refdef_s const *refdef) {
  int *v1;                  // eax
  _DWORD *v2;               // edx
  int v3;                   // edx
  int v4;                   // eax
  int v5;                   // edx
  size_t v6;                // eax
  uint32_t entityCount;     // edx
  int v8;                   // ecx
  int v9;                   // edx
  int v10;                  // ecx
  _DWORD *j;                // edx
  int v12;                  // esi
  _DWORD *v13;              // ebx
  int v14;                  // edi
  GfxSceneEntity *v15;      // edx
  GfxSceneEntity *v16;      // esi
  int v17;                  // eax
  int v18;                  // ebx
  _DWORD *v19;              // edx
  int v20;                  // ebx
  int v21;                  // eax
  const XModel *obj;        // eax
  const char *Name;         // eax
  float v24;                // xmm1_4
  float v25;                // xmm2_4
  bool v26;                 // al
  const char **v27;         // eax
  const char *v28;          // eax
  int Model;                // ebx
  PointLightPartition *i;   // edx
  const GfxLight *light;    // esi
  GfxDrawSurf *v32;         // ebx
  int drawSurfCount;        // edi
  GfxViewParms *v34;        // [esp+2Ch] [ebp-2C5Ch]
  bool v35;                 // [esp+33h] [ebp-2C55h]
  int v36;                  // [esp+34h] [ebp-2C54h]
  GfxDrawSurf *v37;         // [esp+38h] [ebp-2C50h]
  int PointLightPartitions; // [esp+3Ch] [ebp-2C4Ch]
  uint32_t viewIndex;       // [esp+40h] [ebp-2C48h]
  int v40;                  // [esp+44h] [ebp-2C44h]
  GfxSceneEntity *v41;      // [esp+48h] [ebp-2C40h]
  _DWORD *v42;              // [esp+4Ch] [ebp-2C3Ch]
  int v43;                  // [esp+50h] [ebp-2C38h]
  int v44;                  // [esp+54h] [ebp-2C34h]
  float v45;                // [esp+58h] [ebp-2C30h]
  int *v46;                 // [esp+5Ch] [ebp-2C2Ch]
  int v47;                  // [esp+64h] [ebp-2C24h]
  PointLightPartition *v48; // [esp+68h] [ebp-2C20h]
  GfxViewParms *v49;        // [esp+6Ch] [ebp-2C1Ch]
  _DWORD __base[2046];      // [esp+78h] [ebp-2C10h] BYREF
  PointLightPartition v51;  // [esp+2070h] [ebp-C18h] BYREF
  const char *v52;          // [esp+207Ch] [ebp-C0Ch]
  const char *v53;          // [esp+2080h] [ebp-C08h]
  const char *v54;          // [esp+2084h] [ebp-C04h]
  const char *v55;          // [esp+2088h] [ebp-C00h]
  const char *v56;          // [esp+208Ch] [ebp-BFCh]
  const char *v57;          // [esp+2090h] [ebp-BF8h]
  const char *v58;          // [esp+2094h] [ebp-BF4h]

  if (!rg[0] || *(_BYTE *)(r_norefresh + 8))
    return;
  if (!dword_1184B9C)
    R_Error(ERR_DROP, "\x15R_RenderScene: NULL worldmodel");
  stru_1155004.time = a1->time;
  stru_1155004.floatTime = (float)(int)stru_1155004.time * 0.001;
  flt_1180904[0] = a1->vieworg[0];
  flt_1180904[1] = a1->vieworg[1];
  flt_1180904[2] = a1->vieworg[2];
  *(_QWORD *)&flt_1180904[3] = *(_QWORD *)&a1->viewaxis[0][0];
  flt_1180904[5] = a1->viewaxis[0][2];
  v49 = (GfxViewParms *)R_AllocViewParms();
  R_SetViewParmsForScene((int)a1, v49->origin);
  v45 = *(float *)&a1->blurRadius;
  v35 = a1->width == vidConfig && a1->height == dword_1180684;
  v1 = &lockPvsViewParms;
  if (!*(_BYTE *)(r_lockPvs + 8))
    v1 = (int *)v49;
  v34 = (GfxViewParms *)v1;
  if ((int)stru_1155004.time < dword_1181DC8[11]) {
    if (dword_1181DC8[1] == dword_1181DC8[9]) {
      if (dword_1181DC8[11] - dword_1181DC8[10] <= 0)
        v24 = 1.0;
      else
        v24 = (float)(dword_1181DC8[11] - dword_1181DC8[10]);
      v25 = fminf(1.0, (float)(stru_1155004.time - dword_1181DC8[10]) / v24);
      flt_1181DBC = *(float *)&dword_1181DC8[5] +
                    (float)((float)(*(float *)&dword_1181DC8[13] -
                                    *(float *)&dword_1181DC8[5]) *
                            v25);
      flt_1181DC0 = *(float *)&dword_1181DC8[6] +
                    (float)((float)(*(float *)&dword_1181DC8[14] -
                                    *(float *)&dword_1181DC8[6]) *
                            v25);
      flt_1181DC4 = *(float *)&dword_1181DC8[7] +
                    (float)((float)(*(float *)&dword_1181DC8[15] -
                                    *(float *)&dword_1181DC8[7]) *
                            v25);
      unk_1181DB8 = (int)(float)((float)LOBYTE(dword_1181DC8[4]) +
                                 (float)((float)(LOBYTE(dword_1181DC8[12]) -
                                                 LOBYTE(dword_1181DC8[4])) *
                                         v25));
      unk_1181DB9 = (int)(float)((float)BYTE1(dword_1181DC8[4]) +
                                 (float)((float)(BYTE1(dword_1181DC8[12]) -
                                                 BYTE1(dword_1181DC8[4])) *
                                         v25));
      unk_1181DBA = (int)(float)((float)BYTE2(dword_1181DC8[4]) +
                                 (float)((float)(BYTE2(dword_1181DC8[12]) -
                                                 BYTE2(dword_1181DC8[4])) *
                                         v25));
      unk_1181DBB =
          (int)(float)((float)HIBYTE(dword_1181DC8[4]) +
                       (float)(v25 * (float)(HIBYTE(dword_1181DC8[12]) -
                                             HIBYTE(dword_1181DC8[4]))));
      unk_1181DAC = dword_1181DC8[9];
      LOBYTE(dword_1181DC8[0]) = 1;
      v26 = BYTE2(dword_1181DC8[16]) || BYTE2(dword_1181DC8[8]);
      BYTE2(dword_1181DC8[0]) = v26;
    } else {
      unk_1181DAC = dword_1181DC8[9];
      unk_1181DB0 = dword_1181DC8[10];
      unk_1181DB4 = dword_1181DC8[11];
      unk_1181DB8 = dword_1181DC8[12];
      flt_1181DBC = *(float *)&dword_1181DC8[13];
      flt_1181DC0 = *(float *)&dword_1181DC8[14];
      flt_1181DC4 = *(float *)&dword_1181DC8[15];
      dword_1181DC8[0] = dword_1181DC8[16];
      dword_1181DC8[11] = 0;
    }
  } else {
    unk_1181DAC = dword_1181DC8[9];
    unk_1181DB0 = dword_1181DC8[10];
    unk_1181DB4 = dword_1181DC8[11];
    unk_1181DB8 = dword_1181DC8[12];
    flt_1181DBC = *(float *)&dword_1181DC8[13];
    flt_1181DC0 = *(float *)&dword_1181DC8[14];
    flt_1181DC4 = *(float *)&dword_1181DC8[15];
    dword_1181DC8[0] = dword_1181DC8[16];
  }
  if (unk_1181E0C) {
    v2 = frontEndDataOut;
    *((_DWORD *)frontEndDataOut + 550715) = unk_1181DAC;
    v2[550716] = unk_1181DB0;
    v2[550717] = unk_1181DB4;
    v2[550718] = unk_1181DB8;
    v2[550719] = LODWORD(flt_1181DBC);
    v2[550720] = LODWORD(flt_1181DC0);
    v2[550721] = LODWORD(flt_1181DC4);
    v2[550722] = dword_1181DC8[0];
  } else {
    *((_DWORD *)frontEndDataOut + 550715) = 0;
  }
  viewIndex = a1->viewIndex;
  v3 = R_CellForPoint(v34->origin);
  if (dword_1184B9C && *(_DWORD *)(dword_1184B9C + 256))
    R_AddWorldSurfacesDpvs(v34, v3);
  CG_AddMarks();
  FX_DrawScheduledEffects();
  v36 = dword_11555B8;
  v37 = dword_11555BC;
  qsortDrawSurfs(dword_11555BC, dword_11555B8);
  if (*(_DWORD *)(r_rendererInUse + 8) != 2 && *(_DWORD *)(r_dlightLimit + 8))
    PointLightPartitions = R_GetPointLightPartitions(v37, v36, &v51, 256);
  else
    PointLightPartitions = 0;
  if (*(_BYTE *)(r_fullbright + 8)) {
    if (!R_BeginDrawGroupSection(R_DRAWGROUP_WORLD_REMAINDER)) {
      R_AddCmdSetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
      R_AddCmdSetViewport(0, 0, vidConfig, dword_1180684);
      R_AddClearCommandsForFrameBuffer(0);
    }
    R_BeginDrawGroupLoop(R_DRAWGROUP_WORLD_REMAINDER, viewIndex);
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_FOGABLE_FIRST);
    R_AddCmdDrawSun(viewIndex);
    R_EndDrawGroupLoop(R_DRAWGROUP_WORLD_REMAINDER, viewIndex);
    R_EndDrawGroupSection(R_DRAWGROUP_WORLD_REMAINDER);
    if (!R_BeginDrawGroupSection(R_DRAWGROUP_POST_AA))
      R_AddCmdSetViewport(0, 0, vidConfig, dword_1180684);
    R_BeginDrawGroupLoop(R_DRAWGROUP_POST_AA, viewIndex);
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
  } else if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
    R_AddCmdSetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
    R_AddClearCommandsForFrameBuffer(0);
    R_AddCmdLightProperties(0, (const GfxLight *)(dword_1184B9C + 180));
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_SKY);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_LIGHTING_FIRST);
    R_AddCmdDrawSun(viewIndex);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_EMISSIVE);
  } else if (*(_DWORD *)(r_debugShader + 8)) {
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
    R_AddCmdSetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
    R_AddClearCommandsForFrameBuffer(0);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_DEBUG_BUMPMAP);
  } else {
    if (!R_BeginDrawGroupSection(R_DRAWGROUP_WORLD_SUN)) {
      R_AddCmdSetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
      R_AddCmdSetViewport(0, 0, vidConfig, dword_1180684);
      R_AddClearCommandsForFrameBuffer(0);
      R_AddCmdLightProperties(0, (const GfxLight *)(dword_1184B9C + 180));
    }
    R_BeginDrawGroupLoop(R_DRAWGROUP_WORLD_SUN, viewIndex);
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_SKY);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_LIGHTING_FIRST);
    R_AddCmdDrawSun(viewIndex);
    if (!R_EndDrawGroupLoop(R_DRAWGROUP_WORLD_SUN, viewIndex) && v35)
      R_AddCmdApplyEarlyPostEffects();
    R_EndDrawGroupSection(R_DRAWGROUP_WORLD_SUN);
    R_BeginDrawGroupSection(R_DRAWGROUP_WORLD_REMAINDER);
    R_BeginDrawGroupLoop(R_DRAWGROUP_WORLD_REMAINDER, viewIndex);
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
    if (PointLightPartitions > 0) {
      v40 = 0;
      v48 = &v51;
      for (i = &v51;; i = v48) {
        light = (const GfxLight *)i->light;
        v32 = &dword_11555BC[i->firstDrawSurf];
        drawSurfCount = i->drawSurfCount;
        R_AddCmdDrawFullScreenColoredQuad(0.0, 0.0, 1.0, 1.0, colorWhite,
                                          (Material *)rgp[1042]);
        R_AddCmdLightProperties(0, light);
        R_AddCmdDrawSurfs(v32, drawSurfCount, TECHNIQUE_POINTLIGHT);
        ++v40;
        ++v48;
        if (PointLightPartitions == v40)
          break;
      }
    }
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_EMISSIVE);
    R_EndDrawGroupLoop(R_DRAWGROUP_WORLD_REMAINDER, viewIndex);
    R_EndDrawGroupSection(R_DRAWGROUP_WORLD_REMAINDER);
    R_BeginDrawGroupSection(R_DRAWGROUP_POST_AA);
    R_BeginDrawGroupLoop(R_DRAWGROUP_POST_AA, viewIndex);
    R_AddCmdBeginView(scene, &stru_1155004, v49,
                      (const GfxLodParms *)algn_1183A7C);
    if (v35)
      R_AddCmdApplyLatePostEffects(v45);
    R_AddCmdDrawSunPostEffects(viewIndex);
  }
  v4 = *(_DWORD *)(r_showTris + 8);
  if (v4) {
    if ((v4 & 2) != 0)
      R_AddCmdClearScreen(6, colorWhite, 1.0, 0);
    R_AddCmdDrawSurfs(v37, v36, TECHNIQUE_WIREFRAME_SOLID);
  }
  R_UnlockSkinnedCache();
  v5 = *(_DWORD *)(r_debugEntCounts + 8);
  if (!v5 || v5 >= (int)stru_1155004.entityCount)
    return;
  dword_1180758(r_debugEntCounts, 0);
  v51.light = (int32_t) "dobj";
  v51.firstDrawSurf = (int32_t) "xmodel";
  v51.drawSurfCount = (uint32_t) "smodel";
  v52 = "bmodel";
  v53 = "sprite";
  v54 = "rail core";
  v55 = "cloud";
  v56 = "oriented";
  v57 = "line";
  v58 = "cylinder";
  if (stru_1155004.entityCount) {
    v6 = 0;
    entityCount = stru_1155004.entityCount;
    do {
      __base[v6] = v6;
      ++v6;
    } while (entityCount != v6);
  } else {
    v6 = 0;
  }
  qsort(__base, v6, 4u,
        (int(__cdecl *)(const void *, const void *))R_CompareDumpSceneEntities);
  if (!stru_1155004.entityCount)
    return;
  v43 = 0;
  v8 = 0;
  do {
    v9 = __base[v8];
    v41 = &stru_11555C4 + v9;
    v42 = (char *)frontEndDataOut + 116 * v9 + 655376;
    v10 = v8 + 1;
    v44 = v10;
    if (v10 == stru_1155004.entityCount) {
      v18 = v10;
      v19 = (char *)frontEndDataOut + 116 * v9 + 655376;
      goto LABEL_44;
    }
    v47 = v10;
    for (j = &__base[v43];; j = &__base[v43]) {
      v12 = __base[v47];
      v46 = (int *)((char *)frontEndDataOut + 116 * *j + 655376);
      v13 = (char *)frontEndDataOut + 116 * v12 + 655376;
      v14 = *v46;
      if (*v46 != *v13) {
      LABEL_43:
        v18 = v44;
        v19 = v42;
        goto LABEL_44;
      }
      v15 = &stru_11555C4 + *j;
      v16 = &stru_11555C4 + v12;
      if (v14 > 2) {
        if (v14 != 3)
          goto LABEL_72;
        v17 = (v15->u.obj - v16->u.obj) >> 5;
      } else {
        if (v14 >= 1) {
          v17 = v15->u.obj - v16->u.obj;
          goto LABEL_40;
        }
        if (v14) {
        LABEL_72:
          v17 = -252645135 * ((v46[21] - v13[21]) >> 2);
          goto LABEL_40;
        }
        Model = DObjGetModel((const DObj_s *)v15->u.obj, 0);
        v17 = Model - DObjGetModel((const DObj_s *)v16->u.obj, 0);
      }
    LABEL_40:
      if (v17)
        goto LABEL_43;
      ++v44;
      ++v47;
      if (v44 == stru_1155004.entityCount)
        break;
    }
    v18 = v44;
    v19 = v42;
  LABEL_44:
    v20 = v18 - v43;
    Com_Printf("%3i: %-8s: ", v20, *((const char **)&v51.light + *v19));
    v21 = *v42;
    if ((int)*v42 > 2) {
      if (v21 == 3) {
        Com_Printf("*%i\n",
                   (v41->u.obj - *(_DWORD *)(dword_1184B9C + 312)) >> 5);
        goto LABEL_48;
      }
    LABEL_68:
      v27 = (const char **)v42[21];
      if (v27)
        v28 = *v27;
      else
        v28 = "(null)";
      Com_Printf("%s\n", v28);
      goto LABEL_48;
    }
    if (v21 >= 1) {
      obj = (const XModel *)v41->u.obj;
      goto LABEL_47;
    }
    if (v21)
      goto LABEL_68;
    obj = (const XModel *)DObjGetModel((const DObj_s *)v41->u.obj, 0);
  LABEL_47:
    Name = (const char *)XModelGetName(obj);
    Com_Printf("%s\n", Name);
  LABEL_48:
    v43 += v20;
    v8 = v43;
  } while (stru_1155004.entityCount != v43);
}

int marker_r_scene;
struct GfxScene scene;
void __cdecl R_SetPostProcessParms(struct refdef_s const *,
                                   struct GfxPostProcessParms *) {
  UNIMPLEMENTED();
}

bool __cdecl R_ShouldDrawDLights(void) { UNIMPLEMENTED(); }

void __cdecl swapDrawSurfs(struct GfxDrawSurf *, struct GfxDrawSurf *) {
  UNIMPLEMENTED();
}

unsigned char __cdecl LerpByte(unsigned char, unsigned char, float) {
  UNIMPLEMENTED();
}

int __cdecl R_AllocSceneEntity(void) { UNIMPLEMENTED(); }

int __cdecl R_CompareDumpSceneEntities(void const *, void const *) {
  int v2;             // ebx
  _DWORD *v3;         // esi
  int v4;             // edx
  int result;         // eax
  GfxSceneEntity *v6; // ecx
  GfxSceneEntity *v7; // edi
  int Model;          // ebx
  int *v9;            // [esp+1Ch] [ebp-1Ch]

  v2 = *a2;
  v9 = (int *)((char *)frontEndDataOut + 116 * *a1 + 655376);
  v3 = (char *)frontEndDataOut + 116 * *a2 + 655376;
  v4 = *v9;
  result = *v9 - *v3;
  if (*v9 == *v3) {
    v6 = &stru_11555C4 + *a1;
    v7 = &stru_11555C4 + v2;
    if (v4 <= 2) {
      if (v4 >= 1)
        return v6->u.obj - v7->u.obj;
      if (!v4) {
        Model = DObjGetModel((const DObj_s *)v6->u.obj, 0);
        return Model - DObjGetModel((const DObj_s *)v7->u.obj, 0);
      }
    } else if (v4 == 3) {
      return (v6->u.obj - v7->u.obj) >> 5;
    }
    return -252645135 * ((*((_DWORD *)frontEndDataOut + 29 * *a1 + 163865) -
                          *((_DWORD *)frontEndDataOut + 29 * v2 + 163865)) >>
                         2);
  }
  return result;
}

void __cdecl R_InitGfxEntity(struct GfxEntity *) { UNIMPLEMENTED(); }

enum MaterialTechniqueType __cdecl R_EmissiveTechniqueType(
    struct GfxPostProcessParms const *) {
  UNIMPLEMENTED();
}

void __cdecl shortsortDrawSurfs(struct GfxDrawSurf *, struct GfxDrawSurf *) {
  UNIMPLEMENTED();
}

void __cdecl R_SetFrameFog(struct GfxViewParms const *) { UNIMPLEMENTED(); }

int __cdecl R_CountSameSceneEntity(int *const, int) { UNIMPLEMENTED(); }

void __cdecl R_SetSceneRefEntity(int, struct GfxEntity const *,
                                 union GfxModel) {
  UNIMPLEMENTED();
}

void __cdecl R_AddClearCommandsForFloatZ(void) { UNIMPLEMENTED(); }

void __cdecl R_AddClearCommandsForFrameBuffer(enum ShadowType) {
  UNIMPLEMENTED();
}

void __cdecl R_SetupProjection(float, float, float, struct GfxViewParms *) {
  UNIMPLEMENTED();
}

void __cdecl R_SetViewParmsForScene(struct refdef_s const *,
                                    struct GfxViewParms *) {
  UNIMPLEMENTED();
}

void __cdecl R_AddDebugShaderDrawCommands(int, struct GfxViewParms const *,
                                          struct GfxDrawSurf *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddFullbrightDrawCommands(int, struct GfxViewParms const *,
                                         struct GfxDrawSurf *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddDepthPrepassCommands(int, struct GfxViewParms const *,
                                       struct GfxDrawSurf *, int,
                                       enum ShadowType) {
  UNIMPLEMENTED();
}

void __cdecl R_AddClearCommandsForFrameBufferIfNeeded(enum ShadowType) {
  UNIMPLEMENTED();
}

void __cdecl R_DrawPointLitSurfs(int, struct PointLightPartition const *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddStandardDrawCommands(int, struct GfxViewParms const *,
                                       struct GfxPostProcessParms const *,
                                       struct GfxDrawSurf *, int,
                                       enum ShadowType,
                                       struct ShadowCookieList *,
                                       struct PointLightPartition *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_AddDrawCommands(int, struct GfxViewParms const *,
                               struct GfxPostProcessParms const *,
                               struct GfxDrawSurf *, int, enum ShadowType,
                               struct ShadowCookieList *,
                               struct PointLightPartition *const, int) {
  UNIMPLEMENTED();
}

void __cdecl R_DumpSceneEntities(void) { UNIMPLEMENTED(); }

struct GfxEntity *__cdecl R_AddGfxModelToScene(struct GfxEntity const *,
                                               union GfxModel,
                                               struct centity_s const *) {
  UNIMPLEMENTED();
}

void __cdecl R_GenerateSortedDrawSurfs(int, struct GfxViewParms const *,
                                       struct GfxViewParms const *,
                                       struct GfxPostProcessParms const *) {
  UNIMPLEMENTED();
}
