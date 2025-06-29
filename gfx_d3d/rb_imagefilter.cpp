float __cdecl exp(float)
{
  UNIMPLEMENTED();
}

void __cdecl RB_GaussianFilterImage(float radius,
                                    enum GfxRenderTargetId renderTargetId)
{
  UNIMPLEMENTED();
}

void __cdecl RB_GlowFilterImage(float *const radius)
{
  __m128 v4;            // xmm2
  float v5;             // xmm0_4
  float *v6;            // edi
  float v7;             // xmm0_4
  __m128 v8;            // xmm1
  GfxRenderTargetId v9; // ecx
  __m128 v10;           // xmm1
  bool v11;             // al

  v4 = (__m128) * (unsigned int *)a4;
    if (v4.f32[0] != 0.0) {
      v5 = (float)dword_118050C[33] / (float)dword_1180504;
      v4.f32[0] = v4.f32[0] * v5;
      *a4 = v4.f32[0];
      v6 = a4 + 1;
      v7 = v5 * a4[1];
      a4[1] = v7;
      g_LastGlowFilter = v7 == 0.0;
      v8 = (__m128) * ((unsigned int *)a4 + 1);
        if (v8.f32[0] != 0.0) {
          v8.f32[0] = (float)(v8.f32[0] * v8.f32[0]) - (float)(*a4 * *a4);
          v11 = 1;
          if (fsqrt(v8.f32[0]) != 0.0)
            v11 = v7 == 0.0;
          g_LastGlowFilter = v11;
        }
      v9 = RB_ApplyGlowFilter(dword_11E4488, R_RENDERTARGET_GLOW_0, a1, *a4, v8,
                              v4, (__m128)0LL, a2, a3);
      unk_11E1AD4 = dx[5 * v9 + 2828];
      v10 = (__m128) * (unsigned int *)v6;
        if (v10.f32[0] == 0.0) {
          dword_11E1AD0 = 1;
        }
        else {
          v10.f32[0] = (float)(v10.f32[0] * v10.f32[0]) - (float)(*a4 * *a4);
          *v6 = fsqrt(v10.f32[0]);
          g_LastGlowFilter = 1;
          unk_11E1AD8 =
              dx[5 * RB_ApplyGlowFilter(v9, R_RENDERTARGET_GLOW_0, a1, *v6, v10,
                                        v4, (__m128)0LL, a2, a3) +
                 2828];
          dword_11E1AD0 = 2;
        }
    }
}

int marker_rb_imagefilter;

int __cdecl RB_PickSymmetricFilterMaterial(int, struct Material const **)
{
  UNIMPLEMENTED();
}

void __cdecl RB_VirtualToRealRadius(float, float *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetupFilterPass(struct GfxImageFilterPass const *)
{
  UNIMPLEMENTED();
}

int __cdecl RB_GaussianFilterPoints1D(float, int, int, int, float *const,
                                      float *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_GenerateGaussianFilter2D(float, int, int, int, int,
                                         struct GfxImageFilterPass *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_GenerateGaussianFilter1D(float, int *const, int,
                                         struct GfxImageFilterPass *)
{
  UNIMPLEMENTED();
}

int __cdecl RB_GenerateGaussianFilterChain(float, float, int, int, int, int,
                                           int,
                                           struct GfxImageFilterPass *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_FilterPingPongEnd(struct GfxImageFilter const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_FilterPingPong(struct GfxImageFilter const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl RB_FilterImage(struct GfxImageFilter *)
{
  UNIMPLEMENTED();
}

enum GfxRenderTargetId __cdecl RB_ApplyGlowFilter(float, enum GfxRenderTargetId,
                                                  enum GfxRenderTargetId)
{
  UNIMPLEMENTED();
}
