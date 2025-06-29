int __cdecl I_side(float)
{
  UNIMPLEMENTED();
}

struct cmodel_t *__cdecl CM_ClipHandleToModel(int handle)
{
  if (dword_1007E94 <= a1)
    return *(_DWORD *)(Sys_GetValue(3) + 20);
  else
    return unk_1007E98 + 72 * a1;
}

int __cdecl CM_TempBoxModel(float const *const mins, float const *const maxs,
                            int contents)
{
  int Value; // eax
  int v4;    // esi
  float *v5; // edx

  Value = Sys_GetValue(3);
  v4 = *(_DWORD *)(Value + 16);
  v5 = *(float **)(Value + 20);
  *v5 = *a1;
  v5[1] = a1[1];
  v5[2] = a1[2];
  v5[3] = *a2;
  v5[4] = a2[1];
  v5[5] = a2[2];
  *(float *)v4 = *a1;
  *(float *)(v4 + 4) = a1[1];
  *(float *)(v4 + 8) = a1[2];
  *(float *)(v4 + 16) = *a2;
  *(float *)(v4 + 20) = a2[1];
  *(float *)(v4 + 24) = a2[2];
  *(_DWORD *)(v4 + 12) = a3;
  return 1023;
}

float __cdecl CM_RadiusOfModel(int handle)
{
  if (a1 >= dword_1007E94)
    return *(float *)(*(_DWORD *)(Sys_GetValue(3) + 20) + 24);
  else
    return *(float *)(unk_1007E98 + 72 * a1 + 24);
}

int __cdecl CM_ContentsOfModel(int handle)
{
  int Value; // eax

  if (a1 < dword_1007E94)
    return *(_DWORD *)(unk_1007E98 + 72 * a1 + 36) |
           *(_DWORD *)(unk_1007E98 + 72 * a1 + 32);
  Value = Sys_GetValue(3);
  return *(_DWORD *)(*(_DWORD *)(Value + 20) + 36) |
         *(_DWORD *)(*(_DWORD *)(Value + 20) + 32);
}

int __cdecl CM_BoxSightTrace(int oldHitNum, float const *const start,
                             float const *const end, float const *const mins,
                             float const *const maxs, int model, int brushmask)
{
  int v7;                 // ecx
  int v8;                 // edx
  float *v9;              // eax
  float v10;              // xmm0_4
  float v11;              // xmm0_4
  float v12;              // xmm0_4
  float v13;              // xmm0_4
  float v14;              // xmm3_4
  __m128 v15;             // xmm2
  float v16;              // xmm2_4
  TraceExtents *v17;      // eax
  float v18;              // xmm1_4
  float v19;              // xmm0_4
  int *Value;             // eax
  int v21;                // edx
  int v22;                // edx
  float *v23;             // ecx
  int result;             // eax
  float v25;              // xmm4_4
  float v26;              // xmm5_4
  float v27;              // xmm6_4
  float v28;              // xmm7_4
  float *v29;             // eax
  int v30;                // ecx
  int v31;                // edx
  float v32;              // xmm0_4
  float v33;              // xmm2_4
  float v34;              // xmm1_4
  float v35;              // xmm4_4
  float v36;              // xmm3_4
  float v37;              // xmm2_4
  float v38;              // xmm0_4
  float *v39;             // edx
  const traceWork_t *v40; // eax
  _BOOL4 v41;             // eax
  float v42;              // xmm2_4
  float v43;              // xmm2_4
  float v44;              // xmm1_4
  float v45;              // [esp+10h] [ebp-1C8h]
  int v46;                // [esp+3Ch] [ebp-19Ch]
  float v47;              // [esp+40h] [ebp-198h]
  float v48;              // [esp+44h] [ebp-194h]
  float v49;              // [esp+48h] [ebp-190h]
  float v50;              // [esp+4Ch] [ebp-18Ch]
  float v51;              // [esp+50h] [ebp-188h]
  float v52;              // [esp+54h] [ebp-184h]
  float v53;              // [esp+58h] [ebp-180h]
  float v54;              // [esp+5Ch] [ebp-17Ch]
  TraceExtents v55;       // [esp+60h] [ebp-178h] BYREF
  float v56;              // [esp+84h] [ebp-154h]
  float v57;              // [esp+88h] [ebp-150h]
  float v58;              // [esp+8Ch] [ebp-14Ch]
  float v59;              // [esp+90h] [ebp-148h]
  float v60;              // [esp+94h] [ebp-144h]
  _BYTE v61[16];          // [esp+A0h] [ebp-138h]
  char v62;               // [esp+B0h] [ebp-128h] BYREF
  float v63;              // [esp+BCh] [ebp-11Ch]
  float v64;              // [esp+C0h] [ebp-118h]
  float v65;              // [esp+C4h] [ebp-114h]
  float v66;              // [esp+C8h] [ebp-110h]
  float v67;              // [esp+CCh] [ebp-10Ch]
  float v68;              // [esp+D0h] [ebp-108h]
  float v69;              // [esp+D4h] [ebp-104h]
  float v70;              // [esp+D8h] [ebp-100h]
  float v71;              // [esp+DCh] [ebp-FCh]
  int v72;                // [esp+E0h] [ebp-F8h]
  _BOOL4 v73;             // [esp+E4h] [ebp-F4h]
  _BOOL4 v74;             // [esp+E8h] [ebp-F0h]
  float v75;              // [esp+ECh] [ebp-ECh]
  float v76;              // [esp+F0h] [ebp-E8h]
  float v77;              // [esp+F4h] [ebp-E4h]
  float v78;              // [esp+F8h] [ebp-E0h]
  float v79;              // [esp+FCh] [ebp-DCh]
  int v80;                // [esp+100h] [ebp-D8h]
  int v81;                // [esp+104h] [ebp-D4h]
  int v82;                // [esp+108h] [ebp-D0h]
  int v83;                // [esp+10Ch] [ebp-CCh]
  int v84;                // [esp+110h] [ebp-C8h]
  float *v85;             // [esp+114h] [ebp-C4h]
  cLeaf_t v86;            // [esp+118h] [ebp-C0h] BYREF
  float v87;              // [esp+148h] [ebp-90h]
  float v88;              // [esp+150h] [ebp-88h]
  float v89;              // [esp+154h] [ebp-84h]
  float v90;              // [esp+158h] [ebp-80h]
  float v91;              // [esp+15Ch] [ebp-7Ch]
  float v92[2];           // [esp+160h] [ebp-78h] BYREF
  float v93;              // [esp+168h] [ebp-70h]
  float v94[2];           // [esp+16Ch] [ebp-6Ch] BYREF
  float v95;              // [esp+174h] [ebp-64h]
  _DWORD v96[2];          // [esp+178h] [ebp-60h] BYREF
  float v97;              // [esp+180h] [ebp-58h]
  _DWORD v98[2];          // [esp+184h] [ebp-54h] BYREF
  float v99;              // [esp+18Ch] [ebp-4Ch]
  float v100[2];          // [esp+190h] [ebp-48h] BYREF
  float v101;             // [esp+198h] [ebp-40h]
  float v102;             // [esp+19Ch] [ebp-3Ch] BYREF
  float v103;             // [esp+1A0h] [ebp-38h]
  float v104;             // [esp+1A4h] [ebp-34h]
  float v105;             // [esp+1A8h] [ebp-30h]
  float v106;             // [esp+1ACh] [ebp-2Ch]
  float v107;             // [esp+1B0h] [ebp-28h]
  float v108[9];          // [esp+1B4h] [ebp-24h] BYREF

  if (a6 >= dword_1007E94)
    v46 = *(_DWORD *)(Sys_GetValue(3) + 20);
  else
    v46 = unk_1007E98 + 72 * a6;
  *(_DWORD *)&v86.firstCollAabbIndex = 1065353216;
  HIWORD(v86.maxs[2]) = 0;
  v72 = a7;
  v7 = 1;
  v8 = 1;
  v9 = (float *)&v62;
    do {
      v10 = (float)(a5[v8 - 1] + a4[v8 - 1]) * 0.5;
      v9[3] = a5[v8 - 1] - v10;
      *(v9 - 20) = v10 + a2[v8 - 1];
      v11 = v10 + a3[v8 - 1];
      *(v9 - 17) = v11;
      *(v9 - 6) = (float)(v11 + *(v9 - 20)) * 0.5;
      v12 = v11 - *(v9 - 20);
      v55.invDelta[v8 + 2] = v12;
      v13 = v12 * 0.5;
      *(float *)&v61[v8 * 4] = v13;
      *v9 = fabs(v13);
      ++v7;
      ++v8;
      ++v9;
    }
  while (v7 != 4);
  CM_CalcTraceEntents(&v55);
  v60 = (float)((float)(v56 * v56) + (float)(v57 * v57)) + (float)(v58 * v58);
  v59 = fsqrt(v60);
  v14 = v63;
  v15 = _mm_cmpge_ss((__m128)LODWORD(v65), (__m128)LODWORD(v63));
  LODWORD(v16) = _mm_andnot_ps(v15, (__m128)LODWORD(v65)).u32[0] |
                 LODWORD(v63) & v15.i32[0];
  v75 = v16;
  v76 = v65 - v16;
  v17 = &v55;
    do {
      v18 = v17->start[0];
      v19 = v17->end[0];
        if (v19 <= v17->start[0]) {
          v17[2].invDelta[2] = v19 - v16;
          v17[3].start[2] = v18 + v16;
        }
        else {
          v17[2].invDelta[2] = v18 - v16;
          v17[3].start[2] = v19 + v16;
        }
      v17 = (TraceExtents *)((char *)v17 + 4);
    }
  while ((TraceExtents *)&v55.start[2] != v17);
    if (v55.end[2] <= v55.start[2]) {
      v68 = (float)(v55.end[2] - v76) - v75;
      v71 = (float)(v55.start[2] + v76) + v75;
    }
    else {
      v68 = (float)(v55.start[2] - v76) - v75;
      v71 = (float)(v55.end[2] + v76) + v75;
    }
  v74 = (float)((float)((float)((float)(v14 * v64) * v65) * 16.0) * v59) >
        (float)((float)(v71 - v68) *
                (float)((float)(v69 - v66) * (float)(v70 - v67)));
  v73 = (float)((float)(v14 + v64) + v65) == 0.0;
  v77 = v75;
  v78 = v75;
  v79 = v75 + v76;
  Value = (int *)Sys_GetValue(3);
  v21 = *Value + 1;
  *Value = v21;
  v80 = v21;
  v81 = Value[1];
  v82 = Value[2];
  v83 = Value[3];
  v22 = Value[4];
  v84 = v22;
  v23 = (float *)Value[5];
  v85 = v23;
    if (a6) {
      if (a6 != 1023)
        return CM_SightTraceThroughLeaf((int)&v55, (float *)(v46 + 28),
                                        (trace_t *)&v86);
        if ((*(_DWORD *)(v22 + 12) & v72) == 0 || v66 > (float)(v23[3] + 1.0) ||
            v67 > (float)(v23[4] + 1.0) || v68 > (float)(v23[5] + 1.0) ||
            (float)(*v23 - 1.0) > v69 || (float)(v23[1] - 1.0) > v70 ||
            (float)(v23[2] - 1.0) > v71) {
          return 0;
        }
      v25 = v55.start[0];
      v94[0] = v55.start[0];
      v26 = v55.start[1];
      v94[1] = v55.start[1];
      v27 = v55.start[2];
      v47 = v76 + v55.start[2];
      v95 = v76 + v55.start[2];
      v92[0] = v55.start[0];
      v92[1] = v55.start[1];
      v28 = v55.start[2] - v76;
      v93 = v55.start[2] - v76;
      v89 = v55.end[0];
      v90 = v55.end[1];
      v91 = v76 + v55.end[2];
      v105 = v55.end[0];
      v106 = v55.end[1];
      v107 = v55.end[2] - v76;
      v29 = v23;
      v30 = 1;
      v31 = 1;
        do {
          v32 = *v29;
          v33 = v29[3];
          v34 = (float)(*v29 + v33) * 0.5;
          *(float *)((char *)&v102 + v31 * 4 - 4) = v34;
          v86.maxs[v31 + 2] = v32 - v34;
          *((float *)&v86 + v31 + 11) = v33 - v34;
          ++v30;
          ++v31;
          ++v29;
        }
      while (v30 != 4);
      v51 = fminf(v88, v87);
      v52 = v88 - v51;
      v48 = v102;
      *(float *)v98 = v102;
      v49 = v103;
      *(float *)&v98[1] = v103;
      v50 = v104;
      v99 = (float)(v88 - v51) + v104;
      *(float *)v96 = v102;
      *(float *)&v96[1] = v103;
      v97 = v104 - (float)(v88 - v51);
        if (v28 <= v99) {
          if ((float)(v104 - (float)(v88 - v51)) <= v47)
            goto LABEL_30;
          if (!CM_SightTraceSphereThroughSphere(
                  v55.start, v94, v51, (const traceWork_t *)v96,
                  (const float *)&v86.firstCollAabbIndex))
            return -1;
          if (v58 <= 0.0)
            return 0;
        LABEL_51:
          v27 = v55.start[2];
          v25 = v55.start[0];
          v26 = v55.start[1];
        LABEL_30:
          v35 = v25 - v48;
          v100[0] = v35;
          v36 = v26 - v49;
          v100[1] = v26 - v49;
          v101 = v27 - v50;
          v37 = (float)((float)(v35 * v35) + (float)(v36 * v36)) -
                (float)((float)(v51 + v75) * (float)(v51 + v75));
            if (v37 <= 0.0) {
              v41 = fabs(v27 - v50) > (float)((float)(v65 - v75) + v52);
            }
            else {
              v38 = (float)(v35 * v56) + (float)(v36 * v57);
                if (v38 >= 0.0 ||
                    (v53 = v60, v42 = v37 * v60,
                     (float)((float)(v38 * v38) - v42) < 0.0) ||
                    (v101 = 0.0, v45 = (float)(v38 * v38) - v42,
                     v54 = Vec3NormalizeTo(v100, v108),
                     v43 = (float)(v38 * 0.125) / v54,
                     v44 =
                         (float)((float)((float)-v38 - fsqrt(v45)) / v53) + v43,
                     v44 >= *(float *)&v86.firstCollAabbIndex)) {
                LABEL_32:
                    if (v107 <= v99) {
                      if (v97 <= v91 || v95 < v97)
                        return 0;
                      v39 = v94;
                      v40 = (const traceWork_t *)v96;
                    }
                    else {
                      if (v99 < v93)
                        return 0;
                      v39 = v92;
                      v40 = (const traceWork_t *)v98;
                    }
                  if (!CM_SightTraceSphereThroughSphere(
                          v55.start, v39, v51, v40,
                          (const float *)&v86.firstCollAabbIndex))
                    return -1;
                  return 0;
                }
              v41 = fabs((float)((float)((float)(v44 - v43) * v58) +
                                 v55.start[2]) -
                         v50) > (float)((float)(v65 - v75) + v52);
            }
          if (!v41)
            return -1;
          goto LABEL_32;
        }
      if (!CM_SightTraceSphereThroughSphere(
              v55.start, v92, v51, (const traceWork_t *)v98,
              (const float *)&v86.firstCollAabbIndex))
        return -1;
      if (v58 < 0.0)
        goto LABEL_51;
      return 0;
    }
    else {
      if (a1 <= 0)
        return CM_SightTraceThroughTree((int)&v55, 0, v55.start,
                                        (const traceWork_t *)v55.end,
                                        (trace_t *)&v86);
      if (a1 - 1 >= unk_1007E9C)
        return CM_SightTraceThroughTree((int)&v55, 0, v55.start,
                                        (const traceWork_t *)v55.end,
                                        (trace_t *)&v86);
      result =
          CM_SightTraceThroughBrush(v55.start, unk_1007EA0 + 48 * (a1 - 1));
      if (!result)
        return CM_SightTraceThroughTree((int)&v55, 0, v55.start,
                                        (const traceWork_t *)v55.end,
                                        (trace_t *)&v86);
    }
  return result;
}

void __cdecl CM_TransformedBoxTrace(
    struct trace_t *results, float const *const start, float const *const end,
    float const *const mins, float const *const maxs, int model, int brushmask,
    float const *const origin, float const *const angles)
{
  int v9;         // edx
  int v10;        // eax
  float v11;      // xmm1_4
  float v12;      // xmm2_4
  float v13;      // xmm5_4
  float v14;      // xmm1_4
  float v15;      // xmm2_4
  char v16;       // bl
  int v17;        // esi
  float *i;       // eax
  float *v19;     // ecx
  float *v20;     // edx
  float v21;      // xmm2_4
  float v22;      // xmm3_4
  float v23;      // xmm4_4
  float fraction; // [esp+10h] [ebp-A8h]
  float v25[9];   // [esp+28h] [ebp-90h] BYREF
  float v26;      // [esp+4Ch] [ebp-6Ch] BYREF
  float v27;      // [esp+50h] [ebp-68h]
  float v28;      // [esp+54h] [ebp-64h]
  float v29;      // [esp+58h] [ebp-60h] BYREF
  float v30;      // [esp+5Ch] [ebp-5Ch]
  float v31;      // [esp+60h] [ebp-58h]
  float v32;      // [esp+64h] [ebp-54h] BYREF
  float v33;      // [esp+68h] [ebp-50h]
  float v34;      // [esp+6Ch] [ebp-4Ch]
  trace_t v35;    // [esp+70h] [ebp-48h] BYREF
  float v36;      // [esp+94h] [ebp-24h] BYREF
  float v37;      // [esp+98h] [ebp-20h]
  float v38;      // [esp+9Ch] [ebp-1Ch]

  v9 = 1;
  v10 = 1;
    do {
      v11 = (float)(a4[v10 - 1] + a5[v10 - 1]) * 0.5;
      *(float *)((char *)&v34 + v10 * 4) = a4[v10 - 1] - v11;
      v35.normal[v10 + 1] = a5[v10 - 1] - v11;
      *(float *)&v35.partName[v10 * 4 + 2] = v11 + a2[v10 - 1];
      *(float *)((char *)&v35.contents + v10 * 4) = v11 + a3[v10 - 1];
      ++v9;
      ++v10;
    }
  while (v9 != 4);
  v36 = v36 - *a8;
  v37 = v37 - a8[1];
  v38 = v38 - a8[2];
  *(float *)&v35.material = *(float *)&v35.material - *a8;
  *(float *)&v35.entityNum = *(float *)&v35.entityNum - a8[1];
  *(float *)&v35.partGroup = *(float *)&v35.partGroup - a8[2];
    if (*a9 == 0.0 && a9[1] == 0.0 && a9[2] == 0.0) {
      v16 = 0;
    }
    else {
      AngleVectors(a9, &v26, &v29, &v32);
      LODWORD(v29) ^= 0x80000000;
      v30 = -v30;
      v31 = -v31;
      v12 = v36;
      v13 = v37;
      v36 =
          (float)((float)(v36 * v26) + (float)(v37 * v27)) + (float)(v28 * v38);
      v37 =
          (float)((float)(v12 * v29) + (float)(v37 * v30)) + (float)(v38 * v31);
      v38 =
          (float)((float)(v12 * v32) + (float)(v13 * v33)) + (float)(v38 * v34);
      v14 = *(float *)&v35.material;
      v15 = *(float *)&v35.entityNum;
      *(float *)&v35.material =
          (float)((float)(*(float *)&v35.material * v26) +
                  (float)(v27 * *(float *)&v35.entityNum)) +
          (float)(v28 * *(float *)&v35.partGroup);
      *(float *)&v35.entityNum =
          (float)((float)(v14 * v29) +
                  (float)(v30 * *(float *)&v35.entityNum)) +
          (float)(v31 * *(float *)&v35.partGroup);
      *(float *)&v35.partGroup =
          (float)((float)(v14 * v32) + (float)(v15 * v33)) +
          (float)(*(float *)&v35.partGroup * v34);
      v16 = 1;
    }
  fraction = a1->fraction;
  CM_Trace((int)a1, &v36, (float *)&v35.material, &v35, &v35.normal[2], a6, a7);
    if (v16 && fraction > a1->fraction) {
      v17 = 0;
        for (i = v25;; i += 3) {
          v19 = &v26 + v17;
          v20 = i;
            do {
              *v20 = *v19;
              v19 += 3;
              ++v20;
            }
          while (i + 3 != v20);
          if (++v17 == 3)
            break;
        }
      v21 = a1->normal[0];
      v22 = a1->normal[1];
      v23 = a1->normal[2];
      a1->normal[0] = (float)((float)(v21 * v25[0]) + (float)(v22 * v25[1])) +
                      (float)(v23 * v25[2]);
      a1->normal[1] = (float)((float)(v21 * v25[3]) + (float)(v22 * v25[4])) +
                      (float)(v23 * v25[5]);
      a1->normal[2] = (float)((float)(v21 * v25[6]) + (float)(v22 * v25[7])) +
                      (float)(v23 * v25[8]);
    }
}

void __cdecl CM_BoxTrace(struct trace_t *results, float const *const start,
                         float const *const end, float const *const mins,
                         float const *const maxs, int model, int brushmask)
{
  memset(a1, 0, sizeof(trace_t));
  a1->fraction = 1.0;
  CM_Trace((int)a1, a2, a3, a4, a5, a6, a7);
}

int __cdecl CM_TransformedBoxSightTrace(
    int hitNum, float const *const start, float const *const end,
    float const *const mins, float const *const maxs, int model, int brushmask,
    float const *const origin, float const *const angles)
{
  int v9;       // edx
  int v10;      // eax
  float v11;    // xmm1_4
  float *v12;   // edi
  float v13;    // xmm2_4
  float v14;    // xmm5_4
  float v15;    // xmm1_4
  float v16;    // xmm2_4
  float v18;    // [esp+3Ch] [ebp-6Ch] BYREF
  float v19;    // [esp+40h] [ebp-68h]
  float v20;    // [esp+44h] [ebp-64h]
  float v21;    // [esp+48h] [ebp-60h] BYREF
  float v22;    // [esp+4Ch] [ebp-5Ch]
  float v23;    // [esp+50h] [ebp-58h]
  float v24;    // [esp+54h] [ebp-54h] BYREF
  float v25;    // [esp+58h] [ebp-50h]
  float v26;    // [esp+5Ch] [ebp-4Ch]
  float v27[3]; // [esp+60h] [ebp-48h] BYREF
  float v28[3]; // [esp+6Ch] [ebp-3Ch] BYREF
  float v29;    // [esp+78h] [ebp-30h] BYREF
  float v30;    // [esp+7Ch] [ebp-2Ch]
  float v31;    // [esp+80h] [ebp-28h]
  float v32;    // [esp+84h] [ebp-24h] BYREF
  float v33;    // [esp+88h] [ebp-20h]
  float v34;    // [esp+8Ch] [ebp-1Ch]

  v9 = 1;
  v10 = 1;
    do {
      v11 = (float)(a4[v10 - 1] + a5[v10 - 1]) * 0.5;
      v27[v10 - 1] = a4[v10 - 1] - v11;
      v27[v10 + 2] = a5[v10 - 1] - v11;
      *(float *)((char *)&v31 + v10 * 4) = v11 + a2[v10 - 1];
      v28[v10 + 2] = v11 + a3[v10 - 1];
      ++v9;
      ++v10;
    }
  while (v9 != 4);
  v32 = v32 - *a8;
  v33 = v33 - a8[1];
  v34 = v34 - a8[2];
  v29 = v29 - *a8;
  v30 = v30 - a8[1];
  v31 = v31 - a8[2];
    if (*a9 != 0.0) {
      v12 = a9;
      goto LABEL_8;
    }
    if (a9[1] != 0.0 || a9[2] != 0.0) {
      v12 = a9;
    LABEL_8:
      AngleVectors(v12, &v18, &v21, &v24);
      LODWORD(v21) ^= 0x80000000;
      v22 = -v22;
      v23 = -v23;
      v13 = v32;
      v14 = v33;
      v32 =
          (float)((float)(v32 * v18) + (float)(v33 * v19)) + (float)(v20 * v34);
      v33 =
          (float)((float)(v13 * v21) + (float)(v33 * v22)) + (float)(v34 * v23);
      v34 =
          (float)((float)(v13 * v24) + (float)(v14 * v25)) + (float)(v34 * v26);
      v15 = v29;
      v16 = v30;
      v29 =
          (float)((float)(v29 * v18) + (float)(v19 * v30)) + (float)(v20 * v31);
      v30 =
          (float)((float)(v15 * v21) + (float)(v22 * v30)) + (float)(v23 * v31);
      v31 =
          (float)((float)(v15 * v24) + (float)(v16 * v25)) + (float)(v31 * v26);
    }
  return CM_BoxSightTrace(a1, &v32, &v29, v27, v28, a6, a7);
}

void __cdecl CM_TransformedBoxTraceExternal(
    struct trace_t *results, float const *const start, float const *const end,
    float const *const mins, float const *const maxs, int model, int brushmask,
    float const *const origin, float const *const angles)
{
  memset(a1, 0, sizeof(trace_t));
  a1->fraction = 1.0;
  CM_TransformedBoxTrace(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int marker_cm_trace;

void __cdecl TransposeMatrix(float (*const)[3], float (*const)[3])
{
  UNIMPLEMENTED();
}

void __cdecl CM_GetBox(struct cbrush_t **, struct cmodel_t **)
{
  UNIMPLEMENTED();
}

void __cdecl CM_GetTrackThreadInfo(struct TraceThreadInfo *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceSphereThroughSphere(struct traceWork_t const *,
                                             float const *const,
                                             float const *const,
                                             float const *const, float,
                                             struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_SetAxialCullOnly(struct traceWork_t *)
{
  UNIMPLEMENTED();
}

void __cdecl RotatePoint(float *const, float (*const)[3])
{
  UNIMPLEMENTED();
}

int __cdecl CM_TraceSphereThroughSphere(struct traceWork_t const *,
                                        float const *const, float const *const,
                                        float const *const, float,
                                        struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceCylinderThroughCylinder(struct traceWork_t const *,
                                                 float const *const, float,
                                                 float, struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceThroughBrush(struct traceWork_t const *,
                                      struct cbrush_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_TraceCylinderThroughCylinder(struct traceWork_t const *,
                                            float const *const, float, float,
                                            struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TraceThroughBrush(struct traceWork_t const *, struct cbrush_t *,
                                  struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TestCapsuleInCapsule(struct traceWork_t *, struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TestBoxInBrush(struct traceWork_t const *, struct cbrush_t *,
                               struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CreateRotationMatrix(float const *const, float (*const)[3])
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceCapsuleThroughCapsule(struct traceWork_t const *,
                                               struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceThroughLeafBrushNode_r(struct traceWork_t const *,
                                                struct cLeafBrushNode_s *,
                                                float const *const,
                                                float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TraceCapsuleThroughCapsule(struct traceWork_t const *,
                                           struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TraceThroughLeafBrushNode_r(struct traceWork_t const *,
                                            struct cLeafBrushNode_s *,
                                            float const *const,
                                            float const *const,
                                            struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TestInLeafBrushNode_r(struct traceWork_t const *,
                                      struct cLeafBrushNode_s *,
                                      struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceThroughLeafBrushNode(struct traceWork_t const *,
                                              struct cLeaf_t *)
{
  UNIMPLEMENTED();
}

bool __cdecl CM_TraceThroughLeafBrushNode(struct traceWork_t const *,
                                          struct cLeaf_t *, struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_TestInLeafBrushNode(struct traceWork_t *, struct cLeaf_t *,
                                   struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TraceThroughLeaf(struct traceWork_t const *, struct cLeaf_t *,
                                 struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TestInLeaf(struct traceWork_t *, struct cLeaf_t *,
                           struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceThroughLeaf(struct traceWork_t const *,
                                     struct cLeaf_t *, struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_TraceThroughTree(struct traceWork_t const *, int,
                                 float const *const, float const *const,
                                 struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_PositionTest(struct traceWork_t *, struct trace_t *)
{
  UNIMPLEMENTED();
}

int __cdecl CM_SightTraceThroughTree(struct traceWork_t const *, int,
                                     float const *const, float const *const,
                                     struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl CM_Trace(struct trace_t *, float const *const, float const *const,
                      float const *const, float const *const, int, int)
{
  int v9;              // ecx
  int v10;             // edx
  float *halfDeltaAbs; // eax
  float v12;           // xmm0_4
  float v13;           // xmm0_4
  float v14;           // xmm0_4
  float v15;           // xmm0_4
  float v16;           // xmm3_4
  __m128 v17;          // xmm2
  float v18;           // xmm2_4
  traceWork_t *v19;    // eax
  float v20;           // xmm1_4
  float v21;           // xmm0_4
  int32_t *Value;      // eax
  int32_t v23;         // edx
  traceWork_t *v25;    // eax
  int v26;             // edi
  cLeaf_t *v27;        // esi
  int32_t v28;         // edx
  int v29;             // eax
  int v30;             // ebx
  int v31;             // ecx
  float v32;           // xmm4_4
  int32_t v33;         // edx
  int v34;             // ebx
  trace_t *i;          // edi
  int32_t contents;    // edx
  int v37;             // eax
  int v38;             // ebx
  int v39;             // ecx
  float v40;           // xmm6_4
  float v41;           // xmm7_4
  float *v42;          // eax
  int v43;             // ecx
  int v44;             // edx
  float v45;           // xmm0_4
  float v46;           // xmm2_4
  float v47;           // xmm1_4
  float v48;           // xmm2_4
  float v49;           // xmm4_4
  float v50;           // xmm5_4
  float v51;           // xmm2_4
  float v52;           // xmm3_4
  float v53;           // xmm5_4
  float v54;           // xmm6_4
  float *v55;          // eax
  int v56;             // ebx
  int v57;             // edx
  float v58;           // xmm0_4
  float v59;           // xmm2_4
  float v60;           // xmm1_4
  float v61;           // xmm3_4
  float v62;           // xmm5_4
  float v63;           // xmm2_4
  float v64;           // xmm3_4
  float v65;           // xmm1_4
  float v66;           // xmm4_4
  float v67;           // xmm2_4
  float v68;           // xmm2_4
  float v69;           // xmm1_4
  float v70;           // [esp+1Ch] [ebp-121Ch]
  float v71;           // [esp+60h] [ebp-11D8h]
  float v72;           // [esp+7Ch] [ebp-11BCh]
  float v73;           // [esp+7Ch] [ebp-11BCh]
  int v75;             // [esp+84h] [ebp-11B4h]
  float v76;           // [esp+88h] [ebp-11B0h]
  float v77;           // [esp+8Ch] [ebp-11ACh]
  float v78;           // [esp+90h] [ebp-11A8h]
  float v79;           // [esp+94h] [ebp-11A4h]
  float v80;           // [esp+98h] [ebp-11A0h]
  float v81;           // [esp+9Ch] [ebp-119Ch]
  float v82;           // [esp+A0h] [ebp-1198h]
  float v83;           // [esp+A4h] [ebp-1194h]
  float v84;           // [esp+A8h] [ebp-1190h]
  float v85;           // [esp+ACh] [ebp-118Ch]
  traceWork_t v86;     // [esp+BCh] [ebp-117Ch] BYREF
  traceWork_t v87;     // [esp+10BCh] [ebp-17Ch] BYREF
  traceWork_t v88;     // [esp+1174h] [ebp-C4h] BYREF

  if ((int)a6 >= dword_1007E94)
    v75 = *(_DWORD *)(Sys_GetValue(3) + 20);
  else
    v75 = unk_1007E98 + 72 * (_DWORD)a6;
  v87.contents = (int32_t)a7;
  v9 = 1;
  v10 = 1;
  halfDeltaAbs = v87.halfDeltaAbs;
    do {
      v12 = (float)(a5[v10 - 1] + *(float *)((char *)a4 + v10 * 4 - 4)) * 0.5;
      halfDeltaAbs[3] = a5[v10 - 1] - v12;
      *(halfDeltaAbs - 20) = v12 + a2[v10 - 1];
      v13 = v12 + a3[v10 - 1];
      *(halfDeltaAbs - 17) = v13;
      *(halfDeltaAbs - 6) = (float)(v13 + *(halfDeltaAbs - 20)) * 0.5;
      v14 = v13 - *(halfDeltaAbs - 20);
      v87.delta[v10 - 1] = v14;
      v15 = v14 * 0.5;
      v87.halfDelta[v10 - 1] = v15;
      *halfDeltaAbs = fabs(v15);
      ++v9;
      ++v10;
      ++halfDeltaAbs;
    }
  while (v9 != 4);
  CM_CalcTraceEntents(&v87.extents);
  *(float *)&v87.deltaLenSq = (float)((float)(v87.delta[0] * v87.delta[0]) +
                                      (float)(v87.delta[1] * v87.delta[1])) +
                              (float)(v87.delta[2] * v87.delta[2]);
  v87.deltaLen = fsqrt(*(float *)&v87.deltaLenSq);
  v16 = v87.size[0];
  v17 =
      _mm_cmpge_ss((__m128)LODWORD(v87.size[2]), (__m128)LODWORD(v87.size[0]));
  LODWORD(v18) = _mm_andnot_ps(v17, (__m128)LODWORD(v87.size[2])).u32[0] |
                 LODWORD(v87.size[0]) & v17.i32[0];
  *(float *)&v87.radius = v18;
  *(float *)&v87.offsetZ = v87.size[2] - v18;
  v19 = &v87;
    do {
      v20 = v19->extents.start[0];
      v21 = v19->extents.end[0];
        if (v21 <= v19->extents.start[0]) {
          v19->bounds[0][0] = v21 - v18;
          v19->bounds[1][0] = v20 + v18;
        }
        else {
          v19->bounds[0][0] = v20 - v18;
          v19->bounds[1][0] = v21 + v18;
        }
      v19 = (traceWork_t *)((char *)v19 + 4);
    }
  while (v19 != (traceWork_t *)&v87.extents.start[2]);
    if (v87.extents.end[2] <= v87.extents.start[2]) {
      v87.bounds[0][2] = (float)(v87.extents.end[2] - *(float *)&v87.offsetZ) -
                         *(float *)&v87.radius;
      v87.bounds[1][2] =
          (float)(v87.extents.start[2] + *(float *)&v87.offsetZ) +
          *(float *)&v87.radius;
    }
    else {
      v87.bounds[0][2] =
          (float)(v87.extents.start[2] - *(float *)&v87.offsetZ) -
          *(float *)&v87.radius;
      v87.bounds[1][2] = (float)(v87.extents.end[2] + *(float *)&v87.offsetZ) +
                         *(float *)&v87.radius;
    }
  v87.axialCullOnly =
      (float)((float)((float)((float)(v16 * v87.size[1]) * v87.size[2]) *
                      16.0) *
              *(float *)&v87.deltaLen) >
      (float)((float)(v87.bounds[1][2] - v87.bounds[0][2]) *
              (float)((float)(v87.bounds[1][0] - v87.bounds[0][0]) *
                      (float)(v87.bounds[1][1] - v87.bounds[0][1])));
  Value = (int32_t *)Sys_GetValue(3);
  v23 = *Value + 1;
  *Value = v23;
  v87.threadInfo.checkcount.global = v23;
  v87.threadInfo.checkcount.edges = Value[1];
  v87.threadInfo.checkcount.verts = Value[2];
  v87.threadInfo.checkcount.partitions = Value[3];
  v87.threadInfo.box_brush = Value[4];
  *(_DWORD *)v87.threadInfo.box_model = Value[5];
    if (*a2 == *a3 && a2[1] == a3[1] && a2[2] == a3[2]) {
      v87.isPoint = 0;
        if (a6) {
            if (a6 == (const float *)1023) {
                if ((*(_DWORD *)(v87.threadInfo.box_brush + 12) &
                     v87.contents) != 0) {
                  v40 = v87.extents.start[0];
                  v41 = v87.extents.start[1];
                  v72 = v87.extents.start[2];
                  v85 = v87.extents.start[2] + *(float *)&v87.offsetZ;
                  v81 = v87.extents.start[2] - *(float *)&v87.offsetZ;
                  v42 = *(float **)v87.threadInfo.box_model;
                  v43 = 1;
                  v44 = 1;
                    do {
                      v45 = *v42;
                      v46 = v42[3];
                      v47 = (float)(*v42 + v46) * 0.5;
                      v88.halfDeltaAbs[v44 - 2] = v47;
                      v86.extents.start[v44 - 1] = v45 - v47;
                      v86.extents.start[v44 + 2] = v46 - v47;
                      ++v43;
                      ++v44;
                      ++v42;
                    }
                  while (v43 != 4);
                  v48 = fminf(v86.extents.end[2], v86.extents.end[0]);
                  v49 = v86.extents.end[2] - v48;
                  v50 = (float)(v48 + *(float *)&v87.radius) *
                        (float)(v48 + *(float *)&v87.radius);
                  v84 = v88.halfDelta[2];
                  v83 = v88.halfDeltaAbs[0];
                  v82 = v88.halfDeltaAbs[1];
                  v51 = v88.halfDeltaAbs[1] + v49;
                  v52 = (float)((float)(v88.halfDelta[2] - v40) *
                                (float)(v88.halfDelta[2] - v40)) +
                        (float)((float)(v88.halfDeltaAbs[0] - v41) *
                                (float)(v88.halfDeltaAbs[0] - v41));
                    if (v50 >
                        (float)((float)((float)((float)(v88.halfDeltaAbs[1] +
                                                        v49) -
                                                v85) *
                                        (float)((float)(v88.halfDeltaAbs[1] +
                                                        v49) -
                                                v85)) +
                                v52)) {
                      *(_BYTE *)(a1 + 34) = 1;
                      *(_BYTE *)(a1 + 35) = 1;
                      *(_DWORD *)a1 = 0;
                    }
                    if (v50 > (float)((float)((float)(v51 - v81) *
                                              (float)(v51 - v81)) +
                                      v52)) {
                      *(_BYTE *)(a1 + 34) = 1;
                      *(_BYTE *)(a1 + 35) = 1;
                      *(_DWORD *)a1 = 0;
                    }
                    if (v50 >
                        (float)((float)((float)((float)(v82 - v49) - v85) *
                                        (float)((float)(v82 - v49) - v85)) +
                                v52)) {
                      *(_BYTE *)(a1 + 34) = 1;
                      *(_BYTE *)(a1 + 35) = 1;
                      *(_DWORD *)a1 = 0;
                    }
                    if (v50 >
                        (float)(v52 +
                                (float)((float)((float)(v82 - v49) - v81) *
                                        (float)((float)(v82 - v49) - v81)))) {
                      *(_BYTE *)(a1 + 34) = 1;
                      *(_BYTE *)(a1 + 35) = 1;
                      *(_DWORD *)a1 = 0;
                    }
                    if ((float)((float)(v49 + v87.size[2]) -
                                *(float *)&v87.radius) >=
                            fabs(v72 - v88.halfDeltaAbs[1]) &&
                        v50 > (float)((float)((float)((float)(v40 - v84) *
                                                      (float)(v40 - v84)) +
                                              (float)((float)(v41 - v83) *
                                                      (float)(v41 - v83))) +
                                      0.0)) {
                      *(_BYTE *)(a1 + 34) = 1;
                      *(_BYTE *)(a1 + 35) = 1;
                      *(_DWORD *)a1 = 0;
                    }
                }
            }
            else if (!*(_BYTE *)(a1 + 34)) {
              contents = v87.contents;
                if ((v87.contents & *(_DWORD *)(v75 + 32)) != 0) {
                  v37 = v75 + 28;
                  v38 = 0;
                  v39 = 0;
                    while (*(float *)(v37 + 12) < v87.bounds[1][v39] &&
                           v87.bounds[0][v39] < *(float *)(v37 + 24)) {
                      ++v38;
                      ++v39;
                      v37 += 4;
                        if (v38 == 3) {
                          CM_TestInLeafBrushNode_r(
                              (int)&v87,
                              (unsigned __int8 *)(unk_1007E50 +
                                                  20 * *(_DWORD *)(v75 + 64)),
                              a1);
                          if (*(_BYTE *)(a1 + 34))
                            return;
                          contents = v87.contents;
                          break;
                        }
                    }
                }
              if ((contents & *(_DWORD *)(v75 + 36)) != 0)
                CM_MeshTestInLeaf(&v87, (cLeaf_t *)(v75 + 28), (trace_t *)a1);
            }
        }
        else if (!*(_BYTE *)(a1 + 34)) {
          v88.extents.end[1] = v87.extents.start[0] - v87.size[0];
          v88.extents.end[2] = v87.extents.start[1] - v87.size[1];
          v88.extents.invDelta[0] = v87.extents.start[2] - v87.size[2];
          v88.extents.invDelta[1] = v87.extents.start[0] + v87.size[0];
          v88.extents.invDelta[2] = v87.extents.start[1] + v87.size[1];
          v88.delta[0] = v87.extents.start[2] + v87.size[2];
          v25 = &v88;
            do {
              v25->extents.end[1] = v25->extents.end[1] - 1.0;
              v25->extents.invDelta[1] = v25->extents.invDelta[1] + 1.0;
              v25 = (traceWork_t *)((char *)v25 + 4);
            }
          while ((traceWork_t *)v88.extents.end != v25);
          v88.extents.start[0] = 0.0;
          LODWORD(v88.extents.start[1]) = 1024;
          LODWORD(v88.extents.end[0]) = &v86;
          v88.delta[1] = 0.0;
          v88.extents.start[2] = 0.0;
          CM_BoxLeafnums_r((leafList_s *)&v88, 0);
            if (SLODWORD(v88.extents.start[0]) > 0 && !*(_BYTE *)(a1 + 34)) {
              v26 = 0;
                do {
                  v27 = (cLeaf_t *)(dword_1007E48 +
                                    44 * LODWORD(v86.extents.start[v26]));
                  v28 = v87.contents;
                    if ((v87.contents & v27->brushContents) != 0) {
                      v29 =
                          dword_1007E48 + 44 * LODWORD(v86.extents.start[v26]);
                      v30 = 0;
                      v31 = 0;
                        while (*(float *)(v29 + 12) < v87.bounds[1][v31] &&
                               v87.bounds[0][v31] < *(float *)(v29 + 24)) {
                          ++v30;
                          ++v31;
                          v29 += 4;
                            if (v30 == 3) {
                              CM_TestInLeafBrushNode_r(
                                  (int)&v87,
                                  (unsigned __int8 *)(unk_1007E50 +
                                                      20 * v27->leafBrushNode),
                                  a1);
                              if (*(_BYTE *)(a1 + 34))
                                goto LABEL_31;
                              v28 = v87.contents;
                              break;
                            }
                        }
                    }
                  if ((v28 & v27->terrainContents) != 0)
                    CM_MeshTestInLeaf(&v87, v27, (trace_t *)a1);
                LABEL_31:
                  ++v26;
                }
              while (SLODWORD(v88.extents.start[0]) > v26 &&
                     !*(_BYTE *)(a1 + 34));
            }
        }
      return;
    }
  v87.isPoint =
      (float)((float)(v87.size[0] + v87.size[1]) + v87.size[2]) == 0.0;
  v32 = *(float *)&v87.radius;
  LODWORD(v87.radiusOffset[0]) = v87.radius;
  LODWORD(v87.radiusOffset[1]) = v87.radius;
  v87.radiusOffset[2] = *(float *)&v87.radius + *(float *)&v87.offsetZ;
    if (!a6) {
      v88.delta[2] = v87.extents.start[0];
      v88.deltaLen = LODWORD(v87.extents.start[1]);
      v88.deltaLenSq = LODWORD(v87.extents.start[2]);
      v88.midpoint[0] = 0.0;
      v88.midpoint[1] = v87.extents.end[0];
      v88.midpoint[2] = v87.extents.end[1];
      v88.halfDelta[0] = v87.extents.end[2];
      v88.halfDelta[1] = *(float *)a1;
      CM_TraceThroughTree(&v87, 0, &v88.delta[2],
                          (traceWork_t *)&v88.midpoint[1], (trace_t *)a1);
      return;
    }
    if (a6 == (const float *)1023) {
        if ((*(_DWORD *)(v87.threadInfo.box_brush + 12) & v87.contents) == 0 ||
            v87.bounds[0][0] >
                (float)(*(float *)(*(_DWORD *)v87.threadInfo.box_model + 12) +
                        1.0) ||
            v87.bounds[0][1] >
                (float)(*(float *)(*(_DWORD *)v87.threadInfo.box_model + 16) +
                        1.0) ||
            v87.bounds[0][2] >
                (float)(*(float *)(*(_DWORD *)v87.threadInfo.box_model + 20) +
                        1.0) ||
            (float)(**(float **)v87.threadInfo.box_model - 1.0) >
                v87.bounds[1][0] ||
            (float)(*(float *)(*(_DWORD *)v87.threadInfo.box_model + 4) - 1.0) >
                v87.bounds[1][1] ||
            (float)(*(float *)(*(_DWORD *)v87.threadInfo.box_model + 8) - 1.0) >
                v87.bounds[1][2]) {
          return;
        }
      v53 = v87.extents.start[0];
      v88.axialCullOnly = LODWORD(v87.extents.start[0]);
      v54 = v87.extents.start[1];
      v88.radius = LODWORD(v87.extents.start[1]);
      v73 = v87.extents.start[2];
      *(float *)&v88.offsetZ = v87.extents.start[2] + *(float *)&v87.offsetZ;
      v88.bounds[1][2] = v87.extents.start[0];
      v88.contents = LODWORD(v87.extents.start[1]);
      *(float *)&v88.isPoint = v87.extents.start[2] - *(float *)&v87.offsetZ;
      v88.bounds[0][2] = v87.extents.end[0];
      v88.bounds[1][0] = v87.extents.end[1];
      v88.bounds[1][1] = v87.extents.end[2] + *(float *)&v87.offsetZ;
      v88.size[2] = v87.extents.end[0];
      v88.bounds[0][0] = v87.extents.end[1];
      v88.bounds[0][1] = v87.extents.end[2] - *(float *)&v87.offsetZ;
      v55 = *(float **)v87.threadInfo.box_model;
      v56 = 1;
      v57 = 1;
        do {
          v58 = *v55;
          v59 = v55[3];
          v60 = (float)(*v55 + v59) * 0.5;
          v88.size[v57 - 2] = v60;
          v88.extents.start[v57 - 1] = v58 - v60;
          v88.extents.start[v57 + 2] = v59 - v60;
          ++v56;
          ++v57;
          ++v55;
        }
      while (v56 != 4);
      v79 = fminf(v88.extents.end[2], v88.extents.end[0]);
      v80 = v88.extents.end[2] - v79;
      v76 = v88.halfDeltaAbs[2];
      v86.extents.start[0] = v88.halfDeltaAbs[2];
      v77 = v88.size[0];
      v86.extents.start[1] = v88.size[0];
      v78 = v88.size[1];
      v86.extents.start[2] = (float)(v88.extents.end[2] - v79) + v88.size[1];
      v88.radiusOffset[0] = v88.halfDeltaAbs[2];
      v88.radiusOffset[1] = v88.size[0];
      v88.radiusOffset[2] = v88.size[1] - (float)(v88.extents.end[2] - v79);
        if (*(float *)&v88.isPoint > v86.extents.start[2]) {
            if (!CM_TraceSphereThroughSphere((int)&v87, &v88.bounds[1][2],
                                             &v88.size[2], v79, &v86,
                                             (float *)a1) ||
                v87.delta[2] >= 0.0) {
              return;
            }
        }
        else {
          if ((float)(v88.size[1] - (float)(v88.extents.end[2] - v79)) <=
              *(float *)&v88.offsetZ)
            goto LABEL_87;
            if (!CM_TraceSphereThroughSphere(
                    (int)&v87, (float *)&v88.axialCullOnly, &v88.bounds[0][2],
                    v79, (traceWork_t *)v88.radiusOffset, (float *)a1) ||
                v87.delta[2] <= 0.0) {
              return;
            }
        }
      v73 = v87.extents.start[2];
      v53 = v87.extents.start[0];
      v54 = v87.extents.start[1];
      v32 = *(float *)&v87.radius;
    LABEL_87:
      v61 = v53 - v76;
      v88.halfDelta[2] = v53 - v76;
      v62 = v54 - v77;
      v88.halfDeltaAbs[0] = v54 - v77;
      v88.halfDeltaAbs[1] = v73 - v78;
      v63 = (float)((float)(v61 * v61) + (float)(v62 * v62)) -
            (float)((float)(v79 + v32) * (float)(v79 + v32));
        if (v63 <= 0.0) {
          v65 = (float)(v87.size[2] - v32) + v80;
            if (fabs(v73 - v78) <= v65) {
              *(_DWORD *)a1 = 0;
              *(_BYTE *)(a1 + 35) = 1;
              v88.halfDeltaAbs[1] = 0.0;
              Vec3NormalizeTo(&v88.halfDelta[2], (float *)(a1 + 4));
              *(_DWORD *)(a1 + 20) = *(_DWORD *)(v87.threadInfo.box_brush + 12);
              v88.halfDelta[2] = v87.extents.end[0] - v76;
              v88.halfDeltaAbs[0] = v87.extents.end[1] - v77;
              v88.halfDeltaAbs[1] = v87.extents.end[2] - v78;
              if (v65 >= fabs(v87.extents.end[2] - v78))
                *(_BYTE *)(a1 + 34) = 1;
              return;
            }
        }
        else {
          v64 = (float)(v61 * v87.delta[0]) + (float)(v62 * v87.delta[1]);
            if (v64 < 0.0) {
              v66 = (float)(v87.delta[0] * v87.delta[0]) +
                    (float)(v87.delta[1] * v87.delta[1]);
              v67 = v63 * v66;
                if ((float)((float)(v64 * v64) - v67) >= 0.0) {
                  v88.halfDeltaAbs[1] = 0.0;
                  v71 = (float)(v64 * v64) - v67;
                  v70 = Vec3NormalizeTo(
                      &v88.halfDelta[2],
                      (float *)&v88.threadInfo.checkcount.global);
                  v68 = (float)(v70 * 0.125) / v64;
                  v69 = (float)((float)((float)-v64 - fsqrt(v71)) / v66) + v68;
                    if (*(float *)a1 > v69 &&
                        fabs(
                            (float)((float)((float)(v69 - v68) * v87.delta[2]) +
                                    v87.extents.start[2]) -
                            v78) <= (float)((float)(v87.size[2] -
                                                    *(float *)&v87.radius) +
                                            v80)) {
                      *(float *)a1 = fmaxf(0.0, v69);
                      *(_DWORD *)(a1 + 4) = v88.threadInfo.checkcount.global;
                      *(_DWORD *)(a1 + 8) = v88.threadInfo.checkcount.edges;
                      *(_DWORD *)(a1 + 12) = v88.threadInfo.checkcount.verts;
                      *(_DWORD *)(a1 + 20) =
                          *(_DWORD *)(v87.threadInfo.box_brush + 12);
                      return;
                    }
                }
            }
        }
        if (v88.bounds[0][1] <= v86.extents.start[2]) {
          if (v88.radiusOffset[2] > v88.bounds[1][1] &&
              *(float *)&v88.offsetZ >= v88.radiusOffset[2])
            CM_TraceSphereThroughSphere(
                (int)&v87, (float *)&v88.axialCullOnly, &v88.bounds[0][2], v79,
                (traceWork_t *)v88.radiusOffset, (float *)a1);
        }
        else if (v86.extents.start[2] >= *(float *)&v88.isPoint) {
          CM_TraceSphereThroughSphere((int)&v87, &v88.bounds[1][2],
                                      &v88.size[2], v79, &v86, (float *)a1);
        }
      return;
    }
  if (*(float *)a1 == 0.0)
    return;
  v33 = v87.contents;
    if ((v87.contents & *(_DWORD *)(v75 + 32)) != 0) {
      if (CM_TraceThroughLeafBrushNode((int)&v87, v75 + 28, (unsigned int *)a1))
        return;
      v33 = v87.contents;
    }
    if ((v33 & *(_DWORD *)(v75 + 36)) != 0 && *(_WORD *)(v75 + 30) &&
        *(float *)a1 != 0.0) {
      v34 = 0;
        for (i = (trace_t *)a1;; i = (trace_t *)a1) {
          CM_TraceThroughAabbTree(
              &v87,
              (CollisionAabbTree *)(unk_1007E90 +
                                    32 * (v34 +
                                          *(unsigned __int16 *)(v75 + 28))),
              i);
          if (++v34 >= *(unsigned __int16 *)(v75 + 30) || *(float *)a1 == 0.0)
            break;
        }
    }
}
