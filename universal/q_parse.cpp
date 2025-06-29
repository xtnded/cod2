int __cdecl Com_Compress(char *data_p)
{
  char *v1; // ecx
  int v2;   // ebx
  char v3;  // dl
  char *v5; // edi
  char v6;  // si
  char *v7; // edx
  char *v8; // [esp+0h] [ebp-10h]

    if (a1) {
      v1 = a1;
      v8 = a1;
      v2 = 0;
      v3 = *a1;
        while (1) {
            while (1) {
            LABEL_3:
                if (!v3) {
                LABEL_4:
                  *v1 = 0;
                  return v2;
                }
              if (v3 != 13 && v3 != 10)
                break;
              *v1++ = v3;
              ++v2;
              v3 = *++v8;
            }
          if (v3 != 47)
            break;
          v5 = v8 + 1;
          v6 = v8[1];
            if (v6 == 47) {
                while (1) {
                  v8 = v5;
                  v3 = *v5;
                  if (!*v5)
                    goto LABEL_4;
                  if (v3 == 10)
                    goto LABEL_3;
                  ++v5;
                }
            }
            if (v6 == 42) {
                while (1) {
                  v7 = v5;
                  if (!v6)
                    break;
                    if (v6 == 42) {
                        if (v8[2] == 47) {
                          v8 = v5 + 2;
                          v3 = v5[2];
                          goto LABEL_3;
                        }
                    }
                    else if (v6 == 10) {
                      *v1++ = 10;
                      ++v2;
                    }
                  v8 = v5++;
                  v6 = v7[1];
                }
              v8 = v5;
              v3 = *v5;
            }
            else {
              ++v8;
            LABEL_10:
              *v1++ = v3;
              ++v2;
              v3 = *v8;
            }
        }
      ++v8;
      goto LABEL_10;
    }
  MEMORY[0] = 0;
  return 0;
}

char const *__cdecl Com_GetLastTokenPos()
{
  return dword_30F124;
}

void __cdecl Com_ParseReturnToMark(char const **, struct com_parse_mark_t *)
{
  char *v2;   // edx
  int result; // eax

  v2 = &g_parse[1116 * dword_30F120];
  *((_DWORD *)v2 + 256) = a2->lines;
  *a1 = *(const char **)a2->text;
  v2[1028] = a2->ungetToken != 0;
  *((_DWORD *)v2 + 261) = a2->backup_lines;
  result = *(_DWORD *)a2->backup_text;
  *((_DWORD *)v2 + 262) = result;
  return result;
}

void __cdecl Com_ParseSetMark(char const **text, struct com_parse_mark_t *mark)
{
  char *v2;   // edx
  int result; // eax

  v2 = &g_parse[1116 * dword_30F120];
  a2->lines = *((_DWORD *)v2 + 256);
  *(_DWORD *)a2->text = *a1;
  a2->ungetToken = (unsigned __int8)v2[1028];
  a2->backup_lines = *((_DWORD *)v2 + 261);
  result = *((_DWORD *)v2 + 262);
  *(_DWORD *)a2->backup_text = result;
  return result;
}

void __cdecl Com_SetScriptWarningPrefix(char const *prefix)
{
  gentity_s *result; // eax

  result = a1;
  *(&off_30AF70 + 279 * dword_30F120) = a1;
  return result;
}

void __cdecl Com_SetScriptErrorPrefix(char const *)
{
  UNIMPLEMENTED();
}

char const *__cdecl Com_ParseRestOfLine(char const **)
{
  UNIMPLEMENTED();
}

int __cdecl Com_GetArgCountOnLine(char const **data_p)
{
  int v1;          // ecx
  char *v2;        // eax
  int v3;          // edi
  int i;           // ebx
  char *v5;        // edx
  char *v6;        // edx
  int v8;          // [esp+0h] [ebp-28h]
  int v9;          // [esp+4h] [ebp-24h]
  int v10;         // [esp+8h] [ebp-20h]
  const char *v11; // [esp+Ch] [ebp-1Ch]

  v1 = dword_30F120;
  v2 = &g_parse[1116 * dword_30F120];
  v3 = *((_DWORD *)v2 + 256);
  v11 = *a1;
  v10 = (unsigned __int8)v2[1028];
  v9 = *((_DWORD *)v2 + 261);
  v8 = *((_DWORD *)v2 + 262);
    for (i = 0;; ++i) {
      v5 = &g_parse[1116 * v1];
      if (!v5[1028])
        break;
      v5[1028] = 0;
        if (v5[1029]) {
          *a1 = (char *)*((_DWORD *)v5 + 262);
          *((_DWORD *)v5 + 256) = *((_DWORD *)v5 + 261);
          break;
        }
      if (!*v5)
        goto LABEL_8;
    LABEL_3:
      v1 = dword_30F120;
    }
  if (*Com_ParseExt(a1, 0))
    goto LABEL_3;
LABEL_8:
  v6 = &g_parse[1116 * dword_30F120];
  *((_DWORD *)v6 + 256) = v3;
  *a1 = (char *)v11;
  v6[1028] = v10 != 0;
  *((_DWORD *)v6 + 261) = v9;
  *((_DWORD *)v6 + 262) = v8;
  return i;
}

int const __cdecl Com_SkipBracedSection(char const **, int)
{
  UNIMPLEMENTED();
}

void __cdecl Com_ScriptError(char const *msg, ...)
{
  char *v1;      // esi
  char v3[4096]; // [esp+2Ch] [ebp-100Ch] BYREF
  va_list v4;    // [esp+102Ch] [ebp-Ch]
  va_list va;    // [esp+1044h] [ebp+Ch] BYREF

  va_start(va, a1);
  v1 = &g_parse[1116 * dword_30F120];
  va_copy(v4, va);
  vsprintf(v3, a1, va);
  if (dword_30F120)
    return Com_Error(1, "\x15%sFile %s, line %i: %s", *((_DWORD *)v1 + 259));
  else
    return Com_Error(1, "\x15%s", (char)v3);
}

void __cdecl Com_Parse3DMatrix(char const **, int, int, int, float *)
{
  UNIMPLEMENTED();
}

int marker_q_parse;

void __cdecl Com_InitParseInfo(struct parseInfo_t *)
{
  UNIMPLEMENTED();
}

struct ParseThreadInfo *__cdecl Com_GetParseThreadInfo(void)
{
  UNIMPLEMENTED();
}

char *__cdecl Com_ParseCSV(char const **, int)
{
  UNIMPLEMENTED();
}

char const *__cdecl SkipWhitespace(char const *, int *)
{
  UNIMPLEMENTED();
}

char *__cdecl Com_ParseExt(char const **, int)
{
  UNIMPLEMENTED();
}
