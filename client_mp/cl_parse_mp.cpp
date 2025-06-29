void __cdecl CL_ParseCommandString(struct msg_t *) { UNIMPLEMENTED(); }

void __cdecl CL_SystemInfoChanged() {
  dvar_s *Buf;    // esi
  _DWORD *v1;     // ebx
  char *v2;       // edi
  const char *v3; // eax
  char *v4;       // eax
  char *v5;       // eax
  char *v6;       // [esp+1Ch] [ebp-2Ch]
  LargeLocal v7;  // [esp+24h] [ebp-24h] BYREF
  LargeLocal v8;  // [esp+28h] [ebp-20h] BYREF
  char *v9;       // [esp+2Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v8, 0x2000);
  Buf = (dvar_s *)LargeLocal::GetBuf(&v8);
  LargeLocal::LargeLocal(&v7, 0x2000);
  v6 = (char *)LargeLocal::GetBuf(&v7);
  v1 = cl;
  v2 = (char *)cl + *((_DWORD *)cl + 2500) + 18188;
  v3 = (const char *)Info_ValueForKey(v2, "sv_serverid");
  v1[8586] = atoi(v3);
  if (*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc)) {
    LargeLocal::~LargeLocal(&v7);
    LargeLocal::~LargeLocal(&v8);
  } else {
    v9 = (char *)Info_ValueForKey(v2, "sv_cheats");
    if (!atoi(v9))
      Dvar_SetCheatState();
    v9 = (char *)Info_ValueForKey(v2, "sv_iwds");
    v4 = (char *)Info_ValueForKey(v2, "sv_iwdNames");
    FS_PureServerSetLoadedIwds(v9, v4);
    v9 = (char *)Info_ValueForKey(v2, "sv_referencedIwds");
    v5 = (char *)Info_ValueForKey(v2, "sv_referencedIwdNames");
    FS_PureServerSetReferencedIwds(v9, v5);
    if (!*(_BYTE *)(com_sv_running + 8)) {
      v9 = v2;
      while (v9) {
        Info_NextPair((const char **)&v9, Buf->name, v6);
        if (!Buf->name[0])
          break;
        Dvar_SetFromStringByName(Buf, (DvarValue)v6);
      }
    }
    cl_connectedToPureServer = (unsigned __int8)Dvar_GetBool("sv_pure");
    LargeLocal::~LargeLocal(&v7);
    LargeLocal::~LargeLocal(&v8);
  }
}

void __cdecl SHOWNET(struct msg_t *, char *) { UNIMPLEMENTED(); }

void __cdecl CL_DeltaClient(struct msg_t *, struct clSnapshot_t *, int,
                            struct clientState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl CL_ParseSnapshot(struct msg_t *msg) {
  void *v8;             // ebx
  int Byte;             // edx
  int v10;              // ebx
  int v11;              // edx
  void *v12;            // ecx
  msg_t *number;        // edi
  msg_t *i;             // ecx
  msg_t *Bits;          // esi
  _DWORD *v16;          // ebx
  _DWORD *v17;          // ebx
  void *v18;            // ecx
  msg_t *v19;           // edx
  msg_t *v20;           // edi
  _DWORD *v21;          // ebx
  _DWORD *v22;          // esi
  _DWORD *v23;          // ebx
  _DWORD *v24;          // ebx
  _DWORD *v25;          // ebx
  _DWORD *v26;          // ebx
  _DWORD *v27;          // esi
  int v28;              // ebx
  int v29;              // ecx
  _DWORD *v30;          // ebx
  int v31;              // edx
  _DWORD *v32;          // ecx
  _DWORD *v33;          // ebx
  int v34;              // edi
  char *v35;            // [esp+14h] [ebp-94h]
  _DWORD *Buf;          // [esp+18h] [ebp-90h]
  int v37;              // [esp+1Ch] [ebp-8Ch]
  entityState_s *__src; // [esp+20h] [ebp-88h]
  int v39;              // [esp+24h] [ebp-84h]
  clientState_s *v40;   // [esp+28h] [ebp-80h]
  msg_t *clientIndex;   // [esp+2Ch] [ebp-7Ch]
  clientState_s __b;    // [esp+30h] [ebp-78h] BYREF
  LargeLocal v43;       // [esp+8Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v43, 9944);
  Buf = (_DWORD *)LargeLocal::GetBuf(&v43);
  memset(Buf, 0, 0x26D8u);
  v8 = clc;
  Buf[2485] = *((_DWORD *)clc + 32847);
  Buf[2] = MSG_ReadLong(a8);
  Buf[3] = *(_DWORD *)((char *)&loc_20138 + (_DWORD)v8);
  Byte = MSG_ReadByte(a8);
  if (Byte)
    Buf[4] = Buf[3] - Byte;
  else
    Buf[4] = -1;
  Buf[1] = MSG_ReadByte(a8);
  v10 = Buf[4];
  if (v10 <= 0) {
    *Buf = 1;
    *((_DWORD *)clc + 66026) = 0;
    v35 = 0;
  } else {
    v11 = Buf[4] & 0x1F;
    v35 = (char *)cl + 9944 * v11 + 300512;
    if (*(_DWORD *)v35) {
      if (v10 == *((_DWORD *)cl + 2486 * v11 + 75131)) {
        if (*((_DWORD *)cl + 8564) - *((_DWORD *)cl + 2486 * v11 + 77611) >
            1920) {
          Com_DPrintf("Delta parseEntitiesNum too old.\n");
        } else if (*((_DWORD *)cl + 8565) -
                       *((_DWORD *)cl + 2486 * v11 + 77612) >
                   1920) {
          Com_DPrintf("Delta parseClientsNum too old.\n");
        } else {
          *Buf = 1;
        }
      } else {
        Com_DPrintf("Delta frame too old.\n");
      }
    } else {
      Com_Printf("Delta from invalid frame (not supposed to happen!).\n");
    }
  }
  if (*(int *)(cl_shownet + 8) > 1)
    Com_Printf("%3i:%s\n", a8->readcount - 1, "playerstate");
  if (v35)
    MSG_ReadDeltaPlayerstate(a8, (playerState_s *)(v35 + 28),
                             (playerState_s *)(Buf + 7));
  else
    MSG_ReadDeltaPlayerstate(a8, 0, (playerState_s *)(Buf + 7));
  if (*(int *)(cl_shownet + 8) > 1)
    Com_Printf("%3i:%s\n", a8->readcount - 1, "packet entities");
  v12 = cl;
  Buf[2483] = *((_DWORD *)cl + 8564);
  Buf[2481] = 0;
  if (v35 && *((int *)v35 + 2481) > 0) {
    __src = (entityState_s *)((char *)&loc_D30E0 + (_DWORD)v12 +
                              240 * (*((_DWORD *)v35 + 2483) & 0x7FF));
    number = (msg_t *)__src->number;
  } else {
    __src = 0;
    number = (msg_t *)&loc_1869F;
  }
  v37 = 0;
LABEL_17:
  for (i = a8; !a8->overflowed; i = a8) {
    Bits = (msg_t *)MSG_ReadBits(i, 10);
    if (Bits == (msg_t *)1023)
      break;
    if ((signed int)a8->readcount > (signed int)a8->cursize)
      Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
                "\x15CL_ParsePacketEntities: end of message");
    while ((int)number < (int)Bits && !a8->overflowed) {
      if (*(_DWORD *)(cl_shownet + 8) == 3)
        Com_Printf("%3i:  unchanged: %i\n", a8->readcount, number);
      v24 = cl;
      memcpy((char *)&loc_D30E0 + (_DWORD)cl +
                 240 * (*((_DWORD *)cl + 8564) & 0x7FF),
             __src, 0xF0u);
      ++v24[8564];
      ++Buf[2481];
      if (++v37 >= *((_DWORD *)v35 + 2481)) {
        number = (msg_t *)&loc_1869F;
      } else {
        __src = (entityState_s
                     *)((char *)&loc_D30E0 +
                        (_DWORD)&v24[60 * ((*((_DWORD *)v35 + 2483) + v37) &
                                           0x7FF)]);
        number = (msg_t *)__src->number;
      }
    }
    if (number == Bits) {
      if (*(_DWORD *)(cl_shownet + 8) == 3)
        Com_Printf("%3i:  delta: %i\n", a8->readcount, number);
      v26 = cl;
      if (!MSG_ReadDeltaEntity(
              a8, __src,
              (entityState_s *)((char *)&loc_D30E0 + (_DWORD)cl +
                                240 * (*((_DWORD *)cl + 8564) & 0x7FF)),
              number)) {
        ++v26[8564];
        ++Buf[2481];
      }
      if (++v37 < *((_DWORD *)v35 + 2481)) {
        __src = (entityState_s
                     *)((char *)&loc_D30E0 +
                        (_DWORD)&v26[60 * ((*((_DWORD *)v35 + 2483) + v37) &
                                           0x7FF)]);
        number = (msg_t *)__src->number;
      } else {
        number = (msg_t *)&loc_1869F;
      }
      goto LABEL_17;
    }
    if (*(_DWORD *)(cl_shownet + 8) == 3)
      Com_Printf("%3i:  baseline: %i\n", a8->readcount, Bits);
    v16 = cl;
    if (MSG_ReadDeltaEntity(
            a8, (entityState_s *)cl + (_DWORD)Bits + 2578,
            (entityState_s *)((char *)&loc_D30E0 + (_DWORD)cl +
                              240 * (*((_DWORD *)cl + 8564) & 0x7FF)),
            Bits)) {
      goto LABEL_17;
    }
    ++v16[8564];
    ++Buf[2481];
  }
  if (number != (msg_t *)&loc_1869F) {
    do {
      if (a8->overflowed)
        break;
      if (*(_DWORD *)(cl_shownet + 8) == 3)
        Com_Printf("%3i:  unchanged: %i\n", a8->readcount, number);
      v17 = cl;
      memcpy((char *)&loc_D30E0 + (_DWORD)cl +
                 240 * (*((_DWORD *)cl + 8564) & 0x7FF),
             __src, 0xF0u);
      ++v17[8564];
      ++Buf[2481];
      if (++v37 >= *((_DWORD *)v35 + 2481))
        break;
      __src =
          (entityState_s
               *)((char *)&loc_D30E0 +
                  (_DWORD)&v17[60 * ((*((_DWORD *)v35 + 2483) + v37) & 0x7FF)]);
      number = (msg_t *)__src->number;
    } while ((_UNKNOWN *)__src->number != &loc_1869F);
  }
  if (*(_BYTE *)(cl_shownuments + 8))
    Com_Printf("Entities in packet: %i\n", Buf[2481]);
  if (*(int *)(cl_shownet + 8) > 1)
    Com_Printf("%3i:%s\n", a8->readcount - 1, "packet clients");
  v18 = cl;
  Buf[2484] = *((_DWORD *)cl + 8565);
  Buf[2482] = 0;
  if (v35 && *((int *)v35 + 2482) > 0) {
    v40 = (clientState_s *)((char *)&loc_14B0E0 + (_DWORD)v18 +
                            92 * (*((_DWORD *)v35 + 2484) & 0x7FF));
    clientIndex = (msg_t *)v40->clientIndex;
  } else {
    v40 = 0;
    clientIndex = (msg_t *)&loc_1869F;
  }
  v39 = 0;
LABEL_41:
  v19 = a8;
  if (!a8->overflowed) {
    while (MSG_ReadBit(v19)) {
      v20 = (msg_t *)MSG_ReadBits(a8, 6);
      if ((signed int)a8->readcount > (signed int)a8->cursize)
        Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
                  "\x15CL_ParsePacketClients: end of message");
      while ((int)v20 > (int)clientIndex) {
        while (1) {
          if (*(_DWORD *)(cl_shownet + 8) == 3)
            Com_Printf("%3i:  unchanged: %i\n", a8->readcount, clientIndex);
          v21 = cl;
          memcpy((char *)&loc_14B0E0 + (_DWORD)cl +
                     92 * (*((_DWORD *)cl + 8565) & 0x7FF),
                 v40, 0x5Cu);
          ++v21[8565];
          ++Buf[2482];
          if (++v39 < *((_DWORD *)v35 + 2482))
            break;
          clientIndex = (msg_t *)&loc_1869F;
          if ((int)v20 <= (int)&loc_1869F)
            goto LABEL_50;
        }
        v40 = (clientState_s
                   *)((char *)&loc_14B0E0 +
                      (_DWORD)&v21[23 *
                                   ((*((_DWORD *)v35 + 2484) + v39) & 0x7FF)]);
        clientIndex = (msg_t *)v40->clientIndex;
      }
    LABEL_50:
      if (v20 == clientIndex) {
        if (*(_DWORD *)(cl_shownet + 8) == 3)
          Com_Printf("%3i:  delta: %i\n", a8->readcount, clientIndex);
        v25 = cl;
        if (!MSG_ReadDeltaClient(
                a8, v40,
                (clientState_s *)((char *)&loc_14B0E0 + (_DWORD)cl +
                                  92 * (*((_DWORD *)cl + 8565) & 0x7FF)),
                clientIndex)) {
          ++v25[8565];
          ++Buf[2482];
        }
        if (++v39 < *((_DWORD *)v35 + 2482)) {
          v40 = (clientState_s
                     *)((char *)&loc_14B0E0 +
                        (_DWORD)&v25[23 * ((*((_DWORD *)v35 + 2484) + v39) &
                                           0x7FF)]);
          clientIndex = (msg_t *)v40->clientIndex;
        } else {
          clientIndex = (msg_t *)&loc_1869F;
        }
        goto LABEL_41;
      }
      if (*(_DWORD *)(cl_shownet + 8) == 3)
        Com_Printf("%3i:  baseline: %i\n", a8->readcount, v20);
      memset(&__b, 0, sizeof(__b));
      v22 = cl;
      if (MSG_ReadDeltaClient(
              a8, &__b,
              (clientState_s *)((char *)&loc_14B0E0 + (_DWORD)cl +
                                92 * (*((_DWORD *)cl + 8565) & 0x7FF)),
              v20)) {
        goto LABEL_41;
      }
      ++v22[8565];
      ++Buf[2482];
      v19 = a8;
      if (a8->overflowed)
        break;
    }
  }
  if (clientIndex != (msg_t *)&loc_1869F && !a8->overflowed) {
    do {
      if (*(_DWORD *)(cl_shownet + 8) == 3)
        Com_Printf("%3i:  unchanged: %i\n", a8->readcount, clientIndex);
      v23 = cl;
      memcpy((char *)&loc_14B0E0 + (_DWORD)cl +
                 92 * (*((_DWORD *)cl + 8565) & 0x7FF),
             v40, 0x5Cu);
      ++v23[8565];
      ++Buf[2482];
      if (++v39 >= *((_DWORD *)v35 + 2482))
        break;
      v40 =
          (clientState_s
               *)((char *)&loc_14B0E0 +
                  (_DWORD)&v23[23 * ((*((_DWORD *)v35 + 2484) + v39) & 0x7FF)]);
      clientIndex = (msg_t *)v40->clientIndex;
      if ((_UNKNOWN *)v40->clientIndex == &loc_1869F)
        break;
    } while (!a8->overflowed);
  }
  if (*(_BYTE *)(cl_shownuments + 8))
    Com_Printf("Clients in packet: %i\n", Buf[2482]);
  if (a8->overflowed) {
    *Buf = 0;
  LABEL_66:
    LargeLocal::~LargeLocal(&v43);
    return;
  }
  if (!*Buf)
    goto LABEL_66;
  v27 = cl;
  v28 = *((_DWORD *)cl + 9) + 1;
  v29 = Buf[3];
  if (v29 - v28 >= 32)
    v28 = v29 - 31;
  if (v29 > v28) {
    v34 = Buf[3];
    do
      v27[2486 * (v28++ & 0x1F) + 75128] = 0;
    while (v28 < v34);
  }
  v30 = cl;
  *((_DWORD *)cl + 2496) = *((_DWORD *)cl + 8);
  memcpy(v30 + 6, Buf, 0x26D8u);
  v30[11] = 999;
  v31 = 1;
  while (1) {
    v32 =
        &v30[3 *
             (((unsigned __int8)*(_DWORD *)((char *)&loc_407C8 + (_DWORD)clc) -
               (_BYTE)v31) &
              0x1F)];
    if (v30[13] >= *(_DWORD *)((char *)&loc_49464 + (_DWORD)v32))
      break;
    if (++v31 == 33)
      goto LABEL_103;
  }
  v30[11] = dword_1220A78 - v32[75034];
LABEL_103:
  v33 = cl;
  memcpy((char *)cl + 9944 * (*((_DWORD *)cl + 9) & 0x1F) + 300512,
         (char *)cl + 24, 0x26D8u);
  if (*(_DWORD *)(cl_shownet + 8) == 3)
    Com_Printf("   snapshot:%i  delta:%i  ping:%i\n", v33[9], v33[10], v33[11]);
  v33[2498] = 1;
  LargeLocal::~LargeLocal(&v43);
}

void __cdecl CL_ParseGamestate(struct msg_t *msg) {
  _DWORD *v8;         // ebx
  int Byte;           // eax
  char *v10;          // ebx
  unsigned int Bits;  // eax
  msg_t *v12;         // ebx
  size_t v13;         // esi
  _DWORD *v14;        // ebx
  int v15;            // edx
  netadr_t v16;       // [esp+0h] [ebp-138h]
  unsigned int Short; // [esp+18h] [ebp-120h]
  char *__src;        // [esp+1Ch] [ebp-11Ch]
  entityState_s __b;  // [esp+24h] [ebp-114h] BYREF
  __int64 v20;        // [esp+114h] [ebp-24h]
  int v21;            // [esp+11Ch] [ebp-1Ch]

  Con_Close();
  v8 = clc;
  *((_DWORD *)clc + 9) = 0;
  CL_ClearState();
  v8[32847] = MSG_ReadLong(a8);
  *((_DWORD *)cl + 8547) = 1;
LABEL_2:
  while (1) {
    Byte = MSG_ReadByte(a8);
    if (Byte == 7)
      break;
    while (Byte != 2) {
      if (Byte == 3) {
        Bits = MSG_ReadBits(a8, 10);
        v12 = (msg_t *)Bits;
        if (Bits > 0x3FF)
          Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                    "\x15Baseline number out of range: %i", Bits);
        memset(&__b, 0, sizeof(__b));
        MSG_ReadDeltaEntity(a8, &__b, (entityState_s *)cl + (_DWORD)v12 + 2578,
                            v12);
        goto LABEL_2;
      }
      Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                "\x15CL_ParseGamestate: bad command byte");
      Byte = MSG_ReadByte(a8);
      if (Byte == 7)
        goto LABEL_6;
    }
    Short = MSG_ReadShort(a8);
    if (Short > 0x7FF)
      Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                "\x15configstring > MAX_CONFIGSTRINGS");
    __src = MSG_ReadBigString(a8);
    v13 = strlen(__src) + 1;
    v14 = cl;
    v15 = *((_DWORD *)cl + 8547);
    if ((int)(v13 + v15) > 16000) {
      Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                "\x15MAX_GAMESTATE_CHARS exceeded");
      v15 = v14[8547];
    }
    v14[Short + 2499] = v15;
    memcpy((char *)v14 + v15 + 18188, __src, v13);
    v14[8547] += v13;
  }
LABEL_6:
  v10 = (char *)clc;
  *((_DWORD *)v10 + 2) = MSG_ReadLong(a8);
  *((_DWORD *)v10 + 75) = MSG_ReadLong(a8);
  CL_SystemInfoChanged();
  FS_ConditionalRestart(a1, *(float *)&a2, a3, a4, a5, a6, a7,
                        *((_DWORD *)v10 + 75));
  if (*(_BYTE *)(net_lanauthorize + 8) ||
      (v20 = *(_QWORD *)(v10 + 20), v21 = *((_DWORD *)v10 + 7),
       *(_QWORD *)&v16.type = v20, v16.port = v21, !Sys_IsLANAddress(v16))) {
    CL_RequestAuthorization(a1, *(float *)&a2, a3, a4, a5, a6, a7);
  }
  CL_InitDownloads(a1, a2, a3, a4, a5, a6, a7);
  Dvar_SetInt((dvar_s *)cl_paused, 0);
}

void __cdecl CL_ParseServerMessage(struct msg_t *msg) {
  unsigned __int8 *Buf; // edi
  int v9;               // ebx
  int v10;              // ebx
  char *v11;            // edx
  char *v12;            // eax
  msg_t v13;            // [esp+14h] [ebp-34h] BYREF
  LargeLocal v14;       // [esp+2Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v14, 0x4000);
  Buf = (unsigned __int8 *)LargeLocal::GetBuf(&v14);
  if (*(_DWORD *)(cl_shownet + 8) == 1) {
    Com_Printf("%i ", a8->cursize);
  } else if (*(int *)(cl_shownet + 8) > 1) {
    Com_Printf("------------------\n");
  }
  MSG_Init(&v13, Buf, 0x4000u);
  v13.cursize =
      MSG_ReadBitsCompress((unsigned __int8 *)(a8->data + a8->readcount), Buf,
                           a8->cursize - a8->readcount);
  while (2) {
    if (v13.overflowed)
      goto LABEL_12;
  LABEL_6:
    v9 = MSG_ReadByte(&v13);
    if (v9 != 7) {
      if (*(int *)(cl_shownet + 8) > 1) {
        if (svc_strings[v9])
          Com_Printf("%3i:%s\n", v13.readcount - 1, svc_strings[v9]);
        else
          Com_Printf("%3i:BAD CMD %i\n", v13.readcount - 1, v9);
      }
      switch (v9) {
      case 0:
        continue;
      case 1:
        CL_ParseGamestate(a1, a2, a3, a4, a5, a6, a7, &v13);
        continue;
      case 4:
        v10 = MSG_ReadLong(&v13);
        v11 = MSG_ReadString(&v13);
        v12 = (char *)clc;
        if (v10 > *((_DWORD *)clc + 32847)) {
          *((_DWORD *)clc + 32847) = v10;
          I_strncpyz(&v12[1024 * (v10 & 0x7F) + 131396], v11, 1024);
        }
        continue;
      case 5:
        CL_ParseDownload(a1, a2, a3, a4, a5, a6, a7, &v13);
        continue;
      case 6:
        CL_ParseSnapshot(a1, *(float *)&a2, a3, a4, a5, a6, a7, &v13);
        continue;
      default:
        Com_Error(a1, *(float *)&a2, a3, a4, a5, a6, a7, 1,
                  "\x15CL_ParseServerMessage: Illegible server message %d\n",
                  v9);
        if (v13.overflowed)
          goto LABEL_12;
        goto LABEL_6;
      }
    }
    break;
  }
  if (*(int *)(cl_shownet + 8) <= 1) {
  LABEL_12:
    LargeLocal::~LargeLocal(&v14);
    return;
  }
  Com_Printf("%3i:%s\n", v13.readcount - 1, "END OF MESSAGE");
  LargeLocal::~LargeLocal(&v14);
}

char **svc_strings;
void __cdecl CL_DeltaEntity(struct msg_t *, struct clSnapshot_t *, int,
                            struct entityState_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl CL_ParsePacketClients(struct msg_t *, struct clSnapshot_t *,
                                   struct clSnapshot_t *) {
  UNIMPLEMENTED();
}

void __cdecl CL_ParsePacketEntities(struct msg_t *, struct clSnapshot_t *,
                                    struct clSnapshot_t *) {
  UNIMPLEMENTED();
}

CL_ParseDownload(msg_t *msg) { UNIMPLEMENTED(); }
