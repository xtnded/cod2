bool __cdecl R_ValidXModelName(char const *name) {
  return strlen(a1) <= 0x3F && !strnicmp(a1, "xmodel", 6u) && a1[6] == 47;
}

void __cdecl R_ConvertColorToBytes(float const *const colorFloat,
                                   unsigned char *const colorBytes) {
  int result; // eax

  if (a1) {
    *a2 = (int)(float)(a1[3] * 255.0);
    a2[1] = (int)(float)(*a1 * 255.0);
    a2[2] = (int)(float)(a1[1] * 255.0);
    result = (int)(float)(255.0 * a1[2]);
    a2[3] = result;
  } else {
    *(_DWORD *)a2 = -1;
  }
  return result;
}

int __cdecl R_HashString(char const *string) {
  char v1; // al
  int v2;  // edx
  int v3;  // ecx

  v1 = *a1;
  if (!*a1)
    return 0;
  v2 = 119;
  v3 = 0;
  do {
    v3 += v2 * (v1 | 0x20);
    v1 = a1[++v2 - 119];
  } while (v1);
  return v3;
}

int __cdecl R_HashAssetName(char const *name) {
  char v1; // al
  int v2;  // edx
  int v3;  // ecx

  v1 = *a1;
  if (!*a1)
    return 0;
  v2 = 119;
  v3 = 0;
  do {
    v3 += v2 * v1;
    v1 = a1[++v2 - 119];
  } while (v1);
  return v3;
}

int __cdecl R_PickMaterial(float const *const org, float const *const dir,
                           char *name, char *surfaceFlags, char *contents,
                           int charLimit) {
  unsigned int v6;  // eax
  char **v7;        // ebx
  char *v8;         // eax
  char *v10;        // [esp+28h] [ebp-60h]
  char *v11;        // [esp+2Ch] [ebp-5Ch]
  unsigned int v12; // [esp+30h] [ebp-58h]
  unsigned int v13; // [esp+34h] [ebp-54h]
  float v14[4];     // [esp+40h] [ebp-48h] BYREF
  int v15;          // [esp+50h] [ebp-38h]
  int v16;          // [esp+54h] [ebp-34h]
  char *__src;      // [esp+58h] [ebp-30h]
  __int16 v18;      // [esp+62h] [ebp-26h]
  float v19[9];     // [esp+64h] [ebp-24h] BYREF

  v19[0] = (float)(*a2 * 262144.0) + *a1;
  v19[1] = (float)(a2[1] * 262144.0) + a1[1];
  v19[2] = (float)(262144.0 * a2[2]) + a1[2];
  unk_1180818(v14, a1, v19, vec3_origin, vec3_origin, 0, 260308983);
  if (v18 || v14[0] == 1.0 || !__src)
    return 0;
  strcpy(__dst, __src);
  *a4 = 0;
  v10 = &a4[__n - 1];
  *v10 = 0;
  *a5 = 0;
  v11 = &a5[__n - 1];
  *v11 = 0;
  v6 = ((v15 & 0x1F00000u) >> 20) - 1;
  if (v6 > 0x15)
    strncpy(a4, "^1default^7", __n);
  else
    strncpy(a4, (&infoParms)[5 * v6], __n);
  if (*v10)
    return 0;
  v12 = strlen(a4);
  if ((v16 & 1) != 0)
    strncpy(a5, "solid", __n);
  else
    strncpy(a5, "^3nonsolid^7", __n);
  if (*v11)
    return 0;
  v13 = strlen(a5);
  if (unk_30F858) {
    v7 = &infoParms;
    do {
      if (((unsigned int)v7[112] & v15) != 0) {
        a4[v12] = 32;
        strncpy(&a4[v12 + 1], v7[110], __n - (v12 + 1));
        if (*v10)
          return 0;
        v12 += strlen(&a4[v12 + 1]) + 1;
        if (((unsigned int)v7[113] & v16) == 0)
          goto LABEL_13;
      } else if (((unsigned int)v7[113] & v16) == 0) {
        goto LABEL_13;
      }
      a5[v13] = 32;
      strncpy(&a5[v13 + 1], v7[110], __n - (v13 + 1));
      if (*v11)
        return 0;
      v13 += strlen(&a5[v13 + 1]) + 1;
    LABEL_13:
      v8 = v7[115];
      v7 += 5;
    } while (v8);
  }
  return 1;
}

int __cdecl R_CullPointAndRadius(float const *const pt, float radius,
                                 struct DpvsPlane const *const clipPlanes,
                                 int clipPlaneCount) {
  float *coeffs;       // eax
  const DpvsPlane *v5; // ecx
  int v6;              // edx
  float v7;            // xmm0_4

  if (a4 > 0) {
    if ((float)-a2 >
        (float)((float)((float)((float)(*a1 * *(float *)a3->coeffs) +
                                (float)(a1[1] * *(float *)&a3->coeffs[4])) +
                        (float)(a1[2] * *(float *)&a3->coeffs[8])) +
                *(float *)&a3->coeffs[12]))
      return 2;
    coeffs = (float *)a3[1].coeffs;
    v5 = a3 + 1;
    v6 = 0;
    while (a4 != ++v6) {
      v7 =
          (float)((float)((float)(*a1 * *coeffs) + (float)(a1[1] * coeffs[1])) +
                  (float)(a1[2] * coeffs[2])) +
          *(float *)&v5->coeffs[12];
      coeffs += 5;
      ++v5;
      if ((float)-a2 > v7)
        return 2;
    }
  }
  return 0;
}

struct mnode_t *__cdecl R_LeafForPoint(float const *const) {
  UNIMPLEMENTED();
}

float __cdecl FresnelTerm(float n0, float n1, float cosIncidentAngle) {
  double v3;       // xmm1_8
  double v4;       // xmm0_8
  long double v5;  // fst7
  float v6;        // xmm1_4
  long double v8;  // [esp+0h] [ebp-78h]
  long double v9;  // [esp+0h] [ebp-78h]
  long double v10; // [esp+0h] [ebp-78h]
  long double v11; // [esp+0h] [ebp-78h]
  long double v12; // [esp+0h] [ebp-78h]
  long double v13; // [esp+0h] [ebp-78h]
  long double v14; // [esp+0h] [ebp-78h]
  double v15;      // [esp+18h] [ebp-60h]
  double v16;      // [esp+38h] [ebp-40h]
  double v17;      // [esp+48h] [ebp-30h]
  double v18;      // [esp+48h] [ebp-30h]
  double v19;      // [esp+58h] [ebp-20h]
  double v20;      // [esp+60h] [ebp-18h]
  double __x;      // [esp+68h] [ebp-10h]

  *(double *)&v8 = fabs(a3);
  __x = acos(v8);
  *(double *)&v9 = __x;
  v3 = (double)sin(v9) * (float)(a1 / a2);
  v4 = 1.0;
  if (v3 <= 1.0)
    v4 = fmax(-1.0, v3);
  *(double *)&v10 = v4;
  v5 = asin(v10);
  v19 = __x + (double)v5;
  v20 = __x - (double)v5;
  *(double *)&v11 = v20;
  v17 = sin(v11);
  *(double *)&v12 = v19;
  v18 = v17 / (double)sin(v12);
  *(double *)&v13 = v20;
  v15 = tan(v13);
  *(double *)&v14 = v19;
  v16 = tan(v14);
  v6 = (v15 / v16 * (v15 / v16) + v18 * v18) * 0.5;
  if (v6 < 0.0)
    return 0.0;
  else
    return fminf(1.0, v6);
}

int marker_r_utils;
