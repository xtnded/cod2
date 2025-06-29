unsigned char *__cdecl CM_ClusterPVS(int cluster)
{
  if (a1 < 0)
    return unk_1007EAC;
  if (a1 < unk_1007EA4 && unk_1007EB0)
    return unk_1007EAC + unk_1007EA8 * a1;
  return unk_1007EAC;
}

void __cdecl CM_StoreLeafs(struct leafList_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl CM_BoxLeafnums_r(struct leafList_s *ll, int nodenum)
{
  int v2;         // edx
  int v3;         // ebx
  int v4;         // eax
  int32_t v5;     // ecx
  int result;     // eax
  uint32_t count; // edx

  v2 = a2;
    while (v2 >= 0) {
      v3 = unk_1007E40 + 8 * v2;
      v4 = BoxOnPlaneSide(a1->bounds[0], a1->bounds[1], *(_DWORD *)v3);
        if (v4 == 1) {
          v2 = *(__int16 *)(v3 + 4);
        }
        else {
          if (v4 != 2)
            CM_BoxLeafnums_r(a1, *(__int16 *)(v3 + 4));
          v2 = *(__int16 *)(v3 + 6);
        }
    }
  v5 = ~v2;
  result = 11 * ~v2;
  if (*(_WORD *)(dword_1007E48 + 44 * ~v2 + 40) != 0xFFFF)
    a1->lastLeaf = v5;
  count = a1->count;
    if ((signed int)a1->count < (signed int)a1->maxcount) {
      *(_DWORD *)(a1->list + 4 * count) = v5;
      result = count + 1;
      a1->count = count + 1;
    }
    else {
      a1->overflowed = 1;
    }
  return result;
}

int __cdecl CM_PointLeafnum_r(float const *const, int)
{
  UNIMPLEMENTED();
}

int __cdecl CM_PointContents(float const *const p, int model)
{
  int v2;                 // eax
  __int16 *v3;            // ecx
  float *v4;              // edx
  unsigned __int8 v5;     // al
  int v6;                 // eax
  int v7;                 // ecx
  int i;                  // edx
  float v9;               // xmm1_4
  cLeafBrushNode_s *v10;  // ebx
  __int16 leafBrushCount; // ax
  int v12;                // edi
  int32_t v13;            // edx
  float *v14;             // edx
  float *v15;             // eax
  int v16;                // ecx
  float v17;              // xmm1_4
  float **v18;            // ecx
  float **v19;            // ecx
  int v20;                // ebx
  float *v21;             // eax
  int v23;                // [esp+1Ch] [ebp-2Ch]
  int32_t brushes;        // [esp+20h] [ebp-28h]
  int v25;                // [esp+28h] [ebp-20h]
  int v26;                // [esp+2Ch] [ebp-1Ch]

    if (!a2) {
      v2 = 0;
        while (1) {
          v3 = (__int16 *)(unk_1007E40 + 8 * v2);
          v4 = *(float **)v3;
          v5 = *(_BYTE *)(*(_DWORD *)v3 + 16);
            if (v5 <= 2u) {
              if ((float)(a1[v5] - v4[3]) >= 0.0)
                goto LABEL_4;
            LABEL_7:
              v2 = v3[3];
                if (v2 < 0) {
                LABEL_8:
                  v6 = dword_1007E48 + 44 * ~v2;
                  goto LABEL_9;
                }
            }
            else {
              if ((float)((float)((float)((float)(*v4 * *a1) +
                                          (float)(v4[1] * a1[1])) +
                                  (float)(v4[2] * a1[2])) -
                          v4[3]) < 0.0)
                goto LABEL_7;
            LABEL_4:
              v2 = v3[2];
              if (v2 < 0)
                goto LABEL_8;
            }
        }
    }
  v6 = CM_ClipHandleToModel(a2) + 28;
LABEL_9:
  v7 = *(_DWORD *)(v6 + 36);
  if (!v7)
    return 0;
    for (i = 1; i != 4; ++i) {
      v9 = a1[i - 1];
      if (*(float *)(v6 + 12) >= v9 || v9 >= *(float *)(v6 + 24))
        return 0;
      v6 += 4;
    }
  v10 = (cLeafBrushNode_s *)(unk_1007E50 + 20 * v7);
  v26 = 0;
    while (1) {
      leafBrushCount = v10->leafBrushCount;
      if (leafBrushCount)
        break;
    LABEL_16:
      v10 += *(unsigned __int16 *)((char *)&v10->data.children.childOffset +
                                   (*(float *)&v10->data.leaf.brushes >=
                                            a1[(unsigned __int8)v10->axis]
                                        ? 2
                                        : 0));
    }
    if (leafBrushCount <= 0) {
      v26 |= CM_PointContentsLeafBrushNode_r(a1, v10 + 1);
      goto LABEL_16;
    }
  v23 = leafBrushCount;
  brushes = v10->data.leaf.brushes;
  v12 = 0;
  v13 = brushes;
    while (2) {
      v14 = (float *)(48 * *(unsigned __int16 *)(v13 + 2 * v12) + unk_1007EA0);
      v15 = v14;
      v16 = 1;
        while (1) {
          v17 = a1[v16 - 1];
          if (*v15 > v17 || v17 > v15[4])
            break;
          ++v16;
          ++v15;
            if (v16 == 4) {
              v18 = (float **)*((_DWORD *)v14 + 8);
              v25 = *((_DWORD *)v14 + 7);
                if (v25) {
                  if ((float)((float)((float)(a1[1] * (*v18)[1]) +
                                      (float)(*a1 * **v18)) +
                              (float)(a1[2] * (*v18)[2])) > (*v18)[3])
                    break;
                  v19 = v18 + 2;
                  v20 = 0;
                    while (v20 != v25 - 1) {
                      v21 = *v19;
                      ++v20;
                      v19 += 2;
                      if ((float)((float)((float)(*a1 * *v21) +
                                          (float)(a1[1] * v21[1])) +
                                  (float)(a1[2] * v21[2])) > v21[3])
                        goto LABEL_30;
                    }
                }
              v26 |= *((_DWORD *)v14 + 3);
              break;
            }
        }
    LABEL_30:
        if (v23 != ++v12) {
          v13 = brushes;
          continue;
        }
      return v26;
    }
}

int __cdecl CM_BoxLeafnums(float const *const mins, float const *const maxs,
                           int *list, int listsize, int *lastLeaf)
{
  leafList_s v6; // [esp+14h] [ebp-34h] BYREF

  v6.bounds[0][0] = *a1;
  *(_QWORD *)&v6.bounds[0][1] = *(_QWORD *)(a1 + 1);
  *(_QWORD *)&v6.bounds[1][0] = *(_QWORD *)a2;
  v6.bounds[1][2] = a2[2];
  v6.count = 0;
  v6.maxcount = a4;
  v6.list = (int32_t)a3;
  v6.lastLeaf = 0;
  v6.overflowed = 0;
  CM_BoxLeafnums_r(&v6, 0);
  *a5 = v6.lastLeaf;
  return v6.count;
}

int __cdecl CM_PointLeafnum(float const *const p)
{
  int i;              // eax
  __int16 *v2;        // ecx
  float *v3;          // edx
  unsigned __int8 v4; // al

    for (i = 0; i >= 0; i = v2[3]) {
        while (1) {
          v2 = (__int16 *)(unk_1007E40 + 8 * i);
          v3 = *(float **)v2;
          v4 = *(_BYTE *)(*(_DWORD *)v2 + 16);
          if (v4 > 2u)
            break;
          if ((float)(a1[v4] - v3[3]) < 0.0)
            goto LABEL_6;
        LABEL_3:
          i = v2[2];
          if (i < 0)
            return ~i;
        }
      if ((float)((float)((float)((float)(*v3 * *a1) + (float)(v3[1] * a1[1])) +
                          (float)(v3[2] * a1[2])) -
                  v3[3]) >= 0.0)
        goto LABEL_3;
    LABEL_6:;
    }
  return ~i;
}

int __cdecl CM_TransformedPointContents(float const *const p, int model,
                                        float const *const origin,
                                        float const *const angles)
{
  float v4;    // xmm2_4
  float v5;    // xmm3_4
  float v7[3]; // [esp+10h] [ebp-38h] BYREF
  float v8[3]; // [esp+1Ch] [ebp-2Ch] BYREF
  float v9[3]; // [esp+28h] [ebp-20h] BYREF
  float v10;   // [esp+34h] [ebp-14h] BYREF
  float v11;   // [esp+38h] [ebp-10h]
  float v12;   // [esp+3Ch] [ebp-Ch]

  v10 = *a1 - *a3;
  v11 = a1[1] - a3[1];
  v12 = a1[2] - a3[2];
    if (*a4 != 0.0 || a4[1] != 0.0 || a4[2] != 0.0) {
      AngleVectors(a4, v9, v8, v7);
      v4 = v10;
      v5 = v11;
      v10 = (float)((float)(v10 * v9[0]) + (float)(v11 * v9[1])) +
            (float)(v12 * v9[2]);
      v11 = -(float)((float)((float)(v4 * v8[0]) + (float)(v11 * v8[1])) +
                     (float)(v12 * v8[2]));
      v12 = (float)((float)(v4 * v7[0]) + (float)(v5 * v7[1])) +
            (float)(v12 * v7[2]);
    }
  return CM_PointContents(&v10, a2);
}

int marker_cm_test;

int __cdecl CM_PointContentsLeafBrushNode_r(float const *const,
                                            struct cLeafBrushNode_s *)
{
  UNIMPLEMENTED();
}
