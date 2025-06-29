int __cdecl Image_GetCardMemoryAmount(int imageFlags, enum _D3DFORMAT format,
                                      int width, int height, int depth) {
  int v5; // ecx
  int v6; // ebx
  int v7; // esi
  int v9; // [esp+0h] [ebp-10h]

  v5 = a3;
  v6 = a4;
  v7 = a5;
  if (a2 == 71)
    goto LABEL_16;
  if (a2 <= 71) {
    if (a2 == 23)
      goto LABEL_54;
    if (a2 <= 23) {
      if (a2 >= 21)
        goto LABEL_16;
    } else {
      switch (a2) {
      case 50:
        goto LABEL_14;
      case 51:
        goto LABEL_54;
      case 28:
      LABEL_14:
        v9 = a5 * a4 * a3;
        goto LABEL_17;
      }
    }
  LABEL_53:
    v9 = 0;
    goto LABEL_17;
  }
  if (a2 == 114) {
  LABEL_16:
    v9 = 4 * a5 * a4 * a3;
    goto LABEL_17;
  }
  if (a2 <= 114) {
    if (a2 != 75) {
      if (a2 != 80)
        goto LABEL_53;
    LABEL_54:
      v9 = 2 * a5 * a4 * a3;
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  if (a2 != 861165636 && a2 != 894720068) {
    if (a2 == 827611204) {
      v9 = 8 * a5 * ((a4 + 3) >> 2) * ((a3 + 3) >> 2);
      goto LABEL_17;
    }
    goto LABEL_53;
  }
  v9 = 16 * a5 * ((a4 + 3) >> 2) * ((a3 + 3) >> 2);
LABEL_17:
  if ((a1 & 2) == 0) {
    if (a3 <= 1)
      goto LABEL_31;
    while (1) {
      v5 >>= 1;
      if (1 - v5 >= 0)
        v5 = 1;
      v6 >>= 1;
      if (1 - v6 >= 0)
        v6 = 1;
      v7 >>= 1;
      if (1 - v7 >= 0)
        v7 = 1;
      if (a2 == 71)
        break;
      if (a2 > 71) {
        if (a2 == 114)
          break;
        if (a2 > 114) {
          if (a2 == 861165636 || a2 == 894720068) {
            v9 += 16 * ((v6 + 3) >> 2) * ((v5 + 3) >> 2) * v7;
          } else if (a2 == 827611204) {
            v9 += 8 * v7 * ((v6 + 3) >> 2) * ((v5 + 3) >> 2);
          }
          goto LABEL_30;
        }
        if (a2 == 75)
          break;
        if (a2 == 80)
          goto LABEL_40;
      } else {
        if (a2 == 23)
          goto LABEL_40;
        if (a2 > 23) {
          switch (a2) {
          case 50:
            goto LABEL_48;
          case 51:
          LABEL_40:
            v9 += 2 * v7 * v6 * v5;
            break;
          case 28:
          LABEL_48:
            v9 += v7 * v6 * v5;
            break;
          }
        } else if (a2 >= 21) {
          break;
        }
      }
    LABEL_30:
      if (v5 <= 1) {
      LABEL_31:
        if (v6 <= 1 && v7 <= 1)
          goto LABEL_33;
      }
    }
    v9 += 4 * v7 * v6 * v5;
    goto LABEL_30;
  }
LABEL_33:
  if ((a1 & 4) != 0)
    return 6 * v9;
  else
    return v9;
}

enum _D3DCUBEMAP_FACES __cdecl Image_CubemapFace(int) { return a1; }

void __cdecl Image_GetPicmip(struct GfxImage const *image,
                             struct Picmip *picmip) {
  const GfxImage *result; // eax

  result = a1;
  if (!a1->noPicmip)
    return (const GfxImage *)Image_PicmipForSemantic(a1->semantic, a2);
  a2->platform = 0;
  return result;
}

void __cdecl Image_Setup(struct GfxImage *image, int width, int height,
                         int depth, int imageFlags, unsigned long usage,
                         enum _D3DFORMAT imageFormat) {
  int v7;               // edi
  int v8;               // ebx
  int v9;               // ecx
  unsigned __int8 v10;  // dl
  unsigned __int8 *v11; // eax
  int v12;              // ecx
  char v13;             // bl
  int v14;              // ecx
  int v15;              // edi
  int v16;              // eax

  *(_BYTE *)(a1 + 11) = (a5 & 3) != 0;
  if (*(_BYTE *)(a1 + 11))
    *(_WORD *)(a1 + 8) = 0;
  else
    Image_PicmipForSemantic(*(_BYTE *)(a1 + 10), (Picmip *)(a1 + 8));
  if (a7 == 827611204 || a7 == 861165636 || a7 == 894720068)
    v7 = 4;
  else
    v7 = 1;
  v8 = a2;
  if (a3 - a2 < 0)
    v8 = a3;
  v9 = 3;
  do {
    v10 = v9;
    if (v7 <= v8 >> v9)
      break;
    v10 = --v9;
  } while (v9);
  v11 = (unsigned __int8 *)(a1 + 8);
  v12 = 2;
  do {
    if (*v11 > v10)
      *v11 = v10;
    ++v11;
    --v12;
  } while (v12);
  v13 = *(_BYTE *)(a1 + 8);
  LOWORD(v14) = 1;
  if (1 - (a2 >> v13) < 0)
    v14 = a2 >> *(_BYTE *)(a1 + 8);
  *(_WORD *)(a1 + 24) = v14;
  LOWORD(v15) = 1;
  if (1 - (a3 >> v13) < 0)
    v15 = a3 >> v13;
  *(_WORD *)(a1 + 26) = v15;
  v16 = a4 >> v13;
  if (1 - (a4 >> v13) >= 0)
    LOWORD(v16) = 1;
  *(_WORD *)(a1 + 28) = v16;
  if ((a5 & 4) != 0) {
    Image_CreateCubeTexture(a1, v14, (a5 >> 1) & 1, a6, a7, 1);
  } else if ((a5 & 8) != 0) {
    Image_Create3DTexture(a1, v14, v15, v16, (a5 >> 1) & 1, a6, a7, 1);
  } else {
    Image_Create2DTexture(a1, v14, v15, (a5 >> 1) & 1, a6, a7, 1);
  }
  return Image_TrackTexture(a1, a5, a7, a2, a3, a4);
}

void __cdecl Image_SetupAndLoad(struct GfxImage *, int, int, int, int,
                                unsigned long, enum _D3DFORMAT) {
  UNIMPLEMENTED();
}

void __cdecl Image_UploadData(struct GfxImage *image, enum _D3DFORMAT format,
                              int face, int mipLevel,
                              unsigned char const *src) {
  int v5;      // edx
  size_t v6;   // esi
  int v7;      // edi
  int *result; // eax
  int v9;      // edx
  int v10;     // eax
  int v11;     // edx
  char *v12;   // esi
  char *v13;   // ebx
  int k;       // edi
  int i;       // ebx
  int j;       // ebx
  int v17;     // [esp+24h] [ebp-74h]
  int v18;     // [esp+28h] [ebp-70h]
  int v19;     // [esp+2Ch] [ebp-6Ch]
  char *__dst; // [esp+30h] [ebp-68h]
  int v21;     // [esp+34h] [ebp-64h]
  int v22;     // [esp+38h] [ebp-60h]
  int v23;     // [esp+3Ch] [ebp-5Ch]
  int v24;     // [esp+40h] [ebp-58h]
  char *v25;   // [esp+44h] [ebp-54h]
  int v26;     // [esp+48h] [ebp-50h]
  int v27;     // [esp+4Ch] [ebp-4Ch]
  char *v28;   // [esp+50h] [ebp-48h]
  int v29;     // [esp+54h] [ebp-44h]
  int v30;     // [esp+58h] [ebp-40h]
  int __n;     // [esp+5Ch] [ebp-3Ch]
  int v32;     // [esp+74h] [ebp-24h] BYREF
  char *v33;   // [esp+78h] [ebp-20h]
  char *v34;   // [esp+7Ch] [ebp-1Ch]

  v5 = *a1;
  if (*a1 != 4) {
    if (v5 == 5) {
      if (a4) {
        result = &dx;
        if (!byte_118061B)
          return result;
      }
    }
    v6 = (int)*((unsigned __int16 *)a1 + 12) >> a4;
    if ((int)(1 - v6) >= 0)
      v6 = 1;
    v7 = (int)*((unsigned __int16 *)a1 + 13) >> a4;
    if (1 - v7 >= 0)
      v7 = 1;
    if (v5 != 3) {
      do
        (*(void(__cdecl **)(int, int, int, int *, _DWORD, _DWORD))(
            *(_DWORD *)a1[1] + 76))(a1[1], a3, a4, &v32, 0, 0);
      while (alwaysfails);
      v28 = v33;
      v29 = v32;
      if (a2 == 50)
        goto LABEL_15;
      if (a2 <= 50) {
        if (a2 != 23) {
          if (a2 > 23) {
            if (a2 == 28)
              goto LABEL_15;
          } else if (a2 >= 21) {
            v6 *= 4;
          LABEL_15:
            v30 = 1;
            goto LABEL_16;
          }
          do {
          LABEL_18:
            (*(void(__cdecl **)(int, int, int))(*(_DWORD *)a1[1] + 80))(a1[1],
                                                                        a3, a4);
            result = (int *)alwaysfails;
          } while (alwaysfails);
          return result;
        }
      LABEL_40:
        v6 *= 2;
        goto LABEL_15;
      }
      if (a2 == 827611204) {
        v6 = 8 * ((int)(v6 + 3) >> 2);
        v30 = 4;
      } else {
        if (a2 <= 827611204) {
          if (a2 != 51)
            goto LABEL_18;
          goto LABEL_40;
        }
        if (a2 != 861165636 && a2 != 894720068)
          goto LABEL_18;
        v6 = 16 * ((int)(v6 + 3) >> 2);
        v30 = 4;
      }
    LABEL_16:
      if (v6 == v32) {
        memcpy(v33, __src, ((v7 - 1) / v30 + 1) * v6);
      } else if (v7 > 0) {
        for (i = 0; i < v7; i += v30) {
          memcpy(v28, __src, v6);
          v28 += v29;
          __src += v6;
        }
      }
      goto LABEL_18;
    }
    do
      (*(void(__cdecl **)(int, int, int *, _DWORD, _DWORD))(
          *(_DWORD *)a1[1] + 76))(a1[1], a4, &v32, 0, 0);
    while (alwaysfails);
    v25 = v33;
    v26 = v32;
    if (a2 == 50)
      goto LABEL_87;
    if (a2 <= 50) {
      if (a2 != 23) {
        if (a2 > 23) {
          if (a2 == 28)
            goto LABEL_87;
        } else if (a2 >= 21) {
          v6 *= 4;
        LABEL_87:
          v27 = 1;
          goto LABEL_88;
        }
        do {
        LABEL_90:
          (*(void(__cdecl **)(int, int))(*(_DWORD *)a1[1] + 80))(a1[1], a4);
          result = &alwaysfails;
          if (!alwaysfails)
            break;
          (*(void(__cdecl **)(int, int))(*(_DWORD *)a1[1] + 80))(a1[1], a4);
          result = &alwaysfails;
        } while (alwaysfails);
        return result;
      }
    LABEL_109:
      v6 *= 2;
      goto LABEL_87;
    }
    if (a2 == 827611204) {
      v6 = 8 * ((int)(v6 + 3) >> 2);
      v27 = 4;
    } else {
      if (a2 <= 827611204) {
        if (a2 != 51)
          goto LABEL_90;
        goto LABEL_109;
      }
      if (a2 != 861165636 && a2 != 894720068)
        goto LABEL_90;
      v6 = 16 * ((int)(v6 + 3) >> 2);
      v27 = 4;
    }
  LABEL_88:
    if (v6 == v32) {
      memcpy(v33, __src, ((v7 - 1) / v27 + 1) * v6);
    } else if (v7 > 0) {
      for (j = 0; j < v7; j += v27) {
        memcpy(v25, __src, v6);
        v25 += v26;
        __src += v6;
      }
    }
    goto LABEL_90;
  }
  v9 = (int)*((unsigned __int16 *)a1 + 12) >> a4;
  v10 = 1;
  if (1 - v9 >= 0)
    v9 = 1;
  v24 = v9;
  v11 = (int)*((unsigned __int16 *)a1 + 13) >> a4;
  if (1 - v11 >= 0)
    v11 = 1;
  v22 = v11;
  if (1 - ((int)*((unsigned __int16 *)a1 + 14) >> a4) < 0)
    v10 = (int)*((unsigned __int16 *)a1 + 14) >> a4;
  v19 = v10;
  if (a2 == 71)
    goto LABEL_48;
  if (a2 <= 71) {
    if (a2 == 23)
      goto LABEL_113;
    if (a2 <= 23) {
      if (a2 == 21)
        goto LABEL_48;
      if (a2 == 22) {
        v18 = 3 * v11 * v24;
        goto LABEL_49;
      }
    } else {
      switch (a2) {
      case 50:
        goto LABEL_46;
      case 51:
        goto LABEL_113;
      case 28:
      LABEL_46:
        v18 = v11 * v24;
        goto LABEL_49;
      }
    }
  LABEL_102:
    v18 = 0;
    goto LABEL_49;
  }
  if (a2 == 114) {
  LABEL_48:
    v18 = 4 * v11 * v24;
    goto LABEL_49;
  }
  if (a2 <= 114) {
    if (a2 != 75) {
      if (a2 != 80)
        goto LABEL_102;
    LABEL_113:
      v18 = 2 * v11 * v24;
      goto LABEL_49;
    }
    goto LABEL_48;
  }
  if (a2 != 861165636 && a2 != 894720068) {
    if (a2 == 827611204) {
      v18 = 8 * ((v11 + 3) >> 2) * ((v24 + 3) >> 2);
      goto LABEL_49;
    }
    goto LABEL_102;
  }
  v18 = 16 * ((v24 + 3) >> 2) * ((v11 + 3) >> 2);
  do
  LABEL_49:
    (*(void(__cdecl **)(int, int, int *, _DWORD, _DWORD))(
        *(_DWORD *)a1[1] + 76))(a1[1], a4, &v32, 0, 0);
  while (alwaysfails);
  __dst = v34;
  if (v19 > 0) {
    v17 = 0;
    while (1) {
      while (1) {
        v21 = v32;
        if (a2 != 50)
          break;
      LABEL_71:
        __n = v24;
        v23 = 1;
        if (v24 == v32) {
        LABEL_72:
          memcpy(__dst, __src, __n * ((v22 - 1) / v23 + 1));
          goto LABEL_55;
        }
      LABEL_63:
        if (v22 <= 0)
          goto LABEL_55;
        v12 = __src;
        v13 = __dst;
        for (k = 0; k < v22; k += v23) {
          memcpy(v13, v12, __n);
          v13 += v21;
          v12 += __n;
        }
        __src += v18;
        __dst = &__dst[(_DWORD)v33];
        if (v19 == ++v17)
          goto LABEL_67;
      }
      if (a2 > 50) {
        if (a2 == 827611204) {
          __n = 8 * ((v24 + 3) >> 2);
          v23 = 4;
          goto LABEL_62;
        }
        if (a2 > 827611204) {
          if (a2 != 861165636 && a2 != 894720068)
            goto LABEL_55;
          __n = 16 * ((v24 + 3) >> 2);
          v23 = 4;
        LABEL_62:
          if (__n == v32)
            goto LABEL_72;
          goto LABEL_63;
        }
        if (a2 == 51) {
        LABEL_61:
          __n = 2 * v24;
          v23 = 1;
          goto LABEL_62;
        }
        goto LABEL_55;
      }
      if (a2 == 23)
        goto LABEL_61;
      if (a2 > 23) {
        if (a2 != 28)
          goto LABEL_55;
        goto LABEL_71;
      }
      if (a2 >= 21) {
        __n = 4 * v24;
        v23 = 1;
        goto LABEL_62;
      }
    LABEL_55:
      __src += v18;
      __dst = &__dst[(_DWORD)v33];
      if (v19 == ++v17)
        goto LABEL_67;
    }
  }
  do {
  LABEL_67:
    (*(void(__cdecl **)(int, int))(*(_DWORD *)a1[1] + 80))(a1[1], a4);
    result = (int *)alwaysfails;
    if (!alwaysfails)
      break;
    (*(void(__cdecl **)(int, int))(*(_DWORD *)a1[1] + 80))(a1[1], a4);
    result = (int *)alwaysfails;
  } while (alwaysfails);
  return result;
}

int marker_r_image_load_common;
int __cdecl Image_GetMinSizeForFormat(enum _D3DFORMAT) { UNIMPLEMENTED(); }

void *__cdecl Image_AllocTextureObject(int) { UNIMPLEMENTED(); }

unsigned char *__cdecl Image_MipLevelBaseAddress(struct GfxImage *,
                                                 enum _D3DFORMAT, int, int) {
  UNIMPLEMENTED();
}

void __cdecl Image_CapPicmipForFormat(enum _D3DFORMAT, int, int,
                                      struct Picmip *) {
  UNIMPLEMENTED();
}

void __cdecl Image_Alloc2DPixels(struct GfxImage *, int, unsigned long,
                                 enum _D3DFORMAT, unsigned long) {
  UNIMPLEMENTED();
}

void __cdecl Image_Alloc3DPixels(struct GfxImage *, int, unsigned long,
                                 enum _D3DFORMAT, unsigned long) {
  UNIMPLEMENTED();
}

void __cdecl Image_AllocCubePixels(struct GfxImage *, int, unsigned long,
                                   enum _D3DFORMAT, unsigned long) {
  UNIMPLEMENTED();
}

void __cdecl Image_Upload3D_CopyData(struct GfxImage *, enum _D3DFORMAT, int,
                                     unsigned char const *) {
  UNIMPLEMENTED();
}

void __cdecl Image_Upload2D_CopyData(struct GfxImage *, enum _D3DFORMAT, int,
                                     int, unsigned char const *) {
  UNIMPLEMENTED();
}
