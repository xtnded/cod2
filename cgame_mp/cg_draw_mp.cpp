void __cdecl Vec2Set(float *const, float, float) { UNIMPLEMENTED(); }

void __cdecl Vec4Set(float *const, float, float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawFrameOverlay(float innerLeft, float innerRight,
                                 float innerTop, float innerBottom,
                                 float const *const color,
                                 struct Material *material) {
  void *result; // eax
  float v7;     // xmm0_4
  float v8;     // [esp+40h] [ebp-28h]
  float v9;     // [esp+5Ch] [ebp-Ch]

  result = &cls;
  v7 = (float)dword_14C13C4;
  v9 = (float)dword_14C13C8;
  if (a1 > 0.0) {
    v8 = (float)dword_14C13C4;
    result = (void *)CL_DrawStretchPicPhysical(0.0, 0.0, a1, v9, 0.0, 0.0, 0.0,
                                               1.0, a5, a6);
    v7 = v8;
  }
  if (v7 > a2)
    result = (void *)CL_DrawStretchPicPhysical(a2, 0.0, v7 - a2, v9, 0.0, 0.0,
                                               0.0, 1.0, a5, a6);
  if (a3 > 0.0)
    result = (void *)CL_DrawStretchPicPhysical(a1, 0.0, a2 - a1, a3, 0.0, 0.0,
                                               1.0, 0.0, a5, a6);
  if (v9 > a4)
    return (void *)CL_DrawStretchPicPhysical(a1, a4, a2 - a1, v9 - a4, 0.0, 0.0,
                                             1.0, 0.0, a5, a6);
  return result;
}

void __cdecl CG_AddLagometerSnapshotInfo(struct snapshot_t *snap) {
  int v1;          // edx
  int v2;          // ecx
  uint32_t result; // eax
  int v4;          // eax

  if (a1) {
    v1 = dword_195B784;
    v2 = dword_195B784 & 0x7F;
    dword_195B584[v2] = a1->ping;
    result = a1->snapFlags;
    dword_195B384[v2] = a1->snapFlags;
    dword_195B784 = v1 + 1;
  } else {
    v4 = dword_195B784;
    dword_195B584[dword_195B784 & 0x7F] = -1;
    result = v4 + 1;
    dword_195B784 = result;
  }
  return result;
}

void __cdecl CG_AddLagometerFrameInfo() {
  int v0;     // edx
  int result; // eax

  v0 = dword_195B380;
  result = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - *((_DWORD *)cg + 7);
  lagometer[dword_195B380 & 0x7F] = result;
  dword_195B380 = v0 + 1;
  return result;
}

int __cdecl CG_DrawFieldWidth(int, int, int, int, int, int) { UNIMPLEMENTED(); }

void __cdecl CG_ScreenFade(void) { UNIMPLEMENTED(); }

void __cdecl CG_CalculateFPS() {
  int v0;     // eax
  int v1;     // ecx
  int v2;     // eax
  int result; // eax

  v0 = Sys_Milliseconds();
  v1 = v0 - CG_CalculateFPS(void)::previous;
  CG_CalculateFPS(void)::previous = v0;
  v2 = fps_index;
  fps_previousTimes[fps_index % 32] = v1;
  result = v2 + 1;
  fps_index = result;
  return result;
}

bool __cdecl CG_GetWeapReticleZoom(float *pfZoom) {
  _DWORD *v1;                   // ebx
  int32_t ViewmodelWeaponIndex; // eax
  int WeaponDef;                // edx
  float v4;                     // xmm1_4
  float v5;                     // xmm1_4
  float v6;                     // xmm0_4
  float v8;                     // xmm1_4

  v1 = cg;
  ViewmodelWeaponIndex = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg));
  WeaponDef = BG_GetWeaponDef(ViewmodelWeaponIndex);
  v4 = *(float *)((char *)&loc_25CA0 + (_DWORD)v1);
  *a1 = 0.0;
  if (!**(_BYTE **)(WeaponDef + 628) && !*(_DWORD *)(WeaponDef + 632) ||
      v4 == 0.0)
    return 0;
  if (v1[41253]) {
    v5 = v4 - (float)(1.0 - *(float *)(WeaponDef + 620));
    v6 = v5;
    *a1 = v5;
    if (v5 > 0.0) {
      v6 = v5 / *(float *)(WeaponDef + 620);
      *a1 = v6;
    }
  } else {
    v8 = v4 - (float)(1.0 - *(float *)(WeaponDef + 624));
    v6 = v8;
    *a1 = v8;
    if (v8 > 0.0) {
      v6 = v8 / *(float *)(WeaponDef + 624);
      *a1 = v6;
    }
  }
  if (v6 <= 0.0099999998)
    return 0;
  if (v6 > 1.0)
    *a1 = 1.0;
  return 1;
}

void __cdecl CG_ShakeCamera() {
  float v0;        // xmm3_4
  int v1;          // edi
  int v2;          // esi
  float *v3;       // ecx
  float *v4;       // edx
  float *v5;       // ebx
  int v6;          // eax
  float v7;        // xmm1_4
  int v8;          // eax
  float v9;        // xmm2_4
  float v10;       // xmm1_4
  float v11;       // xmm0_4
  float *v12;      // ebx
  float v13;       // xmm2_4
  float v14;       // xmm0_4
  float *v15;      // ebx
  float v16;       // xmm0_4
  float v17;       // xmm0_4
  float v18;       // xmm0_4
  long double v19; // [esp+0h] [ebp-A8h]
  long double v20; // [esp+0h] [ebp-A8h]
  long double v21; // [esp+0h] [ebp-A8h]
  float v22;       // [esp+1Ch] [ebp-8Ch]
  float v23;       // [esp+30h] [ebp-78h]
  int v24;         // [esp+5Ch] [ebp-4Ch]
  float v25;       // [esp+7Ch] [ebp-2Ch]
  float v26;       // [esp+88h] [ebp-20h]
  float v27;       // [esp+8Ch] [ebp-1Ch]

  v26 = (float)*(int *)((char *)&loc_25BB0 + (_DWORD)cg) / 600.0;
  v27 = 0.0;
  v0 = 0.0;
  v1 = 0;
  v24 = 0;
  v2 = 181504;
  v3 = (float *)cg;
  v4 = (float *)((char *)cg + 181504);
  v5 = (float *)((char *)cg + 181516);
  v6 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - *((_DWORD *)cg + 45379);
  if (v6 >= 0) {
    v7 = (float)v6;
    if ((float)v6 < *((float *)cg + 45381))
      goto LABEL_6;
  }
LABEL_3:
  while (1) {
    ++v1;
    v2 += 36;
    v24 += 36;
    if (v1 == 4)
      break;
    while (1) {
      v3 = (float *)cg;
      v4 = (float *)((char *)cg + v2);
      v5 = (float *)((char *)cg + v2 + 12);
      v8 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - *(_DWORD *)v5;
      if (v8 < 0)
        break;
      v7 = (float)v8;
      if ((float)v8 >= *(float *)((char *)cg + v2 + 20))
        break;
    LABEL_6:
      v22 = Vec3Distance(v4 + 7, v3 + 41314);
      v9 = 1.0 - (float)(v22 / v5[3]);
      v10 = (float)(1.0 - (float)(v7 / v5[2])) * v5[1];
      if (v10 <= 0.0)
        goto LABEL_3;
      v11 = v9 < 0.0 ? v9 / v10 : v9 * v10;
      v5[7] = v11;
      v5[8] = v10;
      if (*(float *)((char *)cg + v24 + 181544) <= v0)
        goto LABEL_3;
      v27 = *(float *)((char *)cg + v24 + 181548);
      v0 = *(float *)((char *)cg + v24 + 181544);
      ++v1;
      v2 += 36;
      v24 += 36;
      if (v1 == 4)
        goto LABEL_11;
    }
  }
LABEL_11:
  v12 = (float *)cg;
  v13 = *(float *)((char *)&loc_2C5A0 + (_DWORD)cg);
  if (v13 <= v0) {
    v13 = v0;
    if (v0 > 0.0)
      goto LABEL_13;
  } else {
    v27 = *(float *)((char *)&loc_2C5A0 + (_DWORD)cg);
    if (v13 > 0.0) {
    LABEL_13:
      *(double *)&v19 = v26 * 25.13274122871834 + *((float *)cg + 45415);
      v23 = fminf(1.0, v13);
      v14 = sin(v19);
      v12[41330] =
          (float)((float)((float)(v14 * v27) * 18.0) * v23) + v12[41330];
      v15 = (float *)cg;
      *(double *)&v20 = v26 * 47.12388980384689 + *((float *)cg + 45415);
      v16 = sin(v20);
      v15[41331] =
          (float)((float)((float)(v16 * v27) * 16.0) * v23) + v15[41331];
      *(double *)&v21 = v15[45415] + v26 * 37.69911184307752;
      v17 = sin(v21);
      v15[41332] =
          (float)(v23 * (float)((float)(v17 * v27) * 10.0)) + v15[41332];
      return;
    }
  }
  v25 = crandom();
  v18 = v25 * 3.141592653589793;
  v12[45415] = v18;
}

void __cdecl CG_StartShakeCamera(float p, int duration, float *const src,
                                 float radius) {
  int v4;        // eax
  float v5;      // xmm2_4
  char *v6;      // edi
  int v7;        // esi
  char *v8;      // edx
  int v9;        // ebx
  char *v10;     // ecx
  int v11;       // eax
  float v12;     // xmm1_4
  float *result; // eax
  int v14;       // ecx
  int i;         // edx
  int v16;       // edx
  float v17;     // xmm3_4
  float v18;     // xmm1_4
  float v19;     // xmm0_4
  float v20;     // [esp+1Ch] [ebp-5Ch]
  int v21;       // [esp+3Ch] [ebp-3Ch]
  float v22;     // [esp+44h] [ebp-34h]
  int v23;       // [esp+4Ch] [ebp-2Ch] BYREF
  int v24;       // [esp+50h] [ebp-28h]
  int v25;       // [esp+54h] [ebp-24h]
  float v26;     // [esp+58h] [ebp-20h]
  float v27;     // [esp+5Ch] [ebp-1Ch]

  v22 = (float)a2;
  v21 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
  v23 = *(_DWORD *)a3;
  v24 = *((_DWORD *)a3 + 1);
  v25 = *((_DWORD *)a3 + 2);
  v4 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v21;
  if (v4 < 0) {
    v6 = (char *)cg;
  } else {
    v5 = (float)v4;
    if ((float)v4 >= (float)a2 ||
        (v20 = Vec3Distance((float *)&v23, (float *)cg + 41314),
         v17 = 1.0 - (float)(v20 / a4),
         v18 = (float)(1.0 - (float)(v5 / v22)) * a1, v18 <= 0.0)) {
      v6 = (char *)cg;
    } else {
      if (v17 < 0.0)
        v19 = v17 / v18;
      else
        v19 = v17 * v18;
      v26 = v19;
      v27 = (float)(1.0 - (float)(v5 / v22)) * a1;
      v6 = (char *)cg;
    }
  }
  v7 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v6);
  v8 = v6;
  v9 = 0;
  v10 = v6 + 181504;
  do {
    v11 = *(_DWORD *)((char *)&locret_2C50C + (_DWORD)v8);
    if (v11 > v7 ||
        (float)v7 >=
            (float)((float)v11 + *(float *)((char *)&loc_2C514 + (_DWORD)v8))) {
      *((_DWORD *)v10 + 3) = v21;
      *((float *)v10 + 4) = a1;
      *((float *)v10 + 5) = v22;
      *((float *)v10 + 6) = a4;
      *((_DWORD *)v10 + 7) = v23;
      *((_DWORD *)v10 + 8) = v24;
      *((_DWORD *)v10 + 9) = v25;
      *((float *)v10 + 10) = v26;
      result = (float *)LODWORD(v27);
      *((float *)v10 + 11) = v27;
      return result;
    }
    ++v9;
    v10 += 36;
    v8 += 36;
  } while (v9 != 4);
  v12 = v26;
  result = (float *)v6;
  v14 = 4;
  for (i = 0; i != 4; ++i) {
    if (v12 > result[45386]) {
      v14 = i;
      v12 = result[45386];
    }
    result += 9;
  }
  if (v14 != 4) {
    v16 = (int)&v6[36 * v14 + 181504];
    *(_DWORD *)(v16 + 12) = v21;
    *(float *)(v16 + 16) = a1;
    *(float *)(v16 + 20) = v22;
    *(float *)(v16 + 24) = a4;
    *(_DWORD *)(v16 + 28) = v23;
    *(_DWORD *)(v16 + 32) = v24;
    *(_DWORD *)(v16 + 36) = v25;
    *(float *)(v16 + 40) = v26;
    result = (float *)LODWORD(v27);
    *(float *)(v16 + 44) = v27;
  }
  return result;
}

void __cdecl CG_DrawTurretCrossHair() {
  int result;    // eax
  _DWORD *v1;    // esi
  int v2;        // ebx
  int WeaponDef; // ecx
  char *v4;      // ebx
  int v5;        // eax
  float v6;      // xmm1_4
  float v7;      // [esp+40h] [ebp-18h] BYREF
  int v8;        // [esp+44h] [ebp-14h]
  int v9;        // [esp+48h] [ebp-10h]
  int v10;       // [esp+4Ch] [ebp-Ch]

  result = cg_drawTurretCrosshair;
  if (*(_BYTE *)(cg_drawTurretCrosshair + 8)) {
    result = *(_DWORD *)(cg_paused + 8);
    if (!result) {
      v1 = cg;
      result = 137 * *((_DWORD *)cg + 38998);
      v2 = *((_DWORD *)cg_entities + 137 * *((_DWORD *)cg + 38998) + 110);
      if (v2) {
        WeaponDef = BG_GetWeaponDef(
            *((_DWORD *)cg_entities + 137 * *((_DWORD *)cg + 38998) + 110));
        v4 = (char *)cg_weapons + 436 * v2;
        result = *((_DWORD *)v4 + 94);
        if (result) {
          result = (int)&cg_crosshairAlpha;
          if (*(float *)(cg_crosshairAlpha + 8) >= 0.0099999998) {
            v5 = v1[38644];
            if ((v5 & 0x100000) != 0) {
              v7 = 0.25;
              v8 = 1065353216;
              v9 = 1048576000;
            } else if ((v5 & 0x200000) != 0 &&
                       *(_BYTE *)(cg_crosshairEnemyColor + 8)) {
              v7 = 1.0;
              v8 = 1048576000;
              v9 = 1048576000;
            } else {
              v7 = 1.0;
              v8 = 1065353216;
              v9 = 1065353216;
            }
            v10 = *(_DWORD *)(cg_crosshairAlpha + 8);
            v6 = (float)*(int *)(WeaponDef + 288);
            if ((unsigned __int8)CL_IsRenderingSplitScreen())
              v6 = v6 + v6;
            return CL_DrawStretchPic(v6 * -0.5, v6 * -0.5, v6, v6, 2, 2, 0.0,
                                     0.0, 1.0, 1.0, &v7,
                                     *((Material **)v4 + 94));
          }
        }
      }
    }
  }
  return result;
}

void __cdecl CG_DrawPerformanceWarnings(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawTeamBackground(float x, float y, float w, float h,
                                   float alpha, int team) {
  int result; // eax
  float v6;   // [esp+20h] [ebp-18h] BYREF
  int v7;     // [esp+24h] [ebp-14h]
  int v8;     // [esp+28h] [ebp-10h]
  float v9;   // [esp+2Ch] [ebp-Ch]

  result = LODWORD(a4);
  v9 = a4;
  if (a5 == 1) {
    v6 = 1.0;
    v7 = 0;
    v8 = 0;
  } else {
    if (a5 != 2)
      return result;
    v6 = 0.0;
    v7 = 0;
    v8 = 1065353216;
  }
  return UI_DrawHandlePic(*(float *)&a1, *((float *)&a1 + 1), a2, a3, 0, 0, &v6,
                          *((Material **)cgs + 11914));
}

void __cdecl CG_DrawActive() { UNIMPLEMENTED(); }

void __cdecl CG_DrawUpperRight(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawSubtitles(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawMiniConsole(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawBoldGameMessages() { UNIMPLEMENTED(); }

void __cdecl CG_DrawGameMessages(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawCrosshair() {
  void **ViewmodelWeaponIndex;       // eax
  _DWORD *v1;                        // ebx
  char v2;                           // si
  int v3;                            // edi
  float v4;                          // xmm0_4
  int v5;                            // eax
  int v6;                            // edx
  float v7;                          // xmm4_4
  Material *v8;                      // ebx
  float v9;                          // xmm1_4
  float v10;                         // xmm1_4
  float v11;                         // esi
  float *v12;                        // ebx
  float v13;                         // xmm0_4
  int v14;                           // ecx
  float v15;                         // xmm1_4
  float v16;                         // xmm3_4
  float v17;                         // xmm0_4
  float v18;                         // xmm1_4
  long double v20;                   // [esp+0h] [ebp-108h]
  long double v21;                   // [esp+0h] [ebp-108h]
  float v22;                         // [esp+4h] [ebp-104h]
  float RealWidthFromVirtualWidth;   // [esp+34h] [ebp-D4h]
  float RealHeightFromVirtualHeight; // [esp+34h] [ebp-D4h]
  float v25;                         // [esp+34h] [ebp-D4h]
  float v26;                         // [esp+34h] [ebp-D4h]
  float v27;                         // [esp+34h] [ebp-D4h]
  float v28;                         // [esp+34h] [ebp-D4h]
  double v29;                        // [esp+38h] [ebp-D0h]
  float v30;                         // [esp+50h] [ebp-B8h]
  float v31;                         // [esp+70h] [ebp-98h]
  float v32;                         // [esp+70h] [ebp-98h]
  float v33;                         // [esp+80h] [ebp-88h]
  float v34;                         // [esp+84h] [ebp-84h]
  int WeaponDef;                     // [esp+90h] [ebp-78h]
  float v36;                         // [esp+94h] [ebp-74h]
  float v37;                         // [esp+98h] [ebp-70h]
  float v38;                         // [esp+9Ch] [ebp-6Ch]
  float v39;                         // [esp+A0h] [ebp-68h]
  float v40;                         // [esp+A8h] [ebp-60h]
  float v41;                         // [esp+ACh] [ebp-5Ch]
  float v42;                         // [esp+B0h] [ebp-58h]
  float VirtualHeightFromRealHeight; // [esp+B4h] [ebp-54h]
  float VirtualWidthFromRealWidth;   // [esp+B8h] [ebp-50h]
  float v45;                         // [esp+BCh] [ebp-4Ch]
  float v46;                         // [esp+D0h] [ebp-38h] BYREF
  int v47;                           // [esp+D4h] [ebp-34h]
  int v48;                           // [esp+D8h] [ebp-30h]
  float v49;                         // [esp+DCh] [ebp-2Ch]
  float v50;                         // [esp+E0h] [ebp-28h] BYREF
  float v51;                         // [esp+E4h] [ebp-24h] BYREF
  float v52;                         // [esp+E8h] [ebp-20h] BYREF
  float v53[7];                      // [esp+ECh] [ebp-1Ch] BYREF

  ViewmodelWeaponIndex = &cg;
  v1 = cg;
  if (!*(_DWORD *)((char *)&locret_25BC0 + (_DWORD)cg)) {
    LOBYTE(ViewmodelWeaponIndex) = !CG_AreHudMenusHidden();
    v2 = (char)ViewmodelWeaponIndex;
    v36 = *(float *)((char *)&loc_25CA0 + (_DWORD)v1);
    if ((*(_DWORD *)((_BYTE *)&loc_25C64 + (_DWORD)v1) & 0x300) != 0) {
      if ((_BYTE)ViewmodelWeaponIndex && v1[38998] != 1023)
        LOBYTE(ViewmodelWeaponIndex) = CG_DrawTurretCrossHair();
    } else {
      ViewmodelWeaponIndex = (void **)BG_GetViewmodelWeaponIndex(
          (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v1));
      v3 = (int)ViewmodelWeaponIndex;
      if (ViewmodelWeaponIndex) {
        WeaponDef = BG_GetWeaponDef((int)ViewmodelWeaponIndex);
        v4 = COERCE_FLOAT(CG_DrawWeapReticle());
        LOBYTE(ViewmodelWeaponIndex) = v2;
        if (v2) {
          v5 = v1[38644];
          if ((v5 & 0x100000) != 0) {
            v46 = 0.25;
            v47 = 1065353216;
            v48 = 1048576000;
          } else if ((v5 & 0x200000) != 0 &&
                     *(_BYTE *)(cg_crosshairEnemyColor + 8)) {
            v46 = 1.0;
            v47 = 1048576000;
            v48 = 1048576000;
          } else {
            v46 = 1.0;
            v47 = 1065353216;
            v48 = 1065353216;
          }
          LOBYTE(ViewmodelWeaponIndex) = cg_crosshairAlpha;
          v49 = v4 * *(float *)(cg_crosshairAlpha + 8);
          if (v49 >= 0.0099999998) {
            if (v36 != 1.0 || (LOBYTE(ViewmodelWeaponIndex) = cg_drawGun,
                               !*(_BYTE *)(cg_drawGun + 8))) {
              LOBYTE(ViewmodelWeaponIndex) = cg_paused;
              if (!*(_DWORD *)(cg_paused + 8)) {
                LOBYTE(ViewmodelWeaponIndex) = cg_drawCrosshair;
                if (*(_BYTE *)(cg_drawCrosshair + 8)) {
                  v6 = *((_DWORD *)cg + 38695);
                  LOBYTE(ViewmodelWeaponIndex) = v6 - 10;
                  if ((unsigned int)(v6 - 10) > 1 && v6 != 5) {
                    LOBYTE(ViewmodelWeaponIndex) = v6 - 1;
                    if ((unsigned int)(v6 - 1) > 1) {
                      CG_CalcCrosshairPosition(v53, &v52);
                      if (v36 == 0.0) {
                        v37 = 1.0;
                        v7 = 0.0;
                      } else {
                        if (*((_DWORD *)cg + 41253))
                          v15 = *(float *)(WeaponDef + 1136);
                        else
                          v15 = *(float *)(WeaponDef + 1140);
                        v16 = v36 - (float)(1.0 - v15);
                        if (v16 <= 0.0 ||
                            (v17 = v16 / v15, (float)(v16 / v15) <= 0.0)) {
                          v37 = 1.0;
                          v7 = 0.0;
                        } else {
                          v37 = (float)(v17 * -0.5) + 1.0;
                          v7 = (float)((float)(480.0 /
                                               *(float *)((char *)&loc_28584 +
                                                          (_DWORD)cg)) *
                                       v17) *
                               *(float *)(WeaponDef + 1132);
                        }
                        if (!*(_BYTE *)(cg_drawGun + 8) && v37 < 1.0 &&
                            *((_DWORD *)cg_weapons + 109 * v3 + 94)) {
                          v18 = (float)*(int *)(WeaponDef + 288) *
                                (float)(1.5 - v37);
                          CL_DrawStretchPic(
                              v53[0] + (float)(v18 * -0.5),
                              v52 + (float)(v18 * -0.5), v18, v18, 2, 2, 0.0,
                              0.0, 1.0, 1.0, &v46,
                              *((Material **)cg_weapons + 109 * v3 + 94));
                        }
                      }
                      if (v36 != 1.0 ||
                          (LOBYTE(ViewmodelWeaponIndex) = cg_drawGun,
                           *(_BYTE *)(cg_drawGun + 8))) {
                        if (!*(_BYTE *)(cg_crosshairDynamic + 8)) {
                          v53[0] = 0.0;
                          v52 = v7;
                        }
                        v34 = v52;
                        v33 = v53[0];
                        v8 =
                            (Material *)*((_DWORD *)cg_weapons + 109 * v3 + 94);
                        if (v8) {
                          v9 = (float)*(int *)(WeaponDef + 288);
                          if (*(_DWORD *)(WeaponDef + 120) == 1) {
                            v14 = *((_DWORD *)cg + 38656);
                            if (v14) {
                              if (*(_DWORD *)(WeaponDef + 828))
                                v9 = v9 + (float)((float)(v14 % 1000) / 100.0);
                            }
                          }
                          v10 = v9 * v37;
                          if ((unsigned __int8)CL_IsRenderingSplitScreen())
                            v10 = v10 + v10;
                          CL_DrawStretchPic((float)(v10 * -0.5) + v33,
                                            v34 + (float)(v10 * -0.5), v10, v10,
                                            2, 2, 0.0, 0.0, 1.0, 1.0, &v46, v8);
                          v34 = v52;
                          v33 = v53[0];
                        }
                        LOBYTE(ViewmodelWeaponIndex) = (_BYTE)cg_weapons;
                        if (*((_DWORD *)cg_weapons + 109 * v3 + 95)) {
                          CG_DrawWeapReticle();
                          v40 = (float)*(int *)(WeaponDef + 292) * v37;
                          if ((unsigned __int8)CL_IsRenderingSplitScreen()) {
                            v41 = v40 + v40;
                            v11 = v40 + v40;
                          } else {
                            v41 = v40;
                            v11 = v40;
                          }
                          v12 = (float *)cg;
                          BG_GetSpreadForWeapon(
                              (const playerState_s *)((char *)&loc_25BC4 +
                                                      (_DWORD)cg),
                              v3, &v51, &v50);
                          v51 = (float)((float)((float)(v50 - v51) *
                                                (float)(v12[39014] / 255.0)) +
                                        v51) *
                                v37;
                          *(double *)&v20 = v51 * 0.0174532925199433;
                          v29 = tan(v20);
                          *(double *)&v21 =
                              *(float *)((char *)&loc_28584 + (_DWORD)v12) *
                              0.0174532925199433 * 0.5;
                          v13 = v29 * 240.0 / (double)tan(v21);
                          v42 = fmaxf((float)*(int *)(WeaponDef + 296), v13) -
                                (float)(v40 * *(float *)(WeaponDef + 700));
                          RealWidthFromVirtualWidth =
                              GetRealWidthFromVirtualWidth(v41);
                          v31 = RealWidthFromVirtualWidth;
                          RealHeightFromVirtualHeight =
                              GetRealHeightFromVirtualHeight(v11);
                          v30 = (float)*((int *)cgs + 6052);
                          VirtualWidthFromRealWidth =
                              GetVirtualWidthFromRealWidth(
                                  (float)*((int *)cgs + 6051) *
                                  (float)((float)(v31 /
                                                  (float)*((int *)cgs + 6051)) *
                                          0.125));
                          VirtualHeightFromRealHeight =
                              GetVirtualHeightFromRealHeight(
                                  v30 *
                                  (float)((float)(RealHeightFromVirtualHeight /
                                                  v30) *
                                          0.125));
                          v45 = CG_AlignHudElemX(4, v33, v41);
                          v25 = CG_AlignHudElemY(2, v34, v11);
                          CG_DrawRotatedPic(v45,
                                            (float)(v25 - v42) -
                                                VirtualHeightFromRealHeight,
                                            v41, v11, 2, 2, 0.0);
                          v38 = CG_AlignHudElemX(0, v33, v41);
                          v22 = CG_AlignHudElemY(1, v34, v11);
                          CG_DrawRotatedPic(v42 + v38, v22, v41, v11, 2, 2,
                                            90.0);
                          v39 = CG_AlignHudElemX(4, v33, v41);
                          v26 = CG_AlignHudElemY(0, v34, v11);
                          CG_DrawRotatedPic(v39 - VirtualWidthFromRealWidth,
                                            v26 + v42, v41, v11, 2, 2, 180.0);
                          v27 = CG_AlignHudElemX(8, v33, v41);
                          v32 = v27;
                          v28 = CG_AlignHudElemY(1, v34, v11);
                          LOBYTE(ViewmodelWeaponIndex) = CG_DrawRotatedPic(
                              (float)(v32 - v42) - VirtualWidthFromRealWidth,
                              v28 - VirtualHeightFromRealHeight, v41, v11, 2, 2,
                              270.0);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return (char)ViewmodelWeaponIndex;
}

void __cdecl CG_DrawDebugOverlays(void) { UNIMPLEMENTED(); }

void __cdecl CG_PriorityCenterPrint(char const *str, float charWidth,
                                    int priority) {
  char *v3;           // esi
  char *result;       // eax
  int v5;             // esi
  int v6;             // ebx
  int CharFromString; // eax
  char *v8;           // eax
  int v9;             // eax
  char __src[256];    // [esp+1Ch] [ebp-11Ch] BYREF
  char *v11[7];       // [esp+11Ch] [ebp-1Ch] BYREF

  v3 = (char *)cg;
  result = *(char **)((char *)&loc_2B990 + (_DWORD)cg);
  if (!result || a3 >= *((_DWORD *)cg + 44903)) {
    CG_TranslateHudElemMessage(a1, "Center Print", __src);
    I_strncpyz(v3 + 178584, __src, 256);
    *((_DWORD *)v3 + 44903) = a3;
    v11[0] = v3 + 178584;
    v5 = 0;
    v6 = 0;
    while (*v11[0]) {
      CharFromString = SEH_ReadCharFromString((const char **)v11, 0);
      if (CharFromString != 10) {
        if (++v6 <= 74) {
          if (!v5)
            continue;
        } else {
          v5 = 1;
        }
        if (CharFromString != 32)
          continue;
        *(v11[0] - 1) = 10;
      }
      v5 = 0;
      v6 = 0;
    }
    v8 = (char *)cg;
    *(_DWORD *)((char *)&loc_2B990 + (_DWORD)cg) =
        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) + 2000;
    *((_DWORD *)v8 + 44645) = (int)a2;
    *((_DWORD *)v8 + 44902) = 1;
    result = v8 + 178584;
    v11[0] = result;
  LABEL_12:
    while (*result) {
      while (1) {
        v9 = SEH_ReadCharFromString((const char **)v11, 0);
        if (v9 == 10) {
          ++*((_DWORD *)cg + 44902);
          result = v11[0];
          goto LABEL_12;
        }
        if (v9 == 92)
          break;
        result = v11[0];
        if (!*v11[0])
          return result;
      }
      result = v11[0];
      if (*v11[0] == 110) {
        ++*((_DWORD *)cg + 44902);
        result = ++v11[0];
      }
    }
  }
  return result;
}

void __cdecl CG_CenterPrint(char const *, float) { UNIMPLEMENTED(); }

void __cdecl CG_CheckTimedMenus() {
  _DWORD *v0;           // esi
  int v1;               // edx
  int CurrentCmdNumber; // esi
  int v3;               // ebx
  float v4;             // xmm1_4
  float v5;             // xmm1_4
  int v6;               // edx
  float v7;             // xmm1_4
  _DWORD *v8;           // eax
  int v9;               // edx
  int v10;              // eax
  float v11;            // xmm1_4
  int v12;              // edx
  float v13;            // xmm1_4
  int v14;              // edx
  int result;           // eax
  int v16;              // edx
  windowDef_t *v17;     // eax
  windowDef_t *v18;     // eax
  windowDef_t *v19;     // eax
  windowDef_t *v20;     // eax
  windowDef_t *v21;     // eax
  __int16 buttons;      // [esp+54h] [ebp-94h]
  int v23;              // [esp+58h] [ebp-90h]
  float v24;            // [esp+5Ch] [ebp-8Ch]
  _DWORD v25[3];        // [esp+6Ch] [ebp-7Ch] BYREF
  int8_t forwardmove;   // [esp+78h] [ebp-70h]
  int8_t rightmove;     // [esp+79h] [ebp-6Fh]
  uint32_t serverTime;  // [esp+7Ch] [ebp-6Ch]
  int32_t v29;          // [esp+80h] [ebp-68h]
  int8_t weapon;        // [esp+84h] [ebp-64h]
  uint8_t offHandIndex; // [esp+85h] [ebp-63h]
  _DWORD v32[3];        // [esp+88h] [ebp-60h] BYREF
  __int16 v33;          // [esp+94h] [ebp-54h]
  usercmd_s v34;        // [esp+98h] [ebp-50h] BYREF
  usercmd_s v35;        // [esp+B4h] [ebp-34h] BYREF

  v0 = cg;
  v1 = *((_DWORD *)cg + 44947);
  if (v1 && *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v1 > 2500) {
    Menus_CloseByName(&cgDC, "voiceMenu");
    v0[44947] = 0;
  }
  CurrentCmdNumber = CL_GetCurrentCmdNumber();
  if (CurrentCmdNumber <= 1)
    goto LABEL_17;
  CL_GetUserCmd(CurrentCmdNumber - 1, &v35);
  CL_GetUserCmd(CurrentCmdNumber, &v34);
  buttons = v34.buttons;
  v23 = v35.buttons ^ v34.buttons;
  rightmove = v35.rightmove;
  forwardmove = v35.forwardmove;
  v25[2] = LODWORD(v35.angles[2]);
  v25[1] = LODWORD(v35.angles[1]);
  v25[0] = LODWORD(v35.angles[0]);
  v33 = *(_WORD *)&v34.forwardmove;
  v32[2] = LODWORD(v34.angles[2]);
  v32[1] = LODWORD(v34.angles[1]);
  v32[0] = LODWORD(v34.angles[0]);
  offHandIndex = v34.offHandIndex;
  weapon = v34.weapon;
  v29 = v34.buttons;
  serverTime = v34.serverTime;
  v3 = 12;
  if (memcmp((const char *)v25, (const char *)v32, 12) || v33)
    v3 = 1;
  else
    LOBYTE(v3) = 0;
  if (((v34.buttons & 1) == 0 ||
       (*(_DWORD *)((_BYTE *)&loc_25C64 + (_DWORD)cg) & 0x300) != 0) &&
      ((v34.buttons & 0x30) == 0 || (*((_BYTE *)cg + 154576) & 4) != 0 ||
       (*(_BYTE *)(*((_DWORD *)cg + 8) + 1444) & 2) != 0 ||
       (*(_DWORD *)((_BYTE *)&loc_25C64 + (_DWORD)cg) & 0x300) != 0)) {
    if ((v34.buttons & 0x30000) != 0)
      goto LABEL_76;
  } else {
    CG_MenuShowNotify((windowDef_t *)1);
    v3 = 1;
    buttons = v34.buttons;
    if ((v34.buttons & 0x30000) != 0) {
    LABEL_76:
      CG_MenuShowNotify((windowDef_t *)4);
      v3 = 1;
      buttons = v34.buttons;
      if ((v23 & 0x2300) != 0)
        goto LABEL_77;
    LABEL_13:
      if ((buttons & 0x2300) != 0)
        CG_MenuShowNotify((windowDef_t *)3);
      if (!v3 && (v23 & 0xFFFFD4FF) == 0)
        goto LABEL_17;
      goto LABEL_16;
    }
  }
  if ((v23 & 0x2300) == 0)
    goto LABEL_13;
LABEL_77:
  CG_MenuShowNotify((windowDef_t *)3);
LABEL_16:
  CG_MenuShowNotify((windowDef_t *)2);
LABEL_17:
  v24 = CG_CalcPlayerHealth();
  if (*(float *)(hud_health_startpulse_injured + 8) > v24) {
    CG_MenuShowNotify(0);
  } else {
    v4 = *(float *)(hud_fade_healthbar + 8);
    if (v4 != 0.0) {
      v16 = *(_DWORD *)&byte_2C5C4[(_DWORD)cg];
      if (v16) {
        if ((float)(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v16) >
            (float)(v4 * 1000.0)) {
          if (CL_GetLocalClientActiveCount() == 1)
            v17 = (windowDef_t *)Menus_FindByName(&cgDC, "Health");
          else
            v17 = (windowDef_t *)Menus_FindByName(&cgDC, "Health_mp");
          if (v17)
            Window_RemoveDynamicFlags(v17, 4);
          *(_DWORD *)&byte_2C5C4[(_DWORD)cg] = 0;
        }
      }
    }
  }
  if (CG_CheckPlayerForLowAmmo() || CG_CheckPlayerForLowClip())
    CG_MenuShowNotify((windowDef_t *)1);
  v5 = *(float *)(hud_fade_ammodisplay + 8);
  if (v5 != 0.0) {
    v6 = *((_DWORD *)cg + 45426);
    if (v6) {
      if ((float)(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v6) >
          (float)(v5 * 1000.0)) {
        if (CL_GetLocalClientActiveCount() == 1)
          v18 = (windowDef_t *)Menus_FindByName(&cgDC, "weaponinfo");
        else
          v18 = (windowDef_t *)Menus_FindByName(&cgDC, "weaponinfo_mp");
        if (v18)
          Window_RemoveDynamicFlags(v18, 4);
        *((_DWORD *)cg + 45426) = 0;
      }
    }
  }
  v7 = *(float *)(hud_fade_compass + 8);
  if (v7 == 0.0)
    goto LABEL_37;
  v8 = cg;
  v9 = *((_DWORD *)cg + 45424);
  if (!v9)
    goto LABEL_25;
  if ((float)(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v9) <=
      (float)(v7 * 1000.0)) {
  LABEL_37:
    v8 = cg;
  } else {
    if (CL_GetLocalClientActiveCount() == 1)
      v21 = (windowDef_t *)Menus_FindByName(&cgDC, "Compass");
    else
      v21 = (windowDef_t *)Menus_FindByName(&cgDC, "Compass_mp");
    if (v21)
      Window_RemoveDynamicFlags(v21, 4);
    v8 = cg;
    *((_DWORD *)cg + 45424) = 0;
  }
LABEL_25:
  v10 = *(_DWORD *)(v8[9] + 172);
  if ((v10 & 8) != 0 && (v10 & 0x100) != 0 ||
      (v10 & 4) != 0 && (v10 & 0x200) != 0)
    CG_MenuShowNotify((windowDef_t *)3);
  v11 = *(float *)(hud_fade_stance + 8);
  if (v11 != 0.0) {
    v12 = *(_DWORD *)((char *)&loc_2C5CC + (_DWORD)cg);
    if (v12) {
      if ((float)(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v12) >
          (float)(v11 * 1000.0)) {
        if (CL_GetLocalClientActiveCount() == 1)
          v20 = (windowDef_t *)Menus_FindByName(&cgDC, "stance");
        else
          v20 = (windowDef_t *)Menus_FindByName(&cgDC, "stance_mp");
        if (v20)
          Window_RemoveDynamicFlags(v20, 4);
        *(_DWORD *)((char *)&loc_2C5CC + (_DWORD)cg) = 0;
      }
    }
  }
  v13 = *(float *)(hud_fade_offhand + 8);
  if (v13 != 0.0) {
    v14 = *((_DWORD *)cg + 45428);
    if (v14) {
      if ((float)(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v14) >
          (float)(v13 * 1000.0)) {
        if (CL_GetLocalClientActiveCount() == 1)
          v19 = (windowDef_t *)Menus_FindByName(&cgDC, "offhandinfo");
        else
          v19 = (windowDef_t *)Menus_FindByName(&cgDC, "offhandinfo_mp");
        if (v19)
          Window_RemoveDynamicFlags(v19, 4);
        *((_DWORD *)cg + 45428) = 0;
      }
    }
  }
  result = CG_ScoreboardDisplayed();
  if (result) {
    result =
        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - *((_DWORD *)cg + 44366);
    if (result > 100) {
      result = Menus_FindByName(&cgDC, "objectiveinfo");
      if (result)
        return Window_RemoveDynamicFlags((windowDef_t *)result, 4);
    }
  }
  return result;
}

void __cdecl CG_DrawSay(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawPlayerSprites() {
  int result; // eax
  int v1;     // esi
  int v2;     // ebx
  char *v3;   // eax

  result = *((_DWORD *)cg + 9);
  if (*(int *)(result + 9908) > 0) {
    v1 = 0;
    v2 = 0;
    do {
      while (1) {
        v3 = (char *)cg_entities + 548 * *(_DWORD *)(v2 + result + 9916);
        if (*((_DWORD *)v3 + 61) == 1)
          break;
        ++v1;
        v2 += 240;
        result = *((_DWORD *)cg + 9);
        if (*(_DWORD *)(result + 9908) <= v1)
          return result;
      }
      CG_PlayerSprites((centity_s *)v3);
      ++v1;
      v2 += 240;
      result = *((_DWORD *)cg + 9);
    } while (*(_DWORD *)(result + 9908) > v1);
  }
  return result;
}

void __cdecl CG_Draw2D() {
  float *v2;                         // edx
  float v3;                          // xmm0_4
  float v4;                          // xmm2_4
  __m128 v5;                         // xmm3
  int i;                             // ebx
  bool v7;                           // di
  _DWORD *v8;                        // ebx
  int v9;                            // eax
  int v10;                           // eax
  int v11;                           // ebx
  float v12;                         // xmm0_4
  float v13;                         // xmm0_4
  _DWORD *v14;                       // ebx
  int32_t ViewmodelWeaponIndex;      // eax
  int WeaponDef;                     // edx
  __m128 v17;                        // xmm2
  float v18;                         // xmm0_4
  __m128 v19;                        // xmm0
  float v20;                         // eax
  float v21;                         // eax
  float *v22;                        // esi
  int v23;                           // edi
  int v24;                           // ebx
  float v25;                         // xmm2_4
  __m128 v26;                        // xmm1
  __m128 v27;                        // rt1
  __m128 v28;                        // xmm1
  _DWORD *v29;                       // ebx
  int v30;                           // ebx
  float v31;                         // xmm2_4
  float v32;                         // xmm0_4
  int v33;                           // esi
  __m128 v34;                        // xmm0
  int *v35;                          // ebx
  int v36;                           // edx
  float v37;                         // xmm1_4
  float v38;                         // ebx
  statmonitor_s *v39;                // eax
  const char *v40;                   // esi
  int v41;                           // ebx
  const char *v42;                   // eax
  char *v43;                         // eax
  int v44;                           // edi
  const char *v45;                   // ebx
  int v46;                           // esi
  char *v47;                         // eax
  float v48;                         // xmm3_4
  float v49;                         // xmm1_4
  float v50;                         // xmm0_4
  __m128 v51;                        // xmm0
  char *v52;                         // eax
  float v53;                         // xmm2_4
  const float *v54;                  // edx
  float v55;                         // xmm0_4
  float v56;                         // xmm1_4
  int v57;                           // eax
  float v58;                         // xmm0_4
  int *v59;                          // eax
  float v60;                         // eax
  char *v61;                         // esi
  Font_s *v62;                       // eax
  int v63;                           // eax
  int j;                             // edx
  char v65;                          // al
  Font_s *v66;                       // ebx
  int v67;                           // eax
  char v68;                          // al
  int32_t v69;                       // eax
  int v70;                           // edx
  float v71;                         // xmm3_4
  float v72;                         // xmm1_4
  float v73;                         // xmm0_4
  int v74;                           // eax
  int v75;                           // edi
  int v76;                           // ebx
  float *v77;                        // esi
  float v78;                         // xmm2_4
  float v79;                         // xmm3_4
  float v80;                         // xmm3_4
  float v81;                         // xmm0_4
  __m128 v82;                        // xmm0
  __m128 v83;                        // xmm1
  __m128 v84;                        // xmm1
  __m128 v85;                        // xmm2
  __m128 v86;                        // xmm0
  float *v87;                        // eax
  float v88;                         // ebx
  void *v89;                         // ebx
  const char *v90;                   // eax
  char *v91;                         // eax
  int v92;                           // edi
  const char *v93;                   // ebx
  int v94;                           // esi
  char *v95;                         // esi
  Font_s *FontHandle;                // ebx
  float v97;                         // xmm0_4
  const char *v98;                   // [esp+4h] [ebp-724h]
  const char *v99;                   // [esp+4h] [ebp-724h]
  float v100;                        // [esp+3Ch] [ebp-6ECh]
  float v101;                        // [esp+3Ch] [ebp-6ECh]
  float v102;                        // [esp+3Ch] [ebp-6ECh]
  float v103;                        // [esp+3Ch] [ebp-6ECh]
  float v104;                        // [esp+3Ch] [ebp-6ECh]
  float v105;                        // [esp+3Ch] [ebp-6ECh]
  float v106;                        // [esp+50h] [ebp-6D8h]
  int v107;                          // [esp+7Ch] [ebp-6ACh]
  float v108;                        // [esp+88h] [ebp-6A0h]
  float v109;                        // [esp+8Ch] [ebp-69Ch]
  float v110;                        // [esp+90h] [ebp-698h]
  int *v111;                         // [esp+98h] [ebp-690h]
  bool v112;                         // [esp+9Fh] [ebp-689h]
  int v113;                          // [esp+A0h] [ebp-688h]
  int v114;                          // [esp+A4h] [ebp-684h]
  float v115;                        // [esp+ACh] [ebp-67Ch]
  statmonitor_s *v116;               // [esp+B0h] [ebp-678h]
  float RealWidthFromVirtualWidth;   // [esp+B4h] [ebp-674h]
  float RealHeightFromVirtualHeight; // [esp+B8h] [ebp-670h]
  float v119;                        // [esp+BCh] [ebp-66Ch]
  float v120;                        // [esp+C0h] [ebp-668h]
  float v121;                        // [esp+C8h] [ebp-660h]
  statmonitor_s *v122;               // [esp+CCh] [ebp-65Ch]
  float v123;                        // [esp+D0h] [ebp-658h]
  float v124;                        // [esp+D4h] [ebp-654h]
  unsigned int v125;                 // [esp+D8h] [ebp-650h]
  float v126;                        // [esp+DCh] [ebp-64Ch]
  Font_s *v127;                      // [esp+E4h] [ebp-644h]
  float v128;                        // [esp+E8h] [ebp-640h]
  float v129;                        // [esp+ECh] [ebp-63Ch]
  float v130;                        // [esp+F0h] [ebp-638h]
  float v131;                        // [esp+F4h] [ebp-634h]
  float v132;                        // [esp+F8h] [ebp-630h]
  float v133;                        // [esp+FCh] [ebp-62Ch]
  char v134[4];                      // [esp+108h] [ebp-620h] BYREF
  float v135;                        // [esp+10Ch] [ebp-61Ch]
  float v136;                        // [esp+110h] [ebp-618h]
  float v137;                        // [esp+114h] [ebp-614h]
  char __dst[4];                     // [esp+508h] [ebp-220h] BYREF
  float v139;                        // [esp+50Ch] [ebp-21Ch]
  float v140;                        // [esp+510h] [ebp-218h]
  float v141;                        // [esp+514h] [ebp-214h]
  char __src[8];                     // [esp+608h] [ebp-120h] BYREF
  float v143;                        // [esp+610h] [ebp-118h]
  float v144;                        // [esp+614h] [ebp-114h]
  float v145;                        // [esp+618h] [ebp-110h]
  float v146;                        // [esp+61Ch] [ebp-10Ch]
  float v147;                        // [esp+620h] [ebp-108h]
  float v148;                        // [esp+624h] [ebp-104h]
  float v149;                        // [esp+708h] [ebp-20h] BYREF
  statmonitor_s *v150[7];            // [esp+70Ch] [ebp-1Ch] BYREF

  v2 = (float *)cg;
  if (*((_DWORD *)cg + 3) || !*(_BYTE *)(cg_draw2D + 8))
    return;
  v3 = *((float *)cg + 44905);
  if (v3 != 0.0) {
    if (*((_DWORD *)cg + 44904) -
            *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) <=
        0) {
      *(_DWORD *)((char *)&loc_2BDA8 + (_DWORD)cg) = *((_DWORD *)cg + 44910);
      *(float *)((char *)&loc_2BDAC + (_DWORD)v2) = v2[44911];
      v2[44908] = v2[44912];
      v2[44909] = *(float *)((char *)&loc_2BDC4 + (_DWORD)v2);
      if (v2[44909] == 0.0)
        v2[44905] = 0.0;
      else
        UI_FillRectPhysical(0, (float)dword_14C13C4, (float)dword_14C13C8,
                            (float *)((char *)&loc_2BDA8 + (_DWORD)v2));
    } else {
      v4 = (float)(*((_DWORD *)cg + 44904) -
                   *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg)) *
           v3;
      v5 = (__m128)0x3F800000u;
      v5.f32[0] = 1.0 - v4;
      for (i = 0; i != 4; ++i) {
        a2 = v5;
        *(float *)&v134[4 * i] =
            (float)(v4 * *(float *)((char *)&loc_2BDA8 + (_DWORD)&v2[i])) +
            (float)(v5.f32[0] * v2[i + 44910]);
      }
      if (v137 != 0.0)
        UI_FillRectPhysical(0, (float)dword_14C13C4, (float)dword_14C13C8,
                            (float *)v134);
    }
  }
  v7 = !CG_AreHudMenusHidden();
  v112 = !CG_AreHudElemsHidden();
  v8 = cg;
  v9 = *(_DWORD *)(*((_DWORD *)cg + 9) + 16);
  if (v9 == 5) {
    CL_CloseAllMenus();
    v8[44365] = 1;
    v8[44366] = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v8);
    CG_DrawScoreboard(a1);
    return;
  }
  if (v9 != 4) {
    if (v9 <= 5)
      CG_DrawCrosshair();
    if (v7) {
      if (*(int *)(v8[9] + 16) <= 5)
        CG_DrawCrosshairNames(a1);
      CG_DrawChatMessages(a1);
      CG_CheckTimedMenus();
      if (!v112)
        goto LABEL_15;
    } else {
      CG_CheckTimedMenus();
      if (!v112) {
      LABEL_15:
        if (v7)
          Menu_PaintAll(a1, &cgDC);
        CG_Draw2dHudElems(a1, 1);
        goto LABEL_18;
      }
    }
    CG_Draw2dHudElems(a1, 0);
    goto LABEL_15;
  }
  if (v7) {
    v95 = (char *)UI_SafeTranslateString("CGAME_SPECTATOR");
    FontHandle = (Font_s *)UI_GetFontHandle(4, 0.5);
    v97 = (float)-UI_TextWidth(a1, v95, 0, FontHandle, 0.5) * 0.5;
    UI_DrawText(a1, v95, 0x7FFFFFFF, FontHandle, v97, -27.0, 7, 3, 0.5);
    CG_DrawCrosshairNames(a1);
    CG_DrawChatMessages(a1);
  }
  if (v112) {
    CG_Draw2dHudElems(a1, 0);
    CG_Draw2dHudElems(a1, 1);
  }
LABEL_18:
  v111 = CG_DrawScoreboard(a1);
  if (!v7)
    return;
  if (*((_DWORD *)cg + 9)) {
    v10 = *(_DWORD *)((char *)&loc_2BF0C + (_DWORD)cg);
    v11 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
    if (v10 > v11) {
      v12 = fabs((float)((float)(v10 - v11) * *((float *)cg + 44996)) / 500.0);
      if (v12 <= 5.0)
        v13 = v12 / 5.0;
      else
        v13 = 1.0;
      *(float *)v134 = 0.2;
      v135 = 0.0;
      v136 = 0.0;
      v137 = v13 * 0.69999999;
      a2 = (__m128)0x41200000u;
      UI_FillRectPhysical(0xC1200000C1200000LL, (float)dword_14C13C4 + 10.0,
                          (float)dword_14C13C8 + 10.0, (float *)v134);
    }
    v14 = cg;
  } else {
    v14 = cg;
  }
  if (!v14[9])
    goto LABEL_34;
  ViewmodelWeaponIndex = BG_GetViewmodelWeaponIndex(
      (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v14));
  WeaponDef = BG_GetWeaponDef(ViewmodelWeaponIndex);
  a2 = (__m128) * (unsigned int *)((char *)&loc_25CA0 + (_DWORD)v14);
  if (!**(_BYTE **)(WeaponDef + 628) && !*(_DWORD *)(WeaponDef + 632) ||
      a2.f32[0] == 0.0)
    goto LABEL_28;
  if (v14[41253])
    v48 = *(float *)(WeaponDef + 620);
  else
    v48 = *(float *)(WeaponDef + 624);
  v49 = a2.f32[0] - (float)(1.0 - v48);
  v50 = v49;
  if (v49 > 0.0)
    v50 = v49 / v48;
  if (v50 <= 0.0099999998) {
  LABEL_28:
    v149 = 320.0;
    v150[0] = (statmonitor_s *)1131413504;
    goto LABEL_29;
  }
  if (*(_BYTE *)(cg_hudDamageIconInScope + 8)) {
    CG_CalcCrosshairPosition(&v149, (float *)v150);
    v149 = v149 + 320.0;
    *(float *)v150 = *(float *)v150 + 240.0;
  LABEL_29:
    v17 = (__m128)0x3F000000u;
    v18 = *(float *)(cg_hudDamageIconOffset + 8) +
          *(float *)(cg_hudDamageIconHeight + 8);
    *(float *)__src = 0.5 * *(float *)(cg_hudDamageIconWidth + 8);
    v17.f32[0] = *(float *)__src;
    *(float *)&__src[4] = v18;
    v19 = (__m128) * (unsigned int *)(cg_hudDamageIconOffset + 8);
    v19.f32[0] = v19.f32[0] + *(float *)(cg_hudDamageIconHeight + 8);
    a2 = _mm_xor_ps(v17, (__m128)xmmword_303410);
    v143 = a2.f32[0];
    v144 = v19.f32[0];
    v20 = *(float *)(cg_hudDamageIconOffset + 8);
    v145 = a2.f32[0];
    v146 = v20;
    v21 = *(float *)(cg_hudDamageIconOffset + 8);
    v147 = *(float *)__src;
    v148 = v21;
    CalcScreenX(&v149, 0);
    CalcScreenY((float *)v150, 0);
    *(float *)v134 = colorWhite[0];
    v135 = colorWhite[1];
    v136 = colorWhite[2];
    v137 = colorWhite[3];
    v113 = 0;
    v107 = 0;
    do {
      while (1) {
        v22 = (float *)((char *)cg + v107);
        v23 = *(_DWORD *)((char *)cg + v107 + 179832);
        v24 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) -
              *(_DWORD *)((char *)cg + v107 + 179828);
        if (v24 > 0 && v23 > v24)
          break;
        ++v113;
        v107 += 12;
        if (v113 == 8)
          goto LABEL_34;
      }
      a1 = vectoyaw((const float *)cg + 41317);
      v100 = a1;
      v25 = v100 - v22[44959];
      v19.f32[0] = (float)((float)((float)v24 * -2.0) / (float)v23) + 2.0;
      v26 = v19;
      v26.f32[0] = v19.f32[0] - 1.0;
      v27.i32[0] = 0;
      v28 = _mm_cmplt_ss(v26, v27);
      a2 = _mm_or_ps(_mm_andnot_ps(v28, (__m128)0x3F800000u),
                     _mm_and_ps(v19, v28));
      v137 = a2.f32[0];
      CG_DrawRotatedQuadPic(v149, *(float *)v150, (const float(*)[2])__src,
                            v25);
      ++v113;
      v107 += 12;
    } while (v113 != 8);
  }
LABEL_34:
  v29 = cg;
  if (*((_DWORD *)cg + 9) && *((_DWORD *)cg + 38642) != 4 &&
      (*((_BYTE *)cg + 154578) & 0x40) == 0) {
    v69 = BG_GetViewmodelWeaponIndex(
        (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg));
    v70 = BG_GetWeaponDef(v69);
    a2 = (__m128) * (unsigned int *)((char *)&loc_25CA0 + (_DWORD)v29);
    if (!**(_BYTE **)(v70 + 628) && !*(_DWORD *)(v70 + 632))
      goto LABEL_165;
    if (a2.f32[0] == 0.0)
      goto LABEL_165;
    if (v29[41253])
      v71 = *(float *)(v70 + 620);
    else
      v71 = *(float *)(v70 + 624);
    v72 = a2.f32[0] - (float)(1.0 - v71);
    v73 = v72;
    if (v72 > 0.0)
      v73 = v72 / v71;
    if (v73 > 0.0099999998) {
      if (!*(_BYTE *)(cg_hudGrenadeIconInScope + 8))
        goto LABEL_37;
      CG_CalcCrosshairPosition((float *)v150, &v149);
    } else {
    LABEL_165:
      v150[0] = 0;
      v149 = 0.0;
    }
    CalcScreenX((float *)v150, 2);
    CalcScreenY(&v149, 2);
    v74 = *((_DWORD *)cg + 9);
    if (*(int *)(v74 + 9908) > 0) {
      v114 = 0;
      v75 = 9904;
      do {
        v76 = v74 + v75;
        v77 = (float *)(v74 + v75 + 12);
        if (*(_DWORD *)(v74 + v75 + 16) == 4) {
          a2 = (__m128) * (unsigned int *)(v76 + 52);
          if ((float)((float)((float)(*(float *)(v76 + 48) *
                                      *(float *)(v76 + 48)) +
                              (float)(a2.f32[0] * a2.f32[0])) +
                      (float)(*(float *)(v76 + 56) * *(float *)(v76 + 56))) <=
                  1.0 &&
              !*(_DWORD *)(BG_GetWeaponDef(*(_DWORD *)(v74 + v75 + 212)) +
                           912)) {
            a2 = (__m128) * (unsigned int *)(v76 + 44);
            a2.f32[0] = a2.f32[0] - *((float *)cg + 38648);
            if (a2.f32[0] < 0.0) {
              if ((float)-*(float *)(cg_hudGrenadeIconMaxHeight + 8) <=
                  a2.f32[0]) {
              LABEL_155:
                v78 = *(float *)(v76 + 36) - *((float *)cg + 38646);
                v79 = *(float *)(v76 + 40) - *((float *)cg + 38647);
                if ((float)((float)((float)(v78 * v78) + (float)(v79 * v79)) +
                            (float)(a2.f32[0] * a2.f32[0])) <=
                    (float)(*(float *)(cg_hudGrenadeIconMaxRange + 8) *
                            *(float *)(cg_hudGrenadeIconMaxRange + 8))) {
                  *(float *)v134 = v77[6] - *((float *)cg + 38646);
                  v135 = v77[7] - *((float *)cg + 38647);
                  v136 = v77[8] - *((float *)cg + 38648);
                  *(float *)__dst = colorWhite[0];
                  v139 = colorWhite[1];
                  v140 = colorWhite[2];
                  v141 = colorWhite[3];
                  v80 = *(float *)(cg_hudGrenadePointerPulseMin + 8);
                  v81 = (double)*(int *)((char *)&loc_25BB0 + (_DWORD)cg) *
                        0.006283185307179587 *
                        *(float *)(cg_hudGrenadePointerPulseFreq + 8);
                  v106 = (float)(*(float *)(cg_hudGrenadePointerPulseMax + 8) -
                                 v80) *
                         0.5;
                  v101 = sinf(v81);
                  v82 = (__m128)LODWORD(v101);
                  v82.f32[0] = (float)(v101 * v106) + (float)(v80 + v106);
                  v83 = v82;
                  v83.f32[0] = v82.f32[0] - 1.0;
                  v84 = _mm_cmpge_ss(v83, (__m128)0LL);
                  v84.i32[0] =
                      _mm_andnot_ps(v84, v82).u32[0] | v84.i32[0] & 0x3F800000;
                  v85 = 0;
                  v85.f32[0] = 0.0 - v82.f32[0];
                  v86 = _mm_cmplt_ss(v85, (__m128)0LL);
                  LODWORD(v141) = _mm_andnot_ps(v86, (__m128)0LL).u32[0] |
                                  v84.i32[0] & v86.i32[0];
                  v115 = v149;
                  v116 = v150[0];
                  RealWidthFromVirtualWidth = GetRealWidthFromVirtualWidth(
                      *(float *)(cg_hudGrenadePointerWidth + 8));
                  RealHeightFromVirtualHeight = GetRealHeightFromVirtualHeight(
                      *(float *)(cg_hudGrenadePointerHeight + 8));
                  v119 = GetRealHeightFromVirtualHeight(
                      *(float *)(cg_hudGrenadeIconOffset + 8));
                  v87 = *(float **)(cg_hudGrenadePointerPivot + 8);
                  v88 = v87[1];
                  v133 = GetRealWidthFromVirtualWidth(*v87);
                  v132 = GetRealHeightFromVirtualHeight(v88);
                  v102 = vectoyaw((const float *)v134);
                  v89 = cg;
                  v120 = AngleNormalize360(
                      v102 - *(float *)((char *)&loc_25CB0 + (_DWORD)cg));
                  v86.f32[0] = v120 * 0.0174532925199433;
                  v103 = sinf(v86.f32[0]);
                  v110 = cosf(v86.f32[0]);
                  v147 = -v133;
                  *(float *)__src = -v133;
                  v145 = RealWidthFromVirtualWidth - v133;
                  v143 = RealWidthFromVirtualWidth - v133;
                  v144 = -v132;
                  *(float *)&__src[4] = -v132;
                  v148 = RealHeightFromVirtualHeight - v132;
                  v146 = RealHeightFromVirtualHeight - v132;
                  CG_DrawRotatedQuadPic(
                      *(float *)&v116 - (float)(v103 * v119),
                      v115 - (float)(v119 * v110), (const float(*)[2])__src,
                      COERCE_FLOAT(LODWORD(v120) ^ 0x80000000));
                  v121 = v149;
                  v122 = v150[0];
                  v123 = GetRealWidthFromVirtualWidth(
                      *(float *)(cg_hudGrenadeIconWidth + 8));
                  v124 = GetRealHeightFromVirtualHeight(
                      *(float *)(cg_hudGrenadeIconHeight + 8));
                  *(float *)&v125 = GetRealHeightFromVirtualHeight(
                      *(float *)(cg_hudGrenadeIconOffset + 8));
                  v104 = vectoyaw((const float *)v134);
                  v126 = AngleNormalize360(
                      v104 - *(float *)((char *)&loc_25CB0 + (_DWORD)v89));
                  v86.f32[0] = v126 * 0.0174532925199433;
                  v109 = cosf(v86.f32[0]);
                  a1 = sinf(v86.f32[0]);
                  v105 = a1;
                  v147 = (float)((float)(v123 * -0.5) + *(float *)&v122) -
                         (float)(v105 * *(float *)&v125);
                  *(float *)__src = v147;
                  v145 = (float)((float)(v123 * 0.5) + *(float *)&v122) -
                         (float)(v105 * *(float *)&v125);
                  v143 = v145;
                  a2 = (__m128)v125;
                  v144 = (float)((float)(v124 * -0.5) + v121) -
                         (float)(*(float *)&v125 * v109);
                  *(float *)&__src[4] = v144;
                  v148 = (float)((float)(v124 * 0.5) + v121) -
                         (float)(*(float *)&v125 * v109);
                  v146 = v148;
                  CL_DrawQuadPic();
                }
              }
            } else if (a2.f32[0] <=
                       (float)(*(float *)(cg_hudGrenadeIconMaxHeight + 8) +
                               *((float *)cg + 38703))) {
              goto LABEL_155;
            }
          }
        }
        ++v114;
        v75 += 240;
        v74 = *((_DWORD *)cg + 9);
      } while (*(_DWORD *)(v74 + 9908) > v114);
    }
  }
LABEL_37:
  if (!v111) {
    CG_DrawSpectatorMessage(a1);
    CG_DrawFollow(a1);
  }
  if (*((_DWORD *)cgs + 6178)) {
    v127 = (Font_s *)UI_GetFontHandle(0, 0.20833333);
    if (GetKeyBindingLocalizedString("vote yes", __src))
      I_strncpyz(__dst, __src, 256);
    else
      I_strncpyz(__dst, "vote yes", 256);
    if (GetKeyBindingLocalizedString("vote no", __src))
      I_strncpyz(v134, __src, 256);
    else
      I_strncpyz(v134, "vote no", 256);
    v40 = (const char *)cgs;
    v41 = (*((_DWORD *)cgs + 6178) -
           *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg)) /
          1000;
    if (v41 < 0)
      v41 = 0;
    if ((*(_BYTE *)(*((_DWORD *)cg + 9) + 174) & 0x10) != 0) {
      v42 = UI_SafeTranslateString("CGAME_VOTE");
      v43 = va("%s(%i):%s", v42, v41, v40 + 24724);
      UI_DrawText(a1, v43, 0x7FFFFFFF, v127, 8.0, 200.0, 0, 0, 0.20833333);
      v44 = *((_DWORD *)v40 + 6180);
      v45 = UI_SafeTranslateString("CGAME_NO");
      v46 = *((_DWORD *)v40 + 6179);
      v98 = UI_SafeTranslateString("CGAME_YES");
      v47 = va("%s:%i, %s:%i", v98, v46, v45, v44);
    } else {
      v90 = UI_SafeTranslateString("CGAME_VOTE");
      v91 = va("%s(%i):%s", v90, v41, v40 + 24724);
      UI_DrawText(a1, v91, 0x7FFFFFFF, v127, 8.0, 200.0, 0, 0, 0.20833333);
      v92 = *((_DWORD *)v40 + 6180);
      v93 = UI_SafeTranslateString("CGAME_NO");
      v94 = *((_DWORD *)v40 + 6179);
      v99 = UI_SafeTranslateString("CGAME_YES");
      v47 = va("%s(%s):%i, %s(%s):%i", v99, __dst, v94, v93, v134, v92);
    }
    UI_DrawText(a1, v47, 0x7FFFFFFF, v127, 8.0, 210.0, 0, 0, 0.20833333);
  }
  if (*(_BYTE *)(cg_drawLagometer + 8) && !*((_DWORD *)cgs + 6056)) {
    UI_DrawHandlePic(-55.0, -140.0, 48.0, 48.0, 3, 3, 0,
                     *((Material **)cgs + 11920));
    v30 = 0;
    v31 = 0.0;
    do {
      a2.f32[0] =
          (float)lagometer[((_BYTE)dword_195B380 + ~(_BYTE)v30) & 0x7F] *
          0.053333335;
      if (a2.f32[0] <= 0.0) {
        if (a2.f32[0] < 0.0) {
          a2 = _mm_xor_ps(a2, (__m128)xmmword_303410);
          v51 = _mm_cmplt_ss((__m128)0x41800000u, a2);
          CL_DrawStretchPic(-7.0 - v31, -124.0, 1.0,
                            COERCE_FLOAT(_mm_andnot_ps(v51, a2).u32[0] |
                                         v51.i32[0] & 0x41800000),
                            3, 3, 0.0, 0.0, 0.0, 0.0, colorBlue,
                            *((Material **)cgs + 11911));
        }
      } else {
        if (a2.f32[0] <= 16.0) {
          v32 = -124.0 - a2.f32[0];
        } else {
          a2 = (__m128)0x41800000u;
          v32 = -140.0;
        }
        CL_DrawStretchPic(-7.0 - v31, v32, 1.0, a2.f32[0], 3, 3, 0.0, 0.0, 0.0,
                          0.0, colorYellow, *((Material **)cgs + 11911));
      }
      v31 = (float)++v30;
    } while (v30 != 48);
    LOBYTE(v30) = 0;
    v53 = 0.0;
    while (1) {
      v57 = ((_BYTE)dword_195B784 + ~(_BYTE)v30) & 0x7F;
      v58 = (float)dword_195B584[v57];
      if (v58 <= 0.0) {
        if (v58 < 0.0)
          CL_DrawStretchPic(-7.0 - v53, -116.0, 1.0, 24.0, 3, 3, 0.0, 0.0, 0.0,
                            0.0, &colorRed, *((Material **)cgs + 11911));
        goto LABEL_111;
      }
      if ((dword_195B384[v57] & 1) != 0) {
        v54 = colorYellow;
        v55 = v58 * 0.026666667;
        if (v55 > 24.0) {
        LABEL_115:
          v55 = 24.0;
          v56 = -116.0;
          goto LABEL_110;
        }
      } else {
        v54 = colorGreen;
        v55 = v58 * 0.026666667;
        if (v55 > 24.0)
          goto LABEL_115;
      }
      v56 = -92.0 - v55;
    LABEL_110:
      CL_DrawStretchPic(-7.0 - v53, v56, 1.0, v55, 3, 3, 0.0, 0.0, 0.0, 0.0,
                        v54, *((Material **)cgs + 11911));
    LABEL_111:
      v53 = (float)++v30;
      if (v30 == 48) {
        if (*(_BYTE *)(cg_nopredict + 8) ||
            *(_BYTE *)(cg_synchronousClients + 8))
          CG_DrawBigDevString(-55.0, -140.0, "snc", 1.0, 9);
        break;
      }
    }
  }
  CG_DrawDisconnect(a1);
  v33 = Sys_Milliseconds();
  StatMon_GetStatsArray((const statmonitor_s **)v150, (int *)&v149);
  if (SLODWORD(v149) > 0) {
    v37 = 2.0;
    v128 = 200.0;
    v38 = 0.0;
    do {
      v39 = &v150[0][LODWORD(v38)];
      if (v33 <= (signed int)v39->endtime)
        UI_DrawHandlePic(v37, v128, 32.0, 32.0, 1, 0, 0,
                         (Material *)v39->material);
      v37 = v37 + 34.0;
      if ((float)(v37 + 32.0) > 68.0) {
        v128 = v128 + 34.0;
        v37 = 2.0;
      }
      ++LODWORD(v38);
    } while (SLODWORD(v38) < SLODWORD(v149));
  }
  if (*(_DWORD *)(cg_drawSoundOverlay + 8)) {
    CG_DrawSoundOverlay(a1);
  } else if (*(_BYTE *)(cg_drawScriptUsage + 8)) {
    CG_DrawScriptUsage(a1);
  } else if (*(_BYTE *)(cg_drawMaterial + 8)) {
    CG_DrawMaterial();
  }
  CL_TrackStatistics();
  v34 = 0;
  if (*(_BYTE *)(cg_drawSnapshot + 8)) {
    v52 = va("time:%i snap:%i cmd:%i", *(_DWORD *)(*((_DWORD *)cg + 9) + 8),
             *((_DWORD *)cg + 6), *((_DWORD *)cgs + 6054));
    v34.f32[0] =
        (float)CG_DrawBigDevStringColor(620.0, 0.0, v52, colorWhite, 6) + 0.0;
  }
  if (*(_DWORD *)(cg_drawFPS + 8))
    CG_DrawFPS(v34);
  if (!v111) {
    v35 = (int *)cg;
    v36 = *(_DWORD *)((char *)&loc_2B990 + (_DWORD)cg);
    if (v36) {
      if (CG_FadeColor(
              v36, (int)(float)(1000.0 * *(float *)(cg_centertime + 8)), 100)) {
        v61 = (char *)(v35 + 44646);
        v131 = (float)v35[44645] * 0.03125;
        if ((unsigned __int8)CL_IsRenderingSplitScreen())
          v131 = v131 * 1.25;
        v62 = (Font_s *)UI_GetFontHandle(0, v131);
        v63 = UI_TextHeight(a1, v62, v131);
        v130 = (float)((float)((float)v63 * -1.2) * (float)v35[44902]) +
               *(float *)(cg_centerPrintY + 8);
        v129 = (float)v63 * 1.2;
        while (1) {
          for (j = 0; j != 75; ++j) {
            v65 = v61[j];
            if (!v65)
              break;
            if (v65 == 10)
              break;
            v134[j] = v65;
          }
          v134[j] = 0;
          v66 = (Font_s *)UI_GetFontHandle(0, v131);
          v67 = UI_TextWidth(a1, v134, 0, v66, v131);
          UI_DrawText(a1, v134, 0x7FFFFFFF, v66, (float)v67 * -0.5, v130, 7, 3,
                      v131);
          v130 = v130 + v129;
          v68 = *v61;
          if (!*v61)
            break;
          while (v68 != 10) {
            v68 = *++v61;
            if (!*v61)
              goto LABEL_63;
          }
          ++v61;
        }
      } else {
        *(_DWORD *)((char *)&loc_2B990 + (_DWORD)v35) = 0;
        v35[44903] = 0;
      }
    }
  LABEL_63:
    if (!*(_BYTE *)(cg_drawGameMessages + 8))
      goto LABEL_64;
    v108 = floorf(
        (float)((float)(*((float *)cgs + 12420) -
                        (float)((float)(*(float *)(cg_hudCompassSize + 8) -
                                        1.0) *
                                *((float *)cgs + 12419))) +
                12.0) +
        0.5);
    if (CG_ScoreboardDisplayed()) {
      v59 = CG_FadeColor(*((_DWORD *)cg + 44366), 100, 100);
      if (!v59) {
      LABEL_64:
        CG_DrawBoldGameMessages();
        if (*(_BYTE *)(cg_minicon + 8))
          Con_DrawMiniConsole(2, 4, 1.0);
        if (*(_BYTE *)(cg_subtitles + 8))
          Con_DrawSubtitles(*(_DWORD *)(cg_subtitlePosX + 8),
                            *(_DWORD *)(cg_subtitlePosY + 8),
                            *(MessageWindow **)(cg_subtitleCharHeight + 8), 1.0,
                            MWM_BOTTOMUP);
        Con_DrawSay((int)*(float *)(*(_DWORD *)(cg_hudSayPosition + 8) + 4) +
                    24);
        return;
      }
      v60 = *((float *)v59 + 3);
    } else {
      v60 = 1.0;
    }
    Con_DrawNotify(6, (int)v108, v60, 2);
    goto LABEL_64;
  }
}

struct lagometer_t lagometer;
int *sortedTeamPlayers;
int numSortedTeamPlayers;
struct menuDef_t *menuScoreboard;
int __cdecl CG_CheckPlayerMiscInput(int) { UNIMPLEMENTED(); }

int __cdecl CG_CheckPlayerFireNonTurret(int) { UNIMPLEMENTED(); }

int __cdecl CG_CheckPlayerTryReload(int) { UNIMPLEMENTED(); }

int __cdecl CG_CheckPlayerMovement(struct usercmd_s, struct usercmd_s) {
  UNIMPLEMENTED();
}

void __cdecl CG_TransitionToAds(struct WeaponDef const *, float, float *,
                                float *) {
  UNIMPLEMENTED();
}

bool __cdecl CG_IsValidHudGrenade(struct entityState_s const *) {
  UNIMPLEMENTED();
}

void __cdecl CG_CalcReticleImageOffset(struct Material *, float *const,
                                       float *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_CalcReticleColor(float const *const, float, float *const) {
  UNIMPLEMENTED();
}

bool __cdecl CG_IsReticleTurnedOff(void) { UNIMPLEMENTED(); }

void __cdecl CG_CalcCrosshairColor(float, float *const) { UNIMPLEMENTED(); }

int __cdecl CG_UpdateCameraShake(struct cameraShake_t *) { UNIMPLEMENTED(); }

void __cdecl CG_CheckHudObjectiveDisplay(void) { UNIMPLEMENTED(); }

void __cdecl CG_CheckHudOffHandDisplay(void) { UNIMPLEMENTED(); }

void __cdecl CG_CheckHudStanceDisplay(void) { UNIMPLEMENTED(); }

void __cdecl CG_CheckHudCompassDisplay(void) { UNIMPLEMENTED(); }

void __cdecl CG_CheckHudAmmoDisplay(void) { UNIMPLEMENTED(); }

void __cdecl CG_CheckHudHealthDisplay(void) { UNIMPLEMENTED(); }

int __cdecl CG_CheckPlayerOffHandUsage(int) { UNIMPLEMENTED(); }

int __cdecl CG_CheckPlayerWeaponUsage(int) { UNIMPLEMENTED(); }

int __cdecl CG_CheckPlayerStanceChange(int, int) { UNIMPLEMENTED(); }

void __cdecl CG_CalcReticleSpread(struct WeaponDef const *, int,
                                  float const *const, float, float *const) {
  UNIMPLEMENTED();
}

bool __cdecl CG_AllowedToDrawCrosshair(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawSavedScreenBlend(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawGrenadeIcon(float, float, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawGrenadePointer(float, float, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawFlashDamage(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawReticleCenter(struct WeaponDef const *, int,
                                  float const *const, float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawAdsAimIndicator(struct WeaponDef const *, int,
                                    float const *const, float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawAdsOverlay(struct WeaponDef const *, int,
                               float const *const, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl CG_CalcCrosshairPosition(float *, float *) {
  float *v4;       // ebx
  float v5;        // ecx
  float v6;        // edx
  float v7;        // xmm2_4
  float v8;        // xmm0_4
  float v9;        // xmm0_4
  float v10;       // xmm0_4
  long double v11; // [esp+0h] [ebp-78h]
  long double v12; // [esp+0h] [ebp-78h]
  float v13;       // [esp+20h] [ebp-58h]
  float v14;       // [esp+20h] [ebp-58h]
  float v15;       // [esp+48h] [ebp-30h] BYREF
  float v16;       // [esp+4Ch] [ebp-2Ch]
  float v17;       // [esp+50h] [ebp-28h]
  float v18[9];    // [esp+54h] [ebp-24h] BYREF

  v4 = (float *)cg;
  v5 = *((float *)cg + 41332);
  v6 = *((float *)cg + 45093);
  v18[0] = *(float *)((char *)&loc_2C090 + (_DWORD)cg);
  v18[1] = v6;
  v18[2] = v5;
  AngleVectors(v18, &v15, 0, 0);
  v7 = (float)((float)(v15 * *(float *)((char *)&loc_28594 + (_DWORD)v4)) +
               (float)(v16 * *(float *)((char *)&loc_28594 + (_DWORD)v4 + 4))) +
       (float)(v17 * *(float *)((char *)&loc_28594 + (_DWORD)v4 + 8));
  if (v7 <= 0.0 || (v8 = v4[41312], v8 <= 0.0) ||
      *(float *)((char *)&loc_28584 + (_DWORD)v4) <= 0.0) {
    *a1 = 0.0;
    *a2 = 0.0;
  } else {
    *(double *)&v11 = v8 * 0.008726646259971648;
    v13 = (float)((float)(v15 * v4[41320]) + (float)(v16 * v4[41321])) +
          (float)(v17 * v4[41322]);
    v9 = tan(v11);
    *a1 = (float)(v13 / (float)(v9 * v7)) * -320.0;
    *(double *)&v12 =
        *(float *)((char *)&loc_28584 + (_DWORD)v4) * 0.008726646259971648;
    v14 = (float)((float)(v4[41323] * v15) + (float)(v4[41324] * v16)) +
          (float)(v4[41325] * v17);
    v10 = tan(v12);
    *a2 = (float)(v14 / (float)(v7 * v10)) * -240.0;
  }
}

void __cdecl CG_DrawMaterial(void) {
  int result;    // eax
  float v1;      // xmm0_4
  float v2;      // [esp+20h] [ebp-2068h]
  char v3[4096]; // [esp+30h] [ebp-2058h] BYREF
  char v4[4096]; // [esp+1030h] [ebp-1058h] BYREF
  char v5[88];   // [esp+2030h] [ebp-58h] BYREF

  result = CL_PickMaterial();
  if (result) {
    v2 = (float)CG_DrawSmallDevStringColor(8.0, 240.0, v5, colorWhite, 5) +
         240.0;
    v1 = (float)CG_DrawSmallDevStringColor(8.0, v2, v4, colorWhite, 5);
    return CG_DrawSmallDevStringColor(8.0, v2 + v1, v3, colorWhite, 5);
  }
  return result;
}

void __cdecl CG_DrawGrenadeIndicators(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawDamageDirectionIndicators(void) { UNIMPLEMENTED(); }

float __cdecl CG_DrawWeapReticle(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawCenterString(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawChatMessages(void) { UNIMPLEMENTED(); }

float __cdecl CG_DrawFPS(float) { UNIMPLEMENTED(); }

float __cdecl CG_DrawSnapshot(float) { UNIMPLEMENTED(); }

void __cdecl CG_DrawScriptUsage(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawReticleSides(struct WeaponDef const *, int,
                                 float const *const, float, float, float) {
  UNIMPLEMENTED();
}

void __cdecl CG_DrawSoundOverlay(void) { UNIMPLEMENTED(); }

void __cdecl CG_ScanForCrosshairEntity(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawCrosshairNames(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawSpectator(void) { UNIMPLEMENTED(); }

int __cdecl CG_DrawFollow(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawSpectatorMessage(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawVote(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawIntermission(void) { UNIMPLEMENTED(); }

void __cdecl CG_CheckForPlayerInput(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawDisconnect(void) { UNIMPLEMENTED(); }

void __cdecl CG_DrawLagometer(void) { UNIMPLEMENTED(); }
