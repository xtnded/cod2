void __cdecl Vec4Lerp(float const *const, float const *const, float,
                      float *const)
{
  UNIMPLEMENTED();
}

float *__cdecl CG_TeamColor(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_NorthDirectionChanged()
{
  char *ConfigString; // eax
  float *v1;          // ebx
  float v2;           // xmm0_4

  ConfigString = CL_GetConfigString(11);
  v1 = (float *)cg;
  v2 = atof(ConfigString);
  v1[45419] = v2;
}

float *__cdecl CG_FadeColor(int startMsec, int totalMsec, int fadeMsec)
{
  int v4; // eax

  if (!a1)
    return 0;
  v4 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - a1;
  if (v4 >= a2)
    return 0;
  if (a2 - v4 >= a3)
    dword_F3170C = 1065353216;
  else
    *(float *)&dword_F3170C = (float)(a2 - v4) / (float)a3;
  dword_F31708 = 1065353216;
  dword_F31704 = 1065353216;
  CG_FadeColor(int, int, int)::color = 1065353216;
  return &CG_FadeColor(int, int, int)::color;
}

bool __cdecl CG_IsFullViewportRendering(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ColorForHealth(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_GetColorForHealth(int, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DebugLine(float const *const, float const *const,
                          float const *const, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DebugArc(float const *const, float, float, float,
                         float const *const, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DebugCircle(float const *const, float, float const *const,
                            float const *const, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DebugBox(float const *const, float const *const,
                         float const *const, float, float const *const, int,
                         int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateCompPointerOrientation()
{
  void *v0;   // eax
  int v1;     // ecx
  int v2;     // edx
  int v3;     // esi
  float v4;   // xmm4_4
  __m128 v5;  // xmm2
  float *v6;  // ebx
  float *v7;  // eax
  float v8;   // xmm1_4
  float v9;   // xmm1_4
  float v10;  // xmm0_4
  float v11;  // xmm0_4
  float v12;  // xmm0_4
  float v13;  // xmm0_4
  float *v14; // ebx
  float v15;  // [esp+1Ch] [ebp-2Ch]
  float v16;  // [esp+1Ch] [ebp-2Ch]
  float v17;  // [esp+3Ch] [ebp-Ch]

    if (!*(_BYTE *)(cg_hudCompassSpringyPointers + 8)) {
      *((_DWORD *)cg + 45422) = *((_DWORD *)cg + 41331);
      return;
    }
  v0 = cg;
  v1 = *(_DWORD *)((char *)&loc_2C5A8 + (_DWORD)cg);
  v2 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (v1 != v2) {
      v17 = *((float *)cg + 41331);
        if (v1 > v2 || (v3 = v2 - v1, (float)(v2 - v1) > 500.0)) {
          *(_DWORD *)((char *)&loc_2C5A8 + (_DWORD)cg) = v2;
        LABEL_8:
          *((_QWORD *)v0 + 22711) = LODWORD(v17);
          return;
        }
      *(_DWORD *)((char *)&loc_2C5A8 + (_DWORD)cg) = v2;
      v15 = AngleSubtract(*((float *)v0 + 45422), v17);
      v4 = v15;
        if (fabs(v15) > 10.0) {
          if (v15 < 0.0)
            v4 = -10.0;
          else
            v4 = 10.0;
        }
        if (v3 <= 0) {
        LABEL_40:
          v14 = (float *)cg;
          v14[45422] = AngleNormalize360(v4 + v17);
          return;
        }
      if (v3 <= 5)
        goto LABEL_27;
    LABEL_12:
      v3 -= 5;
      v5.f32[0] = 5.0 * 0.001;
        if (fabs(v4) < 0.5) {
        LABEL_13:
          v0 = cg;
            if (fabs(*((float *)cg + 45423)) >= 2.0) {
              v6 = (float *)cg;
              goto LABEL_15;
            }
          goto LABEL_8;
        }
        while (1) {
          v6 = (float *)cg;
        LABEL_15:
          v16 = AngleNormalize180((float)(v5.f32[0] * v6[45423]) + v4);
          v4 = v16;
          v5 = (__m128)v5.u32[0];
            if (v16 <= 0.0) {
                if (v16 < 0.0) {
                  v7 = (float *)cg;
                  *((float *)cg + 45423) =
                      (float)(v5.f32[0] * 1500.0) + *((float *)cg + 45423);
                  goto LABEL_18;
                }
            }
            else {
              v6[45423] = v6[45423] - (float)(v5.f32[0] * 1500.0);
            }
          v7 = (float *)cg;
        LABEL_18:
          v8 = v7[45423] - (float)((float)(v7[45423] * 3.0) * v5.f32[0]);
          v7[45423] = v8;
            if (v8 <= 0.0) {
              if (v16 < 0.0)
                v7[45423] = v8 - (float)((float)(v8 * 5.0) * v5.f32[0]);
              v5.f32[0] = (float)(v5.f32[0] + v5.f32[0]) + v7[45423];
              *((_DWORD *)v7 + 45423) =
                  _mm_andnot_ps(_mm_cmplt_ss((__m128)0LL, v5), v5).u32[0];
            }
            else {
                if (v16 <= 0.0) {
                  v10 = v7[45423];
                }
                else {
                  v9 = v8 - (float)((float)(v8 * 5.0) * v5.f32[0]);
                  v7[45423] = v9;
                  v10 = v9;
                }
              v11 = v10 - (float)(v5.f32[0] + v5.f32[0]);
              v7[45423] = v11;
              if (v11 < 0.0)
                v7[45423] = 0.0;
            }
          v12 = *((float *)cg + 45423);
            if (v12 <= 2000.0) {
              if (v12 < -2000.0)
                *((_DWORD *)cg + 45423) = -990248960;
            }
            else {
              *((_DWORD *)cg + 45423) = 1157234688;
            }
          if (v3 <= 0)
            goto LABEL_40;
          if (v3 > 5)
            goto LABEL_12;
        LABEL_27:
          v13 = (float)v3;
          v3 = 0;
          v5.f32[0] = v13 * 0.001;
          if (fabs(v4) < 0.5)
            goto LABEL_13;
        }
    }
}

void __cdecl CG_UpdateCompassOrientation()
{
  void *v0;  // ebx
  int v1;    // edx
  int v2;    // eax
  int v3;    // esi
  float v4;  // xmm4_4
  float v5;  // xmm0_4
  __m128 v6; // xmm2
  void *v7;  // eax
  void *v8;  // ebx
  void *v9;  // eax
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  void *v15; // ebx
  float v16; // [esp+1Ch] [ebp-3Ch]
  float v17; // [esp+1Ch] [ebp-3Ch]
  float v18; // [esp+3Ch] [ebp-1Ch]

  v0 = cg;
  v18 = AngleNormalize360(*((float *)cg + 41331) - *((float *)cg + 45419));
  v1 = *(_DWORD *)((char *)&loc_2C5A8 + (_DWORD)v0);
  v2 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v0);
    if (v1 > v2 || (v3 = v2 - v1, (float)(v2 - v1) > 500.0)) {
      *(_DWORD *)((char *)&loc_2C5A8 + (_DWORD)v0) = v2;
      *(float *)((char *)&loc_2C5B0 + (_DWORD)v0) = v18;
      *(_DWORD *)((char *)&loc_2C5B4 + (_DWORD)v0) = 0;
      return;
    }
  *(_DWORD *)((char *)&loc_2C5A8 + (_DWORD)v0) = v2;
  v16 = AngleSubtract(*(float *)((char *)&loc_2C5B0 + (_DWORD)v0), v18);
  v4 = v16;
    if (v3 <= 0) {
    LABEL_20:
      v15 = cg;
      *(float *)((char *)&loc_2C5B0 + (_DWORD)v15) =
          AngleNormalize360(v4 + v18);
      return;
    }
    while (v3 <= 5) {
      v5 = (float)v3;
      v3 = 0;
      v6.f32[0] = v5 * 0.001;
      if (fabs(v4) < 0.25)
        goto LABEL_7;
    LABEL_22:
      v8 = cg;
    LABEL_9:
      v17 = AngleNormalize180(
          (float)(v6.f32[0] * *(float *)((char *)&loc_2C5B4 + (_DWORD)v8)) +
          v4);
      v4 = v17;
      v6 = (__m128)v6.u32[0];
        if (v17 <= 0.0) {
            if (v17 < 0.0) {
              v9 = cg;
              *(float *)((char *)&loc_2C5B4 + (_DWORD)cg) =
                  (float)(v6.f32[0] * 1000.0) +
                  *(float *)((char *)&loc_2C5B4 + (_DWORD)cg);
              goto LABEL_12;
            }
        }
        else {
          *(float *)((char *)&loc_2C5B4 + (_DWORD)v8) =
              *(float *)((char *)&loc_2C5B4 + (_DWORD)v8) -
              (float)(v6.f32[0] * 1000.0);
        }
      v9 = cg;
    LABEL_12:
      v10 = *(float *)((char *)&loc_2C5B4 + (_DWORD)v9) -
            (float)((float)(*(float *)((char *)&loc_2C5B4 + (_DWORD)v9) +
                            *(float *)((char *)&loc_2C5B4 + (_DWORD)v9)) *
                    v6.f32[0]);
      *(float *)((char *)&loc_2C5B4 + (_DWORD)v9) = v10;
        if (v10 <= 0.0) {
          if (v17 < 0.0)
            *(float *)((char *)&loc_2C5B4 + (_DWORD)v9) =
                v10 - (float)((float)(v10 * 3.5) * v6.f32[0]);
          v6.f32[0] = v6.f32[0] + *(float *)((char *)&loc_2C5B4 + (_DWORD)v9);
          *(_DWORD *)((char *)&loc_2C5B4 + (_DWORD)v9) =
              _mm_andnot_ps(_mm_cmplt_ss((__m128)0, v6), v6).u32[0];
        }
        else {
            if (v17 <= 0.0) {
              v12 = *(float *)((char *)&loc_2C5B4 + (_DWORD)v9);
            }
            else {
              v11 = v10 - (float)((float)(v10 * 3.5) * v6.f32[0]);
              *(float *)((char *)&loc_2C5B4 + (_DWORD)v9) = v11;
              v12 = v11;
            }
          v13 = v12 - v6.f32[0];
          *(float *)((char *)&loc_2C5B4 + (_DWORD)v9) = v13;
          if (v13 < 0.0)
            *(_DWORD *)((char *)&loc_2C5B4 + (_DWORD)v9) = 0;
        }
      v14 = *(float *)((char *)&loc_2C5B4 + (_DWORD)cg);
        if (v14 <= 30000.0) {
          if (v14 < -30000.0)
            *(_DWORD *)((char *)&loc_2C5B4 + (_DWORD)cg) = -957718528;
        }
        else {
          *(_DWORD *)((char *)&loc_2C5B4 + (_DWORD)cg) = 1189765120;
        }
      if (v3 <= 0)
        goto LABEL_20;
    }
  v3 -= 5;
  v6.f32[0] = 5.0 * 0.001;
  if (fabs(v4) >= 0.25)
    goto LABEL_22;
LABEL_7:
  v7 = cg;
    if (fabs(*(float *)((char *)&loc_2C5B4 + (_DWORD)cg)) >= 1.0) {
      v8 = cg;
      goto LABEL_9;
    }
  *(float *)((char *)&loc_2C5B0 + (_DWORD)cg) = v18;
  *(_DWORD *)((char *)&loc_2C5B4 + (_DWORD)v7) = 0;
}

int __cdecl CG_DrawDevString(float x, float y, char const *s,
                             float const *const color, int align,
                             struct Font_s *font, int style)
{
  int v7;   // esi
  float v8; // xmm0_4
  int v9;   // eax
  int v10;  // eax

  if ((a5 & 3) != 1)
    CL_TextWidth(a3, 0, a6);
  v7 = CL_TextHeight(a6);
  v8 = (float)v7;
  v9 = a5 & 0xC;
    if (v9 != 8) {
      if (v9 == 12)
        v8 = v8 * 0.5;
      a2 = v8 + a2;
    }
  v10 = CL_TextWidth(a3, 0, a6);
  CL_DrawText(a3, 0x7FFFFFFF, a6, -(float)v10, a2, 3, 1, 1.0, 1.0, a4, a7);
  return v7;
}

void __cdecl CG_DrawRotatedQuadPic(float, float, float const (*)[2], float,
                                   float const *const, struct Material *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawRotatedPicPhysical(float x, float y, float width,
                                       float height, float angle,
                                       float const *const color,
                                       struct Material *material)
{
  float v5;      // xmm0_4
  int v6;        // ecx
  float *v7;     // edx
  int v8;        // eax
  float v9;      // xmm1_4
  float v10;     // xmm3_4
  float v12;     // [esp+1Ch] [ebp-3Ch]
  float v13;     // [esp+20h] [ebp-38h]
  float v14[10]; // [esp+30h] [ebp-28h]

  v5 = a5 * 0.0174532925199433;
  v13 = sinf(v5);
  v12 = cosf(v5);
  v6 = 0;
  v7 = (float *)&CG_DrawRotatedPicPhysical(float, float, float, float, float,
                                           float const *, Material *)::sign;
  v8 = 0;
    do {
      v9 = *v7;
      v10 = v7[1];
      v14[v8] = (float)((float)((float)(v12 * (float)(a3 * 0.5)) * *v7) +
                        (float)((float)(a3 * 0.5) + a1)) -
                (float)((float)(v13 * (float)(a3 * 0.5)) * v10);
      v14[v8 + 1] = (float)((float)(v9 * (float)(v13 * (float)(0.5 * a4))) +
                            (float)((float)(0.5 * a4) + a2)) +
                    (float)(v10 * (float)(v12 * (float)(0.5 * a4)));
      ++v6;
      v8 += 2;
      v7 += 2;
    }
  while (v6 != 4);
  return CL_DrawQuadPic();
}

void __cdecl CG_TileClear()
{
  UNIMPLEMENTED();
}

int __cdecl CG_DrawSmallDevStringColor(float x, float y, char const *s,
                                       float const *const color, int align)
{
  return CG_DrawDevString(a1, a2, a3, a4, a5, *((Font_s **)cgs + 12063), 0);
}

int __cdecl CG_DrawSmallDevString(float, float, char const *, float, int)
{
  UNIMPLEMENTED();
}

int __cdecl CG_DrawBigDevStringColor(float x, float y, char const *s,
                                     float const *const color, int align)
{
  return CG_DrawDevString(a1, a2, a3, a4, a5, *((Font_s **)cgs + 12064), 0);
}

int __cdecl CG_DrawBigDevString(float x, float y, char const *s, float alpha,
                                int align)
{
  float v6[6]; // [esp+20h] [ebp-18h] BYREF

  v6[0] = 1.0;
  v6[1] = 1.0;
  v6[2] = 1.0;
  v6[3] = a4;
  return CG_DrawDevString(a1, a2, a3, v6, a5, *((Font_s **)cgs + 12064), 0);
}

void __cdecl CG_DrawStringExt(float x, float y, char const *string,
                              float const *const setColor, int forceColor,
                              int shadow, float charHeight, int adjust)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawRotatedPic(float x, float y, float width, float height,
                               int horzAlign, int vertAlign, float angle,
                               float const *const color,
                               struct Material *material)
{
  CalcScreenPlacement(&a1, &a2, &a3, &a4, a5, a6);
  return CG_DrawRotatedPicPhysical(a1, a2, a3, a4, a7);
}

void __cdecl CG_FilledBar(float, float, float, float, float const *, float *,
                          float const *, float, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_HorizontalPercentBar(float, float, float, float, float)
{
  UNIMPLEMENTED();
}
