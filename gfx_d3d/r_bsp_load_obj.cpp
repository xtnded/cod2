void __cdecl R_InterpretSunLightParseParamsIntoLights(
    struct SunLightParseParams *sunParse, struct GfxLight *sunLight) {
  float v2;             // xmm3_4
  float v3;             // xmm5_4
  float v4;             // xmm4_4
  float v5;             // xmm0_4
  GfxLightInfo *result; // eax
  float v7;             // xmm1_4
  float v8;             // xmm2_4
  float v9;             // xmm0_4
  float v10;            // [esp+1Ch] [ebp-2Ch]
  float v11[9];         // [esp+24h] [ebp-24h] BYREF

  AngleVectors(a1->angles, v11, 0, 0);
  if (*(float *)&a1->ambientScale == 0.0 ||
      (v10 = ColorNormalize(a1->ambientColor, a1->ambientColor), v10 == 0.0)) {
    v2 = 0.0;
    v3 = 0.0;
    v4 = 0.0;
  } else {
    v4 = *(float *)&a1->ambientScale * a1->ambientColor[0];
    v3 = *(float *)&a1->ambientScale * a1->ambientColor[1];
    v2 = *(float *)&a1->ambientScale * a1->ambientColor[2];
  }
  v5 = (float)(*(float *)&a1->sunLight - *(float *)&a1->ambientScale) *
       (float)(1.0 - a1->diffuseFraction);
  result = (GfxLightInfo *)a1->sunColor;
  v7 = v5 * a1->sunColor[0];
  v8 = v5 * a1->sunColor[1];
  v9 = v5 * a1->sunColor[2];
  if (a2) {
    a2->position[0] = v11[0];
    a2->position[1] = v11[1];
    a2->position[2] = v11[2];
    a2->position[3] = 0.0;
    a2->color[0] = v7;
    a2->color[1] = v8;
    a2->color[2] = v9;
    result = &a2->u;
    a2->u.dir.ambientColor[0] = v4;
    a2->u.dir.ambientColor[1] = v3;
    a2->u.dir.ambientColor[2] = v2;
  }
  return result;
}

int marker_r_bsp_load_obj;
void __cdecl R_SetUpSunLight(float *const, float *const, float *const,
                             struct GfxLight *) {
  UNIMPLEMENTED();
}

R_ParseSunLight(SunLightParseParams *params, char const *text) {
  UNIMPLEMENTED();
}

R_LoadWorldInternal(char const *name) { UNIMPLEMENTED(); }
