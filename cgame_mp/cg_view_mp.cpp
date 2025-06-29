float __cdecl atan(float)
{
  UNIMPLEMENTED();
}

float __cdecl atan2(float, float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_SetView(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateThirdPerson(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_GetViewFov()
{
  _DWORD *v0;                   // ebx
  int32_t ViewmodelWeaponIndex; // esi
  float *WeaponDef;             // edi
  float v3;                     // xmm2_4
  __m128 v4;                    // xmm5
  float v5;                     // xmm2_4
  __m128 v6;                    // xmm0
  __m128 v7;                    // xmm0
  float v9;                     // xmm1_4
  float v10;                    // xmm4_4
  float v11;                    // xmm1_4
  float v12;                    // xmm1_4
  float v13;                    // [esp+20h] [ebp-28h]

  v0 = cg;
  ViewmodelWeaponIndex = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg));
  WeaponDef = (float *)BG_GetWeaponDef(ViewmodelWeaponIndex);
    if (v0[38642] == 5) {
      v3 = 90.0;
      v4.i32[0] = 0;
    }
    else {
      v13 = *(float *)(cg_fov + 8);
      v3 = v13;
        if (BG_IsAimDownSightWeapon(ViewmodelWeaponIndex)) {
          v9 = *(float *)((char *)&loc_25CA0 + (_DWORD)v0);
            if (v9 == 1.0) {
              v3 = WeaponDef[154];
              v4.i32[0] = 0;
            }
            else {
              v4.i32[0] = 0;
                if (v9 != 0.0) {
                  v10 = v0[41253] ? WeaponDef[155] : WeaponDef[156];
                  v11 = v9 - (float)(1.0 - v10);
                    if (v11 > 0.0) {
                      v12 = v11 / v10;
                      if (v12 > 0.0)
                        v3 = v13 - (float)((float)(v13 - WeaponDef[154]) * v12);
                    }
                }
            }
        }
        else {
          v4.i32[0] = 0;
        }
    }
  if ((*(_DWORD *)((_BYTE *)&loc_25C64 + (_DWORD)cg) & 0x300) != 0)
    v3 = 55.0;
  v5 = v3 * *(float *)(cg_fovScale + 8);
  v6 = (__m128) * (unsigned int *)(cg_fovMin + 8);
  v6.f32[0] = v6.f32[0] - v5;
  v7 = _mm_cmplt_ss(v6, v4);
  return COERCE_FLOAT(
      _mm_andnot_ps(v7, (__m128) * (unsigned int *)(cg_fovMin + 8)).u32[0] |
      LODWORD(v5) & v7.i32[0]);
}

void __cdecl CG_FxRestart()
{
  Com_Printf("FX Restarting so off-line changes are loaded.\n");
  FX_FreeSystem();
  return FX_InitSystem(1);
}

void __cdecl CG_FxSetTestPosition()
{
  float *v0; // eax
  float *v1; // ebx
  float *v2; // ecx
  float *v3; // edx

  v0 = (float *)cg;
  v1 = (float *)((char *)cg + 180252);
  v2 = (float *)((char *)cg + 165256);
  v3 = (float *)((char *)&loc_28594 + (_DWORD)cg);
  *((float *)cg + 45063) =
      (float)(*(float *)((char *)&loc_28594 + (_DWORD)cg) * 100.0) +
      *((float *)cg + 41314);
  v1[1] = (float)(v3[1] * 100.0) + v2[1];
  v1[2] = (float)(100.0 * v3[2]) + v2[2];
  Com_Printf("\n\nFX Testing position set to: (%f, %f, %f)\n\n", v0[45063],
             v0[45064], v0[45065]);
}

void __cdecl updateTestFX(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_FxTest()
{
  UNIMPLEMENTED();
}

void __cdecl CG_InitView()
{
  UNIMPLEMENTED();
}

int __cdecl CG_DrawActiveFrame(int serverTime, enum DemoType demoType,
                               enum CubemapShot cubemapShot, int cubemapSize,
                               int renderScreen)
{
  UNIMPLEMENTED();
}

void __cdecl CG_StepOffset(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_StoreViewModelPosition(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalcCubemapViewValues(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ApplyViewAnimation(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_KickAngles(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalcFov(void)
{
  float v0;       // xmm1_4
  float v1;       // xmm0_4
  float v2;       // xmm0_4
  float *v3;      // ebx
  double v4;      // xmm0_8
  int result;     // eax
  long double v6; // [esp+0h] [ebp-58h]
  float v7;       // [esp+1Ch] [ebp-3Ch]
  float v8;       // [esp+30h] [ebp-28h]
  float v9;       // [esp+34h] [ebp-24h]
  float v10;      // [esp+44h] [ebp-14h]
  float v11;      // [esp+48h] [ebp-10h]
  float ViewFov;  // [esp+4Ch] [ebp-Ch]

  ViewFov = CG_GetViewFov();
  *(double *)&v6 = ViewFov * 0.0174532925199433 * 0.5;
  v0 = tan(v6);
  v9 = atanf((float)(v0 * 0.75) * *((float *)cgs + 6053));
  v1 = v9 * 57.29577951308232 + v9 * 57.29577951308232;
  v10 = v1;
  v8 = atanf(v0 * 0.75);
  v2 = v8 * 57.29577951308232 + v8 * 57.29577951308232;
  v11 = v2;
  v3 = (float *)cg;
    if (CG_PointContents((float *)cg + 41314, -1, 32)) {
      v4 = (float)((float)((float)*(int *)((char *)&loc_25BB0 + (_DWORD)v3) /
                           1000.0) *
                   0.40000001) *
           3.141592653589793;
      *(float *)&v4 = v4 + v4;
      v7 = sinf(*(float *)&v4);
      v10 = v10 + v7;
      v11 = v11 - v7;
    }
  v3[41312] = v10;
  *(float *)((char *)&loc_28584 + (_DWORD)v3) = v11;
  result = cg_fov;
  v3[43390] = v10 / *(float *)(cg_fov + 8);
  return result;
}

void __cdecl CG_CalcVrect(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_OffsetFirstPersonView(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_OffsetThirdPersonView(void)
{
  void *v0;             // esi
  __m128 v1;            // xmm0
  float v2;             // xmm1_4
  float *v3;            // ebx
  float *v4;            // edx
  float v5;             // xmm1_4
  double v6;            // xmm1_8
  float v7;             // xmm0_4
  float v8;             // xmm0_4
  long double v9;       // [esp+0h] [ebp-B8h]
  long double v10;      // [esp+10h] [ebp-A8h]
  float v11;            // [esp+34h] [ebp-84h]
  float v12;            // [esp+38h] [ebp-80h]
  float v13;            // [esp+3Ch] [ebp-7Ch]
  trace_t v14;          // [esp+40h] [ebp-78h] BYREF
  unsigned __int32 v15; // [esp+64h] [ebp-54h] BYREF
  float v16;            // [esp+68h] [ebp-50h]
  int v17;              // [esp+6Ch] [ebp-4Ch]
  __int64 __x;          // [esp+70h] [ebp-48h] BYREF
  float __x_8;          // [esp+78h] [ebp-40h]
  float __x_12;         // [esp+7Ch] [ebp-3Ch] BYREF
  float v21[3];         // [esp+88h] [ebp-30h] BYREF
  float v22;            // [esp+94h] [ebp-24h] BYREF
  float v23;            // [esp+98h] [ebp-20h]
  float v24;            // [esp+9Ch] [ebp-1Ch]

  v0 = cg;
  *((float *)cg + 41316) = *((float *)cg + 41316) + *((float *)cg + 38703);
  v15 = *((_DWORD *)v0 + 41330);
  v16 = *((float *)v0 + 41331);
  v17 = *((_DWORD *)v0 + 41332);
    if (*((int *)v0 + 38642) > 5) {
      v16 = (float)*(int *)((char *)&loc_25CF4 + (_DWORD)v0);
      *((float *)v0 + 41331) = (float)*(int *)((char *)&loc_25CF4 + (_DWORD)v0);
    }
  v1 = _mm_cmpge_ss((__m128)0x42340000u, (__m128)v15);
  v15 = _mm_andnot_ps(v1, (__m128)0x42340000u).u32[0] | v15 & v1.i32[0];
  AngleVectors((float *)&v15, &v22, 0, 0);
  v13 = (float)(v22 * 512.0) + *((float *)v0 + 41314);
  v12 = (float)(v23 * 512.0) + *(float *)((char *)&loc_2858C + (_DWORD)v0);
  v11 = (float)(512.0 * v24) + *((float *)v0 + 41316);
  LODWORD(__x) = *((_DWORD *)v0 + 41314);
  HIDWORD(__x) = *(_DWORD *)((char *)&loc_2858C + (_DWORD)v0);
  __x_8 = *((float *)v0 + 41316) + 8.0;
  *((float *)v0 + 41330) = 0.5 * *((float *)v0 + 41330);
  *((float *)v0 + 41331) =
      *((float *)v0 + 41331) - *(float *)(cg_thirdPersonAngle + 8);
  AngleVectors((float *)v0 + 41330, &v22, v21, &__x_12);
  v2 = -*(float *)(cg_thirdPersonRange + 8);
  *(float *)&__x = (float)(v2 * v22) + *(float *)&__x;
  *((float *)&__x + 1) = (float)(v2 * v23) + *((float *)&__x + 1);
  __x_8 = (float)(v2 * v24) + __x_8;
  CG_TraceCapsule(&v14, (float *)v0 + 41314,
                  (trace_t *)&CG_OffsetThirdPersonView(void)::mins,
                  &CG_OffsetThirdPersonView(void)::maxs, (float *)&__x,
                  *((_DWORD *)v0 + 38692), (const float *)0x811);
    if (v14.fraction != 1.0) {
      *(float *)&__x =
          *((float *)v0 + 41314) +
          (float)((float)(*(float *)&__x - *((float *)v0 + 41314)) *
                  v14.fraction);
      *((float *)&__x + 1) =
          *((float *)v0 + 41315) +
          (float)((float)(*((float *)&__x + 1) - *((float *)v0 + 41315)) *
                  v14.fraction);
      __x_8 = (float)((float)(1.0 - v14.fraction) * 32.0) +
              (float)(*((float *)v0 + 41316) +
                      (float)(v14.fraction *
                              (float)(__x_8 - *((float *)v0 + 41316))));
      CG_TraceCapsule(&v14, (float *)v0 + 41314,
                      (trace_t *)&CG_OffsetThirdPersonView(void)::mins,
                      &CG_OffsetThirdPersonView(void)::maxs, (float *)&__x,
                      *((_DWORD *)v0 + 38692), (const float *)0x811);
      *(float *)&__x =
          *((float *)v0 + 41314) +
          (float)((float)(*(float *)&__x - *((float *)v0 + 41314)) *
                  v14.fraction);
      *((float *)&__x + 1) =
          *((float *)v0 + 41315) +
          (float)((float)(*((float *)&__x + 1) - *((float *)v0 + 41315)) *
                  v14.fraction);
      __x_8 = *((float *)v0 + 41316) +
              (float)(v14.fraction * (float)(__x_8 - *((float *)v0 + 41316)));
    }
  v3 = (float *)cg;
  v4 = (float *)((char *)cg + 165256);
  *((_QWORD *)cg + 20657) = __x;
  v4[2] = __x_8;
  v5 = fsqrt((float)((float)(v13 - *v4) * (float)(v13 - *v4)) +
             (float)((float)(v12 - v4[1]) * (float)(v12 - v4[1])));
  if (v5 < 1.0)
    v6 = 1.0;
  else
    v6 = v5;
  *((double *)&v9 + 1) = v6;
  *(double *)&v9 = (float)(v11 - v4[2]);
  v7 = atan2(v9, v10);
  v8 = v7 * -57.29577951308232;
  v3[41330] = v8;
}

void __cdecl CG_DumpAnims(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalcTurretViewValues(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalcViewValues(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateEntInfo(void)
{
  UNIMPLEMENTED();
}
