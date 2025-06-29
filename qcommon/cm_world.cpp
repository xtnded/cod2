void __cdecl CM_UnlinkEntity(struct svEntity_s *ent)
{
  svEntity_s *result;                       // eax
  unsigned __int16 worldSector;             // bx
  int *v3;                                  // edi
  svEntity_s *v4;                           // ecx
  unsigned __int16 v5;                      // dx
  int v6;                                   // esi
  unsigned __int16 v7;                      // ax
  svEntity_s *i;                            // ebx
  unsigned __int16 nextEntityInWorldSector; // ax

  result = a1;
  worldSector = a1->worldSector;
    if (a1->worldSector) {
      v3 = &dword_4ED89C[6 * worldSector];
      a1->worldSector = 0;
      v4 = (svEntity_s *)((char *)&sv + 372 * *((unsigned __int16 *)v3 + 4) +
                          8868);
        if (a1 == v4) {
          *((_WORD *)v3 + 4) =
              *((_WORD *)&sv + 186 * *((unsigned __int16 *)v3 + 4) + 4435);
        }
        else {
          while (a1 != (svEntity_s *)((char *)&sv +
                                      372 * (unsigned __int16)
                                                v4->nextEntityInWorldSector +
                                      8868))
            v4 = (svEntity_s *)((char *)&sv +
                                372 * (unsigned __int16)
                                          v4->nextEntityInWorldSector +
                                8868);
          v4->nextEntityInWorldSector = a1->nextEntityInWorldSector;
        }
        for (; !v3[2]; worldSector = v5) {
          if (v3[5])
            break;
          v3[1] = 0;
          v5 = *((_WORD *)v3 + 9);
          if (!v5)
            break;
          *((_WORD *)v3 + 9) = word_4ED89A;
          word_4ED89A = worldSector;
          v3 = &dword_4ED89C[6 * v5];
          if (worldSector == *((_WORD *)v3 + 10))
            *((_WORD *)v3 + 10) = 0;
          else
            *((_WORD *)v3 + 11) = 0;
        }
        while (1) {
          v6 = dword_4ED8A0[6 * *((unsigned __int16 *)v3 + 11)] |
               dword_4ED8A0[6 * *((unsigned __int16 *)v3 + 10)];
          v7 = *((_WORD *)v3 + 4);
            if (v7) {
                for (i = (svEntity_s *)((char *)&sv + 372 * v7 + 8868);;
                     i = (svEntity_s *)((char *)&sv +
                                        372 * nextEntityInWorldSector + 8868)) {
                  v6 |= *(_DWORD *)(SV_GEntityForSvEntity(i) + 284);
                  nextEntityInWorldSector = i->nextEntityInWorldSector;
                  if (!nextEntityInWorldSector)
                    break;
                }
            }
          v3[1] = v6;
          result = (svEntity_s *)*((unsigned __int16 *)v3 + 9);
          if (!(_WORD)result)
            break;
          v3 = &dword_4ED89C[6 * (unsigned __int16)result];
        }
    }
  return result;
}

int __cdecl CM_AreaEntities(float const *const mins, float const *const maxs,
                            int *entityList, int maxcount, int contentmask)
{
  _DWORD v6[4]; // [esp+0h] [ebp-28h] BYREF
  int v7;       // [esp+10h] [ebp-18h]
  int v8;       // [esp+14h] [ebp-14h]
  int v9;       // [esp+18h] [ebp-10h]

  v6[1] = a1;
  v6[2] = a2;
  v6[3] = a3;
  v7 = 0;
  v8 = a4;
  v9 = a5;
  CM_AreaEntities_r(1u, v6);
  return v7;
}

void __cdecl CM_LinkEntity(struct svEntity_s *ent, float *const absmin,
                           float *const absmax, int clipHandle)
{
  int v4;                                   // eax
  int result;                               // eax
  unsigned __int16 v6;                      // bx
  int *v7;                                  // edi
  svEntity_s *v8;                           // ecx
  unsigned __int16 v9;                      // dx
  int v10;                                  // esi
  unsigned __int16 v11;                     // ax
  svEntity_s *m;                            // ebx
  unsigned __int16 nextEntityInWorldSector; // ax
  int v14;                                  // esi
  int16_t *v15;                             // ecx
  unsigned __int16 j;                       // dx
  unsigned __int16 i;                       // di
  int v18;                                  // eax
  int v19;                                  // eax
  int v20;                                  // edx
  float v21;                                // xmm1_4
  unsigned __int16 v22;                     // ax
  svEntity_s *v23;                          // eax
  unsigned __int16 worldSector;             // si
  int *v25;                                 // edi
  svEntity_s *v26;                          // ecx
  unsigned __int16 v27;                     // dx
  int v28;                                  // esi
  unsigned __int16 k;                       // ax
  svEntity_s *v30;                          // ebx
  unsigned __int16 v31;                     // ax
  unsigned __int16 v32;                     // ax
  int v33;                                  // [esp+18h] [ebp-30h]
  int32_t v34;                              // [esp+1Ch] [ebp-2Ch]
  float v35[2];                             // [esp+20h] [ebp-28h] BYREF
  float v36[8];                             // [esp+28h] [ebp-20h] BYREF

  v4 = CM_ClipHandleToModel(a4);
  v34 = *(_DWORD *)(v4 + 36) | *(_DWORD *)(v4 + 32);
    if (*(_QWORD *)(v4 + 32)) {
      v33 = ~(*(_DWORD *)(v4 + 36) | *(_DWORD *)(v4 + 32));
        while (1) {
          v36[0] = cm_world;
          LODWORD(v36[1]) = dword_4ED884;
          v35[0] = flt_4ED88C;
          v35[1] = *(float *)dword_4ED890;
            for (i = 1;; i = v32) {
                while (1) {
                  v18 = 6 * i;
                  dword_4ED8A0[v18] |= v34;
                  v19 = v18 * 4 + 5167260;
                  v20 = *(unsigned __int16 *)(v19 + 16);
                  v21 = *(float *)(v19 + 12);
                  if (a2[v20] <= v21)
                    break;
                  v36[v20] = v21;
                  v22 = *(_WORD *)(v19 + 20);
                  if (!v22)
                    goto LABEL_32;
                  i = v22;
                }
              if (v21 <= a3[v20])
                break;
              v35[v20] = v21;
              v32 = *(_WORD *)(v19 + 22);
              if (!v32)
                goto LABEL_32;
            }
          v23 = a1;
            if (i == a1->worldSector) {
                if ((v33 & a1->linkcontents) == 0) {
                  a1->linkcontents = v34;
                  a1->linkmin = *(_QWORD *)a2;
                  *(float *)&a1->linkmax = *a3;
                  result = *((_DWORD *)a3 + 1);
                  HIDWORD(a1->linkmax) = result;
                  return result;
                }
            LABEL_32:
              v23 = a1;
            }
          worldSector = v23->worldSector;
            if (!v23->worldSector) {
              v14 = 1062196213 * (((char *)a1 - (char *)&unk_16A3318) >> 2);
              v15 = (int16_t *)&dword_4ED890[6 * i + 5];
              for (j = *v15;
                   (unsigned __int16)v14 >= (unsigned __int16)(*v15 - 1);
                   j = *v15)
                v15 = (int16_t *)((char *)&sv + 372 * j + 8870);
              a1->worldSector = i;
              a1->nextEntityInWorldSector = *v15;
              *v15 = v14 + 1;
            LABEL_23:
              a1->linkcontents = v34;
              a1->linkmin = *(_QWORD *)a2;
              a1->linkmax = *(_QWORD *)a3;
              return CM_SortNode(i, v36, v35);
            }
          if (worldSector == i && (v33 & v23->linkcontents) == 0)
            goto LABEL_23;
          v25 = &dword_4ED89C[6 * worldSector];
          a1->worldSector = 0;
          v26 = (svEntity_s *)((char *)&sv +
                               372 * *((unsigned __int16 *)v25 + 4) + 8868);
            if (a1 == v26) {
              *((_WORD *)v25 + 4) = a1->nextEntityInWorldSector;
            }
            else {
              while (a1 != (svEntity_s *)((char *)&sv +
                                          372 * (unsigned __int16)v26
                                                    ->nextEntityInWorldSector +
                                          8868))
                v26 = (svEntity_s *)((char *)&sv +
                                     372 * (unsigned __int16)
                                               v26->nextEntityInWorldSector +
                                     8868);
              v26->nextEntityInWorldSector = a1->nextEntityInWorldSector;
            }
            for (; !v25[2]; worldSector = v27) {
              if (v25[5])
                break;
              v25[1] = 0;
              v27 = *((_WORD *)v25 + 9);
              if (!v27)
                break;
              *((_WORD *)v25 + 9) = word_4ED89A;
              word_4ED89A = worldSector;
              v25 = &dword_4ED89C[6 * v27];
              if (worldSector == *((_WORD *)v25 + 10))
                *((_WORD *)v25 + 10) = 0;
              else
                *((_WORD *)v25 + 11) = 0;
            }
            while (1) {
              v28 = dword_4ED8A0[6 * *((unsigned __int16 *)v25 + 11)] |
                    dword_4ED8A0[6 * *((unsigned __int16 *)v25 + 10)];
                for (k = *((_WORD *)v25 + 4); k;
                     k = v30->nextEntityInWorldSector) {
                  v30 = (svEntity_s *)((char *)&sv + 372 * k + 8868);
                  v28 |= *(_DWORD *)(SV_GEntityForSvEntity(v30) + 284);
                }
              v25[1] = v28;
              v31 = *((_WORD *)v25 + 9);
              if (!v31)
                break;
              v25 = &dword_4ED89C[6 * v31];
            }
        }
    }
  result = (int)a1;
  v6 = a1->worldSector;
    if (a1->worldSector) {
      v7 = &dword_4ED89C[6 * v6];
      a1->worldSector = 0;
      v8 = (svEntity_s *)((char *)&sv + 372 * *((unsigned __int16 *)v7 + 4) +
                          8868);
        if (a1 == v8) {
          *((_WORD *)v7 + 4) = a1->nextEntityInWorldSector;
        }
        else {
          while (a1 != (svEntity_s *)((char *)&sv +
                                      372 * (unsigned __int16)
                                                v8->nextEntityInWorldSector +
                                      8868))
            v8 = (svEntity_s *)((char *)&sv +
                                372 * (unsigned __int16)
                                          v8->nextEntityInWorldSector +
                                8868);
          v8->nextEntityInWorldSector = a1->nextEntityInWorldSector;
        }
        for (; !v7[2]; v6 = v9) {
          if (v7[5])
            break;
          v7[1] = 0;
          v9 = *((_WORD *)v7 + 9);
          if (!v9)
            break;
          *((_WORD *)v7 + 9) = word_4ED89A;
          word_4ED89A = v6;
          v7 = &dword_4ED89C[6 * v9];
          if (v6 == *((_WORD *)v7 + 10))
            *((_WORD *)v7 + 10) = 0;
          else
            *((_WORD *)v7 + 11) = 0;
        }
        while (1) {
          v10 = dword_4ED8A0[6 * *((unsigned __int16 *)v7 + 11)] |
                dword_4ED8A0[6 * *((unsigned __int16 *)v7 + 10)];
          v11 = *((_WORD *)v7 + 4);
            if (v11) {
                for (m = (svEntity_s *)((char *)&sv + 372 * v11 + 8868);;
                     m = (svEntity_s *)((char *)&sv +
                                        372 * nextEntityInWorldSector + 8868)) {
                  v10 |= *(_DWORD *)(SV_GEntityForSvEntity(m) + 284);
                  nextEntityInWorldSector = m->nextEntityInWorldSector;
                  if (!nextEntityInWorldSector)
                    break;
                }
            }
          v7[1] = v10;
          result = *((unsigned __int16 *)v7 + 9);
          if (!(_WORD)result)
            break;
          v7 = &dword_4ED89C[6 * (unsigned __int16)result];
        }
    }
  return result;
}

void __cdecl CM_LinkWorld()
{
  UNIMPLEMENTED();
}

int __cdecl CM_PointTraceStaticModelsComplete(float const *const start,
                                              float const *const end,
                                              int contentmask)
{
  TraceExtents v4; // [esp+18h] [ebp-30h] BYREF
  int v5;          // [esp+3Ch] [ebp-Ch]

  v5 = a3;
  v4.start[0] = *a1;
  v4.start[1] = a1[1];
  v4.start[2] = a1[2];
  v4.end[0] = *a2;
  v4.end[1] = a2[1];
  v4.end[2] = a2[2];
  CM_CalcTraceEntents(&v4);
  return CM_PointTraceStaticModelsComplete_r(
      (int)&v4, 1u, v4.start, (const staticmodeltrace_t *)v4.end);
}

void __cdecl CM_PointTraceStaticModels(struct trace_t *results,
                                       float const *const start,
                                       float const *const end, int contentmask)
{
  int v5;            // [esp+18h] [ebp-50h] BYREF
  TraceExtents v6;   // [esp+1Ch] [ebp-4Ch] BYREF
  locTraceWork_t v7; // [esp+40h] [ebp-28h] BYREF

  v5 = a4;
  v6.start[0] = *a2;
  v6.start[1] = a2[1];
  v6.start[2] = a2[2];
  v6.end[0] = *a3;
  v6.end[1] = a3[1];
  v6.end[2] = a3[2];
  CM_CalcTraceEntents(&v6);
  *(float *)&v7.extents[12] = v6.start[0];
  *(float *)&v7.extents[16] = v6.start[1];
  *(float *)&v7.extents[20] = v6.start[2];
  *(_DWORD *)&v7.extents[24] = 0;
  v7.contents = LODWORD(v6.end[0]);
  *(float *)v7.extents = v6.end[1];
  *(float *)&v7.extents[4] = v6.end[2];
  *(float *)&v7.extents[8] = a1->fraction;
  return CM_PointTraceStaticModels_r((int)&v5, 1u, (float *)&v7.extents[12],
                                     &v7, a1);
}

void __cdecl CM_ClipMoveToEntities(struct moveclip_t *clip,
                                   struct trace_t *trace)
{
  _DWORD v3[4]; // [esp+10h] [ebp-28h] BYREF
  float v4[6];  // [esp+20h] [ebp-18h] BYREF

  v4[0] = *(float *)a1->extents;
  v4[1] = *(float *)&a1->extents[4];
  v4[2] = *(float *)&a1->extents[8];
  v3[0] = *(_DWORD *)&a1->extents[12];
  v3[1] = *(_DWORD *)&a1->extents[16];
  v3[2] = *(_DWORD *)&a1->extents[20];
  v4[3] = 0.0;
  v3[3] = LODWORD(a2->fraction);
  return CM_ClipMoveToEntities_r(a1, 1u, v4, (const moveclip_t *)v3, a2);
}

int __cdecl CM_ClipSightTraceToEntities(struct sightclip_t *clip)
{
  return CM_ClipSightTraceToEntities_r(a1, 1u, a1->start,
                                       (sightclip_t *)a1->end);
}

int __cdecl CM_PointSightTraceToEntities(struct sightpointtrace_t *clip)
{
  return CM_PointSightTraceToEntities_r(a1, 1u, a1->start,
                                        (sightpointtrace_t *)a1->end);
}

void __cdecl CM_PointTraceToEntities(struct pointtrace_t *clip,
                                     struct trace_t *trace)
{
  _DWORD v3[4]; // [esp+10h] [ebp-28h] BYREF
  _DWORD v4[6]; // [esp+20h] [ebp-18h] BYREF

  v4[0] = *(_DWORD *)a1->extents;
  v4[1] = *(_DWORD *)&a1->extents[4];
  v4[2] = *(_DWORD *)&a1->extents[8];
  v3[0] = *(_DWORD *)&a1->extents[12];
  v3[1] = *(_DWORD *)&a1->extents[16];
  v3[2] = *(_DWORD *)&a1->extents[20];
  v4[3] = 0;
  v3[3] = LODWORD(a2->fraction);
  return CM_PointTraceToEntities_r((int)a1, 1u, (int)v4, (pointtrace_t *)v3,
                                   a2);
}

int marker_cm_world;

void __cdecl CM_AddStaticModelToNode(struct cStaticModel_s *, unsigned short)
{
  UNIMPLEMENTED();
}

void __cdecl CM_AddEntityToNode(struct svEntity_s *, unsigned short)
{
  UNIMPLEMENTED();
}

void __cdecl CM_AreaEntities_r(unsigned short, struct areaParms_t *)
{
  _DWORD *v2;                               // esi
  int *v3;                                  // ebx
  unsigned __int16 nextEntityInWorldSector; // ax
  int v5;                                   // edx
  svEntity_s *v6;                           // edi
  int v7;                                   // edx
  float *v8;                                // eax
  float *v9;                                // ecx
  unsigned __int16 v10;                     // [esp+0h] [ebp-38h]
  areaParms_t *v11;                         // [esp+4h] [ebp-34h]
  int v12;                                  // [esp+18h] [ebp-20h]

    while (1) {
      v2 = a2;
      v3 = &dword_4ED89C[6 * a1];
      if ((v3[1] & a2[6]) == 0)
        break;
      nextEntityInWorldSector = *((_WORD *)v3 + 4);
        if (nextEntityInWorldSector) {
            do {
              v6 = (svEntity_s *)&sv[93 * nextEntityInWorldSector + 2217];
              v7 = SV_GEntityForSvEntity(v6);
                if ((*(_DWORD *)(v7 + 284) & v2[6]) != 0) {
                  v8 = (float *)v2[2];
                    if (*(float *)(v7 + 288) <= *v8) {
                      v9 = (float *)v2[1];
                        if (*v9 <= *(float *)(v7 + 300) &&
                            *(float *)(v7 + 292) <= v8[1] &&
                            v9[1] <= *(float *)(v7 + 304) &&
                            *(float *)(v7 + 296) <= v8[2] &&
                            v9[2] <= *(float *)(v7 + 308)) {
                          v12 = v2[4];
                            if (v12 == v2[5]) {
                              Com_DPrintf("CM_AreaEntities: MAXCOUNT\n");
                              return;
                            }
                          *(_DWORD *)(v2[3] + 4 * v12) =
                              1062196213 *
                              (((char *)v6 - (char *)&unk_16A3318) >> 2);
                          ++v2[4];
                        }
                    }
                }
              nextEntityInWorldSector = v6->nextEntityInWorldSector;
            }
          while (nextEntityInWorldSector);
          v5 = *((unsigned __int16 *)v3 + 8);
          if (*(float *)(v2[2] + 4 * v5) <= *((float *)v3 + 3))
            goto LABEL_4;
        }
        else {
          v5 = *((unsigned __int16 *)v3 + 8);
            if (*(float *)(v2[2] + 4 * v5) <= *((float *)v3 + 3)) {
            LABEL_4:
              if (*((float *)v3 + 3) <= *(float *)(v2[1] + 4 * v5))
                return;
              goto LABEL_6;
            }
        }
      CM_AreaEntities_r(v10, v11);
      if (*((float *)v3 + 3) <=
          *(float *)(v2[1] + 4 * *((unsigned __int16 *)v3 + 8)))
        return;
    LABEL_6:
      a1 = *((_WORD *)v3 + 11);
      a2 = v2;
    }
}

unsigned short __cdecl CM_AllocWorldSector(float *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CM_SortNode(unsigned short, float *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl CM_ClearWorld(void)
{
  UNIMPLEMENTED();
}

void __cdecl CM_LinkStaticModel(struct cStaticModel_s *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_PointTraceStaticModelsComplete_r(
    struct staticmodeltrace_t const *, unsigned short, float const *const,
    float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl CM_PointTraceStaticModels_r(struct locTraceWork_t *,
                                         unsigned short, float const *const,
                                         float const *const, struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_LinkStaticModels(void)
{
  UNIMPLEMENTED();
}

void __cdecl CM_ClipMoveToEntities_r(struct moveclip_t const *, unsigned short,
                                     float const *const, float const *const,
                                     struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_ClipSightTraceToEntities_r(struct sightclip_t const *,
                                          unsigned short, float const *const,
                                          float const *const)
{
  UNIMPLEMENTED();
}

int __cdecl CM_PointSightTraceToEntities_r(struct sightpointtrace_t *,
                                           unsigned short, float const *const,
                                           float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl CM_PointTraceToEntities_r(struct pointtrace_t *, unsigned short,
                                       float const *const, float const *const,
                                       struct trace_t *)
{
  UNIMPLEMENTED();
}
