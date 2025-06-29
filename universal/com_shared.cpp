void Com_Memset(void *dest, int val, int count)
{
  return memset(dest, val, count);
}

int __cdecl Com_HashKey(char *string, int maxlen)
{
  char v2; // al
  int v3;  // ecx
  int v4;  // ebx

  if (a2 <= 0)
    return 0;
  v2 = *a1;
  if (!*a1)
    return 0;
  v3 = 0;
  v4 = 0;
    do {
      v4 += (v3 + 119) * v2;
      if (a2 == ++v3)
        break;
      v2 = a1[v3];
    }
  while (v2);
  return (v4 >> 20) ^ (v4 >> 10) ^ v4;
}

int __cdecl Com_RealTime(struct qtime_s *qtime)
{
  time_t result; // eax
  tm *v2;        // eax
  time_t v3;     // [esp+1Ch] [ebp-Ch] BYREF

  result = time(0);
  v3 = result;
    if (a1) {
      v2 = localtime(&v3);
      if (v2)
        *a1 = *(qtime_s *)&v2->tm_sec;
      return v3;
    }
  return result;
}

bool __cdecl Com_Filter(char const *filter, char const *name, int casesensitive)
{
  char v4;                            // al
  int v5;                             // edx
  signed int v6;                      // edi
  signed int v7;                      // ebx
  char v9;                            // al
  int v10;                            // edx
  char v11;                           // al
  const char *v12;                    // edi
  int v13;                            // ebx
  char v14;                           // dl
  int v15;                            // ebx
  int v16;                            // ebx
  int v17;                            // ebx
  int(__cdecl * v18)(char *, char *); // [esp+18h] [ebp-420h]
  const char *v19;                    // [esp+1Ch] [ebp-41Ch]
  char v20[1048];                     // [esp+20h] [ebp-418h] BYREF

    while (1) {
      v4 = *a1;
      if (!*a1)
        return 1;
        switch (v4) {
        case '*':
          v9 = *++a1;
            if (!*a1 || v9 == 42 || v9 == 63) {
              v5 = 0;
            }
            else {
              v5 = 0;
                do {
                  v20[v5] = v9;
                  ++a1;
                  ++v5;
                  v9 = *a1;
                }
              while (*a1 && v9 != 42 && v9 != 63);
            }
          v20[v5] = 0;
            if (v20[0]) {
              if (a3)
                v18 = I_strcmp;
              else
                v18 = I_stricmp;
              v6 = strlen(a2) - strlen(v20);
              if (v6 < 0)
                return 0;
              v7 = 0;
                while (v18(a2, v20)) {
                  ++v7;
                  ++a2;
                  if (v6 < v7)
                    return 0;
                }
              if (!a2)
                return 0;
              a2 += strlen(v20);
            }
          break;
        case '?':
          goto LABEL_7;
        case '[':
            if (*++a1 != 91) {
              v10 = 0;
              v11 = *a1;
                if (!*a1) {
                LABEL_35:
                  if (!v10)
                    return 0;
                  ++a1;
                  goto LABEL_8;
                }
                while (!v10) {
                    if (v11 == 93) {
                      v12 = a1 + 1;
                      if (a1[1] != 93)
                        return 0;
                      if (*v12 != 45)
                        goto LABEL_31;
                    }
                    else {
                      v12 = a1 + 1;
                      if (a1[1] != 45)
                        goto LABEL_31;
                    }
                  v14 = a1[2];
                    if (v14) {
                        if (v14 != 93) {
                          v19 = a1 + 3;
                          if (a3)
                            goto LABEL_49;
                        LABEL_59:
                          v16 = __toupper(*a2);
                            if (v16 >= __toupper(*a1)) {
                              v17 = __toupper(*a2);
                                if (v17 <= __toupper(a1[2])) {
                                  v10 = 1;
                                  goto LABEL_51;
                                }
                            }
                          goto LABEL_50;
                        }
                      v19 = a1 + 3;
                        if (a1[3] == 93) {
                          if (!a3)
                            goto LABEL_59;
                        LABEL_49:
                            if (v11 <= *a2 && v14 >= *a2) {
                              v10 = 1;
                              goto LABEL_51;
                            }
                        LABEL_50:
                          v10 = 0;
                        LABEL_51:
                          a1 = v19;
                          goto LABEL_34;
                        }
                    }
                LABEL_31:
                    if (a3) {
                      if (v11 == *a2)
                        goto LABEL_43;
                    }
                    else {
                      v13 = __toupper(v11);
                        if (v13 == __toupper(*a2)) {
                        LABEL_43:
                          v10 = 1;
                          a1 = v12;
                          goto LABEL_34;
                        }
                    }
                  v10 = 0;
                  a1 = v12;
                LABEL_34:
                  v11 = *a1;
                  if (!*a1)
                    goto LABEL_35;
                }
                while (v11 != 93) {
                  ++a1;
                LABEL_38:
                  v11 = *a1;
                  if (!*a1)
                    goto LABEL_7;
                }
              if (*++a1 == 93)
                goto LABEL_38;
              ++a2;
            }
          break;
        default:
            if (a3) {
              if (v4 != *a2)
                return 0;
            LABEL_7:
              ++a1;
              goto LABEL_8;
            }
          v15 = __toupper(v4);
          if (v15 != __toupper(*a2))
            return 0;
          ++a1;
        LABEL_8:
          ++a2;
          break;
        }
    }
}

bool __cdecl Com_FilterPath(char const *filter, char const *name,
                            int casesensitive)
{
  int v3;      // edx
  char v4;     // al
  int v5;      // edx
  char v6;     // al
  char v8[64]; // [esp+10h] [ebp-88h] BYREF
  char v9[72]; // [esp+50h] [ebp-48h] BYREF

  v3 = 0;
    while (1) {
      v4 = a1[v3];
      if (!v4)
        break;
        if (v4 == 92 || v4 == 58) {
          v9[v3] = 47;
          if (++v3 == 63)
            break;
        }
        else {
          v9[v3] = v4;
          if (++v3 == 63)
            break;
        }
    }
  v9[v3] = 0;
  v5 = 0;
    while (1) {
      v6 = a2[v5];
      if (!v6)
        break;
        if (v6 == 92 || v6 == 58) {
          v8[v5] = 47;
          if (++v5 == 63)
            break;
        }
        else {
          v8[v5] = v6;
          if (++v5 == 63)
            break;
        }
    }
  v8[v5] = 0;
  return (unsigned __int8)Com_Filter(v9, v8, a3);
}

int marker_com_shared;

char const *__cdecl Com_StringContains(char const *, char const *,
                                       int(__cdecl *)(char const *,
                                                      char const *))
{
  UNIMPLEMENTED();
}
