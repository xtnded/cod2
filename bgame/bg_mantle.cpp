float __cdecl acos(float)
{
  UNIMPLEMENTED();
}

bool __cdecl Mantle_IsWeaponInactive(struct playerState_s *ps)
{
  return *(_BYTE *)(mantle_enable + 8) && (a1->pm_flags & 4) != 0 &&
         *(&dword_30AAA4 + 3 * a1->mantleState.transIndex) != 10;
}

void __cdecl Mantle_ClearHint(struct playerState_s *ps)
{
  playerState_s *result; // eax

  result = a1;
  a1->mantleState.flags &= ~8u;
  return result;
}

void __cdecl Mantle_ShutdownAnims()
{
  s_mantleAnims = 0;
}

void __cdecl Mantle_CapView(struct playerState_s *)
{
  __m128 v1; // xmm1
  __m128 v2; // xmm2
  float v3;  // xmm3_4
  __m128 v4; // xmm0
  float v5;  // [esp+1Ch] [ebp-Ch]

    if (*(_BYTE *)(mantle_enable + 8)) {
      v5 = AngleDelta(*(float *)&a1->mantleState.yaw, a1->viewangles[1]);
      v1.f32[0] = v5;
      v2 = (__m128) * (unsigned int *)(mantle_view_yawcap + 8);
      v3 = -*(float *)(mantle_view_yawcap + 8);
      if (v5 < v3)
        goto LABEL_7;
        if (v2.f32[0] < v5) {
          if (v3 <= v5)
            goto LABEL_10;
            do {
              v1.f32[0] = v1.f32[0] + v2.f32[0];
            LABEL_7:;
            }
          while (v3 > v1.f32[0]);
            while (v1.f32[0] > v2.f32[0]) {
              v1.f32[0] = v1.f32[0] - v2.f32[0];
            LABEL_10:;
            }
          v4 = _mm_cmplt_ss((__m128)0LL, v1);
          LODWORD(a1->delta_angles[1]) +=
              (unsigned __int16)(int)(float)(v1.f32[0] * 182.04445);
          a1->viewangles[1] = AngleNormalize360Accurate(
              COERCE_FLOAT(_mm_andnot_ps(v4, v2).u32[0] |
                           LODWORD(v3) & v4.i32[0]) +
              *(float *)&a1->mantleState.yaw);
        }
    }
}

void __cdecl Mantle_Move(struct pmove_t *pm, struct playerState_s *ps,
                         struct pml_t *pml)
{
  int result;     // eax
  uint32_t flags; // eax
  int LengthMsec; // esi
  int v6;         // eax
  uint32_t timer; // edx
  signed int v8;  // eax
  int v9;         // esi
  int v10;        // eax
  float v11;      // xmm1_4
  float v12;      // xmm0_4
  float v13;      // xmm0_4
  uint32_t v14;   // edx
  int v15;        // [esp+18h] [ebp-40h]
  int v16;        // [esp+1Ch] [ebp-3Ch]
  float v17[3];   // [esp+28h] [ebp-30h] BYREF
  float v18;      // [esp+34h] [ebp-24h] BYREF
  float v19;      // [esp+38h] [ebp-20h]
  float v20;      // [esp+3Ch] [ebp-1Ch]

  result = mantle_enable;
    if (*(_BYTE *)(mantle_enable + 8)) {
      flags = a2->mantleState.flags;
      a2->mantleState.flags = flags & 0xFFFFFFF7;
      if ((flags & 2) != 0)
        BG_AddPredictableEventToPlayerstate(141, 0, a2);
      LengthMsec = XAnimGetLengthMsec(
          s_mantleAnims, *(&s_mantleTrans + 3 * a2->mantleState.transIndex));
      if ((a2->mantleState.flags & 1) != 0)
        v6 = XAnimGetLengthMsec(
            s_mantleAnims, *(&dword_30AAA4 + 3 * a2->mantleState.transIndex));
      else
        v6 = 0;
      v16 = LengthMsec + v6;
      timer = a2->mantleState.timer;
      v8 = a3->msec + timer;
      if (v16 < v8)
        v8 = v16;
      a2->mantleState.timer = v8;
      v15 = v8 - timer;
      Mantle_GetAnimDelta((int)&a2->mantleState, timer, v17);
      Mantle_GetAnimDelta((int)&a2->mantleState, a2->mantleState.timer, &v18);
      v9 = XAnimGetLengthMsec(
          s_mantleAnims, *(&s_mantleTrans + 3 * a2->mantleState.transIndex));
      if ((a2->mantleState.flags & 1) != 0)
        XAnimGetLengthMsec(s_mantleAnims,
                           *(&dword_30AAA4 + 3 * a2->mantleState.transIndex));
      if (v9 < (signed int)a2->mantleState.timer)
        v10 = *(&dword_30AAA4 + 3 * a2->mantleState.transIndex);
      else
        v10 = *(&s_mantleTrans + 3 * a2->mantleState.transIndex);
      BG_AnimScriptAnimation(a2, AISTATE_COMBAT,
                             (scriptAnimMoveTypes_t)(v10 + 20), 1);
      v18 = v18 - v17[0];
      v19 = v19 - v17[1];
      v11 = v19;
      v20 = v20 - v17[2];
      v12 = v20;
      a2->origin[0] = v18 + a2->origin[0];
      a2->origin[1] = v11 + a2->origin[1];
      a2->origin[2] = v12 + a2->origin[2];
      v13 = 1.0 / (float)((float)v15 * 0.001);
      a2->velocity[0] = v13 * v18;
      a2->velocity[1] = v13 * v19;
      a2->velocity[2] = v13 * v20;
      result = v16;
        if (v16 == a2->mantleState.timer) {
          a2->pm_flags &= ~4u;
          a1->mantleStarted = 0;
          v14 = a2->mantleState.flags;
            if ((v14 & 1) != 0) {
              result = BG_AnimScriptEvent(a2, ANIM_ET_JUMP, 0, 1);
              v14 = a2->mantleState.flags;
            }
            if ((v14 & 4) != 0) {
              result = BG_AddPredictableEventToPlayerstate(140, 0, a2);
              a2->eFlags &= ~0x4000u;
            }
        }
    }
  return result;
}

void __cdecl Mantle_CreateAnims(void *  xanimAlloc)(int))
{
  UNIMPLEMENTED();
}

void __cdecl Mantle_RegisterDvars()
{
  UNIMPLEMENTED();
}

void __cdecl Mantle_Check(struct pmove_t *pm, struct pml_t *pml)
{
  int32_t ps;      // esi
  int32_t v3;      // ebx
  float v4;        // xmm1_4
  float v5;        // eax
  int v6;          // ecx
  float v7;        // xmm1_4
  float v8;        // xmm4_4
  float v9;        // xmm1_4
  long double v10; // [esp+0h] [ebp-128h]
  float v11;       // [esp+5Ch] [ebp-CCh]
  _DWORD v12[14];  // [esp+6Ch] [ebp-BCh] BYREF
  trace_t v13;     // [esp+A4h] [ebp-84h] BYREF
  float v14;       // [esp+C8h] [ebp-60h]
  float v15;       // [esp+CCh] [ebp-5Ch]
  int v16;         // [esp+D0h] [ebp-58h]
  float v17[3];    // [esp+D4h] [ebp-54h] BYREF
  float v18;       // [esp+E0h] [ebp-48h] BYREF
  float v19;       // [esp+E4h] [ebp-44h]
  float v20;       // [esp+E8h] [ebp-40h]
  float v21;       // [esp+ECh] [ebp-3Ch]
  float v22;       // [esp+F0h] [ebp-38h]
  float v23;       // [esp+F4h] [ebp-34h]
  float v24[3];    // [esp+F8h] [ebp-30h] BYREF
  float v25;       // [esp+104h] [ebp-24h] BYREF
  float v26;       // [esp+108h] [ebp-20h]
  float v27;       // [esp+10Ch] [ebp-1Ch]

  if (*(_BYTE *)(mantle_debug + 8))
    Com_Printf("%s\n", "====== Mantle Debug ======");
    if (*(_BYTE *)(mantle_enable + 8)) {
      ps = a1->ps;
      *(_DWORD *)(ps + 1480) &= ~8u;
        if (*(int *)(ps + 4) > 5) {
          if (*(_BYTE *)(mantle_debug + 8))
            Com_Printf("%s\n", "Mantle Failed: Player is dead");
        }
        else if ((*(_BYTE *)(ps + 12) & 4) != 0) {
          if (*(_BYTE *)(mantle_debug + 8))
            Com_Printf("%s\n", "Mantle Failed: Player already mantling");
        }
        else if ((*(_BYTE *)(ps + 160) & 0xC) != 0) {
          if (*(_BYTE *)(mantle_debug + 8))
            Com_Printf("%s\n", "Mantle Failed: Player not standing");
        }
        else if ((unsigned int)(*(_DWORD *)(ps + 216) - 17) > 5) {
          v3 = a1->ps;
          v4 = *(float *)(a1->ps + 1400);
          v5 = *(float *)(a1->ps + 1396);
          v17[0] = -*(float *)(mantle_check_radius + 8);
          v17[1] = v17[0];
          v17[2] = v5;
          v6 = *(_DWORD *)(v3 + 1408);
          v14 = *(float *)(mantle_check_radius + 8);
          v15 = v14;
          v16 = v6;
          v7 = v4 - *(float *)(mantle_check_radius + 8);
          v8 = v7 + *(float *)(mantle_check_range + 8);
          v25 = a2->forward[0];
          v26 = a2->forward[1];
          v27 = 0.0;
          Vec3Normalize(&v25);
          v9 = -v7;
          v24[0] = (float)(v9 * v25) + *(float *)(v3 + 20);
          v24[1] = (float)(v9 * v26) + *(float *)(v3 + 24);
          v24[2] = (float)(v9 * v27) + *(float *)(v3 + 28);
          v21 = (float)(v25 * v8) + *(float *)(v3 + 20);
          v22 = (float)(v26 * v8) + *(float *)(v3 + 24);
          v23 = (float)(v8 * v27) + *(float *)(v3 + 28);
          PM_trace(a1, &v13, v24, v17);
            if (*(_WORD *)&v13.allsolid) {
              if (*(_BYTE *)(mantle_debug + 8))
                Com_Printf("%s\n", "Mantle Failed: Mantle brush is too thick");
            }
            else if (v13.fraction == 1.0) {
              if (*(_BYTE *)(mantle_debug + 8))
                Com_Printf("%s\n", "Mantle Failed: No mantle surface found");
            }
            else if ((v13.surfaceFlags & 0x6000000) != 0) {
              LODWORD(v18) = LODWORD(v13.normal[0]) ^ 0x80000000;
              v19 = -v13.normal[1];
              v20 = 0.0;
              v11 = Vec3Normalize(&v18);
                if (v11 >= 0.000099999997) {
                  *(double *)&v10 =
                      (float)((float)((float)(v25 * v18) + (float)(v26 * v19)) +
                              (float)(v27 * v20));
                    if ((double)acos(v10) * 57.29577951308232 <=
                        *(float *)(mantle_check_angle + 8)) {
                      memset(v12, 0, sizeof(v12));
                      *(float *)v12 = v18;
                      *(float *)&v12[1] = v19;
                      *(float *)&v12[2] = v20;
                      v12[3] = *(_DWORD *)(ps + 20);
                      v12[4] = *(_DWORD *)(ps + 24);
                      v12[5] = *(_DWORD *)(ps + 28);
                      if ((v13.surfaceFlags & 0x4000000) != 0)
                        v12[12] |= 1u;
                        if (!(unsigned __int8)Mantle_CheckLedge(a1, (int)v12,
                                                                60.0) &&
                            !(unsigned __int8)Mantle_CheckLedge(a1, (int)v12,
                                                                40.0)) {
                          Mantle_CheckLedge(a1, (int)v12, 20.0);
                        }
                    }
                    else if (*(_BYTE *)(mantle_debug + 8)) {
                      Com_Printf(
                          "%s\n",
                          "Mantle Failed: Player is not facing mantle surface");
                    }
                }
                else if (*(_BYTE *)(mantle_debug + 8)) {
                  Com_Printf(
                      "%s\n",
                      "Mantle Failed: Mantle surface has vertical normal");
                }
            }
            else if (*(_BYTE *)(mantle_debug + 8)) {
              Com_Printf("%s\n",
                         "Mantle Failed: No mantle surface with MANTLE_ON or "
                         "MANTLE_OVER found");
            }
        }
        else if (*(_BYTE *)(mantle_debug + 8)) {
          Com_Printf("%s\n", "Mantle Failed: Player using binoculars");
        }
    }
    else if (*(_BYTE *)(mantle_debug + 8)) {
      Com_Printf("%s\n", "Mantle Failed: Not enabled");
    }
}

int marker_bg_mantle;

void __cdecl Mantle_CalcEndPos(struct pmove_t *, struct MantleResults *)
{
  UNIMPLEMENTED();
}

int __cdecl Mantle_GetOverLength(struct MantleState *)
{
  UNIMPLEMENTED();
}

int __cdecl Mantle_GetUpLength(struct MantleState *)
{
  UNIMPLEMENTED();
}

int __cdecl Mantle_GetAnim(struct MantleState *)
{
  UNIMPLEMENTED();
}

int __cdecl Mantle_FindTransition(float, float)
{
  UNIMPLEMENTED();
}

void __cdecl Mantle_GetAnimDelta(struct MantleState *, int, float *const)
{
  int LengthMsec; // ebx
  int v7;         // [esp+2Ch] [ebp-3Ch]
  float v8[3];    // [esp+3Ch] [ebp-2Ch] BYREF
  float v9[8];    // [esp+48h] [ebp-20h] BYREF

  LengthMsec = XAnimGetLengthMsec(s_mantleAnims,
                                  *(&s_mantleTrans + 3 * *(_DWORD *)(a1 + 8)));
  if ((*(_BYTE *)(a1 + 12) & 1) != 0)
    v7 = XAnimGetLengthMsec(s_mantleAnims,
                            *(&dword_30AAA4 + 3 * *(_DWORD *)(a1 + 8)));
  else
    v7 = 0;
    if (LengthMsec < a2) {
      XAnimGetAbsDelta(s_mantleAnims,
                       *(&s_mantleTrans + 3 * *(_DWORD *)(a1 + 8)), v9, v8,
                       1.0);
      XAnimGetAbsDelta(s_mantleAnims,
                       *(&dword_30AAA4 + 3 * *(_DWORD *)(a1 + 8)), v9, a3,
                       (float)(a2 - LengthMsec) / (float)v7);
      *a3 = *a3 + v8[0];
      a3[1] = a3[1] + v8[1];
      a3[2] = a3[2] + v8[2];
      VectorAngleMultiply(a3, *(float *)a1);
    }
    else {
      XAnimGetAbsDelta(s_mantleAnims,
                       *(&s_mantleTrans + 3 * *(_DWORD *)(a1 + 8)), v9, a3,
                       (float)a2 / (float)LengthMsec);
      VectorAngleMultiply(a3, *(float *)a1);
    }
}

void __cdecl Mantle_Start(struct pmove_t *, struct playerState_s *,
                          struct MantleResults *)
{
  UNIMPLEMENTED();
}

void __cdecl Mantle_DebugPrint(char const *)
{
  UNIMPLEMENTED();
}

bool __cdecl Mantle_FindMantleSurface(struct pmove_t *, struct pml_t *,
                                      struct trace_t *, float *const)
{
  UNIMPLEMENTED();
}

bool __cdecl Mantle_CheckLedge(struct pmove_t *, struct pml_t *,
                               struct MantleResults *, float)
{
  UNIMPLEMENTED();
}
