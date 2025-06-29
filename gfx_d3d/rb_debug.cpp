void __cdecl RB_DrawDebugPolys(void) { UNIMPLEMENTED(); }

void __cdecl RB_DrawDebug(struct GfxViewParms const *viewParms) {
  UNIMPLEMENTED();
}

int marker_rb_debug;
void __cdecl RB_SetPolyVert(float const *const, union GfxColor, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_AddPlumeStrings(struct GfxViewParms const *) {
  UNIMPLEMENTED();
}

void __cdecl RB_DrawPolyInteriors(void) { UNIMPLEMENTED(); }

int __cdecl RB_EndDebugLines(bool, int, struct GfxPointVertex const *const) {
  UNIMPLEMENTED();
}

int __cdecl RB_AddDebugLine(float const *const, float const *const,
                            float const *const, bool, int, int,
                            struct GfxPointVertex *const) {
  UNIMPLEMENTED();
}

void __cdecl RB_DrawDebugStrings(struct trDebugString_t *, int) {
  UNIMPLEMENTED();
}

void __cdecl RB_DrawDebugLines(struct trDebugLine_t *, int) { UNIMPLEMENTED(); }

void __cdecl RB_DrawPolyOutlines(void) { UNIMPLEMENTED(); }
