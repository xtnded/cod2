int __cdecl G_IsPlaying(struct gentity_s *ent)
{
  return *(_DWORD *)(a1->client + 9896) == 0;
}

void __cdecl SanitizeString(char *, char *)
{
  UNIMPLEMENTED();
}

char *__cdecl ConcatArgs(int start)
{
  int v1;           // eax
  int v3;           // ebx
  unsigned int v4;  // ecx
  int v5;           // edi
  int v6;           // [esp+14h] [ebp-424h]
  int v7;           // [esp+18h] [ebp-420h]
  int v8;           // [esp+1Ch] [ebp-41Ch]
  char __src[1048]; // [esp+20h] [ebp-418h] BYREF

  v1 = SV_Cmd_Argc();
    if (v1 > a1) {
      v3 = a1;
      v8 = 0;
      v6 = v1;
      v7 = v1 - 1;
        while (1) {
          SV_Cmd_ArgvBuffer(v3, __src, 1024);
          v4 = strlen(__src) + 1;
          v5 = v4 - 1 + v8;
          if (v5 > 1022)
            break;
          memcpy((void *)(v8 + 15931264), __src, v4 - 1);
          if (v3 != v7)
            ConcatArgs(int)::line[v5++] = 32;
          v8 = v5;
            if (v6 == ++v3) {
              ConcatArgs(int)::line[v5] = 0;
              return ConcatArgs(int)::line;
            }
        }
    }
    else {
      v8 = 0;
    }
  ConcatArgs(int)::line[v8] = 0;
  return ConcatArgs(int)::line;
}

void __cdecl Cmd_Where_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

int __cdecl ClientNumberFromString(struct gentity_s *, char *)
{
  UNIMPLEMENTED();
}

int __cdecl CheatsOk(struct gentity_s *ent)
{
  char *v2; // eax

    if (*(_BYTE *)(g_cheats + 8)) {
      if (a1->health > 0)
        return 1;
      v2 = va("%c \"GAME_MUSTBEALIVECOMMAND\"", 101);
    }
    else {
      v2 = va("%c \"GAME_CHEATSNOTENABLED\"", 101);
    }
  SV_GameSendServerCommand(-1963413621 *
                               (((char *)a1 - (char *)&g_entities) >> 4),
                           SV_CMD_CAN_IGNORE, v2);
  return 0;
}

void __cdecl DeathmatchScoreboardMessage(struct gentity_s *ent)
{
  int *v1;          // esi
  int v2;           // edx
  unsigned int v3;  // kr04_4
  _DWORD *v4;       // edi
  char *v5;         // eax
  int v6;           // [esp+24h] [ebp-9A4h]
  int v7;           // [esp+28h] [ebp-9A0h]
  int v8;           // [esp+2Ch] [ebp-99Ch]
  char v9[1400];    // [esp+38h] [ebp-990h] BYREF
  char __src[1048]; // [esp+5B0h] [ebp-418h] BYREF

  v9[0] = 0;
  v8 = dword_1934698;
    if (dword_1934698 <= 64) {
        if (dword_1934698 <= 0) {
          v7 = 0;
          goto LABEL_12;
        }
    }
    else {
      v8 = 64;
    }
  v6 = 0;
  v7 = 0;
  v1 = &level;
    while (1) {
      v4 = (_DWORD *)(level + 10404 * v1[135]);
      v2 = v4[2481] == 1 ? -1 : SV_GetClientPing(v1[135]);
      Com_sprintf(__src, 0x400u, " %i %i %i %i %i", v1[135], v4[2478], v2,
                  v4[2479], v4[2476]);
      v3 = strlen(__src) + 1;
      if ((int)(v3 + v6 - 1) > 1024)
        break;
      strcpy(&v9[v6], __src);
      ++v7;
      ++v1;
        if (v8 == v7) {
          v5 = va("%c %i %i %i%s", 98, v8, dword_1934680, dword_1934684, v9);
          goto LABEL_13;
        }
      v6 = v3 + v6 - 1;
    }
LABEL_12:
  v5 = va("%c %i %i %i%s", 98, v7, dword_1934680, dword_1934684, v9);
LABEL_13:
  SV_GameSendServerCommand(-1963413621 *
                               (((char *)a1 - (char *)&g_entities) >> 4),
                           SV_CMD_RELIABLE, v5);
}

void __cdecl Cmd_UFO_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Noclip_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Notarget_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_DemiGod_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_God_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Take_f(struct gentity_s *ent)
{
  int v1;           // eax
  int v2;           // ebx
  int v3;           // eax
  int v4;           // ecx
  int32_t v5;       // eax
  int i;            // esi
  int32_t client;   // ebx
  int32_t v8;       // ebx
  int32_t v9;       // eax
  int v10;          // eax
  int v11;          // eax
  int32_t v12;      // ebx
  int v13;          // edi
  int32_t v14;      // esi
  int v15;          // ebx
  int32_t v16;      // ebx
  int32_t v17;      // ebx
  int32_t v18;      // ebx
  int v19;          // esi
  unsigned int v20; // kr04_4
  int v21;          // ebx
  int v22;          // esi
  unsigned int v23; // kr08_4
  int v24;          // eax
  int32_t v25;      // ebx
  int v26;          // edi
  int32_t v27;      // esi
  int v28;          // ebx
  int32_t v29;      // ebx
  int32_t v30;      // ebx
  int32_t v31;      // ebx
  int k;            // esi
  int32_t v33;      // ebx
  int32_t v34;      // ebx
  int v35;          // [esp+18h] [ebp-440h]
  int v36;          // [esp+1Ch] [ebp-43Ch]
  int v37;          // [esp+20h] [ebp-438h]
  int v38;          // [esp+24h] [ebp-434h]
  int v39;          // [esp+28h] [ebp-430h]
  int v40;          // [esp+2Ch] [ebp-42Ch]
  int v41;          // [esp+30h] [ebp-428h]
  int v42;          // [esp+34h] [ebp-424h]
  int v43;          // [esp+38h] [ebp-420h]
  int j;            // [esp+3Ch] [ebp-41Ch]
  char __src[1048]; // [esp+40h] [ebp-418h] BYREF

  if (!CheatsOk(a1))
    return;
  v1 = SV_Cmd_Argc();
  v40 = v1;
    if (v1 > 2) {
      v22 = 2;
      v41 = 0;
      v36 = v1 - 1;
        while (1) {
          SV_Cmd_ArgvBuffer(v22, __src, 1024);
          v23 = strlen(__src) + 1;
          v2 = v23 - 1 + v41;
          if (v2 > 1022)
            break;
          memcpy((void *)(v41 + 15931264), __src, v23 - 1);
            if (v22 != v36) {
              ConcatArgs(int)::line[v2] = 32;
              v2 = v23 + v41;
            }
          if (v40 == ++v22)
            goto LABEL_5;
          v41 = v2;
        }
      v2 = v41;
    }
    else {
      v2 = 0;
    }
LABEL_5:
  ConcatArgs(int)::line[v2] = 0;
  v39 = atoi(ConcatArgs(int)::line);
  v3 = SV_Cmd_Argc();
  v42 = v3;
    if (v3 > 1) {
      v19 = 1;
      v43 = 0;
      v35 = v3 - 1;
        while (1) {
          SV_Cmd_ArgvBuffer(v19, __src, 1024);
          v20 = strlen(__src) + 1;
          v4 = v43;
          v21 = v20 - 1 + v43;
          if (v21 > 1022)
            break;
          memcpy((void *)(v43 + 15931264), __src, v20 - 1);
            if (v19 != v35) {
              ConcatArgs(int)::line[v21] = 32;
              v21 = v20 + v43;
            }
            if (v42 == ++v19) {
              v4 = v21;
              break;
            }
          v43 = v21;
        }
    }
    else {
      v4 = 0;
    }
  ConcatArgs(int)::line[v4] = 0;
  if (!ConcatArgs(int)::line[0])
    return;
    if (!I_stricmp(ConcatArgs(int)::line, "all")) {
      v38 = 1;
      goto LABEL_10;
    }
    if (!I_strnicmp(ConcatArgs(int)::line, "health", 6)) {
      v38 = 0;
    LABEL_10:
        if (v39) {
          v5 = a1->health - v39;
          a1->health = v5;
          if (v5 <= 0)
            a1->health = 1;
        }
        else {
          a1->health = 1;
        }
      if (!v38)
        return;
      goto LABEL_14;
    }
    if (!I_stricmp(ConcatArgs(int)::line, "weapons")) {
      v38 = 0;
    LABEL_14:
        for (i = 1; i <= BG_GetNumWeapons(); ++i) {
          BG_TakePlayerWeapon((playerState_s *)a1->client, i);
          client = a1->client;
          *(_DWORD *)(client + 4 * BG_AmmoForWeapon(i) + 324) = 0;
          v8 = a1->client;
          *(_DWORD *)(v8 + 4 * BG_ClipForWeapon(i) + 836) = 0;
        }
      v9 = a1->client;
        if (*(_DWORD *)(v9 + 212)) {
          *(_DWORD *)(v9 + 212) = 0;
          G_SelectWeaponIndex(
              -1963413621 * (((char *)a1 - (char *)&g_entities) >> 4), 0);
        }
      if (!v38)
        return;
      goto LABEL_20;
    }
    if (I_strnicmp(ConcatArgs(int)::line, "ammo", 4)) {
    LABEL_23:
        if (!I_strnicmp(ConcatArgs(int)::line, "allammo", 7) && v39) {
            for (j = 1; j <= BG_GetNumWeapons(); ++j) {
              v11 = BG_AmmoForWeapon(j);
              *(_DWORD *)(a1->client + 4 * v11 + 324) -= v39;
              v12 = a1->client;
                if (*(int *)(v12 + 4 * BG_AmmoForWeapon(j) + 324) < 0) {
                  v13 = BG_ClipForWeapon(j);
                  v14 = a1->client;
                  v15 = *(_DWORD *)(v14 + 4 * v13 + 836);
                  *(_DWORD *)(v14 + 4 * v13 + 836) =
                      *(_DWORD *)(v14 + 4 * BG_AmmoForWeapon(j) + 324) + v15;
                  v16 = a1->client;
                  *(_DWORD *)(v16 + 4 * BG_AmmoForWeapon(j) + 324) = 0;
                  v17 = a1->client;
                    if (*(int *)(v17 + 4 * BG_ClipForWeapon(j) + 836) < 0) {
                      v18 = a1->client;
                      *(_DWORD *)(v18 + 4 * BG_ClipForWeapon(j) + 836) = 0;
                    }
                }
            }
        }
      return;
    }
  v38 = 0;
LABEL_20:
    if (v39) {
      v10 = *(_DWORD *)(a1->client + 212);
      v37 = v10;
        if (v10) {
          v24 = BG_AmmoForWeapon(v10);
          *(_DWORD *)(a1->client + 4 * v24 + 324) -= v39;
          v25 = a1->client;
            if (*(int *)(v25 + 4 * BG_AmmoForWeapon(v37) + 324) < 0) {
              v26 = BG_ClipForWeapon(v37);
              v27 = a1->client;
              v28 = *(_DWORD *)(v27 + 4 * v26 + 836);
              *(_DWORD *)(v27 + 4 * v26 + 836) =
                  *(_DWORD *)(v27 + 4 * BG_AmmoForWeapon(v37) + 324) + v28;
              v29 = a1->client;
              *(_DWORD *)(v29 + 4 * BG_AmmoForWeapon(v37) + 324) = 0;
              v30 = a1->client;
                if (*(int *)(v30 + 4 * BG_ClipForWeapon(v37) + 836) < 0) {
                  v31 = a1->client;
                  *(_DWORD *)(v31 + 4 * BG_ClipForWeapon(v37) + 836) = 0;
                }
            }
        }
    }
    else {
        for (k = 1; k <= BG_GetNumWeapons(); ++k) {
          v33 = a1->client;
          *(_DWORD *)(v33 + 4 * BG_AmmoForWeapon(k) + 324) = 0;
          v34 = a1->client;
          *(_DWORD *)(v34 + 4 * BG_ClipForWeapon(k) + 836) = 0;
        }
    }
  if (v38)
    goto LABEL_23;
}

void __cdecl Cmd_Score_f(struct gentity_s *ent)
{
  DeathmatchScoreboardMessage(a1);
}

void __cdecl G_setfog(char const *fogstring)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_SetViewpos_f(struct gentity_s *ent)
{
  char *v1;      // eax
  int i;         // ebx
  float v3;      // xmm0_4
  float v4;      // xmm0_4
  char v5[1024]; // [esp+28h] [ebp-430h] BYREF
  float v6;      // [esp+428h] [ebp-30h] BYREF
  float v7;      // [esp+42Ch] [ebp-2Ch]
  int v8;        // [esp+430h] [ebp-28h]
  float v9[2];   // [esp+434h] [ebp-24h] BYREF
  float v10;     // [esp+43Ch] [ebp-1Ch]

    if (!*(_BYTE *)(g_cheats + 8)) {
      v1 = va("%c \"GAME_CHEATSNOTENABLED\"", 101);
    LABEL_3:
      SV_GameSendServerCommand(-1963413621 *
                                   (((char *)a1 - (char *)&g_entities) >> 4),
                               SV_CMD_CAN_IGNORE, v1);
      return;
    }
    if (SV_Cmd_Argc() != 5) {
      v1 = va("%c \"GAME_USAGE\x15: setviewpos x y z yaw\"", 101);
      goto LABEL_3;
    }
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0;
    for (i = 0; i != 3; v9[i - 1] = v3) {
      SV_Cmd_ArgvBuffer(++i, v5, 1024);
      v3 = atof(v5);
    }
  SV_Cmd_ArgvBuffer(4, v5, 1024);
  v4 = atof(v5);
  v7 = v4;
  v10 = v10 - *(float *)(a1->client + 248);
  TeleportPlayer(a1, v9, &v6);
}

void __cdecl Cmd_Fogswitch_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_EntityCount_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl G_Say(struct gentity_s *ent, struct gentity_s *target, int mode,
                   char const *chatText)
{
  int32_t client;  // eax
  int32_t v5;      // edx
  int v6;          // eax
  const char *v7;  // ecx
  uint32_t v8;     // ebx
  int v9;          // eax
  const char *v10; // ebx
  uint32_t number; // esi
  int Guid;        // eax
  int v13;         // esi
  gentity_s *v14;  // ebx
  int v15;         // edx
  int v16;         // [esp+2Ch] [ebp-1BCh]
  char v17[150];   // [esp+3Ah] [ebp-1AEh] BYREF
  char v18[128];   // [esp+D0h] [ebp-118h] BYREF
  char __str[64];  // [esp+150h] [ebp-98h] BYREF
  char __dst[88];  // [esp+190h] [ebp-58h] BYREF

    if (a3 == 1) {
      client = a1->client;
      v15 = *(_DWORD *)(client + 10060);
      a3 = v15 == 1 || v15 == 2;
    }
    else {
      client = a1->client;
    }
  I_strncpyz(__dst, (char *)(client + 10116), 64);
  I_CleanStr(__dst);
  v5 = a1->client;
  v6 = *(_DWORD *)(v5 + 10060);
    if (v6 == 1) {
      v7 = "^9";
      if (*(_DWORD *)(v5 + 9896))
        goto LABEL_7;
    }
    else if (v6 == 2) {
      v7 = "^8";
      if (*(_DWORD *)(v5 + 9896))
        goto LABEL_7;
    }
    else {
      v7 = (const char *)&inData;
        if (v6 == 3) {
          Com_sprintf(__str, 0x40u, "\x15(\x14GAME_SPECTATOR\x15)");
        LABEL_8:
          if (a3 != 1)
            goto LABEL_9;
        LABEL_15:
          v10 = "GAME_AXIS";
          if (*(_DWORD *)(a1->client + 10060) != 1)
            v10 = "GAME_ALLIES";
          number = a1->s.number;
          Guid = SV_GetGuid(a1->s.number);
          G_LogPrintf("sayteam;%d;%d;%s;%s\n", Guid, number, __dst, __src);
          Com_sprintf(v18, 0x80u, "%s(\x14%s\x15)%s%s: ", __str, v10, __dst,
                      "^7");
          v16 = 53;
          I_strncpyz(v17, __src, 150);
          if (a2)
            goto LABEL_12;
          goto LABEL_18;
        }
        if (*(_DWORD *)(v5 + 9896)) {
        LABEL_7:
          Com_sprintf(__str, 0x40u, "\x15%s(\x14GAME_DEAD\x15)", v7);
          goto LABEL_8;
        }
    }
  Com_sprintf(__str, 0x40u, "\x15%s", v7);
  if (a3 == 1)
    goto LABEL_15;
LABEL_9:
    if (a3 == 2) {
      Com_sprintf(v18, 0x80u, "%s[%s]%s: ", __str, __dst, "^7");
      v16 = 51;
    }
    else {
      v8 = a1->s.number;
      v9 = SV_GetGuid(a1->s.number);
      G_LogPrintf("say;%d;%d;%s;%s\n", v9, v8, __dst, __src);
      Com_sprintf(v18, 0x80u, "%s%s%s: ", __str, __dst, "^7");
      v16 = 55;
    }
  I_strncpyz(v17, __src, 150);
    if (a2) {
    LABEL_12:
      G_SayTo(a1, a2, a3, (gentity_s *)v16, (gentity_s *)v18, v17);
      return;
    }
LABEL_18:
  if (*(_DWORD *)(g_dedicated + 8))
    Com_Printf("%s%s\n", v18, v17);
    if (dword_1934664 > 0) {
      v13 = 0;
      v14 = &g_entities;
        do {
          G_SayTo(a1, v14, a3, (gentity_s *)v16, (gentity_s *)v18, v17);
          ++v13;
          ++v14;
        }
      while (dword_1934664 > v13);
    }
}

void __cdecl Cmd_GameCommand_f(struct gentity_s *ent)
{
  unsigned int v1; // esi
  unsigned int v2; // eax
  unsigned int v3; // ebx
  char v4[1032];   // [esp+10h] [ebp-408h] BYREF

  SV_Cmd_ArgvBuffer(1, v4, 1024);
  v1 = atoi(v4);
  SV_Cmd_ArgvBuffer(2, v4, 1024);
  v2 = atoi(v4);
  v3 = v2;
    if (v1 <= 0x3F && v2 <= 6) {
      G_Say(a1, &g_entities + v1, 2, (&gc_orders)[v2]);
      G_Say(a1, a1, 2, (&gc_orders)[v3]);
    }
}

void __cdecl Cmd_MenuResponse_f(struct gentity_s *pEnt)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Vote_f(struct gentity_s *ent)
{
  int32_t client; // eax
  char *v9;       // eax
  char *v10;      // eax
  char *v11;      // eax
  char *v12;      // eax
  char v13;       // [esp+10h] [ebp-48h] BYREF
  char v14;       // [esp+11h] [ebp-47h]

    if (*(_BYTE *)(g_oldVoting + 8)) {
        if (dword_1934F9C) {
          client = a8->client;
            if ((*(_BYTE *)(client + 162) & 0x10) != 0) {
              v11 = va("%c \"GAME_VOTEALREADYCAST\"", 101);
            }
            else {
                if (*(_DWORD *)(client + 10060) != 3) {
                  v9 = va("%c \"GAME_VOTECAST\"", 101);
                  SV_GameSendServerCommand(
                      -1963413621 * (((char *)a8 - (char *)&g_entities) >> 4),
                      SV_CMD_CAN_IGNORE, v9);
                  *(_DWORD *)(a8->client + 160) |= 0x100000u;
                  goto LABEL_6;
                }
              v11 = va("%c \"GAME_NOSPECTATORVOTE\"", 101);
            }
        }
        else {
          v11 = va("%c \"GAME_NOVOTEINPROGRESS\"", 101);
        }
      SV_GameSendServerCommand(-1963413621 *
                                   (((char *)a8 - (char *)&g_entities) >> 4),
                               SV_CMD_CAN_IGNORE, v11);
      return;
    }
LABEL_6:
  SV_Cmd_ArgvBuffer(1, &v13, 64);
    if (v13 == 121 || v14 == 89 || v14 == 49) {
        if (*(_BYTE *)(g_oldVoting + 8)) {
          v12 = va("%i", ++dword_1934FA4);
          SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x11u, v12);
        }
        else {
          Scr_PlayerVote(a2, a8, "yes");
        }
    }
    else if (*(_BYTE *)(g_oldVoting + 8)) {
      v10 = va("%i", ++dword_1934FA8);
      SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x12u, v10);
    }
    else {
      Scr_PlayerVote(a2, a8, "no");
    }
}

void __cdecl Cmd_CallVote_f(struct gentity_s *ent)
{
  int32_t client;              // eax
  char *v9;                    // eax
  char v10;                    // bl
  bool v11;                    // zf
  char v12;                    // al
  dvar_s *v13;                 // eax
  char *v14;                   // eax
  int v15;                     // ebx
  char *v16;                   // eax
  char *v17;                   // eax
  char *v18;                   // eax
  int v19;                     // ecx
  int v20;                     // edx
  char *v21;                   // eax
  char *v22;                   // eax
  char *v23;                   // eax
  char *v24;                   // eax
  int v25;                     // edi
  int v26;                     // ebx
  int v27;                     // eax
  unsigned int v28;            // eax
  int v29;                     // edi
  int v30;                     // eax
  const char *v31;             // eax
  char v32;                    // [esp+8h] [ebp-380h]
  int v33;                     // [esp+Ch] [ebp-37Ch]
  char *GameTypeNameForScript; // [esp+Ch] [ebp-37Ch]
  char *v35;                   // [esp+Ch] [ebp-37Ch]
  int v36;                     // [esp+2Ch] [ebp-35Ch]
  char __src[256];             // [esp+30h] [ebp-358h] BYREF
  char v38[256];               // [esp+130h] [ebp-258h] BYREF
  char __s[256];               // [esp+230h] [ebp-158h] BYREF
  char __dst[88];              // [esp+330h] [ebp-58h] BYREF

    if (!*(_BYTE *)(g_allowVote + 8)) {
      v9 = va("%c \"GAME_VOTINGNOTENABLED\"", 101);
      goto LABEL_8;
    }
    if (*(_BYTE *)(g_oldVoting + 8)) {
        if (dword_1934F9C) {
          v9 = va("%c \"GAME_VOTEALREADYINPROGRESS\"", 101);
          goto LABEL_8;
        }
      client = a8->client;
        if (*(int *)(client + 10036) > 2) {
          v9 = va("%c \"GAME_MAXVOTESCALLED\"", 101);
          goto LABEL_8;
        }
        if (*(_DWORD *)(client + 10060) == 3) {
          v9 = va("%c \"GAME_NOSPECTATORCALLVOTE\"", 101);
          goto LABEL_8;
        }
    }
  SV_Cmd_ArgvBuffer(1, __s, 256);
  SV_Cmd_ArgvBuffer(2, v38, 256);
  SV_Cmd_ArgvBuffer(3, __src, 256);
    if (strchr(__s, 59) || strchr(v38, 59) || strchr(__src, 59)) {
      v9 = va("%c \"GAME_INVALIDVOTESTRING\"", 101);
    LABEL_8:
      SV_GameSendServerCommand(-1963413621 *
                                   (((char *)a8 - (char *)&g_entities) >> 4),
                               SV_CMD_CAN_IGNORE, v9);
      return;
    }
    if (!*(_BYTE *)(g_oldVoting + 8)) {
      Scr_VoteCalled(a2, a8, __s, v38, __src);
      return;
    }
    if (I_stricmp(__s, "map_restart") && I_stricmp(__s, "map_rotate") &&
        I_stricmp(__s, "typemap") && I_stricmp(__s, "map") &&
        I_stricmp(__s, "g_gametype") && I_stricmp(__s, "kick") &&
        I_stricmp(__s, "clientkick") && I_stricmp(__s, "tempBanUser") &&
        I_stricmp(__s, "tempBanClient")) {
      v14 = va("%c \"GAME_INVALIDVOTESTRING\"", 101);
      v15 = -1963413621 * (((char *)a8 - (char *)&g_entities) >> 4);
      SV_GameSendServerCommand(v15, SV_CMD_CAN_IGNORE, v14);
      v16 = va("%c \"GAME_VOTECOMMANDSARE\x15 map_restart, map_rotate, map "
               "<mapname>, g_gametype <typename>, typemap <typena"
               "me> <mapname>, kick <player>, clientkick <clientnum>, "
               "tempBanUser <player>, tempBanClient <clientNum>\"",
               101);
      SV_GameSendServerCommand(v15, SV_CMD_CAN_IGNORE, v16);
      return;
    }
    if (dword_1934FA0) {
      dword_1934FA0 = 0;
      v17 = va("%s\n", byte_193479C);
      Cbuf_ExecuteText(2, v17, v32);
    }
    if (I_stricmp(__s, "typemap")) {
        if (!I_stricmp(__s, "g_gametype")) {
            if (Scr_IsValidGameType(v38)) {
              Com_sprintf(byte_193479C, 0x400u, "%s %s; map_restart", __s, v38);
              GameTypeNameForScript = Scr_GetGameTypeNameForScript(v38);
              Com_sprintf(&byte_193479C[1024], 0x400u,
                          "GAME_VOTE_GAMETYPE\x14%s", GameTypeNameForScript);
              goto LABEL_44;
            }
        LABEL_32:
          v9 = va("%c \"GAME_INVALIDGAMETYPE\"", 101);
          goto LABEL_8;
        }
        if (!I_stricmp(__s, "map_restart")) {
          Com_sprintf(byte_193479C, 0x400u, "fast_restart");
          Com_sprintf(&byte_193479C[1024], 0x400u, "GAME_VOTE_MAPRESTART");
          goto LABEL_44;
        }
        if (!I_stricmp(__s, "map_rotate")) {
          Com_sprintf(byte_193479C, 0x400u, "%s", __s);
          Com_sprintf(&byte_193479C[1024], 0x400u, "GAME_VOTE_NEXTMAP", v33);
          goto LABEL_44;
        }
        if (!I_stricmp(__s, "map")) {
            if (SV_MapExists(v38)) {
              Com_sprintf(byte_193479C, 0x400u, "%s %s", __s, v38);
              Com_sprintf(&byte_193479C[1024], 0x400u, "GAME_VOTE_MAP\x15%s",
                          v38);
              goto LABEL_44;
            }
        LABEL_50:
          v9 = va("%c \"\x15the server doesn't have that map\"", 101);
          goto LABEL_8;
        }
        if (I_stricmp(__s, "kick") && I_stricmp(__s, "clientkick") &&
            I_stricmp(__s, "tempBanUser") && I_stricmp(__s, "tempBanClient")) {
          return;
        }
        if (I_stricmp(__s, "kick") && I_stricmp(__s, "tempBanUser")) {
          v28 = atoi(v38);
          v36 = v28;
            if (v28) {
                if (v28 >= 0x40) {
                LABEL_73:
                  v9 = va("%c \"GAME_CLIENTNOTONSERVER\"", 101);
                  goto LABEL_8;
                }
            }
            else if (I_stricmp(v38, "0")) {
              goto LABEL_73;
            }
          v29 = 10404 * v36;
          v30 = 10404 * v36 + level;
          if (*(_DWORD *)(v30 + 9924) != 2)
            goto LABEL_73;
          I_strncpyz(__dst, (char *)(v30 + 10116), 64);
          I_CleanStr(__dst);
        }
        else {
          v36 = 64;
          v25 = 0;
          v26 = 0;
            do {
                if (*(_DWORD *)(level + v26 + 9924) == 2) {
                  I_strncpyz(__dst, (char *)(level + v26 + 10116), 64);
                  I_CleanStr(__dst);
                  v11 = I_stricmp(__dst, v38) == 0;
                  v27 = v36;
                  if (v11)
                    v27 = v25;
                  v36 = v27;
                }
              ++v25;
              v26 += 10404;
            }
          while (v25 != 64);
          if (v36 == 64)
            goto LABEL_73;
          v29 = 10404 * v36;
        }
      if (__s[0] == 116 || __s[0] == 84)
        v31 = "tempBanClient";
      else
        v31 = "clientkick";
      Com_sprintf(byte_193479C, 0x400u, "%s \"%d\"", v31, v36);
      Com_sprintf(&byte_193479C[1024], 0x400u, "GAME_VOTE_KICK\x15(%i)%s", v36,
                  (const char *)(level + v29 + 10116));
      goto LABEL_44;
    }
  if (!Scr_IsValidGameType(v38))
    goto LABEL_32;
  v10 = 0;
  v11 = I_stricmp(v38, *(char **)(g_gametype_0 + 8)) == 0;
  v12 = v38[0];
  if (v11)
    v12 = 0;
  v38[0] = v12;
  SV_Cmd_ArgvBuffer(3, __src, 256);
  if (!SV_MapExists(__src))
    goto LABEL_50;
  v13 = Dvar_RegisterString("mapname", (DvarValue)&inData, 0x1044u);
  if (I_stricmp(__src, (char *)v13->current.integer))
    v10 = __src[0];
  __src[0] = v10;
    if (!v38[0]) {
        if (!v10) {
          v9 = va("%c \"GAME_TYPEMAP_NOCHANGE\"", 101);
          goto LABEL_8;
        }
      Com_sprintf(byte_193479C, 0x400u, "map %s", __src);
      goto LABEL_56;
    }
    if (__src[0]) {
      Com_sprintf(byte_193479C, 0x400u, "g_gametype %s; map %s", v38, __src);
    LABEL_56:
        if (v38[0]) {
          v24 = Scr_GetGameTypeNameForScript(v38);
          Com_sprintf(&byte_193479C[1024], 0x400u,
                      "GAME_VOTE_GAMETYPE\x14%s\x15 - \x14GAME_VOTE_MAP\x15%s",
                      v24, __src);
        }
        else {
          Com_sprintf(&byte_193479C[1024], 0x400u, "GAME_VOTE_MAP\x15%s",
                      __src);
        }
      goto LABEL_44;
    }
  Com_sprintf(byte_193479C, 0x400u, "g_gametype %s; map_restart", v38);
  v35 = Scr_GetGameTypeNameForScript(v38);
  Com_sprintf(&byte_193479C[1024], 0x400u, "GAME_VOTE_GAMETYPE\x14%s", v35);
LABEL_44:
  v18 = va("%c \"GAME_CALLEDAVOTE\x15%s\"", 101,
           (const char *)(a8->client + 10116));
  SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, v18);
  dword_1934F9C = dword_193466C + 30000;
  dword_1934FA4 = 1;
  dword_1934FA8 = 0;
    if (dword_1934664 > 0) {
      v19 = 0;
      v20 = 0;
        do {
          *(_DWORD *)(level + v20 + 160) &= ~0x100000u;
          ++v19;
          v20 += 10404;
        }
      while (v19 < dword_1934664);
    }
  *(_DWORD *)(a8->client + 160) |= 0x100000u;
  v21 = va("%i", dword_1934F9C);
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0xFu, v21);
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x10u, &byte_193479C[1024]);
  v22 = va("%i", dword_1934FA4);
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x11u, v22);
  v23 = va("%i", dword_1934FA8);
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x12u, v23);
}

void __cdecl Cmd_Kill_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl StopFollowing(struct gentity_s *ent)
{
  int32_t client; // esi
  int result;     // eax
  trace_t v3;     // [esp+28h] [ebp-90h] BYREF
  float v4[3];    // [esp+4Ch] [ebp-6Ch] BYREF
  trace_t v5;     // [esp+58h] [ebp-60h] BYREF
  float v6[3];    // [esp+7Ch] [ebp-3Ch] BYREF
  float v7;       // [esp+88h] [ebp-30h] BYREF
  float v8;       // [esp+8Ch] [ebp-2Ch]
  float v9;       // [esp+90h] [ebp-28h]
  float v10[9];   // [esp+94h] [ebp-24h] BYREF

  client = a1->client;
  *(_DWORD *)(client + 9900) = -1;
  *(_DWORD *)(client + 10152) = -1;
    if ((*(_BYTE *)(client + 14) & 0x40) != 0) {
      G_GetPlayerViewOrigin(a1, &v7);
      G_GetPlayerViewDirection(a1, v6, 0, (float *)&v5.material);
      v10[0] = *(float *)(client + 232);
      v10[1] = *(float *)(client + 236);
      v10[2] = *(float *)(client + 240);
      v10[0] = v10[0] + 15.0;
      v5.normal[2] = (float)(v6[0] * -40.0) + v7;
      *(float *)&v5.surfaceFlags = (float)(v6[1] * -40.0) + v8;
      *(float *)&v5.contents = (float)(-40.0 * v6[2]) + v9;
      v5.normal[2] = (float)(*(float *)&v5.material * 10.0) + v5.normal[2];
      *(float *)&v5.surfaceFlags =
          (float)(*(float *)&v5.entityNum * 10.0) + *(float *)&v5.surfaceFlags;
      *(float *)&v5.contents =
          (float)(10.0 * *(float *)&v5.partGroup) + *(float *)&v5.contents;
      v5.fraction = -8.0;
      v5.normal[0] = -8.0;
      v5.normal[1] = -8.0;
      v4[0] = 8.0;
      v4[1] = 8.0;
      v4[2] = 8.0;
      G_TraceCapsule(&v3, &v7, &v5, v4, &v5.normal[2], 1023, flt_810011);
      v7 = v7 + (float)((float)(v5.normal[2] - v7) * v3.fraction);
      v8 = v8 + (float)((float)(*(float *)&v5.surfaceFlags - v8) * v3.fraction);
      v9 = v9 + (float)(v3.fraction * (float)(*(float *)&v5.contents - v9));
      *(_DWORD *)(client + 204) =
          -1963413621 * (((char *)a1 - (char *)&g_entities) >> 4);
      *(_DWORD *)(client + 160) &= 0xFFFFFCFF;
      *(_DWORD *)(client + 1424) = 0;
      *(_DWORD *)(client + 1428) = 1023;
      *(_DWORD *)(client + 12) &= 0xFFBFFFBF;
      *(_DWORD *)(client + 220) = 0;
      G_SetOrigin(a1, &v7);
      *(float *)(client + 20) = v7;
      *(float *)(client + 24) = v8;
      *(float *)(client + 28) = v9;
      result = SetClientViewAngle(a1, v10);
      *(_DWORD *)(client + 1496) = 0;
      *(_DWORD *)(client + 1500) = 0;
      *(_DWORD *)(client + 1504) = 0;
    }
  return result;
}

int __cdecl Cmd_FollowCycle_f(struct gentity_s *ent, int dir)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Give_f(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl ClientCommand(int clientNum)
{
  int v8;                  // eax
  int v9;                  // edx
  gentity_s *v10;          // eax
  int v11;                 // eax
  int v12;                 // ebx
  uint32_t v13;            // esi
  int v14;                 // eax
  int v15;                 // eax
  int v16;                 // esi
  unsigned int v17;        // ecx
  int v18;                 // ebx
  int v19;                 // esi
  unsigned int v20;        // ecx
  int v21;                 // ebx
  int v22;                 // esi
  unsigned int v23;        // kr04_4
  int v24;                 // edx
  const char *v25;         // eax
  bool v26;                // zf
  const char *v27;         // edx
  char *v28;               // eax
  int v29;                 // edx
  int v30;                 // edx
  int32_t client;          // ebx
  int v32;                 // ecx
  const char *v33;         // edx
  char *v34;               // eax
  int32_t v35;             // ebx
  int v36;                 // ecx
  int32_t v37;             // eax
  _DWORD *v38;             // edx
  int v39;                 // ebx
  int v40;                 // esi
  _DWORD *v41;             // edx
  int v42;                 // ebx
  int v43;                 // esi
  char *v44;               // eax
  char *v45;               // [esp+8h] [ebp-3370h]
  int v46;                 // [esp+3Ch] [ebp-333Ch]
  int v47;                 // [esp+40h] [ebp-3338h]
  int v48;                 // [esp+44h] [ebp-3334h]
  gentity_s *v49;          // [esp+48h] [ebp-3330h]
  int v50;                 // [esp+4Ch] [ebp-332Ch]
  int v51;                 // [esp+50h] [ebp-3328h]
  int v52;                 // [esp+54h] [ebp-3324h]
  int v53;                 // [esp+58h] [ebp-3320h]
  int number;              // [esp+5Ch] [ebp-331Ch]
  int Guid;                // [esp+60h] [ebp-3318h]
  gentity_s *v56;          // [esp+64h] [ebp-3314h]
  int v57;                 // [esp+68h] [ebp-3310h]
  int v58;                 // [esp+6Ch] [ebp-330Ch]
  playerState_s v59;       // [esp+78h] [ebp-3300h] BYREF
  char v60[1024];          // [esp+2720h] [ebp-C58h] BYREF
  char v61[1024];          // [esp+2B20h] [ebp-858h] BYREF
  clientState_s __src[11]; // [esp+2F20h] [ebp-458h] BYREF
  char __dst[88];          // [esp+3320h] [ebp-58h] BYREF

  v49 = &g_entities + a8;
  if (!v49->client)
    return;
  SV_Cmd_ArgvBuffer(0, v60, 1024);
    if (!I_stricmp(v60, "say")) {
        if (SV_Cmd_Argc() > 1) {
          v8 = SV_Cmd_Argc();
          v50 = v8;
            if (v8 > 1) {
              v16 = 1;
              v51 = 0;
              v48 = v8 - 1;
                do {
                  SV_Cmd_ArgvBuffer(v16, (char *)__src, 1024);
                  v17 = strlen((const char *)__src) + 1;
                  v18 = v17 - 1 + v51;
                  if (v18 > 1022)
                    break;
                  memcpy((void *)(v51 + 15931264), __src, v17 - 1);
                  if (v16 != v48)
                    ConcatArgs(int)::line[v18++] = 32;
                  v51 = v18;
                  ++v16;
                }
              while (v50 != v16);
            }
            else {
              v51 = 0;
            }
          ConcatArgs(int)::line[v51] = 0;
          G_Say(v49, 0, 0, ConcatArgs(int)::line);
        }
      return;
    }
    if (!I_stricmp(v60, "say_team")) {
        if (SV_Cmd_Argc() > 1) {
          v15 = SV_Cmd_Argc();
          v52 = v15;
            if (v15 > 1) {
              v19 = 1;
              v53 = 0;
              v47 = v15 - 1;
                do {
                  SV_Cmd_ArgvBuffer(v19, v59.commandTime, 1024);
                  v20 = strlen(v59.commandTime) + 1;
                  v21 = v20 - 1 + v53;
                  if (v21 > 1022)
                    break;
                  memcpy((void *)(v53 + 15931264), &v59, v20 - 1);
                  if (v19 != v47)
                    ConcatArgs(int)::line[v21++] = 32;
                  v53 = v21;
                  ++v19;
                }
              while (v52 != v19);
            }
            else {
              v53 = 0;
            }
          ConcatArgs(int)::line[v53] = 0;
          G_Say(v49, 0, 1, ConcatArgs(int)::line);
        }
      return;
    }
    if (!I_stricmp(v60, "tell")) {
        if (SV_Cmd_Argc() > 1) {
          SV_Cmd_ArgvBuffer(1, v61, 1024);
          v9 = atoi(v61);
            if (v9 >= 0 && v9 < dword_1934664) {
              v10 = &g_entities + v9;
              v56 = v10;
                if (v10) {
                    if (v10->r.inuse && v10->client) {
                      v11 = SV_Cmd_Argc();
                      v57 = v11;
                        if (v11 > 2) {
                          v22 = 2;
                          v58 = 0;
                          v46 = v11 - 1;
                            while (1) {
                              SV_Cmd_ArgvBuffer(v22, v59.commandTime, 1024);
                              v23 = strlen(v59.commandTime) + 1;
                              v12 = v23 - 1 + v58;
                              if (v12 > 1022)
                                break;
                              memcpy((void *)(v58 + 15931264), &v59, v23 - 1);
                                if (v22 != v46) {
                                  ConcatArgs(int)::line[v12] = 32;
                                  v12 = v23 + v58;
                                }
                              if (v57 == ++v22)
                                goto LABEL_18;
                              v58 = v12;
                            }
                          v12 = v58;
                        }
                        else {
                          v12 = 0;
                        }
                    LABEL_18:
                      ConcatArgs(int)::line[v12] = 0;
                      I_strncpyz(__dst, (char *)(v49->client + 10116), 64);
                      I_CleanStr(__dst);
                      I_strncpyz((char *)__src, (char *)(v56->client + 10116),
                                 64);
                      I_CleanStr((char *)__src);
                      number = v56->s.number;
                      Guid = SV_GetGuid(v56->s.number);
                      v13 = v49->s.number;
                      v14 = SV_GetGuid(v49->s.number);
                      G_LogPrintf("tell;%d;%d;%s;%d;%d;%s;%s\n", v14, v13,
                                  __dst, Guid, number, (const char *)__src,
                                  ConcatArgs(int)::line);
                      G_Say(v49, v56, 2, ConcatArgs(int)::line);
                      G_Say(v49, v49, 2, ConcatArgs(int)::line);
                    }
                }
            }
        }
      return;
    }
    if (!I_stricmp(v60, "score")) {
      DeathmatchScoreboardMessage(v49);
      return;
    }
    if (*(_DWORD *)(v49->client + 4) != 5) {
        if (!I_stricmp(v60, "mr")) {
          Cmd_MenuResponse_f(a1, a2, a3, a4, a5, a6, a7, v49);
          return;
        }
        if (!I_stricmp(v60, "give")) {
          Cmd_Give_f(a1, a3, a4, a5, a6, a7, v49);
          return;
        }
        if (!I_stricmp(v60, "take")) {
          Cmd_Take_f(v49);
          return;
        }
        if (!I_stricmp(v60, "god")) {
          if (!CheatsOk(v49))
            return;
          v24 = v49->flags ^ 1;
          v49->flags = v24;
          v25 = "GAME_GODMODE_ON";
          v26 = (v24 & 1) == 0;
          v27 = "GAME_GODMODE_OFF";
        LABEL_54:
          if (v26)
            v25 = v27;
          goto LABEL_56;
        }
        if (!I_stricmp(v60, "demigod")) {
          if (!CheatsOk(v49))
            return;
          v29 = v49->flags ^ 2;
          v49->flags = v29;
          v25 = "GAME_DEMI_GODMODE_ON";
          v26 = (v29 & 2) == 0;
          v27 = "GAME_DEMI_GODMODE_OFF";
          goto LABEL_54;
        }
        if (!I_stricmp(v60, "notarget")) {
          if (!CheatsOk(v49))
            return;
          v30 = v49->flags ^ 4;
          v49->flags = v30;
          v25 = "GAME_NOTARGETOFF";
          if ((v30 & 4) != 0)
            v25 = "GAME_NOTARGETON";
        LABEL_56:
          v28 = va("%c \"%s\"", 101, v25);
          SV_GameSendServerCommand(-1963413621 * ((560 * a8) >> 4),
                                   SV_CMD_CAN_IGNORE, v28);
          return;
        }
        if (!I_stricmp(v60, "noclip")) {
          if (!CheatsOk(v49))
            return;
          client = v49->client;
          v32 = *(_DWORD *)(client + 10156);
          v33 = "GAME_NOCLIPOFF";
          if (!v32)
            v33 = "GAME_NOCLIPON";
          *(_DWORD *)(client + 10156) = v32 == 0;
        LABEL_70:
          v34 = va("%c \"%s\"", 101, v33);
          goto LABEL_71;
        }
        if (!I_stricmp(v60, "ufo")) {
          if (!CheatsOk(v49))
            return;
          v35 = v49->client;
          v36 = *(_DWORD *)(v35 + 10160);
          v33 = "GAME_UFOOFF";
          if (!v36)
            v33 = "GAME_UFOON";
          *(_DWORD *)(v35 + 10160) = v36 == 0;
          goto LABEL_70;
        }
        if (!I_stricmp(v60, "kill")) {
          v37 = v49->client;
            if (!*(_DWORD *)(v37 + 9896)) {
              v49->flags &= 0xFFFFFFFC;
              v49->health = 0;
              *(_DWORD *)(v37 + 300) = 0;
              player_die(a1, a2, a3, a4, a5, a6, a7, v49, v49, v49, 100000,
                         0xCu, 0, 0, HITLOC_NONE, 0);
            }
          return;
        }
        if (I_stricmp(v60, "follownext")) {
            if (I_stricmp(v60, "followprev")) {
                if (I_stricmp(v60, "where")) {
                    if (I_stricmp(v60, "callvote")) {
                        if (I_stricmp(v60, "vote")) {
                            if (I_stricmp(v60, "gc")) {
                                if (I_stricmp(v60, "setviewpos")) {
                                    if (I_stricmp(v60, "entitycount")) {
                                        if (I_stricmp(v60, "printentities")) {
                                          v44 =
                                              va("%c "
                                                 "\"GAME_"
                                                 "UNKNOWNCLIENTCOMMAND\x15%s\"",
                                                 101, v60);
                                          SV_GameSendServerCommand(
                                              a8, SV_CMD_CAN_IGNORE, v44);
                                        }
                                        else {
                                          G_PrintEntities();
                                        }
                                    }
                                    else if (*(_BYTE *)(g_cheats + 8)) {
                                      Com_Printf("entity count = %i\n",
                                                 dword_193448C);
                                    }
                                }
                                else {
                                  Cmd_SetViewpos_f(v49);
                                }
                            }
                            else {
                              Cmd_GameCommand_f(v49);
                            }
                        }
                        else {
                          Cmd_Vote_f(a1, a2, a3, a4, a5, a6, a7, v49);
                        }
                    }
                    else {
                      Cmd_CallVote_f(a1, a2, a3, a4, a5, a6, a7, v49);
                    }
                  return;
                }
              v45 = vtos(v49->r.currentOrigin);
              v34 = va("%c \"\x15%s\n\"", 101, v45);
            LABEL_71:
              SV_GameSendServerCommand(-1963413621 * ((560 * a8) >> 4),
                                       SV_CMD_CAN_IGNORE, v34);
              return;
            }
          v41 = (_DWORD *)v49->client;
            if (v41[2474] == 2 && (int)v41[2475] < 0) {
              v42 = 0;
              if ((int)v41[2538] >= 0)
                v42 = v41[2538];
              v43 = v42;
                while (1) {
                    if (--v42 < dword_1934664) {
                      if (v42 <= -1)
                        v42 = dword_1934664 - 1;
                    }
                    else {
                      v42 = 0;
                    }
                    if (SV_GetArchivedClientInfo(
                            v42, (int *)(v49->client + 9908), &v59, __src) &&
                        G_ClientCanSpectateTeam((gclient_s *)v49->client,
                                                (team_t)__src[0].team)) {
                      break;
                    }
                  if (v43 == v42)
                    return;
                }
              *(_DWORD *)(v49->client + 10152) = v42;
              *(_DWORD *)(v49->client + 9896) = 2;
            }
        }
        else {
          v38 = (_DWORD *)v49->client;
            if (v38[2474] == 2 && (int)v38[2475] < 0) {
              v39 = 0;
              if ((int)v38[2538] >= 0)
                v39 = v38[2538];
              v40 = v39;
                while (1) {
                    if (++v39 < dword_1934664) {
                      if (v39 <= -1)
                        v39 = dword_1934664 - 1;
                    }
                    else {
                      v39 = 0;
                    }
                    if (SV_GetArchivedClientInfo(
                            v39, (int *)(v49->client + 9908), &v59, __src) &&
                        G_ClientCanSpectateTeam((gclient_s *)v49->client,
                                                (team_t)__src[0].team)) {
                      break;
                    }
                  if (v40 == v39)
                    return;
                }
              *(_DWORD *)(v49->client + 10152) = v39;
              *(_DWORD *)(v49->client + 9896) = 2;
            }
        }
    }
}

void __cdecl G_SayTo(struct gentity_s *, struct gentity_s *, int, int,
                     char const *, char const *)
{
  int32_t client; // eax
  int v10;        // eax
  char *v11;      // eax

    if (a2) {
        if (a2->r.inuse) {
          client = a2->client;
            if (client) {
                if (*(_DWORD *)(client + 9924) == 2 &&
                    (a3 != 1 || OnSameTeam(a1, a2)) &&
                    (*(_BYTE *)(g_deadChat + 8) ||
                     !*(_DWORD *)(a1->client + 9896) ||
                     *(_DWORD *)(a2->client + 9896))) {
                  if (a3 == 1)
                    v10 = 105;
                  else
                    v10 = 104;
                  v11 = va("%c \"\x15%s%c%c%s\"", v10, (const char *)a5, 94, a4,
                           a6);
                  SV_GameSendServerCommand(
                      -1963413621 * (((char *)a2 - (char *)&g_entities) >> 4),
                      SV_CMD_CAN_IGNORE, v11);
                }
            }
        }
    }
}

void __cdecl Cmd_PrintEntities_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Tell_f(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Cmd_Say_f(struct gentity_s *, int, int)
{
  UNIMPLEMENTED();
}
