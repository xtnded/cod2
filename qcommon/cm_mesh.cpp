bool __cdecl CM_RayTriangleIntersect(float const *const, float const *const,
                                     float const *const, float const *const,
                                     float const *const, float *, float *,
                                     float *) {
  UNIMPLEMENTED();
}

void __cdecl CM_MeshTestInLeaf(struct traceWork_t const *tw,
                               struct cLeaf_t *leaf, struct trace_t *trace) {
  int32_t result;       // eax
  int collAabbCount;    // ecx
  int v5;               // esi
  int v6;               // ebx
  int32_t v7;           // edi
  int v8;               // ecx
  _WORD *v9;            // ebx
  unsigned __int8 *v10; // ebx
  int v11;              // esi
  int v12;              // esi
  int32_t global;       // [esp+0h] [ebp-28h]
  int v14;              // [esp+4h] [ebp-24h]
  int v15;              // [esp+8h] [ebp-20h]
  int v16;              // [esp+Ch] [ebp-1Ch]

  result = (int32_t)a2;
  collAabbCount = a2->collAabbCount;
  if (a2->collAabbCount) {
    v14 = 0;
    while (1) {
      while (1) {
        v5 = unk_1007E90;
        v6 = unk_1007E90 + 32 * (v14 + a2->firstCollAabbIndex);
        v7 = unk_1007E30 + 72 * *(unsigned __int16 *)(v6 + 24);
        result = a1->contents;
        if ((result & *(_DWORD *)(v7 + 68)) != 0)
          break;
        if (++v14 >= collAabbCount)
          return result;
      }
      if (!CM_CullBox(
              (int)a1,
              (float *)(unk_1007E90 + 32 * (v14 + a2->firstCollAabbIndex)),
              (float *)(v6 + 12))) {
        if (*(_WORD *)(v6 + 26)) {
          v11 = 32 * *(_DWORD *)(v6 + 28) + v5;
          v15 = 0;
          do {
            CM_PositionTestInAabbTree_r((int)a1, v11, (int)a3);
            ++v15;
            v11 += 32;
          } while (v15 < *(unsigned __int16 *)(v6 + 26));
        } else {
          global = a1->threadInfo.checkcount.global;
          v8 = *(_DWORD *)(v6 + 28);
          v9 = (_WORD *)(a1->threadInfo.checkcount.partitions + 2 * v8);
          if ((unsigned __int16)*v9 != (__int16)global) {
            *v9 = global;
            v10 = (unsigned __int8 *)(unk_1007E88 + 12 * v8);
            if (*v10) {
              v16 = 0;
              v12 = 0;
              do {
                CM_PositionTestCapsuleInTriangle(
                    a1->extents.start, (float *)(*((_DWORD *)v10 + 1) + v12),
                    (int)a3);
                ++v16;
                v12 += 72;
              } while (*v10 > v16);
            }
          }
        }
      }
      result = (int32_t)a3;
      if (a3->allsolid)
        break;
      collAabbCount = a2->collAabbCount;
      if (++v14 >= collAabbCount)
        return result;
    }
    a3->surfaceFlags = *(_DWORD *)(v7 + 64);
    result = *(_DWORD *)(v7 + 68);
    a3->contents = result;
    a3->material = v7;
  }
  return result;
}

void __cdecl CM_TraceThroughAabbTree(struct traceWork_t const *tw,
                                     struct CollisionAabbTree *aabbTree,
                                     struct trace_t *trace) {
  int32_t v3;     // ebx
  int32_t result; // eax
  float fraction; // [esp+Ch] [ebp-1Ch]

  v3 = unk_1007E30 + 72 * a2->materialIndex;
  result = a1->contents;
  if ((result & *(_DWORD *)(v3 + 68)) != 0) {
    fraction = a3->fraction;
    CM_TraceThroughAabbTree_r((int)a1, (int)a2, (int)a3);
    result = (int32_t)a3;
    if (fraction > a3->fraction) {
      a3->surfaceFlags = *(_DWORD *)(v3 + 64);
      result = *(_DWORD *)(v3 + 68);
      a3->contents = result;
      a3->material = v3;
    }
  }
  return result;
}

void __cdecl CM_SightTraceThroughAabbTree(struct traceWork_t const *tw,
                                          struct CollisionAabbTree *aabbTree,
                                          struct trace_t *trace) {
  int32_t v3;     // ebx
  int32_t result; // eax
  float fraction; // [esp+Ch] [ebp-1Ch]

  v3 = unk_1007E30 + 72 * a2->materialIndex;
  result = a1->contents;
  if ((result & *(_DWORD *)(v3 + 68)) != 0) {
    fraction = a3->fraction;
    CM_TraceThroughAabbTree_r((int)a1, (int)a2, (int)a3);
    result = (int32_t)a3;
    if (fraction > a3->fraction) {
      a3->surfaceFlags = *(_DWORD *)(v3 + 64);
      result = *(_DWORD *)(v3 + 68);
      a3->contents = result;
      a3->material = v3;
    }
  }
  return result;
}

int marker_cm_mesh;
void __cdecl CM_TracePointThroughTriangle(struct traceWork_t const *,
                                          struct CollisionTriangle const *,
                                          struct trace_t *) {
  UNIMPLEMENTED();
}

void __cdecl CM_TraceCapsuleThroughBorder(struct traceWork_t const *,
                                          struct CollisionBorder *,
                                          struct trace_t *) {
  UNIMPLEMENTED();
}

void __cdecl CM_TraceCapsuleThroughTriangle(struct traceWork_t const *,
                                            struct CollisionTriangle const *,
                                            float, struct trace_t *) {
  int v8;      // eax
  float v9;    // xmm7_4
  float v10;   // xmm2_4
  float v11;   // xmm6_4
  float v12;   // xmm5_4
  float v13;   // xmm1_4
  float v14;   // xmm3_4
  float v15;   // xmm1_4
  float v16;   // xmm0_4
  float v17;   // xmm7_4
  float v18;   // xmm5_4
  float v19;   // xmm4_4
  float v20;   // xmm2_4
  float v21;   // xmm1_4
  float v22;   // xmm0_4
  float v23;   // xmm0_4
  float v24;   // xmm1_4
  float v25;   // xmm0_4
  float v26;   // xmm0_4
  float v27;   // xmm6_4
  float v28;   // xmm5_4
  float v29;   // xmm2_4
  float v30;   // xmm4_4
  float v31;   // xmm1_4
  float v32;   // xmm0_4
  int v33;     // edx
  _DWORD *v34; // ecx
  int v35;     // eax
  float *v36;  // edx
  float v37;   // xmm3_4
  float v38;   // xmm4_4
  float v39;   // xmm1_4
  float v40;   // xmm2_4
  float v41;   // xmm6_4
  float v42;   // xmm5_4
  float v43;   // xmm3_4
  float v44;   // xmm1_4
  int v45;     // edx
  _DWORD *v46; // ecx
  int v47;     // eax
  float *v48;  // eax
  float v49;   // xmm3_4
  float v50;   // xmm4_4
  float v51;   // xmm5_4
  float v52;   // xmm6_4
  float v53;   // xmm1_4
  float v54;   // xmm0_4
  float v55;   // xmm2_4
  float v56;   // xmm3_4
  float v57;   // xmm1_4
  float v58;   // xmm4_4
  float v59;   // xmm2_4
  float v60;   // xmm4_4
  float v61;   // xmm0_4
  float v62;   // xmm0_4
  float v63;   // xmm2_4
  float v64;   // xmm2_4
  float v65;   // xmm0_4
  float v66;   // xmm0_4
  float v67;   // xmm1_4
  float v68;   // [esp+40h] [ebp-78h]
  float v69;   // [esp+44h] [ebp-74h]
  int v70;     // [esp+48h] [ebp-70h]
  float v71;   // [esp+4Ch] [ebp-6Ch]
  float v72;   // [esp+50h] [ebp-68h]
  float v73;   // [esp+54h] [ebp-64h]
  float v74;   // [esp+58h] [ebp-60h]
  float v75;   // [esp+5Ch] [ebp-5Ch]
  _DWORD *v76; // [esp+60h] [ebp-58h]
  _DWORD *v77; // [esp+64h] [ebp-54h]
  float v78;   // [esp+68h] [ebp-50h]
  float v79;   // [esp+6Ch] [ebp-4Ch]
  float v80;   // [esp+70h] [ebp-48h]
  float *v81;  // [esp+74h] [ebp-44h]
  float v82;   // [esp+78h] [ebp-40h]
  float v83;   // [esp+7Ch] [ebp-3Ch]
  float v84;   // [esp+80h] [ebp-38h]
  float *v85;  // [esp+84h] [ebp-34h]
  float v86;   // [esp+88h] [ebp-30h]
  float v87;   // [esp+8Ch] [ebp-2Ch]
  float v88;   // [esp+90h] [ebp-28h]
  float v89;   // [esp+94h] [ebp-24h]
  int v90;     // [esp+98h] [ebp-20h]
  float v91;   // [esp+9Ch] [ebp-1Ch]

  v8 = a1 + 12;
  v9 = *(float *)(v8 + 8) - a4;
  v71 = *(float *)(a1 + 140) + 0.125;
  v75 = *a2;
  v76 = a2 + 1;
  v10 = a2[1];
  v77 = a2 + 2;
  v11 = a2[2];
  v12 = a2[3];
  v13 = (float)((float)((float)(*a2 * *(float *)(a1 + 12)) +
                        (float)(v10 * *(float *)(v8 + 4))) +
                (float)(v9 * v11)) -
        v12;
  if (v13 < v71) {
    v83 = *(float *)a1;
    v82 = *(float *)(a1 + 4);
    v91 = *(float *)(a1 + 8) - a4;
    v14 = (float)((float)((float)(v75 * *(float *)a1) + (float)(v10 * v82)) +
                  (float)(v91 * v11)) -
          v12;
    v15 = v14 - v13;
    if (v15 > 0.000099999997) {
      v16 = -v71;
      if ((float)-v71 < v14) {
        v26 = v14 - v71;
        if ((float)(v14 - v71) <= 0.0) {
          v27 = 0.0;
          v30 = *(float *)(a1 + 8) - a4;
          v29 = *(float *)(a1 + 4);
          v28 = *(float *)a1;
        } else {
          v27 = v26 / v15;
          if ((float)(v26 / v15) > *(float *)a3)
            return;
          v28 = (float)(v27 * *(float *)(a1 + 36)) + v83;
          v29 = (float)(v27 * *(float *)(a1 + 40)) + v82;
          v30 = (float)(v27 * *(float *)(a1 + 44)) + v91;
        }
        v31 = (float)((float)((float)(v28 * a2[4]) + (float)(v29 * a2[5])) +
                      (float)(v30 * a2[6])) -
              a2[7];
        v32 = (float)((float)((float)(v28 * a2[8]) + (float)(v29 * a2[9])) +
                      (float)(v30 * a2[10])) -
              a2[11];
        v90 =
            ((float)(v31 + v32) > 1.0) | (2 * (v31 < 0.0)) | (4 * (v32 < 0.0));
        if (v90) {
          v69 = v71 * v71;
          v85 = a2;
          v70 = 0;
          v81 = (float *)(a3 + 4);
          if (COERCE_UNSIGNED_INT(v31 + v32) <= COERCE_UNSIGNED_INT(1.0))
            goto LABEL_27;
        LABEL_22:
          v33 = *((_DWORD *)v85 + 15);
          if (v33 < 0)
            goto LABEL_25;
          v34 = (_DWORD *)(*(_DWORD *)(a1 + 164) + 4 * v33);
          v35 = *(_DWORD *)(a1 + 160);
          if (*v34 == v35)
            goto LABEL_25;
          *v34 = v35;
          v36 = (float *)(unk_1007E70 + 48 * v33);
          v89 = v83 - *v36;
          v88 = v82 - v36[1];
          v87 = v91 - v36[2];
          v37 = v36[4];
          v38 = v36[5];
          v84 = (float)(v87 * v38) +
                (float)((float)(v88 * v37) + (float)(v89 * v36[3]));
          v39 = v36[7];
          v40 = v36[8];
          v41 = (float)((float)(v89 * v36[6]) + (float)(v88 * v39)) +
                (float)(v87 * v40);
          v78 = *(float *)(a1 + 36);
          v79 = *(float *)(a1 + 40);
          v80 = *(float *)(a1 + 44);
          v42 = (float)((float)(v78 * v36[3]) + (float)(v37 * v79)) +
                (float)(v38 * v80);
          v43 = (float)((float)(v78 * v36[6]) + (float)(v39 * v79)) +
                (float)(v40 * v80);
          v44 = (float)(v84 * v42) + (float)(v41 * v43);
          if (v44 >= 0.0)
            goto LABEL_25;
          v58 = (float)(v84 * v84) + (float)(v41 * v41);
          v59 = v58 - v69;
          if ((float)(v58 - v69) <= 0.0) {
            if (fabs((float)((float)((float)(v89 * v36[9]) +
                                     (float)(v88 * v36[10])) +
                             (float)(v87 * v36[11])) -
                     0.5) > 0.5)
              goto LABEL_25;
            *(float *)(a3 + 4) = v84 * v36[3];
            *(float *)(a3 + 8) = v84 * v36[4];
            *(float *)(a3 + 12) = v84 * v36[5];
            *(float *)(a3 + 4) = (float)(v41 * v36[6]) + *(float *)(a3 + 4);
            *(float *)(a3 + 8) = (float)(v41 * v36[7]) + v81[1];
            *(float *)(a3 + 12) = (float)(v41 * v36[8]) + v81[2];
            Vec3Normalize(v81);
            if (a2[2] >= 0.69999999) {
              v65 = *(float *)(a3 + 12);
              if (v65 >= 0.0 && v65 < 0.69999999 && v91 > v9) {
                *(float *)(a3 + 4) = *a2;
                *(_DWORD *)(a3 + 8) = *v76;
                *(_DWORD *)(a3 + 12) = *v77;
              }
            }
            *(_DWORD *)a3 = 0;
            if ((float)(*(float *)(a1 + 140) * *(float *)(a1 + 140)) > v58)
              *(_BYTE *)(a3 + 35) = 1;
          } else {
            v60 = (float)(v42 * v42) + (float)(v43 * v43);
            v61 = (float)(v44 * v44) - (float)(v59 * v60);
            if (v61 > 0.0) {
              v86 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(fsqrt(v61)) ^
                                         0x80000000) -
                            v44) /
                    v60;
              if (*(float *)a3 > v86 &&
                  fabs((float)((float)((float)((float)(v89 +
                                                       (float)(v78 * v86)) *
                                               v36[9]) +
                                       (float)((float)(v88 +
                                                       (float)(v79 * v86)) *
                                               v36[10])) +
                               (float)((float)(v87 + (float)(v80 * v86)) *
                                       v36[11])) -
                       0.5) <= 0.5) {
                v62 = (float)((float)(v86 * v42) + v84) / v71;
                v63 = (float)((float)(v86 * v43) + v41) / v71;
                *(float *)(a3 + 4) = v62 * v36[3];
                *(float *)(a3 + 8) = v62 * v36[4];
                *(float *)(a3 + 12) = v62 * v36[5];
                *(float *)(a3 + 4) = (float)(v63 * v36[6]) + *(float *)(a3 + 4);
                *(float *)(a3 + 8) = (float)(v63 * v36[7]) + v81[1];
                v64 = (float)(v63 * v36[8]) + v81[2];
                *(float *)(a3 + 12) = v64;
                if (a2[2] >= 0.69999999 && v64 >= 0.0 && v64 < 0.69999999 &&
                    v91 > v9) {
                  *(float *)(a3 + 4) = *a2;
                  *(_DWORD *)(a3 + 8) = *v76;
                  *(_DWORD *)(a3 + 12) = *v77;
                }
                *(float *)a3 = v86;
              }
            }
          LABEL_25:
            while (1) {
              ++v70;
              ++v85;
              if (v70 == 3)
                break;
              if (((v90 >> v70) & 1) != 0)
                goto LABEL_22;
            LABEL_27:
              v45 = *((_DWORD *)v85 + 12);
              if (v45 >= 0) {
                v46 = (_DWORD *)(*(_DWORD *)(a1 + 168) + 4 * v45);
                v47 = *(_DWORD *)(a1 + 160);
                if (*v46 != v47) {
                  *v46 = v47;
                  v48 = (float *)(unk_1007E68 + 12 * v45);
                  v49 = v83 - *v48;
                  v50 = v82 - v48[1];
                  v51 = v91 - v48[2];
                  v52 = *(float *)(a1 + 36);
                  v53 = (float)((float)(v49 * v52) +
                                (float)(v50 * *(float *)(a1 + 40))) +
                        (float)(v51 * *(float *)(a1 + 44));
                  if (v53 < 0.0) {
                    v72 = (float)(v51 * v51) +
                          (float)((float)(v50 * v50) + (float)(v49 * v49));
                    if ((float)(v72 - v69) <= 0.0) {
                      v66 = fsqrt(v72);
                      *(float *)(a3 + 4) = v49 * (float)(1.0 / v66);
                      *(float *)(a3 + 8) = v50 * (float)(1.0 / v66);
                      v67 = (float)(1.0 / v66) * v51;
                      *(float *)(a3 + 12) = v67;
                      if (a2[2] >= 0.69999999 && v67 >= 0.0 &&
                          v67 < 0.69999999 && v91 > v9) {
                        *(float *)(a3 + 4) = *a2;
                        *(_DWORD *)(a3 + 8) = *v76;
                        *(_DWORD *)(a3 + 12) = *v77;
                      }
                      *(_DWORD *)a3 = 0;
                      if ((float)(*(float *)(a1 + 140) * *(float *)(a1 + 140)) >
                          v72)
                        *(_BYTE *)(a3 + 35) = 1;
                      return;
                    }
                    v73 = *(float *)(a1 + 52);
                    v54 =
                        (float)(v53 * v53) - (float)((float)(v72 - v69) * v73);
                    if (v54 >= 0.0) {
                      v55 = (float)((float)-fsqrt(v54) - v53) / v73;
                      if (*(float *)a3 > v55) {
                        v56 = v49 + (float)(v52 * v55);
                        *(float *)(a3 + 4) = v56;
                        *(float *)(a3 + 8) =
                            v50 + (float)(v55 * *(float *)(a1 + 40));
                        *(float *)(a3 + 12) =
                            v51 + (float)(v55 * *(float *)(a1 + 44));
                        *(float *)(a3 + 4) = (float)(1.0 / v71) * v56;
                        *(float *)(a3 + 8) = (float)(1.0 / v71) * v81[1];
                        v57 = (float)(1.0 / v71) * v81[2];
                        *(float *)(a3 + 12) = v57;
                        if (a2[2] >= 0.69999999 && v57 >= 0.0 &&
                            v57 < 0.69999999 && v91 > v9) {
                          *(float *)(a3 + 4) = *a2;
                          *(_DWORD *)(a3 + 8) = *v76;
                          *(_DWORD *)(a3 + 12) = *v77;
                        }
                        *(float *)a3 = v55;
                      }
                    }
                  }
                }
              }
            }
          }
        } else {
          *(float *)(a3 + 4) = v75;
          *(_DWORD *)(a3 + 8) = *v76;
          *(_DWORD *)(a3 + 12) = *v77;
          *(float *)a3 = v27;
          if (*(float *)(a1 + 140) > v14)
            *(_BYTE *)(a3 + 35) = 1;
        }
      } else {
        v74 = a4 + a4;
        v17 = (float)((float)(a4 + a4) * v11) + v14;
        if (v16 < v17) {
          v18 = (float)(v16 - v14) / v11;
          v19 = (float)((float)((float)(v83 * a2[4]) + (float)(v82 * a2[5])) +
                        (float)(v91 * a2[6])) -
                a2[7];
          v20 = (float)((float)((float)(v83 * a2[8]) + (float)(v82 * a2[9])) +
                        (float)(v91 * a2[10])) -
                a2[11];
          v68 = a2[6];
          v21 = (float)(v68 * v18) + v19;
          if (v21 >= 0.0 && (v22 = (float)(v18 * a2[10]) + v20, v22 >= 0.0) &&
              (float)(v22 + v21) <= 1.0) {
            *(float *)(a3 + 4) = v75;
            *(float *)(a3 + 8) = a2[1];
            *(float *)(a3 + 12) = a2[2];
            *(_DWORD *)a3 = 0;
            *(_BYTE *)(a3 + 35) = 1;
          } else {
            if (v71 <= v17)
              v23 = (float)(v71 - v14) / v11;
            else
              v23 = v74;
            v24 = (float)(v68 * v23) + v19;
            if (v24 >= 0.0) {
              v25 = (float)(v23 * a2[10]) + v20;
              if (v25 >= 0.0 && (float)(v24 + v25) <= 1.0) {
                *(float *)(a3 + 4) = v75;
                *(_DWORD *)(a3 + 8) = *v76;
                *(_DWORD *)(a3 + 12) = *v77;
                *(_DWORD *)a3 = 0;
                *(_BYTE *)(a3 + 35) = 1;
              }
            }
          }
        }
      }
    }
  }
}

void __cdecl CM_PositionTestCapsuleInTriangle(struct traceWork_t const *,
                                              struct CollisionTriangle const *,
                                              struct trace_t *) {
  UNIMPLEMENTED();
}

bool __cdecl CM_CullBox(struct traceWork_t const *, float const *const,
                        float const *const) {
  UNIMPLEMENTED();
}

void __cdecl CM_PositionTestInAabbTree_r(struct traceWork_t const *,
                                         struct CollisionAabbTree *,
                                         struct trace_t *) {
  UNIMPLEMENTED();
}

void __cdecl CM_TraceThroughAabbTree_r(struct traceWork_t const *,
                                       struct CollisionAabbTree *,
                                       struct trace_t *) {
  UNIMPLEMENTED();
}
