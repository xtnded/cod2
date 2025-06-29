void __cdecl G_BroadcastVoice(struct gentity_s *talker,
                              unsigned char *voicePacket) {
  int result;     // eax
  int v3;         // esi
  gentity_s *v4;  // ebx
  int32_t client; // edx
  int v6;         // eax
  int v7;         // edx

  result = a1->client;
  *(_DWORD *)(result + 10248) = dword_193466C;
  v3 = 0;
  v4 = &g_entities;
  do {
    while (1) {
      if (v4->r.inuse) {
        result = v4->client;
        if (result)
          break;
      }
    LABEL_6:
      ++v3;
      ++v4;
      if (v3 == 64)
        return result;
    }
    if (*(_BYTE *)(voice_global + 8) || (result = OnSameTeam(a1, v4)) != 0) {
      client = a1->client;
    LABEL_3:
      v6 = *(_DWORD *)(v4->client + 9896);
      v7 = *(_DWORD *)(client + 9896);
      if (v6 == v7 ||
          ((result = v6 - 1) == 0 || v7 == 1) &&
              (result = voice_deadChat, *(_BYTE *)(voice_deadChat + 8))) {
        if (a1 != v4 ||
            (result = voice_localEcho, *(_BYTE *)(voice_localEcho + 8))) {
          result = SV_ClientHasClientMuted(v3, a1->s.number);
          if (!(_BYTE)result) {
            result = SV_ClientWantsVoiceData(v3);
            if ((_BYTE)result)
              result = SV_QueueVoicePacket(a1->s.number, v3, a2);
          }
        }
      }
      goto LABEL_6;
    }
    client = a1->client;
    if (!*(_DWORD *)(client + 10060))
      goto LABEL_3;
    ++v3;
    ++v4;
  } while (v3 != 64);
  return result;
}

void __cdecl SetClientViewAngle(struct gentity_s *ent,
                                float const *const angle) {
  float v2;       // ecx
  int32_t client; // edx
  int v4;         // ecx
  int32_t v5;     // edx
  int result;     // eax
  float v7;       // xmm1_4
  float v8;       // xmm1_4
  float v9;       // [esp+0h] [ebp-38h]
  float v10;      // [esp+0h] [ebp-38h]
  float v11;      // [esp+1Ch] [ebp-1Ch]
  float v12;      // [esp+1Ch] [ebp-1Ch]
  float v13;      // [esp+24h] [ebp-14h]
  float v14;      // [esp+28h] [ebp-10h]
  float v15;      // [esp+2Ch] [ebp-Ch]

  v13 = *a2;
  v2 = a2[1];
  v14 = v2;
  v15 = a2[2];
  client = a1->client;
  if ((*(_BYTE *)(client + 12) & 1) != 0 &&
      (*(_DWORD *)(client + 160) & 0x300) == 0) {
    v9 = AngleDelta(*(float *)(client + 1412), v2);
    v11 = AngleNormalize180(v9);
    if (v11 > 45.0) {
      v8 = v11 - 45.0;
    } else {
      if (v11 >= -45.0)
        goto LABEL_9;
      v8 = v11 + 45.0;
    }
    *(_DWORD *)(a1->client + 88) +=
        (unsigned __int16)(int)(float)(v8 * 182.04445);
    if (v8 <= 0.0)
      v14 = AngleNormalize360(*(float *)(a1->client + 1412) + 45.0);
    else
      v14 = AngleNormalize360(*(float *)(a1->client + 1412) - 45.0);
  LABEL_9:
    v10 = AngleDelta(*(float *)(a1->client + 1420), v13);
    v12 = AngleNormalize180(v10);
    if (v12 > 45.0) {
      v7 = v12 - 45.0;
    } else {
      if (v12 >= -15.0) {
      LABEL_15:
        client = a1->client;
        goto LABEL_3;
      }
      v7 = v12 + 15.0;
    }
    *(_DWORD *)(a1->client + 84) +=
        (unsigned __int16)(int)(float)(v7 * 182.04445);
    if (v7 <= 0.0)
      v13 = AngleNormalize180(*(float *)(a1->client + 1420) + 15.0);
    else
      v13 = AngleNormalize180(*(float *)(a1->client + 1420) - 45.0);
    goto LABEL_15;
  }
LABEL_3:
  v4 = 0;
  while (1) {
    *(_DWORD *)(client + 4 * v4 + 84) =
        (unsigned __int16)(int)(float)(*(&v13 + v4) * 182.04445) -
        *(_DWORD *)(client + 4 * v4 + 9940);
    if (++v4 == 3)
      break;
    client = a1->client;
  }
  a1->r.currentAngles[0] = v13;
  a1->r.currentAngles[1] = v14;
  a1->r.currentAngles[2] = v15;
  v5 = a1->client;
  *(float *)(v5 + 232) = a1->r.currentAngles[0];
  *(float *)(v5 + 236) = a1->r.currentAngles[1];
  result = LODWORD(a1->r.currentAngles[2]);
  *(_DWORD *)(v5 + 240) = result;
  return result;
}

void __cdecl G_GetPlayerViewDirection(struct gentity_s const *ent,
                                      float *const forward, float *const right,
                                      float *const up) {
  AngleVectors((float *)(a1->client + 232), a2, a3, a4);
}

void __cdecl ClientUserinfoChanged(int clientNum) { UNIMPLEMENTED(); }

int __cdecl G_GetNonPVSFriendlyInfo(struct gentity_s *pSelf,
                                    float *const vPosition,
                                    int iLastUpdateEnt) {
  UNIMPLEMENTED();
}

void __cdecl ClientBegin(int) { UNIMPLEMENTED(); }

char *__cdecl ClientConnect(int clientNum, unsigned short scriptPersId) {
  UNIMPLEMENTED();
}

void __cdecl G_GetPlayerViewOrigin(struct gentity_s const *ent,
                                   float *const origin) {
  int32_t client;            // esi
  float v3;                  // xmm0_4
  float v4;                  // xmm0_4
  char v5;                   // [esp+8h] [ebp-70h]
  float VerticalBobFactor;   // [esp+2Ch] [ebp-4Ch]
  float HorizontalBobFactor; // [esp+2Ch] [ebp-4Ch]
  float BobCycle;            // [esp+48h] [ebp-30h]
  float Speed;               // [esp+4Ch] [ebp-2Ch]
  float v10[9];              // [esp+54h] [ebp-24h] BYREF

  client = a1->client;
  if ((*(_DWORD *)(client + 160) & 0x300) != 0) {
    if (!G_DObjGetWorldTagPos(&g_entities + *(_DWORD *)(client + 1428),
                              (unsigned __int16)word_195B11A, a2))
      Com_Error(
          1,
          "\x15G_GetPlayerViewOrigin: Couldn't find [tag_player] on turret\n",
          v5);
  } else {
    *a2 = *(float *)(client + 20);
    a2[1] = *(float *)(client + 24);
    v3 = *(float *)(client + 28);
    a2[2] = v3;
    a2[2] = v3 + *(float *)(client + 248);
    BobCycle = BG_GetBobCycle((const playerState_s *)client);
    Speed = BG_GetSpeed((const playerState_s *)client, dword_193466C);
    VerticalBobFactor =
        BG_GetVerticalBobFactor((const playerState_s *)client, BobCycle, Speed,
                                *(float *)(bg_bobMax + 8));
    a2[2] = VerticalBobFactor + a2[2];
    HorizontalBobFactor =
        BG_GetHorizontalBobFactor((const playerState_s *)client, BobCycle,
                                  Speed, *(float *)(bg_bobMax + 8));
    AngleVectors((float *)(a1->client + 232), 0, v10, 0);
    *a2 = (float)(HorizontalBobFactor * v10[0]) + *a2;
    a2[1] = (float)(HorizontalBobFactor * v10[1]) + a2[1];
    a2[2] = (float)(HorizontalBobFactor * v10[2]) + a2[2];
    AddLeanToPosition(a2, *(float *)(client + 236), *(float *)(client + 76),
                      16.0, 20.0);
    v4 = *(float *)(client + 28) + 8.0;
    if (v4 > a2[2])
      a2[2] = v4;
  }
}

void __cdecl ClientDisconnect(int clientNum) {
  int v2;         // esi
  int v3;         // ebx
  gentity_s *v4;  // edi
  int v5;         // eax
  gentity_s *__b; // [esp+28h] [ebp-20h]
  int v7;         // [esp+2Ch] [ebp-1Ch]

  v7 = level + 10404 * a2;
  __b = &g_entities + a2;
  if (Scr_IsSystemActive()) {
    Scr_AddString(a1, "disconnect");
    Scr_AddString(a1, "-1");
    Scr_Notify(a1, __b, word_195B0F0, 2u);
  }
  if (dword_1934664 > 0) {
    v2 = 0;
    v3 = 0;
    v4 = &g_entities;
    do {
      v5 = level + v3;
      if (*(_DWORD *)(level + v3 + 9924) && *(_DWORD *)(v5 + 9896) == 2 &&
          a2 == *(_DWORD *)(v5 + 10152))
        StopFollowing(v4);
      ++v2;
      ++v4;
      v3 += 10404;
    } while (v2 < dword_1934664);
  }
  HudElem_ClientDisconnect(__b);
  if (Scr_IsSystemActive())
    Scr_PlayerDisconnect(a1, __b);
  G_FreeEntity(a1, __b);
  *(_DWORD *)(v7 + 9924) = 0;
  memset((void *)(v7 + 10056), 0, 0x5Cu);
  CalculateRanks();
}

void __cdecl ClientSpawn(struct gentity_s *ent, float const *const spawn_origin,
                         float const *const spawn_angles) {
  UNIMPLEMENTED();
}

float *playerMins;
float *playerMaxs;
void __cdecl ClientCleanName(char const *, char *, int) { UNIMPLEMENTED(); }
