struct gentity_s *__cdecl fire_rocket(struct gentity_s *self,
                                      float *const start, float *const dir) {
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl fire_grenade(struct gentity_s *self,
                                       float *const start, float *const dir,
                                       int grenadeWPID, int time) {
  UNIMPLEMENTED();
}

void __cdecl G_ExplodeMissile(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl G_RunMissile(struct gentity_s *ent) { UNIMPLEMENTED(); }

float __cdecl G_RunMissile_GetPerturbation(float) { UNIMPLEMENTED(); }

void __cdecl G_RunMissile_Destabilize(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl G_MissileLandAngles(struct gentity_s *, struct trace_t *,
                                 float *const, int) {
  float v7;  // xmm0_4
  float v8;  // xmm1_4
  float v9;  // [esp+1Ch] [ebp-4Ch]
  float v10; // [esp+1Ch] [ebp-4Ch]
  float v11; // [esp+1Ch] [ebp-4Ch]
  float v12; // [esp+20h] [ebp-48h]
  float v13; // [esp+38h] [ebp-30h]
  int v14;   // [esp+3Ch] [ebp-2Ch]
  float v15; // [esp+40h] [ebp-28h]
  float v16; // [esp+44h] [ebp-24h]
  float v17; // [esp+4Ch] [ebp-1Ch]

  v14 = (int)(float)((float)(dword_193466C - dword_1934670) * *(float *)a2) +
        dword_1934670;
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 48), v14, (float *)a3);
  if (*(float *)(a2 + 12) > 0.1) {
    v15 = PitchForYawOnNormal(*(float *)(a3 + 4), (const float *)(a2 + 4));
    v16 = AngleSubtract(v15, *(float *)a3);
    v8 = fabs(v16);
    if (!a4) {
      *(_DWORD *)(a1 + 60) = *(_DWORD *)a3;
      *(_DWORD *)(a1 + 64) = *(_DWORD *)(a3 + 4);
      *(_DWORD *)(a1 + 68) = *(_DWORD *)(a3 + 8);
      *(_DWORD *)(a1 + 52) = v14;
      if (v8 >= 80.0) {
        v17 = *(float *)(a1 + 72);
        v11 = randomf();
        *(float *)(a1 + 72) =
            (float)((float)(v11 * 0.30000001) + 0.85000002) * v17;
      } else {
        v12 = *(float *)(a1 + 72);
        v9 = randomf();
        *(float *)(a1 + 72) =
            -(float)(v12 * (float)((float)(v9 * 0.30000001) + 0.85000002));
      }
    }
    v10 = AngleNormalize180(*(float *)a3);
    *(float *)a3 = v10;
    if (a4 || v8 < 45.0) {
      if (fabs(v10) > 90.0)
        *(float *)a3 = AngleNormalize360(v15 + 180.0);
      else
        *(float *)a3 = AngleNormalize360(v15);
    } else if (v8 >= 80.0) {
      *(float *)a3 = AngleNormalize360(v10);
    } else {
      *(float *)a3 = AngleNormalize360(v10 + (float)(v16 * 0.25));
    }
  } else if (!a4) {
    v13 = *(float *)(a1 + 72);
    v7 = (float)((rand() & 0x7F) - 63) + v13;
    *(float *)(a1 + 72) = AngleNormalize360(v7);
  }
}

int __cdecl G_BounceMissile(struct gentity_s *, struct trace_t *) {
  UNIMPLEMENTED();
}

void __cdecl G_RunMissile_CreateWaterSplash(struct gentity_s const *,
                                            struct trace_t const *) {
  UNIMPLEMENTED();
}

void __cdecl G_MissileTrace(struct trace_t *, float const *const,
                            float const *const, int, int) {
  UNIMPLEMENTED();
}

void __cdecl G_MissileTrace_IgnoreEntity(struct trace_t *, int,
                                         struct gentity_s const *,
                                         float const *const) {
  UNIMPLEMENTED();
}

void __cdecl G_MissileImpact(struct gentity_s *, struct trace_t *, float *const,
                             float *const) {
  UNIMPLEMENTED();
}
