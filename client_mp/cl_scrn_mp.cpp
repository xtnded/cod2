void __cdecl SCR_UpdateScreen()
{
  UNIMPLEMENTED();
}

float __cdecl CL_GetMenuBlurRadius()
{
  if ((*((_BYTE *)cl + 4) & 8) != 0 && dword_1220A70 && *(_DWORD *)clc != 1)
    return UI_GetBlurRadius();
  else
    return 0.0;
}

void __cdecl SCR_Init()
{
  scr_initialized = 1;
}

void __cdecl SCR_DrawConsoleString(int x, int y, short const *string,
                                   int maxChars, float const *const setColor)
{
  float v5; // xmm1_4

  v5 = (float)dword_121C7B8(dword_14C13C0);
  return ((int(__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD,
                          _DWORD, _DWORD, _DWORD))unk_121C7C8)(
      a3, a4, dword_14C13C0, (float)a1, (float)a2 + v5, 1065353216, 1065353216,
      a5, 0);
}

void __cdecl SCR_DrawSmallStringExt(int x, int y, char const *string,
                                    float const *const setColor)
{
  float v4; // xmm1_4

  v4 = (float)dword_121C7B8(dword_14C13C0);
  return ((int(__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD,
                          _DWORD, _DWORD, _DWORD))dword_121C7BC)(
      a3, 0x7FFFFFFF, dword_14C13C0, (float)a1, (float)a2 + v4, 1065353216,
      1065353216, a4, 0);
}

void __cdecl SCR_DrawSmallChar(int, int, int, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl SCR_DrawPic(float, float, float, float, int, int,
                         struct Material *)
{
  UNIMPLEMENTED();
}

void __cdecl CL_DrawScreen(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_CubemapShot_f()
{
  const char *v5;                                   // eax
  const char *v6;                                   // eax
  int v7;                                           // edi
  float v8;                                         // xmm0_4
  CubemapShot i;                                    // ebx
  int v10;                                          // edi
  const char **v11;                                 // esi
  void(__cdecl * v12)(char *, int, _DWORD, _DWORD); // ebx
  char *v13;                                        // eax
  const char *v14;                                  // eax
  const char *v15;                                  // eax
  float v16;                                        // xmm0_4
  const char *v17;                                  // eax
  float v18;                                        // xmm0_4
  const char *v19;                                  // eax
  float v20;                                        // xmm0_4
  const char *v21;                                  // eax
  const char *v22;                                  // eax
  float v23;                                        // xmm0_4
  const char *v24;                                  // eax
  float v25;                                        // xmm0_4
  char v26;                                         // [esp+57h] [ebp-71h]
  __int64 v27;                                      // [esp+58h] [ebp-70h]
  char __dst[64];                                   // [esp+64h] [ebp-64h] BYREF
  float v29;                                        // [esp+A4h] [ebp-24h] BYREF
  float v30;                                        // [esp+A8h] [ebp-20h]
  float v31;                                        // [esp+ACh] [ebp-1Ch]

    if (!*((_BYTE *)cl + 9)) {
      Com_Printf("must be in a map to use this command\n");
      return;
    }
  if (Cmd_Argc() <= 2)
    goto LABEL_4;
  if (strlen((const char *)Cmd_Argv(2)) > 0x28)
    goto LABEL_4;
  v5 = (const char *)Cmd_Argv(2);
  strcpy(__dst, v5);
  v6 = (const char *)Cmd_Argv(1);
  v7 = atoi(v6);
  if ((unsigned int)(v7 - 4) > 0x3FC || ((v7 - 1) & v7) != 0)
    goto LABEL_4;
  v29 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
    if (Cmd_Argc() == 7) {
      v14 = (const char *)Cmd_Argv(3);
      if (stricmp(v14, "lighting"))
        goto LABEL_4;
      v15 = (const char *)Cmd_Argv(4);
      v16 = atof(v15);
      v29 = v16;
      v17 = (const char *)Cmd_Argv(5);
      v18 = atof(v17);
      v30 = v18;
      v19 = (const char *)Cmd_Argv(6);
      a1 = atof(v19);
      v20 = a1;
      v31 = v20;
      v26 = 1;
      v27 = 0x3FAA9FBE3F800000LL;
      v8 = 1.3329999;
    }
    else {
        if (Cmd_Argc() != 6) {
            if (Cmd_Argc() == 3) {
              v26 = 0;
              v27 = 0x3FAA9FBE3F800000LL;
              v8 = 1.3329999;
              goto LABEL_12;
            }
        LABEL_4:
          CL_CubemapShotUsage();
          return;
        }
      v21 = (const char *)Cmd_Argv(3);
      if (stricmp(v21, "fresnel"))
        goto LABEL_4;
      v22 = (const char *)Cmd_Argv(4);
      v23 = atof(v22);
      *(float *)&v27 = v23;
      v24 = (const char *)Cmd_Argv(5);
      a1 = atof(v24);
      v25 = a1;
      *((float *)&v27 + 1) = v25;
      if (*(float *)&v27 < 1.0)
        goto LABEL_4;
      v8 = 1.0;
      if (*((float *)&v27 + 1) < 1.0)
        goto LABEL_4;
      v26 = 0;
    }
LABEL_12:
  CL_ResetSkeletonCache(0);
    for (i = CUBEMAPSHOT_UP; i != CUBEMAPSHOT_COUNT; ++i) {
      unk_121C78C(v7, 1);
      (*(void (**)(void)) & algn_121C738[16])();
      CL_ClearScene();
      CG_DrawActiveFrame(
          a1, v8, a2, a3, a4, a5, *((_DWORD *)cl + 2492),
          (DemoType)(*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc) != 0), i, v7,
          0);
      (*(void (**)(void)) & algn_121C738[20])();
      unk_121C790(i);
    }
  if (v26)
    unk_121C798(&v29);
  v10 = 1;
  v11 = (const char **)&CL_CubemapShot_f(void)::szShotName;
    do {
      v12 = (void(__cdecl *)(char *, int, _DWORD, _DWORD))unk_121C794;
      v13 = va("env/%s%s.tga", __dst, *v11);
      v12(v13, v10++, v27, HIDWORD(v27));
      ++v11;
    }
  while (v10 != 7);
}

void __cdecl SCR_UpdateScreenInternal()
{
  UNIMPLEMENTED();
}

int scr_initialized;
bool updateScreenCalled;

enum DemoType __cdecl CL_GetDemoType(void)
{
  UNIMPLEMENTED();
}

void __cdecl SCR_UpdateRumble(void)
{
  UNIMPLEMENTED();
}

void __cdecl SCR_DrawDemoRecording(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_CubemapShotUsage(void)
{
  Com_Printf("Syntax: cubemapShot size basefilename [water r0 g0 b0 r90 g90 "
             "b90 | fresnel n0 n1]\n");
  Com_Printf("size must be a power of 2 >= 4 and <= 1024\n");
  Com_Printf("screenshots will be written to 'env/basefilename_*.tga'\n");
  Com_Printf("basefilename must not exceed %i chars\n", 40);
  Com_Printf("If 'water' is specified, a diffuse water color cubemap is "
             "generated using local lighting.\n");
  Com_Printf("The water has the given colors at the given angles, and blends "
             "between them in the middle.\n");
  Com_Printf("If 'fresnel' is specified, the alpha channel of the cubemap "
             "contains the reflection factor.\n");
  Com_Printf("n0 and n1 are the index of refraction of the 'air' and 'water' "
             "surfaces, respectively.\n");
  Com_Printf("The index of refraction must always be 1 or greater.\n");
  Com_Printf("This is always calculated, and defaults to air-water interface "
             "(n0 = 1, n1 = 1.333).\n");
}

int __cdecl CL_CGameRendering(int)
{
  UNIMPLEMENTED();
}

void __cdecl SCR_DrawScreenField(void)
{
  UNIMPLEMENTED();
}

void __cdecl SCR_UpdateFrame(void)
{
  UNIMPLEMENTED();
}
