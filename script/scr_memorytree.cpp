unsigned int __cdecl Scr_GetStringUsage() { return dword_476A28; }

void __cdecl MT_DumpTree() {
  int v0;              // edi
  int v1;              // edx
  int v2;              // eax
  unsigned __int16 v3; // ax
  int *v4;             // ebx
  int SubTreeSize;     // esi
  int *v6;             // [esp+2Ch] [ebp-1Ch]

  Com_Printf("********************************\n");
  v0 = 0;
  v6 = scrMemTreeGlob;
  do {
    v3 = *((_WORD *)v6 + 262528);
    if (v3) {
      v4 = &scrMemTreeGlob[2 * v3];
      SubTreeSize = MT_GetSubTreeSize(*(unsigned __int16 *)v4);
      v1 = SubTreeSize + MT_GetSubTreeSize(*((unsigned __int16 *)v4 + 1)) + 1;
      v2 = v1 << v0;
    } else {
      v1 = 0;
      v2 = 0;
    }
    Com_Printf("%d subtree has %d * %d = %d free buckets\n", v0, v1, 1 << v0,
               v2);
    ++v0;
    v6 = (int *)((char *)v6 + 2);
  } while (v0 != 17);
  Com_Printf("********************************\n");
  Com_Printf("********************************\n");
  Com_Printf("total memory alloc buckets: %d (%d instances)\n", dword_476A28,
             dword_476A24);
  Com_Printf("total memory free buckets: %d\n", 0xFFFF - dword_476A28);
  Com_Printf("********************************\n");
}

void __cdecl MT_Init() {
  int v0;     // ebx
  int *v1;    // esi
  int v2;     // edx
  char v3;    // cl
  char v4;    // cl
  int v5;     // eax
  char v6;    // dl
  int *v7;    // eax
  int i;      // ebx
  int result; // eax

  scrMemTreePub = (int)scrMemTreeGlob;
  v0 = 0;
  v1 = scrMemTreeGlob;
LABEL_2:
  *((_BYTE *)v1 + 524544) = 0;
LABEL_3:
  *((_BYTE *)v1 + 0x80000) = 8;
  if (v0) {
    while (1) {
      v5 = v0;
      v6 = 0;
      do {
        ++v6;
        v5 >>= 1;
      } while (v5);
      *((_BYTE *)&loc_80200 + (_DWORD)v1) = v6;
      ++v0;
      v1 = (int *)((char *)v1 + 1);
      if (v0 == 256)
        break;
    LABEL_5:
      if (!v0)
        goto LABEL_2;
      v2 = v0;
      v3 = 0;
      do {
        v3 -= ((v2 & 1) == 0) - 1;
        v2 >>= 1;
      } while (v2);
      *((_BYTE *)v1 + 524544) = v3;
      if (!(_BYTE)v0)
        goto LABEL_3;
      v4 = 8;
      do
        --v4;
      while ((((1 << v4) - 1) & v0) != 0);
      *((_BYTE *)v1 + 0x80000) = v4;
      if (!v0)
        goto LABEL_4;
    }
  } else {
  LABEL_4:
    *((_BYTE *)&loc_80200 + (_DWORD)v1) = 0;
    ++v0;
    v1 = (int *)((char *)v1 + 1);
    if (v0 != 256)
      goto LABEL_5;
  }
  v7 = scrMemTreeGlob;
  do {
    *((_WORD *)v7 + 262528) = 0;
    v7 = (int *)((char *)v7 + 2);
  } while (&unk_3F6722 != (_UNKNOWN *)v7);
  scrMemTreeGlob[0] = 0;
  for (i = 0; i != 16; ++i)
    result = MT_AddMemoryNode(1 << i, i);
  dword_476A24 = 0;
  dword_476A28 = 0;
  return result;
}

void __cdecl MT_FinishForceAlloc(unsigned char *allocBits) {
  int i;                // edi
  unsigned __int16 v2;  // ax
  int v3;               // edx
  int v4;               // ecx
  int v5;               // ebx
  unsigned __int16 v6;  // ax
  int v7;               // edx
  int v9;               // esi
  unsigned __int16 v10; // di
  int v11;              // edx
  int v12;              // ecx
  int v13;              // edx
  char v14;             // cl
  int v15;              // ecx
  int v16;              // edx
  char v17;             // cl
  int v18;              // edx
  int v19;              // ecx
  int v20;              // ebx
  int v21;              // esi
  unsigned __int16 v22; // ax
  unsigned __int16 v23; // di
  int v24;              // edx
  int v25;              // ecx
  int v26;              // edx
  char v27;             // cl
  int v28;              // ecx
  int v29;              // edx
  char v30;             // cl
  int v31;              // [esp+28h] [ebp-B0h]
  int v32;              // [esp+30h] [ebp-A8h]
  int v33;              // [esp+3Ch] [ebp-9Ch]
  int v34;              // [esp+40h] [ebp-98h]
  int v35;              // [esp+44h] [ebp-94h]
  int *v36;             // [esp+48h] [ebp-90h]
  int v37;              // [esp+4Ch] [ebp-8Ch]
  int j;                // [esp+50h] [ebp-88h]
  int v39;              // [esp+54h] [ebp-84h]
  int *v40;             // [esp+58h] [ebp-80h]
  int v41;              // [esp+5Ch] [ebp-7Ch]
  unsigned __int16 v42; // [esp+60h] [ebp-78h]
  unsigned __int16 v43; // [esp+76h] [ebp-62h]
  int v44;              // [esp+78h] [ebp-60h]
  int v45;              // [esp+7Ch] [ebp-5Ch]
  unsigned __int16 v46; // [esp+80h] [ebp-58h]
  unsigned __int16 v47; // [esp+9Eh] [ebp-3Ah]
  int v48;              // [esp+A0h] [ebp-38h]
  int v49;              // [esp+A8h] [ebp-30h]
  int v50;              // [esp+ACh] [ebp-2Ch]

  v33 = 1;
LABEL_2:
  while (2) {
    if ((((int)a1[v33 >> 3] >> (v33 & 7)) & 1) != 0)
      goto LABEL_17;
    v50 = v33;
    v35 = 0;
    for (i = 525056;; i += 2) {
      v36 = (int *)((char *)scrMemTreeGlob + i);
      v2 = *(_WORD *)((char *)scrMemTreeGlob + i);
      v3 = v2;
      if (v2) {
        if (v2 == v50) {
        LABEL_19:
          v44 = dword_3F6704[2 * v50];
          v42 = HIWORD(scrMemTreeGlob[2 * v50]);
          v43 = scrMemTreeGlob[2 * v50];
          while (1) {
            if (v43) {
              if (v42) {
                v9 = v43;
                v12 = (unsigned __int8)-(char)v43;
                v13 =
                    0x10000 - v43 -
                    ((unsigned __int8)byte_476800[(unsigned __int16)-v43 >> 8] +
                     (unsigned __int8)byte_476800[v12]);
                v14 = byte_476700[v12];
                if (!(_BYTE)v43)
                  v14 += byte_476700[(unsigned __int16)-v43 >> 8];
                v37 = (1 << v14) + v13;
                v10 = v42;
                v15 = (unsigned __int8)-(char)v42;
                v45 = (unsigned __int8)((unsigned __int16)-v42 >> 8);
                v16 = 0x10000 - v42 -
                      ((unsigned __int8)byte_476800[v45] +
                       (unsigned __int8)byte_476800[v15]);
                v17 = byte_476700[v15];
                if (!(_BYTE)v42)
                  v17 += byte_476700[v45];
                if (v37 >= v16 + (1 << v17)) {
                  *(_WORD *)v36 = v43;
                  v36 = &scrMemTreeGlob[2 * v43];
                } else {
                  *(_WORD *)v36 = v42;
                  v36 = (int *)(8 * v42 + 4155138);
                  v9 = v42;
                }
              } else {
                v9 = v43;
                *(_WORD *)v36 = v43;
                v36 = &scrMemTreeGlob[2 * v43];
                v10 = 0;
              }
            } else {
              v9 = v42;
              v10 = v42;
              *(_WORD *)v36 = v42;
              if (!v42) {
                MT_AddMemoryNode(v50, v35);
                if (++v33 == 0x10000)
                  return Z_VirtualFreeInternal(a1);
                goto LABEL_2;
              }
              v36 = (int *)(8 * v42 + 4155138);
            }
            HIWORD(v32) = v10;
            LOWORD(v32) = v43;
            v11 = v44;
            v44 = dword_3F6704[2 * v9];
            v42 = HIWORD(scrMemTreeGlob[2 * v9]);
            v43 = scrMemTreeGlob[2 * v9];
            scrMemTreeGlob[2 * v9] = v32;
            dword_3F6704[2 * v9] = v11;
          }
        }
        if (v50) {
          v4 = 0;
          v5 = 0x10000;
          do {
            v5 >>= 1;
            if (v4 > v50) {
              v36 = &scrMemTreeGlob[2 * v3];
              v4 -= v5;
              v3 = *(unsigned __int16 *)v36;
              if (!*(_WORD *)v36)
                break;
            } else {
              v36 = (int *)(8 * v3 + 4155138);
              v4 += v5;
              v6 = HIWORD(scrMemTreeGlob[2 * v3]);
              v3 = v6;
              if (!v6)
                break;
            }
            if (v50 == v3)
              goto LABEL_19;
          } while (v4 != v50);
        }
      }
      if (v35 == 16)
        break;
      v50 &= ~(1 << v35++);
    }
    v49 = v33;
    v34 = 1;
    for (j = 0; j != 16; v34 = 1 << j) {
      v18 = v49 ^ v34;
      v40 = (int *)((char *)&scrMemTreeGlob[131264] + 2 * j);
      v19 = *(unsigned __int16 *)v40;
      if (!*(_WORD *)v40) {
        v7 = j;
        goto LABEL_16;
      }
      if (v18 != *(unsigned __int16 *)v40) {
        if (v18) {
          v20 = 0;
          v21 = 0x10000;
          do {
            v21 >>= 1;
            if (v20 > v18) {
              v40 = &scrMemTreeGlob[2 * v19];
              v20 -= v21;
              v19 = *(unsigned __int16 *)v40;
              if (!*(_WORD *)v40)
                break;
            } else {
              v40 = (int *)(8 * v19 + 4155138);
              v20 += v21;
              v22 = HIWORD(scrMemTreeGlob[2 * v19]);
              v19 = v22;
              if (!v22)
                break;
            }
            if (v18 == v19)
              goto LABEL_46;
          } while (v20 != v18);
        }
        v7 = j;
        goto LABEL_16;
      }
    LABEL_46:
      v48 = dword_3F6704[2 * v18];
      v46 = HIWORD(scrMemTreeGlob[2 * v18]);
      v47 = scrMemTreeGlob[2 * v18];
      while (v47) {
        if (v46) {
          v39 = v47;
          v25 = (unsigned __int8)-(char)v47;
          v26 = 0x10000 - v47 -
                ((unsigned __int8)byte_476800[(unsigned __int16)-v47 >> 8] +
                 (unsigned __int8)byte_476800[v25]);
          v27 = byte_476700[v25];
          if (!(_BYTE)v47)
            v27 += byte_476700[(unsigned __int16)-v47 >> 8];
          v41 = (1 << v27) + v26;
          v23 = v46;
          v28 = (unsigned __int8)-(char)v46;
          v29 = 0x10000 - v46 -
                ((unsigned __int8)byte_476800[(unsigned __int16)-v46 >> 8] +
                 (unsigned __int8)byte_476800[v28]);
          v30 = byte_476700[v28];
          if (!(_BYTE)v46)
            v30 += byte_476700[(unsigned __int16)-v46 >> 8];
          if (v41 >= v29 + (1 << v30)) {
            *(_WORD *)v40 = v47;
            v40 = &scrMemTreeGlob[2 * v47];
          } else {
            *(_WORD *)v40 = v46;
            v40 = (int *)(8 * v46 + 4155138);
            v39 = v46;
          }
        } else {
          v39 = v47;
          *(_WORD *)v40 = v47;
          v40 = &scrMemTreeGlob[2 * v47];
          v23 = 0;
        }
      LABEL_49:
        HIWORD(v31) = v23;
        LOWORD(v31) = v47;
        v24 = v48;
        v48 = dword_3F6704[2 * v39];
        v46 = HIWORD(scrMemTreeGlob[2 * v39]);
        v47 = scrMemTreeGlob[2 * v39];
        scrMemTreeGlob[2 * v39] = v31;
        dword_3F6704[2 * v39] = v24;
      }
      v39 = v46;
      v23 = v46;
      *(_WORD *)v40 = v46;
      if (v46) {
        v40 = (int *)(8 * v46 + 4155138);
        goto LABEL_49;
      }
      v49 &= ~v34;
      ++j;
    }
    v7 = 16;
  LABEL_16:
    MT_AddMemoryNode(v49, v7);
  LABEL_17:
    if (++v33 != 0x10000)
      continue;
    return Z_VirtualFreeInternal(a1);
  }
}

int __cdecl MT_Realloc(int oldNumBytes, int newNumbytes) { UNIMPLEMENTED(); }

void __cdecl MT_ForceAllocIndex(unsigned char *allocBits, unsigned int nodeNum,
                                int numBytes) {
  UNIMPLEMENTED();
}

void __cdecl MT_FreeIndex(unsigned int nodeNum, int numBytes) {
  UNIMPLEMENTED();
}

unsigned short __cdecl MT_AllocIndex(int numBytes, int type) {
  int v1;               // eax
  int v2;               // eax
  int v4;               // edx
  int v5;               // ebx
  int v6;               // eax
  int v7;               // esi
  unsigned __int16 v8;  // di
  int v9;               // edx
  int v10;              // ecx
  int v11;              // edx
  char v12;             // cl
  int v13;              // ecx
  int v14;              // edx
  char v15;             // cl
  int v16;              // ebx
  int v17;              // eax
  __int16 *v18;         // edx
  int v19;              // [esp+0h] [ebp-98h]
  int v20;              // [esp+4h] [ebp-94h]
  int v21;              // [esp+30h] [ebp-68h]
  unsigned __int16 v22; // [esp+3Ch] [ebp-5Ch]
  int v23;              // [esp+40h] [ebp-58h]
  int v24;              // [esp+44h] [ebp-54h]
  __int16 *v25;         // [esp+48h] [ebp-50h]
  int v26;              // [esp+4Ch] [ebp-4Ch]
  unsigned __int16 v27; // [esp+50h] [ebp-48h]
  unsigned __int16 v28; // [esp+66h] [ebp-32h]
  int v29;              // [esp+68h] [ebp-30h]
  int v30;              // [esp+6Ch] [ebp-2Ch]

  if (a1 <= 0xFFFF) {
    v1 = a1 + 7;
    if (a1 + 7 < 0)
      v1 = a1 + 14;
    v2 = (v1 >> 3) - 1;
    if (v2 > 255) {
      v23 = (unsigned __int8)byte_476900[v2 >> 8] + 8;
      if (v23 > 16)
        goto LABEL_6;
    } else {
      v23 = (unsigned __int8)byte_476900[v2];
      if ((unsigned int)v23 > 0x10) {
      LABEL_6:
        MT_DumpTree();
        Com_Printf(
            "%s: failed memory allocation of %d bytes for script usage\n",
            "MT_AllocIndex", a1);
        Scr_TerminalError("failed memory allocation for script usage");
        return 0;
      }
    }
    v4 = v23;
    v22 = word_476A00[v23];
    if (v22)
      goto LABEL_9;
  LABEL_29:
    v17 = v4;
    v18 = &word_476A00[v4];
    v24 = v17;
    do {
      if (++v24 == 17)
        goto LABEL_6;
      v22 = v18[1];
      ++v18;
    } while (!v22);
    v5 = v24;
    goto LABEL_10;
  }
  MT_DumpTree();
  Com_Printf("%s: failed memory allocation of %d bytes for script usage\n",
             "MT_GetSize: max allocation exceeded", a1);
  Scr_TerminalError("failed memory allocation for script usage");
  v23 = 0;
  v4 = 0;
  v22 = word_476A00[0];
  if (!word_476A00[0])
    goto LABEL_29;
LABEL_9:
  v24 = v4;
  v5 = v4;
LABEL_10:
  v25 = &word_476A00[v5];
  v6 = (unsigned __int16)word_476A00[v24];
  v29 = dword_3F6704[2 * v6];
  v27 = HIWORD(scrMemTreeGlob[2 * v6]);
  v28 = scrMemTreeGlob[2 * v6];
  while (v28) {
    if (v27) {
      v7 = v28;
      v10 = (unsigned __int8)-(char)v28;
      v11 = 0x10000 - v28 -
            ((unsigned __int8)byte_476800[(unsigned __int16)-v28 >> 8] +
             (unsigned __int8)byte_476800[v10]);
      v12 = byte_476700[v10];
      if (!(_BYTE)v28)
        v12 += byte_476700[(unsigned __int16)-v28 >> 8];
      v26 = (1 << v12) + v11;
      v8 = v27;
      v13 = (unsigned __int8)-(char)v27;
      v30 = (unsigned __int8)((unsigned __int16)-v27 >> 8);
      v14 = 0x10000 - v27 -
            ((unsigned __int8)byte_476800[v30] +
             (unsigned __int8)byte_476800[v13]);
      v15 = byte_476700[v13];
      if (!(_BYTE)v27)
        v15 += byte_476700[v30];
      if (v26 >= v14 + (1 << v15)) {
        *v25 = v28;
        v25 = (__int16 *)&scrMemTreeGlob[2 * v28];
      } else {
        *v25 = v27;
        v25 = (__int16 *)(8 * v27 + 4155138);
        v7 = v27;
      }
    } else {
      v7 = v28;
      *v25 = v28;
      v25 = (__int16 *)&scrMemTreeGlob[2 * v28];
      v8 = 0;
    }
  LABEL_13:
    HIWORD(v21) = v8;
    LOWORD(v21) = v28;
    v9 = v29;
    v29 = dword_3F6704[2 * v7];
    v27 = HIWORD(scrMemTreeGlob[2 * v7]);
    v28 = scrMemTreeGlob[2 * v7];
    scrMemTreeGlob[2 * v7] = v21;
    dword_3F6704[2 * v7] = v9;
  }
  v7 = v27;
  v8 = v27;
  *v25 = v27;
  if (v27) {
    v25 = (__int16 *)(8 * v27 + 4155138);
    goto LABEL_13;
  }
  if (v24 != v23) {
    v16 = v24;
    do {
      --v16;
      MT_AddMemoryNode(v19, v20);
    } while (v16 != v23);
  }
  ++dword_476A24;
  dword_476A28 += 1 << v23;
  return v22;
}

void __cdecl MT_Free(void *p, int numBytes) {
  int v2;               // eax
  int v3;               // eax
  int v4;               // ebx
  int i;                // edx
  int v6;               // edx
  int v7;               // ecx
  int v8;               // ebx
  int v9;               // esi
  int *v10;             // ecx
  unsigned __int16 v11; // ax
  int v13;              // esi
  unsigned __int16 v14; // di
  int v15;              // edx
  int v16;              // ecx
  int v17;              // edx
  char v18;             // cl
  int v19;              // ecx
  int v20;              // edx
  char v21;             // cl
  int v22;              // [esp+0h] [ebp-88h]
  int v23;              // [esp+4h] [ebp-84h]
  int v24;              // [esp+28h] [ebp-60h]
  int v25;              // [esp+30h] [ebp-58h]
  int v26;              // [esp+34h] [ebp-54h]
  int *v27;             // [esp+38h] [ebp-50h]
  int v28;              // [esp+3Ch] [ebp-4Ch]
  unsigned __int16 v29; // [esp+40h] [ebp-48h]
  unsigned __int16 v30; // [esp+56h] [ebp-32h]
  int v31;              // [esp+58h] [ebp-30h]
  int v32;              // [esp+5Ch] [ebp-2Ch]
  int v33;              // [esp+90h] [ebp+8h]

  v33 = (a1 - (_BYTE *)scrMemTreeGlob) >> 3;
  if (a2 > 0xFFFF) {
    MT_DumpTree();
    Com_Printf("%s: failed memory allocation of %d bytes for script usage\n",
               "MT_GetSize: max allocation exceeded", a2);
    Scr_TerminalError("failed memory allocation for script usage");
    v26 = 0;
    v25 = 1;
  } else {
    v2 = a2 + 7;
    if (a2 + 7 < 0)
      v2 = a2 + 14;
    v3 = (v2 >> 3) - 1;
    if (v3 > 255) {
      v26 = (unsigned __int8)byte_476900[v3 >> 8] + 8;
      v25 = 1 << v26;
      --dword_476A24;
      v4 = 1 << v26;
      dword_476A28 -= 1 << v26;
      if (v26 != 16)
        goto LABEL_7;
      return MT_AddMemoryNode(v22, v23);
    }
    v26 = (unsigned __int8)byte_476900[v3];
    v25 = 1 << v26;
  }
  --dword_476A24;
  v4 = v25;
  dword_476A28 -= v25;
  if (v26 != 16) {
  LABEL_7:
    for (i = v4;; i = 1 << v26) {
      v6 = v33 ^ i;
      v27 = (int *)((char *)&scrMemTreeGlob[131264] + 2 * v26);
      v7 = *(unsigned __int16 *)v27;
      if (!*(_WORD *)v27)
        return MT_AddMemoryNode(v22, v23);
      if (v6 != *(unsigned __int16 *)v27) {
        if (v6) {
          v8 = 0;
          v9 = 0x10000;
          do {
            v9 >>= 1;
            if (v8 > v6) {
              v10 = &scrMemTreeGlob[2 * v7];
              v27 = v10;
              v8 -= v9;
            } else {
              v10 = (int *)(8 * v7 + 4155138);
              v27 = v10;
              v8 += v9;
            }
            v11 = *(_WORD *)v10;
            v7 = *(unsigned __int16 *)v10;
            if (!v11)
              break;
            if (v6 == v11)
              goto LABEL_21;
          } while (v8 != v6);
        }
        return MT_AddMemoryNode(v22, v23);
      }
    LABEL_21:
      v31 = dword_3F6704[2 * v6];
      v29 = HIWORD(scrMemTreeGlob[2 * v6]);
      v30 = scrMemTreeGlob[2 * v6];
      while (v30) {
        if (v29) {
          v13 = v30;
          v16 = (unsigned __int8)-(char)v30;
          v17 = 0x10000 - v30 -
                ((unsigned __int8)byte_476800[(unsigned __int16)-v30 >> 8] +
                 (unsigned __int8)byte_476800[v16]);
          v18 = byte_476700[v16];
          if (!(_BYTE)v30)
            v18 += byte_476700[(unsigned __int16)-v30 >> 8];
          v28 = (1 << v18) + v17;
          v14 = v29;
          v19 = (unsigned __int8)-(char)v29;
          v32 = (unsigned __int8)((unsigned __int16)-v29 >> 8);
          v20 = 0x10000 - v29 -
                ((unsigned __int8)byte_476800[v32] +
                 (unsigned __int8)byte_476800[v19]);
          v21 = byte_476700[v19];
          if (!(_BYTE)v29)
            v21 += byte_476700[v32];
          if (v28 >= v20 + (1 << v21)) {
            *(_WORD *)v27 = v30;
            v27 = &scrMemTreeGlob[2 * v30];
          } else {
            *(_WORD *)v27 = v29;
            v27 = (int *)(8 * v29 + 4155138);
            v13 = v29;
          }
        } else {
          v13 = v30;
          *(_WORD *)v27 = v30;
          v27 = &scrMemTreeGlob[2 * v30];
          v14 = 0;
        }
      LABEL_24:
        HIWORD(v24) = v14;
        LOWORD(v24) = v30;
        v15 = v31;
        v31 = dword_3F6704[2 * v13];
        v29 = HIWORD(scrMemTreeGlob[2 * v13]);
        v30 = scrMemTreeGlob[2 * v13];
        scrMemTreeGlob[2 * v13] = v24;
        dword_3F6704[2 * v13] = v15;
      }
      v13 = v29;
      v14 = v29;
      *(_WORD *)v27 = v29;
      if (v29)
        break;
      v33 &= ~v25;
      v25 = 1 << ++v26;
      if (v26 == 16)
        return MT_AddMemoryNode(v22, v23);
    }
    v27 = (int *)(8 * v29 + 4155138);
    goto LABEL_24;
  }
  return MT_AddMemoryNode(v22, v23);
}

void *__cdecl MT_Alloc(int numBytes, int type) {
  return &scrMemTreeGlob[2 * (unsigned __int16)MT_AllocIndex(a1, a2)];
}

unsigned char *__cdecl MT_InitForceAlloc() { UNIMPLEMENTED(); }

struct scrMemTreePub_t scrMemTreePub;
int marker_scr_memorytree;
int __cdecl MT_GetScore(int) { UNIMPLEMENTED(); }

void __cdecl MT_InitBits(void) { UNIMPLEMENTED(); }

int __cdecl MT_GetSubTreeSize(int) { UNIMPLEMENTED(); }

void __cdecl MT_RemoveHeadMemoryNode(int) { UNIMPLEMENTED(); }

bool __cdecl MT_RemoveMemoryNode(int, int) { UNIMPLEMENTED(); }

void __cdecl MT_AddMemoryNode(int, int) { UNIMPLEMENTED(); }

void __cdecl MT_SafeFreeIndex(unsigned int) { UNIMPLEMENTED(); }

void __cdecl MT_Error(char const *, int) { UNIMPLEMENTED(); }

int __cdecl MT_GetSize(int) { UNIMPLEMENTED(); }
