int __cdecl UI_CursorInRect(int, int, int, int)
{
  UNIMPLEMENTED();
}

float __cdecl UI_ClampDvar(float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl UI_FillRectPhysical(float x, float y, float width, float height,
                                 float const *const color)
{
  Material *result; // eax

  result = dword_1684AE0;
  if (dword_1684AE0)
    return (Material *)CL_DrawStretchPicPhysical(
        *(float *)&a1, *((float *)&a1 + 1), a2, a3, 0.0, 0.0, 0.0, 0.0, a4,
        dword_1684AE0);
  return result;
}

void __cdecl UI_FillRect(float x, float y, float width, float height,
                         int horzAlign, int vertAlign, float const *const color)
{
  Material *result; // eax

  result = dword_1684AE0;
  if (dword_1684AE0)
    return (Material *)CL_DrawStretchPic(*(float *)&a1, *((float *)&a1 + 1), a2,
                                         a3, a4, a5, 0.0, 0.0, 0.0, 0.0, a6,
                                         dword_1684AE0);
  return result;
}

void __cdecl UI_DrawLoadBar(float x, float y, float w, float h, int horzAlign,
                            int vertAlign, float const *const color,
                            struct Material *material)
{
  int Int;  // ebx
  float v9; // xmm1_4

  Int = Dvar_GetInt("com_expectedHunkUsage");
  v9 = 0.0;
  if (Int > 0)
    v9 = fminf(1.0, (float)Hunk_Used() / (float)Int);
  return CL_DrawStretchPic(a1, a2, v9 * a3, a4, a5, a6, 0.0, 0.0, v9, 1.0, a7,
                           a8);
}

void __cdecl UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign,
                              int vertAlign, float const *const color,
                              struct Material *hMaterial)
{
  float v8;  // xmm2_4
  float v9;  // xmm1_4
  float v10; // ebx
  float v11; // ecx
  float v12; // edx
  float v13; // esi

  v8 = a3;
  v9 = a4;
    if (a3 < 0.0) {
      v8 = -a3;
      v10 = 1.0;
      v12 = 1.0;
      v11 = 0.0;
    }
    else {
      v10 = 0.0;
      v11 = 1.0;
      v12 = 1.0;
    }
    if (a4 < 0.0) {
      v9 = -a4;
      v13 = 1.0;
      v12 = 0.0;
    }
    else {
      v13 = 0.0;
    }
  return CL_DrawStretchPic(a1, a2, v8, v9, a5, a6, v10, v13, v11, v12, a7, a8);
}

void __cdecl UI_StartDemoLoop(void)
{
  UNIMPLEMENTED();
}
