void __cdecl G_UpdateObjectiveToClients(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_LogPrintf(char const *fmt, ...)
{
  int result;       // eax
  char __str[1024]; // [esp+2Ch] [ebp-81Ch] BYREF
  char v3[1024];    // [esp+42Ch] [ebp-41Ch] BYREF
  va_list v4;       // [esp+82Ch] [ebp-1Ch]
  va_list va;       // [esp+854h] [ebp+Ch] BYREF

  va_start(va, __format);
    if (dword_1934498) {
      va_copy(v4, va);
      vsnprintf(__str, 0x400u, __format, va);
      Com_sprintf(v3, 0x400u, "%3i:%i%i %s", dword_193466C / 1000 / 60,
                  dword_193466C / 1000 % 60 / 10,
                  dword_193466C / 1000 % 60 % 10, __str);
      return FS_Write(v3, strlen(v3), dword_1934498);
    }
  return result;
}

struct clientState_s *__cdecl G_GetClientState(int clientNum)
{
  return level + 10404 * a1 + 10056;
}

void __cdecl G_SetClientArchiveTime(int clientNum, int time)
{
  int result; // eax

  result = 2601 * a1;
  *(_DWORD *)(level + 10404 * a1 + 9908) = a2;
  return result;
}

int __cdecl G_GetClientArchiveTime(int clientNum)
{
  return *(_DWORD *)(level + 10404 * a1 + 9908);
}

int __cdecl G_GetClientScore(int clientNum)
{
  return *(_DWORD *)(level + 10404 * a1 + 9912);
}

float __cdecl G_GetFogOpaqueDistSqrd()
{
  return flt_193625C;
}

void __cdecl G_SetSavePersist(int savepersist)
{
  int result; // eax

  result = a1;
  dword_19361D4 = a1;
  return result;
}

int __cdecl G_GetSavePersist()
{
  return dword_19361D4;
}

void __cdecl G_UpdateHudElemsToClients(void)
{
  UNIMPLEMENTED();
}

void __cdecl CalculateRanks()
{
  size_t v0; // ecx
  int v1;    // edx
  int v2;    // eax

  v0 = 0;
  dword_1934698 = 0;
  dword_1934FAC = 0;
    if (dword_1934664 <= 0) {
      v0 = dword_1934698;
    }
    else {
      v1 = 0;
      v2 = level;
        do {
            if (*(_DWORD *)(v2 + 9924)) {
              dword_1934690[v0++ + 3] = v1;
              dword_1934698 = v0;
              if (*(_DWORD *)(v2 + 10060) != 3 && *(_DWORD *)(v2 + 9924) == 2)
                ++dword_1934FAC;
            }
          ++v1;
          v2 += 10404;
        }
      while (v1 < dword_1934664);
    }
  qsort(&unk_193469C, v0, 4u,
        (int(__cdecl *)(const void *, const void *))SortRanks);
  dword_1934690[0] = 1;
}

void __cdecl G_AddDebugString(float const *const xyz, float const *const color,
                              float scale, char const *pszText)
{
  return CL_AddDebugString(a1, a2, a3, __src, 1);
}

void __cdecl SendScoreboardMessageToAllIntermissionClients(void)
{
  UNIMPLEMENTED();
}

void __cdecl ExitLevel()
{
  int v0;  // ebx
  int v1;  // ecx
  int v2;  // edx
  int v3;  // ecx
  int v4;  // edx
  char v6; // [esp+8h] [ebp-10h]

  Cbuf_ExecuteText(2, "map_rotate\n", v6);
  dword_1934680 = 0;
  dword_1934684 = 0;
  v0 = g_maxclients;
    if (*(int *)(g_maxclients + 8) > 0) {
      v1 = 0;
      v2 = 0;
        do {
            while (*(_DWORD *)(level[0] + v2 + 9924) != 2) {
              ++v1;
              v2 += 10404;
              if (v1 >= *(_DWORD *)(v0 + 8))
                goto LABEL_6;
            }
          *(_DWORD *)(level[0] + v2 + 9912) = 0;
          v0 = g_maxclients;
          ++v1;
          v2 += 10404;
        }
      while (v1 < *(_DWORD *)(g_maxclients + 8));
    LABEL_6:
        if (*(int *)(v0 + 8) > 0) {
          v3 = 0;
          v4 = 0;
            do {
                while (*(_DWORD *)(level[0] + v4 + 9924) != 2) {
                  ++v3;
                  v4 += 10404;
                  if (v3 >= *(_DWORD *)(v0 + 8))
                    return G_LogPrintf("ExitLevel: executed\n");
                }
              *(_DWORD *)(level[0] + v4 + 9924) = 1;
              v0 = g_maxclients;
              ++v3;
              v4 += 10404;
            }
          while (v3 < *(_DWORD *)(g_maxclients + 8));
        }
    }
  return G_LogPrintf("ExitLevel: executed\n");
}

void __cdecl G_RunThink(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl CheckVote()
{
  UNIMPLEMENTED();
}

void *__cdecl Hunk_AllocXAnimServer(int)
{
  return Hunk_AllocLowInternal(__len);
}

void __cdecl G_FreeEntities(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_ShutdownGame(int freeScripts)
{
  UNIMPLEMENTED();
}

void __cdecl DebugDumpAnims(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_SightTrace(int *hitNum, float const *const start,
                          float const *const end, int passEntityNum,
                          int contentmask)
{
  return SV_SightTrace(a1, a2, vec3_origin, vec3_origin, a3,
                       (unsigned int)a4 | 0x3FF00000000LL, a5);
}

int __cdecl G_LocationalTracePassed(float const *const start,
                                    float const *const end, int passEntityNum,
                                    int contentmask)
{
  return SV_TracePassed(a1, vec3_origin, vec3_origin, a2,
                        (unsigned int)a3 | 0x3FF00000000LL, a4, 1, 1);
}

void __cdecl G_LocationalTrace(struct trace_t *results,
                               float const *const start, float const *const end,
                               int passEntityNum, int contentmask,
                               unsigned char *priorityMap)
{
  return SV_Trace(a1, a2, (trace_t *)vec3_origin, vec3_origin, a3, a4, a5, 1,
                  a6, 1);
}

int __cdecl G_TraceCapsuleComplete(float const *const, float const *const,
                                   float const *const, float const *const, int,
                                   int)
{
  return SV_TracePassed(a1, a2, a3, a4, (unsigned int)a5 | 0x3FF00000000LL, a6,
                        0, 0);
}

void __cdecl G_TraceCapsule(struct trace_t *results, float const *const start,
                            float const *const mins, float const *const maxs,
                            float const *const end, int passEntityNum,
                            int contentmask)
{
  return SV_Trace(a1, a2, a3, a4, a5, a6, a7, 0, 0, 0);
}

void __cdecl G_XAnimUpdateEnt(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl G_RunFrame(int levelTime)
{
  UNIMPLEMENTED();
}

void __cdecl G_InitGame(int levelTime, int randomSeed, int restart,
                        int savepersist)
{
  UNIMPLEMENTED();
}

struct entityHandler_t *entityHandlers;
struct dvar_s const *const g_password;
struct dvar_s const *const g_smoothClients;
struct dvar_s const *const g_voteAbstainWeight;
struct dvar_s const *const g_gravity;
struct dvar_s const *const g_filterBan;
struct dvar_s const *const g_voiceChatsAllowed;
struct dvar_s const *const g_deadChat;
struct dvar_s const *const player_meleeHeight;
struct dvar_s const *const g_dumpAnims;
struct dvar_s const *const g_friendlyfireDist;
struct dvar_s const *const g_dropUpSpeedRand;
struct dvar_s const *const g_maxclients;
struct dvar_s const *const g_TeamName_Allies;
struct dvar_s const *const g_debugBullets;
struct dvar_s const *const g_synchronousClients;
struct dvar_s const *const player_meleeRange;
struct dvar_s const *const g_knockback;
struct dvar_s const *const voice_global;
struct dvar_s const *const g_allowVote;
struct dvar_s const *const g_dedicated;
struct dvar_s const *const g_TeamColor_Allies;
struct dvar_s const *const g_antilag;
struct dvar_s const *const g_playerCollisionEjectSpeed;
struct dvar_s const *const g_useholdspawndelay;
struct dvar_s const *const g_weaponAmmoPools;
struct dvar_s const *const g_ScoresBanner_Axis;
struct dvar_s const *const voice_localEcho;
struct dvar_s const *const g_dropUpSpeedBase;
struct dvar_s const *const g_listEntity;
struct dvar_s const *const g_inactivity;
struct dvar_s const *const voice_deadChat;
struct dvar_s const *const g_cheats;
struct dvar_s const *const g_maxDroppedWeapons;
struct dvar_s const *const g_dropForwardSpeed;
struct dvar_s const *const g_ScoresBanner_None;
struct dvar_s const *const player_meleeWidth;
struct dvar_s const *const g_voiceChatTalkingDuration;
struct dvar_s const *const g_useholdtime;
struct dvar_s const *const g_ScoresBanner_Spectators;
struct dvar_s const *const g_speed;
struct dvar_s const *const g_friendlyNameDist;
struct dvar_s const *const g_log;
struct dvar_s const *const g_TeamName_Axis;
struct dvar_s const *const g_TeamColor_Axis;
struct dvar_s const *const g_NoScriptSpam;
struct dvar_s const *const g_banIPs;
struct dvar_s const *const g_gametype;
struct dvar_s const *const g_debugLocDamage;
struct dvar_s const *const g_logSync;
struct dvar_s const *const g_mantleBlockTimeBuffer;
struct dvar_s const *const g_oldVoting;
struct dvar_s const *const g_ScoresBanner_Allies;
struct dvar_s const *const g_motd;
struct dvar_s const *const g_debugDamage;
struct dvar_s const *const g_clonePlayerMaxVelocity;
struct gentity_s *g_entities;
struct bgs_t level_bgs;
struct level_locals_t level;

int __cdecl SortRanks(void const *, void const *)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edx
  int v5;     // eax
  int v6;     // eax

  v2 = (_DWORD *)(level + 10404 * *a1);
  v3 = (_DWORD *)(level + 10404 * *a2);
  if (v2[2481] == 1)
    return 1;
  if (v3[2481] == 1)
    return -1;
    if (v2[2515] != 3) {
        if (v3[2515] != 3) {
          v5 = v3[2478];
            if (v2[2478] <= v5) {
              if (v2[2478] < v5)
                return 1;
              v6 = v3[2479];
              if (v2[2479] >= v6)
                return v2[2479] > v6;
            }
        }
      return -1;
    }
  if (v3[2515] != 3)
    return 1;
  if (v2 < v3)
    return -1;
  return v2 > v3;
}

void __cdecl G_FreeAnimTreeInstances(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_LoadAnimTreeInstances(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_RegisterDvars(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_CreateDObj(struct DObjModel_s *, unsigned short,
                          struct XAnimTree_s *, int, struct clientInfo_t *)
{
  UNIMPLEMENTED();
}

void __cdecl G_RunFrameForEntity(struct gentity_s *)
{
  UNIMPLEMENTED();
}
