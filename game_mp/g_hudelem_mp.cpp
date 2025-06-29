int const __cdecl FastCeil(float) { UNIMPLEMENTED(); }

void __cdecl HudElem_UpdateClient(struct gclient_s *client, int clientNum,
                                  enum hudelem_update_t which) {
  char v3;             // si
  int v4;              // esi
  int32_t *v5;         // ebx
  char *result;        // eax
  uint8_t *v7;         // edx
  int v8;              // esi
  int32_t *v9;         // ebx
  uint8_t *v10;        // edx
  int v11;             // esi
  int32_t *p_archived; // ebx
  char *v13;           // edx
  $_3593 *p_hud;       // [esp+18h] [ebp-20h]
  int v15;             // [esp+1Ch] [ebp-1Ch]

  v3 = a3 & 1;
  if ((a3 & 1) == 0) {
    if ((a3 & 2) == 0)
      goto LABEL_3;
    goto LABEL_16;
  }
  memset(a1->ps.hud.archival, 0, sizeof(a1->ps.hud.archival));
  if ((a3 & 2) != 0) {
  LABEL_16:
    p_hud = &a1->ps.hud;
    memset(&a1->ps.hud, 0, 0xF80u);
    if (!v3) {
      v11 = 0;
      p_archived = &g_hudelems.archived;
      do {
        result = (char *)*(p_archived - 34);
        if (result) {
          result = (char *)*(p_archived - 1);
          if (!result || result == *(char **)((char *)&a1->sess.cs.team + 2)) {
            result = (char *)*(p_archived - 2);
            if (result == (char *)1023 || result == a2) {
              result = (char *)*p_archived;
              if (!*p_archived) {
                result = (char *)(v11 << 7);
                v13 = (char *)p_hud + 128 * v11++;
                if (v11 <= 31)
                  result = (char *)memcpy(v13, p_archived - 34, 0x80u);
              }
            }
          }
        }
        p_archived += 35;
      } while (p_archived != (int32_t *)&unk_195AF88);
      return result;
    }
    v15 = 0;
    v8 = 0;
    v9 = &g_hudelems.archived;
    while (1) {
      result = (char *)*(v9 - 34);
      if (!result)
        goto LABEL_18;
      result = (char *)*(v9 - 1);
      if (result) {
        if (result != *(char **)((char *)&a1->sess.cs.team + 2))
          goto LABEL_18;
      }
      result = (char *)*(v9 - 2);
      if (result != (char *)1023 && result != a2)
        goto LABEL_18;
      if (!*v9)
        break;
      result = (char *)(v15 << 7);
      v10 = &a1->ps.hud.archival[128 * v15++];
      if (v15 <= 31)
        goto LABEL_26;
    LABEL_18:
      v9 += 35;
      if (v9 == (int32_t *)&unk_195AF88)
        return result;
    }
    result = (char *)(v8 << 7);
    v10 = &p_hud->current[128 * v8++];
    if (v8 > 31)
      goto LABEL_18;
  LABEL_26:
    result = (char *)memcpy(v10, v9 - 34, 0x80u);
    goto LABEL_18;
  }
LABEL_3:
  if (v3) {
    v4 = 0;
    v5 = &g_hudelems.archived;
    do {
      while (1) {
        result = (char *)*(v5 - 34);
        if (result) {
          result = (char *)*(v5 - 1);
          if (!result || result == *(char **)((char *)&a1->sess.cs.team + 2)) {
            result = (char *)*(v5 - 2);
            if (result == (char *)1023 || result == a2) {
              result = (char *)*v5;
              if (*v5) {
                result = (char *)(v4 << 7);
                v7 = &a1->ps.hud.archival[128 * v4++];
                if (v4 <= 31)
                  break;
              }
            }
          }
        }
        v5 += 35;
        if (v5 == (int32_t *)&unk_195AF88)
          return result;
      }
      result = (char *)memcpy(v7, v5 - 34, 0x80u);
      v5 += 35;
    } while (v5 != (int32_t *)&unk_195AF88);
  } else {
    result = (char *)&g_hudelems.archived;
    do
      result += 140;
    while (result != (char *)&unk_195AF88);
  }
  return result;
}

void (__cdecl*__cdecl HudElem_GetMethod pName))(struct scr_entref_t)
{
  UNIMPLEMENTED();
}

struct game_hudelem_s *__cdecl HudElem_Alloc(int, int) {
  UNIMPLEMENTED();
}

void __cdecl GScr_AddFieldsForHudElems() {
  const char *v0;  // ebx
  int v1;          // edi
  const char **v2; // esi
  int result;      // eax

  v0 = fields_0;
  if (fields_0) {
    v1 = 0;
    v2 = (const char **)&unk_33351C;
    do {
      result = Scr_AddClassField(1, v0, 28087 * (v1 >> 2));
      v0 = *v2;
      v1 += 28;
      v2 += 7;
    } while (v0);
  }
  return result;
}

void __cdecl Scr_FreeHudElemConstStrings(struct game_hudelem_s *hud) {
  UNIMPLEMENTED();
}

void __cdecl Scr_SetHudElemField(int entnum, int offset) { UNIMPLEMENTED(); }

void __cdecl HudElem_Free(struct game_hudelem_s *) { UNIMPLEMENTED(); }

void __cdecl HudElem_DestroyAll() { UNIMPLEMENTED(); }

void __cdecl HudElem_ClientDisconnect(struct gentity_s *ent) {
  game_hudelem_s *v1; // ebx
  uint32_t result;    // eax

  v1 = &g_hudelems;
  do {
    while (1) {
      if (v1->elem.type) {
        result = v1->clientNum;
        if (result == a1->s.number)
          break;
      }
      if (++v1 == (game_hudelem_s *)&unk_195AF00)
        return result;
    }
    result = Scr_FreeHudElem(v1);
    v1->elem.type = 0;
    ++v1;
  } while (v1 != (game_hudelem_s *)&unk_195AF00);
  return result;
}

void __cdecl GScr_NewTeamHudElem() { UNIMPLEMENTED(); }

void __cdecl GScr_NewClientHudElem() { UNIMPLEMENTED(); }

void __cdecl GScr_NewHudElem() {
  int v0;             // ebx
  int v1;             // eax
  game_hudelem_s *v2; // ecx
  int v3;             // eax
  game_hudelem_s *v5; // edx
  int32_t type;       // eax

  if (g_hudelems.elem.type) {
    v0 = 0;
    v5 = &g_hudelems;
    while (++v0 != 1024) {
      type = v5[1].elem.type;
      ++v5;
      if (!type) {
        v1 = v0;
        goto LABEL_3;
      }
    }
    Scr_Error("out of hudelems");
    v2 = 0;
  } else {
    v0 = 0;
    v1 = 0;
  LABEL_3:
    v2 = &g_hudelems + v1;
    v2->elem.type = 1;
    v2->elem.x = 0;
    v2->elem.y = 0;
    v2->elem.z = 0;
    v2->elem.fontScale = 1065353216;
    v2->elem.font = 0;
    v2->elem.alignOrg = 0;
    v2->elem.alignScreen = 0;
    v2->elem.color.rgba = -1;
    v2->elem.fromColor = 0;
    v2->elem.fadeStartTime = 0;
    v2->elem.fadeTime = 0;
    v2->elem.label = 0;
    v2->elem.sort = 0;
    v2->elem.foreground = 0;
    v2->archived = 1;
    v2->elem.width = 0;
    v2->elem.height = 0;
    v2->elem.materialIndex = 0;
    v2->elem.fromX = 0;
    v2->elem.fromY = 0;
    v2->elem.fromAlignOrg = 0;
    v2->elem.fromAlignScreen = 0;
    v2->elem.fromWidth = 0;
    v2->elem.fromHeight = 0;
    v2->elem.scaleStartTime = 0;
    v2->elem.scaleTime = 0;
    v2->elem.time = 0;
    v2->elem.duration = 0;
    v2->elem.value = 0;
    *(_DWORD *)v2->elem.text = 0;
    v3 = 140 * v0;
    *(uint32_t *)((char *)&g_hudelems.clientNum + v3) = 1023;
    *(int32_t *)((char *)&g_hudelems.team + v3) = 0;
  }
  return Scr_AddHudElem(v2);
}

void __cdecl Scr_GetHudElemField(int entnum, int offset) { UNIMPLEMENTED(); }

struct game_hudelem_s *g_hudelems;
void __cdecl HudElem_ClearTypeSettings(struct game_hudelem_s *) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetFontScale(struct game_hudelem_s *, int) {
  game_hudelem_s *result; // eax
  char *v2;               // eax
  float Float;            // [esp+1Ch] [ebp-Ch]

  Float = Scr_GetFloat(0);
  if (Float <= 0.0) {
    v2 = va("font scale was %g; should be > 0", Float);
    Scr_Error(v2);
  }
  result = a1;
  *(float *)&a1->elem.fontScale = Float;
  return result;
}

void __cdecl HudElem_SetBoolean(struct game_hudelem_s *, int) {
  VariableUnion result; // eax

  result.intValue = Scr_GetInt(0).intValue;
  *(VariableUnion *)((char *)&a1->elem.type + dword_333504[7 * a2]) = result;
  return result;
}

void __cdecl HudElem_SetDefaults(struct game_hudelem_s *) { UNIMPLEMENTED(); }

struct game_hudelem_s *__cdecl HECmd_GetHudElem(struct scr_entref_t) {
  UNIMPLEMENTED();
}

void __cdecl HECmd_Reset(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_MoveOverTime(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_ScaleOverTime(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_FadeOverTime(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetWaypoint(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetValue(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetTimer_Internal(struct scr_entref_t, enum he_type_t,
                                     char const *) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetAlpha(struct game_hudelem_s *, int) {
  float v1;               // xmm1_4
  float v2;               // xmm0_4
  game_hudelem_s *result; // eax
  float Float;            // [esp+1Ch] [ebp-1Ch]
  float v5;               // [esp+2Ch] [ebp-Ch]

  Float = Scr_GetFloat(0);
  v1 = Float;
  if ((float)(Float - 1.0) < 0.0) {
    v2 = 0.0 - Float;
  } else {
    v1 = 1.0;
    v2 = -1.0;
  }
  if (v2 < 0.0)
    v5 = floorf((float)(v1 * 255.0) + 0.5);
  else
    v5 = floorf(0.0 + 0.5);
  result = a1;
  a1->elem.color.unnamed_field.a = (int)v5;
  return result;
}

void __cdecl HudElem_SetColor(struct game_hudelem_s *, int) {
  float v1;   // xmm1_4
  float v2;   // xmm0_4
  float v3;   // xmm0_4
  float v4;   // xmm1_4
  float v5;   // xmm0_4
  float v6;   // xmm0_4
  float v7;   // xmm1_4
  float v8;   // xmm0_4
  int result; // eax
  float v10;  // [esp+24h] [ebp-24h]
  float v11;  // [esp+28h] [ebp-20h]
  float v12;  // [esp+2Ch] [ebp-1Ch]
  float v13;  // [esp+34h] [ebp-14h] BYREF
  float v14;  // [esp+38h] [ebp-10h]
  float v15;  // [esp+3Ch] [ebp-Ch]

  Scr_GetVector(0, &v13);
  v1 = v13;
  if ((float)(v13 - 1.0) < 0.0) {
    v2 = 0.0 - v13;
  } else {
    v1 = 1.0;
    v2 = -1.0;
  }
  if (v2 < 0.0)
    v3 = v1 * 255.0;
  else
    v3 = 0.0;
  v12 = floorf(v3 + 0.5);
  a1->elem.color.unnamed_field.r = (int)v12;
  v4 = v14;
  if ((float)(v14 - 1.0) < 0.0) {
    v5 = 0.0 - v14;
  } else {
    v4 = 1.0;
    v5 = -1.0;
  }
  if (v5 < 0.0)
    v6 = v4 * 255.0;
  else
    v6 = 0.0;
  v11 = floorf(v6 + 0.5);
  a1->elem.color.unnamed_field.g = (int)v11;
  v7 = v15;
  if ((float)(v15 - 1.0) < 0.0) {
    v8 = 0.0 - v15;
  } else {
    v7 = 1.0;
    v8 = -1.0;
  }
  if (v8 < 0.0)
    v10 = floorf((float)(v7 * 255.0) + 0.5);
  else
    v10 = floorf(0.0 + 0.5);
  result = (int)v10;
  a1->elem.color.unnamed_field.b = (int)v10;
  return result;
}

void __cdecl HECmd_SetTenthsTimerUp(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetTenthsTimer(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetTimerUp(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetTimer(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HudElem_SetEnumString(struct game_hudelem_s *,
                                   struct game_hudelem_field_t const *,
                                   char const **const, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetVertAlign(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetHorzAlign(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetAlignY(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetAlignX(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_SetFont(struct game_hudelem_s *, int) { UNIMPLEMENTED(); }

void __cdecl HECmd_Destroy(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetClock_Internal(struct scr_entref_t, enum he_type_t,
                                     char const *) {
  UNIMPLEMENTED();
}

void __cdecl HECmd_SetShader(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetText(struct scr_entref_t) {
  game_hudelem_s *v1;  // ebx
  const char *IString; // eax
  int result;          // eax

  if (a1.classnum == 1) {
    v1 = &g_hudelems + a1.entnum;
  } else {
    Scr_ObjectError("not a hud element");
    v1 = 0;
  }
  IString = (const char *)Scr_GetIString(0);
  v1->elem.width = 0;
  v1->elem.height = 0;
  v1->elem.materialIndex = 0;
  v1->elem.fromX = 0;
  v1->elem.fromY = 0;
  v1->elem.fromAlignOrg = 0;
  v1->elem.fromAlignScreen = 0;
  v1->elem.fromWidth = 0;
  v1->elem.fromHeight = 0;
  v1->elem.scaleStartTime = 0;
  v1->elem.scaleTime = 0;
  v1->elem.time = 0;
  v1->elem.duration = 0;
  v1->elem.value = 0;
  *(_DWORD *)v1->elem.text = 0;
  v1->elem.type = 1;
  result = G_LocalizedStringIndex(IString);
  *(_DWORD *)v1->elem.text = result;
  return result;
}

void __cdecl HudElem_GetAlpha(struct game_hudelem_s *, int) {
  float v1; // xmm0_4

  v1 = (float)(unsigned __int8)a1->elem.color.unnamed_field.a * 0.0039215689;
  return Scr_AddFloat(v1, v1);
}

void __cdecl HudElem_GetColor(struct game_hudelem_s *, int) {
  float v2[5]; // [esp+14h] [ebp-14h] BYREF

  v2[0] = (float)(unsigned __int8)a1->elem.color.unnamed_field.r * 0.0039215689;
  v2[1] = (float)(unsigned __int8)a1->elem.color.unnamed_field.g * 0.0039215689;
  v2[2] = (float)(unsigned __int8)a1->elem.color.unnamed_field.b * 0.0039215689;
  return Scr_AddVector(v2);
}

void __cdecl HudElem_SetLocalizedString(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_GetEnumString(struct game_hudelem_s *,
                                   struct game_hudelem_field_t const *,
                                   char const **const, int) {
  UNIMPLEMENTED();
}

void __cdecl HECmd_SetClockUp(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetClock(struct scr_entref_t) { UNIMPLEMENTED(); }

void __cdecl HudElem_GetVertAlign(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_GetHorzAlign(struct game_hudelem_s *, int) {
  return Scr_AddString(
      g_he_horzalign[*((_DWORD *)&unk_33350C + 7 * a2) &
                     (*(int *)((char *)&a1->elem.type + dword_333504[7 * a2]) >>
                      *((_DWORD *)&unk_333510 + 7 * a2))]);
}

void __cdecl HudElem_GetAlignY(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_GetAlignX(struct game_hudelem_s *, int) {
  UNIMPLEMENTED();
}

void __cdecl HudElem_GetFont(struct game_hudelem_s *, int) { UNIMPLEMENTED(); }

void __cdecl HECmd_SetMapNameString(struct scr_entref_t) {
  game_hudelem_s *v8; // ebx
  char *String;       // eax
  char *v10;          // esi

  if (a8.classnum != 1) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not a hud element");
    v8 = 0;
    String = (char *)Scr_GetString(a2, 0);
    v10 = String;
    if (String)
      goto LABEL_3;
  LABEL_7:
    Com_Printf("Invalid mapname passed to hudelem setmapnamestring()\n");
    return;
  }
  v8 = &g_hudelems + a8.entnum;
  String = (char *)Scr_GetString(a2, 0);
  v10 = String;
  if (!String)
    goto LABEL_7;
LABEL_3:
  if (SV_MapExists(String)) {
    SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x13u, v10);
    v8->elem.width = 0;
    v8->elem.height = 0;
    v8->elem.materialIndex = 0;
    v8->elem.fromX = 0;
    v8->elem.fromY = 0;
    v8->elem.fromAlignOrg = 0;
    v8->elem.fromAlignScreen = 0;
    v8->elem.fromWidth = 0;
    v8->elem.fromHeight = 0;
    v8->elem.scaleStartTime = 0;
    v8->elem.scaleTime = 0;
    v8->elem.time = 0;
    v8->elem.duration = 0;
    v8->elem.value = 0;
    *(_DWORD *)v8->elem.text = 0;
    v8->elem.type = 4;
  } else {
    Com_Printf("Invalid map name passed to hudelem setmapnamestring(), map not "
               "found\n");
  }
}

void __cdecl HECmd_SetGameTypeString(struct scr_entref_t) {
  game_hudelem_s *v8; // ebx
  char *String;       // eax
  char *v10;          // esi

  if (a8.classnum != 1) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not a hud element");
    v8 = 0;
    String = (char *)Scr_GetString(a2, 0);
    v10 = String;
    if (String)
      goto LABEL_3;
  LABEL_6:
    Com_Printf("Invalid entity passed to hudelem setgametypestring()\n");
    return;
  }
  v8 = &g_hudelems + a8.entnum;
  String = (char *)Scr_GetString(a2, 0);
  v10 = String;
  if (!String)
    goto LABEL_6;
LABEL_3:
  if (Scr_GetGameTypeNameForScript(String)) {
    SV_SetConfigstring(a1, a2, a3, a4, a5, a6, a7, 0x14u, v10);
    v8->elem.width = 0;
    v8->elem.height = 0;
    v8->elem.materialIndex = 0;
    v8->elem.fromX = 0;
    v8->elem.fromY = 0;
    v8->elem.fromAlignOrg = 0;
    v8->elem.fromAlignScreen = 0;
    v8->elem.fromWidth = 0;
    v8->elem.fromHeight = 0;
    v8->elem.scaleStartTime = 0;
    v8->elem.scaleTime = 0;
    v8->elem.time = 0;
    v8->elem.duration = 0;
    *(_DWORD *)v8->elem.text = 0;
    v8->elem.type = 5;
    v8->elem.value = 1101004800;
  } else {
    Com_Printf("Invalid gametype '%s'\n", v10);
  }
}

void __cdecl HECmd_SetPlayerNameString(struct scr_entref_t) {
  game_hudelem_s *v8; // ebx
  gentity_s *Entity;  // eax

  if (a8.classnum == 1) {
    v8 = &g_hudelems + a8.entnum;
  } else {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not a hud element");
    v8 = 0;
  }
  Entity = Scr_GetEntity(0);
  if (Entity) {
    if (Entity->client) {
      v8->elem.width = 0;
      v8->elem.height = 0;
      v8->elem.materialIndex = 0;
      v8->elem.fromX = 0;
      v8->elem.fromY = 0;
      v8->elem.fromAlignOrg = 0;
      v8->elem.fromAlignScreen = 0;
      v8->elem.fromWidth = 0;
      v8->elem.fromHeight = 0;
      v8->elem.scaleStartTime = 0;
      v8->elem.scaleTime = 0;
      v8->elem.time = 0;
      v8->elem.duration = 0;
      v8->elem.value = 0;
      *(_DWORD *)v8->elem.text = 0;
      v8->elem.type = 3;
      *(float *)&v8->elem.value = (float)(int)Entity->s.number;
    } else {
      Com_Printf("Invalid entity passed to hudelem setplayernamestring(), "
                 "entity is not a client\n");
    }
  } else {
    Com_Printf("Invalid entity passed to hudelem setplayernamestring()\n");
  }
}
