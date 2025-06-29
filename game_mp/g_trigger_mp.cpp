int __cdecl Respond_trigger_damage(struct gentity_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl hurt_use(struct gentity_s *self, struct gentity_s *other,
                      struct gentity_s *activator)
{
  int8_t result; // al

  result = (a1->handler != 3) + 2;
  a1->handler = result;
  return result;
}

void __cdecl InitSentientTrigger(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl SP_trigger_lookat(struct gentity_s *self)
{
  SV_SetBrushModel(a1);
  a1->r.contents = 0x20000000;
  a1->r.svFlags = 1;
  a1->s.eFlags |= 1u;
  return SV_LinkEntity(a1);
}

void __cdecl SP_trigger_disk(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl SP_trigger_radius(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl InitTrigger(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl SP_trigger_damage(struct gentity_s *pSelf)
{
  float v2[3]; // [esp+1Ch] [ebp-Ch] BYREF

  G_SpawnInt("accumulate", "0", &a1->unnamed_field.trigger.accumulate);
  G_SpawnInt("threshold", "0", (int *)&a1->unnamed_field);
  a1->health = 32000;
  a1->takedamage = 1;
  a1->handler = 4;
  if (stru_19357C8.spawnVarsValid &&
      G_SpawnFloat("wait", (char *)&inData, v2) && v2[0] <= 0.0)
    a1->spawnflags |= 0x200u;
  SV_SetBrushModel(a1);
  a1->r.contents = 1079771144;
  a1->r.svFlags = 1;
  a1->s.eFlags |= 1u;
  return SV_LinkEntity(a1);
}

void __cdecl SP_trigger_once(struct gentity_s *ent)
{
  uint32_t spawnflags; // eax

  a1->handler = 1;
  a1->spawnflags |= 0x10u;
  SV_SetBrushModel(a1);
  a1->r.svFlags = 1;
  a1->s.eFlags |= 1u;
  a1->r.contents = 0;
  spawnflags = a1->spawnflags;
  if ((spawnflags & 8) == 0)
    a1->r.contents = 0x40000000;
  if ((spawnflags & 1) != 0)
    a1->r.contents |= 0x40000u;
  if ((spawnflags & 2) != 0)
    a1->r.contents |= 0x80000u;
  if ((spawnflags & 4) != 0)
    a1->r.contents |= 0x100000u;
  return SV_LinkEntity(a1);
}

void __cdecl SP_trigger_hurt(struct gentity_s *self)
{
  int8_t result; // al
  char *v2;      // [esp+1Ch] [ebp-Ch] BYREF

  SV_SetBrushModel(a1);
  a1->r.contents = 1079771144;
  a1->r.svFlags = 1;
  a1->s.eFlags |= 1u;
  G_SpawnString("sound", "world_hurt_me", &v2);
  if (!a1->damage)
    a1->damage = 5;
  a1->r.contents = 1079771144;
  result = 3 - (a1->spawnflags & 1);
  a1->handler = result;
  return result;
}

void __cdecl SP_trigger_multiple(struct gentity_s *ent)
{
  uint32_t spawnflags; // eax
  float v3[3];         // [esp+1Ch] [ebp-Ch] BYREF

  a1->handler = 1;
  if (stru_19357C8.spawnVarsValid &&
      G_SpawnFloat("wait", (char *)&inData, v3) && v3[0] <= 0.0)
    a1->spawnflags |= 0x10u;
  SV_SetBrushModel(a1);
  a1->r.svFlags = 1;
  a1->s.eFlags |= 1u;
  a1->r.contents = 0;
  spawnflags = a1->spawnflags;
  if ((spawnflags & 8) == 0)
    a1->r.contents = 0x40000000;
  if ((spawnflags & 1) != 0)
    a1->r.contents |= 0x40000u;
  if ((spawnflags & 2) != 0)
    a1->r.contents |= 0x80000u;
  if ((spawnflags & 4) != 0)
    a1->r.contents |= 0x100000u;
  return SV_LinkEntity(a1);
}

void __cdecl G_Trigger(struct gentity_s *self, struct gentity_s *other)
{
  UNIMPLEMENTED();
}

void __cdecl Activate_trigger_damage(struct gentity_s *pEnt,
                                     struct gentity_s *pOther, int iDamage,
                                     int iMOD)
{
  UNIMPLEMENTED();
}

void __cdecl multi_trigger(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl G_GrenadeTouchTriggerDamage(struct gentity_s *pActivator,
                                         float *const vStart, float *const vEnd,
                                         int iDamage, int iMOD)
{
  UNIMPLEMENTED();
}

void __cdecl G_CheckHitTriggerDamage(struct gentity_s *pActivator,
                                     float *const vStart, float *const vEnd,
                                     int iDamage, int iMOD)
{
  UNIMPLEMENTED();
}

void __cdecl Die_trigger_damage(struct gentity_s *pSelf,
                                struct gentity_s *pInflictor,
                                struct gentity_s *pAttacker, int iDamage,
                                int iMod, int iWeapon, float const *const vDir,
                                enum hitLocation_t hitLoc, int timeOffset)
{
  UNIMPLEMENTED();
}

void __cdecl Pain_trigger_damage(struct gentity_s *, struct gentity_s *, int,
                                 float const *const, int, float const *const,
                                 enum hitLocation_t)
{
  UNIMPLEMENTED();
}

void __cdecl Use_trigger_damage(struct gentity_s *pEnt,
                                struct gentity_s *pOther,
                                struct gentity_s *pActivator)
{
  UNIMPLEMENTED();
}

void __cdecl hurt_touch(struct gentity_s *self, struct gentity_s *other,
                        int bTouched)
{
  int *v9;             // edx
  uint32_t spawnflags; // edx

    if (a9->takedamage &&
        (signed int)a8->unnamed_field.trigger.timestamp <= dword_193466C) {
        if (Scr_IsSystemActive()) {
            if (dword_1937A68 == 256) {
              Scr_AddEntity(a2, a9);
              Scr_Notify(a2, a8, word_195B0D4, 1u);
            }
            else {
              v9 = &level[3 * dword_1937A68++ + 1912];
              *((_WORD *)v9 + 4) = a8->s.number;
              *((_WORD *)v9 + 5) = a9->s.number;
              v9[3] = a8->useCount;
              v9[4] = a9->useCount;
            }
        }
      spawnflags = a8->spawnflags;
      if ((spawnflags & 0x10) != 0)
        a8->unnamed_field.trigger.timestamp = dword_193466C + 1000;
      else
        a8->unnamed_field.trigger.timestamp = dword_193466C + 50;
      G_Damage(a1, a2, a3, a4, a5, a6, a7, a9, a8, a8, 0, 0, a8->damage,
               (spawnflags & 8) != 0 ? 0x10 : 0, 0xDu, HITLOC_NONE, 0);
      if ((a8->spawnflags & 0x20) != 0)
        a8->handler = 2;
    }
}

void __cdecl Touch_Multi(struct gentity_s *self, struct gentity_s *other,
                         int bTouched)
{
  UNIMPLEMENTED();
}

void __cdecl InitTriggerWait(struct gentity_s *, int)
{
  UNIMPLEMENTED();
}
