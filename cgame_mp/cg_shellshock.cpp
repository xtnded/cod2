int const __cdecl FastFloor(float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_StartShellShock(struct shellshock_parms_t const *, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_PerturbCamera()
{
  UNIMPLEMENTED();
}

void __cdecl CG_SetShellShockParmsFromDvars(struct shellshock_parms_t *parms)
{
  float v1;       // xmm1_4
  float v2;       // xmm0_4
  const char *v3; // eax
  float v4;       // xmm1_4
  __m128 v5;      // xmm0
  __m128 v6;      // xmm0
  float v7;       // xmm1_4
  __m128 v8;      // xmm0
  __m128 v9;      // xmm0
  float v10;      // xmm1_4
  __m128 v11;     // xmm0
  __m128 v12;     // xmm0
  float v13;      // xmm1_4
  __m128 v14;     // xmm0
  __m128 v15;     // xmm0
  float v16;      // xmm1_4
  __m128 v17;     // xmm0
  __m128 v18;     // xmm0
  float v19;      // xmm1_4
  __m128 v20;     // xmm0
  __m128 v21;     // xmm0
  float v22;      // xmm1_4
  __m128 v23;     // xmm0
  __m128 v24;     // xmm0
  float v25;      // xmm1_4
  __m128 v26;     // xmm0
  __m128 v27;     // xmm0
  float v28;      // xmm1_4
  __m128 v29;     // xmm0
  __m128 v30;     // xmm0
  float v31;      // xmm1_4
  __m128 v32;     // xmm0
  __m128 v33;     // xmm0
  float v34;      // xmm1_4
  __m128 v35;     // xmm3
  __m128 v36;     // xmm3
  int32_t result; // eax
  __m128 v38;     // xmm0
  float v39;      // [esp+10h] [ebp-28h]
  float v40;      // [esp+14h] [ebp-24h]
  float v41;      // [esp+18h] [ebp-20h]
  float v42;      // [esp+1Ch] [ebp-1Ch]
  float v43;      // [esp+20h] [ebp-18h]
  float v44;      // [esp+24h] [ebp-14h]
  float v45;      // [esp+28h] [ebp-10h]
  float v46;      // [esp+2Ch] [ebp-Ch]

  v46 = floorf((float)(*(float *)(cg_shock_screenBlendFadeTime + 8) * 1000.0) +
               0.5);
  a1->screenBlend.fadeTime = (int)v46;
  v45 =
      floorf((float)(*(float *)(cg_shock_screenBlendTime + 8) * 1000.0) + 0.5);
  a1->screenBlend.effectTime = (int)v45;
  a1->view.fadeTime = 3000;
  v1 = *(float *)(cg_shock_viewKickPeriod + 8);
  if ((float)(0.001 - v1) < 0.0)
    v2 = 0.001 / v1;
  else
    v2 = 1.0;
  *(float *)&a1->view.kickRate = v2;
  a1->view.kickRadius = *(_DWORD *)(cg_shock_viewKickRadius + 8);
  a1->sound.use = *(unsigned __int8 *)(cg_shock_sound + 8);
  v44 =
      floorf((float)(*(float *)(cg_shock_soundFadeInTime + 8) * 1000.0) + 0.5);
  a1->sound.fadeInTime = (int)v44;
  v43 =
      floorf((float)(*(float *)(cg_shock_soundFadeOutTime + 8) * 1000.0) + 0.5);
  a1->sound.fadeOutTime = (int)v43;
  v42 = floorf((float)(*(float *)(cg_shock_soundLoopFadeTime + 8) * 1000.0) +
               0.5);
  a1->sound.loopFadeTime = (int)v42;
  v41 = floorf((float)(*(float *)(cg_shock_soundLoopEndDelay + 8) * 1000.0) +
               0.5);
  a1->sound.loopEndDelay = (int)v41;
  v3 = (const char *)Dvar_EnumToString((const dvar_s *)cg_shock_soundRoomType);
  strncpy((char *)a1->sound.roomtype, v3, 0xFu);
  a1->sound.roomtype[15] = 0;
  a1->sound.drylevel = *(_DWORD *)(cg_shock_soundDryLevel + 8);
  a1->sound.wetlevel = *(_DWORD *)(cg_shock_soundWetLevel + 8);
  v40 =
      floorf((float)(1000.0 * *(float *)(cg_shock_soundModEndDelay + 8)) + 0.5);
  a1->sound.modEndDelay = (int)v40;
  v4 = *(float *)(cg_shock_volume_auto + 8);
    if ((float)(0.0 - v4) < 0.0) {
      v5 = (__m128) * (unsigned int *)(cg_shock_volume_auto + 8);
      v5.f32[0] = v4 - 1.0;
    }
    else {
      v4 = 0.0;
      v5 = (__m128)0xBF800000;
    }
  v6 = _mm_cmplt_ss(v5, (__m128)0LL);
  *(_DWORD *)a1->sound.channelvolume =
      _mm_andnot_ps(v6, (__m128)0x3F800000u).u32[0] | LODWORD(v4) & v6.i32[0];
  v7 = *(float *)(cg_shock_volume_auto2d + 8);
    if ((float)(0.0 - v7) < 0.0) {
      v8 = (__m128) * (unsigned int *)(cg_shock_volume_auto2d + 8);
      v8.f32[0] = v7 - 1.0;
    }
    else {
      v7 = 0.0;
      v8 = (__m128)0xBF800000;
    }
  v9 = _mm_cmplt_ss(v8, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[4] =
      _mm_andnot_ps(v9, (__m128)0x3F800000u).u32[0] | LODWORD(v7) & v9.i32[0];
  v10 = *(float *)(cg_shock_volume_menu + 8);
    if ((float)(0.0 - v10) < 0.0) {
      v11 = (__m128) * (unsigned int *)(cg_shock_volume_menu + 8);
      v11.f32[0] = v10 - 1.0;
    }
    else {
      v10 = 0.0;
      v11 = (__m128)0xBF800000;
    }
  v12 = _mm_cmplt_ss(v11, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[8] =
      _mm_andnot_ps(v12, (__m128)0x3F800000u).u32[0] |
      LODWORD(v10) & v12.i32[0];
  v13 = *(float *)(cg_shock_volume_weapon + 8);
    if ((float)(0.0 - v13) < 0.0) {
      v14 = (__m128) * (unsigned int *)(cg_shock_volume_weapon + 8);
      v14.f32[0] = v13 - 1.0;
    }
    else {
      v13 = 0.0;
      v14 = (__m128)0xBF800000;
    }
  v15 = _mm_cmplt_ss(v14, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[20] =
      _mm_andnot_ps(v15, (__m128)0x3F800000u).u32[0] |
      LODWORD(v13) & v15.i32[0];
  v16 = *(float *)(cg_shock_volume_voice + 8);
    if ((float)(0.0 - v16) < 0.0) {
      v17 = (__m128) * (unsigned int *)(cg_shock_volume_voice + 8);
      v17.f32[0] = v16 - 1.0;
    }
    else {
      v16 = 0.0;
      v17 = (__m128)0xBF800000;
    }
  v18 = _mm_cmplt_ss(v17, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[24] =
      _mm_andnot_ps(v18, (__m128)0x3F800000u).u32[0] |
      LODWORD(v16) & v18.i32[0];
  v19 = *(float *)(cg_shock_volume_item + 8);
    if ((float)(0.0 - v19) < 0.0) {
      v20 = (__m128) * (unsigned int *)(cg_shock_volume_item + 8);
      v20.f32[0] = v19 - 1.0;
    }
    else {
      v19 = 0.0;
      v20 = (__m128)0xBF800000;
    }
  v21 = _mm_cmplt_ss(v20, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[16] =
      _mm_andnot_ps(v21, (__m128)0x3F800000u).u32[0] |
      LODWORD(v19) & v21.i32[0];
  v22 = *(float *)(cg_shock_volume_body + 8);
    if ((float)(0.0 - v22) < 0.0) {
      v23 = (__m128) * (unsigned int *)(cg_shock_volume_body + 8);
      v23.f32[0] = v22 - 1.0;
    }
    else {
      v22 = 0.0;
      v23 = (__m128)0xBF800000;
    }
  v24 = _mm_cmplt_ss(v23, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[12] =
      _mm_andnot_ps(v24, (__m128)0x3F800000u).u32[0] |
      LODWORD(v22) & v24.i32[0];
  v25 = *(float *)(cg_shock_volume_local + 8);
    if ((float)(0.0 - v25) < 0.0) {
      v26 = (__m128) * (unsigned int *)(cg_shock_volume_local + 8);
      v26.f32[0] = v25 - 1.0;
    }
    else {
      v25 = 0.0;
      v26 = (__m128)0xBF800000;
    }
  v27 = _mm_cmplt_ss(v26, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[28] =
      _mm_andnot_ps(v27, (__m128)0x3F800000u).u32[0] |
      LODWORD(v25) & v27.i32[0];
  v28 = *(float *)(cg_shock_volume_music + 8);
    if ((float)(0.0 - v28) < 0.0) {
      v29 = (__m128) * (unsigned int *)(cg_shock_volume_music + 8);
      v29.f32[0] = v28 - 1.0;
    }
    else {
      v28 = 0.0;
      v29 = (__m128)0xBF800000;
    }
  v30 = _mm_cmplt_ss(v29, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[32] =
      _mm_andnot_ps(v30, (__m128)0x3F800000u).u32[0] |
      LODWORD(v28) & v30.i32[0];
  v31 = *(float *)(cg_shock_volume_announcer + 8);
    if ((float)(0.0 - v31) < 0.0) {
      v32 = (__m128) * (unsigned int *)(cg_shock_volume_announcer + 8);
      v32.f32[0] = v31 - 1.0;
    }
    else {
      v31 = 0.0;
      v32 = (__m128)0xBF800000;
    }
  v33 = _mm_cmplt_ss(v32, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[36] =
      _mm_andnot_ps(v33, (__m128)0x3F800000u).u32[0] |
      LODWORD(v31) & v33.i32[0];
  v34 = *(float *)(cg_shock_volume_shellshock + 8);
    if ((float)(0.0 - v34) < 0.0) {
      v38 = (__m128) * (unsigned int *)(cg_shock_volume_shellshock + 8);
      v38.f32[0] = v34 - 1.0;
      v35 = v38;
    }
    else {
      v34 = 0.0;
      v35 = (__m128)0xBF800000;
    }
  v36 = _mm_cmplt_ss(v35, (__m128)0LL);
  *(_DWORD *)&a1->sound.channelvolume[40] =
      _mm_andnot_ps(v36, (__m128)0x3F800000u).u32[0] |
      LODWORD(v34) & v36.i32[0];
  a1->mouse.use = *(unsigned __int8 *)(cg_shock_mouse + 8);
  v39 = floorf((float)(1000.0 * *(float *)(cg_shock_mouse_fadeTime + 8)) + 0.5);
  a1->mouse.fadeTime = (int)v39;
  a1->mouse.maxPitchSpeed = *(float *)(cg_shock_mouse_maxpitchspeed + 8);
  a1->mouse.maxYawSpeed = *(float *)(cg_shock_mouse_maxyawspeed + 8);
  result = *(_DWORD *)(cg_shock_mouse_sensitivityscale + 8);
  a1->mouse.sensitivity = result;
  return result;
}

int __cdecl CG_DrawShellShockSavedScreenBlend(struct shellshock_parms_t const *,
                                              int, int)
{
  _DWORD *v3;          // ebx
  int v4;              // eax
  signed int fadeTime; // ecx

    if (a2 && a3 > 0) {
      v3 = cg;
      v4 = a2 + a3 - *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
        if (v4 <= 0) {
          *((_DWORD *)cg + 45885) = 0;
          return 0;
        }
        else {
          fadeTime = a1->screenBlend.fadeTime;
          if (v4 < fadeTime)
            floorf((float)((float)(int)a1->screenBlend.effectTime *
                           (float)((float)v4 / (float)fadeTime)) +
                   0.5);
          if (v3[45885])
            CL_BlendSavedScreen();
          CL_SaveScreen();
          v3[45885] = 1;
          return 1;
        }
    }
    else {
      *((_DWORD *)cg + 45885) = 0;
      return 0;
    }
}

int __cdecl CG_SaveShellShockDvars(char const *name)
{
  UNIMPLEMENTED();
}

void __cdecl CG_PrintPerturbationPoints(void)
{
  UNIMPLEMENTED();
}

int __cdecl CG_LoadShellShockDvars(char const *name)
{
  char *v1;            // edi
  signed int v2;       // esi
  char *v3;            // ebx
  int DvarsFromBuffer; // esi
  dvar_s v6;           // [esp+8h] [ebp-30h] BYREF

  v1 = va("shock/%s.shock", a1);
  v2 = FS_FOpenFileByMode(v1, &v6.domain.integer.min, FS_READ);
    if (v2 >= 0 || (Com_Printf("^1couldn't open '%s'.\n", v1),
                    v2 = FS_FOpenFileByMode("shock/default.shock",
                                            &v6.domain.integer.min, FS_READ),
                    v2 >= 0)) {
      v3 = (char *)Z_MallocInternal(v2 + 1);
      FS_Read(v3, v2, v6.domain.integer.min);
      v3[v2] = 0;
      FS_FCloseFile(v6.domain.integer.min);
      *(_DWORD *)&v6.flags = v1;
      *(_DWORD *)v6.name = v3;
      DvarsFromBuffer =
          Com_LoadDvarsFromBuffer((const char **)&cg_shock_dvar_names, 29, v6);
      Z_FreeInternal(v3);
    }
    else {
      Com_Printf(
          "^1couldn't open 'shock/default.shock'. This is a default shock "
          "file that you should have.\n");
      return 0;
    }
  return DvarsFromBuffer;
}

void __cdecl CG_UpdateShellShock(struct shellshock_parms_t const *parms,
                                 int start, int duration)
{
  _DWORD *v3;                    // esi
  int v4;                        // edi
  signed int fadeOutTime;        // edx
  int v6;                        // eax
  float v7;                      // xmm1_4
  const shellshock_parms_t *v8;  // eax
  int i;                         // edx
  int32_t loopEndDelay;          // ecx
  int v11;                       // ebx
  snd_alias_t *v12;              // esi
  const snd_alias_t *v13;        // edx
  signed int loopFadeTime;       // eax
  float v15;                     // xmm0_4
  int v16;                       // edx
  int v17;                       // eax
  const shellshock_parms_t *v18; // edx
  const shellshock_parms_t *v19; // ecx
  int v20;                       // ebx
  int fadeTime;                  // eax
  float v22;                     // xmm1_4
  float v23;                     // xmm1_4
  float v24;                     // xmm5_4
  float v25;                     // xmm4_4
  int v26;                       // edx
  float v27;                     // xmm2_4
  float v28;                     // xmm3_4
  float v29;                     // xmm1_4
  float v30;                     // xmm0_4
  void *v31;                     // eax
  float v32;                     // xmm2_4
  float v33;                     // xmm3_4
  float v34;                     // xmm1_4
  float v35;                     // xmm0_4
  signed int fadeInTime;         // eax
  void *v38;                     // edx
  const snd_alias_t *v39;        // ebx
  snd_alias_t *v40;              // eax
  snd_alias_t *v41;              // eax
  snd_alias_t *v42;              // eax
  snd_alias_t *v43;              // eax
  float v44;                     // [esp+20h] [ebp-78h]
  float v45;                     // [esp+30h] [ebp-68h]
  float v46;                     // [esp+48h] [ebp-50h]
  float v47;                     // [esp+4Ch] [ebp-4Ch]
  float v48[17];                 // [esp+54h] [ebp-44h] BYREF

  v3 = cg;
  v4 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - a2;
    if (a2 && v4 >= 0) {
        if (!a1->sound.use) {
          SND_DeactivateChannelVolumes(3, 0);
          SND_DeactivateEnvironmentEffects(2, 0);
            if (!v3[45881]) {
              v18 = a1;
                if (a1->mouse.use) {
                LABEL_19:
                  v19 = v18;
                  v20 = a3 - v4;
                  fadeTime = v18->mouse.fadeTime;
                    if (a3 - v4 < fadeTime) {
                        if (v20 <= 0) {
                          *((_DWORD *)cg + 45882) = 1065353216;
                          CL_CapTurnRate(0.0, 0.0);
                        }
                        else {
                          v22 = (float)v20 / (float)fadeTime;
                            if (v22 == 1.0) {
                              v19 = a1;
                              goto LABEL_23;
                            }
                          *((float *)cg + 45882) =
                              (float)((float)(*(float *)&a1->mouse.sensitivity -
                                              1.0) *
                                      v22) +
                              1.0;
                          CL_CapTurnRate(a1->mouse.maxPitchSpeed / v22,
                                         a1->mouse.maxYawSpeed / v22);
                        }
                    LABEL_24:
                        if (v20 > 0) {
                        LABEL_25:
                            if ((signed int)a1->view.fadeTime > v20) {
                              v23 = (float)v20 / (float)(int)a1->view.fadeTime;
                              v24 = v23 * -2.0;
                            }
                            else {
                              v23 = 1.0;
                              v24 = -2.0;
                            }
                          v45 = (float)v4 * *(float *)&a1->view.kickRate;
                          v44 =
                              (float)((float)((float)(v24 + 3.0) * v23) * v23) *
                              *(float *)&a1->view.kickRadius;
                          v46 = floorf(v45);
                          v25 = v45 - (float)(int)v46;
                          v26 = 2 *
                                ((61 * (_BYTE)a3 + (unsigned __int8)(int)v46) &
                                 0x7F);
                          v27 = *(float *)&cg_perturbations[v26 + 4];
                          v28 = *(float *)&cg_perturbations[v26 + 2];
                          v29 = *(float *)&cg_perturbations[v26];
                          v30 =
                              (float)((float)(*(float *)&cg_perturbations[v26 +
                                                                          6] -
                                              v27) +
                                      v28) -
                              v29;
                          v31 = cg;
                          *((float *)cg + 45883) =
                              (float)(v28 +
                                      (float)((float)((float)(v27 - v29) +
                                                      (float)((float)((float)((float)(v29 -
                                                                                      v28) -
                                                                              v30) +
                                                                      (float)(v30 *
                                                                              v25)) *
                                                              v25)) *
                                              v25)) *
                              v44;
                          v32 = *(float *)&cg_perturbations[v26 + 5];
                          v33 = *(float *)&cg_perturbations[v26 + 3];
                          v34 = *(float *)&cg_perturbations[v26 + 1];
                          v35 =
                              (float)((float)(*(float *)&cg_perturbations[v26 +
                                                                          7] -
                                              v32) +
                                      v33) -
                              v34;
                          *(float *)((char *)&loc_2CCF0 + (_DWORD)v31) =
                              v44 *
                              (float)(v33 +
                                      (float)(v25 *
                                              (float)((float)(v32 - v34) +
                                                      (float)((float)((float)((float)(v34 -
                                                                                      v33) -
                                                                              v35) +
                                                                      (float)(v35 *
                                                                              v25)) *
                                                              v25))));
                          return CL_SetUserCmdInShellshock(v4 < a3);
                        }
                    LABEL_37:
                      v38 = cg;
                      *((_DWORD *)cg + 45883) = 0;
                      *(_DWORD *)((char *)&loc_2CCF0 + (_DWORD)v38) = 0;
                      return CL_SetUserCmdInShellshock(v4 < a3);
                    }
                LABEL_23:
                  *((_DWORD *)cg + 45882) = v19->mouse.sensitivity;
                  CL_CapTurnRate(v19->mouse.maxPitchSpeed,
                                 v19->mouse.maxYawSpeed);
                  goto LABEL_24;
                }
            LABEL_36:
              *((_DWORD *)cg + 45882) = 1065353216;
              CL_CapTurnRate(0.0, 0.0);
              v20 = a3 - v4;
              if (a3 - v4 > 0)
                goto LABEL_25;
              goto LABEL_37;
            }
          v3[45881] = 0;
          v43 = (snd_alias_t *)CL_PickSoundAlias("shellshock_end_abort");
          SND_PlaySoundAlias(v43, (float *)0x3FF, vec3_origin, 0,
                             (const float *)1);
        LABEL_18:
          v18 = a1;
          if (a1->mouse.use)
            goto LABEL_19;
          goto LABEL_36;
        }
      fadeOutTime = a1->sound.fadeOutTime;
      v6 = fadeOutTime + a1->sound.modEndDelay + a3 - v4;
        if (fadeOutTime <= v6) {
          fadeInTime = a1->sound.fadeInTime;
            if (v4 >= fadeInTime) {
              v47 = 1.0;
            LABEL_8:
              v8 = a1;
                for (i = 1; i != 12; ++i) {
                  v48[i - 1] =
                      (float)((float)(*(float *)v8->sound.channelvolume - 1.0) *
                              v47) +
                      1.0;
                  v8 = (const shellshock_parms_t *)((char *)v8 + 4);
                }
              SND_SetChannelVolumes(3, v48, 0);
              SND_SetEnvironmentEffects(2, (char *)a1->sound.roomtype,
                                        v47 * *(float *)&a1->sound.drylevel,
                                        v47 * *(float *)&a1->sound.wetlevel, 0);
              goto LABEL_11;
            }
          v7 = (float)v4 / (float)fadeInTime;
          v47 = v7;
        }
        else {
          v7 = (float)v6 / (float)fadeOutTime;
          v47 = v7;
        }
        if (v7 < 0.0) {
          v47 = 0.0;
        }
        else if (v7 != 0.0) {
          goto LABEL_8;
        }
      SND_DeactivateChannelVolumes(3, 0);
      SND_DeactivateEnvironmentEffects(2, 0);
    LABEL_11:
      loopEndDelay = a1->sound.loopEndDelay;
      v11 = a1->sound.loopFadeTime + loopEndDelay + a3 - v4;
        if (v11 > 0) {
          v12 = (snd_alias_t *)CL_PickSoundAlias("shellshock_loop");
          v13 =
              (const snd_alias_t *)CL_PickSoundAlias("shellshock_loop_silent");
          loopFadeTime = a1->sound.loopFadeTime;
          if (loopFadeTime)
            v15 = fmaxf(0.0, 1.0 - (float)((float)v11 / (float)loopFadeTime));
          else
            v15 = v47;
          SND_PlayBlendedSoundAliases(v12, v13, SLODWORD(v15), (float *)0x3FF,
                                      vec3_origin, 0, (const float *)1);
          loopEndDelay = a1->sound.loopEndDelay;
        }
      v16 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
      v17 = loopEndDelay + a3 + v16 - v4;
        if (v16 >= v17) {
            if (v17 != *((_DWORD *)cg + 45881)) {
              *((_DWORD *)cg + 45881) = v17;
              v39 = (const snd_alias_t *)-(loopEndDelay + a3 - v4);
              v40 = (snd_alias_t *)CL_PickSoundAlias("shellshock_end");
              SND_PlaySoundAlias(v40, (float *)0x3FF, vec3_origin, v39,
                                 (const float *)1);
            }
        }
        else if (*((_DWORD *)cg + 45881)) {
          *((_DWORD *)cg + 45881) = 0;
          v42 = (snd_alias_t *)CL_PickSoundAlias("shellshock_end_abort");
          SND_PlaySoundAlias(v42, (float *)0x3FF, vec3_origin, 0,
                             (const float *)1);
        }
      goto LABEL_18;
    }
  SND_DeactivateChannelVolumes(3, 0);
  SND_DeactivateEnvironmentEffects(2, 0);
    if (v3[45881]) {
      v3[45881] = 0;
      v41 = (snd_alias_t *)CL_PickSoundAlias("shellshock_end_abort");
      SND_PlaySoundAlias(v41, (float *)0x3FF, vec3_origin, 0, (const float *)1);
    }
  v3[45882] = 1065353216;
  CL_CapTurnRate(0.0, 0.0);
  v3[45883] = 0;
  *(_DWORD *)((char *)&loc_2CCF0 + (_DWORD)v3) = 0;
  return CL_SetUserCmdInShellshock(0);
}

void __cdecl CG_EndShellShockCamera(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_EndShellShockMouse(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_CubicInterpolate(float, float, float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateShellShockMouse(struct shellshock_parms_t const *, int,
                                      int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateShellShockCamera(struct shellshock_parms_t const *, int,
                                       int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_PerturbationPoint(float const *const, float *const, float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_EndShellShockSound(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_EndShellShock(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_UpdateShellShockSound(struct shellshock_parms_t const *, int,
                                      int)
{
  UNIMPLEMENTED();
}
