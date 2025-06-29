float __cdecl SIGN(float) { UNIMPLEMENTED(); }

void __cdecl NormalizeQuatTrans(struct DObjAnimMat_s *) { UNIMPLEMENTED(); }

void __cdecl LocalMatrixTransformVectorQuatTransEquals(
    float *const, struct DObjAnimMat_s const *) {
  UNIMPLEMENTED();
}

void __cdecl LocalQuatMultiplyEquals(float *const, float const *const) {
  UNIMPLEMENTED();
}

void __cdecl LocalQuatMultiplyReverseEquals(float const *const, float *const) {
  UNIMPLEMENTED();
}

void __cdecl DObjUnlock(struct DObj_s const *) { UNIMPLEMENTED(); }

void __cdecl DObjLock(struct DObj_s const *) { UNIMPLEMENTED(); }

void __cdecl DObjSetModel(struct DObj_s *obj, struct XModel const *model) {
  int result; // eax

  a1->skel = a2->parts + 20;
  result = *(unsigned __int16 *)a2->parts;
  a1->numBones = result;
  *(_DWORD *)a1->models = a2;
  return result;
}

int __cdecl DObjHasContents(struct DObj_s *obj, int contentmask) {
  DObj_s *v3; // ebx
  int v4;     // esi

  if (!a1->numModels)
    return 0;
  v3 = a1;
  v4 = 0;
  while ((XModelGetContents(*(const XModel **)v3->models) & a2) == 0) {
    ++v4;
    v3 = (DObj_s *)((char *)v3 + 4);
    if (a1->numModels <= v4)
      return 0;
  }
  return 1;
}

int __cdecl DObjNumBones(struct DObj_s const *obj) { return a1->numBones; }

struct XAnimTree_s *__cdecl DObjGetTree(struct DObj_s const *obj) {
  return a1->tree;
}

struct XSurface_s *__cdecl DObjGetSurface(struct DObj_s const *obj,
                                          int modelIndex, int subMatIndex,
                                          int lod) {
  return *(
      _DWORD *)(**(_DWORD **)(*(_DWORD *)&a1->models[4 * a2] + 20 * a4 + 20) +
                4 * a3);
}

int __cdecl DObjGetNumSurfaces(struct DObj_s const *obj, char *lods) {
  int v2;   // eax
  char *v3; // ebx
  int v4;   // esi
  char *v5; // ecx
  int v7;   // [esp+0h] [ebp-10h]

  v2 = a1->numModels - 1;
  if (v2 < 0)
    return 0;
  v3 = &a1->models[4 * v2];
  v7 = 0;
  v4 = 0;
  v5 = &a2[v2];
  do {
    if (*v5 >= 0) {
      if (*(_DWORD *)(*(_DWORD *)v3 + 20 * (unsigned __int8)*v5 + 20))
        v7 += *(__int16 *)(*(_DWORD *)v3 + 20 * (unsigned __int8)*v5 + 12);
    }
    --v4;
    --v5;
    v3 -= 4;
  } while (v4 != ~v2);
  return v7;
}

int __cdecl DObjSetControlRotTransIndex(struct DObj_s const *, int *const,
                                        int) {
  UNIMPLEMENTED();
}

int __cdecl DObjSetRotTransIndex(struct DObj_s const *, int *const, int) {
  UNIMPLEMENTED();
}

void __cdecl DObjGetBoneInfo(struct DObj_s const *obj,
                             struct XBoneInfo_s **boneInfo) {
  int result;        // eax
  const DObj_s *i;   // edx
  __int16 **v5;      // edi
  int v6;            // esi
  int v7;            // ecx
  int v8;            // edx
  int v9;            // [esp+0h] [ebp-14h]
  const DObj_s *v10; // [esp+4h] [ebp-10h]

  result = (int)a1;
  if (a1->numModels) {
    v10 = a1;
    v9 = 0;
    for (i = a1;; i = v10) {
      v5 = *(__int16 ***)i->models;
      v6 = **v5;
      if (v6 > 0) {
        v7 = 0;
        v8 = 0;
        do {
          *a2 = (XBoneInfo_s *)&v5[24][v8];
          ++v7;
          ++a2;
          v8 += 20;
        } while (v6 != v7);
      }
      ++v9;
      v10 = (const DObj_s *)((char *)v10 + 4);
      result = a1->numModels;
      if (v9 >= result)
        break;
    }
  }
  return result;
}

int __cdecl DObjGetMatOffset(struct DObj_s const *obj, int modelIndex) {
  return *((unsigned __int8 *)a1->matOffset + a2);
}

struct DObjAnimMat_s *__cdecl DObjGetRotTransArray(struct DObj_s const *obj) {
  int32_t result; // eax

  result = a1->skel;
  if (result)
    result += 48;
  return result;
}

struct XModel *__cdecl DObjGetModel(struct DObj_s const *obj, int modelIndex) {
  return *(_DWORD *)&a1->models[4 * a2];
}

int __cdecl DObjGetNumModels(struct DObj_s const *obj) { return a1->numModels; }

void __cdecl DObjCreateSkel(struct DObj_s const *obj, char *buf,
                            int timeStamp) {
  char *result; // eax
  int v4;       // edx

  a1->skel = (int32_t)a2;
  a1->timeStamp = a3;
  result = a2;
  v4 = 4;
  do {
    *(_DWORD *)result = 0;
    *((_DWORD *)result + 4) = 0;
    *((_DWORD *)result + 8) = 0;
    result += 4;
    --v4;
  } while (v4);
  return result;
}

void __cdecl DObjSkelClear(struct DObj_s const *obj) {
  const DObj_s *result; // eax

  result = a1;
  a1->timeStamp = 0;
  a1->skel = 0;
  return result;
}

int __cdecl DObjSkelExistsConst(struct DObj_s const *, int) { UNIMPLEMENTED(); }

int __cdecl DObjSkelExists(struct DObj_s const *obj, int timeStamp) {
  if (a1->timeStamp == a2)
    return a1->skel != 0;
  a1->skel = 0;
  return 0;
}

int __cdecl DObjGetAllocSkelSize(struct DObj_s const *obj) {
  return 32 * a1->numBones + 48;
}

void __cdecl DObjSetTree(struct DObj_s *, struct XAnimTree_s *) {
  UNIMPLEMENTED();
}

int __cdecl DObjSkelAreBonesUpToDate(struct DObj_s const *obj,
                                     int *const partBits) {
  int32_t skel; // edx
  int v3;       // ecx

  skel = a1->skel;
  v3 = 1;
  while ((~*(_DWORD *)(skel + 32) & a2[v3 - 1]) == 0) {
    ++v3;
    skel += 4;
    if (v3 == 5)
      return 1;
  }
  return 0;
}

int __cdecl DObjSkelIsBoneUpToDate(struct DObj_s *obj, int boneIndex) {
  return (*(int *)(a1->skel + 4 * (a2 >> 5) + 32) >> (a2 & 0x1F)) & 1;
}

bool __cdecl DObjIgnoreCollision(struct DObj_s const *obj, int modelIndex) {
  return ((int)(unsigned __int8)a1->ignoreCollision >> a2) & 1;
}

void __cdecl DObjAbort() { g_empty = 0; }

float __cdecl DObjGetLodOutDist(struct DObj_s const *obj) {
  const DObj_s *v2; // ebx
  int v3;           // esi
  float v4;         // xmm0_4
  float v5;         // xmm1_4
  float LodOutDist; // [esp+3Ch] [ebp-1Ch]

  if (!a1->numModels)
    return 0.0;
  v2 = a1;
  v3 = 0;
  v4 = 0.0;
  do {
    LodOutDist = XModelGetLodOutDist((const XModel *)*(_DWORD *)v2->models);
    v5 = fmaxf(LodOutDist, v4);
    v4 = v5;
    ++v3;
    v2 = (const DObj_s *)((char *)v2 + 4);
  } while (a1->numModels > v3);
  return v5;
}

int __cdecl DObjGetLodForDist(struct DObj_s const *obj, int modelIndex,
                              float dist) {
  return XModelGetLodForDist(*(const XModel **)&a1->models[4 * a2], a3);
}

int __cdecl DObjGetBoneIndex(struct DObj_s const *obj, unsigned int boneName) {
  const DObj_s *v3; // esi
  int v4;           // edi
  const XModel *v5; // ebx
  int BoneIndex;    // eax
  int numModels;    // [esp+18h] [ebp-20h]
  int v8;           // [esp+1Ch] [ebp-1Ch]

  numModels = a1->numModels;
  if (!a1->numModels)
    return -1;
  v3 = a1;
  v4 = 0;
  v8 = 0;
  while (1) {
    v5 = *(const XModel **)v3->models;
    BoneIndex = XModelGetBoneIndex(v5, a2);
    if (BoneIndex >= 0)
      break;
    v8 += *(__int16 *)v5->parts;
    ++v4;
    v3 = (const DObj_s *)((char *)v3 + 4);
    if (numModels == v4)
      return -1;
  }
  return v8 + BoneIndex;
}

void __cdecl DObjGetBounds(struct DObj_s const *obj, float *const mins,
                           float *const maxs) {
  int result; // eax

  *a2 = a1->mins[0];
  a2[1] = a1->mins[1];
  a2[2] = a1->mins[2];
  *a3 = a1->maxs[0];
  a3[1] = a1->maxs[1];
  result = LODWORD(a1->maxs[2]);
  *((_DWORD *)a3 + 2) = result;
  return result;
}

char const *__cdecl DObjGetBoneName(struct DObj_s const *, int) {
  UNIMPLEMENTED();
}

char const *__cdecl DObjGetSurfaceName(struct DObj_s *obj, int modelIndex,
                                       int subMatIndex, int lod) {
  unsigned __int16 v4; // ax

  v4 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)&a1->models[4 * a2] + 20 * a4 + 16) +
                  2 * a3);
  if (v4)
    return (const char *)SL_ConvertToString(v4);
  else
    return "DEFAULT";
}

void __cdecl DObjGetCreateParms(struct DObj_s const *,
                                struct DObjModel_s *const, unsigned short *,
                                struct XAnimTree_s **, unsigned short *) {
  UNIMPLEMENTED();
}

void __cdecl DObjClone(struct DObj_s const *, struct XAnimTree_s *, char *) {
  UNIMPLEMENTED();
}

void __cdecl DObjSetLocalTagInternal(struct DObj_s const *obj,
                                     float const *const trans,
                                     float const *const angles, int boneIndex) {
  int32_t result; // eax
  int v5;         // ebx
  float v6;       // xmm0_4
  float v7;       // xmm0_4
  float v8;       // xmm0_4
  float v9;       // xmm2_4
  float v10;      // [esp+1Ch] [ebp-4Ch]
  float v11;      // [esp+1Ch] [ebp-4Ch]
  float v12;      // [esp+20h] [ebp-48h]
  float v13;      // [esp+34h] [ebp-34h]
  float v14;      // [esp+38h] [ebp-30h]
  float v15;      // [esp+3Ch] [ebp-2Ch]
  float v16;      // [esp+40h] [ebp-28h]

  result = a1->skel;
  if (result) {
    result += 48;
    if (result) {
      v5 = 32 * a4 + result;
      if (a3) {
        v6 = a3[1] * 0.008726646259971648;
        v16 = sinf(v6);
        v15 = cosf(v6);
        v7 = *a3 * 0.008726646259971648;
        v14 = sinf(v7);
        v13 = cosf(v7);
        v8 = a3[2] * 0.008726646259971648;
        v10 = sinf(v8);
        v12 = v10;
        v11 = cosf(v8);
        v9 = (float)-v14 * v16;
        *(float *)v5 = (float)(v12 * (float)(v15 * v13)) + (float)(v11 * v9);
        *(float *)(v5 + 4) = (float)(v11 * (float)(v14 * v15)) +
                             (float)(v12 * (float)(v16 * v13));
        *(float *)(v5 + 8) = (float)((float)(v16 * v13) * v11) -
                             (float)((float)(v14 * v15) * v12);
        *(float *)(v5 + 12) =
            (float)((float)(v15 * v13) * v11) - (float)(v9 * v12);
      } else {
        *(_DWORD *)v5 = 0;
        *(_DWORD *)(v5 + 4) = 0;
        *(_DWORD *)(v5 + 8) = 0;
        *(_DWORD *)(v5 + 12) = 1065353216;
      }
      *(_DWORD *)(v5 + 28) = 0;
      *(float *)(v5 + 16) = *a2;
      *(float *)(v5 + 20) = a2[1];
      result = *((_DWORD *)a2 + 2);
      *(_DWORD *)(v5 + 24) = result;
    }
  }
  return result;
}

void __cdecl DObjGeomTraceline(struct DObj_s *obj, float *const localStart,
                               float *const localEnd, int contentmask,
                               struct DObjTrace_s *results) {
  DObjTrace_s *v5;         // edx
  int32_t skel;            // eax
  const DObjAnimMat_s *v7; // edi
  int result;              // eax
  DObj_s *v9;              // esi
  int v10;                 // ebx
  const XModel *v11;       // edx
  int v12;                 // eax
  __int16 *parts;          // [esp+28h] [ebp-50h]
  int v14;                 // [esp+2Ch] [ebp-4Ch]
  trace_t v15;             // [esp+3Ch] [ebp-3Ch] BYREF

  *(_WORD *)a5->partName = 0;
  a5->partGroup = 0;
  v5 = a5;
  v15.fraction = a5->fraction;
  memset(v15.normal, 0, 16);
  skel = a1->skel;
  if (skel) {
    v7 = (const DObjAnimMat_s *)(skel + 48);
    if (skel != -48 && a1->numModels) {
      v9 = a1;
      v10 = 0;
      do {
        v11 = *(const XModel **)v9->models;
        parts = (__int16 *)v11->parts;
        v14 = **(_DWORD **)(v11->parts + 4);
        v12 = XModelTraceLine(v11, &v15, v7, a2, a3, a4);
        if (v12 >= 0)
          *(_WORD *)a5->partName = *(_WORD *)(v14 + 2 * v12);
        v7 += *parts;
        ++v10;
        v9 = (DObj_s *)((char *)v9 + 4);
      } while (a1->numModels > v10);
    }
    v5 = a5;
  }
  v5->fraction = v15.fraction;
  v5->surfaceflags = v15.surfaceFlags;
  a5->normal[0] = v15.normal[0];
  a5->normal[1] = v15.normal[1];
  result = LODWORD(v15.normal[2]);
  a5->normal[2] = v15.normal[2];
  return result;
}

void __cdecl DObjTraceline(struct DObj_s *obj, float *const start,
                           float *const end, unsigned char *priorityMap,
                           struct DObjTrace_s *trace) {
  float v5;              // xmm1_4
  int32_t skel;          // eax
  DObj_s *i;             // edx
  int v8;                // ecx
  float *v9;             // ebx
  int j;                 // edx
  unsigned __int16 v11;  // di
  unsigned __int8 v12;   // dl
  float *v13;            // edx
  float v14;             // xmm3_4
  float v15;             // xmm5_4
  float v16;             // xmm2_4
  float v17;             // xmm4_4
  float *v18;            // esi
  float v19;             // xmm1_4
  float *v20;            // ecx
  float v21;             // xmm0_4
  float v22;             // xmm3_4
  float v23;             // xmm5_4
  float v24;             // xmm1_4
  float v25;             // xmm2_4
  float v26;             // xmm4_4
  float v27;             // xmm6_4
  float v28;             // xmm7_4
  float v29;             // xmm5_4
  float v30;             // xmm7_4
  float v31;             // xmm1_4
  float v32;             // xmm4_4
  float v33;             // xmm3_4
  float v34;             // xmm2_4
  float v35;             // xmm6_4
  float v36;             // xmm5_4
  float v37;             // xmm7_4
  float v38;             // xmm2_4
  float v39;             // xmm3_4
  float v40;             // xmm5_4
  float v41;             // xmm7_4
  float v42;             // xmm4_4
  float v43;             // xmm2_4
  float v44;             // xmm4_4
  float v45;             // xmm7_4
  float v46;             // xmm6_4
  float v47;             // xmm2_4
  float v48;             // xmm3_4
  float v49;             // xmm1_4
  float v50;             // xmm0_4
  float v51;             // xmm6_4
  float v52;             // xmm5_4
  float v53;             // xmm2_4
  float v54;             // xmm5_4
  float *v55;            // ecx
  float v56;             // xmm4_4
  char v57;              // si
  float k;               // xmm3_4
  int m;                 // edx
  float v60;             // xmm0_4
  float v61;             // xmm2_4
  float v62;             // xmm1_4
  float v63;             // xmm1_4
  DObjTrace_s *v64;      // esi
  float v65;             // xmm1_4
  unsigned __int8 *v66;  // esi
  int v67;               // eax
  unsigned __int8 v68;   // al
  int v69;               // eax
  float v70;             // xmm4_4
  float v71;             // xmm6_4
  float v72;             // xmm1_4
  float v73;             // xmm3_4
  float v74;             // xmm5_4
  float v75;             // xmm2_4
  float v76;             // xmm0_4
  float v77;             // xmm4_4
  float v78;             // xmm7_4
  float v79;             // xmm6_4
  float *v80;            // eax
  __m128 v81;            // xmm0
  float v82;             // [esp+3Ch] [ebp-24Ch]
  float v83;             // [esp+40h] [ebp-248h]
  __int16 **v84;         // [esp+44h] [ebp-244h]
  _DWORD *v85;           // [esp+48h] [ebp-240h]
  int v86;               // [esp+4Ch] [ebp-23Ch]
  float *v87;            // [esp+50h] [ebp-238h]
  float *v88;            // [esp+54h] [ebp-234h]
  float fraction;        // [esp+58h] [ebp-230h]
  char v90;              // [esp+5Fh] [ebp-229h]
  int v91;               // [esp+60h] [ebp-228h]
  float v92;             // [esp+64h] [ebp-224h]
  int v93;               // [esp+68h] [ebp-220h]
  int v94;               // [esp+6Ch] [ebp-21Ch]
  int v95;               // [esp+70h] [ebp-218h]
  int v96;               // [esp+74h] [ebp-214h]
  unsigned int v97;      // [esp+78h] [ebp-210h]
  unsigned int v98;      // [esp+7Ch] [ebp-20Ch]
  int v99;               // [esp+80h] [ebp-208h]
  unsigned __int8 *v100; // [esp+84h] [ebp-204h]
  int v101;              // [esp+88h] [ebp-200h]
  int *v102;             // [esp+8Ch] [ebp-1FCh]
  float *normal;         // [esp+90h] [ebp-1F8h]
  float *v104;           // [esp+94h] [ebp-1F4h]
  float *v105;           // [esp+9Ch] [ebp-1ECh]
  float *v106;           // [esp+A0h] [ebp-1E8h]
  float *v107;           // [esp+A4h] [ebp-1E4h]
  float *v108;           // [esp+A8h] [ebp-1E0h]
  float v109;            // [esp+ACh] [ebp-1DCh]
  float v110;            // [esp+B0h] [ebp-1D8h]
  float v111;            // [esp+B4h] [ebp-1D4h]
  float v112;            // [esp+B8h] [ebp-1D0h]
  float v113;            // [esp+BCh] [ebp-1CCh]
  float v114;            // [esp+C0h] [ebp-1C8h]
  float v115;            // [esp+C8h] [ebp-1C0h]
  float v116;            // [esp+CCh] [ebp-1BCh]
  float v117;            // [esp+D0h] [ebp-1B8h]
  float v118;            // [esp+D4h] [ebp-1B4h]
  float v119;            // [esp+D8h] [ebp-1B0h]
  float v120;            // [esp+DCh] [ebp-1ACh]
  float v121;            // [esp+E0h] [ebp-1A8h]
  float v122;            // [esp+ECh] [ebp-19Ch]
  float v123;            // [esp+F0h] [ebp-198h]
  float v124;            // [esp+F4h] [ebp-194h]
  float v125;            // [esp+F8h] [ebp-190h]
  float v126;            // [esp+FCh] [ebp-18Ch]
  float v127;            // [esp+100h] [ebp-188h]
  float v128;            // [esp+104h] [ebp-184h]
  float v129;            // [esp+108h] [ebp-180h]
  float v130;            // [esp+10Ch] [ebp-17Ch]
  float v131;            // [esp+110h] [ebp-178h]
  float v132;            // [esp+114h] [ebp-174h]
  float v133;            // [esp+118h] [ebp-170h]
  int v134;              // [esp+11Ch] [ebp-16Ch]
  float *v135;           // [esp+120h] [ebp-168h]
  float *v136;           // [esp+124h] [ebp-164h]
  DObj_s *v137;          // [esp+128h] [ebp-160h]
  DObj_s *v138;          // [esp+12Ch] [ebp-15Ch]
  _WORD v139[129];       // [esp+132h] [ebp-156h]
  float v140[9];         // [esp+234h] [ebp-54h] BYREF
  float v141[3];         // [esp+258h] [ebp-30h]
  float v142[9];         // [esp+264h] [ebp-24h]

  a5->surfaceflags = 0;
  *(_WORD *)a5->partName = 0;
  a5->partGroup = 0;
  normal = a5->normal;
  a5->normal[0] = 0.0;
  v104 = &a5->normal[1];
  a5->normal[1] = 0.0;
  a5->normal[2] = 0.0;
  v127 = *a3 - *a2;
  v105 = a3 + 1;
  v106 = a2 + 1;
  v126 = a3[1] - a2[1];
  v107 = a3 + 2;
  v108 = a2 + 2;
  v125 = a3[2] - a2[2];
  v5 = (float)((float)(v127 * v127) + (float)(v126 * v126)) +
       (float)(v125 * v125);
  if (v5 == 0.0)
    return;
  skel = a1->skel;
  if (!skel)
    return;
  v87 = (float *)(skel + 48);
  if (skel == -48)
    return;
  v83 = 1.0 / v5;
  v100 = (unsigned __int8 *)(SL_ConvertToString(
                                 (unsigned __int16)a1->duplicateParts) +
                             16);
  fraction = a5->fraction;
  if (!a1->numModels)
    return;
  v137 = a1;
  v138 = a1;
  v97 = 2;
  v95 = 0;
  v93 = -1;
  v96 = 0;
  v94 = -1;
  v92 = 0.0;
  v88 = 0;
  for (i = a1;; i = v137) {
    v84 = *(__int16 ***)i->models;
    v85 = *v84;
    v102 = (int *)*((_DWORD *)*v84 + 1);
    v99 = *v102;
    v86 = **v84;
    v101 = (1 << v96) & (unsigned __int8)a1->ignoreCollision;
    if (v86 > 0)
      break;
  LABEL_49:
    ++v96;
    v137 = (DObj_s *)((char *)v137 + 4);
    v138 = (DObj_s *)((char *)v138 + 1);
    if (a1->numModels <= v96) {
      if (v88) {
        v70 = v88[7] * *v88;
        v71 = v88[7] * v88[1];
        v72 = v88[7] * v88[2];
        v122 = v70 * *v88;
        v73 = v88[1];
        v74 = v70 * v73;
        v75 = v88[2];
        v123 = v70 * v75;
        v76 = v88[3];
        v77 = v70 * v76;
        v124 = v73 * v71;
        v78 = v71 * v75;
        v79 = v71 * v76;
        v140[0] = 1.0 - (float)(v124 + (float)(v72 * v75));
        v140[1] = (float)(v72 * v76) + v74;
        v140[2] = v123 - v79;
        v140[3] = v74 - (float)(v72 * v76);
        v140[4] = 1.0 - (float)((float)(v72 * v75) + v122);
        v140[5] = v77 + v78;
        v140[6] = v79 + v123;
        v140[7] = v78 - v77;
        v140[8] = 1.0 - (float)(v122 + v124);
        v80 = &v140[3 * v94];
        *normal = v92 * *v80;
        *v104 = v92 * v80[1];
        a5->normal[2] = v92 * v80[2];
      }
      return;
    }
  }
  v91 = 0;
  v134 = 0;
  v8 = v95;
  v9 = v87 + 4;
  for (j = 0;; j = v91) {
    v11 = *(unsigned __int8 *)(v85[4] + j);
    v12 = a4[*(unsigned __int8 *)(v85[4] + j)];
    v98 = v12;
    if (*v100 - 1 == v8) {
      v66 = v100 + 2;
      v100 += 2;
      if (v12 == 1) {
        v11 = v139[*(v66 - 1)];
        v98 = a4[v11];
      }
    } else if (v12 == 1) {
      v67 = *((__int16 *)v85 + 1);
      if (v91 >= v67) {
        v11 = v139[v8 - *((unsigned __int8 *)v102 + v91 - v67 + 4) + 1];
        v69 = v11;
      } else {
        v68 = v138->modelParents[0];
        if (v68 == 0xFF) {
          v11 = 0;
          v69 = 0;
        } else {
          v11 = v139[v68 + 1];
          v69 = v11;
        }
      }
      v98 = a4[v69];
    }
    v139[v8 + 1] = v11;
    if (!v101) {
      v13 = (float *)&v84[24][v134];
      v82 = v13[9];
      if (v82 != 0.0 && v98 >= v97) {
        v135 = v87 + 7;
        v14 = v9[3] * *(v9 - 4);
        v15 = v9[3] * *(v9 - 3);
        v16 = v9[3] * *(v9 - 2);
        v109 = v14 * *(v9 - 4);
        v136 = v87 + 1;
        v17 = *(v9 - 3);
        v110 = v14 * v17;
        v18 = v87 + 2;
        v19 = *(v9 - 2);
        v111 = v14 * v19;
        v20 = v87 + 3;
        v21 = *(v9 - 1);
        v22 = v14 * v21;
        v112 = v17 * v15;
        v113 = v15 * v19;
        v23 = v15 * v21;
        v24 = v19 * v16;
        v25 = v16 * v21;
        v26 = v13[6];
        v27 = v13[7];
        v28 = v13[8];
        v129 = (float)((float)((float)(v111 + v23) * v28) +
                       (float)((float)((float)(v110 - v25) * v27) +
                               (float)((float)(1.0 - (float)(v112 + v24)) *
                                       v26))) +
               *v9;
        v128 =
            (float)((float)((float)(v113 - v22) * v28) +
                    (float)((float)((float)(1.0 - (float)(v24 + v109)) * v27) +
                            (float)((float)(v25 + v110) * v26))) +
            v9[1];
        v29 = (float)((float)((float)((float)(v111 - v23) * v26) +
                              (float)((float)(v22 + v113) * v27)) +
                      (float)((float)(1.0 - (float)(v109 + v112)) * v28)) +
              v9[2];
        v30 = *a2 - v129;
        v114 = *v106;
        v31 = *v106 - v128;
        v32 = *v108 - v29;
        v33 =
            (float)-(float)((float)((float)(v127 * v30) + (float)(v126 * v31)) +
                            (float)(v125 * v32)) *
            v83;
        if (v33 < 1.0)
          v34 = v33 <= 0.0
                    ? (float)((float)(v30 * v30) + (float)(v31 * v31)) +
                          (float)(v32 * v32)
                    : (float)((float)((float)((float)(v127 * v33) + v30) *
                                      (float)((float)(v127 * v33) + v30)) +
                              (float)((float)(v31 + (float)(v126 * v33)) *
                                      (float)(v31 + (float)(v126 * v33)))) +
                          (float)((float)(v32 + (float)(v125 * v33)) *
                                  (float)(v32 + (float)(v125 * v33)));
        else
          v34 =
              (float)((float)((float)(*a3 - v129) * (float)(*a3 - v129)) +
                      (float)((float)(*v105 - v128) * (float)(*v105 - v128))) +
              (float)((float)(*v107 - v29) * (float)(*v107 - v29));
        if ((float)(v82 - v34) > 0.0) {
          if (v98 == v97 &&
              (float)(v33 - fsqrt((float)(v82 - v34) * v83)) >= a5->fraction)
            goto LABEL_63;
          v35 = *a2 - *v9;
          v131 = v114 - v9[1];
          v130 = *v108 - v9[2];
          v36 = *v135 * *(v9 - 4);
          v37 = *v135 * *(v9 - 3);
          v38 = *v135 * *(v9 - 2);
          v115 = v36 * *(v9 - 4);
          v39 = v36 * *v136;
          v116 = v36 * *v18;
          v40 = v36 * *v20;
          v117 = *v136 * v37;
          v118 = v37 * *v18;
          v41 = v37 * *v20;
          v42 = v38 * *v18;
          v43 = v38 * *v20;
          v142[0] = (float)((float)((float)(1.0 - (float)(v117 + v42)) * v35) +
                            (float)((float)(v39 + v43) * v131)) +
                    (float)((float)(v116 - v41) * v130);
          v142[1] =
              (float)((float)((float)(v39 - v43) * v35) +
                      (float)((float)(1.0 - (float)(v42 + v115)) * v131)) +
              (float)((float)(v118 + v40) * v130);
          v142[2] = (float)((float)(v35 * (float)(v41 + v116)) +
                            (float)(v131 * (float)(v118 - v40))) +
                    (float)((float)(1.0 - (float)(v115 + v117)) * v130);
          v44 = *a3 - *v9;
          v45 = *v105 - v9[1];
          v132 = *v107 - v9[2];
          v46 = *v135 * *(v9 - 4);
          v133 = *v135 * *(v9 - 3);
          v47 = *v135 * *(v9 - 2);
          v119 = v46 * *(v9 - 4);
          v48 = v46 * *v136;
          v49 = *v18;
          v120 = v46 * *v18;
          v50 = *v20;
          v51 = v46 * *v20;
          v121 = *v136 * v133;
          v52 = v47 * *v18;
          v53 = v47 * *v20;
          v141[0] = (float)((float)((float)(1.0 - (float)(v121 + v52)) * v44) +
                            (float)((float)(v48 + v53) * v45)) +
                    (float)((float)(v120 - (float)(v133 * *v20)) * v132);
          v141[1] = (float)((float)((float)(v48 - v53) * v44) +
                            (float)((float)(1.0 - (float)(v52 + v119)) * v45)) +
                    (float)((float)((float)(v133 * v49) + v51) * v132);
          v141[2] = (float)((float)(v44 * (float)(v120 + (float)(v133 * v50))) +
                            (float)(v45 * (float)((float)(v133 * v49) - v51))) +
                    (float)((float)(1.0 - (float)(v119 + v121)) * v132);
          if (v98 == v97)
            v54 = a5->fraction;
          else
            v54 = fraction;
          v55 = v13;
          v56 = 0.0;
          v57 = 1;
          v90 = 1;
          for (k = -1.0;; k = 1.0) {
            for (m = 0; m != 3; ++m) {
              v60 = v55[m];
              v61 = (float)(v142[m] - v60) * k;
              v62 = (float)(v141[m] - v60) * k;
              if (v61 <= 0.0) {
                if (v62 > 0.0) {
                  v65 = v61 - v62;
                  if (v61 > (float)(v65 * v54)) {
                    v54 = v61 / v65;
                    if (v56 >= (float)(v61 / v65))
                      goto LABEL_40;
                  }
                  v90 = 0;
                }
              } else {
                if (v62 > 0.0)
                  goto LABEL_40;
                v63 = v61 - v62;
                if (v61 > (float)(v63 * v56)) {
                  v56 = v61 / v63;
                  if ((float)(v61 / v63) >= v54)
                    goto LABEL_40;
                  v93 = m;
                  v92 = k;
                }
                v57 = 0;
              }
            }
            if (k == 1.0)
              break;
            v55 += 3;
          }
          if (!v57) {
            if (v98 == v97) {
              if (v56 >= a5->fraction) {
              LABEL_63:
                v97 = v98;
                goto LABEL_40;
              }
              v64 = a5;
            } else {
              v64 = a5;
            }
            v64->fraction = v56;
            *(_WORD *)v64->partName = *(_WORD *)(v99 + 2 * v91);
            v64->partGroup = v11;
            v97 = v98;
            v94 = v93;
            v88 = v87;
            goto LABEL_40;
          }
          if (v90 && (float)((float)(v127 * *a2) + (float)(v126 * v114)) <= 0.0)
            break;
        }
      }
    }
  LABEL_40:
    ++v91;
    v87 += 8;
    v9 += 8;
    v8 = v95 + v91;
    v134 += 20;
    if (v86 == v91) {
      v95 += v91;
      goto LABEL_49;
    }
  }
  a5->fraction = 0.0;
  *(_WORD *)a5->partName = *(_WORD *)(v99 + 2 * v91);
  a5->partGroup = v11;
  if (v127 == 0.0 && v126 == 0.0) {
    v81 = _mm_cmpge_ss((__m128)LODWORD(v125), (__m128)0LL);
    LODWORD(a5->normal[2]) = _mm_andnot_ps(v81, (__m128)0x3F800000u).u32[0] |
                             v81.i32[0] & 0xBF800000;
  } else {
    *normal = *a2;
    *v104 = *v106;
    Vec2Normalize(normal);
  }
}

int __cdecl DObjSetLocalBoneIndex(struct DObj_s *, int *const, int,
                                  float const *const, float const *const) {
  UNIMPLEMENTED();
}

int __cdecl DObjSetLocalTag(struct DObj_s const *obj, int *const partBits,
                            unsigned int tagName, float const *const trans,
                            float const *const angles) {
  const DObj_s *v6; // esi
  int v7;           // edi
  const XModel *v8; // ebx
  int BoneIndex;    // eax
  int v10;          // esi
  int v11;          // edx
  int v12;          // ebx
  int32_t skel;     // eax
  int numModels;    // [esp+18h] [ebp-20h]
  int v15;          // [esp+1Ch] [ebp-1Ch]

  numModels = a1->numModels;
  if (!a1->numModels)
    return 0;
  v6 = a1;
  v7 = 0;
  v15 = 0;
  while (1) {
    v8 = *(const XModel **)v6->models;
    BoneIndex = XModelGetBoneIndex(v8, a3);
    if (BoneIndex >= 0)
      break;
    v15 += *(__int16 *)v8->parts;
    ++v7;
    v6 = (const DObj_s *)((char *)v6 + 4);
    if (numModels == v7)
      return 0;
  }
  v10 = BoneIndex + v15;
  if (BoneIndex + v15 < 0)
    return 0;
  v11 = v10 >> 5;
  v12 = 1 << (v10 & 0x1F);
  if ((v12 & a2[v10 >> 5]) == 0)
    return 0;
  skel = a1->skel;
  if ((v12 & *(_DWORD *)(skel + 4 * v11 + 32)) != 0)
    return 0;
  *(_DWORD *)(skel + 4 * v11) |= v12;
  DObjSetLocalTagInternal(a1, a4, a5, v10);
  return 1;
}

int __cdecl DObjSetControlTagAngles(struct DObj_s const *obj,
                                    int *const partBits, unsigned int tagName,
                                    float *const angles) {
  const DObj_s *v5; // esi
  int v6;           // edi
  const XModel *v7; // ebx
  int BoneIndex;    // eax
  int v9;           // esi
  int v10;          // edx
  int v11;          // ebx
  int32_t skel;     // eax
  int numModels;    // [esp+18h] [ebp-20h]
  int v14;          // [esp+1Ch] [ebp-1Ch]

  numModels = a1->numModels;
  if (!a1->numModels)
    return 0;
  v5 = a1;
  v6 = 0;
  v14 = 0;
  while (1) {
    v7 = *(const XModel **)v5->models;
    BoneIndex = XModelGetBoneIndex(v7, a3);
    if (BoneIndex >= 0)
      break;
    v14 += *(__int16 *)v7->parts;
    ++v6;
    v5 = (const DObj_s *)((char *)v5 + 4);
    if (numModels == v6)
      return 0;
  }
  v9 = BoneIndex + v14;
  if (BoneIndex + v14 < 0)
    return 0;
  v10 = v9 >> 5;
  v11 = 1 << (v9 & 0x1F);
  if ((v11 & a2[v9 >> 5]) == 0)
    return 0;
  skel = a1->skel;
  if ((v11 & *(_DWORD *)(skel + 4 * v10 + 32)) != 0)
    return 0;
  *(_DWORD *)(skel + 4 * v10 + 16) |= v11;
  *(_DWORD *)(skel + 4 * v10) |= v11;
  DObjSetLocalTagInternal(a1, vec3_origin, a4, v9);
  return 1;
}

void __cdecl DObjInit() {
  int result;      // eax
  _DWORD __src[7]; // [esp+1Ch] [ebp-1Ch] BYREF

  memset(__src, 0, 20);
  result = SL_GetStringOfLen((char *)__src, 0, 0x11u);
  g_empty = result;
  return result;
}

void __cdecl DObjFree(struct DObj_s *obj) { UNIMPLEMENTED(); }

void __cdecl DObjShutdown() { UNIMPLEMENTED(); }

int __cdecl DObjGetSurfaces(struct DObj_s const *obj,
                            struct DSurface_s *surfaces, int *const partBits,
                            char *lods) {
  unsigned __int8 v4;      // al
  __int16 **v5;            // edx
  uint16_t *p_subMatIndex; // eax
  int v7;                  // edx
  int v8;                  // eax
  int v9;                  // edx
  char v10;                // di
  int v11;                 // edx
  int v12;                 // eax
  int *v14;                // edx
  int k;                   // ecx
  const DObj_s *i;         // edx
  const XModel *v17;       // edi
  int Surfaces;            // ebx
  int v19;                 // esi
  const char *Name;        // eax
  int *v21;                // ebx
  int v22;                 // esi
  _DWORD *j;               // ecx
  char v24;                // [esp+8h] [ebp-80h]
  _DWORD *v25;             // [esp+1Ch] [ebp-6Ch]
  int v27;                 // [esp+30h] [ebp-58h]
  int numModels;           // [esp+34h] [ebp-54h]
  unsigned __int8 v29;     // [esp+3Bh] [ebp-4Dh]
  int v30;                 // [esp+3Ch] [ebp-4Ch]
  __int16 *v31;            // [esp+40h] [ebp-48h]
  __int16 *v32;            // [esp+44h] [ebp-44h]
  int v33;                 // [esp+48h] [ebp-40h]
  int v34;                 // [esp+4Ch] [ebp-3Ch]
  char v35;                // [esp+50h] [ebp-38h]
  int v36;                 // [esp+54h] [ebp-34h]
  int v37;                 // [esp+58h] [ebp-30h]
  const DObj_s *v38;       // [esp+5Ch] [ebp-2Ch]
  int *v39;                // [esp+68h] [ebp-20h] BYREF
  XSurface_s **v40;        // [esp+6Ch] [ebp-1Ch] BYREF

  *a3 = 0;
  a3[1] = 0;
  a3[2] = 0;
  a3[3] = 0;
  numModels = a1->numModels;
  if (!a1->numModels)
    return 0;
  v29 = 0;
  v27 = 0;
  v36 = 0;
  do {
    v4 = a4[v29];
    if ((v4 & 0x80u) == 0) {
      v5 = *(__int16 ***)&a1->models[4 * v27];
      v31 = v5[5 * v4 + 5];
      if (v31) {
        v33 = (**v5 - 1) >> 5;
        v30 = SLOWORD(v5[5 * v4 + 3]);
        if (v36 + v30 > 64) {
          Com_Printf("ERROR: models with more than %i total surfaces\n", 64);
          v38 = a1;
          v37 = 0;
          for (i = a1;; i = v38) {
            v17 = *(const XModel **)i->models;
            Surfaces = XModelGetSurfaces(v17, &v40, a4[v37], &v39);
            v19 = a4[v37];
            Name = (const char *)XModelGetName(v17);
            Com_Printf("  model '%s' lod %i has %i surfaces\n", Name, v19,
                       Surfaces);
            ++v37;
            v38 = (const DObj_s *)((char *)v38 + 4);
            if (numModels == v37)
              break;
          }
          Com_Error(1, "Max surfs exceeded - see console for details", v24);
        }
        if (v30 > 0) {
          p_subMatIndex = &a2->subMatIndex;
          v7 = 0;
          do {
            *p_subMatIndex = v7;
            *(p_subMatIndex - 1) = v29;
            ++v7;
            ++v36;
            ++a2;
            p_subMatIndex += 2;
          } while (v30 != v7);
        }
        v8 = *((unsigned __int8 *)a1->matOffset + v27);
        v32 = v31 + 2;
        v9 = v8 >> 5;
        v10 = v8 & 0x1F;
        if ((v8 & 0x1F) != 0) {
          v35 = 32 - v10;
          a3[v9] |= *((_DWORD *)v31 + 1) << v10;
          v11 = v9 + 1;
          v34 = v11;
          if (v33 > 0) {
            v21 = &a3[v11];
            v22 = 0;
            v25 = v31 + 2;
            for (j = v31 + 2;; j = v25) {
              *v21 |= (v25[1] << v10) | (*j >> v35);
              ++v22;
              ++v25;
              ++v21;
              if (v33 == v22)
                break;
            }
            v12 = v33;
            v34 = v33 + v11;
          } else {
            v12 = 0;
          }
          a3[v34] |= *(_DWORD *)&v32[2 * v12] >> v35;
        } else if (v33 >= 0) {
          v14 = &a3[v9];
          for (k = 0; k <= v33; ++k)
            *v14++ |= *(_DWORD *)&v32[2 * k];
        }
      }
    }
    v27 = ++v29;
  } while (numModels > v29);
  return v36;
}

void __cdecl DObjCreate(struct DObjModel_s *dobjModels, unsigned int numModels,
                        struct XAnimTree_s *tree, char *buf,
                        unsigned int entnum) {
  size_t v5;          // ecx
  char *v6;           // eax
  char *v7;           // ebx
  char v8;            // al
  unsigned __int8 v9; // al
  int v10;            // edi
  float v11;          // xmm0_4
  float v12;          // xmm5_4
  float v13;          // xmm3_4
  float v14;          // xmm1_4
  float v15;          // xmm4_4
  float v16;          // xmm2_4
  char *result;       // eax
  char *v18;          // esi
  char *i;            // ecx
  __int16 **v21;      // ebx
  char *v22;          // ecx
  char *v23;          // ebx
  int v24;            // esi
  const XModel *v25;  // eax
  char *j;            // ecx
  int BoneIndex;      // eax
  int v28;            // [esp+7Ch] [ebp-5Ch]
  int v29;            // [esp+80h] [ebp-58h]
  const char *v30;    // [esp+84h] [ebp-54h]
  int String;         // [esp+88h] [ebp-50h]
  int v32;            // [esp+8Ch] [ebp-4Ch]
  char v33;           // [esp+93h] [ebp-45h]
  char *v34;          // [esp+94h] [ebp-44h]
  char *v35;          // [esp+98h] [ebp-40h]
  float v36[3];       // [esp+A8h] [ebp-30h] BYREF
  float v37[9];       // [esp+B4h] [ebp-24h] BYREF

  *((_DWORD *)a4 + 1) = 0;
  *((_DWORD *)a4 + 2) = 0;
  *((_WORD *)a4 + 8) = 0;
  a4[26] = 0;
  *(_DWORD *)a4 = a3;
  if (a3) {
    v5 = *(_DWORD *)(a3->anims + 4);
    v6 = &a3->infoArray[2 * v5];
    *((_DWORD *)a4 + 3) = v6;
    v7 = &v6[2 * v5];
    v8 = *v7 + 1;
    if (*v7 == -1) {
      memset(v7 + 1, 0, v5);
      v8 = 1;
    }
    *v7 = v8;
    a3->entnum = a5;
  } else {
    *((_DWORD *)a4 + 3) = 0;
  }
  if (!a2) {
    v9 = 0;
    v33 = 0;
    goto LABEL_7;
  }
  v35 = a4;
  v18 = a4;
  v32 = 0;
  v29 = 0;
  for (i = a4;; i = v35) {
    v21 = *(__int16 ***)a1->model;
    *((_DWORD *)i + 7) = *(_DWORD *)a1->model;
    v18[60] = -1;
    v33 = v29;
    v18[68] = v29;
    if (a1->ignoreCollision)
      a4[26] |= 1 << v32;
    if (v32) {
      v22 = *(char **)a1->boneName;
      v30 = v22;
      if (v22) {
        if (*v22) {
          String = SL_FindString(v22);
          if (String && v32 > 0) {
            v34 = a4;
            v28 = 0;
            for (j = a4;; j = v34) {
              BoneIndex = XModelGetBoneIndex(*((const XModel **)j + 7), String);
              if (BoneIndex >= 0)
                break;
              ++v28;
              v34 += 4;
              if (v32 == v28)
                goto LABEL_23;
            }
            v18[60] = a4[v28 + 68] + BoneIndex;
          } else {
          LABEL_23:
            Com_Printf("WARNING: Part '%s' not found in model '%s' or any of "
                       "its descendants\n",
                       v30, *(const char **)(*((_DWORD *)a4 + 7) + 136));
          }
        }
      }
    }
    if (v21)
      break;
  LABEL_14:
    ++v32;
    ++a1;
    v35 += 4;
    ++v18;
    if (a2 == v32) {
      v9 = v32;
      goto LABEL_7;
    }
  }
  if (v29 + **v21 <= 127) {
    v33 = v29 + **v21;
    v29 += **v21;
    goto LABEL_14;
  }
  Com_Error(1, "\x15dobj for xmodel '%s' has more than %d bones",
            *(_DWORD *)(*((_DWORD *)a4 + 7) + 136));
  v9 = v32;
LABEL_7:
  a4[24] = v9;
  a4[25] = v33;
  v10 = v9;
  if (v9) {
    v23 = a4;
    v24 = 0;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    v16 = 0.0;
    do {
      v25 = (const XModel *)*((_DWORD *)v23 + 7);
      if (v25) {
        XModelGetBounds(v25, v37, v36);
        v13 = v13 + v37[0];
        v12 = v12 + v37[1];
        v11 = v11 + v37[2];
        v16 = v16 + v36[0];
        v15 = v15 + v36[1];
        v14 = v14 + v36[2];
      }
      ++v24;
      v23 += 4;
    } while (v10 != v24);
  } else {
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    v16 = 0.0;
  }
  *((float *)a4 + 19) = v13;
  *((float *)a4 + 20) = v12;
  *((float *)a4 + 21) = v11;
  result = a4 + 88;
  *((float *)a4 + 22) = v16;
  *((float *)a4 + 23) = v15;
  *((float *)a4 + 24) = v14;
  return result;
}

void __cdecl DObjDumpInfo(struct DObj_s const *obj) {
  __int16 *v1;          // edx
  int v2;               // eax
  int v3;               // ecx
  const DObj_s *v4;     // ebx
  int v5;               // edi
  int v6;               // esi
  __int16 *v7;          // edx
  int v8;               // edx
  const char *v9;       // eax
  unsigned int v10;     // eax
  __int16 *v11;         // edx
  int v12;              // eax
  int v13;              // ecx
  const DObj_s *v14;    // ebx
  int v15;              // edi
  int v16;              // esi
  __int16 *v17;         // edx
  int v18;              // edx
  __int16 *v19;         // edx
  int v20;              // eax
  int v21;              // edx
  const DObj_s *v22;    // ebx
  int v23;              // edi
  int v24;              // esi
  __int16 *v25;         // edx
  int v26;              // edx
  const char *v27;      // eax
  const DObj_s *v28;    // esi
  int v29;              // edi
  __int16 **v30;        // ebx
  unsigned __int8 *v31; // [esp+2Ch] [ebp-4Ch]
  int v32;              // [esp+34h] [ebp-44h]
  int i;                // [esp+38h] [ebp-40h]
  int numBones;         // [esp+3Ch] [ebp-3Ch]
  int numModels;        // [esp+40h] [ebp-38h]
  int v36;              // [esp+44h] [ebp-34h]
  const char *v37;      // [esp+4Ch] [ebp-2Ch]
  int v38;              // [esp+50h] [ebp-28h]
  int v39;              // [esp+54h] [ebp-24h]
  int v40;              // [esp+58h] [ebp-20h]
  int v41;              // [esp+5Ch] [ebp-1Ch]

  if (a1) {
    Com_Printf("\nModels:\n");
    numModels = a1->numModels;
    if (a1->numModels) {
      v28 = a1;
      v36 = 0;
      v29 = 0;
      do {
        v30 = *(__int16 ***)v28->models;
        Com_Printf("%d: '%s'\n", v36, (const char *)v30[34]);
        v36 += **v30;
        ++v29;
        v28 = (const DObj_s *)((char *)v28 + 4);
      } while (numModels != v29);
    }
    Com_Printf("\nBones:\n");
    numBones = a1->numBones;
    if (a1->numBones) {
      for (i = 0; numBones != i; ++i) {
        if (a1->numModels) {
          v1 = **(__int16 ***)a1->models;
          v2 = **((_DWORD **)v1 + 1);
          v3 = *v1;
          if (i < v3) {
            v8 = i;
          LABEL_10:
            v9 = (const char *)SL_ConvertToString(
                *(unsigned __int16 *)(v2 + 2 * v8));
            goto LABEL_11;
          }
          v4 = a1;
          v5 = 0;
          v6 = 0;
          while (1) {
            v5 += v3;
            if (a1->numModels == ++v6)
              break;
            v7 = **(__int16 ***)&v4->models[4];
            v2 = **((_DWORD **)v7 + 1);
            v3 = *v7;
            v8 = i - v5;
            v4 = (const DObj_s *)((char *)v4 + 4);
            if (i - v5 < v3)
              goto LABEL_10;
          }
        }
        v9 = 0;
      LABEL_11:
        Com_Printf("Bone %d: '%s'\n", i, v9);
      }
    }
    if (a1->duplicateParts) {
      Com_Printf("\nPart duplicates:\n");
      v10 = SL_ConvertToString((unsigned __int16)a1->duplicateParts);
      if (*(_BYTE *)(v10 + 16)) {
        v31 = (unsigned __int8 *)(v10 + 16);
        v39 = *(unsigned __int8 *)(v10 + 17) - 1;
        v38 = a1->numModels;
        if (!a1->numModels)
          goto LABEL_28;
      LABEL_15:
        v11 = **(__int16 ***)a1->models;
        v12 = **((_DWORD **)v11 + 1);
        v13 = *v11;
        if (v39 < v13) {
          v18 = v39;
        LABEL_19:
          v37 = (const char *)SL_ConvertToString(
              *(unsigned __int16 *)(v12 + 2 * v18));
          v32 = v31[1] - 1;
          v41 = *v31 - 1;
          v40 = a1->numModels;
          if (!a1->numModels)
            goto LABEL_29;
        } else {
          v14 = a1;
          v15 = 0;
          v16 = 0;
          while (1) {
            v15 += v13;
            if (v38 == ++v16)
              break;
            v17 = **(__int16 ***)&v14->models[4];
            v12 = **((_DWORD **)v17 + 1);
            v13 = *v17;
            v18 = v39 - v15;
            v14 = (const DObj_s *)((char *)v14 + 4);
            if (v39 - v15 < v13)
              goto LABEL_19;
          }
        LABEL_28:
          while (1) {
            v37 = 0;
            v32 = v31[1] - 1;
            v41 = *v31 - 1;
            v40 = a1->numModels;
            if (a1->numModels)
              break;
          LABEL_29:
            v27 = 0;
          LABEL_26:
            Com_Printf("%d ('%s') -> %d ('%s')\n", *v31 - 1, v27, v32, v37);
            v31 += 2;
            if (!*v31)
              goto LABEL_31;
            v39 = v31[1] - 1;
            v38 = a1->numModels;
            if (a1->numModels)
              goto LABEL_15;
          }
        }
        v19 = **(__int16 ***)a1->models;
        v20 = **((_DWORD **)v19 + 1);
        v21 = *v19;
        if (v41 < v21) {
          v26 = v41;
        } else {
          v22 = a1;
          v23 = 0;
          v24 = 0;
          do {
            v23 += v21;
            if (v40 == ++v24)
              goto LABEL_29;
            v25 = **(__int16 ***)&v22->models[4];
            v20 = **((_DWORD **)v25 + 1);
            v21 = *v25;
            v22 = (const DObj_s *)((char *)v22 + 4);
          } while (v41 - v23 >= v21);
          v26 = v41 - v23;
        }
        v27 = (const char *)SL_ConvertToString(
            *(unsigned __int16 *)(v20 + 2 * v26));
        goto LABEL_26;
      }
    } else {
      Com_Printf("\nNo part duplicates.\n");
    }
  LABEL_31:
    Com_Printf("\n");
  } else {
    Com_Printf("No Dobj\n");
  }
}

void __cdecl DObjCalcSkel(struct DObj_s const *obj, int *const partBits) {
  int32_t v2;            // edx
  char v3;               // bl
  int i;                 // ecx
  int v5;                // eax
  bool v6;               // zf
  int result;            // eax
  int32_t v8;            // ebx
  int j;                 // esi
  int v10;               // ecx
  int v11;               // edx
  int v12;               // eax
  int k;                 // ecx
  int v14;               // edi
  unsigned __int8 v15;   // al
  float *v16;            // esi
  __int16 v17;           // ax
  int v18;               // edx
  int v19;               // eax
  float v20;             // xmm7_4
  float v21;             // xmm5_4
  float v22;             // xmm6_4
  float v23;             // xmm2_4
  float v24;             // xmm3_4
  float v25;             // xmm4_4
  float v26;             // xmm1_4
  float v27;             // xmm1_4
  float v28;             // xmm3_4
  float v29;             // xmm5_4
  float v30;             // xmm7_4
  float v31;             // xmm2_4
  float v32;             // xmm6_4
  float v33;             // xmm4_4
  float v34;             // xmm1_4
  float v35;             // xmm3_4
  float v36;             // xmm0_4
  float v37;             // xmm5_4
  float v38;             // xmm7_4
  float v39;             // xmm6_4
  float v40;             // xmm2_4
  float v41;             // xmm1_4
  float v42;             // xmm4_4
  int v43;               // edx
  float v44;             // xmm3_4
  float v45;             // xmm1_4
  float v46;             // xmm7_4
  float v47;             // xmm6_4
  float v48;             // xmm4_4
  float v49;             // xmm5_4
  float v50;             // xmm2_4
  __int16 *v51;          // edx
  __int16 *v52;          // ecx
  float *v53;            // esi
  int v54;               // eax
  float v55;             // xmm7_4
  float v56;             // xmm5_4
  float v57;             // xmm6_4
  float v58;             // xmm2_4
  float v59;             // xmm3_4
  float v60;             // xmm4_4
  float v61;             // xmm1_4
  float v62;             // xmm1_4
  float v63;             // xmm3_4
  float v64;             // xmm7_4
  int v65;               // eax
  float v66;             // xmm5_4
  float v67;             // xmm1_4
  float v68;             // xmm6_4
  float v69;             // xmm4_4
  float v70;             // xmm2_4
  float v71;             // xmm3_4
  float v72;             // xmm0_4
  float v73;             // xmm5_4
  float v74;             // xmm6_4
  float v75;             // xmm1_4
  float v76;             // xmm2_4
  float v77;             // xmm4_4
  int v78;               // edx
  int v79;               // ebx
  unsigned __int8 *v80;  // ecx
  int v81;               // eax
  __int16 v82;           // ax
  int v83;               // ebx
  float v84;             // xmm3_4
  int v85;               // edx
  unsigned __int8 *v86;  // ecx
  int v87;               // eax
  float v88;             // xmm3_4
  float v89;             // xmm1_4
  float v90;             // xmm7_4
  float v91;             // xmm6_4
  float v92;             // xmm4_4
  float v93;             // xmm5_4
  float v94;             // xmm2_4
  float v95;             // [esp+24h] [ebp-C4h]
  float v96;             // [esp+24h] [ebp-C4h]
  float v97;             // [esp+28h] [ebp-C0h]
  float v98;             // [esp+28h] [ebp-C0h]
  float v99;             // [esp+2Ch] [ebp-BCh]
  float v100;            // [esp+2Ch] [ebp-BCh]
  float v101;            // [esp+2Ch] [ebp-BCh]
  float v102;            // [esp+2Ch] [ebp-BCh]
  float v103;            // [esp+30h] [ebp-B8h]
  float v104;            // [esp+30h] [ebp-B8h]
  const DObj_s *v105;    // [esp+34h] [ebp-B4h]
  int v106;              // [esp+3Ch] [ebp-ACh]
  int v107;              // [esp+40h] [ebp-A8h]
  float v108;            // [esp+44h] [ebp-A4h]
  float v109;            // [esp+48h] [ebp-A0h]
  int v110;              // [esp+4Ch] [ebp-9Ch]
  __int16 *v111;         // [esp+50h] [ebp-98h]
  int v112;              // [esp+54h] [ebp-94h]
  int v113;              // [esp+58h] [ebp-90h]
  float *v114;           // [esp+5Ch] [ebp-8Ch]
  unsigned __int8 *v115; // [esp+60h] [ebp-88h]
  int32_t skel;          // [esp+68h] [ebp-80h]
  unsigned int v117;     // [esp+6Ch] [ebp-7Ch]
  float v118;            // [esp+70h] [ebp-78h]
  float v119;            // [esp+74h] [ebp-74h]
  float v120;            // [esp+78h] [ebp-70h]
  float v121;            // [esp+7Ch] [ebp-6Ch]
  float v122;            // [esp+80h] [ebp-68h]
  float v123;            // [esp+84h] [ebp-64h]
  float v124;            // [esp+8Ch] [ebp-5Ch]
  int v125;              // [esp+90h] [ebp-58h]
  const DObj_s *v126;    // [esp+94h] [ebp-54h]
  const DObj_s *v127;    // [esp+98h] [ebp-50h]
  _DWORD v128[19];       // [esp+9Ch] [ebp-4Ch] BYREF

  skel = a1->skel;
  v2 = skel;
  v3 = 1;
  for (i = 1; i != 5; ++i) {
    v5 = *(_DWORD *)(v2 + 32) | ~a2[i - 1];
    v128[i + 4] = v5;
    v6 = v5 == -1;
    result = 0;
    if (!v6)
      v3 = 0;
    v2 += 4;
  }
  if (!v3) {
    if (!a1->duplicateParts)
      DObjCreateDuplicateParts((int)a1);
    v117 = SL_ConvertToString((unsigned __int16)a1->duplicateParts);
    v8 = skel;
    for (j = 1; j != 5; ++j) {
      *(_DWORD *)(v8 + 32) |= a2[j - 1];
      v10 = j;
      v11 = v128[j + 4];
      v12 = *(_DWORD *)(v8 + 16) & ~v11;
      v128[v10 + 8] = v12;
      v128[v10] = *(_DWORD *)(v117 + 4 * j - 4) | v12 | v11;
      v8 += 4;
    }
    for (k = 1; k != 5; ++k)
      v128[k + 8] |= ~v128[k];
    result = a1->numModels;
    v113 = skel + 48;
    if (a1->numModels) {
      v127 = a1;
      v126 = a1;
      v14 = skel + 48;
      v115 = (unsigned __int8 *)(v117 + 16);
      v128[0] = 0;
      v105 = (const DObj_s *)((char *)a1 + result);
      v111 = **(__int16 ***)a1->models;
      v15 = a1->modelParents[0];
      if (v15 == 0xFF)
        goto LABEL_41;
    LABEL_14:
      v16 = (float *)(32 * v15 + v113);
      v17 = v111[1];
      v18 = v17;
      if (v17) {
        v19 = v128[0];
        v106 = v128[0] + v18;
        do {
          v43 = 1 << (v19 & 0x1F);
          if ((v43 & v128[(v19 >> 5) + 9]) != 0) {
            if ((v43 & v128[(v19 >> 5) + 1]) != 0) {
              v44 = *v16;
              v45 = *(float *)(v14 + 12);
              v46 = v16[3];
              v47 = *(float *)v14;
              v48 = v16[2];
              v49 = *(float *)(v14 + 4);
              v50 = v16[1];
              v100 = *(float *)(v14 + 8);
              v95 = (float)((float)((float)(v45 * v46) -
                                    (float)(*v16 * *(float *)v14)) -
                            (float)(v49 * v50)) -
                    (float)(v100 * v48);
              *(float *)(v14 + 12) = v95;
              v97 = (float)((float)(v48 * v49) +
                            (float)((float)(v46 * v47) + (float)(v44 * v45))) -
                    (float)(v100 * v50);
              *(float *)v14 = v97;
              v103 = (float)(v100 * v44) +
                     (float)((float)(v46 * v49) +
                             (float)((float)(v45 * v50) - (float)(v47 * v48)));
              *(float *)(v14 + 4) = v103;
              v27 = (float)((float)((float)(v45 * v48) + (float)(v50 * v47)) -
                            (float)(v44 * v49)) +
                    (float)(v46 * v100);
            } else {
              v20 = *(float *)v14;
              v21 = v16[3];
              v22 = *(float *)(v14 + 12);
              v23 = *v16;
              v99 = *(float *)(v14 + 8);
              v24 = v16[1];
              v25 = *(float *)(v14 + 4);
              v26 = v16[2];
              v95 = (float)((float)((float)(v21 * v22) -
                                    (float)(*(float *)v14 * *v16)) -
                            (float)(v24 * v25)) -
                    (float)(v99 * v26);
              *(float *)(v14 + 12) = v95;
              v97 = (float)((float)(v99 * v24) +
                            (float)((float)(v22 * v23) + (float)(v20 * v21))) -
                    (float)(v25 * v26);
              *(float *)v14 = v97;
              v103 = (float)(v20 * v26) +
                     (float)((float)(v22 * v24) +
                             (float)((float)(v21 * v25) - (float)(v99 * v23)));
              *(float *)(v14 + 4) = v103;
              v27 = (float)(v26 * v22) +
                    (float)((float)((float)(v23 * v25) + (float)(v21 * v99)) -
                            (float)(v24 * v20));
            }
            *(float *)(v14 + 8) = v27;
            v28 = (float)((float)((float)(v97 * v97) + (float)(v103 * v103)) +
                          (float)(v27 * v27)) +
                  (float)(v95 * v95);
            if (v28 == 0.0) {
              *(_DWORD *)(v14 + 12) = 1065353216;
              *(_DWORD *)(v14 + 28) = 0x40000000;
            } else {
              *(float *)(v14 + 28) = 2.0 / v28;
            }
            v29 = v16[7] * *v16;
            v30 = v16[7] * v16[1];
            v31 = v16[7] * v16[2];
            v118 = v29 * *v16;
            v32 = v16[1];
            v33 = v29 * v32;
            v34 = v16[2];
            v35 = v29 * v34;
            v36 = v16[3];
            v37 = v29 * v36;
            v119 = v32 * v30;
            v120 = v30 * v34;
            v38 = v30 * v36;
            v39 = v31 * v34;
            v40 = v31 * v36;
            v41 = (float)((float)((float)((float)(1.0 - (float)(v119 + v39)) *
                                          *(float *)(v14 + 16)) +
                                  (float)((float)(v33 - v40) *
                                          *(float *)(v14 + 20))) +
                          (float)((float)(v35 + v38) * *(float *)(v14 + 24))) +
                  v16[4];
            v42 = (float)((float)((float)((float)(v33 + v40) *
                                          *(float *)(v14 + 16)) +
                                  (float)((float)(1.0 - (float)(v39 + v118)) *
                                          *(float *)(v14 + 20))) +
                          (float)((float)(v120 - v37) * *(float *)(v14 + 24))) +
                  v16[5];
            *(float *)(v14 + 24) =
                (float)((float)((float)((float)(v35 - v38) *
                                        *(float *)(v14 + 16)) +
                                (float)((float)(v37 + v120) *
                                        *(float *)(v14 + 20))) +
                        (float)((float)(1.0 - (float)(v118 + v119)) *
                                *(float *)(v14 + 24))) +
                v16[6];
            *(float *)(v14 + 16) = v41;
            *(float *)(v14 + 20) = v42;
          }
          v14 += 32;
          ++v19;
        } while (v106 != v19);
        v128[0] = v106;
        v51 = v111;
        v52 = v111;
      } else {
        v51 = v111;
        v52 = v111;
      }
      while (1) {
      LABEL_27:
        v114 = (float *)*((_DWORD *)v51 + 3);
        v112 = *((_DWORD *)v52 + 1) + 4;
        result = v52[1];
        v110 = *v52 - result;
        if (v110) {
          v125 = 0;
          v53 = (float *)(v14 + 16);
          while (1) {
            v78 = v128[0] >> 5;
            v79 = 1 << (v128[0] & 0x1F);
            if ((v79 & v128[(v128[0] >> 5) + 9]) != 0)
              break;
            if (*v115 - 1 != v128[0] ||
                (v80 = v115 + 2, v115 += 2, (v79 & v128[v78 + 5]) != 0)) {
            LABEL_34:
              v14 += 32;
              v53 += 8;
              v114 += 3;
              ++v128[0];
              result = ++v125;
              if (v110 == v125)
                goto LABEL_39;
            } else {
              v81 = 32 * (*(v80 - 1) - 1);
              *(v53 - 4) = *(float *)(v81 + v113);
              *(v53 - 3) = *(float *)(v81 + v113 + 4);
              *(v53 - 2) = *(float *)(v81 + v113 + 8);
              *(v53 - 1) = *(float *)(v81 + v113 + 12);
              *v53 = *(float *)(v81 + v113 + 16);
              v53[1] = *(float *)(v81 + v113 + 20);
              v53[2] = *(float *)(v81 + v113 + 24);
              v53[3] = *(float *)(v81 + v113 + 28);
              v14 += 32;
              v53 += 8;
              v114 += 3;
              ++v128[0];
              result = ++v125;
              if (v110 == v125)
                goto LABEL_39;
            }
          }
          v54 = 32 * *(unsigned __int8 *)(v112 + v125);
          if ((v79 & v128[v78 + 1]) != 0) {
            v88 = *(float *)(v14 - 32 * *(unsigned __int8 *)(v112 + v125));
            v89 = *(v53 - 1);
            v90 = *(float *)(v14 - v54 + 12);
            v91 = *(v53 - 4);
            v92 = *(float *)(v14 - v54 + 8);
            v93 = *(v53 - 3);
            v94 = *(float *)(v14 - v54 + 4);
            v102 = *(v53 - 2);
            v96 = (float)((float)((float)(v89 * v90) - (float)(v88 * v91)) -
                          (float)(v93 * v94)) -
                  (float)(v102 * v92);
            *(v53 - 1) = v96;
            v98 = (float)((float)(v92 * v93) +
                          (float)((float)(v90 * v91) + (float)(v88 * v89))) -
                  (float)(v102 * v94);
            *(v53 - 4) = v98;
            v104 = (float)(v102 * v88) +
                   (float)((float)(v90 * v93) +
                           (float)((float)(v89 * v94) - (float)(v91 * v92)));
            *(v53 - 3) = v104;
            v62 = (float)((float)((float)(v89 * v92) + (float)(v94 * v91)) -
                          (float)(v88 * v93)) +
                  (float)(v90 * v102);
          } else {
            v55 = *(v53 - 4);
            v56 = *(float *)(v14 - v54 + 12);
            v57 = *(v53 - 1);
            v58 = *(float *)(v14 - 32 * *(unsigned __int8 *)(v112 + v125));
            v101 = *(v53 - 2);
            v59 = *(float *)(v14 - v54 + 4);
            v60 = *(v53 - 3);
            v61 = *(float *)(v14 - v54 + 8);
            v96 = (float)((float)((float)(v56 * v57) - (float)(v55 * v58)) -
                          (float)(v59 * v60)) -
                  (float)(v101 * v61);
            *(v53 - 1) = v96;
            v98 = (float)((float)(v101 * v59) +
                          (float)((float)(v57 * v58) + (float)(v55 * v56))) -
                  (float)(v60 * v61);
            *(v53 - 4) = v98;
            v104 = (float)(v55 * v61) +
                   (float)((float)(v57 * v59) +
                           (float)((float)(v56 * v60) - (float)(v101 * v58)));
            *(v53 - 3) = v104;
            v62 = (float)(v61 * v57) +
                  (float)((float)((float)(v58 * v60) + (float)(v56 * v101)) -
                          (float)(v59 * v55));
          }
          *(v53 - 2) = v62;
          v63 = (float)((float)((float)(v98 * v98) + (float)(v104 * v104)) +
                        (float)(v62 * v62)) +
                (float)(v96 * v96);
          if (v63 == 0.0) {
            *(v53 - 1) = 1.0;
            v53[3] = 2.0;
          } else {
            v53[3] = 2.0 / v63;
          }
          v109 = *v53 + *v114;
          *v53 = v109;
          v108 = v53[1] + v114[1];
          v53[1] = v108;
          v64 = v53[2] + v114[2];
          v53[2] = v64;
          v65 = 32 * *(unsigned __int8 *)(v125 + v112);
          v66 = *(float *)(v14 - v65 + 28) * *(float *)(v14 - v65);
          v124 = *(float *)(v14 - v65 + 28) * *(float *)(v14 - v65 + 4);
          v67 = *(float *)(v14 - v65 + 28) * *(float *)(v14 - v65 + 8);
          v121 = v66 * *(float *)(v14 - v65);
          v68 = *(float *)(v14 - v65 + 4);
          v69 = v66 * v68;
          v70 = *(float *)(v14 - v65 + 8);
          v71 = v66 * v70;
          v72 = *(float *)(v14 - v65 + 12);
          v73 = v66 * v72;
          v122 = v68 * v124;
          v123 = v124 * v70;
          v74 = v67 * v70;
          v75 = v67 * v72;
          v76 = (float)((float)((float)((float)(1.0 - (float)(v122 + v74)) *
                                        v109) +
                                (float)((float)(v69 - v75) * v108)) +
                        (float)((float)((float)(v124 * v72) + v71) * v64)) +
                *(float *)(v14 - v65 + 16);
          v77 = (float)((float)((float)((float)(v69 + v75) * v109) +
                                (float)((float)(1.0 - (float)(v74 + v121)) *
                                        v108)) +
                        (float)((float)(v123 - v73) * v64)) +
                *(float *)(v14 - v65 + 20);
          v53[2] = (float)((float)((float)((float)(v71 - (float)(v124 * v72)) *
                                           v109) +
                                   (float)((float)(v73 + v123) * v108)) +
                           (float)(v64 * (float)(1.0 - (float)(v121 + v122)))) +
                   *(float *)(v14 - v65 + 24);
          *v53 = v76;
          v53[1] = v77;
          goto LABEL_34;
        }
      LABEL_39:
        v126 = (const DObj_s *)((char *)v126 + 4);
        v127 = (const DObj_s *)((char *)v127 + 1);
        if (v105 == v127)
          return result;
        v111 = **(__int16 ***)v126->models;
        v15 = v127->modelParents[0];
        if (v15 != 0xFF)
          goto LABEL_14;
      LABEL_41:
        v82 = v111[1];
        if (v82)
          break;
        v51 = v111;
        v52 = v111;
      }
      v83 = v128[0];
      v107 = v128[0] + v82;
      while (1) {
        v85 = 1 << (v83 & 0x1F);
        if ((v85 & v128[(v83 >> 5) + 9]) != 0)
          break;
        if (v83 != *v115 - 1 ||
            (v86 = v115 + 2, v115 += 2, (v85 & v128[(v83 >> 5) + 5]) != 0)) {
        LABEL_45:
          v14 += 32;
          if (v107 == ++v83)
            goto LABEL_50;
        } else {
          v87 = 32 * (*(v86 - 1) - 1);
          *(_DWORD *)v14 = *(_DWORD *)(v87 + v113);
          *(_DWORD *)(v14 + 4) = *(_DWORD *)(v87 + v113 + 4);
          *(_DWORD *)(v14 + 8) = *(_DWORD *)(v87 + v113 + 8);
          *(_DWORD *)(v14 + 12) = *(_DWORD *)(v87 + v113 + 12);
          *(_DWORD *)(v14 + 16) = *(_DWORD *)(v87 + v113 + 16);
          *(_DWORD *)(v14 + 20) = *(_DWORD *)(v87 + v113 + 20);
          *(_DWORD *)(v14 + 24) = *(_DWORD *)(v87 + v113 + 24);
          *(_DWORD *)(v14 + 28) = *(_DWORD *)(v87 + v113 + 28);
          v14 += 32;
          if (v107 == ++v83) {
          LABEL_50:
            v128[0] = v107;
            v51 = v111;
            v52 = v111;
            goto LABEL_27;
          }
        }
      }
      v84 =
          (float)((float)((float)(*(float *)v14 * *(float *)v14) +
                          (float)(*(float *)(v14 + 4) * *(float *)(v14 + 4))) +
                  (float)(*(float *)(v14 + 8) * *(float *)(v14 + 8))) +
          (float)(*(float *)(v14 + 12) * *(float *)(v14 + 12));
      if (v84 == 0.0) {
        *(_DWORD *)(v14 + 12) = 1065353216;
        *(_DWORD *)(v14 + 28) = 0x40000000;
      } else {
        *(float *)(v14 + 28) = 2.0 / v84;
      }
      goto LABEL_45;
    }
  }
  return result;
}

void __cdecl DObjCompleteHierarchyBits(struct DObj_s const *obj,
                                       int *const partBits) {
  int v2;              // ebx
  int v3;              // edx
  const DObj_s *v4;    // ecx
  _DWORD *v5;          // esi
  int v6;              // eax
  int i;               // edi
  int v8;              // edx
  int v9;              // eax
  int v10;             // ecx
  unsigned __int8 *k;  // edx
  unsigned __int8 v12; // al
  int j;               // [esp+1Ch] [ebp-5Ch]
  int v15;             // [esp+2Ch] [ebp-4Ch]
  __int16 *v16;        // [esp+30h] [ebp-48h]
  int v17;             // [esp+38h] [ebp-40h]
  unsigned int v18;    // [esp+3Ch] [ebp-3Ch]
  _DWORD v19[14];      // [esp+40h] [ebp-38h] BYREF

  v2 = a1->numBones - 1;
  if (!a1->duplicateParts)
    DObjCreateDuplicateParts((int)a1);
  v18 = SL_ConvertToString((unsigned __int16)a1->duplicateParts);
  v19[0] = 0;
  v16 = **(__int16 ***)a1->models;
  v3 = *v16;
  if (v2 < v3) {
    v15 = 0;
  } else {
    v4 = a1;
    v15 = 0;
    v5 = v19;
    do {
      ++v15;
      *++v5 = v3;
      v16 = **(__int16 ***)&v4->models[4];
      v3 += *v16;
      v4 = (const DObj_s *)((char *)v4 + 4);
    } while (v2 >= v3);
  }
  LOBYTE(v6) = (_BYTE)v16;
  v17 = *((_DWORD *)v16 + 1) + 4;
  for (i = v19[v15];; i = v19[v15]) {
    for (j = v2 - i; v2 - i >= 0; j = v2 - i) {
      v8 = v2 >> 5;
      v6 = a2[v8] >> (v2 & 0x1F);
      if ((v6 & 1) != 0) {
        if (((*(int *)(v18 + v8 * 4) >> (v2 & 0x1F)) & 1) != 0) {
          for (k = (unsigned __int8 *)(v18 + 16); v2 != *k - 1; k += 2)
            ;
          v10 = k[1] - 1;
        } else {
          v9 = v16[1];
          if (j - v9 < 0) {
            v12 = a1->modelParents[v15];
            v10 = v12;
            LOBYTE(v6) = v12 + 1;
            if (!(_BYTE)v6) {
              --v2;
              continue;
            }
          } else {
            v10 = v2 - *(unsigned __int8 *)(v17 + j - v9);
          }
        }
        v6 = 1 << (v10 & 0x1F);
        a2[v10 >> 5] |= v6;
      }
      --v2;
    }
    if (--v15 < 0)
      break;
    v6 = **(_DWORD **)&a1->models[4 * v15];
    v16 = (__int16 *)v6;
    v17 = *(_DWORD *)(v6 + 4) + 4;
  }
  return v6;
}

void __cdecl DObjGetHierarchyBits(struct DObj_s *obj, int boneIndex,
                                  int *const partBits) {
  int v3;               // esi
  int i;                // eax
  uint8_t numModels;    // bl
  __int16 *v6;          // eax
  int v7;               // edx
  int v8;               // ebx
  int v9;               // eax
  int v10;              // ebx
  unsigned __int8 v11;  // al
  int v12;              // edx
  _DWORD *v13;          // eax
  unsigned __int8 *v14; // edx
  DObj_s *v15;          // ecx
  __int16 *v17;         // [esp+1Ch] [ebp-6Ch]
  int j;                // [esp+44h] [ebp-44h]
  unsigned int v19;     // [esp+48h] [ebp-40h]
  int v20;              // [esp+4Ch] [ebp-3Ch]
  _DWORD v21[14];       // [esp+50h] [ebp-38h] BYREF

  v3 = a2;
  for (i = 0; i != 4; ++i)
    a3[i] = 0;
  numModels = a1->numModels;
  if (!a1->duplicateParts)
    DObjCreateDuplicateParts((int)a1);
  v19 = SL_ConvertToString((unsigned __int16)a1->duplicateParts);
  v21[0] = 0;
  v6 = **(__int16 ***)a1->models;
  v17 = v6;
  v7 = *v6;
  if (v7 > a2) {
    v20 = 0;
  LABEL_7:
    for (j = *((_DWORD *)v17 + 1) + 4;; v3 -= *(unsigned __int8 *)(v10 + j)) {
      v8 = v3 - v21[v20];
      while (1) {
        v9 = v3 >> 5;
        a3[v9] |= 1 << (v3 & 0x1F);
        if (((*(int *)(v19 + v9 * 4) >> (v3 & 0x1F)) & 1) != 0) {
          if (v3 == *(unsigned __int8 *)(v19 + 16) - 1) {
            v3 = *(unsigned __int8 *)(v19 + 17) - 1;
            v12 = v20;
          } else {
            v14 = (unsigned __int8 *)(v19 + 16);
            do
              v14 += 2;
            while (v3 != *v14 - 1);
            v3 = v14[1] - 1;
            v12 = v20;
          }
          goto LABEL_13;
        }
        v10 = v8 - v17[1];
        if (v10 >= 0)
          break;
        v11 = a1->modelParents[v20];
        v3 = v11;
        LOBYTE(v6) = v11 + 1;
        if (!(_BYTE)v6)
          return (char)v6;
        v12 = v20;
      LABEL_13:
        v13 = &v21[v12];
        do {
          --v12;
          v8 = v3 - *--v13;
        } while (v8 < 0);
        v17 = **(__int16 ***)&a1->models[4 * v12];
        j = *((_DWORD *)v17 + 1) + 4;
        v20 = v12;
      }
    }
  }
  if (numModels != 1) {
    v15 = a1;
    v20 = 1;
    while (1) {
      v21[v20] = v7;
      v17 = **(__int16 ***)&v15->models[4];
      v6 = (__int16 *)*v17;
      v7 += (int)v6;
      if (a2 < v7)
        break;
      ++v20;
      v15 = (DObj_s *)((char *)v15 + 4);
      if (v20 == numModels)
        return (char)v6;
    }
    goto LABEL_7;
  }
  return (char)v6;
}

int marker_dobj;
int __cdecl DObjGetBoneIndexInternal(struct DObj_s const *, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl DObjComputeBounds(struct DObj_s *) { UNIMPLEMENTED(); }

void __cdecl LocalInvMatrixTransformVectorQuatTrans(
    float const *const, struct DObjAnimMat_s const *, float *const) {
  UNIMPLEMENTED();
}

void __cdecl DObjCreateDuplicateParts(struct DObj_s const *) {
  UNIMPLEMENTED();
}

DObjBad(DObj_s const *obj) { UNIMPLEMENTED(); }
