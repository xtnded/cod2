float __cdecl FxCurve_Interpolate1d(float const *, float) { UNIMPLEMENTED(); }

void __cdecl FxCurveIterator_Release(struct FxCurveIterator *) {
  UNIMPLEMENTED();
}

void __cdecl FxCurveIterator_Create(struct FxCurveIterator *createe,
                                    struct FxCurve const *master) {
  const FxCurve *result; // eax

  result = a2;
  a1->master = (int32_t)a2;
  a1->currentKeyIndex = 0;
  return result;
}

float __cdecl FxCurve_Integrate(struct FxCurve const *curve,
                                float normDuration) {
  float *p_keys;           // ecx
  uint32_t v3;             // eax
  int v4;                  // esi
  float *v5;               // edx
  float v6;                // xmm1_4
  float *p_dimensionCount; // ebx
  float v8;                // xmm5_4
  int32_t *v10;            // eax

  p_keys = (float *)&a1->keys;
  v3 = a1->dimensionCount + 1;
  v4 = 4 * v3;
  v5 = (float *)(&a1->keys + v3);
  v6 = *v5;
  if (a2 > *v5) {
    v10 = &a1->keys + v3;
    v8 = 0.0;
    while (1) {
      p_dimensionCount = v5 + 1;
      v8 = v8 + (float)((float)((float)(v5[1] + p_keys[1]) * 0.5) *
                        (float)(v6 - *p_keys));
      v5 = (float *)((char *)v5 + v4);
      v6 = *v5;
      if (a2 <= *v5)
        break;
      p_keys = (float *)v10;
      v10 = (int32_t *)v5;
    }
    p_keys = (float *)v10;
  } else {
    p_dimensionCount = (float *)&a1[1].dimensionCount;
    v8 = 0.0;
  }
  return (
      float)(v8 +
             (float)((float)(a2 - *p_keys) *
                     (float)((float)(*p_dimensionCount +
                                     (float)((float)((float)((float)(p_keys[3] -
                                                                     *p_dimensionCount) *
                                                             (float)(a2 -
                                                                     *p_keys)) /
                                                     (float)(p_keys[2] -
                                                             *p_keys)) +
                                             *p_dimensionCount)) *
                             0.5)));
}

int marker_FxCurve;
float __cdecl FxIntegrateLineSegment(float, float, float, float) {
  UNIMPLEMENTED();
}
