char const *__cdecl BG_GetWeaponSlotNameForIndex(int iSlot)
{
  return szWeapSlotNames[a1];
}

int __cdecl BG_GetWeaponSlotForName(char const *)
{
  int v1;         // esi
  const char **i; // ebx

  v1 = 0;
    for (i = (const char **)szWeapSlotNames; stricmp(a1, *i); ++i) {
        if (++v1 == 3) {
          LOWORD(v1) = 0;
          return v1;
        }
    }
  return v1;
}

char const *__cdecl BG_GetWeaponTypeName(enum weapType_t)
{
  UNIMPLEMENTED();
}

void __cdecl BG_LoadWeaponStrings()
{
  UNIMPLEMENTED();
}

void __cdecl BG_LoadPlayerAnimTypes()
{
  UNIMPLEMENTED();
}

int marker_bg_weapons_load_obj;

SetConfigString(char **ppszConfigString, char const *pszKeyValue)
{
  UNIMPLEMENTED();
}

BG_LoadDefaultWeaponDef()
{
  UNIMPLEMENTED();
}

BG_LoadWeaponDefInternal(char const *folder, char const *name)
{
  UNIMPLEMENTED();
}
