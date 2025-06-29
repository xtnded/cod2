#include "../game/q_shared.h"

void Sys_OutOfMemErrorInternal(const char *file, int line)
{
  Com_Printf("Out of memory: filename '%s', line %d\n", file, line);
  const char *title = Win_LocalizeRef("WIN_OUT_OF_MEM_TITLE");
  const char *body = Win_LocalizeRef("WIN_OUT_OF_MEM_BODY");
  MessageBoxA(NULL, body, title, 16);
  exit(-1);
}

int main(int argc, char **argv)
{
  const dvar_s *sys_SSE;
  dvar_s *dedicated;
  char cwd[264];

  Sys_InitMainThread();
  Win_InitLocalization();
  Dvar_Init();
  sys_info.cpuGHz = Sys_CpuGHz(a1);
  sys_info.sysMB = Sys_SystemMemoryMB();
  Sys_DetectVideoCard(0x200u, sys_info.gpuDescription);
  sys_info.SSE = Sys_SupportsSSE();
  sys_SSE = Dvar_RegisterBool("sys_SSE", 0, 0x1000u);
  Dvar_SetBool(sys_SSE, sys_info.SSE);
  dword_1150F8C = a2;
  Sys_CreateConsole(a2);
  Sys_CreateSplashWindow();
  Sys_ShowSplashWindow();
  Sys_Milliseconds();
  Sys_InitStreamThread();
  Com_Init(cmdline);
  getcwd(cwd, 0x100u);
  Com_Printf("Working directory: %s\n", cwd);
  dedicated = com_dedicated;
  if ( !com_dedicated->current.integer )
  {
    if ( !com_viewlog->current.integer )
      Sys_ShowConsole(0, 0);
    dedicated = com_dedicated;
  }
  while ( 1 )
  {
    if ( dedicated )
    {
      if ( dedicated->current.integer )
        WinSleep(5);
    }
    Com_Frame();
    dedicated = com_dedicated;
  }
  return 0;
}
