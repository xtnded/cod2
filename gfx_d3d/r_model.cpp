public:
__cdecl _XMMATRIX::_XMMATRIX(void)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMLoadVector3(void const *)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMLoadFloat3(struct _XMFLOAT3 const *)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMLoadVector4A(void const *)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMLoadFloat4A(struct _XMFLOAT4 const *)
{
  UNIMPLEMENTED();
}

struct _XMMATRIX __cdecl XMLoadFloat4x4A(struct _XMFLOAT4X4 const *)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMLoadFloat4A16(struct _XMFLOAT4 const *)
{
  UNIMPLEMENTED();
}

struct _XMMATRIX __cdecl XMLoadFloat4x4A16(struct _XMFLOAT4X4 const *)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMVectorAdd(struct __vector4, struct __vector4)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMVectorMultiply(struct __vector4, struct __vector4)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMVector3Transform(struct __vector4, struct _XMMATRIX)
{
  UNIMPLEMENTED();
}

struct __vector4 __cdecl XMVector3TransformNormal(struct __vector4,
                                                  struct _XMMATRIX)
{
  UNIMPLEMENTED();
}

struct __vector4 &__cdecl operator+=(struct __vector4 &, struct __vector4)
{
  UNIMPLEMENTED();
}

public:
struct _XMMATRIX &__cdecl _XMMATRIX::operator=(struct _XMMATRIX const &)
{
  UNIMPLEMENTED();
}

int __cdecl FloatAsInt(float const *)
{
  UNIMPLEMENTED();
}

void __cdecl LocalConvertQuatToSkelMat(struct DObjAnimMat_s const *,
                                       struct DObjSkelMat_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Com_InitPrefetch(int, void const *)
{
  UNIMPLEMENTED();
}

void __cdecl MatrixTransformVertexAndBasis(float const *, float const *,
                                           float const *, float const *,
                                           struct DObjSkelMat_s const *,
                                           struct GfxVertex *)
{
  UNIMPLEMENTED();
}

void __cdecl LocalAddScaledMatrixTransformVector43(float const *const, float,
                                                   struct DObjSkelMat_s const *,
                                                   float *const)
{
  UNIMPLEMENTED();
}

struct DObj_s *__cdecl R_GetGfxEntityDObj(struct GfxSceneEntity *,
                                          struct GfxEntity *)
{
  int v3; // ebx

    if (a2->reType) {
      v3 = dword_1183A10;
      DObjSetModel((DObj_s *)dword_1183A10, (const XModel *)a1->u.obj);
      return (GfxModel)v3;
    }
    else {
      return a1->u;
    }
}

int __cdecl R_GetIgnorePrecacheErrors()
{
  return unk_1180902 != 0;
}

void __cdecl R_SetIgnorePrecacheErrors(int ignore)
{
  char *result; // eax

  result = rg;
  unk_1180902 = a1 != 0;
  return result;
}

struct GfxBrushModel *__cdecl R_RegisterInlineModel(int)
{
  return *(_DWORD *)(dword_1184B9C + 312) + 32 * a1;
}

void __cdecl R_GetRigidTransform(struct DObjSkelMat_s const *,
                                 float const *const, float const (*const)[3],
                                 float, float (*const)[3])
{
  UNIMPLEMENTED();
}

void __cdecl R_ModelBounds(struct GfxBrushModel *bmodel, float *const mins,
                           float *const maxs)
{
  int result; // eax

    if (a1) {
      *(_QWORD *)a2 = *(_QWORD *)&a1->bounds[0][0];
      a2[2] = a1->bounds[0][2];
      *(_QWORD *)a3 = *(_QWORD *)&a1->bounds[1][0];
      result = LODWORD(a1->bounds[1][2]);
      *((_DWORD *)a3 + 2) = result;
    }
    else {
      result = 0;
      *a2 = 0.0;
      a2[1] = 0.0;
      a2[2] = 0.0;
      *a3 = 0.0;
      a3[1] = 0.0;
      a3[2] = 0.0;
    }
  return result;
}

float __cdecl R_GetLodDist(float const *const, float)
{
  UNIMPLEMENTED();
}

void __cdecl R_SkinRigidXModelCmd(struct SkinRigidXModelCmd *skinRigidCmd)
{
  float v1;                // xmm3_4
  float v2;                // xmm6_4
  float v3;                // xmm1_4
  float v4;                // xmm4_4
  float v5;                // xmm5_4
  float v6;                // xmm2_4
  float v7;                // xmm7_4
  float v8;                // xmm0_4
  float v9;                // xmm3_4
  float v10;               // xmm4_4
  float v11;               // xmm6_4
  float v12;               // xmm2_4
  signed int result;       // eax
  _DWORD *surfs;           // edi
  SkinRigidXModelCmd *i;   // eax
  _DWORD *v16;             // eax
  SkinRigidXModelCmd *v17; // ebx
  int32_t e;               // esi
  _DWORD *v19;             // ebx
  int BoneOffset;          // eax
  signed int v21;          // [esp+30h] [ebp-78h]
  float v22;               // [esp+34h] [ebp-74h]
  float v23;               // [esp+38h] [ebp-70h]
  float v24;               // [esp+3Ch] [ebp-6Ch]
  float v25[26];           // [esp+40h] [ebp-68h] BYREF

  v1 = *(float *)&a1->mat[28] * *(float *)a1->mat;
  v2 = *(float *)&a1->mat[28] * *(float *)&a1->mat[4];
  v3 = *(float *)&a1->mat[28] * *(float *)&a1->mat[8];
  v22 = v1 * *(float *)a1->mat;
  v4 = *(float *)&a1->mat[4];
  v5 = v1 * v4;
  v6 = *(float *)&a1->mat[8];
  v7 = v1 * v6;
  v8 = *(float *)&a1->mat[12];
  v9 = v1 * v8;
  v23 = v4 * v2;
  v10 = v2 * v6;
  v11 = v2 * v8;
  v12 = v6 * v3;
  v25[0] = 1.0 - (float)(v23 + v12);
  v25[1] = (float)(v3 * v8) + v5;
  v25[2] = v7 - v11;
  v25[3] = 0.0;
  v25[4] = v5 - (float)(v3 * v8);
  v25[5] = 1.0 - (float)(v12 + v22);
  v25[6] = v9 + v10;
  v25[7] = 0.0;
  v25[8] = v7 + v11;
  v25[9] = v10 - v9;
  v25[10] = 1.0 - (float)(v22 + v23);
  v25[11] = 0.0;
  v25[12] = *(float *)&a1->mat[16];
  v25[13] = *(float *)&a1->mat[20];
  result = *(_DWORD *)&a1->mat[24];
  LODWORD(v25[14]) = result;
  v25[15] = 1.0;
  surfs = (_DWORD *)a1->surfs;
    if ((int)a1->surfCount > 0) {
      v21 = 0;
        for (i = a1;; i = v17) {
          e = i->e;
            if (*surfs == 5) {
              surfs += 4;
              result = ++v21;
              v17 = a1;
              if ((signed int)a1->surfCount <= v21)
                return result;
            }
            else {
                if (*surfs == 4) {
                  v19 = surfs;
                  surfs += 14;
                  v24 = *(float *)(e + 56);
                  BoneOffset =
                      XSurfaceGetBoneOffset((const XSurface_s *)v19[1]);
                  R_GetRigidTransform(
                      (const DObjSkelMat_s *)((char *)v25 + BoneOffset),
                      (const float *)(e + 60), (const float(*)[3])(e + 20), v24,
                      (float(*)[3])(v19 + 2));
                }
                else {
                  v16 = surfs;
                  surfs += 4;
                  R_SkinXSurfaceSkinned(v16, (int)v25);
                }
              result = ++v21;
              v17 = a1;
              if ((signed int)a1->surfCount <= v21)
                return result;
            }
        }
    }
  return result;
}

void __cdecl R_SkinXModelCmd(struct SkinXModelCmd *skinCmd, int context)
{
  float *v2;          // ebx
  int v3;             // edi
  int v4;             // esi
  float v5;           // xmm3_4
  float v6;           // xmm6_4
  float v7;           // xmm1_4
  float v8;           // xmm5_4
  float v9;           // xmm4_4
  float v10;          // xmm2_4
  float v11;          // xmm7_4
  float v12;          // xmm0_4
  float v13;          // xmm3_4
  float v14;          // xmm5_4
  float v15;          // xmm6_4
  float v16;          // xmm2_4
  int result;         // eax
  _DWORD *v18;        // edi
  SkinXModelCmd *v19; // edx
  _DWORD *v20;        // ebx
  float v21;          // esi
  int BoneOffset;     // eax
  _DWORD *v23;        // eax
  int v24;            // [esp+30h] [ebp-38h]
  int boneCount;      // [esp+38h] [ebp-30h]
  float v26;          // [esp+3Ch] [ebp-2Ch]
  float v27;          // [esp+40h] [ebp-28h]
  int32_t e;          // [esp+44h] [ebp-24h]
  char *v29;          // [esp+48h] [ebp-20h]
  SkinXModelCmd *v30; // [esp+4Ch] [ebp-1Ch]

  boneCount = a1->boneCount;
    if (a1->boneCount) {
      v2 = (float *)((char *)&g_skinBuffers + 40960 * a2);
      v3 = 0;
      v4 = a1->mat + 16;
        do {
            if (((*(int *)&a1->surfacePartBits[4 * (v3 >> 5)] >> (v3 & 0x1F)) &
                 1) != 0) {
              v5 = *(float *)(v4 + 12) * *(float *)(v4 - 16);
              v6 = *(float *)(v4 + 12) * *(float *)(v4 - 12);
              v7 = *(float *)(v4 + 12) * *(float *)(v4 - 8);
              v26 = v5 * *(float *)(v4 - 16);
              v8 = *(float *)(v4 - 12);
              v9 = v5 * v8;
              v10 = *(float *)(v4 - 8);
              v11 = v5 * v10;
              v12 = *(float *)(v4 - 4);
              v13 = v5 * v12;
              v27 = v8 * v6;
              v14 = v6 * v10;
              v15 = v6 * v12;
              v16 = v10 * v7;
              *v2 = 1.0 - (float)(v27 + v16);
              v2[1] = (float)(v7 * v12) + v9;
              v2[2] = v11 - v15;
              v2[3] = 0.0;
              v2[4] = v9 - (float)(v7 * v12);
              v2[5] = 1.0 - (float)(v16 + v26);
              v2[6] = v13 + v14;
              v2[7] = 0.0;
              v2[8] = v11 + v15;
              v2[9] = v14 - v13;
              v2[10] = 1.0 - (float)(v26 + v27);
              v2[11] = 0.0;
              v2[12] = *(float *)v4;
              v2[13] = *(float *)(v4 + 4);
              v2[14] = *(float *)(v4 + 8);
              v2[15] = 1.0;
            }
          ++v3;
          v4 += 32;
          v2 += 16;
        }
      while (boneCount != v3);
      result = (int)a1;
    }
    else {
      result = (int)a1;
    }
  v18 = *(_DWORD **)result;
    if (*(_BYTE *)(result + 28)) {
      v30 = (SkinXModelCmd *)result;
      v24 = 0;
      v19 = a1;
        while (1) {
          e = v19->e;
          v29 = (char *)&g_skinBuffers + 40960 * a2 + 64 * v30->matOffset[0];
          if (*v18 == 3)
            break;
            if (*v18 == 5) {
              v18 += 4;
            LABEL_10:
              ++v24;
              v30 = (SkinXModelCmd *)((char *)v30 + 1);
              v19 = a1;
              result = a1->surfCount;
              if (v24 >= result)
                return result;
            }
            else {
              v20 = v18;
              v18 += 14;
              v21 = *(float *)(e + 56);
              BoneOffset = XSurfaceGetBoneOffset((const XSurface_s *)v20[1]);
              R_GetRigidTransform((const DObjSkelMat_s *)&v29[BoneOffset],
                                  (const float *)(e + 60),
                                  (const float(*)[3])(e + 20), v21,
                                  (float(*)[3])(v20 + 2));
              ++v24;
              v30 = (SkinXModelCmd *)((char *)v30 + 1);
              v19 = a1;
              result = a1->surfCount;
              if (v24 >= result)
                return result;
            }
        }
      v23 = v18;
      v18 += 4;
      R_SkinXSurfaceSkinned(v23, (int)v29);
      goto LABEL_10;
    }
  return result;
}

struct XModel *__cdecl R_RegisterModel(char const *name)
{
  UNIMPLEMENTED();
}

void __cdecl R_DObjReplaceMaterial(struct DObj_s *obj, int lod,
                                   int surfaceIndex, struct Material *material)
{
  int NumModels;       // eax
  int i;               // edx
  int v6;              // ebx
  const XModel *Model; // eax
  int32_t result;      // eax
  DSurface_s v9[64];   // [esp+18h] [ebp-130h] BYREF
  int v10[4];          // [esp+118h] [ebp-30h] BYREF
  char v11[32];        // [esp+128h] [ebp-20h] BYREF

  NumModels = DObjGetNumModels(a1);
    if (NumModels > 0) {
      for (i = 0; i != NumModels; ++i)
        v11[i] = a2;
    }
  DObjGetSurfaces(a1, v9, v10, v11);
  v6 = *(__int16 *)v9[a3].modelIndex;
  Model = (const XModel *)DObjGetModel(a1, v6);
  result = XModelGetSkins(Model);
    if (result) {
      result = *(_DWORD *)(result + 4 * v11[v6]);
      *(_DWORD *)(result + 4 * (__int16)v9[a3].subMatIndex) = a4;
    }
  return result;
}

void __cdecl R_DObjGetSurfMaterials(struct DObj_s *obj, int lod,
                                    struct Material **matHandleArray)
{
  int NumModels;       // eax
  int i;               // edx
  Material *result;    // eax
  Material *v6;        // esi
  int v7;              // ebx
  const XModel *Model; // eax
  int32_t Skins;       // eax
  Material *v10;       // [esp+1Ch] [ebp-13Ch]
  DSurface_s v11[64];  // [esp+28h] [ebp-130h] BYREF
  int v12[4];          // [esp+128h] [ebp-30h] BYREF
  char v13[32];        // [esp+138h] [ebp-20h] BYREF

  NumModels = DObjGetNumModels(a1);
    if (NumModels > 0) {
      for (i = 0; i != NumModels; ++i)
        v13[i] = a2;
    }
  result = (Material *)DObjGetSurfaces(a1, v11, v12, v13);
  v10 = result;
    if ((int)result > 0) {
      v6 = 0;
        do {
          v7 = *(__int16 *)v11[(_DWORD)v6].modelIndex;
          Model = (const XModel *)DObjGetModel(a1, v7);
          Skins = XModelGetSkins(Model);
            if (Skins) {
              result = *(Material **)(*(_DWORD *)(Skins + 4 * v13[v7]) +
                                      4 * (__int16)v11[(_DWORD)v6].subMatIndex);
              a3[(_DWORD)v6] = result;
            }
            else {
              result = (Material *)a3;
              a3[(_DWORD)v6] = 0;
            }
          v6 = (Material *)((char *)v6 + 1);
        }
      while (v10 != v6);
    }
  return result;
}

void __cdecl R_UpdateXModelBounds(struct GfxSceneEntity *sceneEnt,
                                  struct GfxEntity *ent)
{
  int32_t cullState;     // eax
  bool v3;               // cc
  int result;            // eax
  int32_t v5;            // eax
  DObj_s *obj;           // ebx
  const centity_s *cent; // eax
  int32_t RotTransArray; // esi
  int v9;                // eax
  float v10;             // xmm4_4
  float v11;             // xmm3_4
  float v12;             // xmm5_4
  float v13;             // xmm2_4
  float v14;             // xmm1_4
  float v15;             // xmm6_4
  float v16;             // xmm7_4
  float v17;             // xmm0_4
  float v18;             // xmm4_4
  float v19;             // xmm5_4
  float v20;             // xmm2_4
  float v21;             // xmm1_4
  XBoneInfo_s *v22;      // edx
  __m128 v23;            // xmm2
  int v24;               // eax
  __m128 v25;            // xmm1
  int v26;               // eax
  int v27;               // eax
  __int32 v28;           // xmm6_4
  __m128 v29;            // xmm1
  __m128 v30;            // xmm0
  __m128 v31;            // xmm2
  int v32;               // eax
  __m128 v33;            // xmm1
  int v34;               // eax
  int v35;               // eax
  __int32 v36;           // xmm3_4
  __m128 v37;            // xmm1
  __m128 v38;            // xmm0
  __m128 v39;            // xmm2
  int v40;               // eax
  __m128 v41;            // xmm1
  float *v42;            // ebx
  int v43;               // eax
  int v44;               // eax
  __int32 v45;           // xmm3_4
  __m128 v46;            // xmm1
  __m128 v47;            // xmm0
  unsigned int v48;      // [esp+30h] [ebp-398h]
  int v49;               // [esp+38h] [ebp-390h]
  int v50;               // [esp+3Ch] [ebp-38Ch]
  float v51;             // [esp+40h] [ebp-388h]
  float v52;             // [esp+44h] [ebp-384h]
  float v53;             // [esp+48h] [ebp-380h]
  int32_t v54;           // [esp+4Ch] [ebp-37Ch]
  XBoneInfo_s *v55[128]; // [esp+5Ch] [ebp-36Ch] BYREF
  DSurface_s v56;        // [esp+25Ch] [ebp-16Ch] BYREF
  float v57;             // [esp+35Ch] [ebp-6Ch]
  float v58;             // [esp+360h] [ebp-68h]
  float v59;             // [esp+364h] [ebp-64h]
  float v60;             // [esp+368h] [ebp-60h]
  float v61;             // [esp+36Ch] [ebp-5Ch]
  float v62;             // [esp+370h] [ebp-58h]
  float v63;             // [esp+374h] [ebp-54h]
  float v64;             // [esp+378h] [ebp-50h]
  float v65;             // [esp+37Ch] [ebp-4Ch]
  unsigned __int32 v66;  // [esp+380h] [ebp-48h] BYREF
  unsigned __int32 v67;  // [esp+384h] [ebp-44h]
  unsigned __int32 v68;  // [esp+388h] [ebp-40h]
  unsigned __int32 v69;  // [esp+38Ch] [ebp-3Ch] BYREF
  unsigned __int32 v70;  // [esp+390h] [ebp-38h]
  unsigned __int32 v71;  // [esp+394h] [ebp-34h]
  int v72[4];            // [esp+398h] [ebp-30h] BYREF
  char v73;              // [esp+3A8h] [ebp-20h] BYREF

  cullState = a1->cullState;
  v3 = cullState <= 1;
  result = cullState - 1;
  if (!v3)
    return result;
    if (InterlockedCompareExchange((int)&a1->cullState, 1, 0)) {
        do {
          v5 = a1->cullState;
          v3 = v5 <= 1;
          result = v5 - 1;
        }
      while (v3);
      return result;
    }
    if (a2->reType) {
      obj = (DObj_s *)dword_1183A10;
      DObjSetModel((DObj_s *)dword_1183A10, (const XModel *)a1->u.obj);
    }
    else {
      obj = (DObj_s *)a1->u.obj;
    }
    if (DObjBad(obj)) {
        if (*(_DWORD *)(developer + 8)) {
          R_XModelDebugBoxes((int)a1, (float *)&a2->reType, obj);
          R_XModelDebugAxes((int)a1, (float *)&a2->reType, obj);
        }
    LABEL_13:
      a1->curMins[0] = a2->origin[0];
      a1->curMins[1] = a2->origin[1];
      a1->curMins[2] = a2->origin[2];
      a1->curMaxs[0] = a2->origin[0];
      a1->curMaxs[1] = a2->origin[1];
      result = LODWORD(a2->origin[2]);
      LODWORD(a1->curMaxs[2]) = result;
      a1->cullState = 2;
      return result;
    }
  if (!R_GetSurfaceData((int)a2, obj, &v56, (GfxEntity *)v72, (DObj_s *)&v73))
    goto LABEL_13;
  cent = (const centity_s *)a1->cent;
  if (cent)
    CG_DObjCalcPose(cent, obj, v72);
  RotTransArray = DObjGetRotTransArray(obj);
  if (!RotTransArray)
    goto LABEL_13;
  ClearBounds(&v66, &v69);
  DObjGetBoneInfo(obj, v55);
  v50 = DObjNumBones(obj);
    if (v50 > 0) {
      v54 = RotTransArray;
      v49 = 0;
      v9 = 0;
        do {
            if (((v72[v9 >> 5] >> (v49 & 0x1F)) & 1) != 0) {
              v10 = *(float *)(v54 + 28) * *(float *)v54;
              v11 = *(float *)(v54 + 4);
              v12 = *(float *)(v54 + 28) * v11;
              v13 = *(float *)(v54 + 8);
              v14 = *(float *)(v54 + 28) * v13;
              v51 = *(float *)v54 * v10;
              v15 = v10 * v11;
              v16 = v10 * v13;
              v17 = *(float *)(v54 + 12);
              v18 = v10 * v17;
              v52 = v11 * v12;
              v53 = v12 * v13;
              v19 = v12 * v17;
              v20 = v13 * v14;
              v21 = v14 * v17;
              v57 = 1.0 - (float)(v52 + v20);
              *(float *)&v48 = v15 + v21;
              v58 = v15 + v21;
              v59 = v16 - v19;
              v60 = v15 - v21;
              v61 = 1.0 - (float)(v20 + v51);
              v62 = v53 + v18;
              v63 = v16 + v19;
              v64 = v53 - v18;
              v65 = 1.0 - (float)(v51 + v52);
              v22 = v55[v49];
              v23 = (__m128) * (unsigned int *)(v54 + 16);
              v24 = (SLODWORD(v57) >> 31) & 0xC;
              v25 = (__m128) * (unsigned int *)((char *)v22->bounds[0] + v24);
              v25.f32[0] = (float)(v25.f32[0] * v57) + v23.f32[0];
              v23.f32[0] =
                  v23.f32[0] +
                  (float)(v57 * *(float *)((char *)v22->bounds[1] - v24));
              v26 = (SLODWORD(v60) >> 31) & 0xC;
              v25.f32[0] =
                  v25.f32[0] +
                  (float)(*(float *)((char *)&v22->bounds[0][1] + v26) * v60);
              v23.f32[0] =
                  v23.f32[0] +
                  (float)(v60 * *(float *)((char *)&v22->bounds[1][1] - v26));
              v27 = (COERCE_INT(v16 + v19) >> 31) & 0xC;
              v25.f32[0] =
                  v25.f32[0] +
                  (float)(*(float *)((char *)&v22->bounds[0][2] + v27) *
                          (float)(v16 + v19));
              v23.f32[0] =
                  v23.f32[0] +
                  (float)((float)(v16 + v19) *
                          *(float *)((char *)&v22->bounds[1][2] - v27));
              v28 = v25.i32[0];
              v29 = _mm_cmplt_ss(v25, (__m128)v66);
              v66 = _mm_andnot_ps(v29, (__m128)v66).u32[0] | v28 & v29.i32[0];
              v30 = _mm_cmpge_ss((__m128)v69, v23);
              v69 = _mm_andnot_ps(v30, v23).u32[0] | v69 & v30.i32[0];
              v31 = (__m128) * (unsigned int *)(v54 + 20);
              v32 = (SLODWORD(v58) >> 31) & 0xC;
              v33 = (__m128)v48;
              v33.f32[0] = (float)(*(float *)&v48 *
                                   *(float *)((char *)v22->bounds[0] + v32)) +
                           v31.f32[0];
              v31.f32[0] = v31.f32[0] +
                           (float)(*(float *)&v48 *
                                   *(float *)((char *)v22->bounds[1] - v32));
              v34 = (SLODWORD(v61) >> 31) & 0xC;
              v33.f32[0] =
                  v33.f32[0] +
                  (float)(*(float *)((char *)&v22->bounds[0][1] + v34) * v61);
              v31.f32[0] =
                  v31.f32[0] +
                  (float)(v61 * *(float *)((char *)&v22->bounds[1][1] - v34));
              v35 = (COERCE_INT(v53 - v18) >> 31) & 0xC;
              v33.f32[0] =
                  v33.f32[0] +
                  (float)(*(float *)((char *)&v22->bounds[0][2] + v35) *
                          (float)(v53 - v18));
              v31.f32[0] =
                  v31.f32[0] +
                  (float)((float)(v53 - v18) *
                          *(float *)((char *)&v22->bounds[1][2] - v35));
              v36 = v33.i32[0];
              v37 = _mm_cmplt_ss(v33, (__m128)v67);
              v67 = _mm_andnot_ps(v37, (__m128)v67).u32[0] | v36 & v37.i32[0];
              v38 = _mm_cmpge_ss((__m128)v70, v31);
              v70 = _mm_andnot_ps(v38, v31).u32[0] | v70 & v38.i32[0];
              v39 = (__m128) * (unsigned int *)(v54 + 24);
              v40 = (COERCE_INT(v16 - v19) >> 31) & 0xC;
              v41 = (__m128)COERCE_UNSIGNED_INT(v16 - v19);
              v41.f32[0] = (float)((float)(v16 - v19) *
                                   *(float *)((char *)v22->bounds[0] + v40)) +
                           v39.f32[0];
              v42 = (float *)((char *)v22->bounds[1] - v40);
              v43 = (COERCE_INT(v53 + v18) >> 31) & 0xC;
              v41.f32[0] =
                  v41.f32[0] +
                  (float)((float)(v53 + v18) *
                          *(float *)((char *)&v22->bounds[0][1] + v43));
              v39.f32[0] =
                  (float)(v39.f32[0] + (float)((float)(v16 - v19) * *v42)) +
                  (float)((float)(v53 + v18) *
                          *(float *)((char *)&v22->bounds[1][1] - v43));
              v44 = (SLODWORD(v65) >> 31) & 0xC;
              v41.f32[0] =
                  v41.f32[0] +
                  (float)(*(float *)((char *)&v22->bounds[0][2] + v44) * v65);
              v39.f32[0] =
                  v39.f32[0] +
                  (float)(v65 * *(float *)((char *)&v22->bounds[1][2] - v44));
              v45 = v41.i32[0];
              v46 = _mm_cmplt_ss(v41, (__m128)v68);
              v68 = _mm_andnot_ps(v46, (__m128)v68).u32[0] | v45 & v46.i32[0];
              v47 = _mm_cmpge_ss((__m128)v71, v39);
              v71 = _mm_andnot_ps(v47, v39).u32[0] | v71 & v47.i32[0];
            }
          ++v49;
          v54 += 32;
          v9 = v49;
        }
      while (v50 != v49);
    }
  result =
      GetRotatedBounds((int)&v66, (int)a2->origin, (int)a2->axis, a1->curMins);
  a1->cullState = 2;
  return result;
}

void __cdecl R_SkinSceneDObj(struct GfxSceneEntity *sceneEnt,
                             struct GfxEntity *ent)
{
  int result;                  // eax
  DObj_s *obj;                 // esi
  int v4;                      // edx
  unsigned __int8 *v5;         // edi
  size_t v6;                   // edi
  int v7;                      // edx
  char *v8;                    // eax
  int v9;                      // eax
  int v10;                     // edx
  int i;                       // edi
  int v12;                     // [esp+8h] [ebp-FF0h]
  DSurface_s *v13;             // [esp+2Ch] [ebp-FCCh]
  int v14;                     // [esp+30h] [ebp-FC8h]
  int v15;                     // [esp+34h] [ebp-FC4h]
  int v16;                     // [esp+38h] [ebp-FC0h]
  int v17;                     // [esp+3Ch] [ebp-FBCh]
  unsigned __int8 __src[3584]; // [esp+4Ch] [ebp-FACh] BYREF
  DSurface_s v19[64];          // [esp+E4Ch] [ebp-1ACh] BYREF
  _DWORD v20[3];               // [esp+F4Ch] [ebp-ACh] BYREF
  GfxEntity v21;               // [esp+F58h] [ebp-A0h] BYREF
  int v22;                     // [esp+FCCh] [ebp-2Ch]
  int v23;                     // [esp+FD0h] [ebp-28h]
  int v24;                     // [esp+FD4h] [ebp-24h]
  char v25[32];                // [esp+FD8h] [ebp-20h] BYREF

  result = a1->cullState;
    if (result <= 3) {
        if (InterlockedCompareExchange((int)&a1->cullState, 3, 2) == 2) {
          obj = (DObj_s *)a1->u.obj;
            if (DObjBad(obj)) {
              result = developer;
                if (*(_DWORD *)(developer + 8)) {
                  R_XModelDebugBoxes((int)a1, (float *)&a2->reType, obj);
                  result =
                      R_XModelDebugAxes((int)a1, (float *)&a2->reType, obj);
                }
            }
            else {
              v15 = DObjNumBones(obj);
              result = R_GetSurfaceData((int)a2, obj, v19, &v21, (DObj_s *)v25);
              v14 = result;
                if (result) {
                  result = DObjGetRotTransArray(obj);
                  v16 = result;
                    if (result) {
                      v4 = InterlockedExchangeAdd((int)&dword_116F55C, v14);
                        if ((unsigned int)(v4 + v14) <= 0x1000) {
                          a1->materials = (int32_t)(&scene + v4 + 26968);
                            if (v14 <= 0) {
                              v5 = __src;
                            LABEL_19:
                              v6 = v5 - __src;
                              v7 = InterlockedExchangeAdd(
                                  (int)frontEndDataOut + 524296, v6);
                                if (v6 + v7 <= (unsigned int)&loc_20000) {
                                  v8 = (char *)frontEndDataOut + v7 + 524300;
                                  a1->surfs = (int32_t)v8;
                                  memcpy(v8, __src, v6);
                                  a1->surfCount = v14;
                                  v9 = r_xdebug;
                                  v10 = *(_DWORD *)(r_xdebug + 8);
                                    if (v10) {
                                        if ((v10 & 1) != 0) {
                                          R_XModelDebugBoxes(
                                              (int)a1, (float *)&a2->reType,
                                              obj);
                                          v9 = r_xdebug;
                                        }
                                      if ((*(_BYTE *)(v9 + 8) & 2) != 0)
                                        R_XModelDebugAxes(
                                            (int)a1, (float *)&a2->reType, obj);
                                    }
                                    if (v15 == 1) {
                                      v21.customMaterial = a1->surfs;
                                      v21.materialRGBA = v14;
                                      v21.materialTime = (uint32_t)a2;
                                      v21.materialSubimageIndex =
                                          *(_DWORD *)v16;
                                      v21.radius = *(_QWORD *)(v16 + 4);
                                      v21.rotation = *(_DWORD *)(v16 + 12);
                                      v21.minScreenRadius =
                                          *(_DWORD *)(v16 + 16);
                                      v22 = *(_DWORD *)(v16 + 20);
                                      v23 = *(_DWORD *)(v16 + 24);
                                      v24 = *(_DWORD *)(v16 + 28);
                                      result = R_AddFrontendCmd(
                                          2, &v21.customMaterial, v12);
                                    }
                                    else {
                                        if (v14 > 0) {
                                          for (i = 0; i != v14; ++i)
                                            *((_BYTE *)&v21.lighting.origin[2] +
                                              i + 2) =
                                                DObjGetMatOffset(
                                                    obj, *(__int16 *)v19[i]
                                                              .modelIndex);
                                        }
                                      v20[0] = a1->surfs;
                                      LOBYTE(v21.lighting.origin[2]) = v14;
                                      v20[1] = a2;
                                      v20[2] = v16;
                                      BYTE1(v21.lighting.origin[2]) = v15;
                                      result = R_AddFrontendCmd((v14 > 10) + 6,
                                                                v20, v12);
                                    }
                                }
                                else {
                                  *((_DWORD *)frontEndDataOut + 131074) =
                                      &loc_20000;
                                  result = *(_DWORD *)frontEndDataOut;
                                    if (*(_DWORD *)frontEndDataOut !=
                                        R_SkinSceneDObj(
                                            GfxSceneEntity *,
                                            GfxEntity *)::warnCount) {
                                      R_SkinSceneDObj(GfxSceneEntity *,
                                                      GfxEntity *)::warnCount =
                                          *(_DWORD *)frontEndDataOut;
                                      result = ri(
                                          2,
                                          "MAX_SCENE_SURFS_SIZE exceeded - not "
                                          "drawing surface\n");
                                    }
                                }
                            }
                            else {
                              v17 = 0;
                              v5 = __src;
                              v13 = v19;
                                for (result = R_PreSkinXSurface(a1, obj, v19, 0,
                                                                v25, __src);
                                     result; result = R_PreSkinXSurface(
                                                 a1, obj, v13, v17, v25, v5)) {
                                  v5 += result;
                                  ++v17;
                                  ++v13;
                                  if (v14 == v17)
                                    goto LABEL_19;
                                }
                            }
                        }
                        else {
                          dword_116F55C = 4096;
                          result = *(_DWORD *)frontEndDataOut;
                            if (*(_DWORD *)frontEndDataOut !=
                                R_SkinSceneDObj(GfxSceneEntity *,
                                                GfxEntity *)::warnCount) {
                              R_SkinSceneDObj(GfxSceneEntity *,
                                              GfxEntity *)::warnCount =
                                  *(_DWORD *)frontEndDataOut;
                              result = ri(2, "MAX_SCENE_MATERIALS exceeded - "
                                             "not drawing surface\n");
                            }
                        }
                    }
                }
            }
          a1->cullState = 4;
        }
        else {
          do
            result = a1->cullState;
          while (result <= 3);
        }
    }
  return result;
}

void __cdecl R_SkinStaticModel(struct GfxSceneEntity *sceneEnt,
                               struct GfxEntity *ent, int smodelIndex)
{
  return R_SkinXModel(a1, a2, a3);
}

void __cdecl R_SkinSceneEnt(struct GfxSceneEntity *sceneEnt,
                            struct GfxEntity *ent)
{
  if (a2->reType == 1)
    return R_SkinXModel(a1, a2, -1);
  else
    return R_SkinSceneDObj(a1, a2);
}

int marker_r_model;

void __cdecl R_PostXModelBounds(struct GfxSceneEntity *)
{
  UNIMPLEMENTED();
}

void __cdecl R_PostSkinXModel(struct GfxSceneEntity *)
{
  UNIMPLEMENTED();
}

struct trXSkin_t const *__cdecl R_DObjGetXSkins(struct DObj_s const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl LocalExpandRotatedBounds(float const (*const)[3],
                                      float const *const,
                                      float const (*const)[3],
                                      float (*const)[3])
{
  UNIMPLEMENTED();
}

void __cdecl R_SetNoBounds(struct GfxSceneEntity *, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl R_SkinXSurfaceRigid(struct GfxVertex *, struct XSurface_s const *,
                                 struct DObjSkelMat_s const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl R_SkinXSurfaceWeight(struct GfxVertex *, struct XSurface_s const *,
                                  struct DObjSkelMat_s const *)
{
  UNIMPLEMENTED();
}

int __cdecl R_AllocSkinnedCachedVerts(int)
{
  UNIMPLEMENTED();
}

void __cdecl R_CalcXModelMatArray(struct SkinXModelCmd *,
                                  struct DObjSkelMat_s *)
{
  UNIMPLEMENTED();
}

int __cdecl R_PreSkinXSurface(struct GfxSceneEntity *, struct DObj_s const *,
                              struct DSurface_s *, int, char *const,
                              unsigned char *)
{
  int v6;                    // esi
  const XModel *Model;       // eax
  int32_t Skins;             // eax
  int v9;                    // ebx
  const XSurface_s *Surface; // esi
  int NumVerts;              // ecx
  int v13;                   // edx
  int v14;                   // eax
  int *v15;                  // ecx
  int *v16;                  // edx
  int v17;                   // ebx
  int v18;                   // eax
  int v19;                   // ecx
  int v20;                   // ecx

  v6 = *(__int16 *)a3->modelIndex;
  Model = (const XModel *)DObjGetModel(a2, v6);
  Skins = XModelGetSkins(Model);
  if (!Skins)
    return 0;
  v9 = *(_DWORD *)(*(_DWORD *)(Skins + 4 * a5[v6]) +
                   4 * (__int16)a3->subMatIndex);
  Surface = (const XSurface_s *)DObjGetSurface(a2, v6, (__int16)a3->subMatIndex,
                                               a5[v6]);
  *(_DWORD *)(a1->materials + 4 * a4) = v9;
    if (Surface->surfRigid.vb) {
      *(_DWORD *)a6 = 4;
      *((_DWORD *)a6 + 1) = Surface;
      return 56;
    }
  if (!*(_BYTE *)(r_skinCache + 8) || !Surface->indexBuffer)
    goto LABEL_19;
  *((_DWORD *)a6 + 3) = 0;
  NumVerts = XSurfaceGetNumVerts(Surface);
  if (!unk_1180660)
    goto LABEL_15;
  v13 = 36;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2)
    v13 = 64;
  v14 = InterlockedExchangeAdd(*((_DWORD *)frontEndDataOut + 548638),
                               NumVerts * v13);
  v15 = (int *)frontEndDataOut;
  v16 = (int *)*((_DWORD *)frontEndDataOut + 548638);
  v17 = v16[1];
    if (*v16 > v17) {
        if (v14 <= v17) {
          InterlockedExchange(v16, v14);
          v15 = (int *)frontEndDataOut;
        }
        if (*v15 != R_AllocSkinnedCachedVerts(int)::warnCount) {
          R_AllocSkinnedCachedVerts(int)::warnCount = *v15;
          ri(2,
             "R_MAX_SKINNED_CACHE_VERTICES exceeded - not drawing surface\n");
        }
    LABEL_15:
      v14 = -1;
    }
  *((_DWORD *)a6 + 2) = v14;
  if (v14 >= 0 && **((_DWORD **)frontEndDataOut + 548638) + unk_1180660)
    goto LABEL_18;
LABEL_19:
  *((_DWORD *)a6 + 2) = -1;
  v18 = XSurfaceGetNumVerts(Surface);
  v19 = 36;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2)
    v19 = 64;
  v20 = v18 * v19;
    if (v20 + dword_1180674 <= (int)&unk_A00000) {
      *((_DWORD *)a6 + 3) = dword_1180670 + dword_1180674;
      dword_1180674 += v20;
      unk_11806E4(*((_DWORD *)a6 + 3), v20);
    LABEL_18:
      *(_DWORD *)a6 = 3;
      *((_DWORD *)a6 + 1) = Surface;
      return 16;
    }
  if (*(_DWORD *)frontEndDataOut ==
      R_PreSkinXSurface(GfxSceneEntity *, DObj_s const *, DSurface_s *, int,
                        char *, unsigned char *)::warnCount)
    return 0;
  R_PreSkinXSurface(GfxSceneEntity *, DObj_s const *, DSurface_s *, int, char *,
                    unsigned char *)::warnCount = *(_DWORD *)frontEndDataOut;
  ri(2, "TEMP_SKIN_BUF_SIZE exceeded - not skinning surface\n");
  return 0;
}

void __cdecl R_GetRigidXSurfaceTransform(struct XSurface_s const *,
                                         struct DObjSkelMat_s const *const,
                                         float const *const,
                                         float const (*const)[3], float,
                                         float (*const)[3])
{
  UNIMPLEMENTED();
}

enum surfaceType_t *__cdecl R_SkinRigidXSurface(struct GfxEntity *,
                                                struct DObjSkelMat_s *,
                                                enum surfaceType_t *)
{
  UNIMPLEMENTED();
}

void __cdecl R_SkinXSurfaceWeightAltivec(struct GfxVertex *,
                                         struct XSurface_s const *,
                                         struct DObjSkelMat_s const *)
{
  UNIMPLEMENTED();
}

int __cdecl R_PreSkinStaticSurface(struct GfxSceneEntity *, struct GfxEntity *,
                                   int, struct XModel const *,
                                   struct XSurface_s *, int, int, int *,
                                   unsigned char *)
{
  int32_t Skins;                    // eax
  const Material *v10;              // ebx
  GfxStaticSurface *v12;            // edx
  GfxStaticModelSurfaceCached *v13; // eax
  int v14;                          // eax
  int NumVerts;                     // ecx
  int v16;                          // edx
  int v17;                          // eax
  int *v18;                         // ebx
  int *v19;                         // edx
  int v20;                          // ecx
  int v21;                          // eax
  int v22;                          // ecx
  int v23;                          // ecx
  GfxStaticSurface *v24;            // [esp+1Ch] [ebp-1Ch]

  Skins = XModelGetSkins(a4);
  if (!Skins)
    return 0;
  v10 = *(const Material **)(4 * a6 + *(_DWORD *)(Skins + 4 * a7));
  *(_DWORD *)(a1->materials + 4 * a6) = v10;
    if (a2->reType == 2) {
        if (*(_BYTE *)(r_smc_enable + 8)) {
            if (XSurfaceGetBoneOffset(a5) != -1 &&
                (*(_DWORD *)(r_rendererInUse + 8) != 2 ||
                 (v14 = *(_DWORD *)(v10->techniqueSet + 52)) != 0 &&
                     *(_WORD *)(v14 + 6) && *(_BYTE *)(v14 + 12))) {
              v12 = (GfxStaticSurface
                         *)(*(_DWORD *)(*(_DWORD *)&algn_1183A7C[24] + 8 * a3 +
                                        4) +
                            16 * a6);
              v24 = v12;
              v13 = *(GfxStaticModelSurfaceCached **)&v12->cachedLods[4 * a7];
                if (v13 || (v13 = (GfxStaticModelSurfaceCached *)
                                R_CacheStaticModelSurface(v12, a5, a3, v10),
                            (*(_DWORD *)&v24->cachedLods[4 * a7] = v13) != 0)) {
                  R_UsedCachedStaticModelSurface(v13);
                  *(_DWORD *)a9 = 5;
                  *((_DWORD *)a9 + 1) = a5;
                  *((_DWORD *)a9 + 2) = *(_DWORD *)&v24->cachedLods[4 * a7];
                  *((_DWORD *)a9 + 3) = a2;
                  return 16;
                }
            }
        }
    }
    if (a5->surfRigid.vb) {
      *(_DWORD *)a9 = 4;
      *((_DWORD *)a9 + 1) = a5;
      *a8 = 1;
      return 56;
    }
  if (!*(_BYTE *)(r_skinCache + 8) || !a5->indexBuffer)
    goto LABEL_29;
  *((_DWORD *)a9 + 3) = 0;
  NumVerts = XSurfaceGetNumVerts(a5);
  if (!unk_1180660)
    goto LABEL_25;
  v16 = 36;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2)
    v16 = 64;
  v17 = InterlockedExchangeAdd(*((_DWORD *)frontEndDataOut + 548638),
                               NumVerts * v16);
  v18 = (int *)frontEndDataOut;
  v19 = (int *)*((_DWORD *)frontEndDataOut + 548638);
  v20 = v19[1];
    if (*v19 > v20) {
        if (v17 <= v20) {
          InterlockedExchange(v19, v17);
          v18 = (int *)frontEndDataOut;
        }
        if (*v18 != R_AllocSkinnedCachedVerts(int)::warnCount) {
          R_AllocSkinnedCachedVerts(int)::warnCount = *v18;
          ri(2,
             "R_MAX_SKINNED_CACHE_VERTICES exceeded - not drawing surface\n");
        }
    LABEL_25:
      v17 = -1;
    }
  *((_DWORD *)a9 + 2) = v17;
  if (v17 >= 0 && **((_DWORD **)frontEndDataOut + 548638) + unk_1180660)
    goto LABEL_28;
LABEL_29:
  *((_DWORD *)a9 + 2) = -1;
  v21 = XSurfaceGetNumVerts(a5);
  v22 = 36;
  if (*(_DWORD *)(r_rendererInUse + 8) != 2)
    v22 = 64;
  v23 = v21 * v22;
    if (v23 + dword_1180674 <= (int)&unk_A00000) {
      *((_DWORD *)a9 + 3) = dword_1180670 + dword_1180674;
      dword_1180674 += v23;
      unk_11806E4(*((_DWORD *)a9 + 3), v23);
    LABEL_28:
      *(_DWORD *)a9 = 3;
      *((_DWORD *)a9 + 1) = a5;
      *a8 = 1;
      return 16;
    }
  if (*(_DWORD *)frontEndDataOut ==
      R_PreSkinStaticSurface(GfxSceneEntity *, GfxEntity *, int, XModel const *,
                             XSurface_s *, int, int, int *,
                             unsigned char *)::warnCount)
    return 0;
  R_PreSkinStaticSurface(
      GfxSceneEntity *, GfxEntity *, int, XModel const *, XSurface_s *, int,
      int, int *, unsigned char *)::warnCount = *(_DWORD *)frontEndDataOut;
  ri(2, "TEMP_SKIN_BUF_SIZE exceeded - not skinning surface\n");
  return 0;
}

void __cdecl R_SkinXSurfaceSkinned(struct GfxModelSkinnedSurface *,
                                   struct DObjSkelMat_s const *)
{
  UNIMPLEMENTED();
}

enum surfaceType_t *__cdecl R_SkinXSurface(struct GfxEntity *, int,
                                           struct DObjSkelMat_s *,
                                           enum surfaceType_t *)
{
  UNIMPLEMENTED();
}

void *__cdecl Hunk_AllocXModelPrecacheColl(int)
{
  return Hunk_AllocInternal(__len);
}

void *__cdecl Hunk_AllocXModelPrecache(int)
{
  return Hunk_AllocInternal(__len);
}

int __cdecl R_GetSurfaceData(struct GfxEntity *, struct DObj_s const *,
                             struct DSurface_s *, int *const, char *const)
{
  UNIMPLEMENTED();
}

void __cdecl R_DObjCalcPose(struct GfxSceneEntity const *,
                            struct DObj_s const *, int *const)
{
  UNIMPLEMENTED();
}

void __cdecl R_XModelDebugAxes(struct GfxSceneEntity *, struct GfxEntity *,
                               struct DObj_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl R_XModelDebugBoxes(struct GfxSceneEntity *, struct GfxEntity *,
                                struct DObj_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl R_XModelDebug(struct GfxSceneEntity *, struct GfxEntity *,
                           struct DObj_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl R_SkinXModel(struct GfxSceneEntity *, struct GfxEntity *, int)
{
  int result;           // eax
  const XModel *obj;    // edi
  float v5;             // xmm0_4
  int v6;               // edx
  int v7;               // ebx
  unsigned __int8 *j;   // edx
  unsigned __int8 *v9;  // ebx
  size_t v10;           // ebx
  int v11;              // edx
  char *v12;            // eax
  _DWORD *BasePose;     // eax
  _DWORD *v14;          // ecx
  int i;                // eax
  DObj_s *v16;          // ebx
  int v17;              // eax
  int v18;              // [esp+8h] [ebp-F10h]
  float v19;            // [esp+3Ch] [ebp-EDCh]
  int Surfaces;         // [esp+4Ch] [ebp-ECCh]
  int v21;              // [esp+50h] [ebp-EC8h]
  int v22;              // [esp+54h] [ebp-EC4h]
  unsigned __int8 *v23; // [esp+58h] [ebp-EC0h]
  float v24;            // [esp+5Ch] [ebp-EBCh]
  _BYTE __src[3584];    // [esp+68h] [ebp-EB0h] BYREF
  _DWORD v26[7];        // [esp+E68h] [ebp-B0h] BYREF
  char v27;             // [esp+E84h] [ebp-94h]
  char v28;             // [esp+E85h] [ebp-93h]
  _BYTE v29[66];        // [esp+E86h] [ebp-92h]
  _DWORD v30[11];       // [esp+EC8h] [ebp-50h] BYREF
  XSurface_s **v31;     // [esp+EF4h] [ebp-24h] BYREF
  int *v32;             // [esp+EF8h] [ebp-20h] BYREF
  int v33[7];           // [esp+EFCh] [ebp-1Ch] BYREF

  result = a1->cullState;
    if (result <= 3) {
        if (InterlockedCompareExchange((int)&a1->cullState, 3, 2) == 2) {
          obj = (const XModel *)a1->u.obj;
            if (XModelBad(obj)) {
              result = developer;
                if (*(_DWORD *)(developer + 8)) {
                  DObjSetModel((DObj_s *)dword_1183A10, obj);
                  R_XModelDebugBoxes((int)a1, (float *)&a2->reType,
                                     (DObj_s *)dword_1183A10);
                  result = R_XModelDebugAxes((int)a1, (float *)&a2->reType,
                                             (DObj_s *)dword_1183A10);
                }
            }
            else {
              v21 = XModelNumBones(obj);
              v24 = *(float *)&a2->scale;
              v19 = Vec3Distance(a2->origin, (float *)algn_1183A7C);
              v5 = (float)(v19 * *(float *)&algn_1183A7C[12]) +
                   *(float *)&algn_1183A7C[16];
              if (v24 != 0.0)
                v5 = v5 / v24;
              result = XModelGetLodForDist(obj, v5);
              v22 = result;
                if (result >= 0) {
                  Surfaces = XModelGetSurfaces(obj, &v31, result, &v32);
                  v6 = InterlockedExchangeAdd((int)&dword_116F55C, Surfaces);
                    if ((unsigned int)(v6 + Surfaces) <= 0x1000) {
                      a1->materials = (int32_t)(&scene + v6 + 26968);
                      v33[0] = 0;
                        if (Surfaces <= 0) {
                          v9 = __src;
                        LABEL_21:
                          v10 = v9 - __src;
                          v11 = InterlockedExchangeAdd(
                              (int)frontEndDataOut + 524296, v10);
                            if (v10 + v11 <= (unsigned int)&loc_20000) {
                              v12 = (char *)frontEndDataOut + v11 + 524300;
                              a1->surfs = (int32_t)v12;
                              memcpy(v12, __src, v10);
                              a1->surfCount = Surfaces;
                                if (*(_DWORD *)(r_xdebug + 8)) {
                                  DObjSetModel((DObj_s *)dword_1183A10, obj);
                                  v16 = (DObj_s *)dword_1183A10;
                                  v17 = r_xdebug;
                                    if ((*(_BYTE *)(r_xdebug + 8) & 1) != 0) {
                                      R_XModelDebugBoxes(
                                          (int)a1, (float *)&a2->reType,
                                          (DObj_s *)dword_1183A10);
                                      v17 = r_xdebug;
                                    }
                                  if ((*(_BYTE *)(v17 + 8) & 2) != 0)
                                    R_XModelDebugAxes(
                                        (int)a1, (float *)&a2->reType, v16);
                                }
                              result = v33[0];
                                if (v33[0]) {
                                  BasePose = (_DWORD *)XModelGetBasePose(obj);
                                  v14 = BasePose;
                                    if (v21 == 1) {
                                      v30[0] = a1->surfs;
                                      v30[1] = Surfaces;
                                      v30[2] = a2;
                                      v30[3] = *BasePose;
                                      v30[4] = BasePose[1];
                                      v30[5] = BasePose[2];
                                      v30[6] = BasePose[3];
                                      v30[7] = BasePose[4];
                                      v30[8] = BasePose[5];
                                      v30[9] = BasePose[6];
                                      v30[10] = BasePose[7];
                                      result = R_AddFrontendCmd(2, v30, v18);
                                    }
                                    else {
                                      v26[3] = *v32;
                                      v26[4] = v32[1];
                                      v26[5] = v32[2];
                                      v26[6] = v32[3];
                                        if (Surfaces > 0) {
                                          for (i = 0; i != Surfaces; ++i)
                                            v29[i] = 0;
                                        }
                                      v26[0] = a1->surfs;
                                      v27 = Surfaces;
                                      v26[1] = a2;
                                      v26[2] = v14;
                                      v28 = v21;
                                      result = R_AddFrontendCmd(
                                          (Surfaces > 10) + 6, v26, v18);
                                    }
                                }
                            }
                            else {
                              *((_DWORD *)frontEndDataOut + 131074) =
                                  &loc_20000;
                              result = *(_DWORD *)frontEndDataOut;
                                if (*(_DWORD *)frontEndDataOut !=
                                    R_SkinXModel(GfxSceneEntity *, GfxEntity *,
                                                 int)::warnCount) {
                                  R_SkinXModel(GfxSceneEntity *, GfxEntity *,
                                               int)::warnCount =
                                      *(_DWORD *)frontEndDataOut;
                                  result =
                                      ri(2, "MAX_SCENE_SURFS_SIZE exceeded - "
                                            "not drawing surface\n");
                                }
                            }
                        }
                        else {
                          v7 = 0;
                          v23 = __src;
                            for (j = __src;; j = v23) {
                              result = R_PreSkinStaticSurface(
                                  a1, a2, a3, obj, v31[v7], v7, v22, v33, j);
                              if (!result)
                                break;
                              v23 += result;
                                if (Surfaces == ++v7) {
                                  v9 = v23;
                                  goto LABEL_21;
                                }
                            }
                        }
                    }
                    else {
                      dword_116F55C = 4096;
                      result = *(_DWORD *)frontEndDataOut;
                        if (*(_DWORD *)frontEndDataOut !=
                            R_SkinXModel(GfxSceneEntity *, GfxEntity *,
                                         int)::warnCount) {
                          R_SkinXModel(GfxSceneEntity *, GfxEntity *,
                                       int)::warnCount =
                              *(_DWORD *)frontEndDataOut;
                          result = ri(2, "MAX_SCENE_MATERIALS exceeded - not "
                                         "drawing surface\n");
                        }
                    }
                }
            }
          a1->cullState = 4;
        }
        else {
          do
            result = a1->cullState;
          while (result <= 3);
        }
    }
  return result;
}

R_UnlockSkinnedCache()
{
  UNIMPLEMENTED();
}

R_OptimizeAllModels()
{
  UNIMPLEMENTED();
}

R_ReleaseAllModels()
{
  UNIMPLEMENTED();
}

Model_Alloc(int size)
{
  UNIMPLEMENTED();
}

R_LockSkinnedCache(GfxLockType lockType)
{
  UNIMPLEMENTED();
}

R_ShutdownModels()
{
  UNIMPLEMENTED();
}

R_FinishLoadingModels()
{
  UNIMPLEMENTED();
}
