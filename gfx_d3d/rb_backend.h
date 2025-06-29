
struct GfxViewParms
{
  char origin[12];
  char axis[36];
  char viewport[24];
  char viewMatrix[64];
  char projectionMatrix[64];
  char viewProjectionMatrix[64];
  char inverseViewProjectionMatrix[64];
  int depthHackNearClip;
};

typedef enum
{
  SHADOW_NONE = 0,
  SHADOW_COOKIE = 1
} ShadowType;

struct GfxPostProcessParms
{
  int blurRadius;
  char isRenderingFullScreen;
};

struct GfxLight
{
  int def;
  char position[16];
  char color[12];
  GfxLightInfo u;
};

union GfxLightInfo
{
  GfxLightDir dir;
};

struct GfxLightDef
{
  GfxLightType type;
  GfxLightImage cookie;
  int64_t attenuation;
  int name;
};

struct GfxLightDir
{
  char ambientColor[12];
};

typedef enum
{
  GFX_LIGHT_TYPE_SUN = 0,
  GFX_LIGHT_TYPE_SKY = 1,
  GFX_LIGHT_TYPE_POINT = 2,
  GFX_LIGHT_TYPE_COUNT = 3
} GfxLightType;

struct GfxLightImage
{
  int image;
  char samplerState;
};

struct GfxScene
{
  int viewCount;
  GfxSceneDef def;
  int dlightCount;
  char dlights[1408];
  char dlightCulled[32];
  int drawSurfCount;
  int drawSurfs;
  int polyCount;
  char sceneEnts[106392];
  int sceneEntMaterialCount;
  char sceneMaterials[16384];
};

struct GfxSceneDef
{
  int time;
  int floatTime;
  int entityCount;
  int entities;
};

struct trXSkin_t
{
  int materialHandles;
};

union _3729
{
  int verts;
  int blends;
};

union _3664
{
  short b;
  short s;
};

union _3665
{
  short b;
  short s;
};

struct _3715
{
  int verts;
  int vertCount;
  int vertLimit;
  int polys;
  int polyCount;
  int polyLimit;
  int strings;
  int stringCount;
  int stringLimit;
  int externStrings;
  int externStringCount;
  int externMaxStringCount;
  int lines;
  int lineCount;
  int lineLimit;
  int externLines;
  int externLineCount;
  int externMaxLineCount;
  int plumes;
  int plumeCount;
  int plumeLimit;
};

struct GfxDebugPoly
{
  char color[16];
  int firstVert;
  int vertCount;
};

struct trDebugString_t
{
  char xyz[12];
  char color[16];
  int scale;
  char text[96];
};

struct trDebugLine_t
{
  char start[12];
  char end[12];
  char color[16];
  int depthTest;
};

struct GfxDebugPlume
{
  char origin[12];
  char color[16];
  int score;
  int startTime;
  int duration;
};

struct GfxCmdHeader
{
  short id;
  short byteCount;
};

typedef enum
{
  R_RENDERTARGET_FRAME_BUFFER = 0,
  R_RENDERTARGET_RESOLVED_POST_SUN = 1,
  R_RENDERTARGET_RESOLVED_SCENE = 2,
  R_RENDERTARGET_DYNAMICSHADOWS = 3,
  R_RENDERTARGET_SHADOWCOOKIE = 4,
  R_RENDERTARGET_SHADOWCOOKIE_BLUR = 5,
  R_RENDERTARGET_FLOAT_Z = 6,
  R_RENDERTARGET_SAVED_SCREEN = 7,
  R_RENDERTARGET_BLURRED_SCREEN = 8,
  R_RENDERTARGET_GLOW_0 = 9,
  R_RENDERTARGET_GLOW_1 = 10,
  R_RENDERTARGET_PINGPONG_0 = 11,
  R_RENDERTARGET_PINGPONG_1 = 12,
  R_RENDERTARGET_COUNT = 13,
  R_RENDERTARGET_NONE = 14
} GfxRenderTargetId;

struct GfxLodParms
{
  char origin[12];
  int scale;
  int bias;
};

struct GfxCmdDrawPoints
{
  int header;
  short pointCount;
  short size;
  char verts[16];
};

struct GfxPointVertex
{
  char xyz[12];
  int color;
};

struct GfxCmdDrawLines
{
  int header;
  short lineCount;
  short width;
  char verts[32];
};

struct GfxBackEndData
{
  int frameCount;
  int drawSurfCount;
  char drawSurfs[524288];
  int surfPos;
  char surfsBuffer[131072];
  int entityCount;
  char entities[949344];
  int polyCount;
  char polys[32768];
  int polyVertCount;
  char polyVerts[557056];
  int skinnedCacheVb;
  int viewParmCount;
  char viewParms[8300];
  GfxFog fogSettings;
  GfxCmdArray commands;
  char debugGlobals[84];
};

struct GfxFog
{
  GfxFogOffset techniqueOffset;
  int startTime;
  int finishTime;
  GfxColor color;
  int fogStart;
  int fogEnd;
  int density;
  char registered;
  char drawSky;
  char clearScreen;
};

struct GfxCmdArray
{
  char cmds[196608];
  int usedTotal;
  int usedCritical;
  int lastCmd;
};

struct SkinBuffers
{
  char matArrayBuf[8192];
};

struct r_vb_state_t
{
  int used;
  int total;
  int buffer;
};

typedef enum
{
  FOG_OFFSET_NONE = 0,
  FOG_OFFSET_LINEAR = 1,
  FOG_OFFSET_EXP = 2,
  FOG_OFFSET_COUNT = 3
} GfxFogOffset;

union _3714
{
  char dx7[12288];
  char dx9[32768];
};

struct DObjSkelMat_s
{
  char axis[48];
  char origin[16];
};

struct GfxSModelCachedVertexDx7
{
  char xyz[12];
  int color;
  int64_t texCoord;
};

struct GfxSModelCachedVertex
{
  char xyz[12];
  char normal[12];
  int color;
  int64_t texCoord;
  int baseLightingCoords;
  char binormal[12];
  char tangent[12];
};

struct GfxDebugFrameGlob
{
  int restoreCmdList;
  int restoreFrontEndDataOut;
  char restoreSkinnedCache;
  char pad0[3];
  char frontEndDataOut[2399596];
};

struct trStatistics_t
{
  int c_indexes;
  int c_fxIndexes;
  int c_viewIndexes;
  int c_shadowIndexes;
  int c_vertexes;
  int c_batches;
  int c_refents;
  int dc;
  Image_MemUsage c_imageUsage;
};

struct Image_MemUsage
{
  int total;
  int lightmap;
  int minspec;
};

struct refexport_t
{
  int Shutdown;
  int BeginRegistration;
  int RegisterModel;
  int RegisterInlineModel;
  int RegisterMaterial;
  int RegisterRawImage;
  int Material_IsDefault;
  int LoadWorld;
  int GetWorldBounds;
  int FinishLoadingModels;
  int SetIgnorePrecacheErrors;
  int GetIgnorePrecacheErrors;
  int GetMinSpecImageMemory;
  int GetMaterialName;
  int GetMaterialSubimageCount;
  int IsMaterialRefractive;
  int GetFarPlaneDist;
  int EndRegistration;
  int ClearScene;
  int DefaultVertexFrames;
  int AddPolyToScene;
  int AddLightToScene;
  int InterpretSunLightParseParams;
  int ResetSunLightParseParams;
  int SetCullDist;
  int SetFog;
  int SwitchFog;
  int ArchiveFogState;
  int ClearFogs;
  int SetSunLightOverride;
  int ResetSunLightOverride;
  int RenderScene;
  int BeginDelayedDrawing;
  int EndDelayedDrawing;
  int IssueDelayedDrawing;
  int ClearFlares;
  int SetMaterialColor;
  int DrawStretchPic;
  int DrawStretchPicRotate;
  int DrawStretchRaw;
  int DrawQuadPic;
  int DrawSprite;
  int BeginFrame;
  int EndFrame;
  int BeginDebugFrame;
  int EndDebugFrame;
  int EndView;
  int DoneRenderingViews;
  int SaveScreen;
  int BlendSavedScreen;
  int ClearScreen;
  int SetViewport;
  int MarkFragments;
  int ModelBounds;
  int TrackStatistics;
  int PickMaterial;
  int RegisterFont;
  int ResetImageAllocations;
  int FreeImageAllocations;
  int BeginCubemapShot;
  int EndCubemapShot;
  int SaveCubemapShot;
  int LightingFromCubemapShots;
  int LocateDebugStrings;
  int LocateDebugLines;
  int AddPlume;
  int ShutdownDebug;
  int UpdateColor;
  int NormalizedTextScale;
  int TextWidth;
  int TextHeight;
  int DrawText;
  int DrawTextInSpace;
  int ConsoleTextWidth;
  int DrawConsoleText;
  int DrawTextWithCursor;
  int DObjGetSurfMaterials;
  int DObjReplaceMaterial;
  int ParseSunLight;
  int Material_Duplicate;
  int DuplicateFont;
  char XModelAllowReadSurface;
  char pad0[3];
  int SyncRenderThread;
  int AbortRenderCommands;
  int IsGpuFenceFinished;
  int SyncGpu;
  int GpuWaited;
  int SetLodOrigin;
};

struct refimport_t
{
  int Printf;
  int Error;
  int Milliseconds;
  int Hunk_AllocInternal;
  int Hunk_AllocateTempMemoryInternal;
  int Z_MallocInternal;
  int Z_FreeInternal;
  int Hunk_AllocAlignInternal;
  int Z_VirtualReserveInternal;
  int Z_VirtualCommitInternal;
  int Z_VirtualDecommitInternal;
  int Z_VirtualFreeInternal;
  int Hunk_FreeTempMemory;
  int Hunk_ClearTempMemory;
  int Hunk_HideTempMemory;
  int Hunk_ShowTempMemory;
  int Hunk_AllocateTempMemoryHighInternal;
  int Hunk_ClearTempMemoryHigh;
  int Sys_DirectXFatalError;
  int Sys_ShowSplashWindow;
  int Sys_HideSplashWindow;
  int Sys_LoadingKeepAlive;
  int Dvar_RegisterBool;
  int Dvar_RegisterInt;
  int Dvar_RegisterFloat;
  int Dvar_RegisterString;
  int Dvar_RegisterEnum;
  int Dvar_RegisterColor;
  int Dvar_RegisterVec2;
  int Dvar_RegisterVec3;
  int Dvar_RegisterVec4;
  int Dvar_UnregisterSystem;
  int Dvar_ChangeResetValue;
  int Dvar_IsAtDefaultValue;
  int Dvar_ClearModified;
  int Dvar_SetModified;
  int Dvar_UpdateEnumDomain;
  int Dvar_SetBool;
  int Dvar_SetInt;
  int Dvar_SetFloat;
  int Dvar_SetString;
  int Dvar_SetColor;
  int Dvar_SetVec2;
  int Dvar_SetVec3;
  int Dvar_SetVec4;
  int Dvar_SetFromString;
  int Dvar_SetBoolByName;
  int Dvar_SetIntByName;
  int Dvar_SetFloatByName;
  int Dvar_SetStringByName;
  int Dvar_SetColorByName;
  int Dvar_SetVec2ByName;
  int Dvar_SetVec3ByName;
  int Dvar_SetVec4ByName;
  int Dvar_SetFromStringByName;
  int Dvar_GetBool;
  int Dvar_GetInt;
  int Dvar_GetFloat;
  int Dvar_GetString;
  int Dvar_GetVariantString;
  int Dvar_EnumToString;
  int Dvar_Reset;
  int Cmd_AddCommand;
  int Cmd_RemoveCommand;
  int Cmd_Argc;
  int Cmd_Argv;
  int Cbuf_ExecuteText;
  int Com_SaveDvarsToBuffer;
  int Com_LoadDvarsFromBuffer;
  int Com_GetBsp;
  int SEH_ReadCharFromString;
  int CL_UpdateDebugData;
  int CL_FlushDebugData;
  int StatMon_Warning;
  int FS_ReadFile;
  int FS_FreeFile;
  int FS_FOpenFileRead;
  int FS_ListFiles;
  int FS_FreeFileList;
  int FS_FileExists;
  int FS_WriteFile;
  int FS_FOpenFileByMode;
  int FS_FCloseFile;
  int FS_Read;
  int FS_Write;
  int CM_SaveLump;
  int CM_BoxTrace;
  int CM_BoxSightTrace;
  int CM_RayTriangleIntersect;
  int XModelPrecache;
  int XModelGetSurfaces;
  int XModelBad;
  int Hunk_OverrideDataForFile;
  int XModelGetNumLods;
  int XModelSetTestLods;
  int XModelGetLodForDist;
  int XModelGetLodOutDist;
  int XModelGetSurfaceName;
  int XModelGetName;
  int XModelGetFlags;
  int XModelNumBones;
  int XModelGetSkins;
  int XModelGetMemUsage;
  int XModelGetLodName;
  int XModelGetBasePose;
  int XModelGetBasePoseBone;
  int DObjBad;
  int DB_EnumXAssets;
  int DObjGetBounds;
  int DObjGetSurface;
  int DObjGetNumModels;
  int DObjGetNumSurfaces;
  int DObjGetSurfaces;
  int DObjGetPartBits;
  int DObjGetRotTransArray;
  int DObjSkelAreBonesUpToDate;
  int DObjGetMatOffset;
  int DObjGetModel;
  int DObjGetSurfaceName;
  int DObjCreate;
  int DObjGetAllocSkelSize;
  int DObjCreateSkel;
  int DObjCalcAnim;
  int DObjCalcSkel;
  int DObjNumBones;
  int DObjGetBoneInfo;
  int DObjGetLodForDist;
  int DObjGetLodOutDist;
  int DObjCompleteHierarchyBits;
  int DObjSetModel;
  int CIN_UploadCinematic;
  int CIN_PlayCinematic;
  int CIN_RunCinematic;
  int CG_DObjCalcPose;
  int CL_GetHudMsgIconMaterialName;
};

struct GfxGammaRamp
{
  char entries[512];
};

struct GfxWindowParms
{
  int hwnd;
  int hz;
  char fullscreen;
  char pad0[3];
  int x;
  int y;
  int width;
  int height;
  int tileCount;
  int aaSamples;
};

struct vidConfig_t
{
  int width;
  int height;
  int displayFrequency;
  int isFullscreen;
  int aspectRatioWindow;
  int aspectRatioPixel;
  int maxTextureSize;
  int maxTextureMaps;
  int maxTextureCoords;
  int maxActiveLights;
  char deviceSupportsGamma;
};

struct DxGlobals
{
  int hinst;
  int d3d9;
  int device;
  int adapterIndex;
  int backBufferFormat;
  int displayModeCount;
  char displayModes[4096];
  char resolutionNameTable[1028];
  char refreshRateNameTable[1028];
  char modeText[5120];
  int gpuSync;
  int multiSampleType;
  int multiSampleQuality;
  int sunSpriteSamples;
  char renderTargets[260];
  int singleSampleDepthStencilSurface;
  short cubemapShotRes;
  short cubemapShotPixelBorder;
  char deviceLost;
  char inScene;
  short feedbackWidth;
  short feedbackHeight;
  char pad0[2];
  int targetWindowIndex;
  int windowCount;
  char windows[16];
  int flushGpuQuery;
  int gpuSyncDelay;
  int gpuSyncAlreadyWaited;
  char flushGpuQueryIssued;
  char pad1[3];
  int anisotropy;
  int maxAnisotropy;
  int maxClipPlanes;
  char stencilTwoSided;
  char stencilWrap;
  char slopeScaleDepthBias;
  char canMipCubemaps;
  char hasBlendOp;
  char hasSeparateAlphaBlend;
  char hasTransparencyMsaa;
  char pad2[1];
  char dynamicIndexBufferPool[12];
  int dynamicIndexBuffer;
  char skinnedCacheVbPool[24];
  char dynamicVertexBufferPool[12];
  int dynamicVertexBuffer;
  int particleCloudVertexBuffer;
  int particleCloudIndexBuffer;
  int skinnedCacheLockAddr;
  int smodelCacheVb;
  int smodelCacheIndices;
  int dynamicBufferFrame;
  int tempSkinBuf;
  int tempSkinPos;
};

struct GfxRenderTarget
{
  int image;
  int colorSurface;
  int depthStencilSurface;
  int width;
  int height;
};

struct GfxWindowTarget
{
  int hwnd;
  int swapChain;
  int width;
  int height;
};

struct r_ib_state_t
{
  int used;
  int total;
  int buffer;
};

struct r_global_permanent_t
{
  int materialLoaded;
  int materialCount;
  char sortedMaterials[4096];
  int whiteImage;
  int blackImage;
  int identityNormalMapImage;
  int specularityImage;
  int lightmapWeightsImage;
  int64_t lightGridWeightsImage;
  int outdoorImage;
  int dlightDef;
  int defaultMaterial;
  int rawMaterial;
  int stencilPlaneMaterial;
  int whiteMaterial;
  int additiveMaterial;
  int pointMaterial;
  int lineMaterial;
  int clearAlphaStencilMaterial;
  int shadowClearMaterial;
  int shadowCookieOverlayMaterial;
  int shadowCookieBlurMaterial;
  int glareBlindMaterial;
  int normalFillMaterial;
  int alphaBlendFillMaterial;
  int alphaTestPassFillMaterial;
  int alphaTestFailFillMaterial;
  int additiveFillMaterial;
  int depthOnlyFillMaterial;
  int stencilOneSideKeepFillMaterial;
  int stencilOneSideRejectFillMaterial;
  int stencilTwoSideKeepFillMaterial;
  int stencilTwoSideRejectFillMaterial;
  int phongBumpFillMaterial;
  int phongBumpSpecFillMaterial;
  int colorChannelMixerMaterial;
  int frameColorDebugMaterial;
  int frameAlphaDebugMaterial;
  int rawImage;
  int world;
  int sunHalfAngleImage;
  int waterColorImage;
  int feedbackReplaceMaterial;
  int feedbackBlendMaterial;
  char symmetricFilterMaterial[32];
  int shellShockMaterial;
  int glowSetupMaterial;
  int glowApplySkyBleedMaterial;
  int glowApplyBloomMaterial;
  int savedScreenTime;
  char rawTexdef[12];
};

struct GfxWorld
{
  int name;
  int baseName;
  int nodeCount;
  int nodes;
  int surfaceCount;
  int surfaces;
  int skySurfCount;
  int skyStartSurfs;
  int skyImage;
  char skySamplerState;
  char pad0[3];
  int vertexCount;
  GfxWorldVertexData vd;
  SunLightParseParams sunParse;
  GfxLight sunLight;
  char sunColorFromBsp[12];
  int cullGroupCount;
  int cullGroups;
  int smodelCount;
  int smodelInsts;
  int cellCount;
  int cells;
  int lightmapCount;
  int lightmaps;
  int smodelLightingImage;
  char smodelLightingLookupScale[12];
  GfxLightGrid lightGrid;
  int smodelLightingColorTable;
  int smodelLightingSunVisTable;
  int modelCount;
  int models;
  char mins[12];
  char maxs[12];
  int checksum;
  int materialMemoryCount;
  int materialMemory;
  sunflare_t sun;
  char outdoorLookupMatrix[64];
  int outdoorImage;
};

struct GfxWorldVertexData
{
  int vertices;
  int worldVb;
};

struct SunLightParseParams
{
  char name[64];
  int ambientScale;
  char ambientColor[12];
  int diffuseFraction;
  int sunLight;
  char sunColor[12];
  char diffuseColor[12];
  char diffuseColorHasBeenSet;
  char pad0[3];
  char angles[12];
};

struct GfxLightGrid
{
  int pointCount;
  int points;
  int colorCount;
  int colors;
};

struct sunflare_t
{
  char hasValidData;
  char pad0[3];
  int spriteMaterial;
  int flareMaterial;
  int spriteSize;
  int flareMinSize;
  int flareMinDot;
  int flareMaxSize;
  int flareMaxDot;
  int flareMaxAlpha;
  int flareFadeInTime;
  int flareFadeOutTime;
  int blindMinDot;
  int blindMaxDot;
  int blindMaxDarken;
  int blindFadeInTime;
  int blindFadeOutTime;
  int glareMinDot;
  int glareMaxDot;
  int glareMaxLighten;
  int glareFadeInTime;
  int glareFadeOutTime;
  char sunFxPosition[12];
};

struct r_globals_t
{
  char registered;
  char forbidDelayLoadImages;
  char ignorePrecacheErrors;
  char pad0[1];
  char viewOrg[12];
  char viewDir[12];
  int frameCountInternal;
  int markCount;
  int totalImageMemory;
  char materialHashTable[4096];
  int sceneWaterMapSetupsCount;
  char sceneWaterMapSetups[1088];
  char fogSettings[160];
  int fogIndex;
  char sinTable[4096];
  char fftTrigTable[2048];
  char fftBitswap[1024];
  int modelDObj;
  char modelDObjBuf[100];
  int stats;
  GfxLodParms lodParms;
  int debugViewParms;
  int smodelDyncs;
  int surfaces;
  int cullGroups;
};

struct GfxStaticModelDynamic
{
  int viewCount;
  int staticSurfs;
};

struct GfxSurfaceDynamic
{
  int viewCount;
};

struct GfxCullGroupDynamic
{
  int viewCount;
};

struct GfxStaticSurface
{
  char cachedLods[16];
};

struct GfxStaticModelSurfaceCached
{
  int baseVertIndex;
  int smodelIndex;
  int xsurf;
  int surface;
};

struct DxTextureStageEnums
{
  int op;
  char arg[12];
};

struct DxTextureOpDecode
{
  int enumerant;
  int usedArgs;
};

struct GfxCodeMatrices
{
  int worldScale;
  char pad0[12];
  GfxCodeMatrix world;
  char normalizedWorld[272];
  char view[272];
  char projection[272];
  char worldView[272];
  char normalizedWorldView[272];
  char viewProjection[272];
  char worldViewProjection[272];
  char normalizedWorldViewProjection[272];
  char shadowLookupMatrix[272];
  char lightGridLookupMatrix[272];
  char worldOutdoorLookup[272];
  char OGLworldViewProjection[272];
};

struct GfxCodeMatrix
{
  char matrix[256];
  int valid;
};

struct GfxViewport
{
  int x;
  int y;
  int width;
  int height;
};

struct DxState
{
  char vertexShaderConsts[4096];
  char pixelShaderConsts[4096];
  int64_t refStateBits;
  int64_t activeStateBits;
  int stencilRefValue;
  char refColorStageBits[32];
  char refAlphaStageBits[32];
  char activeColorStageBits[32];
  char activeAlphaStageBits[32];
  char gridLighting;
  short genTexCoords;
  char pad0[1];
  int renderTargetId;
  int renderTargetWidth;
  int renderTargetHeight;
  GfxViewportBehavior viewportBehavior;
  int renderTargetSurface;
  int depthStencilSurface;
  char viewport[24];
  char viewportIsNull;
  char pad1[3];
  int indexBuffer;
  char streams[12];
  int indexBufferDeselecting;
  int vertexBufferDeselecting;
  char samplerState[16];
  char samplerImage[64];
  int textureColorArg;
  int pixelShader;
  int vertexShader;
  int vertexDecl;
  int fvf;
  char alphaRef;
  char pad2[3];
  int textureFactor;
  int ambientColor;
  int clipPlaneCount;
};

typedef enum
{
  GFX_USE_VIEWPORT_FOR_VIEW = 0,
  GFX_USE_VIEWPORT_FULL = 1
} GfxViewportBehavior;

struct _3726
{
  GfxColor color;
  D3DFOGMODE mode;
  int start;
  int end;
  int density;
};

struct _3725
{
  int vb;
  int offset;
  int stride;
};

typedef enum
{
  D3DFOG_NONE = 0,
  D3DFOG_EXP = 1,
  D3DFOG_EXP2 = 2,
  D3DFOG_LINEAR = 3,
  D3DFOG_FORCE_DWORD = 2147483647
} _D3DFOGMODE;

struct DxStencilDecode
{
  int shift;
  int renderState;
};

union XAssetHeader
{
  int parts;
  int model;
  int material;
  int image;
  int sound;
  int sndCurve;
  int clipMap;
  int world;
  int lightDef;
  int font;
  int menuList;
  int menu;
  int localize;
  int weapon;
  int sndDriverGlobals;
  int fx;
  int impactFx;
  int rawfile;
  int data;
};

typedef enum
{
  GFX_LOCK_BEGIN_FRAME = 0,
  GFX_LOCK_RESUME_FRAME = 1
} GfxLockType;

struct GfxModelSkinnedSurface
{
  GfxModelSurface surf;
  int skinnedCachedOffset;
};

union _3720
{
  int variant;
  int dx7;
  int dx9;
};

struct GfxVertexDx7
{
  char xyz[12];
  char normal[12];
  int color;
  int64_t texCoord;
};

struct GfxVertex
{
  char xyzw[16];
  char normal[12];
  int color;
  int64_t texCoord;
  char binormal[12];
  char tangent[12];
};

struct GfxModelRigidSurface
{
  int64_t surf;
  char boneAxis[48];
};

struct SkinXModelCmd
{
  int surfs;
  int e;
  int mat;
  char surfacePartBits[16];
  char surfCount;
  char boneCount;
  char matOffset[64];
};

struct SkinRigidXModelCmd
{
  int surfs;
  int surfCount;
  int e;
  char mat[32];
};

struct GfxStaticModelCachedSurface
{
  int64_t surf;
  int surface;
  int ent;
};

union _3732
{
  int v;
  int w;
};

union _3734
{
  int v;
  int w;
};

struct stream_source_info_t
{
  char Stream;
  char Offset;
  char Type;
};

struct stream_dest_info_t
{
  char Usage;
  char UsageIndex;
};

typedef enum
{
  MTL_VERTEX_SHADER = 0,
  MTL_PIXEL_SHADER = 1
} MaterialShaderType;

struct _3752
{
  int vertexDeclCount;
  char vertexDeclHashTable[768];
  int techniqueSetCount;
  char techniqueSetHashTable[4096];
  int techniqueCount;
  char techniqueHashTable[4096];
  int literalCount;
  char literalTable[256];
  int stateMapCount;
  char stateMapHashTable[128];
  int stringCount;
  char stringHashTable[256];
  int shaderCount;
  char shaderHashTable[1024];
};

struct BuiltInMaterialTable
{
  int name;
  int material;
};

struct GfxRenderCommandExecState
{
  int cmd;
  int stackPos;
  int64_t retCmd;
};

struct GfxCmdCall
{
  GfxCmdHeader header;
  int subCmd;
};

struct GfxCmdSetClipPlanes
{
  int header;
  int clipPlaneCount;
  char clipPlanes[16];
};

struct GfxCmdStretchRaw
{
  int header;
  int x;
  int y;
  int w;
  int h;
  int cols;
  int rows;
  int data;
  int client;
  int dirty;
};

struct GfxCmdClearScreen
{
  int header;
  char whichToClear;
  char stencil;
  char pad0[2];
  int depth;
  char color[16];
};

struct GfxCmdSetMaterialColor
{
  int header;
  char color[16];
};

struct GfxCmdSetLightProperties
{
  int header;
  int lightIndex;
  char position[16];
  char ambient[16];
  char color[16];
  char specular[16];
  int lightDef;
};

struct GfxCmdSetStencilRefValue
{
  int header;
  int refValue;
};

struct GfxCmdSetShadowCookie
{
  int header;
  char lookupMatrix[64];
  int fade;
};

struct GfxCmdBeginView
{
  int header;
  GfxSceneDef sceneDef;
  int viewParms;
  GfxLodParms lodParms;
  int viewCount;
};

struct GfxCmdSetViewport
{
  int header;
  char viewport[16];
};

struct GfxCmdSetRenderTarget
{
  int header;
  GfxRenderTargetId renderTargetId;
};

typedef enum
{
  GFX_DRAW_SURFS_ITER_FORWARD = 0,
  GFX_DRAW_SURFS_ITER_BACKWARD = 1
} GfxDrawSurfOrder;

struct GfxCmdDrawSurfs
{
  int header;
  int order;
  int drawSurfs;
  int drawSurfCount;
  int techType;
};

struct GfxCmdDrawSunPostEffects
{
  int header;
  int viewIndex;
};

struct GfxCmdDrawTriangles
{
  int header;
  int material;
  int techType;
  short indexCount;
  short vertexCount;
};

struct GfxCmdDrawSprite
{
  int header;
  int material;
  int rgbaColor;
  char pos[12];
  int radius;
  int minScreenRadius;
  int renderFxFlags;
};

struct GfxCmdDrawTextInSpace
{
  int header;
  char org[12];
  int font;
  char xPixelStep[12];
  char yPixelStep[12];
  int color;
  int text;
};

typedef enum
{
  GFX_PRIM_STATS_WORLD = 0,
  GFX_PRIM_STATS_SMODELCACHED = 1,
  GFX_PRIM_STATS_SMODELRIGID = 2,
  GFX_PRIM_STATS_XMODELCACHED = 3,
  GFX_PRIM_STATS_XMODELRIGID = 4,
  GFX_PRIM_STATS_XMODELSKINNED = 5,
  GFX_PRIM_STATS_BMODEL = 6,
  GFX_PRIM_STATS_FX = 7,
  GFX_PRIM_STATS_HUD = 8,
  GFX_PRIM_STATS_DEBUG = 9,
  GFX_PRIM_STATS_CODE = 10,
  GFX_PRIM_STATS_COUNT = 11
} GfxPrimStatsTarget;

struct GfxCmdStretchPic
{
  int header;
  int material;
  int x;
  int y;
  int w;
  int h;
  int s0;
  int t0;
  int s1;
  int t1;
  int color;
};

struct GfxCmdDrawFullScreenColoredQuad
{
  int header;
  int material;
  int s0;
  int t0;
  int s1;
  int t1;
  int color;
};

struct GfxCmdBlendSavedScreen
{
  int header;
  int fadeMsec;
  int material;
};

struct GfxCmdDrawText
{
  int header;
  int x;
  int y;
  int font;
  int xScale;
  int yScale;
  int color;
  int style;
  int cursorPos;
  char cursor;
  char pad0[3];
  int maxChars;
  char text[3];
};

struct GfxCmdApplyLatePostEffects
{
  int header;
  int blurRadius;
};

struct GfxCmdStretchPicRotate
{
  int header;
  int material;
  int x;
  int y;
  int w;
  int h;
  int s0;
  int t0;
  int s1;
  int t1;
  int color;
  int rotation;
};

struct GfxCmdDrawQuadPic
{
  int header;
  int material;
  char verts[32];
  int color;
};

struct GfxCmdStencilPlanes
{
  int header;
  int nearDist;
  int planeCount;
  int planeDists;
};

struct materialCommands_t
{
  char pad0[370608];
  int indices;
  int optimizedIndices;
  GfxOptimizedVertexSource optimizedVertexSource;
  int material;
  int techType;
  int lmapIndex;
  int materialTime;
  MaterialVertexDeclType declType;
  int indexCount;
  int vertexCount;
  int firstVertex;
  int lastVertex;
  int optimizedIndexCount;
  int optimizedVertexCount;
  int firstOptimizedVertex;
};

union _3718
{
};

typedef enum
{
  OPT_VERTS_NONE = 0,
  OPT_VERTS_WORLD = 1,
  OPT_VERTS_SMC = 2,
  OPT_VERTS_COUNT = 3
} GfxOptimizedVertexSource;

typedef enum
{
  VERTDECL_GENERIC = 0,
  VERTDECL_WORLD = 1,
  VERTDECL_POS_TEX = 2,
  VERTDECL_STATICMODELCACHE = 3,
  VERTDECL_COUNT = 4
} MaterialVertexDeclType;

union _3719
{
  char generic[348800];
  char world[370600];
};

struct GfxWorldVertexDx7
{
  char xyz[12];
  int color;
  int64_t texCoord;
  int64_t lmapCoord;
};

struct r_backEndGlobals_t
{
  char codeConsts[944];
  int frameCount;
  int viewCount;
  char sceneDef[16];
  int viewParms;
  char lodParms[20];
  char sceneViewport[16];
  char viewProjectionMatrix[64];
  int tileIndex;
  int tileCount;
  int width;
  int height;
  int currentEntity;
  int currentEntityLighting;
  char worldEntity[116];
  char viewportIsDirty;
  char projection2D;
  char defaultSamplerState;
  char pad0[1];
  int color_axis;
  int color_allies;
  int fogColor;
  int glowIndexFirst;
  int glowCount;
  int64_t glowImage;
  int texScrollAmountDx7;
  char codeMatrixStack[10656];
  int codeMatrixStackLevel;
  int resolvedPostSunTarget;
  int resolvedSceneTarget;
  int currentFeedbackImage;
  char light[136];
  char entityLighting[212784];
  char shadowLookupMatrix[64];
  int debugFont;
};

struct GfxEntityLighting
{
  int viewCount;
  int sunVisibility;
  char colorForDir[96];
};

struct GfxBackEndLightSettings
{
  char position[16];
  char ambient[16];
  char color[16];
  char specular[16];
  int def;
};

struct DebugGlobals
{
  int verts;
  int vertCount;
  int vertLimit;
  int polys;
  int polyCount;
  int polyLimit;
  int strings;
  int stringCount;
  int stringLimit;
  int externStrings;
  int externStringCount;
  int externMaxStringCount;
  int lines;
  int lineCount;
  int lineLimit;
  int externLines;
  int externLineCount;
  int externMaxLineCount;
  int plumes;
  int plumeCount;
  int plumeLimit;
};

struct SunFlareDynamic
{
  int flareIntensity;
  int currentBlind;
  int currentGlare;
  int lastTime;
  char error;
  char pad0[3];
  int cumulVisibility;
  int lastVisibility;
  int lastDot;
  int hitNum;
  int64_t sunQuery;
  short sunQueryIssued;
};