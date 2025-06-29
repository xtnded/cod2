void __cdecl WinInitControlfp(void) { UNIMPLEMENTED(); }

struct Font_s *__cdecl CL_RegisterFont(char const *fontName, int imageTrack) {
  return dword_121C780();
}

bool __cdecl CL_GetDisplayHUDWithKeycatchUI() {
  return (unsigned __int8)byte_1509C48;
}

int __cdecl CL_GetKeyCatchers() { return dword_1509C44; }

void __cdecl CL_DrawTextPhysicalWithCursor(char const *text, int maxChars,
                                           struct Font_s *font, float x,
                                           float y, float xScale, float yScale,
                                           float const *const color, int style,
                                           int cursorPos, char cursor) {
  return dword_121C7CC(a1, a2, a3, LODWORD(a4), LODWORD(a5), LODWORD(a6),
                       LODWORD(a7), a8, a9, a10, a11);
}

void __cdecl CL_DrawTextPhysical(char const *text, int maxChars,
                                 struct Font_s *font, float x, float y,
                                 float xScale, float yScale,
                                 float const *const color, int style) {
  return dword_121C7BC();
}

float __cdecl CL_NormalizedTextScale(struct Font_s *font, float scale) {
  dword_121C7B0(a1, LODWORD(a2));
}

int __cdecl CL_TextHeight(struct Font_s *font) { return dword_121C7B8(a1); }

int __cdecl CL_TextWidth(char const *text, int maxChars, struct Font_s *font) {
  return dword_121C7B4(a1, a2, a3);
}

void __cdecl CL_ShutdownDebugData() {
  int result; // eax

  if (dword_14C1408) {
    Z_FreeInternal((void *)dword_14C1408);
    dword_14C1408 = 0;
  }
  if (dword_14C140C) {
    Z_FreeInternal((void *)dword_14C140C);
    dword_14C140C = 0;
  }
  if (dword_14C1410) {
    Z_FreeInternal((void *)dword_14C1410);
    dword_14C1410 = 0;
  }
  if (dword_14C13F8) {
    Z_FreeInternal((void *)dword_14C13F8);
    dword_14C13F8 = 0;
  }
  if (dword_14C13FC) {
    Z_FreeInternal((void *)dword_14C13FC);
    dword_14C13FC = 0;
  }
  result = 0;
  memset(&dword_14C13F0, 0, 0x24u);
  if (dword_121C7A8)
    return dword_121C7A8();
  return result;
}

void __cdecl CL_UpdateDebugData() {
  int result; // eax

  result = dword_1220A68;
  if (dword_1220A68) {
    if (dword_14C13F8)
      result = dword_121C79C(dword_14C13F8, dword_14C13F4, dword_14C13F0);
    if (dword_14C1408)
      return dword_121C7A0(dword_14C1408, dword_14C1404, _size);
  }
  return result;
}

void __cdecl CL_FlushDebugData(int fromServer) {
  int result; // eax
  int v2;     // ebx
  int i;      // ecx
  int v4;     // esi
  int v5;     // ecx
  int v6;     // edx
  int v7;     // ebx
  int v8;     // ecx

  result = dword_1220A68;
  if (dword_1220A68) {
    if (dword_14C13F8) {
      v2 = 0;
      for (i = dword_14C13F4; v2 < i; i = dword_14C13F4) {
        while (a1 != *(unsigned __int8 *)(dword_14C13FC + v2)) {
          if (++v2 >= i)
            goto LABEL_7;
        }
        dword_14C13F4 = i - 1;
        *(_BYTE *)(v2 + dword_14C13FC) = *(_BYTE *)(dword_14C13FC + i - 1);
        memcpy((void *)(dword_14C13F8 + (v2 << 7)),
               (const void *)(dword_14C13F8 + (dword_14C13F4 << 7)), 0x80u);
      }
    LABEL_7:
      dword_121C79C(dword_14C13F8, i, dword_14C13F0);
    }
    result = dword_14C1408;
    if (!dword_14C1408)
      return result;
    v4 = 0;
    v5 = dword_14C1404;
    while (v4 < v5) {
      if (*(unsigned __int8 *)(dword_14C140C + v4) == a1) {
        --*(_DWORD *)(dword_14C1410 + 4 * v4);
        if (*(int *)(4 * v4 + dword_14C1410) <= 0) {
          --dword_14C1404;
          *(_BYTE *)(v4 + dword_14C140C) =
              *(_BYTE *)(dword_14C140C + dword_14C1404);
          *(_DWORD *)(4 * v4 + dword_14C1410) =
              *(_DWORD *)(dword_14C1410 + 4 * dword_14C1404);
          v6 = dword_14C1408;
          v7 = 44 * v4;
          v8 = 44 * dword_14C1404;
          *(_DWORD *)(v7 + dword_14C1408) =
              *(_DWORD *)(44 * dword_14C1404 + dword_14C1408);
          *(_DWORD *)(v7 + v6 + 4) = *(_DWORD *)(v8 + v6 + 4);
          *(_DWORD *)(v7 + v6 + 8) = *(_DWORD *)(v8 + v6 + 8);
          *(_DWORD *)(v7 + v6 + 12) = *(_DWORD *)(v8 + v6 + 12);
          *(_DWORD *)(v7 + v6 + 16) = *(_DWORD *)(v8 + v6 + 16);
          *(_DWORD *)(v7 + v6 + 20) = *(_DWORD *)(v8 + v6 + 20);
          *(_DWORD *)(v7 + v6 + 24) = *(_DWORD *)(v8 + v6 + 24);
          *(_DWORD *)(v7 + v6 + 28) = *(_DWORD *)(v8 + v6 + 28);
          *(_DWORD *)(v7 + v6 + 32) = *(_DWORD *)(v8 + v6 + 32);
          *(_DWORD *)(v7 + v6 + 36) = *(_DWORD *)(v8 + v6 + 36);
          *(_DWORD *)(v7 + v6 + 40) = *(_DWORD *)(v8 + v6 + 40);
          v5 = dword_14C1404;
          continue;
        }
        v5 = dword_14C1404;
        ++v4;
      } else {
        ++v4;
      }
    }
    return dword_121C7A0(dword_14C1408, v5, _size);
  }
  return result;
}

char const *__cdecl CL_GetServerIPAddress() { UNIMPLEMENTED(); }

int __cdecl CL_GetPingQueueCount(void) { UNIMPLEMENTED(); }

void __cdecl CL_ClearPing(int) { UNIMPLEMENTED(); }

void __cdecl CL_GetPingInfo(int, char *, int) { UNIMPLEMENTED(); }

void __cdecl CL_StopLogo() { clientConnections = 0; }

void __cdecl CL_DrawLogo() { UNIMPLEMENTED(); }

int __cdecl CL_ScaledMilliseconds() { return dword_1220A78; }

void __cdecl CL_ShutdownRef() {
  if (dword_121C7E8)
    dword_121C7E8();
  if (re) {
    re(1);
    memset(&re, 0, 0x160u);
  }
  return StatMon_Reset();
}

int __cdecl CL_IsClientActive(void) { UNIMPLEMENTED(); }

void __cdecl CL_RequestAuthorization() {
  dvar_s *v7;     // eax
  char *v8;       // eax
  int v9;         // ecx
  int v10;        // ebx
  int v11;        // edi
  char v12;       // dl
  char __dst[64]; // [esp+24h] [ebp-64h] BYREF
  int32_t type;   // [esp+64h] [ebp-24h]
  int32_t ip;     // [esp+68h] [ebp-20h]
  int v16;        // [esp+6Ch] [ebp-1Ch]

  if (!CL_CDKeyValidate(cl_cdkey, cl_cdkeychecksum)) {
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 1, "EXE_ERR_INVALID_CD_KEY");
    return;
  }
  if (stru_14C13AC.port) {
    if (stru_14C13AC.type == 1)
      return;
  LABEL_4:
    if ((unsigned __int8)Dvar_GetBool("fs_restrict")) {
      I_strncpyz(__dst, "demo", 64);
    LABEL_6:
      v7 = Dvar_RegisterBool("cl_anonymous", 0, 0x101Bu);
      v8 = va("getKeyAuthorize %i %s", (unsigned __int8)v7->current.enabled,
              __dst);
      type = stru_14C13AC.type;
      ip = stru_14C13AC.ip;
      v16 = *(_DWORD *)&stru_14C13AC.port;
      NET_OutOfBandPrint(NS_CLIENT1, stru_14C13AC, v8);
      return;
    }
    v9 = strlen(cl_cdkey);
    if (v9 > 32) {
      v9 = 32;
    } else if (v9 <= 0) {
      __dst[0] = 0;
      goto LABEL_6;
    }
    v10 = 0;
    v11 = 0;
    do {
      v12 = cl_cdkey[v10];
      if ((unsigned __int8)(v12 - 48) <= 9u ||
          (unsigned __int8)(v12 - 97) <= 0x19u ||
          (unsigned __int8)(v12 - 65) <= 0x19u) {
        __dst[v11++] = v12;
      }
      ++v10;
    } while (v9 != v10);
    __dst[v11] = 0;
    goto LABEL_6;
  }
  Com_Printf("Resolving %s\n", "cod2master.activision.com");
  if (!NET_StringToAdr("cod2master.activision.com", &stru_14C13AC)) {
    Com_Printf("Couldn't resolve address\n");
    return;
  }
  stru_14C13AC.port = -9136;
  Com_Printf("%s resolved to %i.%i.%i.%i:%i\n", "cod2master.activision.com",
             LOBYTE(stru_14C13AC.ip), BYTE1(stru_14C13AC.ip),
             BYTE2(stru_14C13AC.ip), HIBYTE(stru_14C13AC.ip), 20700);
  if (stru_14C13AC.type != 1)
    goto LABEL_4;
}

void __cdecl CL_ResetSkeletonCache(int localClientNum) {
  char *v1;            // edx
  int v2;              // eax
  unsigned int result; // eax

  v1 = &clients[1547284 * a1];
  v2 = 1;
  if (*((_DWORD *)v1 + 8595) != -1)
    v2 = *((_DWORD *)v1 + 8595) + 1;
  *((_DWORD *)v1 + 8595) = v2;
  result = (unsigned int)(v1 + 34403) & 0xFFFFFFF0;
  *((_DWORD *)v1 + 74133) = result;
  *((_DWORD *)v1 + 8596) = 0;
  return result;
}

char *__cdecl CL_AllocSkelMemory(int localClientNum, unsigned int size) {
  char *v2;      // ecx
  int result;    // eax
  signed int v4; // edx

  v2 = &clients[1547284 * a1];
  result = *((_DWORD *)v2 + 74133) + *((_DWORD *)v2 + 8596);
  v4 = *((_DWORD *)v2 + 8596) + ((a2 + 15) & 0xFFFFFFF0);
  *((_DWORD *)v2 + 8596) = v4;
  if (v4 >= 262129)
    return 0;
  return result;
}

int __cdecl CL_GetSkelTimeStamp(int localClientNum) {
  return dword_151228C[386821 * a1];
}

void __cdecl CL_AddReliableCommand(char const *cmd) {
  char *v1; // eax
  char v3;  // [esp+8h] [ebp-10h]

  if (!((dword_14C1550 - dword_14C1554 - 128 < 0) ^
            __OFADD__(-128, dword_14C1550 - dword_14C1554) |
        (dword_14C1550 - dword_14C1554 == 128)))
    Com_Error(1, "EXE_ERR_CLIENT_CMD_OVERFLOW", v3);
  v1 = (char *)clc;
  ++*((_DWORD *)clc + 76);
  return MSG_WriteReliableCommandToBuffer(
      a1, &v1[1024 * (*((_DWORD *)v1 + 76) & 0x7F) + 312], (char *)0x400);
}

char const *__cdecl CL_GetXuidForLocalClient(int) { UNIMPLEMENTED(); }

enum connstate_t __cdecl CL_GetLocalClientConnectionState(int) {
  UNIMPLEMENTED();
}

void __cdecl CL_SetLocalClientConnectionState(int, enum connstate_t) {
  UNIMPLEMENTED();
}

bool __cdecl CL_AllLocalClientsStateConsistent(void) { UNIMPLEMENTED(); }

bool __cdecl CL_AnyLocalClientChallenging() {
  return clients && clientConnections == 4;
}

bool __cdecl CL_AnyLocalClientStateActive(void) { UNIMPLEMENTED(); }

bool __cdecl CL_AllLocalClientsInactive(void) { UNIMPLEMENTED(); }

int __cdecl CL_ControllerIndexFromClientNum(int) { UNIMPLEMENTED(); }

int __cdecl CL_LocalClientNumFromControllerIndex(int) { UNIMPLEMENTED(); }

int __cdecl CL_GetFrameActiveClientCount(void) { UNIMPLEMENTED(); }

int __cdecl CL_GetActiveLocalClientIndex(int) { UNIMPLEMENTED(); }

int __cdecl CL_GetLocalClientActiveCount() { return 1; }

bool __cdecl CL_GetLocalClientActive(int clientNum) { return 1; }

void __cdecl CL_SetView(void) { UNIMPLEMENTED(); }

void __cdecl CL_ForwardCommandToServer(char const *string) {
  const char *v1; // ebx
  _DWORD *v2;     // esi
  int v3;         // edx
  int v4;         // edx
  char v5;        // [esp+8h] [ebp-10h]

  v1 = (const char *)Cmd_Argv(0);
  if (*v1 != 45) {
    v2 = clc;
    if (*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc) || *(int *)clc <= 4 ||
        *v1 == 43) {
      Com_Printf("Unknown command \"%s\"\n", v1);
    } else if (Cmd_Argc() <= 1) {
      v4 = v2[76];
      if (!((v4 - v2[77] - 128 < 0) ^ __OFADD__(-128, v4 - v2[77]) |
            (v4 - v2[77] == 128))) {
        Com_Error(1, "EXE_ERR_CLIENT_CMD_OVERFLOW", v5);
        v4 = v2[76];
      }
      v2[76] = v4 + 1;
      MSG_WriteReliableCommandToBuffer(
          v1, (char *)&v2[256 * (v2[76] & 0x7F) + 78], (char *)0x400);
    } else {
      v3 = v2[76];
      if (!((v3 - v2[77] - 128 < 0) ^ __OFADD__(-128, v3 - v2[77]) |
            (v3 - v2[77] == 128))) {
        Com_Error(1, "EXE_ERR_CLIENT_CMD_OVERFLOW", v5);
        v3 = v2[76];
      }
      v2[76] = v3 + 1;
      MSG_WriteReliableCommandToBuffer(
          a1, (char *)&v2[256 * (v2[76] & 0x7F) + 78], (char *)0x400);
    }
  }
}

void __cdecl CL_ClearState() { UNIMPLEMENTED(); }

void __cdecl CL_StopRecord_f() {
  _DWORD *v0;  // ebx
  char v1[12]; // [esp+1Ch] [ebp-Ch] BYREF

  if (dword_1501BBC) {
    *(_DWORD *)v1 = -1;
    FS_Write(v1, 4u, dword_1501BD0);
    v0 = clc;
    FS_Write(v1, 4u, *((_DWORD *)clc + 66028));
    FS_FCloseFile(v0[66028]);
    v0[66028] = 0;
    v0[66023] = 0;
    Com_Printf("Stopped demo.\n");
  } else {
    Com_Printf("Not recording a demo.\n");
  }
}

void __cdecl CL_WriteDemoMessage(struct msg_t *msg, int headerBytes) {
  size_t v2;   // ebx
  _DWORD *v3;  // esi
  char v5[28]; // [esp+1Ch] [ebp-1Ch] BYREF

  *(_DWORD *)v5 = dword_14E1558;
  FS_Write(v5, 4u, dword_1501BD0);
  *(_DWORD *)v5 = a1->cursize - a2;
  v2 = *(_DWORD *)v5;
  v3 = clc;
  FS_Write(v5, 4u, *((_DWORD *)clc + 66028));
  return FS_Write((char *)(a1->data + a2), v2, v3[66028]);
}

bool __cdecl CL_IsRenderingSplitScreen() { return 0; }

int __cdecl CL_GetLocalClientControllerIndex(void) { UNIMPLEMENTED(); }

void __cdecl CL_SetLocalClientViewData(void) { UNIMPLEMENTED(); }

void __cdecl CL_AddDebugLine(float const *const start, float const *const end,
                             float const *const color, int depthTest,
                             int duration, int fromServer) {
  int result; // eax
  int v7;     // ecx
  int v8;     // edx

  result = dword_1220A68;
  if (dword_1220A68) {
    _size = 4096;
    v7 = dword_14C1404;
    result = dword_14C1404 + 1;
    if (dword_14C1404 + 1 <= 4096) {
      if (!dword_14C1408) {
        dword_14C1408 = (int)Z_MallocInternal(0x2C000u);
        dword_14C140C = (int)Z_MallocInternal(_size);
        dword_14C1410 = (int)Z_MallocInternal(4 * _size);
        v7 = 0;
        dword_14C1404 = 0;
      }
      v8 = dword_14C1408 + 44 * v7;
      *(float *)v8 = *a1;
      *(float *)(v8 + 4) = a1[1];
      *(float *)(v8 + 8) = a1[2];
      *(float *)(v8 + 12) = *a2;
      *(float *)(v8 + 16) = a2[1];
      *(float *)(v8 + 20) = a2[2];
      *(float *)(v8 + 24) = *a3;
      *(float *)(v8 + 28) = a3[1];
      *(float *)(v8 + 32) = a3[2];
      *(float *)(v8 + 36) = a3[3];
      *(_DWORD *)(v8 + 40) = a4;
      *(_BYTE *)(dword_14C140C + dword_14C1404) = a6;
      result = dword_14C1410;
      *(_DWORD *)(dword_14C1410 + 4 * dword_14C1404++) = a5;
    }
  }
  return result;
}

void __cdecl CL_AddDebugString(float const *const xyz, float const *const color,
                               float scale, char const *text, int fromServer) {
  int result; // eax
  int v6;     // edx
  int v7;     // ebx

  result = dword_1220A68;
  if (dword_1220A68) {
    dword_14C13F0 = 256;
    v6 = dword_14C13F4;
    result = dword_14C13F4 + 1;
    if (dword_14C13F4 + 1 <= 256) {
      if (!dword_14C13F8) {
        dword_14C13F8 = (int)Z_MallocInternal(0x8000u);
        dword_14C13FC = (int)Z_MallocInternal(dword_14C13F0);
        v6 = 0;
        dword_14C13F4 = 0;
      }
      v7 = dword_14C13F8 + (v6 << 7);
      *(float *)v7 = *a1;
      *(float *)(v7 + 4) = a1[1];
      *(float *)(v7 + 8) = a1[2];
      *(float *)(v7 + 12) = *a2;
      *(float *)(v7 + 16) = a2[1];
      *(float *)(v7 + 20) = a2[2];
      *(float *)(v7 + 24) = a2[3];
      *(float *)(v7 + 28) = a3;
      strncpy((char *)(v7 + 32), __src, 0x5Fu);
      *(_BYTE *)(v7 + 127) = 0;
      result = dword_14C13F4;
      *(_BYTE *)(dword_14C13FC + dword_14C13F4++) = a5;
    }
  }
  return result;
}

void __cdecl CL_SwitchToLocalClient(int clientNum) { ; }

void __cdecl CL_DrawTextWithCursor(char const *text, int maxChars,
                                   struct Font_s *font, float x, float y,
                                   int horzAlign, int vertAlign, float xScale,
                                   float yScale, float const *const color,
                                   int style, int cursorPos, char cursor) {
  int v13; // ebx

  v13 = a13;
  CalcSplitScreenTextOffset();
  CalcScreenPlacement(&a4, &a5, &a8, &a9, a6, a7);
  return dword_121C7CC(a1, a2, a3, LODWORD(a4), LODWORD(a5), LODWORD(a8),
                       LODWORD(a9), a10, a11, a12, v13);
}

void __cdecl CL_DrawText(char const *text, int maxChars, struct Font_s *font,
                         float x, float y, int horzAlign, int vertAlign,
                         float xScale, float yScale, float const *const color,
                         int style) {
  CalcSplitScreenTextOffset();
  CalcScreenPlacement(&a4, &a5, &a8, &a9, a6, a7);
  return dword_121C7BC(a1, a2, a3, LODWORD(a4), LODWORD(a5), LODWORD(a8),
                       LODWORD(a9), a10, a11);
}

bool __cdecl CL_IsPlayerTalking(int clientIndex) {
  return Voice_IsClientTalking(a1);
}

bool __cdecl CL_AllLocalClientsDisconnected() {
  return !Sys_IsMainThread() || UI_IsFullscreen() || !clients[0] ||
         clientConnections <= 2;
}

void __cdecl CL_UpdateServerInfo(int) { UNIMPLEMENTED(); }

void __cdecl CL_GetPing(int n, char *buf, int buflen, int *pingtime) {
  int *result;  // eax
  char *v5;     // eax
  int v6;       // edi
  int v7;       // eax
  int Int;      // eax
  __int128 v9;  // [esp+0h] [ebp-58h]
  netadr_t v10; // [esp+0h] [ebp-58h]

  if (LOWORD(dword_121C808[261 * a1])) {
    LODWORD(v9) = cl_pinglist[261 * a1];
    DWORD1(v9) = dword_121C804[261 * a1];
    DWORD2(v9) = dword_121C808[261 * a1];
    v5 = NET_AdrToString(v9);
    I_strncpyz(__dst, v5, a3);
    v6 = dword_121C810[261 * a1];
    if (v6) {
      v7 = dword_121C810[261 * a1];
    } else {
      v6 = Sys_Milliseconds() - dword_121C80C[261 * a1];
      Int = Dvar_GetInt("cl_maxPing");
      if (Int <= 99)
        Int = 100;
      if (Int > v6)
        v6 = 0;
      v7 = dword_121C810[261 * a1];
    }
    v10.type = cl_pinglist[261 * a1];
    v10.ip = dword_121C804[261 * a1];
    v10.port = dword_121C808[261 * a1];
    CL_SetServerInfoByAddress(v10, &byte_121C814[1044 * a1], v7);
    result = a4;
    *a4 = v6;
  } else {
    *__dst = 0;
    result = a4;
    *a4 = 0;
  }
  return result;
}

void __cdecl CL_StopLogoOrCinematic() {
  if (clientConnections == 1)
    SCR_StopCinematic();
  else
    clientConnections = 0;
  SND_StopSounds(SND_STOP_ALL);
  if (*(_DWORD *)clc)
    return UI_SetActiveMenu(0);
  else
    return UI_SetActiveMenu(1);
}

void __cdecl CL_InitRenderer() { UNIMPLEMENTED(); }

int __cdecl CL_UpdateDirtyPings_f(int source) {
  int *v1;          // eax
  char *i;          // ecx
  int *v3;          // edi
  int v4;           // edx
  int *v5;          // eax
  int v6;           // ebx
  int *v7;          // edx
  unsigned int v9;  // ebx
  int *v10;         // esi
  char *v11;        // eax
  netadr_t v12;     // [esp+0h] [ebp-488h]
  netadr_t v13;     // [esp+4h] [ebp-484h]
  netadr_t v14;     // [esp+Ch] [ebp-47Ch]
  int v15;          // [esp+2Ch] [ebp-45Ch]
  int v16;          // [esp+30h] [ebp-458h]
  int v17;          // [esp+34h] [ebp-454h]
  int v18;          // [esp+38h] [ebp-450h]
  char *v19;        // [esp+3Ch] [ebp-44Ch]
  char __dst[1024]; // [esp+48h] [ebp-440h] BYREF
  __int64 v21;      // [esp+448h] [ebp-40h]
  int v22;          // [esp+450h] [ebp-38h]
  int v23;          // [esp+454h] [ebp-34h]
  int32_t v24;      // [esp+458h] [ebp-30h]
  int v25;          // [esp+45Ch] [ebp-2Ch]
  __int64 v26;      // [esp+460h] [ebp-28h]
  int v27;          // [esp+468h] [ebp-20h]
  int v28[7];       // [esp+46Ch] [ebp-1Ch] BYREF

  if (clientConnections || a1 > 2)
    return 0;
  dword_14C13A8 = a1;
  v15 = 0;
  v1 = dword_121C808;
  do {
    v15 -= (*(_WORD *)v1 == 0) - 1;
    v1 += 261;
  } while (&unk_1220948 != (_UNKNOWN *)v1);
  if (v15 <= 15) {
    if (a1 == 1) {
      v17 = dword_1224EA0;
      v11 = (char *)&unk_1224EA4;
    } else if (a1 == 2) {
      v17 = dword_14BCFA4;
      v11 = (char *)&unk_14BCFA8;
    } else {
      v17 = dword_1220A98;
      v11 = (char *)&unk_1220A9C;
    }
    if (v17 > 0) {
      v19 = v11;
      v18 = 0;
      v16 = 0;
      for (i = v11;; i = v19) {
        if (i[15] && *((_WORD *)i + 15) == 0xFFFF) {
          if (v15 > 15)
            goto LABEL_30;
          v3 = dword_121C808;
          do {
            while (!*(_WORD *)v3) {
              v3 += 261;
              if (&unk_1220948 == (_UNKNOWN *)v3)
                goto LABEL_20;
            }
            v21 = *(_QWORD *)v19;
            v22 = *((_DWORD *)v19 + 2);
            v23 = *(v3 - 2);
            v24 = *(v3 - 1);
            v25 = *v3;
            *(_QWORD *)&v14.type = v21;
            v14.port = v22;
            v12.type = *(v3 - 2);
            v12.ip = v24;
            v12.port = v25;
            if (NET_CompareAdr(v12, v14))
              goto LABEL_10;
            v3 += 261;
          } while (&unk_1220948 != (_UNKNOWN *)v3);
        LABEL_20:
          v4 = 0;
          v5 = cl_pinglist;
          do {
            if (!*((_WORD *)v5 + 4))
              break;
            ++v4;
            v5 += 261;
          } while (v4 != 16);
          v6 = 261 * v4;
          v7 = &cl_pinglist[v6];
          cl_pinglist[v6] = *(_DWORD *)v19;
          v7[1] = *((_DWORD *)v19 + 1);
          v7[2] = *((_DWORD *)v19 + 2);
          dword_121C80C[v6] = Sys_Milliseconds();
          dword_121C810[v6] = 0;
          LODWORD(v26) = cl_pinglist[v6];
          HIDWORD(v26) = dword_121C804[v6];
          v27 = dword_121C808[v6];
          *(_QWORD *)&v13.type = v26;
          v13.port = v27;
          NET_OutOfBandPrint(NS_CLIENT1, v13, "getinfo xxx");
          ++v15;
          v18 = 1;
        }
      LABEL_10:
        ++v16;
        v19 += 136;
        if (v17 == v16)
          goto LABEL_29;
      }
    }
  }
  v18 = 0;
LABEL_29:
  if (v15)
  LABEL_30:
    v18 = 1;
  v9 = 0;
  v10 = cl_pinglist;
  do {
    if (*((_WORD *)v10 + 4)) {
      CL_GetPing(v9, __dst, 1024, v28);
      if (v28[0]) {
        if (v9 <= 0xF)
          *((_WORD *)v10 + 4) = 0;
        v18 = 1;
      }
    }
    ++v9;
    v10 += 261;
  } while (v9 != 16);
  return v18;
}

void __cdecl CL_UpdateInGameState(void) { UNIMPLEMENTED(); }

void __cdecl CL_Disconnect() { UNIMPLEMENTED(); }

void __cdecl CL_SetLocalClientActive(int, bool) { UNIMPLEMENTED(); }

char const *__cdecl CL_GetUsernameForLocalClient(int controllerIndex) {
  return *(_DWORD *)(name + 8);
}

void __cdecl CL_CheckUserinfo(void) { UNIMPLEMENTED(); }

void __cdecl CL_NextDemo(void) { UNIMPLEMENTED(); }

void __cdecl CL_ToggleMenu_f() { UNIMPLEMENTED(); }

void __cdecl CL_CheckTimeout(void) { UNIMPLEMENTED(); }

void __cdecl CL_CheckForResend() {
  char *v7;                  // ebx
  char *v8;                  // eax
  char *v9;                  // eax
  char *v10;                 // eax
  char *v11;                 // eax
  unsigned int i;            // edx
  netadr_t v13;              // [esp+0h] [ebp-868h]
  netadr_t v14;              // [esp+4h] [ebp-864h]
  netadr_t v15;              // [esp+4h] [ebp-864h]
  unsigned __int8 v16[1024]; // [esp+2Ch] [ebp-83Ch] BYREF
  char __dst[1024];          // [esp+42Ch] [ebp-43Ch] BYREF
  __int64 v18;               // [esp+82Ch] [ebp-3Ch]
  int v19;                   // [esp+834h] [ebp-34h]
  __int64 v20;               // [esp+838h] [ebp-30h]
  __int64 v21;               // [esp+844h] [ebp-24h]
  int v22;                   // [esp+84Ch] [ebp-1Ch]

  if (!dword_1501BC0 && (unsigned int)(clientConnections - 3) <= 1 &&
      dword_1220A78 - dword_14C1440 > 2999) {
    dword_14C1440 = dword_1220A78;
    v7 = (char *)clc;
    ++*((_DWORD *)clc + 9);
    if (*(_DWORD *)v7 == 3) {
      if (*(_BYTE *)(net_lanauthorize + 8) ||
          (v18 = *(_QWORD *)(v7 + 20), v19 = *((_DWORD *)v7 + 7),
           *(_QWORD *)&v13.type = v18, v13.port = v19,
           !Sys_IsLANAddress(v13))) {
        CL_RequestAuthorization(a1, a2, a3, a4, a5, a6, a7);
      }
      v20 = *(_QWORD *)((char *)clc + 20);
      *(_QWORD *)&v14.type = v20;
      v14.port = *((_DWORD *)clc + 7);
      NET_OutOfBandPrint(NS_CLIENT1, v14, "getchallenge");
    } else if (*(_DWORD *)v7 == 4) {
      v8 = Dvar_InfoString(2u);
      I_strncpyz(__dst, v8, 1024);
      v9 = va("%i", 115);
      Info_SetValueForKey(__dst, "protocol", v9);
      v10 = va("%i", *((_DWORD *)v7 + 74));
      Info_SetValueForKey(__dst, "challenge", v10);
      v11 = va("%i", *((_DWORD *)v7 + 1));
      Info_SetValueForKey(__dst, "qport", v11);
      qmemcpy(v16, "connect \"", 9);
      for (i = 0; strlen(__dst) > i; ++i)
        v16[i + 9] = __dst[i];
      v16[i + 9] = 34;
      v16[i + 10] = 0;
      v21 = *(_QWORD *)((char *)clc + 20);
      v22 = *((_DWORD *)clc + 7);
      *(_QWORD *)&v15.type = v21;
      v15.port = v22;
      NET_OutOfBandData(NS_CLIENT1, v15, v16, i + 10);
      dvar_modifiedFlags &= ~2u;
    } else {
      Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
                "\x15CL_CheckForResend: bad clc->state");
    }
  }
}

void __cdecl CL_Disconnect_f() { UNIMPLEMENTED(); }

void __cdecl CL_MapLoading(char const *mapname) {
  netadr_t *v8; // eax
  _DWORD *v9;   // ebx

  if (*(_DWORD *)(legacyHacks + 4)) {
    g_waitingForServer = 0;
    Con_Close();
    dword_1509C44 = 0;
    byte_1509C48 = 0;
    if (clientConnections <= 4 || I_stricmp(&byte_1220968, "localhost")) {
      Dvar_SetString(nextmap, (char *)&inData);
      I_strncpyz(&byte_1220968, "localhost", 256);
      CL_Disconnect(a1, a2, a3, a4, a5, a6, a7);
      UI_CloseAll(a1, a2, a3, a4, a5, a6, a7);
      v8 = (netadr_t *)clc;
      *(_DWORD *)clc = 4;
      *(int32_t *)((char *)&v8[3].type + 2) = -3000;
      v8->ip = g_qport[0];
      NET_StringToAdr(&byte_1220968, v8 + 2);
      CL_CheckForResend(a1, a2, a3, a4, a5, a6, a7);
      I_strncpyz((char *)(legacyHacks + 92), __src, 64);
      *(_BYTE *)(legacyHacks + 220) = 0;
    } else {
      v9 = clc;
      *(_DWORD *)clc = 5;
      memset(v9 + 10, 0, 0x100u);
      memset((char *)cl + 9996, 0, 0x5E84u);
      v9[3] = -9999;
      I_strncpyz((char *)(legacyHacks + 92), __src, 64);
      *(_BYTE *)(legacyHacks + 220) = 0;
    }
    SND_FadeAllSounds(0, 0);
  }
}

void __cdecl CL_LocalServers_f() {
  char *v0;         // esi
  char *v1;         // edi
  char v2;          // bl
  int v3;           // esi
  int i;            // ebx
  int result;       // eax
  netadr_t v6;      // [esp+8h] [ebp-60h]
  int v7;           // [esp+2Ch] [ebp-3Ch]
  int __b;          // [esp+38h] [ebp-30h] BYREF
  unsigned int v9;  // [esp+3Ch] [ebp-2Ch]
  int v10;          // [esp+40h] [ebp-28h]
  int v11;          // [esp+44h] [ebp-24h]
  unsigned int v12; // [esp+48h] [ebp-20h]
  int v13;          // [esp+4Ch] [ebp-1Ch]

  Com_Printf("Scanning for servers on the local network...\n");
  dword_1220A98 = 0;
  dword_14C13A8 = 0;
  v7 = 0;
  v0 = (char *)&cls;
  v1 = (char *)&unk_1220A9C;
  do {
    v2 = v0[331];
    Com_Memset(v1, 0, 0x88u);
    v0[331] = v2;
    ++v7;
    v1 += 136;
    v0 += 136;
  } while (v7 != 128);
  Com_Memset(&__b, 0, 0xCu);
  v3 = 2;
  do {
    for (i = 28960; i != 28964; ++i) {
      LOWORD(v10) = __ROL2__(i, 8);
      __b = 3;
      v11 = 3;
      v12 = v9;
      v13 = v10;
      *(_QWORD *)&v6.type = __PAIR64__(v9, 3);
      v6.port = v10;
      result = CL_Netchan_SendOOBPacket(15, "\xFF\xFF\xFF\xFFgetinfo xxx", v6);
    }
    --v3;
  } while (v3);
  return result;
}

void __cdecl CL_PlayLogo_f() {
  _DWORD *v7;                           // ebx
  int v8;                               // eax
  const char *v9;                       // esi
  const char *v10;                      // eax
  float v11;                            // xmm0_4
  const char *v12;                      // eax
  float v13;                            // xmm0_4
  const char *v14;                      // eax
  float v15;                            // xmm0_4
  int(__cdecl * v16)(char *, int, int); // ebx
  char *v17;                            // eax
  int(__cdecl * v18)(char *, int, int); // ebx
  char *v19;                            // eax
  float v20;                            // [esp+1Ch] [ebp-2Ch]
  float v21;                            // [esp+20h] [ebp-28h]
  float v22;                            // [esp+24h] [ebp-24h]

  if (Cmd_Argc() != 5) {
    Com_Printf("USAGE: logo <image name> <fadein seconds> <full duration "
               "seconds> <fadeout seconds>\n");
    return;
  }
  Com_DPrintf("CL_PlayLogo_f\n");
  v7 = clc;
  v8 = *(_DWORD *)clc;
  if (*(_DWORD *)clc == 1) {
    SCR_StopCinematic(a1, a2, a3, a4, a5, a6, a7);
  } else if (v8 == 2) {
    *(_DWORD *)clc = 0;
  } else if (v8) {
    return;
  }
  *v7 = 2;
  if (dword_1220A70)
    UI_SetActiveMenu(a1, a2, a3, a4, a5, a6, a7, 0);
  SND_StopSounds(SND_STOP_ALL);
  SND_FadeAllSounds(1065353216, 0);
  v9 = (const char *)Cmd_Argv(1);
  v10 = (const char *)Cmd_Argv(2);
  v11 = atof(v10);
  v22 = floorf((float)(v11 * 1000.0) + 0.5);
  dword_1220A88 = (int)v22;
  v12 = (const char *)Cmd_Argv(3);
  v13 = atof(v12);
  v21 = floorf((float)(v13 * 1000.0) + 0.5);
  dword_1220A84 = (int)v21;
  v14 = (const char *)Cmd_Argv(4);
  v15 = atof(v14);
  v20 = floorf((float)(v15 * 1000.0) + 0.5);
  dword_1220A8C = (int)v20;
  dword_1220A84 += dword_1220A88 + (int)v20;
  v16 = (int(__cdecl *)(char *, int, int))dword_121C6B0;
  v17 = va("%s1", v9);
  dword_1220A90 = v16(v17, 48, 3);
  v18 = (int(__cdecl *)(char *, int, int))dword_121C6B0;
  v19 = va("%s2", v9);
  dword_1220A94 = v18(v19, 48, 3);
  dword_1220A80 = dword_1220A78 + 100;
}

void __cdecl CL_RefPrintf(int print_level, char const *fmt, ...) {
  char __str[4096]; // [esp+1Ch] [ebp-100Ch] BYREF
  va_list v3;       // [esp+101Ch] [ebp-Ch]
  va_list va;       // [esp+1038h] [ebp+10h] BYREF

  va_start(va, __format);
  va_copy(v3, va);
  vsnprintf(__str, 0x1000u, __format, va);
  if (a1) {
    switch (a1) {
    case 2:
      Com_Printf("^3%s", __str);
      break;
    case 3:
      Com_Printf("^1%s", __str);
      break;
    case 1:
      Com_DPrintf("^1%s", __str);
      break;
    }
  } else {
    Com_Printf("%s", __str);
  }
}

void __cdecl CL_Configstrings_f() {
  int v0;         // ebx
  const char *v1; // esi
  int v2;         // eax

  if (clientConnections == 8) {
    v0 = 0;
    v1 = (const char *)cl;
    do {
      v2 = *(_DWORD *)&v1[4 * v0 + 9996];
      if (v2)
        Com_Printf("%4i: %s\n", v0, &v1[v2 + 18188]);
      ++v0;
    } while (v0 != 2048);
  } else {
    Com_Printf("Not connected to a server.\n");
  }
}

void __cdecl CL_Reconnect_f() {
  char *v0; // eax

  if (byte_1220968 && strcmp(&byte_1220968, "localhost")) {
    v0 = va("connect %s\n", &byte_1220968);
    Cbuf_AddText(v0);
  } else {
    Com_Printf("Can't reconnect to localhost.\n");
  }
}

void __cdecl CL_Setenv_f() {
  int v0;           // eax
  int v1;           // edi
  char *v2;         // eax
  int v3;           // ebx
  char *v4;         // eax
  const char *v5;   // eax
  char *v6;         // ebx
  const char *v7;   // eax
  char __dst[1048]; // [esp+10h] [ebp-418h] BYREF

  v0 = Cmd_Argc();
  v1 = v0;
  if (v0 > 2) {
    v2 = (char *)Cmd_Argv(1);
    I_strncpyz(__dst, v2, 1024);
    I_strncat(__dst, 1024, (char *)&stru_222904);
    v3 = 2;
    do {
      v4 = (char *)Cmd_Argv(v3);
      I_strncat(__dst, 1024, v4);
      I_strncat(__dst, 1024, " ");
      ++v3;
    } while (v1 != v3);
    putenv(__dst);
  } else if (v0 == 2) {
    v5 = (const char *)Cmd_Argv(1);
    v6 = getenv(v5);
    v7 = (const char *)Cmd_Argv(1);
    if (v6)
      Com_Printf("%s=%s\n", v7, v6);
    else
      Com_Printf("%s undefined\n", v7);
  }
}

void __cdecl CL_ForwardToServer_f() {
  char *v7;   // esi
  _DWORD *v8; // ebx
  int v9;     // edx

  if (clientConnections != 8 || dword_1501BC0) {
    Com_Printf("Not connected to a server.\n");
  } else if (Cmd_Argc() > 1) {
    v7 = Cmd_Args(1);
    v8 = clc;
    v9 = *((_DWORD *)clc + 76);
    if (!((v9 - *((_DWORD *)clc + 77) - 128 < 0) ^
              __OFADD__(-128, v9 - *((_DWORD *)clc + 77)) |
          (v9 - *((_DWORD *)clc + 77) == 128))) {
      Com_Error(a1, a2, a3, a4, a5, a6, a7, 1, "EXE_ERR_CLIENT_CMD_OVERFLOW");
      v9 = v8[76];
    }
    v8[76] = v9 + 1;
    MSG_WriteReliableCommandToBuffer(
        v7, (char *)&v8[256 * (v8[76] & 0x7F) + 78], (char *)0x400);
  }
}

void __cdecl CL_DemoCompleted() { UNIMPLEMENTED(); }

void __cdecl CL_ShowIP_f() { Sys_ShowIP(); }

void __cdecl CL_VoicePacket(struct msg_t *) {
  int Byte;                   // eax
  int v4;                     // ebx
  int v5;                     // edi
  int v6;                     // edx
  unsigned __int8 v7;         // [esp+1Bh] [ebp-11Dh]
  unsigned __int8 __dst[256]; // [esp+1Ch] [ebp-11Ch] BYREF
  int v9;                     // [esp+11Ch] [ebp-1Ch]

  Byte = MSG_ReadByte(a3);
  v4 = Byte;
  if ((unsigned int)Byte <= 0x28 && Byte > 0) {
    v5 = 0;
    while (1) {
      v7 = MSG_ReadByte(a3);
      v6 = MSG_ReadByte(a3);
      v9 = v6;
      if ((unsigned int)(v6 - 1) > 0xFF) {
        Com_Printf("Invalid server voice packet of %i bytes\n", v6);
        return;
      }
      MSG_ReadData(a3, __dst, v6);
      if (v7 > 0x3Fu)
        break;
      if (!(unsigned __int8)CL_IsPlayerMuted(v7)) {
        if (*(_BYTE *)(cl_voice + 8))
          Voice_IncomingVoiceData(a1, a2, v7, __dst, v9);
      }
      if (v4 == ++v5)
        return;
    }
    Com_Printf("Invalid voice packet - talker was %i\n", v7);
  }
}

void __cdecl CL_Clientinfo_f() {
  char *v0; // eax

  Com_Printf("--------- Client Information ---------\n");
  Com_Printf("state: %i\n", *(_DWORD *)clc);
  Com_Printf("Server: %s\n", &byte_1220968);
  Com_Printf("User info settings:\n");
  v0 = Dvar_InfoString(2u);
  Info_Print(v0);
  Com_Printf("--------------------------------------\n");
}

void __cdecl CL_DisconnectPacket(struct netadr_t) { UNIMPLEMENTED(); }

void __cdecl CL_Record_f() {
  int i;                      // ebx
  void *v1;                   // ebx
  int v2;                     // eax
  int v3;                     // esi
  char *v4;                   // edi
  int v5;                     // ebx
  entityState_s *v6;          // ebx
  _DWORD *v7;                 // esi
  char *v8;                   // eax
  size_t v9;                  // [esp+2Ch] [ebp-826Ch]
  int v10;                    // [esp+34h] [ebp-8264h] BYREF
  unsigned __int8 v11[16380]; // [esp+38h] [ebp-8260h] BYREF
  unsigned __int8 v12[16384]; // [esp+4034h] [ebp-4264h] BYREF
  char __str[256];            // [esp+8034h] [ebp-264h] BYREF
  entityState_s __b;          // [esp+8134h] [ebp-164h] BYREF
  char __src[64];             // [esp+8224h] [ebp-74h] BYREF
  msg_t v16;                  // [esp+8264h] [ebp-34h] BYREF
  char v17[28];               // [esp+827Ch] [ebp-1Ch] BYREF

  if (Cmd_Argc() > 2) {
    Com_Printf("record <demoname>\n");
  } else if (*((_DWORD *)clc + 66023)) {
    Com_Printf("Already recording.\n");
  } else if (*(_DWORD *)clc == 8) {
    if (Cmd_Argc() == 2) {
      v8 = (char *)Cmd_Argv(1);
      I_strncpyz(__src, v8, 64);
      Com_sprintf(__str, 0x100u, "demos/%s.dm_%d", __src, 1);
    } else {
      for (i = 0; i != 10000; ++i) {
        Com_sprintf(__src, 0x40u, "demo%04i", i);
        Com_sprintf(__str, 0x100u, "demos/%s.dm_%d", __src, 1);
        if (!FS_FileExists(__str))
          break;
      }
    }
    Com_Printf("recording to %s.\n", __str);
    v1 = clc;
    v2 = FS_FOpenFileWrite(__str);
    *((_DWORD *)v1 + 66028) = v2;
    if (v2) {
      *((_DWORD *)v1 + 66023) = 1;
      I_strncpyz((char *)v1 + 264028, __src, 64);
      *((_DWORD *)v1 + 66026) = 1;
      MSG_Init(&v16, v12, 0x4000u);
      MSG_WriteLong(&v16, *((_DWORD *)v1 + 76));
      MSG_WriteByte(&v16, 1);
      MSG_WriteLong(&v16, *((_DWORD *)v1 + 32847));
      v3 = 0;
      v4 = (char *)cl;
      do {
        v5 = *(_DWORD *)&v4[4 * v3 + 9996];
        if (v5) {
          MSG_WriteByte(&v16, 2);
          MSG_WriteShort(&v16, v3);
          MSG_WriteBigString(&v16, &v4[v5 + 18188]);
        }
        ++v3;
      } while (v3 != 2048);
      memset(&__b, 0, sizeof(__b));
      LOWORD(v3) = 0;
      v6 = (entityState_s *)((char *)cl + 618720);
      do {
        if (v6->number) {
          MSG_WriteByte(&v16, 3);
          MSG_WriteDeltaEntity(&v16, &__b, v6, (msg_t *)1);
        }
        ++v3;
        ++v6;
      } while (v3 != 1024);
      MSG_WriteByte(&v16, 7);
      v7 = clc;
      MSG_WriteLong(&v16, *((_DWORD *)clc + 2));
      MSG_WriteLong(&v16, v7[75]);
      MSG_WriteByte(&v16, 7);
      v10 = *(_DWORD *)v16.data;
      v9 = MSG_WriteBitsCompress((unsigned __int8 *)(v16.data + 4), v11,
                                 v16.cursize - 4) +
           4;
      *(_DWORD *)v17 = *(_DWORD *)((char *)&loc_20138 + (_DWORD)v7);
      FS_Write(v17, 4u, v7[66028]);
      *(_DWORD *)v17 = v9;
      FS_Write(v17, 4u, v7[66028]);
      FS_Write((char *)&v10, v9, v7[66028]);
    } else {
      Com_Printf("ERROR: couldn't open.\n");
    }
  } else {
    Com_Printf("You must be in a level to record.\n");
  }
}

void __cdecl CL_VoiceTransmit() { UNIMPLEMENTED(); }

void __cdecl CL_VoiceFrame(void) { UNIMPLEMENTED(); }

void __cdecl CL_Init() {
  _BYTE *v0; // ebx
  char v1;   // si
  char v2;   // di
  int v3;    // [esp+18h] [ebp-20h]
  char v4;   // [esp+1Eh] [ebp-1Ah]
  char v5;   // [esp+1Fh] [ebp-19h]

  Com_Printf("----- Client Initialization -----\n");
  v0 = cl;
  v1 = *((_BYTE *)cl + 9);
  v2 = *((_BYTE *)cl + 10);
  v3 = *((_DWORD *)cl + 1);
  v4 = *((_BYTE *)cl + 8);
  v5 = *(_BYTE *)cl;
  memset(cl, 0, 0x179C14u);
  v0[9] = v1;
  v0[10] = v2;
  *((_DWORD *)v0 + 1) = v3;
  v0[8] = v4;
  *v0 = v5;
  Com_ClientDObjClearAllSkel();
  CL_ClearMutedList();
  *((_DWORD *)v0 + 386819) = 0;
  *(_DWORD *)clc = 0;
  dword_1220A78 = 0;
  *v0 = 1;
  *(_BYTE *)(legacyHacks + 92) = 0;
  *(_BYTE *)(legacyHacks + 156) = 0;
  *(_BYTE *)(legacyHacks + 220) = 0;
  Cbuf_Execute();
  *(_DWORD *)(legacyHacks + 4) = 1;
  CL_SetADS(0);
  Com_Printf("----- Client Initialization Complete -----\n");
}

void __cdecl CL_StartHunkUsers() { UNIMPLEMENTED(); }

void __cdecl CL_Snd_Restart_f() {
  void *v7;            // eax
  void *v8;            // edi
  snd_listener v9;     // [esp+14h] [ebp-64h] BYREF
  MemoryFile __src[2]; // [esp+4Ch] [ebp-2Ch] BYREF

  if (*(_BYTE *)(com_sv_running + 8)) {
    Com_Printf("Listen server cannot sound restart.\n");
  } else {
    v7 = Z_VirtualAllocInternal((size_t)&unk_A00000);
    MemFile_InitForWriting(__src, (uint32_t)&unk_A00000, v7, 1u);
    SND_Save(a1, *(float *)&a2, a3, a4, a5, a6, a7, __src);
    v8 = Z_MallocInternal(__src[0].bytesUsed);
    memcpy(v8, __src[0].buffer, __src[0].bytesUsed);
    Z_VirtualFreeInternal(__src[0].buffer);
    SND_SaveListeners(&v9);
    SND_Shutdown();
    SND_Init(a1, *(float *)&a2, a3, a4, a5, a6, a7);
    SND_RestoreListeners(&v9);
    CL_Vid_Restart_f(a1, a2, a3, a4, a5, a6, a7);
    MemFile_InitForReading(__src, __src[0].bytesUsed, v8);
    SND_Restore(__src);
    Z_FreeInternal(v8);
  }
}

void __cdecl CL_RunOncePerClientFrame(int msec) {
  int v1;     // ebx
  int v2;     // edx
  int v3;     // eax
  int result; // eax
  char v5;    // [esp+8h] [ebp-10h]

  v1 = a1;
  if (UI_IsFullscreen())
    dword_121C7F4();
  v2 = cl_avidemo;
  if (!*(_DWORD *)(cl_avidemo + 8) || !a1) {
    if (!dword_1220A70)
      goto LABEL_6;
    goto LABEL_16;
  }
  if (*(_DWORD *)clc == 8 || *(_BYTE *)(cl_forceavidemo + 8)) {
    Cbuf_ExecuteText(0, "screenshot silent\n", v5);
    v2 = cl_avidemo;
  }
  v1 = (int)(float)((float)(1000.0 / (float)*(int *)(v2 + 8)) *
                    *(float *)&com_timescaleValue);
  if (!v1)
    v1 = 1;
  if (dword_1220A70)
  LABEL_16:
    CG_CalculateFPS();
LABEL_6:
  dword_1220A7C = v1;
  dword_1220A74 = v1;
  dword_1220A78 += v1;
  v3 = 1;
  if (com_frameTime != old_com_frameTime)
    v3 = com_frameTime - old_com_frameTime;
  frame_msec = v3;
  result = 200;
  if ((unsigned int)frame_msec < 0xC9)
    result = frame_msec;
  frame_msec = result;
  old_com_frameTime = com_frameTime;
  return result;
}

void __cdecl CL_startSingleplayer_f() { Sys_StartProcess("cod2sp_s.exe", 1); }

void __cdecl CL_ShutdownHunkUsers() { UNIMPLEMENTED(); }

void __cdecl CL_Shutdown() {
  Com_Printf("----- CL_Shutdown -----\n");
  if (CL_Shutdown(void)::recursive) {
    puts("recursive shutdown");
  } else {
    CL_Shutdown(void)::recursive = 1;
    CL_Disconnect(a1, a2, a3, a4, a5, a6, a7);
    if (!Sys_IsMainThread() || UI_IsFullscreen() || !clients[0] ||
        clientConnections <= 2) {
      CL_ShutdownDebugData();
      if (dword_1220964) {
        CL_ShutdownCGame(a2);
        CL_ShutdownUI(a1, a2, a3, a4, a5, a6, a7);
        dword_14C13B8 = 0;
        dword_14C13BC = 0;
        dword_14C13C0 = 0;
        dword_1220964 = 0;
      }
      SND_Shutdown();
      if (dword_121C7E8)
        dword_121C7E8();
      if (re) {
        re(1);
        memset(&re, 0, 0x160u);
      }
      StatMon_Reset();
      CL_ShutdownInput();
      Cmd_RemoveCommand("cmd");
      Cmd_RemoveCommand("configstrings");
      Cmd_RemoveCommand("clientinfo");
      Cmd_RemoveCommand("vid_restart");
      Cmd_RemoveCommand("snd_restart");
      Cmd_RemoveCommand("disconnect");
      Cmd_RemoveCommand("record");
      Cmd_RemoveCommand("demo");
      Cmd_RemoveCommand("cinematic");
      Cmd_RemoveCommand("logo");
      Cmd_RemoveCommand("stoprecord");
      Cmd_RemoveCommand("connect");
      Cmd_RemoveCommand("reconnect");
      Cmd_RemoveCommand("localservers");
      Cmd_RemoveCommand("globalservers");
      Cmd_RemoveCommand("rcon");
      Cmd_RemoveCommand("setenv");
      Cmd_RemoveCommand("ping");
      Cmd_RemoveCommand("serverstatus");
      Cmd_RemoveCommand("showip");
      Cmd_RemoveCommand("fs_openedList");
      Cmd_RemoveCommand("fs_referencedList");
      Cmd_RemoveCommand("updatehunkusage");
      Cmd_RemoveCommand("updatescreen");
      Cmd_RemoveCommand("SaveTranslations");
      Cmd_RemoveCommand("SaveNewTranslations");
      Cmd_RemoveCommand("LoadTranslations");
      Cmd_RemoveCommand("startSingleplayer");
      Cmd_RemoveCommand("buyNow");
      Cmd_RemoveCommand("singlePlayLink");
      Cmd_RemoveCommand("setRecommended");
      Cmd_RemoveCommand("cubemapShot");
      Cmd_RemoveCommand("openScriptMenu");
      Cmd_RemoveCommand("openmenu");
      Cmd_RemoveCommand("closemenu");
      memset(&cls, 0, 0x2A0AB4u);
    }
    *(_DWORD *)(legacyHacks + 4) = 0;
    CL_Shutdown(void)::recursive = 0;
    Com_Printf("-----------------------\n");
  }
}

void __cdecl CL_ShutdownAll() { UNIMPLEMENTED(); }

void __cdecl CL_InitRef() {
  int *RefAPI;       // eax
  _DWORD __src[137]; // [esp+14h] [ebp-224h] BYREF

  Com_Printf("----- Initializing Renderer ----\n");
  __src[62] = Cmd_AddCommand;
  __src[63] = Cmd_RemoveCommand;
  __src[64] = Cmd_Argc;
  __src[65] = Cmd_Argv;
  __src[66] = Cbuf_ExecuteText;
  __src[0] = CL_RefPrintf;
  __src[1] = Com_Error;
  __src[2] = CL_ScaledMilliseconds;
  __src[3] = Hunk_AllocInternal;
  __src[4] = Hunk_AllocateTempMemoryInternal;
  __src[5] = Z_MallocInternal;
  __src[6] = Z_FreeInternal;
  __src[7] = Hunk_AllocAlignInternal;
  __src[8] = Z_VirtualReserveInternal;
  __src[9] = Z_VirtualCommitInternal;
  __src[10] = Z_VirtualDecommitInternal;
  __src[11] = Z_VirtualFreeInternal;
  __src[12] = Hunk_FreeTempMemory;
  __src[16] = Hunk_AllocateTempMemoryHighInternal;
  __src[13] = Hunk_ClearTempMemory;
  __src[17] = Hunk_ClearTempMemoryHigh;
  __src[18] = Sys_DirectXFatalError;
  __src[19] = Sys_ShowSplashWindow;
  __src[20] = Sys_HideSplashWindow;
  __src[21] = Sys_LoadingKeepAlive;
  __src[74] = FS_ReadFile;
  __src[75] = FS_FreeFile;
  __src[76] = FS_FOpenFileRead;
  __src[80] = FS_WriteFile;
  __src[78] = FS_FreeFileList;
  __src[77] = FS_ListFiles;
  __src[79] = FS_FileExists;
  __src[81] = FS_FOpenFileByMode;
  __src[82] = FS_FCloseFile;
  __src[83] = FS_Read;
  __src[84] = FS_Write;
  __src[85] = CM_SaveLump;
  __src[86] = CM_BoxTrace;
  __src[87] = CM_BoxSightTrace;
  __src[22] = Dvar_RegisterBool;
  __src[23] = Dvar_RegisterInt;
  __src[24] = Dvar_RegisterFloat;
  __src[25] = Dvar_RegisterString;
  __src[26] = Dvar_RegisterEnum;
  __src[27] = Dvar_RegisterColor;
  __src[28] = Dvar_RegisterVec2;
  __src[29] = Dvar_RegisterVec3;
  __src[30] = Dvar_RegisterVec4;
  __src[34] = Dvar_ClearModified;
  __src[35] = Dvar_SetModified;
  __src[36] = Dvar_UpdateEnumDomain;
  __src[31] = Dvar_UnregisterSystem;
  __src[32] = Dvar_ChangeResetValue;
  __src[33] = Dvar_IsAtDefaultValue;
  __src[37] = Dvar_SetBool;
  __src[38] = Dvar_SetInt;
  __src[39] = Dvar_SetFloat;
  __src[40] = Dvar_SetString;
  __src[41] = Dvar_SetColor;
  __src[42] = Dvar_SetVec2;
  __src[43] = Dvar_SetVec3;
  __src[44] = Dvar_SetVec4;
  __src[45] = Dvar_SetFromString;
  __src[46] = Dvar_SetBoolByName;
  __src[47] = Dvar_SetIntByName;
  __src[48] = Dvar_SetFloatByName;
  __src[49] = Dvar_SetStringByName;
  __src[50] = Dvar_SetColorByName;
  __src[51] = Dvar_SetVec2ByName;
  __src[52] = Dvar_SetVec3ByName;
  __src[53] = Dvar_SetVec4ByName;
  __src[54] = Dvar_SetFromStringByName;
  __src[55] = Dvar_GetBool;
  __src[56] = Dvar_GetInt;
  __src[57] = Dvar_GetFloat;
  __src[58] = Dvar_GetString;
  __src[59] = Dvar_GetVariantString;
  __src[60] = Dvar_EnumToString;
  __src[61] = Dvar_Reset;
  __src[67] = Com_SaveDvarsToBuffer;
  __src[68] = Com_LoadDvarsFromBuffer;
  __src[69] = Com_GetBsp;
  __src[70] = SEH_ReadCharFromString;
  __src[71] = CL_UpdateDebugData;
  __src[72] = CL_FlushDebugData;
  __src[73] = StatMon_Warning;
  __src[89] = XModelPrecache;
  __src[90] = XModelGetSurfaces;
  __src[91] = XModelBad;
  __src[92] = Hunk_OverrideDataForFile;
  __src[93] = XModelGetNumLods;
  __src[94] = XModelSetTestLods;
  __src[95] = XModelGetLodForDist;
  __src[96] = XModelGetLodOutDist;
  __src[97] = XModelGetSurfaceName;
  __src[98] = XModelGetName;
  __src[99] = XModelGetFlags;
  __src[100] = XModelNumBones;
  __src[101] = XModelGetSkins;
  __src[102] = XModelGetMemUsage;
  __src[103] = XModelGetLodName;
  __src[104] = XModelGetBasePose;
  __src[105] = XModelGetBasePoseBone;
  __src[106] = DObjBad;
  __src[108] = DObjGetBounds;
  __src[109] = DObjGetSurface;
  __src[110] = DObjGetNumModels;
  __src[111] = DObjGetNumSurfaces;
  __src[112] = DObjGetSurfaces;
  __src[117] = DObjGetModel;
  __src[118] = DObjGetSurfaceName;
  __src[119] = DObjCreate;
  __src[120] = DObjGetAllocSkelSize;
  __src[121] = DObjCreateSkel;
  __src[122] = DObjCalcAnim;
  __src[123] = DObjCalcSkel;
  __src[114] = DObjGetRotTransArray;
  __src[115] = DObjSkelAreBonesUpToDate;
  __src[116] = DObjGetMatOffset;
  __src[124] = DObjNumBones;
  __src[125] = DObjGetBoneInfo;
  __src[126] = DObjGetLodForDist;
  __src[127] = DObjGetLodOutDist;
  __src[128] = DObjCompleteHierarchyBits;
  __src[129] = DObjSetModel;
  __src[130] = CIN_UploadCinematic;
  __src[131] = CIN_PlayCinematic;
  __src[132] = CIN_RunCinematic;
  __src[133] = CG_DObjCalcPose;
  __src[134] = CL_GetHudMsgIconMaterialName;
  RefAPI = GetRefAPI(59, __src);
  memcpy(&re, RefAPI, 0x160u);
  Dvar_SetInt((dvar_s *)cl_paused, 0);
}

void __cdecl CL_Vid_Restart_f() {
  void *v7;            // edi
  char *v8;            // esi
  _DWORD *v9;          // ebx
  int v10;             // edx
  void *v11;           // eax
  char *v12;           // ebx
  int i;               // ecx
  _DWORD *v14;         // ebx
  int v15;             // edx
  int32_t __n;         // [esp+2Ch] [ebp-43Ch]
  char __str[1024];    // [esp+3Ch] [ebp-42Ch] BYREF
  MemoryFile __src[2]; // [esp+43Ch] [ebp-2Ch] BYREF

  if (*(_BYTE *)(com_sv_running + 8)) {
    Com_Printf("Listen server cannot video restart.\n");
  } else {
    if (byte_1509C49) {
      v11 = Z_VirtualAllocInternal((size_t)&unk_A00000);
      MemFile_InitForWriting(__src, (uint32_t)&unk_A00000, v11, 1u);
      CL_ArchiveClientState(__src);
      __n = __src[0].bytesUsed;
      v7 = Z_MallocInternal(__src[0].bytesUsed);
      memcpy(v7, __src[0].buffer, __n);
      Z_VirtualFreeInternal(__src[0].buffer);
    } else {
      v7 = 0;
      __n = 0;
    }
    Dvar_SetInt(com_expectedHunkUsage, 0);
    g_waitingForServer = 0;
    SND_StopSounds(SND_KEEP_REVERB);
    if (dword_1220964) {
      CL_ShutdownCGame(*(float *)&a2);
      CL_ShutdownUI(a1, *(float *)&a2, a3, a4, a5, a6, a7);
      dword_14C13B8 = 0;
      dword_14C13BC = 0;
      dword_14C13C0 = 0;
      dword_1220964 = 0;
    }
    if (dword_121C7E8)
      dword_121C7E8();
    if (re) {
      re(1);
      memset(&re, 0, 0x160u);
    }
    StatMon_Reset();
    dword_1220A68 = 0;
    v8 = va("vdr");
    v9 = clc;
    v10 = *((_DWORD *)clc + 76);
    if (!((v10 - *((_DWORD *)clc + 77) - 128 < 0) ^
              __OFADD__(-128, v10 - *((_DWORD *)clc + 77)) |
          (v10 - *((_DWORD *)clc + 77) == 128))) {
      Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                "EXE_ERR_CLIENT_CMD_OVERFLOW");
      v10 = v9[76];
    }
    v9[76] = v10 + 1;
    MSG_WriteReliableCommandToBuffer(
        v8, (char *)&v9[256 * (v9[76] & 0x7F) + 78], (char *)0x400);
    Com_Restart();
    Dvar_RegisterInt("loc_language", 0, 0, 13, 0x1021u);
    Dvar_RegisterBool("loc_translate", 1u, 0x1020u);
    Dvar_RegisterBool("fs_ignoreLocalized", 0, 0x10A0u);
    FS_ConditionalRestart(a1, *(float *)&a2, a3, a4, a5, a6, a7, v9[75]);
    SEH_UpdateLanguageInfo(a1, *(float *)&a2, a3, a4, a5, a6, a7);
    Dvar_SetInt((dvar_s *)cl_paused, 0);
    CL_InitRef();
    CL_StartHunkUsers(a1, *(float *)&a2, a3, a4, a5, a6, a7);
    if ((unsigned int)(*v9 - 6) <= 0x7FFFFFF9) {
      CL_InitCGame(a1, a2, a3, a4, a5, a6, a7);
      v12 = FS_ReferencedIwdPureChecksums();
      Com_sprintf(__str, 0x400u, "Va ");
      I_strncat(__str, 1024, v12);
      for (i = 0; i != 2; ++i)
        __str[i] += 2 * i + 13;
      v14 = clc;
      v15 = *((_DWORD *)clc + 76);
      if (!((v15 - *((_DWORD *)clc + 77) - 128 < 0) ^
                __OFADD__(-128, v15 - *((_DWORD *)clc + 77)) |
            (v15 - *((_DWORD *)clc + 77) == 128))) {
        Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                  "EXE_ERR_CLIENT_CMD_OVERFLOW");
        v15 = v14[76];
      }
      v14[76] = v15 + 1;
      MSG_WriteReliableCommandToBuffer(
          __str, (char *)&v14[256 * (v14[76] & 0x7F) + 78], (char *)0x400);
    }
    if (v7) {
      if (*((_BYTE *)cl + 9)) {
        MemFile_InitForReading(__src, __n, v7);
        CL_ArchiveClientState(__src);
      }
      Z_FreeInternal(v7);
    }
  }
}

void __cdecl CL_SetupForNewServerMap(char const *pszMapName,
                                     char const *pszGametype) {
  UNIMPLEMENTED();
}

void __cdecl CL_InitLoad(char const *mapname, char const *gametype) {
  UNIMPLEMENTED();
}

bool __cdecl CL_ConnectionlessPacket(struct netadr_t from, struct msg_t *msg,
                                     int time) {
  UNIMPLEMENTED();
}

void __cdecl CL_DownloadsComplete() { UNIMPLEMENTED(); }

bool __cdecl CL_PacketEvent(struct netadr_t from, struct msg_t *msg, int time) {
  UNIMPLEMENTED();
}

void __cdecl CL_ReadDemoMessage() {
  _DWORD *v7;                 // ebx
  int v8;                     // eax
  int v9;                     // edx
  unsigned __int8 v10[16384]; // [esp+14h] [ebp-4024h] BYREF
  msg_t v11;                  // [esp+4014h] [ebp-24h] BYREF
  char v12[12];               // [esp+402Ch] [ebp-Ch] BYREF

  if (!dword_1501BD0)
    goto LABEL_3;
  if (FS_Read(v12, 4u, dword_1501BD0) != 4)
    goto LABEL_3;
  v7 = clc;
  *(_DWORD *)((char *)&loc_20138 + (_DWORD)clc) = *(_DWORD *)v12;
  MSG_Init(&v11, v10, 0x4000u);
  if (FS_Read((char *)&v11.cursize, 4u, v7[66028]) != 4 || v11.cursize == -1)
    goto LABEL_3;
  if ((int)v11.cursize > (int)v11.maxsize)
    Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
              "\x15CL_ReadDemoMessage: demoMsglen > MAX_MSGLEN");
  v8 = FS_Read((char *)v11.data, v11.cursize, v7[66028]);
  if (v8 != v11.cursize) {
    Com_Printf("Demo file was truncated.\n");
  LABEL_3:
    CL_DemoCompleted(a1, a2, a3, a4, a5, a6, a7);
    return;
  }
  v7[4] = dword_1220A78;
  v11.readcount = 0;
  v7[77] = MSG_ReadLong(&v11);
  v9 = v7[76];
  if (v7[77] >= v9 - 128)
    CL_ParseServerMessage(a1, a2, a3, a4, a5, a6, a7, &v11);
  else
    v7[77] = v9;
}

void __cdecl CL_Frame(int msec) {
  int *v7;   // ebx
  int v8;    // eax
  int v9;    // eax
  int v10;   // edx
  int v11;   // edx
  char *v12; // eax
  char *v13; // edi
  int v14;   // edx

  if (!*(_DWORD *)(legacyHacks + 4))
    return;
  Voice_GetLocalVoiceData();
  Voice_Playback();
  CL_UpdateColor();
  v7 = (int *)clc;
  if (*(int *)clc <= 3) {
    v8 = cl_paused;
  } else {
    v8 = cl_paused;
    if (!*(_DWORD *)(cl_paused + 8)) {
      if ((dvar_modifiedFlags & 2) != 0) {
        dvar_modifiedFlags &= ~2u;
        v12 = Dvar_InfoString(2u);
        v13 = va("userinfo \"%s\"", v12);
        v14 = v7[76];
        if (!((v14 - v7[77] - 128 < 0) ^ __OFADD__(-128, v14 - v7[77]) |
              (v14 - v7[77] == 128))) {
          Com_Error(a3, *(float *)&a4, a5, a6, a1, a2, a7, 1,
                    "EXE_ERR_CLIENT_CMD_OVERFLOW");
          v14 = v7[76];
        }
        v7[76] = v14 + 1;
        MSG_WriteReliableCommandToBuffer(
            v13, (char *)&v7[256 * (v7[76] & 0x7F) + 78], (char *)0x400);
        v8 = cl_paused;
      } else {
        v8 = cl_paused;
      }
    }
  }
  if (*(_DWORD *)(v8 + 8) && *(_DWORD *)(sv_paused + 8))
    goto LABEL_6;
  v9 = *v7;
  if (*v7 <= 4) {
  LABEL_7:
    if ((unsigned int)(v9 - 3) <= 1) {
      v11 = v7[4];
      if (v11 > 0) {
        a5.f32[0] = (float)(dword_1220A78 - v11);
        HIDWORD(a4) = 0;
        *(float *)&a4 = 1000.0 * *(float *)(cl_connectTimeout + 8);
        if (a5.f32[0] > *(float *)&a4)
          goto LABEL_18;
      }
    }
    *((_DWORD *)cl + 5) = 0;
    goto LABEL_9;
  }
  if (v9 == 1 || v9 == 2 ||
      (a5.f32[0] = (float)(dword_1220A78 - v7[4]), HIDWORD(a4) = 0,
       *(float *)&a4 = 1000.0 * *(float *)(cl_timeout + 8),
       a5.f32[0] <= *(float *)&a4)) {
  LABEL_6:
    v9 = *v7;
    goto LABEL_7;
  }
  v10 = *((_DWORD *)cl + 5) + 1;
  *((_DWORD *)cl + 5) = v10;
  if (v10 > 5)
  LABEL_18:
    Com_Error(a3, *(float *)&a4, a5, a6, a1, a2, a7, 1,
              "EXE_ERR_SERVER_TIMEOUT");
LABEL_9:
  CL_CheckForResend(a3, *(float *)&a4, a5, a6, a1, a2, a7);
  if (*(_DWORD *)clc == 8) {
    if (!cl_ingame->current.enabled)
      Dvar_SetBool(cl_ingame, 1);
  } else if (cl_ingame->current.enabled) {
    Dvar_SetBool(cl_ingame, 0);
  }
  CL_SetCGameTime(a3, a4, a5, a6, a1, a2, a7);
  CL_SendCmd(a1, a2);
}

void __cdecl CL_PlayDemo_f() {
  const char *v7; // eax
  const char *v8; // esi
  void *v9;       // ebx
  char *v10;      // eax
  char *v11;      // eax
  char *v12;      // eax
  char *v13;      // eax
  char v14[256];  // [esp+20h] [ebp-138h] BYREF
  char __str[56]; // [esp+120h] [ebp-38h] BYREF

  if (Cmd_Argc() == 2) {
    if (*(_BYTE *)(com_sv_running + 8)) {
      Com_Printf("listen server cannot play a demo.\n");
    } else {
      CL_Disconnect(a1, *(float *)&a2, a3, a4, a5, a6, a7);
      v8 = (const char *)Cmd_Argv(1);
      Com_sprintf(__str, 0x20u, ".dm_%d", 1);
      if (I_stricmp((char *)&v8[strlen(v8) - strlen(__str)], __str))
        Com_sprintf(v14, 0x100u, "demos/%s.dm_%d", v8, 1);
      else
        Com_sprintf(v14, 0x100u, "demos/%s", v8);
      v9 = clc;
      FS_FOpenFileRead(v14, (int *)clc + 66028, 1);
      if (!*((_DWORD *)v9 + 66028)) {
        v13 = va("EXE_ERR_NOT_FOUND\x15%s", v14);
        Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1, v13);
      }
      v10 = (char *)Cmd_Argv(1);
      I_strncpyz((char *)v9 + 264028, v10, 64);
      Con_Close();
      *(_DWORD *)v9 = 5;
      *(_DWORD *)((char *)&loc_407A0 + (_DWORD)v9) = 1;
      v11 = (char *)Cmd_Argv(0);
      *(_DWORD *)((char *)&loc_407A4 + (_DWORD)v9) =
          I_stricmp(v11, "timedemo") == 0;
      v12 = (char *)Cmd_Argv(1);
      I_strncpyz(&byte_1220968, v12, 256);
      while ((unsigned int)(*(_DWORD *)v9 - 5) <= 1) {
        CL_ReadDemoMessage(a1, a2, a3, a4, a5, a6, a7);
        if ((unsigned int)(*(_DWORD *)v9 - 5) > 1)
          break;
        CL_ReadDemoMessage(a1, a2, a3, a4, a5, a6, a7);
      }
      *((_DWORD *)v9 + 66027) = 0;
    }
  } else {
    v7 = (const char *)Cmd_Argv(0);
    Com_Printf("%s <demoname>\n", v7);
  }
}

void __cdecl CL_InitOnceForAllClients() {
  unsigned int v0; // eax

  v0 = Sys_MillisecondsRaw();
  srand(v0);
  Con_Init();
  CL_InitInput();
  cl_noprint = (int)Dvar_RegisterBool("cl_noprint", 0, 0x1000u);
  cl_voice = (int)Dvar_RegisterBool("cl_voice", 1u, 0x1003u);
  cl_timeout = (int)Dvar_RegisterFloat("cl_timeout", (DvarValue)1128792064, 0.0,
                                       3600.0, 0x1000u);
  cl_connectTimeout = (int)Dvar_RegisterFloat(
      "cl_connectTimeout", (DvarValue)1128792064, 0.0, 3600.0, 0x1000u);
  cl_shownet = (int)Dvar_RegisterInt("cl_shownet", 0, -2, 4, 0x1000u);
  cl_shownuments = (int)Dvar_RegisterBool("cl_shownuments", 0, 0x1000u);
  cl_showServerCommands =
      (int)Dvar_RegisterBool("cl_showServerCommands", 0, 0x1000u);
  cl_showSend = (int)Dvar_RegisterBool("cl_showSend", 0, 0x1000u);
  cl_showTimeDelta = (int)Dvar_RegisterBool("cl_showTimeDelta", 0, 0x1000u);
  cl_freezeDemo = (int)Dvar_RegisterBool("cl_freezeDemo", 0, 0x1000u);
  cl_activeAction =
      (int)Dvar_RegisterString("activeAction", (DvarValue)&inData, 0x1000u);
  cl_avidemo = (int)Dvar_RegisterInt("cl_avidemo", 0, 0, 0x7FFFFFFF, 0x1000u);
  cl_forceavidemo = (int)Dvar_RegisterBool("cl_forceavidemo", 0, 0x1000u);
  cl_yawspeed = (int)Dvar_RegisterFloat("cl_yawspeed", (DvarValue)1124859904,
                                        -3.4028235e38, 3.4028235e38, 0x1001u);
  cl_pitchspeed =
      (int)Dvar_RegisterFloat("cl_pitchspeed", (DvarValue)1124859904,
                              -3.4028235e38, 3.4028235e38, 0x1001u);
  cl_anglespeedkey = (int)Dvar_RegisterFloat(
      "cl_anglespeedkey", (DvarValue)1069547520, 0.0, 3.4028235e38, 0x1000u);
  cl_maxpackets = (int)Dvar_RegisterInt("cl_maxpackets", 30, 15, 100, 0x1001u);
  cl_packetdup = (int)Dvar_RegisterInt("cl_packetdup", 1, 0, 5, 0x1001u);
  cl_sensitivity = (int)Dvar_RegisterFloat("sensitivity", (DvarValue)1084227584,
                                           0.0099999998, 100.0, 0x1001u);
  cl_mouseAccel =
      (int)Dvar_RegisterFloat("cl_mouseAccel", 0, 0.0, 100.0, 0x1001u);
  cl_freelook = (int)Dvar_RegisterBool("cl_freelook", 1u, 0x1001u);
  cl_showMouseRate = (int)Dvar_RegisterBool("cl_showmouserate", 0, 0x1000u);
  cl_allowDownload = (int)Dvar_RegisterBool("cl_allowDownload", 1u, 0x1001u);
  cl_talking = Dvar_RegisterBool("cl_talking", 0, 0x1000u);
  cl_inGameVideo = (int)Dvar_RegisterBool("r_inGameVideo", 1u, 0x1001u);
  cl_serverStatusResendTime =
      (int)Dvar_RegisterInt("cl_serverStatusResendTime", 750, 0, 3600, 0x1000u);
  cl_bypassMouseInput =
      (int)Dvar_RegisterBool("cl_bypassMouseInput", 0, 0x1000u);
  m_pitch = (int)Dvar_RegisterFloat(stru_2A8F04.name, (DvarValue)1018444120,
                                    -1.0, 1.0, 0x1001u);
  m_yaw = (int)Dvar_RegisterFloat((char *)&stru_2A8F04.current,
                                  (DvarValue)1018444120, -1.0, 1.0, 0x1001u);
  m_forward = (int)Dvar_RegisterFloat(
      (char *)&stru_2A8F04.reset, (DvarValue)1048576000, -1.0, 1.0, 0x1001u);
  m_side = (int)Dvar_RegisterFloat((char *)&stru_2A8F04.next,
                                   (DvarValue)1048576000, -1.0, 1.0, 0x1001u);
  m_filter = (int)Dvar_RegisterBool("m_filter", 0, 0x1001u);
  input_viewSensitivity =
      (int)Dvar_RegisterFloat("input_viewSensitivity", (DvarValue)1065353216,
                              0.000099999997, 5.0, 0x1001u);
  cg_drawCrosshair = Dvar_RegisterBool("cg_drawCrosshair", 1u, 0x1001u);
  cl_motdString =
      (int)Dvar_RegisterString("cl_motdString", (DvarValue)&inData, 0x1040u);
  cl_ingame = Dvar_RegisterBool("cl_ingame", 0, 0x1040u);
  Dvar_RegisterInt("cl_maxPing", 800, 20, 2000, 0x1001u);
  name =
      (int)Dvar_RegisterString("name", (DvarValue) "Unknown Soldier", 0x1003u);
  Dvar_RegisterInt("rate", 5000, 1000, 25000, 0x1003u);
  Dvar_RegisterInt("snaps", 20, 1, 30, 0x1003u);
  Dvar_RegisterString("password", (DvarValue)&inData, 0x1002u);
  fx_enable = (int)Dvar_RegisterBool("fx_enable", 1u, 0x1080u);
  fx_draw = (int)Dvar_RegisterBool("fx_draw", 1u, 0x1080u);
  fx_cull = (int)Dvar_RegisterBool("fx_cull", 1u, 0x1000u);
  fx_sort = (int)Dvar_RegisterBool("fx_sort", 1u, 0x1000u);
  fx_freeze = (int)Dvar_RegisterBool("fx_freeze", 0, 0x1080u);
  fx_debug = (int)Dvar_RegisterBool("fx_debug", 0, 0x1080u);
  fx_debugBolt =
      (int)Dvar_RegisterFloat("fx_debugBolt", 0, 0.0, 100.0, 0x1080u);
  fx_count = (int)Dvar_RegisterBool("fx_count", 0, 0x1080u);
  fx_visMinTraceDist = (int)Dvar_RegisterFloat(
      "fx_visMinTraceDist", (DvarValue)1117782016, 0.0, 1000.0, 0x1080u);
  fx_profile = (int)Dvar_RegisterBool("fx_profile", 0, 0x1080u);
  nextdemo = (int)Dvar_RegisterString("nextdemo", (DvarValue)&inData, 0x1000u);
  Dvar_RegisterBool("hud_enable", 1u, 0x1001u);
  Dvar_RegisterBool("cg_blood", 1u, 0x1001u);
  Cmd_AddCommand("cmd", (void (*)(void))CL_ForwardToServer_f);
  Cmd_AddCommand("configstrings", CL_Configstrings_f);
  Cmd_AddCommand("clientinfo", CL_Clientinfo_f);
  Cmd_AddCommand("vid_restart", (void (*)(void))CL_Vid_Restart_f);
  Cmd_AddCommand("snd_restart", (void (*)(void))CL_Snd_Restart_f);
  Cmd_AddCommand("disconnect", (void (*)(void))CL_Disconnect_f);
  Cmd_AddCommand("record", CL_Record_f);
  Cmd_AddCommand("stoprecord", CL_StopRecord_f);
  Cmd_AddCommand("demo", (void (*)(void))CL_PlayDemo_f);
  Cmd_AddCommand("timedemo", (void (*)(void))CL_PlayDemo_f);
  Cmd_SetAutoComplete("demo", "demos", "dm_1");
  Cmd_SetAutoComplete("timedemo", "demos", "dm_1");
  Cmd_AddCommand("cinematic", (void (*)(void))CL_PlayCinematic_f);
  Cmd_SetAutoComplete("cinematic", "video", "roq");
  Cmd_AddCommand("logo", (void (*)(void))CL_PlayLogo_f);
  Cmd_AddCommand("connect", (void (*)(void))CL_Connect_f);
  Cmd_AddCommand("reconnect", CL_Reconnect_f);
  Cmd_AddCommand("localservers", (void (*)(void))CL_LocalServers_f);
  Cmd_AddCommand("globalservers", (void (*)(void))CL_GlobalServers_f);
  CL_RconInit();
  Cmd_AddCommand("rcon", (void (*)(void))CL_Rcon_f);
  Cmd_AddCommand("ping", (void (*)(void))CL_Ping_f);
  Cmd_AddCommand("serverstatus", (void (*)(void))CL_ServerStatus_f);
  Cmd_AddCommand("toggleMenu", (void (*)(void))CL_ToggleMenu_f);
  Cmd_AddCommand("setenv", CL_Setenv_f);
  Cmd_AddCommand("showip", CL_ShowIP_f);
  Cmd_AddCommand("fs_openedList", CL_OpenedIWDList_f);
  Cmd_AddCommand("fs_referencedList", CL_ReferencedIWDList_f);
  Cmd_AddCommand("updatehunkusage", (void (*)(void))CL_UpdateLevelHunkUsage);
  Cmd_AddCommand("updatescreen", (void (*)(void))SCR_UpdateScreen);
  Cmd_AddCommand("startSingleplayer", CL_startSingleplayer_f);
  Cmd_AddCommand("setRecommended", CL_SetRecommended_f);
  Cmd_AddCommand("cubemapShot", (void (*)(void))CL_CubemapShot_f);
  Cmd_AddCommand("openScriptMenu", CL_OpenScriptMenu_f);
  Cmd_AddCommand("localizeSoundAliasFiles",
                 (void (*)(void))Com_WriteLocalizedSoundAliasFiles);
  Cmd_AddCommand("openmenu", (void (*)(void))UI_OpenMenu_f);
  Cmd_AddCommand("closemenu", (void (*)(void))UI_CloseMenu_f);
  CL_InitRef();
  SCR_Init();
}

struct clientActive_t *cl;
struct clientConnection_t *clc;
bool g_waitingForServer;
struct dvar_s const *const cl_conXOffset;
struct dvar_s const *const cl_showSend;
struct dvar_s const *const fx_enable;
struct dvar_s const *const cl_returnToSplitscreenGameSetupScreenOnDisconnect;
struct dvar_s const *const fx_sort;
struct dvar_s const *const cl_avidemo;
struct clientConnection_t *clientConnections;
struct refexport_t re;
struct dvar_s const *const cl_nodelta;
struct dvar_s const *const cl_showServerCommands;
struct dvar_s const *const cl_connectTimeout;
struct dvar_s const *const cl_sensitivity;
struct dvar_s const *const cl_forceavidemo;
struct dvar_s const *const cl_timeout;
struct dvar_s const *const cl_returnToXenonLiveScreenOnDisconnect;
struct dvar_s const *const m_yaw;
struct dvar_s const *const cl_returnToSystemLinkGameSetupScreenOnDisconnect;
struct dvar_s const *const m_pitch;
struct dvar_s const *const cl_activeAction;
struct dvar_s const *const nextdemo;
struct clientStatic_t cls;
struct ping_t *cl_pinglist;
struct dvar_s const *const fx_freeze;
int old_com_frameTime;
struct dvar_s const *const fx_debugBolt;
struct dvar_s const *const cl_showMouseRate;
struct dvar_s const *const fx_count;
struct dvar_s const *const fx_visMinTraceDist;
unsigned int frame_msec;
struct dvar_s const *const m_forward;
struct dvar_s const *const cl_packetdup;
struct dvar_s const *const cl_mouseAccel;
struct dvar_s const *const cl_maxpackets;
struct dvar_s const *const cl_motdString;
struct dvar_s const *const cl_freezeDemo;
struct dvar_s const *const cl_showTimeDelta;
struct dvar_s const *const fx_draw;
struct dvar_s const *const fx_profile;
struct dvar_s const *const fx_debug;
struct dvar_s const *const cl_ingame;
struct dvar_s const *const cl_inGameVideo;
struct dvar_s const *const name;
struct dvar_s const *const cl_noprint;
struct dvar_s const *const m_side;
struct dvar_s const *const cl_serverStatusResendTime;
struct dvar_s const *const m_filter;
struct dvar_s const *const cl_returnToSystemLinkJoinGameScreenOnDisconnect;
struct dvar_s const *const fx_cull;
struct clientActive_t *clients;
struct dvar_s const *const cl_shownuments;
struct dvar_s const *const cl_freelook;
struct dvar_s const *const cl_shownet;
int g_localClientNum;
void __cdecl CL_ShutdownRenderer(void) { UNIMPLEMENTED(); }

CL_ShutdownDemo() { UNIMPLEMENTED(); }

CL_OpenedIWDList_f() { UNIMPLEMENTED(); }

CL_ReferencedIWDList_f() { UNIMPLEMENTED(); }

Voice_SendVoiceData() { UNIMPLEMENTED(); }

CL_SyncGpu() { UNIMPLEMENTED(); }

CL_SetRecommended_f() { UNIMPLEMENTED(); }

CL_OpenScriptMenu_f() { UNIMPLEMENTED(); }

Client_SendVoiceData(int bytes, char *enc_buffer) { UNIMPLEMENTED(); }

CL_BeginDownload(char const *localName, char const *remoteName) {
  UNIMPLEMENTED();
}

CL_NextDownload() { UNIMPLEMENTED(); }

CL_InitDownloads() { UNIMPLEMENTED(); }
