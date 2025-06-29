char const *__cdecl FS_GetMapBaseName(char const *mapname)
{
  int v1;             // eax
  const char *v2;     // edx
  unsigned int v3;    // esi
  signed __int32 v4;  // ebx
  char *v5;           // eax
  char *v6;           // edx
  const char *__srca; // [esp+30h] [ebp+8h]

  v1 = I_strnicmp(__src, "maps/mp/", 8);
  v2 = __src + 8;
  if (v1)
    v2 = __src;
  __srca = v2;
  v3 = strlen(v2) + 1;
  v4 = v3 - 1;
  if (!stricmp(&v2[v3 - 4], "bsp"))
    v4 = v3 - 8;
  memcpy(FS_GetMapBaseName(char const *)::basename, __srca, v4);
  FS_GetMapBaseName(char const *)::basename[v4] = 0;
    if (v4 > 0) {
      v5 = FS_GetMapBaseName(char const *)::basename;
      v6 = &FS_GetMapBaseName(char const *)::basename[v4];
        do {
            while (*v5 != 37) {
              if (++v5 == v6)
                return FS_GetMapBaseName(char const *)::basename;
            }
          *v5++ = 95;
        }
      while (v5 != v6);
    }
  return FS_GetMapBaseName(char const *)::basename;
}

int marker_files;

FS_SV_FOpenFileWrite(char const *filename)
{
  UNIMPLEMENTED();
}

FS_SV_FOpenFileRead(char const *filename, int *fp)
{
  UNIMPLEMENTED();
}

FS_SV_Rename(char const *from, char const *to)
{
  UNIMPLEMENTED();
}

FS_ShiftStr(char const *string, int shift)
{
  UNIMPLEMENTED();
}

FS_Dir_f()
{
  UNIMPLEMENTED();
}

FS_NewDir_f()
{
  UNIMPLEMENTED();
}

FS_TouchFile_f()
{
  UNIMPLEMENTED();
}

FS_iwIwd(char *iwd, char *base)
{
  UNIMPLEMENTED();
}

FS_AddCommands()
{
  UNIMPLEMENTED();
}

FS_SetRestrictions()
{
  UNIMPLEMENTED();
}

FS_LoadedIwdChecksums()
{
  UNIMPLEMENTED();
}

FS_LoadedIwdNames()
{
  UNIMPLEMENTED();
}

FS_LoadedIwdPureChecksums()
{
  UNIMPLEMENTED();
}

FS_ReferencedIwdChecksums()
{
  UNIMPLEMENTED();
}

FS_ReferencedIwdNames()
{
  UNIMPLEMENTED();
}

FS_ReferencedIwdPureChecksums()
{
  UNIMPLEMENTED();
}

FS_PureServerSetLoadedIwds(char const *iwdSums, char const *iwdNames)
{
  UNIMPLEMENTED();
}

FS_PureServerSetReferencedIwds(char const *iwdSums, char const *iwdNames)
{
  UNIMPLEMENTED();
}

FS_GetModList(char *listbuf, int bufsize)
{
  UNIMPLEMENTED();
}

FS_CompareIwds(char *needediwds, int len, int dlstring)
{
  UNIMPLEMENTED();
}
