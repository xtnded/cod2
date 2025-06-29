bool __cdecl Vec2Compare(float const *const, float const *const) {
  UNIMPLEMENTED();
}

bool __cdecl Vec4Compare(float const *const, float const *const) {
  UNIMPLEMENTED();
}

bool __cdecl Byte4Compare(unsigned char const *const,
                          unsigned char const *const) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_ResetScriptInfo() { UNIMPLEMENTED(); }

void __cdecl Dvar_AddFlags(struct dvar_s const *dvar, int flags) {
  int result; // eax

  result = a2 | (unsigned __int16)a1->flags;
  a1->flags = result;
  return result;
}

struct dvar_s const *__cdecl Dvar_RegisterString(char const *dvarName,
                                                 char const *value,
                                                 unsigned short flags) {
  return Dvar_RegisterVariant(a1, 7, a3, a2, 0.0, 0.0);
}

void __cdecl Dvar_SetModified(struct dvar_s const *dvar) {
  const dvar_s *result; // eax

  result = a1;
  a1->modified = 1;
  return result;
}

void __cdecl Dvar_ClearModified(struct dvar_s const *dvar) {
  const dvar_s *result; // eax

  result = a1;
  a1->modified = 0;
  return result;
}

struct dvar_s const *__cdecl Dvar_FindVar(char const *dvarName) {
  char v1;            // al
  int v2;             // eax
  int v3;             // ebx
  unsigned __int8 v5; // si
  int v6;             // ebx
  char v7;            // [esp+8h] [ebp-20h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v7);
  v1 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v1);
      v1 = a1[v6++ - 118];
    } while (v1);
    v2 = v5;
  } else {
    v2 = 0;
  }
  v3 = (int)*(&dvarHashTable + v2);
  if (!v3)
    return 0;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 32);
    if (!v3)
      return 0;
  }
  return v3;
}

char const *__cdecl Dvar_EnumToString(struct dvar_s const *dvar) {
  if (a1->domain.integer.min)
    return *(const gentity_s **)(a1->domain.integer.max +
                                 4 * a1->current.integer);
  else
    return &inData;
}

bool __cdecl Dvar_IsValidName(char const *dvarName) {
  char v1;        // bl
  const char *v2; // esi
  _BOOL4 v3;      // eax

  if (a1) {
    v1 = *a1;
    if (!*a1)
      return 1;
    v2 = a1;
    while (1) {
      v3 = (v1 & 0xFFFFFF80) != 0
               ? __maskrune(v1, 1280) != 0
               : (_DefaultRuneLocale.__runetype[v1] & 0x500) != 0;
      if (!v3 && v1 != 95)
        break;
      v1 = *++v2;
      if (!v1)
        return 1;
    }
  }
  return 0;
}

bool __cdecl Dvar_IsSystemActive() {
  return (unsigned __int8)isDvarSystemActive;
}

void __cdecl Dvar_SetInAutoExec(bool inAutoExec) {
  int result; // eax

  result = a1;
  isLoadingAutoExecGlobalFlag = a1;
  return result;
}

char const *__cdecl Dvar_GetString(char const *dvarName) {
  char v1;            // al
  int v2;             // eax
  int v3;             // ebx
  unsigned __int8 v5; // si
  int v6;             // ebx
  char v7;            // [esp+8h] [ebp-20h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v7);
  v1 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v1);
      v1 = a1[v6++ - 118];
    } while (v1);
    v2 = v5;
  } else {
    v2 = 0;
  }
  v3 = (int)*(&dvarHashTable + v2);
  if (!v3)
    return &inData;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 32);
    if (!v3)
      return &inData;
  }
  if (*(_BYTE *)(v3 + 6) != 6)
    return *(const gentity_s **)(v3 + 8);
  if (!*(_DWORD *)(v3 + 20))
    return &inData;
  return *(const gentity_s **)(*(_DWORD *)(v3 + 24) + 4 * *(_DWORD *)(v3 + 8));
}

float __cdecl Dvar_GetFloat(char const *dvarName) {
  char v1;            // al
  int v2;             // eax
  int v3;             // ebx
  unsigned __int8 v5; // si
  int v6;             // ebx
  char v8;            // [esp+8h] [ebp-40h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v8);
  v1 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v1);
      v1 = a1[v6++ - 118];
    } while (v1);
    v2 = v5;
  } else {
    v2 = 0;
  }
  v3 = (int)*(&dvarHashTable + v2);
  if (!v3)
    return 0.0;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 32);
    if (!v3)
      return 0.0;
  }
  if (*(_BYTE *)(v3 + 6) == 1)
    return *(float *)(v3 + 8);
  return (float)atof((const char *)*(_DWORD *)(v3 + 8));
}

int __cdecl Dvar_GetInt(char const *dvarName) {
  char v1;            // al
  int v2;             // eax
  int v3;             // ebx
  unsigned __int8 v5; // di
  int v6;             // ebx
  char v7;            // [esp+8h] [ebp-20h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v7);
  v1 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v1);
      v1 = a1[v6++ - 118];
    } while (v1);
    v2 = v5;
  } else {
    v2 = 0;
  }
  v3 = (int)*(&dvarHashTable + v2);
  if (!v3)
    return 0;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 32);
    if (!v3)
      return 0;
  }
  if ((unsigned __int8)(*(_BYTE *)(v3 + 6) - 5) <= 1u)
    return *(_DWORD *)(v3 + 8);
  else
    return atoi(*(const char **)(v3 + 8));
}

bool __cdecl Dvar_GetBool(char const *dvarName) {
  char v1;            // al
  int v2;             // eax
  int v3;             // ebx
  unsigned __int8 v5; // si
  int v6;             // ebx
  char v7;            // [esp+8h] [ebp-20h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v7);
  v1 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v1);
      v1 = a1[v6++ - 118];
    } while (v1);
    v2 = v5;
  } else {
    v2 = 0;
  }
  v3 = (int)*(&dvarHashTable + v2);
  if (!v3)
    return 0;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 32);
    if (!v3)
      return 0;
  }
  if (*(_BYTE *)(v3 + 6))
    return atoi(*(const char **)(v3 + 8)) != 0;
  else
    return *(unsigned __int8 *)(v3 + 8);
}

char const *__cdecl Dvar_IndexStringToEnumString(struct dvar_s const *dvar,
                                                 char const *indexString) {
  unsigned int v3; // kr04_4
  int v4;          // edx
  unsigned int v5; // eax

  if (!a1->domain.integer.min)
    return &inData;
  v3 = strlen(a2) + 1;
  if ((int)(v3 - 1) > 0) {
    v4 = 0;
    while (1) {
      v5 = a2[v4];
      if (v5 > 0xFF || (_DefaultRuneLocale.__runetype[v5] & 0x400) == 0)
        break;
      if (v3 - 1 == ++v4)
        return *(const gentity_s **)(a1->domain.integer.max + 4 * atoi(a2));
    }
    return &inData;
  }
  return *(const gentity_s **)(a1->domain.integer.max + 4 * atoi(a2));
}

char const *__cdecl Dvar_GetVariantString(char const *dvarName) {
  char v1;            // al
  int v2;             // eax
  int v3;             // ebx
  unsigned __int8 v5; // di
  int v6;             // ebx
  char v7;            // [esp+8h] [ebp-20h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v7);
  v1 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v1);
      v1 = a1[v6++ - 118];
    } while (v1);
    v2 = v5;
  } else {
    v2 = 0;
  }
  v3 = (int)*(&dvarHashTable + v2);
  if (!v3)
    return &inData;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 32);
    if (!v3)
      return &inData;
  }
  return (const gentity_s *)Dvar_ValueToString(v3, *(float **)(v3 + 8));
}

float const *__cdecl Dvar_GetFloat4(char const *) { UNIMPLEMENTED(); }

float const *__cdecl Dvar_GetFloat3(char const *) { UNIMPLEMENTED(); }

float const *__cdecl Dvar_GetFloat2(char const *) { UNIMPLEMENTED(); }

void __cdecl Dvar_UpdateEnumDomain(struct dvar_s const *dvar,
                                   char const **const stringTable) {
  int32_t v2;        // eax
  DvarLimits domain; // kr00_8
  float *integer;    // ebx
  int32_t min;       // edi
  float v6;          // xmm1_4
  int v7;            // edx
  float v8;          // xmm0_4
  float v9;          // xmm1_4
  int v10;           // edx
  float v11;         // xmm0_4
  float v12;         // xmm1_4
  int v13;           // edx
  float v14;         // xmm0_4

  if (*a2) {
    v2 = 0;
    do
      ++v2;
    while (a2[v2]);
  } else {
    v2 = 0;
  }
  a1->domain.integer.min = v2;
  a1->domain.integer.max = (int32_t)a2;
  domain = a1->domain;
  integer = (float *)a1->current.integer;
  min = (int32_t)integer;
  LOBYTE(v2) = a1->type;
  switch ((char)v2) {
  case 0:
    v2 = a1->current.integer;
    LOBYTE(v2) = (_BYTE)integer != 0;
    min = v2;
    break;
  case 1:
    if (*(float *)&domain.integer.min > *(float *)&integer) {
      min = a1->domain.integer.min;
    } else if (*(float *)&integer > *(float *)&domain.integer.max) {
      min = a1->domain.integer.max;
    }
    break;
  case 2:
    v12 = *(float *)&a1->domain.integer.min;
    v13 = 1;
    v2 = (int32_t)(integer + 1);
    do {
      v14 = *(float *)(v2 - 4);
      if (v12 <= v14) {
        if (v14 > *(float *)&domain.integer.max)
          *(_DWORD *)(v2 - 4) = domain.integer.max;
      } else {
        *(float *)(v2 - 4) = v12;
      }
      ++v13;
      v2 += 4;
    } while (v13 != 3);
    break;
  case 3:
    v9 = *(float *)&a1->domain.integer.min;
    v10 = 1;
    v2 = (int32_t)(integer + 1);
    v11 = *integer;
    if (v9 <= *integer)
      goto LABEL_23;
  LABEL_20:
    *(float *)(v2 - 4) = v9;
    while (1) {
      ++v10;
      v2 += 4;
      if (v10 == 4)
        break;
      v11 = *(float *)(v2 - 4);
      if (v9 > v11)
        goto LABEL_20;
    LABEL_23:
      if (v11 > *(float *)&domain.integer.max)
        *(_DWORD *)(v2 - 4) = domain.integer.max;
    }
    break;
  case 4:
    v6 = *(float *)&a1->domain.integer.min;
    v7 = 1;
    v2 = (int32_t)(integer + 1);
    v8 = *integer;
    if (v6 <= *integer)
      goto LABEL_17;
  LABEL_14:
    *(float *)(v2 - 4) = v6;
    while (1) {
      ++v7;
      v2 += 4;
      if (v7 == 5)
        break;
      v8 = *(float *)(v2 - 4);
      if (v6 > v8)
        goto LABEL_14;
    LABEL_17:
      if (v8 > *(float *)&domain.integer.max)
        *(_DWORD *)(v2 - 4) = domain.integer.max;
    }
    break;
  case 5:
    if ((int)integer < domain.integer.min) {
      min = a1->domain.integer.min;
    } else if ((int)integer > domain.integer.max) {
      min = a1->domain.integer.max;
    }
    break;
  case 6:
    if ((int)integer < 0 || (int)integer >= domain.integer.min)
      min = a1->reset;
    break;
  default:
    break;
  }
  a1->current.integer = min;
  a1->latched = min;
  return v2;
}

bool __cdecl Dvar_IsAtDefaultValue(struct dvar_s const *dvar) {
  return Dvar_ValuesEqual(a1->type, *(float *)&a1->current.integer,
                          *(float *)&a1->reset);
}

bool __cdecl Dvar_HasLatchedValue(struct dvar_s const *dvar) {
  return !Dvar_ValuesEqual(a1->type, *(float *)&a1->current.integer,
                           *(float *)&a1->latched);
}

char const *__cdecl Dvar_DomainToString_GetLines(unsigned char type,
                                                 union DvarLimits domain,
                                                 char *outBuffer,
                                                 int outBufferLen,
                                                 int *outLineCount) {
  return Dvar_DomainToString_Internal(a1, *(float *)&a2.integer.min,
                                      *(float *)&a2.integer.max, a3, a4);
}

char const *__cdecl Dvar_DomainToString(unsigned char, union DvarLimits, char *,
                                        int) {
  UNIMPLEMENTED();
}

char const *__cdecl Dvar_DisplayableLatchedValue(struct dvar_s const *dvar) {
  return Dvar_ValueToString((int)a1, (float *)a1->latched);
}

char const *__cdecl Dvar_DisplayableResetValue(struct dvar_s const *dvar) {
  return Dvar_ValueToString((int)a1, (float *)a1->reset);
}

char const *__cdecl Dvar_DisplayableValue(struct dvar_s const *dvar) {
  return Dvar_ValueToString((int)a1, (float *)a1->current.integer);
}

int __cdecl Com_SaveDvarsToBuffer(char const **const dvarnames, int numDvars,
                                  char *buffer, int bufsize) {
  UNIMPLEMENTED();
}

int __cdecl Dvar_SerializeDvars(char *, unsigned int) { UNIMPLEMENTED(); }

bool __cdecl Dvar_AnyLatchedValues() {
  int v0; // ebx

  v0 = sortedDvars;
  if (!sortedDvars)
    return 0;
  while (Dvar_ValuesEqual(*(_BYTE *)(v0 + 6), *(float *)(v0 + 8),
                          *(float *)(v0 + 12))) {
    v0 = *(_DWORD *)(v0 + 28);
    if (!v0)
      return 0;
  }
  return 1;
}

void __cdecl Dvar_Shutdown() { UNIMPLEMENTED(); }

void __cdecl Dvar_PrintDomain(unsigned char type, union DvarLimits domain) {
  char *v2;         // eax
  char __str[1032]; // [esp+10h] [ebp-408h] BYREF

  v2 = Dvar_DomainToString_Internal(a1, *(float *)&a2.integer.min,
                                    *(float *)&a2.integer.max, __str,
                                    (DvarLimits)1024LL);
  Com_Printf(stru_2182FC.name, v2);
}

void __cdecl Dvar_GetUnpackedColor(struct dvar_s const *dvar,
                                   float *const expandedColor) {
  int result;        // eax
  DvarValue current; // [esp+Ch] [ebp-Ch] BYREF

  if (a1->type == 8)
    current = a1->current;
  else
    Dvar_StringToColor((const char *)a1->current.integer, &current);
  *a2 = (float)(unsigned __int8)current.enabled * 0.0039215689;
  a2[1] = (float)(unsigned __int8)current.string[1] * 0.0039215689;
  a2[2] = (float)(unsigned __int8)current.string[2] * 0.0039215689;
  result = (unsigned __int8)current.string[3];
  a2[3] = (float)(unsigned __int8)current.string[3] * 0.0039215689;
  return result;
}

void __cdecl Dvar_GetUnpackedColorByName(char const *dvarName,
                                         float *const expandedColor) {
  char v2;            // al
  int v3;             // eax
  int v4;             // ebx
  int result;         // eax
  unsigned __int8 v6; // si
  int v7;             // ebx
  char v8;            // [esp+8h] [ebp-30h]
  int v9;             // [esp+1Ch] [ebp-1Ch] BYREF

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v8);
  v2 = *a1;
  if (*a1) {
    v6 = 0;
    v7 = 119;
    do {
      v6 += v7 * __tolower(v2);
      v2 = a1[v7++ - 118];
    } while (v2);
    v3 = v6;
  } else {
    v3 = 0;
  }
  v4 = (int)*(&dvarHashTable + v3);
  if (v4) {
    while (I_stricmp(a1, *(char **)v4)) {
      v4 = *(_DWORD *)(v4 + 32);
      if (!v4)
        goto LABEL_8;
    }
    if (*(_BYTE *)(v4 + 6) == 8)
      v9 = *(_DWORD *)(v4 + 8);
    else
      Dvar_StringToColor(*(const char **)(v4 + 8), &v9);
    *a2 = (float)(unsigned __int8)v9 * 0.0039215689;
    a2[1] = (float)BYTE1(v9) * 0.0039215689;
    a2[2] = (float)BYTE2(v9) * 0.0039215689;
    result = HIBYTE(v9);
    a2[3] = (float)HIBYTE(v9) * 0.0039215689;
  } else {
  LABEL_8:
    *a2 = colorWhite[0];
    a2[1] = colorWhite[1];
    a2[2] = colorWhite[2];
    result = LODWORD(colorWhite[3]);
    *((_DWORD *)a2 + 3) = result;
  }
  return result;
}

void __cdecl Dvar_ClearLatchedValue(struct dvar_s const *) { UNIMPLEMENTED(); }

void __cdecl Dvar_ChangeResetValue(struct dvar_s const *dvar,
                                   union DvarValue value) {
  Dvar_UpdateResetValue((int)a1, a2.integer);
}

void __cdecl Dvar_Unregister(struct dvar_s const *, int) { UNIMPLEMENTED(); }

void __cdecl Dvar_SetCheatState() {
  int i; // ebx

  for (i = sortedDvars; i; i = *(_DWORD *)(i + 28)) {
    while (*(char *)(i + 4) >= 0) {
      i = *(_DWORD *)(i + 28);
      if (!i)
        return;
    }
    Dvar_SetVariant((const char **)i, *(float *)(i + 16), 0);
  }
}

void __cdecl Dvar_Reset(struct dvar_s const *dvar,
                        enum DvarSetSource setSource) {
  Dvar_SetVariant((const char **)a1, *(float *)&a1->reset, a2);
}

void __cdecl Dvar_SetColorFromSource(struct dvar_s const *dvar, float r,
                                     float g, float b, float a,
                                     enum DvarSetSource source) {
  int v6;           // ebx
  float v7;         // xmm1_4
  float v8;         // xmm3_4
  float v9;         // xmm0_4
  float v10;        // xmm0_4
  float v11;        // xmm0_4
  float v12;        // xmm0_4
  float v13;        // xmm0_4
  unsigned int v14; // ebx
  float v15;        // xmm0_4
  float v16;        // xmm0_4
  float v17;        // [esp+50h] [ebp-98h]
  float v18;        // [esp+54h] [ebp-94h]
  float v19;        // [esp+58h] [ebp-90h]
  float v20;        // [esp+5Ch] [ebp-8Ch]
  char __str[136];  // [esp+60h] [ebp-88h] BYREF

  HIWORD(v6) = 0;
  v7 = a2;
  v8 = a3;
  if (a1->type != 8) {
    Com_sprintf(__str, 0x80u, "%g %g %g %g", a2, a3, a4, a5);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), a6);
    return;
  }
  if ((float)(a2 - 1.0) < 0.0) {
    if ((float)(0.0 - a2) >= 0.0)
      goto LABEL_5;
  LABEL_20:
    v9 = v7 * 255.0;
    goto LABEL_6;
  }
  v7 = 1.0;
  if (0.0 > -1.0)
    goto LABEL_20;
LABEL_5:
  v9 = 0.0;
LABEL_6:
  v20 = floorf(v9 + 0.5);
  if ((float)(a3 - 1.0) < 0.0) {
    v10 = 0.0 - a3;
  } else {
    v8 = 1.0;
    v10 = -1.0;
  }
  if (v10 < 0.0)
    v11 = v8 * 255.0;
  else
    v11 = 0.0;
  v19 = floorf(v11 + 0.5);
  if ((float)(a4 - 1.0) < 0.0) {
    v12 = 0.0 - a4;
  } else {
    a4 = 1.0;
    v12 = -1.0;
  }
  if (v12 < 0.0)
    v13 = a4 * 255.0;
  else
    v13 = 0.0;
  v18 = floorf(v13 + 0.5);
  LOBYTE(v6) = (int)v20;
  BYTE1(v6) = (int)v19;
  v14 = ((unsigned __int8)(int)v18 << 16) | v6 & 0xFF00FFFF;
  if ((float)(a5 - 1.0) < 0.0) {
    v15 = 0.0 - a5;
  } else {
    a5 = 1.0;
    v15 = -1.0;
  }
  if (v15 < 0.0)
    v16 = a5 * 255.0;
  else
    v16 = 0.0;
  v17 = floorf(v16 + 0.5);
  Dvar_SetVariant((const char **)a1,
                  COERCE_FLOAT(((int)v17 << 24) | v14 & 0xFFFFFF), a6);
}

void __cdecl Dvar_SetVec4FromSource(struct dvar_s const *, float, float, float,
                                    float, enum DvarSetSource) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_SetVec3FromSource(struct dvar_s const *, float, float, float,
                                    enum DvarSetSource) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_SetVec2FromSource(struct dvar_s const *, float, float,
                                    enum DvarSetSource) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_SetFloatFromSource(struct dvar_s const *dvar, float value,
                                     enum DvarSetSource source) {
  char __str[40]; // [esp+30h] [ebp-28h] BYREF

  if (a1->type == 1) {
    Dvar_SetVariant((const char **)a1, a2, a3);
  } else {
    Com_sprintf(__str, 0x20u, "%g", a2);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), a3);
  }
}

void __cdecl Dvar_SetIntFromSource(struct dvar_s const *dvar, int value,
                                   enum DvarSetSource source) {
  char __str[40]; // [esp+10h] [ebp-28h] BYREF

  if ((unsigned __int8)(a1->type - 5) <= 1u) {
    Dvar_SetVariant((const char **)a1, *(float *)&a2, a3);
  } else {
    Com_sprintf(__str, 0x20u, "%i", a2);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), a3);
  }
}

void __cdecl Dvar_SetBoolFromSource(struct dvar_s const *dvar, bool value,
                                    enum DvarSetSource source) {
  float v3;       // edx
  const char *v4; // edx

  v3 = 0.0;
  if (a1->type) {
    v4 = "1";
    if (!a2)
      v4 = "0";
    Dvar_SetVariant((const char **)a1, *(float *)&v4, a3);
  } else {
    LOBYTE(v3) = a2;
    Dvar_SetVariant((const char **)a1, v3, a3);
  }
}

void __cdecl Dvar_MakeLatchedValueCurrent(struct dvar_s const *) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_UnregisterSystem(int sysFlag) {
  int i;      // ebx
  int v2;     // eax
  __int16 v3; // ax

  for (i = sortedDvars; i; i = *(_DWORD *)(i + 28)) {
    v2 = *(unsigned __int16 *)(i + 4);
    if ((a1 & v2) != 0 && (v2 & 0x4000) == 0) {
      v3 = *(_WORD *)(i + 4) & ~(_WORD)a1;
      *(_WORD *)(i + 4) = v3;
      if ((v3 & 0x7000) == 0)
        Dvar_PerformUnregistration(i);
    }
  }
}

void __cdecl Dvar_ResetDvars(unsigned int filter,
                             enum DvarSetSource setSource) {
  int i; // ebx

  for (i = sortedDvars; i; i = *(_DWORD *)(i + 28)) {
    while ((a1 & *(_WORD *)(i + 4)) == 0) {
      i = *(_DWORD *)(i + 28);
      if (!i)
        return;
    }
    Dvar_SetVariant((const char **)i, *(float *)(i + 16), a2);
  }
}

struct dvar_s const *__cdecl Dvar_SetFromStringByNameFromSource(
    char const *dvarName, char const *string, enum DvarSetSource source) {
  char v3;            // al
  int v4;             // eax
  int v5;             // ebx
  unsigned __int8 v7; // si
  int v8;             // ebx
  char v9;            // [esp+8h] [ebp-30h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v9);
  v3 = a1->name[0];
  if (a1->name[0]) {
    v7 = 0;
    v8 = 119;
    do {
      v7 += v8 * __tolower(v3);
      v3 = *((_BYTE *)&a1[-3] + v8++ - 10);
    } while (v3);
    v4 = v7;
  } else {
    v4 = 0;
  }
  v5 = (int)*(&dvarHashTable + v4);
  if (v5) {
    while (I_stricmp(a1->name, *(char **)v5)) {
      v5 = *(_DWORD *)(v5 + 32);
      if (!v5)
        goto LABEL_8;
    }
  } else {
  LABEL_8:
    v5 = 0;
  }
  if (!v5)
    return Dvar_RegisterVariant(a1->name, 7, 0x4000u, a2, 0.0, 0.0);
  Dvar_SetFromStringFromSource(v5, (char *)a2.integer, a3);
  return (dvar_s *)v5;
}

void __cdecl Dvar_SetFromString(struct dvar_s const *dvar, char const *string) {
  Dvar_SetFromStringFromSource((int)a1, a2, 0);
}

void __cdecl Dvar_SetColor(struct dvar_s const *dvar, float r, float g, float b,
                           float a) {
  Dvar_SetColorFromSource(a1, a2, a3, a4, a5, DVAR_SOURCE_INTERNAL);
}

void __cdecl Dvar_SetString(struct dvar_s const *dvar, char const *value) {
  int32_t min;          // esi
  char v3;              // cl
  int v4;               // ebx
  unsigned int v5;      // kr04_4
  char *v6;             // edi
  DvarLimits *v7;       // edx
  DvarLimits *p_domain; // [esp+1Ch] [ebp-41Ch]
  char __dst[1048];     // [esp+20h] [ebp-418h] BYREF

  if (a1->type != 7) {
    p_domain = &a1->domain;
    min = a1->domain.integer.min;
    if (min > 0) {
      v4 = 0;
      v7 = &a1->domain;
      while (stricmp(__src, *(const char **)(v7->integer.max + 4 * v4))) {
        ++v4;
        v7 = &a1->domain;
        min = p_domain->integer.min;
        if (v4 >= p_domain->integer.min)
          goto LABEL_3;
      }
      goto LABEL_8;
    }
  LABEL_3:
    v3 = *__src;
    if (*__src) {
      if ((unsigned __int8)(v3 - 48) > 9u) {
      LABEL_7:
        v4 = -1337;
        goto LABEL_8;
      }
      v6 = __src;
      v4 = 0;
      while (1) {
        v4 = v3 + 10 * v4 - 48;
        v3 = v6[1];
        if (!v3)
          break;
        ++v6;
        if ((unsigned __int8)(v3 - 48) > 9u) {
          v4 = -1337;
          goto LABEL_8;
        }
      }
      if (v4 < 0) {
      LABEL_6:
        v5 = strlen(__src) + 1;
        if (p_domain->integer.min > 0) {
          v4 = 0;
          while (strnicmp(__src,
                          *(const char **)(a1->domain.integer.max + 4 * v4),
                          v5 - 1)) {
            if (++v4 >= p_domain->integer.min) {
              v4 = -1337;
              goto LABEL_8;
            }
          }
          goto LABEL_8;
        }
        goto LABEL_7;
      }
    } else {
      v4 = 0;
    }
    if (min > v4) {
    LABEL_8:
      Dvar_SetVariant((const char **)a1, *(float *)&v4, 0);
      return;
    }
    goto LABEL_6;
  }
  I_strncpyz(__dst, __src, 1024);
  Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__dst), 0);
}

void __cdecl Dvar_SetVec4(struct dvar_s const *dvar, float x, float y, float z,
                          float w) {
  char __str[128]; // [esp+30h] [ebp-98h] BYREF
  _DWORD v6[6];    // [esp+B0h] [ebp-18h] BYREF

  if (a1->type == 4) {
    *(float *)v6 = a2;
    *(float *)&v6[1] = a3;
    *(float *)&v6[2] = a4;
    *(float *)&v6[3] = a5;
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(v6), 0);
  } else {
    Com_sprintf(__str, 0x80u, "%g %g %g %g", a2, a3, a4, a5);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), 0);
  }
}

void __cdecl Dvar_SetVec3(struct dvar_s const *dvar, float x, float y,
                          float z) {
  char __str[96]; // [esp+34h] [ebp-74h] BYREF
  _DWORD v5[5];   // [esp+94h] [ebp-14h] BYREF

  if (a1->type == 3) {
    *(float *)v5 = a2;
    *(float *)&v5[1] = a3;
    *(float *)&v5[2] = a4;
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(v5), 0);
  } else {
    Com_sprintf(__str, 0x60u, "%g %g %g", a2, a3, a4);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), 0);
  }
}

void __cdecl Dvar_SetVec2(struct dvar_s const *dvar, float x, float y) {
  char __str[64]; // [esp+28h] [ebp-50h] BYREF
  _DWORD v4[4];   // [esp+68h] [ebp-10h] BYREF

  if (a1->type == 4) {
    *(float *)v4 = a2;
    *(float *)&v4[1] = a3;
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(v4), 0);
  } else {
    Com_sprintf(__str, 0x40u, "%g %g", a2, a3);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), 0);
  }
}

void __cdecl Dvar_SetFloat(struct dvar_s const *dvar, float value) {
  char __str[40]; // [esp+30h] [ebp-28h] BYREF

  if (a1->type == 1) {
    Dvar_SetVariant((const char **)a1, a2, 0);
  } else {
    Com_sprintf(__str, 0x20u, "%g", a2);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), 0);
  }
}

void __cdecl Dvar_SetInt(struct dvar_s const *dvar, int value) {
  char __str[40]; // [esp+10h] [ebp-28h] BYREF

  if ((unsigned __int8)(a1->type - 5) <= 1u) {
    Dvar_SetVariant((const char **)a1, *(float *)&a2, 0);
  } else {
    Com_sprintf(__str, 0x20u, "%i", a2);
    Dvar_SetVariant((const char **)a1, COERCE_FLOAT(__str), 0);
  }
}

void __cdecl Dvar_SetBool(struct dvar_s const *dvar, bool value) {
  float v2;       // edx
  const char *v3; // edx

  v2 = 0.0;
  if (a1->type) {
    v3 = "1";
    if (!a2)
      v3 = "0";
    Dvar_SetVariant((const char **)a1, *(float *)&v3, 0);
  } else {
    LOBYTE(v2) = a2;
    Dvar_SetVariant((const char **)a1, v2, 0);
  }
}

void __cdecl Dvar_SetCommand(char const *dvarName, char const *string) {
  dvar_s *v2; // eax

  v2 = Dvar_SetFromStringByNameFromSource(a1, a2, DVAR_SOURCE_EXTERNAL);
  if (v2) {
    if (isLoadingAutoExecGlobalFlag) {
      v2->flags |= 0x8000u;
      Dvar_UpdateResetValue((int)v2, v2->current.integer);
    }
  }
}

void __cdecl Dvar_SetFromStringByName(char const *dvarName,
                                      char const *string) {
  return Dvar_SetFromStringByNameFromSource(a1, a2, DVAR_SOURCE_INTERNAL);
}

void __cdecl Dvar_SetColorByName(char const *dvarName, unsigned char r,
                                 unsigned char g, unsigned char b,
                                 unsigned char a) {
  char v12;    // al
  int v13;     // eax
  dvar_s *v14; // ebx
  char *v15;   // eax
  int v16;     // esi
  int v17;     // ebx
  double v18;  // [esp+4h] [ebp-54h]
  double v19;  // [esp+Ch] [ebp-4Ch]
  double v20;  // [esp+14h] [ebp-44h]
  double v21;  // [esp+1Ch] [ebp-3Ch]

  if (!a8)
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
              "\x15null name in generateHashValue");
  v12 = *a8;
  if (*a8) {
    v16 = 0;
    v17 = 119;
    do {
      v16 += v17 * __tolower(v12);
      v12 = a8[v17++ - 118];
    } while (v12);
    v13 = (unsigned __int8)v16;
  } else {
    v13 = 0;
  }
  v14 = *(&dvarHashTable + v13);
  if (v14) {
    while (I_stricmp(a8, *(char **)v14->name)) {
      v14 = (dvar_s *)v14->hashNext;
      if (!v14)
        goto LABEL_8;
    }
    Dvar_SetColorFromSource(v14, (float)a9, (float)a10, (float)a11, (float)a12,
                            DVAR_SOURCE_INTERNAL);
  } else {
  LABEL_8:
    HIDWORD(v19) = a12;
    LODWORD(v19) = a11;
    HIDWORD(v18) = a10;
    LODWORD(v18) = a9;
    v15 = va("%g %g %g %g", v18, v19, v20, v21);
    Dvar_RegisterVariant(a8, 7, 0x4000u, (DvarValue)v15, 0.0, 0.0);
  }
}

void __cdecl Dvar_SetStringByName(char const *dvarName, char const *value) {
  char v2;                 // al
  int v3;                  // eax
  int v4;                  // esi
  unsigned __int8 v5;      // si
  int v6;                  // ebx
  char v7;                 // cl
  int v8;                  // ebx
  unsigned int v9;         // kr04_4
  char *v10;               // edx
  char *v11;               // edi
  char v12;                // [esp+8h] [ebp-430h]
  int *v13;                // [esp+18h] [ebp-420h]
  int v14;                 // [esp+1Ch] [ebp-41Ch]
  char __dst[4];           // [esp+20h] [ebp-418h] BYREF
  unsigned __int16 v16[2]; // [esp+24h] [ebp-414h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v12);
  v2 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v2);
      v2 = a1[v6++ - 118];
    } while (v2);
    v3 = v5;
  } else {
    v3 = 0;
  }
  v4 = (int)*(&dvarHashTable + v3);
  if (!v4) {
  LABEL_8:
    *(_DWORD *)__dst = 0;
    *(_DWORD *)v16 = 0;
    Dvar_RegisterVariant(a1, 7, 0x4000u, (DvarValue)__src, 0.0, 0.0);
    return;
  }
  while (I_stricmp(a1, *(char **)v4)) {
    v4 = *(_DWORD *)(v4 + 32);
    if (!v4)
      goto LABEL_8;
  }
  if (*(_BYTE *)(v4 + 6) == 7) {
    I_strncpyz(__dst, __src, 1024);
    v10 = __dst;
    goto LABEL_23;
  }
  v13 = (int *)(v4 + 20);
  v14 = *(_DWORD *)(v4 + 20);
  if (v14 > 0) {
    v8 = 0;
    while (stricmp(__src, *(const char **)(*(_DWORD *)(v4 + 24) + 4 * v8))) {
      ++v8;
      v14 = *v13;
      if (v8 >= *v13)
        goto LABEL_14;
    }
    goto LABEL_22;
  }
LABEL_14:
  v7 = *__src;
  if (*__src) {
    if ((unsigned __int8)(v7 - 48) > 9u) {
    LABEL_21:
      v8 = -1337;
      goto LABEL_22;
    }
    v11 = __src;
    v8 = 0;
    while (1) {
      v8 = v7 + 10 * v8 - 48;
      v7 = v11[1];
      if (!v7)
        break;
      ++v11;
      if ((unsigned __int8)(v7 - 48) > 9u) {
        v8 = -1337;
        goto LABEL_22;
      }
    }
    if (v8 < 0) {
    LABEL_17:
      v9 = strlen(__src) + 1;
      if (*v13 > 0) {
        v8 = 0;
        while (strnicmp(__src, *(const char **)(*(_DWORD *)(v4 + 24) + 4 * v8),
                        v9 - 1)) {
          if (++v8 >= *v13)
            goto LABEL_21;
        }
        goto LABEL_22;
      }
      goto LABEL_21;
    }
  } else {
    v8 = 0;
  }
  if (v14 <= v8)
    goto LABEL_17;
LABEL_22:
  v10 = (char *)v8;
LABEL_23:
  Dvar_SetVariant((const char **)v4, *(float *)&v10, 0);
}

void __cdecl Dvar_SetVec4ByName(char const *dvarName, float x, float y, float z,
                                float w) {
  char v12;                // al
  int v13;                 // eax
  int v14;                 // esi
  char *v15;               // eax
  unsigned __int8 v16;     // si
  int v17;                 // ebx
  void *v18;               // edx
  char __str[128];         // [esp+30h] [ebp-A8h] BYREF
  DvarSetSource v20;       // [esp+B0h] [ebp-28h] BYREF
  unsigned __int16 v21[2]; // [esp+B4h] [ebp-24h]
  float v22;               // [esp+B8h] [ebp-20h]
  float v23;               // [esp+BCh] [ebp-1Ch]

  if (!a8)
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
              "\x15null name in generateHashValue");
  v12 = a8->name[0];
  if (a8->name[0]) {
    v16 = 0;
    v17 = 119;
    do {
      v16 += v17 * __tolower(v12);
      v12 = *((_BYTE *)&a8[-3] + v17++ - 10);
    } while (v12);
    v13 = v16;
  } else {
    v13 = 0;
  }
  v14 = (int)*(&dvarHashTable + v13);
  if (v14) {
    while (I_stricmp(a8->name, *(char **)v14)) {
      v14 = *(_DWORD *)(v14 + 32);
      if (!v14)
        goto LABEL_8;
    }
    if (*(_BYTE *)(v14 + 6) == 4) {
      v20 = LODWORD(a9);
      *(float *)v21 = a10;
      v22 = a11;
      v23 = a12;
      v18 = &v20;
    } else {
      Com_sprintf(__str, 0x80u, "%g %g %g %g", a9, a10, a11, a12);
      v18 = __str;
    }
    Dvar_SetVariant((const char **)v14, *(float *)&v18, 0);
  } else {
  LABEL_8:
    v15 = va("%g %g %g %g", a9, a10, a11, a12);
    v20 = DVAR_SOURCE_INTERNAL;
    *(_DWORD *)v21 = 0;
    Dvar_RegisterVariant(a8->name, 7, 0x4000u, (DvarValue)v15, 0.0, 0.0);
  }
}

void __cdecl Dvar_SetVec3ByName(char const *dvarName, float x, float y,
                                float z) {
  char v11;                // al
  int v12;                 // eax
  int v13;                 // esi
  char *v14;               // eax
  unsigned __int8 v15;     // si
  int v16;                 // ebx
  void *v17;               // edx
  char __str[96];          // [esp+34h] [ebp-84h] BYREF
  DvarSetSource v19;       // [esp+94h] [ebp-24h] BYREF
  unsigned __int16 v20[2]; // [esp+98h] [ebp-20h]
  float v21;               // [esp+9Ch] [ebp-1Ch]

  if (!a8)
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
              "\x15null name in generateHashValue");
  v11 = a8->name[0];
  if (a8->name[0]) {
    v15 = 0;
    v16 = 119;
    do {
      v15 += v16 * __tolower(v11);
      v11 = *((_BYTE *)&a8[-3] + v16++ - 10);
    } while (v11);
    v12 = v15;
  } else {
    v12 = 0;
  }
  v13 = (int)*(&dvarHashTable + v12);
  if (v13) {
    while (I_stricmp(a8->name, *(char **)v13)) {
      v13 = *(_DWORD *)(v13 + 32);
      if (!v13)
        goto LABEL_8;
    }
    if (*(_BYTE *)(v13 + 6) == 3) {
      v19 = LODWORD(a9);
      *(float *)v20 = a10;
      v21 = a11;
      v17 = &v19;
    } else {
      Com_sprintf(__str, 0x60u, "%g %g %g", a9, a10, a11);
      v17 = __str;
    }
    Dvar_SetVariant((const char **)v13, *(float *)&v17, 0);
  } else {
  LABEL_8:
    v14 = va("%g %g %g", a9, a10, a11);
    v19 = DVAR_SOURCE_INTERNAL;
    *(_DWORD *)v20 = 0;
    Dvar_RegisterVariant(a8->name, 7, 0x4000u, (DvarValue)v14, 0.0, 0.0);
  }
}

void __cdecl Dvar_SetVec2ByName(char const *dvarName, float x, float y) {
  char v10;                // al
  int v11;                 // eax
  int v12;                 // esi
  char *v13;               // eax
  unsigned __int8 v14;     // si
  int v15;                 // ebx
  void *v16;               // edx
  char __str[64];          // [esp+28h] [ebp-60h] BYREF
  DvarSetSource v18;       // [esp+68h] [ebp-20h] BYREF
  unsigned __int16 v19[2]; // [esp+6Ch] [ebp-1Ch]

  if (!a8)
    Com_Error(a1, a2, a3, a4, a5, a6, a7, 1,
              "\x15null name in generateHashValue");
  v10 = a8->name[0];
  if (a8->name[0]) {
    v14 = 0;
    v15 = 119;
    do {
      v14 += v15 * __tolower(v10);
      v10 = *((_BYTE *)&a8[-3] + v15++ - 10);
    } while (v10);
    v11 = v14;
  } else {
    v11 = 0;
  }
  v12 = (int)*(&dvarHashTable + v11);
  if (v12) {
    while (I_stricmp(a8->name, *(char **)v12)) {
      v12 = *(_DWORD *)(v12 + 32);
      if (!v12)
        goto LABEL_8;
    }
    if (*(_BYTE *)(v12 + 6) == 4) {
      v18 = LODWORD(a9);
      *(float *)v19 = a10;
      v16 = &v18;
    } else {
      Com_sprintf(__str, 0x40u, "%g %g", a9, a10);
      v16 = __str;
    }
    Dvar_SetVariant((const char **)v12, *(float *)&v16, 0);
  } else {
  LABEL_8:
    v13 = va("%g %g", a9, a10);
    v18 = DVAR_SOURCE_INTERNAL;
    *(_DWORD *)v19 = 0;
    Dvar_RegisterVariant(a8->name, 7, 0x4000u, (DvarValue)v13, 0.0, 0.0);
  }
}

void __cdecl Dvar_SetFloatByName(char const *dvarName, float value) {
  char v2;                 // al
  int v3;                  // eax
  int v4;                  // esi
  char *v5;                // eax
  unsigned __int8 v6;      // si
  int v7;                  // ebx
  float v8;                // edx
  char v9;                 // [esp+8h] [ebp-50h]
  char __str[4];           // [esp+20h] [ebp-38h] BYREF
  unsigned __int16 v11[2]; // [esp+24h] [ebp-34h]

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v9);
  v2 = a1->name[0];
  if (a1->name[0]) {
    v6 = 0;
    v7 = 119;
    do {
      v6 += v7 * __tolower(v2);
      v2 = *((_BYTE *)&a1[-3] + v7++ - 10);
    } while (v2);
    v3 = v6;
  } else {
    v3 = 0;
  }
  v4 = (int)*(&dvarHashTable + v3);
  if (v4) {
    while (I_stricmp(a1->name, *(char **)v4)) {
      v4 = *(_DWORD *)(v4 + 32);
      if (!v4)
        goto LABEL_8;
    }
    if (*(_BYTE *)(v4 + 6) == 1) {
      v8 = a2;
    } else {
      Com_sprintf(__str, 0x20u, "%g", a2);
      v8 = COERCE_FLOAT(__str);
    }
    Dvar_SetVariant((const char **)v4, v8, 0);
  } else {
  LABEL_8:
    v5 = va("%g", a2);
    *(_DWORD *)__str = 0;
    *(_DWORD *)v11 = 0;
    Dvar_RegisterVariant(a1->name, 7, 0x4000u, (DvarValue)v5, 0.0, 0.0);
  }
}

void __cdecl Dvar_SetIntByName(char const *dvarName, int value) {
  char v2;            // al
  int v3;             // eax
  int v4;             // esi
  unsigned __int8 v5; // si
  int v6;             // ebx
  dvar_s *integer;    // edx
  char v8;            // [esp+8h] [ebp-60h]
  dvar_s v9;          // [esp+10h] [ebp-58h] BYREF

  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v8);
  v2 = *a1;
  if (*a1) {
    v5 = 0;
    v6 = 119;
    do {
      v5 += v6 * __tolower(v2);
      v2 = a1[v6++ - 118];
    } while (v2);
    v3 = v5;
  } else {
    v3 = 0;
  }
  v4 = (int)*(&dvarHashTable + v3);
  if (v4) {
    while (I_stricmp(a1, *(char **)v4)) {
      v4 = *(_DWORD *)(v4 + 32);
      if (!v4)
        goto LABEL_8;
    }
    if ((unsigned __int8)(*(_BYTE *)(v4 + 6) - 5) <= 1u) {
      integer = (dvar_s *)a2.integer;
    } else {
      Com_sprintf(v9.name, 0x20u, "%i", a2.integer);
      integer = &v9;
    }
    Dvar_SetVariant((const char **)v4, *(float *)&integer, 0);
  } else {
  LABEL_8:
    Com_sprintf((char *)&v9.hashNext, 0x20u, "%i", a2.integer);
    *(_DWORD *)v9.name = 0;
    *(_DWORD *)&v9.flags = 0;
    Dvar_RegisterVariant(a1, 7, 0x4000u, (DvarValue)&v9.hashNext, 0.0, 0.0);
  }
}

void __cdecl Dvar_SetBoolByName(char const *dvarName, bool value) {
  char v2;            // al
  int v3;             // eax
  int v4;             // ebx
  const char *v5;     // ecx
  unsigned __int8 v6; // si
  int v7;             // ebx
  float v8;           // edx
  const char *v9;     // eax
  char v10;           // [esp+8h] [ebp-40h]
  float v11;          // [esp+1Ch] [ebp-2Ch]

  v11 = 0.0;
  if (!a1)
    Com_Error(1, "\x15null name in generateHashValue", v10);
  v2 = a1->name[0];
  if (a1->name[0]) {
    v6 = 0;
    v7 = 119;
    do {
      v6 += v7 * __tolower(v2);
      v2 = *((_BYTE *)&a1[-3] + v7++ - 10);
    } while (v2);
    v3 = v6;
  } else {
    v3 = 0;
  }
  v4 = (int)*(&dvarHashTable + v3);
  if (v4) {
    while (I_stricmp(a1->name, *(char **)v4)) {
      v4 = *(_DWORD *)(v4 + 32);
      if (!v4)
        goto LABEL_8;
    }
    if (*(_BYTE *)(v4 + 6)) {
      *(float *)&v9 = COERCE_FLOAT("0");
      if (a2)
        *(float *)&v9 = COERCE_FLOAT("1");
      v8 = *(float *)&v9;
    } else {
      LOBYTE(v11) = a2;
      v8 = v11;
    }
    Dvar_SetVariant((const char **)v4, v8, 0);
  } else {
  LABEL_8:
    v5 = "1";
    if (!a2)
      v5 = "0";
    Dvar_RegisterVariant(a1->name, 7, 0x4000u, (DvarValue)v5, 0.0, 0.0);
  }
}

void __cdecl Dvar_DeserializeDvars(char const *, int) { UNIMPLEMENTED(); }

struct dvar_s const *__cdecl Dvar_RegisterColor(char const *dvarName, float r,
                                                float g, float b, float a,
                                                unsigned short flags) {
  int v6;           // ebx
  float v7;         // xmm1_4
  float v8;         // xmm0_4
  float v9;         // xmm0_4
  float v10;        // xmm3_4
  float v11;        // xmm0_4
  float v12;        // xmm0_4
  float v13;        // xmm0_4
  float v14;        // xmm0_4
  unsigned int v15; // ebx
  float v16;        // xmm0_4
  float v17;        // xmm0_4
  float v19;        // [esp+30h] [ebp-28h]
  float v20;        // [esp+34h] [ebp-24h]
  float v21;        // [esp+38h] [ebp-20h]
  float v22;        // [esp+3Ch] [ebp-1Ch]

  HIWORD(v6) = 0;
  v7 = a2;
  if ((float)(a2 - 1.0) < 0.0) {
    v8 = 0.0 - a2;
  } else {
    v7 = 1.0;
    v8 = -1.0;
  }
  if (v8 < 0.0)
    v9 = v7 * 255.0;
  else
    v9 = 0.0;
  v22 = floorf(v9 + 0.5);
  v10 = a3;
  if ((float)(a3 - 1.0) < 0.0) {
    v11 = 0.0 - a3;
  } else {
    v10 = 1.0;
    v11 = -1.0;
  }
  if (v11 < 0.0)
    v12 = v10 * 255.0;
  else
    v12 = 0.0;
  v21 = floorf(v12 + 0.5);
  if ((float)(a4 - 1.0) < 0.0) {
    v13 = 0.0 - a4;
  } else {
    a4 = 1.0;
    v13 = -1.0;
  }
  if (v13 < 0.0)
    v14 = a4 * 255.0;
  else
    v14 = 0.0;
  v20 = floorf(v14 + 0.5);
  LOBYTE(v6) = (int)v22;
  BYTE1(v6) = (int)v21;
  v15 = ((unsigned __int8)(int)v20 << 16) | v6 & 0xFF00FFFF;
  if ((float)(a5 - 1.0) < 0.0) {
    v16 = 0.0 - a5;
  } else {
    a5 = 1.0;
    v16 = -1.0;
  }
  if (v16 < 0.0)
    v17 = a5 * 255.0;
  else
    v17 = 0.0;
  v19 = floorf(v17 + 0.5);
  return Dvar_RegisterVariant(
      a1, 8, a6, (DvarValue)(((int)v19 << 24) | v15 & 0xFFFFFF), 0.0, 0.0);
}

struct dvar_s const *__cdecl Dvar_RegisterEnum(char const *dvarName,
                                               char const **const valueList,
                                               int defaultIndex,
                                               unsigned short flags) {
  float v4; // ebx
  float v5; // edx

  v4 = 0.0;
  if (*a2) {
    v5 = 0.0;
    do
      ++LODWORD(v5);
    while (a2[LODWORD(v5)]);
    v4 = v5;
  }
  return Dvar_RegisterVariant(a1, 6, a4, (DvarValue)a3, v4, *(float *)&a2);
}

struct dvar_s const *__cdecl Dvar_RegisterVec4(char const *dvarName, float x,
                                               float y, float z, float w,
                                               float min, float max,
                                               unsigned short flags) {
  DvarValue v9; // [esp+10h] [ebp-18h] BYREF
  float v10;    // [esp+14h] [ebp-14h]
  float v11;    // [esp+18h] [ebp-10h]
  float v12;    // [esp+1Ch] [ebp-Ch]

  v9 = a2;
  v10 = a3;
  v11 = a4;
  v12 = a5;
  return Dvar_RegisterVariant(a1, 4, a8, (DvarValue)&v9, a6, a7);
}

struct dvar_s const *__cdecl Dvar_RegisterVec3(char const *dvarName, float x,
                                               float y, float z, float min,
                                               float max,
                                               unsigned short flags) {
  DvarValue v8; // [esp+14h] [ebp-14h] BYREF
  float v9;     // [esp+18h] [ebp-10h]
  float v10;    // [esp+1Ch] [ebp-Ch]

  v8 = a2;
  v9 = a3;
  v10 = a4;
  return Dvar_RegisterVariant(a1, 3, a7, (DvarValue)&v8, a5, a6);
}

struct dvar_s const *__cdecl Dvar_RegisterVec2(char const *dvarName, float x,
                                               float y, float min, float max,
                                               unsigned short flags) {
  DvarValue v7; // [esp+18h] [ebp-10h] BYREF
  float v8;     // [esp+1Ch] [ebp-Ch]

  v7 = a2;
  v8 = a3;
  return Dvar_RegisterVariant(a1, 2, a6, (DvarValue)&v7, a4, a5);
}

struct dvar_s const *__cdecl Dvar_RegisterFloat(char const *dvarName,
                                                float value, float min,
                                                float max,
                                                unsigned short flags) {
  return Dvar_RegisterVariant(a1, 1, a5, a2, a3, a4);
}

struct dvar_s const *__cdecl Dvar_RegisterInt(char const *dvarName, int value,
                                              int min, int max,
                                              unsigned short flags) {
  return Dvar_RegisterVariant(a1, 5, a5, (DvarValue)a2, *(float *)&a3,
                              *(float *)&a4);
}

struct dvar_s const *__cdecl Dvar_RegisterBool(char const *dvarName, bool value,
                                               unsigned short flags) {
  return Dvar_RegisterVariant(a1, 0, a3, (DvarValue)a2, 0.0, 0.0);
}

int __cdecl Com_LoadDvarsFromBuffer(char const **const dvarnames, int numDvars,
                                    char const *buffer, char const *filename) {
  int v3;           // eax
  char *v4;         // esi
  char v5;          // al
  int v6;           // eax
  int v7;           // ebx
  char *i;          // esi
  const char **v9;  // ebx
  int v10;          // edi
  int j;            // ebx
  char *v13;        // esi
  char v14;         // al
  int v15;          // eax
  int v16;          // ebx
  char *v17;        // eax
  int v18;          // edi
  int v19;          // ebx
  int v20;          // ebx
  char v21;         // [esp+8h] [ebp-4030h]
  int v22;          // [esp+14h] [ebp-4024h]
  int v23;          // [esp+18h] [ebp-4020h]
  int v24;          // [esp+1Ch] [ebp-401Ch]
  _BYTE __b[16408]; // [esp+20h] [ebp-4018h] BYREF

  memset(__b, 0, __len);
  if (__len > 0) {
    v22 = 0;
    v3 = 0;
    do {
      v4 = (char *)a1[v3];
      if (!v4)
        Com_Error(1, "\x15null name in generateHashValue", v21);
      v5 = *v4;
      if (*v4) {
        v18 = 0;
        v19 = 119;
        do {
          v18 += v19 * __tolower(v5);
          v5 = v4[v19 - 118];
          ++v19;
        } while (v5);
        v6 = (unsigned __int8)v18;
      } else {
        v6 = 0;
      }
      v7 = (int)*(&dvarHashTable + v6);
      if (v7) {
        while (I_stricmp(v4, *(char **)v7)) {
          v7 = *(_DWORD *)(v7 + 32);
          if (!v7)
            goto LABEL_10;
        }
      } else {
      LABEL_10:
        v7 = 0;
      }
      Dvar_SetVariant((const char **)v7, *(float *)(v7 + 16), 0);
      v3 = ++v22;
    } while (__len != v22);
  }
  Com_BeginParseSession(*(char **)&a3.flags);
  v23 = 0;
  for (i = Com_Parse((char **)&a3); *i; i = Com_Parse((char **)&a3)) {
    if (__len <= 0) {
    LABEL_17:
      Com_Printf("^3WARNING: unknown dvar '%s' in file '%s'\n", i,
                 *(const char **)&a3.flags);
    } else {
      v9 = a1;
      v10 = 0;
      while (stricmp(i, *v9)) {
        ++v10;
        ++v9;
        if (__len == v10)
          goto LABEL_17;
      }
      v13 = (char *)*v9;
      if (!*v9)
        Com_Error(1, "\x15null name in generateHashValue", v21);
      v14 = *v13;
      if (*v13) {
        v24 = 0;
        v20 = 119;
        do {
          v24 += v20 * __tolower(v14);
          v14 = v13[v20++ - 118];
        } while (v14);
        v15 = (unsigned __int8)v24;
      } else {
        v15 = 0;
      }
      v16 = (int)*(&dvarHashTable + v15);
      if (v16) {
        while (I_stricmp(v13, *(char **)v16)) {
          v16 = *(_DWORD *)(v16 + 32);
          if (!v16)
            goto LABEL_33;
        }
      } else {
      LABEL_33:
        v16 = 0;
      }
      v17 = Com_ParseOnLine((char **)&a3);
      Dvar_SetFromStringFromSource(v16, v17, 0);
      if (!__b[v10]) {
        __b[v10] = 1;
        ++v23;
      }
    }
    Com_SkipRestOfLine((unsigned __int8 **)&a3);
  }
  Com_EndParseSession();
  if (__len == v23)
    return 1;
  Com_Printf("^1ERROR: the following dvars were not specified in file '%s'\n",
             *(const char **)&a3.flags);
  if (__len > 0) {
    for (j = 0; j != __len; ++j) {
      while (__b[j]) {
        if (__len == ++j)
          return 0;
      }
      Com_Printf("^1  %s\n", a1[j]);
    }
  }
  return 0;
}
qboolean isDvarSystemActive = 0;
dvar_s *dvar_cheats;
void Dvar_Init() {
  DvarValue value = {0};
  DvarLimits limits = {0};
  isDvarSystemActive = 1;
  dvar_cheats = Dvar_RegisterVariant("sv_cheats", 0, 0x1018u, value, limits);
  Dvar_AddCommands();
}

int dvar_modifiedFlags;
int dvarCount;
int marker_dvar;
struct dvar_s *sortedDvars;
void __cdecl Dvar_UpdateSystems(struct dvar_s *, char const *, unsigned char,
                                unsigned short, union DvarValue,
                                union DvarLimits) {
  UNIMPLEMENTED();
}

union DvarValue __cdecl Dvar_GetReinterpretedResetValue(struct dvar_s *,
                                                        union DvarValue,
                                                        unsigned char,
                                                        unsigned short,
                                                        union DvarLimits) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_VectorDomainToString(int, union DvarLimits, char *, int) {
  UNIMPLEMENTED();
}

bool __cdecl Dvar_VectorInDomain(float const *, int, float, float) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_ClampVectorToDomain(float *, int, float, float) {
  UNIMPLEMENTED();
}

float __cdecl Dvar_StringToFloat(char const *) { UNIMPLEMENTED(); }

int __cdecl Dvar_StringToInt(char const *) { UNIMPLEMENTED(); }

bool __cdecl Dvar_StringToBool(char const *) { UNIMPLEMENTED(); }

float *__cdecl Dvar_TempVec(int) { UNIMPLEMENTED(); }

bool __cdecl Dvar_ValuesEqual(unsigned char, union DvarValue, union DvarValue) {
  UNIMPLEMENTED();
}

char const *__cdecl Dvar_DomainToString_Internal(unsigned char,
                                                 union DvarLimits, char *, int,
                                                 int *) {
  UNIMPLEMENTED();
}

bool __cdecl Dvar_ValueInDomain(unsigned char, union DvarValue,
                                union DvarLimits) {
  UNIMPLEMENTED();
}

union DvarValue __cdecl Dvar_ClampValueToDomain(unsigned char, union DvarValue,
                                                union DvarValue,
                                                union DvarLimits) {
  UNIMPLEMENTED();
}

int __cdecl Dvar_StringToEnum(union DvarLimits const *, char const *) {
  UNIMPLEMENTED();
}

float *__cdecl Dvar_StringToVec4(char const *) { UNIMPLEMENTED(); }

float *__cdecl Dvar_StringToVec3(char const *) { UNIMPLEMENTED(); }

float *__cdecl Dvar_StringToVec2(char const *) { UNIMPLEMENTED(); }

char const *__cdecl Dvar_ValueToString(struct dvar_s const *, union DvarValue) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_FreeString(char const *) { UNIMPLEMENTED(); }

void __cdecl Dvar_FreeNameString(char const *) { UNIMPLEMENTED(); }

void __cdecl Dvar_FreeVectorMemory(struct dvar_s *) { UNIMPLEMENTED(); }

void __cdecl Dvar_FreeResetString(struct dvar_s *) { UNIMPLEMENTED(); }

void __cdecl Dvar_FreeLatchedString(struct dvar_s *) { UNIMPLEMENTED(); }

void __cdecl Dvar_FreeCurrentString(struct dvar_s *) { UNIMPLEMENTED(); }

void __cdecl Dvar_StringToColor(char const *, unsigned char *const) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_AllocVectorMemory(struct dvar_s *) { UNIMPLEMENTED(); }

union DvarValue __cdecl Dvar_StringToValue(unsigned char, union DvarLimits,
                                           char const *) {
  UNIMPLEMENTED();
}

char const *__cdecl Dvar_CopyString(char const *) { UNIMPLEMENTED(); }

char const *__cdecl Dvar_AllocNameString(char const *) { UNIMPLEMENTED(); }

void __cdecl Dvar_AssignResetString(struct dvar_s *, char const *) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_AssignLatchedString(struct dvar_s *, char const *) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_AssignCurrentString(struct dvar_s *, char const *) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_UpdateValue(struct dvar_s *, union DvarValue) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_UpdateResetValue(struct dvar_s *, union DvarValue) {
  unsigned __int8 v4; // al
  _DWORD *v5;         // eax
  _DWORD *v6;         // edx
  char *v7;           // eax
  char v8;            // dl
  int v9;             // edi
  char v10;           // dl
  _DWORD *v11;        // edx
  unsigned int v12;   // kr04_4
  char v13;           // al

  v4 = *(_BYTE *)(a1 + 6);
  if (v4 == 3) {
    v6 = *(_DWORD **)(a1 + 16);
    *v6 = *(_DWORD *)a2;
    v6[1] = *(_DWORD *)(a2 + 4);
    v6[2] = *(_DWORD *)(a2 + 8);
    return;
  }
  if (v4 <= 3u) {
    if (v4 != 2)
      goto LABEL_5;
    v5 = *(_DWORD **)(a1 + 16);
    *v5 = *(_DWORD *)a2;
    v5[1] = *(_DWORD *)(a2 + 4);
  } else {
    if (v4 == 4) {
      v11 = *(_DWORD **)(a1 + 16);
      *v11 = *(_DWORD *)a2;
      v11[1] = *(_DWORD *)(a2 + 4);
      v11[2] = *(_DWORD *)(a2 + 8);
      v11[3] = *(_DWORD *)(a2 + 12);
      return;
    }
    if (v4 != 7) {
    LABEL_5:
      *(_DWORD *)(a1 + 16) = a2;
      return;
    }
    v7 = *(char **)(a1 + 16);
    if (v7 != *(char **)(a1 + 8) && v7 != *(char **)(a1 + 12)) {
      v8 = *v7;
      if (*v7) {
        if ((v7[1] || v8 <= 47 || v8 > 57) && v7 != dvarOnOffStrings[0] &&
            v7 != off_30A3E4)
          Z_FreeInternal(*(void **)(a1 + 16));
      }
    }
    *(_DWORD *)(a1 + 16) = 0;
    v9 = *(_DWORD *)(a1 + 8);
    if (v9 &&
            (a2 == v9 || !strcmp((const char *)a2, *(const char **)(a1 + 8))) ||
        (v9 = *(_DWORD *)(a1 + 12)) != 0 &&
            (a2 == v9 ||
             !strcmp((const char *)a2, *(const char **)(a1 + 12)))) {
      *(_DWORD *)(a1 + 16) = v9;
      return;
    }
    v10 = *(_BYTE *)a2;
    if (!*(_BYTE *)a2) {
      *(_DWORD *)(a1 + 16) = &inData;
      return;
    }
    v12 = strlen((const char *)a2) + 1;
    v13 = *(_BYTE *)(a2 + 1);
    if (!v13) {
      if ((unsigned __int8)(v10 - 48) <= 9u) {
        *(_DWORD *)(a1 + 16) = (char *)&xmmword_2F0200 + 2 * v10;
        return;
      }
      goto LABEL_31;
    }
    if (v10 != 111)
      goto LABEL_31;
    if (v12 != 4) {
      if (v12 == 3 && v13 == 110 && !*(_BYTE *)(a2 + 2)) {
        *(_DWORD *)(a1 + 16) = off_30A3E4;
        return;
      }
    LABEL_31:
      *(_DWORD *)(a1 + 16) = CopyStringInternal((char *)a2);
      return;
    }
    if (v13 != 102 || *(_BYTE *)(a2 + 2) != 102 || *(_BYTE *)(a2 + 3))
      goto LABEL_31;
    *(char **)(a1 + 16) = dvarOnOffStrings[0];
  }
}

void __cdecl Dvar_PerformUnregistration(struct dvar_s *) {
  __int16 v2;       // ax
  char v3;          // al
  char *v4;         // esi
  char v5;          // dl
  char *v6;         // eax
  char *v7;         // eax
  char *v8;         // esi
  char *v9;         // edi
  char v10;         // dl
  unsigned int v11; // kr04_4
  char v12;         // al
  unsigned int v13; // kr08_4
  char v14;         // al
  void *v15;        // [esp+1Ch] [ebp-1Ch]

  v2 = *(_WORD *)(a1 + 4);
  if ((v2 & 0x4000) == 0) {
    HIBYTE(v2) |= 0x40u;
    *(_WORD *)(a1 + 4) = v2;
    *(_DWORD *)a1 = CopyStringInternal(*(char **)a1);
  }
  v3 = *(_BYTE *)(a1 + 6);
  if (v3 == 7)
    return;
  if ((unsigned __int8)(v3 - 2) <= 2u) {
    v15 = *(void **)(a1 + 8);
    v4 = Dvar_ValueToString(a1, *(float **)(a1 + 12));
    v5 = *v4;
    if (!*v4)
      goto LABEL_6;
  } else {
    v15 = 0;
    v4 = Dvar_ValueToString(a1, *(float **)(a1 + 12));
    v5 = *v4;
    if (!*v4) {
    LABEL_6:
      v6 = (char *)&inData;
      goto LABEL_7;
    }
  }
  v11 = strlen(v4) + 1;
  v12 = v4[1];
  if (v12) {
    if (v5 == 111) {
      if (v11 == 4) {
        if (v12 == 102 && v4[2] == 102 && !v4[3]) {
          v6 = dvarOnOffStrings[0];
          goto LABEL_7;
        }
      } else if (v11 == 3 && v12 == 110 && !v4[2]) {
        v6 = off_30A3E4;
        goto LABEL_7;
      }
    }
  } else if ((unsigned __int8)(v5 - 48) <= 9u) {
    v6 = (char *)&xmmword_2F0200 + 2 * v5;
    goto LABEL_7;
  }
  v6 = CopyStringInternal(v4);
LABEL_7:
  *(_DWORD *)(a1 + 8) = v6;
  *(_DWORD *)(a1 + 12) = v6;
  v7 = Dvar_ValueToString(a1, *(float **)(a1 + 16));
  v8 = v7;
  v9 = *(char **)(a1 + 8);
  if (!v9 || v7 != v9 && strcmp(v7, *(const char **)(a1 + 8))) {
    v9 = *(char **)(a1 + 12);
    if (!v9 || v8 != v9 && strcmp(v8, *(const char **)(a1 + 12))) {
      v10 = *v8;
      if (!*v8) {
        *(_DWORD *)(a1 + 16) = &inData;
        goto LABEL_15;
      }
      v13 = strlen(v8) + 1;
      v14 = v8[1];
      if (v14) {
        if (v10 != 111) {
        LABEL_27:
          *(_DWORD *)(a1 + 16) = CopyStringInternal(v8);
          goto LABEL_15;
        }
        if (v13 == 4) {
          if (v14 != 102 || v8[2] != 102 || v8[3])
            goto LABEL_27;
          *(char **)(a1 + 16) = dvarOnOffStrings[0];
        } else {
          if (v13 != 3 || v14 != 110 || v8[2])
            goto LABEL_27;
          *(_DWORD *)(a1 + 16) = off_30A3E4;
        }
      } else {
        if ((unsigned __int8)(v10 - 48) > 9u)
          goto LABEL_27;
        *(_DWORD *)(a1 + 16) = (char *)&xmmword_2F0200 + 2 * v10;
      }
    LABEL_15:
      *(_BYTE *)(a1 + 6) = 7;
      if (!v15)
        return;
    LABEL_22:
      Z_FreeInternal(v15);
      return;
    }
  }
  *(_DWORD *)(a1 + 16) = v9;
  *(_BYTE *)(a1 + 6) = 7;
  if (v15)
    goto LABEL_22;
}

void __cdecl Dvar_SetLatchedValue(struct dvar_s *, union DvarValue) {
  unsigned __int8 v4; // al
  _DWORD *v5;         // eax
  _DWORD *v6;         // edx
  char *v7;           // eax
  char v8;            // dl
  int v9;             // edi
  char v10;           // dl
  _DWORD *v11;        // edx
  unsigned int v12;   // kr04_4
  char v13;           // al

  v4 = *(_BYTE *)(a1 + 6);
  if (v4 == 3) {
    v6 = *(_DWORD **)(a1 + 12);
    *v6 = *(_DWORD *)a2;
    v6[1] = *(_DWORD *)(a2 + 4);
    v6[2] = *(_DWORD *)(a2 + 8);
    return;
  }
  if (v4 <= 3u) {
    if (v4 != 2)
      goto LABEL_5;
    v5 = *(_DWORD **)(a1 + 12);
    *v5 = *(_DWORD *)a2;
    v5[1] = *(_DWORD *)(a2 + 4);
  } else {
    if (v4 == 4) {
      v11 = *(_DWORD **)(a1 + 12);
      *v11 = *(_DWORD *)a2;
      v11[1] = *(_DWORD *)(a2 + 4);
      v11[2] = *(_DWORD *)(a2 + 8);
      v11[3] = *(_DWORD *)(a2 + 12);
      return;
    }
    if (v4 != 7) {
    LABEL_5:
      *(_DWORD *)(a1 + 12) = a2;
      return;
    }
    v7 = *(char **)(a1 + 12);
    if (v7 != *(char **)(a1 + 8) && v7 != *(char **)(a1 + 16)) {
      v8 = *v7;
      if (*v7) {
        if ((v7[1] || v8 <= 47 || v8 > 57) && v7 != dvarOnOffStrings[0] &&
            v7 != off_30A3E4)
          Z_FreeInternal(*(void **)(a1 + 12));
      }
    }
    *(_DWORD *)(a1 + 12) = 0;
    v9 = *(_DWORD *)(a1 + 8);
    if (v9 &&
            (a2 == v9 || !strcmp((const char *)a2, *(const char **)(a1 + 8))) ||
        (v9 = *(_DWORD *)(a1 + 16)) != 0 &&
            (a2 == v9 ||
             !strcmp((const char *)a2, *(const char **)(a1 + 16)))) {
      *(_DWORD *)(a1 + 12) = v9;
      return;
    }
    v10 = *(_BYTE *)a2;
    if (!*(_BYTE *)a2) {
      *(_DWORD *)(a1 + 12) = &inData;
      return;
    }
    v12 = strlen((const char *)a2) + 1;
    v13 = *(_BYTE *)(a2 + 1);
    if (!v13) {
      if ((unsigned __int8)(v10 - 48) <= 9u) {
        *(_DWORD *)(a1 + 12) = (char *)&xmmword_2F0200 + 2 * v10;
        return;
      }
      goto LABEL_31;
    }
    if (v10 != 111)
      goto LABEL_31;
    if (v12 != 4) {
      if (v12 == 3 && v13 == 110 && !*(_BYTE *)(a2 + 2)) {
        *(_DWORD *)(a1 + 12) = off_30A3E4;
        return;
      }
    LABEL_31:
      *(_DWORD *)(a1 + 12) = CopyStringInternal((char *)a2);
      return;
    }
    if (v13 != 102 || *(_BYTE *)(a2 + 2) != 102 || *(_BYTE *)(a2 + 3))
      goto LABEL_31;
    *(char **)(a1 + 12) = dvarOnOffStrings[0];
  }
}

void __cdecl Dvar_MakeExplicitType(struct dvar_s *, char const *, unsigned char,
                                   unsigned short, union DvarValue,
                                   union DvarLimits) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_SetVariant(struct dvar_s *, union DvarValue,
                             enum DvarSetSource) {
  char *v4;            // eax
  char *v5;            // eax
  float v6;            // ecx
  float v7;            // ebx
  const char *v8;      // ebx
  char *v9;            // eax
  int v10;             // eax
  float v11;           // xmm0_4
  char v12;            // al
  int v13;             // ebx
  unsigned __int8 v14; // al
  __int16 v15;         // dx
  int v16;             // eax
  float v17;           // xmm0_4
  int v18;             // eax
  float v19;           // xmm0_4
  char *v20;           // eax
  char v21;            // dl
  const char *v22;     // ecx
  char *v23;           // ebx
  char v24;            // al
  char *v25;           // edx
  char *v26;           // edx
  char *v27;           // edx
  char *v28;           // edx
  char *v29;           // edx
  char *v30;           // edx
  const char *v31;     // ebx
  char v32;            // dl
  char *v33;           // eax
  unsigned int v34;    // kr08_4
  char v35;            // al
  dvar_s *v36;         // [esp+0h] [ebp-448h]
  char *v37;           // [esp+4h] [ebp-444h]
  DvarSetSource v38;   // [esp+8h] [ebp-440h]
  char *v40;           // [esp+24h] [ebp-424h]
  char v42;            // [esp+2Ch] [ebp-41Ch]
  char __str[1048];    // [esp+30h] [ebp-418h] BYREF

  v4 = Dvar_ValueToString((int)a1, (float *)LODWORD(a2));
  v5 = va("      dvar set %s %s\n", *a1, v4);
  Com_PrintMessage(PMSG_LOGFILE, v5);
  v6 = *((float *)a1 + 5);
  v7 = *((float *)a1 + 6);
  v42 = *((_BYTE *)a1 + 6);
  switch (v42) {
  case 0:
  case 7:
  case 8:
    goto LABEL_12;
  case 1:
    if (v6 > a2 || a2 > v7)
      goto LABEL_4;
    goto LABEL_12;
  case 2:
    v10 = 1;
    while (1) {
      v11 = *(float *)(LODWORD(a2) + 4 * v10 - 4);
      if (v6 > v11 || v11 > v7)
        goto LABEL_43;
      if (++v10 == 3)
        goto LABEL_10;
    }
  case 3:
    v16 = 1;
    while (1) {
      v17 = *(float *)(LODWORD(a2) + 4 * v16 - 4);
      if (v6 > v17 || v17 > v7)
        goto LABEL_43;
      if (++v16 == 4)
        goto LABEL_10;
    }
  case 4:
    v18 = 1;
    break;
  case 5:
    if (SLODWORD(a2) >= SLODWORD(v6) && SLODWORD(a2) <= SLODWORD(v7))
      goto LABEL_12;
    goto LABEL_4;
  case 6:
    if ((a2 < 0.0 || SLODWORD(a2) >= SLODWORD(v6)) && a2 != 0.0)
      goto LABEL_43;
    v12 = 1;
    goto LABEL_11;
  default:
    goto LABEL_4;
  }
  while (1) {
    v19 = *(float *)(LODWORD(a2) + 4 * v18 - 4);
    if (v6 > v19 || v19 > v7)
      break;
    if (++v18 == 5) {
    LABEL_10:
      v12 = 1;
      goto LABEL_11;
    }
  }
LABEL_43:
  v12 = 0;
LABEL_11:
  if (!v12) {
  LABEL_4:
    v8 = *a1;
    v9 = Dvar_ValueToString((int)a1, (float *)LODWORD(a2));
    Com_Printf("'%s' is not a valid value for dvar '%s'\n", v9, v8);
    v37 = Dvar_DomainToString_Internal(*((_BYTE *)a1 + 6), *((float *)a1 + 5),
                                       *((float *)a1 + 6), __str,
                                       (DvarLimits)1024LL);
    Com_Printf(stru_2182FC.name);
    if (*((_BYTE *)a1 + 6) == 6)
      Dvar_SetVariant(v36, (DvarValue)v37, v38);
    return;
  }
LABEL_12:
  if ((unsigned int)(a3 - 1) <= 1) {
    v15 = *((_WORD *)a1 + 2);
    if ((v15 & 0x40) != 0) {
      Com_Printf("%s is read only.\n", *a1);
      return;
    }
    if ((v15 & 0x10) != 0) {
      Com_Printf("%s is write protected.\n", *a1);
      return;
    }
    if (a3 == 1 && (v15 & 0x80u) != 0 && !*(_BYTE *)(dvar_cheats + 8)) {
      Com_Printf("%s is cheat protected.\n", *a1);
      return;
    }
    if ((v15 & 0x20) != 0) {
      Dvar_SetLatchedValue((int)a1, SLODWORD(a2));
      if (!Dvar_ValuesEqual(*((_BYTE *)a1 + 6), *((float *)a1 + 3),
                            *((float *)a1 + 2)))
        Com_Printf("%s will be changed upon restarting.\n", *a1);
      return;
    }
  }
  v13 = (int)a1[2];
  if (Dvar_ValuesEqual(v42, *(float *)&v13, a2)) {
    Dvar_SetLatchedValue((int)a1, v13);
    return;
  }
  dvar_modifiedFlags |= *((unsigned __int16 *)a1 + 2);
  v14 = *((_BYTE *)a1 + 6);
  if (v14 == 3) {
    v29 = (char *)a1[2];
    *(_DWORD *)v29 = *(_DWORD *)LODWORD(a2);
    *((_DWORD *)v29 + 1) = *(_DWORD *)(LODWORD(a2) + 4);
    *((_DWORD *)v29 + 2) = *(_DWORD *)(LODWORD(a2) + 8);
    v30 = (char *)a1[3];
    *(_DWORD *)v30 = *(_DWORD *)LODWORD(a2);
    *((_DWORD *)v30 + 1) = *(_DWORD *)(LODWORD(a2) + 4);
    *((_DWORD *)v30 + 2) = *(_DWORD *)(LODWORD(a2) + 8);
    *((_BYTE *)a1 + 7) = 1;
    return;
  }
  if (v14 > 3u) {
    if (v14 == 4) {
      v25 = (char *)a1[2];
      *(_DWORD *)v25 = *(_DWORD *)LODWORD(a2);
      *((_DWORD *)v25 + 1) = *(_DWORD *)(LODWORD(a2) + 4);
      *((_DWORD *)v25 + 2) = *(_DWORD *)(LODWORD(a2) + 8);
      *((_DWORD *)v25 + 3) = *(_DWORD *)(LODWORD(a2) + 12);
      v26 = (char *)a1[3];
      *(_DWORD *)v26 = *(_DWORD *)LODWORD(a2);
      *((_DWORD *)v26 + 1) = *(_DWORD *)(LODWORD(a2) + 4);
      *((_DWORD *)v26 + 2) = *(_DWORD *)(LODWORD(a2) + 8);
      *((_DWORD *)v26 + 3) = *(_DWORD *)(LODWORD(a2) + 12);
      *((_BYTE *)a1 + 7) = 1;
      return;
    }
    if (v14 != 7)
      goto LABEL_17;
    v20 = (char *)a1[2];
    if (v20 != a1[3] && v20 != a1[4]) {
      v21 = *v20;
      if (*v20) {
        if ((v20[1] || v21 <= 47 || v21 > 57) && v20 != dvarOnOffStrings[0] &&
            v20 != off_30A3E4)
          Z_FreeInternal((void *)a1[2]);
      }
    }
    a1[2] = 0;
    v22 = a1[3];
    v40 = (char *)v22;
    if (v22 && ((const char *)LODWORD(a2) == v22 ||
                !strcmp((const char *)LODWORD(a2), v22))) {
      a1[2] = v40;
      v23 = v40;
      goto LABEL_59;
    }
    v31 = a1[4];
    if (v31 && ((const char *)LODWORD(a2) == v31 ||
                !strcmp((const char *)LODWORD(a2), a1[4]))) {
      a1[2] = v31;
      v23 = v40;
      goto LABEL_59;
    }
    v32 = *(_BYTE *)LODWORD(a2);
    if (!*(_BYTE *)LODWORD(a2)) {
      v33 = (char *)&inData;
    LABEL_83:
      a1[2] = v33;
      v23 = v40;
    LABEL_59:
      if (v23 != a1[2] && v23 != a1[4]) {
        v24 = *v23;
        if (*v23) {
          if ((v23[1] || v24 <= 47 || v24 > 57) && v40 != dvarOnOffStrings[0] &&
              v40 != off_30A3E4)
            Z_FreeInternal(v40);
        }
      }
      a1[3] = a1[2];
      *((_BYTE *)a1 + 7) = 1;
      return;
    }
    v34 = strlen((const char *)LODWORD(a2)) + 1;
    v35 = *(_BYTE *)(LODWORD(a2) + 1);
    if (v35) {
      if (v32 == 111) {
        if (v34 == 4) {
          if (v35 == 102 && *(_BYTE *)(LODWORD(a2) + 2) == 102 &&
              !*(_BYTE *)(LODWORD(a2) + 3)) {
            v33 = dvarOnOffStrings[0];
            goto LABEL_83;
          }
        } else if (v34 == 3 && v35 == 110 && !*(_BYTE *)(LODWORD(a2) + 2)) {
          v33 = off_30A3E4;
          goto LABEL_83;
        }
      }
    } else if ((unsigned __int8)(v32 - 48) <= 9u) {
      v33 = (char *)&xmmword_2F0200 + 2 * v32;
      goto LABEL_83;
    }
    v33 = CopyStringInternal((char *)LODWORD(a2));
    v40 = (char *)a1[3];
    goto LABEL_83;
  }
  if (v14 != 2) {
  LABEL_17:
    *((float *)a1 + 2) = a2;
    *((float *)a1 + 3) = a2;
    *((_BYTE *)a1 + 7) = 1;
    return;
  }
  v27 = (char *)a1[2];
  *(_DWORD *)v27 = *(_DWORD *)LODWORD(a2);
  *((_DWORD *)v27 + 1) = *(_DWORD *)(LODWORD(a2) + 4);
  v28 = (char *)a1[3];
  *(_DWORD *)v28 = *(_DWORD *)LODWORD(a2);
  *((_DWORD *)v28 + 1) = *(_DWORD *)(LODWORD(a2) + 4);
  *((_BYTE *)a1 + 7) = 1;
}

void __cdecl Dvar_SetFromStringFromSource(struct dvar_s const *, char const *,
                                          enum DvarSetSource) {
  char *v4;         // eax
  char *v5;         // eax
  char __str[1024]; // [esp+20h] [ebp-818h] BYREF
  char __dst[1048]; // [esp+420h] [ebp-418h] BYREF

  I_strncpyz(__dst, a2, 1024);
  v4 = Dvar_StringToValue(*(_BYTE *)(a1 + 6), *(_DWORD *)(a1 + 20),
                          *(_DWORD *)(a1 + 24), __dst);
  if (*(_BYTE *)(a1 + 6) == 6 && v4 == (char *)-1337) {
    Com_Printf("'%s' is not a valid value for dvar '%s'\n", __dst,
               *(const char **)a1);
    v5 = Dvar_DomainToString_Internal(*(_BYTE *)(a1 + 6), *(float *)(a1 + 20),
                                      *(float *)(a1 + 24), __str,
                                      (DvarLimits)1024LL);
    Com_Printf(stru_2182FC.name, v5);
    Dvar_SetVariant((const char **)a1, *(float *)(a1 + 16), a3);
  } else {
    Dvar_SetVariant((const char **)a1, *(float *)&v4, a3);
  }
}

void __cdecl Dvar_SetStringFromSource(struct dvar_s const *, char const *,
                                      enum DvarSetSource) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_ReinterpretDvar(struct dvar_s *, char const *, unsigned char,
                                  unsigned short, union DvarValue,
                                  union DvarLimits) {
  UNIMPLEMENTED();
}

void __cdecl Dvar_Reregister(struct dvar_s *, char const *, unsigned char,
                             unsigned short, union DvarValue,
                             union DvarLimits) {
  UNIMPLEMENTED();
}

long __cdecl generateHashValue(char const *) { UNIMPLEMENTED(); }

struct dvar_s const *__cdecl Dvar_RegisterNew(char const *, unsigned char,
                                              unsigned short, union DvarValue,
                                              union DvarLimits) {
  UNIMPLEMENTED();
}

struct dvar_s *__cdecl Dvar_FindMalleableVar(char const *) {
  UNIMPLEMENTED();
}

dvar_s *__usercall Dvar_RegisterVariant@<eax>(
        char *a1@<eax>,
        int8_t a2@<dl>,
        unsigned __int16 a3@<cx>,
        DvarValue a4,
        DvarSetSource a5,
        int32_t a6)
{
  char *v7; // edx
  char v8; // al
  int v9; // eax
  int v10; // edi
  int8_t v11; // di
  int v12; // ebx
  dvar_s *v13; // esi
  int8_t v14; // cl
  bool v15; // cc
  char v16; // dl
  char *v17; // eax
  const char **v18; // eax
  int *v19; // edi
  int v20; // eax
  int v21; // edx
  unsigned __int8 v23; // bl
  int v24; // edi
  unsigned __int8 v25; // bl
  int v26; // edi
  _DWORD *v27; // eax
  int v28; // ecx
  _DWORD *v29; // edx
  _DWORD *v30; // edx
  __int16 v31; // dx
  unsigned __int16 v32; // si
  __int16 v33; // ax
  _DWORD *v34; // eax
  int type; // ecx
  _DWORD *latched; // edx
  _DWORD *reset; // edx
  _DWORD *v38; // eax
  int v39; // ecx
  _DWORD *v40; // edx
  _DWORD *v41; // edx
  unsigned int v42; // kr04_4
  char v43; // al
  char *integer; // ecx
  dvar_s *v45; // [esp+0h] [ebp-48h]
  dvar_s *v46; // [esp+0h] [ebp-48h]
  DvarValue v47; // [esp+4h] [ebp-44h]
  DvarValue v48; // [esp+4h] [ebp-44h]
  DvarSetSource v49; // [esp+8h] [ebp-40h]
  DvarValue v50; // [esp+10h] [ebp-38h]
  DvarLimits v51; // [esp+14h] [ebp-34h]
  int8_t v54; // [esp+2Ch] [ebp-1Ch]

  if ( a1 )
  {
    v7 = a1;
  }
  else
  {
    Com_Error(1, "\x15null name in generateHashValue", v49);
    v7 = 0;
  }
  v8 = *v7;
  if ( *v7 )
  {
    v23 = 0;
    v24 = 119;
    do
    {
      v23 += v24 * __tolower(v8);
      v8 = a1[v24++ - 118];
    }
    while ( v8 );
    v9 = v23;
  }
  else
  {
    v9 = 0;
  }
  v10 = (int)*(&dvarHashTable + v9);
  if ( !v10 )
  {
LABEL_8:
    v11 = a2;
    if ( dvarCount > 1279 )
      Com_Error(0, "Can't create dvar '%s': %i dvars already exist", (char)a1);
    v12 = 9 * dvarCount;
    v13 = (dvar_s *)&dvarPool[9 * dvarCount++];
    v13->type = v11;
    if ( (a3 & 0x4000) != 0 )
    {
      dvarPool[v12] = (int)CopyStringInternal(a1);
      v14 = v11;
      v15 = (unsigned __int8)v11 <= 3u;
      if ( v11 != 3 )
      {
LABEL_12:
        if ( v15 )
        {
          if ( v14 != 2 )
            goto LABEL_18;
          v34 = Z_MallocInternal(12 * (unsigned __int8)v13->type);
          v13->current.integer = (int32_t)v34;
          type = (unsigned __int8)v13->type;
          v13->latched = (int32_t)&v34[type];
          v13->reset = (int32_t)&v34[type + type];
          *v34 = *(_DWORD *)a4.integer;
          v34[1] = *(_DWORD *)(a4.integer + 4);
          latched = (_DWORD *)v13->latched;
          *latched = *(_DWORD *)a4.integer;
          latched[1] = *(_DWORD *)(a4.integer + 4);
          reset = (_DWORD *)v13->reset;
          *reset = *(_DWORD *)a4.integer;
          reset[1] = *(_DWORD *)(a4.integer + 4);
        }
        else
        {
          if ( v11 != 4 )
          {
            if ( v11 == 7 )
            {
              v16 = *(_BYTE *)a4.integer;
              if ( !*(_BYTE *)a4.integer )
              {
                v17 = (char *)&inData;
LABEL_19:
                v13->current.integer = (int32_t)v17;
                v13->latched = (int32_t)v17;
                v13->reset = (int32_t)v17;
                goto LABEL_20;
              }
              v42 = strlen((const char *)a4.integer) + 1;
              v43 = *(_BYTE *)(a4.integer + 1);
              if ( v43 )
              {
                if ( v16 == 111 )
                {
                  if ( v42 == 4 )
                  {
                    if ( v43 == 102 )
                    {
                      if ( *(_BYTE *)(a4.integer + 2) != 102 )
                      {
                        integer = (char *)a4.integer;
                        goto LABEL_61;
                      }
                      if ( !*(_BYTE *)(a4.integer + 3) )
                      {
                        v17 = dvarOnOffStrings[0];
                        goto LABEL_19;
                      }
                    }
                  }
                  else if ( v42 == 3 && v43 == 110 )
                  {
                    if ( !*(_BYTE *)(a4.integer + 2) )
                    {
                      v17 = off_30A3E4;
                      goto LABEL_19;
                    }
                    integer = (char *)a4.integer;
                    goto LABEL_61;
                  }
                }
              }
              else if ( (unsigned __int8)(v16 - 48) <= 9u )
              {
                v17 = (char *)&xmmword_2F0200 + 2 * v16;
                goto LABEL_19;
              }
              integer = (char *)a4.integer;
LABEL_61:
              v17 = CopyStringInternal(integer);
              goto LABEL_19;
            }
LABEL_18:
            v17 = (char *)a4.integer;
            goto LABEL_19;
          }
          v38 = Z_MallocInternal(12 * (unsigned __int8)v13->type);
          v13->current.integer = (int32_t)v38;
          v39 = (unsigned __int8)v13->type;
          v13->latched = (int32_t)&v38[v39];
          v13->reset = (int32_t)&v38[v39 + v39];
          *v38 = *(_DWORD *)a4.integer;
          v38[1] = *(_DWORD *)(a4.integer + 4);
          v38[2] = *(_DWORD *)(a4.integer + 8);
          v38[3] = *(_DWORD *)(a4.integer + 12);
          v40 = (_DWORD *)v13->latched;
          *v40 = *(_DWORD *)a4.integer;
          v40[1] = *(_DWORD *)(a4.integer + 4);
          v40[2] = *(_DWORD *)(a4.integer + 8);
          v40[3] = *(_DWORD *)(a4.integer + 12);
          v41 = (_DWORD *)v13->reset;
          *v41 = *(_DWORD *)a4.integer;
          v41[1] = *(_DWORD *)(a4.integer + 4);
          v41[2] = *(_DWORD *)(a4.integer + 8);
          v41[3] = *(_DWORD *)(a4.integer + 12);
        }
LABEL_20:
        v13->domain.integer.min = a5;
        v13->domain.integer.max = a6;
        v13->modified = 0;
        v18 = (const char **)sortedDvars;
        if ( sortedDvars )
        {
          v19 = &sortedDvars;
          do
          {
            if ( (int)stricmp(*(const char **)v13->name, *v18) < 0 )
              break;
            v19 = (int *)(*v19 + 28);
            v18 = (const char **)*v19;
          }
          while ( *v19 );
          v13->next = *v19;
          *v19 = (int)v13;
          v13->flags = a3;
          LOBYTE(v20) = *a1;
          if ( !*a1 )
            goto LABEL_25;
        }
        else
        {
          v13->next = 0;
          sortedDvars = (int)v13;
          v13->flags = a3;
          v20 = (unsigned __int8)*a1;
          if ( !*a1 )
          {
LABEL_25:
            v21 = 0;
LABEL_26:
            v13->hashNext = (int32_t)*(&dvarHashTable + v21);
            *(&dvarHashTable + v21) = v13;
            return v13;
          }
        }
        v25 = 0;
        v26 = 119;
        do
        {
          v25 += v26 * __tolower((char)v20);
          LOBYTE(v20) = a1[v26++ - 118];
        }
        while ( (_BYTE)v20 );
        v21 = v25;
        goto LABEL_26;
      }
    }
    else
    {
      dvarPool[v12] = (int)a1;
      v14 = v11;
      v15 = (unsigned __int8)v11 <= 3u;
      if ( v11 != 3 )
        goto LABEL_12;
    }
    v27 = Z_MallocInternal(12 * (unsigned __int8)v13->type);
    v13->current.integer = (int32_t)v27;
    v28 = (unsigned __int8)v13->type;
    v13->latched = (int32_t)&v27[v28];
    v13->reset = (int32_t)&v27[v28 + v28];
    *v27 = *(_DWORD *)a4.integer;
    v27[1] = *(_DWORD *)(a4.integer + 4);
    v27[2] = *(_DWORD *)(a4.integer + 8);
    v29 = (_DWORD *)v13->latched;
    *v29 = *(_DWORD *)a4.integer;
    v29[1] = *(_DWORD *)(a4.integer + 4);
    v29[2] = *(_DWORD *)(a4.integer + 8);
    v30 = (_DWORD *)v13->reset;
    *v30 = *(_DWORD *)a4.integer;
    v30[1] = *(_DWORD *)(a4.integer + 4);
    v30[2] = *(_DWORD *)(a4.integer + 8);
    goto LABEL_20;
  }
  while ( I_stricmp(a1, *(_DWORD *)v10) )
  {
    v10 = *(_DWORD *)(v10 + 32);
    if ( !v10 )
      goto LABEL_8;
  }
  v54 = a2;
  v31 = *(_WORD *)(v10 + 4);
  if ( ((HIBYTE(v31) ^ HIBYTE(a3)) & 0x70) == 0 )
    goto LABEL_39;
  if ( (v31 & 0x4000) != 0 )
  {
    v32 = a3;
    if ( (a3 & 0x4000) != 0 )
      goto LABEL_39;
    Dvar_PerformUnregistration(v45);
    Z_FreeInternal(*(_DWORD *)v10);
    *(_DWORD *)v10 = a1;
    *(_WORD *)(v10 + 4) &= ~0x4000u;
    Dvar_MakeExplicitType((dvar_s *)a3, (const char *)a4.integer, a5, a6, v50, v51);
    v31 = *(_WORD *)(v10 + 4);
LABEL_53:
    if ( (v32 & 0x1000) != 0 && (v31 & 0x1000) == 0 )
    {
      *(_DWORD *)v10 = a1;
      if ( *(_BYTE *)(v10 + 6) == 6 )
      {
        *(_DWORD *)(v10 + 20) = a5;
        *(_DWORD *)(v10 + 24) = a6;
      }
    }
    goto LABEL_39;
  }
  v32 = a3;
  if ( (a3 & 0x4000) == 0 )
    goto LABEL_53;
LABEL_39:
  if ( (v31 & 0x4000) != 0 && v54 != *(_BYTE *)(v10 + 6) )
    Dvar_MakeExplicitType((dvar_s *)a3, (const char *)a4.integer, a5, a6, v50, v51);
  v33 = *(_WORD *)(v10 + 4) | a3;
  *(_WORD *)(v10 + 4) = v33;
  if ( (v33 & 0x80u) != 0 && dvar_cheats && !*(_BYTE *)(dvar_cheats + 8) )
  {
    Dvar_SetVariant(v45, v47, v49);
    Dvar_SetLatchedValue(v46, v48);
  }
  if ( (*(_BYTE *)(v10 + 4) & 0x20) != 0 )
    Dvar_SetVariant(v45, v47, v49);
  return (dvar_s *)v10;
}
