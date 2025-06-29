int __cdecl CG_CheckDObjInfoMatches(int, int, struct XModel *)
{
  return *(_DWORD *)((char *)&loc_285F8 + (_DWORD)cg + 4 * a1) == a2 &&
         *((XModel **)cg + a1 + 42366) == a3;
}

void __cdecl CG_SetDObjInfo(int iEntNum, int iEntType, struct XModel *pXModel)
{
  _DWORD *v3;     // edx
  XModel *result; // eax

  v3 = cg;
  *(_DWORD *)((char *)&loc_285F8 + (_DWORD)cg + 4 * a1) = a2;
  result = a3;
  v3[a1 + 42366] = a3;
  return result;
}

void __cdecl CGScr_LoadAnimTrees()
{
  UNIMPLEMENTED();
}

void __cdecl CG_SafeDObjFree(int iEntNum)
{
  UNIMPLEMENTED();
}

void __cdecl CG_FreeClientDObjInfo()
{
  UNIMPLEMENTED();
}

void __cdecl CG_FreeEntityDObjInfo()
{
  UNIMPLEMENTED();
}
