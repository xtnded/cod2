void __cdecl CalcScreenY(float *y, int vertAlign)
{
  int result; // eax

  result = a2;
    switch (a2) {
    case 1:
      *a1 = (float)(*a1 * *(float *)&dword_F2F584) + *(float *)&dword_F2F5B8;
      break;
    case 2:
      *a1 = (float)(*a1 * *(float *)&dword_F2F584) +
            (float)(0.5 * *(float *)&dword_F2F5B0);
      break;
    case 3:
      *a1 = (float)(*a1 * *(float *)&dword_F2F584) + *(float *)&dword_F2F5C0;
      break;
    case 4:
      *a1 = *a1 * *(float *)&dword_F2F58C;
      break;
    case 5:
      return result;
    case 6:
      *a1 = *a1 * *(float *)&dword_F2F594;
      break;
    case 7:
      *a1 = (float)(*a1 * *(float *)&dword_F2F584) +
            (float)((float)(*(float *)&dword_F2F5B8 + *(float *)&dword_F2F5C0) *
                    0.5);
      break;
    default:
      *a1 = *a1 * *(float *)&dword_F2F584;
      break;
    }
  return result;
}

void __cdecl CalcScreenX(float *x, int horzAlign)
{
  int result; // eax

  result = a2;
    switch (a2) {
    case 1:
      *a1 = (float)(*a1 * *(float *)&spGlob) + *(float *)&dword_F2F5B4;
      break;
    case 2:
      *a1 = (float)(*a1 * *(float *)&spGlob) +
            (float)(0.5 * *(float *)&dword_F2F5AC);
      break;
    case 3:
      *a1 = (float)(*a1 * *(float *)&spGlob) + *(float *)&dword_F2F5BC;
      break;
    case 4:
      *a1 = *a1 * *(float *)&dword_F2F588;
      break;
    case 5:
      return result;
    case 6:
      *a1 = (float)(*a1 * *(float *)&dword_F2F590) + *(float *)&dword_F2F598;
      break;
    case 7:
      *a1 = (float)(*a1 * *(float *)&spGlob) +
            (float)((float)(*(float *)&dword_F2F5B4 + *(float *)&dword_F2F5BC) *
                    0.5);
      break;
    default:
      *a1 =
          (float)((float)(*a1 * *(float *)&spGlob) + *(float *)&dword_F2F5C4) +
          *(float *)&dword_F2F598;
      break;
    }
  return result;
}

float __cdecl GetVirtualHeightFromRealHeight(float height)
{
  return (float)(a1 * *(float *)&dword_F2F594);
}

float __cdecl GetVirtualWidthFromRealWidth(float width)
{
  return (float)(a1 * *(float *)&dword_F2F590);
}

float __cdecl GetRealHeightFromVirtualHeight(float height)
{
  return (float)(a1 * *(float *)&dword_F2F584);
}

float __cdecl GetRealWidthFromVirtualWidth(float width)
{
  return (float)(a1 * *(float *)&spGlob);
}

float __cdecl GetRealViewportHeight(void)
{
  UNIMPLEMENTED();
}

float __cdecl GetRealViewportWidth(void)
{
  UNIMPLEMENTED();
}

float __cdecl GetVirtualViewportHeight(void)
{
  UNIMPLEMENTED();
}

float __cdecl GetVirtualViewportWidth(void)
{
  UNIMPLEMENTED();
}

void __cdecl ApplySplitscreenScaling(float *, float *, float *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl CalcSplitScreenTextOffset(struct Font_s *font, float *y)
{
  ;
}

void __cdecl CalcScreenPlacement(float *x, float *y, float *w, float *h,
                                 int horzAlign, int vertAlign)
{
  int result; // eax
  float v7;   // xmm0_4
  float v8;   // xmm1_4
  float v9;   // xmm0_4
  float v10;  // xmm1_4

  result = a5;
    switch (a5) {
    case 1:
      *a1 = (float)(*a1 * *(float *)&spGlob) + *(float *)&dword_F2F5B4;
      *a3 = *a3 * *(float *)&spGlob;
      break;
    case 2:
      v7 = *a1 * *(float *)&spGlob;
      v8 = 0.5 * *(float *)&dword_F2F5AC;
      goto LABEL_3;
    case 3:
      *a1 = (float)(*a1 * *(float *)&spGlob) + *(float *)&dword_F2F5BC;
      *a3 = *a3 * *(float *)&spGlob;
      break;
    case 4:
      *a1 = *a1 * *(float *)&dword_F2F588;
      *a3 = *a3 * *(float *)&dword_F2F588;
      break;
    case 5:
      break;
    case 6:
      *a1 = (float)(*a1 * *(float *)&dword_F2F590) + *(float *)&dword_F2F598;
      *a3 = *a3 * *(float *)&dword_F2F590;
      break;
    case 7:
      v7 = *a1 * *(float *)&spGlob;
      v8 = (float)(*(float *)&dword_F2F5B4 + *(float *)&dword_F2F5BC) * 0.5;
    LABEL_3:
      *a1 = v7 + v8;
      *a3 = *a3 * *(float *)&spGlob;
      break;
    default:
      *a1 =
          (float)((float)(*a1 * *(float *)&spGlob) + *(float *)&dword_F2F5C4) +
          *(float *)&dword_F2F598;
      *a3 = *a3 * *(float *)&spGlob;
      break;
    }
    switch (a6) {
    case 1:
      *a2 = (float)(*a2 * *(float *)&dword_F2F584) + *(float *)&dword_F2F5B8;
      *a4 = *a4 * *(float *)&dword_F2F584;
      break;
    case 2:
      v9 = *a2 * *(float *)&dword_F2F584;
      v10 = 0.5 * *(float *)&dword_F2F5B0;
      goto LABEL_6;
    case 3:
      *a2 = (float)(*a2 * *(float *)&dword_F2F584) + *(float *)&dword_F2F5C0;
      *a4 = *a4 * *(float *)&dword_F2F584;
      break;
    case 4:
      *a2 = *a2 * *(float *)&dword_F2F58C;
      *a4 = *a4 * *(float *)&dword_F2F58C;
      break;
    case 5:
      return result;
    case 6:
      *a2 = *a2 * *(float *)&dword_F2F594;
      *a4 = *a4 * *(float *)&dword_F2F594;
      break;
    case 7:
      v9 = *a2 * *(float *)&dword_F2F584;
      v10 = (float)(*(float *)&dword_F2F5B8 + *(float *)&dword_F2F5C0) * 0.5;
    LABEL_6:
      *a2 = v9 + v10;
      *a4 = *a4 * *(float *)&dword_F2F584;
      break;
    default:
      *a2 = *a2 * *(float *)&dword_F2F584;
      *a4 = *a4 * *(float *)&dword_F2F584;
      break;
    }
  return result;
}

void __cdecl SetScreenScaling(float safeAreaRatioHorizontal,
                              float safeAreaRatioVertical, int viewportX,
                              int viewportY, int viewportWidth,
                              int viewportHeight)
{
  UNIMPLEMENTED();
}

void __cdecl CalcSafeAreaOffsets(float, float, float, float, float, float,
                                 float, float *const, float *const,
                                 float *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl SetScreenScalingTypecast(float, float, float, float, float, float)
{
  UNIMPLEMENTED();
}
