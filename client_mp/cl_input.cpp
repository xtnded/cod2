void __cdecl CL_ClearKeys(void) { UNIMPLEMENTED(); }

void __cdecl CL_ShutdownInput() {
  Cmd_RemoveCommand("centerview");
  Cmd_RemoveCommand("+moveup");
  Cmd_RemoveCommand("-moveup");
  Cmd_RemoveCommand("+movedown");
  Cmd_RemoveCommand("-movedown");
  Cmd_RemoveCommand("+left");
  Cmd_RemoveCommand("-left");
  Cmd_RemoveCommand("+right");
  Cmd_RemoveCommand("-right");
  Cmd_RemoveCommand("+forward");
  Cmd_RemoveCommand("-forward");
  Cmd_RemoveCommand("+back");
  Cmd_RemoveCommand("-back");
  Cmd_RemoveCommand("+lookup");
  Cmd_RemoveCommand("-lookup");
  Cmd_RemoveCommand("+lookdown");
  Cmd_RemoveCommand("-lookdown");
  Cmd_RemoveCommand("+strafe");
  Cmd_RemoveCommand("-strafe");
  Cmd_RemoveCommand("+moveleft");
  Cmd_RemoveCommand("-moveleft");
  Cmd_RemoveCommand("+moveright");
  Cmd_RemoveCommand("-moveright");
  Cmd_RemoveCommand("+speed");
  Cmd_RemoveCommand("-speed");
  Cmd_RemoveCommand("+attack");
  Cmd_RemoveCommand("-attack");
  Cmd_RemoveCommand("+melee");
  Cmd_RemoveCommand("-melee");
  Cmd_RemoveCommand("+holdbreath");
  Cmd_RemoveCommand("-holdbreath");
  Cmd_RemoveCommand("+melee_breath");
  Cmd_RemoveCommand("-melee_breath");
  Cmd_RemoveCommand("+frag");
  Cmd_RemoveCommand("-frag");
  Cmd_RemoveCommand("+smoke");
  Cmd_RemoveCommand("-smoke");
  Cmd_RemoveCommand("+binoculars");
  Cmd_RemoveCommand("-binoculars");
  Cmd_RemoveCommand("+breath_binoculars");
  Cmd_RemoveCommand("-breath_binoculars");
  Cmd_RemoveCommand("+activate");
  Cmd_RemoveCommand("-activate");
  Cmd_RemoveCommand("+reload");
  Cmd_RemoveCommand("-reload");
  Cmd_RemoveCommand("+usereload");
  Cmd_RemoveCommand("-usereload");
  Cmd_RemoveCommand("+leanleft");
  Cmd_RemoveCommand("-leanleft");
  Cmd_RemoveCommand("+leanright");
  Cmd_RemoveCommand("-leanright");
  Cmd_RemoveCommand("+prone");
  Cmd_RemoveCommand("-prone");
  Cmd_RemoveCommand("+stance");
  Cmd_RemoveCommand("-stance");
  Cmd_RemoveCommand("+mlook");
  Cmd_RemoveCommand("-mlook");
  Cmd_RemoveCommand("toggleads");
  Cmd_RemoveCommand("leaveads");
  Cmd_RemoveCommand("lowerstance");
  Cmd_RemoveCommand("raisestance");
  Cmd_RemoveCommand("togglecrouch");
  Cmd_RemoveCommand("toggleprone");
  Cmd_RemoveCommand("goprone");
  Cmd_RemoveCommand("gocrouch");
  Cmd_RemoveCommand("+gostand");
  Cmd_RemoveCommand("-gostand");
  Cmd_RemoveCommand("+talk");
  Cmd_RemoveCommand("-talk");
}

void __cdecl CL_FinishMove(struct usercmd_s *) { UNIMPLEMENTED(); }

void __cdecl CL_UpdateCmdButton(int *, int, int) { UNIMPLEMENTED(); }

void __cdecl CL_MouseEvent(int dx, int dy) {
  _DWORD *v2;        // edx
  signed int result; // eax

  v2 = cl;
  if ((*((_BYTE *)cl + 4) & 8) != 0 && !*(_BYTE *)(cl_bypassMouseInput + 8))
    return UI_MouseEvent(a1, a2);
  result = *((_DWORD *)cl + 8570);
  *((_DWORD *)cl + result + 8566) += a1;
  v2[result + 8568] += a2;
  return result;
}

void __cdecl CL_StanceButtonUpdate(void) { UNIMPLEMENTED(); }

void __cdecl IN_GoCrouch() { UNIMPLEMENTED(); }

void __cdecl IN_GoProne() { UNIMPLEMENTED(); }

void __cdecl IN_ToggleProne() { UNIMPLEMENTED(); }

void __cdecl IN_ToggleCrouch() { UNIMPLEMENTED(); }

void __cdecl IN_RaiseStance() { UNIMPLEMENTED(); }

void __cdecl IN_LowerStance() { UNIMPLEMENTED(); }

void __cdecl IN_LeaveADS() { UNIMPLEMENTED(); }

void __cdecl IN_ToggleADS() { UNIMPLEMENTED(); }

void __cdecl IN_CenterView() { UNIMPLEMENTED(); }

void __cdecl IN_Stance_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Stance_Down() { UNIMPLEMENTED(); }

void __cdecl CL_SetTempStanceStatus(void) { UNIMPLEMENTED(); }

float __cdecl CL_KeyState(struct kbutton_t *) { UNIMPLEMENTED(); }

void __cdecl IN_KeyUp(struct kbutton_t *b) {
  const gentity_s *result; // eax
  const char *v2;          // eax
  int v3;                  // eax

  result = Cmd_Argv(1);
  if (!LOBYTE(result->s.number)) {
    a1->down = 0;
    a1->active = 0;
    return result;
  }
  result = (const gentity_s *)atoi((const char *)result);
  if (result == (const gentity_s *)LODWORD(a1->down)) {
    LODWORD(a1->down) = 0;
  } else {
    if (result != (const gentity_s *)HIDWORD(a1->down))
      return result;
    HIDWORD(a1->down) = 0;
  }
  if (!LODWORD(a1->down)) {
    result = (const gentity_s *)HIDWORD(a1->down);
    if (!result) {
      a1->active = 0;
      v2 = (const char *)Cmd_Argv(2);
      v3 = atoi(v2);
      if (v3) {
        result = (const gentity_s *)(v3 - a1->downtime);
        a1->msec += (int32_t)result;
      } else {
        result = (const gentity_s *)((unsigned int)frame_msec >> 1);
        a1->msec += (unsigned int)frame_msec >> 1;
      }
      a1->active = 0;
    }
  }
  return result;
}

void __cdecl IN_MLookUp() { UNIMPLEMENTED(); }

void __cdecl IN_MLookDown() { UNIMPLEMENTED(); }

void __cdecl IN_SwitchToLocalClient(int) { UNIMPLEMENTED(); }

void __cdecl CL_CmdButtons(struct usercmd_s *cmd) {
  int32_t *p_buttons; // esi
  kbutton_t *v2;      // edx
  char *v3;           // eax
  _DWORD *v4;         // eax
  int result;         // eax

  p_buttons = &a1->buttons;
  v2 = kb;
  v3 = (char *)&kb[15].downtime + 2;
  if (LOWORD(kb[16].downtime))
    a1->buttons |= 1u;
  v3[17] = 0;
  if (HIWORD(v2[17].downtime))
    a1->buttons |= 0x8000u;
  HIBYTE(v2[17].downtime) = 0;
  if (LOWORD(v2[18].msec))
    a1->buttons |= 0x10000u;
  BYTE1(v2[18].msec) = 0;
  if (HIWORD(v2[19].msec))
    a1->buttons |= 0x20000u;
  HIBYTE(v2[19].msec) = 0;
  if (*(_WORD *)&v2[20].active)
    a1->buttons |= 0x4000u;
  v2[20].wasPressed = 0;
  if (LOWORD(v2[22].down))
    a1->buttons |= 4u;
  BYTE1(v2[22].down) = 0;
  if (WORD1(v2[23].down))
    a1->buttons |= 8u;
  BYTE3(v2[23].down) = 0;
  if (WORD2(v2[24].down))
    a1->buttons |= 0x10u;
  BYTE5(v2[24].down) = 0;
  if (HIWORD(v2[25].down))
    a1->buttons |= 0x20u;
  HIBYTE(v2[25].down) = 0;
  if (LOWORD(v2[26].downtime))
    a1->buttons |= 0x40u;
  BYTE1(v2[26].downtime) = 0;
  if (HIWORD(v2[27].downtime))
    *p_buttons |= 0x80u;
  HIBYTE(v2[27].downtime) = 0;
  if (LOWORD(v2[28].msec))
    *p_buttons |= 0x100u;
  BYTE1(v2[28].msec) = 0;
  if (HIWORD(v2[29].msec))
    *p_buttons |= 0x200u;
  HIBYTE(v2[29].msec) = 0;
  if (LOWORD(v2[12].down))
    *p_buttons |= 0x400u;
  BYTE1(v2[12].down) = 0;
  v4 = cl;
  if (*((_DWORD *)cl + 1)) {
    if (!*(_BYTE *)(cl_bypassMouseInput + 8))
      a1->buttons |= 0x40000u;
    v4 = cl;
  }
  if ((unsigned int)(v4[14] - 2) <= 2) {
    if (WORD2(v2[14].down))
      *p_buttons |= 0x400u;
    BYTE5(v2[14].down) = 0;
  }
  result = *((_DWORD *)cl + 8576);
  if (result)
    a1->buttons |= 0x800u;
  return result;
}

void __cdecl CL_KeyMove(struct usercmd_s *cmd) {
  kbutton_t *v1;     // ebx
  int32_t buttons;   // edx
  char *v3;          // ecx
  usercmd_s *v4;     // ebx
  kbutton_t *v5;     // edi
  int v6;            // esi
  int v7;            // ecx
  int down_high;     // ebx
  float v9;          // xmm0_4
  int v10;           // esi
  int v11;           // ecx
  int v12;           // ebx
  float v13;         // xmm0_4
  int v14;           // ecx
  int32_t v15;       // ebx
  float v16;         // xmm0_4
  int v17;           // esi
  int down;          // ecx
  int v19;           // ebx
  float v20;         // xmm0_4
  float v21;         // xmm0_4
  int result;        // eax
  int v23;           // ecx
  int v24;           // ebx
  float v25;         // xmm0_4
  float v26;         // xmm0_4
  int v27;           // ebx
  int msec;          // ecx
  uint32_t downtime; // edx
  float v30;         // xmm0_4
  float v31;         // xmm0_4
  int v32;           // eax
  float v33;         // xmm0_4
  float v34;         // xmm0_4
  float v35;         // xmm0_4
  int v36;           // [esp+2Ch] [ebp-1Ch]

  v1 = kb;
  if (LOBYTE(kb[28].msec)) {
    buttons = a1->buttons;
    BYTE1(buttons) = BYTE1(buttons) & 0xFC | 1;
    a1->buttons = buttons;
  } else {
    if (!BYTE2(kb[13].down)) {
      if (*((_BYTE *)cl + 34284) && com_frameTime - *((_DWORD *)cl + 8573) >=
                                        *(_DWORD *)(cl_stanceHoldTime + 8)) {
        if (*((_DWORD *)cl + 8572) == 2)
          *(_DWORD *)(legacyHacks + 8) = 0;
        else
          *(_DWORD *)(legacyHacks + 8) = 2;
        *((_BYTE *)cl + 34284) = 0;
      }
      v32 = *(_DWORD *)(legacyHacks + 8);
      if (v32 == 1) {
        buttons = a1->buttons;
        BYTE1(buttons) = BYTE1(buttons) & 0xFC | 2;
        a1->buttons = buttons;
      } else {
        buttons = a1->buttons;
        if (v32 == 2)
          BYTE1(buttons) = BYTE1(buttons) & 0xFC | 1;
        else
          BYTE1(buttons) &= 0xFCu;
        a1->buttons = buttons;
      }
      BYTE1(buttons) &= ~0x20u;
      a1->buttons = buttons;
      v3 = (char *)cl;
      if ((*((_BYTE *)cl + 11) == 0) != v1[10].active)
        goto LABEL_6;
    LABEL_67:
      v4 = a1;
      goto LABEL_8;
    }
    buttons = a1->buttons;
    BYTE1(buttons) = BYTE1(buttons) & 0xFC | 2;
    a1->buttons = buttons;
  }
  BYTE1(buttons) |= 0x20u;
  a1->buttons = buttons;
  v3 = (char *)cl;
  if ((*((_BYTE *)cl + 11) == 0) == v1[10].active)
    goto LABEL_67;
LABEL_6:
  if (!PM_IsBinocularsADS((const playerState_s *)(v3 + 52))) {
    a1->buttons &= ~0x1000u;
    v5 = kb;
    if (!BYTE2(kb[9].msec))
      goto LABEL_9;
    goto LABEL_42;
  }
  buttons = a1->buttons;
  v4 = a1;
LABEL_8:
  BYTE1(buttons) |= 0x10u;
  v4->buttons = buttons;
  v5 = kb;
  if (!BYTE2(kb[9].msec)) {
  LABEL_9:
    v6 = 0;
    goto LABEL_10;
  }
LABEL_42:
  v23 = *(int32_t *)((char *)&v5[1].msec + 2);
  *(int32_t *)((char *)&v5[1].msec + 2) = 0;
  if (LOBYTE(v5[2].down)) {
    v24 = *(uint32_t *)((char *)&v5[1].downtime + 2);
    if (v24)
      v23 += com_frameTime - v24;
    else
      v23 = com_frameTime;
    *(uint32_t *)((char *)&v5[1].downtime + 2) = com_frameTime;
  }
  v25 = 0.0;
  if (v23 > 0) {
    if (v23 >= (unsigned int)frame_msec) {
      v25 = 127.0;
    } else {
      if (frame_msec < 0)
        v26 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
              (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
      else
        v26 = (float)frame_msec;
      v25 = (float)((float)v23 / v26) * 127.0;
    }
  }
  v27 = (int)v25;
  msec = v5->msec;
  v5->msec = 0;
  if (v5->active) {
    downtime = v5->downtime;
    if (downtime)
      msec += com_frameTime - downtime;
    else
      msec = com_frameTime;
    v5->downtime = com_frameTime;
  }
  v30 = 0.0;
  if (msec <= 0)
    goto LABEL_60;
  if (msec < (unsigned int)frame_msec) {
    if (frame_msec < 0)
      v31 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
            (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
    else
      v31 = (float)frame_msec;
    v30 = (float)((float)msec / v31) * 127.0;
  LABEL_60:
    v6 = v27 - (int)v30;
    goto LABEL_10;
  }
  v6 = v27 - (int)127.0;
LABEL_10:
  v7 = v5[8].downtime;
  v5[8].downtime = 0;
  if (LOBYTE(v5[8].msec)) {
    down_high = HIDWORD(v5[8].down);
    if (down_high)
      v7 += com_frameTime - down_high;
    else
      v7 = com_frameTime;
    HIDWORD(v5[8].down) = com_frameTime;
  }
  v9 = 0.0;
  if (v7 > 0) {
    if (v7 < (unsigned int)frame_msec) {
      if (frame_msec < 0)
        v33 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
              (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
      else
        v33 = (float)frame_msec;
      v9 = (float)((float)v7 / v33) * 127.0;
    } else {
      v9 = 127.0;
    }
  }
  v10 = (int)v9 + v6;
  v11 = *(_DWORD *)((char *)&v5[7].down + 6);
  *(_DWORD *)((char *)&v5[7].down + 6) = 0;
  if (BYTE2(v5[7].downtime)) {
    v12 = *(_DWORD *)((char *)&v5[7].down + 2);
    if (v12)
      v11 += com_frameTime - v12;
    else
      v11 = com_frameTime;
    *(_DWORD *)((char *)&v5[7].down + 2) = com_frameTime;
  }
  v13 = 0.0;
  if (v11 > 0) {
    if (v11 < (unsigned int)frame_msec) {
      if (frame_msec < 0)
        v34 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
              (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
      else
        v34 = (float)frame_msec;
      v13 = (float)((float)v11 / v34) * 127.0;
    } else {
      v13 = 127.0;
    }
  }
  v36 = v10 - (int)v13;
  v14 = *(_DWORD *)&v5[2].active;
  *(_DWORD *)&v5[2].active = 0;
  if (BYTE2(v5[3].down)) {
    v15 = v5[2].msec;
    if (v15)
      v14 += com_frameTime - v15;
    else
      v14 = com_frameTime;
    v5[2].msec = com_frameTime;
  }
  v16 = 0.0;
  if (v14 > 0) {
    if (v14 < (unsigned int)frame_msec) {
      if (frame_msec < 0)
        v35 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
              (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
      else
        v35 = (float)frame_msec;
      v16 = (float)((float)v14 / v35) * 127.0;
    } else {
      v16 = 127.0;
    }
  }
  v17 = (int)v16;
  down = v5[4].down;
  LODWORD(v5[4].down) = 0;
  if (BYTE4(v5[4].down)) {
    v19 = *(int32_t *)((char *)&v5[3].msec + 2);
    if (v19)
      down += com_frameTime - v19;
    else
      down = com_frameTime;
    *(int32_t *)((char *)&v5[3].msec + 2) = com_frameTime;
  }
  v20 = 0.0;
  if (down > 0) {
    if (down >= (unsigned int)frame_msec) {
      v20 = 127.0;
    } else {
      if (frame_msec < 0)
        v21 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
              (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
      else
        v21 = (float)frame_msec;
      v20 = (float)((float)down / v21) * 127.0;
    }
  }
  a1->forwardmove = ClampChar(v17 - (int)v20);
  result = ClampChar(v36);
  a1->rightmove = result;
  return result;
}

void __cdecl CL_AdjustAngles() { UNIMPLEMENTED(); }

void __cdecl IN_ToggleSpec_Up(void) { UNIMPLEMENTED(); }

void __cdecl IN_SpecNext_Up(void) { UNIMPLEMENTED(); }

void __cdecl IN_GoStandUp() { UNIMPLEMENTED(); }

void __cdecl IN_Crouch_Up(void) { UNIMPLEMENTED(); }

void __cdecl IN_Prone_Up() {
  int result; // eax

  IN_KeyUp((kbutton_t *)((char *)kb + 500));
  if (LOBYTE(kb[28].msec) || BYTE2(kb[13].down)) {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 1;
  } else {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 0;
  }
  return result;
}

void __cdecl IN_LeanRight_Up() { UNIMPLEMENTED(); }

void __cdecl IN_LeanLeft_Up() { UNIMPLEMENTED(); }

void __cdecl IN_UseReload_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Reload_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Activate_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Melee_Up() { UNIMPLEMENTED(); }

void __cdecl IN_BreathBinoculars_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Binoculars_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Smoke_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Frag_Up() { UNIMPLEMENTED(); }

void __cdecl IN_MeleeBreath_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Breath_Up() { UNIMPLEMENTED(); }

void __cdecl IN_Attack_Up() { UNIMPLEMENTED(); }

void __cdecl IN_StrafeUp() { UNIMPLEMENTED(); }

void __cdecl IN_SpeedUp() { UNIMPLEMENTED(); }

void __cdecl IN_MoverightUp() { UNIMPLEMENTED(); }

void __cdecl IN_MoveleftUp() { UNIMPLEMENTED(); }

void __cdecl IN_LookdownUp() { UNIMPLEMENTED(); }

void __cdecl IN_LookupUp() { UNIMPLEMENTED(); }

void __cdecl IN_BackUp() { UNIMPLEMENTED(); }

void __cdecl IN_ForwardUp() { return IN_KeyUp((kbutton_t *)((char *)kb + 40)); }

void __cdecl IN_RightUp() { UNIMPLEMENTED(); }

void __cdecl IN_LeftUp() { UNIMPLEMENTED(); }

void __cdecl IN_DownUp() {
  int result; // eax

  IN_KeyUp((kbutton_t *)((char *)kb + 220));
  if (LOBYTE(kb[28].msec) || BYTE2(kb[13].down)) {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 1;
  } else {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 0;
  }
  return result;
}

void __cdecl IN_UpUp() { UNIMPLEMENTED(); }

void __cdecl CL_WritePacket() { UNIMPLEMENTED(); }

void __cdecl CL_MouseMove(struct usercmd_s *cmd) {
  float v3;   // xmm3_4
  _DWORD *v4; // eax
  int v5;     // edx
  int v6;     // edx
  float v7;   // xmm1_4
  float v8;   // xmm0_4
  float v9;   // xmm0_4
  float v10;  // xmm2_4
  float *v11; // edx
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  float v15;  // xmm1_4
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  float v18;  // xmm2_4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  float v23;  // xmm1_4
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  float v27;  // xmm2_4
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm1

  if (*(_BYTE *)(m_filter + 8)) {
    a2.f32[0] = (float)(*((_DWORD *)cl + 8567) + *((_DWORD *)cl + 8566)) * 0.5;
    v3 = (float)(*((_DWORD *)cl + 8569) + *((_DWORD *)cl + 8568)) * 0.5;
    v4 = cl;
  } else {
    v4 = cl;
    v6 = *((_DWORD *)cl + 8570);
    a2.f32[0] = (float)*((int *)cl + v6 + 8566);
    v3 = (float)*((int *)cl + v6 + 8568);
  }
  v5 = v4[8570] ^ 1;
  v4[8570] = v5;
  v4[v5 + 8566] = 0;
  v4[v5 + 8568] = 0;
  if (frame_msec) {
    v7 = fsqrt((float)(a2.f32[0] * a2.f32[0]) + (float)(v3 * v3));
    if (frame_msec < 0)
      v8 = (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
           (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
    else
      v8 = (float)frame_msec;
    v9 = v7 / v8;
    v10 = (float)((float)(v9 * *(float *)(cl_mouseAccel + 8)) +
                  *(float *)(cl_sensitivity + 8)) *
          *((float *)cl + 8577);
    if (v9 == 0.0) {
      v11 = (float *)cl;
    } else {
      if (*(_BYTE *)(cl_showMouseRate + 8)) {
        Com_Printf("%f : %f\n", v9, v10);
        a2 = (__m128)a2.u32[0];
        a1 = (__m128)LODWORD(v3);
      }
      v11 = (float *)cl;
    }
    if (*((__int16 *)v11 + 32) >= 0) {
      v12 = a2;
      if (((_DWORD)v11[53] & 0x300) != 0) {
        v12.f32[0] = a2.f32[0] * 2.5;
        a1.f32[0] = v3 + v3;
      } else {
        v12.f32[0] = a2.f32[0] * v10;
        a1.f32[0] = v3 * v10;
      }
      v13.i32[0] = 0;
      if (v12.f32[0] != 0.0 || a1.f32[0] != 0.0) {
        if (BYTE2(kb[9].msec)) {
          a3->rightmove =
              ClampChar((int)(float)(v12.f32[0] * *(float *)(m_side + 8)) +
                        a3->rightmove);
          a1 = (__m128)a1.u32[0];
        } else {
          v14 = v12;
          v14.f32[0] = v12.f32[0] * *(float *)(m_yaw + 8);
          v15 = v11[8579];
          if (v15 != 0.0) {
            if (frame_msec < 0)
              v12.f32[0] =
                  (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
                  (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
            else
              v12.f32[0] = (float)frame_msec;
            v12.f32[0] = (float)(v12.f32[0] * v15) * 0.001;
            v16 = v14;
            v16.f32[0] = v14.f32[0] - v12.f32[0];
            v17 = _mm_cmplt_ss(v16, v13);
            LODWORD(v18) =
                _mm_andnot_ps(v17, v12).u32[0] | v14.i32[0] & v17.i32[0];
            v19 = _mm_xor_ps(v12, (__m128)xmmword_302D40);
            v20 = v19;
            v20.f32[0] = v19.f32[0] - v18;
            v21 = _mm_cmplt_ss(v20, v13);
            v14.i32[0] =
                _mm_andnot_ps(v21, v19).u32[0] | LODWORD(v18) & v21.i32[0];
          }
          v12 = (__m128) * ((unsigned int *)v11 + 8584);
          v11[8584] = v12.f32[0] - v14.f32[0];
        }
        if ((BYTE6(kb[15].down) || *(_BYTE *)(cl_freelook + 8)) &&
            !BYTE2(kb[9].msec)) {
          v22 = a1;
          v22.f32[0] = a1.f32[0] * *(float *)(m_pitch + 8);
          v23 = *((float *)cl + 8578);
          v24.i32[0] = 0;
          if (v23 != 0.0) {
            if (frame_msec < 0)
              v12.f32[0] =
                  (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1)) +
                  (float)(frame_msec & 1 | ((unsigned int)frame_msec >> 1));
            else
              v12.f32[0] = (float)frame_msec;
            v12.f32[0] = (float)(v12.f32[0] * v23) * 0.001;
            v25 = v22;
            v25.f32[0] = v22.f32[0] - v12.f32[0];
            v26 = _mm_cmplt_ss(v25, v24);
            LODWORD(v27) =
                _mm_andnot_ps(v26, v12).u32[0] | v22.i32[0] & v26.i32[0];
            v28 = _mm_xor_ps(v12, (__m128)xmmword_302D40);
            v29 = v28;
            v29.f32[0] = v28.f32[0] - v27;
            v30 = _mm_cmplt_ss(v29, v24);
            v22.i32[0] =
                _mm_andnot_ps(v30, v28).u32[0] | LODWORD(v27) & v30.i32[0];
          }
          *((float *)cl + 8583) = v22.f32[0] + *((float *)cl + 8583);
        } else {
          a3->forwardmove =
              ClampChar(a3->forwardmove -
                        (int)(float)(a1.f32[0] * *(float *)(m_forward + 8)));
        }
      }
    }
  }
}

void __cdecl IN_KeyDown(struct kbutton_t *b) {
  const char *v1; // eax
  int v2;         // eax
  int down_high;  // ecx
  const char *v4; // eax

  v1 = (const char *)Cmd_Argv(1);
  if (*v1)
    v2 = atoi(v1);
  else
    v2 = -1;
  if (v2 != LODWORD(a1->down)) {
    down_high = HIDWORD(a1->down);
    if (v2 != down_high) {
      if (LODWORD(a1->down)) {
        if (down_high) {
          Com_Printf("Three keys down for a button!\n");
          return;
        }
        HIDWORD(a1->down) = v2;
      } else {
        LODWORD(a1->down) = v2;
      }
      if (!a1->active) {
        v4 = (const char *)Cmd_Argv(2);
        a1->downtime = atoi(v4);
        a1->active = 1;
        a1->wasPressed = 1;
      }
    }
  }
}

void __cdecl IN_ToggleSpec_Down(void) { UNIMPLEMENTED(); }

void __cdecl IN_SpecNext_Down(void) { UNIMPLEMENTED(); }

void __cdecl IN_GoStandDown() {
  IN_KeyDown((kbutton_t *)((char *)kb + 240));
  if (*(_DWORD *)(legacyHacks + 8)) {
    if (!LOBYTE(kb[28].msec) && !BYTE2(kb[13].down))
      *(_DWORD *)(legacyHacks + 8) = 0;
  } else {
    IN_KeyDown((kbutton_t *)((char *)kb + 200));
  }
}

void __cdecl IN_Crouch_Down(void) { UNIMPLEMENTED(); }

void __cdecl IN_Prone_Down() {
  int result; // eax

  IN_KeyDown((kbutton_t *)((char *)kb + 500));
  if (LOBYTE(kb[28].msec) || BYTE2(kb[13].down)) {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 1;
  } else {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 0;
  }
  return result;
}

void __cdecl IN_LeanRight_Down() {
  return IN_KeyDown((kbutton_t *)((char *)kb + 480));
}

void __cdecl IN_LeanLeft_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 460)); }

void __cdecl IN_UseReload_Down() {
  IN_KeyDown((kbutton_t *)((char *)kb + 440));
}

void __cdecl IN_Reload_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 420)); }

void __cdecl IN_Activate_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 400)); }

void __cdecl IN_Melee_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 380)); }

void __cdecl IN_BreathBinoculars_Down() {
  IN_KeyDown((kbutton_t *)((char *)kb + 300));
  return IN_KeyDown(kb + 20);
}

void __cdecl IN_Binoculars_Down() { IN_KeyDown(kb + 20); }

void __cdecl IN_Smoke_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 340)); }

void __cdecl IN_Frag_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 320)); }

void __cdecl IN_MeleeBreath_Down() {
  IN_KeyDown((kbutton_t *)((char *)kb + 380));
  IN_KeyDown((kbutton_t *)((char *)kb + 300));
}

void __cdecl IN_Breath_Down() { IN_KeyDown((kbutton_t *)((char *)kb + 300)); }

void __cdecl IN_Attack_Down() {
  return IN_KeyDown((kbutton_t *)((char *)kb + 280));
}

void __cdecl IN_StrafeDown() { IN_KeyDown((kbutton_t *)((char *)kb + 160)); }

void __cdecl IN_SpeedDown() { IN_KeyDown(kb + 10); }

void __cdecl IN_MoverightDown() { IN_KeyDown((kbutton_t *)((char *)kb + 140)); }

void __cdecl IN_MoveleftDown() { IN_KeyDown((kbutton_t *)((char *)kb + 120)); }

void __cdecl IN_LookdownDown() { IN_KeyDown((kbutton_t *)((char *)kb + 100)); }

void __cdecl IN_LookupDown() {
  return IN_KeyDown((kbutton_t *)((char *)kb + 80));
}

void __cdecl IN_BackDown() { IN_KeyDown((kbutton_t *)((char *)kb + 60)); }

void __cdecl IN_ForwardDown() { IN_KeyDown((kbutton_t *)((char *)kb + 40)); }

void __cdecl IN_RightDown() {
  return IN_KeyDown((kbutton_t *)((char *)kb + 20));
}

void __cdecl IN_LeftDown() { IN_KeyDown(kb); }

void __cdecl IN_DownDown() {
  int result; // eax

  IN_KeyDown((kbutton_t *)((char *)kb + 220));
  if (LOBYTE(kb[28].msec) || BYTE2(kb[13].down)) {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 1;
  } else {
    result = legacyHacks;
    *(_DWORD *)(legacyHacks + 12) = 0;
  }
  return result;
}

void __cdecl IN_UpDown() {
  IN_KeyDown((kbutton_t *)((char *)kb + 240));
  if (!LOBYTE(kb[28].msec) && !BYTE2(kb[13].down)) {
    if (*(int *)(legacyHacks + 8) <= 1) {
      if (*(_DWORD *)(legacyHacks + 8) == 1)
        *(_DWORD *)(legacyHacks + 8) = 0;
      else
        IN_KeyDown((kbutton_t *)((char *)kb + 200));
    } else {
      *(_DWORD *)(legacyHacks + 8) = 1;
    }
  }
}

void __cdecl CL_InitInput() { UNIMPLEMENTED(); }

void __cdecl CL_WriteVoicePacket() { UNIMPLEMENTED(); }

void __cdecl CL_GamepadMove(struct usercmd_s *) { UNIMPLEMENTED(); }

struct usercmd_s __cdecl CL_CreateCmd() {
  UNIMPLEMENTED();
}

void __cdecl CL_SendCmdInternal() {
  _BYTE *v2;    // esi
  int v3;       // edx
  char v4;      // cl
  void *v5;     // eax
  int v6;       // ebx
  _DWORD *v7;   // ebx
  netadr_t v8;  // [esp+0h] [ebp-48h]
  _DWORD v9[9]; // [esp+10h] [ebp-38h] BYREF
  __int64 v10;  // [esp+34h] [ebp-14h]
  int v11;      // [esp+3Ch] [ebp-Ch]

  v2 = clc;
  if (*(int *)clc > 6) {
    v5 = cl;
    v6 = *((_DWORD *)cl + 75031) + 1;
    *((_DWORD *)cl + 75031) = v6;
    v7 = (_DWORD *)((char *)&loc_48650 + (_DWORD)v5 + 28 * (v6 & 0x7F));
    CL_CreateCmd(a1, a2, (usercmd_s *)v9);
    v7[3] = v9[0];
    v7[4] = v9[1];
    v7[5] = v9[2];
    v7[6] = v9[3];
    v7[7] = v9[4];
    v7[8] = v9[5];
    v7[9] = v9[6];
  }
  if (*(_DWORD *)((char *)&loc_407A0 + (_DWORD)v2) ||
      (v3 = *(_DWORD *)v2, *(_DWORD *)v2 == 1) || v3 == 2 ||
      (v4 = v2[262472]) != 0 && dword_1220A78 - *((_DWORD *)v2 + 3) <= 49 ||
      (unsigned int)(v3 - 7) > 1 && !v4 &&
          dword_1220A78 - *((_DWORD *)v2 + 3) <= 999 ||
      *((_DWORD *)v2 + 66038) != 2 &&
          (v10 = *((_QWORD *)v2 + 33019), v11 = *((_DWORD *)v2 + 66040),
           *(_QWORD *)&v8.type = v10, v8.port = v11, !Sys_IsLANAddress(v8)) &&
          dword_1220A78 -
                  *((_DWORD *)cl +
                    3 * (((unsigned __int8)*(_DWORD *)((char *)&loc_407C8 +
                                                       (_DWORD)clc) -
                          1) &
                         0x1F) +
                    75034) <
              1000 / *(_DWORD *)(cl_maxpackets + 8)) {
    if (*(_BYTE *)(cl_showSend + 8))
      Com_Printf(". ");
  } else {
    CL_WritePacket();
  }
}

void __cdecl CL_SendCmd() {
  if (*(int *)clc > 4 && *(_DWORD *)clc != 8)
    CL_SendCmdInternal(a1, a2);
}

struct dvar_s const *const cl_stanceHoldTime;
struct dvar_s const *const cl_analog_attack_threshold;
struct dvar_s const *const cl_yawspeed;
struct dvar_s const *const cl_upspeed;
struct dvar_s const *const cl_sidespeed;
struct dvar_s const *const cl_bypassMouseInput;
struct dvar_s const *const cl_pitchspeed;
struct dvar_s const *const cl_forwardspeed;
struct dvar_s const *const cl_anglespeedkey;
int __cdecl CL_ReadyToSendPacket(void) { UNIMPLEMENTED(); }

void __cdecl CL_CreateNewCommands(void) { UNIMPLEMENTED(); }

IN_TalkDown() { UNIMPLEMENTED(); }

IN_TalkUp() { UNIMPLEMENTED(); }

IsTalking() { UNIMPLEMENTED(); }

CL_Input() { UNIMPLEMENTED(); }
