int __cdecl LogAccuracyHit(struct gentity_s *target, struct gentity_s *attacker)
{
  int32_t client; // eax
  _BOOL4 result;  // eax

  result = 0;
    if (a1->takedamage) {
        if (a1 != a2) {
          client = a1->client;
            if (client) {
              if (a2->client && *(int *)(client + 4) <= 5 &&
                  !OnSameTeam(a1, a2))
                return 1;
            }
        }
    }
  return result;
}

int __cdecl Bullet_GetDamage(struct weaponParms const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl SnapVectorTowards(float *const v, float *const to)
{
  int i;     // esi
  float *v3; // ebx

    for (i = 1; i != 4; ++i) {
      v3 = &a1[i];
      if (*(v3 - 1) < a2[i - 1])
        *(v3 - 1) = ceilf(*(v3 - 1));
      else
        *(v3 - 1) = floorf(*(v3 - 1));
    }
}

void __cdecl Bullet_Endpos(float spread, float *const end,
                           struct weaponParms const *wp, float maxRange)
{
  float v4;       // xmm0_4
  float v5;       // xmm0_4
  float v6;       // xmm2_4
  float v7;       // xmm1_4
  float *result;  // eax
  long double v9; // [esp+0h] [ebp-68h]
  float v10;      // [esp+1Ch] [ebp-4Ch]
  float v11;      // [esp+1Ch] [ebp-4Ch]
  float v12;      // [esp+1Ch] [ebp-4Ch]
  float v13;      // [esp+20h] [ebp-48h]
  float v14;      // [esp+54h] [ebp-14h]
  float v15;      // [esp+58h] [ebp-10h]

  *(double *)&v9 = a1 * 0.0174532925199433;
  v4 = tan(v9);
  v14 = v4 * a4;
  v10 = randomf();
  v15 = randomf();
  v5 = (float)(v10 * 360.0) * 0.0174532925199433;
  v11 = cosf(v5);
  v13 = (float)(v11 * v15) * v14;
  v12 = sinf(v5);
  v6 = (float)(v12 * v15) * v14;
  *a2 = (float)(a4 * a3->forward[0]) + a3->muzzleTrace[0];
  a2[1] = (float)(a4 * a3->forward[1]) + a3->muzzleTrace[1];
  a2[2] = (float)(a4 * a3->forward[2]) + a3->muzzleTrace[2];
  *a2 = (float)(v13 * a3->right[0]) + *a2;
  a2[1] = (float)(v13 * a3->right[1]) + a2[1];
  v7 = (float)(v13 * a3->right[2]) + a2[2];
  a2[2] = v7;
  result = a3->up;
  *a2 = (float)(v6 * a3->up[0]) + *a2;
  a2[1] = (float)(v6 * a3->up[1]) + a2[1];
  a2[2] = (float)(v6 * a3->up[2]) + v7;
  return result;
}

void __cdecl G_SetEquippedOffHand(int clientNum, int offHandIndex)
{
  char *v2; // eax

  v2 = va("%c %i", 67, a2);
  SV_GameSendServerCommand(a1, SV_CMD_RELIABLE, v2);
}

void __cdecl G_SelectWeaponIndex(int clientNum, int iWeaponIndex)
{
  char *v2; // eax

  v2 = va("%c %i", 97, a2);
  SV_GameSendServerCommand(a1, SV_CMD_RELIABLE, v2);
}

int __cdecl G_GivePlayerWeapon(struct playerState_s *pPS, int iWeaponIndex)
{
  int v2;                         // ebx
  char v3;                        // si
  _DWORD *WeaponDef;              // edx
  int v6;                         // eax
  int v7;                         // esi
  uint32_t clientNum;             // ebx
  uint32_t FirstAvailableOffhand; // eax
  char *v10;                      // eax
  int v11;                        // edx
  char v12;                       // bl
  int v13;                        // eax
  int v14;                        // [esp+1Ch] [ebp-2Ch]
  uint8_t *weapons;               // [esp+28h] [ebp-20h]
  uint8_t *v16;                   // [esp+2Ch] [ebp-1Ch]

  weapons = a1->weapons;
  v2 = 4 * (a2 >> 5);
  v3 = a2 & 0x1F;
  if (((*(int *)&a1->weapons[v2] >> (a2 & 0x1F)) & 1) != 0)
    return 0;
  WeaponDef = (_DWORD *)BG_GetWeaponDef(a2);
  v6 = WeaponDef[31];
  if (v6 == 7 || v6 == 8)
    return 0;
  *(_DWORD *)&weapons[v2] |= 1 << v3;
  v16 = &a1->weaponrechamber[v2];
  v7 = ~(1 << v3);
  *(_DWORD *)v16 &= v7;
    if (WeaponDef[31] != 9) {
        if (!WeaponDef[33]) {
            if ((unsigned int)(WeaponDef[32] - 1) <= 1) {
                if (BYTE1(a1->weaponslots)) {
                  if (!BYTE2(a1->weaponslots))
                    BYTE2(a1->weaponslots) = a2;
                }
                else {
                  BYTE1(a1->weaponslots) = a2;
                }
            }
          v11 = WeaponDef[219];
            if (v11) {
              v14 = 4 * (v11 >> 5);
              v12 = v11 & 0x1F;
                if (((*(int *)&weapons[v14] >> (v11 & 0x1F)) & 1) == 0) {
                    while (1) {
                      *(_DWORD *)&weapons[v14] |= 1 << v12;
                      *(_DWORD *)v16 &= v7;
                      v11 = *(_DWORD *)(BG_GetWeaponDef(v11) + 876);
                      if (!v11)
                        break;
                      v14 = 4 * (v11 >> 5);
                      v12 = v11 & 0x1F;
                      if (((*(int *)&weapons[v14] >> (v11 & 0x1F)) & 1) != 0)
                        return 1;
                    }
                }
            }
          return 1;
        }
        if (a1->offHandIndex) {
          if (BG_WeaponAmmo(a1, a1->offHandIndex) > 0)
            return 1;
          v13 = BG_GetWeaponDef(a1->offHandIndex);
          FirstAvailableOffhand =
              BG_GetFirstAvailableOffhand(a1, *(_DWORD *)(v13 + 132));
          if (!FirstAvailableOffhand)
            FirstAvailableOffhand = a2;
          a1->offHandIndex = FirstAvailableOffhand;
          clientNum = a1->clientNum;
        }
        else {
          a1->offHandIndex = a2;
          clientNum = a1->clientNum;
          FirstAvailableOffhand = a2;
        }
      v10 = va("%c %i", 67, FirstAvailableOffhand);
      SV_GameSendServerCommand(clientNum, SV_CMD_RELIABLE, v10);
    }
  return 1;
}

int __cdecl G_GetWeaponIndexForName(char const *)
{
  if (dword_193449C)
    return BG_GetWeaponIndexForName(a1, (void (*)(int))G_RegisterWeapon);
  else
    return BG_FindWeaponIndexForName(a1);
}

void __cdecl G_SetupWeaponDef()
{
  Com_DPrintf("----------------------\n");
  Com_DPrintf("Game: G_SetupWeaponDef\n");
    if (!bg_iNumWeapons) {
      SV_SetWeaponInfoMemory();
      ClearRegisteredItems();
      BG_ClearWeaponDef(a1, a2, a3, a4, a5, a6, a7);
      BG_FillInAmmoItems(a1, a2, a3, a4, a5, a6, a7,
                         (void (*)(int))G_RegisterWeapon);
      if (dword_193449C)
        BG_GetWeaponIndexForName("defaultweapon_mp",
                                 (void (*)(int))G_RegisterWeapon);
      else
        BG_FindWeaponIndexForName("defaultweapon_mp");
    }
  Com_DPrintf("----------------------\n");
}

void __cdecl Weapon_RocketLauncher_Fire(struct gentity_s *ent, float spread,
                                        struct weaponParms *wp)
{
  float v3;          // xmm0_4
  float v4;          // xmm0_4
  float v5;          // xmm2_4
  float v6;          // xmm0_4
  gentity_s *result; // eax
  float *client;     // edx
  long double v9;    // [esp+0h] [ebp-98h]
  float v10;         // [esp+1Ch] [ebp-7Ch]
  float v11;         // [esp+1Ch] [ebp-7Ch]
  float v12;         // [esp+1Ch] [ebp-7Ch]
  float v13;         // [esp+20h] [ebp-78h]
  float v14;         // [esp+54h] [ebp-44h]
  float v15;         // [esp+58h] [ebp-40h]
  float v16[3];      // [esp+68h] [ebp-30h] BYREF
  float v17;         // [esp+74h] [ebp-24h] BYREF
  float v18;         // [esp+78h] [ebp-20h]
  float v19;         // [esp+7Ch] [ebp-1Ch]

  *(double *)&v9 = a2 * 0.0174532925199433;
  v3 = tan(v9);
  v14 = 16.0 * v3;
  v10 = randomf();
  v15 = randomf();
  v4 = (float)(v10 * 360.0) * 0.0174532925199433;
  v11 = cosf(v4);
  v13 = (float)(v11 * v15) * v14;
  v12 = sinf(v4);
  v5 = (float)(v12 * v15) * v14;
  v17 = a3->forward[0] * 16.0;
  v18 = a3->forward[1] * 16.0;
  v19 = 16.0 * a3->forward[2];
  v17 = (float)(v13 * a3->right[0]) + v17;
  v18 = (float)(v13 * a3->right[1]) + v18;
  v19 = (float)(v13 * a3->right[2]) + v19;
  v17 = (float)(v5 * a3->up[0]) + v17;
  v18 = (float)(v5 * a3->up[1]) + v18;
  v6 = v18;
  v19 = (float)(v5 * a3->up[2]) + v19;
  Vec3Normalize(&v17);
  v16[0] = a3->muzzleTrace[0];
  v16[1] = a3->muzzleTrace[1];
  v16[2] = a3->muzzleTrace[2];
  result = fire_rocket(v6, a1, v16, &v17);
  client = (float *)a1->client;
    if (client) {
      result = (gentity_s *)(client + 8);
      client[8] = (float)(a3->forward[0] * -64.0) + client[8];
      client[9] = (float)(a3->forward[1] * -64.0) + client[9];
      client[10] = (float)(-64.0 * a3->forward[2]) + client[10];
    }
  return result;
}

struct gentity_s *__cdecl weapon_grenadelauncher_fire(struct gentity_s *ent,
                                                      int grenType,
                                                      struct weaponParms *wp)
{
  int *weapDef;  // eax
  float v4;      // xmm0_4
  gentity_s *v5; // ebx
  float v6;      // xmm1_4
  float v8;      // [esp+24h] [ebp-24h] BYREF
  float v9;      // [esp+28h] [ebp-20h]
  float v10;     // [esp+2Ch] [ebp-1Ch]

  weapDef = (int *)a3->weapDef;
  v4 = (float)weapDef[225];
  v8 = v4 * a3->forward[0];
  v9 = v4 * a3->forward[1];
  v10 = v4 * a3->forward[2];
  v10 = (float)weapDef[226] + v10;
  v5 = fire_grenade(v10, a1, a3->muzzleTrace, &v8, a2, weapDef[146]);
  Vec3Normalize(&v8);
  v6 = (float)((float)(v8 * *(float *)(a1->client + 32)) +
               (float)(*(float *)(a1->client + 36) * v9)) +
       (float)(*(float *)(a1->client + 40) * v10);
  v5->s.pos.trDelta[0] = (float)(v8 * v6) + v5->s.pos.trDelta[0];
  v5->s.pos.trDelta[1] = (float)(v6 * v9) + v5->s.pos.trDelta[1];
  v5->s.pos.trDelta[2] = (float)(v6 * v10) + v5->s.pos.trDelta[2];
  return v5;
}

void __cdecl G_UseOffHand(struct gentity_s *ent)
{
  _DWORD *client; // edx
  weaponParms v3; // [esp+14h] [ebp-54h] BYREF
  int v4;         // [esp+54h] [ebp-14h] BYREF
  int v5;         // [esp+58h] [ebp-10h]
  int v6;         // [esp+5Ch] [ebp-Ch]

  v3.weapDef = BG_GetWeaponDef(*(_DWORD *)(a1->client + 208));
  client = (_DWORD *)a1->client;
  v4 = client[58];
  v5 = client[59];
  v6 = client[60];
  v4 = client[2550];
  v5 = client[2551];
  AngleVectors((float *)&v4, v3.forward, v3.right, v3.up);
  G_GetPlayerViewOrigin(a1, v3.muzzleTrace);
  return weapon_grenadelauncher_fire(a1, *(_DWORD *)(a1->client + 208), &v3);
}

void __cdecl Weapon_Melee(struct gentity_s *ent, struct weaponParms *wp,
                          float range, float width, float height)
{
  gentity_s *v12;          // esi
  gentity_s *v13;          // ebx
  hitLocation_t partGroup; // ebx
  int v15;                 // [esp+3Ch] [ebp-5Ch]
  int v16;                 // [esp+4Ch] [ebp-4Ch]
  trace_t v17;             // [esp+50h] [ebp-48h] BYREF
  float v18[9];            // [esp+74h] [ebp-24h] BYREF

  v16 = *(_DWORD *)(BG_GetWeaponDef(a8->s.weapon) + 500);
    if ((unsigned __int8)Melee_Trace(a8, a9, v16, a10, a11, a12, &v17, v18)) {
      v12 = &g_entities + v17.entityNum;
      if (v12->client)
        v13 = G_TempEntity(v18, 173);
      else
        v13 = G_TempEntity(v18, 174);
      v13->s.otherEntityNum = v17.entityNum;
      v13->s.eventParm = (unsigned __int8)DirToByte(v17.normal);
      v13->s.weapon = a8->s.weapon;
        if (v17.entityNum != 1022) {
            if (v12->takedamage) {
              partGroup = (unsigned __int16)v17.partGroup;
              v15 = rand() % 5;
              G_Damage(a1, a2, a3, a4, a5, a6, a7, v12, a8, a8, a9->forward,
                       v18, v16 + v15, 0, 7u, partGroup, 0);
            }
        }
    }
}

void __cdecl FireWeaponMelee(struct gentity_s *ent)
{
  weaponParms v8; // [esp+20h] [ebp-48h] BYREF

    if ((*(_DWORD *)(a8->client + 160) & 0x300) == 0 || !a8->active) {
      v8.weapDef = BG_GetWeaponDef(a8->s.weapon);
      G_GetPlayerViewOrigin(a8, v8.muzzleTrace);
      G_GetPlayerViewDirection(a8, v8.forward, v8.right, v8.up);
      Weapon_Melee(a1, a2, a3, a4, a5, a6, a7, a8, &v8,
                   *(float *)(player_meleeRange + 8),
                   *(float *)(player_meleeWidth + 8),
                   *(float *)(player_meleeHeight + 8));
    }
}

void __cdecl Bullet_Fire(struct gentity_s *attacker, float spread,
                         struct weaponParms *wp, struct gentity_s *weaponEnt,
                         int gametime)
{
  UNIMPLEMENTED();
}

void __cdecl FireWeaponAntiLag(struct gentity_s *ent, int gametime)
{
  UNIMPLEMENTED();
}

void __cdecl FireWeapon(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl gunrandom(float *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl G_AntiLag_RestoreClientPos(struct AntilagClientStore *)
{
  UNIMPLEMENTED();
}

void __cdecl CalcMuzzlePoints(struct gentity_s const *, struct weaponParms *)
{
  UNIMPLEMENTED();
}

void __cdecl G_AntiLagRewindClientPos(int, struct AntilagClientStore *)
{
  UNIMPLEMENTED();
}

void __cdecl Bullet_Fire_Extended(struct gentity_s const *, struct gentity_s *,
                                  float *const, float *const, float, int,
                                  struct weaponParms const *,
                                  struct gentity_s const *, int)
{
  int v11;                // edx
  int v12;                // eax
  unsigned __int8 *v13;   // eax
  float v14;              // xmm1_4
  float v15;              // xmm0_4
  gentity_s *v16;         // esi
  long double v17;        // fst7
  float v18;              // xmm0_4
  __m128 v19;             // xmm3
  __m128 v20;             // xmm4
  __m128 v21;             // xmm2
  __m128 v22;             // xmm1
  int v23;                // eax
  float v24;              // xmm0_4
  int v25;                // edx
  int v26;                // eax
  float v27;              // xmm1_4
  float v28;              // xmm2_4
  float v29;              // xmm1_4
  float v30;              // xmm2_4
  uint32_t v31;           // eax
  int v32;                // [esp+14h] [ebp-A4h]
  int v33;                // [esp+14h] [ebp-A4h]
  const weaponParms *v34; // [esp+18h] [ebp-A0h]
  const weaponParms *v35; // [esp+18h] [ebp-A0h]
  const gentity_s *v36;   // [esp+1Ch] [ebp-9Ch]
  const gentity_s *v37;   // [esp+1Ch] [ebp-9Ch]
  int v38;                // [esp+20h] [ebp-98h]
  int v39;                // [esp+20h] [ebp-98h]
  gentity_s *v43;         // [esp+44h] [ebp-74h]
  int v44;                // [esp+48h] [ebp-70h]
  unsigned int v45;       // [esp+4Ch] [ebp-6Ch]
  float *v46;             // [esp+50h] [ebp-68h]
  float *v47;             // [esp+58h] [ebp-60h]
  trace_t v48;            // [esp+64h] [ebp-54h] BYREF
  float v49;              // [esp+88h] [ebp-30h] BYREF
  float v50;              // [esp+8Ch] [ebp-2Ch]
  float v51;              // [esp+90h] [ebp-28h]
  float v52;              // [esp+94h] [ebp-24h] BYREF
  float v53;              // [esp+98h] [ebp-20h]
  float v54;              // [esp+9Ch] [ebp-1Ch]

    if ((int)a7 > 12) {
      Com_DPrintf(
          "Bullet_Fire_Extended: Too many resursions, bullet aborted\n");
      return;
    }
  v11 = *((_DWORD *)a8 + 15);
    if (*(_DWORD *)(v11 + 796)) {
      v45 = 2;
      v12 = 34;
      if (!*(_DWORD *)(v11 + 800))
        v12 = 32;
      v44 = v12;
      v13 = (unsigned __int8 *)&riflePriorityMap;
    }
    else {
      v45 = 1;
      v26 = 2;
      if (!*(_DWORD *)(v11 + 800))
        v26 = 0;
      v44 = v26;
      v13 = bulletPriorityMap;
    }
  G_LocationalTrace(&v48, a3, (float *)&a6->s.number, *a1,
                    (const float *)0x2802831, v13);
  v52 = *a3 + (float)((float)(*(float *)&a6->s.number - *a3) * v48.fraction);
  v46 = a3 + 1;
  v53 = a3[1] + (float)((float)(*(float *)&a6->s.eType - a3[1]) * v48.fraction);
  v47 = a3 + 2;
  v14 = a3[2];
  v15 = *(float *)&a6->s.eFlags - v14;
  v54 = v14 + (float)(v48.fraction * v15);
  G_CheckHitTriggerDamage(v15, a2, a3, &v52,
                          *(_DWORD *)(*((_DWORD *)a8 + 15) + 492), v45);
  v16 = &g_entities + v48.entityNum;
  v49 = *(float *)&a6->s.number - *a3;
  v50 = *(float *)&a6->s.eType - a3[1];
  v51 = *(float *)&a6->s.eFlags - a3[2];
  v17 = Vec3Normalize(&v49);
  v19 = (__m128)LODWORD(v48.normal[0]);
  v20 = (__m128)LODWORD(v48.normal[2]);
  v18 = (float)((float)((float)(v49 * v48.normal[0]) +
                        (float)(v48.normal[1] * v50)) +
                (float)(v48.normal[2] * v51)) *
        -2.0;
  v19.f32[0] = v48.normal[0] * v18;
  v49 = v49 + (float)(v48.normal[0] * v18);
  v50 = (float)(v48.normal[1] * v18) + v50;
  v20.f32[0] = (float)(v48.normal[2] * v18) + v51;
  v51 = v20.f32[0];
    if ((v48.surfaceFlags & 4) == 0 && !v16->client && v48.fraction < 1.0) {
      v43 = G_TempEntity(&v52,
                         183 - (*(_DWORD *)(*((_DWORD *)a8 + 15) + 796) == 0));
      v43->s.eventParm = (unsigned __int8)DirToByte(v48.normal);
      v43->s.unnamed_field.scale = (unsigned __int8)DirToByte(&v49);
      if (v16->s.eType == 2)
        v31 = 7;
      else
        v31 = (v48.surfaceFlags & 0x1F00000) >> 20;
      v43->s.surfType = v31;
      v43->s.otherEntityNum = *(uint32_t *)a9;
    }
    if ((v48.contents & 0x10) == 0) {
      if (!v16->takedamage || a2 == v16)
        return;
      v22 = (__m128) * (unsigned int *)v46;
      v21 = (__m128) * (unsigned int *)v47;
      v21.f32[0] = (float)(v21.f32[0] - v54) * (float)(v21.f32[0] - v54);
      v22.f32[0] =
          fsqrt((float)((float)((float)(*a3 - v52) * (float)(*a3 - v52)) +
                        (float)((float)(v22.f32[0] - v53) *
                                (float)(v22.f32[0] - v53))) +
                v21.f32[0]);
      v23 = *((_DWORD *)a8 + 15);
      v24 = *(float *)(v23 + 1432);
      if (v24 > v22.f32[0])
        goto LABEL_12;
      v21 = (__m128) * (unsigned int *)(v23 + 1436);
        if (v21.f32[0] <= v22.f32[0]) {
          v25 = *(_DWORD *)(v23 + 1424);
          goto LABEL_13;
        }
      v21.f32[0] = v21.f32[0] - v24;
        if (v21.f32[0] == 0.0) {
        LABEL_12:
          v25 = *(_DWORD *)(v23 + 492);
        }
        else {
          v29 = (float)(v22.f32[0] - v24) / v21.f32[0];
          v30 = (float)*(int *)(v23 + 492) * (float)(1.0 - v29);
          v22.f32[0] = v29 * (float)*(int *)(v23 + 1424);
          v21.f32[0] = v30 + v22.f32[0];
          v25 = (int)v21.f32[0];
        }
    LABEL_13:
      G_Damage(v17, (float)v25 * a4, v22, v21, v19, v20, a5, v16, a2, a2, a8,
               &v52, (int)(float)((float)v25 * a4), v44, v45,
               (hitLocation_t)(unsigned __int16)v48.partGroup,
               dword_193466C - LODWORD(a10));
      if (v16->client && (v44 & 0x20) != 0 &&
          (Dvar_GetInt("scr_friendlyfire") || !OnSameTeam(v16, a2)))
        Bullet_Fire_Extended(a6, (gentity_s *)((char *)&a7->s.number + 1), a8,
                             a9, a10, v33, v35, v37, v39);
      return;
    }
  v49 = *(float *)&a6->s.number - *a3;
  v50 = *(float *)&a6->s.eType - *v46;
  v51 = *(float *)&a6->s.eFlags - *v47;
  Vec3Normalize(&v49);
  v27 = -(float)((float)((float)(v49 * v48.normal[0]) +
                         (float)(v48.normal[1] * v50)) +
                 (float)(v48.normal[2] * v51));
  v28 = 0.0;
  if (v27 >= 0.125)
    v28 = 0.25 / v27;
  *a3 = (float)(v49 * v28) + v52;
  a3[1] = (float)(v28 * v50) + v53;
  a3[2] = (float)(v28 * v51) + v54;
  Bullet_Fire_Extended(a6, (gentity_s *)((char *)&a7->s.number + 1), a8, a9,
                       a10, v32, v34, v36, v38);
}

bool __cdecl Melee_Trace(struct gentity_s *, struct weaponParms *, int, float,
                         float, float, struct trace_t *, float *const)
{
  int v8;             // edi
  float *v9;          // esi
  float *right;       // eax
  float *i;           // edx
  float v12;          // xmm1_4
  float v13;          // xmm1_4
  float fraction;     // xmm2_4
  float v15;          // xmm1_4
  float v16;          // xmm0_4
  float *muzzleTrace; // [esp+28h] [ebp-40h]
  int v19;            // [esp+30h] [ebp-38h]
  float v20;          // [esp+44h] [ebp-24h] BYREF
  float v21;          // [esp+48h] [ebp-20h]
  float v22;          // [esp+4Ch] [ebp-1Ch]

  if (a5 <= 0.0 && a6 <= 0.0)
    v19 = 1;
  else
    v19 = 5;
  v8 = 0;
  v9 = (float *)&Melee_Trace(gentity_s *, weaponParms *, int, float, float,
                             float, trace_t *, float *)::traceOffsets;
  muzzleTrace = a2->muzzleTrace;
  right = a2->right;
    for (i = a2->up;; i = a2->up) {
      v20 = (float)(a4 * a2->forward[0]) + a2->muzzleTrace[0];
      v21 = (float)(a4 * a2->forward[1]) + a2->muzzleTrace[1];
      v22 = (float)(a4 * a2->forward[2]) + a2->muzzleTrace[2];
      v12 = a5 * *v9;
      v20 = (float)(v12 * a2->right[0]) + v20;
      v21 = (float)(v12 * right[1]) + v21;
      v22 = (float)(v12 * right[2]) + v22;
      v13 = a6 * v9[1];
      v20 = (float)(v13 * a2->up[0]) + v20;
      v21 = (float)(v13 * i[1]) + v21;
      v22 = (float)(v13 * i[2]) + v22;
      G_LocationalTrace(a7, muzzleTrace, &v20, a1->s.number,
                        (const float *)0x2802831, bulletPriorityMap);
      fraction = a7->fraction;
      *a8 = a2->muzzleTrace[0] +
            (float)((float)(v20 - a2->muzzleTrace[0]) * a7->fraction);
      a8[1] = a2->muzzleTrace[1] +
              (float)((float)(v21 - a2->muzzleTrace[1]) * fraction);
      v15 = a2->muzzleTrace[2];
      v16 = v22 - v15;
      a8[2] = v15 + (float)(fraction * (float)(v22 - v15));
      if (!v8)
        G_CheckHitTriggerDamage(v16, a1, muzzleTrace, a8, a3, 7u);
      if ((a7->surfaceFlags & 0x10) == 0 && a7->fraction != 1.0)
        break;
      ++v8;
      v9 += 2;
      if (v19 == v8)
        return 0;
      right = a2->right;
    }
  return 1;
}

void __cdecl G_BulletFireSpread(struct gentity_s const *, struct gentity_s *,
                                struct weaponParms const *, int, float)
{
  UNIMPLEMENTED();
}
