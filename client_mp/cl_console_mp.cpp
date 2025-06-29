float __cdecl ceil(float)
{
  UNIMPLEMENTED();
}

void __cdecl Vec4Scale(float const *const, float, float *const)
{
  UNIMPLEMENTED();
}

int __cdecl I_strlen(char const *)
{
  UNIMPLEMENTED();
}

bool __cdecl Con_IsActive()
{
  return *((_BYTE *)cl + 4) & 1;
}

void __cdecl Con_Bottom()
{
  int result; // eax

  result = dword_EFB204;
  dword_EFB20C = dword_EFB204;
  return result;
}

void __cdecl Con_Top()
{
  int result; // eax
  int v1;     // edx

  result = dword_EFB218;
  dword_EFB20C = dword_EFB218;
  v1 = dword_EFB204 - dword_EFB218;
    if (dword_EFB204 - dword_EFB218 >= dword_EFB218) {
      result = v1 + 1;
      dword_EFB20C = v1 + 1;
    }
  return result;
}

void __cdecl Con_PageDown()
{
  int result; // eax

  dword_EFB20C += 2;
  result = dword_EFB204;
  if (dword_EFB20C <= dword_EFB204)
    result = dword_EFB20C;
  dword_EFB20C = result;
  return result;
}

void __cdecl Con_PageUp()
{
  int result; // eax

  result = dword_EFB20C - 2;
  dword_EFB20C = result;
    if (dword_EFB204 - result >= dword_EFB218) {
      result = dword_EFB204 - dword_EFB218 + 1;
      dword_EFB20C = result;
    }
  return result;
}

void __cdecl Con_ToggleConsoleOutput()
{
  byte_EFB21C = byte_EFB21C == 0;
}

bool __cdecl Con_AnySpaceAfterCommand()
{
  field_t *i;       // ebx
  int v1;           // eax
  signed __int8 v2; // al
  uint8_t *buffer;  // ebx

    for (i = &g_consoleField;; i = (field_t *)((char *)i + 1)) {
      v1 = (char)i->buffer[0];
      if ((v1 & 0xFFFFFF80) != 0)
        break;
      if (((_DefaultRuneLocale.__runetype[v1] >> 14) & 1) == 0)
        goto LABEL_6;
    LABEL_3:;
    }
  if (__maskrune(v1, 0x4000))
    goto LABEL_3;
LABEL_6:
  v2 = i->buffer[0];
    if (v2) {
      buffer = i->buffer;
        do {
            if ((v2 & 0xFFFFFF80) != 0) {
              if (__maskrune(v2, 0x4000))
                return 1;
            }
            else if (((_DefaultRuneLocale.__runetype[v2] >> 14) & 1) != 0) {
              return 1;
            }
          v2 = *++buffer;
        }
      while (v2);
    }
  return 0;
}

void __cdecl Con_AutoCompleteFromList(char const **const strings,
                                      int stringCount, char const *prefix,
                                      char *const completed,
                                      int sizeofCompleted)
{
  size_t v5;    // esi
  char *result; // eax
  int i;        // ebx
  char *v8;     // edi
  char v9;      // dl
  char *v10;    // edx

  v5 = strlen(a3);
  result = __dst;
  *__dst = 0;
    if (a2 > 0) {
        for (i = 0; i != a2; ++i) {
          v8 = (char *)a1[i];
          result = (char *)strnicmp(a3, v8, v5);
            if (!result) {
                if (*__dst) {
                  result = &__dst[v5];
                  v9 = __dst[v5];
                    if (v9 == v8[v5] && v9) {
                      ++result;
                      v10 = &v8[v5];
                        while (*result == v10[1]) {
                          ++v10;
                          if (!*result)
                            break;
                          ++result;
                        }
                    }
                  *result = 0;
                }
                else {
                  result = I_strncpyz(__dst, v8, a5);
                }
            }
        }
    }
  return result;
}

void __cdecl CL_ConsoleFixPosition()
{
  int result; // eax

  CL_ConsolePrint(PMSG_CONSOLE, "\n", 0, PMSG_CONSOLE);
  result = dword_EFB204 - 1;
  HIDWORD(qword_EFB208) = dword_EFB204 - 1;
  return result;
}

void __cdecl Con_OpenConsoleOutput(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_ToggleConsole_f()
{
  UNIMPLEMENTED();
}

void __cdecl Con_SwitchToLocalClient(int)
{
  UNIMPLEMENTED();
}

unsigned char __cdecl CL_GetHudMsgIconMaterialIndex(char const *)
{
  UNIMPLEMENTED();
}

char const *__cdecl CL_GetHudMsgIconMaterialName(unsigned char)
{
  return hudMsgIconMaterials[a1];
}

void __cdecl Con_Shutdown()
{
  int result; // eax

    for (result = registeredIconMaterialCount; registeredIconMaterialCount;
         result = registeredIconMaterialCount) {
      registeredIconMaterialCount = result - 1;
      Z_FreeInternal((void *)hudMsgIconMaterials[result - 1]);
      result = registeredIconMaterialCount;
      if (!registeredIconMaterialCount)
        break;
      Z_FreeInternal(
          (void *)hudMsgIconMaterials[--registeredIconMaterialCount]);
    }
  return result;
}

void __cdecl Con_ClearSubtitles()
{
  UNIMPLEMENTED();
}

void __cdecl Con_ClearNotify()
{
  UNIMPLEMENTED();
}

void __cdecl Con_CloseConsole(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_OpenConsole(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_Close()
{
  UNIMPLEMENTED();
}

char const *__cdecl Con_TokenizeInput()
{
  UNIMPLEMENTED();
}

void __cdecl CL_RegisterHudMsgIconMaterial(char const *name)
{
  int v1;          // edi
  int v2;          // esi
  const char **v3; // ebx
  char *result;    // eax

  v1 = registeredIconMaterialCount;
    if (registeredIconMaterialCount <= 0) {
    LABEL_5:
      result = CopyStringInternal(__s2);
      hudMsgIconMaterials[v1] = (int)result;
      ++registeredIconMaterialCount;
    }
    else {
      v2 = 0;
      v3 = (const char **)hudMsgIconMaterials;
        while (1) {
          result = (char *)strcmp(*v3, __s2);
          if (!result)
            break;
          ++v2;
          ++v3;
          if (v2 == v1)
            goto LABEL_5;
        }
    }
  return result;
}

void __cdecl Con_DrawSolidConsole(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawSubtitles(int xPos, int yPos, int charHeight, float alpha,
                               enum msgwnd_mode_t mode)
{
  return Con_DrawMessageWindow((int *)(dword_EFB230 + 2680), a1, a2, a4, 1.0,
                               a3, 1, 1, a5);
}

void __cdecl Con_DrawMiniConsole(int xPos, int yPos, float alpha)
{
  *(_DWORD *)(dword_EFB230 + 4028) = *(_DWORD *)(con_miniconlines + 8);
  return Con_DrawMessageWindow((int *)(dword_EFB230 + 4020), a1, a2, a3, 1.0,
                               (MessageWindow *)0xC, 1, 1, 0);
}

void __cdecl Con_DrawBoldMessages(int xPos, int yPos, float alpha,
                                  enum msgwnd_mode_t mode)
{
  return Con_DrawMessageWindow((int *)(dword_EFB230 + 1340), a1, a2, a3, 1.0,
                               (MessageWindow *)0xC, 7, 7, a4);
}

void __cdecl Con_DrawNotify(int xPos, int yPos, float alpha,
                            enum msgwnd_mode_t mode)
{
  return Con_DrawMessageWindow((int *)dword_EFB230, a1, a2, a3, 1.0,
                               (MessageWindow *)0xC, 1, 3, a4);
}

void __cdecl Con_DrawConsole()
{
  UNIMPLEMENTED();
}

void __cdecl CL_DeathMessagePrint(
    char const *attackerName, float const *const attackerColor,
    char const *victimName, float const *const victimColor,
    char const *iconShader, float iconWidth, float iconHeight,
    float const *const iconColor, bool horzFlipIcon)
{
  const char *v9;   // ebx
  int result;       // eax
  int v11;          // eax
  int v12;          // edi
  int v13;          // ecx
  int v14;          // eax
  int v15;          // ecx
  int v16;          // eax
  char v17;         // cl
  __int16 v18;      // ax
  const char *v19;  // edx
  int v20;          // esi
  char v21;         // al
  __int16 i;        // bx
  int v23;          // ecx
  const char *v24;  // edi
  char v25;         // al
  __int16 v26;      // bx
  int v27;          // ecx
  const char *v28;  // edi
  const char *v29;  // esi
  int v30;          // esi
  const char **v31; // ebx
  char v32;         // al
  char v33;         // al
  char v34;         // al
  __int16 v35;      // di
  int v36;          // ecx
  const char *v37;  // esi
  const char *v38;  // edx
  int v39;          // edi
  char v40;         // al
  int v41;          // ecx
  const char *v42;  // ebx
  char v43;         // al
  char v44;         // al
  int v45;          // [esp+1Ch] [ebp-5Ch]
  int v46;          // [esp+34h] [ebp-44h]
  int v47;          // [esp+38h] [ebp-40h]
  int v48;          // [esp+3Ch] [ebp-3Ch]
  float v49;        // [esp+40h] [ebp-38h]
  int v50;          // [esp+4Ch] [ebp-2Ch]
  int v51;          // [esp+50h] [ebp-28h]
  int v52;          // [esp+54h] [ebp-24h]
  __int16 v53;      // [esp+5Ch] [ebp-1Ch]

  v9 = a1;
  result = cl_noprint;
  if (cl_noprint && *(_BYTE *)(cl_noprint + 8))
    return result;
  if (!con)
    Con_OneTimeInit();
  v49 = floorf((float)(1000.0 * *(float *)(con_gamemessagetime + 8)) + 0.5);
  v11 = 0;
  if ((int)v49 >= 0)
    v11 = (int)v49;
  v50 = v11;
  if ((int)qword_EFB208 > 0)
    Con_Linefeed(dword_EFB210, v11);
  v53 = (unsigned __int8)ColorIndex(55);
    if (*a1) {
      CL_AddConsoleInfoColor(10, (unsigned int *)a2);
      v48 = dword_EFB204 % dword_EFB218;
      v34 = *a1;
      v35 = *(unsigned __int8 *)a1;
        if (*a1) {
            do {
              v36 = qword_EFB208;
              if ((int)qword_EFB208 >= dword_EFB214)
                break;
                if (v34 == 94) {
                  v37 = v9 + 1;
                  v43 = v9[1];
                    if (v43 && v43 != 94 && v43 > 47 && v43 <= 57) {
                      v9 += 2;
                      goto LABEL_56;
                    }
                }
                else {
                  v37 = v9 + 1;
                  if (v34 == 10 || v34 == 13)
                    goto LABEL_55;
                }
              word_EDB204[(_DWORD)qword_EFB208 + dword_EFB214 * v48] =
                  v35 | (v53 << 8);
              LODWORD(qword_EFB208) = v36 + 1;
            LABEL_55:
              v9 = v37;
            LABEL_56:
              v34 = *v9;
              v35 = *(unsigned __int8 *)v9;
            }
          while (*v9);
        }
      v47 = dword_EFB204 % dword_EFB218;
      v38 = " ";
      v39 = dword_EFB214;
        while (1) {
            while (1) {
              v40 = *v38;
              if (!*v38)
                goto LABEL_10;
              v41 = qword_EFB208;
              if ((int)qword_EFB208 >= v39)
                goto LABEL_10;
              if (v40 == 94)
                break;
              v42 = v38 + 1;
              if (v40 != 10 && v40 != 13)
                goto LABEL_63;
            LABEL_64:
              v38 = v42;
            }
          v42 = v38 + 1;
          v44 = v38[1];
            if (!v44 || v44 == 94 || v44 <= 47 || v44 > 57) {
            LABEL_63:
              word_EDB204[(_DWORD)qword_EFB208 + v39 * v47] =
                  *(unsigned __int8 *)v38 | (unsigned __int16)(v53 << 8);
              LODWORD(qword_EFB208) = v41 + 1;
              goto LABEL_64;
            }
          v38 += 2;
        }
    }
LABEL_10:
  CL_AddConsoleInfoColor(13, (unsigned int *)a8);
  v12 = dword_EFB204;
  v13 = qword_EFB208;
  v14 = (int)(float)(a6 * 32.0);
  if (a9)
    BYTE1(v14) |= 0x13u;
  else
    BYTE1(v14) |= 0x10u;
  word_EDB204[(_DWORD)qword_EFB208 +
              dword_EFB214 * (dword_EFB204 % dword_EFB218)] = v14;
  v15 = v13 + 1;
  v16 = (int)(float)(32.0 * a7);
  BYTE1(v16) |= 0x11u;
  word_EDB204[v15 + dword_EFB214 * (v12 % dword_EFB218)] = v16;
  v51 = v15 + 1;
  LODWORD(qword_EFB208) = v15 + 1;
  v52 = registeredIconMaterialCount;
    if (registeredIconMaterialCount > 0) {
      v30 = 0;
      v31 = (const char **)hudMsgIconMaterials;
        while (strcmp(*v31, __s2)) {
          ++v30;
          ++v31;
          if (v30 == v52)
            goto LABEL_13;
        }
      v17 = v30;
    }
    else {
    LABEL_13:
      v17 = 0;
    }
  LOBYTE(v18) = v17;
  HIBYTE(v18) = 18;
  word_EDB204[v51 + dword_EFB214 * (v12 % dword_EFB218)] = v18;
  LODWORD(qword_EFB208) = qword_EFB208 + 1;
  v46 = v12 % dword_EFB218;
  v19 = " ";
  v20 = dword_EFB214;
  v21 = _sep[0];
    for (i = (unsigned __int8)_sep[0]; *v19; i = *(unsigned __int8 *)v19) {
      v23 = qword_EFB208;
      if ((int)qword_EFB208 >= v20)
        break;
        if (v21 == 94) {
          v24 = v19 + 1;
          v32 = v19[1];
            if (v32 && v32 != 94 && v32 > 47 && v32 <= 57) {
              v19 += 2;
              goto LABEL_21;
            }
        }
        else {
          v24 = v19 + 1;
          if (v21 == 10 || v21 == 13)
            goto LABEL_20;
        }
      word_EDB204[(_DWORD)qword_EFB208 + v20 * v46] = i | (v53 << 8);
      LODWORD(qword_EFB208) = v23 + 1;
    LABEL_20:
      v19 = v24;
    LABEL_21:
      v21 = *v19;
    }
  CL_AddConsoleInfoColor(10, (unsigned int *)a4);
    if ((int)(strlen(a3) + 1 + qword_EFB208 + 2) >= dword_EFB214) {
      Con_Linefeed(1, v50);
      CL_AddConsoleInfoColor(10, (unsigned int *)a4);
    }
  v45 = dword_EFB204 % dword_EFB218;
  v25 = *a3;
  v26 = *(unsigned __int8 *)a3;
    if (*a3) {
        do {
          v27 = qword_EFB208;
          if ((int)qword_EFB208 >= dword_EFB214)
            break;
            if (v25 == 94) {
              v28 = a3 + 1;
              v33 = a3[1];
                if (v33 && v33 != 94 && v33 > 47 && v33 <= 57) {
                  a3 += 2;
                  v29 = a3;
                  goto LABEL_31;
                }
            }
            else {
              v28 = a3 + 1;
              if (v25 == 10 || v25 == 13)
                goto LABEL_30;
            }
          word_EDB204[(_DWORD)qword_EFB208 + dword_EFB214 * v45] =
              v26 | (v53 << 8);
          LODWORD(qword_EFB208) = v27 + 1;
        LABEL_30:
          a3 = v28;
          v29 = v28;
        LABEL_31:
          v25 = *v29;
          v26 = *(unsigned __int8 *)v29;
        }
      while (*v29);
    }
  result = Con_Linefeed(1, v50);
  dword_EFB210 = 1;
  return result;
}

void __cdecl CL_ConsolePrint(enum print_msg_type_t type, char const *txt,
                             int duration, int linewidth)
{
  int v4;             // edi
  const char *result; // eax
  char *i;            // esi
  unsigned int v7;    // ebx
  size_t v8;          // eax
  char *v9;           // eax
  char *v10;          // [esp+1Ch] [ebp-102Ch]
  float v11;          // [esp+20h] [ebp-1028h]
  float v12;          // [esp+24h] [ebp-1024h]
  float v13;          // [esp+28h] [ebp-1020h]
  char *v14;          // [esp+2Ch] [ebp-101Ch]
  char __dst[4120];   // [esp+30h] [ebp-1018h] BYREF

  v4 = a3;
  result = (const char *)cl_noprint;
  if (!cl_noprint || *(_BYTE *)(cl_noprint + 8) || a1 == PMSG_LOGFILE)
    return result;
    if (con) {
      if (a3)
        goto LABEL_6;
    }
    else {
      Con_OneTimeInit();
      if (a3)
        goto LABEL_6;
    }
    if (a1 == PMSG_GAME) {
      v12 = floorf((float)(1000.0 * *(float *)(con_gamemessagetime + 8)) + 0.5);
      v4 = (int)v12;
      goto LABEL_6;
    }
    if (a1 <= PMSG_GAME) {
      if (a1)
        goto LABEL_16;
      v13 = floorf((float)(1000.0 * *(float *)(con_minicontime + 8)) + 0.5);
      v4 = (int)v13;
    LABEL_6:
      if (v4 < 0)
        v4 = 0;
      goto LABEL_8;
    }
    if (a1 == PMSG_BOLDGAME) {
      v11 = floorf((float)(1000.0 * *(float *)(con_boldgamemessagetime + 8)) +
                   0.5);
      v4 = (int)v11;
      goto LABEL_6;
    }
    if (a1 == PMSG_SUBTITLE) {
      v4 = 5000;
      goto LABEL_8;
    }
LABEL_16:
  v4 = 0;
LABEL_8:
  v14 = (char *)(unsigned __int8)ColorIndex(55);
    if ((unsigned int)(a1 - 1) <= 1) {
        for (i = __src;; i = v10 + 1) {
          v9 = strchr(i, 10);
          v10 = v9;
          if (!v9)
            break;
          v7 = v9 - i + 1;
          v8 = v7;
            if (v7 > 0xFFF) {
              v7 = 4095;
              v8 = 4095;
            }
          memcpy(__dst, i, v8);
          __dst[v7] = 0;
          v14 = (char *)CL_ConsolePrint_AddLine(a1, __dst, v4, a4, v14);
        }
    }
    else {
      i = __src;
    }
  return CL_ConsolePrint_AddLine(a1, i, v4, a4, v14);
}

void __cdecl Con_DrawSay(int y)
{
  void *result;       // eax
  Font_s *FontHandle; // edi
  char v3;            // al
  const char *v4;     // esi
  int v5;             // ebx
  int v6;             // eax
  int v7;             // eax
  float v8;           // [esp+3Ch] [ebp-1Ch]

  result = cl;
    if ((*((_BYTE *)cl + 4) & 0x10) != 0) {
      FontHandle = (Font_s *)UI_GetFontHandle(0, 0.20833333);
      if (*(_DWORD *)chat_team)
        v3 = SEH_SafeTranslateString("EXE_SAYTEAM");
      else
        v3 = SEH_SafeTranslateString("EXE_SAY");
      v4 = (const char *)va("%s: ", v3);
      v8 = dword_121C7B0(FontHandle, 1045779797);
      v5 = (int)**(float **)(cg_hudSayPosition + 8);
      v6 = dword_121C7B8(FontHandle);
      CL_DrawText(v4, 0x7FFFFFFF, FontHandle, (float)v5,
                  (float)a1 + (float)((float)v6 * v8), 1, 1, v8, v8, colorWhite,
                  3);
      v7 = dword_121C7B4(v4, 0, FontHandle);
      return (void *)Field_Draw(chatField, (int)(float)((float)v7 * v8) + v5,
                                a1, 1, 1, 1);
    }
  return result;
}

void __cdecl Con_Init()
{
  UNIMPLEMENTED();
}

int g_console_field_width;
float g_console_char_height;
struct dvar_s const *const con_restricted;
struct dvar_s const *const con_boldgamemessagetime;
struct dvar_s const *const con_gamemessagetime;
struct dvar_s const *const con_minicontime;
struct dvar_s const *const con_miniconlines;

int __cdecl ConDrawInput_TextFieldFirstArgChar(void)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_Over(int)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_Newline(void)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_TextLimitChars(char const *, int, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_Text(char const *, float const *const)
{
  UNIMPLEMENTED();
}

int __cdecl ConDrawInput_TextWidth(char const *)
{
  UNIMPLEMENTED();
}

int __cdecl ConDrawInput_TextHeight(struct Font_s *)
{
  UNIMPLEMENTED();
}

void __cdecl CL_AddDeathMessageText(char const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl CL_AddConsoleInfoChar(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl Con_CopyCurrentConsoleLineText(struct MessageLine *)
{
  UNIMPLEMENTED();
}

void __cdecl Con_InitMessageWindow(struct MessageWindow *, struct MessageLine *,
                                   int, int, int, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl Con_ClearMessageWindow(struct MessageWindow *)
{
  UNIMPLEMENTED();
}

void __cdecl Con_Clear_f(void)
{
  int *v0;    // ebx
  int result; // eax

  v0 = &con;
    do {
      *((_WORD *)v0 + 2) = ((unsigned __int16)ColorIndex(55) << 8) | 0x20;
      v0 = (int *)((char *)v0 + 2);
    }
  while (v0 != (int *)&unk_EFB200);
  result = dword_EFB204;
  HIDWORD(qword_EFB208) = dword_EFB204;
  return result;
}

void __cdecl Con_ChatModeTeam_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_ChatModePublic_f(void)
{
  UNIMPLEMENTED();
}

void __cdecl CL_ShutdownHudMsgIconMaterials(void)
{
  UNIMPLEMENTED();
}

char const *__cdecl Con_GetVersionString(void)
{
  UNIMPLEMENTED();
}

bool __cdecl ConDrawInput_StringMatchesInputText(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl ConDraw_Box(float, float, float, float, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_TextAndOver(char const *, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl Con_InitMessageBuffer(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_UpdateMessageWindowLine(struct MessageWindow *, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl Con_ClearMiniConsole(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawOutputVersion(float, float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawOutputText(float, float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawOutputScrollBar(float, float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_CmdMatch(char const *)
{
  int result; // eax

  result = I_strnicmp(a1, (char *)LODWORD(flt_F00244), SLODWORD(flt_F00248));
    if (!result) {
      dword_121C7BC(a1, 0x7FFFFFFF, dword_14C13C0, dword_F00250,
                    *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                    1065353216, 1065353216, &con_inputCommandMatchColor, 0);
      *(float *)&dword_F00254 =
          *(float *)&dword_F00254 + *(float *)&dword_F0025C;
      result = dword_F00258;
      dword_F00250 = dword_F00258;
    }
  return result;
}

int __cdecl ConDrawInput_CompareStrings(void const *, void const *)
{
  return I_stricmp(*a1, *a2);
}

void __cdecl ConDrawInput_DvarMatch(char const *)
{
  int result;                     // eax
  const gentity_s *VariantString; // eax

  result = I_strnicmp(a1, (char *)LODWORD(flt_F00244), SLODWORD(flt_F00248));
    if (!result) {
      dword_121C7BC(a1, 24, dword_14C13C0, dword_F00250,
                    *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                    1065353216, 1065353216, &con_inputDvarMatchColor, 0);
      *(float *)&dword_F00250 = *(float *)&dword_F00250 + 200.0;
      VariantString = Dvar_GetVariantString(a1);
      dword_121C7BC(VariantString, 40, dword_14C13C0, dword_F00250,
                    *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                    1065353216, 1065353216, &con_inputDvarValueColor, 0);
      *(float *)&dword_F00254 =
          *(float *)&dword_F00254 + *(float *)&dword_F0025C;
      result = dword_F00258;
      dword_F00250 = dword_F00258;
    }
  return result;
}

void __cdecl ConDrawInput_IncrMatchCounter(char const *)
{
  int result; // eax

  result = I_strnicmp(a1, (char *)LODWORD(flt_F00244), SLODWORD(flt_F00248));
    if (!result) {
      ++LODWORD(conDrawInputGlob);
      result = 1;
      if (a1[LODWORD(flt_F00248)])
        result = (unsigned __int8)byte_F0024C;
      byte_F0024C = result;
    }
  return result;
}

void __cdecl ConDrawInput_Box(int, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl CL_AddConsoleInfoColor(int, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl Con_UpdateNotifyLine(enum print_msg_type_t, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl Con_CheckResize(void)
{
  int v0;         // eax
  int v1;         // eax
  int v2;         // ecx
  int v3;         // eax
  int v4;         // eax
  int *v5;        // ebx
  int v6;         // esi
  int v7;         // ebx
  int v8;         // edi
  int v9;         // ebx
  int v10;        // ebx
  int v11;        // ebx
  int v12;        // ebx
  int *v13;       // ebx
  float v14;      // [esp+24h] [ebp-44h]
  int i;          // [esp+28h] [ebp-40h]
  int v16;        // [esp+2Ch] [ebp-3Ch]
  int v17;        // [esp+30h] [ebp-38h]
  int v18;        // [esp+34h] [ebp-34h]
  void *__dst;    // [esp+38h] [ebp-30h]
  int v20;        // [esp+3Ch] [ebp-2Ch]
  LargeLocal v21; // [esp+4Ch] [ebp-1Ch] BYREF

  LargeLocal::LargeLocal(&v21, (int)&loc_20000);
  __dst = (void *)LargeLocal::GetBuf(&v21);
  flt_EFB220 = 4.0;
  flt_EFB224 = 4.0;
  flt_EFB228 = -4.0;
  flt_EFB22C = -4.0;
  CalcScreenX(&flt_EFB220, 1);
  CalcScreenY(&flt_EFB224, 1);
  CalcScreenX(&flt_EFB228, 3);
  CalcScreenY(&flt_EFB22C, 3);
  flt_EFB220 = floorf(flt_EFB220);
  flt_EFB224 = floorf(flt_EFB224);
  v14 = floorf(flt_EFB228);
  flt_EFB228 = v14;
  flt_EFB22C = floorf(flt_EFB22C);
  v0 = (int)(float)(v14 - flt_EFB220);
  if (v0 > 639)
    v1 = v0 >> 3;
  else
    v1 = 80;
  v2 = v1 - 2;
  v20 = dword_EFB214;
    if (v1 - 2 != dword_EFB214) {
        if (v2 <= 0) {
          dword_EFB214 = 78;
          dword_EFB218 = 840;
          v13 = &con;
            do {
              *((_WORD *)v13 + 2) =
                  ((unsigned __int16)ColorIndex(55) << 8) | 0x20;
              v13 = (int *)((char *)v13 + 2);
            }
          while (v13 != (int *)&unk_EFB200);
        }
        else {
          dword_EFB214 = v1 - 2;
          v16 = dword_EFB218;
          dword_EFB218 = 0x10000 / v2;
          v3 = v16;
          if (v16 > 0x10000 / v2)
            v3 = 0x10000 / v2;
          v17 = v3;
          v4 = v20;
          if (v20 > v2)
            v4 = v2;
          v18 = v4;
          memcpy(__dst, word_EDB204, (size_t)&loc_20000);
          v5 = &con;
            do {
              *((_WORD *)v5 + 2) =
                  ((unsigned __int16)ColorIndex(55) << 8) | 0x20;
              v5 = (int *)((char *)v5 + 2);
            }
          while (&unk_EFB200 != (_UNKNOWN *)v5);
            if (v17 > 0) {
                for (i = 0; i != v17; ++i) {
                    if (v18 > 0) {
                      v6 = 0;
                      v7 = dword_EFB214 * (dword_EFB218 + ~i);
                      v8 = dword_EFB204 - i + v16;
                        do {
                          word_EDB204[v6 + v7] =
                              *((_WORD *)__dst + v6 + v20 * (v8 % v16));
                          ++v6;
                        }
                      while (v18 != v6);
                    }
                }
            }
          v9 = dword_EFB230;
          memset(*(void **)dword_EFB230, 0,
                 164 * *(_DWORD *)(dword_EFB230 + 8));
          *(_DWORD *)(v9 + 4) = 0;
          v10 = dword_EFB230 + 1340;
          memset(*(void **)(dword_EFB230 + 1340), 0,
                 164 * *(_DWORD *)(dword_EFB230 + 1348));
          *(_DWORD *)(v10 + 4) = 0;
          v11 = dword_EFB230 + 4020;
          memset(*(void **)(dword_EFB230 + 4020), 0,
                 164 * *(_DWORD *)(dword_EFB230 + 4028));
          *(_DWORD *)(v11 + 4) = 0;
          v12 = dword_EFB230 + 2680;
          memset(*(void **)(dword_EFB230 + 2680), 0,
                 164 * *(_DWORD *)(dword_EFB230 + 2688));
          *(_DWORD *)(v12 + 4) = 0;
        }
      dword_EFB204 = dword_EFB218 - 1;
      dword_EFB20C = dword_EFB218 - 1;
    }
  LargeLocal::~LargeLocal(&v21);
}

void __cdecl Con_DrawOuputWindow(void)
{
  char *BuildNumber; // eax
  char *v1;          // eax
  int result;        // eax
  int v3;            // esi
  int v4;            // ebx
  int v5;            // [esp+2Ch] [ebp-7Ch]
  float v6;          // [esp+40h] [ebp-68h]
  float v7;          // [esp+50h] [ebp-58h]
  float v8;          // [esp+60h] [ebp-48h]
  float v9;          // [esp+64h] [ebp-44h]
  float v10;         // [esp+6Ch] [ebp-3Ch]
  float v11;         // [esp+74h] [ebp-34h]
  float v12[10];     // [esp+80h] [ebp-28h] BYREF

  v8 = flt_EFB220;
  v9 = flt_EFB228 - flt_EFB220;
  v7 = flt_EFB224 + 32.0;
  v6 = (float)(flt_EFB22C - flt_EFB224) - 32.0;
  ConDraw_Box(*(float **)(con_outputWindowColor + 8), flt_EFB220,
              flt_EFB224 + 32.0, flt_EFB228 - flt_EFB220, v6);
  BuildNumber = getBuildNumber();
  v1 = va("Build %s %s", BuildNumber, "MacOSXS-i386");
  SCR_DrawSmallStringExt(
      (int)(float)(v8 + 6.0),
      (int)(float)((float)((float)(v6 - 12.0) - 16.0) + (float)(v7 + 6.0)), v1,
      &con_versionColor);
  ConDraw_Box(*(float **)(con_outputBarColor + 8),
              (float)((float)(v9 - 12.0) + (float)(v8 + 6.0)) - 10.0, v7 + 6.0,
              10.0, v6 - 12.0);
  ConDraw_Box(*(float **)(con_outputSliderColor + 8),
              (float)((float)(v9 - 12.0) + (float)(v8 + 6.0)) - 10.0,
              (float)(v7 + 6.0) +
                  (float)((float)(1.0 - (float)((float)(dword_EFB204 -
                                                        HIDWORD(qword_EFB208)) /
                                                (float)(dword_EFB218 - 1))) *
                          (float)((float)((float)((float)(v7 + 6.0) +
                                                  (float)(v6 - 12.0)) -
                                          10.0) -
                                  (float)(v7 + 6.0))),
              10.0, 10.0);
  v11 = (float)(v6 - 12.0) - 28.0;
  result = CL_LookupColor(55, v12);
  v5 = (int)(float)(v11 * 0.0625);
  v3 = (unsigned __int64)(qword_EFB208 - 1) >> 32;
  v10 = (float)(v7 + 6.0) + v11;
    if (v5 > 0 && v3 >= 0) {
      v4 = 0;
        do {
          result = dword_EFB204 - (v3 - v4);
            if (result >= dword_EFB218) {
              if (v5 == ++v4)
                return result;
            }
            else {
              v10 = v10 - 16.0;
              result = SCR_DrawConsoleString(
                  (int)(float)(v8 + 6.0), (int)v10,
                  &word_EDB204[dword_EFB214 * ((v3 - v4++) % dword_EFB218)],
                  dword_EFB214, v12);
              if (v5 == v4)
                return result;
            }
          result = v3 + 1;
        }
      while (v4 != v3 + 1);
    }
  return result;
}

void __cdecl Con_DrawStringOnHUD(int, int, int, int, int, short const *, int,
                                 float, float, int)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_DetailedCmdMatch(char const *)
{
  char **AutoCompleteFileList; // eax
  void **v2;                   // ebx
  int v3[3];                   // [esp+3Ch] [ebp-Ch] BYREF

    if (!I_strnicmp((char *)a1, (char *)LODWORD(flt_F00244),
                    SLODWORD(flt_F00248)) &&
        (!byte_F0024C || !*((_BYTE *)a1 + LODWORD(flt_F00248)))) {
      ConDraw_Box(
          *(float **)(con_inputHintBoxColor + 8), *(float *)&dword_F00250 - 6.0,
          *(float *)&dword_F00254 - 6.0,
          (float)(flt_EFB228 - flt_EFB220) -
              (float)((float)(*(float *)&dword_F00250 - 6.0) - flt_EFB220),
          *(float *)&dword_F0025C + 12.0);
      dword_121C7BC(a1, 0x7FFFFFFF, dword_14C13C0, dword_F00250,
                    *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                    1065353216, 1065353216, &con_inputCommandMatchColor, 0);
      *(float *)&dword_F00254 =
          *(float *)&dword_F00254 + *(float *)&dword_F0025C;
      dword_F00250 = dword_F00258;
        if (Cmd_Argc() == 2) {
          AutoCompleteFileList =
              (char **)Cmd_GetAutoCompleteFileList((char *)a1, v3);
          v2 = (void **)AutoCompleteFileList;
            if (v3[0]) {
              ConDrawInput_AutoCompleteArg(AutoCompleteFileList, v3[0]);
              FS_FreeFileList(v2);
            }
        }
    }
}

void __cdecl ConDrawInput_AutoCompleteArg(char const **const, int)
{
  UNIMPLEMENTED();
}

void __cdecl Con_Linefeed(enum print_msg_type_t, int)
{
  UNIMPLEMENTED();
}

void __cdecl CL_InitHudMsgIconMaterials(void)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawMessageWindowBottomUp(struct MessageWindow *, int, int,
                                           int, int, int, float, float, int)
{
  UNIMPLEMENTED();
}

void __cdecl ConDrawInput_DetailedDvarMatch(char const *)
{
  int result;           // eax
  bool HasLatchedValue; // bl
  char *v3;             // eax
  float v4;             // xmm0_4
  int v5;               // eax
  char *v6;             // eax
  char *v7;             // eax
  DvarLimits v8;        // [esp+10h] [ebp-458h]
  dvar_s *Var;          // [esp+3Ch] [ebp-42Ch]
  char v10[1024];       // [esp+4Ch] [ebp-41Ch] BYREF
  int v11;              // [esp+44Ch] [ebp-1Ch] BYREF

  result = I_strnicmp(a1, (char *)LODWORD(flt_F00244), SLODWORD(flt_F00248));
    if (!result) {
        if (!byte_F0024C ||
            (result = LODWORD(flt_F00248), !a1[LODWORD(flt_F00248)])) {
          Var = (dvar_s *)Dvar_FindVar(a1);
          HasLatchedValue = Dvar_HasLatchedValue(Var);
          v11 = 3 - !HasLatchedValue;
          ConDraw_Box(
              *(float **)(con_inputHintBoxColor + 8),
              *(float *)&dword_F00250 - 6.0, *(float *)&dword_F00254 - 6.0,
              (float)(flt_EFB228 - flt_EFB220) -
                  (float)((float)(*(float *)&dword_F00250 - 6.0) - flt_EFB220),
              (float)((float)v11 * *(float *)&dword_F0025C) + 12.0);
          dword_121C7BC(a1, 24, dword_14C13C0, dword_F00250,
                        *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                        1065353216, 1065353216, &con_inputDvarMatchColor, 0);
          *(float *)&dword_F00250 = *(float *)&dword_F00250 + 200.0;
          v3 = Dvar_DisplayableValue(Var);
          dword_121C7BC(v3, 40, dword_14C13C0, dword_F00250,
                        *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                        1065353216, 1065353216, &con_inputDvarValueColor, 0);
          v4 = *(float *)&dword_F00254 + *(float *)&dword_F0025C;
          *(float *)&dword_F00254 =
              *(float *)&dword_F00254 + *(float *)&dword_F0025C;
          v5 = dword_F00258;
          dword_F00250 = dword_F00258;
            if (HasLatchedValue) {
              dword_121C7BC("  latched value", 0x7FFFFFFF, dword_14C13C0,
                            dword_F00258, v4 + *(float *)&dword_F0025C,
                            1065353216, 1065353216,
                            &con_inputDvarInactiveValueColor, 0);
              *(float *)&dword_F00250 = *(float *)&dword_F00250 + 200.0;
              v7 = Dvar_DisplayableLatchedValue(Var);
              dword_121C7BC(v7, 40, dword_14C13C0, dword_F00250,
                            *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                            1065353216, 1065353216,
                            &con_inputDvarInactiveValueColor, 0);
              v4 = *(float *)&dword_F00254 + *(float *)&dword_F0025C;
              *(float *)&dword_F00254 =
                  *(float *)&dword_F00254 + *(float *)&dword_F0025C;
              v5 = dword_F00258;
              dword_F00250 = dword_F00258;
            }
          dword_121C7BC("  default", 0x7FFFFFFF, dword_14C13C0, v5,
                        v4 + *(float *)&dword_F0025C, 1065353216, 1065353216,
                        &con_inputDvarInactiveValueColor, 0);
          *(float *)&dword_F00250 = *(float *)&dword_F00250 + 200.0;
          v6 = Dvar_DisplayableResetValue(Var);
          dword_121C7BC(v6, 40, dword_14C13C0, dword_F00250,
                        *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                        1065353216, 1065353216,
                        &con_inputDvarInactiveValueColor, 0);
          *(float *)&dword_F00254 =
              (float)(*(float *)&dword_F00254 + *(float *)&dword_F0025C) +
              *(float *)&dword_F0025C;
          dword_F00250 = dword_F00258;
          v8.integer.max = (int32_t)&v11;
          v8.integer.min = 1024;
          Dvar_DomainToString_GetLines(Var->type, Var->domain, v10, v8);
          ConDraw_Box(
              *(float **)(con_inputHintBoxColor + 8),
              *(float *)&dword_F00250 - 6.0, *(float *)&dword_F00254 - 6.0,
              (float)(flt_EFB228 - flt_EFB220) -
                  (float)((float)(*(float *)&dword_F00250 - 6.0) - flt_EFB220),
              (float)((float)(v11 + 1) * *(float *)&dword_F0025C) + 12.0);
          dword_121C7BC(v10, 0x7FFFFFFF, dword_14C13C0, dword_F00250,
                        *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                        1065353216, 1065353216, &con_inputDvarInfoColor, 0);
          *(float *)&dword_F00254 =
              *(float *)&dword_F00254 + *(float *)&dword_F0025C;
          dword_F00250 = dword_F00258;
          result = (int)Var;
            if (Var->type == 6) {
              result = Cmd_Argc();
              if (result == 2)
                return ConDrawInput_AutoCompleteArg(
                    (char **)Var->domain.integer.max, Var->domain.integer.min);
            }
        }
    }
  return result;
}

int __cdecl CL_ConsolePrint_AddLine(enum print_msg_type_t, char const *, int,
                                    int, int)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawMessageWindow(struct MessageWindow *, int, int, int, int,
                                   int, float, float, enum msgwnd_mode_t)
{
  UNIMPLEMENTED();
}

void __cdecl Con_DrawInput(void)
{
  int result;        // eax
  char *v1;          // edi
  int v2;            // xmm1_4
  const char *v3;    // ebx
  int v4;            // edx
  unsigned int v5;   // kr04_4
  int v6;            // esi
  float v7;          // xmm5_4
  field_t *i;        // ebx
  int v10;           // eax
  char *v11;         // ebx
  signed __int8 v12; // al
  uint8_t *buffer;   // ebx
  float v15;         // [esp+3Ch] [ebp-1Ch]

  result = (int)cl;
    if ((*((_BYTE *)cl + 4) & 1) != 0) {
      result = Sys_IsMainThread();
        if ((_BYTE)result) {
          v1 = va("%s: %s> ", "CoD2 MP", "1.0");
          *(float *)&dword_F0025C = (float)dword_121C7B8(dword_14C13C0);
          *(float *)&dword_F00250 = flt_EFB220 + 6.0;
          *(float *)&dword_F00254 = flt_EFB224 + 6.0;
          *(float *)&dword_F00258 = flt_EFB220 + 6.0;
          ConDraw_Box(*(float **)(con_inputBoxColor + 8),
                      (float)(flt_EFB220 + 6.0) - 6.0,
                      (float)(flt_EFB224 + 6.0) - 6.0,
                      (float)(flt_EFB228 - flt_EFB220) -
                          (float)((float)((float)(flt_EFB220 + 6.0) - 6.0) -
                                  flt_EFB220),
                      *(float *)&dword_F0025C + 12.0);
          dword_121C7BC(v1, 0x7FFFFFFF, dword_14C13C0, dword_F00250,
                        *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                        1065353216, 1065353216, &con_versionColor, 0);
          v15 = *(float *)&dword_F00250;
          *(float *)&v2 = (float)dword_121C7B4(v1, 0, dword_14C13C0) + v15;
          dword_F00250 = v2;
          dword_F00258 = v2;
          g_consoleField.widthInPixels =
              (int)(float)((float)(flt_EFB228 - 6.0) - *(float *)&v2);
          Field_Draw(&g_consoleField, (int)*(float *)&v2,
                     (int)*(float *)&dword_F00254, 5, 5);
          *(float *)&dword_F00254 =
              *(float *)&dword_F00254 + *(float *)&dword_F0025C;
          dword_F00250 = dword_F00258;
          Cmd_TokenizeString((char *)g_consoleField.buffer);
          v3 = (const char *)Cmd_Argv(0);
          if (*v3 != 92 && *v3 != 47)
            goto LABEL_7;
            do {
              ++v3;
            LABEL_7:
              v4 = *v3;
              if ((v4 & 0xFFFFFF80) != 0)
                result = __maskrune(v4, 0x4000) != 0;
              else
                result = (_DefaultRuneLocale.__runetype[v4] >> 14) & 1;
            }
          while (result);
          LODWORD(flt_F00244) = v3;
          v5 = strlen(v3) + 1;
          LODWORD(flt_F00248) = v5 - 1;
            if (v5 != 1) {
              byte_F0024C = 0;
              conDrawInputGlob = 0.0;
              Dvar_ForEach(
                  (void (*)(const char *))ConDrawInput_IncrMatchCounter);
              result = Cmd_ForEach(
                  (void (*)(const char *))ConDrawInput_IncrMatchCounter);
              v6 = LODWORD(conDrawInputGlob);
                if (LODWORD(conDrawInputGlob)) {
                  v7 = *(float *)&dword_F00254 + *(float *)&dword_F0025C;
                  *(float *)&dword_F00254 =
                      *(float *)&dword_F00254 + *(float *)&dword_F0025C;
                  dword_F00250 = dword_F00258;
                    if (SLODWORD(conDrawInputGlob) > 24) {
                      v11 =
                          va("%i matches (too many to show)", conDrawInputGlob);
                      ConDraw_Box(
                          *(float **)(con_inputHintBoxColor + 8),
                          *(float *)&dword_F00250 - 6.0,
                          *(float *)&dword_F00254 - 6.0,
                          (float)(flt_EFB228 - flt_EFB220) -
                              (float)((float)(*(float *)&dword_F00250 - 6.0) -
                                      flt_EFB220),
                          *(float *)&dword_F0025C + 12.0);
                      return dword_121C7BC(
                          v11, 0x7FFFFFFF, dword_14C13C0, dword_F00250,
                          *(float *)&dword_F00254 + *(float *)&dword_F0025C,
                          1065353216, 1065353216, &con_inputDvarMatchColor, 0);
                    }
                  if (LODWORD(conDrawInputGlob) == 1)
                    goto LABEL_32;
                    if (byte_F0024C) {
                        for (i = &g_consoleField;;
                             i = (field_t *)((char *)i + 1)) {
                          v10 = (char)i->buffer[0];
                          if (!((v10 & 0xFFFFFF80) != 0
                                    ? __maskrune(v10, 0x4000) != 0
                                    : (_DefaultRuneLocale.__runetype[v10] >>
                                       14) &
                                          1))
                            break;
                        }
                      v12 = i->buffer[0];
                        if (v12) {
                          buffer = i->buffer;
                            while (
                                !((v12 & 0xFFFFFF80) != 0
                                      ? __maskrune(v12, 0x4000) != 0
                                      : (_DefaultRuneLocale.__runetype[v12] >>
                                         14) &
                                            1)) {
                              v12 = *++buffer;
                              if (!v12)
                                goto LABEL_23;
                            }
                        LABEL_32:
                          Dvar_ForEach((void (*)(
                              const char *))ConDrawInput_DetailedDvarMatch);
                          return Cmd_ForEach((void (*)(
                              const char *))ConDrawInput_DetailedCmdMatch);
                        }
                    LABEL_23:
                      v7 = *(float *)&dword_F00254;
                    }
                  ConDraw_Box(
                      *(float **)(con_inputHintBoxColor + 8),
                      *(float *)&dword_F00250 - 6.0, v7 - 6.0,
                      (float)(flt_EFB228 - flt_EFB220) -
                          (float)((float)(*(float *)&dword_F00250 - 6.0) -
                                  flt_EFB220),
                      (float)((float)v6 * *(float *)&dword_F0025C) + 12.0);
                  Dvar_ForEach((void (*)(const char *))ConDrawInput_DvarMatch);
                  return Cmd_ForEach(
                      (void (*)(const char *))ConDrawInput_CmdMatch);
                }
            }
        }
    }
  return result;
}

void __cdecl Con_OneTimeInit(void)
{
  int v0; // eax

  con_inputBoxColor =
      (int)Dvar_RegisterVec4("con_inputBoxColor", (DvarValue)1048576000, 0.25,
                             0.2, 1.0, 0.0, 1.0, 0x1001u);
  con_inputHintBoxColor =
      (int)Dvar_RegisterVec4("con_inputHintBoxColor", (DvarValue)1053609165,
                             0.40000001, 0.34999999, 1.0, 0.0, 1.0, 0x1001u);
  con_outputBarColor =
      (int)Dvar_RegisterVec4("con_outputBarColor", (DvarValue)1065353216, 1.0,
                             0.94999999, 0.60000002, 0.0, 1.0, 0x1001u);
  con_outputSliderColor =
      (int)Dvar_RegisterVec4("con_outputSliderColor", (DvarValue)1041865114,
                             0.15000001, 0.1, 0.60000002, 0.0, 1.0, 0x1001u);
  con_outputWindowColor =
      (int)Dvar_RegisterVec4("con_outputWindowColor", (DvarValue)1051931443,
                             0.34999999, 0.30000001, 0.75, 0.0, 1.0, 0x1001u);
  con_gamemessagetime = (int)Dvar_RegisterFloat(
      "con_gamemessagetime", (DvarValue)1084227584, 0.0, 3.4028235e38, 0x1000u);
  con_boldgamemessagetime =
      (int)Dvar_RegisterFloat("con_boldgamemessagetime", (DvarValue)1090519040,
                              0.0, 3.4028235e38, 0x1000u);
  con_minicontime = (int)Dvar_RegisterFloat(
      "con_minicontime", (DvarValue)1082130432, 0.0, 3.4028235e38, 0x1001u);
  con_miniconlines =
      (int)Dvar_RegisterInt("con_miniconlines", 5, 0, 100, 0x1001u);
  dword_EFB234 = (int)&unk_EFB250;
  dword_EFB238 = 0;
  dword_EFB23C = 8;
  dword_EFB240 = 3;
  dword_EFB244 = 250;
  dword_EFB248 = 250;
  dword_EFB24C = 500;
  dword_EFB770 = (int)&unk_EFB78C;
  dword_EFB774 = 0;
  dword_EFB778 = 8;
  dword_EFB77C = 3;
  dword_EFB780 = 250;
  dword_EFB784 = 250;
  dword_EFB788 = 500;
  dword_EFBCAC = (int)&unk_EFBCC8;
  dword_EFBCB0 = 0;
  dword_EFBCB4 = 8;
  dword_EFBCB8 = 3;
  dword_EFBCBC = 250;
  dword_EFBCC0 = 250;
  dword_EFBCC4 = 500;
  v0 = *(_DWORD *)(con_miniconlines + 8);
  dword_EFC1E8 = (int)&unk_EFC204;
  dword_EFC1EC = 0;
  dword_EFC1F0 = v0;
  dword_EFC1F4 = 0;
  dword_EFC1F8 = 0;
  dword_EFC1FC = 0;
  dword_EFC200 = 0;
  dword_EFB230 = (int)&dword_EFB234;
  dword_F00214 = LODWORD(colorWhite[0]);
  dword_F00218 = LODWORD(colorWhite[1]);
  dword_F0021C = LODWORD(colorWhite[2]);
  dword_F00220 = LODWORD(colorWhite[3]);
  dword_EFB214 = -1;
  Con_CheckResize();
  con = 1;
}

void __cdecl Con_Dump_f(void)
{
  const char *v0; // eax
  char *v1;       // eax
  int v2;         // edi
  int v3;         // esi
  int v4;         // ecx
  int v5;         // eax
  __int16 *v6;    // edx
  int v7;         // edi
  __int16 *v8;    // edi
  int i;          // edx
  char *v10;      // eax
  int v11;        // ebx
  char *v12;      // edx
  int v13;        // eax
  int v14;        // [esp+2Ch] [ebp-41Ch] BYREF
  char v15[1048]; // [esp+30h] [ebp-418h] BYREF

    if (Cmd_Argc() == 2) {
      v0 = (const char *)Cmd_Argv(1);
      Com_Printf("Dumped console text to %s.\n", v0);
      v1 = (char *)Cmd_Argv(1);
      v14 = FS_FOpenFileWrite(v1);
        if (v14) {
          v2 = dword_EFB204;
          v3 = dword_EFB204 - dword_EFB218 + 1;
            if (dword_EFB204 < v3) {
              v4 = dword_EFB214;
            }
            else {
              v4 = dword_EFB214;
                do {
                  v5 = 2 * dword_EFB214 * (v3 % dword_EFB218);
                  v6 = (__int16 *)&word_EDB204[v5];
                    if (dword_EFB214 <= 0) {
                      if (dword_EFB214)
                        break;
                    }
                    else {
                      if (word_EDB204[v5] != 32)
                        break;
                      v13 = 0;
                        while (dword_EFB214 != ++v13) {
                          if (LOBYTE(v6[v13]) != 32)
                            goto LABEL_8;
                        }
                    }
                  ++v3;
                }
              while (dword_EFB204 >= v3);
            }
        LABEL_8:
          v15[v4] = 0;
            if (v2 >= v3) {
                while (1) {
                  v8 = (__int16 *)&word_EDB204[2 * v4 * (v3 % dword_EFB218)];
                    if (v4 > 0) {
                      for (i = 0; i != v4; ++i)
                        v15[i] = v8[i];
                    }
                  v7 = v4 - 1;
                    if (v4 - 1 >= 0 && v15[v7] == 32) {
                      v10 = &v15[v7];
                      v11 = 0;
                        do {
                          v12 = v10;
                          *v10 = 0;
                          if (v11 == v7)
                            break;
                          ++v11;
                          --v10;
                        }
                      while (v12[(char *)&v14 + 2 - ((char *)&v14 + 3)] == 32);
                    }
                  I_strncat(v15, 1024, "\n");
                  FS_Write(v15, strlen(v15), v14);
                  if (++v3 > dword_EFB204)
                    break;
                  v4 = dword_EFB214;
                }
            }
          FS_FCloseFile(v14);
        }
        else {
          Com_Printf("ERROR: couldn't open.\n");
        }
    }
    else {
      Com_Printf("usage: condump <filename>\n");
    }
}
