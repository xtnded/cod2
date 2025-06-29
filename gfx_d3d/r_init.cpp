public:
static long __cdecl Direct3D::GetDeviceCaps(unsigned int, enum _D3DDEVTYPE,
                                            struct _D3DCAPS9 *) {
  UNIMPLEMENTED();
}

public:
static long __cdecl Direct3D::CreateDevice(unsigned int, enum _D3DDEVTYPE,
                                           void *, unsigned long,
                                           struct _D3DPRESENT_PARAMETERS_ *,
                                           struct D3DDevice **) {
  UNIMPLEMENTED();
}

public:
unsigned long __cdecl D3DDevice::Release(void) { UNIMPLEMENTED(); }

public:
long __cdecl D3DDevice::EndScene(void) { UNIMPLEMENTED(); }

public:
long __cdecl D3DDevice::CreateQuery(enum _D3DQUERYTYPE, struct D3DQuery **) {
  UNIMPLEMENTED();
}

float __cdecl pow(float, float) { UNIMPLEMENTED(); }

int __cdecl R_GetVertexSize(void) { UNIMPLEMENTED(); }

void __cdecl R_EndRegistration() {
  Material_FinishLoading();
  return R_AddCmdTouchAllImages();
}

char const *__cdecl R_ErrorDescription(long hr) {
  return DXGetErrorDescription9A();
}

void __cdecl R_FatalLockError(long hr) {
  void (*v0)(_DWORD, const char *, ...); // esi
  const char *v1;                        // eax

  ri(0, "********** DirectX failed a call to lock a vertex buffer or an index "
        "buffer **********\n");
  v0 = (void (*)(_DWORD, const char *, ...))ri;
  v1 = (const char *)DXGetErrorDescription9A();
  v0(0, "********** error information:  %s\n", v1);
  return dword_1180708();
}

void __cdecl R_FatalInitError(char const *msg) {
  ri(0, "********** DirectX returned an unrecoverable error code during "
        "initialization  **********\n");
  ri(0, "********** Initialization also happens while playing if DirectX loses "
        "a device **********\n");
  ri(0, "********** Consult the readme for how to continue from this problem   "
        "         **********\n");
  ri(0, "\n%s\n", a1);
  return dword_1180708();
}

void __cdecl R_UnloadWorld(void) { UNIMPLEMENTED(); }

void __cdecl R_Error(enum errorParm_t errorLevel, char const *msg, ...) {
  char __str[1024]; // [esp+1Ch] [ebp-40Ch] BYREF
  va_list v4;       // [esp+41Ch] [ebp-Ch]
  va_list va;       // [esp+438h] [ebp+10h] BYREF

  va_start(va, __format);
  if (Sys_IsMainThread())
    R_SyncRenderThread();
  if (byte_11805DD) {
    (*(void(__cdecl **)(int))(*(_DWORD *)dword_117D8A8 + 168))(dword_117D8A8);
    byte_11805DD = 0;
  }
  va_copy(v4, va);
  vsnprintf(__str, 0x3FFu, __format, va);
  __str[1023] = 0;
  return dword_11806C4(a1, "%s", __str);
}

void __cdecl R_ReleaseAndSetNULL(struct IUnknown *, char const *, char const *,
                                 int) {
  UNIMPLEMENTED();
}

void __cdecl R_GammaCorrect(unsigned char *buffer, int bufSize) {
  float v2;       // xmm0_4
  int v3;         // ebx
  int result;     // eax
  int i;          // ebx
  float v6;       // xmm0_4
  long double v7; // [esp+0h] [ebp-248h]
  int v8;         // [esp+10h] [ebp-238h]
  float v9;       // [esp+1Ch] [ebp-22Ch]
  double v10;     // [esp+28h] [ebp-220h]
  _WORD v11[268]; // [esp+30h] [ebp-218h]

  v2 = 1.0 / *(float *)(r_gamma + 8);
  v3 = 0;
  v10 = v2;
  if (v2 == 1.0) {
    do {
      v11[v3] = 257 * v3;
      ++v3;
    } while (v3 != 256);
  } else {
    do {
      *((double *)&v7 + 1) = v10;
      *(double *)&v7 = (float)((float)v3 / 255.0);
      v6 = pow(v7, v8);
      v9 = floorf((float)(v6 * 65535.0) + 0.5);
      v11[v3++] = (int)v9;
    } while (v3 != 256);
  }
  result = a2;
  if (a2 > 0) {
    for (i = 0; i != a2; ++i) {
      result = 2139127681 * (unsigned __int16)v11[a1[i]];
      a1[i] = (unsigned __int16)v11[a1[i]] / 257;
    }
  }
  return result;
}

void __cdecl R_SetColorMappings() {
  float v0;        // xmm0_4
  int v1;          // ebx
  int result;      // eax
  float v3;        // xmm0_4
  long double v4;  // [esp+0h] [ebp-238h]
  int v5;          // [esp+10h] [ebp-228h]
  float v6;        // [esp+1Ch] [ebp-21Ch]
  double v7;       // [esp+28h] [ebp-210h]
  GfxGammaRamp v8; // [esp+30h] [ebp-208h] BYREF

  if ((_BYTE)dword_11806A8) {
    v0 = 1.0 / *(float *)(r_gamma + 8);
    v1 = 0;
    v7 = v0;
    if (v0 == 1.0) {
      do {
        *(_WORD *)&v8.entries[2 * v1] = 257 * v1;
        ++v1;
      } while (v1 != 256);
    } else {
      do {
        *((double *)&v4 + 1) = v7;
        *(double *)&v4 = (float)((float)v1 / 255.0);
        v3 = pow(v4, v5);
        v6 = floorf((float)(v3 * 65535.0) + 0.5);
        *(_WORD *)&v8.entries[2 * v1++] = (int)v6;
      } while (v1 != 256);
    }
    return RB_SetGammaRamp(&v8);
  }
  return result;
}

void __cdecl R_ShutdownStreams(void) { UNIMPLEMENTED(); }

void __cdecl R_Register(void) { UNIMPLEMENTED(); }

void __cdecl R_ShutdownDirect3D(void) { UNIMPLEMENTED(); }

void __cdecl R_BeginRegistration(struct vidConfig_t *vidConfigOut) {
  UNIMPLEMENTED();
}

void __cdecl R_InitThreads(void) { UNIMPLEMENTED(); }

int g_disableRendering;
int marker_r_init;
struct DxGlobals dx;
void __cdecl R_TrackStatistics(struct trStatistics_t *) {
  trStatistics_t *result; // eax

  result = a1;
  dword_1183A78 = (int)a1;
  return result;
}

void __cdecl R_InitModelDObj(void) { UNIMPLEMENTED(); }

void __cdecl R_InitGlobalStructs(void) { UNIMPLEMENTED(); }

bool __cdecl R_ReduceWindowSettings(struct GfxWindowParms *) {
  UNIMPLEMENTED();
}

void __cdecl R_SetWndParms(struct GfxWindowParms *) { UNIMPLEMENTED(); }

unsigned int __cdecl R_ChooseAdapter(void) { UNIMPLEMENTED(); }

enum _D3DDEVTYPE __cdecl R_GetDeviceType(void) { UNIMPLEMENTED(); }

void __cdecl R_InitGamma(void) { UNIMPLEMENTED(); }

void __cdecl R_StoreWindowSettings(struct GfxWindowParms const *) {
  UNIMPLEMENTED();
}

void __cdecl R_SetupAntiAliasing(struct GfxWindowParms const *) {
  UNIMPLEMENTED();
}

void __cdecl R_GetDirect3DCaps(unsigned int, struct _D3DCAPS9 *) {
  UNIMPLEMENTED();
}

void __cdecl R_SetD3DPresentParameters(struct _D3DPRESENT_PARAMETERS_ *,
                                       struct GfxWindowParms const *) {
  UNIMPLEMENTED();
}

void __cdecl R_DoneRenderingViews(void) { return R_IssueDrawGroups(); }

void __cdecl R_EndView(int) {
  R_EndDrawGroupLoop(R_DRAWGROUP_POST_AA, a1);
  return R_EndDrawGroupSection(R_DRAWGROUP_POST_AA);
}

void __cdecl R_InitFunctionTables(void) { UNIMPLEMENTED(); }

void __cdecl R_StoreDirect3DCaps(unsigned int) { UNIMPLEMENTED(); }

void __cdecl R_InitFFT(void) { UNIMPLEMENTED(); }

bool __cdecl R_PreCreateWindow(void) { UNIMPLEMENTED(); }

void __cdecl R_CalcGammaRamp(struct GfxGammaRamp *) { UNIMPLEMENTED(); }

void __cdecl R_CreateDynamicIndexBuffer(struct r_ib_state_t *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_CreateDynamicVertexBuffer(struct r_vb_state_t *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_CreateDynamicBuffers(void) { UNIMPLEMENTED(); }

void __cdecl R_CreateParticleCloudBuffer(void) {
  int v0;      // ebx
  _WORD *v1;   // eax
  int v2;      // edi
  _WORD *j;    // esi
  int v4;      // ebx
  float v5;    // xmm1_4
  int v6;      // ecx
  int v7;      // edx
  _WORD *v8;   // edx
  float v10;   // [esp+10h] [ebp-68h]
  float v11;   // [esp+20h] [ebp-58h]
  int i;       // [esp+34h] [ebp-44h]
  int v13;     // [esp+38h] [ebp-40h]
  int v14;     // [esp+3Ch] [ebp-3Ch]
  _WORD *v15;  // [esp+48h] [ebp-30h]
  __int16 v16; // [esp+4Eh] [ebp-2Ah]
  int v17;     // [esp+50h] [ebp-28h]
  int v18;     // [esp+54h] [ebp-24h]
  int v19;     // [esp+58h] [ebp-20h]
  int v20;     // [esp+5Ch] [ebp-1Ch]

  v0 = R_AllocStaticVertexBuffer(&dword_1180658, (int)&loc_14000);
  v19 = R_AllocStaticIndexBuffer(&dword_118065C, 12288);
  v20 = v0;
  for (i = 0; i != 8; ++i) {
    v16 = (_WORD)i << 7;
    v17 = v20;
    v1 = (_WORD *)v19;
    v18 = v19;
    v13 = 0;
    while (1) {
      v15 = v1;
      v2 = v17;
      v14 = 0;
      for (j = v1;; j = v15) {
        v4 = v2;
        v10 =
            (float)((float)((float)((float)rand() * 4.6566129e-10) + (float)i) *
                    0.25) -
            1.0;
        v11 = (float)((float)((float)((float)rand() * 4.6566129e-10) +
                              (float)v13) *
                      0.25) -
              1.0;
        v5 = (float)((float)((float)((float)rand() * 4.6566129e-10) +
                             (float)v14) *
                     0.125) -
             1.0;
        v6 = 0;
        v7 = 0;
        do {
          *(float *)v4 = v10;
          *(float *)(v4 + 4) = v11;
          *(float *)(v4 + 8) = v5;
          *(_DWORD *)(v4 + 12) = cornerTexCoords_136164[v7];
          *(_DWORD *)(v4 + 16) = dword_2F2244[v7];
          v4 += 20;
          ++v6;
          v7 += 2;
        } while (v6 != 4);
        v8 = &quadIndices_136165;
        do
          *j++ = *v8++ + 4 * (v14 + v16);
        while (&unk_2F222C != (_UNKNOWN *)v8);
        ++v14;
        v15 += 6;
        v2 += 80;
        if (v14 == 16)
          break;
      }
      ++v13;
      v16 += 16;
      v17 += 1280;
      v18 += 192;
      if (v13 == 8)
        break;
      v1 = (_WORD *)v18;
    }
    v19 += 1536;
    v20 += 10240;
  }
  R_FinishStaticIndexBuffer(dword_118065C);
  return R_FinishStaticVertexBuffer(dword_1180658);
}

void __cdecl R_InitSystems(void) { UNIMPLEMENTED(); }

void __cdecl R_Shutdown(int) { UNIMPLEMENTED(); }

long __cdecl R_CreateDevice(struct HWND__ *, unsigned long,
                            struct _D3DPRESENT_PARAMETERS_ *) {
  UNIMPLEMENTED();
}

bool __cdecl R_CreateForInitOrReset(struct _D3DPRESENT_PARAMETERS_ const *,
                                    struct GfxWindowParms const *) {
  UNIMPLEMENTED();
}

bool __cdecl R_InitHardware(struct GfxWindowParms const *) { UNIMPLEMENTED(); }

bool __cdecl R_CreateGameWindow(struct GfxWindowParms *) { UNIMPLEMENTED(); }

void __cdecl R_InitDirect3D(void) { UNIMPLEMENTED(); }

void __cdecl R_Init(void) { UNIMPLEMENTED(); }

R_UpdateGpuSyncType() { UNIMPLEMENTED(); }

void std::__adjust_heap<_D3DDISPLAYMODE *, int, _D3DDISPLAYMODE,
                        unsigned char (*)(_D3DDISPLAYMODE const &,
                                          _D3DDISPLAYMODE const &)>(
    _D3DDISPLAYMODE *, int, int, _D3DDISPLAYMODE,
    unsigned char (*)(_D3DDISPLAYMODE const &, _D3DDISPLAYMODE const &)) {
  UNIMPLEMENTED();
}

void std::__insertion_sort<_D3DDISPLAYMODE *,
                           unsigned char (*)(_D3DDISPLAYMODE const &,
                                             _D3DDISPLAYMODE const &)>(
    _D3DDISPLAYMODE *, _D3DDISPLAYMODE *,
    unsigned char (*)(_D3DDISPLAYMODE const &, _D3DDISPLAYMODE const &)) {
  UNIMPLEMENTED();
}

void std::__introsort_loop<_D3DDISPLAYMODE *, int,
                           unsigned char (*)(_D3DDISPLAYMODE const &,
                                             _D3DDISPLAYMODE const &)>(
    _D3DDISPLAYMODE *, _D3DDISPLAYMODE *, int,
    unsigned char (*)(_D3DDISPLAYMODE const &, _D3DDISPLAYMODE const &)) {
  UNIMPLEMENTED();
}

R_RecoverLostDevice() { UNIMPLEMENTED(); }
