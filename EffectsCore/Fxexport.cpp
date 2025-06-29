float __cdecl FX_GetEffectLength(struct EffectTemplate *fx) {
  FxScheduler::GetEffectLength(theFxScheduler, a1);
}

void __cdecl FX_AdjustTime(int) {
  int *result; // eax

  fx_camera_valid = 0;
  FxHelper::AdjustTime(theFxHelper, a1);
  privateEffectActiveCountBolt = effectActiveCountBolt;
  result = &privateEffectActiveCountNonBolt;
  privateEffectActiveCountNonBolt = effectActiveCountNonBolt;
  return result;
}

int __cdecl FX_GetBoneIndex(int entNum, unsigned int bone) {
  DObj_s *ClientDObj; // eax

  ClientDObj = Com_GetClientDObj(a1, 0);
  if (ClientDObj)
    return DObjGetBoneIndex(ClientDObj, a2);
  else
    return -1;
}

void __cdecl FX_SwitchToLocalClient(int) { UNIMPLEMENTED(); }

void __cdecl FX_AdjustCamera(struct refdef_s *refdef, float zfar) {
  FxHelper::AdjustCamera(theFxHelper, a1, a2);
  fx_camera_valid = 1;
}

void __cdecl FX_FreeActive() { return FX_Free(0); }

void __cdecl FX_FreeSystem() { return FX_Free(1u); }

int __cdecl FX_InitSystem(bool) { return FX_Init(a1); }

void __cdecl FX_PlayEntityEffect(struct EffectTemplate *, float const *const,
                                 float const (*const)[3],
                                 struct FxBoltInfo const *) {
  UNIMPLEMENTED();
}

void __cdecl FX_PlayEffect(struct EffectTemplate *fx, float const *const org,
                           float const *const fwd, float const *const up) {
  UNIMPLEMENTED();
}

void __cdecl FX_PlayEffect(struct EffectTemplate *, float const *const,
                           float const *const) {
  FxScheduler::PlayEffect(a1, theFxScheduler, a2, a3, a4, a5);
}

void __cdecl FX_PlaySimpleEffect(struct EffectTemplate *fx,
                                 float const *const org) {
  FxScheduler::PlayEffect(a1, theFxScheduler, a2, a3);
}

void __cdecl FX_WarpTime(int time) {
  return FxHelper::WarpTime(theFxHelper, a1);
}

int volatile fx_camera_valid;
int marker_Fxexport;
Server_SwitchToValidFxScheduler() { UNIMPLEMENTED(); }
