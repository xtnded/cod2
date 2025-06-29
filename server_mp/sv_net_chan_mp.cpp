void __cdecl SV_Netchan_UpdateProfileStats(void) { UNIMPLEMENTED(); }

void __cdecl SV_Netchan_AddOOBProfilePacket(int iLength) {
  int result; // eax

  result = net_profile;
  if (*(_DWORD *)(net_profile + 8)) {
    NetProf_PrepProfiling((netProfileInfo_t **)&byte_170A4EC[8]);
    return NetProf_AddPacket(*(netProfileStream_t **)&byte_170A4EC[8], a1, 0);
  }
  return result;
}

bool __cdecl SV_Netchan_TransmitNextFragment(struct netchan_t *chan) {
  return (unsigned __int8)Netchan_TransmitNextFragment(a1);
}

bool __cdecl SV_Netchan_Transmit(struct client_s *client, unsigned char *data,
                                 int length) {
  unsigned __int8 *v3; // edi
  char v4;             // bl
  int v5;              // esi
  int v6;              // edx
  char *v7;            // eax
  size_t v9;           // [esp+18h] [ebp-20h]
  char *v10;           // [esp+1Ch] [ebp-1Ch]

  v9 = __n - 4;
  v3 = __src + 4;
  v10 = &a1->lastClientCommandString[2];
  v4 = *(int32_t *)((char *)&a1->netchan.outgoingSequence + 2) ^
       *((_BYTE *)COpenGL::SetColorMaterialEnable + (_DWORD)a1);
  if ((int)(__n - 4) > 0) {
    v5 = 0;
    v6 = 0;
    do {
      while (1) {
        v7 = &v10[v5];
        if (v10[v5])
          break;
        v5 = 1;
        v4 ^= (unsigned __int8)*v10 << (v6 & 1);
        v3[v6++] ^= v4;
        if (v6 == v9)
          return Netchan_Transmit(
              (netchan_t *)((char *)&a1->netchan.outgoingSequence + 2), __n,
              __src);
      }
      ++v5;
      v4 ^= (unsigned __int8)*v7 << (v6 & 1);
      v3[v6++] ^= v4;
    } while (v6 != v9);
  }
  return Netchan_Transmit(
      (netchan_t *)((char *)&a1->netchan.outgoingSequence + 2), __n, __src);
}

void __cdecl SV_Netchan_PrintProfileStats(int bPrintToConsole) {
  UNIMPLEMENTED();
}

void __cdecl SV_Netchan_SendOOBPacket(int, void const *, struct netadr_t) {
  UNIMPLEMENTED();
}

void __cdecl SV_ProfDraw(int, char const *) { UNIMPLEMENTED(); }

SV_Netchan_Decode(client_s *client, unsigned char *data, int size) {
  UNIMPLEMENTED();
}
