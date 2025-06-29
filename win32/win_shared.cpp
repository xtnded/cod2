int marker_win_shared;

int Sys_Milliseconds(void)
{
  static qboolean initialized = 0;
    if (!initialized) {
      sys_timeBase = timeGetTime();
      initialized = 1;
    }
  return timeGetTime() - sys_timeBase;
}

Sys_MillisecondsRaw()
{
  UNIMPLEMENTED();
}

Sys_SnapVector(float *v)
{
  UNIMPLEMENTED();
}
