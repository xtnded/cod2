int __cdecl DebugLine(float *const, float *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl G_AddEvent(struct gentity_s *ent, int event, int eventParm)
{
  int32_t client;        // edx
  int result;            // eax
  int32_t eventSequence; // eax
  int v6;                // edx

  client = a1->client;
    if (client) {
      *(_DWORD *)(client + 4 * (*(_DWORD *)(client + 164) & 3) + 168) = a2;
      *(_DWORD *)(a1->client + 4 * ((*(_DWORD *)(a1->client + 164))++ & 3) +
                  184) = a3;
    }
    else {
      eventSequence = a1->s.eventSequence;
      v6 = eventSequence & 3;
      *(_DWORD *)&a1->s.events[4 * v6] = a2;
      *(_DWORD *)&a1->s.eventParms[4 * v6] = a3;
      a1->s.eventSequence = eventSequence + 1;
    }
  a1->eventTime = dword_193466C;
  result = dword_193466C;
  a1->r.eventTime = dword_193466C;
  return result;
}

int __cdecl G_GetPlayerCorpseIndex(struct gentity_s *ent)
{
  int v1; // eax
  int *i; // edx

  v1 = 0;
    for (i = &g_scr_data; a1->s.number != i[1071]; i += 306) {
        if (++v1 == 8) {
          LOBYTE(v1) = 0;
          return v1;
        }
    }
  return v1;
}

void __cdecl G_FreeEntityRefs(struct gentity_s *)
{
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl G_Find(struct gentity_s *, int, unsigned short)
{
  UNIMPLEMENTED();
}

int __cdecl G_EntIsLinkedTo(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

char const *__cdecl G_ModelName(int index)
{
  return SV_GetConfigstringConst(a1 + 334);
}

void __cdecl G_SetAngle(struct gentity_s *ent, float const *const angle)
{
  int result; // eax

  *(float *)&a1->s.apos[12] = *a2;
  *(float *)&a1->s.apos[16] = a2[1];
  *(float *)&a1->s.apos[20] = a2[2];
  *(_DWORD *)a1->s.apos = 0;
  *(_DWORD *)&a1->s.apos[4] = 0;
  *(_DWORD *)&a1->s.apos[8] = 0;
  *(_DWORD *)&a1->s.apos[24] = 0;
  *(_DWORD *)&a1->s.apos[28] = 0;
  *(_DWORD *)&a1->s.apos[32] = 0;
  a1->r.currentAngles[0] = *a2;
  a1->r.currentAngles[1] = a2[1];
  result = *((_DWORD *)a2 + 2);
  LODWORD(a1->r.currentAngles[2]) = result;
  return result;
}

void __cdecl G_SetOrigin(struct gentity_s *ent, float const *const origin)
{
  int result; // eax

  a1->s.pos.trBase[0] = *a2;
  a1->s.pos.trBase[1] = a2[1];
  a1->s.pos.trBase[2] = a2[2];
  a1->s.pos.trType = 0;
  a1->s.pos.trTime = 0;
  a1->s.pos.trDuration = 0;
  a1->s.pos.trDelta[0] = 0.0;
  a1->s.pos.trDelta[1] = 0.0;
  a1->s.pos.trDelta[2] = 0.0;
  a1->r.currentOrigin[0] = *a2;
  a1->r.currentOrigin[1] = a2[1];
  result = *((_DWORD *)a2 + 2);
  LODWORD(a1->r.currentOrigin[2]) = result;
  return result;
}

void __cdecl G_PlaySoundAliasAsMaster(struct gentity_s *, unsigned char)
{
  UNIMPLEMENTED();
}

void __cdecl G_PlaySoundAlias(struct gentity_s *ent, unsigned char index)
{
  int result;            // eax
  int32_t client;        // edx
  int32_t eventSequence; // eax
  int v5;                // edx

  result = a2;
    if (a2) {
      client = a1->client;
        if (client) {
          *(_DWORD *)(client + 4 * (*(_DWORD *)(client + 164) & 3) + 168) = 179;
          *(_DWORD *)(a1->client + 4 * ((*(_DWORD *)(a1->client + 164))++ & 3) +
                      184) = a2;
        }
        else {
          eventSequence = a1->s.eventSequence;
          v5 = eventSequence & 3;
          *(_DWORD *)&a1->s.events[4 * v5] = 179;
          *(_DWORD *)&a1->s.eventParms[4 * v5] = a2;
          a1->s.eventSequence = eventSequence + 1;
        }
      a1->eventTime = dword_193466C;
      result = dword_193466C;
      a1->r.eventTime = dword_193466C;
    }
  return result;
}

void __cdecl G_AddPredictableEvent(struct gentity_s *ent, int event,
                                   int eventParm)
{
  int32_t result; // eax

  result = a1->client;
  if (result)
    return BG_AddPredictableEventToPlayerstate(a2, a3,
                                               (playerState_s *)a1->client);
  return result;
}

void __cdecl PlayerCorpse_Free(struct gentity_s *)
{
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl G_FindStr(struct gentity_s *, int, char const *)
{
  UNIMPLEMENTED();
}

int __cdecl G_XModelBad(int index)
{
  return XModelBad((const XModel *)cached_models[a1]);
}

int __cdecl infront(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl G_SetConstString(unsigned short *to, char const *from)
{
  UNIMPLEMENTED();
}

void __cdecl G_InitGentity(struct gentity_s *e)
{
  UNIMPLEMENTED();
}

void __cdecl G_SafeDObjFree(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl G_EntUnlink(struct gentity_s *ent)
{
  _BYTE *v2;      // esi
  int32_t client; // edx
  gentity_s *v4;  // eax
  int v5;         // edx
  float v6[5];    // [esp+14h] [ebp-14h] BYREF

  v2 = *(_BYTE **)a2->tagInfo;
    if (v2) {
      a2->s.pos.trBase[0] = a2->r.currentOrigin[0];
      a2->s.pos.trBase[1] = a2->r.currentOrigin[1];
      a2->s.pos.trBase[2] = a2->r.currentOrigin[2];
      a2->s.pos.trType = 0;
      a2->s.pos.trTime = 0;
      a2->s.pos.trDuration = 0;
      a2->s.pos.trDelta[0] = 0.0;
      a2->s.pos.trDelta[1] = 0.0;
      a2->s.pos.trDelta[2] = 0.0;
      *(float *)&a2->s.apos[12] = a2->r.currentAngles[0];
      *(float *)&a2->s.apos[16] = a2->r.currentAngles[1];
      *(float *)&a2->s.apos[20] = a2->r.currentAngles[2];
      *(_DWORD *)a2->s.apos = 0;
      *(_DWORD *)&a2->s.apos[4] = 0;
      *(_DWORD *)&a2->s.apos[8] = 0;
      *(_DWORD *)&a2->s.apos[24] = 0;
      *(_DWORD *)&a2->s.apos[28] = 0;
      *(_DWORD *)&a2->s.apos[32] = 0;
      client = a2->client;
        if (client) {
          v6[0] = *(float *)(client + 232);
          v6[1] = *(float *)(client + 236);
          v6[2] = 0.0;
          SetClientViewAngle(a2, v6);
        }
      v4 = *(gentity_s **)(*(_DWORD *)v2 + 524);
        if (a2 == v4) {
          *(_DWORD *)(*(_DWORD *)v2 + 524) = *((_DWORD *)v2 + 1);
        }
        else {
            do {
              v5 = *(_DWORD *)v4->tagInfo;
              v4 = *(gentity_s **)(v5 + 4);
            }
          while (a2 != v4);
          *(_DWORD *)(v5 + 4) = *((_DWORD *)v2 + 1);
        }
      *(_DWORD *)a2->tagInfo = 0;
      Scr_SetString(a1, (unsigned __int16 *)v2 + 4, 0);
      MT_Free(v2, 112);
    }
}

void __cdecl G_UpdateTagInfo(struct gentity_s *, int)
{
  UNIMPLEMENTED();
}

int __cdecl G_EntLinkToWithOffset(struct gentity_s *ent,
                                  struct gentity_s *parent,
                                  unsigned int tagName,
                                  float const *const originOffset,
                                  float const *const anglesOffset)
{
  UNIMPLEMENTED();
}

void __cdecl G_UpdateTagInfoOfChildren(struct gentity_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl G_OverrideModel(int modelindex, char const *defaultModelName)
{
  UNIMPLEMENTED();
}

int __cdecl G_FindConfigstringIndex(char const *name, int start, int max,
                                    int create, char const *errormsg)
{
  UNIMPLEMENTED();
}

int __cdecl G_RumbleIndex(char const *)
{
  UNIMPLEMENTED();
}

unsigned char __cdecl G_SoundAliasIndex(char const *name)
{
  UNIMPLEMENTED();
}

int __cdecl G_ShellShockIndex(char const *name)
{
  UNIMPLEMENTED();
}

int __cdecl G_EffectIndex(char const *name)
{
  UNIMPLEMENTED();
}

int __cdecl G_TagIndex(char const *name)
{
  UNIMPLEMENTED();
}

int __cdecl G_ModelIndex(char const *name)
{
  int v1;                        // esi
  char v3;                       // bl
  const char *ConfigstringConst; // eax
  const char *v5;                // eax
  char v6;                       // [esp+8h] [ebp-20h]

    if (*__s1) {
      v1 = 1;
        while (1) {
          v3 = v1 + 78;
          ConfigstringConst = (const char *)SV_GetConfigstringConst(v1 + 334);
          if (!*ConfigstringConst)
            break;
          if (!stricmp(ConfigstringConst, __s1))
            return v1;
            if (++v1 == 256) {
              v3 = 78;
              break;
            }
        }
        if (!dword_193449C) {
          v5 = (const char *)va("model '%s' not precached", (char)__s1);
          Scr_Error(v5);
        }
      if (v1 == 256)
        Com_Error(1, "\x15G_ModelIndex: overflow", v6);
      cached_models[v1] = SV_XModelGet(__s1);
      SV_SetConfigstring(v3, __s1);
      return v1;
    }
    else {
      return 0;
    }
}

int __cdecl G_ShaderIndex(char const *name)
{
  char __dst[72]; // [esp+20h] [ebp-48h] BYREF

  strcpy(__dst, __src);
  I_strlwr(__dst);
  return G_FindConfigstringIndex(__dst, 30, 128, dword_193449C, "shader");
}

int __cdecl G_LocalizedStringIndex(char const *string)
{
  UNIMPLEMENTED();
}

int __cdecl G_AnimScriptSound(int client, struct snd_alias_list_t *aliasList)
{
  UNIMPLEMENTED();
}

void __cdecl G_SetModel(struct gentity_s *ent, char const *modelName)
{
  char *result; // eax

  result = __s1;
    if (*__s1) {
      result = (char *)G_ModelIndex(__s1);
      a1->model = (char)result;
    }
    else {
      a1->model = 0;
    }
  return result;
}

void __cdecl G_FreeEntity(struct gentity_s *ed)
{
  UNIMPLEMENTED();
}

int __cdecl G_GetFreePlayerCorpseIndex()
{
  gentity_s *v0;   // edx
  char *classname; // esi
  gentity_s *v2;   // ecx
  int8_t *p_inuse; // eax
  int v4;          // edi
  int v5;          // ebx
  int *i;          // esi
  int v7;          // eax
  float v9;        // [esp+18h] [ebp-30h]
  float v10;       // [esp+1Ch] [ebp-2Ch]
  float v11[9];    // [esp+24h] [ebp-24h] BYREF

  v0 = &g_entities + dword_193448C;
    if (v0 <= &g_entities) {
    LABEL_7:
      v2 = 0;
    }
    else {
      classname = g_entities.classname;
      v2 = &g_entities;
      p_inuse = &g_entities.r.inuse;
        while (!*p_inuse || !*(_WORD *)classname ||
               word_195B0B2 != *(_WORD *)classname) {
          ++v2;
          p_inuse += 560;
          classname += 560;
          if (v0 <= v2)
            goto LABEL_7;
        }
    }
  v11[0] = v2->s.pos.trBase[0];
  v11[1] = v2->s.pos.trBase[1];
  v11[2] = v2->s.pos.trBase[2];
  v10 = -1.0;
  v4 = 0;
  v5 = 0;
    for (i = &g_scr_data;; i += 306) {
      v7 = i[1071];
      if (v7 == -1)
        break;
      v9 = Vec3DistanceSq(dword_1934484[v7].r.currentOrigin, v11);
        if (v9 > v10) {
          v10 = v9;
          v4 = v5;
        }
        if (++v5 == 8) {
          G_FreeEntity(v9, &dword_1934484[*(&g_scr_data + 306 * v4 + 1071)]);
          *(&g_scr_data + 306 * v4 + 1071) = -1;
          return v4;
        }
    }
  return v5;
}

struct gentity_s *__cdecl G_SpawnPlayerClone()
{
  UNIMPLEMENTED();
}

void __cdecl G_PrintEntities()
{
  int v0;              // esi
  gentity_s *v1;       // ebx
  const char *v2;      // eax
  unsigned __int16 v3; // ax
  double v4;           // [esp+38h] [ebp-30h]
  double v5;           // [esp+40h] [ebp-28h]
  double v6;           // [esp+48h] [ebp-20h]

    if (dword_193448C > 0) {
      v0 = 0;
      v1 = &g_entities;
        do {
          v4 = v1->r.currentOrigin[2];
          v5 = v1->r.currentOrigin[1];
          v6 = v1->r.currentOrigin[0];
          v3 = *(_WORD *)v1->classname;
          if (v3)
            v2 = (const char *)SL_ConvertToString(v3);
          else
            v2 = (const char *)&inData;
          Com_Printf("%4i: '%s', origin: %f %f %f\n", v0++, v2, v6, v5, v4);
          ++v1;
        }
      while (v0 < dword_193448C);
    }
}

struct gentity_s *__cdecl G_PickTarget(unsigned short)
{
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl G_Spawn()
{
  UNIMPLEMENTED();
}

void __cdecl G_DObjUpdate(struct gentity_s *ent)
{
  unsigned __int8 model;  // al
  int32_t v9;             // edx
  gentity_s *tagChildren; // eax
  int v11;                // edx
  gentity_s *v12;         // ebx
  int32_t eType;          // eax
  gentity_s *v14;         // ebx
  gentity_s *v15;         // esi
  int v16;                // edi
  unsigned __int8 v17;    // al
  gentity_s *v18;         // eax
  gentity_s *v19;         // esi
  int v20;                // ebx
  gentity_s *v21;         // edi
  unsigned __int16 v22;   // ax
  int BoneIndex;          // eax
  char *v24;              // [esp+18h] [ebp-80h]
  unsigned __int16 v25;   // [esp+1Ch] [ebp-7Ch]
  DObjModel_s v26;        // [esp+20h] [ebp-78h] BYREF
  char v27;               // [esp+8Ch] [ebp-Ch] BYREF

  if (a8->client)
    return;
  Com_SafeServerDObjFree(a2, a8->s.number);
  model = a8->model;
  v9 = model;
    if (!model) {
      tagChildren = (gentity_s *)a8->tagChildren;
        if (tagChildren) {
            while (1) {
              v11 = *(_DWORD *)tagChildren->tagInfo;
              v12 = *(gentity_s **)(v11 + 4);
              if (*(_WORD *)(v11 + 8))
                G_EntUnlink(a2, tagChildren);
              else
                *(_DWORD *)(v11 + 12) = -1;
              if (!v12)
                break;
              tagChildren = v12;
            }
        }
      return;
    }
  *(_DWORD *)v26.model = cached_models[model];
  *(_DWORD *)v26.boneName = 0;
  v26.ignoreCollision = 0;
  eType = a8->s.eType;
    if (!eType) {
      v18 = a8;
    LABEL_19:
      v18->s.index.item = v9;
      goto LABEL_14;
    }
    if (eType == 6 || eType == 9) {
      v18 = a8;
      goto LABEL_19;
    }
LABEL_14:
  v14 = a8;
  v15 = a8;
  v25 = 1;
  v16 = 0;
  v24 = &v27;
    do {
      v17 = v14->attachModelNames[0];
        if (v17) {
          *((_DWORD *)v24 - 24) = cached_models[v17];
          *((_DWORD *)v24 - 23) =
              SL_ConvertToString(*(unsigned __int16 *)v15->attachTagNames);
          *((_DWORD *)v24 - 22) =
              ((int)(unsigned __int8)a8->attachIgnoreCollision >> v16) & 1;
          ++v25;
          v24 += 12;
        }
      ++v16;
      v14 = (gentity_s *)((char *)v14 + 1);
      v15 = (gentity_s *)((char *)v15 + 2);
    }
  while (v16 != 7);
  Com_ServerDObjCreate(a1, a2, a3, a4, a5, a6, a7, &v26, v25, 0, a8->s.number);
  v19 = (gentity_s *)a8->tagChildren;
    if (v19) {
        while (1) {
          v20 = *(_DWORD *)v19->tagInfo;
          v21 = *(gentity_s **)(v20 + 4);
          v22 = *(_WORD *)(v20 + 8);
            if (v22) {
              BoneIndex = SV_DObjGetBoneIndex(*(gentity_s **)v20, v22);
              *(_DWORD *)(v20 + 12) = BoneIndex;
              if (BoneIndex < 0)
                G_EntUnlink(a2, v19);
            }
            else {
              *(_DWORD *)(v20 + 12) = -1;
            }
          if (!v21)
            break;
          v19 = v21;
        }
    }
}

struct gentity_s *__cdecl G_TempEntity(float const *const origin, int event)
{
  gentity_s *v2; // ebx
  float v3;      // xmm2_4
  float v4;      // xmm1_4
  float v5;      // xmm0_4

  v2 = G_Spawn();
  v2->s.eType = a2 + 10;
  Scr_SetString((unsigned __int16 *)v2->classname,
                (unsigned __int16)word_195B0D0);
  v2->eventTime = dword_193466C;
  v2->r.eventTime = dword_193466C;
  v2->freeAfterEvent = 1;
  v3 = (float)(int)*a1;
  v4 = (float)(int)a1[1];
  v5 = (float)(int)a1[2];
  v2->s.pos.trBase[0] = v3;
  v2->s.pos.trBase[1] = v4;
  v2->s.pos.trBase[2] = v5;
  v2->s.pos.trType = 0;
  v2->s.pos.trTime = 0;
  v2->s.pos.trDuration = 0;
  v2->s.pos.trDelta[0] = 0.0;
  v2->s.pos.trDelta[1] = 0.0;
  v2->s.pos.trDelta[2] = 0.0;
  v2->r.currentOrigin[0] = v3;
  v2->r.currentOrigin[1] = v4;
  v2->r.currentOrigin[2] = v5;
  SV_LinkEntity(v2);
  return v2;
}

void __cdecl G_DObjCalcBone(struct gentity_s *ent, int boneIndex)
{
  int result;                             // eax
  void(__cdecl * v3)(gentity_s *, int *); // eax
  int v4[10];                             // [esp+10h] [ebp-28h] BYREF

  result = SV_DObjCreateSkelForBone(a1, a2);
    if (!result) {
      SV_DObjGetHierarchyBits(a1, a2, v4);
      SV_DObjCalcAnim(a1, v4);
      v3 = (void(__cdecl *)(gentity_s *, int *))
          entityHandlers[10 * (unsigned __int8)a1->handler + 7];
      if (v3)
        v3(a1, v4);
      return SV_DObjCalcSkel(a1, v4);
    }
  return result;
}

void __cdecl G_DObjCalcPose(struct gentity_s *ent)
{
  int result;                             // eax
  void(__cdecl * v2)(gentity_s *, int *); // eax
  int v3[6];                              // [esp+10h] [ebp-18h] BYREF

  memset(v3, 255, 16);
  result = SV_DObjCreateSkelForBones(a1, v3);
    if (!result) {
      SV_DObjCalcAnim(a1, v3);
      v2 = (void(__cdecl *)(gentity_s *, int *))
          entityHandlers[10 * (unsigned __int8)a1->handler + 7];
      if (v2)
        v2(a1, v3);
      return SV_DObjCalcSkel(a1, v3);
    }
  return result;
}

void __cdecl G_CalcTagParentAxis(struct gentity_s * ent, float  parentAxis)[3])
{
  UNIMPLEMENTED();
}

void __cdecl G_EntDetachAll(struct gentity_s *ent)
{
  gentity_s *v8;                    // esi
  int v9;                           // edi
  unsigned __int16 *attachTagNames; // ebx

  v8 = a8;
  v9 = 0;
  attachTagNames = (unsigned __int16 *)a8->attachTagNames;
    do {
      v8->attachModelNames[0] = 0;
      Scr_SetString(a2, attachTagNames, 0);
      ++v9;
      ++attachTagNames;
      v8 = (gentity_s *)((char *)v8 + 1);
    }
  while (v9 != 7);
  a8->attachIgnoreCollision = 0;
  G_DObjUpdate(a1, a2, a3, a4, a5, a6, a7, a8);
}

int __cdecl G_EntDetach(struct gentity_s *ent, char const *modelName,
                        unsigned int tagName)
{
  UNIMPLEMENTED();
}

int __cdecl G_EntAttach(struct gentity_s *ent, char const *modelName,
                        unsigned int tagName, int ignoreCollision)
{
  UNIMPLEMENTED();
}

void __cdecl G_PlaySoundAliasAtPoint(float const *const, unsigned char)
{
  UNIMPLEMENTED();
}

struct DObjAnimMat_s *__cdecl G_DObjGetLocalTagMatrix(struct gentity_s *ent,
                                                      unsigned int tagName)
{
  int BoneIndex; // eax
  int v3;        // ebx

  BoneIndex = SV_DObjGetBoneIndex(a1, a2);
  v3 = BoneIndex;
  if (BoneIndex < 0)
    return 0;
  G_DObjCalcBone(a1, BoneIndex);
  return 32 * v3 + SV_DObjGetMatrixArray(a1);
}

void __cdecl G_SetFixedLink(struct gentity_s *ent, int eAngles)
{
  int v2;       // edx
  float v3[12]; // [esp+10h] [ebp-78h] BYREF
  float v4[9];  // [esp+40h] [ebp-48h] BYREF
  float v5;     // [esp+64h] [ebp-24h] BYREF
  float v6;     // [esp+68h] [ebp-20h]
  float v7;     // [esp+6Ch] [ebp-1Ch]

  G_CalcTagParentAxis(a1, (float(*)[3])v3);
  v2 = *(_DWORD *)a1->tagInfo;
    switch (a2) {
    case 1:
      MatrixMultiply43((float *)(v2 + 16), v3, v4);
      a1->r.currentOrigin[0] = v5;
      a1->r.currentOrigin[1] = v6;
      a1->r.currentOrigin[2] = v7;
      a1->r.currentAngles[1] = vectoyaw(v4);
      break;
    case 2:
      MatrixTransformVector43((const float *)(v2 + 52), (const float(*)[3])v3,
                              &v5);
      a1->r.currentOrigin[0] = v5;
      a1->r.currentOrigin[1] = v6;
      a1->r.currentOrigin[2] = v7;
      break;
    case 0:
      MatrixMultiply43((float *)(v2 + 16), v3, v4);
      a1->r.currentOrigin[0] = v5;
      a1->r.currentOrigin[1] = v6;
      a1->r.currentOrigin[2] = v7;
      AxisToAngles(v4, a1->r.currentAngles);
      break;
    }
}

void __cdecl G_CalcTagAxis(struct gentity_s *ent, int bAnglesOnly)
{
  int v3;       // [esp+1Ch] [ebp-ACh]
  float v4[12]; // [esp+20h] [ebp-A8h] BYREF
  float v5[12]; // [esp+50h] [ebp-78h] BYREF
  float v6[18]; // [esp+80h] [ebp-48h] BYREF

  G_CalcTagParentAxis(a1, (float(*)[3])v5);
  AnglesToAxis(a1->r.currentAngles, v6);
  v3 = *(_DWORD *)a1->tagInfo;
    if (a2) {
      MatrixTranspose(v5, v4);
      return MatrixMultiply(v6, v4, (float *)(v3 + 16));
    }
    else {
      MatrixInverseOrthogonal43((int)v5, (int)v4);
      v6[9] = a1->r.currentOrigin[0];
      v6[10] = a1->r.currentOrigin[1];
      v6[11] = a1->r.currentOrigin[2];
      return MatrixMultiply43(v6, v4, (float *)(v3 + 16));
    }
}

void __cdecl G_CalcTagParentRelAxis(struct gentity_s *, float (*const)[3])
{
  UNIMPLEMENTED();
}

int __cdecl G_EntLinkTo(struct gentity_s *ent, struct gentity_s *parent,
                        unsigned int tagName)
{
  UNIMPLEMENTED();
}

int __cdecl G_DObjGetWorldTagPos(struct gentity_s *ent, unsigned int tagName,
                                 float *const pos)
{
  int BoneIndex; // eax
  int v4;        // ebx
  int v5;        // edi
  float v7[18];  // [esp+10h] [ebp-48h] BYREF

  BoneIndex = SV_DObjGetBoneIndex(a1, a2);
  v4 = BoneIndex;
  if (BoneIndex < 0)
    return 0;
  G_DObjCalcBone(a1, BoneIndex);
  v5 = 32 * v4 + SV_DObjGetMatrixArray(a1);
  if (!v5)
    return 0;
  AnglesToAxis(a1->r.currentAngles, v7);
  v7[9] = a1->r.currentOrigin[0];
  v7[10] = a1->r.currentOrigin[1];
  v7[11] = a1->r.currentOrigin[2];
  MatrixTransformVector43((const float *)(v5 + 16), (const float(*)[3])v7, a3);
  return 1;
}

int __cdecl G_DObjGetWorldTagMatrix(struct gentity_s * ent, unsigned int tagName, float  tagMat)[3])
{
  UNIMPLEMENTED();
}

void __cdecl G_GeneralLink(struct gentity_s *ent)
{
  G_SetFixedLink(a1, 0);
  a1->s.pos.trBase[0] = a1->r.currentOrigin[0];
  a1->s.pos.trBase[1] = a1->r.currentOrigin[1];
  a1->s.pos.trBase[2] = a1->r.currentOrigin[2];
  a1->s.pos.trTime = 0;
  a1->s.pos.trDuration = 0;
  a1->s.pos.trDelta[0] = 0.0;
  a1->s.pos.trDelta[1] = 0.0;
  a1->s.pos.trDelta[2] = 0.0;
  *(float *)&a1->s.apos[12] = a1->r.currentAngles[0];
  *(float *)&a1->s.apos[16] = a1->r.currentAngles[1];
  *(float *)&a1->s.apos[20] = a1->r.currentAngles[2];
  *(_DWORD *)&a1->s.apos[4] = 0;
  *(_DWORD *)&a1->s.apos[8] = 0;
  *(_DWORD *)&a1->s.apos[24] = 0;
  *(_DWORD *)&a1->s.apos[28] = 0;
  *(_DWORD *)&a1->s.apos[32] = 0;
  a1->s.pos.trType = 1;
  *(_DWORD *)a1->s.apos = 1;
  return SV_LinkEntity(a1);
}

void __cdecl G_FreeEntityDelay(struct gentity_s *ed)
{
  UNIMPLEMENTED();
}

void __cdecl G_KillBox(struct gentity_s *)
{
  UNIMPLEMENTED();
}

int __cdecl G_DObjUpdateServerTime(struct gentity_s *ent, int bNotify)
{
  return SV_DObjUpdateServerTime(a1, (float)dword_1934674 * 0.001, a2);
}

bool __cdecl G_MaySpawnEntity(struct gentity_s *)
{
  UNIMPLEMENTED();
}

struct XModel *__cdecl G_GetModel(int)
{
  UNIMPLEMENTED();
}

int __cdecl G_EntLinkToInternal(struct gentity_s *, struct gentity_s *,
                                unsigned int)
{
  UNIMPLEMENTED();
}
