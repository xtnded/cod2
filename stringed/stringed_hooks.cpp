char const *__cdecl SEH_GetLanguageName(int iLanguage) {
  if (a1 <= 0xD)
    return *(_DWORD *)&g_languages[8 * a1];
  else
    return *(_DWORD *)g_languages;
}

int __cdecl Language_IsAsian(void) { UNIMPLEMENTED(); }

int __cdecl SEH_VerifyLanguageSelection(int iLanguageSelection) {
  int v1; // edi
  int v2; // esi

  v1 = a1;
  if (dword_308BC4[2 * a1])
    return v1;
  v2 = 0;
  while (!dword_308BC4[2 * ((v2 + a1) % 14)]) {
    if (++v2 == 14)
      return 0;
  }
  return (v2 + a1) % 14;
}

int __cdecl SEH_GetCurrentLanguage() { return loc_language->current; }

int __cdecl Language_UsesSpaces(void) { UNIMPLEMENTED(); }

int __cdecl Taiwanese_CollapseBig5Code(unsigned int) { UNIMPLEMENTED(); }

int __cdecl SEH_GetLanguageIndexForName(char const *pszLanguageName,
                                        int *piLanguageIndex) {
  int v2;   // esi
  char **i; // ebx

  v2 = 0;
  for (i = (char **)g_languages; I_stricmp(a1, *i); i += 2) {
    if (++v2 == 14) {
      *a2 = 0;
      return 0;
    }
  }
  *a2 = v2;
  return 1;
}

unsigned int __cdecl SEH_ReadCharFromString(char const **ppsText,
                                            int *pbIsTrailingPunctuation) {
  unsigned __int8 *v2; // ecx
  DvarValue current;   // eax
  char v4;             // dl
  int v5;              // ebx
  _BOOL4 v6;           // eax
  int v8;              // edx
  int v10;             // ebx
  unsigned __int8 v12; // [esp+3h] [ebp-15h]
  int v13;             // [esp+8h] [ebp-10h]

  v2 = (unsigned __int8 *)*a1;
  if (!g_currentAsian)
    goto LABEL_6;
  current = loc_language->current;
  if (current.integer == 9) {
    v5 = (*v2 << 8) + v2[1];
    if ((unsigned __int8)(BYTE1(v5) + 95) > 0x25u &&
            (unsigned __int8)(BYTE1(v5) + 55) > 0x30u ||
        (unsigned __int8)(v2[1] - 64) > 0x3Eu &&
            (unsigned __int8)(v5 + 95) > 0x5Du) {
      goto LABEL_6;
    }
    *a1 = (const char *)(v2 + 2);
    if (a2)
      *a2 = (unsigned int)(v5 - 41280) <= 0x13;
  } else {
    if (current.integer > 9) {
      if (current.integer != 10) {
        if (current.integer == 11) {
          v5 = (*v2 << 8) + v2[1];
          if ((unsigned __int8)(BYTE1(v5) + 95) <= 0x56u && v2[1] > 0xA0u &&
              v2[1] != 0xFF) {
            *a1 = (const char *)(v2 + 2);
            if (a2)
              *a2 = (unsigned int)(v5 - 41377) <= 0xC;
            return v5;
          }
        }
        goto LABEL_6;
      }
      v10 = *v2;
      v12 = v2[1];
      if (((unsigned __int8)(v10 + 127) <= 0x1Eu ||
           (unsigned __int8)(v10 + 32) <= 0xFu) &&
          ((unsigned __int8)(v12 - 64) <= 0x3Eu ||
           (unsigned __int8)(v12 + 0x80) <= 0x7Cu)) {
        v5 = v2[1] + (v10 << 8);
        *a1 = (const char *)(v2 + 2);
        if (a2)
          *a2 = (unsigned int)(v5 - 33088) <= 0x11;
        return v5;
      }
    LABEL_6:
      v4 = *v2;
      v5 = *v2;
      *a1 = (const char *)(v2 + 1);
      if (a2) {
        v6 = v4 == 33 || v4 == 63 || v4 == 44 || v4 == 46 || v4 == 59 ||
             v4 == 58;
        *a2 = v6;
      }
      return v5;
    }
    if (current.integer != 8)
      goto LABEL_6;
    v13 = v2[1];
    v8 = *v2;
    if ((unsigned __int8)(v8 + 80) > 0x18u || (unsigned __int8)v13 <= 0xA0u ||
        (_BYTE)v13 == 0xFF)
      goto LABEL_6;
    v5 = (v8 << 8) + v13;
    *a1 = (const char *)(v2 + 2);
    if (a2)
      *a2 = 0;
  }
  return v5;
}

int __cdecl Chinese_CollapseGBCode(unsigned int) { UNIMPLEMENTED(); }

int __cdecl Japanese_CollapseShiftJISCode(unsigned int) { UNIMPLEMENTED(); }

int __cdecl Korean_CollapseKSC5601HangulCode(unsigned int) { UNIMPLEMENTED(); }

int __cdecl SEH_PrintStrlen(char const *string) {
  char *v1;           // eax
  int v2;             // ebx
  int CharFromString; // eax
  char *v4;           // eax
  char v6;            // dl
  char *v7;           // [esp+1Ch] [ebp-Ch] BYREF

  v1 = a1;
  if (a1) {
    v7 = a1;
    v2 = 0;
  LABEL_3:
    if (!*v1)
      return v2;
    while (1) {
      CharFromString = SEH_ReadCharFromString((const char **)&v7, 0);
      if (CharFromString == 94) {
        v4 = v7;
        if (v7) {
          v6 = *v7;
          if (*v7 != 94 && v6 > 47 && v6 <= 57) {
            v1 = ++v7;
            goto LABEL_3;
          }
        }
      } else {
        if (CharFromString == 10 || CharFromString == 13) {
          v1 = v7;
          goto LABEL_3;
        }
        v4 = v7;
      }
      ++v2;
      if (!*v4)
        return v2;
    }
  }
  return 0;
}

char const *__cdecl SE_GetString(char const *) {
  _DWORD *v1;     // esi
  const char *v2; // ebx
  const char *v4; // [esp+18h] [ebp-10h] BYREF
  char v5;        // [esp+1Eh] [ebp-Ah] BYREF
  _BYTE v6[9];    // [esp+1Fh] [ebp-9h] BYREF

  std::string::string(&v4, a1, &v5);
  v1 = (_DWORD *)
      std::_Rb_tree<std::string, std::pair<std::string const, std::string>,
                    std::_Select1st<std::pair<std::string const, std::string>>,
                    std::less<std::string>,
                    std::allocator<std::pair<std::string const, std::string>>>::
          find((int)TheStringPackage + 16, &v4);
  v2 = v4 - 12;
  if (v4 - 12 != (const char *)&std::string::_Rep::_S_empty_rep_storage &&
      (int)__gnu_cxx::__exchange_and_add((volatile int *)v4 - 1, -1) <= 0) {
    std::string::_Rep::_M_destroy(v2, v6);
  }
  if ((_DWORD *)((char *)TheStringPackage + 20) == v1)
    return 0;
  else
    return v1[5];
}

char const *__cdecl SEH_StringEd_GetString(char const *pszReference) {
  const char *result; // eax

  result = a1;
  if (loc_translate && *(_BYTE *)(loc_translate + 8) && *a1) {
    if (a1[1])
      return (const char *)SE_GetString(a1);
  }
  return result;
}

char const *__cdecl SEH_LocalizeTextMessage(char const *pszInputBuffer,
                                            char const *pszMessageType,
                                            enum msgLocErrType_t errType) {
  char *v3;           // edx
  int v4;             // ebx
  char v5;            // al
  int i;              // edx
  char *v8;           // ecx
  unsigned int v9;    // edx
  char *v10;          // edx
  char *v11;          // ebx
  unsigned int v12;   // eax
  char *v13;          // ebx
  unsigned int v14;   // esi
  const char *String; // eax
  unsigned int v16;   // eax
  char *v17;          // [esp+1Ch] [ebp-85Ch]
  unsigned int v18;   // [esp+24h] [ebp-854h]
  int v19;            // [esp+28h] [ebp-850h]
  int v20;            // [esp+2Ch] [ebp-84Ch]
  unsigned int v21;   // [esp+30h] [ebp-848h]
  char *__dst;        // [esp+34h] [ebp-844h]
  const char *v23;    // [esp+38h] [ebp-840h]
  int v24;            // [esp+3Ch] [ebp-83Ch]
  int v25;            // [esp+40h] [ebp-838h]
  int v26;            // [esp+44h] [ebp-834h]
  int v27;            // [esp+48h] [ebp-830h]
  int v28;            // [esp+4Ch] [ebp-82Ch]
  int v29;            // [esp+50h] [ebp-828h]
  int v30;            // [esp+54h] [ebp-824h]
  int v31;            // [esp+58h] [ebp-820h]
  char v32[1024];     // [esp+60h] [ebp-818h] BYREF
  char __src[1048];   // [esp+460h] [ebp-418h] BYREF

  SEH_LocalizeTextMessage(char const *, char const *,
                          msgLocErrType_t)::iCurrString =
      (SEH_LocalizeTextMessage(char const *, char const *,
                               msgLocErrType_t)::iCurrString +
       1) %
      2;
  memset((void *)((SEH_LocalizeTextMessage(char const *, char const *,
                                           msgLocErrType_t)::iCurrString
                   << 10) +
                  3392928),
         0, 0x400u);
  __dst = (char *)((SEH_LocalizeTextMessage(char const *, char const *,
                                            msgLocErrType_t)::iCurrString
                    << 10) +
                   3392928);
  v3 = a1;
  v23 = a1;
  v31 = 0;
  v24 = 1;
  v4 = 1;
  v25 = 0;
  v27 = 1;
  v26 = 0;
  while (*v3) {
    while (1) {
      v5 = *v23;
      if (!*v23 || v5 == 20 || v5 == 21 || v5 == 22)
        break;
      ++v23;
      if (!*v3)
        goto LABEL_8;
    }
    if (v3 < v23) {
      v21 = v23 - v3;
      I_strncpyz(__src, v3, v23 - v3 + 1);
      if (v24) {
        if (loc_translate && *(_BYTE *)(loc_translate + 8) && __src[0] &&
            __src[1]) {
          String = (const char *)SE_GetString(__src);
          if (!String) {
            if (loc_warnings && *(_BYTE *)(loc_warnings + 8)) {
              if (loc_warningsAsErrors &&
                  *(_BYTE *)(loc_warningsAsErrors + 8) && a3 != LOCMSG_NOERR)
                Com_Error(6, "Could not translate part of %s: \"%s\"",
                          (char)a2);
              else
                Com_Printf(
                    "^3WARNING: Could not translate part of %s: \"%s\"\n", a2,
                    __src);
              String = va("^1UNLOCALIZED(^7%s^1)^7", __src);
            } else {
              String = va("%s", __src);
            }
            if (a3 == LOCMSG_NOERR)
              return 0;
          }
        } else {
          String = __src;
        }
        strcpy(__src, String);
        v21 = strlen(__src);
        v9 = v21;
      } else {
        v9 = v21;
      }
      v20 = v31 + v9;
      if ((int)(v31 + v9) > 1023) {
        if (loc_warnings && *(_BYTE *)(loc_warnings + 8) &&
            loc_warningsAsErrors && *(_BYTE *)(loc_warningsAsErrors + 8) &&
            a3 != LOCMSG_NOERR) {
          Com_Error(1, "%s too long when translated: \"%s\"", (char)a2);
        }
        Com_Printf("%s too long when translated: \"%s\"\n", a2, a1);
      }
      v18 = v21 - 2;
      if ((int)(v21 - 2) > 0) {
        if (v4) {
          v30 = 0;
          v11 = __src;
          do {
            if (!memcmp(v11, "&&", 2)) {
              v12 = v11[2];
              if (v12 <= 0xFF &&
                  (_DefaultRuneLocale.__runetype[v12] & 0x400) != 0)
                ++v25;
            }
            ++v30;
            ++v11;
          } while (v18 != v30);
        } else {
          v19 = 0;
          v17 = __src;
          do {
            if (!memcmp(v17, "&&", 2)) {
              v16 = v17[2];
              if (v16 <= 0xFF &&
                  (_DefaultRuneLocale.__runetype[v16] & 0x400) != 0) {
                *v17 = 22;
                v26 = 1;
              }
            }
            ++v19;
            ++v17;
          } while (v19 != v18);
        }
      }
      if (v25 <= 0 || v31 <= 0) {
        strcpy(&__dst[v31], __src);
        v31 = v20;
        v5 = *v23;
        goto LABEL_16;
      }
      v28 = v31 - 2;
      if (v31 - 2 > 0) {
        v13 = __dst;
        v29 = 0;
        while (1) {
          if (!memcmp(v13, "&&", 2)) {
            v14 = v13[2];
            if (v14 <= 0xFF &&
                (_DefaultRuneLocale.__runetype[v14] & 0x400) != 0) {
              if (v14 == 48)
                Com_Printf("%s cannot have &&0 as conversion format: \"%s\"\n",
                           a2, a1);
              if (v27 == v14 - 48)
                break;
            }
          }
          ++v29;
          ++v13;
          if (v28 == v29) {
            v10 = &__dst[v29];
            goto LABEL_34;
          }
        }
        strcpy(v32, v13 + 3);
        *v13 = 0;
        v27 = v14 - 47;
        v28 = v29;
        v10 = v13;
      } else {
        v10 = __dst;
        v28 = 0;
      }
    LABEL_34:
      strcpy(v10, __src);
      strcpy(&__dst[v28 + v21], v32);
      --v25;
      v31 = v31 + v21 - 3;
      v5 = *v23;
      if (*v23 == 20)
        goto LABEL_35;
    LABEL_17:
      if (v5 == 21) {
        ++v23;
        v24 = 0;
      }
      v8 = (char *)v23;
      if (*v23 == 22)
        goto LABEL_36;
    LABEL_20:
      v3 = v8;
      v4 = 1;
    } else {
    LABEL_16:
      if (v5 != 20)
        goto LABEL_17;
    LABEL_35:
      ++v23;
      v24 = 1;
      v8 = (char *)v23;
      if (*v23 != 22)
        goto LABEL_20;
    LABEL_36:
      v3 = (char *)++v23;
      v4 = 0;
    }
  }
LABEL_8:
  if (v26 && v31 > 0) {
    for (i = 0; i != v31; ++i) {
      while (__dst[i] != 22) {
        if (++i == v31)
          return __dst;
      }
      __dst[i] = 37;
    }
  }
  return __dst;
}

void __cdecl SEH_InitLanguage() {
  _BOOL4 result; // eax

  loc_language = Dvar_RegisterInt("loc_language", 0, 0, 13, 0x1021u);
  loc_forceEnglish = (int)Dvar_RegisterBool("loc_forceEnglish", 0, 0x1021u);
  loc_translate = (int)Dvar_RegisterBool("loc_translate", 1u, 0x1020u);
  loc_warnings = (int)Dvar_RegisterBool("loc_warnings", 0, 0x1000u);
  loc_warningsAsErrors =
      (int)Dvar_RegisterBool("loc_warningsAsErrors", 0, 0x1000u);
  result = (unsigned int)(loc_language->current.integer - 8) <= 4;
  g_currentAsian = result;
  return result;
}

char const *__cdecl SEH_SafeTranslateString(char const *pszReference) {
  char *result; // eax

  if (loc_translate && *(_BYTE *)(loc_translate + 8)) {
    if (!*__src || !__src[1])
      return __src;
    result = (char *)SE_GetString(__src);
  } else {
    result = __src;
  }
  if (!result) {
    if (*(_BYTE *)(loc_warnings + 8)) {
      if (*(_BYTE *)(loc_warningsAsErrors + 8))
        Com_Error(6, "Could not translate exe string \"%s\"", (char)__src);
      else
        Com_Printf("^3WARNING: Could not translate exe string \"%s\"\n", __src);
      strcpy(SEH_SafeTranslateString(char const *)::szErrorString,
             "^1UNLOCALIZED(^7");
      I_strncat(SEH_SafeTranslateString(char const *)::szErrorString, 1024,
                __src);
      I_strncat(SEH_SafeTranslateString(char const *)::szErrorString, 1024,
                "^1)^7");
      return SEH_SafeTranslateString(char const *)::szErrorString;
    } else {
      I_strncpyz(SEH_SafeTranslateString(char const *)::szErrorString, __src,
                 1024);
      return SEH_SafeTranslateString(char const *)::szErrorString;
    }
  }
  return result;
}

struct dvar_s const *const loc_warningsAsErrors;
struct dvar_s const *const loc_warnings;
struct dvar_s const *const loc_language;
struct dvar_s const *const loc_forceEnglish;
struct dvar_s const *const loc_translate;
bool __cdecl Chinese_IsTrailingPunctuation(unsigned int) { UNIMPLEMENTED(); }

bool __cdecl Chinese_ValidGBCode(unsigned char, unsigned char) {
  UNIMPLEMENTED();
}

bool __cdecl Japanese_IsTrailingPunctuation(unsigned int) { UNIMPLEMENTED(); }

bool __cdecl Japanese_ValidShiftJISCode(unsigned char, unsigned char) {
  UNIMPLEMENTED();
}

bool __cdecl Taiwanese_IsTrailingPunctuation(unsigned int) { UNIMPLEMENTED(); }

bool __cdecl Taiwanese_ValidBig5Code(unsigned int) { UNIMPLEMENTED(); }

bool __cdecl Korean_ValidKSC5601Hangul(unsigned char, unsigned char) {
  UNIMPLEMENTED();
}

void __cdecl SEH_UpdateCurrentLanguage(void) { UNIMPLEMENTED(); }

bool __cdecl Chinese_ValidGBCode_UICode(unsigned int) { UNIMPLEMENTED(); }

bool __cdecl Japanese_ValidShiftJISCode_UICode(unsigned int) {
  UNIMPLEMENTED();
}

bool __cdecl Korean_ValidKSC5601Hangul_Code(unsigned int) { UNIMPLEMENTED(); }

int __cdecl SEH_GetLocalizedTokenReference(char *, char const *, char const *,
                                           enum msgLocErrType_t) {
  UNIMPLEMENTED();
}

SEH_Init_StringEd() { UNIMPLEMENTED(); }

SEH_Shutdown_StringEd() { UNIMPLEMENTED(); }

SEH_UpdateLanguageInfo() { UNIMPLEMENTED(); }
