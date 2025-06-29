public:
void __cdecl D3DDevice::SetGammaRamp(unsigned int, unsigned long,
                                     struct _D3DGAMMARAMP const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::BeginScene(void)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::ClearF(unsigned long, struct _D3DRECT const *,
                               struct __vector4 const *, float, unsigned long)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SynchronizeToPresentationInterval(void)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::Swap(struct D3DBaseTexture *,
                             struct _D3DVIDEO_SCALER_PARAMETERS const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetClipPlane(unsigned long, float const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::Resolve(unsigned long, struct _D3DRECT const *,
                                struct D3DBaseTexture *,
                                struct _D3DPOINT const *, unsigned int,
                                unsigned int, struct __vector4 const *, float,
                                unsigned long,
                                struct _D3DRESOLVE_PARAMETERS const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::BlockUntilIdle(void)
{
  UNIMPLEMENTED();
}

public:
unsigned long __cdecl D3DDevice::InsertFence(void)
{
  UNIMPLEMENTED();
}

public:
int __cdecl D3DResource::IsBusy(void)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Byte4GetPackedNativeColor(unsigned char, unsigned char,
                                               unsigned char, unsigned char)
{
  UNIMPLEMENTED();
}

void __cdecl RB_EndSurfaceIfNeeded(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetCodeConstantFromVec4(int, float const *const)
{
  UNIMPLEMENTED();
}

float const *__cdecl RB_GetCodeConstant(int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetTessTechnique(struct Material const *,
                                 enum MaterialTechniqueType, int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetVertDeclType(enum MaterialVertexDeclType)
{
  UNIMPLEMENTED();
}

void __cdecl RB_Overflow(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_CheckOverflow(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetFeedbackImage(struct GfxImage *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetIndices(struct D3DIndexBuffer *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_InitBackendGlobalStructs()
{
  memset(backEnd, 0, 0x36E90u);
  dword_11E1A48 = 3;
  dword_11E4484 = 14;
  dword_11E4488 = 14;
  return RB_InitSceneViewport();
}

void __cdecl RB_SetCodeConstant(int constant, float x, float y, float z,
                                float w)
{
  float *v5;  // ecx
  int result; // eax

  v5 = (float *)&backEnd[4 * a1 - 512];
  *v5 = a2;
  v5[1] = a3;
  v5[2] = a4;
  result = LODWORD(a5);
  v5[3] = a5;
  return result;
}

void __cdecl RB_LookupColor(unsigned char c, unsigned char *const color)
{
  int result; // eax

  result = (unsigned __int8)ColorIndex(a1);
    if ((unsigned __int8)result > 7u) {
        if (a1 == 56) {
          result = dword_11E1AC4;
          *(_DWORD *)a2 = dword_11E1AC4;
        }
        else if (a1 == 57) {
          result = dword_11E1AC0;
          *(_DWORD *)a2 = dword_11E1AC0;
        }
        else {
          a2[2] = -1;
          a2[1] = -1;
          *a2 = -1;
          a2[3] = -1;
        }
    }
    else {
      result = RB_LookupColor(
          unsigned char, unsigned char *)::color_table[(unsigned __int8)result];
      *(_DWORD *)a2 = result;
    }
  return result;
}

void __cdecl RB_UpdateColor(float const *const color_allies,
                            float const *const color_axis)
{
  RB_UpdateColorInternal(a1, &dword_11E1AC4);
  return RB_UpdateColorInternal(a2, &dword_11E1AC0);
}

void __cdecl RB_FlushGpu(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetGammaRamp(struct GfxGammaRamp const *gammaTable)
{
  char *v2;      // edx
  __int16 v3;    // ax
  _BYTE v5[512]; // [esp+10h] [ebp-608h] BYREF
  char v6;       // [esp+210h] [ebp-408h] BYREF

  v2 = v5;
    do {
      v3 = *(_WORD *)a1->entries;
      *(_WORD *)v2 = *(_WORD *)a1->entries;
      *((_WORD *)v2 + 256) = v3;
      *((_WORD *)v2 + 512) = v3;
      a1 = (const GfxGammaRamp *)((char *)a1 + 2);
      v2 += 2;
    }
  while (v2 != &v6);
  return (*(int(__cdecl **)(int, int, _DWORD, _BYTE *))(
      *(_DWORD *)dword_117D8A8 + 84))(dword_117D8A8, dword_11805E4, 0, v5);
}

void __cdecl RB_CheckSkinnedCacheNotBusy(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ClearScreen(unsigned char whichToClear,
                            float const *const color, float depth,
                            unsigned char stencil)
{
  int v4;              // edi
  int v5;              // edx
  unsigned __int8 v6;  // al
  int v7;              // edx
  unsigned __int8 v8;  // al
  int v9;              // esi
  int v10;             // edx
  unsigned __int8 v11; // al
  int v12;             // edx
  int v13;             // eax
  int v14;             // ebx
  int result;          // eax
  float v16;           // [esp+24h] [ebp-44h]
  float v17;           // [esp+28h] [ebp-40h]
  float v18;           // [esp+2Ch] [ebp-3Ch]
  float v19;           // [esp+30h] [ebp-38h]
  int v20;             // [esp+38h] [ebp-30h]
  int v21;             // [esp+3Ch] [ebp-2Ch]
  GfxViewport v22;     // [esp+40h] [ebp-28h] BYREF

  v4 = (a1 & 2) != 0 ? 2 : 0;
  if ((a1 & 4) != 0)
    v4 = ((a1 & 2) != 0 ? 2 : 0) | 4;
  if ((a1 & 1) != 0)
    v4 |= 1u;
  v22.x = 0;
  v22.y = 0;
  *(_QWORD *)&v22.width = qword_1186C9C;
  RB_SetViewport(&v22);
  byte_11E1ABC = 1;
  v19 = floorf((float)(*a2 * 255.0) + 0.5);
  v5 = (int)v19;
    if ((int)v19 - 255 >= 0) {
      LOBYTE(v5) = -1;
    LABEL_7:
      v6 = v5;
      goto LABEL_8;
    }
  if (v5 > 0)
    goto LABEL_7;
  v6 = 0;
LABEL_8:
  v20 = v6;
  v18 = floorf((float)(a2[1] * 255.0) + 0.5);
  v7 = (int)v18;
    if ((int)v18 - 255 >= 0) {
      LOBYTE(v7) = -1;
    LABEL_10:
      v8 = v7;
      goto LABEL_11;
    }
  if (v7 > 0)
    goto LABEL_10;
  v8 = 0;
LABEL_11:
  v9 = v8;
  v17 = floorf((float)(a2[2] * 255.0) + 0.5);
  v10 = (int)v17;
    if ((int)v17 - 255 >= 0) {
      LOBYTE(v10) = -1;
    LABEL_13:
      v11 = v10;
      goto LABEL_14;
    }
  if (v10 > 0)
    goto LABEL_13;
  v11 = 0;
LABEL_14:
  v21 = v11;
  v16 = floorf((float)(255.0 * a2[3]) + 0.5);
  v12 = (int)v16;
    if ((int)v16 - 255 < 0) {
        if (v12 <= 0) {
          v13 = 0;
          goto LABEL_17;
        }
    }
    else {
      v12 = 255;
    }
  v13 = v12;
LABEL_17:
  v14 = v21 | (v9 << 8) | (v20 << 16) | (v13 << 24);
    do {
      (*(void(__cdecl **)(int, _DWORD, _DWORD, int, int, _DWORD, _DWORD))(
          *(_DWORD *)dword_117D8A8 + 172))(dword_117D8A8, 0, 0, v4, v14,
                                           LODWORD(a3), a4);
      result = alwaysfails;
    }
  while (alwaysfails);
  return result;
}

void __cdecl RB_RegisterBackendAssets()
{
  int result; // eax

  result = R_RegisterFont("fonts/smalldevfont", 1);
  dword_1218488 = result;
  return result;
}

void __cdecl RB_Resolve(struct GfxImage *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_Set3D()
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawLines3D(int count, int width,
                            struct GfxPointVertex const *const verts,
                            bool depthTest)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawLines2D(int count, int width,
                            struct GfxPointVertex const *const verts)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawStretchPic(struct Material const *material, float x,
                               float y, float w, float h, float s0, float t0,
                               float s1, float t1, unsigned long color,
                               enum GfxPrimStatsTarget statsTarget)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawTextInSpace(char const *text, struct Font_s *font,
                                float const *const org,
                                float const *const xPixelStep,
                                float const *const yPixelStep,
                                unsigned long color)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawFullScreenColoredQuad(struct Material const *material,
                                          float s0, float t0, float s1,
                                          float t1, unsigned long color)
{
  UNIMPLEMENTED();
}

void __cdecl RB_EndFrame()
{
  int v0;         // eax
  int result;     // eax
  const char *v2; // eax

  v0 = (*(int(__cdecl **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(
      *(_DWORD *)dword_117D8A8 + 68))(dword_117D8A8, 0, 0, 0, 0);
    if (v0 < 0) {
        if (v0 != -2005530520) {
          v2 = (const char *)R_ErrorDescription();
          R_Error(ERR_FATAL, "Direct3DDevice9::Present failed: %s\n", v2);
        }
      byte_11805DC = 1;
      R_FlushStaticModelCache();
    }
  *(_DWORD *)dword_118062C = 0;
  byte_11E1ABD = 0;
    if (*(_BYTE *)(r_gamma + 7) ||
        (result = r_ignoreHwGamma, *(_BYTE *)(r_ignoreHwGamma + 7))) {
      unk_1180748(r_gamma);
      unk_1180748(r_ignoreHwGamma);
      result = r_ignoreHwGamma;
      if (!*(_BYTE *)(r_ignoreHwGamma + 8))
        return R_SetColorMappings();
    }
  return result;
}

void __cdecl RB_FullScreenFilter(struct Material const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawText(char const *, struct Font_s *, float, float,
                         union GfxColor)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ExecuteRenderCommands(void const *data)
{
  char v8;                                       // di
  int v9;                                        // eax
  int v10;                                       // eax
  int v11;                                       // eax
  int v12;                                       // eax
  int v13;                                       // eax
  unsigned __int16 v14;                          // ax
  int v15;                                       // eax
  long double v16;                               // fst7
  long double (*v17)(_DWORD, const char *, ...); // ebx
  float v18;                                     // xmm0_4
  long double v19;                               // fst7
  long double (*v20)(_DWORD, const char *, ...); // ebx
  float v21;                                     // xmm0_4
  long double v22;                               // fst7
  long double (*v23)(_DWORD, const char *, ...); // ebx
  float v24;                                     // xmm0_4
  long double v25;                               // fst7
  long double (*v26)(_DWORD, const char *, ...); // ebx
  float v27;                                     // xmm0_4
  long double v28;                               // fst7
  long double (*v29)(_DWORD, const char *, ...); // ebx
  float v30;                                     // xmm0_4
  long double v31;                               // fst7
  long double (*v32)(_DWORD, const char *, ...); // ebx
  float v33;                                     // xmm0_4
  long double v34;                               // fst7
  long double (*v35)(_DWORD, const char *, ...); // ebx
  float v36;                                     // xmm0_4
  long double v37;                               // fst7
  long double (*v38)(_DWORD, const char *, ...); // ebx
  double v39;                                    // xmm0_8
  long double (*v40)(_DWORD, const char *, ...); // ebx
  double v41;                                    // xmm0_8
  long double v42;                               // fst7
  long double (*v43)(_DWORD, const char *, ...); // ebx
  double v44;                                    // xmm0_8
  long double v45;                               // fst7
  long double (*v46)(_DWORD, const char *, ...); // ebx
  double v47;                                    // xmm0_8
  long double v48;                               // fst7
  long double (*v49)(_DWORD, const char *, ...); // ebx
  GLboolean v50;                                 // al
  bool v51;                                      // bl
  unsigned __int64 v52;                          // rax
  unsigned __int64 v53;                          // rax
  int v54;                                       // eax
  GLboolean v55;                                 // al
  bool v56;                                      // bl
  long double (*v57)(_DWORD, const char *, ...); // ebx
  float v58;                                     // xmm0_4
  long double (*v59)(_DWORD, const char *, ...); // ebx
  GLboolean v60;                                 // al
  bool v61;                                      // bl
  GLboolean v62;                                 // al
  bool v63;                                      // bl
  unsigned __int64 v64;                          // rax
  int v65;                                       // [esp+28h] [ebp-30h]
  float v66;                                     // [esp+2Ch] [ebp-2Ch]
  _DWORD v67[10];                                // [esp+30h] [ebp-28h] BYREF

  backEndData = 0;
  if (g_disableRendering)
    return;
    if (!byte_11805DC) {
      v15 = (*(int(__cdecl **)(int))(*(_DWORD *)dword_117D8A8 + 12))(
          dword_117D8A8);
      if (v15 == -2005530520 || v15 == -2005530519)
        byte_11805DC = 1;
    }
  v8 = byte_11805DC;
    if (byte_11805DC) {
      if (!(unsigned __int8)R_RecoverLostDevice(a2, a3, a4, a5, a6, a7))
        return;
      backEndData = (int)a8;
      v9 = r_textureMode;
        if (!*(_BYTE *)(r_textureMode + 7)) {
        LABEL_5:
          v10 = r_anisotropy;
          if (!*(_BYTE *)(r_anisotropy + 7))
            goto LABEL_6;
          goto LABEL_51;
        }
    }
    else {
      backEndData = (int)a8;
      v9 = r_textureMode;
      if (!*(_BYTE *)(r_textureMode + 7))
        goto LABEL_5;
    }
  unk_1180748(v9);
  RB_DecideDefaultSamplerState();
  v10 = r_anisotropy;
    if (!*(_BYTE *)(r_anisotropy + 7)) {
    LABEL_6:
      v11 = r_cosinePowerMapShift;
      if (!*(_BYTE *)(r_cosinePowerMapShift + 7))
        goto LABEL_7;
      goto LABEL_52;
    }
LABEL_51:
  unk_1180748(v10);
  RB_SetAnisotropy();
  v11 = r_cosinePowerMapShift;
    if (!*(_BYTE *)(r_cosinePowerMapShift + 7)) {
    LABEL_7:
      v12 = r_outdoorFeather;
      if (!*(_BYTE *)(r_outdoorFeather + 7))
        goto LABEL_8;
    LABEL_53:
      unk_1180748(v12);
      dword_11E1920 = *(_DWORD *)(r_outdoorFeather + 8);
      dword_11E1924 = dword_11E1920;
      dword_11E1928 = dword_11E1920;
      dword_11E192C = dword_11E1920;
      v13 = r_aaAlpha;
      if (!*(_BYTE *)(r_aaAlpha + 7))
        goto LABEL_9;
    LABEL_54:
      unk_1180748(v13);
      if (byte_118061E)
        RB_SetAlphaAntiAliasingState(dword_1186C08);
      goto LABEL_9;
    }
LABEL_52:
  unk_1180748(v11);
  Image_RebuildCosinePowerMap(*(float *)(r_cosinePowerMapShift + 8));
  v12 = r_outdoorFeather;
  if (*(_BYTE *)(r_outdoorFeather + 7))
    goto LABEL_53;
LABEL_8:
  v13 = r_aaAlpha;
  if (*(_BYTE *)(r_aaAlpha + 7))
    goto LABEL_54;
LABEL_9:
    if (dword_11804C0 == 3) {
        if (byte_1180608) {
          v50 = glTestFenceAPPLE(g_FenceID);
          v51 = v50 != 0;
          if (v50)
            glDeleteFencesAPPLE(1, &g_FenceID);
            if (v51) {
              byte_1180608 = 0;
            }
            else {
              v52 = __rdtsc();
              v65 = v52;
                while (byte_1180608) {
                  v62 = glTestFenceAPPLE(g_FenceID);
                  v63 = v62 != 0;
                  if (v62)
                    glDeleteFencesAPPLE(1, &g_FenceID);
                    if (!v63) {
                      v64 = __rdtsc();
                      if ((int)v64 - v65 <= dword_1180600)
                        continue;
                    }
                  byte_1180608 = 0;
                  break;
                }
              v53 = __rdtsc();
              v54 = 3 * (v53 - v65);
              if (v54 <= -1)
                v54 += 3;
              dword_1180600 += v54 >> 2;
            }
        }
    }
    else if (dword_11804C0 == 1) {
        while (byte_1180608) {
          v60 = glTestFenceAPPLE(g_FenceID);
          v61 = v60 != 0;
          if (v60)
            glDeleteFencesAPPLE(1, &g_FenceID);
            if (v61) {
              byte_1180608 = 0;
              break;
            }
        }
      glGenFencesAPPLE(1, &g_FenceID);
      glSetFenceAPPLE(g_FenceID);
      byte_1180608 = 1;
    }
  byte_11805DD = 1;
  do
    (*(void(__cdecl **)(int))(*(_DWORD *)dword_117D8A8 + 164))(dword_117D8A8);
  while (alwaysfails);
  ++dword_11E19B0;
  if (v8)
    RB_TouchAllImages(a1, a2, a3, a4, a5, a6, a7);
    if (*(_BYTE *)(r_skipBackEnd + 8)) {
      if (byte_11E1ABC)
        RB_UpdateViewport();
      do
        (*(void(__cdecl **)(int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))(
            *(_DWORD *)dword_117D8A8 + 172))(dword_117D8A8, 0, 0, 1, 0, 0, 0);
      while (alwaysfails);
    }
    else {
      v67[0] = &aActiveFxI[backEndData];
      v67[1] = 0;
      v14 = *(_WORD *)&aActiveFxI[backEndData];
        if (v14) {
            do {
              ((void(__cdecl *)(_DWORD *))RB_RenderCommandTable[v14])(v67);
              v14 = *(_WORD *)v67[0];
            }
          while (*(_WORD *)v67[0]);
        }
    }
  if (dword_11E15D0 || dword_11E15E0)
    RB_EndSurface(a1, a2, a3, a4, a5, a6, a7);
  if (dword_11E19C8 && *(_DWORD *)(developer + 8))
    RB_DrawDebug(a1, a2, a3, a4, a5, a6, a7, dword_11E19C8);
  if (dword_1186CCC)
    RB_ChangeIndices(0);
  RB_ClearAllStreamSources();
  do
    (*(void(__cdecl **)(int))(*(_DWORD *)dword_117D8A8 + 168))(dword_117D8A8);
  while (alwaysfails);
  byte_11805DD = 0;
    if (*(int *)(r_testFill + 8) > 0) {
        if (*(_BYTE *)(r_testFillEnable + 8)) {
          v16 = ri(0, "-----------------------------------------------\n");
          v17 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v18 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1047], *(_DWORD *)(r_testFill + 8), v16,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v19 = v17(0, "normal fill                 %4.1f overdraw @ 60Hz\n",
                    (float)(v18 / 60.0));
          v20 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v21 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1048], *(_DWORD *)(r_testFill + 8), v19,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v22 = v20(0, "alpha blend fill            %4.1f overdraw @ 60Hz\n",
                    (float)(v21 / 60.0));
          v23 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v24 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1049], *(_DWORD *)(r_testFill + 8), v22,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v25 = v23(0, "alpha test pass fill        %4.1f overdraw @ 60Hz\n",
                    (float)(v24 / 60.0));
          v26 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v27 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1050], *(_DWORD *)(r_testFill + 8), v25,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v28 = v26(0, "alpha test fail fill        %4.1f overdraw @ 60Hz\n",
                    (float)(v27 / 60.0));
          v29 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v30 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1051], *(_DWORD *)(r_testFill + 8), v28,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v31 = v29(0, "additive fill               %4.1f overdraw @ 60Hz\n",
                    (float)(v30 / 60.0));
          v32 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v33 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1052], *(_DWORD *)(r_testFill + 8), v31,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v34 = v32(0, "depth only fill             %4.1f overdraw @ 60Hz\n",
                    (float)(v33 / 60.0));
          v35 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v36 = RB_BenchmarkRepeatedCalls(
              (const Material *)rgp[1053], *(_DWORD *)(r_testFill + 8), v34,
              (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
          v37 = v35(0, "1-sided stencil keep fill   %4.1f overdraw @ 60Hz\n",
                    (float)(v36 / 60.0));
          v38 = ri;
          a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
          v39 = (float)(RB_BenchmarkRepeatedCalls(
                            (const Material *)rgp[1054],
                            *(_DWORD *)(r_testFill + 8), v37,
                            (float)(int)qword_1186C9C, a3, a4, a5, a6, a7) /
                        60.0);
          v38(0, "1-sided stencil reject fill %4.1f overdraw @ 60Hz\n", v39);
            if (byte_1180618) {
              v57 = ri;
              a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
              v58 = RB_BenchmarkRepeatedCalls(
                  (const Material *)rgp[1055], *(_DWORD *)(r_testFill + 8), v37,
                  (float)(int)qword_1186C9C, a3, a4, a5, a6, a7);
              v37 =
                  v57(0, "2-sided stencil keep fill   %4.1f overdraw @ 60Hz\n",
                      (float)(v58 / 60.0));
              v59 = ri;
              a3.f32[0] = (float)SHIDWORD(qword_1186C9C);
              v39 = (float)(RB_BenchmarkRepeatedCalls(
                                (const Material *)rgp[1056],
                                *(_DWORD *)(r_testFill + 8), v37,
                                (float)(int)qword_1186C9C, a3, a4, a5, a6, a7) /
                            60.0);
              v59(0, "2-sided stencil reject fill %4.1f overdraw @ 60Hz\n",
                  v39);
            }
          v40 = ri;
          v41 = RB_TestFillPass3D((const Material *)rgp[1057],
                                  TECHNIQUE_POINTLIGHT, v37, *(float *)&v39, a3,
                                  a4, a5, a6, a7);
          v42 = v40(0, "phong point bump fill       %4.1f overdraw @ 60Hz\n",
                    v41);
          v43 = ri;
          v44 = RB_TestFillPass3D((const Material *)rgp[1058],
                                  TECHNIQUE_POINTLIGHT, v42, *(float *)&v41, a3,
                                  a4, a5, a6, a7);
          v45 = v43(0, "phong point bump+spec fill  %4.1f overdraw @ 60Hz\n",
                    v44);
          v46 = ri;
          v47 = RB_TestFillPass3D((const Material *)rgp[1057],
                                  TECHNIQUE_LIGHTPROBE_NOT_CACHED_FIRST, v45,
                                  *(float *)&v44, a3, a4, a5, a6, a7);
          v48 = v46(0, "phong dir bump fill         %4.1f overdraw @ 60Hz\n",
                    v47);
          v49 = ri;
          *(float *)&v47 =
              RB_TestFillPass3D((const Material *)rgp[1058],
                                TECHNIQUE_LIGHTPROBE_NOT_CACHED_FIRST, v48,
                                *(float *)&v47, a3, a4, a5, a6, a7);
          v49(0, "phong dir bump+spec fill    %4.1f overdraw @ 60Hz\n",
              *(float *)&v47);
          a1 = ri(0, "-----------------------------------------------\n");
        }
        else {
          ri(0,
             "Fill testing uses extra textures and materials, so it is usually "
             "unavailable.\n");
          a1 = ri(
              0, "You must set 'r_testFillEnable' to 1 and vid_restart to test "
                 "fill rates.\n");
        }
      dword_1180758(r_testFill, 0);
    }
    if (*(int *)(r_testTransform + 8) > 0) {
      v66 = RB_BenchmarkRepeatedCalls((const Material *)rgp[1038], 1362, a1,
                                      0.0, (__m128)0LL, a4, a5, a6, a7) /
            60.0;
      ri(0, "-----------------------------------------------\n");
      ri(0, "static vertex data    %8.0f verts/sec @ 60Hz\n", 0.0);
      ri(0, "static vertex data    %8.0f tris/sec @ 60Hz\n", 0.0);
      ri(0, "skinned vertex data   %8.0f verts/sec @ 60Hz\n", 0.0);
      ri(0, "skinned vertex data   %8.0f tris/sec @ 60Hz\n", 0.0);
      ri(0, "dynamic vertex data   %8.0f verts/sec @ 60Hz\n",
         (float)(v66 * 4.0));
      ri(0, "dynamic vertex data   %8.0f tris/sec @ 60Hz\n",
         (float)(v66 + v66));
      ri(0, "-----------------------------------------------\n");
      dword_1180758(r_testTransform, 0);
    }
    if (dword_11804C0 == 3) {
      glGenFencesAPPLE(1, &g_FenceID);
      glSetFenceAPPLE(g_FenceID);
      byte_1180608 = 1;
    }
    else if (dword_11804C0 == 2) {
        while (byte_1180608) {
          v55 = glTestFenceAPPLE(g_FenceID);
          v56 = v55 != 0;
          if (v55)
            glDeleteFencesAPPLE(1, &g_FenceID);
            if (v56) {
              byte_1180608 = 0;
              break;
            }
        }
      glGenFencesAPPLE(1, &g_FenceID);
      glSetFenceAPPLE(g_FenceID);
      byte_1180608 = 1;
    }
}

void __cdecl RB_RenderThread(void)
{
  UNIMPLEMENTED();
}

struct GfxBackEndData const *const backEndData;
int marker_rb_backend;
struct materialCommands_t tess;
struct r_backEndGlobals_t backEnd;

void __cdecl R_SetSkinnedCacheEvent(void)
{
  UNIMPLEMENTED();
}

float __cdecl RB_TestTransformSkinned(struct Material const *)
{
  UNIMPLEMENTED();
}

float __cdecl RB_TestTransformStatic(struct Material const *)
{
  UNIMPLEMENTED();
}

double __cdecl RB_BenchmarkTime(union _LARGE_INTEGER const *,
                                union _LARGE_INTEGER const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetTechniqueDepthTest(struct Material *, int)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_UsingGlow(void)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_UsingBlur(float)
{
  UNIMPLEMENTED();
}

int __cdecl RB_GetGlowRadiusOrder(float *const)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_DoesTechniqueExistForMaterial(struct Material const *,
                                              enum MaterialTechniqueType)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_IsMaterialSuppressed(struct Material const *)
{
  UNIMPLEMENTED();
}

enum MaterialTechniqueType __cdecl RB_ChooseActualTechniqueType(
    enum MaterialTechniqueType, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_StretchRaw(int, int, int, int, int, int, unsigned char const *,
                           int, int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ReturnCmd(struct GfxRenderCommandExecState *)
{
  GfxRenderCommandExecState *result; // eax
  uint32_t v2;                       // edx

  result = a1;
  v2 = a1->stackPos - 1;
  a1->stackPos = v2;
  *(_DWORD *)a1->cmd = *(_DWORD *)&a1->retCmd[4 * v2];
  return result;
}

void __cdecl RB_GotoCmd(struct GfxRenderCommandExecState *)
{
  GfxRenderCommandExecState *result; // eax

  result = a1;
  *(_DWORD *)a1->cmd = *(_DWORD *)(*(_DWORD *)a1->cmd + 4);
  return result;
}

void __cdecl RB_SetViewProjectionMatrix(void)
{
  UNIMPLEMENTED();
}

void const *__cdecl RB_NextRenderCmd(void const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetOutdoorFeatherConst(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DeriveNearPlaneConstantsForView(void)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_UsingPostEffects(float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_CallCmd(struct GfxRenderCommandExecState *)
{
  int v1;            // ebx
  uint32_t stackPos; // edx
  int result;        // eax

  v1 = *(_DWORD *)a1->cmd;
  stackPos = a1->stackPos;
  *(_DWORD *)&a1->retCmd[4 * stackPos] =
      *(_DWORD *)a1->cmd + *(unsigned __int16 *)(*(_DWORD *)a1->cmd + 2);
  a1->stackPos = stackPos + 1;
  result = *(_DWORD *)(v1 + 4);
  *(_DWORD *)a1->cmd = result;
  return result;
}

void __cdecl RB_SetTessVertex4dWithNormal(int, float, float, float, float,
                                          float, float, float, float, float,
                                          unsigned char const *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetTessVertex4d(int, float, float, float, float, float, float,
                                unsigned char const *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetTessVertex3d(int, float, float, float, float, float,
                                unsigned char const *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetTessVertex2d(int, float, float, float, float, unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl RB_AdvanceToNextRenderCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

float __cdecl RB_GetBlurRadius(float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_StretchRawCmd(struct GfxRenderCommandExecState *)
{
  int v1;        // edi
  char *v2;      // ebx
  int result;    // eax
  size_t v4;     // edi
  int i;         // esi
  char *__src;   // [esp+34h] [ebp-54h]
  int v7;        // [esp+38h] [ebp-50h]
  int v8;        // [esp+3Ch] [ebp-4Ch]
  int v9;        // [esp+40h] [ebp-48h]
  int v10;       // [esp+44h] [ebp-44h]
  int v11;       // [esp+48h] [ebp-40h]
  int v12;       // [esp+4Ch] [ebp-3Ch]
  _DWORD v13[4]; // [esp+50h] [ebp-38h] BYREF
  _DWORD v14[2]; // [esp+60h] [ebp-28h] BYREF
  int v15;       // [esp+68h] [ebp-20h] BYREF
  _DWORD v16[7]; // [esp+6Ch] [ebp-1Ch] BYREF

  __src = *(char **)(*(_DWORD *)a1->cmd + 28);
  v7 = *(_DWORD *)(*(_DWORD *)a1->cmd + 24);
  v1 = *(_DWORD *)(*(_DWORD *)a1->cmd + 20);
  v8 = *(_DWORD *)(*(_DWORD *)a1->cmd + 16);
  v9 = *(_DWORD *)(*(_DWORD *)a1->cmd + 12);
  v10 = *(_DWORD *)(*(_DWORD *)a1->cmd + 8);
  v11 = *(_DWORD *)(*(_DWORD *)a1->cmd + 4);
    if ((*(int(__cdecl **)(int, int, int, int, _DWORD, int, _DWORD, _DWORD *,
                           _DWORD))(*(_DWORD *)dword_117D8A8 + 92))(
            dword_117D8A8, v1, v7, 1, 0, 22, 0, v16, 0) >= 0) {
      do
        (*(void(__cdecl **)(_DWORD, _DWORD, _DWORD *, _DWORD, int))(
            *(_DWORD *)v16[0] + 76))(v16[0], 0, v14, 0, 0x2000);
      while (alwaysfails);
      v2 = (char *)v14[1];
      v12 = v14[0];
        if (v7 > 0) {
          v4 = 4 * v1;
            for (i = 0; i != v7; ++i) {
              memcpy(v2, __src, v4);
              __src += v4;
              v2 += v12;
            }
        }
      (*(void(__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)v16[0] + 80))(v16[0], 0);
      v13[0] = v11;
      v13[1] = v10;
      v13[2] = v11 + v9;
      v13[3] = v10 + v8;
      (*(void(__cdecl **)(_DWORD, _DWORD, int *))(*(_DWORD *)v16[0] + 72))(
          v16[0], 0, &v15);
      (*(void(__cdecl **)(int, int, _DWORD, _DWORD, _DWORD *, int))(
          *(_DWORD *)dword_117D8A8 + 136))(dword_117D8A8, v15, 0, unk_11804D4,
                                           v13, 2);
      (*(void(__cdecl **)(int))(*(_DWORD *)v15 + 8))(v15);
      (*(void(__cdecl **)(_DWORD))(*(_DWORD *)v16[0] + 8))(v16[0]);
    }
  result = *(_DWORD *)a1->cmd + *(unsigned __int16 *)(*(_DWORD *)a1->cmd + 2);
  *(_DWORD *)a1->cmd = result;
  return result;
}

void __cdecl RB_UpdateColorInternal(float const *const, unsigned char *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetGameTime(float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetClipPlanesCmd(struct GfxRenderCommandExecState *)
{
  int v1;     // edx
  int v2;     // esi
  int v3;     // ebx
  int v4;     // esi
  int v5;     // ebx
  int result; // eax
  int v7;     // [esp+2Ch] [ebp-1Ch]

  v7 = *(_DWORD *)a1->cmd;
  v1 = *(_DWORD *)(*(_DWORD *)a1->cmd + 4);
    if (v1 == unk_1186D54) {
      v2 = *(_DWORD *)a1->cmd;
    }
    else {
        while (1) {
          (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 + 228))(
              dword_117D8A8, 152, (1 << v1) - 1);
          if (!alwaysfails)
            break;
          v1 = *(_DWORD *)(v7 + 4);
        }
      unk_1186D54 = *(_DWORD *)(v7 + 4);
      v2 = v7;
    }
    if (*(int *)(v2 + 4) > 0) {
      v3 = v2;
      v4 = 0;
      v5 = v3 + 8;
        do {
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                220))(dword_117D8A8, v4, v5);
          while (alwaysfails);
          ++v4;
          v5 += 16;
        }
      while (v4 < *(_DWORD *)(v7 + 4));
    }
  result = *(_DWORD *)a1->cmd + *(unsigned __int16 *)(*(_DWORD *)a1->cmd + 2);
  *(_DWORD *)a1->cmd = result;
  return result;
}

void __cdecl RB_FinishGpu(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_EndBenchmarkGpu(union _LARGE_INTEGER *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BeginBenchmarkGpu(union _LARGE_INTEGER *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BeginFrame(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ResolveTile(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_PreTessGroupCompletedCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ClearScreenCmd(struct GfxRenderCommandExecState *)
{
  int result; // eax

  RB_ClearScreen(*(_BYTE *)(*(_DWORD *)a1->cmd + 4),
                 (const float *)(*(_DWORD *)a1->cmd + 12),
                 *(float *)(*(_DWORD *)a1->cmd + 8),
                 *(_BYTE *)(*(_DWORD *)a1->cmd + 5));
  result = *(_DWORD *)a1->cmd + *(unsigned __int16 *)(*(_DWORD *)a1->cmd + 2);
  *(_DWORD *)a1->cmd = result;
  return result;
}

void __cdecl RB_ResolveAndClear(struct GfxImage *, unsigned char,
                                enum _D3DFORMAT, float const *const, float,
                                unsigned char)
{
  UNIMPLEMENTED();
}

void __cdecl RB_UpdateBackEndDvarOptions(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_RestoreViewAfterTiling(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetViewportCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ResolveRenderTargetCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetRenderTargetCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetLightPropertiesCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetMaterialColorCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SaveScreenCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ApplyEarlyPostEffectsCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetStencilRefValueCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetShadowCookieCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_Set2D(void)
{
  UNIMPLEMENTED();
}

float __cdecl RB_TestFillPass3D(struct Material const *,
                                enum MaterialTechniqueType)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BeginViewCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_RenderDrawSurfList(struct GfxDrawSurf *, int,
                                   enum MaterialTechniqueType,
                                   enum GfxDrawSurfOrder)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawCharInSpace(struct Material const *, float const *const,
                                float const *const, float const *const,
                                struct Glyph const *, unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawTriangles_Internal(struct Material const *,
                                       enum MaterialTechniqueType, short,
                                       unsigned short const *const, short,
                                       float const (*const)[4],
                                       float const (*const)[3],
                                       union GfxColor const *const,
                                       float const (*const)[2])
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawPoints3D(struct GfxCmdDrawPoints const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawPoints2D(struct GfxCmdDrawPoints const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_StencilPlanesCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawSunCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawSurfsCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawQuadPicCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_StretchPicRotateCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

float __cdecl RB_BenchmarkRepeatedCalls(struct Material const *, float, float,
                                        int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawChar(struct Material const *, float, float, float, float,
                         struct Glyph const *, unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawTrianglesCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawLinesCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawPointsCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BlurShadowPass(float, float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ShowShadowsDebug(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ShowFloatZDebug(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ShowFbColorDebug_Screen(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ShowFbColorDebug_Feedback(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_StretchPicCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

float __cdecl RB_TestTransformDynamic(struct Material const *)
{
  UNIMPLEMENTED();
}

float __cdecl RB_TestFillPass(struct Material const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawTextInSpaceCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawCursor(struct Material const *, unsigned char, float, float,
                           struct Font_s *, float, float, unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BlurShadowCookieCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawDebugPostEffects(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawFullScreenColoredQuadCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_FullScreenColoredFilter(struct Material const *, unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawFullScreenQuad(struct Material const *, float, float, float,
                                   float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_TestTransform(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_TestFill(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawTextWithCursor(char const *, int, struct Font_s *, float,
                                   float, float, float, union GfxColor, int,
                                   int, char)
{
  UNIMPLEMENTED();
}

void __cdecl RB_AdjustViewForTile(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BlendSavedScreenCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawSunPostEffectsCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BlurScreen(float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_CalcGlowEffect(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawTextCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ResumeUntiledRenderingCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_EndTilingCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_BeginTilingCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ApplyGlowEffectPass(int, struct GfxImage *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DrawSpriteCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ApplyGlowEffect(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ProcessPostEffects(float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_RenderCommandFrame(void const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ApplyLatePostEffectsCmd(struct GfxRenderCommandExecState *)
{
  UNIMPLEMENTED();
}

RB_IsGpuFenceFinished()
{
  UNIMPLEMENTED();
}

RB_GpuWaited(int ticks)
{
  UNIMPLEMENTED();
}

RB_AdaptiveGpuSyncWait()
{
  UNIMPLEMENTED();
}

RB_AdaptiveGpuSyncTarget()
{
  UNIMPLEMENTED();
}
