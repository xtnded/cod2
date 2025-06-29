int __cdecl SV_GetClientPing(int clientNum) {
  return *(_DWORD *)&dword_170048C->frames[495372 * a1 + 317570];
}

int __cdecl SV_GetGuid(int clientNum) {
  if (a1 < 0 || a1 >= *(_DWORD *)(sv_maxclients + 8))
    return 0;
  else
    return *(_DWORD *)&dword_170048C->scriptId[495372 * a1];
}

int __cdecl SV_MapExists(char const *name) {
  char *MapBaseName;  // ebx
  char *BspExtension; // eax
  char *v3;           // eax

  MapBaseName = SV_GetMapBaseName(a1);
  BspExtension = GetBspExtension();
  v3 = va("maps/mp/%s.%s", MapBaseName, BspExtension);
  return (FS_ReadFile(v3, 0) & 0x80000000) == 0;
}

void __cdecl SV_ResetSkeletonCache() {
  int v0;              // eax
  unsigned int result; // eax

  v0 = 1;
  if (unk_1700330 != -1)
    v0 = unk_1700330 + 1;
  unk_1700330 = v0;
  result = (unsigned int)&unk_E8700F & 0xFFFFFFF0;
  g_sv_skel_memory_start = (unsigned int)&unk_E8700F & 0xFFFFFFF0;
  unk_1700334 = 0;
  return result;
}

void __cdecl SV_GetUsercmd(int clientNum, struct usercmd_s *cmd) {
  client_s *v2; // ecx
  int result;   // eax

  v2 = dword_170048C;
  a2->serverTime = *(&dword_170048C->lastUsercmd.serverTime + 123843 * a1);
  a2->buttons = *(&v2->lastUsercmd.buttons + 123843 * a1);
  *(_DWORD *)&a2->weapon = *((_DWORD *)&v2->lastUsercmd.weapon + 123843 * a1);
  a2->angles[0] = v2->lastUsercmd.angles[123843 * a1];
  a2->angles[1] = v2->lastUsercmd.angles[123843 * a1 + 1];
  a2->angles[2] = v2->lastUsercmd.angles[123843 * a1 + 2];
  result = LODWORD(v2->lastUsercmd.angles[123843 * a1 + 3]);
  *(_DWORD *)&a2->forwardmove = result;
  return result;
}

void __cdecl SV_LocateGameData(struct gentity_s *gEnts, int numGEntities,
                               int sizeofGEntity_t,
                               struct playerState_s *clients,
                               int sizeofGameClient) {
  int result; // eax

  unk_170031C = a1;
  unk_1700320 = a3;
  unk_1700324 = a2;
  unk_1700328 = a4;
  result = a5;
  unk_170032C = a5;
  return result;
}

struct playerState_s *__cdecl SV_GameClientNum(int num) {
  return unk_1700328 + unk_170032C * a1;
}

struct gentity_s *__cdecl SV_GentityNum(int) {
  return unk_170031C + unk_1700320 * a1;
}

int __cdecl SV_NumForGentity(struct gentity_s *) { UNIMPLEMENTED(); }

int __cdecl SV_IsLocalClient(int clientNum) {
  netadr_t v2; // [esp+0h] [ebp-28h]

  v2.type =
      *(_DWORD *)((char *)&loc_6E5C4 + (_DWORD)dword_170048C + 495372 * a1);
  v2.ip = *(int32_t *)((char *)&dword_170048C->netchan.remoteAddress.ip +
                       495372 * a1 + 2);
  v2.port = *(&dword_170048C->netchan.qport + 123843 * a1);
  return NET_IsLocalAddress(v2);
}

void __cdecl SV_SetWeaponInfoMemory() { return Com_SetWeaponInfoMemory(1); }

int __cdecl SV_DObjExists(struct gentity_s *ent) {
  return Com_GetServerDObj(a1->s.number) != 0;
}

void __cdecl SV_ResetEntityParsePoint() {
  int result; // eax

  result = CM_EntityString();
  unk_1700318 = result;
  return result;
}

struct XAnimTree_s *__cdecl SV_DObjGetTree(struct gentity_s *ent) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (ServerDObj)
    return DObjGetTree(ServerDObj);
  else
    return 0;
}

int __cdecl SV_DObjSetControlRotTransIndex(struct gentity_s *, int *const,
                                           int) {
  UNIMPLEMENTED();
}

int __cdecl SV_DObjSetRotTransIndex(struct gentity_s *, int *const, int) {
  UNIMPLEMENTED();
}

struct DObjAnimMat_s *__cdecl SV_DObjGetRotTransArray(struct gentity_s *) {
  UNIMPLEMENTED();
}

struct DObjAnimMat_s *__cdecl SV_DObjGetMatrixArray(struct gentity_s *ent) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  return DObjGetRotTransArray(ServerDObj);
}

int __cdecl SV_DObjGetBoneIndex(struct gentity_s *ent, unsigned int boneName) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (ServerDObj)
    return DObjGetBoneIndex(ServerDObj, a2);
  else
    return -1;
}

int __cdecl SV_DObjNumBones(struct gentity_s *) { UNIMPLEMENTED(); }

struct gentity_s *__cdecl SV_GEntityForSvEntity(struct svEntity_s *svEnt) {
  return unk_170031C +
         unk_1700320 * 1062196213 * (((char *)a1 - (char *)&unk_16A3318) >> 2);
}

void __cdecl SV_FreeWeaponInfoMemory(void) { UNIMPLEMENTED(); }

int __cdecl SV_GetEntityToken(char *buffer, int bufferSize) {
  char *v2; // esi

  v2 = Com_Parse(&dword_1700318);
  I_strncpyz(__dst, v2, a2);
  return dword_1700318 || *v2;
}

void __cdecl SV_XModelDebugBoxes(struct gentity_s *ent) {
  int result;               // eax
  const XModel *Model;      // eax
  float *v3;                // eax
  int v4;                   // edx
  XBoneInfo_s *v5;          // ebx
  float v6;                 // xmm3_4
  float v7;                 // xmm5_4
  float v8;                 // xmm1_4
  float v9;                 // xmm6_4
  float v10;                // xmm4_4
  float v11;                // xmm2_4
  float v12;                // xmm7_4
  float v13;                // xmm0_4
  float v14;                // xmm3_4
  float v15;                // xmm6_4
  float v16;                // xmm5_4
  float v17;                // xmm2_4
  _DWORD *v18;              // edi
  char **v19;               // esi
  float *v20;               // [esp+3Ch] [ebp-2DCh]
  int32_t RotTransArray;    // [esp+40h] [ebp-2D8h]
  const DObj_s *ServerDObj; // [esp+44h] [ebp-2D4h]
  int v23;                  // [esp+48h] [ebp-2D0h]
  int v24;                  // [esp+4Ch] [ebp-2CCh]
  int v25;                  // [esp+50h] [ebp-2C8h]
  int v26;                  // [esp+54h] [ebp-2C4h]
  float v27;                // [esp+58h] [ebp-2C0h]
  float v28;                // [esp+5Ch] [ebp-2BCh]
  XBoneInfo_s *v29[128];    // [esp+6Ch] [ebp-2ACh] BYREF
  float v30[12];            // [esp+26Ch] [ebp-ACh] BYREF
  float v31[9];             // [esp+29Ch] [ebp-7Ch] BYREF
  float v32[4];             // [esp+2C0h] [ebp-58h] BYREF
  float v33;                // [esp+2D0h] [ebp-48h] BYREF
  float v34;                // [esp+2D4h] [ebp-44h]
  float v35;                // [esp+2D8h] [ebp-40h]
  float v36;                // [esp+2DCh] [ebp-3Ch] BYREF
  float v37;                // [esp+2E0h] [ebp-38h]
  float v38;                // [esp+2E4h] [ebp-34h]
  float v39[3];             // [esp+2E8h] [ebp-30h] BYREF
  float v40;                // [esp+2F4h] [ebp-24h] BYREF
  float v41;                // [esp+2F8h] [ebp-20h]
  float v42;                // [esp+2FCh] [ebp-1Ch]

  ServerDObj = Com_GetServerDObj(a1->s.number);
  DObjNumBones(ServerDObj);
  DObjGetBoneInfo(ServerDObj, v29);
  RotTransArray = DObjGetRotTransArray(ServerDObj);
  v32[0] = 1.0;
  v32[1] = 1.0;
  v32[2] = 1.0;
  v32[3] = 0.0;
  AnglesToAxis(a1->r.currentAngles, v31);
  result = DObjGetNumModels(ServerDObj);
  v23 = result;
  if (result > 0) {
    v24 = 0;
    LOBYTE(result) = 0;
    do {
      if (!(unsigned __int8)DObjIgnoreCollision(ServerDObj, result)) {
        Model = (const XModel *)DObjGetModel(ServerDObj, v24);
        v25 = XModelNumBones(Model);
        if (v25 > 0) {
          v26 = 0;
          v3 = (float *)(RotTransArray + 16);
          v20 = (float *)(RotTransArray + 16);
          v4 = 0;
          while (1) {
            v5 = v29[v4];
            v6 = v3[3] * *(v3 - 4);
            v7 = v3[3] * *(v3 - 3);
            v8 = v3[3] * *(v3 - 2);
            v27 = v6 * *(v3 - 4);
            v9 = *(v3 - 3);
            v10 = v6 * v9;
            v11 = *(v3 - 2);
            v12 = v6 * v11;
            v13 = *(v3 - 1);
            v14 = v6 * v13;
            v28 = v9 * v7;
            v15 = v7 * v11;
            v16 = v7 * v13;
            v17 = v11 * v8;
            v30[0] = 1.0 - (float)(v28 + v17);
            v30[1] = (float)(v8 * v13) + v10;
            v30[2] = v12 - v16;
            v30[3] = v10 - (float)(v8 * v13);
            v30[4] = 1.0 - (float)(v17 + v27);
            v30[5] = v14 + v15;
            v30[6] = v12 + v16;
            v30[7] = v15 - v14;
            v30[8] = 1.0 - (float)(v27 + v28);
            v30[9] = *v3;
            v30[10] = v3[1];
            v30[11] = v3[2];
            v18 = &unk_311C4C;
            v19 = (char **)&boxVerts_1;
            do {
              v40 = v5->bounds[(_DWORD)*v19][0];
              v41 = v5->bounds[(_DWORD)v19[1]][1];
              v42 = v5->bounds[(_DWORD)v19[2]][2];
              MatrixTransformVector43(&v40, (const float(*)[3])v30, v39);
              MatrixTransformVector(v39, v31, &v36);
              v36 = v36 + a1->r.currentOrigin[0];
              v37 = v37 + a1->r.currentOrigin[1];
              v38 = v38 + a1->r.currentOrigin[2];
              v40 = v5->bounds[*v18][0];
              v41 = v5->bounds[v18[1]][1];
              v42 = v5->bounds[v18[2]][2];
              MatrixTransformVector43(&v40, (const float(*)[3])v30, v39);
              MatrixTransformVector(v39, v31, &v33);
              v33 = v33 + a1->r.currentOrigin[0];
              v34 = v34 + a1->r.currentOrigin[1];
              v35 = v35 + a1->r.currentOrigin[2];
              CL_AddDebugLine(&v36, &v33, v32, 0, 0, 1);
              v19 += 6;
              v18 += 6;
            } while (v19 != serverStatusDvars);
            ++v26;
            RotTransArray += 32;
            v20 += 8;
            v4 = v26;
            if (v25 == v26)
              break;
            v3 = v20;
          }
        }
      }
      result = ++v24;
    } while (v23 != v24);
  }
  return result;
}

void __cdecl SV_GameSendServerCommand(int clientNum, enum svscmd_type type,
                                      char const *text) {
  if (a1 == -1) {
    SV_SendServerCommand(0, a2, "%s", a3);
  } else if (a1 >= 0 && a1 < *(_DWORD *)(sv_maxclients + 8)) {
    SV_SendServerCommand((client_s *)((char *)dword_170048C + 495372 * a1), a2,
                         "%s", a3);
  }
}

int __cdecl SV_EntityContact(float const *const mins, float const *const maxs,
                             struct gentity_s const *gEnt) {
  int8_t svFlags; // al
  float v4;       // xmm1_4
  float v6;       // xmm1_4
  float *v7;      // eax
  float v8;       // xmm1_4
  float v9;       // [esp+30h] [ebp-68h]
  float v10;      // [esp+30h] [ebp-68h]
  float v11;      // [esp+48h] [ebp-50h]
  float v12;      // [esp+4Ch] [ebp-4Ch]
  trace_t v13;    // [esp+54h] [ebp-44h] BYREF
  float v14;      // [esp+78h] [ebp-20h] BYREF
  float v15;      // [esp+7Ch] [ebp-1Ch]

  svFlags = a3->r.svFlags;
  if ((svFlags & 0x60) != 0) {
    if ((svFlags & 0x20) != 0) {
      v4 = a3->r.currentOrigin[2];
      if (v4 < a2[2] && a1[2] < (float)(v4 + a3->r.maxs[2])) {
        v8 = a1[1] + a2[1];
        v14 = (float)(*a1 + *a2) * 0.5;
        v15 = v8 * 0.5;
        v10 = (float)(*a2 - v14) + a3->r.maxs[0];
        v11 = Vec2DistanceSq(a3->r.currentOrigin, &v14);
        return (float)(v10 * v10) > v11;
      } else {
        return 0;
      }
    } else {
      v6 = a1[1] + a2[1];
      v14 = (float)(*a1 + *a2) * 0.5;
      v15 = v6 * 0.5;
      v9 = (float)((float)(*a2 - v14) + a3->r.maxs[0]) - 64.0;
      v12 = Vec2DistanceSq(a3->r.currentOrigin, &v14);
      return v12 >= (float)(v9 * v9);
    }
  } else {
    v7 = (float *)SV_ClipHandleForEntity(a3);
    CM_TransformedBoxTraceExternal(&v13, vec3_origin, vec3_origin, a1, a2, v7,
                                   (float *)0xFFFFFFFF, a3->r.currentOrigin,
                                   a3->r.currentAngles);
    return (unsigned __int8)v13.startsolid;
  }
}

int __cdecl SV_GameCommand() {
  if (sv == 2)
    return ConsoleCommand();
  else
    return 0;
}

void __cdecl SV_DObjInitServerTime(struct gentity_s *ent, float dtime) {
  DObj_s *result; // eax

  result = Com_GetServerDObj(a1->s.number);
  if (result)
    return (DObj_s *)DObjInitServerTime(result, a2);
  return result;
}

void __cdecl SV_Hunk_FreeTempMemoryInternal(void *) { UNIMPLEMENTED(); }

void *__cdecl SV_Hunk_AllocateTempMemoryInternal(int) { UNIMPLEMENTED(); }

void *__cdecl SV_Hunk_AllocAlignInternal(int, int) { UNIMPLEMENTED(); }

void *__cdecl SV_Hunk_AllocInternal(int) { UNIMPLEMENTED(); }

void __cdecl SV_GetServerinfo(char *buffer, int bufferSize) { UNIMPLEMENTED(); }

struct svEntity_s *__cdecl SV_SvEntityForGentity(struct gentity_s const *) {
  signed int number; // eax
  char v3;           // [esp+8h] [ebp-10h]

  if (!a1 || (number = a1->s.number, (a1->s.number & 0x80000000) != 0) ||
      number > 1023) {
    Com_Error(1, "\x15SV_SvEntityForGentity: bad gEnt", v3);
    number = a1->s.number;
  }
  return (char *)&sv + 372 * number + 9240;
}

struct XModel *__cdecl SV_XModelGet(char const *name) {
  UNIMPLEMENTED();
}

int __cdecl SV_inSnapshot(float const *const origin, int iEntityNum) {
  UNIMPLEMENTED();
}

void __cdecl SV_SetBrushModel(struct gentity_s *ent) {
  float v2[3]; // [esp+18h] [ebp-20h] BYREF
  float v3[5]; // [esp+24h] [ebp-14h] BYREF

  CM_ModelBounds(a1->s.index.item, v3, v2);
  a1->r.mins[0] = v3[0];
  a1->r.mins[1] = v3[1];
  a1->r.mins[2] = v3[2];
  a1->r.maxs[0] = v2[0];
  a1->r.maxs[1] = v2[1];
  a1->r.maxs[2] = v2[2];
  a1->r.bmodel = 1;
  a1->r.contents = -1;
  return SV_LinkEntity(a1);
}

void __cdecl SV_SetGametype() {
  char v0;        // al
  char *v1;       // ebx
  char __dst[72]; // [esp+10h] [ebp-48h] BYREF

  Dvar_RegisterString("g_gametype", (DvarValue) "dm", 0x1024u);
  if (*(_BYTE *)(com_sv_running + 8) && G_GetSavePersist())
    I_strncpyz(__dst, (char *)&dword_1700390[25], 64);
  else
    I_strncpyz(__dst, *(char **)(sv_gametype + 8), 64);
  v0 = __dst[0];
  if (__dst[0]) {
    v1 = __dst;
    do {
      *v1++ = __tolower(v0);
      v0 = *v1;
    } while (*v1);
  }
  if (!Scr_IsValidGameType(__dst)) {
    Com_Printf("g_gametype %s is not a valid gametype, defaulting to dm\n",
               __dst);
    strcpy(__dst, "dm");
  }
  Dvar_SetString((dvar_s *)sv_gametype, __dst);
}

void __cdecl SV_DObjDumpInfo(struct gentity_s *ent) {
  DObj_s *ServerDObj; // eax

  if (*(_DWORD *)(com_developer + 8)) {
    ServerDObj = Com_GetServerDObj(a1->s.number);
    if (ServerDObj)
      DObjDumpInfo(ServerDObj);
    else
      Com_Printf("no model.\n");
  }
}

void __cdecl SV_DObjDisplayAnim(struct gentity_s *ent) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (ServerDObj)
    DObjDisplayAnim(ServerDObj);
}

void __cdecl SV_DObjCalcSkel(struct gentity_s *ent, int *const partBits) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  return DObjCalcSkel(ServerDObj, a2);
}

void __cdecl SV_DObjCalcAnim(struct gentity_s *ent, int *const partBits) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  DObjCalcAnim(ServerDObj, a2);
}

void __cdecl SV_DObjGetHierarchyBits(struct gentity_s *ent, int boneIndex,
                                     int *const partBits) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  return DObjGetHierarchyBits(ServerDObj, a2, a3);
}

int __cdecl SV_DObjCreateSkelForBones(struct gentity_s *ent,
                                      int *const partBits) {
  unsigned int v3;          // ebx
  char *v4;                 // esi
  uint32_t v5;              // edx
  uint32_t v6;              // edx
  uint32_t v7;              // eax
  const DObj_s *ServerDObj; // [esp+1Ch] [ebp-1Ch]

  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (DObjSkelExists(ServerDObj, dword_1700330))
    return DObjSkelAreBonesUpToDate(ServerDObj, a2);
  v3 = (DObjGetAllocSkelSize(ServerDObj) + 15) & 0xFFFFFFF0;
  v4 = (char *)(g_sv_skel_memory_start + unk_1700334);
  unk_1700334 += v3;
  if (unk_1700334 > 0x3FFF0u) {
    v4 = (char *)((unsigned int)&unk_E8700F & 0xFFFFFFF0);
    if (v3 > 0x3FFF0) {
      while (1) {
        if (dword_1700330 != SV_AllocSkelMemory(unsigned int)::warnCount) {
          SV_AllocSkelMemory(unsigned int)::warnCount = dword_1700330;
          Com_Printf("^3WARNING: SV_SKEL_MEMORY_SIZE exceeded\n");
        }
        if (!++dword_1700330)
          dword_1700330 = 1;
        g_sv_skel_memory_start = (unsigned int)&unk_E8700F & 0xFFFFFFF0;
        unk_1700334 = v3;
      }
    }
    v5 = dword_1700330;
    if (dword_1700330 != SV_AllocSkelMemory(unsigned int)::warnCount) {
      SV_AllocSkelMemory(unsigned int)::warnCount = dword_1700330;
      Com_Printf("^3WARNING: SV_SKEL_MEMORY_SIZE exceeded\n");
      v5 = dword_1700330;
    }
    v6 = v5 + 1;
    v7 = 1;
    if (v6)
      v7 = v6;
    dword_1700330 = v7;
    g_sv_skel_memory_start = (unsigned int)&unk_E8700F & 0xFFFFFFF0;
    unk_1700334 = v3;
  }
  DObjCreateSkel(ServerDObj, v4, dword_1700330);
  return 0;
}

int __cdecl SV_DObjCreateSkelForBone(struct gentity_s *ent, int boneIndex) {
  unsigned int v3;    // ebx
  char *v4;           // esi
  uint32_t v5;        // edx
  int v6;             // edx
  int v7;             // eax
  DObj_s *ServerDObj; // [esp+1Ch] [ebp-1Ch]

  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (DObjSkelExists(ServerDObj, dword_1700330))
    return DObjSkelIsBoneUpToDate(ServerDObj, a2);
  v3 = (DObjGetAllocSkelSize(ServerDObj) + 15) & 0xFFFFFFF0;
  v4 = (char *)(g_sv_skel_memory_start + unk_1700334);
  unk_1700334 += v3;
  if (unk_1700334 > 0x3FFF0u) {
    v4 = (char *)((unsigned int)&unk_E8700F & 0xFFFFFFF0);
    if (v3 > 0x3FFF0) {
      while (1) {
        if (dword_1700330 != SV_AllocSkelMemory(unsigned int)::warnCount) {
          SV_AllocSkelMemory(unsigned int)::warnCount = dword_1700330;
          Com_Printf("^3WARNING: SV_SKEL_MEMORY_SIZE exceeded\n");
        }
        if (!++dword_1700330)
          dword_1700330 = 1;
        g_sv_skel_memory_start = (unsigned int)&unk_E8700F & 0xFFFFFFF0;
        unk_1700334 = v3;
      }
    }
    v5 = dword_1700330;
    if (dword_1700330 != SV_AllocSkelMemory(unsigned int)::warnCount) {
      SV_AllocSkelMemory(unsigned int)::warnCount = dword_1700330;
      Com_Printf("^3WARNING: SV_SKEL_MEMORY_SIZE exceeded\n");
      v5 = dword_1700330;
    }
    v6 = v5 + 1;
    v7 = 1;
    if (v6)
      v7 = v6;
    dword_1700330 = v7;
    g_sv_skel_memory_start = (unsigned int)&unk_E8700F & 0xFFFFFFF0;
    unk_1700334 = v3;
  }
  DObjCreateSkel(ServerDObj, v4, dword_1700330);
  return 0;
}

int __cdecl SV_DObjUpdateServerTime(struct gentity_s *ent, float dtime,
                                    int bNotify) {
  DObj_s *ServerDObj; // eax

  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (ServerDObj)
    return DObjUpdateServerInfo(ServerDObj, a2, a3);
  else
    return 0;
}

void __cdecl SV_GameDropClient(int, char const *) { UNIMPLEMENTED(); }

void __cdecl SV_ShutdownGameProgs() {
  sv = 0;
  Com_UnloadSoundAliases(SASYS_GAME);
  if (gameInitialized) {
    G_ShutdownGame(a1, 1);
    Com_FreeWeaponInfoMemory(1);
    gameInitialized = 0;
  }
}

void __cdecl SV_InitGameProgs(int savepersist) {
  gameInitialized = 1;
  SV_InitGameVM(0, a8, a1, a2, a3, a4, a5, a6, a7);
}

void __cdecl SV_RestartGameProgs(int savepersist) {
  G_ShutdownGame(a2, 0);
  com_fixedConsolePosition = 0;
  SV_InitGameVM(1, a8, a1, a2, a3, a4, a5, a6, a7);
}

int gameInitialized;
void *__cdecl SV_AllocXModelPrecacheColl(int) {
  return Hunk_AllocInternal(__len);
}

void *__cdecl SV_AllocXModelPrecache(int) { return Hunk_AllocInternal(__len); }

char *__cdecl SV_AllocSkelMemory(unsigned int) { UNIMPLEMENTED(); }

void __cdecl SV_InitGameVM(int, int) {
  unsigned int v11; // eax
  int v12;          // ecx
  int v13;          // edx

  FX_InitServer();
  dword_1700318 = (char *)CM_EntityString();
  Sys_LoadingKeepAlive();
  v11 = Sys_MillisecondsRaw();
  G_InitGame(a3, a4, a5, a6, a7, a8, a9, dword_1700484, v11, a1, a2);
  Sys_LoadingKeepAlive();
  if (*(int *)(sv_maxclients + 8) > 0) {
    v12 = 0;
    v13 = 0;
    do {
      *(_DWORD *)&dword_170048C->lastClientCommandString[v13 + 1026] = 0;
      ++v12;
      v13 += 495372;
    } while (v12 < *(_DWORD *)(sv_maxclients + 8));
  }
  if (*(_DWORD *)(com_dedicated + 8))
    Com_DvarDump(PMSG_LOGFILE);
}
