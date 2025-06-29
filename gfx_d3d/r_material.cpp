public:
long __cdecl D3DDevice::CreateVertexDeclaration(
    struct _D3DVERTEXELEMENT9 const *, struct D3DVertexDeclaration **) {
  UNIMPLEMENTED();
}

public:
unsigned long __cdecl D3DVertexDeclaration::Release(void) { UNIMPLEMENTED(); }

struct Material *__cdecl Material_ToHandle(struct Material *) {
  UNIMPLEMENTED();
}

struct Material const *__cdecl Material_FromHandle(struct Material *) {
  UNIMPLEMENTED();
}

void __cdecl std::sort<struct Material **,
                       bool(__cdecl *)(struct Material const *,
                                       struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::_Sort<struct Material **, int,
                        bool(__cdecl *)(struct Material const *,
                                        struct Material const *)>(
    struct Material **, struct Material **, int,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

struct std::pair<struct Material **, struct Material **> __cdecl std::
    _Unguarded_partition<struct Material **,
                         bool(__cdecl *)(struct Material const *,
                                         struct Material const *)>(
        struct Material **, struct Material **,
        bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::make_heap<struct Material **,
                            bool(__cdecl *)(struct Material const *,
                                            struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::sort_heap<struct Material **,
                            bool(__cdecl *)(struct Material const *,
                                            struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::_Insertion_sort<struct Material **,
                                  bool(__cdecl *)(struct Material const *,
                                                  struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

public:
__cdecl std::pair<struct Material **, struct Material **>::pair<
    struct Material **, struct Material **>(struct Material **const &,
                                            struct Material **const &) {
  UNIMPLEMENTED();
}

void __cdecl std::_Median<struct Material **,
                          bool(__cdecl *)(struct Material const *,
                                          struct Material const *)>(
    struct Material **, struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::iter_swap<struct Material **, struct Material **>(
    struct Material **, struct Material **) {
  UNIMPLEMENTED();
}

int *__cdecl std::_Dist_type<struct Material **>(struct Material **) {
  UNIMPLEMENTED();
}

struct Material **__cdecl std::_Val_type<struct Material **>(
    struct Material **) {
  UNIMPLEMENTED();
}

void __cdecl std::_Make_heap<struct Material **, int, struct Material *,
                             bool(__cdecl *)(struct Material const *,
                                             struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *), int *,
    struct Material **) {
  UNIMPLEMENTED();
}

void __cdecl std::pop_heap<struct Material **,
                           bool(__cdecl *)(struct Material const *,
                                           struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::rotate<struct Material **>(struct Material **,
                                             struct Material **,
                                             struct Material **) {
  UNIMPLEMENTED();
}

void __cdecl std::_Med3<struct Material **,
                        bool(__cdecl *)(struct Material const *,
                                        struct Material const *)>(
    struct Material **, struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::swap<struct Material *>(struct Material *&,
                                          struct Material *&) {
  UNIMPLEMENTED();
}

void __cdecl std::_Adjust_heap<struct Material **, int, struct Material *,
                               bool(__cdecl *)(struct Material const *,
                                               struct Material const *)>(
    struct Material **, int, int, struct Material *,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::_Pop_heap_0<struct Material **, struct Material *,
                              bool(__cdecl *)(struct Material const *,
                                              struct Material const *)>(
    struct Material **, struct Material **,
    bool(__cdecl *)(struct Material const *, struct Material const *),
    struct Material **) {
  UNIMPLEMENTED();
}

struct std::random_access_iterator_tag __cdecl std::_Iter_cat<
    struct Material **>(struct Material **const &) {
  UNIMPLEMENTED();
}

void __cdecl std::_Rotate<struct Material **>(
    struct Material **, struct Material **, struct Material **,
    struct std::random_access_iterator_tag) {
  UNIMPLEMENTED();
}

void __cdecl std::_Push_heap<struct Material **, int, struct Material *,
                             bool(__cdecl *)(struct Material const *,
                                             struct Material const *)>(
    struct Material **, int, int, struct Material *,
    bool(__cdecl *)(struct Material const *, struct Material const *)) {
  UNIMPLEMENTED();
}

void __cdecl std::_Pop_heap<struct Material **, int, struct Material *,
                            bool(__cdecl *)(struct Material const *,
                                            struct Material const *)>(
    struct Material **, struct Material **, struct Material **,
    struct Material *,
    bool(__cdecl *)(struct Material const *, struct Material const *), int *) {
  UNIMPLEMENTED();
}

void __cdecl std::_Rotate<struct Material **, int, struct Material *>(
    struct Material **, struct Material **, struct Material **, int *,
    struct Material **) {
  UNIMPLEMENTED();
}

void __cdecl Material_ReloadAll() {
  int result;                            // eax
  int v1;                                // ecx
  unsigned __int8 *v2;                   // edx
  _BYTE *v3;                             // edi
  int v4;                                // ecx
  int v5;                                // esi
  _DWORD *v6;                            // ebx
  int v7;                                // edx
  unsigned int v8;                       // edx
  unsigned __int8 *v9;                   // edx
  int v10;                               // edi
  int v11;                               // esi
  int (*v12)(_DWORD, const char *, ...); // ebx
  const char *v13;                       // eax
  unsigned __int8 *v14;                  // [esp+28h] [ebp-860h]
  char *v15;                             // [esp+2Ch] [ebp-85Ch]
  int v16;                               // [esp+30h] [ebp-858h]
  char *v17;                             // [esp+38h] [ebp-850h]
  int *v18;                              // [esp+3Ch] [ebp-84Ch]
  _DWORD *v19;                           // [esp+40h] [ebp-848h]
  unsigned __int8 *v20;                  // [esp+44h] [ebp-844h]
  char *v21;                             // [esp+48h] [ebp-840h]
  int *v22;                              // [esp+4Ch] [ebp-83Ch]
  int v23;                               // [esp+58h] [ebp-830h]
  _DWORD v24[4];                         // [esp+5Ch] [ebp-82Ch] BYREF
  _DWORD v25[512];                       // [esp+6Ch] [ebp-81Ch] BYREF
  int v26[7];                            // [esp+86Ch] [ebp-1Ch] BYREF

  v15 = (char *)&unk_C85B84;
  v22 = (int *)&unk_C85B88;
  do {
    result = *(v22 - 1);
    if (result) {
      v21 = v15;
      v16 = 0;
      while (1) {
        v1 = *v22;
        v23 = v1;
        v2 = (unsigned __int8 *)*(v22 - 1);
        v26[0] = 0;
        if (!v1)
          goto LABEL_18;
        v3 = (char *)&s_streamSourceInfo + 21 * v16 + 3 * *v2;
        if (*v3 != 0xFF)
          break;
      LABEL_31:
        result = 0;
      LABEL_21:
        *((_DWORD *)v21 + 2) = result;
        ++v16;
        v21 += 4;
        if (v16 == 4)
          goto LABEL_22;
      }
      v14 = v2 + 2;
      v20 = v2 + 2;
      v24[0] = 0;
      v17 = (char *)&s_streamDestInfo + 2 * v2[1];
    LABEL_15:
      v4 = v24[0];
      while (1) {
        LOWORD(v25[2 * v4]) = (unsigned __int8)*v3;
        HIWORD(v25[2 * v4]) = (unsigned __int8)v3[1];
        LOBYTE(v25[2 * v4 + 1]) = v3[2];
        BYTE1(v25[2 * v4 + 1]) = 0;
        BYTE2(v25[2 * v4 + 1]) = *v17;
        HIBYTE(v25[2 * v4 + 1]) = v17[1];
        ++v24[0];
        v9 = v14;
        if (v23 == v24[0])
          break;
        v3 = (char *)&s_streamSourceInfo + 21 * v16 + 3 * *v20;
        v20 += 2;
        if (*v3 == 0xFF)
          goto LABEL_31;
        v14 += 2;
        v17 = (char *)&s_streamDestInfo + 2 * v9[1];
        if (v24[0] <= 0)
          goto LABEL_15;
        v4 = v24[0] - 1;
        if ((unsigned __int8)*v3 >= (unsigned int)LOWORD(v24[2 * v24[0] + 2])) {
          v4 = v24[0];
        } else {
          v5 = v24[0];
          v19 = &v25[2 * v4];
          v6 = v19;
          while (1) {
            v7 = v6[1];
            v25[2 * v5] = *v6;
            v25[2 * v5 + 1] = v7;
            if (v4 <= 0)
              break;
            v8 = *(unsigned __int16 *)((char *)v6 + (char *)&v24[2 * v24[0]] -
                                       (char *)v19);
            v6 -= 2;
            if (v8 <= (unsigned __int8)*v3)
              break;
            v5 = v4--;
          }
        }
      }
      v1 = v23;
    LABEL_18:
      v25[2 * v1] = declEnd_131795;
      v25[2 * v1 + 1] = 17;
      do
        (*(void(__cdecl **)(int, _DWORD *, int *))(
            *(_DWORD *)dword_117D8A8 + 344))(dword_117D8A8, v25, v26);
      while (alwaysfails);
      result = v26[0];
      goto LABEL_21;
    }
  LABEL_22:
    v15 += 24;
    v22 += 6;
  } while (v15 != (char *)&unk_C85E84);
  v18 = materialGlobals;
  do {
    while (1) {
      v11 = v18[2407];
      if (!v11)
        goto LABEL_25;
      if (*(_BYTE *)(v11 + 10))
        break;
      result = (*(int(__cdecl **)(int, _DWORD, int))(
          *(_DWORD *)dword_117D8A8 + 364))(dword_117D8A8, *(_DWORD *)(v11 + 4),
                                           v11 + 12);
      v10 = result;
      if (result < 0)
        goto LABEL_29;
    LABEL_25:
      if (&unk_C85F80 == (_UNKNOWN *)++v18)
        return result;
    }
    result =
        (*(int(__cdecl **)(int, _DWORD, int))(*(_DWORD *)dword_117D8A8 + 424))(
            dword_117D8A8, *(_DWORD *)(v11 + 4), v11 + 12);
    v10 = result;
    if (result >= 0)
      goto LABEL_25;
  LABEL_29:
    v12 = dword_11806C4;
    v13 = (const char *)R_ErrorDescription();
    result = v12(0,
                 "Couldn't reload shader '%s' when recovering from a lost "
                 "device: %s (0x%08x)\n",
                 *(const char **)v11, v13, v10);
    ++v18;
  } while (&unk_C85F80 != (_UNKNOWN *)v18);
  return result;
}

void __cdecl Material_ReleaseAll() {
  char *v0;   // esi
  int v1;     // edi
  _DWORD *v2; // ebx
  int *v3;    // ebx
  int result; // eax
  char *v5;   // [esp+1Ch] [ebp-1Ch]

  RB_ReleaseVertexDecl();
  v5 = (char *)&unk_C85B84;
  do {
    v0 = v5;
    v1 = 4;
    do {
      v2 = v0 + 8;
      if (*((_DWORD *)v0 + 2)) {
        do {
          (*(void(__cdecl **)(_DWORD))(*(_DWORD *)*v2 + 8))(*v2);
          *v2 = 0;
        } while (alwaysfails);
      }
      v0 += 4;
      --v1;
    } while (v1);
    v5 += 24;
  } while (v5 != (char *)&unk_C85E84);
  v3 = materialGlobals;
  do {
    result = v3[2407];
    if (result)
      result = (*(int(__cdecl **)(_DWORD))(**(_DWORD **)(result + 12) + 8))(
          *(_DWORD *)(result + 12));
    ++v3;
  } while (v3 != (int *)&unk_C85F80);
  return result;
}

void __cdecl Material_FinishLoading() { ; }

struct Material *__cdecl Material_LoadRawImage(char const *, int) {
  UNIMPLEMENTED();
}

bool __cdecl Material_IsDefault(struct Material const *material) {
  _DWORD *v1; // edx

  v1 = (_DWORD *)rgp[1035];
  return *(_DWORD *)a1->textures == v1[15] && a1->constants == v1[16] &&
         a1->techniqueSet == v1[14];
}

void __cdecl Material_DirtySort(void) { UNIMPLEMENTED(); }

void *__cdecl Material_Alloc(int size) {
  return (*(int (**)(void)) & algn_11806C8[4])();
}

bool __cdecl R_IsMaterialRefractive(struct Material *) {
  int v1;        // eax
  _BOOL4 result; // eax

  result = 0;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2) {
    v1 = *(_DWORD *)(a1->techniqueSet + 88);
    if (v1) {
      if ((*(_BYTE *)(v1 + 4) & 1) != 0)
        return 1;
    }
  }
  return result;
}

int __cdecl R_GetMaterialSubimageCount(struct Material *handle) {
  return a1->info.textureAtlasRowCount * a1->info.textureAtlasColumnCount;
}

char const *__cdecl R_GetMaterialName(struct Material *handle) {
  return *(_DWORD *)a1->info.name;
}

struct Material *__cdecl R_RegisterRawImage(char const *name,
                                            int baseImageFlags,
                                            int imageTrack) {
  _DWORD *v1; // edx
  _DWORD *v3; // ecx

  if (!*a1)
    return (_DWORD *)rgp[1035];
  v1 = (_DWORD *)rgp[1036];
  v3 = (_DWORD *)rgp[1035];
  if (v1[15] == v3[15] && v1[16] == v3[16] && v1[14] == v3[14])
    return v1;
  Image_Release((GfxImage *)rgp[1062]);
  if ((unsigned __int8)Image_LoadRaw((GfxImage *)rgp[1062], a1))
    return (_DWORD *)rgp[1036];
  else
    return (_DWORD *)rgp[1035];
}

void __cdecl Material_Sort() { UNIMPLEMENTED(); }

void __cdecl Unload_Material(struct Material *) { UNIMPLEMENTED(); }

struct Material *__cdecl Material_Register(char const *name, int imageTrack) {
  int v2;          // eax
  unsigned int v3; // ebx
  int v4;          // esi
  const char **v5; // eax
  char *v6;        // eax
  char *v7;        // ebx
  int v8;          // eax

  v2 = R_HashAssetName(__s2);
  v3 = v2 & 0xFFFF03FF;
  v4 = v2 & 0x3FF;
  v5 = *(const char ***)&rg[4 * v4 + 40];
  if (v5) {
    while (strcmp(*v5, __s2)) {
      ++v3;
      LOWORD(v3) = v3 & 0x3FF;
      v4 = (unsigned __int16)v3;
      v5 = *(const char ***)&rg[4 * (unsigned __int16)v3 + 40];
      if (!v5)
        goto LABEL_4;
    }
    return *(int **)&rg[4 * v4 + 40];
  } else {
  LABEL_4:
    v6 = Material_Load(__s2, a2);
    v7 = v6;
    if (v6) {
      rgp[0] = 1;
      *((_WORD *)v6 + 4) = v4;
      *((_WORD *)v6 + 5) = rgp[1];
      v8 = rgp[1];
      rgp[v8 + 2] = v7;
      *(_DWORD *)&rg[4 * v4 + 40] = v7;
      rgp[1] = ++v8;
      if (v8 == 1024)
        R_Error(ERR_FATAL, "Too many unique materials (%i or more)\n", 1024);
      return (int *)v7;
    } else {
      if (!rgp[1035])
        R_Error(ERR_FATAL, "couldn't load material '$default'");
      Com_Printf("^3WARNING: Could not find material '%s'\n", __s2);
      return Material_Duplicate((Material *)rgp[1035], __s2);
    }
  }
}

struct Material *__cdecl Material_RegisterHandle(char const *name,
                                                 int baseImageFlags,
                                                 int imageTrack) {
  if (*a1)
    return Material_Register(a1, a3);
  else
    return (int *)rgp[1035];
}

void __cdecl Material_Init() { UNIMPLEMENTED(); }

void __cdecl Load_CreateMaterialShader(union MaterialShaderPtr *,
                                       struct MaterialShader *) {
  UNIMPLEMENTED();
}

void __cdecl Load_BuildVertexDecl(
    struct MaterialVertexDeclaration **mtlVertDecl) {
  unsigned __int8 *data; // edx
  char *v2;              // edi
  int v3;                // ecx
  _DWORD *v4;            // ebx
  int v5;                // esi
  int v6;                // edx
  unsigned int v7;       // edx
  unsigned __int8 *v8;   // edx
  int result;            // eax
  char *v10;             // [esp+18h] [ebp-850h]
  unsigned __int8 *v11;  // [esp+1Ch] [ebp-84Ch]
  int v12;               // [esp+20h] [ebp-848h]
  int v13;               // [esp+24h] [ebp-844h]
  char *v14;             // [esp+28h] [ebp-840h]
  uint32_t streamCount;  // [esp+2Ch] [ebp-83Ch]
  _DWORD *v16;           // [esp+30h] [ebp-838h]
  unsigned __int8 *v17;  // [esp+34h] [ebp-834h]
  int v18;               // [esp+38h] [ebp-830h]
  _DWORD v19[4];         // [esp+3Ch] [ebp-82Ch] BYREF
  _DWORD v20[512];       // [esp+4Ch] [ebp-81Ch] BYREF
  int v21[7];            // [esp+84Ch] [ebp-1Ch] BYREF

  v13 = 0;
  v10 = (char *)&s_streamSourceInfo;
  do {
    v12 = (int)*a1;
    streamCount = (*a1)->streamCount;
    data = (unsigned __int8 *)(*a1)->data;
    v21[0] = 0;
    if (streamCount) {
      v2 = &v10[3 * *data];
      if (*v2 == -1) {
      LABEL_19:
        result = 0;
        goto LABEL_17;
      }
      v11 = data + 2;
      v17 = data + 2;
      v18 = 0;
      v14 = (char *)&s_streamDestInfo + 2 * data[1];
    LABEL_13:
      v3 = v18;
      while (1) {
        LOWORD(v20[2 * v3]) = (unsigned __int8)*v2;
        HIWORD(v20[2 * v3]) = (unsigned __int8)v2[1];
        LOBYTE(v20[2 * v3 + 1]) = v2[2];
        BYTE1(v20[2 * v3 + 1]) = 0;
        BYTE2(v20[2 * v3 + 1]) = *v14;
        HIBYTE(v20[2 * v3 + 1]) = v14[1];
        ++v18;
        v8 = v11;
        if (streamCount == v18)
          break;
        v2 = &v10[3 * *v17];
        v17 += 2;
        if (*v2 == -1)
          goto LABEL_19;
        v11 += 2;
        v14 = (char *)&s_streamDestInfo + 2 * v8[1];
        if (v18 <= 0)
          goto LABEL_13;
        v3 = v18 - 1;
        if (LOWORD(v19[2 * v18 + 2]) <= (unsigned int)(unsigned __int8)*v2)
          goto LABEL_13;
        v16 = &v20[2 * v3];
        v4 = v16;
        v5 = v18;
        while (1) {
          v6 = v4[1];
          v20[2 * v5] = *v4;
          v20[2 * v5 + 1] = v6;
          if (v3 <= 0)
            break;
          v19[0] = v3 - 1;
          v7 = *(unsigned __int16 *)((char *)v4 + (char *)&v19[2 * v18] -
                                     (char *)v16);
          v4 -= 2;
          if ((unsigned __int8)*v2 >= v7)
            break;
          v5 = v3;
          v3 = v19[0];
        }
      }
    }
    v20[2 * streamCount] = declEnd_131795;
    v20[2 * streamCount + 1] = 17;
    do
      (*(void(__cdecl **)(int, _DWORD *, int *))(*(_DWORD *)dword_117D8A8 +
                                                 344))(dword_117D8A8, v20, v21);
    while (alwaysfails);
    result = v21[0];
  LABEL_17:
    *(_DWORD *)(v12 + 4 * v13++ + 8) = result;
    v10 += 21;
  } while (v13 != 4);
  return result;
}

int marker_r_material;
bool __cdecl Material_Compare(struct Material const *,
                              struct Material const *) {
  unsigned int v2; // eax

  v2 = (unsigned __int8)a1->info.sortKey - (unsigned __int8)a2->info.sortKey;
  if (v2)
    return v2 >> 31;
  v2 = a1->techniqueSet - a2->techniqueSet;
  if (v2)
    return v2 >> 31;
  else
    return 0;
}

void __cdecl Material_LoadBuiltIn(struct BuiltInMaterialTable const *const,
                                  int) {
  UNIMPLEMENTED();
}

struct D3DVertexDeclaration *__cdecl Material_BuildVertexDecl(
    struct MaterialStreamRouting const *, int,
    struct stream_source_info_t const *const) {
  UNIMPLEMENTED();
}

Material_RegisterLiteral(float const *) { UNIMPLEMENTED(); }

Material_SetTechnique(char const *name, MaterialTechnique *technique) {
  UNIMPLEMENTED();
}

Material_SetTechniqueSet(char const *name, MaterialTechniqueSet *techniqueSet) {
  UNIMPLEMENTED();
}

Material_SetStateMap(char const *name, MaterialStateMap *stateMap) {
  UNIMPLEMENTED();
}

Material_SetShader(char const *shaderName, MaterialShaderType shaderType,
                   int shaderVersion, MaterialShader *mtlShader) {
  UNIMPLEMENTED();
}

Material_UpdatePicmipAll() { UNIMPLEMENTED(); }

Material_LoadFile(char const *filename, int *file) { UNIMPLEMENTED(); }

void std::__adjust_heap<Material **, int, Material *,
                        unsigned char (*)(Material const *, Material const *)>(
    Material **, int, int, Material *,
    unsigned char (*)(Material const *, Material const *)) {
  UNIMPLEMENTED();
}

void std::__insertion_sort<Material **, unsigned char (*)(Material const *,
                                                          Material const *)>(
    Material **, Material **,
    unsigned char (*)(Material const *, Material const *)) {
  UNIMPLEMENTED();
}

void std::__introsort_loop<
    Material **, int, unsigned char (*)(Material const *, Material const *)>(
    Material **, Material **, int,
    unsigned char (*)(Material const *, Material const *)) {
  UNIMPLEMENTED();
}

Material_RegisterString(char const *string) { UNIMPLEMENTED(); }

Material_AllocVertexDecl(MaterialStreamRouting *routingData, int streamCount,
                         unsigned char *existing) {
  UNIMPLEMENTED();
}

Material_FindStateMap(char const *name) { UNIMPLEMENTED(); }

Material_FindTechniqueSet(char const *name) { UNIMPLEMENTED(); }

Material_FindTechnique(char const *name) { UNIMPLEMENTED(); }

Material_FindShader(char const *shaderName, MaterialShaderType shaderType,
                    int shaderVersion) {
  UNIMPLEMENTED();
}

Material_Shutdown() { UNIMPLEMENTED(); }

R_Cmd_ReloadMaterialTextures() { UNIMPLEMENTED(); }

Material_Duplicate(Material *mtlCopy, char const *name) { UNIMPLEMENTED(); }
