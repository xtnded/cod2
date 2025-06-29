void __cdecl R_UnregisterDvars() { return unk_118073C(0x2000); }

void __cdecl R_RegisterDvars() {
  int result; // eax

  R_RegisterSunDvars();
  r_ignore = unk_118071C("r_ignore", 0, 0x80000000, 0x7FFFFFFF, 0x2000);
  r_overbrightBits = unk_118071C("r_overbrightBits", 1, 0, 1, 8225);
  r_gamma = unk_1180720("r_gamma", 1065353216, 1056964608, 1077936128, 8193);
  r_ignoreHwGamma = unk_1180718("r_ignorehwgamma", 0, 8225);
  r_textureMode = dword_1180728("r_textureMode", &textureModeNames, 2, 8193);
  r_anisotropy = unk_118071C("r_anisotropy", 8, 2, 16, 8193);
  r_fullbright = unk_1180718("r_fullbright", 0, 8320);
  r_debugShader = dword_1180728("r_debugShader", &debugShaderNames, 0, 8320);
  r_debugEntCounts = unk_118071C("r_debugEntCounts", 0, 0, 2046, 0x2000);
  r_optimize = unk_1180718("r_optimize", 1, 8224);
  r_optimizeLightmaps = unk_1180718("r_optimizeLightmaps", 1, 8224);
  r_optimizeXModels = unk_118071C("r_optimizeXModels", 100, 0, 1000, 8224);
  r_gpuSync = dword_1180728("r_gpuSync", &gpuSyncNames, 3, 0x2000);
  r_multiGpu = unk_1180718("r_multiGpu", 0, 0x2000);
  r_skinCache = unk_1180718("r_skinCache", 1, 0x2000);
  r_smc_enable = unk_1180718("r_smc_enable", 1, 0x2000);
  r_lodScale =
      unk_1180720("r_lodScale", 1065353216, 1065353216, 1082130432, 8193);
  r_lodBias = unk_1180720("r_lodBias", 0, -998637568, 0, 8193);
  r_znear = unk_1180720("r_znear", 1082130432, 981668463, 1098907648, 8320);
  r_znear_depthhack =
      unk_1180720("r_znear_depthhack", 1036831949, 981668463, 1098907648, 8320);
  r_zfar = unk_1180720("r_zfar", 0, 0, 2139095039, 8320);
  r_fog = unk_1180718("r_fog", 1, 8320);
  r_polygonOffsetScale = unk_1180720("r_polygonOffsetScale", -1082130432,
                                     -1065353216, 1082130432, 8193);
  r_polygonOffsetBias = unk_1180720("r_polygonOffsetBias", -1082130432,
                                    -1048576000, 1098907648, 8193);
  r_picmip_manual = unk_1180718("r_picmip_manual", 0, 8193);
  r_picmip = unk_118071C("r_picmip", 0, 0, 3, 8193);
  r_picmip_bump = unk_118071C("r_picmip_bump", 0, 0, 3, 8193);
  r_picmip_spec = unk_118071C("r_picmip_spec", 0, 0, 3, 8193);
  r_lightMap = dword_1180728("r_lightMap", &colorMapNames, 0, 8320);
  r_colorMap = dword_1180728("r_colorMap", &colorMapNames, 0, 8320);
  r_normalMap = dword_1180728("r_normalMap", &normalMapNames, 0, 8320);
  r_specularMap = dword_1180728("r_specularMap", &colorMapNames, 0, 8320);
  r_specularColorScale = unk_1180720("r_specularColorScale", 1065353216,
                                     1008981770, 1120403456, 8320);
  r_cosinePowerMapShift =
      unk_1180720("r_cosinePowerMapShift", 0, -1082130432, 1065353216, 8320);
  r_showTris = unk_118071C("r_showTris", 0, 0, 2, 8320);
  r_showTriCounts = unk_1180718("r_showTriCounts", 0, 8320);
  r_showSurfCounts = unk_1180718("r_showSurfCounts", 0, 8320);
  r_showVertCounts = unk_1180718("r_showVertCounts", 0, 8320);
  r_xdebug = dword_1180728("r_xdebug", &xdebugNames, 0, 8320);
  r_railCoreWidth =
      unk_1180720("r_railCoreWidth", 1065353216, 0, 1098907648, 8193);
  r_vc_makelog = unk_118071C("r_vc_makelog", 0, 0, 2, 8224);
  r_vc_showlog = unk_118071C("r_vc_showlog", 0, 0, 1024, 0x2000);
  r_showLightGrid = unk_1180718("r_showLightGrid", 0, 8320);
  r_showMissingLightGrid = unk_1180718("r_showMissingLightGrid", 0, 8320);
  r_lightTweakAmbient =
      unk_1180720("r_lightTweakAmbient", 1036831949, 0, 1082130432, 8704);
  r_lightTweakDiffuseFraction = unk_1180720("r_lightTweakDiffuseFraction",
                                            1056964608, 0, 1065353216, 8704);
  r_lightTweakSunLight =
      unk_1180720("r_lightTweakSunLight", 1065353216, 0, 1082130432, 8704);
  r_lightTweakAmbientColor = unk_118072C("r_lightTweakAmbientColor", 1065353216,
                                         0, 0, 1065353216, 8704);
  r_lightTweakSunColor =
      unk_118072C("r_lightTweakSunColor", 0, 1065353216, 0, 1065353216, 8704);
  r_lightTweakSunDiffuseColor = unk_118072C("r_lightTweakSunDiffuseColor", 0, 0,
                                            1065353216, 1065353216, 8704);
  r_lightTweakSunDirection = unk_1180734("r_lightTweakSunDirection", 0, 0, 0,
                                         -1011613696, 1135869952, 8704);
  r_objectiveColorDx7Min = unk_118072C("r_objectiveColorDx7Min", 1057803469,
                                       1052938076, 0, 1065353216, 0x2000);
  r_objectiveColorDx7Max =
      unk_118072C("r_objectiveColorDx7Max", 1065353216, 1060320051, 1045220557,
                  1065353216, 0x2000);
  r_logFile = unk_118071C("r_logFile", 0, 0, 0x7FFFFFFF, 0x2000);
  r_skipBackEnd = unk_1180718("r_skipBackEnd", 0, 8320);
  r_norefresh = unk_1180718("r_norefresh", 0, 8320);
  r_swapInterval = unk_1180718("r_swapInterval", 0, 8225);
  r_aaAlpha = dword_1180728("r_aaAlpha", &s_aaAlphaNames, 1, 8193);
  r_aaSamples = unk_118071C("r_aaSamples", 1, 1, 4, 8225);
  r_clearColor = unk_118072C("r_clearColor", 0, 0, 0, 0, 0x2000);
  r_clearColor2 = unk_118072C("r_clearColor2", 0, 0, 0, 0, 0x2000);
  r_drawSun = unk_1180718("r_drawSun", 1, 8193);
  r_drawWorld = unk_1180718("r_drawWorld", 1, 8320);
  r_drawDecals = unk_1180718("r_drawDecals", 1, 8320);
  r_drawEntities = unk_1180718("r_drawEntities", 1, 8320);
  r_drawBModels = unk_1180718("r_drawBModels", 1, 8320);
  r_drawSModels = unk_1180718("r_drawSModels", 1, 8320);
  r_drawXModels = unk_1180718("r_drawXModels", 1, 8320);
  r_dlightLimit = unk_118071C("r_dlightLimit", 4, 0, 32, 0x2000);
  r_drawPrimCap = unk_118071C("r_drawPrimCap", 0, -1, 10000, 8320);
  r_drawPrimFloor = unk_118071C("r_drawPrimFloor", 0, 0, 10000, 8320);
  r_drawWater = unk_1180718("r_drawWater", 1, 8320);
  r_depthPrepassModels = unk_1180718("r_depthPrepassModels", 0, 0x2000);
  r_lockPvs = unk_1180718("r_lockPvs", 0, 8320);
  r_skipPvs = unk_1180718("r_skipPvs", 0, 8320);
  r_pvsStats = unk_1180718("r_pvsStats", 0, 0x2000);
  r_portalFineCull = unk_1180718("r_portalFineCull", 1, 8320);
  r_portalBevels =
      unk_1180720("r_portalBevels", 1060320051, 0, 1065353216, 8193);
  r_portalBevelsOnly = unk_1180718("r_portalBevelsOnly", 0, 0x2000);
  r_singleCell = unk_1180718("r_singleCell", 0, 8320);
  r_portalWalkLimit = unk_118071C("r_portalWalkLimit", 0, 0, 100, 8320);
  r_portalMinClipArea =
      unk_1180720("r_portalMinClipArea", 1017370378, 0, 1065353216, 0x2000);
  r_showPortals = unk_118071C("r_showPortals", 0, 0, 3, 8320);
  r_showSModelNames = unk_1180718("r_showSModelNames", 0, 8320);
  r_showFbColorDebug =
      dword_1180728("r_showFbColorDebug", &fbColorDebugNames, 0, 8320);
  r_showFloatZDebug = unk_1180718("r_showFloatZDebug", 0, 8320);
  r_showGroundLit = unk_1180718("r_showGroundLit", 0, 8352);
  r_highLodDist =
      unk_1180720("r_highLodDist", -1082130432, -1082130432, 2139095039, 8320);
  r_mediumLodDist = unk_1180720("r_mediumLodDist", -1082130432, -1082130432,
                                2139095039, 8320);
  r_lowLodDist =
      unk_1180720("r_lowLodDist", -1082130432, -1082130432, 2139095039, 8320);
  r_lowestLodDist = unk_1180720("r_lowestLodDist", -1082130432, -1082130432,
                                2139095039, 8320);
  r_forceLod = dword_1180728("r_forceLod", &r_forceLodNames, 4, 8320);
  sc_enable = unk_1180718("sc_enable", 1, 0x2000);
  sc_blur = unk_118071C("sc_blur", 2, 0, 4, 8320);
  sc_count = unk_118071C("sc_count", 24, 0, 24, 8320);
  sc_debugCasterCount = unk_118071C("sc_debugCasterCount", 24, 0, 24, 8320);
  sc_debugReceiverCount = unk_118071C("sc_debugReceiverCount", 24, 0, 24, 8320);
  sc_showOverlay = unk_1180718("sc_showOverlay", 0, 8320);
  sc_showDebug = unk_1180718("sc_showDebug", 0, 8320);
  sc_wantCount = unk_118071C("sc_wantCount", 12, 0, 24, 8320);
  sc_wantCountMargin = unk_118071C("sc_wantCountMargin", 1, 0, 24, 8320);
  sc_fadeRange = unk_1180720("sc_fadeRange", 1048576000, 0, 1065353216, 8320);
  sc_shadowInRate =
      unk_1180720("sc_shadowInRate", 0x40000000, 0, 1101004800, 8320);
  sc_shadowOutRate =
      unk_1180720("sc_shadowOutRate", 1084227584, 0, 1101004800, 8320);
  sc_length =
      unk_1180720("sc_length", 1137180672, 1065353216, 1157234688, 8320);
  sc_offscreenCasterLodBias =
      unk_1180720("sc_offscreenCasterLodBias", 0, -8388609, 2139095039, 8320);
  sc_offscreenCasterLodScale = unk_1180720("sc_offscreenCasterLodScale",
                                           1101004800, 0, 2139095039, 8320);
  r_blur = unk_1180720("r_blur", 0, 0, 1107296256, 8320);
  r_distortion = unk_1180718("r_distortion", 1, 8193);
  r_glow = unk_1180718("r_glow", 1, 8193);
  r_glowRadius[0] =
      unk_1180720("r_glowRadius0", 1084227584, 0, 1107296256, 0x2000);
  dword_117D66C =
      unk_1180720("r_glowRadius1", 1094713344, 0, 1107296256, 0x2000);
  r_glowSkyBleedIntensity[0] = unk_1180720("r_glowSkyBleedIntensity0",
                                           1056964608, 0, 1065353216, 0x2000);
  dword_117D664 =
      unk_1180720("r_glowSkyBleedIntensity1", 0, 0, 1065353216, 0x2000);
  r_glowBloomIntensity[0] =
      unk_1180720("r_glowBloomIntensity0", 1065353216, 0, 1090519040, 0x2000);
  dword_117D65C =
      unk_1180720("r_glowBloomIntensity1", 1065353216, 0, 1090519040, 0x2000);
  r_glowBloomCutoff =
      unk_1180720("r_glowBloomCutoff", 1063675494, 0, 1065353216, 0x2000);
  r_glowBloomDesaturation =
      unk_1180720("r_glowBloomDesaturation", 1061158912, 0, 1065353216, 0x2000);
  r_outdoorAwayBias = unk_1180720("r_outdoorAwayBias", 1107296256, -8388609,
                                  2139095039, 0x2000);
  r_outdoorDownBias =
      unk_1180720("r_outdoorDownBias", 0, -8388609, 2139095039, 0x2000);
  r_outdoorFeather =
      unk_1180720("r_outdoorFeather", 1090519040, -8388609, 2139095039, 0x2000);
  dword_118074C(r_outdoorFeather);
  r_sun_from_dvars = unk_1180718("r_sun_from_dvars", 0, 8320);
  r_testTransform = unk_118071C("r_testTransform", 0, 0, 1, 0x2000);
  r_testFill = unk_118071C("r_testFill", 0, 0, 500, 0x2000);
  r_testFillEnable = unk_1180718("r_testFillEnable", 0, 8224);
  fx_sort = unk_1180718("fx_sort", 1, 0x2000);
  vid_xpos = unk_118071C("vid_xpos", 3, -4096, 4096, 8193);
  vid_ypos = unk_118071C("vid_ypos", 22, -4096, 4096, 8193);
  developer = unk_118071C("developer", 0, 0, 2, 0x2000);
  sv_cheats = unk_1180718("sv_cheats", 0, 8264);
  com_statmon = unk_1180718("com_statmon", 0, 0x2000);
  sys_SSE = unk_1180718("sys_SSE", 0, 0x2000);
  r_sse_skinning = unk_1180718("r_sse_skinning", 1, 0x2000);
  r_fullscreen = unk_1180718("r_fullscreen", 1, 8256);
  r_monitor = unk_118071C("r_monitor", 0, 0, 8, 8225);
  r_rendererPreference =
      dword_1180728("r_rendererPreference", &s_technologyNames, 0, 8225);
  r_rendererInUse =
      dword_1180728("r_rendererInUse", &s_technologyNames, 0, 8256);
  result = dword_1180728("r_aspectRatio", &s_aspectRatioNames, 0, 8225);
  r_aspectRatio = result;
  return result;
}

struct dvar_s const *const r_lightTweakDiffuseFraction;
struct dvar_s const *const r_norefresh;
struct dvar_s const *const r_lightTweakSunLight;
struct dvar_s const *const sc_offscreenCasterLodBias;
struct dvar_s const *const r_outdoorAwayBias;
struct dvar_s const *const sc_length;
struct dvar_s const *const r_zfar;
struct dvar_s const *const sc_shadowInRate;
struct dvar_s const *const r_lodBias;
struct dvar_s const *const r_gamma;
struct dvar_s const *const r_lowestLodDist;
struct dvar_s const *const r_specularColorScale;
struct dvar_s const *const r_showTriCounts;
struct dvar_s const *const sc_debugReceiverCount;
struct dvar_s const *const r_textureMode;
struct dvar_s const *const r_drawEntities;
struct dvar_s const *const r_distortion;
struct dvar_s const *const r_drawBModels;
struct dvar_s const *const r_drawXModels;
struct dvar_s const *const r_drawDlights;
struct dvar_s const *const r_singleCell;
struct dvar_s const *const r_overbrightBits;
struct dvar_s const *const vid_ypos;
struct dvar_s const *const r_ignore;
struct dvar_s const *const r_polygonOffsetScale;
struct dvar_s const *const r_znear_depthhack;
struct dvar_s const *const r_cosinePowerMapShift;
struct dvar_s const *const r_drawSun;
struct dvar_s const *const r_portalWalkLimit;
struct dvar_s const *const r_lodScale;
struct dvar_s const *const r_zFeather;
struct dvar_s const *const r_smp_backend;
struct dvar_s const *const r_polygonOffsetBias;
struct dvar_s const *const r_lowLodDist;
struct dvar_s const *const r_portalBevels;
struct dvar_s const *const r_drawWorld;
struct dvar_s const *const r_railCoreWidth;
struct dvar_s const *const r_debugShader;
struct dvar_s const *const r_outdoorFeather;
struct dvar_s const *const r_drawPrimCap;
struct dvar_s const *const r_optimizeLightmaps;
struct dvar_s const *const vid_xpos;
struct dvar_s const *const r_fullbright;
struct dvar_s const *const r_vc_makelog;
struct dvar_s const *const r_lightTweakAmbientColor;
struct dvar_s const *const r_aaSamples;
struct dvar_s const *const r_showPortals;
struct dvar_s const *const r_showTris;
struct dvar_s const **r_glowBloomIntensity;
struct dvar_s const *const r_anisotropy;
int marker_r_dvars;
struct dvar_s const *const r_ignoreHwGamma;
struct dvar_s const *const r_dlightLimit;
struct dvar_s const *const r_specularMap;
struct dvar_s const *const r_lockPvs;
struct dvar_s const *const r_tiling;
struct dvar_s const *const r_lightMap;
struct dvar_s const *const sc_wantCount;
struct dvar_s const *const r_glow;
struct dvar_s const *const r_optimize;
struct dvar_s const *const r_mediumLodDist;
struct dvar_s const *const r_lightTweakSunDirection;
struct dvar_s const *const sc_wantCountMargin;
struct dvar_s const *const sc_showOverlay;
struct dvar_s const *const r_d3dSingleStepper;
struct dvar_s const *const sc_offscreenCasterLodScale;
struct dvar_s const *const r_showSModelNames;
struct dvar_s const *const r_lightTweakAmbient;
struct dvar_s const **r_glowSkyBleedIntensity;
struct dvar_s const *const r_depthPrepassModels;
struct dvar_s const *const r_testTransform;
struct dvar_s const *const r_skipBackEnd;
struct dvar_s const *const r_showFbColorDebug;
struct dvar_s const *const r_showMissingLightGrid;
struct dvar_s const *const r_testFill;
struct dvar_s const *const r_drawSModels;
struct dvar_s const *const r_drawPrimFloor;
struct dvar_s const *const r_lightTweakSunDiffuseColor;
struct dvar_s const *const sc_fadeRange;
struct dvar_s const *const r_showSurfCounts;
struct dvar_s const *const r_lightTweakSunColor;
struct dvar_s const *const r_clearColor2;
struct dvar_s const *const r_smc_enable;
struct dvar_s const *const r_glowBloomCutoff;
struct dvar_s const *const r_portalMinClipArea;
struct dvar_s const *const r_skipPvs;
struct dvar_s const *const sc_showDebug;
struct dvar_s const *const r_drawWater;
struct dvar_s const *const r_clearColor;
struct dvar_s const *const r_testFillEnable;
struct dvar_s const *const r_colorMap;
struct dvar_s const *const r_blur;
struct dvar_s const *const sc_count;
struct dvar_s const **r_glowRadius;
struct dvar_s const *const r_showFloatZDebug;
struct dvar_s const *const r_drawDecals;
struct dvar_s const *const sc_enable;
struct dvar_s const *const r_xdebug;
struct dvar_s const *const r_vc_showlog;
struct dvar_s const *const sc_shadowOutRate;
struct dvar_s const *const developer;
struct dvar_s const *const r_pretess;
struct dvar_s const *const r_highLodDist;
struct dvar_s const *const r_forceLod;
struct dvar_s const *const r_logFile;
struct dvar_s const *const r_normalMap;
struct dvar_s const *const r_outdoorDownBias;
struct dvar_s const *const r_portalFineCull;
struct dvar_s const *const r_showVertCounts;
struct dvar_s const *const r_portalBevelsOnly;
struct dvar_s const *const sc_debugCasterCount;
struct dvar_s const *const r_znear;
struct dvar_s const *const r_showLightGrid;
struct dvar_s const *const r_pvsStats;
struct dvar_s const *const r_debugEntCounts;
struct dvar_s const *const r_fog;
struct dvar_s const *const r_altivec_skinning;
struct dvar_s const *const r_smp_frontend;
struct dvar_s const *const r_glowBloomDesaturation;
struct dvar_s const *const sc_blur;
