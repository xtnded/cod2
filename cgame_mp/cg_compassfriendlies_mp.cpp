void __cdecl Vec4Copy(float const *const, float *const) { UNIMPLEMENTED(); }

void __cdecl CG_ApplyCompassPointerRadiusScale(float *radiusScale) {
  int result; // eax
  float v2;   // xmm0_4

  result = cg_hudCompassSize;
  v2 = *(float *)(cg_hudCompassSize + 8) * 43.75 * *a1;
  *a1 = v2;
  return result;
}

void __cdecl CG_CalcCompassPointerRadius(float *, float) { UNIMPLEMENTED(); }

void __cdecl CG_CompassAddWeaponPingInfo(struct centity_s *cent,
                                         float const *const origin, int msec) {
  void *v3;   // ebx
  int v4;     // ecx
  int v5;     // edx
  int v6;     // eax
  bool v7;    // si
  float *v8;  // eax
  _DWORD *v9; // [esp+0h] [ebp-10h]

  if (*(_DWORD *)&a1->nextState[4] != 2) {
    v3 = cg;
    v9 = (char *)cg + 1208 * *((_DWORD *)cg + 1) + 919828;
    v4 = *(_DWORD *)a1->nextState;
    if (v9 != (_DWORD *)((char *)cg + 1208 * v4 + 919828)) {
      v5 = *((_DWORD *)cg + 302 * v4 + 229968);
      if (v5 != 3) {
        *(_DWORD *)((char *)&loc_2C5EC + (_DWORD)cg + 28 * v4) =
            *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) + a3;
        v6 = v9[11];
        v7 = !v6 || v5 != v6;
        *((_BYTE *)&loc_2C5F0 + (_DWORD)v3 + 28 * v4) = v7;
        if (*((_BYTE *)&loc_2C5F0 + (_DWORD)cg + 28 * v4)) {
          v8 = (float *)((char *)cg + 28 * v4 + 181712);
          v8[3] = *a2;
          v8[4] = a2[1];
        }
      }
    }
  }
}

void __cdecl CG_DrawCompassFriendlies(struct rectDef_s *rect,
                                      struct Material *material,
                                      float *const color) {
  const dvar_s *v3; // ebx
  _DWORD *v4;       // esi
  char *v5;         // eax
  char *v6;         // ebx
  int v7;           // edi
  int v8;           // edx
  float *v9;        // esi
  float v10;        // xmm0_4
  float v11;        // xmm0_4
  __m128 v12;       // xmm0
  int v13;          // edx
  int v14;          // eax
  __m128 v15;       // xmm1
  int v16;          // ecx
  int v17;          // ebx
  int v18;          // eax
  int v19;          // ecx
  char *v20;        // esi
  char *v21;        // eax
  int v22;          // edx
  char *v23;        // ecx
  char *v24;        // edx
  int v25;          // eax
  int v26;          // eax
  int v27;          // esi
  float v28;        // xmm1_4
  float v29;        // xmm0_4
  _DWORD *v30;      // edx
  float v31;        // xmm1_4
  float *v32;       // eax
  _DWORD *v33;      // ebx
  float *v34;       // eax
  float *v35;       // edx
  __m128 v36;       // xmm1
  char *v37;        // esi
  float *v38;       // ebx
  __m128 v39;       // xmm2
  float v40;        // xmm0_4
  int v41;          // edx
  float v42;        // xmm1_4
  float v43;        // xmm2_4
  int v44;          // eax
  float v45;        // xmm0_4
  float v46;        // xmm0_4
  void *v47;        // ebx
  int v48;          // eax
  int v49;          // ebx
  _BOOL4 v50;       // ecx
  int v51;          // edx
  int v52;          // ebx
  __m128 v53;       // xmm2
  __m128 v54;       // xmm0
  __m128 v55;       // xmm1
  int v56;          // eax
  float v57;        // [esp+3Ch] [ebp-ECh]
  float v58;        // [esp+3Ch] [ebp-ECh]
  float v59;        // [esp+3Ch] [ebp-ECh]
  float v60;        // [esp+40h] [ebp-E8h]
  float v61;        // [esp+50h] [ebp-D8h]
  int v62;          // [esp+6Ch] [ebp-BCh]
  int v63;          // [esp+70h] [ebp-B8h]
  float v64;        // [esp+74h] [ebp-B4h]
  float v65;        // [esp+78h] [ebp-B0h]
  float v66;        // [esp+7Ch] [ebp-ACh]
  float v67;        // [esp+80h] [ebp-A8h]
  char *v68;        // [esp+84h] [ebp-A4h]
  float v69;        // [esp+8Ch] [ebp-9Ch]
  float v70;        // [esp+90h] [ebp-98h]
  float v71;        // [esp+94h] [ebp-94h]
  float v72;        // [esp+98h] [ebp-90h]
  float v73;        // [esp+9Ch] [ebp-8Ch]
  int v74;          // [esp+A0h] [ebp-88h]
  _DWORD *v75;      // [esp+B8h] [ebp-70h]
  float v76;        // [esp+BCh] [ebp-6Ch]
  float v77;        // [esp+C0h] [ebp-68h]
  float v78;        // [esp+C4h] [ebp-64h]
  float v79;        // [esp+C8h] [ebp-60h]
  int v80;          // [esp+CCh] [ebp-5Ch]
  float v81[3];     // [esp+D8h] [ebp-50h] BYREF
  float v82;        // [esp+E4h] [ebp-44h]
  float v83;        // [esp+E8h] [ebp-40h]
  int v84;          // [esp+ECh] [ebp-3Ch]
  int v85;          // [esp+F0h] [ebp-38h]
  float v86;        // [esp+F4h] [ebp-34h]
  float v87;        // [esp+F8h] [ebp-30h] BYREF
  float v88;        // [esp+FCh] [ebp-2Ch]
  float v89;        // [esp+100h] [ebp-28h]
  float v90;        // [esp+104h] [ebp-24h]
  float v91;        // [esp+108h] [ebp-20h]
  float v92;        // [esp+10Ch] [ebp-1Ch]

  v3 = (const dvar_s *)hud_fade_compass;
  v69 = floorf((float)(1000.0 * *(float *)(hud_fade_compass + 8)) + 0.5);
  v4 = cg;
  v73 = CG_FadeHudMenu(v3, *((_DWORD *)cg + 45424), (int)v69);
  if (v73 != 0.0) {
    v5 = (char *)&v4[302 * *(_DWORD *)(v4[9] + 216)];
    if (*((_DWORD *)v5 + 229957)) {
      v74 = *((_DWORD *)v5 + 229968);
      if (v74 != 3) {
        CG_UpdateCompPointerOrientation();
        v70 = (float)(0.5 * (float)(*(float *)(cg_hudCompassSize + 8) *
                                    *(float *)&a1->w)) +
              *(float *)&a1->x;
        v71 = (float)((float)(*(float *)(cg_hudCompassSize + 8) *
                              *(float *)&a1->h) *
                      -0.5) +
              (float)(*(float *)&a1->h + *(float *)&a1->y);
        v81[0] = *a3;
        v81[1] = a3[1];
        v81[2] = a3[2];
        v82 = a3[3];
        if (v74) {
          v75 = v4;
          v16 = v4[9];
          if (*(int *)(v16 + 9908) <= 0) {
            v18 = v4[9];
          } else {
            v17 = 0;
            do {
              v19 = *(_DWORD *)(240 * v17 + v16 + 9916);
              v20 = (char *)cg_entities + 548 * v19;
              if (*((_DWORD *)v20 + 61) == 1 && (v20[250] & 2) == 0 &&
                  v19 >= 0) {
                v21 = (char *)&v75[302 * v19];
                if (*((_DWORD *)v21 + 229957)) {
                  if (v74 == *((_DWORD *)v21 + 229968)) {
                    v22 = 7 * v19;
                    v75[v22 + 45430] =
                        *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v75);
                    v68 = (char *)cg;
                    v23 = (char *)cg + 28 * v19 + 181712;
                    *((_DWORD *)v23 + 3) = *((_DWORD *)v20 + 123);
                    *((_DWORD *)v23 + 4) = *((_DWORD *)v20 + 124);
                    v24 = &v68[v22 * 4];
                    *((_DWORD *)v24 + 45433) = *((_DWORD *)v20 + 127);
                    if ((v20[250] & 0x40) != 0) {
                      v25 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v68);
                      if (*((_DWORD *)v24 + 45434) <= v25)
                        *((_DWORD *)v24 + 45434) = v25 + 3000;
                    }
                  }
                }
              }
              ++v17;
              v75 = cg;
              v16 = *((_DWORD *)cg + 9);
              v18 = v16;
            } while (*(_DWORD *)(v16 + 9908) > v17);
          }
          v26 = *(_DWORD *)(v18 + 1456);
          if (v26) {
            v27 = v26 & 0x3F;
            v75[7 * v27 + 45430] =
                *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v75);
            v28 = (float)(int)(((*(_DWORD *)(*((_DWORD *)cg + 9) + 1456) &
                                 0x7FC0u) >>
                                4) -
                               1020);
            v87 = v28;
            v29 = (float)(int)(((*(_DWORD *)(*((_DWORD *)cg + 9) + 1456) &
                                 0xFF8000u) >>
                                13) -
                               1020);
            v88 = v29;
            if (v28 == 1024.0 || v28 == -1020.0 || v29 == 1024.0 ||
                v29 == -1020.0) {
              Vec2Normalize(&v87);
              v34 = (float *)((char *)cg + 28 * v27 + 181712);
              v34[3] = v87;
              v34[4] = v88;
              v33 = cg;
            } else {
              v30 = cg;
              v31 = *(float *)((char *)&loc_2858C + (_DWORD)cg);
              v32 = (float *)((char *)cg + 28 * v27 + 181712);
              v32[3] = *((float *)cg + 41314) + v87;
              v32[4] = v31 + v88;
              v33 = v30;
            }
            v35 = (float *)&v33[7 * v27];
            v35[45433] = (float)*(char *)(v33[9] + 1459) * 1.40625;
            if (*(char *)(v33[9] + 174) < 0) {
              v56 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v33);
              if (*((_DWORD *)v35 + 45434) <= v56)
                *((_DWORD *)v35 + 45434) = v56 + 3000;
            }
          }
          if (a3[3] > v73)
            a3[3] = v73;
          v36 = _mm_cmplt_ss((__m128)LODWORD(v73), (__m128)LODWORD(v82));
          LODWORD(v82) = _mm_andnot_ps(v36, (__m128)LODWORD(v82)).u32[0] |
                         LODWORD(v73) & v36.i32[0];
          v37 = (char *)cg + 181748;
          v80 = 0;
          v63 = 45428;
          v62 = 0;
          do {
            v38 = (float *)cg;
            if (*((_DWORD *)v37 - 7) >
                *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg))
              *((_DWORD *)v37 - 7) = 0;
            if (*((_DWORD *)v37 - 7) >=
                    *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v38) - 800 &&
                v80 != *(_DWORD *)(*((_DWORD *)v38 + 9) + 216)) {
              v39 = (__m128)0x3F800000u;
              if (fabs(v38[v62 + 45431]) <= 1.0 &&
                  fabs(v38[v62 + 45432]) <= 1.0) {
                v59 = vectoyaw(&v38[v62 + 45431]);
                v72 = AngleNormalize360(v59 - v38[45422]);
                v43 = *(float *)(cg_hudCompassMaxRange + 8);
                v82 = *(float *)(cg_hudObjectiveMinAlpha + 8) +
                      (float)((float)(1.0 -
                                      *(float *)(cg_hudObjectiveMinAlpha + 8)) *
                              0.5);
                v44 = cg_hudCompassMinRange;
              } else {
                v87 = v38[v63 + 3] - v38[41314];
                v88 =
                    v38[v63 + 4] - *(float *)((char *)&loc_2858C + (_DWORD)v38);
                v58 = vectoyaw(&v87);
                v72 = AngleNormalize360(v58 - *((float *)cg + 45422));
                v39.f32[0] = fsqrt((float)(v87 * v87) + (float)(v88 * v88));
                v82 = v39.f32[0];
                v40 = *(float *)(cg_hudObjectiveMaxRange + 8);
                if (v39.f32[0] <= v40) {
                  v54 = (__m128) * (unsigned int *)(cg_hudCompassMaxRange + 8);
                  v55 = _mm_cmpge_ss(v39, v54);
                  LODWORD(v42) =
                      _mm_andnot_ps(v55, v54).u32[0] | v39.i32[0] & v55.i32[0];
                  v82 = v42;
                  v41 = cg_hudCompassMaxRange;
                } else {
                  v82 = *(float *)(cg_hudObjectiveMaxRange + 8);
                  v41 = cg_hudCompassMaxRange;
                  v42 = v40;
                }
                v82 = v42 - *(float *)(v41 + 8);
                v82 = v82 / (float)(*(float *)(cg_hudObjectiveMaxRange + 8) -
                                    *(float *)(v41 + 8));
                v82 = (float)(v82 *
                              (float)(*(float *)(cg_hudObjectiveMinAlpha + 8) -
                                      1.0)) +
                      1.0;
                if (v39.f32[0] <= *(float *)(v41 + 8)) {
                  v44 = cg_hudCompassMinRange;
                  v43 =
                      fmaxf(*(float *)(cg_hudCompassMinRange + 8), v39.f32[0]);
                } else {
                  v43 = *(float *)(v41 + 8);
                  v44 = cg_hudCompassMinRange;
                }
              }
              v45 =
                  *(float *)(cg_hudCompassSize + 8) * 43.75 *
                  (float)(*(float *)(cg_hudCompassMinRadius + 8) +
                          (float)((float)(1.0 -
                                          *(float *)(cg_hudCompassMinRadius +
                                                     8)) *
                                  (float)((float)(v43 - *(float *)(v44 + 8)) /
                                          (float)(*(float
                                                        *)(cg_hudCompassMaxRange +
                                                           8) -
                                                  *(float *)(v44 + 8)))));
              v79 = v45;
              v46 = v72 * 0.0174532925199433;
              v61 = *(float *)(cg_hudCompassSize + 8);
              v67 = sinf(v46);
              v66 = cosf(v46);
              v90 = v61 * 10.0;
              v92 = 10.0 * *(float *)(cg_hudCompassSize + 8);
              v89 = (float)((float)((float)(v61 * 10.0) * -0.5) + v70) -
                    (float)(v79 * v67);
              v91 = (float)((float)(v92 * -0.5) + v71) - (float)(v79 * v66);
              CG_ApplySplitScreenCompassScale();
              v47 = cg;
              v77 =
                  AngleNormalize360(*((float *)cg + 41331) -
                                    *(float *)((char *)cg + v62 * 4 + 181732));
              v48 = *((_DWORD *)v37 - 3);
              v49 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v47);
              v50 = v48 > v49 && (v48 - v49) % 500 > 249;
              v51 = *((_DWORD *)v37 - 2);
              if ((float)((float)v51 +
                          (float)(*(float *)(cg_hudCompassSoundPingFadeTime +
                                             8) *
                                  1000.0)) >= (float)v49) {
                if (v49 > v51)
                  v82 =
                      (float)((float)(v49 - v51) /
                              (float)(*(float
                                            *)(cg_hudCompassSoundPingFadeTime +
                                               8) *
                                      -1000.0)) +
                      1.0;
                else
                  v82 = 1.0;
                v52 = *((_DWORD *)cgs + 12408);
              } else {
                v52 = 0;
              }
              v83 = *a3;
              v84 = *((_DWORD *)a3 + 1);
              v85 = *((_DWORD *)a3 + 2);
              v86 = fminf(v73, a3[3]);
              v53 = _mm_cmplt_ss((__m128)LODWORD(v73), (__m128)LODWORD(v82));
              LODWORD(v82) = _mm_andnot_ps(v53, (__m128)LODWORD(v82)).u32[0] |
                             LODWORD(v73) & v53.i32[0];
              if (v50) {
                UI_DrawHandlePic(v89, v91, v90, v92, a1->horzAlign,
                                 a1->vertAlign, v81,
                                 *((Material **)cgs + 12060));
              } else if (v52 && v82 == 1.0 ||
                         (CG_DrawRotatedPic(v89, v91, v90, v92, a1->horzAlign,
                                            a1->vertAlign, v77),
                          v52)) {
                CG_DrawRotatedPic(v89, v91, v90, v92, a1->horzAlign,
                                  a1->vertAlign, v77);
              }
            }
            ++v80;
            v62 += 7;
            v63 += 7;
            v37 += 28;
          } while (v80 != 64);
        }
        v6 = (char *)cg + 181720;
        v7 = 64;
        do {
          while (1) {
            if (v6[24]) {
              v8 = *((_DWORD *)v6 + 5);
              v9 = (float *)cg;
              if ((float)*(int *)((char *)&loc_25BB0 + (_DWORD)cg) <=
                  (float)((float)v8 +
                          (float)(*(float *)(cg_hudCompassSoundPingFadeTime +
                                             8) *
                                  1000.0))) {
                if (v8)
                  break;
              }
            }
            v6 += 28;
            if (!--v7)
              return;
          }
          v87 = *((float *)v6 + 1) - *((float *)cg + 41314);
          v88 =
              *((float *)v6 + 2) - *(float *)((char *)&loc_2858C + (_DWORD)cg);
          v57 = vectoyaw(&v87);
          v76 = AngleNormalize360(v57 - v9[45422]);
          v10 =
              *(float *)(cg_hudCompassSize + 8) * 43.75 *
              (float)(*(float *)(cg_hudCompassMinRadius + 8) +
                      (float)((float)((float)(fminf(
                                                  *(float
                                                        *)(cg_hudCompassMaxRange +
                                                           8),
                                                  fsqrt((float)(v87 * v87) +
                                                        (float)(v88 * v88))) -
                                              *(float *)(cg_hudCompassMinRange +
                                                         8)) /
                                      (float)(*(float *)(cg_hudCompassMaxRange +
                                                         8) -
                                              *(float *)(cg_hudCompassMinRange +
                                                         8))) *
                              (float)(1.0 -
                                      *(float *)(cg_hudCompassMinRadius + 8))));
          v78 = v10;
          v11 = v76 * 0.0174532925199433;
          v60 = *(float *)(cg_hudCompassSize + 8);
          v65 = sinf(v11);
          v64 = cosf(v11);
          v90 = v60 * 10.0;
          v12 = (__m128) * (unsigned int *)(cg_hudCompassSize + 8);
          v92 = v12.f32[0] * 10.0;
          v89 = (float)((float)((float)(v60 * 10.0) * -0.5) + v70) -
                (float)(v78 * v65);
          v91 = (float)((float)((float)(v12.f32[0] * 10.0) * -0.5) + v71) -
                (float)(v78 * v64);
          CG_ApplySplitScreenCompassScale();
          v13 = *((_DWORD *)v6 + 5);
          v14 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v9);
          if (v13 < v14) {
            v12.f32[0] =
                (float)((float)(v14 - v13) /
                        (float)(*(float *)(cg_hudCompassSoundPingFadeTime + 8) *
                                -1000.0)) +
                1.0;
            v82 = v12.f32[0];
          } else {
            v82 = 1.0;
            v12 = (__m128)0x3F800000u;
          }
          v15 = _mm_cmplt_ss((__m128)LODWORD(v73), v12);
          LODWORD(v82) =
              _mm_andnot_ps(v15, v12).u32[0] | LODWORD(v73) & v15.i32[0];
          UI_DrawHandlePic(v89, v91, v90, v92, a1->horzAlign, a1->vertAlign,
                           v81, *((Material **)cgs + 12410));
          v6 += 28;
          --v7;
        } while (v7);
      }
    }
  }
}

void __cdecl CalcCompassFriendlySize(float *, float *) { UNIMPLEMENTED(); }
