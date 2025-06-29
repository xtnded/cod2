void __cdecl Byte4SetNativeColor(unsigned char *const, unsigned char,
                                 unsigned char, unsigned char, unsigned char) {
  UNIMPLEMENTED();
}

void __cdecl R_SwitchFog(int, int) {
  int result; // eax

  unk_1181E0C = a1;
  if (LOBYTE(dword_1181DC8[0])) {
    dword_1181DC8[1] = unk_1181DAC;
    dword_1181DC8[2] = unk_1181DB0;
    dword_1181DC8[3] = unk_1181DB4;
    dword_1181DC8[4] = unk_1181DB8;
    dword_1181DC8[5] = unk_1181DBC;
    dword_1181DC8[6] = unk_1181DC0;
    dword_1181DC8[7] = unk_1181DC4;
    dword_1181DC8[8] = dword_1181DC8[0];
  } else {
    dword_1181DC8[1] = *(_DWORD *)&rg[32 * a1 + 5228];
    dword_1181DC8[2] = *(_DWORD *)&rg[32 * a1 + 5232];
    dword_1181DC8[3] = *(_DWORD *)&rg[32 * a1 + 5236];
    dword_1181DC8[4] = *(_DWORD *)&rg[32 * a1 + 5240];
    dword_1181DC8[5] = *(_DWORD *)&rg[32 * a1 + 5244];
    dword_1181DC8[6] = *(_DWORD *)&rg[32 * a1 + 5248];
    dword_1181DC8[7] = *(_DWORD *)&rg[32 * a1 + 5252];
    dword_1181DC8[8] = *(_DWORD *)&rg[32 * a1 + 5256];
    a3 = 0;
  }
  dword_1181DC8[9] = *(_DWORD *)&rg[32 * unk_1181E0C + 5228];
  dword_1181DC8[10] = *(_DWORD *)&rg[32 * unk_1181E0C + 5232];
  dword_1181DC8[11] = *(_DWORD *)&rg[32 * unk_1181E0C + 5236];
  dword_1181DC8[12] = *(_DWORD *)&rg[32 * unk_1181E0C + 5240];
  dword_1181DC8[13] = *(_DWORD *)&rg[32 * unk_1181E0C + 5244];
  dword_1181DC8[14] = *(_DWORD *)&rg[32 * unk_1181E0C + 5248];
  dword_1181DC8[15] = *(_DWORD *)&rg[32 * unk_1181E0C + 5252];
  result = *(_DWORD *)&rg[32 * unk_1181E0C + 5256];
  dword_1181DC8[16] = result;
  if (a3) {
    dword_1181DC8[10] = a2;
    result = a3 + a2;
    dword_1181DC8[11] = a3 + a2;
  } else {
    dword_1181DC8[10] = 0;
    dword_1181DC8[11] = 0;
  }
  return result;
}

void __cdecl R_ClearFogs() { UNIMPLEMENTED(); }

void __cdecl R_ArchiveFogState(struct MemoryFile *memFile) {
  ((void(__cdecl *)(MemoryFile *, int, void *))a1->archiveProc)(a1, 160,
                                                                &unk_1181D6C);
  return ((int(__cdecl *)(MemoryFile *, int, void *))a1->archiveProc)(
      a1, 4, &unk_1181E0C);
}

void __cdecl R_SetFog(int fogvar, float start, float end, unsigned char r,
                      unsigned char g, unsigned char b, float density) {
  char *v7;   // edx
  char *v8;   // ecx
  int result; // eax

  v7 = &rg[32 * a1 + 5240];
  v7[2] = a4;
  v7[1] = a5;
  *v7 = a6;
  v7[3] = -1;
  v8 = &rg[32 * a1];
  *((float *)v8 + 1311) = a2;
  *((float *)v8 + 1312) = a3;
  if (a7 < 1.0) {
    *((_DWORD *)v8 + 1307) = 2;
    v8[5257] = 1;
    v8[5258] = 0;
    *((float *)v8 + 1313) = a7;
  } else {
    *((_DWORD *)v8 + 1307) = 1;
    v8[5257] = 1;
    v8[5258] = 0;
    *((_DWORD *)v8 + 1313) = 1065353216;
  }
  result = 32 * a1;
  rg[32 * a1 + 5256] = 1;
  return result;
}

int marker_r_fog;
