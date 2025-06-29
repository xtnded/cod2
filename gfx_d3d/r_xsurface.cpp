void __cdecl LocalMatrixTransformVector43(float const *const,
                                          struct DObjSkelMat_s const *,
                                          float *const)
{
  UNIMPLEMENTED();
}

void __cdecl LocalMatrixTransformVector(float const *const,
                                        struct DObjSkelMat_s const *,
                                        float *const)
{
  UNIMPLEMENTED();
}

int __cdecl XSurfaceGetBoneOffset(struct XSurface_s const *surf)
{
  return (__int16)a1->boneOffset;
}

struct XVertexInfo_s *__cdecl XSurfaceGetVertexInfoArray(
    struct XSurface_s const *surf)
{
  return a1->verts;
}

void __cdecl XSurfaceGetTris(struct XSurface_s const *surface,
                             unsigned short *dstIndices, unsigned short offset)
{
  int v3;               // ebx
  unsigned __int16 *v4; // ecx
  _DWORD *triIndices;   // edx
  int v6;               // edi
  int v7;               // esi
  void *result;         // eax

  if (!a3)
    return memcpy(__dst, (const void *)a1->triIndices,
                  6 * (__int16)a1->triCount);
  v3 = a3 | (a3 << 16);
  v4 = __dst;
  triIndices = (_DWORD *)a1->triIndices;
  v6 = (__int16)a1->triCount >> 1;
  v7 = 0;
    do {
      *(_DWORD *)v4 = *triIndices + v3;
      *((_DWORD *)v4 + 1) = triIndices[1] + v3;
      result = (void *)(triIndices[2] + v3);
      *((_DWORD *)v4 + 2) = result;
      v4 += 6;
      triIndices += 3;
      ++v7;
    }
  while (v7 != v6);
  return result;
}

int __cdecl XSurfaceGetNumTris(struct XSurface_s const *)
{
  return (__int16)a1->triCount;
}

int __cdecl XSurfaceGetNumVerts(struct XSurface_s const *surface)
{
  return (__int16)a1->vertCount;
}

void __cdecl XSurfaceTransfer(struct XVertexBuffer const *surfVerts,
                              struct GfxVertex *verts, int vertCount)
{
  int result; // eax
  int i;      // edi

  result = a3;
    if (a3 > 0) {
        for (i = 0; i != a3; ++i) {
          *(float *)a2->xyzw = a1->v.offset[0];
          *(float *)&a2->xyzw[4] = a1->v.offset[1];
          *(float *)&a2->xyzw[8] = a1->v.offset[2];
          *(_DWORD *)&a2->xyzw[12] = 1065353216;
          a2->normal[0] = a1->v.normal[0];
          a2->normal[1] = a1->v.normal[1];
          a2->normal[2] = a1->v.normal[2];
          a2->color = a1->v.color;
          LODWORD(a2->texCoord[0]) = a1->v.texCoordX;
          LODWORD(a2->texCoord[1]) = a1->v.texCoordY;
          a2->binormal[0] = a1->v.binormal[0];
          a2->binormal[1] = a1->v.binormal[1];
          a2->binormal[2] = a1->v.binormal[2];
          a2->tangent[0] = a1->v.tangent[0];
          a2->tangent[1] = a1->v.tangent[1];
          result = LODWORD(a1->v.tangent[2]);
          LODWORD(a2->tangent[2]) = result;
          a1 = (const XVertexBuffer *)((char *)a1 + 64);
          ++a2;
        }
    }
  return result;
}

void __cdecl XSurfaceGetVerts(struct XSurface_s const *surf,
                              struct DObjSkelMat_s *boneMatrix, float *pVert,
                              float *pTexCoord, float *pNormal)
{
  float *v5;                 // esi
  int32_t verts;             // edx
  float *v8;                 // ecx
  signed __int16 boneOffset; // ax
  float *v10;                // edx
  float *result;             // eax
  int v12;                   // ebx
  float *v13;                // esi
  float *v14;                // eax
  float *v15;                // eax
  float v16;                 // xmm0_4
  int32_t v17;               // ecx
  int v18;                   // ebx
  float *v19;                // edx
  float v20;                 // xmm2_4
  int v21;                   // [esp+0h] [ebp-28h]
  int v22;                   // [esp+4h] [ebp-24h]
  int v23;                   // [esp+8h] [ebp-20h]
  int v24;                   // [esp+18h] [ebp-10h]

  v5 = a3;
  verts = a1->verts;
  v8 = (float *)verts;
  boneOffset = a1->boneOffset;
    if (boneOffset == -1) {
      result = (float *)a1->vertCount;
      v21 = (__int16)result;
        if ((_WORD)result) {
          v13 = a3 + 3;
          v23 = 0;
            do {
                if (a5) {
                  v14 = (float *)((char *)a2 + *(__int16 *)(verts + 62));
                  *a5 = (float)((float)(*(float *)verts * *v14) +
                                (float)(*(float *)(verts + 4) * v14[4])) +
                        (float)(*(float *)(verts + 8) * v14[8]);
                  a5[1] = (float)((float)(*(float *)verts * v14[1]) +
                                  (float)(*(float *)(verts + 4) * v14[5])) +
                          (float)(*(float *)(verts + 8) * v14[9]);
                  a5[2] = (float)((float)(*(float *)verts * v14[2]) +
                                  (float)(*(float *)(verts + 4) * v14[6])) +
                          (float)(*(float *)(verts + 8) * v14[10]);
                  a5 += 3;
                }
              v15 = (float *)((char *)a2 + *(__int16 *)(verts + 62));
              *(v13 - 3) =
                  (float)((float)((float)(*(float *)(verts + 48) * *v15) +
                                  (float)(*(float *)(verts + 52) * v15[4])) +
                          (float)(*(float *)(verts + 56) * v15[8])) +
                  v15[12];
              *(v13 - 2) =
                  (float)((float)((float)(*(float *)(verts + 48) * v15[1]) +
                                  (float)(*(float *)(verts + 52) * v15[5])) +
                          (float)(*(float *)(verts + 56) * v15[9])) +
                  v15[13];
              *(v13 - 1) =
                  (float)((float)((float)(*(float *)(verts + 48) * v15[2]) +
                                  (float)(*(float *)(verts + 52) * v15[6])) +
                          (float)(*(float *)(verts + 56) * v15[10])) +
                  v15[14];
              result = (float *)*(unsigned __int8 *)(verts + 60);
              v22 = (unsigned __int8)result;
                if ((_BYTE)result) {
                  v16 = (float)*(unsigned __int8 *)(verts + 61) * 0.00390625;
                  *(v13 - 3) = v16 * *(v13 - 3);
                  *(v13 - 2) = v16 * *(v13 - 2);
                  *(v13 - 1) = v16 * *(v13 - 1);
                  v17 = verts + 64;
                  v18 = 0;
                    do {
                      v19 = (float *)((char *)a2 + *(__int16 *)(v17 + 12));
                      v20 = (float)*(unsigned __int16 *)(v17 + 14) *
                            0.000015258789;
                      *(v13 - 3) =
                          (float)((float)((float)((float)((float)(*(float *)
                                                                      v17 *
                                                                  *v19) +
                                                          (float)(*(float
                                                                        *)(v17 +
                                                                           4) *
                                                                  v19[4])) +
                                                  (float)(*(float *)(v17 + 8) *
                                                          v19[8])) +
                                          v19[12]) *
                                  v20) +
                          *(v13 - 3);
                      *(v13 - 2) =
                          (float)((float)((float)((float)((float)(*(float *)
                                                                      v17 *
                                                                  v19[1]) +
                                                          (float)(*(float
                                                                        *)(v17 +
                                                                           4) *
                                                                  v19[5])) +
                                                  (float)(*(float *)(v17 + 8) *
                                                          v19[9])) +
                                          v19[13]) *
                                  v20) +
                          *(v13 - 2);
                      result = v13 - 1;
                      *(v13 - 1) =
                          (float)((float)((float)((float)((float)(*(float *)
                                                                      v17 *
                                                                  v19[2]) +
                                                          (float)(*(float
                                                                        *)(v17 +
                                                                           4) *
                                                                  v19[6])) +
                                                  (float)(*(float *)(v17 + 8) *
                                                          v19[10])) +
                                          v19[14]) *
                                  v20) +
                          *(v13 - 1);
                      v17 += 16;
                      ++v18;
                    }
                  while (v18 != v22);
                  verts = v17;
                }
                else {
                  verts += 64;
                }
              ++v23;
              v13 += 3;
            }
          while (v21 != v23);
        }
    }
    else {
      v10 = (float *)((char *)a2 + boneOffset);
      result = (float *)a1->vertCount;
      v24 = (__int16)result;
        if ((_WORD)result) {
          v12 = 0;
            do {
                if (a5) {
                  *a5 = (float)((float)(*v8 * *v10) + (float)(v8[1] * v10[4])) +
                        (float)(v8[2] * v10[8]);
                  a5[1] =
                      (float)((float)(*v8 * v10[1]) + (float)(v8[1] * v10[5])) +
                      (float)(v8[2] * v10[9]);
                  a5[2] =
                      (float)((float)(*v8 * v10[2]) + (float)(v8[1] * v10[6])) +
                      (float)(v8[2] * v10[10]);
                  a5 += 3;
                }
              result = a4;
                if (a4) {
                  *a4 = v8[7];
                  a4[1] = v8[11];
                  result = a4 + 2;
                  a4 += 2;
                }
              *v5 = (float)((float)((float)(v8[12] * *v10) +
                                    (float)(v8[13] * v10[4])) +
                            (float)(v8[14] * v10[8])) +
                    v10[12];
              v5[1] = (float)((float)((float)(v8[12] * v10[1]) +
                                      (float)(v8[13] * v10[5])) +
                              (float)(v8[14] * v10[9])) +
                      v10[13];
              v5[2] = (float)((float)((float)(v8[12] * v10[2]) +
                                      (float)(v8[13] * v10[6])) +
                              (float)(v8[14] * v10[10])) +
                      v10[14];
              v8 += 16;
              v5 += 3;
              ++v12;
            }
          while (v24 != v12);
        }
    }
  return result;
}

int marker_r_xsurface;

XSurfaceTransferDx7(XVertexBuffer const *surfVerts, GfxVertexDx7 *verts,
                    int vertCount)
{
  UNIMPLEMENTED();
}
