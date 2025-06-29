void (__cdecl*__cdecl Player_GetMethod pName))(struct scr_entref_t)
{
  UNIMPLEMENTED();
}

void __cdecl BodyEnd(struct gentity_s *ent) {
  gentity_s *result; // eax

  result = a1;
  a1->s.eFlags &= ~0x80000u;
  a1->r.contents = 0x4000000;
  a1->r.svFlags = 0;
  return result;
}

void __cdecl PlayerCmd_pingPlayer(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_takeAllWeapons(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_isOnGround(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_playerADS(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_meleeButtonPressed(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_attackButtonPressed(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_useButtonPressed(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_hasWeapon(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_getCurrentOffhand(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_getCurrentWeapon(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_getFractionMaxAmmo(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_getFractionStartAmmo(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_giveMaxAmmo(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_giveStartAmmo(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_switchToOffhand(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_switchToWeapon(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_takeWeapon(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_giveWeapon(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

int __cdecl ClientPlaying(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_EnableWeapon(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_DisableWeapon(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_FreezeControls(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_setEnterTime(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_setAngles(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_CloseInGameMenu(struct scr_entref_t) {
  int entnum; // ebx
  char *v9;   // eax
  char *v10;  // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    entnum = a8.entnum;
  } else {
    entnum = a8.entnum;
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v10 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
    }
  }
  v9 = va("%c", 75);
  SV_GameSendServerCommand(entnum, SV_CMD_RELIABLE, v9);
}

void __cdecl PlayerCmd_CloseMenu(struct scr_entref_t) {
  int entnum; // ebx
  char *v9;   // eax
  char *v10;  // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    entnum = a8.entnum;
  } else {
    entnum = a8.entnum;
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v10 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
    }
  }
  v9 = va("%c", 117);
  SV_GameSendServerCommand(entnum, SV_CMD_RELIABLE, v9);
}

void __cdecl PlayerCmd_showScoreboard(struct scr_entref_t) {
  gentity_s *v8; // ebx
  char *v9;      // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    Cmd_Score_f(0);
  } else {
    v8 = &g_entities + a8.entnum;
    if (v8->client) {
      Cmd_Score_f(&g_entities + a8.entnum);
    } else {
      v9 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v9);
      Cmd_Score_f(v8);
    }
  }
}

void __cdecl PlayerCmd_AllowSpectateTeam(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_DeactivateChannelVolumes(struct scr_entref_t) {
  int NumParam;                // eax
  double v9;                   // xmm0_8
  unsigned __int16 floatValue; // ax
  int v11;                     // eax
  char *v12;                   // eax
  char *v13;                   // eax
  double v14;                  // [esp+10h] [ebp-28h]
  double v15;                  // [esp+18h] [ebp-20h]
  double v16;                  // [esp+20h] [ebp-18h]
  double v17;                  // [esp+28h] [ebp-10h]

  if (!a8.classnum) {
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v13 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v13);
    }
    NumParam = Scr_GetNumParam();
    if (NumParam != 1)
      goto LABEL_5;
  LABEL_8:
    LODWORD(v9) = 0;
    v17 = 0.0;
    goto LABEL_9;
  }
  Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
  NumParam = Scr_GetNumParam();
  if (NumParam == 1)
    goto LABEL_8;
LABEL_5:
  if (NumParam != 2) {
    Scr_Error(
        "USAGE: player deactivatechannelvolumes(\"priority\", fadetime = 0);\n"
        "Valid priorities are \"snd_channelvolprio_holdbreath\", "
        "\"snd_channelvolprio_pain\", or \"snd_channelvolprio_shell"
        "shock\", fadetime is the time spent fading to the next lowest active "
        "reverb priority level in seconds\n");
    return;
  }
  *((float *)&v16 + 1) = Scr_GetFloat(1u);
  v9 = *((float *)&v16 + 1);
  v17 = *((float *)&v16 + 1);
LABEL_9:
  floatValue =
      (unsigned __int16)Scr_GetConstString(*(float *)&v9, 0).floatValue;
  if (floatValue != word_195B106) {
    if (floatValue == word_195B108) {
      v11 = 2;
      goto LABEL_14;
    }
    if (floatValue == word_195B10A) {
      v11 = 3;
      goto LABEL_14;
    }
    Scr_Error(
        "priority must be 'snd_channelvolprio_holdbreath', "
        "'snd_channelvolprio_pain', or 'snd_channelvolprio_shellshock'\n");
  }
  v11 = 1;
LABEL_14:
  LODWORD(v14) = HIDWORD(v17);
  v12 = va("%c %i \"%s\" %g %g %g", 70, v11, (const char *)LODWORD(v17), v14,
           v15, v16);
  SV_GameSendServerCommand(a8.entnum, SV_CMD_RELIABLE, v12);
}

void __cdecl PlayerCmd_DeactivateReverb(struct scr_entref_t) {
  int NumParam;                // eax
  double v9;                   // xmm0_8
  unsigned __int16 floatValue; // ax
  int v11;                     // eax
  char *v12;                   // eax
  char *v13;                   // eax
  double v14;                  // [esp+10h] [ebp-28h]
  double v15;                  // [esp+18h] [ebp-20h]
  double v16;                  // [esp+20h] [ebp-18h]
  double v17;                  // [esp+28h] [ebp-10h]

  if (!a8.classnum) {
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v13 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v13);
    }
    NumParam = Scr_GetNumParam();
    if (NumParam != 1)
      goto LABEL_5;
  LABEL_8:
    LODWORD(v9) = 0;
    v17 = 0.0;
    goto LABEL_9;
  }
  Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
  NumParam = Scr_GetNumParam();
  if (NumParam == 1)
    goto LABEL_8;
LABEL_5:
  if (NumParam != 2) {
    Scr_Error(
        "USAGE: player deactivateReverb(\"priority\", fadetime = 0);\n"
        "Valid priorities are \"snd_enveffectsprio_level\" or "
        "\"snd_enveffectsprio_shellshock\", fadetime is the time spent"
        " fading to the next lowest active reverb priority level in seconds\n");
    return;
  }
  *((float *)&v16 + 1) = Scr_GetFloat(1u);
  v9 = *((float *)&v16 + 1);
  v17 = *((float *)&v16 + 1);
LABEL_9:
  floatValue =
      (unsigned __int16)Scr_GetConstString(*(float *)&v9, 0).floatValue;
  if (floatValue != word_195B102) {
    if (floatValue == word_195B104) {
      v11 = 2;
      goto LABEL_13;
    }
    Scr_Error("priority must be 'snd_enveffectsprio_level' or "
              "'snd_enveffectsprio_shellshock'\n");
  }
  v11 = 1;
LABEL_13:
  LODWORD(v14) = HIDWORD(v17);
  v12 = va("%c %i \"%s\" %g %g %g", 68, v11, (const char *)LODWORD(v17), v14,
           v15, v16);
  SV_GameSendServerCommand(a8.entnum, SV_CMD_RELIABLE, v12);
}

void __cdecl PlayerCmd_SetWeaponSlotAmmo(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_SetReverb(struct scr_entref_t) {
  unsigned int NumParam;       // eax
  bool v9;                     // cc
  double v10;                  // xmm0_8
  const char *String;          // ebx
  unsigned __int16 floatValue; // ax
  int v13;                     // eax
  char *v14;                   // eax
  char *v15;                   // eax
  float v16;                   // [esp+3Ch] [ebp-2Ch]
  float v17;                   // [esp+40h] [ebp-28h]
  float Float;                 // [esp+44h] [ebp-24h]
  double v19;                  // [esp+48h] [ebp-20h]
  double v20;                  // [esp+50h] [ebp-18h]
  double v21;                  // [esp+58h] [ebp-10h]

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    NumParam = Scr_GetNumParam();
    v9 = NumParam <= 3;
    if (NumParam != 3)
      goto LABEL_5;
  LABEL_13:
    Float = 0.0;
    v17 = 0.5;
    goto LABEL_14;
  }
  if (!*(&g_entities.client + 140 * a8.entnum)) {
    v15 = va("entity %i is not a player", a8.entnum);
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v15);
  }
  NumParam = Scr_GetNumParam();
  v9 = NumParam <= 3;
  if (NumParam == 3)
    goto LABEL_13;
LABEL_5:
  if (!v9) {
    if (NumParam == 4) {
      Float = 0.0;
      goto LABEL_9;
    }
    if (NumParam == 5) {
      Float = Scr_GetFloat(4u);
    LABEL_9:
      v17 = Scr_GetFloat(3u);
    LABEL_14:
      v16 = Scr_GetFloat(2u);
      v19 = Float;
      v20 = v17;
      v10 = v16;
      v21 = v16;
      goto LABEL_15;
    }
  LABEL_11:
    Scr_Error("USAGE: player setReverb(\"priority\", \"roomtype\", drylevel = "
              "1.0, wetlevel = 0.5, fadetime = 0);\n"
              "Valid priorities are \"snd_enveffectsprio_level\" or "
              "\"snd_enveffectsprio_shellshock\", dry level is a float from "
              "0 (no source sound) to 1 (full source sound), wetlevel is a "
              "float from 0 (no effect) to 1 (full effect), fadetime "
              "is in sec and modifies drylevel and wetlevel\n");
    return;
  }
  if (NumParam != 2)
    goto LABEL_11;
  v19 = 0.0;
  v20 = 0.5;
  LODWORD(v10) = 0;
  v21 = 1.0;
LABEL_15:
  String = (const char *)Scr_GetString(*(float *)&v10, 1u);
  floatValue =
      (unsigned __int16)Scr_GetConstString(*(float *)&v10, 0).floatValue;
  if (floatValue != word_195B102) {
    if (floatValue == word_195B104) {
      v13 = 2;
      goto LABEL_19;
    }
    Scr_Error("priority must be 'snd_enveffectsprio_level' or "
              "'snd_enveffectsprio_shellshock'\n");
  }
  v13 = 1;
LABEL_19:
  v14 = va("%c %i \"%s\" %g %g %g", 114, v13, String, v21, v20, v19);
  SV_GameSendServerCommand(a8.entnum, SV_CMD_RELIABLE, v14);
}

void __cdecl PlayerCmd_SetChannelVolumes(struct scr_entref_t) {
  int NumParam;                // eax
  double v9;                   // xmm0_8
  char *String;                // eax
  int ConfigstringIndex;       // ebx
  unsigned __int16 floatValue; // ax
  int v13;                     // eax
  char *v14;                   // eax
  char *v15;                   // eax
  float v16;                   // [esp+24h] [ebp-14h]
  double v17;                  // [esp+28h] [ebp-10h]

  if (!a8.classnum) {
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v15 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(Float, a2, a3, a4, a5, a6, a7, v15);
    }
    NumParam = Scr_GetNumParam();
    if (NumParam != 2)
      goto LABEL_5;
  LABEL_8:
    LODWORD(v9) = 0;
    v17 = 0.0;
    goto LABEL_9;
  }
  Scr_ObjectError(Float, a2, a3, a4, a5, a6, a7, "not an entity");
  NumParam = Scr_GetNumParam();
  if (NumParam == 2)
    goto LABEL_8;
LABEL_5:
  if (NumParam != 3) {
    Scr_Error("USAGE: player setchannelvolumes(\"priority\", \"shock name\", "
              "fadetime = 0);\n"
              "Valid priorities are \"snd_channelvolprio_holdbreath\", "
              "\"snd_channelvolprio_pain\", or \"snd_channelvolprio_shell"
              "shock\", fadetime is in sec\n");
    return;
  }
  Float = Scr_GetFloat(2u);
  v16 = Float;
  v9 = v16;
  v17 = v16;
LABEL_9:
  String = (char *)Scr_GetString(*(float *)&v9, 1u);
  ConfigstringIndex = G_FindConfigstringIndex(Float, *(float *)&v9, a3, a4, a5,
                                              a6, a7, String, 1166, 16, 0, 0);
  floatValue =
      (unsigned __int16)Scr_GetConstString(*(float *)&v9, 0).floatValue;
  if (floatValue != word_195B106) {
    if (floatValue == word_195B108) {
      v13 = 2;
      goto LABEL_14;
    }
    if (floatValue == word_195B10A) {
      v13 = 3;
      goto LABEL_14;
    }
    Scr_Error(
        "priority must be 'snd_channelvolprio_holdbreath', "
        "'snd_channelvolprio_pain', or 'snd_channelvolprio_shellshock'\n");
  }
  v13 = 1;
LABEL_14:
  v14 = va("%c %i %i %g", 69, v13, ConfigstringIndex, v17);
  SV_GameSendServerCommand(a8.entnum, SV_CMD_RELIABLE, v14);
}

void __cdecl PlayerCmd_GetGuid(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl ScrCmd_PlayLocalSound(struct scr_entref_t) {
  int entnum;          // ebx
  char *String;        // eax
  unsigned __int8 v10; // al
  char *v11;           // eax
  char *v12;           // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    entnum = a8.entnum;
  } else {
    entnum = a8.entnum;
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v12 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v12);
    }
  }
  String = (char *)Scr_GetString(a2, 0);
  v10 = G_SoundAliasIndex(a1, a2, a3, a4, a5, a6, a7, String);
  v11 = va("%c %i", 115, v10);
  SV_GameSendServerCommand(entnum, SV_CMD_CAN_IGNORE, v11);
}

void __cdecl ScrCmd_IsLookingAt(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_IsTalking(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_SetWeaponSlotClipAmmo(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_GetWeaponSlotClipAmmo(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_GetWeaponSlotAmmo(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_GetWeaponSlotWeapon(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_OpenMenuNoMouse(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_OpenMenu(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_GetViewmodel(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_SetViewmodel(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_getAngles(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_setOrigin(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_SetWeaponClipAmmo(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_SetWeaponSlotWeapon(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_setSpawnWeapon(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_ClonePlayer(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_SayTeam(struct scr_entref_t) {
  gentity_s *v8;  // esi
  int NumParam;   // eax
  char *v10;      // eax
  char __src;     // [esp+20h] [ebp-408h] BYREF
  char v12[1031]; // [esp+21h] [ebp-407h] BYREF

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
  } else {
    v8 = &g_entities + a8.entnum;
    if (!v8->client) {
      v10 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
    }
  }
  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(a1, a2, a3, a4, a5, a6, a7, 0, NumParam - 1,
                             "Client Chat Message", v12, 1023);
  __src = 20;
  G_Say(v8, 0, 1, &__src);
}

void __cdecl PlayerCmd_SayAll(struct scr_entref_t) {
  gentity_s *v8;  // esi
  int NumParam;   // eax
  char *v10;      // eax
  char __src;     // [esp+20h] [ebp-408h] BYREF
  char v12[1031]; // [esp+21h] [ebp-407h] BYREF

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
  } else {
    v8 = &g_entities + a8.entnum;
    if (!v8->client) {
      v10 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
    }
  }
  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(a1, a2, a3, a4, a5, a6, a7, 0, NumParam - 1,
                             "Client Chat Message", v12, 1023);
  __src = 20;
  G_Say(v8, 0, 0, &__src);
}

void __cdecl PlayerCmd_SetClientDvar(struct scr_entref_t) {
  unsigned int v8; // edi
  char *v9;        // eax
  int i;           // ebx
  char v11;        // al
  char v12;        // dl
  char v13;        // al
  char *v14;       // eax
  int NumParam;    // eax
  char *v16;       // eax
  char *String;    // [esp+28h] [ebp-820h]
  uint16_t entnum; // [esp+2Eh] [ebp-81Ah]
  char __b[1024];  // [esp+30h] [ebp-818h] BYREF
  char v20[1048];  // [esp+430h] [ebp-418h] BYREF

  entnum = a8.entnum;
  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    String = (char *)Scr_GetString(a2, 0);
    if (Scr_GetType(a1, a2, a3, a4, a5, a6, a7, 1u) != 3) {
    LABEL_5:
      v8 = Scr_GetString(a2, 1u);
      goto LABEL_6;
    }
  } else {
    if (!*(&g_entities.client + 140 * entnum)) {
      v16 = va("entity %i is not a player", entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v16);
    }
    String = (char *)Scr_GetString(a2, 0);
    if (Scr_GetType(a1, a2, a3, a4, a5, a6, a7, 1u) != 3)
      goto LABEL_5;
  }
  NumParam = Scr_GetNumParam();
  Scr_ConstructMessageString(a1, a2, a3, a4, a5, a6, a7, 1, NumParam - 1,
                             "Client Dvar Value", v20, 1024);
  v8 = (unsigned int)v20;
LABEL_6:
  if ((unsigned __int8)Dvar_IsValidName(String)) {
    memset(__b, 0, sizeof(__b));
    for (i = 1; i != 8193; ++i) {
      v13 = *(_BYTE *)(v8 + i - 1);
      if (!v13)
        break;
      v11 = I_CleanChar(v13);
      v12 = 39;
      if (v11 != 34)
        v12 = v11;
      __b[i - 1] = v12;
    }
    v14 = va("%c %s \"%s\"", 118, String, __b);
    SV_GameSendServerCommand(entnum, SV_CMD_RELIABLE, v14);
  } else {
    v9 = va("Dvar %s has an invalid dvar name", String);
    Scr_Error(v9);
  }
}

void __cdecl iclientprintlnbold(struct scr_entref_t) {
  char *v8;  // eax
  char *v9;  // eax
  char *v10; // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v9 = va("%c", 103);
    Scr_MakeGameMessage(a1, a2, a3, a4, a5, a6, a7, a8.entnum, v9);
  } else {
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v10 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
    }
    v8 = va("%c", 103);
    Scr_MakeGameMessage(a1, a2, a3, a4, a5, a6, a7, a8.entnum, v8);
  }
}

void __cdecl iclientprintln(struct scr_entref_t) {
  char *v8;  // eax
  char *v9;  // eax
  char *v10; // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v9 = va("%c", 102);
    Scr_MakeGameMessage(a1, a2, a3, a4, a5, a6, a7, a8.entnum, v9);
  } else {
    if (!*(&g_entities.client + 140 * a8.entnum)) {
      v10 = va("entity %i is not a player", a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
    }
    v8 = va("%c", 102);
    Scr_MakeGameMessage(a1, a2, a3, a4, a5, a6, a7, a8.entnum, v8);
  }
}

void __cdecl PlayerCmd_finishPlayerDamage(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl PlayerCmd_Suicide(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_dropItem(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl PlayerCmd_spawn(struct scr_entref_t) { UNIMPLEMENTED(); }
