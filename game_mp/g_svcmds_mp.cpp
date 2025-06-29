void __cdecl Svcmd_EntityList_f()
{
  UNIMPLEMENTED();
}

void __cdecl Svcmd_RemoveIP_f()
{
  int i;            // eax
  char *v1;         // edi
  int j;            // ebx
  char v3;          // dl
  int v4;           // ecx
  char *v5;         // edi
  char v6;          // al
  int v7;           // edx
  _DWORD *v8;       // eax
  _DWORD *v9;       // ebx
  unsigned int v10; // kr04_4
  int v11;          // [esp+2Ch] [ebp-82Ch]
  char __src[1024]; // [esp+38h] [ebp-820h] BYREF
  char v13[1024];   // [esp+438h] [ebp-420h] BYREF
  _DWORD v14[8];    // [esp+838h] [ebp-20h]

    if (SV_Cmd_Argc() <= 1) {
      Com_Printf("Usage:  sv removeip <ip-mask>\n");
    }
    else {
      SV_Cmd_ArgvBuffer(1, v13, 1024);
        for (i = 1; i != 5; ++i) {
          *((_BYTE *)v14 + i + 3) = 0;
          v13[i + 1023] = 0;
        }
      v1 = v13;
        for (j = 1; j != 5; ++j) {
          v3 = *v1;
            if ((unsigned __int8)(*v1 - 48) > 9u) {
              Com_Printf("Bad filter address: %s\n", v1);
              return;
            }
          v4 = 0;
            do {
              __src[v4] = v3;
              v3 = v1[++v4];
            }
          while ((unsigned __int8)(v3 - 48) <= 9u);
          v5 = &v1[v4];
          __src[v4] = 0;
          v6 = atoi(__src);
          *((_BYTE *)v14 + j + 3) = v6;
          if (v6)
            v13[j + 1023] = -1;
          if (!*v5)
            break;
          v1 = v5 + 1;
        }
        if (numIPFilters <= 0) {
        LABEL_23:
          Com_Printf("Didn't find %s.\n", v13);
        }
        else {
          v7 = 0;
          v8 = &ipFilters;
            while (*v8 != v14[0] || v8[1] != v14[1]) {
              ++v7;
              v8 += 2;
              if (v7 == numIPFilters)
                goto LABEL_23;
            }
          *((_DWORD *)&ipFilters + 2 * v7 + 1) = -1;
          Com_Printf("Removed.\n");
          __src[0] = 0;
            if (numIPFilters > 0) {
              v11 = 0;
              v9 = &ipFilters;
                do {
                    if (v9[1] != -1) {
                      v14[0] = v9[1];
                      v10 = strlen(__src) + 1;
                      Com_sprintf(&__src[v10 - 1], 1024 - (v10 - 1),
                                  "%i.%i.%i.%i ", LOBYTE(v14[0]), BYTE1(v14[0]),
                                  BYTE2(v14[0]), HIBYTE(v14[0]));
                    }
                  ++v11;
                  v9 += 2;
                }
              while (v11 < numIPFilters);
            }
          Dvar_SetString((dvar_s *)g_banIPs, __src);
        }
    }
}

void __cdecl Svcmd_AddIP_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_ProcessIPBans()
{
  char *v0;       // ebx
  char *v1;       // esi
  char *v2;       // eax
  char __s[1032]; // [esp+10h] [ebp-408h] BYREF

  numIPFilters = 0;
  v0 = __s;
  I_strncpyz(__s, *(char **)(g_banIPs + 8), 1024);
  v1 = __s;
    while (*v1) {
      v2 = strchr(v0, 32);
      v0 = v2;
      if (!v2)
        break;
      if (*v2 != 32)
        goto LABEL_4;
      do
        *v0++ = 0;
      while (*v0 == 32);
        if (*v1) {
        LABEL_4:
          AddIP(v1);
          v1 = v0;
        }
        else {
          v1 = v0;
        }
    }
}

int __cdecl ConsoleCommand()
{
  char *v1;      // eax
  char *v2;      // eax
  char v3[1024]; // [esp+10h] [ebp-808h] BYREF
  char v4[1032]; // [esp+410h] [ebp-408h] BYREF

  SV_Cmd_ArgvBuffer(0, v4, 1024);
    if (I_stricmp(v4, "entitylist")) {
        if (I_stricmp(v4, "addip")) {
            if (I_stricmp(v4, "removeip")) {
                if (I_stricmp(v4, "listip")) {
                    if (!*(_DWORD *)(g_dedicated + 8) || I_stricmp(v4, "say")) {
                      return 0;
                    }
                    else {
                      v1 = ConcatArgs(1);
                      v2 = va("%c \"GAME_SERVER\x15: %s\"", 101, v1);
                      SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, v2);
                      return 1;
                    }
                }
                else {
                  Cbuf_ExecuteText(1, "g_banIPs\n");
                  return 1;
                }
            }
            else {
              Svcmd_RemoveIP_f();
              return 1;
            }
        }
        else {
            if (SV_Cmd_Argc() <= 1) {
              Com_Printf("Usage:  addip <ip-mask>\n");
            }
            else {
              SV_Cmd_ArgvBuffer(1, v3, 1024);
              AddIP(v3);
            }
          return 1;
        }
    }
    else {
      Svcmd_EntityList_f();
      return 1;
    }
}

struct gclient_s *__cdecl ClientForString(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl StringToFilter(char *, struct ipFilter_s *)
{
  UNIMPLEMENTED();
}

void __cdecl UpdateIPBans(void)
{
  UNIMPLEMENTED();
}

void __cdecl AddIP(char *)
{
  int v2;           // ecx
  _DWORD *v3;       // edx
  int v4;           // eax
  int v5;           // edx
  int i;            // eax
  int v7;           // esi
  char v8;          // dl
  int v9;           // ecx
  const char *v10;  // edi
  char v11;         // al
  _DWORD *v12;      // esi
  unsigned int v13; // kr04_4
  int v14;          // [esp+24h] [ebp-434h]
  _DWORD *v15;      // [esp+28h] [ebp-430h]
  int v16;          // [esp+2Ch] [ebp-42Ch]
  char __src[1024]; // [esp+38h] [ebp-420h] BYREF
  _DWORD v18[8];    // [esp+438h] [ebp-20h]

  v2 = numIPFilters;
    if (numIPFilters > 0 && dword_FE8124[0] != -1) {
      v14 = 0;
      v3 = &ipFilters;
        while (++v14 != numIPFilters) {
          v4 = v3[3];
          v3 += 2;
            if (v4 == -1) {
              v5 = v14;
              goto LABEL_9;
            }
        }
        if (numIPFilters == 1024) {
          Com_Printf("IP filter list is full\n");
          return;
        }
      goto LABEL_26;
    }
    if (!numIPFilters) {
    LABEL_26:
      ++numIPFilters;
      v14 = v2;
      v5 = v2;
      goto LABEL_9;
    }
  v14 = 0;
  v5 = 0;
LABEL_9:
  v15 = (_DWORD *)((char *)&ipFilters + 8 * v5);
    for (i = 1; i != 5; ++i) {
      *((_BYTE *)v18 + i + 3) = 0;
      __src[i + 1023] = 0;
    }
  v7 = 1;
    while (1) {
      v8 = *a1;
      if ((unsigned __int8)(*a1 - 48) > 9u)
        break;
      v9 = 0;
        do {
          __src[v9] = v8;
          v8 = a1[++v9];
        }
      while ((unsigned __int8)(v8 - 48) <= 9u);
      v10 = &a1[v9];
      __src[v9] = 0;
      v11 = atoi(__src);
      *((_BYTE *)v18 + v7 + 3) = v11;
      if (v11)
        __src[v7 + 1023] = -1;
        if (*v10) {
          a1 = v10 + 1;
          if (++v7 != 5)
            continue;
        }
      *v15 = v18[0];
      v15[1] = v18[1];
      goto LABEL_20;
    }
  Com_Printf("Bad filter address: %s\n", a1);
  dword_FE8124[2 * v14] = -1;
LABEL_20:
  __src[0] = 0;
    if (numIPFilters > 0) {
      v16 = 0;
      v12 = &ipFilters;
        do {
            if (v12[1] != -1) {
              v18[0] = v12[1];
              v13 = strlen(__src) + 1;
              Com_sprintf(&__src[v13 - 1], 1024 - (v13 - 1), "%i.%i.%i.%i ",
                          LOBYTE(v18[0]), BYTE1(v18[0]), BYTE2(v18[0]),
                          HIBYTE(v18[0]));
            }
          ++v16;
          v12 += 2;
        }
      while (v16 < numIPFilters);
    }
  Dvar_SetString((dvar_s *)g_banIPs, __src);
}
