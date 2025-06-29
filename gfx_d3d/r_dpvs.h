
struct mnode_t {
  int contents;
  int parent;
  int cellIndex;
  mnode_info_t u;
};

struct GfxCullGroup {
  char mins[12];
  char maxs[12];
  int surfaceCount;
  int startSurfIndex;
};

struct GfxCell {
  GfxCellWritable writable;
  char mins[12];
  char maxs[12];
  int aabbTree;
  int portalCount;
  int portals;
  int cullGroupCount;
  int cullGroups;
  int occluderCount;
  int occluders;
  int modelRefs;
};

struct MaterialMemory {
  int material;
  int memory;
};

union mnode_info_t {
  mnode_node_t node;
  mnode_leaf_t leaf;
};

struct GfxCellWritable {
  int markCount;
};

struct GfxLightGridPoint {
  int xyzHighBits;
  char xyzLowBitsAndSunVisible;
  char needsTrace;
  short colorsIndex;
};

struct GfxLightGridColors {
  char rgb[24];
};

struct mnode_node_t {
  int plane;
  int64_t children;
};

struct mnode_leaf_t {
  int cluster;
};

struct GfxAabbTree {
  char mins[12];
  char maxs[12];
  int surfaceCount;
  int startSurfIndex;
  int staticModelCount;
  int staticModels;
  int childCount;
  int children;
};

struct GfxPortal {
  GfxPortalWritable writable;
  DpvsPlane plane;
  int cell;
  int vertices;
  char vertexCount;
  char hullPointCount;
  char pad0[2];
  int hullPoints;
  char hullAxis[24];
};

struct GfxSceneModelCellRef {
  int entIndex;
  char mins[12];
  char maxs[12];
  int next;
};

struct GfxPortalWritable {
  char isQueued;
  char isAncestor;
  char pad0[2];
  int queuedParent;
};

struct DpvsPlane {
  char coeffs[16];
  char side[3];
  DpvsPlaneInfo u;
};

struct GfxOccluder {
  int planeCount;
  int planes;
  int edgeCount;
  int edges;
  int vertexCount;
  int vertices;
  int ignoreStackLevel;
  int viewPlaneCount;
  int viewPlanes;
};

union DpvsPlaneInfo {
  char frontal;
  char ignoreStackLevel;
};

struct GfxOccluderEdge {
  int64_t plane;
  int64_t vertex;
};