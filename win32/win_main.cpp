
void __usercall __noreturn WinMain(__m128 a1 @<xmm0>, __m128 a2 @<xmm1>,
                                   __m128 a3 @<xmm2>, __m128 a4 @<xmm3>,
                                   __m128 a5 @<xmm4>, __m128 a6 @<xmm6>, int a7,
                                   int a8, char *a9)
{
  long double v9; // fst7
  dvar_s *v10;    // eax
  int v11;        // eax
  char v12[264];  // [esp+10h] [ebp-108h] BYREF

  Sys_InitMainThread();
  Win_InitLocalization();
  Dvar_Init();
  v9 = Sys_CpuGHz();
  *(double *)&sys_info = v9;
  dword_7EFC88 = Sys_SystemMemoryMB();
  Sys_DetectVideoCard(0x200u, byte_7EFC8D);
  byte_7EFC8C = Sys_SupportsSSE();
  v10 = Dvar_RegisterBool("sys_SSE", 0, 0x1000u);
  Dvar_SetBool(v10, byte_7EFC8C);
  dword_1150F8C = a7;
  Sys_CreateConsole();
  Sys_CreateSplashWindow();
  Sys_ShowSplashWindow();
  Sys_Milliseconds();
  Sys_InitStreamThread();
  Com_Init(v9, a1.f32[0], a2, a3, a4, a5, a6, a9);
  getcwd(v12, 0x100u);
  Com_Printf("Working directory: %s\n", v12);
  v11 = com_dedicated;
    if (!*(_DWORD *)(com_dedicated + 8)) {
      if (!com_viewlog->current.integer)
        Sys_ShowConsole(0);
      v11 = com_dedicated;
    }
    while (1) {
        if (v11) {
          if (*(_DWORD *)(v11 + 8))
            WinSleep(5);
        }
      Com_Frame(v9, a1, a2, a3, a4, a5, a6);
      v11 = com_dedicated;
    }
}
