
struct XSurface_s {
  char tileMode;
  char pad0[1];
  short vertCount;
  short triCount;
  short boneOffset;
  int triIndices;
  int verts;
  XRigidSurface surfRigid;
  int indexBuffer;
};

struct XRigidSurface {
  int vb;
};

struct XVertexBuffer {
  XVertexInfo v;
  char w[16];
};

struct XVertexInfo_s {
  char normal[12];
  int color;
  char binormal[12];
  int texCoordX;
  char tangent[12];
  int texCoordY;
  char offset[12];
  char numWeights;
  char boneWeight;
  short boneOffset;
};

struct XBlendInfo_s {
  char offset[12];
  short boneOffset;
  short boneWeight;
};