void __cdecl CM_CalcTraceEntents(struct TraceExtents *extents)
{
  TraceExtents *result; // eax
  int v2;               // edx
  float v3;             // xmm0_4
  float v4;             // xmm0_4

  result = a1;
  v2 = 3;
    do {
      v3 = result->start[0] - result->end[0];
      if (v3 == 0.0)
        v4 = 0.0;
      else
        v4 = 1.0 / v3;
      result->invDelta[0] = v4;
      result = (TraceExtents *)((char *)result + 4);
      --v2;
    }
  while (v2);
  return result;
}

int __cdecl CM_TraceBox(struct TraceExtents const *extents,
                        float const *const mins, float const *const maxs,
                        float fraction)
{
  __m128 v4;              // xmm5
  float v6;               // xmm6_4
  float v7;               // xmm3_4
  __m128 v8;              // xmm4
  const TraceExtents *v9; // eax
  int i;                  // edx
  float v11;              // xmm0_4
  __m128 v12;             // xmm2
  float v13;              // xmm1_4
  float v14;              // xmm1_4
  __m128 v15;             // xmm1
  __m128 v16;             // xmm0
  __m128 v17;             // xmm0

  v4 = (__m128)a4;
  v6 = 0.0;
  v7 = -1.0;
  v8.i32[0] = 0;
    while (2) {
      v9 = a1;
        for (i = 1; i != 4; ++i) {
          v11 = a2[i - 1];
          v12 = (__m128)LODWORD(v9->start[0]);
          v12.f32[0] = (float)(v12.f32[0] - v11) * v7;
          v13 = (float)(v9->end[0] - v11) * v7;
            if (v12.f32[0] <= 0.0) {
                if (v13 > 0.0) {
                  v15 = v12;
                  v15.f32[0] = (float)(v12.f32[0] * v9->invDelta[0]) * v7;
                  if (v6 >= v15.f32[0])
                    return 1;
                  v16 = v15;
                  v16.f32[0] = v15.f32[0] - v4.f32[0];
                  v17 = _mm_cmpge_ss(v16, v8);
                  v4 = _mm_or_ps(_mm_andnot_ps(v17, v15), _mm_and_ps(v4, v17));
                }
            }
            else {
              if (v13 > 0.0)
                return 1;
              v14 = (float)(v12.f32[0] * v9->invDelta[0]) * v7;
              if (v14 >= v4.f32[0])
                return 1;
              if ((float)(v6 - v14) < 0.0)
                v6 = (float)(v12.f32[0] * v9->invDelta[0]) * v7;
            }
          v9 = (const TraceExtents *)((char *)v9 + 4);
        }
        if (v7 != 1.0) {
          a2 = a3;
          v7 = 1.0;
          continue;
        }
      break;
    }
  return 0;
}

int marker_cm_tracebox;
