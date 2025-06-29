char *__cdecl strstr(char *, char const *) { UNIMPLEMENTED(); }

struct rectDef_s const *__cdecl Window_GetRect(struct windowDef_t const *) {
  UNIMPLEMENTED();
}

int __cdecl CG_CrosshairPlayer() {
  if (dword_DB8C30 > dword_DBEE50 + 1000)
    return -1;
  else
    return dword_DBEE4C;
}

void __cdecl CG_ClearSoundPlaybackTracking(void) { UNIMPLEMENTED(); }

bool __cdecl CG_PlaySoundOnCurrentLocalClient(int entitynum,
                                              float const *const origin,
                                              char const *aliasname) {
  return 1;
}

bool __cdecl CG_PlaySoundOnFirstClient() { return 1; }

char const *__cdecl CG_Argv(int arg) {
  Cmd_ArgvBuffer(a1, CG_Argv(int)::buffer, 1024);
  return CG_Argv(int)::buffer;
}

void __cdecl CG_SwitchToLocalClient(int) { UNIMPLEMENTED(); }

void __cdecl CG_GetEntityOrientation(int entnum, float * const origin_out, float  axis_out)[3])
{
  UNIMPLEMENTED();
}

void __cdecl CG_GetDObjOrientation(int dobjHandle, float  axis_out)[3])
{
  UNIMPLEMENTED();
}

void __cdecl CG_FreeWeapons() { UNIMPLEMENTED(); }

void __cdecl CG_InitVote() { UNIMPLEMENTED(); }

void __cdecl CG_Shutdown() { UNIMPLEMENTED(); }

void __cdecl CG_TranslateHudElemMessage(char const *message,
                                        char const *messageType,
                                        char *const hudElemString) {
  char *v3;      // edx
  signed int v4; // ecx
  int result;    // eax
  int v6;        // [esp+18h] [ebp-20h] BYREF
  _DWORD v7[7];  // [esp+1Ch] [ebp-1Ch] BYREF

  v3 = SEH_LocalizeTextMessage(a1, a2, LOCMSG_SAFE);
  v4 = strlen(v3) + 1;
  result = v4 - 1;
  v6 = v4 - 1;
  if (v4 <= 256) {
    memcpy(__dst, v3, v4 - 1);
    __dst[v6] = 0;
    v7[0] = 0;
    do
      result = CG_ReplaceDirective(v7, (size_t *)&v6, __dst);
    while ((_BYTE)result);
  }
  return result;
}

void __cdecl CG_SafeTranslateHudElemString(int index,
                                           char *const hudElemString) {
  int result;         // eax
  char *ConfigString; // eax
  char *v4;           // edx
  signed int v5;      // ecx
  int v6;             // [esp+18h] [ebp-20h] BYREF
  _DWORD v7[7];       // [esp+1Ch] [ebp-1Ch] BYREF

  result = a1;
  if (a1) {
    ConfigString = CL_GetConfigString(a1 + 1310);
    v4 = SEH_LocalizeTextMessage(ConfigString, "hudelem string", LOCMSG_SAFE);
    v5 = strlen(v4) + 1;
    result = v5 - 1;
    v6 = v5 - 1;
    if (v5 <= 256) {
      memcpy(__dst, v4, v5 - 1);
      __dst[v6] = 0;
      v7[0] = 0;
      do
        result = CG_ReplaceDirective(v7, (size_t *)&v6, __dst);
      while ((_BYTE)result);
    }
  }
  return result;
}

void *__cdecl Hunk_AllocXAnimClient(int size) {
  return Hunk_AllocInternal(__len);
}

void __cdecl CG_StartAmbient() {
  char *ConfigString;    // ebx
  const char *v1;        // eax
  const snd_alias_t *v2; // esi
  const char *v3;        // eax
  int v4;                // eax
  int v5;                // edx
  int v6;                // eax

  ConfigString = CL_GetConfigString(3);
  v1 = (const char *)Info_ValueForKey(ConfigString, "n");
  v2 = (const snd_alias_t *)CL_PickSoundAlias(v1);
  v3 = (const char *)Info_ValueForKey(ConfigString, "t");
  v4 = atoi(v3);
  v5 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
  v6 = v4 - v5;
  if (v6 < 0 || !v5)
    v6 = 0;
  return SND_PlayAmbientAlias(v2, v6, SASYS_CGAME);
}

void __cdecl CG_BoldGameMessage(char const *msg) {
  return CL_ConsolePrint(PMSG_BOLDGAME, a1, 0,
                         *(print_msg_type_t *)(cg_gameBoldMessageWidth + 8));
}

void __cdecl CG_GameMessage(char const *msg) {
  return CL_ConsolePrint(PMSG_GAME, a1, 0,
                         *(print_msg_type_t *)(cg_gameMessageWidth + 8));
}

int __cdecl CG_PlaySoundAliasAsMasterByName(int entitynum,
                                            float const *const origin,
                                            char const *aliasname) {
  snd_alias_t *v3;     // ebx
  int v4;              // esi
  char *pszSubtitle;   // edi
  print_msg_type_t v6; // ebx
  int v7;              // eax
  float v9;            // [esp+2Ch] [ebp-1Ch]

  v3 = (snd_alias_t *)CL_PickSoundAlias(a3);
  if (!v3)
    return 0;
  v4 = SND_PlaySoundAliasAsMaster(v3, a1, a2, 0, (const float *)1);
  if (v4) {
    pszSubtitle = (char *)v3->pszSubtitle;
    if (pszSubtitle) {
      if (*((float *)cgs + 6053) <= 1.3333334)
        v6 = *(_DWORD *)(cg_subtitleWidthStandard + 8);
      else
        v6 = *(_DWORD *)(cg_subtitleWidthWidescreen + 8);
      v9 = floorf((float)(1000.0 * *(float *)(cg_subtitleMinTime + 8)) + 0.5);
      v7 = (int)v9;
      if ((int)v9 - v4 < 0)
        v7 = v4;
      CL_SubtitlePrint(pszSubtitle, v7, v6);
    }
  }
  return v4;
}

int __cdecl CG_PlaySoundAliasByName(int entitynum, float const *const origin,
                                    char const *aliasname) {
  snd_alias_t *v3;     // ebx
  int v4;              // esi
  char *pszSubtitle;   // edi
  print_msg_type_t v6; // ebx
  int v7;              // eax
  float v9;            // [esp+2Ch] [ebp-1Ch]

  v3 = (snd_alias_t *)CL_PickSoundAlias(a3);
  if (!v3)
    return 0;
  v4 = SND_PlaySoundAlias(v3, a1, a2, 0, (const float *)1);
  if (v4) {
    pszSubtitle = (char *)v3->pszSubtitle;
    if (pszSubtitle) {
      if (*((float *)cgs + 6053) <= 1.3333334)
        v6 = *(_DWORD *)(cg_subtitleWidthStandard + 8);
      else
        v6 = *(_DWORD *)(cg_subtitleWidthWidescreen + 8);
      v9 = floorf((float)(1000.0 * *(float *)(cg_subtitleMinTime + 8)) + 0.5);
      v7 = (int)v9;
      if ((int)v9 - v4 < 0)
        v7 = v4;
      CL_SubtitlePrint(pszSubtitle, v7, v6);
    }
  }
  return v4;
}

int __cdecl CG_PlaySoundAlias(int entitynum, float const *const origin,
                              struct snd_alias_list_t *aliasList) {
  snd_alias_t *v3;     // ebx
  int v4;              // esi
  char *pszSubtitle;   // edi
  print_msg_type_t v6; // ebx
  int v7;              // eax
  float v9;            // [esp+2Ch] [ebp-1Ch]

  v3 = (snd_alias_t *)Com_PickSoundAliasFromList(a3);
  if (!v3)
    return 0;
  v4 = SND_PlaySoundAlias(v3, a1, a2, 0, (const float *)1);
  if (v4) {
    pszSubtitle = (char *)v3->pszSubtitle;
    if (pszSubtitle) {
      if (*((float *)cgs + 6053) <= 1.3333334)
        v6 = *(_DWORD *)(cg_subtitleWidthStandard + 8);
      else
        v6 = *(_DWORD *)(cg_subtitleWidthWidescreen + 8);
      v9 = floorf((float)(1000.0 * *(float *)(cg_subtitleMinTime + 8)) + 0.5);
      v7 = (int)v9;
      if ((int)v9 - v4 < 0)
        v7 = v4;
      CL_SubtitlePrint(pszSubtitle, v7, v6);
    }
  }
  return v4;
}

int __cdecl CG_PlayEntitySoundAliasByName(int, char const *) {
  UNIMPLEMENTED();
}

int __cdecl CG_PlayEntitySoundAlias(int entitynum,
                                    struct snd_alias_list_t *aliasList) {
  const float *v2;     // edi
  snd_alias_t *v3;     // eax
  snd_alias_t *v4;     // ebx
  int v5;              // esi
  char *pszSubtitle;   // edi
  print_msg_type_t v7; // ebx
  int v8;              // eax
  float v10;           // [esp+2Ch] [ebp-1Ch]

  v2 = (const float *)((char *)cg_entities + 548 * a1 + 264);
  v3 = (snd_alias_t *)Com_PickSoundAliasFromList(a2);
  v4 = v3;
  if (!v3)
    return 0;
  v5 = SND_PlaySoundAlias(v3, (float *)a1, v2, 0, (const float *)1);
  if (v5) {
    pszSubtitle = (char *)v4->pszSubtitle;
    if (pszSubtitle) {
      if (*((float *)cgs + 6053) <= 1.3333334)
        v7 = *(_DWORD *)(cg_subtitleWidthStandard + 8);
      else
        v7 = *(_DWORD *)(cg_subtitleWidthWidescreen + 8);
      v10 = floorf((float)(1000.0 * *(float *)(cg_subtitleMinTime + 8)) + 0.5);
      v8 = (int)v10;
      if ((int)v10 - v5 < 0)
        v8 = v5;
      CL_SubtitlePrint(pszSubtitle, v8, v7);
    }
  }
  return v5;
}

int __cdecl CG_PlayClientSoundAliasByName(char const *aliasname) {
  float *v1;           // edi
  const float *v2;     // esi
  snd_alias_t *v3;     // eax
  snd_alias_t *v4;     // ebx
  int v5;              // esi
  char *pszSubtitle;   // edi
  print_msg_type_t v7; // ebx
  int v8;              // eax
  float v10;           // [esp+2Ch] [ebp-1Ch]

  v1 = *(float **)(dword_D930A4 + 216);
  v2 = (const float *)(dword_D930A4 + 32);
  v3 = (snd_alias_t *)CL_PickSoundAlias(a1);
  v4 = v3;
  if (!v3)
    return 0;
  v5 = SND_PlaySoundAlias(v3, v1, v2, 0, (const float *)1);
  if (v5) {
    pszSubtitle = (char *)v4->pszSubtitle;
    if (pszSubtitle) {
      if (*((float *)cgs + 6053) <= 1.3333334)
        v7 = *(_DWORD *)(cg_subtitleWidthStandard + 8);
      else
        v7 = *(_DWORD *)(cg_subtitleWidthWidescreen + 8);
      v10 = floorf((float)(1000.0 * *(float *)(cg_subtitleMinTime + 8)) + 0.5);
      v8 = (int)v10;
      if ((int)v10 - v5 < 0)
        v8 = v5;
      CL_SubtitlePrint(pszSubtitle, v8, v7);
    }
  }
  return v5;
}

int __cdecl CG_PlayClientSoundAlias(struct snd_alias_list_t *aliasList) {
  float *v1;           // edi
  const float *v2;     // esi
  snd_alias_t *v3;     // eax
  snd_alias_t *v4;     // ebx
  int v5;              // esi
  char *pszSubtitle;   // edi
  print_msg_type_t v7; // ebx
  int v8;              // eax
  float v10;           // [esp+2Ch] [ebp-1Ch]

  v1 = *(float **)(dword_D930A4 + 216);
  v2 = (const float *)(dword_D930A4 + 32);
  v3 = (snd_alias_t *)Com_PickSoundAliasFromList(a1);
  v4 = v3;
  if (!v3)
    return 0;
  v5 = SND_PlaySoundAlias(v3, v1, v2, 0, (const float *)1);
  if (v5) {
    pszSubtitle = (char *)v4->pszSubtitle;
    if (pszSubtitle) {
      if (*((float *)cgs + 6053) <= 1.3333334)
        v7 = *(_DWORD *)(cg_subtitleWidthStandard + 8);
      else
        v7 = *(_DWORD *)(cg_subtitleWidthWidescreen + 8);
      v10 = floorf((float)(1000.0 * *(float *)(cg_subtitleMinTime + 8)) + 0.5);
      v8 = (int)v10;
      if ((int)v10 - v5 < 0)
        v8 = v5;
      CL_SubtitlePrint(pszSubtitle, v8, v7);
    }
  }
  return v5;
}

void __cdecl CG_PlaySmokeGrenadesAtTime(int gametime) { UNIMPLEMENTED(); }

void __cdecl CG_Init(int serverMessageNum, int serverCommandSequence,
                     int clientNum) {
  UNIMPLEMENTED();
}

struct cg_t *cg;
struct cgs_t *cgs;
struct centity_s *cg_entities;
struct weaponInfo_s *cg_weapons;
struct itemInfo_t *cg_items;
struct dvar_s const *const cg_marks;
struct dvar_s const *const cg_shock_mouse_maxyawspeed;
struct dvar_s const *const cg_shock_volume_weapon;
struct dvar_s const *const cg_shock_volume_voice;
struct dvar_s const *const cg_hudCompassMaxRange;
struct dvar_s const *const cg_gun_y;
struct dvar_s const *const cg_noTaunt;
struct dvar_s const *const cg_scoreboardScrollStep;
struct dvar_s const *const cg_shock_volume_auto2d;
struct dvar_s const *const cg_hudSplitscreenOffsetsUseScale;
struct dvar_s const *const cg_fovMin;
struct dvar_s const *const cg_drawBreathHint;
struct dvar_s const *const cg_shock_volume_shellshock;
struct dvar_s const *const cg_hudCompassSoundPingFadeTime;
struct dvar_s const *const cg_shock_volume_announcer;
struct dvar_s const *const cg_drawFPS;
struct dvar_s const *const cg_subtitlePosX;
struct dvar_s const *const cg_subtitlePosY;
struct dvar_s const *const cg_drawGameMessages;
struct dvar_s const *const cg_thirdPerson;
struct dvar_s const *const cg_hudObjectiveTextHeight;
struct dvar_s const *const cg_drawHealth;
struct dvar_s const *const cg_brass;
struct dvar_s const *const cg_hudGrenadeIconMaxRange;
struct displayContextDef_s cgDC;
struct dvar_s const *const cg_shock_volume_auto;
struct dvar_s const *const cg_hudNormalSplitscreenScale;
struct dvar_s const *const cg_shock_soundFadeInTime;
struct dvar_s const *const cg_drawCrosshair;
struct dvar_s const *const cg_hudObjectiveMinHeight;
struct dvar_s const *const cg_hudObjectiveMinAlpha;
struct dvar_s const *const cg_hudSplitscreenCompassScale;
struct dvar_s const *const cg_hudSplitscreenStanceScale;
struct dvar_s const *const cg_scoreboardItemHeight;
struct dvar_s const *const cg_hudGrenadeIconWidth;
struct dvar_s const *const cg_gun_z;
struct dvar_s const *const cg_hudDamageIconOffset;
struct dvar_s const *const cg_voiceIconSize;
struct dvar_s const *const cg_drawTurretCrosshair;
struct dvar_s const *const cg_shock_mouse_fadeTime;
struct dvar_s const *const cg_hudDamageIconHeight;
struct dvar_s const *const cg_drawSnapshot;
struct dvar_s const *const cg_shock_soundWetLevel;
struct dvar_s const *const cg_hudChatPosition;
struct dvar_s const *const cg_weaponrightbone;
struct dvar_s const *const cg_voiceSpriteTime;
struct dvar_s const *const cg_hudCompassSpringyPointers;
struct dvar_s const *const cg_gun_move_minspeed;
struct dvar_s const *const cg_gun_ofs_u;
struct dvar_s const *const cg_subtitles;
struct dvar_s const *const cg_hudObjectiveMaxRange;
struct dvar_s const *const cg_hudStanceHintPrints;
struct dvar_s const *const cg_youInKillCamSize;
struct dvar_s const *const cg_shock_sound;
struct dvar_s const *const cg_hudDamageIconWidth;
struct dvar_s const *const cg_hudProneY;
struct dvar_s const *const cg_draw2D;
struct dvar_s const *const cg_gun_x;
struct dvar_s const *const cg_crosshairAlpha;
struct dvar_s const *const cg_hudCompassMinRange;
struct dvar_s const *const cg_debugPosition;
struct dvar_s const *const cg_drawGun;
struct dvar_s const *const cg_shock_soundModEndDelay;
struct dvar_s const *const cg_hudGrenadeIconOffset;
struct dvar_s const *const cg_hudSplitscreenScoreboardScale;
struct dvar_s const *const cg_centertime;
struct dvar_s const *const cg_chatHeight;
struct dvar_s const *const cg_minicon;
struct dvar_s const *const cg_drawCrosshairNamesPosX;
struct dvar_s const *const cg_gun_move_rate;
struct dvar_s const *const cg_tracerSpeed;
struct dvar_s const *const cg_shock_screenBlendFadeTime;
struct dvar_s const *const cg_shock_viewKickPeriod;
struct dvar_s const *const cg_shock_volume_local;
struct dvar_s const *const cg_hudGrenadePointerPivot;
struct dvar_s const *const cg_crosshairAlphaMin;
struct dvar_s const *const cg_shock_volume_body;
struct dvar_s const *const cg_tracerChance;
struct dvar_s const *const cg_hudGrenadeIconInScope;
struct dvar_s const *const cg_hudSplitscreenBannerScoreboardScale;
struct dvar_s const *const cg_fovScale;
struct dvar_s const *const cg_hudObjectiveTextScale;
struct dvar_s const *const cg_crosshairEnemyColor;
struct dvar_s const *const cg_hudLegacySplitscreenScale;
struct dvar_s const *const cg_hudCompassMinRadius;
struct dvar_s const *const cg_tracerScale;
struct dvar_s const *const cg_weaponCycleDelay;
struct dvar_s const *const cg_gameMessageWidth;
struct dvar_s const *const cg_thirdPersonRange;
struct dvar_s const *const cg_drawSoundOverlay;
struct dvar_s const *const cg_shock_soundLoopEndDelay;
struct dvar_s const *const cg_gun_ofs_r;
struct dvar_s const *const cg_hudGrenadeIconMaxHeight;
struct dvar_s const *const cg_shock_screenBlendTime;
struct dvar_s const *const cg_debugEvents;
struct dvar_s const *const cg_shock_soundDryLevel;
struct dvar_s const *const cg_hudStanceFlash;
struct dvar_s const *const cg_drawScriptUsage;
struct dvar_s const *const cg_shock_soundLoopFadeTime;
struct dvar_s const *const cg_shock_volume_music;
struct dvar_s const *const cg_crosshairDynamic;
struct dvar_s const *const cg_hudDamageIconInScope;
struct dvar_s const *const cg_drawCrosshairNames;
struct dvar_s const *const cg_gun_move_r;
struct dvar_s const *const cg_constantSizeHeadIcons;
struct dvar_s const *const cg_footsteps;
struct dvar_s const *const cg_shock_volume_menu;
struct dvar_s const *const cg_gun_move_f;
struct dvar_s const *const cg_hudGrenadeIconHeight;
struct dvar_s const *const cg_shock_mouse_maxpitchspeed;
struct dvar_s const *const cg_hudGrenadePointerWidth;
struct dvar_s const *const cg_nopredict;
struct dvar_s const *const cg_drawMaterial;
struct dvar_s const *const cg_shock_viewKickRadius;
struct dvar_s const *const cg_synchronousClients;
struct dvar_s const *const cg_connectionIconSize;
struct dvar_s const *const cg_dumpAnims;
struct dvar_s const *const cg_errorDecay;
struct dvar_s const *const cg_subtitleWidthStandard;
struct dvar_s const *const cg_tracerScaleMinDist;
struct dvar_s const *const cg_drawMantleHint;
struct dvar_s const *const cg_gameBoldMessageWidth;
struct dvar_s const *const cg_tracerWidth;
struct dvar_s const *const cg_centerPrintY;
struct dvar_s const *const cg_hudCompassSize;
struct dvar_s const *const cg_drawCrosshairNamesPosY;
struct dvar_s const *const cg_headIconMinScreenRadius;
struct dvar_s const *const cg_chatTime;
struct dvar_s const *const cg_shock_volume_item;
struct dvar_s const *const cg_marksLimit;
struct dvar_s const *const cg_splitscreenSpectatorScaleIncrease;
struct dvar_s const *const cg_hudDamageIconTime;
struct dvar_s const *const cg_blood;
struct dvar_s const *const cg_teamChatsOnly;
struct dvar_s const *const cg_viewsize;
struct dvar_s const *const cg_weaponleftbone;
struct dvar_s const *const cg_scriptIconSize;
struct dvar_s const *const cg_showmiss;
struct dvar_s const *const cg_predictItems;
struct dvar_s const *const cg_shock_soundRoomType;
struct dvar_s const *const cg_shock_mouse;
struct dvar_s const *const cg_descriptiveText;
struct dvar_s const *const cg_fov;
struct dvar_s const *const cg_hudSplitscreenCompassElementScale;
struct dvar_s const *const cg_drawLagometer;
struct dvar_s const *const cg_subtitleWidthWidescreen;
float cg_hudSplitscreenScale;
struct dvar_s const *const cg_developer;
struct dvar_s const *const cg_subtitleCharHeight;
struct dvar_s const *const cg_hudGrenadePointerHeight;
struct dvar_s const *const cg_gun_move_u;
struct dvar_s const *const cg_hintFadeTime;
struct dvar_s const *const cg_shock_soundFadeOutTime;
struct dvar_s const *const cg_shock_mouse_sensitivityscale;
struct dvar_s const *const cg_subtitleMinTime;
struct dvar_s const *const cg_tracerScaleDistRange;
struct dvar_s const *const cg_paused;
struct dvar_s const *const cg_cursorHints;
struct dvar_s const *const cg_thirdPersonAngle;
struct dvar_s const *const cg_gun_ofs_f;
struct dvar_s const *const cg_scoreboardBannerHeight;
struct dvar_s const *const cg_tracerLength;
void __cdecl CG_InitViewDimensions(void) { UNIMPLEMENTED(); }

struct XModel *__cdecl CG_GetXModel(char const *) {
  return CL_RegisterModel();
}

struct entityState_s *__cdecl CG_FindOldestSmokeGrenade(int, int) {
  UNIMPLEMENTED();
}

int __cdecl CG_GetClientNumForLocalClient(int) { UNIMPLEMENTED(); }

void __cdecl CG_InitEntities(void) { UNIMPLEMENTED(); }

struct FxImpactTable *__cdecl CG_RegisterImpactEffects(char const *) {
  UNIMPLEMENTED();
}

void __cdecl CG_RegisterSurfaceTypeSounds(char const *,
                                          struct snd_alias_list_t **const) {
  UNIMPLEMENTED();
}

void __cdecl CG_RegisterSounds(void) {
  _DWORD *v0;      // ebx
  char *v1;        // edi
  int i;           // ebx
  const char *v3;  // eax
  char *v4;        // edi
  const char *v5;  // eax
  char *v6;        // edi
  const char *v7;  // eax
  char *v8;        // edi
  const char *v9;  // eax
  char *v10;       // edi
  const char *v11; // eax
  char *v12;       // edi
  const char *v13; // eax
  char *v14;       // edi
  const char *v15; // eax
  char *v16;       // edi
  const char *v17; // eax
  char *v18;       // edi
  const char *v19; // eax
  char *v20;       // edi
  const char *v21; // eax
  char *v22;       // edi
  const char *v23; // eax
  char *v24;       // edi
  const char *v25; // eax
  char *v26;       // edi
  const char *v27; // eax
  char *v28;       // edi
  const char *v29; // eax
  _DWORD *v30;     // ebx
  int result;      // eax
  char v32[280];   // [esp+10h] [ebp-118h] BYREF

  v0 = cgs;
  v0[12065] = Com_FindSoundAlias("player_out_of_ammo");
  v0[12066] = Com_FindSoundAlias("land_damage");
  v1 = (char *)(v0 + 12068);
  for (i = 0; i != 23; ++i) {
    v3 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "grenade_bounce", v3);
    *(_DWORD *)&v1[4 * i] = Com_FindSoundAlias(v32);
  }
  v4 = (char *)cgs + 48364;
  LOBYTE(i) = 0;
  do {
    v5 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "grenade_explode", v5);
    *(_DWORD *)&v4[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v6 = (char *)cgs + 48456;
  LOBYTE(i) = 0;
  do {
    v7 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "rocket_explode", v7);
    *(_DWORD *)&v6[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v8 = (char *)cgs + 48548;
  LOBYTE(i) = 0;
  do {
    v9 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "bullet_small", v9);
    *(_DWORD *)&v8[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v10 = (char *)cgs + 48640;
  LOBYTE(i) = 0;
  do {
    v11 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "bulletspray_small", v11);
    *(_DWORD *)&v10[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v12 = (char *)cgs + 48732;
  LOBYTE(i) = 0;
  do {
    v13 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "bullet_large", v13);
    *(_DWORD *)&v12[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v14 = (char *)cgs + 48824;
  LOBYTE(i) = 0;
  do {
    v15 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "step_run", v15);
    *(_DWORD *)&v14[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v16 = (char *)cgs + 48916;
  LOBYTE(i) = 0;
  do {
    v17 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "step_run_plr", v17);
    *(_DWORD *)&v16[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v18 = (char *)cgs + 49008;
  LOBYTE(i) = 0;
  do {
    v19 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "step_walk", v19);
    *(_DWORD *)&v18[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v20 = (char *)cgs + 49100;
  LOBYTE(i) = 0;
  do {
    v21 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "step_walk_plr", v21);
    *(_DWORD *)&v20[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v22 = (char *)cgs + 49192;
  LOBYTE(i) = 0;
  do {
    v23 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "step_prone", v23);
    *(_DWORD *)&v22[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v24 = (char *)cgs + 49284;
  LOBYTE(i) = 0;
  do {
    v25 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "step_prone_plr", v25);
    *(_DWORD *)&v24[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v26 = (char *)cgs + 49376;
  LOBYTE(i) = 0;
  do {
    v27 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "land", v27);
    *(_DWORD *)&v26[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v28 = (char *)cgs + 49468;
  LOBYTE(i) = 0;
  do {
    v29 = Com_SurfaceTypeToName(i);
    sprintf(v32, "%s_%s", "land_plr", v29);
    *(_DWORD *)&v28[4 * i++] = Com_FindSoundAlias(v32);
  } while (i != 23);
  v30 = cgs;
  v30[12390] = Com_FindSoundAlias("gear_rattle_run");
  v30[12391] = Com_FindSoundAlias("gear_rattle_plr_run");
  v30[12392] = Com_FindSoundAlias("gear_rattle_walk");
  v30[12393] = Com_FindSoundAlias("gear_rattle_plr_walk");
  v30[12394] = Com_FindSoundAlias("movement_foliage");
  v30[12395] = Com_FindSoundAlias("whizby");
  v30[12396] = Com_FindSoundAlias("melee_swing_large");
  v30[12397] = Com_FindSoundAlias("melee_swing_small");
  v30[12398] = Com_FindSoundAlias("melee_hit");
  v30[12399] = Com_FindSoundAlias("melee_hit_other");
  v30[12400] = Com_FindSoundAlias("weap_sniper_heartbeat");
  v30[12401] = Com_FindSoundAlias("weap_sniper_breathin");
  v30[12402] = Com_FindSoundAlias("weap_sniper_breathout");
  v30[12403] = Com_FindSoundAlias("weap_sniper_breathgasp");
  result = Com_FindSoundAlias("weap_offhand_select");
  v30[12404] = result;
  return result;
}

void __cdecl CG_FreeAnimTreeInstances(void) { UNIMPLEMENTED(); }

bool __cdecl CG_ReplaceDirective(int *, int *, char *const) { UNIMPLEMENTED(); }

void __cdecl CG_LoadAnimTreeInstances(void) { UNIMPLEMENTED(); }

void __cdecl CG_LoadHudMenu(void) { UNIMPLEMENTED(); }

void __cdecl CG_RegisterDvars(void) { UNIMPLEMENTED(); }

void __cdecl CG_SubtitlePrint(int, struct snd_alias_t *) { UNIMPLEMENTED(); }

void __cdecl CG_CreateDObj(struct DObjModel_s *, unsigned short,
                           struct XAnimTree_s *, int, struct clientInfo_t *) {
  int v5;               // eax
  unsigned __int16 v6;  // bx
  uint32_t iDObjWeapon; // edx
  int v8;               // ecx
  DObjModel_s *v9;      // edx
  int v10;              // eax

  v5 = a4;
  v6 = a2;
  iDObjWeapon = a5->iDObjWeapon;
  if (iDObjWeapon) {
    v8 = *((_DWORD *)cg_weapons + 109 * iDObjWeapon + 47);
    if (v8) {
      v9 = &a1[a2];
      *(_DWORD *)v9->model = v8;
      if (a5->leftHandGun)
        v10 = *(_DWORD *)(cg_weaponleftbone + 8);
      else
        v10 = *(_DWORD *)(cg_weaponrightbone + 8);
      *(_DWORD *)v9->boneName = v10;
      v9->ignoreCollision = 0;
      v6 = a2 + 1;
      v5 = a4;
    } else {
      v5 = a4;
    }
  }
  return Com_ClientDObjCreate(a1, v6, a3, v5);
}

void __cdecl CG_RegisterGraphics(char const *) { UNIMPLEMENTED(); }

Hunk_AllocXAnimPrecache(int size) { UNIMPLEMENTED(); }
