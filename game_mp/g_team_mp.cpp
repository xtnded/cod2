int __cdecl OnSameTeam(struct gentity_s *ent1, struct gentity_s *ent2)
{
  int32_t client; // eax
  int32_t v3;     // edx
  int v4;         // eax
  _BOOL4 result;  // eax

  client = a1->client;
  result = 0;
    if (client) {
      v3 = a2->client;
        if (v3) {
          v4 = *(_DWORD *)(client + 10060);
            if (v4) {
              if (v4 == *(_DWORD *)(v3 + 10060))
                return 1;
            }
        }
    }
  return result;
}

void __cdecl TeamplayInfoMessage(struct gentity_s *)
{
  _DWORD *client; // eax
  int32_t result; // eax
  int32_t v3;     // edx
  int entityNum;  // esi
  gentity_s *v5;  // ebx
  int32_t v6;     // edx
  int32_t health; // ecx
  float v8;       // xmm0_4
  trace_t v9;     // [esp+38h] [ebp-60h] BYREF
  float v10;      // [esp+5Ch] [ebp-3Ch] BYREF
  float v11;      // [esp+60h] [ebp-38h]
  float v12;      // [esp+64h] [ebp-34h]
  float v13;      // [esp+68h] [ebp-30h] BYREF
  float v14;      // [esp+6Ch] [ebp-2Ch]
  float v15;      // [esp+70h] [ebp-28h]
  float v16;      // [esp+74h] [ebp-24h] BYREF
  float v17;      // [esp+78h] [ebp-20h]
  float v18;      // [esp+7Ch] [ebp-1Ch]

  client = (_DWORD *)a1->client;
    if (client[2474]) {
      G_GetPlayerViewOrigin(a1, &v13);
      G_GetPlayerViewDirection(a1, &v16, 0, 0);
      v3 = a1->client;
      v8 = *(float *)(v3 + 248);
      if (v8 < 8.0)
        v15 = (float)(8.0 - v8) + v15;
      v10 = (float)(v16 * 8192.0) + v13;
      v11 = (float)(v17 * 8192.0) + v14;
      v12 = (float)(8192.0 * v18) + v15;
    }
    else {
        if (!client[2515]) {
          client[78] = -1;
          result = a1->client;
          *(_DWORD *)(result + 316) = 0;
          return result;
        }
      G_GetPlayerViewOrigin(a1, &v13);
      G_GetPlayerViewDirection(a1, &v16, 0, 0);
      v10 = (float)(v16 * 8192.0) + v13;
      v11 = (float)(v17 * 8192.0) + v14;
      v12 = (float)(8192.0 * v18) + v15;
      v3 = a1->client;
    }
  G_TraceCapsule(&v9, &v13, (trace_t *)vec3_origin, vec3_origin, &v10,
                 *(_DWORD *)(v3 + 204), (const float *)0x2000001);
  entityNum = v9.entityNum;
    if (v9.entityNum > 0x3Fu ||
        (v5 = &g_entities + v9.entityNum, !v5->client)) {
      v6 = a1->client;
      goto LABEL_11;
    }
    if (!G_IsPlaying(a1)) {
      v6 = a1->client;
      goto LABEL_9;
    }
  v6 = a1->client;
    if (*(_DWORD *)(v5->client + 10060) != *(_DWORD *)(v6 + 10060)) {
    LABEL_11:
      entityNum = -1;
      health = 0;
      goto LABEL_12;
    }
LABEL_9:
  health = v5->health;
LABEL_12:
  *(_DWORD *)(v6 + 312) = entityNum;
  result = a1->client;
  *(_DWORD *)(result + 316) = health;
  return result;
}

void __cdecl CheckTeamStatus()
{
  int result;      // eax
  int v1;          // esi
  int8_t *p_inuse; // ebx
  gentity_s *v3;   // edi

  result = dword_193466C - *(_DWORD *)&algn_1934688[4];
    if (dword_193466C - *(_DWORD *)&algn_1934688[4] > 0) {
      *(_DWORD *)&algn_1934688[4] = dword_193466C;
      result = g_maxclients;
        if (*(int *)(g_maxclients + 8) > 0) {
          v1 = 0;
          p_inuse = &g_entities.r.inuse;
          v3 = &g_entities;
            do {
                while (!*p_inuse ||
                       (*(_BYTE *)(*((_DWORD *)p_inuse + 23) + 14) & 0x40) !=
                           0) {
                  ++v1;
                  p_inuse += 560;
                  ++v3;
                  result = g_maxclients;
                  if (v1 >= *(_DWORD *)(g_maxclients + 8))
                    return result;
                }
              TeamplayInfoMessage(v3);
              ++v1;
              p_inuse += 560;
              ++v3;
              result = g_maxclients;
            }
          while (v1 < *(_DWORD *)(g_maxclients + 8));
        }
    }
  return result;
}
