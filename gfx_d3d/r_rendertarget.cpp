public:
long __cdecl D3DDevice::CreateTexture(unsigned int, unsigned int, unsigned int,
                                      unsigned long, enum _D3DFORMAT,
                                      unsigned long, struct D3DTexture **,
                                      void **) {
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::CreateRenderTarget(
    unsigned int, unsigned int, enum _D3DFORMAT, enum _D3DMULTISAMPLE_TYPE,
    unsigned long, int, struct D3DSurface **,
    struct _D3DSURFACE_PARAMETERS const *) {
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::CreateDepthStencilSurface(
    unsigned int, unsigned int, enum _D3DFORMAT, enum _D3DMULTISAMPLE_TYPE,
    unsigned long, int, struct D3DSurface **,
    struct _D3DSURFACE_PARAMETERS const *) {
  UNIMPLEMENTED();
}

public:
unsigned long __cdecl D3DResource::AddRef(void) { UNIMPLEMENTED(); }

public:
unsigned long __cdecl D3DResource::Release(void) { UNIMPLEMENTED(); }

void __cdecl R_ShutdownRenderTargets() { UNIMPLEMENTED(); }

void __cdecl R_InitRenderTargets() { UNIMPLEMENTED(); }

int marker_r_rendertarget;
void __cdecl R_SetBackBufferFormat(void) { UNIMPLEMENTED(); }

int __cdecl R_RenderTargetImageSize(int, int, enum _D3DFORMAT) {
  UNIMPLEMENTED();
}

void __cdecl R_ReserveHighDefRenderTargetMemory(int, int, enum _D3DFORMAT) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFrameBufferRenderTarget_Xbox360_1280x720x2_TileBot(
    struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFrameBufferRenderTarget_Xbox360_1280x720x2_TileTop(
    struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFrameBufferRenderTarget_Xbox360_1280x720x2_SingleSample(
    struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFrameBufferRenderTarget_Xbox360_Untiled(void) {
  UNIMPLEMENTED();
}

struct D3DSurface *__cdecl R_AssignShadowCookieDepthStencilSurface(void) {
  UNIMPLEMENTED();
}

struct D3DSurface *__cdecl R_AssignSingleSampleDepthStencilSurface(void) {
  UNIMPLEMENTED();
}

void __cdecl R_InitRenderTargetImage(int, unsigned short, unsigned short,
                                     enum _D3DFORMAT, enum RenderTargetUsage,
                                     struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFrameBufferRenderTarget_Xbox360_1280x720x2(void) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFullscreenRenderTargetImage(int, int, enum _D3DFORMAT,
                                               enum RenderTargetUsage,
                                               struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitAndTrackRenderTargetImage(int, unsigned short,
                                             unsigned short, enum _D3DFORMAT,
                                             enum RenderTargetUsage,
                                             struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitFrameBufferRenderTarget(void) { UNIMPLEMENTED(); }

void __cdecl R_InitShadowCookieRenderTarget(struct GfxRenderTarget *) {
  UNIMPLEMENTED();
}

R_DescribeFormat(_D3DFORMAT format) { UNIMPLEMENTED(); }
