
struct Picmip
{
  short platform;
};

struct CardMemory
{
  int64_t platform;
};

union GfxTexture
{
  int basemap;
  int map;
  int volmap;
  int cubemap;
  int loadDef;
};

struct GfxImage
{
  D3DRESOURCETYPE mapType;
  GfxTexture texture;
  Picmip picmip;
  char semantic;
  char noPicmip;
  char track;
  char pad0[3];
  CardMemory cardMemory;
  short width;
  short height;
  short depth;
  char category;
  char pad1[1];
  int name;
};

struct GfxImageLoadDef
{
  char format;
  char flags;
  char dimensions[6];
  int data;
  int resourceSize;
};