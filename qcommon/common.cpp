char com_errorMessage[4096];

char __cdecl Com_GetDecimalDelimiter()
{
  DvarValue current; // edx

  current = loc_language->current;
  if ((unsigned int)(current.integer - 1) <= 3 || current.integer == 6 ||
      current.integer == 7)
    return 44;
  else
    return 46;
}

int __cdecl Com_AddToString(char const *add, char *msg, int len, int maxlen,
                            int mayAddQuotes)
{
  int result; // eax
  char v6;    // dl
  int v7;     // ecx
  int v8;     // edx
  char v9;    // cl
  int v10;    // [esp+0h] [ebp-14h]
  int v11;    // [esp+4h] [ebp-10h]

  result = a3;
  if (!a5)
    goto LABEL_10;
  if (!*a1)
    goto LABEL_3;
    if (a4 - a3 <= 0) {
    LABEL_10:
      v11 = 0;
      if (a3 >= a4)
        goto LABEL_5;
      goto LABEL_11;
    }
    if (*a1 > 32) {
      v8 = 0;
        while (a4 - a3 != ++v8) {
          v9 = a1[v8];
          if (!v9)
            break;
          if (v9 <= 32)
            goto LABEL_3;
        }
      goto LABEL_10;
    }
LABEL_3:
    if (a3 < a4) {
      a2[a3] = 34;
      result = a3 + 1;
      v11 = 1;
      if (a3 + 1 >= a4)
        goto LABEL_5;
    LABEL_11:
      v6 = *a1;
        if (*a1) {
          v7 = 1;
            while (1) {
              a2[result - 1 + v7] = v6;
              v10 = result + v7;
              if (v7 == a4 - result)
                break;
              v6 = a1[v7++];
                if (!v6) {
                  result = v10;
                  goto LABEL_5;
                }
            }
          result += v7;
        }
    LABEL_5:
      if (!v11)
        return result;
    }
  if (a4 > result)
    a2[result++] = 34;
  return result;
}

void __cdecl Com_SetWeaponInfoMemory(int iSource)
{
  int result; // eax

  result = a1;
  iWeaponInfoSource = a1;
  return result;
}

void __cdecl Field_Clear(struct field_t *edit)
{
  void *result; // eax

  result = memset(a1->buffer, 0, sizeof(a1->buffer));
  a1->cursor = 0;
  a1->scroll = 0;
  a1->drawWidth = 256;
  return result;
}

void __cdecl Com_CheckSyncFrame(void)
{
  UNIMPLEMENTED();
}

float __cdecl Com_GetTimescaleForSnd()
{
  int v0; // eax

  v0 = *(_DWORD *)(com_fixedtime + 8);
  if (v0)
    return (float)v0;
  else
    return *(float *)(com_timescale + 8);
}

void __cdecl Com_SetScriptSettings(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ShutdownEvents()
{
  int i;    // edx
  void *v1; // ecx

    for (i = com_pushedEventsTail; com_pushedEventsHead > i; ++i) {
        while (1) {
          v1 = (void *)dword_33A914[6 * (unsigned __int8)i];
          com_pushedEventsTail = i + 1;
          if (!v1)
            break;
          Z_FreeInternal(v1);
          i = com_pushedEventsTail;
          if (com_pushedEventsHead <= com_pushedEventsTail)
            return;
        }
    }
}

void __cdecl Com_PushEvent(struct sysEvent_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_InitPushEvent(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ForceSafeMode(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ParseCommandLine(char *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_SetTimeScale(float)
{
  UNIMPLEMENTED();
}

void __cdecl Com_DPrintf(char const *fmt, ...)
{
  char __str[4096]; // [esp+1Ch] [ebp-100Ch] BYREF
  va_list v2;       // [esp+101Ch] [ebp-Ch]
  va_list va;       // [esp+1034h] [ebp+Ch] BYREF

  va_start(va, __format);
    if (com_developer) {
        if (*(_DWORD *)(com_developer + 8)) {
          va_copy(v2, va);
          vsnprintf(__str, 0x1000u, __format, va);
          __str[4095] = 0;
          Com_Printf("%s", __str);
        }
    }
}

void __cdecl Com_LocalizedFloatToString(float f, char *buffer,
                                        unsigned int maxlen,
                                        unsigned int numDecimalPlaces)
{
  DvarValue current; // edx
  char *result;      // eax
  int v6;            // edx

  snprintf(__str, a3 - 1, "%.*f", a4, a1);
  __str[a3 - 1] = 0;
  current = loc_language->current;
  result = (char *)(current.integer - 1);
    if (((unsigned int)(current.integer - 1) <= 3 || current.integer == 6 ||
         current.integer == 7) &&
        a3) {
        if (*__str == 46) {
          result = __str;
          *__str = 44;
        }
        else {
          v6 = 0;
            while (a3 != ++v6) {
              result = &__str[v6];
                if (__str[v6] == 46) {
                  *result = 44;
                  return result;
                }
            }
        }
    }
  return result;
}

void __cdecl Com_CloseLogfiles(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ResetFrametime(void)
{
  UNIMPLEMENTED();
}

int __cdecl Com_AddStartupCommands(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_FreeWeaponInfoMemory(int iSource)
{
    if (iWeaponInfoSource == a1) {
      iWeaponInfoSource = 0;
      BG_ShutdownWeaponDefFiles();
    }
}

void __cdecl Com_PumpMessageLoop()
{
  int v0;     // edx
  int v1;     // esi
  int result; // eax
  int *v3;    // ebx
  int v4;     // [esp+10h] [ebp-58h] BYREF
  int v5;     // [esp+14h] [ebp-54h]
  int v6;     // [esp+18h] [ebp-50h]
  int v7;     // [esp+1Ch] [ebp-4Ch]
  int v8;     // [esp+20h] [ebp-48h]
  int v9;     // [esp+24h] [ebp-44h]
  int v10;    // [esp+38h] [ebp-30h]
  int v11;    // [esp+3Ch] [ebp-2Ch]
  int v12;    // [esp+40h] [ebp-28h]
  int v13;    // [esp+44h] [ebp-24h]
  int v14;    // [esp+48h] [ebp-20h]
  int v15;    // [esp+4Ch] [ebp-1Ch]

    while (1) {
      Sys_GetEvent(&v4);
      v10 = v4;
      v1 = v5;
      v11 = v5;
      v12 = v6;
      v13 = v7;
      v14 = v8;
      result = v9;
      v15 = v9;
      if (!v5)
        break;
      v0 = com_pushedEventsHead;
      v3 = &com_pushedEvents[6 * (unsigned __int8)com_pushedEventsHead];
        if (com_pushedEventsHead - com_pushedEventsTail > 255) {
            if (!Com_PushEvent(sysEvent_t *)::printedWarning) {
              Com_PushEvent(sysEvent_t *)::printedWarning = 1;
              Com_Printf("WARNING: Com_PushEvent overflow\n");
            }
          if (v3[5])
            Z_FreeInternal((void *)v3[5]);
          ++com_pushedEventsTail;
          v0 = com_pushedEventsHead;
        }
        else {
          Com_PushEvent(sysEvent_t *)::printedWarning = 0;
        }
      v11 = v1;
      *v3 = v10;
      v3[1] = v1;
      v3[2] = v12;
      v3[3] = v13;
      v3[4] = v14;
      v3[5] = v15;
      com_pushedEventsHead = v0 + 1;
    }
  return result;
}

int __cdecl Com_Milliseconds()
{
  int v0;  // edx
  int v1;  // edi
  int v2;  // esi
  int *v3; // ebx
  int v5;  // [esp+10h] [ebp-58h] BYREF
  int v6;  // [esp+14h] [ebp-54h]
  int v7;  // [esp+18h] [ebp-50h]
  int v8;  // [esp+1Ch] [ebp-4Ch]
  int v9;  // [esp+20h] [ebp-48h]
  int v10; // [esp+24h] [ebp-44h]
  int v11; // [esp+38h] [ebp-30h]
  int v12; // [esp+3Ch] [ebp-2Ch]
  int v13; // [esp+40h] [ebp-28h]
  int v14; // [esp+44h] [ebp-24h]
  int v15; // [esp+48h] [ebp-20h]
  int v16; // [esp+4Ch] [ebp-1Ch]

    while (1) {
      Sys_GetEvent(&v5);
      v1 = v5;
      v11 = v5;
      v2 = v6;
      v12 = v6;
      v13 = v7;
      v14 = v8;
      v15 = v9;
      v16 = v10;
      if (!v6)
        break;
      v0 = com_pushedEventsHead;
      v3 = &com_pushedEvents[6 * (unsigned __int8)com_pushedEventsHead];
        if (com_pushedEventsHead - com_pushedEventsTail > 255) {
            if (!Com_PushEvent(sysEvent_t *)::printedWarning) {
              Com_PushEvent(sysEvent_t *)::printedWarning = 1;
              Com_Printf("WARNING: Com_PushEvent overflow\n");
            }
          if (v3[5])
            Z_FreeInternal((void *)v3[5]);
          ++com_pushedEventsTail;
          v0 = com_pushedEventsHead;
        }
        else {
          Com_PushEvent(sysEvent_t *)::printedWarning = 0;
        }
      v11 = v1;
      v12 = v2;
      *v3 = v1;
      v3[1] = v2;
      v3[2] = v13;
      v3[3] = v14;
      v3[4] = v15;
      v3[5] = v16;
      com_pushedEventsHead = v0 + 1;
    }
  return v5;
}

struct sysEvent_t __cdecl Com_GetEvent(void)
{
  UNIMPLEMENTED();
}

int __cdecl Com_SafeMode()
{
  int v1;   // esi
  char **i; // ebx
  char *v3; // eax
  char *v4; // eax

  if (com_numConsoleLines <= 0)
    return com_safemode;
  v1 = 0;
    for (i = (char **)com_consoleLines;; ++i) {
      Cmd_TokenizeString(*i);
      v4 = (char *)Cmd_Argv(0);
      if (!I_stricmp(v4, "safe"))
        break;
      v3 = (char *)Cmd_Argv(0);
      if (!I_stricmp(v3, "dvar_restart"))
        break;
      if (++v1 >= com_numConsoleLines)
        return com_safemode;
    }
  *(_BYTE *)com_consoleLines[v1] = 0;
  return 1;
}

void *__cdecl MT_AllocAnimTree(int)
{
  UNIMPLEMENTED();
}

struct XAnimTree_s *__cdecl Com_XAnimCreateSmallTree(struct XAnim_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_XAnimFreeSmallTree(struct XAnimTree_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_RunAutoExec(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ExecStartupConfigs(char const *configFile)
{
  char *v1; // eax

  Cbuf_AddText("exec default_mp.cfg\n");
  Cbuf_AddText("exec language.cfg\n");
    if (a1) {
      v1 = va("exec %s\n", a1);
      Cbuf_AddText(v1);
    }
  Cbuf_Execute();
  Dvar_SetInAutoExec(1);
  Cbuf_Execute();
  Dvar_SetInAutoExec(0);
  if (Com_SafeMode())
    Cbuf_AddText("exec safemode_mp.cfg\n");
  Cbuf_Execute();
}

int __cdecl Debug_EventLoop()
{
  UNIMPLEMENTED();
}

void __cdecl Com_ReadCDKey()
{
  int result;    // eax
  char __dst[4]; // [esp+1Bh] [ebp-1Dh] BYREF
  int v2;        // [esp+1Fh] [ebp-19h]
  int v3;        // [esp+23h] [ebp-15h]
  int v4;        // [esp+27h] [ebp-11h]
  int v5;        // [esp+2Bh] [ebp-Dh]

  result = MacPreferences::GetString((MacPreferences *)"codkey", __dst, 21, 0);
  if (!(_BYTE)result)
    goto LABEL_3;
  *(_DWORD *)cl_cdkey = *(_DWORD *)__dst;
  dword_308B70 = v2;
  dword_308B74 = v3;
  dword_308B78 = v4;
  byte_308B7C = 0;
  *(_DWORD *)cl_cdkeychecksum = v5;
  byte_308B64 = 0;
  result = CL_CDKeyValidate(cl_cdkey, cl_cdkeychecksum);
  if (!result)
  LABEL_3:
    strcpy(cl_cdkey, "                ");
  return result;
}

void __cdecl Com_PrintMessage(enum print_msg_type_t type, char const *msg)
{
  char *v2;  // esi
  char *v3;  // ebx
  int v4;    // edx
  int v5;    // eax
  tm *v6;    // ebx
  char *v7;  // eax
  time_t v8; // [esp+2Ch] [ebp-1Ch] BYREF

  v2 = __src;
  v3 = rd_buffer;
    if (rd_buffer) {
        if (a1 != PMSG_LOGFILE) {
          v4 = rd_buffersize;
            if (strlen(rd_buffer) + 1 + strlen(__src) + 1 - 2 >
                rd_buffersize - 1) {
              rd_flush(rd_buffer);
              *rd_buffer = 0;
              v3 = rd_buffer;
              v4 = rd_buffersize;
            }
          I_strncat(v3, v4, __src);
        }
    }
    else {
      if (a1 != PMSG_LOGFILE && com_dedicated &&
          !*(_DWORD *)(com_dedicated + 8))
        CL_ConsolePrint(a1, __src, 0, PMSG_CONSOLE);
      if (*__src == 94 && __src[1])
        v2 = __src + 2;
      if (a1 != PMSG_LOGFILE)
        Sys_Print(v2);
        if (com_logfile) {
            if (*(_DWORD *)(com_logfile + 8)) {
                if (FS_Initialized()) {
                  v5 = logfile;
                  if (logfile)
                    goto LABEL_18;
                    if (!Com_PrintMessage(print_msg_type_t,
                                          char const *)::opening_qconsole) {
                      Com_PrintMessage(print_msg_type_t,
                                       char const *)::opening_qconsole = 1;
                      time(&v8);
                      v6 = localtime(&v8);
                      logfile = FS_FOpenTextFileWrite("console_mp.log");
                      v7 = asctime(v6);
                      Com_Printf("logfile opened on %s\n", v7);
                      Com_PrintMessage(print_msg_type_t,
                                       char const *)::opening_qconsole = 0;
                      v5 = logfile;
                        if (logfile) {
                        LABEL_18:
                          FS_Write(v2, strlen(v2), v5);
                          if (*(int *)(com_logfile + 8) > 1)
                            FS_Flush(logfile);
                        }
                    }
                }
            }
        }
    }
}

void __cdecl Com_Printf(char const *fmt, ...)
{
  char __str[4096]; // [esp+1Ch] [ebp-100Ch] BYREF
  va_list v2;       // [esp+101Ch] [ebp-Ch]
  va_list va;       // [esp+1034h] [ebp+Ch] BYREF

  va_start(va, __format);
  va_copy(v2, va);
  vsnprintf(__str, 0x1000u, __format, va);
  __str[4095] = 0;
  Com_PrintMessage(PMSG_CONSOLE, __str);
}

void __cdecl Com_WriteDefaultsToFile(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_WriteCDKey()
{
  char v0[29]; // [esp+1Bh] [ebp-1Dh] BYREF

    if (CL_CDKeyValidate(cl_cdkey, cl_cdkeychecksum)) {
      strcpy(v0, "                    ");
      MacPreferences::PutString((MacPreferences *)"codkey", v0);
    }
    else {
      strcpy(cl_cdkey, "                ");
    }
}

void __cdecl Info_Print(char const *s)
{
  const char *v1; // ebx
  char v2;        // al
  char *v3;       // edx
  int v4;         // ecx
  char *v5;       // ebx
  char v6;        // al
  char *v7;       // edx
  char v8[512];   // [esp+10h] [ebp-408h] BYREF
  char v9;        // [esp+210h] [ebp-208h] BYREF
  _BYTE __b[519]; // [esp+211h] [ebp-207h] BYREF

  v1 = a1;
  if (*a1 == 92)
    v1 = a1 + 1;
    if (*v1) {
        while (1) {
            if (*v1 == 92) {
              v3 = &v9;
            }
            else {
              v9 = *v1++;
              v2 = *v1;
                if (*v1) {
                  v3 = __b;
                    while (v2 != 92) {
                      *v3++ = v2;
                      v2 = *++v1;
                        if (!*v1) {
                          v4 = v3 - &v9;
                          if (v3 - &v9 > 19)
                            goto LABEL_8;
                          goto LABEL_22;
                        }
                    }
                }
                else {
                  v3 = __b;
                }
            }
          v4 = v3 - &v9;
            if (v3 - &v9 <= 19) {
            LABEL_22:
              memset(v3, 32, 20 - v4);
              __b[19] = 0;
              Com_Printf("%s", &v9);
                if (!*v1) {
                LABEL_23:
                  Com_Printf("MISSING VALUE\n");
                  return;
                }
            }
            else {
            LABEL_8:
              *v3 = 0;
              Com_Printf("%s", &v9);
              if (!*v1)
                goto LABEL_23;
            }
          v5 = (char *)(v1 + 1);
          v6 = *v5;
            if (!*v5 || v6 == 92) {
              v8[0] = 0;
              v1 = &v5[-(*v5 == 0) + 1];
              Com_Printf("%s\n", v8);
              if (!*v1)
                return;
            }
            else {
              v7 = v8;
                do {
                  *v7++ = v6;
                  v6 = *++v5;
                }
              while (*v5 && v6 != 92);
              *v7 = 0;
              v1 = &v5[-(*v5 == 0) + 1];
              Com_Printf("%s\n", v8);
              if (!*v1)
                return;
            }
        }
    }
}

void __cdecl Com_WriteDefaults_f()
{
  char *v0;       // eax
  int v1;         // eax
  int v2;         // ebx
  char __dst[72]; // [esp+10h] [ebp-48h] BYREF

    if (Cmd_Argc() == 2) {
      v0 = (char *)Cmd_Argv(1);
      I_strncpyz(__dst, v0, 64);
      Com_DefaultExtension(__dst, 0x40u, ".cfg");
      Com_Printf("Writing %s.\n", __dst);
      v1 = FS_FOpenFileWrite(__dst);
      v2 = v1;
        if (v1) {
          FS_Printf(v1, "// generated by Call of Duty, do not modify\n");
          Dvar_WriteDefaults(v2);
          FS_FCloseFile(v2);
        }
        else {
          Com_Printf("Couldn't write %s.\n", __dst);
        }
    }
    else {
      Com_Printf("Usage: writedefaults <filename>\n");
    }
}

void __cdecl Com_WriteConfig_f()
{
  char *v0;       // eax
  char __dst[72]; // [esp+10h] [ebp-48h] BYREF

    if (Cmd_Argc() == 2) {
      v0 = (char *)Cmd_Argv(1);
      I_strncpyz(__dst, v0, 64);
      Com_DefaultExtension(__dst, 0x40u, ".cfg");
      Com_Printf("Writing %s.\n", __dst);
      Com_WriteConfigToFile(__dst);
    }
    else {
      Com_Printf("Usage: writeconfig <filename>\n");
    }
}

void __cdecl Com_WriteConfiguration(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_StartupVariable(char const *match)
{
  int v1;         // esi
  char **v2;      // ebx
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax

    if (com_numConsoleLines > 0) {
      v1 = 0;
      v2 = (char **)com_consoleLines;
        if (__s2) {
            do {
              Cmd_TokenizeString(*v2);
              v3 = (const char *)Cmd_Argv(1);
                if (!strcmp(v3, __s2)) {
                  v4 = (const char *)Cmd_Argv(0);
                    if (!stricmp(v4, "set")) {
                      Dvar_Set_f();
                    }
                    else {
                      v5 = (const char *)Cmd_Argv(0);
                      if (!stricmp(v5, "seta"))
                        Dvar_SetA_f();
                    }
                }
              ++v1;
              ++v2;
            }
          while (v1 < com_numConsoleLines);
        }
        else {
            do {
              Cmd_TokenizeString(*v2);
              v6 = (const char *)Cmd_Argv(0);
                if (!stricmp(v6, "set")) {
                  Dvar_Set_f();
                }
                else {
                  v7 = (const char *)Cmd_Argv(0);
                  if (!stricmp(v7, "seta"))
                    Dvar_SetA_f();
                }
              ++v1;
              ++v2;
            }
          while (v1 < com_numConsoleLines);
        }
    }
}

void __cdecl Com_Close()
{
  Com_ShutdownDObj();
  DObjShutdown(a1);
  XAnimShutdown(a1);
  CM_Shutdown();
  SND_ShutdownChannels();
  Hunk_Clear(a1);
  Scr_Shutdown(a1);
}

void __cdecl Com_SyncThreads(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_Restart()
{
  _BOOL4 v0; // ecx

  CL_ShutdownHunkUsers();
  SV_ShutdownGameProgs();
  CIN_CloseAllVideos();
  Com_ShutdownDObj();
  DObjShutdown();
  XAnimShutdown();
  CM_Shutdown();
  SND_ShutdownChannels();
  Hunk_Clear();
  Scr_Init();
  v0 = *(_DWORD *)(com_developer + 8) || *(_DWORD *)(com_logfile + 8);
  Scr_Settings(v0, *(unsigned __int8 *)(com_developer_script + 8),
               *(_DWORD *)(com_developer + 8));
  com_fixedConsolePosition = 0;
  XAnimInit();
  DObjInit();
  return Com_InitDObj();
}

void __cdecl Com_AssetLoadUI(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_Quit_f()
{
  Com_Printf("quitting...\n");
    if (!com_errorEntered) {
      Hunk_ClearTempMemory();
      Hunk_ClearTempMemoryHigh();
      Sys_DestroySplashWindow();
      CL_SwitchToLocalClient(0);
      CL_Shutdown();
      CL_SwitchToLocalClient(0);
      SV_Shutdown("EXE_SERVERQUIT");
      Com_Close();
        if (logfile) {
          FS_FCloseFile(logfile);
          logfile = 0;
        }
      FS_Shutdown(1);
      FS_ShutdownServerIwdNames();
      FS_ShutdownServerReferencedIwds();
    }
  Sys_Quit();
}

void __cdecl Com_ShutdownInternal(char *finalmsg)
{
  UNIMPLEMENTED();
}

void __cdecl Com_Shutdown(char *finalmsg)
{
  UNIMPLEMENTED();
}

int __cdecl Com_EventLoop()
{
  UNIMPLEMENTED();
}

void Com_Frame_Try_Block_Function(void)
{
  const dvar_s *v0; // edx
  int v1;           // edx
  int v2;           // ebx
  int v3;           // eax
  int v4;           // edx
  int v5;           // esi
  int v6;           // ebx
  float v7;         // xmm1_4
  int v8;           // edi
  float v9;         // xmm1_4
  dvar_s *v10;      // eax
  DvarValue result; // eax
  int v12;          // ebx
  int v13;          // edx
  const char *v14;  // [esp+0h] [ebp-88h]
  float v15;        // [esp+28h] [ebp-60h]
  char v16;         // [esp+2Fh] [ebp-59h]
  char __str[88];   // [esp+30h] [ebp-58h] BYREF

    if (com_fullyInitialized) {
        if ((dvar_modifiedFlags & 1) != 0) {
          dvar_modifiedFlags &= ~1u;
            if ((unsigned __int8)Com_HasPlayerProfile()) {
              Com_BuildPlayerProfilePath(__str, 0x40u, "config_mp.cfg");
              Com_WriteConfigToFile(v14);
            }
        }
    }
  v0 = com_viewlog;
    if (com_viewlog->modified) {
        if (!com_dedicated->current.integer) {
          Sys_ShowConsole(com_viewlog->current.integer, 0);
          v0 = com_viewlog;
        }
      Dvar_ClearModified(v0);
    }
  SetAnimCheck(*(unsigned __int8 *)(com_animCheck + 8));
  v1 = *(_DWORD *)(com_maxfps + 8);
  if (v1 <= 0 || com_dedicated->current.integer || (v2 = 1000 / v1) == 0)
    v2 = 1;
    while (1) {
      v3 = Com_EventLoop();
      com_frameTime = v3;
      v4 = com_lastFrameTime;
      if (v3 < com_lastFrameTime)
        v4 = v3;
      com_lastFrameTime = v4;
      v5 = v3 - v4;
      if (v3 - v4 >= v2)
        break;
      NET_Sleep(0);
    }
  Cbuf_Execute();
  com_lastFrameTime = com_frameTime;
  v6 = *(_DWORD *)(com_fixedtime + 8);
    if (v6) {
    LABEL_35:
      v16 = 1;
      if (v6 <= 0)
        v6 = 1;
      if (com_dedicated->current.integer)
        goto LABEL_20;
    LABEL_38:
      if (!*(_BYTE *)(com_sv_running + 8))
        goto LABEL_21;
      v8 = 200;
      goto LABEL_22;
    }
  v7 = *(float *)(com_timescale + 8);
    if (v7 != 1.0 || *(float *)&com_codeTimeScale != 1.0) {
      v15 = floorf(
          (float)((float)(v7 * (float)v5) * *(float *)&com_codeTimeScale) +
          0.5);
      v6 = (int)v15;
      goto LABEL_35;
    }
  v6 = v5;
  v16 = 0;
  if (v5 <= 0)
    v6 = 1;
  if (!com_dedicated->current.integer)
    goto LABEL_38;
LABEL_20:
    if ((unsigned int)(v6 - 501) > 0x79F2A) {
    LABEL_21:
      v8 = 5000;
      goto LABEL_22;
    }
  Com_Printf("Hitch warning: %i msec frame time\n", v6);
  v8 = 5000;
LABEL_22:
  if (v6 <= v8)
    v8 = v6;
  if (v16 && v5)
    v9 = (float)v8 / (float)v5;
  else
    v9 = 1.0;
  com_timescaleValue = LODWORD(v9);
  CL_SwitchToLocalClient(0);
  SV_Frame(v8);
    if ((com_dedicated->flags & 0x40) != 0) {
      result = com_dedicated->current;
      if (result.integer)
        return;
      goto LABEL_41;
    }
    if (com_dedicated->latched != com_dedicated->current.integer) {
      v10 = (dvar_s *)Dvar_RegisterInt(stru_21675C.name, 0, 0, 2, 0x1020u);
      com_dedicated = v10;
        if (v10->current.integer) {
          Dvar_RegisterInt(stru_21675C.name, 0, 0, 2, 0x1040u);
          v10 = com_dedicated;
        }
      Dvar_ClearModified(v10);
      CL_SwitchToLocalClient(0);
      CL_Shutdown();
      CL_SwitchToLocalClient(0);
      Sys_ShowConsole(1, 1);
      Sys_NormalExit();
      SV_AddDedicatedCommands();
    }
  result = com_dedicated->current;
    if (!result.integer) {
    LABEL_41:
      CL_SwitchToLocalClient(0);
      CL_RunOncePerClientFrame(v8);
      CL_SwitchToLocalClient(0);
      Com_EventLoop();
      CL_SwitchToLocalClient(0);
      Cbuf_Execute();
      CL_SwitchToLocalClient(0);
      SND_UpdateLoopingSounds();
      SND_Update();
      CL_SwitchToLocalClient(0);
      CL_Frame(v8);
      CL_SwitchToLocalClient(0);
      SCR_UpdateScreenInternal();
      SCR_RunCinematic();
      result.integer = com_statmon;
        if (*(_BYTE *)(com_statmon + 8)) {
            if (com_fileAccessed) {
              StatMon_Warning(1, 3000, "gfx/2d/warning@file.jpg");
              com_fileAccessed = 0;
            }
          v12 = Com_Statmon(void)::timeClientFrame;
          v13 = Sys_Milliseconds();
          Com_Statmon(void)::timeClientFrame = v13;
          result.integer = com_statmon;
            if (*(_BYTE *)(com_statmon + 8) && v13 - v12 > 33) {
              if (v12)
                StatMon_Warning(0, 3000, "gfx/2d/warning@fps.jpg");
            }
        }
    }
}

void Com_Frame(void)
{
  jmp_buf *Value; // eax

  Value = (jmp_buf *)Sys_GetValue(2);
    if (!setjmp(*Value)) {
      Com_Frame_Try_Block_Function();
      ++com_frameNumber;
    }
    if (com_errorEntered) {
      Com_ErrorCleanup();
      Com_StartHunkUsers();
    }
}

int __cdecl Com_Init_Try_Block_Function(char *a1)
{
  char *v1;                // ebx
  char v2;                 // al
  const char *BuildNumber; // eax
  const char *v4;          // ebx
  int v5;                  // edx
  int *v6;                 // ebx
  int v7;                  // eax
  _BOOL4 v8;               // ecx
  int v9;                  // edx
  int *v10;                // ebx
  int v11;                 // esi
  const char **v12;        // ebx
  const char *v13;         // eax
  dvar_s *v14;             // eax
  int result;              // eax
  int v16;                 // [esp+20h] [ebp-78h]
  int v17;                 // [esp+24h] [ebp-74h]
  int v18;                 // [esp+28h] [ebp-70h]
  int v19;                 // [esp+2Ch] [ebp-6Ch]
  int v20;                 // [esp+30h] [ebp-68h]
  int v21;                 // [esp+34h] [ebp-64h]
  int v22;                 // [esp+40h] [ebp-58h]
  int v23;                 // [esp+44h] [ebp-54h]
  int v24;                 // [esp+48h] [ebp-50h]
  int v25;                 // [esp+4Ch] [ebp-4Ch]
  int v26;                 // [esp+50h] [ebp-48h]
  int v27;                 // [esp+54h] [ebp-44h]

  v1 = a1;
  Com_Printf("%s %s build %s %s\n", "CoD2 MP", "1.0", "MacOSXS-i386",
             "Apr 18 2006");
  memset(com_pushedEvents, 0, 0x1800u);
  com_pushedEventsHead = 0;
  com_pushedEventsTail = 0;
  com_consoleLines[0] = (int)a1;
  com_numConsoleLines = 1;
    while (1) {
      v2 = *v1;
      if (!*v1)
        break;
        while (v2 != 43 && v2 != 10) {
          v2 = *++v1;
          if (!*v1)
            goto LABEL_6;
        }
      v7 = com_numConsoleLines;
      if (com_numConsoleLines == 32)
        break;
      com_consoleLines[com_numConsoleLines] = (int)(v1 + 1);
      com_numConsoleLines = v7 + 1;
      *v1++ = 0;
    }
LABEL_6:
  Swap_Init();
  Cbuf_Init();
  Cmd_Init();
  Com_StartupVariable(0);
  Com_StartupVariable("developer");
  CL_InitKeyCommands();
  FS_InitFilesystem();
  com_dedicated =
      (dvar_s *)Dvar_RegisterInt(stru_21675C.name, 0, 0, 2, 0x1020u);
  if (com_dedicated->current.integer)
    Dvar_RegisterInt(stru_21675C.name, 0, 0, 2, 0x1040u);
  com_maxfps = Dvar_RegisterInt("com_maxfps", 85, 0, 1000, 0x1001u);
  com_developer = Dvar_RegisterInt("developer", 0, 0, 2, 0x1000u);
  com_developer_script = (int)Dvar_RegisterBool("developer_script", 0, 0x1000u);
  com_logfile = Dvar_RegisterInt("logfile", 0, 0, 2, 0x1000u);
  com_statmon = (int)Dvar_RegisterBool("com_statmon", 0, 0x1000u);
  com_timescale = Dvar_RegisterFloat("timescale", 1.0, 0.001, 1000.0, 0x1088u);
  com_fixedtime = Dvar_RegisterInt("fixedtime", 0, 0, 1000, 0x1080u);
  com_viewlog = (dvar_s *)Dvar_RegisterInt("viewlog", 0, 0, 2, 0x1080u);
  sv_paused = Dvar_RegisterInt("sv_paused", 0, 0, 2, 0x1040u);
  cl_paused = Dvar_RegisterInt("cl_paused", 0, 0, 2, 0x1040u);
  com_sv_running = (int)Dvar_RegisterBool("sv_running", 0, 0x1040u);
  *(_DWORD *)(legacyHacks + 4) = 0;
  com_introPlayed = Dvar_RegisterBool(stru_216870.name, 0, 0x1001u);
  com_animCheck =
      (int)Dvar_RegisterBool((const char *)&stru_216870.reset, 0, 0x1000u);
  if (com_dedicated->current.integer && !com_viewlog->current.integer)
    Dvar_SetInt(com_viewlog, 1);
  CL_SwitchToLocalClient(0);
  Com_InitPlayerProfiles();
  CL_SwitchToLocalClient(0);
  Cbuf_Execute();
  com_recommendedSet =
      Dvar_RegisterBool((const char *)&stru_216870.hashNext, 0, 0x1001u);
  Com_CheckSetRecommended();
  Com_StartupVariable(0);
  SEH_UpdateLanguageInfo();
    if (com_dedicated->current.integer) {
      Sys_HideSplashWindow();
      Sys_ShowConsole(1, 1);
      Sys_NormalExit();
    }
  Com_InitHunkMemory();
  dvar_modifiedFlags &= ~1u;
  com_codeTimeScale = 1065353216;
    if (*(_DWORD *)(com_developer + 8)) {
      Cmd_AddCommand("error", (void (*)(void))Com_Error_f);
      Cmd_AddCommand("crash", (void (*)(void))Com_Crash_f);
      Cmd_AddCommand("freeze", (void (*)(void))Com_Freeze_f);
    }
  Cmd_AddCommand("quit", (void (*)(void))Com_Quit_f);
  Cmd_AddCommand("writeconfig", (void (*)(void))Com_WriteConfig_f);
  Cmd_AddCommand("writedefaults", (void (*)(void))Com_WriteDefaults_f);
  BuildNumber = (const char *)getBuildNumber();
  v4 = (const char *)va("%s %s build %s %s", "CoD2 MP", "1.0", BuildNumber,
                        "MacOSXS-i386");
  version = Dvar_RegisterString("version", (DvarValue)&inData, 0x1040u);
  Dvar_SetString((const dvar_s *)version, v4);
  shortversion =
      Dvar_RegisterString("shortversion", (DvarValue) "1.0", 0x1044u);
  FxMem_Init();
  Sys_Init();
    while (1) {
      Sys_GetEvent();
      if (!v23)
        break;
      v5 = com_pushedEventsHead;
      v6 = &com_pushedEvents[6 * (unsigned __int8)com_pushedEventsHead];
        if (com_pushedEventsHead - com_pushedEventsTail > 255) {
            if (!Com_PushEvent(sysEvent_t *)::printedWarning) {
              Com_PushEvent(sysEvent_t *)::printedWarning = 1;
              Com_Printf("WARNING: Com_PushEvent overflow\n");
            }
          if (v6[5])
            Z_FreeInternal(v6[5]);
          ++com_pushedEventsTail;
          v5 = com_pushedEventsHead;
        }
        else {
          Com_PushEvent(sysEvent_t *)::printedWarning = 0;
        }
      *v6 = v22;
      v6[1] = v23;
      v6[2] = v24;
      v6[3] = v25;
      v6[4] = v26;
      v6[5] = v27;
      com_pushedEventsHead = v5 + 1;
    }
  Netchan_Init(v22);
  Scr_Init();
  v8 = *(_DWORD *)(com_developer + 8) || *(_DWORD *)(com_logfile + 8);
  Scr_Settings(v8, *(unsigned __int8 *)(com_developer_script + 8),
               *(_DWORD *)(com_developer + 8));
  XAnimInit();
  DObjInit();
  SV_Init();
  NET_Init();
  Dvar_ClearModified(com_dedicated);
    if (!com_dedicated->current.integer) {
      CL_InitOnceForAllClients();
      CL_SwitchToLocalClient(0);
      CL_Init();
      CL_SwitchToLocalClient(0);
      Sys_ShowConsole(com_viewlog->current.integer, 0);
    }
    while (1) {
      Sys_GetEvent();
      if (!v17)
        break;
      v9 = com_pushedEventsHead;
      v10 = &com_pushedEvents[6 * (unsigned __int8)com_pushedEventsHead];
        if (com_pushedEventsHead - com_pushedEventsTail > 255) {
            if (!Com_PushEvent(sysEvent_t *)::printedWarning) {
              Com_PushEvent(sysEvent_t *)::printedWarning = 1;
              Com_Printf("WARNING: Com_PushEvent overflow\n");
            }
          if (v10[5])
            Z_FreeInternal(v10[5]);
          ++com_pushedEventsTail;
          v9 = com_pushedEventsHead;
        }
        else {
          Com_PushEvent(sysEvent_t *)::printedWarning = 0;
        }
      *v10 = v16;
      v10[1] = v17;
      v10[2] = v18;
      v10[3] = v19;
      v10[4] = v20;
      v10[5] = v21;
      com_pushedEventsHead = v9 + 1;
    }
  com_frameTime = v16;
    if (com_numConsoleLines > 0) {
      v11 = 0;
      v12 = (const char **)com_consoleLines;
        do {
            while (1) {
              v13 = *v12;
                if (*v12) {
                  if (*v13)
                    break;
                }
              ++v11;
              ++v12;
              if (v11 >= com_numConsoleLines)
                goto LABEL_47;
            }
          I_strnicmp(v13, "set", 3);
          Cbuf_AddText(*v12);
          Cbuf_AddText("\n");
          ++v11;
          ++v12;
        }
      while (v11 < com_numConsoleLines);
    }
LABEL_47:
    if (!com_dedicated->current.integer) {
      dword_1220A68 = 1;
      CL_InitRenderer();
      dword_1220A6C = 1;
      SND_Init();
      Sys_LoadingKeepAlive();
      v14 = com_dedicated;
      if (com_dedicated->current.integer)
        goto LABEL_49;
    LABEL_57:
      Sys_ShowConsole(com_viewlog->current.integer, 0);
      v14 = com_dedicated;
      goto LABEL_49;
    }
  Sys_LoadingKeepAlive();
  v14 = com_dedicated;
  if (!com_dedicated->current.integer)
    goto LABEL_57;
LABEL_49:
    if (!v14->current.integer && !com_introPlayed->current.enabled) {
      Cbuf_AddText("cinematic atvi\n");
      Dvar_SetString(nextmap,
                     "cinematic IW_logo; set nextmap cinematic cod_intro");
      Dvar_SetBool(com_introPlayed, 1);
    }
  com_fullyInitialized = 1;
  Com_Printf("--- Common Initialization Complete ---\n");
  Cbuf_Execute();
  result = com_sv_running;
    if (!*(_BYTE *)(com_sv_running + 8)) {
      UI_SetMap((const char *)&inData, (const char *)&inData);
      return CL_StartHunkUsers();
    }
  return result;
}

void Com_Init(char *commandLine)
{
  jmp_buf *Value;

  Value = (jmp_buf *)Sys_GetValue(2);
    if (setjmp(*Value)) {
      Sys_Error(va("Error during initialization:\n%s\n", com_errorMessage));
    }
  Com_Init_Try_Block_Function(commandLine);
}

struct GamePadCheat *com_gamePadCheats;
char *cl_cdkey;
char *cl_cdkeychecksum;
struct dvar_s const *const com_developer;
int marker_common;
struct dvar_s const *const com_statmon;
int com_skelTimeStamp;
struct dvar_s const *const com_viewlog;
struct dvar_s const *const com_useConfig;
struct dvar_s const *const com_fixedtime;
struct dvar_s const *const com_logfile;
struct dvar_s const *const cl_paused;
struct dvar_s const *const com_timescale;
struct dvar_s const *const nextmap;
struct dvar_s const *const version;
struct dvar_s const *const com_sv_running;
float com_timescaleValue;
struct _iobuf *debuglogfile;
struct dvar_s const *const ui_errorTitle;
struct dvar_s const *const shortversion;
struct dvar_s const *const com_attractmodeduration;
struct dvar_s const *const com_attractmode;
int com_numConsoleLines;
struct dvar_s const *const sv_paused;
int com_fixedConsolePosition;
struct dvar_s const *const com_animCheck;
struct dvar_s const *const com_developer_script;
int com_argc;
struct dvar_s const *const com_maxfps;
int com_frameTime;
struct dvar_s const *const com_recommendedSet;
struct dvar_s const *const ui_errorMessage;
struct dvar_s const *const com_introPlayed;
int com_errorEntered;
int com_frameNumber;
char **com_argv;
char **com_consoleLines;

void __cdecl Com_ClearCDKey(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_Crash_f(void)
{
  MEMORY[0] = 305419896;
}

void __cdecl Com_ClearGamePadCheat(struct GamePadCheat *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ClearTempMemory(void)
{
  UNIMPLEMENTED();
}

void __cdecl COM_PlayIntroMovies(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_UpdateGamePadCheat(struct GamePadCheat *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_UpdateAllGamePadCheats(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_SetErrorMessage(char const *)
{
  char *v2;  // eax
  char *v3;  // eax
  char *v4;  // eax
  char *v5;  // ebx
  char **v6; // ebx

  ui_errorMessage =
      Dvar_RegisterString("com_errorMessage", (DvarValue)&inData, 0x1040u);
  ui_errorTitle =
      Dvar_RegisterString("com_errorTitle", (DvarValue)&inData, 0x1040u);
    if (errorcode == 2) {
    LABEL_10:
      v3 =
          SEH_LocalizeTextMessage("MENU_NOTICE", "error message", LOCMSG_NOERR);
      if (v3)
        goto LABEL_4;
      Dvar_SetString(ui_errorTitle, "MENU_NOTICE");
      goto LABEL_5;
    }
  v2 = noticeErrors;
    if (*noticeErrors) {
      v6 = &noticeErrors;
        while (stricmp(v2, a1)) {
          v2 = v6[1];
          ++v6;
          if (!*v2)
            goto LABEL_3;
        }
      goto LABEL_10;
    }
LABEL_3:
  v3 = SEH_LocalizeTextMessage("MENU_ERROR", "error message", LOCMSG_NOERR);
    if (v3) {
    LABEL_4:
      Dvar_SetString(ui_errorTitle, v3);
      goto LABEL_5;
    }
  Dvar_SetString(ui_errorTitle, "MENU_ERROR");
LABEL_5:
  v4 = SEH_LocalizeTextMessage(a1, "error message", LOCMSG_NOERR);
  v5 = v4;
    if (v4) {
      Dvar_SetString(ui_errorMessage, v4);
      I_strncpyz(&com_errorMessage, v5, 4096);
    }
    else {
      Dvar_SetString(ui_errorMessage, a1);
    }
}

void __cdecl Com_StartupConfigs(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_CheckStartupMessage(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_Statmon(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_Error_f(void)
{
  char v1; // [esp+8h] [ebp-10h]

  if ((int)Cmd_Argc() <= 1)
    return Com_Error(0, "\x15Testing fatal error", v1);
  else
    return Com_Error(1, "\x15Testing drop error", v1);
}

void __cdecl Com_InitDvars(void)
{
  UNIMPLEMENTED();
}

int __cdecl Com_ModifyMsec(int)
{
  UNIMPLEMENTED();
}

void __cdecl Com_WriteConfigToFile(char const *)
{
  int v2; // eax
  int v3; // ebx

  v2 = FS_FOpenFileWrite(a1);
  v3 = v2;
    if (v2) {
      FS_Printf(v2, "// generated by Call of Duty, do not modify\n");
      FS_Printf(v3, "unbindall\n");
      Key_WriteBindings(v3);
      Dvar_WriteVariables(v3);
      FS_FCloseFile(v3);
    }
    else {
      Com_Printf("Couldn't write %s.\n", a1);
    }
}

void __cdecl Com_Freeze_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_AttractMode(void)
{
  UNIMPLEMENTED();
}

void __cdecl Com_DedicatedModified(void)
{
  UNIMPLEMENTED();
}

void Com_ErrorCleanup(void)
{
  int v0;           // edx
  int result;       // eax
  const char *v2;   // eax
  const char *v3;   // [esp+0h] [ebp-1018h]
  char __dst[4104]; // [esp+10h] [ebp-1008h] BYREF

  LargeLocalReset();
  if (unk_121C7EC)
    unk_121C7EC();
  Dvar_SetInAutoExec(0);
  Hunk_ClearTempMemory();
  Hunk_ClearTempMemoryHigh();
  Com_IsMapProfilerActive();
  Dvar_SetIntByName("cl_paused", 0);
  FS_PureServerSetLoadedIwds((const char *)&inData, (const char *)&inData);
  SEH_UpdateLanguageInfo();
  strcpy(__dst, com_errorMessage);
    if (errorcode == 3) {
        if (com_errorMessage[0]) {
          v2 = (const char *)SEH_LocalizeTextMessage(
              com_errorMessage, "error message", LOCMSG_NOERR);
          if (v2)
            I_strncpyz(com_errorMessage, v2, 4096);
        }
    }
    else {
      if (dword_1220A70)
        UI_SetActiveMenu(0);
      Com_SetErrorMessage(v3);
    }
  if (errorcode != 3)
    Scr_Abort();
  SND_ErrorCleanup();
  Com_CleanupBsp();
  CM_Cleanup();
  Com_ResetParseSessions();
  CL_FlushDebugData(1);
  if (unk_121C784)
    unk_121C784();
  FS_ResetFiles();
  if (errorcode == 1)
    Cbuf_Init();
  v0 = Sys_Milliseconds();
    if (v0 - Com_ErrorCleanup(void)::lastErrorTime > 99) {
      Com_ErrorCleanup(void)::errorCount = 0;
      Com_ErrorCleanup(void)::lastErrorTime = v0;
      if ((unsigned int)(errorcode - 1) <= 2)
        goto LABEL_17;
    LABEL_22:
      Sys_Error("%s", com_errorMessage);
    }
  if (++Com_ErrorCleanup(void)::errorCount > 3)
    errorcode = 0;
  Com_ErrorCleanup(void)::lastErrorTime = v0;
  if ((unsigned int)(errorcode - 1) > 2)
    goto LABEL_22;
LABEL_17:
  updateScreenCalled = 0;
    if (errorcode == 2) {
      Com_ShutdownInternal("EXE_DISCONNECTEDFROMOWNLISTENSERVER");
      com_fixedConsolePosition = 0;
      com_errorEntered = 0;
    }
    else {
      Com_Printf("********************\nERROR: %s\n********************\n",
                 com_errorMessage);
      if (errorcode == 1 && dword_1220A70 && !com_fixedConsolePosition)
        CL_ConsoleFixPosition();
      Com_ShutdownInternal(__dst);
        if (errorcode == 1) {
          if (QuitOnError())
            Com_Quit_f();
        }
      com_fixedConsolePosition = 0;
      com_errorEntered = 0;
    }
}

void Com_StartHunkUsers(void)
{
  jmp_buf *Value; // eax

  Value = (jmp_buf *)Sys_GetValue(2);
  if (setjmp(*Value))
    Sys_Error((const char *)&stru_21675C.latched);
  UI_SetMap((const char *)&inData, (const char *)&inData);
  CL_StartHunkUsers();
  Com_EventLoop();
    if (com_dedicated) {
      if (!com_dedicated->current.integer)
        UI_SetActiveMenu(1);
    }
}

Com_BeginRedirect(char* buffer,  int buffersize,  void  flush)(char*))
{
  UNIMPLEMENTED();
}

Com_EndRedirect()
{
  UNIMPLEMENTED();
}

Com_SetRecommended(int restart)
{
  UNIMPLEMENTED();
}

Com_CheckSetRecommended()
{
  UNIMPLEMENTED();
}
