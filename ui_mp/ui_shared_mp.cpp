int __cdecl Window_GetOffsetTime(struct windowDef_t const *)
{
  UNIMPLEMENTED();
}

struct rectDef_s const *__cdecl Window_GetRectEffects0(
    struct windowDef_t const *)
{
  UNIMPLEMENTED();
}

struct rectDef_s const *__cdecl Window_GetRectEffects1(
    struct windowDef_t const *)
{
  UNIMPLEMENTED();
}

bool __cdecl Window_IsHorizontal(struct windowDef_t const *)
{
  UNIMPLEMENTED();
}

bool __cdecl Window_HasFocus(struct windowDef_t const *)
{
  UNIMPLEMENTED();
}

int __cdecl Menu_Count(struct displayContextDef_s *dc)
{
  return a1->menuCount;
}

int __cdecl Display_KeyBindPending()
{
  return g_waitingForKey;
}

void __cdecl Controls_SetDefaults()
{
  char *v0;   // edx
  int result; // eax

  v0 = (char *)&g_bindings;
    do {
      *((_DWORD *)v0 + 3) = *((_DWORD *)v0 + 1);
      result = *((_DWORD *)v0 + 2);
      *((_DWORD *)v0 + 4) = result;
      v0 += 20;
    }
  while (v0 != &updateScreenCalled);
  return result;
}

void __cdecl Item_Action(struct displayContextDef_s *, struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Item_StopCapture(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

int __cdecl IsVisible(int)
{
  UNIMPLEMENTED();
}

void __cdecl Fade(int *, float *, float, int *, int, int, float, float,
                  struct displayContextDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl GradientBar_Paint(struct rectDef_s *, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl LerpColor(float *const a, float *const b, float *const c, float t)
{
  int i;         // edx
  float v5;      // xmm1_4
  float *result; // eax

    for (i = 1; i != 5; ++i) {
      v5 = (float)((float)(a2[i - 1] - a1[i - 1]) * a4) + a1[i - 1];
      result = &a3[i];
      *(result - 1) = v5;
        if (v5 < 0.0) {
          *(result - 1) = 0.0;
        }
        else if (v5 > 1.0) {
          *(result - 1) = 1.0;
        }
    }
  return result;
}

int __cdecl Item_OwnerDraw_HandleKey(struct itemDef_s *, int)
{
  UNIMPLEMENTED();
}

int __cdecl GetCommandHasBinding(char const *command)
{
  int v1;    // esi
  char **v2; // ebx
  int *v3;   // edi

  v1 = 0;
  v2 = (char **)&g_bindings;
  v3 = dword_3121AC;
    while (I_stricmp(a1, *v2)) {
      ++v1;
      v3 += 5;
      v2 += 5;
      if (v1 == 56)
        return 0;
    }
  return *v3 != -1;
}

int __cdecl BindingIDFromName(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl ToWindowCoords(float *, float *, struct windowDef_t *)
{
  UNIMPLEMENTED();
}

int __cdecl Display_VisibleMenuCount(struct displayContextDef_s *)
{
  UNIMPLEMENTED();
}

float __cdecl Item_Slider_ThumbPosition(struct itemDef_s *item)
{
  itemDefData_t v1; // esi
  float v2;         // xmm1_4
  float v3;         // xmm3_4
  float v4;         // xmm1_4
  float v5;         // xmm0_4
  float Float;      // [esp+1Ch] [ebp-1Ch]

  v1.listBox = Item_GetEditFieldDef(a1).listBox;
  v2 = 0.0;
    if (v1.listBox) {
      if (*(_DWORD *)a1->text)
        v3 = (float)(*(float *)a1->textRect + *(float *)&a1->textRect[8]) + 8.0;
      else
        v3 = *(float *)a1->window;
      Float = Dvar_GetFloat((char *)a1->dvar);
        if (*(float *)v1.listBox <= Float) {
          v5 = *(float *)(v1.listBox + 4);
          v4 = fminf(v5, Float);
        }
        else {
          v4 = *(float *)v1.listBox;
          v5 = *(float *)(v1.listBox + 4);
        }
      return (
          float)((float)((float)((float)((float)((float)(v4 -
                                                         *(float *)v1.listBox) /
                                                 (float)(v5 - *(float *)v1
                                                                   .listBox)) *
                                         84.0) +
                                 5.0) +
                         1.0) +
                 v3);
    }
  return v2;
}

void __cdecl Script_ShowGamerCard(struct displayContextDef_s *,
                                  struct itemDef_s *, char const **)
{
  UNIMPLEMENTED();
}

struct menuDef_t *__cdecl Menus_FindByName(struct displayContextDef_s *dc,
                                           char const *p)
{
  displayContextDef_s *v3; // ebx
  signed int v4;           // esi

  if ((int)a1->menuCount <= 0)
    return 0;
  v3 = a1;
  v4 = 0;
    while (I_stricmp(*(char **)(*(_DWORD *)v3->Menus + 192), a2)) {
      ++v4;
      v3 = (displayContextDef_s *)((char *)v3 + 4);
      if (v4 >= (signed int)a1->menuCount)
        return 0;
    }
  return *(_DWORD *)&a1->Menus[4 * v4];
}

struct itemDef_s *__cdecl Menu_FindItemByName(struct menuDef_t *, char const *)
{
  UNIMPLEMENTED();
}

struct itemDef_s *__cdecl Menu_GetMatchingItemByNumber(struct menuDef_t *menu,
                                                       int index,
                                                       char const *name)
{
  char *v3;      // eax
  signed int v4; // edi
  int v5;        // ebx
  int32_t v6;    // edx
  char *v7;      // eax
  char *v8;      // eax
  int32_t items; // edx
  char *v11;     // eax
  char *v12;     // eax
  int v13;       // [esp+18h] [ebp-20h]
  int v14;       // [esp+1Ch] [ebp-1Ch]

  v3 = strchr(__s, 42);
  if (v3)
    v14 = v3 - __s;
  else
    v14 = -1;
  if ((int)a1->itemCount <= 0)
    return 0;
  v13 = 0;
  v4 = 0;
  v5 = 0;
    while (v14 == -1) {
      items = a1->items;
      v11 = *(char **)(*(_DWORD *)(items + v5) + 192);
      if (!v11)
        goto LABEL_20;
        if (I_stricmp(v11, __s)) {
          items = a1->items;
        LABEL_20:
          v12 = *(char **)(*(_DWORD *)(items + v5) + 196);
          if (!v12 || I_stricmp(v12, __s))
            goto LABEL_13;
          if (v13 == a2)
            return *(_DWORD *)(a1->items + v5);
          goto LABEL_12;
        }
      if (v13 == a2)
        return *(_DWORD *)(a1->items + v5);
    LABEL_12:
      ++v13;
    LABEL_13:
      ++v4;
      v5 += 4;
      if (v4 >= (signed int)a1->itemCount)
        return 0;
    }
  v6 = a1->items;
  v7 = *(char **)(*(_DWORD *)(v6 + v5) + 192);
    if (v7) {
      if (!I_strncmp(v7, __s, v14))
        goto LABEL_11;
      v6 = a1->items;
    }
  v8 = *(char **)(*(_DWORD *)(v5 + v6) + 196);
  if (!v8 || I_strncmp(v8, __s, v14))
    goto LABEL_13;
LABEL_11:
  if (v13 != a2)
    goto LABEL_12;
  return *(_DWORD *)(v5 + a1->items);
}

int __cdecl Menu_ItemsMatchingGroup(struct menuDef_t *menu, char const *name)
{
  char *v2;      // eax
  signed int v3; // esi
  int i;         // ebx
  int32_t v5;    // edx
  char *v6;      // eax
  char *v7;      // eax
  int32_t items; // edx
  char *v9;      // eax
  char *v11;     // eax
  int v12;       // [esp+18h] [ebp-20h]
  int v13;       // [esp+1Ch] [ebp-1Ch]

  v2 = strchr(__s, 42);
  if (v2)
    v13 = v2 - __s;
  else
    v13 = -1;
    if ((int)a1->itemCount > 0) {
      v3 = 0;
      v12 = 0;
        for (i = 0;; i += 4) {
            while (v13 == -1) {
              items = a1->items;
              v9 = *(char **)(*(_DWORD *)(items + i) + 192);
                if (v9) {
                  if (!I_stricmp(v9, __s))
                    goto LABEL_14;
                  items = a1->items;
                }
              v11 = *(char **)(*(_DWORD *)(items + i) + 196);
                if (v11 && !I_stricmp(v11, __s)) {
                  ++v12;
                  goto LABEL_15;
                }
            LABEL_10:
              ++v3;
              i += 4;
              if (v3 >= (signed int)a1->itemCount)
                return v12;
            }
          v5 = a1->items;
          v6 = *(char **)(*(_DWORD *)(i + v5) + 192);
          if (!v6)
            goto LABEL_8;
          if (I_strncmp(v6, __s, v13))
            break;
        LABEL_14:
          ++v12;
        LABEL_15:
          if (++v3 >= (signed int)a1->itemCount)
            return v12;
        }
      v5 = a1->items;
    LABEL_8:
      v7 = *(char **)(*(_DWORD *)(i + v5) + 196);
      if (v7 && !I_strncmp(v7, __s, v13))
        goto LABEL_14;
      goto LABEL_10;
    }
  return 0;
}

int __cdecl Menus_AnyFullScreenVisible(struct displayContextDef_s *dc)
{
  signed int v1; // ebx
  uint8_t *v2;   // edx
  int v3;        // ecx

  v1 = a1->openMenuCount - 1;
  if (v1 < 0)
    return 0;
  v2 = &a1->menuStack[4 * v1];
  v3 = 0;
    while ((*(_BYTE *)(*(_DWORD *)v2 + 232) & 4) == 0 ||
           !*(_DWORD *)(*(_DWORD *)v2 + 532)) {
      ++v3;
      v2 -= 4;
      if (a1->openMenuCount == v3)
        return 0;
    }
  return 1;
}

int __cdecl GetKeyBindings(char const * command, char  bindings)[128])
{
  UNIMPLEMENTED();
}

void __cdecl Controls_GetConfig()
{
  char **i;     // eax
  int v1;       // esi
  int j;        // ebx
  int result;   // eax
  char *v4;     // edx
  char *v5;     // [esp+18h] [ebp-130h]
  char *v6;     // [esp+1Ch] [ebp-12Ch]
  char v7[256]; // [esp+28h] [ebp-120h] BYREF
  int v8;       // [esp+128h] [ebp-20h]
  int v9;       // [esp+12Ch] [ebp-1Ch]

  v6 = (char *)&g_bindings;
    for (i = (char **)&g_bindings;; i = (char **)v4) {
      v5 = *i;
      v9 = -1;
      v8 = -1;
      v1 = 0;
        for (j = 0; j != 256; ++j) {
          Key_GetBindingBuf(j, v7, 256);
            if (v7[0]) {
                if (!I_stricmp(v7, v5)) {
                  *(&v8 + v1++) = j;
                  if (v1 == 2)
                    break;
                }
            }
        }
      *((_DWORD *)v6 + 3) = v8;
      result = v9;
      *((_DWORD *)v6 + 4) = v9;
      v4 = v6 + 20;
      v6 = v4;
      if (v4 == &updateScreenCalled)
        break;
    }
  return result;
}

void __cdecl Item_SetMouseOver(struct itemDef_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl Menu_FadeItemByName(struct menuDef_t *menu, char const *p,
                                 int fadeOut)
{
  windowDef_t *result; // eax
  windowDef_t *v4;     // edi
  int v5;              // esi
  windowDef_t *v6;     // ebx

  result = (windowDef_t *)Menu_ItemsMatchingGroup(a1, __s);
  v4 = result;
    if ((int)result > 0) {
      v5 = 0;
        do {
          result = (windowDef_t *)Menu_GetMatchingItemByNumber(a1, v5, __s);
          v6 = result;
            if (result) {
                if (a3) {
                  Window_AddDynamicFlags(result, 20);
                  result = (windowDef_t *)Window_RemoveDynamicFlags(v6, 32);
                }
                else {
                  Window_AddDynamicFlags(result, 36);
                  result = (windowDef_t *)Window_RemoveDynamicFlags(v6, 16);
                }
            }
          ++v5;
        }
      while (v4 != (windowDef_t *)v5);
    }
  return result;
}

void __cdecl Menu_ShowItemByName(struct menuDef_t *menu, char const *p,
                                 int bShow)
{
  windowDef_t *result; // eax
  windowDef_t *v4;     // edi
  int v5;              // esi
  windowDef_t *v6;     // ebx

  result = (windowDef_t *)Menu_ItemsMatchingGroup(a1, __s);
  v4 = result;
    if ((int)result > 0) {
      v5 = 0;
        do {
          result = (windowDef_t *)Menu_GetMatchingItemByNumber(a1, v5, __s);
          v6 = result;
            if (result) {
                if (a3) {
                  result = (windowDef_t *)Window_AddDynamicFlags(result, 4);
                }
                else {
                  Window_RemoveDynamicFlags(result, 4);
                  result = (windowDef_t *)v6->cinematic;
                    if ((int)result >= 0) {
                      result = (windowDef_t *)CIN_StopCinematic(v6->cinematic);
                      v6->cinematic = -1;
                    }
                }
            }
          ++v5;
        }
      while (v4 != (windowDef_t *)v5);
    }
  return result;
}

void __cdecl Item_UpdatePosition(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Menu_Setup(struct displayContextDef_s *dc)
{
  char **i;     // eax
  int v2;       // esi
  int j;        // ebx
  int result;   // eax
  char *v5;     // edx
  char *v6;     // [esp+18h] [ebp-130h]
  char *v7;     // [esp+1Ch] [ebp-12Ch]
  char v8[256]; // [esp+28h] [ebp-120h] BYREF
  int v9;       // [esp+128h] [ebp-20h]
  int v10;      // [esp+12Ch] [ebp-1Ch]

  a1->menuCount = 0;
  a1->openMenuCount = 0;
  Item_SetupKeywordHash();
  Menu_SetupKeywordHash();
  v7 = (char *)&g_bindings;
    for (i = (char **)&g_bindings;; i = (char **)v5) {
      v6 = *i;
      v10 = -1;
      v9 = -1;
      v2 = 0;
        for (j = 0; j != 256; ++j) {
          Key_GetBindingBuf(j, v8, 256);
            if (v8[0]) {
                if (!I_stricmp(v8, v6)) {
                  *(&v9 + v2++) = j;
                  if (v2 == 2)
                    break;
                }
            }
        }
      *((_DWORD *)v7 + 3) = v9;
      result = v10;
      *((_DWORD *)v7 + 4) = v10;
      v5 = v7 + 20;
      v7 = v5;
      if (v5 == &updateScreenCalled)
        break;
    }
  return result;
}

struct menuDef_t *__cdecl Menu_GetFocused(struct displayContextDef_s *dc)
{
  signed int v1; // esi
  uint8_t *v2;   // ecx
  int v3;        // ebx
  int result;    // eax
  int v5;        // edx

  v1 = a1->openMenuCount - 1;
  if (v1 < 0)
    return 0;
  v2 = &a1->menuStack[4 * v1];
  v3 = 0;
    while (1) {
      result = *(_DWORD *)v2;
      v5 = *(_DWORD *)(*(_DWORD *)v2 + 232);
      if ((v5 & 4) != 0 && (v5 & 2) != 0)
        break;
      ++v3;
      v2 -= 4;
      if (a1->openMenuCount == v3)
        return 0;
    }
  return result;
}

struct itemDef_s *__cdecl Menu_GetFocusedItem(struct menuDef_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Menu_OrbitItemByName(struct menuDef_t *menu, char const *p,
                                  float x, float y, float cx, float cy,
                                  int time)
{
  windowDef_t *result; // eax
  windowDef_t *v8;     // edi
  int v9;              // esi
  windowDef_t *v10;    // ebx
  int v11;             // edx
  float v12;           // xmm2_4
  float v13;           // xmm1_4
  float v14;           // xmm0_4
  rectDef_s v15;       // [esp+28h] [ebp-30h] BYREF

  result = (windowDef_t *)Menu_ItemsMatchingGroup(a1, __s);
  v8 = result;
    if ((int)result > 0) {
      v9 = 0;
        do {
          result = (windowDef_t *)Menu_GetMatchingItemByNumber(a1, v9, __s);
          v10 = result;
            if (result) {
              Window_AddDynamicFlags(result, 8196);
              Window_SetOffsetTime(v10, a7);
              v15 = *(rectDef_s *)&v10->rectEffects0[0][0];
              v15.x = a5;
              v15.y = a6;
              Window_SetRectEffects0(v10, &v15);
              v15 = *(rectDef_s *)v10->rectClient;
              v15.x = a3;
              v15.y = a4;
              result = (windowDef_t *)Window_SetRectClient(v10, &v15);
              v11 = *(_DWORD *)&v10[1].rectClient[44];
                if (v11) {
                  v12 = *(float *)v11;
                  v13 = *(float *)(v11 + 4);
                    if (*(_DWORD *)(v11 + 212)) {
                      v14 = *(float *)(v11 + 224);
                      v12 = v12 + v14;
                      v13 = v13 + v14;
                    }
                  result = (windowDef_t *)Item_SetScreenCoords(
                      (itemDef_s *)v10, v12, v13, *(_DWORD *)(v11 + 16),
                      *(_DWORD *)(v11 + 20));
                }
            }
          ++v9;
        }
      while (v8 != (windowDef_t *)v9);
    }
  return result;
}

void __cdecl Menu_TransitionItemByName(struct menuDef_t *menu, char const *p,
                                       struct rectDef_s rectFrom,
                                       struct rectDef_s rectTo, int time,
                                       float amt)
{
  windowDef_t *result; // eax
  windowDef_t *v7;     // edi
  int v8;              // esi
  windowDef_t *v9;     // ebx
  int v10;             // eax
  int v11;             // eax
  int v12;             // eax
  int v13;             // eax
  int v14;             // edx
  float v15;           // xmm2_4
  float v16;           // xmm1_4
  float v17;           // xmm0_4
  rectDef_s v18;       // [esp+28h] [ebp-30h] BYREF

  result = (windowDef_t *)Menu_ItemsMatchingGroup(a1, __s);
  v7 = result;
    if ((int)result > 0) {
      v8 = 0;
        do {
          result = (windowDef_t *)Menu_GetMatchingItemByNumber(a1, v8, __s);
          v9 = result;
            if (result) {
              Window_AddDynamicFlags(result, 132);
              Window_SetOffsetTime(v9, a5);
              Window_SetRectClient(v9, &a3);
              Window_SetRectEffects0(v9, &a4);
              v18 = *(rectDef_s *)&v9->rectEffects1[0][0];
              v10 = (int)(float)(*(float *)&a4.x - *(float *)&a3.x);
              if (v10 <= -1)
                v10 = -(int)(float)(*(float *)&a4.x - *(float *)&a3.x);
              *(float *)&v18.x = (float)v10 / a6;
              v11 = (int)(float)(*(float *)&a4.y - *(float *)&a3.y);
              if (v11 <= -1)
                v11 = -(int)(float)(*(float *)&a4.y - *(float *)&a3.y);
              *(float *)&v18.y = (float)v11 / a6;
              v12 = (int)(float)(*(float *)&a4.w - *(float *)&a3.w);
              if (v12 <= -1)
                v12 = -(int)(float)(*(float *)&a4.w - *(float *)&a3.w);
              *(float *)&v18.w = (float)v12 / a6;
              v13 = (int)(float)(*(float *)&a4.h - *(float *)&a3.h);
              if (v13 <= -1)
                v13 = -(int)(float)(*(float *)&a4.h - *(float *)&a3.h);
              *(float *)&v18.h = (float)v13 / a6;
              result = (windowDef_t *)Window_SetRectEffects1(v9, &v18);
              v14 = *(_DWORD *)&v9[1].rectClient[44];
                if (v14) {
                  v15 = *(float *)v14;
                  v16 = *(float *)(v14 + 4);
                    if (*(_DWORD *)(v14 + 212)) {
                      v17 = *(float *)(v14 + 224);
                      v15 = v15 + v17;
                      v16 = v16 + v17;
                    }
                  result = (windowDef_t *)Item_SetScreenCoords(
                      (itemDef_s *)v9, v15, v16, *(_DWORD *)(v14 + 16),
                      *(_DWORD *)(v14 + 20));
                }
            }
          ++v8;
        }
      while (v7 != (windowDef_t *)v8);
    }
  return result;
}

void __cdecl Menus_Close(struct displayContextDef_s *dc, struct menuDef_t *menu)
{
  UNIMPLEMENTED();
}

int __cdecl Rect_ContainsPoint(struct rectDef_s const *, float, float)
{
  UNIMPLEMENTED();
}

struct itemDef_s *__cdecl Menu_ClearFocus(struct displayContextDef_s *,
                                          struct menuDef_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Menu_SetFeederSelection(struct displayContextDef_s *dc,
                                     struct menuDef_t *menu, int feeder,
                                     int index, char const *name)
{
  menuDef_t *v5;            // esi
  int result;               // eax
  float v7;                 // xmm0_4
  int v8;                   // edi
  int v9;                   // ebx
  displayContextDef_s *v10; // ebx
  signed int v11;           // esi
  signed int v12;           // ebx
  uint8_t *v13;             // edx
  int v14;                  // ecx
  listBoxDef_s *listBox;    // [esp+18h] [ebp-20h]

  v5 = a2;
  if (a2)
    goto LABEL_2;
    if (a5) {
      result = a1->menuCount;
      if (result <= 0)
        return result;
      v10 = a1;
      v11 = 0;
        while (1) {
          result = I_stricmp(*(char **)(*(_DWORD *)v10->Menus + 192), a5);
          if (!result)
            break;
          ++v11;
          v10 = (displayContextDef_s *)((char *)v10 + 4);
          result = (int)a1;
          if ((signed int)a1->menuCount <= v11)
            return result;
        }
      v5 = *(menuDef_t **)&a1->Menus[4 * v11];
    }
    else {
      result = (int)a1;
      v12 = a1->openMenuCount - 1;
      if (v12 < 0)
        return result;
      v13 = &a1->menuStack[4 * v12];
      v14 = 0;
        do {
          v5 = *(menuDef_t **)v13;
          result = *(_DWORD *)(*(_DWORD *)v13 + 232);
          if ((result & 4) != 0 && (result & 2) != 0)
            break;
          ++v14;
          v13 -= 4;
          result = a1->openMenuCount;
        }
      while (v14 != result);
    }
    if (v5) {
    LABEL_2:
      result = v5->itemCount;
        if (result > 0) {
          v7 = (float)a3;
          v8 = 0;
            while (1) {
              v9 = 4 * v8;
              result = *(_DWORD *)(4 * v8 + v5->items);
              if (v7 != *(float *)(result + 728))
                goto LABEL_4;
              listBox = (listBoxDef_s *)Item_GetListBoxDef(
                            *(itemDef_s **)(4 * v8 + v5->items))
                            .listBox;
              Item_SetCursorPos(*(itemDef_s **)(v9 + v5->items), a4);
              UI_FeederSelection(
                  *(float *)(*(_DWORD *)(v9 + v5->items) + 728),
                  *(_DWORD *)(*(_DWORD *)(v9 + v5->items) + 732));
              result = (int)listBox;
              if (!listBox)
                goto LABEL_4;
              if (!a4)
                break;
              result = a4;
              if (a4 >= *(_DWORD *)listBox->startPos)
                goto LABEL_4;
              result = (int)ListBox_SetStartPos(listBox, a4);
              if (++v8 >= (signed int)v5->itemCount)
                return result;
            LABEL_5:
              v7 = (float)a3;
            }
          ListBox_SetCursorPos(listBox, 0);
          result = (int)ListBox_SetStartPos(listBox, 0);
        LABEL_4:
          if (++v8 >= (signed int)v5->itemCount)
            return result;
          goto LABEL_5;
        }
    }
  return result;
}

void __cdecl Item_Text_Wrapped_Paint(struct itemDef_s *item,
                                     char const *textPtr, float *const color)
{
  UNIMPLEMENTED();
}

void __cdecl Item_Text_AutoWrapped_Paint(struct itemDef_s *item,
                                         char const *textPtr,
                                         float *const color)
{
  UNIMPLEMENTED();
}

struct itemDef_s *__cdecl Menu_HitTest(struct menuDef_t *, float, float)
{
  UNIMPLEMENTED();
}

int __cdecl Item_Slider_OverSlider(struct itemDef_s *, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl Menus_CloseAll(struct displayContextDef_s *dc)
{
  UNIMPLEMENTED();
}

void __cdecl Menus_CloseByName(struct displayContextDef_s *dc, char const *p)
{
  int result;              // eax
  displayContextDef_s *v3; // ebx
  signed int v4;           // esi

  result = a1->menuCount;
    if (result > 0) {
      v3 = a1;
      v4 = 0;
        while (1) {
          result = I_stricmp(*(char **)(*(_DWORD *)v3->Menus + 192), a2);
          if (!result)
            break;
          ++v4;
          v3 = (displayContextDef_s *)((char *)v3 + 4);
          if (v4 >= (signed int)a1->menuCount)
            return result;
        }
      result = *(_DWORD *)&a1->Menus[4 * v4];
      if (result)
        return Menus_Close(a1, *(menuDef_t **)&a1->Menus[4 * v4]);
    }
  return result;
}

int __cdecl Color_Parse(char const **, float (*)[4])
{
  UNIMPLEMENTED();
}

int __cdecl Item_YesNo_HandleKey(struct displayContextDef_s *dc,
                                 struct itemDef_s *item, int key)
{
  int v3;              // eax
  float cursory;       // xmm1_4
  float cursorx;       // xmm0_4
  char *VariantString; // eax
  int v8;              // eax
  char *v9;            // eax
  char __dst[25];      // [esp+27h] [ebp-41h] BYREF
  float v11;           // [esp+40h] [ebp-28h] BYREF
  float v12;           // [esp+44h] [ebp-24h] BYREF
  float v13;           // [esp+48h] [ebp-20h] BYREF
  float v14[3];        // [esp+4Ch] [ebp-1Ch] BYREF
  float v15;           // [esp+58h] [ebp-10h] BYREF
  float v16[3];        // [esp+5Ch] [ebp-Ch] BYREF

  if (!a2->dvar)
    return 0;
  v3 = *(_DWORD *)&a2->window[232];
  if ((v3 & 4) == 0)
    return 0;
  if ((v3 & 2) == 0)
    return 0;
    if ((unsigned int)(a3 - 200) <= 2) {
      cursory = (float)a1->cursory;
      cursorx = (float)a1->cursorx;
      v11 = *(float *)a2->window;
      v12 = *(float *)&a2->window[4];
      v13 = *(float *)&a2->window[8];
      v14[0] = *(float *)&a2->window[12];
      v16[0] = cursorx;
      v15 = cursory;
      CalcScreenX(v16, 4);
      CalcScreenY(&v15, 4);
      CalcScreenPlacement(&v11, &v12, &v13, v14, *(_DWORD *)&a2->window[16],
                          *(_DWORD *)&a2->window[20]);
      if (v16[0] < v11 || (float)(v11 + v13) < v16[0] || v15 < v12 ||
          (float)(v12 + v14[0]) < v15)
        return 0;
    }
  if (a3 != 13 && a3 != 156 && a3 != 157 && a3 != 164 && a3 != 163 &&
      a3 != 200 && a3 != 201 && a3 != 202)
    return 0;
  VariantString = (char *)Dvar_GetVariantString((char *)a2->dvar);
  I_strncpyz(__dst, VariantString, 25);
  v8 = atoi(__dst);
  v9 = va("%i", v8 == 0);
  Dvar_SetFromStringByName((dvar_s *)a2->dvar, (DvarValue)v9);
  return 1;
}

struct MenuList *__cdecl UI_LoadMenu(char const *, int)
{
  UNIMPLEMENTED();
}

struct MenuList *__cdecl UI_LoadMenus(char const *, int)
{
  UNIMPLEMENTED();
}

int __cdecl Item_Slider_HandleKey(struct displayContextDef_s *dc,
                                  struct itemDef_s *item, int key, int down)
{
  int v3;                    // eax
  float cursory;             // xmm1_4
  float cursorx;             // xmm0_4
  itemDefData_t v7;          // eax
  float *listBox;            // esi
  const char *VariantString; // eax
  float v10;                 // xmm0_4
  float v11;                 // xmm0_4
  char *v12;                 // eax
  float v13;                 // [esp+2Ch] [ebp-2Ch]
  float v14;                 // [esp+30h] [ebp-28h] BYREF
  float v15;                 // [esp+34h] [ebp-24h] BYREF
  float v16;                 // [esp+38h] [ebp-20h] BYREF
  float v17[3];              // [esp+3Ch] [ebp-1Ch] BYREF
  float v18;                 // [esp+48h] [ebp-10h] BYREF
  float v19[3];              // [esp+4Ch] [ebp-Ch] BYREF

  if (!a2->dvar)
    return 0;
  v3 = *(_DWORD *)&a2->window[232];
  if ((v3 & 4) == 0)
    return 0;
  if ((v3 & 2) == 0)
    return 0;
    if ((unsigned int)(a3 - 200) <= 2) {
      cursory = (float)a1->cursory;
      cursorx = (float)a1->cursorx;
      v14 = *(float *)a2->window;
      v15 = *(float *)&a2->window[4];
      v16 = *(float *)&a2->window[8];
      v17[0] = *(float *)&a2->window[12];
      v19[0] = cursorx;
      v18 = cursory;
      CalcScreenX(v19, 4);
      CalcScreenY(&v18, 4);
      CalcScreenPlacement(&v14, &v15, &v16, v17, *(_DWORD *)&a2->window[16],
                          *(_DWORD *)&a2->window[20]);
      if (v19[0] < v14 || (float)(v14 + v16) < v19[0] || v18 < v15 ||
          (float)(v15 + v17[0]) < v18)
        return 0;
    }
    if ((unsigned int)(a3 - 200) <= 2) {
      Scroll_Slider_SetThumbPos((int)a1, (int)a2);
      return 1;
    }
  v7.listBox = Item_GetEditFieldDef(a2).listBox;
  listBox = (float *)v7.listBox;
  if (!v7.listBox)
    return 0;
  v13 =
      (float)(*(float *)(v7.listBox + 4) - *(float *)v7.listBox) * 0.050000001;
  VariantString = (const char *)Dvar_GetVariantString((char *)a2->dvar);
  v10 = atof(VariantString);
    if (a3 == 156 || a3 == 164) {
      v11 = fmaxf(v10 - v13, *listBox);
      goto LABEL_18;
    }
  if (a3 != 157 && a3 != 163)
    return 0;
  v11 = fminf(v10 + v13, listBox[1]);
LABEL_18:
  v12 = va("%g", v11);
  Dvar_SetFromStringByName((dvar_s *)a2->dvar, (DvarValue)v12);
  return 1;
}

int __cdecl String_Parse(char const **p, char *out, int len)
{
  char *v3;     // esi
  char *String; // eax

  v3 = Com_ParseOnLine(a1);
  if (!*a1)
    return 0;
    if (*v3 != 64) {
    LABEL_3:
      I_strncpyz(__dst, v3, a3);
      return 1;
    }
  String = (char *)SEH_StringEd_GetString(v3 + 1);
    if (!String) {
        if ((unsigned __int8)Dvar_GetBool("loc_warnings")) {
          if ((unsigned __int8)Dvar_GetBool("loc_warningsAsErrors"))
            Com_Error(6, "Could not translate menu string reference %s",
                      (char)v3);
          else
            Com_Printf(
                "^3WARNING: Could not translate menu string reference %s\n",
                v3);
        }
      goto LABEL_3;
    }
  I_strncpyz(__dst, String, a3);
  return 1;
}

int __cdecl GetKeyBindingLocalizedString(char const *command, char *const keys)
{
  int KeyBindings; // esi
  char *String;    // eax
  const char *v4;  // eax
  char *v5;        // eax
  char *v6;        // eax
  char *v8;        // eax
  char __src[128]; // [esp+10h] [ebp-118h] BYREF
  char v10[152];   // [esp+90h] [ebp-98h] BYREF

  KeyBindings = GetKeyBindings(a1, (char(*)[128])__src);
    if (KeyBindings) {
      String = (char *)SEH_StringEd_GetString(__src);
      if (String)
        I_strncpyz(__dst, String, 256);
      else
        I_strncpyz(__dst, __src, 256);
        if (KeyBindings > 1) {
          v4 = UI_SafeTranslateString("KEY_OR");
          v5 = va(" %s ", v4);
          I_strncat(__dst, 256, v5);
          v6 = (char *)SEH_StringEd_GetString(v10);
            if (v6) {
              I_strncat(__dst, 256, v6);
              return KeyBindings;
            }
          I_strncat(__dst, 256, v10);
        }
    }
    else {
      v8 = (char *)UI_SafeTranslateString("KEY_UNBOUND");
      I_strncpyz(__dst, v8, 256);
    }
  return KeyBindings;
}

void __cdecl BindingFromName(char const *dvar, char *const nameBind)
{
  int v2;          // esi
  char **v3;       // ebx
  int v4;          // edi
  int v5;          // eax
  char *v6;        // eax
  char *result;    // eax
  char *v8;        // eax
  const char *v9;  // eax
  char *v10;       // eax
  char *v11;       // eax
  char __src[152]; // [esp+10h] [ebp-98h] BYREF

  v2 = 0;
  v3 = (char **)&g_bindings;
  v4 = 0;
    while (I_stricmp(a1, *v3)) {
      ++v2;
      v4 += 5;
      v3 += 5;
      if (v2 == 56)
        goto LABEL_7;
    }
  v5 = dword_3121AC[v4];
    if (v5 == -1) {
    LABEL_7:
      v11 = (char *)UI_SafeTranslateString("KEY_UNBOUND");
      return I_strncpyz(__dst, v11, 128);
    }
  Key_KeynumToStringBuf(v5, __dst, 32);
  v6 = (char *)UI_SafeTranslateString(__dst);
  I_strncpyz(__dst, v6, 128);
  result = (char *)dword_3121B0[v4];
    if (result != (char *)-1) {
      Key_KeynumToStringBuf((int)result, __src, 32);
      v8 = (char *)UI_SafeTranslateString(__src);
      I_strncpyz(__src, v8, 128);
      v9 = UI_SafeTranslateString("KEY_OR");
      v10 = va(" %s ", v9);
      I_strncat(__dst, 128, v10);
      return I_strncat(__dst, 128, __src);
    }
  return result;
}

void __cdecl Item_TextColor(struct displayContextDef_s * dc, struct itemDef_s * item, float  newColor)[4])
{
  UNIMPLEMENTED();
}

void __cdecl Item_SetTextExtents(struct itemDef_s *item, int *width,
                                 int *height, char const *text)
{
  char *v5;            // esi
  Font_s *FontHandle;  // edi
  unsigned int type;   // ecx
  float v8;            // xmm1_4
  int v9;              // eax
  int32_t x;           // xmm1_4
  int32_t y;           // xmm0_4
  char *VariantString; // eax
  int v13;             // [esp+1Ch] [ebp-3Ch]
  rectDef_s v14;       // [esp+28h] [ebp-30h] BYREF

    if (a5) {
      v5 = a5;
    }
    else {
      v5 = *(char **)a2->text;
      if (!v5)
        return;
      if (*v5 == 64)
        v5 = (char *)UI_SafeTranslateString(v5 + 1);
    }
  *a3 = (int)*(float *)&a2->textRect[8];
  *a4 = (int)*(float *)&a2->textRect[12];
    if (!*a3 ||
        (a2->type == 8 || a2->dvar) && *(_DWORD *)a2->textalignment == 1 ||
        *(_DWORD *)a2->textalignment == 3) {
      FontHandle =
          (Font_s *)UI_GetFontHandle(a2->fontEnum, *(float *)a2->textscale);
      v13 = UI_TextWidth(a1, v5, 0, FontHandle, *(float *)a2->textscale);
      type = a2->type;
        if (type == 8) {
            if ((unsigned int)(*(_DWORD *)a2->textalignment - 1) <= 1) {
              v13 += UI_OwnerDrawWidth(a1, *(_DWORD *)&a2->window[216],
                                       FontHandle, *(float *)a2->textscale);
            LABEL_14:
              *a3 =
                  UI_TextWidth(a1, v5, 0, FontHandle, *(float *)a2->textscale);
              *a4 = UI_TextHeight(a1, FontHandle, *(float *)a2->textscale);
              *(float *)&v14.w = (float)*a3;
              *(float *)&v14.h = (float)*a4;
              v8 = *(float *)a2->textalignx;
              *(float *)&v14.x = v8;
              v14.y = *(_DWORD *)a2->textaligny;
              v14.horzAlign = *(_DWORD *)&a2->window[16];
              v14.vertAlign = *(_DWORD *)&a2->window[20];
              v9 = *(_DWORD *)a2->textalignment;
                if (v9 == 2) {
                  *(float *)&v14.x = v8 - (float)v13;
                }
                else if (v9 == 1 || v9 == 3) {
                  *(float *)&v14.x = v8 - (float)(v13 / 2);
                }
                if (*(_DWORD *)&a2->window[212]) {
                  *(float *)&x = *(float *)&v14.x + *(float *)&a2->window[224];
                  v14.x = x;
                  *(float *)&y = *(float *)&v14.y + *(float *)&a2->window[224];
                  v14.y = y;
                }
                else {
                  x = v14.x;
                  y = v14.y;
                }
              *(float *)&v14.x = *(float *)&x + *(float *)a2->window;
              *(float *)&v14.y = *(float *)&y + *(float *)&a2->window[4];
              Item_SetTextRect(a2, &v14);
              return;
            }
        }
        else if (type <= 0x12 && ((1 << type) & 0x70210) != 0 &&
                 *(_DWORD *)a2->textalignment == 1 && a2->dvar) {
          VariantString = (char *)Dvar_GetVariantString((char *)a2->dvar);
          v13 += UI_TextWidth(a1, VariantString, 0, FontHandle,
                              *(float *)a2->textscale);
          goto LABEL_14;
        }
      if (*(_DWORD *)a2->textalignment == 3)
        v13 += UI_TextWidth(a1, a5, 0, FontHandle, *(float *)a2->textscale);
      goto LABEL_14;
    }
}

int __cdecl Menu_CheckOnKey(struct displayContextDef_s *dc,
                            struct menuDef_t *menu, int key)
{
  int32_t onKey; // eax
  int v5;        // esi
  menuDef_t *v6; // edx
  int v7;        // ebx
  itemDef_s v8;  // [esp+1Ch] [ebp-30Ch] BYREF

  onKey = a2->onKey;
    if (onKey) {
      if (*(_DWORD *)onKey == a3)
        goto LABEL_5;
        while (1) {
          onKey = *(_DWORD *)(onKey + 8);
          if (!onKey)
            break;
          if (a3 == *(_DWORD *)onKey)
            goto LABEL_5;
        }
    }
  if ((int)a2->itemCount <= 0)
    return 0;
  v5 = 0;
  v6 = a2;
    while (1) {
      v7 = *(_DWORD *)(v6->items + 4 * v5);
      if ((*(_BYTE *)(v7 + 232) & 4) != 0)
        break;
    LABEL_17:
      if ((signed int)v6->itemCount <= ++v5)
        return 0;
    }
    if ((*(_BYTE *)(v7 + 720) & 0xC) != 0 &&
            !Item_EnableShowViaDvar((const itemDef_s *)v7, 4) ||
        (onKey = *(_DWORD *)(v7 + 712)) == 0) {
    LABEL_16:
      v6 = a2;
      goto LABEL_17;
    }
    while (a3 != *(_DWORD *)onKey) {
      onKey = *(_DWORD *)(onKey + 8);
      if (!onKey)
        goto LABEL_16;
    }
LABEL_5:
  v8.parent = (int32_t)a2;
  Item_RunScript(a1, &v8, *(const char **)(onKey + 4));
  return 1;
}

int __cdecl Item_SetFocus(struct displayContextDef_s *dc,
                          struct itemDef_s *item, float x, float y)
{
  int v4;                // eax
  int32_t parent;        // ecx
  int v6;                // eax
  const itemDef_s *v7;   // edx
  uint32_t dvarFlags;    // eax
  int32_t v9;            // esi
  int v10;               // ebx
  int v11;               // eax
  int v12;               // edx
  bool v13;              // zf
  windowDef_t *v14;      // edx
  int v15;               // edx
  itemDef_s *v16;        // ebx
  snd_alias_list_t *v17; // eax
  signed int v18;        // esi
  uint8_t *v19;          // edx
  int v20;               // ecx
  int v21;               // ebx
  int v22;               // eax
  itemDef_s *v24;        // ecx
  char *textRect;        // eax
  float v26;             // edx
  int v27;               // ebx
  int v28;               // esi
  float v29;             // xmm1_4
  float v30;             // xmm0_4
  int itemCount;         // ecx
  itemDef_s **items;     // edx
  int v33;               // eax
  windowDef_t *v34;      // [esp+24h] [ebp-44h]
  int v35;               // [esp+28h] [ebp-40h]
  menuDef_t *v36;        // [esp+2Ch] [ebp-3Ch]
  float v37;             // [esp+30h] [ebp-38h] BYREF
  float v38;             // [esp+34h] [ebp-34h] BYREF
  float v39;             // [esp+38h] [ebp-30h] BYREF
  float v40[3];          // [esp+3Ch] [ebp-2Ch] BYREF
  float v41;             // [esp+48h] [ebp-20h] BYREF
  float v42[7];          // [esp+4Ch] [ebp-1Ch] BYREF

  v35 = dword_1684B00;
  if (!a2)
    return 0;
  if ((a2->window[230] & 0x10) != 0)
    return 0;
  v4 = *(_DWORD *)&a2->window[232];
  if ((v4 & 4) == 0)
    return 0;
  if ((v4 & 2) != 0)
    return 1;
  parent = a2->parent;
  v36 = (menuDef_t *)parent;
    if (parent) {
      v6 = *(_DWORD *)(parent + 232);
        if ((v6 & 4) == 0 || (v6 & 2) == 0) {
          v18 = a1->openMenuCount - 1;
            if (v18 >= 0) {
              v19 = &a1->menuStack[4 * v18];
              v20 = 0;
                while (1) {
                  v21 = *(_DWORD *)v19;
                  v22 = *(_DWORD *)(*(_DWORD *)v19 + 232);
                  if ((v22 & 4) != 0 && (v22 & 2) != 0)
                    break;
                  ++v20;
                  v19 -= 4;
                    if (v20 == a1->openMenuCount) {
                      v7 = a2;
                      dvarFlags = a2->dvarFlags;
                      if ((dvarFlags & 3) == 0)
                        goto LABEL_9;
                      goto LABEL_54;
                    }
                }
              if (!v21)
                goto LABEL_8;
              v37 = *(float *)v21;
              v38 = *(float *)(v21 + 4);
              v39 = *(float *)(v21 + 8);
              v40[0] = *(float *)(v21 + 12);
              v42[0] = a3;
              v41 = a4;
              CalcScreenX(v42, 4);
              CalcScreenY(&v41, 4);
              CalcScreenPlacement(&v37, &v38, &v39, v40, *(_DWORD *)(v21 + 16),
                                  *(_DWORD *)(v21 + 20));
              if (v42[0] < v37)
                goto LABEL_8;
              if ((float)(v37 + v39) < v42[0])
                goto LABEL_8;
              if (v41 < v38)
                goto LABEL_8;
              if ((float)(v38 + v40[0]) < v41)
                goto LABEL_8;
              v37 = *(float *)v36->window.rect;
              v38 = *(float *)&v36->window.rect[4];
              v39 = *(float *)&v36->window.rect[8];
              v40[0] = *(float *)&v36->window.rect[12];
              v41 = a3;
              v42[0] = a4;
              CalcScreenX(&v41, 4);
              CalcScreenY(v42, 4);
              CalcScreenPlacement(&v37, &v38, &v39, v40,
                                  *(_DWORD *)&v36->window.rect[16],
                                  *(_DWORD *)&v36->window.rect[20]);
              if (v41 < v37 || (float)(v37 + v39) < v41 || v42[0] < v38 ||
                  (float)(v38 + v40[0]) < v42[0])
                goto LABEL_8;
              return 0;
            }
        }
    }
LABEL_8:
  v7 = a2;
  dvarFlags = a2->dvarFlags;
    if ((dvarFlags & 3) != 0) {
    LABEL_54:
      if (!Item_EnableShowViaDvar(v7, 1))
        return 0;
      dvarFlags = a2->dvarFlags;
    }
LABEL_9:
  if ((dvarFlags & 0xC) != 0 && !Item_EnableShowViaDvar(a2, 4))
    return 0;
  v9 = a2->parent;
    if (v9 && *(int *)(v9 + 536) > 0) {
      v34 = 0;
      v10 = 0;
        do {
          v11 = *(_DWORD *)(4 * v10 + *(_DWORD *)(v9 + 636));
          v12 = *(_DWORD *)(v11 + 232);
            if ((v12 & 4) != 0) {
              v13 = (v12 & 2) == 0;
              v14 = v34;
              if (!v13)
                v14 = *(windowDef_t **)(4 * v10 + *(_DWORD *)(v9 + 636));
              v34 = v14;
            }
          Window_RemoveDynamicFlags((windowDef_t *)v11, 2);
          v15 = *(_DWORD *)(4 * v10 + *(_DWORD *)(v9 + 636));
          if (*(_DWORD *)(v15 + 700))
            Item_RunScript(a1, (itemDef_s *)v15, *(const char **)(v15 + 700));
          ++v10;
        }
      while (v10 < *(_DWORD *)(v9 + 536));
      v16 = a2;
        if (a2->type) {
        LABEL_21:
          Window_AddDynamicFlags((windowDef_t *)v16, 2);
          if (a2->onFocus)
            Item_RunScript(a1, a2, (const char *)a2->onFocus);
          v17 = *(snd_alias_list_t **)a2->focusSound;
          if (v17)
            goto LABEL_24;
          goto LABEL_61;
        }
    }
    else {
      v34 = 0;
      v16 = a2;
      if (a2->type)
        goto LABEL_21;
    }
  v24 = v16;
  textRect = v16->textRect;
  v26 = *(float *)&v16->textRect[8];
  v27 = *(_DWORD *)&v16->textRect[20];
  v28 = *((_DWORD *)textRect + 4);
  v29 = *((float *)textRect + 3);
  v30 = *((float *)textRect + 1);
  v37 = *(float *)v24->textRect;
  v38 = v30 - v29;
  v39 = v26;
  v40[0] = v29;
  v41 = a3;
  v42[0] = a4;
  CalcScreenX(&v41, 4);
  CalcScreenY(v42, 4);
  CalcScreenPlacement(&v37, &v38, &v39, v40, v28, v27);
    if (v41 < v37 || (float)(v37 + v39) < v41 || v42[0] < v38 ||
        (float)(v38 + v40[0]) < v42[0]) {
        if (v34) {
          Window_AddDynamicFlags(v34, 2);
          if (*(_DWORD *)&v34[1].rectClient[72])
            Item_RunScript(a1, (itemDef_s *)v34,
                           *(const char **)&v34[1].rectClient[72]);
        }
      goto LABEL_46;
    }
  Window_AddDynamicFlags((windowDef_t *)a2, 2);
  v17 = *(snd_alias_list_t **)a2->focusSound;
    if (v17) {
    LABEL_24:
      UI_PlayLocalSoundAlias(v17);
      goto LABEL_46;
    }
LABEL_61:
    if (v35) {
      v17 = (snd_alias_list_t *)v35;
      goto LABEL_24;
    }
LABEL_46:
  itemCount = v36->itemCount;
  if (itemCount <= 0)
    return 1;
  items = (itemDef_s **)v36->items;
    if (a2 != *items) {
      v33 = 0;
        while (itemCount != ++v33) {
          if (a2 == items[v33])
            goto LABEL_51;
        }
      return 1;
    }
  v33 = 0;
LABEL_51:
  Menu_SetCursorItem(v36, v33);
  return 1;
}

void __cdecl Script_Play(struct displayContextDef_s *dc, struct itemDef_s *item,
                         char const **args)
{
  int result;       // eax
  char __dst[1032]; // [esp+10h] [ebp-408h] BYREF

  result = String_Parse(a3, __dst, 1024);
  if (result)
    return UI_PlayLocalSoundAliasByName(__dst);
  return result;
}

void __cdecl Script_SetDvar(struct displayContextDef_s *dc,
                            struct itemDef_s *item, char const **args)
{
  dvar_s *result; // eax
  DvarValue v4;   // [esp+10h] [ebp-818h] BYREF
  dvar_s v5;      // [esp+410h] [ebp-418h] BYREF

  result = (dvar_s *)String_Parse(a3, v5.name, 1024);
    if (result) {
      result = (dvar_s *)String_Parse(a3, (char *)&v4, 1024);
      if (result)
        return Dvar_SetFromStringByName(&v5, (DvarValue)&v4);
    }
  return result;
}

void __cdecl Script_Orbit(struct displayContextDef_s *dc,
                          struct itemDef_s *item, char const **args)
{
  windowDef_t *result; // eax
  char __s[1024];      // [esp+2Ch] [ebp-41Ch] BYREF
  int v5;              // [esp+42Ch] [ebp-1Ch] BYREF
  int32_t v6;          // [esp+430h] [ebp-18h] BYREF
  int32_t v7;          // [esp+434h] [ebp-14h] BYREF
  int32_t v8;          // [esp+438h] [ebp-10h] BYREF
  int32_t v9[3];       // [esp+43Ch] [ebp-Ch] BYREF

  result = (windowDef_t *)String_Parse(a3, __s, 1024);
    if (result) {
      result = (windowDef_t *)Float_Parse(a3, (float *)&v7);
        if (result) {
          result = (windowDef_t *)Float_Parse(a3, (float *)&v6);
            if (result) {
              result = (windowDef_t *)Float_Parse(a3, (float *)v9);
                if (result) {
                  result = (windowDef_t *)Float_Parse(a3, (float *)&v8);
                    if (result) {
                      result = (windowDef_t *)Int_Parse(a3, &v5);
                      if (result)
                        return Menu_OrbitItemByName((menuDef_t *)a2->parent,
                                                    __s, v7, v6, v9[0], v8, v5);
                    }
                }
            }
        }
    }
  return result;
}

void __cdecl Script_Transition(struct displayContextDef_s *dc,
                               struct itemDef_s *item, char const **args)
{
  windowDef_t *result; // eax
  char __s[1024];      // [esp+48h] [ebp-480h] BYREF
  rectDef_s v5;        // [esp+448h] [ebp-80h]
  rectDef_s v6;        // [esp+460h] [ebp-68h] BYREF
  rectDef_s v7;        // [esp+478h] [ebp-50h] BYREF
  rectDef_s v8;        // [esp+490h] [ebp-38h]
  int v9;              // [esp+4A8h] [ebp-20h] BYREF
  float v10[7];        // [esp+4ACh] [ebp-1Ch] BYREF

  result = (windowDef_t *)String_Parse(a3, __s, 1024);
    if (result) {
      result = (windowDef_t *)Rect_Parse(a3, &v6);
        if (result) {
          result = (windowDef_t *)Rect_Parse(a3, &v7);
            if (result) {
              result = (windowDef_t *)Int_Parse(a3, &v9);
                if (result) {
                  result = (windowDef_t *)Float_Parse(a3, v10);
                    if (result) {
                      v5 = v7;
                      v8 = v6;
                      return Menu_TransitionItemByName((menuDef_t *)a2->parent,
                                                       __s, v6, v7, v9, v10[0]);
                    }
                }
            }
        }
    }
  return result;
}

void __cdecl Script_InGameClose(struct displayContextDef_s *dc,
                                struct itemDef_s *item, char const **args)
{
  UNIMPLEMENTED();
}

void __cdecl Script_Close(struct displayContextDef_s *dc,
                          struct itemDef_s *item, char const **args)
{
  UNIMPLEMENTED();
}

void __cdecl Script_CloseForGameType(struct displayContextDef_s *dc,
                                     struct itemDef_s *item, char const **args)
{
  UNIMPLEMENTED();
}

void __cdecl Script_FadeOut(struct displayContextDef_s *dc,
                            struct itemDef_s *item, char const **args)
{
  windowDef_t *result; // eax
  char __s[1032];      // [esp+10h] [ebp-408h] BYREF

  result = (windowDef_t *)String_Parse(a3, __s, 1024);
  if (result)
    return Menu_FadeItemByName((menuDef_t *)a2->parent, __s, 1);
  return result;
}

void __cdecl Script_FadeIn(struct displayContextDef_s *dc,
                           struct itemDef_s *item, char const **args)
{
  windowDef_t *result; // eax
  char __s[1032];      // [esp+10h] [ebp-408h] BYREF

  result = (windowDef_t *)String_Parse(a3, __s, 1024);
  if (result)
    return Menu_FadeItemByName((menuDef_t *)a2->parent, __s, 0);
  return result;
}

void __cdecl Script_Hide(struct displayContextDef_s *dc, struct itemDef_s *item,
                         char const **args)
{
  windowDef_t *result; // eax
  char __dst[1032];    // [esp+10h] [ebp-408h] BYREF

  result = (windowDef_t *)String_Parse(a3, __dst, 1024);
  if (result)
    return Menu_ShowItemByName((menuDef_t *)a2->parent, __dst, 0);
  return result;
}

void __cdecl Script_Show(struct displayContextDef_s *dc, struct itemDef_s *item,
                         char const **args)
{
  windowDef_t *result; // eax
  char __dst[1032];    // [esp+10h] [ebp-408h] BYREF

  result = (windowDef_t *)String_Parse(a3, __dst, 1024);
  if (result)
    return Menu_ShowItemByName((menuDef_t *)a2->parent, __dst, 1);
  return result;
}

void __cdecl Script_SetItemColor(struct displayContextDef_s *dc,
                                 struct itemDef_s *item, char const **args)
{
  int result;       // eax
  int i;            // ebx
  int j;            // edi
  windowDef_t *v6;  // esi
  float *backColor; // ebx
  int *v8;          // edx
  int k;            // ecx
  int v10;          // [esp+1Ch] [ebp-83Ch]
  char __dst[1024]; // [esp+2Ch] [ebp-82Ch] BYREF
  char __s[1040];   // [esp+42Ch] [ebp-42Ch] BYREF
  float v13[7];     // [esp+83Ch] [ebp-1Ch] BYREF

  result = String_Parse(a3, __s, 1024);
    if (result) {
      result = String_Parse(a3, __dst, 1024);
        if (result) {
          v10 = Menu_ItemsMatchingGroup((menuDef_t *)a2->parent, __s);
            for (i = 1; i != 5; ++i) {
              result = Float_Parse(a3, v13);
              if (!result)
                return result;
              result = LODWORD(v13[0]);
              *(float *)&__s[4 * i + 1020] = v13[0];
            }
            if (v10 > 0) {
                for (j = 0; v10 != j; ++j) {
                  result = Menu_GetMatchingItemByNumber((menuDef_t *)a2->parent,
                                                        j, __s);
                  v6 = (windowDef_t *)result;
                    if (result) {
                      result = I_stricmp(__dst, "backcolor");
                        if (!result) {
                          backColor = v6->backColor;
                          goto LABEL_12;
                        }
                        if (!I_stricmp(__dst, "forecolor")) {
                          backColor = v6->foreColor;
                          result = Window_AddDynamicFlags(v6, 0x10000);
                        LABEL_12:
                            if (backColor) {
                              v8 = (int *)backColor;
                                for (k = 1; k != 5; ++k) {
                                  result = *(_DWORD *)&__s[4 * k + 1020];
                                  *v8++ = result;
                                }
                            }
                          continue;
                        }
                      result = I_stricmp(__dst, "bordercolor");
                        if (!result) {
                          backColor = v6->borderColor;
                          goto LABEL_12;
                        }
                    }
                }
            }
        }
    }
  return result;
}

void __cdecl Script_SetBackground(struct displayContextDef_s *dc,
                                  struct itemDef_s *item, char const **args)
{
  int result;       // eax
  char __dst[1032]; // [esp+10h] [ebp-408h] BYREF

  result = String_Parse(a3, __dst, 1024);
    if (result) {
      result = CL_RegisterMaterialNoMip(__dst, a2->imageTrack);
      *(_DWORD *)&a2->window[524] = result;
    }
  return result;
}

void __cdecl Script_SetColor(struct displayContextDef_s *dc,
                             struct itemDef_s *item, char const **args)
{
  int result;           // eax
  uint8_t *borderColor; // ebx
  int v5;               // esi
  char __dst[1024];     // [esp+1Ch] [ebp-41Ch] BYREF
  float v7[7];          // [esp+41Ch] [ebp-1Ch] BYREF

  result = String_Parse(a3, __dst, 1024);
    if (result) {
        if (I_stricmp(__dst, "backcolor")) {
            if (I_stricmp(__dst, "forecolor")) {
              result = I_stricmp(__dst, "bordercolor");
              if (result)
                return result;
              borderColor = (uint8_t *)a2->borderColor;
            }
            else {
              borderColor = (uint8_t *)a2->foreColor;
              result = Window_AddDynamicFlags(a2, 0x10000);
            }
        }
        else {
          borderColor = (uint8_t *)a2->backColor;
          result = Window_AddDynamicFlags(a2, 0x8000);
        }
        if (borderColor) {
          v5 = 4;
            do {
              result = Float_Parse(a3, v7);
              if (!result)
                break;
              result = LODWORD(v7[0]);
              *(float *)borderColor = v7[0];
              borderColor += 4;
              --v5;
            }
          while (v5);
        }
    }
  return result;
}

void __cdecl Controls_SetConfig(int restart)
{
  int *v0; // ebx
  int v1;  // edx
  char v2; // [esp+8h] [ebp-10h]

  v0 = dword_3121AC;
    do {
        if (*v0 != -1) {
          Key_SetBinding(*v0, (char *)*(v0 - 3));
          v1 = v0[1];
          if (v1 != -1)
            Key_SetBinding(v1, (char *)*(v0 - 3));
        }
      v0 += 5;
    }
  while (v0 != (int *)&unk_31260C);
  Cbuf_ExecuteText(2, "in_restart\n", v2);
}

void __cdecl Item_Text_Paint(struct displayContextDef_s *dc,
                             struct itemDef_s *item)
{
  char *v3;             // edi
  uint32_t staticFlags; // eax
  float v5;             // ebx
  Font_s *FontHandle;   // eax
  char *VariantString;  // eax
  int v8;               // [esp+40h] [ebp-448h]
  int v9;               // [esp+44h] [ebp-444h]
  float v10;            // [esp+48h] [ebp-440h]
  float v11;            // [esp+4Ch] [ebp-43Ch]
  char __dst[1040];     // [esp+58h] [ebp-430h] BYREF
  int v13;              // [esp+468h] [ebp-20h] BYREF
  int v14[7];           // [esp+46Ch] [ebp-1Ch] BYREF

  v3 = *(char **)&a3[1].rectClient[36];
    if (v3) {
      if (*v3 != 64)
        goto LABEL_3;
      goto LABEL_11;
    }
  if (!*(_DWORD *)&a3[1].rectClient[80])
    return;
  VariantString =
      (char *)Dvar_GetVariantString(*(char **)&a3[1].rectClient[80]);
  I_strncpyz(__dst, VariantString, 1024);
  v3 = __dst;
  if (__dst[0] == 64)
  LABEL_11:
    v3 = (char *)UI_SafeTranslateString(v3 + 1);
LABEL_3:
    if (*v3) {
      Item_TextColor(a2, a3, (float(*)[4]) & __dst[1024]);
      Item_SetTextExtents(a1, (itemDef_s *)a3, &v13, v14, v3);
      staticFlags = a3->staticFlags;
        if ((staticFlags & 0x400000) != 0) {
          Item_Text_Wrapped_Paint(a1, (itemDef_s *)a3, v3);
        }
        else if ((staticFlags & 0x800000) != 0) {
          Item_Text_AutoWrapped_Paint(a1, (itemDef_s *)a3, v3);
        }
        else {
          v5 = *(float *)&a3[1].rectClient[28];
          v8 = *(_DWORD *)&a3->rect[20];
          v9 = *(_DWORD *)&a3->rect[16];
          v10 = *(float *)&a3[1].rect[4];
          v11 = *(float *)a3[1].rect;
          FontHandle =
              (Font_s *)UI_GetFontHandle(*(_DWORD *)&a3[1].rectClient[12], v5);
          UI_DrawText(a1, v3, 0x7FFFFFFF, FontHandle, v11, v10, v9, v8, v5);
        }
    }
}

struct itemDef_s *__cdecl Menu_SetNextCursorItem(struct displayContextDef_s *dc,
                                                 struct menuDef_t *menu)
{
  signed int v2; // edx
  int v3;        // edi
  signed int v4; // edx
  float *v5;     // eax
  __int64 v7;    // [esp+8h] [ebp-30h]
  int v8;        // [esp+1Ch] [ebp-1Ch]

  v8 = *(_DWORD *)a2->cursorItem;
  v2 = v8;
    if (v8 == -1) {
      Menu_SetCursorItem(a2, 0);
      v3 = 1;
      v2 = *(_DWORD *)a2->cursorItem;
    }
    else {
      v3 = 0;
    }
    while (1) {
        if (v2 >= (signed int)a2->itemCount) {
          Menu_SetCursorItem(a2, v8);
          return 0;
        }
      Menu_SetCursorItem(a2, v2 + 1);
      v4 = *(_DWORD *)a2->cursorItem;
      if (v4 >= (signed int)a2->itemCount)
        break;
    LABEL_8:
        if (Item_SetFocus(a1, *(itemDef_s **)(a2->items + 4 * v4),
                          (float)a1->cursorx, (float)a1->cursory)) {
          v5 = *(float **)(a2->items + 4 * *(_DWORD *)a2->cursorItem);
          *((float *)&v7 + 1) = v5[1] + 1.0;
          *(float *)&v7 = *v5 + 1.0;
          Menu_HandleMouseMove(a1, a2, v7);
          return *(_DWORD *)(a2->items + 4 * *(_DWORD *)a2->cursorItem);
        }
      v2 = *(_DWORD *)a2->cursorItem;
    }
    if (!v3) {
      Menu_SetCursorItem(a2, 0);
      LOWORD(v3) = 1;
      v4 = *(_DWORD *)a2->cursorItem;
      goto LABEL_8;
    }
  return *(_DWORD *)(a2->items + 4 * v8);
}

struct itemDef_s *__cdecl Menu_SetPrevCursorItem(struct displayContextDef_s *dc,
                                                 struct menuDef_t *menu)
{
  int v2;     // edi
  int v3;     // eax
  int v4;     // edx
  float *v6;  // eax
  __int64 v7; // [esp+8h] [ebp-30h]
  int v8;     // [esp+1Ch] [ebp-1Ch]

  v2 = *(_DWORD *)a2->cursorItem;
  v3 = v2;
    if (v2 < 0) {
      Menu_SetCursorItem(a2, a2->itemCount - 1);
      v8 = 1;
      v3 = *(_DWORD *)a2->cursorItem;
    }
    else {
      v8 = 0;
    }
    while (1) {
        if (v3 <= -1) {
        LABEL_10:
          Menu_SetCursorItem(a2, v2);
          return 0;
        }
      Menu_SetCursorItem(a2, v3 - 1);
        if (*(int *)a2->cursorItem >= 0 || v8) {
          v4 = *(_DWORD *)a2->cursorItem;
          if (v4 < 0)
            goto LABEL_10;
        }
        else {
          Menu_SetCursorItem(a2, a2->itemCount - 1);
          v8 = 1;
          v4 = *(_DWORD *)a2->cursorItem;
          if (v4 < 0)
            goto LABEL_10;
        }
      if (Item_SetFocus(a1, *(itemDef_s **)(a2->items + 4 * v4),
                        (float)a1->cursorx, (float)a1->cursory))
        break;
      v3 = *(_DWORD *)a2->cursorItem;
    }
  v6 = *(float **)(a2->items + 4 * *(_DWORD *)a2->cursorItem);
  *((float *)&v7 + 1) = v6[1] + 1.0;
  *(float *)&v7 = *v6 + 1.0;
  Menu_HandleMouseMove(a1, a2, v7);
  return *(_DWORD *)(a2->items + 4 * *(_DWORD *)a2->cursorItem);
}

int __cdecl Item_TextField_HandleKey(struct displayContextDef_s *dc,
                                     struct itemDef_s *item, int key)
{
  int v3;                // ebx
  itemDefData_t v4;      // esi
  char *VariantString;   // eax
  int v6;                // edi
  int v7;                // eax
  itemDef_s *v9;         // edx
  int v10;               // eax
  itemDef_s *v11;        // edx
  char *v12;             // eax
  int CursorPosOffset;   // eax
  itemDefData_t v14;     // edi
  int v15;               // eax
  int v16;               // eax
  int v17;               // eax
  itemDef_s *v18;        // esi
  itemDef_s *v19;        // edx
  char *v20;             // eax
  itemDefData_t v21;     // eax
  itemDefData_t v22;     // ebx
  int v23;               // eax
  int v24;               // eax
  itemDef_s *v25;        // eax
  int v26;               // eax
  itemDef_s *CursorItem; // edx
  int v28;               // eax
  int OverstrikeMode;    // eax
  int v30;               // [esp+4h] [ebp-424h]
  char __b[1048];        // [esp+10h] [ebp-418h] BYREF

  v3 = a3;
  v4.listBox = Item_GetEditFieldDef(a2).listBox;
  if (!v4.listBox || !a2->dvar)
    return 0;
  memset(__b, 0, 0x400u);
  VariantString = (char *)Dvar_GetVariantString((char *)a2->dvar);
  I_strncpyz(__b, VariantString, 1024);
  v6 = strlen(__b);
  v7 = *(_DWORD *)(v4.listBox + 16);
    if (v7 && v6 > v7) {
      __b[v7] = 0;
      v6 = v7;
      if ((a3 & 0x400) != 0)
        goto LABEL_18;
    }
    else if ((a3 & 0x400) != 0) {
    LABEL_18:
      BYTE1(v3) = BYTE1(a3) & 0xFB;
        if (v3 != 8) {
          if (a2->type == 16 && !I_isforfilename(v3) || v3 <= 31 || !a2->dvar)
            return 1;
          if (a2->type == 9 && !I_isdigit(v3))
            return 0;
            if (a2->type == 17) {
              if (!I_isdigit(v3) && v3 != (char)Com_GetDecimalDelimiter())
                return 0;
              if (v3 == (char)Com_GetDecimalDelimiter())
                v3 = 46;
              v9 = a2;
            }
            else {
              v9 = a2;
            }
          if (v9->type == 18)
            v3 = __toupper(v3);
            if (Key_GetOverstrikeMode()) {
              v26 = *(_DWORD *)(v4.listBox + 16);
                if (v26) {
                  v11 = a2;
                    if (v26 <= *(_DWORD *)a2->cursorPos) {
                      if (!*(_DWORD *)(v4.listBox + 20))
                        return 1;
                      CursorItem = (itemDef_s *)Menu_SetNextCursorItem(
                          a1, (menuDef_t *)a2->parent);
                      if (!CursorItem)
                        return 1;
                    LABEL_69:
                        if (CursorItem->type <= 0x12u &&
                            ((1 << CursorItem->type) & 0x70210) != 0) {
                          g_editItem = CursorItem;
                          return 1;
                        }
                      return 1;
                    }
                }
                else {
                  v11 = a2;
                }
            }
            else {
              if (v6 == 255)
                return 1;
              v10 = *(_DWORD *)(v4.listBox + 16);
                if (v10) {
                  if (v6 >= v10)
                    return 1;
                }
              memmove(&__b[*(_DWORD *)a2->cursorPos + 1],
                      &__b[*(_DWORD *)a2->cursorPos],
                      v6 - *(_DWORD *)a2->cursorPos + 1);
              v11 = a2;
            }
          __b[*(_DWORD *)v11->cursorPos] = v3;
          Dvar_SetFromStringByName((dvar_s *)v11->dvar, (DvarValue)__b);
          v12 = (char *)Dvar_GetVariantString((char *)a2->dvar);
          I_strncpyz(__b, v12, 1024);
          CursorPosOffset = Item_GetCursorPosOffset(a2, __b, 1);
          Item_SetCursorPos(a2, CursorPosOffset);
          v14.listBox = Item_GetEditFieldDef(a2).listBox;
          v15 = *(_DWORD *)a2->cursorPos;
            if (v15 < *(_DWORD *)(v14.listBox + 28) ||
                (v16 = *(_DWORD *)(v14.listBox + 24)) != 0 &&
                    (v15 = Item_GetCursorPosOffset(a2, __b, -v16),
                     v15 > *(_DWORD *)(v14.listBox + 28))) {
              *(_DWORD *)(v14.listBox + 28) = v15;
            }
          v17 = *(_DWORD *)(v4.listBox + 16);
            if (v17) {
                if (v17 <= *(_DWORD *)a2->cursorPos) {
                    if (*(_DWORD *)(v4.listBox + 20)) {
                      v18 = (itemDef_s *)Menu_SetNextCursorItem(
                          a1, (menuDef_t *)a2->parent);
                      Item_SetCursorPos(v18, 0);
                        if (v18) {
                          if (v18->type <= 0x12u &&
                              ((1 << v18->type) & 0x70210) != 0)
                            g_editItem = v18;
                        }
                    }
                }
            }
        LABEL_11:
            if (v3 == 9 || v3 == 155) {
              v25 = (itemDef_s *)Menu_SetNextCursorItem(
                  a1, (menuDef_t *)a2->parent);
                if (v25) {
                  if (v25->type <= 0x12u && ((1 << v25->type) & 0x70210) != 0)
                    g_editItem = v25;
                }
            }
            if (v3 != 154) {
                if (v3 == 13 || v3 == 191) {
                  if (a2->onAccept)
                    Item_RunScript(a1, a2, (const char *)a2->onAccept);
                  if (v3 == 13)
                    return 0;
                  if (v3 == 191)
                    return 0;
                }
              return v3 != 27;
            }
          CursorItem =
              (itemDef_s *)Menu_SetPrevCursorItem(a1, (menuDef_t *)a2->parent);
          if (!CursorItem)
            return 1;
          goto LABEL_69;
        }
      v19 = a2;
        if (*(int *)a2->cursorPos > 0) {
          memmove(&__b[*(_DWORD *)a2->cursorPos - 1],
                  &__b[*(_DWORD *)a2->cursorPos],
                  v6 - *(_DWORD *)a2->cursorPos + 1);
          v19 = a2;
        }
      Dvar_SetFromStringByName((dvar_s *)v19->dvar, (DvarValue)__b);
      v20 = (char *)Dvar_GetVariantString((char *)a2->dvar);
      I_strncpyz(__b, v20, 1024);
      v30 = Item_GetCursorPosOffset(a2, __b, -1);
      Item_SetCursorPos(a2, v30);
      goto LABEL_51;
    }
    switch (a3) {
    case 162:
        if (v6 > *(_DWORD *)a2->cursorPos) {
          memmove(&__b[*(_DWORD *)a2->cursorPos],
                  &__b[*(_DWORD *)a2->cursorPos + 1],
                  v6 - *(_DWORD *)a2->cursorPos);
          Dvar_SetFromStringByName((dvar_s *)a2->dvar, (DvarValue)__b);
          return 1;
        }
      return 1;
    case 157:
      v28 = Item_GetCursorPosOffset(a2, __b, 1);
      goto LABEL_74;
    case 156:
      v28 = Item_GetCursorPosOffset(a2, __b, -1);
    LABEL_74:
      Item_SetCursorPos(a2, v28);
      v21.listBox = Item_GetEditFieldDef(a2).listBox;
      goto LABEL_52;
    case 165:
      Item_SetCursorPos(a2, 0);
      *(_DWORD *)(v4.listBox + 28) = 0;
      return 1;
    case 166:
      Item_SetCursorPos(a2, v6);
    LABEL_51:
      v21.listBox = Item_GetEditFieldDef(a2).listBox;
    LABEL_52:
      v22.listBox = v21.listBox;
      v23 = *(_DWORD *)a2->cursorPos;
        if (v23 < *(_DWORD *)(v22.listBox + 28) ||
            (v24 = *(_DWORD *)(v22.listBox + 24)) != 0 &&
                (v23 = Item_GetCursorPosOffset(a2, __b, -v24),
                 v23 > *(_DWORD *)(v22.listBox + 28))) {
          *(_DWORD *)(v22.listBox + 28) = v23;
          return 1;
        }
      return 1;
    }
  if (a3 != 161)
    goto LABEL_11;
  OverstrikeMode = Key_GetOverstrikeMode();
  Key_SetOverstrikeMode(OverstrikeMode == 0);
  return 1;
}

int __cdecl Item_ListBox_MaxScroll(struct itemDef_s *item)
{
  itemDefData_t v1; // ebx
  int32_t v2;       // eax
  int result;       // eax

  v1.listBox = Item_GetListBoxDef(a1).listBox;
  v2 = UI_FeederCount(*(float *)a1->special);
  if (!v1.listBox)
    return 0;
    if ((a1->window[230] & 0x20) != 0) {
      result =
          v2 -
          (int)(float)(*(float *)&a1->window[8] / *(float *)(v1.listBox + 52)) +
          1;
      if (result >= 0)
        return result;
      return 0;
    }
  result =
      v2 -
      (int)(float)(*(float *)&a1->window[12] / *(float *)(v1.listBox + 56)) + 1;
  if (result < 0)
    return 0;
  return result;
}

void __cdecl Script_ScriptMenuResponse(struct displayContextDef_s *dc,
                                       struct itemDef_s *item,
                                       char const **args)
{
  int v3;             // ebx
  char *ConfigString; // eax
  int Int;            // eax
  char *v6;           // eax
  char v7;            // [esp+8h] [ebp-420h]
  char __dst[1048];   // [esp+10h] [ebp-418h] BYREF

    if (*(_BYTE *)(legacyHacks + 1261) && String_Parse(a3, __dst, 1024)) {
      v3 = 0;
        while (1) {
          ConfigString = CL_GetConfigString(v3 + 1246);
            if (*ConfigString) {
              if (!I_stricmp(*(char **)(a2->parent + 192), ConfigString))
                break;
            }
            if (++v3 == 32) {
              v3 = -1;
              break;
            }
        }
      Int = Dvar_GetInt("sv_serverId");
      v6 = va("cmd mr %i %i %s\n", Int, v3, __dst);
      Cbuf_ExecuteText(2, v6, v7);
    }
}

int __cdecl Item_Bind_HandleKey(struct displayContextDef_s *dc,
                                struct itemDef_s *item, int key, int down)
{
  int v4;        // esi
  char *v6;      // edx
  int v7;        // edi
  char **v8;     // ebx
  char *i;       // edx
  int v10;       // edx
  int *v11;      // ebx
  int v12;       // edx
  float cursory; // xmm1_4
  float cursorx; // xmm0_4
  char *dvar;    // edi
  int v16;       // esi
  char **v17;    // ebx
  int v18;       // eax
  int v19;       // eax
  char v20;      // [esp+8h] [ebp-60h]
  int32_t v21;   // [esp+2Ch] [ebp-3Ch]
  float v22;     // [esp+30h] [ebp-38h] BYREF
  float v23;     // [esp+34h] [ebp-34h] BYREF
  float v24;     // [esp+38h] [ebp-30h] BYREF
  float v25[3];  // [esp+3Ch] [ebp-2Ch] BYREF
  float v26;     // [esp+48h] [ebp-20h] BYREF
  float v27[7];  // [esp+4Ch] [ebp-1Ch] BYREF

  v4 = a3;
    if (g_waitingForKey) {
      if (!g_bindItem)
        return 0;
      if ((a3 & 0x400) != 0 || a3 == 96)
        return 1;
        switch (a3) {
        case 127:
          dvar = (char *)a2->dvar;
          v16 = 0;
          v17 = (char **)&g_bindings;
            while (I_stricmp(dvar, *v17)) {
              ++v16;
              v17 += 5;
              if (v16 == 56)
                goto LABEL_47;
            }
            if (v16 == -1) {
            LABEL_47:
              v4 = 127;
              goto LABEL_12;
            }
          v4 = -1;
          break;
        case 27:
        LABEL_34:
          g_waitingForKey = 0;
          return 1;
        case -1:
          break;
        default:
        LABEL_12:
          v6 = (char *)&g_bindings;
            while (1) {
                if (*((_DWORD *)v6 + 4) == v4) {
                  *((_DWORD *)v6 + 4) = -1;
                  if (*((_DWORD *)v6 + 3) == v4)
                    goto LABEL_17;
                LABEL_14:
                  v6 += 20;
                  if (v6 == &updateScreenCalled)
                    goto LABEL_18;
                }
                else {
                  if (*((_DWORD *)v6 + 3) != v4)
                    goto LABEL_14;
                LABEL_17:
                  *((_DWORD *)v6 + 3) = *((_DWORD *)v6 + 4);
                  *((_DWORD *)v6 + 4) = -1;
                  v6 += 20;
                  if (v6 == &updateScreenCalled)
                    goto LABEL_18;
                }
            }
        }
    LABEL_18:
      v21 = a2->dvar;
      v7 = 0;
      v8 = (char **)&g_bindings;
        for (i = (char *)v21; I_stricmp(i, *v8); i = (char *)v21) {
          ++v7;
          v8 += 5;
          if (v7 == 56)
            goto LABEL_28;
        }
        if (v7 != -1) {
            if (v4 == -1) {
              v18 = dword_3121AC[5 * v7];
                if (v18 != -1) {
                  Key_SetBinding(v18, (char *)&inData);
                  dword_3121AC[5 * v7] = -1;
                }
              v19 = dword_3121B0[5 * v7];
                if (v19 != -1) {
                  Key_SetBinding(v19, (char *)&inData);
                  dword_3121B0[5 * v7] = -1;
                }
            }
            else {
              v10 = dword_3121AC[5 * v7];
                if (v10 == -1) {
                  dword_3121AC[5 * v7] = v4;
                }
                else if (v10 != v4 && dword_3121B0[5 * v7] == -1) {
                  dword_3121B0[5 * v7] = v4;
                }
                else {
                  Key_SetBinding(v10, (char *)&inData);
                  Key_SetBinding(dword_3121B0[5 * v7], (char *)&inData);
                  dword_3121AC[5 * v7] = v4;
                  dword_3121B0[5 * v7] = -1;
                }
            }
        }
    LABEL_28:
      v11 = dword_3121AC;
        do {
            if (*v11 != -1) {
              Key_SetBinding(*v11, (char *)*(v11 - 3));
              v12 = v11[1];
              if (v12 != -1)
                Key_SetBinding(v12, (char *)*(v11 - 3));
            }
          v11 += 5;
        }
      while (&unk_31260C != (_UNKNOWN *)v11);
      Cbuf_ExecuteText(2, "in_restart\n", v20);
      goto LABEL_34;
    }
  if (!a4)
    return 0;
    if (a3 != 13) {
      if (a3 != 200)
        return 0;
      cursory = (float)a1->cursory;
      cursorx = (float)a1->cursorx;
      v22 = *(float *)a2->window;
      v23 = *(float *)&a2->window[4];
      v24 = *(float *)&a2->window[8];
      v25[0] = *(float *)&a2->window[12];
      v27[0] = cursorx;
      v26 = cursory;
      CalcScreenX(v27, 4);
      CalcScreenY(&v26, 4);
      CalcScreenPlacement(&v22, &v23, &v24, v25, *(_DWORD *)&a2->window[16],
                          *(_DWORD *)&a2->window[20]);
      if (v27[0] < v22 || (float)(v22 + v24) < v27[0] || v26 < v23 ||
          (float)(v23 + v25[0]) < v26)
        return 0;
    }
  g_waitingForKey = 1;
  g_bindItem = a2;
  return 1;
}

void __cdecl Item_Bind_Paint(struct displayContextDef_s *dc,
                             struct itemDef_s *item)
{
  UNIMPLEMENTED();
}

void __cdecl Item_Slider_Paint(struct displayContextDef_s *dc,
                               struct itemDef_s *item)
{
  UNIMPLEMENTED();
}

void __cdecl Item_YesNo_Paint(struct displayContextDef_s *dc,
                              struct itemDef_s *item)
{
  UNIMPLEMENTED();
}

void __cdecl Item_TextField_Paint(struct displayContextDef_s *dc,
                                  struct itemDef_s *item)
{
  UNIMPLEMENTED();
}

int __cdecl Item_ListBox_HandleKey(struct displayContextDef_s *dc,
                                   struct itemDef_s *item, int key, int down,
                                   int force)
{
  itemDefData_t v5;    // edi
  float cursory;       // xmm1_4
  float cursorx;       // xmm0_4
  _BOOL4 v8;           // eax
  int v9;              // ebx
  int32_t v11;         // edx
  int v12;             // edx
  int v13;             // eax
  int v14;             // eax
  signed int realTime; // edx
  int v16;             // eax
  int32_t v17;         // ebx
  int32_t v18;         // [esp+24h] [ebp-44h]
  int v19;             // [esp+28h] [ebp-40h]
  int v20;             // [esp+2Ch] [ebp-3Ch]
  float v21;           // [esp+30h] [ebp-38h] BYREF
  float v22;           // [esp+34h] [ebp-34h] BYREF
  float v23;           // [esp+38h] [ebp-30h] BYREF
  float v24[3];        // [esp+3Ch] [ebp-2Ch] BYREF
  float v25;           // [esp+48h] [ebp-20h] BYREF
  float v26[7];        // [esp+4Ch] [ebp-1Ch] BYREF

  v5.listBox = Item_GetListBoxDef(a2).listBox;
  if (!v5.listBox)
    return 0;
  v18 = UI_FeederCount(*(float *)a2->special);
  cursory = (float)a1->cursory;
  cursorx = (float)a1->cursorx;
  v21 = *(float *)a2->window;
  v22 = *(float *)&a2->window[4];
  v23 = *(float *)&a2->window[8];
  v24[0] = *(float *)&a2->window[12];
  v26[0] = cursorx;
  v25 = cursory;
  CalcScreenX(v26, 4);
  CalcScreenY(&v25, 4);
  CalcScreenPlacement(&v21, &v22, &v23, v24, *(_DWORD *)&a2->window[16],
                      *(_DWORD *)&a2->window[20]);
  v8 = v26[0] >= v21 && (float)(v21 + v23) >= v26[0] && v25 >= v22 &&
       (float)(v22 + v24[0]) >= v25;
  v9 = *(_DWORD *)&a2->window[232];
  if (!a5 && (!v8 || (v9 & 2) == 0))
    return 0;
  UI_OverrideCursorPos(a2);
  v19 = Item_ListBox_MaxScroll(a2);
    if ((a2->window[230] & 0x20) != 0) {
      v20 =
          (int)(float)(*(float *)&a2->window[8] / *(float *)(v5.listBox + 52));
        if (a3 == 156) {
            if (!*(_DWORD *)(v5.listBox + 264)) {
              ListBox_SetCursorPos((listBoxDef_s *)v5.listBox,
                                   *(_DWORD *)(v5.listBox + 36) - 1);
              if (*(int *)(v5.listBox + 36) < 0)
                ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, 0);
              v12 = *(_DWORD *)(v5.listBox + 36);
                if (v12 < *(_DWORD *)v5.listBox) {
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                      *(_DWORD *)(v5.listBox + 36));
                  v12 = *(_DWORD *)(v5.listBox + 36);
                }
                if (*(_DWORD *)(v5.listBox + 36) >=
                    *(_DWORD *)v5.listBox + v20) {
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                      v12 - v20 + 1);
                  Item_SetCursorPos(a2, *(_DWORD *)(v5.listBox + 36));
                  goto LABEL_18;
                }
              goto LABEL_47;
            }
          goto LABEL_48;
        }
        if (a3 == 157) {
            if (!*(_DWORD *)(v5.listBox + 264)) {
              ListBox_SetCursorPos((listBoxDef_s *)v5.listBox,
                                   *(_DWORD *)(v5.listBox + 36) + 1);
              if (*(_DWORD *)(v5.listBox + 36) < *(_DWORD *)v5.listBox)
                ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                    *(_DWORD *)(v5.listBox + 36));
              if (v18 <= *(_DWORD *)(v5.listBox + 36))
                ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, v18 - 1);
            LABEL_15:
              if (*(_DWORD *)(v5.listBox + 36) >= *(_DWORD *)v5.listBox + v20)
                ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                    *(_DWORD *)(v5.listBox + 36) - v20 + 1);
            LABEL_17:
              Item_SetCursorPos(a2, *(_DWORD *)(v5.listBox + 36));
            LABEL_18:
              UI_FeederSelection(*(float *)a2->special,
                                 *(_DWORD *)a2->cursorPos);
              return 1;
            }
          ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                              *(_DWORD *)v5.listBox + 1);
            if (v18 <= *(_DWORD *)v5.listBox) {
              ListBox_SetStartPos((listBoxDef_s *)v5.listBox, v18 - 1);
              return 1;
            }
          return 1;
        }
      goto LABEL_23;
    }
  v20 = (int)(float)(*(float *)&a2->window[12] / *(float *)(v5.listBox + 56));
    if (a3 != 154 && a3 != 206) {
        if (a3 == 155 || a3 == 205) {
            if (!*(_DWORD *)(v5.listBox + 264)) {
              Item_SetCursorPos(a2, *(_DWORD *)a2->cursorPos + 1);
              if (*(_DWORD *)a2->cursorPos < *(_DWORD *)v5.listBox)
                ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                    *(_DWORD *)a2->cursorPos);
              if (v18 <= *(_DWORD *)a2->cursorPos)
                Item_SetCursorPos(a2, v18 - 1);
              if (*(int *)a2->cursorPos < 0)
                Item_SetCursorPos(a2, 0);
              if (*(_DWORD *)a2->cursorPos >= *(_DWORD *)v5.listBox + v20)
                ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                    *(_DWORD *)a2->cursorPos - v20 + 1);
              goto LABEL_18;
            }
          goto LABEL_60;
        }
    LABEL_23:
        if ((unsigned int)(a3 - 200) > 1) {
            if (a3 == 165) {
                if (!*(_DWORD *)(v5.listBox + 264)) {
                  Item_SetCursorPos(a2, 0);
                  ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, 0);
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox, 0);
                  goto LABEL_18;
                }
              goto LABEL_70;
            }
            if (a3 == 166) {
                if (!*(_DWORD *)(v5.listBox + 264)) {
                  Item_SetCursorPos(a2, v18 - 1);
                  ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, v18 - 1);
                  if (*(_DWORD *)a2->cursorPos >= *(_DWORD *)v5.listBox + v20)
                    ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                        *(_DWORD *)a2->cursorPos - v20 + 1);
                    if (*(int *)a2->cursorPos < 0) {
                      Item_SetCursorPos(a2, 0);
                      ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, 0);
                    }
                  goto LABEL_18;
                }
              goto LABEL_62;
            }
            if (a3 != 164) {
              if (a3 != 163)
                return 0;
                if (!*(_DWORD *)(v5.listBox + 264)) {
                  ListBox_SetCursorPos((listBoxDef_s *)v5.listBox,
                                       *(_DWORD *)(v5.listBox + 36) + v20);
                  if (*(_DWORD *)(v5.listBox + 36) < *(_DWORD *)v5.listBox)
                    ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                        *(_DWORD *)(v5.listBox + 36));
                  if (v18 <= *(_DWORD *)(v5.listBox + 36))
                    ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, v18 - 1);
                  if (*(int *)(v5.listBox + 36) < 0)
                    ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, 0);
                  goto LABEL_15;
                }
              goto LABEL_105;
            }
            if (!*(_DWORD *)(v5.listBox + 264)) {
              ListBox_SetCursorPos((listBoxDef_s *)v5.listBox,
                                   *(_DWORD *)(v5.listBox + 36) - v20);
              if (*(int *)(v5.listBox + 36) < 0)
                ListBox_SetCursorPos((listBoxDef_s *)v5.listBox, 0);
              v12 = *(_DWORD *)(v5.listBox + 36);
                if (v12 < *(_DWORD *)v5.listBox) {
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                      *(_DWORD *)(v5.listBox + 36));
                  v12 = *(_DWORD *)(v5.listBox + 36);
                }
                if (*(_DWORD *)(v5.listBox + 36) >=
                    *(_DWORD *)v5.listBox + v20) {
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox,
                                      v12 - v20 + 1);
                  v12 = *(_DWORD *)(v5.listBox + 36);
                }
            LABEL_47:
              Item_SetCursorPos(a2, v12);
              goto LABEL_18;
            }
          goto LABEL_104;
        }
        if ((v9 & 0x100) == 0) {
            if ((v9 & 0x200) == 0) {
                if ((v9 & 0x800) == 0) {
                    if ((v9 & 0x1000) == 0) {
                        if ((v9 & 0x400) == 0) {
                            if (*(float *)a2->special == 18.0) {
                              UI_OverrideCursorPos(a2);
                              UI_FeederSelection(*(float *)a2->special,
                                                 *(_DWORD *)a2->cursorPos);
                            }
                          realTime = a1->realTime;
                            if (realTime < lastListBoxClickTime &&
                                *(_DWORD *)(v5.listBox + 260) &&
                                *(_DWORD *)a2->cursorPos ==
                                    *(_DWORD *)(v5.listBox + 36)) {
                              if (ListBox_HasValidCursorPos(
                                      (const listBoxDef_s *)v5.listBox))
                                Item_RunScript(
                                    a1, a2, *(const char **)(v5.listBox + 260));
                              realTime = a1->realTime;
                            }
                          lastListBoxClickTime = realTime + 300;
                          v16 = *(_DWORD *)a2->cursorPos;
                            if (v16 != *(_DWORD *)(v5.listBox + 36)) {
                              if (v16 < 0)
                                Item_SetCursorPos(a2,
                                                  *(_DWORD *)(v5.listBox + 36));
                              v17 = *(_DWORD *)(v5.listBox + 36);
                              if (v17 >= UI_FeederCount(*(float *)a2->special))
                                goto LABEL_18;
                              goto LABEL_17;
                            }
                        }
                      return 1;
                    }
                LABEL_105:
                  v14 = *(_DWORD *)v5.listBox + v20;
                LABEL_61:
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox, v14);
                  if (v19 >= *(_DWORD *)v5.listBox)
                    return 1;
                LABEL_62:
                  ListBox_SetStartPos((listBoxDef_s *)v5.listBox, v19);
                  return 1;
                }
            LABEL_104:
              v13 = *(_DWORD *)v5.listBox - v20;
            LABEL_49:
              ListBox_SetStartPos((listBoxDef_s *)v5.listBox, v13);
              if (*(int *)v5.listBox >= 0)
                return 1;
            LABEL_70:
              ListBox_SetStartPos((listBoxDef_s *)v5.listBox, 0);
              return 1;
            }
        LABEL_60:
          v14 = *(_DWORD *)v5.listBox + 1;
          goto LABEL_61;
        }
    LABEL_48:
      v13 = *(_DWORD *)v5.listBox - 1;
      goto LABEL_49;
    }
  if (*(_DWORD *)(v5.listBox + 264))
    goto LABEL_48;
  Item_SetCursorPos(a2, *(_DWORD *)a2->cursorPos - 1);
  if (*(int *)a2->cursorPos < 0)
    Item_SetCursorPos(a2, 0);
  v11 = *(_DWORD *)a2->cursorPos;
    if (v11 < *(_DWORD *)v5.listBox) {
      ListBox_SetStartPos((listBoxDef_s *)v5.listBox, *(_DWORD *)a2->cursorPos);
      v11 = *(_DWORD *)a2->cursorPos;
    }
    if (*(_DWORD *)a2->cursorPos >= *(_DWORD *)v5.listBox + v20) {
      ListBox_SetStartPos((listBoxDef_s *)v5.listBox, v11 - v20 + 1);
      v11 = *(_DWORD *)a2->cursorPos;
    }
  UI_FeederSelection(*(float *)a2->special, v11);
  return 1;
}

int __cdecl Item_ListBox_ThumbPosition(struct itemDef_s *item)
{
  itemDefData_t v1; // esi
  int v2;           // eax
  float v3;         // xmm1_4
  float v5;         // xmm1_4

  v1.listBox = Item_GetListBoxDef(a1).listBox;
  if (!v1.listBox)
    return 0;
  v2 = Item_ListBox_MaxScroll(a1);
    if ((a1->window[230] & 0x20) != 0) {
      if (v2 <= 0)
        v3 = 0.0;
      else
        v3 = (float)((float)((float)(*(float *)&a1->window[8] - 32.0) - 2.0) -
                     16.0) /
             (float)v2;
      return (int)(float)((float)(v3 * (float)*(int *)v1.listBox) +
                          (float)((float)(*(float *)a1->window + 1.0) + 16.0));
    }
    else {
      if (v2 <= 0)
        v5 = 0.0;
      else
        v5 = (float)((float)((float)(*(float *)&a1->window[12] - 32.0) - 2.0) -
                     16.0) /
             (float)v2;
      return (
          int)(float)((float)(v5 * (float)*(int *)v1.listBox) +
                      (float)((float)(*(float *)&a1->window[4] + 1.0) + 16.0));
    }
}

void __cdecl Script_ExecNowOnDvarFloatValue(struct displayContextDef_s *dc,
                                            struct itemDef_s *item,
                                            char const **args)
{
  Script_ConditionalExecHandler(
      0, a3,
      (unsigned __int8(__cdecl *)(const gentity_s *,
                                  char *))Script_ExecIfFloatsEqual);
}

void __cdecl Script_ExecNowOnDvarIntValue(struct displayContextDef_s *dc,
                                          struct itemDef_s *item,
                                          char const **args)
{
  Script_ConditionalExecHandler(
      0, a3,
      (unsigned __int8(__cdecl *)(const gentity_s *,
                                  char *))Script_ExecIfIntsEqual);
}

void __cdecl Script_ExecNowOnDvarStringValue(struct displayContextDef_s *dc,
                                             struct itemDef_s *item,
                                             char const **args)
{
  Script_ConditionalExecHandler(
      0, a3,
      (unsigned __int8(__cdecl *)(const gentity_s *,
                                  char *))Script_ExecIfStringsEqual);
}

void __cdecl Script_ExecOnDvarFloatValue(struct displayContextDef_s *dc,
                                         struct itemDef_s *item,
                                         char const **args)
{
  Script_ConditionalExecHandler(
      2, a3,
      (unsigned __int8(__cdecl *)(const gentity_s *,
                                  char *))Script_ExecIfFloatsEqual);
}

void __cdecl Script_ExecOnDvarIntValue(struct displayContextDef_s *dc,
                                       struct itemDef_s *item,
                                       char const **args)
{
  Script_ConditionalExecHandler(
      2, a3,
      (unsigned __int8(__cdecl *)(const gentity_s *,
                                  char *))Script_ExecIfIntsEqual);
}

void __cdecl Script_ExecOnDvarStringValue(struct displayContextDef_s *dc,
                                          struct itemDef_s *item,
                                          char const **args)
{
  Script_ConditionalExecHandler(
      2, a3,
      (unsigned __int8(__cdecl *)(const gentity_s *,
                                  char *))Script_ExecIfStringsEqual);
}

void __cdecl Script_ExecNow(struct displayContextDef_s *dc,
                            struct itemDef_s *item, char const **args)
{
  char *v3;         // eax
  char v4;          // [esp+8h] [ebp-410h]
  char __dst[1032]; // [esp+10h] [ebp-408h] BYREF

    if (String_Parse(a3, __dst, 1024)) {
      v3 = va("%s\n", __dst);
      Cbuf_ExecuteText(0, v3, v4);
    }
}

void __cdecl Script_Exec(struct displayContextDef_s *dc, struct itemDef_s *item,
                         char const **args)
{
  char *v3;         // eax
  char v4;          // [esp+8h] [ebp-410h]
  char __dst[1032]; // [esp+10h] [ebp-408h] BYREF

    if (String_Parse(a3, __dst, 1024)) {
      v3 = va("%s\n", __dst);
      Cbuf_ExecuteText(2, v3, v4);
    }
}

void __cdecl Menu_ScrollFeeder(struct displayContextDef_s *, struct menuDef_t *,
                               int, int)
{
  UNIMPLEMENTED();
}

int __cdecl Item_ListBox_OverLB(struct itemDef_s *item, float x, float y)
{
  int v3;       // edi
  int v4;       // esi
  float v5;     // eax
  float v6;     // xmm0_4
  float v7;     // xmm1_4
  float v8;     // xmm0_4
  float v9;     // xmm1_4
  float v10;    // xmm2_4
  float v12;    // [esp+20h] [ebp-48h]
  float v13;    // [esp+24h] [ebp-44h]
  float v14;    // [esp+28h] [ebp-40h]
  float v15;    // [esp+2Ch] [ebp-3Ch]
  float v16;    // [esp+30h] [ebp-38h] BYREF
  float v17;    // [esp+34h] [ebp-34h] BYREF
  float v18;    // [esp+38h] [ebp-30h] BYREF
  float v19[3]; // [esp+3Ch] [ebp-2Ch] BYREF
  float v20;    // [esp+48h] [ebp-20h] BYREF
  float v21[7]; // [esp+4Ch] [ebp-1Ch] BYREF

  UI_FeederCount(*(float *)a1->special);
  if (!Item_GetListBoxDef(a1).listBox)
    return 0;
  v3 = *(_DWORD *)&a1->window[16];
  v4 = *(_DWORD *)&a1->window[20];
    if ((a1->window[230] & 0x20) == 0) {
      v13 = (float)(*(float *)a1->window + *(float *)&a1->window[8]) - 16.0;
      v5 = *(float *)&a1->window[4];
      v16 = v13;
      v17 = v5;
      v18 = 16.0;
      v19[0] = 16.0;
      v20 = a2;
      v21[0] = a3;
      CalcScreenX(&v20, 4);
      CalcScreenY(v21, 4);
      CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
      if (v20 >= v16 && (float)(v16 + v18) >= v20 && v21[0] >= v17 &&
          (float)(v17 + v19[0]) >= v21[0])
        return 256;
      v6 = (float)(*(float *)&a1->window[4] + *(float *)&a1->window[12]) - 16.0;
      v16 = v13;
      v17 = v6;
      v18 = 16.0;
      v19[0] = 16.0;
      v21[0] = a2;
      v20 = a3;
      CalcScreenX(v21, 4);
      CalcScreenY(&v20, 4);
      CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
      if (v21[0] >= v16 && (float)(v16 + v18) >= v21[0] && v20 >= v17 &&
          (float)(v17 + v19[0]) >= v20)
        return 512;
      v12 = (float)Item_ListBox_ThumbPosition(a1);
      v16 = v13;
      v17 = v12;
      v18 = 16.0;
      v19[0] = 16.0;
      v21[0] = a2;
      v20 = a3;
      CalcScreenX(v21, 4);
      CalcScreenY(&v20, 4);
      CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
      if (v21[0] >= v16 && (float)(v16 + v18) >= v21[0] && v20 >= v17 &&
          (float)(v17 + v19[0]) >= v20)
        return 1024;
      v7 = *(float *)&a1->window[4] + 16.0;
      v16 = v13;
      v17 = v7;
      v18 = 16.0;
      v19[0] = v12 - v7;
      v20 = a2;
      v21[0] = a3;
      CalcScreenX(&v20, 4);
      CalcScreenY(v21, 4);
      CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
      if (v20 >= v16 && (float)(v16 + v18) >= v20 && v21[0] >= v17 &&
          (float)(v17 + v19[0]) >= v21[0])
        return 2048;
      v8 = 16.0;
      v9 = (float)(*(float *)&a1->window[4] + *(float *)&a1->window[12]) - 16.0;
      v16 = v13;
      v10 = v12 + 16.0;
      goto LABEL_11;
    }
  v15 = (float)(*(float *)&a1->window[4] + *(float *)&a1->window[12]) - 16.0;
  v16 = *(float *)a1->window;
  v17 = v15;
  v18 = 16.0;
  v19[0] = 16.0;
  v21[0] = a2;
  v20 = a3;
  CalcScreenX(v21, 4);
  CalcScreenY(&v20, 4);
  CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
  if (v21[0] >= v16 && (float)(v16 + v18) >= v21[0] && v20 >= v17 &&
      (float)(v17 + v19[0]) >= v20)
    return 256;
  v16 = (float)(*(float *)a1->window + *(float *)&a1->window[8]) - 16.0;
  v17 = v15;
  v18 = 16.0;
  v19[0] = 16.0;
  v21[0] = a2;
  v20 = a3;
  CalcScreenX(v21, 4);
  CalcScreenY(&v20, 4);
  CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
  if (v21[0] >= v16 && (float)(v16 + v18) >= v21[0] && v20 >= v17 &&
      (float)(v17 + v19[0]) >= v20)
    return 512;
  v14 = (float)Item_ListBox_ThumbPosition(a1);
  v16 = v14;
  v17 = v15;
  v18 = 16.0;
  v19[0] = 16.0;
  v21[0] = a2;
  v20 = a3;
  CalcScreenX(v21, 4);
  CalcScreenY(&v20, 4);
  CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
  if (v21[0] >= v16 && (float)(v16 + v18) >= v21[0] && v20 >= v17 &&
      (float)(v17 + v19[0]) >= v20)
    return 1024;
  v16 = *(float *)a1->window + 16.0;
  v17 = v15;
  v18 = v14 - v16;
  v19[0] = 16.0;
  v20 = a2;
  v21[0] = a3;
  CalcScreenX(&v20, 4);
  CalcScreenY(v21, 4);
  CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
    if (v20 < v16 || (float)(v16 + v18) < v20 || v21[0] < v17 ||
        (float)(v17 + v19[0]) < v21[0]) {
      v9 = 16.0;
      v8 = (float)(*(float *)a1->window + *(float *)&a1->window[8]) - 16.0;
      v16 = v14 + 16.0;
      v10 = v15;
    LABEL_11:
      v17 = v10;
      v18 = v8;
      v19[0] = v9;
      v21[0] = a2;
      v20 = a3;
      CalcScreenX(v21, 4);
      CalcScreenY(&v20, 4);
      CalcScreenPlacement(&v16, &v17, &v18, v19, v3, v4);
      if (v21[0] >= v16 && (float)(v16 + v18) >= v21[0] && v20 >= v17 &&
          (float)(v17 + v19[0]) >= v20)
        return 4096;
      return 0;
    }
  return 2048;
}

int __cdecl Item_ListBox_ThumbDrawPosition(struct displayContextDef_s *dc,
                                           struct itemDef_s *item)
{
  int v3;          // ebx
  int32_t cursorx; // ecx

  if ((itemDef_s *)itemCapture != a2)
    return Item_ListBox_ThumbPosition(a2);
    if ((a2->window[230] & 0x20) != 0) {
      v3 = (int)(float)((float)((float)(*(float *)a2->window +
                                        *(float *)&a2->window[8]) -
                                32.0) -
                        1.0);
      cursorx = a1->cursorx;
      if (cursorx <
          (int)(float)((float)(*(float *)a2->window + 16.0) + 1.0) + 8)
        return Item_ListBox_ThumbPosition((itemDef_s *)itemCapture);
    }
    else {
      v3 = (int)(float)((float)((float)(*(float *)&a2->window[4] +
                                        *(float *)&a2->window[12]) -
                                32.0) -
                        1.0);
      cursorx = a1->cursory;
      if (cursorx <
          (int)(float)((float)(*(float *)&a2->window[4] + 16.0) + 1.0) + 8)
        return Item_ListBox_ThumbPosition((itemDef_s *)itemCapture);
    }
  if (cursorx <= v3 + 8)
    return cursorx - 8;
  return Item_ListBox_ThumbPosition((itemDef_s *)itemCapture);
}

void __cdecl Item_ListBox_Paint(struct displayContextDef_s *dc,
                                struct itemDef_s *item)
{
  UNIMPLEMENTED();
}

void __cdecl Item_ListBox_MouseEnter(struct itemDef_s *item, float x, float y)
{
  listBoxDef_s *result; // eax
  listBoxDef_s *v3;     // esi
  int v4;               // eax
  int v5;               // edi
  float v6;             // xmm1_4
  float v7;             // xmm0_4
  float v8;             // eax
  float v9;             // xmm1_4
  float v10;            // xmm0_4
  float v11;            // [esp+24h] [ebp-44h]
  int v12;              // [esp+28h] [ebp-40h]
  float v13;            // [esp+2Ch] [ebp-3Ch]
  float v14;            // [esp+30h] [ebp-38h] BYREF
  float v15;            // [esp+34h] [ebp-34h] BYREF
  float v16;            // [esp+38h] [ebp-30h] BYREF
  float v17[3];         // [esp+3Ch] [ebp-2Ch] BYREF
  float v18[8];         // [esp+48h] [ebp-20h] BYREF

  result = (listBoxDef_s *)Item_GetListBoxDef((itemDef_s *)a1).listBox;
  v3 = result;
    if (result) {
      Window_RemoveDynamicFlags(a1, 7936);
      v4 = Item_ListBox_OverLB((itemDef_s *)a1, *(float *)&a2,
                               *((float *)&a2 + 1));
      Window_AddDynamicFlags(a1, v4);
      result = *(listBoxDef_s **)&a1->rect[16];
      v12 = (int)result;
      v5 = *(_DWORD *)&a1->rect[20];
        if ((a1->staticFlags & 0x200000) != 0) {
            if ((*(_DWORD *)a1->dynamicFlags & 0x1F00) == 0 &&
                v3->elementStyle == 1) {
              v13 = *(float *)a1->rect;
              v8 = *(float *)&a1->rect[4];
              v9 = *(float *)&a1->rect[12] - 16.0;
              v10 = *(float *)&a1->rect[8] - (float)v3->drawPadding;
              v14 = *(float *)a1->rect;
              v15 = v8;
              v16 = v10;
              v17[0] = v9;
              *(_QWORD *)v18 = a2;
              CalcScreenX(v18, 4);
              CalcScreenY(&v18[1], 4);
              result = (listBoxDef_s *)CalcScreenPlacement(&v14, &v15, &v16,
                                                           v17, v12, v5);
                if (v18[0] >= v14 && (float)(v14 + v16) >= v18[0] &&
                    v18[1] >= v15 && (float)(v15 + v17[0]) >= v18[1]) {
                  ListBox_SetCursorPos(
                      v3, *(_DWORD *)v3->startPos +
                              (int)(float)((float)(*(float *)&a2 - v13) /
                                           *(float *)&v3->elementWidth));
                  result = *(listBoxDef_s **)v3->cursorPos;
                  if ((int)result >= *(_DWORD *)v3->endPos)
                    return ListBox_SetCursorPos(v3, *(_DWORD *)v3->endPos);
                }
            }
        }
        else if ((*(_DWORD *)a1->dynamicFlags & 0x1F00) == 0) {
          v11 = *(float *)&a1->rect[4];
          v6 = *(float *)&a1->rect[8] - 16.0;
          v7 = *(float *)&a1->rect[12] - (float)v3->drawPadding;
          v14 = *(float *)a1->rect;
          v15 = v11;
          v16 = v6;
          v17[0] = v7;
          *(_QWORD *)v18 = __PAIR64__(a2, HIDWORD(a2));
          CalcScreenX(&v18[1], 4);
          CalcScreenY(v18, 4);
          result = (listBoxDef_s *)CalcScreenPlacement(&v14, &v15, &v16, v17,
                                                       v12, v5);
            if (v18[1] >= v14 && (float)(v14 + v16) >= v18[1] &&
                v18[0] >= v15 && (float)(v15 + v17[0]) >= v18[0]) {
              ListBox_SetCursorPos(
                  v3,
                  *(_DWORD *)v3->startPos +
                      (int)(float)((float)((float)(*((float *)&a2 + 1) - 2.0) -
                                           v11) /
                                   *(float *)&v3->elementHeight));
              result = *(listBoxDef_s **)v3->cursorPos;
              if ((int)result > *(_DWORD *)v3->endPos)
                return ListBox_SetCursorPos(v3, *(_DWORD *)v3->endPos);
            }
        }
    }
  return result;
}

int __cdecl Item_HandleKey(struct displayContextDef_s *dc,
                           struct itemDef_s *item, int key, int down)
{
  int result;                // eax
  int32_t type;              // eax
  float v6;                  // xmm1_4
  int v7;                    // ebx
  int v8;                    // eax
  int v9;                    // eax
  int Var;                   // edi
  int v11;                   // ebx
  int v12;                   // eax
  int v13;                   // edx
  char *v14;                 // eax
  int v15;                   // eax
  itemDefData_t v16;         // eax
  itemDefData_t v17;         // ebx
  itemDefData_t v18;         // eax
  int v19;                   // edx
  int v20;                   // edx
  unsigned int v21;          // eax
  int v22;                   // edx
  int v23;                   // eax
  unsigned int v24;          // xmm1_4
  unsigned int v25;          // xmm0_4
  unsigned int v26;          // xmm1_4
  unsigned int v27;          // xmm0_4
  const char *VariantString; // eax
  float v29;                 // xmm1_4
  int v30;                   // edx
  itemDefData_t v31;         // eax
  float v32;                 // xmm0_4
  itemDefData_t v33;         // edi
  float v34;                 // [esp+2Ch] [ebp-6Ch]
  __int64 v35;               // [esp+3Ch] [ebp-5Ch]
  itemDefData_t v36;         // [esp+44h] [ebp-54h]
  char *v37;                 // [esp+50h] [ebp-48h]
  char *v38;                 // [esp+54h] [ebp-44h]
  int v39;                   // [esp+58h] [ebp-40h]
  int v40;                   // [esp+5Ch] [ebp-3Ch]
  float v41;                 // [esp+60h] [ebp-38h] BYREF
  float v42;                 // [esp+64h] [ebp-34h] BYREF
  float v43;                 // [esp+68h] [ebp-30h] BYREF
  float v44[3];              // [esp+6Ch] [ebp-2Ch] BYREF
  float v45[8];              // [esp+78h] [ebp-20h] BYREF

    if (itemCapture) {
      itemCapture = 0;
      captureFunc = 0;
      captureData = 0;
      goto LABEL_3;
    }
  if (!a4)
    return 0;
    if ((unsigned int)(a3 - 200) <= 2) {
      type = a2->type;
        if (type == 6) {
          v21 = Item_ListBox_OverLB(a2, (float)a1->cursorx, (float)a1->cursory);
            if ((v21 & 0x300) != 0) {
              scrollInfo = a1->realTime + 500;
              dword_F00724 = a1->realTime + 150;
              dword_F00728 = 500;
              dword_F0072C = a3;
              dword_F0073C = (v21 >> 8) & 1;
              dword_F00738 = (int)a2;
              captureData = (int)&scrollInfo;
              captureFunc = (int)Scroll_ListBox_AutoFunc;
              itemCapture = (int)a2;
            }
            else if ((v21 & 0x400) != 0) {
              dword_F0072C = a3;
              dword_F00738 = (int)a2;
              *(float *)&dword_F00730 = (float)a1->cursorx;
              *(float *)&dword_F00734 = (float)a1->cursory;
              captureData = (int)&scrollInfo;
              captureFunc = (int)Scroll_ListBox_ThumbFunc;
              itemCapture = (int)a2;
            }
        }
        else {
            if (type != 10) {
            LABEL_3:
              if (a4)
                goto LABEL_6;
              return 0;
            }
          *(float *)&v35 = (float)a1->cursory;
          *((float *)&v35 + 1) = (float)a1->cursorx;
          v34 = Item_Slider_ThumbPosition(a2);
          v6 = *(float *)&a2->window[4] - 2.0;
          v39 = *(_DWORD *)&a2->window[16];
          v7 = *(_DWORD *)&a2->window[20];
          v41 = v34 - 5.0;
          v42 = v6;
          v43 = 10.0;
          v44[0] = 20.0;
          *(_QWORD *)v45 = v35;
          CalcScreenX(&v45[1], 4);
          CalcScreenY(v45, 4);
          CalcScreenPlacement(&v41, &v42, &v43, v44, v39, v7);
          if (v45[1] < v41 || (float)(v41 + v43) < v45[1] || v45[0] < v42 ||
              (float)(v42 + v44[0]) < v45[0])
            v8 = 0;
          else
            v8 = 1024;
            if (v8) {
              dword_F0072C = a3;
              dword_F00738 = (int)a2;
              *(float *)&dword_F00730 = (float)a1->cursorx;
              *(float *)&dword_F00734 = (float)a1->cursory;
              captureData = (int)&scrollInfo;
              captureFunc = (int)Scroll_Slider_ThumbFunc;
              itemCapture = (int)a2;
            }
        }
    }
LABEL_6:
    switch (a2->type) {
    case 6:
      return Item_ListBox_HandleKey(a1, a2, a3, a4, 0);
    case 8:
      return UI_OwnerDrawHandleKey(*(_DWORD *)&a2->window[216],
                                   *(_DWORD *)&a2->window[220],
                                   (float *)a2->special, a3);
    case 0xA:
      return Item_Slider_HandleKey(a1, a2, a3);
    case 0xB:
      return Item_YesNo_HandleKey(a1, a2, a3);
    case 0xC:
      v36.listBox = Item_GetMultiDef(a2).listBox;
      if (!v36.listBox)
        return 0;
      v15 = *(_DWORD *)&a2->window[232];
      if ((v15 & 4) == 0)
        return 0;
      if ((v15 & 2) == 0)
        return 0;
        if ((unsigned int)(a3 - 200) <= 2) {
          *(float *)&v26 = (float)a1->cursory;
          *(float *)&v27 = (float)a1->cursorx;
          v41 = *(float *)a2->window;
          v42 = *(float *)&a2->window[4];
          v43 = *(float *)&a2->window[8];
          v44[0] = *(float *)&a2->window[12];
          *(_QWORD *)v45 = __PAIR64__(v26, v27);
          CalcScreenX(v45, 4);
          CalcScreenY(&v45[1], 4);
          CalcScreenPlacement(&v41, &v42, &v43, v44, *(_DWORD *)&a2->window[16],
                              *(_DWORD *)&a2->window[20]);
          if (v45[0] < v41 || (float)(v41 + v43) < v45[0] || v45[1] < v42 ||
              (float)(v42 + v44[0]) < v45[1])
            return 0;
        }
      v16.listBox = Item_GetMultiDef(a2).listBox;
      v17.listBox = v16.listBox;
      if (!v16.listBox)
        goto LABEL_39;
        if (!*(_DWORD *)(v16.listBox + 388)) {
          VariantString = (const char *)Dvar_GetVariantString((char *)a2->dvar);
          v29 = atof(VariantString);
          v30 = *(_DWORD *)(v17.listBox + 384);
            if (v30 > 0 && v29 != *(float *)(v17.listBox + 256)) {
              v31.listBox = v17.listBox;
              v40 = 0;
                while (v30 != ++v40) {
                  v32 = *(float *)(v31.listBox + 260);
                  v31.listBox += 4;
                  if (v29 == v32)
                    goto LABEL_40;
                }
            }
        LABEL_39:
          v40 = 0;
          goto LABEL_40;
        }
      v37 = (char *)Dvar_GetVariantString((char *)a2->dvar);
      if (*(int *)(v17.listBox + 384) <= 0)
        goto LABEL_39;
      v33.listBox = v17.listBox;
      v40 = 0;
        while (I_stricmp(v37, *(char **)(v33.listBox + 128))) {
          ++v40;
          v33.listBox += 4;
          if (*(_DWORD *)(v17.listBox + 384) <= v40)
            goto LABEL_39;
        }
    LABEL_40:
      v18.listBox = Item_GetMultiDef(a2).listBox;
        if (v18.listBox && (v19 = *(_DWORD *)(v18.listBox + 384)) != 0) {
            if (a3 == 200 || a3 == 13 || a3 == 202 || a3 == 163 || a3 == 157) {
              v20 = (v40 + 1) % v19;
            }
            else {
              if (a3 != 201 && a3 != 164 && a3 != 156)
                return 0;
              v20 = (v40 + v19 - 1) % v19;
            }
        }
        else {
          v20 = 0;
        }
      if (v40 == v20)
        return 0;
      if (*(_DWORD *)(v36.listBox + 388))
        v14 = *(char **)(v36.listBox + 4 * v20 + 128);
      else
        v14 = va("%g", *(float *)(v36.listBox + 4 * v20 + 256));
    LABEL_54:
      Dvar_SetFromStringByName((dvar_s *)a2->dvar, (DvarValue)v14);
      result = 1;
      break;
    case 0xD:
      v9 = *(_DWORD *)&a2->window[232];
      if ((v9 & 4) == 0)
        return 0;
      if ((v9 & 2) == 0)
        return 0;
        if ((unsigned int)(a3 - 200) <= 2) {
          *(float *)&v24 = (float)a1->cursory;
          *(float *)&v25 = (float)a1->cursorx;
          v41 = *(float *)a2->window;
          v42 = *(float *)&a2->window[4];
          v43 = *(float *)&a2->window[8];
          v44[0] = *(float *)&a2->window[12];
          *(_QWORD *)v45 = __PAIR64__(v24, v25);
          CalcScreenX(v45, 4);
          CalcScreenY(&v45[1], 4);
          CalcScreenPlacement(&v41, &v42, &v43, v44, *(_DWORD *)&a2->window[16],
                              *(_DWORD *)&a2->window[20]);
          if (v45[0] < v41 || (float)(v41 + v43) < v45[0] || v45[1] < v42 ||
              (float)(v42 + v44[0]) < v45[1])
            return 0;
        }
      Var = Dvar_FindVar((char *)a2->typeData.listBox);
      if (*(_BYTE *)(Var + 6) != 6)
        goto LABEL_27;
      v38 = (char *)Dvar_GetVariantString((char *)a2->dvar);
      v23 = atoi(v38);
      v11 = v23;
      if (v23 >= 0 && v23 < *(_DWORD *)(Var + 20))
        goto LABEL_28;
      if (*(int *)(Var + 20) <= 0)
        goto LABEL_27;
      v11 = 0;
        while (I_stricmp(v38, *(char **)(*(_DWORD *)(Var + 24) + 4 * v11))) {
            if (++v11 >= *(_DWORD *)(Var + 20)) {
            LABEL_27:
              v11 = 0;
              break;
            }
        }
    LABEL_28:
      v12 = Dvar_FindVar((char *)a2->typeData.listBox);
        if (*(_BYTE *)(v12 + 6) == 6 && (v22 = *(_DWORD *)(v12 + 20)) != 0) {
            if (a3 == 200 || a3 == 13 || a3 == 202 || a3 == 163 || a3 == 157) {
              v13 = (v11 + 1) % v22;
            }
            else {
              if (a3 != 201 && a3 != 164 && a3 != 156)
                return 0;
              v13 = (v11 + v22 - 1) % v22;
            }
        }
        else {
          v13 = 0;
        }
      if (v11 == v13)
        return 0;
      v14 = va("%i", v13);
      goto LABEL_54;
    case 0xE:
      return Item_Bind_HandleKey(a1, a2, a3, a4);
    default:
      return 0;
    }
  return result;
}

void __cdecl Menu_HandleKey(struct displayContextDef_s *dc,
                            struct menuDef_t *menu, int key, int down)
{
  signed int itemCount; // edi
  int i;                // ecx
  itemDef_s *v6;        // edx
  int v7;               // eax
  itemDef_s *v8;        // edx
  float cursory;        // xmm1_4
  float cursorx;        // xmm0_4
  float v11;            // xmm2_4
  float v12;            // xmm1_4
  float v13;            // xmm0_4
  float v14;            // xmm1_4
  float v15;            // xmm0_4
  itemDefData_t v16;    // eax
  char v17;             // [esp+8h] [ebp-340h]
  itemDef_s *v18;       // [esp+2Ch] [ebp-31Ch]
  itemDef_s v19;        // [esp+34h] [ebp-314h] BYREF
  float v20;            // [esp+328h] [ebp-20h] BYREF
  float v21[7];         // [esp+32Ch] [ebp-1Ch] BYREF

    if (g_waitingForKey && a4) {
      Item_Bind_HandleKey(a1, g_bindItem, a3, a4);
      return;
    }
    if (g_editingField && a4) {
        if (!Item_TextField_HandleKey(a1, g_editItem, a3)) {
          g_editingField = 0;
          g_editItem = 0;
          return;
        }
      if ((unsigned int)(a3 - 200) > 2)
        return;
      g_editingField = 0;
      g_editItem = 0;
      Display_MouseMove(a1, 0, a1->cursorx, a1->cursory);
    }
  if (!a2)
    return;
    if (a4) {
        if ((a2->window.staticFlags & 0x1000000) == 0 && !a2->fullScreen) {
          cursory = (float)a1->cursory;
          cursorx = (float)a1->cursorx;
          *(_DWORD *)v19.window = *(_DWORD *)a2->window.rect;
          *(_DWORD *)&v19.window[4] = *(_DWORD *)&a2->window.rect[4];
          *(_DWORD *)&v19.window[8] = *(_DWORD *)&a2->window.rect[8];
          *(_DWORD *)&v19.window[12] = *(_DWORD *)&a2->window.rect[12];
          v21[0] = cursorx;
          v20 = cursory;
          CalcScreenX(v21, 4);
          CalcScreenY(&v20, 4);
          CalcScreenPlacement((float *)v19.window, (float *)&v19.window[4],
                              (float *)&v19.window[8], (float *)&v19.window[12],
                              *(_DWORD *)&a2->window.rect[16],
                              *(_DWORD *)&a2->window.rect[20]);
            if ((v21[0] < *(float *)v19.window ||
                 (float)(*(float *)v19.window + *(float *)&v19.window[8]) <
                     v21[0] ||
                 v20 < *(float *)&v19.window[4] ||
                 (float)(*(float *)&v19.window[4] + *(float *)&v19.window[12]) <
                     v20) &&
                !Menu_HandleKey(displayContextDef_s *, menuDef_t *, int,
                                int)::inHandleKey &&
                (unsigned int)(a3 - 200) <= 2) {
              Menu_HandleKey(displayContextDef_s *, menuDef_t *, int,
                             int)::inHandleKey = 1;
              Menus_HandleOOBClick(a1, a2, a3, a4);
              Menu_HandleKey(displayContextDef_s *, menuDef_t *, int,
                             int)::inHandleKey = 0;
              return;
            }
        }
    }
  itemCount = a2->itemCount;
    if (itemCount <= 0) {
      v18 = 0;
      if ((unsigned int)(a3 - 205) > 1)
        goto LABEL_14;
    }
    else {
      v18 = 0;
        for (i = 0; i != itemCount; ++i) {
          v6 = *(itemDef_s **)(a2->items + 4 * i);
          v7 = *(_DWORD *)&v6->window[232];
            if ((v7 & 4) != 0) {
              if ((v7 & 2) == 0)
                v6 = v18;
              v18 = v6;
            }
        }
        if ((unsigned int)(a3 - 205) > 1) {
        LABEL_14:
          if (!v18)
            goto LABEL_32;
          goto LABEL_15;
        }
    }
  if (!v18 || v18->type != 6)
    return;
LABEL_15:
  if (Item_HandleKey(a1, v18, a3, a4))
    goto LABEL_16;
LABEL_32:
  if (!a4 || (unsigned int)(a3 - 1) <= 0xFE && Menu_CheckOnKey(a1, a2, a3))
    return;
    if (a3 == 177) {
      if (Dvar_GetInt("developer"))
        debugMode ^= 1u;
      return;
    }
    if (a3 > 177) {
        if (a3 <= 201) {
            if (a3 >= 200) {
              if (!v18)
                return;
                if (!v18->type) {
                  v11 = (float)a1->cursory;
                  v12 = (float)a1->cursorx;
                  memset(&Item_CorrectedTextRect(itemDef_s *)::rect, 0, 0x18u);
                  Item_CorrectedTextRect(itemDef_s *)::rect =
                      *(float *)v18->textRect;
                  dword_F00748 = *(_DWORD *)&v18->textRect[4];
                  flt_F0074C = *(float *)&v18->textRect[8];
                  flt_F00750 = *(float *)&v18->textRect[12];
                  dword_F00754 = *(_DWORD *)&v18->textRect[16];
                  dword_F00758 = *(_DWORD *)&v18->textRect[20];
                    if (flt_F0074C == 0.0) {
                      v13 = *(float *)&dword_F00748;
                    }
                    else {
                      v13 = *(float *)&dword_F00748 - flt_F00750;
                      *(float *)&dword_F00748 =
                          *(float *)&dword_F00748 - flt_F00750;
                    }
                  *(float *)v19.window =
                      Item_CorrectedTextRect(itemDef_s *)::rect;
                  *(float *)&v19.window[4] = v13;
                  *(float *)&v19.window[8] = flt_F0074C;
                  *(float *)&v19.window[12] = flt_F00750;
                  v20 = v12;
                  v21[0] = v11;
                  CalcScreenX(&v20, 4);
                  CalcScreenY(v21, 4);
                  CalcScreenPlacement(
                      (float *)v19.window, (float *)&v19.window[4],
                      (float *)&v19.window[8], (float *)&v19.window[12],
                      dword_F00754, dword_F00758);
                    if (v20 >= *(float *)v19.window &&
                        (float)(*(float *)v19.window +
                                *(float *)&v19.window[8]) >= v20 &&
                        v21[0] >= *(float *)&v19.window[4] &&
                        (float)(*(float *)&v19.window[4] +
                                *(float *)&v19.window[12]) >= v21[0]) {
                      goto LABEL_16;
                    }
                  return;
                }
              v14 = (float)a1->cursory;
              v15 = (float)a1->cursorx;
              *(_DWORD *)v19.window = *(_DWORD *)v18->window;
              *(_DWORD *)&v19.window[4] = *(_DWORD *)&v18->window[4];
              *(_DWORD *)&v19.window[8] = *(_DWORD *)&v18->window[8];
              *(_DWORD *)&v19.window[12] = *(_DWORD *)&v18->window[12];
              v20 = v15;
              v21[0] = v14;
              CalcScreenX(&v20, 4);
              CalcScreenY(v21, 4);
              CalcScreenPlacement(
                  (float *)v19.window, (float *)&v19.window[4],
                  (float *)&v19.window[8], (float *)&v19.window[12],
                  *(_DWORD *)&v18->window[16], *(_DWORD *)&v18->window[20]);
                if (v20 < *(float *)v19.window ||
                    (float)(*(float *)v19.window + *(float *)&v19.window[8]) <
                        v20 ||
                    v21[0] < *(float *)&v19.window[4] ||
                    (float)(*(float *)&v19.window[4] +
                            *(float *)&v19.window[12]) < v21[0]) {
                  return;
                }
              if (v18->type > 0x12u || ((1 << v18->type) & 0x70210) == 0)
                goto LABEL_16;
              v16.listBox = Item_GetEditFieldDef(v18).listBox;
              if (v16.listBox)
                *(_DWORD *)(v16.listBox + 28) = 0;
            LABEL_54:
              Item_SetCursorPos(v18, 0);
              g_editingField = 1;
              g_editItem = v18;
              Key_SetOverstrikeMode(1);
              return;
            }
            if (a3 == 178) {
              if (Dvar_GetInt("developer"))
                Cbuf_ExecuteText(2, "screenshot\n", v17);
              return;
            }
          if (a3 != 191)
            return;
        LABEL_51:
          if (!v18)
            return;
            if (v18->type > 0x12u) {
              v8 = v18;
              goto LABEL_17;
            }
            if (((1 << v18->type) & 0x70210) == 0) {
            LABEL_16:
              v8 = v18;
            LABEL_17:
              Item_RunScript(a1, v8, (const char *)v8->action);
              return;
            }
          goto LABEL_54;
        }
      if (a3 == 205)
        goto LABEL_41;
        if (a3 != 206) {
          if (a3 != 202)
            return;
          goto LABEL_51;
        }
    LABEL_69:
      Menu_SetPrevCursorItem(a1, a2);
      return;
    }
  if (a3 == 154)
    goto LABEL_69;
    if (a3 > 154) {
        if (a3 != 156) {
          if (a3 >= 156 && a3 != 157)
            return;
        LABEL_41:
          Menu_SetNextCursorItem(a1, a2);
          return;
        }
      goto LABEL_69;
    }
  if (a3 == 13)
    goto LABEL_51;
    if (a3 != 27) {
      if (a3 != 9)
        return;
      goto LABEL_41;
    }
    if (!g_waitingForKey) {
        if (a2->onESC) {
          v19.parent = (int32_t)a2;
          Item_RunScript(a1, &v19, (const char *)a2->onESC);
        }
    }
}

void __cdecl Item_RunScript(struct displayContextDef_s *dc,
                            struct itemDef_s *item, char const *s)
{
  UNIMPLEMENTED();
}

void __cdecl Menus_Open(struct displayContextDef_s *dc, struct menuDef_t *menu)
{
  uint32_t openMenuCount;   // edi
  windowDef_t **v3;         // ebx
  int v4;                   // esi
  signed int v5;            // ebx
  uint8_t *v6;              // ecx
  signed int v7;            // esi
  int v8;                   // edx
  menuDef_t *v9;            // eax
  displayContextDef_s *v10; // edx
  displayContextDef_s *v11; // ecx
  uint32_t v12;             // eax
  uint32_t v13;             // ecx
  uint8_t *i;               // ecx
  _DWORD *v15;              // esi
  int j;                    // edi
  int v17;                  // eax
  int v18;                  // eax
  int v19;                  // edi
  int v20;                  // eax
  int v21;                  // ebx
  uint8_t *v23;             // edx
  signed int v24;           // ecx
  char v25;                 // [esp+8h] [ebp-330h]
  uint32_t v26;             // [esp+10h] [ebp-328h]
  int v27;                  // [esp+14h] [ebp-324h]
  int v28;                  // [esp+18h] [ebp-320h]
  uint8_t *v29;             // [esp+1Ch] [ebp-31Ch]
  itemDef_s v30;            // [esp+2Ch] [ebp-30Ch] BYREF

  openMenuCount = a1->openMenuCount;
    if ((int)(openMenuCount - 1) >= 0) {
      v3 = (windowDef_t **)&a1->Menus[4 * openMenuCount + 512];
      v4 = 0;
        do {
          Window_RemoveDynamicFlags(*v3, 2);
          ++v4;
          --v3;
        }
      while (v4 != openMenuCount);
      openMenuCount = a1->openMenuCount;
    }
  v5 = openMenuCount - 1;
    if ((int)(openMenuCount - 1) >= 0) {
        if (a2 == *(menuDef_t **)&a1->menuStack[4 * v5]) {
          a1->openMenuCount = v5;
        }
        else {
          v6 = &a1->menuStack[4 * v5];
          v7 = openMenuCount - 1;
          v8 = 0;
            while (1) {
              --v7;
              if (v8 == v5)
                break;
              v9 = (menuDef_t *)*((_DWORD *)v6 - 1);
              ++v8;
              v6 -= 4;
                if (a2 == v9) {
                  a1->openMenuCount = v5;
                  if (v5 <= v7)
                    break;
                  v23 = &a1->menuStack[4 * v7 + 4];
                  v24 = v7;
                    do {
                      ++v24;
                      *(_DWORD *)&v23[4 * v7 + 560 - (4 * v7 + 564)] =
                          *(_DWORD *)v23;
                      v23 += 4;
                    }
                  while ((signed int)a1->openMenuCount > v24);
                  v10 = a1;
                  if (a1->openMenuCount != 16)
                    goto LABEL_12;
                  goto LABEL_40;
                }
            }
        }
    }
  v10 = a1;
    if (a1->openMenuCount == 16) {
    LABEL_40:
      Com_Error(1, "\x15Too many menus opened", v25);
      v11 = a1;
    }
    else {
    LABEL_12:
      v11 = v10;
    }
  v12 = v11->openMenuCount;
  *(_DWORD *)&v11->menuStack[4 * v12] = a2;
  v11->openMenuCount = v12 + 1;
  Window_AddDynamicFlags(&a2->window, 6);
    if (a2->onOpen) {
      v30.parent = (int32_t)a2;
      Item_RunScript(a1, &v30, (const char *)a2->onOpen);
    }
  if (*(_DWORD *)a2->soundName)
    UI_PlayLocalSoundAliasByName(*(char **)a2->soundName);
  v13 = a1->openMenuCount;
  v26 = v13;
    if ((int)(v13 - 1) >= 0) {
      v29 = &a1->Menus[4 * v13 + 512];
      v28 = 0;
        for (i = v29;; i = v29) {
          v15 = *(_DWORD **)i;
            if (*(_DWORD *)i) {
                if (v15[52] == 5 && (int)v15[51] >= 0) {
                  CIN_StopCinematic(v15[51]);
                  v15[51] = -1;
                }
              if ((int)v15[134] > 0)
                break;
            }
        LABEL_31:
          ++v28;
          v29 -= 4;
          if (v28 == v26)
            return Display_MouseMove(a1, 0, a1->cursorx, a1->cursory);
        }
      v27 = 0;
        for (j = 0;; j = v18) {
          v19 = 4 * j;
          v20 = v15[159];
          v21 = *(_DWORD *)(v20 + v19);
          if (*(_DWORD *)(v21 + 208) != 5)
            break;
            if (*(int *)(v21 + 204) < 0) {
              v17 = *(_DWORD *)(v20 + v19);
            LABEL_24:
              if (*(_DWORD *)(v17 + 624) != 8)
                goto LABEL_25;
              goto LABEL_30;
            }
          CIN_StopCinematic(*(_DWORD *)(v21 + 204));
          *(_DWORD *)(v21 + 204) = -1;
          v17 = *(_DWORD *)(v15[159] + v19);
            if (*(_DWORD *)(v17 + 624) != 8) {
            LABEL_25:
              v18 = ++v27;
              if (v27 >= v15[134])
                goto LABEL_31;
              continue;
            }
        LABEL_30:
          CIN_StopCinematic(-*(_DWORD *)(v17 + 216));
          v18 = ++v27;
          if (v27 >= v15[134])
            goto LABEL_31;
        }
      v17 = *(_DWORD *)(v20 + v19);
      goto LABEL_24;
    }
  return Display_MouseMove(a1, 0, a1->cursorx, a1->cursory);
}

void __cdecl Item_MouseLeave(struct displayContextDef_s *dc,
                             struct itemDef_s *item)
{
  int result; // eax

    if (a2) {
        if ((a2->dynamicFlags[0] & 0x40) != 0) {
          Item_RunScript(a1, (itemDef_s *)a2,
                         *(const char **)&a2[1].rectClient[52]);
          Window_RemoveDynamicFlags(a2, 64);
        }
      Item_RunScript(a1, (itemDef_s *)a2,
                     *(const char **)&a2[1].rectClient[60]);
      return Window_RemoveDynamicFlags(a2, 768);
    }
  return result;
}

void __cdecl Item_MouseEnter(struct displayContextDef_s *dc,
                             struct itemDef_s *item, float x, float y)
{
  float v3;           // edi
  uint32_t dvarFlags; // eax
  int v5;             // esi
  float v6;           // [esp+2Ch] [ebp-4Ch]
  int v7;             // [esp+30h] [ebp-48h]
  int v8;             // [esp+34h] [ebp-44h]
  float v9;           // [esp+38h] [ebp-40h]
  float v10;          // [esp+3Ch] [ebp-3Ch]
  float v11;          // [esp+40h] [ebp-38h] BYREF
  float v12;          // [esp+44h] [ebp-34h] BYREF
  float v13;          // [esp+48h] [ebp-30h] BYREF
  float v14[3];       // [esp+4Ch] [ebp-2Ch] BYREF
  float v15;          // [esp+58h] [ebp-20h] BYREF
  float v16[7];       // [esp+5Ch] [ebp-1Ch] BYREF

    if (a2) {
      v6 = *(float *)&a2->textRect[8];
      v3 = *(float *)a2->textRect;
      v7 = *(_DWORD *)&a2->textRect[20];
      v8 = *(_DWORD *)&a2->textRect[16];
      v9 = *(float *)&a2->textRect[12];
      v10 = *(float *)&a2->textRect[4] - v9;
      dvarFlags = a2->dvarFlags;
        if ((dvarFlags & 3) != 0) {
          if (!Item_EnableShowViaDvar(a2, 1))
            return;
          dvarFlags = a2->dvarFlags;
        }
        if ((dvarFlags & 0xC) == 0 || Item_EnableShowViaDvar(a2, 4)) {
          v5 = *(_DWORD *)&a2->window[232];
          v11 = v3;
          v12 = v10;
          v13 = v6;
          v14[0] = v9;
          v15 = *((float *)&a3 + 1);
          v16[0] = *(float *)&a3;
          CalcScreenX(v16, 4);
          CalcScreenY(&v15, 4);
          CalcScreenPlacement(&v11, &v12, &v13, v14, v8, v7);
            if (v16[0] >= v11 && (float)(v11 + v13) >= v16[0] && v15 >= v12 &&
                (float)(v12 + v14[0]) >= v15) {
                if ((v5 & 0x40) == 0) {
                  Item_RunScript(a1, a2, *(const char **)a2->mouseEnterText);
                  Window_AddDynamicFlags((windowDef_t *)a2, 64);
                }
                if ((v5 & 1) == 0) {
                  Item_RunScript(a1, a2, (const char *)a2->mouseEnter);
                  Window_AddDynamicFlags((windowDef_t *)a2, 1);
                }
              return;
            }
            if ((v5 & 0x40) != 0) {
              Item_RunScript(a1, a2, *(const char **)a2->mouseExitText);
              Window_RemoveDynamicFlags((windowDef_t *)a2, 64);
                if ((v5 & 1) != 0) {
                LABEL_7:
                  if (a2->type != 6)
                    return;
                  goto LABEL_22;
                }
            }
            else if ((v5 & 1) != 0) {
              goto LABEL_7;
            }
          Item_RunScript(a1, a2, (const char *)a2->mouseEnter);
          Window_AddDynamicFlags((windowDef_t *)a2, 1);
          if (a2->type != 6)
            return;
        LABEL_22:
          Item_ListBox_MouseEnter((windowDef_t *)a2, a3);
        }
    }
}

int __cdecl Menus_OpenByName(struct displayContextDef_s *dc, char const *p)
{
  displayContextDef_s *v3; // ebx
  signed int v4;           // esi

  if ((int)a1->menuCount <= 0)
    return 0;
  v3 = a1;
  v4 = 0;
    while (I_stricmp(*(char **)(*(_DWORD *)v3->Menus + 192), a2)) {
      ++v4;
      v3 = (displayContextDef_s *)((char *)v3 + 4);
      if (v4 >= (signed int)a1->menuCount)
        return 0;
    }
  if (!*(_DWORD *)&a1->Menus[4 * v4])
    return 0;
  Menus_Open(a1, *(menuDef_t **)&a1->Menus[4 * v4]);
  return 1;
}

void __cdecl Script_InGameOpen(struct displayContextDef_s *dc,
                               struct itemDef_s *item, char const **args)
{
  int result;              // eax
  displayContextDef_s *v4; // ebx
  signed int v5;           // esi
  char __dst[1048];        // [esp+10h] [ebp-418h] BYREF

  result = String_Parse(a3, __dst, 1024);
    if (result) {
      result = UI_ClientIsInGame();
        if (result) {
            if ((int)a1->menuCount > 0) {
              v4 = a1;
              v5 = 0;
                while (1) {
                  result =
                      I_stricmp(*(char **)(*(_DWORD *)v4->Menus + 192), __dst);
                  if (!result)
                    break;
                  ++v5;
                  v4 = (displayContextDef_s *)((char *)v4 + 4);
                  if (v5 >= (signed int)a1->menuCount)
                    return result;
                }
              result = *(_DWORD *)&a1->Menus[4 * v5];
              if (result)
                return Menus_Open(a1, *(menuDef_t **)&a1->Menus[4 * v5]);
            }
        }
    }
  return result;
}

void __cdecl Script_OpenForGameType(struct displayContextDef_s *dc,
                                    struct itemDef_s *item, char const **args)
{
  displayContextDef_s *result; // eax
  const gentity_s *String;     // eax
  char *v5;                    // edi
  displayContextDef_s *v6;     // ebx
  signed int v7;               // esi
  char __format[1048];         // [esp+10h] [ebp-418h] BYREF

  result = (displayContextDef_s *)String_Parse(a3, __format, 1024);
    if (result) {
      String = Dvar_GetString((char *)a2->dvar);
      v5 = va(__format, String);
      result = a1;
        if ((int)a1->menuCount > 0) {
          v6 = a1;
          v7 = 0;
            while (I_stricmp(*(char **)(*(_DWORD *)v6->Menus + 192), v5)) {
              ++v7;
              v6 = (displayContextDef_s *)((char *)v6 + 4);
              result = a1;
              if (v7 >= (signed int)a1->menuCount)
                return result;
            }
          result = *(displayContextDef_s **)&a1->Menus[4 * v7];
          if (result)
            return (displayContextDef_s *)Menus_Open(
                a1, *(menuDef_t **)&a1->Menus[4 * v7]);
        }
    }
  return result;
}

void __cdecl Script_Open(struct displayContextDef_s *dc, struct itemDef_s *item,
                         char const **args)
{
  int result;              // eax
  displayContextDef_s *v4; // ebx
  signed int v5;           // esi
  char __dst[1048];        // [esp+10h] [ebp-418h] BYREF

  result = String_Parse(a3, __dst, 1024);
    if (result && (int)a1->menuCount > 0) {
      v4 = a1;
      v5 = 0;
        while (1) {
          result = I_stricmp(*(char **)(*(_DWORD *)v4->Menus + 192), __dst);
          if (!result)
            break;
          ++v5;
          v4 = (displayContextDef_s *)((char *)v4 + 4);
          if (v5 >= (signed int)a1->menuCount)
            return result;
        }
      result = *(_DWORD *)&a1->Menus[4 * v5];
      if (result)
        return Menus_Open(a1, *(menuDef_t **)&a1->Menus[4 * v5]);
    }
  return result;
}

void __cdecl Script_SetFocusByDvar(struct displayContextDef_s *dc,
                                   struct itemDef_s *item, char const **args)
{
  UNIMPLEMENTED();
}

void __cdecl UI_AddMenuList(struct displayContextDef_s *dc,
                            struct MenuList *menuList)
{
  UNIMPLEMENTED();
}

void __cdecl Script_SetFocus(struct displayContextDef_s *dc,
                             struct itemDef_s *item, char const **args)
{
  int result;       // eax
  int32_t parent;   // esi
  int v5;           // ebx
  int v6;           // ebx
  int EditFieldDef; // eax
  char __dst[1048]; // [esp+10h] [ebp-418h] BYREF

  result = String_Parse((const char **)a3, __dst, 1024);
    if (result) {
      parent = a2->parent;
      if (!parent || *(int *)(parent + 536) <= 0)
        return Com_Printf("setFocus: could not find widget named '%s'\n",
                          __dst);
      v5 = 0;
        while (!*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(parent + 636) + 4 * v5) +
                            192) ||
               I_stricmp(
                   __dst,
                   *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(parent + 636) + 4 * v5) +
                               192))) {
          if (++v5 >= *(_DWORD *)(parent + 536))
            return Com_Printf("setFocus: could not find widget named '%s'\n",
                              __dst);
        }
      v6 = *(_DWORD *)(*(_DWORD *)(parent + 636) + 4 * v5);
        if (v6) {
          result = Item_SetFocus(a1, (itemDef_s *)v6, *(float *)v6,
                                 *(float *)(v6 + 4));
            if (result) {
                if (*(_DWORD *)(v6 + 624) <= 0x12u) {
                  result = 1 << *(_DWORD *)(v6 + 624);
                    if ((result & 0x70210) != 0) {
                      EditFieldDef = Item_GetEditFieldDef((itemDef_s *)v6);
                      if (EditFieldDef)
                        *(_DWORD *)(EditFieldDef + 28) = 0;
                      Item_SetCursorPos((itemDef_s *)v6, 0);
                      g_editingField = 1;
                      g_editItem = (itemDef_s *)v6;
                      return Key_SetOverstrikeMode(1);
                    }
                }
            }
            else {
              return Com_Printf(
                  "setFocus: error focusing widget '%s' (widget was "
                  "found but could not accept focus)\n",
                  __dst);
            }
        }
        else {
          return Com_Printf("setFocus: could not find widget named '%s'\n",
                            __dst);
        }
    }
  return result;
}

void __cdecl Window_Paint(struct displayContextDef_s *dc, struct windowDef_t *w,
                          float fadeAmount, float fadeInAmount, float fadeClamp,
                          float fadeCycle)
{
  unsigned int style;   // eax
  float v7;             // xmm0_4
  float v8;             // xmm0_4
  float *borderColor;   // eax
  int32_t border;       // eax
  float *v11;           // edx
  float *v12;           // edx
  int v13;              // edx
  signed int realTime;  // eax
  float v15;            // xmm0_4
  float *foreColor;     // edx
  int32_t cinematic;    // eax
  int v18;              // eax
  int32_t v19;          // edx
  float v20;            // xmm0_4
  float *backColor;     // [esp+18h] [ebp-30h]
  Material *background; // [esp+1Ch] [ebp-2Ch]
  float v23;            // [esp+20h] [ebp-28h]
  float v24;            // [esp+24h] [ebp-24h]
  float v25;            // [esp+28h] [ebp-20h]
  float v26;            // [esp+2Ch] [ebp-1Ch]
  float v27;            // [esp+30h] [ebp-18h] BYREF
  int v28;              // [esp+34h] [ebp-14h]
  int v29;              // [esp+38h] [ebp-10h]
  int v30;              // [esp+3Ch] [ebp-Ch]

  v23 = *(float *)&a2->rect[12];
  v24 = *(float *)&a2->rect[8];
  v25 = *(float *)&a2->rect[4];
  v26 = *(float *)a2->rect;
    if (debugMode) {
      v30 = 1065353216;
      v29 = 1065353216;
      v28 = 1065353216;
      v27 = 1.0;
      UI_DrawRect(__SPAIR64__(LODWORD(v25), LODWORD(v26)), v24, v23,
                  *(_DWORD *)&a2->rect[16], *(_DWORD *)&a2->rect[20], 1.0,
                  &v27);
    }
    if (a2) {
      style = a2->style;
        if (style) {
            if (!a2->border) {
                if (style > 7) {
                LABEL_14:
                  border = a2->border;
                    switch (border) {
                    case 1:
                        if (a2->style == 4) {
                            if (a2->borderColor[0] <= 0.0) {
                              v29 = 1065353216;
                              v28 = 1056964608;
                              v27 = 0.5;
                            }
                            else {
                              v27 = 1.0;
                              v29 = 1056964608;
                              v28 = 1056964608;
                            }
                          v30 = 1065353216;
                          borderColor = &v27;
                        }
                        else {
                          borderColor = a2->borderColor;
                        }
                      UI_DrawRect(*(_QWORD *)a2->rect, *(float *)&a2->rect[8],
                                  *(float *)&a2->rect[12],
                                  *(_DWORD *)&a2->rect[16],
                                  *(_DWORD *)&a2->rect[20],
                                  *(float *)&a2->borderSize, borderColor);
                      break;
                    case 2:
                      UI_DrawTopBottom(
                          *(float *)a2->rect, *(_QWORD *)&a2->rect[4],
                          *(float *)&a2->rect[12], *(_DWORD *)&a2->rect[16],
                          *(_DWORD *)&a2->rect[20], *(float *)&a2->borderSize,
                          a2->borderColor);
                      break;
                    case 3:
                      UI_DrawSides(*(_QWORD *)a2->rect, *(float *)&a2->rect[8],
                                   *(float *)&a2->rect[12],
                                   *(_DWORD *)&a2->rect[16],
                                   *(_DWORD *)&a2->rect[20],
                                   *(float *)&a2->borderSize, a2->borderColor);
                      break;
                    }
                  return;
                }
            LABEL_7:
                switch (style) {
                case 1u:
                    if (a2->background) {
                      v13 = *(_DWORD *)a2->dynamicFlags;
                        if ((v13 & 0x30) != 0) {
                          realTime = a1->realTime;
                            if (realTime > (signed int)a2->nextTime) {
                              a2->nextTime = (int)a6 + realTime;
                                if ((v13 & 0x10) != 0) {
                                  v15 = a2->backColor[3] - a3;
                                  a2->backColor[3] = v15;
                                  if (v15 <= 0.0)
                                    v13 &= 0xFFFFFFEB;
                                }
                                else {
                                  v20 = a4 + a2->backColor[3];
                                  a2->backColor[3] = v20;
                                    if (v20 >= a5) {
                                      a2->backColor[3] = a5;
                                      v13 &= ~0x20u;
                                    }
                                }
                            }
                        }
                      Window_SetDynamicFlags(a2, v13);
                      background = (Material *)a2->background;
                      backColor = a2->backColor;
                      goto LABEL_35;
                    }
                  UI_FillRect(__SPAIR64__(LODWORD(v25), LODWORD(v26)), v24, v23,
                              *(_DWORD *)&a2->rect[16],
                              *(_DWORD *)&a2->rect[20], a2->backColor);
                  break;
                case 3u:
                  if ((a2->dynamicFlags[2] & 1) != 0)
                    foreColor = a2->foreColor;
                  else
                    foreColor = 0;
                  background = (Material *)a2->background;
                  backColor = foreColor;
                  goto LABEL_35;
                case 5u:
                    if (a2->cinematic == -1) {
                      v18 = CIN_PlayCinematic(*(const char **)a2->cinematicName,
                                              (int)v26, (int)v25, (int)v24,
                                              (int)v23, 0xAu);
                      v19 = -2;
                      if (v18 != -1)
                        v19 = v18;
                      a2->cinematic = v19;
                      cinematic = v19;
                    }
                    else {
                      cinematic = a2->cinematic;
                    }
                    if (cinematic >= 0) {
                      CIN_RunCinematic(cinematic);
                      CIN_SetExtents(a2->cinematic, (int)v26, (int)v25,
                                     (int)v24, (int)v23);
                      CIN_DrawCinematic(a2->cinematic);
                    }
                  break;
                case 6u:
                    if (a2->background) {
                      if ((a2->dynamicFlags[2] & 1) != 0)
                        v11 = a2->foreColor;
                      else
                        v11 = 0;
                      background = (Material *)a2->background;
                      backColor = v11;
                    LABEL_35:
                      UI_DrawHandlePic(
                          v26, v25, v24, v23, *(_DWORD *)&a2->rect[16],
                          *(_DWORD *)&a2->rect[20], backColor, background);
                    }
                  break;
                case 7u:
                  if ((a2->dynamicFlags[2] & 1) != 0)
                    v12 = a2->foreColor;
                  else
                    v12 = 0;
                  UI_DrawLoadBar(v26, v25, v24, v23, *(_DWORD *)&a2->rect[16],
                                 *(_DWORD *)&a2->rect[20], v12,
                                 (Material *)a2->background);
                  break;
                default:
                  goto LABEL_14;
                }
              goto LABEL_14;
            }
        }
        else if (!a2->border) {
          return;
        }
      v7 = *(float *)&a2->borderSize;
      v26 = v26 + v7;
      v25 = v25 + v7;
      v8 = v7 + 1.0;
      v24 = v24 - v8;
      v23 = v23 - v8;
      goto LABEL_7;
    }
}

void __cdecl Item_OwnerDraw_Paint(struct displayContextDef_s *dc,
                                  struct itemDef_s *item)
{
  UNIMPLEMENTED();
}

void __cdecl Item_Paint(struct displayContextDef_s *dc, struct itemDef_s *item)
{
  int v3;                  // eax
  signed int realTime;     // edx
  signed int v5;           // eax
  windowDef_t *v6;         // ecx
  uint32_t ownerDrawFlags; // eax
  windowDef_t *v8;         // edx
  int v9;                  // eax
  int v10;                 // ebx
  int32_t v11;             // edx
  float v12;               // xmm2_4
  float v13;               // xmm1_4
  float v14;               // xmm0_4
  windowDef_t *v15;        // ecx
  windowDef_t *v16;        // ecx
  float *v17;              // edx
  float *v18;              // ecx
  float v19;               // xmm1_4
  float v20;               // xmm1_4
  float v21;               // xmm0_4
  int32_t v22;             // edx
  float v23;               // xmm2_4
  float v24;               // xmm1_4
  float v25;               // xmm0_4
  float v26;               // xmm1_4
  float v27;               // xmm1_4
  float v28;               // xmm1_4
  int borderSize;          // ebx
  const char *String;      // eax
  int Var;                 // eax
  int v32;                 // ebx
  char *v33;               // ecx
  itemDefData_t v34;       // eax
  itemDefData_t v35;       // esi
  itemDefData_t v36;       // ebx
  int v37;                 // edi
  const char *v38;         // eax
  float v39;               // xmm1_4
  int v40;                 // ecx
  int v41;                 // edi
  int v42;                 // eax
  itemDefData_t v43;       // edx
  int v44;                 // eax
  float v45;               // xmm0_4
  int v46;                 // esi
  float v47;               // [esp+2Ch] [ebp-8Ch]
  float v48;               // [esp+30h] [ebp-88h]
  float v49;               // [esp+44h] [ebp-74h]
  menuDef_t *v50;          // [esp+48h] [ebp-70h]
  float v51;               // [esp+4Ch] [ebp-6Ch]
  float v52;               // [esp+50h] [ebp-68h]
  float v53;               // [esp+54h] [ebp-64h]
  char *VariantString;     // [esp+60h] [ebp-58h]
  int v55;                 // [esp+64h] [ebp-54h]
  char *v56;               // [esp+68h] [ebp-50h]
  int v57;                 // [esp+6Ch] [ebp-4Ch]
  rectDef_s v58;           // [esp+78h] [ebp-40h] BYREF
  float v59[10];           // [esp+90h] [ebp-28h] BYREF

  v50 = *(menuDef_t **)&a3[1].rectClient[44];
  v3 = *(_DWORD *)a3->dynamicFlags;
    if ((v3 & 0x2000) != 0) {
      realTime = a2->realTime;
        if (realTime > (signed int)a3->nextTime) {
          a3->nextTime = *(_DWORD *)a3->offsetTime + realTime;
          v52 = *(float *)&a3->rectClient[8] * 0.5;
          v53 = 0.5 * *(float *)&a3->rectClient[12];
          v51 = (float)(v53 + *(float *)&a3->rectClient[4]) -
                a3->rectEffects0[0][1];
          v48 =
              (float)(v52 + *(float *)a3->rectClient) - a3->rectEffects0[0][0];
          v49 = sinf(0.052359879);
          a1 = cosf(0.052359879);
          v47 = a1;
          v58.w = *(_DWORD *)&a3->rectClient[8];
          v58.h = *(_DWORD *)&a3->rectClient[12];
          v58.horzAlign = *(_DWORD *)&a3->rectClient[16];
          v58.vertAlign = *(_DWORD *)&a3->rectClient[20];
          *(float *)&v58.x =
              (float)((float)((float)(v48 * v47) - (float)(v51 * v49)) +
                      a3->rectEffects0[0][0]) -
              v52;
          *(float *)&v58.y =
              (float)((float)((float)(v48 * v49) + (float)(v47 * v51)) +
                      a3->rectEffects0[0][1]) -
              v53;
          Window_SetRectClient(a3, &v58);
          v22 = *(_DWORD *)&a3[1].rectClient[44];
            if (v22) {
              v23 = *(float *)v22;
              v24 = *(float *)(v22 + 4);
                if (*(_DWORD *)(v22 + 212)) {
                  v25 = *(float *)(v22 + 224);
                  v23 = v23 + v25;
                  v24 = v24 + v25;
                }
              Item_SetScreenCoords((itemDef_s *)a3, v23, v24,
                                   *(_DWORD *)(v22 + 16),
                                   *(_DWORD *)(v22 + 20));
              v3 = *(_DWORD *)a3->dynamicFlags;
            }
            else {
              v3 = *(_DWORD *)a3->dynamicFlags;
            }
        }
    }
    if ((v3 & 0x80u) != 0) {
      v5 = a2->realTime;
        if (v5 <= (signed int)a3->nextTime) {
          v6 = a3;
          ownerDrawFlags = a3->ownerDrawFlags;
          if (ownerDrawFlags)
            goto LABEL_6;
        LABEL_22:
          v8 = v6;
          goto LABEL_23;
        }
      a3->nextTime = *(_DWORD *)a3->offsetTime + v5;
      v17 = a3->rectEffects0[0];
      v18 = a3->rectEffects1[0];
      v58 = *(rectDef_s *)a3->rectClient;
      v19 = a3->rectEffects0[0][0];
        if (*(float *)&v58.x != v19) {
            if (v19 <= *(float *)&v58.x) {
              *(float *)&v58.x = *(float *)&v58.x - *v18;
              v20 = *v17;
              if (*v17 <= *(float *)&v58.x)
                goto LABEL_34;
            }
            else {
              *(float *)&v58.x = *(float *)&v58.x + *v18;
              v20 = *v17;
                if (*(float *)&v58.x <= *v17) {
                LABEL_34:
                  v10 = 0;
                  goto LABEL_46;
                }
            }
          *(float *)&v58.x = v20;
        }
      v10 = 1;
    LABEL_46:
      v26 = a3->rectEffects0[0][1];
        if (*(float *)&v58.y == v26) {
        LABEL_47:
          ++v10;
          goto LABEL_48;
        }
        if (v26 <= *(float *)&v58.y) {
          *(float *)&v58.y = *(float *)&v58.y - a3->rectEffects1[0][1];
            if (v26 > *(float *)&v58.y) {
              *(float *)&v58.y = v26;
              goto LABEL_47;
            }
        }
        else {
          *(float *)&v58.y = *(float *)&v58.y + a3->rectEffects1[0][1];
            if (*(float *)&v58.y > v26) {
              *(float *)&v58.y = v26;
              ++v10;
            }
        }
    LABEL_48:
      v27 = a3->rectEffects0[0][2];
        if (*(float *)&v58.w == v27) {
        LABEL_49:
          ++v10;
          goto LABEL_50;
        }
        if (v27 <= *(float *)&v58.w) {
          *(float *)&v58.w = *(float *)&v58.w - a3->rectEffects1[0][2];
            if (v27 > *(float *)&v58.w) {
              *(float *)&v58.w = v27;
              goto LABEL_49;
            }
        }
        else {
          *(float *)&v58.w = *(float *)&v58.w + a3->rectEffects1[0][2];
            if (*(float *)&v58.w > v27) {
              *(float *)&v58.w = v27;
              ++v10;
            }
        }
    LABEL_50:
      v28 = a3->rectEffects0[1][0];
        if (*(float *)&v58.h != v28) {
            if (v28 > *(float *)&v58.h) {
              *(float *)&v58.h = *(float *)&v58.h + a3->rectEffects1[1][0];
                if (*(float *)&v58.h > v28) {
                  *(float *)&v58.h = v28;
                  ++v10;
                }
              goto LABEL_15;
            }
          *(float *)&v58.h = *(float *)&v58.h - a3->rectEffects1[1][0];
            if (v28 <= *(float *)&v58.h) {
            LABEL_15:
              Window_SetRectClient(a3, &v58);
              v11 = *(_DWORD *)&a3[1].rectClient[44];
                if (v11) {
                  v12 = *(float *)v11;
                  v13 = *(float *)(v11 + 4);
                    if (*(_DWORD *)(v11 + 212)) {
                      v14 = *(float *)(v11 + 224);
                      v12 = v12 + v14;
                      v13 = v13 + v14;
                    }
                  Item_SetScreenCoords((itemDef_s *)a3, v12, v13,
                                       *(_DWORD *)(v11 + 16),
                                       *(_DWORD *)(v11 + 20));
                }
              if (v10 == 4)
                Window_RemoveDynamicFlags(a3, 128);
              goto LABEL_21;
            }
          *(float *)&v58.h = v28;
        }
      ++v10;
      goto LABEL_15;
    }
LABEL_21:
  v6 = a3;
  ownerDrawFlags = a3->ownerDrawFlags;
  if (!ownerDrawFlags)
    goto LABEL_22;
LABEL_6:
    if (!UI_OwnerDrawVisible(ownerDrawFlags)) {
      Window_RemoveDynamicFlags(a3, 4);
      v8 = a3;
    LABEL_23:
      if ((v8[1].name[0] & 0xC) != 0)
        goto LABEL_8;
    LABEL_24:
      v15 = v8;
      goto LABEL_25;
    }
  Window_AddDynamicFlags(a3, 4);
  v8 = a3;
  if ((a3[1].name[0] & 0xC) == 0)
    goto LABEL_24;
LABEL_8:
    if (!Item_EnableShowViaDvar((const itemDef_s *)v8, 4)) {
      v9 = *(_DWORD *)a3->dynamicFlags;
        if ((v9 & 4) != 0 && (v9 & 2) != 0) {
          Menu_HandleKey(a2, v50, 155, 1);
          Menu_HandleKey(a2, v50, 155, 0);
        }
      return;
    }
  v15 = a3;
LABEL_25:
  if ((v15->dynamicFlags[0] & 4) == 0)
    return;
    if (v15->style == 6) {
      borderSize = v15[1].borderSize;
      String = (const char *)Dvar_GetString(*(char **)&v15[1].rectClient[80]);
      a3->background = CL_RegisterMaterialNoMip(String, borderSize);
    }
  Window_Paint(a2, a3, *(float *)&v50->fadeAmount, *(float *)&v50->fadeInAmount,
               *(float *)&v50->fadeClamp, (float)v50->fadeCycle);
    if (debugMode) {
      memset(&Item_CorrectedTextRect(itemDef_s *)::rect, 0, 0x18u);
      Item_CorrectedTextRect(itemDef_s *)::rect = *(float *)a3[1].rect;
      dword_F00748 = *(_DWORD *)&a3[1].rect[4];
      flt_F0074C = *(float *)&a3[1].rect[8];
      flt_F00750 = *(float *)&a3[1].rect[12];
      dword_F00754 = *(_DWORD *)&a3[1].rect[16];
      dword_F00758 = *(_DWORD *)&a3[1].rect[20];
      LODWORD(v21) = dword_F00748;
        if (flt_F0074C != 0.0) {
          v21 = *(float *)&dword_F00748 - flt_F00750;
          *(float *)&dword_F00748 = *(float *)&dword_F00748 - flt_F00750;
        }
      v59[3] = 1.0;
      v59[1] = 1.0;
      v59[2] = 0.0;
      v59[0] = 0.0;
      UI_DrawRect(__SPAIR64__(LODWORD(v21), LODWORD(Item_CorrectedTextRect(
                                                itemDef_s *)::rect)),
                  flt_F0074C, flt_F00750, dword_F00754, dword_F00758, 1.0, v59);
      v16 = a3;
      if (a3->style == 6)
        return;
    }
    else {
      v16 = a3;
      if (a3->style == 6)
        return;
    }
    switch (*(_DWORD *)v16[1].rectClient) {
    case 0:
    case 1:
      Item_Text_Paint(a1, a2, a3);
      return;
    case 4:
    case 9:
    case 0x10:
    case 0x11:
    case 0x12:
      Item_TextField_Paint(a1, a2, (itemDef_s *)a3);
      return;
    case 6:
      Item_ListBox_Paint(a1, a2, (itemDef_s *)a3);
      return;
    case 8:
      Item_OwnerDraw_Paint(a1, a2, a3);
      return;
    case 0xA:
      Item_Slider_Paint(a1, a2, a3);
      return;
    case 0xB:
      Item_YesNo_Paint(a1, a2, (itemDef_s *)a3);
      return;
    case 0xC:
      v34.listBox = Item_GetMultiDef((itemDef_s *)a3).listBox;
      v35.listBox = v34.listBox;
        if (!v34.listBox) {
          v33 = "<dvarStrList or dvarFloatList not set>";
          goto LABEL_76;
        }
        if (*(_DWORD *)(v34.listBox + 388)) {
          VariantString =
              (char *)Dvar_GetVariantString(*(char **)&a3[1].rectClient[80]);
          if (*(int *)(v35.listBox + 384) <= 0)
            goto LABEL_80;
          v36.listBox = v35.listBox;
          v37 = 0;
            while (I_stricmp(VariantString, *(char **)(v36.listBox + 128))) {
              ++v37;
              v36.listBox += 4;
                if (v37 >= *(_DWORD *)(v35.listBox + 384)) {
                  v33 = (char *)&inData;
                  goto LABEL_76;
                }
            }
          v33 = *(char **)(v35.listBox + 4 * v37);
        }
        else {
          v38 = (const char *)Dvar_GetVariantString(
              *(char **)&a3[1].rectClient[80]);
          a1 = atof(v38);
          v39 = a1;
          v40 = *(_DWORD *)(v35.listBox + 384);
          if (v40 <= 0)
            goto LABEL_80;
            if (v39 == *(float *)(v35.listBox + 256)) {
              v33 = *(char **)v35.listBox;
              goto LABEL_76;
            }
          v43.listBox = v35.listBox;
          v44 = 0;
            do {
              if (++v44 == v40)
                goto LABEL_80;
              v45 = *(float *)(v43.listBox + 260);
              v43.listBox += 4;
            }
          while (v39 != v45);
          v33 = *(char **)(v35.listBox + 4 * v44);
        }
      goto LABEL_76;
    case 0xD:
        if (!a3[1].ownerDrawFlags) {
          v33 = "<dvarEnumList not set>";
          goto LABEL_76;
        }
      Var = Dvar_FindVar((char *)a3[1].ownerDrawFlags);
      v32 = Var;
        if (*(_BYTE *)(Var + 6) != 6) {
          v33 = "<not an enum dvar>";
          goto LABEL_76;
        }
        if (!*(_DWORD *)(Var + 20)) {
        LABEL_80:
          v33 = (char *)&inData;
          goto LABEL_76;
        }
      v55 = Dvar_FindVar((char *)a3[1].ownerDrawFlags);
      if (*(_BYTE *)(v55 + 6) != 6)
        goto LABEL_95;
      v56 = (char *)Dvar_GetVariantString(*(char **)&a3[1].rectClient[80]);
      v42 = atoi(v56);
        if (v42 < 0 || v42 >= *(_DWORD *)(v55 + 20)) {
            if (*(int *)(v55 + 20) <= 0) {
            LABEL_95:
              v41 = 0;
              goto LABEL_96;
            }
          v57 = 0;
          v46 = 0;
            while (1) {
              v41 = v46;
              if (!I_stricmp(v56, *(char **)(*(_DWORD *)(v55 + 24) + v46)))
                break;
              ++v57;
              v46 += 4;
              if (*(_DWORD *)(v55 + 20) <= v57)
                goto LABEL_95;
            }
        }
        else {
          v41 = 4 * v42;
        }
    LABEL_96:
      v33 = *(char **)(*(_DWORD *)(v32 + 24) + v41);
    LABEL_76:
      Item_List_Paint(a2, (int)a3, v33, a1);
      break;
    case 0xE:
      Item_Bind_Paint(a1, a2, (itemDef_s *)a3);
      return;
    default:
      return;
    }
}

void __cdecl Menu_Paint(struct displayContextDef_s *dc, struct menuDef_t *menu,
                        int forcePaint)
{
  uint32_t ownerDrawFlags;  // eax
  float v5;                 // xmm1_4
  signed int v6;            // ebx
  signed int v7;            // ebx
  uint8_t *v8;              // ecx
  signed int v9;            // edi
  int v10;                  // edx
  menuDef_t *v11;           // eax
  uint8_t *v12;             // edx
  signed int v13;           // ecx
  displayContextDef_s *v14; // edx
  uint32_t openMenuCount;   // eax
  char v16;                 // [esp+8h] [ebp-40h]
  float v17[10];            // [esp+20h] [ebp-28h] BYREF

  if (!a3)
    return;
    if ((a3->window.dynamicFlags[0] & 4) != 0) {
      ownerDrawFlags = a3->window.ownerDrawFlags;
      if (!ownerDrawFlags)
        goto LABEL_4;
    }
    else {
      if (!a4)
        return;
      ownerDrawFlags = a3->window.ownerDrawFlags;
      if (!ownerDrawFlags)
        goto LABEL_4;
    }
  if (!UI_OwnerDrawVisible(ownerDrawFlags))
    return;
LABEL_4:
  if (*(_DWORD *)a3->soundName)
    UI_PlayLocalSoundAliasByName(*(char **)a3->soundName);
  v5 = *(float *)&a3->blurRadius;
    if (v5 == 0.0) {
      if (!a4)
        goto LABEL_8;
    LABEL_23:
      Window_AddDynamicFlags(&a3->window, 0x4000);
      v7 = a2->openMenuCount - 1;
        if (v7 >= 0) {
            if (a3 == *(menuDef_t **)&a2->menuStack[4 * v7]) {
              v9 = a2->openMenuCount - 1;
            LABEL_28:
              a2->openMenuCount = v7;
                if (v9 < v7) {
                  v12 = &a2->menuStack[4 * v9 + 4];
                  v13 = v9;
                    do {
                      ++v13;
                      *(_DWORD *)&v12[4 * v9 + 560 - (4 * v9 + 564)] =
                          *(_DWORD *)v12;
                      v12 += 4;
                    }
                  while ((signed int)a2->openMenuCount > v13);
                  v14 = a2;
                LABEL_32:
                    if (v14->openMenuCount == 16) {
                      Com_Error(1, "\x15Too many menus opened", v16);
                      v14 = a2;
                    }
                  openMenuCount = v14->openMenuCount;
                  *(_DWORD *)&v14->menuStack[4 * openMenuCount] = a3;
                  v14->openMenuCount = openMenuCount + 1;
                  if (!a3->fullScreen)
                    goto LABEL_11;
                  goto LABEL_9;
                }
            }
            else {
              v8 = &a2->menuStack[4 * v7];
              v9 = a2->openMenuCount - 1;
              v10 = 0;
                while (1) {
                  --v9;
                  if (v10 == v7)
                    break;
                  v11 = (menuDef_t *)*((_DWORD *)v8 - 1);
                  ++v10;
                  v8 -= 4;
                  if (a3 == v11)
                    goto LABEL_28;
                }
            }
        }
      v14 = a2;
      goto LABEL_32;
    }
  *(float *)&a2->blurRadiusOut =
      fsqrt((float)(v5 * v5) + (float)(*(float *)&a2->blurRadiusOut *
                                       *(float *)&a2->blurRadiusOut));
  if (a4)
    goto LABEL_23;
LABEL_8:
    if (a3->fullScreen) {
    LABEL_9:
      if (a3->window.background)
        UI_DrawHandlePic(0.0, 0.0, 640.0, 480.0,
                         *(_DWORD *)&a3->window.rect[16],
                         *(_DWORD *)&a3->window.rect[20], 0,
                         (Material *)a3->window.background);
    }
LABEL_11:
  Window_Paint(a2, &a3->window, *(float *)&a3->fadeAmount,
               *(float *)&a3->fadeInAmount, *(float *)&a3->fadeClamp,
               (float)a3->fadeCycle);
    if ((int)a3->itemCount <= 0) {
      if (!debugMode)
        return;
    LABEL_18:
      v17[3] = 1.0;
      v17[2] = 1.0;
      v17[0] = 1.0;
      v17[1] = 0.0;
      UI_DrawRect(*(_QWORD *)a3->window.rect, *(float *)&a3->window.rect[8],
                  *(float *)&a3->window.rect[12],
                  *(_DWORD *)&a3->window.rect[16],
                  *(_DWORD *)&a3->window.rect[20], 1.0, v17);
      return;
    }
  v6 = 0;
  do
    Item_Paint(a1, a2, *(windowDef_t **)(a3->items + 4 * v6++));
  while (v6 < (signed int)a3->itemCount);
  if (debugMode)
    goto LABEL_18;
}

void __cdecl Menu_PaintAll(struct displayContextDef_s *dc)
{
  UNIMPLEMENTED();
}

int scriptCommandCount;
struct commandDef_t *commandList;
int g_waitingForKey;
int g_editingField;
struct itemDef_s *g_editItem;

void __cdecl GetPlatformCommand(char const *, char const **)
{
  UNIMPLEMENTED();
}

bool __cdecl Item_IsTextField(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Item_List_NextEntryForKey(int, int, int)
{
  UNIMPLEMENTED();
}

int __cdecl Item_DvarEnum_CountSettings(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

bool __cdecl Script_ExecIfIntsEqual(char const *, char const *)
{
  int v2; // ebx

  v2 = atoi(a1);
  return v2 == atoi(a2);
}

int __cdecl Menus_MenuIsInStack(struct displayContextDef_s *,
                                struct menuDef_t *)
{
  UNIMPLEMENTED();
}

int __cdecl Menus_RemoveFromStack(struct displayContextDef_s *,
                                  struct menuDef_t *)
{
  UNIMPLEMENTED();
}

int __cdecl Menus_IsMenuOnStack(struct displayContextDef_s *,
                                struct menuDef_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Window_CloseCinematic(struct windowDef_t *)
{
  UNIMPLEMENTED();
}

int __cdecl Item_Multi_CountSettings(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Menus_AddToStack(struct displayContextDef_s *, struct menuDef_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Controls_GetKeyAssignment(char *, int *)
{
  UNIMPLEMENTED();
}

struct rectDef_s *__cdecl Item_CorrectedTextRect(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Menu_CloseCinematics(struct menuDef_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Item_TextField_BeginEdit(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Item_DvarEnum_EnumIndex(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

char const *__cdecl Item_Multi_Setting(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Item_Multi_FindDvarByValue(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

bool __cdecl Script_ExecIfStringsEqual(char const *, char const *)
{
  return I_stricmp(a1, a2) == 0;
}

struct Font_s *__cdecl Item_GetFont(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Display_CloseCinematics(struct displayContextDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Item_TextField_EnsureCursorVisible(struct itemDef_s *,
                                                char const *)
{
  UNIMPLEMENTED();
}

char const *__cdecl Item_DvarEnum_Setting(struct itemDef_s *)
{
  UNIMPLEMENTED();
}

bool __cdecl Script_ExecIfFloatsEqual(char const *, char const *)
{
  float v2;  // xmm0_4
  double v4; // [esp+10h] [ebp-18h]

  v4 = atof(a1);
  v2 = v4 - atof(a2);
  return fabs(v2) < 0.0000099999997;
}

void __cdecl Menu_RunCloseScript(struct displayContextDef_s *,
                                 struct menuDef_t *)
{
  UNIMPLEMENTED();
}

void __cdecl Scroll_Slider_SetThumbPos(struct displayContextDef_s *,
                                       struct itemDef_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Item_DvarEnum_HandleKey(struct displayContextDef_s *,
                                    struct itemDef_s *, int)
{
  UNIMPLEMENTED();
}

int __cdecl Item_Multi_HandleKey(struct displayContextDef_s *,
                                 struct itemDef_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl Scroll_Slider_ThumbFunc(struct displayContextDef_s *, void *)
{
  return Scroll_Slider_SetThumbPos((int)a1, a2[6]);
}

void __cdecl Script_ConditionalExecHandler(int, struct itemDef_s *,
                                           char const **,
                                           bool(__cdecl *)(char const *,
                                                           char const *))
{
  UNIMPLEMENTED();
}

void __cdecl Script_ExecHandler(int, struct itemDef_s *, char const **)
{
  UNIMPLEMENTED();
}

void __cdecl Item_List_Paint(struct displayContextDef_s *, struct itemDef_s *,
                             char const *)
{
  UNIMPLEMENTED();
}

void __cdecl Item_DvarEnum_Paint(struct displayContextDef_s *,
                                 struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Item_Multi_Paint(struct displayContextDef_s *, struct itemDef_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Scroll_ListBox_ThumbFunc(struct displayContextDef_s *, void *)
{
  UNIMPLEMENTED();
}

void __cdecl Scroll_ListBox_AutoFunc(struct displayContextDef_s *, void *)
{
  signed int result; // eax

  result = a1->realTime;
    if (result > *(_DWORD *)a2) {
      Item_ListBox_HandleKey(a1, *((itemDef_s **)a2 + 6), *((_DWORD *)a2 + 3),
                             1, 0);
      *(_DWORD *)a2 = *((_DWORD *)a2 + 2) + a1->realTime;
      result = a1->realTime;
    }
    if (result > *((_DWORD *)a2 + 1)) {
      *((_DWORD *)a2 + 1) = result + 150;
      result = *((_DWORD *)a2 + 2);
        if (result > 20) {
          result -= 40;
          *((_DWORD *)a2 + 2) = result;
        }
    }
  return result;
}

void __cdecl Item_StartCapture(struct displayContextDef_s *, struct itemDef_s *,
                               int)
{
  UNIMPLEMENTED();
}

void __cdecl UI_AddMenu(struct displayContextDef_s *, struct menuDef_t *)
{
  UNIMPLEMENTED();
}

Menu_HandleMouseMove(displayContextDef_s *dc, menuDef_t *menu, float x, float y)
{
  UNIMPLEMENTED();
}

Display_MouseMove(displayContextDef_s *dc, void *p, int x, int y)
{
  UNIMPLEMENTED();
}

Menus_HandleOOBClick(displayContextDef_s *dc, menuDef_t *menu, int key,
                     int down)
{
  UNIMPLEMENTED();
}
