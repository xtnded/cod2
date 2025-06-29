void __cdecl Byte4SetRgba(unsigned char *const, unsigned char, unsigned char,
                          unsigned char, unsigned char)
{
  UNIMPLEMENTED();
}

int __cdecl compare_hudelems(void const *pe0, void const *pe1)
{
  float v2; // xmm0_4

  v2 = *(float *)(*(_DWORD *)a1 + 120) - *(float *)(*(_DWORD *)a2 + 120);
  if (v2 < 0.0)
    return -1;
  else
    return v2 > 0.0;
}

float __cdecl CG_AlignHudElemY(int alignOrg, float y, float height)
{
  int v3; // eax

  v3 = a1 & 3;
  if (v3 == 1)
    return (float)((float)(a3 * -0.5) + a2);
  if (v3 == 2)
    return (float)(a2 - a3);
  return a2;
}

float __cdecl CG_AlignHudElemX(int alignOrg, float x, float width)
{
  int v3; // eax

  v3 = (a1 >> 2) & 3;
  if (v3 == 1)
    return (float)((float)(a3 * -0.5) + a2);
  if (v3 == 2)
    return (float)(a2 - a3);
  return a2;
}

bool __cdecl CG_AreHudElemsHidden()
{
  if (!*((_DWORD *)cg + 44914))
    return 1;
  return (CL_GetKeyCatchers() & 8) != 0 &&
         !(unsigned __int8)CL_GetDisplayHUDWithKeycatchUI();
}

void __cdecl CG_Draw3dHudElems()
{
  int v1;              // eax
  int v2;              // eax
  int v3;              // ecx
  int v4;              // edx
  signed __int32 v5;   // esi
  int v6;              // eax
  int v7;              // eax
  signed __int32 v8;   // ecx
  int v9;              // ebx
  int v10;             // edx
  int i;               // edi
  int v12;             // ebx
  int v13;             // eax
  float v14;           // xmm2_4
  int v15;             // ecx
  int v16;             // eax
  int v17;             // edx
  float v18;           // xmm3_4
  float v19;           // xmm1_4
  float v20;           // xmm1_4
  float v21;           // xmm1_4
  float v22;           // [esp+38h] [ebp-4A0h]
  float v23[5];        // [esp+40h] [ebp-498h] BYREF
  char v24;            // [esp+54h] [ebp-484h]
  float v25;           // [esp+154h] [ebp-384h]
  float v26;           // [esp+264h] [ebp-274h]
  _BYTE v27[256];      // [esp+278h] [ebp-260h] BYREF
  _DWORD __base[62];   // [esp+378h] [ebp-160h] BYREF
  char __dst[64];      // [esp+470h] [ebp-68h] BYREF
  float v30;           // [esp+4B0h] [ebp-28h]
  int v31;             // [esp+4B4h] [ebp-24h]
  int v32;             // [esp+4B8h] [ebp-20h]
  unsigned __int8 v33; // [esp+4BCh] [ebp-1Ch]
  char v34;            // [esp+4BDh] [ebp-1Bh]
  char v35;            // [esp+4BEh] [ebp-1Ah]
  char v36;            // [esp+4BFh] [ebp-19h]

    if (*((_DWORD *)cg + 44914)) {
        if ((CL_GetKeyCatchers() & 8) == 0) {
          v1 = 0;
          goto LABEL_3;
        }
        if ((unsigned __int8)CL_GetDisplayHUDWithKeycatchUI()) {
          v1 = 0;
          goto LABEL_3;
        }
    }
  v1 = 1;
LABEL_3:
    if (!v1) {
      v2 = *((_DWORD *)cg + 9);
      v3 = v2 + 12;
      v4 = v2 + 12;
      v5 = 0;
      v6 = v2 + 5940;
        do {
          if (!*(_DWORD *)(v4 + 5928))
            break;
          __base[v5++] = v6;
          v6 += 128;
          v4 += 128;
        }
      while (v5 != 31);
      v7 = v3;
      v8 = v5;
      v9 = 0;
      v10 = v7 + 1960;
        do {
          if (!*(_DWORD *)(v7 + 1960))
            break;
          __base[v8] = v10;
          ++v5;
          ++v9;
          v10 += 128;
          v7 += 128;
          ++v8;
        }
      while (v9 != 31);
      qsort(__base, v5, 4u, compare_hudelems);
        if (v5 > 0) {
            for (i = 0; i != v5; ++i) {
              v12 = __base[i];
                if (*(_DWORD *)v12 == 13) {
                  CG_GetHudElemInfo(__base[i], (int)v23, v27, a1);
                    if (v24) {
                      CG_DrawHudElemString(v12, (int)v23, a1);
                      v23[0] = v23[0] + v25;
                    }
                    if (*(_DWORD *)v12 == 13 && *(_BYTE *)(v12 + 35) &&
                        CG_ServerMaterialName(*(_DWORD *)(v12 + 60), __dst,
                                              0x40u)) {
                      CL_RegisterMaterial(__dst, 7);
                      v13 = *(_DWORD *)(v12 + 56);
                      if (v13)
                        v14 = (float)v13;
                      else
                        v14 = v26;
                      v15 = *(_DWORD *)(v12 + 76);
                        if (v15 > 0) {
                          v16 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) -
                                *(_DWORD *)(v12 + 72);
                            if (v15 > v16) {
                              v17 = *(_DWORD *)(v12 + 68);
                              if (v17)
                                v18 = (float)v17;
                              else
                                v18 = v26;
                              v19 = (float)v16 * (float)(1.0 / (float)v15);
                              if (v19 < 0.0)
                                v20 = 0.0;
                              else
                                v20 = fminf(1.0, v19);
                              v14 = (float)((float)(v14 - v18) * v20) + v18;
                            }
                        }
                        if (v14 != 0.0) {
                          v30 = *(float *)(v12 + 4);
                          v31 = *(_DWORD *)(v12 + 8);
                          v32 = *(_DWORD *)(v12 + 12);
                          v21 = (float)*(unsigned __int8 *)(v12 + 35) / 255.0;
                          v33 = -1;
                          v34 = -1;
                          v35 = -1;
                          a1 = floorf((float)(v21 * 255.0) + 0.5);
                          v22 = a1;
                          v36 = (int)v22;
                          CL_DrawSprite();
                        }
                    }
                }
            }
        }
    }
}

void __cdecl CG_Draw2dHudElems(int foreground)
{
  int v2;            // eax
  int v3;            // ecx
  int v4;            // edx
  signed __int32 v5; // esi
  int v6;            // eax
  int v7;            // eax
  signed __int32 v8; // ecx
  int v9;            // ebx
  int v10;           // edx
  _DWORD *v11;       // ebx
  int v12;           // eax
  Material *v13;     // edi
  int v14;           // eax
  float v15;         // xmm2_4
  int v16;           // ecx
  int v17;           // eax
  int v18;           // edx
  float v19;         // xmm4_4
  float v20;         // xmm1_4
  float v21;         // xmm1_4
  int v22;           // eax
  float v23;         // xmm2_4
  int v24;           // ecx
  int v25;           // eax
  int v26;           // edx
  float v27;         // xmm4_4
  float v28;         // xmm1_4
  float v29;         // xmm1_4
  float v30;         // xmm1_4
  int v31;           // edx
  int v32;           // eax
  float v33;         // xmm3_4
  float v34;         // xmm0_4
  int v35;           // eax
  int v36;           // eax
  int v37;           // edx
  float v38;         // xmm1_4
  int v39;           // eax
  int v40;           // eax
  float v41;         // xmm2_4
  int v42;           // ecx
  int v43;           // eax
  int v44;           // edx
  float v45;         // xmm4_4
  float v46;         // xmm1_4
  float v47;         // xmm1_4
  int v48;           // eax
  float v49;         // xmm2_4
  int v50;           // ecx
  int v51;           // eax
  int v52;           // edx
  float v53;         // xmm4_4
  float v54;         // xmm1_4
  float v55;         // xmm1_4
  float v56;         // xmm1_4
  int v57;           // edx
  int v58;           // eax
  float v59;         // xmm3_4
  float v60;         // xmm0_4
  int v61;           // eax
  int v62;           // eax
  float v63;         // xmm0_4
  int v64;           // eax
  float v65;         // xmm2_4
  int v66;           // eax
  float v67;         // xmm0_4
  int v68;           // eax
  float v69;         // xmm2_4
  int v70;           // eax
  int v71;           // [esp+44h] [ebp-4A4h]
  Material *v72;     // [esp+48h] [ebp-4A0h]
  float v73;         // [esp+4Ch] [ebp-49Ch]
  float v74;         // [esp+50h] [ebp-498h] BYREF
  float v75;         // [esp+54h] [ebp-494h]
  float v76;         // [esp+60h] [ebp-488h]
  char v77;          // [esp+64h] [ebp-484h]
  float v78;         // [esp+164h] [ebp-384h]
  char v79;          // [esp+168h] [ebp-380h]
  float v80;         // [esp+274h] [ebp-274h]
  float v81[4];      // [esp+278h] [ebp-270h] BYREF
  _BYTE v82[256];    // [esp+288h] [ebp-260h] BYREF
  _DWORD __base[62]; // [esp+388h] [ebp-160h] BYREF
  char __dst[64];    // [esp+480h] [ebp-68h] BYREF
  float v85;         // [esp+4C0h] [ebp-28h] BYREF
  float v86;         // [esp+4C4h] [ebp-24h] BYREF
  float v87;         // [esp+4C8h] [ebp-20h] BYREF
  float v88[7];      // [esp+4CCh] [ebp-1Ch] BYREF

  v2 = *((_DWORD *)cg + 9);
  v3 = v2 + 12;
  v4 = v2 + 12;
  v5 = 0;
  v6 = v2 + 5940;
    do {
      if (!*(_DWORD *)(v4 + 5928))
        break;
      __base[v5++] = v6;
      v6 += 128;
      v4 += 128;
    }
  while (v5 != 31);
  v7 = v3;
  v8 = v5;
  v9 = 0;
  v10 = v7 + 1960;
    do {
      if (!*(_DWORD *)(v7 + 1960))
        break;
      __base[v8] = v10;
      ++v5;
      ++v9;
      v10 += 128;
      v7 += 128;
      ++v8;
    }
  while (v9 != 31);
  qsort(__base, v5, 4u, compare_hudelems);
    if (v5 > 0) {
      v71 = 0;
        while (1) {
          v11 = (_DWORD *)__base[v71];
          if (v11[31] != a2)
            goto LABEL_9;
          if (*v11 == 13)
            goto LABEL_9;
          CG_GetHudElemInfo(__base[v71], (int)&v74, v82, a1);
          if (v81[3] == 0.0)
            goto LABEL_9;
            if (v77) {
              CG_DrawHudElemString((int)v11, (int)&v74, a1);
              v74 = v74 + v78;
            }
          if (*v11 > 0xCu)
            goto LABEL_9;
          v12 = 1 << *v11;
            if ((v12 & 0x7BE) != 0) {
              if (v79)
                CG_DrawHudElemString((int)v11, (int)&v74, a1);
              goto LABEL_9;
            }
            if ((v12 & 0x40) == 0) {
              if ((v12 & 0x1800) == 0 ||
                  !CG_ServerMaterialName(v11[15], __dst, 0x3Au))
                goto LABEL_9;
              v72 = (Material *)CL_RegisterMaterialNoMip(__dst, 7);
              I_strncat(__dst, 64, "needle");
              CL_RegisterMaterialNoMip(__dst, 7);
                switch (*v11) {
                case 7:
                  v37 = v11[26] - *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) +
                        999;
                  goto LABEL_52;
                case 8:
                case 0xA:
                case 0xC:
                  v37 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[26];
                  goto LABEL_52;
                case 9:
                  v37 = v11[26] - *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) +
                        99;
                  goto LABEL_52;
                case 0xB:
                  v37 = v11[26] - *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg);
                LABEL_52:
                  if (v37 < 0)
                    goto LABEL_88;
                  v38 = (float)v37;
                  break;
                default:
                LABEL_88:
                  v38 = 0.0;
                  break;
                }
              v39 = v11[27];
              if (v39)
                a1 = AngleNormalize360((float)(v38 * 360.0) / (float)v39);
              else
                a1 = AngleNormalize360(v38 * 0.0060000001);
              v40 = v11[13];
              if (v40)
                v41 = (float)v40;
              else
                v41 = v80;
              v42 = v11[19];
                if (v42 > 0) {
                  v43 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[18];
                    if (v42 > v43) {
                      v44 = v11[16];
                      if (v44)
                        v45 = (float)v44;
                      else
                        v45 = v80;
                      v46 = (float)v43 * (float)(1.0 / (float)v42);
                      if (v46 < 0.0)
                        v47 = 0.0;
                      else
                        v47 = fminf(1.0, v46);
                      v41 = (float)((float)(v41 - v45) * v47) + v45;
                    }
                }
              v86 = v41;
              v48 = v11[14];
              if (v48)
                v49 = (float)v48;
              else
                v49 = v80;
              v50 = v11[19];
                if (v50 > 0) {
                  v51 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[18];
                    if (v50 > v51) {
                      v52 = v11[17];
                      if (v52)
                        v53 = (float)v52;
                      else
                        v53 = v80;
                      v54 = (float)v51 * (float)(1.0 / (float)v50);
                      if (v54 < 0.0)
                        v55 = 0.0;
                      else
                        v55 = fminf(1.0, v54);
                      v49 = (float)((float)(v49 - v53) * v55) + v53;
                    }
                }
              v85 = v49;
              v56 = -(float)(v76 - v49);
              v57 = v11[25];
                if (v57 <= 0) {
                LABEL_78:
                  v60 = v75;
                  v61 = v11[6] & 3;
                    if (v61 == 1) {
                      v60 = v75 + (float)(v56 * -0.5);
                    }
                    else if (v61 == 2) {
                      v60 = v75 - v56;
                    }
                }
                else {
                  v58 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[24];
                    if (v58 <= 0) {
                      v59 = 0.0;
                    }
                    else {
                      if (v57 <= v58)
                        goto LABEL_78;
                      v59 = (float)v58 / (float)v57;
                      if (v59 == 1.0)
                        goto LABEL_78;
                    }
                  v67 = v75;
                  v68 = v11[22] & 3;
                    if (v68 == 1) {
                      v69 = (float)(v56 * -0.5) + v75;
                    }
                    else if (v68 == 2) {
                      v69 = v75 - v56;
                    }
                    else {
                      v69 = v75;
                    }
                  v70 = v11[6] & 3;
                    if (v70 == 1) {
                      v67 = v75 + (float)(v56 * -0.5);
                    }
                    else if (v70 == 2) {
                      v67 = v75 - v56;
                    }
                  v60 = (float)((float)(v69 - v67) * v59) + v69;
                }
              v62 = v11[7];
              v88[0] = 0.0;
              v87 = 0.0;
              CalcScreenPlacement(v88, &v87, &v86, &v85, (v62 >> 3) & 7,
                                  v62 & 7);
              CL_DrawStretchPicPhysical(v74, v60, v86, v85, 0.0, 0.0, 1.0, 1.0,
                                        v81, v72);
              v73 = a1;
              CG_DrawRotatedPicPhysical(v74, v60, v86, v85, v73);
              goto LABEL_9;
            }
          if (CG_ServerMaterialName(v11[15], __dst, 0x40u))
            break;
        LABEL_9:
          if (++v71 == v5)
            return;
        }
      v13 = (Material *)CL_RegisterMaterial(__dst, 7);
      v14 = v11[13];
      if (v14)
        v15 = (float)v14;
      else
        v15 = v80;
      v16 = v11[19];
        if (v16 > 0) {
          v17 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[18];
            if (v16 > v17) {
              v18 = v11[16];
              if (v18)
                v19 = (float)v18;
              else
                v19 = v80;
              v20 = (float)v17 * (float)(1.0 / (float)v16);
              if (v20 < 0.0)
                v21 = 0.0;
              else
                v21 = fminf(1.0, v20);
              v15 = (float)((float)(v15 - v19) * v21) + v19;
            }
        }
      v87 = v15;
      v22 = v11[14];
      if (v22)
        v23 = (float)v22;
      else
        v23 = v80;
      v24 = v11[19];
        if (v24 > 0) {
          v25 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[18];
            if (v24 > v25) {
              v26 = v11[17];
              if (v26)
                v27 = (float)v26;
              else
                v27 = v80;
              v28 = (float)v25 * (float)(1.0 / (float)v24);
              if (v28 < 0.0)
                v29 = 0.0;
              else
                v29 = fminf(1.0, v28);
              v23 = (float)((float)(v23 - v27) * v29) + v27;
            }
        }
      v85 = v23;
      v30 = -(float)(v76 - v23);
      v31 = v11[25];
      if (v31 <= 0)
        goto LABEL_41;
      v32 = *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) - v11[24];
        if (v32 <= 0) {
          v33 = 0.0;
        }
        else if (v31 <= v32 || (v33 = (float)v32 / (float)v31, v33 == 1.0)) {
        LABEL_41:
          v34 = v75;
          v35 = v11[6] & 3;
            if (v35 == 1) {
              v34 = v75 + (float)(v30 * -0.5);
            }
            else if (v35 == 2) {
              v34 = v75 - v30;
            }
        LABEL_44:
          v36 = v11[7];
          v86 = 0.0;
          v88[0] = 0.0;
          CalcScreenPlacement(&v86, v88, &v87, &v85, (v36 >> 3) & 7, v36 & 7);
          CL_DrawStretchPicPhysical(v74, v34, v87, v85, 0.0, 0.0, 1.0, 1.0, v81,
                                    v13);
          goto LABEL_9;
        }
      v63 = v75;
      v64 = v11[22] & 3;
        if (v64 == 1) {
          v65 = (float)(v30 * -0.5) + v75;
        }
        else if (v64 == 2) {
          v65 = v75 - v30;
        }
        else {
          v65 = v75;
        }
      v66 = v11[6] & 3;
        if (v66 == 1) {
          v63 = v75 + (float)(v30 * -0.5);
        }
        else if (v66 == 2) {
          v63 = v75 - v30;
        }
      v34 = (float)((float)(v65 - v63) * v33) + v65;
      goto LABEL_44;
    }
}

float __cdecl CG_HudElemMovementFrac(struct hudelem_s const *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_HudElemMaterialDimension(int, struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CG_GetHudElemTime(struct hudelem_s const *)
{
  UNIMPLEMENTED();
}

int __cdecl CG_GetSortedHudElems(struct hudelem_s **const)
{
  UNIMPLEMENTED();
}

float __cdecl CG_OffsetHudElemY(struct hudelem_s const *,
                                struct cg_hudelem_t const *, float)
{
  UNIMPLEMENTED();
}

float __cdecl CG_HudElemMaterialHeight(struct hudelem_s const *,
                                       struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_HudElemMaterialWidth(struct hudelem_s const *,
                                      struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

char const *__cdecl CG_HudElemTenthsTimerString(struct hudelem_s const *)
{
  UNIMPLEMENTED();
}

char const *__cdecl CG_HudElemTimerString(struct hudelem_s const *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_HudElemStringWidth(char const *, struct cg_hudelem_t const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_ConsolidateHudElemText(struct cg_hudelem_t *, char *const)
{
  UNIMPLEMENTED();
}

float __cdecl CG_HudElemHeight(struct hudelem_s const *, struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_HudElemWidth(struct hudelem_s const *, struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawWaypointIcon3d(struct Material *, float const *const, float,
                                   float, bool)
{
  UNIMPLEMENTED();
}

void __cdecl CG_HudElemPhysicalSize(int, float *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_GetHudElemOrg(int, int, float, float, float, float, float *,
                              float *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawHudElemWaypoint(struct hudelem_s const *,
                                    struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawHudElemMaterial(struct hudelem_s const *,
                                    struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawHudElemClock(struct hudelem_s const *,
                                 struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawHudElemString(char const *, struct hudelem_s const *,
                                  struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_SetHudElemPos(struct hudelem_s const *, struct cg_hudelem_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_GetHudElemInfo(struct hudelem_s const *, struct cg_hudelem_t *,
                               char *const)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawSingleHudElem3d(struct hudelem_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawSingleHudElem2d(struct hudelem_s const *)
{
  UNIMPLEMENTED();
}
