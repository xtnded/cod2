int __cdecl Scr_Allign2(int) { UNIMPLEMENTED(); }

int __cdecl Scr_Allign4(int) { UNIMPLEMENTED(); }

int __cdecl Scr_Allign2Strict(int) { UNIMPLEMENTED(); }

int __cdecl Scr_Allign4Strict(int) { UNIMPLEMENTED(); }

void __cdecl TempMemoryReset() { *(_DWORD *)currentPos = 0; }

char *__cdecl TempMalloc(int len) { UNIMPLEMENTED(); }

void __cdecl TempMemorySetPos(char *pos) { UNIMPLEMENTED(); }

char *__cdecl TempMallocAlignStrict(int len) { UNIMPLEMENTED(); }

char *__cdecl TempMallocAlign(int len) { UNIMPLEMENTED(); }

int marker_scr_tempmemory;
