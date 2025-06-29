void __cdecl CG_SetNextSnap(struct snapshot_t *snap)
{
  int v3;                  // ecx
  int v4;                  // ebx
  int v5;                  // edx
  int v6;                  // ebx
  char *v7;                // eax
  snapshot_t *v8;          // edx
  _DWORD *v9;              // ebx
  uint32_t clientNum;      // esi
  _DWORD *v11;             // edx
  snapshot_t *v12;         // eax
  snapshot_t *v13;         // eax
  uint8_t *v14;            // edi
  int v15;                 // ebx
  char *v16;               // esi
  snapshot_t *v17;         // edx
  int v18;                 // eax
  char *v19;               // eax
  _DWORD *v20;             // ebx
  int32_t *v21;            // edi
  int32_t *i;              // edx
  int32_t *v23;            // edi
  int32_t v24;             // eax
  char *v25;               // ebx
  char *ConfigString;      // ebx
  int32_t *v27;            // esi
  char *v28;               // edi
  char *v29;               // ebx
  char *v30;               // ebx
  const char *v31;         // eax
  char *v32;               // eax
  snapshot_t *v33;         // ebx
  signed int v34;          // esi
  snapshot_t *v35;         // ebx
  signed int v36;          // esi
  entityState_s *v37;      // edi
  _DWORD *v38;             // edx
  _DWORD *v39;             // ebx
  int v40;                 // eax
  int v41;                 // ebx
  int v42;                 // esi
  char *v43;               // edx
  char *v44;               // eax
  unsigned int v45;        // edi
  const XAnim_s *Anims;    // eax
  int32_t *p_fTorsoHeight; // [esp+1Ch] [ebp-43Ch]
  char *__s1;              // [esp+20h] [ebp-438h]
  playerState_s *__src;    // [esp+24h] [ebp-434h]
  char *v50;               // [esp+28h] [ebp-430h]
  int v51;                 // [esp+2Ch] [ebp-42Ch]
  XAnim_s *v52;            // [esp+30h] [ebp-428h]
  XAnimTree_s *v53;        // [esp+34h] [ebp-424h]
  signed int v54;          // [esp+38h] [ebp-420h]
  signed int v55;          // [esp+3Ch] [ebp-41Ch]
  _BYTE __b[1048];         // [esp+40h] [ebp-418h] BYREF

  memset(__b, 0, 0x400u);
  v3 = *((_DWORD *)cg + 9);
    if (v3) {
        if (*(int *)(v3 + 9908) > 0) {
          v4 = 0;
            do {
              v5 = *(_DWORD *)(240 * v4 + v3 + 9916);
              *((_BYTE *)cg_entities + 548 * v5 + 480) = 0;
              __b[v5] = 1;
              ++v4;
              v3 = *((_DWORD *)cg + 9);
            }
          while (v4 < *(_DWORD *)(v3 + 9908));
        }
      v6 = *(_DWORD *)(v3 + 216);
      v7 = (char *)cg_entities + 548 * v6;
        if (v7[480]) {
          v7[480] = 0;
          __b[v6] = 1;
        }
    }
  *((_DWORD *)cg + 9) = a3;
    if (!a3) {
      CG_ClearSolidList();
      return;
    }
  CL_ResetSkeletonCache(0);
  CG_SetFrameInterpolation();
  CG_ExecuteNewServerCommands(a2, *(_DWORD *)a3->serverCommandSequence);
  CG_CheckOpenWaitingScriptMenu();
    if ((int)a3->numClients > 0) {
      v54 = 0;
      p_fTorsoHeight = &a3->entities[255].fTorsoHeight;
      v21 = &a3->entities[255].fTorsoHeight;
        for (i = &a3->entities[255].fTorsoHeight;; i = p_fTorsoHeight) {
          v23 = v21 + 3;
          v50 = (char *)cg + 1208 * i[3] + 919828;
          if (*(_DWORD *)v50)
            v24 = *((_DWORD *)cg + 302 * i[3] + 229968);
          else
            v24 = p_fTorsoHeight[4];
          *((_DWORD *)cg + 302 * i[3] + 229969) = v24;
          *(_DWORD *)v50 = 1;
          *((_DWORD *)v50 + 1) = 1;
          *((_DWORD *)v50 + 2) = p_fTorsoHeight[3];
          *((_DWORD *)v50 + 11) = p_fTorsoHeight[4];
          v25 = v50 + 12;
            if (strcmp(v50 + 12, (const char *)v23 + 60)) {
                if (v50[12]) {
                  v31 = UI_SafeTranslateString("CGAME_PLAYERRENAMES");
                  v32 = va("%s^7 %s %s", v25, v31, (const char *)v23 + 60);
                  CG_GameMessage(v32);
                }
              I_strncpyz(v25, (char *)v23 + 60, 32);
            }
          ConfigString = CL_GetConfigString(p_fTorsoHeight[5] + 334);
            if (strcmp(v50 + 64, ConfigString)) {
              I_strncpyz(v50 + 64, ConfigString, 64);
              *((_DWORD *)v50 + 254) = 1;
            }
          v27 = v23;
          v51 = 0;
          __s1 = v50 + 512;
          v28 = v50 + 128;
            do {
                while (1) {
                  v30 = CL_GetConfigString(v27[3] + 334);
                    if (strcmp(v28, v30)) {
                      I_strncpyz(v28, v30, 64);
                      *((_DWORD *)v50 + 254) = 1;
                    }
                  v29 = CL_GetConfigString(v27[9] + 110);
                  if (strcmp(__s1, v29))
                    break;
                  ++v51;
                  v28 += 64;
                  __s1 += 64;
                  ++v27;
                  if (v51 == 6)
                    goto LABEL_51;
                }
              I_strncpyz(__s1, v29, 64);
              *((_DWORD *)v50 + 254) = 1;
              ++v51;
              v28 += 64;
              __s1 += 64;
              ++v27;
            }
          while (v51 != 6);
        LABEL_51:
          ++v54;
          p_fTorsoHeight += 23;
          if ((signed int)a3->numClients <= v54)
            break;
          v21 = p_fTorsoHeight;
        }
      v8 = a3;
    }
    else {
      v8 = a3;
    }
  v9 = cg;
  *((_DWORD *)cg + 44919) = *(_DWORD *)&v8->ps.stats[12];
  *(_DWORD *)((char *)&loc_2BDE0 + (_DWORD)v9) = *(_DWORD *)&v8->ps.stats[16];
  clientNum = v8->ps.clientNum;
    if ((v8->ps.pm_flags & 0xC00000) != 0) {
      v37 = (entityState_s *)((char *)cg_entities + 548 * clientNum);
      v37[1].number = (unsigned __int16)clientNum;
      __src = &a3->ps;
      BG_PlayerStateToEntityState(&a3->ps, v37 + 1, 0, 0);
      LOBYTE(v37[2].number) = 1;
        if (v9[38639]) {
          v38 = (_DWORD *)v9[8];
        }
        else {
          v38 = (_DWORD *)v9[8];
            if (*(_DWORD *)&a3->ps.stats[20] == v38[83] &&
                clientNum == v38[54]) {
                if (!__b[clientNum] ||
                    ((LOBYTE(v37[1].eFlags) ^ LOBYTE(v37->eFlags)) & 2) != 0) {
                  memcpy(v38 + 3, __src, 0x26A8u);
                  CG_ResetEntity((int)v37, a2);
                  v9[41265] = 0;
                  v9[41266] = 0;
                  v9[41267] = 0;
                }
              goto LABEL_15;
            }
        }
      memcpy(v38 + 3, __src, 0x26A8u);
      CG_ResetEntity((int)v37, a2);
      CG_Respawn();
    }
    else {
        if (v9[38639]) {
          v11 = (_DWORD *)v9[8];
          v12 = a3;
        }
        else {
          v11 = (_DWORD *)v9[8];
            if (*(_DWORD *)&a3->ps.stats[20] == v11[83]) {
              if (clientNum == v11[54])
                goto LABEL_15;
              v12 = a3;
            }
            else {
              v12 = a3;
            }
        }
      memcpy(v11 + 3, &v12->ps, 0x26A8u);
      CG_Respawn();
    }
LABEL_15:
  v13 = a3;
    if ((int)a3->numEntities > 0) {
      v55 = 0;
      v14 = &a3->ps.hud.archival[3964];
        do {
          v15 = *((_DWORD *)v14 + 3);
          v16 = (char *)cg_entities + 548 * v15;
          memcpy(v16 + 240, v14 + 12, 0xF0u);
          v16[480] = 1;
          if (!__b[v15] || ((v14[20] ^ (unsigned __int8)v16[8]) & 2) != 0)
            CG_ResetEntity((int)v16, a2);
          ++v55;
          v14 += 240;
          v13 = a3;
        }
      while ((signed int)a3->numEntities > v55);
    }
    if ((int)v13->numClients > 0) {
      v35 = v13;
      v36 = 0;
        do {
          CG_UpdatePlayerDObj(a2, (centity_s *)cg_entities +
                                      v35->clients[0].clientIndex);
          ++v36;
          v35 = (snapshot_t *)((char *)v35 + 92);
        }
      while (v36 < (signed int)a3->numClients);
      v17 = a3;
    }
    else {
      v17 = v13;
    }
  v18 = *(_DWORD *)v17->ps.viewmodelIndex;
    if (v18 > 0) {
      v19 = CL_GetConfigString(v18 + 334);
      CG_UpdateHandViewmodels(a2, v19);
    }
  CG_BuildSolidList();
  v20 = cg;
  if (*((_DWORD *)cg + 45893))
    goto LABEL_85;
    if (*(_DWORD *)(*((_DWORD *)cg + 9) + 1968)) {
      *((_DWORD *)cg + 45893) = 1;
      CG_SetEquippedOffHand(0);
      CG_PlaySmokeGrenadesAtTime(a1,
                                 *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v20));
    }
    if (v20[45893]) {
    LABEL_85:
        if (!*(_DWORD *)(v20[9] + 1968)) {
          v20[45893] = 0;
          v39 = cg;
          CG_PlaySmokeGrenadesAtTime(
              a1, *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg));
          v40 = v39[9];
            if (*(int *)(v40 + 9908) > 0) {
              v41 = 0;
              v42 = 0;
                do {
                  v43 =
                      (char *)cg_entities + 548 * *(_DWORD *)(v42 + v40 + 9916);
                    if (*((_DWORD *)v43 + 61) == 2) {
                      v44 = (char *)cgs + 1208 * *((_DWORD *)v43 + 60) - 27628;
                      v53 = (XAnimTree_s *)*((_DWORD *)v44 + 297);
                      v45 = *((_DWORD *)v44 + 228) & 0xFFFFFDFF;
                      Anims = (const XAnim_s *)XAnimGetAnims(v53);
                      v52 = (XAnim_s *)Anims;
                        if (v45) {
                          if (!(unsigned __int8)XAnimIsLooped(Anims, v45) &&
                              !XAnimGetNumChildren(v52, v45))
                            XAnimSetTime(v53, v45, 1.0);
                        }
                    }
                  ++v41;
                  v42 += 240;
                  v40 = *((_DWORD *)cg + 9);
                }
              while (v41 < *(_DWORD *)(v40 + 9908));
            }
        }
    }
    if ((int)a3->numEntities > 0) {
      v33 = a3;
      v34 = 0;
        do {
          CG_CheckEvents(a2,
                         (centity_s *)cg_entities + v33->entities[0].number);
          ++v34;
          v33 = (snapshot_t *)((char *)v33 + 240);
        }
      while (v34 < (signed int)a3->numEntities);
    }
    if (*((_DWORD *)cg + 2) ||
        (*(_BYTE *)(*((_DWORD *)cg + 9) + 26) & 0x40) != 0 ||
        *(_BYTE *)(cg_nopredict + 8) || *(_BYTE *)(cg_synchronousClients + 8)) {
      CG_TransitionPlayerState(a2, (playerState_s *)(*((_DWORD *)cg + 9) + 12),
                               (playerState_s *)(*((_DWORD *)cg + 8) + 12));
    }
}

void __cdecl CG_SetInitialSnapshot(struct snapshot_t *snap)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ProcessSnapshots()
{
  _DWORD *v5;      // ebx
  int v6;          // eax
  char *v7;        // edi
  int v8;          // ecx
  _DWORD *v9;      // ebx
  int v10;         // edx
  _DWORD *v11;     // esi
  int v12;         // ecx
  char *v13;       // edx
  snapshot_t *v14; // ebx
  _DWORD *v15;     // ebx
  int v16;         // eax
  int v17;         // edi
  int v18;         // eax
  _DWORD *v19;     // esi
  int v20;         // ebx
  _DWORD *v21;     // ebx
  _DWORD *v22;     // eax
  int v23;         // esi
  int v24;         // ebx
  char *v25;       // eax
  char *v26;       // ebx
  int v27;         // ecx
  _DWORD *v28;     // esi
  int v29;         // edx
  int v30;         // ecx
  char *v31;       // edx
  snapshot_t *v32; // ebx
  _DWORD *v33;     // edx
  int v34;         // eax
  _DWORD *v35;     // ebx
  int v36;         // ecx
  int v37;         // edx
  int v38;         // edi
  int v39;         // edx
  _DWORD *v40;     // esi
  int v41;         // ebx
  _DWORD *v42;     // ebx
  _DWORD *v43;     // eax
  int v44;         // esi
  int v45;         // ebx
  char *v46;       // eax
  _DWORD *v47;     // esi
  int v48;         // edx
  _DWORD *v49;     // ebx
  int v50;         // eax
  int v51;         // edi
  int v52;         // eax
  _DWORD *v53;     // esi
  int v54;         // ebx
  _DWORD *v55;     // ebx
  _DWORD *v56;     // eax
  int v57;         // ebx
  int v58;         // esi
  char *v59;       // eax
  char v60;        // [esp+8h] [ebp-60h]
  int v61;         // [esp+24h] [ebp-44h]
  int v62;         // [esp+28h] [ebp-40h]
  int v63;         // [esp+34h] [ebp-34h]
  int v64;         // [esp+38h] [ebp-30h]
  int v65;         // [esp+3Ch] [ebp-2Ch]
  int v66[7];      // [esp+4Ch] [ebp-1Ch] BYREF

  v5 = cg;
  CL_GetCurrentSnapshotNumber(v66, (int *)cg + 7);
  v6 = v66[0];
    if (v5[6] != v66[0]) {
        if (v5[6] > v66[0]) {
          Com_Error(1, "\x15CG_ProcessSnapshots: n < cg->latestSnapshotNum",
                    v60);
          v6 = v66[0];
        }
      v5[6] = v6;
    }
  *((_DWORD *)cg + 229950) = *((_DWORD *)cg + 7);
    while (1) {
      v7 = (char *)cg;
        if (*((_DWORD *)cg + 8)) {
          CG_SetFrameInterpolation();
            while (1) {
              v26 = (char *)cg;
              if (*((_DWORD *)cg + 9) != *((_DWORD *)cg + 8) &&
                  !*((_DWORD *)cg + 3))
                goto LABEL_42;
              v27 = *((_DWORD *)cg + 6);
              v28 = cgs;
              v29 = *((_DWORD *)cgs + 6055);
                if (v27 > v29 + 1000) {
                  Com_Printf("WARNING: CG_ReadNextSnapshot: way out of range, "
                             "%i > %i\n",
                             v27, *((_DWORD *)cgs + 6055));
                  v29 = v28[6055];
                }
              v30 = v29;
              v31 = v26;
              if (*((_DWORD *)v26 + 6) <= v30)
                goto LABEL_40;
                while (1) {
                  v32 = (snapshot_t *)(v31 + 40);
                  if (*((char **)v31 + 8) == v31 + 40)
                    v32 = (snapshot_t *)(v31 + 77288);
                  v28[6055] = v30 + 1;
                  v28 = cgs;
                  if (CL_GetSnapshot(*((_DWORD *)cgs + 6055), v32))
                    break;
                  CG_AddLagometerSnapshotInfo(0);
                  v30 = v28[6055];
                  v31 = (char *)cg;
                  if (*((_DWORD *)cg + 6) <= v30)
                    goto LABEL_40;
                }
              CG_AddLagometerSnapshotInfo(v32);
                if (!v32) {
                LABEL_40:
                  v33 = cg;
                  v34 = *(_DWORD *)(*((_DWORD *)cg + 8) + 8);
                    if (*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v34 <
                        0) {
                      *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) = v34;
                      v33[229949] = v34;
                    }
                  return;
                }
              v47 = cg;
              v48 = *((_DWORD *)cg + 9);
                if (((*(_BYTE *)v48 ^ LOBYTE(v32->snapFlags)) & 4) != 0) {
                  CG_SetInitialSnapshot(a1, a2, a3, a4, a5, v32);
                  CG_SetNextSnap(a1, a2, v32);
                  v49 = v47;
                  v50 = v47[8];
                    if (*(int *)(v50 + 9912) > 0) {
                      v65 = 0;
                      v62 = 71344;
                        do {
                          v51 = v50 + v62;
                          v52 = *(_DWORD *)(v50 + v62 + 12);
                          v53 = &v49[302 * v52 + 229957];
                            if (v49[302 * v52 + 229958]) {
                              v49[302 * v52 + 229958] = 0;
                            }
                            else {
                              v54 = v49[302 * v52 + 230254];
                              memset(v53, 0, 0x4B8u);
                              v53[297] = v54;
                              CG_SafeDObjFree(a2, *(_DWORD *)(v51 + 12));
                            }
                          ++v65;
                          v62 += 92;
                          v49 = cg;
                          v50 = *((_DWORD *)cg + 8);
                        }
                      while (v65 < *(_DWORD *)(v50 + 9912));
                    }
                  v49[8] = v49[9];
                  v55 = cg;
                  v56 = (_DWORD *)*((_DWORD *)cg + 9);
                    if ((v56[6] & 0xC00000) != 0) {
                      memcpy((char *)cg_entities + 548 * v56[54],
                             (char *)cg_entities + 548 * v56[54] + 240, 0xF0u);
                      v56 = (_DWORD *)v55[9];
                    }
                    if ((int)v56[2477] > 0) {
                      v57 = 0;
                      v58 = 0;
                        do {
                          v59 = (char *)cg_entities + 548 * v56[v58 + 2479];
                          memcpy(v59, v59 + 240, 0xF0u);
                          ++v57;
                          v58 += 60;
                          v56 = (_DWORD *)*((_DWORD *)cg + 9);
                        }
                      while (v57 < v56[2477]);
                    }
                }
                else {
                  if ((signed int)(v32->serverTime - *(_DWORD *)(v48 + 8)) < 0)
                    Com_Error(
                        1,
                        "\x15CG_ProcessSnapshots: Server time went backwards",
                        v60);
                  CG_SetNextSnap(a1, a2, v32);
                LABEL_42:
                  v35 = cg;
                  v36 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
                  v37 = *((_DWORD *)cg + 8);
                  if (v36 - *(_DWORD *)(v37 + 8) >= 0 &&
                      v36 - *(_DWORD *)(*((_DWORD *)cg + 9) + 8) < 0)
                    return;
                    if (*(int *)(v37 + 9912) > 0) {
                      v38 = 0;
                        do {
                          v63 = v37 + 92 * v38 + 71344;
                          v39 = *(_DWORD *)(v37 + 92 * v38 + 71356);
                          v40 = &v35[302 * v39 + 229957];
                            if (v35[302 * v39 + 229958]) {
                              v35[302 * v39 + 229958] = 0;
                            }
                            else {
                              v41 = v35[302 * v39 + 230254];
                              memset(v40, 0, 0x4B8u);
                              v40[297] = v41;
                              CG_SafeDObjFree(a2, *(_DWORD *)(v63 + 12));
                            }
                          ++v38;
                          v35 = cg;
                          v37 = *((_DWORD *)cg + 8);
                        }
                      while (v38 < *(_DWORD *)(v37 + 9912));
                    }
                  v35[8] = v35[9];
                  v42 = cg;
                  v43 = (_DWORD *)*((_DWORD *)cg + 9);
                    if ((v43[6] & 0xC00000) != 0) {
                      memcpy((char *)cg_entities + 548 * v43[54],
                             (char *)cg_entities + 548 * v43[54] + 240, 0xF0u);
                      v43 = (_DWORD *)v42[9];
                    }
                    if ((int)v43[2477] > 0) {
                      v44 = 0;
                      v45 = 0;
                        do {
                          v46 = (char *)cg_entities + 548 * v43[v45 + 2479];
                          memcpy(v46, v46 + 240, 0xF0u);
                          ++v44;
                          v45 += 60;
                          v43 = (_DWORD *)*((_DWORD *)cg + 9);
                        }
                      while (v44 < v43[2477]);
                    }
                }
            }
        }
      v8 = *((_DWORD *)cg + 6);
      v9 = cgs;
      v10 = *((_DWORD *)cgs + 6055);
        if (v8 > v10 + 1000) {
          Com_Printf(
              "WARNING: CG_ReadNextSnapshot: way out of range, %i > %i\n", v8,
              *((_DWORD *)cgs + 6055));
          v10 = v9[6055];
        }
      v11 = v9;
      v12 = v10;
      v13 = v7;
      if (v12 >= *((_DWORD *)v7 + 6))
        break;
        while (1) {
          v14 = (snapshot_t *)(v13 + 40);
          if (*((char **)v13 + 8) == v13 + 40)
            v14 = (snapshot_t *)(v13 + 77288);
          v11[6055] = v12 + 1;
          v11 = cgs;
          if (CL_GetSnapshot(*((_DWORD *)cgs + 6055), v14))
            break;
          CG_AddLagometerSnapshotInfo(0);
          v12 = v11[6055];
          v13 = (char *)cg;
          if (v12 >= *((_DWORD *)cg + 6))
            return;
        }
      CG_AddLagometerSnapshotInfo(v14);
      if (!v14)
        break;
        if ((v14->snapFlags & 2) == 0) {
          CG_SetInitialSnapshot(a1, a2, a3, a4, a5, v14);
          CG_SetNextSnap(a1, a2, v14);
          v15 = cg;
          v16 = *((_DWORD *)cg + 8);
            if (*(int *)(v16 + 9912) > 0) {
              v64 = 0;
              v61 = 71344;
                do {
                  v17 = v16 + v61;
                  v18 = *(_DWORD *)(v16 + v61 + 12);
                  v19 = &v15[302 * v18 + 229957];
                    if (v15[302 * v18 + 229958]) {
                      v15[302 * v18 + 229958] = 0;
                    }
                    else {
                      v20 = v15[302 * v18 + 230254];
                      memset(v19, 0, 0x4B8u);
                      v19[297] = v20;
                      CG_SafeDObjFree(a2, *(_DWORD *)(v17 + 12));
                    }
                  ++v64;
                  v61 += 92;
                  v15 = cg;
                  v16 = *((_DWORD *)cg + 8);
                }
              while (v64 < *(_DWORD *)(v16 + 9912));
            }
          v15[8] = v15[9];
          v21 = cg;
          v22 = (_DWORD *)*((_DWORD *)cg + 9);
            if ((v22[6] & 0xC00000) != 0) {
              memcpy((char *)cg_entities + 548 * v22[54],
                     (char *)cg_entities + 548 * v22[54] + 240, 0xF0u);
              v22 = (_DWORD *)v21[9];
            }
            if ((int)v22[2477] > 0) {
              v23 = 0;
              v24 = 0;
                do {
                  v25 = (char *)cg_entities + 548 * v22[v24 + 2479];
                  memcpy(v25, v25 + 240, 0xF0u);
                  ++v23;
                  v24 += 60;
                  v22 = (_DWORD *)*((_DWORD *)cg + 9);
                }
              while (v23 < v22[2477]);
            }
        }
    }
}

void __cdecl CG_CopyCorpseInfo(struct clientInfo_t *,
                               struct clientInfo_t const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_TransitionSnapshot(void)
{
  UNIMPLEMENTED();
}

struct snapshot_t *__cdecl CG_ReadNextSnapshot(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ResetEntity(struct centity_s *)
{
  int v3;                    // eax
  char *v4;                  // esi
  int v5;                    // eax
  int v6;                    // edx
  int v7;                    // ecx
  char *v8;                  // ecx
  char *v9;                  // esi
  char *v10;                 // edi
  char *v11;                 // esi
  const XAnimTree_s **v12;   // eax
  char *v13;                 // edi
  char *v14;                 // esi
  const XAnimTree_s **__src; // [esp+1Ch] [ebp-2Ch]
  _DWORD *__dst;             // [esp+20h] [ebp-28h]
  XAnimTree_s *v17;          // [esp+24h] [ebp-24h]
  int v18;                   // [esp+28h] [ebp-20h]
  int v19;                   // [esp+2Ch] [ebp-1Ch]

  v3 = a1 + 516;
  *(_DWORD *)(a1 + 516) = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  memcpy((void *)a1, (const void *)(a1 + 240), 0xF0u);
  *(_BYTE *)(a1 + 483) = 0;
  *(_BYTE *)(a1 + 481) = 0;
  v4 = (char *)cg;
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 252),
                        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg),
                        (float *)(a1 + 492));
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 288),
                        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v4),
                        (float *)(a1 + 504));
  v5 = *(_DWORD *)(a1 + 244);
    if (v5 == 1) {
      *(_DWORD *)(a1 + 484) = *(_DWORD *)(a1 + 404);
      v6 = *(_DWORD *)(a1 + 384);
      v7 = (int)&v4[1208 * v6 + 919828];
      *(_DWORD *)(v7 + 992) = *(_DWORD *)(a1 + 348);
      *(_DWORD *)(v7 + 996) = *(_DWORD *)(a1 + 452);
      v8 = &v4[1208 * v6 + 920828];
      *(_DWORD *)v8 = *(_DWORD *)(a1 + 504);
      *((_DWORD *)v8 + 1) = *(_DWORD *)(a1 + 508);
      *((_DWORD *)v8 + 2) = *(_DWORD *)(a1 + 512);
      *(_DWORD *)(a1 + 504) = 0;
      *(_DWORD *)(a1 + 512) = 0;
      CG_ResetPlayerEntity((centity_s *)a1);
      return;
    }
    if (v5 > 1) {
        if (v5 != 2) {
            if (v5 != 4) {
            LABEL_5:
              *(_DWORD *)(a1 + 484) = *(_DWORD *)(a1 + 404);
              return;
            }
          goto LABEL_15;
        }
      __src = (const XAnimTree_s **)&v4[1208 * *(_DWORD *)(a1 + 384) + 919828];
      v9 = (char *)cgs + 1208 * *(_DWORD *)(a1 + 240) - 27632;
      __dst = v9 + 4;
      v17 = (XAnimTree_s *)*((_DWORD *)v9 + 298);
        if ((*(_BYTE *)(a1 + 250) & 8) != 0) {
          memcpy(v9 + 4, __src, 0x4B8u);
          v10 = v9 + 4;
          v18 = 0;
          v11 = v9 + 516;
            do {
                if (!I_stricmp(v11, "J_Spine4")) {
                  v10[128] = 0;
                  v10[512] = 0;
                }
              ++v18;
              v11 += 64;
              v10 += 64;
            }
          while (v18 != 6);
          __dst[297] = v17;
          XAnimCloneAnimTree(a2, __src[297], v17);
          *(_DWORD *)(a1 + 484) = 0;
          goto LABEL_13;
        }
        if (v9[68]) {
            if (*((const XAnimTree_s **)v9 + 3) == __src[2]) {
            LABEL_24:
              *(_DWORD *)(a1 + 484) = *(_DWORD *)(a1 + 404);
            LABEL_13:
              __dst[254] = 1;
              return;
            }
          v12 = __src;
        }
        else {
          v12 = __src;
        }
      memcpy(__dst, v12, 0x4B8u);
      v13 = v9 + 4;
      v19 = 0;
      v14 = v9 + 516;
        do {
            if (!I_stricmp(v14, "J_Spine4")) {
              v13[128] = 0;
              v13[512] = 0;
            }
          ++v19;
          v14 += 64;
          v13 += 64;
        }
      while (v19 != 6);
      __dst[297] = v17;
      goto LABEL_24;
    }
  if (v5)
    goto LABEL_5;
LABEL_15:
  *(_DWORD *)(a1 + 484) = 0;
}

void __cdecl CG_TransitionKillcam(void)
{
  UNIMPLEMENTED();
}
