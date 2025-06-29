
void *__cdecl Sys_GetInfo(SysInfo *__dst)
{
  return memcpy(__dst, &sys_info, 0x210u);
}

void __cdecl Sys_ArchiveInfo(int a1)
{
  float v1; // xmm0_4

  sys_cpuGHz =
      Dvar_RegisterFloat("sys_cpuGHz", 0, -3.4028235e38, 3.4028235e38, 0x1011u);
  sys_sysMB = Dvar_RegisterInt("sys_sysMB", 0, 0x80000000, 0x7FFFFFFF, 0x1011u);
  sys_gpu = Dvar_RegisterString("sys_gpu", (DvarValue)&inData, 0x1011u);
  sys_configSum =
      Dvar_RegisterInt("sys_configSum", 0, 0x80000000, 0x7FFFFFFF, 0x1011u);
  v1 = *(double *)&sys_info;
  Dvar_SetFloat(sys_cpuGHz, v1);
  Dvar_SetInt(sys_sysMB, dword_7EFC88);
  Dvar_SetString(sys_gpu, byte_7EFC8D);
  Dvar_SetInt(sys_configSum, a1);
}

void __noreturn Sys_DirectXFatalError(void)
{
  char *v0; // ebx
  char *v1; // eax

  v0 = Win_LocalizeRef("WIN_DIRECTX_INIT_TITLE");
  v1 = Win_LocalizeRef("WIN_DIRECTX_INIT_BODY");
  MessageBoxA(0, (MacStrings *)v1, (MacStrings *)v0, 16);
  j__exit(-1);
}

void __cdecl __noreturn Sys_OutOfMemErrorInternal(const char *a1, int a2)
{
  char *v2; // ebx
  char *v3; // eax

  Com_Printf("Out of memory: filename '%s', line %d\n", a1, a2);
  v2 = Win_LocalizeRef("WIN_OUT_OF_MEM_TITLE");
  v3 = Win_LocalizeRef("WIN_OUT_OF_MEM_BODY");
  MessageBoxA(0, (MacStrings *)v3, (MacStrings *)v2, 16);
  j__exit(-1);
}

void __cdecl Sys_StartProcess(char *__big, int a2)
{
  OSStatus ApplicationFolderItemRef; // eax
  char v3;                           // [esp+8h] [ebp-60h]
  FSRef inRef;                       // [esp+10h] [ebp-58h] BYREF

    if (strstr(__big, "cod2sp")) {
      ApplicationFolderItemRef = MacFolders::GetApplicationFolderItemRef(
          (MacFolders *)"Call of Duty 2.app", &inRef);
    }
    else {
        if (!strstr(__big, "cod2mp")) {
          dprintf();
          return;
        }
      ApplicationFolderItemRef = MacFolders::GetApplicationFolderItemRef(
          (MacFolders *)"Call of Duty 2 Multiplayer.app", &inRef);
    }
    if (!ApplicationFolderItemRef && !LSOpenFSRef(&inRef, 0)) {
      if (a2)
        Cbuf_ExecuteText(2, "quit\n", v3);
    }
}

void __usercall __noreturn Sys_Error(long double a1 @<st0>, float a2 @<xmm0>,
                                     __m128 a3 @<xmm1>, __m128 a4 @<xmm2>,
                                     __m128 a5 @<xmm3>, __m128 a6 @<xmm4>,
                                     __m128 a7 @<xmm6>, char *__format, ...)
{
  CMacGameEngine *v8; // [esp+0h] [ebp-1028h]
  char __str[4096];   // [esp+1Ch] [ebp-100Ch] BYREF
  va_list v10;        // [esp+101Ch] [ebp-Ch]
  va_list va;         // [esp+1034h] [ebp+Ch] BYREF

  va_start(va, __format);
  com_errorEntered = 1;
  va_copy(v10, va);
  vsnprintf(__str, 0x1000u, __format, va);
  Sys_DestroySplashWindow();
  timeEndPeriod();
  IN_Shutdown();
  CL_ShutdownHunkUsers(a1, a2, a3, a4, a5, a6, a7);
  CL_ShutdownRef();
  Conbuf_AppendText(__str);
  Conbuf_AppendText("\n");
  Sys_SetErrorText((MacStrings *)__str);
  Sys_ShowConsole(1);
  while (!(unsigned __int8)CMacGameEngine::ProcessAllEvents(v8) &&
         gConsoleRunning)
    ;
  Com_Quit_f();
}

void Sys_NormalExit(void)
{
  ;
}

void __cdecl Sys_Print(const char *iDataPtr)
{
  Conbuf_AppendText(iDataPtr);
}

char *Sys_GetClipboardData()
{
  return &inData;
}

void *__cdecl Sys_QueEvent(int a1, sysEventType_t a2, int a3, int a4, int a5,
                           void *a6)
{
  int v6;       // esi
  int v7;       // edx
  int *v8;      // ebx
  void *result; // eax

  v6 = a1;
  v7 = eventHead;
  v8 = &eventQue[6 * (unsigned __int8)eventHead];
    if (eventHead - eventTail > 255) {
      Com_Printf("Sys_QueEvent: overflow\n");
      if (v8[5])
        Z_FreeInternal((void *)v8[5]);
      ++eventTail;
      v7 = eventHead;
    }
  eventHead = v7 + 1;
  if (!a1)
    v6 = Sys_Milliseconds();
  *v8 = v6;
  v8[1] = a2;
  v8[2] = a3;
  v8[3] = a4;
  v8[4] = a5;
  result = a6;
  v8[5] = (int)a6;
  return result;
}

void Sys_Init(void)
{
  const char *v0; // eax

  timeBeginPeriod();
  Cmd_AddCommand("in_restart", (void (*)(void))Sys_In_Restart_f);
  Cmd_AddCommand("net_restart", Sys_Net_Restart_f);
  Com_Printf("Measured CPU speed is %.2lf GHz\n", *(double *)&sys_info);
  Com_Printf("System memory is %i MB (capped at 1 GB)\n", dword_7EFC88);
  Com_Printf("Video card is \"%s\"\n", byte_7EFC8D);
  v0 = (const char *)&inData;
  if (!byte_7EFC8C)
    v0 = "not ";
  Com_Printf("Streaming SIMD Extensions (SSE) %ssupported\n", v0);
  Com_Printf("\n");
  IN_Init();
}

OSErr Sys_LoadingKeepAlive(void)
{
  return UpdateSystemActivity(0);
}

void __noreturn Sys_Quit(void)
{
  int v0; // edx

  timeEndPeriod();
  IN_Shutdown();
  Key_Shutdown();
  Sys_DestroyConsole();
  Win_ShutdownLocalization();
  RefreshQuitOnErrorCondition();
  Dvar_Shutdown();
  Cmd_Shutdown();
  Con_Shutdown();
  Com_ShutdownEvents();
    while (1) {
      v0 = eventTail;
      if (eventHead <= eventTail)
        break;
        while (1) {
          eventTail = v0 + 1;
          if (!*(&dword_7EFEB4 + 6 * (unsigned __int8)v0))
            break;
          Z_FreeInternal(*(&dword_7EFEB4 + 6 * (unsigned __int8)v0));
          v0 = eventTail;
          if (eventHead <= eventTail)
            goto LABEL_5;
        }
    }
LABEL_5:
  MacPreferences::Synchronize();
  j__exit(0);
}

_DWORD *__stdcall Sys_GetEvent(_DWORD *a1)
{
  int v1;              // edx
  int v2;              // eax
  char *v4;            // eax
  char *v5;            // edi
  int v6;              // edx
  int *v7;             // ebx
  _DWORD *v8;          // edi
  int v9;              // edx
  int *v10;            // ebx
  CMacGameEngine *v11; // [esp+0h] [ebp-78h]
  unsigned int __size; // [esp+14h] [ebp-64h]
  char *__src;         // [esp+18h] [ebp-60h]
  size_t v14;          // [esp+1Ch] [ebp-5Ch]
  msg_t v15;           // [esp+24h] [ebp-54h] BYREF
  _DWORD v16[6];       // [esp+3Ch] [ebp-3Ch] BYREF
  _DWORD v17[9];       // [esp+54h] [ebp-24h] BYREF

  v1 = eventTail;
  if (eventHead > eventTail)
    goto LABEL_2;
  if ((unsigned __int8)CMacGameEngine::ProcessAllEvents(v11))
    Com_Quit_f();
  v4 = Sys_ConsoleInput();
  __src = v4;
    if (v4) {
      __size = strlen(v4) + 1;
      v5 = (char *)Z_MallocInternal(__size);
      I_strncpyz(v5, __src, __size - 1);
      v6 = eventHead;
      v7 = &eventQue[6 * (unsigned __int8)eventHead];
        if (eventHead - eventTail > 255) {
          Com_Printf("Sys_QueEvent: overflow\n");
          if (v7[5])
            Z_FreeInternal((void *)v7[5]);
          ++eventTail;
          v6 = eventHead;
        }
      eventHead = v6 + 1;
      *v7 = Sys_Milliseconds();
      v7[1] = 4;
      v7[2] = 0;
      v7[3] = 0;
      v7[4] = __size;
      v7[5] = (int)v5;
    }
  MSG_Init(&v15, &sys_packetReceived, 0x4000u);
    if (NET_GetPacket((netadr_t *)v17, &v15)) {
      v14 = v15.cursize - v15.readcount + 12;
      v8 = Z_MallocInternal(v14);
      *v8 = v17[0];
      v8[1] = v17[1];
      v8[2] = v17[2];
      memcpy(v8 + 3, (const void *)(v15.data + v15.readcount),
             v15.cursize - v15.readcount);
      v9 = eventHead;
      v10 = &eventQue[6 * (unsigned __int8)eventHead];
        if (eventHead - eventTail > 255) {
          Com_Printf("Sys_QueEvent: overflow\n");
          if (v10[5])
            Z_FreeInternal((void *)v10[5]);
          ++eventTail;
          v9 = eventHead;
        }
      eventHead = v9 + 1;
      *v10 = Sys_Milliseconds();
      v10[1] = 5;
      v10[2] = 0;
      v10[3] = 0;
      v10[4] = v14;
      v10[5] = (int)v8;
    }
  v1 = eventTail;
    if (eventHead > eventTail) {
    LABEL_2:
      eventTail = v1 + 1;
      v2 = 6 * (unsigned __int8)v1;
      *a1 = eventQue[v2];
      a1[1] = dword_7EFEA4[v2];
      a1[2] = dword_7EFEA8[v2];
      a1[3] = dword_7EFEAC[v2];
      a1[4] = dword_7EFEB0[v2];
      a1[5] = *(MacPreferences **)((char *)&dword_7EFEB4 + v2 * 4);
    }
    else {
      memset(v16, 0, sizeof(v16));
      v16[0] = Sys_Milliseconds();
      *a1 = v16[0];
      a1[1] = v16[1];
      a1[2] = v16[2];
      a1[3] = v16[3];
      a1[4] = v16[4];
      a1[5] = v16[5];
    }
  return a1;
}

_BOOL4 __cdecl Sys_HasConfigureChecksumChanged(int checksum)
{
  DvarValue current; // eax
  char *v2;          // ebx
  char *v3;          // eax
  _BOOL4 v4;         // ebx
  DvarValue v5;      // eax

  sys_cpuGHz =
      Dvar_RegisterFloat("sys_cpuGHz", 0, -3.4028235e38, 3.4028235e38, 0x1011u);
  sys_sysMB = Dvar_RegisterInt("sys_sysMB", 0, 0x80000000, 0x7FFFFFFF, 0x1011u);
  sys_gpu = Dvar_RegisterString("sys_gpu", (DvarValue)&inData, 0x1011u);
  sys_configSum =
      Dvar_RegisterInt("sys_configSum", 0, 0x80000000, 0x7FFFFFFF, 0x1011u);
  current = sys_configSum->current;
    if (!current.integer || current.integer == checksum) {
      v4 = 0;
    }
    else {
      v2 = Win_LocalizeRef("WIN_CONFIGURE_UPDATED_TITLE");
      v3 = Win_LocalizeRef("WIN_CONFIGURE_UPDATED_BODY");
      v4 = MessageBoxA(0, (MacStrings *)v3, (MacStrings *)v2, 68) == 6;
    }
  v5 = sys_configSum->current;
  if (!v5.integer || v5.integer != checksum)
    Dvar_SetInt(sys_configSum, checksum);
  return v4;
}

int Sys_HasInfoChanged(void)
{
  double v0;         // xmm2_8
  DvarValue current; // ecx
  int result;        // eax

  sys_cpuGHz =
      Dvar_RegisterFloat("sys_cpuGHz", 0, -3.4028235e38, 3.4028235e38, 0x1011u);
  sys_sysMB = Dvar_RegisterInt("sys_sysMB", 0, 0x80000000, 0x7FFFFFFF, 0x1011u);
  sys_gpu = Dvar_RegisterString("sys_gpu", (DvarValue)&inData, 0x1011u);
  sys_configSum =
      Dvar_RegisterInt("sys_configSum", 0, 0x80000000, 0x7FFFFFFF, 0x1011u);
  v0 = *(float *)&sys_cpuGHz->current.integer;
  if (v0 > *(double *)&sys_info * 1.100000023841858)
    return Sys_ShouldUpdateForInfoChange();
  if (*(double *)&sys_info * 0.8999999761581421 > v0)
    return Sys_ShouldUpdateForInfoChange();
  current = sys_sysMB->current;
  if (current.integer > dword_7EFC88 + 32)
    return Sys_ShouldUpdateForInfoChange();
  if (current.integer < dword_7EFC88 - 32)
    return Sys_ShouldUpdateForInfoChange();
  result = strcmp((const char *)sys_gpu->current.integer, byte_7EFC8D);
  if (result)
    return Sys_ShouldUpdateForInfoChange();
  return result;
}