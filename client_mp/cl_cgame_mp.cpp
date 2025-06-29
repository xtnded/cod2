void __cdecl CL_SetLodOrigin(struct refdef_s const *)
{
  return (*(int (**)(void)) & algn_121C7F8[4])();
}

void __cdecl CL_SetADS(bool ads)
{
  int result; // eax

  result = a1;
  *((_BYTE *)cl + 11) = a1;
  return result;
}

void __cdecl LoadWorld(char const *mapname)
{
  unk_121C6BC(a1, 0);
  Com_UnloadBsp();
}

void __cdecl CL_CapTurnRate(float maxPitchSpeed, float maxYawSpeed)
{
  float *v2;  // edx
  int result; // eax

  v2 = (float *)cl;
  *((float *)cl + 8578) = a1;
  result = LODWORD(a2);
  v2[8579] = a2;
  return result;
}

void __cdecl CL_SetWeaponInfoMemory()
{
  return Com_SetWeaponInfoMemory(2);
}

int __cdecl CL_PickMaterial(float const *const, float const *const, char *,
                            char *, char *, int)
{
  return (*(int (**)(void)) & algn_121C738[68])();
}

void __cdecl CL_TrackStatistics(struct trStatistics_t *)
{
  return (*(int (**)(void)) & algn_121C738[64])();
}

int __cdecl CL_MarkFragments(float const (*const)[3], float const *const,
                             float const (*const)[3], float, int,
                             struct GfxWorldVertex *const, int,
                             struct GfxMarkFragment *const, struct Material *)
{
  UNIMPLEMENTED();
}

void __cdecl CL_ModelBounds(struct GfxBrushModel *model, float *const mins,
                            float *const maxs)
{
  return (*(int (**)(void)) & algn_121C738[60])();
}

void __cdecl CL_DrawSprite(struct Material *material,
                           unsigned char const *const rgbaColor,
                           float const *const pos, float radius,
                           float minScreenRadius, int renderFxFlags)
{
  return (*(int (**)(void)) & algn_121C738[12])();
}

void __cdecl CL_DrawQuadPic(float const (*)[2], float const *const,
                            struct Material *)
{
  UNIMPLEMENTED();
}

void __cdecl CL_GetWorldBounds(float *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CL_DrawStretchPicRotate(float, float, float, float, float, float,
                                     float, float, float, float const *const,
                                     struct Material *)
{
  UNIMPLEMENTED();
}

void __cdecl CL_DrawStretchPicPhysical(float x, float y, float w, float h,
                                       float s1, float t1, float s2, float t2,
                                       float const *const color,
                                       struct Material *material)
{
  return dword_121C734(LODWORD(a1), LODWORD(a2), LODWORD(a3), LODWORD(a4),
                       LODWORD(a5), LODWORD(a6), LODWORD(a7), LODWORD(a8), a9,
                       a10);
}

void __cdecl CL_BlendSavedScreen(int fadeMsec)
{
  return (*(int (**)(void)) & algn_121C738[44])();
}

void __cdecl CL_SaveScreen()
{
  return (*(int (**)(void)) & algn_121C738[40])();
}

void __cdecl CL_SetViewport(int x, int y, int width, int height)
{
  return (*(int (**)(void)) & algn_121C738[52])();
}

void __cdecl CL_IssueDelayedDrawing(int marker)
{
  return unk_121C728();
}

void __cdecl CL_EndDelayedDrawing(int marker)
{
  return unk_121C724();
}

int __cdecl CL_BeginDelayedDrawing()
{
  return unk_121C720();
}

void __cdecl CL_RenderScene(struct refdef_s const *fd)
{
  return unk_121C71C();
}

void __cdecl CL_SwitchFog(int, int)
{
  return unk_121C708();
}

void __cdecl CL_SetFog(int fogvar, float start, float end, unsigned char r,
                       unsigned char g, unsigned char b, float density)
{
  return unk_121C704(a1, LODWORD(a2), LODWORD(a3), a4, a5, a6);
}

void __cdecl CL_AddLightToScene(float const *const org, float radius, float r,
                                float g, float b)
{
  return unk_121C6F4(a1, LODWORD(a2), LODWORD(a3), LODWORD(a4), LODWORD(a5));
}

void __cdecl CL_AddPolyToScene(struct Material *, unsigned short,
                               unsigned short,
                               struct GfxWorldVertex const *const)
{
  return unk_121C6F0(a1, a2, a3);
}

void __cdecl CL_DefaultVertexFrames(int vertCount,
                                    struct GfxWorldVertex *const verts)
{
  return unk_121C6EC();
}

void __cdecl CL_ClearScene()
{
  return unk_121C6E8();
}

struct Material *__cdecl CL_RegisterMaterialNoMip(char const *name,
                                                  int imageTrack)
{
  return dword_121C6B0(a1, 48, a2);
}

struct Material *__cdecl CL_RegisterMaterial(char const *name, int imageTrack)
{
  return dword_121C6B0(a1, 3, a2);
}

void __cdecl CL_SetIgnorePrecacheErrors(int)
{
  UNIMPLEMENTED();
}

void __cdecl CL_FinishLoadingModels()
{
  return unk_121C6C4();
}

struct GfxBrushModel *__cdecl CL_RegisterInlineModel(int modelIndex)
{
  return (*(&algn_121C6A8 + 1))();
}

struct XModel *__cdecl CL_RegisterModel(char const *)
{
  return algn_121C6A8();
}

char const *__cdecl CL_GetConfigString(int index)
{
  return (char *)cl + *((_DWORD *)cl + a1 + 2499) + 18188;
}

char const *__cdecl CL_SurfaceTypeToName(int)
{
  UNIMPLEMENTED();
}

int __cdecl CL_SurfaceTypeFromName(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl CL_GetUserCmdInShellshock(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_SetUserCmdInShellshock(int shocked)
{
  int result; // eax

  result = a1;
  *((_DWORD *)cl + 8576) = a1;
  return result;
}

void __cdecl CL_SetUserCmdValue(int userCmdValue, int holdableValue,
                                float sensitivityScale)
{
  float *v3;  // edx
  int result; // eax

  v3 = (float *)cl;
  *((_DWORD *)cl + 8574) = a1;
  *((_DWORD *)v3 + 8575) = a2;
  result = LODWORD(a3);
  v3[8577] = a3;
  return result;
}

void __cdecl CL_GetCurrentSnapshotNumber(int *snapshotNumber, int *serverTime)
{
  _DWORD *v2;  // ecx
  int *result; // eax

  v2 = cl;
  *a1 = *((_DWORD *)cl + 9);
  result = a2;
  *a2 = v2[8];
  return result;
}

int __cdecl CL_GetCurrentCmdNumber()
{
  return *((_DWORD *)cl + 75031);
}

void __cdecl CL_GetScreenDimensions(int *, int *, float *)
{
  float *result; // eax

  *a1 = dword_14C13C4;
  *a2 = dword_14C13C8;
  result = a3;
  *(_DWORD *)a3 = unk_14C13D4;
  return result;
}

void __cdecl CL_GetGameState(struct gameState_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CL_LookupColor(unsigned char c, float *const color)
{
  unsigned __int8 v2; // al
  int *v3;            // edx
  int v4;             // eax
  int result;         // eax

  v2 = ColorIndex(a1);
    if (v2 <= 7u) {
      v3 = &g_color_table[4 * v2];
      v4 = *v3;
    LABEL_3:
      *(_DWORD *)a2 = v4;
      *((_DWORD *)a2 + 1) = v3[1];
      *((_DWORD *)a2 + 2) = v3[2];
      result = v3[3];
      *((_DWORD *)a2 + 3) = result;
      return result;
    }
    if (a1 == 56) {
      v3 = (int *)((char *)cl + 34348);
      v4 = *((_DWORD *)cl + 8587);
      goto LABEL_3;
    }
    if (a1 == 57) {
      v3 = (int *)((char *)cl + 34364);
      v4 = *((_DWORD *)cl + 8591);
      goto LABEL_3;
    }
  result = 1065353216;
  *a2 = 1.0;
  a2[1] = 1.0;
  a2[2] = 1.0;
  a2[3] = 1.0;
  return result;
}

void __cdecl CL_SetViewAngles(float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CL_SetUserCmdAimValues(float *const kickAngles)
{
  float *v1;  // ebx
  int result; // eax

  v1 = (float *)((char *)cl + 34320);
  *((float *)cl + 8580) = *a1;
  v1[1] = a1[1];
  result = *((_DWORD *)a1 + 2);
  *((_DWORD *)v1 + 2) = result;
  return result;
}

void __cdecl CL_FreeWeaponInfoMemory()
{
  Com_FreeWeaponInfoMemory(2);
}

void __cdecl CL_ArchiveClientState(struct MemoryFile *memFile)
{
  CG_ArchiveState(a1);
  return unk_121C70C(a1);
}

int __cdecl CL_GameCommand()
{
  if (*((_BYTE *)cl + 9))
    return CG_ConsoleCommand();
  else
    return 0;
}

void __cdecl CL_DrawStretchPic(float x, float y, float w, float h,
                               int horzAlign, int vertAlign, float s1, float t1,
                               float s2, float t2, float const *const color,
                               struct Material *material)
{
  CalcScreenPlacement(&a1, &a2, &a3, &a4, a5, a6);
  return dword_121C734(LODWORD(a1), LODWORD(a2), LODWORD(a3), LODWORD(a4),
                       LODWORD(a7), LODWORD(a8), LODWORD(a9), LODWORD(a10), a11,
                       a12);
}

void __cdecl CL_SetFullScreenViewport()
{
  UNIMPLEMENTED();
}

void __cdecl CL_DrawString(int x, int y, char const *pszString, int bShadow,
                           int iCharHeight)
{
  UNIMPLEMENTED();
}

void __cdecl CL_CloseInGameMenu()
{
  int result; // eax

  result = UI_IsFullscreen();
    if (!result) {
      result = UI_GetActiveMenu();
      if (result == 2)
        return UI_CloseFocusedMenu();
    }
  return result;
}

void __cdecl CL_ClosePopup(char const *menu)
{
  int result; // eax

  result = UI_IsFullscreen();
    if (!result) {
      if (!I_stricmp(a1, "UIMENU_SCRIPT_POPUP_NO_MOUSE") &&
          UI_GetActiveMenu() == 9)
        return UI_CloseFocusedMenu();
      result = I_stricmp(a1, "UIMENU_SCRIPT_POPUP");
        if (!result) {
          result = UI_GetActiveMenu();
          if (result == 9)
            return UI_CloseFocusedMenu();
        }
    }
  return result;
}

void __cdecl CL_UpdateColor()
{
  float *v0; // ebx
  char *v1;  // esi

  v0 = (float *)cl;
  v1 = (char *)cl + 34348;
  Dvar_GetUnpackedColorByName("g_TeamColor_Allies", (float *)cl + 8587);
  *((_DWORD *)v1 + 3) = 1065353216;
  v0 += 8591;
  Dvar_GetUnpackedColorByName("g_TeamColor_Axis", v0);
  v0[3] = 1.0;
  return algn_121C7AC(v1, v0);
}

void __cdecl CL_FX_AdjustCamera(struct refdef_s *refdef)
{
  float v1; // [esp+4h] [ebp-14h]

  v1 = unk_121C6E0();
  FX_AdjustCamera(a1, v1);
}

struct snd_alias_t *__cdecl CL_PickSoundAlias(char const *aliasname)
{
  return Com_PickSoundAlias(a1);
}

void __cdecl CL_ShutdownCGame()
{
  UNIMPLEMENTED();
}

void __cdecl CL_CloseAllMenus()
{
    if (!UI_IsFullscreen()) {
      UI_KeyEvent(27, 1);
      UI_KeyEvent(27, 1);
      UI_KeyEvent(27, 1);
    }
}

int __cdecl CL_Popup(char const *menu)
{
  if (*(_DWORD *)clc != 8 || *(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc) ||
      UI_IsFullscreen())
    return 0;
    if (I_stricmp(a1, "UIMENU_WM_QUICKMESSAGE")) {
        if (I_strnicmp(a1, "UIMENU_SCRIPT_POPUP", 19)) {
          return 1;
        }
        else if (I_stricmp(a1, "UIMENU_SCRIPT_POPUP_NO_MOUSE")) {
          return UI_SetActiveMenu(9);
        }
        else {
          return UI_SetActiveMenu(10);
        }
    }
    else {
      UI_SetActiveMenu(8);
      return 1;
    }
}

void __cdecl CL_ConfigstringModified()
{
  const char *v0;     // eax
  _DWORD *v1;         // esi
  const char *v2;     // ebx
  size_t v3;          // esi
  _DWORD *v4;         // edi
  int v5;             // edx
  char v6;            // [esp+8h] [ebp-5EC0h]
  char v7;            // [esp+8h] [ebp-5EC0h]
  char *__s2;         // [esp+10h] [ebp-5EB8h]
  int i;              // [esp+14h] [ebp-5EB4h]
  unsigned int v10;   // [esp+18h] [ebp-5EB0h]
  _DWORD __dst[6055]; // [esp+2Ch] [ebp-5E9Ch] BYREF

  v0 = (const char *)Cmd_Argv(1);
  v10 = atoi(v0);
  if (v10 > 0x7FF)
    Com_Error(1, "\x15configstring > MAX_CONFIGSTRINGS", v6);
  __s2 = (char *)Cmd_Argv(2);
  v1 = cl;
    if (strcmp((const char *)cl + *((_DWORD *)cl + v10 + 2499) + 18188, __s2)) {
      memcpy(__dst, v1 + 2499, 0x5E84u);
      memset(v1 + 2499, 0, 0x5E84u);
      v1[8547] = 1;
        for (i = 0; i != 2048; ++i) {
            while (1) {
              v2 = v10 == i ? __s2 : (char *)&__dst[2048] + __dst[i];
              if (*v2)
                break;
              if (++i == 2048)
                goto LABEL_13;
            }
          v3 = strlen(v2) + 1;
          v4 = cl;
          v5 = *((_DWORD *)cl + 8547);
            if ((int)(v3 + v5) > 16000) {
              Com_Error(1, "\x15MAX_GAMESTATE_CHARS exceeded", v7);
              v5 = v4[8547];
            }
          v4[i + 2499] = v5;
          memcpy((char *)v4 + v5 + 18188, v2, v3);
          v4[8547] += v3;
        }
    LABEL_13:
      if (v10 == 1)
        CL_SystemInfoChanged();
    }
}

int __cdecl CL_GetUserCmd(int cmdNumber, struct usercmd_s *ucmd)
{
  _DWORD *v2; // ebx
  int v3;     // eax
  char *v4;   // eax

  v2 = cl;
  v3 = *((_DWORD *)cl + 75031);
    if (v3 < a1) {
      Com_Error(1, "\x15CL_GetUserCmd: %i >= %i", a1);
      v3 = v2[75031];
    }
  if (a1 <= v3 - 128)
    return 0;
  v4 = (char *)&loc_48650 + (_DWORD)&v2[7 * (a1 & 0x7F)];
  a2->serverTime = *((_DWORD *)v4 + 3);
  a2->buttons = *((_DWORD *)v4 + 4);
  *(_DWORD *)&a2->weapon = *((_DWORD *)v4 + 5);
  a2->angles[0] = *((float *)v4 + 6);
  a2->angles[1] = *((float *)v4 + 7);
  a2->angles[2] = *((float *)v4 + 8);
  *(_DWORD *)&a2->forwardmove = *((_DWORD *)v4 + 9);
  return 1;
}

int __cdecl CL_GetSnapshot(int snapshotNumber, struct snapshot_t *snapshot)
{
  _DWORD *v2;     // ebx
  int v3;         // eax
  _DWORD *v4;     // edi
  signed int v5;  // edx
  snapshot_t *v6; // ebx
  int v7;         // esi
  signed int v8;  // eax
  snapshot_t *v9; // ebx
  int v10;        // esi
  char v12;       // [esp+8h] [ebp-30h]
  int v13;        // [esp+18h] [ebp-20h]
  signed int v14; // [esp+1Ch] [ebp-1Ch]

  v2 = cl;
  if (*((_DWORD *)cl + 9) < a1)
    Com_Error(1, "\x15CL_GetSnapshot: snapshotNumber > cl->snapshot.messageNum",
              v12);
  if (v2[9] - a1 > 31)
    return 0;
  v3 = a1 & 0x1F;
  v4 = &v2[2486 * v3 + 75128];
  if (!*v4 || v2[8564] - v2[2486 * v3 + 77611] > 2047 ||
      v2[8565] - v2[2486 * v3 + 77612] > 2047)
    return 0;
  a2->snapFlags = v2[2486 * v3 + 75129];
  *(_DWORD *)a2->serverCommandSequence = v2[2486 * v3 + 77613];
  a2->ping = v2[2486 * v3 + 75133];
  a2->serverTime = v2[2486 * v3 + 75130];
  memcpy(&a2->ps, &v2[2486 * v3 + 75135], sizeof(a2->ps));
  v13 = v4[2481];
    if (v13 <= 256) {
      v5 = v4[2481];
    }
    else {
      if (*(_BYTE *)(com_statmon + 8))
        StatMon_Warning(4u, 3000, "gfx/2d/warning@snapshotents.jpg");
      else
        Com_DPrintf("CL_GetSnapshot: truncated %i entities to %i\n", v13, 256);
      v13 = 256;
      v5 = 256;
    }
  a2->numEntities = v5;
    if (v5 > 0) {
      v6 = a2;
      v7 = 0;
        do {
          memcpy(v6->entities,
                 (char *)cl + 240 * ((v4[2483] + v7++) & 0x7FF) + 864480,
                 0xF0u);
          v6 = (snapshot_t *)((char *)v6 + 240);
        }
      while (v13 != v7);
    }
  v8 = 64;
  if ((int)v4[2482] < 65)
    v8 = v4[2482];
  v14 = v8;
  a2->numClients = v8;
    if (v8 > 0) {
      v9 = a2;
      v10 = 0;
        do {
          memcpy(v9->clients,
                 (char *)cl + 92 * ((v4[2484] + v10++) & 0x7FF) + 1356000,
                 0x5Cu);
          v9 = (snapshot_t *)((char *)v9 + 92);
        }
      while (v14 != v10);
    }
  return 1;
}

void __cdecl CL_CM_LoadMap(char const *mapname)
{
  UNIMPLEMENTED();
}

void __cdecl CL_AdjustTimeDelta()
{
  _DWORD *v0;      // ebx
  unsigned int v1; // ecx
  int v2;          // esi
  int v3;          // edx
  int v4;          // eax
  _DWORD *v5;      // ebx
  _DWORD *v6;      // eax
  int v7;          // edx

  v0 = cl;
  *((_DWORD *)cl + 2498) = 0;
    if (!*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc)) {
      v1 = v0[8] - v0[2496];
      v2 = v0[8] - dword_1220A78 - v1 - 5;
      v3 = v0[2495];
      v4 = v2 - v3;
        if (v2 - v3 <= 0) {
          v4 = v3 - (v0[8] - dword_1220A78 - v1 - 5);
          if (v4 <= 500)
            goto LABEL_5;
        }
        else {
            if (v1 <= 0x1F4) {
              v4 -= v1;
              if (v4 < 0)
                goto LABEL_15;
            }
            if (v4 <= 500) {
            LABEL_5:
                if (v4 > 100) {
                  if (*(_BYTE *)(cl_showTimeDelta + 8))
                    Com_Printf("<FAST> ");
                  *((_DWORD *)cl + 2495) = (*((_DWORD *)cl + 2495) + v2) >> 1;
                  goto LABEL_9;
                }
            LABEL_15:
                if (*(float *)&com_timescaleValue == 1.0) {
                    if (v0[2497]) {
                      v0[2497] = 0;
                      *((_DWORD *)cl + 2495) -= 2;
                    }
                    else if (v2 <= v3) {
                      if (v2 < v3)
                        v0[2495] = v3 - 1;
                    }
                    else {
                      v0[2495] = v3 + 1;
                    }
                }
            LABEL_9:
                if (*(_BYTE *)(cl_showTimeDelta + 8)) {
                  v5 = cl;
                  Com_Printf("client time: %i, server time: %i\n",
                             *((_DWORD *)cl + 2495) + dword_1220A78,
                             *((_DWORD *)cl + 8));
                  Com_Printf("snapshot delta: %i, time delta: %i\n", v2,
                             v5[2495]);
                }
              return;
            }
        }
      v0[2495] = v2;
      v6 = cl;
      v7 = *((_DWORD *)cl + 8);
      *((_DWORD *)cl + 2493) = v7;
      v6[2492] = v7;
      if (!*(_BYTE *)(cl_showTimeDelta + 8))
        return;
      Com_Printf("<RESET> ");
      goto LABEL_9;
    }
}

void __cdecl CL_SubtitlePrint(char const *pszText, int iDuration,
                              int iLineWidth)
{
  const char *String; // edx
  const char *v5;     // eax

  String = (const char *)SEH_StringEd_GetString(__src);
  if (String)
    return CL_ConsolePrint(PMSG_SUBTITLE, String, a2, a3);
  if (!*(_BYTE *)(loc_warnings + 8))
    return CL_ConsolePrint(PMSG_SUBTITLE, __src, a2, a3);
  if (*(_BYTE *)(loc_warningsAsErrors + 8))
    Com_Error(6, "Could not translate subtitle text: \"%s\"", (char)__src);
  else
    Com_Printf("^3WARNING: Could not translate subtitle text: \"%s\"\n", __src);
  v5 = (const char *)va("^1UNLOCALIZED(^7%s^1)^7", (char)__src);
  return CL_ConsolePrint(PMSG_SUBTITLE, v5, a2, a3);
}

int __cdecl CL_DObjCreateSkelForBones(struct DObj_s const *obj,
                                      int *const partBits, int localClientNum)
{
  int SkelTimeStamp;          // ebx
  unsigned int AllocSkelSize; // eax
  char *v6;                   // eax

  SkelTimeStamp = CL_GetSkelTimeStamp(a3);
  if (DObjSkelExists(a1, SkelTimeStamp))
    return DObjSkelAreBonesUpToDate(a1, a2);
  AllocSkelSize = DObjGetAllocSkelSize(a1);
  v6 = (char *)CL_AllocSkelMemory(a3, AllocSkelSize);
    if (v6) {
      DObjCreateSkel(a1, v6, SkelTimeStamp);
      return 0;
    }
    else {
        if (SkelTimeStamp !=
            CL_DObjCreateSkelForBones(DObj_s const *, int *, int)::warnCount) {
          CL_DObjCreateSkelForBones(DObj_s const *, int *, int)::warnCount =
              SkelTimeStamp;
          Com_Printf(
              "^3WARNING: CL_SKEL_MEMORY_SIZE exceeded - not calculating "
              "skeleton\n");
        }
      return 1;
    }
}

int __cdecl CL_DObjCreateSkelForBone(struct DObj_s *obj, int boneIndex,
                                     int localClientNum)
{
  int SkelTimeStamp;          // ebx
  unsigned int AllocSkelSize; // eax
  char *v6;                   // eax

  SkelTimeStamp = CL_GetSkelTimeStamp(a3);
  if (DObjSkelExists(a1, SkelTimeStamp))
    return DObjSkelIsBoneUpToDate(a1, a2);
  AllocSkelSize = DObjGetAllocSkelSize(a1);
  v6 = (char *)CL_AllocSkelMemory(a3, AllocSkelSize);
    if (v6) {
      DObjCreateSkel(a1, v6, SkelTimeStamp);
      return 0;
    }
    else {
        if (SkelTimeStamp !=
            CL_DObjCreateSkelForBone(DObj_s *, int, int)::warnCount) {
          CL_DObjCreateSkelForBone(DObj_s *, int, int)::warnCount =
              SkelTimeStamp;
          Com_Printf(
              "^3WARNING: CL_SKEL_MEMORY_SIZE exceeded - not calculating "
              "skeleton\n");
        }
      return 1;
    }
}

void __cdecl CL_AddCgameCommand(char const *cmdName)
{
  Cmd_AddCommand(__s1, 0);
}

void __cdecl CL_FirstSnapshot(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_SyncTimes()
{
  _DWORD *v0; // ebx
  _DWORD *v1; // ecx
  int v2;     // edx

  v0 = clc;
    if (*(_DWORD *)clc == 8) {
      v1 = cl;
        if ((*((_BYTE *)cl + 28) & 2) == 0) {
          *(_DWORD *)clc = 8;
          v2 = v1[8];
          v1[2495] = v2 - dword_1220A78;
          v1[2493] = v2;
          v0[66033] = v2;
            if (**(_BYTE **)(cl_activeAction + 8)) {
              Cbuf_AddText(*(const char **)(cl_activeAction + 8));
              Cbuf_AddText("\n");
              Dvar_SetString((dvar_s *)cl_activeAction, (char *)&inData);
            }
        }
    }
}

void __cdecl CL_DObjCreate(struct DObjModel_s *, unsigned short,
                           struct XAnimTree_s *, char *)
{
  UNIMPLEMENTED();
}

int __cdecl CL_GetServerCommand(int serverCommandNumber)
{
  int v1;              // esi
  _DWORD *v2;          // ebx
  int v3;              // eax
  int v4;              // ecx
  char *v5;            // esi
  const gentity_s *v6; // ebx
  int v7;              // edx
  int result;          // eax
  int i;               // ebx
  const char *v10;     // ebx
  const char *v11;     // eax
  const char *v12;     // ebx
  const char *v13;     // esi
  char *v14;           // eax
  char *v15;           // ebx
  char *v16;           // eax
  char *v17;           // eax
  char v18;            // [esp+8h] [ebp-40h]
  char v19;            // [esp+8h] [ebp-40h]

    if (*((_DWORD *)clc + 32847) - 128 < a1) {
      v1 = a1 & 0x7F;
      v2 = clc;
      v3 = a1;
      if (a1 <= *((_DWORD *)clc + 32847))
        goto LABEL_3;
    LABEL_12:
      Com_Error(1, "\x15CL_GetServerCommand: \x14EXE_ERR_NOT_RECEIVED", v18);
      v4 = a1;
      v5 = (char *)&v2[256 * v1 + 32849];
      v2[32848] = a1;
      if (!*(_BYTE *)(cl_showServerCommands + 8))
        goto LABEL_4;
      goto LABEL_13;
    }
  if (*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc))
    return 0;
  Com_Printf("===== CL_GetServerCommand =====\n");
  v1 = a1 & 0x7F;
  Com_Printf("serverCommandNumber: %d\n", v1);
  for (i = 0; i != 128; ++i)
    Com_Printf("cmd %5d: %s\n", i,
               (const char *)clc + 1024 * (i & 0x7F) + 131396);
  Com_Error(1, "\x15CL_GetServerCommand: \x14EXE_ERR_RELIABLE_CYCLED_OUT", v19);
  v2 = clc;
  v3 = a1;
  if (a1 > *((_DWORD *)clc + 32847))
    goto LABEL_12;
LABEL_3:
  v4 = v3;
  v5 = (char *)&v2[256 * v1 + 32849];
  v2[32848] = v3;
  if (!*(_BYTE *)(cl_showServerCommands + 8))
    goto LABEL_4;
LABEL_13:
  Com_DPrintf("serverCommand: %i : %s\n", v4, v5);
LABEL_4:
    while (2) {
      Cmd_TokenizeString(v5);
      v6 = Cmd_Argv(0);
      v7 = Cmd_Argc();
        switch (LOBYTE(v6->s.number)) {
        case 'B':
        case 'n':
          Con_ClearNotify();
          Con_ClearSubtitles();
          memset((char *)cl + 296540, 0, 0xE00u);
          unk_121C72C();
          goto LABEL_5;
        case 'd':
          Cmd_TokenizeString2(v5, 3);
          CL_ConfigstringModified();
          Cmd_TokenizeString2(v5, 3);
          return 1;
        case 'w':
            if (v7 > 1) {
              v14 = (char *)Cmd_Argv(1);
              v15 = SEH_SafeTranslateString(v14);
              v16 = SEH_SafeTranslateString("EXE_SERVERDISCONNECTREASON");
              v17 = UI_ReplaceConversionString(v16, v15);
              Com_Error(2, v17, v18);
            }
            else {
              Com_Error(2, "EXE_SERVER_DISCONNECTED", v18);
            }
          goto LABEL_16;
        case 'x':
        LABEL_16:
          Cmd_TokenizeString2(v5, 3);
          v10 = (const char *)Cmd_Argv(2);
          v11 = (const char *)Cmd_Argv(1);
          Com_sprintf(bigConfigString, 0x2000u, "%c %s %s", 100, v11, v10);
          result = 0;
          break;
        case 'y':
          Cmd_TokenizeString2(v5, 3);
          v12 = (const char *)Cmd_Argv(2);
          if (strlen(v12) + 1 + strlen(bigConfigString) + 1 - 2 > 0x1FFF)
            Com_Error(1, "\x15bcs exceeded BIG_INFO_STRING", v18);
          strcat(bigConfigString, v12);
          result = 0;
          break;
        case 'z':
          Cmd_TokenizeString2(v5, 3);
          v13 = (const char *)Cmd_Argv(2);
          if (strlen(v13) + strlen(bigConfigString) + 1 > 0x1FFF)
            Com_Error(1, "\x15bcs exceeded BIG_INFO_STRING", v18);
          strcat(bigConfigString, v13);
          v5 = bigConfigString;
          continue;
        default:
        LABEL_5:
          result = 1;
          break;
        }
      return result;
    }
}

void __cdecl CL_InitCGame()
{
  int v7;             // edi
  _BYTE *v8;          // esi
  char *v9;           // eax
  char *BspExtension; // eax
  _DWORD *v11;        // ebx
  double v12;         // xmm0_8
  char __dst[88];     // [esp+20h] [ebp-58h] BYREF

  v7 = Sys_Milliseconds();
  Con_Close();
  v8 = cl;
  v9 = (char *)Info_ValueForKey(
      (const char *)cl + *((_DWORD *)cl + 2499) + 18188, "mapname");
  I_strncpyz(__dst, v9, 64);
  BspExtension = GetBspExtension();
  Com_sprintf(v8 + 34192, 0x40u, "maps/mp/%s.%s", __dst, BspExtension);
    if (!*(_BYTE *)(com_sv_running + 8)) {
      Com_InitDObj();
      CL_SetExpectedHunkUsage(v8 + 34192);
    }
  v11 = clc;
  *(_DWORD *)clc = 6;
  v8[10] = 1;
  CG_Init(a1, a2, a3, a4, a5, a6, a7,
          *(_DWORD *)((char *)&loc_20138 + (_DWORD)v11), v11[32848], v11[2]);
  v8[9] = 1;
  *v11 = 7;
  v12 = (double)(Sys_Milliseconds() - v7) / 1000.0;
  Com_Printf("CL_InitCGame: %5.2f seconds\n", v12);
  unk_121C6E4();
  Com_TouchMemory();
  Con_ClearNotify();
  Con_ClearSubtitles();
  CL_UpdateLevelHunkUsage(a1, *(float *)&v12, a3, a4, a5, a6, a7);
}

void __cdecl CL_StartLoading(char const *mapname, char const *gametype)
{
  UNIMPLEMENTED();
}

void __cdecl CL_SetCGameTime()
{
  UNIMPLEMENTED();
}

char const *__cdecl CL_TimeDemoLogBaseName(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_UpdateColorInternal(char const *, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CL_UpdateTimeDemo(void)
{
  UNIMPLEMENTED();
}

CL_SetExpectedHunkUsage(char const *mapname)
{
  UNIMPLEMENTED();
}

CL_Material_Duplicate(Material *mtlCopy, char const *name)
{
  UNIMPLEMENTED();
}

CL_DuplicateFont(Font_s *fontCopy, char const *name)
{
  UNIMPLEMENTED();
}

CL_LoadSoundAliases(char const *loadspec)
{
  UNIMPLEMENTED();
}

CL_UpdateLevelHunkUsage()
{
  UNIMPLEMENTED();
}
