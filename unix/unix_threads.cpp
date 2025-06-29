#include "../qcommon/qcommon.h"
#include <pthread.h>
threadid_t mainthread;
void *g_threadValues[THREAD_VALUE_COUNT];

void Sys_InitMainThread(void)
{
  mainthread = pthread_self();
  Com_InitThreadData(THREAD_CONTEXT_MAIN);
}

qboolean Sys_IsMainThread(void)
{
  return mainthread == pthread_self();
}

void Sys_SetValue(int valueIndex, void *data)
{

  g_threadValues[valueIndex] = data;
}

void *Sys_GetValue(int valueIndex)
{
  return g_threadValues[valueIndex];
}