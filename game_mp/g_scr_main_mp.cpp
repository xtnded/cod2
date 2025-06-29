float __cdecl asin(float) { UNIMPLEMENTED(); }

void *__cdecl Scr_LoadRead(int) { UNIMPLEMENTED(); }

void(__cdecl *__cdecl Scr_GetFunction(char const **, int *))(void) {
  UNIMPLEMENTED();
}

int __cdecl ObjectiveStateIndexFromString(enum objectiveState_t *,
                                          unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_SetHealth(struct gentity_s *ent, int offset) {
  VariableUnion v1;      // edx
  VariableUnion *result; // eax

  v1.intValue = Scr_GetInt(0).intValue;
  result = (VariableUnion *)a1->client;
  if (result) {
    a1->health = v1.intValue;
    result = (VariableUnion *)a1->client;
    result[75].intValue = v1.intValue;
  } else {
    a1->maxHealth = v1.intValue;
    a1->health = v1.intValue;
  }
  return result;
}

void __cdecl Scr_SetAngles(struct gentity_s *ent, int offset) {
  float v2[5]; // [esp+14h] [ebp-14h] BYREF

  Scr_GetVector(0, v2);
  return G_SetAngle(a1, v2);
}

void(__cdecl *__cdecl Scr_GetMethod(char const **,
                                    int *))(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl G_InitObjectives() { UNIMPLEMENTED(); }

char const *__cdecl Scr_GetGameTypeNameForScript(
    char const *pszGameTypeScript) {
  int v2;   // esi
  char *v3; // edi
  char *i;  // ebx

  if (dword_17DDAA8 <= 0)
    return 0;
  v2 = 0;
  v3 = (char *)&unk_17DDAEC;
  for (i = (char *)&unk_17DDAAC; I_stricmp(i, a1); i += 132) {
    ++v2;
    v3 += 132;
    if (dword_17DDAA8 <= v2)
      return 0;
  }
  return v3;
}

int __cdecl Scr_IsValidGameType(char const *pszGameType) {
  char *v1; // eax
  int v3;   // esi
  char *v4; // edi
  char *v5; // ebx

  if (dword_17DDAA8 > 0) {
    v3 = 0;
    v4 = (char *)&unk_17DDAEC;
    v5 = (char *)&unk_17DDAAC;
    while (I_stricmp(v5, a1)) {
      ++v3;
      v5 += 132;
      v4 += 132;
      if (dword_17DDAA8 <= v3)
        goto LABEL_2;
    }
    v1 = v4;
  } else {
  LABEL_2:
    v1 = 0;
  }
  return v1 != 0;
}

void __cdecl GScr_DisableAimAssist(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl GScr_EnableAimAssist(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl GScr_DisableGrenadeBounce(struct scr_entref_t entref) {
  int result; // eax

  if (a1.classnum) {
    result = Scr_ObjectError("not an entity");
    MEMORY[0x174] |= 0x8000u;
  } else {
    result = 5 * a1.entnum;
    *(&g_entities.flags + 140 * a1.entnum) |= 0x8000u;
  }
  return result;
}

void __cdecl GScr_EnableGrenadeBounce(struct scr_entref_t entref) {
  int result; // eax

  if (a1.classnum) {
    result = Scr_ObjectError("not an entity");
    MEMORY[0x174] &= ~0x8000u;
  } else {
    result = 5 * a1.entnum;
    *(&g_entities.flags + 140 * a1.entnum) &= ~0x8000u;
  }
  return result;
}

void __cdecl GScr_DisableGrenadeTouchDamage(struct scr_entref_t entref) {
  gentity_s *v1;   // ebx
  __int16 *result; // eax

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  result = &scr_const;
  if (*(_WORD *)v1->classname != word_195B0DA)
    result = (__int16 *)Scr_Error("Currently on supported on damage triggers");
  v1->flags &= ~0x4000u;
  return result;
}

void __cdecl GScr_EnableGrenadeTouchDamage(struct scr_entref_t entref) {
  gentity_s *v1;   // ebx
  __int16 *result; // eax

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  result = &scr_const;
  if (*(_WORD *)v1->classname != word_195B0DA)
    result = (__int16 *)Scr_Error("Currently on supported on damage triggers");
  v1->flags |= 0x4000u;
  return result;
}

void __cdecl ScrCmd_ShowToPlayer(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScrCmd_Hide(struct scr_entref_t entref) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_Show(struct scr_entref_t entref) { UNIMPLEMENTED(); }

unsigned int __cdecl GScr_AllocString(char const *s) {
  return Scr_AllocString(__src);
}

void __cdecl GScr_FreeScripts() { UNIMPLEMENTED(); }

void __cdecl Scr_LocalizationError(int, char const *) { UNIMPLEMENTED(); }

int __cdecl GScr_GetHeadIconIndex(char const *pszIcon) { UNIMPLEMENTED(); }

int __cdecl GScr_GetStatusIconIndex(char const *pszIcon) { UNIMPLEMENTED(); }

int __cdecl GScr_GetScriptMenuIndex(char const *pszMenu) {
  int i;          // ebx
  const char *v3; // eax
  char v4[1048];  // [esp+10h] [ebp-418h] BYREF

  for (i = 0; i != 32; ++i) {
    SV_GetConfigstring(i - 34, v4, 0);
    if (!I_stricmp(v4, a1))
      return i;
  }
  v3 = (const char *)va("Menu '%s' was not precached\n", (char)a1);
  Scr_Error(v3);
  LOBYTE(i) = 0;
  return i;
}

int __cdecl G_GetHintStringIndex(int *piIndex, char const *pszString) {
  UNIMPLEMENTED();
}

void __cdecl GScr_AddVector(float const *const) { UNIMPLEMENTED(); }

void __cdecl Scr_SetOrigin(struct gentity_s *ent, int offset) {
  svEntity_s *result; // eax
  float v2[5];        // [esp+14h] [ebp-14h] BYREF

  Scr_GetVector(0, v2);
  result = (svEntity_s *)G_SetOrigin(a1, v2);
  if (a1->r.linked)
    return SV_LinkEntity(a1);
  return result;
}

void __cdecl GScr_GetPartName() { UNIMPLEMENTED(); }

void __cdecl GScr_GetNumParts() { UNIMPLEMENTED(); }

void __cdecl GScr_AddEntity(struct gentity_s *pEnt) {
  if (a1)
    return Scr_AddEntity(a1);
  else
    return Scr_AddUndefined();
}

void __cdecl Scr_ParseGameTypeList() {
  int result;       // eax
  char *v1;         // esi
  unsigned int v2;  // ecx
  unsigned int v3;  // ebx
  char *v4;         // eax
  signed int v5;    // edi
  char *v6;         // eax
  char *v7;         // eax
  char *v8;         // eax
  char *v9;         // [esp+28h] [ebp-1440h]
  int v10;          // [esp+30h] [ebp-1438h]
  int v11;          // [esp+34h] [ebp-1434h]
  int FileList;     // [esp+38h] [ebp-1430h]
  char *__dst;      // [esp+3Ch] [ebp-142Ch]
  char __src[4096]; // [esp+48h] [ebp-1420h] BYREF
  char v15[1024];   // [esp+1048h] [ebp-420h] BYREF
  int v16;          // [esp+1448h] [ebp-20h] BYREF
  char *v17[7];     // [esp+144Ch] [ebp-1Ch] BYREF

  memset(&unk_17DDAAC, 0, 0x1080u);
  FileList = FS_GetFileList("maps/mp/gametypes", "gsc", FS_LIST_PURE_ONLY,
                            __src, 4096);
  if (FileList > 0) {
    v1 = __src;
    v10 = 0;
    v11 = 0;
    v9 = (char *)&unk_17DDAA0;
    while (1) {
      __dst = v9 + 12;
      v2 = strlen(v1) + 1;
      v3 = v2 - 1;
      if (*v1 == 95) {
        v1 += v2;
      } else {
        if (!I_stricmp(&v1[v3 - 4], ".gsc"))
          v1[v3 - 4] = 0;
        if (v11 == 32) {
          Com_Printf(
              "Too many game type scripts found! Only loading the first %i\n",
              31);
          goto LABEL_3;
        }
        I_strncpyz(__dst, v1, 64);
        strlwr(__dst);
        v4 = va("maps/mp/gametypes/%s.txt", v1);
        v5 = FS_FOpenFileByMode(v4, &v16, FS_READ);
        if ((unsigned int)(v5 - 1) <= 0x3FE) {
          FS_Read(v15, v5, v16);
          v17[0] = v15;
          v7 = Com_Parse(v17);
          I_strncpyz(v9 + 76, v7, 64);
          v8 = Com_Parse(v17);
          *((_DWORD *)v9 + 35) = v8 && !I_stricmp(v8, "team");
        } else {
          v6 = va("maps/mp/gametypes/%s.txt", v1);
          if (v5 <= 0)
            Com_Printf("WARNING: Could not load GameType description file %s "
                       "for gametype %s\n",
                       v6, v1);
          else
            Com_Printf(
                "WARNING: GameType description file %s is too big to load.\n",
                v6);
          I_strncpyz(v9 + 76, v9 + 12, 64);
          *((_DWORD *)v9 + 35) = 0;
        }
        ++v11;
        v9 += 132;
        if (v5 > 0)
          FS_FCloseFile(v16);
        v1 += v3 + 1;
      }
      if (FileList == ++v10)
        goto LABEL_3;
    }
  }
  v11 = 0;
LABEL_3:
  result = v11;
  dword_17DDAA8 = v11;
  return result;
}

void __cdecl Scr_ConstructMessageString(int firstParmIndex, int lastParmIndex,
                                        char const *errorContext, char *string,
                                        int stringLimit) {
  UNIMPLEMENTED();
}

void __cdecl Scr_MakeGameMessage(int iClientNum, char const *pszCmd) {
  int NumParam;   // eax
  char *v10;      // eax
  char v11[1032]; // [esp+20h] [ebp-408h] BYREF

  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(a1, a2, a3, a4, a5, a6, a7, 0, NumParam - 1,
                             "Game Message", v11, 1024);
  v10 = va("%s \"%s\"", a9, v11);
  SV_GameSendServerCommand(a8, SV_CMD_CAN_IGNORE, v10);
}

void __cdecl Scr_PlayerVote(struct gentity_s *self, char *option) {
  UNIMPLEMENTED();
}

void __cdecl Scr_VoteCalled(struct gentity_s *self, char *command, char *param1,
                            char *param2) {
  UNIMPLEMENTED();
}

void __cdecl Scr_PlayerKilled(struct gentity_s *self,
                              struct gentity_s *inflictor,
                              struct gentity_s *attacker, int damage,
                              int meansOfDeath, int iWeapon,
                              float const *const vDir,
                              enum hitLocation_t hitLoc, int psTimeOffset,
                              int deathAnimDuration) {
  UNIMPLEMENTED();
}

void __cdecl Scr_PlayerDamage(struct gentity_s *self,
                              struct gentity_s *inflictor,
                              struct gentity_s *attacker, int damage,
                              int dflags, int meansOfDeath, int iWeapon,
                              float const *const vPoint,
                              float const *const vDir,
                              enum hitLocation_t hitLoc, int timeOffset) {
  UNIMPLEMENTED();
}

void __cdecl Scr_PlayerDisconnect(struct gentity_s *self) { UNIMPLEMENTED(); }

void __cdecl Scr_PlayerConnect(struct gentity_s *self) { UNIMPLEMENTED(); }

void __cdecl Scr_StartupGameType() { UNIMPLEMENTED(); }

void __cdecl Scr_LoadGameType() { UNIMPLEMENTED(); }

void __cdecl Scr_LoadLevel() { UNIMPLEMENTED(); }

void __cdecl Scr_SightTracePassed() { UNIMPLEMENTED(); }

void __cdecl GScr_LoadGameTypeScript() { UNIMPLEMENTED(); }

void __cdecl GScr_LoadScripts() { UNIMPLEMENTED(); }

struct BuiltinFunctionDef *functions;
struct scr_data_t g_scr_data;
void(__cdecl *__cdecl BuiltIn_GetMethod(char const **,
                                        int *))(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl GScr_MatchEnd(void) { ; }

void __cdecl ClearObjective_OnEntity(struct objective_t *) { UNIMPLEMENTED(); }

void __cdecl GScr_SetPlayerIgnoreRadiusDamage(void) {
  int result; // eax

  result = Scr_GetInt(0);
  unk_1937A78 = result;
  return result;
}

void __cdecl ClearObjective(struct objective_t *) { UNIMPLEMENTED(); }

void __cdecl assertCmd(void) { UNIMPLEMENTED(); }

void __cdecl GScr_SetArchive(void) { UNIMPLEMENTED(); }

void __cdecl Scr_Objective_Current(void) {
  int result;       // eax
  int *v1;          // edx
  unsigned int i;   // ebx
  VariableUnion v3; // eax
  VariableUnion v4; // edi
  char *v5;         // eax
  int NumParam;     // [esp+1Ch] [ebp-5Ch]
  _DWORD v7[22];    // [esp+20h] [ebp-58h] BYREF

  NumParam = Scr_GetNumParam();
  memset(v7, 0, 0x40u);
  if (NumParam > 0) {
    for (i = 0; i != NumParam; ++i) {
      v3.intValue = Scr_GetInt(i).intValue;
      v4.intValue = v3.intValue;
      if (v3.intValue > 0xFu) {
        v5 = va("index %i is an illegal objective index. Valid indexes are 0 "
                "to %i\n",
                v3.intValue, 15);
        Scr_ParamError(i, v5);
      }
      v7[v4.intValue] = 1;
    }
  }
  result = 1;
  v1 = dword_19344A4;
  do {
    while (v7[result - 1]) {
      *v1 = 4;
    LABEL_4:
      ++result;
      v1 += 7;
      if (result == 17)
        return result;
    }
    if (*v1 != 4)
      goto LABEL_4;
    *v1 = 1;
    ++result;
    v1 += 7;
  } while (result != 17);
  return result;
}

void __cdecl Scr_Objective_OnEntity(void) {
  VariableUnion v0;  // eax
  VariableUnion v1;  // ebx
  int *v2;           // ebx
  int v3;            // eax
  gentity_s *v4;     // edx
  gentity_s *Entity; // eax
  uint32_t result;   // eax
  char *v7;          // eax

  v0.intValue = Scr_GetInt(0).intValue;
  v1.intValue = v0.intValue;
  if (v0.intValue > 0xFu) {
    v7 = va(
        "index %i is an illegal objective index. Valid indexes are 0 to %i\n",
        v0.intValue, 15);
    Scr_ParamError(0, v7);
  }
  v2 = &dword_19344A4[7 * v1.intValue];
  v3 = v2[4];
  if (v3 != 1023) {
    v4 = &g_entities + v3;
    if (v4->r.inuse)
      v4->r.svFlags &= ~0x10u;
    v2[4] = 1023;
  }
  Entity = Scr_GetEntity(1u);
  Entity->r.svFlags |= 0x10u;
  result = Entity->s.number;
  v2[4] = result;
  return result;
}

void __cdecl Scr_Objective_Position(void) {
  VariableUnion v0; // eax
  VariableUnion v1; // ebx
  int *v2;          // ebx
  int v3;           // eax
  gentity_s *v4;    // edx
  int result;       // eax
  char *v6;         // eax

  v0.intValue = Scr_GetInt(0).intValue;
  v1.intValue = v0.intValue;
  if (v0.intValue > 0xFu) {
    v6 = va(
        "index %i is an illegal objective index. Valid indexes are 0 to %i\n",
        v0.intValue, 15);
    Scr_ParamError(0, v6);
  }
  v2 = &dword_19344A4[7 * v1.intValue];
  v3 = v2[4];
  if (v3 != 1023) {
    v4 = &g_entities + v3;
    if (v4->r.inuse)
      v4->r.svFlags &= ~0x10u;
    v2[4] = 1023;
  }
  Scr_GetVector(1u, (float *)v2 + 1);
  *((float *)v2 + 1) = (float)(int)*((float *)v2 + 1);
  *((float *)v2 + 2) = (float)(int)*((float *)v2 + 2);
  result = (int)*((float *)v2 + 3);
  *((float *)v2 + 3) = (float)result;
  return result;
}

void __cdecl Scr_Objective_Delete(void) {
  VariableUnion v0; // eax
  VariableUnion v1; // ebx
  int *v2;          // ecx
  int v3;           // eax
  gentity_s *v4;    // edx
  int result;       // eax
  char *v6;         // eax

  v0.intValue = Scr_GetInt(0).intValue;
  v1.intValue = v0.intValue;
  if (v0.intValue > 0xFu) {
    v6 = va(
        "index %i is an illegal objective index. Valid indexes are 0 to %i\n",
        v0.intValue, 15);
    Scr_ParamError(0, v6);
  }
  v2 = &dword_19344A4[7 * v1.intValue];
  v3 = v2[4];
  if (v3 != 1023) {
    v4 = &g_entities + v3;
    if (v4->r.inuse)
      v4->r.svFlags &= ~0x10u;
    v2[4] = 1023;
  }
  *v2 = 0;
  result = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = 1023;
  v2[5] = 0;
  v2[6] = 0;
  return result;
}

void __cdecl Scr_ValidateLocalizedStringRef(int, char const *, int) {
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl GetEntity(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl GScr_ReleaseClaimedTrigger(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl GScr_ClientReleaseTrigger(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_ClientClaimTrigger(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_SetBottomArc(struct scr_entref_t) {
  gentity_s *v8; // edx
  int v9;        // ebx
  float Float;   // [esp+1Ch] [ebp-Ch]

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
  } else {
    v8 = &g_entities + a8.entnum;
  }
  v9 = *(_DWORD *)v8->pTurretInfo;
  if (!v9)
    Scr_Error("entity is not a turret");
  Float = Scr_GetFloat(0);
  *(float *)(v9 + 20) = Float;
  if (Float < 0.0)
    *(_DWORD *)(v9 + 20) = 0;
}

void __cdecl GScr_SetTopArc(struct scr_entref_t) {
  gentity_s *v8; // edx
  int v9;        // ebx
  float Float;   // [esp+1Ch] [ebp-Ch]

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
  } else {
    v8 = &g_entities + a8.entnum;
  }
  v9 = *(_DWORD *)v8->pTurretInfo;
  if (!v9)
    Scr_Error("entity is not a turret");
  Float = Scr_GetFloat(0);
  *(float *)(v9 + 12) = -Float;
  if ((float)-Float > 0.0)
    *(_DWORD *)(v9 + 12) = 0;
}

void __cdecl GScr_SetLeftArc(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_SetRightArc(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl Scr_SetStableMissile(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_StopLoopSound(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_EnableLinkTo(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_line(void) {
  int NumParam;     // eax
  VariableUnion v1; // edi
  float v3;         // [esp+2Ch] [ebp-4Ch] BYREF
  float v4;         // [esp+30h] [ebp-48h]
  float v5;         // [esp+34h] [ebp-44h]
  float Float;      // [esp+38h] [ebp-40h]
  float v7[3];      // [esp+3Ch] [ebp-3Ch] BYREF
  float v8[3];      // [esp+48h] [ebp-30h] BYREF
  float v9[9];      // [esp+54h] [ebp-24h] BYREF

  v3 = 1.0;
  v4 = 1.0;
  v5 = 1.0;
  Float = 1.0;
  NumParam = Scr_GetNumParam();
  if (NumParam == 3) {
    v1.intValue = 0;
  } else {
    if (NumParam == 4) {
      v1.intValue = 0;
    } else {
      if (NumParam == 2) {
        v1.intValue = 0;
        goto LABEL_7;
      }
      v1.intValue = Scr_GetInt(4u).intValue;
    }
    Float = Scr_GetFloat(3u);
  }
  Scr_GetVector(2u, v7);
  v3 = v7[0];
  v4 = v7[1];
  v5 = v7[2];
LABEL_7:
  Scr_GetVector(1u, v8);
  Scr_GetVector(0, v9);
  return CL_AddDebugLine(v9, v8, &v3, v1.intValue, 0, 1);
}

struct gentity_s *__cdecl GetPlayerEntity(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl GScr_ViewKick(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_StopShellShock(struct scr_entref_t) {
  gentity_s *PlayerEntity; // ebx
  int32_t result;          // eax

  PlayerEntity = GetPlayerEntity(*(_DWORD *)&a1);
  if (Scr_GetNumParam())
    Scr_Error("USAGE: <player> stopshellshock()\n");
  *(_DWORD *)(PlayerEntity->client + 1496) = 0;
  *(_DWORD *)(PlayerEntity->client + 1500) = 0;
  result = PlayerEntity->client;
  *(_DWORD *)(result + 1504) = 0;
  return result;
}

void __cdecl GScr_SendXboxLiveRanks(void) { ; }

void __cdecl GScr_UpdateScores(struct scr_entref_t) {
  gentity_s *v1;  // ebx
  const char *v2; // eax
  int v3;         // ebx
  const char *v4; // eax

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  v2 = (const char *)va("%c %i", 72);
  v3 = -1963413621 * (((char *)v1 - (char *)&g_entities) >> 4);
  SV_GameSendServerCommand(v3, SV_CMD_CAN_IGNORE, v2);
  v4 = (const char *)va("%c %i", 71);
  return SV_GameSendServerCommand(v3, SV_CMD_CAN_IGNORE, v4);
}

void __cdecl Scr_SoundFade(void) {
  int v0;      // eax
  char *v1;    // eax
  float v2;    // [esp+2Ch] [ebp-1Ch]
  float Float; // [esp+3Ch] [ebp-Ch]

  Float = Scr_GetFloat(0);
  if ((unsigned int)Scr_GetNumParam() <= 1) {
    v0 = 0;
  } else {
    v2 = Scr_GetFloat(1u);
    v0 = (int)(float)(v2 * 1000.0);
  }
  v1 = va("%c %f %i\n", 113, Float, v0);
  SV_GameSendServerCommand(-1, SV_CMD_RELIABLE, v1);
}

void __cdecl Scr_MusicStop(void) {
  int NumParam; // eax
  char *v1;     // eax
  int v2;       // ebx
  char *v3;     // eax
  char *v4;     // eax
  float Float;  // [esp+1Ch] [ebp-1Ch]
  float v6;     // [esp+2Ch] [ebp-Ch]

  NumParam = Scr_GetNumParam();
  if (NumParam) {
    if (NumParam != 1) {
      v1 = va("USAGE: musicStop([fadetime]);\n");
      Scr_Error(v1);
      return;
    }
    Float = Scr_GetFloat(0);
    v6 = floorf((float)(Float * 1000.0) + 0.5);
    v2 = (int)v6;
    if ((int)v6 < 0) {
      v4 = va("musicStop: fade time must be >= 0\n");
      Scr_Error(v4);
    }
  } else {
    v2 = 0;
  }
  v3 = va("%c %i", 112, v2);
  SV_GameSendServerCommand(-1, SV_CMD_RELIABLE, v3);
}

void __cdecl ScrCmd_Unlink(struct scr_entref_t) {
  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    G_EntUnlink(a2, 0);
  } else {
    G_EntUnlink(a2, &g_entities + a8.entnum);
  }
}

void __cdecl GScr_SetTeamForTrigger(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_SetClientNameMode(void) { UNIMPLEMENTED(); }

void __cdecl GScr_SetTeamScore(void) { UNIMPLEMENTED(); }

void __cdecl GScr_Objective_Team(void) {
  unsigned int Int; // eax
  unsigned int v1;  // ebx
  int *v2;          // ebx
  int result;       // eax
  char v4;          // al
  const char *v5;   // eax
  const char *v6;   // eax

  Int = Scr_GetInt(0);
  v1 = Int;
  if (Int > 0xF) {
    v6 = (const char *)va(
        "index %i is an illegal objective index. Valid indexes are 0 to %i\n",
        Int);
    Scr_ParamError(0, v6);
  }
  v2 = &dword_19344A4[7 * v1];
  result = Scr_GetConstString(1u);
  if ((_WORD)result == word_195B082) {
    v2[5] = 2;
  } else if ((_WORD)result == word_195B084) {
    v2[5] = 1;
  } else if ((_WORD)result == word_195B0F4) {
    v2[5] = 0;
  } else {
    v4 = SL_ConvertToString((unsigned __int16)result);
    v5 = (const char *)va(
        "Illegal team string '%s'. Must be allies, axis, or none.", v4);
    return Scr_ParamError(1u, v5);
  }
  return result;
}

void __cdecl GScr_ClientPrint(void) {
  gentity_s *Entity;  // ebx
  const char *String; // eax
  char *v3;           // eax

  if (Scr_GetNumParam()) {
    Entity = Scr_GetEntity(0);
    String = (const char *)Scr_GetString(a1, 1u);
    v3 = va("%c \"%s\"", 101, String);
    SV_GameSendServerCommand(-1963413621 *
                                 (((char *)Entity - (char *)&g_entities) >> 4),
                             SV_CMD_CAN_IGNORE, v3);
  }
}

void __cdecl GScr_AllClientsPrint(void) {
  const char *String; // eax
  char *v2;           // eax

  if (Scr_GetNumParam()) {
    String = (const char *)Scr_GetString(a1, 0);
    v2 = va("%c \"%s\"", 101, String);
    SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, v2);
  }
}

void __cdecl Scr_MusicPlay(void) {
  const char *String; // eax
  char *v2;           // eax

  String = (const char *)Scr_GetString(a1, 0);
  v2 = va("%c %s", 111, String);
  SV_GameSendServerCommand(-1, SV_CMD_RELIABLE, v2);
}

void __cdecl GScr_LogPrint(void) {
  int v0;              // esi
  unsigned int i;      // ebx
  const char *String;  // edx
  int NumParam;        // [esp+1Ch] [ebp-41Ch]
  char __format[1048]; // [esp+20h] [ebp-418h] BYREF

  __format[0] = 0;
  NumParam = Scr_GetNumParam();
  if (NumParam > 0) {
    v0 = 0;
    for (i = 0; i != NumParam; ++i) {
      String = (const char *)Scr_GetString(i);
      v0 += strlen(String);
      if (v0 > 1023)
        break;
      I_strncat(__format, 1024, String);
    }
  }
  return G_LogPrintf(__format);
}

void __cdecl Scr_Objective_State(void) { UNIMPLEMENTED(); }

void __cdecl assertmsgCmd(void) {
  char String;    // al
  const char *v1; // eax

  String = Scr_GetString(0);
  v1 = (const char *)va("assert fail: %s", String);
  return Scr_Error(v1);
}

void __cdecl assertexCmd(void) { UNIMPLEMENTED(); }

void __cdecl GScr_print3d(void) { UNIMPLEMENTED(); }

void __cdecl GScr_BanPlayer(void) {
  VariableUnion v0; // eax
  char *v1;         // eax
  char v2;          // [esp+8h] [ebp-10h]

  if (Scr_GetNumParam()) {
    v0.intValue = Scr_GetInt(0).intValue;
    v1 = va("banClient %i\n", v0.intValue);
    Cbuf_ExecuteText(2, v1, v2);
  }
}

void __cdecl GScr_KickPlayer(void) {
  VariableUnion v0; // eax
  char *v1;         // eax
  char v2;          // [esp+8h] [ebp-10h]

  if (Scr_GetNumParam()) {
    v0.intValue = Scr_GetInt(0).intValue;
    v1 = va("tempBanClient %i\n", v0.intValue);
    Cbuf_ExecuteText(2, v1, v2);
  }
}

void __cdecl GScr_LoadMap(void) {
  char *String; // esi
  char *v2;     // eax
  char *v3;     // eax
  char v4;      // [esp+8h] [ebp-10h]

  if (Scr_GetNumParam()) {
    String = (char *)Scr_GetString(a1, 0);
    if (SV_MapExists(String)) {
      if (unk_1937A70) {
        v3 = "map already called";
        if (unk_1937A70 != 2)
          v3 = "exitlevel already called";
        Scr_Error(v3);
        unk_1937A70 = 2;
        dword_19361D4 = 0;
        if ((unsigned int)Scr_GetNumParam() <= 1)
          goto LABEL_7;
      } else {
        unk_1937A70 = 2;
        dword_19361D4 = 0;
        if ((unsigned int)Scr_GetNumParam() <= 1) {
        LABEL_7:
          v2 = va("map %s\n", String);
          Cbuf_ExecuteText(2, v2, v4);
          return;
        }
      }
      dword_19361D4 = Scr_GetInt(1u).intValue;
      goto LABEL_7;
    }
  }
}

void __cdecl GScr_MapRestart(void) {
  char *v0; // eax
  char v1;  // [esp+8h] [ebp-10h]

  if (unk_1937A70) {
    v0 = "map_restart already called";
    if (unk_1937A70 != 1)
      v0 = "exitlevel already called";
    Scr_Error(v0);
  }
  unk_1937A70 = 1;
  dword_19361D4 = 0;
  if (Scr_GetNumParam())
    dword_19361D4 = Scr_GetInt(0).intValue;
  Cbuf_ExecuteText(2, "fast_restart\n", v1);
}

void __cdecl GScr_ExitLevel(void) {
  char *v0; // eax

  if (unk_1937A70) {
    v0 = "map_restart already called";
    if (unk_1937A70 != 1)
      v0 = "exitlevel already called";
    Scr_Error(v0);
  }
  unk_1937A70 = 3;
  dword_19361D4 = 0;
  if (Scr_GetNumParam())
    dword_19361D4 = Scr_GetInt(0).intValue;
  SV_MatchEnd();
  return ExitLevel();
}

void __cdecl GScr_SetVoteNoCount(void) { UNIMPLEMENTED(); }

void __cdecl GScr_SetVoteYesCount(void) {
  int result;     // eax
  char Int;       // al
  const char *v2; // eax
  const char *v3; // eax

  result = Scr_GetNumParam();
  if (result) {
    Int = Scr_GetInt(0);
    v2 = (const char *)va("%i", Int);
    SV_SetConfigstring(17, v2);
    v3 = (const char *)va("%i", dword_1934FA8);
    return SV_SetConfigstring(18, v3);
  }
  return result;
}

void __cdecl GScr_SetVoteTime(void) {
  int result;     // eax
  char Int;       // al
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax

  result = Scr_GetNumParam();
  if (result) {
    Int = Scr_GetInt(0);
    v2 = (const char *)va("%i", Int);
    SV_SetConfigstring(15, v2);
    v3 = (const char *)va("%i", dword_1934FA4);
    SV_SetConfigstring(17, v3);
    v4 = (const char *)va("%i", dword_1934FA8);
    return SV_SetConfigstring(18, v4);
  }
  return result;
}

void __cdecl GScr_SetVoteString(void) { UNIMPLEMENTED(); }

void __cdecl GScr_ShellShock(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_SetWinningTeam(void) { UNIMPLEMENTED(); }

void __cdecl GScr_SetWinningPlayer(void) {
  uint32_t v0;     // ebx
  const char *v1;  // ebx
  int v2;          // eax
  int result;      // eax
  char __s1[1032]; // [esp+10h] [ebp-408h] BYREF

  v0 = Scr_GetEntity(0)->s.number + 1;
  SV_GetConfigstring(22, __s1, 0);
  v1 = (const char *)va("%i", v0);
  v2 = Info_ValueForKey(__s1, "winner");
  result = I_stricmp(v2, v1);
  if (result) {
    Info_SetValueForKey(__s1, "winner", v1);
    return SV_SetConfigstring(22, __s1);
  }
  return result;
}

void __cdecl Scr_PlayFX_Error(char *, int) { UNIMPLEMENTED(); }

void __cdecl Scr_AmbientStop(void) { UNIMPLEMENTED(); }

void __cdecl Scr_AmbientPlay(void) { UNIMPLEMENTED(); }

void __cdecl GScr_PrecacheHeadIcon(void) {
  unsigned int i;  // ebx
  int v8;          // esi
  unsigned int v9; // ebx
  char *v10;       // eax
  char *__s1;      // [esp+1Ch] [ebp-41Ch]
  char v12[1048];  // [esp+20h] [ebp-418h] BYREF

  __s1 = (char *)Scr_GetString(a2, 0);
  for (i = 31; i != 46; ++i) {
    SV_GetConfigstring(a1, a2, a3, a4, a5, a6, a7, i, v12, 1024);
    if (!I_stricmp(v12, __s1)) {
      Com_DPrintf(
          "Script tried to precache the player head icon '%s' more than once\n",
          __s1);
      return;
    }
  }
  v8 = 0;
  while (1) {
    v9 = v8 + 31;
    SV_GetConfigstring(a1, a2, a3, a4, a5, a6, a7, v8 + 31, v12, 1024);
    if (!v12[0])
      break;
    if (++v8 == 15) {
      v10 = va("Too many player head icons precached. Max allowed is %i", 15);
      Scr_Error(v10);
      v9 = 46;
      break;
    }
  }
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, v9, __s1);
}

void __cdecl GScr_PrecacheStatusIcon(void) {
  unsigned int i;  // ebx
  int v8;          // esi
  unsigned int v9; // ebx
  char *v10;       // eax
  char *__s1;      // [esp+1Ch] [ebp-41Ch]
  char v12[1048];  // [esp+20h] [ebp-418h] BYREF

  __s1 = (char *)Scr_GetString(a2, 0);
  for (i = 23; i != 31; ++i) {
    SV_GetConfigstring(a1, a2, a3, a4, a5, a6, a7, i, v12, 1024);
    if (!I_stricmp(v12, __s1)) {
      Com_DPrintf("Script tried to precache the player status icon '%s' more "
                  "than once\n",
                  __s1);
      return;
    }
  }
  v8 = 0;
  while (1) {
    v9 = v8 + 23;
    SV_GetConfigstring(a1, a2, a3, a4, a5, a6, a7, v8 + 23, v12, 1024);
    if (!v12[0])
      break;
    if (++v8 == 8) {
      v10 = va("Too many player status icons precached. Max allowed is %i", 8);
      Scr_Error(v10);
      v9 = 31;
      break;
    }
  }
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, v9, __s1);
}

void __cdecl GScr_PrecacheMenu(void) {
  unsigned int i; // ebx
  int j;          // esi
  char *v9;       // eax
  char *__s1;     // [esp+1Ch] [ebp-41Ch]
  char v11[1048]; // [esp+20h] [ebp-418h] BYREF

  __s1 = (char *)Scr_GetString(a2, 0);
  for (i = 1246; i != 1278; ++i) {
    SV_GetConfigstring(a1, a2, a3, a4, a5, a6, a7, i, v11, 1024);
    if (!I_stricmp(v11, __s1)) {
      Com_DPrintf("Script tried to precache the menu '%s' more than once\n",
                  __s1);
      return;
    }
  }
  for (j = 0; j != 32; ++j) {
    SV_GetConfigstring(a1, a2, a3, a4, a5, a6, a7, j + 1246, v11, 1024);
    if (!v11[0]) {
      SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, j + 1246, __s1);
      return;
    }
  }
  v9 = va("Too many menus precached. Max allowed menus is %i", 32);
  Scr_Error(v9);
  SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x4FEu, __s1);
}

void __cdecl Scr_IsSplitscreen(void) { UNIMPLEMENTED(); }

void __cdecl GScr_IsValidGameType(void) { UNIMPLEMENTED(); }

void __cdecl GScr_MapExists(void) {
  int result;         // eax
  const char *String; // eax

  result = Scr_GetNumParam();
  if (result) {
    String = (const char *)Scr_GetString(0);
    if (SV_MapExists(String))
      return Scr_AddInt(1);
    else
      return Scr_AddInt(0);
  }
  return result;
}

void __cdecl GScr_LocalToWorldCoords(struct scr_entref_t) {
  gentity_s *v1; // edi
  _BYTE v3[36];  // [esp+14h] [ebp-54h] BYREF
  float v4;      // [esp+38h] [ebp-30h] BYREF
  float v5;      // [esp+3Ch] [ebp-2Ch]
  float v6;      // [esp+40h] [ebp-28h]
  float v7[9];   // [esp+44h] [ebp-24h] BYREF

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  Scr_GetVector(0, v7);
  AnglesToAxis(v1->r.currentAngles, v3);
  MatrixTransformVector(v7, v3, &v4);
  v4 = v4 + v1->r.currentOrigin[0];
  v5 = v5 + v1->r.currentOrigin[1];
  v6 = v6 + v1->r.currentOrigin[2];
  return Scr_AddVector(&v4);
}

void __cdecl GScr_GetTeamPlayersAlive(void) { UNIMPLEMENTED(); }

void __cdecl GScr_UpdateClientNames(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetTeamScore(void) {
  unsigned __int16 ConstString; // ax
  unsigned __int16 v1;          // bx
  char v2;                      // al
  const char *v3;               // eax

  ConstString = Scr_GetConstString(0);
  v1 = ConstString;
  if (ConstString == word_195B082)
    return Scr_AddInt(dword_1934684);
  if (ConstString != word_195B084 &&
      (v2 = SL_ConvertToString(ConstString),
       v3 = (const char *)va(
           "Illegal team string '%s'. Must be allies, or axis.", v2),
       Scr_Error(v3), v1 == word_195B082)) {
    return Scr_AddInt(dword_1934684);
  } else {
    return Scr_AddInt(dword_1934680);
  }
}

void __cdecl GScr_IsPlayerNumber(void) { UNIMPLEMENTED(); }

void __cdecl GScr_IsPlayer(void) {
  if (Scr_GetType(0) == 1 && Scr_GetPointerType(0) == 21 &&
      Scr_GetEntity(0)->client)
    return Scr_AddInt(1);
  else
    return Scr_AddInt(0);
}

void __cdecl Scr_SetFog(char const *, float, float, float, float, float, float,
                        float) {
  UNIMPLEMENTED();
}

void __cdecl Scr_LoadFX(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetNorthYaw(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetAngleDelta(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetMoveDelta(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PrecacheRumble(void) { ; }

void __cdecl Scr_PrecacheString(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PrecacheShader(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PrecacheShellShock(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PrecacheModel(void) { UNIMPLEMENTED(); }

void __cdecl Scr_StrTok(void) { UNIMPLEMENTED(); }

void __cdecl Scr_ToLower(void) { UNIMPLEMENTED(); }

void __cdecl Scr_GetSubStr(void) { UNIMPLEMENTED(); }

void __cdecl Scr_IsSubStr(void) { UNIMPLEMENTED(); }

void __cdecl Scr_AnglesToForward(void) { UNIMPLEMENTED(); }

void __cdecl Scr_AnglesToRight(void) { UNIMPLEMENTED(); }

void __cdecl Scr_AnglesToUp(void) { UNIMPLEMENTED(); }

void __cdecl Scr_VectorToAngles(void) { UNIMPLEMENTED(); }

void __cdecl Scr_VectorNormalize(void) { UNIMPLEMENTED(); }

void __cdecl Scr_VectorDot(void) {
  float v1[3]; // [esp+18h] [ebp-20h] BYREF
  float v2[5]; // [esp+24h] [ebp-14h] BYREF

  Scr_GetVector(0, v2);
  Scr_GetVector(1u, v1);
  return Scr_AddFloat((float)((float)(v2[0] * v1[0]) + (float)(v2[1] * v1[1])) +
                      (float)(v2[2] * v1[2]));
}

void __cdecl Scr_Closer(void) { UNIMPLEMENTED(); }

void __cdecl Scr_LengthSquared(void) { UNIMPLEMENTED(); }

void __cdecl Scr_Length(void) {
  float v1; // [esp+14h] [ebp-14h] BYREF
  float v2; // [esp+18h] [ebp-10h]
  float v3; // [esp+1Ch] [ebp-Ch]

  Scr_GetVector(0, &v1);
  return Scr_AddFloat(
      fsqrt((float)((float)(v1 * v1) + (float)(v2 * v2)) + (float)(v3 * v3)));
}

void __cdecl Scr_DistanceSquared(void) { UNIMPLEMENTED(); }

void __cdecl Scr_Distance(void) { UNIMPLEMENTED(); }

void __cdecl GScr_CastInt(void) { UNIMPLEMENTED(); }

void __cdecl GScr_atan(void) { UNIMPLEMENTED(); }

void __cdecl GScr_acos(void) { UNIMPLEMENTED(); }

void __cdecl GScr_asin(void) { UNIMPLEMENTED(); }

void __cdecl GScr_tan(void) { UNIMPLEMENTED(); }

void __cdecl GScr_cos(void) { UNIMPLEMENTED(); }

void __cdecl GScr_sin(void) { UNIMPLEMENTED(); }

void __cdecl Scr_RandomFloat(void) { UNIMPLEMENTED(); }

void __cdecl GScr_getStartTime(void) { return Scr_AddInt(dword_1934678); }

void __cdecl GScr_positionWouldTelefrag(void) { UNIMPLEMENTED(); }

void __cdecl GScr_WorldEntNumber(void) { return Scr_AddInt(1022); }

void __cdecl SetObjectiveIcon(struct objective_t *, int) { UNIMPLEMENTED(); }

void __cdecl GScr_GetEntityNumber(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_SetContents(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetNormalHealth(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_StopRumble(struct scr_entref_t) { ; }

void __cdecl ScrCmd_PlayRumbleInternal(struct scr_entref_t, int) {
  UNIMPLEMENTED();
}

void __cdecl ScrCmd_PlayLoopSound(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_SoundExists(void) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_IsTouching(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetEye(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetOrigin(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetAttachIgnoreCollision(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl ScrCmd_GetAttachTagName(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetAttachModelName(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetAttachSize(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_GetBrushModelCenter(void) { UNIMPLEMENTED(); }

void __cdecl GScr_AnimHasNotetrack(void) {
  unsigned int Anim;            // eax
  unsigned int v1;              // ebx
  unsigned __int16 v2;          // di
  unsigned __int16 ConstString; // si
  const XAnim_s *Anims;         // eax
  unsigned __int8 v5;           // al

  Anim = Scr_GetAnim(0, 0);
  v1 = HIWORD(Anim);
  v2 = Anim;
  ConstString = Scr_GetConstString(1u);
  Anims = (const XAnim_s *)Scr_GetAnims((unsigned __int16)v1);
  v5 = XAnimNotetrackExists(Anims, v2, ConstString);
  return Scr_AddBool(v5);
}

void __cdecl GScr_GetAnimLength(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetTime(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetDvarFloat(void) { UNIMPLEMENTED(); }

void __cdecl GScr_GetDvarInt(void) {
  const char *String;        // eax
  const char *VariantString; // eax
  int v2;                    // eax

  String = (const char *)Scr_GetString(0);
  VariantString = (const char *)Dvar_GetVariantString(String);
  v2 = atoi(VariantString);
  return Scr_AddInt(v2);
}

void __cdecl GScr_GetDvar(void) {
  const char *String;        // eax
  const char *VariantString; // eax

  String = (const char *)Scr_GetString(0);
  VariantString = (const char *)Dvar_GetVariantString(String);
  return Scr_AddString(VariantString);
}

void __cdecl GScr_IsAlive(void) {
  if (Scr_GetType(0) == 1 && Scr_GetPointerType(0) == 21 &&
      Scr_GetEntity(0)->health > 0)
    return Scr_AddInt(1);
  else
    return Scr_AddInt(0);
}

void __cdecl GScr_IsString(void) {
  int Type; // eax

  Type = Scr_GetType(0);
  return Scr_AddInt(Type == 2);
}

void __cdecl GScr_IsDefined(void) {
  int Type;        // eax
  int PointerType; // eax

  Type = Scr_GetType(0);
  if (Type != 1)
    return Scr_AddInt(Type != 0);
  PointerType = Scr_GetPointerType(0);
  if (PointerType > 22 || PointerType == 20)
    return Scr_AddInt(0);
  else
    return Scr_AddInt(1);
}

void __cdecl ScrCmd_GetClanURL(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetClanDescription(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetClanMotto(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetClanName(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_GetClanId(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl Scr_SetExponentialFog(void) { UNIMPLEMENTED(); }

void __cdecl Scr_SetLinearFog(void) { UNIMPLEMENTED(); }

void __cdecl Scr_Objective_Icon(void) { UNIMPLEMENTED(); }

void __cdecl Scr_Objective_Add(void) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_PlayLoopRumble(struct scr_entref_t) { ; }

void __cdecl ScrCmd_PlayRumble(struct scr_entref_t) { ; }

void __cdecl Scr_GetEntByNum(void) { UNIMPLEMENTED(); }

void __cdecl GScr_PrecacheTurret(void) {
  const char *String; // eax

  if (!dword_193449C)
    Scr_Error("precacheTurret must be called before any wait statements in the "
              "level script\n");
  String = (const char *)Scr_GetString(0);
  return G_GetWeaponIndexForName(String);
}

void __cdecl GScr_GetAmmoCount(struct scr_entref_t) {
  int PlayerEntity;       // ebx
  const char *String;     // eax
  int WeaponIndexForName; // eax
  int v4;                 // eax
  scr_entref_t v5;        // [esp+0h] [ebp-18h]

  PlayerEntity = GetPlayerEntity(v5);
  String = (const char *)Scr_GetString(0);
  WeaponIndexForName = G_GetWeaponIndexForName(String);
  if (!WeaponIndexForName)
    return Scr_AddInt(0);
  v4 = BG_WeaponAmmo(*(const playerState_s **)(PlayerEntity + 344),
                     WeaponIndexForName);
  return Scr_AddInt(v4);
}

void __cdecl Scr_PrecacheItem(void) { UNIMPLEMENTED(); }

void __cdecl GScr_FGetArg(void) { UNIMPLEMENTED(); }

void __cdecl GScr_FReadLn(void) { UNIMPLEMENTED(); }

void __cdecl GScr_FPrintln(void) { UNIMPLEMENTED(); }

void __cdecl GScr_CloseFile(void) { UNIMPLEMENTED(); }

void __cdecl Scr_RandomFloatRange(void) { UNIMPLEMENTED(); }

void __cdecl Scr_RandomIntRange(void) { UNIMPLEMENTED(); }

void __cdecl Scr_RandomInt(void) { UNIMPLEMENTED(); }

void __cdecl GScr_SetCursorHint(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_SetNormalHealth(struct scr_entref_t) {
  gentity_s *v8;  // ebx
  float v9;       // xmm0_4
  int32_t client; // eax
  int v11;        // esi
  char *v12;      // eax
  int maxHealth;  // eax
  float Float;    // [esp+1Ch] [ebp-1Ch]
  float v15;      // [esp+2Ch] [ebp-Ch]

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
  } else {
    v8 = &g_entities + a8.entnum;
  }
  Float = Scr_GetFloat(0);
  v9 = fminf(1.0, Float);
  client = v8->client;
  if (client) {
    v15 = floorf((float)(v9 * (float)*(int *)(client + 10024)) + 0.5);
    v11 = (int)v15;
    v12 = va("%c \"%i\"", 73, 0);
    SV_GameSendServerCommand(-1963413621 *
                                 (((char *)v8 - (char *)&g_entities) >> 4),
                             SV_CMD_CAN_IGNORE, v12);
  } else {
    maxHealth = v8->maxHealth;
    if (!maxHealth) {
      v11 = (int)v9;
      if ((int)v9 > 0)
        goto LABEL_6;
      goto LABEL_9;
    }
    v11 = (int)(float)((float)maxHealth * v9);
  }
  if (v11 > 0) {
  LABEL_6:
    v8->health = v11;
    return;
  }
LABEL_9:
  Com_Printf("ERROR: Cannot setnormalhealth to 0 or below.\n");
}

void __cdecl Scr_GetWeaponModel(void) { UNIMPLEMENTED(); }

void __cdecl print(void) {
  int NumParam;            // esi
  unsigned int v8;         // ebx
  const char *DebugString; // eax

  if (!*(_BYTE *)(g_NoScriptSpam + 8)) {
    NumParam = Scr_GetNumParam();
    if (NumParam > 0) {
      v8 = 0;
      do {
        DebugString =
            (const char *)Scr_GetDebugString(a1, a2, a3, a4, a5, a6, a7, v8);
        Com_Printf("%s", DebugString);
        ++v8;
      } while (NumParam != v8);
    }
  }
}

void __cdecl GScr_SetPlayerTeamRank(void) { ; }

void __cdecl GScr_OpenFile(void) { UNIMPLEMENTED(); }

void __cdecl GScr_MakeDvarServerInfo(void) {
  const char *String; // edi
  const dvar_s *Var;  // eax
  char *v3;           // edx
  char v4;            // al
  char *v5;           // ecx
  char *v6;           // ebx
  char *v7;           // esi
  char v8;            // al
  char v9;            // dl
  int NumParam;       // eax
  char *v11;          // [esp+2Ch] [ebp-81Ch]
  char v12;           // [esp+30h] [ebp-818h] BYREF
  char v13;           // [esp+31h] [ebp-817h] BYREF
  char v14;           // [esp+42Fh] [ebp-419h] BYREF
  char v15[1048];     // [esp+430h] [ebp-418h] BYREF

  String = (const char *)Scr_GetString(0);
  Var = (const dvar_s *)Dvar_FindVar(String);
  if (Var)
    return Dvar_AddFlags(Var, 256);
  if (Scr_GetType(1u) == 3) {
    NumParam = Scr_GetNumParam();
    Scr_ConstructMessageString(1u, NumParam - 1, "Dvar Value", v15, 1024);
    v11 = v15;
    v3 = v15;
  } else {
    v11 = (char *)Scr_GetString(1u);
    v3 = v11;
  }
  v4 = *v3;
  if (*v3) {
    v6 = v3;
    v7 = &v13;
    do {
      v8 = I_CleanChar(v4);
      v5 = v7;
      v9 = 39;
      if (v8 != 34)
        v9 = v8;
      *(v7 - 1) = v9;
      if (v7 == &v14)
        break;
      v4 = v6[1];
      ++v7;
      ++v6;
    } while (v4);
  } else {
    v5 = &v12;
  }
  *v5 = 0;
  return Dvar_RegisterString(String, (DvarValue)v11, 0x4100u);
}

void __cdecl GScr_ClientAnnouncement(void) {
  gentity_s *Entity; // esi
  int NumParam;      // eax
  const char *v2;    // eax
  char v4[1032];     // [esp+20h] [ebp-408h] BYREF

  Entity = Scr_GetEntity(0);
  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(1u, NumParam - 1, "Announcement", v4, 1024);
  v2 = (const char *)va("%c \"%s\" 2", 99);
  return SV_GameSendServerCommand(Entity->s.number, SV_CMD_CAN_IGNORE, v2);
}

void __cdecl GScr_Announcement(void) {
  int NumParam;   // eax
  const char *v1; // eax
  char v3[1032];  // [esp+20h] [ebp-408h] BYREF

  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(0, NumParam - 1, "Announcement", v3, 1024);
  v1 = (const char *)va("%c \"%s\" 2", 99);
  return SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, v1);
}

void __cdecl Scr_PlayLoopedFX(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PlayFXOnTag(void) { UNIMPLEMENTED(); }

void __cdecl GScr_SetHintString(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_SetModel(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_SetDvar(void) {
  char *v0;          // esi
  int i;             // ebx
  char v2;           // al
  char v3;           // dl
  char v4;           // al
  const char *v5;    // eax
  int result;        // eax
  bool v7;           // bl
  const dvar_s *Var; // eax
  int NumParam;      // eax
  dvar_s *String;    // [esp+2Ch] [ebp-81Ch]
  char __b[1024];    // [esp+30h] [ebp-818h] BYREF
  char v12[1048];    // [esp+430h] [ebp-418h] BYREF

  String = (dvar_s *)Scr_GetString(0);
  if (Scr_GetType(1u) == 3) {
    NumParam = Scr_GetNumParam();
    Scr_ConstructMessageString(1u, NumParam - 1, "Dvar Value", v12, 1024);
    v0 = v12;
  } else {
    v0 = (char *)Scr_GetString(1u);
  }
  memset(__b, 0, sizeof(__b));
  for (i = 1; i != 8193; ++i) {
    v4 = v0[i - 1];
    if (!v4)
      break;
    v2 = I_CleanChar(v4);
    v3 = 39;
    if (v2 != 34)
      v3 = v2;
    __b[i - 1] = v3;
  }
  if ((unsigned __int8)Dvar_IsValidName(String->name)) {
    v7 = Scr_GetNumParam() > 2u && Scr_GetInt(2u);
    result = Dvar_SetFromStringByName(String, (DvarValue)v0);
    if (v7) {
      Var = (const dvar_s *)Dvar_FindVar(String->name);
      return Dvar_AddFlags(Var, 1024);
    }
  } else {
    v5 = (const char *)va("Dvar %s has an invalid dvar name", (char)String);
    return Scr_Error(v5);
  }
  return result;
}

void __cdecl println(void) {
  int result;              // eax
  int NumParam;            // esi
  unsigned int v2;         // ebx
  const char *DebugString; // eax

  result = g_NoScriptSpam;
  if (!*(_BYTE *)(g_NoScriptSpam + 8)) {
    NumParam = Scr_GetNumParam();
    if (NumParam > 0) {
      v2 = 0;
      do {
        DebugString = (const char *)Scr_GetDebugString(v2);
        Com_Printf("%s", DebugString);
        ++v2;
      } while (NumParam != v2);
    }
    return Com_Printf("\n");
  }
  return result;
}

void __cdecl Scr_StopAllRumbles(void) { ; }

void __cdecl Scr_PlayRumbleOnPosInternal(int) { UNIMPLEMENTED(); }

void __cdecl GScr_Earthquake(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PlayFX(void) {
  int NumParam;   // esi
  int Int;        // edi
  gentity_s *v2;  // ebx
  int result;     // eax
  const char *v4; // eax
  const char *v5; // eax
  float v6;       // xmm1_4
  const char *v7; // eax
  float v8;       // [esp+18h] [ebp-450h]
  float v9;       // [esp+1Ch] [ebp-44Ch]
  char v10[20];   // [esp+20h] [ebp-448h] BYREF
  void *v11;      // [esp+34h] [ebp-434h]
  float v12;      // [esp+420h] [ebp-48h] BYREF
  float v13;      // [esp+424h] [ebp-44h]
  float v14;      // [esp+428h] [ebp-40h]
  float v15;      // [esp+42Ch] [ebp-3Ch] BYREF
  float v16;      // [esp+430h] [ebp-38h]
  float v17;      // [esp+434h] [ebp-34h]
  float v18;      // [esp+438h] [ebp-30h] BYREF
  float v19;      // [esp+43Ch] [ebp-2Ch]
  float v20;      // [esp+440h] [ebp-28h]
  float v21[9];   // [esp+444h] [ebp-24h] BYREF

  NumParam = Scr_GetNumParam();
  if ((unsigned int)(NumParam - 2) > 2)
    Scr_Error("Incorrect number of parameters");
  Int = Scr_GetInt(0);
  Scr_GetVector(1u, v21);
  v2 = G_TempEntity(v21, 194);
  result = (unsigned __int8)Int;
  v2->s.eventParm = (unsigned __int8)Int;
  if (NumParam == 2) {
    *(_DWORD *)&v2->s.apos[12] = -1028390912;
  } else {
    Scr_GetVector(2u, &v12);
    v8 = fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) +
               (float)(v14 * v14));
    if (v8 == 0.0) {
      if (Int) {
        SV_GetConfigstring(Int + 78, v10, 0);
      } else {
        qmemcpy(v10, "not successfully loa", sizeof(v10));
        v11 = &unk_646564;
      }
      v4 = (const char *)va(
          "%s (effect = %s)\n",
          (char)"playFx called with (0 0 0) forward direction");
      Scr_Error(v4);
    }
    v12 = (float)(1.0 / v8) * v12;
    v13 = (float)(1.0 / v8) * v13;
    v14 = (float)(1.0 / v8) * v14;
    if (NumParam == 3) {
      return vectoangles(&v12, (float *)&v2->s.apos[12]);
    } else {
      Scr_GetVector(3u, &v18);
      v9 = fsqrt((float)((float)(v18 * v18) + (float)(v19 * v19)) +
                 (float)(v20 * v20));
      if (v9 == 0.0) {
        if (Int) {
          SV_GetConfigstring(Int + 78, v10, 0);
        } else {
          qmemcpy(v10, "not successfully loa", sizeof(v10));
          v11 = &unk_646564;
        }
        v5 = (const char *)va("%s (effect = %s)\n",
                              (char)"playFx called with (0 0 0) up direction");
        Scr_Error(v5);
      }
      v18 = (float)(1.0 / v9) * v18;
      v19 = (float)(1.0 / v9) * v19;
      v20 = (float)(1.0 / v9) * v20;
      Vec3Cross(&v18, &v12, &v15);
      v6 = fsqrt((float)((float)(v15 * v15) + (float)(v16 * v16)) +
                 (float)(v17 * v17));
      if (v6 >= 0.001) {
        if (v6 < 0.99900001) {
          v15 = v15 * (float)(1.0 / v6);
          v16 = (float)(1.0 / v6) * v16;
          v17 = (float)(1.0 / v6) * v17;
          Vec3Cross(&v12, &v15, &v18);
        }
      } else {
        if (Int) {
          SV_GetConfigstring(Int + 78, v10, 0);
        } else {
          qmemcpy(v10, "not successfully loa", sizeof(v10));
          v11 = &unk_646564;
        }
        v7 = (const char *)va("%s (effect = %s)\n",
                              (char)"playFx called an up direction 0 or 180 "
                                    "degrees from forward");
        Scr_Error(v7);
      }
      return AxisToAngles(&v12, (float *)&v2->s.apos[12]);
    }
  }
  return result;
}

void __cdecl GScr_Obituary(void) {
  const char *String;         // eax
  const char *v1;             // eax
  int v2;                     // esi
  gentity_s *Entity;          // ebx
  gentity_s *v4;              // edi
  int32_t result;             // eax
  int32_t WeaponIndexForName; // [esp+1Ch] [ebp-1Ch]

  String = (const char *)Scr_GetString(2u);
  WeaponIndexForName = G_GetWeaponIndexForName(String);
  v1 = (const char *)Scr_GetString(3u);
  v2 = G_IndexForMeansOfDeath(v1);
  Entity = Scr_GetEntity(0);
  v4 = G_TempEntity(vec3_origin, 198);
  v4->s.otherEntityNum = Entity->s.number;
  if (Scr_GetType(1u) == 1 && Scr_GetPointerType(1u) == 21)
    v4->s.attackerEntityNum = Scr_GetEntity(1u)->s.number;
  else
    v4->s.attackerEntityNum = 1022;
  v4->r.svFlags = 8;
  result = v2 - 7;
  if ((unsigned int)(v2 - 7) <= 1 || v2 == 12 || v2 == 11 || v2 == 9) {
    v4->s.eventParm = v2 | 0x80;
  } else {
    result = WeaponIndexForName;
    v4->s.eventParm = WeaponIndexForName;
  }
  return result;
}

void __cdecl ScrCmd_PlaySoundAsMaster(struct scr_entref_t) {
  gentity_s *v1;      // ebx
  const char *String; // eax
  unsigned __int8 v3; // si
  gentity_s *result;  // eax

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  String = (const char *)Scr_GetString(0);
  v3 = G_SoundAliasIndex(String);
  result = G_TempEntity(v1->r.currentOrigin, 180);
  result->r.svFlags |= 8u;
  result->s.eventParm = v3;
  return result;
}

void __cdecl ScrCmd_PlaySound(struct scr_entref_t) {
  gentity_s *v1;      // ebx
  const char *String; // eax
  unsigned __int8 v3; // si
  gentity_s *result;  // eax

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  String = (const char *)Scr_GetString(0);
  v3 = G_SoundAliasIndex(String);
  result = G_TempEntity(v1->r.currentOrigin, 179);
  result->r.svFlags |= 8u;
  result->s.eventParm = v3;
  return result;
}

void __cdecl ScrCmd_detachAll(struct scr_entref_t) {
  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    G_EntDetachAll(a1, a2, a3, a4, a5, a6, a7, 0);
  } else {
    G_EntDetachAll(a1, a2, a3, a4, a5, a6, a7, &g_entities + a8.entnum);
  }
}

void __cdecl ScrCmd_detach(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_attach(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_SpawnTurret(void) { UNIMPLEMENTED(); }

void __cdecl GScr_Spawn(void) { UNIMPLEMENTED(); }

void __cdecl iprintlnbold(void) {
  char *v7;       // esi
  int NumParam;   // eax
  char *v9;       // eax
  char v10[1032]; // [esp+20h] [ebp-408h] BYREF

  v7 = va("%c", 103);
  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(a1, a2, a3, a4, a5, a6, a7, 0, NumParam - 1,
                             "Game Message", v10, 1024);
  v9 = va("%s \"%s\"", v7, v10);
  SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, v9);
}

void __cdecl iprintln(void) {
  char *v7;       // esi
  int NumParam;   // eax
  char *v9;       // eax
  char v10[1032]; // [esp+20h] [ebp-408h] BYREF

  v7 = va("%c", 102);
  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(a1, a2, a3, a4, a5, a6, a7, 0, NumParam - 1,
                             "Game Message", v10, 1024);
  v9 = va("%s \"%s\"", v7, v10);
  SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, v9);
}

void __cdecl GScr_PostLoadScripts(void) { UNIMPLEMENTED(); }

void __cdecl Scr_PlayLoopRumbleOnPos(void) { ; }

void __cdecl Scr_PlayRumbleOnPos(void) { ; }

void __cdecl ScrCmd_Delete(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_UseBy(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_LinkTo(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl GScr_PlaceSpawnPoint(struct scr_entref_t) {
  gentity_s *v1; // edi
  trace_t v3;    // [esp+24h] [ebp-54h] BYREF
  float v4;      // [esp+48h] [ebp-30h] BYREF
  float v5;      // [esp+4Ch] [ebp-2Ch]
  float v6;      // [esp+50h] [ebp-28h]
  float v7;      // [esp+54h] [ebp-24h] BYREF
  float v8;      // [esp+58h] [ebp-20h]
  float v9;      // [esp+5Ch] [ebp-1Ch]

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
  }
  v7 = v1->r.currentOrigin[0];
  v8 = v1->r.currentOrigin[1];
  v9 = v1->r.currentOrigin[2];
  v4 = v1->r.currentOrigin[0];
  v5 = v1->r.currentOrigin[1];
  v6 = v1->r.currentOrigin[2] + 128.0;
  G_TraceCapsule(&v3, &v7, (const float *)&playerMins,
                 (const float *)&playerMaxs, &v4, v1->s.number, 42008593);
  v7 = (float)((float)(v4 - v7) * v3.fraction) + v7;
  v8 = (float)((float)(v5 - v8) * v3.fraction) + v8;
  v9 = (float)((float)(v6 - v9) * v3.fraction) + v9;
  v4 = v7;
  v5 = v8;
  v6 = v9 - 262144.0;
  G_TraceCapsule(&v3, &v7, (const float *)&playerMins,
                 (const float *)&playerMaxs, &v4, v1->s.number, 42008593);
  v1->s.groundEntityNum = v3.entityNum;
  v7 = v7 + (float)((float)(v4 - v7) * v3.fraction);
  v8 = v8 + (float)((float)(v5 - v8) * v3.fraction);
  v9 = v9 + (float)(v3.fraction * (float)(v6 - v9));
  G_TraceCapsule(&v3, &v7, (const float *)&playerMins,
                 (const float *)&playerMaxs, &v7, v1->s.number, 42008593);
  if (v3.allsolid)
    Com_Printf("WARNING: Spawn point entity %i is in solid at (%i, %i, %i)\n",
               v1->s.number, (int)v1->r.currentOrigin[0],
               (int)v1->r.currentOrigin[1], (int)v1->r.currentOrigin[2]);
  return G_SetOrigin(v1, &v7);
}

void __cdecl Scr_GrenadeExplosionEffect(void) {
  gentity_s *v0;   // esi
  uint32_t result; // eax
  trace_t v2;      // [esp+2Ch] [ebp-5Ch] BYREF
  float v3[3];     // [esp+50h] [ebp-38h] BYREF
  float v4;        // [esp+5Ch] [ebp-2Ch] BYREF
  float v5;        // [esp+60h] [ebp-28h]
  float v6;        // [esp+64h] [ebp-24h]
  float v7[3];     // [esp+68h] [ebp-20h] BYREF
  float v8[5];     // [esp+74h] [ebp-14h] BYREF

  Scr_GetVector(0, v8);
  v4 = v8[0];
  v5 = v8[1];
  v6 = v8[2] + 1.0;
  v0 = G_TempEntity(&v4, 188);
  v7[0] = 0.0;
  v7[1] = 0.0;
  v7[2] = 1.0;
  v0->s.eventParm = (unsigned __int8)DirToByte(v7);
  v3[0] = v4;
  v3[1] = v5;
  v3[2] = v6 - 17.0;
  G_TraceCapsule(&v2, &v4, (trace_t *)vec3_origin, vec3_origin, v3, 1023,
                 (const float *)0x811);
  result = (v2.surfaceFlags & 0x1F00000) >> 20;
  v0->s.surfType = result;
  return result;
}

void __cdecl Scr_PhysicsTrace(void) { UNIMPLEMENTED(); }

void __cdecl Scr_BulletTracePassed(void) { UNIMPLEMENTED(); }

void __cdecl Scr_BulletTrace(void) { UNIMPLEMENTED(); }

void __cdecl GScr_RadiusDamage(void) { UNIMPLEMENTED(); }

void __cdecl GScr_AddTestClient(void) { UNIMPLEMENTED(); }

int __cdecl GScr_LoadScriptAndLabel(char const *, char const *, int) {
  UNIMPLEMENTED();
}

void __cdecl GScr_LoadLevelScript(void) { UNIMPLEMENTED(); }
