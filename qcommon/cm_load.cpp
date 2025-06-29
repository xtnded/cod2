int __cdecl Path_BuildChains(unsigned short **, unsigned short **) {
  UNIMPLEMENTED();
}

void __cdecl Path_LoadPaths(int *, unsigned char **, int *,
                            struct pathnode_tree_t **) {
  UNIMPLEMENTED();
}

int __cdecl Path_GetLoadPathNodeCount(void) { UNIMPLEMENTED(); }

struct pathnode_t *__cdecl Path_CreateNodes(void) {
  UNIMPLEMENTED();
}

int __cdecl CM_LeafCluster(int leafnum) {
  return *(__int16 *)(dword_1007E48 + 44 * a1 + 40);
}

char const *__cdecl CM_EntityString() { return dword_1007EB8; }

int __cdecl CM_NumInlineModels() { return dword_1007E94; }

void __cdecl CM_Shutdown() { UNIMPLEMENTED(); }

void __cdecl CM_ModelBounds(int model, float *const mins, float *const maxs) {
  int v3;     // eax
  int result; // eax

  v3 = CM_ClipHandleToModel(a1);
  *a2 = *(float *)v3;
  a2[1] = *(float *)(v3 + 4);
  a2[2] = *(float *)(v3 + 8);
  *a3 = *(float *)(v3 + 12);
  a3[1] = *(float *)(v3 + 16);
  result = *(_DWORD *)(v3 + 20);
  *((_DWORD *)a3 + 2) = result;
  return result;
}

void __cdecl CM_Unload(void) { UNIMPLEMENTED(); }

void __cdecl CM_LoadMap(char const *name, int *checksum) { UNIMPLEMENTED(); }

int marker_cm_load;
struct clipMap_t cm;
void __cdecl CM_LoadMapInternal(char const *) { UNIMPLEMENTED(); }

void __cdecl CM_InitThreadData(int) { UNIMPLEMENTED(); }

void __cdecl CM_InitAllThreadData(void) { UNIMPLEMENTED(); }

CM_Hunk_Alloc(int size, char const *name, int type) { UNIMPLEMENTED(); }

CM_Hunk_CheckTempMemoryClear() { UNIMPLEMENTED(); }

CM_Hunk_CheckTempMemoryHighClear() { UNIMPLEMENTED(); }

CM_Hunk_AllocateTempMemoryHigh(int size, char const *name) { UNIMPLEMENTED(); }

CM_Hunk_ClearTempMemory() { UNIMPLEMENTED(); }

CM_Hunk_ClearTempMemoryHigh() { UNIMPLEMENTED(); }

CM_SaveLump(int lumpnum, unsigned char *newLump, int size, int *checksum) {
  UNIMPLEMENTED();
}
