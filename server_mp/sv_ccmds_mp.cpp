void __cdecl SV_RemoveOperatorCommands() { ; }

void __cdecl SV_GameCompleteStatus_f() { SV_MasterGameCompleteStatus(); }

void __cdecl SV_Heartbeat_f() { UNIMPLEMENTED(); }

void __cdecl SV_RemoveDedicatedCommands(void) { UNIMPLEMENTED(); }

char const *__cdecl SV_GetMapBaseName(char const *mapname) {
  return FS_GetMapBaseName(__src);
}

void __cdecl SV_AddDedicatedCommands() {
  Cmd_AddCommand("say", SV_ConSay_f);
  Cmd_AddCommand("tell", SV_ConTell_f);
}

void __cdecl SV_AddOperatorCommands() {
  if (!SV_AddOperatorCommands(void)::initialized) {
    SV_AddOperatorCommands(void)::initialized = 1;
    Cmd_AddCommand("heartbeat", (void (*)(void))SV_Heartbeat_f);
    Cmd_AddCommand("onlykick", (void (*)(void))SV_Drop_f);
    Cmd_AddCommand("banUser", (void (*)(void))SV_Ban_f);
    Cmd_AddCommand("banClient", (void (*)(void))SV_BanNum_f);
    Cmd_AddCommand("kick", (void (*)(void))SV_TempBan_f);
    Cmd_AddCommand("tempBanUser", (void (*)(void))SV_TempBan_f);
    Cmd_AddCommand("tempBanClient", (void (*)(void))SV_TempBanNum_f);
    Cmd_AddCommand("unbanUser", SV_Unban_f);
    Cmd_AddCommand("clientkick", (void (*)(void))SV_DropNum_f);
    Cmd_AddCommand("status", SV_Status_f);
    Cmd_AddCommand("serverinfo", SV_Serverinfo_f);
    Cmd_AddCommand("systeminfo", SV_Systeminfo_f);
    Cmd_AddCommand("dumpuser", SV_DumpUser_f);
    Cmd_AddCommand("map_restart", (void (*)(void))SV_MapRestart_f);
    Cmd_AddCommand("fast_restart", (void (*)(void))SV_FastRestart_f);
    Cmd_AddCommand("map", (void (*)(void))SV_Map_f);
    Cmd_SetAutoComplete("map", "maps/mp", "d3dbsp");
    Cmd_AddCommand("map_rotate", (void (*)(void))SV_MapRotate_f);
    Cmd_AddCommand("gameCompleteStatus", SV_GameCompleteStatus_f);
    Cmd_AddCommand("devmap", (void (*)(void))SV_Map_f);
    Cmd_SetAutoComplete("devmap", "maps/mp", "d3dbsp");
    Cmd_AddCommand("killserver", (void (*)(void))SV_KillServer_f);
    if (*(_DWORD *)(com_dedicated + 8)) {
      Cmd_AddCommand("say", SV_ConSay_f);
      Cmd_AddCommand("tell", SV_ConTell_f);
    }
    Cmd_AddCommand("scriptUsage", (void (*)(void))SV_ScriptUsage_f);
    Cmd_AddCommand("stringUsage", SV_StringUsage_f);
  }
}

void __cdecl SV_MapRotate_f(void) {
  char *integer;  // eax
  char *v8;       // ebx
  char *v9;       // ebx
  char *v10;      // ebx
  char *v11;      // eax
  char v12;       // [esp+8h] [ebp-30h]
  char *__src[7]; // [esp+1Ch] [ebp-1Ch] BYREF

  Com_Printf("map_rotate...\n\n");
  Com_Printf("\"sv_mapRotation\" is:\"%s\"\n\n",
             *(const char **)(sv_mapRotation + 8));
  Com_Printf("\"sv_mapRotationCurrent\" is:\"%s\"\n\n",
             (const char *)sv_mapRotationCurrent->current.integer);
  integer = (char *)sv_mapRotationCurrent->current.integer;
  if (!*integer) {
    Dvar_SetString(sv_mapRotationCurrent, *(char **)(sv_mapRotation + 8));
    integer = (char *)sv_mapRotationCurrent->current.integer;
  }
  __src[0] = integer;
  v8 = Com_Parse(__src);
  if (!__src[0]) {
    Dvar_SetString(sv_mapRotationCurrent, (char *)&inData);
    goto LABEL_19;
  }
  Dvar_SetString(sv_mapRotationCurrent, __src[0]);
  if (!v8) {
  LABEL_19:
    Dvar_SetString(sv_mapRotationCurrent, *(char **)(sv_mapRotation + 8));
    goto LABEL_10;
  }
  while (!stricmp(v8, "gametype")) {
    __src[0] = (char *)sv_mapRotationCurrent->current.integer;
    v9 = Com_Parse(__src);
    if (!__src[0]) {
      Dvar_SetString(sv_mapRotationCurrent, (char *)&inData);
    LABEL_21:
      Com_Printf("No gametype specified after 'gametype' keyword in "
                 "sv_mapRotation - forcing map_restart.\n");
      SV_MapRestart(1, a1, a2, a3, a4, a5, a6, a7);
      return;
    }
    Dvar_SetString(sv_mapRotationCurrent, __src[0]);
    if (!v9)
      goto LABEL_21;
    Com_Printf("Setting g_gametype: %s.\n", v9);
    if (*(_BYTE *)(com_sv_running + 8)) {
      if (stricmp(*(const char **)(sv_gametype + 8), v9))
        G_SetSavePersist(0);
    }
    Dvar_SetString((dvar_s *)sv_gametype, v9);
  LABEL_10:
    __src[0] = (char *)sv_mapRotationCurrent->current.integer;
    v8 = Com_Parse(__src);
    if (!__src[0]) {
      Dvar_SetString(sv_mapRotationCurrent, (char *)&inData);
    LABEL_12:
      Com_Printf("No map specified in sv_mapRotation - forcing map_restart.\n");
      SV_MapRestart(1, a1, a2, a3, a4, a5, a6, a7);
      return;
    }
    Dvar_SetString(sv_mapRotationCurrent, __src[0]);
    if (!v8)
      goto LABEL_12;
  }
  if (stricmp(v8, "map")) {
    Com_Printf("Unknown keyword '%s' in sv_mapRotation.\n", v8);
    goto LABEL_10;
  }
  __src[0] = (char *)sv_mapRotationCurrent->current.integer;
  v10 = Com_Parse(__src);
  if (__src[0]) {
    Dvar_SetString(sv_mapRotationCurrent, __src[0]);
    if (v10) {
      Com_Printf("Setting map: %s.\n", v10);
      v11 = va("map %s\n", v10);
      Cbuf_ExecuteText(0, v11, v12);
      return;
    }
  } else {
    Dvar_SetString(sv_mapRotationCurrent, (char *)&inData);
  }
  Com_Printf("No map specified after 'map' keyword in sv_mapRotation - forcing "
             "map_restart.\n");
  SV_MapRestart(1, a1, a2, a3, a4, a5, a6, a7);
}

void __cdecl SV_StringUsage_f(void) { MT_DumpTree(); }

void __cdecl SV_ScriptUsage_f(void) { Scr_DumpScriptThreads(a1); }

void __cdecl SV_ConTell_f(void) {
  const char *v0; // eax
  int v1;         // ecx
  client_s *v2;   // ebx
  char *v3;       // eax
  char *v4;       // edx
  char v5[1048];  // [esp+20h] [ebp-418h] BYREF

  if (*(_BYTE *)(com_sv_running + 8)) {
    if (SV_Cmd_Argc() > 2) {
      v0 = (const char *)SV_Cmd_Argv(1);
      v1 = atoi(v0);
      if (v1 >= 0 && v1 < *(_DWORD *)(sv_maxclients + 8)) {
        v2 = (client_s *)((char *)dword_170048C + 495372 * v1);
        if (v2->state == 4) {
          strcpy(v5, "console: ");
          v3 = Cmd_Args(2);
          v4 = v3;
          if (*v3 == 34) {
            v4 = v3 + 1;
            v3[strlen(v3 + 1)] = 0;
          }
          I_strncat(v5, 1024, v4);
          SV_SendServerCommand(v2, SV_CMD_CAN_IGNORE, "%c \"\x15%s\"", 104, v5);
        }
      }
    }
  } else {
    Com_Printf("Server is not running.\n");
  }
}

void __cdecl SV_ConSay_f(void) {
  char *v0;      // eax
  char *v1;      // edx
  char v2[1032]; // [esp+20h] [ebp-408h] BYREF

  if (*(_BYTE *)(com_sv_running + 8)) {
    if (SV_Cmd_Argc() > 1) {
      strcpy(v2, "console: ");
      v0 = Cmd_Args(1);
      v1 = v0;
      if (*v0 == 34) {
        v1 = v0 + 1;
        v0[strlen(v0 + 1)] = 0;
      }
      I_strncat(v2, 1024, v1);
      SV_SendServerCommand(0, SV_CMD_CAN_IGNORE, "%c \"\x15%s\"", 104, v2);
    }
  } else {
    Com_Printf("Server is not running.\n");
  }
}

void __cdecl SV_Status_f(void) {
  char *v0;        // esi
  int ClientScore; // eax
  int v2;          // eax
  int v3;          // eax
  int v4;          // ebx
  char *v5;        // edi
  unsigned int v6; // kr04_4
  int i;           // edi
  int v8;          // edi
  __int128 v9;     // [esp+0h] [ebp-48h]
  int v10;         // [esp+18h] [ebp-30h]
  client_s *v11;   // [esp+1Ch] [ebp-2Ch]

  if (*(_BYTE *)(com_sv_running + 8)) {
    Com_Printf("map: %s\n", *(const char **)(sv_mapname + 8));
    Com_Printf("num score ping guid   name            lastmsg address          "
               "     qport rate\n");
    Com_Printf("--- ----- ---- ------ --------------- ------- "
               "--------------------- ----- -----\n");
    v11 = dword_170048C;
    if (*(int *)(sv_maxclients + 8) > 0) {
      v10 = 0;
      v0 = &dword_170048C->name[2];
      do {
        while (!*((_DWORD *)v0 - 33554)) {
          ++v10;
          v11 = (client_s *)((char *)v11 + 495372);
          v0 += 495372;
          if (v10 >= *(_DWORD *)(sv_maxclients + 8))
            goto LABEL_15;
        }
        Com_Printf("%3i ", v10);
        SV_GameClientNum(v10);
        ClientScore = G_GetClientScore(
            931767531 * (((char *)v11 - (char *)dword_170048C) >> 2));
        Com_Printf("%5i ", ClientScore);
        v2 = *((_DWORD *)v0 - 33554);
        if (v2 == 2) {
          Com_Printf("CNCT ");
        } else if (v2 == 1) {
          Com_Printf("ZMBI ");
        } else {
          v3 = *(_DWORD *)((char *)&loc_4D95C + (_DWORD)v0);
          if (v3 >= 10000)
            v3 = 9999;
          Com_Printf("%4i ", v3);
        }
        Com_Printf("%6i ", *((_DWORD *)v0 + 87657));
        Com_Printf("%s^7", v0);
        v4 = 16 - I_DrawStrlen(v0);
        if (v4 > 0) {
          for (i = 0; i != v4; ++i)
            Com_Printf(" ");
        }
        Com_Printf("%7i ", dword_1700484 - *((_DWORD *)v0 + 50));
        LODWORD(v9) = *(_DWORD *)((char *)&loc_4D97C + (_DWORD)v0);
        DWORD1(v9) = *(_DWORD *)((char *)&loc_4D980 + (_DWORD)v0);
        DWORD2(v9) = *(_DWORD *)((char *)&loc_4D984 + (_DWORD)v0);
        v5 = NET_AdrToString(v9);
        Com_Printf("%s", v5);
        v6 = strlen(v5) + 1;
        if ((int)(23 - v6) > 0) {
          v8 = 0;
          do {
            Com_Printf(" ");
            ++v8;
          } while (23 - v6 != v8);
        }
        Com_Printf("%5i", *((_DWORD *)v0 + 79458));
        Com_Printf(" %5i", *((_DWORD *)v0 + 79448));
        Com_Printf("\n");
        ++v10;
        v11 = (client_s *)((char *)v11 + 495372);
        v0 += 495372;
      } while (v10 < *(_DWORD *)(sv_maxclients + 8));
    }
  LABEL_15:
    Com_Printf("\n");
  } else {
    Com_Printf("Server is not running.\n");
  }
}

void __cdecl SV_Unban_f(void) {
  char *v0; // eax

  if (SV_Cmd_Argc() == 2) {
    v0 = (char *)SV_Cmd_Argv(1);
    SV_UnbanClient(v0);
  } else {
    Com_Printf("Usage: unban <client name>\n");
  }
}

struct client_s *__cdecl SV_GetPlayerByNum(void) {
  UNIMPLEMENTED();
}

struct client_s *__cdecl SV_GetPlayerByName(void) {
  UNIMPLEMENTED();
}

void __cdecl SV_DumpUser_f(void) {
  client_s *PlayerByName; // ebx

  if (*(_BYTE *)(com_sv_running + 8)) {
    if (SV_Cmd_Argc() == 2) {
      PlayerByName = SV_GetPlayerByName();
      if (PlayerByName) {
        Com_Printf("userinfo\n");
        Com_Printf("--------\n");
        Info_Print(PlayerByName->userinfo);
      }
    } else {
      Com_Printf("Usage: info <userid>\n");
    }
  } else {
    Com_Printf("Server is not running.\n");
  }
}

void __cdecl SV_Systeminfo_f(void) {
  char *v0; // eax

  Com_Printf("System info settings:\n");
  v0 = Dvar_InfoString(8u);
  Info_Print(v0);
}

void __cdecl SV_Serverinfo_f(void) {
  char *v0; // eax

  Com_Printf("Server info settings:\n");
  v0 = Dvar_InfoString(0x404u);
  Info_Print(v0);
}

void __cdecl SV_BanNum_f(void) {
  client_s *PlayerByNum; // eax

  if (*(_BYTE *)(com_sv_running + 8)) {
    if (SV_Cmd_Argc() == 2) {
      PlayerByNum = (client_s *)SV_GetPlayerByNum();
      if (PlayerByNum)
        SV_BanClient(a1, PlayerByNum);
    } else {
      Com_Printf("Usage: banClient <client number>\n");
    }
  } else {
    Com_Printf("Server is not running.\n");
  }
}

void __cdecl SV_Ban_f(void) {
  client_s *PlayerByName; // eax

  if (*(_BYTE *)(com_sv_running + 8)) {
    if (SV_Cmd_Argc() == 2) {
      PlayerByName = SV_GetPlayerByName();
      if (PlayerByName)
        SV_BanClient(a1, PlayerByName);
    } else {
      Com_Printf("Usage: banUser <player name>\n");
    }
  } else {
    Com_Printf("Server is not running.\n");
  }
}

int __cdecl SV_KickClient(struct client_s *, char *, int) { UNIMPLEMENTED(); }

int __cdecl SV_KickClient_f(char *, int) { UNIMPLEMENTED(); }

int __cdecl SV_KickUser_f(char *, int) { UNIMPLEMENTED(); }

void __cdecl SV_TempBanNum_f(void) { UNIMPLEMENTED(); }

void __cdecl SV_DropNum_f(void) { UNIMPLEMENTED(); }

void __cdecl SV_Drop_f(void) { UNIMPLEMENTED(); }

void __cdecl SV_TempBan_f(void) { UNIMPLEMENTED(); }

void __cdecl SV_KillServer_f(void) { UNIMPLEMENTED(); }

void __cdecl SV_MapRestart(int) {
  char *String;    // eax
  int v10;         // esi
  int v11;         // esi
  int v12;         // edi
  char *v13;       // ebx
  char *v14;       // eax
  char *v15;       // eax
  int SavePersist; // [esp+1Ch] [ebp-5Ch]
  char __dst[88];  // [esp+20h] [ebp-58h] BYREF

  if (*(_BYTE *)(com_sv_running + 8)) {
    SV_SetGametype();
    I_strncpyz((char *)&dword_1700390[25], *(char **)(sv_gametype + 8), 64);
    SavePersist = G_GetSavePersist();
    if (!*(_BYTE *)(sv_maxclients + 7) &&
        !stricmp((const char *)&dword_1700390[25],
                 *(const char **)(sv_gametype + 8)) &&
        a1) {
      if (sv[2] != com_frameTime) {
        SV_InitDvar();
        SV_InitArchivedSnapshot();
        unk_1700488 ^= 4u;
        sv_serverId_value =
            (((_BYTE)sv_serverId_value + 1) & 0xF) + (sv_serverId_value & 0xF0);
        Dvar_SetInt(sv_serverid, sv_serverId_value);
        sv[2] = com_frameTime;
        sv[0] = 1;
        sv[1] = 1;
        SV_RestartGameProgs(a2, a3.f32[0], a4, a5, a6, a7, a8, SavePersist);
        v10 = 3;
        do {
          dword_1700484 += 100;
          SV_RunFrame(a2, a3, a4, a5, a6, a7, a8);
          --v10;
        } while (v10);
        if (*(int *)(sv_maxclients + 8) > 0) {
          v11 = 0;
          v12 = 0;
          do {
            v13 = (char *)dword_170048C + v12;
            if (*(int *)((char *)&dword_170048C->state + v12) > 1) {
              v14 = va("%c", SavePersist == 0 ? 66 : 110);
              SV_AddServerCommand((client_s *)v13, SV_CMD_RELIABLE, v14);
              v15 = (char *)ClientConnect(a2, a3.f32[0], a4, a5, a6, a7, a8,
                                          v11, *((_WORD *)v13 + 242424));
              if (v15) {
                SV_DropClient(a3.f32[0], (client_s *)v13, v15);
                Com_Printf("SV_MapRestart_f: dropped client %i - denied!\n",
                           v11);
              } else if (*(_DWORD *)v13 == 4) {
                SV_ClientEnterWorld(a3.f32[0], (client_s *)v13,
                                    (usercmd_s *)(v13 + 133156));
              }
            }
            ++v11;
            v12 += 495372;
          } while (v11 < *(_DWORD *)(sv_maxclients + 8));
        }
        sv[0] = 2;
        sv[1] = 0;
      }
    } else {
      G_SetSavePersist(0);
      String = (char *)Dvar_GetString("mapname");
      I_strncpyz(__dst, String, 64);
      FS_ConvertPath(__dst);
      SV_SpawnServer(a2, a3, a4, a5, a6, a7, a8, __dst);
    }
  } else {
    Com_Printf("Server is not running.\n");
  }
}

void __cdecl SV_Map_f(void) {
  char *v7;           // ebx
  char *MapBaseName;  // eax
  char *BspExtension; // eax
  char *v10;          // ebx
  char *v11;          // eax
  int v12;            // ebx
  char __dst[72];     // [esp+10h] [ebp-48h] BYREF

  v7 = (char *)SV_Cmd_Argv(1);
  if (*v7) {
    if (Com_HasPlayerProfile()) {
      MapBaseName = FS_GetMapBaseName(v7);
      I_strncpyz(__dst, MapBaseName, 64);
      I_strlwr(__dst);
      BspExtension = GetBspExtension();
      v10 = va("maps/mp/%s.%s", __dst, BspExtension);
      if (FS_ReadFile(v10, 0) == -1) {
        Com_Printf("Can't find map %s\n", v10);
      } else {
        v11 = (char *)SV_Cmd_Argv(0);
        v12 = I_stricmp(v11, "devmap");
        FS_ConvertPath(__dst);
        SV_SpawnServer(a1, a2, a3, a4, a5, a6, a7, __dst);
        Dvar_SetBool(sv_cheats, v12 == 0);
      }
    } else {
      Com_Printf("Can't load a map without a player profile selected.\n");
    }
  }
}

void __cdecl SV_FastRestart_f(void) {
  SV_MapRestart(1, a1, a2, a3, a4, a5, a6, a7);
}

void __cdecl SV_MapRestart_f(void) {
  SV_MapRestart(0, a1, a2, a3, a4, a5, a6, a7);
}
