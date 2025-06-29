char const *__cdecl Com_SurfaceTypeToName(int iTypeIndex) {
  if ((unsigned int)(a1 - 1) > 0x15)
    return "default";
  else
    return (&infoParms)[5 * a1 - 5];
}

int __cdecl Com_SurfaceTypeFromName(char const *name) {
  unsigned int result; // eax
  int v2;              // esi
  const char **v3;     // ebx

  result = stricmp(a1, "default");
  if (result) {
    v2 = 0;
    v3 = (const char **)&infoParms;
    do {
      if (!stricmp(a1, *v3))
        return ((unsigned int)*(&off_30F6A8 + 5 * v2) & 0x1F00000) >> 20;
      ++v2;
      v3 += 5;
    } while (v2 != 22);
    return -1;
  }
  return result;
}

int marker_surfaceflags;
