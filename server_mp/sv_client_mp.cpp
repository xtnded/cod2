void __cdecl SV_DelayDropClient(struct client_s *drop, char const *reason)
{
  client_s *result; // eax

  result = a1;
  if (a1->state != 1 && !a1->dropReason)
    a1->dropReason = (int32_t)a2;
  return result;
}

void __cdecl SV_BanGuidBriefly(int guid)
{
  int v1;     // esi
  int v2;     // ecx
  int result; // eax
  _DWORD *v4; // edx
  _DWORD *v5; // ebx

    if (*(_DWORD *)&byte_170A4EC[12]) {
      v2 = 0;
      v1 = 0;
      v4 = &svs;
        while (1) {
          v5 = v4;
          if (v4[10271] < *((_DWORD *)&svs + 2 * v2 + 10271))
            v2 = v1;
          if (++v1 == 16)
            break;
          v4 += 2;
          if (!v5[10272])
            goto LABEL_3;
        }
    }
    else {
      v1 = 0;
    LABEL_3:
      v2 = v1;
    }
  *((_DWORD *)&svs + 2 * v2 + 10270) = a1;
  result = dword_1700484;
  *((_DWORD *)&svs + 2 * v2 + 10271) = dword_1700484;
  return result;
}

float __cdecl SV_FX_GetVisibility(float const *const start,
                                  float const *const end)
{
  return FX_GetServerVisibility(a1, a2);
}

void __cdecl SV_FreeClientScriptPers()
{
  UNIMPLEMENTED();
}

void __cdecl SV_UnbanClient(char const *name)
{
  signed int File; // esi
  void *v2;        // eax
  void *v3;        // edi
  const char *v4;  // edx
  char i;          // al
  char v6;         // al
  size_t v7;       // [esp+18h] [ebp-70h]
  int v8;          // [esp+1Ch] [ebp-6Ch]
  char v9[64];     // [esp+28h] [ebp-60h] BYREF
  void *__src;     // [esp+68h] [ebp-20h] BYREF
  void *__dst;     // [esp+6Ch] [ebp-1Ch] BYREF

  File = FS_ReadFile("ban.txt", (char **)&__dst);
    if (File >= 0) {
      I_strncpyz(v9, a1, 64);
      I_CleanStr(v9);
      v7 = strlen(v9);
      v2 = __dst;
      __src = __dst;
      v8 = 0;
        while (1) {
          v3 = v2;
          if (!*Com_Parse((char **)&__src))
            break;
            while (1) {
              v4 = (const char *)__src;
                for (i = *(_BYTE *)__src; *v4; i = *v4) {
                  if (i > 32)
                    break;
                  __src = (void *)++v4;
                }
                if (!strnicmp(v4, v9, v7)) {
                  v6 = *((_BYTE *)__src + v7);
                  if (v6 == 13 || v6 == 10)
                    break;
                }
              Com_SkipRestOfLine((unsigned __int8 **)&__src);
              v3 = __src;
              if (!*Com_Parse((char **)&__src))
                goto LABEL_11;
            }
          Com_SkipRestOfLine((unsigned __int8 **)&__src);
          ++v8;
          memmove(v3, __src, File - ((_BYTE *)__src - (_BYTE *)__dst) + 1);
          File -= (_BYTE *)__src - (_BYTE *)v3;
          v2 = v3;
          __src = v3;
        }
    LABEL_11:
      FS_WriteFile("ban.txt", (char *)__dst, File);
      FS_FreeFile(__dst);
      if (v8)
        Com_Printf("unbanned %i user(s) named %s\n", v8, v9);
      else
        Com_Printf("no banned user has name %s\n", v9);
    }
}

void __cdecl SV_UserinfoChanged(struct client_s *cl)
{
  char *userinfo; // esi
  char *v2;       // eax
  const char *v3; // eax
  const char *v4; // eax
  int result;     // eax
  const char *v6; // eax
  int v7;         // eax
  int v8;         // eax
  int v9;         // eax
  netadr_t v10;   // [esp+0h] [ebp-28h]

  userinfo = a1->userinfo;
  v2 = (char *)Info_ValueForKey(a1->userinfo, "name");
  I_strncpyz(&a1->name[2], v2, 32);
  v10.type = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a1);
  v10.ip = *(int32_t *)((char *)&a1->netchan.remoteAddress.ip + 2);
  v10.port = a1->netchan.qport;
    if (!Sys_IsLANAddress(v10) || *(_DWORD *)(com_dedicated + 8) == 2) {
      v6 = (const char *)Info_ValueForKey(userinfo, "rate");
        if (!*v6) {
          *(int32_t *)((char *)&a1->rate + 2) = 5000;
          v3 = (const char *)Info_ValueForKey(userinfo, "snaps");
          if (!*v3)
            goto LABEL_5;
          goto LABEL_11;
        }
      v9 = atoi(v6);
      *(int32_t *)((char *)&a1->rate + 2) = v9;
        if (v9 > 999) {
          if (v9 > 90000)
            *(int32_t *)((char *)&a1->rate + 2) = 90000;
        }
        else {
          *(int32_t *)((char *)&a1->rate + 2) = 1000;
        }
    }
    else {
      *(int32_t *)((char *)&a1->rate + 2) = (int32_t)&loc_1869F;
    }
  v3 = (const char *)Info_ValueForKey(userinfo, "snaps");
    if (!*v3) {
    LABEL_5:
      *(int32_t *)((char *)&a1->snapshotMsec + 2) = 50;
      goto LABEL_6;
    }
LABEL_11:
  v7 = atoi(v3);
    if (v7 <= 0) {
      v8 = 1000;
    }
    else if (v7 <= 30) {
      v8 = 1000 / v7;
    }
    else {
      v8 = 33;
    }
  *(int32_t *)((char *)&a1->snapshotMsec + 2) = v8;
LABEL_6:
  v4 = (const char *)Info_ValueForKey(userinfo, "cl_voice");
  result = atoi(v4);
  HIBYTE(a1[1].state) = result > 0;
  if (*(int *)((char *)&a1->rate + 2) <= 4999)
    HIBYTE(a1[1].state) = 0;
  return result;
}

void __cdecl SV_GetChallenge(struct netadr_t from)
{
  char *v1;       // edi
  int v2;         // esi
  _DWORD *v3;     // ebx
  __int64 *v5;    // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8;         // ebx
  netadr_t v9;    // [esp+4h] [ebp-B4h]
  __int64 v10;    // [esp+Ch] [ebp-ACh]
  __int64 v11;    // [esp+Ch] [ebp-ACh]
  int v12;        // [esp+14h] [ebp-A4h] OVERLAPPED
  int v13;        // [esp+14h] [ebp-A4h] OVERLAPPED
  int v14;        // [esp+2Ch] [ebp-8Ch]
  int v15;        // [esp+30h] [ebp-88h]

  v14 = 0;
  v15 = 0x7FFFFFFF;
  v1 = (char *)&unk_17004DC;
  v2 = 0;
  v3 = &unk_17004FC;
    while (1) {
        if (!*v3) {
          v12 = *(v3 - 6);
          v10 = *((_QWORD *)v3 - 4);
          if (NET_CompareAdr((netadr_t)a1, *(netadr_t *)(&v12 - 2)))
            break;
        }
        if (*(v3 - 4) < v15) {
          v14 = v2;
          v15 = *(v3 - 4);
        }
      ++v2;
      v1 += 40;
      v3 += 10;
        if (v2 == 1024) {
          v1 = (char *)&svs + 40 * v14 + 92;
          v8 = rand();
          *((_DWORD *)v1 + 3) = dword_1700484 ^ rand() ^ (v8 << 16);
          *((_WORD *)v1 + 4) = WORD4(a1);
          *(_QWORD *)v1 = a1;
          *((_DWORD *)v1 + 6) = dword_1700484;
          *((_DWORD *)v1 + 7) = 0;
          *((_DWORD *)v1 + 4) = dword_1700484;
          *((_DWORD *)v1 + 8) = 0;
          v2 = v14;
          break;
        }
    }
    if (!*(_BYTE *)(net_lanauthorize + 8) && Sys_IsLANAddress((netadr_t)a1)) {
      *((_DWORD *)v1 + 5) = dword_1700484;
      v7 = (const char *)va("challengeResponse %i", *((_DWORD *)v1 + 3));
      return NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, v7);
    }
    if (!MEMORY[0x170A4EC][0] && stru_170A4E8 != 1) {
      Com_Printf("Resolving %s\n", "cod2master.activision.com");
      if (!NET_StringToAdr("cod2master.activision.com",
                           (netadr_t *)&stru_170A4E8))
        return Com_Printf("Couldn't resolve address\n");
      *(_WORD *)&MEMORY[0x170A4EC][4] = -9136;
      Com_Printf("%s resolved to %i.%i.%i.%i:%i\n", "cod2master.activision.com",
                 MEMORY[0x170A4EC][0], MEMORY[0x170A4EC][1],
                 MEMORY[0x170A4EC][2], MEMORY[0x170A4EC][3], 20700);
    }
  if (dword_1700484 - *((_DWORD *)v1 + 6) <= 5000)
    return SV_AuthorizeRequest((netadr_t)a1, *((_DWORD *)&svs + 10 * v2 + 26));
  v5 = (__int64 *)SV_MasterAddress();
  v13 = *((_DWORD *)v5 + 2);
  v11 = *v5;
  if (NET_CompareAdr((netadr_t)a1, *(netadr_t *)(&v13 - 2)))
    return SV_AuthorizeRequest((netadr_t)a1, *((_DWORD *)&svs + 10 * v2 + 26));
  Com_DPrintf("authorize server timed out\n");
  *((_DWORD *)v1 + 5) = dword_1700484;
  v6 = (const char *)va("challengeResponse %i", *((_DWORD *)v1 + 3));
  *(_QWORD *)&v9.type = *(_QWORD *)v1;
  v9.port = *((_DWORD *)v1 + 2);
  return NET_OutOfBandPrint(NS_SERVER, v9, v6);
}

void __cdecl SV_ClientEnterWorld(struct client_s *client, struct usercmd_s *cmd)
{
  UNIMPLEMENTED();
}

void __cdecl SV_FreeClient(struct client_s *cl)
{
  UNIMPLEMENTED();
}

void __cdecl SV_DropClient(struct client_s *drop, char const *reason)
{
  UNIMPLEMENTED();
}

void __cdecl SV_DirectConnect(struct netadr_t from)
{
  const char *v1;   // eax
  const char *v2;   // eax
  int v3;           // ebx
  const char *v4;   // eax
  int result;       // eax
  const char *v6;   // eax
  const char *v7;   // eax
  client_s *v8;     // ebx
  int v9;           // esi
  client_s *v10;    // ebx
  int v11;          // esi
  const char *v12;  // eax
  int v13;          // edx
  int32_t *v14;     // edx
  int32_t *v15;     // ebx
  int *v16;         // ecx
  int v17;          // eax
  const char *v18;  // eax
  const char *v19;  // eax
  char *v20;        // ebx
  int i;            // esi
  int v22;          // ebx
  const char *v23;  // eax
  int v24;          // eax
  int v25;          // eax
  const char *v26;  // eax
  int v27;          // ebx
  int v28;          // esi
  client_s *v29;    // edx
  int v30;          // ecx
  const char *v31;  // eax
  netadr_t v32;     // [esp+Ch] [ebp-54Ch]
  netadr_t v33;     // [esp+Ch] [ebp-54Ch]
  netadr_t v34;     // [esp+Ch] [ebp-54Ch]
  int v35;          // [esp+28h] [ebp-530h]
  int v36;          // [esp+2Ch] [ebp-52Ch]
  int v37;          // [esp+30h] [ebp-528h]
  int v38;          // [esp+34h] [ebp-524h]
  int v39;          // [esp+38h] [ebp-520h]
  const char *v40;  // [esp+3Ch] [ebp-51Ch]
  int v41;          // [esp+48h] [ebp-510h]
  int v42;          // [esp+4Ch] [ebp-50Ch]
  char __dst[1024]; // [esp+5Ch] [ebp-4FCh] BYREF
  __int64 v44;      // [esp+45Ch] [ebp-FCh]
  int v45;          // [esp+464h] [ebp-F4h]
  __int64 v46;      // [esp+468h] [ebp-F0h]
  int32_t qport;    // [esp+470h] [ebp-E8h]
  __int64 v48;      // [esp+474h] [ebp-E4h]
  int v49;          // [esp+47Ch] [ebp-DCh]
  __int64 v50;      // [esp+480h] [ebp-D8h]
  int v51;          // [esp+488h] [ebp-D0h]
  __int64 v52;      // [esp+48Ch] [ebp-CCh]
  int v53;          // [esp+494h] [ebp-C4h]
  __int64 v54;      // [esp+498h] [ebp-C0h]
  int v55;          // [esp+4A0h] [ebp-B8h]
  __int64 v56;      // [esp+4A4h] [ebp-B4h]
  int v57;          // [esp+4ACh] [ebp-ACh]
  __int64 v58;      // [esp+4B0h] [ebp-A8h]
  int v59;          // [esp+4B8h] [ebp-A0h]
  __int64 v60;      // [esp+4BCh] [ebp-9Ch]
  int v61;          // [esp+4C4h] [ebp-94h]
  __int64 v62;      // [esp+4C8h] [ebp-90h]
  int v63;          // [esp+4D0h] [ebp-88h]
  __int64 v64;      // [esp+4D4h] [ebp-84h]
  int v65;          // [esp+4DCh] [ebp-7Ch]
  __int64 v66;      // [esp+4E0h] [ebp-78h]
  int v67;          // [esp+4E8h] [ebp-70h]
  __int64 v68;      // [esp+4ECh] [ebp-6Ch]
  int32_t v69;      // [esp+4F4h] [ebp-64h]
  __int64 v70;      // [esp+4F8h] [ebp-60h]
  int v71;          // [esp+500h] [ebp-58h]
  __int64 v72;      // [esp+504h] [ebp-54h]
  int v73;          // [esp+50Ch] [ebp-4Ch]
  __int64 v74;      // [esp+510h] [ebp-48h]
  int v75;          // [esp+518h] [ebp-40h]
  __int64 v76;      // [esp+51Ch] [ebp-3Ch]
  int v77;          // [esp+524h] [ebp-34h]
  __int64 v78;      // [esp+528h] [ebp-30h]
  int v79;          // [esp+530h] [ebp-28h]
  __int64 v80;      // [esp+534h] [ebp-24h]
  int v81;          // [esp+53Ch] [ebp-1Ch]

  Com_DPrintf("SV_DirectConnect()\n");
  v1 = (const char *)SV_Cmd_Argv(1);
  I_strncpyz(__dst, v1, 1024);
  v2 = (const char *)Info_ValueForKey(__dst, "protocol");
  v3 = atoi(v2);
    if (v3 != 115) {
      v4 = (const char *)va("error\nEXE_SERVER_IS_DIFFERENT_VER\x15%s\n",
                            (char)"1.0");
      v44 = a1;
      LOWORD(v45) = WORD4(a1);
      NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, v4);
      return Com_DPrintf(
          "    rejected connect from protocol version %i (should be %i)\n", v3,
          115);
    }
  v6 = (const char *)Info_ValueForKey(__dst, "challenge");
  v38 = atoi(v6);
  v7 = (const char *)Info_ValueForKey(__dst, "qport");
  v37 = atoi(v7);
  v8 = dword_170048C;
    if (*(int *)(sv_maxclients + 8) > 0) {
      v9 = 0;
        while (1) {
          LODWORD(v46) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)v8);
          HIDWORD(v46) =
              *(int32_t *)((char *)&v8->netchan.remoteAddress.ip + 2);
          qport = v8->netchan.qport;
          v32.port = qport;
          v48 = a1;
          LOWORD(v49) = WORD4(a1);
          *(_QWORD *)&v32.type = v46;
            if (NET_CompareBaseAdr((netadr_t)a1, v32)) {
              if (v37 == *(_DWORD *)((char *)&loc_6E5D0 + (_DWORD)v8) ||
                  LOWORD(v8->netchan.qport) == WORD4(a1))
                break;
            }
          ++v9;
          v8 = (client_s *)((char *)v8 + 495372);
          if (v9 >= *(_DWORD *)(sv_maxclients + 8))
            goto LABEL_10;
        }
        if ((signed int)(dword_1700484 -
                         *(uint32_t *)((char *)&v8->lastConnectTime + 2)) <
            1000 * *(_DWORD *)(sv_reconnectlimit + 8)) {
          v50 = a1;
          LOWORD(v51) = WORD4(a1);
          v26 = (const char *)NET_AdrToString((netadr_t)a1);
          return Com_DPrintf("%s:reconnect rejected : too soon\n", v26);
        }
    }
LABEL_10:
  v52 = a1;
  LOWORD(v53) = WORD4(a1);
    if (NET_IsLocalAddress((netadr_t)a1)) {
      v36 = 0;
    }
    else {
      v42 = 0;
      v20 = (char *)&svs;
        for (i = 0;; i += 40) {
          v54 = *(_QWORD *)(v20 + 92);
          v55 = *((_DWORD *)v20 + 25);
          v34.port = v55;
          v56 = a1;
          LOWORD(v57) = WORD4(a1);
          *(_QWORD *)&v34.type = v54;
            if (NET_CompareAdr((netadr_t)a1, v34)) {
              if (v38 == *((_DWORD *)v20 + 26))
                break;
            }
          ++v42;
          v20 += 40;
            if (v42 == 1024) {
              v58 = a1;
              LOWORD(v59) = WORD4(a1);
              return NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1,
                                        "error\nEXE_BAD_CHALLENGE");
            }
        }
      v36 = *(_DWORD *)((char *)&svs + i + 128);
      v22 = *(_DWORD *)((char *)&svs + i + 120);
        if (!v22) {
          v22 = dword_1700484 - *(_DWORD *)((char *)&svs + i + 112);
          *(_DWORD *)((char *)&svs + i + 120) = v22;
        }
      v60 = a1;
      LOWORD(v61) = WORD4(a1);
      v23 = (const char *)NET_AdrToString((netadr_t)a1);
      Com_Printf("Client %i connecting with %i challenge ping from %s\n", v42,
                 v22, v23);
      *((_DWORD *)&svs + 10 * v42 + 31) = 1;
      v62 = a1;
      LOWORD(v63) = WORD4(a1);
        if (!Sys_IsLANAddress((netadr_t)a1)) {
          v24 = *(_DWORD *)(sv_minPing + 8);
            if (v24 && v22 < v24) {
              v64 = a1;
              LOWORD(v65) = WORD4(a1);
              NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1,
                                 "error\nEXE_ERR_HIGH_PING_ONLY");
              return Com_DPrintf("Client %i rejected on a too low ping\n", v42);
            }
          v25 = *(_DWORD *)(sv_maxPing + 8);
            if (v25 && v22 > v25) {
              v66 = a1;
              LOWORD(v67) = WORD4(a1);
              NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1,
                                 "error\nEXE_ERR_LOW_PING_ONLY");
              return Com_DPrintf("Client %i rejected on a too high ping: %i\n",
                                 v42, v22);
            }
        }
    }
  v10 = dword_170048C;
    if (*(int *)(sv_maxclients + 8) <= 0) {
    LABEL_20:
      v12 = (const char *)Info_ValueForKey(__dst, "password");
        if (!strcmp(v12, *(const char **)(sv_privatePassword + 8))) {
          v39 = 0;
          v13 = 0;
        }
        else {
          v39 = *(_DWORD *)(sv_privateClients + 8);
          v13 = v39;
        }
      v41 = *(_DWORD *)(sv_maxclients + 8);
        if (v41 > v13) {
          v14 = &dword_170048C->state + 123840 * v13 + 3 * v39;
            if (!*v14) {
              v11 = v39;
            LABEL_27:
              v14[33284] = 0;
        *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)v14) = 0;
        v10 = (client_s *)v14;
        goto LABEL_28;
            }
          v15 = v14 + 123843;
          v16 = v14 + 123843;
          v11 = v39;
            while (v41 != ++v11) {
              v14 = v15;
              v17 = *v16;
              v15 += 123843;
              v16 += 123843;
              if (!v17)
                goto LABEL_27;
            }
        }
      v74 = a1;
      LOWORD(v75) = WORD4(a1);
      NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, "error\nEXE_SERVERISFULL");
      return Com_DPrintf("Rejected a connection.\n");
    }
  v11 = 0;
    while (1) {
        while (!v10->state) {
          ++v11;
          v10 = (client_s *)((char *)v10 + 495372);
          if (*(_DWORD *)(sv_maxclients + 8) <= v11)
            goto LABEL_20;
        }
      LODWORD(v68) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)v10);
      HIDWORD(v68) = *(int32_t *)((char *)&v10->netchan.remoteAddress.ip + 2);
      v69 = v10->netchan.qport;
      v33.port = v69;
      v70 = a1;
      LOWORD(v71) = WORD4(a1);
      *(_QWORD *)&v33.type = v68;
        if (NET_CompareBaseAdr((netadr_t)a1, v33)) {
          if (v37 == *(_DWORD *)((char *)&loc_6E5D0 + (_DWORD)v10) ||
              LOWORD(v10->netchan.qport) == WORD4(a1))
            break;
        }
      ++v11;
      v10 = (client_s *)((char *)v10 + 495372);
      if (*(_DWORD *)(sv_maxclients + 8) <= v11)
        goto LABEL_20;
    }
  v72 = a1;
  LOWORD(v73) = WORD4(a1);
  v31 = (const char *)NET_AdrToString((netadr_t)a1);
  Com_Printf("%s:reconnect\n", v31);
  if (v10->state > 1)
    SV_FreeClient(v10);
LABEL_28:
  memset(v10, 0, 0x78F0Cu);
  v35 = 931767531 * (((char *)v10 - (char *)dword_170048C) >> 2);
  *(int32_t *)((char *)&v10->gentity + 2) = SV_GentityNum(v35);
  LOWORD(v10->bIsTestClient) = Scr_AllocArray();
  *(_DWORD *)((char *)COpenGL::SetColorMaterialEnable + (_DWORD)v10) = v38;
  *(_DWORD *)v10->scriptId = v36;
  v76 = a1;
  LOWORD(v77) = WORD4(a1);
  Netchan_Setup(NS_SERVER,
                (netchan_t *)((char *)&v10->netchan.outgoingSequence + 2),
                (netadr_t)a1, v37);
  *(_DWORD *)v10->muteList = 0;
  HIBYTE(v10[1].state) = 1;
  I_strncpyz(v10->userinfo, __dst, 1024);
  v18 = (const char *)ClientConnect(v35, v10->bIsTestClient);
  v40 = v18;
    if (v18) {
      v19 = (const char *)va("error\n%s", (char)v18);
      v78 = a1;
      LOWORD(v79) = WORD4(a1);
      NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, v19);
      Com_DPrintf("Game rejected a connection: %s.\n", v40);
      return SV_FreeClientScriptId(v10);
    }
  Com_Printf("Going from CS_FREE to CS_CONNECTED for %s (num %i guid %i)\n",
             &v10->name[2], v35, *(_DWORD *)v10->scriptId);
  v10->state = 2;
  *(uint32_t *)((char *)&v10->nextSnapshotTime + 2) = dword_1700484;
  *(uint32_t *)((char *)&v10->lastPacketTime + 2) = dword_1700484;
  *(uint32_t *)((char *)&v10->lastConnectTime + 2) = dword_1700484;
  SV_UserinfoChanged(v10);
  *((_DWORD *)&svs + 10 * v11 + 30) = 0;
  v80 = a1;
  LOWORD(v81) = WORD4(a1);
  NET_OutOfBandPrint(NS_SERVER, (netadr_t)a1, "connectResponse");
  *(_DWORD *)v10->gamestateMessageNum = -1;
  result = sv_maxclients;
  v27 = *(_DWORD *)(sv_maxclients + 8);
    if (v27 > 0) {
      v29 = dword_170048C;
      v30 = 0;
      v28 = 0;
        do {
          result = v28 + 1;
          if (v29->state >= 2)
            ++v28;
          ++v30;
          v29 = (client_s *)((char *)v29 + 495372);
        }
      while (v30 != v27);
      if (v28 == 1)
        return SV_Heartbeat_f();
    }
    else {
      v28 = 0;
    }
  if (v28 == v27)
    return SV_Heartbeat_f();
  return result;
}

void __cdecl SV_FreeClients()
{
  UNIMPLEMENTED();
}

void __cdecl SV_BanClient(struct client_s *cl)
{
  int v2;         // eax
  char __dst[64]; // [esp+1Ch] [ebp-4Ch] BYREF
  int v4[3];      // [esp+5Ch] [ebp-Ch] BYREF

    if (*(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a2) == 2) {
      SV_SendServerCommand(0, SV_CMD_CAN_IGNORE,
                           "%c \"EXE_CANNOTKICKHOSTPLAYER\"", 101);
    }
    else {
      v2 = *(_DWORD *)a2->scriptId;
        if (v2) {
            if (SV_IsBannedGuid(v2)) {
              Com_Printf("This GUID (%i) is already banned\n",
                         *(_DWORD *)a2->scriptId);
            }
            else if (FS_FOpenFileByMode("ban.txt", v4, FS_APPEND) >= 0) {
              I_strncpyz(__dst, &a2->name[2], 64);
              I_CleanStr(__dst);
              FS_Printf(v4[0], "%i %s\r\n", *(_DWORD *)a2->scriptId, __dst);
              FS_FCloseFile(v4[0]);
              SV_DropClient(a1, a2, "EXE_PLAYERKICKED");
              *(uint32_t *)((char *)&a2->lastPacketTime + 2) = dword_1700484;
            }
        }
        else {
          Com_Printf("Can't ban user, GUID is 0\n");
        }
    }
}

void __cdecl SV_ExecuteClientCommand(struct client_s *cl, char const *s,
                                     int clientOK)
{
  const char *v10; // ebx
  char **v11;      // esi
  const char *v12; // eax

  SV_Cmd_TokenizeString(a9);
  v10 = ucmds;
    if (ucmds) {
      v11 = &ucmds;
        while (1) {
          v12 = (const char *)SV_Cmd_Argv(0);
          if (!strcmp(v12, v10))
            break;
          v11 += 2;
          v10 = *v11;
          if (!*v11)
            goto LABEL_5;
        }
      ((void(__cdecl *)(client_s *))v11[1])(a8);
    }
    else {
      v11 = &ucmds;
    }
LABEL_5:
  if (a10 && !*v11 && SV_Loaded())
    ClientCommand(a1, a2, a3, a4, a5, a6, a7,
                  931767531 * (((char *)a8 - (char *)dword_170048C) >> 2));
}

void __cdecl SV_SendClientGameState(struct client_s *client)
{
  unsigned __int8 *Buf; // esi
  int v3;               // esi
  _DWORD *v4;           // ebx
  int v5;               // edi
  char *v6;             // ebx
  entityState_s __b;    // [esp+24h] [ebp-124h] BYREF
  msg_t v8;             // [esp+114h] [ebp-34h] BYREF
  LargeLocal v9;        // [esp+12Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v9, 0x4000);
  Buf = (unsigned __int8 *)LargeLocal::GetBuf(&v9);
  while (a2->state && *(_DWORD *)((char *)&loc_725DC + (_DWORD)a2))
    SV_Netchan_TransmitNextFragment(
        (netchan_t *)((char *)&a2->netchan.outgoingSequence + 2));
  Com_DPrintf("SV_SendClientGameState() for %s\n", &a2->name[2]);
  Com_DPrintf("Going from CS_CONNECTED to CS_PRIMED for %s\n", &a2->name[2]);
  a2->state = 3;
  *(int32_t *)((char *)&a2->pureAuthentic + 2) = 0;
  *(_DWORD *)a2->gamestateMessageNum =
      *(int32_t *)((char *)&a2->netchan.outgoingSequence + 2);
  MSG_Init(&v8, Buf, 0x4000u);
  MSG_WriteLong(&v8, *(_DWORD *)&a2->lastClientCommand[2]);
  SV_UpdateServerCommandsToClient(a2, &v8);
  MSG_WriteByte(&v8, 1);
  MSG_WriteLong(&v8, *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a2));
  v3 = 0;
  v4 = sv;
  do
  {
      while (!*(_BYTE *)v4[262]) {
        ++v3;
        ++v4;
        if (v3 == 2048)
          goto LABEL_9;
      }
    MSG_WriteByte(&v8, 2);
    MSG_WriteShort(&v8, v3);
    MSG_WriteBigString(&v8, (char *)v4[262]);
    ++v3;
    ++v4;
  }
  while ( v3 != 2048 );
LABEL_9:
  memset(&__b, 0, sizeof(__b));
  v5 = 0;
  v6 = (char *)&unk_16A3310;
  do
  {
      while (!*((_DWORD *)v6 + 3)) {
        ++v5;
        v6 += 372;
        if (v5 == 1024)
          goto LABEL_13;
      }
    MSG_WriteByte(&v8, 3);
    MSG_WriteDeltaEntity(&v8, &__b, (entityState_s *)(v6 + 12), (msg_t *)1);
    ++v5;
    v6 += 372;
  }
  while ( v5 != 1024 );
LABEL_13:
  MSG_WriteByte(&v8, 7);
  MSG_WriteLong(&v8, 931767531 * (((char *)a2 - (char *)dword_170048C) >> 2));
  MSG_WriteLong(&v8, sv[3]);
  MSG_WriteByte(&v8, 7);
  Com_DPrintf(
    "Sending %i bytes in gamestate to client: %i\n",
    v8.cursize,
    931767531 * (((char *)a2 - (char *)dword_170048C) >> 2));
  SV_SendMessageToClient(a1, &v8, a2);
  LargeLocal::~LargeLocal(&v9);
}

struct gentity_s *__cdecl SV_AddTestClient()
{
  UNIMPLEMENTED();
}

void __cdecl SV_ClientThink(struct client_s *cl, struct usercmd_s *cmd)
{
  int result; // eax

  a1->lastUsercmd.serverTime = a2->serverTime;
  a1->lastUsercmd.buttons = a2->buttons;
  *(_DWORD *)&a1->lastUsercmd.weapon = *(_DWORD *)&a2->weapon;
  a1->lastUsercmd.angles[0] = a2->angles[0];
  a1->lastUsercmd.angles[1] = a2->angles[1];
  a1->lastUsercmd.angles[2] = a2->angles[2];
  result = *(_DWORD *)&a2->forwardmove;
  *(_DWORD *)&a1->lastUsercmd.forwardmove = result;
    if (a1->state == 4) {
      G_SetLastServerTime(931767531 *
                              (((char *)a1 - (char *)dword_170048C) >> 2),
                          a2->serverTime);
      return ClientThink(931767531 *
                         (((char *)a1 - (char *)dword_170048C) >> 2));
    }
  return result;
}

void __cdecl SV_UserMove(struct client_s *cl, struct msg_t *msg, int delta)
{
  playerState_s *v10; // esi
  usercmd_s *v11;     // eax
  usercmd_s *v12;     // edi
  usercmd_s *v13;     // ebx
  client_s *v14;      // eax
  int v15;            // edi
  _DWORD *v16;        // esi
  int v17;            // edx
  int *v18;           // ebx
  int v19;            // edx
  int v20;            // ebx
  int *v21;           // eax
  int v22;            // [esp+14h] [ebp-3C4h]
  int Byte;           // [esp+18h] [ebp-3C0h]
  int v24;            // [esp+1Ch] [ebp-3BCh]
  int v25;            // [esp+1Ch] [ebp-3BCh]
  _DWORD v26[224];    // [esp+24h] [ebp-3B4h] BYREF
  usercmd_s v27;      // [esp+3A4h] [ebp-34h] BYREF

    if (a10) {
      *(_DWORD *)&a8->deltaMessage[2] = *(_DWORD *)a8->messageAcknowledge;
    if ( *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a8)
       - a8->reliableAcknowledge > 127 )
      return;
    }
    else {
      *(_DWORD *)&a8->deltaMessage[2] = -1;
    if ( *(_DWORD *)((char *)`global constructor keyed to'CMemoryBuffer::sDelayedFreeRequests + (_DWORD)a8)
       - a8->reliableAcknowledge > 127 )
      return;
    }
  Byte = MSG_ReadByte(a9);
    if (Byte <= 0) {
      Com_Printf("cmdCount < 1\n");
      return;
    }
    if (Byte > 32) {
      Com_Printf("cmdCount > MAX_PACKET_USERCMDS\n");
      return;
    }
  v24 = sv[3] ^ *(_DWORD *)a8->messageAcknowledge;
  v25 = Com_HashKey(
            &a8->reliableCommandInfo[1032 * (a8->reliableAcknowledge & 0x7F)],
            32) ^
        v24;
  v10 = (playerState_s *)SV_GameClientNum(
      931767531 * (((char *)a8 - (char *)dword_170048C) >> 2));
  MSG_SetDefaultUserCmd(v10, &v27);
  v11 = &v27;
  v22 = 0;
  v12 = (usercmd_s *)v26;
    do {
      v13 = v12;
      MSG_ReadDeltaUsercmdKey(a9, v25, v11, v12);
      if (!BG_IsWeaponValid(v10, (unsigned __int8)v12->weapon))
        v12->weapon = v10->weapon;
      if (!BG_IsWeaponValid(v10, v12->offHandIndex))
        v12->offHandIndex = v10->offHandIndex;
      ++v22;
      v12 = (usercmd_s *)((char *)v12 + 28);
      v11 = v13;
    }
  while (Byte != v22);
  *(_DWORD *)&a8
       ->frames[9924 * (*(_DWORD *)a8->messageAcknowledge & 0x1F) + 9918] =
      dword_1700484;
    if (a8->state == 3) {
      Com_DPrintf("Going from CS_PRIMED to CS_ACTIVE for %s\n", &a8->name[2]);
      a8->state = 4;
      v20 = 931767531 * (((char *)a8 - (char *)dword_170048C) >> 2);
      v21 = (int *)SV_GentityNum(v20);
      *v21 = v20;
      *(int32_t *)((char *)&a8->gentity + 2) = (int32_t)v21;
      *(_DWORD *)&a8->deltaMessage[2] = -1;
      *(uint32_t *)((char *)&a8->nextSnapshotTime + 2) = dword_1700484;
      a8->lastUsercmd.serverTime = v26[0];
      a8->lastUsercmd.buttons = v26[1];
      *(_DWORD *)&a8->lastUsercmd.weapon = v26[2];
      LODWORD(a8->lastUsercmd.angles[0]) = v26[3];
      LODWORD(a8->lastUsercmd.angles[1]) = v26[4];
      LODWORD(a8->lastUsercmd.angles[2]) = v26[5];
      *(_DWORD *)&a8->lastUsercmd.forwardmove = v26[6];
      ClientBegin(a2.f32[0],
                  931767531 * (((char *)a8 - (char *)dword_170048C) >> 2));
    }
    if (*(_BYTE *)(sv_pure + 8)) {
        if (!*(int32_t *)((char *)&a8->pureAuthentic + 2)) {
          SV_DropClient(a2.f32[0], a8, "EXE_CANNOTVALIDATEPURECLIENT");
          return;
        }
      v14 = a8;
    }
    else {
      v14 = a8;
    }
    if (v14->state == 4) {
      v15 = 0;
      v16 = v26;
      v17 = 7 * (Byte - 1);
      v18 = v26;
        while (1) {
            if (*v16 <= v26[v17] &&
                *v16 > (signed int)a8->lastUsercmd.serverTime) {
              v19 = *v18;
              a8->lastUsercmd.serverTime = *v18;
              a8->lastUsercmd.buttons = v18[1];
              *(_DWORD *)&a8->lastUsercmd.weapon = v18[2];
              LODWORD(a8->lastUsercmd.angles[0]) = v18[3];
              LODWORD(a8->lastUsercmd.angles[1]) = v18[4];
              LODWORD(a8->lastUsercmd.angles[2]) = v18[5];
              *(_DWORD *)&a8->lastUsercmd.forwardmove = v18[6];
                if (a8->state == 4) {
                  G_SetLastServerTime(
                      931767531 * (((char *)a8 - (char *)dword_170048C) >> 2),
                      v19);
                  ClientThink(a1, a2, a3, a4, a5, a6, a7,
                              931767531 *
                                  (((char *)a8 - (char *)dword_170048C) >> 2));
                }
            }
          ++v15;
          v18 += 7;
          v16 += 7;
          if (Byte == v15)
            break;
          v17 = 7 * (Byte - 1);
        }
    }
    else {
      *(_DWORD *)&v14->deltaMessage[2] = -1;
    }
}

void __cdecl SV_ExecuteClientMessage(struct client_s *cl, struct msg_t *msg)
{
  int v9;                     // esi
  int v10;                    // ebx
  char *v11;                  // esi
  int v12;                    // edx
  _BOOL4 v13;                 // edx
  int v14;                    // edx
  int v15;                    // ebx
  const char *v16;            // eax
  int v17;                    // ebx
  int *v18;                   // eax
  netadr_t v19;               // [esp+0h] [ebp-4058h]
  netadr_t v20;               // [esp+0h] [ebp-4058h]
  unsigned __int8 v21[16384]; // [esp+10h] [ebp-4048h] BYREF
  msg_t v22;                  // [esp+4010h] [ebp-48h] BYREF
  __int64 v23;                // [esp+4028h] [ebp-30h]
  int32_t v24;                // [esp+4030h] [ebp-28h]
  __int64 v25;                // [esp+4034h] [ebp-24h]
  int32_t qport;              // [esp+403Ch] [ebp-1Ch]

  MSG_Init(&v22, v21, 0x4000u);
  v22.cursize =
      MSG_ReadBitsCompress((unsigned __int8 *)(a9->data + a9->readcount), v21,
                           a9->cursize - a9->readcount);
    if (*(_DWORD *)a8->voicePackets == sv_serverId_value ||
        *((_BYTE *)&loc_20C68 + (_DWORD)a8)) {
        while (1) {
          v9 = MSG_ReadBits(&v22, 3);
            if (v9 != 2) {
                if (*(_BYTE *)(sv_pure + 8) &&
                    *(int32_t *)((char *)&a8->pureAuthentic + 2) == 2) {
                  *(uint32_t *)((char *)&a8->nextSnapshotTime + 2) = -1;
                  SV_DropClient(a2.f32[0], a8, "EXE_UNPURECLIENTDETECTED");
                  a8->state = 4;
                  SV_SendClientSnapshot(a2.f32[0], a8);
                  a8->state = 1;
                }
                if (v9) {
                    if (v9 == 1) {
                      SV_UserMove(a1, a2, a3, a4, a5, a6, a7, a8, &v22, 0);
                    }
                    else if (v9 != 3) {
                      Com_Printf(
                          "WARNING: bad command byte %i for client %i\n", v9,
                          931767531 *
                              (((char *)a8 - (char *)dword_170048C) >> 2));
                    }
                }
                else {
                  SV_UserMove(a1, a2, a3, a4, a5, a6, a7, a8, &v22, 1);
                }
              return;
            }
          v10 = MSG_ReadLong(&v22);
          v11 = MSG_ReadString(&v22);
          if (v10 > *(_DWORD *)&a8->lastClientCommand[2])
            break;
        LABEL_16:
          if (a8->state == 1)
            return;
        }
      if (*(_BYTE *)(sv_showCommands + 8))
        Com_Printf("clientCommand: %i : %s\n", v10, v11);
      v12 = *(_DWORD *)&a8->lastClientCommand[2];
        if (v10 > v12 + 1) {
          Com_Printf("Client %s lost %i clientCommands\n", &a8->name[2],
                     v10 - v12 + 1);
          SV_DropClient(a2.f32[0], a8, "EXE_LOSTRELIABLECOMMANDS");
          return;
        }
      v13 = I_strncmp("team ", v11, 5) && I_strncmp("score ", v11, 6) &&
            I_strncmp("mr ", v11, 3);
        if (*(_DWORD *)(legacyHacks + 4) || a8->state <= 3 ||
            !*(_BYTE *)(sv_floodProtect + 8) ||
            dword_1700484 >=
                *(signed int *)((char *)&a8->nextReliableTime + 2)) {
            if (v13) {
              v14 = 1;
              goto LABEL_29;
            }
        }
        else if (v13) {
          v16 = (const char *)SV_Cmd_Argv(0);
          Com_DPrintf("client text ignored for %s: %s\n", &a8->name[2], v16);
          v14 = 0;
        LABEL_29:
          *(uint32_t *)((char *)&a8->nextReliableTime + 2) =
              dword_1700484 + 800;
          goto LABEL_15;
        }
      v14 = 1;
    LABEL_15:
      SV_ExecuteClientCommand(a1, a2.f32[0], a3, a4, a5, a6, a7, a8, v11, v14);
      *(_DWORD *)&a8->lastClientCommand[2] = v10;
      Com_sprintf(&a8->lastClientCommandString[2], 0x400u, "%s", v11);
      goto LABEL_16;
    }
    if ((*(_DWORD *)a8->voicePackets & 0xF0) == (sv_serverId_value & 0xF0)) {
        if (a8->state == 3) {
          Com_DPrintf("Going from CS_PRIMED to CS_ACTIVE for %s\n",
                      &a8->name[2]);
          a8->state = 4;
          v17 = 931767531 * (((char *)a8 - (char *)dword_170048C) >> 2);
          v18 = (int *)SV_GentityNum(v17);
          *v18 = v17;
          *(int32_t *)((char *)&a8->gentity + 2) = (int32_t)v18;
          *(_DWORD *)&a8->deltaMessage[2] = -1;
          *(uint32_t *)((char *)&a8->nextSnapshotTime + 2) = dword_1700484;
          ClientBegin(a2.f32[0],
                      931767531 * (((char *)a8 - (char *)dword_170048C) >> 2));
        }
    }
    else if (*(_DWORD *)a8->messageAcknowledge >
             *(_DWORD *)a8->gamestateMessageNum) {
      Com_DPrintf("%s : dropped gamestate, resending\n", &a8->name[2]);
      SV_SendClientGameState(a2.f32[0], a8);
        if (*(_BYTE *)(net_lanauthorize + 8) ||
            (LODWORD(v23) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a8),
             HIDWORD(v23) =
                 *(int32_t *)((char *)&a8->netchan.remoteAddress.ip + 2),
             v24 = a8->netchan.qport, *(_QWORD *)&v19.type = v23,
             v19.port = v24, !Sys_IsLANAddress(v19))) {
          v15 =
              *(_DWORD *)((char *)COpenGL::SetColorMaterialEnable + (_DWORD)a8);
          LODWORD(v25) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a8);
          HIDWORD(v25) =
              *(int32_t *)((char *)&a8->netchan.remoteAddress.ip + 2);
          qport = a8->netchan.qport;
          *(_QWORD *)&v20.type = v25;
          v20.port = qport;
          SV_AuthorizeRequest(v20, v15);
        }
    }
}

int __cdecl SV_FindFreeTempBanSlot(void)
{
  UNIMPLEMENTED();
}

int __cdecl SV_IsBannedGuid(int)
{
  UNIMPLEMENTED();
}

void __cdecl SV_UnmutePlayer_f(struct client_s *)
{
  const char *v1;  // eax
  unsigned int v2; // eax

  v1 = (const char *)SV_Cmd_Argv(1);
  v2 = atoi(v1);
  if (v2 > 0x40)
    Com_Printf("Invalid unmute client %i\n", v2);
  else
    a1->muteList[v2 + 4] = 0;
}

void __cdecl SV_MutePlayer_f(struct client_s *)
{
  const char *v1;  // eax
  unsigned int v2; // eax

  v1 = (const char *)SV_Cmd_Argv(1);
  v2 = atoi(v1);
  if (v2 > 0x40)
    Com_Printf("Invalid mute client %i\n", v2);
  else
    a1->muteList[v2 + 4] = 1;
}

void __cdecl SV_UpdateUserinfo_f(struct client_s *)
{
  UNIMPLEMENTED();
}

void __cdecl SV_Disconnect_f(struct client_s *)
{
  UNIMPLEMENTED();
}

int __cdecl SV_ClientCommand(struct client_s *, struct msg_t *)
{
  UNIMPLEMENTED();
}

SV_AuthorizeRequest(netadr_t from, int challenge)
{
  UNIMPLEMENTED();
}

SV_AuthorizeIpPacket(netadr_t from)
{
  UNIMPLEMENTED();
}

SV_DoneDownload_f(client_s *cl)
{
  UNIMPLEMENTED();
}

SV_RetransmitDownload_f(client_s *cl)
{
  UNIMPLEMENTED();
}

SV_WriteDownloadToClient(client_s *cl, msg_t *msg)
{
  UNIMPLEMENTED();
}

SV_StopDownload_f(client_s *cl)
{
  UNIMPLEMENTED();
}

SV_NextDownload_f(client_s *cl)
{
  UNIMPLEMENTED();
}

SV_BeginDownload_f(client_s *cl)
{
  UNIMPLEMENTED();
}
