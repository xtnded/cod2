void __cdecl Player_UpdateActivate(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl Player_UpdateLookAtEntity(struct gentity_s *) {
  _DWORD *client;      // esi
  unsigned __int8 *v2; // edi
  gentity_s *v3;       // ecx
  float v4;            // xmm1_4
  float v5;            // xmm2_4
  float v6;            // xmm3_4
  int v7;              // eax
  int32_t v8;          // edx
  float v9;            // xmm1_4
  int WeaponDef;       // [esp+24h] [ebp-84h]
  float Visibility;    // [esp+28h] [ebp-80h]
  float v12;           // [esp+2Ch] [ebp-7Ch]
  trace_t v13;         // [esp+3Ch] [ebp-6Ch] BYREF
  float v14;           // [esp+60h] [ebp-48h] BYREF
  float v15;           // [esp+64h] [ebp-44h]
  float v16;           // [esp+68h] [ebp-40h]
  float v17;           // [esp+6Ch] [ebp-3Ch] BYREF
  float v18;           // [esp+70h] [ebp-38h]
  float v19;           // [esp+74h] [ebp-34h]
  float v20[3];        // [esp+78h] [ebp-30h] BYREF
  float v21;           // [esp+84h] [ebp-24h] BYREF
  float v22;           // [esp+88h] [ebp-20h]
  float v23;           // [esp+8Ch] [ebp-1Ch]

  client = (_DWORD *)a1->client;
  client[3] &= 0xFFCFFFFF;
  *(_DWORD *)(a1->client + 10284) = 0;
  G_GetPlayerViewOrigin(a1, &v21);
  G_GetPlayerViewDirection(a1, &v17, 0, 0);
  if ((client[40] & 0x300) != 0)
    WeaponDef = BG_GetWeaponDef(
        *(_DWORD *)&g_entities.s.eventParms[560 * client[357] + 16]);
  else
    WeaponDef = BG_GetWeaponDef(*(_DWORD *)(a1->client + 212));
  if (*(_DWORD *)(a1->client + 212) && *(_DWORD *)(WeaponDef + 796))
    v2 = (unsigned __int8 *)&riflePriorityMap;
  else
    v2 = bulletPriorityMap;
  v20[0] = (float)(v17 * 15000.0) + v21;
  v20[1] = (float)(v18 * 15000.0) + v22;
  v20[2] = (float)(v19 * 15000.0) + v23;
  G_LocationalTrace(&v13, &v21, v20, a1->s.number, (const float *)0x22802801,
                    v2);
  if (v13.entityNum <= 0x3FDu) {
    v14 = (float)((float)(v13.fraction * 15000.0) * v17) + v21;
    v15 = (float)((float)(v13.fraction * 15000.0) * v18) + v22;
    v16 = (float)((float)(v13.fraction * 15000.0) * v19) + v23;
    Visibility = SV_FX_GetVisibility(&v21, &v14);
    if (Visibility >= 0.2) {
      v3 = &g_entities + v13.entityNum;
      if (v3) {
        if (*(_WORD *)v3->classname != word_195B0DC)
          goto LABEL_14;
        *(_DWORD *)(a1->client + 10284) = v3;
        G_Trigger(Visibility, v3, a1);
        G_LocationalTrace(&v13, &v21, v20, a1->s.number,
                          (const float *)0x2802801, v2);
        if (v13.entityNum <= 0x3FDu) {
          v14 = (float)((float)(15000.0 * v13.fraction) * v17) + v21;
          v15 = (float)((float)(15000.0 * v13.fraction) * v18) + v22;
          v16 = (float)((float)(15000.0 * v13.fraction) * v19) + v23;
          v12 = SV_FX_GetVisibility(&v21, &v14);
          if (v12 >= 0.2) {
            v3 = &g_entities + v13.entityNum;
            if (v3) {
            LABEL_14:
              if (v3->s.eType == 1 && (v13.surfaceFlags & 0x10) == 0) {
                v4 = v3->r.currentOrigin[0] - v21;
                v5 = v3->r.currentOrigin[1] - v22;
                v6 = v3->r.currentOrigin[2] - v23;
                v7 = *(_DWORD *)(v3->client + 10060);
                v8 = a1->client;
                if (v7 == *(_DWORD *)(v8 + 10060) && v7) {
                  v9 = (float)((float)(v4 * v4) + (float)(v5 * v5)) +
                       (float)(v6 * v6);
                  if ((float)(*(float *)(g_friendlyNameDist + 8) *
                              *(float *)(g_friendlyNameDist + 8)) > v9 &&
                      !*(_DWORD *)(v8 + 10284)) {
                    *(_DWORD *)(v8 + 10284) = v3;
                  }
                  if ((float)(*(float *)(g_friendlyfireDist + 8) *
                              *(float *)(g_friendlyfireDist + 8)) > v9)
                    client[3] |= 0x100000u;
                } else if ((float)(*(float *)(WeaponDef + 608) *
                                   *(float *)(WeaponDef + 608)) >
                           (float)((float)((float)(v4 * v4) +
                                           (float)(v5 * v5)) +
                                   (float)(v6 * v6))) {
                  if (!*(_DWORD *)(v8 + 10284))
                    *(_DWORD *)(v8 + 10284) = v3;
                  client[3] |= 0x200000u;
                }
              }
            }
          }
        }
      }
    }
  }
}

void __cdecl Player_UpdateCursorHints(struct gentity_s *ent) {
  _DWORD *client;         // ebx
  int32_t v2;             // esi
  gentity_s *v3;          // ebx
  __int16 v4;             // ax
  unsigned __int8 team;   // al
  int32_t eType;          // eax
  _DWORD *v7;             // esi
  int v8;                 // edx
  int v9;                 // esi
  int v10;                // edx
  int weapon;             // eax
  int32_t v12;            // eax
  int v13;                // edx
  int32_t v14;            // edx
  gentity_s *ent;         // [esp+10h] [ebp-2028h]
  int UseList;            // [esp+14h] [ebp-2024h]
  int v17;                // [esp+18h] [ebp-2020h]
  int32_t v18;            // [esp+1Ch] [ebp-201Ch]
  useList_t __base[1027]; // [esp+20h] [ebp-2018h] BYREF

  client = (_DWORD *)a1->client;
  client[358] = 0;
  client[359] = -1;
  client[360] = 1023;
  if (a1->health <= 0)
    return;
  v2 = a1->client;
  if ((unsigned int)(*(_DWORD *)(v2 + 216) - 17) <= 5)
    return;
  if (a1->active) {
    if ((client[40] & 0x300) != 0) {
      v3 = &dword_1934484[*(_DWORD *)(v2 + 1428)];
      if (**(_BYTE **)(BG_GetWeaponDef(v3->s.weapon) + 1392)) {
        *(_DWORD *)(v2 + 1440) = 1023;
        *(_DWORD *)(v2 + 1432) = v3->s.weapon + 4;
        *(_DWORD *)(v2 + 1436) =
            *(_DWORD *)(BG_GetWeaponDef(v3->s.weapon) + 1400);
      }
    }
    return;
  }
  if ((*(_BYTE *)(v2 + 12) & 4) != 0)
    return;
  UseList = Player_GetUseList(a1, __base);
  if (UseList <= 0)
    return;
  v17 = 0;
  while (1) {
    ent = (gentity_s *)__base[v17].ent;
    eType = ent->s.eType;
    if (eType == 3) {
      v18 = a1->client;
      v7 = &bg_itemlist[11 * ent->unnamed_field.item.index];
      if (v7[7] == 1 && *(_DWORD *)(BG_GetWeaponDef(v7[8]) + 120) != 1) {
        v8 = v7[8];
        if (((*(int *)(v18 + 4 * (v8 >> 5) + 1348) >> (v7[8] & 0x1F)) & 1) ==
                0 &&
            v8 != -4) {
          v9 = v8 + 4;
          v10 = -1;
          goto LABEL_24;
        }
      }
      goto LABEL_17;
    }
    if (eType == 9) {
      if (!G_IsTurretUsable(ent, a1))
        goto LABEL_17;
      weapon = ent->s.weapon;
      v9 = weapon + 4;
      if (**(_BYTE **)(BG_GetWeaponDef(weapon) + 1388)) {
        v10 = *(_DWORD *)(BG_GetWeaponDef(ent->s.weapon) + 1396);
        goto LABEL_24;
      }
    LABEL_28:
      v10 = -1;
      goto LABEL_24;
    }
    if (eType)
      goto LABEL_17;
    v4 = *(_WORD *)ent->classname;
    if (v4 != word_195B0D6 && v4 != word_195B0D8) {
      v9 = 0;
      v10 = -1;
      goto LABEL_24;
    }
    team = ent->team;
    if (team) {
      if (team != *(_DWORD *)(a1->client + 10060))
        goto LABEL_17;
      v12 = __base[v17].ent;
    } else {
      v12 = __base[v17].ent;
    }
    v13 = *(_DWORD *)(v12 + 436);
    if (v13 == 1023)
      break;
    if (v13 == *(_DWORD *)(a1->client + 204)) {
      v14 = __base[v17].ent;
      goto LABEL_34;
    }
  LABEL_17:
    if (UseList == ++v17)
      return;
  }
  v14 = v12;
LABEL_34:
  v9 = *(_DWORD *)(v14 + 220);
  if (!v9)
    goto LABEL_28;
  v10 = *(_DWORD *)(v14 + 216);
  if (v10 == 255)
    v10 = -1;
LABEL_24:
  client[360] = ent->s.number;
  client[358] = v9;
  client[359] = v10;
  if (!v9)
    client[360] = 1023;
}

int __cdecl compare_use(void const *, void const *) {
  return (int)(float)(a1[1] - a2[1]);
}

bool __cdecl Player_ActivateCmd(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl Player_SetTurretDropHint(struct gentity_s *) { UNIMPLEMENTED(); }

int __cdecl Player_GetItemCursorHint(struct gclient_s const *,
                                     struct gentity_s const *) {
  UNIMPLEMENTED();
}

void __cdecl Player_UseEntity(struct gentity_s *, struct gentity_s *) {
  UNIMPLEMENTED();
}

void __cdecl Player_ActivateHoldCmd(struct gentity_s *) { UNIMPLEMENTED(); }

struct gentity_s *__cdecl Player_UpdateLookAtEntityTrace(struct trace_t *,
                                                         float *const,
                                                         float *const, int, int,
                                                         unsigned char *,
                                                         float *const) {
  UNIMPLEMENTED();
}

int __cdecl Player_GetUseList(struct gentity_s *, struct useList_t *const) {
  size_t v2;      // eax
  int v4;         // esi
  useList_t *v5;  // edi
  gentity_s *v6;  // ebx
  float v7;       // xmm2_4
  float v8;       // xmm1_4
  float *p_ent;   // ebx
  int v10;        // edi
  gentity_s *v11; // ecx
  float v12;      // xmm1_4
  float v13;      // [esp+2Ch] [ebp-10ACh]
  int32_t client; // [esp+48h] [ebp-1090h]
  int v15;        // [esp+4Ch] [ebp-108Ch]
  int v16;        // [esp+50h] [ebp-1088h]
  int v17;        // [esp+54h] [ebp-1084h]
  int __nel;      // [esp+58h] [ebp-1080h]
  size_t v19;     // [esp+5Ch] [ebp-107Ch]
  int v20[1024];  // [esp+60h] [ebp-1078h] BYREF
  float v21;      // [esp+1060h] [ebp-78h] BYREF
  float v22;      // [esp+1064h] [ebp-74h]
  float v23;      // [esp+1068h] [ebp-70h]
  float v24[3];   // [esp+106Ch] [ebp-6Ch] BYREF
  float v25;      // [esp+1078h] [ebp-60h] BYREF
  float v26;      // [esp+107Ch] [ebp-5Ch]
  float v27;      // [esp+1080h] [ebp-58h]
  float v28;      // [esp+1084h] [ebp-54h] BYREF
  float v29;      // [esp+1088h] [ebp-50h]
  float v30;      // [esp+108Ch] [ebp-4Ch]
  float v31;      // [esp+1090h] [ebp-48h] BYREF
  float v32;      // [esp+1094h] [ebp-44h]
  float v33;      // [esp+1098h] [ebp-40h]
  float v34[3];   // [esp+109Ch] [ebp-3Ch] BYREF
  float v35[3];   // [esp+10A8h] [ebp-30h] BYREF
  float v36;      // [esp+10B4h] [ebp-24h] BYREF
  float v37;      // [esp+10B8h] [ebp-20h]
  float v38;      // [esp+10BCh] [ebp-1Ch]

  client = a1->client;
  G_GetPlayerViewOrigin(a1, &v31);
  G_GetPlayerViewDirection(a1, v24, 0, 0);
  v21 = *(float *)(client + 20) + *(float *)(client + 1388);
  v22 = *(float *)(client + 24) + *(float *)(client + 1392);
  v23 = *(float *)(client + 28) + *(float *)(client + 1396);
  v36 = *(float *)(client + 20) + *(float *)(client + 1400);
  v37 = *(float *)(client + 24) + *(float *)(client + 1404);
  v38 = *(float *)(client + 28) + *(float *)(client + 1408);
  v35[0] = v31 - 192.0;
  v35[1] = v32 - 192.0;
  v35[2] = v33 - 96.0;
  v34[0] = v31 + 192.0;
  v34[1] = v32 + 192.0;
  v34[2] = v33 + 96.0;
  v15 = CM_AreaEntities(v35, v34, v20, 1024, 0x200000);
  if (v15 <= 0) {
    v2 = 0;
    __nel = 0;
    goto LABEL_3;
  }
  v4 = 0;
  v17 = 0;
  v19 = 0;
  v5 = __base;
  do {
    while (1) {
      v6 = &g_entities + v20[v4];
      if (a1 != v6 && (v6->s.eType == 3 || (v6->r.contents & 0x200000) != 0)) {
        if (*(_WORD *)v6->classname == word_195B0D8) {
          if (v6->r.absmin[0] <= v36 && v21 <= v6->r.absmax[0] &&
              v6->r.absmin[1] <= v37 && v22 <= v6->r.absmax[1] &&
              v6->r.absmin[2] <= v38 && v23 <= v6->r.absmax[2] &&
              SV_EntityContact(&v21, &v36, &g_entities + v20[v4])) {
            v5->score = -1015021568;
            v5->ent = (int32_t)v6;
            ++v19;
            ++v5;
          }
          goto LABEL_13;
        }
        v28 = v6->r.absmin[0] + v6->r.absmax[0];
        v29 = v6->r.absmin[1] + v6->r.absmax[1];
        v7 = v6->r.absmin[2] + v6->r.absmax[2];
        v28 = v28 * 0.5;
        v29 = v29 * 0.5;
        v30 = v7 * 0.5;
        v25 = v28 - v31;
        v26 = v29 - v32;
        v27 = (float)(v7 * 0.5) - v33;
        v13 = Vec3Normalize(&v25);
        if (v13 <= 128.0)
          break;
      }
    LABEL_13:
      if (v15 == ++v4)
        goto LABEL_14;
    }
    v8 = (float)((float)((float)((float)((float)((float)(v25 * v24[0]) +
                                                 (float)(v26 * v24[1])) +
                                         (float)(v27 * v24[2])) +
                                 1.0) *
                         -0.5) +
                 1.0) *
         256.0;
    *(float *)&v5->score = v8;
    if (*(_WORD *)v6->classname == word_195B0D6)
      *(float *)&v5->score = v8 - 256.0;
    if (v6->s.eType == 3 &&
        !BG_CanItemBeGrabbed(&v6->s, (const playerState_s *)a1->client, 0)) {
      *(float *)&v5->score = *(float *)&v5->score + 10000.0;
      ++v17;
    }
    v5->ent = (int32_t)v6;
    *(float *)&v5->score = v13 + *(float *)&v5->score;
    ++v19;
    ++v5;
    ++v4;
  } while (v15 != v4);
LABEL_14:
  v2 = v19;
  __nel = v19 - v17;
LABEL_3:
  qsort(__base, v2, 8u,
        (int(__cdecl *)(const void *, const void *))compare_use);
  if (__nel > 0) {
    p_ent = (float *)&__base->ent;
    v10 = 0;
    v16 = 0;
    do {
      v11 = *(gentity_s **)p_ent;
      if (*(_WORD *)(*(_DWORD *)p_ent + 360) != word_195B0D8) {
        v28 = v11->r.absmin[0] + v11->r.absmax[0];
        v29 = v11->r.absmin[1] + v11->r.absmax[1];
        v12 = v11->r.absmin[2] + v11->r.absmax[2];
        v28 = v28 * 0.5;
        v29 = v29 * 0.5;
        v30 = v12 * 0.5;
        if (v11->s.eType == 9)
          G_DObjGetWorldTagPos(v11, (unsigned __int16)word_195B11E, &v28);
        if (!G_TraceCapsuleComplete(&v31, vec3_origin, vec3_origin, &v28,
                                    *(_DWORD *)(client + 204), 17)) {
          p_ent[1] = p_ent[1] + 10000.0;
          ++v16;
        }
      }
      ++v10;
      p_ent += 2;
    } while (v10 != __nel);
  } else {
    v16 = 0;
  }
  qsort(__base, __nel, 8u,
        (int(__cdecl *)(const void *, const void *))compare_use);
  return __nel - v16;
}
