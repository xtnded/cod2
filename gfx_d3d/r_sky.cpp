void __cdecl R_FlushSun()
{
  UNIMPLEMENTED();
}

int __cdecl R_GetSundvarsSize()
{
  return 21;
}

void __cdecl R_Cmd_SaveSun()
{
  void(__cdecl * v0)(char *, char *, unsigned int); // ebx
  unsigned int v1;                                  // kr04_4
  char *v2;                                         // eax
  const char *v3;                                   // [esp+1Ch] [ebp-201Ch]
  char v4[8216]; // [esp+20h] [ebp-2018h] BYREF

    if (unk_11807C0() == 2) {
      v3 = (const char *)unk_11807C4(1);
        if (unk_11807CC(&s_sundvars, 21, v4, 0x2000)) {
          v0 = (void(__cdecl *)(char *, char *, unsigned int))unk_1180800;
          v1 = strlen(v4) + 1;
          v2 = va("sun/%s.sun", v3);
          v0(v2, v4, v1 - 1);
        }
    }
    else {
      ri(0,
         "USAGE: r_savesun <sunname>\n  sunname must not have an extension\n");
    }
}

void __cdecl R_SetSunFromDvars(struct sunflare_t *)
{
  int32_t v1;      // xmm0_4
  int32_t v2;      // xmm0_4
  int32_t v3;      // xmm0_4
  int32_t v4;      // xmm0_4
  int32_t v5;      // xmm0_4
  int32_t v6;      // xmm0_4
  long double v7;  // [esp+0h] [ebp-68h]
  long double v8;  // [esp+0h] [ebp-68h]
  long double v9;  // [esp+0h] [ebp-68h]
  long double v10; // [esp+0h] [ebp-68h]
  long double v11; // [esp+0h] [ebp-68h]
  long double v12; // [esp+0h] [ebp-68h]
  float v13;       // [esp+18h] [ebp-50h]
  float v14;       // [esp+1Ch] [ebp-4Ch]
  float v15;       // [esp+30h] [ebp-38h]
  float v16;       // [esp+34h] [ebp-34h]
  float v17;       // [esp+48h] [ebp-20h]
  float v18;       // [esp+4Ch] [ebp-1Ch]

  a1->spriteMaterial = (int32_t)Material_RegisterHandle(
      *(char **)(r_sunsprite_shader + 8), 0, 6);
  a1->spriteSize = *(_DWORD *)(r_sunsprite_size + 8);
  a1->flareMaterial =
      (int32_t)Material_RegisterHandle(*(char **)(r_sunflare_shader + 8), 0, 6);
  *(float *)&a1->flareMinSize = *(float *)(r_sunflare_min_size + 8) * 0.5;
  *(double *)&v7 = *(float *)(r_sunflare_min_angle + 8) * 0.0174532925199433;
  *(float *)&v1 = cos(v7);
  a1->flareMinDot = v1;
  *(float *)&a1->flareMaxSize = *(float *)(r_sunflare_max_size + 8) * 0.5;
  *(double *)&v8 = *(float *)(r_sunflare_max_angle + 8) * 0.0174532925199433;
  *(float *)&v2 = cos(v8);
  a1->flareMaxDot = v2;
  a1->flareMaxAlpha = *(_DWORD *)(r_sunflare_max_alpha + 8);
  v18 = floorf((float)(*(float *)(r_sunflare_fadein + 8) * 1000.0) + 0.5);
  a1->flareFadeInTime = (int)v18;
  v17 = floorf((float)(*(float *)(r_sunflare_fadeout + 8) * 1000.0) + 0.5);
  a1->flareFadeOutTime = (int)v17;
  *(double *)&v9 = *(float *)(r_sunblind_min_angle + 8) * 0.0174532925199433;
  *(float *)&v3 = cos(v9);
  a1->blindMinDot = v3;
  *(double *)&v10 = *(float *)(r_sunblind_max_angle + 8) * 0.0174532925199433;
  *(float *)&v4 = cos(v10);
  a1->blindMaxDot = v4;
  a1->blindMaxDarken = *(_DWORD *)(r_sunblind_max_darken + 8);
  v16 = floorf((float)(*(float *)(r_sunblind_fadein + 8) * 1000.0) + 0.5);
  a1->blindFadeInTime = (int)v16;
  v15 = floorf((float)(*(float *)(r_sunblind_fadeout + 8) * 1000.0) + 0.5);
  a1->blindFadeOutTime = (int)v15;
  *(double *)&v11 = *(float *)(r_sunglare_min_angle + 8) * 0.0174532925199433;
  *(float *)&v5 = cos(v11);
  a1->glareMinDot = v5;
  *(double *)&v12 = *(float *)(r_sunglare_max_angle + 8) * 0.0174532925199433;
  *(float *)&v6 = cos(v12);
  a1->glareMaxDot = v6;
  a1->glareMaxLighten = *(_DWORD *)(r_sunglare_max_lighten + 8);
  v14 = floorf((float)(*(float *)(r_sunglare_fadein + 8) * 1000.0) + 0.5);
  a1->glareFadeInTime = (int)v14;
  v13 = floorf((float)(1000.0 * *(float *)(r_sunglare_fadeout + 8)) + 0.5);
  a1->glareFadeOutTime = (int)v13;
  AngleVectors(*(float **)(r_sun_fx_position + 8), a1->sunFxPosition, 0, 0);
  a1->hasValidData = 1;
}

void __cdecl R_RegisterSunDvars()
{
  UNIMPLEMENTED();
}

char const **s_sundvars;
struct dvar_s const *const r_sunflare_min_size;
struct dvar_s const *const r_sunsprite_shader;
struct dvar_s const *const r_sunblind_min_angle;
struct dvar_s const *const r_sunblind_fadeout;
struct dvar_s const *const r_sun_fx_position;
struct dvar_s const *const r_sunglare_fadein;
struct dvar_s const *const r_sunglare_fadeout;
struct dvar_s const *const r_sunflare_fadein;
struct dvar_s const *const r_sunblind_fadein;
struct dvar_s const *const r_sunflare_fadeout;
struct dvar_s const *const r_sunflare_max_alpha;
struct dvar_s const *const r_sunblind_max_darken;
struct dvar_s const *const r_sunflare_max_angle;
struct dvar_s const *const r_sunblind_max_angle;
struct dvar_s const *const r_sunglare_max_angle;
struct dvar_s const *const r_sunglare_min_angle;
struct dvar_s const *const r_sunflare_min_angle;
struct dvar_s const *const r_sunflare_max_size;
struct dvar_s const *const r_sunflare_shader;
int marker_r_sky;
struct dvar_s const *const r_sunsprite_size;
struct dvar_s const *const r_sunglare_max_lighten;

void __cdecl R_SaveSunFromDvars(char const *)
{
  UNIMPLEMENTED();
}

R_Cmd_LoadSun()
{
  UNIMPLEMENTED();
}
