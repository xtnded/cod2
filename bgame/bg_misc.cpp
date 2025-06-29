int const *const singleClientEvents;
void __cdecl BG_LerpHudColors(struct hudelem_s const &, int,
                              union hudelem_color_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm,
                                                 struct playerState_s *ps) {
  int result;            // eax
  int32_t eventSequence; // edx
  int v5;                // ecx

  result = a1;
  if (a1) {
    eventSequence = a3->eventSequence;
    v5 = eventSequence & 3;
    *(_DWORD *)&a3->events[4 * v5] = (unsigned __int8)a1;
    result = a2;
    *(_DWORD *)&a3->eventParms[4 * v5] = a2;
    a3->eventSequence = eventSequence + 1;
  }
  return result;
}

struct gitem_s const *__cdecl BG_FindItemForWeapon(int weapon) {
  return &bg_itemlist[11 * a1];
}

void __cdecl BG_PlayerStateToEntityState(struct playerState_s *ps,
                                         struct entityState_s *s, int snap,
                                         unsigned char handler) {
  uint32_t v4;                 // eax
  int v5;                      // eax
  int32_t entityEventSequence; // edx
  playerState_s *v7;           // ebx
  int32_t eventSequence;       // ecx
  playerState_s *v9;           // ebx
  int32_t oldEventSequence;    // edi
  playerState_s *i;            // eax
  uint8_t v12;                 // si
  _DWORD(__cdecl * v13)
  (trace_t *, const float *, const float *, const float *, const float *, int,
   int);              // edx
  int v14;            // ecx
  int *v15;           // edx
  int v16;            // eax
  playerState_s *v17; // esi
  int32_t v18;        // edx
  int v19;            // ecx
  uint32_t result;    // eax
  int v21;            // eax
  float v22;          // xmm1_4
  playerState_s *v23; // edx
  playerState_s *v24; // edi
  int32_t v25;        // eax
  float v26;          // xmm1_4
  float v27;          // [esp+1Ch] [ebp-3Ch]
  float v28;          // [esp+38h] [ebp-20h]
  int v29;            // [esp+3Ch] [ebp-1Ch]

  a2->eType = (a1->pm_flags & 0xC00000) == 0 ? 5 : 1;
  a2->pos.trType = 1;
  a2->pos.trBase[0] = a1->origin[0];
  a2->pos.trBase[1] = a1->origin[1];
  a2->pos.trBase[2] = a1->origin[2];
  if (a3) {
    a2->pos.trBase[0] = (float)(int)a2->pos.trBase[0];
    a2->pos.trBase[1] = (float)(int)a2->pos.trBase[1];
    a2->pos.trBase[2] = (float)(int)a2->pos.trBase[2];
  }
  *(_DWORD *)a2->apos = 1;
  *(float *)&a2->apos[12] = a1->viewangles[0];
  *(float *)&a2->apos[16] = a1->viewangles[1];
  *(float *)&a2->apos[20] = a1->viewangles[2];
  if (a3) {
    *(float *)&a2->apos[12] = (float)(int)*(float *)&a2->apos[12];
    *(float *)&a2->apos[16] = (float)(int)*(float *)&a2->apos[16];
    *(float *)&a2->apos[20] = (float)(int)*(float *)&a2->apos[20];
  }
  a2->angles2[1] = (float)a1->movementDir;
  a2->legsAnim = a1->legsAnim;
  a2->torsoAnim = a1->torsoAnim;
  a2->clientNum = a1->clientNum;
  a2->eFlags = a1->eFlags;
  if ((a1->eFlags & 0x300) != 0)
    a2->otherEntityNum = a1->viewlocked_entNum;
  if (a1->pm_type <= 5)
    v4 = a2->eFlags & 0xFFFDFFFF;
  else
    v4 = a2->eFlags | 0x20000;
  a2->eFlags = v4;
  if ((a1->pm_flags & 0x40) != 0) {
    a2->eFlags = v4 | 0x40000;
    a2->leanf = a1->leanf;
    LOBYTE(v5) = PM_GetEffectiveStance(a1);
    if (v5 != 1)
      goto LABEL_11;
  } else {
    a2->eFlags = v4 & 0xFFFBFFFF;
    a2->leanf = a1->leanf;
    LOBYTE(v21) = PM_GetEffectiveStance(a1);
    if (v21 != 1) {
    LABEL_11:
      a2->fTorsoHeight = 0;
      a2->fTorsoPitch = 0;
      a2->fWaistPitch = 0;
      entityEventSequence = a1->entityEventSequence;
      v7 = a1;
      eventSequence = a1->eventSequence;
      if (entityEventSequence - eventSequence >= 0)
        goto LABEL_12;
    LABEL_29:
      if (eventSequence - entityEventSequence > 4) {
        v7->entityEventSequence = eventSequence - 4;
        v24 = a1;
        v25 = a1->eventParms[4 * ((eventSequence - 4) & 3)];
      } else {
        v24 = a1;
        v25 = a1->eventParms[4 * (entityEventSequence & 3)];
      }
      a2->eventParm = v25;
      ++v24->entityEventSequence;
      v9 = a1;
      oldEventSequence = a1->oldEventSequence;
      if (oldEventSequence != a1->eventSequence)
        goto LABEL_13;
      goto LABEL_32;
    }
  }
  if (a1->viewHeightLerpTime) {
    v26 = (float)(*(_DWORD *)a1->commandTime - a1->viewHeightLerpTime) /
          (float)PM_GetViewHeightLerpTime(a1, a1->viewHeightLerpTarget,
                                          a1->viewHeightLerpDown);
    if (v26 < 0.0)
      v22 = 0.0;
    else
      v22 = fminf(1.0, v26);
    if (!a1->viewHeightLerpDown)
      v22 = 1.0 - v22;
    v23 = a1;
  } else {
    v22 = 1.0;
    v23 = a1;
  }
  *(float *)&a2->fTorsoHeight = v22 * *(float *)&v23->fTorsoHeight;
  v27 = AngleNormalize180(*(float *)&v23->fTorsoPitch);
  *(float *)&a2->fTorsoPitch = v27 * v22;
  v28 = AngleNormalize180(*(float *)&a1->fWaistPitch);
  *(float *)&a2->fWaistPitch = v22 * v28;
  entityEventSequence = a1->entityEventSequence;
  v7 = a1;
  eventSequence = a1->eventSequence;
  if (entityEventSequence - eventSequence < 0)
    goto LABEL_29;
LABEL_12:
  a2->eventParm = 0;
  v9 = a1;
  oldEventSequence = a1->oldEventSequence;
  if (oldEventSequence != a1->eventSequence) {
  LABEL_13:
    for (i = a1;; i = v17) {
      v29 = oldEventSequence & 3;
      v12 = i->events[4 * v29];
      v13 = pmoveHandlers[3 * a4 + 2];
      if (v13)
        ((void(__cdecl *)(uint32_t, _DWORD))v13)(a2->number, v12);
      if (v12 == 140)
        goto LABEL_20;
      v14 = 0;
      v15 = singleClientEvents;
      while (1) {
        ++v14;
        v16 = v15[1];
        if (v16 <= 0)
          break;
        ++v15;
        if (v16 == v12)
          goto LABEL_20;
      }
      if (singleClientEvents[v14] >= 0) {
      LABEL_20:
        ++oldEventSequence;
        v17 = a1;
        if (oldEventSequence == a1->eventSequence)
          goto LABEL_24;
      } else {
        v18 = a2->eventSequence;
        v19 = v18 & 3;
        *(_DWORD *)&a2->events[4 * v19] = v12;
        *(_DWORD *)&a2->eventParms[4 * v19] = a1->eventParms[4 * v29];
        a2->eventSequence = v18 + 1;
        ++oldEventSequence;
        v17 = a1;
        if (oldEventSequence == a1->eventSequence) {
        LABEL_24:
          v17->oldEventSequence = oldEventSequence;
          a2->weapon = LOBYTE(a1->weapon);
          result = LOWORD(a1->groundEntityNum);
          a2->groundEntityNum = result;
          return result;
        }
      }
    }
  }
LABEL_32:
  v9->oldEventSequence = oldEventSequence;
  a2->weapon = LOBYTE(a1->weapon);
  result = LOWORD(a1->groundEntityNum);
  a2->groundEntityNum = result;
  return result;
}

void __cdecl BG_GetMarkDir(float const *const, float const *const,
                           float *const) {
  UNIMPLEMENTED();
}

int __cdecl BG_CheckProneValid(int passEntityNum, float const *const vPos,
                               float fSize, float fHeight, float fYaw,
                               float *pfTorsoHeight, float *pfTorsoPitch,
                               float *pfWaistPitch, int bAlreadyProne,
                               int bOnGround, float *const vGroundNormal,
                               unsigned char handler,
                               enum proneCheckType_t proneCheckType,
                               float prone_feet_dist) {
  _DWORD(__cdecl * v14)
  (trace_t *, const float *, const float *, const float *, const float *, int,
   int);        // edi
  int v15;      // esi
  int v16;      // esi
  float v17;    // xmm5_4
  float v18;    // xmm7_4
  float v19;    // xmm6_4
  float v20;    // xmm4_4
  float v21;    // xmm3_4
  float v22;    // xmm1_4
  float v24;    // xmm5_4
  bool v25;     // al
  bool v26;     // al
  float v27;    // [esp+0h] [ebp-178h]
  float v28;    // [esp+0h] [ebp-178h]
  float v29;    // [esp+0h] [ebp-178h]
  float v30;    // [esp+84h] [ebp-F4h]
  float v31;    // [esp+88h] [ebp-F0h]
  float v32;    // [esp+8Ch] [ebp-ECh]
  float v33;    // [esp+90h] [ebp-E8h]
  int v34;      // [esp+94h] [ebp-E4h]
  bool v35;     // [esp+9Bh] [ebp-DDh]
  bool v36;     // [esp+9Bh] [ebp-DDh]
  bool v37;     // [esp+9Bh] [ebp-DDh]
  float *v38;   // [esp+9Ch] [ebp-DCh]
  float *v39;   // [esp+A0h] [ebp-D8h]
  float v40;    // [esp+A4h] [ebp-D4h]
  float v41;    // [esp+A8h] [ebp-D0h]
  float v42;    // [esp+ACh] [ebp-CCh]
  float v43;    // [esp+B0h] [ebp-C8h]
  float v44;    // [esp+B4h] [ebp-C4h]
  float v45;    // [esp+B8h] [ebp-C0h]
  float v46;    // [esp+BCh] [ebp-BCh]
  float v47;    // [esp+C0h] [ebp-B8h]
  float v48;    // [esp+C4h] [ebp-B4h]
  float v49;    // [esp+C8h] [ebp-B0h]
  float v50;    // [esp+CCh] [ebp-ACh]
  float v51[3]; // [esp+DCh] [ebp-9Ch] BYREF
  float v52;    // [esp+E8h] [ebp-90h]
  char v53;     // [esp+FEh] [ebp-7Ah]
  float v54[3]; // [esp+100h] [ebp-78h] BYREF
  float v55;    // [esp+10Ch] [ebp-6Ch] BYREF
  float v56;    // [esp+110h] [ebp-68h]
  float v57;    // [esp+114h] [ebp-64h]
  float v58;    // [esp+118h] [ebp-60h] BYREF
  float v59;    // [esp+11Ch] [ebp-5Ch]
  float v60;    // [esp+120h] [ebp-58h]
  float v61;    // [esp+124h] [ebp-54h] BYREF
  float v62;    // [esp+128h] [ebp-50h]
  float v63;    // [esp+12Ch] [ebp-4Ch]
  float v64;    // [esp+130h] [ebp-48h] BYREF
  float v65;    // [esp+134h] [ebp-44h]
  float v66;    // [esp+138h] [ebp-40h]
  float v67;    // [esp+13Ch] [ebp-3Ch] BYREF
  float v68;    // [esp+140h] [ebp-38h]
  float v69;    // [esp+144h] [ebp-34h]
  float v70;    // [esp+148h] [ebp-30h] BYREF
  float v71;    // [esp+14Ch] [ebp-2Ch]
  float v72;    // [esp+150h] [ebp-28h]
  float v73[9]; // [esp+154h] [ebp-24h] BYREF

  v14 = pmoveHandlers[3 * a12];
  v64 = *a2 - a3;
  v38 = (float *)(a2 + 1);
  v65 = a2[1] - a3;
  v39 = (float *)(a2 + 2);
  v66 = a2[2] + 0.0;
  v61 = a3 + *a2;
  v62 = a3 + a2[1];
  v63 = a4 + a2[2];
  v15 = -(a13 == PCT_CLIENT);
  LOWORD(v15) = 0;
  v16 = v15 + 8519697;
  if (!a9) {
    v64 = -a3;
    v65 = -a3;
    v66 = 0.0;
    v61 = a3;
    v62 = a3;
    v63 = a4;
    v70 = *a2;
    v71 = a2[1];
    v72 = a2[2];
    v67 = v70;
    v68 = v71;
    v69 = v72 + 10.0;
    v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
    if (v53)
      return 0;
  }
  if (a10 && a11 && a11[2] < 0.69999999)
    return 0;
  v64 = -6.0;
  v65 = -6.0;
  v66 = -6.0;
  v61 = 6.0;
  v62 = 6.0;
  v63 = 6.0;
  v67 = 0.0;
  v68 = a5 - 180.0;
  v69 = 0.0;
  AngleVectors(&v67, &v55, v54, v73);
  v33 = a4 - 6.0;
  v70 = *a2;
  v71 = *v38;
  v72 = *v39;
  v72 = (float)(a4 - 6.0) + v72;
  v40 = a14 - 6.0;
  v67 = (float)((float)(a14 - 6.0) * v55) + v70;
  v68 = (float)((float)(a14 - 6.0) * v56) + v71;
  v69 = (float)((float)(a14 - 6.0) * v57) + v72;
  v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
  v17 = v51[0];
  if (v51[0] >= 1.0)
    goto LABEL_6;
  if (!a10)
    return 0;
  v18 = (float)(v40 * v51[0]) + 6.0;
  if ((float)(a3 + 2.0) > v18)
    return 0;
  v30 = (float)(v33 * 0.69999999) + 48.0;
  if (v30 > v18) {
    v69 = v69 + 22.0;
    v58 = v67 - v70;
    v59 = v68 - v71;
    v60 = v69 - v72;
    v47 = Vec3NormalizeTo(&v58, &v55);
    v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
    v17 = v51[0];
    if (v51[0] >= 1.0) {
    LABEL_6:
      v18 = a14;
      v34 = 0;
      goto LABEL_7;
    }
    v18 = (float)(v47 * v51[0]) + 6.0;
    if (v30 > v18)
      return 0;
  }
  v34 = 1;
LABEL_7:
  v19 = (float)((float)(v67 - v70) * v17) + v70;
  v20 = (float)((float)(v68 - v71) * v17) + v71;
  v21 = (float)((float)(v69 - v72) * v17) + v72;
  v70 = (float)(v55 * 48.0) + *a2;
  v71 = (float)(v56 * 48.0) + *v38;
  v72 = (float)(v57 * 48.0) + *v39;
  v72 = v33 + v72;
  v67 = v70;
  v68 = v71;
  v69 = v72 - (float)((float)((float)(a3 * 2.5) + v33) - 6.0);
  v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
  if (v51[0] == 1.0)
    goto LABEL_11;
  if (v52 < 0.69999999)
    return 0;
  v43 = v70 + (float)((float)(v67 - v70) * v51[0]);
  v42 = v71 + (float)((float)(v68 - v71) * v51[0]);
  v50 = (float)(v72 + (float)(v51[0] * (float)(v69 - v72))) - 6.0;
  if (v34) {
    v22 =
        (float)((float)((float)((float)(a3 * 2.5) + v33) - 6.0) * v51[0]) + 6.0;
    if ((float)(v22 * -0.75) > (float)(v18 - v22))
      goto LABEL_11;
    v58 = (float)(v55 * 6.0) + (float)(v19 - v43);
    v59 = (float)(v56 * 6.0) + (float)(v20 - v42);
    v60 = (float)((float)(v57 * 6.0) + (float)(v21 - v50)) + 6.0;
    Vec3Normalize(&v58);
    v67 = (float)((float)(v40 - 48.0) * v58) + v70;
    v68 = (float)((float)(v40 - 48.0) * v59) + v71;
    v69 = (float)((float)(v40 - 48.0) * v60) + v72;
    v67 = (float)((float)((float)(v40 * v55) + *a2) + v67) * 0.5;
    v68 = 0.5 * (float)((float)((float)(v40 * v56) + *v38) + v68);
    v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
    v24 = v51[0];
    if (v51[0] < 1.0) {
      v70 = v70 + (float)((float)(v67 - v70) * v51[0]);
      v71 = v71 + (float)((float)(v68 - v71) * v51[0]);
      v72 = (float)(v72 + (float)(v51[0] * (float)(v69 - v72))) + 18.0;
      v69 = v69 + 18.0;
      v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
      if (v51[0] < 1.0) {
      LABEL_11:
        if (!a10) {
          if (a6)
            *a6 = 0.0;
          if (a7)
            *a7 = 0.0;
          if (a8) {
            *a8 = 0.0;
            return 1;
          }
          return 1;
        }
        return 0;
      }
      v24 = v51[0];
    }
    v19 = (float)((float)(v67 - v70) * v24) + v70;
    v20 = (float)((float)(v68 - v71) * v24) + v71;
    v21 = (float)((float)(v69 - v72) * v24) + v72;
  }
  v70 = v19;
  v71 = v20;
  v72 = v21;
  v67 = v19;
  v68 = v20;
  v69 = v21 - (float)((float)((float)(v21 - v50) + (float)(v21 - v50)) + a3);
  v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
  if (v51[0] == 1.0)
    goto LABEL_11;
  if (v52 < 0.69999999)
    return 0;
  v41 = v70 + (float)((float)(v67 - v70) * v51[0]);
  v49 = v71 + (float)((float)(v68 - v71) * v51[0]);
  v48 = (float)(v72 + (float)(v51[0] * (float)(v69 - v72))) - 6.0;
  v46 = *a2;
  v45 = *v38;
  v44 = *v39;
  v58 = v43 - *a2;
  v59 = v42 - v45;
  v60 = v50 - v44;
  v31 = vectopitch(&v58);
  v58 = v41 - v43;
  v59 = v49 - v42;
  v60 = v48 - v50;
  v27 = vectopitch(&v58);
  v32 = AngleSubtract(v27, v31);
  v35 = v32 >= -50.0 && v32 <= 70.0;
  v64 = -0.0;
  v65 = -0.0;
  v66 = -0.0;
  v61 = 0.0;
  v62 = 0.0;
  v63 = 0.0;
  v70 = v46;
  v71 = v45;
  v72 = v44 + 5.0;
  v67 = v43;
  v68 = v42;
  v69 = v50 + 5.0;
  v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
  v25 = v35;
  if (v51[0] < 1.0)
    v25 = 0;
  v36 = v25;
  v70 = v67;
  v71 = v68;
  v72 = v69;
  v67 = v41;
  v68 = v49;
  v69 = v48 + 5.0;
  v14((trace_t *)v51, &v70, &v64, &v61, &v67, a1, v16);
  v26 = v36;
  if (v51[0] < 1.0)
    v26 = 0;
  v37 = v26;
  if (a6)
    *a6 = 0.0;
  if (a7) {
    v58 = v46 - v43;
    v59 = v45 - v42;
    v60 = v44 - v50;
    v28 = vectopitch(&v58);
    *a7 = AngleNormalize180(v28);
  }
  if (a8) {
    v58 = v43 - v41;
    v59 = v42 - v49;
    v60 = v50 - v48;
    v29 = vectopitch(&v58);
    *a8 = AngleNormalize180(v29);
  }
  if (!v37)
    goto LABEL_11;
  return 1;
}

int __cdecl BG_CheckProne(int passEntityNum, float const *const vPos,
                          float fSize, float fHeight, float fYaw,
                          float *pfTorsoHeight, float *pfTorsoPitch,
                          float *pfWaistPitch, int bAlreadyProne, int bOnGround,
                          float *const vGroundNormal, unsigned char handler,
                          enum proneCheckType_t proneCheckType,
                          float prone_feet_dist) {
  return BG_CheckProneValid(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12,
                            a13, a14);
}

void __cdecl BG_EvaluateTrajectoryDelta(struct trajectory_t const *tr,
                                        int atTime, float *const result) {
  UNIMPLEMENTED();
}

void __cdecl BG_EvaluateTrajectory(struct trajectory_t const *tr, int atTime,
                                   float *const result) {
  uint32_t v3;        // ebx
  float *result;      // eax
  float v5;           // xmm1_4
  float *trBase;      // edx
  float v7;           // xmm0_4
  uint32_t v8;        // edx
  int32_t v9;         // ecx
  int v10;            // eax
  float v11;          // xmm2_4
  float v12;          // xmm4_4
  float v13;          // xmm1_4
  uint32_t trTime;    // edx
  int32_t trDuration; // ecx
  float v16;          // xmm1_4
  float v17;          // xmm1_4
  long double v18;    // [esp+0h] [ebp-58h]
  float v19;          // [esp+10h] [ebp-48h]
  float v20;          // [esp+10h] [ebp-48h]
  float v21;          // [esp+20h] [ebp-38h]
  float v22;          // [esp+20h] [ebp-38h]

  v3 = a2;
  switch (a1->trType) {
  case 0:
  case 1:
  case 6:
    *a3 = a1->trBase[0];
    a3[1] = a1->trBase[1];
    result = (float *)LODWORD(a1->trBase[2]);
    *((_DWORD *)a3 + 2) = result;
    return result;
  case 2:
    v5 = (float)(a2 - a1->trTime) * 0.001;
    goto LABEL_4;
  case 3:
    if (a2 > (signed int)(a1->trDuration + a1->trTime))
      v3 = a1->trDuration + a1->trTime;
    v7 = fmaxf(0.0, (float)(int)(v3 - a1->trTime) * 0.001);
    v5 = v7;
    result = a1->trDelta;
    trBase = a1->trBase;
    goto LABEL_5;
  case 4:
    *(double *)&v18 =
        (float)((float)(a2 - a1->trTime) / (float)a1->trDuration) *
            3.141592653589793 +
        (float)((float)(a2 - a1->trTime) / (float)a1->trDuration) *
            3.141592653589793;
    v5 = sin(v18);
  LABEL_4:
    result = a1->trDelta;
    trBase = a1->trBase;
    v7 = v5;
  LABEL_5:
    *a3 = (float)(v7 * a1->trDelta[0]) + a1->trBase[0];
    a3[1] = (float)(v5 * result[1]) + trBase[1];
    a3[2] = (float)(v5 * result[2]) + trBase[2];
    break;
  case 5:
    v17 = (float)(a2 - a1->trTime) * 0.001;
    result = a1->trDelta;
    *a3 = (float)(v17 * a1->trDelta[0]) + a1->trBase[0];
    a3[1] = (float)(v17 * a1->trDelta[1]) + a1->trBase[1];
    a3[2] = (float)((float)(v17 * a1->trDelta[2]) + a1->trBase[2]) +
            (float)(v17 * (float)(v17 * -400.0));
    break;
  case 7:
    trTime = a1->trTime;
    trDuration = a1->trDuration;
    if (a2 > (int)(trTime + trDuration))
      v3 = trTime + trDuration;
    v22 = fsqrt((float)((float)(a1->trDelta[0] * a1->trDelta[0]) +
                        (float)(a1->trDelta[1] * a1->trDelta[1])) +
                (float)(a1->trDelta[2] * a1->trDelta[2])) /
          (float)((float)trDuration * 0.001);
    v20 = (float)(int)(v3 - trTime) * 0.001;
    Vec3NormalizeTo(a1->trDelta, a3);
    v16 = (float)((float)(v22 * 0.5) * v20) * v20;
    result = a1->trBase;
    *a3 = (float)(v16 * *a3) + a1->trBase[0];
    a3[1] = (float)(v16 * a3[1]) + a1->trBase[1];
    a3[2] = (float)(v16 * a3[2]) + a1->trBase[2];
    break;
  case 8:
    v8 = a1->trTime;
    v9 = a1->trDuration;
    v10 = v8 + v9;
    if ((int)(v8 + v9) >= a2)
      v10 = a2;
    v21 = fsqrt((float)((float)(a1->trDelta[0] * a1->trDelta[0]) +
                        (float)(a1->trDelta[1] * a1->trDelta[1])) +
                (float)(a1->trDelta[2] * a1->trDelta[2])) /
          (float)((float)v9 * 0.001);
    v19 = (float)(int)(v10 - v8) * 0.001;
    Vec3NormalizeTo(a1->trDelta, a3);
    result = a1->trBase;
    v11 = (float)(v19 * a1->trDelta[1]) + a1->trBase[1];
    v12 = (float)(v19 * a1->trDelta[2]) + a1->trBase[2];
    v13 = (float)((float)(v21 * -0.5) * v19) * v19;
    *a3 = (float)((float)(v19 * a1->trDelta[0]) + a1->trBase[0]) +
          (float)(v13 * *a3);
    a3[1] = v11 + (float)(v13 * a3[1]);
    a3[2] = v12 + (float)(v13 * a3[2]);
    break;
  default:
    result = (float *)Com_Error(
        1, "\x15BG_EvaluateTrajectory: unknown trType: %i", a1->trType);
    break;
  }
  return result;
}

int __cdecl BG_CanItemBeGrabbed(struct entityState_s const *ent,
                                struct playerState_s const *ps, int bTouched) {
  int32_t item; // edx
  _DWORD *v4;   // esi
  int v5;       // eax
  char *v7;     // eax
  int v8;       // edx
  char v9;      // [esp+8h] [ebp-20h]
  char v10;     // [esp+8h] [ebp-20h]

  item = a1->index.item;
  if (item <= 0 || item >= bg_numItems) {
    v7 = va("\x15BG_CanItemBeGrabbed: index out of range (index is %i, eType "
            "is %i)",
            item, a1->eType);
    Com_Error(1, v7, v10);
    item = a1->index.item;
  }
  v4 = &bg_itemlist[11 * item];
  if (a1->clientNum == a2->clientNum)
    return 0;
  v5 = v4[7];
  if (v5 == 1) {
    if (BG_DoesWeaponNeedSlot(v4[8])) {
      v8 = v4[8];
      if (((*(int *)&a2->weapons[4 * (v8 >> 5)] >> (v4[8] & 0x1F)) & 1) == 0 &&
          a3)
        return 0;
    } else {
      v8 = v4[8];
    }
  } else {
    if (v5 <= 1) {
      if (!v5) {
        Com_Error(1, "\x15BG_CanItemBeGrabbed: IT_BAD", v9);
        return 0;
      }
      return 0;
    }
    if (v5 != 2)
      return v5 == 3 && *(_DWORD *)a2->stats < *(_DWORD *)&a2->stats[8];
    v8 = v4[8];
    if (((*(int *)&a2->weapons[4 * (v8 >> 5)] >> (v4[8] & 0x1F)) & 1) == 0)
      return BG_WeaponIsClipOnly(v4[8]) &&
             BG_GetMaxPickupableAmmo(a2, v4[8]) > 0;
  }
  return BG_GetMaxPickupableAmmo(a2, v8) > 0;
}

int __cdecl BG_PlayerTouchesItem(struct playerState_s *ps,
                                 struct entityState_s *item, int atTime) {
  float v3;      // xmm0_4
  _BOOL4 result; // eax
  float v5;      // xmm1_4
  float v6;      // xmm0_4
  float v7[5];   // [esp+14h] [ebp-14h] BYREF

  BG_EvaluateTrajectory(&a2->pos, a3, v7);
  v3 = a1->origin[0] - v7[0];
  result = 0;
  if (v3 <= 36.0 && v3 >= -36.0) {
    v5 = a1->origin[1] - v7[1];
    if (v5 <= 36.0 && v5 >= -36.0) {
      v6 = a1->origin[2] - v7[2];
      if (v6 <= 18.0 && v6 >= -88.0)
        return 1;
    }
  }
  return result;
}

struct gitem_s const *__cdecl G_FindItem(char const *) {
  int v1;                 // esi
  char **v2;              // ebx
  int WeaponIndexForName; // eax

  if (bg_numItems > 129) {
    v1 = 129;
    do {
      v2 = (char **)&bg_itemlist[11 * v1];
      if (!I_stricmp(v2[5], a1) || !I_stricmp(*v2, a1))
        return v2;
    } while (++v1 < bg_numItems);
  }
  WeaponIndexForName = G_GetWeaponIndexForName(a1);
  if (WeaponIndexForName)
    return (char **)&bg_itemlist[11 * WeaponIndexForName];
  return 0;
}

void __cdecl BG_RegisterDvars() { UNIMPLEMENTED(); }

char **eventnames;
struct dvar_s const *const player_footstepsThreshhold;
struct dvar_s const *const player_view_pitch_down;
struct dvar_s const *const player_runbkThreshhold;
struct dvar_s const *const player_turnAnims;
struct dvar_s const *const stopspeed;
struct dvar_s const *const player_view_pitch_up;
struct dvar_s const *const bg_foliagesnd_minspeed;
struct dvar_s const *const player_dmgtimer_flinchTime;
struct dvar_s const *const player_adsExitDelay;
struct dvar_s const *const bg_swingSpeed;
struct dvar_s const *const bg_aimSpreadMoveSpeedThreshold;
struct dvar_s const *const player_breath_snd_lerp;
struct dvar_s const *const player_breath_gasp_scale;
struct dvar_s const *const player_moveThreshhold;
struct dvar_s const *const player_dmgtimer_minScale;
struct dvar_s const *const bg_foliagesnd_fastinterval;
struct dvar_s const *const player_breath_snd_delay;
struct dvar_s const *const inertiaDebug;
struct dvar_s const *const bg_fallDamageMaxHeight;
struct dvar_s const *const player_runThreshhold;
struct dvar_s const *const player_spectateSpeedScale;
struct dvar_s const *const player_dmgtimer_timePerPoint;
struct dvar_s const *const bg_prone_yawcap;
struct dvar_s const *const friction;
struct dvar_s const *const inertiaMax;
struct dvar_s const *const player_scopeExitOnDamage;
struct dvar_s const *const player_dmgtimer_stumbleTime;
struct dvar_s const *const bg_foliagesnd_resetinterval;
struct dvar_s const *const player_backSpeedScale;
struct dvar_s const *const player_breath_fire_delay;
struct dvar_s const *const bg_foliagesnd_slowinterval;
struct dvar_s const *const player_toggleBinoculars;
int marker_bg_misc;
struct dvar_s const *const player_breath_hold_lerp;
struct dvar_s const *const inertiaAngle;
struct dvar_s const *const player_dmgtimer_maxTime;
struct dvar_s const *const bg_bobMax;
struct dvar_s const *const player_breath_gasp_time;
struct dvar_s const *const bg_bobAmplitudeProne;
struct dvar_s const *const player_breath_gasp_lerp;
struct dvar_s const *const bg_fallDamageMinHeight;
struct dvar_s const *const bg_bobAmplitudeDucked;
struct dvar_s const *const player_strafeSpeedScale;
struct dvar_s const *const player_breath_hold_time;
struct dvar_s const *const bg_ladder_yawcap;
struct dvar_s const *const bg_bobAmplitudeStanding;
struct dvar_s const *const bg_foliagesnd_maxspeed;
