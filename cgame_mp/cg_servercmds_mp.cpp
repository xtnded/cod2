bool __cdecl CG_XuidExistsInArray(unsigned __int64, unsigned __int64 const *,
                                  int) {
  UNIMPLEMENTED();
}

void __cdecl CG_HudMenuShowAllTimed(void) { UNIMPLEMENTED(); }

void __cdecl CG_MenuShowNotify(int menuToShow) {
  windowDef_t *result; // eax
  int v2;              // edx
  int v3;              // edx
  int v4;              // edx
  int v5;              // edx
  int v6;              // edx
  int v7;              // edx

  result = a1;
  switch ((unsigned int)a1->rect) {
  case 0u:
    result = (windowDef_t *)cg;
    v3 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (*(_DWORD *)&byte_2C5C4[(_DWORD)cg] < v3) {
      *(_DWORD *)&byte_2C5C4[(_DWORD)cg] = v3;
      if (CL_GetLocalClientActiveCount() == 1)
        result = (windowDef_t *)Menus_FindByName(&cgDC, "Health");
      else
        result = (windowDef_t *)Menus_FindByName(&cgDC, "Health_mp");
      goto LABEL_5;
    }
    break;
  case 1u:
    CG_MenuShowNotify(4);
    result = (windowDef_t *)cg;
    v2 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (*((_DWORD *)cg + 45426) < v2) {
      *((_DWORD *)cg + 45426) = v2;
      if (CL_GetLocalClientActiveCount() == 1)
        result = (windowDef_t *)Menus_FindByName(&cgDC, "weaponinfo");
      else
        result = (windowDef_t *)Menus_FindByName(&cgDC, "weaponinfo_mp");
      goto LABEL_5;
    }
    break;
  case 2u:
    result = (windowDef_t *)cg;
    v7 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (*((_DWORD *)cg + 45424) < v7) {
      *((_DWORD *)cg + 45424) = v7;
      if (CL_GetLocalClientActiveCount() == 1)
        result = (windowDef_t *)Menus_FindByName(&cgDC, "Compass");
      else
        result = (windowDef_t *)Menus_FindByName(&cgDC, "Compass_mp");
      goto LABEL_5;
    }
    break;
  case 3u:
    result = (windowDef_t *)cg;
    v6 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (*(_DWORD *)((char *)&loc_2C5CC + (_DWORD)cg) < v6) {
      *(_DWORD *)((char *)&loc_2C5CC + (_DWORD)cg) = v6;
      if (CL_GetLocalClientActiveCount() == 1)
        result = (windowDef_t *)Menus_FindByName(&cgDC, "stance");
      else
        result = (windowDef_t *)Menus_FindByName(&cgDC, "stance_mp");
      goto LABEL_5;
    }
    break;
  case 4u:
    result = (windowDef_t *)cg;
    v5 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (*((_DWORD *)cg + 45428) < v5) {
      *((_DWORD *)cg + 45428) = v5;
      if (CL_GetLocalClientActiveCount() == 1)
        result = (windowDef_t *)Menus_FindByName(&cgDC, "offhandinfo");
      else
        result = (windowDef_t *)Menus_FindByName(&cgDC, "offhandinfo_mp");
      goto LABEL_5;
    }
    break;
  case 5u:
    result = (windowDef_t *)cg;
    v4 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (*((_DWORD *)cg + 44366) < v4) {
      *((_DWORD *)cg + 44366) = v4;
      result = (windowDef_t *)Menus_FindByName(&cgDC, "objectiveinfo");
    LABEL_5:
      if (result)
        result = (windowDef_t *)Window_AddDynamicFlags(result, 4);
    }
    break;
  default:
    return result;
  }
  return result;
}

void __cdecl CG_ParseFog() {
  char *v0;     // eax
  float v1;     // xmm0_4
  char *v2;     // eax
  char *v4;     // eax
  char *v5;     // eax
  char *v6;     // eax
  char *v7;     // eax
  char *v8;     // eax
  float v9;     // xmm0_4
  float v10;    // xmm0_4
  float v11;    // xmm0_4
  float v12;    // xmm0_4
  float v13;    // [esp+2Ch] [ebp-5Ch]
  float v14;    // [esp+30h] [ebp-58h]
  float v15;    // [esp+34h] [ebp-54h]
  double v16;   // [esp+40h] [ebp-48h]
  double v17;   // [esp+50h] [ebp-38h]
  double v18;   // [esp+58h] [ebp-30h]
  double v19;   // [esp+60h] [ebp-28h]
  float v20;    // [esp+6Ch] [ebp-1Ch]
  char *v21[3]; // [esp+7Ch] [ebp-Ch] BYREF

  v21[0] = CL_GetConfigString(12);
  v0 = Com_Parse(v21);
  v1 = atof(v0);
  v20 = v1;
  v2 = Com_Parse(v21);
  if (!v2 || !*v2)
    return CL_SwitchFog();
  v16 = atof(v2);
  v4 = Com_Parse(v21);
  atof(v4);
  v5 = Com_Parse(v21);
  v17 = atof(v5);
  v6 = Com_Parse(v21);
  v18 = atof(v6);
  v7 = Com_Parse(v21);
  v19 = atof(v7);
  v8 = Com_Parse(v21);
  atoi(v8);
  v9 = v19;
  v15 = floorf((float)(v9 * 255.0) + 0.5);
  v10 = v18;
  v14 = floorf((float)(v10 * 255.0) + 0.5);
  v11 = v17;
  v13 = floorf((float)(v11 * 255.0) + 0.5);
  v12 = v16;
  CL_SetFog(1, v20, v12, (int)v13, (int)v14, (int)v15);
  return CL_SwitchFog();
}

void __cdecl CG_CloseScriptMenu() {
  int result; // eax

  CL_ClosePopup("UIMENU_SCRIPT_POPUP");
  CL_ClosePopup("UIMENU_SCRIPT_POPUP_NO_MOUSE");
  *(_BYTE *)(legacyHacks + 478) = 0;
  *(_DWORD *)(legacyHacks + 736) = -1;
  *(_BYTE *)(legacyHacks + 740) = 0;
  *(_DWORD *)(legacyHacks + 996) = -1;
  *(_BYTE *)(legacyHacks + 1000) = 0;
  *(_DWORD *)(legacyHacks + 1256) = -1;
  result = legacyHacks;
  *(_BYTE *)(legacyHacks + 1260) = 0;
  return result;
}

void __cdecl CG_ParseCodinfo() { UNIMPLEMENTED(); }

void __cdecl CG_ParseServerinfo() {
  char *ConfigString; // edi
  const char *v1;     // eax
  char *v2;           // esi
  const char *v3;     // eax
  const char *v4;     // eax
  const char *v5;     // ebx
  char *BspExtension; // eax

  ConfigString = CL_GetConfigString(0);
  v1 = (const char *)Info_ValueForKey(ConfigString, "sv_hostname");
  v2 = (char *)cgs;
  strncpy((char *)cgs + 24260, v1, 0x100u);
  v3 = (const char *)Info_ValueForKey(ConfigString, "g_gametype");
  strncpy(v2 + 24228, v3, 0x20u);
  if (!*((_DWORD *)v2 + 6056))
    Dvar_SetStringByName("g_gametype", v2 + 24228);
  v4 = (const char *)Info_ValueForKey(ConfigString, "sv_maxclients");
  *((_DWORD *)v2 + 6129) = atoi(v4);
  v5 = (const char *)Info_ValueForKey(ConfigString, "mapname");
  BspExtension = GetBspExtension();
  return Com_sprintf(v2 + 24520, 0x40u, "maps/mp/%s.%s", v5, BspExtension);
}

void __cdecl CG_CheckOpenWaitingScriptMenu() {
  int result; // eax

  if (*(_BYTE *)(legacyHacks + 1000)) {
    strcpy((char *)(legacyHacks + 740), (const char *)(legacyHacks + 1000));
    *(_DWORD *)(legacyHacks + 996) = *(_DWORD *)(legacyHacks + 1256);
    if (*(_BYTE *)(legacyHacks + 1260)) {
      if (CL_Popup("UIMENU_SCRIPT_POPUP_NO_MOUSE")) {
      LABEL_4:
        *(_BYTE *)(legacyHacks + 1000) = 0;
        *(_DWORD *)(legacyHacks + 1256) = -1;
        result = legacyHacks;
        *(_BYTE *)(legacyHacks + 1260) = 0;
        return result;
      }
    } else if (CL_Popup("UIMENU_SCRIPT_POPUP")) {
      goto LABEL_4;
    }
    *(_BYTE *)(legacyHacks + 740) = 0;
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 996) = -1;
  }
  return result;
}

void __cdecl CG_SetConfigValues() { UNIMPLEMENTED(); }

void __cdecl CG_MapRestart(int savepersist) {
  _DWORD *v1; // ebx

  if (*(_DWORD *)(cg_showmiss + 8))
    Com_Printf("CG_MapRestart\n");
  v1 = cg;
  *(_DWORD *)((char *)&loc_2B990 + (_DWORD)cg) = 0;
  v1[44924] = 0;
  v1[44928] = 1;
  CG_InitLocalEntities();
  CG_InitMarkPolys();
  FX_FreeActive();
  *((_DWORD *)cgs + 6178) = 0;
  v1[38639] = 1;
  SND_StopSounds(SND_STOP_ALL);
  CG_StartAmbient();
  v1[45417] = 0;
  *(_DWORD *)((char *)&loc_2BF0C + (_DWORD)v1) = 0;
  memset(v1 + 44957, 0, 0x60u);
  v1[44952] = 0;
  v1[44953] = 0;
  v1[44954] = 0;
  v1[44955] = 0;
  Dvar_SetBool((dvar_s *)cg_thirdPerson, 0);
  *(_DWORD *)(legacyHacks + 8) = 0;
  CL_SetADS(0);
  if (!a1) {
    *(_BYTE *)(legacyHacks + 1261) = 0;
    CL_ClosePopup("UIMENU_SCRIPT_POPUP");
    CL_ClosePopup("UIMENU_SCRIPT_POPUP_NO_MOUSE");
    *(_BYTE *)(legacyHacks + 478) = 0;
    *(_DWORD *)(legacyHacks + 736) = -1;
    *(_BYTE *)(legacyHacks + 740) = 0;
    *(_DWORD *)(legacyHacks + 996) = -1;
    *(_BYTE *)(legacyHacks + 1000) = 0;
    *(_DWORD *)(legacyHacks + 1256) = -1;
    *(_BYTE *)(legacyHacks + 1260) = 0;
    CL_ClosePopup("UIMENU_SCRIPT_POPUP");
    CL_ClosePopup("UIMENU_SCRIPT_POPUP_NO_MOUSE");
    *(_BYTE *)(legacyHacks + 478) = 0;
    *(_DWORD *)(legacyHacks + 736) = -1;
    *(_BYTE *)(legacyHacks + 740) = 0;
    *(_DWORD *)(legacyHacks + 996) = -1;
    *(_BYTE *)(legacyHacks + 1000) = 0;
    *(_DWORD *)(legacyHacks + 1256) = -1;
    *(_BYTE *)(legacyHacks + 1260) = 0;
    *(_BYTE *)(legacyHacks + 1261) = 1;
    CL_CloseAllMenus();
  }
  CG_ScoresUp_f();
  *((_BYTE *)v1 + 174588) = 0;
  CL_SyncTimes();
}

void __cdecl CG_ParseXboxLiveRanks(void) { UNIMPLEMENTED(); }

void __cdecl CG_ParseXUIDs(void) { UNIMPLEMENTED(); }

void __cdecl CG_ServerCommand() {
  int v1;                                       // esi
  int v2;                                       // esi
  char *v3;                                     // eax
  int v4;                                       // eax
  int v5;                                       // esi
  int v6;                                       // ebx
  char *v7;                                     // eax
  char *v8;                                     // eax
  char *v9;                                     // eax
  int v10;                                      // eax
  int v11;                                      // ebx
  char *v12;                                    // eax
  char *v13;                                    // eax
  char *v14;                                    // eax
  windowDef_t *v15;                             // eax
  char *v16;                                    // eax
  int v17;                                      // eax
  char *v18;                                    // eax
  int v19;                                      // eax
  char *v20;                                    // eax
  int v21;                                      // ebx
  char *v22;                                    // edi
  int k;                                        // esi
  char *v24;                                    // eax
  dvar_s *v25;                                  // ebx
  _DWORD *v26;                                  // ebx
  char *v27;                                    // eax
  int v28;                                      // eax
  _DWORD *v29;                                  // eax
  char *v30;                                    // eax
  char *v31;                                    // eax
  _DWORD *v32;                                  // ecx
  int i;                                        // ebx
  int v34;                                      // edx
  int v35;                                      // eax
  char *v36;                                    // eax
  char *v37;                                    // eax
  char *v38;                                    // eax
  char *v39;                                    // eax
  char v40;                                     // al
  int v41;                                      // ecx
  dvar_s *p_dst;                                // edx
  int v43;                                      // eax
  char *v44;                                    // eax
  char *v45;                                    // eax
  char v46;                                     // al
  dvar_s *v47;                                  // edx
  char *v48;                                    // eax
  const snd_alias_t *v49;                       // eax
  char *v50;                                    // eax
  int v51;                                      // eax
  char *v52;                                    // eax
  int v53;                                      // ebx
  char *v54;                                    // eax
  int v55;                                      // xmm0_4
  int v56;                                      // eax
  int v57;                                      // eax
  char *v58;                                    // eax
  char *v59;                                    // eax
  int v60;                                      // edi
  int v61;                                      // eax
  char *v62;                                    // edx
  char *v63;                                    // eax
  _DWORD *v64;                                  // esi
  char *v65;                                    // eax
  _DWORD *v66;                                  // ebx
  char *v67;                                    // eax
  char *v68;                                    // eax
  char *v69;                                    // eax
  int v70;                                      // edx
  char *v71;                                    // eax
  char *ConfigString;                           // eax
  char *v73;                                    // eax
  int v74;                                      // esi
  char *v75;                                    // eax
  float v76;                                    // xmm0_4
  char *v77;                                    // eax
  float v78;                                    // xmm0_4
  char *v79;                                    // eax
  char *v80;                                    // ebx
  float v81;                                    // xmm0_4
  float v82;                                    // xmm2_4
  int v83;                                      // eax
  char *v84;                                    // eax
  int v85;                                      // edx
  char *v86;                                    // eax
  _DWORD *v87;                                  // ebx
  _DWORD *v88;                                  // ebx
  int j;                                        // esi
  char *v90;                                    // ebx
  char *MapDisplayNameFromPartialLoadNameMatch; // eax
  char v92;                                     // dl
  char *v93;                                    // ecx
  int v94;                                      // ebx
  char *v95;                                    // eax
  _DWORD *v96;                                  // ebx
  _DWORD *v97;                                  // ebx
  _DWORD *v98;                                  // ebx
  _DWORD *v99;                                  // ebx
  _DWORD *v100;                                 // ebx
  _DWORD *v101;                                 // ebx
  char *v102;                                   // eax
  char *v103;                                   // eax
  char *v104;                                   // eax
  int v105;                                     // [esp+24h] [ebp-2F4h]
  float v106;                                   // [esp+2Ch] [ebp-2ECh]
  int v107;                                     // [esp+38h] [ebp-2E0h]
  int v108;                                     // [esp+3Ch] [ebp-2DCh]
  double v109;                                  // [esp+50h] [ebp-2C8h]
  float v110;                                   // [esp+58h] [ebp-2C0h]
  float v111;                                   // [esp+5Ch] [ebp-2BCh]
  char v112[256];                               // [esp+66h] [ebp-2B2h] BYREF
  char v113[256];                               // [esp+166h] [ebp-1B2h] BYREF
  dvar_s __dst;                                 // [esp+266h] [ebp-B2h] BYREF
  int v115[7];                                  // [esp+2FCh] [ebp-1Ch] BYREF

  switch (*CG_Argv(0)) {
  case 0:
    return;
  case 66:
    CG_MapRestart(0);
    break;
  case 67:
    v9 = CG_Argv(1);
    v10 = atoi(v9);
    v11 = v10;
    if (!v10 || *(_DWORD *)(BG_GetWeaponDef(v10) + 132))
      CG_SetEquippedOffHand(v11);
    break;
  case 68:
    CG_DeactivateReverbCmd();
    break;
  case 69:
    CG_SetChannelVolCmd();
    break;
  case 70:
    CG_DeactivateChannelVolCmd();
    break;
  case 71:
    v12 = CG_Argv(1);
    *((_DWORD *)cgs + 6382) = atoi(v12);
    break;
  case 72:
    v13 = CG_Argv(1);
    *((_DWORD *)cgs + 6383) = atoi(v13);
    break;
  case 73:
    v14 = CG_Argv(1);
    v15 = (windowDef_t *)atoi(v14);
    CG_MenuShowNotify(v15);
    break;
  case 74:
    v16 = CG_Argv(1);
    v17 = atoi(v16);
    CL_ResetPlayerMuting(v17);
    break;
  case 75:
    CL_CloseInGameMenu();
    break;
  case 97:
    v18 = CG_Argv(1);
    v19 = atoi(v18);
    CG_SelectWeaponIndex(v19);
    break;
  case 98:
    v26 = cg;
    v27 = CG_Argv(1);
    v28 = atoi(v27);
    v26[43968] = v28;
    if (v28 > 64)
      v26[43968] = 64;
    v29 = (_DWORD *)((char *)&loc_2AF04 + (_DWORD)v26);
    *(_DWORD *)((char *)&loc_2AF04 + (_DWORD)v26) = 0;
    v29[1] = 0;
    v29[2] = 0;
    v29[3] = 0;
    v30 = CG_Argv(2);
    *(_DWORD *)((char *)&loc_2AF08 + (_DWORD)v26) = atoi(v30);
    v31 = CG_Argv(3);
    v26[43971] = atoi(v31);
    memset(v26 + 43981, 0, 0x600u);
    v26[43973] = 0;
    v26[43974] = 0;
    v26[43975] = 0;
    v26[43976] = 0;
    v26[43977] = 0;
    v26[43978] = 0;
    v26[43979] = 0;
    v26[43980] = 0;
    if ((int)v26[43968] > 0) {
      v107 = 0;
      v60 = 4;
      v105 = 0;
      do {
        v63 = CG_Argv(v60);
        v26[v105 + 43981] = atoi(v63);
        v64 = cg;
        v65 = CG_Argv(v60 + 1);
        v66 = &v64[v105];
        *(_DWORD *)((char *)&loc_2AF38 + (_DWORD)&v64[v105]) = atoi(v65);
        v67 = CG_Argv(v60 + 2);
        v66[43983] = atoi(v67);
        v68 = CG_Argv(v60 + 3);
        v66[43984] = atoi(v68);
        v69 = CG_Argv(v60 + 4);
        v70 = atoi(v69);
        if ((unsigned int)(v70 - 1) <= 7) {
          ConfigString = CL_GetConfigString(v70 + 22);
          v66[43986] = CL_RegisterMaterialNoMip(ConfigString, 7);
        }
        if (v66[43981] > 0x3Fu)
          v66[43981] = 0;
        v64[302 * v66[43981] + 229970] =
            *(_DWORD *)((char *)&loc_2AF38 + (_DWORD)v66);
        v71 = (char *)&v64[302 * v66[43981]];
        if (*((_DWORD *)v71 + 229957))
          v61 = *((_DWORD *)v71 + 229968);
        else
          v61 = 0;
        v64[v105 + 43985] = v61;
        v32 = cg;
        v62 = (char *)cg + v105 * 4;
        ++*((_DWORD *)cg + *((_DWORD *)v62 + 43985) + 43977);
        v32[*((_DWORD *)v62 + 43985) + 43973] += *((_DWORD *)v62 + 43983);
        ++v107;
        v105 += 6;
        v26 = v32;
        v60 += 5;
      } while (v32[43968] > v107);
    } else {
      v32 = cg;
    }
    for (i = 0; i != 4; ++i) {
      v34 = v32[i + 43977];
      if (v34 <= 0 || (v35 = v32[i + 43973], v35 <= 0))
        v32[i + 43973] = 0;
      else
        v32[i + 43973] = v35 / v34;
    }
    break;
  case 99:
    v36 = CG_Argv(1);
    CG_TranslateHudElemMessage(v36, "announcement message", v113);
    CG_BoldGameMessage(v113);
    break;
  case 100:
    v20 = CG_Argv(1);
    v21 = atoi(v20);
    v22 = CL_GetConfigString(v21);
    switch (v21) {
    case 7:
      CG_SetupWeaponDef();
      break;
    case 8:
      CG_RegisterItems(a1);
      break;
    case 3:
      CG_StartAmbient();
      break;
    default:
      if (v21) {
        if ((unsigned int)(v21 - 142) > 0xBF) {
          switch (v21) {
          case 5:
            v101 = cgs;
            v101[6382] = atoi(v22);
            break;
          case 6:
            v100 = cgs;
            v100[6383] = atoi(v22);
            break;
          case 13:
            v99 = cgs;
            v99[6381] = atoi(v22);
            break;
          case 15:
            v98 = cgs;
            v98[6178] = atoi(v22);
            break;
          case 17:
            v97 = cgs;
            v97[6179] = atoi(v22);
            break;
          case 18:
            v96 = cgs;
            v96[6180] = atoi(v22);
            break;
          case 16:
            v108 = 0;
            for (j = 0; j <= 255; ++j) {
              v90 = &v22[j];
              MapDisplayNameFromPartialLoadNameMatch =
                  (char *)UI_GetMapDisplayNameFromPartialLoadNameMatch(&v22[j],
                                                                       v115);
              if (MapDisplayNameFromPartialLoadNameMatch) {
                v92 = *MapDisplayNameFromPartialLoadNameMatch;
                if (*MapDisplayNameFromPartialLoadNameMatch) {
                  v93 = &v112[v108];
                  v94 = 0;
                  do {
                    *v93 = v92;
                    v92 = MapDisplayNameFromPartialLoadNameMatch[++v94];
                    ++v93;
                  } while (v92);
                  v108 += v94;
                }
                j += v115[0];
                v90 = &v22[j];
              }
              v112[v108++] = *v90;
              if (!*v90)
                break;
            }
            v112[255] = 0;
            v95 = SEH_LocalizeTextMessage(v112, "vote string", LOCMSG_SAFE);
            I_strncpyz((char *)cgs + 24724, v95, 256);
            break;
          case 12:
            CG_ParseFog();
            break;
          default:
            v1 = v21 - 334;
            if ((unsigned int)(v21 - 334) <= 0xFF) {
              v88 = cgs;
              v88[v1 + 6384] = CL_RegisterModel();
            } else {
              v2 = v21 - 846;
              if ((unsigned int)(v21 - 846) <= 0x3F) {
                v87 = cgs;
                v87[v2 + 6640] = FX_RegisterEffect(a1, v22);
              } else if ((unsigned int)(v21 - 1166) > 0xF) {
                if ((unsigned int)(v21 - 23) <= 7) {
                  v103 = CL_GetConfigString(v21);
                  CL_RegisterMaterialNoMip(v103, 7);
                } else if ((unsigned int)(v21 - 31) <= 0xE) {
                  v102 = CL_GetConfigString(v21);
                  CL_RegisterMaterial(v102, 7);
                } else if ((unsigned int)(v21 - 1566) <= 0x7F) {
                  v104 = CL_GetConfigString(v21);
                  if (*v104)
                    CL_RegisterMaterialNoMip(v104, 7);
                } else if (v21 == 11) {
                  CG_NorthDirectionChanged();
                }
              } else if (*v22 && CG_LoadShellShockDvars(v22)) {
                CG_SetShellShockParmsFromDvars(
                    (shellshock_parms_t *)((char *)cgs + 132 * v21 - 127092));
              }
            }
            break;
          }
        } else if (!*((_DWORD *)cgs + 6056)) {
          for (k = 142; k != 238; ++k) {
            v25 = (dvar_s *)CL_GetConfigString(k);
            if (!v25->name[0])
              break;
            v24 = CL_GetConfigString(k + 96);
            Dvar_SetFromStringByName(v25, (DvarValue)v24);
          }
        }
      } else {
        CG_ParseServerinfo();
      }
      break;
    }
    break;
  case 101:
  case 102:
    v8 = CG_Argv(1);
    CG_TranslateHudElemMessage(v8, "game message", v113);
    CG_GameMessage(v113);
    break;
  case 103:
    v37 = CG_Argv(1);
    CG_TranslateHudElemMessage(v37, "bold game message", v113);
    CG_BoldGameMessage(v113);
    break;
  case 104:
    if (!*(_BYTE *)(cg_teamChatsOnly + 8)) {
      v38 = CG_Argv(1);
      v39 = SEH_LocalizeTextMessage(v38, "chat message", LOCMSG_SAFE);
      I_strncpyz(__dst.name, v39, 150);
      v40 = __dst.name[0];
      if (!__dst.name[0])
        goto LABEL_86;
      v41 = 0;
      p_dst = &__dst;
      do {
        if (v40 != 25)
          __dst.name[v41++] = v40;
        v40 = p_dst->name[1];
        p_dst = (dvar_s *)((char *)p_dst + 1);
      } while (v40);
      goto LABEL_63;
    }
    break;
  case 105:
    v44 = CG_Argv(1);
    v45 = SEH_LocalizeTextMessage(v44, "team chat message", LOCMSG_SAFE);
    I_strncpyz(__dst.name, v45, 150);
    v46 = __dst.name[0];
    if (__dst.name[0]) {
      v41 = 0;
      v47 = &__dst;
      do {
        if (v46 != 25)
          __dst.name[v41++] = v46;
        v46 = v47->name[1];
        v47 = (dvar_s *)((char *)v47 + 1);
      } while (v46);
    LABEL_63:
      v43 = v41;
    } else {
    LABEL_86:
      v43 = 0;
    }
    __dst.name[v43] = 0;
    CG_AddToTeamChat((int)&__dst);
    Com_Printf("%s\n", __dst.name);
    break;
  case 110:
    CG_MapRestart(1);
    break;
  case 111:
    if ((unsigned __int8)CG_PlaySoundOnFirstClient()) {
      v48 = CG_Argv(1);
      v49 = (const snd_alias_t *)CL_PickSoundAlias(v48);
      SND_PlayMusicAlias(v49, SASYS_CGAME);
    }
    break;
  case 112:
    if ((unsigned __int8)CG_PlaySoundOnFirstClient()) {
      v50 = CG_Argv(1);
      v51 = atoi(v50);
      SND_StopMusic(v51);
    }
    break;
  case 113:
    if ((unsigned __int8)CG_PlaySoundOnFirstClient()) {
      v52 = CG_Argv(2);
      v53 = atoi(v52);
      v54 = CG_Argv(1);
      *(float *)&v55 = atof(v54);
      SND_FadeAllSounds(v55, v53);
    }
    break;
  case 114:
    v56 = Cmd_Argc();
    if (v56 == 6) {
      v73 = CG_Argv(1);
      v74 = atoi(v73);
      v75 = CG_Argv(3);
      v76 = atof(v75);
      v110 = v76;
      v77 = CG_Argv(4);
      v78 = atof(v77);
      v111 = v78;
      v79 = CG_Argv(5);
      v109 = atof(v79);
      v80 = CG_Argv(2);
      v81 = v109;
      v106 = floorf((float)(v81 * 1000.0) + 0.5);
      v82 = (float)(int)v106;
      if ((float)(0.0 - v82) < 0.0)
        v83 = (int)v82;
      else
        v83 = 0;
      SND_SetEnvironmentEffects(v74, v80, v110, v111, v83);
    } else {
      Com_Printf("ERROR: CG_ReverbCmd called with %i args (should be 6)\n",
                 v56);
    }
    break;
  case 115:
    v57 = Cmd_Argc();
    if (v57 == 2) {
      v84 = CG_Argv(1);
      v85 = atoi(v84);
      if ((unsigned int)(v85 - 1) <= 0xFF) {
        v86 = CL_GetConfigString(v85 + 590);
        CG_PlayClientSoundAliasByName(v86);
      } else {
        Com_Printf("ERROR: CG_LocalSound called with index %i (should be in "
                   "range[1,%i])\n",
                   v85, 256);
      }
    } else {
      Com_Printf("ERROR: CG_LocalSound called with %i args (should be 2)\n",
                 v57);
    }
    break;
  case 116:
    CG_OpenScriptMenu();
    break;
  case 117:
    CL_ClosePopup("UIMENU_SCRIPT_POPUP");
    CL_ClosePopup("UIMENU_SCRIPT_POPUP_NO_MOUSE");
    *(_BYTE *)(legacyHacks + 478) = 0;
    *(_DWORD *)(legacyHacks + 736) = -1;
    *(_BYTE *)(legacyHacks + 740) = 0;
    *(_DWORD *)(legacyHacks + 996) = -1;
    *(_BYTE *)(legacyHacks + 1000) = 0;
    *(_DWORD *)(legacyHacks + 1256) = -1;
    *(_BYTE *)(legacyHacks + 1260) = 0;
    break;
  case 118:
    v58 = CG_Argv(1);
    I_strncpyz(__dst.name, v58, 150);
    v59 = CG_Argv(2);
    CG_SetClientDvarFromServer(&__dst, v59);
    break;
  default:
    v3 = CG_Argv(0);
    Com_Printf("Unknown client game command: %s\n", v3);
    v4 = Cmd_Argc();
    v5 = v4;
    if (v4 > 1) {
      Com_Printf("Arguments(%i):", v4 - 1);
      v6 = 1;
      do {
        v7 = CG_Argv(v6);
        Com_Printf(" %s", v7);
        ++v6;
      } while (v5 != v6);
      Com_Printf("\n");
    }
    break;
  }
}

void __cdecl CG_ExecuteNewServerCommands(int latestSequence) {
  UNIMPLEMENTED();
}

void __cdecl CG_SetScriptMainMenu(char const *) { UNIMPLEMENTED(); }

void __cdecl CG_SetDrawHud(int) { UNIMPLEMENTED(); }

void __cdecl CG_SetObjectiveText(char const *) { UNIMPLEMENTED(); }

void __cdecl CG_SetTeamScore(int, int) { UNIMPLEMENTED(); }

void __cdecl CG_RemoveChatEscapeChar(char *) { UNIMPLEMENTED(); }

void __cdecl CG_AddToTeamChat(char const *) { UNIMPLEMENTED(); }

void __cdecl CG_RegisterServerMaterial(int) { UNIMPLEMENTED(); }

void __cdecl CG_ParseScores(void) { UNIMPLEMENTED(); }

void __cdecl CG_SetClientDvarFromServer(char const *, char const *) {
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateVoteString(char const *) { UNIMPLEMENTED(); }

void __cdecl CG_PrecacheScriptMenu(int) { UNIMPLEMENTED(); }

void __cdecl CG_DeactivateChannelVolCmd(void) {
  int v0;   // eax
  char *v1; // eax
  int v2;   // ebx
  char *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  int v6;   // eax
  float v7; // [esp+14h] [ebp-14h]

  v0 = Cmd_Argc();
  if (v0 == 3) {
    v1 = CG_Argv(1);
    v2 = atoi(v1);
    v3 = CG_Argv(2);
    v4 = atof(v3);
    v7 = floorf((float)(v4 * 1000.0) + 0.5);
    v5 = (float)(int)v7;
    if ((float)(0.0 - v5) < 0.0)
      v6 = (int)v5;
    else
      v6 = 0;
    SND_DeactivateChannelVolumes(v2, v6);
  } else {
    Com_Printf(
        "ERROR: CG_DeactivateChannelVolCmd called with %i args (should be 3)\n",
        v0);
  }
}

void __cdecl CG_SetChannelVolCmd(void) {
  int v0;   // eax
  char *v1; // eax
  int v2;   // esi
  char *v3; // eax
  int v4;   // ebx
  char *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm2_4
  int v8;   // eax
  float v9; // [esp+14h] [ebp-14h]

  v0 = Cmd_Argc();
  if (v0 == 4) {
    v1 = CG_Argv(1);
    v2 = atoi(v1);
    v3 = CG_Argv(2);
    v4 = atoi(v3);
    v5 = CG_Argv(3);
    v6 = atof(v5);
    v9 = floorf((float)(v6 * 1000.0) + 0.5);
    v7 = (float)(int)v9;
    if ((float)(0.0 - v7) < 0.0)
      v8 = (int)v7;
    else
      v8 = 0;
    SND_SetChannelVolumes(v2, (const float *)cgs + 33 * v4 + 6719, v8);
  } else {
    Com_Printf("ERROR: CG_SetChannelVolCmd called with %i args (should be 4)\n",
               v0);
  }
}

void __cdecl CG_DeactivateReverbCmd(void) {
  int v0;   // eax
  char *v1; // eax
  int v2;   // ebx
  char *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  int v6;   // eax
  float v7; // [esp+14h] [ebp-14h]

  v0 = Cmd_Argc();
  if (v0 == 3) {
    v1 = CG_Argv(1);
    v2 = atoi(v1);
    v3 = CG_Argv(2);
    v4 = atof(v3);
    v7 = floorf((float)(v4 * 1000.0) + 0.5);
    v5 = (float)(int)v7;
    if ((float)(0.0 - v5) < 0.0)
      v6 = (int)v5;
    else
      v6 = 0;
    SND_DeactivateEnvironmentEffects(v2, v6);
  } else {
    Com_Printf(
        "ERROR: CG_DeactivateReverbCmd called with %i args (should be 3)\n",
        v0);
  }
}

void __cdecl CG_OpenScriptMenu(void) {
  char *v0;           // eax
  unsigned int v1;    // eax
  unsigned int v2;    // esi
  char *v3;           // eax
  char *ConfigString; // edi
  int v5;             // eax
  char *v6;           // eax
  bool v7;            // [esp+1Fh] [ebp-19h]

  v0 = CG_Argv(1);
  v1 = atoi(v0);
  v2 = v1;
  if (v1 > 0x1F) {
    Com_Printf("Server tried to open a bad script menu index: %i\n", v1);
  LABEL_3:
    v3 = va("cmd mr %i bad\n", v2);
    Cbuf_AddText(v3);
    return;
  }
  ConfigString = CL_GetConfigString(v1 + 1246);
  if (!*ConfigString) {
    Com_Printf("Server tried to open a non-loaded script menu index: %i\n", v2);
    goto LABEL_3;
  }
  v7 = Cmd_Argc() > 2 && CG_Argv(2) && *CG_Argv(2);
  I_strncpyz((char *)(legacyHacks + 740), ConfigString, 256);
  *(_DWORD *)(legacyHacks + 996) = v2;
  if (v7)
    v5 = CL_Popup("UIMENU_SCRIPT_POPUP_NO_MOUSE");
  else
    v5 = CL_Popup("UIMENU_SCRIPT_POPUP");
  if (!v5) {
    *(_BYTE *)(legacyHacks + 740) = 0;
    *(_DWORD *)(legacyHacks + 996) = -1;
    if (!*(_BYTE *)(legacyHacks + 1000)) {
    LABEL_14:
      I_strncpyz((char *)(legacyHacks + 1000), ConfigString, 256);
      *(_DWORD *)(legacyHacks + 1256) = v2;
      *(_BYTE *)(legacyHacks + 1260) = v7;
      return;
    }
    if (I_stricmp(ConfigString, (char *)(legacyHacks + 1000))) {
      v6 = va("cmd mr %i noop\n", *(_DWORD *)(legacyHacks + 1256));
      Cbuf_AddText(v6);
      goto LABEL_14;
    }
  }
}

void __cdecl CG_LocalSound(void) { UNIMPLEMENTED(); }

void __cdecl CG_ReverbCmd(void) { UNIMPLEMENTED(); }

void __cdecl CG_ConfigStringModified(void) { UNIMPLEMENTED(); }
