bool __cdecl SV_Loaded() { return sv == 2; }

void __cdecl SV_InitDvar() { UNIMPLEMENTED(); }

void __cdecl SV_InitArchivedSnapshot() { UNIMPLEMENTED(); }

void __cdecl SV_ClearServer(void) { UNIMPLEMENTED(); }

char *__cdecl SV_GetConfigValueForKey(int, int, char const *) {
  UNIMPLEMENTED();
}

char const *__cdecl SV_GetConfigstringConst(int index) {
  const gentity_s *result; // eax

  result = &inData;
  if (*((_DWORD *)&sv + a1 + 262))
    return (const gentity_s *)*((_DWORD *)&sv + a1 + 262);
  return result;
}

void __cdecl SV_CreateBaseline(void) { UNIMPLEMENTED(); }

void __cdecl SV_EnableArchivedSnapshot(int bEnable) {
  void *result; // eax

  result = a1;
  unk_17004A8 = a1;
  if (a1) {
    result = dword_17004B0;
    if (!dword_17004B0) {
      dword_17004C8 = Z_MallocInternal((size_t)&unk_450000);
      dword_17004CC = Z_MallocInternal(0x2708000u);
      dword_17004B0 = Z_MallocInternal(0x2580u);
      dword_17004B4 = Z_MallocInternal(0x2000000u);
      result = Z_MallocInternal(0x3800u);
      dword_17004D0 = result;
    }
  }
  return result;
}

void __cdecl SV_GetUserinfo(int index, char *buffer, int bufferSize) {
  UNIMPLEMENTED();
}

void __cdecl SV_SetUserinfo(int index, char const *val) {
  char *v2; // edi
  char *v3; // eax

  v2 = a2;
  if (a1 < 0 || a1 >= *(_DWORD *)(sv_maxclients + 8))
    Com_Error(1, "\x15SV_SetUserinfo: bad index %i\n", a1);
  if (!a2)
    v2 = (char *)&inData;
  I_strncpyz(&dword_170048C->userinfo[495372 * a1], v2, 1024);
  v3 = (char *)Info_ValueForKey(v2, "name");
  return I_strncpyz(&dword_170048C->name[495372 * a1 + 2], v3, 32);
}

void __cdecl SV_GetConfigstring(int index, char *buffer, int bufferSize) {
  UNIMPLEMENTED();
}

void __cdecl SV_SetConfigstring(int index, char const *val) { UNIMPLEMENTED(); }

void __cdecl SV_SetXUIDConfigStrings(void) { UNIMPLEMENTED(); }

void __cdecl SV_SetConfigValueForKey(int start, int max, char const *key,
                                     char const *value) {
  UNIMPLEMENTED();
}

void __cdecl SV_BoundMaxClients(int) { UNIMPLEMENTED(); }

void __cdecl SV_ChangeMaxClients() { UNIMPLEMENTED(); }

void __cdecl SV_Startup() {
  int v7; // eax

  if (svs)
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 0, "\x15SV_Startup: svs.initialized");
  sv_maxclients = (int)Dvar_RegisterInt("sv_maxclients", 20, 1, 64, 0x1025u);
  Dvar_ClearModified((const dvar_s *)sv_maxclients);
  v7 = sv_maxclients;
  if (*(int *)(sv_maxclients + 8) <= 0) {
    Dvar_SetInt((dvar_s *)sv_maxclients, 1);
    v7 = sv_maxclients;
  }
  dword_170048C =
      (client_s *)Z_VirtualAllocInternal(495372 * *(_DWORD *)(v7 + 8));
  if (!dword_170048C)
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 0,
              "\x15SV_Startup: unable to allocate svs.clients");
  if (*(_DWORD *)(com_dedicated + 8)) {
    dword_1700490 = *(_DWORD *)(sv_maxclients + 8) << 11;
    dword_1700494 =
        32 * *(_DWORD *)(sv_maxclients + 8) * *(_DWORD *)(sv_maxclients + 8);
  } else {
    dword_1700490 = *(_DWORD *)(sv_maxclients + 8) << 8;
    dword_1700494 =
        4 * *(_DWORD *)(sv_maxclients + 8) * *(_DWORD *)(sv_maxclients + 8);
  }
  svs = 1;
  Dvar_SetBool((dvar_s *)com_sv_running, 1);
}

void __cdecl SV_DropAllClients(void) { UNIMPLEMENTED(); }

void __cdecl SV_FinalMessage(char *) { UNIMPLEMENTED(); }

void __cdecl SV_Shutdown(char *finalmsg) { UNIMPLEMENTED(); }

void __cdecl SV_SpawnServer(char const *server) {
  _DWORD *v8;         // ebx
  unsigned int v9;    // eax
  int v10;            // ebx
  int v11;            // eax
  char *BspExtension; // eax
  _DWORD *v13;        // ebx
  char *v14;          // eax
  int v15;            // eax
  char *v16;          // eax
  int v17;            // ebx
  int v18;            // esi
  int v19;            // ebx
  char *v20;          // eax
  char *v21;          // ebx
  char *v22;          // eax
  char *v23;          // eax
  char *v24;          // eax
  char *v25;          // eax
  char *v26;          // eax
  int *p_state;       // ebx
  int v28;            // esi
  int i;              // esi
  int v30;            // edx
  _DWORD *v31;        // esi
  _DWORD *v32;        // edx
  _BYTE *v33;         // eax
  netadr_t v34;       // [esp+4h] [ebp-20C4h]
  int v35;            // [esp+48h] [ebp-2080h]
  int SavePersist;    // [esp+4Ch] [ebp-207Ch]
  _DWORD *__src;      // [esp+50h] [ebp-2078h]
  int v38;            // [esp+54h] [ebp-2074h]
  _DWORD *v39;        // [esp+58h] [ebp-2070h]
  char __dst[8192];   // [esp+60h] [ebp-2068h] BYREF
  char __str[64];     // [esp+2060h] [ebp-68h] BYREF
  __int64 v42;        // [esp+20A0h] [ebp-28h]
  int v43;            // [esp+20A8h] [ebp-20h]
  int v44[7];         // [esp+20ACh] [ebp-1Ch] BYREF

  Scr_ParseGameTypeList();
  SV_SetGametype();
  CL_InitLoad(a1, a2.f32[0], a3, a4, a5, a6, a7, a8,
              *(char **)(sv_gametype + 8));
  if (*(_BYTE *)(com_sv_running + 8)) {
    SavePersist = G_GetSavePersist();
    p_state = &dword_170048C->state;
    if (*(int *)(sv_maxclients + 8) > 0) {
      v28 = 0;
      do {
        if (*p_state > 2) {
          Com_sprintf(__str, 0x40u, "loadingnewmap\n%s\n%s", a8,
                      *(const char **)(sv_gametype + 8));
          LODWORD(v42) = *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)p_state);
          HIDWORD(v42) = p_state[113010];
          v43 = p_state[113011];
          *(_QWORD *)&v34.type = v42;
          v34.port = v43;
          NET_OutOfBandPrint(NS_SERVER, v34, __str);
        }
        ++v28;
        p_state += 123843;
      } while (*(_DWORD *)(sv_maxclients + 8) > v28);
    }
    NET_Sleep(250);
  } else {
    SavePersist = 0;
  }
  Dvar_SetStringByName("mapname", a8);
  CL_MapLoading(a1, a2.f32[0], a3, a4, a5, a6, a7, a8);
  CL_ShutdownAll(a1, a2.f32[0], a3, a4, a5, a6, a7);
  SV_ShutdownGameProgs(a2.f32[0]);
  Com_Printf("------ Server Initialization ------\n");
  Com_Printf("Server: %s\n", a8);
  v8 = sv;
  do {
    if (v8[262])
      Z_FreeInternal((void *)v8[262]);
    ++v8;
  } while (&unk_16A2F00 != (_UNKNOWN *)v8);
  Com_Memset(sv, 0, 0x5F534u);
  if (*(_DWORD *)(com_dedicated + 8))
    FX_FreeSystem();
  FS_Shutdown();
  FS_ClearIwdReferences();
  Com_Restart();
  if (*(_BYTE *)(com_sv_running + 8))
    SV_ChangeMaxClients(a1, a2.f32[0], a3, a4, a5, a6, a7);
  else
    SV_Startup(a1, a2.f32[0], a3, a4, a5, a6, a7);
  I_strncpyz((char *)&dword_1700390[25], *(char **)(sv_gametype + 8), 64);
  v9 = Sys_MillisecondsRaw();
  srand(v9);
  v35 = rand();
  v10 = rand();
  v11 = Sys_Milliseconds();
  sv[3] = v11 ^ v10 ^ (v35 << 16);
  FS_Restart(a1, a2.f32[0], a3, a4, a5, a6, a7, v11 ^ v10 ^ (v35 << 16));
  BspExtension = GetBspExtension();
  Com_sprintf(__str, 0x40u, "maps/mp/%s.%s", a8, BspExtension);
  SV_SetExpectedHunkUsage(__str);
  CL_StartLoading(a1, a2.f32[0], a3, a4, a5, a6, a7);
  UI_LoadIngameMenus(a1, a2.f32[0], a3, a4, a5, a6, a7);
  v13 = sv;
  do {
    v13[262] = CopyStringInternal((char *)&inData);
    ++v13;
  } while (&unk_16A2F00 != (_UNKNOWN *)v13);
  Dvar_ResetScriptInfo();
  unk_17004A0 = Hunk_AllocInternal(240 * dword_1700490);
  dword_1700498 = 0;
  unk_17004A4 = Hunk_AllocInternal(92 * dword_1700494);
  dword_170049C = 0;
  unk_17004A8 = 0;
  dword_17004AC = 0;
  dword_17004B8 = 0;
  dword_17004BC = 0;
  dword_17004C0 = 0;
  dword_17004C4 = 0;
  unk_1700488 ^= 4u;
  Dvar_SetString(nextmap, "map_restart");
  Dvar_SetInt((dvar_s *)cl_paused, 0);
  v14 = GetBspExtension();
  Com_sprintf(__str, 0x40u, "maps/mp/%s.%s", a8, v14);
  Com_LoadBsp(a1, a2.f32[0], a3, a4, a5, a6, a7, __str);
  CM_LoadMap(a1, a2.f32[0], a3, a4, a5, a6, a7, __str, v44);
  Com_UnloadBsp();
  CM_LinkWorld();
  v15 = (unsigned __int8)(sv_serverId_value + 16);
  sv_serverId_value = v15;
  if ((v15 & 0xF0) == 0) {
    v15 += 16;
    sv_serverId_value = v15;
  }
  Dvar_SetInt(sv_serverid, v15);
  sv[2] = com_frameTime;
  sv[0] = 1;
  v16 = GetBspExtension();
  Com_sprintf(__str, 0x40u, "maps/mp/%s.%s", a8, v16);
  Com_LoadSoundAliases(a1, a2.f32[0], a3, a4, a5, a6, a7, __str, "all_mp",
                       SASYS_GAME);
  SV_InitGameProgs(a1, a2.f32[0], a3, a4, a5, a6, a7, SavePersist);
  if (*(_DWORD *)(com_dedicated + 8)) {
    FX_InitSystem(0);
    FX_CreateDefaultEffect(a1, a2.f32[0], a3, a4, a5, a6, a7);
  }
  v17 = 3;
  do {
    dword_1700484 += 100;
    SV_RunFrame(a1, a2, a3, a4, a5, a6, a7);
    --v17;
  } while (v17);
  if (unk_1700324 > 1) {
    v38 = 1;
    v39 = sv;
    for (i = 1;; i = v38) {
      v33 = (_BYTE *)SV_GentityNum(i);
      __src = v33;
      if (v33[240]) {
        *(_DWORD *)v33 = i;
        memcpy(v39 + 2404, v33, 0xF0u);
        v39[2464] = *((unsigned __int8 *)__src + 242);
        v39[2465] = __src[61];
        v39[2466] = __src[62];
        v30 = 93 * i;
        v31 = &sv[93 * i + 2374];
        a2.i32[0] = __src[72];
        *v31 = a2.i32[0];
        v31[1] = __src[73];
        v31[2] = __src[74];
        v32 = &sv[v30 + 2372];
        v32[5] = __src[75];
        v32[6] = __src[76];
        v32[7] = __src[77];
      }
      ++v38;
      v39 += 93;
      if (v38 >= unk_1700324)
        break;
    }
  }
  if (*(int *)(sv_maxclients + 8) > 0) {
    v18 = 0;
    v19 = 0;
    while (1) {
      if (*(int *)((char *)&dword_170048C->state + v19) <= 1)
        goto LABEL_23;
      v20 = (char *)ClientConnect(a1, a2.f32[0], a3, a4, a5, a6, a7, v18,
                                  *(_WORD *)&dword_170048C->pad0[v19 + 2]);
      if (v20) {
        SV_DropClient(a2.f32[0], (client_s *)((char *)dword_170048C + v19),
                      v20);
      LABEL_23:
        ++v18;
        v19 += 495372;
        if (*(_DWORD *)(sv_maxclients + 8) <= v18)
          break;
      } else {
        *(int32_t *)((char *)&dword_170048C->state + v19) = 2;
        ++v18;
        v19 += 495372;
        if (*(_DWORD *)(sv_maxclients + 8) <= v18)
          break;
      }
    }
  }
  if (*(_BYTE *)(sv_pure + 8)) {
    v21 = FS_LoadedIwdChecksums();
    Dvar_SetString(sv_iwds, v21);
    if (!*v21)
      Com_Printf("WARNING: sv_pure set but no IWD files loaded\n");
    v22 = FS_LoadedIwdNames();
    Dvar_SetString(sv_iwdNames, v22);
  } else {
    Dvar_SetString(sv_iwds, (char *)&inData);
    Dvar_SetString(sv_iwdNames, (char *)&inData);
  }
  v23 = FS_ReferencedIwdChecksums();
  Dvar_SetString(sv_referencedIwds, v23);
  v24 = FS_ReferencedIwdNames();
  Dvar_SetString(sv_referencedIwdNames, v24);
  v25 = Dvar_InfoString_Big(8u);
  I_strncpyz(__dst, v25, 0x2000);
  dvar_modifiedFlags &= ~8u;
  SV_SetConfigstring(a1, a2.f32[0], a3, a4, a5, a6, a7, 1u, __dst);
  v26 = Dvar_InfoString(0x404u);
  SV_SetConfigstring(a1, a2.f32[0], a3, a4, a5, a6, a7, 0, v26);
  dvar_modifiedFlags &= 0xFFFFFBFB;
  SV_SetConfig(a1, a2.f32[0], a3, a4, a5, a6, a7, 0x8Eu, 96, 256);
  dvar_modifiedFlags &= ~0x100u;
  sv[0] = 2;
  SV_Heartbeat_f();
  Com_Printf("-----------------------------------\n");
}

void __cdecl SV_Init() { UNIMPLEMENTED(); }

int sv_serverId_value;
void __cdecl SV_FreeArchivedSnapshot(void) { UNIMPLEMENTED(); }

void __cdecl SV_SaveSystemInfo(void) { UNIMPLEMENTED(); }

SV_SetExpectedHunkUsage(char *mapname) { UNIMPLEMENTED(); }
