enum GfxFogOffset __cdecl RB_FogOffset() {
  if (*(_BYTE *)(r_fog + 8))
    return *(_DWORD *)(backEndData + 2202860);
  else
    return 0;
}

void __cdecl RB_SetIteratorFog() { UNIMPLEMENTED(); }

int marker_rb_fog;
RB_UpdateFogColor(FogColorSrcEnum) { UNIMPLEMENTED(); }
