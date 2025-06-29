float __cdecl I_rsqrt(float) { UNIMPLEMENTED(); }

bool __cdecl Com_BitCheck(int const *const, int) { UNIMPLEMENTED(); }

void __cdecl Com_BitSet(int *const, int) { UNIMPLEMENTED(); }

int __cdecl BG_PlayAnim(struct playerState_s *ps, int animNum,
                        enum animBodyPart_t bodyPart, int forceDuration,
                        int setTimer, int isContinue, int force) {
  int v7;            // ecx
  int v8;            // ebx
  int32_t torsoAnim; // edx
  int32_t v11;       // eax
  int v12;           // edx
  int32_t legsAnim;  // edx
  int32_t v14;       // eax
  int v15;           // edx
  int v16;           // [esp+0h] [ebp-10h]

  v7 = a2;
  if (!a4) {
    v8 = *(_DWORD *)&globalScriptData[96 * a2 + 72] + 50;
    if (a3 != ANIM_BP_TORSO)
      goto LABEL_3;
  LABEL_7:
    v16 = 0;
    if ((int)a1->torsoTimer <= 49)
      goto LABEL_16;
    goto LABEL_8;
  }
  v8 = a4;
  if (a3 == ANIM_BP_TORSO)
    goto LABEL_7;
LABEL_3:
  if (a3 != ANIM_BP_BOTH && a3 != ANIM_BP_LEGS)
    return -1;
  if ((int)a1->legsTimer > 49 && !a7)
    goto LABEL_13;
  if (!a6) {
    legsAnim = a1->legsAnim;
    goto LABEL_23;
  }
  legsAnim = a1->legsAnim;
  v14 = legsAnim;
  BYTE1(v14) = BYTE1(legsAnim) & 0xFD;
  if (a2 != v14) {
  LABEL_23:
    a1->legsAnimDuration = v8;
    v15 = legsAnim & 0x200;
    BYTE1(v15) ^= 2u;
    a1->legsAnim = v15 | a2;
    if (a5)
      a1->legsTimer = v8;
    v16 = 1;
    goto LABEL_14;
  }
  if (!a5 || globalScriptData[96 * a2 + 80] >= 0) {
  LABEL_13:
    v16 = 0;
    goto LABEL_14;
  }
  a1->legsTimer = v8;
  v16 = 0;
LABEL_14:
  if (a3 != ANIM_BP_BOTH)
    goto LABEL_9;
  v7 = 0;
  if ((int)a1->torsoTimer > 49) {
  LABEL_8:
    if (!a7)
      goto LABEL_9;
  }
LABEL_16:
  if (!a6) {
    torsoAnim = a1->torsoAnim;
    goto LABEL_18;
  }
  torsoAnim = a1->torsoAnim;
  v11 = torsoAnim;
  BYTE1(v11) = BYTE1(torsoAnim) & 0xFD;
  if (v7 != v11) {
  LABEL_18:
    v12 = torsoAnim & 0x200;
    BYTE1(v12) ^= 2u;
    a1->torsoAnim = v12 | v7;
    if (a5)
      a1->torsoTimer = v8;
    a1->torsoAnimDuration = v8;
    goto LABEL_9;
  }
  if (a5 && globalScriptData[96 * v7 + 80] < 0)
    a1->torsoTimer = v8;
LABEL_9:
  if (!v16)
    return -1;
  return v8;
}

void __cdecl BG_LerpOffset(float *const offset_goal, float maxOffsetChange,
                           float *const offset) {
  float v3;   // xmm5_4
  float v4;   // xmm3_4
  float v5;   // xmm4_4
  float v6;   // xmm2_4
  int result; // eax
  float v8;   // xmm0_4

  v3 = *a1 - *a3;
  v4 = a1[1] - a3[1];
  v5 = a1[2] - a3[2];
  v6 = (float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5);
  if (v6 != 0.0) {
    result = 1597463007 - (SLODWORD(v6) >> 1);
    v8 =
        (float)((float)(1.5 -
                        (float)((float)((float)(v6 * 0.5) * *(float *)&result) *
                                *(float *)&result)) *
                *(float *)&result) *
        a2;
    if (v8 < 1.0) {
      *a3 = (float)(v3 * v8) + *a3;
      a3[1] = (float)(v4 * v8) + a3[1];
      a3[2] = (float)(v5 * v8) + a3[2];
    } else {
      *a3 = *a1;
      a3[1] = a1[1];
      result = *((int *)a1 + 2);
      a3[2] = *(float *)&result;
    }
  }
  return result;
}

void __cdecl BG_UpdateConditionValue(int client, int condition, int value,
                                     int checkConversion) {
  int result; // eax
  int v5;     // edx

  if (a4 && !animConditionsTable[2 * a2]) {
    v5 = a2 + 151 * a1;
    *(_DWORD *)(bgs + 8 * v5 + 737368) = 0;
    *(_DWORD *)(bgs + 8 * v5 + 737372) = 0;
    result = 1 << (a3 & 0x1F);
    *(_DWORD *)(bgs + 8 * v5 + 737368 + 4 * (a3 >> 5)) |= result;
  } else {
    result = bgs;
    *(_DWORD *)(bgs + 8 * (a2 + 151 * a1) + 737368) = a3;
  }
  return result;
}

int __cdecl BG_ExecuteCommand(struct playerState_s *ps,
                              struct animScriptCommand_t *scriptCommand,
                              int setTimer, int isContinue, int force) {
  __int16 bodyPart;         // cx
  _BOOL4 v6;                // esi
  animScriptCommand_t *v7;  // edx
  __int16 bodyPart_high;    // bx
  int v9;                   // ecx
  int result;               // eax
  int v11;                  // edx
  int v12;                  // ecx
  int v13;                  // ebx
  int animIndex_high;       // ecx
  int v15;                  // esi
  animScriptCommand_t *v16; // eax
  int animIndex_low;        // ebx
  int v18;                  // esi
  int32_t v19;              // edx
  int32_t v20;              // eax
  int v21;                  // edx
  int32_t v22;              // edx
  int32_t v23;              // eax
  int v24;                  // edx
  int32_t v25;              // edx
  int32_t v26;              // eax
  int32_t v27;              // edx
  int32_t v28;              // eax
  int v29;                  // edx
  int32_t legsAnim;         // edx
  int32_t v31;              // eax
  int v32;                  // edx
  int32_t v33;              // edx
  int v34;                  // edx
  int32_t torsoAnim;        // edx
  int32_t v36;              // eax
  int v37;                  // edx
  int32_t v38;              // edx
  int32_t v39;              // eax
  int v40;                  // edx
  int v41;                  // edx
  int32_t v42;              // eax
  int v43;                  // [esp+10h] [ebp-28h]
  int v44;                  // [esp+14h] [ebp-24h]
  int v45;                  // [esp+18h] [ebp-20h]
  int v46;                  // [esp+1Ch] [ebp-1Ch]

  bodyPart = a2->bodyPart;
  if (!LOWORD(a2->bodyPart)) {
    v43 = -1;
    v6 = 0;
    goto LABEL_3;
  }
  v43 = SLOWORD(a2->animDuration) + 50;
  if (bodyPart == 1) {
    v16 = a2;
    goto LABEL_33;
  }
  if (bodyPart == 3) {
    v16 = a2;
  LABEL_33:
    animIndex_low = SLOWORD(v16->animIndex);
    if (SLOWORD(a2->animDuration) == -50)
      v18 = *(_DWORD *)&globalScriptData[96 * animIndex_low + 72] + 50;
    else
      v18 = SLOWORD(a2->animDuration) + 50;
    if (bodyPart == 2) {
      v44 = 0;
      goto LABEL_91;
    }
    if (bodyPart != 3 && bodyPart != 1)
      goto LABEL_38;
    if ((int)a1->legsTimer > 49 && !a5)
      goto LABEL_74;
    if (a4) {
      legsAnim = a1->legsAnim;
      v31 = legsAnim;
      BYTE1(v31) = BYTE1(legsAnim) & 0xFD;
      if (animIndex_low == v31) {
        if (a3 && globalScriptData[96 * animIndex_low + 80] < 0) {
          a1->legsTimer = v18;
          v44 = 0;
          goto LABEL_75;
        }
      LABEL_74:
        v44 = 0;
      LABEL_75:
        if (bodyPart != 3)
          goto LABEL_93;
        animIndex_low = 0;
      LABEL_91:
        if ((int)a1->torsoTimer > 49 && !a5)
          goto LABEL_93;
        if (a4) {
          torsoAnim = a1->torsoAnim;
          v36 = torsoAnim;
          BYTE1(v36) = BYTE1(torsoAnim) & 0xFD;
          if (animIndex_low == v36) {
            if (a3 && globalScriptData[96 * animIndex_low + 80] < 0)
              a1->torsoTimer = v18;
          LABEL_93:
            if (v44) {
              v6 = v18 >= 0;
              goto LABEL_3;
            }
          LABEL_38:
            v6 = 0;
            goto LABEL_3;
          }
        } else {
          torsoAnim = a1->torsoAnim;
        }
        v37 = torsoAnim & 0x200;
        BYTE1(v37) ^= 2u;
        a1->torsoAnim = v37 | animIndex_low;
        if (a3)
          a1->torsoTimer = v18;
        a1->torsoAnimDuration = v18;
        goto LABEL_93;
      }
    } else {
      legsAnim = a1->legsAnim;
    }
    a1->legsAnimDuration = v18;
    v32 = legsAnim & 0x200;
    BYTE1(v32) ^= 2u;
    a1->legsAnim = v32 | animIndex_low;
    if (a3)
      a1->legsTimer = v18;
    v44 = 1;
    goto LABEL_75;
  }
  v11 = bodyPart;
  v12 = SLOWORD(a2->animIndex);
  if (SLOWORD(a2->animDuration) == -50)
    v13 = *(_DWORD *)&globalScriptData[96 * v12 + 72] + 50;
  else
    v13 = SLOWORD(a2->animDuration) + 50;
  if (v11 == 2) {
    if ((int)a1->torsoTimer > 49 && !a5) {
      v6 = 0;
      goto LABEL_3;
    }
    if (a4) {
      v33 = a1->torsoAnim;
      v42 = v33;
      BYTE1(v42) = BYTE1(v33) & 0xFD;
      if (v12 == v42) {
        if (!a3 || globalScriptData[96 * v12 + 80] >= 0)
          goto LABEL_24;
        a1->torsoTimer = v13;
        v6 = 0;
        goto LABEL_3;
      }
    } else {
      v33 = a1->torsoAnim;
    }
    v34 = v33 & 0x200;
    BYTE1(v34) ^= 2u;
    a1->torsoAnim = v34 | v12;
    if (a3)
      a1->torsoTimer = v13;
    a1->torsoAnimDuration = v13;
    v6 = 0;
    goto LABEL_3;
  }
  if (v11 != 3 && v11 != 1)
    goto LABEL_24;
  if ((int)a1->legsTimer > 49 && !a5) {
    v6 = 0;
    goto LABEL_3;
  }
  if (a4) {
    v25 = a1->legsAnim;
    v26 = v25;
    BYTE1(v26) = BYTE1(v25) & 0xFD;
    if (v12 == v26) {
      if (!a3 || globalScriptData[96 * v12 + 80] >= 0) {
      LABEL_24:
        v6 = 0;
        goto LABEL_3;
      }
      goto LABEL_61;
    }
  } else {
    v25 = a1->legsAnim;
  }
  a1->legsAnimDuration = v13;
  v41 = v25 & 0x200;
  BYTE1(v41) ^= 2u;
  a1->legsAnim = v41 | v12;
  if (a3) {
  LABEL_61:
    a1->legsTimer = v13;
    v6 = 0;
    goto LABEL_3;
  }
  v6 = 0;
LABEL_3:
  v7 = a2;
  bodyPart_high = HIWORD(a2->bodyPart);
  if (!bodyPart_high)
    goto LABEL_12;
  v43 = SLOWORD(a2->animDuration) + 50;
  if (LOWORD(a2->bodyPart) == 1 || LOWORD(a2->bodyPart) == 3) {
    animIndex_high = SHIWORD(a2->animIndex);
    if (SLOWORD(a2->animDuration) == -50)
      v15 = *(_DWORD *)&globalScriptData[96 * animIndex_high + 72] + 50;
    else
      v15 = SLOWORD(a2->animDuration) + 50;
    if (bodyPart_high == 2) {
      v45 = 0;
      goto LABEL_101;
    }
    if (bodyPart_high != 3 && bodyPart_high != 1) {
    LABEL_30:
      v15 = -1;
    LABEL_31:
      v6 = v15 >= 0;
      v7 = a2;
      goto LABEL_12;
    }
    if ((int)a1->legsTimer > 49 && !a5)
      goto LABEL_64;
    if (a4) {
      v27 = a1->legsAnim;
      v28 = v27;
      BYTE1(v28) = BYTE1(v27) & 0xFD;
      if (animIndex_high == v28) {
        if (a3 && globalScriptData[96 * animIndex_high + 80] < 0) {
          a1->legsTimer = v15;
          v45 = 0;
          goto LABEL_65;
        }
      LABEL_64:
        v45 = 0;
      LABEL_65:
        if (bodyPart_high != 3)
          goto LABEL_103;
        animIndex_high = 0;
      LABEL_101:
        if ((int)a1->torsoTimer > 49 && !a5)
          goto LABEL_103;
        if (a4) {
          v38 = a1->torsoAnim;
          v39 = v38;
          BYTE1(v39) = BYTE1(v38) & 0xFD;
          if (animIndex_high == v39) {
            if (a3 && globalScriptData[96 * animIndex_high + 80] < 0)
              a1->torsoTimer = v15;
          LABEL_103:
            if (v45)
              goto LABEL_31;
            goto LABEL_30;
          }
        } else {
          v38 = a1->torsoAnim;
        }
        v40 = v38 & 0x200;
        BYTE1(v40) ^= 2u;
        a1->torsoAnim = v40 | animIndex_high;
        if (a3)
          a1->torsoTimer = v15;
        a1->torsoAnimDuration = v15;
        goto LABEL_103;
      }
    } else {
      v27 = a1->legsAnim;
    }
    a1->legsAnimDuration = v15;
    v29 = v27 & 0x200;
    BYTE1(v29) ^= 2u;
    a1->legsAnim = v29 | animIndex_high;
    if (a3)
      a1->legsTimer = v15;
    v45 = 1;
    goto LABEL_65;
  }
  v9 = SHIWORD(a2->animIndex);
  if (SLOWORD(a2->animDuration) == -50)
    v46 = *(_DWORD *)&globalScriptData[96 * v9 + 72] + 50;
  else
    v46 = SLOWORD(a2->animDuration) + 50;
  if (bodyPart_high == 2)
    goto LABEL_46;
  if (bodyPart_high != 3 && bodyPart_high != 1)
    goto LABEL_11;
  if ((int)a1->legsTimer <= 49 || a5) {
    if (a4) {
      v22 = a1->legsAnim;
      v23 = v22;
      BYTE1(v23) = BYTE1(v22) & 0xFD;
      if (v9 == v23) {
        if (a3 && globalScriptData[96 * v9 + 80] < 0)
          a1->legsTimer = v46;
        goto LABEL_44;
      }
    } else {
      v22 = a1->legsAnim;
    }
    a1->legsAnimDuration = v46;
    v24 = v22 & 0x200;
    BYTE1(v24) ^= 2u;
    a1->legsAnim = v24 | v9;
    if (a3)
      a1->legsTimer = v46;
  }
LABEL_44:
  if (bodyPart_high != 3)
    goto LABEL_11;
  v9 = 0;
LABEL_46:
  if ((int)a1->torsoTimer > 49 && !a5) {
    v7 = a2;
    goto LABEL_12;
  }
  if (!a4) {
    v19 = a1->torsoAnim;
    goto LABEL_49;
  }
  v19 = a1->torsoAnim;
  v20 = v19;
  BYTE1(v20) = BYTE1(v19) & 0xFD;
  if (v9 == v20) {
    if (a3 && globalScriptData[96 * v9 + 80] < 0) {
      a1->torsoTimer = v46;
      v7 = a2;
      goto LABEL_12;
    }
  LABEL_11:
    v7 = a2;
    goto LABEL_12;
  }
LABEL_49:
  v21 = v19 & 0x200;
  BYTE1(v21) ^= 2u;
  a1->torsoAnim = v21 | v9;
  if (a3)
    a1->torsoTimer = v46;
  a1->torsoAnimDuration = v46;
  v7 = a2;
LABEL_12:
  if (*(_DWORD *)v7->soundAlias)
    (*((void(__cdecl **)(uint32_t, _DWORD))globalScriptData + 184049))(
        a1->clientNum, *(_DWORD *)v7->soundAlias);
  result = -1;
  if (v6)
    return v43;
  return result;
}

void __cdecl BG_InitWeaponString(int index, char const *name) {
  char v2;     // al
  int v3;      // esi
  int *result; // eax
  int v5;      // ebx

  weaponStrings[2 * a1] = (int)a2;
  v2 = *a2;
  if (!*a2)
    goto LABEL_2;
  v3 = 0;
  v5 = 119;
  do {
    v3 += v5 * (char)__tolower(v2);
    v2 = a2[v5++ - 118];
  } while (v2);
  if (v3 == -1)
  LABEL_2:
    v3 = 0;
  result = weaponStrings;
  weaponStrings[2 * a1 + 1] = v3;
  return result;
}

void __cdecl BG_AnimUpdatePlayerStateConditions(struct pmove_t *pmove) {
  int32_t ps;                   // esi
  int32_t ViewmodelWeaponIndex; // eax
  int WeaponDef;                // edi
  int v4;                       // ebx
  int v5;                       // ecx
  int v6;                       // ebx
  int v7;                       // ecx
  int v8;                       // ecx
  int v9;                       // ecx
  int v10;                      // ecx
  int v11;                      // ecx
  int v12;                      // ebx
  int v13;                      // ecx
  int v14;                      // ecx
  int result;                   // eax
  int v16;                      // ecx

  ps = a1->ps;
  ViewmodelWeaponIndex =
      BG_GetViewmodelWeaponIndex((const playerState_s *)a1->ps);
  WeaponDef = BG_GetWeaponDef(ViewmodelWeaponIndex);
  v4 = *(_DWORD *)(WeaponDef + 116);
  v5 = *(_DWORD *)(ps + 204);
  if (!animConditionsTable[0]) {
    *(_DWORD *)(bgs + 1208 * v5 + 737368) = 0;
    *(_DWORD *)(bgs + 1208 * v5 + 737372) = 0;
    *(_DWORD *)(1208 * v5 + bgs + 737368 + 4 * (v4 >> 5)) |= 1 << (v4 & 0x1F);
    v6 = *(_DWORD *)(WeaponDef + 124);
    v7 = *(_DWORD *)(ps + 204);
    if (!dword_312F68)
      goto LABEL_3;
  LABEL_9:
    *(_DWORD *)((char *)&loc_B4060 + 1208 * v7 + bgs) = v6;
    if ((*(_BYTE *)(ps + 162) & 4) != 0)
      goto LABEL_4;
  LABEL_10:
    v10 = *(_DWORD *)(ps + 204);
    if (dword_312F98) {
      *(_DWORD *)(bgs + 1208 * v10 + 737424) = 0;
    } else {
      *(_DWORD *)(bgs + 1208 * v10 + 737424) = 0;
      *(_DWORD *)(bgs + 1208 * v10 + 737428) = 0;
      *(_DWORD *)(1208 * v10 + bgs + 737424) |= 1u;
    }
    goto LABEL_12;
  }
  *(_DWORD *)(bgs + 1208 * v5 + 737368) = v4;
  v6 = *(_DWORD *)(WeaponDef + 124);
  v7 = *(_DWORD *)(ps + 204);
  if (dword_312F68)
    goto LABEL_9;
LABEL_3:
  *(_DWORD *)((char *)&loc_B4060 + 1208 * v7 + bgs) = 0;
  *(_DWORD *)(bgs + 1208 * v7 + 737380) = 0;
  *(_DWORD *)((char *)&loc_B4060 + 1208 * v7 + 4 * (v6 >> 5) + bgs) |=
      1 << (v6 & 0x1F);
  if ((*(_BYTE *)(ps + 162) & 4) == 0)
    goto LABEL_10;
LABEL_4:
  v8 = *(_DWORD *)(ps + 204);
  if (dword_312F98) {
    *(_DWORD *)(bgs + 1208 * v8 + 737424) = 1;
    if ((*(_DWORD *)(ps + 160) & 0x300) == 0)
      goto LABEL_6;
  LABEL_13:
    v11 = *(_DWORD *)(ps + 204);
    if (dword_312F70) {
      *(_DWORD *)(bgs + 1208 * v11 + 737384) = 1;
    } else {
      *(_DWORD *)(bgs + 1208 * v11 + 737384) = 0;
      *(_DWORD *)(bgs + 1208 * v11 + 737388) = 0;
      *(_DWORD *)(1208 * v11 + bgs + 737384) |= 2u;
    }
    goto LABEL_15;
  }
  *(_DWORD *)(bgs + 1208 * v8 + 737424) = 0;
  *(_DWORD *)(bgs + 1208 * v8 + 737428) = 0;
  *(_DWORD *)(1208 * v8 + bgs + 737424) |= 2u;
LABEL_12:
  if ((*(_DWORD *)(ps + 160) & 0x300) != 0)
    goto LABEL_13;
LABEL_6:
  v9 = *(_DWORD *)(ps + 204);
  if (dword_312F70) {
    *(_DWORD *)(bgs + 1208 * v9 + 737384) = 0;
  } else {
    *(_DWORD *)(bgs + 1208 * v9 + 737384) = 0;
    *(_DWORD *)(bgs + 1208 * v9 + 737388) = 0;
    *(_DWORD *)(1208 * v9 + bgs + 737384) |= 1u;
  }
LABEL_15:
  v12 = *(float *)(ps + 232) > 0.0;
  v13 = *(_DWORD *)(ps + 204);
  if (dword_312F80) {
    *(_DWORD *)(bgs + 1208 * v13 + 737400) = v12;
  } else {
    *(_DWORD *)(bgs + 1208 * v13 + 737400) = 0;
    *(_DWORD *)(bgs + 1208 * v13 + 737404) = 0;
    *(_DWORD *)(1208 * v13 + bgs + 737400) |= 1 << v12;
  }
  if ((a1->cmd[4] & 1) != 0) {
    v14 = *(_DWORD *)(ps + 204);
    if (dword_312F90) {
      result = bgs + 1208 * v14;
      *(_DWORD *)(result + 737416) = 1;
    } else {
      result = 1208 * v14;
      *(_DWORD *)(bgs + 1208 * v14 + 737416) = 0;
      *(_DWORD *)(bgs + 1208 * v14 + 737420) = 0;
      *(_DWORD *)(1208 * v14 + bgs + 737416) |= 2u;
    }
  } else {
    v16 = *(_DWORD *)(ps + 204);
    if (dword_312F90) {
      result = bgs + 1208 * v16;
      *(_DWORD *)(result + 737416) = 0;
    } else {
      result = 1208 * v16;
      *(_DWORD *)(bgs + 1208 * v16 + 737416) = 0;
      *(_DWORD *)(bgs + 1208 * v16 + 737420) = 0;
      *(_DWORD *)(1208 * v16 + bgs + 737416) |= 1u;
    }
  }
  return result;
}

int __cdecl BG_GetAnimScriptEvent(struct playerState_s *,
                                  enum scriptAnimEventTypes_t) {
  UNIMPLEMENTED();
}

int __cdecl BG_AnimScriptEvent(struct playerState_s *ps,
                               enum scriptAnimEventTypes_t event,
                               int isContinue, int force) {
  char *v4;     // eax
  int v5;       // ecx
  int *v7;      // edi
  int *v8;      // ebx
  int i;        // esi
  int v10;      // edx
  int v11;      // eax
  int v12;      // eax
  int **v13;    // [esp+30h] [ebp-28h]
  int v14;      // [esp+34h] [ebp-24h]
  uint32_t v15; // [esp+38h] [ebp-20h]
  int v16;      // [esp+3Ch] [ebp-1Ch]

  if (a2 != ANIM_ET_DEATH && a1->pm_type > 5)
    return -1;
  v4 = &globalScriptData[516 * a2 + 226656];
  v5 = *((_DWORD *)v4 + 1);
  if (!v5)
    return -1;
  v13 = (int **)(v4 + 8);
  if (v5 <= 0)
    return -1;
  v15 = bgs + 1208 * a1->clientNum + 736252;
  v14 = 0;
LABEL_7:
  v7 = *v13;
  v8 = *v13 + 1;
  v16 = **v13;
  if (v16 > 0) {
    for (i = 0; v16 != i; ++i) {
      v10 = *v8;
      v11 = animConditionsTable[2 * *v8];
      if (v11) {
        if (v11 == 1 && *(_DWORD *)(v15 + 8 * v10 + 1116) != v8[1]) {
        LABEL_14:
          ++v14;
          ++v13;
          if (v5 == v14)
            return -1;
          goto LABEL_7;
        }
      } else if ((*(_DWORD *)(v15 + 8 * v10 + 1116) & v8[1]) == 0 &&
                 (*(_DWORD *)(v15 + 8 * v10 + 1120) & v8[2]) == 0) {
        goto LABEL_14;
      }
      v8 += 3;
    }
  }
  if (!v7[28])
    return -1;
  v12 = rand();
  return BG_ExecuteCommand(
      a1, (animScriptCommand_t *)&v7[4 * (v12 % v7[28]) + 29], 1, a3, a4);
}

int __cdecl BG_AnimScriptStateChange(struct playerState_s *, enum aistateEnum_t,
                                     enum aistateEnum_t) {
  UNIMPLEMENTED();
}

int __cdecl BG_AnimScriptAnimation(struct playerState_s *ps,
                                   enum aistateEnum_t state,
                                   enum scriptAnimMoveTypes_t movetype,
                                   int isContinue) {
  char *v5;           // eax
  int v6;             // edi
  int *v7;            // ecx
  int i;              // esi
  int v9;             // edx
  int v10;            // eax
  int v11;            // edx
  int *v12;           // [esp+34h] [ebp-34h]
  uint32_t clientNum; // [esp+38h] [ebp-30h]
  int **v14;          // [esp+40h] [ebp-28h]
  int v15;            // [esp+44h] [ebp-24h]
  uint32_t v16;       // [esp+48h] [ebp-20h]
  int v17;            // [esp+4Ch] [ebp-1Ch]

  if (a1->pm_type > 5 || a2 < AISTATE_RELAXED)
    return -1;
  while (1) {
    v5 = &globalScriptData[21156 * a2 + 49152 + 516 * a3];
    v6 = *((_DWORD *)v5 + 1);
    if (v6) {
      clientNum = a1->clientNum;
      v14 = (int **)(v5 + 8);
      if (v6 > 0)
        break;
    }
  LABEL_15:
    if (--a2 < AISTATE_RELAXED)
      return -1;
  }
  v16 = bgs + 1208 * a1->clientNum + 736252;
  v15 = 0;
LABEL_7:
  v12 = *v14;
  v7 = *v14 + 1;
  v17 = **v14;
  if (v17 > 0) {
    for (i = 0; v17 != i; ++i) {
      v9 = *v7;
      v10 = animConditionsTable[2 * *v7];
      if (v10) {
        if (v10 == 1 && *(_DWORD *)(v16 + 8 * v9 + 1116) != v7[1]) {
        LABEL_14:
          ++v15;
          ++v14;
          if (v6 == v15)
            goto LABEL_15;
          goto LABEL_7;
        }
      } else if ((*(_DWORD *)(v16 + 8 * v9 + 1116) & v7[1]) == 0 &&
                 (*(_DWORD *)(v16 + 8 * v9 + 1120) & v7[2]) == 0) {
        goto LABEL_14;
      }
      v7 += 3;
    }
  }
  if (!v12[28])
    return -1;
  if (dword_312F78) {
    *(_DWORD *)((char *)&loc_B4070 + 1208 * clientNum + bgs) = a3;
  } else {
    v11 = 1208 * clientNum;
    *(_DWORD *)((char *)&loc_B4070 + v11 + bgs) = 0;
    *(_DWORD *)(bgs + v11 + 737396) = 0;
    *(_DWORD *)((char *)&loc_B4070 + 1208 * clientNum + 4 * (a3 >> 5) + bgs) |=
        1 << (a3 & 0x1F);
  }
  return BG_ExecuteCommand(
             a1,
             (animScriptCommand_t
                  *)&v12[4 * ((signed int)a1->clientNum % v12[28]) + 29],
             0, a4, 0) != -1;
}

void __cdecl BG_InitWeaponStrings() { UNIMPLEMENTED(); }

void __cdecl BG_Player_DoControllers(struct DObj_s const *pDObj,
                                     struct entityState_s const *es,
                                     int *const partBits,
                                     struct clientInfo_t *ci, int frametime) {
  uint32_t eFlags;          // ecx
  int32_t fTorsoHeight;     // edi
  float v7;                 // xmm2_4
  float v8;                 // xmm3_4
  uint32_t v9;              // eax
  float v10;                // xmm1_4
  float v11;                // xmm2_4
  float v12;                // xmm3_4
  float v13;                // xmm0_4
  float v14;                // xmm0_4
  int v15;                  // ebx
  int v16;                  // edx
  float v17;                // xmm3_4
  unsigned __int16 **v18;   // edi
  float *v19;               // ebx
  int v20;                  // esi
  _DWORD *v21;              // ecx
  int i;                    // edx
  float *v23;               // eax
  float v24;                // xmm0_4
  float v25;                // xmm1_4
  float *tag_origin_angles; // esi
  int j;                    // edx
  float *v28;               // eax
  float v29;                // xmm0_4
  float v30;                // xmm1_4
  float v32;                // xmm0_4
  float v33;                // xmm0_4
  float v34;                // xmm3_4
  float v35;                // xmm0_4
  float v36;                // xmm1_4
  float v37;                // xmm1_4
  float LeanFraction;       // [esp+2Ch] [ebp-16Ch]
  float v39;                // [esp+2Ch] [ebp-16Ch]
  float v40;                // [esp+2Ch] [ebp-16Ch]
  float v41;                // [esp+8Ch] [ebp-10Ch]
  int v42;                  // [esp+90h] [ebp-108h]
  float v43;                // [esp+98h] [ebp-100h]
  float v44;                // [esp+9Ch] [ebp-FCh]
  float v45;                // [esp+A4h] [ebp-F4h]
  float v46;                // [esp+A8h] [ebp-F0h]
  _DWORD __b[24];           // [esp+B4h] [ebp-E4h] BYREF
  float v48;                // [esp+114h] [ebp-84h] BYREF
  float v49;                // [esp+118h] [ebp-80h]
  float v50;                // [esp+11Ch] [ebp-7Ch]
  float v51;                // [esp+120h] [ebp-78h]
  float v52;                // [esp+124h] [ebp-74h]
  float v53;                // [esp+128h] [ebp-70h]
  float v54;                // [esp+12Ch] [ebp-6Ch]
  float v55;                // [esp+130h] [ebp-68h]
  float v56;                // [esp+134h] [ebp-64h]
  float v57;                // [esp+138h] [ebp-60h]
  float v58;                // [esp+13Ch] [ebp-5Ch]
  int v59;                  // [esp+140h] [ebp-58h]
  float v60;                // [esp+144h] [ebp-54h]
  float v61;                // [esp+148h] [ebp-50h]
  float v62;                // [esp+14Ch] [ebp-4Ch]
  float v63;                // [esp+150h] [ebp-48h]
  int v64;                  // [esp+154h] [ebp-44h]
  int v65;                  // [esp+158h] [ebp-40h]
  float v66;                // [esp+15Ch] [ebp-3Ch] BYREF
  float v67;                // [esp+160h] [ebp-38h]
  float v68;                // [esp+164h] [ebp-34h]
  float v69;                // [esp+168h] [ebp-30h] BYREF
  float v70;                // [esp+16Ch] [ebp-2Ch]
  float v71;                // [esp+170h] [ebp-28h]
  float v72;                // [esp+174h] [ebp-24h] BYREF
  float yawAngle;           // [esp+178h] [ebp-20h]
  float v74;                // [esp+17Ch] [ebp-1Ch]

  eFlags = a2->eFlags;
  if ((eFlags & 0x300) != 0) {
    memset(__b, 0, sizeof(__b));
    goto LABEL_17;
  }
  v72 = 0.0;
  v74 = 0.0;
  v69 = 0.0;
  v71 = 0.0;
  v66 = a4->playerAngles[0];
  v67 = a4->playerAngles[1];
  v68 = a4->playerAngles[2];
  yawAngle = a4->legs.yawAngle;
  v70 = *(float *)a4->torso;
  if ((LODWORD(a4->clientConditions[2][0]) & 0xC0000) == 0) {
    v36 = *(float *)&a4->torso[8];
    v69 = v36;
    if ((eFlags & 8) != 0) {
      v40 = AngleNormalize180(v36);
      v69 = v40;
      if (v40 <= 0.0)
        v37 = v40 * 0.25;
      else
        v37 = v40 * 0.5;
      v69 = v37;
    }
  }
  AnglesSubtract(&v66, &v69, &v66);
  AnglesSubtract(&v69, &v72, &v69);
  fTorsoHeight = a2->fTorsoHeight;
  LeanFraction = GetLeanFraction(*(float *)&a4->lerpLean);
  v7 = LeanFraction;
  v8 = LeanFraction * 50.0;
  v71 = (float)(LeanFraction * 50.0) * 0.92500001;
  v68 = v71;
  if (LeanFraction == 0.0) {
    v45 = 0.0;
    v9 = a2->eFlags;
    goto LABEL_5;
  }
  v9 = a2->eFlags;
  if ((v9 & 4) != 0) {
    if (LeanFraction > 0.0)
      goto LABEL_30;
    v45 = (float)(LeanFraction * -12.5) + 0.0;
  LABEL_5:
    if ((v9 & 0x20000) != 0)
      goto LABEL_6;
    goto LABEL_31;
  }
  if (LeanFraction <= 0.0) {
    v45 = (float)(LeanFraction * -5.0) + 0.0;
    goto LABEL_5;
  }
LABEL_30:
  v45 = (float)(LeanFraction * -2.5) + 0.0;
  if ((v9 & 0x20000) != 0) {
  LABEL_6:
    if ((v9 & 8) == 0)
      goto LABEL_7;
  LABEL_32:
    if (v7 != 0.0)
      v68 = 0.5 * v68;
    v72 = v72 + *(float *)&a2->fTorsoPitch;
    v32 = v70 * 0.0174532925199433;
    v39 = sinf(v32);
    v41 = cosf(v32);
    v46 = (float)((float)(1.0 - v41) * -24.0) + 0.0;
    v33 = (float)(v39 * -12.0) + v45;
    v45 = v33;
    if ((float)(v39 * v7) > 0.0)
      v45 = (float)((float)((float)(1.0 - v41) * (float)-v7) * 16.0) + v33;
    v48 = 0.0;
    v34 = v71;
    v49 = v71 * -1.2;
    v50 = v71 * 0.30000001;
    v35 = *(float *)&a2->fTorsoPitch;
    if (v35 != 0.0 || *(float *)&a2->fWaistPitch != 0.0) {
      v43 = AngleSubtract(v35, *(float *)&a2->fWaistPitch);
      v48 = v48 + v43;
      v34 = v71;
    }
    v51 = 0.0;
    v52 = (float)(v70 * 0.1) + (float)(v34 * -0.2);
    v53 = v34 * 0.2;
    v54 = v69;
    v55 = (float)(v70 * 0.80000001) + v71;
    v56 = v34 * -0.2;
    goto LABEL_11;
  }
LABEL_31:
  yawAngle = AngleSubtract(yawAngle, a4->playerAngles[1]);
  v9 = a2->eFlags;
  v8 = LeanFraction * 50.0;
  v7 = LeanFraction;
  if ((v9 & 8) != 0)
    goto LABEL_32;
LABEL_7:
  if (v7 != 0.0 && ((v9 & 4) == 0 || v7 <= 0.0)) {
    v71 = v71 * 1.25;
    v68 = 1.25 * v68;
  }
  v74 = (float)(v8 * 0.075000003) + v74;
  v10 = v69;
  v48 = v69 * 0.2;
  v11 = v70;
  v49 = v70 * 0.40000001;
  v12 = v71;
  v50 = v71 * 0.5;
  v13 = *(float *)&a2->fTorsoPitch;
  if (v13 != 0.0 || *(float *)&a2->fWaistPitch != 0.0) {
    v44 = AngleSubtract(v13, *(float *)&a2->fWaistPitch);
    v48 = v48 + v44;
    v12 = v71;
    v11 = v70;
    v10 = v69;
  }
  v51 = v10 * 0.30000001;
  v52 = 0.40000001 * v11;
  v53 = v12 * 0.5;
  v54 = 0.5 * v10;
  v55 = v11 * 0.2;
  v56 = v12 * -0.60000002;
  v46 = 0.0;
LABEL_11:
  v57 = v66 * 0.30000001;
  v58 = 0.30000001 * v67;
  v59 = 0;
  v60 = v66 * 0.69999999;
  v61 = v67 * 0.69999999;
  v62 = -0.30000001 * v68;
  v63 = 0.0;
  v64 = 0;
  v65 = 0;
  v14 = *(float *)&a2->fWaistPitch;
  if (v14 != 0.0 || *(float *)&a2->fTorsoPitch != 0.0)
    v63 = AngleSubtract(v14, *(float *)&a2->fTorsoPitch);
  v15 = 0;
  v16 = 0;
  do {
    __b[v16] = *(_DWORD *)((char *)&v48 + v16 * 4);
    __b[v16 + 1] = *(_DWORD *)((char *)&v48 + v16 * 4 + 4);
    __b[v16 + 2] = *(_DWORD *)((char *)&v48 + v16 * 4 + 8);
    ++v15;
    v16 += 3;
  } while (v15 != 6);
  *(float *)&__b[18] = v72;
  *(float *)&__b[19] = yawAngle;
  *(float *)&__b[20] = v74;
  *(float *)&__b[21] = v46;
  *(float *)&__b[22] = v45;
  __b[23] = fTorsoHeight;
LABEL_17:
  v17 = (float)a5 * 0.36000001;
  v42 = 0;
  v18 = (unsigned __int16 **)&controller_names;
  v19 = a4->angles[0];
  v20 = 0;
  do {
    v21 = &__b[v20];
    for (i = 1; i != 4; ++i) {
      v23 = &v19[i];
      v24 = *(v23 - 1);
      v25 = *(float *)&v21[i - 1] - v24;
      if (v25 <= v17) {
        if ((float)-v17 <= v25)
          *(v23 - 1) = *(float *)&v21[i - 1];
        else
          *(v23 - 1) = v24 - v17;
      } else {
        *(v23 - 1) = v24 + v17;
      }
    }
    DObjSetControlTagAngles(a1, a3, **v18, v19);
    ++v42;
    v20 += 3;
    v19 += 3;
    ++v18;
  } while (v42 != 6);
  tag_origin_angles = a4->tag_origin_angles;
  for (j = 1; j != 4; ++j) {
    v28 = &tag_origin_angles[j];
    v29 = *(v28 - 1);
    v30 = *(float *)&__b[j + 17] - v29;
    if (v30 <= v17) {
      if ((float)-v17 <= v30)
        *(v28 - 1) = *(float *)&__b[j + 17];
      else
        *(v28 - 1) = v29 - v17;
    } else {
      *(v28 - 1) = v29 + v17;
    }
  }
  BG_LerpOffset((float *)&__b[21], (float)a5 * 0.1, a4->tag_origin_offset);
  return DObjSetLocalTag(a1, a3, (unsigned __int16)word_195B122,
                         a4->tag_origin_offset, tag_origin_angles);
}

void __cdecl BG_UpdatePlayerDObj(struct DObj_s *pDObj, struct entityState_s *es,
                                 struct clientInfo_t *ci,
                                 int attachIgnoreCollision) {
  UNIMPLEMENTED();
}

struct animation_s *__cdecl BG_GetAnimationForIndex(int, int) {
  UNIMPLEMENTED();
}

struct animation_s *__cdecl BG_AnimationForString(char const *) {
  UNIMPLEMENTED();
}

void __cdecl BG_AnimParseError(char const *msg, ...) { UNIMPLEMENTED(); }

int __cdecl BG_IsMantleAnim(struct clientInfo_t *, int) { UNIMPLEMENTED(); }

int __cdecl BG_IsProneAnim(struct clientInfo_t *, int) { UNIMPLEMENTED(); }

int __cdecl BG_IsCrouchingAnim(struct clientInfo_t *, int) { UNIMPLEMENTED(); }

char *__cdecl BG_GetAnimString(int, int) { UNIMPLEMENTED(); }

char *__cdecl BG_CopyStringIntoBuffer(char const *, char *, int, int *) {
  UNIMPLEMENTED();
}

int __cdecl BG_IndexForString(char const *token,
                              struct animStringItem_t *strings, int allowFail) {
  UNIMPLEMENTED();
}

int __cdecl BG_AnimationIndexForString(char const *string) { UNIMPLEMENTED(); }

int __cdecl BG_PlayAnimName(struct playerState_s *, char *, enum animBodyPart_t,
                            int, int, int) {
  UNIMPLEMENTED();
}

void __cdecl BG_ParseCommands(char const **input,
                              struct animScriptItem_t *scriptItem,
                              struct animScriptData_t *scriptData) {
  UNIMPLEMENTED();
}

void __cdecl BG_PlayerAnimation(struct DObj_s const *pDObj,
                                struct entityState_s *es,
                                struct clientInfo_t *ci) {
  uint32_t eFlags;               // edx
  float v4;                      // xmm4_4
  float v5;                      // xmm0_4
  float v6;                      // xmm2_4
  uint32_t v7;                   // eax
  entityState_s *v8;             // eax
  uint32_t v9;                   // edx
  float v10;                     // xmm0_4
  int WeaponDef;                 // esi
  int v12;                       // ebx
  uint32_t clientNum;            // ecx
  int v14;                       // ebx
  uint32_t v15;                  // ecx
  entityState_s *v16;            // eax
  uint32_t v17;                  // ecx
  uint32_t v18;                  // ecx
  int v19;                       // ebx
  uint32_t v20;                  // ecx
  uint32_t v21;                  // ecx
  uint32_t v22;                  // ecx
  unsigned int v23;              // edi
  int v24;                       // edx
  int v25;                       // ecx
  int v26;                       // eax
  uint32_t v27;                  // ecx
  int v28;                       // eax
  const XAnimTree_s *pXAnimTree; // ebx
  unsigned int v30;              // eax
  unsigned int v31;              // eax
  float v33;                     // eax
  int32_t legsAnim;              // eax
  uint32_t v35;                  // ecx
  uint32_t v36;                  // ecx
  uint32_t v37;                  // ecx
  uint32_t v38;                  // ecx
  uint32_t v39;                  // ecx
  int32_t *p_yawing;             // edx
  int v41;                       // ecx
  lerpFrame_t *v42;              // eax
  uint32_t v43;                  // ecx
  int v44;                       // eax
  float v45;                     // xmm0_4
  int v46;                       // eax
  int v47;                       // ebx
  int *p_legs;                   // [esp+28h] [ebp-40h]
  int v49;                       // [esp+2Ch] [ebp-3Ch]
  float v50;                     // [esp+38h] [ebp-30h]
  float Weight;                  // [esp+3Ch] [ebp-2Ch]
  float v52;                     // [esp+40h] [ebp-28h]
  float v53;                     // [esp+44h] [ebp-24h]
  float v54;                     // [esp+48h] [ebp-20h]
  float v55;                     // [esp+4Ch] [ebp-1Ch]

  GetLeanFraction(*(float *)&a3->lerpLean);
  v50 = *(float *)&a3->lerpMoveDir;
  v53 = a3->playerAngles[0];
  v55 = AngleMod(a3->playerAngles[1]);
  eFlags = a2->eFlags;
  if ((eFlags & 0x300) != 0) {
    *(_DWORD *)&a3->torso[4] = 1;
    *(_DWORD *)&a3->torso[12] = 1;
    a3->legs.yawing = 1;
    eFlags = a2->eFlags;
  } else {
    v33 = a3->clientConditions[2][0];
    if ((LODWORD(v33) & 0xC0000) != 0) {
      *(_DWORD *)&a3->torso[4] = 1;
      *(_DWORD *)&a3->torso[12] = 1;
      a3->legs.yawing = 1;
      eFlags = a2->eFlags;
    } else if ((eFlags & 0x4000) != 0) {
      *(_DWORD *)&a3->torso[4] = 1;
      *(_DWORD *)&a3->torso[12] = 1;
      a3->legs.yawing = 1;
      eFlags = a2->eFlags;
    } else if ((LOBYTE(v33) & 6) != 0) {
      v47 = LODWORD(a3->clientConditions[4][0]);
      if (dword_312F90) {
      LABEL_108:
        if (v47) {
          *(_DWORD *)&a3->torso[4] = 1;
          *(_DWORD *)&a3->torso[12] = 1;
          eFlags = a2->eFlags;
        }
      } else if ((v47 & 1) == 0) {
        v47 = 0;
        while (++v47 != 64) {
          if (((SLODWORD(a3->clientConditions[4][v47 >> 5]) >> (v47 & 0x1F)) &
               1) != 0)
            goto LABEL_108;
        }
      }
    } else {
      *(_DWORD *)&a3->torso[4] = 1;
      *(_DWORD *)&a3->torso[12] = 1;
      a3->legs.yawing = 1;
      eFlags = a2->eFlags;
    }
  }
  v54 = v50 + v55;
  if ((eFlags & 0x20000) != 0)
    goto LABEL_6;
  if ((LODWORD(a3->clientConditions[2][0]) & 0xC0000) != 0) {
    v4 = v50 + v55;
    v5 = v50 + v55;
    v6 = 0.0;
    goto LABEL_7;
  }
  if ((eFlags & 0x4000) != 0) {
  LABEL_6:
    v4 = v55;
    v5 = v55;
    v6 = 90.0;
    goto LABEL_7;
  }
  if ((eFlags & 8) != 0) {
  LABEL_102:
    v4 = v50 + v55;
    v5 = v55;
    v6 = 90.0;
    goto LABEL_7;
  }
  if ((eFlags & 0x40) == 0) {
    if ((eFlags & 0x40000) == 0) {
      v5 = (float)(v50 * 0.30000001) + v55;
      v4 = v50 + v55;
      v6 = 90.0;
      goto LABEL_7;
    }
    goto LABEL_102;
  }
  v4 = v50 + v55;
  v5 = v55;
  v6 = 45.0;
LABEL_7:
  BG_SwingAngles((float *)a3->torso, &a3->torso[4], v5, 0.0, v6,
                 *(float *)(bg_swingSpeed + 8));
  v7 = a2->eFlags;
  if ((v7 & 0x20000) != 0) {
    p_yawing = &a3->legs.yawing;
    p_legs = (int *)&a3->legs;
    v41 = bg_swingSpeed;
    v42 = &a3->legs;
  LABEL_76:
    BG_SwingAngles(&v42->yawAngle, p_yawing, v4, 0.0, 150.0,
                   *(float *)(v41 + 8));
    goto LABEL_10;
  }
  if ((v7 & 8) != 0) {
    a3->legs.yawing = 0;
    a3->legs.yawAngle = v54;
    p_legs = (int *)&a3->legs;
    goto LABEL_10;
  }
  legsAnim = a2->legsAnim;
  BYTE1(legsAnim) &= ~2u;
  if ((*(_BYTE *)(bgs + 96 * legsAnim + 80) & 0x30) != 0) {
    a3->legs.yawing = 0;
    p_legs = (int *)&a3->legs;
    BG_SwingAngles(&a3->legs.yawAngle, &a3->legs.yawing, v55, 0.0, 150.0,
                   *(float *)(bg_swingSpeed + 8));
  LABEL_10:
    v8 = a2;
    v9 = a2->eFlags;
    if ((v9 & 0x300) == 0)
      goto LABEL_11;
  LABEL_54:
    *(float *)a3->torso = v55;
    a3->legs.yawAngle = v55;
    v9 = v8->eFlags;
    goto LABEL_13;
  }
  if (a3->legs.yawing) {
    p_yawing = &a3->legs.yawing;
    v42 = &a3->legs;
    p_legs = (int *)&a3->legs;
    v41 = bg_swingSpeed;
    goto LABEL_76;
  }
  p_legs = (int *)&a3->legs;
  BG_SwingAngles(&a3->legs.yawAngle, &a3->legs.yawing, v4, 40.0, 150.0,
                 *(float *)(bg_swingSpeed + 8));
  v8 = a2;
  v9 = a2->eFlags;
  if ((v9 & 0x300) != 0)
    goto LABEL_54;
LABEL_11:
  if ((LODWORD(a3->clientConditions[2][0]) & 0xC0000) != 0) {
    *(float *)a3->torso = v54;
    a3->legs.yawAngle = v54;
    v9 = a2->eFlags;
  }
LABEL_13:
  if ((v9 & 0x20000) != 0 || (v9 & 0x300) != 0 ||
      (LODWORD(a3->clientConditions[2][0]) & 0xC0000) != 0 || v9 == 0x4000) {
    v10 = 0.0;
  } else {
    v45 = v53;
    if (v53 > 180.0)
      v45 = v53 - 360.0;
    v10 = v45 * 0.60000002;
  }
  BG_SwingAngles((float *)&a3->torso[8], &a3->torso[12], v10, 0.0, 45.0,
                 0.15000001);
  WeaponDef = BG_GetWeaponDef(a2->weapon);
  v12 = *(_DWORD *)(WeaponDef + 116);
  clientNum = a2->clientNum;
  if (animConditionsTable[0]) {
    *(_DWORD *)(bgs + 1208 * clientNum + 737368) = v12;
  } else {
    *(_DWORD *)(bgs + 1208 * clientNum + 737368) = 0;
    *(_DWORD *)(bgs + 1208 * clientNum + 737372) = 0;
    *(_DWORD *)(1208 * clientNum + bgs + 737368 + 4 * (v12 >> 5)) |=
        1 << (v12 & 0x1F);
  }
  v14 = *(_DWORD *)(WeaponDef + 124);
  v15 = a2->clientNum;
  if (!dword_312F68) {
    *(_DWORD *)((char *)&loc_B4060 + 1208 * v15 + bgs) = 0;
    *(_DWORD *)(bgs + 1208 * v15 + 737380) = 0;
    *(_DWORD *)((char *)&loc_B4060 + 1208 * v15 + 4 * (v14 >> 5) + bgs) |=
        1 << (v14 & 0x1F);
    v16 = a2;
    if ((a2->eFlags & 0x40000) != 0)
      goto LABEL_21;
  LABEL_71:
    v39 = v16->clientNum;
    if (dword_312F98) {
      *(_DWORD *)(bgs + 1208 * v39 + 737424) = 0;
    } else {
      *(_DWORD *)(bgs + 1208 * v39 + 737424) = 0;
      *(_DWORD *)(bgs + 1208 * v39 + 737428) = 0;
      *(_DWORD *)(1208 * v39 + bgs + 737424) |= 1u;
    }
    goto LABEL_23;
  }
  *(_DWORD *)((char *)&loc_B4060 + 1208 * v15 + bgs) = v14;
  v16 = a2;
  if ((a2->eFlags & 0x40000) == 0)
    goto LABEL_71;
LABEL_21:
  v17 = v16->clientNum;
  if (dword_312F98) {
    *(_DWORD *)(bgs + 1208 * v17 + 737424) = 1;
  } else {
    *(_DWORD *)(bgs + 1208 * v17 + 737424) = 0;
    *(_DWORD *)(bgs + 1208 * v17 + 737428) = 0;
    *(_DWORD *)(1208 * v17 + bgs + 737424) |= 2u;
  }
LABEL_23:
  if ((a2->eFlags & 0x300) != 0) {
    v18 = a2->clientNum;
    if (dword_312F70) {
      *(_DWORD *)(bgs + 1208 * v18 + 737384) = 1;
    } else {
      *(_DWORD *)(bgs + 1208 * v18 + 737384) = 0;
      *(_DWORD *)(bgs + 1208 * v18 + 737388) = 0;
      *(_DWORD *)(1208 * v18 + bgs + 737384) |= 2u;
    }
  } else {
    v37 = a2->clientNum;
    if (dword_312F70) {
      *(_DWORD *)(bgs + 1208 * v37 + 737384) = 0;
    } else {
      *(_DWORD *)(bgs + 1208 * v37 + 737384) = 0;
      *(_DWORD *)(bgs + 1208 * v37 + 737388) = 0;
      *(_DWORD *)(1208 * v37 + bgs + 737384) |= 1u;
    }
  }
  v19 = a3->playerAngles[0] > 0.0;
  v20 = a2->clientNum;
  if (dword_312F80) {
    *(_DWORD *)(bgs + 1208 * v20 + 737400) = v19;
  } else {
    *(_DWORD *)(bgs + 1208 * v20 + 737400) = 0;
    *(_DWORD *)(bgs + 1208 * v20 + 737404) = 0;
    *(_DWORD *)(1208 * v20 + bgs + 737400) |= 1 << v19;
  }
  if ((a2->eFlags & 4) != 0) {
    v21 = a2->clientNum;
    if (dword_312F88) {
      *(_DWORD *)(bgs + 1208 * v21 + 737408) = 1;
    } else {
      *(_DWORD *)(bgs + 1208 * v21 + 737408) = 0;
      *(_DWORD *)((char *)&loc_B4084 + 1208 * v21 + bgs) = 0;
      *(_DWORD *)(1208 * v21 + bgs + 737408) |= 2u;
    }
  } else {
    v38 = a2->clientNum;
    if (dword_312F88) {
      *(_DWORD *)(bgs + 1208 * v38 + 737408) = 0;
    } else {
      *(_DWORD *)(bgs + 1208 * v38 + 737408) = 0;
      *(_DWORD *)((char *)&loc_B4084 + 1208 * v38 + bgs) = 0;
      *(_DWORD *)(1208 * v38 + bgs + 737408) |= 1u;
    }
  }
  if ((a2->eFlags & 0x40) != 0) {
    v22 = a2->clientNum;
    if (dword_312F90) {
      *(_DWORD *)(bgs + 1208 * v22 + 737416) = 1;
    } else {
      *(_DWORD *)(bgs + 1208 * v22 + 737416) = 0;
      *(_DWORD *)(bgs + 1208 * v22 + 737420) = 0;
      *(_DWORD *)(1208 * v22 + bgs + 737416) |= 2u;
    }
  } else {
    v36 = a2->clientNum;
    if (dword_312F90) {
      *(_DWORD *)(bgs + 1208 * v36 + 737416) = 0;
    } else {
      *(_DWORD *)(bgs + 1208 * v36 + 737416) = 0;
      *(_DWORD *)(bgs + 1208 * v36 + 737420) = 0;
      *(_DWORD *)(1208 * v36 + bgs + 737416) |= 1u;
    }
  }
  v23 = a2->legsAnim & 0xFFFFFDFF;
  v49 = bgs;
  v24 = bgs;
  if (!*(_QWORD *)(96 * v23 + bgs + 84))
    goto LABEL_37;
  if (LODWORD(a3->clientConditions[2][0]) != *(_QWORD *)(96 * v23 + bgs + 84)) {
    *(_DWORD *)((char *)&loc_B4070 + 1208 * a2->clientNum + bgs) =
        *(_DWORD *)(96 * v23 + bgs + 84);
    v24 = bgs;
    v49 = bgs;
  LABEL_37:
    v25 = v24;
    goto LABEL_38;
  }
  v25 = bgs;
LABEL_38:
  v26 = *(_DWORD *)(96 * v23 + v25 + 80);
  if ((v26 & 0x10) != 0) {
    v27 = a2->clientNum;
    if (dword_312FA0) {
      *(_DWORD *)((char *)&loc_B4098 + 1208 * v27 + v49) = 1;
    } else {
      v28 = 1208 * v27;
      *(_DWORD *)((char *)&loc_B4098 + v28 + v49) = 0;
      *(_DWORD *)(bgs + 1208 * v27 + 737436) = 0;
      *(_DWORD *)((char *)&loc_B4098 + v28 + bgs) |= 2u;
    }
    goto LABEL_41;
  }
  if ((v26 & 0x20) == 0) {
    v43 = a2->clientNum;
    if (dword_312FA0) {
      *(_DWORD *)((char *)&loc_B4098 + 1208 * v43 + v49) = 0;
    } else {
      v46 = 1208 * v43;
      *(_DWORD *)((char *)&loc_B4098 + v46 + v49) = 0;
      *(_DWORD *)(bgs + 1208 * v43 + 737436) = 0;
      *(_DWORD *)((char *)&loc_B4098 + v46 + bgs) |= 1u;
    }
  LABEL_41:
    pXAnimTree = (const XAnimTree_s *)a3->pXAnimTree;
    v30 = p_legs[4];
    if (!v30)
      goto LABEL_42;
    goto LABEL_60;
  }
  v35 = a2->clientNum;
  if (!dword_312FA0) {
    v44 = 1208 * v35;
    *(_DWORD *)((char *)&loc_B4098 + v44 + v49) = 0;
    *(_DWORD *)(bgs + 1208 * v35 + 737436) = 0;
    *(_DWORD *)((char *)&loc_B4098 + v44 + bgs) |= 4u;
    goto LABEL_41;
  }
  *(_DWORD *)((char *)&loc_B4098 + 1208 * v35 + v49) = 2;
  pXAnimTree = (const XAnimTree_s *)a3->pXAnimTree;
  v30 = p_legs[4];
  if (!v30)
    goto LABEL_42;
LABEL_60:
  BYTE1(v30) &= ~2u;
  Weight = XAnimGetWeight(pXAnimTree, v30);
  if (Weight != 0.0) {
  LABEL_42:
    v31 = *(_DWORD *)&a3->torso[16];
    if (!v31)
      goto LABEL_43;
    goto LABEL_62;
  }
  p_legs[4] = 0;
  p_legs[5] = 0;
  p_legs[6] = 150;
  v31 = *(_DWORD *)&a3->torso[16];
  if (!v31)
    goto LABEL_43;
LABEL_62:
  BYTE1(v31) &= ~2u;
  v52 = XAnimGetWeight(pXAnimTree, v31);
  if (v52 == 0.0) {
    *(_DWORD *)&a3->torso[16] = 0;
    *(_DWORD *)&a3->torso[20] = 0;
    *(_DWORD *)&a3->torso[24] = 150;
  }
LABEL_43:
  if (a3->leftHandGun && (*(_DWORD *)&a3->torso[16] & 0xFFFFFDFF) == 0) {
    a3->leftHandGun = 0;
    a3->dobjDirty = 1;
  }
  BG_RunLerpFrameRate((int *)a3->infoValid, p_legs, a2->legsAnim,
                      (clientInfo_t *)a2);
  return BG_RunLerpFrameRate((int *)a3->infoValid, (int *)a3->torso,
                             a2->torsoAnim, (clientInfo_t *)a2);
}

void __cdecl BG_LoadAnim() {
  uint32_t Buf;            // ebx
  int v8;                  // esi
  int AnimTree;            // ebx
  char *v10;               // ebx
  char *v11;               // edi
  int v12;                 // ebx
  int v13;                 // eax
  unsigned __int16 *v14;   // edx
  int v15;                 // ecx
  int v16;                 // eax
  char *v17;               // esi
  char *v18;               // eax
  int v19;                 // edx
  char *v20;               // edi
  int v21;                 // ebx
  int v22;                 // ecx
  _WORD *v23;              // edx
  char *AnimName;          // eax
  char v25;                // al
  int v26;                 // esi
  int v27;                 // ebx
  signed int AnimTreeSize; // [esp+28h] [ebp-50h]
  XAnim_s *v29;            // [esp+2Ch] [ebp-4Ch]
  float v30;               // [esp+30h] [ebp-48h]
  unsigned int i;          // [esp+34h] [ebp-44h]
  int v32;                 // [esp+3Ch] [ebp-3Ch]
  float v33[3];            // [esp+44h] [ebp-34h] BYREF
  float v34[2];            // [esp+50h] [ebp-28h] BYREF
  LargeLocal v35;          // [esp+58h] [ebp-20h] BYREF
  _DWORD v36[7];           // [esp+5Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v35, 36864);
  Buf = LargeLocal::GetBuf(&v35);
  v36[0] = 0;
  Scr_FindAnim(Length, a2, a3, a4, a5, a6, a7, "multiplayer", "root",
               (scr_anim_s *)(bgs + 736204), *(_DWORD *)(bgs + 736232));
  Scr_FindAnim(Length, a2, a3, a4, a5, a6, a7, "multiplayer", "torso",
               (scr_anim_s *)(bgs + 736208), *(_DWORD *)(bgs + 736232));
  Scr_FindAnim(Length, a2, a3, a4, a5, a6, a7, "multiplayer", "legs",
               (scr_anim_s *)(bgs + 736212), *(_DWORD *)(bgs + 736232));
  Scr_FindAnim(Length, a2, a3, a4, a5, a6, a7, "multiplayer", "turning",
               (scr_anim_s *)(bgs + 736216), *(_DWORD *)(bgs + 736232));
  BG_AnimParseAnimScript((char *)bgs, Buf, (int)v36, Length, a2, a3, a4, a5, a6,
                         a7);
  Scr_PrecacheAnimTrees(Length, a2, a3, a4, a5, a6, a7,
                        *(void *(**)(int))((char *)&loc_B3BF8 + bgs),
                        *(_DWORD *)(bgs + 736232));
  v8 = bgs;
  AnimTree = Scr_FindAnimTree(Length, a2, a3, a4, a5, a6, a7, "multiplayer");
  if (!AnimTree)
    Com_Error(Length, a2, a3, a4, a5, a6, a7, 1,
              "\x15Could not find animation tree '%s'", "multiplayer");
  *(_DWORD *)(v8 + 736200) = AnimTree;
  *(_DWORD *)((char *)&loc_B3BB4 + bgs) = *(_DWORD *)(bgs + 736200);
  *(_WORD *)(bgs + 736184) = *(_WORD *)((char *)&loc_B3BD0 + bgs);
  *(_WORD *)(bgs + 736186) = *(_WORD *)(bgs + 736212);
  *(_WORD *)(bgs + 736188) = *(_WORD *)(bgs + 736216);
  Scr_EndLoadAnimTrees(a2);
  v10 = globalScriptData;
  v29 = *(XAnim_s **)((char *)&loc_B3BB4 + (_DWORD)globalScriptData);
  AnimTreeSize = XAnimGetAnimTreeSize(v29);
  *((_DWORD *)globalScriptData + 12288) = AnimTreeSize;
  *((_DWORD *)v10 + 20) |= 0x101u;
  I_strncpyz(v10, "root", 64);
  *((_DWORD *)v10 + 19) = 0;
  v11 = v10 + 96;
  if (AnimTreeSize > 1) {
    for (i = 1; AnimTreeSize != i; ++i) {
      if (i >= *((_DWORD *)globalScriptData + 12288))
        Com_Error(Length, a2, a3, a4, a5, a6, a7, 1,
                  "\x15Player animation index %i out of 0 to %i range", i,
                  *((_DWORD *)globalScriptData + 12288));
      v12 = g_pLoadAnims;
      if (*(int *)g_piNumLoadAnims > 0) {
        if (i == *(unsigned __int16 *)g_pLoadAnims) {
        LABEL_13:
          if (XAnimIsPrimitive(v29, i)) {
            AnimName = (char *)XAnimGetAnimName(v29, i);
            I_strncpyz(v11, AnimName, 64);
            v25 = *v11;
            if (!*v11)
              goto LABEL_35;
            v26 = 0;
            v27 = 119;
            do {
              v26 += v27 * (char)__tolower(v25);
              v25 = v11[v27++ - 118];
            } while (v25);
            if (v26 == -1)
            LABEL_35:
              v26 = 0;
            *((_DWORD *)v11 + 19) = v26;
            if (!*((_DWORD *)v11 + 16))
              *((_DWORD *)v11 + 16) = -1;
            Length = XAnimGetLength(v29, i);
            v30 = Length;
            a2 = v30;
            a3 = 0;
            if (v30 == 0.0) {
              *((_DWORD *)v11 + 18) = 500;
              *((_DWORD *)v11 + 17) = 0;
            } else {
              *((_DWORD *)v11 + 18) = (int)(float)(v30 * 1000.0);
              XAnimGetRelDelta(v29, i, v34, v33, 0.0, 1.0);
              a3 = (__m128)LODWORD(v33[1]);
              a4 = (__m128)LODWORD(v33[2]);
              a3.f32[0] = a3.f32[0] * a3.f32[0];
              a4.f32[0] = a4.f32[0] * a4.f32[0];
              a2 = fsqrt((float)((float)(v33[0] * v33[0]) + a3.f32[0]) +
                         a4.f32[0]) /
                   v30;
              *((float *)v11 + 17) = a2;
              if (*((int *)v11 + 18) <= 499)
                *((_DWORD *)v11 + 18) = 500;
            }
            if ((unsigned __int8)XAnimIsLooped(v29, i))
              *((_DWORD *)v11 + 20) |= 0x80u;
          } else {
            *((_DWORD *)v11 + 20) |= 1u;
            I_strncpyz(v11, (char *)(v12 + 8), 64);
            *((_DWORD *)v11 + 19) = *(_DWORD *)(v12 + 4);
            if (!*((_DWORD *)v11 + 16))
              *((_DWORD *)v11 + 16) = -1;
            *((_DWORD *)v11 + 18) = 0;
            *((_DWORD *)v11 + 17) = 0;
          }
          goto LABEL_17;
        }
        v13 = g_pLoadAnims + 72;
        v14 = (unsigned __int16 *)(g_pLoadAnims + 72);
        v15 = 1;
        while (1) {
          v12 = v13;
          if (v15 == *(_DWORD *)g_piNumLoadAnims)
            break;
          v16 = *v14;
          ++v15;
          v14 += 36;
          if (i == v16)
            goto LABEL_13;
          v13 = v12 + 72;
        }
      }
      *((_DWORD *)v11 + 20) |= 0x100u;
      I_strncpyz(v11, "unused", 64);
      *((_DWORD *)v11 + 19) = 0;
    LABEL_17:
      v11 += 96;
    }
  }
  BG_AnimParseAnimScript(globalScriptData, 0, 0, Length, a2, a3, a4, a5, a6,
                         a7);
  v17 = globalScriptData;
  if (*((int *)globalScriptData + 12288) > 0) {
    v18 = globalScriptData;
    v19 = 0;
    do {
      *((_DWORD *)v18 + 23) = 0;
      ++v19;
      v18 += 96;
    } while (v19 < *((_DWORD *)v17 + 12288));
  }
  if (!*(_DWORD *)(bgs + 736232) && *((int *)v17 + 57955) > 0) {
    v20 = v17 + 231820;
    v32 = 0;
    do {
      v21 = *((_DWORD *)v20 + 1);
      if (*(int *)(v21 + 112) > 0) {
        v22 = 0;
        v23 = (_WORD *)(v21 + 112);
        do {
          if (v23[2])
            *(_DWORD *)&v17[96 * (__int16)v23[4] + 92] = 1;
          if (v23[3])
            *(_DWORD *)&v17[96 * (__int16)v23[5] + 92] = 1;
          ++v22;
          v23 += 8;
        } while (v22 < *(_DWORD *)(v21 + 112));
      }
      ++v32;
      v20 += 4;
    } while (v32 < *((_DWORD *)v17 + 57955));
  }
  LargeLocal::~LargeLocal(&v35);
}

struct bgs_t *bgs;
void __cdecl BG_LerpAngles(float *const, float, float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_PlayerAnimation_VerifyAnim(struct XAnimTree_s *,
                                           struct lerpFrame_t *) {
  UNIMPLEMENTED();
}

int __cdecl BG_EvaluateConditions(struct clientInfo_t *,
                                  struct animScriptItem_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_SetupAnimNoteTypes(struct animScriptData_t *) {
  UNIMPLEMENTED();
}

long __cdecl BG_StringHashValue(char const *) { UNIMPLEMENTED(); }

int __cdecl BG_GetConditionValue(struct clientInfo_t *, int, int) {
  UNIMPLEMENTED();
}

struct animScriptItem_t *__cdecl BG_FirstValidItem(int, struct animScript_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_AnimPlayerConditions(struct entityState_s *,
                                     struct clientInfo_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_Player_DoControllersInternal(struct DObj_s const *,
                                             struct entityState_s const *,
                                             int *const, struct clientInfo_t *,
                                             struct controller_info_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_SwingAngles(float, float, float, float, float *, int *) {
  float v8;  // xmm1_4
  float v9;  // xmm0_4
  float v10; // [esp+1Ch] [ebp-3Ch]
  float v12; // [esp+48h] [ebp-10h]
  float v13; // [esp+4Ch] [ebp-Ch]

  if (*a2)
    goto LABEL_5;
  v13 = AngleSubtract(*a1, a3);
  if (v13 > a4 || (float)-a4 > v13)
    *a2 = 1;
  if (*a2) {
  LABEL_5:
    v10 = AngleSubtract(a3, *a1);
    v8 = fmaxf(0.5, fabs(v10) * 0.050000001);
    if (v10 < 0.0) {
      v9 = (float)((float)*(int *)(bgs + 736228) * v8) *
           COERCE_FLOAT(LODWORD(a6) ^ 0x80000000);
      if (v10 >= v9)
        goto LABEL_7;
    } else {
      v9 = (float)((float)*(int *)(bgs + 736228) * v8) * a6;
      if (v9 >= v10) {
      LABEL_7:
        *a2 = 0;
        v9 = v10;
        goto LABEL_8;
      }
    }
    *a2 = 1;
  LABEL_8:
    *a1 = AngleMod(v9 + *a1);
    v12 = AngleSubtract(a3, *a1);
    if (v12 > a5) {
      *a1 = AngleMod(a3 - a5);
    } else if ((float)-a5 > v12) {
      *a1 = AngleMod(a3 + a5);
    }
  }
}

void __cdecl BG_PlayerAngles(struct entityState_s *, struct clientInfo_t *) {
  UNIMPLEMENTED();
}

struct loadAnim_t *__cdecl BG_LoadAnimForAnimIndex(int) {
  UNIMPLEMENTED();
}

struct scr_animtree_t __cdecl BG_FindAnimTree(char const *, int) {
  UNIMPLEMENTED();
}

void __cdecl BG_ParseConditionBits(char const **, struct animStringItem_t *,
                                   int, int *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_FindAnimTrees(void) { UNIMPLEMENTED(); }

void __cdecl BG_FindAnims(void) { UNIMPLEMENTED(); }

void __cdecl BG_SetNewAnimation(struct clientInfo_t *, struct lerpFrame_t *,
                                int, int) {
  UNIMPLEMENTED();
}

int __cdecl BG_ParseConditions(char const **, struct animScriptItem_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_RunLerpFrameRate(struct clientInfo_t *, struct lerpFrame_t *,
                                 int, struct entityState_s *) {
  UNIMPLEMENTED();
}

void __cdecl BG_AnimParseAnimScript(struct animScriptData_t *,
                                    struct loadAnim_t *, int *) {
  UNIMPLEMENTED();
}

void __cdecl BG_FinalizePlayerAnims(void) { UNIMPLEMENTED(); }
