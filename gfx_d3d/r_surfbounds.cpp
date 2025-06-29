float const *__cdecl R_BoundsForSurf_StaticModelCached(
    struct GfxDrawSurf const *drawSurf, int entIndex) {
  return *(_DWORD *)(dword_1184B9C + 248) +
         96 * *(_DWORD *)(*(_DWORD *)(a1->surface + 8) + 4) + 20;
}

float const *__cdecl R_BoundsForSurf_ModelInst(
    struct GfxDrawSurf const *drawSurf, int entIndex) {
  return &scene + 13 * a2 + 374;
}

float const *__cdecl R_BoundsForDrawSurf(struct GfxDrawSurf const *surf) {
  int(__cdecl * v1)(const GfxDrawSurf *, int); // ebx
  unsigned int sort;                           // eax
  int v3;                                      // edx

  v1 = (int(__cdecl *)(const GfxDrawSurf *,
                       int))R_BoundsForDrawSurfTable[*(_DWORD *)a1->surface];
  if (!v1)
    return 0;
  sort = a1->sort;
  if (a1->sort < 0)
    v3 = (sort >> 19) & 0xFFF;
  else
    v3 = (unsigned __int16)sort >> 4;
  if (v3 >= 2048)
    v3 = 2046;
  return v1(a1, v3);
}

float const *__cdecl R_BoundsForSurf_Triangles(
    struct GfxDrawSurf const *drawSurf, int entIndex) {
  if (a2 > 2045)
    return (float *)(a1->surface + 4);
  GetRotatedBounds(a1->surface + 4, stru_1155004.entities + 116 * a2 + 60,
                   stru_1155004.entities + 116 * a2 + 20, surfBoundsGlob);
  return surfBoundsGlob;
}

float const *(__cdecl **R_BoundsForDrawSurfTable)(struct GfxDrawSurf const *,
                                                  int) {
  UNIMPLEMENTED();
}

int marker_r_surfbounds;
