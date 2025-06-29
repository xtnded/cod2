int __cdecl UI_ClientIsInGame()
{
  return *(_DWORD *)clc == 8;
}

bool __cdecl IsPartyMemberReady(int)
{
  UNIMPLEMENTED();
}

unsigned __int64 __cdecl GetPartyMemberXuid(int)
{
  UNIMPLEMENTED();
}

char const *__cdecl GetPartyMemberName(int)
{
  UNIMPLEMENTED();
}

int __cdecl GetOurPartyMemberCount(void)
{
  UNIMPLEMENTED();
}

int __cdecl GetClientname(int index, char *buf, int size)
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

void __cdecl CLUI_GetCDKey(char *buf, int buflen, char *buf2, int buf2len)
{
  int result; // eax

  Dvar_RegisterString("fs_game", (DvarValue)&inData, 0x101Cu);
  strcpy(a1, "                ");
  result = *(_DWORD *)cl_cdkeychecksum;
  strcpy(a3, "    ");
  return result;
}

void __cdecl Key_SetCatcher(int catcher)
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

int __cdecl Key_GetCatcher()
{
  return *((_DWORD *)cl + 1);
}

int __cdecl LAN_ServerIsDirty(int source, int n)
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

void __cdecl LAN_CleanHostname(char const *, char *)
{
  UNIMPLEMENTED();
}

struct serverInfo_t *__cdecl LAN_GetServerPtr(int, int)
{
  UNIMPLEMENTED();
}

int __cdecl LAN_GetServerPing(int source, int n)
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

int __cdecl LAN_WaitServerResponse(int source)
{
  if (a1 == 1)
    return unk_1224E9C;
  else
    return 0;
}

int __cdecl LAN_GetServerCount(int source)
{
  if (a1 == 1)
    return dword_1224EA0;
  if (a1 == 2)
    return dword_14BCFA4;
  if (a1)
    return 0;
  return dword_1220A98;
}

void __cdecl LAN_ResetPings(int)
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

void __cdecl GetClientState(struct uiClientState_t *state)
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

void __cdecl Key_GetBindingBuf(int keynum, char *buf, int buflen)
{
  char *result; // eax

  result = (char *)Key_GetBinding(a1);
  if (result)
    return I_strncpyz(a2, result, a3);
  *a2 = 0;
  return result;
}

void __cdecl LAN_GetServerInfo(int source, int n, char *buf, int buflen)
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

bool __cdecl IsPartyMemberMuted(int)
{
  UNIMPLEMENTED();
}

void __cdecl Key_KeynumToStringBuf(int keynum, char *buf, int buflen)
{
  char *v3; // eax

  v3 = (char *)Key_KeynumToString(a1, 1);
  return I_strncpyz(a2, v3, a3);
}

int __cdecl LAN_CompareHostname(char const *hostName1, char const *hostName2)
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

bool __cdecl IsPartyMemberTalking(int)
{
  UNIMPLEMENTED();
}

int __cdecl LAN_CompareServers(int source, int sortKey, int sortDir, int s1,
                               int s2)
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

int __cdecl UI_checkKeyExec(int key)
{
  if (dword_1220A70)
    return UI_CheckExecKey(a1);
  else
    return 0;
}

void __cdecl LAN_MarkServerDirty(int source, int n, int dirty)
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

int __cdecl CL_ShutdownUI()
{
  UNIMPLEMENTED();
}

void __cdecl CL_XenonHudIsOffscreen(void)
{
  UNIMPLEMENTED();
}

int __cdecl LAN_UpdateDirtyPings(int source)
{
  return CL_UpdateDirtyPings_f(a1);
}

int __cdecl UI_PlayLocalSoundAliasByName(char const *)
{
  return SND_PlayLocalSoundAliasByName(a1, 0);
}

int __cdecl UI_PlayLocalSoundAlias(struct snd_alias_list_t *aliasList)
{
  return SND_PlayLocalSoundAlias(a1, SASYS_UI);
}

void __cdecl CLUI_SetCDKey(char *buf, char *buf2)
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

void __cdecl CL_InitUI()
{
  dword_1220A70 = 1;
  CL_SwitchToLocalClient();
  UI_Init(a1, a2, a3, a4, a5, a6, a7);
  CL_SwitchToLocalClient();
  UI_Component_Init();
}

LAN_GetServerStatus(char *serverAddress, char *serverStatus, int maxLen)
{
  UNIMPLEMENTED();
}

UI_LoadSoundAliases()
{
  UNIMPLEMENTED();
}
