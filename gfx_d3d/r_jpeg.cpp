unsigned char __cdecl empty_output_buffer(struct jpeg_compress_struct *)
{
  return 1;
}

void __cdecl R_LoadJpg(char const *filepath, unsigned char **file,
                       unsigned char **pic, int *width, int *height,
                       enum _D3DFORMAT *imageFormat)
{
  int result;              // eax
  int v7;                  // ebx
  unsigned int v8;         // edx
  int v9;                  // ebx
  _BYTE *v10;              // ecx
  unsigned int v11;        // edx
  int v12;                 // [esp+1Ch] [ebp-26Ch]
  _DWORD __b[25];          // [esp+28h] [ebp-260h] BYREF
  unsigned int v14;        // [esp+8Ch] [ebp-1FCh]
  unsigned int v15;        // [esp+90h] [ebp-1F8h]
  int v16;                 // [esp+98h] [ebp-1F0h]
  unsigned int v17;        // [esp+A8h] [ebp-1E0h]
  int(__cdecl * v18)(int); // [esp+1DCh] [ebp-ACh] BYREF
  int v19;                 // [esp+268h] [ebp-20h] BYREF
  int v20[7];              // [esp+26Ch] [ebp-1Ch] BYREF

  result = unk_11807E8(a1, v20);
  v7 = result;
    if (v20[0]) {
      __b[0] = jpeg_std_error(&v18, (int(__cdecl *)(int))ExitJpeg,
                              (int(__cdecl *)(int))PrintfJpeg);
      __b[6] = Z_MallocJpeg;
      __b[7] = Z_FreeJpeg;
      jpeg_CreateDecompress(__b, 62, 436);
      jpeg_memory_src((int)__b, v20[0], v7);
      jpeg_read_header(__b, 1);
      jpeg_start_decompress((int)__b);
      v8 = v14;
        if (v14 <= dword_1180698 && dword_1180698 >= v15) {
            if (v16 == 3) {
              *a4 = v14;
              *a5 = v15;
              *a6 = 21;
              v9 = (*(int(__cdecl **)(unsigned int)) &
                    algn_11806C8[8])(4 * v15 * v8);
              *a3 = v9;
              v12 = 4 * v14;
                for (*a2 = v20[0]; v15 > v17; v9 += v12) {
                    while (1) {
                      v19 = v9;
                      jpeg_read_scanlines(__b, (int)&v19, 1);
                      if ((int)(v14 - 1) >= 0)
                        break;
                      v9 += v12;
                      if (v15 <= v17)
                        goto LABEL_9;
                    }
                  v10 = (_BYTE *)(v9 + 4 * (v14 - 1) + 3);
                  v11 = v14 - 1;
                    do {
                      *v10 = -1;
                      *(v10 - 1) = *(_BYTE *)(v9 + v16 * v11 + 2);
                      *(v10 - 2) = *(_BYTE *)(v9 + v16 * v11 + 1);
                      *(v10 - 3) = *(_BYTE *)(v9 + v16 * v11--);
                      v10 -= 4;
                    }
                  while (v11 != -1);
                }
            LABEL_9:
              jpeg_finish_decompress((int)__b);
              return jpeg_destroy_decompress((int)__b);
            }
            else {
              ri(2, "WARNING: jpeg image '%s' is not RGB\n", a1);
              jpeg_destroy_decompress((int)__b);
              return unk_11807EC(v20[0]);
            }
        }
        else {
          ri(2, "WARNING: image '%s' is larger than %i on at least one side\n",
             a1, dword_1180698);
          jpeg_destroy_decompress((int)__b);
          return unk_11807EC(v20[0]);
        }
    }
  return result;
}

void __cdecl R_SaveJpg(char const *filename, int quality, int image_width,
                       int image_height, unsigned char *image_buffer)
{
  int v5;                  // edi
  _DWORD *v6;              // eax
  unsigned int i;          // eax
  _DWORD __b[8];           // [esp+14h] [ebp-214h] BYREF
  _DWORD *v10;             // [esp+34h] [ebp-1F4h]
  int v11;                 // [esp+38h] [ebp-1F0h]
  unsigned int v12;        // [esp+3Ch] [ebp-1ECh]
  int v13;                 // [esp+40h] [ebp-1E8h]
  int v14;                 // [esp+44h] [ebp-1E4h]
  unsigned int v15;        // [esp+E8h] [ebp-140h]
  int(__cdecl * v16)(int); // [esp+180h] [ebp-A8h] BYREF
  unsigned __int8 *v17;    // [esp+20Ch] [ebp-1Ch] BYREF

  __b[0] = jpeg_std_error(&v16, (int(__cdecl *)(int))ExitJpeg,
                          (int(__cdecl *)(int))PrintfJpeg);
  __b[6] = Z_MallocJpeg;
  __b[7] = Z_FreeJpeg;
  jpeg_CreateCompress(__b, 62, 364);
  v5 = (*(int(__cdecl **)(unsigned int)) & algn_11806C8[8])(3 * a4 * a3);
    if (v10) {
      v6 = v10;
    }
    else {
      v6 = (_DWORD *)(*(int(__cdecl **)(_DWORD *, _DWORD, int))__b[1])(__b, 0,
                                                                       28);
      v10 = v6;
    }
  v6[2] = init_destination;
  v6[3] = empty_output_buffer;
  v6[4] = term_destination;
  v6[5] = v5;
  v6[6] = 3 * a4 * a3;
  v11 = a3;
  v12 = a4;
  v13 = 3;
  v14 = 2;
  jpeg_set_defaults((int)__b);
  jpeg_set_quality(__b, a2, 1);
  jpeg_start_compress(__b, 1);
    for (i = v15; v15 < v12; i = v15) {
      v17 = &a5[3 * a3 * i];
      jpeg_write_scanlines(__b, (int)&v17, 1u);
    }
  jpeg_finish_compress(__b);
  unk_1180800(a1, v5, hackSize);
  unk_11806F0(v5);
  return jpeg_destroy_compress((int)__b);
}

int marker_r_jpeg;

void __cdecl PrintfJpeg(char *)
{
  return ri(0, "%s\n", a1);
}

void __cdecl ExitJpeg(void)
{
  return dword_11806C4(0, "jpeg internal error");
}

void __cdecl Z_FreeJpeg(void *, unsigned int)
{
  return (*(int(__cdecl **)(void *)) & algn_11806C8[16])(a1);
}

void *__cdecl Z_MallocJpeg(unsigned int)
{
  return (*(int(__cdecl **)(unsigned int)) & algn_11806C8[12])(a1);
}

void __cdecl term_destination(struct jpeg_compress_struct *)
{
  int result; // eax

  result = *(_DWORD *)(a1->dest + 24) - *(_DWORD *)(a1->dest + 4);
  hackSize = result;
  return result;
}

void __cdecl init_destination(struct jpeg_compress_struct *)
{
  _DWORD *result; // eax

  result = (_DWORD *)a1->dest;
  *result = result[5];
  result[1] = result[6];
  return result;
}

void __cdecl jpegDest(struct jpeg_compress_struct *, unsigned char *, int)
{
  UNIMPLEMENTED();
}
