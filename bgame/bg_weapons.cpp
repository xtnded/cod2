void __cdecl Com_BitClear(int *const, int) { UNIMPLEMENTED(); }

float __cdecl BG_GetBobCycle(struct playerState_s const *ps) {
  return (
      float)((float)((float)LOBYTE(a1->bobCycle) / 255.0) * 3.141592653589793 +
             (float)((float)LOBYTE(a1->bobCycle) / 255.0) * 3.141592653589793 +
             6.283185307179586);
}

bool __cdecl PM_IsBinocularsADS(struct playerState_s const *ps) {
  return (unsigned int)(a1->weaponstate - 19) <= 1;
}

bool __cdecl BG_IsAnyEmptyPrimaryWeaponSlot(struct playerState_s const *ps) {
  return !BYTE1(a1->weaponslots) || !BYTE2(a1->weaponslots);
}

char const *__cdecl BG_GetAmmoClipName(int) { UNIMPLEMENTED(); }

char const *__cdecl BG_GetAmmoTypeName(int) { UNIMPLEMENTED(); }

char const *__cdecl BG_GetSharedAmmoCapName(int) { UNIMPLEMENTED(); }

int __cdecl BG_GetSharedAmmoCapSize(int) { UNIMPLEMENTED(); }

int __cdecl BG_GetAmmoClipSize(int iClipIndex) {
  return *(_DWORD *)(bg_weapClips[a1] + 472);
}

int __cdecl BG_GetNumAmmoClips(void) { UNIMPLEMENTED(); }

int __cdecl BG_GetAmmoTypeMax(int iAmmoIndex) {
  return *(_DWORD *)(bg_weapAmmoTypes[a1] + 468);
}

int __cdecl BG_GetNumAmmoTypes(void) { UNIMPLEMENTED(); }

int __cdecl BG_GetNumWeapons() { return bg_iNumWeapons; }

struct WeaponDef *__cdecl BG_GetWeaponDef(int iWeapon) {
  return bg_weaponDefs[a1];
}

void __cdecl PM_StartWeaponAnim(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

int __cdecl BG_WeaponIsClipOnly(int weapon) {
  return *(_DWORD *)(bg_weaponDefs[a1] + 832);
}

int __cdecl BG_AmmoForWeapon(int weapon) {
  return *(_DWORD *)(bg_weaponDefs[a1] + 456);
}

int __cdecl BG_ClipForWeapon(int weapon) {
  return *(_DWORD *)(bg_weaponDefs[a1] + 464);
}

void __cdecl BG_GetSpreadForWeapon(struct playerState_s const *ps,
                                   int weaponIndex, float *minSpread,
                                   float *maxSpread) {
  float *v4;                   // edx
  const playerState_s *result; // eax
  float v6;                    // xmm2_4
  float v7;                    // xmm2_4
  float v8;                    // xmm1_4
  float v9;                    // xmm0_4

  v4 = (float *)bg_weaponDefs[a2];
  result = a1;
  v6 = *(float *)&a1->viewHeightCurrent;
  if (v6 <= 40.0) {
    v7 = (float)(v6 - 11.0) / 29.0;
    *a3 = v4[165] + (float)((float)(v4[164] - v4[165]) * v7);
    v8 = v4[168];
    v9 = v4[167];
  } else {
    v7 = (float)(v6 - 40.0) / 20.0;
    *a3 = v4[164] + (float)((float)(v4[163] - v4[164]) * v7);
    v8 = v4[167];
    v9 = v4[166];
  }
  *a4 = v8 + (float)(v7 * (float)(v9 - v8));
  return result;
}

int __cdecl BG_GetTotalAmmoReserve(struct playerState_s const *ps,
                                   int weaponIndex) {
  int v2;          // eax
  int v3;          // edi
  int v4;          // esi
  int v5;          // edx
  int *v6;         // ebx
  _DWORD *v7;      // ecx
  int v8;          // eax
  int v10;         // eax
  int v11;         // [esp+1Ch] [ebp-42Ch]
  int v12;         // [esp+28h] [ebp-420h]
  int v13;         // [esp+2Ch] [ebp-41Ch]
  _DWORD v14[128]; // [esp+30h] [ebp-418h] BYREF
  _DWORD __b[134]; // [esp+230h] [ebp-218h] BYREF

  v2 = bg_weaponDefs[a2];
  v13 = *(_DWORD *)(v2 + 456);
  v3 = *(_DWORD *)(v2 + 464);
  memset(__b, 0, 0x200u);
  memset(v14, 0, sizeof(v14));
  v4 = bg_weaponDefs[a2];
  if (*(int *)(v4 + 484) < 0) {
    if (*(_DWORD *)(v4 + 832))
      return *(_DWORD *)&a1->ammoclip[4 * v3];
    else
      return *(_DWORD *)&a1->ammo[4 * v13];
  } else {
    v12 = bg_iNumWeapons;
    if (bg_iNumWeapons > 0) {
      v11 = 0;
      v5 = 1;
      v6 = bg_weaponDefs;
      while (1) {
        if (((*(int *)&a1->weapons[4 * (v5 >> 5)] >> (v5 & 0x1F)) & 1) == 0)
          goto LABEL_4;
        v7 = (_DWORD *)v6[1];
        if (v7[121] != *(_DWORD *)(v4 + 484))
          goto LABEL_4;
        if (!v7[208])
          break;
        v8 = v7[116];
        if (v14[v8]) {
        LABEL_4:
          ++v5;
          ++v6;
          if (v5 > v12)
            return v11;
        } else {
          v14[v8] = 1;
          v11 += *(_DWORD *)&a1->ammoclip[4 * v7[116]];
          ++v5;
          ++v6;
          if (v5 > v12)
            return v11;
        }
      }
      v10 = v7[114];
      if (!__b[v10]) {
        __b[v10] = 1;
        v11 += *(_DWORD *)&a1->ammo[4 * v7[114]];
      }
      goto LABEL_4;
    }
    return 0;
  }
}

int __cdecl BG_GetMaxPickupableAmmo(struct playerState_s const *ps,
                                    int weaponIndex) {
  _DWORD *v2;      // edi
  int v3;          // eax
  int v4;          // ebx
  int *v5;         // esi
  _DWORD *v6;      // edx
  int v7;          // eax
  int v9;          // eax
  int v10;         // [esp+18h] [ebp-420h]
  int v11;         // [esp+1Ch] [ebp-41Ch]
  _DWORD v12[128]; // [esp+20h] [ebp-418h] BYREF
  _DWORD __b[134]; // [esp+220h] [ebp-218h] BYREF

  memset(__b, 0, 0x200u);
  memset(v12, 0, sizeof(v12));
  v2 = (_DWORD *)bg_weaponDefs[a2];
  v3 = v2[121];
  if (v3 < 0) {
    if (v2[208])
      return *(_DWORD *)(bg_weapClips[v2[116]] + 472) -
             *(_DWORD *)&a1->ammoclip[4 * v2[116]];
    else
      return *(_DWORD *)(bg_weapAmmoTypes[v2[114]] + 468) -
             *(_DWORD *)&a1->ammo[4 * v2[114]];
  } else {
    v11 = *(_DWORD *)(bg_sharedAmmoCaps[v3] + 488);
    v10 = bg_iNumWeapons;
    if (bg_iNumWeapons > 0) {
      v4 = 1;
      v5 = bg_weaponDefs;
      while (1) {
        if (((*(int *)&a1->weapons[4 * (v4 >> 5)] >> (v4 & 0x1F)) & 1) == 0)
          goto LABEL_4;
        v6 = (_DWORD *)v5[1];
        if (v6[121] != v2[121])
          goto LABEL_4;
        if (!v6[208])
          break;
        v7 = v6[116];
        if (v12[v7]) {
        LABEL_4:
          ++v4;
          ++v5;
          if (v10 < v4)
            return v11;
        } else {
          v12[v7] = 1;
          v11 -= *(_DWORD *)&a1->ammoclip[4 * v6[116]];
          ++v4;
          ++v5;
          if (v10 < v4)
            return v11;
        }
      }
      v9 = v6[114];
      if (!__b[v9]) {
        __b[v9] = 1;
        v11 -= *(_DWORD *)&a1->ammo[4 * v6[114]];
      }
      goto LABEL_4;
    }
    return v11;
  }
}

int __cdecl BG_IsPlayerWeaponAnAlt(int iWeaponIndex, int iAltIndex) {
  int v2; // eax

  v2 = *(_DWORD *)(bg_weaponDefs[a1] + 876);
  if (v2) {
    if (v2 == a2)
      return 1;
    while (a1 != v2) {
      v2 = *(_DWORD *)(bg_weaponDefs[v2] + 876);
      if (!v2)
        break;
      if (a2 == v2)
        return 1;
    }
  }
  return 0;
}

int __cdecl BG_GetStackSlotForWeapon(struct playerState_s const *pPS,
                                     int iWeaponIndex,
                                     enum weapSlot_t preferedSlot) {
  int v3;           // eax
  char v4;          // al
  char v5;          // al
  weapSlot_t v6;    // edx
  signed __int8 v8; // al

  v3 = bg_weaponDefs[a2];
  if (!*(_DWORD *)(v3 + 136) || (unsigned int)(*(_DWORD *)(v3 + 128) - 1) > 1)
    return 0;
  if ((unsigned int)(a3 - 1) > 1)
    goto LABEL_4;
  v6 = a3;
  v8 = a1->weapons[a3 + 16];
  if (!v8)
    return v6;
  if (!*(_DWORD *)(bg_weaponDefs[v8] + 136)) {
  LABEL_4:
    v4 = BYTE1(a1->weaponslots);
    if (!v4 || *(_DWORD *)(bg_weaponDefs[v4] + 136))
      return 1;
    v5 = BYTE2(a1->weaponslots);
    if (!v5 || *(_DWORD *)(bg_weaponDefs[v5] + 136))
      return 2;
    return 0;
  }
  return a3;
}

int __cdecl BG_GetEmptySlotForWeapon(struct playerState_s const *pPS,
                                     int iWeaponIndex) {
  if ((unsigned int)(*(_DWORD *)(bg_weaponDefs[a2] + 128) - 1) > 1)
    return 0;
  if (BYTE1(a1->weaponslots)) {
    if (!BYTE2(a1->weaponslots))
      return 2;
    return 0;
  }
  return 1;
}

int __cdecl BG_IsPlayerWeaponInSlot(struct playerState_s const *pPS,
                                    int iWeaponIndex, int bAnyMode) {
  int v4; // ecx
  int v5; // esi

  if (((*(int *)&a1->weapons[4 * (a2 >> 5)] >> (a2 & 0x1F)) & 1) == 0)
    return 0;
  if (a3) {
    v4 = a2;
    while (1) {
      v5 = bg_weaponDefs[v4];
      if ((unsigned int)(*(_DWORD *)(v5 + 128) - 1) > 1)
        break;
      if (v4 == SBYTE1(a1->weaponslots))
        return 1;
      if (v4 == SBYTE2(a1->weaponslots))
        return 2;
      if (*(_DWORD *)(v5 + 876))
        v4 = *(_DWORD *)(v5 + 876);
      if (v4 == a2)
        return 0;
    }
    return 0;
  }
  if ((unsigned int)(*(_DWORD *)(bg_weaponDefs[a2] + 128) - 1) > 1)
    return 0;
  if (a2 == SBYTE1(a1->weaponslots))
    return 1;
  if (a2 != SBYTE2(a1->weaponslots))
    return 0;
  return 2;
}

int __cdecl BG_SetPlayerWeaponForSlot(struct playerState_s *, int, int) {
  UNIMPLEMENTED();
}

int __cdecl BG_TakePlayerWeapon(struct playerState_s *pPS, int iWeaponIndex) {
  uint8_t *weapons; // esi
  int v3;           // ebx
  int v4;           // edx
  int v5;           // ecx
  int v6;           // edx
  char v8;          // bl
  int v9;           // edx
  int v10;          // eax
  int v11;          // [esp+0h] [ebp-2Ch]
  int v12;          // [esp+0h] [ebp-2Ch]
  int v13;          // [esp+Ch] [ebp-20h]
  int v14;          // [esp+18h] [ebp-14h]
  int v15;          // [esp+1Ch] [ebp-10h]

  weapons = a1->weapons;
  v3 = 4 * (a2 >> 5);
  if (((*(int *)&a1->weapons[v3] >> (a2 & 0x1F)) & 1) == 0)
    return 0;
  v13 = bg_weaponDefs[a2];
  v4 = a2;
  do {
    v5 = bg_weaponDefs[v4];
    if ((unsigned int)(*(_DWORD *)(v5 + 128) - 1) > 1)
      break;
    if (v4 == SBYTE1(a1->weaponslots)) {
      v15 = 1;
      goto LABEL_19;
    }
    if (v4 == SBYTE2(a1->weaponslots)) {
      v15 = 2;
    LABEL_19:
      if (*(_DWORD *)(v13 + 136)) {
        if (bg_iNumWeapons <= 0)
          goto LABEL_32;
        v9 = 1;
        while (((*(int *)&weapons[4 * (v9 >> 5)] >> (v9 & 0x1F)) & 1) == 0) {
        LABEL_35:
          if (bg_iNumWeapons < ++v9)
            goto LABEL_32;
        }
        if (((*(int *)&a1->weapons[4 * (v9 >> 5)] >> (v9 & 0x1F)) & 1) != 0) {
          v12 = v9;
          v10 = v9;
          do {
            v14 = bg_weaponDefs[v10];
            if ((unsigned int)(*(_DWORD *)(v14 + 128) - 1) > 1)
              break;
            if (v12 == SBYTE1(a1->weaponslots) ||
                v12 == SBYTE2(a1->weaponslots))
              goto LABEL_35;
            v10 = *(_DWORD *)(v14 + 876);
            if (!v10)
              v10 = v12;
            v12 = v10;
          } while (v10 != v9);
        }
        a1->weapons[v15 + 16] = v9;
        if (v9 > bg_iNumWeapons)
        LABEL_32:
          a1->weapons[v15 + 16] = 0;
      } else {
        a1->weapons[v15 + 16] = 0;
      }
      break;
    }
    if (*(_DWORD *)(v5 + 876))
      v4 = *(_DWORD *)(v5 + 876);
  } while (v4 != a2);
  *(_DWORD *)&weapons[v3] &= __ROL4__(-2, a2 & 0x1F);
  v6 = *(_DWORD *)(v13 + 876);
  if (v6) {
    v11 = 4 * (v6 >> 5);
    v8 = v6 & 0x1F;
    if (((*(int *)&weapons[v11] >> (v6 & 0x1F)) & 1) != 0) {
      while (1) {
        *(_DWORD *)&weapons[v11] &= __ROL4__(-2, v8);
        v6 = *(_DWORD *)(bg_weaponDefs[v6] + 876);
        if (!v6)
          break;
        v11 = 4 * (v6 >> 5);
        v8 = v6 & 0x1F;
        if (((*(int *)&weapons[v11] >> (v6 & 0x1F)) & 1) == 0) {
          if (a2 != a1->weapon)
            return 1;
          goto LABEL_16;
        }
      }
    }
  }
  if (a2 != a1->weapon)
    return 1;
LABEL_16:
  a1->weapon = 0;
  return 1;
}

bool __cdecl BG_DoesWeaponNeedSlot(int weapIndex) {
  int v1; // eax

  v1 = bg_weaponDefs[a1];
  return *(_DWORD *)(v1 + 124) != 9 && !*(_DWORD *)(v1 + 132);
}

bool __cdecl BG_DoesWeaponRequireSlot(int weaponIndex) {
  return (unsigned int)(*(_DWORD *)(bg_weaponDefs[a1] + 128) - 1) <= 1;
}

bool __cdecl BG_ValidateWeaponNumber(int) { UNIMPLEMENTED(); }

int __cdecl BG_IsAimDownSightWeapon(int iWeapon) {
  return *(_DWORD *)(bg_weaponDefs[a1] + 812);
}

int __cdecl BG_GetFirstEquippedOffhand(struct playerState_s const *ps,
                                       int offhandClass) {
  int v2; // edx
  int *i; // ebx

  if (bg_iNumWeapons <= 0)
    return 0;
  v2 = 1;
  for (i = bg_weaponDefs;
       *(_DWORD *)(i[1] + 132) != a2 ||
       ((*(int *)&a1->weapons[4 * (v2 >> 5)] >> (v2 & 0x1F)) & 1) == 0;
       ++i) {
    if (bg_iNumWeapons < ++v2)
      return 0;
  }
  return v2;
}

int __cdecl BG_GetViewmodelWeaponIndex(struct playerState_s const *ps) {
  uint32_t pm_flags; // edx
  int v2;            // ecx
  int *v3;           // edx
  int v4;            // eax

  pm_flags = a1->pm_flags;
  if ((pm_flags & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0)
      return 0;
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v2 = 1;
      v3 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v2) {
        v4 = v3[2];
        ++v3;
        if (*(_DWORD *)(v4 + 120) == 3)
          return (unsigned __int8)v2;
      }
      return 0;
    }
    return 1;
  } else if ((pm_flags & 0x10) != 0) {
    return a1->offHandIndex;
  } else {
    return a1->weapon;
  }
}

void __cdecl BG_ShutdownWeaponDefFiles() { bg_iNumWeapons = 0; }

float __cdecl BG_GetHorizontalBobFactor(struct playerState_s const *ps,
                                        float cycle, float speed,
                                        float maxAmp) {
  int32_t viewHeightTarget; // eax
  float v5;                 // xmm0_4
  float v7;                 // [esp+3Ch] [ebp-Ch]

  viewHeightTarget = a1->viewHeightTarget;
  if (viewHeightTarget == 11) {
    v5 = a3 * *(float *)(bg_bobAmplitudeProne + 8);
  } else if (viewHeightTarget == 40) {
    v5 = a3 * *(float *)(bg_bobAmplitudeDucked + 8);
  } else {
    v5 = a3 * *(float *)(bg_bobAmplitudeStanding + 8);
  }
  v7 = sinf(a2);
  return (float)(fminf(a4, v5) * v7);
}

float __cdecl BG_GetVerticalBobFactor(struct playerState_s const *ps,
                                      float cycle, float speed, float maxAmp) {
  int32_t viewHeightTarget; // eax
  float v5;                 // xmm2_4
  float v6;                 // xmm0_4
  long double v8;           // [esp+0h] [ebp-68h]
  float v9;                 // [esp+1Ch] [ebp-4Ch]

  viewHeightTarget = a1->viewHeightTarget;
  if (viewHeightTarget == 11) {
    v5 = a3 * *(float *)(bg_bobAmplitudeProne + 8);
  } else if (viewHeightTarget == 40) {
    v5 = a3 * *(float *)(bg_bobAmplitudeDucked + 8);
  } else {
    v5 = a3 * *(float *)(bg_bobAmplitudeStanding + 8);
  }
  v9 = sinf(a2 + a2);
  *(double *)&v8 = (float)(a2 * 4.0) + 1.570796326794897;
  v6 = sin(v8);
  return (float)(fminf(a4, v5) *
                 (float)((float)(v9 + (float)(v6 * 0.2)) * 0.75));
}

void __cdecl BG_WeaponFireRecoil(struct playerState_s const *ps,
                                 float *const vGunSpeed,
                                 float *const kickAVel) {
  uint32_t pm_flags;     // eax
  uint32_t offHandIndex; // eax
  float *v5;             // ebx
  float fWeaponPosFrac;  // xmm0_4
  float v7;              // xmm0_4
  float v8;              // xmm1_4
  float v9;              // xmm0_4
  float v10;             // xmm0_4
  float *result;         // eax
  float v12;             // xmm1_4
  float v13;             // xmm0_4
  int v14;               // ecx
  int *v15;              // edx
  int v16;               // eax
  float v17;             // [esp+Ch] [ebp-7Ch]
  float v18;             // [esp+Ch] [ebp-7Ch]
  float v19;             // [esp+Ch] [ebp-7Ch]
  float v20;             // [esp+Ch] [ebp-7Ch]
  float v21;             // [esp+10h] [ebp-78h]
  float v22;             // [esp+10h] [ebp-78h]
  float v23;             // [esp+10h] [ebp-78h]
  float v24;             // [esp+10h] [ebp-78h]
  float v25;             // [esp+10h] [ebp-78h]
  float v26;             // [esp+28h] [ebp-60h]
  float v27;             // [esp+2Ch] [ebp-5Ch]
  float v28;             // [esp+30h] [ebp-58h]
  float v29;             // [esp+34h] [ebp-54h]
  float v30;             // [esp+38h] [ebp-50h]
  float v31;             // [esp+3Ch] [ebp-4Ch]
  float v32;             // [esp+40h] [ebp-48h]
  float v33;             // [esp+44h] [ebp-44h]
  float v34;             // [esp+48h] [ebp-40h]
  float v35;             // [esp+4Ch] [ebp-3Ch]
  float v36;             // [esp+50h] [ebp-38h]
  float v37;             // [esp+54h] [ebp-34h]
  float v38;             // [esp+58h] [ebp-30h]
  float v39;             // [esp+5Ch] [ebp-2Ch]
  float v40;             // [esp+60h] [ebp-28h]
  float v41;             // [esp+64h] [ebp-24h]
  float v42;             // [esp+68h] [ebp-20h]
  float v43;             // [esp+6Ch] [ebp-1Ch]

  pm_flags = a1->pm_flags;
  if ((pm_flags & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0) {
    LABEL_3:
      offHandIndex = 0;
      goto LABEL_4;
    }
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v14 = 1;
      v15 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v14) {
        v16 = v15[2];
        ++v15;
        if (*(_DWORD *)(v16 + 120) == 3) {
          offHandIndex = (unsigned __int8)v14;
          goto LABEL_4;
        }
      }
      goto LABEL_3;
    }
    offHandIndex = 1;
  } else {
    if ((pm_flags & 0x10) == 0) {
      v5 = (float *)bg_weaponDefs[a1->weapon];
      fWeaponPosFrac = a1->fWeaponPosFrac;
      v42 = fWeaponPosFrac;
      if ((int)a1->weaponRestrictKickTime > 0)
        goto LABEL_5;
      goto LABEL_13;
    }
    offHandIndex = a1->offHandIndex;
  }
LABEL_4:
  v5 = (float *)bg_weaponDefs[offHandIndex];
  fWeaponPosFrac = a1->fWeaponPosFrac;
  v42 = fWeaponPosFrac;
  if ((int)a1->weaponRestrictKickTime > 0) {
  LABEL_5:
    if (fWeaponPosFrac == 1.0) {
      v43 = 0.0099999998 * v5[287];
    LABEL_7:
      v26 = v5[296];
      v21 = v5[297] - v26;
      v27 = randomf();
      v28 = v5[298];
      v29 = v5[299] - v28;
      v17 = randomf();
      v7 = (float)(v17 * v29) + v28;
      v8 = (float)(v21 * v27) + v26;
      goto LABEL_8;
    }
    v13 = 0.0099999998 * v5[305];
    goto LABEL_22;
  }
LABEL_13:
  v12 = fWeaponPosFrac;
  v13 = 1.0;
  if (v12 == 1.0) {
    v43 = 1.0;
    goto LABEL_7;
  }
LABEL_22:
  v43 = v13;
  v30 = v5[314];
  v24 = v5[315] - v30;
  v31 = randomf();
  v32 = v5[316];
  v33 = v5[317] - v32;
  v19 = randomf();
  v7 = (float)(v19 * v33) + v32;
  v8 = (float)(v24 * v31) + v30;
LABEL_8:
  v9 = v7 * v43;
  *a3 = -(float)(v8 * v43);
  a3[1] = v9;
  a3[2] = v9 * -0.5;
  if (v42 <= 0.0) {
    v38 = v5[306];
    v25 = v5[307] - v38;
    v39 = randomf();
    v40 = v5[308];
    v41 = v5[309] - v40;
    v23 = (float)(v25 * v39) + v38;
    v20 = randomf();
    v10 = (float)(v20 * v41) + v40;
  } else {
    v34 = v5[288];
    v22 = v5[289] - v34;
    v35 = randomf();
    v36 = v5[290];
    v37 = v5[291] - v36;
    v23 = (float)(v22 * v35) + v34;
    v18 = randomf();
    v10 = (float)(v18 * v37) + v36;
  }
  result = a2;
  *a2 = (float)(v23 * v43) + *a2;
  a2[1] = (float)(v10 * v43) + a2[1];
  return result;
}

int __cdecl PM_WeaponAmmoAvailable(struct playerState_s *ps) {
  return *(_DWORD *)&a1
              ->ammoclip[4 * *(_DWORD *)(bg_weaponDefs[a1->weapon] + 464)];
}

int __cdecl BG_WeaponAmmo(struct playerState_s const *ps, int weapon) {
  return *(_DWORD *)&a1->ammoclip[4 * *(_DWORD *)(bg_weaponDefs[a2] + 464)] +
         *(_DWORD *)&a1->ammo[4 * *(_DWORD *)(bg_weaponDefs[a2] + 456)];
}

void __cdecl PM_ExitAimDownSight(struct playerState_s *ps) {
  int result; // eax

  result = PM_AddEvent(a1, 149);
  a1->pm_flags &= ~0x40u;
  return result;
}

bool __cdecl BG_IsWeaponValid(struct playerState_s const *ps, int weaponIndex) {
  bool v2; // bl
  bool v3; // cl
  int v4;  // eax

  v2 = a2 >= 0 && a2 <= bg_iNumWeapons;
  v3 = 0;
  if (((*(int *)&a1->weapons[4 * (a2 >> 5)] >> (a2 & 0x1F)) & 1) != 0)
    v3 = v2;
  v4 = bg_weaponDefs[a2];
  return (*(_DWORD *)(v4 + 132) || a2 == SBYTE1(a1->weaponslots) ||
          a2 == SBYTE2(a1->weaponslots) || a2 == *(_DWORD *)(v4 + 876)) &&
         v3;
}

int __cdecl BG_GetFirstAvailableOffhand(struct playerState_s const *ps,
                                        int offhandClass) {
  int v2;     // ebx
  int *i;     // esi
  _DWORD *v4; // edx

  if (bg_iNumWeapons <= 0)
    return 0;
  v2 = 1;
  for (i = bg_weaponDefs;; ++i) {
    v4 = (_DWORD *)i[1];
    if (v4[33] == a2 &&
        ((*(int *)&a1->weapons[4 * (v2 >> 5)] >> (v2 & 0x1F)) & 1) != 0 &&
        *(_DWORD *)&a1->ammoclip[4 * v4[116]] +
            *(_DWORD *)&a1->ammo[4 * v4[114]]) {
      break;
    }
    if (bg_iNumWeapons < ++v2)
      return 0;
  }
  return v2;
}

int __cdecl BG_FindWeaponIndexForName(char const *name) {
  int v1; // ebx
  int *i; // esi

  if (bg_iNumWeapons <= 0)
    return 0;
  v1 = 1;
  for (i = bg_weaponDefs; I_stricmp(a1, *(char **)i[1]); ++i) {
    if (++v1 > bg_iNumWeapons)
      return 0;
  }
  return v1;
}

int __cdecl BG_GetAmmoClipForName(char const *) { UNIMPLEMENTED(); }

int __cdecl BG_GetAmmoTypeForName(char const *) { UNIMPLEMENTED(); }

void __cdecl PM_AdjustAimSpreadScale(struct pmove_t *pm, struct pml_t *pml) {
  int32_t ps;    // ebx
  pml_t *result; // eax
  float *v4;     // esi
  float v5;      // xmm0_4
  float v6;      // xmm0_4
  float v7;      // xmm0_4
  int v8;        // eax
  float v9;      // xmm5_4
  float v10;     // xmm4_4
  pmove_t *v11;  // edi
  int i;         // eax
  float v13;     // [esp+1Ch] [ebp-3Ch]
  float v14;     // [esp+38h] [ebp-20h]
  int v15;       // [esp+3Ch] [ebp-1Ch]

  ps = a1->ps;
  result = *(pml_t **)(a1->ps + 212);
  v4 = (float *)bg_weaponDefs[(_DWORD)result];
  v5 = v4[169];
  if (v5 == 0.0) {
    v6 = -1.0;
    goto LABEL_3;
  }
  if (*(_DWORD *)(ps + 96) != 1023 || *(_DWORD *)(ps + 4) == 1) {
    v8 = *(_DWORD *)(ps + 160);
    if ((v8 & 8) != 0) {
      v5 = v5 * v4[174];
    } else if ((v8 & 4) != 0) {
      v5 = v5 * v4[173];
    }
    result = a2;
    v14 = v5 * *(float *)&a2->frametime;
    if (*(float *)(ps + 220) != 1.0)
      goto LABEL_17;
  } else {
    result = a2;
    v14 = (float)(v5 * 0.5) * *(float *)&a2->frametime;
    if (*(float *)(ps + 220) != 1.0) {
    LABEL_17:
      if (v4[171] == 0.0) {
        v9 = 0.0;
      } else {
        v11 = a1;
        v9 = 0.0;
        v15 = 2;
        do {
          v13 = AngleSubtract((float)*(int *)&v11->cmd[12] * 0.0054931641,
                              (float)*(int *)&v11->oldcmd[12] * 0.0054931641);
          v9 = v9 +
               (float)((float)((float)(fabs(v13) * 0.0099999998) * v4[171]) /
                       *(float *)&a2->frametime);
          v11 = (pmove_t *)((char *)v11 + 4);
          --v15;
        } while (v15);
      }
      v10 = v4[172];
      if (v10 != 0.0 && *(_WORD *)&a1->cmd[24] &&
          (float)((float)(*(float *)(ps + 32) * *(float *)(ps + 32)) +
                  (float)(*(float *)(ps + 36) * *(float *)(ps + 36))) >
              (float)(*(float *)(bg_aimSpreadMoveSpeedThreshold + 8) *
                      *(float *)(bg_aimSpreadMoveSpeedThreshold + 8))) {
        v9 = v9 + v10;
      }
      if (*(_DWORD *)(ps + 96) == 1023 && *(_DWORD *)(ps + 4) != 1) {
        for (i = 0; i != 2; ++i)
          v9 = v9 + 1.28;
      }
      result = a2;
      v6 = (float)(v9 * *(float *)&a2->frametime) - v14;
    LABEL_3:
      v7 = (float)(v6 * 255.0) + *(float *)(ps + 1492);
      *(float *)(ps + 1492) = v7;
      if (v7 >= 0.0)
        goto LABEL_4;
    LABEL_12:
      *(_DWORD *)(ps + 1492) = 0;
      return result;
    }
  }
  v7 = (float)((float)(0.0 - v14) * 255.0) + *(float *)(ps + 1492);
  *(float *)(ps + 1492) = v7;
  if (v7 < 0.0)
    goto LABEL_12;
LABEL_4:
  if (v7 > 255.0)
    *(_DWORD *)(ps + 1492) = 1132396544;
  return result;
}

int __cdecl PM_InteruptWeaponWithProneMove(struct playerState_s *) {
  unsigned int weaponstate; // edx
  int32_t v2;               // eax

  weaponstate = a1->weaponstate;
  if (weaponstate <= 2 || weaponstate == 5 || weaponstate == 7 ||
      weaponstate == 9 || weaponstate == 8 || weaponstate == 6 ||
      weaponstate == 4) {
    return 1;
  }
  if (weaponstate != 3 && weaponstate != 11 && weaponstate - 12 > 4) {
    a1->pm_flags &= 0xFFFFF7EF;
    if (weaponstate - 17 <= 5) {
      a1->fWeaponPosFrac = 0.0;
      PM_AddEvent(a1, 149);
      a1->pm_flags &= 0xFFFDFFBF;
      PM_AddEvent(a1, 169);
    }
    a1->weaponTime = 0;
    a1->weaponDelay = 0;
    a1->weaponstate = 0;
    if (a1->pm_type <= 5) {
      v2 = a1->weapAnim & 0x200;
      BYTE1(v2) ^= 2u;
      a1->weapAnim = v2;
      return 1;
    }
    return 1;
  }
  return 0;
}

void __cdecl PM_UpdateAimDownSightLerp(struct pmove_t *pm, struct pml_t *pml) {
  UNIMPLEMENTED();
}

void __cdecl PM_UpdateAimDownSightFlag(struct pmove_t *pm, struct pml_t *pml) {
  _DWORD *ps;      // ebx
  unsigned int v3; // edi
  char v4;         // si
  int v5;          // eax
  char v6;         // dl
  int v8;          // eax
  int v9;          // edx
  int v10;         // ecx
  int *v11;        // edx
  int v12;         // eax
  int v13;         // [esp+18h] [ebp-20h]

  ps = (_DWORD *)a1->ps;
  v13 = *(_DWORD *)(a1->ps + 12);
  v3 = v13 & 0xFFFFFFBF;
  v4 = v13 & 0xBF;
  ps[3] = v13 & 0xFFFFFFBF;
  v5 = ps[1];
  if (v5 == 1) {
    if (a2->almostGroundPlane)
      goto LABEL_4;
  } else if (v5 >= 1 && v5 <= 7) {
    goto LABEL_4;
  }
  if ((v13 & 0x20000) == 0) {
    if ((v13 & 0x10) != 0)
      v8 = ps[52];
    else
      v8 = ps[53];
    goto LABEL_13;
  }
  if (bg_iNumWeapons <= 0)
    goto LABEL_12;
  if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
    v10 = 1;
    v11 = bg_weaponDefs;
    while (bg_iNumWeapons >= ++v10) {
      v12 = v11[2];
      ++v11;
      if (*(_DWORD *)(v12 + 120) == 3) {
        v8 = (unsigned __int8)v10;
        goto LABEL_13;
      }
    }
  LABEL_12:
    v8 = 0;
    goto LABEL_13;
  }
  v8 = 1;
LABEL_13:
  if (!*(_DWORD *)(bg_weaponDefs[v8] + 812))
    goto LABEL_4;
  v9 = ps[54];
  if ((unsigned int)(v9 - 12) <= 4 || (unsigned int)(v9 - 10) <= 1 ||
      (unsigned int)(v9 - 1) <= 1)
    goto LABEL_4;
  if ((unsigned int)(v9 - 17) > 5) {
    v6 = 1;
    goto LABEL_5;
  }
  if ((unsigned int)(v9 - 19) > 1) {
  LABEL_4:
    v6 = 0;
    goto LABEL_5;
  }
  v6 = 1;
LABEL_5:
  if (((a1->cmd[5] & 0x10) != 0 || (unsigned int)(ps[54] - 19) <= 1) && v6) {
    if ((v13 & 1) != 0) {
      if ((a1->oldcmd[5] & 0x10) == 0 || !*(_WORD *)&a1->cmd[24]) {
        ps[3] = v13 & 0xFFFFF7BF | 0x840;
        return BG_UpdateConditionValue(ps[51], 7, 1, 1);
      }
    } else {
      v4 = v3 | 0x40;
      ps[3] = v3 | 0x40;
    }
  }
  if ((v4 & 0x40) != 0)
    return BG_UpdateConditionValue(ps[51], 7, 1, 1);
  return BG_UpdateConditionValue(ps[51], 7, 0, 1);
}

void __cdecl BG_CalculateWeaponPosition_Sway(struct playerState_s *ps,
                                             float *const swayViewAngles,
                                             float *const swayOffset,
                                             float *const swayAngles,
                                             float ssSwayScale, int frametime) {
  float fWeaponPosFrac;  // xmm5_4
  uint32_t pm_flags;     // eax
  uint32_t offHandIndex; // eax
  int v9;                // eax
  float v10;             // xmm6_4
  float v11;             // xmm4_4
  float v12;             // xmm3_4
  float v13;             // xmm2_4
  float v14;             // xmm1_4
  __m128 v15;            // xmm0
  __m128 v16;            // xmm4
  __m128 v17;            // xmm5
  __m128 v18;            // xmm2
  __m128 v19;            // xmm1
  __m128 v20;            // xmm1
  __m128 v21;            // xmm0
  __m128 v22;            // xmm0
  __m128 v23;            // xmm0
  __m128 v24;            // xmm0
  __m128 v25;            // xmm1
  __m128 v26;            // xmm1
  int v27;               // ecx
  int *v28;              // edx
  int v29;               // eax
  float v30;             // [esp+28h] [ebp-40h]
  float v31;             // [esp+2Ch] [ebp-3Ch]
  float v32;             // [esp+30h] [ebp-38h]
  float v33;             // [esp+30h] [ebp-38h]
  float v34;             // [esp+34h] [ebp-34h]
  float v35;             // [esp+3Ch] [ebp-2Ch]
  float v36;             // [esp+44h] [ebp-24h] BYREF
  float v37;             // [esp+48h] [ebp-20h]
  float v38;             // [esp+4Ch] [ebp-1Ch]

  fWeaponPosFrac = a1->fWeaponPosFrac;
  if (!a6)
    return;
  pm_flags = a1->pm_flags;
  if ((pm_flags & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0) {
    LABEL_4:
      offHandIndex = 0;
      goto LABEL_5;
    }
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v27 = 1;
      v28 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v27) {
        v29 = v28[2];
        ++v28;
        if (*(_DWORD *)(v29 + 120) == 3) {
          offHandIndex = (unsigned __int8)v27;
          goto LABEL_5;
        }
      }
      goto LABEL_4;
    }
    offHandIndex = 1;
  } else {
    if ((pm_flags & 0x10) == 0) {
      v9 = bg_weaponDefs[a1->weapon];
      v31 = (float)a6 * 0.001;
      if (*(_DWORD *)(v9 + 812))
        goto LABEL_6;
    LABEL_13:
      v10 = *(float *)(v9 + 744);
      v30 = *(float *)(v9 + 748);
      v11 = *(float *)(v9 + 752);
      v12 = *(float *)(v9 + 756);
      v13 = *(float *)(v9 + 760);
      v14 = *(float *)(v9 + 764);
      goto LABEL_9;
    }
    offHandIndex = a1->offHandIndex;
  }
LABEL_5:
  v9 = bg_weaponDefs[offHandIndex];
  v31 = (float)a6 * 0.001;
  if (!*(_DWORD *)(v9 + 812))
    goto LABEL_13;
LABEL_6:
  if (fWeaponPosFrac <= 0.0 || !*(_DWORD *)(v9 + 632)) {
    v10 = (float)((float)(*(float *)(v9 + 772) - *(float *)(v9 + 744)) *
                  fWeaponPosFrac) +
          *(float *)(v9 + 744);
    v30 = *(float *)(v9 + 748) +
          (float)((float)(*(float *)(v9 + 776) - *(float *)(v9 + 748)) *
                  fWeaponPosFrac);
    v11 = (float)((float)(*(float *)(v9 + 780) - *(float *)(v9 + 752)) *
                  fWeaponPosFrac) +
          *(float *)(v9 + 752);
    v12 = (float)((float)(*(float *)(v9 + 784) - *(float *)(v9 + 756)) *
                  fWeaponPosFrac) +
          *(float *)(v9 + 756);
    v13 = (float)((float)(*(float *)(v9 + 788) - *(float *)(v9 + 760)) *
                  fWeaponPosFrac) +
          *(float *)(v9 + 760);
    v14 = (float)((float)(*(float *)(v9 + 792) - *(float *)(v9 + 764)) *
                  fWeaponPosFrac) +
          *(float *)(v9 + 764);
  LABEL_9:
    v35 = v11 * a5;
    v34 = v13 * a5;
    v32 = v14 * a5;
    AnglesSubtract(a1->viewangles, a2, &v36);
    v15 = (__m128)0x3F800000u;
    v15.f32[0] = 1.0 / (float)(v31 * 60.0);
    v16 = v15;
    v16.f32[0] = v15.f32[0] * v36;
    v17 = v15;
    v17.f32[0] = v15.f32[0] * v37;
    v38 = v15.f32[0] * v38;
    v18 = _mm_xor_ps((__m128)LODWORD(v10), (__m128)xmmword_2F0A00);
    v19 = v16;
    v19.f32[0] = (float)(v15.f32[0] * v36) - v10;
    v20 = _mm_cmpge_ss(v19, (__m128)0LL);
    v21 = v18;
    v21.f32[0] = v18.f32[0] - v16.f32[0];
    v22 = _mm_cmplt_ss(v21, (__m128)0LL);
    LODWORD(v36) =
        _mm_andnot_ps(v22, v18).u32[0] |
        (_mm_andnot_ps(v20, v16).u32[0] | LODWORD(v10) & v20.i32[0]) &
            v22.i32[0];
    v23 = v17;
    v23.f32[0] = v17.f32[0] - v10;
    v24 = _mm_cmpge_ss(v23, (__m128)0LL);
    v25 = v18;
    v25.f32[0] = v18.f32[0] - v17.f32[0];
    v26 = _mm_cmpge_ss(v25, (__m128)0LL);
    LODWORD(v37) =
        _mm_andnot_ps(v26, _mm_or_ps(_mm_andnot_ps(v24, v17),
                                     _mm_and_ps((__m128)LODWORD(v10), v24)))
            .u32[0] |
        v18.i32[0] & v26.i32[0];
    v33 = v32 * v36;
    a3[1] = DiffTrack(v37 * v34, a3[1], v30, v31);
    a3[2] = DiffTrack(v33, a3[2], v30, v31);
    v36 = v35 * v36;
    v37 = (float)(v12 * a5) * v37;
    *a4 = DiffTrackAngle(v36, *a4, v30, v31);
    a4[1] = DiffTrackAngle(v37, a4[1], v30, v31);
    *a2 = a1->viewangles[0];
    a2[1] = a1->viewangles[1];
    a2[2] = a1->viewangles[2];
  }
}

void __cdecl BG_CalculateViewAngles(struct viewState_t *vs,
                                    float *const angles) {
  viewState_t *v2;       // edx
  uint32_t damageTime;   // edi
  int32_t ps;            // ebx
  int v5;                // eax
  int v6;                // eax
  int v7;                // eax
  float v8;              // xmm0_4
  float v9;              // xmm0_4
  float v10;             // xmm0_4
  float v11;             // xmm0_4
  int v12;               // eax
  int v13;               // eax
  int v14;               // eax
  float v15;             // xmm0_4
  float v16;             // xmm3_4
  float v17;             // xmm2_4
  int v18;               // edx
  float v19;             // xmm4_4
  viewState_t *v20;      // edx
  float fLastIdleFactor; // xmm1_4
  float v22;             // xmm0_4
  float v23;             // xmm1_4
  int v24;               // eax
  int v25;               // ecx
  int *v26;              // edx
  int v27;               // eax
  int v28;               // eax
  int v29;               // ecx
  int *v30;              // edx
  int v31;               // eax
  int v32;               // esi
  double v33;            // xmm0_8
  __m128 v34;            // xmm0
  int v35;               // eax
  __m128 v36;            // xmm1
  float v37;             // xmm0_4
  int v38;               // eax
  __m128 v39;            // xmm0
  __m128 v40;            // xmm4
  float v41;             // xmm4_4
  __m128 v42;            // xmm0
  int v43;               // eax
  __m128 v44;            // xmm1
  __m128 v45;            // xmm0
  __m128 v46;            // xmm1
  __m128 v47;            // xmm1
  float v48;             // xmm3_4
  float v49;             // xmm2_4
  float v50;             // xmm0_4
  float v51;             // xmm0_4
  int v52;               // eax
  int v53;               // ecx
  int *v54;              // edx
  int v55;               // eax
  int result;            // eax
  int v57;               // esi
  double v58;            // xmm0_8
  float xyspeed;         // xmm0_4
  int v60;               // eax
  __m128 xyspeed_low;    // xmm2
  __m128 v62;            // xmm0
  float v63;             // xmm0_4
  int v64;               // eax
  __m128 v65;            // xmm1
  __m128 v66;            // xmm0
  int v67;               // ecx
  int *v68;              // edx
  int v69;               // eax
  float v70;             // xmm0_4
  long double v71;       // [esp+0h] [ebp-B8h]
  float v72;             // [esp+0h] [ebp-B8h]
  float v73;             // [esp+1Ch] [ebp-9Ch]
  float v74;             // [esp+1Ch] [ebp-9Ch]
  float v75;             // [esp+1Ch] [ebp-9Ch]
  float v76;             // [esp+1Ch] [ebp-9Ch]
  float v77;             // [esp+1Ch] [ebp-9Ch]
  float v78;             // [esp+30h] [ebp-88h]
  float v79;             // [esp+40h] [ebp-78h]
  float v80;             // [esp+54h] [ebp-64h]
  float v81;             // [esp+64h] [ebp-54h]
  float v82;             // [esp+74h] [ebp-44h]
  float *v83;            // [esp+78h] [ebp-40h]
  float *v84;            // [esp+7Ch] [ebp-3Ch]
  float LeanFraction;    // [esp+80h] [ebp-38h]
  float v86;             // [esp+84h] [ebp-34h]
  float v87;             // [esp+88h] [ebp-30h]
  float v88;             // [esp+8Ch] [ebp-2Ch]
  float v89;             // [esp+90h] [ebp-28h]
  float v90;             // [esp+94h] [ebp-24h]
  float v91;             // [esp+98h] [ebp-20h]
  float v92;             // [esp+9Ch] [ebp-1Ch]
  float v93;             // [esp+9Ch] [ebp-1Ch]

  *a2 = 0.0;
  v83 = a2 + 1;
  a2[1] = 0.0;
  v84 = a2 + 2;
  a2[2] = 0.0;
  v2 = a1;
  damageTime = a1->damageTime;
  if (!damageTime) {
  LABEL_11:
    ps = v2->ps;
    goto LABEL_12;
  }
  ps = a1->ps;
  v5 = *(_DWORD *)(a1->ps + 12);
  if ((v5 & 0x20000) != 0) {
    if (bg_iNumWeapons > 0) {
      if (*(_DWORD *)(dword_1007FA4 + 120) == 3) {
        v6 = 1;
        goto LABEL_5;
      }
      v67 = 1;
      v68 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v67) {
        v69 = v68[2];
        ++v68;
        if (*(_DWORD *)(v69 + 120) == 3) {
          v6 = (unsigned __int8)v67;
          goto LABEL_5;
        }
      }
    }
    v6 = 0;
  } else if ((v5 & 0x10) != 0) {
    v6 = *(_DWORD *)(ps + 208);
  } else {
    v6 = *(_DWORD *)(ps + 212);
  }
LABEL_5:
  v7 = bg_weaponDefs[v6];
  v8 = *(float *)(ps + 220);
  v86 = (float)(v8 * -0.5) + 1.0;
  if (v8 != 0.0 && *(_DWORD *)(v7 + 632))
    v86 = (float)((float)(v8 * 0.5) + 1.0) *
          (float)((float)(*(float *)(ps + 220) * -0.5) + 1.0);
  v9 = (float)(int)(a1->time - damageTime);
  if (v9 >= 100.0) {
    v10 = (float)((float)(v9 - 100.0) / -400.0) + 1.0;
    if (v10 <= 0.0)
      goto LABEL_12;
    LeanFraction = GetLeanFraction(1.0 - v10);
    v11 = (float)(1.0 - LeanFraction) * v86;
    *a2 = (float)(v11 * *(float *)&a1->v_dmg_pitch) + *a2;
    *v84 = (float)(v11 * *(float *)&a1->v_dmg_roll) + *v84;
    v2 = a1;
    goto LABEL_11;
  }
  v77 = GetLeanFraction(v9 / 100.0);
  *a2 = (float)((float)(v77 * v86) * *(float *)&a1->v_dmg_pitch) + *a2;
  *v84 = (float)((float)(v77 * v86) * *(float *)&a1->v_dmg_roll) + *v84;
  ps = a1->ps;
LABEL_12:
  v12 = *(_DWORD *)(ps + 12);
  if ((v12 & 0x20000) != 0) {
    if (bg_iNumWeapons > 0) {
      if (*(_DWORD *)(dword_1007FA4 + 120) == 3) {
        v13 = 1;
        goto LABEL_17;
      }
      v29 = 1;
      v30 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v29) {
        v31 = v30[2];
        ++v30;
        if (*(_DWORD *)(v31 + 120) == 3) {
          v13 = (unsigned __int8)v29;
          goto LABEL_17;
        }
      }
    }
    v13 = 0;
    goto LABEL_17;
  }
  if ((v12 & 0x10) != 0)
    v13 = *(_DWORD *)(ps + 208);
  else
    v13 = *(_DWORD *)(ps + 212);
LABEL_17:
  v14 = bg_weaponDefs[v13];
  if (!*(_DWORD *)(v14 + 632))
    goto LABEL_25;
  if (*(_DWORD *)(v14 + 812)) {
    v15 = *(float *)(ps + 220);
    v16 =
        (float)((float)(*(float *)(v14 + 712) - *(float *)(v14 + 716)) * v15) +
        *(float *)(v14 + 716);
    v17 =
        (float)((float)(*(float *)(v14 + 720) - *(float *)(v14 + 724)) * v15) +
        *(float *)(v14 + 724);
  } else {
    v16 = *(float *)(v14 + 716);
    if (v16 == 0.0) {
      v16 = 80.0;
      v17 = 1.0;
    } else {
      v17 = *(float *)(v14 + 724);
    }
  }
  v18 = *(_DWORD *)(ps + 160);
  if ((v18 & 8) != 0) {
    v19 = *(float *)(v14 + 732);
  } else if ((v18 & 4) != 0) {
    v19 = *(float *)(v14 + 728);
  } else {
    v19 = 1.0;
  }
  if (*(float *)(ps + 220) == 0.0) {
  LABEL_76:
    v20 = a1;
    goto LABEL_24;
  }
  v20 = a1;
  fLastIdleFactor = a1->fLastIdleFactor;
  if (v19 != fLastIdleFactor) {
    if (v19 <= fLastIdleFactor) {
      a1->fLastIdleFactor =
          fmaxf(v19, fLastIdleFactor - (float)(0.5 * *(float *)&a1->frametime));
    } else {
      v70 = (float)(0.5 * *(float *)&a1->frametime) + fLastIdleFactor;
      a1->fLastIdleFactor = v70;
      if (v70 > v19) {
        a1->fLastIdleFactor = v19;
        v20 = a1;
        goto LABEL_24;
      }
    }
    goto LABEL_76;
  }
LABEL_24:
  v22 = *(float *)(ps + 1460);
  v23 =
      (float)((float)(v16 * v20->fLastIdleFactor) * *(float *)(ps + 220)) * v22;
  *(_DWORD *)v20->weapIdleTime +=
      (int)(float)(v17 *
                   (float)((float)(v22 * *(float *)&v20->frametime) * 1000.0));
  v73 = sinf((float)*(int *)a1->weapIdleTime * 0.00069999998);
  *v83 = (float)((float)(v73 * v23) * 0.0099999998) + *v83;
  v82 = sinf((float)*(int *)a1->weapIdleTime * 0.001);
  *a2 = (float)((float)(v23 * v82) * 0.0099999998) + *a2;
  ps = a1->ps;
LABEL_25:
  v24 = *(_DWORD *)(ps + 12);
  if ((v24 & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0) {
    LABEL_77:
      v28 = 0;
      goto LABEL_42;
    }
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v25 = 1;
      v26 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v25) {
        v27 = v26[2];
        ++v26;
        if (*(_DWORD *)(v27 + 120) == 3) {
          v28 = (unsigned __int8)v25;
          goto LABEL_42;
        }
      }
      goto LABEL_77;
    }
    v28 = 1;
  } else if ((v24 & 0x10) != 0) {
    v28 = *(_DWORD *)(ps + 208);
  } else {
    v28 = *(_DWORD *)(ps + 212);
  }
LABEL_42:
  v32 = bg_weaponDefs[v28];
  if (*(_DWORD *)(v32 + 632)) {
    v33 = (float)((float)*(unsigned __int8 *)(ps + 8) / 255.0) *
          3.141592653589793;
    *(float *)&v33 = v33 + v33 + 6.283185307179586;
    *(float *)&v33 = *(float *)&v33 + 0.7853981633974483 + 6.283185307179586;
    v88 = *(float *)&v33;
    v34 = (__m128)0x3E23D70Au;
    v87 = 0.16 * a1->xyspeed;
    v35 = *(_DWORD *)(ps + 244);
    if (v35 == 11) {
      v34.f32[0] =
          (float)(0.16 * a1->xyspeed) * *(float *)(bg_bobAmplitudeProne + 8);
    } else {
      v34 = (__m128)LODWORD(v87);
      if (v35 == 40)
        v34.f32[0] = v87 * *(float *)(bg_bobAmplitudeDucked + 8);
      else
        v34.f32[0] = v87 * *(float *)(bg_bobAmplitudeStanding + 8);
    }
    v36 = _mm_cmplt_ss((__m128)0x41200000u, v34);
    LODWORD(v92) = _mm_andnot_ps(v36, v34).u32[0] | v36.i32[0] & 0x41200000;
    v74 = sinf(v88 + v88);
    *(double *)&v71 = (float)(v88 * 4.0) + 1.570796326794897;
    v37 = sin(v71);
    v93 = -(float)((float)((float)(v74 + (float)(v37 * 0.2)) * 0.75) * v92);
    v38 = *(_DWORD *)(ps + 244);
    if (v38 == 11) {
      v39 = (__m128)LODWORD(v87);
      v39.f32[0] = v87 * *(float *)(bg_bobAmplitudeProne + 8);
    } else {
      v39 = (__m128)LODWORD(v87);
      if (v38 == 40)
        v39.f32[0] = v87 * *(float *)(bg_bobAmplitudeDucked + 8);
      else
        v39.f32[0] = v87 * *(float *)(bg_bobAmplitudeStanding + 8);
    }
    v40 = _mm_cmplt_ss((__m128)0x41200000u, v39);
    v81 = sinf(v88);
    v41 = -(float)(COERCE_FLOAT(_mm_andnot_ps(v40, v39).u32[0] |
                                v40.i32[0] & 0x41200000) *
                   v81);
    v42 = (__m128)LODWORD(v87);
    v42.f32[0] = v87 * 1.5;
    v43 = *(_DWORD *)(ps + 244);
    if (v43 == 11) {
      v44 = v42;
      v44.f32[0] = v42.f32[0] * *(float *)(bg_bobAmplitudeProne + 8);
    } else {
      v44 = v42;
      if (v43 == 40)
        v44.f32[0] = v42.f32[0] * *(float *)(bg_bobAmplitudeDucked + 8);
      else
        v44.f32[0] = v42.f32[0] * *(float *)(bg_bobAmplitudeStanding + 8);
    }
    v45 = _mm_cmplt_ss((__m128)0x41200000u, v44);
    v72 = v88 - 0.4712389167638204;
    LODWORD(v79) = _mm_andnot_ps(v45, v44).u32[0] | v45.i32[0] & 0x41200000;
    v75 = sinf(v72);
    v46 = 0;
    v46.f32[0] = 0.0 - (float)(v75 * v79);
    v47 = _mm_cmpge_ss(v46, (__m128)0LL);
    LODWORD(v48) = _mm_andnot_ps(v47, (__m128)0LL).u32[0] |
                   COERCE_UNSIGNED_INT(v75 * v79) & v47.i32[0];
    v49 = *(float *)(ps + 220);
    if (v49 == 0.0) {
      v51 = v93;
    } else {
      v50 = 1.0 - (float)((float)(1.0 - *(float *)(v32 + 644)) * v49);
      v41 = v41 * v50;
      v48 = v48 * v50;
      v51 = v93 * v50;
    }
    *a2 = (float)(v51 * v49) + *a2;
    *v83 = (float)(v41 * v49) + a2[1];
    *v84 = (float)(v49 * v48) + a2[2];
    ps = a1->ps;
  }
  v52 = *(_DWORD *)(ps + 12);
  if ((v52 & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0) {
    LABEL_78:
      result = 0;
      goto LABEL_65;
    }
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v53 = 1;
      v54 = bg_weaponDefs;
      while (++v53 <= bg_iNumWeapons) {
        v55 = v54[2];
        ++v54;
        if (*(_DWORD *)(v55 + 120) == 3) {
          result = (unsigned __int8)v53;
          v57 = bg_weaponDefs[(unsigned __int8)v53];
          if ((*(_DWORD *)(ps + 160) & 0x300) == 0)
            goto LABEL_66;
          return result;
        }
      }
      goto LABEL_78;
    }
    result = 1;
  } else if ((v52 & 0x10) != 0) {
    result = *(_DWORD *)(ps + 208);
  } else {
    result = *(_DWORD *)(ps + 212);
  }
LABEL_65:
  v57 = bg_weaponDefs[result];
  if ((*(_DWORD *)(ps + 160) & 0x300) == 0) {
  LABEL_66:
    v89 = *(float *)(ps + 220);
    if (v89 != 0.0) {
      v90 = *(float *)(v57 + 648);
      if (v90 != 0.0) {
        v58 = (float)((float)*(unsigned __int8 *)(ps + 8) / 255.0) *
              3.141592653589793;
        *(float *)&v58 = v58 + v58 + 6.283185307179586;
        v91 = *(float *)&v58;
        xyspeed = a1->xyspeed;
        v60 = *(_DWORD *)(ps + 244);
        if (v60 == 11) {
          xyspeed_low = (__m128)LODWORD(a1->xyspeed);
          xyspeed_low.f32[0] = xyspeed * *(float *)(bg_bobAmplitudeProne + 8);
        } else {
          xyspeed_low = (__m128)LODWORD(a1->xyspeed);
          if (v60 == 40)
            xyspeed_low.f32[0] =
                xyspeed * *(float *)(bg_bobAmplitudeDucked + 8);
          else
            xyspeed_low.f32[0] =
                xyspeed * *(float *)(bg_bobAmplitudeStanding + 8);
        }
        v62 = _mm_cmplt_ss((__m128)0x42340000u, xyspeed_low);
        LODWORD(v78) =
            _mm_andnot_ps(v62, xyspeed_low).u32[0] | v62.i32[0] & 0x42340000;
        v76 = sinf(v91 + v91);
        *(double *)&v71 = (float)(v91 * 4.0) + 1.570796326794897;
        v62.f32[0] = sin(v71);
        *a2 = *a2 -
              (float)((float)(v78 *
                              (float)((float)(v76 + (float)(v62.f32[0] * 0.2)) *
                                      0.75)) *
                      (float)(v89 * v90));
        v63 = a1->xyspeed;
        v64 = *(_DWORD *)(ps + 244);
        if (v64 == 11) {
          v65 = (__m128)LODWORD(a1->xyspeed);
          v65.f32[0] = v63 * *(float *)(bg_bobAmplitudeProne + 8);
        } else {
          v65 = (__m128)LODWORD(a1->xyspeed);
          if (v64 == 40)
            v65.f32[0] = v63 * *(float *)(bg_bobAmplitudeDucked + 8);
          else
            v65.f32[0] = v63 * *(float *)(bg_bobAmplitudeStanding + 8);
        }
        v66 = _mm_cmplt_ss((__m128)0x42340000u, v65);
        v80 = sinf(v91);
        result = (int)(a2 + 1);
        *v83 = *v83 -
               (float)((float)(COERCE_FLOAT(_mm_andnot_ps(v66, v65).u32[0] |
                                            v66.i32[0] & 0x42340000) *
                               v80) *
                       (float)(*(float *)(ps + 220) * *(float *)(v57 + 648)));
      }
    }
  }
  return result;
}

void __cdecl PM_ResetWeaponState(struct playerState_s *ps) {
  unsigned int v1; // eax

  a1->pm_flags &= 0xFFFFF7EF;
  v1 = a1->weaponstate - 17;
  if (v1 <= 5) {
    a1->fWeaponPosFrac = 0.0;
    PM_AddEvent(a1, 149);
    a1->pm_flags &= 0xFFFDFFBF;
    LOWORD(v1) = PM_AddEvent(a1, 169);
  }
  a1->weaponTime = 0;
  a1->weaponDelay = 0;
  a1->weaponstate = 0;
  if (a1->pm_type <= 5) {
    v1 = a1->weapAnim & 0x200;
    BYTE1(v1) ^= 2u;
    a1->weapAnim = v1;
  }
  return v1;
}

void __cdecl BG_CalculateWeaponAngles(struct weaponState_t *ws,
                                      float *const angles) {
  int32_t ps;            // eax
  float v3;              // xmm0_4
  int32_t v4;            // esi
  int v5;                // eax
  int v6;                // eax
  int v7;                // eax
  int v8;                // eax
  int v9;                // ecx
  int *v10;              // edx
  int v11;               // eax
  float *v12;            // ebx
  int v13;               // edx
  bool v14;              // al
  float v15;             // xmm1_4
  __m128 xyspeed_low;    // xmm0
  __m128 v17;            // xmm2
  __m128 v18;            // xmm1
  __m128 v19;            // xmm1
  float v20;             // xmm1_4
  float *v21;            // eax
  float v22;             // xmm0_4
  int v23;               // ecx
  int *v24;              // edx
  int v25;               // eax
  int v26;               // eax
  float v27;             // xmm1_4
  weaponState_t *v28;    // eax
  int i;                 // ecx
  float *vLastMoveAng;   // edx
  float v31;             // xmm3_4
  float v32;             // xmm2_4
  float v33;             // xmm1_4
  float v34;             // xmm0_4
  float v35;             // xmm1_4
  float v36;             // xmm1_4
  int v37;               // eax
  int v38;               // eax
  int v39;               // edx
  float v40;             // xmm5_4
  float v41;             // xmm3_4
  int v42;               // eax
  float v43;             // xmm4_4
  float fLastIdleFactor; // xmm2_4
  float v45;             // xmm1_4
  float v46;             // xmm2_4
  weaponState_t *v47;    // ecx
  int v48;               // ecx
  int *v49;              // edx
  int v50;               // eax
  float v51;             // xmm0_4
  float v52;             // xmm5_4
  weaponState_t *v53;    // edi
  int32_t v54;           // ebx
  int v55;               // eax
  int v56;               // ecx
  int *v57;              // edx
  int v58;               // eax
  int v59;               // eax
  int v60;               // esi
  double v61;            // xmm0_8
  __m128 v62;            // xmm0
  int v63;               // eax
  __m128 v64;            // xmm1
  float v65;             // xmm0_4
  int v66;               // eax
  __m128 v67;            // xmm0
  __m128 v68;            // xmm4
  float v69;             // xmm4_4
  __m128 v70;            // xmm0
  int v71;               // eax
  __m128 v72;            // xmm1
  __m128 v73;            // xmm0
  __m128 v74;            // xmm0
  __m128 v75;            // xmm0
  float v76;             // xmm2_4
  float v77;             // xmm3_4
  float v78;             // xmm0_4
  float v79;             // xmm0_4
  weaponState_t *v80;    // eax
  uint32_t damageTime;   // edi
  int32_t v82;           // esi
  int v83;               // eax
  int v84;               // eax
  int v85;               // eax
  float v86;             // xmm1_4
  float v87;             // xmm2_4
  float v88;             // xmm3_4
  float v89;             // xmm4_4
  float v90;             // xmm0_4
  float v91;             // xmm1_4
  float v92;             // xmm1_4
  int v93;               // eax
  int v94;               // eax
  int v95;               // ebx
  float v96;             // xmm1_4
  float v97;             // xmm7_4
  float v98;             // xmm6_4
  float v99;             // xmm5_4
  float v100;            // xmm4_4
  float *vGunOffset;     // edi
  float v102;            // xmm0_4
  int v103;              // esi
  weaponState_t *v104;   // ecx
  int v105;              // ecx
  int *v106;             // edx
  int v107;              // eax
  float v108;            // xmm0_4
  int v109;              // ecx
  int *v110;             // edx
  int v111;              // eax
  long double v112;      // [esp+0h] [ebp-E8h]
  float v113;            // [esp+0h] [ebp-E8h]
  float v114;            // [esp+1Ch] [ebp-CCh]
  float v115;            // [esp+1Ch] [ebp-CCh]
  float v116;            // [esp+1Ch] [ebp-CCh]
  float v117;            // [esp+1Ch] [ebp-CCh]
  float LeanFraction;    // [esp+1Ch] [ebp-CCh]
  float v119;            // [esp+1Ch] [ebp-CCh]
  float v120;            // [esp+70h] [ebp-78h]
  float *v121;           // [esp+8Ch] [ebp-5Ch]
  float *v122;           // [esp+90h] [ebp-58h]
  float v123;            // [esp+94h] [ebp-54h]
  float v124;            // [esp+A0h] [ebp-48h]
  float v125;            // [esp+A4h] [ebp-44h]
  float v126;            // [esp+A8h] [ebp-40h]
  float v127;            // [esp+ACh] [ebp-3Ch]
  float v128;            // [esp+B0h] [ebp-38h]
  float v129;            // [esp+B4h] [ebp-34h]
  float v130;            // [esp+B8h] [ebp-30h]
  float v131;            // [esp+B8h] [ebp-30h]
  float v132;            // [esp+BCh] [ebp-2Ch]
  int v133;              // [esp+C0h] [ebp-28h]
  float v134;            // [esp+C4h] [ebp-24h]
  float v135;            // [esp+C8h] [ebp-20h]
  float v136;            // [esp+CCh] [ebp-1Ch]

  ps = a1->ps;
  *a2 = 0.0;
  v122 = a2 + 1;
  a2[1] = 0.0;
  v121 = a2 + 2;
  a2[2] = 0.0;
  v3 = *(float *)(ps + 76);
  if (v3 != 0.0) {
    LeanFraction = GetLeanFraction(v3);
    a2[2] = (float)(LeanFraction * -2.0) + a2[2];
  }
  v4 = a1->ps;
  v5 = *(_DWORD *)(a1->ps + 12);
  if ((v5 & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0) {
    LABEL_5:
      v6 = 0;
      goto LABEL_6;
    }
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v23 = 1;
      v24 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v23) {
        v25 = v24[2];
        ++v24;
        if (*(_DWORD *)(v25 + 120) == 3) {
          v6 = (unsigned __int8)v23;
          goto LABEL_6;
        }
      }
      goto LABEL_5;
    }
    v6 = 1;
  } else if ((v5 & 0x10) != 0) {
    v6 = *(_DWORD *)(v4 + 208);
  } else {
    v6 = *(_DWORD *)(v4 + 212);
  }
LABEL_6:
  v7 = bg_weaponDefs[v6];
  if (*(_DWORD *)(v7 + 812)) {
    *a2 = (float)(*(float *)(v4 + 220) * *(float *)(v7 + 1132)) + *a2;
    v4 = a1->ps;
  }
  v8 = *(_DWORD *)(v4 + 12);
  if ((v8 & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0) {
    LABEL_138:
      v26 = 0;
      goto LABEL_32;
    }
    if (*(_DWORD *)(dword_1007FA4 + 120) != 3) {
      v9 = 1;
      v10 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v9) {
        v11 = v10[2];
        ++v10;
        if (*(_DWORD *)(v11 + 120) == 3) {
          v12 = (float *)bg_weaponDefs[(unsigned __int8)v9];
          v13 = *(_DWORD *)(v4 + 160);
          v14 = (v13 & 8) != 0;
          if ((v13 & 8) == 0)
            goto LABEL_33;
          goto LABEL_15;
        }
      }
      goto LABEL_138;
    }
    v26 = 1;
  } else if ((v8 & 0x10) != 0) {
    v26 = *(_DWORD *)(v4 + 208);
  } else {
    v26 = *(_DWORD *)(v4 + 212);
  }
LABEL_32:
  v12 = (float *)bg_weaponDefs[v26];
  v13 = *(_DWORD *)(v4 + 160);
  v14 = (v13 & 8) != 0;
  if ((v13 & 8) != 0) {
  LABEL_15:
    v15 = v12[108];
    xyspeed_low = (__m128)LODWORD(a1->xyspeed);
    if (xyspeed_low.f32[0] <= v15)
      goto LABEL_36;
  } else {
  LABEL_33:
    if ((v13 & 4) != 0)
      v15 = v12[107];
    else
      v15 = v12[106];
    xyspeed_low = (__m128)LODWORD(a1->xyspeed);
    if (xyspeed_low.f32[0] <= v15)
      goto LABEL_36;
  }
  if (*(_DWORD *)(v4 + 216) != 5) {
    v17 = xyspeed_low;
    v17.f32[0] = (float)(xyspeed_low.f32[0] - v15) /
                 (float)((float)*(int *)(v4 + 80) - v15);
    if ((float)(0.0 - v17.f32[0]) < 0.0) {
      v18 = v17;
      v18.f32[0] = v17.f32[0] - 1.0;
    } else {
      v17.i32[0] = 0;
      v18 = (__m128)0xBF800000;
    }
    v19 = _mm_cmplt_ss(v18, (__m128)0LL);
    LODWORD(v20) = _mm_andnot_ps(v19, (__m128)0x3F800000u).u32[0] |
                   v17.i32[0] & v19.i32[0];
    if (v14) {
      v21 = v12 + 96;
      v22 = v20 * v12[96];
    } else if ((v13 & 4) != 0) {
      v21 = v12 + 87;
      v22 = v20 * v12[87];
    } else {
      v21 = v12 + 78;
      v22 = v20 * v12[78];
    }
    v134 = v22;
    v135 = v20 * v21[1];
    v136 = v20 * v21[2];
    goto LABEL_37;
  }
LABEL_36:
  v134 = 0.0;
  v135 = 0.0;
  v136 = 0.0;
LABEL_37:
  v27 = *(float *)(v4 + 220);
  if (v27 != 0.0) {
    v134 = (float)(1.0 - v27) * v134;
    v135 = (float)(1.0 - v27) * v135;
    v136 = (float)(1.0 - v27) * v136;
  }
  v28 = a1;
  for (i = 1; i != 4; ++i) {
    vLastMoveAng = v28->vLastMoveAng;
    v31 = v28->vLastMoveAng[0];
    v32 = *((float *)&v133 + i);
    if (v31 == v32)
      goto LABEL_45;
    if (*(float *)(v4 + 248) == 11.0)
      v33 = (float)((float)(v32 - v31) * *(float *)&a1->frametime) * v12[105];
    else
      v33 = (float)((float)(v32 - v31) * *(float *)&a1->frametime) * v12[104];
    if (v32 <= v31) {
      v32 = fmaxf(v32, fminf(*(float *)&a1->frametime * -0.1, v33) + v31);
    } else {
      v34 = fmaxf(*(float *)&a1->frametime * 0.1, v33) + v31;
      *vLastMoveAng = v34;
      if (v34 <= v32)
        goto LABEL_45;
    }
    *vLastMoveAng = v32;
  LABEL_45:
    v28 = (weaponState_t *)((char *)v28 + 4);
  }
  v35 = *(float *)(v4 + 220);
  if (v35 == 0.0) {
    *a2 = *a2 + a1->vLastMoveAng[0];
    *v122 = a2[1] + a1->vLastMoveAng[1];
    *v121 = a2[2] + a1->vLastMoveAng[2];
    v4 = a1->ps;
    v37 = *(_DWORD *)(a1->ps + 12);
    if ((v37 & 0x20000) == 0)
      goto LABEL_50;
  LABEL_68:
    if (bg_iNumWeapons > 0) {
      if (*(_DWORD *)(dword_1007FA4 + 120) == 3) {
        v38 = 1;
        goto LABEL_52;
      }
      v48 = 1;
      v49 = bg_weaponDefs;
      while (++v48 <= bg_iNumWeapons) {
        v50 = v49[2];
        ++v49;
        if (*(_DWORD *)(v50 + 120) == 3) {
          v39 = bg_weaponDefs[(unsigned __int8)v48];
          if (!*(_DWORD *)(v39 + 812))
            goto LABEL_53;
          goto LABEL_74;
        }
      }
    }
    v38 = 0;
    goto LABEL_52;
  }
  if (v35 < 0.5) {
    v36 = (float)(v35 * -2.0) + 1.0;
    *a2 = (float)(v36 * a1->vLastMoveAng[0]) + *a2;
    *v122 = (float)(v36 * a1->vLastMoveAng[1]) + a2[1];
    *v121 = (float)(v36 * a1->vLastMoveAng[2]) + a2[2];
    v4 = a1->ps;
  }
  v37 = *(_DWORD *)(v4 + 12);
  if ((v37 & 0x20000) != 0)
    goto LABEL_68;
LABEL_50:
  if ((v37 & 0x10) != 0)
    v38 = *(_DWORD *)(v4 + 208);
  else
    v38 = *(_DWORD *)(v4 + 212);
LABEL_52:
  v39 = bg_weaponDefs[v38];
  if (*(_DWORD *)(v39 + 812)) {
  LABEL_74:
    v51 = *(float *)(v4 + 220);
    v40 =
        (float)((float)(*(float *)(v39 + 712) - *(float *)(v39 + 716)) * v51) +
        *(float *)(v39 + 716);
    v41 =
        (float)((float)(*(float *)(v39 + 720) - *(float *)(v39 + 724)) * v51) +
        *(float *)(v39 + 724);
    v42 = *(_DWORD *)(v4 + 160);
    if ((v42 & 8) == 0)
      goto LABEL_56;
    goto LABEL_75;
  }
LABEL_53:
  v40 = *(float *)(v39 + 716);
  if (v40 == 0.0) {
    v40 = 80.0;
    v41 = 1.0;
  } else {
    v41 = *(float *)(v39 + 724);
  }
  v42 = *(_DWORD *)(v4 + 160);
  if ((v42 & 8) != 0) {
  LABEL_75:
    v43 = *(float *)(v39 + 732);
    goto LABEL_58;
  }
LABEL_56:
  if ((v42 & 4) != 0)
    v43 = *(float *)(v39 + 728);
  else
    v43 = 1.0;
LABEL_58:
  if (*(_DWORD *)(v39 + 632) && *(float *)(v4 + 220) != 0.0) {
    v45 = *(float *)&a1->frametime;
    v47 = a1;
  } else {
    fLastIdleFactor = a1->fLastIdleFactor;
    if (v43 == fLastIdleFactor) {
      v45 = *(float *)&a1->frametime;
      v47 = a1;
    } else if (v43 > fLastIdleFactor) {
      v45 = *(float *)&a1->frametime;
      v108 = (float)(v45 * 0.5) + fLastIdleFactor;
      a1->fLastIdleFactor = v108;
      if (v108 <= v43)
        goto LABEL_171;
      a1->fLastIdleFactor = v43;
      v47 = a1;
    } else {
      v45 = *(float *)&a1->frametime;
      v46 = fLastIdleFactor - (float)(v45 * 0.5);
      a1->fLastIdleFactor = v46;
      if (v43 > v46) {
        a1->fLastIdleFactor = v43;
        v47 = a1;
        goto LABEL_77;
      }
    LABEL_171:
      v47 = a1;
    }
  }
LABEL_77:
  v52 = v40 * v47->fLastIdleFactor;
  v132 = v52;
  if (*(_DWORD *)(v39 + 632)) {
    v132 = (float)(1.0 - *(float *)(v4 + 220)) * v52;
    v53 = a1;
  } else {
    v53 = v47;
  }
  *(_DWORD *)v53->weapIdleTime += (int)(float)(v41 * (float)(v45 * 1000.0));
  v114 = sinf((float)*(int *)v53->weapIdleTime * 0.00050000002);
  *v121 = (float)((float)(v114 * v132) * 0.0099999998) + *v121;
  v115 = sinf((float)*(int *)v53->weapIdleTime * 0.00069999998);
  *v122 = (float)((float)(v115 * v132) * 0.0099999998) + *v122;
  v124 = sinf((float)*(int *)v53->weapIdleTime * 0.001);
  *a2 = (float)(0.0099999998 * (float)(v132 * v124)) + *a2;
  v54 = v53->ps;
  v55 = *(_DWORD *)(v53->ps + 12);
  if ((v55 & 0x20000) != 0) {
    if (bg_iNumWeapons <= 0)
      goto LABEL_136;
    if (*(_DWORD *)(dword_1007FA4 + 120) == 3) {
      v59 = 1;
    } else {
      v56 = 1;
      v57 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v56) {
        v58 = v57[2];
        ++v57;
        if (*(_DWORD *)(v58 + 120) == 3) {
          v59 = (unsigned __int8)v56;
          goto LABEL_89;
        }
      }
    LABEL_136:
      v59 = 0;
    }
  } else if ((v55 & 0x10) != 0) {
    v59 = *(_DWORD *)(v54 + 208);
  } else {
    v59 = *(_DWORD *)(v54 + 212);
  }
LABEL_89:
  v60 = bg_weaponDefs[v59];
  v61 =
      (float)((float)*(unsigned __int8 *)(v54 + 8) / 255.0) * 3.141592653589793;
  *(float *)&v61 = v61 + v61 + 6.283185307179586;
  *(float *)&v61 = *(float *)&v61 + 0.7853981633974483 + 6.283185307179586;
  v126 = *(float *)&v61;
  v62 = (__m128)0x3E23D70Au;
  v125 = 0.16 * a1->xyspeed;
  v63 = *(_DWORD *)(v54 + 244);
  if (v63 == 11) {
    v62.f32[0] =
        (float)(0.16 * a1->xyspeed) * *(float *)(bg_bobAmplitudeProne + 8);
  } else {
    v62 = (__m128)LODWORD(v125);
    if (v63 == 40)
      v62.f32[0] = v125 * *(float *)(bg_bobAmplitudeDucked + 8);
    else
      v62.f32[0] = v125 * *(float *)(bg_bobAmplitudeStanding + 8);
  }
  v64 = _mm_cmplt_ss((__m128)0x41200000u, v62);
  LODWORD(v130) = _mm_andnot_ps(v64, v62).u32[0] | v64.i32[0] & 0x41200000;
  v116 = sinf(v126 + v126);
  *(double *)&v112 = (float)(v126 * 4.0) + 1.570796326794897;
  v65 = sin(v112);
  v131 = -(float)((float)((float)(v116 + (float)(v65 * 0.2)) * 0.75) * v130);
  v66 = *(_DWORD *)(v54 + 244);
  if (v66 == 11) {
    v67 = (__m128)LODWORD(v125);
    v67.f32[0] = v125 * *(float *)(bg_bobAmplitudeProne + 8);
  } else {
    v67 = (__m128)LODWORD(v125);
    if (v66 == 40)
      v67.f32[0] = v125 * *(float *)(bg_bobAmplitudeDucked + 8);
    else
      v67.f32[0] = v125 * *(float *)(bg_bobAmplitudeStanding + 8);
  }
  v68 = _mm_cmplt_ss((__m128)0x41200000u, v67);
  v123 = sinf(v126);
  v69 = -(float)(COERCE_FLOAT(_mm_andnot_ps(v68, v67).u32[0] |
                              v68.i32[0] & 0x41200000) *
                 v123);
  v70 = (__m128)LODWORD(v125);
  v70.f32[0] = v125 * 1.5;
  v71 = *(_DWORD *)(v54 + 244);
  if (v71 == 11) {
    v72 = v70;
    v72.f32[0] = v70.f32[0] * *(float *)(bg_bobAmplitudeProne + 8);
  } else {
    v72 = v70;
    if (v71 == 40)
      v72.f32[0] = v70.f32[0] * *(float *)(bg_bobAmplitudeDucked + 8);
    else
      v72.f32[0] = v70.f32[0] * *(float *)(bg_bobAmplitudeStanding + 8);
  }
  v73 = _mm_cmplt_ss((__m128)0x41200000u, v72);
  v113 = v126 - 0.4712389167638204;
  LODWORD(v120) = _mm_andnot_ps(v73, v72).u32[0] | v73.i32[0] & 0x41200000;
  v117 = sinf(v113);
  v74 = 0;
  v74.f32[0] = 0.0 - (float)(v117 * v120);
  v75 = _mm_cmpge_ss(v74, (__m128)0LL);
  LODWORD(v76) = _mm_andnot_ps(v75, (__m128)0LL).u32[0] |
                 COERCE_UNSIGNED_INT(v117 * v120) & v75.i32[0];
  v77 = *(float *)(v54 + 220);
  if (v77 != 0.0) {
    v78 = 1.0 - (float)((float)(1.0 - *(float *)(v60 + 644)) * v77);
    v131 = v131 * v78;
    v69 = v69 * v78;
    v76 = v76 * v78;
  }
  if (*(_DWORD *)(v60 + 632)) {
    v69 = v69 * (float)(1.0 - v77);
    v76 = v76 * (float)(1.0 - v77);
    v79 = v131 * (float)(1.0 - v77);
  } else {
    v79 = v131;
  }
  *a2 = v79 + *a2;
  *v122 = v69 + a2[1];
  *v121 = v76 + a2[2];
  v80 = a1;
  damageTime = a1->damageTime;
  if (damageTime) {
    v82 = a1->ps;
    v83 = *(_DWORD *)(a1->ps + 12);
    if ((v83 & 0x20000) != 0) {
      if (bg_iNumWeapons <= 0)
        goto LABEL_105;
      if (*(_DWORD *)(dword_1007FA4 + 120) == 3) {
        v84 = 1;
      } else {
        v109 = 1;
        v110 = bg_weaponDefs;
        while (bg_iNumWeapons >= ++v109) {
          v111 = v110[2];
          ++v110;
          if (*(_DWORD *)(v111 + 120) == 3) {
            v84 = (unsigned __int8)v109;
            goto LABEL_106;
          }
        }
      LABEL_105:
        v84 = 0;
      }
    } else if ((v83 & 0x10) != 0) {
      v84 = *(_DWORD *)(v82 + 208);
    } else {
      v84 = *(_DWORD *)(v82 + 212);
    }
  LABEL_106:
    v85 = bg_weaponDefs[v84];
    v86 = *(float *)(v82 + 220);
    v87 = (float)(v86 * 0.5) + 0.5;
    v88 = v87 * 100.0;
    v89 = v87 * 400.0;
    if (v86 != 0.0 && *(_DWORD *)(v85 + 632))
      v87 = v87 * (float)((float)(v86 * -0.75) + 1.0);
    v90 = (float)(int)(a1->time - damageTime);
    if (v88 > v90) {
      v119 = GetLeanFraction(v90 / v88);
      *a2 = (float)((float)((float)(v119 * v87) * *(float *)&a1->v_dmg_pitch) *
                    0.5) +
            *a2;
      *v122 = *v122 - (float)((float)(v119 * v87) * *(float *)&a1->v_dmg_roll);
      *v121 = (float)((float)((float)(v119 * v87) * *(float *)&a1->v_dmg_roll) *
                      0.5) +
              *v121;
      v82 = a1->ps;
    } else {
      v91 = 1.0 - (float)((float)(v90 - v88) / v89);
      if (v91 > 0.0) {
        v127 = GetLeanFraction(1.0 - v91);
        v92 = (float)(1.0 - v127) * v87;
        v80 = a1;
        *a2 = (float)((float)(v92 * *(float *)&a1->v_dmg_pitch) * 0.5) + *a2;
        *v122 = *v122 - (float)(v92 * *(float *)&a1->v_dmg_roll);
        *v121 = (float)((float)(v92 * *(float *)&a1->v_dmg_roll) * 0.5) + *v121;
        goto LABEL_112;
      }
    }
  } else {
  LABEL_112:
    v82 = v80->ps;
  }
  v93 = *(_DWORD *)(v82 + 12);
  if ((v93 & 0x20000) != 0) {
    if (bg_iNumWeapons > 0) {
      if (*(_DWORD *)(dword_1007FA4 + 120) == 3) {
        v94 = 1;
        goto LABEL_116;
      }
      v105 = 1;
      v106 = bg_weaponDefs;
      while (bg_iNumWeapons >= ++v105) {
        v107 = v106[2];
        ++v106;
        if (*(_DWORD *)(v107 + 120) == 3) {
          v94 = (unsigned __int8)v105;
          goto LABEL_116;
        }
      }
    }
    v94 = 0;
    goto LABEL_116;
  }
  if ((v93 & 0x10) != 0)
    v94 = *(_DWORD *)(v82 + 208);
  else
    v94 = *(_DWORD *)(v82 + 212);
LABEL_116:
  v95 = bg_weaponDefs[v94];
  if (*(_DWORD *)(v95 + 812)) {
    v96 = *(float *)(v82 + 220);
    v129 =
        *(float *)(v95 + 1240) +
        (float)((float)(*(float *)(v95 + 1168) - *(float *)(v95 + 1240)) * v96);
    v97 = (float)((float)(*(float *)(v95 + 1172) - *(float *)(v95 + 1244)) *
                  v96) +
          *(float *)(v95 + 1244);
    v98 = (float)((float)(*(float *)(v95 + 1176) - *(float *)(v95 + 1248)) *
                  v96) +
          *(float *)(v95 + 1248);
    v99 = (float)((float)(*(float *)(v95 + 1180) - *(float *)(v95 + 1252)) *
                  v96) +
          *(float *)(v95 + 1252);
    v100 = *(float *)&a1->frametime;
    if (v100 <= 0.0) {
      vGunOffset = a1->vGunOffset;
      v104 = a1;
    } else {
      vGunOffset = a1->vGunOffset;
      while (1) {
        if (v100 > 0.005) {
          v102 = v100 - 0.005;
          v128 = v102;
          v100 = 0.0049999999;
        } else {
          v128 = 0.0;
        }
        v103 = BG_CalculateWeaponPosition_GunRecoil_SingleAngle(
            vGunOffset, a1->vGunSpeed, v100, *(float *)(v95 + 736),
            (__m128)LODWORD(v129), v97, (float *)LODWORD(v98),
            (float *)LODWORD(v99));
        if (BG_CalculateWeaponPosition_GunRecoil_SingleAngle(
                &a1->vGunOffset[1], &a1->vGunSpeed[1], v100,
                *(float *)(v95 + 740), (__m128)LODWORD(v129), v97,
                (float *)LODWORD(v98), (float *)LODWORD(v99))) {
          if (v103)
            break;
        }
        if (v128 <= 0.0)
          break;
        v100 = v128;
      }
      v104 = a1;
    }
    *a2 = *a2 + v104->vGunOffset[0];
    *v122 = *v122 + vGunOffset[1];
    *v121 = *v121 + vGunOffset[2];
  }
  *a2 = AngleSubtract(*a2, a1->swayAngles[0]);
  *v122 = AngleSubtract(*v122, a1->swayAngles[1]);
}

struct WeaponDef *__cdecl BG_LoadDefaultWeaponDef(void) {
  UNIMPLEMENTED();
}

struct WeaponDef *__cdecl BG_LoadWeaponDef(char const *, char const *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon(struct pmove_t *pm, struct pml_t *pml) {
  UNIMPLEMENTED();
}

void __cdecl BG_FillInAllWeaponItems(void) { UNIMPLEMENTED(); }

int __cdecl BG_GetWeaponIndexForName(char const * name, void  regWeap)(int))
{
  UNIMPLEMENTED();
}

int __cdecl CG_GetWeaponIndexForName(char const *) { UNIMPLEMENTED(); }

void __cdecl CG_SetWeaponDefToDefaultWeapon(int iWeapon) {
  int WeaponIndexForName; // ebx
  int i;                  // ecx
  int result;             // eax
  char v4;                // [esp+8h] [ebp-10h]

  WeaponIndexForName = BG_GetWeaponIndexForName("defaultweapon_mp", 0);
  if (!WeaponIndexForName)
    Com_Error(1,
              "\x15CG_SetWeaponDefToDefaultWeapon: weapon def for default "
              "weapon could not be found!",
              v4);
  *(_DWORD *)(bg_weaponDefs[a1] + 12) =
      *(_DWORD *)(bg_weaponDefs[WeaponIndexForName] + 12);
  *(_DWORD *)(bg_weaponDefs[a1] + 16) =
      *(_DWORD *)(bg_weaponDefs[WeaponIndexForName] + 16);
  for (i = 0; i != 23; ++i) {
    result = bg_weaponDefs[a1];
    *(_DWORD *)(result + 4 * i + 20) =
        *(_DWORD *)(bg_weaponDefs[WeaponIndexForName] + 4 * i + 20);
  }
  return result;
}

void __cdecl BG_FillInAmmoItems(void(__cdecl *)(int)) { UNIMPLEMENTED(); }

void __cdecl BG_ClearWeaponDef() { UNIMPLEMENTED(); }

struct WeaponDef **bg_weaponDefs;
int marker_bg_weapons;
int bg_iNumWeapons;
void __cdecl Binocular_State_Hold(struct playerState_s *) { UNIMPLEMENTED(); }

int __cdecl PM_Weapon_GetAmmoRequired(int) { UNIMPLEMENTED(); }

void __cdecl PM_EndHoldBreath(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_StartHoldBreath(struct playerState_s *) { UNIMPLEMENTED(); }

bool __cdecl PM_IsBinocularADSAllowed(int) { UNIMPLEMENTED(); }

int __cdecl BG_GetBinocularWeaponIndex(void) { UNIMPLEMENTED(); }

void __cdecl BG_FillInWeaponItems(int) { UNIMPLEMENTED(); }

void __cdecl Binocular_State_Init(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_OffHandEnd(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_OffHandHold(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_OffHandPrepare(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_AddFiringAimSpreadScale(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishReloadEnd(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishWeaponRaise(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_ContinueWeaponAnim(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateView_IdleAngles(struct viewState_t *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateWeaponPosition_IdleAngles(struct weaponState_t *,
                                                   float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateWeaponPosition_BasePosition_angles(
    struct weaponState_t *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl Binocular_State_Drop(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_ExitBinoculars(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_EnterBinoculars(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_SendEmtpyOffhandEvent(struct playerState_s *,
                                      enum OffhandClass) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishMelee(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_FireMelee(struct playerState_s *) { UNIMPLEMENTED(); }

int __cdecl PM_Weapon_FinishFiring(struct pmove_t *, int) { UNIMPLEMENTED(); }

void __cdecl PM_SwitchIfEmpty(struct playerState_s *) { UNIMPLEMENTED(); }

int __cdecl PM_Weapon_AllowReload(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_SetWeaponReloadAddAmmoDelay(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishRechamber(struct playerState_s *) {
  UNIMPLEMENTED();
}

int __cdecl PM_WeaponClipEmpty(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_WeaponUseAmmo(struct playerState_s *, int, int) {
  UNIMPLEMENTED();
}

void __cdecl PM_ReloadClip(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_HoldBreathFire(struct playerState_s *) { UNIMPLEMENTED(); }

bool __cdecl PM_IsAdsAllowed(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateView_Velocity(struct viewState_t *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateView_BobAngles(struct viewState_t *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateView_DamageKick(struct viewState_t *, float *const) {
  UNIMPLEMENTED();
}

int __cdecl BG_CalculateWeaponPosition_GunRecoil_SingleAngle(float *, float *,
                                                             float, float,
                                                             float, float,
                                                             float, float) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateWeaponPosition_DamageKick(struct weaponState_t *,
                                                   float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateWeaponPosition_BobOffset(struct weaponState_t *,
                                                  float *const) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateWeaponPosition_BaseAngles(struct weaponState_t *,
                                                   float *const) {
  UNIMPLEMENTED();
}

void __cdecl Binocular_State_End(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl Binocular_State_Raise(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl Binocular_State_Exit_ADS(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_ExitBinocularsQuick(struct playerState_s *) { UNIMPLEMENTED(); }

bool __cdecl PM_UpdateGrenadeThrow(struct playerState_s *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_OffHand(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_OffHandInit(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_Idle(struct playerState_s *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_CheckForMelee(struct pmove_t *, int) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_SetFPSFireAnim(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_StartFiring(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

int __cdecl PM_Weapon_WeaponTimeAdjust(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_ReloadDelayedAction(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishWeaponChange(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl PM_BeginWeaponChange(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl PM_SetReloadingState(struct playerState_s *) { UNIMPLEMENTED(); }

int __cdecl PM_Weapon_CheckForRechamber(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl PM_UpdateHoldBreath(struct pmove_t *, struct pml_t *) {
  UNIMPLEMENTED();
}

void __cdecl BG_CalculateWeaponPosition_GunRecoil(struct weaponState_t *,
                                                  float *const) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_CheckForBinoculars(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_CheckForChangeWeapon(struct pmove_t *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishReload(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_FinishReloadStart(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl PM_BeginWeaponReload(struct playerState_s *) { UNIMPLEMENTED(); }

int __cdecl PM_Weapon_CheckFiringAmmo(struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_CheckForReload(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl PM_Weapon_FireWeapon(struct playerState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl PM_Weapon_CheckForOffHand(struct pmove_t *) { UNIMPLEMENTED(); }

void __cdecl BG_SetupWeaponAlts(int, void(__cdecl *)(int)) { UNIMPLEMENTED(); }

void __cdecl BG_SetupClipIndexes(int) { UNIMPLEMENTED(); }

void __cdecl BG_SetupSharedAmmoIndexes(int) { UNIMPLEMENTED(); }

void __cdecl BG_SetupAmmoIndexes(int) { UNIMPLEMENTED(); }

void __cdecl BG_SetupWeaponIndex(int) { UNIMPLEMENTED(); }

int __cdecl BG_SetupWeaponDef(struct WeaponDef *, void(__cdecl *)(int)) {
  UNIMPLEMENTED();
}
