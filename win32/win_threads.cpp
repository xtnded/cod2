void *Sys_InitMainThread(void) {
  threadId = GetCurrentThreadId();
  return Com_InitThreadData(0);
}
_BOOL4 Sys_IsMainThread(void) { return GetCurrentThreadId() == threadId; }
void *__cdecl Sys_SetValue(int a1, void *a2) {
  void *result; // eax

  result = a2;
  g_threadValues[a1] = (int)a2;
  return result;
}
int __cdecl Sys_GetValue(int a1) { return g_threadValues[a1]; }