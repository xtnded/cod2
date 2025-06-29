int __cdecl UI_ParseInfos(char const *buf, int max, char **const infos)
{
  char *v3;         // eax
  char *v4;         // eax
  char *v5;         // eax
  unsigned int v6;  // kr04_4
  unsigned int v7;  // kr08_4
  char *v8;         // eax
  int v10;          // [esp+2Ch] [ebp-81Ch]
  char __src[1024]; // [esp+30h] [ebp-818h] BYREF
  char __dst[1048]; // [esp+430h] [ebp-418h] BYREF

  v10 = 0;
LABEL_2:
  v3 = Com_Parse((char **)&a1);
  if (!*v3)
    return v10;
    while (1) {
        if (strcmp(v3, "{")) {
          Com_Printf("Missing { in info file\n");
          return v10;
        }
      if (a2 == v10)
        break;
      __src[0] = 0;
        while (1) {
          v5 = Com_Parse((char **)&a1);
          if (!*v5)
            break;
          if (!strcmp(v5, "}"))
            goto LABEL_12;
          I_strncpyz(__dst, v5, 1024);
          v4 = Com_ParseOnLine((char **)&a1);
          if (!*v4)
            v4 = "<NULL>";
          Info_SetValueForKey(__src, __dst, v4);
        }
      Com_Printf("Unexpected end of info file\n");
    LABEL_12:
      v6 = strlen(__src) + 1;
      v7 = strlen(va("%d", 64)) + 1;
      v8 = (char *)UI_Alloc(v7 + v6 - 1 + 5, 1);
      a3[v10] = v8;
      if (!v8)
        goto LABEL_2;
      strcpy(v8, __src);
      ++v10;
      v3 = Com_Parse((char **)&a1);
      if (!*v3)
        return v10;
    }
  Com_Printf("Max infos exceeded\n");
  return v10;
}

//----- (0017EBE6) --------------------------------------------------------
void UI_LoadArenas(void)
{
  int v0;              // ebx
  char *v1;            // eax
  int v2;              // ebx
  char *v3;            // eax
  int *v4;             // ebx
  char *v5;            // eax
  int *v6;             // ebx
  const gentity_s *v7; // eax
  char *v8;            // ebx
  char *v9;            // eax
  char *v10;           // eax
  char *v11;           // esi
  int v12;             // ebx
  int *v13;            // edi
  char *v14;           // esi
  unsigned int v15;    // kr04_4
  signed int v16;      // ebx
  int i;               // [esp+20h] [ebp-24B8h]
  int v18;             // [esp+24h] [ebp-24B4h]
  int FileList;        // [esp+28h] [ebp-24B0h]
  const char **v20;    // [esp+2Ch] [ebp-24ACh]
  char v21[8192];      // [esp+38h] [ebp-24A0h] BYREF
  char __dst[1024];    // [esp+2038h] [ebp-4A0h] BYREF
  char v23[128];       // [esp+2438h] [ebp-A0h] BYREF
  int v24;             // [esp+24B8h] [ebp-20h] BYREF
  char *v25;           // [esp+24BCh] [ebp-1Ch] BYREF

  ui_numArenas = 0;
  dword_1685E10 = 0;
  FileList = FS_GetFileList("mp", "arena", FS_LIST_PURE_ONLY, __dst, 1024);
    if (FileList > 0) {
      v14 = __dst;
        for (i = 0; i != FileList; ++i) {
          v15 = strlen(v14) + 1;
          sprintf(v23, "%s/%s", "mp", v14);
          v16 = FS_FOpenFileByMode(v23, &v24, FS_READ);
            if (v24) {
                if (v16 > 0x1FFF) {
                  Com_Printf("^1file too large: %s is %i, max allowed is %i",
                             v23, v16, 0x2000);
                  FS_FCloseFile(v24);
                }
                else {
                  FS_Read(v21, v16, v24);
                  v21[v16] = 0;
                  FS_FCloseFile(v24);
                  ui_numArenas += UI_ParseInfos(
                      v21, 64 - ui_numArenas, &(&ui_arenaInfos)[ui_numArenas]);
                }
            }
            else {
              Com_Printf("^1file not found: %s\n", v23);
            }
          v14 += v15;
        }
    }
    if (ui_numArenas > 0) {
      v18 = 0;
      v20 = (const char **)&ui_arenaInfos;
        do {
          v0 = dword_1685E10;
          v1 = (char *)Info_ValueForKey(*v20, "map");
          sharedUiInfo[41 * v0 + 1238] = (int)String_Alloc(v1);
          v2 = dword_1685E10;
          v3 = (char *)Info_ValueForKey(*v20, "longname");
          sharedUiInfo[41 * v2 + 1237] = (int)String_Alloc(v3);
          sharedUiInfo[41 * dword_1685E10 + 1243] = -1;
          sharedUiInfo[41 * dword_1685E10 + 1276] = 0;
          v4 = &sharedUiInfo[41 * dword_1685E10];
          v5 = va("loadscreen_%s", (const char *)v4[1238]);
          v4[1239] = (int)String_Alloc(v5);
          v6 = &sharedUiInfo[41 * dword_1685E10];
          v6[1276] = CL_RegisterMaterialNoMip((const char *)v6[1239], 3);
          v7 = Info_ValueForKey(*v20, "gametype");
          v8 = (char *)v7;
            if (v7 && LOBYTE(v7->s.number)) {
              sharedUiInfo[41 * dword_1685E10 + 1242] = 0;
              v9 = va(".arena files : %s",
                      (const char *)sharedUiInfo[41 * dword_1685E10 + 1238]);
              Com_BeginParseSession(v9);
              v25 = v8;
                while (1) {
                  v10 = Com_Parse(&v25);
                  v11 = v10;
                  if (!v10 || !*v10)
                    break;
                    if (dword_1685C08 > 0) {
                      v12 = 0;
                      v13 = sharedUiInfo;
                        do {
                          if (!I_stricmp(v11, (char *)v13[1107]))
                            sharedUiInfo[41 * dword_1685E10 + 1242] |= 1 << v12;
                          ++v12;
                          v13 += 2;
                        }
                      while (v12 < dword_1685C08);
                    }
                }
              Com_EndParseSession();
            }
            else {
              sharedUiInfo[41 * dword_1685E10 + 1242] = -1;
            }
          if (++dword_1685E10 > 127)
            break;
          ++v18;
          ++v20;
        }
      while (ui_numArenas > v18);
    }
}

// F13280: using guessed type int ui_numArenas;
// 1684AC0: using guessed type int sharedUiInfo[];
// 1685C08: using guessed type int dword_1685C08;
// 1685E10: using guessed type int dword_1685E10;

//----- (0017F014) --------------------------------------------------------
uint32_t __cdecl GetClientState(uiClientState_t *a1)
{
  void *v1;        // ebx
  uint32_t result; // eax

  v1 = clc;
  a1->connectPacketCount = *((_DWORD *)clc + 9);
  a1->connState = *(_DWORD *)v1;
  I_strncpyz(a1->servername, &byte_1220968, 1024);
  I_strncpyz(a1->messageString, (char *)v1 + 40, 1024);
  result = *((_DWORD *)cl + 64);
  a1->clientNum = result;
  return result;
}

//----- (0017F084) --------------------------------------------------------
_WORD *__cdecl LAN_ResetPings(_WORD *a1)
{
  _WORD *result; // eax
  int v2;        // ecx
  int v3;        // edx

  result = a1;
    if (a1 == (_WORD *)1) {
      v2 = dword_1224EA0;
      result = &unk_1224EA4;
      if (dword_1224EA0 <= 0)
        return result;
    }
    else if (a1 == (_WORD *)2) {
      result = &unk_14BCFA8;
      v2 = 128;
    }
    else {
      if (a1)
        return result;
      v2 = 128;
      result = &unk_1220A9C;
    }
  v3 = 0;
    do {
      result[15] = -1;
      ++v3;
      result += 68;
    }
  while (v3 != v2);
  return result;
}

// 1224EA0: using guessed type int dword_1224EA0;

//----- (0017F0E6) --------------------------------------------------------
int __cdecl LAN_GetServerCount(int a1)
{
  if (a1 == 1)
    return dword_1224EA0;
  if (a1 == 2)
    return dword_14BCFA4;
  if (a1)
    return 0;
  return dword_1220A98;
}

// 1220A98: using guessed type int dword_1220A98;
// 1224EA0: using guessed type int dword_1224EA0;
// 14BCFA4: using guessed type int dword_14BCFA4;

//----- (0017F126) --------------------------------------------------------
int __cdecl LAN_WaitServerResponse(int a1)
{
  if (a1 == 1)
    return unk_1224E9C;
  else
    return 0;
}

//----- (0017F140) --------------------------------------------------------
char *__cdecl LAN_GetServerInfo(char *a1, int a2, char *__dst, int a4)
{
  char *result;     // eax
  char *v5;         // esi
  char *v6;         // eax
  char *v7;         // eax
  char *v8;         // eax
  char *v9;         // eax
  char *v10;        // eax
  char *v11;        // eax
  char *v12;        // eax
  char *v13;        // eax
  char *v14;        // eax
  char *v15;        // eax
  char *v16;        // eax
  char *v17;        // eax
  char *v18;        // eax
  char *v19;        // eax
  char *v20;        // eax
  char *v21;        // eax
  __int128 v22;     // [esp+0h] [ebp-438h]
  char __src[1024]; // [esp+14h] [ebp-424h] BYREF
  __int64 v24;      // [esp+414h] [ebp-24h]
  int v25;          // [esp+41Ch] [ebp-1Ch]

  result = a1;
  __src[0] = 0;
    if (a1 == (char *)1) {
      if (a2 < 0 || a2 >= dword_1224EA0)
        goto LABEL_4;
      result = (char *)(136 * a2 + 17728);
      v5 = (char *)&cls + (_DWORD)result + 4;
    }
    else if (a1 == (char *)2) {
        if ((unsigned int)a2 > 0x7F) {
        LABEL_4:
          if (__dst)
            *__dst = 0;
          return result;
        }
      result = (char *)&cls + 136 * a2 + 2737728;
      v5 = result + 8;
    }
    else {
      if (a1 || (unsigned int)a2 > 0x7F)
        goto LABEL_4;
      result = (char *)&cls + 136 * a2 + 304;
      v5 = result + 12;
    }
  if (!v5)
    goto LABEL_4;
    if (__dst) {
      *__dst = 0;
      Info_SetValueForKey(__src, "hostname", v5 + 32);
      Info_SetValueForKey(__src, "mapname", v5 + 64);
      v6 = va("%i", (unsigned __int8)v5[13]);
      Info_SetValueForKey(__src, "clients", v6);
      v7 = va("%i", (unsigned __int8)v5[14]);
      Info_SetValueForKey(__src, "sv_maxclients", v7);
      v8 = va("%i", *((__int16 *)v5 + 15));
      Info_SetValueForKey(__src, "ping", v8);
      v9 = va("%i", *((__int16 *)v5 + 13));
      Info_SetValueForKey(__src, "minping", v9);
      v10 = va("%i", *((__int16 *)v5 + 14));
      Info_SetValueForKey(__src, "maxping", v10);
      Info_SetValueForKey(__src, "game", v5 + 96);
      Info_SetValueForKey(__src, "gametype", v5 + 120);
      v11 = va("%i", (unsigned __int8)v5[12]);
      Info_SetValueForKey(__src, "nettype", v11);
      v24 = *(_QWORD *)v5;
      v25 = *((_DWORD *)v5 + 2);
      *(_QWORD *)&v22 = v24;
      DWORD2(v22) = v25;
      v12 = NET_AdrToString(v22);
      Info_SetValueForKey(__src, "addr", v12);
      v13 = va("%i", (unsigned __int8)v5[16]);
      Info_SetValueForKey(__src, "sv_allowAnonymous", v13);
      v14 = va("%i", v5[21]);
      Info_SetValueForKey(__src, "con_disabled", v14);
      v15 = va("%i", (unsigned __int8)v5[17]);
      Info_SetValueForKey(__src, "pswrd", v15);
      v16 = va("%i", (unsigned __int8)v5[18]);
      Info_SetValueForKey(__src, "pure", v16);
      v17 = va("%i", v5[19]);
      Info_SetValueForKey(__src, "ff", v17);
      v18 = va("%i", v5[20]);
      Info_SetValueForKey(__src, "kc", v18);
      v19 = va("%i", (unsigned __int8)v5[22]);
      Info_SetValueForKey(__src, "hw", v19);
      v20 = va("%i", (unsigned __int8)v5[23]);
      Info_SetValueForKey(__src, "mod", v20);
      v21 = va("%i", (unsigned __int8)v5[24]);
      Info_SetValueForKey(__src, "voice", v21);
      return I_strncpyz(__dst, __src, a4);
    }
  return result;
}

// 17F317: variable 'v22' is possibly undefined
// 1224EA0: using guessed type int dword_1224EA0;

//----- (0017F508) --------------------------------------------------------
int __cdecl LAN_GetServerPing(int a1, int a2)
{
  char *v2; // eax

    if (a1 == 1) {
      if (a2 < 0 || a2 >= dword_1224EA0)
        return -1;
      v2 = (char *)&cls + 136 * a2 + 17732;
    }
    else if (a1 == 2) {
      if ((unsigned int)a2 > 0x7F)
        return -1;
      v2 = (char *)&cls + 136 * a2 + 2737736;
    }
    else {
      if (a1 || (unsigned int)a2 > 0x7F)
        return -1;
      v2 = (char *)&cls + 136 * a2 + 316;
    }
  if (v2)
    return *((__int16 *)v2 + 15);
  return -1;
}

// 1224EA0: using guessed type int dword_1224EA0;

//----- (0017F58A) --------------------------------------------------------
int __cdecl LAN_MarkServerDirty(int a1, int a2, char a3)
{
  int result; // eax
  int v4;     // ebx
  int v5;     // edx

  result = Com_PumpMessageLoop();
    if (a2 == -1) {
        if (a1 == 1) {
          v4 = dword_1224EA0;
          result = (int)&unk_1224EA4;
          if (dword_1224EA0 <= 0)
            return result;
        }
        else if (a1 == 2) {
          v4 = 128;
          result = (int)&unk_14BCFA8;
        }
        else {
          if (a1)
            return result;
          result = (int)&unk_1220A9C;
          v4 = 128;
        }
      v5 = 0;
        do {
          *(_BYTE *)(result + 15) = a3;
          ++v5;
          result += 136;
        }
      while (v5 != v4);
    }
    else if (a1 == 1) {
        if (a2 >= 0 && a2 < dword_1224EA0) {
          result = 136 * a2;
          *((_BYTE *)&cls + 136 * a2 + 17747) = a3;
        }
    }
    else if (a1 == 2) {
        if ((unsigned int)a2 <= 0x7F) {
          result = (int)&cls + 136 * a2;
          *(_BYTE *)(result + 2737751) = a3;
        }
    }
    else if (!a1 && (unsigned int)a2 <= 0x7F) {
      result = (int)&cls + 136 * a2;
      *(_BYTE *)(result + 331) = a3;
    }
  return result;
}

// 1224EA0: using guessed type int dword_1224EA0;

//----- (0017F680) --------------------------------------------------------
int __cdecl LAN_ServerIsDirty(int a1, int a2)
{
    if (a1 == 1) {
      if (a2 < 0 || a2 >= dword_1224EA0)
        return 0;
      return *((unsigned __int8 *)&cls + 136 * a2 + 17747);
    }
    else {
        if (a1 != 2) {
          if (!a1 && (unsigned int)a2 <= 0x7F)
            return *((unsigned __int8 *)&cls + 136 * a2 + 331);
          return 0;
        }
      if ((unsigned int)a2 > 0x7F)
        return 0;
      return *((unsigned __int8 *)&cls + 136 * a2 + 2737751);
    }
}

// 1224EA0: using guessed type int dword_1224EA0;

//----- (0017F6F8) --------------------------------------------------------
int __cdecl LAN_UpdateDirtyPings(unsigned int a1)
{
  return CL_UpdateDirtyPings_f(a1);
}

//----- (0017F702) --------------------------------------------------------
int __cdecl LAN_GetServerStatus(char *__src, char *__dst, int a3)
{
  return CL_ServerStatus(__src, __dst, a3);
}

//----- (0017F70C) --------------------------------------------------------
char *__cdecl Key_KeynumToStringBuf(int a1, char *a2, int a3)
{
  char *v3; // eax

  v3 = (char *)Key_KeynumToString(a1, 1);
  return I_strncpyz(a2, v3, a3);
}

//----- (0017F742) --------------------------------------------------------
char *__cdecl Key_GetBindingBuf(int a1, char *a2, int a3)
{
  char *result; // eax

  result = (char *)Key_GetBinding(a1);
  if (result)
    return I_strncpyz(a2, result, a3);
  *a2 = 0;
  return result;
}

//----- (0017F77E) --------------------------------------------------------
int Key_GetCatcher(void)
{
  return *((_DWORD *)cl + 1);
}

//----- (0017F78E) --------------------------------------------------------
void *__cdecl Key_SetCatcher(int a1)
{
  int v1;       // edx
  void *result; // eax

  v1 = a1;
  if ((*((_BYTE *)cl + 4) & 1) != 0)
    v1 = a1 | 1;
  *((_DWORD *)cl + 1) = v1;
  result = cl;
  if ((*((_BYTE *)cl + 4) & 8) == 0)
    *((_BYTE *)cl + 8) = 0;
  return result;
}

//----- (0017F7BC) --------------------------------------------------------
int __cdecl CLUI_GetCDKey(char *a1, int a2, char *a3)
{
  int result; // eax

  Dvar_RegisterString("fs_game", (DvarValue)&inData, 0x101Cu);
  strcpy(a1, "                ");
  result = *(_DWORD *)cl_cdkeychecksum;
  strcpy(a3, "    ");
  return result;
}

//----- (0017F81A) --------------------------------------------------------
void __cdecl CLUI_SetCDKey(char *a1, char *a2)
{
  *(_DWORD *)cl_cdkey = *(_DWORD *)a1;
  dword_308B70 = *((_DWORD *)a1 + 1);
  dword_308B74 = *((_DWORD *)a1 + 2);
  dword_308B78 = *((_DWORD *)a1 + 3);
  byte_308B7C = 0;
  *(_DWORD *)cl_cdkeychecksum = *(_DWORD *)a2;
  byte_308B64 = 0;
  Com_WriteCDKey();
}

// 308B64: using guessed type char byte_308B64;
// 308B70: using guessed type int dword_308B70;
// 308B74: using guessed type int dword_308B74;
// 308B78: using guessed type int dword_308B78;
// 308B7C: using guessed type char byte_308B7C;

//----- (0017F858) --------------------------------------------------------
int __cdecl GetClientname(int a1, char *__dst, size_t __n)
{
  int v3;   // esi
  int v4;   // edi
  char *v5; // eax
  int v6;   // ecx

  *__dst = 0;
    if (*((_DWORD *)cl + 6)) {
      v3 = *((_DWORD *)cl + 2488);
        if (v3 > 0) {
          v4 = *((_DWORD *)cl + 2490);
          v5 = (char *)&loc_14B0E0 + (_DWORD)cl + 92 * (v4 & 0x7FF);
            if (a1 == *(_DWORD *)v5) {
            LABEL_7:
              strncpy(__dst, v5 + 60, __n);
              return 1;
            }
          v6 = 0;
            while (++v6 != v3) {
              v5 = (char *)&loc_14B0E0 + (_DWORD)cl +
                   92 * (((_WORD)v4 + (_WORD)v6) & 0x7FF);
              if (a1 == *(_DWORD *)v5)
                goto LABEL_7;
            }
        }
    }
  return 0;
}

//----- (0017F8FC) --------------------------------------------------------
int __cdecl UI_PlayLocalSoundAlias(snd_alias_list_t *a1)
{
  return SND_PlayLocalSoundAlias(a1, SASYS_UI);
}

//----- (0017F918) --------------------------------------------------------
int __cdecl UI_PlayLocalSoundAliasByName(char *a1)
{
  return SND_PlayLocalSoundAliasByName(a1, 0);
}

//----- (0017F934) --------------------------------------------------------
_BOOL4 UI_ClientIsInGame(void)
{
  return *(_DWORD *)clc == 8;
}

//----- (0017F94A) --------------------------------------------------------
int __usercall CL_ShutdownUI
    @<eax>(long double a1 @<st0>, float a2 @<xmm0>, __m128 a3 @<xmm1>,
           __m128 a4 @<xmm2>, __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
           __m128 a7 @<xmm6>)
{
  _BYTE *v8; // eax

  if (!dword_1220A70)
    return 0;
  Com_UnloadSoundAliases(SASYS_UI);
  v8 = cl;
  *((_DWORD *)cl + 1) &= ~8u;
  v8[8] = 0;
  CL_SwitchToLocalClient();
  UI_Shutdown(a1, a2, a3, a4, a5, a6, a7);
  CL_SwitchToLocalClient();
  dword_1220A70 = 0;
  return 1;
}

// 1220A70: using guessed type int dword_1220A70;

//----- (0017F9B6) --------------------------------------------------------
void __usercall CL_InitUI(long double a1 @<st0>, float a2 @<xmm0>,
                          __m128 a3 @<xmm1>, __m128 a4 @<xmm2>,
                          __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
                          __m128 a7 @<xmm6>)
{
  dword_1220A70 = 1;
  CL_SwitchToLocalClient();
  UI_Init(a1, a2, a3, a4, a5, a6, a7);
  CL_SwitchToLocalClient();
  UI_Component_Init();
}

// 1220A70: using guessed type int dword_1220A70;

//----- (0017F9EE) --------------------------------------------------------
int __cdecl UI_checkKeyExec(int a1)
{
  if (dword_1220A70)
    return UI_CheckExecKey(a1);
  else
    return 0;
}

// 1220A70: using guessed type int dword_1220A70;

//----- (0017FA0A) --------------------------------------------------------
void __usercall UI_LoadSoundAliases(long double a1 @<st0>, float a2 @<xmm0>,
                                    __m128 a3 @<xmm1>, __m128 a4 @<xmm2>,
                                    __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
                                    __m128 a7 @<xmm6>)
{
  Com_LoadSoundAliases(a1, a2, a3, a4, a5, a6, a7, "menu", "all_mp", SASYS_UI);
}

//----- (0017FA2E) --------------------------------------------------------
int __cdecl LAN_CompareHostname(char *a1, char *a2)
{
  unsigned __int8 v2; // bl
  char *v3;           // esi
  char *v4;           // edi
  __uint32_t v5;      // eax
  unsigned __int8 v6; // bl
  char *v7;           // esi
  char *v8;           // edi
  __uint32_t v9;      // eax
  int result;         // eax
  char v11[32];       // [esp+10h] [ebp-58h] BYREF
  char v12[56];       // [esp+30h] [ebp-38h] BYREF

  v2 = *a1;
    if (*a1) {
      v3 = a1;
      v4 = v12;
        do {
          if ((v2 & 0x80u) == 0)
            v5 = (_DefaultRuneLocale.__runetype[v2] >> 8) & 1;
          else
            v5 = __maskrune(v2, 256) != 0;
          if (v5)
            *v4++ = v2;
          v2 = *++v3;
        }
      while (v2);
    }
    else {
      v4 = v12;
    }
  *v4 = 0;
  v6 = *a2;
    if (*a2) {
      v7 = a2;
      v8 = v11;
        do {
          if ((v6 & 0x80u) == 0)
            v9 = (_DefaultRuneLocale.__runetype[v6] >> 8) & 1;
          else
            v9 = __maskrune(v6, 256) != 0;
          if (v9)
            *v8++ = v6;
          v6 = *++v7;
        }
      while (v6);
    }
    else {
      v8 = v11;
    }
  *v8 = 0;
  result = I_stricmp(v12, v11);
  if (!result)
    return I_stricmp(a1, a2);
  return result;
}

// 195E8CA: using guessed type int __cdecl __maskrune(_DWORD, _DWORD);

//----- (0017FB24) --------------------------------------------------------
int __cdecl LAN_CompareServers(int a1, int a2, int a3, int a4, unsigned int a5)
{
  char *v5;            // esi
  char *v6;            // ebx
  int v7;              // edx
  int result;          // eax
  int v9;              // eax
  unsigned __int8 v10; // cl

    if (a1 == 1) {
      if (a4 >= 0 && a4 < dword_1224EA0)
        v5 = (char *)&cls + 136 * a4 + 17732;
      else
        v5 = 0;
        if ((a5 & 0x80000000) == 0 && (int)a5 < dword_1224EA0) {
          v6 = (char *)&cls + 136 * a5 + 17732;
          goto LABEL_10;
        }
      goto LABEL_9;
    }
    if (a1 == 2) {
      if ((unsigned int)a4 <= 0x7F)
        v5 = (char *)&cls + 136 * a4 + 2737736;
      else
        v5 = 0;
        if (a5 <= 0x7F) {
          v6 = (char *)&cls + 136 * a5 + 2737736;
          goto LABEL_10;
        }
      goto LABEL_9;
    }
  if (a1)
    return 0;
    if ((unsigned int)a4 > 0x7F) {
      v5 = 0;
        if (a5 > 0x7F) {
        LABEL_9:
          v6 = 0;
          goto LABEL_10;
        }
    }
    else {
      v5 = (char *)&cls + 136 * a4 + 316;
      if (a5 > 0x7F)
        goto LABEL_9;
    }
  v6 = (char *)&cls + 136 * a5 + 316;
LABEL_10:
  if (!v5 || !v6)
    return 0;
    switch (a2) {
    case 0:
      v7 = (unsigned __int8)v5[17] - (unsigned __int8)v6[17];
      if (!v7)
        goto LABEL_20;
      goto LABEL_22;
    case 1:
      v10 = v6[22];
      v7 = (unsigned __int8)v5[22] - v10;
      if ((unsigned __int8)v5[22] == v10)
        goto LABEL_20;
        if (v7 < 0) {
          if (!v5[22])
            v7 = 1;
        }
        else if (!v10) {
          v7 = -1;
        }
      goto LABEL_22;
    case 2:
      v7 = LAN_CompareHostname(v5 + 32, v6 + 32);
      if (!v7)
        goto LABEL_20;
      goto LABEL_22;
    case 3:
      v9 = I_stricmp(v5 + 64, v6 + 64);
      goto LABEL_36;
    case 4:
      v7 = (unsigned __int8)v5[13] - (unsigned __int8)v6[13];
      if (v7)
        goto LABEL_22;
      goto LABEL_20;
    case 5:
      v9 = I_stricmp(v5 + 120, v6 + 120);
    LABEL_36:
      v7 = v9;
      if (!v9)
        goto LABEL_20;
      goto LABEL_22;
    case 6:
      v7 = (unsigned __int8)v5[24] - (unsigned __int8)v6[24];
      if (v7)
        goto LABEL_22;
      goto LABEL_20;
    case 7:
      v7 = (unsigned __int8)v5[18] - (unsigned __int8)v6[18];
      if (v7)
        goto LABEL_22;
      goto LABEL_20;
    case 8:
      v7 = (unsigned __int8)v5[23] - (unsigned __int8)v6[23];
      if (v7)
        goto LABEL_22;
    LABEL_20:
      a3 = 0;
    LABEL_21:
      v7 = *((__int16 *)v5 + 15) - *((__int16 *)v6 + 15);
        if (!v7) {
          v7 = I_stricmp(v5 + 120, v6 + 120);
          if (!v7)
            v7 = LAN_CompareHostname(v5 + 32, v6 + 32);
        }
    LABEL_22:
      if (a3)
        v7 = -v7;
      result = v7;
      break;
    case 9:
      goto LABEL_21;
    default:
      v7 = 0;
      goto LABEL_22;
    }
  return result;
}

// 17FB4F: conditional instruction was optimized away because %arg_0.4>=3u
// 17FB58: conditional instruction was optimized away because %arg_0.4>=3u
// 17FB60: conditional instruction was optimized away because %arg_0.4>=3u
// 1224EA0: using guessed type int dword_1224EA0;

//----- (0017FDB4) --------------------------------------------------------
char *getBuildNumber()
{
  sprintf(buf, "%s %s", "crc6_v1", "Thu Oct 06 2005 07:13:42PM");
  return buf;
}

//----- (0017FDE8) --------------------------------------------------------
int __usercall BG_AnimParseError
    @<eax>(long double a1 @<st0>, float a2 @<xmm0>, __m128 a3 @<xmm1>,
           __m128 a4 @<xmm2>, __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
           __m128 a7 @<xmm6>, char *__format, ...)
{
  int CurrentParseLine; // eax
  char __str[1024];     // [esp+2Ch] [ebp-40Ch] BYREF
  va_list v11;          // [esp+42Ch] [ebp-Ch]
  va_list va;           // [esp+444h] [ebp+Ch] BYREF

  va_start(va, __format);
  va_copy(v11, va);
  vsnprintf(__str, 0x400u, __format, va);
  if (!*(_DWORD *)globalFilename)
    return Com_Error(a1, a2, a3, a4, a5, a6, a7, 1, "\x15%s", __str);
  CurrentParseLine = Com_GetCurrentParseLine();
  return Com_Error(a1, a2, a3, a4, a5, a6, a7, 1, "\x15%s: (%s, line %i)",
                   __str, *(const char **)globalFilename, CurrentParseLine + 1);
}

//----- (0017FE7C) --------------------------------------------------------
int *BG_InitWeaponStrings(void)
{
  memset(weaponStrings, 0, sizeof(weaponStrings));
  return BG_LoadWeaponStrings();
}

// F13780: using guessed type int weaponStrings[256];

//----- (0017FEA4) --------------------------------------------------------
int __cdecl BG_PlayAnim(playerState_s *a1, int a2, animBodyPart_t a3, int a4,
                        int a5, int a6, int a7)
{
  int v7;            // ecx
  int v8;            // ebx
  int32_t torsoAnim; // edx
  int32_t v11;       // eax
  int v12;           // edx
  int32_t legsAnim;  // edx
  int32_t v14;       // eax
  int v15;           // edx
  int v16;           // [esp+0h] [ebp-10h]

  v7 = a2;
    if (!a4) {
      v8 = *(_DWORD *)&globalScriptData[96 * a2 + 72] + 50;
      if (a3 != ANIM_BP_TORSO)
        goto LABEL_3;
    LABEL_7:
      v16 = 0;
      if ((int)a1->torsoTimer <= 49)
        goto LABEL_16;
      goto LABEL_8;
    }
  v8 = a4;
  if (a3 == ANIM_BP_TORSO)
    goto LABEL_7;
LABEL_3:
  if (a3 != ANIM_BP_BOTH && a3 != ANIM_BP_LEGS)
    return -1;
  if ((int)a1->legsTimer > 49 && !a7)
    goto LABEL_13;
    if (!a6) {
      legsAnim = a1->legsAnim;
      goto LABEL_23;
    }
  legsAnim = a1->legsAnim;
  v14 = legsAnim;
  BYTE1(v14) = BYTE1(legsAnim) & 0xFD;
    if (a2 != v14) {
    LABEL_23:
      a1->legsAnimDuration = v8;
      v15 = legsAnim & 0x200;
      BYTE1(v15) ^= 2u;
      a1->legsAnim = v15 | a2;
      if (a5)
        a1->legsTimer = v8;
      v16 = 1;
      goto LABEL_14;
    }
    if (!a5 || globalScriptData[96 * a2 + 80] >= 0) {
    LABEL_13:
      v16 = 0;
      goto LABEL_14;
    }
  a1->legsTimer = v8;
  v16 = 0;
LABEL_14:
  if (a3 != ANIM_BP_BOTH)
    goto LABEL_9;
  v7 = 0;
    if ((int)a1->torsoTimer > 49) {
    LABEL_8:
      if (!a7)
        goto LABEL_9;
    }
LABEL_16:
    if (!a6) {
      torsoAnim = a1->torsoAnim;
      goto LABEL_18;
    }
  torsoAnim = a1->torsoAnim;
  v11 = torsoAnim;
  BYTE1(v11) = BYTE1(torsoAnim) & 0xFD;
    if (v7 != v11) {
    LABEL_18:
      v12 = torsoAnim & 0x200;
      BYTE1(v12) ^= 2u;
      a1->torsoAnim = v12 | v7;
      if (a5)
        a1->torsoTimer = v8;
      a1->torsoAnimDuration = v8;
      goto LABEL_9;
    }
  if (a5 && globalScriptData[96 * v7 + 80] < 0)
    a1->torsoTimer = v8;
LABEL_9:
  if (!v16)
    return -1;
  return v8;
}

//----- (00180024) --------------------------------------------------------
void __usercall BG_SwingAngles(float *a1 @<eax>, _DWORD *a2 @<edx>,
                               float a3 @<xmm0>, float a4 @<xmm1>,
                               float a5 @<xmm2>, float a6 @<xmm3>)
{
  float v8;  // xmm1_4
  float v9;  // xmm0_4
  float v10; // [esp+1Ch] [ebp-3Ch]
  float v12; // [esp+48h] [ebp-10h]
  float v13; // [esp+4Ch] [ebp-Ch]

  if (*a2)
    goto LABEL_5;
  v13 = AngleSubtract(*a1, a3);
  if (v13 > a4 || (float)-a4 > v13)
    *a2 = 1;
    if (*a2) {
    LABEL_5:
      v10 = AngleSubtract(a3, *a1);
      v8 = fmaxf(0.5, fabs(v10) * 0.050000001);
        if (v10 < 0.0) {
          v9 = (float)((float)*(int *)(bgs + 736228) * v8) *
               COERCE_FLOAT(LODWORD(a6) ^ 0x80000000);
          if (v10 >= v9)
            goto LABEL_7;
        }
        else {
          v9 = (float)((float)*(int *)(bgs + 736228) * v8) * a6;
            if (v9 >= v10) {
            LABEL_7:
              *a2 = 0;
              v9 = v10;
              goto LABEL_8;
            }
        }
      *a2 = 1;
    LABEL_8:
      *a1 = AngleMod(v9 + *a1);
      v12 = AngleSubtract(a3, *a1);
        if (v12 > a5) {
          *a1 = AngleMod(a3 - a5);
        }
        else if ((float)-a5 > v12) {
          *a1 = AngleMod(a3 + a5);
        }
    }
}

// 312D00: using guessed type int bgs;

//----- (001801C6) --------------------------------------------------------
int32_t __usercall BG_UpdatePlayerDObj
    @<eax>(float a1 @<xmm0>, DObj_s *a2, entityState_s *a3, clientInfo_t *a4,
           int a5)
{
  int32_t weapon;          // edx
  XAnimTree_s *v6;         // edx
  int32_t result;          // eax
  clientInfo_t *v8;        // ebx
  char *attachTagNames;    // edi
  char *attachModelNames;  // esi
  char *v11;               // [esp+2Ch] [ebp-8Ch]
  uint32_t v12;            // [esp+30h] [ebp-88h]
  int v13;                 // [esp+34h] [ebp-84h]
  XAnimTree_s *pXAnimTree; // [esp+38h] [ebp-80h]
  unsigned __int16 v15;    // [esp+3Ch] [ebp-7Ch]
  _DWORD v16[27];          // [esp+40h] [ebp-78h] BYREF
  char v17;                // [esp+ACh] [ebp-Ch] BYREF

  weapon = 0;
  if ((a3->eFlags & 0x300) == 0)
    weapon = a3->weapon;
  v12 = weapon;
  pXAnimTree = (XAnimTree_s *)a4->pXAnimTree;
    if (!*(_DWORD *)a4->infoValid) {
      v6 = (XAnimTree_s *)a4->pXAnimTree;
      goto LABEL_6;
    }
    if (!a4->model[0]) {
      v6 = (XAnimTree_s *)a4->pXAnimTree;
    LABEL_6:
      XAnimClearTree(a1, v6);
      return (*(int(__cdecl **)(uint32_t))(bgs + 736244))(a3->number);
    }
    if (a2) {
        if (weapon == a4->iDObjWeapon) {
          result = a4->dobjDirty;
          if (!result)
            return result;
        }
      (*(void(__cdecl **)(uint32_t))(bgs + 736244))(a3->number);
    }
  v16[0] = (*(int(__cdecl **)(char *))((char *)&loc_B3BEC + bgs))(a4->model);
  v16[1] = 0;
  v16[2] = 0;
  v8 = a4;
  v15 = 1;
  v13 = 0;
  attachTagNames = a4->attachTagNames;
  attachModelNames = a4->attachModelNames;
  v11 = &v17;
    do {
        while (!v8->attachModelNames[0]) {
          ++v13;
          attachModelNames += 64;
          attachTagNames += 64;
          v8 = (clientInfo_t *)((char *)v8 + 64);
          if (v13 == 6)
            goto LABEL_14;
        }
      *((_DWORD *)v11 - 24) = (*(int(__cdecl **)(char *))(
          (char *)&loc_B3BEC + bgs))(attachModelNames);
      *((_DWORD *)v11 - 23) = attachTagNames;
      *((_DWORD *)v11 - 22) = (a5 >> v13) & 1;
      ++v15;
      v11 += 12;
      ++v13;
      attachModelNames += 64;
      attachTagNames += 64;
      v8 = (clientInfo_t *)((char *)v8 + 64);
    }
  while (v13 != 6);
LABEL_14:
  a4->iDObjWeapon = v12;
  result = (*(int(__cdecl **)(_DWORD *, _DWORD, XAnimTree_s *, uint32_t,
                              clientInfo_t *))(bgs + 736240))(
      v16, v15, pXAnimTree, a3->number, a4);
  a4->dobjDirty = 0;
  return result;
}

// 312D00: using guessed type int bgs;

//----- (001803A2) --------------------------------------------------------
int __cdecl BG_LerpOffset(float *a1, float a2, float *a3)
{
  float v3;   // xmm5_4
  float v4;   // xmm3_4
  float v5;   // xmm4_4
  float v6;   // xmm2_4
  int result; // eax
  float v8;   // xmm0_4

  v3 = *a1 - *a3;
  v4 = a1[1] - a3[1];
  v5 = a1[2] - a3[2];
  v6 = (float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5);
    if (v6 != 0.0) {
      result = 1597463007 - (SLODWORD(v6) >> 1);
      v8 = (float)((float)(1.5 - (float)((float)((float)(v6 * 0.5) *
                                                 *(float *)&result) *
                                         *(float *)&result)) *
                   *(float *)&result) *
           a2;
        if (v8 < 1.0) {
          *a3 = (float)(v3 * v8) + *a3;
          a3[1] = (float)(v4 * v8) + a3[1];
          a3[2] = (float)(v5 * v8) + a3[2];
        }
        else {
          *a3 = *a1;
          a3[1] = a1[1];
          result = *((int *)a1 + 2);
          a3[2] = *(float *)&result;
        }
    }
  return result;
}

//----- (00180488) --------------------------------------------------------
int __cdecl BG_UpdateConditionValue(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5;     // edx

    if (a4 && !animConditionsTable[2 * a2]) {
      v5 = a2 + 151 * a1;
      *(_DWORD *)(bgs + 8 * v5 + 737368) = 0;
      *(_DWORD *)(bgs + 8 * v5 + 737372) = 0;
      result = 1 << (a3 & 0x1F);
      *(_DWORD *)(bgs + 8 * v5 + 737368 + 4 * (a3 >> 5)) |= result;
    }
    else {
      result = bgs;
      *(_DWORD *)(bgs + 8 * (a2 + 151 * a1) + 737368) = a3;
    }
  return result;
}

// 312D00: using guessed type int bgs;
// 312F60: using guessed type int animConditionsTable[];

//----- (0018051A) --------------------------------------------------------
int __cdecl BG_AnimUpdatePlayerStateConditions(pmove_t *a1)
{
  int32_t ps;                   // esi
  int32_t ViewmodelWeaponIndex; // eax
  int WeaponDef;                // edi
  int v4;                       // ebx
  int v5;                       // ecx
  int v6;                       // ebx
  int v7;                       // ecx
  int v8;                       // ecx
  int v9;                       // ecx
  int v10;                      // ecx
  int v11;                      // ecx
  int v12;                      // ebx
  int v13;                      // ecx
  int v14;                      // ecx
  int result;                   // eax
  int v16;                      // ecx

  ps = a1->ps;
  ViewmodelWeaponIndex =
      BG_GetViewmodelWeaponIndex((const playerState_s *)a1->ps);
  WeaponDef = BG_GetWeaponDef(ViewmodelWeaponIndex);
  v4 = *(_DWORD *)(WeaponDef + 116);
  v5 = *(_DWORD *)(ps + 204);
    if (!animConditionsTable[0]) {
      *(_DWORD *)(bgs + 1208 * v5 + 737368) = 0;
      *(_DWORD *)(bgs + 1208 * v5 + 737372) = 0;
      *(_DWORD *)(1208 * v5 + bgs + 737368 + 4 * (v4 >> 5)) |= 1 << (v4 & 0x1F);
      v6 = *(_DWORD *)(WeaponDef + 124);
      v7 = *(_DWORD *)(ps + 204);
      if (!dword_312F68)
        goto LABEL_3;
    LABEL_9:
      *(_DWORD *)((char *)&loc_B4060 + 1208 * v7 + bgs) = v6;
      if ((*(_BYTE *)(ps + 162) & 4) != 0)
        goto LABEL_4;
    LABEL_10:
      v10 = *(_DWORD *)(ps + 204);
        if (dword_312F98) {
          *(_DWORD *)(bgs + 1208 * v10 + 737424) = 0;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v10 + 737424) = 0;
          *(_DWORD *)(bgs + 1208 * v10 + 737428) = 0;
          *(_DWORD *)(1208 * v10 + bgs + 737424) |= 1u;
        }
      goto LABEL_12;
    }
  *(_DWORD *)(bgs + 1208 * v5 + 737368) = v4;
  v6 = *(_DWORD *)(WeaponDef + 124);
  v7 = *(_DWORD *)(ps + 204);
  if (dword_312F68)
    goto LABEL_9;
LABEL_3:
  *(_DWORD *)((char *)&loc_B4060 + 1208 * v7 + bgs) = 0;
  *(_DWORD *)(bgs + 1208 * v7 + 737380) = 0;
  *(_DWORD *)((char *)&loc_B4060 + 1208 * v7 + 4 * (v6 >> 5) + bgs) |=
      1 << (v6 & 0x1F);
  if ((*(_BYTE *)(ps + 162) & 4) == 0)
    goto LABEL_10;
LABEL_4:
  v8 = *(_DWORD *)(ps + 204);
    if (dword_312F98) {
      *(_DWORD *)(bgs + 1208 * v8 + 737424) = 1;
      if ((*(_DWORD *)(ps + 160) & 0x300) == 0)
        goto LABEL_6;
    LABEL_13:
      v11 = *(_DWORD *)(ps + 204);
        if (dword_312F70) {
          *(_DWORD *)(bgs + 1208 * v11 + 737384) = 1;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v11 + 737384) = 0;
          *(_DWORD *)(bgs + 1208 * v11 + 737388) = 0;
          *(_DWORD *)(1208 * v11 + bgs + 737384) |= 2u;
        }
      goto LABEL_15;
    }
  *(_DWORD *)(bgs + 1208 * v8 + 737424) = 0;
  *(_DWORD *)(bgs + 1208 * v8 + 737428) = 0;
  *(_DWORD *)(1208 * v8 + bgs + 737424) |= 2u;
LABEL_12:
  if ((*(_DWORD *)(ps + 160) & 0x300) != 0)
    goto LABEL_13;
LABEL_6:
  v9 = *(_DWORD *)(ps + 204);
    if (dword_312F70) {
      *(_DWORD *)(bgs + 1208 * v9 + 737384) = 0;
    }
    else {
      *(_DWORD *)(bgs + 1208 * v9 + 737384) = 0;
      *(_DWORD *)(bgs + 1208 * v9 + 737388) = 0;
      *(_DWORD *)(1208 * v9 + bgs + 737384) |= 1u;
    }
LABEL_15:
  v12 = *(float *)(ps + 232) > 0.0;
  v13 = *(_DWORD *)(ps + 204);
    if (dword_312F80) {
      *(_DWORD *)(bgs + 1208 * v13 + 737400) = v12;
    }
    else {
      *(_DWORD *)(bgs + 1208 * v13 + 737400) = 0;
      *(_DWORD *)(bgs + 1208 * v13 + 737404) = 0;
      *(_DWORD *)(1208 * v13 + bgs + 737400) |= 1 << v12;
    }
    if ((a1->cmd[4] & 1) != 0) {
      v14 = *(_DWORD *)(ps + 204);
        if (dword_312F90) {
          result = bgs + 1208 * v14;
          *(_DWORD *)(result + 737416) = 1;
        }
        else {
          result = 1208 * v14;
          *(_DWORD *)(bgs + 1208 * v14 + 737416) = 0;
          *(_DWORD *)(bgs + 1208 * v14 + 737420) = 0;
          *(_DWORD *)(1208 * v14 + bgs + 737416) |= 2u;
        }
    }
    else {
      v16 = *(_DWORD *)(ps + 204);
        if (dword_312F90) {
          result = bgs + 1208 * v16;
          *(_DWORD *)(result + 737416) = 0;
        }
        else {
          result = 1208 * v16;
          *(_DWORD *)(bgs + 1208 * v16 + 737416) = 0;
          *(_DWORD *)(bgs + 1208 * v16 + 737420) = 0;
          *(_DWORD *)(1208 * v16 + bgs + 737416) |= 1u;
        }
    }
  return result;
}

// 312D00: using guessed type int bgs;
// 312F60: using guessed type int animConditionsTable[];
// 312F68: using guessed type int dword_312F68;
// 312F70: using guessed type int dword_312F70;
// 312F80: using guessed type int dword_312F80;
// 312F90: using guessed type int dword_312F90;
// 312F98: using guessed type int dword_312F98;

//----- (00180A36) --------------------------------------------------------
int __cdecl BG_Player_DoControllers(const DObj_s *a1, const entityState_s *a2,
                                    int *a3, clientInfo_t *a4, int a5)
{
  uint32_t eFlags;          // ecx
  int32_t fTorsoHeight;     // edi
  float v7;                 // xmm2_4
  float v8;                 // xmm3_4
  uint32_t v9;              // eax
  float v10;                // xmm1_4
  float v11;                // xmm2_4
  float v12;                // xmm3_4
  float v13;                // xmm0_4
  float v14;                // xmm0_4
  int v15;                  // ebx
  int v16;                  // edx
  float v17;                // xmm3_4
  unsigned __int16 **v18;   // edi
  float *v19;               // ebx
  int v20;                  // esi
  _DWORD *v21;              // ecx
  int i;                    // edx
  float *v23;               // eax
  float v24;                // xmm0_4
  float v25;                // xmm1_4
  float *tag_origin_angles; // esi
  int j;                    // edx
  float *v28;               // eax
  float v29;                // xmm0_4
  float v30;                // xmm1_4
  float v32;                // xmm0_4
  float v33;                // xmm0_4
  float v34;                // xmm3_4
  float v35;                // xmm0_4
  float v36;                // xmm1_4
  float v37;                // xmm1_4
  float LeanFraction;       // [esp+2Ch] [ebp-16Ch]
  float v39;                // [esp+2Ch] [ebp-16Ch]
  float v40;                // [esp+2Ch] [ebp-16Ch]
  float v41;                // [esp+8Ch] [ebp-10Ch]
  int v42;                  // [esp+90h] [ebp-108h]
  float v43;                // [esp+98h] [ebp-100h]
  float v44;                // [esp+9Ch] [ebp-FCh]
  float v45;                // [esp+A4h] [ebp-F4h]
  float v46;                // [esp+A8h] [ebp-F0h]
  _DWORD __b[24];           // [esp+B4h] [ebp-E4h] BYREF
  float v48;                // [esp+114h] [ebp-84h] BYREF
  float v49;                // [esp+118h] [ebp-80h]
  float v50;                // [esp+11Ch] [ebp-7Ch]
  float v51;                // [esp+120h] [ebp-78h]
  float v52;                // [esp+124h] [ebp-74h]
  float v53;                // [esp+128h] [ebp-70h]
  float v54;                // [esp+12Ch] [ebp-6Ch]
  float v55;                // [esp+130h] [ebp-68h]
  float v56;                // [esp+134h] [ebp-64h]
  float v57;                // [esp+138h] [ebp-60h]
  float v58;                // [esp+13Ch] [ebp-5Ch]
  int v59;                  // [esp+140h] [ebp-58h]
  float v60;                // [esp+144h] [ebp-54h]
  float v61;                // [esp+148h] [ebp-50h]
  float v62;                // [esp+14Ch] [ebp-4Ch]
  float v63;                // [esp+150h] [ebp-48h]
  int v64;                  // [esp+154h] [ebp-44h]
  int v65;                  // [esp+158h] [ebp-40h]
  float v66;                // [esp+15Ch] [ebp-3Ch] BYREF
  float v67;                // [esp+160h] [ebp-38h]
  float v68;                // [esp+164h] [ebp-34h]
  float v69;                // [esp+168h] [ebp-30h] BYREF
  float v70;                // [esp+16Ch] [ebp-2Ch]
  float v71;                // [esp+170h] [ebp-28h]
  float v72;                // [esp+174h] [ebp-24h] BYREF
  float yawAngle;           // [esp+178h] [ebp-20h]
  float v74;                // [esp+17Ch] [ebp-1Ch]

  eFlags = a2->eFlags;
    if ((eFlags & 0x300) != 0) {
      memset(__b, 0, sizeof(__b));
      goto LABEL_17;
    }
  v72 = 0.0;
  v74 = 0.0;
  v69 = 0.0;
  v71 = 0.0;
  v66 = a4->playerAngles[0];
  v67 = a4->playerAngles[1];
  v68 = a4->playerAngles[2];
  yawAngle = a4->legs.yawAngle;
  v70 = *(float *)a4->torso;
    if ((LODWORD(a4->clientConditions[2][0]) & 0xC0000) == 0) {
      v36 = *(float *)&a4->torso[8];
      v69 = v36;
        if ((eFlags & 8) != 0) {
          v40 = AngleNormalize180(v36);
          v69 = v40;
          if (v40 <= 0.0)
            v37 = v40 * 0.25;
          else
            v37 = v40 * 0.5;
          v69 = v37;
        }
    }
  AnglesSubtract(&v66, &v69, &v66);
  AnglesSubtract(&v69, &v72, &v69);
  fTorsoHeight = a2->fTorsoHeight;
  LeanFraction = GetLeanFraction(*(float *)&a4->lerpLean);
  v7 = LeanFraction;
  v8 = LeanFraction * 50.0;
  v71 = (float)(LeanFraction * 50.0) * 0.92500001;
  v68 = v71;
    if (LeanFraction == 0.0) {
      v45 = 0.0;
      v9 = a2->eFlags;
      goto LABEL_5;
    }
  v9 = a2->eFlags;
    if ((v9 & 4) != 0) {
      if (LeanFraction > 0.0)
        goto LABEL_30;
      v45 = (float)(LeanFraction * -12.5) + 0.0;
    LABEL_5:
      if ((v9 & 0x20000) != 0)
        goto LABEL_6;
      goto LABEL_31;
    }
    if (LeanFraction <= 0.0) {
      v45 = (float)(LeanFraction * -5.0) + 0.0;
      goto LABEL_5;
    }
LABEL_30:
  v45 = (float)(LeanFraction * -2.5) + 0.0;
    if ((v9 & 0x20000) != 0) {
    LABEL_6:
      if ((v9 & 8) == 0)
        goto LABEL_7;
    LABEL_32:
      if (v7 != 0.0)
        v68 = 0.5 * v68;
      v72 = v72 + *(float *)&a2->fTorsoPitch;
      v32 = v70 * 0.0174532925199433;
      v39 = sinf(v32);
      v41 = cosf(v32);
      v46 = (float)((float)(1.0 - v41) * -24.0) + 0.0;
      v33 = (float)(v39 * -12.0) + v45;
      v45 = v33;
      if ((float)(v39 * v7) > 0.0)
        v45 = (float)((float)((float)(1.0 - v41) * (float)-v7) * 16.0) + v33;
      v48 = 0.0;
      v34 = v71;
      v49 = v71 * -1.2;
      v50 = v71 * 0.30000001;
      v35 = *(float *)&a2->fTorsoPitch;
        if (v35 != 0.0 || *(float *)&a2->fWaistPitch != 0.0) {
          v43 = AngleSubtract(v35, *(float *)&a2->fWaistPitch);
          v48 = v48 + v43;
          v34 = v71;
        }
      v51 = 0.0;
      v52 = (float)(v70 * 0.1) + (float)(v34 * -0.2);
      v53 = v34 * 0.2;
      v54 = v69;
      v55 = (float)(v70 * 0.80000001) + v71;
      v56 = v34 * -0.2;
      goto LABEL_11;
    }
LABEL_31:
  yawAngle = AngleSubtract(yawAngle, a4->playerAngles[1]);
  v9 = a2->eFlags;
  v8 = LeanFraction * 50.0;
  v7 = LeanFraction;
  if ((v9 & 8) != 0)
    goto LABEL_32;
LABEL_7:
    if (v7 != 0.0 && ((v9 & 4) == 0 || v7 <= 0.0)) {
      v71 = v71 * 1.25;
      v68 = 1.25 * v68;
    }
  v74 = (float)(v8 * 0.075000003) + v74;
  v10 = v69;
  v48 = v69 * 0.2;
  v11 = v70;
  v49 = v70 * 0.40000001;
  v12 = v71;
  v50 = v71 * 0.5;
  v13 = *(float *)&a2->fTorsoPitch;
    if (v13 != 0.0 || *(float *)&a2->fWaistPitch != 0.0) {
      v44 = AngleSubtract(v13, *(float *)&a2->fWaistPitch);
      v48 = v48 + v44;
      v12 = v71;
      v11 = v70;
      v10 = v69;
    }
  v51 = v10 * 0.30000001;
  v52 = 0.40000001 * v11;
  v53 = v12 * 0.5;
  v54 = 0.5 * v10;
  v55 = v11 * 0.2;
  v56 = v12 * -0.60000002;
  v46 = 0.0;
LABEL_11:
  v57 = v66 * 0.30000001;
  v58 = 0.30000001 * v67;
  v59 = 0;
  v60 = v66 * 0.69999999;
  v61 = v67 * 0.69999999;
  v62 = -0.30000001 * v68;
  v63 = 0.0;
  v64 = 0;
  v65 = 0;
  v14 = *(float *)&a2->fWaistPitch;
  if (v14 != 0.0 || *(float *)&a2->fTorsoPitch != 0.0)
    v63 = AngleSubtract(v14, *(float *)&a2->fTorsoPitch);
  v15 = 0;
  v16 = 0;
    do {
      __b[v16] = *(_DWORD *)((char *)&v48 + v16 * 4);
      __b[v16 + 1] = *(_DWORD *)((char *)&v48 + v16 * 4 + 4);
      __b[v16 + 2] = *(_DWORD *)((char *)&v48 + v16 * 4 + 8);
      ++v15;
      v16 += 3;
    }
  while (v15 != 6);
  *(float *)&__b[18] = v72;
  *(float *)&__b[19] = yawAngle;
  *(float *)&__b[20] = v74;
  *(float *)&__b[21] = v46;
  *(float *)&__b[22] = v45;
  __b[23] = fTorsoHeight;
LABEL_17:
  v17 = (float)a5 * 0.36000001;
  v42 = 0;
  v18 = (unsigned __int16 **)&controller_names;
  v19 = a4->angles[0];
  v20 = 0;
    do {
      v21 = &__b[v20];
        for (i = 1; i != 4; ++i) {
          v23 = &v19[i];
          v24 = *(v23 - 1);
          v25 = *(float *)&v21[i - 1] - v24;
            if (v25 <= v17) {
              if ((float)-v17 <= v25)
                *(v23 - 1) = *(float *)&v21[i - 1];
              else
                *(v23 - 1) = v24 - v17;
            }
            else {
              *(v23 - 1) = v24 + v17;
            }
        }
      DObjSetControlTagAngles(a1, a3, **v18, v19);
      ++v42;
      v20 += 3;
      v19 += 3;
      ++v18;
    }
  while (v42 != 6);
  tag_origin_angles = a4->tag_origin_angles;
    for (j = 1; j != 4; ++j) {
      v28 = &tag_origin_angles[j];
      v29 = *(v28 - 1);
      v30 = *(float *)&__b[j + 17] - v29;
        if (v30 <= v17) {
          if ((float)-v17 <= v30)
            *(v28 - 1) = *(float *)&__b[j + 17];
          else
            *(v28 - 1) = v29 - v17;
        }
        else {
          *(v28 - 1) = v29 + v17;
        }
    }
  BG_LerpOffset((float *)&__b[21], (float)a5 * 0.1, a4->tag_origin_offset);
  return DObjSetLocalTag(a1, a3, (unsigned __int16)word_195B122,
                         a4->tag_origin_offset, tag_origin_angles);
}

// 195B122: using guessed type __int16 word_195B122;

//----- (00181346) --------------------------------------------------------
int __usercall BG_RunLerpFrameRate
    @<eax>(int *a1 @<eax>, int *a2 @<edx>, unsigned int a3 @<ecx>,
           clientInfo_t *a4)
{
  int result;       // eax
  int v6;           // ebx
  int v7;           // eax
  unsigned int v8;  // edx
  int v9;           // ecx
  int v10;          // edx
  unsigned int v11; // ebx
  int v12;          // ebx
  bool v13;         // bl
  int v14;          // ebx
  int v15;          // edx
  float v16;        // xmm1_4
  char *v17;        // ecx
  int *v18;         // edi
  float v19;        // xmm0_4
  int v20;          // ebx
  char *v21;        // ecx
  unsigned int v22; // ebx
  unsigned int v23; // ebx
  int v24;          // edx
  float v25;        // xmm0_4
  float v26;        // xmm1_4
  float v27;        // xmm1_4
  float v28;        // xmm1_4
  char v29;         // [esp+8h] [ebp-A0h]
  float v30;        // [esp+2Ch] [ebp-7Ch]
  _BOOL4 v31;       // [esp+48h] [ebp-60h]
  int v32;          // [esp+4Ch] [ebp-5Ch]
  int v33;          // [esp+50h] [ebp-58h]
  char v35;         // [esp+5Fh] [ebp-49h]
  int v36;          // [esp+60h] [ebp-48h]
  unsigned int v37; // [esp+64h] [ebp-44h]
  uint32_t v38;     // [esp+68h] [ebp-40h]
  XAnimTree_s *v39; // [esp+6Ch] [ebp-3Ch]
  float Weight;     // [esp+70h] [ebp-38h]
  char v41[4];      // [esp+74h] [ebp-34h]
  float Time;       // [esp+78h] [ebp-30h]
  XAnimTree_s *v43; // [esp+80h] [ebp-28h]
  XAnim_s *v44;     // [esp+84h] [ebp-24h]
  unsigned int v45; // [esp+88h] [ebp-20h]

  result = a2[5];
  v36 = result;
    if (result && (*(_BYTE *)(result + 80) & 2) != 0) {
      v35 = 1;
      v39 = (XAnimTree_s *)a1[297];
      v6 = a2[4];
      v37 = v6;
      if (v6 != a3)
        goto LABEL_4;
    }
    else {
      v35 = 0;
      v39 = (XAnimTree_s *)a1[297];
      v6 = a2[4];
      v37 = v6;
      if (v6 != a3)
        goto LABEL_4;
    }
    if (result) {
      BYTE1(v6) &= ~2u;
      result = v6;
      if (!v6)
        return result;
      goto LABEL_31;
    }
  if ((v37 & 0xFFFFFDFF) == 0)
    return result;
LABEL_4:
  v38 = (a4->clientNum >> 19) & 1;
  a2[4] = a3;
  BYTE1(a3) &= ~2u;
  v45 = a3;
  v7 = bgs;
  v8 = *(_DWORD *)(bgs + 49152);
    if (a3 >= v8) {
      Com_Error(1, "\x15Player animation index out of range (%i): %i", v8);
      v7 = bgs;
    }
  v43 = (XAnimTree_s *)a1[297];
  v44 = *(XAnim_s **)((char *)&loc_B3BB4 + v7);
    if (v45) {
      v20 = 96 * v45;
      *(_DWORD *)v41 = 96 * v45 + v7;
      a2[5] = *(_DWORD *)v41;
      a2[6] = *(_DWORD *)(*(_DWORD *)v41 + 64);
      v21 = globalScriptData;
        if (v45 >= *((_DWORD *)globalScriptData + 12288)) {
          Com_Error(1, "\x15BG_GetAnimationForIndex: index out of bounds", v29);
          v21 = globalScriptData;
          v20 = 96 * v45;
        }
      v33 = (*(_DWORD *)&v21[v20 + 88] & 0x180 |
             *(_DWORD *)&v21[v20 + 84] & 0xC4) != 0;
        if ((v37 & 0xFFFFFDFF) >= *((_DWORD *)v21 + 12288)) {
          Com_Error(1, "\x15BG_GetAnimationForIndex: index out of bounds", v29);
          v21 = globalScriptData;
        }
      v22 = 96 * (v37 & 0xFFFFFDFF);
      v32 = (*(_DWORD *)&v21[v22 + 88] & 0x180 |
             *(_DWORD *)&v21[v22 + 84] & 0xC4) != 0;
        if (v45 >= *((_DWORD *)v21 + 12288)) {
          Com_Error(1, "\x15BG_GetAnimationForIndex: index out of bounds", v29);
          v21 = globalScriptData;
        }
      v31 = (*(_DWORD *)&v21[96 * v45 + 84] & 0x308) != 0;
        if ((v37 & 0xFFFFFDFF) >= *((_DWORD *)v21 + 12288)) {
          Com_Error(1, "\x15BG_GetAnimationForIndex: index out of bounds", v29);
          v21 = globalScriptData;
        }
        if (a2 == a1 + 224 &&
            (v33 != v32 || v31 != ((*(_DWORD *)&v21[v22 + 84] & 0x308) != 0))) {
          a1[299] = *(_DWORD *)(bgs + 736220) + 400;
          if (v36)
            goto LABEL_9;
          goto LABEL_55;
        }
    }
    else {
      a2[5] = 0;
      a2[6] = 200;
      *(_DWORD *)v41 = 0;
    }
  if (v36)
    goto LABEL_9;
LABEL_55:
    if (a2 == a1 + 224) {
      a2[6] = 0;
      goto LABEL_16;
    }
LABEL_9:
  if (!*(_DWORD *)v41)
    goto LABEL_75;
    if (a2[6] <= 0) {
        if (*(float *)(*(_DWORD *)v41 + 68) != 0.0) {
          v9 = 120;
          goto LABEL_12;
        }
    LABEL_75:
      if (v36 && *(float *)(v36 + 68) != 0.0)
        v9 = 250;
      else
        v9 = 170;
      goto LABEL_12;
    }
  v9 = -1;
LABEL_12:
  v10 = a1[299] - *(_DWORD *)(bgs + 736220);
  if (v9 >= v10)
    v10 = v9;
  if (v10 > a2[6])
    a2[6] = v10;
LABEL_16:
    if (*(_DWORD *)v41 && *(float *)(*(_DWORD *)v41 + 68) != 0.0 &&
        (unsigned __int8)XAnimIsLooped(v44, v45)) {
      v11 = v37;
      BYTE1(v11) = BYTE1(v37) & 0xFD;
        if (v36 && *(float *)(v36 + 68) != 0.0 &&
            (unsigned __int8)XAnimIsLooped(v44, v11)) {
          Time = XAnimGetTime(v43, v11);
          goto LABEL_21;
        }
        if (XAnimIsPrimitive(v44, v11)) {
          v24 = XAnimGetLengthMsec(v44, v11) + 200;
          v25 = (float)v24;
        }
        else {
          v24 = 1000;
          v25 = 1000.0;
        }
      v26 = (float)((float)(*(_DWORD *)(bgs + 736220) % v24) / v25) +
            (float)((float)a1[2] * 0.36000001);
      Time = v26 - (float)(int)v26;
    }
    else {
      Time = 0.0;
    }
  if (!v36)
    goto LABEL_22;
  v11 = v37;
  BYTE1(v11) = BYTE1(v37) & 0xFD;
LABEL_21:
  XAnimClearGoalWeight((float)a2[6] * 0.001, v43, v11, (float)a2[6] * 0.001);
LABEL_22:
    if (v45) {
        if (a2 == a1 + 224) {
          v12 = *(_DWORD *)v41;
            if ((*(_BYTE *)(*(_DWORD *)v41 + 80) & 0x40) == 0) {
            LABEL_25:
              v13 = 0;
                if (*(float *)(v12 + 68) != 0.0) {
                  Weight = XAnimGetWeight(v43, v45);
                  if (Weight == 0.0)
                    v13 = 1;
                }
              XAnimSetCompleteGoalWeight(
                  v43, v45, 0x3F800000u, (float)a2[6] * 0.001, 1065353216, 0,
                  *(_DWORD *)(*(_DWORD *)v41 + 92), a2 != a1 + 224);
              if (v13)
                XAnimSetTime(v43, v45, Time);
            LABEL_29:
                if (a2 != a1 + 224) {
                  XAnimSetCompleteGoalWeight(
                      v43, *(unsigned __int16 *)(bgs + 736184), 0x3F800000u,
                      (float)a2[6] * 0.001, 1065353216, 0,
                      *(_DWORD *)(*(_DWORD *)v41 + 92), 0);
                  XAnimSetCompleteGoalWeight(
                      v43, *(unsigned __int16 *)(bgs + 736186), 0x3C23D70Au,
                      (float)a2[6] * 0.001, 1065353216, 0,
                      *(_DWORD *)(*(_DWORD *)v41 + 92), 0);
                }
            LABEL_31:
              v14 = a2[5];
                if (*(float *)(v14 + 68) == 0.0 || (v15 = a2[11]) == 0) {
                  a2[10] = 1065353216;
                  a2[11] = *(_DWORD *)((char *)&loc_B3BE0 + bgs);
                  a2[7] = *(_DWORD *)&a4->name[12];
                  a2[8] = *(_DWORD *)&a4->name[16];
                  result = *(_DWORD *)&a4->name[20];
                  a2[9] = result;
                }
                else {
                  result = bgs;
                    if (v15 != *(_DWORD *)((char *)&loc_B3BE0 + bgs)) {
                        if (v35) {
                          v16 = fabs(*((float *)a2 + 9) -
                                     *(float *)&a4->name[20]);
                          v17 = &a4->name[12];
                          v18 = a2 + 7;
                        }
                        else {
                          v18 = a2 + 7;
                          v30 = Vec3Distance((float *)a2 + 7,
                                             (float *)&a4->name[12]);
                          v16 = v30;
                          result = bgs;
                          v15 = a2[11];
                          v17 = &a4->name[12];
                        }
                      *((float *)a2 + 10) =
                          (float)(v16 /
                                  (float)((float)(*(_DWORD
                                                        *)((char *)&loc_B3BE0 +
                                                           result) -
                                                  v15) *
                                          0.001)) /
                          *(float *)(v14 + 68);
                      a2[11] = *(_DWORD *)((char *)&loc_B3BE0 + bgs);
                      a2[7] = *(_DWORD *)&a4->name[12];
                      v18[1] = *((_DWORD *)v17 + 1);
                      result = *((_DWORD *)v17 + 2);
                      v18[2] = result;
                      v19 = *((float *)a2 + 10);
                        if (v19 >= 0.1) {
                            if (v19 > 2.0) {
                                if ((*(_BYTE *)(v14 + 80) & 2) != 0) {
                                  if (v19 > 4.0)
                                    a2[10] = 1082130432;
                                }
                                else {
                                  v27 = *(float *)(v14 + 68);
                                    if (v27 <= 150.0) {
                                        if (v27 >= 20.0) {
                                          v28 = (float)((float)(v27 - 20.0) /
                                                        -130.0) +
                                                3.0;
                                          if (v19 > v28)
                                            *((float *)a2 + 10) = v28;
                                        }
                                        else if (v19 > 3.0) {
                                          a2[10] = 1077936128;
                                        }
                                    }
                                    else {
                                      a2[10] = 0x40000000;
                                    }
                                }
                            }
                        }
                        else if (v19 < 0.0099999998 && v35) {
                          a2[10] = 0;
                        }
                        else {
                          a2[10] = 1036831949;
                        }
                    }
                }
              v23 = a2[4];
                if (v23) {
                  BYTE1(v23) &= ~2u;
                  return XAnimSetAnimRate(v39, v23, a2[10]);
                }
              return result;
            }
        }
        else {
          a1[253] = 0;
          a1[254] = 1;
          v12 = *(_DWORD *)v41;
          if ((*(_BYTE *)(*(_DWORD *)v41 + 80) & 0x40) == 0)
            goto LABEL_25;
        }
      if ((unsigned __int8)XAnimIsLooped(v44, v45))
        Com_Error(1, "death animation '%s' is looping", v12);
        if (v38) {
          XAnimSetCompleteGoalWeight(v43, v45, 0x3F800000u,
                                     (float)a2[6] * 0.001, 1065353216, 0, 0, 0);
        }
        else {
          XAnimSetCompleteGoalWeightKnobAll(
              v43, v45, *(unsigned __int16 *)((char *)&loc_B3BCC + bgs),
              0x3F800000u, 0.0, 1065353216, 0, 0);
          XAnimSetTime(v43, v45, 1.0);
        }
      goto LABEL_29;
    }
  result = a2 == a1 + 224;
    if (a2 != a1 + 224) {
      XAnimSetCompleteGoalWeight(v43, *(unsigned __int16 *)(bgs + 736184), 0,
                                 (float)a2[6] * 0.001, 1065353216, 0, 0, 0);
      return XAnimSetCompleteGoalWeight(
          v43, *(unsigned __int16 *)(bgs + 736186), 0x3F800000u,
          (float)a2[6] * 0.001, 1065353216, 0, 0, 0);
    }
  return result;
}

// 18153F: conditional instruction was optimized away because %var_20.4!=0
// 181B87: variable 'v29' is possibly undefined
// 312D00: using guessed type int bgs;

//----- (00181DA6) --------------------------------------------------------
int __cdecl BG_PlayerAnimation(const DObj_s *a1, entityState_s *a2,
                               clientInfo_t *a3)
{
  uint32_t eFlags;               // edx
  float v4;                      // xmm4_4
  float v5;                      // xmm0_4
  float v6;                      // xmm2_4
  uint32_t v7;                   // eax
  entityState_s *v8;             // eax
  uint32_t v9;                   // edx
  float v10;                     // xmm0_4
  int WeaponDef;                 // esi
  int v12;                       // ebx
  uint32_t clientNum;            // ecx
  int v14;                       // ebx
  uint32_t v15;                  // ecx
  entityState_s *v16;            // eax
  uint32_t v17;                  // ecx
  uint32_t v18;                  // ecx
  int v19;                       // ebx
  uint32_t v20;                  // ecx
  uint32_t v21;                  // ecx
  uint32_t v22;                  // ecx
  unsigned int v23;              // edi
  int v24;                       // edx
  int v25;                       // ecx
  int v26;                       // eax
  uint32_t v27;                  // ecx
  int v28;                       // eax
  const XAnimTree_s *pXAnimTree; // ebx
  unsigned int v30;              // eax
  unsigned int v31;              // eax
  float v33;                     // eax
  int32_t legsAnim;              // eax
  uint32_t v35;                  // ecx
  uint32_t v36;                  // ecx
  uint32_t v37;                  // ecx
  uint32_t v38;                  // ecx
  uint32_t v39;                  // ecx
  int32_t *p_yawing;             // edx
  int v41;                       // ecx
  lerpFrame_t *v42;              // eax
  uint32_t v43;                  // ecx
  int v44;                       // eax
  float v45;                     // xmm0_4
  int v46;                       // eax
  int v47;                       // ebx
  int *p_legs;                   // [esp+28h] [ebp-40h]
  int v49;                       // [esp+2Ch] [ebp-3Ch]
  float v50;                     // [esp+38h] [ebp-30h]
  float Weight;                  // [esp+3Ch] [ebp-2Ch]
  float v52;                     // [esp+40h] [ebp-28h]
  float v53;                     // [esp+44h] [ebp-24h]
  float v54;                     // [esp+48h] [ebp-20h]
  float v55;                     // [esp+4Ch] [ebp-1Ch]

  GetLeanFraction(*(float *)&a3->lerpLean);
  v50 = *(float *)&a3->lerpMoveDir;
  v53 = a3->playerAngles[0];
  v55 = AngleMod(a3->playerAngles[1]);
  eFlags = a2->eFlags;
    if ((eFlags & 0x300) != 0) {
      *(_DWORD *)&a3->torso[4] = 1;
      *(_DWORD *)&a3->torso[12] = 1;
      a3->legs.yawing = 1;
      eFlags = a2->eFlags;
    }
    else {
      v33 = a3->clientConditions[2][0];
        if ((LODWORD(v33) & 0xC0000) != 0) {
          *(_DWORD *)&a3->torso[4] = 1;
          *(_DWORD *)&a3->torso[12] = 1;
          a3->legs.yawing = 1;
          eFlags = a2->eFlags;
        }
        else if ((eFlags & 0x4000) != 0) {
          *(_DWORD *)&a3->torso[4] = 1;
          *(_DWORD *)&a3->torso[12] = 1;
          a3->legs.yawing = 1;
          eFlags = a2->eFlags;
        }
        else if ((LOBYTE(v33) & 6) != 0) {
          v47 = LODWORD(a3->clientConditions[4][0]);
            if (dword_312F90) {
            LABEL_108:
                if (v47) {
                  *(_DWORD *)&a3->torso[4] = 1;
                  *(_DWORD *)&a3->torso[12] = 1;
                  eFlags = a2->eFlags;
                }
            }
            else if ((v47 & 1) == 0) {
              v47 = 0;
                while (++v47 != 64) {
                  if (((SLODWORD(a3->clientConditions[4][v47 >> 5]) >>
                        (v47 & 0x1F)) &
                       1) != 0)
                    goto LABEL_108;
                }
            }
        }
        else {
          *(_DWORD *)&a3->torso[4] = 1;
          *(_DWORD *)&a3->torso[12] = 1;
          a3->legs.yawing = 1;
          eFlags = a2->eFlags;
        }
    }
  v54 = v50 + v55;
  if ((eFlags & 0x20000) != 0)
    goto LABEL_6;
    if ((LODWORD(a3->clientConditions[2][0]) & 0xC0000) != 0) {
      v4 = v50 + v55;
      v5 = v50 + v55;
      v6 = 0.0;
      goto LABEL_7;
    }
    if ((eFlags & 0x4000) != 0) {
    LABEL_6:
      v4 = v55;
      v5 = v55;
      v6 = 90.0;
      goto LABEL_7;
    }
    if ((eFlags & 8) != 0) {
    LABEL_102:
      v4 = v50 + v55;
      v5 = v55;
      v6 = 90.0;
      goto LABEL_7;
    }
    if ((eFlags & 0x40) == 0) {
        if ((eFlags & 0x40000) == 0) {
          v5 = (float)(v50 * 0.30000001) + v55;
          v4 = v50 + v55;
          v6 = 90.0;
          goto LABEL_7;
        }
      goto LABEL_102;
    }
  v4 = v50 + v55;
  v5 = v55;
  v6 = 45.0;
LABEL_7:
  BG_SwingAngles((float *)a3->torso, &a3->torso[4], v5, 0.0, v6,
                 *(float *)(bg_swingSpeed + 8));
  v7 = a2->eFlags;
    if ((v7 & 0x20000) != 0) {
      p_yawing = &a3->legs.yawing;
      p_legs = (int *)&a3->legs;
      v41 = bg_swingSpeed;
      v42 = &a3->legs;
    LABEL_76:
      BG_SwingAngles(&v42->yawAngle, p_yawing, v4, 0.0, 150.0,
                     *(float *)(v41 + 8));
      goto LABEL_10;
    }
    if ((v7 & 8) != 0) {
      a3->legs.yawing = 0;
      a3->legs.yawAngle = v54;
      p_legs = (int *)&a3->legs;
      goto LABEL_10;
    }
  legsAnim = a2->legsAnim;
  BYTE1(legsAnim) &= ~2u;
    if ((*(_BYTE *)(bgs + 96 * legsAnim + 80) & 0x30) != 0) {
      a3->legs.yawing = 0;
      p_legs = (int *)&a3->legs;
      BG_SwingAngles(&a3->legs.yawAngle, &a3->legs.yawing, v55, 0.0, 150.0,
                     *(float *)(bg_swingSpeed + 8));
    LABEL_10:
      v8 = a2;
      v9 = a2->eFlags;
      if ((v9 & 0x300) == 0)
        goto LABEL_11;
    LABEL_54:
      *(float *)a3->torso = v55;
      a3->legs.yawAngle = v55;
      v9 = v8->eFlags;
      goto LABEL_13;
    }
    if (a3->legs.yawing) {
      p_yawing = &a3->legs.yawing;
      v42 = &a3->legs;
      p_legs = (int *)&a3->legs;
      v41 = bg_swingSpeed;
      goto LABEL_76;
    }
  p_legs = (int *)&a3->legs;
  BG_SwingAngles(&a3->legs.yawAngle, &a3->legs.yawing, v4, 40.0, 150.0,
                 *(float *)(bg_swingSpeed + 8));
  v8 = a2;
  v9 = a2->eFlags;
  if ((v9 & 0x300) != 0)
    goto LABEL_54;
LABEL_11:
    if ((LODWORD(a3->clientConditions[2][0]) & 0xC0000) != 0) {
      *(float *)a3->torso = v54;
      a3->legs.yawAngle = v54;
      v9 = a2->eFlags;
    }
LABEL_13:
    if ((v9 & 0x20000) != 0 || (v9 & 0x300) != 0 ||
        (LODWORD(a3->clientConditions[2][0]) & 0xC0000) != 0 || v9 == 0x4000) {
      v10 = 0.0;
    }
    else {
      v45 = v53;
      if (v53 > 180.0)
        v45 = v53 - 360.0;
      v10 = v45 * 0.60000002;
    }
  BG_SwingAngles((float *)&a3->torso[8], &a3->torso[12], v10, 0.0, 45.0,
                 0.15000001);
  WeaponDef = BG_GetWeaponDef(a2->weapon);
  v12 = *(_DWORD *)(WeaponDef + 116);
  clientNum = a2->clientNum;
    if (animConditionsTable[0]) {
      *(_DWORD *)(bgs + 1208 * clientNum + 737368) = v12;
    }
    else {
      *(_DWORD *)(bgs + 1208 * clientNum + 737368) = 0;
      *(_DWORD *)(bgs + 1208 * clientNum + 737372) = 0;
      *(_DWORD *)(1208 * clientNum + bgs + 737368 + 4 * (v12 >> 5)) |=
          1 << (v12 & 0x1F);
    }
  v14 = *(_DWORD *)(WeaponDef + 124);
  v15 = a2->clientNum;
    if (!dword_312F68) {
      *(_DWORD *)((char *)&loc_B4060 + 1208 * v15 + bgs) = 0;
      *(_DWORD *)(bgs + 1208 * v15 + 737380) = 0;
      *(_DWORD *)((char *)&loc_B4060 + 1208 * v15 + 4 * (v14 >> 5) + bgs) |=
          1 << (v14 & 0x1F);
      v16 = a2;
      if ((a2->eFlags & 0x40000) != 0)
        goto LABEL_21;
    LABEL_71:
      v39 = v16->clientNum;
        if (dword_312F98) {
          *(_DWORD *)(bgs + 1208 * v39 + 737424) = 0;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v39 + 737424) = 0;
          *(_DWORD *)(bgs + 1208 * v39 + 737428) = 0;
          *(_DWORD *)(1208 * v39 + bgs + 737424) |= 1u;
        }
      goto LABEL_23;
    }
  *(_DWORD *)((char *)&loc_B4060 + 1208 * v15 + bgs) = v14;
  v16 = a2;
  if ((a2->eFlags & 0x40000) == 0)
    goto LABEL_71;
LABEL_21:
  v17 = v16->clientNum;
    if (dword_312F98) {
      *(_DWORD *)(bgs + 1208 * v17 + 737424) = 1;
    }
    else {
      *(_DWORD *)(bgs + 1208 * v17 + 737424) = 0;
      *(_DWORD *)(bgs + 1208 * v17 + 737428) = 0;
      *(_DWORD *)(1208 * v17 + bgs + 737424) |= 2u;
    }
LABEL_23:
    if ((a2->eFlags & 0x300) != 0) {
      v18 = a2->clientNum;
        if (dword_312F70) {
          *(_DWORD *)(bgs + 1208 * v18 + 737384) = 1;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v18 + 737384) = 0;
          *(_DWORD *)(bgs + 1208 * v18 + 737388) = 0;
          *(_DWORD *)(1208 * v18 + bgs + 737384) |= 2u;
        }
    }
    else {
      v37 = a2->clientNum;
        if (dword_312F70) {
          *(_DWORD *)(bgs + 1208 * v37 + 737384) = 0;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v37 + 737384) = 0;
          *(_DWORD *)(bgs + 1208 * v37 + 737388) = 0;
          *(_DWORD *)(1208 * v37 + bgs + 737384) |= 1u;
        }
    }
  v19 = a3->playerAngles[0] > 0.0;
  v20 = a2->clientNum;
    if (dword_312F80) {
      *(_DWORD *)(bgs + 1208 * v20 + 737400) = v19;
    }
    else {
      *(_DWORD *)(bgs + 1208 * v20 + 737400) = 0;
      *(_DWORD *)(bgs + 1208 * v20 + 737404) = 0;
      *(_DWORD *)(1208 * v20 + bgs + 737400) |= 1 << v19;
    }
    if ((a2->eFlags & 4) != 0) {
      v21 = a2->clientNum;
        if (dword_312F88) {
          *(_DWORD *)(bgs + 1208 * v21 + 737408) = 1;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v21 + 737408) = 0;
          *(_DWORD *)((char *)&loc_B4084 + 1208 * v21 + bgs) = 0;
          *(_DWORD *)(1208 * v21 + bgs + 737408) |= 2u;
        }
    }
    else {
      v38 = a2->clientNum;
        if (dword_312F88) {
          *(_DWORD *)(bgs + 1208 * v38 + 737408) = 0;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v38 + 737408) = 0;
          *(_DWORD *)((char *)&loc_B4084 + 1208 * v38 + bgs) = 0;
          *(_DWORD *)(1208 * v38 + bgs + 737408) |= 1u;
        }
    }
    if ((a2->eFlags & 0x40) != 0) {
      v22 = a2->clientNum;
        if (dword_312F90) {
          *(_DWORD *)(bgs + 1208 * v22 + 737416) = 1;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v22 + 737416) = 0;
          *(_DWORD *)(bgs + 1208 * v22 + 737420) = 0;
          *(_DWORD *)(1208 * v22 + bgs + 737416) |= 2u;
        }
    }
    else {
      v36 = a2->clientNum;
        if (dword_312F90) {
          *(_DWORD *)(bgs + 1208 * v36 + 737416) = 0;
        }
        else {
          *(_DWORD *)(bgs + 1208 * v36 + 737416) = 0;
          *(_DWORD *)(bgs + 1208 * v36 + 737420) = 0;
          *(_DWORD *)(1208 * v36 + bgs + 737416) |= 1u;
        }
    }
  v23 = a2->legsAnim & 0xFFFFFDFF;
  v49 = bgs;
  v24 = bgs;
  if (!*(_QWORD *)(96 * v23 + bgs + 84))
    goto LABEL_37;
    if (LODWORD(a3->clientConditions[2][0]) !=
        *(_QWORD *)(96 * v23 + bgs + 84)) {
      *(_DWORD *)((char *)&loc_B4070 + 1208 * a2->clientNum + bgs) =
          *(_DWORD *)(96 * v23 + bgs + 84);
      v24 = bgs;
      v49 = bgs;
    LABEL_37:
      v25 = v24;
      goto LABEL_38;
    }
  v25 = bgs;
LABEL_38:
  v26 = *(_DWORD *)(96 * v23 + v25 + 80);
    if ((v26 & 0x10) != 0) {
      v27 = a2->clientNum;
        if (dword_312FA0) {
          *(_DWORD *)((char *)&loc_B4098 + 1208 * v27 + v49) = 1;
        }
        else {
          v28 = 1208 * v27;
          *(_DWORD *)((char *)&loc_B4098 + v28 + v49) = 0;
          *(_DWORD *)(bgs + 1208 * v27 + 737436) = 0;
          *(_DWORD *)((char *)&loc_B4098 + v28 + bgs) |= 2u;
        }
      goto LABEL_41;
    }
    if ((v26 & 0x20) == 0) {
      v43 = a2->clientNum;
        if (dword_312FA0) {
          *(_DWORD *)((char *)&loc_B4098 + 1208 * v43 + v49) = 0;
        }
        else {
          v46 = 1208 * v43;
          *(_DWORD *)((char *)&loc_B4098 + v46 + v49) = 0;
          *(_DWORD *)(bgs + 1208 * v43 + 737436) = 0;
          *(_DWORD *)((char *)&loc_B4098 + v46 + bgs) |= 1u;
        }
    LABEL_41:
      pXAnimTree = (const XAnimTree_s *)a3->pXAnimTree;
      v30 = p_legs[4];
      if (!v30)
        goto LABEL_42;
      goto LABEL_60;
    }
  v35 = a2->clientNum;
    if (!dword_312FA0) {
      v44 = 1208 * v35;
      *(_DWORD *)((char *)&loc_B4098 + v44 + v49) = 0;
      *(_DWORD *)(bgs + 1208 * v35 + 737436) = 0;
      *(_DWORD *)((char *)&loc_B4098 + v44 + bgs) |= 4u;
      goto LABEL_41;
    }
  *(_DWORD *)((char *)&loc_B4098 + 1208 * v35 + v49) = 2;
  pXAnimTree = (const XAnimTree_s *)a3->pXAnimTree;
  v30 = p_legs[4];
  if (!v30)
    goto LABEL_42;
LABEL_60:
  BYTE1(v30) &= ~2u;
  Weight = XAnimGetWeight(pXAnimTree, v30);
    if (Weight != 0.0) {
    LABEL_42:
      v31 = *(_DWORD *)&a3->torso[16];
      if (!v31)
        goto LABEL_43;
      goto LABEL_62;
    }
  p_legs[4] = 0;
  p_legs[5] = 0;
  p_legs[6] = 150;
  v31 = *(_DWORD *)&a3->torso[16];
  if (!v31)
    goto LABEL_43;
LABEL_62:
  BYTE1(v31) &= ~2u;
  v52 = XAnimGetWeight(pXAnimTree, v31);
    if (v52 == 0.0) {
      *(_DWORD *)&a3->torso[16] = 0;
      *(_DWORD *)&a3->torso[20] = 0;
      *(_DWORD *)&a3->torso[24] = 150;
    }
LABEL_43:
    if (a3->leftHandGun && (*(_DWORD *)&a3->torso[16] & 0xFFFFFDFF) == 0) {
      a3->leftHandGun = 0;
      a3->dobjDirty = 1;
    }
  BG_RunLerpFrameRate((int *)a3->infoValid, p_legs, a2->legsAnim,
                      (clientInfo_t *)a2);
  return BG_RunLerpFrameRate((int *)a3->infoValid, (int *)a3->torso,
                             a2->torsoAnim, (clientInfo_t *)a2);
}

// 312D00: using guessed type int bgs;
// 312F60: using guessed type int animConditionsTable[];
// 312F68: using guessed type int dword_312F68;
// 312F70: using guessed type int dword_312F70;
// 312F80: using guessed type int dword_312F80;
// 312F88: using guessed type int dword_312F88;
// 312F90: using guessed type int dword_312F90;
// 312F98: using guessed type int dword_312F98;
// 312FA0: using guessed type int dword_312FA0;
// 1007D70: using guessed type int bg_swingSpeed;

//----- (00182B8A) --------------------------------------------------------
int __usercall BG_AnimationIndexForString
    @<eax>(long double a1 @<st0>, float a2 @<xmm0>, __m128 a3 @<xmm1>,
           __m128 a4 @<xmm2>, __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
           __m128 a7 @<xmm6>, char *__src)
{
  char v8;     // al
  int v9;      // edi
  int v10;     // edx
  int v11;     // ebx
  _DWORD *v12; // eax
  int v13;     // esi
  int v14;     // ebx
  int v17;     // ebx
  char v18;    // al
  int v19;     // edi
  char *v20;   // eax
  char *v21;   // ebx
  int v22;     // ebx

    if (g_pLoadAnims) {
      v8 = *__src;
      if (!*__src)
        goto LABEL_3;
      v9 = 0;
      v17 = 119;
        do {
          v9 += v17 * (char)__tolower(v8);
          v8 = __src[v17++ - 118];
        }
      while (v8);
      if (v9 == -1)
      LABEL_3:
        v9 = 0;
      v10 = g_pLoadAnims;
      v11 = g_pLoadAnims;
      v12 = (_DWORD *)g_piNumLoadAnims;
        if (*(int *)g_piNumLoadAnims > 0) {
          v13 = 0;
            do {
                while (v9 != *(_DWORD *)(v11 + 4)) {
                  ++v13;
                  v11 += 72;
                  if (v13 >= *v12)
                    goto LABEL_10;
                }
              if (!I_stricmp(__src, (char *)(v11 + 8)))
                return v13;
              v12 = (_DWORD *)g_piNumLoadAnims;
              ++v13;
              v11 += 72;
            }
          while (v13 < *(_DWORD *)g_piNumLoadAnims);
        LABEL_10:
          v10 = g_pLoadAnims;
        }
      v14 = v10 + 72 * *v12;
      Scr_FindAnim(a1, a2, a3, a4, a5, a6, a7, "multiplayer", __src,
                   (scr_anim_s *)v14, *(_DWORD *)(bgs + 736232));
      strcpy((char *)(v14 + 8), __src);
      *(_DWORD *)(v14 + 4) = v9;
      return (*(_DWORD *)g_piNumLoadAnims)++;
    }
  v18 = *__src;
  if (!*__src)
    goto LABEL_18;
  v19 = 0;
  v22 = 119;
    do {
      v19 += v22 * (char)__tolower(v18);
      v18 = __src[v22++ - 118];
    }
  while (v18);
  if (v19 == -1)
  LABEL_18:
    v19 = 0;
  v20 = globalScriptData;
  v21 = globalScriptData;
    if (*((int *)globalScriptData + 12288) > 0) {
      v13 = 0;
        do {
            while (v19 != *((_DWORD *)v21 + 19)) {
              ++v13;
              v21 += 96;
              if (v13 >= *((_DWORD *)v20 + 12288))
                goto LABEL_25;
            }
          if (!I_stricmp(__src, v21))
            return v13;
          v20 = globalScriptData;
          ++v13;
          v21 += 96;
        }
      while (v13 < *((_DWORD *)globalScriptData + 12288));
    }
LABEL_25:
  BG_AnimParseError(a1, a2, a3, a4, a5, a6, a7,
                    "BG_AnimationIndexForString: unknown player animation '%s'",
                    __src);
  return -1;
}

// 312D00: using guessed type int bgs;
// F16780: using guessed type int g_piNumLoadAnims;
// F16784: using guessed type int g_pLoadAnims;

//----- (00182D4E) --------------------------------------------------------
int __usercall BG_IndexForString
    @<eax>(long double a1 @<st0>, float a2 @<xmm0>, __m128 a3 @<xmm1>,
           __m128 a4 @<xmm2>, __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
           __m128 a7 @<xmm6>, char *a8, animStringItem_t *a9, int a10)
{
  animStringItem_t *v10; // edi
  char v11;              // al
  char *v12;             // esi
  char v13;              // al
  int v15;               // ebx
  int v16;               // ebx
  int v17;               // [esp+1Ch] [ebp-2Ch]
  int v18;               // [esp+20h] [ebp-28h]
  int32_t v19;           // [esp+24h] [ebp-24h]
  animStringItem_t *v20; // [esp+28h] [ebp-20h]
  int32_t *p_hash;       // [esp+2Ch] [ebp-1Ch]

  v10 = a9;
  v11 = *a8;
  if (!*a8)
    goto LABEL_2;
  v18 = 0;
  v16 = 119;
    do {
      v18 += v16 * (char)__tolower(v11);
      v11 = a8[v16++ - 118];
    }
  while (v11);
  if (v18 == -1)
  LABEL_2:
    v18 = 0;
  v12 = *(char **)a9->string;
    if (*(_DWORD *)a9->string) {
      v20 = a9 + 1;
      v17 = 0;
        do {
          p_hash = &v10->hash;
            if (v10->hash == -1) {
              v13 = *v12;
              if (!*v12)
                goto LABEL_9;
              v19 = 0;
              v15 = 119;
                do {
                  v19 += v15 * (char)__tolower(v13);
                  v13 = v12[v15++ - 118];
                }
              while (v13);
              if (v19 == -1)
              LABEL_9:
                v19 = 0;
              *p_hash = v19;
              if (v18 != *p_hash)
                goto LABEL_6;
            }
            else if (v18 != v10->hash) {
              goto LABEL_6;
            }
          if (!I_stricmp(a8, *(char **)v10->string))
            return v17;
        LABEL_6:
          ++v10;
          ++v17;
          v12 = *(char **)v20->string;
          ++v20;
        }
      while (v12);
    }
  if (!a10)
    BG_AnimParseError(a1, a2, a3, a4, a5, a6, a7,
                      "BG_IndexForString: unknown token '%s'", a8);
  return -1;
}

//----- (00182E9E) --------------------------------------------------------
int __usercall BG_ParseConditionBits
    @<eax>(char **a1 @<eax>, animStringItem_t *a2 @<edx>, int a3 @<ecx>,
           long double a4 @<st0>, float a5 @<xmm0>, __m128 a6 @<xmm1>,
           __m128 a7 @<xmm2>, __m128 a8 @<xmm3>, __m128 a9 @<xmm4>,
           __m128 a10 @<xmm6>, const char **a11)
{
  char *v11;        // eax
  char *v12;        // ebx
  int v13;          // esi
  int result;       // eax
  bool v15;         // zf
  int v16;          // eax
  int v17;          // eax
  unsigned int v18; // kr04_4
  int v19;          // eax
  int v23;          // [esp+1Ch] [ebp-6Ch]
  char v24[64];     // [esp+28h] [ebp-60h] BYREF
  int v25;          // [esp+68h] [ebp-20h]
  int v26;          // [esp+6Ch] [ebp-1Ch]

  v24[0] = 0;
  *a11 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
LABEL_2:
  v11 = Com_ParseOnLine(a1);
  v12 = v11;
  if (!v11)
    goto LABEL_11;
LABEL_3:
    if (*v11) {
      v13 = 0;
      goto LABEL_5;
    }
LABEL_11:
    while (1) {
      result = Com_UngetToken();
      if (!v24[0])
        return result;
      v13 = 1;
    LABEL_5:
      if (!I_stricmp(v12, ","))
        v13 = 1;
      result = I_stricmp(v12, "none");
        if (result) {
            if (!I_stricmp(v12, "none,")) {
              result = (int)a11;
              *a11 = (const char *)((unsigned int)*a11 | 1);
              return result;
            }
          if (!I_stricmp(v12, "NOT"))
            v12 = "MINUS";
            if (!v13) {
                if (I_stricmp(v12, "AND") && I_stricmp(v12, "MINUS")) {
                  v18 = strlen(v12) + 1;
                    if (v12[v18 - 2] == 44) {
                      v12[v18 - 2] = 0;
                      LOWORD(v13) = 1;
                    }
                  if (v24[0])
                    I_strncat(v24, 64, " ");
                  I_strncat(v24, 64, v12);
                }
                else {
                  v13 = 0;
                }
            }
          if (I_stricmp(v12, "AND") && I_stricmp(v12, "MINUS") && !v13)
            goto LABEL_2;
          if (v24[0])
            goto LABEL_25;
            if (v13) {
              BG_AnimParseError(
                  a4, a5, a6, a7, a8, a9, a10,
                  "BG_ParseConditionBits: unexpected end of condition");
              if (!I_stricmp(v24, "all"))
                goto LABEL_26;
            }
            else {
                if (!I_stricmp(v12, "MINUS")) {
                  v23 = 1;
                  goto LABEL_2;
                }
              BG_AnimParseError(a4, a5, a6, a7, a8, a9, a10,
                                "BG_ParseConditionBits: unexpected '%s'", v12);
            LABEL_25:
                if (!I_stricmp(v24, "all")) {
                LABEL_26:
                  v25 = -1;
                  v26 = -1;
                  goto LABEL_27;
                }
            }
          v16 =
              BG_IndexForString(a4, a5, a6, a7, a8, a9, a10, v24,
                                (animStringItem_t *)((a3 << 7) + 15819520), 1);
            if (v16 < 0) {
              v19 = BG_IndexForString(a4, a5, a6, a7, a8, a9, a10, v24, a2, 0);
              *(&v25 + (v19 >> 5)) |= 1 << (v19 & 0x1F);
            }
            else {
              v17 = v16 + 16 * a3;
              v25 = (int)(&defineBits)[2 * v17];
              v26 = dword_F13304[2 * v17];
            }
        LABEL_27:
            if (v23) {
              *a11 = (const char *)(~v25 & (unsigned int)*a11);
              a11[1] = (const char *)(~v26 & (unsigned int)a11[1]);
            }
            else {
              *a11 = (const char *)(v25 | (unsigned int)*a11);
              a11[1] = (const char *)(v26 | (unsigned int)a11[1]);
            }
          v24[0] = 0;
          v15 = I_stricmp(v12, "MINUS") == 0;
          result = 1;
          if (!v15)
            result = v23;
          v23 = result;
          goto LABEL_9;
        }
      *a11 = (const char *)((unsigned int)*a11 | 1);
    LABEL_9:
      if (v13)
        return result;
      v11 = Com_ParseOnLine(a1);
      v12 = v11;
      if (v11)
        goto LABEL_3;
    }
}

// F13304: using guessed type int dword_F13304[287];

//----- (001831BA) --------------------------------------------------------
int __usercall BG_ParseConditions
    @<eax>(char **a1 @<eax>, _DWORD *a2 @<edx>, long double a3 @<st0>,
           float a4 @<xmm0>, __m128 a5 @<xmm1>, __m128 a6 @<xmm2>,
           __m128 a7 @<xmm3>, __m128 a8 @<xmm4>, __m128 a9 @<xmm6>)
{
  char *v10;        // eax
  char *v11;        // edi
  int v12;          // esi
  int v13;          // eax
  char *v14;        // eax
  unsigned int v15; // eax
  char *v16;        // edx
  char **v18;       // [esp+18h] [ebp-30h]
  char *v19;        // [esp+1Ch] [ebp-2Ch]
  char *v20;        // [esp+28h] [ebp-20h] BYREF
  int v21;          // [esp+2Ch] [ebp-1Ch]

  v18 = a1;
  v20 = 0;
  v21 = 0;
    while (1) {
      v10 = Com_ParseOnLine(a1);
      v11 = v10;
      if (!v10 || !*v10)
        break;
      if (!I_stricmp(v10, "default"))
        return 1;
      v12 = BG_IndexForString(a3, a4, a5, a6, a7, a8, a9, v11,
                              &animConditionsStr, 0);
      v13 = animConditionsTable[2 * v12];
        if (!v13) {
          BG_ParseConditionBits(v18, (&off_312F64)[2 * v12], v12, a3, a4, a5,
                                a6, a7, a8, a9, (const char **)&v20);
          goto LABEL_3;
        }
      if (v13 != 1)
        goto LABEL_3;
        if ((&off_312F64)[2 * v12]) {
          v14 = Com_ParseOnLine(v18);
          v19 = v14;
            if (v14 && *v14) {
              v15 = strlen(v14);
              v16 = v19;
                if (v19[v15 - 1] != 44) {
                LABEL_13:
                  v20 =
                      (char *)BG_IndexForString(a3, a4, a5, a6, a7, a8, a9, v19,
                                                (&off_312F64)[2 * v12], 0);
                  goto LABEL_3;
                }
            }
            else {
              BG_AnimParseError(a3, a4, a5, a6, a7, a8, a9,
                                "BG_ParseConditions: expected condition value, "
                                "found end of line");
              v15 = strlen(v19);
              v16 = v19;
              if (v19[v15 - 1] != 44)
                goto LABEL_13;
            }
          v16[v15 - 1] = 0;
          goto LABEL_13;
        }
      v20 = (char *)1;
    LABEL_3:
      a2[3 * *a2 + 1] = v12;
      a2[3 * *a2 + 2] = v20;
      a2[3 * (*a2)++ + 3] = v21;
      a1 = v18;
    }
  if (!*a2)
    BG_AnimParseError(a3, a4, a5, a6, a7, a8, a9,
                      "BG_ParseConditions: no conditions found");
  return 1;
}

// 312F60: using guessed type int animConditionsTable[];

//----- (00183342) --------------------------------------------------------
char *__usercall BG_ParseCommands
    @<eax>(long double a1 @<st0>, float a2 @<xmm0>, __m128 a3 @<xmm1>,
           __m128 a4 @<xmm2>, __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
           __m128 a7 @<xmm6>, char **a8, animScriptItem_t *a9,
           animScriptData_t *a10)
{
  char *result;          // eax
  char *v11;             // ebx
  __int16 v12;           // ax
  char *v13;             // eax
  char *v14;             // ebx
  __int16 v15;           // ax
  uint8_t *v16;          // edx
  char *v17;             // eax
  char *v18;             // ebx
  char *v19;             // eax
  const char *v20;       // ebx
  char *v21;             // eax
  const char *v22;       // ebx
  char *v23;             // eax
  const char *v24;       // ebx
  char *v25;             // eax
  const char *v26;       // edi
  int v27;               // ebx
  int v28;               // eax
  int v29;               // edi
  int v30;               // ecx
  animScriptItem_t *v31; // edx
  int v32;               // ecx
  int v33;               // eax
  int v34;               // eax
  int v35;               // eax
  int v36;               // eax
  int v37;               // eax
  int v38;               // eax
  char *v39;             // eax
  char *v40;             // [esp+28h] [ebp-20h]
  int v41;               // [esp+2Ch] [ebp-1Ch]

  v40 = 0;
  v41 = 0;
LABEL_2:
  result = Com_Parse(a8);
  v11 = result;
    if (result) {
        while (1) {
          if (!*v11)
            return result;
            if (!I_stricmp(v11, "}")) {
              result = 0;
              *a8 -= strlen(v11);
              return result;
            }
            if (!v41) {
              if (*(int *)a9->numCommands > 7)
                BG_AnimParseError(a1, a2, a3, a4, a5, a6, a7,
                                  "BG_ParseCommands: exceeded maximum number "
                                  "of animations (%i)",
                                  8);
              v40 = &a9->commands[16 * (*(_DWORD *)a9->numCommands)++];
              *(_DWORD *)v40 = 0;
            }
          v12 = BG_IndexForString(a1, a2, a3, a4, a5, a6, a7, v11,
                                  &animBodyPartsStr, 1);
          *(_WORD *)&v40[2 * v41] = v12;
            if (v12 <= 0) {
              *a8 -= strlen(v11);
            LABEL_23:
              v21 = Com_ParseOnLine(a8);
              v22 = v21;
                if (v21) {
                    while (*v21) {
                        if (I_stricmp(v21, "sound")) {
                          BG_AnimParseError(
                              a1, a2, a3, a4, a5, a6, a7,
                              "BG_ParseCommands: unknown parameter '%s'", v22);
                          goto LABEL_23;
                        }
                      v23 = Com_ParseOnLine(a8);
                      v24 = v23;
                      if (!v23 || !*v23)
                        BG_AnimParseError(a1, a2, a3, a4, a5, a6, a7,
                                          "BG_ParseCommands: expected sound");
                      if (strstr(v24, ".wav"))
                        BG_AnimParseError(
                            a1, a2, a3, a4, a5, a6, a7,
                            "BG_ParseCommands: wav files not supported, "
                            "only sound scripts");
                      *((_DWORD *)v40 + 3) = (*(int(__cdecl **)(const char *))(
                          (char *)&loc_B3BC0 + (_DWORD)globalScriptData))(v24);
                      v21 = Com_ParseOnLine(a8);
                      v22 = v21;
                      if (!v21)
                        break;
                    }
                }
              v41 = 0;
              result = Com_Parse(a8);
              v11 = result;
              if (!result)
                return result;
            }
            else {
              v13 = Com_ParseOnLine(a8);
              v14 = v13;
              if (!v13 || !*v13)
                BG_AnimParseError(a1, a2, a3, a4, a5, a6, a7,
                                  "BG_ParseCommands: expected animation");
              v15 = BG_AnimationIndexForString(a1, a2, a3, a4, a5, a6, a7, v14);
              *(_WORD *)&v40[2 * v41 + 4] = v15;
              v16 = &a10->animations[96 * v15];
              *(_WORD *)&v40[2 * v41 + 8] = *((_DWORD *)v16 + 18);
                if (!g_pLoadAnims) {
                  v29 = parseMovetype;
                    if (parseMovetype && *(_WORD *)&v40[2 * v41] != 2) {
                      v30 = *((_DWORD *)v16 + 22) |
                            (((parseMovetype & 0x20) != 0) << parseMovetype);
                      *((_DWORD *)v16 + 21) |= ((parseMovetype & 0x20) == 0)
                                               << parseMovetype;
                      *((_DWORD *)v16 + 22) = v30;
                        if ((unsigned int)(v29 - 18) <= 1) {
                          v39 =
                              (char *)a10 + 96 * *(__int16 *)&v40[2 * v41 + 4];
                          a2 = 0.0;
                          if (*((float *)v39 + 17) != 0.0)
                            *((_DWORD *)v39 + 20) |= 2u;
                        }
                        if ((int)a9->numConditions > 0) {
                          v31 = a9;
                            if (*(_DWORD *)a9->conditions == 8) {
                              v34 = *(_DWORD *)&a9->conditions[4];
                                if (v34 == 1) {
                                LABEL_69:
                                  v38 = 96 * *(__int16 *)&v40[2 * v41 + 4];
                                  *(_DWORD *)&a10->animations[v38 + 80] |=
                                      0x10u;
                                }
                                else {
                                LABEL_56:
                                    if (v34 == 2) {
                                      v35 = 96 * *(__int16 *)&v40[2 * v41 + 4];
                                      *(_DWORD *)&a10->animations[v35 + 80] |=
                                          0x20u;
                                    }
                                }
                            }
                            else {
                              v32 = 0;
                                while (++v32 != a9->numConditions) {
                                  v33 = *(_DWORD *)&v31->conditions[12];
                                  v31 = (animScriptItem_t *)((char *)v31 + 12);
                                    if (v33 == 8) {
                                      v34 = *(_DWORD *)&a9
                                                 ->conditions[12 * v32 + 4];
                                      if (v34 == 1)
                                        goto LABEL_69;
                                      goto LABEL_56;
                                    }
                                }
                            }
                        }
                    }
                    if (parseEvent == 2) {
                      v36 = 96 * *(__int16 *)&v40[2 * v41 + 4];
                      *(_DWORD *)&a10->animations[v36 + 80] |= 8u;
                      *(_DWORD *)&a10
                           ->animations[96 * *(__int16 *)&v40[2 * v41 + 4] +
                                        64] = 30;
                    }
                    else if (parseEvent == 1) {
                      *(_DWORD *)&a10
                           ->animations[96 * *(__int16 *)&v40[2 * v41 + 4] +
                                        68] = 0;
                      v37 = 96 * *(__int16 *)&v40[2 * v41 + 4];
                      *(_DWORD *)&a10->animations[v37 + 80] |= 0x40u;
                    }
                    else if (parseEvent == 10 ||
                             (unsigned int)(v29 - 21) <= 9) {
                      *(_DWORD *)&a10
                           ->animations[96 * *(__int16 *)&v40[2 * v41 + 4] +
                                        68] = 0;
                    }
                }
            LABEL_14:
              v17 = Com_ParseOnLine(a8);
              v18 = v17;
                if (v17) {
                    while (*v17) {
                        if (I_stricmp(v17, "duration")) {
                            if (I_stricmp(v18, "turretanim")) {
                              if (I_stricmp(v18, "blendtime"))
                                break;
                              v25 = Com_ParseOnLine(a8);
                              v26 = v25;
                              if (!v25 || !*v25)
                                BG_AnimParseError(a1, a2, a3, a4, a5, a6, a7,
                                                  "BG_ParseCommands: expected "
                                                  "blendtime value");
                                if (!g_pLoadAnims) {
                                  v27 = *(__int16 *)&v40[2 * v41 + 4];
                                  *(_DWORD *)&a10->animations[96 * v27 + 64] =
                                      atoi(v26);
                                }
                            }
                            else {
                                if (!g_pLoadAnims) {
                                  v28 = 96 * *(__int16 *)&v40[2 * v41 + 4];
                                  *(_DWORD *)&a10->animations[v28 + 80] |= 4u;
                                }
                              if (*(_WORD *)&v40[2 * v41] != 3)
                                BG_AnimParseError(
                                    a1, a2, a3, a4, a5, a6, a7,
                                    "BG_ParseCommands: Turret animations can "
                                    "only be played on the 'both' body part");
                            }
                          goto LABEL_14;
                        }
                      v19 = Com_ParseOnLine(a8);
                      v20 = v19;
                      if (!v19 || !*v19)
                        BG_AnimParseError(
                            a1, a2, a3, a4, a5, a6, a7,
                            "BG_ParseCommands: expected duration value");
                      *(_WORD *)&v40[2 * v41 + 8] = atoi(v20);
                      v17 = Com_ParseOnLine(a8);
                      v18 = v17;
                      if (!v17)
                        break;
                    }
                }
              Com_UngetToken();
              if (*(_WORD *)&v40[2 * v41] == 3)
                goto LABEL_23;
              if (v41++ > 0)
                goto LABEL_23;
              if (v41 <= 0)
                goto LABEL_2;
              result = Com_ParseOnLine(a8);
              v11 = result;
              if (!result)
                return result;
            }
        }
    }
  return result;
}

void __cdecl UI_LoadArenas()
{
  int v0;              // ebx
  char *v1;            // eax
  int v2;              // ebx
  char *v3;            // eax
  int *v4;             // ebx
  char *v5;            // eax
  int *v6;             // ebx
  const gentity_s *v7; // eax
  char *v8;            // ebx
  char *v9;            // eax
  char *v10;           // eax
  char *v11;           // esi
  int v12;             // ebx
  int *v13;            // edi
  char *v14;           // esi
  unsigned int v15;    // kr04_4
  signed int v16;      // ebx
  int i;               // [esp+20h] [ebp-24B8h]
  int v18;             // [esp+24h] [ebp-24B4h]
  int FileList;        // [esp+28h] [ebp-24B0h]
  const char **v20;    // [esp+2Ch] [ebp-24ACh]
  char v21[8192];      // [esp+38h] [ebp-24A0h] BYREF
  char __dst[1024];    // [esp+2038h] [ebp-4A0h] BYREF
  char v23[128];       // [esp+2438h] [ebp-A0h] BYREF
  int v24;             // [esp+24B8h] [ebp-20h] BYREF
  char *v25;           // [esp+24BCh] [ebp-1Ch] BYREF

  ui_numArenas = 0;
  dword_1685E10 = 0;
  FileList = FS_GetFileList("mp", "arena", FS_LIST_PURE_ONLY, __dst, 1024);
    if (FileList > 0) {
      v14 = __dst;
        for (i = 0; i != FileList; ++i) {
          v15 = strlen(v14) + 1;
          sprintf(v23, "%s/%s", "mp", v14);
          v16 = FS_FOpenFileByMode(v23, &v24, FS_READ);
            if (v24) {
                if (v16 > 0x1FFF) {
                  Com_Printf("^1file too large: %s is %i, max allowed is %i",
                             v23, v16, 0x2000);
                  FS_FCloseFile(v24);
                }
                else {
                  FS_Read(v21, v16, v24);
                  v21[v16] = 0;
                  FS_FCloseFile(v24);
                  ui_numArenas += UI_ParseInfos(
                      v21, 64 - ui_numArenas, &(&ui_arenaInfos)[ui_numArenas]);
                }
            }
            else {
              Com_Printf("^1file not found: %s\n", v23);
            }
          v14 += v15;
        }
    }
    if (ui_numArenas > 0) {
      v18 = 0;
      v20 = (const char **)&ui_arenaInfos;
        do {
          v0 = dword_1685E10;
          v1 = (char *)Info_ValueForKey(*v20, "map");
          sharedUiInfo[41 * v0 + 1238] = (int)String_Alloc(v1);
          v2 = dword_1685E10;
          v3 = (char *)Info_ValueForKey(*v20, "longname");
          sharedUiInfo[41 * v2 + 1237] = (int)String_Alloc(v3);
          sharedUiInfo[41 * dword_1685E10 + 1243] = -1;
          sharedUiInfo[41 * dword_1685E10 + 1276] = 0;
          v4 = &sharedUiInfo[41 * dword_1685E10];
          v5 = va("loadscreen_%s", (const char *)v4[1238]);
          v4[1239] = (int)String_Alloc(v5);
          v6 = &sharedUiInfo[41 * dword_1685E10];
          v6[1276] = CL_RegisterMaterialNoMip((const char *)v6[1239], 3);
          v7 = Info_ValueForKey(*v20, "gametype");
          v8 = (char *)v7;
            if (v7 && LOBYTE(v7->s.number)) {
              sharedUiInfo[41 * dword_1685E10 + 1242] = 0;
              v9 = va(".arena files : %s",
                      (const char *)sharedUiInfo[41 * dword_1685E10 + 1238]);
              Com_BeginParseSession(v9);
              v25 = v8;
                while (1) {
                  v10 = Com_Parse(&v25);
                  v11 = v10;
                  if (!v10 || !*v10)
                    break;
                    if (dword_1685C08 > 0) {
                      v12 = 0;
                      v13 = sharedUiInfo;
                        do {
                          if (!I_stricmp(v11, (char *)v13[1107]))
                            sharedUiInfo[41 * dword_1685E10 + 1242] |= 1 << v12;
                          ++v12;
                          v13 += 2;
                        }
                      while (v12 < dword_1685C08);
                    }
                }
              Com_EndParseSession();
            }
            else {
              sharedUiInfo[41 * dword_1685E10 + 1242] = -1;
            }
          if (++dword_1685E10 > 127)
            break;
          ++v18;
          ++v20;
        }
      while (ui_numArenas > v18);
    }
}

void __cdecl UI_LoadArenasFromFile(char *)
{
  UNIMPLEMENTED();
}
