void __cdecl GScr_AddFieldsForClient()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_SetClientField(struct gclient_s *client, int offset)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_GetClientField(struct gclient_s *client, int offset)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_SetPSOffsetTime(struct gclient_s *,
                                       struct client_fields_s const *)
{
  VariableUnion result; // eax

  result.intValue = Scr_GetInt(0).intValue;
  *(VariableUnion *)((char *)&a1->sess.psOffsetTime + 2) = result;
  return result;
}

void __cdecl ClientScr_SetArchiveTime(struct gclient_s *,
                                      struct client_fields_s const *)
{
  gclient_s *result; // eax
  float Float;       // [esp+1Ch] [ebp-Ch]

  Float = Scr_GetFloat(0);
  result = a1;
  a1->sess.archiveTime = (int)(float)(Float * 1000.0);
  return result;
}

void __cdecl ClientScr_SetSpectatorClient(struct gclient_s *,
                                          struct client_fields_s const *)
{
  VariableUnion v1;  // ebx
  gclient_s *result; // eax

  v1.intValue = Scr_GetInt(0).intValue;
  if ((unsigned int)(v1.intValue + 1) > 0x40)
    Scr_Error(
        "spectatorclient can only be set to -1, or a valid client number");
  result = a1;
  *(VariableUnion *)a1->sess.forceSpectatorClient = v1;
  return result;
}

void __cdecl ClientScr_SetScore(struct gclient_s *,
                                struct client_fields_s const *)
{
  a1->sess.score = Scr_GetInt(0).intValue;
  CalculateRanks();
}

void __cdecl ClientScr_SetMaxHealth(struct gclient_s *,
                                    struct client_fields_s const *)
{
  VariableUnion v1; // eax
  VariableUnion v2; // edx
  int32_t intValue; // ecx
  int result;       // eax

  v1.intValue = Scr_GetInt(0).intValue;
  v2.intValue = 1;
  if (v1.intValue > 0)
    v2.intValue = v1.intValue;
  *(VariableUnion *)((char *)&a1->sess.maxHealth + 2) = v2;
    if (*(_DWORD *)a1->ps.stats <= v2.intValue) {
      intValue = *(_DWORD *)a1->ps.stats;
    }
    else {
      *(VariableUnion *)a1->ps.stats = v2;
      intValue = v2.intValue;
    }
  *(&g_entities.health + 421488044 * (((int)a1 - level[0]) >> 2)) = intValue;
  result = *(int32_t *)((char *)&a1->sess.maxHealth + 2);
  *(_DWORD *)&a1->ps.stats[8] = result;
  return result;
}

void __cdecl ClientScr_ReadOnly(struct gclient_s *,
                                struct client_fields_s const *)
{
  char *v2; // eax

  v2 = va("player field %s is read-only", *(const char **)a2->name);
  return Scr_Error(v2);
}

void __cdecl ClientScr_SetHeadIconTeam(struct gclient_s *,
                                       struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_SetSessionState(struct gclient_s *,
                                       struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_SetHeadIcon(struct gclient_s *,
                                   struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_SetStatusIcon(struct gclient_s *,
                                     struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_SetSessionTeam(struct gclient_s *,
                                      struct client_fields_s const *)
{
  unsigned __int16 floatValue; // ax
  const char *v9;              // eax
  char *v10;                   // eax

  floatValue = (unsigned __int16)Scr_GetConstString(a2, 0).floatValue;
    if (floatValue == word_195B084) {
      *(int32_t *)((char *)&a8->sess.cs.team + 2) = 1;
    }
    else if (floatValue == word_195B082) {
      *(int32_t *)((char *)&a8->sess.cs.team + 2) = 2;
    }
    else if (floatValue == word_195B0C8) {
      *(int32_t *)((char *)&a8->sess.cs.team + 2) = 3;
    }
    else if (floatValue == word_195B0F4) {
      *(int32_t *)((char *)&a8->sess.cs.team + 2) = 0;
    }
    else {
      v9 = (const char *)SL_ConvertToString(floatValue);
      v10 = va("'%s' is an illegal sessionteam string. Must be allies, axis, "
               "none, or spectator.",
               v9);
      Scr_Error(v10);
    }
  ClientUserinfoChanged(a1, a2, a3, a4, a5, a6, a7,
                        1682649625 * (((int)a8 - level[0]) >> 2));
  CalculateRanks();
}

void __cdecl ClientScr_GetPSOffsetTime(struct gclient_s *,
                                       struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_GetArchiveTime(struct gclient_s *,
                                      struct client_fields_s const *)
{
  return Scr_AddFloat((float)(int)a1->sess.archiveTime * 0.001,
                      (float)(int)a1->sess.archiveTime * 0.001);
}

void __cdecl ClientScr_GetHeadIconTeam(struct gclient_s *,
                                       struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_GetHeadIcon(struct gclient_s *,
                                   struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_GetStatusIcon(struct gclient_s *,
                                     struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_GetSessionState(struct gclient_s *,
                                       struct client_fields_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClientScr_GetSessionTeam(struct gclient_s *,
                                      struct client_fields_s const *)
{
  UNIMPLEMENTED();
}
