
void LargeLocalReset(void)
{
  g_largeLocalPos = 0;
}

void *__cdecl LargeLocalGetBuf(int) { UNIMPLEMENTED(); }

void __cdecl LargeLocalEnd(int) { UNIMPLEMENTED(); }

int __cdecl LargeLocalBegin(int) { UNIMPLEMENTED(); }

void __cdecl Hunk_ConvertTempToPermLowInternal() {
  int result; // eax

  result = dword_3BCF8C;
  hunk_low = dword_3BCF8C;
  return result;
}

public:
void *__cdecl LargeLocal::GetBuf() { UNIMPLEMENTED(); }

public:
__cdecl LargeLocal::~LargeLocal() { UNIMPLEMENTED(); }

public:
__cdecl LargeLocal::LargeLocal(int size) { UNIMPLEMENTED(); }

void *__cdecl XenonHunkMalloc(unsigned int) { UNIMPLEMENTED(); }

void *__cdecl Hunk_ReallocateTempMemoryInternal(int size) { UNIMPLEMENTED(); }

void *__cdecl Hunk_AllocLowAlignInternal(int size, int alignment) {
  void *v2; // edi

  v2 = (void *)(s_hunkData + (~(a2 - 1) & (hunk_low + a2 - 1)));
  hunk_low = (~(a2 - 1) & (hunk_low + a2 - 1)) + __len;
  dword_3BCF8C = hunk_low;
  if (hunk_low + dword_3BCF84 > s_hunkTotal)
    Com_Error(1,
              "\x15Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i "
              "MB, high %i MB)",
              __len);
  memset(v2, 0, __len);
  return v2;
}

void *__cdecl Hunk_AllocLowInternal(int size) {
  void *v1; // edi

  v1 = (void *)(s_hunkData + ((hunk_low + 31) & 0xFFFFFFE0));
  hunk_low = __len + ((hunk_low + 31) & 0xFFFFFFE0);
  dword_3BCF8C = hunk_low;
  if (hunk_low + dword_3BCF84 > s_hunkTotal)
    Com_Error(1,
              "\x15Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i "
              "MB, high %i MB)",
              __len);
  memset(v1, 0, __len);
  return v1;
}

void *__cdecl Hunk_AllocAlignInternal(int size, int alignment) {
  void *v2; // ebx

  hunk_high = ~(a2 - 1) & (a2 - 1 + hunk_high + __len);
  v2 = (void *)(s_hunkData + s_hunkTotal - hunk_high);
  dword_3BCF84 = hunk_high;
  if (s_hunkTotal < hunk_high + dword_3BCF8C)
    Com_Error(1,
              "\x15Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB, "
              "high %i MB)",
              __len);
  memset(v2, 0, __len);
  return v2;
}

void *__cdecl Hunk_AllocInternal(int size) {
  void *v1; // ebx

  hunk_high = (hunk_high + __len + 31) & 0xFFFFFFE0;
  v1 = (void *)(s_hunkData + s_hunkTotal - hunk_high);
  dword_3BCF84 = hunk_high;
  if (s_hunkTotal < hunk_high + dword_3BCF8C)
    Com_Error(1,
              "\x15Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB, "
              "high %i MB)",
              __len);
  memset(v1, 0, __len);
  return v1;
}

int marker_com_memory;
struct dvar_s const *const com_dedicated;
void *__cdecl Hunk_FindDataForFileInternal(int, char const *, int) {
  UNIMPLEMENTED();
}

void __cdecl Z_MallocFailed(int) { UNIMPLEMENTED(); }

// TODO: FIXME replace with macro __FILE__ and __LINE__
void *Z_MallocInternal(size_t __size)
{
  void *ptr = malloc(__size);
  if ( !ptr )
    Sys_OutOfMemErrorInternal("/Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp", 220);
  Com_Memset(ptr, 0, __size);
  return ptr;
}

void __cdecl Hunk_ClearDataFor(struct fileData_s **, unsigned char *,
                               unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl Hunk_ClearData(void) {
  unsigned int v1;    // edi
  unsigned int v2;    // esi
  int *v3;            // ebx
  unsigned int v4;    // edx
  unsigned __int8 v5; // al
  int *v6;            // ebx
  unsigned int v7;    // edx
  unsigned __int8 v8; // al
  int i;              // [esp+1Ch] [ebp-1Ch]

  v1 = hunk_low + s_hunkData;
  v2 = s_hunkTotal + s_hunkData - hunk_high;
  for (i = 0; i != 1024; ++i) {
    v3 = &com_fileDataHashTable[i];
  LABEL_3:
    while (1) {
      v4 = *v3;
      if (!*v3)
        break;
      while (1) {
        if (v1 > v4 || v2 <= v4) {
          v3 = (int *)(v4 + 4);
          goto LABEL_3;
        }
        *v3 = *(_DWORD *)(v4 + 4);
        v5 = *(_BYTE *)(v4 + 8);
        if (v5 == 4) {
          XModelFree(a1, *(XModel **)v4);
          goto LABEL_3;
        }
        if (v5 > 4u)
          break;
        if (v5 != 3)
          goto LABEL_3;
        XModelPartsFree(a1, *(XModelParts_s **)v4);
        v4 = *v3;
        if (!*v3)
          goto LABEL_10;
      }
      if (v5 == 5) {
        XAnimFree(a1, *(XAnimParts_s **)v4);
      } else if (v5 == 6) {
        XAnimFreeList(*(XAnim_s **)v4);
      }
    }
  LABEL_10:;
  }
  v6 = &com_hunkData;
LABEL_12:
  while (1) {
    v7 = *v6;
    if (!*v6)
      break;
    while (1) {
      if (v1 > v7 || v2 <= v7) {
        v6 = (int *)(v7 + 4);
        goto LABEL_12;
      }
      *v6 = *(_DWORD *)(v7 + 4);
      v8 = *(_BYTE *)(v7 + 8);
      if (v8 == 4) {
        XModelFree(a1, *(XModel **)v7);
        goto LABEL_12;
      }
      if (v8 > 4u)
        break;
      if (v8 != 3)
        goto LABEL_12;
      XModelPartsFree(a1, *(XModelParts_s **)v7);
      v7 = *v6;
      if (!*v6)
        return;
    }
    if (v8 == 5) {
      XAnimFree(a1, *(XAnimParts_s **)v7);
    } else if (v8 == 6) {
      XAnimFreeList(*(XAnim_s **)v7);
    }
  }
}

void __cdecl Com_Meminfo_f(void) {
  Com_Printf("%8i bytes total hunk\n", s_hunkTotal);
  Com_Printf("\n");
  Com_Printf("%8i low permanent\n", hunk_low);
  if (dword_3BCF8C != hunk_low)
    Com_Printf("%8i low temp\n", dword_3BCF8C);
  Com_Printf("\n");
  Com_Printf("%8i high permanent\n", hunk_high);
  if (dword_3BCF84 != hunk_high)
    Com_Printf("%8i high temp\n", dword_3BCF84);
  Com_Printf("\n");
  Com_Printf("%8i total hunk in use\n", hunk_high + hunk_low);
  Com_Printf("\n");
}

DB_EnumXAssets(int, void (*)(XAssetHeader, void *), void *, unsigned char) {
  UNIMPLEMENTED();
}

Hunk_AllocNoZeroInternal(int size) { UNIMPLEMENTED(); }
