int __cdecl CM_TraceStaticModelComplete(struct cStaticModel_s *sm,
                                        float const *const start,
                                        float const *const end, int contentmask)
{
  const DObjAnimMat_s *BasePose; // eax
  trace_t v6;                    // [esp+28h] [ebp-60h] BYREF
  float v7;                      // [esp+4Ch] [ebp-3Ch] BYREF
  float v8;                      // [esp+50h] [ebp-38h]
  float v9;                      // [esp+54h] [ebp-34h]
  float v10[3];                  // [esp+58h] [ebp-30h] BYREF
  float v11[9];                  // [esp+64h] [ebp-24h] BYREF

  v7 = *a2 - a1->origin[0];
  v8 = a2[1] - a1->origin[1];
  v9 = a2[2] - a1->origin[2];
  MatrixTransformVector(&v7, a1->invAxis[0], v10);
  v7 = *a3 - a1->origin[0];
  v8 = a3[1] - a1->origin[1];
  v9 = a3[2] - a1->origin[2];
  MatrixTransformVector(&v7, a1->invAxis[0], v11);
  v6.fraction = 1.0;
  BasePose =
      (const DObjAnimMat_s *)XModelGetBasePose(*(const XModel **)a1->xmodel);
  return (unsigned int)XModelTraceLine(*(const XModel **)a1->xmodel, &v6,
                                       BasePose, v10, v11, a4) >>
         31;
}

void __cdecl CM_TraceStaticModel(struct cStaticModel_s *sm,
                                 struct trace_t *results,
                                 float const *const start,
                                 float const *const end, int contentmask)
{
  const DObjAnimMat_s *BasePose; // eax
  int result;                    // eax
  __int64 v7;                    // [esp+0h] [ebp-78h]
  float v8[2];                   // [esp+30h] [ebp-48h] BYREF
  float v9;                      // [esp+38h] [ebp-40h]
  float v10;                     // [esp+3Ch] [ebp-3Ch] BYREF
  float v11;                     // [esp+40h] [ebp-38h]
  float v12;                     // [esp+44h] [ebp-34h]
  float v13[3];                  // [esp+48h] [ebp-30h] BYREF
  float v14[9];                  // [esp+54h] [ebp-24h] BYREF

  v10 = *a3 - a1->origin[0];
  v11 = a3[1] - a1->origin[1];
  v12 = a3[2] - a1->origin[2];
  MatrixTransformVector(&v10, a1->invAxis[0], v13);
  v10 = *a4 - a1->origin[0];
  v11 = a4[1] - a1->origin[1];
  v12 = a4[2] - a1->origin[2];
  MatrixTransformVector(&v10, a1->invAxis[0], v14);
  BasePose =
      (const DObjAnimMat_s *)XModelGetBasePose(*(const XModel **)a1->xmodel);
  result =
      XModelTraceLine(*(const XModel **)a1->xmodel, a2, BasePose, v13, v14, a5);
    if (result >= 0) {
      a2->entityNum = 1022;
      HIDWORD(v7) = a1->invAxis;
      LODWORD(v7) = a2->normal;
      MatrixTransposeTransformVector(v7, v8);
      Vec3Normalize(v8);
      a2->normal[0] = v8[0];
      a2->normal[1] = v8[1];
      result = LODWORD(v9);
      a2->normal[2] = v9;
    }
  return result;
}

int marker_cm_staticmodel;

CM_Hunk_AllocXModel(int size)
{
  UNIMPLEMENTED();
}

CM_XModelPrecache(char const *name)
{
  UNIMPLEMENTED();
}
