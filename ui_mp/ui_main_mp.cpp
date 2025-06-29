float __cdecl UI_GetBlurRadius()
{
  return *(float *)&uiInfo->blurRadiusOut;
}

char const *__cdecl UI_GetTopActiveMenuName(void)
{
  UNIMPLEMENTED();
}

enum uiMenuCommand_t __cdecl UI_GetActiveMenu()
{
  return *(_DWORD *)&uiInfo[1].Menus[508];
}

void __cdecl UI_MouseEvent(int dx, int dy)
{
  displayContextDef_s *v2; // edx
  int32_t cursorx;         // eax
  displayContextDef_s *v4; // edx
  int32_t cursory;         // eax
  signed int result;       // eax

  uiInfo->cursorx += a1;
  v2 = uiInfo;
  cursorx = uiInfo->cursorx;
    if (cursorx < 0) {
      uiInfo->cursorx = 0;
      v2 = uiInfo;
    LABEL_3:
      v2->cursory += a2;
      v4 = uiInfo;
      cursory = uiInfo->cursory;
      if (cursory >= 0)
        goto LABEL_4;
    LABEL_10:
      v4->cursory = 0;
      v4 = uiInfo;
      goto LABEL_6;
    }
  if (cursorx <= 640)
    goto LABEL_3;
  uiInfo->cursorx = 640;
  uiInfo->cursory += a2;
  v4 = uiInfo;
  cursory = uiInfo->cursory;
  if (cursory < 0)
    goto LABEL_10;
LABEL_4:
    if (cursory > 480) {
      v4->cursory = 480;
      v4 = uiInfo;
    }
LABEL_6:
  result = Menu_Count(v4);
  if (result > 0)
    return Display_MouseMove(uiInfo, 0, uiInfo->cursorx, uiInfo->cursory);
  return result;
}

struct Material *__cdecl UI_FeederItemImage(float feederID, int index)
{
  int v3;  // ebx
  int v4;  // edx
  int *v5; // eax
  int v6;  // ebx

  if (a1 != 4.0)
    return 0;
    if (dword_1685E10 <= 0) {
    LABEL_9:
      v4 = 0;
      goto LABEL_10;
    }
  v3 = 0;
  v4 = 0;
  v5 = &sharedUiInfo;
    while (!v5[1277]) {
    LABEL_8:
      ++v4;
      v5 += 41;
      if (dword_1685E10 == v4)
        goto LABEL_9;
    }
    if (v3 != a2) {
      ++v3;
      goto LABEL_8;
    }
  if (v4 < 0)
    return 0;
LABEL_10:
  if (dword_1685E10 <= v4)
    return 0;
  v6 = 164 * v4;
  if (!*(&dword_1685EB0 + 41 * v4))
    *((_DWORD *)&unk_1685EA0 + 41 * v4 + 4) =
        CL_RegisterMaterialNoMip((const char *)dword_1685E1C[41 * v4], 3);
  return *(int *)((char *)&dword_1685EB0 + v6);
}

int __cdecl UI_OwnerDrawHandleKey(int ownerDraw, int flags, float *special,
                                  int key)
{
  dvar_s *v5;        // ecx
  int v6;            // edx
  int v7;            // eax
  dvar_s *v8;        // ecx
  int v9;            // edx
  DvarValue v10;     // esi
  int v11;           // ecx
  int v12;           // ebx
  int *v13;          // edx
  DvarValue v14;     // ebx
  int v15;           // ebx
  int *v16;          // edx
  int v17;           // eax
  int v18;           // ebx
  DvarValue current; // esi
  int v20;           // ebx
  int v21;           // edi
  int *v22;          // edx
  dvar_s *v23;       // edx
  int v24;           // eax
  DvarValue v25;     // esi
  int v26;           // ebx
  int *v27;          // edx
  DvarValue v28;     // eax
  DvarValue v29;     // eax
  DvarValue v30;     // eax
  int v31;           // esi
  int v32;           // eax
  int *v33;          // edx
  int v34;           // [esp+2Ch] [ebp-1Ch]

    switch (a1) {
    case 205:
      if ((unsigned int)(a4 - 200) > 1 && a4 != 13 && a4 != 191)
        return 0;
      current = ui_netGameType->current;
        if (dword_1685E10 <= 0) {
          v21 = 0;
        }
        else {
          v20 = 0;
          v21 = 0;
          v22 = &sharedUiInfo;
            do {
              v22[1277] = 0;
                if (((v22[1242] >> current.enabled) & 1) != 0) {
                  ++v21;
                  v22[1277] = 1;
                }
              ++v20;
              v22 += 41;
            }
          while (dword_1685E10 > v20);
        }
        if (a4 == 201) {
          v23 = ui_gametype;
          v24 = ui_gametype->current.integer - 1;
            if (ui_gametype->current.integer != 3) {
              if (v24 <= 1)
                v24 = dword_1685C08 - 1;
              goto LABEL_58;
            }
        }
        else {
          v23 = ui_gametype;
          v24 = ui_gametype->current.integer + 1;
            if (v24 < dword_1685C08) {
              if (ui_gametype->current.integer == 1)
                LOBYTE(v24) = 3;
              goto LABEL_58;
            }
        }
      v24 = 1;
    LABEL_58:
      Dvar_SetInt(v23, v24);
      v25 = ui_netGameType->current;
        if (dword_1685E10 <= 0) {
          v26 = 0;
        }
        else {
          v34 = 0;
          v26 = 0;
          v27 = &sharedUiInfo;
            do {
              v27[1277] = 0;
                if (((v27[1242] >> v25.enabled) & 1) != 0) {
                  ++v26;
                  v27[1277] = 1;
                }
              ++v34;
              v27 += 41;
            }
          while (dword_1685E10 > v34);
        }
      if (v21 == v26)
        return 1;
      Dvar_SetInt(ui_currentMap, 0);
      return 1;
    case 220:
      if ((unsigned int)(a4 - 200) > 1 && a4 != 13 && a4 != 191)
        return 0;
        if (a4 == 201) {
          v30 = ui_netSource->current;
          v18 = v30.integer ? v30.integer - 1 : 2;
        }
        else {
          v18 = ui_netSource->current.integer + 1;
          if (ui_netSource->current.integer == 2)
            v18 = 0;
        }
      UI_BuildServerDisplayList(1);
      Dvar_SetInt(ui_netSource, v18);
      if (ui_netSource->current.integer == 1)
        return 0;
      UI_StartServerRefresh(1);
      UI_BuildServerDisplayList(1);
      return 0;
    case 222:
      if ((unsigned int)(a4 - 200) > 1 && a4 != 13 && a4 != 191)
        return 0;
      if (a4 == 201)
        v7 = --ui_serverFilterType;
      else
        v7 = ++ui_serverFilterType;
      if (v7 > 0 || v7 < 0)
        ui_serverFilterType = 0;
      UI_BuildServerDisplayList(1);
      return 0;
    case 245:
      if ((unsigned int)(a4 - 200) > 1 && a4 != 13 && a4 != 191)
        return 0;
        if (a4 == 201) {
          v8 = ui_netGameType;
          v29 = ui_netGameType->current;
          if (!v29.integer)
            v29.integer = dword_1685C08;
          v9 = v29.integer - 1;
        }
        else {
          v8 = ui_netGameType;
          v9 = ui_netGameType->current.integer + 1;
          if (v9 == dword_1685C08)
            v9 = 0;
        }
      Dvar_SetInt(v8, v9);
      Dvar_SetString(
          ui_netGameTypeName,
          *(char **)&dword_1685C0C[8 * ui_netGameType->current.integer]);
      v10 = ui_netGameType->current;
      v11 = dword_1685E10;
        if (dword_1685E10 > 0) {
          v12 = 0;
          v13 = &sharedUiInfo;
            do {
              v13[1277] = 0;
              if (((v13[1242] >> v10.enabled) & 1) != 0)
                v13[1277] = 1;
              ++v12;
              v11 = dword_1685E10;
              v13 += 41;
            }
          while (v12 < dword_1685E10);
        }
      v14 = ui_currentNetMap->current;
        if (dword_1685EB4[41 * v14.integer]) {
            if (v11 > 0) {
              v31 = 0;
              v32 = 0;
              v33 = &sharedUiInfo;
                do {
                    if (v33[1277]) {
                      if (v32 == v14.integer)
                        goto LABEL_82;
                      ++v31;
                    }
                  ++v32;
                  v33 += 41;
                }
              while (v11 != v32);
            }
          v31 = 0;
        LABEL_82:
          Menu_SetFeederSelection(uiInfo, 0, 4, v31, "createserver_maps");
          UI_SelectCurrentMap();
        }
        else {
            if (v11 > 0) {
                if (dword_1685EB4[0]) {
                  v15 = 0;
                LABEL_38:
                  Menu_SetFeederSelection(uiInfo, 0, 4, 0, "createserver_maps");
                  Dvar_SetInt(ui_currentNetMap, v15);
                }
                else {
                  v15 = 0;
                  v16 = &sharedUiInfo;
                    while (v11 != ++v15) {
                      v17 = v16[1318];
                      v16 += 41;
                      if (v17)
                        goto LABEL_38;
                    }
                }
            }
          UI_SelectCurrentMap();
        }
      return 1;
    case 253:
      if ((unsigned int)(a4 - 200) > 1 && a4 != 13 && a4 != 191)
        return 0;
        if (a4 == 201) {
          v5 = ui_joinGameType;
          v28 = ui_joinGameType->current;
          if (!v28.integer)
            v28.integer = dword_1685D0C;
          v6 = v28.integer - 1;
        }
        else {
          v5 = ui_joinGameType;
          v6 = ui_joinGameType->current.integer + 1;
          if (v6 == dword_1685D0C)
            v6 = 0;
        }
      Dvar_SetInt(v5, v6);
      UI_BuildServerDisplayList(1);
      return 1;
    default:
      return 0;
    }
}

int __cdecl UI_OwnerDrawVisible(int flags)
{
  int v1; // edx

    if ((a1 & 4) == 0 || ui_netSource->current.integer == 2) {
      v1 = 1;
      if ((a1 & 0x1000) == 0)
        return v1;
    }
    else {
      v1 = 0;
      if ((a1 & 0x1000) == 0)
        return v1;
    }
  if (ui_netSource->current.integer == 2)
    return 0;
  return v1;
}

void __cdecl UI_SetMap(char const *mapname, char const *gametype)
{
  char *v9; // eax

  I_strncpyz(&g_mapname, __src, 64);
  I_strncpyz(g_gametype, a9, 64);
    if (g_mapname) {
      v9 = va("maps/mp/%s.csv", &g_mapname);
      UI_MapLoadInfo(a1, a2, a3, a4, a5, a6, a7, v9);
    }
}

void __cdecl UI_UpdateTime(int realtime)
{
  int result;              // eax
  displayContextDef_s *v2; // eax
  int v3;                  // ecx
  int v4;                  // edx

  uiInfo->frameTime = a1 - uiInfo->realTime;
  uiInfo->realTime = a1;
  *(_DWORD *)&uiInfo[1]
       .Menus[4 * (*(_DWORD *)&uiInfo[1].Menus[488] % 4) + 492] =
      uiInfo->frameTime;
  result = (int)uiInfo;
    if ((int)++*(_DWORD *)&uiInfo[1].Menus[488] > 4) {
      v2 = uiInfo;
      v3 = 0;
      v4 = 4;
        do {
          v3 += *(_DWORD *)&v2[1].Menus[492];
          v2 = (displayContextDef_s *)((char *)v2 + 4);
          --v4;
        }
      while (v4);
      if (v3)
        result = 4000 / v3;
      else
        result = 4000;
      *(float *)&uiInfo->FPS = (float)result;
    }
  return result;
}

void __cdecl UI_SwitchToLocalClient(int)
{
  UNIMPLEMENTED();
}

char const *__cdecl UI_ReplaceConversions(char const *sourceString,
                                          struct ConversionArguments *arguments)
{
  unsigned int v2;  // kr04_4
  char *v4;         // ebx
  unsigned int v5;  // edx
  const char *v6;   // esi
  unsigned int v7;  // kr08_4
  char *v8;         // edx
  int v9;           // ebx
  signed int v10;   // [esp+14h] [ebp-424h]
  int v11;          // [esp+18h] [ebp-420h]
  unsigned int v12; // [esp+1Ch] [ebp-41Ch]
  char __b[1048];   // [esp+20h] [ebp-418h] BYREF

  if (!strstr(__big, "&&"))
    return __big;
  v2 = strlen(__big) + 1;
  memset(__b, 0, 0x400u);
    if ((int)(v2 - 1) > 0) {
      v11 = 0;
      v10 = 0;
      v4 = __big;
      if (!memcmp(__big, "&&", 2))
        goto LABEL_5;
    LABEL_14:
      __b[v11++] = *v4;
      ++v10;
        while ((int)(v2 - 1) > v10) {
          v4 = &__big[v10];
          if (memcmp(&__big[v10], "&&", 2))
            goto LABEL_14;
        LABEL_5:
          v5 = __big[v10 + 2];
          if (v5 > 0xFF || (_DefaultRuneLocale.__runetype[v5] & 0x400) == 0)
            goto LABEL_14;
          v12 = v5 - 49;
          v6 = (const char *)*((_DWORD *)&a2[-4] + v5 - 8);
          v7 = strlen(v6) + 1;
            if ((int)(v7 - 1) > 0) {
              v8 = &__b[v11];
              v9 = 0;
                while (1) {
                  *v8 = v6[v9];
                  ++v11;
                  ++v9;
                  ++v8;
                  if (v7 - 1 == v9)
                    break;
                  v6 = *(const char **)&a2->args[4 * v12];
                }
            }
          v10 += 3;
        }
    }
  return va(__b);
}

char const *__cdecl UI_ReplaceConversionInt(char const *, int)
{
  UNIMPLEMENTED();
}

char const *__cdecl UI_ReplaceConversionString(char const *sourceString,
                                               char const *replaceString)
{
  ConversionArguments v3; // [esp+18h] [ebp-30h] BYREF

  memset(&v3, 0, sizeof(v3));
  v3.argCount = 1;
  *(_DWORD *)v3.args = a2;
  return UI_ReplaceConversions(__big, &v3);
}

char const *__cdecl UI_GetMapDisplayNameFromPartialLoadNameMatch(
    char const *pszMap, int *mapLoadNameLen)
{
  int v3;          // esi
  int *v4;         // ebx
  unsigned int v5; // kr04_4
  int *i;          // [esp+1Ch] [ebp-1Ch]

  if (dword_1685E10 <= 0)
    return 0;
  v3 = 0;
  v4 = &sharedUiInfo;
    for (i = dword_1685E14;; i += 41) {
      v5 = strlen((const char *)v4[1238]) + 1;
      *a2 = v5 - 1;
      if (!I_strnicmp(a1, (char *)v4[1238], v5 - 1))
        break;
      ++v3;
      v4 += 41;
      if (v3 >= dword_1685E10)
        return 0;
    }
  return *i;
}

int __cdecl UI_TextHeight(struct Font_s *font, float scale)
{
  UNIMPLEMENTED();
}

int __cdecl UI_TextWidth(char const *text, int maxChars, struct Font_s *font,
                         float scale)
{
  UNIMPLEMENTED();
}

void __cdecl UI_AssetCache()
{
  int result; // eax

  dword_1684AE0 = (Material *)CL_RegisterMaterialNoMip("white", 3);
  dword_1684AD0 = CL_RegisterMaterialNoMip("ui/assets/scrollbar.tga", 3);
  dword_1684AC4 =
      CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_dwn_a.tga", 3);
  sharedUiInfo[0] =
      CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_up_a.tga", 3);
  dword_1684AC8 =
      CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_left.tga", 3);
  dword_1684ACC =
      CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_right.tga", 3);
  dword_1684AD4[0] =
      CL_RegisterMaterialNoMip("ui/assets/scrollbar_thumb.tga", 3);
  dword_1684AD8 = CL_RegisterMaterialNoMip("ui/assets/slider2.tga", 3);
  dword_1684ADC = CL_RegisterMaterialNoMip("ui/assets/sliderbutt_1", 3);
  dword_1684AE4 = (Material *)CL_RegisterMaterialNoMip("$cursor", 0);
  dword_1684AE8 = CL_RegisterFont();
  dword_1684AEC = CL_RegisterFont();
  dword_1684AF0 = CL_RegisterFont();
  dword_1684AF4 = CL_RegisterFont();
  dword_1684AF8 = CL_RegisterFont();
  dword_1684AFC = CL_RegisterFont();
  result = Com_FindSoundAlias("$itemfocussound");
  dword_1684B00 = result;
  return result;
}

void __cdecl UI_FeederSelection(float feederID, int index)
{
  int v2;         // ebx
  int v3;         // edx
  int v4;         // ebx
  int *v5;        // eax
  int32_t v6;     // eax
  const char *v7; // eax
  char *v8;       // esi
  char v9;        // al
  char *v10;      // ebx

    if (a1 == 4.0) {
      v2 = 41 * ui_currentNetMap->current.integer;
        if (dword_1685E2C[v2] >= 0) {
          CIN_StopCinematic(dword_1685E2C[v2]);
          *(_DWORD *)((char *)&unk_1685E20 + v2 * 4 + 12) = -1;
        }
        if (dword_1685E10 > 0) {
          v3 = 0;
          v4 = 0;
          v5 = &sharedUiInfo;
            do {
                if (v5[1277]) {
                  if (v3 == a2)
                    goto LABEL_11;
                  ++v3;
                }
              ++v4;
              v5 += 41;
            }
          while (v4 != dword_1685E10);
        }
      v4 = 0;
    LABEL_11:
      Dvar_SetInt(ui_currentMap, v4);
      Dvar_SetInt(ui_currentNetMap, v4);
    }
    else if (a1 == 2.0) {
      v6 = dword_168BAB0;
      if ((int)_nel >= 1)
        v6 = a2;
      dword_168BAB0 = v6;
      LAN_GetServerInfo((char *)ui_netSource->current.integer,
                        dword_168BAB4[a2], UI_FeederSelection(float, int)::info,
                        1024);
      v7 = (const char *)Info_ValueForKey(UI_FeederSelection(float, int)::info,
                                          "mapname");
      v8 = va("levelshots/%s", v7);
      v9 = *v8;
        if (*v8) {
          v10 = v8;
            do {
              *v10++ = __tolower(v9);
              v9 = *v10;
            }
          while (*v10);
        }
      dword_169F348 = CL_RegisterMaterialNoMip(v8, 3);
        if (dword_169F34C >= 0) {
          CIN_StopCinematic(dword_169F34C);
          dword_169F34C = -1;
        }
    }
    else {
      if (a1 == 7.0)
        goto LABEL_22;
        if (a1 == 9.0) {
          dword_168B238 = a2;
          return;
        }
        if (a1 == 20.0) {
        LABEL_22:
          uiInfo[1].frameTime = a2;
        }
        else if (a1 == 24.0 && a2 >= 0 && a2 < uiInfo[1].cursorx) {
          Dvar_SetString(ui_playerProfileSelected,
                         *((char **)&uiInfo[1].cursory +
                           *(_DWORD *)&uiInfo[1].Menus[4 * a2 + 232]));
        }
    }
}

char const *__cdecl UI_GetGameTypeDisplayName(char const *pszGameType)
{
  char *v1; // esi
  int v3;   // edi
  int *i;   // ebx

  v1 = a1;
    if (dword_1685C08 > 0) {
      v3 = 0;
        for (i = &sharedUiInfo; I_stricmp(a1, (char *)i[1107]); i += 2) {
          if (++v3 >= dword_1685C08)
            return (int)v1;
        }
      return dword_1685C10[2 * v3];
    }
  return (int)v1;
}

char const *__cdecl UI_GetMapDisplayName(char const *pszMap)
{
  char *v1; // esi
  int v3;   // edi
  int *v4;  // ebx
  int *v5;  // [esp+1Ch] [ebp-1Ch]

  v1 = a1;
    if (dword_1685E10 > 0) {
      v3 = 0;
      v4 = &sharedUiInfo;
      v5 = dword_1685E14;
        while (I_stricmp(a1, (char *)v4[1238])) {
          ++v3;
          v5 += 41;
          v4 += 41;
          if (v3 >= dword_1685E10)
            return v1;
        }
      return (char *)*v5;
    }
  return v1;
}

struct Font_s *__cdecl UI_GetFontHandle(int fontEnum, float scale)
{
  float RealHeightFromVirtualHeight; // [esp+1Ch] [ebp-Ch]

    switch (a1) {
    case 2:
      return dword_1684AE8;
    case 3:
      return dword_1684AEC;
    case 5:
      return dword_1684AF0;
    }
  RealHeightFromVirtualHeight = GetRealHeightFromVirtualHeight(a2);
    if (a1 == 4) {
        if (*(float *)(ui_smallFont + 8) < RealHeightFromVirtualHeight) {
          if (RealHeightFromVirtualHeight < *(float *)(ui_bigFont + 8))
            return dword_1684AF8;
          return dword_1684AF4;
        }
      return dword_1684AEC;
    }
  if (*(float *)(ui_smallFont + 8) >= RealHeightFromVirtualHeight)
    return dword_1684AEC;
    if (RealHeightFromVirtualHeight < *(float *)(ui_extraBigFont + 8)) {
      if (RealHeightFromVirtualHeight < *(float *)(ui_bigFont + 8))
        return dword_1684AF8;
      return dword_1684AE8;
    }
  return dword_1684AFC;
}

int __cdecl UI_AnyFullScreenMenuVisible()
{
  return Menus_AnyFullScreenVisible(uiInfo);
}

int __cdecl UI_IsFullscreen()
{
  return Menus_AnyFullScreenVisible(uiInfo);
}

int __cdecl UI_CheckExecKey(int key)
{
  int Focused; // edx
  _DWORD *v2;  // eax

  Focused = Menu_GetFocused(uiInfo);
  if (g_editingField)
    return 1;
    if (a1 <= 256) {
        if (Focused) {
          v2 = *(_DWORD **)(Focused + 592);
            if (v2) {
                while (a1 != *v2) {
                  v2 = (_DWORD *)v2[2];
                  if (!v2)
                    return 0;
                }
              return 1;
            }
        }
    }
  return 0;
}

void __cdecl WM_setVisibility(char *, int)
{
  UNIMPLEMENTED();
}

void __cdecl WM_setItemPic(char *, char const *)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawTextWithCursor(char const *text, int maxChars,
                                   struct Font_s *font, float x, float y,
                                   int horzAlign, int vertAlign, float scale,
                                   float const *const color, int style,
                                   int cursorPos, char cursor)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawText(char const *text, int maxChars, struct Font_s *font,
                         float x, float y, int horzAlign, int vertAlign,
                         float scale, float const *const color, int style)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawTopBottom(float x, float y, float w, float h, int horzAlign,
                              int vertAlign, float size,
                              float const *const color)
{
  CL_DrawStretchPic(a1, *(float *)&a2, *((float *)&a2 + 1), a6, a4, a5, 0.0,
                    0.0, 0.0, 0.0, a7, dword_1684AE0);
  return CL_DrawStretchPic(a1, (float)(*(float *)&a2 + a3) - a6,
                           *((float *)&a2 + 1), a6, a4, a5, 0.0, 0.0, 0.0, 0.0,
                           a7, dword_1684AE0);
}

void __cdecl UI_DrawSides(float x, float y, float w, float h, int horzAlign,
                          int vertAlign, float size, float const *const color)
{
  CL_DrawStretchPic(*(float *)&a1, *((float *)&a1 + 1), a6, a3, a4, a5, 0.0,
                    0.0, 0.0, 0.0, a7, dword_1684AE0);
  return CL_DrawStretchPic((float)(*(float *)&a1 + a2) - a6,
                           *((float *)&a1 + 1), a6, a3, a4, a5, 0.0, 0.0, 0.0,
                           0.0, a7, dword_1684AE0);
}

void __cdecl UI_CloseXenonHudWaitScreen(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_CloseMenu(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl UI_CloseFocusedMenu()
{
  int result;  // eax
  int Catcher; // eax

  result = Menu_Count(uiInfo);
    if (result > 0) {
        if (Menu_GetFocused(uiInfo)) {
          result = Menus_AnyFullScreenVisible(uiInfo);
          if (!result)
            return Menus_CloseAll(uiInfo);
        }
        else {
          result = Key_GetCatcher();
            if ((result & 8) != 0) {
              Catcher = Key_GetCatcher();
              return (int)Key_SetCatcher(Catcher & 0xFFFFFFF7);
            }
        }
    }
  return result;
}

void __cdecl UI_CloseAll()
{
  UNIMPLEMENTED();
}

void __cdecl Text_PaintCenter(float, float, struct Font_s *, float,
                              float const *const, char const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl UI_CloseMenu_f()
{
  char *v0; // eax

  v0 = Cmd_Args(1);
  return Menus_CloseByName(uiInfo, v0);
}

void __cdecl UI_Shutdown()
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawRect(float x, float y, float width, float height,
                         int horzAlign, int vertAlign, float size,
                         float const *const color)
{
  CL_DrawStretchPic(*(float *)&a1, *((float *)&a1 + 1), a2, a6, a4, a5, 0.0,
                    0.0, 0.0, 0.0, a7, dword_1684AE0);
  CL_DrawStretchPic(*(float *)&a1, (float)(*((float *)&a1 + 1) + a3) - a6, a2,
                    a6, a4, a5, 0.0, 0.0, 0.0, 0.0, a7, dword_1684AE0);
  CL_DrawStretchPic(*(float *)&a1, *((float *)&a1 + 1), a6, a3, a4, a5, 0.0,
                    0.0, 0.0, 0.0, a7, dword_1684AE0);
  return CL_DrawStretchPic((float)(*(float *)&a1 + a2) - a6,
                           *((float *)&a1 + 1), a6, a3, a4, a5, 0.0, 0.0, 0.0,
                           0.0, a7, dword_1684AE0);
}

char const *__cdecl UI_SafeTranslateString(char const *reference)
{
  char *v1;           // ebx
  const char *result; // eax

  v1 = __src;
    if (*__src == 21) {
      v1 = __src + 1;
    }
    else {
      result = SEH_StringEd_GetString(__src);
      if (result)
        return result;
    }
    if (*(_BYTE *)(loc_warnings + 8)) {
      if (*(_BYTE *)(loc_warningsAsErrors + 8))
        Com_Error(6, stru_2AA0B4.domain.enumeration.stringCount, (char)v1);
      else
        Com_Printf("^3WARNING: Could not translate string \"%s\"\n", v1);
      strcpy(UI_SafeTranslateString(char const *)::errorString,
             "^1UNLOCALIZED(^7");
      I_strncat(UI_SafeTranslateString(char const *)::errorString, 1024, v1);
      I_strncat(UI_SafeTranslateString(char const *)::errorString, 1024,
                "^1)^7");
      return UI_SafeTranslateString(char const *)::errorString;
    }
    else {
      strcpy(UI_SafeTranslateString(char const *)::errorString, v1);
      return UI_SafeTranslateString(char const *)::errorString;
    }
}

int __cdecl UI_OwnerDrawWidth(int ownerDraw, struct Font_s *font, float scale)
{
  UNIMPLEMENTED();
}

char const *__cdecl UI_FeederItemText(float feederID, int index, int column,
                                      struct Material **handle)
{
  int v4;           // ecx
  int v5;           // edx
  int *v6;          // eax
  char *v7;         // ebx
  float v9;         // xmm0_4
  int ServerCount;  // eax
  const char *v11;  // eax
  int v12;          // eax
  const char *v13;  // eax
  const char *v14;  // ebx
  const char *v15;  // eax
  char *v16;        // eax
  int v17;          // edi
  int *v18;         // esi
  const char *v19;  // eax
  unsigned int v20; // eax
  char *v21;        // [esp+50h] [ebp+8h]
  const char *v22;  // [esp+54h] [ebp+Ch]

  *a4 = 0;
    if (a1 == 4.0) {
        if (dword_1685E10 > 0) {
          v4 = 0;
          v5 = 0;
          v6 = &sharedUiInfo;
            do {
                if (v6[1277]) {
                  if (v4 == a2)
                    return (const gentity_s *)dword_1685E14[41 * v5];
                  ++v4;
                }
              ++v5;
              v6 += 41;
            }
          while (dword_1685E10 != v5);
        }
      return &inData;
    }
  v9 = a1;
    if (a1 == 2.0) {
      ServerCount = LAN_GetServerCount(ui_netSource->current.integer);
        if (ServerCount != dword_169F338) {
          dword_169F338 = ServerCount;
            if (_nel) {
              dword_168BAB0 = -1;
              UI_BuildServerDisplayList(1);
            }
        }
      if (a2 < 0 || a2 >= (int)_nel)
        return &inData;
        if (a3 != UI_FeederItemText(float, int, int, Material **)::lastColumn ||
            (signed int)(uiInfo->realTime + 5000) <
                UI_FeederItemText(float, int, int, Material **)::lastTime) {
          LAN_GetServerInfo(
              (char *)ui_netSource->current.integer, dword_168BAB4[a2],
              UI_FeederItemText(float, int, int, Material **)::info, 1024);
          UI_FeederItemText(float, int, int, Material **)::lastColumn = a3;
          UI_FeederItemText(float, int, int, Material **)::lastTime =
              uiInfo->realTime;
        }
      v11 = (const char *)Info_ValueForKey(
          UI_FeederItemText(float, int, int, Material **)::info, "ping");
      v12 = atoi(v11);
        switch (a3) {
        case 0u:
          v13 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "pswrd");
          goto LABEL_51;
        case 1u:
          v19 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "hw");
          v20 = atoi(v19);
          if (v20 > 7)
            return &inData;
          *a4 = (Material *)dword_168B014[v20];
          return &inData;
        case 2u:
            if (v12 > 0) {
              v16 = (char *)Info_ValueForKey(
                  UI_FeederItemText(float, int, int, Material **)::info,
                  "hostname");
              I_strncpyz(
                  UI_FeederItemText(float, int, int, Material **)::clientBuff,
                  v16, 20);
              return (const gentity_s *)UI_FeederItemText(
                  float, int, int, Material **)::clientBuff;
            }
          v22 = "addr";
          return Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, v22);
        case 3u:
          v7 = (char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "mapname");
          if (dword_1685E10 <= 0)
            return (const gentity_s *)v7;
          v17 = 0;
          v18 = &sharedUiInfo;
          break;
        case 4u:
          v14 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info,
              "sv_maxclients");
          v15 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "clients");
          Com_sprintf(
              UI_FeederItemText(float, int, int, Material **)::clientBuff,
              0x20u, "%s (%s)", v15, v14);
          return (const gentity_s *)UI_FeederItemText(float, int, int,
                                                      Material **)::clientBuff;
        case 5u:
            if (!Info_ValueForKey(
                    UI_FeederItemText(float, int, int, Material **)::info,
                    "gametype") ||
                !LOBYTE(Info_ValueForKey(UI_FeederItemText(float, int, int,
                                                           Material **)::info,
                                         "gametype")
                            ->s.number)) {
              return (const gentity_s *)"?";
            }
          v22 = "gametype";
          return Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, v22);
        case 6u:
          v13 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "voice");
          goto LABEL_51;
        case 7u:
          v13 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "pure");
          goto LABEL_51;
        case 8u:
          v13 = (const char *)Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, "mod");
        LABEL_51:
          v7 = "X";
          if (!atoi(v13))
            return &inData;
          return (const gentity_s *)v7;
        case 9u:
          if (v12 <= 0)
            return (const gentity_s *)"...";
          v22 = "ping";
          return Info_ValueForKey(
              UI_FeederItemText(float, int, int, Material **)::info, v22);
        default:
          v9 = a1;
          goto LABEL_30;
        }
        while (I_stricmp(v7, (char *)v18[1238])) {
          ++v17;
          v18 += 41;
          if (v17 >= dword_1685E10)
            return (const gentity_s *)v7;
        }
      return (const gentity_s *)dword_1685E14[41 * v17];
    }
    if (a1 != 13.0) {
        if (a1 == 7.0) {
          if (a2 < 0 || a2 >= dword_1684B04)
            return &inData;
          return (const gentity_s *)((char *)&unk_1684B08 + 32 * a2);
        }
        if (a1 != 9.0) {
            if (a1 != 20.0) {
            LABEL_30:
              if (v9 == 24.0 && a2 >= 0 && a2 < uiInfo[1].cursorx)
                return (const gentity_s *)*(
                    &uiInfo[1].cursory +
                    *(_DWORD *)&uiInfo[1].Menus[4 * a2 + 232]);
              return &inData;
            }
          if (a2 < 0 || a2 >= dword_1684B04)
            return &inData;
          if (a3 == 1)
            return (const gentity_s *)((char *)&unk_1684B08 + 32 * a2);
          if (!(unsigned __int8)CL_IsPlayerMuted(
                  *(_DWORD *)&dword_1685B08[4 * a2]))
            return &inData;
          v21 = "MP_MUTED";
          return (const gentity_s *)UI_SafeTranslateString(v21);
        }
      if (a2 < 0 || a2 >= dword_168B234)
        return &inData;
      v7 = (char *)dword_168B038[2 * a2];
      if (!v7 || !*v7)
        return (const gentity_s *)(&dword_168B034)[2 * a2];
      return (const gentity_s *)v7;
    }
  if (a2 < 0 || a2 >= dword_16A04A8 || a3 > 3)
    return &inData;
  v7 = (char *)dword_169F7E8[4 * a2 + a3];
  if (*v7 != 64)
    return (const gentity_s *)v7;
  v21 = v7 + 1;
  return (const gentity_s *)UI_SafeTranslateString(v21);
}

int __cdecl UI_FeederCount(float feederID)
{
  DvarValue current;   // esi
  int v2;              // edi
  int v3;              // ebx
  int *v4;             // edx
  int ServerCount;     // eax
  signed int realTime; // eax

    if (a1 != 4.0) {
      if (a1 == 9.0)
        return dword_168B234;
        if (a1 == 2.0) {
          ServerCount = LAN_GetServerCount(ui_netSource->current.integer);
            if (ServerCount != dword_169F338) {
              dword_169F338 = ServerCount;
                if (_nel) {
                  dword_168BAB0 = -1;
                  UI_BuildServerDisplayList(1);
                }
            }
          return _nel;
        }
      if (a1 == 13.0)
        return dword_16A04A8;
        if (a1 == 7.0 || a1 == 20.0) {
          realTime = uiInfo->realTime;
            if (realTime > (signed int)uiInfo[1].realTime) {
              uiInfo[1].realTime = realTime + 3000;
              UI_BuildPlayerList();
            }
          return dword_1684B04;
        }
      if (a1 == 24.0)
        return uiInfo[1].cursorx;
      return 0;
    }
  current = ui_netGameType->current;
  if (dword_1685E10 <= 0)
    return 0;
  v2 = 0;
  v3 = 0;
  v4 = &sharedUiInfo;
    do {
      v4[1277] = 0;
        if (((v4[1242] >> current.enabled) & 1) != 0) {
          ++v3;
          v4[1277] = 1;
        }
      ++v2;
      v4 += 41;
    }
  while (dword_1685E10 > v2);
  return v3;
}

void __cdecl UI_OverrideCursorPos(struct itemDef_s *item)
{
  float v1;         // xmm0_4
  int v2;           // ecx
  int v3;           // eax
  int *v4;          // edx
  itemDefData_t v5; // esi
  int v6;           // eax
  int v7;           // ebx
  int v8;           // eax

  v1 = *(float *)a1->special;
    if (v1 == 4.0) {
        if (dword_1685E10 > 0) {
          v2 = 0;
          v3 = 0;
          v4 = &sharedUiInfo;
            do {
                if (v4[1277]) {
                  if (v3 == ui_currentNetMap->current.integer)
                    goto LABEL_9;
                  ++v2;
                }
              ++v3;
              v4 += 41;
            }
          while (dword_1685E10 != v3);
        }
      v2 = 0;
    LABEL_9:
      Item_SetCursorPos(a1, v2);
    }
    else if (v1 == 2.0) {
      v5.listBox = (int32_t)a1->typeData;
        if (*(_DWORD *)(v5.listBox + 16)) {
            if (dword_168BAB0 >= 0) {
              v6 = *(_DWORD *)a1->cursorPos;
                if (v6 >= *(_DWORD *)v5.listBox &&
                    v6 <= *(_DWORD *)(v5.listBox + 16)) {
                  v7 = dword_168BAB0 - v6;
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                      *(_DWORD *)v5.listBox + dword_168BAB0 -
                                          v6);
                  ListBox_SetEndPos((listBoxDef_s *)v5.listBox,
                                    *(_DWORD *)(v5.listBox + 16) + v7);
                  ListBox_SetCursorPos((listBoxDef_s *)v5.listBox,
                                       *(_DWORD *)(v5.listBox + 36) + v7);
                  Item_SetCursorPos(a1, dword_168BAB0);
                  v8 = Item_ListBox_MaxScroll(a1);
                  if (v8 < *(_DWORD *)v5.listBox)
                    ListBox_SetStartPos((listBoxDef_s *)v5.listBox, v8);
                  if (*(int *)v5.listBox < 0)
                    ListBox_SetStartPos((listBoxDef_s *)v5.listBox, 0);
                }
            }
        }
        else {
          Item_SetCursorPos(a1, -1);
        }
    }
}

void __cdecl UI_KeyEvent(int key, int down)
{
  menuDef_t *Focused; // ebx
  char Bool;          // al
  int v4;             // edx
  int Catcher;        // eax

    if ((int)Menu_Count(uiInfo) > 0) {
      Focused = (menuDef_t *)Menu_GetFocused(uiInfo);
      if (!Focused)
        goto LABEL_13;
      Bool = Dvar_GetBool("cl_bypassMouseInput");
      v4 = 1;
      if (!Bool)
        v4 = UI_KeyEvent(int, int)::bypassKeyClear;
      UI_KeyEvent(int, int)::bypassKeyClear = v4;
      if (a1 != 27 || !a2 || Menus_AnyFullScreenVisible(uiInfo) ||
          Focused->onESC)
        Menu_HandleKey(uiInfo, Focused, a1, a2);
      else
        Menus_CloseAll(uiInfo);
        if (!Menu_GetFocused(uiInfo)) {
        LABEL_13:
            if ((Key_GetCatcher() & 8) != 0) {
              Catcher = Key_GetCatcher();
              Key_SetCatcher(Catcher & 0xFFFFFFF7);
              if (!UI_KeyEvent(int, int)::bypassKeyClear)
                Key_ClearStates();
              UI_KeyEvent(int, int)::bypassKeyClear = 0;
              Dvar_SetIntByName("cl_paused", 0);
            }
        }
    }
}

void __cdecl UI_Pause(int b)
{
  int Catcher; // eax

    if (a1) {
      Dvar_SetIntByName("cl_paused", (DvarValue)1);
      Key_SetCatcher(8);
    }
    else {
      Catcher = Key_GetCatcher();
      Key_SetCatcher(Catcher & 0xFFFFFFF7);
      Key_ClearStates();
      Dvar_SetIntByName("cl_paused", 0);
    }
}

void __cdecl UI_RunMenuScript(char const **args)
{
  char *v8;                 // eax
  char *v9;                 // eax
  char *String;             // edi
  DvarValue current;        // ebx
  int v12;                  // esi
  int *v13;                 // edx
  char *VariantString;      // eax
  char *v15;                // eax
  char *v16;                // eax
  char *v17;                // eax
  char *v18;                // eax
  char *v19;                // eax
  char *v20;                // eax
  char *v21;                // edi
  int v22;                  // esi
  unsigned int v23;         // ebx
  int v24;                  // esi
  int v25;                  // esi
  int *v26;                 // ebx
  char *v27;                // eax
  DvarValue v28;            // edx
  char *v29;                // eax
  char *v30;                // eax
  displayContextDef_s *v31; // edx
  displayContextDef_s *v32; // ecx
  int32_t v33;              // eax
  displayContextDef_s *v34; // edx
  int32_t v35;              // eax
  displayContextDef_s *v36; // edx
  uint32_t v37;             // ebx
  menuDef_t *v38;           // eax
  int32_t v39;              // eax
  uint32_t v40;             // ebx
  menuDef_t *v41;           // eax
  int v42;                  // edi
  displayContextDef_s *v43; // ebx
  int32_t cursorx;          // esi
  char *integer;            // ebx
  displayContextDef_s *v46; // edx
  int32_t v47;              // esi
  char *v48;                // eax
  displayContextDef_s *v49; // eax
  int32_t v50;              // edx
  int32_t v51;              // ebx
  displayContextDef_s *v52; // edx
  uint32_t v53;             // ebx
  menuDef_t *v54;           // eax
  char *v55;                // ebx
  displayContextDef_s *v56; // edx
  int32_t v57;              // esi
  int v58;                  // ecx
  int32_t v59;              // eax
  displayContextDef_s *v60; // ebx
  int32_t v61;              // ecx
  displayContextDef_s *v62; // ebx
  int32_t v63;              // esi
  displayContextDef_s *v64; // edx
  displayContextDef_s *v65; // ecx
  int32_t v66;              // eax
  displayContextDef_s *v67; // edx
  int32_t v68;              // esi
  int v69;                  // ebx
  menuDef_t *v70;           // eax
  int32_t v71;              // eax
  uint32_t v72;             // ebx
  menuDef_t *v73;           // eax
  int32_t v74;              // eax
  uint32_t v75;             // ebx
  menuDef_t *v76;           // eax
  int v77;                  // edx
  int v78;                  // eax
  char *v79;                // esi
  unsigned int v80;         // ecx
  int v81;                  // ebx
  char *v82;                // eax
  signed __int32 v83;       // eax
  int ServerCount;          // eax
  int v85;                  // eax
  char *v86;                // eax
  signed __int32 v87;       // eax
  int Catcher;              // eax
  signed int frameTime;     // eax
  char *v90;                // eax
  signed int v91;           // eax
  char *v92;                // eax
  int v93;                  // eax
  int v94;                  // eax
  char *v95;                // eax
  char *v96;                // eax
  char *v97;                // eax
  char *v98;                // eax
  char *v99;                // eax
  char *v100;               // eax
  char *v101;               // eax
  int v102;                 // eax
  float Int;                // xmm0_4
  int v104;                 // eax
  signed int v105;          // eax
  bool v106;                // si
  char *v107;               // eax
  bool v108;                // si
  char *v109;               // eax
  char v110;                // [esp+8h] [ebp-2C80h]
  char v111;                // [esp+8h] [ebp-2C80h]
  char v112;                // [esp+8h] [ebp-2C80h]
  char v113;                // [esp+8h] [ebp-2C80h]
  char v114;                // [esp+8h] [ebp-2C80h]
  char v115;                // [esp+8h] [ebp-2C80h]
  char v116;                // [esp+8h] [ebp-2C80h]
  char v117;                // [esp+8h] [ebp-2C80h]
  int FileList;             // [esp+28h] [ebp-2C60h]
  char *__s1;               // [esp+2Ch] [ebp-2C5Ch]
  int v120;                 // [esp+30h] [ebp-2C58h]
  void **v121;              // [esp+34h] [ebp-2C54h]
  int v122;                 // [esp+38h] [ebp-2C50h]
  int *v123;                // [esp+3Ch] [ebp-2C4Ch]
  char v124[4096];          // [esp+4Ch] [ebp-2C3Ch] BYREF
  char v125[1024];          // [esp+104Ch] [ebp-1C3Ch] BYREF
  char v126[1024];          // [esp+144Ch] [ebp-183Ch] BYREF
  char v127[1024];          // [esp+184Ch] [ebp-143Ch] BYREF
  char __src[1024];         // [esp+1C4Ch] [ebp-103Ch] BYREF
  char *v129[256];          // [esp+204Ch] [ebp-C3Ch] BYREF
  char v130[1024];          // [esp+244Ch] [ebp-83Ch] BYREF
  char v131[4];             // [esp+284Ch] [ebp-43Ch] BYREF
  char v132[4];             // [esp+2850h] [ebp-438h] BYREF
  char v133[4];             // [esp+2854h] [ebp-434h] BYREF
  char v134[1012];          // [esp+2858h] [ebp-430h] BYREF
  char __dst[32];           // [esp+2C4Ch] [ebp-3Ch] BYREF
  int v136[7];              // [esp+2C6Ch] [ebp-1Ch] BYREF

  if (!String_Parse(a8, v130, 1024))
    return;
    if (!I_stricmp(v130, "StartServer")) {
      Dvar_SetBoolByName((dvar_s *)&stru_2A83E4, 0);
      v8 = va("%i", *(_DWORD *)(ui_dedicated + 8));
      Dvar_SetFromStringByNameFromSource((dvar_s *)&stru_21675C, (DvarValue)v8,
                                         DVAR_SOURCE_EXTERNAL);
      Dvar_SetStringByName(
          "g_gametype",
          *(char **)&dword_1685C0C[8 * ui_netGameType->current.integer]);
      v9 = va("wait ; wait ; map %s\n",
              *(const char *
                    *)&dword_1685E18[164 * ui_currentNetMap->current.integer]);
      Cbuf_ExecuteText(2, v9, v111);
      return;
    }
    if (!I_stricmp(v130, "resetDefaults")) {
      Cbuf_ExecuteText(0, "dvar_restart\n", v110);
      Cbuf_ExecuteText(0, "exec default_mp.cfg\n", v112);
      Cbuf_ExecuteText(0, "exec language.cfg\n", v113);
      Cbuf_ExecuteText(0, "setRecommended\n", v114);
      Controls_SetDefaults();
      Dvar_SetBoolByName((dvar_s *)&stru_216870, 1);
      Dvar_SetBoolByName((dvar_s *)&stru_216870.hashNext, 1);
      Cbuf_ExecuteText(2, "vid_restart\n", v115);
      return;
    }
    if (!I_stricmp(v130, "getCDKey")) {
      CLUI_GetCDKey(v131, 17, __src);
      Dvar_SetStringByName("cdkey1", (char *)&inData);
      Dvar_SetStringByName("cdkey2", (char *)&inData);
      Dvar_SetStringByName("cdkey3", (char *)&inData);
      Dvar_SetStringByName("cdkey4", (char *)&inData);
      Dvar_SetStringByName("cdkey5", (char *)&inData);
        if (~(strlen(v131) + 1) == -18) {
          I_strncpyz(__dst, v131, 5);
          Dvar_SetStringByName("cdkey1", __dst);
          I_strncpyz(__dst, v132, 5);
          Dvar_SetStringByName("cdkey2", __dst);
          I_strncpyz(__dst, v133, 5);
          Dvar_SetStringByName("cdkey3", __dst);
          I_strncpyz(__dst, v134, 5);
          Dvar_SetStringByName("cdkey4", __dst);
        }
        if (~(strlen(__src) + 1) == -6) {
          I_strncpyz(__dst, __src, 5);
          Dvar_SetStringByName("cdkey5", __dst);
        }
      return;
    }
    if (!I_stricmp(v130, "verifyCDKey")) {
      v131[0] = 0;
      VariantString = (char *)Dvar_GetVariantString("cdkey1");
      I_strncat(v131, 1024, VariantString);
      v15 = (char *)Dvar_GetVariantString("cdkey2");
      I_strncat(v131, 1024, v15);
      v16 = (char *)Dvar_GetVariantString("cdkey3");
      I_strncat(v131, 1024, v16);
      v17 = (char *)Dvar_GetVariantString("cdkey4");
      I_strncat(v131, 1024, v17);
      __src[0] = 0;
      v18 = (char *)Dvar_GetVariantString("cdkey5");
      I_strncat(__src, 1024, v18);
        if (CL_CDKeyValidate(v131, __src)) {
          v19 = (char *)UI_SafeTranslateString("EXE_CDKEYVALID");
          Dvar_SetStringByName("ui_cdkeyvalid", v19);
          CLUI_SetCDKey(v131, __src);
        }
        else {
          v20 = (char *)UI_SafeTranslateString("EXE_CDKEYINVALID");
          Dvar_SetStringByName("ui_cdkeyvalid", v20);
        }
      return;
    }
    if (!I_stricmp(v130, "loadArenas")) {
      UI_LoadArenas();
      String = (char *)Dvar_GetString("g_gametype");
        if (dword_1685C08 > 0) {
          v25 = 0;
          v26 = sharedUiInfo;
            while (I_stricmp(String, (char *)v26[1107])) {
              ++v25;
              v26 += 2;
              if (dword_1685C08 <= v25)
                goto LABEL_15;
            }
          Dvar_SetInt(ui_netGameType, v25);
          Dvar_SetString(ui_netGameTypeName, *(char **)&dword_1685C0C[8 * v25]);
        }
    LABEL_15:
      current = ui_netGameType->current;
        if (dword_1685E10 > 0) {
          v12 = 0;
          v13 = sharedUiInfo;
            do {
              v13[1277] = 0;
              if (((v13[1242] >> current.enabled) & 1) != 0)
                v13[1277] = 1;
              ++v12;
              v13 += 41;
            }
          while (dword_1685E10 > v12);
        }
      Menu_SetFeederSelection(uiInfo, 0, 4, 0, "createserver_maps");
      UI_SelectCurrentMap();
      return;
    }
    if (!I_stricmp(v130, "loadGameInfo")) {
      UI_GetGameTypesList();
      return;
    }
    if (!I_stricmp(v130, "LoadMods")) {
      dword_168B234 = 0;
      v21 = v124;
      FileList =
          FS_GetFileList("$modlist", (char *)&inData, FS_LIST_ALL, v124, 2048);
        if (FileList > 0) {
          __s1 = v124;
          v120 = 0;
          v22 = dword_168B234;
            while (1) {
              v23 = strlen(v21) + 1;
              (&dword_168B034)[2 * v22] = (char *)String_Alloc(__s1);
              v24 = dword_168B234;
              dword_168B038[2 * v24] = (int)String_Alloc(&__s1[v23]);
              __s1 += strlen(&__s1[v23]) + v23 + 1;
              v22 = ++dword_168B234;
              if (dword_168B234 > 63)
                break;
              if (FileList == ++v120)
                break;
              v21 = __s1;
            }
        }
      return;
    }
    if (!I_stricmp(v130, "voteTypeMap")) {
      v27 = va(
          "callvote typemap %s %s\n",
          *(const char **)&dword_1685C0C[8 * ui_netGameType->current.integer],
          *(const char *
                *)&dword_1685E18[164 * ui_currentNetMap->current.integer]);
      Cbuf_ExecuteText(2, v27, v116);
      return;
    }
    if (!I_stricmp(v130, "voteMap")) {
      v28 = ui_currentNetMap->current;
        if (v28.integer >= 0 && v28.integer < dword_1685E10) {
          v29 = va("callvote map %s\n",
                   *(const char **)&dword_1685E18[164 * v28.integer]);
          Cbuf_ExecuteText(2, v29, v110);
        }
      return;
    }
    if (!I_stricmp(v130, "voteGame")) {
      v30 = va(
          "callvote g_gametype %s\n",
          *(const char **)&dword_1685C0C[8 * ui_netGameType->current.integer]);
      Cbuf_ExecuteText(2, v30, v110);
      return;
    }
    if (!I_stricmp(v130, "saveControls")) {
      Controls_SetConfig();
      return;
    }
    if (!I_stricmp(v130, "loadControls")) {
      Controls_GetConfig();
      return;
    }
    if (!I_stricmp(v130, "clearError")) {
      Dvar_SetStringByName("com_errorMessage", (char *)&inData);
      Dvar_SetBoolByName((dvar_s *)&stru_2AABC8, 0);
      return;
    }
    if (!I_stricmp(v130, (char *)&stru_2AABC8.reset)) {
      UI_StartServerRefresh(1);
      UI_BuildServerDisplayList(1);
      return;
    }
    if (!I_stricmp(v130, (char *)&stru_2AABC8.hashNext)) {
      UI_StartServerRefresh(0);
      UI_BuildServerDisplayList(1);
      return;
    }
    if (!I_stricmp(v130, "addPlayerProfiles")) {
      uiInfo[1].cursorx = 0;
      *(_DWORD *)&uiInfo[1].Menus[228] = 1;
      v121 = (void **)FS_ListFiles("players", "/", FS_LIST_ALL, v136);
        if (v136[0] > 0) {
          v42 = 0;
            do {
              v43 = uiInfo;
              cursorx = uiInfo[1].cursorx;
              *(&v43[1].cursory + cursorx) =
                  (int32_t)String_Alloc((char *)v121[v42]);
              ++uiInfo[1].cursorx;
              ++v42;
            }
          while (v136[0] > v42);
        }
      FS_FreeFileList(v121);
      v31 = uiInfo;
      v32 = uiInfo;
      v33 = uiInfo[1].cursorx;
        if (v33) {
            if (v33 > 0) {
              v39 = 0;
                do {
                  *(_DWORD *)&v32[1].Menus[4 * v39 + 232] = v39;
                  ++v39;
                  v32 = uiInfo;
                }
              while (uiInfo[1].cursorx > v39);
            }
          qsort(&v32[1].Menus[232], v32[1].cursorx, 4u,
                (int(__cdecl *)(const void *,
                                const void *))UI_PlayerProfilesQsortCompare);
          v31 = uiInfo;
            if ((signed int)(uiInfo->openMenuCount - 1) >= 0) {
              v40 = uiInfo->openMenuCount - 1;
                do {
                  v41 = *(menuDef_t **)&v31->menuStack[4 * v40];
                    if ((v41->window.dynamicFlags[0] & 4) != 0) {
                      Menu_SetFeederSelection(v31, v41, 24, 0, 0);
                      v31 = uiInfo;
                    }
                  --v40;
                }
              while (v40 != -1);
            }
        }
      goto LABEL_58;
    }
    if (!I_stricmp(v130, "sortPlayerProfiles")) {
      *(_DWORD *)&uiInfo[1].Menus[228] = *(_DWORD *)&uiInfo[1].Menus[228] == 0;
      v34 = uiInfo;
        if (uiInfo[1].cursorx) {
            if (uiInfo[1].cursorx > 0) {
              v35 = 0;
                do {
                  *(_DWORD *)&v34[1].Menus[4 * v35 + 232] = v35;
                  ++v35;
                  v34 = uiInfo;
                }
              while (uiInfo[1].cursorx > v35);
            }
          qsort(&v34[1].Menus[232], v34[1].cursorx, 4u,
                (int(__cdecl *)(const void *,
                                const void *))UI_PlayerProfilesQsortCompare);
          v36 = uiInfo;
            if ((signed int)(uiInfo->openMenuCount - 1) >= 0) {
              v37 = uiInfo->openMenuCount - 1;
                while (1) {
                  v38 = *(menuDef_t **)&v36->menuStack[4 * v37];
                  if ((v38->window.dynamicFlags[0] & 4) != 0)
                    Menu_SetFeederSelection(v36, v38, 24, 0, 0);
                  if (--v37 == -1)
                    break;
                  v36 = uiInfo;
                }
            }
        }
      return;
    }
    if (!I_stricmp(v130, "selectActivePlayerProfile")) {
      integer = (char *)com_playerProfile->current.integer;
      v46 = uiInfo;
        if (uiInfo[1].cursorx > 0) {
          v47 = 0;
            while (I_stricmp(integer,
                             *((char **)&v46[1].cursory +
                               *(_DWORD *)&v46[1].Menus[4 * v47 + 232]))) {
              ++v47;
              v46 = uiInfo;
              if (uiInfo[1].cursorx <= v47)
                return;
            }
            if (v47 >= 0) {
              v52 = uiInfo;
                if (uiInfo[1].cursorx > v47 &&
                    (signed int)(uiInfo->openMenuCount - 1) >= 0) {
                  v53 = uiInfo->openMenuCount - 1;
                    while (1) {
                      v54 = *(menuDef_t **)&v52->menuStack[4 * v53];
                      if ((v54->window.dynamicFlags[0] & 4) != 0)
                        Menu_SetFeederSelection(v52, v54, 24, v47, 0);
                      if (--v53 == -1)
                        break;
                      v52 = uiInfo;
                    }
                }
            }
        }
      return;
    }
    if (!I_stricmp(v130, "createPlayerProfile")) {
      v48 = (char *)ui_playerProfileNameNew->current.integer;
        if (*v48) {
          I_strncpyz(__dst, v48, 32);
          Dvar_SetString(ui_playerProfileNameNew, (char *)&inData);
          v49 = uiInfo;
          v50 = uiInfo[1].cursorx;
            if (v50 == 64) {
              Menus_OpenByName(uiInfo, "profile_create_too_many_popmenu");
            }
            else if (v50 <= 0) {
            LABEL_95:
                if ((unsigned __int8)Com_NewPlayerProfile(__dst)) {
                  v62 = uiInfo;
                  v63 = uiInfo[1].cursorx;
                  *(&v62[1].cursory + v63) = (int32_t)String_Alloc(__dst);
                  ++uiInfo[1].cursorx;
                  v64 = uiInfo;
                  v65 = uiInfo;
                  v66 = uiInfo[1].cursorx;
                    if (v66) {
                        if (v66 > 0) {
                          v71 = 0;
                            do {
                              *(_DWORD *)&v65[1].Menus[4 * v71 + 232] = v71;
                              ++v71;
                              v65 = uiInfo;
                            }
                          while (uiInfo[1].cursorx > v71);
                        }
                      qsort(&v65[1].Menus[232], v65[1].cursorx, 4u,
                            (int(__cdecl *)(const void *, const void *))
                                UI_PlayerProfilesQsortCompare);
                      v64 = uiInfo;
                        if ((signed int)(uiInfo->openMenuCount - 1) >= 0) {
                          v72 = uiInfo->openMenuCount - 1;
                            do {
                              v73 = *(menuDef_t **)&v64->menuStack[4 * v72];
                                if ((v73->window.dynamicFlags[0] & 4) != 0) {
                                  Menu_SetFeederSelection(v64, v73, 24, 0, 0);
                                  v64 = uiInfo;
                                }
                              --v72;
                            }
                          while (v72 != -1);
                        }
                    }
                  Dvar_SetInt(ui_playerProfileCount, v64[1].cursorx);
                  v67 = uiInfo;
                    if (uiInfo[1].cursorx > 0) {
                      v68 = 0;
                        while (I_stricmp(
                            __dst,
                            *((char **)&v67[1].cursory +
                              *(_DWORD *)&v67[1].Menus[4 * v68 + 232]))) {
                          ++v68;
                          v67 = uiInfo;
                          if (uiInfo[1].cursorx <= v68)
                            goto LABEL_119;
                        }
                      v67 = uiInfo;
                    }
                    else {
                    LABEL_119:
                      v68 = -1;
                    }
                    if ((signed int)(v67->openMenuCount - 1) >= 0) {
                      v69 = v67->openMenuCount - 1;
                        while (1) {
                          v70 = *(menuDef_t **)&v67->menuStack[4 * v69];
                          if ((v70->window.dynamicFlags[0] & 4) != 0)
                            Menu_SetFeederSelection(v67, v70, 24, v68, 0);
                          if (--v69 == -1)
                            break;
                          v67 = uiInfo;
                        }
                    }
                }
                else {
                  Menus_OpenByName(uiInfo, "profile_create_fail_popmenu");
                }
            }
            else {
              v51 = 0;
                while (I_stricmp(__dst, *((char **)&v49[1].cursory + v51))) {
                  ++v51;
                  v49 = uiInfo;
                  if (uiInfo[1].cursorx <= v51)
                    goto LABEL_95;
                }
              Menus_OpenByName(uiInfo, "profile_exists_popmenu");
            }
        }
      return;
    }
    if (!I_stricmp(v130, "deletePlayerProfile")) {
      if (!uiInfo[1].cursorx)
        return;
        if (!(unsigned __int8)Com_DeletePlayerProfile(
                (char *)ui_playerProfileSelected->current.integer)) {
          Menus_OpenByName(uiInfo, "profile_delete_fail_popmenu");
          return;
        }
      v55 = (char *)ui_playerProfileSelected->current.integer;
      v56 = uiInfo;
        if (uiInfo[1].cursorx > 0) {
          v57 = 0;
            while (I_stricmp(v55, *((char **)&v56[1].cursory +
                                    *(_DWORD *)&v56[1].Menus[4 * v57 + 232]))) {
              ++v57;
              v56 = uiInfo;
              if (v57 >= uiInfo[1].cursorx)
                goto LABEL_111;
            }
          v56 = uiInfo;
        }
        else {
        LABEL_111:
          v57 = -1;
        }
      v58 = *(_DWORD *)&v56[1].Menus[4 * v57 + 232];
      --v56[1].cursorx;
      v59 = uiInfo[1].cursorx;
        if (v59) {
          *(&uiInfo[1].cursory + v58) = *(&uiInfo[1].cursory + v59);
          v31 = uiInfo;
          v60 = uiInfo;
          v61 = uiInfo[1].cursorx;
          if (v57 == v61)
            v57 = v61 - 1;
            if (v61) {
                if (v61 > 0) {
                  v74 = 0;
                    do {
                      *(_DWORD *)&v60[1].Menus[4 * v74 + 232] = v74;
                      ++v74;
                      v60 = uiInfo;
                    }
                  while (uiInfo[1].cursorx > v74);
                }
              qsort(&v60[1].Menus[232], v60[1].cursorx, 4u,
                    (int(__cdecl *)(const void *, const void *))
                        UI_PlayerProfilesQsortCompare);
              v31 = uiInfo;
                if ((signed int)(uiInfo->openMenuCount - 1) >= 0) {
                  v75 = uiInfo->openMenuCount - 1;
                    do {
                      v76 = *(menuDef_t **)&v31->menuStack[4 * v75];
                        if ((v76->window.dynamicFlags[0] & 4) != 0) {
                          Menu_SetFeederSelection(v31, v76, 24, v57, 0);
                          v31 = uiInfo;
                        }
                      --v75;
                    }
                  while (v75 != -1);
                }
            }
        }
        else {
          Dvar_SetString(ui_playerProfileSelected, (char *)&inData);
          v31 = uiInfo;
        }
    LABEL_58:
      Dvar_SetInt(ui_playerProfileCount, v31[1].cursorx);
      return;
    }
    if (!I_stricmp(v130, "loadPlayerProfile")) {
      if (*(_BYTE *)ui_playerProfileSelected->current.integer)
        Com_ChangePlayerProfile(
            (char *)ui_playerProfileSelected->current.integer);
      return;
    }
    if (!I_stricmp(v130, "LoadMovies")) {
      v77 = FS_GetFileList("video", "roq", FS_LIST_PURE_ONLY, v124, 4096);
      dword_168B63C = v77;
        if (v77) {
          v78 = 256;
          if (v77 < 257)
            v78 = v77;
          dword_168B63C = v78;
            if (v78 > 0) {
              v79 = v124;
              v122 = 0;
              v123 = sharedUiInfo;
                do {
                  v80 = strlen(v79) + 1;
                  v81 = (int)&v79[v80 - 1];
                  if (!I_stricmp(&v79[v80 - 5], ".roq"))
                    *(_BYTE *)(v81 - 4) = 0;
                  I_strupr(v79);
                  v123[6623] = (int)String_Alloc(v79);
                  v79 = (char *)(v81 + 1);
                  ++v122;
                  ++v123;
                }
              while (v122 < dword_168B63C);
            }
        }
      return;
    }
    if (!I_stricmp(v130, "playMovie")) {
      if (dword_168B644 >= 0)
        CIN_StopCinematic(dword_168B644);
      v82 = va("cinematic %s 2\n",
               *(const char **)&dword_168B23C[4 * dword_168B640]);
      Cbuf_ExecuteText(2, v82, v110);
      return;
    }
    if (!I_stricmp(v130, "RunMod")) {
      Dvar_SetStringByName("fs_game", (&dword_168B034)[2 * dword_168B238]);
      Cbuf_ExecuteText(2, "vid_restart;", v110);
      return;
    }
    if (!I_stricmp(v130, "closeJoin")) {
        if (dword_168BAAC) {
          dword_168BAAC = 0;
          Com_Printf("%d servers listed in browser with %d players.\n", _nel,
                     dword_169F33C);
          v83 = LAN_GetServerCount(ui_netSource->current.integer) - _nel;
          if (v83 > 0)
            Com_Printf("%d servers not listed (filtered out by game browser "
                       "settings)\n",
                       v83);
          dword_169F340 = 0;
          dword_16A04AC = 0;
          *(_DWORD *)&uiInfo[6].Menus[448] = 0;
          UI_BuildServerDisplayList(1);
        }
        else {
          Menus_CloseByName(uiInfo, "joinserver");
          Menus_OpenByName(uiInfo, "main");
        }
      return;
    }
    if (!I_stricmp(v130, "StopRefresh")) {
        if (dword_168BAAC) {
          dword_168BAAC = 0;
          Com_Printf("%d servers listed in browser with %d players.\n", _nel,
                     dword_169F33C);
          v87 = LAN_GetServerCount(ui_netSource->current.integer) - _nel;
          if (v87 > 0)
            Com_Printf("%d servers not listed (filtered out by game browser "
                       "settings)\n",
                       v87);
        }
      dword_169F340 = 0;
      dword_16A04AC = 0;
      *(_DWORD *)&uiInfo[6].Menus[448] = 0;
      return;
    }
    if (!I_stricmp(v130, "ServerStatus")) {
      ServerCount = LAN_GetServerCount(ui_netSource->current.integer);
        if (ServerCount != dword_169F338) {
          dword_169F338 = ServerCount;
            if (_nel) {
              dword_168BAB0 = -1;
              UI_BuildServerDisplayList(1);
            }
        }
        if (dword_168BAB0 >= 0 && dword_168BAB0 < (int)_nel) {
          LAN_GetServerAddressString((char *)ui_netSource->current.integer,
                                     dword_168BAB4[dword_168BAB0], byte_169F768,
                                     64);
          UI_BuildServerStatus(1u);
        }
      return;
    }
    if (!I_stricmp(v130, "UpdateFilter")) {
      if (!ui_netSource->current.integer)
        UI_StartServerRefresh(1);
      UI_BuildServerDisplayList(1);
      UI_FeederSelection(2.0, 0);
      return;
    }
    if (!I_stricmp(v130, "JoinServer")) {
      Dvar_SetBoolByName((dvar_s *)&stru_2A83E4, 0);
      v85 = LAN_GetServerCount(ui_netSource->current.integer);
        if (v85 != dword_169F338) {
          dword_169F338 = v85;
            if (_nel) {
              dword_168BAB0 = -1;
              UI_BuildServerDisplayList(1);
            }
        }
        if (dword_168BAB0 >= 0 && dword_168BAB0 < (int)_nel) {
          LAN_GetServerAddressString((char *)ui_netSource->current.integer,
                                     dword_168BAB4[dword_168BAB0], v131, 1024);
          v86 = va("connect %s\n", v131);
          Cbuf_ExecuteText(2, v86, v117);
        }
      return;
    }
    if (!I_stricmp(v130, "Quit")) {
      Cbuf_ExecuteText(0, "quit", v110);
      return;
    }
    if (!I_stricmp(v130, "Controls")) {
      Dvar_SetIntByName("cl_paused", (DvarValue)1);
      Key_SetCatcher(8);
      Menus_CloseAll(uiInfo);
      Menus_OpenByName(uiInfo, "setup_menu2");
      return;
    }
    if (!I_stricmp(v130, "Leave")) {
      Cbuf_ExecuteText(2, "disconnect\n", v110);
      Key_SetCatcher(8);
      Menus_CloseAll(uiInfo);
      Menus_OpenByName(uiInfo, "main");
      return;
    }
    if (!I_stricmp(v130, "ServerSort")) {
        if (Int_Parse(a8, v136)) {
          if (dword_168BAA0 == v136[0])
            dword_168BAA4 = dword_168BAA4 == 0;
          dword_168BAA0 = v136[0];
          qsort(dword_168BAB4, _nel, 4u,
                (int(__cdecl *)(const void *,
                                const void *))UI_ServersQsortCompare);
        }
      return;
    }
  if (!I_stricmp(v130, "nextSkirmish") || !I_stricmp(v130, "SkirmishStart"))
    return;
    if (!I_stricmp(v130, "closeingame")) {
      Catcher = Key_GetCatcher();
      Key_SetCatcher(Catcher & 0xFFFFFFF7);
      Key_ClearStates(a1, a2, a3, a4, a5, a6, a7);
      Dvar_SetIntByName("cl_paused", 0);
      Menus_CloseAll(uiInfo);
      return;
    }
    if (!I_stricmp(v130, "voteKick")) {
      frameTime = uiInfo[1].frameTime;
        if (frameTime >= 0 && frameTime < dword_1684B04) {
          v90 = va("callvote kick \"%s\"\n",
                   (const char *)(32 * frameTime + 23612168));
          Cbuf_ExecuteText(2, v90, v110);
        }
      return;
    }
    if (!I_stricmp(v130, "voteTempBan")) {
      v91 = uiInfo[1].frameTime;
        if (v91 >= 0 && v91 < dword_1684B04) {
          v92 = va("callvote tempBanUser \"%s\"\n",
                   (const char *)(32 * v91 + 23612168));
          Cbuf_ExecuteText(2, v92, v110);
        }
      return;
    }
    if (!I_stricmp(v130, "addFavorite")) {
        if (ui_netSource->current.integer != 2) {
          v124[0] = 0;
          __dst[0] = 0;
          v93 = LAN_GetServerCount(ui_netSource->current.integer);
            if (v93 != dword_169F338) {
              dword_169F338 = v93;
                if (_nel) {
                  dword_168BAB0 = -1;
                  UI_BuildServerDisplayList(1);
                }
            }
            if (dword_168BAB0 >= 0 && dword_168BAB0 < (int)_nel) {
              LAN_GetServerInfo((char *)ui_netSource->current.integer,
                                dword_168BAB4[dword_168BAB0], v131, 1024);
              v98 = (char *)Info_ValueForKey(v131, "hostname");
              I_strncpyz(__dst, v98, 32);
              v99 = (char *)Info_ValueForKey(v131, "addr");
              I_strncpyz(v124, v99, 32);
            }
          UI_AddServerToFavoritesList(__dst, v124);
        }
      return;
    }
    if (!I_stricmp(v130, "deleteFavorite")) {
        if (ui_netSource->current.integer == 2 && dword_168BAB0 >= 0 &&
            dword_168BAB0 < (int)_nel) {
          v94 = LAN_GetServerCount(2);
            if (v94 != dword_169F338) {
              dword_169F338 = v94;
                if (_nel) {
                  dword_168BAB0 = -1;
                  UI_BuildServerDisplayList(1);
                }
            }
          LAN_GetServerInfo((char *)ui_netSource->current.integer,
                            dword_168BAB4[dword_168BAB0], v131, 1024);
          v124[0] = 0;
          v95 = (char *)Info_ValueForKey(v131, "addr");
          I_strncpyz(v124, v95, 32);
          if (v124[0])
            LAN_RemoveServer(2, v124);
        }
      return;
    }
    if (!I_stricmp(v130, "createFavorite")) {
        if (ui_netSource->current.integer == 2) {
          __dst[0] = 0;
          v124[0] = 0;
          v96 = (char *)Dvar_GetVariantString("ui_favoriteName");
          I_strncpyz(v124, v96, 32);
          v97 = (char *)Dvar_GetVariantString("ui_favoriteAddress");
          I_strncpyz(__dst, v97, 32);
          UI_AddServerToFavoritesList(v124, __dst);
        }
      return;
    }
    if (!I_stricmp(v130, "update")) {
        if (String_Parse(a8, v127, 1024)) {
            if (I_stricmp(v127, "ui_SetName")) {
                if (I_stricmp(v127, "ui_GetName")) {
                    if (I_stricmp(v127, "ui_setRate")) {
                        if (!I_stricmp(v127, stru_2AA6F8.name)) {
                          if ((unsigned __int8)Dvar_GetBool(v127))
                            Dvar_SetFloatByName((dvar_s *)&stru_2A8F04, -0.022);
                          else
                            Dvar_SetFloatByName((dvar_s *)&stru_2A8F04, 0.022);
                        }
                    }
                    else {
                      Int = (float)Dvar_GetInt("rate");
                        if (Int >= 5000.0) {
                          Dvar_SetIntByName("cl_maxpackets", (DvarValue)30);
                          Dvar_SetIntByName("cl_packetdup", (DvarValue)1);
                        }
                        else {
                          Dvar_SetIntByName("cl_maxpackets", (DvarValue)15);
                          if (Int < 4000.0)
                            Dvar_SetIntByName("cl_packetdup", (DvarValue)1);
                          else
                            Dvar_SetIntByName("cl_packetdup", (DvarValue)2);
                        }
                    }
                }
                else {
                  v101 = (char *)Dvar_GetVariantString("name");
                  Dvar_SetStringByName("ui_Name", v101);
                }
            }
            else {
              v100 = (char *)Dvar_GetVariantString("ui_Name");
              Dvar_SetStringByName("name", v100);
            }
        }
      return;
    }
    if (!I_stricmp(v130, "startSingleplayer")) {
      Cbuf_ExecuteText(2, "startSingleplayer\n", v110);
      return;
    }
    if (!I_stricmp(v130, "getLanguage")) {
      v102 = Dvar_GetInt("loc_language");
      Dvar_SetIntByName("ui_language", (DvarValue)v102);
      UI_VerifyLanguage();
      return;
    }
    if (!I_stricmp(v130, "verifyLanguage")) {
      UI_VerifyLanguage();
      return;
    }
    if (!I_stricmp(v130, "updateLanguage")) {
      v104 = Dvar_GetInt("ui_language");
      Dvar_SetIntByName("loc_language", (DvarValue)v104);
      UI_VerifyLanguage();
      Cbuf_ExecuteText(2, "vid_restart\n", v110);
      return;
    }
    if (!I_stricmp(v130, "mutePlayer")) {
      v105 = uiInfo[1].frameTime;
      if (v105 >= 0 && v105 < dword_1684B04)
        CL_MutePlayer(*(_DWORD *)&dword_1685B08[4 * v105]);
      return;
    }
    if (!I_stricmp(v130, "openMenuOnDvar") ||
        !I_stricmp(v130, "openMenuOnDvarNot")) {
      if (!(unsigned __int8)UI_GetOpenOrCloseMenuOnDvarArgs(
              a8, v130, v125, (const char **)v129, v126))
        return;
      v106 = I_stricmp(v130, "openMenuOnDvar") == 0;
        if (Dvar_FindVar(v125)) {
          v107 = (char *)Dvar_GetVariantString(v125);
          if (v106 == (I_stricmp((char *)v129, v107) == 0))
            Menus_OpenByName(uiInfo, v126);
          return;
        }
      goto LABEL_287;
    }
    if (I_stricmp(v130, "closeMenuOnDvar") &&
        I_stricmp(v130, "closeMenuOnDvarNot")) {
      Com_Printf("unknown UI script %s\n", v130);
      return;
    }
    if ((unsigned __int8)UI_GetOpenOrCloseMenuOnDvarArgs(
            a8, v130, v125, (const char **)v129, v126)) {
      v108 = I_stricmp(v130, "closeMenuOnDvar") == 0;
        if (Dvar_FindVar(v125)) {
          v109 = (char *)Dvar_GetVariantString(v125);
          if (v108 == (I_stricmp((char *)v129, v109) == 0))
            Menus_CloseByName(uiInfo, v126);
          return;
        }
    LABEL_287:
      Com_Printf("%s: cannot find dvar %s\n", v130, v125);
    }
}

void __cdecl UI_OpenMenu(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl UI_SetActiveMenu(int menu)
{
  UNIMPLEMENTED();
}

void __cdecl UI_OpenMenu_f()
{
  char *v0; // eax

  v0 = Cmd_Args(1);
  return Menus_OpenByName(uiInfo, v0);
}

void __cdecl UI_ShowPartyLobby(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_LoadIngameMenus()
{
  MenuList *Menus; // eax

    if (!g_ingameMenusLoaded) {
      g_ingameMenusLoaded = 1;
      Menus = (MenuList *)UI_LoadMenus(a1, a2, a3, a4, a5, a6, a7,
                                       "ui_mp/ingame.txt", 3);
      UI_AddMenuList(a1, a2, a3, a4, a5, a6, a7, uiInfo, Menus);
    }
}

int __cdecl Load_ScriptMenu(char const *pszMenu, int imageTrack)
{
  UNIMPLEMENTED();
}

int __cdecl String_ParseInternal(char const **, char const **)
{
  UNIMPLEMENTED();
}

char *__cdecl GetMenuBuffer(char const *filename)
{
  signed int v1; // ebx
  int v3[3];     // [esp+1Ch] [ebp-Ch] BYREF

  v1 = FS_FOpenFileByMode(a1, v3, FS_READ);
    if (v3[0]) {
        if (v1 > 0x7FFF) {
          Com_Printf("^1menu file too large: %s is %i, max allowed is %i", a1,
                     v1, 0x8000);
          FS_FCloseFile(v3[0]);
          return 0;
        }
        else {
          FS_Read(menuBuf2, v1, v3[0]);
          menuBuf2[v1] = 0;
          FS_FCloseFile(v3[0]);
          return menuBuf2;
        }
    }
    else {
      Com_Printf("^1menu file not found: %s, using default\n", a1);
      return 0;
    }
}

void __cdecl UI_OwnerDraw(float x, float y, float w, float h, int horzAlign,
                          int vertAlign, float text_x, float text_y,
                          int ownerDraw, int ownerDrawFlags, int align,
                          float special, struct Font_s *font, float scale,
                          float *const color, struct Material *material,
                          int textStyle)
{
  UNIMPLEMENTED();
}

void __cdecl UI_Init()
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawMapLevelshot()
{
  menuDef_t *v1; // eax

    if (g_mapname &&
        (v1 = (menuDef_t *)Menus_FindByName(uiInfo, "connect")) != 0) {
      uiInfo->blurRadiusOut = 0;
      Menu_Paint(a1, uiInfo, v1, 1);
    }
    else {
      UI_FillRect(0, 640.0, 480.0, 0, 0, &colorBlack);
    }
}

void __cdecl UI_DrawConnectScreen()
{
  UNIMPLEMENTED();
}

void __cdecl UI_Refresh()
{
  UNIMPLEMENTED();
}

struct uiInfo_t *uiInfo;
struct serverStatusDvar_t *serverStatusDvars;
struct dvar_s const *const ui_mapname;
struct dvar_s const *const ui_netSource;
struct dvar_s const *const ui_bigFont;
struct dvar_s const *const ui_selectedPlayer;
struct dvar_s const *const ui_extraBigFont;
struct dvar_s const *const ui_gametype;
struct dvar_s const *const ui_currentMap;
struct dvar_s const *const ui_smallFont;
struct dvar_s const *const ui_serverStatusTimeOut;
struct uiInfo_t *uiInfoArray;
struct sharedUiInfo_t sharedUiInfo;

void __cdecl UI_InsertServerIntoDisplayList(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_StartSkirmish(int)
{
  UNIMPLEMENTED();
}

int __cdecl UI_GetPlayerListNumForClientNum(int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_UpdatePendingPings(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_ClearDisplayedServers(void)
{
  UNIMPLEMENTED();
}

bool __cdecl UI_DvarValueTest(char const *, char const *, char const *, bool)
{
  UNIMPLEMENTED();
}

void __cdecl UI_OpenMenuOnDvar(char const *, char const *, char const *,
                               char const *)
{
  UNIMPLEMENTED();
}

void __cdecl UI_BuildPlayerList(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_BinaryServerInsertion(int)
{
  UNIMPLEMENTED();
}

int __cdecl UI_ServersQsortCompare(void const *, void const *)
{
  return LAN_CompareServers(ui_netSource->current.integer, dword_168BAA0,
                            dword_168BAA4, *a1, *a2);
}

int __cdecl UI_GetTalkerClientNum(int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_CloseMenuOnDvar(char const *, char const *, char const *,
                                char const *)
{
  UNIMPLEMENTED();
}

void __cdecl UI_ServersSort(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawTalkerNum(int, struct rectDef_s *, struct Font_s *,
                              float *const, float, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_VerifyLanguage(void)
{
  int Int; // esi
  int v1;  // ebx
  int v2;  // eax

  Int = Dvar_GetInt("loc_language");
  v1 = Dvar_GetInt("ui_language");
  v2 = SEH_VerifyLanguageSelection(v1);
  if (v1 != v2)
    Dvar_SetIntByName("ui_language", (DvarValue)v2);
  if (Int == v1)
    Dvar_SetBoolByName((dvar_s *)&stru_2AA0B4, 0);
  else
    Dvar_SetBoolByName((dvar_s *)&stru_2AA0B4, 1);
}

void __cdecl UI_Update(char const *)
{
  UNIMPLEMENTED();
}

struct MenuList *__cdecl Load_ScriptMenuInternal(char const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_BuildServerDisplayList(int)
{
  int v1;             // ebx
  signed int result;  // eax
  char *String;       // eax
  unsigned int v4;    // ecx
  unsigned int v5;    // eax
  dvar_s *v6;         // edx
  const char *v7;     // eax
  char *v8;           // eax
  int i;              // esi
  dvar_s *v10;        // edx
  const char *v11;    // eax
  int v12;            // ebx
  char *v13;          // eax
  const char *v14;    // eax
  const char *v15;    // eax
  const char *v16;    // eax
  DvarValue current;  // edx
  char *v18;          // ebx
  char *v19;          // eax
  dvar_s *v20;        // edx
  int v21;            // ebx
  int v22;            // edi
  int v23;            // ebx
  int v24;            // eax
  int v25;            // edx
  const char *v26;    // eax
  const char *v27;    // eax
  const char *v28;    // eax
  const char *v29;    // eax
  const char *v30;    // eax
  int v31;            // eax
  int v32;            // ecx
  int *v33;           // edx
  char *v34;          // ebx
  char *v35;          // ebx
  char *v36;          // eax
  signed __int32 v37; // edi
  int *v38;           // ecx
  int v39;            // eax
  int *v40;           // ecx
  signed __int32 v41; // ebx
  char *v42;          // edi
  size_t v43;         // ebx
  signed __int32 v44; // ecx
  int *v45;           // edx
  char *v46;          // ebx
  int ServerCount;    // [esp+20h] [ebp-428h]
  int ServerPing;     // [esp+24h] [ebp-424h]
  int v49;            // [esp+28h] [ebp-420h]
  int v50;            // [esp+28h] [ebp-420h]
  int v51;            // [esp+2Ch] [ebp-41Ch]
  char __dst[1048];   // [esp+30h] [ebp-418h] BYREF

  v1 = a1;
    if (!a1) {
      result = uiInfo->realTime;
      if (result <= dword_169F340)
        return result;
      goto LABEL_3;
    }
  if (a1 == 2)
  LABEL_3:
    v1 = 0;
  String = (char *)Dvar_GetString("cl_motdString");
  I_strncpyz(_dst, String, 1024);
  v4 = strlen(_dst) + 1;
  v5 = v4 - 1;
    if (v4 == 1) {
      v7 = UI_SafeTranslateString("EXE_COD_MULTIPLAYER");
      v8 = va("%s - %s", v7, "1.0");
      strcpy(_dst, v8);
      v5 = strlen(_dst);
    }
    if (v5 != dword_169F350) {
      dword_169F350 = v5;
      dword_169F354 = -1;
    }
    if (v1) {
      UI_BuildServerDisplayList(int)::numclean = 0;
      _nel = 0;
      dword_169F33C = 0;
      dword_169F338 = LAN_GetServerCount(ui_netSource->current.integer);
      if (dword_168BAB0 >= 0)
        Menu_SetFeederSelection(uiInfo, 0, 2, 0, 0);
      LAN_MarkServerDirty(ui_netSource->current.integer, -1, 1);
    }
  ServerCount = LAN_GetServerCount(ui_netSource->current.integer);
    if (LAN_WaitServerResponse(ui_netSource->current.integer)) {
      v6 = ui_netSource;
    LABEL_18:
      _nel = 0;
      dword_169F33C = 0;
      dword_169F338 = LAN_GetServerCount(v6->current.integer);
      result = uiInfo->realTime + 500;
      dword_169F340 = result;
      return result;
    }
  v6 = ui_netSource;
  if (!ui_netSource->current.integer && !ServerCount)
    goto LABEL_18;
  qsort(dword_168BAB4, _nel, 4u,
        (int(__cdecl *)(const void *, const void *))UI_ServersQsortCompare);
    if (ServerCount > 0) {
        for (i = 0; ServerCount != i; ++i) {
            if (LAN_ServerIsDirty(ui_netSource->current.integer, i)) {
              ServerPing = LAN_GetServerPing(ui_netSource->current.integer, i);
                if (ServerPing <= 0) {
                  v10 = ui_netSource;
                  if (ui_netSource->current.integer != 2)
                    continue;
                }
                else {
                  v10 = ui_netSource;
                }
              LAN_GetServerInfo((char *)v10->current.integer, i, __dst, 1024);
              v11 = (const char *)Info_ValueForKey(__dst, "clients");
              v12 = atoi(v11);
              dword_169F33C += v12;
              v13 = (char *)Info_ValueForKey(__dst, "addr");
                if (I_strnicmp(v13, "000.000.000.000", 15) &&
                    (*(_BYTE *)(ui_browserShowEmpty + 8) || v12)) {
                    if (*(_BYTE *)(ui_browserShowFull + 8) ||
                        (v26 = (const char *)Info_ValueForKey(__dst,
                                                              "sv_maxclients"),
                         v12 != atoi(v26))) {
                        if (*(_BYTE *)(ui_browserShowPassword + 8) ||
                            (v27 =
                                 (const char *)Info_ValueForKey(__dst, "pswrd"),
                             !atoi(v27))) {
                            if (*(_BYTE *)(ui_browserShowNoPassword + 8) ||
                                (v28 = (const char *)Info_ValueForKey(__dst,
                                                                      "pswrd"),
                                 atoi(v28))) {
                                if (!*(_BYTE *)(ui_browserShowPure + 8) ||
                                    (v29 = (const char *)Info_ValueForKey(
                                         __dst, "pure"),
                                     atoi(v29))) {
                                    if (!*(_BYTE *)(ui_browserShowDedicated +
                                                    8) ||
                                        (v30 = (const char *)Info_ValueForKey(
                                             __dst, "hw"),
                                         (unsigned int)(atoi(v30) - 1) <= 2)) {
                                        if (*(int *)(ui_browserMod + 8) < 0 ||
                                            (v14 = (const char *)
                                                 Info_ValueForKey(__dst, "mod"),
                                             atoi(v14) ==
                                                 *(_DWORD *)(ui_browserMod +
                                                             8))) {
                                            if (*(int *)(ui_browserFriendlyfire +
                                                         8) < 0 ||
                                                (v15 = (const char *)
                                                     Info_ValueForKey(__dst,
                                                                      "ff"),
                                                 atoi(v15) ==
                                                     *(_DWORD
                                                           *)(ui_browserFriendlyfire +
                                                              8))) {
                                                if (*(int *)(ui_browserKillcam +
                                                             8) < 0 ||
                                                    (v16 = (const char *)
                                                         Info_ValueForKey(__dst,
                                                                          "kc"),
                                                     atoi(v16) ==
                                                         *(_DWORD
                                                               *)(ui_browserKillcam +
                                                                  8))) {
                                                  current =
                                                      ui_joinGameType->current;
                                                    if (!*(_BYTE *)dword_1685D14
                                                             [2 *
                                                              current
                                                                  .integer] ||
                                                        (v35 = (char *)
                                                             dword_1685D10
                                                                 [2 *
                                                                  current
                                                                      .integer],
                                                         v36 = (char *)
                                                             Info_ValueForKey(
                                                                 __dst,
                                                                 "gametype"),
                                                         !I_stricmp(v36,
                                                                    v35))) {
                                                        if (ui_serverFilterType <=
                                                                0 ||
                                                            (v18 = (char *)*(
                                                                 &off_3325E4 +
                                                                 2 * ui_serverFilterType),
                                                             v19 = (char *)
                                                                 Info_ValueForKey(
                                                                     __dst,
                                                                     "game"),
                                                             !I_stricmp(v19,
                                                                        v18))) {
                                                          v20 = ui_netSource;
                                                          if (ui_netSource
                                                                  ->current
                                                                  .integer != 2)
                                                            goto LABEL_46;
                                                          v21 = _nel;
                                                            if ((int)_nel > 0) {
                                                                if (dword_168BAB4
                                                                        [0] ==
                                                                    i) {
                                                                  v37 = 0;
                                                                LABEL_89:
                                                                  --_nel;
                                                                    if (v37 >=
                                                                        v21 -
                                                                            1) {
                                                                      --v21;
                                                                    }
                                                                    else {
                                                                      v40 =
                                                                          &dword_1684AD4
                                                                              [v37 +
                                                                               7161];
                                                                      v41 = v37;
                                                                      v42 =
                                                                          (char
                                                                               *)((char
                                                                                       *)&dword_168BAB4
                                                                                      [v37] -
                                                                                  (char
                                                                                       *)
                                                                                      v40);
                                                                        do {
                                                                          ++v41;
                                                                          *(int *)((char
                                                                                        *)
                                                                                       v40 +
                                                                                   (_DWORD)
                                                                                       v42) =
                                                                              *v40;
                                                                          ++v40;
                                                                        }
                                                                      while (
                                                                          (int)
                                                                              _nel >
                                                                          v41);
                                                                    LABEL_46:
                                                                      v21 =
                                                                          _nel;
                                                                    }
                                                                }
                                                                else {
                                                                  v37 = 0;
                                                                  v38 =
                                                                      &sharedUiInfo;
                                                                    while (
                                                                        _nel !=
                                                                        ++v37) {
                                                                      v39 = v38
                                                                          [7166];
                                                                      ++v38;
                                                                      if (i ==
                                                                          v39)
                                                                        goto LABEL_89;
                                                                    }
                                                                }
                                                            }
                                                          v22 = v21;
                                                            if (v21 <= 0) {
                                                              v50 = 0;
                                                            LABEL_71:
                                                                if (v21 >=
                                                                    v50) {
                                                                  if (dword_168BAB0 >=
                                                                          v50 &&
                                                                      v21)
                                                                    ++dword_168BAB0;
                                                                  v32 = v21 + 1;
                                                                  _nel =
                                                                      v21 + 1;
                                                                    if (v21 +
                                                                            1 >
                                                                        v50) {
                                                                      v33 =
                                                                          &dword_1684AD4
                                                                              [v21 +
                                                                               7160];
                                                                      v34 =
                                                                          (char
                                                                               *)((char
                                                                                       *)&dword_168BAB4
                                                                                      [v32] -
                                                                                  (char
                                                                                       *)
                                                                                      v33);
                                                                        do {
                                                                          --v32;
                                                                          *(int *)((char
                                                                                        *)
                                                                                       v33 +
                                                                                   (_DWORD)
                                                                                       v34) =
                                                                              *v33;
                                                                          --v33;
                                                                        }
                                                                      while (
                                                                          v32 >
                                                                          v50);
                                                                    }
                                                                  dword_168BAB4
                                                                      [v50] = i;
                                                                }
                                                            }
                                                            else {
                                                              v49 = 0;
                                                                while (1) {
                                                                  v23 =
                                                                      v22 >> 1;
                                                                  v51 = (v22 >>
                                                                         1) +
                                                                        v49;
                                                                  v24 = LAN_CompareServers(
                                                                      v20->current
                                                                          .integer,
                                                                      dword_168BAA0,
                                                                      dword_168BAA4,
                                                                      i,
                                                                      dword_168BAB4
                                                                          [v51]);
                                                                  v25 = v24;
                                                                    if (!v24) {
                                                                        if (v51 >=
                                                                            0) {
                                                                          v43 =
                                                                              _nel;
                                                                            if ((int)
                                                                                    _nel >=
                                                                                v51) {
                                                                              if (dword_168BAB0 >=
                                                                                      v51 &&
                                                                                  _nel)
                                                                                ++dword_168BAB0;
                                                                              v44 =
                                                                                  ++_nel;
                                                                                if ((int)(v43 +
                                                                                          1) >
                                                                                    v51) {
                                                                                  v45 =
                                                                                      &dword_1684AD4
                                                                                          [v43 +
                                                                                           7160];
                                                                                  v46 =
                                                                                      (char
                                                                                           *)((char
                                                                                                   *)&dword_168BAB4
                                                                                                  [v44] -
                                                                                              (char
                                                                                                   *)
                                                                                                  v45);
                                                                                    do {
                                                                                      --v44;
                                                                                      *(int *)((char
                                                                                                    *)
                                                                                                   v45 +
                                                                                               (_DWORD)
                                                                                                   v46) =
                                                                                          *v45;
                                                                                      --v45;
                                                                                    }
                                                                                  while (
                                                                                      v44 >
                                                                                      v51);
                                                                                }
                                                                              *(&dword_168BAA0 +
                                                                                v51 +
                                                                                5) =
                                                                                  i;
                                                                            }
                                                                        }
                                                                      goto LABEL_79;
                                                                    }
                                                                  v22 -= v23;
                                                                  if (v24 > 0)
                                                                    v49 = v51;
                                                                  if (v23 <= 0)
                                                                    break;
                                                                  v20 =
                                                                      ui_netSource;
                                                                }
                                                              v31 = v49 + 1;
                                                              if (v25 < 1)
                                                                v31 = v49;
                                                              v50 = v31;
                                                                if (v31 >= 0) {
                                                                  v21 = _nel;
                                                                  goto LABEL_71;
                                                                }
                                                            }
                                                        LABEL_79:
                                                            if (ServerPing >
                                                                0) {
                                                              LAN_MarkServerDirty(
                                                                  ui_netSource
                                                                      ->current
                                                                      .integer,
                                                                  i, 0);
                                                              ++UI_BuildServerDisplayList(
                                                                  int)::
                                                                  numclean;
                                                            }
                                                          continue;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
              LAN_MarkServerDirty(ui_netSource->current.integer, i, 0);
            }
        }
    }
  result = uiInfo->realTime;
  dword_168BA98 = result;
  return result;
}

bool __cdecl UI_GetOpenOrCloseMenuOnDvarArgs(char const **, char const *,
                                             char *const, char *const,
                                             char *const)
{
  UNIMPLEMENTED();
}

void __cdecl UI_UpdateDisplayServers(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawPartyStatus(struct rectDef_s *, struct Font_s *,
                                float *const, float, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawKeyBindStatus(struct rectDef_s *, struct Font_s *, float,
                                  float *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DrawServerRefreshDate(struct rectDef_s *, struct Font_s *,
                                      float, float *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_BuildServerStatus(int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_StartServerRefresh(int)
{
  int32_t tm_min;            // ebx
  int32_t tm_hour;           // esi
  int v3;                    // edi
  const char *v4;            // eax
  char *v5;                  // eax
  const char *VariantString; // eax
  char *v7;                  // eax
  char v8;                   // [esp+8h] [ebp-80h]
  char v9;                   // [esp+8h] [ebp-80h]
  int32_t tm_mday;           // [esp+2Ch] [ebp-5Ch]
  qtime_s v12;               // [esp+34h] [ebp-54h] BYREF
  char __str[48];            // [esp+58h] [ebp-30h] BYREF

  Com_RealTime(&v12);
  snprintf(__str, 0x18u, "ui_lastServerRefresh_%i",
           ui_netSource->current.integer);
  tm_min = v12.tm_min;
  tm_hour = v12.tm_hour;
  v3 = v12.tm_year + 1900;
  tm_mday = v12.tm_mday;
  v4 = UI_SafeTranslateString((&MonthAbbrev)[v12.tm_mon]);
  v5 = va("%s %i, %i   %i:%02i", v4, tm_mday, v3, tm_hour, tm_min);
  Dvar_SetStringByName(__str, v5);
    if (a1) {
      dword_168BAAC = 1;
      dword_169F340 = uiInfo->realTime + 1000;
      _nel = 0;
      dword_169F33C = 0;
      dword_169F338 = LAN_GetServerCount(ui_netSource->current.integer);
      LAN_MarkServerDirty(ui_netSource->current.integer, -1, 1);
      LAN_ResetPings((_WORD *)ui_netSource->current.integer);
        if (ui_netSource->current.integer) {
          dword_168BA98 = uiInfo->realTime + 5000;
            if (ui_netSource->current.integer == 1) {
              VariantString =
                  (const char *)Dvar_GetVariantString("debug_protocol");
              if (*VariantString)
                v7 = va("globalservers %d %s full empty\n", 0, VariantString);
              else
                v7 = va("globalservers %d %d full empty\n", 0, 115);
              Cbuf_ExecuteText(0, v7, v9);
            }
        }
        else {
          Cbuf_ExecuteText(0, "localservers\n", v8);
          dword_168BA98 = uiInfo->realTime + 1000;
        }
    }
    else {
      LAN_ResetPings((_WORD *)ui_netSource->current.integer);
      dword_168BAAC = 1;
      dword_168BA98 = uiInfo->realTime + 1000;
    }
}

void __cdecl UI_RegisterDvars(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_StopServerRefresh(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_DoServerRefresh(void)
{
  UNIMPLEMENTED();
}

void __cdecl UI_GetGameTypesList(void)
{
  int result;       // eax
  char *v1;         // esi
  unsigned int v2;  // ecx
  unsigned int v3;  // ebx
  int v4;           // ebx
  char *v5;         // eax
  char *v6;         // eax
  int v7;           // ebx
  char v8;          // [esp+8h] [ebp-1050h]
  char *v9;         // [esp+24h] [ebp-1034h]
  int FileList;     // [esp+28h] [ebp-1030h]
  int v11;          // [esp+2Ch] [ebp-102Ch]
  char __dst[4096]; // [esp+3Ch] [ebp-101Ch] BYREF
  char *MenuBuffer; // [esp+103Ch] [ebp-1Ch] BYREF

  dword_1685C08 = 0;
  dword_1685D0C = 0;
  dword_1685D10[0] = (int)String_Alloc("All");
  dword_1685D14[2 * dword_1685D0C++] = (int)&inData;
  FileList = FS_GetFileList("maps/mp/gametypes", "gsc", FS_LIST_PURE_ONLY,
                            __dst, 4096);
  if (FileList <= 0)
    goto LABEL_2;
  v1 = __dst;
  v11 = 0;
    while (1) {
      v2 = strlen(v1) + 1;
      v3 = v2 - 1;
      if (*v1 != 95)
        break;
      v1 += v2;
    LABEL_7:
      if (FileList == ++v11)
        goto LABEL_2;
    }
  v9 = &v1[v3];
  if (!I_stricmp(&v1[v3 - 4], ".gsc"))
    v1[v3 - 4] = 0;
  v4 = dword_1685C08;
    if (dword_1685C08 != 32 && dword_1685D0C != 32) {
      *((_DWORD *)&unk_1685C00 + 2 * v4 + 3) = String_Alloc(v1);
      dword_1685D10[2 * dword_1685D0C] =
          *(_DWORD *)&dword_1685C0C[8 * dword_1685C08];
      v5 = va("maps/mp/gametypes/%s.txt", v1);
      MenuBuffer = GetMenuBuffer(v5);
        if (MenuBuffer) {
          v6 = Com_Parse(&MenuBuffer);
          v7 = dword_1685C08;
          *((_DWORD *)&unk_1685C00 + 2 * v7 + 4) = String_Alloc(v6);
          dword_1685D10[2 * dword_1685D0C + 1] =
              dword_1685C10[2 * dword_1685C08];
        }
        else {
          *((_DWORD *)&unk_1685C00 + 2 * dword_1685C08 + 4) =
              *(_DWORD *)&dword_1685C0C[8 * dword_1685C08];
          dword_1685D14[2 * dword_1685D0C] = dword_1685C10[2 * dword_1685C08];
        }
      ++dword_1685C08;
      ++dword_1685D0C;
      v1 = v9 + 1;
      goto LABEL_7;
    }
  Com_Printf("Too many game type scripts found! Only loading the first %i\n",
             31);
LABEL_2:
  result = dword_1685C08;
  if (!dword_1685C08)
    return Com_Error(
        0, "\x15No game type scripts found in maps/mp/gametypes folder", v8);
  return result;
}

UI_DrawRecordLevel(rectDef_s *rect)
{
  UNIMPLEMENTED();
}
