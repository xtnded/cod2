void __cdecl CIN_CloseAllVideos()
{
  UNIMPLEMENTED();
}

void __cdecl SCR_RunCinematic()
{
  return ROQ_RunCinematic();
}

void __cdecl SCR_DrawCinematic()
{
  return ROQ_DrawCinematic();
}

void __cdecl CIN_DrawCinematic(int handle)
{
  return ROQ_DrawCinematicFromHandle(a1);
}

enum e_status __cdecl CIN_RunCinematic(int)
{
  return ROQ_RunCinematicFromHandle(a1);
}

enum e_status __cdecl CIN_StopCinematic(int handle)
{
  return ROQ_StopCinematicFromHandle(a1);
}

void __cdecl SCR_StopCinematic()
{
  ROQ_StopCinematic(a1, a2, a3, a4, a5, a6, a7);
}

bool __cdecl XenonPlayCinematicCallback(void)
{
  UNIMPLEMENTED();
}

void __cdecl CIN_UploadCinematic(int handle)
{
  return ROQ_UploadCinematicFromHandle(a1);
}

void __cdecl CIN_SetLooping(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CIN_SetExtents(int handle, int x, int y, int w, int h)
{
  return ROQ_SetExtentsFromHandle(a1, a2, a3, a4, a5);
}

int __cdecl CIN_PlayCinematic(char const *arg, int x, int y, int w, int h,
                              int systemBits)
{
  return ROQ_PlayCinematic(a1, a2, a3, a4, a5, a6);
}

void __cdecl CIN_PlayAttractModeMovie(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_PlayCinematic_f()
{
  UNIMPLEMENTED();
}

int marker_cl_cin;
