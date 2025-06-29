void __cdecl CG_SetEquippedOffHand(int offHandIndex)
{
  *((_DWORD *)cg + 44956) = a1;
  return CG_MenuShowNotify((windowDef_t *)4);
}

void __cdecl CG_SwitchOffHandCmd()
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawOffHandAmmo(struct rectDef_s *rect, struct Font_s *font,
                                float scale, float *const color, int textStyle,
                                int weaponType)
{
  _DWORD *v6;       // esi
  const dvar_s *v7; // ebx
  long double v8;   // fst7
  int NumWeapons;   // edi
  int v10;          // ebx
  char *v11;        // edx
  float v12;        // [esp+34h] [ebp-34h]
  float v13;        // [esp+38h] [ebp-30h]
  char v14[4];      // [esp+3Ch] [ebp-2Ch]

  v6 = cg;
    if (*((int *)cg + 38642) <= 5 &&
        (BG_GetFirstAvailableOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg), a6) ||
         BG_GetFirstEquippedOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v6), a6))) {
      v7 = (const dvar_s *)hud_fade_offhand;
      v12 = floorf((float)(1000.0 * *(float *)(hud_fade_offhand + 8)) + 0.5);
      v8 = CG_FadeHudMenu(v7, v6[45428], (int)v12);
      v13 = v8;
        if (v13 != 0.0) {
          NumWeapons = BG_GetNumWeapons();
            if (NumWeapons <= 0) {
              *(_DWORD *)v14 = 0;
            }
            else {
              v10 = 1;
              *(_DWORD *)v14 = 0;
                do {
                  if ((((int)v6[(v10 >> 5) + 38978] >> (v10 & 0x1F)) & 1) !=
                          0 &&
                      a6 == *(_DWORD *)(BG_GetWeaponDef(v10) + 132))
                    *(_DWORD *)v14 += v6[BG_ClipForWeapon(v10) + 38850];
                  ++v10;
                }
              while (NumWeapons >= v10);
            }
          v11 = va("%i", *(_DWORD *)v14);
          UI_DrawText(v8, v11, 0x7FFFFFFF, a2, *(float *)&a1->x,
                      *(float *)&a1->y, a1->horzAlign, a1->vertAlign, a3);
        }
    }
}

void __cdecl CG_DrawOffHandHighlight(struct rectDef_s *rect, float scale,
                                     float *const color,
                                     struct Material *material, int weaponType)
{
  _DWORD *v5;       // esi
  const dvar_s *v6; // ebx
  int v7;           // ebx
  _DWORD *v8;       // esi
  float v9;         // ebx
  float v10;        // ecx
  float v11;        // eax
  float v12;        // xmm1_4
  float v13;        // [esp+2Ch] [ebp-3Ch]
  float v14;        // [esp+30h] [ebp-38h]
  int v15;          // [esp+34h] [ebp-34h]
  int NumWeapons;   // [esp+38h] [ebp-30h]
  float v17;        // [esp+3Ch] [ebp-2Ch]
  float v18[3];     // [esp+40h] [ebp-28h] BYREF
  float v19;        // [esp+4Ch] [ebp-1Ch]

  v5 = cg;
    if (*((int *)cg + 38642) <= 5 &&
        (BG_GetFirstAvailableOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg), a5) ||
         BG_GetFirstEquippedOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v5), a5))) {
        if (v5[44956]) {
          v6 = (const dvar_s *)hud_fade_offhand;
          v14 =
              floorf((float)(1000.0 * *(float *)(hud_fade_offhand + 8)) + 0.5);
          v17 = CG_FadeHudMenu(v6, v5[45428], (int)v14);
            if (v17 != 0.0 &&
                a5 == *(_DWORD *)(BG_GetWeaponDef(v5[44956]) + 132)) {
              NumWeapons = BG_GetNumWeapons();
              if (NumWeapons <= 0)
                goto LABEL_16;
              v7 = 1;
              v15 = 0;
                do {
                  v8 = cg;
                    if (((*((int *)cg + (v7 >> 5) + 38978) >> (v7 & 0x1F)) &
                         1) != 0 &&
                        a5 == *(_DWORD *)(BG_GetWeaponDef(v7) + 132)) {
                      v15 += v8[BG_ClipForWeapon(v7) + 38850];
                    }
                  ++v7;
                }
              while (NumWeapons >= v7);
                if (v15) {
                  v11 = *a3;
                  v10 = a3[1];
                  v9 = a3[2];
                }
                else {
                LABEL_16:
                  v9 = 0.0099999998;
                  v10 = 0.18000001;
                  v11 = 0.88999999;
                }
              v18[0] = v11;
              v18[1] = v10;
              v18[2] = v9;
              v19 = v17;
              v12 = (float)(*(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg) -
                            *((_DWORD *)cg + 45429)) /
                    1000.0;
                if (*(float *)(hud_flash_time_offhand + 8) > v12) {
                  v13 = cosf((float)(v12 * 6.2831855) /
                             *(float *)(hud_flash_period_offhand + 8));
                  v19 = (float)((float)(v13 * 0.5) + 0.5) * v17;
                }
              UI_DrawHandlePic(*(float *)&a1->x, *(float *)&a1->y,
                               *(float *)&a1->w, *(float *)&a1->h,
                               a1->horzAlign, a1->vertAlign, v18, a4);
            }
        }
    }
}

void __cdecl CG_DrawOffHandIcon(struct rectDef_s *rect, float scale,
                                float *const color, struct Material *material,
                                int weaponType)
{
  _DWORD *v5;                // esi
  const dvar_s *v6;          // ebx
  const playerState_s *v7;   // ebx
  int FirstAvailableOffhand; // ecx
  float v9;                  // [esp+28h] [ebp-30h]
  float v10;                 // [esp+2Ch] [ebp-2Ch]
  float v11[10];             // [esp+30h] [ebp-28h] BYREF

  v5 = cg;
    if (*((int *)cg + 38642) <= 5 &&
        (BG_GetFirstAvailableOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg), a5) ||
         BG_GetFirstEquippedOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v5), a5))) {
      v6 = (const dvar_s *)hud_fade_offhand;
      v9 = floorf((float)(1000.0 * *(float *)(hud_fade_offhand + 8)) + 0.5);
      v10 = CG_FadeHudMenu(v6, v5[45428], (int)v9);
      v11[3] = v10;
        if (v10 != 0.0) {
            if ((v11[0] = *a3, v11[1] = a3[1], v11[2] = a3[2], v5[44956]) &&
                    a5 == *(_DWORD *)(BG_GetWeaponDef(v5[44956]) + 132) &&
                    (FirstAvailableOffhand = v5[44956]) != 0 ||
                (v7 = (const playerState_s *)((char *)cg + 154564),
                 (FirstAvailableOffhand = BG_GetFirstAvailableOffhand(
                      (const playerState_s *)((char *)cg + 154564), a5)) !=
                     0) ||
                (FirstAvailableOffhand = BG_GetFirstEquippedOffhand(v7, a5)) !=
                    0) {
              UI_DrawHandlePic(*(float *)&a1->x, *(float *)&a1->y,
                               *(float *)&a1->w, *(float *)&a1->h,
                               a1->horzAlign, a1->vertAlign, v11,
                               *((Material **)cg_weapons +
                                 109 * FirstAvailableOffhand + 78));
            }
        }
    }
}

void __cdecl CG_DrawOffHandName(struct rectDef_s *rect, struct Font_s *font,
                                float scale, float *const color, int textStyle,
                                int weaponType)
{
  _DWORD *v6;       // esi
  const dvar_s *v7; // ebx
  long double v8;   // fst7
  char *v9;         // eax
  float v10;        // [esp+38h] [ebp-20h]
  float v11;        // [esp+3Ch] [ebp-1Ch]

  v6 = cg;
    if (*((int *)cg + 38642) <= 5 &&
        (BG_GetFirstAvailableOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)cg), a6) ||
         BG_GetFirstEquippedOffhand(
             (const playerState_s *)((char *)&loc_25BC4 + (_DWORD)v6), a6))) {
      v7 = (const dvar_s *)hud_fade_offhand;
      v10 = floorf((float)(1000.0 * *(float *)(hud_fade_offhand + 8)) + 0.5);
      v8 = CG_FadeHudMenu(v7, v6[45428], (int)v10);
      v11 = v8;
        if (v11 != 0.0) {
          v9 = (char *)UI_SafeTranslateString((&offhandStrings)[a6]);
          UI_DrawText(v8, v9, 0x7FFFFFFF, a2, *(float *)&a1->x,
                      *(float *)&a1->y, a1->horzAlign, a1->vertAlign, a3);
        }
    }
}

void __cdecl CG_OffhandRegisterDvars()
{
  UNIMPLEMENTED();
}

void __cdecl CG_PrepOffHand(struct entityState_s *ent, int event,
                            int eventParam)
{
  int result; // eax

  result = *((_DWORD *)cg_weapons + 109 * a3 + 54);
  if (result)
    return CG_PlayEntitySoundAlias(
        a1->number, *((snd_alias_list_t **)cg_weapons + 109 * a3 + 54));
  return result;
}

void __cdecl CG_UseOffHand(struct centity_s *, int, int)
{
  char *v3;           // ebx
  int result;         // eax
  int v5;             // edx
  void *v6;           // esi
  DObj_s *ClientDObj; // edx
  float v8[9];        // [esp+14h] [ebp-24h] BYREF

  v3 = (char *)cg_weapons + 436 * a3;
  result = *((_DWORD *)v3 + 55);
    if (result) {
      v5 = *(_DWORD *)a1->nextState;
      v6 = cg;
        if (v5 == *(_DWORD *)(*((_DWORD *)cg + 9) + 216)) {
          if (*(_DWORD *)v3 &&
              CG_DObjGetViewModelTagPos(*(DObj_s **)v3,
                                        (unsigned __int16)word_195B10C, v8))
            return CG_PlaySoundAlias(*(float **)a1->nextState, v8,
                                     *((snd_alias_list_t **)v3 + 55));
        }
        else {
          ClientDObj = Com_GetClientDObj(v5, a1->localClientNum);
          if (ClientDObj &&
              CG_DObjGetWorldTagPos(a1, ClientDObj,
                                    (unsigned __int16)word_195B10C, v8))
            return CG_PlaySoundAlias(*(float **)a1->nextState, v8,
                                     *((snd_alias_list_t **)v3 + 55));
        }
      BG_EvaluateTrajectory((const trajectory_t *)&a1->nextState[12],
                            *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)v6), v8);
      return CG_PlaySoundAlias(*(float **)a1->nextState, v8,
                               *((snd_alias_list_t **)v3 + 55));
    }
  return result;
}

bool __cdecl CG_IsOffHandDisplayVisible(void)
{
  UNIMPLEMENTED();
}

int __cdecl CG_CalcOffHandAmmo(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_OffHandFlash(float const *const, float *const)
{
  UNIMPLEMENTED();
}

int __cdecl CG_GetBestOffhand(int)
{
  UNIMPLEMENTED();
}
