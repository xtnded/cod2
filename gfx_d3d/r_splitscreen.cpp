void __cdecl R_InitDrawGroups() { UNIMPLEMENTED(); }

void __cdecl R_IssueDrawGroups() {
  char *v0;   // edi
  int v1;     // ebx
  int v2;     // esi
  int result; // eax
  int v4;     // [esp+18h] [ebp-20h]
  int v5;     // [esp+1Ch] [ebp-1Ch]

  v5 = 0;
  v0 = delayedGroup;
  v4 = 0;
  do {
    if (*((_DWORD *)v0 + 1) != -1) {
      R_IssueDelayedDrawing(*((_DWORD *)v0 + 1));
      *((_DWORD *)v0 + 1) = -1;
    }
    v1 = v4 + 18975104;
    v2 = 4;
    do {
      if (*(_DWORD *)(v1 + 8) != -1) {
        R_IssueDelayedDrawing(*(_DWORD *)(v1 + 8));
        *(_DWORD *)(v1 + 8) = -1;
      }
      v1 += 4;
      --v2;
    } while (v2);
    result = *((_DWORD *)v0 + 6);
    if (result != -1) {
      result = R_IssueDelayedDrawing(*((_DWORD *)v0 + 6));
      *((_DWORD *)v0 + 6) = -1;
    }
    ++v5;
    v4 += 28;
    v0 += 28;
  } while (v5 != 5);
  return result;
}

void __cdecl R_EndDrawGroupSection(enum GfxDrawGroupType group) {
  GfxDrawGroupType result; // eax

  result = a1;
  if (delayedGroup[28 * a1]) {
    result = R_EndDelayedDrawing(dword_1218998[7 * a1]);
    delayedGroup[28 * a1] = 0;
  }
  return result;
}

enum GfxDrawGroupGlueBehavior __cdecl R_EndDrawGroupLoop(
    enum GfxDrawGroupType group, int viewIndex) {
  if (*(&dword_1218988 + 7 * a1 + a2) != -1)
    R_EndDelayedDrawing(*(&dword_1218988 + 7 * a1 + a2));
  if (dword_1218998[7 * a1] != -1)
    return 1;
  delayedGroup[28 * a1] = 1;
  *((_DWORD *)&unk_1218990 + 7 * a1 + 2) = R_BeginDelayedDrawing();
  return 0;
}

void __cdecl R_BeginDrawGroupLoop(enum GfxDrawGroupType, int) {
  int result; // eax

  if (delayedGroup[28 * a1]) {
    R_EndDelayedDrawing(dword_1218984[7 * a1]);
    delayedGroup[28 * a1] = 0;
  }
  result = R_BeginDelayedDrawing();
  *(_DWORD *)&delayedGroup[28 * a1 + 8 + 4 * a2] = result;
  return result;
}

enum GfxDrawGroupGlueBehavior __cdecl R_BeginDrawGroupSection(
    enum GfxDrawGroupType group) {
  if (dword_1218984[7 * a1] != -1)
    return 1;
  delayedGroup[28 * a1] = 1;
  dword_1218984[7 * a1] = R_BeginDelayedDrawing();
  return 0;
}

struct GfxDrawGroupCommands *delayedGroup;
