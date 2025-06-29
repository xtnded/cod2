char const *__cdecl GetBspExtension()
{
  UNIMPLEMENTED();
}

void __cdecl FS_ConvertPath(char *s)
{
  char *v1;   // edx
  int result; // eax

  v1 = a1;
    for (result = (unsigned __int8)*a1; (_BYTE)result; ++v1) {
        while ((_BYTE)result != 92 && (_BYTE)result != 58) {
          result = (unsigned __int8)*++v1;
          if (!(_BYTE)result)
            return result;
        }
      *v1 = 47;
      result = (unsigned __int8)v1[1];
    }
  return result;
}

void __cdecl FS_ResetFiles()
{
  fs_loadStack = 0;
}

void __cdecl FS_Printf(int h, char const *fmt, ...)
{
  char *v2;         // ebx
  size_t result;    // eax
  unsigned int v4;  // ecx
  size_t v5;        // edi
  int v6;           // [esp+18h] [ebp-1030h]
  FILE *v7;         // [esp+1Ch] [ebp-102Ch]
  char __str[4096]; // [esp+2Ch] [ebp-101Ch] BYREF
  va_list v9;       // [esp+102Ch] [ebp-1Ch]
  va_list va;       // [esp+1058h] [ebp+10h] BYREF

  va_start(va, __format);
  va_copy(v9, va);
  v2 = __str;
  vsnprintf(__str, 0x1000u, __format, va);
  result = 0;
  v4 = strlen(__str) + 1;
  v5 = v4 - 1;
    if (a1) {
      v7 = *(&fsh + 71 * a1);
        if (v4 != 1) {
          v6 = 0;
            do {
              result = FS_FileWrite(v2, 1u, v5, v7);
                if (result) {
                  if (result == -1)
                    return result;
                }
                else {
                  if (v6)
                    return result;
                  v6 = 1;
                }
              v2 += result;
              v5 -= result;
            }
          while (v5);
        }
      result = 71 * a1;
      if (dword_FF8248[71 * a1])
        return fflush(v7);
    }
  return result;
}

int __cdecl FS_Write(void const *buffer, int len, int h)
{
  size_t v5; // ebx
  size_t v6; // eax
  int v7;    // [esp+18h] [ebp-20h]
  FILE *v8;  // [esp+1Ch] [ebp-1Ch]

  if (!a3)
    return 0;
  v8 = *(&fsh + 71 * a3);
    if (a2) {
      v5 = a2;
      v7 = 0;
        do {
          v6 = FS_FileWrite(a1, 1u, v5, v8);
            if (v6) {
              if (v6 == -1)
                return 0;
            }
            else {
              if (v7)
                return 0;
              v7 = 1;
            }
          a1 += v6;
          v5 -= v6;
        }
      while (v5);
    }
  if (dword_FF8248[71 * a3])
    fflush(v8);
  return a2;
}

int __cdecl FS_Delete(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl FS_CreatePath(char *)
{
  char v2;  // al
  char *v3; // esi

    if (strstr(__big, "..") || strstr(__big, "::")) {
      Com_Printf("WARNING: refusing to create relative path \"%s\"\n", __big);
      return 1;
    }
    else {
      v2 = __big[1];
        if (v2) {
          v3 = __big + 1;
            do {
                if (v2 == 47) {
                  *v3 = 0;
                  Sys_Mkdir(__big);
                  *v3 = 47;
                }
              v2 = *++v3;
            }
          while (v2);
        }
      return 0;
    }
}

struct _iobuf *__cdecl FS_FileForHandle(int f)
{
  return (int)*(&fsh + 71 * a1);
}

long __cdecl FS_HashFileName(char const *fname, int hashSize)
{
  char v2; // al
  int v4;  // esi
  int v5;  // ebx
  int v6;  // eax
  int v7;  // edx

  v2 = *a1;
  if (!*a1)
    return 0;
  v4 = 0;
  v5 = 119;
    do {
      v6 = __tolower(v2);
      v7 = v6;
      if (v6 == 46)
        break;
      if (v6 == 92)
        v7 = 47;
      v4 += v5 * v7;
      v2 = a1[v5++ - 118];
    }
  while (v2);
  return (a2 - 1) & ((v4 >> 10) ^ v4 ^ (v4 >> 20));
}

int __cdecl FS_LoadStack()
{
  return fs_loadStack;
}

void __cdecl FS_CheckFileSystemStarted()
{
  ;
}

void __cdecl FS_Flush(int f)
{
  return fflush(*(&fsh + 71 * a1));
}

int __cdecl FS_FTell(int f)
{
  if (dword_FF8254[71 * a1])
    return unztell((int)*(&fsh + 71 * a1));
  else
    return ftell(*(&fsh + 71 * a1));
}

int __cdecl FS_Seek(int f, long offset, int origin)
{
  unsigned __int8 *v3; // eax
  int v5;              // edx
  int v6;              // [esp+1Ch] [ebp-1Ch]

    if (dword_FF8258[71 * a1]) {
      dword_FF8258[71 * a1] = 0;
      Sys_StreamSeek(a1, a2, a3);
      dword_FF8258[71 * a1] = 1;
        if (dword_FF8254[71 * a1]) {
        LABEL_3:
            if (!a2) {
                if (a3 == 2) {
                  unzSetCurrentFileInfoPosition(*(&fsh + 71 * a1),
                                                dword_FF8250[71 * a1]);
                  return unzOpenCurrentFile((int)*(&fsh + 71 * a1));
                }
              if (!a3)
                return 0;
            }
          v6 = unztell((int)*(&fsh + 71 * a1));
            if (a3) {
                if (a3 == 1) {
                    if (v6 > (int)&FS_filelength(a1)[a2]) {
                      unzSetCurrentFileInfoPosition(*(&fsh + 71 * a1),
                                                    dword_FF8250[71 * a1]);
                      unzOpenCurrentFile((int)*(&fsh + 71 * a1));
                      v3 = &FS_filelength(a1)[a2];
                    }
                    else {
                      v3 = &FS_filelength(a1)[a2 - v6];
                    }
                LABEL_12:
                  if (unzReadCurrentFile((int)*(&fsh + 71 * a1), 0,
                                         (unsigned int)v3))
                    return 0;
                  return -1;
                }
              if (a3 != 2)
                return -1;
                if (a2 >= v6) {
                  v3 = (unsigned __int8 *)(a2 - v6);
                  goto LABEL_12;
                }
              unzSetCurrentFileInfoPosition(*(&fsh + 71 * a1),
                                            dword_FF8250[71 * a1]);
              unzOpenCurrentFile((int)*(&fsh + 71 * a1));
            }
            else if (a2 < 0) {
              unzSetCurrentFileInfoPosition(*(&fsh + 71 * a1),
                                            dword_FF8250[71 * a1]);
              unzOpenCurrentFile((int)*(&fsh + 71 * a1));
              v3 = (unsigned __int8 *)(v6 + a2);
              goto LABEL_12;
            }
          v3 = (unsigned __int8 *)a2;
          goto LABEL_12;
        }
    }
    else if (dword_FF8254[71 * a1]) {
      goto LABEL_3;
    }
    if (a3 == 1) {
      v5 = 2;
    }
    else if (a3 == 2) {
      v5 = 0;
    }
    else {
      if (a3)
        return 0;
      v5 = 1;
    }
  return FS_FileSeek(*(&fsh + 71 * a1), a2, v5);
}

void __cdecl FS_FCloseFile(int h)
{
  int v1; // ebx

  v1 = 284 * a1;
  if (dword_FF8258[71 * a1])
    Sys_EndStreamedFile();
    if (dword_FF8254[71 * a1]) {
      unzCloseCurrentFile((int)*(&fsh + 71 * a1));
      if (!dword_FF8244[71 * a1])
        return Com_Memset((char *)&fsh + v1, 0, 0x11Cu);
      unzClose((FILE **)*(&fsh + 71 * a1));
      return Com_Memset((char *)&fsh + v1, 0, 0x11Cu);
    }
    else {
      if (!a1)
        return Com_Memset((char *)&fsh + v1, 0, 0x11Cu);
      FS_FileClose(*(&fsh + 71 * a1));
      return Com_Memset((char *)&fsh + v1, 0, 0x11Cu);
    }
}

int __cdecl FS_filelength(int f)
{
  FILE *v2;   // ebx
  __int32 v3; // edi
  __int32 v4; // esi

  if (dword_FF8254[71 * a1])
    return (*(&fsh + 71 * a1))->_lb._base;
  v2 = *(&fsh + 71 * a1);
  v3 = ftell(v2);
  FS_FileSeek(v2, 0, 2);
  v4 = ftell(v2);
  FS_FileSeek(v2, v3, 0);
  return (unsigned __int8 *)v4;
}

int __cdecl FS_Read(void *buffer, int len, int h)
{
  char *v4;  // edi
  size_t v5; // esi
  size_t v6; // eax
  size_t v7; // ebx
  char v8;   // [esp+8h] [ebp-30h]
  int v9;    // [esp+18h] [ebp-20h]
  FILE *v10; // [esp+1Ch] [ebp-1Ch]

  if (!a3)
    return 0;
  if (dword_FF8254[71 * a3])
    return unzReadCurrentFile((int)*(&fsh + 71 * a3), (int)a1, a2);
  v10 = *(&fsh + 71 * a3);
  v4 = a1;
  if (!a2)
    return a2;
  v5 = a2;
  v9 = 0;
    while (1) {
      v6 = FS_FileRead(v4, 1u, v5, v10);
      v7 = v6;
      if (v6)
        break;
      if (v9)
        return a2 - v5;
      v9 = 1;
    LABEL_10:
      v4 += v7;
      v5 -= v7;
      if (!v5)
        return a2;
    }
  if (v6 != -1)
    goto LABEL_10;
    if ((unsigned int)(a3 - 61) > 0xC) {
      Com_Error(0, "\x15FS_Read: -1 bytes read", v8);
      goto LABEL_10;
    }
  return -1;
}

void __cdecl FS_BuildOSPath(char const *base, char const *game,
                            char const *qpath, char *const ospath)
{
  return FS_BuildOSPath_Internal(a1, a2, a3, a4, 0);
}

int __cdecl FS_FOpenFileAppend(char const *filename)
{
  int v1;         // ebx
  FILE **v2;      // eax
  char v4;        // al
  char *p_big;    // edi
  const char *v6; // esi
  FILE *v7;       // eax
  int v8;         // edx
  char v9;        // [esp+8h] [ebp-120h]
  char __big;     // [esp+10h] [ebp-118h] BYREF
  char v11;       // [esp+11h] [ebp-117h]

  v1 = 0;
  v2 = &fsh;
    while (1) {
      ++v1;
      if (!v2[71])
        break;
      v2 += 71;
        if (v1 == 60) {
          LOBYTE(v1) = 1;
          v6 = (const char *)&unk_FF8378;
            do {
              Com_Printf("FILE %2i: '%s'\n", v1++, v6);
              v6 += 284;
            }
          while (v1 != 74);
          Com_Error(1, "\x15FS_HandleForFile: none free", v9);
          v1 = -1;
          break;
        }
    }
  dword_FF8254[71 * v1] = 0;
  I_strncpyz((char *)(284 * v1 + 16745052), __src, 256);
  FS_BuildOSPath_Internal(*(const char **)(fs_homepath + 8), fs_gamedir, __src,
                          &__big, 0);
    if (*(_DWORD *)(fs_debug + 8)) {
      Com_Printf("FS_FOpenFileAppend: %s\n", &__big);
      if (strstr(&__big, ".."))
        goto LABEL_6;
    }
    else if (strstr(&__big, "..")) {
    LABEL_6:
      Com_Printf("WARNING: refusing to create relative path \"%s\"\n", &__big);
      return 0;
    }
  if (strstr(&__big, "::"))
    goto LABEL_6;
  v4 = v11;
    if (v11) {
      p_big = &__big;
        do {
            if (v4 == 47) {
              p_big[1] = 0;
              Sys_Mkdir(&__big);
              p_big[1] = 47;
            }
          v4 = p_big[2];
          ++p_big;
        }
      while (v4);
    }
  v7 = FS_FileOpen(&__big, "at");
  v8 = 71 * v1;
  *(FILE **)((char *)&fsh + v8 * 4) = v7;
  dword_FF8248[v8] = 0;
  if (!v7)
    return 0;
  return v1;
}

int __cdecl FS_FOpenTextFileWrite(char const *filename)
{
  int v1;         // esi
  FILE **v2;      // eax
  char v4;        // al
  char *p_big;    // edi
  int v6;         // ebx
  const char *v7; // esi
  char v8;        // [esp+8h] [ebp-120h]
  char __big;     // [esp+10h] [ebp-118h] BYREF
  char v10;       // [esp+11h] [ebp-117h]

  v1 = 0;
  v2 = &fsh;
    while (1) {
      ++v1;
      if (!v2[71])
        break;
      v2 += 71;
        if (v1 == 60) {
          v6 = 1;
          v7 = (const char *)&unk_FF8378;
            do {
              Com_Printf("FILE %2i: '%s'\n", v6++, v7);
              v7 += 284;
            }
          while (v6 != 74);
          Com_Error(1, "\x15FS_HandleForFile: none free", v8);
          v1 = -1;
          break;
        }
    }
  dword_FF8254[71 * v1] = 0;
  FS_BuildOSPath_Internal(*(const char **)(fs_homepath + 8), fs_gamedir, __src,
                          &__big, 0);
    if (*(_DWORD *)(fs_debug + 8)) {
      Com_Printf("FS_FOpenFileWrite: %s\n", &__big);
      if (strstr(&__big, ".."))
        goto LABEL_6;
    }
    else if (strstr(&__big, "..")) {
    LABEL_6:
      Com_Printf("WARNING: refusing to create relative path \"%s\"\n", &__big);
      return 0;
    }
  if (strstr(&__big, "::"))
    goto LABEL_6;
  v4 = v10;
    if (v10) {
      p_big = &__big;
        do {
            if (v4 == 47) {
              p_big[1] = 0;
              Sys_Mkdir(&__big);
              p_big[1] = 47;
            }
          v4 = p_big[2];
          ++p_big;
        }
      while (v4);
    }
  *(&fsh + 71 * v1) = FS_FileOpen(&__big, "wt");
  I_strncpyz(&byte_FF825C[284 * v1], __src, 256);
  dword_FF8248[71 * v1] = 0;
  if (!*(&fsh + 71 * v1))
    return 0;
  return v1;
}

int __cdecl FS_FOpenFileWrite(char const *filename)
{
  int v1;         // esi
  char v3;        // al
  char *p_big;    // esi
  FILE *v5;       // edi
  FILE **v6;      // eax
  int v7;         // ebx
  int v8;         // ebx
  const char *v9; // esi
  char v10;       // [esp+8h] [ebp-120h]
  char __big;     // [esp+10h] [ebp-118h] BYREF
  char v12;       // [esp+11h] [ebp-117h]

  FS_BuildOSPath_Internal(*(const char **)(fs_homepath + 8), fs_gamedir, __src,
                          &__big, 0);
    if (*(_DWORD *)(fs_debug + 8)) {
      Com_Printf("FS_FOpenFileWrite: %s\n", &__big);
      if (strstr(&__big, ".."))
        goto LABEL_3;
    }
    else if (strstr(&__big, "..")) {
    LABEL_3:
      Com_Printf("WARNING: refusing to create relative path \"%s\"\n", &__big);
      return 0;
    }
  if (strstr(&__big, "::"))
    goto LABEL_3;
  v3 = v12;
    if (v12) {
      p_big = &__big;
        do {
            if (v3 == 47) {
              p_big[1] = 0;
              Sys_Mkdir(&__big);
              p_big[1] = 47;
            }
          v3 = p_big[2];
          ++p_big;
        }
      while (v3);
    }
  v5 = FS_FileOpen(&__big, "wb");
  if (!v5)
    return 0;
  v1 = 0;
  v6 = &fsh;
    while (1) {
      ++v1;
      if (!v6[71])
        break;
      v6 += 71;
        if (v1 == 60) {
          v8 = 1;
          v9 = (const char *)&unk_FF8378;
            do {
              Com_Printf("FILE %2i: '%s'\n", v8++, v9);
              v9 += 284;
            }
          while (v8 != 74);
          Com_Error(1, "\x15FS_HandleForFile: none free", v10);
          v1 = -1;
          break;
        }
    }
  v7 = 71 * v1;
  dword_FF8254[v7] = 0;
  *(FILE **)((char *)&fsh + v7 * 4) = v5;
  I_strncpyz(&byte_FF825C[284 * v1], __src, 256);
  dword_FF8248[71 * v1] = 0;
  return v1;
}

int __cdecl FS_FOpenFileRead(char const *filename, int *file, int uniqueFILE)
{
  char *ExtensionSubString; // eax
  int Internal;             // edx

  com_fileAccessed = 1;
  ExtensionSubString = (char *)Com_GetExtensionSubString(a1);
  if (!FS_PureIgnoresExtension(ExtensionSubString))
    return FS_FOpenFileRead_Internal(a1, a2, a3, 0, 0);
  Internal = FS_FOpenFileRead_Internal(a1, a2, a3, 0, (int *)1);
  if (Internal == -2 || Internal == -1)
    return FS_FOpenFileRead_Internal(a1, a2, a3, 0, 0);
  else
    return Internal;
}

int __cdecl FS_FOpenFileReadStream(char const *filename, int *file,
                                   int uniqueFILE)
{
  return FS_FOpenFileRead_Internal(a1, a2, a3, (char *)1, 0);
}

int __cdecl FS_FOpenFileByMode(char const *qpath, int *f, enum fsMode_t mode)
{
  int Internal;             // ecx
  int v4;                   // esi
  int v5;                   // edx
  int v7;                   // eax
  char *ExtensionSubString; // eax
  char v9;                  // [esp+8h] [ebp-10h]

    if (a3 == FS_WRITE) {
      v7 = FS_FOpenFileWrite(__src);
      *a2 = v7;
      if (v7)
        Internal = 0;
      else
        Internal = -1;
      v4 = 0;
      v5 = *a2;
      goto LABEL_8;
    }
    if (a3 > FS_WRITE) {
        if (a3 == FS_APPEND) {
          v4 = 0;
        }
        else {
          if (a3 != FS_APPEND_SYNC)
            goto LABEL_5;
          v4 = 1;
        }
      v5 = FS_FOpenFileAppend(__src);
      *a2 = v5;
      Internal = -(v5 == 0);
      goto LABEL_8;
    }
    if (a3 == FS_READ) {
      com_fileAccessed = 1;
      ExtensionSubString = (char *)Com_GetExtensionSubString(__src);
        if (!FS_PureIgnoresExtension(ExtensionSubString) ||
            (Internal = FS_FOpenFileRead_Internal(__src, a2, 1, 0, (int *)1),
             Internal == -2 || Internal == -1)) {
          Internal = FS_FOpenFileRead_Internal(__src, a2, 1, 0, 0);
        }
      goto LABEL_6;
    }
LABEL_5:
  Com_Error(0, "\x15FSH_FOpenFile: bad mode", v9);
  Internal = 6969;
LABEL_6:
  if (!a2)
    return Internal;
  v4 = 0;
  v5 = *a2;
LABEL_8:
    if (v5) {
      dword_FF824C[71 * v5] = Internal;
      dword_FF8258[71 * *a2] = 0;
      v5 = *a2;
    }
  dword_FF8248[71 * v5] = v4;
  return Internal;
}

int __cdecl FS_WriteFile(char const *qpath, void const *buffer, int size)
{
  int v3;          // eax
  int v4;          // esi
  int v6;          // ebx
  int v8;          // ebx
  int v9;          // eax
  const char *v10; // [esp+8h] [ebp-130h]
  char *v11;       // [esp+Ch] [ebp-12Ch]
  int v12;         // [esp+10h] [ebp-128h]
  int v13;         // [esp+18h] [ebp-120h]
  FILE *v14;       // [esp+1Ch] [ebp-11Ch]
  char __dst[280]; // [esp+20h] [ebp-118h] BYREF

  v3 = FS_FOpenFileWrite(__src);
  v4 = v3;
    if (v3) {
      v14 = *(&fsh + 71 * v3);
        if (a3) {
          v8 = a3;
          v13 = 0;
            do {
              v11 = (char *)v14;
              v10 = (const char *)v8;
              v9 = FS_FileWrite(a2, 1);
                if (v9) {
                    if (v9 == -1) {
                    LABEL_16:
                      v6 = 0;
                      goto LABEL_6;
                    }
                }
                else {
                  if (v13)
                    goto LABEL_16;
                  v13 = 1;
                }
              a2 += v9;
              v8 -= v9;
            }
          while (v8);
        }
      if (dword_FF8248[71 * v4])
        fflush(v14);
      v6 = a3;
    LABEL_6:
      FS_FCloseFile(v4);
        if (v6 == a3) {
          return 1;
        }
        else {
            if (*__src) {
              FS_BuildOSPath_Internal(__dst, 0, v10, v11, v12);
              remove(__dst);
            }
          return 0;
        }
    }
    else {
      Com_Printf("Failed to open %s\n", __src);
      return 0;
    }
}

void __cdecl FS_InitFilesystem()
{
  UNIMPLEMENTED();
}

int com_fileAccessed;
int marker_com_files;
int fs_loadStack;

void __cdecl FS_ReplaceSeparators(char *)
{
  UNIMPLEMENTED();
}

int __cdecl FS_GetHandleAndOpenFile(char const *, char const *, char const *,
                                    int)
{
  UNIMPLEMENTED();
}

void __cdecl FS_BuildOSPath_Internal(char const *, char const *, char const *,
                                     char *const, int)
{
  UNIMPLEMENTED();
}

int __cdecl FS_FOpenFileRead_Internal(char const *, int *, int, int)
{
  UNIMPLEMENTED();
}

FS_Initialized()
{
  UNIMPLEMENTED();
}

FS_UseSearchPath(searchpath_s const *pSearch)
{
  UNIMPLEMENTED();
}

FS_LanguageHasAssets(int)
{
  UNIMPLEMENTED();
}

FS_HandleForFile(int streamThread)
{
  UNIMPLEMENTED();
}

FS_Remove(char const *osPath)
{
  UNIMPLEMENTED();
}

FS_FilenameCompare(char const *s1, char const *s2)
{
  UNIMPLEMENTED();
}

FS_PureIgnoresExtension(char const *extension)
{
  UNIMPLEMENTED();
}

FS_ShutdownServerIwdNames()
{
  UNIMPLEMENTED();
}

FS_ShutdownServerReferencedIwds()
{
  UNIMPLEMENTED();
}

FS_RegisterDvars()
{
  UNIMPLEMENTED();
}

FS_ClearIwdReferences()
{
  UNIMPLEMENTED();
}

FS_Shutdown(int closemfp)
{
  UNIMPLEMENTED();
}

FS_FileExists(char const *file)
{
  UNIMPLEMENTED();
}

FS_ShortOSFilePath(char const *filename)
{
  UNIMPLEMENTED();
}

FS_GetFileOsPath(char const *filename, char *ospath)
{
  UNIMPLEMENTED();
}

FS_DisplayPath(int bLanguageCull)
{
  UNIMPLEMENTED();
}

FS_Path_f()
{
  UNIMPLEMENTED();
}

FS_FullPath_f()
{
  UNIMPLEMENTED();
}

FS_ListFilteredFiles(searchpath_s *searchPath, char const *path,
                     char const *extension, char const *filter,
                     FsListBehavior_e behavior, int *numfiles,
                     int allocTrackType)
{
  UNIMPLEMENTED();
}

FS_GetFileList(char const *path, char const *extension,
               FsListBehavior_e behavior, char *listbuf, int bufsize)
{
  UNIMPLEMENTED();
}

FS_SortFileList(char const **filelist, int numfiles)
{
  UNIMPLEMENTED();
}

FS_OpenFileOverwrite(char const *qpath)
{
  UNIMPLEMENTED();
}

FS_CopyFile(char *fromOSPath, char *toOSPath)
{
  UNIMPLEMENTED();
}

FS_TouchFile(char const *name)
{
  UNIMPLEMENTED();
}

FS_Startup(char const *gameName)
{
  UNIMPLEMENTED();
}

FS_Restart(int checksumFeed)
{
  UNIMPLEMENTED();
}

FS_ConditionalRestart(int checksumFeed)
{
  UNIMPLEMENTED();
}
