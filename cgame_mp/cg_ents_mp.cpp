void __cdecl CG_CullIn(struct centity_s const *cent) {
  const centity_s *result; // eax

  result = a1;
  if (a1)
    a1->cullIn = 2;
  return result;
}

void __cdecl CG_UsedDObjCalcPose(struct centity_s const *cent) {
  const centity_s *result; // eax

  result = a1;
  if (a1) {
    if (!a1->cullIn)
      a1->cullIn = 1;
  }
  return result;
}

void __cdecl CG_ProcessClientNoteTracks(int clientNum) {
  int v1;               // esi
  int v2;               // ebx
  int v3;               // edi
  char *v4;             // eax
  char *v5;             // eax
  int ClientNotifyList; // [esp+1Ch] [ebp-2Ch]
  XAnimNotify_s *v7;    // [esp+2Ch] [ebp-1Ch] BYREF

  if (a1 <= 0x3F) {
    ClientNotifyList = DObjGetClientNotifyList(&v7);
    if (ClientNotifyList > 0) {
      v1 = 0;
      v2 = 0;
      v3 = 1208 * a1;
      do {
        if (v7[v2].type == 1) {
          if (!stricmp(*(const char **)v7[v2].name,
                       "anim_gunhand = \"left\"")) {
            v4 = (char *)cg + v3;
            *((_DWORD *)v4 + 230210) = 1;
            *((_DWORD *)v4 + 230211) = 1;
          } else if (!stricmp(*(const char **)v7[v2].name,
                              "anim_gunhand = \"right\"")) {
            v5 = (char *)cg + v3;
            *((_DWORD *)v5 + 230210) = 0;
            *((_DWORD *)v5 + 230211) = 1;
          }
        }
        ++v1;
        ++v2;
      } while (ClientNotifyList != v1);
    }
  }
}

void __cdecl CG_SetFrameInterpolation() {
  float *v0;  // ecx
  int v1;     // edx
  int result; // eax
  int v3;     // ebx

  v0 = (float *)cg;
  v1 = *(_DWORD *)(*((_DWORD *)cg + 8) + 8);
  result = *(_DWORD *)(*((_DWORD *)cg + 9) + 8);
  v3 = result - v1;
  if (result == v1) {
    *((_DWORD *)cg + 38634) = 0;
  } else {
    result = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v1;
    *((float *)cg + 38634) = (float)result / (float)v3;
    if (v0[38634] < 0.0)
      v0[38634] = 0.0;
  }
  return result;
}

void __cdecl CG_LockLightingOrigin(struct centity_s *, struct GfxEntity *) {
  UNIMPLEMENTED();
}

int __cdecl CG_DObjGetLocalTagBox(struct DObj_s *, unsigned int,
                                  float (*const)[3]) {
  UNIMPLEMENTED();
}

int __cdecl CG_DObjGetWorldTagBox(struct centity_s *, struct DObj_s *,
                                  unsigned int, float (*const)[3]) {
  UNIMPLEMENTED();
}

void __cdecl CG_AdjustPositionForMover(float const *const in, int moverNum,
                                       int fromTime, int toTime,
                                       float *const out,
                                       float *const outDeltaAngles) {
  char *v6;               // ebx
  float *result;          // eax
  const trajectory_t *v8; // ebx
  float v9;               // xmm1_4
  float v10;              // xmm2_4
  float v11;              // xmm5_4
  float v12;              // xmm4_4
  float v13;              // xmm3_4
  trajectory_t *v14;      // [esp+1Ch] [ebp-4Ch]
  float v15[3];           // [esp+20h] [ebp-48h] BYREF
  float v16[3];           // [esp+2Ch] [ebp-3Ch] BYREF
  float v17[3];           // [esp+38h] [ebp-30h] BYREF
  float v18[9];           // [esp+44h] [ebp-24h] BYREF

  if (a6) {
    *a6 = 0.0;
    a6[1] = 0.0;
    a6[2] = 0.0;
  }
  if ((unsigned int)(a2 - 1) <= 0x3FC &&
      (v6 = (char *)cg_entities + 548 * a2, *((_DWORD *)v6 + 61) == 6)) {
    v14 = (trajectory_t *)(v6 + 12);
    BG_EvaluateTrajectory((const trajectory_t *)(v6 + 12), a3, v18);
    v8 = (const trajectory_t *)(v6 + 48);
    BG_EvaluateTrajectory(v8, a3, v16);
    BG_EvaluateTrajectory(v14, a4, v17);
    result = BG_EvaluateTrajectory(v8, a4, v15);
    v9 = v17[1] - v18[1];
    v10 = v17[2] - v18[2];
    v11 = v15[0] - v16[0];
    v12 = v15[1] - v16[1];
    v13 = v15[2] - v16[2];
    *a5 = (float)(v17[0] - v18[0]) + *a1;
    a5[1] = v9 + a1[1];
    a5[2] = v10 + a1[2];
    if (a6) {
      *a6 = v11;
      a6[1] = v12;
      a6[2] = v13;
    }
  } else {
    *a5 = *a1;
    a5[1] = a1[1];
    result = (float *)*((_DWORD *)a1 + 2);
    *((_DWORD *)a5 + 2) = result;
  }
  return result;
}

struct XAnim_s *__cdecl CG_GetMG42Anims(struct centity_s *cent) {
  int WeaponDef;  // esi
  XAnim_s *Anims; // ebx

  WeaponDef = BG_GetWeaponDef(*(_DWORD *)&a1->nextState[200]);
  Anims = (XAnim_s *)XAnimCreateAnims("MG42", 3,
                                      (void *(*)(int))Hunk_AllocXAnimClient);
  XAnimBlend(Anims, 0, "root", 1u, 2u, 0);
  XAnimPrecache(*(char **)(WeaponDef + 24),
                (void *(*)(int))Hunk_AllocXAnimPrecache);
  XAnimCreate(Anims, 1u, *(char **)(WeaponDef + 24));
  XAnimPrecache(*(char **)(WeaponDef + 32),
                (void *(*)(int))Hunk_AllocXAnimPrecache);
  XAnimCreate(Anims, 2u, *(char **)(WeaponDef + 32));
  return Anims;
}

int __cdecl CG_PlayerSeesItem(struct playerState_s *, struct entityState_s *,
                              int, int) {
  UNIMPLEMENTED();
}

struct XAnim_s *__cdecl CG_GetAnimations(int, int) {
  UNIMPLEMENTED();
}

void __cdecl CG_CalcEntityLerpPositions(struct centity_s *cent) {
  int v1;   // eax
  void *v2; // ebx
  int v3;   // eax
  int v4;   // edx
  int v5;   // eax
  int v6;   // ebx
  char *v7; // ecx
  char *v8; // eax

  v1 = *(_DWORD *)&a1->currentState[12];
  if (v1 == 1 || v1 == 3 && *(int *)a1->currentState <= 63) {
    CG_InterpolateEntityPosition((int)a1);
    return;
  }
  v2 = cg;
  BG_EvaluateTrajectory((const trajectory_t *)&a1->currentState[12],
                        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg),
                        a1->lerpOrigin);
  BG_EvaluateTrajectory((const trajectory_t *)&a1->currentState[48],
                        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v2),
                        a1->lerpAngles);
  v3 = *(_DWORD *)&a1->nextState[4];
  if (v3 == 1) {
    v4 = *(_DWORD *)&a1->nextState[144];
    v5 = (int)v2 + 1208 * v4 + 919808;
    v6 = (int)v2 + 1208 * v4 + 919828;
    *(_DWORD *)(v6 + 992) = *(_DWORD *)&a1->nextState[108];
    v7 = (char *)(v5 + 1020);
    *(float *)(v5 + 1020) = a1->lerpAngles[0];
  } else {
    if (v3 != 2)
      goto LABEL_5;
    v8 = (char *)cgs + 1208 * *(_DWORD *)a1->nextState - 27632;
    v6 = (int)(v8 + 4);
    *((_DWORD *)v8 + 249) = *(_DWORD *)&a1->nextState[108];
    v7 = v8 + 1004;
    *((_DWORD *)v8 + 251) = LODWORD(a1->lerpAngles[0]);
  }
  *((_DWORD *)v7 + 1) = LODWORD(a1->lerpAngles[1]);
  *((_DWORD *)v7 + 2) = LODWORD(a1->lerpAngles[2]);
  a1->lerpAngles[0] = 0.0;
  a1->lerpAngles[2] = 0.0;
  *(_DWORD *)(v6 + 996) = *(_DWORD *)&a1->nextState[212];
LABEL_5:
  if (a1 != (centity_s *)((char *)cg + 164460))
    CG_AdjustPositionForMover(a1->lerpOrigin, *(_DWORD *)&a1->currentState[124],
                              *(_DWORD *)(*((_DWORD *)cg + 8) + 8),
                              *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg),
                              a1->lerpOrigin, 0);
}

void __cdecl CG_SoundBlend(struct centity_s *cent) {
  int result;            // eax
  char *ConfigString;    // eax
  char *v3;              // eax
  const snd_alias_t *v4; // edx
  snd_alias_t *v5;       // [esp+2Ch] [ebp-1Ch]

  result = *(_DWORD *)&a1->nextState[184];
  if (result) {
    if (*(_DWORD *)&a1->nextState[188]) {
      CL_GetConfigString(result + 590);
      result = CG_PlaySoundOnCurrentLocalClient();
      if ((_BYTE)result) {
        ConfigString = CL_GetConfigString(*(_DWORD *)&a1->nextState[184] + 590);
        v5 = (snd_alias_t *)CL_PickSoundAlias(ConfigString);
        v3 = CL_GetConfigString(*(_DWORD *)&a1->nextState[188] + 590);
        v4 = (const snd_alias_t *)CL_PickSoundAlias(v3);
        result = (int)v5;
        if (v5) {
          if (v4)
            return SND_PlayBlendedSoundAliases(
                v5, v4,
                COERCE_INT(*(float *)&a1->currentState[212] +
                           (float)((float)(*(float *)&a1->nextState[212] -
                                           *(float *)&a1->currentState[212]) *
                                   *((float *)cg + 38634))),
                *(float **)a1->nextState, a1->lerpOrigin, 0, (const float *)1);
        }
      }
    }
  }
  return result;
}

void __cdecl CG_EntityEffects(struct centity_s *cent) {
  int v1;             // ebx
  char *v2;           // eax
  unsigned int v3;    // edx
  float *v4;          // edx
  char *ConfigString; // eax
  float v6[5];        // [esp+24h] [ebp-14h] BYREF

  v1 = *(_DWORD *)&a1->nextState[132];
  if (v1) {
    if (*(_UNKNOWN **)&a1->nextState[156] == &unk_FFFFFF) {
      v4 = (float *)((char *)cgs + 12 * *(_DWORD *)&a1->nextState[140] + 33160);
      v6[0] = a1->lerpOrigin[0] + *v4;
      v6[1] = a1->lerpOrigin[1] + v4[1];
      v6[2] = a1->lerpOrigin[2] + v4[2];
      ConfigString = CL_GetConfigString(v1 + 590);
      CG_PlaySoundAliasByName(*(float **)a1->nextState, v6, ConfigString);
    } else {
      v2 = CL_GetConfigString(v1 + 590);
      CG_PlaySoundAliasByName(*(float **)a1->nextState, a1->lerpOrigin, v2);
    }
  }
  v3 = *(_DWORD *)&a1->nextState[128];
  if (v3)
    CL_AddLightToScene(a1->lerpOrigin, (float)(int)(4 * HIBYTE(v3)),
                       (float)(unsigned __int8)v3 / 255.0,
                       (float)BYTE1(v3) / 255.0, (float)BYTE2(v3) / 255.0);
}

void __cdecl CG_DObjCalcBoneGeneric(int handle, int localClientNum,
                                    int boneIndex) {
  DObj_s *ClientDObj;      // esi
  int result;              // eax
  int *v5;                 // ecx
  int v6;                  // eax
  const entityState_s *v7; // edi
  const DObj_s *v8;        // [esp+2Ch] [ebp-2Ch]
  int v9[10];              // [esp+30h] [ebp-28h] BYREF

  ClientDObj = Com_GetClientDObj(a1, a2);
  result = CL_DObjCreateSkelForBone(ClientDObj, a3, 0);
  if (!result) {
    DObjGetHierarchyBits(ClientDObj, a3, v9);
    DObjCalcAnim(ClientDObj, v9);
    if (a1 <= 1023) {
      v5 = (int *)((char *)cg_entities + 548 * a1);
      v6 = v5[61];
      if (v6 == 1) {
        v7 = (const entityState_s *)(v5 + 60);
        v8 = Com_GetClientDObj(v5[60], v5[136]);
        if (*((_DWORD *)cg + 302 * v7->clientNum + 229957))
          BG_Player_DoControllers(
              v8, v7, v9,
              (clientInfo_t *)((char *)cg + 1208 * v7->clientNum + 919828),
              *((_DWORD *)cg + 38635));
      } else if (v6 == 9) {
        CG_mg42_DoControllers((int)cg_entities + 548 * a1, v9);
      }
    }
    return DObjCalcSkel(ClientDObj, v9);
  }
  return result;
}

void __cdecl CG_DObjCalcBone(struct centity_s const *cent, struct DObj_s *obj,
                             int boneIndex) {
  int result;               // eax
  int v4;                   // eax
  clientInfo_t *v5;         // edx
  const DObj_s *ClientDObj; // [esp+2Ch] [ebp-2Ch]
  int v7[10];               // [esp+30h] [ebp-28h] BYREF

  result = CL_DObjCreateSkelForBone(a2, a3, a1->localClientNum);
  if (!result) {
    DObjGetHierarchyBits(a2, a3, v7);
    DObjCalcAnim(a2, v7);
    v4 = *(_DWORD *)&a1->nextState[4];
    if (v4 == 1) {
      ClientDObj =
          Com_GetClientDObj(*(_DWORD *)a1->nextState, a1->localClientNum);
      v5 = (clientInfo_t *)((char *)cg + 1208 * *(_DWORD *)&a1->nextState[144] +
                            919828);
      if (*(_DWORD *)v5->infoValid)
        BG_Player_DoControllers(ClientDObj,
                                (const entityState_s *)a1->nextState, v7, v5,
                                *((_DWORD *)cg + 38635));
    } else if (v4 == 9) {
      CG_mg42_DoControllers((int)a1, v7);
    }
    return DObjCalcSkel(a2, v7);
  }
  return result;
}

void __cdecl CG_DObjCalcPose(struct centity_s const *cent,
                             struct DObj_s const *obj, int *const partBits) {
  int result;               // eax
  int v4;                   // eax
  clientInfo_t *v5;         // edx
  const DObj_s *ClientDObj; // [esp+2Ch] [ebp-2Ch]
  int v7[10];               // [esp+30h] [ebp-28h] BYREF

  v7[0] = *a3;
  v7[1] = a3[1];
  v7[2] = a3[2];
  v7[3] = a3[3];
  DObjCompleteHierarchyBits(a2, v7);
  result = CL_DObjCreateSkelForBones(a2, v7, a1->localClientNum);
  if (!result) {
    DObjCalcAnim(a2, v7);
    v4 = *(_DWORD *)&a1->nextState[4];
    if (v4 == 1) {
      ClientDObj =
          Com_GetClientDObj(*(_DWORD *)a1->nextState, a1->localClientNum);
      v5 = (clientInfo_t *)((char *)cg + 1208 * *(_DWORD *)&a1->nextState[144] +
                            919828);
      if (*(_DWORD *)v5->infoValid)
        BG_Player_DoControllers(ClientDObj,
                                (const entityState_s *)a1->nextState, v7, v5,
                                *((_DWORD *)cg + 38635));
    } else if (v4 == 9) {
      CG_mg42_DoControllers((int)a1, v7);
    }
    return DObjCalcSkel(a2, v7);
  }
  return result;
}

int __cdecl CG_DObjGetViewModelTagPos(struct DObj_s *obj, unsigned int tagName,
                                      float *const pos) {
  int BoneIndex;         // eax
  int v4;                // edi
  float *v5;             // ebx
  int32_t RotTransArray; // [esp+1Ch] [ebp-5Ch]
  float v8[12];          // [esp+20h] [ebp-58h] BYREF
  int v9[10];            // [esp+50h] [ebp-28h] BYREF

  BoneIndex = DObjGetBoneIndex(a1, a2);
  v4 = BoneIndex;
  if (BoneIndex < 0)
    return 0;
  if (!CL_DObjCreateSkelForBone(a1, BoneIndex, 0)) {
    DObjGetHierarchyBits(a1, v4, v9);
    DObjCalcAnim(a1, v9);
    DObjCalcSkel(a1, v9);
  }
  RotTransArray = DObjGetRotTransArray(a1);
  if (!RotTransArray)
    return 0;
  v5 = (float *)cg;
  AxisCopy((_DWORD *)cg + 45106, v8);
  v8[9] = v5[45103];
  v8[10] = v5[45104];
  v8[11] = v5[45105];
  MatrixTransformVector43((const float *)(RotTransArray + 32 * v4 + 16),
                          (const float(*)[3])v8, a3);
  return 1;
}

struct DObjAnimMat_s *__cdecl CG_DObjGetLocalTagMatrix(
    struct centity_s const *cent, struct DObj_s *obj, unsigned int tagName) {
  int BoneIndex;         // eax
  int v4;                // ebx
  int32_t RotTransArray; // eax

  BoneIndex = DObjGetBoneIndex(a2, a3);
  v4 = BoneIndex;
  if (BoneIndex >= 0 && (CG_DObjCalcBone(a1, a2, BoneIndex),
                         (RotTransArray = DObjGetRotTransArray(a2)) != 0))
    return 32 * v4 + RotTransArray;
  else
    return 0;
}

int __cdecl CG_DObjGetWorldTagPos(struct centity_s const *cent,
                                  struct DObj_s *obj, unsigned int tagName,
                                  float *const pos) {
  int BoneIndex;         // eax
  int v5;                // ebx
  int32_t RotTransArray; // eax
  int v7;                // esi
  float v9[18];          // [esp+10h] [ebp-48h] BYREF

  BoneIndex = DObjGetBoneIndex(a2, a3);
  v5 = BoneIndex;
  if (BoneIndex < 0)
    return 0;
  CG_DObjCalcBone(a1, a2, BoneIndex);
  RotTransArray = DObjGetRotTransArray(a2);
  if (!RotTransArray)
    return 0;
  v7 = 32 * v5 + RotTransArray;
  if (!v7)
    return 0;
  AnglesToAxis(a1->lerpAngles, v9);
  v9[9] = a1->lerpOrigin[0];
  v9[10] = a1->lerpOrigin[1];
  v9[11] = a1->lerpOrigin[2];
  MatrixTransformVector43((const float *)(v7 + 16), (const float(*)[3])v9, a4);
  return 1;
}

int __cdecl CG_DObjGetWorldTagMatrix(struct centity_s const *, struct DObj_s *,
                                     unsigned int, float (*const)[3]) {
  UNIMPLEMENTED();
}

void __cdecl CG_DObjUpdateInfo(struct DObj_s *obj) {
  DObjUpdateClientInfo(a1, (float)*((int *)cg + 38635) * 0.001);
}

void __cdecl CG_AddCEntityToScene(struct GfxEntity const *ent,
                                  struct DObj_s const *obj,
                                  struct centity_s const *cent) {
  GfxEntity *v3; // eax
  int8_t cullIn; // dl

  v3 = (GfxEntity *)R_AddRefEntityToScene(__src, a2, a3);
  if (v3) {
    cullIn = a3->cullIn;
    if (cullIn == 1) {
      a3->cullIn = 0;
      R_UpdateXModelBoundsDelayed(v3);
    } else if (cullIn == 2) {
      a3->cullIn = 0;
      R_SkinGfxEntityDelayed(v3);
    }
  }
}

void __cdecl CG_Missile(struct centity_s *cent) {
  int v2;            // ebx
  DObj_s *DObj;      // esi
  float *lerpOrigin; // edi
  float v5;          // xmm0_4
  GfxEntity *v6;     // eax
  int8_t cullIn;     // dl
  char *v8;          // [esp+2Ch] [ebp-9Ch]
  GfxEntity __b;     // [esp+34h] [ebp-94h] BYREF
  FxBoltInfo v10;    // [esp+A8h] [ebp-20h] BYREF

  if ((a2->nextState[8] & 0x20) == 0 &&
      *(_DWORD *)&a2->nextState[84] <=
          *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg)) {
    v2 = *(_DWORD *)&a2->nextState[200];
    if (v2 > BG_GetNumWeapons())
      *(_DWORD *)&a2->nextState[200] = 0;
    v8 = (char *)cg_weapons + 436 * *(_DWORD *)&a2->nextState[200];
    if (*((_DWORD *)v8 + 53))
      CG_PlaySoundAlias(*(float **)a2->nextState, a2->lerpOrigin,
                        *((snd_alias_list_t **)v8 + 53));
    DObj = CG_PreProcess_GetDObj(*(_DWORD *)a2->nextState,
                                 *(_DWORD *)&a2->nextState[4],
                                 *((XModel **)v8 + 80), a1);
    if (DObj) {
      if (*((_DWORD *)v8 + 91)) {
        if (a2->bTrailMade) {
          lerpOrigin = a2->lerpOrigin;
        } else {
          v10.dobjHandle = *(_DWORD *)a2->nextState;
          v10.boneIndex =
              FX_GetBoneIndex(v10.dobjHandle, (unsigned __int16)word_195B122);
          lerpOrigin = a2->lerpOrigin;
          if ((v10.boneIndex & 0x80000000) == 0)
            FX_PlayEntityEffect(a1, *((EffectTemplate **)v8 + 91),
                                a2->lerpOrigin, 0, &v10);
          a2->bTrailMade = 1;
        }
      } else {
        lerpOrigin = a2->lerpOrigin;
      }
      v5 = *((float *)v8 + 82);
      if (v5 != 0.0)
        CL_AddLightToScene(lerpOrigin, v5, *((float *)v8 + 83),
                           *((float *)v8 + 84), *((float *)v8 + 85));
      memset(&__b, 0, sizeof(__b));
      __b.origin[0] = a2->lerpOrigin[0];
      __b.origin[1] = lerpOrigin[1];
      __b.origin[2] = lerpOrigin[2];
      __b.renderFxFlags = *((_DWORD *)v8 + 86) | 0x40;
      AnglesToAxis(a2->lerpAngles, __b.axis[0]);
      __b.reType = 0;
      v6 = (GfxEntity *)R_AddRefEntityToScene(&__b, (GfxModel)DObj, a2);
      if (v6) {
        cullIn = a2->cullIn;
        if (cullIn == 1) {
          a2->cullIn = 0;
          R_UpdateXModelBoundsDelayed(v6);
        } else if (cullIn == 2) {
          a2->cullIn = 0;
          R_SkinGfxEntityDelayed(v6);
        }
      }
    }
  }
}

void __cdecl CG_Item(struct centity_s *cent) {
  int v2;        // ecx
  char *v3;      // ebx
  DObj_s *DObj;  // esi
  GfxEntity *v5; // eax
  int8_t cullIn; // dl
  GfxEntity __b; // [esp+2Ch] [ebp-8Ch] BYREF

  if (*(_DWORD *)&a2->nextState[140] >= bg_numItems)
    Com_Error(1, "\x15Bad item index %i on entity",
              *(_DWORD *)&a2->nextState[140]);
  if ((a2->nextState[8] & 0x20) == 0) {
    v2 = *(_DWORD *)&a2->nextState[140];
    v3 = (char *)cg_items + 36 * v2;
    if (*(_DWORD *)v3) {
      if (!*((_DWORD *)v3 + 1))
        Com_Error(1, "\x15No XModel loaded for item index %i (%s)", v2);
      DObj = CG_PreProcess_GetDObj(*(_DWORD *)a2->nextState,
                                   *(_DWORD *)&a2->nextState[4],
                                   *((XModel **)v3 + 1), a1);
      if (DObj) {
        memset(&__b, 0, sizeof(__b));
        AnglesToAxis(a2->lerpAngles, __b.axis[0]);
        __b.origin[0] = a2->lerpOrigin[0];
        __b.origin[1] = a2->lerpOrigin[1];
        __b.origin[2] = a2->lerpOrigin[2];
        __b.reType = 0;
        v5 = (GfxEntity *)R_AddRefEntityToScene(&__b, (GfxModel)DObj, a2);
        if (v5) {
          cullIn = a2->cullIn;
          if (cullIn == 1) {
            a2->cullIn = 0;
            R_UpdateXModelBoundsDelayed(v5);
          } else if (cullIn == 2) {
            a2->cullIn = 0;
            R_SkinGfxEntityDelayed(v5);
          }
        }
      }
    } else {
      CG_RegisterItemVisuals(a1, v2);
    }
  }
}

void __cdecl CG_General(struct centity_s *cent) {
  DObj_s *DObj;            // edi
  int32_t *lightingOrigin; // ecx
  float *v4;               // ebx
  _BOOL4 v5;               // eax
  GfxEntity *v6;           // eax
  int8_t cullIn;           // dl
  int32_t *v8;             // [esp+1Ch] [ebp-9Ch]
  GfxEntity __b;           // [esp+2Ch] [ebp-8Ch] BYREF

  if ((a2->nextState[8] & 0x20) == 0) {
    DObj = CG_PreProcess_GetDObj(
        *(_DWORD *)a2->nextState, *(_DWORD *)&a2->nextState[4],
        *((XModel **)cgs + *(_DWORD *)&a2->nextState[140] + 6384), a1);
    if (DObj) {
      memset(&__b, 0, sizeof(__b));
      __b.origin[0] = a2->lerpOrigin[0];
      __b.origin[1] = a2->lerpOrigin[1];
      __b.origin[2] = a2->lerpOrigin[2];
      AnglesToAxis(a2->lerpAngles, __b.axis[0]);
      __b.reType = 0;
      if ((a2->nextState[9] & 4) != 0) {
        lightingOrigin = (int32_t *)a2->lightingOrigin;
        if (a2->lightingOrigin[0] == 0.0) {
          v8 = (int32_t *)&a2->lightingOrigin[1];
          v4 = &a2->lightingOrigin[2];
          v5 = a2->lightingOrigin[1] == vec3_origin[1] &&
               a2->lightingOrigin[2] == vec3_origin[2];
        } else {
          v8 = (int32_t *)&a2->lightingOrigin[1];
          v4 = &a2->lightingOrigin[2];
          v5 = 0;
        }
        if (v5) {
          *lightingOrigin = LODWORD(a2->lerpOrigin[0]);
          a2->lightingOrigin[1] = a2->lerpOrigin[1];
          a2->lightingOrigin[2] = a2->lerpOrigin[2];
        }
        __b.lighting.dx7.colorForDir = *lightingOrigin;
        __b.lighting.dx7.sunVisibility = *v8;
        __b.lighting.baseCoords[2] = *v4;
        __b.renderFxFlags |= 0x80u;
      } else {
        a2->lightingOrigin[0] = 0.0;
        a2->lightingOrigin[1] = 0.0;
        a2->lightingOrigin[2] = 0.0;
      }
      v6 = (GfxEntity *)R_AddRefEntityToScene(&__b, (GfxModel)DObj, a2);
      if (v6) {
        cullIn = a2->cullIn;
        if (cullIn == 1) {
          a2->cullIn = 0;
          R_UpdateXModelBoundsDelayed(v6);
        } else if (cullIn == 2) {
          a2->cullIn = 0;
          R_SkinGfxEntityDelayed(v6);
        }
      }
    }
  }
}

void __cdecl CG_ScriptMover(struct centity_s *cent) {
  DObj_s *DObj;            // edi
  int32_t *lightingOrigin; // ecx
  float *v4;               // ebx
  _BOOL4 v5;               // eax
  GfxEntity *v6;           // eax
  int8_t cullIn;           // dl
  int32_t *v8;             // [esp+1Ch] [ebp-9Ch]
  GfxEntity __b;           // [esp+2Ch] [ebp-8Ch] BYREF

  if ((a2->nextState[8] & 0x20) == 0) {
    memset(&__b, 0, sizeof(__b));
    __b.origin[0] = a2->lerpOrigin[0];
    __b.origin[1] = a2->lerpOrigin[1];
    __b.origin[2] = a2->lerpOrigin[2];
    AnglesToAxis(a2->lerpAngles, __b.axis[0]);
    __b.renderFxFlags = 64;
    if (*(_UNKNOWN **)&a2->nextState[156] == &unk_FFFFFF) {
      __b.reType = 3;
      R_AddRefEntityToScene(&__b,
                            *(GfxModel *)((char *)cgs +
                                          4 * *(_DWORD *)&a2->nextState[140] +
                                          29068),
                            0);
    } else {
      DObj = CG_PreProcess_GetDObj(
          *(_DWORD *)a2->nextState, *(_DWORD *)&a2->nextState[4],
          *((XModel **)cgs + *(_DWORD *)&a2->nextState[140] + 6384), a1);
      if (DObj) {
        __b.reType = 0;
        if ((a2->nextState[9] & 4) != 0) {
          lightingOrigin = (int32_t *)a2->lightingOrigin;
          if (a2->lightingOrigin[0] == 0.0) {
            v8 = (int32_t *)&a2->lightingOrigin[1];
            v4 = &a2->lightingOrigin[2];
            v5 = a2->lightingOrigin[1] == vec3_origin[1] &&
                 a2->lightingOrigin[2] == vec3_origin[2];
          } else {
            v8 = (int32_t *)&a2->lightingOrigin[1];
            v4 = &a2->lightingOrigin[2];
            v5 = 0;
          }
          if (v5) {
            *lightingOrigin = LODWORD(a2->lerpOrigin[0]);
            a2->lightingOrigin[1] = a2->lerpOrigin[1];
            a2->lightingOrigin[2] = a2->lerpOrigin[2];
          }
          __b.lighting.dx7.colorForDir = *lightingOrigin;
          __b.lighting.dx7.sunVisibility = *v8;
          __b.lighting.baseCoords[2] = *v4;
          __b.renderFxFlags |= 0x80u;
        } else {
          a2->lightingOrigin[0] = 0.0;
          a2->lightingOrigin[1] = 0.0;
          a2->lightingOrigin[2] = 0.0;
        }
        v6 = (GfxEntity *)R_AddRefEntityToScene(&__b, (GfxModel)DObj, a2);
        if (v6) {
          cullIn = a2->cullIn;
          if (cullIn == 1) {
            a2->cullIn = 0;
            R_UpdateXModelBoundsDelayed(v6);
          } else if (cullIn == 2) {
            a2->cullIn = 0;
            R_SkinGfxEntityDelayed(v6);
          }
        }
      }
    }
  }
}

void __cdecl CG_ProcessEntity(struct centity_s *cent) {
  void *v1;           // ebx
  signed int v2;      // eax
  signed int dl_time; // edx
  float v4;           // xmm0_4
  int v5;             // edx
  EffectTemplate *v6; // edi
  int v7;             // eax
  GfxModel v8;        // edi
  GfxEntity *v9;      // eax
  int8_t cullIn;      // dl
  int v11;            // ecx
  float v12;          // xmm1_4
  int v13;            // [esp+0h] [ebp-C8h]
  int v14;            // [esp+4h] [ebp-C4h]
  XModel *v15;        // [esp+8h] [ebp-C0h]
  float v16;          // [esp+28h] [ebp-A0h]
  float *v17;         // [esp+2Ch] [ebp-9Ch]
  GfxEntity __b;      // [esp+3Ch] [ebp-8Ch] BYREF

  CG_EntityEffects(a1);
  switch (*(_DWORD *)&a1->nextState[4]) {
  case 0:
    CG_General(a1);
    return;
  case 1:
    CG_Player(a1);
    return;
  case 2:
    CG_Corpse(a1);
    return;
  case 3:
    CG_Item(a1);
    return;
  case 4:
    CG_Missile(a1);
    return;
  case 5:
    return;
  case 6:
    CG_ScriptMover(a1);
    return;
  case 7:
    CG_SoundBlend(a1);
    return;
  case 8:
    v1 = cg;
    v2 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    dl_time = a1->dl_time;
    if (v2 >= dl_time) {
      v11 = (int)*(float *)&a1->nextState[108];
      if (v11 > v2 - dl_time)
        return;
      do {
        dl_time += v11;
        a1->dl_time = dl_time;
      } while (v11 <= *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v1) - dl_time);
    } else {
      a1->dl_time = v2;
    }
    v4 = *(float *)&a1->nextState[104];
    if (v4 == 0.0 || (v16 = Vec3DistanceSq((char *)cg + 154584, a1->lerpOrigin),
                      v16 < (float)(v4 * v4))) {
      v5 = *(_DWORD *)&a1->nextState[216];
      if ((unsigned int)(v5 - 1) > 0x3E) {
        Com_Printf("ERROR: CG_PlayFx called with invalid effect id %i\n",
                   *(_DWORD *)&a1->nextState[216]);
      } else {
        v6 = (EffectTemplate *)*((_DWORD *)cgs + v5 + 6640);
        v17 = (float *)&a1->nextState[92];
        if ((float)((float)((float)(*(float *)&a1->nextState[92] *
                                    *(float *)&a1->nextState[92]) +
                            (float)(*(float *)&a1->nextState[96] *
                                    *(float *)&a1->nextState[96])) +
                    (float)(*(float *)&a1->nextState[100] *
                            *(float *)&a1->nextState[100])) == 0.0) {
          FX_PlaySimpleEffect(v6, a1->lerpOrigin);
        } else {
          v7 = *(_DWORD *)&a1->nextState[160];
          if (v7) {
            ByteToDir(v7, (float *)&__b.reType);
            v12 = -(float)((float)((float)(*(float *)&__b.reType *
                                           *(float *)&a1->nextState[92]) +
                                   (float)(*(float *)&a1->nextState[96] *
                                           *(float *)&__b.renderFxFlags)) +
                           (float)(*(float *)&a1->nextState[100] *
                                   __b.lighting.baseCoords[0]));
            *(float *)&__b.reType = *(float *)&__b.reType +
                                    (float)(v12 * *(float *)&a1->nextState[92]);
            *(float *)&__b.renderFxFlags =
                (float)(v12 * *(float *)&a1->nextState[96]) +
                *(float *)&__b.renderFxFlags;
            __b.lighting.baseCoords[0] =
                (float)(v12 * *(float *)&a1->nextState[100]) +
                __b.lighting.baseCoords[0];
            Vec3Normalize(&__b);
            FX_PlayEffect(v6, a1->lerpOrigin, v17, (const float *)&__b.reType);
          } else {
            FX_PlayEffect(v6, a1->lerpOrigin, v17);
          }
        }
      }
    }
    return;
  case 9:
    if ((a1->nextState[8] & 0x20) == 0) {
      v8.obj = CG_PreProcess_GetDObj(v13, v14, v15);
      if (v8.obj) {
        memset(&__b, 0, sizeof(__b));
        *(_QWORD *)__b.origin = *(_QWORD *)a1->lerpOrigin;
        __b.origin[2] = a1->lerpOrigin[2];
        __b.lighting.dx7 = *($_3622 *)__b.origin;
        __b.lighting.baseCoords[2] = __b.origin[2] + 32.0;
        __b.renderFxFlags = 128;
        AnglesToAxis(a1->lerpAngles, (float *)__b.axis);
        __b.reType = 0;
        v9 = (GfxEntity *)R_AddRefEntityToScene(&__b, v8, a1);
        if (v9) {
          cullIn = a1->cullIn;
          if (cullIn == 1) {
            a1->cullIn = 0;
            R_UpdateXModelBoundsDelayed(v9);
          } else if (cullIn == 2) {
            a1->cullIn = 0;
            R_SkinGfxEntityDelayed(v9);
          }
        }
      }
    }
    return;
  default:
    Com_Error(1, "\x15Bad entity type: %i\n", *(_DWORD *)&a1->nextState[4]);
    return;
  }
}

void __cdecl CG_AddPacketEntities() {
  void *v0;   // ebx
  int v1;     // ecx
  int result; // eax
  int v3;     // ebx
  int v4;     // esi
  int v5;     // edx
  int *v6;    // eax
  int v7;     // [esp+1Ch] [ebp-1Ch]

  v0 = cg;
  *(_DWORD *)((char *)&loc_2C5A0 + (_DWORD)cg) = 0;
  *((_DWORD *)v0 + 41272) = 0;
  v1 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v0);
  *(float *)((char *)&loc_284E4 + (_DWORD)v0) =
      (float)(360 * (v1 & 0xFFF)) / 4095.0;
  *((_DWORD *)v0 + 41274) = 0;
  *((_DWORD *)v0 + 41284) = 0;
  *((float *)v0 + 41285) = (float)(360 * (v1 & 0x7FF)) * 0.00048828125;
  *((_DWORD *)v0 + 41286) = 0;
  *((_DWORD *)v0 + 41296) = 0;
  *((float *)v0 + 41297) = (float)(360 * (v1 & 0x3FF)) * 0.0009765625;
  *((_DWORD *)v0 + 41298) = 0;
  AnglesToAxis((float *)v0 + 41272, (float *)((char *)&loc_284EC + (_DWORD)v0));
  AnglesToAxis((float *)v0 + 41284, (float *)v0 + 41287);
  AnglesToAxis((float *)v0 + 41296, (float *)v0 + 41299);
  v7 = *((_DWORD *)v0 + 38998);
  result = *((_DWORD *)v0 + 9);
  if (*(int *)(result + 9908) > 0) {
    v3 = 0;
    v4 = 0;
    do {
      while (1) {
        v5 = *(_DWORD *)(v4 + result + 9916);
        if (v7 != v5) {
          v6 = (int *)((char *)cg_entities + 548 * v5);
          if (v6[61] <= 9)
            break;
        }
        ++v3;
        v4 += 240;
        result = *((_DWORD *)cg + 9);
        if (*(_DWORD *)(result + 9908) <= v3)
          return result;
      }
      CG_ProcessEntity((centity_s *)v6);
      ++v3;
      v4 += 240;
      result = *((_DWORD *)cg + 9);
    } while (*(_DWORD *)(result + 9908) > v3);
  }
  return result;
}

enum<unnamed - tag> mg42anims_t;
void __cdecl CG_Player_DoControllers(struct centity_s const *, int *const) {
  UNIMPLEMENTED();
}

void *__cdecl CG_AllocAnimTree(int) { return MT_Alloc(a1, 5); }

void __cdecl CG_InterpolateEntityPosition(struct centity_s *) {
  _DWORD *v2; // esi
  int v3;     // eax
  _DWORD *v4; // ebx
  float v5;   // [esp+18h] [ebp-40h]
  int v6;     // [esp+1Ch] [ebp-3Ch]
  float v7;   // [esp+28h] [ebp-30h] BYREF
  float v8;   // [esp+2Ch] [ebp-2Ch]
  float v9;   // [esp+30h] [ebp-28h]
  float v10;  // [esp+34h] [ebp-24h] BYREF
  float v11;  // [esp+38h] [ebp-20h]
  float v12;  // [esp+3Ch] [ebp-1Ch]

  v2 = cg;
  v5 = *((float *)cg + 38634);
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 12),
                        *(_DWORD *)(*((_DWORD *)cg + 8) + 8), &v10);
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 252),
                        *(_DWORD *)(v2[9] + 8), &v7);
  *(float *)(a1 + 492) = v10 + (float)((float)(v7 - v10) * v5);
  *(float *)(a1 + 496) = v11 + (float)((float)(v8 - v11) * v5);
  *(float *)(a1 + 500) = v12 + (float)((float)(v9 - v12) * v5);
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 48), *(_DWORD *)(v2[8] + 8),
                        &v10);
  BG_EvaluateTrajectory((const trajectory_t *)(a1 + 288),
                        *(_DWORD *)(v2[9] + 8), &v7);
  *(float *)(a1 + 504) = LerpAngle(v10, v7, v5);
  *(float *)(a1 + 508) = LerpAngle(v11, v8, v5);
  *(float *)(a1 + 512) = LerpAngle(v12, v9, v5);
  if (*(_DWORD *)(a1 + 244) == 1) {
    v3 = *(_DWORD *)(a1 + 384);
    v4 = &v2[302 * v3 + 229952];
    v6 = (int)&v2[302 * v3 + 229957];
    *(float *)(v6 + 992) =
        LerpAngle(*(float *)(a1 + 108), *(float *)(a1 + 348), v5);
    v4[255] = *(_DWORD *)(a1 + 504);
    v4[256] = *(_DWORD *)(a1 + 508);
    v4[257] = *(_DWORD *)(a1 + 512);
    *(_DWORD *)(a1 + 504) = 0;
    *(_DWORD *)(a1 + 512) = 0;
    *(float *)(v6 + 996) =
        LerpAngle(*(float *)(a1 + 212), *(float *)(a1 + 452), v5);
  }
}

void __cdecl CG_mg42_DoControllers(struct centity_s const *, int *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DoControllers(struct centity_s const *, int *const) {
  UNIMPLEMENTED();
}

struct DObj_s *__cdecl CG_PreProcess_GetDObj(int, int, struct XModel *) {
  UNIMPLEMENTED();
}

void __cdecl CG_LoopFx(struct centity_s *) { UNIMPLEMENTED(); }

void __cdecl CG_mg42(struct centity_s *) { UNIMPLEMENTED(); }
