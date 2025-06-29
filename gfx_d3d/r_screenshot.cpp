public:
long __cdecl D3DDevice::Clear(unsigned long, struct _D3DRECT const *,
                              unsigned long, unsigned long, float,
                              unsigned long) {
  UNIMPLEMENTED();
}

void __cdecl Vec3Mul(float const *const, float const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl R_ScreenshotCommand(enum GfxScreenshotType type) {
  int v1;              // eax
  int v2;              // edx
  unsigned int v3;     // edi
  int v4;              // esi
  unsigned __int8 *v5; // ebx
  const char *v6;      // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  GLsizei v9;          // ebx
  __int16 v10;         // si
  int v11;             // edi
  const char *v12;     // eax
  _BOOL4 v13;          // [esp+54h] [ebp-224h]
  const char *v14;     // [esp+58h] [ebp-220h]
  int v15;             // [esp+5Ch] [ebp-21Ch]
  char v16[256];       // [esp+60h] [ebp-218h] BYREF
  char __str[280];     // [esp+160h] [ebp-118h] BYREF

  if (a1) {
    if (a1 != R_SCREENSHOT_TGA)
      return;
    v14 = "tga";
  } else {
    v14 = "jpg";
  }
  if (!strcmp((const char *)unk_11807C4(1), "levelshot")) {
    R_LevelShot();
    return;
  }
  if (!strcmp((const char *)unk_11807C4(1), "savegame") && unk_11807C0() == 3 &&
      *(_BYTE *)unk_11807C4(2)) {
    v6 = (const char *)unk_11807C4(2);
    sprintf(v16, "%s.jpg", v6);
    v7 = (unsigned __int8 *)R_TakeResampledScreenshot(512, 512, 3, 0);
    v8 = v7;
    if (v7) {
      R_SaveJpg(v16, 90, 512, 0x200u, v7);
      (*(void(__cdecl **)(unsigned __int8 *)) & algn_11806C8[16])(v8);
    }
  } else {
    v13 = strcmp((const char *)unk_11807C4(1), "silent") == 0;
    if (unk_11807C0() != 2 || v13) {
      v1 = R_ScreenshotCommand(GfxScreenshotType)::lastNumber;
      v2 = R_ScreenshotCommand(GfxScreenshotType)::lastNumber;
      if (R_ScreenshotCommand(GfxScreenshotType)::lastNumber <= 9999) {
        while (1) {
          if ((unsigned int)v2 > 0x270F)
            Com_sprintf(__str, 0x100u, "screenshots/shot9999.%s", v14);
          else
            Com_sprintf(__str, 0x100u, "screenshots/shot%04i.%s", v2, v14);
          if (!unk_11807FC(__str))
            break;
          v2 = R_ScreenshotCommand(GfxScreenshotType)::lastNumber + 1;
          v1 = v2;
          ++R_ScreenshotCommand(GfxScreenshotType)::lastNumber;
          if (v2 > 9999)
            goto LABEL_17;
        }
        v1 = R_ScreenshotCommand(GfxScreenshotType)::lastNumber;
      }
    LABEL_17:
      if (v1 > 9998) {
        ri(0, "ScreenShot: Couldn't create a file\n");
        return;
      }
      R_ScreenshotCommand(GfxScreenshotType)::lastNumber = v1 + 1;
    } else {
      v12 = (const char *)unk_11807C4(1);
      Com_sprintf(__str, 0x100u, "screenshots/%s.%s", v12, v14);
    }
    if (a1) {
      v9 = HIDWORD(vidConfig);
      v10 = vidConfig;
      v15 = 3 * vidConfig * v9 + 18;
      v11 = (*(int(__cdecl **)(int)) & algn_11806C8[12])(v15);
      *(_DWORD *)v11 = 0;
      *(_DWORD *)(v11 + 4) = 0;
      *(_DWORD *)(v11 + 8) = 0;
      *(_DWORD *)(v11 + 12) = 0;
      *(_WORD *)(v11 + 16) = 0;
      *(_BYTE *)(v11 + 2) = 2;
      *(_WORD *)(v11 + 12) = v10;
      *(_WORD *)(v11 + 14) = v9;
      *(_BYTE *)(v11 + 16) = 24;
      *(_BYTE *)(v11 + 17) = 32;
      if ((unsigned __int8)R_GetFrontBufferData(v9, 3, v11 + 18))
        unk_1180800(__str, v11, v15);
      (*(void(__cdecl **)(int)) & algn_11806C8[16])(v11);
    } else {
      v3 = HIDWORD(vidConfig);
      v4 = vidConfig;
      v5 = (unsigned __int8 *)(*(int(__cdecl **)(_DWORD)) &
                               algn_11806C8[12])(3 * vidConfig * v3);
      if ((unsigned __int8)R_GetFrontBufferData(v3, 3, (int)v5))
        R_SaveJpg(__str, 90, v4, v3, v5);
      (*(void(__cdecl **)(unsigned __int8 *)) & algn_11806C8[16])(v5);
    }
    if (!v13)
      ri(0, "Wrote %s\n", __str);
  }
}

void __cdecl R_SaveGameShot(char const *) { UNIMPLEMENTED(); }

void __cdecl R_LevelShot() {
  int v0;       // eax
  int v1;       // esi
  char v2[280]; // [esp+10h] [ebp-118h] BYREF

  if (dword_1184B9C)
    sprintf(v2, "levelshots/%s.tga", *(const char **)(dword_1184B9C + 4));
  else
    sprintf(v2, "levelshots/%s.tga", "screenshot");
  v0 = R_TakeResampledScreenshot(128, 128, 3, 18);
  v1 = v0;
  if (v0) {
    *(_DWORD *)v0 = 0;
    *(_DWORD *)(v0 + 4) = 0;
    *(_DWORD *)(v0 + 8) = 0;
    *(_DWORD *)(v0 + 12) = 0;
    *(_WORD *)(v0 + 16) = 0;
    *(_BYTE *)(v0 + 2) = 2;
    *(_BYTE *)(v0 + 12) = 0x80;
    *(_BYTE *)(v0 + 14) = 0x80;
    *(_BYTE *)(v0 + 16) = 24;
    unk_1180800(v2, v0, 49170);
    (*(void(__cdecl **)(int)) & algn_11806C8[16])(v1);
    ri(0, "Wrote %s\n", v2);
  }
}

void __cdecl R_LightingFromCubemapShots(float const *const baseColor) {
  int v1;          // ebx
  int v2;          // edi
  _DWORD *v3;      // ebx
  int v4;          // esi
  float v5;        // xmm0_4
  int v6;          // esi
  float v7;        // xmm0_4
  int v8;          // ebx
  float v9;        // xmm0_4
  int v10;         // eax
  float v11;       // xmm0_4
  float *v12;      // ecx
  float *v13;      // edx
  float v14;       // xmm3_4
  int v15;         // ebx
  int v16;         // eax
  float v17;       // xmm2_4
  int v18;         // edi
  int k;           // esi
  float v20;       // xmm0_4
  float v21;       // xmm1_4
  float v22;       // xmm1_4
  float *v23;      // eax
  float v24;       // xmm2_4
  float v25;       // xmm2_4
  float v26;       // xmm2_4
  float v27;       // xmm1_4
  float v28;       // xmm0_4
  float v29;       // xmm0_4
  float v30;       // xmm0_4
  long double v32; // [esp+0h] [ebp-118h]
  long double v33; // [esp+0h] [ebp-118h]
  long double v34; // [esp+0h] [ebp-118h]
  long double v35; // [esp+0h] [ebp-118h]
  long double v36; // [esp+0h] [ebp-118h]
  long double v37; // [esp+0h] [ebp-118h]
  int v38;         // [esp+10h] [ebp-108h]
  int v39;         // [esp+10h] [ebp-108h]
  int v40;         // [esp+10h] [ebp-108h]
  int v41;         // [esp+10h] [ebp-108h]
  int v42;         // [esp+10h] [ebp-108h]
  int v43;         // [esp+10h] [ebp-108h]
  float v44;       // [esp+30h] [ebp-E8h]
  float v45;       // [esp+34h] [ebp-E4h]
  float v46;       // [esp+38h] [ebp-E0h]
  float v47;       // [esp+3Ch] [ebp-DCh]
  int v48;         // [esp+70h] [ebp-A8h]
  int i;           // [esp+74h] [ebp-A4h]
  int v50;         // [esp+78h] [ebp-A0h]
  int v51;         // [esp+7Ch] [ebp-9Ch]
  int j;           // [esp+80h] [ebp-98h]
  int v53;         // [esp+84h] [ebp-94h]
  int v54;         // [esp+88h] [ebp-90h]
  _BYTE *v55;      // [esp+8Ch] [ebp-8Ch]
  int v56;         // [esp+90h] [ebp-88h]
  int v57;         // [esp+94h] [ebp-84h]
  int v58;         // [esp+98h] [ebp-80h]
  float v59;       // [esp+9Ch] [ebp-7Ch]
  int *v60;        // [esp+A0h] [ebp-78h]
  float v61;       // [esp+A4h] [ebp-74h]
  int v62;         // [esp+A8h] [ebp-70h]
  int v63;         // [esp+ACh] [ebp-6Ch]
  int v64;         // [esp+B0h] [ebp-68h]
  int v65;         // [esp+B4h] [ebp-64h]
  int *v66;        // [esp+B8h] [ebp-60h]
  float v67;       // [esp+BCh] [ebp-5Ch]
  float v68;       // [esp+C0h] [ebp-58h]
  float v69;       // [esp+C0h] [ebp-58h]
  float v70;       // [esp+C4h] [ebp-54h]
  float v71;       // [esp+C8h] [ebp-50h]
  float v72;       // [esp+CCh] [ebp-4Ch]
  _DWORD v73[2];   // [esp+D0h] [ebp-48h] BYREF
  int v74;         // [esp+D8h] [ebp-40h]
  int v75;         // [esp+DCh] [ebp-3Ch]
  int v76;         // [esp+E0h] [ebp-38h]
  int v77;         // [esp+E4h] [ebp-34h]
  float v78;       // [esp+E8h] [ebp-30h] BYREF
  float v79;       // [esp+ECh] [ebp-2Ch]
  float v80;       // [esp+F0h] [ebp-28h]
  float v81;       // [esp+F4h] [ebp-24h] BYREF
  float v82;       // [esp+F8h] [ebp-20h]
  float v83;       // [esp+FCh] [ebp-1Ch]

  v1 = LOWORD(dword_11805D4[1]) * LOWORD(dword_11805D4[1]);
  v73[0] = (*(int(__cdecl **)(int)) & algn_11806C8[12])(72 * v1);
  v1 *= 12;
  v73[1] = v1 + v73[0];
  v74 = v1 + v1 + v73[0];
  v75 = v1 + v74;
  v76 = v1 + v1 + v74;
  v77 = v76 + v1;
  v48 = LOWORD(dword_11805D4[1]);
  v65 = 1;
  v66 = cubeShotGlob;
  do {
    if (v48 > 0) {
      v51 = 0;
      v50 = 0;
      do {
        v64 = 12 * v51;
        v2 = 4 * v51;
        for (i = 0; i != v48; ++i) {
          v3 = &v73[v65];
          v4 = *(v3 - 1);
          *((_QWORD *)&v32 + 1) = 0x40019999A0000000LL;
          *(double *)&v32 = (float)((float)*(unsigned __int8 *)(v2 + *v66 + 2) *
                                    0.0039215689);
          v5 = pow(v32, v38);
          *(float *)(v64 + v4) = v5;
          v6 = *(v3 - 1);
          *((_QWORD *)&v33 + 1) = 0x40019999A0000000LL;
          *(double *)&v33 = (float)((float)*(unsigned __int8 *)(v2 + *v66 + 1) *
                                    0.0039215689);
          v7 = pow(v33, v39);
          *(float *)(v64 + v6 + 4) = v7;
          v8 = *(v3 - 1);
          *((_QWORD *)&v34 + 1) = 0x40019999A0000000LL;
          *(double *)&v34 =
              (float)((float)*(unsigned __int8 *)(v2 + *v66) * 0.0039215689);
          v9 = pow(v34, v40);
          *(float *)(v64 + v8 + 8) = v9;
          v64 += 12;
          v2 += 4;
        }
        v51 += i;
        ++v50;
      } while (i != v50);
    }
    ++v65;
    ++v66;
  } while (v65 != 7);
  v56 = LOWORD(dword_11805D4[1]);
  v10 = 0;
  v44 = (float)LOWORD(dword_11805D4[1]);
  do {
    if (v56 <= 0) {
      ++v10;
    } else {
      v54 = v10 + 1;
      v60 = &cubeShotGlob[v10];
      v53 = 0;
      do {
        v61 = (float)((float)((float)((float)v53 + 0.5) +
                              (float)((float)v53 + 0.5)) /
                      v44) -
              1.0;
        v63 = 4 * v56 * v53;
        for (j = 0; j != v56; ++j) {
          v11 = (float)((float)((float)((float)j + 0.5) +
                                (float)((float)j + 0.5)) /
                        v44) -
                1.0;
          v12 = (float *)&cubemapShotAxis[9 * v54 + 3];
          v81 = (float)(v11 * *v12) + *(float *)&cubemapShotAxis[9 * v54];
          v82 = (float)(v11 * v12[1]) + *(float *)&cubemapShotAxis[9 * v54 + 1];
          v83 = (float)(v11 * v12[2]) + *(float *)&cubemapShotAxis[9 * v54 + 2];
          v13 = (float *)&cubemapShotAxis[9 * v54 + 6];
          v81 = (float)(v61 * *v13) + v81;
          v82 = (float)(v61 * v13[1]) + v82;
          v83 = (float)(v61 * v13[2]) + v83;
          Vec3Normalize(&v81);
          v55 = (_BYTE *)(*v60 + v63);
          v58 = 0;
          v72 = 0.0;
          v70 = 0.0;
          v14 = 0.0;
          v62 = 1;
          v15 = 9;
          do {
            v57 = 0;
            v16 = 0;
            do {
              v17 = (float)((float)((float)((float)v57 + 0.5) +
                                    (float)((float)v57 + 0.5)) /
                            v44) -
                    1.0;
              v18 = 12 * v56 * v16;
              for (k = 0; k != v56; ++k) {
                v20 = (float)((float)((float)((float)k + 0.5) +
                                      (float)((float)k + 0.5)) /
                              v44) -
                      1.0;
                v78 = (float)(v20 * *(float *)&dword_2F272C[v15]) +
                      *(float *)&cubemapShotAxis[v15];
                v21 = (float)(v20 * *(float *)&dword_2F2730[v15]) +
                      *(float *)&dword_2F2724[v15];
                v80 = (float)(v20 * *(float *)&dword_2F2734[v15]) +
                      *(float *)&dword_2F2728[v15];
                v78 = (float)(v17 * *(float *)&dword_2F2738[v15]) + v78;
                v79 = (float)(v17 * *(float *)&dword_2F273C[v15]) + v21;
                v80 = (float)(v17 * *(float *)&dword_2F2740[v15]) + v80;
                v41 = LODWORD(v14);
                Vec3Normalize(&v78);
                v22 = (float)((float)(v81 * v78) + (float)(v82 * v79)) +
                      (float)(v83 * v80);
                if (v22 > 0.0) {
                  v23 = (float *)(v73[v62 - 1] + v18);
                  v14 = v14 + (float)(v22 * *v23);
                  v70 = (float)(v22 * v23[1]) + v70;
                  v72 = (float)(v22 * v23[2]) + v72;
                  ++v58;
                }
                v18 += 12;
              }
              v16 = ++v57;
            } while (v56 != v57);
            ++v62;
            v15 += 9;
          } while (v62 != 7);
          v59 = 1.0 / (float)v58;
          *((_QWORD *)&v35 + 1) = 0x3FDD1745C0000000LL;
          *(double *)&v35 = (float)(v14 * v59);
          v24 = pow(v35, v41);
          v67 = v24;
          *((_QWORD *)&v36 + 1) = 0x3FDD1745C0000000LL;
          *(double *)&v36 = (float)(v59 * v70);
          v25 = pow(v36, v42);
          v68 = v25;
          *((_QWORD *)&v37 + 1) = 0x3FDD1745C0000000LL;
          *(double *)&v37 = (float)(v59 * v72);
          v26 = pow(v37, v43);
          v27 = v67 * *a1;
          v69 = v68 * a1[1];
          v71 = v26 * a1[2];
          if ((float)(v27 - 1.0) < 0.0)
            v28 = v27 * 255.0;
          else
            v28 = 255.0;
          v47 = floorf(v28 + 0.5);
          v55[2] = (int)v47;
          if ((float)(v69 - 1.0) < 0.0)
            v29 = v69 * 255.0;
          else
            v29 = 255.0;
          v46 = floorf(v29 + 0.5);
          v55[1] = (int)v46;
          if ((float)(v71 - 1.0) < 0.0)
            v30 = v71 * 255.0;
          else
            v30 = 255.0;
          v45 = floorf(v30 + 0.5);
          *v55 = (int)v45;
          v55[3] = -1;
          v63 += 4;
        }
        ++v53;
      } while (j != v53);
      v10 = v54;
    }
  } while (v10 <= 5);
  return (*(int(__cdecl **)(_DWORD)) & algn_11806C8[16])(v73[0]);
}

void __cdecl R_SaveCubemapShot(char const *filename, enum CubemapShot shotIndex,
                               float n0, float n1) {
  __int16 v3; // dx
  int v4;     // eax
  int v5;     // ebx
  int v6;     // edi
  float *v7;  // ecx
  float v8;   // xmm2_4
  float *v9;  // edx
  float v10;  // xmm1_4
  int v12;    // edi
  int v13;    // ebx
  int v14;    // eax
  _BYTE *v15; // ecx
  _BYTE *v16; // eax
  float v17;  // [esp+1Ch] [ebp-4Ch]
  float v18;  // [esp+24h] [ebp-44h]
  int v19;    // [esp+2Ch] [ebp-3Ch]
  int v20;    // [esp+30h] [ebp-38h]
  int v21;    // [esp+34h] [ebp-34h]
  int v22;    // [esp+38h] [ebp-30h]
  float v23;  // [esp+44h] [ebp-24h] BYREF
  float v24;  // [esp+48h] [ebp-20h]
  float v25;  // [esp+4Ch] [ebp-1Ch]

  v19 = 4 * LOWORD(dword_11805D4[1]) * LOWORD(dword_11805D4[1]) + 18;
  v21 = (*(int(__cdecl **)(int)) & algn_11806C8[12])(v19);
  v3 = dword_11805D4[1];
  *(_DWORD *)v21 = 0;
  *(_DWORD *)(v21 + 4) = 0;
  *(_DWORD *)(v21 + 8) = 0;
  *(_DWORD *)(v21 + 12) = 0;
  *(_WORD *)(v21 + 16) = 0;
  *(_BYTE *)(v21 + 2) = 2;
  *(_WORD *)(v21 + 12) = v3;
  *(_WORD *)(v21 + 14) = v3;
  *(_BYTE *)(v21 + 16) = 32;
  v20 = cubeShotGlob[a2 - 1];
  v4 = LOWORD(dword_11805D4[1]);
  if (LOWORD(dword_11805D4[1])) {
    v12 = 0;
  LABEL_11:
    v13 = 0;
    do {
      v14 = 4 * (v13 + v12 * v4);
      v15 = (_BYTE *)(v14 + v21 + 18);
      v16 = (_BYTE *)(v20 + v14);
      v15[2] = v16[2];
      v15[1] = v16[1];
      *v15 = *v16;
      v15[3] = v16[3];
      ++v13;
      v4 = LOWORD(dword_11805D4[1]);
    } while (LOWORD(dword_11805D4[1]) > v13);
    while (++v12 < LOWORD(dword_11805D4[1])) {
      v4 = LOWORD(dword_11805D4[1]);
      if (LOWORD(dword_11805D4[1]))
        goto LABEL_11;
    }
  }
  if (LOWORD(dword_11805D4[1])) {
    v5 = LOWORD(dword_11805D4[1]);
    v22 = 0;
    while (1) {
      v6 = 0;
      do {
        v23 = (float)((float)v5 * 0.5) * *(float *)&cubemapShotAxis[9 * a2];
        v24 = (float)((float)v5 * 0.5) * *(float *)&cubemapShotAxis[9 * a2 + 1];
        v25 = (float)((float)v5 * 0.5) * *(float *)&cubemapShotAxis[9 * a2 + 2];
        v7 = (float *)&cubemapShotAxis[9 * a2 + 3];
        v8 = (float)v5 * -0.5;
        v23 = (float)((float)((float)((float)v6 + v8) + 0.5) * *v7) + v23;
        v24 = (float)((float)((float)((float)v6 + v8) + 0.5) * v7[1]) + v24;
        v25 = (float)((float)((float)((float)v6 + v8) + 0.5) * v7[2]) + v25;
        v9 = (float *)&cubemapShotAxis[9 * a2 + 6];
        v10 = (float)((float)v22 + v8) + 0.5;
        v23 = (float)(v10 * *v9) + v23;
        v24 = (float)(v10 * v9[1]) + v24;
        v25 = (float)(v10 * v9[2]) + v25;
        Vec3Normalize(&v23);
        v17 = FresnelTerm(*(float *)&a3, *((float *)&a3 + 1), v25);
        v18 = floorf((float)(v17 * 255.0) + 0.5);
        *(_BYTE *)(v21 + 4 * (v6 + v22 * v5) + 21) = (int)v18;
        ++v6;
        v5 = LOWORD(dword_11805D4[1]);
      } while (v6 < LOWORD(dword_11805D4[1]));
      if (++v22 >= LOWORD(dword_11805D4[1]))
        break;
      while (1) {
        v5 = LOWORD(dword_11805D4[1]);
        if (LOWORD(dword_11805D4[1]))
          break;
        if (++v22 >= 0)
          goto LABEL_9;
      }
    }
  }
LABEL_9:
  unk_1180800(a1, v21, v19);
  (*(void(__cdecl **)(int)) & algn_11806C8[16])(v21);
  return (*(int(__cdecl **)(int)) & algn_11806C8[16])(cubeShotGlob[a2 - 1]);
}

void __cdecl R_EndCubemapShot(enum CubemapShot shotIndex) {
  unsigned __int8 *v1; // edi
  int v2;              // esi
  int v3;              // edx
  int v4;              // ebx
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // eax
  int v8;              // [esp+1Ch] [ebp-2Ch]
  int v9;              // [esp+2Ch] [ebp-1Ch]

  v8 = 4 * LOWORD(dword_11805D4[1]) * LOWORD(dword_11805D4[1]);
  v1 = (unsigned __int8 *)(*(int(__cdecl **)(int)) & algn_11806C8[12])(v8);
  dword_C96BFC[a1] = (int)v1;
  R_GetFrontBufferData(LOWORD(dword_11805D4[1]), 4, (int)v1);
  if ((dword_11805D4[1] & 0xFFFE) != 0) {
    v2 = 0;
    do {
      v3 = LOWORD(dword_11805D4[1]);
      if (LOWORD(dword_11805D4[1])) {
        v4 = 0;
        do {
          v5 = &v1[4 * v4 + 4 * v3 * v2];
          v9 = *(_DWORD *)v5;
          v6 = &v1[4 * v4 + 4 * (v3 - v2 - 1) * v3];
          *(_DWORD *)v5 = *(_DWORD *)v6;
          *(_DWORD *)v6 = v9;
          ++v4;
          v3 = LOWORD(dword_11805D4[1]);
        } while (v4 < LOWORD(dword_11805D4[1]));
      }
      ++v2;
    } while (v2 < LOWORD(dword_11805D4[1]) >> 1);
  }
  if (*(int *)(r_overbrightBits + 8) <= 0 || !(_BYTE)dword_11806A8)
    return RB_SetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
  R_GammaCorrect(v1, v8);
  return RB_SetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
}

void __cdecl R_BeginCubemapShot(int pixelWidthHeight, int pixelBorder) {
  int result; // eax

  LOWORD(dword_11805D4[1]) = a1;
  HIWORD(dword_11805D4[1]) = a2;
  RB_SetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
  do {
    (*(void(__cdecl **)(int, _DWORD, _DWORD, int, int, int, _DWORD))(
        *(_DWORD *)dword_117D8A8 + 172))(dword_117D8A8, 0, 0, 7, -65281,
                                         1065353216, 0);
    result = alwaysfails;
  } while (alwaysfails);
  return result;
}

int marker_r_screenshot;
void __cdecl R_CubemapShotCopyBufferToTarga(unsigned char const *,
                                            unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapShotWriteTargaHeader(int, unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapShotCopySurfaceToBuffer(unsigned char *, int) {
  UNIMPLEMENTED();
}

void __cdecl R_GetDirForCubemapPixel(int, float, float, float *const) {
  UNIMPLEMENTED();
}

void __cdecl R_CopyCubemapShot(enum CubemapShot) { UNIMPLEMENTED(); }

void __cdecl R_CubemapShotExtractLinearLight(unsigned char **const, int, int,
                                             float (**const)[3]) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapLightingForDir(float (**const)[3], int, int,
                                     float const *const, float const *const,
                                     unsigned char *const) {
  UNIMPLEMENTED();
}

unsigned char __cdecl R_CubemapShotCalcReflectionFactor(int, int, int, float,
                                                        float) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapLighting(float (**const)[3], int, int, float const *const,
                               unsigned char **const) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapShotApplyFresnelToTarga(enum CubemapShot, float, float,
                                              unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapShotWriteTargaFile(char const *, enum CubemapShot, float,
                                         float) {
  UNIMPLEMENTED();
}

void __cdecl R_CubemapShotRestoreState(void) { UNIMPLEMENTED(); }

void __cdecl R_CubemapShotSetInitialState(void) { UNIMPLEMENTED(); }
