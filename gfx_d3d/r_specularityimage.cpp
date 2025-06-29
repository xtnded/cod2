float __cdecl log(float)
{
  UNIMPLEMENTED();
}

void __cdecl Image_BuildSpecularityMap(float shift, unsigned char *const pic)
{
  int v2;              // edi
  double v3;           // xmm0_8
  double v4;           // xmm0_8
  unsigned __int8 *v5; // ebx
  int j;               // esi
  float v7;            // xmm0_4
  int result;          // eax
  long double v9;      // [esp+0h] [ebp-68h]
  long double v10;     // [esp+0h] [ebp-68h]
  long double v11;     // [esp+0h] [ebp-68h]
  long double v12;     // [esp+0h] [ebp-68h]
  int v13;             // [esp+10h] [ebp-58h]
  float v14;           // [esp+3Ch] [ebp-2Ch]
  double v15;          // [esp+48h] [ebp-20h]
  double i;            // [esp+48h] [ebp-20h]

  v2 = 0;
LABEL_2:
  v3 = (float)((float)((float)v2 / 30.0) + a1);
    if (v3 < 0.0) {
      v4 = -0.0;
    }
    else if (v3 <= 1.0) {
      v4 = v3 * -175.0;
    }
    else {
      v4 = -175.0;
    }
  *(_QWORD *)&v9 = 0x3FB99999A0000000LL;
  v15 = log(v9);
  *(double *)&v10 = (v4 + 180.0) * 0.004363323129985824;
  *(double *)&v11 = cos(v10);
    for (i = v15 / (double)log(v11);; i = 30.0) {
      v5 = &a2[v2];
        for (j = 0; j != 256; ++j) {
          *((double *)&v12 + 1) = i;
          *(double *)&v12 = (float)((float)j * 0.0039215689);
          v7 = (double)pow(v12, v13) * 255.0;
          v14 = floorf(v7 + 0.5);
          result = (int)v14;
          *v5 = (int)v14;
          v5 += 32;
        }
      if (++v2 > 31)
        break;
      if (v2 != 31)
        goto LABEL_2;
    }
  return result;
}

int marker_r_specularityimage;
