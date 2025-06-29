void __cdecl SV_QueueVoicePacket(int talkerNum, int clientNum,
                                 unsigned char *voicePacket)
{
  int result; // eax
  char *v4;   // ebx
  int v5;     // edx

  result = (int)dword_170048C;
  v4 = (char *)dword_170048C + 495372 * a2;
  v5 = *((_DWORD *)v4 + 123825);
    if (v5 <= 39) {
      *(_DWORD *)&v4[261 * v5 + 485117] = a3->dataSize;
      memcpy(&v4[261 * *((_DWORD *)v4 + 123825) + 484861], a3->data,
             a3->dataSize);
      result = 261 * *((_DWORD *)v4 + 123825);
      v4[result + 484860] = a1;
      ++*((_DWORD *)v4 + 123825);
    }
  return result;
}

bool __cdecl SV_ClientHasClientMuted(int listener, int talker)
{
  return dword_170048C->muteList[495372 * a1 + 4 + a2];
}

void __cdecl SV_PreGameUserVoice(struct client_s *cl, struct msg_t *msg)
{
  size_t Short;     // edx
  int v3;           // esi
  int v4;           // edi
  char *v5;         // ebx
  int v6;           // edx
  int v7;           // [esp+14h] [ebp-134h]
  int Byte;         // [esp+18h] [ebp-130h]
  int v9;           // [esp+1Ch] [ebp-12Ch]
  _BYTE __src[256]; // [esp+2Ch] [ebp-11Ch] BYREF
  size_t __n;       // [esp+12Ch] [ebp-1Ch]

    if (*(_BYTE *)(sv_voice + 8)) {
      v7 = 931767531 * (((char *)a1 - (char *)dword_170048C) >> 2);
      Byte = MSG_ReadByte(a2);
        if (Byte > 0) {
          v9 = 0;
            while (1) {
              Short = MSG_ReadShort(a2);
              __n = Short;
              if (Short - 1 > 0xFF)
                break;
              MSG_ReadData(a2, __src, Short);
              v3 = 0;
              v4 = 0;
                do {
                    while (1) {
                        if (v7 != v3) {
                          v5 = (char *)dword_170048C + v4;
                            if (*(int *)((char *)&dword_170048C->state + v4) >
                                    1 &&
                                !v5[v7 + 495304]) {
                                if (v5[495368]) {
                                  v6 = *((_DWORD *)v5 + 123825);
                                  if (v6 <= 39)
                                    break;
                                }
                            }
                        }
                      ++v3;
                      v4 += 495372;
                      if (v3 == 64)
                        goto LABEL_14;
                    }
                  *(_DWORD *)&v5[261 * v6 + 485117] = __n;
                  memcpy(&v5[261 * *((_DWORD *)v5 + 123825) + 484861], __src,
                         __n);
                  v5[261 * (*((_DWORD *)v5 + 123825))++ + 484860] = v7;
                  ++v3;
                  v4 += 495372;
                }
              while (v3 != 64);
            LABEL_14:
              if (Byte == ++v9)
                return;
            }
          Com_Printf("Received invalid voice packet of size %i from %s\n",
                     Short, &a1->name[2]);
        }
    }
}

void __cdecl SV_UserVoice(struct client_s *cl, struct msg_t *msg)
{
  int Byte;            // edi
  int v3;              // ebx
  uint32_t v4;         // edx
  VoicePacket_t __dst; // [esp+2Bh] [ebp-11Dh] BYREF

    if (*(_BYTE *)(sv_voice + 8)) {
      Byte = MSG_ReadByte(a2);
        if (Byte > 0) {
          v3 = 0;
            while (1) {
              v4 = MSG_ReadByte(a2);
              __dst.dataSize = v4;
              if (v4 - 1 > 0xFF)
                break;
              MSG_ReadData(a2, __dst.data, v4);
              G_BroadcastVoice(*(gentity_s **)((char *)&a1->gentity + 2),
                               &__dst);
              if (Byte == ++v3)
                return;
            }
          Com_Printf("Received invalid voice packet of size %i from %s\n", v4,
                     &a1->name[2]);
        }
    }
}

void __cdecl SV_SendClientVoiceData(struct client_s *client)
{
  unsigned __int8 *Buf; // eax
  client_s *v2;         // esi
  int v3;               // ebx
  netadr_t v4;          // [esp+4h] [ebp-64h]
  msg_t v5;             // [esp+28h] [ebp-40h] BYREF
  __int64 v6;           // [esp+40h] [ebp-28h]
  int32_t qport;        // [esp+48h] [ebp-20h]
  LargeLocal v8;        // [esp+4Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v8, (int)&loc_20000);
  Buf = (unsigned __int8 *)LargeLocal::GetBuf(&v8);
  if (a1->state != 4 || !*(_DWORD *)a1->muteList)
    goto LABEL_2;
  MSG_Init(&v5, Buf, (uint32_t)&loc_20000);
  MSG_WriteString(&v5, "v");
  MSG_WriteByte(&v5, *(_DWORD *)a1->muteList);
    if (*(int *)a1->muteList > 0) {
      v2 = a1;
      v3 = 0;
        do {
          MSG_WriteByte(&v5, v2->voicePackets[4]);
          MSG_WriteByte(&v5, *(_DWORD *)&v2->voicePackets[261]);
          MSG_WriteData(&v5, &a1->voicePackets[261 * v3++ + 5],
                        *(_DWORD *)&v2->voicePackets[261]);
          v2 = (client_s *)((char *)v2 + 261);
        }
      while (v3 < *(_DWORD *)a1->muteList);
    }
    if (v5.overflowed) {
      Com_Printf("WARNING: voice msg overflowed for %s\n", &a1->name[2]);
    LABEL_2:
      LargeLocal::~LargeLocal(&v8);
      return;
    }
  LODWORD(v6) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)a1);
  HIDWORD(v6) = *(int32_t *)((char *)&a1->netchan.remoteAddress.ip + 2);
  qport = a1->netchan.qport;
  *(_QWORD *)&v4.type = v6;
  v4.port = qport;
  NET_OutOfBandVoiceData(NS_SERVER, v4, (unsigned __int8 *)v5.data, v5.cursize);
  *(_DWORD *)a1->muteList = 0;
  LargeLocal::~LargeLocal(&v8);
}

void __cdecl SV_WriteVoiceDataToClient(struct client_s *, struct msg_t *)
{
  UNIMPLEMENTED();
}

SV_ClientWantsVoiceData(int clientNum)
{
  UNIMPLEMENTED();
}
