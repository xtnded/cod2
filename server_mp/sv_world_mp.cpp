int __cdecl SV_ClipHandleForEntity(struct gentity_s const *ent)
{
  if (a1->r.bmodel)
    return a1->s.index.item;
  else
    return CM_TempBoxModel(a1->r.mins, a1->r.maxs, a1->r.contents);
}

int __cdecl SV_PointContents(float const *const p, int passEntityNum,
                             int contentmask)
{
  int v3;        // edi
  int i;         // esi
  int v5;        // edx
  int v6;        // eax
  int v7;        // ebx
  int v9;        // [esp+2Ch] [ebp-101Ch]
  int v10[1030]; // [esp+30h] [ebp-1018h] BYREF

  v3 = CM_PointContents(a1, 0);
  v9 = CM_AreaEntities(a1, a1, v10, 1024, a3);
    if (v9 > 0) {
        for (i = 0; i != v9; ++i) {
            if (v10[i] != a2) {
              v6 = SV_GentityNum(v10[i]);
              v7 = v6;
              if (*(_BYTE *)(v6 + 241))
                v5 = *(_DWORD *)(v6 + 140);
              else
                v5 = CM_TempBoxModel((float *)(v6 + 260),
                                     (const float *)(v6 + 272),
                                     *(_DWORD *)(v6 + 284));
              v3 |= CM_TransformedPointContents(
                  a1, v5, (const float *)(v7 + 312), (float *)(v7 + 324));
            }
        }
    }
  return v3 & a3;
}

void __cdecl SV_ClipMoveToEntity(struct moveclip_t const *clip,
                                 struct svEntity_s *check,
                                 struct trace_t *trace)
{
  int v3;                 // ebx
  uint32_t passEntityNum; // eax
  int v5;                 // edx
  float *v6;              // edx
  float *v7;              // eax
  float fraction;         // [esp+3Ch] [ebp-3Ch]
  float v9[3];            // [esp+48h] [ebp-30h] BYREF
  float v10[9];           // [esp+54h] [ebp-24h] BYREF

  v3 = SV_GentityNum(1062196213 * (((char *)a2 - (char *)&unk_16A3318) >> 2));
    if ((a1->contentmask & *(_DWORD *)(v3 + 284)) != 0) {
      passEntityNum = a1->passEntityNum;
        if (passEntityNum == 1023 ||
            1062196213 * (((char *)a2 - (char *)&unk_16A3318) >> 2) !=
                    passEntityNum &&
                (v5 = *(_DWORD *)(v3 + 336), passEntityNum != v5) &&
                v5 != a1->passOwnerNum) {
          v10[0] = *(float *)(v3 + 288) + a1->mins[0];
          v10[1] = *(float *)(v3 + 292) + a1->mins[1];
          v10[2] = *(float *)(v3 + 296) + a1->mins[2];
          v9[0] = *(float *)(v3 + 300) + a1->maxs[0];
          v9[1] = *(float *)(v3 + 304) + a1->maxs[1];
          v9[2] = *(float *)(v3 + 308) + a1->maxs[2];
            if (!CM_TraceBox((const TraceExtents *)a1->extents, v10, v9,
                             LODWORD(a3->fraction))) {
              if (*(_BYTE *)(v3 + 241))
                v6 = *(float **)(v3 + 140);
              else
                v6 = (float *)CM_TempBoxModel((float *)(v3 + 260),
                                              (const float *)(v3 + 272),
                                              *(_DWORD *)(v3 + 284));
              v7 = (float *)(v3 + 324);
              if (!*(_BYTE *)(v3 + 241))
                v7 = vec3_origin;
              fraction = a3->fraction;
              CM_TransformedBoxTrace(a3, (const float *)a1->extents,
                                     (const float *)&a1->extents[12], a1->mins,
                                     a1->maxs, v6, (float *)a1->contentmask,
                                     (const float *)(v3 + 312), v7);
              if (a3->fraction < fraction)
                a3->entityNum = *(_DWORD *)v3;
            }
        }
    }
}

int __cdecl SV_SightTraceToEntity(float const *const start,
                                  float const *const mins,
                                  float const *const maxs,
                                  float const *const end, int entityNum,
                                  int contentmask)
{
  int v6;        // ebx
  int i;         // edx
  float v8;      // xmm1_4
  float v9;      // xmm0_4
  int v10;       // eax
  float *v11;    // edx
  _DWORD v13[3]; // [esp+34h] [ebp-34h]
  float v14[10]; // [esp+40h] [ebp-28h]

  v6 = SV_GentityNum(a5);
  if ((a6 & *(_DWORD *)(v6 + 284)) == 0)
    return 0;
    for (i = 1; i != 4; ++i) {
      v8 = a4[i - 1];
      v9 = a1[i - 1];
        if (v8 <= v9) {
          v14[i] = (float)(v8 + a2[i - 1]) - 1.0;
          *(float *)&v13[i] = (float)(v9 + a3[i - 1]) + 1.0;
        }
        else {
          v14[i] = (float)(v9 + a2[i - 1]) - 1.0;
          *(float *)&v13[i] = (float)(v8 + a3[i - 1]) + 1.0;
        }
    }
    if (*(float *)(v6 + 288) > *(float *)&v13[1] ||
        *(float *)(v6 + 292) > *(float *)&v13[2] ||
        *(float *)(v6 + 296) > v14[0] || v14[1] > *(float *)(v6 + 300) ||
        v14[2] > *(float *)(v6 + 304) || v14[3] > *(float *)(v6 + 308)) {
      return 0;
    }
  v10 = *(_BYTE *)(v6 + 241)
            ? *(_DWORD *)(v6 + 140)
            : CM_TempBoxModel((float *)(v6 + 260), (const float *)(v6 + 272),
                              *(_DWORD *)(v6 + 284));
  v11 = (float *)(v6 + 324);
  if (!*(_BYTE *)(v6 + 241))
    v11 = vec3_origin;
  if (CM_TransformedBoxSightTrace(0, a1, a4, a2, a3, v10, a6,
                                  (const float *)(v6 + 312), v11))
    return -1;
  else
    return 0;
}

int __cdecl SV_ClipSightToEntity(struct sightclip_t const *clip,
                                 struct svEntity_s *check)
{
  int v2;                 // esi
  int v3;                 // ebx
  int v4;                 // ecx
  uint32_t contentmask;   // edx
  int passEntityNum;      // eax
  int passEntityNum_high; // eax
  int v8;                 // ecx
  float *v9;              // eax

  v2 = 1062196213 * (((char *)a2 - (char *)&unk_16A3318) >> 2);
  v3 = SV_GentityNum(v2);
  v4 = *(_DWORD *)(v3 + 284);
  contentmask = a1->contentmask;
  if ((v4 & contentmask) == 0)
    return 0;
  passEntityNum = a1->passEntityNum;
  if (passEntityNum != 1023 &&
      (v2 == passEntityNum || passEntityNum == *(_DWORD *)(v3 + 336)))
    return 0;
  passEntityNum_high = HIDWORD(a1->passEntityNum);
  if (passEntityNum_high != 1023 &&
      (v2 == passEntityNum_high || passEntityNum_high == *(_DWORD *)(v3 + 336)))
    return 0;
    if (*(_BYTE *)(v3 + 241)) {
      v8 = *(_DWORD *)(v3 + 140);
    }
    else {
      v8 = CM_TempBoxModel((float *)(v3 + 260), (const float *)(v3 + 272), v4);
      contentmask = a1->contentmask;
    }
  v9 = (float *)(v3 + 324);
  if (!*(_BYTE *)(v3 + 241))
    v9 = vec3_origin;
    if (CM_TransformedBoxSightTrace(0, a1->start, a1->end, a1->mins, a1->maxs,
                                    v8, contentmask, (const float *)(v3 + 312),
                                    v9)) {
      return -1;
    }
    else {
      return 0;
    }
}

void __cdecl SV_LinkEntity(struct gentity_s *gEnt)
{
  int v1;               // esi
  float *v2;            // ebx
  float v3;             // xmm1_4
  float *maxs;          // esi
  gentity_s *v5;        // edx
  int v6;               // ecx
  float *v7;            // eax
  int32_t item;         // ebx
  DObj_s *ServerDObj;   // eax
  int8_t svFlags;       // dl
  int v12;              // edx
  int v13;              // eax
  int v14;              // ecx
  int v15;              // eax
  int v16;              // eax
  signed int v17;       // eax
  float v18;            // xmm2_4
  float v19;            // xmm1_4
  gentity_s *v20;       // edx
  int v21;              // ecx
  float *v22;           // eax
  int v23;              // ebx
  int v24;              // edx
  uint32_t numClusters; // eax
  float v26;            // xmm2_4
  float v27;            // xmm1_4
  float v28;            // [esp+2Ch] [ebp-25Ch]
  float v29;            // [esp+2Ch] [ebp-25Ch]
  float *mins;          // [esp+38h] [ebp-250h]
  float v31;            // [esp+3Ch] [ebp-24Ch]
  signed int v32;       // [esp+40h] [ebp-248h]
  float *currentOrigin; // [esp+44h] [ebp-244h]
  svEntity_s *v34;      // [esp+4Ch] [ebp-23Ch]
  int v35[128];         // [esp+54h] [ebp-234h] BYREF
  float v36;            // [esp+254h] [ebp-34h] BYREF
  float v37;            // [esp+258h] [ebp-30h]
  float v38;            // [esp+260h] [ebp-28h] BYREF
  float v39;            // [esp+264h] [ebp-24h]
  int v40[7];           // [esp+26Ch] [ebp-1Ch] BYREF

  v34 = (svEntity_s *)SV_SvEntityForGentity(a1);
    if (a1->r.bmodel) {
      a1->s.solid = (uint32_t)&unk_FFFFFF;
    }
    else if ((a1->r.contents & 0x2000001) != 0) {
      v12 = (int)a1->r.maxs[0];
        if (v12 <= 0) {
          v12 = 1;
        }
        else if (v12 >= 256) {
          v12 = 255;
        }
      v13 = (int)(float)(1.0 - a1->r.mins[2]);
        if (v13 <= 0) {
          v14 = 256;
        }
        else if (v13 <= 255) {
          v14 = v13 << 8;
        }
        else {
          v14 = 65280;
        }
      v15 = (int)(float)(a1->r.maxs[2] + 32.0);
        if (v15 <= 0) {
          v16 = 0x10000;
        }
        else if (v15 <= 255) {
          v16 = v15 << 16;
        }
        else {
          v16 = (int)&unk_FF0000;
        }
      a1->s.solid = v14 | v16 | v12;
    }
    else {
      a1->s.solid = 0;
    }
  currentOrigin = a1->r.currentOrigin;
  v1 = 1;
  v2 = &a1->r.currentAngles[1];
    do {
      v31 = floorf(*(v2 - 1) + 0.5);
      v3 = (float)(int)v31;
      if ((float)((float)(v3 - *(v2 - 1)) * (float)(v3 - *(v2 - 1))) <
          0.0000010000001)
        *(v2 - 1) = v3;
      ++v1;
      ++v2;
    }
  while (v1 != 4);
  if (!a1->r.bmodel)
    goto LABEL_14;
  if (a1->r.currentAngles[0] != 0.0)
    goto LABEL_9;
    if (a1->r.currentAngles[1] == 0.0) {
        if (a1->r.currentAngles[2] == 0.0) {
        LABEL_14:
          mins = a1->r.mins;
          a1->r.absmin[0] = *currentOrigin + a1->r.mins[0];
          a1->r.absmin[1] = a1->r.currentOrigin[1] + a1->r.mins[1];
          a1->r.absmin[2] = a1->r.currentOrigin[2] + a1->r.mins[2];
          maxs = a1->r.maxs;
          a1->r.absmax[0] = *currentOrigin + a1->r.maxs[0];
          a1->r.absmax[1] = a1->r.currentOrigin[1] + a1->r.maxs[1];
          a1->r.absmax[2] = a1->r.currentOrigin[2] + a1->r.maxs[2];
          goto LABEL_15;
        }
    LABEL_9:
      maxs = a1->r.maxs;
      mins = a1->r.mins;
      v28 = RadiusFromBounds(a1->r.mins, a1->r.maxs);
      v5 = a1;
      v6 = 1;
      v7 = &a1->r.currentOrigin[1];
        do {
          v5->r.absmin[0] = *(v7 - 1) - v28;
          v5->r.absmax[0] = v28 + *(v7 - 1);
          ++v6;
          ++v7;
          v5 = (gentity_s *)((char *)v5 + 4);
        }
      while (v6 != 4);
      goto LABEL_15;
    }
  if (a1->r.currentAngles[2] != 0.0)
    goto LABEL_9;
  maxs = a1->r.maxs;
  mins = a1->r.mins;
  v29 = RadiusFromBounds2D(a1->r.mins, a1->r.maxs);
  v20 = a1;
  v21 = 1;
  v22 = &a1->r.currentOrigin[1];
    do {
      v20->r.absmin[0] = *(v22 - 1) - v29;
      v20->r.absmax[0] = v29 + *(v22 - 1);
      ++v21;
      ++v22;
      v20 = (gentity_s *)((char *)v20 + 4);
    }
  while (v21 != 3);
  a1->r.absmin[2] = a1->r.currentOrigin[2] + a1->r.mins[2];
  a1->r.absmax[2] = a1->r.currentOrigin[2] + a1->r.maxs[2];
LABEL_15:
  a1->r.absmin[0] = a1->r.absmin[0] - 1.0;
  a1->r.absmin[1] = a1->r.absmin[1] - 1.0;
  a1->r.absmin[2] = a1->r.absmin[2] - 1.0;
  a1->r.absmax[0] = a1->r.absmax[0] + 1.0;
  a1->r.absmax[1] = a1->r.absmax[1] + 1.0;
  a1->r.absmax[2] = a1->r.absmax[2] + 1.0;
  v34->numClusters = 0;
  v34->lastCluster = 0;
    if ((a1->r.svFlags & 0x19) == 0) {
      v17 = CM_BoxLeafnums(a1->r.absmin, a1->r.absmax, v35, 0x80u, v40);
      v32 = v17;
        if (v17) {
            if (v17 > 0) {
              v23 = 0;
                while (1) {
                  v24 = CM_LeafCluster(v35[v23]);
                    if (v24 != -1) {
                      numClusters = v34->numClusters;
                      *(_DWORD *)&v34->clusternums[4 * numClusters++] = v24;
                      v34->numClusters = numClusters;
                      if (numClusters == 16)
                        break;
                    }
                  if (++v23 == v32)
                    goto LABEL_16;
                }
            }
          v34->lastCluster = CM_LeafCluster(v40[0]);
          a1->r.linked = 1;
          if (a1->r.contents)
            goto LABEL_17;
        }
      return CM_UnlinkEntity(v34);
    }
LABEL_16:
  a1->r.linked = 1;
  if (!a1->r.contents)
    return CM_UnlinkEntity(v34);
LABEL_17:
  if (a1->r.bmodel)
    item = a1->s.index.item;
  else
    item = CM_TempBoxModel(mins, maxs, a1->r.contents);
  ServerDObj = Com_GetServerDObj(a1->s.number);
  if (!ServerDObj)
    return (svEntity_s *)CM_LinkEntity(v34, a1->r.absmin, a1->r.absmax, item);
  svFlags = a1->r.svFlags;
  if ((svFlags & 6) == 0)
    return (svEntity_s *)CM_LinkEntity(v34, a1->r.absmin, a1->r.absmax, item);
    if ((svFlags & 2) != 0) {
      v18 = *currentOrigin;
      v38 = *currentOrigin + *(float *)&actorLocationalMins;
      v19 = a1->r.currentOrigin[1];
      v39 = v19 + *(float *)&dword_314550;
      v36 = v18 + *(float *)&actorLocationalMaxs;
      v37 = v19 + *(float *)&dword_314544;
    }
    else {
      DObjGetBounds(ServerDObj, &v38, &v36);
      v26 = *currentOrigin;
      v38 = *currentOrigin + v38;
      v27 = a1->r.currentOrigin[1];
      v39 = v27 + v39;
      v36 = v26 + v36;
      v37 = v27 + v37;
    }
  return (svEntity_s *)CM_LinkEntity(v34, &v38, &v36, item);
}

void __cdecl SV_UnlinkEntity(struct gentity_s *)
{
  char *v1; // eax

  v1 = SV_SvEntityForGentity(a1);
  a1->r.linked = 0;
  return CM_UnlinkEntity((svEntity_s *)v1);
}

int __cdecl SV_PointSightTraceToEntity(struct sightpointtrace_t const *clip,
                                       struct svEntity_s *check)
{
  int v2;                 // ebx
  gentity_s *v3;          // edi
  int passEntityNum;      // eax
  int passEntityNum_high; // eax
  int item;               // ecx
  float *currentAngles;   // eax
  DObj_s *ServerDObj;     // [esp+3Ch] [ebp-BCh]
  float v10[9];           // [esp+44h] [ebp-B4h] BYREF
  float v11;              // [esp+68h] [ebp-90h]
  float v12;              // [esp+6Ch] [ebp-8Ch]
  float v13;              // [esp+70h] [ebp-88h]
  TraceExtents v14;       // [esp+74h] [ebp-84h] BYREF
  DObjTrace_s v15;        // [esp+98h] [ebp-60h] BYREF
  float v16[3];           // [esp+B0h] [ebp-48h] BYREF
  float v17;              // [esp+BCh] [ebp-3Ch] BYREF
  float v18;              // [esp+C0h] [ebp-38h]
  float v19;              // [esp+C4h] [ebp-34h]
  float v20;              // [esp+C8h] [ebp-30h] BYREF
  float v21;              // [esp+CCh] [ebp-2Ch]
  float v22;              // [esp+D0h] [ebp-28h]
  float v23[9];           // [esp+D4h] [ebp-24h] BYREF

  v2 = 1062196213 * (((char *)a2 - (char *)&unk_16A3318) >> 2);
  v3 = (gentity_s *)SV_GentityNum(v2);
  if ((a1->contentmask & v3->r.contents) == 0)
    return 0;
  passEntityNum = a1->passEntityNum;
  if (passEntityNum != 1023 &&
      (v2 == passEntityNum || passEntityNum == v3->r.ownerNum))
    return 0;
  passEntityNum_high = HIDWORD(a1->passEntityNum);
  if (passEntityNum_high != 1023 &&
      (v2 == passEntityNum_high || passEntityNum_high == v3->r.ownerNum))
    return 0;
    if (!a1->locational ||
        (ServerDObj = Com_GetServerDObj(v3->s.number)) == 0 ||
        (v3->r.svFlags & 4) == 0) {
      if (v3->r.bmodel)
        item = v3->s.index.item;
      else
        item = CM_TempBoxModel(v3->r.mins, v3->r.maxs, v3->r.contents);
      currentAngles = v3->r.currentAngles;
      if (!v3->r.bmodel)
        currentAngles = vec3_origin;
        if (CM_TransformedBoxSightTrace(0, a1->start, a1->end, vec3_origin,
                                        vec3_origin, item, a1->contentmask,
                                        v3->r.currentOrigin, currentAngles)) {
          return -1;
        }
      return 0;
    }
  if (!DObjHasContents(ServerDObj, a1->contentmask))
    return 0;
  v11 = v3->r.currentOrigin[0];
  v12 = v3->r.currentOrigin[1];
  v13 = v3->r.currentOrigin[2];
  DObjGetBounds(ServerDObj, &v20, &v17);
  v20 = v11 + v20;
  v21 = v12 + v21;
  v22 = v13 + v22;
  v17 = v11 + v17;
  v18 = v12 + v18;
  v19 = v13 + v19;
  v14.start[0] = a1->start[0];
  v14.start[1] = a1->start[1];
  v14.start[2] = a1->start[2];
  v14.end[0] = a1->end[0];
  v14.end[1] = a1->end[1];
  v14.end[2] = a1->end[2];
  CM_CalcTraceEntents(&v14);
  if (CM_TraceBox(&v14, &v20, &v17, 0x3F800000u))
    return 0;
  G_DObjCalcPose(v3);
  AnglesToAxis(v3->r.currentAngles, v10);
  MatrixTransposeTransformVector43(v14.start, (const float(*)[3])v10, v23);
  MatrixTransposeTransformVector43(v14.end, (const float(*)[3])v10, v16);
  v15.fraction = 1.0;
  DObjGeomTraceline(ServerDObj, v23, v16, a1->contentmask, &v15);
  if (v15.fraction >= 1.0)
    return 0;
  return -1;
}

void __cdecl SV_PointTraceToEntity(struct pointtrace_t const *clip,
                                   struct svEntity_s *check,
                                   struct trace_t *trace)
{
  gentity_s *v3;        // esi
  uint32_t v4;          // ecx
  uint32_t v5;          // eax
  uint32_t ownerNum;    // edx
  float *v7;            // ecx
  float *currentAngles; // eax
  DObj_s *ServerDObj;   // ebx
  int8_t svFlags;       // al
  float fraction;       // [esp+3Ch] [ebp-9Ch]
  float v12[9];         // [esp+48h] [ebp-90h] BYREF
  float v13;            // [esp+6Ch] [ebp-6Ch]
  float v14;            // [esp+70h] [ebp-68h]
  float v15;            // [esp+74h] [ebp-64h]
  DObjTrace_s v16;      // [esp+78h] [ebp-60h] BYREF
  float v17[3];         // [esp+90h] [ebp-48h] BYREF
  float v18[3];         // [esp+9Ch] [ebp-3Ch] BYREF
  float v19;            // [esp+A8h] [ebp-30h] BYREF
  float v20;            // [esp+ACh] [ebp-2Ch]
  float v21;            // [esp+B0h] [ebp-28h]
  float v22;            // [esp+B4h] [ebp-24h] BYREF
  float v23;            // [esp+B8h] [ebp-20h]
  float v24;            // [esp+BCh] [ebp-1Ch]

  v3 = (gentity_s *)SV_GentityNum(1062196213 *
                                  (((char *)a2 - (char *)&unk_16A3318) >> 2));
  v4 = LODWORD(a1[1].start[2]);
  if ((v4 & v3->r.contents) == 0)
    return;
  v5 = LODWORD(a1[1].start[0]);
    if (v5 != 1023) {
      if (1062196213 * (((char *)a2 - (char *)&unk_16A3318) >> 2) == v5)
        return;
      ownerNum = v3->r.ownerNum;
      if (v5 == ownerNum || ownerNum == LODWORD(a1[1].start[1]))
        return;
    }
  if (!LODWORD(a1[1].end[0]))
    goto LABEL_7;
  ServerDObj = Com_GetServerDObj(v3->s.number);
  if (!ServerDObj)
    goto LABEL_27;
  svFlags = v3->r.svFlags;
  if ((svFlags & 6) == 0)
    goto LABEL_27;
    if ((svFlags & 4) != 0) {
      if (!DObjHasContents(ServerDObj, LODWORD(a1[1].start[2])))
        return;
      v13 = v3->r.currentOrigin[0];
      v14 = v3->r.currentOrigin[1];
      v15 = v3->r.currentOrigin[2];
      DObjGetBounds(ServerDObj, &v22, &v19);
      v22 = v13 + v22;
      v23 = v14 + v23;
      v24 = v15 + v24;
      v19 = v13 + v19;
      v20 = v14 + v20;
      v21 = v15 + v21;
      goto LABEL_22;
    }
    if (!LODWORD(a1[1].end[1])) {
    LABEL_27:
      v4 = LODWORD(a1[1].start[2]);
    LABEL_7:
        if ((v4 & a2->linkcontents) != 0 &&
            !CM_TraceBox(a1, v3->r.absmin, v3->r.absmax,
                         LODWORD(a3->fraction))) {
          v7 = (float *)(v3->r.bmodel ? v3->s.index.item
                                      : CM_TempBoxModel(v3->r.mins, v3->r.maxs,
                                                        v3->r.contents));
          currentAngles = v3->r.currentAngles;
          if (!v3->r.bmodel)
            currentAngles = vec3_origin;
          fraction = a3->fraction;
          CM_TransformedBoxTrace(a3, a1->start, a1->end, vec3_origin,
                                 vec3_origin, v7,
                                 (float *)LODWORD(a1[1].start[2]),
                                 v3->r.currentOrigin, currentAngles);
            if (a3->fraction < fraction) {
              a3->surfaceFlags = 0;
              *(_WORD *)a3->partName = 0;
              a3->partGroup = 0;
            LABEL_16:
              a3->entityNum = v3->s.number;
              a3->contents = v3->r.contents;
              a3->material = 0;
              return;
            }
        }
      return;
    }
  v13 = v3->r.currentOrigin[0];
  v14 = v3->r.currentOrigin[1];
  v15 = v3->r.currentOrigin[2];
  v22 = v13 + *(float *)&actorLocationalMins;
  v23 = v14 + *(float *)&dword_314550;
  v24 = v15 + *(float *)&dword_314554;
  v19 = v13 + *(float *)&actorLocationalMaxs;
  v20 = v14 + *(float *)&dword_314544;
  v21 = v15 + *(float *)&dword_314548;
LABEL_22:
    if (!CM_TraceBox(a1, &v22, &v19, LODWORD(a3->fraction))) {
      G_DObjCalcPose(v3);
      AnglesToAxis(v3->r.currentAngles, v12);
      MatrixTransposeTransformVector43(a1->start, (const float(*)[3])v12, v18);
      MatrixTransposeTransformVector43(a1->end, (const float(*)[3])v12, v17);
      v16.fraction = a3->fraction;
      if ((v3->r.svFlags & 4) != 0)
        DObjGeomTraceline(ServerDObj, v18, v17, LODWORD(a1[1].start[2]), &v16);
      else
        DObjTraceline(ServerDObj, v18, v17,
                      (unsigned __int8 *)LODWORD(a1[1].end[1]), &v16);
        if (v16.fraction < a3->fraction) {
          a3->fraction = v16.fraction;
          a3->surfaceFlags = v16.surfaceflags;
          *(_WORD *)a3->partName = *(_WORD *)v16.partName;
          a3->partGroup = v16.partGroup;
          MatrixTransformVector(v16.normal, v12, a3->normal);
          goto LABEL_16;
        }
    }
}

void __cdecl SV_LocationalTraceToEntity(struct trace_t *, float const *const,
                                        float const *const, int, int,
                                        unsigned char *)
{
  UNIMPLEMENTED();
}

void __cdecl SV_SightTrace(int *hitNum, float const *const start,
                           float const *const mins, float const *const maxs,
                           float const *const end, int passEntityNum0,
                           int passEntityNum1, int contentmask)
{
  int result;      // eax
  float *v8;       // edx
  float *v9;       // eax
  float *v10;      // ecx
  float v11;       // xmm7_4
  float v12;       // xmm5_4
  float v13;       // xmm6_4
  float v14;       // xmm3_4
  float v15;       // xmm4_4
  float v16;       // xmm1_4
  float v17;       // xmm5_4
  float v18;       // xmm6_4
  float *v19;      // [esp+2Ch] [ebp-6Ch]
  sightclip_t v20; // [esp+38h] [ebp-60h] BYREF

  result = CM_BoxSightTrace(*a1, a2, a5, a3, a4, 0, a7);
  *a1 = result;
    if (!result) {
      v8 = a4 + 1;
      v19 = a3 + 1;
      v9 = a4 + 2;
      v10 = a3 + 2;
      v11 = *a4;
        if ((float)((float)((float)((float)((float)(*a4 - *a3) + a4[1]) -
                                    a3[1]) +
                            a4[2]) -
                    a3[2]) == 0.0) {
          LODWORD(v20.outerSize[2]) = a7;
          v20.mins[0] = *a2;
          v20.mins[1] = a2[1];
          v20.mins[2] = a2[2];
          v20.maxs[0] = *a5;
          v20.maxs[1] = a5[1];
          v20.maxs[2] = a5[2];
          *(_QWORD *)v20.outerSize = a6;
          v20.start[0] = 0.0;
          result = CM_PointSightTraceToEntities((sightpointtrace_t *)&v20);
          *a1 = result;
        }
        else {
          v20.contentmask = a7;
          v20.passEntityNum = a6;
          v12 = *v8;
          v13 = *v9;
          v14 = (float)(*v8 - *v19) * 0.5;
          v15 = (float)(*v9 - *v10) * 0.5;
          v20.maxs[0] = (float)(v11 - *a3) * 0.5;
          v20.maxs[1] = v14;
          v20.maxs[2] = v15;
          LODWORD(v20.mins[0]) = LODWORD(v20.maxs[0]) ^ 0x80000000;
          LODWORD(v20.mins[1]) = LODWORD(v14) ^ 0x80000000;
          v20.mins[2] = -v15;
          v20.outerSize[0] = v20.maxs[0] + 1.0;
          v20.outerSize[1] = v14 + 1.0;
          v20.outerSize[2] = v15 + 1.0;
          v16 = (float)(v11 + *a3) * 0.5;
          v17 = (float)(v12 + *v19) * 0.5;
          v18 = (float)(v13 + *v10) * 0.5;
          v20.start[0] = v16 + *a2;
          v20.start[1] = v17 + a2[1];
          v20.start[2] = v18 + a2[2];
          v20.end[0] = v16 + *a5;
          v20.end[1] = v17 + a5[1];
          v20.end[2] = v18 + a5[2];
          result = CM_ClipSightTraceToEntities(&v20);
          *a1 = result;
        }
    }
  return result;
}

int __cdecl SV_TracePassed(float const *const start, float const *const mins,
                           float const *const maxs, float const *const end,
                           int passEntityNum0, int passEntityNum1,
                           int contentmask, int locational, int staticmodels)
{
  float *v8;       // edx
  float *v9;       // eax
  float *v10;      // ecx
  float v11;       // xmm7_4
  float v13;       // xmm5_4
  float v14;       // xmm6_4
  float v15;       // xmm3_4
  float v16;       // xmm4_4
  float v17;       // xmm1_4
  float v18;       // xmm5_4
  float v19;       // xmm6_4
  float *v20;      // [esp+2Ch] [ebp-6Ch]
  sightclip_t v21; // [esp+38h] [ebp-60h] BYREF

  if (CM_BoxSightTrace(0, a1, a4, a2, a3, 0, a6) ||
      a8 && !CM_PointTraceStaticModelsComplete(a1, a4, a6))
    return 0;
  v8 = a3 + 1;
  v20 = a2 + 1;
  v9 = a3 + 2;
  v10 = a2 + 2;
  v11 = *a3;
    if ((float)((float)((float)((float)((float)(*a3 - *a2) + a3[1]) - a2[1]) +
                        a3[2]) -
                a2[2]) == 0.0) {
      LODWORD(v21.outerSize[2]) = a6;
      v21.mins[0] = *a1;
      v21.mins[1] = a1[1];
      v21.mins[2] = a1[2];
      v21.maxs[0] = *a4;
      v21.maxs[1] = a4[1];
      v21.maxs[2] = a4[2];
      *(_QWORD *)v21.outerSize = a5;
      LODWORD(v21.start[0]) = a7;
      if (CM_PointSightTraceToEntities((sightpointtrace_t *)&v21))
        return 0;
    }
    else {
      v21.contentmask = a6;
      v21.passEntityNum = a5;
      v13 = *v8;
      v14 = *v9;
      v15 = (float)(*v8 - *v20) * 0.5;
      v16 = (float)(*v9 - *v10) * 0.5;
      v21.maxs[0] = (float)(v11 - *a2) * 0.5;
      v21.maxs[1] = v15;
      v21.maxs[2] = v16;
      LODWORD(v21.mins[0]) = LODWORD(v21.maxs[0]) ^ 0x80000000;
      LODWORD(v21.mins[1]) = LODWORD(v15) ^ 0x80000000;
      v21.mins[2] = -v16;
      v21.outerSize[0] = v21.maxs[0] + 1.0;
      v21.outerSize[1] = v15 + 1.0;
      v21.outerSize[2] = v16 + 1.0;
      v17 = (float)(v11 + *a2) * 0.5;
      v18 = (float)(v13 + *v20) * 0.5;
      v19 = (float)(v14 + *v10) * 0.5;
      v21.start[0] = v17 + *a1;
      v21.start[1] = v18 + a1[1];
      v21.start[2] = v19 + a1[2];
      v21.end[0] = v17 + *a4;
      v21.end[1] = v18 + a4[1];
      v21.end[2] = v19 + a4[2];
      if (CM_ClipSightTraceToEntities(&v21))
        return 0;
    }
  return 1;
}

void __cdecl SV_Trace(struct trace_t *results, float const *const start,
                      float const *const mins, float const *const maxs,
                      float const *const end, int passEntityNum,
                      int contentmask, int locational,
                      unsigned char *priorityMap, int staticmodels)
{
  uint16_t result; // ax
  float v11;       // xmm2_4
  float v12;       // xmm5_4
  float v13;       // xmm6_4
  float v14;       // xmm3_4
  float v15;       // xmm4_4
  float v16;       // xmm1_4
  float v17;       // xmm5_4
  float v18;       // xmm6_4
  float v19;       // [esp+2Ch] [ebp-8Ch]
  float *v20;      // [esp+30h] [ebp-88h]
  float *normal;   // [esp+34h] [ebp-84h]
  float *v22;      // [esp+38h] [ebp-80h]
  float *v23;      // [esp+3Ch] [ebp-7Ch]
  moveclip_t v24;  // [esp+4Ch] [ebp-6Ch] BYREF

  CM_BoxTrace(a1, a2, a5, a3, a4, 0, a7);
  result = (a1->fraction == 1.0) + 1022;
  a1->entityNum = result;
    if (a1->fraction != 0.0) {
        if (!a10 || (result = (unsigned __int16)CM_PointTraceStaticModels(
                         a1, a2, a5, (int)a7),
                     a1->fraction != 0.0)) {
          v20 = a4 + 1;
          normal = a3->normal;
          v22 = a4 + 2;
          v23 = &a3->normal[1];
          v19 = *a4;
            if ((float)((float)((float)((float)((float)(*a4 - a3->fraction) +
                                                a4[1]) -
                                        a3->normal[0]) +
                                a4[2]) -
                        a3->normal[1]) == 0.0) {
              *(_DWORD *)&v24.extents[8] = a7;
              v24.mins[0] = *a2;
              v24.mins[1] = a2[1];
              v24.mins[2] = a2[2];
              v24.maxs[0] = *a5;
              v24.maxs[1] = a5[1];
              v24.maxs[2] = a5[2];
              CM_CalcTraceEntents((TraceExtents *)&v24);
              *(_DWORD *)v24.extents = a6;
              *(_DWORD *)&v24.extents[12] = a8;
              *(_DWORD *)&v24.extents[16] = a9;
                if (a6 == 1023 || (*(_DWORD *)&v24.extents[4] =
                                       *(_DWORD *)(SV_GentityNum(a6) + 336),
                                   *(_DWORD *)&v24.extents[4] == 1023)) {
                  *(_DWORD *)&v24.extents[4] = -1;
                }
              return (unsigned __int16)CM_PointTraceToEntities(
                  (pointtrace_t *)&v24, a1);
            }
            else {
              v24.contentmask = (uint32_t)a7;
              v24.passEntityNum = a6;
                if (a6 == 1023) {
                  v24.passOwnerNum = -1;
                  v11 = v19;
                }
                else {
                  v24.passOwnerNum = *(_DWORD *)(SV_GentityNum(a6) + 336);
                  if (v24.passOwnerNum == 1023)
                    v24.passOwnerNum = -1;
                  v19 = *a4;
                  v11 = *a4;
                }
              v12 = *v20;
              v13 = *v22;
              v14 = (float)(*v20 - *normal) * 0.5;
              v15 = (float)(*v22 - *v23) * 0.5;
              v24.maxs[0] = (float)(v11 - a3->fraction) * 0.5;
              v24.maxs[1] = v14;
              v24.maxs[2] = v15;
              LODWORD(v24.mins[0]) = LODWORD(v24.maxs[0]) ^ 0x80000000;
              LODWORD(v24.mins[1]) = LODWORD(v14) ^ 0x80000000;
              v24.mins[2] = -v15;
              v24.outerSize[0] = v24.maxs[0] + 1.0;
              v24.outerSize[1] = v14 + 1.0;
              v24.outerSize[2] = v15 + 1.0;
              v16 = (float)(v19 + a3->fraction) * 0.5;
              v17 = (float)(v12 + *normal) * 0.5;
              v18 = (float)(v13 + *v23) * 0.5;
              *(float *)v24.extents = v16 + *a2;
              *(float *)&v24.extents[4] = v17 + a2[1];
              *(float *)&v24.extents[8] = v18 + a2[2];
              *(float *)&v24.extents[12] = v16 + *a5;
              *(float *)&v24.extents[16] = v17 + a5[1];
              *(float *)&v24.extents[20] = v18 + a5[2];
              CM_CalcTraceEntents((TraceExtents *)v24.extents);
              return CM_ClipMoveToEntities(&v24, a1);
            }
        }
    }
  return result;
}

void __cdecl SnapAngles(float *const)
{
  UNIMPLEMENTED();
}
