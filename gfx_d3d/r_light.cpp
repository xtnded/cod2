void __cdecl R_ShutdownLightDefs() { lightGlob = 0; }

int __cdecl R_GetPointLightPartitions(
    struct GfxDrawSurf const *drawSurfs, int drawSurfCount,
    struct PointLightPartition *const partitions, int partitionLimit) {
  int v4;                   // esi
  int *v5;                  // eax
  int v6;                   // ebx
  int *i;                   // edi
  int v8;                   // edi
  int v9;                   // eax
  int *v10;                 // esi
  int v11;                  // ebx
  int *v12;                 // eax
  int v13;                  // ecx
  int v14;                  // eax
  int v15;                  // edi
  bool v16;                 // cc
  int v17;                  // ecx
  int *v18;                 // edx
  PointLightPartition *j;   // ebx
  int32_t v20;              // edx
  const GfxDrawSurf *v21;   // esi
  int v22;                  // edi
  int v23;                  // eax
  int v24;                  // ebx
  GfxDrawSurf *v25;         // ecx
  int32_t surface;          // edx
  int v27;                  // eax
  int v29;                  // ecx
  char *v30;                // edx
  PointLightPartition *v31; // [esp+1Ch] [ebp-FCh]
  int v32;                  // [esp+30h] [ebp-E8h]
  int v33;                  // [esp+34h] [ebp-E4h]
  int v34;                  // [esp+38h] [ebp-E0h]
  int *v35;                 // [esp+3Ch] [ebp-DCh]
  float v36;                // [esp+40h] [ebp-D8h]
  float v37;                // [esp+44h] [ebp-D4h]
  int v38;                  // [esp+48h] [ebp-D0h]
  float v39;                // [esp+4Ch] [ebp-CCh]
  float v40;                // [esp+50h] [ebp-C8h]
  int v41;                  // [esp+54h] [ebp-C4h]
  float v42;                // [esp+58h] [ebp-C0h]
  float v43;                // [esp+5Ch] [ebp-BCh]
  float v44;                // [esp+60h] [ebp-B8h]
  float v45;                // [esp+64h] [ebp-B4h]
  float v46;                // [esp+68h] [ebp-B0h]
  float v47;                // [esp+6Ch] [ebp-ACh]
  int v48;                  // [esp+70h] [ebp-A8h]
  int v49;                  // [esp+74h] [ebp-A4h]
  int v50;                  // [esp+78h] [ebp-A0h]
  int v51;                  // [esp+7Ch] [ebp-9Ch]
  _DWORD v52[38];           // [esp+80h] [ebp-98h] BYREF

  v4 = a4;
  v5 = &scene;
  v6 = dword_1155014;
  if (dword_1155014 > 0) {
    v29 = 0;
    v49 = 0;
    v30 = (char *)&unk_1155018;
    do {
      if (!*((_BYTE *)v5 + 1432))
        v52[v49++] = v30;
      ++v29;
      v30 += 44;
      v5 = (int *)((char *)v5 + 1);
    } while (v29 != v6);
  } else {
    v49 = 0;
  }
  if (*(_DWORD *)(r_dlightLimit + 8) < a4)
    v4 = *(_DWORD *)(r_dlightLimit + 8);
  v33 = v4;
  if (v4 < v49) {
    v50 = v4;
    v35 = v52;
    for (i = v52;; i = v35) {
      v38 = *i;
      v8 = v49;
      v34 = 0;
      do {
      LABEL_8:
        if (v8 <= ++v34)
          break;
        v14 = v35[v34];
        v36 = *(float *)(v14 + 16);
        v37 = *(float *)(v38 + 16);
        v45 = Vec3DistanceSq((float *)(v14 + 4), flt_1180904);
        v44 = Vec3DistanceSq((float *)(v38 + 4), flt_1180904);
      } while ((float)((float)(v36 * v36) * v44) >=
               (float)((float)(v37 * v37) * v45));
      v9 = (int)&v35[v8 - 1];
      while (v34 <= --v8) {
        v10 = (int *)v9;
        v11 = *(_DWORD *)v9;
        v39 = *(float *)(v38 + 16);
        v40 = *(float *)(*(_DWORD *)v9 + 16);
        v47 = Vec3DistanceSq((float *)(v38 + 4), flt_1180904);
        v46 = Vec3DistanceSq((float *)(v11 + 4), flt_1180904);
        v9 = (int)(v10 - 1);
        if ((float)((float)(v39 * v39) * v46) <
            (float)((float)(v40 * v40) * v47)) {
          v12 = &v35[v34];
          v13 = *v12;
          *v12 = *v10;
          *v10 = v13;
          goto LABEL_8;
        }
      }
      if (v49 != v34)
        break;
      v17 = *v35;
      v18 = &v35[v8];
      *v35 = *v18;
      *v18 = v17;
      v15 = --v34;
      v16 = v50 <= v34;
      if (v50 == v34)
        goto LABEL_22;
    LABEL_17:
      if (v16) {
        v49 = v34;
      } else {
        v35 += v15;
        v49 -= v15;
        v50 -= v15;
      }
    }
    v15 = v34;
    v16 = v50 <= v34;
    if (v50 != v34)
      goto LABEL_17;
  LABEL_22:
    v49 = v33;
  }
  if (v49 <= 0)
    return 0;
  v48 = a2 - 1;
  v51 = 0;
  v32 = 0;
  v31 = a3;
  for (j = a3;; j = v31) {
    v20 = v52[v51];
    j->light = v20;
    j->firstDrawSurf = dword_11555B8;
    v41 = v20 + 4;
    v42 = *(float *)(v20 + 16) * *(float *)(v20 + 16);
    if (v48 >= 0) {
      v21 = &a1[v48];
      v22 = 0;
      do {
        v23 = R_BoundsForDrawSurf(v21);
        if (v23) {
          v43 = PointToBoxDistSq(v41, v23, v23 + 12);
          if (v43 <= v42) {
            v24 = dword_11555B8;
            v25 = dword_11555BC;
            surface = v21->surface;
            dword_11555BC[dword_11555B8].sort = v21->sort;
            v25[v24].surface = surface;
            ++dword_11555B8;
            ++*((_DWORD *)frontEndDataOut + 1);
          }
        }
        ++v22;
        --v21;
      } while (a2 != v22);
    }
    v27 = dword_11555B8 - v31->firstDrawSurf;
    v31->drawSurfCount = v27;
    if (v27) {
      ++v32;
      ++v31;
    }
    if (v49 == ++v51)
      break;
  }
  return v32;
}

struct GfxLightDef *__cdecl R_RegisterLightDef(char const *name) {
  int v2;         // eax
  int LightDef;   // ecx
  int v4;         // esi
  int *v5;        // ebx
  const char *v7; // eax
  int v8;         // edx
  int v9;         // esi
  int *v10;       // ebx
  int v11;        // [esp+Ch] [ebp-2Ch]

  v2 = lightGlob[0];
  while (lightGlob[0] <= 0) {
  LABEL_2:
    if (v2 == 64) {
      ri(0, "Loaded light defs:\n");
      v7 = (const char *)lightGlob[0];
      if (lightGlob[0] > 0) {
        v9 = 0;
        v10 = lightGlob;
        do {
          ri(0, stru_2182FC.name, *(_DWORD *)(v10[1] + 20));
          ++v9;
          v7 = (const char *)lightGlob[0];
          ++v10;
        } while (v9 < lightGlob[0]);
      }
      R_Error(ERR_DROP,
              "Can't load light def %s; %i unique light defs already loaded",
              v7, v11);
      LightDef = R_LoadLightDef(__src);
      if (LightDef) {
      LABEL_13:
        v8 = lightGlob[0];
        lightGlob[lightGlob[0] + 1] = LightDef;
        lightGlob[0] = v8 + 1;
        return LightDef;
      }
    } else {
      LightDef = R_LoadLightDef(__src);
      if (LightDef)
        goto LABEL_13;
    }
    if (!stricmp(__src, "light_dynamic"))
      R_Error(ERR_DROP, "Can't load the default light def '%s'", __src);
    __src = "light_dynamic";
    v2 = lightGlob[0];
  }
  v4 = 0;
  v5 = lightGlob;
  while (stricmp(__src, *(const char **)(v5[1] + 20))) {
    ++v4;
    v2 = lightGlob[0];
    ++v5;
    if (v4 >= lightGlob[0])
      goto LABEL_2;
  }
  return dword_1218824[v4];
}

void __cdecl R_InitLightDefs() {
  int result; // eax

  result = R_RegisterLightDef("light_dynamic");
  rgp[1034] = result;
  return result;
}

int marker_r_light;
bool __cdecl R_LightImportanceGreaterEqual(struct GfxLight const *,
                                           struct GfxLight const *) {
  UNIMPLEMENTED();
}

void __cdecl R_CommitSurfsFromListAffectedByLight(struct GfxDrawSurf const *,
                                                  int, float const *const,
                                                  float) {
  UNIMPLEMENTED();
}

void __cdecl R_MostImportantLights(struct GfxLight const **const, int, int) {
  UNIMPLEMENTED();
}
