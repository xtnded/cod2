public:
long __cdecl D3DDevice::DrawIndexedPrimitive(enum _D3DPRIMITIVETYPE, int,
                                             unsigned int, unsigned int,
                                             unsigned int, unsigned int) {
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::DrawIndexedPrimitiveUP(enum _D3DPRIMITIVETYPE,
                                               unsigned int, unsigned int,
                                               unsigned int, void const *,
                                               enum _D3DFORMAT, void const *,
                                               unsigned int) {
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetVertexDeclaration(struct D3DVertexDeclaration *) {
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetVertexShaderConstantF(unsigned int, float const *,
                                                 unsigned long) {
  UNIMPLEMENTED();
}

void __cdecl Vec4Add(float const *const, float const *const, float *const) {
  UNIMPLEMENTED();
}

struct D3DIndexBuffer *__cdecl R_IndexBufferPointer(struct r_ib_state_t *) {
  UNIMPLEMENTED();
}

int __cdecl R_GetSmodelCachedVertexSize(void) { UNIMPLEMENTED(); }

void __cdecl R_SetDrawPrimType(struct GfxDrawPrimArgs *, enum GfxDrawPrimType) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetCodeConstantFromVec3(int, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetState(int *const) { UNIMPLEMENTED(); }

void __cdecl RB_SetStreamSource(int, struct D3DVertexBuffer *, int, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetPixelShader(struct D3DPixelShader *) { UNIMPLEMENTED(); }

void __cdecl RB_SetVertexShader(struct D3DVertexShader *) { UNIMPLEMENTED(); }

void __cdecl RB_SetVertexDecl(struct D3DVertexDeclaration *) {
  UNIMPLEMENTED();
}

void __cdecl RB_BeginSurface(struct Material const *material,
                             enum MaterialTechniqueType techType,
                             int lmapIndex) {
  int *result; // eax

  result = tess;
  dword_11E15CC = 0;
  unk_11E15B8 = 0;
  *(_DWORD *)((char *)&loc_5A7D0 + (_DWORD)tess) = 0;
  dword_11E15D4 = 0;
  *(_DWORD *)((char *)&loc_5A7D8 + (_DWORD)tess) = 0;
  *(_DWORD *)&algn_11E15D8[4] = 0;
  dword_11E15BC = (Material *)a1;
  dword_11E15C0 = a2;
  dword_11E15C4 = a3;
  return result;
}

void __cdecl RB_CreateDynamicBuffers() {
  int result; // eax

  dword_11E15B0 = (*(int(__cdecl **)(int)) & algn_11806C8[4])(0x200000);
  result = (*(int(__cdecl **)(int)) & algn_11806C8[4])(0x200000);
  unk_11E15B4 = result;
  return result;
}

int __cdecl RB_SetIndexData(unsigned short const *, int) {
  size_t v2;                 // edi
  int *v3;                   // edx
  bool v4;                   // al
  int v5;                    // ecx
  IDirect3DIndexBuffer9 *v6; // ebx
  unsigned int v8;           // [esp+2Ch] [ebp-2Ch]
  void *__dst[7];            // [esp+3Ch] [ebp-1Ch] BYREF

  v2 = 2 * a2;
  v3 = (int *)dword_118062C;
  v4 = *(_DWORD *)dword_118062C + 2 * a2 > *(_DWORD *)(dword_118062C + 4);
  if (*(_DWORD *)dword_118062C + 2 * a2 > *(_DWORD *)(dword_118062C + 4)) {
    *(_DWORD *)dword_118062C = 0;
    v3 = (int *)dword_118062C;
  }
  if (!*v3) {
    v3 = &dword_1180620;
    dword_118062C = (int)&dword_1180620;
  }
  v5 = *v3;
  v8 = (unsigned int)*v3 >> 1;
  v6 = (IDirect3DIndexBuffer9 *)v3[2];
  if (v4 || !dword_11804C0 && !v5) {
    if ((*(int(__cdecl **)(IDirect3DIndexBuffer9 *, int, size_t, void **, int))(
            *(_DWORD *)v6 + 44))(v6, v5, v2, __dst, 0x2000) >= 0)
      goto LABEL_11;
    goto LABEL_8;
  }
  if ((*(int(__cdecl **)(IDirect3DIndexBuffer9 *, int, size_t, void **, int))(
          *(_DWORD *)v6 + 44))(v6, v5, v2, __dst, 4096) < 0)
  LABEL_8:
    R_FatalLockError();
LABEL_11:
  Com_Memcpy(__dst[0], __src, v2);
  do
    (*(void(__cdecl **)(IDirect3DIndexBuffer9 *))(*(_DWORD *)v6 + 48))(v6);
  while (alwaysfails);
  if (v6 != (IDirect3DIndexBuffer9 *)dword_1186CCC)
    RB_ChangeIndices(v6);
  *(_DWORD *)dword_118062C += v2;
  return v8;
}

void __cdecl RB_DrawTechnique(enum MaterialVertexDeclType vertDeclType,
                              struct GfxDrawPrimArgs const *args) {
  UNIMPLEMENTED();
}

void __cdecl RB_EndSurface() { UNIMPLEMENTED(); }

int marker_rb_shade;
bool __cdecl RB_ApplyStateBitsRemapRuleSet(
    int const *const, struct MaterialStateMapRuleSet const *, int *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_GetShaderConstantFromMaterial(char const *, float const **,
                                              int *) {
  UNIMPLEMENTED();
}

void __cdecl RB_ScaleMatrixRotation(float const *, float, float *) {
  UNIMPLEMENTED();
}

void __cdecl RB_OverrideGrayscaleImage(struct GfxImage **, unsigned char *,
                                       struct dvar_s const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_GenerateWorldOutdoorLookupMatrix(float (*const)[4]) {
  UNIMPLEMENTED();
}

float const *__cdecl RB_GetCodeMatrix(int, int, int) { UNIMPLEMENTED(); }

void __cdecl RB_GetShaderConstantFromCode(
    struct MaterialArgumentCodeConst const *, float const **, int *) {
  UNIMPLEMENTED();
}

unsigned short *__cdecl RB_CreateDynamicBuffer(struct D3DIndexBuffer *, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_RemapStateBits(int const *const,
                               struct MaterialStateMap const *, int *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetPixelShaderConstant(int, float const *, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetVertexShaderConstant(int, float const *, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetPassVertexShaderArguments(
    struct MaterialShaderArgument const *, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_OverrideImage(struct GfxImage **, unsigned char *,
                              struct MaterialTextureDef const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_GetTextureFromMaterial(char const *, struct GfxImage **,
                                       unsigned char *) {
  UNIMPLEMENTED();
}

bool __cdecl RB_SkipTechnique(struct MaterialTechnique const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_DrawIndexedPrimitive(struct GfxDrawPrimArgs const *,
                                     struct MaterialTechnique const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetupLighting(void) {
  int v0;         // edx
  __int32 result; // eax
  int v2;         // edx

  if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
    result = dword_11E15C0 - 15;
    if ((unsigned int)(dword_11E15C0 - 15) > 2) {
      v2 = dword_11E1A44;
      if (dword_11E1A44) {
        if (*(_DWORD *)dword_11E1A44 != dword_11E19B4) {
          RB_SetupEntityLighting(dword_11E1A40,
                                 (GfxEntityLighting *)dword_11E1A44);
          v2 = dword_11E1A44;
        }
        return RB_SetEntityHwLightsDx7((float *)(v2 + 8), *(_DWORD *)(v2 + 4));
      } else if (dword_11E1A40->reType == 2) {
        return RB_SetEntityHwLightsDx7(
            (float *)dword_11E1A40->lighting.dx7.colorForDir,
            dword_11E1A40->lighting.dx7.sunVisibility);
      }
    }
  } else {
    v0 = dword_11E1A44;
    if (dword_11E1A44) {
      if (*(_DWORD *)dword_11E1A44 != dword_11E19B4) {
        RB_SetupEntityLighting(dword_11E1A40,
                               (GfxEntityLighting *)dword_11E1A44);
        v0 = dword_11E1A44;
      }
      RB_SetCodeConstant(133, flt_11E44B0[0], flt_11E44B0[1], flt_11E44B0[2],
                         *(float *)(v0 + 4));
      unk_11E1720 = *(_DWORD *)(dword_11E1A44 + 8);
      unk_11E1724 = *(_DWORD *)(dword_11E1A44 + 12);
      unk_11E1728 = *(_DWORD *)(dword_11E1A44 + 16);
      unk_11E172C = *(_DWORD *)(dword_11E1A44 + 20);
      unk_11E1730 = *(_DWORD *)(dword_11E1A44 + 24);
      unk_11E1734 = *(_DWORD *)(dword_11E1A44 + 28);
      unk_11E1738 = *(_DWORD *)(dword_11E1A44 + 32);
      unk_11E173C = *(_DWORD *)(dword_11E1A44 + 36);
      unk_11E1740 = *(_DWORD *)(dword_11E1A44 + 40);
      unk_11E1744 = *(_DWORD *)(dword_11E1A44 + 44);
      unk_11E1748 = *(_DWORD *)(dword_11E1A44 + 48);
      unk_11E174C = *(_DWORD *)(dword_11E1A44 + 52);
      unk_11E1750 = *(_DWORD *)(dword_11E1A44 + 56);
      unk_11E1754 = *(_DWORD *)(dword_11E1A44 + 60);
      unk_11E1758 = *(_DWORD *)(dword_11E1A44 + 64);
      unk_11E175C = *(_DWORD *)(dword_11E1A44 + 68);
      unk_11E1760 = *(_DWORD *)(dword_11E1A44 + 72);
      unk_11E1764 = *(_DWORD *)(dword_11E1A44 + 76);
      unk_11E1768 = *(_DWORD *)(dword_11E1A44 + 80);
      unk_11E176C = *(_DWORD *)(dword_11E1A44 + 84);
      unk_11E1770 = *(_DWORD *)(dword_11E1A44 + 88);
      unk_11E1774 = *(_DWORD *)(dword_11E1A44 + 92);
      unk_11E1778 = *(_DWORD *)(dword_11E1A44 + 96);
      result = *(_DWORD *)(dword_11E1A44 + 100);
      unk_11E177C = result;
    } else {
      dword_11E1650 = LODWORD(flt_11E44B0[0]);
      dword_11E1654 = LODWORD(flt_11E44B0[1]);
      dword_11E1658 = LODWORD(flt_11E44B0[2]);
      dword_11E165C = LODWORD(flt_11E44B0[3]);
      result = (__int32)dword_11E1A40;
      if (dword_11E1A40->reType == 2) {
        unk_11E1790 = *(_DWORD *)(dword_1184B9C + 272);
        unk_11E1794 = *(_DWORD *)(dword_1184B9C + 276);
        unk_11E1798 = *(_DWORD *)(dword_1184B9C + 280);
        unk_11E179C = 0;
        unk_11E1780 = dword_11E1A40->lighting.dx7.colorForDir;
        unk_11E1784 = dword_11E1A40->lighting.dx7.sunVisibility;
        result = LODWORD(dword_11E1A40->lighting.baseCoords[2]);
        unk_11E1788 = result;
        unk_11E178C = 0;
      }
    }
  }
  return result;
}

void __cdecl RB_GetTextureFromCode(int, struct GfxImage **, unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetPassPixelShaderArguments(
    struct MaterialShaderArgument const *, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetupPassDx9(struct MaterialPassDx9 const *,
                             enum MaterialVertexDeclType,
                             struct GfxStateOverride const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetupPass(struct MaterialTechnique const *, int,
                          enum MaterialVertexDeclType,
                          struct GfxStateOverride const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_DrawSingleTechnique(enum MaterialTechniqueType,
                                    enum MaterialVertexDeclType,
                                    struct GfxDrawPrimArgs const *,
                                    struct GfxStateOverride const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_EndSurface_Standard(void) { UNIMPLEMENTED(); }

void __cdecl RB_EndSurface_Optimized(void) { UNIMPLEMENTED(); }

RB_SetVertexData(unsigned int streamIndex, void const *data, int vertexCount,
                 int stride) {
  UNIMPLEMENTED();
}
