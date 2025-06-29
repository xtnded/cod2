void __cdecl CG_UpdatePlayerDObj(struct centity_s *cent) {
  clientInfo_t *v2;   // ebx
  DObj_s *ClientDObj; // eax

  if (a2->nextValid) {
    v2 = (clientInfo_t *)((char *)cg + 1208 * *(_DWORD *)&a2->nextState[144] +
                          919828);
    ClientDObj =
        Com_GetClientDObj(*(_DWORD *)&a2->nextState[144], a2->localClientNum);
    BG_UpdatePlayerDObj(a1, ClientDObj, (entityState_s *)a2->nextState, v2, 0);
  }
}

void __cdecl CG_ResetPlayerEntity(struct centity_s *) {
  char *v1;             // esi
  XAnimTree_s *v2;      // edi
  unsigned int v3;      // xmm0_4
  char *v4;             // [esp+38h] [ebp-20h]
  unsigned __int16 *v5; // [esp+3Ch] [ebp-1Ch]

  v5 = (unsigned __int16 *)cg;
  v4 = (char *)cg + 1208 * *(_DWORD *)&a1->nextState[144] + 919808;
  v1 = (char *)cg + 1208 * *(_DWORD *)&a1->nextState[144] + 919828;
  if ((*(_DWORD *)&a1->nextState[8] & 0x20000) == 0) {
    v2 = (XAnimTree_s *)*((_DWORD *)cg + 302 * *(_DWORD *)&a1->nextState[144] +
                          230254);
    XAnimClearTreeGoalWeights(v2, *((unsigned __int16 *)cg + 459890), 0.0);
    XAnimSetCompleteGoalWeight(v2, v5[459880], 0, 0.0, 1065353216, 0, 0, 0);
    XAnimSetCompleteGoalWeight(v2, v5[459881], 0x3F800000u, 0.0, 1065353216, 0,
                               0, 0);
    XAnimSetCompleteGoalWeight(
        v2, *(unsigned __int16 *)((char *)&loc_E08D4 + (_DWORD)v5), 0, 0.0,
        1065353216, 0, 0, 0);
    memset(v4 + 916, 0, 0x30u);
    v3 = *((_DWORD *)v1 + 251);
    *((_QWORD *)v1 + 112) = v3;
    *((_DWORD *)v1 + 226) = 0;
    *((_DWORD *)v1 + 227) = 0;
    memset(v4 + 964, 0, 0x30u);
    *((_DWORD *)v1 + 236) = v3;
    *((_DWORD *)v1 + 237) = 0;
    *((_DWORD *)v1 + 238) = *((_DWORD *)v1 + 250);
    *((_DWORD *)v1 + 239) = 0;
  }
  if (*(_BYTE *)(cg_debugPosition + 8))
    Com_Printf("%i ResetPlayerEntity yaw=%i\n", *(_DWORD *)a1->nextState,
               (unsigned int)COERCE_UNSIGNED_INT64(*((float *)v1 + 236)));
}

void __cdecl CG_PlayerSprites(struct centity_s *cent) {
  char *result;       // eax
  int v2;             // edi
  int v3;             // eax
  int v4;             // edx
  float v5;           // xmm0_4
  int v6;             // ecx
  int v7;             // ecx
  char *ConfigString; // eax
  int v9;             // [esp+1Ch] [ebp-1Ch]

  result = (char *)cg + 1208 * *(_DWORD *)&a1->nextState[144];
  if (*((_DWORD *)result + 229957)) {
    v9 = *((_DWORD *)result + 229968);
    result = (char *)cg + 1208 * *(_DWORD *)(*((_DWORD *)cg + 9) + 216);
    if (*((_DWORD *)result + 229957)) {
      v2 = *((_DWORD *)result + 229968);
      v3 = *(_DWORD *)&a1->nextState[148];
      if (v3 &&
          ((v4 = *(_DWORD *)&a1->nextState[152]) == 0 || v2 == 3 || v2 == v4) &&
          (ConfigString = CL_GetConfigString(v3 + 30),
           CL_RegisterMaterial(ConfigString, 7))) {
        CG_PlayerFloatSprite((int)a1, 0);
        v5 = *(float *)(cg_scriptIconSize + 8) + 16.0;
      } else {
        v5 = 0.0;
      }
      result = *(char **)a1->nextState;
      if (result == *((char **)cg + 1) && *((_DWORD *)cg + 45893)) {
        v7 = (int)v5;
        return (char *)CG_PlayerFloatSprite((int)a1, v7);
      }
      v6 = *(_DWORD *)&a1->nextState[8];
      if ((v6 & 0x80u) != 0) {
        return (char *)CG_PlayerFloatSprite((int)a1, (int)v5);
      } else if (v9 == v2 || v2 == 3) {
        result = *(char **)a1->voiceChatSpriteTime;
        if ((int)result > *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg)) {
          v7 = (int)v5;
          return (char *)CG_PlayerFloatSprite((int)a1, v7);
        }
        if ((v6 & 0x200000) != 0) {
          v7 = (int)(float)(v5 - 5.0);
          return (char *)CG_PlayerFloatSprite((int)a1, v7);
        }
      }
    }
  }
  return result;
}

void __cdecl CG_Corpse(struct centity_s *cent) {
  uint8_t *nextState; // ebx
  DObj_s *ClientDObj; // eax
  DObj_s *v4;         // edi
  float v5;           // xmm0_4
  int v6;             // eax
  float v7;           // xmm0_4
  clientInfo_t *v8;   // [esp+1Ch] [ebp-9Ch]
  GfxEntity __b;      // [esp+2Ch] [ebp-8Ch] BYREF

  nextState = a2->nextState;
  if ((a2->nextState[8] & 0x20) == 0) {
    v8 =
        (clientInfo_t *)((char *)cgs + 1208 * *(_DWORD *)a2->nextState - 27628);
    ClientDObj =
        Com_GetClientDObj(*(_DWORD *)a2->nextState, a2->localClientNum);
    BG_UpdatePlayerDObj(a1, ClientDObj, (entityState_s *)nextState, v8, 0);
    v4 = Com_GetClientDObj(*(_DWORD *)a2->nextState, a2->localClientNum);
    if (v4) {
      memset(&__b, 0, sizeof(__b));
      __b.materialRGBA = -1;
      BG_PlayerAnimation(v4, (entityState_s *)nextState, v8);
      AnglesToAxis(a2->lerpAngles, __b.axis[0]);
      *(_QWORD *)__b.origin = *(_QWORD *)a2->lerpOrigin;
      __b.origin[2] = a2->lerpOrigin[2];
      __b.lighting.dx7 = *($_3622 *)__b.origin;
      v5 = __b.origin[2] + *(float *)&a2->nextState[228];
      __b.lighting.baseCoords[2] = v5;
      v6 = *(_DWORD *)&a2->nextState[8];
      if ((v6 & 8) != 0) {
        __b.lighting.baseCoords[2] = v5 + 12.0;
      } else {
        if ((v6 & 4) != 0)
          v7 = v5 + 20.0;
        else
          v7 = v5 + 32.0;
        __b.lighting.baseCoords[2] = v7;
      }
      __b.reType = 0;
      __b.renderFxFlags = 128;
      CG_AddCEntityToScene(&__b, (GfxModel)v4, a2);
    }
  }
}

void __cdecl CG_Player(struct centity_s *cent) {
  entityState_s *nextState; // edi
  int v2;                   // eax
  int v3;                   // edx
  centity_s *v4;            // edx
  int v5;                   // ebx
  char *v6;                 // esi
  int v7;                   // ebx
  int v8;                   // eax
  char *v9;                 // eax
  DObj_s *v10;              // edx
  unsigned int v11;         // eax
  float v12;                // xmm3_4
  float v13;                // xmm4_4
  float v14;                // xmm1_4
  float v15;                // xmm5_4
  float v16;                // xmm6_4
  float v17;                // xmm2_4
  float v18;                // xmm7_4
  float v19;                // xmm0_4
  float v20;                // xmm3_4
  float v21;                // xmm5_4
  float v22;                // xmm4_4
  float v23;                // xmm2_4
  float v24;                // xmm1_4
  char AnimDebugName;       // al
  int i;                    // eax
  signed int v27;           // ebx
  unsigned int v28;         // esi
  int v29;                  // ebx
  float v30;                // xmm1_4
  float v31;                // xmm0_4
  float *lerpAngles;        // esi
  float v33;                // xmm0_4
  int v34;                  // eax
  float v35;                // xmm0_4
  char v36;                 // al
  float v37;                // xmm2_4
  float v38;                // xmm0_4
  float v39;                // xmm2_4
  float v40;                // xmm0_4
  float v41;                // edx
  float v42;                // xmm2_4
  float v43;                // xmm0_4
  float v44;                // xmm2_4
  float v45;                // xmm0_4
  int v46;                  // esi
  float v47;                // xmm2_4
  float v48;                // xmm0_4
  int v49;                  // ebx
  float v50;                // xmm2_4
  float v51;                // xmm0_4
  int v52;                  // ebx
  float v53;                // xmm2_4
  float v54;                // xmm0_4
  float Weight;             // [esp+2Ch] [ebp-21Ch]
  float v56;                // [esp+2Ch] [ebp-21Ch]
  float v57;                // [esp+2Ch] [ebp-21Ch]
  float v58;                // [esp+2Ch] [ebp-21Ch]
  float v59;                // [esp+2Ch] [ebp-21Ch]
  float v60;                // [esp+2Ch] [ebp-21Ch]
  float v61;                // [esp+2Ch] [ebp-21Ch]
  float *lerpOrigin;        // [esp+3Ch] [ebp-20Ch]
  DObj_s *ClientDObj;       // [esp+40h] [ebp-208h]
  float v64;                // [esp+44h] [ebp-204h]
  float v65;                // [esp+48h] [ebp-200h]
  unsigned int v66;         // [esp+4Ch] [ebp-1FCh]
  int NumChildren;          // [esp+50h] [ebp-1F8h]
  unsigned int v68;         // [esp+54h] [ebp-1F4h]
  char *v69;                // [esp+58h] [ebp-1F0h]
  centity_s *v70;           // [esp+5Ch] [ebp-1ECh]
  int v71;                  // [esp+60h] [ebp-1E8h]
  int WeaponDef;            // [esp+64h] [ebp-1E4h]
  float v73;                // [esp+68h] [ebp-1E0h]
  float v74;                // [esp+6Ch] [ebp-1DCh]
  float v75;                // [esp+70h] [ebp-1D8h]
  float v76;                // [esp+74h] [ebp-1D4h]
  float v77;                // [esp+78h] [ebp-1D0h]
  float v78;                // [esp+7Ch] [ebp-1CCh]
  float *LocalTagMatrix;    // [esp+80h] [ebp-1C8h]
  XAnimTree_s *v80;         // [esp+84h] [ebp-1C4h]
  XAnim_s *v81;             // [esp+88h] [ebp-1C0h]
  unsigned int v82;         // [esp+8Ch] [ebp-1BCh]
  int ChildAt;              // [esp+90h] [ebp-1B8h]
  int v84;                  // [esp+94h] [ebp-1B4h]
  float v85;                // [esp+98h] [ebp-1B0h]
  float v86;                // [esp+9Ch] [ebp-1ACh]
  float v87;                // [esp+A8h] [ebp-1A0h]
  float v88;                // [esp+ACh] [ebp-19Ch]
  GfxEntity __b;            // [esp+B8h] [ebp-190h] BYREF
  float v90[12];            // [esp+12Ch] [ebp-11Ch] BYREF
  float v91[9];             // [esp+15Ch] [ebp-ECh] BYREF
  float v92;                // [esp+180h] [ebp-C8h]
  float v93;                // [esp+184h] [ebp-C4h]
  float v94;                // [esp+188h] [ebp-C0h]
  float v95[9];             // [esp+18Ch] [ebp-BCh] BYREF
  float v96;                // [esp+1B0h] [ebp-98h]
  float v97;                // [esp+1B4h] [ebp-94h]
  float v98;                // [esp+1B8h] [ebp-90h]
  trace_t v99;              // [esp+1BCh] [ebp-8Ch] BYREF
  float v100[9];            // [esp+1E0h] [ebp-68h] BYREF
  float v101[2];            // [esp+204h] [ebp-44h] BYREF
  float v102;               // [esp+20Ch] [ebp-3Ch]
  float v103[2];            // [esp+210h] [ebp-38h] BYREF
  float v104;               // [esp+218h] [ebp-30h]
  float v105;               // [esp+21Ch] [ebp-2Ch] BYREF
  float v106;               // [esp+220h] [ebp-28h]
  float v107;               // [esp+224h] [ebp-24h]
  float v108[8];            // [esp+228h] [ebp-20h] BYREF

  nextState = (entityState_s *)a1->nextState;
  v2 = *(_DWORD *)&a1->nextState[8];
  if ((v2 & 0x20) != 0 || (v2 & 0x20000) != 0)
    return;
  v3 = *((_DWORD *)cg + 9);
  if ((*(_DWORD *)(v3 + 24) & 0xC00000) == 0)
    goto LABEL_43;
  if (*(_DWORD *)a1->nextState == *(_DWORD *)(v3 + 216)) {
    if (!*(_DWORD *)((char *)&locret_25BC0 + (_DWORD)cg))
      return;
  LABEL_43:
    v4 = a1;
    goto LABEL_6;
  }
  v4 = a1;
LABEL_6:
  v5 = *(_DWORD *)&a1->nextState[144];
  ClientDObj = Com_GetClientDObj(nextState->number, v4->localClientNum);
  if (!ClientDObj)
    return;
  memset(&__b, 0, sizeof(__b));
  __b.materialRGBA = -1;
  v6 = (char *)cg;
  BG_PlayerAnimation(ClientDObj, nextState,
                     (clientInfo_t *)((char *)cg + 1208 * v5 + 919828));
  if ((*(_DWORD *)&a1->nextState[8] & 0x300) != 0) {
    v7 = *(_DWORD *)&a1->nextState[116];
    if (v7 <= 63) {
      lerpOrigin = a1->lerpOrigin;
      lerpAngles = a1->lerpAngles;
      goto LABEL_34;
    }
    if (v7 != 1023) {
      v69 = &v6[1208 * *(_DWORD *)&a1->nextState[144] + 919828];
      if (!*(_DWORD *)v69)
        goto LABEL_46;
      v71 = (int)&v6[1208 * *(_DWORD *)&a1->nextState[144] + 920724];
      if (*(_DWORD *)&v6[1208 * *(_DWORD *)&a1->nextState[144] + 920740]) {
        v8 = *(_DWORD *)&v6[1208 * *(_DWORD *)&a1->nextState[144] + 920744];
        if (!v8)
          goto LABEL_46;
        if ((*(_BYTE *)(v8 + 80) & 4) != 0) {
          v9 = (char *)cg_entities + 548 * v7;
          v70 = (centity_s *)v9;
          if (v9[480]) {
            v10 =
                Com_GetClientDObj(*((_DWORD *)v9 + 60), *((_DWORD *)v9 + 136));
            if (v10) {
              LocalTagMatrix = (float *)CG_DObjGetLocalTagMatrix(
                  v70, v10, (unsigned __int16)word_195B118);
              if (LocalTagMatrix) {
                if (*((_DWORD *)v6 + 38635)) {
                  WeaponDef = BG_GetWeaponDef(*(_DWORD *)&v70->nextState[200]);
                  v80 = (XAnimTree_s *)*((_DWORD *)v69 + 297);
                  v81 = (XAnim_s *)*((_DWORD *)v6 + 229939);
                  v11 = *(_DWORD *)(v71 + 16);
                  BYTE1(v11) &= ~2u;
                  v82 = v11;
                  v12 = LocalTagMatrix[7] * *LocalTagMatrix;
                  v13 = LocalTagMatrix[7] * LocalTagMatrix[1];
                  v14 = LocalTagMatrix[7] * LocalTagMatrix[2];
                  v85 = v12 * *LocalTagMatrix;
                  v15 = LocalTagMatrix[1];
                  v16 = v12 * v15;
                  v17 = LocalTagMatrix[2];
                  v18 = v12 * v17;
                  v19 = LocalTagMatrix[3];
                  v20 = v12 * v19;
                  v86 = v15 * v13;
                  v21 = v13 * v17;
                  v22 = v13 * v19;
                  v23 = v17 * v14;
                  v24 = v14 * v19;
                  v100[0] = 1.0 - (float)(v86 + v23);
                  v100[1] = v16 + v24;
                  v100[2] = v18 - v22;
                  v100[3] = v16 - v24;
                  v100[4] = 1.0 - (float)(v23 + v85);
                  v100[5] = v20 + v21;
                  v100[6] = v18 + v22;
                  v100[7] = v21 - v20;
                  v100[8] = 1.0 - (float)(v85 + v86);
                  v73 = vectosignedyaw(v100);
                  AnglesToAxis(v70->lerpAngles, v91);
                  v92 = v70->lerpOrigin[0];
                  v93 = v70->lerpOrigin[1];
                  v94 = v70->lerpOrigin[2];
                  lerpOrigin = a1->lerpOrigin;
                  v78 = (float)((float)(a1->lerpOrigin[2] - v94) * v91[8]) +
                        (float)((float)((float)(a1->lerpOrigin[1] - v93) *
                                        v91[7]) +
                                (float)((float)(a1->lerpOrigin[0] - v92) *
                                        v91[6]));
                  v74 = v78 - LocalTagMatrix[6];
                  XAnimClearTreeGoalWeightsStrict(v80, v82, 0.0);
                  NumChildren = XAnimGetNumChildren(v81, v82);
                  if (!NumChildren) {
                    AnimDebugName =
                        (unsigned __int8)XAnimGetAnimDebugName(v81, v82);
                    Com_Error(1, "\x15Player anim '%s' has no children",
                              AnimDebugName);
                  }
                  v76 = 0.0;
                  v87 = 0.0;
                  v68 = 0;
                  v84 = 0;
                  v66 = 0;
                  for (i = XAnimGetChildAt(v81, v82, 0);;
                       i = XAnimGetChildAt(v81, v82, v66)) {
                    v28 = i;
                    XAnimSetGoalWeight(v80, i, 0x3F800000u, 1.0, 1065353216, 0,
                                       0, 0);
                    v29 = XAnimGetNumChildren(v81, v28);
                    if (!v29) {
                      v36 = (unsigned __int8)XAnimGetAnimDebugName(v81, v28);
                      Com_Error(1, "\x15Player anim '%s' has no children", v36);
                    }
                    v30 = (float)((float)v29 * 0.5) -
                          (float)(v73 / *(float *)(WeaponDef + 1380));
                    if (v30 < 0.0) {
                      v30 = 0.0;
                      v27 = 0;
                    } else {
                      v31 = (float)(v29 - 1);
                      if (v30 < v31) {
                        v27 = (int)v30;
                      } else {
                        v27 = (int)v31;
                        v30 = v31;
                      }
                    }
                    v88 = v30 - (float)v27;
                    ChildAt = XAnimGetChildAt(v81, v28, v27);
                    v64 = 1.0 - v88;
                    XAnimSetGoalWeight(v80, ChildAt,
                                       COERCE_UNSIGNED_INT(1.0 - v88), 1.0,
                                       1065353216, 0, 0, 0);
                    if (v88 != 0.0) {
                      v84 = XAnimGetChildAt(v81, v28, v27 + 1);
                      XAnimSetGoalWeight(v80, v84, LODWORD(v88), 1.0,
                                         1065353216, 0, 0, 0);
                    }
                    XAnimCalcAbsDelta(v80, v28, v108, v101);
                    v75 = v102;
                    if (v102 >= v74)
                      break;
                    if (NumChildren <= (int)++v66) {
                      v76 = v30 - (float)v27;
                      v68 = v27;
                      goto LABEL_49;
                    }
                    v87 = v102;
                    v76 = v30 - (float)v27;
                    v68 = v27;
                  }
                  v75 = v87;
                LABEL_49:
                  XAnimClearTreeGoalWeightsStrict(v80, v82, 0.0);
                  Weight = XAnimGetWeight(v80, ChildAt);
                  v37 = fabs(Weight - v64) *
                        (float)(1000.0 / (float)*((int *)cg + 38635));
                  v38 = 0.0;
                  if (v37 > 0.0)
                    v38 = 1.0 / v37;
                  XAnimSetGoalWeight(v80, ChildAt, LODWORD(v64), v38,
                                     1065353216, 0, 0, 0);
                  if (v88 != 0.0) {
                    v57 = XAnimGetWeight(v80, v84);
                    v42 = fabs(v57 - v88) *
                          (float)(1000.0 / (float)*((int *)cg + 38635));
                    v43 = 0.0;
                    if (v42 > 0.0)
                      v43 = 1.0 / v42;
                    XAnimSetGoalWeight(v80, v84, LODWORD(v88), v43, 1065353216,
                                       0, 0, 0);
                  }
                  if (v66 && v66 != NumChildren) {
                    v77 = (float)(v74 - v75) / (float)(v102 - v75);
                    v58 = XAnimGetWeight(v80, v28);
                    v44 = fabs(v58 - v77) *
                          (float)(1000.0 / (float)*((int *)cg + 38635));
                    v45 = 0.0;
                    if (v44 > 0.0)
                      v45 = 1.0 / v44;
                    XAnimSetGoalWeight(v80, v28, LODWORD(v77), v45, 1065353216,
                                       0, 0, 0);
                    v46 = XAnimGetChildAt(v81, v82, v66 - 1);
                    v59 = XAnimGetWeight(v80, v46);
                    v47 = fabs(v59 - (float)(1.0 - v77)) *
                          (float)(1000.0 / (float)*((int *)cg + 38635));
                    v48 = 0.0;
                    if (v47 > 0.0)
                      v48 = 1.0 / v47;
                    XAnimSetGoalWeight(v80, v46, COERCE_UNSIGNED_INT(1.0 - v77),
                                       v48, 1065353216, 0, 0, 0);
                    v49 = XAnimGetChildAt(v81, v46, v68);
                    v60 = XAnimGetWeight(v80, v49);
                    v50 = fabs(v60 - (float)(1.0 - v76)) *
                          (float)(1000.0 / (float)*((int *)cg + 38635));
                    v51 = 0.0;
                    if (v50 > 0.0)
                      v51 = 1.0 / v50;
                    XAnimSetGoalWeight(v80, v49, COERCE_UNSIGNED_INT(1.0 - v76),
                                       v51, 1065353216, 0, 0, 0);
                    if (v76 != 0.0) {
                      v52 = XAnimGetChildAt(v81, v46, v68 + 1);
                      v61 = XAnimGetWeight(v80, v52);
                      v53 = fabs(v61 - v76) *
                            (float)(1000.0 / (float)*((int *)cg + 38635));
                      v54 = 0.0;
                      if (v53 > 0.0)
                        v54 = 1.0 / v53;
                      XAnimSetGoalWeight(v80, v52, LODWORD(v76), v54,
                                         1065353216, 0, 0, 0);
                    }
                  } else {
                    v56 = XAnimGetWeight(v80, v28);
                    v39 = fabs(v56 - 1.0) *
                          (float)(1000.0 / (float)*((int *)cg + 38635));
                    v40 = 0.0;
                    if (v39 > 0.0)
                      v40 = 1.0 / v39;
                    XAnimSetGoalWeight(v80, v28, 0x3F800000u, v40, 1065353216,
                                       0, 0, 0);
                  }
                  XAnimCalcAbsDelta(v80, v82, v108, v101);
                  VectorAngleMultiply(v101, v73);
                  v90[9] = v101[0] + LocalTagMatrix[4];
                  v90[10] = v101[1] + LocalTagMatrix[5];
                  v90[11] = v78;
                  v65 = RotationToYaw(v108);
                  YawToAxis(v73 + v65, (int)v90);
                  MatrixMultiply43(v90, v91, v95);
                  lerpAngles = a1->lerpAngles;
                  AxisToAngles(v95, a1->lerpAngles);
                  v41 = v96;
                  *lerpOrigin = v96;
                  a1->lerpOrigin[1] = v97;
                  a1->lerpOrigin[2] = v98;
                  v105 = v41;
                  v106 = a1->lerpOrigin[1];
                  v107 = a1->lerpOrigin[2];
                  v103[0] = v41;
                  v103[1] = v106;
                  v104 = v107;
                  v107 = v70->lerpOrigin[2];
                  CG_TraceCapsule(&v99, &v105, (trace_t *)vec3_origin,
                                  vec3_origin, v103, *(_DWORD *)a1->nextState,
                                  (const float *)0x2810011);
                  if (v99.fraction < 1.0)
                    a1->lerpOrigin[2] =
                        v107 + (float)(v99.fraction * (float)(v104 - v107));
                  goto LABEL_34;
                }
                goto LABEL_46;
              }
              Com_Printf("WARNING: aborting player positioning on turret since "
                         "'tag_weapon' does not exist\n");
            }
            goto LABEL_33;
          }
        LABEL_46:
          lerpOrigin = a1->lerpOrigin;
          lerpAngles = a1->lerpAngles;
          goto LABEL_34;
        }
      }
    }
  }
LABEL_33:
  lerpOrigin = a1->lerpOrigin;
  lerpAngles = a1->lerpAngles;
LABEL_34:
  AnglesToAxis(lerpAngles, __b.axis[0]);
  __b.origin[0] = a1->lerpOrigin[0];
  __b.origin[1] = lerpOrigin[1];
  __b.origin[2] = lerpOrigin[2];
  __b.lighting.dx7 = *($_3622 *)__b.origin;
  v33 = __b.origin[2] + *(float *)&a1->nextState[228];
  __b.lighting.baseCoords[2] = v33;
  v34 = *(_DWORD *)&a1->nextState[8];
  if ((v34 & 8) != 0) {
    v35 = v33 + 12.0;
    __b.lighting.baseCoords[2] = v35;
  } else {
    if ((v34 & 4) != 0)
      v35 = v33 + 20.0;
    else
      v35 = v33 + 32.0;
    __b.lighting.baseCoords[2] = v35;
  }
  __b.reType = 0;
  __b.renderFxFlags = 128;
  CG_AddCEntityToScene(&__b, (GfxModel)ClientDObj, a1);
  if ((a1->nextState[10] & 2) == 0)
    CG_AddPlayerWeapon(v35, &__b, 0, a1, 1);
}

void __cdecl CG_PlayerTurretPositionAndBlend(struct centity_s *) {
  UNIMPLEMENTED();
}

void __cdecl CG_PlayerFloatSprite(struct centity_s *, struct Material *, float,
                                  int, bool) {
  UNIMPLEMENTED();
}
