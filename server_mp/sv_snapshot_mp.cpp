void __cdecl SV_UpdateServerCommandsToClient_PreventOverflow(struct client_s *,
                                                             struct msg_t *,
                                                             int) {
  UNIMPLEMENTED();
}

void __cdecl SV_PrintServerCommandsForClient(struct client_s *) {
  UNIMPLEMENTED();
}

void __cdecl SV_UpdateServerCommandsToClient(struct client_s *client,
                                             struct msg_t *msg) {
  int32_t reliableAcknowledge; // edx
  int v3;                      // ebx
  int result;                  // eax

  reliableAcknowledge = a1->reliableAcknowledge;
  if (reliableAcknowledge + 1 <
          *(_DWORD *)((char *)`global constructor keyed
                          to'CMemoryBuffer::sDelayedFreeRequests +
                      (_DWORD)a1) &&
      *(_BYTE *)(sv_debugReliableCmds + 8)) {
    Com_Printf("Client %s has the following un-ack'd reliable commands:\n",
               &a1->name[2]);
    reliableAcknowledge = a1->reliableAcknowledge;
  }
  v3 = reliableAcknowledge + 1;
  result = *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1);
  if ( reliableAcknowledge + 1 <= result )
  {
    do {
      MSG_WriteByte(a2, 4);
      MSG_WriteLong(a2, v3);
      MSG_WriteString(a2, &a1->reliableCommandInfo[1032 * (v3 & 0x7F)]);
      if (*(_BYTE *)(sv_debugReliableCmds + 8))
        Com_Printf("%i: %s\n", v3 - a1->reliableAcknowledge - 1,
                   &a1->reliableCommandInfo[1032 * (v3 & 0x7F)]);
      ++v3;
      result = *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a1);
    } while (result >= v3);
  }
  *(_DWORD *)((char *)&loc_20814 + (_DWORD)a1) = result;
  return result;
}

void __cdecl SV_ArchiveSnapshot() {
  unsigned __int8 *Buf;    // edx
  int v8;                  // esi
  int v9;                  // edx
  int *v10;                // edi
  client_s *v11;           // edi
  char *v12;               // esi
  const void *ClientState; // eax
  int FollowPlayerState;   // eax
  _DWORD *v15;             // ecx
  signed __int32 cursize;  // edx
  size_t v17;              // esi
  int v18;                 // edi
  const gentity_s *v19;    // eax
  const gentity_s *v20;    // ebx
  archivedEntity_s *v21;   // esi
  uint32_t svFlags;        // eax
  char *v23;               // edx
  int v24;                 // ebx
  int v25;                 // ebx
  int v26;                 // esi
  int v27;                 // edx
  bool v28;                // cc
  clientState_s *v29;      // eax
  clientState_s *v30;      // eax
  int v31;                 // esi
  const gentity_s *v32;    // eax
  const gentity_s *v33;    // ebx
  uint32_t v34;            // eax
  char *v35;               // edx
  _DWORD *v36;             // [esp+28h] [ebp-2810h]
  char *v37;               // [esp+2Ch] [ebp-280Ch]
  int v38;                 // [esp+30h] [ebp-2808h]
  int v39;                 // [esp+34h] [ebp-2804h]
  int v40;                 // [esp+3Ch] [ebp-27FCh]
  playerState_s v41;       // [esp+48h] [ebp-27F0h] BYREF
  archivedEntity_s __dst;  // [esp+26F0h] [ebp-148h] BYREF
  msg_t v43;               // [esp+2804h] [ebp-34h] BYREF
  LargeLocal v44;          // [esp+281Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v44, (int)&loc_20000);
  Buf = (unsigned __int8 *)LargeLocal::GetBuf(&v44);
  if (sv[0] != 2 || !unk_17004A8)
    goto LABEL_29;
  MSG_Init(&v43, Buf, (uint32_t)&loc_20000);
  v8 = dword_17004C4 - 512;
  if (dword_17004C4 - 512 < 0)
    v8 = 0;
  v9 = dword_17004C4 - 1;
  if (v8 > dword_17004C4 - 1)
    goto LABEL_10;
  while (1) {
    v10 = (int *)((char *)dword_17004D0 + 28 * (v9 % 512));
    if (dword_17004AC - *(_DWORD *)(sv_fps + 8) <= *v10 && !v10[6])
      break;
    if (v8 > --v9)
      goto LABEL_10;
  }
  if (v10[3] < dword_17004BC - 0x4000 || v10[5] < dword_17004C0 - 4096) {
  LABEL_10:
    MSG_WriteBit1(&v43);
    MSG_WriteLong(&v43, dword_1700484);
    v36 = (char *)dword_17004D0 + 28 * (dword_17004C4 % 512);
    *v36 = dword_17004AC;
    v36[2] = 0;
    v36[3] = dword_17004BC;
    v36[4] = 0;
    v36[5] = dword_17004C0;
    v36[6] = 0;
    v36[1] = dword_1700484;
    v11 = dword_170048C;
    if (*(int *)(sv_maxclients + 8) <= 0) {
    LABEL_19:
      MSG_WriteBit0(&v43);
      if (unk_1700324 > 0) {
        v18 = 0;
        do {
          v19 = (const gentity_s *)SV_GentityNum(v18);
          v20 = v19;
          if (v19->r.linked) {
            if (v19->r.broadcastTime ||
                (v19->r.svFlags & 1) == 0 && ((v23 = SV_SvEntityForGentity(v19),
                                               (v20->r.svFlags & 0x18) != 0) ||
                                              *((_DWORD *)v23 + 70))) {
              v21 = (archivedEntity_s *)((char *)dword_17004C8 +
                                         276 * (dword_17004BC % 0x4000));
              memcpy(v21, v20, 0xF0u);
              svFlags = (unsigned __int8)v20->r.svFlags;
              v21->r.svFlags = svFlags;
              if (v20->r.broadcastTime)
                v21->r.svFlags = svFlags | 8;
              LODWORD(v21->r.clientMask) = v20->r.clientMask;
              HIDWORD(v21->r.clientMask) = HIDWORD(v20->r.clientMask);
              v21->r.absmin[0] = v20->r.absmin[0];
              v21->r.absmin[1] = v20->r.absmin[1];
              v21->r.absmin[2] = v20->r.absmin[2];
              v21->r.absmax[0] = v20->r.absmax[0];
              v21->r.absmax[1] = v20->r.absmax[1];
              v21->r.absmax[2] = v20->r.absmax[2];
              MSG_WriteDeltaArchivedEntity(
                  &v43, (archivedEntity_s *)&sv[93 * v20->s.number + 2311], v21,
                  (msg_t *)1);
              if (++dword_17004BC > 2147483645)
                Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
                          "\x15svs.nextCachedSnapshotEntities wrapped");
              ++v36[2];
            }
          }
          ++v18;
        } while (v18 < unk_1700324);
      }
      if (++dword_17004C4 > 2147483645)
        Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
                  "\x15svs.nextCachedSnapshotFrames wrapped");
      goto LABEL_22;
    }
    v40 = 0;
    while (1) {
      if (v11->state <= 1)
        goto LABEL_14;
      v12 = (char *)dword_17004CC + 9992 * (dword_17004C0 % 4096);
      ClientState = (const void *)G_GetClientState(v40);
      memcpy(v12 + 4, ClientState, 0x5Cu);
      MSG_WriteDeltaClient(&v43, 0, (clientState_s *)(v12 + 4), (msg_t *)1);
      FollowPlayerState =
          GetFollowPlayerState(v40, (playerState_s *)(v12 + 96));
      *(_DWORD *)v12 = FollowPlayerState;
      if (FollowPlayerState) {
        MSG_WriteBit1(&v43);
        MSG_WriteDeltaPlayerstate(&v43, 0, (playerState_s *)(v12 + 96));
        if (++dword_17004C0 > 2147483645)
          goto LABEL_18;
      } else {
        MSG_WriteBit0(&v43);
        if (++dword_17004C0 > 2147483645)
        LABEL_18:
          Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
                    "\x15svs.nextCachedSnapshotClients wrapped");
      }
      ++v36[4];
    LABEL_14:
      ++v40;
      v11 = (client_s *)((char *)v11 + 495372);
      if (v40 >= *(_DWORD *)(sv_maxclients + 8))
        goto LABEL_19;
    }
  }
  MSG_WriteBit0(&v43);
  MSG_WriteLong(&v43, *v10);
  MSG_WriteLong(&v43, dword_1700484);
  v38 = *(_DWORD *)(sv_maxclients + 8);
  v39 = v10[4];
  v37 = 0;
  v25 = 0;
  v26 = 0;
LABEL_48:
  while (v25 < v38) {
    while (1) {
      if (*(&dword_170048C->state + 123843 * v25) <= 1)
        goto LABEL_61;
      if (v26 < v39) {
      LABEL_50:
        v37 = (char *)dword_17004CC + 9992 * ((v10[5] + v26) % 4096);
        v27 = *((_DWORD *)v37 + 1);
        v28 = v25 < v27;
        if (v25 == v27)
          goto LABEL_58;
      } else {
        v27 = 9999;
        v28 = v25 < 9999;
        if (v25 == 9999) {
        LABEL_58:
          v29 = (clientState_s *)G_GetClientState(v25);
          MSG_WriteDeltaClient(&v43, (clientState_s *)(v37 + 4), v29,
                               (msg_t *)1);
          if (GetFollowPlayerState(v25, &v41)) {
            MSG_WriteBit1(&v43);
            MSG_WriteDeltaPlayerstate(&v43, (playerState_s *)(v37 + 96), &v41);
          } else {
            MSG_WriteBit0(&v43);
          }
          ++v26;
        LABEL_61:
          ++v25;
          goto LABEL_48;
        }
      }
      if (v28)
        break;
      if (v25 > v27)
        ++v26;
      if (v25 >= v38)
        goto LABEL_49;
    }
    v30 = (clientState_s *)G_GetClientState(v25);
    MSG_WriteDeltaClient(&v43, 0, v30, (msg_t *)1);
    if (GetFollowPlayerState(v25, &v41)) {
      MSG_WriteBit1(&v43);
      MSG_WriteDeltaPlayerstate(&v43, 0, &v41);
    } else {
      MSG_WriteBit0(&v43);
    }
    ++v25;
  }
LABEL_49:
  if (v26 < v39)
    goto LABEL_50;
  MSG_WriteBit0(&v43);
  if (unk_1700324 > 0) {
    v31 = 0;
    do {
      v32 = (const gentity_s *)SV_GentityNum(v31);
      v33 = v32;
      if (v32->r.linked) {
        if (v32->r.broadcastTime ||
            (v32->r.svFlags & 1) == 0 && ((v35 = SV_SvEntityForGentity(v32),
                                           (v33->r.svFlags & 0x18) != 0) ||
                                          *((_DWORD *)v35 + 70))) {
          memcpy(&__dst, v33, 0xF0u);
          v34 = (unsigned __int8)v33->r.svFlags;
          __dst.r.svFlags = v34;
          if (v33->r.broadcastTime)
            __dst.r.svFlags = v34 | 8;
          __dst.r.clientMask = v33->r.clientMask;
          __dst.r.absmin[0] = v33->r.absmin[0];
          __dst.r.absmin[1] = v33->r.absmin[1];
          __dst.r.absmin[2] = v33->r.absmin[2];
          __dst.r.absmax[0] = v33->r.absmax[0];
          __dst.r.absmax[1] = v33->r.absmax[1];
          __dst.r.absmax[2] = v33->r.absmax[2];
          MSG_WriteDeltaArchivedEntity(
              &v43, (archivedEntity_s *)&sv[93 * v33->s.number + 2311], &__dst,
              (msg_t *)1);
        }
      }
      ++v31;
    } while (unk_1700324 > v31);
  }
LABEL_22:
  MSG_WriteBits(&v43, 1023, 10);
  if (v43.overflowed) {
    Com_DPrintf(
        "SV_ArchiveSnapshot: ignoring snapshot because it overflowed.\n");
  } else {
    v15 = (char *)dword_17004B0 + 8 * (dword_17004AC % 1200);
    *v15 = dword_17004B8;
    v15[1] = v43.cursize;
    v24 = dword_17004B8 % 0x2000000;
    cursize = v43.cursize;
    dword_17004B8 += v43.cursize;
    if (dword_17004B8 > 2147483645) {
      Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
                "\x15svs.nextArchivedSnapshotBuffer wrapped");
      cursize = v43.cursize;
    }
    v17 = 0x2000000 - v24;
    if (0x2000000 - v24 < cursize) {
      memcpy((char *)dword_17004B4 + v24, (const void *)v43.data, v17);
      memcpy((void *)dword_17004B4, (const void *)(v43.data + v17),
             v43.cursize - v17);
    } else {
      memcpy((char *)dword_17004B4 + v24, (const void *)v43.data, cursize);
    }
    if (++dword_17004AC > 2147483645)
      Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
                "\x15svs.nextArchivedSnapshotFrames wrapped");
  }
LABEL_29:
  LargeLocal::~LargeLocal(&v44);
}

int __cdecl SV_GetArchivedClientInfo(int clientNum, int *pArchiveTime,
                                     struct playerState_s *ps,
                                     struct clientState_s *cs) {
  int *v4;                        // eax
  int v5;                         // edx
  int v6;                         // edi
  int v7;                         // ebx
  const void *ClientState;        // eax
  _DWORD *CachedSnapshotInternal; // eax
  int v11;                        // esi
  _DWORD *v12;                    // ebx
  int v13;                        // ecx
  uint32_t pm_time;               // eax
  int v15;                        // eax
  uint32_t jumpTime;              // eax
  uint32_t viewHeightLerpTime;    // eax
  uint32_t shellshockTime;        // eax
  playerState_s *v19;             // edx
  int i;                          // ebx
  int v21;                        // eax
  int v22;                        // eax
  int v23;                        // eax
  int v24;                        // eax
  int v25;                        // eax
  int v26;                        // [esp+18h] [ebp-20h]

  if (!unk_17004A8) {
    if (*a2 > 0)
      return 0;
  LABEL_12:
    if (*(&dword_170048C->state + 123843 * a1) != 4 ||
        !GetFollowPlayerState(a1, a3))
      return 0;
    ClientState = (const void *)G_GetClientState(a1);
    memcpy(__dst, ClientState, sizeof(clientState_s));
    return 1;
  }
  v4 = a2;
  v5 = *a2;
  if (*a2 <= 0) {
  LABEL_9:
    if (*v4 > 0)
      return 0;
    goto LABEL_12;
  }
  v6 = *(_DWORD *)(sv_fps + 8);
  v7 = dword_17004AC - 1200;
  if (dword_17004AC - v6 * v5 / 1000 < dword_17004AC - 1200)
    *a2 = 1200000 / v6;
  else
    v7 = dword_17004AC - v6 * v5 / 1000;
  if (v7 < 0) {
    *a2 = 1000 * dword_17004AC / *(_DWORD *)(sv_fps + 8);
    v7 = 0;
  }
  if (dword_17004AC <= v7) {
  LABEL_8:
    *a2 = 0;
    v4 = a2;
    goto LABEL_9;
  }
  while (1) {
    CachedSnapshotInternal = SV_GetCachedSnapshotInternal(v7);
    if (CachedSnapshotInternal)
      break;
    if (++v7 >= dword_17004AC)
      goto LABEL_8;
  }
  v11 = dword_1700484 - CachedSnapshotInternal[1];
  v26 = CachedSnapshotInternal[4];
  if (v26 <= 0)
    return 0;
  v12 = (char *)dword_17004CC + 9992 * (CachedSnapshotInternal[5] % 4096);
  if (a1 != v12[1]) {
    v13 = 0;
    while (v26 != ++v13) {
      v12 = (char *)dword_17004CC +
            9992 * ((CachedSnapshotInternal[5] + v13) % 4096);
      if (a1 == v12[1])
        goto LABEL_25;
    }
    return 0;
  }
LABEL_25:
  if (!*v12)
    return 0;
  memcpy(a3, v12 + 24, sizeof(playerState_s));
  memcpy(__dst, v12 + 1, sizeof(clientState_s));
  if (*(_DWORD *)a3->commandTime)
    *(_DWORD *)a3->commandTime += v11;
  pm_time = a3->pm_time;
  if (pm_time)
    a3->pm_time = v11 + pm_time;
  v15 = *(_DWORD *)a3->foliageSoundTime;
  if (v15)
    *(_DWORD *)a3->foliageSoundTime = v11 + v15;
  jumpTime = a3->jumpTime;
  if (jumpTime)
    a3->jumpTime = v11 + jumpTime;
  viewHeightLerpTime = a3->viewHeightLerpTime;
  if (viewHeightLerpTime)
    a3->viewHeightLerpTime = v11 + viewHeightLerpTime;
  shellshockTime = a3->shellshockTime;
  if (shellshockTime)
    a3->shellshockTime = v11 + shellshockTime;
  v19 = a3;
  for (i = 0; i != 31; ++i) {
    v21 = *(_DWORD *)&v19->hud.archival[104];
    if (v21)
      *(_DWORD *)&v19->hud.archival[104] = v11 + v21;
    v22 = *(_DWORD *)&v19->hud.archival[40];
    if (v22) {
      v23 = v11 + v22;
      *(_DWORD *)&v19->hud.archival[40] = v23;
      if (v23 > dword_1700484)
        *(_DWORD *)&v19->hud.archival[40] = dword_1700484;
    }
    v24 = *(_DWORD *)&v19->hud.archival[72];
    if (v24)
      *(_DWORD *)&v19->hud.archival[72] = v11 + v24;
    v25 = *(_DWORD *)&v19->hud.archival[96];
    if (v25)
      *(_DWORD *)&v19->hud.archival[96] = v11 + v25;
    v19 = (playerState_s *)((char *)v19 + 128);
  }
  a3->deltaTime += v11;
  return 1;
}

bool __cdecl SV_GetClientPositionAtTime(int client, int gametime,
                                        float *const pos) {
  int v3;                 // esi
  int v4;                 // ebx
  int v5;                 // ebx
  int ArchivedClientInfo; // eax
  float v7;               // xmm2_4
  float v8;               // xmm3_4
  int i;                  // edx
  int v11;                // [esp+24h] [ebp-2744h]
  int v12;                // [esp+28h] [ebp-2740h]
  char v13;               // [esp+2Fh] [ebp-2739h]
  playerState_s v14;      // [esp+30h] [ebp-2738h] BYREF
  clientState_s __dst;    // [esp+26D8h] [ebp-90h] BYREF
  float v16;              // [esp+2734h] [ebp-34h] BYREF
  float v17;              // [esp+2738h] [ebp-30h]
  float v18;              // [esp+273Ch] [ebp-2Ch]
  float v19;              // [esp+2740h] [ebp-28h] BYREF
  float v20;              // [esp+2744h] [ebp-24h]
  float v21;              // [esp+2748h] [ebp-20h]
  int v22[7];             // [esp+274Ch] [ebp-1Ch] BYREF

  v3 = 1000 / *(_DWORD *)(sv_fps + 8);
  v11 = v3 * (SV_GetClientPositionAtTime(int, int, float *)::startOffset +
              (v3 * (dword_1700484 / v3) - a2) / v3);
  v12 = v3 * (SV_GetClientPositionAtTime(int, int, float *)::endOffset +
              (v3 * (dword_1700484 / v3) - a2) / v3);
  v22[0] = v11;
  v4 = 10;
  while (!SV_GetArchivedClientInfo(a1, v22, &v14, &__dst)) {
    v22[0] += v3;
    if (!--v4) {
      v13 = 0;
      goto LABEL_5;
    }
  }
  v11 = v22[0];
  v19 = v14.origin[0];
  v20 = v14.origin[1];
  v21 = v14.origin[2];
  v13 = 1;
LABEL_5:
  v22[0] = v12;
  v5 = 10;
  while (1) {
    ArchivedClientInfo = SV_GetArchivedClientInfo(a1, v22, &v14, &__dst);
    if (ArchivedClientInfo)
      break;
    v22[0] -= v3;
    if (!--v5)
      goto LABEL_8;
  }
  v12 = v22[0];
  v16 = v14.origin[0];
  v17 = v14.origin[1];
  v18 = v14.origin[2];
  LOBYTE(ArchivedClientInfo) = 1;
LABEL_8:
  if (v13) {
    if ((_BYTE)ArchivedClientInfo) {
      v7 = (float)(a2 % v3) / (float)(v11 - v12);
      v8 = 1.0 - v7;
    } else {
      v16 = 0.0;
      v17 = 0.0;
      v18 = 0.0;
      v7 = 0.0;
      v8 = 1.0;
    }
  } else {
    if (!(_BYTE)ArchivedClientInfo)
      return 0;
    v19 = 0.0;
    v20 = 0.0;
    v21 = 0.0;
    v7 = 1.0;
    v8 = 0.0;
  }
  for (i = 1; i != 4; ++i)
    a3[i - 1] = (float)(v8 * *(&v19 + i - 1)) + (float)(v7 * *(&v16 + i - 1));
  return 1;
}

void __cdecl SV_SendMessageToClient(struct msg_t *msg,
                                    struct client_s *client) {
  unsigned __int8 *Buf; // edi
  int v4;               // edi
  DvarValue v5;         // esi
  const dvar_s *v6;     // edx
  DvarValue current;    // eax
  int v8;               // esi
  int v9;               // eax
  int v10;              // eax
  netadr_t v11;         // [esp+0h] [ebp-58h]
  int __n;              // [esp+2Ch] [ebp-2Ch]
  LargeLocal v13;       // [esp+3Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v13, 0x4000);
  Buf = (unsigned __int8 *)LargeLocal::GetBuf(&v13);
  *(_DWORD *)Buf = *(_DWORD *)a2->data;
  __n = MSG_WriteBitsCompress((unsigned __int8 *)(a2->data + 4), Buf + 4,
                              a2->cursize - 4) +
        4;
  if (a3->dropReason)
    SV_DropClient(a1, a3, (char *)a3->dropReason);
  *(_DWORD *)((char *)&loc_233E4 + (_DWORD)a3 +
              9924 * (*(int32_t *)((_BYTE *)&a3->netchan.outgoingSequence + 2) &
                      0x1F)) = __n;
  *(_DWORD *)&a3
       ->frames[9924 *
                    (*(int32_t *)((_BYTE *)&a3->netchan.outgoingSequence + 2) &
                     0x1F) +
                9914] = dword_1700484;
  *(_DWORD *)&a3
       ->frames[9924 *
                    (*(int32_t *)((_BYTE *)&a3->netchan.outgoingSequence + 2) &
                     0x1F) +
                9918] = -1;
  SV_Netchan_Transmit(a3, Buf, __n);
  if (*(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a3) == 2 ||
      (v11.type = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a3),
       v11.ip = *(int32_t *)((char *)&a3->netchan.remoteAddress.ip + 2),
       v11.port = a3->netchan.qport, Sys_IsLANAddress(v11))) {
    *(uint32_t *)((char *)&a3->nextSnapshotTime + 2) = dword_1700484 - 1;
    LargeLocal::~LargeLocal(&v13);
  } else {
    if (__n > 1500)
      v4 = 1500;
    else
      v4 = __n;
    v5 = *(DvarValue *)((char *)&a3->rate + 2);
    v6 = sv_maxRate;
    current = sv_maxRate->current;
    if (current.integer) {
      if (current.integer <= 999) {
        Dvar_SetInt((dvar_s *)sv_maxRate, 1000);
        v6 = sv_maxRate;
      }
      if (v5.integer > v6->current.integer)
        v5 = v6->current;
    }
    v8 = (1000 * v4 + 48000) / v5.integer;
    if (*(_BYTE *)(sv_debugRate + 8))
      Com_Printf("It would take %ims to send %i bytes to client %s (rate %i)\n",
                 v8, v4, &a3->name[2], *(int32_t *)((char *)&a3->rate + 2));
    v9 = *(int32_t *)((char *)&a3->snapshotMsec + 2);
    if (v8 >= v9) {
      *(int32_t *)((char *)&a3->rateDelayed + 2) = 1;
    } else {
      *(int32_t *)((char *)&a3->rateDelayed + 2) = 0;
      v8 = v9;
    }
    v10 = dword_1700484 + v8;
    *(uint32_t *)((char *)&a3->nextSnapshotTime + 2) = dword_1700484 + v8;
    if (a3->state != 4 && !*((_BYTE *)&loc_20C68 + (_DWORD)a3) &&
        v10 < dword_1700484 + 1000)
      *(uint32_t *)((char *)&a3->nextSnapshotTime + 2) = dword_1700484 + 1000;
    *(_DWORD *)((char *)&loc_5F48C + (_DWORD)&sv) += __n;
    LargeLocal::~LargeLocal(&v13);
  }
}

void __cdecl SV_SendClientSnapshot(struct client_s *client) {
  client_s *v2;                   // ebx
  int v3;                         // ebx
  int v4;                         // eax
  playerState_s *v5;              // ebx
  char v6;                        // si
  char v7;                        // dl
  entityState_s *v8;              // edi
  entityState_s *v9;              // ebx
  int ii;                         // edx
  int number;                     // ecx
  bool v12;                       // cc
  int32_t v13;                    // edi
  int32_t v14;                    // ebx
  int clientIndex;                // ecx
  bool v16;                       // cc
  client_s *v17;                  // ebx
  char *v18;                      // esi
  int ClientArchiveTime;          // eax
  int v20;                        // edx
  int v21;                        // ebx
  const void *v22;                // eax
  int v23;                        // eax
  int v24;                        // eax
  __m128 v25;                     // rt1
  int v26;                        // edx
  client_s *v27;                  // edx
  client_s *v28;                  // ecx
  int v29;                        // ebx
  client_s *v30;                  // edx
  int v31;                        // ebx
  client_s *v32;                  // ecx
  client_s *jj;                   // ecx
  const char *v34;                // esi
  int v35;                        // ebx
  int v36;                        // edi
  _DWORD *j;                      // ecx
  int v38;                        // eax
  int v39;                        // eax
  __m128 v40;                     // rt1
  _DWORD *v41;                    // ebx
  const void *ClientState;        // eax
  _DWORD *v43;                    // ebx
  int v44;                        // eax
  int v45;                        // eax
  int v46;                        // eax
  int v47;                        // eax
  signed int v48;                 // eax
  signed int v49;                 // ebx
  const gentity_s *k;             // eax
  int broadcastTime;              // edx
  char *v52;                      // edi
  int v53;                        // edx
  char *v54;                      // ebx
  int n;                          // edi
  int v56;                        // ebx
  int m;                          // eax
  int v58;                        // edi
  int v59;                        // eax
  netadr_t v60;                   // [esp+4h] [ebp-1334h]
  char v61;                       // [esp+8h] [ebp-1330h]
  char v62;                       // [esp+8h] [ebp-1330h]
  char v63;                       // [esp+8h] [ebp-1330h]
  char v64;                       // [esp+8h] [ebp-1330h]
  char v65;                       // [esp+8h] [ebp-1330h]
  void *__src;                    // [esp+2Ch] [ebp-130Ch]
  int v67;                        // [esp+38h] [ebp-1300h]
  const char *v68;                // [esp+3Ch] [ebp-12FCh]
  unsigned __int8 *Buf;           // [esp+40h] [ebp-12F8h]
  client_s *v70;                  // [esp+44h] [ebp-12F4h]
  _DWORD *CachedSnapshotInternal; // [esp+48h] [ebp-12F0h]
  int v72;                        // [esp+4Ch] [ebp-12ECh]
  int v73;                        // [esp+50h] [ebp-12E8h]
  int v74;                        // [esp+58h] [ebp-12E0h]
  int v75;                        // [esp+5Ch] [ebp-12DCh]
  int v76;                        // [esp+60h] [ebp-12D8h]
  gentity_s *v77;                 // [esp+64h] [ebp-12D4h]
  int v78;                        // [esp+68h] [ebp-12D0h]
  unsigned int v79;               // [esp+6Ch] [ebp-12CCh]
  float v80;                      // [esp+6Ch] [ebp-12CCh]
  int v81;                        // [esp+70h] [ebp-12C8h]
  int v82;                        // [esp+74h] [ebp-12C4h]
  int v83;                        // [esp+78h] [ebp-12C0h]
  int v84;                        // [esp+7Ch] [ebp-12BCh]
  float *v85;                     // [esp+80h] [ebp-12B8h]
  float *v86;                     // [esp+84h] [ebp-12B4h]
  int v87;                        // [esp+88h] [ebp-12B0h]
  unsigned int v88;               // [esp+8Ch] [ebp-12ACh]
  float v89;                      // [esp+8Ch] [ebp-12ACh]
  int v90;                        // [esp+90h] [ebp-12A8h]
  playerState_s *v91;             // [esp+94h] [ebp-12A4h]
  int32_t v92;                    // [esp+98h] [ebp-12A0h]
  int v93;                        // [esp+9Ch] [ebp-129Ch]
  int32_t bobCycle;               // [esp+A0h] [ebp-1298h]
  int v95;                        // [esp+A4h] [ebp-1294h]
  int v96;                        // [esp+A8h] [ebp-1290h]
  int v97;                        // [esp+ACh] [ebp-128Ch]
  uint32_t v98;                   // [esp+B0h] [ebp-1288h]
  int32_t v99;                    // [esp+B4h] [ebp-1284h]
  uint32_t pm_flags;              // [esp+B8h] [ebp-1280h]
  int32_t pm_type;                // [esp+BCh] [ebp-127Ch]
  clientState_s *v102;            // [esp+C0h] [ebp-1278h]
  clientState_s *v103;            // [esp+C4h] [ebp-1274h]
  int v104;                       // [esp+C8h] [ebp-1270h]
  int v105;                       // [esp+D4h] [ebp-1264h]
  int v106;                       // [esp+D8h] [ebp-1260h]
  int i;                          // [esp+DCh] [ebp-125Ch]
  int v108[1024];                 // [esp+E8h] [ebp-1250h]
  int v109[128];                  // [esp+10E8h] [ebp-250h] BYREF
  msg_t v110;                     // [esp+12E8h] [ebp-50h] BYREF
  __int64 v111;                   // [esp+1300h] [ebp-38h]
  int32_t qport;                  // [esp+1308h] [ebp-30h]
  float v113[2];                  // [esp+130Ch] [ebp-2Ch] BYREF
  float v114;                     // [esp+1314h] [ebp-24h]
  int v115;                       // [esp+1318h] [ebp-20h] BYREF
  LargeLocal v116;                // [esp+131Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v116, (int)&loc_20000);
  Buf = (unsigned __int8 *)LargeLocal::GetBuf(&v116);
  if (a2->state == 4) {
    v17 = a2;
  } else {
    if (a2->state != 1)
      goto LABEL_3;
    v17 = a2;
  }
  v18 =
      (char *)&loc_20D24 + (_DWORD)v17 +
      9924 * (*(int32_t *)((_BYTE *)&v17->netchan.outgoingSequence + 2) & 0x1F);
  *((_DWORD *)v18 + 2474) = 0;
  *((_DWORD *)v18 + 2475) = 0;
  if (*(int32_t *)((char *)&v17->gentity + 2)) {
    if (v17->state != 1) {
      *((_DWORD *)v18 + 2476) = dword_1700498;
      *((_DWORD *)v18 + 2477) = dword_170049C;
      if (sv == 2) {
        v67 = 931767531 * (((char *)v17 - (char *)dword_170048C) >> 2);
        ClientArchiveTime = G_GetClientArchiveTime(v67);
        v73 = ClientArchiveTime;
        if (unk_17004A8 && ClientArchiveTime > 0) {
          v74 = *(_DWORD *)(sv_fps + 8);
          v20 = v74 * ClientArchiveTime / 1000;
          v21 = dword_17004AC - v20;
          if (dword_17004AC - v20 < dword_17004AC - 1200) {
            v73 = 1200000 / v74;
            v21 = dword_17004AC - 1200;
          }
          if (v21 < 0) {
            v73 = 1000 * dword_17004AC / v74;
            v21 = 0;
          }
          if (v21 < dword_17004AC) {
            while (1) {
              CachedSnapshotInternal = SV_GetCachedSnapshotInternal(v21);
              if (CachedSnapshotInternal)
                break;
              if (++v21 >= dword_17004AC)
                goto LABEL_62;
            }
          } else {
          LABEL_62:
            CachedSnapshotInternal = 0;
            v73 = 0;
          }
        } else {
          CachedSnapshotInternal = 0;
        }
        G_SetClientArchiveTime(v67, v73);
        if (CachedSnapshotInternal)
          v72 = dword_1700484 - CachedSnapshotInternal[1];
        else
          v72 = 0;
        v22 = (const void *)SV_GameClientNum(v67);
        memcpy(v18, v22, 0x26A8u);
        v82 = *((_DWORD *)v18 + 51);
        if ((unsigned int)v82 > 0x3FF)
          Com_Error(1, "\x15SV_BuildClientSnapshot: bad gEnt", v61);
        v113[0] = *((float *)v18 + 5);
        v113[1] = *((float *)v18 + 6);
        v114 = *((float *)v18 + 7);
        a1 = v114 + *((float *)v18 + 62);
        v114 = a1;
        AddLeanToPosition(v113, *((float *)v18 + 59), *((float *)v18 + 19),
                          16.0, 20.0);
        if (CachedSnapshotInternal) {
          v83 = CachedSnapshotInternal[3];
          v84 = CachedSnapshotInternal[2];
          v23 = CM_PointLeafnum(v113);
          v24 = CM_LeafCluster(v23);
          if (v24 >= 0) {
            v87 = CM_ClusterPVS(v24);
            *(float *)&v88 = G_GetFogOpaqueDistSqrd();
            v25.i32[0] = 2139095039;
            LODWORD(a1) = _mm_cmpneq_ss((__m128)v88, v25).u32[0] & v88;
            v89 = a1;
            if (v84 > 0) {
              v90 = 0;
              v105 = 0;
              do {
                v26 = unk_17004C8 + 276 * ((v90 + v83) % 0x4000);
                if (((*(int *)(v26 + 4 * (v82 >> 5) + 244) >> (v82 & 0x1F)) &
                     1) == 0 &&
                    v82 != *(_DWORD *)v26) {
                  if ((*(_BYTE *)(v26 + 240) & 0x18) != 0) {
                    if (v105 != 1024)
                      v108[v105++] = v90;
                  } else {
                    v85 = (float *)(v26 + 264);
                    v86 = (float *)(v26 + 252);
                    v48 = CM_BoxLeafnums((const float *)(v26 + 252),
                                         (const float *)(v26 + 264), v109,
                                         0x80u, &v115);
                    v49 = v48;
                    if (v48) {
                      if (v48 <= 0)
                        goto LABEL_139;
                      v58 = 0;
                      do {
                        v59 = CM_LeafCluster(v109[v58]);
                        if (v59 != -1 &&
                            (((int)*(unsigned __int8 *)(v87 + (v59 >> 3)) >>
                              (v59 & 7)) &
                             1) != 0)
                          break;
                        ++v58;
                      } while (v58 != v49);
                      if (v49 != v58) {
                      LABEL_139:
                        a1 = v89;
                        if ((v89 == 0.0 ||
                             !BoxDistSqrdExceeds(v86, v85, v113, v89)) &&
                            v105 != 1024)
                          v108[v105++] = v90;
                      }
                    }
                  }
                }
                ++v90;
              } while (v84 != v90);
              if (v105 > 0) {
                for (i = 0; i != v105; ++i) {
                  v43 = (_DWORD *)(unk_17004A0 +
                                   240 * (dword_1700498 % dword_1700490));
                  memcpy(v43,
                         (const void *)(unk_17004C8 +
                                        276 * ((v108[i] +
                                                CachedSnapshotInternal[3]) %
                                               0x4000)),
                         0xF0u);
                  v44 = v43[4];
                  if (v44)
                    v43[4] = v72 + v44;
                  v45 = v43[13];
                  if (v45)
                    v43[13] = v72 + v45;
                  v46 = v43[21];
                  if (v46)
                    v43[21] = v72 + v46;
                  v47 = v43[22];
                  if (v47)
                    v43[22] = v72 + v47;
                  if (++dword_1700498 > 2147483645)
                    Com_Error(0, "\x15svs.nextSnapshotEntities wrapped", v64);
                  ++*((_DWORD *)v18 + 2474);
                }
              }
            }
          }
          if ((int)CachedSnapshotInternal[4] > 0) {
            v36 = 0;
            for (j = CachedSnapshotInternal;; j = CachedSnapshotInternal) {
              memcpy(
                  (void *)(unk_17004A4 + 92 * (dword_170049C % dword_1700494)),
                  (const void *)(unk_17004CC + 9992 * ((j[5] + v36) % 4096) +
                                 4),
                  0x5Cu);
              if (++dword_170049C > 2147483645)
                Com_Error(0, "\x15svs.nextSnapshotClients wrapped", v62);
              ++*((_DWORD *)v18 + 2475);
              if (CachedSnapshotInternal[4] <= ++v36)
                break;
            }
          }
          goto LABEL_3;
        }
        v38 = CM_PointLeafnum(v113);
        v39 = CM_LeafCluster(v38);
        if (v39 < 0)
          goto LABEL_116;
        v78 = CM_ClusterPVS(v39);
        *(float *)&v79 = G_GetFogOpaqueDistSqrd();
        v40.i32[0] = 2139095039;
        LODWORD(a1) = _mm_cmpneq_ss((__m128)v79, v40).u32[0] & v79;
        v80 = a1;
        if (unk_1700324 <= 0)
          goto LABEL_116;
        v81 = 0;
        v104 = 0;
        for (k = (const gentity_s *)SV_GentityNum(0);;
             k = (const gentity_s *)SV_GentityNum(v81)) {
          v77 = (gentity_s *)k;
          if (!k->r.linked || v81 == v82)
            goto LABEL_149;
          broadcastTime = k->r.broadcastTime;
          if (broadcastTime) {
            if (broadcastTime < 0 || broadcastTime - dword_1700484 >= 0) {
            LABEL_147:
              if (v104 != 1024)
                v108[v104++] = v81;
              goto LABEL_149;
            }
            k->r.broadcastTime = 0;
          } else if ((k->r.svFlags & 1) != 0 ||
                     ((*(int *)&k->r.pad0[4 * (v82 >> 5) + 1] >> (v82 & 0x1F)) &
                      1) != 0) {
            goto LABEL_149;
          }
          if ((k->r.svFlags & 0x18) != 0)
            goto LABEL_147;
          v52 = SV_SvEntityForGentity(k);
          v75 = *((_DWORD *)v52 + 70);
          if (v75) {
            if (v75 <= 0)
              goto LABEL_163;
            v53 = *((_DWORD *)v52 + 71);
            if ((((int)*(unsigned __int8 *)((v53 >> 3) + v78) >>
                  (v52[284] & 7)) &
                 1) != 0)
              goto LABEL_163;
            v54 = v52;
            v76 = 0;
            while (v75 != ++v76) {
              v53 = *((_DWORD *)v54 + 72);
              v54 += 4;
              if ((((int)*(unsigned __int8 *)((v53 >> 3) + v78) >> (v53 & 7)) &
                   1) != 0)
                goto LABEL_163;
            }
            v56 = *((_DWORD *)v52 + 87);
            if (v56) {
              if (v56 >= v53) {
                for (m = *(unsigned __int8 *)(v78 + (v53 >> 3));
                     ((m >> (v53 & 7)) & 1) == 0;
                     m = *(unsigned __int8 *)((v53 >> 3) + v78)) {
                  if (++v53 > v56)
                    break;
                }
              }
              if (v53 != v56) {
              LABEL_163:
                a1 = v80;
                if ((v80 == 0.0 ||
                     !BoxDistSqrdExceeds(v77->r.absmin, v77->r.absmax, v113,
                                         v80)) &&
                    v104 != 1024)
                  v108[v104++] = v81;
              }
            }
          }
        LABEL_149:
          if (unk_1700324 <= ++v81) {
            if (v104 > 0) {
              for (n = 0; n != v104; ++n) {
                __src = (void *)SV_GentityNum(v108[n]);
                memcpy((void *)(unk_17004A0 +
                                240 * (dword_1700498 % dword_1700490)),
                       __src, 0xF0u);
                if (++dword_1700498 > 2147483645)
                  Com_Error(0, "\x15svs.nextSnapshotEntities wrapped", v65);
                ++*((_DWORD *)v18 + 2474);
              }
            }
          LABEL_116:
            v70 = dword_170048C;
            if (*(int *)(sv_maxclients + 8) > 0) {
              v106 = 0;
              do {
                if (v70->state > 1) {
                  v41 = (_DWORD *)(unk_17004A4 +
                                   92 * (dword_170049C % dword_1700494));
                  ClientState = (const void *)G_GetClientState(v106);
                  memcpy(v41, ClientState, 0x5Cu);
                  if (v106 == *v41) {
                    if (++dword_170049C > 2147483645)
                      Com_Error(0, "\x15svs.nextSnapshotClients wrapped", v63);
                    ++*((_DWORD *)v18 + 2475);
                  }
                }
                ++v106;
                v70 = (client_s *)((char *)v70 + 495372);
              } while (v106 < *(_DWORD *)(sv_maxclients + 8));
            }
            break;
          }
        }
      }
    }
  }
LABEL_3:
  MSG_Init(&v110, Buf, (uint32_t)&loc_20000);
  MSG_WriteLong(&v110, *(_DWORD *)&a2->lastClientCommand[2]);
  if (a2->state != 4 && a2->state != 1) {
    v2 = a2;
    goto LABEL_6;
  }
  SV_UpdateServerCommandsToClient(a2, &v110);
  v3 = *(int32_t *)((char *)&a2->netchan.outgoingSequence + 2);
  v91 = (playerState_s *)((char *)&loc_20D24 + (_DWORD)a2 + 9924 * (v3 & 0x1F));
  v4 = *(_DWORD *)&a2->deltaMessage[2];
  if (v4 > 0 && a2->state == 4) {
    v6 = v3 - v4;
    if (v3 - v4 > 28) {
      Com_DPrintf("%s: Delta request from out of date packet.\n", &a2->name[2]);
    } else {
      v5 = (playerState_s *)((char *)&loc_20D24 + (_DWORD)a2 +
                             9924 * (*(_DWORD *)&a2->deltaMessage[2] & 0x1F));
      if (v5[1].bobCycle >= dword_1700498 - dword_1700490)
        goto LABEL_16;
      Com_DPrintf("%s: Delta request from out of date entities.\n",
                  &a2->name[2]);
    }
  }
  v5 = 0;
  v6 = 0;
LABEL_16:
  MSG_WriteByte(&v110, 6);
  MSG_WriteLong(&v110, dword_1700484);
  MSG_WriteByte(&v110, v6);
  v7 = unk_1700488;
  if (*(int32_t *)((char *)&a2->rateDelayed + 2))
    v7 = unk_1700488 | 1;
  if (a2->state == 4) {
    a2->sendAsActive = 1;
  } else if (a2->state != 1) {
    a2->sendAsActive = 0;
  }
  if (!a2->sendAsActive)
    v7 |= 2u;
  MSG_WriteByte(&v110, v7);
  if (v5) {
    MSG_WriteDeltaPlayerstate(&v110, v5, v91);
    v95 = *(_DWORD *)v5[1].commandTime;
    bobCycle = v5[1].bobCycle;
    pm_type = v5[1].pm_type;
    pm_flags = v5[1].pm_flags;
  } else {
    MSG_WriteDeltaPlayerstate(&v110, 0, v91);
    v95 = 0;
    bobCycle = 0;
    pm_type = 0;
    pm_flags = 0;
  }
  v92 = v91[1].bobCycle;
  v93 = *(_DWORD *)v91[1].commandTime;
  v8 = 0;
  v9 = 0;
  v97 = 0;
  v96 = 0;
  for (ii = v93;; ii = v93) {
    while (v97 < ii) {
      v8 = (entityState_s *)(unk_17004A0 + 240 * ((v92 + v97) % dword_1700490));
      number = v8->number;
      if (v95 > v96)
        goto LABEL_34;
      v12 = number >= 9999;
      if (number != 9999)
        goto LABEL_29;
    LABEL_35:
      MSG_WriteDeltaEntity(&v110, v9, v8, 0);
      ++v96;
      ++v97;
      ii = v93;
    }
    if (v95 <= v96)
      break;
    number = 9999;
  LABEL_34:
    v9 = (entityState_s *)(unk_17004A0 +
                           240 * ((v96 + bobCycle) % dword_1700490));
    v12 = (signed int)v9->number <= number;
    if (v9->number == number)
      goto LABEL_35;
  LABEL_29:
    if (v12) {
      MSG_WriteDeltaEntity(&v110, v9, 0, (msg_t *)1);
      ++v96;
    } else {
      MSG_WriteDeltaEntity(&v110,
                           (entityState_s *)((char *)&sv + 372 * number + 9244),
                           v8, (msg_t *)1);
      ++v97;
    }
  }
  MSG_WriteBits(&v110, 1023, 10);
  v98 = v91[1].pm_flags;
  v99 = v91[1].pm_type;
  v103 = 0;
  v102 = 0;
  v13 = 0;
  v14 = 0;
LABEL_38:
  if (v13 < v99) {
  LABEL_39:
    v103 = (clientState_s *)(unk_17004A4 +
                             92 * ((int)(v13 + v98) % dword_1700494));
    clientIndex = v103->clientIndex;
    if (pm_type <= v14) {
      v16 = clientIndex >= 9999;
      if (clientIndex == 9999)
        goto LABEL_46;
      goto LABEL_41;
    }
    goto LABEL_45;
  }
  while (pm_type > v14) {
    clientIndex = 9999;
  LABEL_45:
    v102 = (clientState_s *)(unk_17004A4 +
                             92 * ((int)(v14 + pm_flags) % dword_1700494));
    v16 = (signed int)v102->clientIndex <= clientIndex;
    if (v102->clientIndex == clientIndex) {
    LABEL_46:
      MSG_WriteDeltaClient(&v110, v102, v103, 0);
      ++v14;
      ++v13;
      goto LABEL_38;
    }
  LABEL_41:
    if (!v16) {
      MSG_WriteDeltaClient(&v110, 0, v103, (msg_t *)1);
      ++v13;
      goto LABEL_38;
    }
    MSG_WriteDeltaClient(&v110, v102, 0, (msg_t *)1);
    ++v14;
    if (v13 < v99)
      goto LABEL_39;
  }
  MSG_WriteBit0(&v110);
  if (*(int *)(sv_padPackets + 8) > 0) {
    v35 = 0;
    do {
      MSG_WriteByte(&v110, 0);
      ++v35;
    } while (v35 < *(_DWORD *)(sv_padPackets + 8));
  }
  if (a2->state != 1) {
    v2 = a2;
  LABEL_6:
    SV_WriteDownloadToClient(v2, &v110);
  }
  MSG_WriteByte(&v110, 7);
  if (v110.overflowed) {
    v68 = &a2->name[2];
    Com_Printf("WARNING: msg overflowed for %s, trying to recover\n",
               &a2->name[2]);
    if (a2->state == 4) {
      v27 = a2;
    } else {
      if (a2->state != 1)
        goto LABEL_10;
      v27 = a2;
    }
    Com_Printf("-- Unacknowledged Server Commands for client %i:%s --\n",
               931767531 * (((char *)v27 - (char *)dword_170048C) >> 2), v68);
    v28 = a2;
    v29 = a2->reliableAcknowledge + 1;
    if ( v29 <= *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a2) )
    {
      while (1) {
        Com_Printf(
            "cmd %5d: %8d: %s\n", v29,
            *(_DWORD *)&v28->reliableCommandInfo[1032 * (v29 & 0x7F) + 1024],
            &v28->reliableCommandInfo[1032 * (v29 & 0x7F)]);
        if ( ++v29 > *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a2) )
          break;
        v28 = a2;
      }
    }
    Com_Printf("----------");
    MSG_Init(&v110, Buf, (uint32_t)&loc_20000);
    MSG_WriteLong(&v110, *(_DWORD *)&a2->lastClientCommand[2]);
    v30 = a2;
    v31 = a2->reliableAcknowledge + 1;
    if ( v31 <= *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a2) )
    {
      for (jj = a2;; jj = a2) {
        v34 = &jj->reliableCommandInfo[1032 * (v31 & 0x7F)];
        if ((int)(strlen(v34) + 1 + v110.cursize + 5) > 0x1FFFF)
          break;
        MSG_WriteByte(&v110, 4);
        MSG_WriteLong(&v110, v31);
        MSG_WriteString(&v110, v34);
        ++v31;
        v30 = a2;
        if ( v31 > *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a2) )
          goto LABEL_85;
      }
      v32 = a2;
    }
    else
    {
    LABEL_85:
      v32 = v30;
    }
    if ( v31 - 1 > *(_DWORD *)((char *)&loc_20814 + (_DWORD)v32) )
      *(_DWORD *)((char *)&loc_20814 + (_DWORD)v32) = v31 - 1;
    MSG_WriteByte(&v110, 7);
LABEL_10:
    if ( v110.overflowed )
    {
      Com_Printf("WARNING: client disconnected for msg overflow: %s\n", v68);
      LODWORD(v111) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a2);
      HIDWORD(v111) = *(int32_t *)((char *)&a2->netchan.remoteAddress.ip + 2);
      qport = a2->netchan.qport;
      *(_QWORD *)&v60.type = v111;
      v60.port = qport;
      NET_OutOfBandPrint(NS_SERVER, v60, "disconnect");
      SV_DropClient(a1, a2, "EXE_SERVERMESSAGEOVERFLOW");
    }
  }
  SV_SendMessageToClient(a1, &v110, a2);
  LargeLocal::~LargeLocal(&v116);
}

void __cdecl SV_SendClientMessages() {
  client_s *v0;      // ebx
  int v1;            // edi
  DvarValue current; // esi
  const dvar_s *v3;  // edx
  int integer;       // eax
  int v5;            // esi
  int result;        // eax
  float v7;          // xmm2_4
  float v8;          // xmm1_4
  _DWORD *v9;        // edx
  int v10;           // eax
  int v11;           // eax
  int v12;           // ecx
  float v13;         // xmm3_4
  float v14;         // xmm4_4
  float v15;         // xmm1_4
  float v16;         // xmm0_4
  int v17;           // [esp+48h] [ebp-30h]
  int v18;           // [esp+4Ch] [ebp-2Ch]
  int v19;           // [esp+50h] [ebp-28h]
  int v20;           // [esp+54h] [ebp-24h]

  *(_DWORD *)((char *)&loc_5F48C + (_DWORD)&sv) = 0;
  dword_1700390[21] = 0;
  v0 = dword_170048C;
  if (*(int *)(sv_maxclients + 8) > 0) {
    v18 = 0;
    v19 = 0;
    while (1) {
      while (1) {
        if (v0->state) {
          v17 = dword_1700484;
          if (dword_1700484 >=
              *(signed int *)((char *)&v0->nextSnapshotTime + 2))
            break;
        }
      LABEL_16:
        ++v18;
        v0 = (client_s *)((char *)v0 + 495372);
        if (v18 >= *(_DWORD *)(sv_maxclients + 8))
          goto LABEL_17;
      }
      ++v19;
      if (*(_DWORD *)((char *)&loc_725DC + (_DWORD)v0)) {
        v1 = *(_DWORD *)v0->netchan.unsentBuffer - v0->netchan.unsentLength;
        if (v1 <= 1500) {
          v20 = 1000 * v1;
        } else {
          v1 = 1500;
          v20 = 1500000;
        }
        current = *(DvarValue *)((char *)&v0->rate + 2);
        v3 = sv_maxRate;
        integer = sv_maxRate->current.integer;
        if (integer) {
          if (integer <= 999) {
            Dvar_SetInt(sv_maxRate, 1000);
            v3 = sv_maxRate;
          }
          if (current.integer > v3->current.integer)
            current = v3->current;
        }
        v5 = (v20 + 48000) / current.integer;
        if (*(_BYTE *)(sv_debugRate + 8))
          Com_Printf(
              "It would take %ims to send %i bytes to client %s (rate %i)\n",
              v5, v1, &v0->name[2], *(int32_t *)((char *)&v0->rate + 2));
        *(uint32_t *)((char *)&v0->nextSnapshotTime + 2) = v5 + v17;
        SV_Netchan_TransmitNextFragment(
            (netchan_t *)((char *)&v0->netchan.outgoingSequence + 2));
        goto LABEL_16;
      }
      SV_SendClientSnapshot(v0);
      SV_SendClientVoiceData(v0);
      ++v18;
      v0 = (client_s *)((char *)v0 + 495372);
      if (v18 >= *(_DWORD *)(sv_maxclients + 8))
        goto LABEL_17;
    }
  }
  v19 = 0;
LABEL_17:
  result = sv_showAverageBPS;
  if (*(_BYTE *)(sv_showAverageBPS + 8) && v19 > 0) {
    v7 = 0.0;
    v8 = 0.0;
    v9 = &sv;
    do {
      v10 = *(_DWORD *)((char *)&loc_5F43C + (_DWORD)v9);
      v9[97550] = v10;
      v8 = v8 + (float)v10;
      v11 = v9[97574];
      *(_DWORD *)((char *)&loc_5F494 + (_DWORD)v9) = v11;
      v7 = v7 + (float)v11;
      ++v9;
    } while (v9 != (_DWORD *)&unk_16A0F4C);
    v12 = *(_DWORD *)((char *)&loc_5F48C + (_DWORD)&sv);
    unk_1700384 = v12;
    dword_1700390[20] = dword_1700390[21];
    if (v12 >= dword_1700390[0]) {
      dword_1700390[0] = v12;
      if (dword_1700390[21] < dword_1700390[22]) {
      LABEL_23:
        result = unk_1700388 + 1;
        unk_1700388 = result;
        if (result <= 19)
          return result;
      LABEL_31:
        unk_1700388 = 0;
        v13 = (float)((float)v12 + v8) / 20.0;
        v14 = (float)((float)dword_1700390[21] + v7) / 20.0;
        v15 = (float)(1.0 - (float)(v13 / v14)) * 100.0;
        v16 = v15 + *(float *)((char *)&loc_5F4EC + (_DWORD)&sv);
        *(float *)((char *)&loc_5F4EC + (_DWORD)&sv) = v16;
        return Com_DPrintf("bpspc(%2.0f) bps(%2.0f) pk(%i) ubps(%2.0f) upk(%i) "
                           "cr(%2.2f) acr(%2.2f)\n",
                           (float)(v13 / (float)v19), v13, dword_1700390[0],
                           v14, dword_1700390[22], v15,
                           (float)(v16 / (float)++dword_1700390[24]));
      }
    } else if (dword_1700390[21] < dword_1700390[22]) {
      goto LABEL_23;
    }
    dword_1700390[22] = dword_1700390[21];
    result = unk_1700388 + 1;
    unk_1700388 = result;
    if (result > 19)
      goto LABEL_31;
  }
  return result;
}

void __cdecl SV_AddArchivedEntToSnapshot(int,
                                         struct snapshotEntityNumbers_t *) {
  UNIMPLEMENTED();
}

void __cdecl SV_AddEntToSnapshot(int, struct snapshotEntityNumbers_t *) {
  UNIMPLEMENTED();
}

int __cdecl SV_GetCurrentClientInfo(int, struct playerState_s *,
                                    struct clientState_s *) {
  UNIMPLEMENTED();
}

void __cdecl SV_AddCachedEntitiesVisibleFromPoint(
    int, int, float *const, int, struct snapshotEntityNumbers_t *,
    struct playerState_s *) {
  UNIMPLEMENTED();
}

void __cdecl SV_AddEntitiesVisibleFromPoint(float *const, int,
                                            struct snapshotEntityNumbers_t *) {
  UNIMPLEMENTED();
}

int __cdecl SV_RateMsec(struct client_s *, int) { UNIMPLEMENTED(); }

void __cdecl SV_EmitPacketClients(int, int, int, int, int, struct msg_t *) {
  UNIMPLEMENTED();
}

void __cdecl SV_EmitPacketEntities(int, int, int, int, int, struct msg_t *) {
  UNIMPLEMENTED();
}

struct cachedSnapshot_t *__cdecl SV_GetCachedSnapshotInternal(int) {
  UNIMPLEMENTED();
}

void __cdecl SV_WriteSnapshotToClient(struct client_s *, struct msg_t *) {
  UNIMPLEMENTED();
}

struct cachedSnapshot_t *__cdecl SV_GetCachedSnapshot(int *) {
  UNIMPLEMENTED();
}

void __cdecl SV_BuildClientSnapshot(struct client_s *) { UNIMPLEMENTED(); }
