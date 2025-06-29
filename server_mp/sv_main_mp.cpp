void __cdecl SV_CalcPings(void) { UNIMPLEMENTED(); }

char *__cdecl SV_ExpandNewlines(char *) { UNIMPLEMENTED(); }

void __cdecl SVC_Info(struct netadr_t from) {
  int v1;               // ecx
  int v2;               // edi
  int v3;               // esi
  int v4;               // ebx
  const char *v5;       // eax
  char *v6;             // eax
  int v7;               // eax
  char *v8;             // eax
  int v9;               // eax
  int v10;              // eax
  const char *String;   // eax
  const char *v12;      // ebx
  unsigned __int8 v13;  // al
  unsigned __int8 v14;  // al
  const gentity_s *v15; // eax
  int Int;              // eax
  int v17;              // eax
  char *v18;            // eax
  int v19;              // eax
  char *v20;            // eax
  char *v21;            // eax
  char *v23;            // eax
  char *v24;            // eax
  char *v25;            // eax
  char *v26;            // eax
  int *v27;             // edx
  client_s *v28;        // edx
  int v29;              // ebx
  char *v30;            // eax
  char *v31;            // eax
  char *v32;            // eax
  char *v33;            // eax
  int v34;              // edi
  int v35;              // ebx
  char *v36;            // eax
  char __dst[1024];     // [esp+34h] [ebp-824h] BYREF
  char __s1[1024];      // [esp+434h] [ebp-424h] BYREF
  __int64 v39;          // [esp+834h] [ebp-24h]
  int v40;              // [esp+83Ch] [ebp-1Ch]

  v1 = *(_DWORD *)(sv_privateClients + 8);
  if (v1 > 0) {
    v28 = dword_170048C;
    v29 = 0;
    v2 = 0;
    do {
      if (v28->state >= 2)
        ++v2;
      ++v29;
      v28 = (client_s *)((char *)v28 + 495372);
    } while (v1 != v29);
  } else {
    v2 = 0;
  }
  v3 = *(_DWORD *)(sv_maxclients + 8);
  if (v1 < v3) {
    v27 = &dword_170048C->state + 123843 * v1;
    v4 = v2;
    do {
      if (*v27 >= 2)
        ++v4;
      ++v1;
      v27 += 123843;
    } while (v3 > v1);
  } else {
    v4 = v2;
  }
  __s1[0] = 0;
  v5 = (const char *)SV_Cmd_Argv(1);
  Info_SetValueForKey(__s1, "challenge", v5);
  v6 = va("%i", 115);
  Info_SetValueForKey(__s1, "protocol", v6);
  Info_SetValueForKey(__s1, "hostname", *(const char **)(sv_hostname + 8));
  Info_SetValueForKey(__s1, "mapname", *(const char **)(sv_mapname + 8));
  if (v4) {
    v33 = va("%i", v4);
    Info_SetValueForKey(__s1, "clients", v33);
  }
  v7 = *(_DWORD *)(sv_privateClients + 8) - v2;
  if (*(_DWORD *)(sv_maxclients + 8) - v7 > 0) {
    v8 = va("%i", *(_DWORD *)(sv_maxclients + 8) - v7);
    Info_SetValueForKey(__s1, "sv_maxclients", v8);
  }
  Info_SetValueForKey(__s1, "gametype", *(const char **)(sv_gametype + 8));
  if (*(_BYTE *)(sv_pure + 8) || fs_numServerIwds) {
    Info_SetValueForKey(__s1, "pure", "1");
    v9 = *(_DWORD *)(sv_minPing + 8);
    if (!v9) {
    LABEL_12:
      v10 = *(_DWORD *)(sv_maxPing + 8);
      if (!v10)
        goto LABEL_13;
      goto LABEL_32;
    }
  } else {
    v9 = *(_DWORD *)(sv_minPing + 8);
    if (!v9)
      goto LABEL_12;
  }
  v23 = va("%i", v9);
  Info_SetValueForKey(__s1, "minPing", v23);
  v10 = *(_DWORD *)(sv_maxPing + 8);
  if (!v10) {
  LABEL_13:
    String = (const char *)Dvar_GetString("fs_game");
    v12 = String;
    if (!*String)
      goto LABEL_14;
    goto LABEL_33;
  }
LABEL_32:
  v24 = va("%i", v10);
  Info_SetValueForKey(__s1, "maxPing", v24);
  String = (const char *)Dvar_GetString("fs_game");
  v12 = String;
  if (!*String) {
  LABEL_14:
    v13 = *(_BYTE *)(sv_allowAnonymous + 8);
    if (!v13)
      goto LABEL_15;
  LABEL_34:
    v25 = va("%i", v13);
    Info_SetValueForKey(__s1, "sv_allowAnonymous", v25);
    v14 = *(_BYTE *)(sv_disableClientConsole + 8);
    if (!v14)
      goto LABEL_16;
  LABEL_35:
    v26 = va("%i", v14);
    Info_SetValueForKey(__s1, "con_disabled", v26);
    goto LABEL_16;
  }
LABEL_33:
  Info_SetValueForKey(__s1, "game", String);
  v13 = *(_BYTE *)(sv_allowAnonymous + 8);
  if (v13)
    goto LABEL_34;
LABEL_15:
  v14 = *(_BYTE *)(sv_disableClientConsole + 8);
  if (v14)
    goto LABEL_35;
LABEL_16:
  v15 = Dvar_GetString("g_password");
  if (v15 && LOBYTE(v15->s.number))
    Info_SetValueForKey(__s1, "pswrd", "1");
  Int = Dvar_GetInt("scr_friendlyfire");
  if (Int) {
    v32 = va("%i", Int);
    Info_SetValueForKey(__s1, "ff", v32);
  }
  v17 = Dvar_GetInt("scr_killcam");
  if (v17) {
    v31 = va("%i", v17);
    Info_SetValueForKey(__s1, "kc", v31);
  }
  if (com_dedicated && *(_DWORD *)(com_dedicated + 8))
    v18 = va("%i", 2);
  else
    v18 = va("%i", 5);
  Info_SetValueForKey(__s1, "hw", v18);
  if (*(_BYTE *)(sv_pure + 8) && !*v12) {
    v30 = (char *)Dvar_GetString("sv_referencedIwdNames");
    if (!*v30 || (SV_Cmd_TokenizeString(v30), v34 = SV_Cmd_Argc(), v34 <= 0)) {
      v19 = 0;
      goto LABEL_29;
    }
    v35 = 0;
    while (1) {
      v36 = (char *)SV_Cmd_Argv(v35);
      if (!FS_iwIwd(v36, "main"))
        break;
      if (v34 == ++v35) {
        v19 = 0;
        goto LABEL_29;
      }
    }
  }
  v19 = 1;
LABEL_29:
  v20 = va("%i", v19);
  Info_SetValueForKey(__s1, "mod", v20);
  v21 = va("%i", *(unsigned __int8 *)(sv_voice + 8));
  Info_SetValueForKey(__s1, "voice", v21);
  I_strncpyz(__dst, "infoResponse\n", 1024);
  I_strncat(__dst, 1024, __s1);
  LOWORD(v40) = WORD4(a1);
  v39 = a1;
  return NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, __dst);
}

void __cdecl SV_AddServerCommand(struct client_s *client, enum svscmd_type type,
                                 char const *cmd) {
  client_s *result; // eax
  int v4;           // ebx
  client_s *v5;     // ecx
  int v6;           // edi
  int v7;           // esi
  client_s *v8;     // ebx
  char *v9;         // edx
  int v10;          // ebx
  int v11;          // esi
  client_s *i;      // edi
  int v13;          // ecx
  char *v14;        // edx
  int v15;          // edi
  client_s *v16;    // edx
  client_s *v17;    // edi
  svscmd_type v18;  // esi
  client_s *v19;    // edx
  const char *v20;  // ecx
  int v21;          // ebx
  char *v22;        // ebx
  int v23;          // ebx
  char v24;         // al
  int v25;          // edi
  char *v26;        // ecx
  char v27;         // dl
  const char *v28;  // edi
  client_s *j;      // ecx
  netadr_t v30;     // [esp+4h] [ebp-64h]
  char v31;         // [esp+38h] [ebp-30h]
  char *v32;        // [esp+3Ch] [ebp-2Ch]
  char *v33;        // [esp+78h] [ebp+10h]

  result = a1;
  if (a1->serverId)
    return result;
  v4 = *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1);
  if ( v4 - a1->reliableAcknowledge > 63 )
  {
    v5 = a1;
  }
  else
  {
    if (a1->state == 4)
      goto LABEL_14;
    v5 = a1;
  }
  v6 = *(_DWORD *)((char *)&loc_20814 + (_DWORD)v5) + 1;
  if ( v4 >= v6 )
  {
    v7 = *(_DWORD *)((char *)&loc_20814 + (_DWORD)v5) + 1;
    v8 = a1;
    do {
      v9 = (char *)v8 + 1032 * (v7 & 0x7F);
      if (*((_DWORD *)v9 + 516)) {
        v10 = v6 & 0x7F;
        if ((v7 & 0x7F) != v10)
          memcpy(&a1->reliableCommandInfo[1032 * v10], v9 + 1036, 0x408u);
        ++v6;
        v8 = a1;
      }
      ++v7;
    }
    while ( *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)v8) >= v7 );
  }
  result = (client_s *)(v6 - 1);
  *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1) = v6 - 1;
  if ( a2 == SV_CMD_CAN_IGNORE )
    return result;
  v4 = v6 - 1;
LABEL_14:
  v11 = *(_DWORD *)((char *)&loc_20814 + (_DWORD)a1) + 1;
  if ( v11 > v4 )
  {
    v16 = a1;
  LABEL_24:
    *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)v16) = ++v4;
    v17 = a1;
    goto LABEL_25;
  }
  for ( i = a1; ; i = a1 )
  {
    v13 = 1032 * (v11 & 0x7F);
    v14 = (char *)i + v13;
    if (*(_DWORD *)&i->reliableCommandInfo[v13 + 1028]) {
      v15 = *a3;
      if (v14[1036] == *a3 && (unsigned __int8)(*a3 - 120) > 2u)
        break;
    }
  LABEL_16:
    if (++v11 > v4)
      goto LABEL_30;
  }
  v32 = &a1->reliableCommandInfo[v13];
  if ( !strcmp(a3 + 1, &a1->reliableCommandInfo[v13 + 1]) )
    goto LABEL_37;
  switch ( v15 )
  {
  case 'C':
  case 'D':
  case 'a':
  case 'b':
  case 'o':
  case 'p':
  case 'q':
  case 'r':
  case 't':
    goto LABEL_37;
  case 'd':
  case 'v':
    v26 = v32 + 2;
    v27 = a3[2];
    if (v27) {
      v24 = v32[2];
      if (!v24)
        goto LABEL_33;
      if (v27 != 32) {
        if (v24 == 32) {
        LABEL_33:
          if (v27 != 32)
            goto LABEL_16;
        } else {
          if (v24 != v27)
            goto LABEL_16;
          v28 = a3 + 2;
          while (1) {
            ++v26;
            v27 = v28[1];
            if (!v27)
              break;
            v24 = *v26;
            if (!*v26)
              goto LABEL_33;
            if (v27 == 32)
              goto LABEL_35;
            if (v24 == 32)
              goto LABEL_33;
            ++v28;
            if (v24 != v27)
              goto LABEL_16;
          }
        }
        v24 = *v26;
      }
    } else {
      v24 = v32[2];
    }
  LABEL_35:
    if (v24 && v24 != 32)
      goto LABEL_16;
  LABEL_37:
    if (v11 < 0) {
    LABEL_30:
      v16 = a1;
      goto LABEL_24;
    }
    v31 = v11 + 1;
    v25 = v11 + 1;
    if (v11 + 1 > v4) {
      v17 = a1;
    } else {
      while (1) {
        memcpy(&a1->reliableCommandInfo[1032 * (v11 & 0x7F)],
               &a1->reliableCommandInfo[1032 * (v25++ & 0x7F)], 0x408u);
        LOBYTE(v11) = v31;
          if ( v25 > *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1) )
            break;
          ++v31;
      }
        v4 = *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1);
        v17 = a1;
    }
  LABEL_25:
    if (v4 - v17->reliableAcknowledge == 129) {
      Com_Printf("===== pending server commands =====\n");
      v23 = a1->reliableAcknowledge + 1;
        if ( v23 <= *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1) )
        {
        for (j = a1;; j = a1) {
          Com_Printf(
              "cmd %5d: %8d: %s\n", v23,
              *(_DWORD *)&j->reliableCommandInfo[1032 * (v23 & 0x7F) + 1024],
              &j->reliableCommandInfo[1032 * (v23 & 0x7F)]);
          if (++v23 > *(_DWORD *)((char *)`global constructor keyed
                                      to'CMemoryBuffer::sDelayedFreeRequests +
                                  (_DWORD)a1))
            break;
        }
        }
        Com_Printf("cmd %5d: %8d: %s\n", v23, dword_1700484, a3);
        v30.type = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a1);
        v30.ip = *(int32_t *)((char *)&a1->netchan.remoteAddress.ip + 2);
        v30.port = a1->netchan.qport;
        NET_OutOfBandPrint(NS_SERVER, v30, "disconnect");
        SV_DelayDropClient(a1, "EXE_SERVERCOMMANDOVERFLOW");
        v33 = va("%c \"EXE_SERVERCOMMANDOVERFLOW\"", 119);
        v18 = SV_CMD_RELIABLE;
        v4 = *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1);
        v19 = a1;
        v20 = v33;
    } else {
      v18 = a2;
      v19 = a1;
      v20 = a3;
    }
    v21 = 1032 * (v4 & 0x7F);
    MSG_WriteReliableCommandToBuffer(v20, &v19->reliableCommandInfo[v21],
                                     (char *)0x400);
    v22 = (char *)a1 + v21;
    result = (client_s *)dword_1700484;
    *((_DWORD *)v22 + 515) = dword_1700484;
    *((_DWORD *)v22 + 516) = v18;
    return result;
  default:
    goto LABEL_16;
  }
}

void __cdecl SV_SendServerCommand(struct client_s *cl, enum svscmd_type type,
                                  char const *fmt, ...) {
  client_s *v3;    // ebx
  int v4;          // eax
  int v5;          // esi
  char *v6;        // ecx
  unsigned int v7; // ebx
  char v8;         // dl
  char *__str;     // [esp+1Ch] [ebp-2Ch]
  LargeLocal v10;  // [esp+28h] [ebp-20h] BYREF
  va_list v11;     // [esp+2Ch] [ebp-1Ch]
  va_list va;      // [esp+5Ch] [ebp+14h] BYREF

  va_start(va, __format);
  LargeLocal::LargeLocal(&v10, 0x4000);
  __str = (char *)LargeLocal::GetBuf(&v10);
  va_copy(v11, va);
  vsnprintf(__str, 0x4000u, __format, va);
  if (a1) {
    SV_AddServerCommand(a1, a2, __str);
    LargeLocal::~LargeLocal(&v10);
  } else {
    if (*(_DWORD *)(com_dedicated + 8) && !memcmp(__str, "print", 5)) {
      v6 = __str;
      v7 = 0;
      while (1) {
        v8 = *v6;
        if (!*v6 || v7 > 0x3FC)
          break;
        if (v8 == 10) {
          SV_ExpandNewlines(char *)::string[v7] = 92;
          byte_EDAE01[v7] = 110;
          v7 += 2;
          ++v6;
        } else {
          if ((unsigned __int8)(v8 - 20) > 1u)
            SV_ExpandNewlines(char *)::string[v7++] = v8;
          ++v6;
        }
      }
      SV_ExpandNewlines(char *)::string[v7] = 0;
      Com_Printf("broadcast: %s\n", SV_ExpandNewlines(char *)::string);
    }
    v3 = dword_170048C;
    v4 = sv_maxclients;
    if (*(int *)(sv_maxclients + 8) > 0) {
      v5 = 0;
      do {
        while (v3->state <= 2) {
          ++v5;
          v3 = (client_s *)((char *)v3 + 495372);
          if (v5 >= *(_DWORD *)(v4 + 8))
            goto LABEL_9;
        }
        SV_AddServerCommand(v3, a2, __str);
        v4 = sv_maxclients;
        ++v5;
        v3 = (client_s *)((char *)v3 + 495372);
      } while (v5 < *(_DWORD *)(sv_maxclients + 8));
    }
  LABEL_9:
    LargeLocal::~LargeLocal(&v10);
  }
}

int __cdecl SV_CheckPaused(void) { UNIMPLEMENTED(); }

void __cdecl SVC_GameCompleteStatus(struct netadr_t from) {
  char *v1;         // eax
  const char *v2;   // eax
  int v3;           // eax
  char *v4;         // ebx
  int v5;           // edi
  int ClientScore;  // eax
  unsigned int v7;  // kr04_4
  char *v8;         // eax
  const char *v9;   // eax
  const char *Buf;  // [esp+24h] [ebp-C44h]
  int v11;          // [esp+28h] [ebp-C40h]
  int v12;          // [esp+2Ch] [ebp-C3Ch]
  int v13;          // [esp+3Ch] [ebp-C2Ch]
  char __str[1024]; // [esp+40h] [ebp-C28h] BYREF
  char __dst[1024]; // [esp+440h] [ebp-828h] BYREF
  char __src[1024]; // [esp+840h] [ebp-428h] BYREF
  __int64 v17;      // [esp+C40h] [ebp-28h]
  int v18;          // [esp+C48h] [ebp-20h]
  LargeLocal v19;   // [esp+C4Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v19, 0x4000);
  Buf = (const char *)LargeLocal::GetBuf(&v19);
  v1 = Dvar_InfoString(0x404u);
  strcpy(__dst, v1);
  v2 = (const char *)SV_Cmd_Argv(1);
  Info_SetValueForKey(__dst, "challenge", v2);
  if ((unsigned __int8)Dvar_GetBool("fs_restrict")) {
    v9 = (const char *)Info_ValueForKey(__dst, "sv_keywords");
    Com_sprintf(__str, 0x400u, "demo %s", v9);
    Info_SetValueForKey(__dst, "sv_keywords", __str);
  }
  *Buf = 0;
  v3 = sv_maxclients;
  if (*(int *)(sv_maxclients + 8) > 0) {
    v12 = 0;
    v11 = 0;
    v13 = 0;
    do {
      v4 = (char *)dword_170048C + v13;
      if (*(int *)((char *)&dword_170048C->state + v13) > 1) {
        SV_GameClientNum(v11);
        v5 = *((_DWORD *)v4 + 113001);
        ClientScore =
            G_GetClientScore(931767531 * ((v4 - (char *)dword_170048C) >> 2));
        Com_sprintf(__src, 0x400u, "%i %i \"%s\"\n", ClientScore, v5,
                    v4 + 134216);
        v7 = strlen(__src) + 1;
        if (v7 + v12 - 1 > 0x3FFF)
          break;
        strcpy((char *)&Buf[v12], __src);
        v12 = v7 + v12 - 1;
        v3 = sv_maxclients;
      }
      ++v11;
      v13 += 495372;
    } while (v11 < *(_DWORD *)(v3 + 8));
  }
  v8 = va("gameCompleteStatus\n%s\n%s", __dst, Buf);
  LOWORD(v18) = WORD4(a1);
  v17 = a1;
  NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, v8);
  LargeLocal::~LargeLocal(&v19);
}

void __cdecl SVC_Status(struct netadr_t from) {
  char *v1;                // eax
  const char *v2;          // eax
  int v3;                  // eax
  int ClientScore;         // eax
  unsigned int v5;         // kr04_4
  char *v6;                // ebx
  int v7;                  // edi
  const gentity_s *String; // eax
  const gentity_s *v9;     // edx
  int v10;                 // eax
  char *v11;               // eax
  char *v12;               // eax
  const char *v13;         // eax
  int v14;                 // esi
  int v15;                 // ebx
  char *v16;               // eax
  const char *Buf;         // [esp+24h] [ebp-4844h]
  int v18;                 // [esp+28h] [ebp-4840h]
  int v19;                 // [esp+2Ch] [ebp-483Ch]
  int v20;                 // [esp+3Ch] [ebp-482Ch]
  char __str[8192];        // [esp+40h] [ebp-4828h] BYREF
  char __dst[8192];        // [esp+2040h] [ebp-2828h] BYREF
  char v23[1024];          // [esp+4040h] [ebp-828h] BYREF
  char __src[1024];        // [esp+4440h] [ebp-428h] BYREF
  __int64 v25;             // [esp+4840h] [ebp-28h]
  int v26;                 // [esp+4848h] [ebp-20h]
  LargeLocal v27;          // [esp+484Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v27, 0x4000);
  Buf = (const char *)LargeLocal::GetBuf(&v27);
  v1 = Dvar_InfoString(0x404u);
  strcpy(__dst, v1);
  v2 = (const char *)SV_Cmd_Argv(1);
  Info_SetValueForKey(__dst, "challenge", v2);
  if ((unsigned __int8)Dvar_GetBool("fs_restrict")) {
    v13 = (const char *)Info_ValueForKey(__dst, "sv_keywords");
    Com_sprintf(v23, 0x400u, "demo %s", v13);
    Info_SetValueForKey(__dst, "sv_keywords", v23);
  }
  *Buf = 0;
  v3 = sv_maxclients;
  if (*(int *)(sv_maxclients + 8) > 0) {
    v19 = 0;
    v18 = 0;
    v20 = 0;
    do {
      v6 = (char *)dword_170048C + v20;
      if (*(int *)((char *)&dword_170048C->state + v20) > 1) {
        SV_GameClientNum(v18);
        v7 = *((_DWORD *)v6 + 113001);
        if (gameInitialized)
          ClientScore =
              G_GetClientScore(931767531 * ((v6 - (char *)dword_170048C) >> 2));
        else
          ClientScore = 0;
        Com_sprintf(__src, 0x400u, "%i %i \"%s\"\n", ClientScore, v7,
                    v6 + 134216);
        v5 = strlen(__src) + 1;
        if (v5 + v19 - 1 > 0x3FFF)
          break;
        strcpy((char *)&Buf[v19], __src);
        v19 = v5 + v19 - 1;
        v3 = sv_maxclients;
      }
      ++v18;
      v20 += 495372;
    } while (*(_DWORD *)(v3 + 8) > v18);
  }
  String = Dvar_GetString("g_password");
  if (String && LOBYTE(String->s.number))
    Info_SetValueForKey(__dst, "pswrd", "1");
  else
    Info_SetValueForKey(__dst, "pswrd", "0");
  v9 = Dvar_GetString("fs_game");
  if (*(_BYTE *)(sv_pure + 8) && (!v9 || !LOBYTE(v9->s.number))) {
    v12 = (char *)Dvar_GetString("sv_referencedIwdNames");
    if (!*v12 || (SV_Cmd_TokenizeString(v12), v14 = SV_Cmd_Argc(), v14 <= 0)) {
      v10 = 0;
      goto LABEL_19;
    }
    v15 = 0;
    while (1) {
      v16 = (char *)SV_Cmd_Argv(v15);
      if (!FS_iwIwd(v16, "main"))
        break;
      if (v14 == ++v15) {
        v10 = 0;
        goto LABEL_19;
      }
    }
  }
  v10 = 1;
LABEL_19:
  v11 = va("%i", v10);
  Info_SetValueForKey(__dst, "mod", v11);
  Com_sprintf(__str, 0x2000u, "statusResponse\n%s\n%s", __dst, Buf);
  LOWORD(v26) = WORD4(a1);
  v25 = a1;
  NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, __str);
  LargeLocal::~LargeLocal(&v27);
}

void __cdecl SV_FreeClientScriptId(struct client_s *cl) { UNIMPLEMENTED(); }

void __cdecl SV_VoicePacket(struct netadr_t from, struct msg_t *msg) {
  client_s *v2;  // ebx
  int result;    // eax
  int i;         // esi
  int v5;        // [esp+Ch] [ebp-5Ch]
  int v6;        // [esp+10h] [ebp-58h]
  int32_t qport; // [esp+14h] [ebp-54h] OVERLAPPED
  int Short;     // [esp+24h] [ebp-44h]

  Short = MSG_ReadShort(a2);
  v2 = dword_170048C;
  result = sv_maxclients;
  if (*(int *)(sv_maxclients + 8) > 0) {
    for (i = 0; i < *(_DWORD *)(sv_maxclients + 8); ++i) {
      while (!v2->state) {
      LABEL_3:
        ++i;
        v2 = (client_s *)((char *)v2 + 495372);
        if (i >= *(_DWORD *)(result + 8))
          return result;
      }
      qport = v2->netchan.qport;
      v5 = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)v2);
      v6 = *(int32_t *)((char *)&v2->netchan.remoteAddress.ip + 2);
      if (NET_CompareBaseAdr(a1, *(netadr_t *)(&qport - 2)) &&
          Short == *(_DWORD *)((char *)&loc_6E5D0 + (_DWORD)v2)) {
        if (LOWORD(v2->netchan.qport) != a1.port) {
          Com_Printf("SV_ReadPackets: fixing up a translated port\n");
          LOWORD(v2->netchan.qport) = a1.port;
        }
        if (v2->state != 1) {
          *(uint32_t *)((char *)&v2->lastPacketTime + 2) = dword_1700484;
          if (v2->state > 3)
            SV_UserVoice(v2, a2);
          else
            SV_PreGameUserVoice(v2, a2);
          result = sv_maxclients;
          goto LABEL_3;
        }
      }
      result = sv_maxclients;
      v2 = (client_s *)((char *)v2 + 495372);
    }
  }
  return result;
}

void __cdecl SV_CheckTimeouts(void) { UNIMPLEMENTED(); }

void __cdecl SV_BotUserMove(struct client_s *cl) {
  int result;         // eax
  int8_t forwardmove; // al
  int8_t rightmove;   // dl
  float v4;           // [esp+1Ch] [ebp-6Ch]
  float v5;           // [esp+1Ch] [ebp-6Ch]
  float v6;           // [esp+1Ch] [ebp-6Ch]
  float v7;           // [esp+2Ch] [ebp-5Ch]
  float v8;           // [esp+30h] [ebp-58h]
  float v9;           // [esp+34h] [ebp-54h]
  float v10;          // [esp+34h] [ebp-54h]
  float v11;          // [esp+38h] [ebp-50h]
  float v12;          // [esp+3Ch] [ebp-4Ch]
  float v13;          // [esp+40h] [ebp-48h]
  float v14;          // [esp+44h] [ebp-44h]
  float v15;          // [esp+48h] [ebp-40h]
  float v16;          // [esp+4Ch] [ebp-3Ch]
  usercmd_s v17[2];   // [esp+54h] [ebp-34h] BYREF

  result = *(int32_t *)((char *)&a1->gentity + 2);
  if (result) {
    memset(v17, 0, 0x1Cu);
    v17[0].weapon = *(
        _DWORD *)(SV_GameClientNum(
                      931767531 * (((char *)a1 - (char *)dword_170048C) >> 2)) +
                  212);
    if (G_GetClientArchiveTime(931767531 *
                               (((char *)a1 - (char *)dword_170048C) >> 2))) {
    LABEL_3:
      *(_DWORD *)&a1->deltaMessage[2] =
          *(int32_t *)((char *)&a1->netchan.outgoingSequence + 2) - 1;
      return SV_ClientThink(a1, v17);
    }
    v7 = randomf();
    if (v7 < 0.5)
      v17[0].buttons |= 1u;
    v8 = randomf();
    if (v8 < 0.5) {
      v17[0].buttons |= 0x28u;
      v10 = randomf();
      if (v10 < 0.33000001)
        goto LABEL_9;
    } else {
      v9 = randomf();
      if (v9 < 0.33000001) {
      LABEL_9:
        v17[0].forwardmove = 127;
      LABEL_10:
        v12 = randomf();
        if (v12 >= 0.33000001) {
          v13 = randomf();
          rightmove = -127;
          if (v13 >= 0.5)
            rightmove = v17[0].rightmove;
          v17[0].rightmove = rightmove;
        } else {
          v17[0].rightmove = 127;
        }
        v14 = randomf();
        if (v14 < 0.33000001) {
          v6 = crandom();
          LODWORD(v17[0].angles[0]) = (int)(float)(v6 * 360.0);
        }
        v15 = randomf();
        if (v15 < 0.33000001) {
          v5 = crandom();
          LODWORD(v17[0].angles[1]) = (int)(float)(v5 * 360.0);
        }
        v16 = randomf();
        if (v16 < 0.33000001) {
          v4 = crandom();
          LODWORD(v17[0].angles[2]) = (int)(float)(v4 * 360.0);
        }
        goto LABEL_3;
      }
    }
    v11 = randomf();
    forwardmove = -127;
    if (v11 >= 0.5)
      forwardmove = v17[0].forwardmove;
    v17[0].forwardmove = forwardmove;
    goto LABEL_10;
  }
  return result;
}

void __cdecl SV_UpdateBots(void) { UNIMPLEMENTED(); }

void __cdecl SV_RunFrame() { UNIMPLEMENTED(); }

void __cdecl SV_Frame(int msec) {
  int result;      // eax
  client_s *v2;    // edx
  int v3;          // esi
  int v4;          // ebx
  int v5;          // ecx
  __int16 v6;      // ax
  client_s *v7;    // ebx
  int v8;          // eax
  int v9;          // esi
  const char *v10; // eax
  char *v11;       // edi
  char *v12;       // ebx
  int v13;         // esi
  int v14;         // ecx
  int v15;         // eax
  int v16;         // edx
  int v17;         // edi
  client_s *v18;   // ebx
  int v19;         // esi
  int v20;         // eax
  const char *v21; // eax
  const char *v22; // eax
  int v23;         // [esp+18h] [ebp-70h]
  int v24;         // [esp+1Ch] [ebp-6Ch]
  int v25;         // [esp+20h] [ebp-68h]
  int v26;         // [esp+24h] [ebp-64h]
  int v27;         // [esp+28h] [ebp-60h]
  int v28;         // [esp+2Ch] [ebp-5Ch]
  char __dst[88];  // [esp+30h] [ebp-58h] BYREF

  if (*(_BYTE *)(legacyHacks + 221)) {
    Com_Shutdown((char *)(legacyHacks + 222));
    result = legacyHacks;
    *(_BYTE *)(legacyHacks + 221) = 0;
    return result;
  }
  result = com_sv_running;
  if (*(_BYTE *)(com_sv_running + 8)) {
    if (*(_DWORD *)(cl_paused + 8)) {
      v2 = dword_170048C;
      v3 = *(_DWORD *)(sv_maxclients + 8);
      if (v3 <= 0)
        return Dvar_SetInt((const dvar_s *)sv_paused, 1);
      v4 = 0;
      v5 = 0;
      do {
        if (v2->state >= 2)
          ++v5;
        ++v4;
        v2 = (client_s *)((char *)v2 + 495372);
      } while (v3 != v4);
      if (v5 <= 1)
        return Dvar_SetInt((const dvar_s *)sv_paused, 1);
      Dvar_SetInt((const dvar_s *)sv_paused, 0);
    }
    v25 = 1000 / *(_DWORD *)(sv_fps + 8);
    result = dword_16A0F10 + a1;
    dword_16A0F10 = result;
    if (v25 <= result) {
      if (dword_1700484 > 1879048192) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTTIMEWRAP");
      } else if (dword_1700498 >= 2147483646 - dword_1700490) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15numSnapshotEntities");
      } else if (dword_17004BC > 2147467261) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15nextCachedSnapshotEntities");
      } else if (dword_17004C0 > 2147479549) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15nextCachedSnapshotClients");
      } else if (dword_17004AC > 2147482445) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15nextArchivedSnapshotFrames");
      } else if (dword_17004B8 > 2113929213) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15nextArchivedSnapshotBuffer");
      } else if (dword_17004C4 > 2147483133) {
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15nextCachedSnapshotFrames");
      } else {
        if (dword_170049C < 2147483646 - dword_1700494) {
          v6 = dvar_modifiedFlags;
          if ((dvar_modifiedFlags & 0x404) != 0) {
            v22 = (const char *)Dvar_InfoString(1028);
            SV_SetConfigstring(0, v22);
            v6 = dvar_modifiedFlags & 0xFBFB;
            dvar_modifiedFlags &= 0xFFFFFBFB;
          }
          if ((v6 & 8) != 0) {
            v21 = (const char *)Dvar_InfoString_Big(8);
            SV_SetConfigstring(1, v21);
            HIBYTE(v6) = BYTE1(dvar_modifiedFlags);
            dvar_modifiedFlags &= ~8u;
          }
          if ((v6 & 0x100) != 0) {
            SV_SetConfig(142, 96, 256);
            dvar_modifiedFlags &= ~0x100u;
          }
          SV_ResetSkeletonCache();
          v7 = dword_170048C;
          v8 = sv_maxclients;
          if (*(int *)(sv_maxclients + 8) > 0) {
            v9 = 0;
            do {
              if (v7->state && !*(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)v7)) {
                SV_BotUserMove(v7);
                v8 = sv_maxclients;
              }
              ++v9;
              v7 = (client_s *)((char *)v7 + 495372);
            } while (v9 < *(_DWORD *)(v8 + 8));
          }
          if (*(int *)(v8 + 8) > 0) {
            v26 = 0;
            v28 = 0;
            do {
              v11 = (char *)dword_170048C + v28;
              if (*(int32_t *)((char *)&dword_170048C->state + v28) != 4 ||
                  !*((_DWORD *)v11 + 33553))
                goto LABEL_43;
              v12 = (char *)dword_170048C + v28;
              v23 = 0;
              v24 = 0;
              v13 = 32;
              do {
                v14 = *((_DWORD *)v12 + 36088);
                if (v14 > 0) {
                  ++v24;
                  v23 += v14 - *((_DWORD *)v12 + 36087);
                }
                v12 += 9924;
                --v13;
              } while (v13);
              if (v24) {
                v15 = 999;
                if (v23 / v24 < 1000)
                  v15 = v23 / v24;
                *((_DWORD *)v11 + 113001) = v15;
              } else {
              LABEL_43:
                *((_DWORD *)v11 + 113001) = 999;
              }
              ++v26;
              v28 += 495372;
            } while (v26 < *(_DWORD *)(sv_maxclients + 8));
          }
          while (1) {
            dword_16A0F10 -= v25;
            dword_1700484 += v25;
            CL_FlushDebugData(1);
            SV_ResetSkeletonCache();
            G_RunFrame(dword_1700484);
            Scr_SetLoading(0);
            if (v25 > dword_16A0F10)
              break;
            SV_ArchiveSnapshot();
          }
          v16 = dword_1700484;
          v17 = dword_1700484 - 1000 * *(_DWORD *)(sv_timeout + 8);
          v27 = dword_1700484 - 1000 * *(_DWORD *)(sv_zombietime + 8);
          v18 = dword_170048C;
          if (*(int *)(sv_maxclients + 8) > 0) {
            v19 = 0;
            while (1) {
              if (*(signed int *)((char *)&v18->lastPacketTime + 2) > v16)
                *(uint32_t *)((char *)&v18->lastPacketTime + 2) = v16;
              if (!v18->serverId) {
                if (v18->state == 1) {
                  if (v27 <= *(signed int *)((char *)&v18->lastPacketTime + 2))
                    goto LABEL_70;
                  Com_DPrintf("Going from CS_ZOMBIE to CS_FREE for %s\n",
                              &v18->name[2]);
                  v18->state = 0;
                } else {
                  if (v18->state <= 1 ||
                      v17 <=
                          *(signed int *)((char *)&v18->lastPacketTime + 2)) {
                  LABEL_70:
                    *(uint32_t *)((char *)&v18->timeoutCount + 2) = 0;
                    goto LABEL_63;
                  }
                  v20 = *(uint32_t *)((char *)&v18->timeoutCount + 2) + 1;
                  *(uint32_t *)((char *)&v18->timeoutCount + 2) = v20;
                  if (v20 > 5) {
                    SV_DropClient(v18, "EXE_TIMEDOUT");
                    v18->state = 0;
                  }
                }
              }
            LABEL_63:
              ++v19;
              v18 = (client_s *)((char *)v18 + 495372);
              if (v19 >= *(_DWORD *)(sv_maxclients + 8))
                break;
              v16 = dword_1700484;
            }
          }
          SV_SendClientMessages();
          SV_ArchiveSnapshot();
          return SV_MasterHeartbeat("COD-2");
        }
        I_strncpyz(__dst, *(const char **)(sv_mapname + 8), 64);
        Com_Shutdown("EXE_SERVERRESTARTMISC\x15numSnapshotClients");
      }
      v10 = (const char *)va("map %s\n", (char)__dst);
      return Cbuf_AddText(v10);
    }
  }
  return result;
}

void __cdecl SV_ConnectionlessPacket(struct netadr_t from, struct msg_t *msg) {
  char *StringLine; // eax
  char *v3;         // ebx
  char *v4;         // eax
  __int128 v5;      // [esp+0h] [ebp-98h]
  int v6;           // [esp+40h] [ebp-58h]
  int v7;           // [esp+4Ch] [ebp-4Ch]
  int v8;           // [esp+58h] [ebp-40h]
  int v9;           // [esp+64h] [ebp-34h]
  int v10;          // [esp+70h] [ebp-28h]
  int v11;          // [esp+7Ch] [ebp-1Ch]

  MSG_BeginReading(a2);
  MSG_ReadLong(a2);
  SV_Netchan_AddOOBProfilePacket(a2->cursize);
  StringLine = MSG_ReadStringLine(a2);
  SV_Cmd_TokenizeString(StringLine);
  v3 = (char *)SV_Cmd_Argv(0);
  if (*(_BYTE *)(sv_packet_info + 8)) {
    LOWORD(v11) = a1.port;
    *(_QWORD *)&v5 = *(_QWORD *)&a1.type;
    DWORD2(v5) = v11;
    v4 = NET_AdrToString(v5);
    Com_Printf("SV packet %s : %s\n", v4, v3);
  }
  if (I_stricmp(v3, "v")) {
    if (I_stricmp(v3, "getstatus")) {
      if (I_stricmp(v3, "getinfo")) {
        if (I_stricmp(v3, "getchallenge")) {
          if (I_stricmp(v3, "connect")) {
            if (I_stricmp(v3, "ipAuthorize")) {
              if (I_stricmp(v3, "rcon"))
                I_stricmp(v3, "disconnect");
              else
                SVC_RemoteCommand(a1);
            } else {
              LOWORD(v10) = a1.port;
              *(_DWORD *)&a1.port = v10;
              SV_AuthorizeIpPacket(*(__int128 *)&a1.type);
            }
          } else {
            LOWORD(v9) = a1.port;
            *(_DWORD *)&a1.port = v9;
            SV_DirectConnect(*(__int128 *)&a1.type);
          }
        } else {
          LOWORD(v8) = a1.port;
          *(_DWORD *)&a1.port = v8;
          SV_GetChallenge(*(__int128 *)&a1.type);
        }
      } else {
        LOWORD(v7) = a1.port;
        *(_DWORD *)&a1.port = v7;
        SVC_Info(*(__int128 *)&a1.type);
      }
    } else {
      LOWORD(v6) = a1.port;
      *(_DWORD *)&a1.port = v6;
      SVC_Status(*(__int128 *)&a1.type);
    }
  } else {
    SV_VoicePacket(a1, a2);
  }
}

void __cdecl SV_PacketEvent(struct netadr_t from, struct msg_t *msg) {
  client_s *v9;  // ebx
  int v10;       // eax
  int v11;       // esi
  int Long;      // eax
  int v13;       // eax
  int v14;       // [esp+Ch] [ebp-6Ch]
  int v15;       // [esp+10h] [ebp-68h]
  int32_t qport; // [esp+14h] [ebp-64h] OVERLAPPED
  int Short;     // [esp+24h] [ebp-54h]

  if ((int)a9->cursize > 3 && *(_DWORD *)a9->data == -1) {
    SV_ConnectionlessPacket(a8, a9);
  } else {
    SV_ResetSkeletonCache();
    MSG_BeginReading(a9);
    MSG_ReadLong(a9);
    Short = (unsigned __int16)MSG_ReadShort(a9);
    v9 = dword_170048C;
    v10 = sv_maxclients;
    if (*(int *)(sv_maxclients + 8) <= 0) {
    LABEL_10:
      NET_OutOfBandPrint(NS_SERVER, a8, "disconnect");
    } else {
      v11 = 0;
      while (1) {
        while (!v9->state) {
          ++v11;
          v9 = (client_s *)((char *)v9 + 495372);
          if (v11 >= *(_DWORD *)(v10 + 8))
            goto LABEL_10;
        }
        qport = v9->netchan.qport;
        v14 = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)v9);
        v15 = *(int32_t *)((char *)&v9->netchan.remoteAddress.ip + 2);
        if (NET_CompareBaseAdr(a8, *(netadr_t *)(&qport - 2)) &&
            Short == *(_DWORD *)((char *)&loc_6E5D0 + (_DWORD)v9))
          break;
        v10 = sv_maxclients;
        ++v11;
        v9 = (client_s *)((char *)v9 + 495372);
        if (v11 >= *(_DWORD *)(sv_maxclients + 8))
          goto LABEL_10;
      }
      if (LOWORD(v9->netchan.qport) != a8.port) {
        Com_Printf("SV_ReadPackets: fixing up a translated port\n");
        LOWORD(v9->netchan.qport) = a8.port;
      }
      if (Netchan_Process(
              (netchan_t *)((char *)&v9->netchan.outgoingSequence + 2), a9)) {
        *(_DWORD *)v9->voicePackets = MSG_ReadByte(a9);
        Long = MSG_ReadLong(a9);
        *(_DWORD *)v9->messageAcknowledge = Long;
        if (Long >= 0) {
          v13 = MSG_ReadLong(a9);
          v9->reliableAcknowledge = v13;
          if ( *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)v9) - v13 <= 127 )
          {
            SV_Netchan_Decode(v9, (unsigned __int8 *)(a9->data + a9->readcount),
                              (unsigned __int8 *)(a9->cursize - a9->readcount));
            if (v9->state != 1) {
              *(uint32_t *)((char *)&v9->lastPacketTime + 2) = dword_1700484;
              SV_ExecuteClientMessage(a1, a2, a3, a4, a5, a6, a7, v9, a9);
              bgs = 0;
            }
          }
          else
          {
            v9->reliableAcknowledge =
                *(_DWORD *)((char *)`global constructor keyed
                                to'CMemoryBuffer::sDelayedFreeRequests +
                            (_DWORD)v9);
          }
        }
      }
    }
  }
}

struct dvar_s const *const sv_allowedClan2;
struct dvar_s const *const sv_maxPing;
struct dvar_s const *const sv_privateClients;
struct dvar_s const *const sv_maxclients;
struct dvar_s const *const sv_hostname;
struct dvar_s const *const sv_allowedClan1;
struct dvar_s const *const sv_allowAnonymous;
struct dvar_s const *const sv_debugReliableCmds;
struct dvar_s const *const sv_reconnectlimit;
struct dvar_s const *const sv_kickBanTime;
struct dvar_s const *const sv_floodProtect;
struct dvar_s const *const sv_allowDownload;
struct dvar_s const *const sv_gametype;
struct dvar_s const *const rcon_password;
struct dvar_s const *const sv_mapname;
struct dvar_s const *const sv_cheats;
struct dvar_s const *const sv_maxRate;
struct dvar_s const *const sv_showCommands;
struct dvar_s const *const sv_packet_info;
struct dvar_s const *const sv_mapRotationCurrent;
struct dvar_s const *const sv_disableClientConsole;
struct dvar_s const *const sv_minPing;
struct dvar_s const *const sv_zombietime;
struct dvar_s const *const sv_privatePassword;
struct dvar_s const *const sv_debugRate;
struct dvar_s const *const sv_showAverageBPS;
struct dvar_s const *const sv_timeout;
struct dvar_s const *const sv_padPackets;
struct dvar_s const *const sv_fps;
struct dvar_s const *const sv_serverid;
struct dvar_s const *const sv_mapRotation;
struct server_t sv;
struct serverStatic_t svs;
void __cdecl SV_CullIgnorableServerCommands(struct client_s *) {
  UNIMPLEMENTED();
}

int __cdecl SV_IsFirstTokenEqual(char const *, char const *) {
  UNIMPLEMENTED();
}

int __cdecl SV_CanReplaceServerCommand(struct client_s *, char const *) {
  UNIMPLEMENTED();
}
