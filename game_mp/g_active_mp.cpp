int __cdecl GetFollowPlayerState(int clientNum, struct playerState_s *ps) {
  char *v2; // eax

  v2 = (char *)*(&g_entities.client + 140 * a1);
  if (v2[14] >= 0)
    return 0;
  memcpy(__dst, v2, sizeof(playerState_s));
  memset(&__dst->hud, 0, 0xF80u);
  return 1;
}

int __cdecl G_ClientCanSpectateTeam(struct gclient_s *client,
                                    enum team_t team) {
  return ((unsigned __int8)(*(int *)&a1->sess.noSpectate[2] >> a2) ^ 1) & 1;
}

void __cdecl G_SetClientContents(struct gentity_s *pEnt) {
  _DWORD *client; // edx
  int32_t result; // eax

  client = (_DWORD *)a1->client;
  result = client[2539];
  if (result || (result = client[2540]) != 0) {
    a1->r.contents = 0;
  } else {
    result = 0;
    if (client[2474] != 1)
      result = 0x2000000;
    a1->r.contents = result;
  }
  return result;
}

void __cdecl G_SetLastServerTime(int clientNum, int lastServerTime) {
  int v2;     // esi
  int result; // eax

  v2 = a2;
  if (dword_193466C - a2 >= 1001)
    v2 = dword_193466C - 1000;
  result = *(&g_entities.client + 140 * a1);
  if (v2 >= *(_DWORD *)(result + 10396) || v2 >= dword_193466C)
    *(_DWORD *)(result + 10396) = v2;
  return result;
}

void __cdecl ClientIntermissionThink(struct gentity_s *, struct usercmd_s *) {
  UNIMPLEMENTED();
}

void __cdecl G_SetClientSound(struct gentity_s *) { UNIMPLEMENTED(); }

int __cdecl StuckInClient(struct gentity_s *self) {
  int32_t client;   // eax
  int32_t contents; // eax
  int v4;           // ecx
  gentity_s *v5;    // esi
  int8_t *i;        // edx
  int v7;           // eax
  int v8;           // eax
  int32_t v9;       // ecx
  float v10;        // xmm2_4
  int32_t v11;      // edx
  float v12;        // xmm1_4
  int32_t v13;      // eax
  float v14;        // [esp+24h] [ebp-34h]
  float v15;        // [esp+2Ch] [ebp-2Ch]
  float v16;        // [esp+38h] [ebp-20h] BYREF
  float v17;        // [esp+3Ch] [ebp-1Ch]

  client = a1->client;
  if (*(char *)(client + 14) >= 0)
    return 0;
  if (*(_DWORD *)(client + 9896))
    return 0;
  contents = a1->r.contents;
  if (contents != 0x2000000 && contents != 0x4000000)
    return 0;
  if (dword_1934664 <= 0)
    return 0;
  v4 = 0;
  v5 = &g_entities;
  for (i = &g_entities.r.inuse;; i += 560) {
    if (*i) {
      v7 = *((_DWORD *)i + 23);
      if (*(char *)(v7 + 14) < 0 && !*(_DWORD *)(v7 + 9896) && a1 != v5 &&
          *((int *)i + 38) > 0) {
        v8 = *((_DWORD *)i + 8);
        if ((v8 == 0x2000000 || v8 == 0x4000000) &&
            *((float *)i + 9) <= a1->r.absmax[0] &&
            a1->r.absmin[0] <= *((float *)i + 12) &&
            *((float *)i + 10) <= a1->r.absmax[1] &&
            a1->r.absmin[1] <= *((float *)i + 13) &&
            *((float *)i + 11) <= a1->r.absmax[2] &&
            a1->r.absmin[2] <= *((float *)i + 14)) {
          v16 = v5->r.currentOrigin[0] - a1->r.currentOrigin[0];
          v17 = v5->r.currentOrigin[1] - a1->r.currentOrigin[1];
          if ((float)((float)(v16 * v16) + (float)(v17 * v17)) <=
              (float)((float)(a1->r.maxs[0] + *((float *)i + 5)) *
                      (float)(a1->r.maxs[0] + *((float *)i + 5))))
            break;
        }
      }
    }
    ++v4;
    ++v5;
    if (v4 == dword_1934664)
      return 0;
  }
  v16 = v5->r.currentOrigin[0] - a1->r.currentOrigin[0];
  v17 = v5->r.currentOrigin[1] - a1->r.currentOrigin[1];
  v14 = crandom();
  v16 = v16 + v14;
  v15 = crandom();
  v17 = v17 + v15;
  Vec2Normalize(&v16);
  v9 = v5->client;
  if (fsqrt((float)(*(float *)(v9 + 32) * *(float *)(v9 + 32)) +
            (float)(*(float *)(v9 + 36) * *(float *)(v9 + 36))) <= 0.0)
    v10 = 0.0;
  else
    v10 = (float)*(int *)(g_playerCollisionEjectSpeed + 8);
  v11 = a1->client;
  if (fsqrt((float)(*(float *)(v11 + 32) * *(float *)(v11 + 32)) +
            (float)(*(float *)(v11 + 36) * *(float *)(v11 + 36))) <= 0.0)
    v12 = 0.0;
  else
    v12 = (float)*(int *)(g_playerCollisionEjectSpeed + 8);
  if (v10 < 0.000099999997 && v12 < 0.000099999997) {
    v10 = (float)*(int *)(v9 + 80);
    v12 = (float)*(int *)(v11 + 80);
  }
  *(float *)(v9 + 32) = v10 * v16;
  *(float *)(v9 + 36) = v10 * v17;
  *(_DWORD *)(v5->client + 16) = 300;
  *(_DWORD *)(v5->client + 12) |= 0x200u;
  v13 = a1->client;
  *(float *)(v13 + 32) = (float)-v12 * v16;
  *(float *)(v13 + 36) = (float)-v12 * v17;
  *(_DWORD *)(a1->client + 16) = 300;
  *(_DWORD *)(a1->client + 12) |= 0x200u;
  return 1;
}

void __cdecl G_PlayerEvent(int, int) {
  float *result; // eax
  int v3;        // edx
  char v4;       // cl
  float v5[5];   // [esp+14h] [ebp-14h] BYREF

  result = (float *)(&g_entities.s.number + 140 * a1);
  v3 = *((_DWORD *)result + 86);
  v4 = a2 + 98;
  if ((unsigned int)(a2 - 158) <= 0x11) {
    result = (float *)(1 << v4);
    if (((1 << v4) & 0x20007) != 0)
      return BG_WeaponFireRecoil((const playerState_s *)v3,
                                 (float *)(v3 + 10380), v5);
  }
  return result;
}

void __cdecl P_DamageFeedback(struct gentity_s *player) {
  int result;     // eax
  int32_t client; // ebx
  int v3;         // edx
  int v4;         // eax
  int v5;         // esi
  float v6;       // xmm1_4
  float v7;       // xmm0_4
  float v8;       // xmm1_4
  float v9;       // xmm1_4
  float v10;      // xmm4_4
  float v11;      // xmm3_4
  float v12;      // [esp+18h] [ebp-50h]
  float v13;      // [esp+1Ch] [ebp-4Ch]
  float v14[9];   // [esp+20h] [ebp-48h] BYREF
  float v15[9];   // [esp+44h] [ebp-24h] BYREF

  result = (int)a1;
  client = a1->client;
  if (*(int *)(client + 4) <= 5) {
    *(_DWORD *)(client + 296) = 0;
    result = *(_DWORD *)(client + 10208);
    if (result > 0) {
      v3 = *(_DWORD *)(client + 10024);
      if (v3 > 0) {
        v4 = 100 * result / v3;
        v5 = v4;
        if (v4 <= 127) {
          v6 = (float)v4;
        } else {
          v5 = 127;
          v6 = 127.0;
        }
        v7 = v6 + *(float *)(client + 1492);
        *(float *)(client + 1492) = v7;
        if (v7 > 255.0)
          *(_DWORD *)(client + 1492) = 1132396544;
        v8 = v6 * 0.2;
        v12 = v8;
        if (v8 >= 5.0) {
          if (v8 <= 90.0) {
            v13 = -v8;
            if (*(_DWORD *)(client + 10224))
              goto LABEL_11;
            goto LABEL_17;
          }
          v12 = 90.0;
          v13 = -90.0;
        } else {
          v12 = 5.0;
          v13 = -5.0;
        }
        if (*(_DWORD *)(client + 10224)) {
        LABEL_11:
          *(_DWORD *)(client + 10308) = 0;
          *(float *)(client + 10312) = v13;
          *(_DWORD *)(client + 292) = 255;
          *(_DWORD *)(client + 288) = 255;
          *(_DWORD *)(client + 10224) = 0;
        LABEL_12:
          ++*(_DWORD *)(client + 284);
          result = dword_193466C - 20;
          *(_DWORD *)(client + 10304) = dword_193466C - 20;
          *(_DWORD *)(client + 296) = v5;
          *(_DWORD *)(client + 10208) = 0;
          return result;
        }
      LABEL_17:
        vectoangles((float *)(client + 10212), v15);
        AnglesToAxis((float *)(client + 232), v14);
        v9 = *(float *)(client + 10212);
        v10 = *(float *)(client + 10216);
        v11 = *(float *)(client + 10220);
        *(float *)(client + 10308) =
            (float)((float)((float)(v9 * v14[3]) + (float)(v10 * v14[4])) +
                    (float)(v11 * v14[5])) *
            v13;
        *(float *)(client + 10312) =
            (float)((float)((float)(v9 * v14[0]) + (float)(v10 * v14[1])) +
                    (float)(v11 * v14[2])) *
            v12;
        *(_DWORD *)(client + 292) =
            (int)(float)((float)(v15[0] / 360.0) * 256.0);
        *(_DWORD *)(client + 288) =
            (int)(float)((float)(v15[1] / 360.0) * 256.0);
        goto LABEL_12;
      }
    }
  }
  return result;
}

void __cdecl G_PlayerController(struct gentity_s *self, int *const partBits) {
  clientInfo_t *v2;   // ebx
  int v3;             // edi
  DObj_s *ServerDObj; // eax

  v2 = (clientInfo_t *)((char *)&level_bgs + 1208 * a1->s.clientNum + 736252);
  bgs = (int)&level_bgs;
  v3 = dword_1934674;
  ServerDObj = Com_GetServerDObj(a1->s.number);
  return BG_Player_DoControllers(ServerDObj, &a1->s, a2, v2, v3);
}

void __cdecl IntermissionClientEndFrame(struct gentity_s *ent) {
  UNIMPLEMENTED();
}

void __cdecl G_TouchTriggers(struct gentity_s *ent) {
  char **result;                                    // eax
  int32_t client;                                   // edx
  float *v3;                                        // edx
  float v4;                                         // xmm0_4
  int i;                                            // ebx
  gentity_s *v6;                                    // esi
  int(__cdecl * v7)(gentity_s *, gentity_s *, int); // edi
  int v8;                                           // [esp+28h] [ebp-1040h]
  int v9;                                           // [esp+2Ch] [ebp-103Ch]
  int v10[1024]; // [esp+38h] [ebp-1030h] BYREF
  float v11;     // [esp+1038h] [ebp-30h] BYREF
  float v12;     // [esp+103Ch] [ebp-2Ch]
  float v13;     // [esp+1040h] [ebp-28h]
  float v14;     // [esp+1044h] [ebp-24h] BYREF
  float v15;     // [esp+1048h] [ebp-20h]
  float v16;     // [esp+104Ch] [ebp-1Ch]

  result = (char **)a1;
  client = a1->client;
  if (*(int *)(client + 4) <= 1) {
    v14 = *(float *)(client + 20) -
          *(float *)&G_TouchTriggers(gentity_s *)::range;
    v15 = *(float *)(client + 24) - *(float *)&dword_313C64;
    v16 = *(float *)(client + 28) - *(float *)&dword_313C68;
    v11 = *(float *)&G_TouchTriggers(gentity_s *)::range +
          *(float *)(client + 20);
    v12 = *(float *)&dword_313C64 + *(float *)(client + 24);
    v13 = *(float *)&dword_313C68 + *(float *)(client + 28);
    v8 = CM_AreaEntities(&v14, &v11, v10, 1024, 1079771144);
    v3 = (float *)(a1->client + 20);
    v14 = *v3 + a1->r.mins[0];
    v15 = v3[1] + a1->r.mins[1];
    v16 = v3[2] + a1->r.mins[2];
    v11 = *v3 + a1->r.maxs[0];
    v12 = v3[1] + a1->r.maxs[1];
    v4 = v3[2] + a1->r.maxs[2];
    v13 = v4;
    ShrinkBoundsToHeight(&v14, &v11);
    v9 = entityHandlers[10 * (unsigned __int8)a1->handler + 3];
    result = (char **)v8;
    if (v8 > 0) {
      for (i = 0; v8 != i; ++i) {
        v6 = &g_entities + v10[i];
        v7 = (int(__cdecl *)(gentity_s *, gentity_s *, int))
            entityHandlers[10 * (unsigned __int8)v6->handler + 3];
        if (!v7) {
          result = (char **)v9;
          if (!v9)
            continue;
        }
        if (v6->s.eType == 3) {
          result = (char **)BG_PlayerTouchesItem((playerState_s *)a1->client,
                                                 &v6->s, dword_193466C);
          if (result) {
            result = (char **)Scr_IsSystemActive();
            if (result) {
            LABEL_14:
              Scr_AddEntity(v4, a1);
              Scr_Notify(v4, v6, word_195B0D2, 1u);
              Scr_AddEntity(v4, v6);
              result = Scr_Notify(v4, a1, word_195B0D2, 1u);
            }
          LABEL_7:
            if (v7)
              result = (char **)v7(v6, a1, 1);
          }
        } else {
          result = (char **)SV_EntityContact(&v14, &v11, &g_entities + v10[i]);
          if (result) {
            result = (char **)Scr_IsSystemActive();
            if (result)
              goto LABEL_14;
            goto LABEL_7;
          }
        }
      }
    }
  }
  return result;
}

void __cdecl ClientImpacts(struct gentity_s *, struct pmove_t *) {
  pmove_t *result;                                   // eax
  int v3;                                            // edi
  pmove_t *v4;                                       // ebx
  gentity_s *v5;                                     // esi
  void(__cdecl * v6)(gentity_s *, gentity_s *, int); // eax
  pmove_t *v7;                                       // edx
  pmove_t *v8;                                       // ecx
  int v9;                                            // edx
  pmove_t *v10;                                      // [esp+18h] [ebp-20h]
  pmove_t *v11;                                      // [esp+1Ch] [ebp-1Ch]

  v10 = (pmove_t *)entityHandlers[10 * (unsigned __int8)a1->handler + 3];
  result = a2;
  if ((int)a2->numtouch > 0) {
    v11 = a2;
    v3 = 0;
    v4 = *(pmove_t **)a2->touchents;
  LABEL_3:
    v5 = &g_entities + (_DWORD)v4;
    if (Scr_IsSystemActive(1u)) {
      Scr_AddEntity(&g_entities + (_DWORD)v4);
      Scr_Notify(a1, word_195B0D2, 1u);
      Scr_AddEntity(a1);
      Scr_Notify(v5, word_195B0D2, 1u);
    }
    v6 = (void(__cdecl *)(gentity_s *, gentity_s *, int))
        entityHandlers[10 * (unsigned __int8)v5->handler + 3];
    if (v6)
      v6(v5, a1, 1);
    result = v10;
    if (v10)
      result = (pmove_t *)((int(__cdecl *)(gentity_s *, gentity_s *, int))v10)(
          a1, v5, 1);
    while (1) {
      ++v3;
      v11 = (pmove_t *)((char *)v11 + 4);
      v7 = a2;
      if (v3 >= (signed int)a2->numtouch)
        break;
    LABEL_10:
      if (v3 <= 0) {
        if (!v3) {
          v4 = *(pmove_t **)v11->touchents;
          goto LABEL_3;
        }
      } else {
        result = v11;
        v4 = *(pmove_t **)v11->touchents;
        if (*(pmove_t **)v7->touchents != v4) {
          v8 = v7;
          v9 = 0;
          while (++v9 != v3) {
            result = *(pmove_t **)&v8->touchents[4];
            v8 = (pmove_t *)((char *)v8 + 4);
            if (result == v4) {
              ++v3;
              v11 = (pmove_t *)((char *)v11 + 4);
              v7 = a2;
              if (v3 < (signed int)a2->numtouch)
                goto LABEL_10;
              return result;
            }
          }
          goto LABEL_3;
        }
      }
    }
  }
  return result;
}

void __cdecl SpectatorClientEndFrame(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl SpectatorThink(struct gentity_s *ent, struct usercmd_s *ucmd) {
  UNIMPLEMENTED();
}

int __cdecl ClientInactivityTimer(struct gclient_s *client) { UNIMPLEMENTED(); }

void __cdecl ClientEvents(struct gentity_s *ent, int oldEventSequence) {
  _DWORD *client; // esi
  int v10;        // eax
  int v11;        // ecx
  int v12;        // ebx
  int v13;        // eax
  int v14;        // edx
  int v15;        // ecx
  int32_t v16;    // eax

  client = (_DWORD *)a8->client;
  v10 = client[41];
  v11 = v10 - 4;
  if (v10 - 4 <= a9)
    v11 = a9;
  if (v11 < v10) {
    v12 = v11;
    while (1) {
      v13 = v12 & 3;
      v14 = client[v13 + 42];
      v15 = client[v13 + 46];
      if ((unsigned int)(v14 - 116) > 0x16) {
        switch (v14) {
        case 158:
        case 159:
        case 160:
        case 175:
          if (*(_BYTE *)(g_antilag + 8))
            FireWeaponAntiLag(a1, a4, a5, a6, a7, a8, client[2599]);
          else
            FireWeaponAntiLag(a1, a4, a5, a6, a7, a8, dword_193466C);
          break;
        case 164:
          FireWeaponMelee(a1, a2, a3, a4, a5, a6, a7, a8);
          break;
        case 166:
          G_UseOffHand(a8);
          break;
        case 168:
          Scr_Notify(a2, a8, word_195B0E2, 0);
          break;
        case 169:
          Scr_Notify(a2, a8, word_195B0E4, 0);
          break;
        case 170:
          Scr_Notify(a2, a8, word_195B0E6, 0);
          break;
        case 171:
          Scr_Notify(a2, a8, word_195B0E8, 0);
          break;
        case 172:
          Scr_Notify(a2, a8, word_195B0EA, 0);
          break;
        case 197:
          v16 = a8->client;
          if (v16 && (a8->flags & 3) == 0) {
            a8->health = 0;
            *(_DWORD *)(v16 + 300) = 0;
            player_die(a1, a2, a3, a4, a5, a6, a7, a8, a8, a8, 100000, 0xCu, 0,
                       0, HITLOC_NONE, 0);
          }
          break;
        default:
          goto LABEL_9;
        }
        goto LABEL_9;
      }
      if (a8->s.eType != 1)
        return;
      if (v15 > 99)
        break;
      a3.f32[0] = (float)v15 * 0.0099999998;
      if (a3.f32[0] != 0.0)
        goto LABEL_8;
    LABEL_9:
      if (++v12 >= client[41])
        return;
    }
    a3 = (__m128)0x3F8CCCCDu;
  LABEL_8:
    a2 = (float)(int)client[77] * a3.f32[0];
    G_Damage(a1, a2, a3, a4, a5, a6, a7, a8, 0, 0, 0, 0, (int)a2, 0, 0xBu,
             HITLOC_NONE, 0);
    goto LABEL_9;
  }
}

void __cdecl ClientThink_real(struct gentity_s *ent, struct usercmd_s *ucmd) {
  UNIMPLEMENTED();
}

void __cdecl ClientEndFrame(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl G_RunClient(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl ClientThink(int clientNum) { UNIMPLEMENTED(); }

void __cdecl G_PlayerStateToEntityStateExtrapolate(struct playerState_s *,
                                                   struct entityState_s *, int,
                                                   int) {
  int v6;              // edx
  int v7;              // ecx
  int v8;              // ecx
  int v9;              // edx
  int v10;             // eax
  unsigned __int8 v11; // cl
  int v12;             // ebx
  int v13;             // edx
  int v14;             // ecx
  int *v15;            // edx
  int v16;             // eax
  unsigned int v17;    // eax
  int v18;             // eax
  int v19;             // eax
  int v20;             // ecx
  int v21;             // eax
  float v22;           // xmm1_4
  float v23;           // xmm1_4
  int v24;             // edx
  float v25;           // [esp+1Ch] [ebp-4Ch]
  int v26;             // [esp+34h] [ebp-34h]
  float v27;           // [esp+38h] [ebp-30h]
  int v28;             // [esp+3Ch] [ebp-2Ch]
  float v29[9];        // [esp+44h] [ebp-24h] BYREF

  *(_DWORD *)(a2 + 12) = 3;
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a2 + 16) = a3;
  *(_DWORD *)(a2 + 20) = 50;
  *(_DWORD *)(a2 + 48) = 1;
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(a1 + 232);
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a1 + 236);
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a1 + 240);
  *(float *)(a2 + 108) = (float)*(int *)(a1 + 156);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 160);
  v6 = *(_DWORD *)(a1 + 1484);
  v7 = *(_DWORD *)(a1 + 164);
  if (v6 - v7 < 0) {
    if (v7 - v6 > 4) {
      *(_DWORD *)(a1 + 1484) = v7 - 4;
      v24 = (v7 - 4) & 3;
    } else {
      v24 = *(_DWORD *)(a1 + 1484) & 3;
    }
    *(_DWORD *)(a2 + 160) = *(unsigned __int8 *)(a1 + 4 * v24 + 184);
    ++*(_DWORD *)(a1 + 1484);
  } else {
    *(_DWORD *)(a2 + 160) = 0;
  }
  v8 = *(_DWORD *)(a1 + 164);
  v9 = *(_DWORD *)(a1 + 200);
  if (v9 - v8 > 0) {
    v9 = *(_DWORD *)(a1 + 164);
    *(_DWORD *)(a1 + 200) = v8;
  }
  v28 = v9;
  if (v9 != *(_DWORD *)(a1 + 164)) {
    LOBYTE(v10) = v9;
    while (1) {
      v26 = v10 & 3;
      v11 = *(_BYTE *)(a1 + 4 * v26 + 168);
      v12 = v11;
      if ((unsigned __int8)(v11 + 98) <= 0x11u &&
          ((1 << (v11 + 98)) & 0x20007) != 0) {
        v13 = *(&g_entities.client + 140 * *(_DWORD *)a2);
        BG_WeaponFireRecoil((const playerState_s *)v13, (float *)(v13 + 10380),
                            v29);
      }
      if (singleClientEvents[0] <= 0)
        break;
      if (v12 == singleClientEvents[0]) {
      LABEL_15:
        v10 = ++v28;
        if (v28 == *(_DWORD *)(a1 + 164))
          goto LABEL_16;
      } else {
        v14 = 0;
        v15 = singleClientEvents;
        while (1) {
          ++v14;
          v16 = v15[1];
          if (v16 <= 0)
            break;
          ++v15;
          if (v12 == v16)
            goto LABEL_15;
        }
      LABEL_27:
        if (singleClientEvents[v14] >= 0)
          goto LABEL_15;
        v19 = *(_DWORD *)(a2 + 164);
        v20 = v19 & 3;
        *(_DWORD *)(a2 + 4 * v20 + 168) = v12;
        *(_DWORD *)(a2 + 4 * v20 + 184) =
            *(unsigned __int8 *)(a1 + 4 * v26 + 184);
        *(_DWORD *)(a2 + 164) = v19 + 1;
        v10 = ++v28;
        if (v28 == *(_DWORD *)(a1 + 164)) {
        LABEL_16:
          v9 = v10;
          goto LABEL_17;
        }
      }
    }
    v14 = 0;
    goto LABEL_27;
  }
LABEL_17:
  *(_DWORD *)(a1 + 200) = v9;
  *(_DWORD *)(a2 + 200) = *(unsigned __int8 *)(a1 + 212);
  *(_DWORD *)(a2 + 124) = *(unsigned __int16 *)(a1 + 96);
  *(_DWORD *)(a2 + 4) = (*(_DWORD *)(a1 + 12) & 0xC00000) == 0 ? 5 : 1;
  if (a4) {
    *(float *)(a2 + 24) = (float)(int)*(float *)(a2 + 24);
    *(float *)(a2 + 28) = (float)(int)*(float *)(a2 + 28);
    *(float *)(a2 + 32) = (float)(int)*(float *)(a2 + 32);
    *(float *)(a2 + 60) = (float)(int)*(float *)(a2 + 60);
    *(float *)(a2 + 64) = (float)(int)*(float *)(a2 + 64);
    *(float *)(a2 + 68) = (float)(int)*(float *)(a2 + 68);
  }
  *(_DWORD *)(a2 + 204) = *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a2 + 208) = *(_DWORD *)(a1 + 132);
  *(_DWORD *)(a2 + 144) = *(_DWORD *)(a1 + 204);
  if ((*(_DWORD *)(a1 + 160) & 0x300) != 0)
    *(_DWORD *)(a2 + 116) = *(_DWORD *)(a1 + 1428);
  if (*(int *)(a1 + 4) <= 5)
    v17 = *(_DWORD *)(a2 + 8) & 0xFFFDFFFF;
  else
    v17 = *(_DWORD *)(a2 + 8) | 0x20000;
  *(_DWORD *)(a2 + 8) = v17;
  if ((*(_BYTE *)(a1 + 12) & 0x40) != 0) {
    *(_DWORD *)(a2 + 8) = v17 | 0x40000;
    *(_DWORD *)(a2 + 212) = *(_DWORD *)(a1 + 76);
    LOBYTE(v18) = PM_GetEffectiveStance((playerState_s *)a1);
    if (v18 != 1) {
    LABEL_25:
      *(_DWORD *)(a2 + 228) = 0;
      *(_DWORD *)(a2 + 232) = 0;
      *(_DWORD *)(a2 + 236) = 0;
      return;
    }
  } else {
    *(_DWORD *)(a2 + 8) = v17 & 0xFFFBFFFF;
    *(_DWORD *)(a2 + 212) = *(_DWORD *)(a1 + 76);
    LOBYTE(v21) = PM_GetEffectiveStance((playerState_s *)a1);
    if (v21 != 1)
      goto LABEL_25;
  }
  v22 = (float)(*(_DWORD *)a1 - *(_DWORD *)(a1 + 252)) /
        (float)PM_GetViewHeightLerpTime((const playerState_s *)a1,
                                        *(_DWORD *)(a1 + 256),
                                        *(_DWORD *)(a1 + 260));
  if (v22 < 0.0)
    v23 = 0.0;
  else
    v23 = fminf(1.0, v22);
  if (!*(_DWORD *)(a1 + 260))
    v23 = 1.0 - v23;
  *(float *)(a2 + 228) = v23 * *(float *)(a1 + 1448);
  v25 = AngleNormalize180(*(float *)(a1 + 1452));
  *(float *)(a2 + 232) = v25 * v23;
  v27 = AngleNormalize180(*(float *)(a1 + 1456));
  *(float *)(a2 + 236) = v23 * v27;
}

int __cdecl G_UpdateClientInfo(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl G_AddPlayerMantleBlockage(float *const, int, struct pmove_t *) {
  UNIMPLEMENTED();
}
