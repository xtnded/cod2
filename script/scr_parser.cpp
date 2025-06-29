int __cdecl Scr_GetSourceBuffer(char const *codePos)
{
  int v1;     // ecx
  _DWORD *v2; // edx
  int v3;     // ebx

  v1 = dword_114DF88 - 1;
    if (dword_114DF88 - 1 > 0) {
      v2 = (char *)scrParserPub + 24 * v1;
      v3 = 0;
        do {
          if (*v2 && *v2 <= (unsigned int)a1)
            break;
          --v1;
          ++v3;
          v2 -= 6;
        }
      while (v3 != dword_114DF88 - 1);
    }
  return v1;
}

int __cdecl Scr_HasSourceFiles(void)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetClosestSourcePosOfType(int, unsigned int, int)
{
  UNIMPLEMENTED();
}

char const *__cdecl Scr_GetOpcodePosOfType(int, unsigned int, unsigned int, int,
                                           unsigned int *)
{
  UNIMPLEMENTED();
}

void __cdecl AddThreadStartOpcodePos(unsigned int sourcePos)
{
  int *result; // eax

  result = (int *)&scrVarPub;
    if (unk_100CEAA) {
      result = scrCompilePub;
        if (dword_114CF48 != 2) {
          result = (int *)((char *)_src + 8 * dword_114DFD0);
          *result = a1;
          result[1] = 4;
          dword_114DFD0 = -1;
        }
    }
  return result;
}

void __cdecl RemoveOpcodePos()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_ShutdownOpcodeLookup()
{
  int v0;          // ebx
  void **v1;       // edx
  unsigned int v2; // ebx
  unsigned int v3; // eax

    if (scrParserGlob) {
      Z_FreeInternal(scrParserGlob);
      scrParserGlob = 0;
    }
    if (_src) {
      Z_FreeInternal(_src);
      _src = 0;
    }
    if (scrParserPub) {
        if (dword_114DF88) {
          v2 = 0;
          v3 = 0;
            do {
              Z_FreeInternal(*((void **)scrParserPub + 6 * v3 + 1));
              v3 = ++v2;
            }
          while (v2 < dword_114DF88);
        }
      Z_FreeInternal(scrParserPub);
      scrParserPub = 0;
    }
    if (dword_114DFC4) {
        if (dword_114DFC8 <= 0) {
          Z_FreeInternal((void *)dword_114DFC4);
          dword_114DFC4 = 0;
        }
        else {
          v0 = 0;
          v1 = (void **)dword_114DFC4;
            do {
                if (v1[2 * v0]) {
                  Z_FreeInternal(v1[2 * v0]);
                  v1 = (void **)dword_114DFC4;
                }
              ++v0;
            }
          while (v0 < dword_114DFC8);
          Z_FreeInternal(v1);
          dword_114DFC4 = 0;
        }
    }
}

int __cdecl Scr_GetLineNum(int, unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetPrevSourcePos(char const *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_GetFileAndLine(char const *, char **, int *)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_GetSourcePos(int, unsigned int, char *, int)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_GetSourcePosOfType(char const *, int, struct Scr_SourcePos_t *)
{
  UNIMPLEMENTED();
}

void __cdecl AddOpcodePos(unsigned int sourcePos, int type)
{
  unsigned int v2; // esi
  char **result;   // eax
  int v4;          // edx
  int v5;          // edx
  char *v6;        // eax
  _DWORD *v7;      // ebx
  int v8;          // edx
  _DWORD *v9;      // ecx
  void *v10;       // ebx
  void *v11;       // ebx

  v2 = a2;
  result = &scrVarPub;
  if (!unk_100CEAA || dword_114CF48 == 2)
    return result;
  if (!byte_114CF45)
    v2 = a2 & 0xFFFFFFFE;
  v4 = dword_114DFA4;
    if (dword_114DFA8 >= (unsigned int)dword_114DFA4) {
      dword_114DFA4 *= 2;
      v11 = Z_MallocInternal(40 * v4);
      memcpy(v11, scrParserGlob, 20 * dword_114DFA8);
      Z_FreeInternal(scrParserGlob);
      scrParserGlob = v11;
      v5 = dword_114DFB0;
        if (dword_114DFB4 < (unsigned int)dword_114DFB0) {
        LABEL_7:
          v6 = dword_114CF4C;
          if ((char *)dword_114DFBC != dword_114CF4C)
            goto LABEL_8;
          goto LABEL_19;
        }
    }
    else {
      v5 = dword_114DFB0;
      if (dword_114DFB4 < (unsigned int)dword_114DFB0)
        goto LABEL_7;
    }
  dword_114DFB0 = 2 * v5;
  v10 = Z_MallocInternal(16 * v5);
  memcpy(v10, _src, 8 * dword_114DFB4);
  Z_FreeInternal(_src);
  _src = v10;
  v6 = dword_114CF4C;
    if ((char *)dword_114DFBC != dword_114CF4C) {
    LABEL_8:
      dword_114DFC0 = 0;
      dword_114DFBC = (int)v6;
      v7 = (char *)scrParserGlob + 20 * dword_114DFA8;
      v7[1] = dword_114DFB4;
      *v7 = dword_114DFBC;
      v8 = dword_114DFC0 + v7[1];
      v9 = (char *)_src + 8 * v8;
      *v9 = a1;
      if (a1 != -1)
        goto LABEL_9;
    LABEL_20:
      dword_114DFCC = v8;
      v9[1] |= v2;
      result = (char **)(dword_114DFC0 + 1);
      dword_114DFC0 = (int)result;
      v7[2] = result;
      ++dword_114DFA8;
      ++dword_114DFB4;
      return result;
    }
LABEL_19:
  --dword_114DFA8;
  v7 = (char *)scrParserGlob + 20 * dword_114DFA8;
  v8 = dword_114DFC0 + v7[1];
  v9 = (char *)_src + 8 * v8;
  *v9 = a1;
  if (a1 == -1)
    goto LABEL_20;
LABEL_9:
    if (a1 == -2) {
      dword_114DFD0 = v8;
      v9[1] |= v2;
      result = (char **)(dword_114DFC0 + 1);
      dword_114DFC0 = (int)result;
      v7[2] = result;
      ++dword_114DFA8;
      ++dword_114DFB4;
    }
    else if (dword_114DFCC >= 0 && (v2 & 1) != 0) {
      *((_DWORD *)_src + 2 * dword_114DFCC) = a1;
      dword_114DFCC = -1;
      v9[1] |= v2;
      result = (char **)(dword_114DFC0 + 1);
      dword_114DFC0 = (int)result;
      v7[2] = result;
      ++dword_114DFA8;
      ++dword_114DFB4;
    }
    else {
      v9[1] |= v2;
      result = (char **)(dword_114DFC0 + 1);
      dword_114DFC0 = (int)result;
      v7[2] = result;
      ++dword_114DFA8;
      ++dword_114DFB4;
    }
  return result;
}

void __cdecl Scr_InitOpcodeLookup()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_GetCodePos(char const *, unsigned int, char *, int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_PrintPrevCodePos(enum print_msg_type_t type,
                                  char const *codePos, unsigned int index)
{
  int v3;           // esi
  _DWORD *v4;       // edx
  int v5;           // ecx
  int v6;           // ecx
  int v7;           // edi
  int v8;           // edx
  _DWORD *v9;       // [esp+1Ch] [ebp-4Ch]
  const char **v10; // [esp+34h] [ebp-34h]
  const char *v11;  // [esp+40h] [ebp-28h]
  char *v12;        // [esp+74h] [ebp+Ch]

    if (!a2) {
      v12 = "<frozen thread>\n";
      goto LABEL_20;
    }
    if (a2 == (char *)&g_EndPos) {
      v12 = "<removed thread>\n";
      goto LABEL_20;
    }
    if (!unk_100CEAA) {
        if (Scr_IsInOpcodeMemory(a2 - 1)) {
          v12 = va("@ %d\n", &a2[-unk_100CEE8]);
          goto LABEL_20;
        }
    LABEL_19:
      v12 = va("%s\n\n", a2);
    LABEL_20:
      Com_PrintMessage(a1, v12);
      return;
    }
  if (!unk_100CEE8 || !Scr_IsInOpcodeMemory(a2))
    goto LABEL_19;
  v11 = a2 - 1;
  v3 = dword_114DF88 - 1;
    if (dword_114DF88 - 1 <= 0) {
      v10 = (const char **)scrParserPub;
    }
    else {
      v10 = (const char **)scrParserPub;
      v4 = (char *)scrParserPub + 24 * v3;
      v5 = 0;
        do {
          if (*v4 && (unsigned int)v11 >= *v4)
            break;
          --v3;
          ++v5;
          v4 -= 6;
        }
      while (dword_114DF88 - 1 != v5);
    }
  v6 = dword_114DFA8 - 1;
    if (dword_114DFA8 - 1 >= 0) {
      v7 = 0;
        do {
          v8 = (v7 + v6) / 2;
          v9 = (char *)scrParserGlob + 20 * v8;
            if ((unsigned int)v11 >= *v9) {
              v7 = v8 + 1;
              if (dword_114DFA8 == v8 + 1 ||
                  (unsigned int)v11 < *((_DWORD *)scrParserGlob + 5 * v7))
                goto LABEL_23;
            }
            else {
              v6 = v8 - 1;
            }
        }
      while (v6 >= v7);
    }
  v9 = 0;
LABEL_23:
  Scr_PrintSourcePos(a1, v10[6 * v3 + 1], v10[6 * v3 + 2],
                     *((print_msg_type_t *)_src + 2 * v9[1] + 2 * a3));
}

char *__cdecl Scr_AddSourceBuffer(char const *filename, char const *extFilename,
                                  char const *codePos, bool archive)
{
  UNIMPLEMENTED();
}

void __cdecl RuntimeError(char const *codePos, unsigned int index,
                          char const *msg, char const *dialogMessage)
{
  print_msg_type_t v3; // esi
  char *v4;            // eax
  int v5;              // edi
  int *v6;             // ebx
  bool v7;             // [esp+2Bh] [ebp-1Dh]
  int v8;              // [esp+2Ch] [ebp-1Ch]

    if (unk_100CEAA) {
      if (!byte_1008214)
        goto LABEL_4;
    LABEL_9:
      Com_Printf("%s\n", a3);
      if (!byte_1008216)
        return;
    LABEL_6:
      Com_Error(5 - (byte_1008216 == 0),
                "\x15script runtime error\n(see console for details)\n%s%s%s",
                (char)a3);
      return;
    }
  if (!byte_1008216)
    return;
  if (byte_1008214)
    goto LABEL_9;
LABEL_4:
  v7 = (*(_DWORD *)&byte_1008214 & 0xFFFF00) != 0;
  v3 = (*(_DWORD *)&byte_1008214 & 0xFFFF00) == 0 ? PMSG_LOGFILE : PMSG_CONSOLE;
  v4 = va("\n******* script runtime error *******\n%s: ", a3);
  Com_PrintMessage(v3, v4);
  Scr_PrintPrevCodePos(v3, a1, a2);
    if (!dword_1008208) {
      Com_PrintMessage(v3, "************************************\n");
      if (!v7)
        return;
      goto LABEL_6;
    }
  v8 = dword_1008208 - 1;
    if (dword_1008208 - 1 > 0) {
      v5 = 0;
      v6 = &scrVmPub[6 * dword_1008208 + 2];
        do {
          Com_PrintMessage(v3, "called from:\n");
          Scr_PrintPrevCodePos(v3, (char *)*v6, v6[1] == 0);
          ++v5;
          v6 -= 6;
        }
      while (v8 != v5);
    }
  Com_PrintMessage(v3, "started from:\n");
  Scr_PrintPrevCodePos(v3, unk_1008220, 1u);
  Com_PrintMessage(v3, "************************************\n");
  if (v7)
    goto LABEL_6;
}

void __cdecl CompileError2(char const *codePos, char *msg, ...)
{
  UNIMPLEMENTED();
}

int marker_scr_parser;
struct scrParserGlob_t scrParserGlob;
struct scrParserPub_t scrParserPub;

int __cdecl Scr_GetLineNumInternal(char const *, unsigned int, char const **,
                                   int *)
{
  UNIMPLEMENTED();
}

struct OpcodeLookup *__cdecl Scr_GetSourcePosOpcodeLookup(char const *)
{
  UNIMPLEMENTED();
}

struct OpcodeLookup *__cdecl Scr_GetPrevSourcePosOpcodeLookup(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_GetLineInfo(char const *, unsigned int, int *, char *)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_PrintSourcePos(enum print_msg_type_t, char const *,
                                char const *, unsigned int)
{
  const char *v5;  // ebx
  int v6;          // ecx
  int j;           // edi
  char v8;         // al
  char *v9;        // eax
  const char *v10; // edx
  char *v11;       // eax
  char *v12;       // eax
  int v13;         // edx
  int i;           // eax
  int k;           // edi
  int v17;         // [esp+18h] [ebp-420h]
  int v18;         // [esp+1Ch] [ebp-41Ch]
  char v19[1048];  // [esp+20h] [ebp-418h] BYREF

    if (a4) {
      v5 = a3;
      v13 = 0;
        for (i = 0; i != a4; ++i) {
            while (*a3) {
              ++a3;
              if (a4 == ++i)
                goto LABEL_22;
            }
          v5 = a3 + 1;
          ++v13;
          ++a3;
        }
    LABEL_22:
      v17 = a3 - v5;
      v18 = v13;
    }
    else {
      v5 = a3;
      v17 = 0;
      v18 = 0;
    }
  v6 = strlen(v5);
    if (v6 <= 1023) {
        if (v6 < 0) {
          v9 = &v19[v6];
          if (v19[v6 - 1] != 13)
            goto LABEL_11;
          goto LABEL_17;
        }
    }
    else {
      v6 = 1023;
    }
    for (j = 1;; ++j) {
      v8 = v5[j - 1];
      if (v8 == 9)
        v8 = 32;
      v19[j - 1] = v8;
      if (v6 < j)
        break;
    }
  v9 = &v19[v6];
  if (v19[v6 - 1] == 13)
  LABEL_17:
    *(v9 - 1) = 0;
LABEL_11:
  v10 = " (savegame)";
  if (!dword_114DFC4)
    v10 = (const char *)&inData;
  v11 = va("(file '%s'%s, line %d)\n", a2, v10, v18 + 1);
  Com_PrintMessage(a1, v11);
  v12 = va("%s\n", v19);
  Com_PrintMessage(a1, v12);
    if (v17 > 0) {
      for (k = 0; k != v17; ++k)
        Com_PrintMessage(a1, " ");
    }
  Com_PrintMessage(a1, "*\n");
}

struct SourceBufferInfo *__cdecl Scr_GetNewSourceBuffer(void)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_AddSourceBufferInternal(char const *, char const *, char *,
                                         int, bool, bool)
{
  UNIMPLEMENTED();
}

char *__cdecl Scr_ReadFile(char const *, char const *, char const *, bool)
{
  UNIMPLEMENTED();
}

void __cdecl RuntimeErrorInternal(enum print_msg_type_t, char const *,
                                  unsigned int, char const *)
{
  UNIMPLEMENTED();
}
