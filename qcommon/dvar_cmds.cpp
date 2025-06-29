void __cdecl Dvar_ForEach(void(__cdecl *)(char const *))
{
  UNIMPLEMENTED();
}

void __cdecl Dvar_WriteDefaults(int f)
{
  size_t result;    // eax
  const dvar_s *v2; // ebx
  char *v3;         // eax

  result = (size_t)&sortedDvars;
  v2 = (const dvar_s *)sortedDvars;
    if (sortedDvars) {
        do {
            while (1) {
              result = I_stricmp(*(char **)v2->name, "cl_cdkey");
                if (result) {
                  result = (unsigned __int16)v2->flags;
                  if ((result & 0x40C0) == 0)
                    break;
                }
              v2 = (const dvar_s *)v2->next;
              if (!v2)
                return result;
            }
          v3 = Dvar_DisplayableResetValue(v2);
          result =
              FS_Printf(a1, "set %s \"%s\"\n", *(const char **)v2->name, v3);
          v2 = (const dvar_s *)v2->next;
        }
      while (v2);
    }
  return result;
}

void __cdecl Dvar_WriteVariables(int f)
{
  int *result;     // eax
  const char **v2; // ebx
  char *v3;        // eax

  result = &sortedDvars;
  v2 = (const char **)sortedDvars;
    if (sortedDvars) {
        do {
            while (1) {
              result = (int *)I_stricmp((char *)*v2, "cl_cdkey");
                if (result) {
                  if (((_BYTE)v2[1] & 1) != 0)
                    break;
                }
              v2 = (const char **)v2[7];
              if (!v2)
                return result;
            }
          v3 = Dvar_DisplayableLatchedValue((const dvar_s *)v2);
          result = (int *)FS_Printf(a1, "seta %s \"%s\"\n", *v2, v3);
          v2 = (const char **)v2[7];
        }
      while (v2);
    }
  return result;
}

int __cdecl Dvar_Command()
{
  char *v0;          // eax
  const dvar_s *Var; // esi
  dvar_s *v2;        // eax
  char *v4;          // ebx
  char *v5;          // eax
  char *v6;          // eax
  DvarValue v7;      // [esp+10h] [ebp-1008h] BYREF

  v0 = (char *)Cmd_Argv(0);
  Var = (const dvar_s *)Dvar_FindVar(v0);
  if (!Var)
    return 0;
    if (Cmd_Argc() == 1) {
      v4 = Dvar_DisplayableResetValue(Var);
      v5 = Dvar_DisplayableValue(Var);
      Com_Printf("\"%s\" is: \"%s^7\" default: \"%s^7\"\n",
                 *(const char **)Var->name, v5, v4);
        if (Dvar_HasLatchedValue(Var)) {
          v6 = Dvar_DisplayableLatchedValue(Var);
          Com_Printf("latched: \"%s\"\n", v6);
        }
      Dvar_PrintDomain(Var->type, Var->domain);
      return 1;
    }
    else {
      Dvar_GetCombinedString((char *)&v7, 1);
      v2 = (dvar_s *)Cmd_Argv(0);
      Dvar_SetCommand(v2, (DvarValue)&v7);
      return 1;
    }
}

char *__cdecl Dvar_InfoString(int bit)
{
  const dvar_s *v1;                   // ebx
  char *v2;                           // eax
  const char *UsernameForLocalClient; // eax

  info1 = 0;
  v1 = (const dvar_s *)sortedDvars;
    if (sortedDvars) {
        do {
            while ((v1->flags & a1) == 0) {
              v1 = (const dvar_s *)v1->next;
              if (!v1)
                goto LABEL_6;
            }
          v2 = Dvar_DisplayableValue(v1);
          Info_SetValueForKey(&info1, *(char **)v1->name, v2);
          v1 = (const dvar_s *)v1->next;
        }
      while (v1);
    }
LABEL_6:
    if ((a1 & 2) != 0) {
      UsernameForLocalClient = (const char *)CL_GetUsernameForLocalClient();
      Info_SetValueForKey(&info1, "name", UsernameForLocalClient);
    }
  return &info1;
}

void __cdecl SV_SetConfig(int start, int max, int bit)
{
  UNIMPLEMENTED();
}

void __cdecl Com_DvarDump(enum print_msg_type_t type)
{
  const dvar_s *v1; // ebx
  int v2;           // edi
  char *v3;         // esi
  char *v4;         // eax
  char *v5;         // esi
  char *v6;         // eax
  char *v7;         // eax
  char *v8;         // eax
  char *v9;         // [esp+2Ch] [ebp-201Ch]
  char __str[8216]; // [esp+30h] [ebp-2018h] BYREF

  if (Cmd_Argc() <= 1)
    v9 = 0;
  else
    v9 = (char *)Cmd_Argv(1);
    if (a1 || com_logfile && *(_DWORD *)(com_logfile + 8)) {
      Com_PrintMessage(a1, "=============================== DVAR DUMP "
                           "========================================\n");
      v1 = (const dvar_s *)sortedDvars;
        if (sortedDvars) {
          v2 = 0;
            if (v9) {
                do {
                    if ((unsigned __int8)Com_Filter(v9, *(char **)v1->name,
                                                    0)) {
                        if (Dvar_HasLatchedValue(v1)) {
                          v5 = Dvar_DisplayableLatchedValue(v1);
                          v6 = Dvar_DisplayableValue(v1);
                          Com_sprintf(__str, 0x2000u,
                                      "      %s \"%s\" -- latched \"%s\"\n",
                                      *(const char **)v1->name, v6, v5);
                        }
                        else {
                          v8 = Dvar_DisplayableValue(v1);
                          Com_sprintf(__str, 0x2000u, "      %s \"%s\"\n",
                                      *(const char **)v1->name, v8);
                        }
                      Com_PrintMessage(a1, __str);
                    }
                  v1 = (const dvar_s *)v1->next;
                  ++v2;
                }
              while (v1);
            }
            else {
                do {
                    if (Dvar_HasLatchedValue(v1)) {
                      v3 = Dvar_DisplayableLatchedValue(v1);
                      v4 = Dvar_DisplayableValue(v1);
                      Com_sprintf(__str, 0x2000u,
                                  "      %s \"%s\" -- latched \"%s\"\n",
                                  *(const char **)v1->name, v4, v3);
                    }
                    else {
                      v7 = Dvar_DisplayableValue(v1);
                      Com_sprintf(__str, 0x2000u, "      %s \"%s\"\n",
                                  *(const char **)v1->name, v7);
                    }
                  Com_PrintMessage(a1, __str);
                  v1 = (const dvar_s *)v1->next;
                  ++v2;
                }
              while (v1);
            }
        }
        else {
          v2 = 0;
        }
      Com_sprintf(__str, 0x2000u, "\n%i total dvars\n%i dvar indexes\n", v2,
                  dvarCount);
      Com_PrintMessage(a1, __str);
      Com_PrintMessage(a1, "=============================== END DVAR DUMP "
                           "=====================================\n");
    }
}

char *__cdecl Dvar_InfoString_Big(int bit)
{
  const dvar_s *v1; // ebx
  char *v2;         // eax

  info2_0 = 0;
  v1 = (const dvar_s *)sortedDvars;
    if (sortedDvars) {
        do {
            while ((a1 & v1->flags) == 0) {
              v1 = (const dvar_s *)v1->next;
              if (!v1)
                return &info2_0;
            }
          v2 = Dvar_DisplayableValue(v1);
          Info_SetValueForKey_Big(&info2_0, *(char **)v1->name, v2);
          v1 = (const dvar_s *)v1->next;
        }
      while (v1);
    }
  return &info2_0;
}

void __cdecl Dvar_Dump_f()
{
  Com_DvarDump(PMSG_CONSOLE);
}

void __cdecl Dvar_List_f()
{
  const char *v0;  // esi
  const char **v1; // ebx
  char *v2;        // eax

  if (Cmd_Argc() <= 1)
    v0 = 0;
  else
    v0 = (const char *)Cmd_Argv(1);
  v1 = (const char **)sortedDvars;
    if (sortedDvars) {
        do {
          if (v0 && !(unsigned __int8)Com_Filter(v0, (char *)*v1, 0))
            goto LABEL_13;
            if (((_WORD)v1[1] & 0x404) != 0) {
              Com_Printf("S");
              if (((_BYTE)v1[1] & 2) != 0)
                goto LABEL_6;
            }
            else {
              Com_Printf(" ");
                if (((_BYTE)v1[1] & 2) != 0) {
                LABEL_6:
                  Com_Printf("U");
                  if (((_BYTE)v1[1] & 0x40) != 0)
                    goto LABEL_7;
                  goto LABEL_19;
                }
            }
          Com_Printf(" ");
            if (((_BYTE)v1[1] & 0x40) != 0) {
            LABEL_7:
              Com_Printf("R");
              if (((_BYTE)v1[1] & 0x10) != 0)
                goto LABEL_8;
              goto LABEL_20;
            }
        LABEL_19:
          Com_Printf(" ");
            if (((_BYTE)v1[1] & 0x10) != 0) {
            LABEL_8:
              Com_Printf("I");
              if (((_BYTE)v1[1] & 1) != 0)
                goto LABEL_9;
              goto LABEL_21;
            }
        LABEL_20:
          Com_Printf(" ");
            if (((_BYTE)v1[1] & 1) != 0) {
            LABEL_9:
              Com_Printf("A");
              if (((_BYTE)v1[1] & 0x20) != 0)
                goto LABEL_10;
              goto LABEL_22;
            }
        LABEL_21:
          Com_Printf(" ");
            if (((_BYTE)v1[1] & 0x20) != 0) {
            LABEL_10:
              Com_Printf("L");
              if (*((char *)v1 + 4) >= 0)
                goto LABEL_23;
              goto LABEL_11;
            }
        LABEL_22:
          Com_Printf(" ");
            if (*((char *)v1 + 4) >= 0) {
            LABEL_23:
              Com_Printf(" ");
              goto LABEL_12;
            }
        LABEL_11:
          Com_Printf("C");
        LABEL_12:
          v2 = Dvar_DisplayableValue((const dvar_s *)v1);
          Com_Printf(" %s \"%s\"\n", *v1, v2);
        LABEL_13:
          v1 = (const char **)v1[7];
        }
      while (v1);
    }
  Com_Printf("\n%i total dvars\n", dvarCount);
}

void __cdecl Dvar_Reset_f()
{
  char *v0;    // eax
  dvar_s *Var; // eax

    if (Cmd_Argc() == 2) {
      v0 = (char *)Cmd_Argv(1);
      Var = (dvar_s *)Dvar_FindVar(v0);
      if (Var)
        Dvar_Reset(Var, DVAR_SOURCE_EXTERNAL);
    }
    else {
      Com_Printf("USAGE: reset <variable>\n");
    }
}

void __cdecl Dvar_SetFromDvar_f()
{
  char *v0;          // eax
  const dvar_s *Var; // eax
  char *v2;          // ebx
  dvar_s *v3;        // eax
  const char *v4;    // eax

    if (Cmd_Argc() == 3) {
      v0 = (char *)Cmd_Argv(2);
      Var = (const dvar_s *)Dvar_FindVar(v0);
        if (Var) {
          v2 = Dvar_DisplayableValue(Var);
          v3 = (dvar_s *)Cmd_Argv(1);
          Dvar_SetCommand(v3, (DvarValue)v2);
        }
        else {
          v4 = (const char *)Cmd_Argv(2);
          Com_Printf("dvar '%s' doesn't exist\n", v4);
        }
    }
    else {
      Com_Printf("USAGE: setfromdvar <dest_dvar> <source_dvar>\n");
    }
}

void __cdecl Dvar_Set_f()
{
  char *v0;       // eax
  dvar_s *v1;     // eax
  const char *v2; // eax
  DvarValue v3;   // [esp+10h] [ebp-1008h] BYREF

    if (Cmd_Argc() > 2) {
      v0 = (char *)Cmd_Argv(1);
        if ((unsigned __int8)Dvar_IsValidName(v0)) {
          Dvar_GetCombinedString((char *)&v3, 2);
          v1 = (dvar_s *)Cmd_Argv(1);
          Dvar_SetCommand(v1, (DvarValue)&v3);
        }
        else {
          v2 = (const char *)Cmd_Argv(1);
          Com_Printf("invalid variable name: %s\n", v2);
        }
    }
    else {
      Com_Printf("USAGE: set <variable> <value>\n");
    }
}

void __cdecl Dvar_SetA_f()
{
  char *v0;          // eax
  const dvar_s *Var; // eax

    if (Cmd_Argc() > 2) {
      Dvar_Set_f();
      v0 = (char *)Cmd_Argv(1);
      Var = (const dvar_s *)Dvar_FindVar(v0);
      if (Var)
        Dvar_AddFlags(Var, 1);
    }
    else {
      Com_Printf("USAGE: seta <variable> <value>\n");
    }
}

void __cdecl Dvar_SetS_f()
{
  char *v0;          // eax
  const dvar_s *Var; // eax

    if (Cmd_Argc() > 2) {
      Dvar_Set_f();
      v0 = (char *)Cmd_Argv(1);
      Var = (const dvar_s *)Dvar_FindVar(v0);
      if (Var)
        Dvar_AddFlags(Var, 4);
    }
    else {
      Com_Printf("USAGE: sets <variable> <value>\n");
    }
}

void __cdecl Dvar_SetU_f()
{
  char *v0;          // eax
  const dvar_s *Var; // eax

    if (Cmd_Argc() > 2) {
      Dvar_Set_f();
      v0 = (char *)Cmd_Argv(1);
      Var = (const dvar_s *)Dvar_FindVar(v0);
      if (Var)
        Dvar_AddFlags(Var, 2);
    }
    else {
      Com_Printf("USAGE: setu <variable> <value>\n");
    }
}

void __cdecl Dvar_TogglePrint_f()
{
  char *v0;          // ebx
  const dvar_s *Var; // eax
  char *v2;          // eax

    if ((unsigned __int8)Dvar_ToggleInternal()) {
      v0 = (char *)Cmd_Argv(1);
      Var = (const dvar_s *)Dvar_FindVar(v0);
      v2 = Dvar_DisplayableValue(Var);
      Com_Printf("%s toggled to %s\n", v0, v2);
    }
}

void __cdecl Dvar_Toggle_f()
{
  return Dvar_ToggleInternal();
}

void Dvar_AddCommands()
{
  Cmd_AddCommand("toggle", Dvar_Toggle_f);
  Cmd_AddCommand("togglep", Dvar_TogglePrint_f);
  Cmd_AddCommand("set", Dvar_Set_f);
  Cmd_AddCommand("sets", Dvar_SetS_f);
  Cmd_AddCommand("seta", Dvar_SetA_f);
  Cmd_AddCommand("setfromdvar", Dvar_SetFromDvar_f);
  Cmd_AddCommand("reset", Dvar_Reset_f);
  Cmd_AddCommand("dvarlist", Dvar_List_f);
  Cmd_AddCommand("dvardump", Dvar_Dump_f);
  Cmd_AddCommand("dvar_bool", Dvar_RegisterBool_f);
  Cmd_AddCommand("dvar_int", Dvar_RegisterInt_f);
  Cmd_AddCommand("dvar_float", Dvar_RegisterFloat_f);
  Cmd_AddCommand("setu", Dvar_SetU_f);
}

int marker_dvar_cmds;

void __cdecl Dvar_GetCombinedString(char *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl Dvar_RegisterFloat_f(void)
{
  const char *v0; // eax
  char *v1;       // ebx
  const char *v2; // eax
  DvarValue v3;   // xmm0_4
  const char *v4; // eax
  float v5;       // xmm0_4
  const char *v6; // eax
  float v7;       // xmm0_4
  int Var;        // eax
  char v9;        // dl
  DvarValue v10;  // [esp+44h] [ebp-14h]
  float v11;      // [esp+48h] [ebp-10h]

    if (Cmd_Argc() != 5) {
      v0 = (const char *)Cmd_Argv(0);
      Com_Printf("USAGE: %s <name> <default> <min> <max>\n", v0);
      return;
    }
  v1 = (char *)Cmd_Argv(1);
  v2 = (const char *)Cmd_Argv(2);
  *(float *)&v3.integer = atof(v2);
  v10 = v3;
  v4 = (const char *)Cmd_Argv(3);
  v5 = atof(v4);
  v11 = v5;
  v6 = (const char *)Cmd_Argv(4);
  v7 = atof(v6);
    if (v11 > v7) {
      Com_Printf("dvar %s: min %g should not be greater than max %g\n", v1, v11,
                 v7);
      return;
    }
  Var = Dvar_FindVar(v1);
  if (!Var)
    goto LABEL_11;
  v9 = *(_BYTE *)(Var + 6);
    if (v9 == 7) {
      if ((*(_BYTE *)(Var + 5) & 0x40) == 0)
        goto LABEL_8;
    LABEL_11:
      Dvar_RegisterFloat(v1, v10, v11, v7, 0x4000u);
      return;
    }
  if (v9 != 1)
  LABEL_8:
    Com_Printf("dvar '%s' is not an integer dvar\n", *(const char **)Var);
}

void __cdecl Dvar_RegisterInt_f(void)
{
  const char *v0; // eax
  char *v1;       // edi
  const char *v2; // eax
  const char *v3; // eax
  int v4;         // esi
  const char *v5; // eax
  int v6;         // eax
  int v7;         // ebx
  int Var;        // eax
  int v9;         // edx
  char v10;       // al
  int v11;        // [esp+2Ch] [ebp-1Ch]

    if (Cmd_Argc() == 5) {
      v1 = (char *)Cmd_Argv(1);
      v2 = (const char *)Cmd_Argv(2);
      v11 = atoi(v2);
      v3 = (const char *)Cmd_Argv(3);
      v4 = atoi(v3);
      v5 = (const char *)Cmd_Argv(4);
      v6 = atoi(v5);
      v7 = v6;
        if (v4 > v6) {
          Com_Printf("dvar %s: min %i should not be greater than max %i\n", v1,
                     v4, v6);
        }
        else {
          Var = Dvar_FindVar(v1);
          v9 = Var;
            if (!Var || (v10 = *(_BYTE *)(Var + 6), v10 == 7) &&
                            (*(_BYTE *)(v9 + 5) & 0x40) != 0) {
              Dvar_RegisterInt(v1, v11, v4, v7, 0x4000u);
            }
            else if ((unsigned __int8)(v10 - 5) > 1u) {
              Com_Printf("dvar '%s' is not an integer dvar\n",
                         *(const char **)v9);
            }
        }
    }
    else {
      v0 = (const char *)Cmd_Argv(0);
      Com_Printf("USAGE: %s <name> <default> <min> <max>\n", v0);
    }
}

void __cdecl Dvar_RegisterBool_f(void)
{
  const char *v0;     // eax
  char *v1;           // ebx
  const char *v2;     // eax
  unsigned __int8 v3; // si
  int Var;            // eax
  char v5;            // dl

    if (Cmd_Argc() != 3) {
      v0 = (const char *)Cmd_Argv(0);
      Com_Printf("USAGE: %s <name> <default>\n", v0);
      return;
    }
  v1 = (char *)Cmd_Argv(1);
  v2 = (const char *)Cmd_Argv(2);
  v3 = atoi(v2) != 0;
  Var = Dvar_FindVar(v1);
  if (!Var)
    goto LABEL_9;
  v5 = *(_BYTE *)(Var + 6);
    if (v5 == 7) {
      if ((*(_BYTE *)(Var + 5) & 0x40) == 0)
        goto LABEL_7;
    LABEL_9:
      Dvar_RegisterBool(v1, v3, 0x4000u);
      return;
    }
  if (v5)
  LABEL_7:
    Com_Printf("dvar '%s' is not a boolean dvar\n", *(const char **)Var);
}

bool __cdecl Dvar_ToggleSimple(struct dvar_s const *)
{
  UNIMPLEMENTED();
}

bool __cdecl Dvar_ToggleInternal(void)
{
  const char **Var;     // edi
  int i;                // ebx
  int v2;               // esi
  char *v3;             // eax
  const char *v4;       // ebx
  const gentity_s *v5;  // eax
  const gentity_s *v6;  // eax
  int result;           // eax
  const char *v8;       // eax
  char *v9;             // eax
  DvarValue v10;        // ebx
  float v11;            // xmm1_4
  int v12;              // eax
  int v13;              // edx
  const gentity_s *v14; // eax
  dvar_s *v15;          // [esp+18h] [ebp-20h]
  const char *v16;      // [esp+1Ch] [ebp-1Ch]

    if (Cmd_Argc() <= 1) {
      v8 = (const char *)Cmd_Argv(0);
      Com_Printf("USAGE: %s <variable> <optional value sequence>\n", v8);
      return 0;
    }
    else {
      v15 = (dvar_s *)Cmd_Argv(1);
      Var = (const char **)Dvar_FindVar(v15->name);
        if (Var) {
            if (Cmd_Argc() == 2) {
                switch (*((_BYTE *)Var + 6)) {
                case 0:
                  Dvar_SetBoolFromSource((dvar_s *)Var,
                                         *((_BYTE *)Var + 8) == 0,
                                         DVAR_SOURCE_EXTERNAL);
                  result = 1;
                  break;
                case 1:
                  v11 = *((float *)Var + 5);
                    if (v11 > 0.0 || *((float *)Var + 6) < 1.0) {
                      if (v11 == *((float *)Var + 2))
                        Dvar_SetFloatFromSource((dvar_s *)Var,
                                                *((float *)Var + 6),
                                                DVAR_SOURCE_EXTERNAL);
                      else
                        Dvar_SetFloatFromSource((dvar_s *)Var, v11,
                                                DVAR_SOURCE_EXTERNAL);
                      result = 1;
                    }
                    else {
                      if (*((float *)Var + 2) == 0.0)
                        Dvar_SetFloatFromSource((dvar_s *)Var, 1.0,
                                                DVAR_SOURCE_EXTERNAL);
                      else
                        Dvar_SetFloatFromSource((dvar_s *)Var, 0.0,
                                                DVAR_SOURCE_EXTERNAL);
                      result = 1;
                    }
                  break;
                case 2:
                case 3:
                case 4:
                case 7:
                case 8:
                  Com_Printf("'toggle' with no arguments makes no sense for "
                             "dvar '%s'\n",
                             *Var);
                  goto LABEL_14;
                case 5:
                  v12 = (int)Var[5];
                    if (v12 > 0 || (int)Var[6] <= 0) {
                      if ((const char *)v12 == Var[2])
                        Dvar_SetIntFromSource((dvar_s *)Var, (int)Var[6],
                                              DVAR_SOURCE_EXTERNAL);
                      else
                        Dvar_SetIntFromSource((dvar_s *)Var, v12,
                                              DVAR_SOURCE_EXTERNAL);
                      result = 1;
                    }
                    else {
                      if (Var[2])
                        Dvar_SetIntFromSource((dvar_s *)Var, 0,
                                              DVAR_SOURCE_EXTERNAL);
                      else
                        Dvar_SetIntFromSource((dvar_s *)Var, 1,
                                              DVAR_SOURCE_EXTERNAL);
                      result = 1;
                    }
                  break;
                case 6:
                  v13 = (int)Var[5];
                  if (v13)
                    Dvar_SetIntFromSource((dvar_s *)Var,
                                          (int)(Var[2] + 1) % v13,
                                          DVAR_SOURCE_EXTERNAL);
                  result = 1;
                  break;
                default:
                LABEL_14:
                  result = 0;
                  break;
                }
            }
            else {
              v16 = Dvar_DisplayableValue((const dvar_s *)Var);
                for (i = 2;; i = v2) {
                  v2 = i + 1;
                  if (Cmd_Argc() <= i + 1)
                    break;
                  v3 = (char *)Cmd_Argv(i);
                  v4 = v3;
                    if (*((_BYTE *)Var + 6) == 6) {
                      v5 =
                          Dvar_IndexStringToEnumString((const dvar_s *)Var, v3);
                      if (LOBYTE(v5->s.number))
                        v4 = (const char *)v5;
                        if (!stricmp(v16, v4)) {
                        LABEL_12:
                          v6 = Cmd_Argv(v2);
                          Dvar_SetCommand(v15, (DvarValue)v6);
                          return 1;
                        }
                    }
                    else if (!stricmp(v16, v3)) {
                      goto LABEL_12;
                    }
                }
              v9 = (char *)Cmd_Argv(2);
              v10.integer = (int32_t)v9;
                if (*((_BYTE *)Var + 6) == 6) {
                  v14 = Dvar_IndexStringToEnumString((const dvar_s *)Var, v9);
                  if (LOBYTE(v14->s.number))
                    v10.integer = (int32_t)v14;
                }
              Dvar_SetCommand(v15, v10);
              return 1;
            }
        }
        else {
          Com_Printf("toggle failed: dvar '%s' not found.\n", v15->name);
          return 0;
        }
    }
  return result;
}
