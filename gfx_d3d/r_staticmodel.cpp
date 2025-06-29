int __cdecl R_GetMaxStaticModelSurfCount(struct XModel const *)
{
  UNIMPLEMENTED();
}

void __cdecl R_InitStaticModelDynamicData(int smodelIndex)
{
  int NumLods;      // edi
  int v2;           // eax
  size_t v3;        // ebx
  void *v4;         // eax
  int v6;           // ebx
  int v7;           // esi
  int Surfaces;     // eax
  int v9;           // [esp+18h] [ebp-30h]
  XModel *v10;      // [esp+1Ch] [ebp-2Ch]
  int *v11;         // [esp+28h] [ebp-20h] BYREF
  XSurface_s **v12; // [esp+2Ch] [ebp-1Ch] BYREF

  v9 = *(_DWORD *)&algn_1183A7C[24] + 8 * a1;
  v10 = *(XModel **)(96 * a1 + *(_DWORD *)(dword_1184B9C + 248) + 16);
  NumLods = XModelGetNumLods(v10);
    if (NumLods > 0) {
      v6 = 0;
      v7 = 0;
        do {
          Surfaces = XModelGetSurfaces(v10, &v12, v6, &v11);
          if (Surfaces > v7)
            v7 = Surfaces;
          ++v6;
        }
      while (NumLods != v6);
      v2 = v7;
    }
    else {
      v2 = 0;
    }
  v3 = 16 * v2;
  v4 = Hunk_AllocAlignInternal(16 * v2, 4);
  *(_DWORD *)(v9 + 4) = v4;
  return memset(v4, 0, v3);
}

int marker_r_staticmodel;
