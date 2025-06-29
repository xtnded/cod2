void __cdecl CG_ScoresDown_f()
{
  _DWORD *v0; // ebx
  int v1;     // edx
  int result; // eax

  v0 = cg;
  v1 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
  result = *(_DWORD *)((char *)&loc_2AEFC + (_DWORD)cg) + 2000;
    if (result < v1) {
      *(_DWORD *)((char *)&loc_2AEFC + (_DWORD)cg) = v1;
      CL_AddReliableCommand("score");
      result = CG_ScoreboardDisplayed();
        if (!result) {
          v0[43968] = 0;
          v0[44367] = 0;
          v0[44365] = 1;
        }
    }
    else {
      *((_DWORD *)cg + 44365) = 1;
    }
  return result;
}

void __cdecl CG_ScoresUp_f()
{
  UNIMPLEMENTED();
}

void __cdecl CG_TargetCommand_f()
{
  int v0;      // esi
  int v1;      // eax
  char *v2;    // eax
  char v3[12]; // [esp+1Ch] [ebp-Ch] BYREF

  v0 = CG_CrosshairPlayer();
    if (v0) {
      Cmd_ArgvBuffer(1, v3, 4);
      v1 = atoi(v3);
      v2 = va("gc %i %i", v0, v1);
      Cbuf_AddText(v2);
    }
}

int __cdecl CG_ConsoleCommand()
{
  char *v0;         // edi
  char *v1;         // eax
  int v2;           // esi
  char **v3;        // ebx
  void (*v5)(void); // eax

  if (!*((_DWORD *)cg + 9))
    return 0;
  v0 = CG_Argv(0);
  v1 = commandsList;
  if (!commandsList)
    return 0;
  v2 = 0;
  v3 = &commandsList;
    while (I_stricmp(v0, v1)) {
      ++v2;
      v1 = v3[2];
      v3 += 2;
      if (!v1)
        return 0;
    }
  v5 = (void (*)(void)) * (&off_333BC4 + 2 * v2);
  if (v5)
    v5();
  return 1;
}

void __cdecl CG_InitConsoleCommands()
{
  char *v0;  // eax
  char **v1; // ebx

  v0 = commandsList;
    if (commandsList) {
      v1 = &commandsList;
        do {
          CL_AddCgameCommand(v0);
          v0 = v1[2];
          v1 += 2;
        }
      while (v0);
    }
  CL_AddCgameCommand("kill");
  CL_AddCgameCommand("give");
  CL_AddCgameCommand("take");
  CL_AddCgameCommand("god");
  CL_AddCgameCommand("demigod");
  CL_AddCgameCommand("notarget");
  CL_AddCgameCommand("noclip");
  CL_AddCgameCommand("ufo");
  CL_AddCgameCommand("levelshot");
  CL_AddCgameCommand("setviewpos");
  CL_AddCgameCommand("jumptonode");
  CL_AddCgameCommand("stats");
  CL_AddCgameCommand("say");
  CL_AddCgameCommand("say_team");
  CL_AddCgameCommand("tell");
  CL_AddCgameCommand("team");
  CL_AddCgameCommand("follow");
  CL_AddCgameCommand("callvote");
  CL_AddCgameCommand("vote");
  CL_AddCgameCommand("follownext");
  CL_AddCgameCommand("followprev");
  CL_AddCgameCommand("printentities");
  CL_AddCgameCommand("muteplayer");
  CL_AddCgameCommand("unmuteplayer");
}

void __cdecl CG_TellTarget_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_SizeDown_f(void)
{
  Dvar_SetInt((dvar_s *)cg_viewsize, *(_DWORD *)(cg_viewsize + 8) - 10);
}

void __cdecl CG_SizeUp_f(void)
{
  Dvar_SetInt((dvar_s *)cg_viewsize, *(_DWORD *)(cg_viewsize + 8) + 10);
}

void __cdecl CG_QuickMessage_f(void)
{
  int result; // eax

  result = *((_DWORD *)cg + 9);
    if (result) {
      if (*(char *)(result + 26) < 0)
        return CL_Popup("UIMENU_WM_QUICKMESSAGE");
    }
  return result;
}

void __cdecl CG_ToggleScores_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_PlayRumble_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_TeamVoiceChat_f(void)
{
  int v0;         // eax
  char *v1;       // eax
  const char *v2; // eax
  char v3[72];    // [esp+10h] [ebp-48h] BYREF

    if (Cmd_Argc() == 2) {
      v0 = *((_DWORD *)cg + 9);
        if (v0 && *(_DWORD *)(v0 + 16) != 5 && *(char *)(v0 + 26) >= 0) {
          v2 = UI_SafeTranslateString("CGAME_NOSPECTATORVOICECHAT");
          Com_Printf("%s\n", v2);
        }
        else {
          Cmd_ArgvBuffer(1, v3, 64);
          v1 = va("cmd vsay_team %s\n", v3);
          Cbuf_AddText(v1);
        }
    }
}

void __cdecl CG_VoiceChat_f(void)
{
  int v0;         // eax
  char *v1;       // eax
  const char *v2; // eax
  char v3[72];    // [esp+10h] [ebp-48h] BYREF

    if (Cmd_Argc() == 2) {
      v0 = *((_DWORD *)cg + 9);
        if (v0 && *(_DWORD *)(v0 + 16) != 5 && *(char *)(v0 + 26) >= 0) {
          v2 = UI_SafeTranslateString("CGAME_NOSPECTATORVOICECHAT");
          Com_Printf("%s\n", v2);
        }
        else {
          Cmd_ArgvBuffer(1, v3, 64);
          v1 = va("cmd vsay %s\n", v3);
          Cbuf_AddText(v1);
        }
    }
}

void __cdecl CG_ShellShock_Save_f(void)
{
  char v7[72]; // [esp+10h] [ebp-48h] BYREF

    if (Cmd_Argc() == 2) {
      Cmd_ArgvBuffer(1, v7, 64);
      CG_SaveShellShockDvars(a1, a2, a3, a4, a5, a6, a7, v7);
    }
    else {
      Com_Printf("USAGE: cg_shellshock_save <name>\n");
    }
}

void __cdecl CG_Viewpos_f(void)
{
  Com_Printf("(%i %i %i) : %i\n", (int)*((float *)cg + 41314),
             (int)*(float *)((char *)&loc_2858C + (_DWORD)cg),
             (int)*((float *)cg + 41316), (int)*((float *)cg + 41331));
}

void __cdecl CG_ShellShock_Load_f(void)
{
  char v0[72]; // [esp+10h] [ebp-48h] BYREF

    if (Cmd_Argc() == 2) {
      Cmd_ArgvBuffer(1, v0, 64);
      CG_LoadShellShockDvars(v0);
    }
    else {
      Com_Printf("USAGE: cg_shellshock_load <name>\n");
    }
}

void __cdecl CG_ShellShock_f(void)
{
  int v0;       // eax
  _DWORD *v1;   // ebx
  float v2;     // xmm0_4
  float v3;     // [esp+14h] [ebp-114h]
  double v4;    // [esp+18h] [ebp-110h]
  char v5[264]; // [esp+20h] [ebp-108h] BYREF

  v0 = Cmd_Argc();
  if (v0 == 2)
    goto LABEL_4;
    if (v0 != 3) {
      Com_Printf("USAGE: cg_shellshock <duration> <filename?>\n");
      return;
    }
  Cmd_ArgvBuffer(2, v5, 256);
    if (CG_LoadShellShockDvars(v5)) {
    LABEL_4:
      Cmd_ArgvBuffer(1, v5, 256);
      v4 = atof(v5);
      CG_SetShellShockParmsFromDvars(
          (shellshock_parms_t *)((char *)cgs + 26820));
      v1 = cg;
      *((_DWORD *)cg + 45886) = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
      v2 = v4;
      v3 = floorf((float)(v2 * 1000.0) + 0.5);
      v1[45887] = (int)v3;
    }
}
