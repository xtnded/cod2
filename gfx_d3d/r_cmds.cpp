void __cdecl R_UnregisterCmds()
{
  unk_11807BC("r_applyPicmip");
  unk_11807BC("r_vc_stats");
  unk_11807BC("screenshot");
  unk_11807BC("screenshotJpeg");
  unk_11807BC("imagelist");
  unk_11807BC("reloadmaterialtextures");
  unk_11807BC("r_loadsun");
  unk_11807BC("r_savesun");
  unk_11807BC("r_smc_stats");
  return unk_11807BC("r_smc_flush");
}

void __cdecl R_RegisterCmds()
{
  unk_11807B8("screenshot", R_Cmd_Screenshot);
  unk_11807B8("screenshotJpeg", R_Cmd_ScreenshotJpeg);
  unk_11807B8("imagelist", R_ImageList_f);
  unk_11807B8("r_applyPicmip", R_Cmd_ApplyPicmip);
  unk_11807B8("reloadmaterialtextures", R_Cmd_ReloadMaterialTextures);
  unk_11807B8("r_loadsun", R_Cmd_LoadSun);
  unk_11807B8("r_savesun", R_Cmd_SaveSun);
  unk_11807B8("r_smc_stats", R_StaticModelCacheStats_f);
  return unk_11807B8("r_smc_flush", R_StaticModelCacheFlush_f);
}

int marker_r_cmds;

void __cdecl R_Cmd_ScreenshotJpeg(void)
{
  R_ScreenshotCommand(R_SCREENSHOT_JPG);
}

void __cdecl R_Cmd_Screenshot(void)
{
  R_ScreenshotCommand(R_SCREENSHOT_TGA);
}
