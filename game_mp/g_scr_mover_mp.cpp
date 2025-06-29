void (__cdecl*__cdecl ScriptEnt_GetMethod pName))(struct scr_entref_t)
{
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmdGetCommandTimes(float *pfTotalTime, float *pfAccelTime,
                                         float *pfDecelTime) {
  int NumParam; // ebx
  int *result;  // eax
  float Float;  // [esp+14h] [ebp-24h]
  float v6;     // [esp+18h] [ebp-20h]
  float v7;     // [esp+1Ch] [ebp-1Ch]

  Float = Scr_GetFloat(1u);
  *a1 = Float;
  if (Float <= 0.0)
    Scr_ParamError(1u, "total time must be positive");
  NumParam = Scr_GetNumParam();
  if (NumParam > 2) {
    v6 = Scr_GetFloat(2u);
    *a2 = v6;
    if (v6 < 0.0)
      Scr_ParamError(2u, "accel time must be nonnegative");
    if (NumParam > 3) {
      v7 = Scr_GetFloat(3u);
      *a3 = v7;
      if (v7 < 0.0)
        Scr_ParamError(3u, "decel time must be nonnegative");
    } else {
      *a3 = 0.0;
    }
  } else {
    *a2 = 0.0;
    *a3 = 0.0;
  }
  result = (int *)a1;
  if ((float)(*a2 + *a3) > *a1)
    return Scr_Error("accel time plus decel time is greater than total time");
  return result;
}

void __cdecl InitScriptMover(struct gentity_s *pSelf) {
  int result;   // eax
  int v2;       // ebx
  int v3;       // eax
  int v4;       // edx
  int v5;       // eax
  int v6;       // ebx
  int v7;       // eax
  int v8;       // ecx
  int v9;       // eax
  int v10;      // eax
  float v11[2]; // [esp+10h] [ebp-18h] BYREF
  float v12;    // [esp+18h] [ebp-10h]
  float v13[3]; // [esp+1Ch] [ebp-Ch] BYREF

  if (stru_19357C8.spawnVarsValid) {
    v2 = G_SpawnFloat("light", "100", v13);
    v3 = G_SpawnVector("color", "1 1 1", v11);
    if (v2 || v3) {
      v4 = (int)(float)(v11[0] * 255.0);
      if (v4 >= 256)
        v4 = 255;
      v5 = (int)(float)(v11[1] * 255.0);
      if (v5 <= 255) {
        v6 = v5 << 8;
        v7 = (int)(float)(255.0 * v12);
        if (v7 > 255) {
        LABEL_9:
          v8 = (int)&unk_FF0000;
          v9 = (int)(float)(0.25 * v13[0]);
          if (v9 > 255) {
          LABEL_10:
            v10 = -16777216;
          LABEL_11:
            a1->s.constantLight = v10 | v8 | v6 | v4;
            goto LABEL_2;
          }
        LABEL_14:
          v10 = v9 << 24;
          goto LABEL_11;
        }
      } else {
        v6 = 65280;
        v7 = (int)(float)(255.0 * v12);
        if (v7 > 255)
          goto LABEL_9;
      }
      v8 = v7 << 16;
      v9 = (int)(float)(0.25 * v13[0]);
      if (v9 > 255)
        goto LABEL_10;
      goto LABEL_14;
    }
  }
LABEL_2:
  a1->handler = 5;
  a1->r.svFlags = 0;
  a1->s.eType = 6;
  a1->s.pos.trBase[0] = a1->r.currentOrigin[0];
  a1->s.pos.trBase[1] = a1->r.currentOrigin[1];
  a1->s.pos.trBase[2] = a1->r.currentOrigin[2];
  a1->s.pos.trType = 0;
  *(float *)&a1->s.apos[12] = a1->r.currentAngles[0];
  *(float *)&a1->s.apos[16] = a1->r.currentAngles[1];
  result = LODWORD(a1->r.currentAngles[2]);
  *(_DWORD *)&a1->s.apos[20] = result;
  *(_DWORD *)a1->s.apos = 0;
  a1->flags |= 0x1000u;
  return result;
}

void __cdecl ScriptEntCmd_NotSolid(struct scr_entref_t entref) {
  gentity_s *v8; // ebx
  __int16 v9;    // ax
  char *v10;     // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
    v9 = MEMORY[0x168];
  } else {
    v8 = &g_entities + a8.entnum;
    v9 = *(_WORD *)v8->classname;
    if (v9 != word_195B0C2 && v9 != word_195B0C4) {
      if (v9 == word_195B0C6) {
      LABEL_10:
        Com_DPrintf("cannot use the solid/notsolid commands on a script_origin "
                    "entity( number %i )\n",
                    v8->s.number);
        return;
      }
      v10 = va("entity %i is not a script_brushmodel, script_model, or "
               "script_origin",
               a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
      v9 = *(_WORD *)v8->classname;
    }
  }
  if (v9 == word_195B0C6)
    goto LABEL_10;
  v8->r.contents = 0;
  if (v9 != word_195B0C4)
    v8->s.eFlags |= 1u;
  SV_LinkEntity(v8);
}

void __cdecl ScriptEntCmd_Solid(struct scr_entref_t entref) {
  gentity_s *v8; // ebx
  __int16 v9;    // ax
  char *v10;     // eax

  if (a8.classnum) {
    Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, "not an entity");
    v8 = 0;
    v9 = MEMORY[0x168];
  } else {
    v8 = &g_entities + a8.entnum;
    v9 = *(_WORD *)v8->classname;
    if (v9 != word_195B0C2 && v9 != word_195B0C4) {
      if (v9 == word_195B0C6) {
      LABEL_10:
        Com_DPrintf("cannot use the solid/notsolid commands on a script_origin "
                    "entity( number %i )\n",
                    v8->s.number);
        return;
      }
      v10 = va("entity %i is not a script_brushmodel, script_model, or "
               "script_origin",
               a8.entnum);
      Scr_ObjectError(a1, a2, a3, a4, a5, a6, a7, v10);
      v9 = *(_WORD *)v8->classname;
    }
  }
  if (v9 == word_195B0C6)
    goto LABEL_10;
  if (word_195B0C4 == v9) {
    v8->r.contents = 8320;
  } else {
    v8->r.contents = 1;
    v8->s.eFlags &= ~1u;
  }
  SV_LinkEntity(v8);
}

void __cdecl SP_script_origin(struct gentity_s *pSelf) {
  int32_t result; // eax

  InitScriptMover(a1);
  a1->r.contents = 0;
  SV_LinkEntity(a1);
  result = a1->s.constantLight;
  if (result)
    a1->s.eFlags |= 0x20u;
  else
    a1->r.svFlags |= 1u;
  return result;
}

void __cdecl SP_script_brushmodel(struct gentity_s *pSelf) {
  SV_SetBrushModel(a1);
  InitScriptMover(a1);
  a1->r.contents = 1;
  return SV_LinkEntity(a1);
}

void __cdecl ScriptEntCmd_RotateVelocity(struct scr_entref_t entref) {
  gentity_s *v1;        // esi
  __int16 v2;           // ax
  const char *v3;       // eax
  float v4;             // xmm3_4
  float v5;             // xmm1_4
  float *currentAngles; // ebx
  uint8_t *apos;        // edi
  float v8;             // xmm0_4
  float v10;            // [esp+20h] [ebp-A8h]
  float v11;            // [esp+30h] [ebp-98h]
  float *p_accumulate;  // [esp+4Ch] [ebp-7Ch]
  float *p_aMidTime;    // [esp+50h] [ebp-78h]
  float v14;            // [esp+58h] [ebp-70h]
  float *apos1;         // [esp+5Ch] [ebp-6Ch]
  float *apos2;         // [esp+68h] [ebp-60h]
  float *apos3;         // [esp+6Ch] [ebp-5Ch]
  trajectory_t v18;     // [esp+74h] [ebp-54h] BYREF
  float v19;            // [esp+98h] [ebp-30h] BYREF
  float v20;            // [esp+9Ch] [ebp-2Ch]
  float v21;            // [esp+A0h] [ebp-28h]
  float v22;            // [esp+A4h] [ebp-24h] BYREF
  float v23;            // [esp+A8h] [ebp-20h] BYREF
  float v24[7];         // [esp+ACh] [ebp-1Ch] BYREF

  if (a1.classnum) {
    Scr_ObjectError("not an entity");
    v1 = 0;
  } else {
    v1 = &g_entities + a1.entnum;
    v2 = *(_WORD *)v1->classname;
    if (v2 != word_195B0C2 && v2 != word_195B0C4 && v2 != word_195B0C6) {
      v3 = (const char *)va("entity %i is not a script_brushmodel, "
                            "script_model, or script_origin",
                            a1.entnum);
      Scr_ObjectError(v3);
    }
  }
  Scr_GetVector(0, &v19);
  ScriptEntCmdGetCommandTimes(v24, &v23, &v22);
  v14 = v22;
  v4 = v23;
  v5 = v24[0];
  apos3 = v1->unnamed_field.mover.apos3;
  apos2 = v1->unnamed_field.mover.apos2;
  apos1 = v1->unnamed_field.mover.apos1;
  p_accumulate = (float *)&v1->unnamed_field.trigger.accumulate;
  p_aMidTime = (float *)&v1->unnamed_field.mover.aMidTime;
  currentAngles = v1->r.currentAngles;
  apos = v1->s.apos;
  if (*(_DWORD *)v1->s.apos) {
    v11 = v24[0];
    v10 = v23;
    BG_EvaluateTrajectory((const trajectory_t *)v1->s.apos, dword_193466C,
                          v1->r.currentAngles);
    v4 = v10;
    v5 = v11;
  }
  if (v4 == 0.0 && v14 == 0.0) {
    *(_DWORD *)&v1->s.apos[4] = dword_193466C;
    *(_DWORD *)&v1->s.apos[8] = (int)(float)(v5 * 1000.0);
    *(float *)&v1->unnamed_field.mover.aMidTime = v5;
    v1->unnamed_field.trigger.accumulate = 0;
    *(float *)&v1->s.apos[12] = v1->r.currentAngles[0];
    *(float *)&v1->s.apos[16] = v1->r.currentAngles[1];
    *(float *)&v1->s.apos[20] = v1->r.currentAngles[2];
    *(float *)&v1->s.apos[24] = v19;
    *(float *)&v1->s.apos[28] = v20;
    *(float *)&v1->s.apos[32] = v21;
    *(_DWORD *)v1->s.apos = 3;
    BG_EvaluateTrajectory((const trajectory_t *)v1->s.apos, dword_193466C,
                          v1->r.currentAngles);
    BG_EvaluateTrajectory((const trajectory_t *)v1->s.apos,
                          *(_DWORD *)&v1->s.apos[8] + dword_193466C, apos3);
    return SV_LinkEntity(v1);
  } else {
    *p_aMidTime = (float)(v5 - v4) - v14;
    *p_accumulate = v14;
    v1->unnamed_field.mover.aSpeed = fsqrt(
        (float)((float)(v19 * v19) + (float)(v20 * v20)) + (float)(v21 * v21));
    if (v4 == 0.0) {
      *apos1 = *currentAngles;
      v1->unnamed_field.mover.apos1[1] = v1->r.currentAngles[1];
      v1->unnamed_field.mover.apos1[2] = v1->r.currentAngles[2];
      if (*p_aMidTime == 0.0) {
        *(_DWORD *)&v1->s.apos[4] = dword_193466C;
        *(_DWORD *)&v1->s.apos[8] = (int)(float)(1000.0 * *p_accumulate);
        *(float *)&v1->s.apos[12] = *currentAngles;
        *(float *)&v1->s.apos[16] = v1->r.currentAngles[1];
        *(float *)&v1->s.apos[20] = v1->r.currentAngles[2];
        *(float *)&v1->s.apos[24] = v19;
        *(float *)&v1->s.apos[28] = v20;
        *(float *)&v1->s.apos[32] = v21;
        *(_DWORD *)apos = 8;
      } else {
        *(_DWORD *)&v1->s.apos[4] = dword_193466C;
        *(_DWORD *)&v1->s.apos[8] = (int)(float)(1000.0 * *p_aMidTime);
        *(float *)&v1->s.apos[12] = *currentAngles;
        *(float *)&v1->s.apos[16] = v1->r.currentAngles[1];
        *(float *)&v1->s.apos[20] = v1->r.currentAngles[2];
        *(float *)&v1->s.apos[24] = v19;
        *(float *)&v1->s.apos[28] = v20;
        *(float *)&v1->s.apos[32] = v21;
        *(_DWORD *)apos = 3;
      }
    } else {
      *(_DWORD *)&v1->s.apos[4] = dword_193466C;
      *(_DWORD *)&v1->s.apos[8] = (int)(float)(v4 * 1000.0);
      *(float *)&v1->s.apos[12] = *currentAngles;
      *(float *)&v1->s.apos[16] = v1->r.currentAngles[1];
      *(float *)&v1->s.apos[20] = v1->r.currentAngles[2];
      *(float *)&v1->s.apos[24] = v19;
      *(float *)&v1->s.apos[28] = v20;
      *(float *)&v1->s.apos[32] = v21;
      *(_DWORD *)apos = 7;
      BG_EvaluateTrajectory((const trajectory_t *)v1->s.apos,
                            *(_DWORD *)&v1->s.apos[8] + dword_193466C, apos1);
    }
    v8 = *p_aMidTime;
    *apos2 = (float)(*p_aMidTime * v19) + *apos1;
    v1->unnamed_field.mover.apos2[1] =
        (float)(v8 * v20) + v1->unnamed_field.mover.apos1[1];
    v1->unnamed_field.mover.apos2[2] =
        (float)(v8 * v21) + v1->unnamed_field.mover.apos1[2];
    if (*p_accumulate == 0.0) {
      *apos3 = *apos2;
      v1->unnamed_field.mover.apos3[1] = v1->unnamed_field.mover.apos2[1];
      v1->unnamed_field.mover.apos3[2] = v1->unnamed_field.mover.apos2[2];
    } else {
      v18.trType = 8;
      v18.trTime = dword_193466C;
      v18.trDuration = (int)(float)(1000.0 * *p_accumulate);
      v18.trBase[0] = *apos2;
      v18.trBase[1] = v1->unnamed_field.mover.apos2[1];
      v18.trBase[2] = v1->unnamed_field.mover.apos2[2];
      v18.trDelta[0] = v19;
      v18.trDelta[1] = v20;
      v18.trDelta[2] = v21;
      BG_EvaluateTrajectory(&v18, dword_193466C + v18.trDuration, apos3);
    }
    BG_EvaluateTrajectory((const trajectory_t *)v1->s.apos, dword_193466C,
                          v1->r.currentAngles);
    return SV_LinkEntity(v1);
  }
}

void __cdecl ScriptEnt_RotateAxis(struct scr_entref_t entref, int iAxis) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_RotateTo(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEnt_MoveAxis(struct scr_entref_t entref, int iAxis) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_GravityMove(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_MoveTo(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_RotateRoll(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_RotateYaw(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_RotatePitch(struct scr_entref_t entref) {
  UNIMPLEMENTED();
}

void __cdecl ScriptEntCmd_MoveZ(struct scr_entref_t entref) { UNIMPLEMENTED(); }

void __cdecl ScriptEntCmd_MoveY(struct scr_entref_t entref) { UNIMPLEMENTED(); }

void __cdecl ScriptEntCmd_MoveX(struct scr_entref_t entref) { UNIMPLEMENTED(); }

void __cdecl SP_script_model(struct gentity_s *pSelf) { UNIMPLEMENTED(); }

void __cdecl Reached_ScriptMover(struct gentity_s *pEnt) {
  char **result; // eax
  float aSpeed;  // xmm0_4
  int v3;        // ebx
  float speed;   // xmm0_4
  int v5;        // ebx

  result = (char **)a1;
  if (a1->s.pos.trType) {
    if ((signed int)(a1->s.pos.trDuration + a1->s.pos.trTime) <=
            dword_193466C &&
        (speed = a1->unnamed_field.mover.speed,
         v5 = ScriptMover_Updatemove(
             &a1->s.pos, a1->unnamed_field.mover.pos1, speed,
             *(float *)&a1->unnamed_field.mover.midTime,
             *(float *)&a1->unnamed_field.item.count2,
             (trajectory_t *)&a1->unnamed_field.grenade + 1,
             a1->unnamed_field.mover.pos3),
         BG_EvaluateTrajectory(&a1->s.pos, dword_193466C, a1->r.currentOrigin),
         SV_LinkEntity(a1), v5)) {
      Scr_Notify(speed, a1, word_195B0A8, 0);
      result = (char **)a1;
    } else {
      result = (char **)a1;
    }
  }
  if (result[12]) {
    result = (char **)&result[13][(_DWORD)result[14]];
    if ((int)result <= dword_193466C) {
      aSpeed = a1->unnamed_field.mover.aSpeed;
      v3 = ScriptMover_Updatemove(
          (trajectory_t *)a1->s.apos, a1->unnamed_field.mover.apos1, aSpeed,
          *(float *)&a1->unnamed_field.mover.aMidTime,
          *(float *)&a1->unnamed_field.trigger.accumulate,
          (trajectory_t *)&a1->unnamed_field.grenade + 2,
          a1->unnamed_field.mover.apos3);
      BG_EvaluateTrajectory((const trajectory_t *)a1->s.apos, dword_193466C,
                            a1->r.currentAngles);
      result = (char **)SV_LinkEntity(a1);
      if (v3) {
        a1->r.currentAngles[0] = AngleNormalize180(a1->r.currentAngles[0]);
        a1->r.currentAngles[1] = AngleNormalize360(a1->r.currentAngles[1]);
        a1->r.currentAngles[2] = AngleNormalize180(a1->r.currentAngles[2]);
        return Scr_Notify(aSpeed, a1, word_195B0C0, 0);
      }
    }
  }
  return result;
}

void __cdecl ScriptMover_SetupMoveSpeed(struct trajectory_t *,
                                        float const *const, float, float, float,
                                        float *const, float *, float *, float *,
                                        float *const, float *const,
                                        float *const) {
  UNIMPLEMENTED();
}

void __cdecl ScriptMover_SetupMove(struct trajectory_t *, float const *const,
                                   float, float, float, float *const, float *,
                                   float *, float *, float *const, float *const,
                                   float *const) {
  UNIMPLEMENTED();
}

int __cdecl ScriptMover_Updatemove(struct trajectory_t *, float *const, float,
                                   float, float, float const *const,
                                   float const *const, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl ScriptMover_RotateSpeed(struct gentity_s *, float const *const,
                                     float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl ScriptMover_Rotate(struct gentity_s *, float const *const, float,
                                float, float) {
  UNIMPLEMENTED();
}

void __cdecl ScriptMover_GravityMove(struct gentity_s *, float const *const,
                                     float) {
  UNIMPLEMENTED();
}

void __cdecl ScriptMover_Move(struct gentity_s *, float const *const, float,
                              float, float) {
  UNIMPLEMENTED();
}
