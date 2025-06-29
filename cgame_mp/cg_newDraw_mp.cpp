void __cdecl MemFile_ArchiveData(struct MemoryFile *, int, void *) {
  UNIMPLEMENTED();
}

void __cdecl MemFile_ArchiveInt(struct MemoryFile *, int *) { UNIMPLEMENTED(); }

void __cdecl CG_GetTeamColor(float (*)[4]) { UNIMPLEMENTED(); }

int __cdecl CG_KeyInterceptEvent(int key, int down) {
  if (!a2 || !CG_ScoreboardDisplayed())
    return 0;
  if (a1 != 206 && a1 != 164) {
    if (a1 == 205 || a1 == 163) {
      CG_ScrollScoreboardDown();
      return 1;
    }
    return 0;
  }
  CG_ScrollScoreboardUp();
  return 1;
}

char const *__cdecl CG_GameTypeString() { UNIMPLEMENTED(); }

int __cdecl CG_OwnerDrawVisible(int) { UNIMPLEMENTED(); }

int __cdecl CG_ServerMaterialName(int index, char *materialName, int maxLen) {
  const char *ConfigString; // edx

  if ((unsigned int)(a1 - 1) > 0x7E)
    return 0;
  ConfigString = (const char *)CL_GetConfigString(a1 + 1566);
  if (!*ConfigString || strlen(ConfigString) >= a3)
    return 0;
  strcpy(__dst, ConfigString);
  return 1;
}

void __cdecl CG_ResetLowHealthOverlay() {
  _DWORD *v0; // edx
  int result; // eax

  v0 = cg;
  *((_BYTE *)cg + 179744) = 0;
  result = *(_DWORD *)(hud_healthOverlay_phaseEnd_toAlpha + 8);
  v0[44932] = result;
  *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)v0) = 0;
  *(_DWORD *)((char *)&locret_2BE1C + (_DWORD)v0) = 0;
  v0[44939] = 0;
  *(_DWORD *)((char *)&loc_2BE28 + (_DWORD)v0) = 1065353216;
  return result;
}

float __cdecl CG_CalcPlayerHealth() {
  int v0;   // edx
  int v1;   // ecx
  float v2; // xmm1_4

  v0 = *(_DWORD *)(*((_DWORD *)cg + 9) + 312);
  if (v0 && (v1 = *(_DWORD *)(*((_DWORD *)cg + 9) + 320)) != 0 &&
      *(_DWORD *)(*((_DWORD *)cg + 9) + 16) != 6 &&
      (v2 = (float)v0 / (float)v1, v2 >= 0.0)) {
    if (v2 > 1.0)
      return 1.0;
  } else {
    return 0.0;
  }
  return v2;
}

void __cdecl CG_SetNormalSplitscreenScaling(void) { UNIMPLEMENTED(); }

void __cdecl CG_SetLegacySplitscreenScaling(void) { UNIMPLEMENTED(); }

bool __cdecl CG_AreHudMenusHidden() {
  return (CL_GetKeyCatchers() & 8) != 0 &&
             !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
         *((_DWORD *)cg + 44914) == 0;
}

char const *__cdecl CG_GetKillerText() { UNIMPLEMENTED(); }

void __cdecl CG_ApplySplitScreenCompassScale(float *x, float *y, float *w,
                                             float *h) {
  ;
}

struct Material *__cdecl CG_ObjectiveIcon(int, int) {
  UNIMPLEMENTED();
}

float __cdecl CG_FadeHudMenu(struct dvar_s const *fadeDvar,
                             int displayStartTime, int duration) {
  _BOOL4 v3; // eax
  int *v5;   // eax

  v3 = (CL_GetKeyCatchers() & 8) != 0 &&
           !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
       !*((_DWORD *)cg + 44914);
  if (v3 || !*(_BYTE *)(hud_enable + 8))
    return 0.0;
  if (*(float *)&a1->current.integer == 0.0)
    return 1.0;
  v5 = CG_FadeColor(a2, a3, 700);
  if (v5)
    return *((float *)v5 + 3);
  else
    return 0.0;
}

void __cdecl CG_ArchiveState(struct MemoryFile *memFile) {
  char *v2; // esi

  v2 = (char *)cg;
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(
      a1, 4, &byte_2C5C4[(_DWORD)cg]);
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(a1, 4,
                                                                v2 + 181704);
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(
      a1, 4, (char *)&loc_2C5CC + (_DWORD)v2);
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(a1, 4,
                                                                v2 + 181696);
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(a1, 4,
                                                                v2 + 181712);
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(a1, 4,
                                                                v2 + 179656);
  ((void(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(a1, 1024,
                                                                v2 + 174588);
  return ((int(__cdecl *)(MemoryFile *, int, char *))a1->archiveProc)(
      a1, 256, v2 + 175612);
}

int __cdecl CG_ClientNumFromName(char const *) { UNIMPLEMENTED(); }

bool __cdecl CG_CheckPlayerForLowClip() {
  _DWORD *v0;       // ebx
  int v1;           // esi
  _DWORD *v2;       // eax
  int v3;           // esi
  int v5;           // ebx
  int v6;           // eax
  int AmmoClipSize; // eax
  float v8;         // xmm1_4
  char *v9;         // [esp+1Ch] [ebp-1Ch]

  v0 = cg;
  v9 = (char *)&loc_25BC4 + (_DWORD)cg;
  v1 = *((_DWORD *)cg + 44948);
  if (v1 < 0) {
    v2 = cg;
    goto LABEL_4;
  }
  if (v1 >= BG_GetNumWeapons() ||
      (v3 = v0[44948],
       (((int)v0[(v3 >> 5) + 38978] >> (v0[44948] & 0x1F)) & 1) == 0)) {
    v2 = cg;
  LABEL_4:
    v3 = v2[38694];
  }
  if (!v3)
    return 0;
  if (BG_WeaponIsClipOnly(v3))
    return 0;
  v5 = *(_DWORD *)&v9[4 * BG_ClipForWeapon(v3) + 836];
  if (v5 < 0)
    return 0;
  if (v5 >= 1000)
    v5 = 999;
  v6 = BG_ClipForWeapon(v3);
  AmmoClipSize = BG_GetAmmoClipSize(v6);
  if (AmmoClipSize <= 999) {
    if (AmmoClipSize <= 0)
      return 0;
    v8 = (float)AmmoClipSize;
  } else {
    v8 = 999.0;
  }
  return (float)(v8 * 0.33000001) >= (float)v5;
}

bool __cdecl CG_CheckPlayerForLowAmmo() {
  _DWORD *v0;           // ebx
  int v1;               // esi
  _DWORD *v2;           // eax
  int v3;               // esi
  int v5;               // ebx
  int TotalAmmoReserve; // esi
  int AmmoTypeMax;      // eax
  float v8;             // xmm1_4
  playerState_s *v9;    // [esp+1Ch] [ebp-1Ch]

  v0 = cg;
  v9 = (playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg);
  v1 = *((_DWORD *)cg + 44948);
  if (v1 < 0) {
    v2 = cg;
  } else {
    if (v1 < BG_GetNumWeapons()) {
      v3 = v0[44948];
      if ((((int)v0[(v3 >> 5) + 38978] >> (v0[44948] & 0x1F)) & 1) != 0)
        goto LABEL_5;
    }
    v2 = cg;
  }
  v3 = v2[38694];
LABEL_5:
  if (!v3)
    return 0;
  v5 = BG_AmmoForWeapon(v3);
  TotalAmmoReserve = BG_GetTotalAmmoReserve(v9, v3);
  if (TotalAmmoReserve >= 1000)
    TotalAmmoReserve = 999;
  AmmoTypeMax = BG_GetAmmoTypeMax(v5);
  if (AmmoTypeMax <= 999) {
    if (AmmoTypeMax < 0)
      return 0;
    v8 = (float)AmmoTypeMax;
  } else {
    v8 = 999.0;
  }
  return (float)(v8 * 0.2) >= (float)TotalAmmoReserve;
}

void __cdecl CG_DrawMenuShader(struct rectDef_s const *, struct Material *,
                               float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerCompassBack(struct rectDef_s const *rect,
                                      struct Material *material,
                                      float *const color) {
  int v3;        // esi
  _DWORD *v4;    // ebx
  _BOOL4 v5;     // eax
  float v6;      // xmm0_4
  float *result; // eax
  int *v8;       // eax
  float v9;      // [esp+30h] [ebp-28h]
  int v10;       // [esp+3Ch] [ebp-1Ch]

  v3 = hud_fade_compass;
  v9 = floorf((float)(1000.0 * *(float *)(hud_fade_compass + 8)) + 0.5);
  v4 = cg;
  v10 = *((_DWORD *)cg + 45424);
  v5 = (CL_GetKeyCatchers() & 8) != 0 &&
           !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
       !v4[44914];
  if (v5 || !*(_BYTE *)(hud_enable + 8))
    goto LABEL_6;
  if (*(float *)(v3 + 8) == 0.0) {
    v6 = 1.0;
  } else {
    v8 = CG_FadeColor(v10, (int)v9, 700);
    if (!v8) {
    LABEL_6:
      v6 = 0.0;
      goto LABEL_7;
    }
    v6 = *((float *)v8 + 3);
  }
LABEL_7:
  result = a3 + 3;
  a3[3] = v6;
  if (v6 != 0.0)
    return (float *)CL_DrawStretchPic(
        *(float *)&a1->x,
        *(float *)&a1->y -
            (float)(*(float *)&a1->h *
                    (float)(*(float *)(cg_hudCompassSize + 8) - 1.0)),
        *(float *)(cg_hudCompassSize + 8) * *(float *)&a1->w,
        *(float *)&a1->h * *(float *)(cg_hudCompassSize + 8), a1->horzAlign,
        a1->vertAlign, 0.0, 0.0, 1.0, 1.0, a3, a2);
  return result;
}

void __cdecl CG_ShowResponseHead(void) { UNIMPLEMENTED(); }

void __cdecl CG_AntiBurnInHUD_RegisterDvars() { UNIMPLEMENTED(); }

char const *__cdecl CG_GetTranslatedLocationString(int iLocation) {
  char *ConfigString; // eax
  char *v2;           // ebx
  const char *result; // eax

  ConfigString = CL_GetConfigString(a1 + 46);
  v2 = ConfigString;
  if (ConfigString && *ConfigString) {
    result = SEH_StringEd_GetString(ConfigString);
    if (result)
      return result;
  } else {
    v2 = "CGAME_UNKNOWN";
    result = SEH_StringEd_GetString("CGAME_UNKNOWN");
    if (result)
      return result;
  }
  if (*(_BYTE *)(loc_warnings + 8)) {
    if (*(_BYTE *)(loc_warningsAsErrors + 8))
      Com_Error(6, "Could not translate map location string \"%s\"", (char)v2);
    else
      Com_Printf("^3WARNING: Could not translate map location string \"%s\"\n",
                 v2);
    strcpy(CG_GetTranslatedLocationString(int)::szErrorString,
           "^1UNLOCALIZED(^7");
    I_strncat(CG_GetTranslatedLocationString(int)::szErrorString, 1024, v2);
    I_strncat(CG_GetTranslatedLocationString(int)::szErrorString, 1024,
              "^1)^7");
    return CG_GetTranslatedLocationString(int)::szErrorString;
  } else {
    I_strncpyz(CG_GetTranslatedLocationString(int)::szErrorString, v2, 1024);
    return CG_GetTranslatedLocationString(int)::szErrorString;
  }
}

void __cdecl CG_OwnerDraw(float x, float y, float w, float h, int horzAlign,
                          int vertAlign, float text_x, float text_y,
                          int ownerDraw, int ownerDrawFlags, int align,
                          float special, struct Font_s *font, float scale,
                          float *const color, struct Material *material,
                          int textStyle) {
  void *v17;                      // ebx
  int v18;                        // edx
  int v19;                        // ecx
  __m128 v20;                     // xmm2
  int v21;                        // esi
  int v22;                        // ebx
  _BOOL4 v23;                     // eax
  __m128 v24;                     // xmm3
  float v25;                      // xmm0_4
  int v26;                        // esi
  __m128 v27;                     // xmm1
  __m128 v28;                     // xmm1
  __m128 v29;                     // xmm0
  __m128 v30;                     // xmm0
  float v31;                      // xmm0_4
  float v32;                      // ecx
  float v33;                      // ebx
  float v34;                      // xmm3_4
  float v35;                      // edx
  float v36;                      // xmm0_4
  _DWORD *v37;                    // eax
  int v38;                        // edx
  float *v39;                     // ecx
  float v40;                      // xmm3_4
  float v41;                      // xmm0_4
  float v42;                      // xmm1_4
  _DWORD *v43;                    // ebx
  int v44;                        // esi
  int v45;                        // edi
  _BOOL4 v46;                     // eax
  float v47;                      // xmm0_4
  _DWORD *v48;                    // ebx
  int v49;                        // esi
  _BOOL4 v50;                     // eax
  float v51;                      // xmm0_4
  _DWORD *v52;                    // esi
  int v53;                        // ebx
  int v54;                        // ebx
  int v55;                        // esi
  _DWORD *v56;                    // ebx
  int v57;                        // edi
  _BOOL4 v58;                     // eax
  float v59;                      // xmm0_4
  int v60;                        // esi
  _DWORD *v61;                    // ebx
  int v62;                        // edi
  _BOOL4 v63;                     // eax
  int i;                          // esi
  int v65;                        // eax
  _DWORD *v66;                    // edi
  int v67;                        // ecx
  float *v68;                     // eax
  float v69;                      // xmm0_4
  float v70;                      // xmm1_4
  float v71;                      // xmm2_4
  float v72;                      // xmm2_4
  float v73;                      // xmm1_4
  float v74;                      // xmm0_4
  float v75;                      // xmm0_4
  int v76;                        // edx
  Material *v77;                  // eax
  __m128 v78;                     // xmm1
  int v79;                        // esi
  _DWORD *v80;                    // ebx
  int v81;                        // edi
  _BOOL4 v82;                     // eax
  int v83;                        // xmm0_4
  float v84;                      // edi
  float v85;                      // esi
  void *v86;                      // ebx
  int v87;                        // edx
  int v88;                        // ecx
  float v89;                      // xmm1_4
  int v90;                        // ecx
  int v91;                        // eax
  int v92;                        // edx
  int v93;                        // edx
  int v94;                        // ecx
  float v95;                      // xmm1_4
  int v96;                        // ecx
  int v97;                        // eax
  float v98;                      // xmm2_4
  int v99;                        // eax
  char *v100;                     // eax
  _DWORD *v101;                   // esi
  int *v102;                      // eax
  int v103;                       // ebx
  int v104;                       // ebx
  const char **v105;              // esi
  char *v106;                     // ebx
  float v107;                     // xmm1_4
  _DWORD *v108;                   // ebx
  int v109;                       // edi
  int v110;                       // esi
  _BOOL4 v111;                    // eax
  float v112;                     // xmm0_4
  _DWORD *v113;                   // esi
  int v114;                       // ebx
  int v115;                       // ebx
  const char **v116;              // esi
  char *v117;                     // eax
  char *v118;                     // eax
  char *TranslatedLocationString; // eax
  char *v120;                     // ebx
  float v121;                     // xmm1_4
  float v122;                     // xmm1_4
  float v123;                     // xmm0_4
  float v124;                     // xmm0_4
  float v125;                     // xmm2_4
  float v126;                     // xmm0_4
  float v127;                     // xmm3_4
  int *v128;                      // eax
  char *ConfigString;             // edx
  float v130;                     // xmm1_4
  int v131;                       // edx
  int v132;                       // edx
  int *v133;                      // eax
  int *v134;                      // eax
  int *v135;                      // eax
  int *v136;                      // eax
  int *v137;                      // eax
  int *v138;                      // eax
  float v139;                     // xmm1_4
  float *v140;                    // [esp+8h] [ebp-1A0h]
  float v141;                     // [esp+8h] [ebp-1A0h]
  Material *v142;                 // [esp+Ch] [ebp-19Ch]
  int v143;                       // [esp+10h] [ebp-198h]
  int v144;                       // [esp+10h] [ebp-198h]
  int v145;                       // [esp+14h] [ebp-194h]
  int v146;                       // [esp+14h] [ebp-194h]
  float v147;                     // [esp+3Ch] [ebp-16Ch]
  float v148;                     // [esp+3Ch] [ebp-16Ch]
  float v149;                     // [esp+84h] [ebp-124h]
  float v150;                     // [esp+88h] [ebp-120h]
  float v151;                     // [esp+8Ch] [ebp-11Ch]
  float v152;                     // [esp+90h] [ebp-118h]
  float v153;                     // [esp+94h] [ebp-114h]
  float v154;                     // [esp+98h] [ebp-110h]
  float v155;                     // [esp+9Ch] [ebp-10Ch]
  float v156;                     // [esp+A0h] [ebp-108h]
  int v157;                       // [esp+ACh] [ebp-FCh]
  float v158;                     // [esp+C0h] [ebp-E8h]
  float v159;                     // [esp+C8h] [ebp-E0h]
  float v160;                     // [esp+CCh] [ebp-DCh]
  float v161;                     // [esp+D0h] [ebp-D8h]
  float v162;                     // [esp+DCh] [ebp-CCh]
  float v163;                     // [esp+E0h] [ebp-C8h]
  float v164;                     // [esp+E4h] [ebp-C4h]
  float v165;                     // [esp+F8h] [ebp-B0h]
  float v166;                     // [esp+FCh] [ebp-ACh]
  float v167;                     // [esp+100h] [ebp-A8h]
  char __dst[64];                 // [esp+114h] [ebp-94h] BYREF
  rectDef_s v169;                 // [esp+154h] [ebp-54h] BYREF
  __int64 v170;                   // [esp+16Ch] [ebp-3Ch] BYREF
  __int64 v171;                   // [esp+174h] [ebp-34h]
  __int64 v172;                   // [esp+17Ch] [ebp-2Ch] BYREF
  float v173;                     // [esp+184h] [ebp-24h]
  float v174;                     // [esp+188h] [ebp-20h]
  float v175[7];                  // [esp+18Ch] [ebp-1Ch] BYREF

  v169.x = a2;
  v169.y = a3;
  v169.w = a4;
  v169.h = a5;
  v169.horzAlign = a6;
  v169.vertAlign = a7;
  switch (a10) {
  case 5:
  case 70:
    CG_DrawPlayerAmmoValue((int)&v169, a14, SHIDWORD(a15), *(float *)&a15);
    return;
  case 6:
    v43 = cg;
    if (!*((_DWORD *)cg + 38694))
      return;
    v44 = hud_fade_ammodisplay;
    v156 = floorf((float)(1000.0 * *(float *)(hud_fade_ammodisplay + 8)) + 0.5);
    v45 = v43[45426];
    v46 = (CL_GetKeyCatchers() & 8) != 0 &&
              !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
          !v43[44914];
    if (v46 || !*(_BYTE *)(hud_enable + 8))
      goto LABEL_33;
    if (*(float *)(v44 + 8) == 0.0) {
      v47 = 1.0;
    } else {
      v138 = CG_FadeColor(v45, (int)v156, 700);
      if (v138)
        v47 = *((float *)v138 + 3);
      else
      LABEL_33:
        v47 = 0.0;
    }
    v174 = v47;
    if (v47 != 0.0) {
      if (CG_CheckPlayerForLowAmmo()) {
        v172 = 0x3E3851EC3F63D70ALL;
        v173 = 0.0099999998;
      } else {
        v172 = *(_QWORD *)HIDWORD(a15);
        v173 = *(float *)(HIDWORD(a15) + 8);
      }
      UI_DrawHandlePic(*(float *)&v169.x, *(float *)&v169.y, *(float *)&v169.w,
                       *(float *)&v169.h, v169.horzAlign, v169.vertAlign,
                       (float *)&v172, a16);
    }
    return;
  case 20:
    CG_DrawPlayerStance(&v169, (float *)HIDWORD(a15),
                        __SPAIR64__(a15, (unsigned int)a14));
    return;
  case 27:
    CG_DrawScore(1, (int)&v169, a14, a1, *(float *)&a15);
    return;
  case 28:
    CG_DrawScore(0, (int)&v169, a14, a1, *(float *)&a15);
    return;
  case 33:
    if (*((_DWORD *)cg + 302 * *(_DWORD *)(*((_DWORD *)cg + 9) + 216) +
          229957)) {
      TranslatedLocationString = (char *)CG_GetTranslatedLocationString(
          *((_DWORD *)cg + 302 * *(_DWORD *)(*((_DWORD *)cg + 9) + 216) +
            229971));
      UI_DrawText(a1, TranslatedLocationString, 0x7FFFFFFF, a14,
                  *(float *)&v169.x, *(float *)&v169.y + *(float *)&v169.h,
                  v169.horzAlign, v169.vertAlign, *(float *)&a15);
    }
    return;
  case 34:
    v118 = (char *)cg + 1208 * *(_DWORD *)(*((_DWORD *)cg + 9) + 216);
    if (*((_DWORD *)v118 + 229957))
      CG_DrawTeamBackground(*(__int64 *)&v169.x, *(float *)&v169.w,
                            *(float *)&v169.h, *(float *)(HIDWORD(a15) + 12),
                            *((_DWORD *)v118 + 229968));
    return;
  case 39:
    UI_DrawText(a1, (char *)cgs + 24228, 0x7FFFFFFF, a14, *(float *)&v169.x,
                *(float *)&v169.y + *(float *)&v169.h, v169.horzAlign, a7,
                *(float *)&a15);
    return;
  case 50:
    if (*((_BYTE *)cg + 177484)) {
      v120 = va("Fragged by %s", (const char *)cg + 177484);
      v121 = (float)((float)(*(float *)&v169.w -
                             (float)UI_TextWidth(a1, v120, 0, a14,
                                                 *(float *)&a15)) *
                     0.5) +
             *(float *)&v169.x;
      UI_DrawText(a1, v120, 0x7FFFFFFF, a14, v121,
                  *(float *)&v169.y + *(float *)&v169.h, v169.horzAlign,
                  v169.vertAlign, *(float *)&a15);
    }
    return;
  case 67:
    v99 = *((_DWORD *)cgs + 6382);
    if (v99 != -9999)
      goto LABEL_133;
    return;
  case 68:
    v99 = *((_DWORD *)cgs + 6383);
    if (v99 != -9999) {
    LABEL_133:
      v100 = va("%2i", v99);
      UI_DrawText(a1, v100, 0x7FFFFFFF, a14, *(float *)&v169.x,
                  *(float *)&v169.y, v169.horzAlign, a7, *(float *)&a15);
    }
    return;
  case 71:
    CG_DrawHoldBreathHint(a1, &v169, a14, *(float *)&a15);
    return;
  case 72:
    CG_DrawCursorhint((int)&v169, a14, a1, *(float *)&a15);
    return;
  case 79:
    if (!*(_BYTE *)(cg_drawHealth + 8))
      return;
    v17 = cg;
    v18 = *(_DWORD *)(*((_DWORD *)cg + 9) + 312);
    if (v18 && (v19 = *(_DWORD *)(*((_DWORD *)cg + 9) + 320)) != 0 &&
        *(_DWORD *)(*((_DWORD *)cg + 9) + 16) != 6 &&
        (v20.f32[0] = (float)v18 / (float)v19, v20.f32[0] >= 0.0)) {
      if (v20.f32[0] > 1.0)
        v20.i32[0] = 1065353216;
    } else {
      v20.i32[0] = 0;
    }
    v21 = hud_fade_healthbar;
    v152 = floorf((float)(1000.0 * *(float *)(hud_fade_healthbar + 8)) + 0.5);
    v22 = *(_DWORD *)&byte_2C5C4[(_DWORD)v17];
    v20 = (__m128)v20.u32[0];
    v23 = (CL_GetKeyCatchers() & 8) != 0 &&
              (v20 = (__m128)v20.u32[0],
               !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI()) ||
          !*((_DWORD *)cg + 44914);
    if (v23 || !*(_BYTE *)(hud_enable + 8))
      goto LABEL_14;
    v24 = 0;
    if (*(float *)(v21 + 8) == 0.0) {
      v25 = 1.0;
    } else {
      v137 = CG_FadeColor(v22, (int)v152, 700);
      v20 = (__m128)v20.u32[0];
      if (v137) {
        v25 = *((float *)v137 + 3);
        v24 = 0;
      } else {
      LABEL_14:
        v24 = 0;
        v25 = 0.0;
      }
    }
    *(float *)(HIDWORD(a15) + 12) = v25;
    if (v25 == v24.f32[0])
      return;
    v26 = *((_DWORD *)cg + 9) + 12;
    v27 = v20;
    v27.f32[0] = v20.f32[0] - 1.0;
    v28 = _mm_cmpge_ss(v27, v24);
    v29 = v24;
    v29.f32[0] = v24.f32[0] - v20.f32[0];
    v30 = _mm_cmplt_ss(v29, v24);
    LODWORD(v31) =
        _mm_andnot_ps(v30, v24).u32[0] |
        (_mm_andnot_ps(v28, v20).u32[0] | v28.i32[0] & 0x3F800000) & v30.i32[0];
    if (v20.f32[0] > v24.f32[0]) {
      v32 = *(float *)&v169.x;
      v33 = *(float *)&v169.y;
      v34 = v20.f32[0] * *(float *)&v169.w;
      v35 = *(float *)&v169.h;
      if (v31 <= 0.5) {
        *(float *)(HIDWORD(a15) + 4) =
            (float)((float)(v31 + 0.2) * *(float *)(HIDWORD(a15) + 4)) +
            0.30000001;
      } else {
        v36 = (float)(1.0 - v31) + (float)(1.0 - v31);
        *(float *)HIDWORD(a15) = v36 * *(float *)HIDWORD(a15);
        *(float *)(HIDWORD(a15) + 8) = v36 * *(float *)(HIDWORD(a15) + 8);
      }
      CL_DrawStretchPic(v32, v33, v34, v35, v169.horzAlign, v169.vertAlign, 0.0,
                        0.0, v20.f32[0], 1.0, (const float *)HIDWORD(a15), a16);
    }
    v37 = cg;
    v38 = *(_DWORD *)(v26 + 204);
    if (*((_DWORD *)cg + 44929) != v38) {
      *((_DWORD *)cg + 44929) = v38;
    LABEL_22:
      v37[44930] = v20.i32[0];
      v37[44928] = 1;
      goto LABEL_23;
    }
    v130 = *((float *)cg + 44930);
    if (v130 <= v20.f32[0])
      goto LABEL_22;
    v131 = *((_DWORD *)cg + 44928);
    if (v131) {
      v132 = v131 - *((_DWORD *)cg + 38635);
      *((_DWORD *)cg + 44928) = v132;
      if (v132 < 0)
        v37[44928] = 0;
    } else {
      v139 = v130 - (float)((float)*((int *)cg + 38635) * 0.0012000001);
      *((float *)cg + 44930) = v139;
      if (v20.f32[0] >= v139)
        goto LABEL_22;
    }
  LABEL_23:
    v39 = (float *)cg;
    v40 = *((float *)cg + 44930);
    if (v40 > v20.f32[0]) {
      v41 = *(float *)&v169.w;
      v42 = (float)(v20.f32[0] * *(float *)&v169.w) + *(float *)&v169.x;
      *(_QWORD *)HIDWORD(a15) = 1065353216;
      *(_DWORD *)(HIDWORD(a15) + 8) = 0;
      CL_DrawStretchPic(v42, *(float *)&v169.y, v41 * (float)(v40 - v20.f32[0]),
                        *(float *)&v169.h, v169.horzAlign, v169.vertAlign,
                        v20.f32[0], 0.0, v39[44930], 1.0,
                        (const float *)HIDWORD(a15), a16);
    }
    return;
  case 80:
    CG_DrawMantleHint(a1, &v169, a14, *(float *)&a15);
    return;
  case 81:
    v101 = cg;
    v102 = CG_FadeColor(*((_DWORD *)cg + 44949), 1800, 700);
    if (v102) {
      v174 = *((float *)v102 + 3);
      v172 = *(_QWORD *)HIDWORD(a15);
      v173 = *(float *)(HIDWORD(a15) + 8);
      v103 = v101[44948];
      if (v103 < 0 || v103 >= BG_GetNumWeapons() ||
          (v104 = v101[44948],
           (((int)v101[(v104 >> 5) + 38978] >> (v101[44948] & 0x1F)) & 1) ==
               0)) {
        v104 = *((_DWORD *)cg + 38694);
      }
      if (v104) {
        v105 = (const char **)((char *)cg_weapons + 436 * v104);
        if (**(_BYTE **)(BG_GetWeaponDef(v104) + 112))
          v106 = va("%s / %s", v105[44], v105[45]);
        else
          v106 = va("%s", v105[44]);
        v107 = (float)((float)(*(float *)&v169.x + *(float *)&v169.w) -
                       (float)UI_TextWidth(a1, v106, 0, a14, *(float *)&a15)) -
               28.0;
        UI_DrawText(a1, v106, 0x7FFFFFFF, a14, v107, *(float *)&v169.y,
                    v169.horzAlign, v169.vertAlign, *(float *)&a15);
      }
    }
    return;
  case 82:
    v108 = cg;
    v109 = *((_DWORD *)cg + 44949);
    v110 = hud_fade_ammodisplay;
    v111 = (CL_GetKeyCatchers() & 8) != 0 &&
               !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
           !v108[44914];
    if (v111 || !*(_BYTE *)(hud_enable + 8))
      goto LABEL_151;
    if (*(float *)(v110 + 8) == 0.0) {
      v112 = 1.0;
    } else {
      v135 = CG_FadeColor(v109, 1800, 700);
      if (v135)
        v112 = *((float *)v135 + 3);
      else
      LABEL_151:
        v112 = 0.0;
    }
    v174 = v112;
    if (v112 != 0.0) {
      v172 = *(_QWORD *)HIDWORD(a15);
      v173 = *(float *)(HIDWORD(a15) + 8);
      v113 = cg;
      v114 = *((_DWORD *)cg + 44948);
      if (v114 < 0 || v114 >= BG_GetNumWeapons() ||
          (v115 = v113[44948],
           (((int)v113[(v115 >> 5) + 38978] >> (v113[44948] & 0x1F)) & 1) ==
               0)) {
        v115 = *((_DWORD *)cg + 38694);
      }
      if (v115) {
        v116 = (const char **)((char *)cg_weapons + 436 * v115);
        if (**(_BYTE **)(BG_GetWeaponDef(v115) + 112))
          v117 = va("%s / %s", v116[44], v116[45]);
        else
          v117 = va("%s", v116[44]);
        v141 = (float)((float)UI_TextWidth(a1, v117, 0, a14, *(float *)&a15) +
                       28.0) +
               8.0;
        UI_DrawHandlePic((float)(*(float *)&v169.x + *(float *)&v169.w) - v141,
                         *(float *)&v169.y, v141, *(float *)&v169.h,
                         v169.horzAlign, v169.vertAlign, (float *)&v172, a16);
      }
    }
    return;
  case 83:
    v48 = cg;
    v157 = *((_DWORD *)cg + 44949);
    v49 = hud_fade_ammodisplay;
    v50 = (CL_GetKeyCatchers() & 8) != 0 &&
              !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
          !v48[44914];
    if (v50 || !*(_BYTE *)(hud_enable + 8))
      goto LABEL_44;
    if (*(float *)(v49 + 8) == 0.0) {
      v51 = 1.0;
    } else {
      v136 = CG_FadeColor(v157, 1800, 700);
      if (v136)
        v51 = *((float *)v136 + 3);
      else
      LABEL_44:
        v51 = 0.0;
    }
    *(float *)(HIDWORD(a15) + 12) = v51;
    if (v51 != 0.0) {
      v52 = cg;
      v53 = *((_DWORD *)cg + 44948);
      if (v53 < 0 || v53 >= BG_GetNumWeapons() ||
          (v54 = v52[44948],
           (((int)v52[(v54 >> 5) + 38978] >> (v52[44948] & 0x1F)) & 1) == 0)) {
        v54 = *((_DWORD *)cg + 38694);
      }
      if (v54 && *((_DWORD *)cg_weapons + 109 * v54 + 79))
        UI_DrawHandlePic(*(float *)&v169.x, *(float *)&v169.y,
                         *(float *)&v169.w, *(float *)&v169.h, v169.horzAlign,
                         v169.vertAlign, (float *)HIDWORD(a15),
                         *((Material **)cg_weapons + 109 * v54 + 79));
    }
    return;
  case 84:
    v55 = hud_fade_compass;
    v155 = floorf((float)(1000.0 * *(float *)(hud_fade_compass + 8)) + 0.5);
    v56 = cg;
    v57 = *((_DWORD *)cg + 45424);
    v58 = (CL_GetKeyCatchers() & 8) != 0 &&
              !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
          !v56[44914];
    if (v58 || !*(_BYTE *)(hud_enable + 8))
      goto LABEL_58;
    if (*(float *)(v55 + 8) == 0.0) {
      v59 = 1.0;
    } else {
      v134 = CG_FadeColor(v57, (int)v155, 700);
      if (v134)
        v59 = *((float *)v134 + 3);
      else
      LABEL_58:
        v59 = 0.0;
    }
    *(float *)(HIDWORD(a15) + 12) = v59;
    if (v59 != 0.0) {
      v158 = *(float *)(cg_hudCompassSize + 8);
      CG_UpdateCompassOrientation();
      CG_DrawRotatedPic(
          *(float *)&v169.x,
          *(float *)&v169.y - (float)((float)(v158 - 1.0) * *(float *)&v169.h),
          v158 * *(float *)&v169.w, *(float *)&v169.h * v158, v169.horzAlign,
          v169.vertAlign, *(float *)((char *)&loc_2C5B0 + (_DWORD)cg));
    }
    return;
  case 85:
    CG_DrawPlayerCompassBack(&v169, a16, (float *)HIDWORD(a15));
    return;
  case 86:
    v60 = hud_fade_compass;
    v154 = floorf((float)(1000.0 * *(float *)(hud_fade_compass + 8)) + 0.5);
    v61 = cg;
    v62 = *((_DWORD *)cg + 45424);
    v63 = (CL_GetKeyCatchers() & 8) != 0 &&
              !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
          !v61[44914];
    if (v63 || !*(_BYTE *)(hud_enable + 8))
      return;
    if (*(float *)(v60 + 8) == 0.0) {
      v163 = 1.0;
    } else {
      v128 = CG_FadeColor(v62, (int)v154, 700);
      if (!v128)
        return;
      v163 = *((float *)v128 + 3);
      if (v163 == 0.0)
        return;
    }
    CG_UpdateCompPointerOrientation();
    v160 =
        (float)((float)(*(float *)(cg_hudCompassSize + 8) * *(float *)&v169.w) *
                0.5) +
        *(float *)&v169.x;
    v161 = (float)((float)((float)(0.5 * *(float *)(cg_hudCompassSize + 8)) *
                           *(float *)&v169.h) -
                   (float)(*(float *)&v169.h *
                           (float)(*(float *)(cg_hudCompassSize + 8) - 1.0))) +
           *(float *)&v169.y;
    if (*((_DWORD *)cg + 302 * *(_DWORD *)(*((_DWORD *)cg + 9) + 216) +
          229957)) {
      for (i = 0; i != 16; ++i) {
        v65 = *((_DWORD *)cg + 9);
        v66 = (_DWORD *)(28 * i + v65 + 1520);
        if (*v66 == 4) {
          v67 = *(_DWORD *)(28 * i + v65 + 1536);
          if (v67 == 1023) {
            v69 = *(float *)(28 * i + v65 + 1524);
            v70 = *(float *)(28 * i + v65 + 1528);
            v71 = *(float *)(28 * i + v65 + 1532);
          } else {
            v68 = (float *)((char *)cg_entities + 548 * v67);
            v69 = v68[123];
            v70 = v68[124];
            v71 = v68[125];
          }
          *(float *)&v172 = v69 - *((float *)cg + 41314);
          *((float *)&v172 + 1) = v70 - *((float *)cg + 41315);
          v173 = v71 - *((float *)cg + 41316);
          v147 = vectoyaw((const float *)&v172);
          v164 = AngleNormalize360(v147 - *((float *)cg + 45422));
          v72 = fsqrt((float)(*(float *)&v172 * *(float *)&v172) +
                      (float)(*((float *)&v172 + 1) * *((float *)&v172 + 1)));
          v170 = *(_QWORD *)HIDWORD(a15);
          v171 = *(_QWORD *)(HIDWORD(a15) + 8);
          v73 = *(float *)(cg_hudCompassMaxRange + 8);
          if (v73 < v72) {
            v123 = *(float *)(cg_hudObjectiveMaxRange + 8);
            if (v72 < v123) {
              v126 = v123 - v73;
              v127 = 0.0;
              if (v126 != 0.0)
                v127 = (float)(v72 - v73) / v126;
              *((float *)&v171 + 1) =
                  1.0 -
                  (float)((float)(1.0 -
                                  *(float *)(cg_hudObjectiveMinAlpha + 8)) *
                          v127);
            } else {
              HIDWORD(v171) = *(_DWORD *)(cg_hudObjectiveMinAlpha + 8);
            }
          } else {
            HIDWORD(v171) = 1065353216;
          }
          v74 = *(float *)(cg_hudCompassMinRange + 8);
          if (v74 < v72) {
            v122 = *(float *)(cg_hudCompassMaxRange + 8);
            if (v72 < v122) {
              v124 = v122 - v74;
              if (v124 == 0.0)
                v125 = 0.0;
              else
                v125 = (float)(v122 - v72) / v124;
              v175[0] =
                  1.0 -
                  (float)((float)(1.0 -
                                  *(float *)(cg_hudCompassMinRadius + 8)) *
                          v125);
            } else {
              v175[0] = 1.0;
            }
          } else {
            v175[0] = *(float *)(cg_hudCompassMinRadius + 8);
          }
          CG_ApplyCompassPointerRadiusScale(v175);
          v75 = v164 * 0.0174532925199433;
          v162 = 16.0 * *(float *)(cg_hudCompassSize + 8);
          v159 = v175[0];
          v148 = sinf(v75);
          v153 = cosf(v75);
          v76 = v66[6];
          if (v76 && (unsigned int)(v76 - 1) <= 0x7E &&
              (ConfigString = CL_GetConfigString(v76 + 1566), *ConfigString) &&
              strlen(ConfigString) <= 0x3F) {
            strcpy(__dst, ConfigString);
            v77 = (Material *)CL_RegisterMaterialNoMip(__dst, 7);
          } else {
            v77 = (Material *)*((_DWORD *)cgs + 12058);
          }
          v78 = _mm_cmplt_ss((__m128)LODWORD(v163), (__m128)HIDWORD(v171));
          HIDWORD(v171) = _mm_andnot_ps(v78, (__m128)HIDWORD(v171)).u32[0] |
                          LODWORD(v163) & v78.i32[0];
          UI_DrawHandlePic(
              (float)(v160 + (float)(v162 * -0.5)) - (float)(v148 * v159),
              (float)(v161 + (float)(v162 * -0.5)) - (float)(v153 * v159), v162,
              v162, v169.horzAlign, v169.vertAlign, (float *)&v170, v77);
        }
      }
    }
    return;
  case 89:
    CG_DrawCompassFriendlies(&v169, a16, (float *)HIDWORD(a15));
    return;
  case 94:
    CL_DrawStretchPic(*(float *)&v169.x, *(float *)&v169.y, *(float *)&v169.w,
                      *(float *)&v169.h, v169.horzAlign, a7, 0.0, 0.0, 1.0, 1.0,
                      (const float *)HIDWORD(a15), a16);
    return;
  case 95:
    if (!*(_BYTE *)(cg_drawHealth + 8))
      return;
    v82 = (v79 = hud_fade_healthbar,
           v151 = floorf((float)(1000.0 * *(float *)(hud_fade_healthbar + 8)) +
                         0.5),
           v80 = cg, v81 = *(_DWORD *)&byte_2C5C4[(_DWORD)cg],
           (CL_GetKeyCatchers() & 8) != 0) &&
              !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
          !v80[44914];
    if (v82 || !*(_BYTE *)(hud_enable + 8))
      return;
    if (*(float *)(v79 + 8) == 0.0) {
      v167 = 1.0;
      v83 = 1065353216;
    } else {
      v133 = CG_FadeColor(v81, (int)v151, 700);
      if (!v133)
        return;
      v167 = *((float *)v133 + 3);
      if (v167 == 0.0)
        return;
      v83 = v133[3];
    }
    *(_DWORD *)(HIDWORD(a15) + 12) = v83;
    v165 = *(float *)&v169.x;
    v166 = *(float *)&v169.y;
    v84 = *(float *)&v169.w;
    v85 = *(float *)&v169.h;
    CL_DrawStretchPic(*(float *)&v169.x, *(float *)&v169.y, *(float *)&v169.w,
                      *(float *)&v169.h, v169.horzAlign, v169.vertAlign, 0.0,
                      0.0, 1.0, 1.0, (const float *)HIDWORD(a15), a16);
    v86 = cg;
    v87 = *(_DWORD *)(*((_DWORD *)cg + 9) + 312);
    if (v87) {
      v88 = *(_DWORD *)(*((_DWORD *)cg + 9) + 320);
      if (v88) {
        if (*(_DWORD *)(*((_DWORD *)cg + 9) + 16) != 6) {
          v89 = (float)v87 / (float)v88;
          if (v89 >= 0.0) {
            if (v89 <= 1.0) {
              if (v89 == 0.0)
                return;
            } else {
              v89 = 1.0;
            }
            if (*(float *)(hud_health_startpulse_critical + 8) > v89) {
              v150 = floorf(
                  (float)(1000.0 *
                          *(float *)(hud_health_pulserate_critical + 8)) +
                  0.5);
              v90 = (int)v150;
            } else {
              if (*(float *)(hud_health_startpulse_injured + 8) <= v89)
                return;
              v149 =
                  floorf((float)(1000.0 *
                                 *(float *)(hud_health_pulserate_injured + 8)) +
                         0.5);
              v90 = (int)v149;
            }
            if (v90) {
              v91 = *(_DWORD *)((char *)&loc_2BDFC + (_DWORD)v86);
              v92 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v86);
              if (v91 > v92 || v92 > v90 + v91)
                *(_DWORD *)((char *)&loc_2BDFC + (_DWORD)v86) = v92;
              *(_DWORD *)HIDWORD(a15) = 1063507722;
              *(_DWORD *)(HIDWORD(a15) + 4) = 1043878380;
              *(_DWORD *)(HIDWORD(a15) + 8) = 1008981770;
              *(float *)(HIDWORD(a15) + 12) = fminf(
                  v167,
                  (float)(*(_DWORD *)((char *)&loc_2BDFC + (_DWORD)cg) + v90 -
                          *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg)) /
                      (float)v90);
              CL_DrawStretchPic(v165, v166, v84, v85, v169.horzAlign,
                                v169.vertAlign, 0.0, 0.0, 1.0, 1.0,
                                (const float *)HIDWORD(a15), a16);
            }
          }
        }
      }
    }
    return;
  case 100:
    v143 = 1;
    v142 = a16;
    v140 = (float *)HIDWORD(a15);
    goto LABEL_108;
  case 101:
    v143 = 2;
    v142 = a16;
    v140 = (float *)HIDWORD(a15);
  LABEL_108:
    CG_DrawOffHandIcon(&v169, *(float *)&a15, v140, v142, v143);
    return;
  case 102:
    v145 = 1;
    goto LABEL_111;
  case 103:
    v145 = 2;
  LABEL_111:
    CG_DrawOffHandAmmo(&v169, a14, *(float *)&a15, (float *)HIDWORD(a15),
                       (int)a17, v145);
    return;
  case 104:
    v146 = 1;
    goto LABEL_114;
  case 105:
    v146 = 2;
  LABEL_114:
    CG_DrawOffHandName(&v169, a14, *(float *)&a15, (float *)HIDWORD(a15),
                       (int)a17, v146);
    return;
  case 106:
    v144 = 1;
    goto LABEL_117;
  case 107:
    v144 = 2;
  LABEL_117:
    CG_DrawOffHandHighlight(&v169, *(float *)&a15, (float *)HIDWORD(a15), a16,
                            v144);
    return;
  case 109:
    v93 = *(_DWORD *)(*((_DWORD *)cg + 9) + 312);
    if (!v93)
      return;
    v94 = *(_DWORD *)(*((_DWORD *)cg + 9) + 320);
    if (!v94)
      return;
    if (*(_DWORD *)(*((_DWORD *)cg + 9) + 16) == 6)
      return;
    v95 = (float)v93 / (float)v94;
    if (v95 < 0.0)
      return;
    if (v95 <= 1.0) {
      if (v95 == 0.0)
        return;
    } else {
      v95 = 1.0;
    }
    CG_PulseLowHealthOverlay(v95);
    v96 =
        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - *((_DWORD *)cg + 44933);
    if (v96 < 0)
      v96 = 0;
    v97 = *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)cg);
    if (v97 <= 0 || v96 >= v97)
      v98 = *((float *)cg + 44932);
    else
      v98 = (float)((float)((float)v96 / (float)v97) *
                    (float)(*((float *)cg + 44932) - *((float *)cg + 44931))) +
            *((float *)cg + 44931);
    *(float *)(HIDWORD(a15) + 12) = v98;
    if (v98 != 0.0)
      CL_DrawStretchPic(*(float *)&v169.x, *(float *)&v169.y, *(float *)&v169.w,
                        *(float *)&v169.h, v169.horzAlign, v169.vertAlign, 0.0,
                        0.0, 1.0, 1.0, (const float *)HIDWORD(a15), a16);
    return;
  default:
    return;
  }
}

struct dvar_s const *const hud_health_pulserate_injured;
struct dvar_s const *const hud_health_startpulse_critical;
struct dvar_s const *const hud_fade_offhand;
struct dvar_s const *const hud_deathQuoteFadeTime;
struct dvar_s const *const hud_fade_ammodisplay;
struct dvar_s const *const hud_health_startpulse_injured;
struct dvar_s const *const hud_fade_stance;
struct dvar_s const *const hud_fade_compass;
struct dvar_s const *const hud_health_pulserate_critical;
struct dvar_s const *const hud_fade_healthbar;
void __cdecl CG_DrawAreaWeapons(struct rectDef_s *, int, float, float,
                                float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawAreaHoldable(struct rectDef_s *, int, float, float,
                                 float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateCursorHints(void) { UNIMPLEMENTED(); }

float __cdecl CG_FadeLowHealthOverlay(void) { UNIMPLEMENTED(); }

void __cdecl CalcCompassPointerSize(float *, float *) { UNIMPLEMENTED(); }

void __cdecl CalcSplitScreenStanceOffset(float *, float *) { UNIMPLEMENTED(); }

void __cdecl CalcSplitScreenStanceScale(float *, float *) { UNIMPLEMENTED(); }

int __cdecl CG_GetSelectedWeaponIndex(void) { UNIMPLEMENTED(); }

void __cdecl CG_CalcCompassDimensions(struct rectDef_s const *, float *,
                                      float *, float *, float *) {
  UNIMPLEMENTED();
}

void __cdecl CG_PulseLowHealthOverlay(float) {
  _DWORD *v1;      // edx
  int result;      // eax
  _DWORD *v3;      // esi
  unsigned int v4; // edi
  __m128 v5;       // xmm0
  __m128 v6;       // xmm1
  __m128 v7;       // xmm1
  __m128 v8;       // xmm2
  __m128 v9;       // xmm0
  __m128 v10;      // xmm0
  __m128 v11;      // xmm1
  __m128 v12;      // xmm1
  __m128 v13;      // xmm2
  __m128 v14;      // xmm0
  __m128 v15;      // xmm0
  __m128 v16;      // xmm1
  __m128 v17;      // xmm1
  __m128 v18;      // xmm2
  __m128 v19;      // xmm0
  int v20;         // ebx

  v1 = cg;
  if (*(float *)((char *)&loc_2BE28 + (_DWORD)cg) > a1) {
    if (*(float *)(hud_healthOverlay_pulseStart + 8) > a1) {
      *((_DWORD *)cg + 44937) = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
      v1[44939] = 0;
    }
    v1 = cg;
  }
  *(float *)((char *)&loc_2BE28 + (_DWORD)v1) = a1;
  result = *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)v1) + v1[44933];
  if (result <= *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v1)) {
    result = hud_healthOverlay_pulseStart;
    if (*(float *)(hud_healthOverlay_pulseStart + 8) > a1) {
      if (!*((_BYTE *)v1 + 179744))
        *((_BYTE *)v1 + 179744) = 1;
    } else if (!*((_BYTE *)v1 + 179744)) {
      return result;
    }
    v3 = cg;
    *((_DWORD *)cg + 44933) = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    v3[44931] = v3[44932];
    v4 = v3[44939];
    if (v4 > 3) {
      *((_BYTE *)v3 + 179744) = 0;
      v3[44932] = *(_DWORD *)(hud_healthOverlay_phaseEnd_toAlpha + 8);
      result = *(_DWORD *)(hud_healthOverlay_phaseEnd_pulseDuration + 8);
      *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)v3) = result;
      *(_DWORD *)((char *)&locret_2BE1C + (_DWORD)v3) = 0;
    } else {
      result = *(_DWORD *)((char *)&locret_2BE1C + (_DWORD)v3);
      switch (result) {
      case 1:
        v10 = (__m128)(unsigned int)pulseMags_126348[v4];
        v10.f32[0] =
            v10.f32[0] *
            *(float *)(hud_healthOverlay_phaseTwo_toAlphaMultiplier + 8);
        v11 = v10;
        v11.f32[0] = v10.f32[0] - 1.0;
        v12 = _mm_cmpge_ss(v11, (__m128)0LL);
        v12.i32[0] = _mm_andnot_ps(v12, v10).u32[0] | v12.i32[0] & 0x3F800000;
        v13 = 0;
        v13.f32[0] = 0.0 - v10.f32[0];
        v14 = _mm_cmplt_ss(v13, (__m128)0LL);
        v3[44932] =
            _mm_andnot_ps(v14, (__m128)0LL).u32[0] | v12.i32[0] & v14.i32[0];
        result = *(_DWORD *)(hud_healthOverlay_phaseTwo_pulseDuration + 8);
        *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)v3) = result;
        *(_DWORD *)((char *)&locret_2BE1C + (_DWORD)v3) = 2;
        break;
      case 2:
        v15 = (__m128)(unsigned int)pulseMags_126348[v4];
        v15.f32[0] =
            v15.f32[0] *
            *(float *)(hud_healthOverlay_phaseThree_toAlphaMultiplier + 8);
        v16 = v15;
        v16.f32[0] = v15.f32[0] - 1.0;
        v17 = _mm_cmpge_ss(v16, (__m128)0LL);
        v17.i32[0] = _mm_andnot_ps(v17, v15).u32[0] | v17.i32[0] & 0x3F800000;
        v18 = 0;
        v18.f32[0] = 0.0 - v15.f32[0];
        v19 = _mm_cmplt_ss(v18, (__m128)0LL);
        v3[44932] =
            _mm_andnot_ps(v19, (__m128)0LL).u32[0] | v17.i32[0] & v19.i32[0];
        v20 = hud_healthOverlay_phaseThree_pulseDuration;
        *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)v3) =
            *(_DWORD *)(hud_healthOverlay_phaseThree_pulseDuration + 8);
        *(_DWORD *)((char *)&locret_2BE1C + (_DWORD)v3) = 0;
        result =
            3 * (*(_DWORD *)(v20 + 8) +
                 *(_DWORD *)(hud_healthOverlay_phaseTwo_pulseDuration + 8) +
                 *(_DWORD *)(hud_healthOverlay_phaseOne_pulseDuration + 8));
        if (*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v3) >=
            *(_DWORD *)(hud_healthOverlay_regenPauseTime + 8) + v3[44937] -
                result) {
          result = v4 + 1;
          v3[44939] = v4 + 1;
        }
        break;
      case 0:
        v5 = (__m128)(unsigned int)pulseMags_126348[v4];
        v6 = v5;
        v6.f32[0] = v5.f32[0] - 1.0;
        v7 = _mm_cmpge_ss(v6, (__m128)0LL);
        v7.i32[0] = _mm_andnot_ps(v7, v5).u32[0] | v7.i32[0] & 0x3F800000;
        v8 = 0;
        v8.f32[0] = 0.0 - v5.f32[0];
        v9 = _mm_cmplt_ss(v8, (__m128)0LL);
        v3[44932] =
            _mm_andnot_ps(v9, (__m128)0LL).u32[0] | v7.i32[0] & v9.i32[0];
        result = *(_DWORD *)(hud_healthOverlay_phaseOne_pulseDuration + 8);
        *(_DWORD *)((char *)&loc_2BE18 + (_DWORD)v3) = result;
        *(_DWORD *)((char *)&locret_2BE1C + (_DWORD)v3) = 1;
        break;
      }
    }
  }
  return result;
}

void __cdecl CG_DrawPlayerLowHealthOverlay(struct rectDef_s const *,
                                           struct Material *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerBarHealthBack(struct rectDef_s const *,
                                        struct Material *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerBarHealth(struct rectDef_s const *, struct Material *,
                                    float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawGameType(struct rectDef_s const *, struct Font_s *, float,
                             float *const, struct Material *, int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawTeamScore(int, struct rectDef_s *, struct Font_s *, float,
                              float *const, struct Material *, int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawKiller(struct rectDef_s const *, struct Font_s *, float,
                           float *const, struct Material *, int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawScore(int, struct rectDef_s const *, struct Font_s *, float,
                          float *const, struct Material *, int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerCompassPointers(struct rectDef_s const *,
                                          struct Material *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawStanceIcon(struct rectDef_s const *, float *const, float,
                               float, float) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerWeaponModeIcon(struct rectDef_s const *,
                                         float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerWeaponNameBack(struct rectDef_s const *,
                                         struct Font_s *, float, float *const,
                                         struct Material *) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerWeaponName(struct rectDef_s const *, struct Font_s *,
                                     float, float *const, int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerAmmoValue(struct rectDef_s const *, struct Font_s *,
                                    float, float *const, struct Material *, int,
                                    int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerAmmoBackdrop(struct rectDef_s const *, float *const,
                                       struct Material *) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawTeamColor(struct rectDef_s const *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerCompass(struct rectDef_s const *, struct Material *,
                                  float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawMantleHint(struct rectDef_s const *, struct Font_s *, float,
                               int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawHoldBreathHint(struct rectDef_s const *, struct Font_s *,
                                   float, int) {
  UNIMPLEMENTED();
}

char const *__cdecl CG_GetUseString(void) { UNIMPLEMENTED(); }

char const *__cdecl CG_GetWeaponUseString(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawPlayerStance(struct rectDef_s const *, float *const,
                                 struct Font_s *, float, int) {
  int v3;          // esi
  long double v4;  // fst7
  _DWORD *v5;      // ebx
  int v6;          // edi
  int result;      // eax
  _DWORD *v8;      // eax
  _DWORD *v9;      // ecx
  int v10;         // eax
  _DWORD *v11;     // edi
  float v12;       // edi
  float v13;       // esi
  int v14;         // eax
  Material *v15;   // eax
  void *v16;       // ebx
  char *v17;       // ebx
  int v18;         // esi
  float v19;       // xmm0_4
  int v20;         // edx
  int v21;         // ecx
  char **i;        // eax
  int v23;         // eax
  char *v24;       // ebx
  _BYTE *v25;      // esi
  _BYTE *v26;      // edi
  int v27;         // eax
  int v28;         // eax
  __m128 v29;      // xmm1
  int j;           // esi
  char *v31;       // eax
  char *v32;       // eax
  char *v33;       // eax
  long double v34; // [esp+0h] [ebp-298h]
  char **v35;      // [esp+38h] [ebp-260h]
  int v36;         // [esp+3Ch] [ebp-25Ch]
  _DWORD *v37;     // [esp+44h] [ebp-254h]
  float v38;       // [esp+50h] [ebp-248h]
  float v39;       // [esp+54h] [ebp-244h]
  float v40;       // [esp+58h] [ebp-240h]
  float v41;       // [esp+5Ch] [ebp-23Ch]
  int v42;         // [esp+64h] [ebp-234h]
  int v43;         // [esp+68h] [ebp-230h]
  float v44;       // [esp+6Ch] [ebp-22Ch]
  float v45;       // [esp+70h] [ebp-228h]
  int v46;         // [esp+74h] [ebp-224h]
  _BYTE *v47;      // [esp+78h] [ebp-220h]
  int v48;         // [esp+7Ch] [ebp-21Ch]
  char v49[256];   // [esp+80h] [ebp-218h] BYREF
  _BYTE v50[72];   // [esp+180h] [ebp-118h] BYREF
  _BYTE __dst[72]; // [esp+1C8h] [ebp-D0h] BYREF
  _BYTE v52[72];   // [esp+210h] [ebp-88h] BYREF
  float v53[3];    // [esp+258h] [ebp-40h] BYREF
  char *__src[3];  // [esp+264h] [ebp-34h]
  char *v55;       // [esp+270h] [ebp-28h]
  _BYTE v56[36];   // [esp+274h] [ebp-24h] BYREF

  v3 = hud_fade_stance;
  v4 = floorf((float)(1000.0 * *(float *)(hud_fade_stance + 8)) + 0.5);
  v5 = cg;
  v6 = *(_DWORD *)((char *)&loc_2C5CC + (_DWORD)cg);
  result = (CL_GetKeyCatchers() & 8) != 0 &&
               !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI() ||
           !v5[44914];
  if (result)
    return result;
  result = hud_enable;
  if (!*(_BYTE *)(hud_enable + 8))
    return result;
  if (*(float *)(v3 + 8) == 0.0) {
    v41 = 1.0;
  } else {
    v38 = v4;
    result = (int)CG_FadeColor(v6, (int)v38, 700);
    if (!result)
      return result;
    v41 = *(float *)(result + 12);
    if (v41 == 0.0)
      return result;
  }
  if (*(_BYTE *)(cg_hudStanceHintPrints + 8)) {
    if (*((_DWORD *)cg + 44941) != (*((_DWORD *)cg + 38644) & 3))
      *(_DWORD *)((char *)&loc_2BE38 + (_DWORD)cg) =
          *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    v9 = cg;
  } else {
    v8 = cg;
    *(_DWORD *)((char *)&loc_2BE38 + (_DWORD)cg) = 0;
    v9 = v8;
  }
  v9[44941] = v9[38644] & 3;
  v39 = (float)((float)((float)(*(float *)(cg_hudCompassSize + 8) - 1.0) *
                        *((float *)cgs + 12418)) *
                0.69999999) +
        *(float *)&a1->x;
  v40 = *(float *)&a1->y;
  v53[0] = *a2;
  v53[1] = a2[1];
  v53[2] = a2[2];
  if ((*((_BYTE *)v9 + 154578) & 1) != 0) {
    v10 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v9);
    if (v9[44940] < v10)
      v9[44940] = v10 + 1500;
    v11 = cg;
    if (*((_DWORD *)cg + 44940) <= *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg))
      goto LABEL_14;
  } else {
    v11 = v9;
    if (v9[44940] <= *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v9))
      goto LABEL_14;
  }
  v17 = (char *)UI_SafeTranslateString("CGAME_PRONE_BLOCKED");
  v18 = UI_TextWidth(v4, v17, 0, (Font_s *)a3, *((float *)&a3 + 1));
  *(double *)&v34 =
      (float)((float)((float)(v11[44940] -
                              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v11)) /
                      1500.0) *
              540.0) *
      0.0174532925199433;
  v4 = sin(v34);
  v19 = v4;
  __src[0] = COERCE_CHAR_(fabs(v19));
  UI_DrawText(v4, v17, 0x7FFFFFFF, (Font_s *)a3, -(float)((float)v18 * 0.5),
              *(float *)(cg_hudProneY + 8), 7, 3, *((float *)&a3 + 1));
LABEL_14:
  if (*(_BYTE *)(cg_hudStanceHintPrints + 8) &&
      *(_DWORD *)((char *)&loc_2BE38 + (_DWORD)v11) + 3000 >
          *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v11)) {
    memcpy(__dst,
           &CG_DrawPlayerStance(rectDef_s const *, float *, Font_s *, float,
                                int)::C .180,
           sizeof(__dst));
    memcpy(v52,
           &CG_DrawPlayerStance(rectDef_s const *, float *, Font_s *, float,
                                int)::C .181,
           sizeof(v52));
    memcpy(v50,
           &CG_DrawPlayerStance(rectDef_s const *, float *, Font_s *, float,
                                int)::C .182,
           sizeof(v50));
    __src[1] = "PLATFORM_STANCEHINT_STAND";
    __src[2] = "PLATFORM_STANCEHINT_CROUCH";
    v55 = "PLATFORM_STANCEHINT_PRONE";
    Controls_GetConfig();
    v20 = *(_DWORD *)((char *)&loc_2BE38 + (_DWORD)v11);
    v21 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v11);
    if (v20 + 2000 <= v21)
      *(float *)__src = (float)(v20 - v21 + 3000) / 1000.0;
    else
      __src[0] = (char *)1065353216;
    v44 = (float)UI_TextHeight(v4, (Font_s *)a3, *((float *)&a3 + 1));
    v43 = 0;
    v42 = 0;
    v48 = 0;
    v37 = cg;
    v36 = 0;
    v35 = (char **)v56;
    for (i = (char **)v56;; i = v35) {
      *i = 0;
      v23 = v37[44941];
      if ((v23 & 1) != 0) {
        v24 = *(char **)&v50[v48];
      } else if ((v23 & 2) != 0) {
        v24 = *(char **)&v52[v48];
      } else {
        v24 = *(char **)&__dst[v48];
      }
      if (v24) {
        v47 = &__dst[v36];
        v25 = &v50[v36];
        v26 = &v52[v36];
        v46 = 6;
        while (1) {
          LOBYTE(v27) = GetCommandHasBinding(v24);
          if (v27)
            break;
          v28 = *((_DWORD *)cg + 44941);
          if ((v28 & 1) != 0) {
            v24 = (char *)*((_DWORD *)v25 + 1);
          } else if ((v28 & 2) != 0) {
            v24 = (char *)*((_DWORD *)v26 + 1);
          } else {
            v24 = (char *)*((_DWORD *)v47 + 1);
          }
          if (--v46) {
            v47 += 4;
            v25 += 4;
            v26 += 4;
            if (v24)
              continue;
          }
          goto LABEL_47;
        }
        *v35 = v24;
        ++v43;
      }
    LABEL_47:
      ++v42;
      ++v35;
      v36 += 24;
      v48 += 24;
      if (v42 == 3)
        break;
    }
    v45 = (float)((float)(*(float *)&a1->h * 0.5) + *(float *)&a1->y) - 1.5;
    if (v43 == 1) {
      v45 = (float)(0.5 * v44) + v45;
    } else if (v43 == 3) {
      v45 =
          (float)((float)((float)(*(float *)&a1->h * 0.5) + *(float *)&a1->y) -
                  1.5) -
          (float)((float)(0.5 * v44) + 1.5);
    }
    v29 = _mm_cmplt_ss((__m128)LODWORD(v41), (__m128)(unsigned int)__src[0]);
    __src[0] =
        (char *)(_mm_andnot_ps(v29, (__m128)(unsigned int)__src[0]).u32[0] |
                 LODWORD(v41) & v29.i32[0]);
    for (j = 1; j != 4; ++j) {
      v31 = *(char **)&v56[4 * j - 4];
      if (v31) {
        GetKeyBindingLocalizedString(v31, v49);
        v32 = (char *)UI_SafeTranslateString(__src[j]);
        v33 = UI_ReplaceConversionString(v32, v49);
        UI_DrawText(v4, v33, 0x7FFFFFFF, (Font_s *)a3, v39 + *(float *)&a1->w,
                    v45, a1->horzAlign, a1->vertAlign, *((float *)&a3 + 1));
        v45 = (float)(v44 + 1.5) + v45;
      }
    }
  }
  __src[0] = (char *)LODWORD(v41);
  v12 = *(float *)&a1->w;
  v13 = *(float *)&a1->h;
  v14 = *((_DWORD *)cg + 44941);
  if ((v14 & 1) != 0) {
    v15 = (Material *)*((_DWORD *)cgs + 12056);
  } else if ((v14 & 2) != 0) {
    v15 = (Material *)*((_DWORD *)cgs + 12055);
  } else {
    v15 = (Material *)*((_DWORD *)cgs + 12054);
  }
  UI_DrawHandlePic(v39, v40, v12, v13, a1->horzAlign, a1->vertAlign, v53, v15);
  v16 = cg;
  result = *(_DWORD *)((char *)&loc_2BE38 + (_DWORD)cg) + 1000;
  if (result > *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg)) {
    Dvar_GetUnpackedColor((const dvar_s *)cg_hudStanceFlash, v53);
    __src[0] = COERCE_CHAR_(fminf(
        v41,
        (float)((float)(*(_DWORD *)((char *)&loc_2BE38 + (_DWORD)v16) -
                        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v16) + 1000) /
                1000.0) *
            0.80000001));
    return UI_DrawHandlePic(v39, v40, v12, v13, a1->horzAlign, a1->vertAlign,
                            v53, *((Material **)cgs + 12057));
  }
  return result;
}

void __cdecl CG_DrawCursorhint(struct rectDef_s const *, struct Font_s *, float,
                               int) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawPlayerLocation(struct rectDef_s const *, struct Font_s *,
                                   float, float *const, int) {
  UNIMPLEMENTED();
}
