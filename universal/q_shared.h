

typedef enum {
  PMSG_CONSOLE = 0,
  PMSG_GAME = 1,
  PMSG_BOLDGAME = 2,
  PMSG_SUBTITLE = 3,
  PMSG_LOGFILE = 4
} print_msg_type_t;

typedef enum {
  ERR_FATAL = 0,
  ERR_DROP = 1,
  ERR_SERVERDISCONNECT = 2,
  ERR_DISCONNECT = 3,
  ERR_SCRIPT = 4,
  ERR_SCRIPT_DROP = 5,
  ERR_LOCALIZATION = 6
} errorParm_t;

struct pc_token_s {
  int type;
  int subtype;
  int intvalue;
  int floatvalue;
  char string[1024];
};

typedef enum {
  FS_READ = 0,
  FS_WRITE = 1,
  FS_APPEND = 2,
  FS_APPEND_SYNC = 3
} fsMode_t;

union DvarValue {
  char enabled;
  int integer;
  int value;
  int vector;
  int string;
  int color;
};

// Failed to parse with python script I wrote, manually fixed. (Size is 8 bytes)
// Not sure about vector, min & max could be pointers to a static vector
// somewhere
union DvarLimits {
  struct {
    int stringCount;
    const char **strings;
  } enumeration;

  struct {
    int min;
    int max;
  } integer;

  struct {
    float min;
    float max;
  } value;

  struct {
    float min;
    float max;
  } vector;
};

struct dvar_s {
  int name;
  short flags;
  char type;
  char modified;
  DvarValue current;
  int latched;
  int reset;
  DvarLimits domain;
  int next;
  int hashNext;
};

struct cplane_s {
  char normal[12];
  int dist;
  char type;
  char signbits;
  short pad;
};

struct trace_t {
  int fraction;
  char normal[12];
  int surfaceFlags;
  int contents;
  int material;
  short entityNum;
  short partName;
  short partGroup;
  char allsolid;
  char startsolid;
};

struct orientation_t {
  char origin[12];
  char axis[36];
};

struct gameState_t {
  char stringOffsets[8192];
  char stringData[16000];
  int dataCount;
};

struct playerState_s {
  int commandTime;
  int pm_type;
  int bobCycle;
  int pm_flags;
  int pm_time;
  char origin[12];
  char velocity[12];
  int64_t oldVelocity;
  int weaponTime;
  int weaponDelay;
  int grenadeTimeLeft;
  int weaponRestrictKickTime;
  int foliageSoundTime;
  int gravity;
  int leanf;
  int speed;
  char delta_angles[12];
  int groundEntityNum;
  char vLadderVec[12];
  int jumpTime;
  int jumpOriginZ;
  int legsTimer;
  int legsAnim;
  int torsoTimer;
  int torsoAnim;
  int legsAnimDuration;
  int torsoAnimDuration;
  int damageTimer;
  int damageDuration;
  int flinchYaw;
  int movementDir;
  int eFlags;
  int eventSequence;
  char events[16];
  char eventParms[16];
  int oldEventSequence;
  int clientNum;
  int offHandIndex;
  int weapon;
  int weaponstate;
  float fWeaponPosFrac;
  int adsDelayTime;
  int viewmodelIndex;
  char viewangles[12];
  int viewHeightTarget;
  int viewHeightCurrent;
  int viewHeightLerpTime;
  int viewHeightLerpTarget;
  int viewHeightLerpDown;
  int viewHeightLerpPosAdj;
  int64_t viewAngleClampBase;
  int64_t viewAngleClampRange;
  int damageEvent;
  int damageYaw;
  int damagePitch;
  int damageCount;
  char stats[24];
  char ammo[512];
  char ammoclip[512];
  char weapons[16];
  int64_t weaponslots;
  char weaponrechamber[16];
  char mins[12];
  char maxs[12];
  int proneDirection;
  int proneDirectionPitch;
  int proneTorsoPitch;
  int viewlocked;
  int viewlocked_entNum;
  int cursorHint;
  int cursorHintString;
  int cursorHintEntIndex;
  int iCompassFriendInfo;
  float fTorsoHeight;
  float fTorsoPitch;
  float fWaistPitch;
  int holdBreathScale;
  int holdBreathTimer;
  MantleState mantleState;
  int entityEventSequence;
  int weapAnim;
  int aimSpreadScale;
  int shellshockIndex;
  int shellshockTime;
  int shellshockDuration;
  char objective[448];
  int deltaTime;
};

struct usercmd_s {
  int serverTime;
  int buttons;
  char weapon;
  char offHandIndex;
  char pad0[2];
  char angles[12];
  char forwardmove;
  char rightmove;
};

typedef enum {
  TR_STATIONARY = 0,
  TR_INTERPOLATE = 1,
  TR_LINEAR = 2,
  TR_LINEAR_STOP = 3,
  TR_SINE = 4,
  TR_GRAVITY = 5,
  TR_GRAVITY_PAUSED = 6,
  TR_ACCELERATE = 7,
  TR_DECELERATE = 8
} trType_t;

struct trajectory_t {
  trType_t trType;
  int trTime;
  int trDuration;
  char trBase[12];
  char trDelta[12];
};

struct entityState_s {
  int number;
  int eType;
  int eFlags;
  trajectory_t pos;
  char apos[36];
  int time;
  int time2;
  char origin2[12];
  char angles2[12];
  int otherEntityNum;
  int attackerEntityNum;
  int groundEntityNum;
  int constantLight;
  int loopSound;
  int surfType;
  char pad0[4];
  int clientNum;
  int iHeadIcon;
  int iHeadIconTeam;
  int solid;
  int eventParm;
  int eventSequence;
  char events[16];
  char eventParms[16];
  int weapon;
  int legsAnim;
  int torsoAnim;
  int leanf;
  char pad1[4];
  int dmgFlags;
  int animMovetype;
  float fTorsoHeight;
  float fTorsoPitch;
  float fWaistPitch;
};

typedef enum {
  CA_DISCONNECTED = 0,
  CA_CINEMATIC = 1,
  CA_LOGO = 2,
  CA_CONNECTING = 3,
  CA_CHALLENGING = 4,
  CA_CONNECTED = 5,
  CA_LOADING = 6,
  CA_PRIMED = 7,
  CA_ACTIVE = 8
} connstate_t;

struct Font_s {
  int name;
  int pixelHeight;
  int glyphCount;
  int material;
  int glyphs;
};

struct Glyph {
  short letter;
  char x0;
  char y0;
  char dx;
  char pixelWidth;
  char pixelHeight;
  char pad0[1];
  int s0;
  int t0;
  int s1;
  int t1;
};

struct qtime_s {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

typedef enum {
  FMV_IDLE = 0,
  FMV_PLAY = 1,
  FMV_EOF = 2,
  FMV_ID_BLT = 3,
  FMV_ID_IDLE = 4,
  FMV_LOOPED = 5,
  FMV_ID_WAIT = 6
} e_status;