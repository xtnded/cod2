void __cdecl Vec2Scale(float const *const, float, float *const) {
  UNIMPLEMENTED();
}

dvar_t *jump_height;
dvar_t *jump_stepSize;
dvar_t *jump_slowdownEnable;

void __cdecl Jump_ActivateSlowdown(playerState_t *ps) {
  if (!ps->pm_time) {
    ps->pm_flags |= 0x80000;
    ps->pm_time = 1800;
  }
}

bool __cdecl Jump_IsPlayerAboveMax(playerState_t *ps) {
  return ps->origin[2] >= ps->jumpOriginZ + jump_height->current.value;
}

bool __cdecl Jump_GetStepHeight(playerState_t *ps, const float *origin,
                                float *stepSize) {
  float height = ps->jumpOriginZ + jump_height->current.value;
  if (height <= origin[2]) {
    return false;
  }
  *stepSize = jump_stepSize->current.value;
  if (jump_stepSize->current.value + origin[2] > height) {
    *stepSize = height - origin[2];
  }
  return true;
}

void __cdecl Jump_ClearState(playerState_t *ps) {
  ps->pm_flags &= ~0x80000;
  ps->jumpOriginZ = 0.f;
}

void __cdecl Jump_ClampVelocity(playerState_t *ps, const float *origin) {
  if (ps->origin[2] - origin[2] != 0.0) {
    float heightDiff =
        ps->jumpOriginZ + jump_height->current.value - ps->origin[2];
    if (heightDiff >= 0.1f) {
      float velZ = sqrtf(heightDiff * 2.f * ps->gravity);
      if (ps->velocity[2] > velZ) {
        ps->velocity[2] = velZ;
      }
    } else {
      ps->velocity[2] = 0.f;
    }
  }
}

#define JUMP_TIME_CONSTANT (1800)

float __cdecl Jump_ReduceFriction(playerState_t *ps) {
  if (ps->pm_time > JUMP_TIME_CONSTANT) {
    Jump_ClearState(ps);
    return 1.f;
  }

  if (!jump_slowdownEnable->current.enabled) {
    return 1.f;
  }

  if (ps->pm_time >= JUMP_TIME_CONSTANT - 100) {
    return 2.5f;
  }
    float inv = 1.f / ((float)JUMP_TIME_CONSTANT) - 100.f);
    float fTime = (float)ps->pm_time;
    return fTime * 1.5f * inv + 1.f;
}

void __cdecl Jump_ApplySlowdown(playerState_t *ps) {
  float factor = 0.f;
  if (ps->pm_time <= JUMP_TIME_CONSTANT) {
    if (ps->pm_time != 0) {
      factor = 1.f;
    } else if (ps->jumpOriginZ + 18.f > ps->origin[2]) {
      ps->pm_time = JUMP_TIME_CONSTANT;
      factor = 0.65f;
    } else {
      ps->pm_time = 1200;
      factor = 0.5f;
    }
  } else {
    Jump_ClearState(ps);
    factor = 0.65f;
  }
  if (!jump_slowdownEnable->current.enabled) {
    factor = 1.f;
  }
  // replace with VectorScale?
  for (int i = 0; i < 3; ++i)
    ps->velocity[i] *= factor;
}

bool __cdecl Jump_Check(struct pmove_t *pm, struct pml_t *pml) {
  playerState_s *ps; // ebx
  uint32_t pm_flags; // eax
  int v5;            // eax
  int v6;            // eax
  int32_t v7;        // edx
  float v8;          // xmm1_4
  int v9;            // ecx
  float v10;         // xmm0_4
  float v11;         // xmm0_4
  unsigned int v12;  // eax
  float v13;         // edx
  float v14;         // xmm0_4
  float v15;         // xmm0_4
  float v16;         // [esp+18h] [ebp-20h] BYREF
  float v17;         // [esp+1Ch] [ebp-1Ch]
  float v18;         // [esp+20h] [ebp-18h]
  float v19;         // [esp+24h] [ebp-14h] BYREF
  float v20;         // [esp+28h] [ebp-10h]
  float v21;         // [esp+2Ch] [ebp-Ch]

  ps = (playerState_s *)a1->ps;
  if (*(_DWORD *)a1->cmd - *(_DWORD *)(a1->ps + 112) <= 499)
    return 0;
  pm_flags = ps->pm_flags;
  if ((pm_flags & 0x1000) != 0)
    return 0;
  if ((pm_flags & 4) != 0)
    return 0;
  if (ps->pm_type > 5)
    return 0;
  LOBYTE(v5) = PM_GetEffectiveStance((playerState_s *)a1->ps);
  if (v5)
    return 0;
  v6 = *(_DWORD *)&a1->cmd[4];
  if ((v6 & 0x400) == 0)
    return 0;
  if ((a1->oldcmd[5] & 4) != 0) {
    BYTE1(v6) &= ~4u;
    *(_DWORD *)&a1->cmd[4] = v6;
    return 0;
  } else {
    v7 = a1->ps;
    v8 = (float)(*(float *)(jump_height + 8) + *(float *)(jump_height + 8)) *
         (float)*(int *)(a1->ps + 72);
    if ((*(_BYTE *)(a1->ps + 14) & 8) != 0) {
      v9 = *(_DWORD *)(v7 + 16);
      if (v9 <= 1800) {
        if (*(_BYTE *)(jump_slowdownEnable + 8)) {
          if (v9 <= 1699)
            v10 = (float)((float)((float)v9 * 1.5) * 0.00058823527) + 1.0;
          else
            v10 = 2.5;
        } else {
          v10 = 1.0;
        }
        v8 = v8 / v10;
      }
    }
    a2->groundPlane = 0;
    a2->almostGroundPlane = 0;
    a2->walking = 0;
    *(_DWORD *)(v7 + 96) = 1023;
    *(_DWORD *)(v7 + 112) = *(_DWORD *)a1->cmd;
    *(_DWORD *)(v7 + 116) = *(_DWORD *)(v7 + 28);
    *(_DWORD *)(v7 + 12) |= 0x80000u;
    *(_DWORD *)(v7 + 16) = 0;
    *(float *)(v7 + 40) = fsqrt(v8);
    v11 = *(float *)(v7 + 1492) + *(float *)(jump_spreadAdd + 8);
    *(float *)(v7 + 1492) = v11;
    if (v11 > 255.0)
      *(_DWORD *)(v7 + 1492) = 1132396544;
    if ((ps->pm_flags & 0x20) != 0) {
      PM_AddEvent(ps, 91);
    } else {
      v12 = PM_GroundSurfaceType(a2);
      if (v12)
        PM_AddEvent(ps, v12 + 70);
    }
    if ((ps->pm_flags & 0x20) != 0) {
      ps->velocity[2] = 0.75 * ps->velocity[2];
      v13 = a2->forward[1];
      v16 = a2->forward[0];
      v17 = v13;
      v18 = 0.0;
      Vec3Normalize(&v16);
      if ((float)((float)((float)(ps->vLadderVec[0] * a2->forward[0]) +
                          (float)(ps->vLadderVec[1] * a2->forward[1])) +
                  (float)(ps->vLadderVec[2] * a2->forward[2])) < 0.0) {
        v15 = (float)((float)((float)(v16 * ps->vLadderVec[0]) +
                              (float)(ps->vLadderVec[1] * v17)) +
                      (float)(ps->vLadderVec[2] * v18)) *
              -2.0;
        v19 = v16 + (float)(v15 * ps->vLadderVec[0]);
        v20 = v17 + (float)(v15 * ps->vLadderVec[1]);
        v21 = v18 + (float)(v15 * ps->vLadderVec[2]);
        Vec3Normalize(&v19);
      } else {
        v19 = v16;
        v20 = v17;
        v21 = v18;
      }
      v14 = *(float *)(jump_ladderPushVel + 8);
      ps->velocity[0] = v14 * v19;
      ps->velocity[1] = v14 * v20;
      ps->pm_flags &= ~0x20u;
    }
    if (a1->cmd[24] < 0)
      BG_AnimScriptEvent(ps, ANIM_ET_JUMPBK, 0, 1);
    else
      BG_AnimScriptEvent(ps, ANIM_ET_JUMP, 0, 1);
    return 1;
  }
}

void __cdecl Jump_RegisterDvars() { UNIMPLEMENTED(); }

float __cdecl Jump_GetLandFactor(playerState_t *) { UNIMPLEMENTED(); }

float __cdecl Jump_GetSlowdownFriction(playerState_t *) { UNIMPLEMENTED(); }

void __cdecl Jump_AddSurfaceEvent(playerState_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl Jump_PushOffLadder(playerState_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl Jump_Start(struct pmove_t *, struct pml_t *, float) {
  UNIMPLEMENTED();
}
