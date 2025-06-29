void __cdecl Scr_PostCompileScripts()
{
  return Hunk_ConvertTempToPermLowInternal();
}

bool __cdecl Scr_IsIdentifier(char const *token)
{
  char v1;       // bl
  const char *i; // esi
  _BOOL4 v3;     // eax

  v1 = *a1;
  if (!*a1)
    return 1;
    for (i = a1;; ++i) {
      v3 = (v1 & 0xFFFFFF80) != 0
               ? __maskrune(v1, 1280) != 0
               : (_DefaultRuneLocale.__runetype[v1] & 0x500) != 0;
      if (!v3 && v1 != 95)
        break;
      v1 = i[1];
      if (!v1)
        return 1;
    }
  return 0;
}

int __cdecl Scr_IsInScriptMemory(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_IsInOpcodeMemory(char const *pos)
{
  return (unsigned int)&a1[-unk_100CEE8] < dword_114CF50;
}

unsigned int __cdecl SL_TransferToCanonicalString(unsigned int stringValue)
{
  _WORD *v1; // ecx
  int v2;    // edx

  SL_TransferRefToUser(a1, 2u);
  v1 = (_WORD *)(unk_114CF38 + 2 * a1);
  v2 = (unsigned __int16)*v1;
    if (!*v1) {
      *v1 = ++word_100CEA8;
      return word_100CEA8;
    }
  return v2;
}

void __cdecl Scr_BeginLoadAnimTrees(int user)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_BeginLoadScriptsRemote(void)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_GetCanonicalString(char const *str)
{
  int v1;              // ebx
  unsigned __int16 v2; // ax
  int v3;              // edx
  int String;          // ebx
  _WORD *v6;           // ecx

  v1 = unk_114CF38;
  v2 = *(_WORD *)(v1 + 2 * SL_FindString(a1));
  v3 = v2;
  if (v2)
    return v3;
  String = SL_GetString_(a1, 0);
  SL_TransferRefToUser(String, 2u);
  v6 = (_WORD *)(unk_114CF38 + 2 * String);
  v3 = (unsigned __int16)*v6;
  if (*v6)
    return v3;
  *v6 = ++word_100CEA8;
  return word_100CEA8;
}

void __cdecl Scr_EndLoadScripts()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EndLoadAnimTrees()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeScripts(unsigned char sys)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_BeginLoadScripts()
{
  byte_114CF44 = 1;
  Scr_InitOpcodeLookup();
  dword_114CF28 = Scr_AllocArray(a1);
  dword_114CF2C = Scr_AllocArray(a1);
  dword_114CF30 = Scr_AllocArray(a1);
  dword_114CF34 = Scr_AllocArray(a1);
  unk_100CEE8 = Hunk_AllocLowInternal(0);
  dword_114CF50 = 0;
  unk_100CEEC = 0;
  unk_100CEA4 = Hunk_SetMark();
  unk_114CF38 = Hunk_AllocInternal((size_t)&loc_20000);
  word_100CEA8 = 0;
  scrVarPub = 0;
  scrCompilePub[0] = 0;
  Scr_ClearErrorMessage();
  dword_114CF54 = 0;
  unk_114E438 = 1;
  unk_114E430 = 0;
  dword_114E22C[0] = 0;
  scrAnimPub = Scr_AllocArray(a1);
  dword_114E024 = 0;
  dword_114CF48 = 0;
  TempMemoryReset();
}

int __cdecl Scr_GetFunctionHandle(char const *filename, char const *name)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_PrecacheAnimTrees(void *(__cdecl *)(int), int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_LoadScript(char const *filename)
{
  UNIMPLEMENTED();
}

int marker_scr_main;

void __cdecl SL_EndLoadScripts(void)
{
  UNIMPLEMENTED();
}

void __cdecl SL_BeginLoadScripts(void)
{
  UNIMPLEMENTED();
}
