float const (*identityMatrix44)[4]
{
  UNIMPLEMENTED();
}

void __cdecl FastSinCosDouble(double, double *, double *)
{
  UNIMPLEMENTED();
}

float __cdecl Vec4LengthSq(float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl LocalMatrixTransformVectorQuatTrans(
    float const *const in, struct DObjAnimMat_s const *mat, float *const out)
{
  UNIMPLEMENTED();
}

int __cdecl irand(int min, int max)
{
  holdrand = 214013 * holdrand + 2531011;
  return ((int)((a2 - a1) * ((unsigned int)holdrand >> 17)) >> 15) + a1;
}

float __cdecl flrand(float min, float max)
{
  holdrand = 214013 * holdrand + 2531011;
  return (float)(a1 + (float)((float)((float)((unsigned int)holdrand >> 17) *
                                      (float)(a2 - a1)) *
                              0.000030517578));
}

void __cdecl Rand_Init(int seed)
{
  int result; // eax

  result = a1;
  holdrand = a1;
  return result;
}

void __cdecl AxisClear(float (*const)[3])
{
  UNIMPLEMENTED();
}

void __cdecl ExtendBounds(float *const, float *const, float const *const)
{
  UNIMPLEMENTED();
}

float const __cdecl AngleNormalize180Accurate(float angle)
{
  float v1; // xmm0_4

  v1 = a1;
    if (a1 <= -180.0) {
      do
        v1 = v1 + 360.0;
      while (v1 <= -180.0);
      return v1;
    }
  if (a1 <= 180.0)
    return v1;
  do
    v1 = v1 - 360.0;
  while (v1 > 180.0);
  return v1;
}

float const __cdecl AngleNormalize360Accurate(float angle)
{
  float v1; // xmm0_4

  v1 = a1;
    if (a1 < 0.0) {
      do
        v1 = v1 + 360.0;
      while (v1 < 0.0);
      return v1;
    }
    else {
        if (a1 >= 360.0) {
          do
            v1 = v1 - 360.0;
          while (v1 >= 360.0);
        }
      return v1;
    }
}

float const __cdecl AngleNormalize360(float angle)
{
  return (float)((float)(unsigned __int16)(int)(float)(182.04445 * a1) *
                 0.0054931641);
}

float const __cdecl AngleSubtract(float a1, float a2)
{
  float i; // xmm0_4

  for (i = a1 - a2; i > 180.0; i = i - 360.0)
    ;
  for (; i < -180.0; i = i + 360.0)
    ;
  return i;
}

float const __cdecl LerpAngle(float from, float to, float frac)
{
  float v3; // xmm2_4
  float v4; // xmm0_4

  v3 = a2;
  v4 = a2 - a1;
    if ((float)(a2 - a1) > 180.0) {
      v3 = a2 - 360.0;
      v4 = (float)(a2 - 360.0) - a1;
    }
  if (v4 < -180.0)
    v4 = (float)(v3 + 360.0) - a1;
  return (float)(a1 + (float)(a3 * v4));
}

float const __cdecl AngleMod(float a)
{
  return (float)((float)(unsigned __int16)(int)(float)(182.04445 * a1) *
                 0.0054931641);
}

unsigned int const __cdecl ColorBytes4(float, float, float, float)
{
  UNIMPLEMENTED();
}

unsigned int const __cdecl ColorBytes3(float, float, float)
{
  UNIMPLEMENTED();
}

float __cdecl QuatEigenTrace(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl QuatToAxis(float const * const quat, float  axis)[3])
{
  UNIMPLEMENTED();
}

void __cdecl QuatInverse(float const *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl QuatMultiply(float const *in1, float const *in2, float *out)
{
  const float *result; // eax

  result = a1;
  *a3 = (float)((float)((float)(*a1 * a2[3]) + (float)(a1[3] * *a2)) +
                (float)(a1[2] * a2[1])) -
        (float)(a1[1] * a2[2]);
  a3[1] = (float)((float)((float)(a1[1] * a2[3]) - (float)(a1[2] * *a2)) +
                  (float)(a1[3] * a2[1])) +
          (float)(*a1 * a2[2]);
  a3[2] = (float)((float)((float)(a1[2] * a2[3]) + (float)(a1[1] * *a2)) -
                  (float)(*a1 * a2[1])) +
          (float)(a1[3] * a2[2]);
  a3[3] = (float)((float)((float)(a1[3] * a2[3]) - (float)(*a1 * *a2)) -
                  (float)(a1[1] * a2[1])) -
          (float)(a1[2] * a2[2]);
  return result;
}

void __cdecl MatrixTransformVector43Equals(float *, float const *)
{
  UNIMPLEMENTED();
}

void __cdecl MatrixTransformVector43(float const *const,
                                     float const (*const)[3], float *const)
{
  UNIMPLEMENTED();
}

void __cdecl MatrixTransposeTransformVector(float const *const,
                                            float const (*const)[3],
                                            float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec3RotateTranspose(float const *const, float const (*const)[3],
                                 float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec3Rotate(float const *const, float const (*const)[3],
                        float *const)
{
  UNIMPLEMENTED();
}

float __cdecl Vec3Max(float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec3UnpackNormalized(unsigned int, float *const)
{
  UNIMPLEMENTED();
}

short const __cdecl ClampShort(int)
{
  UNIMPLEMENTED();
}

signed char const __cdecl ClampChar(int i)
{
  if (a1 < -128)
    return -128;
  if (a1 > 127)
    return 127;
  return (char)a1;
}

int const __cdecl Q_log2(int)
{
  UNIMPLEMENTED();
}

float __cdecl GraphGetValueFromFraction(int, float const (*)[2], float)
{
  UNIMPLEMENTED();
}

float __cdecl random(void)
{
  UNIMPLEMENTED();
}

void __cdecl ConvertMatToQuat(float const (*const)[3], float *const)
{
  UNIMPLEMENTED();
}

void __cdecl VectorRotateAngles(float const *const, float const *const,
                                float *const)
{
  UNIMPLEMENTED();
}

float const __cdecl ColorNormalize(float const *const in, float *const out)
{
  float v2; // xmm2_4

  v2 = fmaxf(a1[2], fmaxf(a1[1], *a1));
    if (v2 == 0.0) {
      a2[2] = 1.0;
      a2[1] = 1.0;
      *a2 = 1.0;
      return 0.0;
    }
    else {
      *a2 = *a1 * (float)(1.0 / v2);
      a2[1] = (float)(1.0 / v2) * a1[1];
      a2[2] = (float)(1.0 / v2) * a1[2];
      return v2;
    }
}

int __cdecl BoxDistSqrdExceeds(float const *const absmin,
                               float const *const absmax,
                               float const *const org, float fogOpaqueDistSqrd)
{
  float v4;     // xmm3_4
  float v5;     // xmm2_4
  float v6;     // xmm1_4
  float v7;     // xmm3_4
  int i;        // edx
  float v9;     // xmm2_4
  float v11[3]; // [esp+8h] [ebp-20h] BYREF
  float v12[5]; // [esp+14h] [ebp-14h] BYREF

  v4 = *a3;
  v12[0] = *a1 - *a3;
  v5 = a3[1];
  v12[1] = a1[1] - v5;
  v6 = a3[2];
  v12[2] = a1[2] - v6;
  v11[0] = *a2 - v4;
  v11[1] = a2[1] - v5;
  v11[2] = a2[2] - v6;
  v7 = 0.0;
    for (i = 1; i != 4; ++i) {
      v9 = v11[i - 1];
      if ((float)(v12[i - 1] * v9) > 0.0)
        v7 = v7 + fminf(v9 * v9, v12[i - 1] * v12[i - 1]);
    }
  return v7 > a4;
}

void __cdecl ProjectPointOnPlane(float const *const p,
                                 float const *const normal, float *const dst)
{
  const float *result; // eax
  float v4;            // xmm1_4

  result = a2;
  v4 = -(float)((float)((float)(*a2 * *a1) + (float)(a2[1] * a1[1])) +
                (float)(a2[2] * a1[2]));
  *a3 = *a1 + (float)(*a2 * v4);
  a3[1] = (float)(v4 * a2[1]) + a1[1];
  a3[2] = (float)(v4 * a2[2]) + a1[2];
  return result;
}

void __cdecl ShrinkBoundsToHeight(float *const mins, float *const maxs)
{
  float *result; // eax
  float v3;      // xmm0_4
  float v4;      // xmm3_4
  float v5;      // xmm2_4
  float v6;      // xmm0_4

  result = a1;
  v3 = *a2 - *a1;
  v4 = a2[1] - a1[1];
  v5 = a2[2] - a1[2];
    if (v3 > v5) {
      v6 = (float)(v3 - v5) * 0.5;
      *a1 = v6 + *a1;
      *a2 = *a2 - v6;
    }
    if (v4 > v5) {
      a1[1] = (float)((float)(v4 - v5) * 0.5) + a1[1];
      a2[1] = a2[1] - (float)((float)(v4 - v5) * 0.5);
    }
  return result;
}

float const __cdecl AngleNormalize180(float angle)
{
  float v1; // xmm0_4

  v1 = (float)(unsigned __int16)(int)(float)(182.04445 * a1) * 0.0054931641;
  if (v1 > 180.0)
    return (float)(v1 - 360.0);
  return v1;
}

void __cdecl AnglesSubtract(float const *const v1, float const *const v2,
                            float *const v3)
{
  float i;       // xmm0_4
  float j;       // xmm0_4
  float *result; // eax
  float k;       // xmm0_4

  for (i = *a1 - *a2; i > 180.0; i = i - 360.0)
    ;
  for (; i < -180.0; i = i + 360.0)
    ;
  *a3 = i;
  for (j = a1[1] - a2[1]; j > 180.0; j = j - 360.0)
    ;
  for (; j < -180.0; j = j + 360.0)
    ;
  a3[1] = j;
  result = a3 + 2;
  for (k = a1[2] - a2[2]; k > 180.0; k = k - 360.0)
    ;
  for (; k < -180.0; k = k + 360.0)
    ;
  *result = k;
  return result;
}

float const __cdecl NormalizeColor(float const *const, float *const)
{
  UNIMPLEMENTED();
}

float __cdecl QuatRatioEigenTrace(float *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl MatrixTransposeTransformVector43(float const *const,
                                              float const (*const)[3],
                                              float *const)
{
  UNIMPLEMENTED();
}

float const __cdecl Vec2NormalizeTo(float const *const, float *const)
{
  UNIMPLEMENTED();
}

float const __cdecl Vec4Normalize(float *const)
{
  UNIMPLEMENTED();
}

float const __cdecl Vec2DistanceSq(float const *const p1, float const *const p2)
{
  return (float)((float)((float)(*a2 - *a1) * (float)(*a2 - *a1)) +
                 (float)((float)(a2[1] - a1[1]) * (float)(a2[1] - a1[1])));
}

void __cdecl ByteToDir(int b, float *const dir)
{
  int result; // eax
  int *v3;    // edx

    if (a1 <= 0xA1) {
      v3 = &bytedirs[3 * a1];
      *(_DWORD *)a2 = *v3;
      *((_DWORD *)a2 + 1) = v3[1];
      result = v3[2];
      *((_DWORD *)a2 + 2) = result;
    }
    else {
      result = 0;
      *a2 = 0.0;
      a2[1] = 0.0;
      a2[2] = 0.0;
    }
  return result;
}

unsigned char const __cdecl DirToByte(float const *const dir)
{
  const float *result; // eax
  float v2;            // xmm3_4
  float v3;            // xmm2_4
  float v4;            // xmm5_4
  int v5;              // ecx
  int v6;              // edx

  result = a1;
    if (a1) {
      v4 = 0.0;
      LOBYTE(result) = 0;
      v5 = 0;
      v6 = 0;
        do {
          v3 = a1[2];
          v2 = a1[1];
            if ((float)((float)((float)(*a1 * *(float *)&bytedirs[v6]) +
                                (float)(v2 * *(float *)&dword_3083C4[v6])) +
                        (float)(v3 * *(float *)&dword_3083C8[v6])) > v4) {
              v4 = (float)((float)(*a1 * *(float *)&bytedirs[v6]) +
                           (float)(v2 * *(float *)&dword_3083C4[v6])) +
                   (float)(v3 * *(float *)&dword_3083C8[v6]);
              LOBYTE(result) = v5;
            }
          ++v5;
          v6 += 3;
        }
      while (v5 != 162);
      return (const float *)(unsigned __int8)result;
    }
  return result;
}

void __cdecl UniformPointsOnSphere(int, void *, int)
{
  UNIMPLEMENTED();
}

void __cdecl UniformPointsOnHemisphere(int, void *, int)
{
  UNIMPLEMENTED();
}

void __cdecl UniformPointsInCircle(int, void *, int)
{
  UNIMPLEMENTED();
}

float __cdecl crandom()
{
  int v0; // eax

  v0 = rand();
  return (float)((float)((float)((float)v0 * 4.6566129e-10) +
                         (float)((float)v0 * 4.6566129e-10)) -
                 1.0);
}

void __cdecl VectorRotateAnglesAroundPoint(float const *const,
                                           float const *const,
                                           float const *const, float *const)
{
  UNIMPLEMENTED();
}

int __cdecl WindingContainsCoplanarPoint(float const (*const)[3], int,
                                         float const *const, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl ExpandBoundsToWidth(float *const mins, float *const maxs)
{
  float *result; // eax
  __m128 v3;     // xmm1
  __m128 v4;     // xmm0
  float v5;      // xmm3_4
  __m128 v6;     // xmm2
  __m128 v7;     // rt1
  __m128 v8;     // xmm2
  float v9;      // xmm2_4
  float v10;     // xmm1_4

  result = a1;
  v3 = (__m128) * (unsigned int *)a2;
  v3.f32[0] = v3.f32[0] - *a1;
  v4 = (__m128) * ((unsigned int *)a2 + 1);
  v4.f32[0] = v4.f32[0] - a1[1];
  v5 = a2[2] - a1[2];
  v6 = v3;
  v6.f32[0] = v3.f32[0] - v4.f32[0];
  v7.i32[0] = 0;
  v8 = _mm_cmpge_ss(v6, v7);
  LODWORD(v9) = _mm_andnot_ps(v8, v4).u32[0] | v3.i32[0] & v8.i32[0];
    if (v9 > v5) {
      v10 = (float)(v9 - v5) * 0.5;
      a1[2] = a1[2] - v10;
      a2[2] = v10 + a2[2];
    }
  return result;
}

float const __cdecl AngleDelta(float angle1, float angle2)
{
  float v2; // xmm0_4

  v2 = (float)(unsigned __int16)(int)(float)((float)(a1 - a2) * 182.04445) *
       0.0054931641;
  if (v2 > 180.0)
    return (float)(v2 - 360.0);
  return v2;
}

float __cdecl RotationToYaw(float const *const rot)
{
  float v1;       // xmm2_4
  float v2;       // xmm4_4
  float v3;       // xmm1_4
  long double v6; // [esp+0h] [ebp-38h]
  long double v7; // [esp+10h] [ebp-28h]

  v1 = *a1;
  v2 = a1[1];
  v3 = 2.0 / (float)((float)(v2 * v2) + (float)(v1 * v1));
  *((double *)&v6 + 1) = (float)(1.0 - (float)((float)(v1 * v1) * v3));
  *(double *)&v6 = (float)(v3 * (float)(*a1 * v2));
  return (float)((double)atan2(v6, v7) * 57.29577951308232);
}

float __cdecl AngleEigenTrace(float)
{
  UNIMPLEMENTED();
}

void __cdecl GetPerpendicularViewVector(float const *const, float const *const,
                                        float const *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl vectosignedangles(float const *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl vectoangles(float const *const vec, float *const angles)
{
  float v2;       // xmm2_4
  float v3;       // xmm3_4
  float v4;       // xmm0_4
  long double v5; // [esp+0h] [ebp-58h]
  long double v6; // [esp+0h] [ebp-58h]
  long double v7; // [esp+10h] [ebp-48h]
  long double v8; // [esp+10h] [ebp-48h]
  float v9;       // [esp+40h] [ebp-18h]

  v2 = a1[1];
    if (v2 == 0.0 && *a1 == 0.0) {
      v3 = 0.0;
      if (a1[2] <= 0.0)
        v4 = 90.0;
      else
        v4 = 270.0;
    LABEL_5:
      *a2 = v4;
      a2[1] = v3;
      a2[2] = 0.0;
      return;
    }
  *((double *)&v5 + 1) = *a1;
  *(double *)&v5 = v2;
  v9 = *a1;
  *((double *)&v8 + 1) = atan2(v5, v7);
  v3 = *((double *)&v8 + 1) * 180.0 / 3.141592653589793;
  if (v3 < 0.0)
    v3 = v3 + 360.0;
  *((double *)&v6 + 1) = fsqrt((float)(v9 * v9) + (float)(v2 * v2));
  *(double *)&v6 = a1[2];
  v4 = (double)atan2(v6, v8) * -180.0 / 3.141592653589793;
  if (v4 >= 0.0)
    goto LABEL_5;
  *a2 = v4 + 360.0;
  a2[1] = v3;
  a2[2] = 0.0;
}

float const __cdecl vectosignedpitch(float const *const)
{
  UNIMPLEMENTED();
}

float const __cdecl vectopitch(float const *const vec)
{
  float v1;       // xmm1_4
  float v2;       // xmm0_4
  long double v4; // [esp+0h] [ebp-38h]
  long double v5; // [esp+10h] [ebp-28h]

  v1 = a1[1];
    if (v1 == 0.0 && *a1 == 0.0) {
      if (a1[2] <= 0.0)
        return 90.0;
      else
        return 270.0;
    }
  *((double *)&v4 + 1) = fsqrt((float)(*a1 * *a1) + (float)(v1 * v1));
  *(double *)&v4 = a1[2];
  v2 = (double)atan2(v4, v5) * -180.0 / 3.141592653589793;
  if (v2 >= 0.0)
    return v2;
  return (float)(v2 + 360.0);
}

float const __cdecl vectosignedyaw(float const *const vec)
{
  float v1;       // xmm1_4
  long double v4; // [esp+0h] [ebp-28h]
  long double v5; // [esp+10h] [ebp-18h]

  v1 = a1[1];
  if (v1 == 0.0 && *a1 == 0.0)
    return 0.0;
  *((double *)&v4 + 1) = *a1;
  *(double *)&v4 = v1;
  return (float)((double)atan2(v4, v5) * 180.0 / 3.141592653589793);
}

float const __cdecl vectoyaw(float const *const vec)
{
  float v1;       // xmm1_4
  float v2;       // xmm0_4
  long double v4; // [esp+0h] [ebp-38h]
  long double v5; // [esp+10h] [ebp-28h]

  v1 = a1[1];
  if (v1 == 0.0 && *a1 == 0.0)
    return 0.0;
  *((double *)&v4 + 1) = *a1;
  *(double *)&v4 = v1;
  v2 = (double)atan2(v4, v5) * 180.0 / 3.141592653589793;
  if (v2 < 0.0)
    return (float)(v2 + 360.0);
  return v2;
}

float const __cdecl Vec2Distance(float const *const, float const *const)
{
  UNIMPLEMENTED();
}

float const __cdecl Q_acos(float c)
{
  long double result; // fst7
  float v2;           // [esp+1Ch] [ebp-Ch]

  result = acosf(a1);
  v2 = result;
  if (v2 > 3.141592653589793 || v2 < -3.141592653589793)
    return 3.1415927;
  return result;
}

void __cdecl GaussianRandom(float *f0, float *f1)
{
  int v2;         // eax
  int v3;         // eax
  float v4;       // xmm2_4
  float v5;       // xmm1_4
  float v6;       // xmm1_4
  float v7;       // xmm1_4
  float *result;  // eax
  long double v9; // [esp+0h] [ebp-58h]
  float v10;      // [esp+20h] [ebp-38h]
  float v11;      // [esp+30h] [ebp-28h]

    do {
      v2 = rand();
      v10 = (float)((float)((float)v2 * 4.6566129e-10) +
                    (float)((float)v2 * 4.6566129e-10)) -
            1.0;
      v3 = rand();
      v4 = (float)((float)((float)v3 * 4.6566129e-10) +
                   (float)((float)v3 * 4.6566129e-10)) -
           1.0;
      v5 = (float)(v10 * v10) + (float)(v4 * v4);
    }
  while (v5 > 1.0);
  *(double *)&v9 = v5;
  v11 = (float)((float)((float)v3 * 4.6566129e-10) +
                (float)((float)v3 * 4.6566129e-10)) -
        1.0;
  v6 = (double)log(v9) * -2.0 / v5;
  v7 = fsqrt(v6);
  *a1 = v10 * v7;
  result = a2;
  *a2 = v7 * v11;
  return result;
}

void __cdecl MatrixTransformVectorQuatTrans(float const *const,
                                            struct DObjAnimMat_s const *,
                                            float *const)
{
  const DObjAnimMat_s *result; // eax
  float v4;                    // xmm6_4
  float v5;                    // xmm7_4
  float v6;                    // xmm3_4
  float v7;                    // xmm4_4
  float v8;                    // xmm2_4
  float v9;                    // xmm1_4
  float v10;                   // xmm5_4
  float v11;                   // xmm0_4
  float v12;                   // xmm6_4
  float v13;                   // xmm7_4
  float v14;                   // xmm3_4
  float v15;                   // [esp+0h] [ebp-10h]
  float v16;                   // [esp+4h] [ebp-Ch]
  float v17;                   // [esp+8h] [ebp-8h]
  float v18;                   // [esp+Ch] [ebp-4h]

  result = a2;
  v4 = *(float *)&a2->transWeight * a2->quat[0];
  v5 = *(float *)&a2->transWeight * a2->quat[1];
  v6 = *(float *)&a2->transWeight * a2->quat[2];
  v15 = v4 * a2->quat[0];
  v7 = a2->quat[1];
  v8 = v4 * v7;
  v9 = a2->quat[2];
  v10 = v4 * v9;
  v11 = a2->quat[3];
  v12 = v4 * v11;
  v16 = v7 * v5;
  v17 = v5 * v9;
  v18 = v5 * v11;
  v13 = v6 * v9;
  v14 = v6 * v11;
  *a3 = (float)((float)((float)((float)(1.0 - (float)(v16 + v13)) * *a1) +
                        (float)((float)(v8 - v14) * a1[1])) +
                (float)((float)(v18 + v10) * a1[2])) +
        a2->trans[0];
  a3[1] = (float)((float)((float)((float)(v8 + v14) * *a1) +
                          (float)((float)(1.0 - (float)(v13 + v15)) * a1[1])) +
                  (float)((float)(v17 - v12) * a1[2])) +
          a2->trans[1];
  a3[2] = (float)((float)((float)((float)(v10 - v18) * *a1) +
                          (float)((float)(v12 + v17) * a1[1])) +
                  (float)((float)(1.0 - (float)(v15 + v16)) * a1[2])) +
          a2->trans[2];
  return result;
}

void __cdecl VectorPolar(float *const, float, float, float)
{
  UNIMPLEMENTED();
}

int __cdecl IsPosInsideArc(float const *const, float, float const *const, float,
                           float, float, float)
{
  UNIMPLEMENTED();
}

float const __cdecl RadiusFromBounds2D(float const *const mins,
                                       float const *const maxs)
{
  int i;    // edx
  float v4; // [esp+10h] [ebp-10h] BYREF
  float v5; // [esp+14h] [ebp-Ch]

  for (i = 1; i != 3; ++i)
    *(&v4 + i - 1) = fmaxf(fabs(a1[i - 1]), fabs(a2[i - 1]));
  return fsqrt((float)(v4 * v4) + (float)(v5 * v5));
}

float const __cdecl RadiusFromBounds(float const *const mins,
                                     float const *const maxs)
{
  int i;    // edx
  float v4; // [esp+8h] [ebp-14h] BYREF
  float v5; // [esp+Ch] [ebp-10h]
  float v6; // [esp+10h] [ebp-Ch]

  for (i = 1; i != 4; ++i)
    *(&v4 + i - 1) = fmaxf(fabs(a1[i - 1]), fabs(a2[i - 1]));
  return fsqrt((float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6));
}

void __cdecl MatrixRotationZ(float (*const)[3], float)
{
  UNIMPLEMENTED();
}

void __cdecl MatrixRotationY(float (*const)[3], float)
{
  UNIMPLEMENTED();
}

void __cdecl MatrixRotationX(float (*const)[3], float)
{
  UNIMPLEMENTED();
}

void __cdecl AngleAxisToQuat(float angle, float const *const axis,
                             float *const quat)
{
  float v3; // xmm0_4
  float v4; // [esp+1Ch] [ebp-2Ch]

  v3 = a1 * 0.008726646259971648;
  v4 = sinf(v3);
  a3[3] = cosf(v3);
  *a3 = v4 * *a2;
  a3[1] = v4 * a2[1];
  a3[2] = v4 * a2[2];
}

void __cdecl RollToQuat(float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl YawToQuat(float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl PitchToQuat(float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl VectorAngleMultiply(float *const vec, float angle)
{
  float v2; // xmm0_4
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // [esp+1Ch] [ebp-1Ch]
  float v6; // [esp+28h] [ebp-10h]

  v2 = a2 * 0.0174532925199433;
  v6 = sinf(v2);
  v5 = cosf(v2);
  v3 = *a1;
  v4 = a1[1];
  a1[1] = (float)(v5 * v4) + (float)(v6 * *a1);
  *a1 = (float)(v3 * v5) - (float)(v4 * v6);
}

void __cdecl YawVectors(float yaw, float *const forward, float *const right)
{
  float v3;       // xmm0_4
  long double v4; // fst7
  float v5;       // [esp+1Ch] [ebp-1Ch]
  float v6;       // [esp+2Ch] [ebp-Ch]

  v3 = a1 * 0.0174532925199433;
  v6 = sinf(v3);
  v4 = cosf(v3);
    if (a2) {
      *a2 = v4;
      *(_QWORD *)(a2 + 1) = LODWORD(v6);
    }
    if (a3) {
      *a3 = v6;
      v5 = v4;
      *((_DWORD *)a3 + 1) = LODWORD(v5) ^ 0x80000000;
      a3[2] = 0.0;
    }
}

void __cdecl RotatePointAroundVector(float *const dst, float const *const dir,
                                     float const *const point, float degrees)
{
  float v4;        // xmm6_4
  float v5;        // xmm7_4
  int v6;          // edx
  unsigned int v7; // edx
  float v8;        // xmm0_4
  float v9;        // xmm3_4
  float v10;       // xmm5_4
  float v11;       // xmm4_4
  float v12;       // xmm1_4
  float v13;       // xmm0_4
  float *result;   // eax
  float v16;       // [esp+14h] [ebp-F4h]
  float v17;       // [esp+1Ch] [ebp-ECh]
  float v18[9];    // [esp+24h] [ebp-E4h] BYREF
  float v19[9];    // [esp+48h] [ebp-C0h] BYREF
  float v20[9];    // [esp+6Ch] [ebp-9Ch] BYREF
  float v21;       // [esp+90h] [ebp-78h] BYREF
  float v22;       // [esp+94h] [ebp-74h]
  float v23;       // [esp+98h] [ebp-70h]
  float v24;       // [esp+9Ch] [ebp-6Ch]
  float v25;       // [esp+A0h] [ebp-68h]
  float v26;       // [esp+A4h] [ebp-64h]
  float v27;       // [esp+A8h] [ebp-60h]
  float v28;       // [esp+ACh] [ebp-5Ch]
  float v29;       // [esp+B0h] [ebp-58h]
  float v30[9];    // [esp+B4h] [ebp-54h] BYREF
  float v31[3];    // [esp+D8h] [ebp-30h]
  float v32;       // [esp+E4h] [ebp-24h]
  float v33;       // [esp+E8h] [ebp-20h]
  float v34;       // [esp+ECh] [ebp-1Ch]

  v4 = *a2;
  v17 = a2[1];
  v5 = a2[2];
  v31[0] = v4 * v4;
  v31[1] = v17 * v17;
  v31[2] = v5 * v5;
  v6 = 2;
  if (v31[(float)(v4 * v4) > (float)(v17 * v17)] <= (float)(v5 * v5))
    v6 = (float)(v4 * v4) > (float)(v17 * v17);
  v7 = 4 * v6;
  v8 = -a2[v7 / 4];
  v32 = v4 * v8;
  v33 = v8 * a2[1];
  v34 = v8 * a2[2];
  *(float *)((char *)&v32 + v7) = *(float *)((char *)&v32 + v7) + 1.0;
  v9 = v32;
  v10 = v33;
  v11 = v34;
  v12 = fsqrt((float)((float)(v9 * v9) + (float)(v10 * v10)) +
              (float)(v11 * v11));
    if (v12 != 0.0) {
      v9 = v32 * (float)(1.0 / v12);
      v32 = v9;
      v33 = (float)(1.0 / v12) * v33;
      v34 = (float)(1.0 / v12) * v34;
      v10 = (float)(1.0 / v12) * v10;
      v11 = (float)(1.0 / v12) * v11;
    }
  v21 = v9;
  v24 = v10;
  v27 = v11;
  v22 = (float)(v5 * v10) - (float)(v17 * v11);
  v25 = (float)(v4 * v11) - (float)(v5 * v9);
  v28 = (float)(v17 * v9) - (float)(v4 * v10);
  v23 = v4;
  v26 = v17;
  v29 = v5;
  v18[0] = v9;
  v18[4] = v25;
  v18[8] = v5;
  v18[1] = v10;
  v18[2] = v11;
  v18[3] = v22;
  v18[5] = v28;
  v18[6] = v4;
  v18[7] = v17;
  memset(v30, 0, sizeof(v30));
  v30[8] = 1.0;
  v30[4] = 1.0;
  v30[0] = 1.0;
  v13 = a4 * 0.0174532925199433;
  v16 = sinf(v13);
  v30[1] = v16;
  v30[0] = cosf(v13);
  v30[3] = -v16;
  v30[4] = v30[0];
  MatrixMultiply(&v21, v30, v19);
  MatrixMultiply(v19, v18, v20);
  result = v20;
    do {
      *a1 = (float)((float)(*result * *a3) + (float)(result[1] * a3[1])) +
            (float)(result[2] * a3[2]);
      result += 3;
      ++a1;
    }
  while (&v21 != result);
  return result;
}

unsigned int __cdecl Vec3PackNormalized(float const *const)
{
  UNIMPLEMENTED();
}

float __cdecl DiffTrack(float tgt, float cur, float rate, float deltaTime)
{
  float v4; // xmm2_4
  float v5; // xmm3_4

  v4 = (float)((float)(a1 - a2) * a3) * a4;
  v5 = fabs(a1 - a2);
  if (v5 > 0.001 && fabs(v4) <= v5)
    return (float)(a2 + v4);
  return a1;
}

float __cdecl LinearTrack(float, float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl PointOnHemisphereFromUniformDeviates(float, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl PointOnSphereFromUniformDeviates(float, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl PointInCircleFromUniformDeviates(float, float, float *const)
{
  UNIMPLEMENTED();
}

float __cdecl PitchForYawOnNormal(float fYaw, float const *const normal)
{
  float v2;        // xmm0_4
  float v3;        // xmm3_4
  float v4;        // xmm0_4
  float v5;        // xmm2_4
  float v6;        // xmm3_4
  float v7;        // xmm5_4
  float v8;        // xmm0_4
  long double v10; // [esp+0h] [ebp-48h]
  long double v11; // [esp+10h] [ebp-38h]
  float v12;       // [esp+38h] [ebp-10h]

  v2 = a1 * 0.0174532925199433;
  v12 = sinf(v2);
  *((float *)&v11 + 3) = cosf(v2);
  v3 = a2[1];
  v4 = -(
      float)((float)((float)(*((float *)&v11 + 3) * *a2) + (float)(v12 * v3)) +
             (float)(a2[2] * 0.0));
  v5 = (float)(*a2 * v4) + *((float *)&v11 + 3);
  v6 = (float)(v3 * v4) + v12;
  v7 = (float)(a2[2] * v4) + 0.0;
    if (v6 == 0.0 && v5 == 0.0) {
      if (v7 <= 0.0)
        return 90.0;
      else
        return 270.0;
    }
  *((double *)&v10 + 1) = fsqrt((float)(v5 * v5) + (float)(v6 * v6));
  *(double *)&v10 = v7;
  v8 = (double)atan2(v10, v11) * -180.0 / 3.141592653589793;
  if (v8 >= 0.0)
    return v8;
  return (float)(v8 + 360.0);
}

void __cdecl RotateAroundDirection(float (*const)[3], float)
{
  UNIMPLEMENTED();
}

float __cdecl DiffTrackAngle(float tgt, float cur, float rate, float deltaTime)
{
  float v4; // xmm1_4
  float i;  // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  v4 = a1;
  for (i = a1 - a2; (float)(v4 - a2) > 180.0; i = v4 - a2)
    v4 = v4 - 360.0;
    if (i < -180.0) {
        do {
          v4 = v4 + 360.0;
          i = v4 - a2;
        }
      while ((float)(v4 - a2) < -180.0);
    }
  v6 = (float)(i * a3) * a4;
  v7 = fabs(i);
  if (v7 > 0.001 && fabs(v6) <= v7)
    v8 = a2 + v6;
  else
    v8 = v4;
  v9 = (float)(unsigned __int16)(int)(float)(v8 * 182.04445) * 0.0054931641;
  if (v9 > 180.0)
    return (float)(v9 - 360.0);
  return v9;
}

float __cdecl LinearTrackAngle(float, float, float, float)
{
  UNIMPLEMENTED();
}

float (*bytedirs)[3]
{
  UNIMPLEMENTED();
}

int marker_com_math;

randomf()
{
  UNIMPLEMENTED();
}
