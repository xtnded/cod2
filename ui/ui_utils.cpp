struct rectDef_s const *__cdecl Window_GetRectClient(
    struct windowDef_t const *) {
  UNIMPLEMENTED();
}

int __cdecl Window_GetDynamicFlags(struct windowDef_t const *) {
  UNIMPLEMENTED();
}

int __cdecl Window_GetStaticFlags(struct windowDef_t const *) {
  UNIMPLEMENTED();
}

int __cdecl Menu_GetCursorItem(struct menuDef_t *) { UNIMPLEMENTED(); }

struct rectDef_s const *__cdecl Item_GetTextRect(struct itemDef_s const *) {
  UNIMPLEMENTED();
}

int __cdecl Item_GetCursorPos(struct itemDef_s const *) { UNIMPLEMENTED(); }

int __cdecl ListBox_GetCursorPos(struct listBoxDef_s const *) {
  UNIMPLEMENTED();
}

int __cdecl ListBox_GetStartPos(struct listBoxDef_s const *) {
  UNIMPLEMENTED();
}

int __cdecl ListBox_GetEndPos(struct listBoxDef_s const *) { UNIMPLEMENTED(); }

bool __cdecl Window_IsVisible(struct windowDef_t const *) { UNIMPLEMENTED(); }

void __cdecl String_Init() { UNIMPLEMENTED(); }

struct multiDef_s *__cdecl Item_GetMultiDef(struct itemDef_s *item) {
  return a1->typeData;
}

struct listBoxDef_s *__cdecl Item_GetListBoxDef(struct itemDef_s *item) {
  if (a1->dataType == 6) {
    return a1->typeData;
  } else {
    Com_Printf("^1Menu Error: Expecting type: ITEM_TYPE_LISTBOX\n");
    return 0;
  }
}

int __cdecl Item_IsEditFieldDef(struct itemDef_s *item) {
  return a1->dataType <= 0x12u && ((1 << a1->dataType) & 0x74E11) != 0;
}

void __cdecl Window_SetStaticFlags(struct windowDef_t *w, int flags) {
  windowDef_t *result; // eax

  result = a1;
  a1->staticFlags = a2;
  return result;
}

struct editFieldDef_s *__cdecl Item_GetEditFieldDef(struct itemDef_s *item) {
  if (a1->dataType <= 0x12u && ((1 << a1->dataType) & 0x74E11) != 0) {
    return a1->typeData;
  } else {
    Com_Printf("^1Menu Error: Expecting type: ITEM_TYPE_EDITFIELD, "
               "ITEM_TYPE_NUMERICFIELD, ITEM_TYPE_DECIMALFIELD, ITEM_T"
               "YPE_VALIDFILEFIELD, ITEM_TYPE_UPREDITFIELD, ITEM_TYPE_YESNO, "
               "ITEM_TYPE_BIND, ITEM_TYPE_SLIDER, or ITEM_TYPE_TEXT\n");
    return 0;
  }
}

void __cdecl ListBox_SetEndPos(struct listBoxDef_s *listBox, int endPos) {
  listBoxDef_s *result; // eax

  result = a1;
  *(_DWORD *)a1->endPos = a2;
  return result;
}

void __cdecl ListBox_SetStartPos(struct listBoxDef_s *listBox, int startPos) {
  listBoxDef_s *result; // eax

  result = a1;
  *(_DWORD *)a1->startPos = a2;
  return result;
}

void __cdecl ListBox_SetCursorPos(struct listBoxDef_s *listBox, int cursorPos) {
  listBoxDef_s *result; // eax

  result = a1;
  *(_DWORD *)a1->cursorPos = a2;
  return result;
}

void __cdecl Item_SetCursorPos(struct itemDef_s *item, int cursorPos) {
  itemDef_s *result; // eax

  result = a1;
  *(_DWORD *)a1->cursorPos = a2;
  return result;
}

void __cdecl Item_SetTextRect(struct itemDef_s *item,
                              struct rectDef_s const *textRect) {
  int32_t result; // eax

  *(_DWORD *)a1->textRect = a2->x;
  *(_DWORD *)&a1->textRect[4] = a2->y;
  *(_DWORD *)&a1->textRect[8] = a2->w;
  *(_DWORD *)&a1->textRect[12] = a2->h;
  *(_DWORD *)&a1->textRect[16] = a2->horzAlign;
  result = a2->vertAlign;
  *(_DWORD *)&a1->textRect[20] = result;
  return result;
}

void __cdecl Menu_SetCursorItem(struct menuDef_t *menu, int cursorItem) {
  menuDef_t *result; // eax

  result = a1;
  *(_DWORD *)a1->cursorItem = a2;
  return result;
}

void __cdecl Window_SetDynamicFlags(struct windowDef_t *w, int flags) {
  windowDef_t *result; // eax

  result = a1;
  *(_DWORD *)a1->dynamicFlags = a2;
  return result;
}

void __cdecl Window_SetRectEffects1(struct windowDef_t *w,
                                    struct rectDef_s const *rectEffects1) {
  int32_t result; // eax

  *(_QWORD *)&a1->rectEffects1[0][0] = *(_QWORD *)&a2->x;
  LODWORD(a1->rectEffects1[0][2]) = a2->w;
  *(_QWORD *)&a1->rectEffects1[1][0] = *(_QWORD *)&a2->h;
  result = a2->vertAlign;
  LODWORD(a1->rectEffects1[1][2]) = result;
  return result;
}

void __cdecl Window_SetRectEffects0(struct windowDef_t *w,
                                    struct rectDef_s const *rectEffects0) {
  int32_t result; // eax

  *(_QWORD *)&a1->rectEffects0[0][0] = *(_QWORD *)&a2->x;
  LODWORD(a1->rectEffects0[0][2]) = a2->w;
  *(_QWORD *)&a1->rectEffects0[1][0] = *(_QWORD *)&a2->h;
  result = a2->vertAlign;
  LODWORD(a1->rectEffects0[1][2]) = result;
  return result;
}

void __cdecl Window_SetRectClient(struct windowDef_t *w,
                                  struct rectDef_s const *rectClient) {
  int32_t result; // eax

  *(_DWORD *)a1->rectClient = a2->x;
  *(_DWORD *)&a1->rectClient[4] = a2->y;
  *(_DWORD *)&a1->rectClient[8] = a2->w;
  *(_DWORD *)&a1->rectClient[12] = a2->h;
  *(_DWORD *)&a1->rectClient[16] = a2->horzAlign;
  result = a2->vertAlign;
  *(_DWORD *)&a1->rectClient[20] = result;
  return result;
}

void __cdecl Window_SetRect(struct windowDef_t *w,
                            struct rectDef_s const *rect) {
  int32_t result; // eax

  *(_DWORD *)a1->rect = a2->x;
  *(_DWORD *)&a1->rect[4] = a2->y;
  *(_DWORD *)&a1->rect[8] = a2->w;
  *(_DWORD *)&a1->rect[12] = a2->h;
  *(_DWORD *)&a1->rect[16] = a2->horzAlign;
  result = a2->vertAlign;
  *(_DWORD *)&a1->rect[20] = result;
  return result;
}

void __cdecl Window_SetOffsetTime(struct windowDef_t *w, int offsetTime) {
  windowDef_t *result; // eax

  result = a1;
  *(_DWORD *)a1->offsetTime = a2;
  return result;
}

void __cdecl Item_SetScreenCoords(struct itemDef_s *item, float x, float y,
                                  int horzAlign, int vertAlign) {
  float v5;   // xmm1_4
  float v6;   // xmm2_4
  int v7;     // edi
  int v8;     // esi
  int result; // eax
  float v10;  // xmm0_4
  float v11;  // [esp+Ch] [ebp-24h]
  int v12;    // [esp+10h] [ebp-20h]
  int v13;    // [esp+14h] [ebp-1Ch]
  int v14;    // [esp+18h] [ebp-18h]
  int v15;    // [esp+1Ch] [ebp-14h]

  v5 = a2;
  v6 = a3;
  if (a1) {
    if (*(_DWORD *)&a1->window[212]) {
      v10 = *(float *)&a1->window[224];
      v5 = a2 + v10;
      v6 = a3 + v10;
    }
    v11 = v6 + *(float *)&a1->window[100];
    v12 = *(_DWORD *)&a1->window[104];
    v13 = *(_DWORD *)&a1->window[108];
    if (*(_DWORD *)&a1->window[112] || *(_DWORD *)&a1->window[116]) {
      v14 = *(_DWORD *)&a1->window[112];
      v15 = *(_DWORD *)&a1->window[116];
    } else {
      v14 = a4;
      v15 = a5;
    }
    *(float *)a1->window = v5 + *(float *)&a1->window[96];
    *(float *)&a1->window[4] = v11;
    *(_DWORD *)&a1->window[8] = v12;
    *(_DWORD *)&a1->window[12] = v13;
    *(_DWORD *)&a1->window[16] = v14;
    *(_DWORD *)&a1->window[20] = v15;
    v7 = *(_DWORD *)&a1->textRect[16];
    v8 = *(_DWORD *)&a1->textRect[20];
    *(_DWORD *)&a1->textRect[4] = *(_DWORD *)&a1->textRect[4];
    *(_DWORD *)&a1->textRect[8] = 0;
    result = 0;
    *(_DWORD *)&a1->textRect[12] = 0;
    *(_DWORD *)&a1->textRect[16] = v7;
    *(_DWORD *)&a1->textRect[20] = v8;
  }
  return result;
}

bool __cdecl ListBox_HasValidCursorPos(struct listBoxDef_s const *listBox) {
  int v1; // edx

  v1 = *(_DWORD *)a1->cursorPos;
  return v1 < *(_DWORD *)a1->endPos && v1 >= *(_DWORD *)a1->startPos;
}

int __cdecl Item_GetCursorPosOffset(struct itemDef_s const *item,
                                    char const *text, int delta) {
  int v3;         // ebx
  int result;     // eax
  const char *v5; // edx
  char v6;        // cl
  char v7;        // dl
  const char *v8; // edx

  v3 = a3;
  result = *(_DWORD *)a1->cursorPos;
  if (a3 > 0) {
    while (1) {
      while (1) {
        v5 = &a2[result];
        if (!&a2[result])
          break;
        if (*v5 != 94)
          break;
        v6 = v5[1];
        if (!v6 || v6 == 94 || v6 <= 47 || v6 > 57)
          break;
        result += 2;
      }
      if (!*v5 || !v3)
        break;
      ++result;
      --v3;
    }
  } else {
  LABEL_18:
    if (result) {
      while (v3) {
        if (result > 1) {
          v8 = &a2[result];
          if (&a2[result] != (const char *)2 && *(v8 - 2) == 94) {
            v7 = *(v8 - 1);
            if (v7) {
              if (v7 != 94 && v7 > 47 && v7 <= 57) {
                result -= 2;
                goto LABEL_18;
              }
            }
          }
        }
        --result;
        ++v3;
        if (!result)
          return result;
      }
    }
  }
  return result;
}

void __cdecl Window_RemoveDynamicFlags(struct windowDef_t *w, int newFlags) {
  int v2;     // eax
  int result; // eax

  v2 = a2;
  if ((a2 & 4) != 0)
    v2 = a2 | 2;
  result = ~v2;
  *(_DWORD *)a1->dynamicFlags &= result;
  return result;
}

void __cdecl Window_AddDynamicFlags(struct windowDef_t *w, int newFlags) {
  int result; // eax

  result = a2;
  *(_DWORD *)a1->dynamicFlags |= a2;
  return result;
}

void __cdecl Menu_UpdatePosition(struct menuDef_t *menu) {
  int result;    // eax
  float v2;      // xmm0_4
  signed int v3; // esi
  float v4;      // [esp+28h] [ebp-10h]
  float v5;      // [esp+2Ch] [ebp-Ch]

  if (a1) {
    v4 = *(float *)a1->window.rect;
    v5 = *(float *)&a1->window.rect[4];
    if (a1->window.border) {
      v2 = *(float *)&a1->window.borderSize;
      v4 = *(float *)a1->window.rect + v2;
      v5 = v2 + v5;
      result = a1->itemCount;
      if (result <= 0)
        return result;
    } else {
      result = a1->itemCount;
      if (result <= 0)
        return result;
    }
    v3 = 0;
    do
      result = Item_SetScreenCoords(*(itemDef_s **)(a1->items + 4 * v3++), v4,
                                    v5, *(_DWORD *)&a1->window.rect[16],
                                    *(_DWORD *)&a1->window.rect[20]);
    while (v3 < (signed int)a1->itemCount);
  }
  return result;
}

int __cdecl Float_Parse(char const **p, float *f) {
  char *v2; // eax
  float v4; // xmm0_4

  v2 = Com_ParseOnLine(a1);
  if (!v2 || !*v2)
    return 0;
  v4 = atof(v2);
  *a2 = v4;
  return 1;
}

int __cdecl Int_Parse(char const **p, int *i) {
  char *v2; // eax

  v2 = Com_ParseOnLine(a1);
  if (!v2 || !*v2)
    return 0;
  *a2 = atoi(v2);
  return 1;
}

int __cdecl Rect_Parse(char const **p, struct rectDef_s *r) {
  char *v2;    // eax
  int32_t v4;  // xmm0_4
  char *v5;    // eax
  int32_t v6;  // xmm0_4
  char *v7;    // eax
  int32_t v8;  // xmm0_4
  char *v9;    // eax
  int32_t v10; // xmm0_4

  v2 = Com_ParseOnLine(a1);
  if (!v2)
    return 0;
  if (!*v2)
    return 0;
  *(float *)&v4 = atof(v2);
  a2->x = v4;
  v5 = Com_ParseOnLine(a1);
  if (!v5)
    return 0;
  if (!*v5)
    return 0;
  *(float *)&v6 = atof(v5);
  a2->y = v6;
  v7 = Com_ParseOnLine(a1);
  if (!v7)
    return 0;
  if (!*v7)
    return 0;
  *(float *)&v8 = atof(v7);
  a2->w = v8;
  v9 = Com_ParseOnLine(a1);
  if (!v9 || !*v9)
    return 0;
  *(float *)&v10 = atof(v9);
  a2->h = v10;
  return 1;
}

int __cdecl Item_EnableShowViaDvar(struct itemDef_s const *, int) {
  _BYTE *enableDvar;   // eax
  _BYTE *dvarTest;     // eax
  char *VariantString; // edi
  char __dst[1024];    // [esp+1Ch] [ebp-81Ch] BYREF
  char __b[1024];      // [esp+41Ch] [ebp-41Ch] BYREF
  char *v8[7];         // [esp+81Ch] [ebp-1Ch] BYREF

  memset(__b, 0, sizeof(__b));
  if (!a1)
    return 1;
  enableDvar = (_BYTE *)a1->enableDvar;
  if (!enableDvar)
    return 1;
  if (!*enableDvar)
    return 1;
  dvarTest = (_BYTE *)a1->dvarTest;
  if (!dvarTest || !*dvarTest)
    return 1;
  VariantString = (char *)Dvar_GetVariantString((char *)a1->dvarTest);
  I_strncat(__b, 1024, (char *)a1->enableDvar);
  v8[0] = __b;
  while (String_Parse(v8, __dst, 1024)) {
    while (__dst[0] == 59 && !__dst[1]) {
      if (!String_Parse(v8, __dst, 1024))
        return (a2 & a1->dvarFlags) == 0;
    }
    if ((a2 & a1->dvarFlags) != 0) {
      if (!I_stricmp(VariantString, __dst))
        return 1;
    } else if (!I_stricmp(VariantString, __dst)) {
      return 0;
    }
  }
  return (a2 & a1->dvarFlags) == 0;
}

int __cdecl Item_CanHaveFocus(struct itemDef_s *) { UNIMPLEMENTED(); }

bool __cdecl Menu_IsNextCursorItemRight(struct menuDef_t *) { UNIMPLEMENTED(); }

bool __cdecl Menu_IsPrevCursorItemLeft(struct menuDef_t *) { UNIMPLEMENTED(); }

void *__cdecl UI_Alloc(int size, int alignment) {
  return Hunk_AllocAlignInternal(__len, a2);
}

char const *__cdecl String_Alloc(char const *p) {
  char v1;        // al
  __int16 v2;     // bx
  int v3;         // edi
  _DWORD *i;      // edi
  const char *v5; // ebx
  char *v6;       // edi
  _DWORD **v7;    // ebx
  _DWORD *v8;     // eax
  _DWORD *v9;     // eax
  int v11;        // [esp+1Ch] [ebp-1Ch]

  if (!__s1)
    return 0;
  v1 = *__s1;
  if (!*__s1)
    return String_Alloc(char const *)::staticNULL;
  v2 = 0;
  v3 = 119;
  do {
    v2 += v3 * __tolower(v1);
    v1 = __s1[v3++ - 118];
  } while (v1);
  v11 = v2 & 0x7FF;
  for (i = (_DWORD *)g_strHandle[v11]; i; i = (_DWORD *)*i) {
    v5 = (const char *)i[1];
    if (!strcmp(__s1, v5))
      return (gentity_s *)v5;
  }
  v6 = (char *)Hunk_AllocAlignInternal(strlen(__s1) + 1, 1);
  strcpy(v6, __s1);
  v7 = (_DWORD **)g_strHandle[v11];
  if (v7) {
    v8 = *v7;
    if (*v7) {
      while (*v8) {
        v7 = (_DWORD **)v8;
        v8 = (_DWORD *)*v8;
      }
    }
  }
  v9 = (_DWORD *)Hunk_AllocAlignInternal(8u, 4);
  *v9 = 0;
  v9[1] = v6;
  if (v7)
    *v7 = v9;
  else
    g_strHandle[v11] = (int)v9;
  return (gentity_s *)v6;
}

long __cdecl hashForString(char const *) { UNIMPLEMENTED(); }
