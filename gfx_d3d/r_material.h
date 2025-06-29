
struct Material
{
  MaterialInfo info;
  int64_t stateBits;
  short textureCount;
  short constantCount;
  int techniqueSet;
  int textures;
  int constants;
};

struct MaterialInfoObj_s
{
  int name;
  int refImageName;
  short hashIndex;
  short sortedIndex;
  char gameFlags;
  char sortKey;
  char textureAtlasRowCount;
  char textureAtlasColumnCount;
  int maxDeformMove;
  char deformFlags;
  char usage;
  short toolFlags;
  int locale;
  short autoTexScaleWidth;
  short autoTexScaleHeight;
  int tessSize;
  int surfaceFlags;
  int contents;
};

struct MaterialTechniqueSet
{
  int name;
  char techniques[136];
};

struct MaterialTextureDef
{
  int name;
  char samplerState;
  char semantic;
  char unused_0;
  char unused_1;
  MaterialTextureDefInfo u;
};

union MaterialTextureDefInfo
{
  int image;
  int water;
};

struct MaterialConstantDefObj
{
  int name;
  char literal[16];
};

struct MaterialTechnique
{
  int name;
  short flags;
  short passCount;
  MaterialPassArray passArray;
};

struct MaterialWaterDef
{
  int textureWidth;
  int horizontalWorldLength;
  int verticalWorldLength;
  int amplitude;
  int windSpeed;
  int64_t windDirection;
  int map;
};

union MaterialPassArray
{
  char dx7[92];
  char dx9[28];
};

struct water_t
{
  WaterWritable writable;
  int H0;
  int wTerm;
  int M;
  int N;
  int Lx;
  int Lz;
  int gravity;
  int windvel;
  int64_t winddir;
  int amplitude;
  char codeConstant[16];
  int image;
};

struct MaterialPassDx7
{
  int stateMap;
  char gridLighting;
  char projectToInfinity;
  char ambientLighting;
  char objectiveGlow;
  char fogToBlack;
  short genTexCoords;
  char pad0[1];
  char samplers[16];
  char colorStageBits[32];
  char alphaStageBits[32];
};

struct MaterialPassDx9
{
  int stateMap;
  int vertexDecl;
  int vertexShader;
  int pixelShader;
  short vertexArgCount;
  short pixelArgCount;
  int vertexArgs;
  int pixelArgs;
};

struct WaterWritable
{
  int frameCount;
};

struct MaterialStateMap
{
  int name;
  char ruleSet[44];
};

struct MaterialShaderArgument
{
  short type;
  short dest;
  MaterialArgumentDef u;
};

struct MaterialVertexDeclaration
{
  int data;
  int streamCount;
  char decl[16];
};

struct MaterialShader
{
  int name;
  int program;
  short programLen;
  char shaderType;
  char shaderVersion;
  MaterialShaderPtr u;
};

union MaterialArgumentDef
{
  int literalConst;
  MaterialArgumentCodeConst codeConst;
  int codeSampler;
  int name;
};

union MaterialShaderPtr
{
  int vs;
  int ps;
};

struct MaterialArgumentCodeConst
{
  short index;
  char firstRow;
  char rowCount;
};

struct MaterialStreamRouting
{
  char source;
  char dest;
};

struct MaterialStateMapRuleSet
{
  int ruleCount;
  char rules[32];
};

struct MaterialStateMapRule
{
  int64_t stateBitsMask;
  int64_t stateBitsValue;
  int64_t stateBitsSet;
  int64_t stateBitsClear;
};

typedef enum
{
  TECHNIQUE_DEPTH_PREPASS = 0,
  TECHNIQUE_SKY = 1,
  TECHNIQUE_BUILD_FLOAT_Z = 2,
  TECHNIQUE_FOGABLE_FIRST = 3,
  TECHNIQUE_UNLIT = 3,
  TECHNIQUE_UNLIT_FOG_LINEAR = 4,
  TECHNIQUE_UNLIT_FOG_EXP = 5,
  TECHNIQUE_LIGHTING_FIRST = 6,
  TECHNIQUE_LIGHTMAP = 6,
  TECHNIQUE_LIGHTMAP_FOG_LINEAR = 7,
  TECHNIQUE_LIGHTMAP_FOG_EXP = 8,
  TECHNIQUE_LIGHTPROBE_NOT_CACHED_FIRST = 9,
  TECHNIQUE_LIGHTPROBE = 9,
  TECHNIQUE_LIGHTPROBE_FOG_LINEAR = 10,
  TECHNIQUE_LIGHTPROBE_FOG_EXP = 11,
  TECHNIQUE_LIGHTPROBE_SMODEL = 12,
  TECHNIQUE_LIGHTPROBE_SMODEL_FOG_LINEAR = 13,
  TECHNIQUE_LIGHTPROBE_SMODEL_FOG_EXP = 14,
  TECHNIQUE_LIGHTPROBE_NOT_CACHED_LAST = 14,
  TECHNIQUE_LIGHTPROBE_SMODEL_CACHED = 15,
  TECHNIQUE_LIGHTPROBE_SMODEL_CACHED_FOG_LINEAR = 16,
  TECHNIQUE_LIGHTPROBE_SMODEL_CACHED_FOG_EXP = 17,
  TECHNIQUE_LIGHTING_LAST = 17,
  TECHNIQUE_POINTLIGHT = 18,
  TECHNIQUE_POINTLIGHT_FOG_LINEAR = 19,
  TECHNIQUE_POINTLIGHT_FOG_EXP = 20,
  TECHNIQUE_EMISSIVE = 21,
  TECHNIQUE_EMISSIVE_FOG_LINEAR = 22,
  TECHNIQUE_EMISSIVE_FOG_EXP = 23,
  TECHNIQUE_EMISSIVE_FEATHERED = 24,
  TECHNIQUE_EMISSIVE_FEATHERED_FOG_LINEAR = 25,
  TECHNIQUE_EMISSIVE_FEATHERED_FOG_EXP = 26,
  TECHNIQUE_FOGABLE_LAST = 26,
  TECHNIQUE_FAKELIGHT_NORMAL = 27,
  TECHNIQUE_FAKELIGHT_VIEW = 28,
  TECHNIQUE_WIREFRAME_SOLID = 29,
  TECHNIQUE_WIREFRAME_SHADED = 30,
  TECHNIQUE_SHADOWCOOKIE_CASTER = 31,
  TECHNIQUE_SHADOWCOOKIE_RECEIVER = 32,
  TECHNIQUE_DEBUG_BUMPMAP = 33,
  TECHNIQUE_COUNT = 34,
  TECHNIQUE_TOTAL_COUNT = 35,
  TECHNIQUE_NONE = -1
} MaterialTechniqueType;