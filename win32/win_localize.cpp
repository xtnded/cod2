int marker_win_localize;

int Win_InitLocalization(void)
{
  FILE *v0;             // eax
  FILE *v1;             // esi
  size_t v2;            // ebx
  size_t v3;            // ebx
  const char *language; // eax
  const char *v5;       // edx
  char v6;              // cl
  int v8[3];            // [esp+1Ch] [ebp-Ch] BYREF

  localization.language = 0;
  localization.strings = 0;
  v0 = FS_FileOpen("localization.txt", "r");
  v1 = v0;
  if (!v0)
    return 0;
  FS_FileSeek(v0, 0, 2);
  v2 = ftell(v1);
  FS_FileSeek(v1, 0, 0);
  localization.language = language_buffer;
  v3 = FS_FileRead(language_buffer, 1u, v2, v1);
  FS_FileClose(v1);
    if (!v3) {
      localization.language = 0;
      return 0;
    }
  language = localization.language;
  localization.language[v3] = '\0';
  v8[0] = 0;
    if (*language) {
        if (*language == '\n') {
        LABEL_8:
          *language = 0;
          localization.strings = language + 1;
          SEH_GetLanguageIndexForName(localization.language, v8);
        }
        else {
          v5 = language + 1;
            while (1) {
              language = v5;
              v6 = *v5;
              if (!*v5)
                break;
              ++v5;
              if (v6 == '\n')
                goto LABEL_8;
            }
        }
    }
  return v8[0];
}

Win_ShutdownLocalization()
{
  UNIMPLEMENTED();
}

Win_LocalizeRef(char const *ref)
{
  UNIMPLEMENTED();
}
