void __cdecl CG_ScrollScoreboardDown()
{
  _DWORD *v0; // ecx
  int result; // eax

  v0 = cg;
  result = *((_DWORD *)cg + 44368);
    if (result) {
      *((_DWORD *)cg + 44367) += *(_DWORD *)(cg_scoreboardScrollStep + 8);
      result = v0[43968] - 1;
      if (v0[44367] > result)
        v0[44367] = result;
    }
  return result;
}

void __cdecl CG_ScrollScoreboardUp()
{
  UNIMPLEMENTED();
}

int __cdecl CG_ScoreboardDisplayed()
{
  return *((_DWORD *)cg + 44365);
}

bool __cdecl Scoreboard_HandleInputXboxLive(int)
{
  UNIMPLEMENTED();
}

bool __cdecl Scoreboard_HandleInputNonXboxLive(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_RegisterScoreboardGraphics()
{
  const char *String; // eax
  const char *v1;     // eax
  const char *v2;     // eax
  const char *v3;     // eax

  CL_RegisterMaterialNoMip("white", 7);
  CL_RegisterMaterialNoMip("white", 7);
  CL_RegisterMaterialNoMip("black", 7);
  CL_RegisterMaterialNoMip("white", 7);
  CL_RegisterMaterialNoMip("white", 7);
  CL_RegisterMaterialNoMip("black", 7);
  CL_RegisterMaterialNoMip("hudscoreboardscroll_uparrow", 7);
  CL_RegisterMaterialNoMip("hudscoreboardscroll_upkey", 7);
  CL_RegisterMaterialNoMip("hudscoreboardscroll_downarrow", 7);
  CL_RegisterMaterialNoMip("hudscoreboardscroll_downkey", 7);
  String = (const char *)Dvar_GetString("g_ScoresBanner_Spectators");
  CL_RegisterMaterialNoMip(String, 7);
  v1 = (const char *)Dvar_GetString("g_ScoresBanner_Axis");
  CL_RegisterMaterialNoMip(v1, 7);
  v2 = (const char *)Dvar_GetString("g_ScoresBanner_Allies");
  CL_RegisterMaterialNoMip(v2, 7);
  v3 = (const char *)Dvar_GetString("g_ScoresBanner_None");
  CL_RegisterMaterialNoMip(v3, 7);
  CL_RegisterMaterialNoMip("voice_on", 7);
  return CL_RegisterMaterialNoMip("voice_off", 7);
}

bool __cdecl Scoreboard_HandleInput(int)
{
  UNIMPLEMENTED();
}

int __cdecl CalcBorderLines(struct sbpicinfo_t *const backdropBorderLines)
{
  a1->x = 1123418112;
  a1->y = 1103626240;
  a1->w = 1136984064;
  a1->h = 0x40000000;
  a1[1].x = 1123418112;
  a1[1].y = 1138720768;
  a1[1].w = 1136984064;
  a1[1].h = 0x40000000;
  a1[2].x = 1123418112;
  a1[2].y = 1104674816;
  a1[2].w = 0x40000000;
  a1[2].h = 1137836032;
  a1[3].x = 1140899840;
  a1[3].y = 1104674816;
  a1[3].w = 0x40000000;
  a1[3].h = 1137836032;
  a1[4].x = 1123680256;
  a1[4].y = 1112276992;
  a1[4].w = 1136852992;
  a1[4].h = 1065353216;
  a1[5].x = 1123680256;
  a1[5].y = 1138229248;
  a1[5].w = 1136852992;
  a1[5].h = 1065353216;
  return 6;
}

void __cdecl CG_DrawScoreboard_GetTeamColor(int, float *const)
{
  float *v2;  // esi
  int v3;     // ebx
  int result; // eax

  v2 = a2 + 3;
  v3 = *((_DWORD *)a2 + 3);
    if (a1 == 1) {
      result = Dvar_GetUnpackedColorByName("g_TeamColor_Axis", a2);
      *(_DWORD *)v2 = v3;
    }
    else {
        if (a1 == 2) {
          result = Dvar_GetUnpackedColorByName("g_TeamColor_Allies", a2);
        }
        else {
          result = 1065353216;
          *a2 = 1.0;
          a2[1] = 1.0;
          a2[2] = 1.0;
        }
      *(_DWORD *)v2 = v3;
    }
  return result;
}

int __cdecl CG_DrawScoreboard()
{
  UNIMPLEMENTED();
}

bool __cdecl Scoreboard_IsValidInput(int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_GetScoreboardInfo(struct listColumnInfo_t const **, int *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_BackdropTop(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_BackdropLeft(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_BackdropHeight(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_BackdropWidth(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_BannerScoreboardScaleMultiplier(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_ScoreboardScaleMultiplier(void)
{
  UNIMPLEMENTED();
}

int __cdecl CG_CheckDrawScoreboardLine(int *, float, float)
{
  UNIMPLEMENTED();
}

float __cdecl CG_DrawScoreboard_ListHeight(int *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_ObjectiveLineHeight(void)
{
  UNIMPLEMENTED();
}

float __cdecl CG_ObjectiveFontScale(void)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawScrollbar(float *const, float, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawBackdropMapName(float, char const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawBackdropGameType(float, char const *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawBackdropMainBorders(float)
{
  UNIMPLEMENTED();
}

float __cdecl CG_DrawScoreboard_ListColumnHeaders(float *const, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawScoreboard_Controls(float, float, float, float)
{
  UNIMPLEMENTED();
}

float __cdecl CG_DrawScoreboard_ListBanner(float *const, float, float, float,
                                           int, int *)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawBackdropBackground(float)
{
  UNIMPLEMENTED();
}

float __cdecl CG_DrawClientScore(float *const, float, struct score_t *, float,
                                 int, int, int *, int)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawScoreboard_Backdrop(float)
{
  UNIMPLEMENTED();
}

float __cdecl CG_DrawTeamOfClientScore(float *const, float, int, float, int *,
                                       int *)
{
  UNIMPLEMENTED();
}

float __cdecl CG_DrawObjectiveInfo(float *const, float)
{
  UNIMPLEMENTED();
}

void __cdecl CG_DrawScoreboard_ScoresList(float)
{
  UNIMPLEMENTED();
}
