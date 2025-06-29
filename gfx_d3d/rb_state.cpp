public:
long __cdecl D3DDevice::SetRenderTarget(unsigned long, struct D3DSurface *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetDepthStencilSurface(struct D3DSurface *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetViewport(struct _D3DVIEWPORT9 const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetStreamSource(unsigned int, struct D3DVertexBuffer *,
                                        unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

public:
long __cdecl D3DDevice::SetIndices(struct D3DIndexBuffer *)
{
  UNIMPLEMENTED();
}

void __cdecl Vec2Mul(float const *const, float const *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec4Mad(float const *const, float, float const *const,
                     float *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetFvf(unsigned long)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_GetViewport(struct GfxViewport *outViewport)
{
    if (dword_1186CA4 == 1) {
      a1->x = 0;
      a1->y = 0;
      a1->width = dword_1186C9C;
      a1->height = dword_1186CA0;
    }
    else {
      *a1 = (GfxViewport)xmmword_11E19E0;
    }
  return 1;
}

void __cdecl RB_InitSceneViewport()
{
  int result; // eax

  dword_11E19E8 = vidConfig;
  result = dword_1180684;
  dword_11E19EC = dword_1180684;
  return result;
}

void __cdecl RB_PopMatrixStack()
{
  int result; // eax

  --dword_11E4480;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
      do
        (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 + 176))(
            dword_117D8A8, 256, &backEnd[888 * dword_11E4480 + 316]);
      while (alwaysfails);
      do
        (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 + 176))(
            dword_117D8A8, 2, &backEnd[888 * dword_11E4480 + 452]);
      while (alwaysfails);
        do {
          (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 +
                                                176))(
              dword_117D8A8, 3, &backEnd[888 * dword_11E4480 + 520]);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_PushMatrixStack()
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetShadowLookupMatrix(struct _D3DMATRIX const *matrix)
{
  int *result; // eax

  result = backEnd;
  unk_1218448 = *a1;
  unk_121844C = a1[1];
  *(_DWORD *)((char *)&loc_36E50 + (_DWORD)backEnd) = a1[2];
  *(_DWORD *)((char *)&locret_36E54 + (_DWORD)backEnd) = a1[3];
  unk_1218458 = a1[4];
  *(_DWORD *)((char *)&loc_36E5C + (_DWORD)backEnd) = a1[5];
  unk_1218460 = a1[6];
  *(_DWORD *)((char *)&loc_36E64 + (_DWORD)backEnd) = a1[7];
  unk_1218468 = a1[8];
  unk_121846C = a1[9];
  *(_DWORD *)((char *)&loc_36E70 + (_DWORD)backEnd) = a1[10];
  unk_1218474 = a1[11];
  unk_1218478 = a1[12];
  *(_DWORD *)((char *)&loc_36E7C + (_DWORD)backEnd) = a1[13];
  unk_1218480 = a1[14];
  *(_DWORD *)((char *)&loc_36E84 + (_DWORD)backEnd) = a1[15];
  unk_11E2580 = 0;
  unk_11E2581 = 0;
  unk_11E2582 = 0;
  unk_11E2583 = 0;
  return result;
}

void __cdecl RB_SetViewMatrix(struct _D3DMATRIX const *matrix)
{
  int *v1;    // eax
  int result; // eax

  v1 = &backEnd[888 * dword_11E4480 + 312];
  v1[140] = *a1;
  v1[141] = a1[1];
  v1[142] = a1[2];
  v1[143] = a1[3];
  v1[144] = a1[4];
  v1[145] = a1[5];
  v1[146] = a1[6];
  v1[147] = a1[7];
  v1[148] = a1[8];
  v1[149] = a1[9];
  v1[150] = a1[10];
  v1[151] = a1[11];
  v1[152] = a1[12];
  v1[153] = a1[13];
  v1[154] = a1[14];
  v1[155] = a1[15];
  *((_BYTE *)v1 + 816) = 1;
  *((_BYTE *)v1 + 817) = 0;
  *((_BYTE *)v1 + 818) = 0;
  *((_BYTE *)v1 + 819) = 0;
  *((_BYTE *)v1 + 1360) = 0;
  *((_BYTE *)v1 + 1361) = 0;
  *((_BYTE *)v1 + 1362) = 0;
  *((_BYTE *)v1 + 1363) = 0;
  *((_BYTE *)v1 + 1904) = 0;
  *((_BYTE *)v1 + 1905) = 0;
  *((_BYTE *)v1 + 1906) = 0;
  *((_BYTE *)v1 + 1907) = 0;
  *((_BYTE *)v1 + 2176) = 0;
  *((_BYTE *)v1 + 2177) = 0;
  *((_BYTE *)v1 + 2178) = 0;
  *((_BYTE *)v1 + 2179) = 0;
  *((_BYTE *)v1 + 3536) = 0;
  *((_BYTE *)v1 + 3537) = 0;
  *((_BYTE *)v1 + 3538) = 0;
  *((_BYTE *)v1 + 3539) = 0;
  *((_BYTE *)v1 + 1632) = 0;
  *((_BYTE *)v1 + 1633) = 0;
  *((_BYTE *)v1 + 1634) = 0;
  *((_BYTE *)v1 + 1635) = 0;
  *((_BYTE *)v1 + 2448) = 0;
  *((_BYTE *)v1 + 2449) = 0;
  *((_BYTE *)v1 + 2450) = 0;
  *((_BYTE *)v1 + 2451) = 0;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
        do {
          (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 +
                                                176))(dword_117D8A8, 2, a1);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_ChangedWorldMatrix(float worldScale)
{
  int *v1;    // edx
  int result; // eax
  int *v3;    // ebx

  v1 = &backEnd[888 * dword_11E4480 + 312];
  *(float *)v1 = a1;
  *((_BYTE *)v1 + 272) = 1;
  *((_BYTE *)v1 + 273) = 0;
  *((_BYTE *)v1 + 274) = 0;
  *((_BYTE *)v1 + 275) = 0;
  *((_BYTE *)v1 + 1360) = 0;
  *((_BYTE *)v1 + 1361) = 0;
  *((_BYTE *)v1 + 1362) = 0;
  *((_BYTE *)v1 + 1363) = 0;
  *((_BYTE *)v1 + 2176) = 0;
  *((_BYTE *)v1 + 2177) = 0;
  *((_BYTE *)v1 + 2178) = 0;
  *((_BYTE *)v1 + 2179) = 0;
  *((_BYTE *)v1 + 3536) = 0;
  *((_BYTE *)v1 + 3537) = 0;
  *((_BYTE *)v1 + 3538) = 0;
  *((_BYTE *)v1 + 3539) = 0;
  *((_BYTE *)v1 + 544) = 0;
  *((_BYTE *)v1 + 545) = 0;
  *((_BYTE *)v1 + 546) = 0;
  *((_BYTE *)v1 + 547) = 0;
  *((_BYTE *)v1 + 1632) = 0;
  *((_BYTE *)v1 + 1633) = 0;
  *((_BYTE *)v1 + 1634) = 0;
  *((_BYTE *)v1 + 1635) = 0;
  *((_BYTE *)v1 + 2448) = 0;
  *((_BYTE *)v1 + 2449) = 0;
  *((_BYTE *)v1 + 2450) = 0;
  *((_BYTE *)v1 + 2451) = 0;
  *((_BYTE *)v1 + 2720) = 0;
  *((_BYTE *)v1 + 2721) = 0;
  *((_BYTE *)v1 + 2722) = 0;
  *((_BYTE *)v1 + 2723) = 0;
  *((_BYTE *)v1 + 2992) = 0;
  *((_BYTE *)v1 + 2993) = 0;
  *((_BYTE *)v1 + 2994) = 0;
  *((_BYTE *)v1 + 2995) = 0;
  *((_BYTE *)v1 + 3264) = 0;
  *((_BYTE *)v1 + 3265) = 0;
  *((_BYTE *)v1 + 3266) = 0;
  *((_BYTE *)v1 + 3267) = 0;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
      v3 = v1 + 4;
        do {
          (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 +
                                                176))(dword_117D8A8, 256, v3);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

struct _D3DMATRIX *__cdecl RB_GetActiveWorldMatrix()
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetWorldMatrixForEntity(struct GfxEntity const *re)
{
  int *v1;    // edx
  int result; // eax
  int *v3;    // ebx

  MatrixSet44((int)&backEnd[888 * dword_11E4480 + 316], a1->origin, a1->axis[0],
              *(float *)&a1->scale);
  v1 = &backEnd[888 * dword_11E4480 + 312];
  *v1 = a1->scale;
  *((_BYTE *)v1 + 272) = 1;
  *((_BYTE *)v1 + 273) = 0;
  *((_BYTE *)v1 + 274) = 0;
  *((_BYTE *)v1 + 275) = 0;
  *((_BYTE *)v1 + 1360) = 0;
  *((_BYTE *)v1 + 1361) = 0;
  *((_BYTE *)v1 + 1362) = 0;
  *((_BYTE *)v1 + 1363) = 0;
  *((_BYTE *)v1 + 2176) = 0;
  *((_BYTE *)v1 + 2177) = 0;
  *((_BYTE *)v1 + 2178) = 0;
  *((_BYTE *)v1 + 2179) = 0;
  *((_BYTE *)v1 + 3536) = 0;
  *((_BYTE *)v1 + 3537) = 0;
  *((_BYTE *)v1 + 3538) = 0;
  *((_BYTE *)v1 + 3539) = 0;
  *((_BYTE *)v1 + 544) = 0;
  *((_BYTE *)v1 + 545) = 0;
  *((_BYTE *)v1 + 546) = 0;
  *((_BYTE *)v1 + 547) = 0;
  *((_BYTE *)v1 + 1632) = 0;
  *((_BYTE *)v1 + 1633) = 0;
  *((_BYTE *)v1 + 1634) = 0;
  *((_BYTE *)v1 + 1635) = 0;
  *((_BYTE *)v1 + 2448) = 0;
  *((_BYTE *)v1 + 2449) = 0;
  *((_BYTE *)v1 + 2450) = 0;
  *((_BYTE *)v1 + 2451) = 0;
  *((_BYTE *)v1 + 2720) = 0;
  *((_BYTE *)v1 + 2721) = 0;
  *((_BYTE *)v1 + 2722) = 0;
  *((_BYTE *)v1 + 2723) = 0;
  *((_BYTE *)v1 + 2992) = 0;
  *((_BYTE *)v1 + 2993) = 0;
  *((_BYTE *)v1 + 2994) = 0;
  *((_BYTE *)v1 + 2995) = 0;
  *((_BYTE *)v1 + 3264) = 0;
  *((_BYTE *)v1 + 3265) = 0;
  *((_BYTE *)v1 + 3266) = 0;
  *((_BYTE *)v1 + 3267) = 0;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
      v3 = v1 + 4;
        do {
          (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 +
                                                176))(dword_117D8A8, 256, v3);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_DecideDefaultSamplerState()
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetDepthHackNearClip(float nearClip)
{
  int *v1;    // edx
  int result; // eax
  int *v3;    // ebx

  backEnd[888 * dword_11E4480 + 534] = LODWORD(a1) ^ 0x80000000;
  v1 = &backEnd[888 * dword_11E4480 + 312];
  *((_BYTE *)v1 + 1088) = 1;
  *((_BYTE *)v1 + 1089) = 0;
  *((_BYTE *)v1 + 1090) = 0;
  *((_BYTE *)v1 + 1091) = 0;
  *((_BYTE *)v1 + 1904) = 0;
  *((_BYTE *)v1 + 1905) = 0;
  *((_BYTE *)v1 + 1906) = 0;
  *((_BYTE *)v1 + 1907) = 0;
  *((_BYTE *)v1 + 2176) = 0;
  *((_BYTE *)v1 + 2177) = 0;
  *((_BYTE *)v1 + 2178) = 0;
  *((_BYTE *)v1 + 2179) = 0;
  *((_BYTE *)v1 + 3536) = 0;
  *((_BYTE *)v1 + 3537) = 0;
  *((_BYTE *)v1 + 3538) = 0;
  *((_BYTE *)v1 + 3539) = 0;
  *((_BYTE *)v1 + 2448) = 0;
  *((_BYTE *)v1 + 2449) = 0;
  *((_BYTE *)v1 + 2450) = 0;
  *((_BYTE *)v1 + 2451) = 0;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
      v3 = v1 + 208;
      do
        result = (*(int(__cdecl **)(int, int, int *))(
            *(_DWORD *)dword_117D8A8 + 176))(dword_117D8A8, 3, v3);
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_SetProjectionMatrix(struct _D3DMATRIX const *matrix)
{
  int v1;     // eax
  int *v2;    // edx
  int result; // eax
  int *v4;    // ebx

  v1 = 3552 * dword_11E4480 + 1248;
  *(int *)((char *)&backEnd[208] + v1) = *a1;
  *(int *)((char *)&backEnd[209] + v1) = a1[1];
  *(int *)((char *)&backEnd[210] + v1) = a1[2];
  *(int *)((char *)&backEnd[211] + v1) = a1[3];
  *(int *)((char *)&backEnd[212] + v1) = a1[4];
  *(int *)((char *)&backEnd[213] + v1) = a1[5];
  *(int *)((char *)&backEnd[214] + v1) = a1[6];
  *(int *)((char *)&backEnd[215] + v1) = a1[7];
  *(int *)((char *)&backEnd[216] + v1) = a1[8];
  *(int *)((char *)&backEnd[217] + v1) = a1[9];
  *(int *)((char *)&backEnd[218] + v1) = a1[10];
  *(int *)((char *)&backEnd[219] + v1) = a1[11];
  *(int *)((char *)&backEnd[220] + v1) = a1[12];
  *(int *)((char *)&backEnd[221] + v1) = a1[13];
  *(int *)((char *)&backEnd[222] + v1) = a1[14];
  *(int *)((char *)&backEnd[223] + v1) = a1[15];
  v2 = &backEnd[888 * dword_11E4480 + 312];
  *((_BYTE *)v2 + 1088) = 1;
  *((_BYTE *)v2 + 1089) = 0;
  *((_BYTE *)v2 + 1090) = 0;
  *((_BYTE *)v2 + 1091) = 0;
  *((_BYTE *)v2 + 1904) = 0;
  *((_BYTE *)v2 + 1905) = 0;
  *((_BYTE *)v2 + 1906) = 0;
  *((_BYTE *)v2 + 1907) = 0;
  *((_BYTE *)v2 + 2176) = 0;
  *((_BYTE *)v2 + 2177) = 0;
  *((_BYTE *)v2 + 2178) = 0;
  *((_BYTE *)v2 + 2179) = 0;
  *((_BYTE *)v2 + 3536) = 0;
  *((_BYTE *)v2 + 3537) = 0;
  *((_BYTE *)v2 + 3538) = 0;
  *((_BYTE *)v2 + 3539) = 0;
  *((_BYTE *)v2 + 2448) = 0;
  *((_BYTE *)v2 + 2449) = 0;
  *((_BYTE *)v2 + 2450) = 0;
  *((_BYTE *)v2 + 2451) = 0;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
      v4 = v2 + 208;
        do {
          (*(void(__cdecl **)(int, int, int *))(*(_DWORD *)dword_117D8A8 +
                                                176))(dword_117D8A8, 3, v4);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_UpdateViewportConstants()
{
  unsigned int v0; // ebx
  float v1;        // xmm2_4
  float v2;        // xmm6_4
  unsigned int v3; // esi
  float v4;        // xmm1_4
  float v5;        // xmm4_4
  float v6;        // xmm3_4
  float v7;        // xmm5_4
  float v8;        // xmm5_4
  float v9;        // xmm3_4
  int v11;         // edx
  int v12;         // eax
  int v13;         // edx
  int v14;         // eax
  float v15;       // [esp+20h] [ebp-78h]
  float v16;       // [esp+30h] [ebp-68h]
  float v17;       // [esp+70h] [ebp-28h]
  float v18;       // [esp+74h] [ebp-24h]
  float v19;       // [esp+78h] [ebp-20h]
  float v20;       // [esp+7Ch] [ebp-1Ch]
  float v21;       // [esp+88h] [ebp-10h] BYREF
  float v22[3];    // [esp+8Ch] [ebp-Ch] BYREF

  byte_11E1ABD = 0;
  byte_11E1ABC = 1;
  v0 = dword_1186C9C;
  v1 = (float)dword_1186C9C;
  v2 = 1.0 / (float)dword_1186C9C;
  v3 = dword_1186CA0;
  v4 = (float)dword_1186CA0;
  v5 = 1.0 / (float)dword_1186CA0;
    if (dword_1186CA4 == 1) {
      v6 = 0.0;
      v7 = 0.0;
    }
    else {
      v3 = HIDWORD(xmmword_11E19E0);
      v0 = DWORD2(xmmword_11E19E0);
      v4 = (float)SHIDWORD(xmmword_11E19E0);
      v1 = (float)SDWORD2(xmmword_11E19E0);
      v6 = (float)SDWORD1(xmmword_11E19E0);
      v7 = (float)(int)xmmword_11E19E0;
    }
  v18 = (float)(v2 * v1) * 0.5;
  v17 = 0.5 * (float)(v5 * v4);
  v16 = 1.0 / (float)dword_1186CA0;
  v15 = 1.0 / (float)dword_1186C9C;
  MacOpenGLUtils::GetSubPixelOffset((MacOpenGLUtils *)v22, &v21);
  v20 = (float)(v15 * v22[0]) + (float)(v18 + (float)(v7 * v2));
  v19 = (float)(v16 * v21) + (float)(v17 + (float)(v6 * v5));
    if (v0 > 1) {
      v11 = 1;
      v12 = 32;
        while (1) {
          v11 *= 2;
          if (v0 <= v11)
            break;
            if (!--v12) {
                if (v11 < 0) {
                  v8 = (float)(v11 & 1 | ((unsigned int)v11 >> 1)) +
                       (float)(v11 & 1 | ((unsigned int)v11 >> 1));
                  goto LABEL_5;
                }
              goto LABEL_12;
            }
        }
        if (v11 < 0) {
          v8 =
              (float)((unsigned int)v11 >> 1) + (float)((unsigned int)v11 >> 1);
          goto LABEL_5;
        }
    LABEL_12:
      v8 = (float)v11;
      if (v3 <= 1)
        goto LABEL_6;
    }
    else {
      v8 = 1.0;
    LABEL_5:
        if (v3 <= 1) {
        LABEL_6:
          v9 = 1.0;
          goto LABEL_7;
        }
    }
  v13 = 1;
  v14 = 32;
    do {
      v13 *= 2;
        if (v3 <= v13) {
          if (v13 >= 0)
            goto LABEL_17;
          v9 =
              (float)((unsigned int)v13 >> 1) + (float)((unsigned int)v13 >> 1);
          goto LABEL_7;
        }
      --v14;
    }
  while (v14);
    if (v13 >= 0) {
    LABEL_17:
      v9 = (float)v13;
      goto LABEL_7;
    }
  v9 = (float)(v13 & 1 | ((unsigned int)v13 >> 1)) +
       (float)(v13 & 1 | ((unsigned int)v13 >> 1));
LABEL_7:
  RB_SetCodeConstant(171, (float)(v1 - 0.5) / v8, (float)(v4 - 0.5) / v9, v15,
                     v16);
  RB_SetCodeConstant(174, v18 * (float)(v1 / v8), v17 * (float)(v4 / v9), 0.0,
                     1.0);
  return RB_SetCodeConstant(175, v20 * (float)(v1 / v8), v19 * (float)(v4 / v9),
                            0.0, 0.0);
}

void __cdecl RB_SetMatricesForView(struct GfxViewParms const *viewParms)
{
  int *v1;    // eax
  int *v2;    // eax
  int result; // eax

  v1 = &backEnd[888 * dword_11E4480 + 312];
  *(D3DMATRIX *)(v1 + 140) = a1->viewMatrix;
  v1[208] = LODWORD(a1->projectionMatrix[0]);
  v1[209] = LODWORD(a1->projectionMatrix[1]);
  v1[210] = LODWORD(a1->projectionMatrix[2]);
  v1[211] = LODWORD(a1->projectionMatrix[3]);
  v1[212] = LODWORD(a1->projectionMatrix[4]);
  v1[213] = LODWORD(a1->projectionMatrix[5]);
  v1[214] = LODWORD(a1->projectionMatrix[6]);
  v1[215] = LODWORD(a1->projectionMatrix[7]);
  v1[216] = LODWORD(a1->projectionMatrix[8]);
  v1[217] = LODWORD(a1->projectionMatrix[9]);
  v1[218] = LODWORD(a1->projectionMatrix[10]);
  v1[219] = LODWORD(a1->projectionMatrix[11]);
  v1[220] = LODWORD(a1->projectionMatrix[12]);
  v1[221] = LODWORD(a1->projectionMatrix[13]);
  v1[222] = LODWORD(a1->projectionMatrix[14]);
  v1[223] = LODWORD(a1->projectionMatrix[15]);
  v1[412] = LODWORD(a1->viewProjectionMatrix[0]);
  v1[413] = LODWORD(a1->viewProjectionMatrix[1]);
  v1[414] = LODWORD(a1->viewProjectionMatrix[2]);
  v1[415] = LODWORD(a1->viewProjectionMatrix[3]);
  v1[416] = LODWORD(a1->viewProjectionMatrix[4]);
  v1[417] = LODWORD(a1->viewProjectionMatrix[5]);
  v1[418] = LODWORD(a1->viewProjectionMatrix[6]);
  v1[419] = LODWORD(a1->viewProjectionMatrix[7]);
  v1[420] = LODWORD(a1->viewProjectionMatrix[8]);
  v1[421] = LODWORD(a1->viewProjectionMatrix[9]);
  v1[422] = LODWORD(a1->viewProjectionMatrix[10]);
  v1[423] = LODWORD(a1->viewProjectionMatrix[11]);
  v1[424] = LODWORD(a1->viewProjectionMatrix[12]);
  v1[425] = LODWORD(a1->viewProjectionMatrix[13]);
  v1[426] = LODWORD(a1->viewProjectionMatrix[14]);
  v1[427] = LODWORD(a1->viewProjectionMatrix[15]);
  v1[428] = LODWORD(a1->inverseViewProjectionMatrix[0]);
  v1[429] = LODWORD(a1->inverseViewProjectionMatrix[1]);
  v1[430] = LODWORD(a1->inverseViewProjectionMatrix[2]);
  v1[431] = LODWORD(a1->inverseViewProjectionMatrix[3]);
  v1[432] = LODWORD(a1->inverseViewProjectionMatrix[4]);
  v1[433] = LODWORD(a1->inverseViewProjectionMatrix[5]);
  v1[434] = LODWORD(a1->inverseViewProjectionMatrix[6]);
  v1[435] = LODWORD(a1->inverseViewProjectionMatrix[7]);
  v1[436] = LODWORD(a1->inverseViewProjectionMatrix[8]);
  v1[437] = LODWORD(a1->inverseViewProjectionMatrix[9]);
  v1[438] = LODWORD(a1->inverseViewProjectionMatrix[10]);
  v1[439] = LODWORD(a1->inverseViewProjectionMatrix[11]);
  v1[440] = LODWORD(a1->inverseViewProjectionMatrix[12]);
  v1[441] = LODWORD(a1->inverseViewProjectionMatrix[13]);
  v1[442] = LODWORD(a1->inverseViewProjectionMatrix[14]);
  v1[443] = LODWORD(a1->inverseViewProjectionMatrix[15]);
  v2 = &backEnd[888 * dword_11E4480 + 312];
  *((_BYTE *)v2 + 816) = 1;
  *((_BYTE *)v2 + 817) = 0;
  *((_BYTE *)v2 + 818) = 0;
  *((_BYTE *)v2 + 819) = 0;
  *((_BYTE *)v2 + 1088) = 1;
  *((_BYTE *)v2 + 1089) = 0;
  *((_BYTE *)v2 + 1090) = 0;
  *((_BYTE *)v2 + 1091) = 0;
  *((_BYTE *)v2 + 1360) = 0;
  *((_BYTE *)v2 + 1361) = 0;
  *((_BYTE *)v2 + 1362) = 0;
  *((_BYTE *)v2 + 1363) = 0;
  *((_BYTE *)v2 + 1904) = 1;
  *((_BYTE *)v2 + 1905) = 1;
  *((_BYTE *)v2 + 1906) = 0;
  *((_BYTE *)v2 + 1907) = 0;
  *((_BYTE *)v2 + 2176) = 0;
  *((_BYTE *)v2 + 2177) = 0;
  *((_BYTE *)v2 + 2178) = 0;
  *((_BYTE *)v2 + 2179) = 0;
  *((_BYTE *)v2 + 3536) = 0;
  *((_BYTE *)v2 + 3537) = 0;
  *((_BYTE *)v2 + 3538) = 0;
  *((_BYTE *)v2 + 3539) = 0;
  *((_BYTE *)v2 + 2448) = 0;
  *((_BYTE *)v2 + 2449) = 0;
  *((_BYTE *)v2 + 2450) = 0;
  *((_BYTE *)v2 + 2451) = 0;
  result = r_rendererInUse;
    if (*(_DWORD *)(r_rendererInUse + 8) == 2) {
      do
        (*(void(__cdecl **)(int, int, D3DMATRIX *))(
            *(_DWORD *)dword_117D8A8 + 176))(dword_117D8A8, 2, &a1->viewMatrix);
      while (alwaysfails);
        do {
          (*(void(__cdecl **)(int, int, float *))(*(_DWORD *)dword_117D8A8 +
                                                  176))(dword_117D8A8, 3,
                                                        a1->projectionMatrix);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_SetAnisotropy()
{
  UNIMPLEMENTED();
}

void __cdecl RB_ChangeState_1(int stateBits1)
{
  int result;      // eax
  unsigned int v2; // ebx
  int v3;          // eax
  int v4;          // ebx
  float v5;        // xmm1_4
  float v6;        // xmm0_4
  _DWORD *v7;      // edi
  int v8;          // esi
  int v9;          // ebx
  _DWORD *v10;     // edi
  int v11;         // esi
  int v12;         // ebx
  int v13;         // [esp+1Ch] [ebp-2Ch]
  float v14;       // [esp+28h] [ebp-20h]
  float v15;       // [esp+2Ch] [ebp-1Ch]

  result = dword_1186C0C ^ a1;
  v13 = dword_1186C0C ^ a1;
  if (dword_1186C0C == a1)
    return result;
    if ((result & 1) != 0) {
      do
        (*(void(__cdecl **)(int, int, unsigned int))(
            *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 14, a1 & 1);
      while (alwaysfails);
      if ((v13 & 2) == 0)
        goto LABEL_4;
    LABEL_34:
      v2 = (a1 >> 1) & 1;
      do
        (*(void(__cdecl **)(int, int, bool))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 7, (a1 & 2) == 0);
      while (alwaysfails);
      goto LABEL_5;
    }
  if ((v13 & 2) != 0)
    goto LABEL_34;
LABEL_4:
  v2 = (a1 >> 1) & 1;
LABEL_5:
    if (v2) {
      a1 |= dword_1186C0C & 0xC;
      v13 &= 0xFFFFFFF3;
    }
    if ((v13 & 0xC) != 0) {
      v3 = a1 & 0xC;
      if (v3 == 4)
        v4 = 4;
      else
        v4 = 5 * (v3 != 8) + 3;
      do
        (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 23, v4);
      while (alwaysfails);
    }
    if ((v13 & 0x30) != 0) {
      v5 = (float)((int)(a1 & 0x30) >> 4);
      v6 = (float)(v5 * *(float *)(r_polygonOffsetBias + 8)) * 0.000015258789;
      v14 = v6;
        if (byte_118061A) {
          v15 = v5 * *(float *)(r_polygonOffsetScale + 8);
          do
            (*(void(__cdecl **)(int, int, float))(
                *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 175,
                                                 COERCE_FLOAT(LODWORD(v15)));
          while (alwaysfails);
        }
        else {
          v14 = v6 + v6;
        }
      do
        (*(void(__cdecl **)(int, int, float))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 195, COERCE_FLOAT(LODWORD(v14)));
      while (alwaysfails);
    }
    if ((a1 & 0x40) != 0) {
        if ((v13 & 0x40) != 0) {
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 52, 1);
          while (alwaysfails);
        }
    }
    else {
        if ((v13 & 0x40) != 0) {
          do
            (*(void(__cdecl **)(int, int, _DWORD))(*(_DWORD *)dword_117D8A8 +
                                                   228))(dword_117D8A8, 52, 0);
          while (alwaysfails);
        }
      a1 |= dword_1186C0C & 0xFFFFFF80;
      v13 &= 0x7Fu;
    }
    if ((a1 & 0x80u) == 0) {
        if ((v13 & 0x80u) != 0) {
          do
            (*(void(__cdecl **)(int, int, _DWORD))(*(_DWORD *)dword_117D8A8 +
                                                   228))(dword_117D8A8, 185, 0);
          while (alwaysfails);
        }
      a1 |= dword_1186C0C & 0xFFF00000;
      v13 &= 0xFFFFFu;
    }
    else if ((v13 & 0x80u) != 0) {
      do
        (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 185, 1);
      while (alwaysfails);
    }
    if ((v13 & 0x1FF1FF00) != 0) {
      v7 = &s_stencilOpDecode;
        do {
            if (((v13 >> *v7) & 7) != 0) {
              v8 = s_stencilOpTable[((int)a1 >> *v7) & 7];
              v9 = v7[1];
              do
                (*(void(__cdecl **)(int, int, int))(
                    *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, v9, v8);
              while (alwaysfails);
            }
          v7 += 2;
        }
      while (v7 != (_DWORD *)&unk_2F2430);
    }
    if ((v13 & 0xE00E0000) != 0) {
      v10 = &s_stencilFuncDecode;
        do {
            if (((v13 >> *v10) & 7) != 0) {
              v11 = s_stencilFuncTable[((int)a1 >> *v10) & 7];
              v12 = v10[1];
              do
                (*(void(__cdecl **)(int, int, int))(
                    *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, v12, v11);
              while (alwaysfails);
            }
          v10 += 2;
        }
      while (&unk_2F23D0 != (_UNKNOWN *)v10);
    }
  result = a1;
  dword_1186C0C = a1;
  return result;
}

void __cdecl RB_ChangeState_0(int stateBits0)
{
  int v1;              // edi
  int v2;              // eax
  unsigned int v3;     // ebx
  int v4;              // eax
  int v5;              // esi
  int i;               // ecx
  int v7;              // ebx
  int v8;              // ebx
  int v9;              // ebx
  int v10;             // ebx
  int v11;             // ebx
  int v12;             // ebx
  int v13;             // ebx
  int v14;             // ebx
  int v16;             // [esp+14h] [ebp-24h]
  unsigned __int8 v17; // [esp+1Bh] [ebp-1Dh]

  v1 = a1;
  v16 = a1 ^ dword_1186C08;
    if (a1 == dword_1186C08) {
      LOBYTE(v2) = dword_1186C00 ^ a1;
      if (((dword_1186C00 ^ a1) & 0x7000700) == 0)
        return v2;
    }
    if ((v16 & 0x800) != 0) {
      v3 = (a1 >> 11) & 1;
      do
        (*(void(__cdecl **)(int, int, bool))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 15, (a1 & 0x800) == 0);
      while (alwaysfails);
    }
    else {
      v3 = (a1 >> 11) & 1;
    }
    if (v3) {
      v1 = dword_1186C08 & 0x3000 | a1;
      v16 &= 0xFFFFCFFF;
      if ((v16 & 0x3000) == 0)
        goto LABEL_17;
    }
    else if ((v16 & 0x3000) == 0) {
      goto LABEL_17;
    }
  v4 = v1 & 0x3000;
    if (v4 == 4096) {
      v5 = 5;
      v17 = 0;
    }
    else {
      if (v4 == 0x2000)
        v5 = 2;
      else
        v5 = 7;
      v17 = 0x80;
    }
  do
    (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 + 228))(
        dword_117D8A8, 25, v5);
  while (alwaysfails);
    if (byte_1186D48 != v17) {
        for (i = v17;; i = v17) {
          (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 + 228))(
              dword_117D8A8, 24, i);
          if (!alwaysfails)
            break;
        }
      byte_1186D48 = v17;
    }
LABEL_17:
    if ((v16 & 0x18000000) != 0) {
      do
        (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 168,
            ((v1 & 0x10000000) != 0 ? 8 : 0) | ((v1 & 0x8000000) != 0 ? 7 : 0));
      while (alwaysfails);
        if ((v16 & 0x20000000) == 0) {
        LABEL_19:
          if ((v16 & 0xC000) == 0)
            goto LABEL_20;
        LABEL_56:
          v12 = s_cullTable[(v1 & 0xC000) >> 14];
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 22, v12);
          while (alwaysfails);
          if (v16 >= 0)
            goto LABEL_21;
          goto LABEL_59;
        }
    }
    else if ((v16 & 0x20000000) == 0) {
      goto LABEL_19;
    }
  do
    (*(void(__cdecl **)(int, int, unsigned int))(
        *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 28,
                                         ((unsigned int)v1 >> 29) & 1);
  while (alwaysfails);
  if ((v16 & 0xC000) != 0)
    goto LABEL_56;
LABEL_20:
    if (v16 < 0) {
    LABEL_59:
        if (v1 < 0) {
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 8, 2);
          while (alwaysfails);
        }
        else {
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 8, 3);
          while (alwaysfails);
        }
    }
LABEL_21:
    if (((v1 & 0x700) == 0) != ((dword_1186C00 & 0x700) == 0)) {
      do
        (*(void(__cdecl **)(int, int, bool))(*(_DWORD *)dword_117D8A8 + 228))(
            dword_117D8A8, 27, (v1 & 0x700) != 0);
      while (alwaysfails);
    }
    if ((v1 & 0x700) != 0) {
        if ((v16 & 0x700) != 0) {
          v13 = s_blendOpTable[(v1 >> 8) & 7];
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 171, v13);
          while (alwaysfails);
        }
    }
    else {
      v1 = dword_1186C08 & 0x7FF | v1 & 0xFFFFF800;
      v16 &= 0xFFFFF800;
    }
    if ((_BYTE)v16) {
        if ((v16 & 0xF) != 0) {
          v7 = s_blendTable[v1 & 0xF];
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 19, v7);
          while (alwaysfails);
        }
        if ((v16 & 0xF0) != 0) {
          v8 = s_blendTable[(v1 >> 4) & 0xF];
          do
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                228))(dword_117D8A8, 20, v8);
          while (alwaysfails);
        }
    }
  LOBYTE(v2) = (dword_1186C00 & 0x7000000) == 0;
    if (((v1 & 0x7000000) == 0) != (_BYTE)v2) {
      do
        LOBYTE(v2) = (*(int(__cdecl **)(int, int, bool))(
            *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 206,
                                             (v1 & 0x7000000) != 0);
      while (alwaysfails);
    }
    if ((v1 & 0x7000000) != 0) {
        if ((v16 & 0x7000000) != 0) {
          v14 = s_blendOpTable[(v1 >> 24) & 7];
            do {
              (*(void(__cdecl **)(int, int, int))(
                  *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 209, v14);
              LOBYTE(v2) = alwaysfails;
            }
          while (alwaysfails);
        }
    }
    else {
      LOBYTE(v2) = 0;
      v1 = dword_1186C08 & 0x7FF0000 | v1 & 0xF800FFFF;
      v16 &= 0xF800FFFF;
    }
    if ((v16 & 0xFF0000) != 0) {
        if ((v16 & 0xF0000) != 0) {
          v9 = s_blendTable[(v1 >> 16) & 0xF];
            do {
              (*(void(__cdecl **)(int, int, int))(*(_DWORD *)dword_117D8A8 +
                                                  228))(dword_117D8A8, 207, v9);
              LOBYTE(v2) = alwaysfails;
            }
          while (alwaysfails);
        }
        if ((v16 & 0xF00000) != 0) {
          v10 = s_blendTable[(v1 >> 20) & 0xF];
            do {
              (*(void(__cdecl **)(int, int, int))(
                  *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 208, v10);
              LOBYTE(v2) = alwaysfails;
            }
          while (alwaysfails);
        }
    }
    if ((v16 & 0x40000000) != 0) {
        do {
          (*(void(__cdecl **)(int, int, unsigned int))(
              *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 143,
                                               ((unsigned int)v1 >> 30) & 1);
          LOBYTE(v2) = alwaysfails;
        }
      while (alwaysfails);
    }
    if (byte_118061E) {
      v2 = *(_DWORD *)(r_aaAlpha + 8);
        if (v2) {
            if ((v16 & 0xF00) != 0) {
                if ((v1 & 0xF00) != 0) {
                  v11 = 0;
                }
                else {
                  v11 = 1094800211;
                  if (v2 != 2)
                    v11 = 1129272385;
                }
                do {
                  (*(void(__cdecl **)(int, int, int))(
                      *(_DWORD *)dword_117D8A8 + 228))(dword_117D8A8, 181, v11);
                  LOBYTE(v2) = alwaysfails;
                }
              while (alwaysfails);
            }
        }
    }
  dword_1186C08 = v1;
  return v2;
}

void __cdecl RB_ReleaseVertexDecl()
{
  int result; // eax

    if (dword_1186D40 || (result = dword_1186D44) != 0) {
        do {
          (*(void(__cdecl **)(int, _DWORD))(*(_DWORD *)dword_117D8A8 + 356))(
              dword_117D8A8, 0);
          result = alwaysfails;
        }
      while (alwaysfails);
      dword_1186D44 = 0;
      dword_1186D40 = 0;
    }
  return result;
}

bool __cdecl RB_IsVertexBufferBusy(struct D3DVertexBuffer *)
{
  UNIMPLEMENTED();
}

bool __cdecl RB_IsIndexBufferBusy(struct D3DIndexBuffer *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ChangeStreamSource(int, struct D3DVertexBuffer *, int, int)
{
  int v4;     // edx
  int result; // eax

  v4 = 3 * a1;
  dword_1186CE0 = dword_1186CD0[3 * a1];
  dword_1186CD0[v4] = (int)a2;
  dword_1186CD0[v4 + 1] = a3;
  dword_1186CD0[v4 + 2] = a4;
  do
    result = (*(int(__cdecl **)(int, int, IDirect3DVertexBuffer9 *, int, int))(
        *(_DWORD *)dword_117D8A8 + 400))(dword_117D8A8, a1, a2, a3, a4);
  while (alwaysfails);
  dword_1186CE0 = 0;
  return result;
}

void __cdecl RB_ChangeIndices(struct D3DIndexBuffer *ib)
{
  int result; // eax

  dword_1186CDC = dword_1186CCC;
  dword_1186CCC = (int)a1;
    do {
      (*(void(__cdecl **)(int, IDirect3DIndexBuffer9 *))(
          *(_DWORD *)dword_117D8A8 + 416))(dword_117D8A8, a1);
      result = alwaysfails;
    }
  while (alwaysfails);
  dword_1186CDC = 0;
  return result;
}

void __cdecl RB_ReleasePixelShader(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetViewport(struct GfxViewport const *viewport)
{
  int32_t result; // eax

    if (a1->x != (_DWORD)xmmword_1186CB0 || a1->y != DWORD1(xmmword_1186CB0) ||
        a1->width != DWORD2(xmmword_1186CB0) ||
        (result = a1->height, result != HIDWORD(xmmword_1186CB0))) {
      xmmword_1186CB0 = (__int128)*a1;
      do
        result = (*(int(__cdecl **)(int, __int128 *))(
            *(_DWORD *)dword_117D8A8 + 188))(dword_117D8A8, &xmmword_1186CB0);
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_SetDepthRange(float, float)
{
  int result; // eax

    if (*(float *)&a1 != *(float *)&dword_1186CC0 ||
        *(float *)&a2 != *(float *)&dword_1186CC4) {
      dword_1186CC0 = a1;
      dword_1186CC4 = a2;
        do {
          (*(void(__cdecl **)(int, int *))(*(_DWORD *)dword_117D8A8 + 188))(
              dword_117D8A8, &dword_1186CB0);
          result = alwaysfails;
        }
      while (alwaysfails);
    }
  return result;
}

void __cdecl RB_SetSampler(int samplerIndex, unsigned char samplerState,
                           struct GfxImage *image)
{
  int *result;         // eax
  char v4;             // dl
  int v5;              // eax
  int v6;              // ebx
  int v7;              // esi
  int v8;              // eax
  int v9;              // edx
  int v10;             // ebx
  unsigned __int8 v11; // [esp+10h] [ebp-38h]
  char v12;            // [esp+20h] [ebp-28h]
  char v13;            // [esp+2Bh] [ebp-1Dh]
  int v14;             // [esp+2Ch] [ebp-1Ch]

  result = (int *)a2;
  v11 = a2;
    if ((GfxImage *)dword_1186CF4[a1] != a3) {
        if (a3) {
          do
            (*(void(__cdecl **)(int, int, GfxTexture))(
                *(_DWORD *)dword_117D8A8 + 260))(dword_117D8A8, a1,
                                                 a3->texture);
          while (alwaysfails);
        }
        else {
          do
            (*(void(__cdecl **)(int, int, _DWORD))(*(_DWORD *)dword_117D8A8 +
                                                   260))(dword_117D8A8, a1, 0);
          while (alwaysfails);
        }
      result = (int *)&unk_1186CF0;
      *((_DWORD *)&unk_1186CF0 + a1 + 1) = a3;
    }
    if (a3) {
      if ((a2 & 0xF) == 0)
        v11 = algn_11E1ABE[0] | a2;
      result = (int *)a1;
      v4 = byte_1186CE4[a1];
      v13 = v4 ^ v11;
        if ((unsigned __int8)v4 != v11) {
          v12 = v4 ^ v11;
            if ((((unsigned __int8)v4 ^ v11) & 3) != 0) {
              v5 = v11 & 3;
              v6 = s_filterTable[v5];
                if (v6 == 3) {
                  if (!*(_DWORD *)&algn_1180609[3])
                    v6 = 2;
                  v7 = 2;
                }
                else {
                  v7 = s_filterTable[v5];
                }
              v8 = v4 & 3;
              v9 = s_filterTable[v8];
                if (v9 == 3) {
                  if (!*(_DWORD *)&algn_1180609[3])
                    v9 = 2;
                  v14 = 2;
                }
                else {
                  v14 = s_filterTable[v8];
                }
                if (v9 != v6) {
                  do
                    (*(void(__cdecl **)(int, int, int, int))(
                        *(_DWORD *)dword_117D8A8 + 276))(dword_117D8A8, a1, 6,
                                                         v6);
                  while (alwaysfails);
                }
                if (v14 != v7) {
                  do
                    (*(void(__cdecl **)(int, int, int, int))(
                        *(_DWORD *)dword_117D8A8 + 276))(dword_117D8A8, a1, 5,
                                                         v7);
                  while (alwaysfails);
                }
            }
            if ((v12 & 0xC) != 0) {
              v10 = *(int *)((char *)s_filterTable + (v11 & 0xC));
              do
                (*(void(__cdecl **)(int, int, int, int))(
                    *(_DWORD *)dword_117D8A8 + 276))(dword_117D8A8, a1, 7, v10);
              while (alwaysfails);
            }
            if ((v12 & 0x70) != 0) {
                if ((v13 & 0x10) != 0) {
                  do
                    (*(void(__cdecl **)(int, int, int, int))(
                        *(_DWORD *)dword_117D8A8 + 276))(
                        dword_117D8A8, a1, 1, (v11 & 0x10) == 0 ? 1 : 3);
                  while (alwaysfails);
                }
                if ((v13 & 0x20) != 0) {
                  do
                    (*(void(__cdecl **)(int, int, int, int))(
                        *(_DWORD *)dword_117D8A8 + 276))(
                        dword_117D8A8, a1, 2, (v11 & 0x20) == 0 ? 1 : 3);
                  while (alwaysfails);
                }
                if ((v13 & 0x40) != 0) {
                  do
                    (*(void(__cdecl **)(int, int, int, int))(
                        *(_DWORD *)dword_117D8A8 + 276))(
                        dword_117D8A8, a1, 3, (v11 & 0x40) == 0 ? 1 : 3);
                  while (alwaysfails);
                }
            }
          result = &dword_1186CE0;
          *((_BYTE *)&dword_1186CE0 + a1 + 4) = v11;
        }
    }
  return result;
}

void __cdecl RB_ClearAllStreamSources()
{
  int result; // eax

  result = dword_1186CD0[0];
    if (dword_1186CD0[0] || dword_1186CD4 || dword_1186CD8) {
      dword_1186CE0 = dword_1186CD0[0];
      dword_1186CD0[0] = 0;
      dword_1186CD4 = 0;
      dword_1186CD8 = 0;
      do
        result = (*(int(__cdecl **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(
            *(_DWORD *)dword_117D8A8 + 400))(dword_117D8A8, 0, 0, 0, 0);
      while (alwaysfails);
      dword_1186CE0 = 0;
    }
  return result;
}

void __cdecl RB_BindDefaultImages()
{
  UNIMPLEMENTED();
}

void __cdecl RB_ReleaseVertexShader(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_UpdateViewport()
{
  int v0;     // ebx
  int v1;     // ecx
  __int64 v2; // rax

  byte_11E1ABC = 0;
    if (dword_1186CA4 == 1) {
      HIDWORD(v2) = dword_1186C9C;
      v0 = dword_1186CA0;
      v1 = 0;
      LODWORD(v2) = 0;
      byte_1186CC8 = 0;
        if ((_DWORD)xmmword_1186CB0) {
        LABEL_3:
          LODWORD(xmmword_1186CB0) = v1;
          *(_QWORD *)((char *)&xmmword_1186CB0 + 4) = v2;
          HIDWORD(xmmword_1186CB0) = v0;
            do {
              (*(void(__cdecl **)(int, __int128 *))(*(_DWORD *)dword_117D8A8 +
                                                    188))(dword_117D8A8,
                                                          &xmmword_1186CB0);
              LODWORD(v2) = alwaysfails;
            }
          while (alwaysfails);
          return v2;
        }
    }
    else {
      v0 = HIDWORD(xmmword_11E19E0);
      v1 = xmmword_11E19E0;
      v2 = *(_QWORD *)((char *)&xmmword_11E19E0 + 4);
      byte_1186CC8 = 0;
      if ((_DWORD)xmmword_1186CB0 != (_DWORD)xmmword_11E19E0)
        goto LABEL_3;
    }
  if (v2 != *(_QWORD *)((char *)&xmmword_1186CB0 + 4) ||
      v0 != HIDWORD(xmmword_1186CB0))
    goto LABEL_3;
  return v2;
}

void __cdecl RB_UnbindAllImages()
{
  UNIMPLEMENTED();
}

void __cdecl RB_UnbindImage(struct GfxImage const *image)
{
  __int64 *result;     // eax
  int v2;              // esi
  const GfxImage **v3; // ebx

  result = &vidConfig;
    if (dword_118069C > 0) {
      v2 = 0;
      v3 = (const GfxImage **)&dxState;
        do {
            if (v3[2109] == a1) {
              RB_SetSampler(v2, 0, 0);
              result = &vidConfig;
            }
          ++v2;
          ++v3;
        }
      while (dword_118069C > v2);
    }
  return result;
}

void __cdecl RB_InitImages()
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetRenderTarget(enum GfxRenderTargetId newTargetId)
{
  int result; // eax
  bool v2;    // dl
  int v3;     // edi
  _DWORD *v4; // ebx
  int *v5;    // ebx
  __int32 v6; // esi
  int v7;     // [esp+1Ch] [ebp-1Ch]

  result = dword_1186C98;
  if (dword_1186C98 == a1)
    return result;
  v2 = a1 == R_RENDERTARGET_SHADOWCOOKIE && dword_1186C98 == 3;
  g_InhibitCopy = v2;
  dword_1186C98 = a1;
  v7 = dx[5 * a1 + 2828];
    if (v7 && dword_118069C > 0) {
      v3 = 0;
      v4 = &dxState;
        do {
          if (v7 == v4[2109])
            RB_SetSampler(v3, 0, 0);
          ++v3;
          ++v4;
        }
      while (v3 < dword_118069C);
    }
    do {
      v5 = &dx[5 * a1];
      (*(void(__cdecl **)(int, _DWORD, int))(*(_DWORD *)dword_117D8A8 + 148))(
          dword_117D8A8, 0, v5[2829]);
    }
  while (alwaysfails);
  dword_1186CA8 = v5[2829];
    if (a1) {
        if (a1 != R_RENDERTARGET_SHADOWCOOKIE &&
            a1 != R_RENDERTARGET_BLURRED_SCREEN) {
            if (a1 == R_RENDERTARGET_DYNAMICSHADOWS) {
              glDrawBuffer(0x40Au);
              glReadBuffer(0x40Au);
              goto LABEL_18;
            }
          if (a1 != R_RENDERTARGET_GLOW_0 && a1 != R_RENDERTARGET_PINGPONG_0 &&
              a1 != R_RENDERTARGET_PINGPONG_1)
            goto LABEL_18;
        }
      glDrawBuffer(0x409u);
      glReadBuffer(0x409u);
    }
    else {
      glDrawBuffer(0x405u);
      glReadBuffer(0x405u);
    }
LABEL_18:
  g_RenderToShadowCookie = a1 == R_RENDERTARGET_SHADOWCOOKIE;
  dword_1186CA4 = s_viewportBehaviorForRenderTarget[dword_1186C98];
  v6 = 5 * a1;
  qword_1186C9C = *(_QWORD *)&dx[5 * a1 + 2831];
  *(_QWORD *)&xmmword_1186CB0 = 0;
  *((_QWORD *)&xmmword_1186CB0 + 1) = qword_1186C9C;
  dword_1186CC0 = 0;
  dword_1186CC4 = 1065353216;
    if (dword_1186CAC != dx[5 * a1 + 2830]) {
      do
        (*(void(__cdecl **)(int, int))(*(_DWORD *)dword_117D8A8 + 156))(
            dword_117D8A8, dx[v6 + 2830]);
      while (alwaysfails);
      dword_1186CAC = dx[v6 + 2830];
    }
  return RB_UpdateViewportConstants();
}

void __cdecl RB_SetInitialState()
{
  UNIMPLEMENTED();
}

int marker_rb_state;
struct DxState dxState;

enum GfxViewportBehavior __cdecl RB_ViewportBehaviorForRenderTarget(
    enum GfxRenderTargetId)
{
  UNIMPLEMENTED();
}

void __cdecl RB_InitMatricesFromView(struct GfxViewParms const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_ChangedProjectionMatrix(void)
{
  UNIMPLEMENTED();
}

void __cdecl RB_DecomposeSamplerFilter(unsigned char,
                                       enum _D3DTEXTUREFILTERTYPE *,
                                       enum _D3DTEXTUREFILTERTYPE *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetDefaultStateBits_Common(int *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_InitMatricesFromViewForTile(struct GfxViewParms const *)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetDefaultStateBits_Ref(int *const)
{
  UNIMPLEMENTED();
}

void __cdecl RB_SetDefaultStateBits_Active(int *const)
{
  UNIMPLEMENTED();
}

RB_SetAlphaAntiAliasingState(int stateBits0)
{
  UNIMPLEMENTED();
}

RB_ChangeAlphaStageState(int stageIndex, int texStageBits)
{
  UNIMPLEMENTED();
}

RB_ChangeColorStageState(int stageIndex, int texStageBits)
{
  UNIMPLEMENTED();
}

RB_SetSamplerConstantDx7(unsigned int color)
{
  UNIMPLEMENTED();
}

RB_ChangeGenTexCoords(int samplerIndex, unsigned char genTexCoords)
{
  UNIMPLEMENTED();
}

RB_SetViewMatrixForWDx7(float w)
{
  UNIMPLEMENTED();
}
