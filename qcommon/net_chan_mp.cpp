void __cdecl XUIDToString(unsigned __int64 const *, char *) { UNIMPLEMENTED(); }

void __cdecl StringToXUID(char const *, unsigned __int64 *) { UNIMPLEMENTED(); }

void __cdecl StringToXNAddr(char const *, struct XNADDR *) { UNIMPLEMENTED(); }

void __cdecl XNAddrToString(struct XNADDR const *, char *) { UNIMPLEMENTED(); }

void __cdecl StringToInt128(char const *, unsigned char *) { UNIMPLEMENTED(); }

__int64 __cdecl StringToInt64(char const *) { UNIMPLEMENTED(); }

void __cdecl Int128ToString(unsigned char *, char *) { UNIMPLEMENTED(); }

void __cdecl Int64ToString(__int64, char *) { UNIMPLEMENTED(); }

void __cdecl NET_SendLoopPacket(enum netsrc_t, int, void const *,
                                struct netadr_t) {
  UNIMPLEMENTED();
}

int __cdecl NET_GetLoopPacket_Real(enum netsrc_t, struct netadr_t *,
                                   struct msg_t *) {
  UNIMPLEMENTED();
}

int __cdecl NET_IsLocalAddress(struct netadr_t adr) {
  return a1.type == 2 || !a1.type;
}

int __cdecl NET_CompareXNAddr(struct XNADDR *, struct XNADDR *) {
  UNIMPLEMENTED();
}

void __cdecl NetProf_PrepProfiling(struct netProfileInfo_t **pProf) {
  int v1;               // edx
  void *v2;             // eax
  netProfileInfo_t *v3; // eax

  v1 = *(_DWORD *)(net_profile + 8);
  if (!v1) {
    if (net_iProfilingOn) {
      net_iProfilingOn = 0;
      Com_Printf("Net Profiling turned off\n");
      v2 = *a1;
      if (!*a1)
        return;
    } else {
      v2 = *a1;
      if (!*a1)
        return;
    }
    free(v2);
    *a1 = 0;
    return;
  }
  if (net_iProfilingOn) {
    if (*a1)
      return;
  LABEL_17:
    v3 = (netProfileInfo_t *)malloc(0x5E0u);
    *a1 = v3;
    memset(v3, 0, sizeof(netProfileInfo_t));
    return;
  }
  if (!*(_BYTE *)(com_sv_running + 8) ||
      *(_DWORD *)(legacyHacks + 4) && v1 == 2)
    net_iProfilingOn = 1;
  else
    net_iProfilingOn = 2;
  Com_Printf("Net Profiling turned on: %s\n",
             (const char *)g_qport[net_iProfilingOn]);
  if (!*a1)
    goto LABEL_17;
}

char const *__cdecl NET_AdrToString(struct netadr_t a) {
  if ((_DWORD)a1 == 2) {
    Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "loopback");
    return NET_AdrToString(netadr_t)::s;
  } else {
    if ((_DWORD)a1 == 4)
      Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "%i.%i.%i.%i:%i",
                  BYTE4(a1), BYTE5(a1), BYTE6(a1), BYTE7(a1),
                  (__int16)__ROL2__(WORD4(a1), 8));
    return NET_AdrToString(netadr_t)::s;
  }
}

int __cdecl NET_GetLoopPacket(enum netsrc_t sock, struct netadr_t *net_from,
                              struct msg_t *net_message) {
  char *v3;   // esi
  int v4;     // edx
  int v5;     // ecx
  size_t *v7; // ebx

  v3 = (char *)&loopbacks + 22536 * a1;
  v4 = *((_DWORD *)v3 + 5633);
  v5 = *((_DWORD *)v3 + 5632);
  if (v4 - v5 > 16) {
    v5 = v4 - 16;
    *((_DWORD *)v3 + 5632) = v4 - 16;
  }
  if (v5 >= *((_DWORD *)v3 + 5633))
    return 0;
  *((_DWORD *)v3 + 5632) = v5 + 1;
  v7 = (size_t *)&v3[1408 * (v5 & 0xF)];
  memcpy((void *)a3->data, v7, v7[350]);
  a3->cursize = v7[350];
  a2->ip = 0;
  *(_DWORD *)&a2->port = 0;
  a2->type = 2;
  a2->port = v7[351];
  return 1;
}

void __cdecl Netchan_Setup(enum netsrc_t sock, struct netchan_t *chan,
                           struct netadr_t adr, int qport) {
  memset(__b, 0, 0x8038u);
  __b->sock = a1;
  __b->remoteAddress = a3;
  *(int32_t *)((char *)&__b->qport + 2) = a4;
  __b->incomingSequence = 0;
  __b->outgoingSequence = 1;
  NetProf_PrepProfiling((netProfileInfo_t **)((char *)&__b->pProf + 2));
}

void __cdecl NetProf_UpdateStatistics(struct netProfileStream_t *pStream) {
  netProfileStream_t *v1; // ebx
  int32_t v2;             // edi
  int i;                  // esi
  int32_t v4;             // eax
  int32_t v5;             // edx
  signed int result;      // eax
  int v7;                 // ebx
  int v8;                 // ebx
  int v9;                 // edx
  char *v10;              // eax
  signed int v11;         // [esp+8h] [ebp-30h]
  uint32_t v12;           // [esp+Ch] [ebp-2Ch]
  int v13;                // [esp+10h] [ebp-28h]
  int v14;                // [esp+14h] [ebp-24h]
  int32_t v15;            // [esp+18h] [ebp-20h]
  int v16;                // [esp+1Ch] [ebp-1Ch]

  v16 = Sys_Milliseconds();
  v1 = a1;
  v11 = 0;
  v12 = 0;
  v13 = -1;
  v14 = 0;
  v15 = 9999;
  v2 = 0;
  for (i = 0; i != 60; ++i) {
    while (!*(_DWORD *)v1->packets ||
           Sys_Milliseconds() > *(_DWORD *)v1->packets + 1000) {
      ++i;
      v1 = (netProfileStream_t *)((char *)v1 + 12);
      if (i == 60)
        goto LABEL_12;
    }
    ++v11;
    v12 -= (*(_DWORD *)&v1->packets[8] == 0) - 1;
    if (*(_DWORD *)v1->packets < v16) {
      v13 = i;
      v16 = *(_DWORD *)v1->packets;
    }
    v4 = *(_DWORD *)&v1->packets[4];
    v14 += v4;
    v5 = v15;
    if (v4 < v15)
      v5 = *(_DWORD *)&v1->packets[4];
    v15 = v5;
    if (v4 > v2)
      v2 = *(_DWORD *)&v1->packets[4];
    v1 = (netProfileStream_t *)((char *)v1 + 12);
  }
LABEL_12:
  result = v11;
  if (!v11) {
    a1->iBytesPerSecond = 0;
    a1->iLastBPSCalcTime = 0;
    a1->iCountedPackets = 0;
    a1->iCountedFragments = 0;
    a1->iFragmentPercentage = 0;
    a1->iLargestPacket = 0;
    a1->iSmallestPacket = 0;
    return result;
  }
  if (!v12) {
    a1->iFragmentPercentage = 0;
    a1->iLargestPacket = v2;
    a1->iSmallestPacket = v15;
    v8 = a1->iLastBPSCalcTime + 100;
    if (v8 >= Sys_Milliseconds())
      goto LABEL_16;
  LABEL_18:
    v9 = Sys_Milliseconds() - v16;
    if (v13 != -1) {
      v10 = (char *)a1 + 12 * v13;
      v14 -= *((_DWORD *)v10 + 1);
      --v11;
      v12 = (*((_DWORD *)v10 + 2) == 0) + v12 - 1;
    }
    if (v9 > 0 && v11) {
      if (v14)
        a1->iBytesPerSecond =
            (int)(float)((float)v14 / (float)((float)v9 * 0.001));
      else
        a1->iBytesPerSecond = 0;
      a1->iLastBPSCalcTime = Sys_Milliseconds();
    } else {
      a1->iBytesPerSecond = 0;
    }
    goto LABEL_16;
  }
  a1->iFragmentPercentage = (int)(100 * v12) / v11;
  a1->iLargestPacket = v2;
  a1->iSmallestPacket = v15;
  v7 = a1->iLastBPSCalcTime + 100;
  if (v7 < Sys_Milliseconds())
    goto LABEL_18;
LABEL_16:
  result = v11;
  a1->iCountedPackets = v11;
  a1->iCountedFragments = v12;
  return result;
}

void __cdecl NetProf_AddPacket(struct netProfileStream_t *, int, int) {
  int v3;     // ecx
  int *v4;    // ebx
  int result; // eax

  v3 = a1->iCurrPacket + 1;
  a1->iCurrPacket = v3 % 60;
  v4 = (int *)((char *)a1 + 12 * (v3 % 60));
  *v4 = Sys_Milliseconds();
  v4[1] = a2;
  result = a3;
  v4[2] = a3;
  return result;
}

int __cdecl NET_StringToAdr(char const *s, struct netadr_t *a) {
  int result;     // eax
  char *v3;       // eax
  const char *v4; // esi
  char __s[1048]; // [esp+10h] [ebp-418h] BYREF

  if (!strcmp(__src, "localhost")) {
    a2->ip = 0;
    *(_DWORD *)&a2->port = 0;
    a2->type = 2;
    return 1;
  } else {
    I_strncpyz(__s, __src, 1024);
    v3 = strchr(__s, 58);
    v4 = v3;
    if (v3) {
      *v3 = 0;
      v4 = v3 + 1;
    }
    result = (int)Sys_StringToAdr(__s, a2);
    if (result) {
      if (a2->ip == -1) {
        a2->type = 1;
        return 0;
      } else {
        if (v4)
          a2->port = __ROL2__(atoi(v4), 8);
        else
          a2->port = 8305;
        return 1;
      }
    } else {
      a2->type = 1;
    }
  }
  return result;
}

void __cdecl NetProf_NewSendPacket(struct netchan_t *, int, int) {
  UNIMPLEMENTED();
}

int __cdecl NET_GetPacket(struct netadr_t *net_from,
                          struct msg_t *net_message) {
  return Sys_GetPacket(a1, a2);
}

bool __cdecl NET_SendPacket(enum netsrc_t sock, int length, void const *data,
                            struct netadr_t to) {
  netsrc_t port; // eax
  netsrc_t v6;   // esi
  char *v7;      // ebx
  int v8;        // edx
  char *v9;      // ebx

  if (*(_BYTE *)(showpackets + 8) && *__src == -1)
    Com_Printf("[client %i] send packet %4i\n", 0, __n);
  if (a4.type == 2) {
    port = a1;
    if (a1 <= NS_CLIENT1) {
      v6 = a1;
      port = NS_SERVER;
    } else {
      if (a1 == NS_SERVER)
        port = a4.port;
      v6 = NS_CLIENT1;
    }
    v7 = (char *)&loopbacks + 22536 * port;
    v8 = (*((_DWORD *)v7 + 5633))++ & 0xF;
    v9 = &v7[1408 * v8];
    memcpy(v9, __src, __n);
    *((_DWORD *)v9 + 350) = __n;
    *((_DWORD *)v9 + 351) = v6;
    return 1;
  } else if (a4.type > 1u) {
    return (unsigned __int8)Sys_SendPacket(__n, __src, a4);
  } else {
    return 0;
  }
}

bool __cdecl Netchan_TransmitNextFragment(struct netchan_t *chan) {
  int v1;                    // edx
  int v2;                    // ecx
  int32_t v3;                // eax
  int v5;                    // esi
  int v6;                    // ecx
  int *v7;                   // ebx
  netadr_t v8;               // [esp+Ch] [ebp-5DCh]
  size_t __n;                // [esp+24h] [ebp-5C4h]
  int v10;                   // [esp+28h] [ebp-5C0h]
  uint32_t cursize;          // [esp+2Ch] [ebp-5BCh]
  unsigned __int8 v12[1400]; // [esp+34h] [ebp-5B4h] BYREF
  msg_t v13;                 // [esp+5ACh] [ebp-3Ch] BYREF
  __int64 v14;               // [esp+5C4h] [ebp-24h]
  int v15;                   // [esp+5CCh] [ebp-1Ch]

  NetProf_PrepProfiling((netProfileInfo_t **)((char *)&a1->pProf + 2));
  MSG_Init(&v13, v12, 0x578u);
  MSG_WriteLong(&v13, a1->outgoingSequence | 0x80000000);
  if (a1->sock <= 0)
    MSG_WriteShort(&v13, *(int32_t *)((char *)&a1->qport + 2));
  v1 = *(int32_t *)((char *)&a1->unsentFragmentStart + 2);
  v2 = *(uint32_t *)((char *)&a1->unsentLength + 2);
  if (v1 + 1300 > v2)
    __n = v2 - v1;
  else
    __n = 1300;
  MSG_WriteShort(&v13, v1);
  MSG_WriteShort(&v13, __n);
  MSG_WriteData(
      &v13,
      &a1->unsentBuffer[*(int32_t *)((char *)&a1->unsentFragmentStart + 2) + 2],
      __n);
  v14 = *(_QWORD *)&a1->remoteAddress.type;
  v15 = *(_DWORD *)&a1->remoteAddress.port;
  *(_QWORD *)&v8.type = v14;
  v8.port = v15;
  v10 = (unsigned __int8)NET_SendPacket((netsrc_t)a1->sock, v13.cursize,
                                        (_DWORD *)v13.data, v8);
  cursize = v13.cursize;
  if (net_iProfilingOn) {
    v5 = *(int32_t *)((char *)&a1->pProf + 2);
    v6 = *(_DWORD *)(v5 + 720) + 1;
    *(_DWORD *)(v5 + 720) = v6 % 60;
    v7 = (int *)(v5 + 12 * (v6 % 60));
    *v7 = Sys_Milliseconds();
    v7[1] = cursize;
    v7[2] = 1;
    if ((*(_BYTE *)(net_showprofile + 8) & 2) != 0)
      Com_Printf("%s send%s: %i\n", netsrcString[a1->sock], " fragment",
                 cursize);
  }
  if (*(_BYTE *)(showpackets + 8))
    Com_Printf("[client %i] %s send %4i : s=%i fragment=%i,%i\n", 0,
               netsrcString[a1->sock], v13.cursize, a1->outgoingSequence - 1,
               *(int32_t *)((char *)&a1->unsentFragmentStart + 2), __n);
  v3 = *(int32_t *)((char *)&a1->unsentFragmentStart + 2) + __n;
  *(int32_t *)((char *)&a1->unsentFragmentStart + 2) = v3;
  if (v3 != *(uint32_t *)((char *)&a1->unsentLength + 2) || __n == 1300)
    return v10 > 0;
  ++a1->outgoingSequence;
  *(int32_t *)((char *)&a1->unsentFragments + 2) = 0;
  return v10 > 0;
}

bool __cdecl NET_OutOfBandData(enum netsrc_t sock, struct netadr_t adr,
                               unsigned char *format, int len) {
  uint32_t Buf;   // eax
  uint32_t v5;    // edx
  int i;          // ecx
  int v7;         // esi
  int v8;         // ebx
  LargeLocal v10; // [esp+4Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v10, 0x4000);
  Buf = LargeLocal::GetBuf(&v10);
  *(_BYTE *)Buf = -1;
  *(_BYTE *)(Buf + 1) = -1;
  *(_BYTE *)(Buf + 2) = -1;
  *(_BYTE *)(Buf + 3) = -1;
  if (a4 > 0) {
    v5 = Buf;
    for (i = 0; i != a4; ++i) {
      *(_BYTE *)(v5 + 4) = a3[i];
      ++v5;
    }
  }
  v7 = a4 + 4;
  v8 = (unsigned __int8)NET_SendPacket(a1, a4 + 4, (_DWORD *)Buf, a2);
  if (a1 == NS_SERVER)
    SV_Netchan_AddOOBProfilePacket(v7);
  else
    CL_Netchan_AddOOBProfilePacket(v7);
  LargeLocal::~LargeLocal(&v10);
  return v8 > 0;
}

bool __cdecl NET_OutOfBandPrint(enum netsrc_t sock, struct netadr_t adr,
                                char const *data) {
  uint32_t Buf;    // ebx
  size_t v4;       // ecx
  unsigned int v6; // esi
  int v7;          // ebx
  LargeLocal v8;   // [esp+3Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v8, 0x4000);
  Buf = LargeLocal::GetBuf(&v8);
  *(_BYTE *)Buf = -1;
  *(_BYTE *)(Buf + 1) = -1;
  *(_BYTE *)(Buf + 2) = -1;
  *(_BYTE *)(Buf + 3) = -1;
  if (*(_BYTE *)(showpackets + 8))
    Com_DPrintf("OOB Print: %s\n", __src);
  v4 = strlen(__src) + 1;
  if (v4 <= 0x3FFC) {
    memcpy((void *)(Buf + 4), __src, v4);
    v6 = strlen((const char *)Buf);
    v7 = (unsigned __int8)NET_SendPacket(a1, v6, (_DWORD *)Buf, a2);
    if (a1 == NS_SERVER)
      SV_Netchan_AddOOBProfilePacket(v6);
    else
      CL_Netchan_AddOOBProfilePacket(v6);
    LargeLocal::~LargeLocal(&v8);
    return v7 > 0;
  } else {
    Com_DPrintf("OOB Packet is %i bytes - too large to send\n", v4 - 1);
    LargeLocal::~LargeLocal(&v8);
    return 0;
  }
}

bool __cdecl Netchan_Transmit(struct netchan_t *chan, int length,
                              unsigned char const *data) {
  int v4;                    // esi
  int v5;                    // ecx
  int *v6;                   // ebx
  netadr_t v7;               // [esp+Ch] [ebp-5DCh]
  int v8;                    // [esp+28h] [ebp-5C0h]
  uint32_t cursize;          // [esp+2Ch] [ebp-5BCh]
  unsigned __int8 v10[1400]; // [esp+34h] [ebp-5B4h] BYREF
  msg_t v11;                 // [esp+5ACh] [ebp-3Ch] BYREF
  __int64 v12;               // [esp+5C4h] [ebp-24h]
  int v13;                   // [esp+5CCh] [ebp-1Ch]

  if (__n > 0x4000)
    Com_Error(1, "\x15Netchan_Transmit: length = %i", __n);
  *(int32_t *)((char *)&a1->unsentFragmentStart + 2) = 0;
  if (__n > 1299) {
    *(int32_t *)((char *)&a1->unsentFragments + 2) = 1;
    *(uint32_t *)((char *)&a1->unsentLength + 2) = __n;
    Com_Memcpy(&a1->unsentBuffer[2], __src, __n);
    Netchan_TransmitNextFragment(a1);
    return 1;
  }
  NetProf_PrepProfiling((netProfileInfo_t **)((char *)&a1->pProf + 2));
  MSG_Init(&v11, v10, 0x578u);
  MSG_WriteLong(&v11, a1->outgoingSequence);
  ++a1->outgoingSequence;
  if (a1->sock <= 0)
    MSG_WriteShort(&v11, *(int32_t *)((char *)&a1->qport + 2));
  if (*(_BYTE *)(packetDebug + 8)) {
    Com_Printf("Adding %i byte payload to packet\n", __n);
    MSG_WriteData(&v11, __src, __n);
    if (!*(_BYTE *)(packetDebug + 8))
      goto LABEL_9;
  } else {
    MSG_WriteData(&v11, __src, __n);
    if (!*(_BYTE *)(packetDebug + 8))
      goto LABEL_9;
  }
  Com_Printf("Sending %i byte packet\n", v11.cursize);
LABEL_9:
  v12 = *(_QWORD *)&a1->remoteAddress.type;
  v13 = *(_DWORD *)&a1->remoteAddress.port;
  *(_QWORD *)&v7.type = v12;
  v7.port = v13;
  v8 = (unsigned __int8)NET_SendPacket((netsrc_t)a1->sock, v11.cursize,
                                       (_DWORD *)v11.data, v7);
  cursize = v11.cursize;
  if (net_iProfilingOn) {
    v4 = *(int32_t *)((char *)&a1->pProf + 2);
    v5 = *(_DWORD *)(v4 + 720) + 1;
    *(_DWORD *)(v4 + 720) = v5 % 60;
    v6 = (int *)(v4 + 12 * (v5 % 60));
    *v6 = Sys_Milliseconds();
    v6[1] = cursize;
    v6[2] = 0;
    if ((*(_BYTE *)(net_showprofile + 8) & 2) != 0)
      Com_Printf("%s send%s: %i\n", netsrcString[a1->sock],
                 (const char *)&inData, cursize);
  }
  if (*(_BYTE *)(showpackets + 8))
    Com_Printf("[client %i] %s send %4i : s=%i ack=%i\n", 1,
               netsrcString[a1->sock], v11.cursize, a1->outgoingSequence - 1,
               a1->incomingSequence);
  return v8 > 0;
}

bool __cdecl NET_SendVoiceDataPackets(enum netsrc_t, int, void const *, int,
                                      void const *, struct netadr_t) {
  UNIMPLEMENTED();
}

int __cdecl NET_CompareAdrSigned(struct netadr_t *a, struct netadr_t *b) {
  int32_t type;  // eax
  uint16_t port; // dx
  uint16_t v5;   // ax

  type = a1->type;
  if (a1->type != a2->type)
    return type - a2->type;
  if (type == 2)
    return 0;
  if (type != 4) {
    Com_Printf("NET_CompareAdrSigned: bad address type\n");
    return 0;
  }
  port = a1->port;
  v5 = a2->port;
  if (port == v5)
    return memcmp((const char *)&a1->ip, (const char *)&a2->ip, 4);
  else
    return port - v5;
}

int __cdecl NET_CompareBaseAdrSigned(struct netadr_t *, struct netadr_t *) {
  UNIMPLEMENTED();
}

void __cdecl Net_DisplayProfile() {
  if (net_iProfilingOn) {
    if (net_iProfilingOn == 1)
      CL_Netchan_PrintProfileStats(a1, 0);
    else
      SV_Netchan_PrintProfileStats(a1, a2, a3, 0);
  }
}

void __cdecl Net_DumpProfile_f() {
  if (net_iProfilingOn) {
    if (net_iProfilingOn == 1)
      CL_Netchan_PrintProfileStats(a1, 1);
    else
      SV_Netchan_PrintProfileStats(a1, a2, a3, 1);
  } else {
    Com_Printf("Network profiling is not on. Set net_profile to turn on "
               "network profiling\n");
  }
}

void __cdecl NetProf_NewRecievePacket(struct netchan_t *, int, int) {
  UNIMPLEMENTED();
}

void __cdecl NET_OutOfBandVoiceData(enum netsrc_t sock, struct netadr_t adr,
                                    unsigned char *format, int len) {
  int v4;             // ebx
  int v6;             // [esp+34h] [ebp-8024h] BYREF
  _BYTE __dst[32764]; // [esp+38h] [ebp-8020h] BYREF
  int32_t type;       // [esp+8034h] [ebp-24h]
  int32_t ip;         // [esp+8038h] [ebp-20h]
  int v10;            // [esp+803Ch] [ebp-1Ch]

  v6 = -1;
  memcpy(__dst, __src, __n);
  v4 = __n + 4;
  LOWORD(v10) = a2.port;
  ip = a2.ip;
  type = a2.type;
  NET_SendPacket(a1, __n + 4, &v6, a2);
  if (a1 == NS_SERVER)
    return SV_Netchan_AddOOBProfilePacket(v4);
  else
    return CL_Netchan_AddOOBProfilePacket(v4);
}

int __cdecl NET_CompareAdr(struct netadr_t a, struct netadr_t b) {
  int v3; // [esp+3Ch] [ebp-2Ch]

  if (a1.type != a2.type) {
    v3 = a1.type - a2.type;
    return v3 == 0;
  }
  if (a1.type == 2)
    return 1;
  if (a1.type != 4) {
    Com_Printf("NET_CompareAdrSigned: bad address type\n");
    return 1;
  }
  if (a1.port == a2.port) {
    v3 = memcmp((const char *)&a1.ip, (const char *)&a2.ip, 4);
    return v3 == 0;
  }
  return a1.port == a2.port;
}

int __cdecl NET_CompareBaseAdr(struct netadr_t a, struct netadr_t b) {
  int32_t type; // edx
  int32_t port; // eax
  int v5;       // [esp+3Ch] [ebp-2Ch]

  type = a1.type;
  port = a2.type;
  if (a1.type != a2.type)
    goto LABEL_2;
  switch (a1.type) {
  case 2:
    v5 = a1.port - a2.port;
    return v5 == 0;
  case 0:
    type = a1.port;
    port = a2.port;
  LABEL_2:
    v5 = type - port;
    return v5 == 0;
  case 4:
    v5 = memcmp((const char *)&a1.ip, (const char *)&a2.ip, 4);
    break;
  default:
    Com_Printf("NET_CompareBaseAdrSigned: bad address type\n");
    v5 = 0;
    break;
  }
  return v5 == 0;
}

int __cdecl Netchan_Process(struct netchan_t *chan, struct msg_t *msg) {
  int32_t incomingSequence; // ebx
  int32_t v3;               // eax
  int32_t v5;               // ebx
  int32_t type;             // edx
  int32_t v7;               // eax
  int v8;                   // esi
  int v9;                   // ecx
  int *v10;                 // ebx
  const char *v11;          // edx
  uint32_t readcount;       // edx
  signed int v13;           // ebx
  int32_t v14;              // eax
  int32_t v15;              // eax
  int32_t Long;             // [esp+24h] [ebp-34h]
  int Short;                // [esp+28h] [ebp-30h]
  int __n;                  // [esp+2Ch] [ebp-2Ch]
  int v19;                  // [esp+30h] [ebp-28h]
  uint32_t cursize;         // [esp+34h] [ebp-24h]

  NetProf_PrepProfiling((netProfileInfo_t **)((char *)&a1->pProf + 2));
  MSG_BeginReading(a2);
  Long = MSG_ReadLong(a2);
  if (Long < 0) {
    Long &= ~0x80000000;
    v19 = 1;
    if (a1->sock != 1)
      goto LABEL_3;
  } else {
    v19 = 0;
    if (a1->sock != 1)
      goto LABEL_3;
  }
  MSG_ReadShort(a2);
LABEL_3:
  if (v19) {
    Short = MSG_ReadShort(a2);
    __n = MSG_ReadShort(a2);
  } else {
    Short = 0;
    __n = 0;
  }
  cursize = a2->cursize;
  if (net_iProfilingOn) {
    v8 = *(int32_t *)((char *)&a1->pProf + 2) + 752;
    v9 = *(_DWORD *)(*(int32_t *)((char *)&a1->pProf + 2) + 1472) + 1;
    *(_DWORD *)(v8 + 720) = v9 % 60;
    v10 = (int *)(v8 + 12 * (v9 % 60));
    *v10 = Sys_Milliseconds();
    v10[1] = cursize;
    v10[2] = v19;
    if ((*(_BYTE *)(net_showprofile + 8) & 2) != 0) {
      v11 = " fragment";
      if (!v19)
        v11 = (const char *)&inData;
      Com_Printf("%s recieve%s: %i\n", netsrcString[a1->sock], v11, cursize);
    }
  }
  if (*(_BYTE *)(showpackets + 8)) {
    if (v19)
      Com_Printf("[client %i] %s recv %4i : s=%i fragment=%i,%i\n", 1,
                 netsrcString[a1->sock], a2->cursize, Long, Short, __n);
    else
      Com_Printf("[client %i] %s recv %4i : s=%i\n", 1, netsrcString[a1->sock],
                 a2->cursize, Long);
  }
  incomingSequence = a1->incomingSequence;
  if (Long > incomingSequence) {
    v5 = Long - incomingSequence - 1;
    a1->dropped = v5;
    if (v5 > 0 && (*(_BYTE *)(showdrop + 8) || *(_BYTE *)(showpackets + 8))) {
      type = a1->remoteAddress.type;
      if (type == 2) {
        Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "loopback");
      } else if (type == 4) {
        Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "%i.%i.%i.%i:%i",
                    LOBYTE(a1->remoteAddress.ip), BYTE1(a1->remoteAddress.ip),
                    BYTE2(a1->remoteAddress.ip), HIBYTE(a1->remoteAddress.ip),
                    (__int16)__ROL2__(a1->remoteAddress.port, 8));
      }
      Com_Printf("[client %i] %s: Dropped %i packets at %i\n", 1,
                 NET_AdrToString(netadr_t)::s, v5, Long);
    }
    if (v19) {
      if (Long != *(int32_t *)((char *)&a1->fragmentSequence + 2)) {
        *(int32_t *)((char *)&a1->fragmentSequence + 2) = Long;
        *(uint32_t *)((char *)&a1->fragmentLength + 2) = 0;
      }
      if (Short != *(uint32_t *)((char *)&a1->fragmentLength + 2)) {
        if (!*(_BYTE *)(showdrop + 8) && !*(_BYTE *)(showpackets + 8))
          return 0;
        v7 = a1->remoteAddress.type;
        if (v7 == 2) {
          Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "loopback");
        } else if (v7 == 4) {
          Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "%i.%i.%i.%i:%i",
                      LOBYTE(a1->remoteAddress.ip), BYTE1(a1->remoteAddress.ip),
                      BYTE2(a1->remoteAddress.ip), HIBYTE(a1->remoteAddress.ip),
                      (__int16)__ROL2__(a1->remoteAddress.port, 8));
        }
        Com_Printf("%s:Dropped a message fragment\n",
                   NET_AdrToString(netadr_t)::s);
        return 0;
      }
      if (__n < 0 ||
          (readcount = a2->readcount,
           (signed int)(readcount + __n) > (signed int)a2->cursize) ||
          (unsigned int)(__n + Short) > 0x4000) {
        if (!*(_BYTE *)(showdrop + 8) && !*(_BYTE *)(showpackets + 8))
          return 0;
        v15 = a1->remoteAddress.type;
        if (v15 == 2) {
          Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "loopback");
        } else if (v15 == 4) {
          Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "%i.%i.%i.%i:%i",
                      LOBYTE(a1->remoteAddress.ip), BYTE1(a1->remoteAddress.ip),
                      BYTE2(a1->remoteAddress.ip), HIBYTE(a1->remoteAddress.ip),
                      (__int16)__ROL2__(a1->remoteAddress.port, 8));
        }
        Com_Printf("%s:illegal fragment length\n",
                   NET_AdrToString(netadr_t)::s);
        return 0;
      }
      memcpy(&a1->fragmentBuffer[Short + 2],
             (const void *)(a2->data + readcount), __n);
      v13 = *(uint32_t *)((char *)&a1->fragmentLength + 2) + __n;
      *(uint32_t *)((char *)&a1->fragmentLength + 2) = v13;
      if (__n == 1300)
        return 0;
      if (v13 > (signed int)a2->maxsize) {
        v14 = a1->remoteAddress.type;
        if (v14 == 2) {
          Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "loopback");
        } else if (v14 == 4) {
          Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "%i.%i.%i.%i:%i",
                      LOBYTE(a1->remoteAddress.ip), BYTE1(a1->remoteAddress.ip),
                      BYTE2(a1->remoteAddress.ip), HIBYTE(a1->remoteAddress.ip),
                      (__int16)__ROL2__(a1->remoteAddress.port, 8));
        }
        Com_Printf("%s:fragmentLength %i > msg->maxsize\n",
                   NET_AdrToString(netadr_t)::s, v13);
        return 0;
      }
      *(_DWORD *)a2->data = Long;
      memcpy((void *)(a2->data + 4), &a1->fragmentBuffer[2],
             *(uint32_t *)((char *)&a1->fragmentLength + 2));
      a2->cursize = *(uint32_t *)((char *)&a1->fragmentLength + 2) + 4;
      *(uint32_t *)((char *)&a1->fragmentLength + 2) = 0;
      MSG_BeginReading(a2);
      MSG_ReadLong(a2);
    }
    a1->incomingSequence = Long;
    return 1;
  }
  if (!*(_BYTE *)(showdrop + 8) && !*(_BYTE *)(showpackets + 8))
    return 0;
  v3 = a1->remoteAddress.type;
  if (v3 == 2) {
    Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "loopback");
  } else if (v3 == 4) {
    Com_sprintf(NET_AdrToString(netadr_t)::s, 0x40u, "%i.%i.%i.%i:%i",
                LOBYTE(a1->remoteAddress.ip), BYTE1(a1->remoteAddress.ip),
                BYTE2(a1->remoteAddress.ip), HIBYTE(a1->remoteAddress.ip),
                (__int16)__ROL2__(a1->remoteAddress.port, 8));
  }
  Com_Printf("[client %i] %s:Out of order packet %i at %i\n", 1,
             NET_AdrToString(netadr_t)::s, Long, incomingSequence);
  return 0;
}

void __cdecl Netchan_Init(int port) {
  showpackets = (int)Dvar_RegisterBool("showpackets", 0, 0x1000u);
  showdrop = (int)Dvar_RegisterBool("showdrop", 0, 0x1000u);
  packetDebug = (int)Dvar_RegisterBool("packetDebug", 0, 0x1000u);
  g_qport[0] = a1;
  net_profile = (int)Dvar_RegisterInt("net_profile", 0, 0, 2, 0x1000u);
  net_showprofile = (int)Dvar_RegisterInt("net_showprofile", 0, 0, 3, 0x1000u);
  net_lanauthorize = (int)Dvar_RegisterBool("net_lanauthorize", 0, 0x1000u);
  Cmd_AddCommand("net_dumpprofile", (void (*)(void))Net_DumpProfile_f);
}

struct dvar_s const *const showpackets;
struct dvar_s const *const net_profile;
struct dvar_s const *const net_lanauthorize;
struct dvar_s const *const packetDebug;
struct dvar_s const *const showdrop;
struct dvar_s const *const net_showprofile;
int g_qport;
int __cdecl LittleLong(int) { UNIMPLEMENTED(); }

int __cdecl LittleLong(int) { UNIMPLEMENTED(); }

int __cdecl LittleLong(int) { UNIMPLEMENTED(); }
