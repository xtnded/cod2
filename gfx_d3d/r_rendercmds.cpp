public:
long __cdecl D3DDevice::AcquireThreadOwnership(void)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::ReleaseThreadOwnership(void)
{
  UNIMPLEMENTED();
}

public:
int __cdecl D3DDevice::IsFencePending(unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl Vec4Clear(float *const)
{
  UNIMPLEMENTED();
}

bool __cdecl R_HaveFloatZ(void)
{
  UNIMPLEMENTED();
}

bool __cdecl R_NeedFloatZ(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_BeginDebugFrame()
{
  UNIMPLEMENTED();
}

struct GfxViewParms *__cdecl R_AllocViewParms()
{
  void *v0; // ecx
  int v1;   // edx

  v0 = frontEndDataOut;
  v1 = *((_DWORD *)frontEndDataOut + 548639);
  *((_DWORD *)frontEndDataOut + 548639) = v1 + 1;
  return (int)v0 + 332 * v1 + 2194560;
}

void __cdecl R_ToggleSmpFrame(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddFrontendCmd(int type, void *data)
{
  return R_ProcessFrontendCmdInternal(a1, a2, a3);
}

void __cdecl R_EndRemoteScreenUpdate(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawTriangles(struct Material *,
                                   enum MaterialTechniqueType, short,
                                   unsigned short const *const, short,
                                   float const (*const)[4],
                                   float const (*const)[3],
                                   unsigned char const (*const)[4],
                                   float const (*const)[2])
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdBlendSavedScreen(int fadeMsec)
{
  int v1;     // ecx
  int v2;     // ebx
  int result; // eax
  int v4;     // edx

    if (a1 > 0) {
      v1 = s_cmdList;
      v2 = *(_DWORD *)(s_cmdList + 196608);
      result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v2 - 0x2000;
        if (result <= 11) {
          *(_DWORD *)(s_cmdList + 196616) = 0;
        }
        else {
          v4 = s_cmdList + v2;
          result = v2 + 12;
          *(_DWORD *)(s_cmdList + 196608) = v2 + 12;
          *(_DWORD *)(v1 + 196616) = v1 + v2;
          *(_WORD *)v4 = 29;
          *(_WORD *)(v4 + 2) = 12;
          if (v1 + v2)
            *(_DWORD *)(v4 + 4) = a1;
        }
    }
  return result;
}

void __cdecl R_AddCmdSaveScreen()
{
  int v0;     // ecx
  int v1;     // ebx
  int result; // eax
  _WORD *v3;  // edx

  v0 = s_cmdList;
  v1 = *(_DWORD *)(s_cmdList + 196608);
  result = 196608 - v1;
    if (196608 - v1 > 3) {
      v3 = (_WORD *)(s_cmdList + v1);
      result = v1 + 4;
      *(_DWORD *)(s_cmdList + 196608) = v1 + 4;
      *(_DWORD *)(v0 + 196612) += 4;
      *(_DWORD *)(v0 + 196616) = v0 + v1;
      *v3 = 10;
      v3[1] = 4;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdClearScreen(int whichToClear, float const *const color,
                                 float depth, unsigned char stencil)
{
  int v4;     // ecx
  int v5;     // ebx
  int v6;     // ecx
  int result; // eax
  _WORD *v8;  // edx

  v4 = s_cmdList;
  v5 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v5 > 27) {
      v8 = (_WORD *)(s_cmdList + v5);
      *(_DWORD *)(s_cmdList + 196608) = v5 + 28;
      *(_DWORD *)(v4 + 196612) += 28;
      *(_DWORD *)(v4 + 196616) = v4 + v5;
      *v8 = 11;
      v8[1] = 28;
      v6 = v4 + v5;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      v6 = 0;
    }
  *(_BYTE *)(v6 + 4) = a1;
  *(_BYTE *)(v6 + 5) = a4;
  *(float *)(v6 + 8) = a3;
  *(float *)(v6 + 12) = *a2;
  *(float *)(v6 + 16) = a2[1];
  *(float *)(v6 + 20) = a2[2];
  result = *((_DWORD *)a2 + 3);
  *(_DWORD *)(v6 + 24) = result;
  return result;
}

void __cdecl R_AddCmdBlurShadowCookie(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawSunPostEffects(int viewIndex)
{
  int v1;     // ecx
  int v2;     // ebx
  int result; // eax
  _WORD *v4;  // edx

  v1 = s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v2 - 0x2000;
    if (result > 7) {
      v4 = (_WORD *)(s_cmdList + v2);
      *(_DWORD *)(s_cmdList + 196608) = v2 + 8;
      *(_DWORD *)(v1 + 196616) = v1 + v2;
      *v4 = 27;
      v4[1] = 8;
      result = v1 + v2;
      if (v1 + v2)
        *(_DWORD *)(result + 4) = a1;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdApplyLatePostEffects(float blurRadius)
{
  int v1;     // ecx
  int v2;     // ebx
  int result; // eax
  int v4;     // edx

  v1 = s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v2 - 0x2000;
    if (result > 7) {
      v4 = s_cmdList + v2;
      result = v2 + 8;
      *(_DWORD *)(s_cmdList + 196608) = v2 + 8;
      *(_DWORD *)(v1 + 196616) = v1 + v2;
      *(_WORD *)v4 = 26;
      *(_WORD *)(v4 + 2) = 8;
      if (v1 + v2)
        *(float *)(v4 + 4) = a1;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdApplyEarlyPostEffects()
{
  int v0;     // ecx
  int v1;     // ebx
  int result; // eax
  _WORD *v3;  // edx

  v0 = s_cmdList;
  v1 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v1 - 0x2000;
    if (result > 3) {
      v3 = (_WORD *)(s_cmdList + v1);
      result = v1 + 4;
      *(_DWORD *)(s_cmdList + 196608) = v1 + 4;
      *(_DWORD *)(v0 + 196616) = v0 + v1;
      *v3 = 25;
      v3[1] = 4;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdSetViewport(int x, int y, int width, int height)
{
  int v4;     // ecx
  int v5;     // ebx
  int result; // eax
  int v7;     // edx

  v4 = s_cmdList;
  v5 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v5 > 19) {
      v7 = s_cmdList + v5;
      *(_DWORD *)(s_cmdList + 196608) = v5 + 20;
      *(_DWORD *)(v4 + 196612) += 20;
      *(_DWORD *)(v4 + 196616) = v4 + v5;
      *(_WORD *)v7 = 13;
      *(_WORD *)(v7 + 2) = 20;
      *(_DWORD *)(v7 + 4) = a1;
      *(_DWORD *)(v7 + 8) = a2;
      *(_DWORD *)(v7 + 12) = a3;
      result = a4;
      *(_DWORD *)(v7 + 16) = a4;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      MEMORY[4] = a1;
      MEMORY[8] = a2;
      MEMORY[0xC] = a3;
      result = a4;
      MEMORY[0x10] = a4;
    }
  return result;
}

void __cdecl R_AddCmdBeginView(int viewCount,
                               struct GfxSceneDef const *sceneDef,
                               struct GfxViewParms const *viewParms,
                               struct GfxLodParms const *lodParms)
{
  int v4;         // ecx
  int v5;         // ebx
  int v6;         // edx
  int32_t result; // eax

  v4 = s_cmdList;
  v5 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v5 > 47) {
      v6 = s_cmdList + v5;
      *(_DWORD *)(s_cmdList + 196608) = v5 + 48;
      *(_DWORD *)(v4 + 196612) += 48;
      *(_DWORD *)(v4 + 196616) = v4 + v5;
      *(_WORD *)v6 = 12;
      *(_WORD *)(v6 + 2) = 48;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      v6 = 0;
    }
  *(_DWORD *)(v6 + 44) = a1;
  *(GfxSceneDef *)(v6 + 4) = *a2;
  *(_DWORD *)(v6 + 20) = a3;
  *(float *)(v6 + 24) = a4->origin[0];
  *(float *)(v6 + 28) = a4->origin[1];
  *(float *)(v6 + 32) = a4->origin[2];
  *(_DWORD *)(v6 + 36) = a4->scale;
  result = a4->bias;
  *(_DWORD *)(v6 + 40) = result;
  return result;
}

void __cdecl R_AddCmdShadowCookie(struct _D3DMATRIX const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdClipPlanes(int, float const (*const)[4])
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdSetStencilPlanes(float, int, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdSetStencilRefValue(int)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawSun(int viewIndex)
{
  int v1;     // ecx
  int v2;     // ebx
  int result; // eax
  int v4;     // edx

  v1 = s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
    if (*(_DWORD *)(s_cmdList + 196612) + 196608 - v2 - 0x2000 > 7) {
      v4 = s_cmdList + v2;
      *(_DWORD *)(s_cmdList + 196608) = v2 + 8;
      *(_DWORD *)(v1 + 196616) = v1 + v2;
      *(_WORD *)v4 = 24;
      *(_WORD *)(v4 + 2) = 8;
      result = a1;
      *(_DWORD *)(v4 + 4) = a1;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      result = a1;
      MEMORY[4] = a1;
    }
  return result;
}

void __cdecl R_AddCmdResolveRenderTarget(int, enum _D3DFORMAT,
                                         float const *const, float,
                                         unsigned char)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdSetRenderTarget(enum GfxRenderTargetId renderTargetId)
{
  int v1;                   // ecx
  int v2;                   // ebx
  GfxRenderTargetId result; // eax
  int v4;                   // edx

  v1 = s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v2 > 7) {
      v4 = s_cmdList + v2;
      *(_DWORD *)(s_cmdList + 196608) = v2 + 8;
      *(_DWORD *)(v1 + 196612) += 8;
      *(_DWORD *)(v1 + 196616) = v1 + v2;
      *(_WORD *)v4 = 14;
      *(_WORD *)(v4 + 2) = 8;
      result = a1;
      *(_DWORD *)(v4 + 4) = a1;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      result = a1;
      MEMORY[4] = a1;
    }
  return result;
}

void __cdecl R_AddCmdResumeUntiledRendering(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdEndTiling(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdBeginTiling(enum GfxTileOrder, enum GfxRenderTargetId,
                                 enum GfxRenderTargetId)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdPreTessGroupCompleted(int)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdLightProperties(int lightIndex,
                                     struct GfxLight const *light)
{
  int v2;         // ebx
  int v3;         // esi
  int v4;         // edx
  float v5;       // ebx
  float v6;       // edx
  float v7;       // edi
  float v8;       // ebx
  float v9;       // xmm1_4
  int32_t result; // eax
  int v11;        // [esp+4h] [ebp-10h]

  v2 = s_cmdList;
  v3 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v3 > 75) {
      v4 = s_cmdList + v3;
      *(_DWORD *)(s_cmdList + 196608) = v3 + 76;
      *(_DWORD *)(v2 + 196612) += 76;
      *(_DWORD *)(v2 + 196616) = v2 + v3;
      *(_WORD *)v4 = 5;
      *(_WORD *)(v4 + 2) = 76;
      v11 = v2 + v3;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      v11 = 0;
      v4 = 0;
    }
  *(_DWORD *)(v4 + 4) = a1;
  *(float *)(v11 + 8) = a2->position[0];
  *(float *)(v4 + 12) = a2->position[1];
  *(float *)(v4 + 16) = a2->position[2];
  *(float *)(v4 + 20) = a2->position[3];
  v5 = a2->color[2];
  v6 = a2->color[1];
  *(float *)(v11 + 40) = a2->color[0];
  *(float *)(v11 + 44) = v6;
  *(float *)(v11 + 48) = v5;
  *(_DWORD *)(v11 + 52) = 1065353216;
  v7 = a2->u.dir.ambientColor[2];
  v8 = a2->u.dir.ambientColor[1];
  *(float *)(v11 + 24) = a2->u.dir.ambientColor[0];
  *(float *)(v11 + 28) = v8;
  *(float *)(v11 + 32) = v7;
  *(_DWORD *)(v11 + 36) = 1065353216;
  v9 = *(float *)(r_specularColorScale + 8);
  *(float *)(v11 + 56) = v9 * *(float *)(v11 + 40);
  *(float *)(v11 + 60) = v9 * *(float *)(v11 + 44);
  *(float *)(v11 + 64) = v9 * *(float *)(v11 + 48);
  *(float *)(v11 + 68) = v9 * *(float *)(v11 + 52);
  result = a2->def;
  *(_DWORD *)(v11 + 72) = a2->def;
  return result;
}

void __cdecl R_AddCmdSetMaterialColor(float const *const color)
{
  int v1;     // ecx
  int v2;     // ebx
  int v3;     // ecx
  int result; // eax
  _WORD *v5;  // edx

  v1 = s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v2 > 19) {
      v5 = (_WORD *)(s_cmdList + v2);
      *(_DWORD *)(s_cmdList + 196608) = v2 + 20;
      *(_DWORD *)(v1 + 196612) += 20;
      *(_DWORD *)(v1 + 196616) = v1 + v2;
      *v5 = 4;
      v5[1] = 20;
      v3 = v1 + v2;
      if (a1)
        goto LABEL_3;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      v3 = 0;
        if (a1) {
        LABEL_3:
          *(float *)(v3 + 4) = *a1;
          *(float *)(v3 + 8) = a1[1];
          *(float *)(v3 + 12) = a1[2];
          result = *((_DWORD *)a1 + 3);
          *(_DWORD *)(v3 + 16) = result;
          return result;
        }
    }
  result = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 16) = 0;
  return result;
}

void __cdecl R_AddCmdDrawFullScreenColoredQuad(float s0, float t0, float s1,
                                               float t1,
                                               float const *const color,
                                               struct Material *material)
{
  int v6;     // ecx
  int v7;     // ebx
  int result; // eax
  int v9;     // edx

  v6 = s_cmdList;
  v7 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v7 - 0x2000;
    if (result > 27) {
      v9 = s_cmdList + v7;
      *(_DWORD *)(s_cmdList + 196608) = v7 + 28;
      *(_DWORD *)(v6 + 196616) = v6 + v7;
      *(_WORD *)v9 = 20;
      *(_WORD *)(v9 + 2) = 28;
      result = v6 + v7;
        if (v6 + v7) {
          *(_DWORD *)(v9 + 4) = a6;
          *(float *)(v9 + 8) = a1;
          *(float *)(v9 + 12) = a2;
          *(float *)(v9 + 16) = a3;
          *(float *)(v9 + 20) = a4;
          return R_ConvertColorToBytes(a5, (unsigned __int8 *)(result + 24));
        }
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdDrawSprite(struct Material *const material,
                                unsigned char const *const rgbaColor,
                                float const *const pos, float radius,
                                float minScreenRadius, int renderFxFlags)
{
  int v6;     // ecx
  int v7;     // ebx
  int result; // eax
  int v9;     // edx
  int v10;    // ecx

  v6 = s_cmdList;
  v7 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v7 - 0x2000;
    if (result > 35) {
      v9 = s_cmdList + v7;
      result = v7 + 36;
      *(_DWORD *)(s_cmdList + 196608) = v7 + 36;
      *(_DWORD *)(v6 + 196616) = v6 + v7;
      *(_WORD *)v9 = 19;
      *(_WORD *)(v9 + 2) = 36;
      v10 = v6 + v7;
        if (v9) {
          *(_DWORD *)(v9 + 4) = a1;
          *(_DWORD *)(v10 + 8) = *(_DWORD *)a2;
          *(float *)(v10 + 12) = *a3;
          *(float *)(v10 + 16) = a3[1];
          *(float *)(v10 + 20) = a3[2];
          *(float *)(v10 + 24) = a4;
          *(float *)(v10 + 28) = a5;
          result = a6;
          *(_DWORD *)(v10 + 32) = a6;
        }
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdDrawQuadPic(float const (*)[2], float const *const,
                                 struct Material *)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawTextInSpace(char const *text, struct Font_s *font,
                                     float const *const org,
                                     float const *const xPixelStep,
                                     float const *const yPixelStep,
                                     float const *const color)
{
  unsigned int v6; // ecx
  signed int v7;   // ebx
  int v8;          // edi
  int v9;          // ecx
  void *result;    // eax
  _WORD *v11;      // edx
  int v12;         // ebx
  float *v13;      // edx
  size_t __n;      // [esp+1Ch] [ebp-1Ch]

    if (*__src) {
      v6 = strlen(__src) + 1;
      __n = v6 - 1;
      v7 = (v6 + 51) & 0xFFFFFFFC;
      v8 = s_cmdList;
      v9 = *(_DWORD *)(s_cmdList + 196608);
      result = (void *)(*(_DWORD *)(s_cmdList + 196612) + 196608 - v9 - 0x2000);
        if (v7 <= (int)result) {
          v11 = (_WORD *)(s_cmdList + v9);
          result = (void *)(v7 + v9);
          *(_DWORD *)(s_cmdList + 196608) = v7 + v9;
          *(_DWORD *)(v8 + 196616) = v8 + v9;
          *v11 = 22;
          v11[1] = v7;
          v12 = v8 + v9;
            if (v8 + v9) {
              v13 = (float *)(v11 + 2);
              *(float *)(v12 + 4) = *a3;
              v13[1] = a3[1];
              v13[2] = a3[2];
              *(_DWORD *)(v12 + 16) = a2;
              *(float *)(v12 + 20) = *a4;
              *(float *)(v12 + 24) = a4[1];
              *(float *)(v12 + 28) = a4[2];
              *(float *)(v12 + 32) = *a5;
              *(float *)(v12 + 36) = a5[1];
              *(float *)(v12 + 40) = a5[2];
              R_ConvertColorToBytes(a6, (unsigned __int8 *)(v12 + 44));
              result = memcpy((void *)(v12 + 48), __src, __n);
              *(_BYTE *)(__n + v12 + 48) = 0;
            }
        }
        else {
          *(_DWORD *)(s_cmdList + 196616) = 0;
        }
    }
  return result;
}

void __cdecl R_AddCmdDrawTextWithCursor(char const *text, int maxChars,
                                        struct Font_s *font, float x, float y,
                                        float xScale, float yScale,
                                        float const *const color, int style,
                                        int cursorPos, char cursor)
{
  int result;       // eax
  unsigned int v12; // ecx
  signed int v13;   // ebx
  int v14;          // edi
  int v15;          // ecx
  int v16;          // edx
  int v17;          // edi
  size_t __n;       // [esp+1Ch] [ebp-1Ch]

  result = a11;
    if (*__src || a10 >= 0) {
      v12 = strlen(__src) + 1;
      __n = v12 - 1;
      v13 = (v12 + 48) & 0xFFFFFFFC;
      v14 = s_cmdList;
      v15 = *(_DWORD *)(s_cmdList + 196608);
      result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v15 - 0x2000;
        if (v13 > result) {
          *(_DWORD *)(s_cmdList + 196616) = 0;
        }
        else {
          v16 = s_cmdList + v15;
          result = v13 + v15;
          *(_DWORD *)(s_cmdList + 196608) = v13 + v15;
          *(_DWORD *)(v14 + 196616) = v14 + v15;
          *(_WORD *)v16 = 21;
          *(_WORD *)(v16 + 2) = v13;
          v17 = v14 + v15;
            if (v16) {
              *(float *)(v16 + 4) = a4;
              *(float *)(v16 + 8) = a5;
              *(_DWORD *)(v16 + 12) = a3;
              *(float *)(v16 + 16) = a6;
              *(float *)(v16 + 20) = a7;
              R_ConvertColorToBytes(a8, (unsigned __int8 *)(v16 + 24));
              *(_DWORD *)(v17 + 28) = a9;
              *(_DWORD *)(v17 + 32) = a10;
              *(_BYTE *)(v17 + 36) = a11;
              *(_DWORD *)(v17 + 40) = a2;
              memcpy((void *)(v17 + 44), __src, __n);
              result = __n;
              *(_BYTE *)(__n + v17 + 44) = 0;
            }
        }
    }
  return result;
}

void __cdecl R_AddCmdDrawStretchRaw(int x, int y, int w, int h, int cols,
                                    int rows, unsigned char const *data,
                                    int client, int dirty)
{
  int v9;     // ecx
  int v10;    // ebx
  int result; // eax
  _WORD *v12; // edx

  v9 = s_cmdList;
  v10 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v10 - 0x2000;
    if (result > 39) {
      v12 = (_WORD *)(s_cmdList + v10);
      *(_DWORD *)(s_cmdList + 196608) = v10 + 40;
      *(_DWORD *)(v9 + 196616) = v9 + v10;
      *v12 = 17;
      v12[1] = 40;
      result = v9 + v10;
        if (v9 + v10) {
          *(_DWORD *)(result + 4) = a1;
          *(_DWORD *)(result + 8) = a2;
          *(_DWORD *)(result + 12) = a3;
          *(_DWORD *)(result + 16) = a4;
          *(_DWORD *)(result + 20) = a5;
          *(_DWORD *)(result + 24) = a6;
          *(_DWORD *)(result + 28) = a7;
          *(_DWORD *)(result + 32) = a8;
          *(_DWORD *)(result + 36) = a9;
        }
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_AddCmdDrawStretchPicRotate(float x, float y, float w, float h,
                                          float s0, float t0, float s1,
                                          float t1, float angle,
                                          float const *const color,
                                          struct Material *material)
{
  int v11; // ecx
  int v12; // ebx
  int v13; // edx
  int v14; // ebx

  v11 = s_cmdList;
  v12 = *(_DWORD *)(s_cmdList + 196608);
    if (*(_DWORD *)(s_cmdList + 196612) + 196608 - v12 - 0x2000 > 47) {
      v13 = s_cmdList + v12;
      *(_DWORD *)(s_cmdList + 196608) = v12 + 48;
      *(_DWORD *)(v11 + 196616) = v11 + v12;
      *(_WORD *)v13 = 16;
      *(_WORD *)(v13 + 2) = 48;
      v14 = v11 + v12;
        if (v13) {
          *(_DWORD *)(v13 + 4) = a11;
          *(float *)(v13 + 8) = a1;
          *(float *)(v13 + 12) = a2;
          *(float *)(v13 + 16) = a3;
          *(float *)(v13 + 20) = a4;
          *(float *)(v13 + 24) = a5;
          *(float *)(v13 + 28) = a6;
          *(float *)(v13 + 32) = a7;
          *(float *)(v13 + 36) = a8;
          R_ConvertColorToBytes(a10, (unsigned __int8 *)(v13 + 40));
          *(float *)(v14 + 44) = AngleNormalize360(a9);
        }
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
}

void __cdecl R_AddCmdDrawStretchPic(float x, float y, float w, float h,
                                    float s0, float t0, float s1, float t1,
                                    float const *const color,
                                    struct Material *material)
{
  int v10;    // ecx
  int v11;    // ebx
  int result; // eax
  int v13;    // edx

  v10 = s_cmdList;
  v11 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v11 - 0x2000;
    if (result > 43) {
      v13 = s_cmdList + v11;
      *(_DWORD *)(s_cmdList + 196608) = v11 + 44;
      *(_DWORD *)(v10 + 196616) = v10 + v11;
      *(_WORD *)v13 = 15;
      *(_WORD *)(v13 + 2) = 44;
      result = v10 + v11;
        if (v10 + v11) {
          *(_DWORD *)(v13 + 4) = a10;
          *(float *)(v13 + 8) = a1;
          *(float *)(v13 + 12) = a2;
          *(float *)(v13 + 16) = a3;
          *(float *)(v13 + 20) = a4;
          *(float *)(v13 + 24) = a5;
          *(float *)(v13 + 28) = a6;
          *(float *)(v13 + 32) = a7;
          *(float *)(v13 + 36) = a8;
          return R_ConvertColorToBytes(a9, (unsigned __int8 *)(result + 40));
        }
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_IssueDelayedDrawing(int marker)
{
  int v1;     // ecx
  int v2;     // ebx
  int result; // eax
  int v4;     // edx

  v1 = s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v2 > 7) {
      v4 = s_cmdList + v2;
      *(_DWORD *)(s_cmdList + 196608) = v2 + 8;
      *(_DWORD *)(v1 + 196612) += 8;
      *(_DWORD *)(v1 + 196616) = v1 + v2;
      *(_WORD *)v4 = 2;
      *(_WORD *)(v4 + 2) = 8;
      result = v1 + a1 + 8;
      *(_DWORD *)(v4 + 4) = result;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      result = v1 + a1 + 8;
      MEMORY[4] = result;
    }
  return result;
}

void __cdecl R_EndDelayedDrawing(int marker)
{
  _DWORD *v1; // ecx
  int v2;     // edx
  char *v3;   // edx
  int result; // eax
  _WORD *v5;  // eax

  v1 = (_DWORD *)s_cmdList;
  v2 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v2 > 3) {
      v5 = (_WORD *)(s_cmdList + v2);
      *(_DWORD *)(s_cmdList + 196608) = v2 + 4;
      v1[49153] += 4;
      v1[49154] = (char *)v1 + v2;
      *v5 = 3;
      v5[1] = 4;
      v3 = (char *)v1 + v1[49152];
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      v3 = (char *)v1 + v2;
    }
  result = a1;
  *(_DWORD *)((char *)v1 + a1 + 4) = v3;
  return result;
}

int __cdecl R_BeginDelayedDrawing()
{
  int v0;    // ecx
  int v1;    // ebx
  _WORD *v3; // edx

  v0 = s_cmdList;
  v1 = *(_DWORD *)(s_cmdList + 196608);
    if (196608 - v1 > 7) {
      v3 = (_WORD *)(s_cmdList + v1);
      *(_DWORD *)(s_cmdList + 196608) = v1 + 8;
      *(_DWORD *)(v0 + 196612) += 8;
      *(_DWORD *)(v0 + 196616) = v0 + v1;
      *v3 = 1;
      v3[1] = 8;
      *(_DWORD *)(v0 + v1 + 4) = 0;
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
      MEMORY[4] = 0;
    }
  return v1;
}

void __cdecl R_SkinGfxEntityDelayed(struct GfxEntity *)
{
  R_ProcessFrontendCmdInternal(1, &a1, 0);
}

void __cdecl R_UpdateXModelBoundsDelayed(struct GfxEntity *ent)
{
  R_ProcessFrontendCmdInternal(0, &a1, 0);
}

void __cdecl R_UpdateEffectsNonBolt()
{
  R_ProcessFrontendCmdInternal(3, (GfxEntity **)&g_dummyBuf, 0);
}

void __cdecl R_UpdateEffectsBolt()
{
  R_ProcessFrontendCmdInternal(4, (GfxEntity **)&g_dummyBuf, 0);
}

void __cdecl R_ShutdownBackendData()
{
  return R_ShutdownDebugEntry(&_b);
}

void __cdecl R_InitBackendData()
{
  UNIMPLEMENTED();
}

int __cdecl R_ForceEndRemoteScreenUpdate(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawLines(short, short, struct GfxPointVertex const *const)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawPoints(short, short,
                                struct GfxPointVertex const *const)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawSurfsReversed(struct GfxDrawSurf *, int,
                                       enum MaterialTechniqueType)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawSurfs(struct GfxDrawSurf *drawSurfs, int drawSurfCount,
                               enum MaterialTechniqueType techType)
{
  int v3;     // ecx
  int v4;     // ebx
  int result; // eax
  int v6;     // edx

  v3 = s_cmdList;
  v4 = *(_DWORD *)(s_cmdList + 196608);
  result = *(_DWORD *)(s_cmdList + 196612) + 196608 - v4 - 0x2000;
    if (result > 19) {
      v6 = s_cmdList + v4;
      *(_DWORD *)(s_cmdList + 196608) = v4 + 20;
      *(_DWORD *)(v3 + 196616) = v3 + v4;
      *(_WORD *)v6 = 23;
      *(_WORD *)(v6 + 2) = 20;
      result = v3 + v4;
        if (v3 + v4) {
          *(_DWORD *)(v6 + 4) = 0;
          *(_DWORD *)(result + 8) = a1;
          *(_DWORD *)(result + 12) = a2;
          *(_DWORD *)(result + 16) = a3;
        }
    }
    else {
      *(_DWORD *)(s_cmdList + 196616) = 0;
    }
  return result;
}

void __cdecl R_SyncRenderThread()
{
  ;
}

void __cdecl R_AbortRenderCommands()
{
  UNIMPLEMENTED();
}

void __cdecl R_BeginFrame()
{
  UNIMPLEMENTED();
}

void __cdecl R_ReleaseThreadOwnership(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_BeginRemoteScreenUpdate(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_ForceBeginRemoteScreenUpdate(int)
{
  UNIMPLEMENTED();
}

int __cdecl R_ProcessFrontendCmd(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl R_ProcessFrontendCmdsForBackend(void)
{
  UNIMPLEMENTED();
}

int __cdecl R_ProcessNonSkinFrontendCmds(int)
{
  UNIMPLEMENTED();
}

void __cdecl R_EndDebugFrame()
{
  UNIMPLEMENTED();
}

void __cdecl R_WaitNonSkinFrontendCmds(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_ProcessFrontendCmds(int)
{
  UNIMPLEMENTED();
}

void __cdecl R_WaitFrontendCmds(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_InitFrontendThread(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_EndFrame()
{
  UNIMPLEMENTED();
}

void __cdecl R_InitRenderThread(void)
{
  UNIMPLEMENTED();
}

struct GfxBackEndData *frontEndDataOut;
long volatile g_frontendCmdProcessCount;
int marker_r_rendercmds;
int volatile g_freezeFrontedCmds;
struct SkinBuffers *g_skinBuffers;

void __cdecl R_SetTestLods(void)
{
  UNIMPLEMENTED();
}

bool __cdecl R_CheckDvarModified(struct dvar_s const *)
{
  UNIMPLEMENTED();
}

void *__cdecl R_GetCommandBuffer(enum GfxRenderCommand, int)
{
  UNIMPLEMENTED();
}

int __cdecl R_IsPendingNonSkinFrontendCmds(void)
{
  UNIMPLEMENTED();
}

int __cdecl R_IsPendingFrontendCmds(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_ClearCmdList(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_InitFrontendCmdsPos(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_PerformanceCounters(void)
{
  UNIMPLEMENTED();
}

bool __cdecl R_LightTweaksModified(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdDrawSurfsInOrder(struct GfxDrawSurf *, int,
                                      enum MaterialTechniqueType,
                                      enum GfxDrawSurfOrder)
{
  UNIMPLEMENTED();
}

void __cdecl R_AddCmdEndOfList(void)
{
  UNIMPLEMENTED();
}

void *__cdecl R_GrowCommandBuffer(int)
{
  UNIMPLEMENTED();
}

void __cdecl R_InitFrontendCmds(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_UpdateFrontEndDvarOptions(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_ProcessFrontendCmdInternal(int, void *, int)
{
    switch (a1) {
    case 0:
      R_UpdateGfxEntityBounds(*a2);
      break;
    case 1:
      R_SkinGfxEntity(*a2);
      break;
    case 2:
      R_SkinRigidXModelCmd((SkinRigidXModelCmd *)a2);
      break;
    case 3:
      FX_UpdateScheduledEffectsNonBolt();
      break;
    case 4:
      FX_UpdateScheduledEffectsBolt();
      break;
    case 5:
      R_SkinStaticModelCachedCmd((SkinStaticModelCachedCmd *)a2,
                                 (SkinBuffers *)(40960 * a3 + 18298368));
      break;
    case 6:
    case 7:
      R_SkinXModelCmd((SkinXModelCmd *)a2, a3);
      break;
    default:
      return;
    }
}

void __cdecl R_ToggleSmpFrameCmd(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_FrontendThread2(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_FrontendThread(void)
{
  UNIMPLEMENTED();
}

void __cdecl R_IssueRenderCommands(void)
{
  UNIMPLEMENTED();
}

R_AddCmdTouchAllImages()
{
  UNIMPLEMENTED();
}
