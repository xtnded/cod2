// 'Temporarily' Move what I assume to be all 'EffectsCore' related types into
// here, to be sorted later.

struct Effect {
  int Effect;
  char pad0[60];
  FxGfxEntity mRefEnt;
  int mFlags;
  int mClusterId;
  int mSortGroup;
  int mModel;
  int mTimeStart;
  int mTimeEnd;
  FxBoltFramePtr mBolt;
};

struct FxGfxEntity {
  int customMaterial;
  int rotation;
  char axis[36];
  char dlightColor[12];
  int materialTime;
  char origin[12];
  int64_t radius;
  int materialRGBA;
  int materialSubimageIndex;
  int scale;
  char endpos[12];
};

struct FxBoltFramePtr {};

struct FxArchive {};

struct EffectTemplate {
  int mEffectName;
  int mPrimitiveCount;
  char mPrimitives[96];
};

struct FxBoltFrame {
  char pad0[60];
  FxBoltInfo mBolt;
};

struct PrimitiveTemplate {
  char mName[32];
  char mMaterialImpact[32];
  PrimType mType;
  int mParentPrimIndex;
  FxRange mSpawnDelay;
  int64_t mSpawnCount;
  int64_t mLife;
  int64_t mSpawnRange;
  MediaHandles mMediaHandles;
  int64_t mImpactFxHandles;
  int64_t mDeathFxHandles;
  int64_t mEmitterFxHandles;
  int64_t mPlayFxHandles;
  int mAttributeFlags;
  int mSpawnFlags;
  int mGroupFlags;
  char mNonUniformScale;
  char useLength;
  char pad0[2];
  char mMin[12];
  char mMax[12];
  int64_t mOrigin1X;
  int64_t mOrigin1Y;
  int64_t mOrigin1Z;
  int64_t mOrigin2X;
  int64_t mOrigin2Y;
  int64_t mOrigin2Z;
  int64_t mRadius;
  int64_t mHeight;
  int64_t mWindModifier;
  char mFxChannels[288];
  int64_t mRotation;
  int64_t mAngle1;
  int64_t mAngle2;
  int64_t mAngle3;
  int64_t mAngle1Delta;
  int64_t mAngle2Delta;
  int64_t mAngle3Delta;
  int64_t mGravity;
  int64_t mDensity;
  int64_t mVariance;
  int64_t mTexCoordS;
  int64_t mTexCoordT;
  int64_t mElasticity;
  StartFrameMode mSequenceStartFrameMode;
  int mSequenceFixedFrameValue;
  PlayRateMode mSequencePlayRateMode;
  int mSequenceFixedFpsValue;
  LoopMode mSequenceLoopMode;
  int mSequenceLoopTimes;
  int spawnFrustumCullRadius;
};

struct FxBoltInfo {
  int dobjHandle;
  int boneIndex;
};

typedef enum {
  PT_NONE = 0,
  PT_PARTICLE = 1,
  PT_LINE = 2,
  PT_TAIL = 3,
  PT_CYLINDER = 4,
  PT_EMITTER = 5,
  PT_DECAL = 6,
  PT_ORIENTEDPARTICLE = 7,
  PT_FXRUNNER = 8,
  PT_LIGHT = 9,
  PT_CAMERASHAKE = 10,
  PT_SCREENFLASH = 11,
  PT_CLOUD = 12
} PrimType;

struct FxRange {
  int mMin;
  int mMax;
};

struct MediaHandles {
  TMediaList mMediaList;
};

typedef enum {
  SFM_FIXED_FRAME = 0,
  SFM_RANDOM = 1,
  SFM_INDEXED = 2,
  SFM_MODE_COUNT = 3
} StartFrameMode;

typedef enum {
  PRM_FIXED_FPS = 0,
  PRM_SYNC_TO_PARTICLE_LIFETIME = 1,
  PRM_MODE_COUNT = 2
} PlayRateMode;

typedef enum { LM_FOREVER = 0, LM_TIMES = 1, LM_MODE_COUNT = 2 } LoopMode;

typedef enum {
  FXCHAN_COLOR = 0,
  FXCHAN_COLOR_RAND = 1,
  FXCHAN_ALPHA = 2,
  FXCHAN_ALPHA_RAND = 3,
  FXCHAN_SIZE = 4,
  FXCHAN_SIZE_RAND = 5,
  FXCHAN_SIZE2 = 6,
  FXCHAN_SIZE2_RAND = 7,
  FXCHAN_LENGTH = 8,
  FXCHAN_LENGTH_RAND = 9,
  FXCHAN_ROTATION_DELTA = 10,
  FXCHAN_ROTATION_DELTA_RAND = 11,
  FXCHAN_VELOCITY_X = 12,
  FXCHAN_VELOCITY_Y = 13,
  FXCHAN_VELOCITY_Z = 14,
  FXCHAN_VELOCITY_X_RAND = 15,
  FXCHAN_VELOCITY_Y_RAND = 16,
  FXCHAN_VELOCITY_Z_RAND = 17,
  FXCHAN_VELOCITY2_X = 18,
  FXCHAN_VELOCITY2_Y = 19,
  FXCHAN_VELOCITY2_Z = 20,
  FXCHAN_VELOCITY2_X_RAND = 21,
  FXCHAN_VELOCITY2_Y_RAND = 22,
  FXCHAN_VELOCITY2_Z_RAND = 23,
  FXCHAN_COUNT = 24
} FxChannelId;

struct FxChannelInstance {
  FxCurveIterator curveIterator;
  int scale;
};

struct TMediaList {
  int elements;
  short size;
  short maxSize;
};

union TMediaElement {
  int model;
  int material;
  EffectTemplateLoadPtr u;
  int data;
};

struct FxChannel {
  int curve;
  int64_t scaleRange;
};

struct BackCompatibleParameters {
  char fxChannels[1536];
};

struct GPGroup {};

struct GPValue {};

struct FxCurveIterator {
  int master;
  int currentKeyIndex;
};

union EffectTemplateLoadPtr {
  int fx;
  int name;
};

struct FxFlagEntry {
  int flag;
  int64_t masks;
};

struct GPObject {};
ents;
short size;
short maxSize;
}
;

union TMediaElement {
  int model;
  int material;
  EffectTemplateLoadPtr u;
  int data;
};

struct FxChannel {
  int curve;
  int64_t scaleRange;
};

struct BackCompatibleParameters {
  char fxChannels[1536];
};

struct GPGroup {};

struct GPValue {};

struct FxCurveIterator {
  int master;
  int currentKeyIndex;
};

union EffectTemplateLoadPtr {
  int fx;
  int name;
};

struct FxFlagEntry {
  int flag;
  int64_t masks;
};

sstruct Effect {
  int Effect;
  char pad0[60];
  FxGfxEntity mRefEnt;
  int mFlags;
  int mClusterId;
  int mSortGroup;
  int mModel;
  int mTimeStart;
  int mTimeEnd;
  FxBoltFramePtr mBolt;
};

struct FxGfxEntity {
  int customMaterial;
  int rotation;
  char axis[36];
  char dlightColor[12];
  int materialTime;
  char origin[12];
  int64_t radius;
  int materialRGBA;
  int materialSubimageIndex;
  int scale;
  char endpos[12];
};

struct FxBoltFramePtr {};

struct FxArchive {};

struct EffectTemplate {
  int mEffectName;
  int mPrimitiveCount;
  char mPrimitives[96];
};

struct FxBoltFrame {
  char pad0[60];
  FxBoltInfo mBolt;
};

struct PrimitiveTemplate {
  char mName[32];
  char mMaterialImpact[32];
  PrimType mType;
  int mParentPrimIndex;
  FxRange mSpawnDelay;
  int64_t mSpawnCount;
  int64_t mLife;
  int64_t mSpawnRange;
  MediaHandles mMediaHandles;
  int64_t mImpactFxHandles;
  int64_t mDeathFxHandles;
  int64_t mEmitterFxHandles;
  int64_t mPlayFxHandles;
  int mAttributeFlags;
  int mSpawnFlags;
  int mGroupFlags;
  char mNonUniformScale;
  char useLength;
  char pad0[2];
  char mMin[12];
  char mMax[12];
  int64_t mOrigin1X;
  int64_t mOrigin1Y;
  int64_t mOrigin1Z;
  int64_t mOrigin2X;
  int64_t mOrigin2Y;
  int64_t mOrigin2Z;
  int64_t mRadius;
  int64_t mHeight;
  int64_t mWindModifier;
  char mFxChannels[288];
  int64_t mRotation;
  int64_t mAngle1;
  int64_t mAngle2;
  int64_t mAngle3;
  int64_t mAngle1Delta;
  int64_t mAngle2Delta;
  int64_t mAngle3Delta;
  int64_t mGravity;
  int64_t mDensity;
  int64_t mVariance;
  int64_t mTexCoordS;
  int64_t mTexCoordT;
  int64_t mElasticity;
  StartFrameMode mSequenceStartFrameMode;
  int mSequenceFixedFrameValue;
  PlayRateMode mSequencePlayRateMode;
  int mSequenceFixedFpsValue;
  LoopMode mSequenceLoopMode;
  int mSequenceLoopTimes;
  int spawnFrustumCullRadius;
};

struct FxBoltInfo {
  int dobjHandle;
  int boneIndex;
};

typedef enum {
  PT_NONE = 0,
  PT_PARTICLE = 1,
  PT_LINE = 2,
  PT_TAIL = 3,
  PT_CYLINDER = 4,
  PT_EMITTER = 5,
  PT_DECAL = 6,
  PT_ORIENTEDPARTICLE = 7,
  PT_FXRUNNER = 8,
  PT_LIGHT = 9,
  PT_CAMERASHAKE = 10,
  PT_SCREENFLASH = 11,
  PT_CLOUD = 12
} PrimType;

struct FxRange {
  int mMin;
  int mMax;
};

struct MediaHandles {
  TMediaList mMediaList;
};

typedef enum {
  SFM_FIXED_FRAME = 0,
  SFM_RANDOM = 1,
  SFM_INDEXED = 2,
  SFM_MODE_COUNT = 3
} StartFrameMode;

typedef enum {
  PRM_FIXED_FPS = 0,
  PRM_SYNC_TO_PARTICLE_LIFETIME = 1,
  PRM_MODE_COUNT = 2
} PlayRateMode;

typedef enum { LM_FOREVER = 0, LM_TIMES = 1, LM_MODE_COUNT = 2 } LoopMode;

typedef enum {
  FXCHAN_COLOR = 0,
  FXCHAN_COLOR_RAND = 1,
  FXCHAN_ALPHA = 2,
  FXCHAN_ALPHA_RAND = 3,
  FXCHAN_SIZE = 4,
  FXCHAN_SIZE_RAND = 5,
  FXCHAN_SIZE2 = 6,
  FXCHAN_SIZE2_RAND = 7,
  FXCHAN_LENGTH = 8,
  FXCHAN_LENGTH_RAND = 9,
  FXCHAN_ROTATION_DELTA = 10,
  FXCHAN_ROTATION_DELTA_RAND = 11,
  FXCHAN_VELOCITY_X = 12,
  FXCHAN_VELOCITY_Y = 13,
  FXCHAN_VELOCITY_Z = 14,
  FXCHAN_VELOCITY_X_RAND = 15,
  FXCHAN_VELOCITY_Y_RAND = 16,
  FXCHAN_VELOCITY_Z_RAND = 17,
  FXCHAN_VELOCITY2_X = 18,
  FXCHAN_VELOCITY2_Y = 19,
  FXCHAN_VELOCITY2_Z = 20,
  FXCHAN_VELOCITY2_X_RAND = 21,
  FXCHAN_VELOCITY2_Y_RAND = 22,
  FXCHAN_VELOCITY2_Z_RAND = 23,
  FXCHAN_COUNT = 24
} FxChannelId;

struct FxChannelInstance {
  FxCurveIterator curveIterator;
  int scale;
};

struct TMediaList {
  int elements;
  short size;
  short maxSize;
};

union TMediaElement {
  int model;
  int material;
  EffectTemplateLoadPtr u;
  int data;
};

struct FxChannel {
  int curve;
  int64_t scaleRange;
};

struct BackCompatibleParameters {
  char fxChannels[1536];
};

struct GPGroup {};

struct GPValue {};

struct FxCurveIterator {
  int master;
  int currentKeyIndex;
};

union EffectTemplateLoadPtr {
  int fx;
  int name;
};

struct FxFlagEntry {
  int flag;
  int64_t masks;
};