void __cdecl Com_AbortDObj()
{
  g_bDObjInited = 0;
}

void __cdecl Com_ShutdownDObj()
{
  g_bDObjInited = 0;
}

void __cdecl Com_InitDObj()
{
  UNIMPLEMENTED();
}

struct DObj_s *__cdecl Com_GetServerDObj(int handle)
{
  __int16 v1; // ax

  v1 = serverObjMap[a1];
  if (v1)
    return &objBuf + v1;
  else
    return 0;
}

struct DObj_s *__cdecl Com_GetClientDObj(int handle, int localClientNum)
{
  __int16 v2; // ax

  v2 = clientObjMap[1152 * a2 + a1];
  if (v2)
    return &objBuf + v2;
  else
    return 0;
}

void __cdecl Com_ClientDObjClearAllSkel()
{
  UNIMPLEMENTED();
}

void __cdecl Com_SafeServerDObjFree(int handle)
{
  UNIMPLEMENTED();
}

void __cdecl Com_SafeClientDObjFree(int handle)
{
  UNIMPLEMENTED();
}

void *__cdecl DB_LoadDObjs(void *)
{
  UNIMPLEMENTED();
}

void *__cdecl DB_SaveDObjs(void *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ServerDObjCreate(struct DObjModel_s *dobjModels,
                                  unsigned short numModels,
                                  struct XAnimTree_s *tree, int handle)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ClientDObjCreate(struct DObjModel_s *dobjModels,
                                  unsigned short numModels,
                                  struct XAnimTree_s *tree, int handle)
{
  int v4;       // edx
  __int16 v5;   // ax
  char *result; // eax
  char *v7;     // ecx

  v4 = com_lastDObjIndex + 1;
    if (com_lastDObjIndex + 1 <= 2047) {
        if (!objAlloced[v4]) {
        LABEL_3:
          com_lastDObjIndex = v4;
          objAlloced[v4] = 1;
          --objFreeCount;
          v5 = v4;
          goto LABEL_4;
        }
      v7 = &objAlloced[v4];
        while (++v4 != 2048) {
          if (!*++v7)
            goto LABEL_3;
        }
    }
    if (com_lastDObjIndex > 0) {
        if (!byte_4B6D81) {
          v4 = 1;
          goto LABEL_3;
        }
      v4 = 1;
        while (com_lastDObjIndex >= ++v4) {
          if (!objAlloced[v4])
            goto LABEL_3;
        }
    }
  v4 = 0;
  v5 = 0;
LABEL_4:
  clientObjMap[a4] = v5;
  result = DObjCreate(a1, a2, a3, (char *)&objBuf + 100 * v4, 0);
  if (!objFreeCount)
    return (char *)Com_Error(1, "\x15No free DObjs", (char)a3);
  return result;
}

int marker_dobj_management;

int __cdecl Com_GetFreeDObjIndex(void)
{
  UNIMPLEMENTED();
}
