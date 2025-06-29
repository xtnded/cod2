int __cdecl R_TextHeight(struct Font_s *font) { return a1->pixelHeight; }

float __cdecl R_NormalizedTextScale(struct Font_s *font, float scale) {
  return (float)((float)(48.0 * a2) / (float)a1->pixelHeight);
}

struct Glyph const *__cdecl R_GetCharacterGlyph(struct Font_s *font,
                                                unsigned int letter) {
  unsigned __int16 *result; // eax
  uint32_t glyphCount;      // eax
  int v4;                   // esi
  int32_t glyphs;           // edi
  int v6;                   // edx
  unsigned int v7;          // ecx
  int v8;                   // ebx

  if (a2 - 32 <= 0x5F)
    return (unsigned __int16 *)(a1->glyphs + 24 * a2 - 768);
  glyphCount = a1->glyphCount;
  v4 = glyphCount - 1;
  if ((int)(glyphCount - 1) <= 95) {
    glyphs = a1->glyphs;
    return (unsigned __int16 *)(glyphs + 336);
  }
  v6 = (int)(glyphCount + 95) / 2;
  glyphs = a1->glyphs;
  result = (unsigned __int16 *)(glyphs + 24 * v6);
  v7 = *result;
  if (a2 != v7) {
    v8 = 96;
    while (1) {
      if (a2 > v7)
        v8 = v6 + 1;
      else
        v4 = v6 - 1;
      if (v4 < v8)
        break;
      v6 = (v4 + v8) / 2;
      result = (unsigned __int16 *)(glyphs + 24 * v6);
      v7 = *result;
      if (a2 == v7)
        return result;
    }
    return (unsigned __int16 *)(glyphs + 336);
  }
  return result;
}

void __cdecl R_DrawText(char const *text, int maxChars, struct Font_s *font,
                        float x, float y, float xScale, float yScale,
                        float const *const color, int style) {
  return R_AddCmdDrawTextWithCursor(__src, a2, a3, a4, a5, a6, a7, a8, a9, -1,
                                    0);
}

int __cdecl R_TextWidth(char const *text, int maxChars, struct Font_s *font) {
  int v3;               // eax
  const char *v4;       // ecx
  int v5;               // eax
  unsigned int v6;      // ebx
  unsigned __int16 *v7; // eax
  int v8;               // edx
  uint32_t glyphCount;  // eax
  int v11;              // edi
  int32_t glyphs;       // eax
  const char *v13;      // edx
  char v14;             // al
  int v15;              // edx
  unsigned int v16;     // ecx
  int v17;              // esi
  int32_t v18;          // [esp+1Ch] [ebp-2Ch]
  const char *v19;      // [esp+20h] [ebp-28h]
  int v20;              // [esp+24h] [ebp-24h]
  int v21;              // [esp+28h] [ebp-20h]
  int v22;              // [esp+2Ch] [ebp-1Ch]

  v3 = 0x7FFFFFFF;
  if (a2 > 0)
    v3 = a2;
  a2 = v3;
  v21 = 0;
  v22 = 0;
  v20 = 0;
  v4 = a1;
LABEL_4:
  if (*v4) {
    while (a2 > v20) {
      v5 = unk_11807D8(&a1, 0);
      v6 = v5;
      if (v5 == 10) {
        v21 = 0;
        v4 = a1;
        goto LABEL_4;
      }
      if (v5 == 94) {
        v19 = a1;
        if (a1) {
          v13 = a1;
          v14 = *a1;
          if (*a1 != 94 && v14 > 47 && v14 <= 57) {
            ++a1;
            v4 = v13 + 1;
            goto LABEL_4;
          }
        }
      } else {
        v19 = a1;
      }
      if (v6 - 32 <= 0x5F) {
        v7 = (unsigned __int16 *)(a3->glyphs + 24 * v6 - 768);
        goto LABEL_11;
      }
      glyphCount = a3->glyphCount;
      v11 = glyphCount - 1;
      if ((int)(glyphCount - 1) <= 95) {
        glyphs = a3->glyphs;
        goto LABEL_17;
      }
      v15 = (int)(glyphCount + 95) / 2;
      v18 = a3->glyphs;
      v7 = (unsigned __int16 *)(v18 + 24 * v15);
      v16 = *v7;
      if (v6 != v16) {
        v17 = 96;
        do {
          if (v6 > v16) {
            v17 = v15 + 1;
            if (v11 < v15 + 1)
              goto LABEL_30;
          } else {
            v11 = v15 - 1;
            if (v15 - 1 < v17) {
            LABEL_30:
              glyphs = a3->glyphs;
            LABEL_17:
              v7 = (unsigned __int16 *)(glyphs + 336);
              break;
            }
          }
          v15 = (v11 + v17) / 2;
          v7 = (unsigned __int16 *)(v18 + 24 * v15);
          v16 = *v7;
        } while (v6 != v16);
      }
    LABEL_11:
      v21 += *((unsigned __int8 *)v7 + 4);
      v8 = v21;
      if (v21 <= v22)
        v8 = v22;
      v22 = v8;
      ++v20;
      if (!*v19)
        return v22;
    }
  }
  return v22;
}

struct Font_s *__cdecl R_RegisterFont(char const *fontName, int imageTrack) {
  int v2;     // eax
  char *Font; // ebx
  int v4;     // eax
  int v6;     // esi
  char ***v7; // ebx

  v2 = registeredFontCount;
  if (registeredFontCount > 0) {
    v6 = 0;
    v7 = (char ***)registeredFont;
    while (I_stricmp(a1, **v7)) {
      ++v6;
      v2 = registeredFontCount;
      ++v7;
      if (registeredFontCount <= v6)
        goto LABEL_2;
    }
    return registeredFont[v6];
  } else {
  LABEL_2:
    if (v2 > 15) {
      R_Error(ERR_DROP, "R_RegisterFont: Too many fonts registered already.\n");
      return 0;
    } else {
      Font = R_LoadFont(a1, a2);
      if (!Font)
        R_Error(ERR_DROP, "R_RegisterFont: Error while reading font '%s'", a1);
      v4 = registeredFontCount;
      registeredFont[registeredFontCount] = (int)Font;
      registeredFontCount = v4 + 1;
    }
  }
  return (int)Font;
}

void __cdecl R_DrawConsoleText(short const *string, int maxChars,
                               struct Font_s *font, float x, float y,
                               float xScale, float yScale,
                               float const *const color, int style) {
  int result;            // eax
  char *v10;             // edx
  unsigned int v11;      // ebx
  unsigned __int16 *v12; // eax
  float pixelHeight;     // xmm0_4
  float v14;             // xmm2_4
  float v15;             // xmm0_4
  float v16;             // xmm1_4
  float v17;             // xmm0_4
  uint32_t glyphCount;   // eax
  int v19;               // edi
  int32_t glyphs;        // eax
  int v21;               // edx
  unsigned int v22;      // ecx
  int v23;               // esi
  char *v24;             // [esp+30h] [ebp-468h]
  int32_t v25;           // [esp+34h] [ebp-464h]
  float v26;             // [esp+38h] [ebp-460h]
  _WORD *ConsoleIcon;    // [esp+3Ch] [ebp-45Ch]
  int v28;               // [esp+40h] [ebp-458h]
  int v29;               // [esp+44h] [ebp-454h]
  int v30;               // [esp+48h] [ebp-450h]
  int v31;               // [esp+4Ch] [ebp-44Ch]
  char __src[1024];      // [esp+5Ch] [ebp-43Ch] BYREF
  float v33[4];          // [esp+45Ch] [ebp-3Ch] BYREF
  float v34;             // [esp+46Ch] [ebp-2Ch] BYREF
  __int16 v35[2];        // [esp+470h] [ebp-28h] BYREF
  char *v36;             // [esp+474h] [ebp-24h] BYREF
  Material *v37;         // [esp+478h] [ebp-20h] BYREF
  float v38[6];          // [esp+47Eh] [ebp-1Ah] BYREF

  v33[0] = *a8;
  v33[1] = a8[1];
  v33[2] = a8[2];
  result = *((_DWORD *)a8 + 3);
  LODWORD(v33[3]) = result;
  if (a1) {
    v26 = 0.0;
    for (result = (int)R_GetConsoleString(a1, &a2, __src, v33,
                                          (int *)((char *)v38 + 1));
         ; result = (int)R_GetConsoleString(ConsoleIcon, &a2, __src, v33,
                                            (int *)((char *)v38 + 1))) {
      ConsoleIcon = (_WORD *)result;
      if (__src[0]) {
        result = R_AddCmdDrawTextWithCursor(__src, 0x7FFFFFFF, a3, v26 + a4,
                                            *(float *)&a5, *(float *)&a6,
                                            *(float *)&a7, v33, a9, -1, 0);
        if (!BYTE1(v38[0]))
          goto LABEL_4;
        v36 = __src;
        result = 0x7FFFFFFF;
        if (a2 > 0)
          result = a2;
        v28 = result;
        v30 = 0;
        v31 = 0;
        v29 = 0;
        v10 = __src;
      LABEL_11:
        if (*v10) {
          while (v28 > v29) {
            result = unk_11807D8(&v36, 0);
            v11 = result;
            if (result == 10) {
              v30 = 0;
              v10 = v36;
              goto LABEL_11;
            }
            if (result == 94) {
              v24 = v36;
              if (v36) {
                result = (unsigned __int8)*v36;
                if ((_BYTE)result != 94 && (char)result > 47 &&
                    (char)result <= 57) {
                  v10 = ++v36;
                  goto LABEL_11;
                }
              }
            } else {
              v24 = v36;
            }
            if (v11 - 32 <= 0x5F) {
              v12 = (unsigned __int16 *)(a3->glyphs + 24 * v11 - 768);
              goto LABEL_18;
            }
            glyphCount = a3->glyphCount;
            v19 = glyphCount - 1;
            if ((int)(glyphCount - 1) <= 95) {
              glyphs = a3->glyphs;
              goto LABEL_28;
            }
            v21 = (int)(glyphCount + 95) / 2;
            v25 = a3->glyphs;
            v12 = (unsigned __int16 *)(v25 + 24 * v21);
            v22 = *v12;
            if (v11 != v22) {
              v23 = 96;
              do {
                if (v11 > v22) {
                  v23 = v21 + 1;
                  if (v19 < v21 + 1)
                    goto LABEL_41;
                } else {
                  v19 = v21 - 1;
                  if (v21 - 1 < v23) {
                  LABEL_41:
                    glyphs = a3->glyphs;
                  LABEL_28:
                    v12 = (unsigned __int16 *)(glyphs + 336);
                    break;
                  }
                }
                v21 = (v19 + v23) / 2;
                v12 = (unsigned __int16 *)(v25 + 24 * v21);
                v22 = *v12;
              } while (v22 != v11);
            }
          LABEL_18:
            v30 += *((unsigned __int8 *)v12 + 4);
            result = v30;
            if (v31 >= v30)
              result = v31;
            v31 = result;
            ++v29;
            if (!*v24)
              break;
          }
        }
        v26 = (float)((float)v31 * *(float *)&a6) + v26;
        if (!BYTE1(v38[0])) {
        LABEL_4:
          if (!ConsoleIcon)
            return result;
          continue;
        }
      } else if (!BYTE1(v38[0])) {
        goto LABEL_4;
      }
      ConsoleIcon = (_WORD *)R_GetConsoleIcon((int)ConsoleIcon, &a2, &v34, v35,
                                              (int *)&v37, v33, v38);
      pixelHeight = (float)a3->pixelHeight;
      v14 = (float)(*(float *)&a6 * pixelHeight) * v34;
      v34 = v14;
      v15 = pixelHeight * *(float *)&a7;
      v16 = v15 * *(float *)v35;
      *(float *)v35 = v16;
      v17 = (float)((float)((float)(v15 * 0.80000001) + v16) * -0.5) +
            *(float *)&a5;
      if (LOBYTE(v38[0]))
        result = R_AddCmdDrawStretchPic(a4 + v26, v17, v14, v16, 1.0, 0.0, 0.0,
                                        1.0, v33, v37);
      else
        result = R_AddCmdDrawStretchPic(a4 + v26, v17, v14, v16, 0.0, 0.0, 1.0,
                                        1.0, v33, v37);
      v26 = v26 + v34;
      if (!ConsoleIcon)
        return result;
    }
  }
  return result;
}

int __cdecl R_ConsoleTextWidth(short const *string, int maxChars,
                               struct Font_s *font) {
  const __int16 *result;  // eax
  char *v4;               // ecx
  int v5;                 // eax
  int v6;                 // eax
  unsigned int v7;        // ebx
  unsigned __int16 *v8;   // eax
  int v9;                 // edx
  uint32_t glyphCount;    // eax
  int v11;                // edi
  int32_t glyphs;         // eax
  char v13;               // al
  int v14;                // edx
  unsigned int v15;       // ecx
  int v16;                // esi
  char *v17;              // [esp+10h] [ebp-458h]
  int32_t v18;            // [esp+14h] [ebp-454h]
  float v19;              // [esp+18h] [ebp-450h]
  __int16 *ConsoleString; // [esp+1Ch] [ebp-44Ch]
  int v21;                // [esp+20h] [ebp-448h]
  int v22;                // [esp+24h] [ebp-444h]
  int v23;                // [esp+28h] [ebp-440h]
  int v24;                // [esp+2Ch] [ebp-43Ch]
  _BYTE v25[1024];        // [esp+3Ch] [ebp-42Ch] BYREF
  char *v26;              // [esp+43Ch] [ebp-2Ch] BYREF
  int v27;                // [esp+440h] [ebp-28h] BYREF
  __int16 v28;            // [esp+444h] [ebp-24h] BYREF
  float v29;              // [esp+448h] [ebp-20h] BYREF
  int v30[6];             // [esp+44Fh] [ebp-19h] BYREF

  result = a1;
  if (a1) {
    ConsoleString = a1;
    v19 = 0.0;
    do {
      ConsoleString = R_GetConsoleString(ConsoleString, &a2, v25, 0, v30);
      v4 = v25;
      v26 = v25;
      v5 = 0x7FFFFFFF;
      if (a2 > 0)
        v5 = a2;
      v21 = v5;
      v23 = 0;
      v24 = 0;
      v22 = 0;
    LABEL_6:
      if (*v4) {
        while (v21 > v22) {
          v6 = unk_11807D8(&v26, 0);
          v7 = v6;
          if (v6 == 10) {
            v23 = 0;
            v4 = v26;
            goto LABEL_6;
          }
          if (v6 == 94) {
            v17 = v26;
            if (v26) {
              v13 = *v26;
              if (*v26 != 94 && v13 > 47 && v13 <= 57) {
                v4 = ++v26;
                goto LABEL_6;
              }
            }
          } else {
            v17 = v26;
          }
          if (v7 - 32 <= 0x5F) {
            v8 = (unsigned __int16 *)(a3->glyphs + 24 * v7 - 768);
            goto LABEL_13;
          }
          glyphCount = a3->glyphCount;
          v11 = glyphCount - 1;
          if ((int)(glyphCount - 1) <= 95) {
            glyphs = a3->glyphs;
            goto LABEL_23;
          }
          v14 = (int)(glyphCount + 95) / 2;
          v18 = a3->glyphs;
          v8 = (unsigned __int16 *)(v18 + 24 * v14);
          v15 = *v8;
          if (v7 != v15) {
            v16 = 96;
            do {
              if (v7 > v15) {
                v16 = v14 + 1;
                if (v11 < v14 + 1)
                  goto LABEL_36;
              } else {
                v11 = v14 - 1;
                if (v14 - 1 < v16) {
                LABEL_36:
                  glyphs = a3->glyphs;
                LABEL_23:
                  v8 = (unsigned __int16 *)(glyphs + 336);
                  break;
                }
              }
              v14 = (v11 + v16) / 2;
              v8 = (unsigned __int16 *)(v18 + 24 * v14);
              v15 = *v8;
            } while (v7 != v15);
          }
        LABEL_13:
          v23 += *((unsigned __int8 *)v8 + 4);
          v9 = v23;
          if (v23 <= v24)
            v9 = v24;
          v24 = v9;
          ++v22;
          if (!*v17)
            break;
        }
      }
      v19 = (float)v24 + v19;
      if (LOBYTE(v30[0])) {
        ConsoleString = (__int16 *)R_GetConsoleIcon((int)ConsoleString, &a2,
                                                    &v29, &v28, &v27, 0, 0);
        v19 = v19 + v29;
      }
    } while (ConsoleString);
    return (const __int16 *)(int)v19;
  }
  return result;
}

int marker_r_font;
short const *__cdecl R_GetConsoleString(short const *, int *, char *,
                                        float *const, bool *) {
  UNIMPLEMENTED();
}

void __cdecl R_DrawConsoleIcon(float, float, float, float, float const *const,
                               struct Material *, bool) {
  UNIMPLEMENTED();
}

short const *__cdecl R_GetConsoleIcon(short const *, int *, float *, float *,
                                      struct Material **, float *const,
                                      bool *) {
  UNIMPLEMENTED();
}

R_DuplicateFont(Font_s *fontCopy, char const *name) { UNIMPLEMENTED(); }

R_InitFonts() { UNIMPLEMENTED(); }

R_ShutdownFonts() { UNIMPLEMENTED(); }
