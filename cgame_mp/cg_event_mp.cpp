void __cdecl CG_EntityEvent(struct centity_s *cent, int event) {
  entityState_s *nextState; // esi
  int v4;                   // edx
  unsigned int v5;          // ebx
  int v6;                   // edx
  int number;               // edx
  int v8;                   // edx
  int v9;                   // edx
  int v10;                  // edx
  int v11;                  // edx
  int v12;                  // edx
  void *v13;                // edx
  int v14;                  // edx
  float v15;                // xmm2_4
  int v16;                  // eax
  float v17;                // xmm1_4
  _DWORD *v18;              // ebx
  EffectTemplate *v19;      // eax
  int v20;                  // ecx
  snd_alias_list_t **v21;   // ebx
  EffectTemplate *v22;      // eax
  int v23;                  // edx
  int v24;                  // ebx
  snd_alias_list_t **v25;   // eax
  _DWORD *v26;              // edi
  int v27;                  // edx
  _DWORD *v28;              // eax
  int v29;                  // ebx
  int WeaponDef;            // eax
  int v31;                  // edx
  int v32;                  // ecx
  float v33;                // xmm2_4
  float v34;                // xmm0_4
  int v35;                  // ecx
  char *v36;                // edx
  int v37;                  // edx
  int v38;                  // ecx
  int v39;                  // ecx
  _DWORD *v40;              // ebx
  int v41;                  // edx
  int v42;                  // ecx
  int v43;                  // edx
  char *v44;                // edx
  int v45;                  // edx
  int v46;                  // edx
  int v47;                  // ecx
  int v48;                  // edx
  int v49;                  // edx
  int v50;                  // ecx
  char *v51;                // eax
  EffectTemplate *v52;      // ebx
  _DWORD *v53;              // ebx
  EffectTemplate *v54;      // eax
  _DWORD *v55;              // ebx
  EffectTemplate *v56;      // eax
  EffectTemplate *v57;      // eax
  char *ConfigString;       // eax
  char *v59;                // eax
  _DWORD *v60;              // ebx
  EffectTemplate *v61;      // edx
  unsigned int v62;         // edi
  int v63;                  // eax
  EffectTemplate *v64;      // edi
  char *v65;                // edx
  char *v66;                // ebx
  int v67;                  // eax
  int v68;                  // eax
  char *v69;                // edx
  int v70;                  // eax
  _DWORD *v71;              // eax
  char v72;                 // [esp+8h] [ebp-100h]
  char v73;                 // [esp+3Bh] [ebp-CDh]
  int v74;                  // [esp+3Ch] [ebp-CCh]
  float *lerpOrigin;        // [esp+40h] [ebp-C8h]
  float v76;                // [esp+44h] [ebp-C4h]
  char *__s2;               // [esp+48h] [ebp-C0h]
  _DWORD *v78;              // [esp+4Ch] [ebp-BCh]
  char *v79;                // [esp+50h] [ebp-B8h]
  char v80;                 // [esp+57h] [ebp-B1h]
  unsigned int v81;         // [esp+58h] [ebp-B0h]
  char v82;                 // [esp+5Fh] [ebp-A9h]
  char __dst[34];           // [esp+60h] [ebp-A8h] BYREF
  char __src[34];           // [esp+82h] [ebp-86h] BYREF
  float v85[4];             // [esp+A4h] [ebp-64h] BYREF
  FxBoltInfo v86;           // [esp+B4h] [ebp-54h] BYREF
  int v87;                  // [esp+BCh] [ebp-4Ch]
  int v88;                  // [esp+C0h] [ebp-48h]
  float v89[4];             // [esp+C4h] [ebp-44h] BYREF
  float v90[3];             // [esp+D4h] [ebp-34h] BYREF
  float v91[3];             // [esp+E0h] [ebp-28h] BYREF
  unsigned __int16 v92[13]; // [esp+EEh] [ebp-1Ah] BYREF

  if (!a3) {
    if (*(_BYTE *)(cg_debugEvents + 8))
      Com_Printf("CG_EntityEvent:ZERO EVENT\n");
    return;
  }
  lerpOrigin = a2->lerpOrigin;
  nextState = (entityState_s *)a2->nextState;
  v74 = *(_DWORD *)&a2->nextState[160];
  v4 = *((_DWORD *)cg + 9);
  if ((*(_DWORD *)(v4 + 24) & 0xC00000) != 0 &&
      *(_DWORD *)a2->nextState == *(_DWORD *)(v4 + 216)) {
    v73 = 1;
    v82 = 1;
  } else {
    v73 = 0;
    v82 = 0;
  }
  if (*(_BYTE *)(cg_debugEvents + 8)) {
    Com_Printf("ent:%3i  event:%3i ", nextState->number, a3);
    if (*(_BYTE *)(cg_debugEvents + 8))
      Com_Printf("CG_EntityEvent:%s\n", *((const char **)&eventnames + a3));
  }
  v5 = *(_DWORD *)&a2->nextState[144];
  if (v5 >= 0x40)
    v5 = 0;
  if (*(_DWORD *)&a2->nextState[200])
    BG_GetWeaponDef(*(_DWORD *)&a2->nextState[200]);
  v6 = a3 - 1;
  if ((unsigned int)(a3 - 1) <= 0x16) {
    if (*(_BYTE *)(cg_footsteps + 8)) {
      if (v73)
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v6 + 12229));
      else
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v6 + 12206));
    }
    number = nextState->number;
    if (!v82)
      goto LABEL_16;
    goto LABEL_48;
  }
  v8 = a3 - 24;
  if ((unsigned int)(a3 - 24) <= 0x16) {
    if (*(_BYTE *)(cg_footsteps + 8)) {
      if (v73)
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v8 + 12275));
      else
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v8 + 12252));
    }
    v10 = nextState->number;
    if (!v82)
      goto LABEL_26;
    goto LABEL_31;
  }
  v9 = a3 - 47;
  if ((unsigned int)(a3 - 47) <= 0x16) {
    if (*(_BYTE *)(cg_footsteps + 8)) {
      if (v73)
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v9 + 12321));
      else
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v9 + 12298));
    }
    v10 = nextState->number;
    if (!v82) {
    LABEL_26:
      CG_PlayEntitySoundAlias(v10, *((snd_alias_list_t **)cgs + 12392));
      return;
    }
  LABEL_31:
    CG_PlayEntitySoundAlias(v10, *((snd_alias_list_t **)cgs + 12393));
    return;
  }
  v11 = a3 - 70;
  if ((unsigned int)(a3 - 70) <= 0x16) {
    if (v73)
      CG_PlayEntitySoundAlias(nextState->number,
                              *((snd_alias_list_t **)cgs + v11 + 12229));
    else
      CG_PlayEntitySoundAlias(nextState->number,
                              *((snd_alias_list_t **)cgs + v11 + 12206));
    number = nextState->number;
    if (!v82) {
    LABEL_16:
      CG_PlayEntitySoundAlias(number, *((snd_alias_list_t **)cgs + 12390));
      return;
    }
  LABEL_48:
    CG_PlayEntitySoundAlias(number, *((snd_alias_list_t **)cgs + 12391));
    return;
  }
  v12 = a3 - 93;
  if ((unsigned int)(a3 - 93) > 0x16) {
    v14 = a3 - 116;
    if ((unsigned int)(a3 - 116) > 0x16) {
      switch (a3) {
      case 139:
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + 12394));
        return;
      case 140:
        if (v5 == *((_DWORD *)cg + 38692)) {
          if (!*(_DWORD *)(legacyHacks + 12))
            *(_DWORD *)(legacyHacks + 8) = 0;
        } else {
          Com_DPrintf("Event %s just for client %i was sent to other clients\n",
                      unk_30A690, v5);
        }
        return;
      case 141:
        if (v5 == *((_DWORD *)cg + 38692)) {
          if (!*(_DWORD *)(legacyHacks + 12))
            *(_DWORD *)(legacyHacks + 8) = 1;
        } else {
          Com_DPrintf("Event %s just for client %i was sent to other clients\n",
                      unk_30A694, v5);
        }
        return;
      case 142:
        if (v5 == *((_DWORD *)cg + 38692)) {
          if (!*(_DWORD *)(legacyHacks + 12))
            *(_DWORD *)(legacyHacks + 8) = 2;
        } else {
          Com_DPrintf("Event %s just for client %i was sent to other clients\n",
                      unk_30A698, v5);
        }
        return;
      case 143:
        if (v5 == *((_DWORD *)cg + 38692)) {
          if (!*((_DWORD *)cg + 2) && !*(_BYTE *)(cg_nopredict + 8) &&
              !*(_BYTE *)(cg_synchronousClients + 8)) {
            v32 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) -
                  *((_DWORD *)cg + 41269);
            v33 = 0.0;
            if (v32 <= 99)
              v33 =
                  (float)((float)((float)(100 - v32) * *((float *)cg + 41268)) /
                          100.0) *
                  0.89999998;
            *((float *)cg + 41268) = v33 + (float)(v74 - 128);
            v34 = *((float *)cg + 41268);
            if (v34 <= 24.0) {
              if (v34 < -16.0)
                *((_DWORD *)cg + 41268) = -1048576000;
            } else {
              *((_DWORD *)cg + 41268) = 1103101952;
            }
            *((_DWORD *)cg + 41269) =
                *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
          }
        } else {
          Com_DPrintf("Event %s just for client %i was sent to other clients\n",
                      unk_30A69C, v5);
        }
        return;
      case 144:
      case 145:
        v24 = *(_DWORD *)&a2->nextState[160];
        if (v24 > 0 && v24 < bg_numItems) {
          v25 = (snd_alias_list_t **)((char *)cg_items + 36 * v24);
          if (a3 == 144) {
            CG_PlayEntitySoundAlias(nextState->number, v25[7]);
          } else if (a3 == 145) {
            CG_PlayEntitySoundAlias(nextState->number, v25[8]);
          }
          v26 = cg;
          v27 = *((_DWORD *)cg + 9);
          if ((*(_DWORD *)(v27 + 24) & 0xC00000) != 0 &&
              nextState->number == *(_DWORD *)(v27 + 216)) {
            v28 = &bg_itemlist[11 * v24];
            v29 = v28[8];
            if (v28[7] == 1) {
              WeaponDef = BG_GetWeaponDef(v28[8]);
              if (*(_DWORD *)(WeaponDef + 124) != 9) {
                if (*(_DWORD *)(WeaponDef + 132)) {
                  if (!v26[44956])
                    CG_SetEquippedOffHand(v29);
                } else if (!v26[44948]) {
                  CG_SelectWeaponIndex(v29);
                }
              }
            }
          }
        }
        return;
      case 146:
        if (!BG_WeaponIsClipOnly(*(_DWORD *)&a2->nextState[200]))
          CG_PlayEntitySoundAlias(nextState->number,
                                  *((snd_alias_list_t **)cgs + 12065));
        v31 = *((_DWORD *)cg + 9);
        if ((*(_DWORD *)(v31 + 24) & 0xC00000) != 0 &&
            nextState->number == *(_DWORD *)(v31 + 216))
          CG_OutOfAmmoChange();
        return;
      case 147:
      case 164:
      case 168:
      case 169:
      case 170:
      case 171:
      case 172:
        return;
      case 148:
        v23 = *((_DWORD *)cg + 9);
        if ((*(_DWORD *)(v23 + 24) & 0xC00000) != 0 &&
            nextState->number == *(_DWORD *)(v23 + 216)) {
          CG_MenuShowNotify((windowDef_t *)4);
          CG_SwitchOffHandCmd();
        }
        return;
      case 149:
        v37 = *((_DWORD *)cg + 9);
        if ((*(_DWORD *)(v37 + 24) & 0xC00000) != 0 &&
            nextState->number == *(_DWORD *)(v37 + 216))
          CL_SetADS(0);
        return;
      case 150:
        if (v73) {
          v35 = *(_DWORD *)&a2->nextState[200];
          v36 = (char *)cg_weapons + 436 * v35;
          if (*((_DWORD *)v36 + 63))
            goto LABEL_111;
          if (*((_DWORD *)v36 + 65))
            goto LABEL_117;
        } else {
          v35 = *(_DWORD *)&a2->nextState[200];
        }
        v65 = (char *)cg_weapons + 436 * v35;
        if (*((_DWORD *)v65 + 62))
          goto LABEL_198;
        if (*((_DWORD *)v65 + 64))
          goto LABEL_205;
        return;
      case 151:
        if (v73) {
          v38 = *(_DWORD *)&a2->nextState[200];
          v36 = (char *)cg_weapons + 436 * v38;
          if (*((_DWORD *)v36 + 65)) {
          LABEL_117:
            CG_PlayEntitySoundAlias(nextState->number,
                                    *((snd_alias_list_t **)v36 + 65));
            return;
          }
          if (*((_DWORD *)v36 + 63)) {
          LABEL_111:
            CG_PlayEntitySoundAlias(nextState->number,
                                    *((snd_alias_list_t **)v36 + 63));
            return;
          }
        } else {
          v38 = *(_DWORD *)&a2->nextState[200];
        }
        v65 = (char *)cg_weapons + 436 * v38;
        if (*((_DWORD *)v65 + 64)) {
        LABEL_205:
          CG_PlayEntitySoundAlias(nextState->number,
                                  *((snd_alias_list_t **)v65 + 64));
        } else if (*((_DWORD *)v65 + 62)) {
        LABEL_198:
          CG_PlayEntitySoundAlias(nextState->number,
                                  *((snd_alias_list_t **)v65 + 62));
        }
        return;
      case 152:
        if (v73) {
          v42 = *(_DWORD *)&a2->nextState[200];
          if (*((_DWORD *)cg_weapons + 109 * v42 + 67)) {
            CG_PlayEntitySoundAlias(
                nextState->number,
                *((snd_alias_list_t **)cg_weapons + 109 * v42 + 67));
            return;
          }
        } else {
          v42 = *(_DWORD *)&a2->nextState[200];
        }
        if (*((_DWORD *)cg_weapons + 109 * v42 + 66))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v42 + 66));
        return;
      case 153:
        if (v73) {
          v50 = *(_DWORD *)&a2->nextState[200];
          if (*((_DWORD *)cg_weapons + 109 * v50 + 69)) {
            CG_PlayEntitySoundAlias(
                nextState->number,
                *((snd_alias_list_t **)cg_weapons + 109 * v50 + 69));
            return;
          }
        } else {
          v50 = *(_DWORD *)&a2->nextState[200];
        }
        if (*((_DWORD *)cg_weapons + 109 * v50 + 68))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v50 + 68));
        return;
      case 154:
        v48 = *(_DWORD *)&a2->nextState[200];
        if (*((_DWORD *)cg_weapons + 109 * v48 + 70))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v48 + 70));
        return;
      case 155:
        v49 = *(_DWORD *)&a2->nextState[200];
        if (*((_DWORD *)cg_weapons + 109 * v49 + 72))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v49 + 72));
        return;
      case 156:
        v45 = *(_DWORD *)&a2->nextState[200];
        if (*((_DWORD *)cg_weapons + 109 * v45 + 71))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v45 + 71));
        return;
      case 157:
        v46 = *(_DWORD *)&a2->nextState[200];
        if (*((_DWORD *)cg_weapons + 109 * v46 + 54))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v46 + 54));
        return;
      case 158:
      case 159:
      case 160:
        CG_FireWeapon(a1, a2, a3, 0);
        return;
      case 161:
        if (v73) {
          v47 = *(_DWORD *)&a2->nextState[200];
          if (*((_DWORD *)cg_weapons + 109 * v47 + 61)) {
            CG_PlayEntitySoundAlias(
                nextState->number,
                *((snd_alias_list_t **)cg_weapons + 109 * v47 + 61));
            return;
          }
        } else {
          v47 = *(_DWORD *)&a2->nextState[200];
        }
        if (*((_DWORD *)cg_weapons + 109 * v47 + 60))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v47 + 60));
        return;
      case 162:
        CG_EjectWeaponBrass(a1, nextState, 162);
        return;
      case 163:
        v43 = *(_DWORD *)&a2->nextState[200];
        if (*((_DWORD *)cg_weapons + 109 * v43 + 59))
          CG_PlayEntitySoundAlias(
              nextState->number,
              *((snd_alias_list_t **)cg_weapons + 109 * v43 + 59));
        return;
      case 165:
        CG_PrepOffHand((entityState_s *)a2->nextState, 165,
                       *(_DWORD *)&a2->nextState[160]);
        return;
      case 166:
        CG_UseOffHand(a2, 166, *(_DWORD *)&a2->nextState[160]);
        return;
      case 167:
        if (v73)
          CG_SetEquippedOffHand(*(_DWORD *)&a2->nextState[160]);
        return;
      case 173:
        CG_PlayEntitySoundAlias(*(_DWORD *)&a2->nextState[116],
                                *((snd_alias_list_t **)cgs + 12398));
        return;
      case 174:
        CG_PlaySoundAlias(*(float **)&a2->nextState[116], lerpOrigin,
                          *((snd_alias_list_t **)cgs + 12399));
        return;
      case 175:
        CG_StartShakeCamera(0.050000001, 100, lerpOrigin, 100.0);
        CG_FireWeapon(a1, a2, 175, 0);
        v44 = (char *)cg_entities + 548 * v74;
        if (v44[480] && *((_DWORD *)v44 + 61) == 1 &&
            *(_DWORD *)(*((_DWORD *)cg + 9) + 1440) !=
                *(_DWORD *)a2->nextState) {
          CG_CompassAddWeaponPingInfo((centity_s *)cg_entities + v74,
                                      lerpOrigin, 50);
        }
        return;
      case 176:
        CG_FireWeapon(a1, a2, 176, 0);
        CG_FireWeapon(a1, a2, 176, 1);
        return;
      case 177:
        CG_FireWeapon(a1, a2, 177, 2);
        CG_FireWeapon(a1, a2, 177, 3);
        return;
      case 179:
        ConfigString = CL_GetConfigString(*(_DWORD *)&a2->nextState[160] + 590);
        CG_PlaySoundAliasByName(*(float **)a2->nextState,
                                (float *)&a2->nextState[24], ConfigString);
        return;
      case 180:
        v59 = CL_GetConfigString(*(_DWORD *)&a2->nextState[160] + 590);
        CG_PlaySoundAliasAsMasterByName(*(float **)a2->nextState,
                                        (float *)&a2->nextState[24], v59);
        return;
      case 181:
      case 182:
      case 183:
        ByteToDir(*(_DWORD *)&a2->nextState[160], v91);
        ByteToDir(*(_DWORD *)&a2->nextState[216], v90);
        CG_BulletHitEvent(*(_DWORD *)&a2->nextState[116], lerpOrigin, v91, v90,
                          *(_DWORD *)&a2->nextState[136], a3);
        return;
      case 185:
      case 186:
        CG_BulletHitClientEvent(*(_DWORD *)&a2->nextState[116], lerpOrigin,
                                *(_DWORD *)&a2->nextState[136], a3);
        return;
      case 187:
        ByteToDir(*(_DWORD *)&a2->nextState[160], v91);
        v53 = cgs;
        CG_PlaySoundAlias((float *)0x3FE, lerpOrigin,
                          *((snd_alias_list_t **)cgs +
                            *(_DWORD *)&a2->nextState[136] + 12068));
        v54 = *(EffectTemplate **)(*(_DWORD *)(v53[12416] + 4) +
                                   4 * *(_DWORD *)&a2->nextState[136] + 736);
        if (v54)
          FX_PlayEffect(v54, lerpOrigin, v91);
        return;
      case 188:
        ByteToDir(*(_DWORD *)&a2->nextState[160], v91);
        v55 = cgs;
        CG_PlaySoundAlias((float *)0x3FE, lerpOrigin,
                          *((snd_alias_list_t **)cgs +
                            *(_DWORD *)&a2->nextState[136] + 12091));
        v56 = *(EffectTemplate **)(*(_DWORD *)(v55[12416] + 4) +
                                   4 * *(_DWORD *)&a2->nextState[136] + 828);
        if (v56)
          FX_PlayEffect(v56, lerpOrigin, v91);
        v39 = *(_DWORD *)&a2->nextState[200];
        v40 = cg_weapons;
        v57 = (EffectTemplate *)*((_DWORD *)cg_weapons + 109 * v39 + 89);
        if (v57) {
          FX_PlayEffect(v57, lerpOrigin, v91);
          v39 = *(_DWORD *)&a2->nextState[200];
        }
        if (v40[109 * v39 + 90])
          goto LABEL_171;
        return;
      case 189:
        goto LABEL_63;
      case 190:
        *(_DWORD *)((char *)&loc_2BEE8 + (_DWORD)cg) = 1;
      LABEL_63:
        ByteToDir(*(_DWORD *)&a2->nextState[160], v91);
        v18 = cgs;
        CG_PlaySoundAlias((float *)0x3FE, lerpOrigin,
                          *((snd_alias_list_t **)cgs +
                            *(_DWORD *)&a2->nextState[136] + 12114));
        v19 = *(EffectTemplate **)(*(_DWORD *)(v18[12416] + 4) +
                                   4 * *(_DWORD *)&a2->nextState[136] + 920);
        if (v19)
          FX_PlayEffect(v19, lerpOrigin, v91);
        v20 = *(_DWORD *)&a2->nextState[200];
        v21 = (snd_alias_list_t **)cg_weapons;
        v22 = (EffectTemplate *)*((_DWORD *)cg_weapons + 109 * v20 + 89);
        if (v22) {
          FX_PlayEffect(v22, lerpOrigin, v91);
          v20 = *(_DWORD *)&a2->nextState[200];
        }
        if (v21[109 * v20 + 90])
          CG_PlaySoundAlias((float *)0x3FE, lerpOrigin, v21[109 * v20 + 90]);
        *(_DWORD *)((char *)&loc_2BEE8 + (_DWORD)cg) = 0;
        return;
      case 191:
        ByteToDir(*(_DWORD *)&a2->nextState[160], v91);
        v39 = *(_DWORD *)&a2->nextState[200];
        v40 = cg_weapons;
        if (*((_DWORD *)cg_weapons + 109 * v39 + 89)) {
          FX_WarpTime(*(_DWORD *)&a2->nextState[84]);
          FX_PlayEffect(
              (EffectTemplate *)v40[109 * *(_DWORD *)&a2->nextState[200] + 89],
              lerpOrigin, v91);
          FX_WarpTime(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg));
          v39 = *(_DWORD *)&a2->nextState[200];
        }
        if (v40[109 * v39 + 90] &&
            ((a2->nextState[10] & 1) == 0 ||
             *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) -
                     *(_DWORD *)&a2->nextState[84] <=
                 49)) {
        LABEL_171:
          CG_PlaySoundAlias((float *)0x3FE, lerpOrigin,
                            (snd_alias_list_t *)v40[109 * v39 + 90]);
        }
        return;
      case 194:
        v41 = *(_DWORD *)&a2->nextState[160];
        if ((unsigned int)(v41 - 1) <= 0x3E) {
          v64 = (EffectTemplate *)*((_DWORD *)cgs + v41 + 6640);
          AngleVectors((float *)&a2->nextState[60], (float *)&v86.dobjHandle, 0,
                       v89);
          FX_PlayEffect(a1, v64, lerpOrigin, (const float *)&v86.dobjHandle,
                        v89);
        } else {
          Com_Printf("ERROR: CG_PlayFx called with invalid effect id %i\n",
                     *(_DWORD *)&a2->nextState[160]);
        }
        return;
      case 195:
        v51 = CL_GetConfigString(*(_DWORD *)&a2->nextState[160] + 910);
        v52 = (EffectTemplate *)*((_DWORD *)cgs + 10 * *v51 + v51[1] + 6112);
        v86.dobjHandle = *(_DWORD *)a2->nextState;
        v92[0] = SL_GetString(v51 + 2, 0);
        v86.boneIndex = FX_GetBoneIndex(v86.dobjHandle, v92[0]);
        Scr_SetString(a1, v92, 0);
        if ((v86.boneIndex & 0x80000000) == 0)
          FX_PlayEntityEffect(a1, v52, lerpOrigin, 0, &v86);
        return;
      case 196:
        CG_StartShakeCamera(*(float *)&a2->nextState[104],
                            *(_DWORD *)&a2->nextState[84], lerpOrigin,
                            *(float *)&a2->nextState[108]);
        return;
      case 197:
        v91[0] = 0.0;
        v91[1] = 0.0;
        v91[2] = 1.0;
        v60 = cgs;
        CG_PlaySoundAlias((float *)0x3FE, lerpOrigin,
                          *((snd_alias_list_t **)cgs + 12091));
        v61 = *(EffectTemplate **)(*(_DWORD *)(v60[12416] + 4) + 828);
        if (v61)
          FX_PlayEffect(v61, lerpOrigin, v91);
        return;
      case 198:
        v86.dobjHandle = 1065353216;
        v86.boneIndex = 1065353216;
        v87 = 1065353216;
        v88 = 1065353216;
        v85[0] = 1.0;
        v85[1] = 1.0;
        v85[2] = 1.0;
        v85[3] = 1.0;
        v89[0] = 1.0;
        v89[1] = 1.0;
        v89[2] = 1.0;
        v89[3] = 1.0;
        v81 = *(_DWORD *)&a2->nextState[116];
        v62 = *(_DWORD *)&a2->nextState[120];
        v63 = *(_DWORD *)&a2->nextState[160];
        if ((v63 & 0x80u) == 0) {
          v71 = (_DWORD *)BG_GetWeaponDef(*(_DWORD *)&a2->nextState[160]);
          if (*(_BYTE *)v71[211]) {
            __s2 = (char *)v71[211];
            if (v71[212])
              v76 = 2.8;
            else
              v76 = 1.4;
            v80 = v71[213] != 0;
          } else {
          LABEL_241:
            v76 = 1.4;
            __s2 = "killicondied";
            v80 = 0;
          }
        } else {
          LOBYTE(v63) = v63 & 0x7F;
          switch (v63) {
          case 7:
            v76 = 1.4;
            __s2 = "killiconmelee";
            v80 = 0;
            break;
          case 8:
            v76 = 1.4;
            __s2 = "killiconheadshot";
            v80 = 0;
            break;
          case 9:
            v76 = 1.4;
            __s2 = "killiconcrush";
            v80 = 0;
            break;
          case 11:
            v76 = 1.4;
            __s2 = "killiconfalling";
            v80 = 0;
            break;
          case 12:
            v76 = 1.4;
            __s2 = "killiconsuicide";
            v80 = 0;
            break;
          default:
            goto LABEL_241;
          }
        }
        if (v81 > 0x3F)
          Com_Error(1, "\x15CG_Obituary: target out of range", v72);
        v66 = (char *)cg;
        v78 = (char *)cg + 1208 * v81 + 919828;
        if (!*v78)
          return;
        I_strncpyz(__dst, (char *)cg + 1208 * v81 + 919840, 32);
        I_strncat(__dst, 34, "^7");
        CG_DrawScoreboard_GetTeamColor(v78[12], v85);
        if (!*(_DWORD *)&v66[1208 * *((_DWORD *)v66 + 1) + 919828])
          return;
        if (v62 <= 0x3F) {
          v79 = &v66[1208 * v62 + 919828];
          if (!*(_DWORD *)v79)
            return;
          I_strncpyz(__src, &v66[1208 * v62 + 919840], 32);
          I_strncat(__src, 34, "^7");
          CG_DrawScoreboard_GetTeamColor(*(_DWORD *)&v66[1208 * v62 + 919876],
                                         (float *)&v86.dobjHandle);
          if (v81 == *(_DWORD *)(*((_DWORD *)v66 + 9) + 216))
            I_strncpyz(v66 + 177484, __src, 32);
        } else {
          __src[0] = 0;
          v62 = 1022;
          v79 = 0;
        }
        if (v62 == v81) {
          __src[0] = 0;
          goto LABEL_223;
        }
        v67 = *(_DWORD *)(*((_DWORD *)cg + 9) + 216);
        if (v62 == v67) {
          v70 = *((_DWORD *)v79 + 12);
          if (v70 && v70 == v78[12])
            v69 = va("CGAME_YOUKILLED\x15^1&&2^7 %s\x14%s", __dst,
                     "CGAME_TEAMMATE");
          else
            v69 = va("CGAME_YOUKILLED\x15%s", __dst);
        } else {
          if (v81 != v67 || !v79)
            goto LABEL_223;
          v68 = *((_DWORD *)v79 + 12);
          if (v68 && v68 == v78[12])
            v69 = va("CGAME_YOUWEREKILLED\x15^1&&2^7 %s\x14%s", __src,
                     "CGAME_TEAMMATE");
          else
            v69 = va("CGAME_YOUWEREKILLED\x15%s", __src);
        }
        if (*((_DWORD *)cg + 45893))
          return;
        CG_PriorityCenterPrint(v69, 9.6000004, 1);
      LABEL_223:
        if (!*((_DWORD *)cg + 45893))
          CL_DeathMessagePrint(__src, (float *)&v86.dobjHandle, __dst, v85,
                               __s2, v76, 1.4, v89, v80);
        break;
      default:
        Com_Error(1, "\x15Unknown event: '%s'", *((_DWORD *)&eventnames + a3));
        return;
      }
    } else {
      if (v73)
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v14 + 12367));
      else
        CG_PlayEntitySoundAlias(nextState->number,
                                *((snd_alias_list_t **)cgs + v14 + 12344));
      CG_PlayEntitySoundAlias(nextState->number,
                              *((snd_alias_list_t **)cgs + 12066));
      if (v5 == *((_DWORD *)cg + 38692)) {
        v15 = (float)((float)((float)v74 * 0.0099999998) *
                      (float)(*(float *)(bg_fallDamageMaxHeight + 8) -
                              *(float *)(bg_fallDamageMinHeight + 8))) +
              *(float *)(bg_fallDamageMinHeight + 8);
        if (v15 > 12.0) {
          v16 =
              (int)(float)((float)((float)((float)(v15 - 12.0) / 26.0) * 4.0) +
                           4.0);
          if (v16 <= 24) {
            if (v16 <= 0)
              return;
            v17 = (float)v16;
          } else {
            v17 = 24.0;
          }
          *(float *)((char *)&loc_284D8 + (_DWORD)cg) = 0.0 - v17;
          *(_DWORD *)((char *)&loc_284DC + (_DWORD)cg) =
              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
        }
      }
    }
  } else {
    if (v73)
      CG_PlayEntitySoundAlias(nextState->number,
                              *((snd_alias_list_t **)cgs + v12 + 12367));
    else
      CG_PlayEntitySoundAlias(nextState->number,
                              *((snd_alias_list_t **)cgs + v12 + 12344));
    v13 = cg;
    if (v5 == *((_DWORD *)cg + 38692)) {
      *(float *)((char *)&loc_284D8 + (_DWORD)cg) = 0.0 - (float)v74;
      *(_DWORD *)((char *)&loc_284DC + (_DWORD)v13) =
          *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v13);
    }
  }
}

void __cdecl CG_CheckEvents(struct centity_s *cent) {
  int32_t v2;                    // edx
  int32_t previousEventSequence; // eax
  int32_t v4;                    // eax
  uint8_t v5;                    // di
  int32_t i;                     // esi
  int v7;                        // eax
  int v8;                        // edx

  if (*(int *)&a2->nextState[4] > 10) {
    if (!a2->previousEventSequence) {
      a2->previousEventSequence = 1;
      CG_CalcEntityLerpPositions(a2);
      CG_EntityEvent(a1, a2, *(_DWORD *)&a2->nextState[4] - 10);
    }
    return;
  }
  v2 = *(_DWORD *)&a2->nextState[164];
  if (!v2) {
    a2->previousEventSequence = 0;
    return;
  }
  previousEventSequence = a2->previousEventSequence;
  if (v2 >= previousEventSequence) {
    if (v2 - previousEventSequence <= 4)
      goto LABEL_7;
  LABEL_11:
    a2->previousEventSequence = v2 - 4;
    if (a2->previousEventSequence >= v2)
      goto LABEL_8;
    goto LABEL_15;
  }
  v4 = previousEventSequence - 256;
  a2->previousEventSequence = v4;
  if (v2 - v4 > 4)
    goto LABEL_11;
LABEL_7:
  if (a2->previousEventSequence >= v2) {
  LABEL_8:
    a2->previousEventSequence = v2;
    return;
  }
LABEL_15:
  CG_CalcEntityLerpPositions(a2);
  v5 = a2->nextState[160];
  for (i = a2->previousEventSequence; i != *(_DWORD *)&a2->nextState[164];
       ++i) {
    v7 = i & 3;
    v8 = *(_DWORD *)&a2->nextState[4 * v7 + 168];
    *(_DWORD *)&a2->nextState[160] = *(_DWORD *)&a2->nextState[4 * v7 + 184];
    CG_EntityEvent(a1, a2, v8);
  }
  *(_DWORD *)&a2->nextState[160] = v5;
  a2->previousEventSequence = *(_DWORD *)&a2->nextState[164];
}

void __cdecl CG_ItemPickup(int) { UNIMPLEMENTED(); }

void __cdecl CG_Obituary(struct entityState_s *) { UNIMPLEMENTED(); }

void __cdecl CG_EquipmentSound(int, bool, bool) { UNIMPLEMENTED(); }

void __cdecl CG_PlayFxOnTag(struct centity_s *, int) { UNIMPLEMENTED(); }

void __cdecl CG_PlayFx(struct centity_s *, float const *const) {
  UNIMPLEMENTED();
}
