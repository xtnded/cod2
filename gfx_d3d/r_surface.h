
struct GfxSceneEntity
{
  int refCount;
  GfxModel u;
  int cent;
  int cullState;
  int surfCount;
  char curMins[12];
  char curMaxs[12];
  int materials;
  int surfs;
};

typedef enum
{
  SF_BAD = 0,
  SF_POLY = 1,
  SF_ENTITY = 2,
  SF_XMODEL_SKINNED = 3,
  SF_XMODEL_RIGID = 4,
  SF_STATICMODEL_CACHED = 5,
  SF_TRIANGLES = 6,
  SF_RAW_GEOMETRY = 7,
  SF_NUM_SURFACE_TYPES = 8,
  SF_MAX = 4294967295
} surfaceType_t;

struct GfxBrushModel
{
  char bounds[24];
  int surfaceCount;
  int startSurfIndex;
};

struct GfxDrawSurf
{
  int sort;
  int surface;
};

struct GfxModelSurface
{
  int surfType;
  int xsurf;
};

struct GfxSurface
{
  int material;
  short lightmapIndex;
  short sortGroup;
};

union _3707
{
  int data;
  int tris;
};

struct srfTriangles_t
{
  int surfaceType;
  char bounds[24];
  int firstVertex;
  short vertexCount;
  short indexCount;
  int indices;
};

struct srfPoly_t
{
  int surfaceType;
  int material;
  short lmapIndex;
  short vertCount;
  int verts;
};

struct PointLightPartition
{
  int light;
  int firstDrawSurf;
  int drawSurfCount;
};

struct GfxStaticModelInstance
{
  int cullDist;
  char origin[12];
  int model;
  char mins[12];
  char maxs[12];
  char axis[36];
  int scale;
  char baseLightingCoords[12];
};