void __cdecl CL_Netchan_UpdateProfileStats(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_Netchan_AddOOBProfilePacket(int iLength)
{
  int result;              // eax
  netProfileStream_t **v2; // ebx

  result = net_profile;
    if (*(_DWORD *)(net_profile + 8)) {
      v2 = (netProfileStream_t **)clc;
      NetProf_PrepProfiling((netProfileInfo_t **)clc + 74240);
      return NetProf_AddPacket(v2[74240], a1, 0);
    }
  return result;
}

void __cdecl CL_Netchan_TransmitNextFragment(struct netchan_t *chan)
{
  return Netchan_TransmitNextFragment(a1);
}

void __cdecl CL_Netchan_Transmit(struct netchan_t *, unsigned char *, int)
{
  unsigned __int8 *v3;  // edi
  char v4;              // bl
  int v5;               // esi
  int v6;               // edx
  unsigned __int8 *v7;  // eax
  size_t v9;            // [esp+18h] [ebp-20h]
  unsigned __int8 *v10; // [esp+1Ch] [ebp-1Ch]

  v9 = __n - 9;
  v3 = __src + 9;
  v10 = (unsigned __int8 *)clc + 1024 * (*((_DWORD *)clc + 32847) & 0x7F) +
        131396;
  v4 = *((_BYTE *)&loc_20138 + (_DWORD)clc) ^ *((_DWORD *)cl + 8586) ^
       *((_BYTE *)clc + 296);
    if ((int)(__n - 9) > 0) {
      v5 = 0;
      v6 = 0;
        do {
            while (1) {
              v7 = &v10[v5];
              if (v10[v5])
                break;
              v5 = 1;
              v4 ^= *v10 << (v6 & 1);
              v3[v6++] ^= v4;
              if (v9 == v6)
                return Netchan_Transmit(a1, __n, __src);
            }
          ++v5;
          v4 ^= *v7 << (v6 & 1);
          v3[v6++] ^= v4;
        }
      while (v9 != v6);
    }
  return Netchan_Transmit(a1, __n, __src);
}

void __cdecl CL_Netchan_PrintProfileStats(int bPrintToConsole)
{
  void *v2;         // ebx
  int v3;           // edi
  _DWORD *v4;       // ebx
  _DWORD *v5;       // ebx
  int v6;           // [esp+28h] [ebp-420h]
  int v7;           // [esp+2Ch] [ebp-41Ch]
  char __str[1048]; // [esp+30h] [ebp-418h] BYREF

  v2 = clc;
    if (*((_DWORD *)clc + 74239)) {
      NetProf_UpdateStatistics(*((netProfileStream_t **)clc + 74239));
      NetProf_UpdateStatistics(
          (netProfileStream_t *)(*((_DWORD *)v2 + 74239) + 752));
    }
    if (*((_DWORD *)v2 + 74240)) {
      NetProf_UpdateStatistics(*((netProfileStream_t **)v2 + 74240));
      NetProf_UpdateStatistics(
          (netProfileStream_t *)(*((_DWORD *)v2 + 74240) + 752));
    }
  if (a2)
    Com_Printf("\n\n");
  Com_sprintf(__str, 0x400u, "====================");
    if (a2) {
      Com_Printf("%s\n", __str);
      v3 = 80;
      Com_sprintf(__str, 0x400u, "Client Network Profile:");
      Com_Printf("%s\n\n", __str);
      Com_sprintf(__str, 0x400u, "      Source    bps   max   min frag%%");
      Com_Printf("%s\n", __str);
      v4 = (_DWORD *)*((_DWORD *)clc + 74240);
        if (v4) {
        LABEL_9:
          v6 = v4[181];
          v7 = v4[369];
          Com_sprintf(__str, 0x400u, "    OOB Sent: %5i %5i %5i    -", v6,
                      v4[186], v4[187]);
            if (a2) {
              Com_Printf("%s\n", __str);
            }
            else {
              v3 += 10;
              CL_DrawString(a1, 32, v3, __str, 0, 10);
            }
          Com_sprintf(__str, 0x400u, "OOB Recieved: %5i %5i %5i    -", v4[369],
                      v4[374], v4[375]);
            if (a2) {
              Com_Printf("%s\n", __str);
            }
            else {
              v3 += 10;
              CL_DrawString(a1, 32, v3, __str, 0, 10);
            }
          goto LABEL_13;
        }
    }
    else {
      CL_DrawString(a1, 32, 90, __str, 0, 10);
      Com_sprintf(__str, 0x400u, "Client Network Profile:");
      CL_DrawString(a1, 32, 100, __str, 0, 10);
      Com_sprintf(__str, 0x400u, "      Source    bps   max   min frag%%");
      v3 = 120;
      CL_DrawString(a1, 32, 120, __str, 0, 10);
      v4 = (_DWORD *)*((_DWORD *)clc + 74240);
      if (v4)
        goto LABEL_9;
    }
  Com_sprintf(__str, 0x400u, "    OOB Sent:     0     0     0    -");
    if (a2) {
      Com_Printf("%s\n", __str);
    }
    else {
      v3 += 10;
      CL_DrawString(a1, 32, v3, __str, 0, 10);
    }
  Com_sprintf(__str, 0x400u, "OOB Recieved:     0     0     0    -");
    if (a2) {
      Com_Printf("%s\n", __str);
    }
    else {
      v3 += 10;
      CL_DrawString(a1, 32, v3, __str, 0, 10);
    }
  v6 = 0;
  v7 = 0;
LABEL_13:
  v5 = (_DWORD *)*((_DWORD *)clc + 74239);
    if (v5) {
      v6 += v5[181];
      v7 += v5[369];
      Com_sprintf(__str, 0x400u, "        Sent: %5i %5i %5i  %3i%%", v5[181],
                  v5[186], v5[187], v5[185]);
        if (a2) {
          Com_Printf("%s\n", __str);
        }
        else {
          v3 += 10;
          CL_DrawString(a1, 32, v3, __str, 0, 10);
        }
      Com_sprintf(__str, 0x400u, "    Recieved: %5i %5i %5i  %3i%%", v5[369],
                  v5[374], v5[375], v5[373]);
        if (!a2) {
        LABEL_17:
          v3 += 10;
          CL_DrawString(a1, 32, v3, __str, 0, 10);
          goto LABEL_18;
        }
    }
    else {
      Com_sprintf(__str, 0x400u, "        Sent:     0     0     0    0%");
        if (a2) {
          Com_Printf("%s\n", __str);
        }
        else {
          v3 += 10;
          CL_DrawString(a1, 32, v3, __str, 0, 10);
        }
      Com_sprintf(__str, 0x400u, "    Recieved:     0     0     0    0%");
      if (!a2)
        goto LABEL_17;
    }
  Com_Printf("%s\n", __str);
LABEL_18:
  Com_sprintf(__str, 0x400u, "       Total: %5i", v7 + v6);
  if (a2)
    Com_Printf("%s\n", __str);
  else
    CL_DrawString(a1, 32, v3 + 10, __str, 0, 10);
}

void __cdecl CL_Netchan_SendOOBPacket(int iLength, void const *pData,
                                      struct netadr_t to)
{
  int result;              // eax
  netProfileStream_t **v4; // [esp+2Ch] [ebp-3Ch]
  netProfileInfo_t **v5;   // [esp+30h] [ebp-38h]

  if (*a2 != -1)
    Com_Printf("CL_Netchan_SendOOBPacket used to send non-OOB packet.\n");
  v4 = (netProfileStream_t **)clc;
  v5 = (netProfileInfo_t **)((char *)clc + 296960);
  NetProf_PrepProfiling((netProfileInfo_t **)clc + 74240);
  NET_SendPacket(NS_CLIENT1, a1, a2, a3);
  result = net_profile;
    if (*(_DWORD *)(net_profile + 8)) {
      NetProf_PrepProfiling(v5);
      return NetProf_AddPacket(v4[74240], a1, 0);
    }
  return result;
}

void __cdecl CL_ProfDraw(int, char const *)
{
  UNIMPLEMENTED();
}

CL_Netchan_Decode(unsigned char *data, int size)
{
  UNIMPLEMENTED();
}
