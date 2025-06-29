void __cdecl SL_Shutdown()
{
  byte_3F6680 = 0;
}

void __cdecl SL_TransferSystem(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl SL_AddRefToString(unsigned int stringValue)
{
  int result; // eax

  result = scrMemTreePub;
  ++*(_WORD *)(scrMemTreePub + 8 * a1 + 2);
  return result;
}

unsigned int __cdecl SL_FindStringOfLen(char const *str, unsigned int len)
{
  const char *v2;   // ecx
  unsigned int v3;  // ebx
  unsigned int v4;  // edx
  __int16 *v5;      // edx
  __int16 v6;       // bx
  int v8;           // eax
  __int16 *v9;      // ebx
  int v10;          // eax
  const char *v11;  // edx
  int v12;          // [esp+Ch] [ebp-2Ch]
  __int16 *v13;     // [esp+10h] [ebp-28h]
  unsigned int v14; // [esp+14h] [ebp-24h]
  unsigned int v15; // [esp+18h] [ebp-20h]
  int v16;          // [esp+1Ch] [ebp-1Ch]
  int v17;          // [esp+24h] [ebp-14h]

    if (a2 > 0xFF) {
      v15 =
          (a2 >> 2) -
          0x3FFF *
              ((unsigned int)(((unsigned int)((a2 >> 2) -
                                              ((262161 *
                                                (unsigned __int64)(a2 >> 2)) >>
                                               32)) >>
                               1) +
                              ((262161 * (unsigned __int64)(a2 >> 2)) >> 32)) >>
               13) +
          1;
      v5 = &scrStringGlob[2 * v15];
      v13 = v5;
      v6 = *v5;
      if ((*v5 & 0xC000) != 0x8000)
        return 0;
    }
    else {
        if (a2) {
          v2 = a1;
          v3 = 0;
          do
            v3 = *v2++ + 31 * v3;
          while (&a1[a2] != v2);
          v4 = v3 % 0x3FFF;
        }
        else {
          v4 = 0;
        }
      v15 = v4 + 1;
      v5 = &scrStringGlob[2 * v4 + 2];
      v13 = v5;
      v6 = *v5;
      if ((*v5 & 0xC000) != 0x8000)
        return 0;
    }
  v17 = (unsigned __int16)v5[1];
  v8 = scrMemTreePub + 8 * v17;
  if (*(_BYTE *)v8 == (_BYTE)a2 && !memcmp((const char *)(v8 + 4), a1, a2))
    return v17;
  v16 = v6 & 0x3FFF;
  v9 = &scrStringGlob[2 * v16];
  if (v13 == v9)
    return 0;
  v14 = v15;
    while (1) {
      v12 = (unsigned __int16)v9[1];
      v11 = (const char *)(scrMemTreePub + 8 * v12);
      if ((unsigned __int8)a2 == *(unsigned __int8 *)v11 &&
          !memcmp(v11 + 4, a1, a2))
        break;
      v10 = *v9 & 0x3FFF;
      v9 = &scrStringGlob[2 * v10];
      if (v13 == v9)
        return 0;
      v14 = v16;
      v16 = v10;
    }
  scrStringGlob[2 * v14] = *v9 & 0x3FFF | scrStringGlob[2 * v14] & 0xC000;
  *v9 = *v13 & 0x3FFF | *v9 & 0xC000;
  *v13 = v16 | *v13 & 0xC000;
  v17 = v12;
  v9[1] = v13[1];
  v13[1] = v12;
  return v17;
}

unsigned int __cdecl SL_ConvertFromString(char const *str)
{
  return (int)&a1[-scrMemTreePub - 4] / 8;
}

int __cdecl SL_GetStringLen(unsigned int stringValue)
{
  _BYTE *v1; // edx
  int v2;    // ecx
  int v3;    // edx
  char v4;   // al

  v1 = (_BYTE *)(scrMemTreePub + 8 * a1);
  v2 = (unsigned __int8)(*v1 - 1);
    if (v1[v2 + 4]) {
      v3 = (int)&v1[v2 + 4];
        do {
          v2 += 256;
          v4 = *(_BYTE *)(v3 + 256);
          v3 += 256;
        }
      while (v4);
    }
  return v2;
}

char const *__cdecl SL_ConvertToString(unsigned int)
{
  if (a1)
    return scrMemTreePub + 8 * a1 + 4;
  else
    return 0;
}

unsigned int __cdecl SL_FindLowercaseString(char const *str)
{
  signed int v1; // ebx
  int i;         // edi
  char v4[8216]; // [esp+10h] [ebp-2018h] BYREF

  v1 = strlen(a1) + 1;
  if (v1 > 0x2000)
    return 0;
    if (v1 > 0) {
      for (i = 0; i != v1; ++i)
        v4[i] = __tolower(a1[i]);
    }
  return SL_FindStringOfLen(v4, v1);
}

unsigned int __cdecl SL_FindString(char const *str)
{
  return SL_FindStringOfLen(a1, strlen(a1) + 1);
}

void __cdecl SL_RemoveRefToStringOfLen(unsigned int stringValue,
                                       unsigned int len)
{
  UNIMPLEMENTED();
}

void __cdecl SL_RemoveRefToString(unsigned int stringValue)
{
  UNIMPLEMENTED();
}

void __cdecl SL_ShutdownSystem(unsigned int user)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_GetStringForVector(float const *v)
{
  char __src[136]; // [esp+20h] [ebp-88h] BYREF

  sprintf(__src, "(%g, %g, %g)", *a1, a1[1], a1[2]);
  return SL_GetStringOfLen(__src, 0, strlen(__src) + 1);
}

unsigned int __cdecl SL_GetStringForInt(int i)
{
  char __src[136]; // [esp+10h] [ebp-88h] BYREF

  sprintf(__src, "%i", a1);
  return SL_GetStringOfLen(__src, 0, strlen(__src) + 1);
}

unsigned int __cdecl SL_GetStringForFloat(float f)
{
  char __src[136]; // [esp+10h] [ebp-88h] BYREF

  sprintf(__src, "%g", a1);
  return SL_GetStringOfLen(__src, 0, strlen(__src) + 1);
}

void __cdecl Scr_SetString(unsigned short *to, unsigned int from)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_GetString(char const *str, unsigned int user)
{
  return SL_GetStringOfLen(__src, a2, strlen(__src) + 1);
}

void __cdecl Scr_ShutdownGameStrings()
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_AllocString(char const *s, int sys)
{
  return SL_GetStringOfLen(__src, 1u, strlen(__src) + 1);
}

void __cdecl Scr_SetStringFromCharString(unsigned short *, char const *)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_CreateCanonicalFilename(char const *filename)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_GetLowercaseString_(char const *str, unsigned int user,
                                            int type)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_GetLowercaseString(char const *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl SL_Init()
{
  UNIMPLEMENTED();
}

int marker_scr_stringlist;

void __cdecl SL_AddUserInternal(class RefString *, unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetHashCode(char const *, unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_ConvertFromRefString(class RefString *)
{
  UNIMPLEMENTED();
}

int __cdecl SL_GetRefStringLen(class RefString *)
{
  UNIMPLEMENTED();
}

class RefString *__cdecl GetRefString(char const *)
{
  UNIMPLEMENTED();
}

class RefString *__cdecl GetRefString(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl SL_Clear(void)
{
  UNIMPLEMENTED();
}

void __cdecl SL_FreeString(unsigned int, class RefString *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl SL_RemoveAllRefToString(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl CreateCanonicalFilename(char *, char const *, int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl SL_GetLowercaseStringOfLen(char const *, unsigned int,
                                                unsigned int, int)
{
  UNIMPLEMENTED();
}

void __cdecl SL_Restart(void)
{
  UNIMPLEMENTED();
}
