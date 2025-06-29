void __cdecl CG_Respawn()
{
  _DWORD *v0; // ebx

  v0 = cg;
  *((_DWORD *)cg + 38639) = 0;
  memcpy((char *)&loc_25BC4 + (_DWORD)v0, (const void *)(v0[8] + 12), 0x26A8u);
  v0[44948] = v0[38694];
  v0[44949] = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v0);
  v0[44956] = *(_DWORD *)((char *)&loc_25C94 + (_DWORD)v0);
  v0[44922] = 0;
  v0[44923] = 0;
  v0[44940] = 0;
  v0[41333] = 0;
  v0[41334] = 0;
  v0[41335] = 0;
  v0[41336] = 0;
  v0[41337] = 0;
  v0[41338] = 0;
  v0[41339] = 0;
  v0[41340] = 0;
  v0[41341] = 0;
  v0[45071] = 0;
  v0[45072] = 0;
  v0[45073] = 0;
  v0[45068] = 0;
  v0[45069] = 0;
  v0[45070] = 0;
  v0[44999] = 0;
  memset(v0 + 41252, 0, 0x30u);
  v0[44981] = 0;
  v0[44996] = 0;
  v0[44997] = 0;
  v0[45097] = 0;
  v0[45098] = 0;
  v0[45099] = 0;
  v0[45100] = 0;
  v0[45101] = 0;
  v0[45102] = 0;
  memset(v0 + 44957, 0, 0x60u);
  memset((char *)&locret_2C50C + (_DWORD)v0, 0, 0x90u);
  v0[41265] = 0;
  v0[41266] = 0;
  v0[41267] = 0;
  *(_DWORD *)((char *)&loc_2CD10 + (_DWORD)v0) = 0;
  *(_DWORD *)(legacyHacks + 8) = 0;
  CL_SetADS(0);
  CG_SetEquippedOffHand(*(_DWORD *)((char *)&loc_25C94 + (_DWORD)v0));
  CG_HoldBreathInit();
  return CG_ResetLowHealthOverlay();
}

void __cdecl CG_DamageFeedback(int yawByte, int pitchByte, int damage)
{
  float v3;     // xmm3_4
  float v4;     // xmm5_4
  float *v5;    // edi
  float *v6;    // ecx
  int v7;       // esi
  int i;        // ebx
  char *v9;     // ebx
  _DWORD *v10;  // eax
  float *v12;   // eax
  float v13;    // [esp+1Ch] [ebp-6Ch]
  float v14[3]; // [esp+58h] [ebp-30h] BYREF
  float v15;    // [esp+64h] [ebp-24h] BYREF
  float v16;    // [esp+68h] [ebp-20h]
  float v17;    // [esp+6Ch] [ebp-1Ch]

  *((_DWORD *)cg + 44946) = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
  v3 = (float)a3 * 0.2;
    if (v3 >= 5.0) {
        if (v3 <= 90.0) {
          v4 = -v3;
          if (a1 != 255)
            goto LABEL_4;
          goto LABEL_12;
        }
      v3 = 90.0;
      v4 = -90.0;
    }
    else {
      v3 = 5.0;
      v4 = -5.0;
    }
  if (a1 != 255)
    goto LABEL_4;
LABEL_12:
    if (a2 == 255) {
      v12 = (float *)cg;
      *((_DWORD *)cg + 44997) = 0;
      v12[44996] = v4;
      goto LABEL_9;
    }
LABEL_4:
  v14[0] = (float)((float)a2 / 255.0) * 360.0;
  v14[1] = (float)((float)a1 / 255.0) * 360.0;
  v14[2] = 0.0;
  AngleVectors(v14, &v15, 0, 0);
  v5 = (float *)cg;
  *((float *)cg + 44997) =
      (float)((float)((float)(v15 * *((float *)cg + 41320)) +
                      (float)(v16 * *((float *)cg + 41321))) +
              (float)(v17 * *((float *)cg + 41322))) *
      v4;
  v5[44996] =
      (float)((float)((float)(v15 *
                              *(float *)((char *)&loc_28594 + (_DWORD)v5)) +
                      (float)(v16 * *(float *)((char *)&loc_28594 + (_DWORD)v5 +
                                               4))) +
              (float)(v17 * *(float *)((char *)&loc_28594 + (_DWORD)v5 + 8))) *
      v3;
  v6 = v5;
  v7 = 0;
    for (i = 1; i != 8; ++i) {
      if (*(_DWORD *)((char *)&loc_2BE80 + (_DWORD)v6) <
          SLODWORD(v5[3 * v7 + 44957]))
        v7 = i;
      v6 += 3;
    }
  v5[3 * v7 + 44957] = *(float *)(*((_DWORD *)v5 + 8) + 8);
  v9 = (char *)cg + 12 * v7;
  *((_DWORD *)v9 + 44958) = *(_DWORD *)(cg_hudDamageIconTime + 8);
  v13 = randomf();
  *((float *)v9 + 44959) =
      AngleNormalize360((float)((float)((float)a1 / 255.0) * 360.0) +
                        (float)((float)(v13 - 0.5) * 20.0));
LABEL_9:
  v10 = cg;
  *(_DWORD *)((char *)&loc_2BF0C + (_DWORD)cg) =
      *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) + 500;
  v10[44981] = *(_DWORD *)(v10[8] + 8);
  return CG_MenuShowNotify(0);
}

void __cdecl CG_CheckPlayerstateEvents(struct playerState_s *,
                                       struct playerState_s *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_TransitionPlayerState(struct playerState_s *ps,
                                      struct playerState_s *ops)
{
  char *v3;              // edi
  int32_t v4;            // ebx
  int v5;                // eax
  int v6;                // edx
  int32_t eventSequence; // eax

  if (a2->damageEvent != a3->damageEvent && a2->damageCount)
    CG_DamageFeedback(a2->damageYaw, a2->damagePitch, a2->damageCount);
  v3 = (char *)cg + 164460;
  v4 = a2->eventSequence - 4;
    do {
      eventSequence = a3->eventSequence;
        if (v4 >= eventSequence) {
          v5 = v4 & 3;
          v6 = *(_DWORD *)&a2->events[4 * v5];
        LABEL_7:
          *((_DWORD *)v3 + 100) = *(_DWORD *)&a2->eventParms[4 * v5];
          CG_EntityEvent(a1, (centity_s *)v3, v6);
          goto LABEL_8;
        }
        if (v4 > eventSequence - 4) {
          v5 = v4 & 3;
          v6 = *(_DWORD *)&a2->events[4 * v5];
          if (v6 != *(_DWORD *)&a3->events[4 * v5])
            goto LABEL_7;
        }
    LABEL_8:
      ++v4;
    }
  while (v4 < a2->eventSequence);
}
