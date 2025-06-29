float __cdecl abs(float) { UNIMPLEMENTED(); }

float __cdecl sqrt(float) { UNIMPLEMENTED(); }

int const __cdecl FloatIsNegative(float) { UNIMPLEMENTED(); }

int const __cdecl FloatSign(float) { UNIMPLEMENTED(); }

void __cdecl Vec2Add(float const *const, float const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl Vec2Sub(float const *const, float const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl Vec2Mad(float const *const, float, float const *const,
                     float *const) {
  UNIMPLEMENTED();
}

float __cdecl Vec2Dot(float const *const, float const *const) {
  UNIMPLEMENTED();
}

float __cdecl Vec2Length(float const *const) { UNIMPLEMENTED(); }

void __cdecl Vec3CrossWithUp(float const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl PM_SetProneMovementOverride(struct playerState_s *ps) {
  uint32_t result; // eax

  result = a1->pm_flags;
  if ((result & 1) != 0) {
    BYTE1(result) |= 8u;
    a1->pm_flags = result;
  }
  return result;
}

int __cdecl PM_GetViewHeightLerpTime(struct playerState_s const *ps,
                                     int iTarget, int bDown) {
  if (a2 == 11 || a2 == 40 && !a3)
    return 400;
  else
    return 200;
}

int __cdecl PM_GroundSurfaceType(struct pml_t *pml) {
  uint32_t surfaceFlags; // eax

  surfaceFlags = a1->groundTrace.surfaceFlags;
  if ((surfaceFlags & 0x2000) != 0)
    return 0;
  else
    return (surfaceFlags & 0x1F00000) >> 20;
}

float __cdecl PM_DamageScale_Walk(int) { UNIMPLEMENTED(); }

int __cdecl PM_GetEffectiveStance(struct playerState_s *ps) {
  int32_t viewHeightTarget; // eax

  viewHeightTarget = a1->viewHeightTarget;
  if (viewHeightTarget == 40)
    return 2;
  else
    return viewHeightTarget == 11;
}

void __cdecl PM_AddTouchEnt(struct pmove_t *, int) {
  signed int numtouch; // ebx
  pmove_t *v3;         // ecx
  int v4;              // edx
  int result;          // eax

  if (a2 != 1022) {
    numtouch = a1->numtouch;
    if (numtouch != 32) {
      if (numtouch <= 0) {
      LABEL_9:
        *(_DWORD *)&a1->touchents[4 * numtouch] = a2;
        a1->numtouch = numtouch + 1;
        return result;
      }
      if (a2 != *(_DWORD *)a1->touchents) {
        v3 = a1;
        v4 = 0;
        while (numtouch != ++v4) {
          result = *(_DWORD *)&v3->touchents[4];
          v3 = (pmove_t *)((char *)v3 + 4);
          if (a2 == result)
            return result;
        }
        goto LABEL_9;
      }
    }
  }
  return result;
}

void __cdecl PM_playerTrace(struct pmove_t *pm, struct trace_t *results,
                            float const *const start, float const *const mins,
                            float const *const maxs, float const *const end,
                            int passEntityNum, int contentMask) {
  int result;          // eax
  uint16_t entityNum;  // ax
  signed int numtouch; // ebx
  pmove_t *v7;         // ecx
  int v8;              // edx
  int v9;              // eax
  int v10;             // [esp+3Ch] [ebp-1Ch]

  result = ((int(__cdecl *)(
      float *, int, int))pmoveHandlers[3 * (unsigned __int8)a1->handler])(
      &a2->fraction, (int)a3, (int)a4);
  if (a2->startsolid && (a2->contents & 0x2000000) != 0) {
    entityNum = a2->entityNum;
    v10 = entityNum;
    if (entityNum == 1022)
      goto LABEL_10;
    numtouch = a1->numtouch;
    if (numtouch == 32)
      goto LABEL_10;
    if (numtouch > 0) {
      if (entityNum == *(_DWORD *)a1->touchents) {
      LABEL_10:
        a1->tracemask &= ~0x2000000u;
        return ((int(__cdecl *)(
            float *, int, int))pmoveHandlers[3 * (unsigned __int8)a1->handler])(
            &a2->fraction, (int)a3, (int)a4);
      }
      v7 = a1;
      v8 = 0;
      while (numtouch != ++v8) {
        v9 = *(_DWORD *)&v7->touchents[4];
        v7 = (pmove_t *)((char *)v7 + 4);
        if (v10 == v9)
          goto LABEL_10;
      }
    }
    *(_DWORD *)&a1->touchents[4 * numtouch] = v10;
    a1->numtouch = numtouch + 1;
    goto LABEL_10;
  }
  return result;
}

void __cdecl PM_trace(struct pmove_t *pm, struct trace_t *results,
                      float const *const start, float const *const mins,
                      float const *const maxs, float const *const end,
                      int passEntityNum, int contentMask) {
  return ((int(__cdecl *)(float *, int,
                          int))pmoveHandlers[3 * (unsigned __int8)a1->handler])(
      &a2->fraction, (int)a3, (int)a4);
}

int __cdecl PM_ShouldMakeFootsteps(struct pmove_t *pm) {
  int v1; // eax

  v1 = *(_DWORD *)(a1->ps + 244);
  return v1 != 40 && v1 != 11 && (*(_DWORD *)(a1->ps + 12) & 0x100) == 0 &&
         a1->xyspeed >= *(float *)(player_footstepsThreshhold + 8);
}

void __cdecl PM_AddEvent(struct playerState_s *ps, int newEvent) {
  return BG_AddPredictableEventToPlayerstate(a2, 0, a1);
}

float __cdecl BG_GetSpeed(struct playerState_s const *ps, int time) {
  if ((a1->pm_flags & 0x20) == 0)
    return fsqrt((float)(a1->velocity[0] * a1->velocity[0]) +
                 (float)(a1->velocity[1] * a1->velocity[1]));
  if ((signed int)(a2 - a1->jumpTime) <= 499)
    return 0.0;
  return a1->velocity[2];
}

void __cdecl PM_FootstepEvent(struct pmove_t *pm, struct pml_t *pml,
                              int iOldBobCycle, int iNewBobCycle,
                              int bFootStep) {
  int32_t ps;            // ebx
  char result;           // al
  uint32_t surfaceFlags; // eax
  int v8;                // eax
  float v9;              // xmm1_4
  float v10;             // xmm2_4
  __m128 v11;            // xmm1
  __int32 v12;           // xmm0_4
  __m128 v13;            // xmm1
  signed int numtouch;   // edi
  pmove_t *v15;          // ecx
  int v16;               // edx
  int v17;               // eax
  uint32_t v18;          // eax
  int v19;               // edx
  unsigned int v20;      // eax
  int v21;               // eax
  trace_t v22;           // [esp+38h] [ebp-60h] BYREF
  float v23;             // [esp+5Ch] [ebp-3Ch]
  float v24;             // [esp+60h] [ebp-38h]
  float v25;             // [esp+64h] [ebp-34h]
  float v26;             // [esp+68h] [ebp-30h]
  float v27;             // [esp+6Ch] [ebp-2Ch]
  unsigned __int32 v28;  // [esp+70h] [ebp-28h]
  float v29[9];          // [esp+74h] [ebp-24h] BYREF

  ps = a1->ps;
  result = a4 + 64;
  if ((((a4 + 64) ^ (a3 + 64)) & 0x80u) != 0) {
    if (*(_DWORD *)(ps + 96) != 1023) {
      result = a5;
      if (!a5)
        return result;
      surfaceFlags = a2->groundTrace.surfaceFlags;
      if ((surfaceFlags & 0x2000) == 0) {
        v20 = (surfaceFlags & 0x1F00000) >> 20;
        v19 = (unsigned __int8)v20;
        if ((_BYTE)v20) {
          v21 = *(_DWORD *)(ps + 12);
          if ((v21 & 1) != 0) {
            v8 = v19 + 47;
            return BG_AddPredictableEventToPlayerstate(v8, 0,
                                                       (playerState_s *)ps);
          }
          if ((v21 & 0x100) != 0 || *(float *)(ps + 76) != 0.0) {
            v8 = v19 + 24;
            return BG_AddPredictableEventToPlayerstate(v8, 0,
                                                       (playerState_s *)ps);
          }
        LABEL_26:
          v8 = v19 + 1;
          return BG_AddPredictableEventToPlayerstate(v8, 0,
                                                     (playerState_s *)ps);
        }
      }
      v8 = 0;
      return BG_AddPredictableEventToPlayerstate(v8, 0, (playerState_s *)ps);
    }
    result = a5;
    if (a5) {
      if ((*(_BYTE *)(ps + 12) & 0x20) != 0) {
        v9 = a1->mins[1];
        v29[0] = a1->mins[0] + 6.0;
        v29[1] = v9 + 6.0;
        v29[2] = 8.0;
        v10 = a1->maxs[1];
        v11 = (__m128)LODWORD(a1->maxs[2]);
        v26 = a1->maxs[0] - 6.0;
        v27 = v10 - 6.0;
        v12 = v11.i32[0];
        v13 = _mm_cmpge_ss(v11, (__m128)0x41000000u);
        v28 = _mm_andnot_ps(v13, (__m128)0x41000000u).u32[0] | v12 & v13.i32[0];
        v23 = (float)(*(float *)(ps + 100) * -31.0) + *(float *)(ps + 20);
        v24 = (float)(*(float *)(ps + 104) * -31.0) + *(float *)(ps + 24);
        v25 = (float)(-31.0 * *(float *)(ps + 108)) + *(float *)(ps + 28);
        ((void(__cdecl *)(float *, int,
                          int))pmoveHandlers[3 * (unsigned __int8)a1->handler])(
            &v22.fraction, ps + 20, (int)v29);
        if (!v22.startsolid || (v22.contents & 0x2000000) == 0)
          goto LABEL_20;
        if (v22.entityNum != 1022) {
          numtouch = a1->numtouch;
          if (numtouch != 32) {
            if (numtouch <= 0) {
            LABEL_31:
              *(_DWORD *)&a1->touchents[4 * numtouch] = v22.entityNum;
              a1->numtouch = numtouch + 1;
              goto LABEL_19;
            }
            if (*(_DWORD *)a1->touchents != v22.entityNum) {
              v15 = a1;
              v16 = 0;
              while (numtouch != ++v16) {
                v17 = *(_DWORD *)&v15->touchents[4];
                v15 = (pmove_t *)((char *)v15 + 4);
                if (v17 == v22.entityNum)
                  goto LABEL_19;
              }
              goto LABEL_31;
            }
          }
        }
      LABEL_19:
        a1->tracemask &= ~0x2000000u;
        ((void(__cdecl *)(float *, int,
                          int))pmoveHandlers[3 * (unsigned __int8)a1->handler])(
            &v22.fraction, ps + 20, (int)v29);
      LABEL_20:
        v18 = (v22.surfaceFlags & 0x1F00000) >> 20;
        v19 = (unsigned __int8)v18;
        if (v22.fraction != 1.0) {
          if (!(_BYTE)v18) {
            v8 = 22;
            return BG_AddPredictableEventToPlayerstate(v8, 0,
                                                       (playerState_s *)ps);
          }
          goto LABEL_26;
        }
        v8 = 22;
        return BG_AddPredictableEventToPlayerstate(v8, 0, (playerState_s *)ps);
      }
    }
  }
  return result;
}

void __cdecl PM_ClipVelocity(float const *const in, float const *const normal,
                             float *const out) {
  const float *result; // eax
  float v4;            // xmm2_4
  float v5;            // xmm1_4

  result = a2;
  v4 = (float)((float)(*a1 * *a2) + (float)(a1[1] * a2[1])) +
       (float)(a1[2] * a2[2]);
  v5 = -(float)((float)(fabs(v4) * -0.001) + v4);
  *a3 = *a1 + (float)(*a2 * v5);
  a3[1] = (float)(v5 * a2[1]) + a1[1];
  a3[2] = (float)(v5 * a2[2]) + a1[2];
  return result;
}

void __cdecl PM_UpdateLean(struct playerState_s * ps, float msec, struct usercmd_s * cmd, void  capsuleTrace)(struct trace_t *,float const * const,float const * const,float const * const,float const * const,int,int))
{
  UNIMPLEMENTED();
}

void __cdecl PM_UpdatePronePitch(struct pmove_t *pm, struct pml_t *pml) {
  int32_t ps;     // ebx
  long double v3; // fst7
  long double v4; // fst7
  float *normal;  // edx
  float v6;       // [esp+0h] [ebp-58h]
  float v7;       // [esp+0h] [ebp-58h]
  float v8;       // [esp+4Ch] [ebp-Ch]
  float v9;       // [esp+4Ch] [ebp-Ch]

  ps = a1->ps;
  if ((*(_BYTE *)(a1->ps + 12) & 1) == 0)
    return;
  if (*(_DWORD *)(ps + 96) == 1023) {
    if (a2->groundPlane)
      normal = a2->groundTrace.normal;
    else
      normal = 0;
    if (!BG_CheckProne(*(_DWORD *)(ps + 204), (const float *)(ps + 20),
                       *(float *)(ps + 1400), 30.0, *(float *)(ps + 1412),
                       (float *)(ps + 1448), (float *)(ps + 1452),
                       (float *)(ps + 1456), 1, 0, normal, a1->handler,
                       PCT_CLIENT, 66.0)) {
      BG_AddPredictableEventToPlayerstate(141, 0, (playerState_s *)ps);
      *(_DWORD *)(ps + 12) |= 0x10000u;
    }
  LABEL_21:
    if (a2->groundPlane)
      goto LABEL_5;
  LABEL_22:
    v3 = 0.0;
    goto LABEL_6;
  }
  if (!a2->groundPlane)
    goto LABEL_22;
  if (a2->groundTrace.normal[2] < 0.69999999) {
    BG_AddPredictableEventToPlayerstate(141, 0, (playerState_s *)a1->ps);
    goto LABEL_21;
  }
LABEL_5:
  v3 = PitchForYawOnNormal(*(float *)(ps + 1412), a2->groundTrace.normal);
LABEL_6:
  v6 = v3;
  v8 = AngleDelta(v6, *(float *)(ps + 1416));
  if (v8 != 0.0) {
    if (fabs(v8) <= (float)(70.0 * *(float *)&a2->frametime))
      *(float *)(ps + 1416) = v8 + *(float *)(ps + 1416);
    else
      *(float *)(ps + 1416) = (float)((float)(70.0 * *(float *)&a2->frametime) *
                                      (float)(-2 * (v8 < 0.0) + 1)) +
                              *(float *)(ps + 1416);
    *(float *)(ps + 1416) = AngleNormalize180Accurate(*(float *)(ps + 1416));
  }
  if (a2->groundPlane)
    v4 = PitchForYawOnNormal(*(float *)(ps + 236), a2->groundTrace.normal);
  else
    v4 = 0.0;
  v7 = v4;
  v9 = AngleDelta(v7, *(float *)(ps + 1420));
  if (v9 != 0.0) {
    if (fabs(v9) <= (float)(70.0 * *(float *)&a2->frametime))
      *(float *)(ps + 1420) = v9 + *(float *)(ps + 1420);
    else
      *(float *)(ps + 1420) = (float)((float)(70.0 * *(float *)&a2->frametime) *
                                      (float)(-2 * (v9 < 0.0) + 1)) +
                              *(float *)(ps + 1420);
    *(float *)(ps + 1420) = AngleNormalize180Accurate(*(float *)(ps + 1420));
  }
}

void __cdecl PM_UpdateViewAngles(struct playerState_s *ps, float msec,
                                 struct usercmd_s *cmd, unsigned char handler) {
  usercmd_s *v4;                 // ecx
  playerState_s *v5;             // edx
  int v6;                        // ebx
  int v7;                        // eax
  uint32_t pm_flags;             // edx
  int32_t pm_type;               // eax
  float v10;                     // xmm0_4
  float v11;                     // xmm2_4
  _BOOL4 v12;                    // ebx
  float v13;                     // xmm1_4
  float v14;                     // xmm0_4
  float v15;                     // xmm1_4
  float v16;                     // xmm1_4
  int v17;                       // edi
  double *p_viewAngleClampRange; // ebx
  float v19;                     // xmm2_4
  float v20;                     // xmm1_4
  float v21;                     // xmm1_4
  float v22;                     // xmm1_4
  float v23;                     // xmm0_4
  unsigned __int8 v24;           // al
  _BOOL4 v25;                    // edi
  float v26;                     // xmm0_4
  long double v27;               // fst7
  int v28;                       // ebx
  float v29;                     // xmm0_4
  float v30;                     // xmm2_4
  float v31;                     // xmm1_4
  float v32;                     // xmm1_4
  float v33;                     // [esp+4h] [ebp-D4h]
  int v34;                       // [esp+4Ch] [ebp-8Ch]
  float v35;                     // [esp+5Ch] [ebp-7Ch]
  float v36;                     // [esp+5Ch] [ebp-7Ch]
  float v37;                     // [esp+5Ch] [ebp-7Ch]
  float v38;                     // [esp+5Ch] [ebp-7Ch]
  float v39;                     // [esp+5Ch] [ebp-7Ch]
  float v40;                     // [esp+5Ch] [ebp-7Ch]
  float v41;                     // [esp+5Ch] [ebp-7Ch]
  float v42;                     // [esp+5Ch] [ebp-7Ch]
  float v43;                     // [esp+5Ch] [ebp-7Ch]
  float v44;                     // [esp+5Ch] [ebp-7Ch]
  float v45;                     // [esp+60h] [ebp-78h]
  int v46;                       // [esp+88h] [ebp-50h]
  const float *origin;           // [esp+8Ch] [ebp-4Ch]
  float v48;                     // [esp+A0h] [ebp-38h]
  float v49;                     // [esp+A4h] [ebp-34h]
  float v50;                     // [esp+A8h] [ebp-30h]
  int v51;                       // [esp+ACh] [ebp-2Ch]
  float v52;                     // [esp+B0h] [ebp-28h]
  int v53;                       // [esp+B4h] [ebp-24h]
  float v54;                     // [esp+BCh] [ebp-1Ch]

  if (a1->pm_type == 5)
    return;
  if (a1->pm_type > 5) {
    if (*(_DWORD *)&a1->stats[4] == 999)
      *(_DWORD *)&a1->stats[4] =
          (int)(float)((float)(__int16)(LOWORD(a3->angles[1]) +
                                        LODWORD(a1->delta_angles[1])) *
                       0.0054931641);
    goto LABEL_18;
  }
  v49 = a1->viewangles[1];
  v53 = (unsigned __int16)(int)(float)(*(float *)(player_view_pitch_up + 8) *
                                       182.04445);
  v34 = (unsigned __int16)(int)(float)(182.04445 *
                                       *(float *)(player_view_pitch_down + 8));
  v4 = a3;
  v5 = a1;
  v6 = 0;
  v46 = -v53;
  do {
    LOWORD(v7) = LOWORD(v4->angles[0]) + LODWORD(v5->delta_angles[0]);
    if (v6)
      goto LABEL_21;
    v7 = (__int16)v7;
    if (v34 < (__int16)v7) {
      LODWORD(a1->delta_angles[0]) = v34 - LODWORD(a3->angles[0]);
      v7 = (__int16)v34;
      goto LABEL_7;
    }
    if ((__int16)v7 < v46) {
      LODWORD(a1->delta_angles[0]) = v46 - LODWORD(a3->angles[0]);
      v7 = -v53;
    LABEL_21:
      v7 = (__int16)v7;
    }
  LABEL_7:
    v5->viewangles[0] = (float)v7 * 0.0054931641;
    ++v6;
    v4 = (usercmd_s *)((char *)v4 + 4);
    v5 = (playerState_s *)((char *)v5 + 4);
  } while (v6 != 3);
  v50 = a1->viewangles[1];
  if ((a1->eFlags & 0x300) != 0) {
    v17 = 0;
    p_viewAngleClampRange = &a1->viewAngleClampRange;
    v39 = AngleDelta(*(float *)&a1->viewAngleClampBase, a1->viewangles[0]);
    v19 = v39;
    v20 = *(float *)&a1->viewAngleClampRange;
    if (v39 > v20)
      goto LABEL_51;
  LABEL_45:
    if ((float)-v20 > v19) {
      v21 = v20 + v19;
      goto LABEL_47;
    }
    while (1) {
      ++v17;
      p_viewAngleClampRange = (double *)((char *)p_viewAngleClampRange + 4);
      if (v17 == 2)
        return;
      v40 = AngleDelta(*((float *)p_viewAngleClampRange - 2),
                       *((float *)p_viewAngleClampRange - 11));
      v19 = v40;
      v20 = *(float *)p_viewAngleClampRange;
      if (v40 <= *(float *)p_viewAngleClampRange)
        goto LABEL_45;
    LABEL_51:
      v21 = v19 - v20;
    LABEL_47:
      *((_DWORD *)p_viewAngleClampRange - 48) +=
          (unsigned __int16)(int)(float)(v21 * 182.04445);
      if (v21 <= 0.0)
        *((float *)p_viewAngleClampRange - 11) =
            AngleNormalize360Accurate(*((float *)p_viewAngleClampRange - 2) +
                                      *(float *)p_viewAngleClampRange);
      else
        *((float *)p_viewAngleClampRange - 11) =
            AngleNormalize360Accurate(*((float *)p_viewAngleClampRange - 2) -
                                      *(float *)p_viewAngleClampRange);
    }
  }
  pm_flags = a1->pm_flags;
  if ((pm_flags & 4) != 0) {
    Mantle_CapView(a1);
    return;
  }
  if ((pm_flags & 0x20) != 0 && a1->groundEntityNum == 1023 &&
      *(float *)(bg_ladder_yawcap + 8) != 0.0) {
    v37 = vectoyaw(a1->vLadderVec);
    v45 = v37 + 180.0;
    v38 = AngleDelta(v37 + 180.0, a1->viewangles[1]);
    v15 = *(float *)(bg_ladder_yawcap + 8);
    if (v38 > v15) {
      v16 = v38 - v15;
    LABEL_42:
      LODWORD(a1->delta_angles[1]) +=
          (unsigned __int16)(int)(float)(v16 * 182.04445);
      if (v16 <= 0.0) {
        a1->viewangles[1] =
            AngleNormalize360Accurate(v45 + *(float *)(bg_ladder_yawcap + 8));
        goto LABEL_96;
      }
      a1->viewangles[1] =
          AngleNormalize360Accurate(v45 - *(float *)(bg_ladder_yawcap + 8));
      pm_flags = a1->pm_flags;
    } else {
      if ((float)-v15 > v38) {
        v16 = v15 + v38;
        goto LABEL_42;
      }
    LABEL_96:
      pm_flags = a1->pm_flags;
    }
  }
  if ((pm_flags & 1) != 0 && (a1->eFlags & 0x300) == 0) {
    v35 = AngleDelta(*(float *)&a1->proneDirection, a1->viewangles[1]);
    v10 = *(float *)(bg_prone_yawcap + 8) - 5.0;
    if (v35 <= v10 && (float)-v10 <= v35 &&
        (!*(_WORD *)&a3->forwardmove || v35 == 0.0)) {
      v51 = 0;
    } else {
      v11 = (float)(a2 * 55.0) * 0.001;
      if (v11 <= fabs(v35)) {
        if (v35 <= 0.0)
          v48 = v11 + *(float *)&a1->proneDirection;
        else
          v48 = (float)((float)(a2 * 55.0) * -0.001) +
                *(float *)&a1->proneDirection;
      } else {
        v48 = a1->viewangles[1];
      }
      v51 = 0;
      v12 = 1;
      origin = a1->origin;
      while (!BG_CheckProneTurned((int)a1, a4, v48)) {
        if (!v12)
          goto LABEL_56;
        v36 = AngleDelta(*(float *)&a1->proneDirection, v48);
        v13 = v36;
        v14 = fabs(v36);
        v12 = v14 > 1.0;
        if (v14 > 1.0) {
          if (v36 <= 0.0)
            v13 = -1.0;
          else
            v13 = 1.0;
        } else {
          v51 = 1;
        }
        v48 = AngleNormalize360Accurate(v13 + v48);
      }
      if (BG_CheckProne(a1->clientNum, origin, a1->maxs[0], 30.0,
                        a1->viewangles[1], 0, 0, 0, 1,
                        a1->groundEntityNum != 1023, 0, a4, PCT_CLIENT, 45.0) &&
          BG_CheckProne(a1->clientNum, origin, a1->maxs[0], 30.0, v48, 0, 0, 0,
                        1, a1->groundEntityNum != 1023, 0, a4, PCT_CLIENT,
                        45.0)) {
        *(float *)&a1->proneDirection = v48;
      } else {
        v51 = 1;
      }
    }
  LABEL_56:
    v41 = AngleDelta(*(float *)&a1->proneDirection, a1->viewangles[1]);
    v22 = v41;
    if (v41 != 0.0) {
      v23 = *(float *)&a1->proneDirection;
      v54 = v23;
      v24 = a4;
      v25 = 1;
      while (1) {
        v28 = BG_CheckProne(a1->clientNum, a1->origin, a1->maxs[0], 30.0, v23,
                            0, 0, 0, 1, a1->groundEntityNum != 1023, 0, v24,
                            PCT_CLIENT, 45.0);
        if (v28) {
          if (BG_CheckProneTurned((int)a1, a4, v54))
            break;
        }
        if (!v25)
          goto LABEL_69;
        v29 = fabs(v22);
        v25 = v29 > 1.0;
        if (v29 > 1.0) {
          if (v22 <= 0.0) {
            v22 = -1.0;
            v26 = -182.04445;
          } else {
            v22 = 1.0;
            v26 = 182.04445;
          }
        } else {
          v26 = v22 * 182.04445;
        }
        LODWORD(a1->delta_angles[1]) += (unsigned __int16)(int)v26;
        v27 = AngleNormalize360Accurate(v22 + a1->viewangles[1]);
        a1->viewangles[1] = v27;
        v33 = v27;
        v42 = AngleDelta(*(float *)&a1->proneDirection, v33);
        v22 = v42;
        if (!v28) {
          v54 = AngleNormalize360Accurate(v54 + v42);
          v22 = v42;
        }
        v51 = 1;
        v24 = a4;
        v23 = v54;
      }
      *(float *)&a1->proneDirection = v54;
    }
  LABEL_69:
    v30 = *(float *)(bg_prone_yawcap + 8);
    if (v22 > v30) {
      v31 = v22 - v30;
      goto LABEL_72;
    }
    if ((float)-v30 > v22) {
      v31 = v22 + v30;
    LABEL_72:
      LODWORD(a1->delta_angles[1]) +=
          (unsigned __int16)(int)(float)(v31 * 182.04445);
      if (v31 <= 0.0)
        a1->viewangles[1] = AngleNormalize360Accurate(
            *(float *)&a1->proneDirection + *(float *)(bg_prone_yawcap + 8));
      else
        a1->viewangles[1] = AngleNormalize360Accurate(
            *(float *)&a1->proneDirection - *(float *)(bg_prone_yawcap + 8));
    }
    if (v51) {
      a1->pm_flags |= 0x10000u;
      v52 = AngleDelta(v49, a1->viewangles[1]);
      if (fabs(v52) <= 1.0) {
        v44 = AngleDelta(v50, a1->viewangles[1]);
        if ((float)(v44 * v52) > 0.0) {
          a1->viewangles[1] = AngleNormalize360Accurate(
              (float)(v52 * 0.98000002) + a1->viewangles[1]);
          LODWORD(a1->delta_angles[1]) +=
              (unsigned __int16)(int)(float)((float)(v52 * 0.98000002) *
                                             182.04445);
        }
      }
    }
    v43 = AngleDelta(*(float *)&a1->proneTorsoPitch, a1->viewangles[0]);
    if (v43 > 45.0) {
      v32 = v43 - 45.0;
      goto LABEL_78;
    }
    if (v43 < -45.0) {
      v32 = v43 + 45.0;
    LABEL_78:
      LODWORD(a1->delta_angles[0]) +=
          (unsigned __int16)(int)(float)(v32 * 182.04445);
      if (v32 <= 0.0)
        a1->viewangles[0] =
            AngleNormalize180Accurate(*(float *)&a1->proneTorsoPitch + 45.0);
      else
        a1->viewangles[0] =
            AngleNormalize180Accurate(*(float *)&a1->proneTorsoPitch - 45.0);
    }
  }
  pm_type = a1->pm_type;
  if (pm_type != 3 && pm_type != 2 && pm_type != 4)
  LABEL_18:
    PM_UpdateLean(
        a1, a2, a3,
        (void (*)(trace_t *, const float *, const float *, const float *,
                  const float *, int, int))pmoveHandlers[3 * a4]);
}

void __cdecl Pmove(struct pmove_t *pm) { UNIMPLEMENTED(); }

struct pmoveHandler_t *pmoveHandlers;
int marker_bg_pmove;
void __cdecl PM_ClearLadderFlag(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_SetLadderFlag(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_UpdatePlayerWalkingFlag(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl PM_DropTimers(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

int __cdecl PM_GetFlinchAnim(float) { UNIMPLEMENTED(); }

float __cdecl PM_ViewHeightTableLerp(int, struct viewLerpWaypoint_s *,
                                     float *) {
  UNIMPLEMENTED();
}

float __cdecl PM_GetViewHeightLerp(struct pmove_t *, int, int) {
  UNIMPLEMENTED();
}

int __cdecl PM_CorrectAllSolid(struct pmove_t *, struct pml_t *,
                               struct trace_t *) {
  UNIMPLEMENTED();
}

int __cdecl PM_DamageLandingForSurface(struct pml_t *) { UNIMPLEMENTED(); }

int __cdecl PM_HardLandingForSurface(struct pml_t *) { UNIMPLEMENTED(); }

int __cdecl PM_MediumLandingForSurface(struct pml_t *) { UNIMPLEMENTED(); }

int __cdecl PM_LightLandingForSurface(struct pml_t *) { UNIMPLEMENTED(); }

int __cdecl PM_FootstepForSurface(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

float __cdecl PM_CmdScale(struct playerState_s *, struct usercmd_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_FoliageSounds(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl PM_DeadMove(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_SetMovementDir(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

float __cdecl PM_MoveScale(struct playerState_s *, float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl PM_Friction(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_CheckLadderMove(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Footsteps(struct pmove_t *, struct pml_t *) { UNIMPLEMENTED(); }

void __cdecl PM_GroundTraceMissed(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

float __cdecl PM_CmdScale_Walk(struct pmove_t *, struct usercmd_s *) {
  UNIMPLEMENTED();
}

int __cdecl BG_CheckProneTurned(struct playerState_s *, float, unsigned char) {
  UNIMPLEMENTED();
}

void __cdecl PM_ViewHeightAdjust(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_CheckDuck(struct pmove_t *, struct pml_t *) {
  int32_t ps;      // edi
  int v5;          // eax
  int v6;          // eax
  unsigned int v7; // eax
  float fraction;  // xmm2_4
  int v9;          // eax
  int v10;         // eax
  int v11;         // edx
  int v12;         // eax
  int v13;         // eax
  int v14;         // [esp+44h] [ebp-74h]
  float v15;       // [esp+50h] [ebp-68h]
  trace_t v16;     // [esp+64h] [ebp-54h] BYREF
  float v17;       // [esp+88h] [ebp-30h] BYREF
  float v18;       // [esp+8Ch] [ebp-2Ch]
  float v19;       // [esp+90h] [ebp-28h]
  float v20;       // [esp+94h] [ebp-24h]
  int v21;         // [esp+98h] [ebp-20h]
  float v22;       // [esp+9Ch] [ebp-1Ch]

  ps = a1->ps;
  a1->proneChange = 0;
  if (*(_DWORD *)(ps + 4) != 4) {
    v14 = *(_DWORD *)(ps + 12) & 1;
    a1->mins[0] = *(float *)(ps + 1388);
    a1->mins[1] = *(float *)(ps + 1392);
    a1->maxs[0] = *(float *)(ps + 1400);
    a1->maxs[1] = *(float *)(ps + 1404);
    a1->mins[2] = *(float *)(ps + 1396);
    if (*(int *)(ps + 4) > 5) {
      a1->maxs[2] = *(float *)(ps + 1408);
      *(_DWORD *)(ps + 244) = 8;
      PM_ViewHeightAdjust(a1, a2);
      return;
    }
    v5 = *(_DWORD *)(ps + 160);
    if ((v5 & 0x300) != 0) {
      if ((v5 & 0x100) == 0) {
        if ((v5 & 0x200) != 0) {
          *(_DWORD *)(ps + 12) = *(_DWORD *)(ps + 12) & 0xFFFFFFFC | 2;
        LABEL_7:
          if (!*(_DWORD *)(ps + 252)) {
            if ((*(_DWORD *)(ps + 12) & 1) != 0) {
              v13 = *(_DWORD *)(ps + 244);
              if (v13 == 60) {
                *(_DWORD *)(ps + 244) = 40;
              } else if (v13 != 11) {
                *(_DWORD *)(ps + 244) = 11;
                a1->proneChange = 1;
                BG_PlayAnim((playerState_s *)ps, 0, ANIM_BP_TORSO, 0, 0, 1, 1);
                Jump_ActivateSlowdown((playerState_s *)ps);
              }
            } else if (*(_DWORD *)(ps + 244) == 11) {
              *(_DWORD *)(ps + 244) = 40;
              a1->proneChange = 1;
              BG_PlayAnim((playerState_s *)ps, 0, ANIM_BP_TORSO, 0, 0, 1, 1);
            } else {
              *(_DWORD *)(ps + 244) = (*(_DWORD *)(ps + 12) & 2) == 0 ? 60 : 40;
            }
          }
          PM_ViewHeightAdjust(a1, a2);
          v6 = *(_DWORD *)(ps + 244);
          if (v6 == 40) {
            a1->maxs[2] = 50.0;
            *(_DWORD *)(ps + 160) = *(_DWORD *)(ps + 160) & 0xFFFFFFF3 | 4;
            v7 = *(_DWORD *)(ps + 12) & 0xFFFFFFFC | 2;
            *(_DWORD *)(ps + 12) = v7;
          } else {
            if (v6 == 11) {
              a1->maxs[2] = 30.0;
              *(_DWORD *)(ps + 160) = *(_DWORD *)(ps + 160) & 0xFFFFFFF3 | 8;
              v7 = *(_DWORD *)(ps + 12) & 0xFFFFFFFC | 1;
            } else {
              a1->maxs[2] = *(float *)(ps + 1408);
              *(_DWORD *)(ps + 160) &= 0xFFFFFFF3;
              v7 = *(_DWORD *)(ps + 12) & 0xFFFFFFFC;
            }
            *(_DWORD *)(ps + 12) = v7;
          }
          if ((v7 & 1) != 0 && !v14) {
            if (*(_WORD *)&a1->cmd[24]) {
              BYTE1(v7) &= ~8u;
              *(_DWORD *)(ps + 12) = v7;
              PM_ExitAimDownSight((playerState_s *)ps);
            }
            v17 = *(float *)(ps + 20);
            v18 = *(float *)(ps + 24);
            v19 = *(float *)(ps + 28) + 10.0;
            ((void(__cdecl *)(float *, int, int))
                 pmoveHandlers[3 * (unsigned __int8)a1->handler])(
                &v16.fraction, ps + 20, (int)a1->mins);
            v17 = *(float *)(ps + 20) +
                  (float)((float)(v17 - *(float *)(ps + 20)) * v16.fraction);
            v18 = *(float *)(ps + 24) +
                  (float)((float)(v18 - *(float *)(ps + 24)) * v16.fraction);
            v19 = *(float *)(ps + 28) +
                  (float)(v16.fraction * (float)(v19 - *(float *)(ps + 28)));
            ((void(__cdecl *)(float *, int, int))
                 pmoveHandlers[3 * (unsigned __int8)a1->handler])(
                &v16.fraction, (int)&v17, (int)a1->mins);
            fraction = v16.fraction;
            *(float *)(ps + 20) =
                v17 +
                (float)((float)(*(float *)(ps + 20) - v17) * v16.fraction);
            *(float *)(ps + 24) =
                v18 + (float)((float)(*(float *)(ps + 24) - v18) * fraction);
            *(float *)(ps + 28) =
                v19 + (float)(fraction * (float)(*(float *)(ps + 28) - v19));
            *(_DWORD *)(ps + 1412) = *(_DWORD *)(ps + 236);
            v20 = *(float *)(ps + 20);
            v21 = *(_DWORD *)(ps + 24);
            v22 = *(float *)(ps + 28) - 0.25;
            ((void(__cdecl *)(float *, int, int))
                 pmoveHandlers[3 * (unsigned __int8)a1->handler])(
                &v16.fraction, ps + 20, (int)a1->mins);
            if (v16.startsolid || v16.fraction >= 1.0)
              *(_DWORD *)(ps + 1416) = 0;
            else
              *(float *)(ps + 1416) =
                  PitchForYawOnNormal(*(float *)(ps + 1412), v16.normal);
            v15 = AngleDelta(*(float *)(ps + 1416), *(float *)(ps + 232));
            if (v15 >= -45.0) {
              if (v15 <= 45.0)
                *(_DWORD *)(ps + 1420) = *(_DWORD *)(ps + 1416);
              else
                *(float *)(ps + 1420) = *(float *)(ps + 232) + 45.0;
            } else {
              *(float *)(ps + 1420) = *(float *)(ps + 232) - 45.0;
            }
          }
          return;
        }
      LABEL_49:
        *(_DWORD *)(ps + 12) &= 0xFFFFFFFC;
        goto LABEL_7;
      }
      if ((v5 & 0x200) != 0)
        goto LABEL_49;
      goto LABEL_43;
    }
    v10 = *(_DWORD *)(ps + 12);
    if ((v10 & 0x8000u) != 0)
      goto LABEL_7;
    if ((v10 & 0x20) != 0) {
      v11 = *(_DWORD *)&a1->cmd[4];
      if ((v11 & 0x300) == 0) {
      LABEL_31:
        if ((v11 & 0x100) == 0) {
          if ((v11 & 0x200) != 0) {
            if ((v10 & 1) != 0) {
              a1->maxs[2] = 50.0;
              ((void(__cdecl *)(float *, int, int))
                   pmoveHandlers[3 * (unsigned __int8)a1->handler])(
                  &v16.fraction, ps + 20, (int)a1->mins);
              if (v16.allsolid) {
                if ((a1->cmd[5] & 0x20) == 0)
                  BG_AddPredictableEventToPlayerstate(142, 2u,
                                                      (playerState_s *)ps);
              } else {
                BG_AnimScriptEvent((playerState_s *)ps, ANIM_ET_PRONE_TO_CROUCH,
                                   0, 0);
                *(_DWORD *)(ps + 12) = *(_DWORD *)(ps + 12) & 0xFFFFFFFC | 2;
              }
            } else {
              BG_AnimScriptEvent((playerState_s *)ps, ANIM_ET_STAND_TO_CROUCH,
                                 0, 0);
              *(_DWORD *)(ps + 12) |= 2u;
            }
            goto LABEL_7;
          }
          if ((v10 & 1) == 0) {
            if ((v10 & 2) != 0) {
              a1->maxs[2] = *(float *)(ps + 1408);
              ((void(__cdecl *)(float *, int, int))
                   pmoveHandlers[3 * (unsigned __int8)a1->handler])(
                  &v16.fraction, ps + 20, (int)a1->mins);
              if (v16.allsolid) {
                if ((a1->cmd[5] & 0x20) == 0)
                  BG_AddPredictableEventToPlayerstate(141, 1u,
                                                      (playerState_s *)ps);
              } else {
                BG_AnimScriptEvent((playerState_s *)ps, ANIM_ET_CROUCH_TO_STAND,
                                   0, 0);
                *(_DWORD *)(ps + 12) &= ~2u;
              }
            }
            goto LABEL_7;
          }
          a1->maxs[2] = *(float *)(ps + 1408);
          ((void(__cdecl *)(float *, int, int))
               pmoveHandlers[3 * (unsigned __int8)a1->handler])(
              &v16.fraction, ps + 20, (int)a1->mins);
          if (v16.allsolid) {
            a1->maxs[2] = 50.0;
            ((void(__cdecl *)(float *, int, int))
                 pmoveHandlers[3 * (unsigned __int8)a1->handler])(
                &v16.fraction, ps + 20, (int)a1->mins);
            if (v16.allsolid) {
              if ((a1->cmd[5] & 0x20) == 0)
                BG_AddPredictableEventToPlayerstate(142, 1u,
                                                    (playerState_s *)ps);
            } else {
              *(_DWORD *)(ps + 12) = *(_DWORD *)(ps + 12) & 0xFFFFFFFC | 2;
            }
            goto LABEL_7;
          }
          BG_AnimScriptEvent((playerState_s *)ps, ANIM_ET_PRONE_TO_STAND, 0, 0);
          goto LABEL_49;
        }
        if ((v10 & 1) != 0) {
        LABEL_44:
          *(_DWORD *)(ps + 12) = v10 & 0xFFFFFFFC | 1;
          goto LABEL_7;
        }
        if (*(_DWORD *)(ps + 96) == 1023)
          goto LABEL_7;
        if (!BG_CheckProne(*(_DWORD *)(ps + 204), (const float *)(ps + 20),
                           a1->maxs[0], 30.0, *(float *)(ps + 236),
                           (float *)(ps + 1448), (float *)(ps + 1452),
                           (float *)(ps + 1456), 0, 1, 0, a1->handler,
                           PCT_CLIENT, 66.0)) {
          if (*(_DWORD *)(ps + 96) != 1023) {
            v12 = *(_DWORD *)(ps + 12) | 0x10000;
            *(_DWORD *)(ps + 12) = v12;
            if ((a1->cmd[5] & 0x20) == 0) {
              if ((v12 & 2) != 0)
                BG_AddPredictableEventToPlayerstate(141, 0,
                                                    (playerState_s *)ps);
              else
                BG_AddPredictableEventToPlayerstate(140, 0,
                                                    (playerState_s *)ps);
            }
          }
          goto LABEL_7;
        }
      LABEL_43:
        v10 = *(_DWORD *)(ps + 12);
        goto LABEL_44;
      }
      BYTE1(v11) &= 0xFCu;
      *(_DWORD *)&a1->cmd[4] = v11;
      BG_AddPredictableEventToPlayerstate(140, 0, (playerState_s *)ps);
      v10 = *(_DWORD *)(ps + 12);
    }
    v11 = *(_DWORD *)&a1->cmd[4];
    goto LABEL_31;
  }
  a1->mins[0] = -8.0;
  a1->mins[1] = -8.0;
  a1->mins[2] = -8.0;
  a1->maxs[0] = 8.0;
  a1->maxs[1] = 8.0;
  a1->maxs[2] = 16.0;
  *(_DWORD *)(ps + 12) &= 0xFFFFFFFC;
  v9 = *(_DWORD *)&a1->cmd[4];
  if ((v9 & 0x100) != 0) {
    BYTE1(v9) &= ~1u;
    *(_DWORD *)&a1->cmd[4] = v9;
    BG_AddPredictableEventToPlayerstate(140, 0, (playerState_s *)ps);
  }
  *(_DWORD *)(ps + 244) = 0;
  *(_DWORD *)(ps + 248) = 0;
}

void __cdecl PM_CrashLand(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

bool __cdecl PM_DoPlayerInertia(struct playerState_s *, float, float *const) {
  UNIMPLEMENTED();
}

void __cdecl PM_GroundTrace(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

float __cdecl PM_PlayerInertia(struct playerState_s *, float, float *const) {
  UNIMPLEMENTED();
}

void __cdecl PM_Accelerate(struct playerState_s *, struct pml_t *, float *const,
                           float, float) {
  UNIMPLEMENTED();
}

void __cdecl PM_UFOMove(struct pmove_t *, struct pml_t *) { UNIMPLEMENTED(); }

void __cdecl PM_NoclipMove(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_AirMove(struct pmove_t *, struct pml_t *) { UNIMPLEMENTED(); }

void __cdecl PM_FlyMove(struct pmove_t *, struct pml_t *) { UNIMPLEMENTED(); }

void __cdecl PM_LadderMove(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_WalkMove(struct pmove_t *, struct pml_t *) { UNIMPLEMENTED(); }

void __cdecl PmoveSingle(struct pmove_t *) { UNIMPLEMENTED(); }
