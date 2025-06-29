char *__cdecl vtos(float const *const v)
{
  char *v1; // ebx

  v1 = (char *)&vtos(float const *)::str + 32 * vtos(float const *)::index;
  vtos(float const *)::index = ((_BYTE)vtos(float const *)::index + 1) & 7;
  Com_sprintf(v1, 0x20u, "(%i %i %i)", (int)*a1, (int)a1[1], (int)a1[2]);
  return v1;
}

int __cdecl G_SpawnStringInternal(struct SpawnVar *spawnVar, char const *key,
                                  char const *defaultString, char const **out)
{
  signed int numSpawnVars; // edi
  SpawnVar *v6;            // ebx
  int v7;                  // esi

  numSpawnVars = a1->numSpawnVars;
    if (numSpawnVars > 0) {
      v6 = a1;
      v7 = 0;
        while (strcmp(__s1, *(const char **)v6->spawnVars)) {
          ++v7;
          v6 = (SpawnVar *)((char *)v6 + 8);
          if (numSpawnVars == v7)
            goto LABEL_2;
        }
      *a4 = *(const char **)&a1->spawnVars[8 * v7 + 4];
      return 1;
    }
    else {
    LABEL_2:
      *a4 = a3;
      return 0;
    }
}

unsigned int __cdecl G_NewString(char const *string)
{
  UNIMPLEMENTED();
}

int __cdecl G_ParseSpawnVars(struct SpawnVar *spawnVar)
{
  UNIMPLEMENTED();
}

int marker_g_load_utils;

char *__cdecl G_AddSpawnVarToken(char const *, struct SpawnVar *)
{
  UNIMPLEMENTED();
}
