void __cdecl XModelSetTestLods(int lodLevel, float dist)
{
  int result; // eax

  result = a1;
  *(float *)&g_testLods[8 * a1 + 4] = a2;
  g_testLods[8 * a1] = a2 >= 0.0;
  return result;
}

struct DObjAnimMat_s const *__cdecl XModelGetBasePoseBone(
    struct XModel const *model, int skelMatBoneOffset)
{
  return (a2 >> 1) + a1->parts + 68;
}

struct DObjAnimMat_s const *__cdecl XModelGetBasePose(
    struct XModel const *model)
{
  return a1->parts + 68;
}

int __cdecl XModelNumBones(struct XModel const *model)
{
  return *(__int16 *)a1->parts;
}

int __cdecl XModelGetNumLods(struct XModel const *model)
{
  return (__int16)a1->numLods;
}

int __cdecl XModelGetSurfaces(struct XModel const *model,
                              struct XSurface_s ***surfaces, int lod,
                              int **partBits)
{
  *a2 = **(XSurface_s ****)&a1->lodInfo[20 * a3 + 16];
  *a4 = (int *)(*(_DWORD *)&a1->lodInfo[20 * a3 + 16] + 4);
  return *(__int16 *)&a1->lodInfo[20 * a3 + 8];
}

unsigned char __cdecl XModelGetFlags(struct XModel const *)
{
  return (unsigned __int8)a1->flags;
}

char const *__cdecl XModelGetName(struct XModel const *model)
{
  return *(_DWORD *)a1->name;
}

int __cdecl XModelGetLodForDist(struct XModel const *model, float dist)
{
  int numLods;   // ebx
  char *lodInfo; // eax
  int v4;        // ecx
  char *i;       // edx
  float v6;      // xmm0_4

  numLods = (__int16)a1->numLods;
  lodInfo = a1->lodInfo;
  if (numLods <= 0)
    return -1;
  v4 = 0;
    for (i = g_testLods;; i += 8) {
      v6 = *i ? *((float *)i + 1) : *(float *)lodInfo;
      if (v6 == 0.0 || v6 > a2)
        break;
      ++v4;
      lodInfo += 20;
      if (numLods == v4)
        return -1;
    }
  return v4;
}

float __cdecl XModelGetLodOutDist(struct XModel const *model)
{
  int v1; // eax

  v1 = (__int16)a1->numLods - 1;
  if (g_testLods[8 * v1])
    return flt_7EF004[2 * v1];
  else
    return *(float *)&a1->lodInfo[20 * v1];
}

char const *__cdecl XModelGetSurfaceName(struct XModel const *model,
                                         int subMatIndex, int lod)
{
  unsigned __int16 v3; // ax

  v3 = *(_WORD *)(*(_DWORD *)&a1->lodInfo[20 * a3 + 12] + 2 * a2);
  if (v3)
    return (const char *)SL_ConvertToString(v3);
  else
    return "DEFAULT";
}

int marker_xmodel_utils;
