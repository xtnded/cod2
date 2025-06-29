float const *const vec3_colorintensity;
void __cdecl R_ResetSunLightOverride() {
  int v0;     // ebx
  int v1;     // ecx
  int result; // eax

  v0 = dword_1184B9C + 200;
  v1 = dword_1184B9C + 224;
  *(_DWORD *)(dword_1184B9C + 200) = *(_DWORD *)(dword_1184B9C + 224);
  *(_DWORD *)(v0 + 4) = *(_DWORD *)(v1 + 4);
  result = *(_DWORD *)(v1 + 8);
  *(_DWORD *)(v0 + 8) = result;
  return result;
}

void __cdecl R_SetSunLightOverride(float const *const sunColor) {
  int result; // eax
  int v2;     // ecx

  result = r_rendererInUse;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2) {
    v2 = dword_1184B9C + 200;
    *(float *)(dword_1184B9C + 200) = *a1;
    *(float *)(v2 + 4) = a1[1];
    result = *((_DWORD *)a1 + 2);
    *(_DWORD *)(v2 + 8) = result;
  }
  return result;
}

void __cdecl R_GetWorldBounds(float *const min, float *const max) {
  int v2;     // ecx
  int v3;     // edx
  int result; // eax

  v2 = dword_1184B9C + 316;
  *a1 = *(float *)(dword_1184B9C + 316);
  a1[1] = *(float *)(v2 + 4);
  a1[2] = *(float *)(v2 + 8);
  v3 = dword_1184B9C + 328;
  *a2 = *(float *)(dword_1184B9C + 328);
  a2[1] = *(float *)(v3 + 4);
  result = *(_DWORD *)(v3 + 8);
  *((_DWORD *)a2 + 2) = result;
  return result;
}

void __cdecl R_InterpretSunLightParseParams(
    struct SunLightParseParams *sunParse) {
  _DWORD *v1; // eax
  int v2;     // ebx
  int result; // eax

  R_InterpretSunLightParseParamsIntoLights(a1,
                                           (GfxLight *)(dword_1184B9C + 180));
  v1 = (_DWORD *)dword_1184B9C;
  v2 = dword_1184B9C + 224;
  *(_DWORD *)(dword_1184B9C + 224) = *(_DWORD *)(dword_1184B9C + 200);
  v1[57] = v1[51];
  result = v1[52];
  *(_DWORD *)(v2 + 8) = result;
  return result;
}

void __cdecl R_UpdateLightsFromDvars() {
  int v0;                  // edx
  int v1;                  // ebx
  float *ambientColor;     // ecx
  int v3;                  // ecx
  float *sunColor;         // edx
  int v5;                  // ecx
  float *diffuseColor;     // edx
  float *v7;               // edx
  _DWORD *v8;              // eax
  int v9;                  // ebx
  int result;              // eax
  SunLightParseParams v11; // [esp+10h] [ebp-88h] BYREF

  v11.ambientScale = *(_DWORD *)(r_lightTweakAmbient + 8);
  v11.diffuseFraction = *(float *)(r_lightTweakDiffuseFraction + 8);
  v11.sunLight = *(_DWORD *)(r_lightTweakSunLight + 8);
  v0 = r_lightTweakAmbientColor;
  v1 = 0;
  ambientColor = v11.ambientColor;
  do {
    *ambientColor = (float)*(unsigned __int8 *)(v0 + 8);
    ++v1;
    ++ambientColor;
    ++v0;
  } while (v1 != 3);
  ColorNormalize(v11.ambientColor, v11.ambientColor);
  v3 = r_lightTweakSunColor;
  LOBYTE(v1) = 0;
  sunColor = v11.sunColor;
  do {
    *sunColor = (float)*(unsigned __int8 *)(v3 + 8);
    ++v1;
    ++sunColor;
    ++v3;
  } while (v1 != 3);
  ColorNormalize(v11.sunColor, v11.sunColor);
  v5 = r_lightTweakSunDiffuseColor;
  LOBYTE(v1) = 0;
  diffuseColor = v11.diffuseColor;
  do {
    *diffuseColor = (float)*(unsigned __int8 *)(v5 + 8);
    ++v1;
    ++diffuseColor;
    ++v5;
  } while (v1 != 3);
  ColorNormalize(v11.diffuseColor, v11.diffuseColor);
  v11.diffuseColorHasBeenSet = 1;
  v7 = *(float **)(r_lightTweakSunDirection + 8);
  v11.angles[0] = *v7;
  v11.angles[1] = v7[1];
  v11.angles[2] = v7[2];
  R_InterpretSunLightParseParamsIntoLights(&v11,
                                           (GfxLight *)(dword_1184B9C + 180));
  v8 = (_DWORD *)dword_1184B9C;
  v9 = dword_1184B9C + 224;
  *(_DWORD *)(dword_1184B9C + 224) = *(_DWORD *)(dword_1184B9C + 200);
  v8[57] = v8[51];
  result = v8[52];
  *(_DWORD *)(v9 + 8) = result;
  return result;
}

void __cdecl R_ResetSunLightParseParams() { return R_UpdateLightsFromDvars(); }

void __cdecl R_LoadWorld(char const *name, int *checksum) { UNIMPLEMENTED(); }

int marker_r_bsp;
void __cdecl R_CopyParseParamsToDvars(struct SunLightParseParams const *) {
  UNIMPLEMENTED();
}

void __cdecl R_GetNormalizedColorFromDvar(struct dvar_s const *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl R_CopyParseParamsFromDvars(struct SunLightParseParams *) {
  UNIMPLEMENTED();
}

void __cdecl R_InitDynamicData(void) { UNIMPLEMENTED(); }

R_ReleaseWorld() { UNIMPLEMENTED(); }

R_CreateWorldVertexBuffer(GfxWorldVertex *vertices, int vertexCount) {
  UNIMPLEMENTED();
}

R_ReloadWorld() { UNIMPLEMENTED(); }

R_ShutdownWorld() { UNIMPLEMENTED(); }
