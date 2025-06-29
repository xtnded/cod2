float __cdecl CG_CalcTracerFinalScale(float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_HoldBreathInit()
{
  UNIMPLEMENTED();
}

int __cdecl CG_WeaponDObjHandle(int weaponNum)
{
  return a1 + 1024;
}

void __cdecl CG_ScaleTracer(float *const, float *const, float *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_SelectWeaponIndex(int weaponIndex)
{
  _DWORD *v1; // eax
  int result; // eax
  _BOOL4 v3;  // esi

  v1 = cg;
  *((_DWORD *)cg + 44949) = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
  result = v1[44948];
    if (result != a1) {
      v3 = a1 && a1 == *(_DWORD *)(BG_GetWeaponDef(result) + 876);
      *((_DWORD *)cg + 44948) = a1;
      CG_MenuShowNotify((windowDef_t *)1);
      result = v3;
      if (!v3)
        return CL_SetADS(0);
    }
  return result;
}

void __cdecl CG_DrawTracer(float *const start, float *const finish)
{
  float v2;  // xmm2_4
  float v3;  // xmm4_4
  float v4;  // xmm3_4
  float v5;  // xmm1_4
  float v6;  // xmm2_4
  float v7;  // xmm1_4
  float *v9; // ebx
  float v10; // [esp+174h] [ebp-24h] BYREF
  float v11; // [esp+178h] [ebp-20h]
  float v12; // [esp+17Ch] [ebp-1Ch]

  v2 = *a2 - *a1;
  v3 = a2[1] - a1[1];
  v4 = a2[2] - a1[2];
  v5 = (float)((float)(v2 * *((float *)cg + 41320)) +
               (float)(v3 * *((float *)cg + 41321))) +
       (float)(v4 * *((float *)cg + 41322));
  v6 = (float)((float)(v2 * *((float *)cg + 41323)) +
               (float)(v3 * *((float *)cg + 41324))) +
       (float)(v4 * *(float *)((char *)&loc_285B4 + (_DWORD)cg));
  v10 = v6 * *((float *)cg + 41320);
  v11 = v6 * *((float *)cg + 41321);
  v12 = v6 * *((float *)cg + 41322);
  v7 = -v5;
  v10 = (float)(v7 * *((float *)cg + 41323)) + v10;
  v11 = (float)(v7 * *((float *)cg + 41324)) + v11;
  v12 = (float)(v7 * *(float *)((char *)&loc_285B4 + (_DWORD)cg)) + v12;
  Vec3Normalize(&v10);
    if (*(float *)(cg_tracerScale + 8) != 1.0) {
      v9 = (float *)((char *)cg + 165256);
      Vec3Distance(a1, (float *)cg + 41314);
      Vec3Distance(a2, v9);
    }
  CL_DefaultVertexFrames();
  return CL_AddPolyToScene(*((Material **)cgs + 11919), 0x1Fu, 4u);
}

int __cdecl CG_SelectFirstWeaponNotInSlot(int bNext, int bIgnoreEmpty)
{
  int v2;         // ebx
  int NumWeapons; // eax
  int v4;         // esi
  _DWORD *v5;     // edi
  int v6;         // ebx

    if (a1) {
      v2 = 1;
      NumWeapons = 1;
    }
    else {
      NumWeapons = BG_GetNumWeapons();
      if (NumWeapons <= 0)
        return 0;
      v2 = -1;
    }
  v4 = NumWeapons;
    while (BG_GetNumWeapons() >= v4) {
        if (((*((int *)cg + (v4 >> 5) + 38978) >> (v4 & 0x1F)) & 1) != 0 &&
            !BG_IsPlayerWeaponInSlot(
                (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg), v4,
                1) &&
            BG_GetStackSlotForWeapon(
                (const playerState_s *)((char *)cg + 154564), v4,
                WEAPSLOT_NONE) == WEAPSLOT_NONE &&
            BG_DoesWeaponNeedSlot(v4) &&
            (!a2 ||
             BG_WeaponAmmo((const playerState_s *)((char *)cg + 154564), v4))) {
          v5 = cg;
          *((_DWORD *)cg + 44949) =
              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
          if (v5[44948] == v4)
            return 1;
          v6 = *(_DWORD *)(BG_GetWeaponDef(v5[44948]) + 876);
          v5[44948] = v4;
          CG_MenuShowNotify((windowDef_t *)1);
          if (v6 == v4)
            return 1;
          CL_SetADS(0);
          return 1;
        }
      v4 += v2;
      if (v4 <= 0)
        return 0;
    }
  return 0;
}

int __cdecl CG_SelectFirstWeaponInSlot(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_WeaponSlot_f()
{
  int *v0;               // esi
  int result;            // eax
  char *v2;              // eax
  int WeaponSlotForName; // edx
  int v4;                // edi
  int v5;                // ebx
  char *v6;              // eax

  v0 = (int *)cg;
  result = *((_DWORD *)cg + 9);
    if (result) {
        if (*((__int16 *)cg + 77288) >= 0 && *(char *)(result + 26) < 0) {
          result = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) -
                   *((_DWORD *)cg + 44949);
            if (result >= *(_DWORD *)(cg_weaponCycleDelay + 8)) {
              *((_DWORD *)cg + 44949) =
                  *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
              v2 = CG_Argv(1);
              WeaponSlotForName = BG_GetWeaponSlotForName(v2);
                if (!WeaponSlotForName) {
                  v6 = CG_Argv(1);
                  WeaponSlotForName = atoi(v6);
                }
              result = WeaponSlotForName - 1;
                if ((unsigned int)(WeaponSlotForName - 1) <= 1) {
                  result =
                      *((unsigned __int8 *)v0 + WeaponSlotForName + 155928);
                  v4 = (char)result;
                    if ((_BYTE)result) {
                      result =
                          v0[((char)result >> 5) + 38978] >> (result & 0x1F);
                        if ((result & 1) != 0) {
                          v0[44949] =
                              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v0);
                          result = v0[44948];
                            if (v4 != result) {
                              v5 =
                                  *(_DWORD *)(BG_GetWeaponDef(v0[44948]) + 876);
                              v0[44948] = v4;
                              result = (int)CG_MenuShowNotify((windowDef_t *)1);
                              if (v4 != v5)
                                return CL_SetADS(0);
                            }
                        }
                    }
                }
            }
        }
    }
  return result;
}

void __cdecl CG_CycleWeap(int bNext, int bIgnoreEmpty)
{
  windowDef_t *result;          // eax
  int v3;                       // edi
  _DWORD *v4;                   // ebx
  __int32 IsPlayerWeaponInSlot; // eax
  int v6;                       // ebx
  unsigned int v7;              // eax
  char v8;                      // al
  _BYTE *v9;                    // eax
  char v10;                     // cl
  int v11;                      // ebx
  _BOOL4 v12;                   // edi
  int v13;                      // ebx
  _BYTE *v14;                   // esi
  const playerState_s *v15;     // edi
  char v16;                     // al
  _DWORD *v17;                  // eax
  char v18;                     // cl
  int v19;                      // ebx
  bool v20;                     // di
  int v21;                      // ebx
  char v22;                     // al
  _DWORD *v23;                  // edx
  int v24;                      // esi
  int v25;                      // ebx
  _DWORD *v26;                  // ebx
  bool v27;                     // bl
  _DWORD *v28;                  // eax
  char v29;                     // cl
  int v30;                      // ebx
  int v31;                      // eax
  bool v32;                     // di
  int v33;                      // [esp+20h] [ebp-28h]
  int NumWeapons;               // [esp+24h] [ebp-24h]
  int v35;                      // [esp+28h] [ebp-20h]
  int v36;                      // [esp+2Ch] [ebp-1Ch]

  result = (windowDef_t *)*((_DWORD *)cg + 9);
  if (!result || (result->rect[26] & 0x80u) == 0)
    return result;
    if (a1) {
      v33 = 1;
      v3 = 1;
      NumWeapons = 1;
    }
    else {
      NumWeapons = BG_GetNumWeapons();
      v33 = -1;
      v3 = 2;
    }
  v4 = cg;
  IsPlayerWeaponInSlot = BG_IsPlayerWeaponInSlot(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg),
      *((_DWORD *)cg + 44948), 1);
    if (!IsPlayerWeaponInSlot) {
      IsPlayerWeaponInSlot = BG_GetStackSlotForWeapon(
          (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v4), v4[44948],
          WEAPSLOT_NONE);
        if (!IsPlayerWeaponInSlot) {
          v24 = *((_DWORD *)cg + 44948);
            while (1) {
              v25 = BG_GetNumWeapons();
              v24 = (v24 + v33 + v25 - 1) % BG_GetNumWeapons() + 1;
              if (NumWeapons == v24)
                break;
              v26 = cg;
                if (((*((int *)cg + (v24 >> 5) + 38978) >> (v24 & 0x1F)) & 1) !=
                        0 &&
                    !BG_IsPlayerWeaponAnAlt(v24, *((_DWORD *)cg + 44948)) &&
                    !BG_IsPlayerWeaponInSlot(
                        (const playerState_s *)((char *)&loc_25BC4 +
                                                (_DWORD)v26),
                        v24, 1) &&
                    BG_GetStackSlotForWeapon(
                        (const playerState_s *)((char *)&loc_25BC4 +
                                                (_DWORD)v26),
                        v24, WEAPSLOT_NONE) == WEAPSLOT_NONE &&
                    (!a2 ||
                     BG_WeaponAmmo((const playerState_s *)((char *)&loc_25BC4 +
                                                           (_DWORD)v26),
                                   v24)) &&
                    BG_DoesWeaponNeedSlot(v24)) {
                  v26[44949] = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v26);
                  result = (windowDef_t *)v26[44948];
                  if ((windowDef_t *)v24 == result)
                    return result;
                  v27 = v24 &&
                        v24 == *(_DWORD *)(BG_GetWeaponDef(v26[44948]) + 876);
                  *((_DWORD *)cg + 44948) = v24;
                  result = CG_MenuShowNotify((windowDef_t *)1);
                  if (v27)
                    return result;
                  return (windowDef_t *)CL_SetADS(0);
                }
            }
            if (a1) {
              v36 = 1;
              v13 = 1;
            }
            else {
              v36 = -1;
              v13 = 2;
            }
            if (a2) {
              v14 = cg;
              v15 = (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg);
                while (1) {
                  v16 = v14[v13 + 155928];
                    if (v16) {
                      if (BG_WeaponAmmo(v15, v16))
                        break;
                    }
                  v13 += v36;
                  if ((unsigned int)(v13 - 1) > 1)
                    goto LABEL_66;
                }
            }
            else {
                while (!*((_BYTE *)cg + v13 + 155928)) {
                  v13 += v36;
                    if ((unsigned int)(v13 - 1) > 1) {
                    LABEL_66:
                      CG_SelectFirstWeaponNotInSlot(a1, a2);
                      goto LABEL_41;
                    }
                }
            }
          v17 = cg;
          v18 = *((_BYTE *)cg + v13 + 155928);
          v19 = v18;
          *((_DWORD *)cg + 44949) =
              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
          result = (windowDef_t *)v17[44948];
            if ((windowDef_t *)v18 != result) {
              v20 =
                  v18 && v18 == *(_DWORD *)(BG_GetWeaponDef((int)result) + 876);
              *((_DWORD *)cg + 44948) = v19;
              result = CG_MenuShowNotify((windowDef_t *)1);
              if (!v20)
                return (windowDef_t *)CL_SetADS(0);
            }
          return result;
        }
    }
    if (a2) {
      v6 = IsPlayerWeaponInSlot;
        do {
          v7 = (v33 + v6 + 1) & 0x80000001;
            if (v33 + v6 + 1 < 0) {
              v6 = (((_BYTE)v7 - 1) | 0xFFFFFFFE) + 2;
              if (v3 == v6)
                goto LABEL_32;
            }
            else {
              v6 = v7 + 1;
              if (v3 == v7 + 1)
                goto LABEL_32;
            }
          v8 = *((_BYTE *)cg + v6 + 155928);
        }
      while (!v8 ||
             !BG_WeaponAmmo(
                 (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg), v8));
      v9 = cg;
    LABEL_13:
      v10 = v9[v6 + 155928];
      v11 = v10;
      *((_DWORD *)v9 + 44949) = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v9);
      result = (windowDef_t *)*((_DWORD *)v9 + 44948);
        if ((windowDef_t *)v10 != result) {
          v12 = v10 && v10 == *(_DWORD *)(BG_GetWeaponDef((int)result) + 876);
          *((_DWORD *)cg + 44948) = v11;
          CG_MenuShowNotify((windowDef_t *)1);
          result = (windowDef_t *)v12;
          if (!v12)
            return (windowDef_t *)CL_SetADS(0);
        }
    }
    else {
      v6 = IsPlayerWeaponInSlot;
        while (1) {
          v6 = (v33 + v6 + 1) % 2 + 1;
          if (v3 == v6)
            break;
          v9 = cg;
          if (*((_BYTE *)cg + v6 + 155928))
            goto LABEL_13;
        }
    LABEL_32:
      result = (windowDef_t *)CG_SelectFirstWeaponNotInSlot(a1, a2);
        if (!result) {
            if (a1) {
              v35 = 1;
              v21 = 1;
            }
            else {
              v35 = -1;
              v21 = 2;
            }
            if (a2) {
                while (1) {
                    while (1) {
                      v22 = *((_BYTE *)cg + v21 + 155928);
                      if (v22)
                        break;
                      v21 += v35;
                      if ((unsigned int)(v21 - 1) > 1)
                        goto LABEL_41;
                    }
                  if (BG_WeaponAmmo((const playerState_s *)((char *)&loc_25BC4 +
                                                            (_DWORD)cg),
                                    v22))
                    break;
                  v21 += v35;
                  if ((unsigned int)(v21 - 1) > 1)
                    goto LABEL_41;
                }
            }
            else {
                while (!*((_BYTE *)cg + v21 + 155928)) {
                  v21 += v35;
                  if ((unsigned int)(v21 - 1) > 1)
                    goto LABEL_41;
                }
            }
          v28 = cg;
          v29 = *((_BYTE *)cg + v21 + 155928);
          v30 = v29;
          *((_DWORD *)cg + 44949) =
              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
          v31 = v28[44948];
            if (v29 != v31) {
              v32 = v29 && v29 == *(_DWORD *)(BG_GetWeaponDef(v31) + 876);
              *((_DWORD *)cg + 44948) = v30;
              CG_MenuShowNotify((windowDef_t *)1);
              if (!v32)
                CL_SetADS(0);
            }
        LABEL_41:
          v23 = cg;
          result = (windowDef_t *)(*((int *)cg + (*((int *)cg + 44948) >> 5) +
                                     38978) >>
                                   (*((_BYTE *)cg + 179792) & 0x1F));
            if (((unsigned __int8)result & 1) == 0) {
              *((_DWORD *)cg + 44949) =
                  *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
              result = (windowDef_t *)v23[44948];
                if (result) {
                  v23[44948] = 0;
                  CG_MenuShowNotify((windowDef_t *)1);
                  return (windowDef_t *)CL_SetADS(0);
                }
            }
        }
    }
  return result;
}

void __cdecl CG_OutOfAmmoChange()
{
  UNIMPLEMENTED();
}

void __cdecl CG_PrevWeapon_f()
{
  UNIMPLEMENTED();
}

void __cdecl CG_NextWeapon_f()
{
  UNIMPLEMENTED();
}

void __cdecl CG_SpawnTracer(float *const pstart, float *const pend)
{
  float v2;   // xmm1_4
  float v3;   // xmm2_4
  int *v4;    // esi
  _DWORD *v5; // ebx
  int v6;     // edi
  int v7;     // eax
  int result; // eax
  float v9;   // xmm0_4
  float v10;  // [esp+10h] [ebp-38h]
  float v11;  // [esp+14h] [ebp-34h]
  float v12;  // [esp+18h] [ebp-30h]
  int v13;    // [esp+1Ch] [ebp-2Ch]
  float v14;  // [esp+24h] [ebp-24h] BYREF
  float v15;  // [esp+28h] [ebp-20h]
  float v16;  // [esp+2Ch] [ebp-1Ch]

  v13 = *(_DWORD *)a1;
  v12 = a1[1];
  v11 = a1[2];
  v2 = a2[1];
  v3 = a2[2];
  v14 = *a2 - *a1;
  v15 = v2 - v12;
  v16 = v3 - v11;
  v10 = Vec3Normalize(&v14);
  v4 = CG_AllocLocalEntity();
  v4[2] = 0;
  *((float *)v4 + 17) = v10;
  v5 = cg;
  v6 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
  if (*((_DWORD *)cg + 38635))
    v7 = rand() % v5[38635] / 2;
  else
    v7 = 0;
  v4[3] = v6 - v7 +
          (int)(float)((float)(v10 * 1000.0) / *(float *)(cg_tracerSpeed + 8));
  v4[4] = 2;
  v4[5] = v6 - v7;
  v4[7] = v13;
  *((float *)v4 + 8) = v12;
  *((float *)v4 + 9) = v11;
  result = cg_tracerSpeed;
  v9 = *(float *)(cg_tracerSpeed + 8);
  *((float *)v4 + 10) = v9 * v14;
  *((float *)v4 + 11) = v9 * v15;
  *((float *)v4 + 12) = v9 * v16;
  return result;
}

void __cdecl CG_SetupWeaponDef()
{
  char *ConfigString; // eax
  int v1;             // edi
  char *v2;           // edx
  int result;         // eax
  int v4;             // ebx
  char *v5;           // esi
  char __dst[8192];   // [esp+14h] [ebp-2214h] BYREF
  _DWORD __b[133];    // [esp+2014h] [ebp-214h] BYREF

  memset(__b, 0, 0x1FCu);
  ConfigString = CL_GetConfigString(7);
  strcpy(__dst, ConfigString);
  __b[0] = __dst;
  v1 = 1;
  v2 = __dst;
  result = (unsigned __int8)__dst[0];
    while ((_BYTE)result) {
        if ((_BYTE)result == 32) {
          *v2++ = 0;
          result = (unsigned __int8)*v2;
          if (!(_BYTE)result)
            break;
            if ((_BYTE)result != 32) {
              __b[v1++] = v2;
              result = (unsigned __int8)*v2;
            }
        }
        else {
          result = (unsigned __int8)*++v2;
        }
    }
    if (v1 > 0) {
      v4 = 0;
        do {
          v5 = (char *)__b[v4];
          result = BG_GetWeaponIndexForName(v5, 0);
          if (result != ++v4)
            result = Com_Error(1, "Weapon index mismatch for '%s'", (char)v5);
        }
      while (v4 != v1);
    }
  return result;
}

void __cdecl CG_AltWeapon_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_Weapons_SetToDefault(int weaponNum,
                                     struct DObjModel_s *dobjModels)
{
  int WeaponDef;  // esi
  _BYTE *v3;      // eax
  const char *v4; // eax
  int result;     // eax
  char v6;        // [esp+8h] [ebp-60h]
  char v7[88];    // [esp+10h] [ebp-58h] BYREF

  CG_SetWeaponDefToDefaultWeapon(a1);
  WeaponDef = BG_GetWeaponDef(a1);
  Com_Printf("WARNING: gun and/or hand model file for weapon [%s] could not be "
             "found, switching to default weapon.\n",
             *(const char **)(WeaponDef + 4));
  v3 = *(_BYTE **)(WeaponDef + 12);
    if (!v3 || !*v3 || (v4 = *(const char **)(WeaponDef + 16)) == 0 || !*v4) {
      Com_Error(1,
                "\x15CG_RegisterWeapon: No gun and/or hand model specified for "
                "default weapon!",
                v6);
      v4 = *(const char **)(WeaponDef + 16);
    }
  sprintf(v7, "%s%s", "xmodel/", v4);
  *(_DWORD *)a2->model = CL_RegisterModel();
  sprintf(v7, "%s%s", "xmodel/", *(const char **)(WeaponDef + 12));
  result = CL_RegisterModel();
  *(_DWORD *)a2[1].model = result;
  return result;
}

void __cdecl CG_WeaponRunXModelAnims(struct playerState_s *ps,
                                     struct weaponInfo_s *weapInfo)
{
  int32_t ViewmodelWeaponIndex; // ebx
  int WeaponDef;                // ecx
  playerState_s *v4;            // edx
  uint32_t pm_flags;            // eax
  int v6;                       // edx
  weaponInfo_s *result;         // eax
  char *v8;                     // edi
  char *v9;                     // ebx
  int v10;                      // esi
  int32_t weapAnim;             // eax
  unsigned int v12;             // esi
  char *v13;                    // edi
  char *v14;                    // ebx
  int i9;                       // esi
  char *v16;                    // edi
  char *v17;                    // ebx
  int i8;                       // esi
  char *v19;                    // edi
  char *v20;                    // ebx
  int i7;                       // esi
  char *v22;                    // edi
  char *v23;                    // ebx
  int i6;                       // esi
  char *v25;                    // edi
  char *v26;                    // ebx
  int i5;                       // esi
  char *v28;                    // edi
  char *v29;                    // ebx
  int i4;                       // esi
  char *v31;                    // edi
  char *v32;                    // ebx
  int i3;                       // esi
  char *v34;                    // edi
  char *v35;                    // ebx
  int i2;                       // esi
  char *v37;                    // edi
  char *v38;                    // ebx
  int i1;                       // esi
  char *v40;                    // edi
  char *v41;                    // ebx
  int nn;                       // esi
  char *v43;                    // edi
  char *v44;                    // ebx
  int mm;                       // esi
  char *v46;                    // edi
  char *v47;                    // ebx
  int kk;                       // esi
  char *v49;                    // edi
  char *v50;                    // ebx
  int jj;                       // esi
  char *v52;                    // edi
  char *v53;                    // ebx
  int ii;                       // esi
  char *v55;                    // edi
  char *v56;                    // ebx
  int n;                        // esi
  char *v58;                    // edi
  char *v59;                    // ebx
  int m;                        // esi
  char *v61;                    // edi
  char *v62;                    // ebx
  int k;                        // esi
  char *v64;                    // edi
  char *v65;                    // ebx
  int j;                        // esi
  char *v67;                    // edi
  char *v68;                    // ebx
  char *v69;                    // edi
  char *v70;                    // ebx
  int i;                        // esi
  XAnimTree_s *Tree;            // [esp+2Ch] [ebp-1Ch]

  Tree = (XAnimTree_s *)DObjGetTree(*(const DObj_s **)a2->viewModelDObj);
  ViewmodelWeaponIndex = BG_GetViewmodelWeaponIndex(a1);
  WeaponDef = BG_GetWeaponDef(ViewmodelWeaponIndex);
  v4 = a1;
    if (a1->weaponstate == 5) {
        if ((signed int)(a1->weaponTime - *(_DWORD *)(WeaponDef + 1316)) > 0) {
          pm_flags = a1->pm_flags;
          goto LABEL_3;
        }
      v4 = a1;
    }
  pm_flags = v4->pm_flags;
    if ((pm_flags & 0x40) == 0) {
    LABEL_3:
      v6 = 0;
      goto LABEL_4;
    }
  v6 = 1;
LABEL_4:
  if ((pm_flags & 0x10) != 0)
    v6 = 0;
    if (*(_DWORD *)(WeaponDef + 812)) {
      if (v6)
        CG_PlayADSAnim(21, Tree);
      else
        CG_PlayADSAnim(22, Tree);
    }
  result = (weaponInfo_s *)a1->weapAnim;
    if (result != (weaponInfo_s *)a2->iPrevAnim) {
      BYTE1(result) &= ~2u;
        switch ((unsigned int)result) {
        case 0u:
          v12 = 1;
            while (XAnimHasFinished(Tree, v12)) {
                if (++v12 == 21) {
                    if (*(_DWORD *)&a1
                             ->ammoclip[4 * BG_ClipForWeapon(
                                                ViewmodelWeaponIndex)]) {
                      v69 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
                      v70 = v69;
                        for (i = 1; i != 21; ++i) {
                          if ((_WORD)i == 1)
                            XAnimSetGoalWeight(Tree, 1, 0x3F800000u, 0.0,
                                               *((_DWORD *)v69 + 2), 0, 1, 1);
                          else
                            XAnimSetGoalWeight(Tree, i, 0, 0.0,
                                               *((_DWORD *)v70 + 2), 0, 0, 0);
                          v70 += 4;
                        }
                    }
                    else {
                      v67 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
                      v68 = v67;
                      LOWORD(v12) = 1;
                        do {
                          if ((_WORD)v12 == 2)
                            XAnimSetGoalWeight(Tree, 2, 0x3F800000u, 0.0,
                                               *((_DWORD *)v67 + 3), 0, 1, 1);
                          else
                            XAnimSetGoalWeight(Tree, v12, 0, 0.0,
                                               *((_DWORD *)v68 + 2), 0, 0, 0);
                          v68 += 4;
                          ++v12;
                        }
                      while (v12 != 21);
                    }
                  goto LABEL_16;
                }
            }
          result = a2;
          a2->iPrevAnim = -1;
          return result;
        case 2u:
          v64 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v65 = v64;
            for (j = 1; j != 21; ++j) {
              if ((_WORD)j == 3)
                XAnimSetGoalWeight(Tree, 3, 0x3F800000u, 0.0,
                                   *((_DWORD *)v64 + 4), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, j, 0, 0.0, *((_DWORD *)v65 + 2), 0, 0,
                                   0);
              v65 += 4;
            }
          goto LABEL_16;
        case 3u:
          v61 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v62 = v61;
            for (k = 1; k != 21; ++k) {
              if ((_WORD)k == 5)
                XAnimSetGoalWeight(Tree, 5, 0x3F800000u, 0.0,
                                   *((_DWORD *)v61 + 6), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, k, 0, 0.0, *((_DWORD *)v62 + 2), 0, 0,
                                   0);
              v62 += 4;
            }
          goto LABEL_16;
        case 4u:
          v58 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v59 = v58;
            for (m = 1; m != 21; ++m) {
              if ((_WORD)m == 6)
                XAnimSetGoalWeight(Tree, 6, 0x3F800000u, 0.0,
                                   *((_DWORD *)v58 + 7), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, m, 0, 0.0, *((_DWORD *)v59 + 2), 0, 0,
                                   0);
              v59 += 4;
            }
          goto LABEL_16;
        case 5u:
          v55 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v56 = v55;
            for (n = 1; n != 21; ++n) {
              if ((_WORD)n == 18)
                XAnimSetGoalWeight(Tree, 18, 0x3F800000u, 0.0,
                                   *((_DWORD *)v55 + 19), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, n, 0, 0.0, *((_DWORD *)v56 + 2), 0, 0,
                                   0);
              v56 += 4;
            }
          goto LABEL_16;
        case 6u:
          v52 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v53 = v52;
            for (ii = 1; ii != 21; ++ii) {
              if ((_WORD)ii == 19)
                XAnimSetGoalWeight(Tree, 19, 0x3F800000u, 0.0,
                                   *((_DWORD *)v52 + 20), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, ii, 0, 0.0, *((_DWORD *)v53 + 2), 0, 0,
                                   0);
              v53 += 4;
            }
          goto LABEL_16;
        case 7u:
          v49 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v50 = v49;
            for (jj = 1; jj != 21; ++jj) {
              if ((_WORD)jj == 20)
                XAnimSetGoalWeight(Tree, 20, 0x3F800000u, 0.0,
                                   *((_DWORD *)v49 + 21), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, jj, 0, 0.0, *((_DWORD *)v50 + 2), 0, 0,
                                   0);
              v50 += 4;
            }
          goto LABEL_16;
        case 8u:
          v46 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v47 = v46;
            for (kk = 1; kk != 21; ++kk) {
              if ((_WORD)kk == 7)
                XAnimSetGoalWeight(Tree, 7, 0x3F800000u, 0.0,
                                   *((_DWORD *)v46 + 8), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, kk, 0, 0.0, *((_DWORD *)v47 + 2), 0, 0,
                                   0);
              v47 += 4;
            }
          goto LABEL_16;
        case 9u:
          v43 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v44 = v43;
            for (mm = 1; mm != 21; ++mm) {
              if ((_WORD)mm == 13)
                XAnimSetGoalWeight(Tree, 13, 0x3F800000u, 0.0,
                                   *((_DWORD *)v43 + 14), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, mm, 0, 0.0, *((_DWORD *)v44 + 2), 0, 0,
                                   0);
              v44 += 4;
            }
          goto LABEL_16;
        case 0xAu:
          v40 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v41 = v40;
            for (nn = 1; nn != 21; ++nn) {
              if ((_WORD)nn == 12)
                XAnimSetGoalWeight(Tree, 12, 0x3F800000u, 0.0,
                                   *((_DWORD *)v40 + 13), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, nn, 0, 0.0, *((_DWORD *)v41 + 2), 0, 0,
                                   0);
              v41 += 4;
            }
          goto LABEL_16;
        case 0xBu:
          v37 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v38 = v37;
            for (i1 = 1; i1 != 21; ++i1) {
              if ((_WORD)i1 == 8)
                XAnimSetGoalWeight(Tree, 8, 0x3F800000u, 0.0,
                                   *((_DWORD *)v37 + 9), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i1, 0, 0.0, *((_DWORD *)v38 + 2), 0, 0,
                                   0);
              v38 += 4;
            }
          goto LABEL_16;
        case 0xCu:
          v34 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v35 = v34;
            for (i2 = 1; i2 != 21; ++i2) {
              if ((_WORD)i2 == 9)
                XAnimSetGoalWeight(Tree, 9, 0x3F800000u, 0.0,
                                   *((_DWORD *)v34 + 10), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i2, 0, 0.0, *((_DWORD *)v35 + 2), 0, 0,
                                   0);
              v35 += 4;
            }
          goto LABEL_16;
        case 0xDu:
          v31 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v32 = v31;
            for (i3 = 1; i3 != 21; ++i3) {
              if ((_WORD)i3 == 10)
                XAnimSetGoalWeight(Tree, 10, 0x3F800000u, 0.0,
                                   *((_DWORD *)v31 + 11), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i3, 0, 0.0, *((_DWORD *)v32 + 2), 0, 0,
                                   0);
              v32 += 4;
            }
          goto LABEL_16;
        case 0xEu:
          v28 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v29 = v28;
            for (i4 = 1; i4 != 21; ++i4) {
              if ((_WORD)i4 == 11)
                XAnimSetGoalWeight(Tree, 11, 0x3F800000u, 0.0,
                                   *((_DWORD *)v28 + 12), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i4, 0, 0.0, *((_DWORD *)v29 + 2), 0, 0,
                                   0);
              v29 += 4;
            }
          goto LABEL_16;
        case 0xFu:
          v25 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v26 = v25;
            for (i5 = 1; i5 != 21; ++i5) {
              if ((_WORD)i5 == 15)
                XAnimSetGoalWeight(Tree, 15, 0x3F800000u, 0.0,
                                   *((_DWORD *)v25 + 16), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i5, 0, 0.0, *((_DWORD *)v26 + 2), 0, 0,
                                   0);
              v26 += 4;
            }
          goto LABEL_16;
        case 0x10u:
          v22 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v23 = v22;
            for (i6 = 1; i6 != 21; ++i6) {
              if ((_WORD)i6 == 14)
                XAnimSetGoalWeight(Tree, 14, 0x3F800000u, 0.0,
                                   *((_DWORD *)v22 + 15), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i6, 0, 0.0, *((_DWORD *)v23 + 2), 0, 0,
                                   0);
              v23 += 4;
            }
          goto LABEL_16;
        case 0x11u:
          v19 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v20 = v19;
            for (i7 = 1; i7 != 21; ++i7) {
              if ((_WORD)i7 == 17)
                XAnimSetGoalWeight(Tree, 17, 0x3F800000u, 0.0,
                                   *((_DWORD *)v19 + 18), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i7, 0, 0.0, *((_DWORD *)v20 + 2), 0, 0,
                                   0);
              v20 += 4;
            }
          goto LABEL_16;
        case 0x12u:
          v16 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v17 = v16;
            for (i8 = 1; i8 != 21; ++i8) {
              if ((_WORD)i8 == 16)
                XAnimSetGoalWeight(Tree, 16, 0x3F800000u, 0.0,
                                   *((_DWORD *)v16 + 17), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i8, 0, 0.0, *((_DWORD *)v17 + 2), 0, 0,
                                   0);
              v17 += 4;
            }
          goto LABEL_16;
        case 0x13u:
          v13 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v14 = v13;
            for (i9 = 1; i9 != 21; ++i9) {
              if ((_WORD)i9 == 4)
                XAnimSetGoalWeight(Tree, 4, 0x3F800000u, 0.0,
                                   *((_DWORD *)v13 + 5), 0, 1, 1);
              else
                XAnimSetGoalWeight(Tree, i9, 0, 0.0, *((_DWORD *)v14 + 2), 0, 0,
                                   0);
              v14 += 4;
            }
          goto LABEL_16;
        default:
          v8 = (char *)cg_weapons + 436 * ViewmodelWeaponIndex;
          v9 = v8;
          v10 = 1;
          break;
        }
        do {
            while ((_WORD)v10 != 1) {
              XAnimSetGoalWeight(Tree, v10, 0, 0.0, *((_DWORD *)v9 + 2), 0, 0,
                                 0);
              v9 += 4;
              if (++v10 == 21)
                goto LABEL_15;
            }
          XAnimSetGoalWeight(Tree, 1, 0x3F800000u, 0.0, *((_DWORD *)v8 + 2), 0,
                             1, 1);
          v9 += 4;
          ++v10;
        }
      while (v10 != 21);
    LABEL_15:
      weapAnim = a1->weapAnim;
      BYTE1(weapAnim) &= ~2u;
      Com_Printf("CG_WeaponRunXModelAnims: Unknown weapon animation %i\n",
                 weapAnim);
    LABEL_16:
      result = (weaponInfo_s *)a1->weapAnim;
      a2->iPrevAnim = (int32_t)result;
    }
  return result;
}

void __cdecl CG_WhizbySound(float *const vStart, float *const vEnd)
{
  void *result; // eax
  float v3;     // xmm1_4
  float v4;     // [esp+1Ch] [ebp-2Ch] BYREF
  float v5;     // [esp+20h] [ebp-28h]
  float v6;     // [esp+24h] [ebp-24h]
  float v7;     // [esp+28h] [ebp-20h] BYREF
  float v8;     // [esp+2Ch] [ebp-1Ch]
  float v9;     // [esp+30h] [ebp-18h]
  float v10;    // [esp+34h] [ebp-14h] BYREF
  float v11;    // [esp+38h] [ebp-10h]
  float v12;    // [esp+3Ch] [ebp-Ch]

  v10 = *a2 - *a1;
  v11 = a2[1] - a1[1];
  v12 = a2[2] - a1[2];
  Vec3NormalizeTo(&v10, &v7);
  result = cg;
  v3 = (float)((float)((float)(*((float *)cg + 41314) - *a1) * v7) +
               (float)((float)(*(float *)((char *)&loc_2858C + (_DWORD)cg) -
                               a1[1]) *
                       v8)) +
       (float)((float)(*((float *)cg + 41316) - a1[2]) * v9);
    if (v3 >= 64.0 && (float)(v3 + 64.0) <= (float)((float)((float)(v7 * v10) +
                                                            (float)(v8 * v11)) +
                                                    (float)(v9 * v12))) {
      v4 = (float)(v7 * v3) + *a1;
      v5 = (float)(v8 * v3) + a1[1];
      v6 = (float)(v3 * v9) + a1[2];
      v10 = v4 - *((float *)cg + 41314);
      v11 = v5 - *(float *)((char *)&loc_2858C + (_DWORD)cg);
      v12 = v6 - *((float *)cg + 41316);
        if (fsqrt((float)((float)(v10 * v10) + (float)(v11 * v11)) +
                  (float)(v12 * v12)) <= 140.0) {
          v4 = v4 + (float)(v7 * -16.0);
          v5 = (float)(v8 * -16.0) + v5;
          v6 = (float)(v9 * -16.0) + v6;
          return (void *)CG_PlaySoundAlias((float *)0x3FE, &v4,
                                           *((snd_alias_list_t **)cgs + 12395));
        }
    }
  return result;
}

void __cdecl CG_BulletHitClientEvent(int sourceEntityNum, float *const position,
                                     int surfType, int event)
{
  snd_alias_list_t *v4; // eax
  void *result;         // eax
  int v6;               // eax
  int v7;               // edx
  float v8;             // xmm0_4
  float v9[9];          // [esp+14h] [ebp-24h] BYREF

    if (a4 == 185) {
      v4 = (snd_alias_list_t *)*((_DWORD *)cgs + a3 + 12137);
    }
    else if (a4 == 183) {
      v4 = (snd_alias_list_t *)*((_DWORD *)cgs + a3 + 12183);
    }
    else {
      v4 = (snd_alias_list_t *)*((_DWORD *)cgs + a3 + 12160);
    }
  CG_PlaySoundAlias((float *)0x3FE, a2, v4);
  result = (void *)cg_tracerChance;
    if (*(float *)(cg_tracerChance + 8) > 0.0) {
      result = (void *)CG_CalcMuzzlePoint(a1, (int)v9,
                                          (unsigned __int16)*s_barrelTags[0]);
        if (result) {
          v6 = *((_DWORD *)cg + 9);
            if ((*(_DWORD *)(v6 + 24) & 0xC00000) == 0 ||
                a1 != *(_DWORD *)(v6 + 216)) {
              v7 = rand();
              if (v7 < 0)
                v8 = (float)(v7 & 1 | ((unsigned int)v7 >> 1)) +
                     (float)(v7 & 1 | ((unsigned int)v7 >> 1));
              else
                v8 = (float)v7;
              if ((float)(2147483600.0 * *(float *)(cg_tracerChance + 8)) > v8)
                CG_SpawnTracer(v9, a2);
            }
          return CG_WhizbySound(v9, a2);
        }
    }
  return result;
}

void __cdecl CG_RegisterWeapon(int weaponNum)
{
  UNIMPLEMENTED();
}

void __cdecl CG_BulletHitEvent(int sourceEntityNum, float *const position,
                               float *const normal, float *const reflected,
                               int surfType, int event)
{
  snd_alias_list_t *v6; // ecx
  int v7;               // eax
  EffectTemplate *v8;   // ebx
  EffectTemplate *v9;   // esi
  void *result;         // eax
  int v11;              // eax
  int v12;              // edx
  float v13;            // xmm0_4
  int v14;              // eax
  int v15;              // eax
  float v16[9];         // [esp+14h] [ebp-24h] BYREF

    if (a6 == 182) {
      v6 = (snd_alias_list_t *)*((_DWORD *)cgs + a5 + 12137);
      v14 = *(_DWORD *)(*((_DWORD *)cgs + 12416) + 4);
      v8 = *(EffectTemplate **)(v14 + 4 * a5);
      v9 = *(EffectTemplate **)(v14 + 4 * a5 + 92);
    }
    else if (a6 == 183) {
      v6 = (snd_alias_list_t *)*((_DWORD *)cgs + a5 + 12183);
      v15 = *(_DWORD *)(*((_DWORD *)cgs + 12416) + 4);
      v8 = *(EffectTemplate **)(v15 + 4 * a5 + 184);
      v9 = *(EffectTemplate **)(v15 + 4 * a5 + 276);
    }
    else {
      v6 = (snd_alias_list_t *)*((_DWORD *)cgs + a5 + 12160);
      v7 = *(_DWORD *)(*((_DWORD *)cgs + 12416) + 4);
      v8 = *(EffectTemplate **)(v7 + 4 * a5 + 368);
      v9 = *(EffectTemplate **)(v7 + 4 * a5 + 460);
    }
    if (!*(_BYTE *)(cg_blood + 8) && a5 == 7) {
      v8 = (EffectTemplate *)*((_DWORD *)cgs + 12417);
      v9 = 0;
    }
  CG_PlaySoundAlias((float *)0x3FE, a2, v6);
  if (v8)
    FX_PlayEffect(v8, a2, a3);
  if (v9)
    FX_PlayEffect(v9, a2, a4);
  result = (void *)cg_tracerChance;
    if (*(float *)(cg_tracerChance + 8) > 0.0) {
      result = (void *)CG_CalcMuzzlePoint(a1, (int)v16,
                                          (unsigned __int16)*s_barrelTags[0]);
        if (result) {
          v11 = *((_DWORD *)cg + 9);
            if ((*(_DWORD *)(v11 + 24) & 0xC00000) == 0 ||
                a1 != *(_DWORD *)(v11 + 216)) {
              v12 = rand();
              if (v12 < 0)
                v13 = (float)(v12 & 1 | ((unsigned int)v12 >> 1)) +
                      (float)(v12 & 1 | ((unsigned int)v12 >> 1));
              else
                v13 = (float)v12;
              if ((float)(2147483600.0 * *(float *)(cg_tracerChance + 8)) > v13)
                CG_SpawnTracer(v16, a2);
            }
          return CG_WhizbySound(v16, a2);
        }
    }
  return result;
}

void __cdecl CG_EjectWeaponBrass(struct entityState_s *ent, int event)
{
  int32_t weapon;  // ebx
  int32_t v4;      // ecx
  char *v5;        // ebx
  int v6;          // edx
  uint32_t number; // eax
  uint32_t v8;     // edx
  int v9;          // edx
  uint32_t v10;    // eax
  uint32_t v11;    // edx
  char v12;        // [esp+8h] [ebp-20h]
  FxBoltInfo v13;  // [esp+18h] [ebp-10h] BYREF

  if (!*(_BYTE *)(cg_brass + 8))
    return;
  if (a2->eType > 9)
    return;
  weapon = a2->weapon;
  if (!weapon)
    return;
    if (weapon > BG_GetNumWeapons()) {
      Com_Error(1, "\x15CG_EjectWeaponBrass: ent->weapon > BG_GetNumWeapons()",
                v12);
      return;
    }
  v4 = a2->weapon;
  v5 = (char *)cg_weapons + 436 * v4;
    if (!*((_DWORD *)v5 + 88) || a3 != 160) {
      if (!*((_DWORD *)v5 + 87))
        return;
      v6 = *((_DWORD *)cg + 9);
        if ((*(_DWORD *)(v6 + 24) & 0xC00000) != 0) {
          number = a2->number;
            if (a2->number == *(_DWORD *)(v6 + 216)) {
              v8 = v4 + 1024;
            LABEL_11:
              v13.dobjHandle = v8;
              v13.boneIndex =
                  FX_GetBoneIndex(v8, (unsigned __int16)word_195B114);
              if ((v13.boneIndex & 0x80000000) == 0)
                FX_PlayEntityEffect(a1, *((EffectTemplate **)v5 + 87),
                                    &ejectBrassCasingOrigin, 0, &v13);
              return;
            }
        }
        else {
          number = a2->number;
        }
      v8 = number;
      goto LABEL_11;
    }
  v9 = *((_DWORD *)cg + 9);
    if ((*(_DWORD *)(v9 + 24) & 0xC00000) == 0) {
      v10 = a2->number;
      goto LABEL_19;
    }
  v10 = a2->number;
    if (a2->number != *(_DWORD *)(v9 + 216)) {
    LABEL_19:
      v11 = v10;
      goto LABEL_20;
    }
  v11 = v4 + 1024;
LABEL_20:
  v13.dobjHandle = v11;
  v13.boneIndex = FX_GetBoneIndex(v11, (unsigned __int16)word_195B114);
  if ((v13.boneIndex & 0x80000000) == 0)
    FX_PlayEntityEffect(a1, *((EffectTemplate **)v5 + 88),
                        &ejectBrassCasingOrigin, 0, &v13);
}

void __cdecl CG_UpdateViewWeaponAnim(struct playerState_s *ps)
{
  UNIMPLEMENTED();
}

void __cdecl CG_RegisterItemVisuals(int itemNum)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateHandViewmodels(char const *handModel)
{
  UNIMPLEMENTED();
}

void __cdecl CG_FireWeapon(struct centity_s *cent, int event, int barrel)
{
  entityState_s *nextState; // esi
  int v5;                   // ebx
  int v6;                   // edx
  snd_alias_list_t *v7;     // ebx
  int v8;                   // eax
  int v9;                   // eax
  int v10;                  // ecx
  DObj_s *ClientDObj;       // edx
  int v12;                  // eax
  int v13;                  // eax
  _BOOL4 v14;               // edx
  int v15;                  // ebx
  int number;               // ecx
  EffectTemplate *v17;      // ebx
  char v18;                 // [esp+8h] [ebp-50h]
  char *v19;                // [esp+10h] [ebp-48h]
  unsigned int v20;         // [esp+14h] [ebp-44h]
  snd_alias_list_t *v21;    // [esp+1Ch] [ebp-3Ch]
  float v22[3];             // [esp+2Ch] [ebp-2Ch] BYREF
  FxBoltInfo v23;           // [esp+38h] [ebp-20h] BYREF

  nextState = (entityState_s *)a2->nextState;
  v5 = *(_DWORD *)&a2->nextState[200];
    if (v5) {
        if (v5 > BG_GetNumWeapons()) {
          Com_Error(1, "\x15CG_FireWeapon: ent->weapon > BG_GetNumWeapons()",
                    v18);
          return;
        }
      v19 = (char *)cg_weapons + 436 * *(_DWORD *)&a2->nextState[200];
      BG_GetWeaponDef(*(_DWORD *)&a2->nextState[200]);
      a2->bMuzzleFlash = 1;
      v6 = *((_DWORD *)cg + 9);
      if ((*(_DWORD *)(v6 + 24) & 0xC00000) != 0 &&
          *(_DWORD *)a2->nextState == *(_DWORD *)(v6 + 216))
        BG_WeaponFireRecoil(
            (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg),
            (float *)cg + 45100, (float *)cg + 45068);
        if (*(_DWORD *)&a2->nextState[4] == 9) {
          v14 = 0;
            if (!*(_DWORD *)((char *)&locret_25BC0 + (_DWORD)cg)) {
              v13 = *((_DWORD *)cg + 9);
              if ((*(_DWORD *)(v13 + 172) & 0x300) != 0 &&
                  *(_DWORD *)(v13 + 1440) == nextState->number)
                v14 = 1;
            }
          v20 = (unsigned __int16)*s_barrelTags[a4];
          v15 = *(_DWORD *)&a2->nextState[200];
          number = nextState->number;
          v17 =
              (EffectTemplate *)(v14 ? *((_DWORD *)cg_weapons + 109 * v15 + 48)
                                     : *((_DWORD *)cg_weapons + 109 * v15 +
                                         49));
            if (v17) {
              v23.dobjHandle = nextState->number;
              v23.boneIndex = FX_GetBoneIndex(number, v20);
              if ((v23.boneIndex & 0x80000000) == 0)
                FX_PlayEntityEffect(a1, v17, a2->lerpOrigin, 0, &v23);
            }
        }
      v7 = (snd_alias_list_t *)*((_DWORD *)v19 + 55);
        if (*((_DWORD *)v19 + 56)) {
          v8 = *((_DWORD *)cg + 9);
          if ((*(_DWORD *)(v8 + 24) & 0xC00000) != 0 &&
              nextState->number == *(_DWORD *)(v8 + 216))
            v7 = (snd_alias_list_t *)*((_DWORD *)v19 + 56);
        }
      if (a3 != 160)
        goto LABEL_12;
      v21 = (snd_alias_list_t *)*((_DWORD *)v19 + 58);
        if (v21) {
          v9 = *((_DWORD *)cg + 9);
            if ((*(_DWORD *)(v9 + 24) & 0xC00000) != 0) {
              v10 = nextState->number;
              if (nextState->number == *(_DWORD *)(v9 + 216))
                goto LABEL_16;
            }
        }
      v21 = (snd_alias_list_t *)*((_DWORD *)v19 + 57);
        if (!v21) {
        LABEL_12:
            if (!v7) {
            LABEL_21:
              if (!*(_DWORD *)(BG_GetWeaponDef(*(_DWORD *)&a2->nextState[200]) +
                               808))
                CG_EjectWeaponBrass(a1, nextState, a3);
              return;
            }
          v21 = v7;
        }
      v9 = *((_DWORD *)cg + 9);
        if ((*(_DWORD *)(v9 + 24) & 0xC00000) == 0) {
          v10 = nextState->number;
          goto LABEL_17;
        }
      v10 = nextState->number;
    LABEL_16:
        if (v10 == *(_DWORD *)(v9 + 216)) {
            if (*(_DWORD *)v19 &&
                CG_DObjGetViewModelTagPos(
                    *(DObj_s **)v19, (unsigned __int16)word_195B10C, v22)) {
            LABEL_19:
              v12 = CG_PlaySoundAlias((float *)nextState->number, v22, v21);
              if (*(_DWORD *)&a2->nextState[4] == 1)
                CG_CompassAddWeaponPingInfo(a2, v22, v12);
              goto LABEL_21;
            }
        LABEL_39:
          BG_EvaluateTrajectory((const trajectory_t *)&a2->nextState[12],
                                *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg),
                                v22);
          goto LABEL_19;
        }
    LABEL_17:
      ClientDObj = Com_GetClientDObj(v10, a2->localClientNum);
      if (ClientDObj &&
          CG_DObjGetWorldTagPos(a2, ClientDObj, (unsigned __int16)word_195B10C,
                                v22))
        goto LABEL_19;
      goto LABEL_39;
    }
}

void __cdecl CG_AddPlayerWeapon(struct GfxEntity *parent,
                                struct playerState_s *ps,
                                struct centity_s *cent, int bDrawGun)
{
  int v5;                       // edx
  void *v6;                     // ebx
  char *v7;                     // edx
  int BoneIndex;                // ebx
  int32_t RotTransArray;        // esi
  void *v10;                    // ebx
  int v11;                      // eax
  int v12;                      // eax
  void *v13;                    // eax
  float v14;                    // xmm2_4
  float *v15;                   // eax
  int i;                        // edx
  unsigned int v17;             // ecx
  float *lerpOrigin;            // esi
  uint32_t v19;                 // edx
  EffectTemplate *v20;          // ebx
  int v21;                      // eax
  void *v22;                    // edx
  GfxEntity *v23;               // eax
  float *v24;                   // [esp+28h] [ebp-100h]
  int v25;                      // [esp+2Ch] [ebp-FCh]
  bool v26;                     // [esp+33h] [ebp-F5h]
  int32_t ViewmodelWeaponIndex; // [esp+34h] [ebp-F4h]
  GfxModel *v28;                // [esp+38h] [ebp-F0h]
  int v29;                      // [esp+3Ch] [ebp-ECh]
  _BYTE __b[128];               // [esp+40h] [ebp-E8h] BYREF
  __int64 v31;                  // [esp+C0h] [ebp-68h]
  float v32;                    // [esp+C8h] [ebp-60h]
  __int64 v33;                  // [esp+CCh] [ebp-5Ch]
  float v34;                    // [esp+D4h] [ebp-54h]
  float v35;                    // [esp+D8h] [ebp-50h]
  float v36;                    // [esp+DCh] [ebp-4Ch]
  float v37;                    // [esp+E0h] [ebp-48h]
  FxBoltInfo v38;               // [esp+E4h] [ebp-44h] BYREF

  v5 = *((_DWORD *)cg + 9);
  v26 = (*(_DWORD *)(v5 + 24) & 0xC00000) != 0 &&
        *(_DWORD *)a4->nextState == *(_DWORD *)(v5 + 216);
    if (a3) {
      ViewmodelWeaponIndex = BG_GetViewmodelWeaponIndex(a3);
      v29 = 1;
    }
    else {
      ViewmodelWeaponIndex = *(_DWORD *)&a4->nextState[200];
      v29 = 0;
    }
    if (ViewmodelWeaponIndex > 0 &&
        (*(_DWORD *)&a4->nextState[8] & 0x300) == 0) {
      v25 = 436 * ViewmodelWeaponIndex;
      v28 = (GfxModel *)((char *)cg_weapons + 436 * ViewmodelWeaponIndex);
        if (v29) {
            if (a5) {
              memset(__b, 0, 0x74u);
              __b[88] = -1;
              __b[89] = -1;
              __b[90] = -1;
              __b[91] = -1;
              *(_DWORD *)__b = 0;
              *(_DWORD *)&__b[4] = 140;
              *(float *)&__b[8] = a3->origin[0];
              *(float *)&__b[12] = a3->origin[1];
              *(float *)&__b[16] =
                  a3->origin[2] + *(float *)&a3->viewHeightCurrent;
              AddLeanToPosition((float *)&__b[8], a3->viewangles[1],
                                *(float *)&a3->leanf, 16.0, 20.0);
              *(float *)&__b[60] = a2->origin[0];
              *(float *)&__b[64] = a2->origin[1];
              *(float *)&__b[68] = a2->origin[2];
              v24 = a2->axis[0];
              AxisCopy(a2->axis[0], &__b[20]);
              v23 = (GfxEntity *)R_AddRefEntityToScene((const GfxEntity *)__b,
                                                       (GfxModel)v28->obj, 0);
              if (v23)
                R_SkinGfxEntityDelayed(v23);
            }
            else {
              v24 = a2->axis[0];
            }
          v6 = cg;
          v7 = (char *)cg + 180412;
          *((_DWORD *)cg + 45103) = LODWORD(a2->origin[0]);
          *((_DWORD *)v7 + 1) = LODWORD(a2->origin[1]);
          *((_DWORD *)v7 + 2) = LODWORD(a2->origin[2]);
          AxisCopy(v24, (_DWORD *)v6 + 45106);
          AxisToAngles((float *)v6 + 45106, (float *)v6 + 45115);
          BoneIndex = DObjGetBoneIndex((const DObj_s *)v28->obj,
                                       (unsigned __int16)word_195B114);
            if (BoneIndex > -1) {
              RotTransArray = DObjGetRotTransArray((const DObj_s *)v28->obj);
                if (RotTransArray) {
                  *(float *)&__b[116] = a2->axis[0][0];
                  *(float *)&__b[120] = v24[1];
                  *(float *)&__b[124] = v24[2];
                  v31 = *(_QWORD *)&a2->axis[1][0];
                  v32 = a2->axis[1][2];
                  v33 = *(_QWORD *)&a2->axis[2][0];
                  v34 = a2->axis[2][2];
                  v35 = a2->origin[0];
                  v36 = a2->origin[1];
                  v37 = a2->origin[2];
                  MatrixTransformVector43(
                      (const float *)(RotTransArray + 32 * BoneIndex + 16),
                      (const float(*)[3]) & __b[116], &ejectBrassCasingOrigin);
                }
            }
          v10 = cg;
          v11 = *((_DWORD *)cg + 45890);
          if (v11 > 0)
            *((_DWORD *)cg + 45890) = v11 - *((_DWORD *)cg + 38635);
            if ((*((_BYTE *)v10 + 154577) & 0x40) != 0) {
              *((float *)v10 + 45891) =
                  DiffTrack(1.0, *((float *)v10 + 45891),
                            *(float *)(player_breath_snd_lerp + 8),
                            (float)*((int *)v10 + 38635) * 0.001);
              v21 = *((_DWORD *)v10 + 45888);
                if (v21 < 0) {
                  *((_DWORD *)v10 + 45888) = 0;
                    if (*((int *)v10 + 45890) <= 0) {
                      *((_DWORD *)v10 + 45889) = CG_PlayClientSoundAlias(
                          *((snd_alias_list_t **)cgs + 12401));
                      *((_DWORD *)v10 + 45890) =
                          (int)(float)(1000.0 *
                                       *(float *)(player_breath_snd_delay + 8));
                    }
                    else {
                      *((_DWORD *)v10 + 45889) = 0;
                    }
                }
                else if (v21 > *((_DWORD *)v10 + 45889)) {
                  CG_PlayClientSoundAlias(*((snd_alias_list_t **)cgs + 12400));
                }
              v22 = cg;
              *((_DWORD *)cg + 45888) += *((_DWORD *)cg + 38635);
              a1 = 0.0;
              v13 = v22;
            }
            else {
              v12 = *((_DWORD *)v10 + 45888);
                if (v12 >= 0) {
                  *((_DWORD *)v10 + 45888) = *((_DWORD *)v10 + 38635) + v12;
                    if ((int)(float)(*(float *)(player_breath_hold_time + 8) *
                                     1000.0) < *((_DWORD *)v10 + 45888)) {
                      CG_PlayClientSoundAlias(
                          *((snd_alias_list_t **)cgs + 12403));
                    }
                    else if (*((int *)v10 + 45890) <= 0) {
                      CG_PlayClientSoundAlias(
                          *((snd_alias_list_t **)cgs + 12402));
                      *((_DWORD *)v10 + 45890) =
                          (int)(float)(1000.0 *
                                       *(float *)(player_breath_snd_delay + 8));
                    }
                }
              v13 = cg;
              *((_DWORD *)cg + 45888) = -1;
              *((_DWORD *)v13 + 45889) = 0;
              a1 = 0.0;
              *((_DWORD *)v13 + 45891) = 0;
            }
          v14 = *((float *)v13 + 45891);
            if (v14 == 0.0) {
              SND_DeactivateChannelVolumes(1, 0);
            }
            else {
              v15 = (float *)((char *)cgs + 28932);
                for (i = 1; i != 12; ++i) {
                  a1 = (float)((float)(v15[14] - 1.0) * v14) + 1.0;
                  *((float *)&v38 + i - 1) = a1;
                  ++v15;
                }
              SND_SetChannelVolumes(1, (const float *)&v38.dobjHandle, 0);
            }
        }
        if (a4->bMuzzleFlash && (!v26 || v29)) {
          a4->bMuzzleFlash = 0;
            if (a5) {
                if (v29) {
                  v17 = (unsigned __int16)*s_barrelTags[0];
                  lerpOrigin = (float *)((char *)cg + 180412);
                  v19 = ViewmodelWeaponIndex + 1024;
                  v20 = *(EffectTemplate **)((char *)cg_weapons + v25 + 192);
                  if (!v20)
                    return;
                }
                else {
                  v17 = (unsigned __int16)*s_barrelTags[0];
                  lerpOrigin = a4->lerpOrigin;
                  v19 = *(_DWORD *)a4->nextState;
                  v20 = *(EffectTemplate **)((char *)cg_weapons + v25 + 196);
                  if (!v20)
                    return;
                }
              v38.dobjHandle = v19;
              v38.boneIndex = FX_GetBoneIndex(v19, v17);
              if ((v38.boneIndex & 0x80000000) == 0)
                FX_PlayEntityEffect(a1, v20, lerpOrigin, 0, &v38);
            }
        }
    }
}

void __cdecl CG_RegisterItems()
{
  UNIMPLEMENTED();
}

void __cdecl CG_AddViewWeapon(struct playerState_s *ps)
{
  int32_t pm_type;              // eax
  void *v2;                     // ebx
  int32_t v3;                   // eax
  int WeaponDef;                // ecx
  int v5;                       // edx
  int v6;                       // eax
  float v7;                     // xmm2_4
  float v8;                     // xmm0_4
  float v9;                     // xmm1_4
  _DWORD *v10;                  // ebx
  int32_t v11;                  // eax
  float v12;                    // xmm0_4
  void *v13;                    // esi
  void *v14;                    // ebx
  int32_t v15;                  // eax
  int v16;                      // edx
  float v17;                    // xmm1_4
  float v18;                    // xmm0_4
  __m128 v19;                   // xmm2
  __m128 v20;                   // xmm6
  __m128 v21;                   // xmm1
  __m128 v22;                   // xmm1
  float v23;                    // xmm1_4
  float *v24;                   // eax
  float v25;                    // xmm0_4
  int v26;                      // eax
  float *v27;                   // edi
  float *v28;                   // edx
  int i;                        // ecx
  float *v30;                   // esi
  float v31;                    // xmm3_4
  float v32;                    // xmm2_4
  float v33;                    // xmm4_4
  float v34;                    // xmm1_4
  float v35;                    // xmm0_4
  float *v36;                   // edx
  float v37;                    // xmm0_4
  float v38;                    // xmm0_4
  float v39;                    // xmm1_4
  float v40;                    // xmm2_4
  float *v41;                   // ebx
  float v42;                    // xmm3_4
  int v43;                      // edx
  float *v44;                   // ebx
  int32_t v45;                  // eax
  float v46;                    // xmm1_4
  char *v47;                    // ebx
  float v48;                    // xmm1_4
  float v49;                    // xmm1_4
  float v50;                    // xmm1_4
  float v51;                    // xmm0_4
  uint32_t deltaTime;           // edx
  uint32_t v53;                 // eax
  float *v54;                   // esi
  int v55;                      // ebx
  char *v56;                    // eax
  char *v57;                    // edx
  float v58;                    // xmm1_4
  float *v59;                   // eax
  float v60;                    // xmm0_4
  float v61;                    // xmm0_4
  char *v62;                    // eax
  float LeanFraction;           // [esp+3Ch] [ebp-1BCh]
  float v64;                    // [esp+40h] [ebp-1B8h]
  float v65;                    // [esp+50h] [ebp-1A8h]
  float v66;                    // [esp+60h] [ebp-198h]
  float v67;                    // [esp+60h] [ebp-198h]
  _BOOL4 v68;                   // [esp+70h] [ebp-188h]
  int32_t ViewmodelWeaponIndex; // [esp+74h] [ebp-184h]
  char *v70;                    // [esp+78h] [ebp-180h]
  float *v71;                   // [esp+7Ch] [ebp-17Ch]
  GfxEntity __b;                // [esp+84h] [ebp-174h] BYREF
  weaponState_t v73;            // [esp+F8h] [ebp-100h] BYREF
  float v74[9];                 // [esp+14Ch] [ebp-ACh] BYREF
  float v75[9];                 // [esp+170h] [ebp-88h] BYREF
  float v76;                    // [esp+194h] [ebp-64h] BYREF
  float v77;                    // [esp+198h] [ebp-60h]
  float v78;                    // [esp+19Ch] [ebp-5Ch]
  float v79[3];                 // [esp+1A0h] [ebp-58h] BYREF
  float v80[3];                 // [esp+1ACh] [ebp-4Ch] BYREF
  float v81[3];                 // [esp+1B8h] [ebp-40h] BYREF
  float v82[2];                 // [esp+1C4h] [ebp-34h] BYREF
  float v83;                    // [esp+1CCh] [ebp-2Ch]
  float v84[3];                 // [esp+1D0h] [ebp-28h] BYREF
  float v85[7];                 // [esp+1DCh] [ebp-1Ch] BYREF

  pm_type = a1->pm_type;
  if (pm_type == 4 || pm_type == 5 ||
      *(_DWORD *)((char *)&locret_25BC0 + (_DWORD)cg))
    return;
  v68 = !*((_DWORD *)cg + 3) && *(_BYTE *)(cg_drawGun + 8) &&
        !(unsigned __int8)CG_GetWeapReticleZoom(v85);
  v2 = cg;
  if (*((_DWORD *)cg + 45046) || (a1->eFlags & 0x300) != 0)
    return;
  ViewmodelWeaponIndex = BG_GetViewmodelWeaponIndex(a1);
    if (ViewmodelWeaponIndex <= 0) {
      *(_DWORD *)((char *)&loc_2C090 + (_DWORD)v2) = *((_DWORD *)v2 + 41330);
      *((_DWORD *)v2 + 45093) = *((_DWORD *)v2 + 41331);
      *(_DWORD *)((char *)&loc_2C098 + (_DWORD)v2) = 0;
      *(_DWORD *)((char *)&loc_2C09C + (_DWORD)v2) = 0;
      *((_DWORD *)v2 + 45096) = 0;
      return;
    }
  v3 = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v2));
  WeaponDef = BG_GetWeaponDef(v3);
  v5 = *(_DWORD *)((char *)&loc_2CCE0 + (_DWORD)v2) + *((_DWORD *)v2 + 45879) -
       *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v2);
    if (v5 <= 0) {
      v9 = 1.0;
    }
    else {
      v6 = **((_DWORD **)v2 + 45878);
        if (v5 < v6) {
          v7 = (float)v5 / (float)v6;
          v8 = v7 * -2.0;
        }
        else {
          v7 = 1.0;
          v8 = -2.0;
        }
      v9 = (float)((float)((float)((float)(v8 + 3.0) * v7) * v7) *
                   (float)(*(float *)(WeaponDef + 768) - 1.0)) +
           1.0;
    }
  BG_CalculateWeaponPosition_Sway(
      (playerState_s *)((char *)&loc_25BC4 + (_DWORD)v2), (float *)v2 + 41333,
      (float *)v2 + 41339, (float *)v2 + 41336, v9, *((_DWORD *)v2 + 38635));
  v10 = cg;
  v11 = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg));
    if (BG_IsAimDownSightWeapon(v11)) {
      v12 = *(float *)((char *)&loc_25CA0 + (_DWORD)v10);
        if (v12 == 1.0) {
          v10[41253] = 0;
        }
        else if (v12 == 0.0) {
          v10[41253] = 1;
        }
      v10[41252] = *(_DWORD *)((char *)&loc_25CA0 + (_DWORD)cg);
    }
  memset(&__b, 0, sizeof(__b));
  memset(__b.origin, 0, sizeof(__b.origin));
  v13 = cg;
    if (*(float *)((char *)&loc_25C10 + (_DWORD)cg) == 0.0) {
      v14 = cg;
    }
    else {
        if (*(float *)((char *)&loc_25CA0 + (_DWORD)cg) < 1.0) {
          v82[0] = 0.0;
          v82[1] = 0.0;
          v83 = 0.0;
          LeanFraction =
              GetLeanFraction(*(float *)((char *)&loc_25C10 + (_DWORD)cg));
          v83 = (float)(LeanFraction * -2.0) + v83;
          v67 = (float)((float)(1.0 -
                                *(float *)((char *)&loc_25CA0 + (_DWORD)v13)) *
                        LeanFraction) *
                1.6;
          AngleVectors(v82, 0, v81, 0);
          __b.origin[0] = (float)(v67 * v81[0]) + __b.origin[0];
          __b.origin[1] = (float)(v67 * v81[1]) + __b.origin[1];
          __b.origin[2] = (float)(v67 * v81[2]) + __b.origin[2];
        }
      v14 = cg;
    }
  v15 = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v14));
  v71 = (float *)BG_GetWeaponDef(v15);
  v16 = *(_DWORD *)((char *)&loc_28364 + (_DWORD)v14);
    if ((v16 & 8) != 0) {
      v17 = v71[103] + *(float *)(cg_gun_move_minspeed + 8);
    }
    else {
      if ((v16 & 4) != 0)
        v58 = v71[102];
      else
        v58 = v71[101];
      v17 = v58 + *(float *)(cg_gun_move_minspeed + 8);
    }
  v18 = *((float *)cg + 44999);
    if (v18 <= v17 || *((_DWORD *)cg + 38695) == 5) {
      v76 = 0.0;
      v77 = 0.0;
      v78 = 0.0;
    }
    else {
      v19 = (__m128) * ((unsigned int *)cg + 44999);
      v19.f32[0] =
          (float)(v18 - v17) / (float)((float)*((int *)cg + 38661) - v17);
      v20.i32[0] = 0;
        if ((float)(0.0 - v19.f32[0]) < 0.0) {
          v21 = v19;
          v21.f32[0] = v19.f32[0] - 1.0;
        }
        else {
          v19.i32[0] = 0;
          v21 = (__m128)0xBF800000;
        }
      v22 = _mm_cmplt_ss(v21, v20);
      LODWORD(v23) = _mm_andnot_ps(v22, (__m128)0x3F800000u).u32[0] |
                     v19.i32[0] & v22.i32[0];
        if ((*(_DWORD *)((_BYTE *)&loc_28364 + (_DWORD)v14) & 8) != 0) {
          v24 = v71 + 93;
          v25 = v23 * v71[93];
        }
        else if ((v16 & 4) != 0) {
          v24 = v71 + 84;
          v25 = v23 * v71[84];
        }
        else {
          v24 = v71 + 75;
          v25 = v23 * v71[75];
        }
      v76 = v25;
      v77 = v23 * v24[1];
      v78 = v23 * v24[2];
      v76 = (float)(v23 * *(float *)(cg_gun_move_f + 8)) + v25;
      v77 = (float)(v23 * *(float *)(cg_gun_move_r + 8)) + v77;
      v78 = (float)(v23 * *(float *)(cg_gun_move_u + 8)) + v78;
    }
  v26 = *((_DWORD *)cg + 38702);
    if (v26 == 40) {
      v59 = v71 + 81;
      v60 = v76 + v71[81];
    LABEL_73:
      v76 = v60;
      v77 = v77 + v59[1];
      v78 = v78 + v59[2];
      v76 = v60 + *(float *)(cg_gun_ofs_f + 8);
      v77 = v77 + *(float *)(cg_gun_ofs_r + 8);
      v78 = v78 + *(float *)(cg_gun_ofs_u + 8);
      goto LABEL_34;
    }
    if (v26 == 11) {
      v59 = v71 + 90;
      v60 = v76 + v71[90];
      goto LABEL_73;
    }
LABEL_34:
  v27 = (float *)((char *)cg + 165008);
  v28 = (float *)((char *)cg + 165008);
    for (i = 1; i != 4; ++i) {
      v30 = v28 + 6;
      v31 = v28[6];
      v32 = v75[i + 8];
      if (v31 == v32)
        goto LABEL_40;
      v33 = (float)*((int *)cg + 38635);
      if (*((float *)cg + 38703) == 11.0)
        v34 = (float)((float)(v33 * 0.001) * (float)(v32 - v31)) *
              (float)(v71[100] + *(float *)(cg_gun_move_rate + 8));
      else
        v34 = (float)((float)(v33 * 0.001) * (float)(v32 - v31)) *
              (float)(v71[99] + *(float *)(cg_gun_move_rate + 8));
        if (v32 <= v31) {
          v32 = fmaxf(v32, fminf((float)(v33 * 0.001) * -0.1, v34) + v31);
        }
        else {
          v35 = fmaxf((float)(v33 * 0.001) * 0.1, v34) + v31;
          *v30 = v35;
          if (v35 <= v32)
            goto LABEL_40;
        }
      *v30 = v32;
    LABEL_40:
      ++v28;
    }
  v36 = (float *)cg;
  v37 = *(float *)((char *)&loc_25CA0 + (_DWORD)cg);
    if (v37 == 0.0) {
      v40 = v27[6] + 0.0;
      v39 = v27[7] + 0.0;
      v38 = v27[8] + 0.0;
    }
    else if (v37 < 0.5) {
      v61 = (float)(v37 * -2.0) + 1.0;
      v40 = (float)(v61 * v27[6]) + 0.0;
      v39 = (float)(v61 * v27[7]) + 0.0;
      v38 = (float)(v61 * v27[8]) + 0.0;
    }
    else {
      v38 = 0.0;
      v39 = 0.0;
      v40 = 0.0;
    }
  *((float *)cg + 41254) = v40;
  v36[41255] = v39;
  v36[41256] = v38;
  __b.origin[0] = v40 + __b.origin[0];
  __b.origin[1] = v39 + __b.origin[1];
  __b.origin[2] = v38 + __b.origin[2];
  v41 = (float *)cg;
  __b.origin[1] = __b.origin[1] - *((float *)cg + 41340);
  __b.origin[2] = __b.origin[2] + *((float *)cg + 41341);
  v66 = __b.origin[1];
  v65 = __b.origin[0];
  v64 = __b.origin[2];
  AngleVectors((float *)cg + 45115, &v76, v79, v80);
  __b.origin[0] = v41[45103];
  __b.origin[1] = v41[45104];
  __b.origin[2] = v41[45105];
  __b.origin[0] = (float)(v65 * v76) + __b.origin[0];
  __b.origin[1] = (float)(v65 * v77) + __b.origin[1];
  __b.origin[0] = (float)((float)-v66 * v79[0]) + __b.origin[0];
  __b.origin[1] = (float)((float)-v66 * v79[1]) + __b.origin[1];
  __b.origin[0] = (float)(v64 * v80[0]) + __b.origin[0];
  __b.origin[1] = (float)(v64 * v80[1]) + __b.origin[1];
  v42 = (float)(v64 * v80[2]) +
        (float)((float)((float)-v66 * v79[2]) +
                (float)((float)(v65 * v78) + __b.origin[2]));
  __b.origin[2] = v42;
  v43 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v41) -
        *(_DWORD *)((char *)&loc_284DC + (_DWORD)v41);
    if (v43 > 149) {
      if (v43 <= 449)
        __b.origin[2] =
            v42 + (float)((float)((float)(0.25 * *(float *)((char *)&loc_284D8 +
                                                            (_DWORD)v41)) *
                                  (float)(450 - v43)) /
                          300.0);
    }
    else {
      __b.origin[2] =
          v42 + (float)((float)((float)(0.25 * *(float *)((char *)&loc_284D8 +
                                                          (_DWORD)v41)) *
                                (float)v43) /
                        150.0);
    }
  v44 = (float *)cg;
  v45 = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg));
    if (BG_IsAimDownSightWeapon(v45)) {
      v46 = *(float *)((char *)&loc_25CA0 + (_DWORD)v44);
        if (v46 == 0.0) {
          *(_DWORD *)((char *)&loc_2C098 + (_DWORD)v44) = 0;
          v62 = (char *)cg;
          *(_DWORD *)((char *)&loc_2C09C + (_DWORD)cg) = 0;
          *((_DWORD *)v62 + 45096) = 0;
          v47 = v62;
        }
        else {
          *(float *)((char *)&loc_2C098 + (_DWORD)v44) =
              (float)(__b.origin[0] - v44[41314]) * v46;
          *(float *)((char *)&loc_2C09C + (_DWORD)v44) =
              (float)(__b.origin[1] -
                      *(float *)((char *)&loc_2858C + (_DWORD)v44)) *
              v46;
          v44[45096] = v46 * (float)(__b.origin[2] - v44[41316]);
          v47 = (char *)cg;
        }
    }
    else {
      *(_DWORD *)((char *)&loc_2C098 + (_DWORD)v44) = 0;
      *(_DWORD *)((char *)&loc_2C09C + (_DWORD)v44) = 0;
      v44[45096] = 0.0;
      v47 = (char *)cg;
    }
  v48 = *(float *)(cg_gun_x + 8);
  __b.origin[0] = (float)(v48 * *((float *)v47 + 45106)) + __b.origin[0];
  __b.origin[1] = (float)(v48 * *((float *)v47 + 45107)) + __b.origin[1];
  __b.origin[2] = (float)(v48 * *((float *)v47 + 45108)) + __b.origin[2];
  v49 = *(float *)(cg_gun_y + 8);
  __b.origin[0] = (float)(v49 * *((float *)v47 + 45109)) + __b.origin[0];
  __b.origin[1] = (float)(v49 * *((float *)v47 + 45110)) + __b.origin[1];
  __b.origin[2] = (float)(v49 * *((float *)v47 + 45111)) + __b.origin[2];
  v50 = *(float *)(cg_gun_z + 8);
  __b.origin[0] = (float)(v50 * *((float *)v47 + 45112)) + __b.origin[0];
  __b.origin[1] = (float)(v50 * *((float *)v47 + 45113)) + __b.origin[1];
  __b.origin[2] = (float)(v50 * *((float *)v47 + 45114)) + __b.origin[2];
  AnglesToAxis((float *)v47 + 45115, v74);
  v70 = v47 + 165008;
  v73.ps = (int32_t)a1;
  v73.xyspeed = *((float *)v47 + 44999);
  v51 = (float)*((int *)v47 + 38635) * 0.001;
  *(float *)&v73.frametime = v51;
  v73.vLastMoveAng[0] = *((float *)v47 + 41261);
  v73.vLastMoveAng[1] = *((float *)v47 + 41262);
  v73.vLastMoveAng[2] = *((float *)v47 + 41263);
  v73.fLastIdleFactor = *((float *)v47 + 41257);
  deltaTime = a1->deltaTime;
  v73.time = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v47) - deltaTime;
  v53 = *((_DWORD *)v47 + 44981);
  if (v53)
    v53 -= deltaTime;
  v73.damageTime = v53;
  v54 = (float *)cg;
  v73.v_dmg_pitch = *((_DWORD *)cg + 44996);
  v73.v_dmg_roll = *((_DWORD *)cg + 44997);
  v73.vGunOffset[0] = *((float *)cg + 45097);
  v73.vGunOffset[1] = *((float *)cg + 45098);
  v73.vGunOffset[2] = *((float *)cg + 45099);
  v73.vGunSpeed[0] = *((float *)cg + 45100);
  v73.vGunSpeed[1] = *((float *)cg + 45101);
  v73.vGunSpeed[2] = *((float *)cg + 45102);
  v73.swayAngles[0] = *((float *)cg + 41336);
  v73.swayAngles[1] = *((float *)cg + 41337);
  v73.swayAngles[2] = *((float *)cg + 41338);
  v73.weapIdleTime = (uint32_t)&loc_2BEEC + (_DWORD)cg;
  BG_CalculateWeaponAngles(&v73, v84);
  AnglesToAxis(v84, v75);
  MatrixMultiply(v75, v74, __b.axis[0]);
  v55 = BG_GetWeaponDef(ViewmodelWeaponIndex);
    if (!BG_IsAimDownSightWeapon(a1->weapon) ||
        (v51 = 0.0, a1->fWeaponPosFrac == 0.0) || *(_DWORD *)(v55 + 632)) {
      v56 = (char *)cg;
      *(_DWORD *)((char *)&loc_2C090 + (_DWORD)cg) = *((_DWORD *)cg + 41330);
      *((_DWORD *)v56 + 45093) = *((_DWORD *)v56 + 41331);
      v57 = v56;
    }
    else {
      AxisToAngles(__b.axis[0], v84);
      *(float *)((char *)&loc_2C090 + (_DWORD)v54) = AngleNormalize360(v84[0]);
      v54[45093] = AngleNormalize360(v84[1]);
      v57 = (char *)cg;
    }
  *((_DWORD *)v57 + 41261) = LODWORD(v73.vLastMoveAng[0]);
  *((_DWORD *)v57 + 41262) = LODWORD(v73.vLastMoveAng[1]);
  *((_DWORD *)v57 + 41263) = LODWORD(v73.vLastMoveAng[2]);
  *((_DWORD *)v70 + 5) = LODWORD(v73.fLastIdleFactor);
  *((_DWORD *)v57 + 45097) = LODWORD(v73.vGunOffset[0]);
  *((_DWORD *)v57 + 45098) = LODWORD(v73.vGunOffset[1]);
  *((_DWORD *)v57 + 45099) = LODWORD(v73.vGunOffset[2]);
  *((_DWORD *)v57 + 45100) = LODWORD(v73.vGunSpeed[0]);
  *((_DWORD *)v57 + 45101) = LODWORD(v73.vGunSpeed[1]);
  *((_DWORD *)v57 + 45102) = LODWORD(v73.vGunSpeed[2]);
  __b.renderFxFlags = 12;
  CG_AddPlayerWeapon(v51, &__b, a1, (centity_s *)(v57 + 164460), v68);
}

int removeMeWhenMPStopsCrashingInHere;
float *ejectBrassCasingOrigin;

void __cdecl CG_CalculateWeaponPosition_SwayMovement(float *const)
{
  UNIMPLEMENTED();
}

int __cdecl CG_WeaponSelectable(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_HoldBreathSoundLerp(float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPostion_PositionToADS(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPosition_SaveOffsetMovement(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPosition_BasePosition_movement(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPosition_ToWorldPosition(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPosition_BasePosition(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPosition(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_CalculateWeaponPosition_Sway(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ParseWeaponDefFiles(char const **, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_PlayADSAnim(int, struct XAnimTree_s *, int)
{
  void *v3; // ebx

    if (a1 == 21) {
      XAnimSetGoalWeight(a2, 21, 0x3F800000u, 0.5, 0, 0, 1, 0);
      XAnimSetGoalWeight(a2, 22, 0, 0.5, 0, 0, 0, 0);
    }
    else {
      XAnimSetGoalWeight(a2, 21, 0, 0.5, 0, 0, 0, 0);
      XAnimSetGoalWeight(a2, 22, 0x3F800000u, 0.5, 0, 0, 1, 0);
    }
  v3 = cg;
  XAnimSetTime(a2, 0x15u, *(float *)((char *)&loc_25CA0 + (_DWORD)cg));
  return XAnimSetTime(a2, 0x16u,
                      1.0 - *(float *)((char *)&loc_25CA0 + (_DWORD)v3));
}

void __cdecl CG_StartWeaponAnim(int, struct XAnimTree_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ResetWeaponAnimTrees(struct playerState_s *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_HoldBreathUpdate(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ProcessWeaponNoteTracks(void)
{
  UNIMPLEMENTED();
}

int __cdecl CG_CalcMuzzlePoint(int, float *const, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_BulletTrajectoryEffects(int, float *const, int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_RegisterWeaponRumble(char const *, char const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ChangeViewmodelDobj(int, char const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_WeaponFlash(int, int, float *const, int, unsigned int)
{
  UNIMPLEMENTED();
}
