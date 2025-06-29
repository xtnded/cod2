void __cdecl Huff_Init(struct huffman_t *huff) {
  int v2;           // edx
  uint8_t *v3;      // eax
  int v4;           // eax
  _DWORD *v5;       // eax
  int32_t blocNode; // edx
  uint8_t *v7;      // eax
  int32_t lhead;    // eax
  _DWORD *tree;     // eax
  int32_t result;   // eax

  Com_Memset(__b, 0, 0x701Cu);
  Com_Memset(__b->decompressor, 0, 0x701Cu);
  v2 = *(_DWORD *)__b->decompressor;
  v3 = &__b->decompressor[32 * *(_DWORD *)__b->decompressor + 1052];
  *(_DWORD *)&__b->decompressor[1044] = v3;
  *(_DWORD *)&__b->decompressor[16] = v3;
  *(_DWORD *)&__b->decompressor[12] = v3;
  *(_DWORD *)&__b->decompressor[8] = v3;
  *(_DWORD *)__b->decompressor = v2 + 1;
  *((_DWORD *)v3 + 7) = 256;
  *(_DWORD *)(*(_DWORD *)&__b->decompressor[8] + 24) = 0;
  v4 = *(_DWORD *)&__b->decompressor[12];
  *(_DWORD *)(v4 + 16) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  v5 = *(_DWORD **)&__b->decompressor[8];
  v5[1] = 0;
  *v5 = 0;
  v5[2] = 0;
  blocNode = __b->compressor.blocNode;
  v7 = &__b->compressor.nodeList[32 * __b->compressor.blocNode];
  __b->compressor.lhead = (int32_t)v7;
  __b->compressor.tree = (int32_t)v7;
  __b->compressor.blocNode = blocNode + 1;
  *((_DWORD *)v7 + 7) = 256;
  *(_DWORD *)(__b->compressor.tree + 24) = 0;
  lhead = __b->compressor.lhead;
  *(_DWORD *)(lhead + 16) = 0;
  *(_DWORD *)(lhead + 12) = 0;
  tree = (_DWORD *)__b->compressor.tree;
  tree[1] = 0;
  *tree = 0;
  tree[2] = 0;
  result = __b->compressor.tree;
  *(_DWORD *)&__b->compressor.loc[1024] = result;
  return result;
}

int __cdecl Huff_getBit(unsigned char *, int *) { UNIMPLEMENTED(); }

void __cdecl Huff_putBit(int, unsigned char *, int *) { UNIMPLEMENTED(); }

void __cdecl huffman_send(struct nodetype *, struct nodetype *,
                          unsigned char *) {
  int32_t parent;       // eax
  int v4;               // edx
  int v5;               // ecx
  int v6;               // eax
  int v7;               // edx
  int v8;               // edi
  int v9;               // esi
  nodetype *v10;        // ebx
  nodetype *v11;        // eax
  int v12;              // edx
  int v13;              // edx
  int v14;              // edx
  int v15;              // edx
  int v16;              // edx
  int v17;              // edx
  int v18;              // edx
  int v19;              // edx
  nodetype *result;     // eax
  int v21;              // edx
  int v22;              // esi
  char v23;             // bl
  unsigned __int8 *v24; // edx
  int v25;              // esi
  char v26;             // bl
  unsigned __int8 *v27; // edx
  int v28;              // esi
  char v29;             // bl
  unsigned __int8 *v30; // edx
  int v31;              // esi
  char v32;             // bl
  unsigned __int8 *v33; // edx
  int v34;              // esi
  char v35;             // bl
  unsigned __int8 *v36; // edx
  int v37;              // esi
  char v38;             // bl
  unsigned __int8 *v39; // edx
  int v40;              // esi
  char v41;             // bl
  unsigned __int8 *v42; // edx
  int v43;              // esi
  char v44;             // bl
  unsigned __int8 *v45; // edx
  char v46;             // bl
  unsigned __int8 *v47; // edx
  int v48;              // [esp+1Ch] [ebp-3Ch]
  int32_t v49;          // [esp+2Ch] [ebp-2Ch]
  int v50;              // [esp+30h] [ebp-28h]
  int v51;              // [esp+34h] [ebp-24h]
  int v52;              // [esp+38h] [ebp-20h]
  int v53;              // [esp+3Ch] [ebp-1Ch]

  parent = a1->parent;
  v49 = parent;
  if (!parent)
    goto LABEL_43;
  v4 = *(_DWORD *)(parent + 8);
  v50 = v4;
  if (v4) {
    v5 = *(_DWORD *)(v4 + 8);
    v51 = v5;
    if (v5) {
      v6 = *(_DWORD *)(v5 + 8);
      v52 = v6;
      if (v6) {
        v7 = *(_DWORD *)(v6 + 8);
        v53 = v7;
        if (v7) {
          v8 = *(_DWORD *)(v7 + 8);
          if (v8) {
            v9 = *(_DWORD *)(v8 + 8);
            if (v9) {
              v10 = *(nodetype **)(v9 + 8);
              if (v10) {
                v11 = (nodetype *)v10->parent;
                if (v11)
                  huffman_send(v11, v10, a3);
                if (v9 == v10->right) {
                  v48 = bloc;
                  v46 = bloc & 7;
                  v47 = &a3[bloc >> 3];
                  if ((bloc & 7) == 0)
                    *v47 = 0;
                  *v47 |= 1 << v46;
                  bloc = v48 + 1;
                } else {
                  v12 = bloc;
                  if ((bloc & 7) == 0)
                    a3[bloc >> 3] = 0;
                  bloc = v12 + 1;
                }
              }
              if (v8 == *(_DWORD *)(v9 + 4)) {
                v43 = bloc;
                v44 = bloc & 7;
                v45 = &a3[bloc >> 3];
                if ((bloc & 7) == 0)
                  *v45 = 0;
                *v45 |= 1 << v44;
                bloc = v43 + 1;
              } else {
                v13 = bloc;
                if ((bloc & 7) == 0)
                  a3[bloc >> 3] = 0;
                bloc = v13 + 1;
              }
            }
            if (v53 == *(_DWORD *)(v8 + 4)) {
              v40 = bloc;
              v41 = bloc & 7;
              v42 = &a3[bloc >> 3];
              if ((bloc & 7) == 0)
                *v42 = 0;
              *v42 |= 1 << v41;
              bloc = v40 + 1;
            } else {
              v14 = bloc;
              if ((bloc & 7) == 0)
                a3[bloc >> 3] = 0;
              bloc = v14 + 1;
            }
          }
          if (v52 == *(_DWORD *)(v53 + 4)) {
            v37 = bloc;
            v38 = bloc & 7;
            v39 = &a3[bloc >> 3];
            if ((bloc & 7) == 0)
              *v39 = 0;
            *v39 |= 1 << v38;
            bloc = v37 + 1;
          } else {
            v15 = bloc;
            if ((bloc & 7) == 0)
              a3[bloc >> 3] = 0;
            bloc = v15 + 1;
          }
        }
        if (v51 == *(_DWORD *)(v52 + 4)) {
          v34 = bloc;
          v35 = bloc & 7;
          v36 = &a3[bloc >> 3];
          if ((bloc & 7) == 0)
            *v36 = 0;
          *v36 |= 1 << v35;
          bloc = v34 + 1;
        } else {
          v16 = bloc;
          if ((bloc & 7) == 0)
            a3[bloc >> 3] = 0;
          bloc = v16 + 1;
        }
      }
      if (v50 == *(_DWORD *)(v51 + 4)) {
        v22 = bloc;
        v23 = bloc & 7;
        v24 = &a3[bloc >> 3];
        if ((bloc & 7) == 0)
          *v24 = 0;
        *v24 |= 1 << v23;
        bloc = v22 + 1;
        if (v49 != *(_DWORD *)(v50 + 4))
          goto LABEL_36;
        goto LABEL_52;
      }
      v17 = bloc;
      if ((bloc & 7) == 0)
        a3[bloc >> 3] = 0;
      bloc = v17 + 1;
    }
    if (v49 != *(_DWORD *)(v50 + 4)) {
    LABEL_36:
      v18 = bloc;
      if ((bloc & 7) == 0)
        a3[bloc >> 3] = 0;
      bloc = v18 + 1;
      goto LABEL_39;
    }
  LABEL_52:
    v25 = bloc;
    v26 = bloc & 7;
    v27 = &a3[bloc >> 3];
    if ((bloc & 7) == 0)
      *v27 = 0;
    *v27 |= 1 << v26;
    bloc = v25 + 1;
    if (a1 != *(nodetype **)(v49 + 4))
      goto LABEL_40;
    goto LABEL_55;
  }
LABEL_39:
  if (a1 != *(nodetype **)(v49 + 4)) {
  LABEL_40:
    v19 = bloc;
    if ((bloc & 7) == 0)
      a3[bloc >> 3] = 0;
    bloc = v19 + 1;
    goto LABEL_43;
  }
LABEL_55:
  v28 = bloc;
  v29 = bloc & 7;
  v30 = &a3[bloc >> 3];
  if ((bloc & 7) == 0)
    *v30 = 0;
  *v30 |= 1 << v29;
  bloc = v28 + 1;
LABEL_43:
  result = a2;
  if (a2) {
    if (a2 == (nodetype *)a1->right) {
      v31 = bloc;
      v32 = bloc & 7;
      v33 = &a3[bloc >> 3];
      if ((bloc & 7) == 0)
        *v33 = 0;
      *v33 |= 1 << v32;
      result = (nodetype *)(v31 + 1);
      bloc = v31 + 1;
    } else {
      v21 = bloc;
      if ((bloc & 7) == 0)
        a3[bloc >> 3] = 0;
      result = (nodetype *)(v21 + 1);
      bloc = v21 + 1;
    }
  }
  return result;
}

void __cdecl Huff_offsetReceive(struct nodetype *node, int *ch,
                                unsigned char *fin, int *offset) {
  nodetype *v4;   // ebx
  int v5;         // edx
  int32_t symbol; // eax
  int *result;    // eax
  int v8;         // eax

  v4 = a1;
  v5 = *a4;
  bloc = *a4;
  if (a1) {
    symbol = a1->symbol;
    if (symbol == 257) {
      do {
        v8 = (int)a3[v5 >> 3] >> (v5 & 7);
        ++v5;
        if ((v8 & 1) != 0)
          v4 = (nodetype *)v4->right;
        else
          v4 = (nodetype *)v4->left;
        if (!v4) {
          bloc = v5;
          goto LABEL_10;
        }
        symbol = v4->symbol;
      } while (symbol == 257);
      bloc = v5;
    }
    *a2 = symbol;
    result = (int *)bloc;
    *a4 = bloc;
  } else {
  LABEL_10:
    result = a2;
    *a2 = 0;
  }
  return result;
}

int __cdecl Huff_Receive(struct nodetype *, int *, unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl Huff_offsetTransmit(struct huff_t *huff, int ch,
                                 unsigned char *fout, int *offset) {
  nodetype *v4;     // edx
  nodetype *parent; // eax
  int result;       // eax

  bloc = *a4;
  v4 = *(nodetype **)&a1->loc[4 * a2];
  parent = (nodetype *)v4->parent;
  if (parent)
    huffman_send(parent, v4, a3);
  result = bloc;
  *a4 = bloc;
  return result;
}

void __cdecl Huff_transmit(struct huff_t *, int, unsigned char *) {
  UNIMPLEMENTED();
}

void __cdecl Huff_addRef(struct huff_t *huff, unsigned char ch) {
  _DWORD *v2;        // edx
  int v4;            // edx
  uint8_t *v5;       // esi
  uint8_t *v6;       // ebx
  int v7;            // eax
  int v8;            // eax
  int32_t *freelist; // edx
  int v10;           // eax
  int v11;           // eax
  int32_t *v12;      // edx
  int32_t lhead;     // edx
  uint8_t **v14;     // eax
  int32_t v15;       // eax
  int32_t *v16;      // edx
  void *blocPtrs;    // eax
  void *v18;         // eax
  void *v19;         // eax

  v2 = *(_DWORD **)&a1->loc[4 * a2];
  if (v2)
    return increment(a1, v2);
  v4 = 32 * a1->blocNode;
  v5 = &a1->nodeList[v4];
  v6 = &a1->nodeList[v4 + 32];
  a1->blocNode += 2;
  *((_DWORD *)v6 + 7) = 257;
  *((_DWORD *)v6 + 6) = 1;
  *((_DWORD *)v6 + 3) = *(_DWORD *)(a1->lhead + 12);
  v7 = *(_DWORD *)(a1->lhead + 12);
  if (v7 && (*(_DWORD *)(v7 + 16) = v6, v8 = *(_DWORD *)(a1->lhead + 12),
             *(_DWORD *)(v8 + 24) == 1)) {
    *(_DWORD *)&a1->nodeList[v4 + 52] = *(_DWORD *)(v8 + 20);
  } else {
    freelist = (int32_t *)a1->freelist;
    if (freelist) {
      a1->freelist = *freelist;
    } else {
      blocPtrs = a1->blocPtrs;
      freelist = (int32_t *)&a1->nodePtrs[4 * (_DWORD)blocPtrs];
      a1->blocPtrs = (char *)blocPtrs + 1;
    }
    *((_DWORD *)v6 + 5) = freelist;
    *freelist = (int32_t)v6;
  }
  *(_DWORD *)(a1->lhead + 12) = v6;
  *((_DWORD *)v6 + 4) = a1->lhead;
  *((_DWORD *)v5 + 7) = a2;
  *((_DWORD *)v5 + 6) = 1;
  *((_DWORD *)v5 + 3) = *(_DWORD *)(a1->lhead + 12);
  v10 = *(_DWORD *)(a1->lhead + 12);
  if (v10) {
    *(_DWORD *)(v10 + 16) = v5;
    v11 = *(_DWORD *)(a1->lhead + 12);
    if (*(_DWORD *)(v11 + 24) == 1) {
      *((_DWORD *)v5 + 5) = *(_DWORD *)(v11 + 20);
    } else {
      v12 = (int32_t *)a1->freelist;
      if (v12) {
        a1->freelist = *v12;
      } else {
        v18 = a1->blocPtrs;
        v12 = (int32_t *)&a1->nodePtrs[4 * (_DWORD)v18];
        a1->blocPtrs = (char *)v18 + 1;
      }
      *((_DWORD *)v5 + 5) = v12;
      *v12 = (int32_t)v6;
    }
  } else {
    v16 = (int32_t *)a1->freelist;
    if (v16) {
      a1->freelist = *v16;
    } else {
      v19 = a1->blocPtrs;
      v16 = (int32_t *)&a1->nodePtrs[4 * (_DWORD)v19];
      a1->blocPtrs = (char *)v19 + 1;
    }
    *((_DWORD *)v5 + 5) = v16;
    *v16 = (int32_t)v5;
  }
  *(_DWORD *)(a1->lhead + 12) = v5;
  *((_DWORD *)v5 + 4) = a1->lhead;
  *((_DWORD *)v5 + 1) = 0;
  *(_DWORD *)v5 = 0;
  lhead = a1->lhead;
  v14 = *(uint8_t ***)(lhead + 8);
  if (v14) {
    if ((uint8_t *)lhead == *v14)
      *v14 = v6;
    else
      v14[1] = v6;
  } else {
    a1->tree = (int32_t)v6;
  }
  *((_DWORD *)v6 + 1) = v5;
  *(_DWORD *)v6 = a1->lhead;
  *((_DWORD *)v6 + 2) = *(_DWORD *)(a1->lhead + 8);
  v15 = a1->lhead;
  *((_DWORD *)v5 + 2) = v6;
  *(_DWORD *)(v15 + 8) = v6;
  *(_DWORD *)&a1->loc[4 * a2] = v5;
  return increment(a1, *((_DWORD **)v6 + 2));
}

void __cdecl Huff_Compress(struct msg_t *, int) { UNIMPLEMENTED(); }

void __cdecl Huff_Decompress(struct msg_t *, int) { UNIMPLEMENTED(); }

int marker_huffman;
void __cdecl swaplist(struct nodetype *, struct nodetype *) { UNIMPLEMENTED(); }

void __cdecl swap(struct huff_t *, struct nodetype *, struct nodetype *) {
  UNIMPLEMENTED();
}

void __cdecl free_ppnode(struct huff_t *, struct nodetype **) {
  UNIMPLEMENTED();
}

struct nodetype **__cdecl get_ppnode(struct huff_t *) {
  UNIMPLEMENTED();
}

int __cdecl get_bit(unsigned char *) { UNIMPLEMENTED(); }

void __cdecl add_bit(char, unsigned char *) { UNIMPLEMENTED(); }

void __cdecl increment(struct huff_t *, struct nodetype *) { UNIMPLEMENTED(); }
