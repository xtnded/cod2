char *__cdecl strchr(char *, int) { UNIMPLEMENTED(); }

char *__cdecl Key_GetBinding(int keynum) {
  if (a1 == -1)
    return &inData;
  else
    return (const gentity_s *)*((_DWORD *)keys + 3 * a1 + 2);
}

bool __cdecl Key_IsValidGamePadChar(char) { UNIMPLEMENTED(); }

int __cdecl Key_IsDown(int) { UNIMPLEMENTED(); }

void __cdecl Key_SetOverstrikeMode(int state) {
  void *result; // eax

  result = key_overstrikeMode;
  *(_DWORD *)key_overstrikeMode = a1;
  return result;
}

int __cdecl Key_GetOverstrikeMode() { return *(_DWORD *)key_overstrikeMode; }

void __cdecl CL_Keys_SwitchToLocalClient(int) { UNIMPLEMENTED(); }

char *__cdecl Key_KeynumToString(int keynum, int translate) {
  char **v2; // eax
  char *v3;  // ecx
  char **i;  // edx
  char *v5;  // eax
  int v7;    // edx
  char v8;   // al
  char v9;   // dl
  char v10;  // al

  if (a1 == -1)
    return "<KEY NOT FOUND>";
  if ((unsigned int)a1 > 0xFF)
    return "<OUT OF RANGE>";
  if (a2 && SEH_GetCurrentLanguage() == 1 && a1 > 47 && a1 <= 57)
    return (const char *)dword_311400[a1];
  if ((unsigned int)(a1 - 33) > 0x5D || a1 == 34) {
    if (a2) {
      v2 = (char **)&keynames_localized;
      goto LABEL_7;
    }
  } else {
    Key_KeynumToString(int, int)::tinystr = __toupper(a1);
    byte_CEBA09 = 0;
    if (a1 != 59 || a2)
      return &Key_KeynumToString(int, int)::tinystr;
  }
  v2 = &keynames;
LABEL_7:
  v3 = *v2;
  if (*v2) {
    if ((char *)a1 != v2[1]) {
      for (i = v2 + 2;; i += 2) {
        v3 = *i;
        if (!*i)
          break;
        v5 = i[1];
        if ((char *)a1 == v5)
          return v3;
      }
      goto LABEL_23;
    }
    return v3;
  }
LABEL_23:
  v7 = a1 >> 4;
  v8 = a1 & 0xF;
  Key_KeynumToString(int, int)::tinystr = 48;
  byte_CEBA09 = 120;
  if (a1 >> 4 <= 9)
    v9 = v7 + 48;
  else
    v9 = v7 + 87;
  byte_CEBA0A = v9;
  if ((a1 & 0xFu) <= 9)
    v10 = v8 + 48;
  else
    v10 = v8 + 87;
  byte_CEBA0B = v10;
  byte_CEBA0C = 0;
  return &Key_KeynumToString(int, int)::tinystr;
}

void __cdecl Key_Shutdown() { UNIMPLEMENTED(); }

void __cdecl Key_AppendBindingsToConfig(char *) { UNIMPLEMENTED(); }

void __cdecl Key_WriteBindings(int f) {
  int v1;          // esi
  int v2;          // edi
  _BYTE *result;   // eax
  const char *v4;  // ecx
  char v5;         // al
  int v6;          // ebx
  const char **v7; // edx
  const char *v8;  // eax
  int v9;          // eax
  char v10;        // dl
  char v11;        // al
  char v12;        // al

  FS_Printf(a1, "unbindall\n");
  v1 = 0;
  v2 = 0;
  do {
    result = *(_BYTE **)((char *)keys + v2 + 8);
    if (!result || !*result)
      goto LABEL_13;
    if (v1 == -1) {
      v4 = "<KEY NOT FOUND>";
    } else if ((unsigned int)v1 <= 0xFF) {
      if ((unsigned int)(v1 - 33) > 0x5D || v1 == 34 ||
          (Key_KeynumToString(int, int)::tinystr = __toupper(v1),
           byte_CEBA09 = 0, v1 == 59)) {
        v4 = keynames;
        if (!keynames)
          goto LABEL_24;
        if (dword_311824 != v1) {
          v7 = (const char **)&unk_311828;
          while (1) {
            v4 = *v7;
            if (!*v7)
              break;
            v8 = v7[1];
            v7 += 2;
            if (v8 == (const char *)v1)
              goto LABEL_7;
          }
        LABEL_24:
          v9 = v1 >> 4;
          v10 = v1 & 0xF;
          Key_KeynumToString(int, int)::tinystr = 48;
          byte_CEBA09 = 120;
          if (v1 >> 4 <= 9)
            v11 = v9 + 48;
          else
            v11 = v9 + 87;
          byte_CEBA0A = v11;
          if ((v1 & 0xFu) <= 9)
            v12 = v10 + 48;
          else
            v12 = v10 + 87;
          byte_CEBA0B = v12;
          byte_CEBA0C = 0;
          v4 = &Key_KeynumToString(int, int)::tinystr;
        }
      } else {
        v4 = &Key_KeynumToString(int, int)::tinystr;
      }
    } else {
      v4 = "<OUT OF RANGE>";
    }
  LABEL_7:
    FS_Printf(a1, "bind %s \"", v4);
    v5 = **(_BYTE **)((char *)keys + v2 + 8);
    if (v5) {
      v6 = *(_DWORD *)((char *)keys + v2 + 8);
      do {
        while (v5 != 34) {
          FS_Printf(a1, "%c", v5);
          v5 = *(_BYTE *)++v6;
          if (!v5)
            goto LABEL_12;
        }
        FS_Printf(a1, "\\\"");
        v5 = *(_BYTE *)++v6;
      } while (v5);
    }
  LABEL_12:
    result = (_BYTE *)FS_Printf(a1, "\"\n");
  LABEL_13:
    ++v1;
    v2 += 12;
  } while (v1 != 256);
  return result;
}

int __cdecl Key_GetKey(char const *) { UNIMPLEMENTED(); }

void __cdecl Key_SetBinding(int keynum, char const *binding) {
  int *result; // eax

  result = (int *)a1;
  if (a1 != -1) {
    ReplaceStringInternal((const char **)keys + 3 * a1 + 2, __src);
    result = &dvar_modifiedFlags;
    dvar_modifiedFlags |= 1u;
  }
  return result;
}

void __cdecl Field_AdjustScroll(struct field_t *edit) {
  float v1;                        // xmm0_4
  int FontHandle;                  // eax
  int scroll;                      // ebx
  int32_t i;                       // eax
  int v5;                          // ebx
  float v6;                        // xmm1_4
  field_t *v7;                     // edx
  signed int v8;                   // esi
  signed int result;               // eax
  char *buffer;                    // [esp+1Ch] [ebp-2Ch]
  int v11;                         // [esp+20h] [ebp-28h]
  float VirtualWidthFromRealWidth; // [esp+24h] [ebp-24h]
  float v13;                       // [esp+28h] [ebp-20h]
  float widthInPixels;             // [esp+2Ch] [ebp-1Ch]

  v1 = *(float *)&a1->charHeight / 48.0;
  VirtualWidthFromRealWidth = v1;
  widthInPixels = (float)(int)a1->widthInPixels;
  if (a1->fixedSize) {
    VirtualWidthFromRealWidth = GetVirtualWidthFromRealWidth(v1);
    widthInPixels = GetVirtualHeightFromRealHeight(widthInPixels);
    FontHandle = dword_14C13C0;
    v11 = dword_14C13C0;
  } else {
    FontHandle = UI_GetFontHandle(0, v1);
    v11 = FontHandle;
  }
  v13 = dword_121C7B0(FontHandle, LODWORD(VirtualWidthFromRealWidth));
  buffer = (char *)a1->buffer;
  if (widthInPixels > (float)((float)dword_121C7B4(a1->buffer, 0, v11) * v13)) {
    a1->scroll = 0;
    result = SEH_PrintStrlen(buffer);
    a1->drawWidth = result;
  } else {
    if (widthInPixels <= 0.0) {
      scroll = a1->scroll;
    } else {
      scroll = a1->scroll;
      for (i = scroll;; a1->scroll = i) {
        if (scroll <= 0)
          goto LABEL_9;
        if ((float)((float)dword_121C7B4(&buffer[i - 1], 0, v11) * v13) >=
            widthInPixels)
          break;
        i = a1->scroll - 1;
        scroll = i;
      }
      scroll = a1->scroll;
    }
    while (1) {
    LABEL_9:
      while (1) {
        v5 = dword_121C7B4(&buffer[scroll], 0, v11);
        v6 = (float)((float)v5 * v13) -
             (float)((float)dword_121C7B4(&buffer[a1->cursor], 0, v11) * v13);
        if (v6 >= 0.0)
          break;
        scroll = a1->scroll;
        if (scroll) {
          a1->scroll = --scroll;
        } else if (widthInPixels > 0.0) {
          v7 = a1;
          goto LABEL_19;
        }
      }
      if (v6 < widthInPixels)
        break;
      scroll = a1->scroll + 1;
      a1->scroll = scroll;
    }
    scroll = a1->scroll;
    v7 = a1;
  LABEL_19:
    v8 = strlen(&buffer[scroll]);
    result = v7->cursor - scroll;
    v7->drawWidth = result;
    if (widthInPixels > 0.0 && v8 > result) {
      while (1) {
        result = dword_121C7B4(&buffer[scroll], result + 1, v11);
        if (widthInPixels <= (float)((float)result * v13))
          break;
        result = a1->drawWidth + 1;
        a1->drawWidth = result;
        if (result >= v8)
          break;
        scroll = a1->scroll;
      }
    }
  }
  return result;
}

void __cdecl Field_Draw(struct field_t *edit, int x, int y, int horzAlign,
                        int vertAlign, int showCursor) {
  int v5;                            // edi
  float v6;                          // xmm2_4
  char v7;                           // bl
  float v8;                          // xmm1_4
  float RealHeightFromVirtualHeight; // [esp+4Ch] [ebp-46Ch]
  float v11;                         // [esp+60h] [ebp-458h]
  Font_s *FontHandle;                // [esp+7Ch] [ebp-43Ch]
  int v13;                           // [esp+80h] [ebp-438h]
  float RealWidthFromVirtualWidth;   // [esp+88h] [ebp-430h]
  float v15;                         // [esp+8Ch] [ebp-42Ch]
  char __dst[1024];                  // [esp+90h] [ebp-428h] BYREF
  float v17[10];                     // [esp+490h] [ebp-28h] BYREF

  v17[0] = 1.0;
  v17[1] = 1.0;
  v17[2] = 1.0;
  v17[3] = 1.0;
  I_strncpyz(__dst, (char *)&a1->buffer[a1->scroll], 256 - a1->scroll);
  v5 = a1->cursor - a1->scroll;
  if (a1->fixedSize) {
    FontHandle = (Font_s *)dword_14C13C0;
    v13 = 0;
    RealWidthFromVirtualWidth = 1.0;
    v6 = 1.0;
    if (*(_DWORD *)key_overstrikeMode)
      v7 = 95;
    else
      v7 = 124;
  } else {
    v11 = *(float *)&a1->charHeight / 48.0;
    FontHandle = (Font_s *)UI_GetFontHandle(0, v11);
    v15 = dword_121C7B0(FontHandle, LODWORD(v11));
    if (a5 == 5) {
      RealWidthFromVirtualWidth = GetRealWidthFromVirtualWidth(v15);
      RealHeightFromVirtualHeight = GetRealHeightFromVirtualHeight(v15);
      v6 = RealHeightFromVirtualHeight;
    } else {
      RealWidthFromVirtualWidth = v15;
      v6 = v15;
    }
    v13 = 3;
    if (*(_DWORD *)key_overstrikeMode)
      v7 = 95;
    else
      v7 = 124;
  }
  v8 = (float)a3 + (float)((float)dword_121C7B8(FontHandle) * v6);
  if (!a1->drawWidth)
    a1->drawWidth = 256;
  return CL_DrawTextWithCursor(__dst, a1->drawWidth, FontHandle, (float)a2, v8,
                               a4, a5, RealWidthFromVirtualWidth, v6, v17, v13,
                               v5, v7);
}

void __cdecl Key_Unbindall_f() { UNIMPLEMENTED(); }

void __cdecl Field_CharEvent(struct field_t *edit, int ch) {
  int v2;                    // ebx
  uint8_t *buffer;           // edx
  int32_t result;            // eax
  unsigned int v5;           // kr04_4
  int32_t v6;                // edx
  const char *ClipboardData; // eax
  unsigned int v8;           // kr08_4
  int32_t cursor;            // edx
  char *v10;                 // [esp+1Ch] [ebp-1Ch]

  v2 = a2;
  buffer = a1->buffer;
  result = 0;
  v5 = strlen((const char *)a1->buffer) + 1;
  switch (a2) {
  case 22:
    ClipboardData = (const char *)Sys_GetClipboardData();
    v10 = (char *)ClipboardData;
    if (ClipboardData) {
      v8 = strlen(ClipboardData) + 1;
      if ((int)(v8 - 1) > 0) {
        LOBYTE(v2) = 0;
        do
          Field_CharEvent(a1, v10[v2++]);
        while (v8 - 1 != v2);
      }
      Z_FreeInternal(v10);
    }
    return Field_AdjustScroll(a1);
  case 3:
    Field_Clear(a1);
    return Field_AdjustScroll(a1);
  case 8:
    if (a1->cursor <= 0)
      return Field_AdjustScroll(a1);
    memmove(&buffer[a1->cursor - 1], &buffer[a1->cursor], v5 - a1->cursor);
    --a1->cursor;
    return Field_AdjustScroll(a1);
  case 1:
    a1->cursor = 0;
    a1->scroll = 0;
    break;
  case 5:
    a1->cursor = v5 - 1;
    return Field_AdjustScroll(a1);
  default:
    if (a2 > 31) {
      result = (int32_t)key_overstrikeMode;
      if (*(_DWORD *)key_overstrikeMode) {
        result = a1->cursor;
        if (a1->cursor != 255) {
          a1->buffer[result] = a2;
          v6 = result + 1;
          a1->cursor = result + 1;
          goto LABEL_10;
        }
      } else if (v5 != 256) {
        memmove(&buffer[a1->cursor + 1], &buffer[a1->cursor], v5 - a1->cursor);
        cursor = a1->cursor;
        a1->buffer[cursor] = a2;
        v6 = cursor + 1;
        a1->cursor = v6;
      LABEL_10:
        if (v6 == v5)
          a1->buffer[v6] = 0;
        return Field_AdjustScroll(a1);
      }
    }
    break;
  }
  return result;
}

void __cdecl Field_Paste(struct field_t *) { UNIMPLEMENTED(); }

void __cdecl Field_KeyDownEvent(struct field_t *edit, int key) {
  int32_t v2;                // edi
  signed int result;         // eax
  const char *ClipboardData; // eax
  unsigned int v5;           // kr08_4
  int32_t cursor;            // edx
  int32_t v7;                // eax
  _BOOL4 v8;                 // eax
  int v9;                    // ecx
  int32_t v10;               // edx
  int32_t j;                 // eax
  _BOOL4 v12;                // eax
  int v13;                   // ecx
  int32_t i;                 // eax
  _BOOL4 v15;                // eax
  int v16;                   // edx
  int v17;                   // ebx
  char *v18;                 // [esp+1Ch] [ebp-1Ch]

  v2 = strlen((const char *)a1->buffer);
  if ((a2 == 161 || a2 == 192) && *((_DWORD *)keys + 480)) {
    ClipboardData = (const char *)Sys_GetClipboardData();
    v18 = (char *)ClipboardData;
    if (ClipboardData) {
      v5 = strlen(ClipboardData) + 1;
      if ((int)(v5 - 1) > 0) {
        v17 = 0;
        do
          Field_CharEvent(a1, v18[v17++]);
        while (v5 - 1 != v17);
      }
      Z_FreeInternal(v18);
    }
  } else {
    switch (a2) {
    case 162:
      if (v2 > a1->cursor)
        memmove(&a1->buffer[a1->cursor], &a1->buffer[a1->cursor + 1],
                v2 - a1->cursor);
      break;
    case 157:
      if (v2 > a1->cursor)
        ++a1->cursor;
      if (*((_DWORD *)keys + 477)) {
        cursor = a1->cursor;
        v7 = a1->cursor;
        if (v2 > a1->cursor) {
          do {
            v9 = (char)a1->buffer[v7];
            if ((v9 & 0xFFFFFF80) != 0) {
              v8 = __maskrune(v9, 1280) != 0;
              cursor = a1->cursor;
            } else {
              v8 = (_DefaultRuneLocale.__runetype[v9] & 0x500) != 0;
            }
            if (!v8)
              break;
            v7 = cursor + 1;
            cursor = v7;
            a1->cursor = v7;
          } while (v2 > v7);
          for (i = cursor; v2 > i; a1->cursor = i) {
            v16 = (char)a1->buffer[i];
            if ((v16 & 0xFFFFFF80) != 0)
              v15 = __maskrune(v16, 1280) != 0;
            else
              v15 = (_DefaultRuneLocale.__runetype[v16] & 0x500) != 0;
            if (v15)
              break;
            i = a1->cursor + 1;
          }
        }
      }
      break;
    case 156:
      v10 = a1->cursor;
      if (a1->cursor > 0)
        a1->cursor = --v10;
      if (*((_DWORD *)keys + 477)) {
        for (j = v10; j > 0; a1->cursor = j) {
          v13 = *((char *)&a1->fixedSize + j + 3);
          if ((v13 & 0xFFFFFF80) != 0) {
            v12 = __maskrune(v13, 1280) != 0;
            v10 = a1->cursor;
          } else {
            v12 = (_DefaultRuneLocale.__runetype[v13] & 0x500) != 0;
          }
          if (!v12)
            break;
          j = v10 - 1;
          v10 = j;
        }
      }
      if (v10 < a1->scroll)
        a1->scroll = v10;
      break;
    default:
      if (a2 == 165 || __tolower(a2) == 97 && *((_DWORD *)keys + 477)) {
        a1->cursor = 0;
      } else if (a2 == 166 || __tolower(a2) == 101 && *((_DWORD *)keys + 477)) {
        a1->cursor = v2;
      } else if (a2 == 161) {
        *(_DWORD *)key_overstrikeMode = *(_DWORD *)key_overstrikeMode == 0;
      }
      break;
    }
  }
  result = dword_1220A70;
  if (dword_1220A70)
    return Field_AdjustScroll(a1);
  return result;
}

void __cdecl Message_Key(int key) {
  char __str[1032]; // [esp+10h] [ebp-408h] BYREF

  if (a1 != 27) {
    if (a1 != 13 && a1 != 191)
      return (void *)Field_KeyDownEvent(chatField, a1);
    if (chatField->buffer[0] && *(_DWORD *)clc == 8) {
      if (*(_DWORD *)chat_team)
        Com_sprintf(__str, 0x400u, "say_team \"\x15%s\"\n",
                    (const char *)chatField->buffer);
      else
        Com_sprintf(__str, 0x400u, "say \"\x15%s\"\n",
                    (const char *)chatField->buffer);
      CL_AddReliableCommand(__str);
    }
  }
  *((_DWORD *)cl + 1) &= ~0x10u;
  return Field_Clear(chatField);
}

void __cdecl Console_Key(int key) {
  int v8;                            // ebx
  int v9;                            // eax
  signed int v10;                    // eax
  int v11;                           // edx
  unsigned int v12;                  // kr04_4
  unsigned int v13;                  // kr08_4
  const char *v14;                   // ebx
  char *v15;                         // edx
  const char *v16;                   // ebx
  char *v17;                         // edx
  char *v18;                         // eax
  int Var;                           // ebx
  char *v20;                         // eax
  const char *v21;                   // esi
  unsigned int v22;                  // kr18_4
  unsigned int v23;                  // ecx
  unsigned int v24;                  // edi
  unsigned int v25;                  // edx
  char *v26;                         // ebx
  char *v27;                         // esi
  const char **AutoCompleteFileList; // ebx
  unsigned int v29;                  // kr1C_4
  unsigned int v30;                  // ecx
  unsigned int v31;                  // edi
  uint8_t *v32;                      // esi
  unsigned int v33;                  // ebx
  int v34;                           // eax
  uint8_t *v36;                      // esi
  unsigned int v37;                  // ebx
  int v38;                           // eax
  unsigned int v40;                  // [esp+3Ch] [ebp-53Ch]
  unsigned int v41;                  // [esp+44h] [ebp-534h]
  int v42;                           // [esp+48h] [ebp-530h]
  int v43;                           // [esp+4Ch] [ebp-52Ch]
  char __dst[1024];                  // [esp+5Ch] [ebp-51Ch] BYREF
  char __src[256];                   // [esp+45Ch] [ebp-11Ch] BYREF
  int v46[7];                        // [esp+55Ch] [ebp-1Ch] BYREF

  if (a8 == 108) {
    if (*((_DWORD *)keys + 477)) {
      Cbuf_AddText("clear\n");
      return;
    }
    goto LABEL_7;
  }
  if (a8 != 13 && a8 != 191) {
    if (a8 != 9) {
      if (a8 == 206) {
        if (*((_DWORD *)keys + 480))
          goto LABEL_41;
      } else if (a8 == 154) {
        goto LABEL_41;
      }
    LABEL_7:
      if (__tolower(a8) == 112 && *((_DWORD *)keys + 477)) {
      LABEL_41:
        v11 = historyLine;
        if (nextHistoryLine - historyLine <= 31 && historyLine > 0)
          v11 = --historyLine;
        v10 = v11 & 0x8000001F;
        if (v11 >= 0)
          goto LABEL_37;
        goto LABEL_45;
      }
      if (a8 == 205) {
        if (*((_DWORD *)keys + 480))
          goto LABEL_35;
      } else if (a8 == 155) {
        goto LABEL_35;
      }
      if (__tolower(a8) == 110 && *((_DWORD *)keys + 477)) {
      LABEL_35:
        v9 = historyLine;
        if (historyLine != nextHistoryLine) {
          ++historyLine;
          v10 = (v9 + 1) & 0x8000001F;
          if (v10 >= 0) {
          LABEL_37:
            memcpy(&g_consoleField, (char *)&historyEditLines + 280 * v10,
                   sizeof(g_consoleField));
            Field_AdjustScroll(&g_consoleField);
            return;
          }
        LABEL_45:
          v10 = (((_BYTE)v10 - 1) | 0xFFFFFFE0) + 1;
          goto LABEL_37;
        }
        return;
      }
      if (a8 != 164) {
        if (a8 == 163)
          goto LABEL_64;
        if (a8 != 206) {
          if (a8 != 205) {
            if (a8 == 165) {
              if (*((_DWORD *)keys + 477)) {
                Con_Top();
                return;
              }
            } else if (a8 == 166 && *((_DWORD *)keys + 477)) {
              Con_Bottom();
              return;
            }
            Field_KeyDownEvent(&g_consoleField, a8);
            return;
          }
          Con_PageDown();
          if (!*((_DWORD *)keys + 477))
            return;
          Con_PageDown();
        LABEL_64:
          Con_PageDown();
          return;
        }
        Con_PageUp();
        if (!*((_DWORD *)keys + 477))
          return;
        Con_PageUp();
      }
      Con_PageUp();
      return;
    }
    completionString = (char *)Con_TokenizeInput();
    matchCount = 0;
    shortestMatch[0] = 0;
    if (!*completionString)
      return;
    Cmd_ForEach((void (*)(const char *))FindMatches);
    v12 = strlen(shortestMatch) + 1;
    Dvar_ForEach((void (*)(const char *))FindMatches);
    v13 = strlen(shortestMatch) + 1;
    if (!matchCount)
      return;
    memcpy(__dst, &g_consoleField, 0x118u);
    if (matchCount != 1 &&
        (!hasExactMatch || !(unsigned __int8)Con_AnySpaceAfterCommand())) {
      Com_sprintf((char *)g_consoleField.buffer, 0x100u, "\\%s", shortestMatch);
      g_consoleField.cursor = strlen((const char *)g_consoleField.buffer);
      v16 = completionString;
      v17 = strstr(&__dst[24], completionString);
      if (v17)
        I_strncat((char *)g_consoleField.buffer, 256, &v17[strlen(v16)]);
      else
        keyConcatArgs();
      Field_AdjustScroll(&g_consoleField);
      Com_Printf("]%s\n", (const char *)g_consoleField.buffer);
      Cmd_ForEach((void (*)(const char *))PrintMatches);
      Dvar_ForEach((void (*)(const char *))PrintMatches);
      return;
    }
    Com_sprintf((char *)g_consoleField.buffer, 0x100u, "\\%s", shortestMatch);
    if (Cmd_Argc() == 1) {
      I_strncat((char *)g_consoleField.buffer, 256, " ");
    } else {
      v14 = completionString;
      v15 = strstr(&__dst[24], completionString);
      if (v15)
        I_strncat((char *)g_consoleField.buffer, 256, &v15[strlen(v14)]);
      else
        keyConcatArgs();
      if (Cmd_Argc() != 2)
        goto LABEL_58;
      if (v12 - 1 == v13 - 1) {
        v26 = (char *)Con_TokenizeInput();
        v27 = (char *)Cmd_Argv(1);
        if (!*v27)
          goto LABEL_58;
        AutoCompleteFileList =
            (const char **)Cmd_GetAutoCompleteFileList(v26, v46);
        if (!v46[0])
          goto LABEL_58;
        Con_AutoCompleteFromList(AutoCompleteFileList, v46[0], v27, __src, 256);
        FS_FreeFileList((void **)AutoCompleteFileList);
        Com_StripExtension(__src, __src);
        v29 = strlen(v27) + 1;
        if (!__src[0])
          goto LABEL_58;
        v30 = strlen((const char *)g_consoleField.buffer) + 1;
        v40 = v30 - 1;
        if (v30 == 1) {
          v31 = 0;
        } else {
          v36 = &g_consoleField.buffer[v30 - 1];
          v37 = v30 - 1;
          v42 = 0;
          while (1) {
            v31 = v37 - 1;
            v38 = (char)*(v36 - 1);
            if (!((v38 & 0xFFFFFF80) != 0
                      ? __maskrune(v38, 0x4000) != 0
                      : (_DefaultRuneLocale.__runetype[v38] >> 14) & 1))
              break;
            ++v42;
            --v36;
            if (v40 == v42)
              goto LABEL_88;
            --v37;
          }
          v31 = v37;
        }
      LABEL_88:
        v25 = v31 - (v29 - 1);
      } else {
        v18 = (char *)Con_TokenizeInput();
        Var = Dvar_FindVar(v18);
        if (*(_BYTE *)(Var + 6) != 6)
          goto LABEL_58;
        v20 = (char *)Cmd_Argv(1);
        v21 = v20;
        if (!*v20)
          goto LABEL_58;
        Con_AutoCompleteFromList(*(const char ***)(Var + 24),
                                 *(_DWORD *)(Var + 20), v20, __src, 256);
        v22 = strlen(v21) + 1;
        if (!__src[0])
          goto LABEL_58;
        v23 = strlen((const char *)g_consoleField.buffer) + 1;
        v41 = v23 - 1;
        if (v23 == 1) {
          v24 = 0;
        } else {
          v32 = &g_consoleField.buffer[v23 - 1];
          v33 = v23 - 1;
          v43 = 0;
          while (1) {
            v24 = v33 - 1;
            v34 = (char)*(v32 - 1);
            if (!((v34 & 0xFFFFFF80) != 0
                      ? __maskrune(v34, 0x4000) != 0
                      : (_DefaultRuneLocale.__runetype[v34] >> 14) & 1))
              break;
            ++v43;
            --v32;
            if (v41 == v43)
              goto LABEL_80;
            --v33;
          }
          v24 = v33;
        }
      LABEL_80:
        v25 = v24 - (v22 - 1);
      }
      I_strncpyz((char *)(v25 + 18980184), __src, 256 - v25);
    }
  LABEL_58:
    g_consoleField.cursor = strlen((const char *)g_consoleField.buffer);
    Field_AdjustScroll(&g_consoleField);
    return;
  }
  if (*(_DWORD *)clc != 8 && g_consoleField.buffer[0] != 92 &&
      g_consoleField.buffer[0] != 47) {
    I_strncpyz(__dst, (char *)g_consoleField.buffer, 1024);
    Com_sprintf((char *)g_consoleField.buffer, 0x100u, "\\%s", __dst);
    ++g_consoleField.cursor;
  }
  Com_Printf("]%s\n", (const char *)g_consoleField.buffer);
  if (g_consoleField.buffer[0] == 92 || g_consoleField.buffer[0] == 47) {
    Cbuf_AddText((const char *)&g_consoleField.buffer[1]);
    Cbuf_AddText("\n");
  } else {
    if (!g_consoleField.buffer[0])
      return;
    if (I_strncmp((char *)g_consoleField.buffer, "rcon", 4)) {
      Cbuf_AddText("cmd say ");
      Cbuf_AddText((const char *)g_consoleField.buffer);
      Cbuf_AddText("\n");
    }
  }
  if (g_consoleField.buffer[0]) {
    v8 = nextHistoryLine;
    memcpy((char *)&historyEditLines + 280 * (nextHistoryLine % 32),
           &g_consoleField, 0x118u);
    nextHistoryLine = v8 + 1;
    historyLine = v8 + 1;
  }
  Field_Clear(&g_consoleField);
  g_consoleField.widthInPixels = g_console_field_width;
  g_consoleField.charHeight = g_console_char_height;
  g_consoleField.fixedSize = 1;
  if (CL_AllLocalClientsDisconnected())
    SCR_UpdateScreen(a1, a2, a3, a4, a5, a6, a7);
}

void __cdecl CL_CharEvent(int key) {
  int v1; // edx
  int v2; // eax

  v1 = a1;
  if (a1 != 96 && a1 != 126) {
    v2 = *((_DWORD *)cl + 1);
    if ((v2 & 1) != 0)
      goto LABEL_8;
    if ((v2 & 8) != 0) {
      BYTE1(v1) = BYTE1(a1) | 4;
      UI_KeyEvent(v1, 1);
      return;
    }
    if ((v2 & 0x10) != 0) {
      Field_CharEvent(chatField, a1);
      return;
    }
    if (!*(_DWORD *)clc)
    LABEL_8:
      Field_CharEvent(&g_consoleField, a1);
  }
}

void __cdecl CL_KeyEvent(int key, int down, unsigned int time) {
  int v10;          // ebx
  char *v11;        // eax
  int v12;          // eax
  int v13;          // eax
  const char *v14;  // eax
  _BOOL4 v15;       // edx
  int v16;          // eax
  const char *v17;  // eax
  int v18;          // eax
  const char *v19;  // ecx
  const char **v20; // edx
  const char *v21;  // eax
  int v22;          // edx
  char v23;         // al
  char v24;         // dl
  char v25;         // al
  char __str[1048]; // [esp+20h] [ebp-418h] BYREF

  v10 = 12 * a8;
  *((_DWORD *)keys + 3 * a8) = a9;
  if (a9) {
    if (++*(_DWORD *)((char *)keys + v10 + 4) == 1)
      anykeydown = (_UNKNOWN *)((char *)anykeydown + 4);
  } else {
    *(_DWORD *)((char *)keys + v10 + 4) = 0;
    anykeydown = (_UNKNOWN *)((char *)anykeydown - 4);
  }
  if (a8 == 96 || a8 == 126 || (*((_BYTE *)cl + 4) & 1) != 0 ||
      (v14 = *(const char **)((char *)keys + v10 + 8)) == 0 ||
      stricmp(v14, "devgui")) {
    if (!a9)
      goto LABEL_30;
    v11 = (char *)keys;
  } else {
    if (!a9)
      goto LABEL_21;
    v11 = (char *)keys;
    if (*(_DWORD *)((char *)keys + v10 + 4) == 1) {
      Cbuf_AddText(*(const char **)((char *)keys + v10 + 8));
      return;
    }
  }
  if (*(int *)&v11[v10 + 4] > 1) {
    v12 = *((_DWORD *)cl + 1);
    if ((v12 & 0x11) == 0 &&
            ((v12 & 8) == 0 || (unsigned int)(a8 - 154) > 0xA ||
             ((1 << (a8 + 102)) & 0x603) == 0) ||
        a8 == 96 || a8 == 126 || a8 == 27) {
      return;
    }
    if (a8 <= 127)
      goto LABEL_18;
    goto LABEL_59;
  }
LABEL_30:
  if (a8 != 96 && a8 != 126) {
    if (!a9)
      goto LABEL_21;
    if (a8 <= 127) {
    LABEL_18:
      if ((*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc) ||
           *(_DWORD *)clc == 1 || *(_DWORD *)clc == 2) &&
          !*((_DWORD *)cl + 1)) {
        Dvar_SetString((dvar_s *)nextdemo, (char *)&inData);
        goto LABEL_67;
      }
    LABEL_21:
      if (a8 == 27 && a9) {
      LABEL_67:
        v18 = *((_DWORD *)cl + 1);
        if ((v18 & 0x10) != 0) {
          Message_Key(27);
        } else if ((v18 & 8) != 0) {
          UI_KeyEvent(27, a9);
        } else {
          switch (*(_DWORD *)clc) {
          case 1:
          case 2:
            CL_StopLogoOrCinematic();
            break;
          case 3:
          case 4:
          case 5:
            CL_Disconnect();
            if (*(_BYTE *)(com_sv_running + 8))
              *(_BYTE *)(legacyHacks + 221) = 1;
            break;
          case 8:
            if (*(_DWORD *)((char *)&loc_407A0 + (_DWORD)clc) ||
                *(_BYTE *)(legacyHacks + 220))
              goto LABEL_80;
            UI_SetActiveMenu(2);
            break;
          default:
            if (dword_1220A70)
            LABEL_80:
              UI_SetActiveMenu(1);
            break;
          }
        }
        return;
      }
      if (!*((_BYTE *)cl + 9)) {
      LABEL_23:
        if (!a9) {
          v13 = *(_DWORD *)((char *)keys + v10 + 8);
          if (v13 && *(_BYTE *)v13 == 43) {
            Com_sprintf(__str, 0x400u, "-%s %i %i\n", (const char *)(v13 + 1),
                        a8, a10);
            Cbuf_AddText(__str);
          }
          if ((*((_BYTE *)cl + 4) & 8) != 0) {
            if (dword_1220A70)
              UI_KeyEvent(a8, 0);
          }
          return;
        }
        v15 = cl_bypassMouseInput && *(_BYTE *)(cl_bypassMouseInput + 8) &&
              ((unsigned int)(a8 - 200) <= 2 || !UI_checkKeyExec(a8));
        v16 = *((_DWORD *)cl + 1);
        if ((v16 & 1) != 0)
          goto LABEL_72;
        if ((v16 & 8) != 0 && !v15) {
          UI_KeyEvent(a8, a9);
          return;
        }
        if ((v16 & 0x10) != 0) {
          Message_Key(a8);
          return;
        }
        if (!*(_DWORD *)clc) {
        LABEL_72:
          Console_Key(a1, a2, a3, a4, a5, a6, a7, a8);
          return;
        }
        v17 = *(const char **)((char *)keys + v10 + 8);
        if (v17) {
          if (*v17 == 43) {
            Com_sprintf(__str, 0x400u, "%s %i %i\n", v17, a8, a10);
            Cbuf_AddText(__str);
          } else {
            Cbuf_AddText(*(const char **)((char *)keys + v10 + 8));
            Cbuf_AddText("\n");
          }
          return;
        }
        if (a8 <= 199)
          return;
        if ((unsigned int)a8 > 0xFF) {
          v19 = "<OUT OF RANGE>";
        LABEL_93:
          Com_Printf("%s is unbound, use controls menu to set.\n", v19);
          return;
        }
        if ((unsigned int)(a8 - 33) <= 0x5D) {
          Key_KeynumToString(int, int)::tinystr = __toupper(a8);
          byte_CEBA09 = 0;
          v19 = &Key_KeynumToString(int, int)::tinystr;
          goto LABEL_93;
        }
        v19 = keynames;
        if (keynames) {
          if (a8 == dword_311824)
            goto LABEL_93;
          v20 = (const char **)&unk_311828;
          while (1) {
            v19 = *v20;
            if (!*v20)
              break;
            v21 = v20[1];
            v20 += 2;
            if ((const char *)a8 == v21)
              goto LABEL_93;
          }
        }
        v22 = a8 >> 4;
        v23 = a8 & 0xF;
        Key_KeynumToString(int, int)::tinystr = 48;
        byte_CEBA09 = 120;
        if (a8 >> 4 <= 9)
          v24 = v22 + 48;
        else
          v24 = v22 + 87;
        byte_CEBA0A = v24;
        if ((a8 & 0xFu) <= 9)
          v25 = v23 + 48;
        else
          v25 = v23 + 87;
        byte_CEBA0B = v25;
        byte_CEBA0C = 0;
        v19 = &Key_KeynumToString(int, int)::tinystr;
        goto LABEL_93;
      }
    LABEL_61:
      if (CG_KeyInterceptEvent(a8, a9))
        return;
      goto LABEL_23;
    }
  LABEL_59:
    if (a8 != 200) {
      if (!*((_BYTE *)cl + 9))
        goto LABEL_23;
      goto LABEL_61;
    }
    goto LABEL_18;
  }
  if (a9 && ((*((_BYTE *)cl + 4) & 1) != 0 || *(_BYTE *)(com_sv_running + 8) ||
             !*(_BYTE *)(sv_disableClientConsole + 8))) {
    if (*((_DWORD *)keys + 480)) {
      if (!(unsigned __int8)Con_IsActive())
        Con_ToggleConsole_f();
      Con_ToggleConsoleOutput();
    } else {
      Con_ToggleConsole_f();
    }
  }
}

void __cdecl Key_ClearStates() { UNIMPLEMENTED(); }

void __cdecl Key_Bindlist_f() {
  int v0;          // esi
  int v1;          // edi
  const char *v2;  // ecx
  const char *v3;  // ebx
  const char **v4; // edx
  const char *v5;  // eax
  int v6;          // eax
  char v7;         // dl
  char v8;         // al
  char v9;         // al

  v0 = 0;
  v1 = 0;
  do {
    v3 = *(const char **)((char *)keys + v1 + 8);
    if (v3 && *v3) {
      if (v0 == -1) {
        v2 = "<KEY NOT FOUND>";
        goto LABEL_3;
      }
      if ((unsigned int)v0 > 0xFF) {
        v2 = "<OUT OF RANGE>";
      } else {
        if ((unsigned int)(v0 - 33) > 0x5D || v0 == 34 ||
            (Key_KeynumToString(int, int)::tinystr = __toupper(v0),
             byte_CEBA09 = 0, v0 == 59)) {
          v2 = keynames;
          if (keynames) {
            if (dword_311824 == v0)
              goto LABEL_3;
            v4 = (const char **)&unk_311828;
            while (1) {
              v2 = *v4;
              if (!*v4)
                break;
              v5 = v4[1];
              v4 += 2;
              if (v5 == (const char *)v0)
                goto LABEL_3;
            }
          }
          v6 = v0 >> 4;
          v7 = v0 & 0xF;
          Key_KeynumToString(int, int)::tinystr = 48;
          byte_CEBA09 = 120;
          if (v0 >> 4 <= 9)
            v8 = v6 + 48;
          else
            v8 = v6 + 87;
          byte_CEBA0A = v8;
          if ((v0 & 0xFu) <= 9)
            v9 = v7 + 48;
          else
            v9 = v7 + 87;
          byte_CEBA0B = v9;
          byte_CEBA0C = 0;
          v2 = &Key_KeynumToString(int, int)::tinystr;
          goto LABEL_3;
        }
        v2 = &Key_KeynumToString(int, int)::tinystr;
      }
    LABEL_3:
      Com_Printf("%s \"%s\"\n", v2, v3);
    }
    ++v0;
    v1 += 12;
  } while (v0 != 256);
}

void __cdecl Key_Bind_f() {
  int v0;              // esi
  const gentity_s *v1; // eax
  int v2;              // eax
  int v3;              // eax
  int v4;              // ebx
  char *v5;            // eax
  const char *v6;      // eax
  const char *v7;      // eax
  char v8;             // di
  char *v9;            // eax
  const char *v10;     // ebx
  const char *v11;     // eax
  int v12;             // [esp+18h] [ebp-420h]
  int v13;             // [esp+1Ch] [ebp-41Ch]
  char __src[1048];    // [esp+20h] [ebp-418h] BYREF

  v0 = Cmd_Argc();
  if (v0 <= 1) {
    Com_Printf("bind <key> [command] : attach a command to a key\n");
  } else {
    v1 = Cmd_Argv(1);
    v2 = Key_StringToKeynum((int)v1);
    if (v2 == -1) {
      v6 = (const char *)Cmd_Argv(1);
      Com_Printf("\"%s\" isn't a valid key\n", v6);
    } else {
      v3 = __tolower(v2);
      v13 = v3;
      if (v0 == 2) {
        v10 = (const char *)*((_DWORD *)keys + 3 * v3 + 2);
        v11 = (const char *)Cmd_Argv(1);
        if (v10)
          Com_Printf("\"%s\" = \"%s\"\n", v11, v10);
        else
          Com_Printf("\"%s\" is not bound\n", v11);
      } else {
        __src[0] = 0;
        v12 = v0 - 1;
        v4 = 2;
        if (v0 == 3) {
          do {
            v5 = (char *)Cmd_Argv(v4);
            I_strncat(__src, 1024, v5);
            if (v4 != v12)
              I_strncat(__src, 1024, " ");
            ++v4;
          } while (v0 != v4);
        } else {
          do {
            v7 = (const char *)Cmd_Argv(v4);
            if (strchr(v7, 32)) {
              I_strncat(__src, 1024, "\"");
              v8 = 1;
            } else {
              v8 = 0;
            }
            v9 = (char *)Cmd_Argv(v4);
            I_strncat(__src, 1024, v9);
            if (v8)
              I_strncat(__src, 1024, "\"");
            if (v4 != v12)
              I_strncat(__src, 1024, " ");
            ++v4;
          } while (v0 != v4);
        }
        if (v13 != -1) {
          ReplaceStringInternal((const char **)keys + 3 * v13 + 2, __src);
          dvar_modifiedFlags |= 1u;
        }
      }
    }
  }
}

void __cdecl Key_Unbind_f() {
  const gentity_s *v0; // eax
  int v1;              // eax
  const char *v2;      // eax

  if (Cmd_Argc() == 2) {
    v0 = Cmd_Argv(1);
    v1 = Key_StringToKeynum((int)v0);
    if (v1 == -1) {
      v2 = (const char *)Cmd_Argv(1);
      Com_Printf("\"%s\" isn't a valid key\n", v2);
    } else {
      ReplaceStringInternal((const char **)keys + 3 * v1 + 2, (char *)&inData);
      dvar_modifiedFlags |= 1u;
    }
  } else {
    Com_Printf("unbind <key> : remove commands from a key\n");
  }
}

void __cdecl CL_InitKeyCommands() {
  Cmd_AddCommand("bind", Key_Bind_f);
  Cmd_AddCommand("unbind", Key_Unbind_f);
  Cmd_AddCommand("unbindall", (void (*)(void))Key_Unbindall_f);
  Cmd_AddCommand("bindlist", Key_Bindlist_f);
}

struct field_t *chatField;
int *chat_team;
int *key_overstrikeMode;
int *anykeydown;
struct qkey_t *keys;
struct keyname_t *keynames;
struct keyname_t *keynames_localized;
char **frenchNumberKeysMap;
int historyLine;
int nextHistoryLine;
struct field_t g_consoleField;
struct PlayerKeyState *playerKeys;
struct field_t *historyEditLines;
void __cdecl CompleteCmdArgument(void) { UNIMPLEMENTED(); }

void __cdecl ReplaceConsoleInputArgument(int, char const *) { UNIMPLEMENTED(); }

bool __cdecl Console_IsRconCmd(char const *) { UNIMPLEMENTED(); }

void __cdecl keyConcatArgs(void) {
  int v0;              // esi
  int result;          // eax
  const gentity_s *v2; // ebx
  char number;         // al
  char *v4;            // eax

  v0 = 1;
  result = Cmd_Argc();
  if (result > 1) {
    do {
      I_strncat((char *)g_consoleField.buffer, 256, " ");
      v2 = Cmd_Argv(v0);
      number = v2->s.number;
      if (LOBYTE(v2->s.number)) {
        while (number != 32) {
          v2 = (const gentity_s *)((char *)v2 + 1);
          number = v2->s.number;
          if (!LOBYTE(v2->s.number))
            goto LABEL_7;
        }
        I_strncat((char *)g_consoleField.buffer, 256, "\"");
      }
    LABEL_7:
      v4 = (char *)Cmd_Argv(v0);
      I_strncat((char *)g_consoleField.buffer, 256, v4);
      if (LOBYTE(v2->s.number) == 32)
        I_strncat((char *)g_consoleField.buffer, 256, "\"");
      ++v0;
      result = Cmd_Argc();
    } while (v0 < result);
  }
  return result;
}

void __cdecl PrintMatches(char const *) {
  if (!I_strnicmp(a1, shortestMatch, strlen(shortestMatch)))
    Com_Printf("    %s\n", a1);
}

void __cdecl FindMatches(char const *) {
  char *result;   // eax
  int v2;         // edi
  const char *v3; // esi
  int v4;         // ebx

  result =
      (char *)I_strnicmp(__src, completionString, strlen(completionString));
  if (!result) {
    if (++matchCount == 1) {
      result = I_strncpyz(shortestMatch, __src, 1024);
      hasExactMatch = 1;
      return result;
    }
    if (*__src) {
      v3 = __src;
      v2 = 0;
      while (1) {
        v4 = __tolower(shortestMatch[v2]);
        if (v4 != __tolower(*v3))
          break;
        v3 = &__src[++v2];
        if (!__src[v2])
          goto LABEL_5;
      }
      if (*v3) {
        if (!hasExactMatch) {
          result = 0;
          goto LABEL_6;
        }
        if (shortestMatch[v2]) {
          result = 0;
          goto LABEL_6;
        }
      }
    } else {
      v2 = 0;
    }
  LABEL_5:
    result = (char *)1;
  LABEL_6:
    hasExactMatch = (char)result;
    shortestMatch[v2] = 0;
  }
  return result;
}

int __cdecl Key_StringToKeynum(char const *) { UNIMPLEMENTED(); }

void __cdecl ConcatRemaining(char const *, char const *) { UNIMPLEMENTED(); }

void __cdecl CompleteDvarArgument(void) { UNIMPLEMENTED(); }

void __cdecl CompleteCommand(void) { UNIMPLEMENTED(); }
