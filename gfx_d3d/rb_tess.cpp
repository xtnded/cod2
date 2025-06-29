int const __cdecl Vec3CompareEpsilon(float const *const, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl Byte4CopyRgbaToNativeColor(unsigned char const *const,
                                        unsigned char *const) {
  UNIMPLEMENTED();
}

struct D3DVertexBuffer *__cdecl R_VertexBufferPointer(struct r_vb_state_t *) {
  UNIMPLEMENTED();
}

struct D3DIndexBuffer *__cdecl XSurfaceGetIndexBuffer(struct XSurface_s *) {
  UNIMPLEMENTED();
}

struct D3DVertexBuffer *__cdecl XRigidSurfaceGetVertexBuffer(
    struct XRigidSurface *) {
  UNIMPLEMENTED();
}

void __cdecl RB_CheckOverflowOptimized(int) { UNIMPLEMENTED(); }

void __cdecl RB_TessBad(enum surfaceType_t const *surfType) { ; }

void __cdecl RB_TessRawGeometry(enum surfaceType_t const *) { UNIMPLEMENTED(); }

void __cdecl RB_TessXModelRigid(enum surfaceType_t const *surfType) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessParticleCloud(struct GfxEntity const *) { UNIMPLEMENTED(); }

void __cdecl RB_TessXModelSkinned(enum surfaceType_t const *surfType) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessTriangles(enum surfaceType_t const *surfType) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessStaticModelCached(enum surfaceType_t const *surfType) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessPoly(enum surfaceType_t const *surfType) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessEntity(struct GfxEntity const *re) { UNIMPLEMENTED(); }

void __cdecl RB_TessBackEndEntity(enum surfaceType_t const *surfType) {
  UNIMPLEMENTED();
}

int marker_rb_tess;
void __cdecl RB_Vec3WorldToHomogenousScreen(float const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_GetScreenW(float const *const, float *) { UNIMPLEMENTED(); }

void __cdecl RB_Vec3DirWorldToView(float const *const, float *const) {
  UNIMPLEMENTED();
}

bool __cdecl RB_RadiusWorldToScreen(float const *const, float const *const,
                                    float *const) {
  UNIMPLEMENTED();
}

bool __cdecl RB_HeightScreenToWorld(float const *const, float, float *) {
  UNIMPLEMENTED();
}

void __cdecl RB_CalcSpriteTexCoords(struct GfxEntity const *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetModelMatrixForRigidSurface(
    struct GfxEntity const *, struct GfxModelRigidSurface const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_CreateParticleCloud2dAxis(struct GfxEntity const *,
                                          float const *const,
                                          float (*const)[2]) {
  UNIMPLEMENTED();
}

void __cdecl RB_SetParticleCloudConstants(struct GfxEntity const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessXModelSkinnedCached(struct GfxModelSkinnedSurface const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_AddLine(float const *const, float const *const, float,
                        unsigned long, float, float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessCylinder(struct GfxEntity const *) { UNIMPLEMENTED(); }

void __cdecl RB_AddQuadStamp(float const *const, float const *const,
                             float const *const, int, float, float, float,
                             float) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessLine(struct GfxEntity const *) { UNIMPLEMENTED(); }

void __cdecl RB_TessRailCore(struct GfxEntity const *) { UNIMPLEMENTED(); }

void __cdecl RB_TessOrientedQuad(struct GfxEntity const *) { UNIMPLEMENTED(); }

void __cdecl RB_BuildSprite(struct GfxEntity const *, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessSpriteFixedWorldSize(struct GfxEntity const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessSpriteFixedScreenSize(struct GfxEntity const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_TessSprite(struct GfxEntity const *) { UNIMPLEMENTED(); }
