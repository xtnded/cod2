void __cdecl RB_ShowLightVisCachePoints(
    float const *const viewOrigin, struct DpvsPlane const *const clipPlanes,
    int clipPlaneCount) {
  int v3;          // edi
  int v4;          // esi
  char *j;         // ebx
  int v6;          // edx
  char *v7;        // ecx
  int v8;          // eax
  const float *v9; // eax
  int v10;         // [esp+2Ch] [ebp-6Ch]
  float v11;       // [esp+38h] [ebp-60h]
  float v12;       // [esp+3Ch] [ebp-5Ch]
  float v13;       // [esp+40h] [ebp-58h]
  int v14;         // [esp+48h] [ebp-50h]
  int v15;         // [esp+4Ch] [ebp-4Ch]
  int v16;         // [esp+50h] [ebp-48h]
  int v17;         // [esp+54h] [ebp-44h]
  unsigned int i;  // [esp+58h] [ebp-40h]
  int v19;         // [esp+5Ch] [ebp-3Ch]
  int v20;         // [esp+64h] [ebp-34h]
  int v21;         // [esp+68h] [ebp-30h]
  float v22;       // [esp+74h] [ebp-24h] BYREF
  float v23;       // [esp+78h] [ebp-20h]
  float v24;       // [esp+7Ch] [ebp-1Ch]

  if (s_vc_log) {
    v19 = *(_DWORD *)(r_vc_showlog + 8);
    if (v19 > 0) {
      v13 = floorf((float)(*a1 + 131072.0) + 0.5);
      v14 = (int)v13 >> 5;
      v12 = floorf((float)(a1[1] + 131072.0) + 0.5);
      v15 = (int)v12 >> 5;
      v11 = floorf(a1[2] + 131072.0);
      v22 = (float)(32 * v14 - (int)&loc_20000);
      v23 = (float)(32 * v15 - (int)&loc_20000);
      v24 = (float)(((int)v11 >> 6 << 6) - (int)&loc_20000);
      v21 = ((int)v11 >> 6) - 1;
      for (i = -1; i != 2; ++i) {
        if (v21 >= 0 && v21 << 6 <= 0x80000 && v19 >= -v19) {
          v20 = v15 - v19;
          v17 = -v19;
          do {
            if (v20 >= 0 && 32 * v20 <= 0x80000) {
              v3 = v14 - v19;
              v16 = -v19;
              do {
                if (v3 >= 0 && 32 * v3 <= 0x80000) {
                  v10 = dword_C96C84 - 1;
                  if (dword_C96C84 - 1 < 0)
                    goto LABEL_22;
                  v4 = 0;
                  for (j = (char *)s_vc_log;; j = (char *)s_vc_log) {
                    v6 = (v4 + v10) >> 1;
                    v7 = &j[6 * v6];
                    v8 = v3 - *(unsigned __int16 *)v7;
                    if (!v8) {
                      v8 = v20 - *((unsigned __int16 *)v7 + 1);
                      if (!v8) {
                        v8 = v21 - *((unsigned __int16 *)v7 + 2);
                        if (!v8)
                          break;
                      }
                    }
                    if (v8 < 0) {
                      v10 = v6 - 1;
                      if (v6 - 1 < v4)
                        goto LABEL_22;
                    } else {
                      v4 = v6 + 1;
                      if (v10 < v6 + 1)
                        goto LABEL_22;
                    }
                  }
                  if (v6 < 0) {
                  LABEL_22:
                    v22 = (float)(32 * v3 - (int)&loc_20000);
                    v23 = (float)(32 * v20 - (int)&loc_20000);
                    v24 = (float)((v21 << 6) - (int)&loc_20000);
                    if (R_CullPointAndRadius(&v22, 0.0, a2, a3) != 2) {
                      if (i <= 1)
                        v9 = colorGreen;
                      else
                        v9 = colorYellow;
                      R_AddDebugString((DebugGlobals *)(backEndData + 2399512),
                                       &v22, v9, 1.0, ".");
                    }
                  }
                }
                ++v16;
                ++v3;
              } while (v19 >= v16);
            }
            ++v17;
            ++v20;
          } while (v19 >= v17);
        }
        ++v21;
      }
    }
  }
}

float __cdecl RB_GetLightingAtPoint(struct GfxLightGrid const * lightGrid, float const * const samplePos, float  colorForDir)[4])
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetupEntityLighting(struct GfxEntity const *ent,
                                    struct GfxEntityLighting *lighting) {
  $_3621 lighting; // [esp+14h] [ebp-14h] BYREF

  a2->viewCount = dword_11E19B4;
  if (SLOBYTE(a1->renderFxFlags) >= 0) {
    lighting.dx7 = *($_3622 *)a1->origin;
    lighting.baseCoords[2] = a1->origin[2] + 4.0;
  } else {
    lighting = a1->lighting;
  }
  *(float *)&a2->sunVisibility =
      RB_GetLightingAtPoint((const GfxLightGrid *)(dword_1184B9C + 284),
                            lighting.baseCoords, (float(*)[4])a2->colorForDir);
}

void __cdecl RB_InitLightVisHistory(char const *bspName) {
  unsigned int File; // eax
  size_t v9;         // ebx
  char v10[64];      // [esp+1Ch] [ebp-5Ch] BYREF
  void *__src;       // [esp+5Ch] [ebp-1Ch] BYREF

  s_vc_log = 0;
  dword_C96C84 = 0;
  if (*(_DWORD *)(r_vc_makelog + 8)) {
    s_vc_log = Z_MallocInternal((size_t)&unk_1800000);
    if (*(_DWORD *)(r_vc_makelog + 8) == 2) {
      Com_StripExtension(a8, v10);
      if (strlen(v10) + 5 > 0x3F)
        Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
                  "\x15light grid log filename '%s.grid' is too long\n", v10);
      strcat(v10, ".grid");
      File = FS_ReadFile(v10, (char **)&__src);
      if ((File & 0x80000000) == 0) {
        if (File == 6 * (File / 6)) {
          v9 = (size_t)&unk_1800000;
          if (File < (unsigned int)&unk_1800001)
            v9 = File;
          memcpy(s_vc_log, __src, v9);
          dword_C96C84 = v9 / 6;
        }
        FS_FreeFile(__src);
      }
    }
  }
}

void __cdecl RB_SaveLightVisHistory() {
  char __src[88]; // [esp+10h] [ebp-58h] BYREF

  if (s_vc_log && dword_1184B9C) {
    Com_StripExtension(*(char **)dword_1184B9C, __src);
    if (strlen(__src) + 5 > 0x3F)
      Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
                "\x15light grid log filename '%s.grid' is too long\n", __src);
    strcat(__src, ".grid");
    FS_WriteFile(__src, (char *)s_vc_log, 6 * dword_C96C84);
    Z_FreeInternal(s_vc_log);
    s_vc_log = 0;
    dword_C96C84 = 0;
  }
}

int marker_rb_light;
void __cdecl RB_WeightedAccumulateLightGridColors(
    struct GfxLightGridColors const *, float, float (*const)[4]) {
  UNIMPLEMENTED();
}

void __cdecl RB_PackLightGridPosition(int, int, int, unsigned int *,
                                      unsigned char *) {
  UNIMPLEMENTED();
}

bool __cdecl RB_AddSortedHistoryEntry(int, int, int, int) { UNIMPLEMENTED(); }

void __cdecl RB_NoLightingAtPoint(float (*const)[4]) { UNIMPLEMENTED(); }

void __cdecl RB_ScaleLightGridColors(float, float (*const)[4]) {
  UNIMPLEMENTED();
}

bool __cdecl RB_FindNearestLightGridSample(struct GfxLightGrid const *, int,
                                           int, int, int *) {
  UNIMPLEMENTED();
}

int __cdecl RB_SortedHistoryEntry(int, int, int, enum GfxSortedHistoryAdd) {
  UNIMPLEMENTED();
}

bool __cdecl RB_ExtrapolateLightingAtPoint(struct GfxLightGrid const *, int,
                                           int, int, float (*const)[4],
                                           float *) {
  UNIMPLEMENTED();
}

void __cdecl RB_ShowCornerSample(float const *const, float,
                                 float const *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_ShowGridBox(int, int, int) { UNIMPLEMENTED(); }

void __cdecl RB_ShowGridOrigin(float const *const) { UNIMPLEMENTED(); }

bool __cdecl RB_IsValidLightGridSample(struct GfxLightGridPoint *, int,
                                       float const *const, float const *const) {
  UNIMPLEMENTED();
}

struct GfxLightGridPoint *__cdecl RB_GetLightGridSample(
    struct GfxLightGrid const *, int, int, int, int, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl R_LightVisHistoryFilename(char const *, char *const) {
  UNIMPLEMENTED();
}

RB_DeriveEntityLights(float const (*)[4], float, Material const *, _D3DLIGHT9 *,
                      int) {
  UNIMPLEMENTED();
}
