float __cdecl cos(float) { UNIMPLEMENTED(); }

float __cdecl sin(float) { UNIMPLEMENTED(); }

float __cdecl tan(float) { UNIMPLEMENTED(); }

void __cdecl FastSinCos(float, float *, float *) { UNIMPLEMENTED(); }

void __cdecl Vec3Negate(float const *const, float *const) { UNIMPLEMENTED(); }

public:
int __cdecl FxHelper::GetSeed() { UNIMPLEMENTED(); }

public:
void __cdecl FxHelper::CameraShake(float *const origin, float intensity,
                                   int radius, int time_) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::AddPolyToScene(struct Material *, int,
                                      struct GfxWorldVertex const *const) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::AddLightToScene(float *const org, float radius,
                                       float red, float green, float blue) {
  UNIMPLEMENTED();
}

public:
bool __cdecl FxHelper::IsMaterialRefractive(struct Material *handle) {
  UNIMPLEMENTED();
}

public:
int __cdecl FxHelper::GetMaterialSubimageCount(struct Material *handle) {
  UNIMPLEMENTED();
}

public:
char const *__cdecl FxHelper::GetMaterialName(struct Material *handle) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::SetIgnorePrecacheErrors(bool ignore) { UNIMPLEMENTED(); }

public:
void __cdecl FxHelper::AdjustTime(int intime) { UNIMPLEMENTED(); }

public:
void __cdecl FxHelper::Init() { UNIMPLEMENTED(); }

public:
__cdecl FxHelper::FxHelper() { UNIMPLEMENTED(); }

public:
bool __cdecl FxHelper::CullCylinder(float const *const worldPos0,
                                    float const *const worldPos1, float radius0,
                                    float radius1, int planeCount) {
  UNIMPLEMENTED();
}

public:
bool __cdecl FxHelper::CullSpherePreviousFrame(float const *const worldPos,
                                               float radius) {
  UNIMPLEMENTED();
}

public:
bool __cdecl FxHelper::CullSphere(float const *const worldPos, float radius,
                                  int planeCount) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::CalcFrustumPlanes(struct refdef_s *refdef, float zfar) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::AdjustCamera(struct refdef_s *refdef, float zfar) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::Trace(struct trace_t *tr, float *const start,
                             float const *const min, float const *const max,
                             float *const end, int skipEntNum, int flags) {
  UNIMPLEMENTED();
}

public:
void __cdecl FxHelper::Archive(class FxArchive &arch) { UNIMPLEMENTED(); }

public:
void __cdecl FxHelper::WarpTime(int intime) { UNIMPLEMENTED(); }

public:
void __cdecl FxHelper::AddFxToScene(struct GfxEntity *ent,
                                    struct XModel const *model) {
  UNIMPLEMENTED();
}

int marker_FxSystem;
