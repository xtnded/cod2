
#include "../qcommon/qcommon.h"
float const *const colorBlack;
float const *const colorRed;
float const *const colorGreen;
float const *const colorLtGreen;
float const *const colorBlue;
float const *const colorLtBlue;
float const *const colorYellow;
float const *const colorLtYellow;
float const *const colorMdYellow;
float const *const colorMagenta;
float const *const colorCyan;
float const *const colorLtCyan;
float const *const colorMdCyan;
float const *const colorDkCyan;
float const *const colorWhite;
float const *const colorLtGrey;
float const *const colorMdGrey;
float const *const colorDkGrey;
float const *const colorOrange;
float const *const colorLtOrange;

float __cdecl IntAsFloat(int)
{
  UNIMPLEMENTED();
}

int __cdecl Info_Validate(char const *s)
{
  return !strchr(__s, 34) && !strchr(__s, 59);
}

void __cdecl Info_RemoveKey(char *s, char const *key)
{
  char *v2;        // ebx
  char *result;    // eax
  char *v4;        // edx
  char *v5;        // ecx
  const char *v6;  // edi
  char v7;         // al
  char *v8;        // edx
  char v9;         // [esp+8h] [ebp-820h]
  char v10[1024];  // [esp+10h] [ebp-818h] BYREF
  char __s2[1048]; // [esp+410h] [ebp-418h] BYREF

  v2 = __dst;
  if (strlen(__dst) > 0x3FF)
    Com_Error(1, "\x15Info_RemoveKey: oversize infostring", v9);
  result = strchr(__s, 92);
    if (!result) {
        while (1) {
            if (*v2 == 92) {
              v4 = v2 + 1;
              result = (char *)(unsigned __int8)v2[1];
                if ((_BYTE)result == 92) {
                  v5 = __s2;
                  goto LABEL_7;
                }
            }
            else {
              result = (char *)(unsigned __int8)*v2;
              v4 = v2;
            }
          if (!(_BYTE)result)
            return result;
          v5 = __s2;
            while (1) {
              *v5++ = (char)result;
              result = (char *)(unsigned __int8)*++v4;
              if ((_BYTE)result == 92)
                break;
              if (!(_BYTE)result)
                return result;
            }
        LABEL_7:
          *v5 = 0;
          v6 = v4 + 1;
          v7 = v4[1];
            if (v7 != 92 && v7) {
              v8 = v10;
                do {
                  *v8++ = v7;
                  v7 = *++v6;
                }
              while (*v6 != 92 && v7);
            }
            else {
              v8 = v10;
            }
          *v8 = 0;
          result = (char *)strcmp(__s, __s2);
          if (!result)
            return strcpy(v2, v6);
          if (!*v6)
            return result;
          v2 = (char *)v6;
        }
    }
  return result;
}

void __cdecl Info_NextPair(char const **head, char *key, char *value)
{
  char *v3;       // edx
  const char *v4; // ecx
  int result;     // eax
  const char *v6; // ebx
  char *v7;       // edx

  v3 = a2;
  v4 = *a1;
  if (**a1 == 92)
    v4 = *a1 + 1;
  *a2 = 0;
  *a3 = 0;
  result = *(unsigned __int8 *)v4;
    if ((_BYTE)result == 92) {
    LABEL_6:
      *v3 = 0;
      v6 = v4 + 1;
      result = *((unsigned __int8 *)v4 + 1);
        if ((_BYTE)result == 92 || !(_BYTE)result) {
          *a3 = 0;
          *a1 = v6;
        }
        else {
          v7 = a3;
            do {
              *v7++ = result;
              result = *(unsigned __int8 *)++v6;
            }
          while ((_BYTE)result != 92 && (_BYTE)result);
          *v7 = 0;
          *a1 = v6;
        }
    }
    else {
        while ((_BYTE)result) {
          *v3++ = result;
          result = *(unsigned __int8 *)++v4;
          if ((_BYTE)result == 92)
            goto LABEL_6;
        }
      *v3 = 0;
      *a1 = v4;
    }
  return result;
}

void __cdecl ConvertWCharToChar(unsigned short const *, char *, int)
{
  UNIMPLEMENTED();
}

int __cdecl Com_sprintf(char *dest, int size, char const *fmt, ...)
{
  int result; // eax
  va_list va; // [esp+3Ch] [ebp+14h] BYREF

  va_start(va, __format);
  result = vsnprintf(__str, __size, __format, va);
  __str[__size - 1] = 0;
  return result;
}

char __cdecl I_CleanChar(char character)
{
  if (a1 == -110)
    return 39;
  else
    return a1;
}

char *__cdecl I_CleanStr(char *string)
{
  char v1;  // dl
  char *v2; // eax
  char *v3; // esi
  char *v4; // ecx
  char v5;  // bl

  v1 = *a1;
    if (*a1) {
      v2 = a1;
      v3 = a1;
        while (1) {
            if (v1 == 94) {
              v4 = v2 + 1;
              v5 = v2[1];
                if (v5 && v5 != 94 && v5 > 47 && v5 <= 57) {
                  v4 = v2 + 2;
                  v1 = v2[2];
                  if (!v1)
                    goto LABEL_14;
                  goto LABEL_7;
                }
            }
            else {
              v4 = v2 + 1;
            }
          if ((unsigned __int8)(v1 - 32) <= 0x5Eu)
            *v3++ = v1;
          v1 = *v4;
            if (!*v4) {
            LABEL_14:
              *v3 = 0;
              return a1;
            }
        LABEL_7:
          v2 = v4;
        }
    }
  *a1 = 0;
  return a1;
}

int __cdecl I_DrawStrlen(char const *str)
{
  int v2;         // ebx
  char v3;        // dl
  const char *v4; // eax
  char v6;        // dl

  v2 = 0;
LABEL_2:
  v3 = *a1;
    if (*a1) {
        do {
            if (v3 == 94) {
              v4 = a1 + 1;
              v6 = a1[1];
                if (v6 && v6 != 94 && v6 > 47 && v6 <= 57) {
                  a1 += 2;
                  goto LABEL_2;
                }
            }
            else {
              v4 = a1 + 1;
            }
          ++v2;
          a1 = v4;
          v3 = *v4;
        }
      while (*v4);
    }
  return v2;
}

void __cdecl I_strncpyz(char *dest, char const *src, int destsize)
{
  char *result; // eax

  result = strncpy(__dst, __src, a3 - 1);
  __dst[a3 - 1] = 0;
  return result;
}

bool __cdecl I_isdigit(int c)
{
  return (unsigned int)(a1 - 48) <= 9;
}

bool __cdecl I_isalpha(int)
{
  UNIMPLEMENTED();
}

bool __cdecl I_isupper(int c)
{
  return (unsigned int)(a1 - 65) <= 0x19;
}

bool __cdecl I_islower(int c)
{
  return (unsigned int)(a1 - 97) <= 0x19;
}

bool __cdecl I_isprint(int)
{
  UNIMPLEMENTED();
}

int __cdecl FloatWriteSwap(float f)
{
  unsigned __int16 v1; // ax

  LOBYTE(v1) = HIBYTE(a1);
  HIBYTE(v1) = BYTE2(a1);
  return (LODWORD(a1) << 24) | (BYTE1(a1) << 16) & 0xFFFFFF | v1;
}

float __cdecl FloatReadSwap(int n)
{
  unsigned __int16 v1; // ax

  LOBYTE(v1) = HIBYTE(a1);
  HIBYTE(v1) = BYTE2(a1);
  return COERCE_FLOAT((a1 << 24) | (BYTE1(a1) << 16) & 0xFFFFFF | v1);
}

unsigned __int64 __cdecl Long64NoSwap(unsigned __int64 ll)
{
  return a1;
}

unsigned __int64 __cdecl Long64Swap(unsigned __int64 l)
{
  __int64 v1; // rax
  __int64 v2; // rcx
  __int64 v3; // rax
  __int64 v4; // rax

  LODWORD(v1) = 0;
  HIDWORD(v1) = (unsigned __int8)a1 << 24;
  LODWORD(v2) = 0;
  HIDWORD(v2) = BYTE1(a1) << 16;
  v3 = v2 + v1;
  LODWORD(v2) = 0;
  HIDWORD(v2) = BYTE2(a1) << 8;
  v4 = v2 + v3;
  HIDWORD(v2) = BYTE3(a1);
  LODWORD(v2) = 0;
  return HIBYTE(a1) + ((unsigned __int64)BYTE6(a1) << 8) +
         ((unsigned __int64)BYTE5(a1) << 16) +
         ((unsigned __int64)BYTE4(a1) << 24) + v2 + v4;
}

int __cdecl LongNoSwap(int l)
{
  return a1;
}

int __cdecl LongSwap(int l)
{
  return HIBYTE(a1) + ((a1 >> 8) & 0xFF00) + (BYTE1(a1) << 16) + (a1 << 24);
}

short __cdecl ShortNoSwap(short l)
{
  return a1;
}

short __cdecl ShortSwap(short l)
{
  return (__int16)__ROL2__(a1, 8);
}

int __cdecl LittleFloatWrite_Util(float)
{
  UNIMPLEMENTED();
}

float __cdecl LittleFloatRead_Util(int)
{
  UNIMPLEMENTED();
}

unsigned __int64 __cdecl LittleLong64(unsigned __int64)
{
  UNIMPLEMENTED();
}

void __cdecl Com_DefaultExtension(char *path, int maxSize,
                                  char const *extension)
{
  unsigned int v3; // kr04_4
  int result;      // eax
  char *i;         // edx
  char v6;         // cl
  char __dst[88];  // [esp+20h] [ebp-58h] BYREF

  v3 = strlen(__src) + 1;
  result = (unsigned __int8)__src[v3 - 2];
    if ((_BYTE)result == 47 || __src == &__src[v3 - 2]) {
    LABEL_9:
      strncpy(__dst, __src, 0x3Fu);
      __dst[63] = 0;
      return Com_sprintf(__src, __size, "%s%s", __dst, a3);
    }
    if ((_BYTE)result != 46) {
        for (i = &__src[v3 - 2];; --i) {
          v6 = *(i - 1);
          if (v6 == 47)
            break;
          result = (int)(__src + 1);
          if (i == __src + 1)
            break;
          if (v6 == 46)
            return result;
        }
      goto LABEL_9;
    }
  return result;
}

char const *__cdecl Com_GetExtensionSubString(char const *filename)
{
  const char *result; // eax
  char v2;            // dl
  const char *v3;     // ecx

  result = a1;
  v2 = *a1;
    if (*a1) {
      v3 = 0;
        do {
            while (v2 == 46) {
              v3 = result++;
              v2 = *result;
              if (!*result)
                goto LABEL_8;
            }
          if (v2 == 47 || v2 == 92)
            v3 = 0;
          v2 = *++result;
        }
      while (*result);
    LABEL_8:
      if (v3)
        return v3;
    }
  return result;
}

char *__cdecl Com_SkipPath(char *pathname)
{
  char *result; // eax
  char v2;      // dl
  char *v3;     // ecx

  result = a1;
  v2 = *a1;
    if (*a1) {
      v3 = a1;
        do {
            while (v2 != 47) {
              v2 = *++result;
              if (!*result)
                return v3;
            }
          v3 = ++result;
          v2 = *result;
        }
      while (*result);
      return v3;
    }
  return result;
}

unsigned char __cdecl ColorIndex(unsigned char c)
{
  int result; // eax

  LOBYTE(result) = a1 - 48;
  if ((unsigned __int8)(a1 - 48) > 9u)
    return 7;
  else
    return (unsigned __int8)result;
}

float __cdecl UnGetLeanFraction(float fFrac)
{
  return (float)(1.0 - fsqrt(1.0 - a1));
}

void __cdecl Info_SetValueForKey(char *s, char const *key, char const *value)
{
  int v3;          // ecx
  int i;           // edx
  char v5;         // al
  char v6[1024];   // [esp+30h] [ebp-818h] BYREF
  char __s2[1048]; // [esp+430h] [ebp-418h] BYREF

    if (strlen(__s1) > 0x3FF) {
      Com_Printf("\x15Info_SetValueForKey: oversize infostring");
    }
    else {
      v3 = 0;
        for (i = 1; i != 1024; ++i) {
          v5 = a3[i - 1];
          if (!v5)
            break;
          if (v5 != 92 && v5 != 59 && v5 != 34)
            v6[v3++] = v5;
        }
      v6[v3] = 0;
        if (strchr(__s, 92)) {
          Com_Printf("\x15Can't use keys with a \\\nkey: '%s'\nvalue: '%s'",
                     __s, a3);
        }
        else if (strchr(__s, 59)) {
          Com_Printf(
              "\x15Can't use keys with a semicolon\nkey: '%s'\nvalue: '%s'",
              __s, a3);
        }
        else if (strchr(__s, 34)) {
          Com_Printf("\x15Can't use keys with a \"\nkey: '%s'\nvalue: '%s'",
                     __s, a3);
        }
        else {
          Info_RemoveKey(__s1, __s);
            if (v6[0]) {
                if (Com_sprintf(__s2, 0x400u, "\\%s\\%s", __s, v6) <= 0) {
                  Com_Printf("\x15Info buffer length exceeded, not including "
                             "key/value "
                             "pair in response\n");
                }
                else if (strlen(__s1) + 1 + strlen(__s2) + 1 - 2 <= 0x400) {
                  strcat(__s1, __s2);
                }
                else {
                  Com_Printf(
                      "\x15Info string length exceeded\nkey: '%s'\nvalue: "
                      "'%s'\nInfo string:\n%s\n",
                      __s, a3, __s1);
                }
            }
        }
    }
}

va_info_t va_info[NUMTHREADS];
jmp_buf g_com_error[NUMTHREADS];
TraceThreadInfo g_traceThreadInfo[NUMTHREADS];

void Com_InitThreadData(int threadContext)
{
  Sys_SetValue(THREAD_VALUE_VA, &va_info[threadContext]);
  Sys_SetValue(THREAD_VALUE_COM_ERROR, &g_com_error[threadContext]);
  Sys_SetValue(THREAD_VALUE_TRACE, &g_traceThreadInfo[threadContext]);
}

void __cdecl I_strncat(char *dest, int size, char const *src)
{
  signed int v3; // ebx
  int v4;        // esi
  char *v5;      // ebx
  char *result;  // eax
  char v7;       // [esp+8h] [ebp-20h]

  v3 = strlen(a1);
  if (v3 >= a2)
    Com_Error(0, "\x15I_strncat: already overflowed", v7);
  v4 = a2 - v3;
  v5 = &a1[v3];
  result = strncpy(v5, __src, v4 - 1);
  v5[v4 - 1] = 0;
  return result;
}

char *__cdecl I_strupr(char *s)
{
  char v1;  // dl
  char *v2; // ecx

  v1 = *a1;
    if (*a1) {
      v2 = a1;
        do {
          if ((unsigned int)(v1 - 97) <= 0x19)
            *v2 = v1 - 32;
          v1 = *++v2;
        }
      while (v1);
    }
  return a1;
}

char *__cdecl I_strlwr(char *s)
{
  char v1;  // dl
  char *v2; // ecx

  v1 = *a1;
    if (*a1) {
      v2 = a1;
        do {
          if ((unsigned int)(v1 - 65) <= 0x19)
            *v2 = v1 + 32;
          v1 = *++v2;
        }
      while (v1);
    }
  return a1;
}

bool __cdecl I_isalnum(int)
{
  UNIMPLEMENTED();
}

int __cdecl FloatWriteNoSwap(float f)
{
  return LODWORD(a1);
}

float __cdecl FloatReadNoSwap(int n)
{
  return *(float *)&a1;
}

void __cdecl Com_StripFilename(char const *, char *)
{
  UNIMPLEMENTED();
}

void __cdecl Com_StripExtension(char const *in, char *out)
{
  char v3;        // dl
  const char *v4; // ecx
  const char *v5; // edx
  const char *v6; // eax

  v3 = *a1;
    if (*a1) {
      v4 = a1;
      v6 = 0;
        do {
            while (v3 == 46) {
              v6 = v4++;
              v3 = *v4;
              if (!*v4)
                goto LABEL_13;
            }
          if (v3 == 47 || v3 == 92)
            v6 = 0;
          v3 = *++v4;
        }
      while (*v4);
    LABEL_13:
      if (v6)
        v4 = v6;
    }
    else {
      v4 = a1;
    }
    if (v4 != a1) {
      v5 = a1;
      do
        *a2++ = *v5++;
      while (v5 != v4);
    }
  *a2 = 0;
}

bool __cdecl I_isforfilename(int c)
{
  _BOOL4 v1;     // eax
  _BOOL4 result; // eax

  v1 = (unsigned int)(a1 - 97) <= 0x19 || (unsigned int)(a1 - 65) <= 0x19;
  result = v1 || (unsigned int)(a1 - 48) <= 9;
  if (result || a1 == 95 || a1 == 45)
    return 1;
  return result;
}

float __cdecl GetLeanFraction(float)
{
  return (float)(a1 * (float)(2.0 - fabs(a1)));
}

char *__cdecl Info_ValueForKey(char const *s, char const *key)
{
  const char *v2;  // ebx
  char v3;         // al
  char *v4;        // edx
  char v6;         // al
  char *v7;        // edx
  const char *v8;  // ebx
  char *v9;        // esi
  int v10;         // ecx
  int v11;         // edi
  char v12;        // [esp+8h] [ebp-2030h]
  int v13;         // [esp+14h] [ebp-2024h]
  int v14;         // [esp+18h] [ebp-2020h]
  _BYTE *v15;      // [esp+1Ch] [ebp-201Ch]
  _BYTE v16[8216]; // [esp+20h] [ebp-2018h] BYREF
  int savedregs;   // [esp+2038h] [ebp+0h] BYREF

  v2 = a1;
  if (!a1 || !a2)
    return &inData;
  if (strlen(a1) > 0x1FFF)
    Com_Error(1, "\x15Info_ValueForKey: oversize infostring", v12);
  v13 = Info_ValueForKey(char const *, char const *)::valueindex ^ 1;
  Info_ValueForKey(char const *, char const *)::valueindex ^= 1u;
  if (*a1 == 92)
    v2 = a1 + 1;
LABEL_7:
  v3 = *v2;
    if (*v2 != 92) {
        if (v3) {
          v4 = v16;
            while (1) {
              *v4++ = v3;
              v3 = *++v2;
              if (*v2 == 92)
                break;
              if (!v3)
                return &inData;
            }
          goto LABEL_15;
        }
      return &inData;
    }
  v4 = v16;
LABEL_15:
  *v4 = 0;
  v15 = v2 + 1;
  v14 = (v13 << 13) + 3362688;
  v6 = v2[1];
    if (v6 != 92 && v6) {
      v7 = (char *)((v13 << 13) + 3362688);
        do {
          *v7++ = v6;
          v6 = *++v15;
        }
      while (*v15 != 92 && v6);
    }
    else {
      v7 = (char *)((v13 << 13) + 3362688);
    }
  *v7 = 0;
  v8 = a2;
  v9 = v16;
    do {
      v10 = *v8++;
      v11 = *v9++;
      if (v9 == (char *)(&savedregs + 536868858))
        break;
        if (v10 != v11) {
          if ((unsigned int)(v10 - 97) <= 0x19)
            v10 -= 32;
          if ((unsigned int)(v11 - 97) <= 0x19)
            v11 -= 32;
            if (v11 != v10) {
              if (!*v15)
                return &inData;
              v2 = v15 + 1;
              goto LABEL_7;
            }
        }
    }
  while (v10);
  return (const gentity_s *)v14;
}

void __cdecl AddLeanToPosition(float *const position, float fViewYaw,
                               float fLeanFrac, float fViewRoll,
                               float fLeanDist)
{
  float v5;    // xmm1_4
  float v6;    // xmm1_4
  float v7[3]; // [esp+28h] [ebp-20h] BYREF
  float v8[5]; // [esp+34h] [ebp-14h] BYREF

    if (a3 != 0.0) {
      v5 = (float)(2.0 - fabs(a3)) * a3;
      v7[0] = 0.0;
      v7[1] = a2;
      v7[2] = a4 * v5;
      AngleVectors(v7, 0, v8, 0);
      v6 = v5 * a5;
      *a1 = (float)(v6 * v8[0]) + *a1;
      a1[1] = (float)(v6 * v8[1]) + a1[1];
      a1[2] = (float)(v6 * v8[2]) + a1[2];
    }
}

int __cdecl ParseConfigStringToStruct(
    unsigned char *, struct cspField_t const *, int, char const *, int,
    int(__cdecl *)(unsigned char *, char const *, int),
    void(__cdecl *)(unsigned char *, char const *))
{
  UNIMPLEMENTED();
}

void __cdecl Info_RemoveKey_Big(char *s, char const *key)
{
  UNIMPLEMENTED();
}

void __cdecl Com_AssembleFilepath(char const *, char const *, char const *,
                                  char *, int)
{
  UNIMPLEMENTED();
}

void __cdecl Info_SetValueForKey_Big(char *s, char const *key,
                                     char const *value)
{
  int v3;          // ecx
  int i;           // edx
  char v5;         // al
  char *result;    // eax
  char v7[8192];   // [esp+30h] [ebp-4018h] BYREF
  char __s2[8216]; // [esp+2030h] [ebp-2018h] BYREF

  if (strlen(__s1) > 0x1FFF)
    return (char *)Com_Printf("\x15Info_SetValueForKey: oversize infostring");
  v3 = 0;
    for (i = 1; i != 0x2000; ++i) {
      v5 = a3[i - 1];
      if (!v5)
        break;
      if (v5 != 92 && v5 != 59 && v5 != 34)
        v7[v3++] = v5;
    }
  v7[v3] = 0;
  if (strchr(__s, 92))
    return (char *)Com_Printf(
        "\x15Can't use keys with a \\\nkey: '%s'\nvalue: '%s'", __s, a3);
  if (strchr(__s, 59))
    return (char *)Com_Printf(
        "\x15Can't use keys with a semicolon\nkey: '%s'\nvalue: '%s'", __s, a3);
  if (strchr(__s, 34))
    return (char *)Com_Printf(
        "\x15Can't use keys with a \"\nkey: '%s'\nvalue: '%s'", __s, a3);
  result = (char *)Info_RemoveKey_Big(__s1, __s);
    if (v7[0]) {
        if ((int)Com_sprintf(__s2, 0x2000u, "\\%s\\%s", __s, v7) <= 0) {
          return (char *)Com_Printf("\x15Info buffer length exceeded, not "
                                    "including key/value pair in response\n");
        }
        else if (strlen(__s1) + 1 + strlen(__s2) + 1 - 2 <= 0x400) {
          return strcat(__s1, __s2);
        }
        else {
          return (char *)Com_Printf("\x15Info string length exceeded\nkey: "
                                    "'%s'\nvalue: '%s'\nInfo string:\n%s\n",
                                    __s, a3, __s1);
        }
    }
  return result;
}

int marker_q_shared;
struct TraceThreadInfo *g_traceThreadInfo;
