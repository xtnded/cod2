void __cdecl PM_StepSlideMove(struct pmove_t *pm, struct pml_t *pml,
                              int gravity) {
  int32_t ps;     // ebx
  int v4;         // eax
  float *v5;      // esi
  float *v6;      // edi
  float v7;       // xmm2_4
  float v8;       // xmm0_4
  int Footsteps;  // eax
  float v10;      // xmm0_4
  float v11;      // edx
  int32_t v12;    // esi
  float v13;      // xmm1_4
  int v14;        // esi
  float v15;      // xmm1_4
  int v16;        // esi
  float v17;      // xmm1_4
  int v18;        // edx
  float v19;      // xmm1_4
  float fraction; // xmm3_4
  float v21;      // xmm3_4
  float v22;      // xmm1_4
  float v24;      // [esp+6Ch] [ebp-BCh]
  _BOOL4 v25;     // [esp+70h] [ebp-B8h]
  int v26;        // [esp+74h] [ebp-B4h]
  int v27;        // [esp+78h] [ebp-B0h]
  float *v28;     // [esp+7Ch] [ebp-ACh]
  float *v29;     // [esp+80h] [ebp-A8h]
  float *v30;     // [esp+84h] [ebp-A4h]
  float *v31;     // [esp+88h] [ebp-A0h]
  int v32;        // [esp+90h] [ebp-98h]
  int v33;        // [esp+94h] [ebp-94h]
  int v34;        // [esp+98h] [ebp-90h]
  float v35;      // [esp+9Ch] [ebp-8Ch]
  float v36;      // [esp+A0h] [ebp-88h]
  float v37;      // [esp+A4h] [ebp-84h]
  float v38;      // [esp+A8h] [ebp-80h]
  float v39;      // [esp+ACh] [ebp-7Ch]
  trace_t v40;    // [esp+B8h] [ebp-70h] BYREF
  float v41;      // [esp+DCh] [ebp-4Ch]
  float v42;      // [esp+E0h] [ebp-48h]
  float v43;      // [esp+E4h] [ebp-44h]
  float v44;      // [esp+E8h] [ebp-40h]
  float v45;      // [esp+ECh] [ebp-3Ch]
  float v46;      // [esp+F0h] [ebp-38h]
  float v47;      // [esp+F4h] [ebp-34h] BYREF
  float v48;      // [esp+F8h] [ebp-30h]
  float v49;      // [esp+FCh] [ebp-2Ch]
  float v50;      // [esp+100h] [ebp-28h] BYREF
  float v51;      // [esp+104h] [ebp-24h]
  float v52;      // [esp+108h] [ebp-20h]
  float v53[7];   // [esp+10Ch] [ebp-1Ch] BYREF

  ps = a1->ps;
  v4 = *(_DWORD *)(a1->ps + 12);
  if ((v4 & 0x20) != 0)
    goto LABEL_46;
  if (a2->groundPlane) {
    v26 = 1;
    goto LABEL_4;
  }
  if ((v4 & 0x80000) != 0 && *(_DWORD *)(ps + 16)) {
  LABEL_46:
    Jump_ClearState((playerState_s *)a1->ps);
    v26 = 0;
  } else {
    v26 = 0;
  }
LABEL_4:
  v5 = (float *)(ps + 20);
  v50 = *(float *)(ps + 20);
  v28 = (float *)(ps + 24);
  v51 = *(float *)(ps + 24);
  v29 = (float *)(ps + 28);
  v52 = *(float *)(ps + 28);
  v6 = (float *)(ps + 32);
  v34 = *(_DWORD *)(ps + 32);
  v30 = (float *)(ps + 36);
  v33 = *(_DWORD *)(ps + 36);
  v31 = (float *)(ps + 40);
  v32 = *(_DWORD *)(ps + 40);
  v25 = PM_SlideMove(a1, (int)a2, a3);
  if ((*(_BYTE *)(ps + 12) & 1) != 0) {
    v53[0] = 10.0;
    if (*(_DWORD *)(ps + 96) != 1023) {
    LABEL_6:
      v27 = 0;
      goto LABEL_7;
    }
  } else {
    v53[0] = 18.0;
    if (*(_DWORD *)(ps + 96) != 1023)
      goto LABEL_6;
  }
  Footsteps = *(_DWORD *)(ps + 12);
  if ((Footsteps & 0x80000) != 0 && *(_DWORD *)(ps + 16)) {
    Jump_ClearState((playerState_s *)ps);
    Footsteps = *(_DWORD *)(ps + 12);
  }
  if (!v25 || (Footsteps & 0x80000) == 0) {
  LABEL_23:
    if ((Footsteps & 0x20) == 0 || *(float *)(ps + 40) <= 0.0)
      return Footsteps;
    goto LABEL_6;
  }
  LOBYTE(Footsteps) = Jump_GetStepHeight((playerState_s *)ps, &v50, v53);
  if (!(_BYTE)Footsteps) {
    Footsteps = *(_DWORD *)(ps + 12);
    goto LABEL_23;
  }
  if (v53[0] < 1.0)
    return Footsteps;
  v27 = 1;
LABEL_7:
  v47 = *v5;
  v48 = *v28;
  v49 = *v29;
  v37 = *v6;
  v36 = *v30;
  v35 = *v31;
  v39 = v47 - v50;
  v38 = v48 - v51;
  if (v25 &&
      (v44 = v50, v45 = v51, v46 = (float)(v53[0] + 1.0) + v52,
       PM_playerTrace(a1, &v40, &v50, a1->mins),
       v7 = (float)((float)(v53[0] + 1.0) * v40.fraction) - 1.0, v7 >= 1.0)) {
    v10 = v7 + v52;
    v11 = v45;
    *v5 = v44;
    *(float *)(ps + 24) = v11;
    *(float *)(ps + 28) = v10;
    *(_DWORD *)v6 = v34;
    *(_DWORD *)(ps + 36) = v33;
    *(_DWORD *)(ps + 40) = v32;
    PM_SlideMove(a1, (int)a2, a3);
  } else {
    v7 = 0.0;
  }
  if (v26 || v7 != 0.0) {
    v41 = *v5;
    v42 = *v28;
    v8 = *v29 - v7;
    v43 = v8;
    if (v26)
      v43 = v8 - 9.0;
    PM_playerTrace(a1, &v40, (const float *)(ps + 20), a1->mins);
    if (v40.entityNum <= 0x3Fu) {
      *v5 = v47;
      *(float *)(ps + 24) = v48;
      LOBYTE(Footsteps) = LOBYTE(v49);
      *(float *)(ps + 28) = v49;
      *v6 = v37;
      *(float *)(ps + 36) = v36;
      *(float *)(ps + 40) = v35;
      return Footsteps;
    }
    fraction = v40.fraction;
    if (v40.fraction < 1.0) {
      if (v40.normal[2] < 0.30000001) {
        *v5 = v47;
        *(float *)(ps + 24) = v48;
        LOBYTE(Footsteps) = LOBYTE(v49);
        *(float *)(ps + 28) = v49;
        *v6 = v37;
        *(float *)(ps + 36) = v36;
        *(float *)(ps + 40) = v35;
        return Footsteps;
      }
      *v5 = *v5 + (float)((float)(v41 - *v5) * v40.fraction);
      *(float *)(ps + 24) = *v28 + (float)((float)(v42 - *v28) * fraction);
      *(float *)(ps + 28) = *v29 + (float)(fraction * (float)(v43 - *v29));
      PM_ClipVelocity((const float *)(ps + 32), v40.normal, (float *)(ps + 32));
    } else if (v7 != 0.0) {
      *(float *)(ps + 28) = *(float *)(ps + 28) - v7;
    }
  }
  if ((float)((float)((float)(v39 * *v6) + (float)(*v30 * v38)) + 0.001) >=
      (float)((float)((float)(*v5 - v50) * *v6) +
              (float)((float)(*v28 - v51) * *v30)))
    goto LABEL_51;
  if (v27) {
    if (!Jump_IsPlayerAboveMax((playerState_s *)ps)) {
    LABEL_53:
      Jump_ClampVelocity((playerState_s *)ps, &v47);
      goto LABEL_30;
    }
  LABEL_51:
    *v5 = v47;
    *(float *)(ps + 24) = v48;
    *(float *)(ps + 28) = v49;
    *v6 = v37;
    *(float *)(ps + 36) = v36;
    *(float *)(ps + 40) = v35;
    if (v26) {
      v41 = *v5;
      v42 = *v28;
      v43 = *v29 - 9.0;
      PM_playerTrace(a1, &v40, (const float *)(ps + 20), a1->mins);
      if (v40.fraction < 1.0) {
        v21 = *v28 + (float)((float)(v42 - *v28) * v40.fraction);
        v22 = *v29 + (float)((float)(v43 - *v29) * v40.fraction);
        *v5 = *v5 + (float)(v40.fraction * (float)(v41 - *v5));
        *(float *)(ps + 24) = v21;
        *(float *)(ps + 28) = v22;
        PM_ClipVelocity((const float *)(ps + 32), v40.normal,
                        (float *)(ps + 32));
      }
    }
    if (!v27)
      goto LABEL_30;
    goto LABEL_53;
  }
LABEL_30:
  LOBYTE(Footsteps) = v26;
  if (v26 && *(int *)(ps + 4) <= 5) {
    LOBYTE(Footsteps) = (_BYTE)a1;
    v12 = a1->ps;
    if ((*(_BYTE *)(a1->ps + 12) & 1) == 0 ||
        (Footsteps =
             BG_CheckProne(*(_DWORD *)(v12 + 204), (const float *)(v12 + 20),
                           *(float *)(v12 + 1400), 30.0, *(float *)(v12 + 1412),
                           (float *)(v12 + 1448), (float *)(v12 + 1452),
                           (float *)(v12 + 1456), 1, 1, 0, a1->handler,
                           PCT_CLIENT, 66.0)) != 0) {
      v13 = *(float *)(ps + 28) - v49;
      if (fabs(v13) > 0.5) {
        v24 = floorf(v13 + 0.5);
        Footsteps = (int)v24;
        if ((int)v24) {
          if (Footsteps >= -16) {
            if (Footsteps <= 24)
              v14 = Footsteps + 128;
            else
              v14 = 152;
          } else {
            v14 = 112;
          }
          BG_AddPredictableEventToPlayerstate(143, v14, (playerState_s *)ps);
          v15 = (float)((float)(1.0 - (float)(fabs(*(float *)(ps + 28) - v52) /
                                              v53[0])) *
                        0.80000001) +
                0.19999999;
          *v6 = v15 * *v6;
          LOBYTE(Footsteps) = ps + 36;
          *(float *)(ps + 36) = v15 * *v30;
          *(float *)(ps + 40) = v15 * *v31;
          v16 = v14 - 128;
          if (v16 < 0)
            v16 = -v16;
          if (v16 > 3 && *(_DWORD *)(ps + 96) != 1023) {
            Footsteps = PM_ShouldMakeFootsteps(a1);
            if (Footsteps) {
              if (v16 >> 1 <= 4)
                v17 = (float)(v16 >> 1);
              else
                v17 = 4.0;
              v18 = *(_DWORD *)(ps + 8);
              v19 = (float)((float)(v17 * 1.25) + 7.0) + (float)v18;
              *(_DWORD *)(ps + 8) = (unsigned __int8)(int)v19;
              LOBYTE(Footsteps) = PM_FootstepEvent(a1, a2, v18, (int)v19, 1);
            }
          }
        }
      }
    } else {
      *(float *)(v12 + 20) = v50;
      *(float *)(v12 + 24) = v51;
      *(float *)(v12 + 28) = v52;
      LOBYTE(Footsteps) = v12 + 32;
      *(_DWORD *)(v12 + 32) = v34;
      *(_DWORD *)(v12 + 36) = v33;
      *(_DWORD *)(v12 + 40) = v32;
    }
  }
  return Footsteps;
}

int marker_bg_slidemove;
float __cdecl PM_PermuteRestrictiveClipPlanes(float const *const, int,
                                              float const (*const)[3],
                                              int *const) {
  UNIMPLEMENTED();
}

int __cdecl PM_SlideMove(struct pmove_t *, struct pml_t *, int) {
  UNIMPLEMENTED();
}

int __cdecl PM_VerifyPronePosition(struct pmove_t *, float *const,
                                   float *const) {
  UNIMPLEMENTED();
}
