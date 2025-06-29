
#pragma pack(push, 1)
#include <stdint.h>

// typedef long long int64_t;
// typedef int int32_t;
// typedef short int16_t;
// typedef char int8_t;
// typedef unsigned long long uint64_t;
// typedef unsigned int uint32_t;
// typedef unsigned short uint16_t;
// typedef unsigned char uint8_t;
typedef float vec2_t[2];
typedef float vec3_t[3];
typedef float vec4_t[4];
typedef float matrix4_t[16];

struct HFSUniStr255
{
	uint16_t length;
	uint8_t unicode[510];
};

struct FSRef
{
	uint8_t hidden[80];
};

struct CFUUIDBytes
{
	int8_t byte0;
	int8_t byte1;
	int8_t byte2;
	int8_t byte3;
	int8_t byte4;
	int8_t byte5;
	int8_t byte6;
	int8_t byte7;
	int8_t byte8;
	int8_t byte9;
	int8_t byte10;
	int8_t byte11;
	int8_t byte12;
	int8_t byte13;
	int8_t byte14;
	int8_t byte15;
};

struct KeyStruct
{
	uint8_t ignore0[64];
	CFUUIDBytes uuid1;
	int32_t ignore1;
	char creatorName[64];
	int32_t ignore2;
	uint8_t creatorMachine[64];
	uint8_t ignore3[32];
	uint64_t dateCreated;
	int32_t ignore4;
	char gameName[64];
	uint8_t ignore5[16];
	int32_t gameCreator;
	int32_t ignore6;
	char playerName[64];
	uint8_t ignore7[64];
	char uuid2[16];
	uint8_t ignore8[16];
	int32_t checkSum;
	uint8_t ignore9[512];
};

struct LSItemInfoRecord
{
	uint32_t flags;
	int32_t filetype;
	int32_t creator;
	int32_t extension;
	char iconFileName[4];
	uint32_t kindID;
};

struct AEDesc
{
	char descriptorType[4];
	uint32_t dataHandle;
};

struct CAEDesc
{
};

struct Point
{
	int16_t v;
	int16_t h;
};

struct MacRect
{
	int16_t top;
	int16_t left;
	int16_t bottom;
	int16_t right;
};

struct FSSpec
{
	uint16_t vRefNum;
	uint32_t parID;
	char name[64];
};

struct CAEEvent
{
};

struct CAERecord
{
};

struct CAETarget
{
};

struct ProcessSerialNumber
{
	int32_t highLongOfPSN;
	int32_t lowLongOfPSN;
};

struct CAEObject
{
};

struct CGSize
{
	uint32_t width;
	int32_t height;
};

struct EventTypeSpec
{
	int32_t eventClass;
	int32_t eventKind;
};

struct ControlID
{
	int32_t signature;
	uint32_t id;
};

struct ControlEditTextSelectionRec
{
	int16_t selStart;
	uint16_t selEnd;
};

struct $_2251
{
	void *menuRef;
	uint16_t menuItemIndex;
};

struct HICommand
{
	int32_t attributes;
	char commandID[4];
	$_2251 menu;
};

struct ControlKind
{
	int32_t signature;
	int32_t kind;
};

union TXNAttributeData
{
	void *dataPtr;
	int32_t dataValue;
	int32_t atsuFeatures;
	int32_t atsuVariations;
	void *urlReference;
};

struct TXNTypeAttributes
{
	int32_t tag;
	uint32_t size;
	TXNAttributeData data;
};

struct TXNATSUIFeatures
{
	uint32_t featureCount;
	int32_t featureTypes;
	int32_t featureSelectors;
};

struct TXNATSUIVariations
{
	uint32_t variationCount;
	int32_t variationAxis;
	int32_t variationValues;
};

struct MacRGBColor
{
	int16_t red;
	int16_t green;
	int16_t blue;
};

struct ControlFontStyleRec
{
	int16_t flags;
	int16_t font;
	uint16_t size;
	int16_t style;
	int16_t mode;
	int16_t just;
	MacRGBColor foreColor;
	uint16_t backColor[3];
};

struct StShowCursor
{
	int8_t mWasVisible;
};

struct GDevice
{
	uint16_t gdRefNum;
	uint16_t gdID;
	int16_t gdType;
	int32_t gdITable;
	int16_t gdResPref;
	int32_t gdSearchProc;
	int32_t gdCompProc;
	int16_t gdFlags;
	int32_t gdPMap;
	void *gdRefCon;
	int32_t gdNextGD;
	MacRect gdRect;
	int32_t gdMode;
	int16_t gdCCBytes;
	int16_t gdCCDepth;
	int32_t gdCCXData;
	uint32_t gdCCXMask;
	int32_t gdExt;
};

struct ITab
{
	int32_t iTabSeed;
	int16_t iTabRes;
	int8_t iTTable;
};

struct SProcRec
{
	int32_t nxtSrch;
	int32_t srchProc;
};

struct CProcRec
{
	int32_t nxtComp;
	int32_t compProc;
};

struct PixMap
{
	int32_t baseAddr;
	int16_t rowBytes;
	uint64_t bounds;
	char pmVersion[2];
	int16_t packType;
	uint32_t packSize;
	int32_t hRes;
	int32_t vRes;
	int16_t pixelType;
	uint16_t pixelSize;
	uint16_t cmpCount;
	uint16_t cmpSize;
	int32_t pixelFormat;
	int32_t pmTable;
	int32_t pmExt;
};

struct ColorTable
{
	int32_t ctSeed;
	int16_t ctFlags;
	uint16_t ctSize;
	uint64_t ctTable;
};

struct ColorSpec
{
	int16_t value;
	MacRGBColor rgb;
};

struct CGPoint
{
	int32_t x;
	int32_t y;
};

struct CGRect
{
	CGPoint origin;
	CGSize size;
};

struct OpaqueContextRef
{
	char mContext[4];
	int32_t mDrawable;
	uint32_t mRendererID;
	int8_t mDoubleBuffered;
};

struct CResInfo
{
	uint32_t width;
	int32_t height;
	int32_t depth;
	int32_t rate;
};

struct ComponentInstanceRecord
{
	int32_t data;
};

struct ImageDescription
{
	uint32_t idSize;
	int32_t cType;
	int32_t resvd1;
	int16_t resvd2;
	uint16_t dataRefIndex;
	char version[2];
	int16_t revisionLevel;
	int32_t vendor;
	int32_t temporalQuality;
	int32_t spatialQuality;
	uint16_t width;
	int16_t height;
	int32_t hRes;
	int32_t vRes;
	uint32_t dataSize;
	uint16_t frameCount;
	char name[32];
	int16_t depth;
	uint16_t clutID;
};

struct random_access_iterator_tag
{
};

struct bidirectional_iterator_tag
{
};

struct forward_iterator_tag
{
};

struct input_iterator_tag
{
};

struct D3DGAMMARAMP
{
	uint8_t red[512];
	uint8_t green[512];
	uint8_t blue[512];
};

struct Vector_impl
{
	int32_t _M_start;
	int32_t _M_finish;
	int32_t _M_end_of_storage;
};

struct false_type
{
};

struct Alloc_hider
{
	int32_t _M_p;
};

struct Rep
{
};

struct Rep_base
{
	uint32_t _M_length;
	int32_t _M_capacity;
	uint32_t _M_refcount;
};

typedef enum
{
	kCGLNoError = 0,
	kCGLBadAttribute = 10000,
	kCGLBadProperty = 10001,
	kCGLBadPixelFormat = 10002,
	kCGLBadRendererInfo = 10003,
	kCGLBadContext = 10004,
	kCGLBadDrawable = 10005,
	kCGLBadDisplay = 10006,
	kCGLBadState = 10007,
	kCGLBadValue = 10008,
	kCGLBadMatch = 10009,
	kCGLBadEnumeration = 10010,
	kCGLBadOffScreen = 10011,
	kCGLBadFullScreen = 10012,
	kCGLBadWindow = 10013,
	kCGLBadAddress = 10014,
	kCGLBadCodeModule = 10015,
	kCGLBadAlloc = 10016,
	kCGLBadConnection = 10017
} CGLError;

typedef enum
{
	kCGLPFAAllRenderers = 1,
	kCGLPFADoubleBuffer = 5,
	kCGLPFAStereo = 6,
	kCGLPFAAuxBuffers = 7,
	kCGLPFAColorSize = 8,
	kCGLPFAAlphaSize = 11,
	kCGLPFADepthSize = 12,
	kCGLPFAStencilSize = 13,
	kCGLPFAAccumSize = 14,
	kCGLPFAMinimumPolicy = 51,
	kCGLPFAMaximumPolicy = 52,
	kCGLPFAOffScreen = 53,
	kCGLPFAFullScreen = 54,
	kCGLPFASampleBuffers = 55,
	kCGLPFASamples = 56,
	kCGLPFAAuxDepthStencil = 57,
	kCGLPFAColorFloat = 58,
	kCGLPFAMultisample = 59,
	kCGLPFASupersample = 60,
	kCGLPFASampleAlpha = 61,
	kCGLPFARendererID = 70,
	kCGLPFASingleRenderer = 71,
	kCGLPFANoRecovery = 72,
	kCGLPFAAccelerated = 73,
	kCGLPFAClosestPolicy = 74,
	kCGLPFARobust = 75,
	kCGLPFABackingStore = 76,
	kCGLPFAMPSafe = 78,
	kCGLPFAWindow = 80,
	kCGLPFAMultiScreen = 81,
	kCGLPFACompliant = 83,
	kCGLPFADisplayMask = 84,
	kCGLPFAPBuffer = 90,
	kCGLPFARemotePBuffer = 91,
	kCGLPFAVirtualScreenCount = 128
} CGLPixelFormatAttribute;

struct FSCatalogInfo
{
	int16_t nodeFlags;
	int16_t volume;
	uint32_t parentDirID;
	uint32_t nodeID;
	int8_t sharingFlags;
	int8_t userPrivileges;
	int8_t reserved1;
	int8_t reserved2;
	uint64_t createDate;
	uint64_t contentModDate;
	uint64_t attributeModDate;
	uint64_t accessDate;
	uint64_t backupDate;
	uint8_t permissions[16];
	char finderInfo[16];
	char extFinderInfo[16];
	vec2_t dataLogicalSize;
	vec2_t dataPhysicalSize;
	vec2_t rsrcLogicalSize;
	vec2_t rsrcPhysicalSize;
	uint32_t valence;
	char textEncodingHint[4];
};

struct RemoveDirectoryInfo
{
	int32_t error;
	int32_t actualObjects;
	FSCatalogInfo catalogInfo;
};

struct UTCDateTime
{
	int16_t highSeconds;
	int32_t lowSeconds;
	int16_t fraction;
};

struct CMMapFile
{
	void *mFileRef;
	uint32_t mFileSize;
	void *mMemRef;
};

struct sFILE
{
	int32_t _p;
	int32_t _r;
	int32_t _w;
	int16_t _flags;
	int16_t _file;
	uint64_t _bf;
	uint32_t _lbfsize;
	int32_t _cookie;
	int32_t _close;
	int32_t _read;
	int32_t _seek;
	int32_t _write;
	uint64_t _ub;
	int32_t _extra;
	int32_t _ur;
	uint8_t _ubuf[3];
	int8_t _nbuf;
	uint64_t _lb;
	uint32_t _blksize;
	vec2_t _offset;
};

struct sbuf
{
	int32_t _base;
	uint32_t _size;
};

struct timespec
{
	int32_t tv_sec;
	int32_t tv_nsec;
};

struct stat
{
	int32_t st_dev;
	int32_t st_ino;
	int16_t st_mode;
	int16_t st_nlink;
	uint32_t st_uid;
	uint32_t st_gid;
	int32_t st_rdev;
	timespec st_atimespec;
	char st_mtimespec[8];
	char st_ctimespec[8];
	vec2_t st_size;
	uint64_t st_blocks;
	uint32_t st_blksize;
	uint32_t st_flags;
	int32_t st_gen;
	int32_t st_lspare;
	uint8_t st_qspare[16];
};

struct DInfo
{
	uint64_t frRect;
	int16_t frFlags;
	int32_t frLocation;
	int16_t frView;
};

struct DXInfo
{
	int32_t frScroll;
	int32_t frOpenChain;
	int8_t frScript;
	int8_t frXFlags;
	int16_t frComment;
	int32_t frPutAway;
};

struct DirInfo
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	uint16_t ioFRefNum;
	uint8_t ioFVersNum;
	int8_t filler1;
	uint16_t ioFDirIndex;
	int8_t ioFlAttrib;
	int8_t ioACUser;
	DInfo ioDrUsrWds;
	uint32_t ioDrDirID;
	int16_t ioDrNmFls;
	uint8_t filler3[18];
	int32_t ioDrCrDat;
	int32_t ioDrMdDat;
	int32_t ioDrBkDat;
	DXInfo ioDrFndrInfo;
	uint32_t ioDrParID;
};

struct FXInfo
{
	uint16_t fdIconID;
	uint8_t fdReserved[6];
	int8_t fdScript;
	int8_t fdXFlags;
	int16_t fdComment;
	int32_t fdPutAway;
};

struct HFileInfo
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	uint16_t ioFRefNum;
	uint8_t ioFVersNum;
	int8_t filler1;
	uint16_t ioFDirIndex;
	int8_t ioFlAttrib;
	int8_t ioACUser;
	char ioFlFndrInfo[16];
	uint32_t ioDirID;
	int16_t ioFlStBlk;
	uint32_t ioFlLgLen;
	uint32_t ioFlPyLen;
	int16_t ioFlRStBlk;
	uint32_t ioFlRLgLen;
	uint32_t ioFlRPyLen;
	int32_t ioFlCrDat;
	int32_t ioFlMdDat;
	int32_t ioFlBkDat;
	FXInfo ioFlXFndrInfo;
	uint32_t ioFlParID;
	int32_t ioFlClpSiz;
};

union CInfoPBRec
{
	HFileInfo hFileInfo;
	DirInfo dirInfo;
};

struct FInfo
{
	int32_t fdType;
	int32_t fdCreator;
	int16_t fdFlags;
	int32_t fdLocation;
	int16_t fdFldr;
};

struct QElem
{
	int32_t qLink;
	int16_t qType;
	int16_t qData;
};

struct MacImageInfo
{
	uint16_t width;
	int16_t height;
	int32_t rowBytes;
	int32_t data;
};

struct CMacLogFile
{
	int32_t mFile;
};

struct StPortState
{
	int32_t mSavedPort;
};

struct StGWorldState
{
	int32_t mSavedPort;
	int32_t mSavedDevice;
};

struct StSetDirectory
{
	uint16_t mSavedVRefNum;
	char pad0[2];
	uint32_t mSavedDirID;
	int8_t mSavedIsValid;
};

struct Cursor
{
	uint8_t data[32];
	uint8_t mask[32];
	Point hotSpot;
};

struct EventRecord
{
	int16_t what;
	char message[4];
	int32_t when;
	int32_t where;
	int16_t modifiers;
};

struct FSVolumeInfo
{
	UTCDateTime createDate;
	uint64_t modifyDate;
	uint64_t backupDate;
	uint64_t checkedDate;
	uint32_t fileCount;
	uint32_t folderCount;
	uint64_t totalBytes;
	uint64_t freeBytes;
	uint32_t blockSize;
	int32_t totalBlocks;
	int32_t freeBlocks;
	int32_t nextAllocation;
	uint32_t rsrcClumpSize;
	uint32_t dataClumpSize;
	uint32_t nextCatalogID;
	char finderInfo[32];
	int16_t flags;
	uint16_t filesystemID;
	int16_t signature;
	uint16_t driveNumber;
	char driverRefNum[2];
};

typedef enum
{
	kCFCompareLessThan = -1,
	kCFCompareEqualTo = 0,
	kCFCompareGreaterThan = 1
} $_18;

struct GetVolParmsInfoBuffer
{
	char vMVersion[2];
	int32_t vMAttrib;
	int32_t vMLocalHand;
	int32_t vMServerAdr;
	int32_t vMVolumeGrade;
	uint16_t vMForeignPrivID;
	int32_t vMExtendedAttributes;
	uint32_t vMDeviceID;
	char vMMaxNameLength[4];
};

struct HVolumeParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	int32_t filler2;
	uint16_t ioVolIndex;
	int32_t ioVCrDate;
	int32_t ioVLsMod;
	int16_t ioVAtrb;
	int16_t ioVNmFls;
	int16_t ioVBitMap;
	int16_t ioAllocPtr;
	int16_t ioVNmAlBlks;
	int32_t ioVAlBlkSiz;
	int32_t ioVClpSiz;
	int16_t ioAlBlSt;
	uint32_t ioVNxtCNID;
	int16_t ioVFrBlk;
	int16_t ioVSigWord;
	char ioVDrvInfo[2];
	uint16_t ioVDRefNum;
	uint16_t ioVFSID;
	int32_t ioVBkUp;
	uint16_t ioVSeqNum;
	int32_t ioVWrCnt;
	int32_t ioVFilCnt;
	int32_t ioVDirCnt;
	char ioVFndrInfo[32];
};

struct CatPositionRec
{
	int32_t initialize;
	vec3_t priv;
};

struct CSParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	void *ioMatchPtr;
	uint32_t ioReqMatchCount;
	uint32_t ioActMatchCount;
	int32_t ioSearchBits;
	char ioSearchInfo1[4];
	char ioSearchInfo2[4];
	uint32_t ioSearchTime;
	CatPositionRec ioCatPosition;
	void *ioOptBuffer;
	uint32_t ioOptBufSize;
};

struct ForeignPrivParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	int32_t ioFiller21;
	int32_t ioFiller22;
	void *ioForeignPrivBuffer;
	uint32_t ioForeignPrivActCount;
	uint32_t ioForeignPrivReqCount;
	int32_t ioFiller23;
	uint32_t ioForeignPrivDirID;
	char ioForeignPrivInfo1[4];
	char ioForeignPrivInfo2[4];
	char ioForeignPrivInfo3[4];
	char ioForeignPrivInfo4[4];
};

struct HIOParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	uint16_t ioRefNum;
	uint8_t ioVersNum;
	int8_t ioPermssn;
	int32_t ioMisc;
	void *ioBuffer;
	uint32_t ioReqCount;
	uint32_t ioActCount;
	uint16_t ioPosMode;
	uint32_t ioPosOffset;
};

struct WDParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	int16_t ioWDCreated;
	uint16_t ioWDIndex;
	uint32_t ioWDProcID;
	uint16_t ioWDVRefNum;
	int16_t filler10;
	int32_t filler11;
	int32_t filler12;
	int32_t filler13;
	uint32_t ioWDDirID;
};

struct CopyParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	uint16_t ioDstVRefNum;
	int16_t filler8;
	char ioNewName[4];
	char ioCopyName[4];
	uint32_t ioNewDirID;
	int32_t filler14;
	int32_t filler15;
	uint32_t ioDirID;
};

struct AccessParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	uint16_t ioRefNum;
	int16_t ioDenyModes;
	int16_t filler4;
	int8_t filler5;
	int8_t ioACUser;
	int32_t filler6;
	uint32_t ioACOwnerID;
	uint32_t ioACGroupID;
	int32_t ioACAccess;
	uint32_t ioDirID;
};

struct FIDParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	int32_t filler14;
	char ioDestNamePtr[4];
	int32_t filler15;
	uint32_t ioDestDirID;
	int32_t filler16;
	int32_t filler17;
	uint32_t ioSrcDirID;
	int16_t filler18;
	uint32_t ioFileID;
};

struct HFileParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	uint16_t ioFRefNum;
	uint8_t ioFVersNum;
	int8_t filler1;
	uint16_t ioFDirIndex;
	int8_t ioFlAttrib;
	uint8_t ioFlVersNum;
	FInfo ioFlFndrInfo;
	uint32_t ioDirID;
	int16_t ioFlStBlk;
	uint32_t ioFlLgLen;
	uint32_t ioFlPyLen;
	int16_t ioFlRStBlk;
	uint32_t ioFlRLgLen;
	uint32_t ioFlRPyLen;
	int32_t ioFlCrDat;
	int32_t ioFlMdDat;
};

struct ObjParam
{
	int32_t qLink;
	int16_t qType;
	int16_t ioTrap;
	char ioCmdAddr[4];
	int32_t ioCompletion;
	int16_t ioResult;
	char ioNamePtr[4];
	uint16_t ioVRefNum;
	int16_t filler7;
	int16_t ioObjType;
	char ioObjNamePtr[4];
	uint32_t ioObjID;
};

union HParamBlockRec
{
	HIOParam ioParam;
	HFileParam fileParam;
	HVolumeParam volumeParam;
	AccessParam accessParam;
	ObjParam objParam;
	CopyParam copyParam;
	WDParam wdParam;
	FIDParam fidParam;
	CSParam csParam;
	ForeignPrivParam foreignPrivParam;
};

struct UnsignedWide
{
	int32_t lo;
	int32_t hi;
};

struct NumVersion
{
	int8_t nonRelRev;
	int8_t stage;
	int8_t minorAndBugRev;
	int8_t majorRev;
};

struct ProcessInfoRec
{
	char processInfoLength[4];
	char processName[4];
	uint64_t processNumber;
	int32_t processType;
	int32_t processSignature;
	int32_t processMode;
	int32_t processLocation;
	uint32_t processSize;
	int32_t processFreeMem;
	uint64_t processLauncher;
	int32_t processLaunchDate;
	uint32_t processActiveTime;
	char processAppSpec[4];
};

struct AlertStdCFStringAlertParamRec
{
	char version[4];
	int8_t movable;
	int8_t helpButton;
	char defaultText[4];
	char cancelText[4];
	char otherText[4];
	int16_t defaultButton;
	int16_t cancelButton;
	uint16_t position;
	uint32_t flags;
};

struct OSVERSIONINFOA
{
	char dwOSVersionInfoSize[4];
	char dwMajorVersion[4];
	char dwMinorVersion[4];
	uint32_t dwBuildNumber;
	uint32_t dwPlatformId;
	char szCSDVersion[128];
};

struct MEMORYSTATUS
{
	uint32_t dwLength;
	int32_t dwMemoryLoad;
	int32_t dwTotalPhys;
	int32_t dwAvailPhys;
	int32_t dwTotalPageFile;
	int32_t dwAvailPageFile;
	int32_t dwTotalVirtual;
	int32_t dwAvailVirtual;
};

struct $_3465
{
	int32_t LowPart;
	int32_t HighPart;
};

struct $_3464
{
	int32_t LowPart;
	int32_t HighPart;
};

union LARGE_INTEGER
{
	$_3464 unnamed_field;
	$_3465 u;
	uint64_t QuadPart;
};

struct $_3513
{
	uint32_t Offset;
	uint32_t OffsetHigh;
};

union $_3512
{
	$_3513 unnamed_field;
	int32_t Pointer;
};

struct OVERLAPPED
{
	int32_t Internal;
	int32_t InternalHigh;
	$_3512 unnamed_field;
	int32_t hEvent;
};

struct SECURITY_ATTRIBUTES
{
	uint32_t nLength;
	char lpSecurityDescriptor[4];
	uint32_t bInheritHandle;
};

struct opaque_pthread_mutex_t
{
	int32_t __sig;
	uint8_t __opaque[40];
};

struct opaque_pthread_mutexattr_t
{
	int32_t __sig;
	uint64_t __opaque;
};

struct opaque_pthread_t
{
	int32_t __sig;
	int32_t __cleanup_stack;
	uint8_t __opaque[596];
};

struct darwin_pthread_handler_rec
{
	int32_t __routine;
	int32_t __arg;
	int32_t __next;
};

struct sched_param
{
	int32_t sched_priority;
	int32_t opaque;
};

struct SYSTEMTIME
{
	int16_t wYear;
	int16_t wMonth;
	int16_t wDayOfWeek;
	int16_t wDay;
	int16_t wHour;
	int16_t wMinute;
	int16_t wSecond;
	int16_t wMilliseconds;
};

struct DateTimeRec
{
	int16_t year;
	int16_t month;
	int16_t day;
	int16_t hour;
	int16_t minute;
	int16_t second;
	int16_t dayOfWeek;
};

struct $_3466
{
	int32_t LowPart;
	int32_t HighPart;
};

struct $_3467
{
	int32_t LowPart;
	int32_t HighPart;
};

union ULARGE_INTEGER
{
	$_3466 unnamed_field;
	$_3467 u;
	uint64_t QuadPart;
};

struct tagRECT
{
	int32_t left;
	int32_t top;
	int32_t right;
	int32_t bottom;
};

struct tagPOINT
{
	int32_t x;
	int32_t y;
};

struct FILETIME
{
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
};

struct LocalDateTime
{
	int16_t highSeconds;
	int32_t lowSeconds;
	int16_t fraction;
};

struct $_614
{
	int16_t era;
	int16_t year;
	int16_t month;
	int16_t day;
	int16_t hour;
	int16_t minute;
	int16_t second;
	int16_t dayOfWeek;
	int16_t dayOfYear;
	int16_t weekOfYear;
	int16_t pm;
	int16_t res1;
	int16_t res2;
	int16_t res3;
};

struct $_615
{
	int16_t eraAlt;
	uint8_t oldDate[14];
};

union LongDateRec
{
	$_614 ld;
	uint8_t list[28];
	$_615 od;
};

struct MEMORY_BASIC_INFORMATION
{
	char BaseAddress[4];
	int32_t AllocationBase;
	int32_t AllocationProtect;
	uint32_t RegionSize;
	int32_t State;
	int32_t Protect;
	int32_t Type;
};

typedef enum
{
	kExactItem = 0,
	kAnyItem = 1,
	kAnyItemType = 2
} FFType;

struct WIN32_FIND_DATAA
{
	int32_t dwFileAttributes;
	uint64_t ftCreationTime;
	uint64_t ftLastAccessTime;
	uint64_t ftLastWriteTime;
	uint32_t nFileSizeHigh;
	uint32_t nFileSizeLow;
	int32_t dwReserved0;
	int32_t dwReserved1;
	char cFileName[260];
	char cAlternateFileName[14];
	char pad0[2];
	int32_t dwFileType;
	int32_t dwCreatorType;
	int16_t wFinderFlags;
};

struct FFItem
{
	FSRef ref;
	char name[260];
	uint64_t modDate;
	int16_t flags;
};

struct ANIHeader
{
	uint32_t cbSizeOf;
	int32_t cFrames;
	int32_t cSteps;
	int32_t cx;
	int32_t cy;
	uint32_t cBitCount;
	int32_t cPlanes;
	int32_t JifRate;
	uint32_t flags;
};

struct WinCursor
{
	uint32_t mHandle;
	char mName[4];
	ANIHeader mHeader;
	int32_t mIcons;
	int32_t mRate;
	int32_t mSequence;
	int32_t mStep;
	uint32_t mNextTime;
	int8_t mFirstTime;
};

struct WinIcon
{
	uint32_t mID;
};

struct BITMAPINFOHEADER
{
	uint32_t biSize;
	uint32_t biWidth;
	int32_t biHeight;
	int16_t biPlanes;
	uint16_t biBitCount;
	int32_t biCompression;
	uint32_t biSizeImage;
	int32_t biXPelsPerMeter;
	int32_t biYPelsPerMeter;
	int32_t biClrUsed;
	int32_t biClrImportant;
};

struct tagRGBQUAD
{
	int8_t rgbBlue;
	int8_t rgbGreen;
	int8_t rgbRed;
	int8_t rgbReserved;
};

struct CColorConverter
{
	void *_vptr$CColorConverter;
};

typedef enum
{
	ATI_4_COMPS_CONVERTER_ARGB = 0,
	ATI_4_COMPS_CONVERTER_ABGR = 1,
	STD_CONVERTER_ARGB = 2,
	STD_CONVERTER_ABGR = 3,
	UNKNOWN_CONVERTER = 4
} ConverterType;

struct ATI4CompsConverterARGB
{
};

struct ATI4CompsConverterABGR
{
};

struct StdConverterARGB
{
};

struct StdConverterABGR
{
};

typedef enum
{
	ARGB = 0,
	ABGR = 1
} Format;

struct StColorConverter
{
	int32_t mType;
};

struct CDirect3D
{
	char pad0[4];
	uint32_t mRefCount;
	char mPrimaryContext[4];
};

struct IDirect3D9
{
};

typedef enum
{
	D3DFMT_UNKNOWN = 0,
	D3DFMT_R8G8B8 = 20,
	D3DFMT_A8R8G8B8 = 21,
	D3DFMT_X8R8G8B8 = 22,
	D3DFMT_R5G6B5 = 23,
	D3DFMT_X1R5G5B5 = 24,
	D3DFMT_A1R5G5B5 = 25,
	D3DFMT_A4R4G4B4 = 26,
	D3DFMT_R3G3B2 = 27,
	D3DFMT_A8 = 28,
	D3DFMT_A8R3G3B2 = 29,
	D3DFMT_X4R4G4B4 = 30,
	D3DFMT_A2B10G10R10 = 31,
	D3DFMT_A8B8G8R8 = 32,
	D3DFMT_X8B8G8R8 = 33,
	D3DFMT_G16R16 = 34,
	D3DFMT_A2R10G10B10 = 35,
	D3DFMT_A16B16G16R16 = 36,
	D3DFMT_A8P8 = 40,
	D3DFMT_P8 = 41,
	D3DFMT_L8 = 50,
	D3DFMT_A8L8 = 51,
	D3DFMT_A4L4 = 52,
	D3DFMT_V8U8 = 60,
	D3DFMT_L6V5U5 = 61,
	D3DFMT_X8L8V8U8 = 62,
	D3DFMT_Q8W8V8U8 = 63,
	D3DFMT_V16U16 = 64,
	D3DFMT_A2W10V10U10 = 67,
	D3DFMT_UYVY = 1498831189,
	D3DFMT_R8G8_B8G8 = 1195525970,
	D3DFMT_YUY2 = 844715353,
	D3DFMT_G8R8_G8B8 = 1111970375,
	D3DFMT_DXT1 = 827611204,
	D3DFMT_DXT2 = 844388420,
	D3DFMT_DXT3 = 861165636,
	D3DFMT_DXT4 = 877942852,
	D3DFMT_DXT5 = 894720068,
	D3DFMT_D16_LOCKABLE = 70,
	D3DFMT_D32 = 71,
	D3DFMT_D15S1 = 73,
	D3DFMT_D24S8 = 75,
	D3DFMT_D24X8 = 77,
	D3DFMT_D24X4S4 = 79,
	D3DFMT_D16 = 80,
	D3DFMT_D32F_LOCKABLE = 82,
	D3DFMT_D24FS8 = 83,
	D3DFMT_L16 = 81,
	D3DFMT_VERTEXDATA = 100,
	D3DFMT_INDEX16 = 101,
	D3DFMT_INDEX32 = 102,
	D3DFMT_Q16W16V16U16 = 110,
	D3DFMT_MULTI2_ARGB8 = 827606349,
	D3DFMT_R16F = 111,
	D3DFMT_G16R16F = 112,
	D3DFMT_A16B16G16R16F = 113,
	D3DFMT_R32F = 114,
	D3DFMT_G32R32F = 115,
	D3DFMT_A32B32G32R32F = 116,
	D3DFMT_CxV8U8 = 117,
	D3DFMT_FORCE_DWORD = 2147483647
} D3DFORMAT;

typedef enum
{
	D3DDEVTYPE_HAL = 1,
	D3DDEVTYPE_REF = 2,
	D3DDEVTYPE_SW = 3,
	D3DDEVTYPE_NULLREF = 4,
	D3DDEVTYPE_FORCE_DWORD = 2147483647
} D3DDEVTYPE;

typedef enum
{
	D3DRTYPE_SURFACE = 1,
	D3DRTYPE_VOLUME = 2,
	D3DRTYPE_TEXTURE = 3,
	D3DRTYPE_VOLUMETEXTURE = 4,
	D3DRTYPE_CUBETEXTURE = 5,
	D3DRTYPE_VERTEXBUFFER = 6,
	D3DRTYPE_INDEXBUFFER = 7,
	D3DRTYPE_FORCE_DWORD = 2147483647
} D3DRESOURCETYPE;

typedef enum
{
	D3DMULTISAMPLE_NONE = 0,
	D3DMULTISAMPLE_NONMASKABLE = 1,
	D3DMULTISAMPLE_2_SAMPLES = 2,
	D3DMULTISAMPLE_3_SAMPLES = 3,
	D3DMULTISAMPLE_4_SAMPLES = 4,
	D3DMULTISAMPLE_5_SAMPLES = 5,
	D3DMULTISAMPLE_6_SAMPLES = 6,
	D3DMULTISAMPLE_7_SAMPLES = 7,
	D3DMULTISAMPLE_8_SAMPLES = 8,
	D3DMULTISAMPLE_9_SAMPLES = 9,
	D3DMULTISAMPLE_10_SAMPLES = 10,
	D3DMULTISAMPLE_11_SAMPLES = 11,
	D3DMULTISAMPLE_12_SAMPLES = 12,
	D3DMULTISAMPLE_13_SAMPLES = 13,
	D3DMULTISAMPLE_14_SAMPLES = 14,
	D3DMULTISAMPLE_15_SAMPLES = 15,
	D3DMULTISAMPLE_16_SAMPLES = 16,
	D3DMULTISAMPLE_FORCE_DWORD = 2147483647
} D3DMULTISAMPLE_TYPE;

struct IUnknown
{
	void *_vptr$IUnknown;
};

struct D3DADAPTER_IDENTIFIER9
{
	char Driver[512];
	char Description[512];
	char DeviceName[32];
	LARGE_INTEGER DriverVersion;
	uint32_t VendorId;
	uint32_t DeviceId;
	uint32_t SubSysId;
	int32_t Revision;
	char DeviceIdentifier[16];
	int32_t WHQLLevel;
};

struct D3DDISPLAYMODE
{
	uint32_t Width;
	int32_t Height;
	void *RefreshRate;
	int32_t Format;
};

struct D3DPSHADERCAPS2_0
{
	int32_t Caps;
	int32_t DynamicFlowControlDepth;
	uint32_t NumTemps;
	int32_t StaticFlowControlDepth;
	uint32_t NumInstructionSlots;
};

struct D3DVSHADERCAPS2_0
{
	int32_t Caps;
	int32_t DynamicFlowControlDepth;
	uint32_t NumTemps;
	int32_t StaticFlowControlDepth;
};

struct D3DCAPS9
{
	int32_t DeviceType;
	int32_t AdapterOrdinal;
	int32_t Caps;
	int32_t Caps2;
	int32_t Caps3;
	int32_t PresentationIntervals;
	int32_t CursorCaps;
	int32_t DevCaps;
	int32_t PrimitiveMiscCaps;
	int32_t RasterCaps;
	int32_t ZCmpCaps;
	uint32_t SrcBlendCaps;
	uint32_t DestBlendCaps;
	int32_t AlphaCmpCaps;
	int32_t ShadeCaps;
	char TextureCaps[4];
	char TextureFilterCaps[4];
	char CubeTextureFilterCaps[4];
	char VolumeTextureFilterCaps[4];
	char TextureAddressCaps[4];
	char VolumeTextureAddressCaps[4];
	int32_t LineCaps;
	char MaxTextureWidth[4];
	char MaxTextureHeight[4];
	int32_t MaxVolumeExtent;
	char MaxTextureRepeat[4];
	char MaxTextureAspectRatio[4];
	int32_t MaxAnisotropy;
	int32_t MaxVertexW;
	int32_t GuardBandLeft;
	int32_t GuardBandTop;
	int32_t GuardBandRight;
	int32_t GuardBandBottom;
	int32_t ExtentsAdjust;
	int32_t StencilCaps;
	int32_t FVFCaps;
	char TextureOpCaps[4];
	char MaxTextureBlendStages[4];
	char MaxSimultaneousTextures[4];
	int32_t VertexProcessingCaps;
	int32_t MaxActiveLights;
	int32_t MaxUserClipPlanes;
	uint32_t MaxVertexBlendMatrices;
	uint32_t MaxVertexBlendMatrixIndex;
	uint32_t MaxPointSize;
	uint32_t MaxPrimitiveCount;
	uint32_t MaxVertexIndex;
	int32_t MaxStreams;
	uint32_t MaxStreamStride;
	char VertexShaderVersion[4];
	int32_t MaxVertexShaderConst;
	char PixelShaderVersion[4];
	int32_t PixelShader1xMaxValue;
	int32_t DevCaps2;
	int32_t MaxNpatchTessellationLevel;
	int32_t Reserved5;
	int32_t MasterAdapterOrdinal;
	int32_t AdapterOrdinalInGroup;
	uint32_t NumberOfAdaptersInGroup;
	int32_t DeclTypes;
	uint32_t NumSimultaneousRTs;
	int32_t StretchRectFilterCaps;
	D3DVSHADERCAPS2_0 VS20Caps;
	D3DPSHADERCAPS2_0 PS20Caps;
	char VertexTextureFilterCaps[4];
	int32_t MaxVShaderInstructionsExecuted;
	int32_t MaxPShaderInstructionsExecuted;
	int32_t MaxVertexShader30InstructionSlots;
	int32_t MaxPixelShader30InstructionSlots;
};

struct D3DPRESENT_PARAMETERS_
{
	void *BackBufferWidth;
	void *BackBufferHeight;
	void *BackBufferFormat;
	uint32_t BackBufferCount;
	int32_t MultiSampleType;
	int32_t MultiSampleQuality;
	int32_t SwapEffect;
	int32_t hDeviceWindow;
	int32_t Windowed;
	int32_t EnableAutoDepthStencil;
	int32_t AutoDepthStencilFormat;
	uint32_t Flags;
	void *FullScreen_RefreshRateInHz;
	int32_t PresentationInterval;
};

typedef enum
{
	D3DSWAPEFFECT_DISCARD = 1,
	D3DSWAPEFFECT_FLIP = 2,
	D3DSWAPEFFECT_COPY = 3,
	D3DSWAPEFFECT_FORCE_DWORD = 2147483647
} D3DSWAPEFFECT;

struct IDirect3DDevice9
{
};

struct GUID
{
	int32_t Data1;
	int16_t Data2;
	int16_t Data3;
	uint64_t Data4;
};

typedef enum
{
	D3DBACKBUFFER_TYPE_MONO = 0,
	D3DBACKBUFFER_TYPE_LEFT = 1,
	D3DBACKBUFFER_TYPE_RIGHT = 2,
	D3DBACKBUFFER_TYPE_FORCE_DWORD = 2147483647
} D3DBACKBUFFER_TYPE;

typedef enum
{
	D3DPOOL_DEFAULT = 0,
	D3DPOOL_MANAGED = 1,
	D3DPOOL_SYSTEMMEM = 2,
	D3DPOOL_SCRATCH = 3,
	D3DPOOL_FORCE_DWORD = 2147483647
} D3DPOOL;

typedef enum
{
	D3DTEXF_NONE = 0,
	D3DTEXF_POINT = 1,
	D3DTEXF_LINEAR = 2,
	D3DTEXF_ANISOTROPIC = 3,
	D3DTEXF_PYRAMIDALQUAD = 6,
	D3DTEXF_GAUSSIANQUAD = 7,
	D3DTEXF_FORCE_DWORD = 2147483647
} D3DTEXTUREFILTERTYPE;

typedef enum
{
	D3DTS_VIEW = 2,
	D3DTS_PROJECTION = 3,
	D3DTS_TEXTURE0 = 16,
	D3DTS_TEXTURE1 = 17,
	D3DTS_TEXTURE2 = 18,
	D3DTS_TEXTURE3 = 19,
	D3DTS_TEXTURE4 = 20,
	D3DTS_TEXTURE5 = 21,
	D3DTS_TEXTURE6 = 22,
	D3DTS_TEXTURE7 = 23,
	D3DTS_FORCE_DWORD = 2147483647
} D3DTRANSFORMSTATETYPE;

typedef enum
{
	D3DRS_ZENABLE = 7,
	D3DRS_FILLMODE = 8,
	D3DRS_SHADEMODE = 9,
	D3DRS_ZWRITEENABLE = 14,
	D3DRS_ALPHATESTENABLE = 15,
	D3DRS_LASTPIXEL = 16,
	D3DRS_SRCBLEND = 19,
	D3DRS_DESTBLEND = 20,
	D3DRS_CULLMODE = 22,
	D3DRS_ZFUNC = 23,
	D3DRS_ALPHAREF = 24,
	D3DRS_ALPHAFUNC = 25,
	D3DRS_DITHERENABLE = 26,
	D3DRS_ALPHABLENDENABLE = 27,
	D3DRS_FOGENABLE = 28,
	D3DRS_SPECULARENABLE = 29,
	D3DRS_FOGCOLOR = 34,
	D3DRS_FOGTABLEMODE = 35,
	D3DRS_FOGSTART = 36,
	D3DRS_FOGEND = 37,
	D3DRS_FOGDENSITY = 38,
	D3DRS_RANGEFOGENABLE = 48,
	D3DRS_STENCILENABLE = 52,
	D3DRS_STENCILFAIL = 53,
	D3DRS_STENCILZFAIL = 54,
	D3DRS_STENCILPASS = 55,
	D3DRS_STENCILFUNC = 56,
	D3DRS_STENCILREF = 57,
	D3DRS_STENCILMASK = 58,
	D3DRS_STENCILWRITEMASK = 59,
	D3DRS_TEXTUREFACTOR = 60,
	D3DRS_WRAP0 = 128,
	D3DRS_WRAP1 = 129,
	D3DRS_WRAP2 = 130,
	D3DRS_WRAP3 = 131,
	D3DRS_WRAP4 = 132,
	D3DRS_WRAP5 = 133,
	D3DRS_WRAP6 = 134,
	D3DRS_WRAP7 = 135,
	D3DRS_CLIPPING = 136,
	D3DRS_LIGHTING = 137,
	D3DRS_AMBIENT = 139,
	D3DRS_FOGVERTEXMODE = 140,
	D3DRS_COLORVERTEX = 141,
	D3DRS_LOCALVIEWER = 142,
	D3DRS_NORMALIZENORMALS = 143,
	D3DRS_DIFFUSEMATERIALSOURCE = 145,
	D3DRS_SPECULARMATERIALSOURCE = 146,
	D3DRS_AMBIENTMATERIALSOURCE = 147,
	D3DRS_EMISSIVEMATERIALSOURCE = 148,
	D3DRS_VERTEXBLEND = 151,
	D3DRS_CLIPPLANEENABLE = 152,
	D3DRS_POINTSIZE = 154,
	D3DRS_POINTSIZE_MIN = 155,
	D3DRS_POINTSPRITEENABLE = 156,
	D3DRS_POINTSCALEENABLE = 157,
	D3DRS_POINTSCALE_A = 158,
	D3DRS_POINTSCALE_B = 159,
	D3DRS_POINTSCALE_C = 160,
	D3DRS_MULTISAMPLEANTIALIAS = 161,
	D3DRS_MULTISAMPLEMASK = 162,
	D3DRS_PATCHEDGESTYLE = 163,
	D3DRS_DEBUGMONITORTOKEN = 165,
	D3DRS_POINTSIZE_MAX = 166,
	D3DRS_INDEXEDVERTEXBLENDENABLE = 167,
	D3DRS_COLORWRITEENABLE = 168,
	D3DRS_TWEENFACTOR = 170,
	D3DRS_BLENDOP = 171,
	D3DRS_POSITIONDEGREE = 172,
	D3DRS_NORMALDEGREE = 173,
	D3DRS_SCISSORTESTENABLE = 174,
	D3DRS_SLOPESCALEDEPTHBIAS = 175,
	D3DRS_ANTIALIASEDLINEENABLE = 176,
	D3DRS_MINTESSELLATIONLEVEL = 178,
	D3DRS_MAXTESSELLATIONLEVEL = 179,
	D3DRS_ADAPTIVETESS_X = 180,
	D3DRS_ADAPTIVETESS_Y = 181,
	D3DRS_ADAPTIVETESS_Z = 182,
	D3DRS_ADAPTIVETESS_W = 183,
	D3DRS_ENABLEADAPTIVETESSELLATION = 184,
	D3DRS_TWOSIDEDSTENCILMODE = 185,
	D3DRS_CCW_STENCILFAIL = 186,
	D3DRS_CCW_STENCILZFAIL = 187,
	D3DRS_CCW_STENCILPASS = 188,
	D3DRS_CCW_STENCILFUNC = 189,
	D3DRS_COLORWRITEENABLE1 = 190,
	D3DRS_COLORWRITEENABLE2 = 191,
	D3DRS_COLORWRITEENABLE3 = 192,
	D3DRS_BLENDFACTOR = 193,
	D3DRS_SRGBWRITEENABLE = 194,
	D3DRS_DEPTHBIAS = 195,
	D3DRS_WRAP8 = 198,
	D3DRS_WRAP9 = 199,
	D3DRS_WRAP10 = 200,
	D3DRS_WRAP11 = 201,
	D3DRS_WRAP12 = 202,
	D3DRS_WRAP13 = 203,
	D3DRS_WRAP14 = 204,
	D3DRS_WRAP15 = 205,
	D3DRS_SEPARATEALPHABLENDENABLE = 206,
	D3DRS_SRCBLENDALPHA = 207,
	D3DRS_DESTBLENDALPHA = 208,
	D3DRS_BLENDOPALPHA = 209,
	D3DRS_FORCE_DWORD = 2147483647
} D3DRENDERSTATETYPE;

typedef enum
{
	D3DSBT_ALL = 1,
	D3DSBT_PIXELSTATE = 2,
	D3DSBT_VERTEXSTATE = 3,
	D3DSBT_FORCE_DWORD = 2147483647
} D3DSTATEBLOCKTYPE;

typedef enum
{
	D3DTSS_COLOROP = 1,
	D3DTSS_COLORARG1 = 2,
	D3DTSS_COLORARG2 = 3,
	D3DTSS_ALPHAOP = 4,
	D3DTSS_ALPHAARG1 = 5,
	D3DTSS_ALPHAARG2 = 6,
	D3DTSS_BUMPENVMAT00 = 7,
	D3DTSS_BUMPENVMAT01 = 8,
	D3DTSS_BUMPENVMAT10 = 9,
	D3DTSS_BUMPENVMAT11 = 10,
	D3DTSS_TEXCOORDINDEX = 11,
	D3DTSS_BUMPENVLSCALE = 22,
	D3DTSS_BUMPENVLOFFSET = 23,
	D3DTSS_TEXTURETRANSFORMFLAGS = 24,
	D3DTSS_COLORARG0 = 26,
	D3DTSS_ALPHAARG0 = 27,
	D3DTSS_RESULTARG = 28,
	D3DTSS_CONSTANT = 32,
	D3DTSS_FORCE_DWORD = 2147483647
} D3DTEXTURESTAGESTATETYPE;

typedef enum
{
	D3DSAMP_ADDRESSU = 1,
	D3DSAMP_ADDRESSV = 2,
	D3DSAMP_ADDRESSW = 3,
	D3DSAMP_BORDERCOLOR = 4,
	D3DSAMP_MAGFILTER = 5,
	D3DSAMP_MINFILTER = 6,
	D3DSAMP_MIPFILTER = 7,
	D3DSAMP_MIPMAPLODBIAS = 8,
	D3DSAMP_MAXMIPLEVEL = 9,
	D3DSAMP_MAXANISOTROPY = 10,
	D3DSAMP_SRGBTEXTURE = 11,
	D3DSAMP_ELEMENTINDEX = 12,
	D3DSAMP_DMAPOFFSET = 13,
	D3DSAMP_FORCE_DWORD = 2147483647
} D3DSAMPLERSTATETYPE;

typedef enum
{
	D3DPT_POINTLIST = 1,
	D3DPT_LINELIST = 2,
	D3DPT_LINESTRIP = 3,
	D3DPT_TRIANGLELIST = 4,
	D3DPT_TRIANGLESTRIP = 5,
	D3DPT_TRIANGLEFAN = 6,
	D3DPT_FORCE_DWORD = 2147483647
} D3DPRIMITIVETYPE;

typedef enum
{
	D3DQUERYTYPE_VCACHE = 4,
	D3DQUERYTYPE_RESOURCEMANAGER = 5,
	D3DQUERYTYPE_VERTEXSTATS = 6,
	D3DQUERYTYPE_EVENT = 8,
	D3DQUERYTYPE_OCCLUSION = 9,
	D3DQUERYTYPE_TIMESTAMP = 10,
	D3DQUERYTYPE_TIMESTAMPDISJOINT = 11,
	D3DQUERYTYPE_TIMESTAMPFREQ = 12,
	D3DQUERYTYPE_PIPELINETIMINGS = 13,
	D3DQUERYTYPE_INTERFACETIMINGS = 14,
	D3DQUERYTYPE_VERTEXTIMINGS = 15,
	D3DQUERYTYPE_PIXELTIMINGS = 16,
	D3DQUERYTYPE_BANDWIDTHTIMINGS = 17,
	D3DQUERYTYPE_CACHEUTILIZATION = 18
} D3DQUERYTYPE;

struct D3DDEVICE_CREATION_PARAMETERS
{
	int32_t AdapterOrdinal;
	int32_t DeviceType;
	int32_t hFocusWindow;
	uint32_t BehaviorFlags;
};

struct IDirect3DSurface9
{
};

struct D3DRASTER_STATUS
{
	int32_t InVBlank;
	int32_t ScanLine;
};

struct IDirect3DBaseTexture9
{
};

struct $_3551
{
	int32_t _11;
	int32_t _12;
	int32_t _13;
	int32_t _14;
	int32_t _21;
	int32_t _22;
	int32_t _23;
	int32_t _24;
	int32_t _31;
	int32_t _32;
	int32_t _33;
	int32_t _34;
	int32_t _41;
	int32_t _42;
	int32_t _43;
	int32_t _44;
};

union $_3550
{
	$_3551 unnamed_field;
	uint8_t m[64];
};

struct D3DMATRIX
{
	$_3550 unnamed_field;
};

struct D3DVIEWPORT9
{
	int32_t X;
	int32_t Y;
	uint32_t Width;
	int32_t Height;
	int32_t MinZ;
	int32_t MaxZ;
};

struct D3DCOLORVALUE
{
	int32_t r;
	int32_t g;
	int32_t b;
	int32_t a;
};

struct D3DMATERIAL9
{
	D3DCOLORVALUE Diffuse;
	uint8_t Ambient[16];
	char Specular[16];
	uint8_t Emissive[16];
	int32_t Power;
};

struct D3DVECTOR
{
	int32_t x;
	int32_t y;
	int32_t z;
};

struct D3DLIGHT9
{
	int32_t Type;
	uint8_t Diffuse[16];
	char Specular[16];
	uint8_t Ambient[16];
	D3DVECTOR Position;
	vec3_t Direction;
	int32_t Range;
	int32_t Falloff;
	int32_t Attenuation0;
	int32_t Attenuation1;
	int32_t Attenuation2;
	int32_t Theta;
	int32_t Phi;
};

struct D3DCLIPSTATUS9
{
	int32_t ClipUnion;
	int32_t ClipIntersection;
};

struct tagPALETTEENTRY
{
	int8_t peRed;
	int8_t peGreen;
	int8_t peBlue;
	int8_t peFlags;
};

struct IDirect3DVertexBuffer9
{
};

struct IDirect3DVertexDeclaration9
{
};

struct IDirect3DVertexShader9
{
};

struct IDirect3DIndexBuffer9
{
};

struct IDirect3DPixelShader9
{
};

struct IDirect3DResource9
{
};

struct IDirect3DSwapChain9
{
};

struct RGNDATAHEADER
{
	uint32_t dwSize;
	int32_t iType;
	uint32_t nCount;
	uint32_t nRgnSize;
	uint8_t rcBound[16];
};

struct RGNDATA
{
	RGNDATAHEADER rdh;
	int8_t Buffer;
};

struct IDirect3DTexture9
{
};

struct IDirect3DVolumeTexture9
{
};

struct IDirect3DCubeTexture9
{
};

struct D3DRECT
{
	int32_t x1;
	int32_t y1;
	int32_t x2;
	int32_t y2;
};

typedef enum
{
	D3DLIGHT_POINT = 1,
	D3DLIGHT_SPOT = 2,
	D3DLIGHT_DIRECTIONAL = 3,
	D3DLIGHT_FORCE_DWORD = 2147483647
} D3DLIGHTTYPE;

struct IDirect3DStateBlock9
{
};

struct D3DVERTEXELEMENT9
{
	int16_t Stream;
	uint16_t Offset;
	int8_t Type;
	int8_t Method;
	int8_t Usage;
	uint8_t UsageIndex;
};

struct D3DRECTPATCH_INFO
{
	uint32_t StartVertexOffsetWidth;
	uint32_t StartVertexOffsetHeight;
	uint32_t Width;
	int32_t Height;
	uint32_t Stride;
	int32_t Basis;
	int32_t Degree;
};

struct D3DTRIPATCH_INFO
{
	uint32_t StartVertexOffset;
	uint32_t NumVertices;
	int32_t Basis;
	int32_t Degree;
};

struct IDirect3DQuery9
{
};

typedef enum
{
	D3DCUBEMAP_FACE_POSITIVE_X = 0,
	D3DCUBEMAP_FACE_NEGATIVE_X = 1,
	D3DCUBEMAP_FACE_POSITIVE_Y = 2,
	D3DCUBEMAP_FACE_NEGATIVE_Y = 3,
	D3DCUBEMAP_FACE_POSITIVE_Z = 4,
	D3DCUBEMAP_FACE_NEGATIVE_Z = 5,
	D3DCUBEMAP_FACE_FORCE_DWORD = 2147483647
} D3DCUBEMAP_FACES;

typedef enum
{
	D3DBASIS_BEZIER = 0,
	D3DBASIS_BSPLINE = 1,
	D3DBASIS_CATMULL_ROM = 2,
	D3DBASIS_FORCE_DWORD = 2147483647
} D3DBASISTYPE;

typedef enum
{
	D3DDEGREE_LINEAR = 1,
	D3DDEGREE_QUADRATIC = 2,
	D3DDEGREE_CUBIC = 3,
	D3DDEGREE_QUINTIC = 5,
	D3DDEGREE_FORCE_DWORD = 2147483647
} D3DDEGREETYPE;

struct D3DSURFACE_DESC
{
	int32_t Format;
	int32_t Type;
	int32_t Usage;
	int32_t Pool;
	int32_t MultiSampleType;
	int32_t MultiSampleQuality;
	uint32_t Width;
	int32_t Height;
};

struct D3DLOCKED_RECT
{
	int32_t Pitch;
	int32_t pBits;
};

struct D3DVERTEXBUFFER_DESC
{
	int32_t Format;
	int32_t Type;
	int32_t Usage;
	int32_t Pool;
	uint32_t Size;
	int32_t FVF;
};

struct D3DINDEXBUFFER_DESC
{
	int32_t Format;
	int32_t Type;
	int32_t Usage;
	int32_t Pool;
	uint32_t Size;
};

struct D3DVOLUME_DESC
{
	int32_t Format;
	int32_t Type;
	int32_t Usage;
	int32_t Pool;
	uint32_t Width;
	int32_t Height;
	int32_t Depth;
};

struct D3DLOCKED_BOX
{
	int32_t RowPitch;
	int32_t SlicePitch;
	int32_t pBits;
};

struct IDirect3DVolume9
{
};

struct D3DBOX
{
	int32_t Left;
	int32_t Top;
	int32_t Right;
	int32_t Bottom;
	int32_t Front;
	int32_t Back;
};

struct CVAOPacketFixedFunction
{
};

struct CVAOPacket
{
};

struct COpenGLVAO
{
	void *_vptr$COpenGLVAO;
	uint32_t mpVAOID;
	int32_t mpVAStart;
	uint32_t mSize;
	vec3_t mColorArray[2];
	vec3_t mSecondaryColorArray[2];
	vec3_t mNormalArray[2];
	vec3_t mVertexArray[2];
	uint8_t mTexCoordArrays[192];
	uint8_t mGenericArrays[384];
};

typedef enum
{
	UNINITIALIZED_VAO_STATUS = 0,
	USING_GENERIC_VAO = 1,
	USING_VIRGIN_VAO = 2,
	USING_CACHED_VAO = 3
} VAOStatus;

struct CColorArray
{
};

struct CSecondaryColorArray
{
};

struct CNormalArray
{
};

struct CVertexArray
{
};

struct CBaseVA
{
	void *_vptr$CBaseVA;
	int8_t mEnabled;
	int8_t mNeedsValidation;
	char pad0[2];
	uint32_t mSize;
	int32_t mType;
	uint32_t mStride;
	int32_t mPointer;
};

struct CTexCoordArray
{
};

struct VertexProgramStreamState
{
	int8_t mNeedsValidation;
	int8_t mEnabled;
	char pad0[2];
	uint32_t mVSize;
	int32_t mVType;
	int8_t mNormalized;
	char pad1[3];
	uint32_t mStride;
	int32_t mpStream;
};

struct CVAOPacketProgrammable
{
};

struct COpenGLMatrix
{
	uint8_t m[64];
};

typedef enum
{
	ATITextFragmentProgram = 0,
	NVidiaRegisterCombinersProgram = 1,
	ARBFragmentProgram = 2
} OpenGLPixelShaderType;

struct ProgrammableShaderType
{
	int8_t mUsed;
	char pad0[3];
	int32_t mStream;
	uint32_t mStreamOffset;
	uint32_t mVSize;
	int32_t mVType;
	int8_t mNormalized;
	char pad1[3];
	uint32_t mStride;
};

struct DXVector3
{
	vec3_t m;
};

struct DXVector4
{
	uint8_t m[16];
};

struct LightInfoType
{
	int8_t Enabled;
	char pad0[3];
	int32_t Type;
	int32_t Range;
	DXVector4 Diffuse;
	char Specular[16];
	uint8_t Ambient[16];
	vec3_t Direction;
	vec3_t Position;
	vec3_t DirectionCS;
	int32_t Exponent;
	int32_t Cutoff;
	int32_t Theta;
	int32_t Phi;
	int32_t Falloff;
	int32_t Attenuation0;
	int32_t Attenuation1;
	int32_t Attenuation2;
	vec3_t CSDirection;
	vec3_t CSPosition;
	int32_t Range2;
	vec3_t VdLd;
	int32_t CosHalfTheta;
	int32_t CosHalfPhi;
	int32_t C1;
};

struct CDirect3DVertexShader
{
	char pad0[404];
	uint32_t mRefCount;
	int8_t mRunInSoftware;
};

struct CDirect3DPixelShader
{
	char pad0[4];
	uint32_t mRefCount;
	char mTextureUseMask[4];
};

struct CTexStage
{
	int8_t mIsProgrammableOnly;
	char pad0[3];
	int32_t mTex;
	char mAddressU[4];
	char mAddressV[4];
	char mAddressW[4];
	int32_t mMinFilter;
	int32_t mMagFilter;
	int32_t mMipFilter;
	int32_t mAnisotropy;
	int32_t mLodBias;
	int32_t mBorderColor;
	int32_t mColorOp;
	int32_t mColorArg0;
	int32_t mColorArg1;
	int32_t mColorArg2;
	int32_t mAlphaOp;
	int32_t mAlphaArg0;
	int32_t mAlphaArg1;
	int32_t mAlphaArg2;
	uint32_t mTransformFlags;
	uint32_t mCoordIndex;
	uint8_t mTexFactor[16];
	matrix4_t mTexMatrix;
};

typedef enum
{
	D3DTADDRESS_WRAP = 1,
	D3DTADDRESS_MIRROR = 2,
	D3DTADDRESS_CLAMP = 3,
	D3DTADDRESS_BORDER = 4,
	D3DTADDRESS_MIRRORONCE = 5,
	D3DTADDRESS_FORCE_DWORD = 2147483647
} D3DTEXTUREADDRESS;

typedef enum
{
	D3DTOP_DISABLE = 1,
	D3DTOP_SELECTARG1 = 2,
	D3DTOP_SELECTARG2 = 3,
	D3DTOP_MODULATE = 4,
	D3DTOP_MODULATE2X = 5,
	D3DTOP_MODULATE4X = 6,
	D3DTOP_ADD = 7,
	D3DTOP_ADDSIGNED = 8,
	D3DTOP_ADDSIGNED2X = 9,
	D3DTOP_SUBTRACT = 10,
	D3DTOP_ADDSMOOTH = 11,
	D3DTOP_BLENDDIFFUSEALPHA = 12,
	D3DTOP_BLENDTEXTUREALPHA = 13,
	D3DTOP_BLENDFACTORALPHA = 14,
	D3DTOP_BLENDTEXTUREALPHAPM = 15,
	D3DTOP_BLENDCURRENTALPHA = 16,
	D3DTOP_PREMODULATE = 17,
	D3DTOP_MODULATEALPHA_ADDCOLOR = 18,
	D3DTOP_MODULATECOLOR_ADDALPHA = 19,
	D3DTOP_MODULATEINVALPHA_ADDCOLOR = 20,
	D3DTOP_MODULATEINVCOLOR_ADDALPHA = 21,
	D3DTOP_BUMPENVMAP = 22,
	D3DTOP_BUMPENVMAPLUMINANCE = 23,
	D3DTOP_DOTPRODUCT3 = 24,
	D3DTOP_MULTIPLYADD = 25,
	D3DTOP_LERP = 26,
	D3DTOP_FORCE_DWORD = 2147483647
} D3DTEXTUREOP;

typedef enum
{
	D3DTTFF_DISABLE = 0,
	D3DTTFF_COUNT1 = 1,
	D3DTTFF_COUNT2 = 2,
	D3DTTFF_COUNT3 = 3,
	D3DTTFF_COUNT4 = 4,
	D3DTTFF_PROJECTED = 256,
	D3DTTFF_FORCE_DWORD = 2147483647
} D3DTEXTURETRANSFORMFLAGS;

struct VertexProgramState
{
	uint32_t mOpenGLProgramID;
	uint8_t mStreams[384];
};

struct CMemoryBuffer
{
	void *_vptr$CMemoryBuffer;
	void *mRawBufferPtr;
	void *mAlignedBufferPtr;
	uint32_t mLength;
	int32_t mOwner;
};

typedef enum
{
	IS_OWNER = 0,
	IS_NOT_OWNER = 1
} OwnershipType;

struct List_impl
{
	uint64_t _M_node;
};

struct List_node_base
{
	int32_t _M_next;
	int32_t _M_prev;
};

struct CCacheInfoBlock
{
	char _vptr$CCacheInfoBlock[4];
	int8_t Dirty;
};

struct TextureInfoType
{
	uint32_t mpTexID;
	int32_t mTexWrapS;
	int32_t mTexWrapT;
	int32_t mTexWrapR;
	int32_t mTexBorderColor;
	int32_t mTexMinFilter;
	int32_t mTexMagFilter;
	int32_t mTexLastLevel;
	int32_t mTexAnisotropicFilter;
};

struct COpenGLTexture
{
	char _vptr$COpenGLTexture[4];
	TextureInfoType mTextureInfo;
	uint32_t mWidth;
	int32_t mHeight;
	int32_t mDepth;
};

struct ParameterType
{
	uint32_t NeedsValidation;
	uint8_t v[16];
};

struct D3DXMATRIX
{
};

struct D3DXFLOAT16
{
	int16_t value;
};

struct D3DXVECTOR4
{
	int32_t x;
	int32_t y;
	int32_t z;
	int32_t w;
};

struct AttribInfo
{
	uint32_t Size;
	uint32_t Stride;
	int32_t Type;
	void *Ptr;
	uint8_t Storage[16];
};

struct CDirect3DSurface
{
	char pad0[4];
	uint32_t mRefCount;
	int32_t mSurfaceType;
	uint32_t mCubemapID;
	int32_t mLevel;
	uint32_t mWidth;
	int32_t mHeight;
	int32_t mFormat;
	int32_t mpSurfaceMemory;
	int8_t mIsDirty;
	char pad1[3];
	char mpOpenGLTextureInfo[4];
	int8_t mOwnOpenGLTextureInfo;
	char pad2[3];
	int32_t mOpenGLInternalFormat;
	int32_t mOpenGLFormat;
	int32_t mOpenGLElementType;
};

typedef enum
{
	TEXTURE_SURFACE = 0,
	CUBE_SURFACE = 1,
	VOLUME_SURFACE = 2
} SurfaceType;

struct CDirect3DVolume
{
	char pad0[4];
	uint32_t mRefCount;
	int32_t mLevel;
	uint32_t mWidth;
	int32_t mHeight;
	int32_t mDepth;
	int32_t mFormat;
	int32_t mpSurfaceMemory;
	int8_t mIsDirty;
	char pad1[3];
	char mpOpenGLTextureInfo[4];
	int32_t mOpenGLInternalFormat;
	int32_t mOpenGLFormat;
	int32_t mOpenGLElementType;
};

struct CDirect3DCubeTexture
{
	char pad0[56];
	uint32_t mRefCount;
	uint32_t mEdgeLength;
	int32_t mLevels;
	uint8_t mSurfaceFaceIndices[24];
	char mTextureMemory[20];
	vec3_t mSurfaces;
};

struct true_type
{
};

struct CDirect3DIndexBuffer
{
	char pad0[4];
	uint32_t mRefCount;
	uint32_t mLength;
	CMemoryBuffer mIndexBufferMemory;
	uint32_t mFormatSize;
	int32_t mUsage;
	int32_t mLockStart;
	uint32_t mLockSize;
	int8_t mHasBeenLocked;
};

struct COpenGLATITextFragmentShader
{
	char pad0[12];
	uint32_t mProgramID;
};

struct COpenGLNVidiaRegisterCombinersProgram
{
	char pad0[12];
	int32_t mpCallbackFunc;
	uint32_t mNumConstants;
};

struct COpenGLARBFragmentProgram
{
	char pad0[12];
	char mName[4];
	int32_t mCode;
	uint32_t mProgramID;
};

struct CDirect3DSwapChain
{
	char pad0[4];
	uint32_t mRefCount;
	void *mBackBuffer;
};

struct CFence
{
	uint32_t mFenceID;
	int32_t mStart;
	uint32_t mSizeInBytes;
	uint32_t mFrameCount;
};

struct CDirect3DVertexDeclaration
{
	char pad0[4];
	uint32_t mRefCount;
	uint32_t mNumElements;
	int32_t mpVertexElements;
};

struct FreeRequest
{
	void *mPtr;
	uint32_t mLength;
	int32_t mDelay;
};

struct CTexUnit
{
	int8_t mIsProgramableOnly;
	uint8_t mTargetEnabled[3];
	vec3_t mTexID;
	vec3_t mTexWrapS;
	vec3_t mTexWrapT;
	vec3_t mTexWrapR;
	vec3_t mTexBorderColor;
	vec3_t mTexMinFilter;
	vec3_t mTexMagFilter;
	vec3_t mTexAnisotropicFilter;
	vec3_t mTexLastLevel;
	int32_t mCombinerColorOp;
	int32_t mCombinerColorSource0;
	int32_t mCombinerColorOperand0;
	int32_t mCombinerColorSource1;
	int32_t mCombinerColorOperand1;
	int32_t mCombinerColorSource2;
	int32_t mCombinerColorOperand2;
	int32_t mCombinerAlphaOp;
	int32_t mCombinerAlphaSource0;
	int32_t mCombinerAlphaOperand0;
	int32_t mCombinerAlphaSource1;
	int32_t mCombinerAlphaOperand1;
	int32_t mCombinerAlphaSource2;
	int32_t mCombinerAlphaOperand2;
	int32_t mCombinerRGBScale;
	int32_t mCombinerAlphaScale;
	uint8_t mTexFactor[16];
	int32_t mLodBias;
	matrix4_t mTexMatrix;
	uint8_t mTexCoordArray[24];
	int32_t mTexGenEnable;
	uint8_t mTexGenMode[16];
};

struct OpenGLStateInfoType
{
	char PName[4];
	int32_t PType;
	char SName[4];
};

typedef enum
{
	BOOLEAN = 0,
	INT = 1,
	FLOAT = 2,
	FOUR_BOOLEANS = 3,
	FOUR_FLOATS = 4,
	THREE_FLOATS = 5,
	MATRIX = 6,
	FOUR_INTS = 7,
	LFOUR_FLOATS = 8,
	LFLOAT = 9,
	MFOUR_FLOATS = 10,
	MFLOAT = 11,
	TEFOUR_FLOATS = 12,
	TEINT = 13,
	TGFOUR_FLOATS = 14,
	TGINT = 15
} OGLSITPTypes;

struct D3DXVECTOR3
{
};

typedef enum
{
	D3DXIFF_BMP = 0,
	D3DXIFF_JPG = 1,
	D3DXIFF_TGA = 2,
	D3DXIFF_PNG = 3,
	D3DXIFF_DDS = 4,
	D3DXIFF_PPM = 5,
	D3DXIFF_DIB = 6,
	D3DXIFF_HDR = 7,
	D3DXIFF_PFM = 8,
	D3DXIFF_FORCE_DWORD = 2147483647
} D3DXIMAGE_FILEFORMAT;

struct D3DXIMAGE_INFO
{
	uint32_t Width;
	int32_t Height;
	int32_t Depth;
	int32_t MipLevels;
	int32_t Format;
	int32_t ResourceType;
	int32_t ImageFileFormat;
};

struct ID3DXFont
{
};

struct ID3DXSprite
{
};

struct D3DXFONT_DESCA
{
	int32_t Height;
	uint32_t Width;
	int32_t Weight;
	int32_t MipLevels;
	int32_t Italic;
	int8_t CharSet;
	int8_t OutputPrecision;
	int8_t Quality;
	int8_t PitchAndFamily;
	char FaceName[32];
};

struct D3DXFONT_DESCW
{
	int32_t Height;
	uint32_t Width;
	int32_t Weight;
	int32_t MipLevels;
	int32_t Italic;
	int8_t CharSet;
	int8_t OutputPrecision;
	int8_t Quality;
	int8_t PitchAndFamily;
	char FaceName[128];
};

struct tagTEXTMETRICA
{
	int32_t tmHeight;
	int32_t tmAscent;
	int32_t tmDescent;
	int32_t tmInternalLeading;
	int32_t tmExternalLeading;
	uint32_t tmAveCharWidth;
	uint32_t tmMaxCharWidth;
	int32_t tmWeight;
	int32_t tmOverhang;
	char tmDigitizedAspectX[4];
	char tmDigitizedAspectY[4];
	int8_t tmFirstChar;
	int8_t tmLastChar;
	int8_t tmDefaultChar;
	int8_t tmBreakChar;
	int8_t tmItalic;
	int8_t tmUnderlined;
	int8_t tmStruckOut;
	int8_t tmPitchAndFamily;
	int8_t tmCharSet;
};

struct tagTEXTMETRICW
{
	int32_t tmHeight;
	int32_t tmAscent;
	int32_t tmDescent;
	int32_t tmInternalLeading;
	int32_t tmExternalLeading;
	uint32_t tmAveCharWidth;
	uint32_t tmMaxCharWidth;
	int32_t tmWeight;
	int32_t tmOverhang;
	char tmDigitizedAspectX[4];
	char tmDigitizedAspectY[4];
	int32_t tmFirstChar;
	int32_t tmLastChar;
	int32_t tmDefaultChar;
	int32_t tmBreakChar;
	int8_t tmItalic;
	int8_t tmUnderlined;
	int8_t tmStruckOut;
	int8_t tmPitchAndFamily;
	int8_t tmCharSet;
};

union $_3575
{
	uint64_t ddckCKDestOverlay;
	int32_t dwEmptyFaceColor;
};

struct DDCOLORKEY
{
	int32_t dwColorSpaceLowValue;
	int32_t dwColorSpaceHighValue;
};

union $_3574
{
	uint32_t dwMipMapCount;
	void *dwRefreshRate;
	uint32_t dwSrcVBHandle;
};

union $_3572
{
	int32_t lPitch;
	uint32_t dwLinearSize;
};

struct $_3561
{
	int32_t overflowed;
	int32_t data;
	uint32_t maxsize;
	uint32_t cursize;
	uint32_t readcount;
	int32_t bit;
};

struct DDSCAPS2
{
	int32_t dwCaps;
	int32_t dwCaps2;
	int32_t dwCaps3;
	$_3561 unnamed_field;
};

union $_3566
{
	uint32_t dwBBitMask;
	uint32_t dwVBitMask;
	uint32_t dwStencilBitMask;
	uint32_t dwBumpLuminanceBitMask;
};

struct $_3562
{
	int32_t min;
	int32_t max;
};

union $_3567
{
	uint32_t dwRGBAlphaBitMask;
	uint32_t dwYUVAlphaBitMask;
	uint32_t dwLuminanceAlphaBitMask;
	uint32_t dwRGBZBitMask;
	uint32_t dwYUVZBitMask;
};

struct $_3563
{
	int32_t min;
	int32_t max;
};

struct $_3565
{
	int16_t wFlipMSTypes;
	int16_t wBltMSTypes;
};

union $_3564
{
	uint32_t dwGBitMask;
	uint32_t dwUBitMask;
	uint32_t dwZBitMask;
	uint32_t dwBumpDvBitMask;
	$_3565 MultiSampleCaps;
};

struct DDPIXELFORMAT
{
	uint32_t dwSize;
	uint32_t dwFlags;
	int32_t dwFourCC;
	$_3562 unnamed_field1;
	$_3563 unnamed_field2;
	$_3564 unnamed_field3;
	$_3566 unnamed_field4;
	$_3567 unnamed_field5;
};

union $_3576
{
	DDPIXELFORMAT ddpfPixelFormat;
	int32_t dwFVF;
};

union $_3573
{
	uint32_t dwBackBufferCount;
	int32_t dwDepth;
};

struct DDSURFACEDESC2
{
	uint32_t dwSize;
	uint32_t dwFlags;
	int32_t dwHeight;
	uint32_t dwWidth;
	$_3572 unnamed_field1;
	$_3573 unnamed_field2;
	$_3574 unnamed_field3;
	int32_t dwAlphaBitDepth;
	int32_t dwReserved;
	int32_t lpSurface;
	$_3575 unnamed_field4;
	DDCOLORKEY ddckCKDestBlt;
	uint64_t ddckCKSrcOverlay;
	uint64_t ddckCKSrcBlt;
	$_3576 unnamed_field5;
	DDSCAPS2 ddsCaps;
	char dwTextureStage[4];
};

struct tagBITMAPFILEHEADER
{
	int16_t bfType;
	uint32_t bfSize;
	int16_t bfReserved1;
	int16_t bfReserved2;
	int32_t bfOffBits;
};

struct tagBITMAPINFO
{
	BITMAPINFOHEADER bmiHeader;
	int32_t bmiColors;
};

struct DXTexColor
{
	int8_t a;
	int8_t r;
	int8_t g;
	int8_t b;
};

struct FIFO
{
	void *_vptr$FIFO;
	int32_t mMaxElements;
	int32_t mpElements;
	int32_t mpHead;
	int32_t mpTail;
	uint32_t mNumElements;
};

struct Tuple
{
	uint8_t v[6];
	char pad0[2];
	int32_t Score;
};

struct CMacGameEngine
{
	void *_vptr$CMacGameEngine;
	int32_t mArgc;
	int32_t mArgv;
	void *mAppHandlerRef;
	void *mWindowHandlerRef;
	int8_t mFakeRightButtonDown;
	char pad0[3];
	int32_t mLastModifierSet;
	int8_t mIsQuitting;
	int8_t mIsRunning;
	int8_t mWheelEventPosted;
};

struct CompressionInfo
{
	uint32_t recordSize;
	int32_t format;
	uint16_t compressionID;
	int16_t samplesPerPacket;
	int16_t bytesPerPacket;
	int16_t bytesPerFrame;
	int16_t bytesPerSample;
	int16_t futureUse1;
};

struct rlimit
{
	uint64_t rlim_cur;
	uint64_t rlim_max;
};

struct unz_global_info_s
{
	uint32_t number_entry;
	uint32_t size_comment;
};

struct tm_unz_s
{
	int32_t tm_sec;
	int32_t tm_min;
	int32_t tm_hour;
	int32_t tm_mday;
	int32_t tm_mon;
	int32_t tm_year;
};

struct unz_file_info_s
{
	char version[4];
	char version_needed[4];
	int32_t flag;
	int32_t compression_method;
	int32_t dosDate;
	int32_t crc;
	uint32_t compressed_size;
	uint32_t uncompressed_size;
	char size_filename[4];
	uint32_t size_file_extra;
	uint32_t size_file_comment;
	uint32_t disk_num_start;
	int32_t internal_fa;
	int32_t external_fa;
	tm_unz_s tmu_date;
};

struct unz_file_info_internal_s
{
	uint32_t offset_curfile;
};
struct $_3555
{
	int32_t file;
	unz_global_info_s gi;
	int32_t byte_before_the_zipfile;
	uint32_t num_file;
	uint32_t pos_in_central_dir;
	int32_t current_file_ok;
	uint32_t central_pos;
	uint32_t size_central_dir;
	uint32_t offset_central_dir;
	unz_file_info_s cur_file_info;
	unz_file_info_internal_s cur_file_info_internal;
	int32_t pfile_in_zip_read;
};

struct z_stream_s
{
	int32_t next_in;
	int32_t avail_in;
	int32_t total_in;
	int32_t next_out;
	int32_t avail_out;
	int32_t total_out;
	int32_t msg;
	int32_t state;
	int32_t zalloc;
	int32_t zfree;
	int32_t opaque;
	int32_t data_type;
	int32_t adler;
	int32_t reserved;
};
struct file_in_zip_read_info_s
{
	void *read_buffer;
	z_stream_s stream;
	uint32_t pos_in_zipfile;
	int32_t stream_initialised;
	uint32_t offset_local_extrafield;
	uint32_t size_local_extrafield;
	uint32_t pos_local_extrafield;
	int32_t rest_read_compressed;
	int32_t rest_read_uncompressed;
	int32_t file;
	int32_t compression_method;
	int32_t byte_before_the_zipfile;
};

struct WSAData
{
	char wVersion[2];
	char wHighVersion[2];
	char szDescription[257];
	char szSystemStatus[129];
	int16_t iMaxSockets;
	int16_t iMaxUdpDg;
	char pad0[2];
	char lpVendorInfo[4];
};

struct lerpFrame_t
{
	float yawAngle;
	int32_t yawing;
	float pitchAngle;
	int32_t pitching;
	uint32_t animationNumber;
	int32_t animation;
	uint32_t animationTime;
	vec3_t oldFramePos;
	float animSpeedScale;
	uint32_t oldFrameSnapshotTime;
};

struct $_3672
{
	char infoValid[4];
	uint32_t nextValid;
	uint32_t clientNum;
	char name[32];
	int32_t team;
	int32_t oldteam;
	int32_t score;
	int32_t location;
	int32_t health;
	char model[64];
	char attachModelNames[384];
	char attachTagNames[384];
	lerpFrame_t legs;
	uint8_t torso[48];
	int32_t lerpMoveDir;
	int32_t lerpLean;
	vec3_t playerAngles;
	int32_t leftHandGun;
	int32_t dobjDirty;
	vec3_t angles[6];
	vec3_t tag_origin_angles;
	vec3_t tag_origin_offset;
	vec3_t clientConditions[6];
	int32_t pXAnimTree;
	uint32_t iDObjWeapon;
	uint32_t stanceTransitionTime;
	uint32_t turnAnimEndTime;
	int8_t turnAnimType;
};

struct scr_anim_s
{
	uint16_t index;
	int16_t tree;
};
struct $_3674
{
	int32_t tree;
	scr_anim_s root;
	int32_t torso;
	int32_t legs;
	int32_t turning;
};

struct scr_animtree_t
{
	int32_t anims;
};

struct animScriptData_t
{
	uint8_t animations[49152];
	uint32_t numAnimations;
	char scriptAnims[84624];
	char scriptCannedAnims[84624];
	char scriptStateChange[8256];
	char scriptEvents[9804];
	char scriptItems[499712];
	char numScriptItems[4];
	scr_animtree_t animTree;
	int16_t torsoAnim;
	int16_t legsAnim;
	int16_t turningAnim;
	char pad0[2];
	char soundAlias[4];
	char playSoundAlias[4];
};

struct $_3673
{
	animScriptData_t animScriptData;
	$_3674 generic_human;
	uint32_t time;
	uint32_t latestSnapshotTime;
	uint32_t frametime;
	int32_t anim_user;
	char GetXModel[4];
	int32_t CreateDObj;
	int32_t SafeDObjFree;
	int32_t AllocXAnim;
	char clientinfo[77312];
};

struct $_3671
{
	char va_string[2048];
	uint32_t index;
};

struct orientation_t
{
	vec3_t origin;
	vec3_t axis[3];
};

struct cspField_t
{
	char szName[4];
	uint32_t iOffset;
	int32_t iFieldType;
};

struct TraceCheckCount
{
	int32_t global;
	int32_t edges;
	int32_t verts;
	int32_t partitions;
};

struct TraceThreadInfo
{
	TraceCheckCount checkcount;
	int32_t box_brush;
	char box_model[4];
};

struct cplane_s
{
	vec3_t normal;
	int32_t dist;
	int8_t type;
	int8_t signbits;
	int16_t pad;
};

struct DObjAnimMat_s
{
	vec4_t quat;
	vec3_t trans;
	int32_t transWeight;
};

typedef enum
{
	PMSG_CONSOLE = 0,
	PMSG_GAME = 1,
	PMSG_BOLDGAME = 2,
	PMSG_SUBTITLE = 3,
	PMSG_LOGFILE = 4
} print_msg_type_t;

struct tm
{
	int32_t tm_sec;
	int32_t tm_min;
	int32_t tm_hour;
	int32_t tm_mday;
	int32_t tm_mon;
	int32_t tm_year;
	int32_t tm_wday;
	int32_t tm_yday;
	int32_t tm_isdst;
	int32_t tm_gmtoff;
	int32_t tm_zone;
};

typedef enum
{
	ERR_FATAL = 0,
	ERR_DROP = 1,
	ERR_SERVERDISCONNECT = 2,
	ERR_DISCONNECT = 3,
	ERR_SCRIPT = 4,
	ERR_SCRIPT_DROP = 5,
	ERR_LOCALIZATION = 6
} errorParm_t;

struct $_3728
{
	uint8_t pixels[24];
};

typedef enum
{
	SE_NONE = 0,
	SE_KEY = 1,
	SE_CHAR = 2,
	SE_GAMEPAD_AXIS = 3,
	SE_CONSOLE = 4,
	SE_PACKET = 5
} sysEventType_t;

union DvarValue
{
	int8_t enabled;
	int32_t integer;
	int32_t value;
	int32_t vector;
	char string[4];
	int32_t color;
};

struct $_3557
{
	char stringCount[4];
	char strings[4];
};

struct $_3560
{
	int32_t min;
	int32_t max;
};

struct $_3559
{
	int32_t min;
	int32_t max;
};

struct $_3558
{
	int32_t min;
	int32_t max;
};

union DvarLimits
{
	$_3557 enumeration;
	$_3558 integer;
	$_3559 value;
	$_3560 vector;
};

struct dvar_s
{
	char name[4];
	int16_t flags;
	int8_t type;
	int8_t modified;
	DvarValue current;
	int32_t latched;
	int32_t reset;
	DvarLimits domain;
	int32_t next;
	int32_t hashNext;
};

struct field_t
{
	int32_t cursor;
	int32_t scroll;
	uint32_t drawWidth;
	uint32_t widthInPixels;
	int32_t charHeight;
	uint32_t fixedSize;
	uint8_t buffer[256];
};

struct SysInfo
{
	uint64_t cpuGHz;
	int32_t sysMB;
	int8_t SSE;
	char gpuDescription[512];
};

struct $_3722
{
	int32_t use;
	uint32_t fadeTime;
	int32_t sensitivity;
	float maxPitchSpeed;
	float maxYawSpeed;
};

typedef enum
{
	NA_BOT = 0,
	NA_BAD = 1,
	NA_LOOPBACK = 2,
	NA_BROADCAST = 3,
	NA_IP = 4
} netadrtype_t;

struct LargeLocal
{
	uint32_t startPos;
};

typedef enum
{
	LOCMSG_SAFE = 0,
	LOCMSG_NOERR = 1
} msgLocErrType_t;

struct languageInfo_t
{
	char pszName[4];
	int32_t bPresent;
};

struct pack_t
{
	char iwdFilename[256];
	char iwdBasename[256];
	char iwdGamename[256];
	uint32_t handle;
	int32_t checksum;
	int32_t pure_checksum;
	uint32_t numfiles;
	int8_t referenced;
	char pad0[3];
	uint32_t hashSize;
	int32_t hashTable;
	void *buildBuffer;
};

struct fileInPack_s
{
	uint32_t pos;
	char name[4];
	int32_t next;
};

struct searchpath_s
{
	int32_t next;
	int32_t pack;
	int32_t dir;
	int32_t bLocalized;
	int32_t language;
};

struct directory_t
{
	char path[256];
	char gamedir[256];
};

typedef enum
{
	FS_LIST_PURE_ONLY = 0,
	FS_LIST_ALL = 1
} FsListBehavior_e;

struct $_3609
{
	int32_t file;
	uint64_t gi;
	int32_t byte_before_the_zipfile;
	uint32_t num_file;
	uint32_t pos_in_central_dir;
	int32_t current_file_ok;
	uint32_t central_pos;
	uint32_t size_central_dir;
	uint32_t offset_central_dir;
	char cur_file_info[80];
	unz_file_info_internal_s cur_file_info_internal;
	int32_t pfile_in_zip_read;
};

typedef enum
{
	FS_READ = 0,
	FS_WRITE = 1,
	FS_APPEND = 2,
	FS_APPEND_SYNC = 3
} fsMode_t;

union qfile_gus
{
	int32_t o;
	int32_t z;
};
struct qfile_us
{
	qfile_gus file;
	int32_t unique;
};
struct fileHandleData_t
{
	qfile_us handleFiles;
	uint32_t handleSync;
	uint32_t fileSize;
	uint32_t zipFilePos;
	int32_t zipFile;
	int32_t streamed;
	char name[256];
};

struct fileData_s
{
	int32_t data;
	int32_t next;
	int8_t type;
	int8_t name;
};

struct $_3622
{
	int32_t colorForDir;
	int32_t sunVisibility;
};

union $_3621
{
	$_3622 dx7;
	vec3_t baseCoords;
	vec3_t origin;
};

typedef enum
{
	PARSEMODE_DEFINES = 0,
	PARSEMODE_ANIMATION = 1,
	PARSEMODE_CANNED_ANIMATIONS = 2,
	PARSEMODE_STATECHANGES = 3,
	PARSEMODE_EVENTS = 4,
	NUM_PARSEMODES = 5
} $_3704;

struct $_3705
{
	char pszScript[64];
	char pszName[64];
	int32_t bTeamBased;
};

struct XAnimParts_s
{
	uint16_t numframes;
	int8_t bLoop;
	int8_t bDelta;
	int32_t framerate;
	int32_t frequency;
	uint8_t notifyCount;
	char pad0[1];
	uint16_t boneCount;
	char names[4];
	int32_t simpleQuatBits;
	int32_t parts;
	int32_t notify;
	int32_t deltaPart;
	char name[4];
	int8_t isDefault;
};

struct XAnimPart
{
	int32_t trans;
	int32_t quat;
};

struct XAnimNotifyInfo
{
	char name[2];
	char pad0[2];
	uint32_t time;
};

struct XAnimDeltaPart
{
	int32_t trans;
	int32_t quat;
};

union XAnimDynamicIndices
{
	int8_t _1;
	int16_t _2;
};

struct XAnimPartTransFrames
{
	int32_t frames;
	XAnimDynamicIndices indices;
};

union XAnimPartTransData
{
	XAnimPartTransFrames frames;
	vec3_t frame0;
};

struct XAnimPartTrans
{
	uint16_t size;
	char pad0[2];
	XAnimPartTransData u;
};

union XAnimPartQuatFrames
{
	int32_t frames;
	int32_t frames2;
};

struct XAnimPartQuatDataFrames
{
	XAnimPartQuatFrames u;
	int16_t indices;
};

union XAnimPartQuatData
{
	XAnimPartQuatDataFrames frames;
	uint64_t frame0;
	int32_t frame02;
};

struct XAnimPartQuat
{
	uint16_t size;
	char pad0[2];
	XAnimPartQuatData u;
};

struct XAnimDeltaPartTransFrames
{
	int32_t frames;
	int16_t indices;
};

union XAnimDeltaPartTransData
{
	XAnimDeltaPartTransFrames frames;
	vec3_t frame0;
};

struct XAnimDeltaPartTrans
{
	uint16_t size;
	char pad0[2];
	XAnimDeltaPartTransData u;
};

struct XAnimDeltaPartQuatDataFrames
{
	int32_t frames;
	int16_t indices;
};

union XAnimDeltaPartQuatData
{
	XAnimDeltaPartQuatDataFrames frames;
	int32_t frame0;
};

struct XAnimDeltaPartQuat
{
	uint16_t size;
	char pad0[2];
	XAnimDeltaPartQuatData u;
};

struct XAnim_s
{
	char debugName[4];
	uint32_t size;
	char debugAnimNames[4];
	uint64_t entries;
};

struct $_3693
{
	uint32_t dobjHandle;
	uint32_t boneIndex;
};

struct XAnimEntry
{
	uint16_t numAnims;
	int16_t parent;
	$_3693 u;
};

struct XAnimParent
{
	int16_t flags;
	int16_t children;
};

struct XAnimTree_s
{
	int32_t anims;
	uint16_t entnum;
	int8_t bAbs;
	int8_t bUseGoalWeight;
	char infoArray[2];
};

struct XAnimState
{
	uint32_t time;
	uint32_t oldTime;
	uint16_t timeCount;
	uint16_t oldTimeCount;
	uint32_t goalTime;
	int32_t goalWeight;
	int32_t weight;
	int32_t rate;
};

struct XAnimInfo
{
	int16_t notifyChild;
	uint16_t notifyIndex;
	char notifyName[2];
	int16_t notifyType;
	int16_t prev;
	int16_t next;
	XAnimState s;
};

struct XAnimNotify_s
{
	char name[4];
	int32_t type;
	float timeFrac;
};

struct XAnimTime
{
	uint32_t time;
	uint32_t frameCount;
	float frameFrac;
	uint32_t frameIndex;
};

struct XAnimSimpleRotPos
{
	uint64_t rot;
	uint32_t posWeight;
	vec3_t pos;
};

struct DObj_s
{
	int32_t tree;
	int32_t skel;
	uint32_t timeStamp;
	char animToModel[4];
	int16_t duplicateParts;
	char pad0[2];
	int32_t locked;
	uint8_t numModels;
	uint8_t numBones;
	int8_t ignoreCollision;
	char pad1[1];
	char models[32];
	char modelParents[8];
	vec2_t matOffset;
	vec3_t mins;
	vec3_t maxs;
};

struct DSkel
{
	uint8_t animPartBits[16];
	uint8_t controlPartBits[16];
	uint8_t skelPartBits[16];
	uint8_t mat[32];
};

struct XModel
{
	int32_t parts;
	char lodInfo[80];
	int32_t collSurfs;
	uint32_t numCollSurfs;
	int32_t contents;
	char boneInfo[4];
	vec3_t mins;
	vec3_t maxs;
	uint16_t numLods;
	int16_t collLod;
	int32_t xskins;
	int32_t memUsage;
	char name[4];
	int8_t flags;
	int8_t bad;
};

struct XModelLodInfo
{
	int32_t dist;
	char filename[4];
	uint16_t numsurfs;
	char pad0[2];
	char surfNames[4];
	int32_t surfs;
};

struct XBoneInfo_s
{
	vec3_t bounds[2];
	vec3_t offset;
	int32_t radiusSquared;
};

struct XModelParts_s
{
	uint16_t numBones;
	uint16_t numRootBones;
	int32_t hierarchy;
	int32_t quats;
	int32_t trans;
	int32_t partClassification;
	DSkel skel;
};

struct XModelCollSurf_s
{
	int32_t collTris;
	uint32_t numCollTris;
	vec3_t mins;
	vec3_t maxs;
	uint32_t boneIdx;
	int32_t contents;
	uint32_t surfFlags;
};

struct XBoneHierarchy
{
	char names[4];
	int8_t parentList;
};

struct XModelSurfs_s
{
	int32_t surfs;
	uint8_t partBits[16];
};

struct XModelCollTri_s
{
	vec4_t plane;
	uint8_t svec[16];
	uint8_t tvec[16];
};

struct XAnimCalcAnimInfo
{
	uint8_t rotTransArray[16384];
	uint8_t animPartBits[16];
	uint8_t ignorePartBits[16];
};

struct XAnimToXModel
{
	uint8_t partBits[16];
	uint8_t boneIndex[128];
};

struct HashEntry
{
	char status_next[2];
	$_3705 u;
};

struct $_3709
{
	float fLastWeaponPosFrac;
	uint32_t bPositionToADS;
	vec3_t vPositionLastOrg;
	float fLastIdleFactor;
	vec3_t vLastMoveOrg;
	vec3_t vLastMoveAng;
};

struct $_3710
{
	uint32_t vertexStride;
};

union $_3708
{
	$_3709 buf;
	$_3710 tess;
};

struct RefString
{
	$_3708 unnamed_field;
	int8_t str;
};

struct scrStringGlob_t
{
	uint8_t hashTable[65536];
	int8_t inited;
	char pad0[3];
	int32_t nextFreeEntry;
};

struct MemoryNode
{
	int16_t prev;
	int16_t next;
	int32_t padding;
};

struct $_3611
{
	uint8_t material[64];
	uint32_t surfaceFlags;
	uint32_t contentFlags;
};

struct $_3634
{
	uint8_t nodes[524288];
	uint8_t leftBits[256];
	uint8_t numBits[256];
	uint8_t logBits[256];
	uint8_t head[34];
	char pad0[2];
	int32_t totalAlloc;
	int32_t totalAllocBuckets;
};

struct trace_t
{
	float fraction;
	vec3_t normal;
	uint32_t surfaceFlags;
	int32_t contents;
	int32_t material;
	uint16_t entityNum;
	char partName[2];
	int16_t partGroup;
	int8_t allsolid;
	int8_t startsolid;
};

struct TraceExtents
{
	vec3_t start;
	vec3_t end;
	vec3_t invDelta;
};

struct $_3740
{
	char boneNames[2];
	char pad0[2];
	uint64_t hierarchy;
	char modelParts[100];
	char modelSurf[20];
	XBoneInfo_s boneInfo;
	int8_t partClassification;
	char pad1[1];
	char surfNames[2];
};

struct qtime_s
{
	int32_t tm_sec;
	int32_t tm_min;
	int32_t tm_hour;
	int32_t tm_mday;
	int32_t tm_mon;
	int32_t tm_year;
	int32_t tm_wday;
	int32_t tm_yday;
	int32_t tm_isdst;
};

struct Rb_tree_node_base
{
	int32_t _M_color;
	int32_t _M_parent;
	int32_t _M_left;
	int32_t _M_right;
};

typedef enum
{
	_S_red = 0,
	_S_black = 1
} Rb_tree_color;

struct gitem_s
{
	char classname[4];
	char pickup_sound[4];
	char world_model[8];
	int32_t icon;
	char pickup_name[4];
	int32_t quantity;
	int32_t giType;
	int32_t giTag;
	uint32_t giAmmoIndex;
	uint32_t giClipIndex;
};

typedef enum
{
	IT_BAD = 0,
	IT_WEAPON = 1,
	IT_AMMO = 2,
	IT_HEALTH = 3
} itemType_t;

struct snd_listener
{
	orientation_t orient;
	uint32_t entnum;
	int8_t active;
};

struct SndCurve
{
	char filename[4];
	uint32_t knotCount;
	uint8_t knots[64];
};

struct snd_alias_t
{
	char pszAliasName[4];
	int32_t pszSubtitle;
	char pszSecondaryAliasName[4];
	char soundFile[4];
	int32_t iSequence;
	int32_t fVolMin;
	int32_t fVolMax;
	int32_t fPitchMin;
	int32_t fPitchMax;
	int32_t fDistMin;
	int32_t fDistMax;
	uint32_t flags;
	int32_t fSlavePercentage;
	int32_t fProbability;
	int32_t fLfePercentage;
	int32_t startDelay;
	int32_t volumeFalloffCurve;
};

struct SoundFile
{
	char soundName[4];
	int32_t fileMem;
	int8_t isStreamFound;
	char pad0[3];
	int32_t type;
};

typedef enum
{
	SAT_UNKNOWN = 0,
	SAT_LOADED = 1,
	SAT_STREAMED = 2,
	SAT_PRIMED = 3,
	SAT_COUNT = 4
} snd_alias_type_t;

struct snd_channelvolgroup
{
	uint8_t channelvol[132];
	int8_t active;
};

struct snd_volume_info_t
{
	int32_t volume;
	int32_t goalvolume;
	int32_t goalrate;
};

struct snd_enveffect
{
	int32_t roomtype;
	int32_t drylevel;
	int32_t drygoal;
	int32_t dryrate;
	int32_t wetlevel;
	int32_t wetgoal;
	int32_t wetrate;
	int8_t active;
};

typedef enum
{
	SASYS_UI = 0,
	SASYS_CGAME = 1,
	SASYS_GAME = 2,
	SASYS_COUNT = 3
} snd_alias_system_t;

typedef enum
{
	SND_OVERLAY_NONE = 0,
	SND_OVERLAY_3D = 1,
	SND_OVERLAY_STREAM = 2,
	SND_OVERLAY_2D = 3
} snd_overlay_type_t;

struct snd_overlay_info_t
{
	char pszSampleName[4];
	int32_t fBaseVolume;
	int32_t fCurVolume;
	int32_t dist;
	int32_t fPitch;
};

struct MemoryFile
{
	void *buffer;
	uint32_t bufferSize;
	int32_t bytesUsed;
	int8_t errorOnOverflow;
	int8_t memoryOverflow;
	char pad0[2];
	int32_t archiveProc;
};

struct snd_channel_info_t
{
	uint32_t entnum;
	int32_t entchannel;
	int32_t startDelay;
	uint32_t looptime;
	uint32_t endtime;
	int32_t basevolume;
	int32_t baserate;
	int32_t pitch;
	uint32_t srcChannelCount;
	char pAlias0[4];
	char pAlias1[4];
	int32_t lerp;
	vec3_t org;
	vec3_t offset;
	int8_t paused;
	int8_t master;
	char pad0[2];
	int32_t system;
};

struct snd_alias_list_t
{
	char aliasName[4];
	int32_t head;
	uint32_t count;
	int32_t pHashNext;
};

typedef enum
{
	SND_STOP_ALL = 0,
	SND_KEEP_REVERB = 1,
	SND_KEEP_MUSIC = 2,
	SND_KEEP_AMBIENT = 4,
	SND_KEEP_MUSIC_AND_AMBIENT = 6,
	SND_STOP_STREAMED = 8,
	SND_KEEP_CHANNEL_VOLUMES = 16
} snd_stopsounds_arg_t;

struct $_3619
{
	int32_t connState;
	uint32_t connectPacketCount;
	uint32_t clientNum;
	char servername[1024];
	char messageString[1024];
};

struct $_3617
{
	float fraction;
	int32_t pitch;
	int32_t volume;
	int32_t pan;
};

struct $_3618
{
	uint32_t codePos;
	void *buf;
	void *sourceBuf;
	uint32_t len;
	uint32_t sortedIndex;
	int8_t archive;
};

struct $_3624
{
	void *buffer;
	uint32_t size;
};

struct $_3623
{
	int8_t Initialized2d;
	int8_t Initialized3d;
	int8_t paused;
	char pad0[1];
	int32_t playback_rate;
	int32_t playback_bits;
	int32_t playback_channels;
	uint32_t timescale;
	uint32_t pausetime;
	int32_t cpu;
	$_3624 restore;
	int32_t volume;
	vec3_t mastervol;
	uint8_t channelVolGroups[544];
	int32_t channelvol;
	uint8_t background[24];
	int32_t ambient_track;
	int32_t slaveLerp;
	vec3_t envEffects[8];
	int32_t effect;
	uint8_t defaultPauseSettings[11];
	uint8_t pauseSettings[11];
	char pad1[2];
	uint8_t listeners[56];
	uint32_t time;
	uint32_t looptime;
	char chaninfo[4240];
	int32_t max_2D_channels;
	int32_t max_3D_channels;
	int32_t max_stream_channels;
};

struct cmd_function_s
{
	int32_t next;
	char name[4];
	int32_t autoCompleteDir;
	int32_t autoCompleteExt;
	int32_t function;
};

struct cmd_t
{
	int32_t data;
	uint32_t maxsize;
	char cmdsize[4];
};

typedef enum
{
	DVAR_SOURCE_INTERNAL = 0,
	DVAR_SOURCE_EXTERNAL = 1,
	DVAR_SOURCE_SCRIPT = 2
} DvarSetSource;

struct AILSOUNDINFO
{
	int32_t format;
	void *data_ptr;
	uint32_t data_len;
	int32_t rate;
	int32_t bits;
	int32_t channels;
	int32_t samples;
	uint32_t block_size;
	void *initial_ptr;
};

struct MssSound
{
	AILSOUNDINFO info;
	int8_t data;
};

struct snd_save_2D_sample_t
{
	float fraction;
	int32_t pitch;
	int32_t volume;
	int32_t pan;
};

struct snd_save_3D_sample_t
{
	float fraction;
	int32_t pitch;
	int32_t volume;
	vec3_t org;
};

struct snd_save_stream_t
{
	float fraction;
	int32_t rate;
	int32_t basevolume;
	int32_t volume;
	int32_t pan;
	vec3_t org;
};

struct ADPCMDATATAG
{
	uint32_t blocksize;
	int32_t extrasamples;
	int32_t blockleft;
	int32_t step;
	int32_t savesrc;
	int32_t sample;
	int32_t destend;
	int32_t srcend;
	int32_t samplesL;
	int32_t samplesR;
	uint8_t moresamples[32];
};
struct AILMIXINFO
{
	char Info[36];
	ADPCMDATATAG mss_adpcm;
	float src_fract;
	int32_t left_val;
	int32_t right_val;
};

struct $_3748
{
	uint32_t handle;
	int32_t rate;
	uint32_t width;
	int32_t channels;
	void *buf;
	uint8_t bufReady[32];
	uint32_t bufSize;
	void *bufUsed;
	void *readBuf;
	void *writeBuf;
	uint64_t sampleTime;
	uint64_t bufRate;
};

struct MssLocal
{
	char driver_2D[4];
	uint32_t provider_3D;
	uint8_t handle_2D[32];
	uint8_t handle_3D[128];
	uint8_t handle_stream[52];
	$_3748 raw;
};

struct Effect
{
	void *_vptr$Effect;
	vec3_t mOrigin1;
	uint32_t mGroupFlags;
	vec3_t mMin;
	vec3_t mMax;
	int32_t mImpactFx;
	int32_t mDeathFx;
	int32_t mFx;
	uint32_t mPrimIndex;
	uint32_t mFrameNormTime;
	uint8_t mRefEnt[104];
	uint32_t mFlags;
	uint32_t mClusterId;
	int32_t mSortGroup;
	char mModel[4];
	uint32_t mTimeStart;
	uint32_t mTimeEnd;
	int32_t mBolt;
};

struct FxGfxEntity
{
	int32_t customMaterial;
	int32_t rotation;
	vec3_t axis[3];
	vec3_t dlightColor;
	uint32_t materialTime;
	vec3_t origin;
	uint64_t radius;
	int32_t materialRGBA;
	uint32_t materialSubimageIndex;
	int32_t scale;
	vec3_t endpos;
};

struct FxBoltFramePtr
{
	void *mFramePtr;
};

struct FxArchive
{
	int32_t mMemFile;
	int8_t mIsReading;
	int8_t mIsWriting;
	char pad0[2];
	int32_t mUncompressedBytes;
	uint32_t mNonZeroCount;
	uint32_t mZeroCount;
	uint32_t mRunIdPos;
};

struct EffectTemplate
{
	char mEffectName[4];
	uint32_t mPrimitiveCount;
	uint8_t mPrimitives[96];
};

struct FxBoltInfo
{
	uint32_t dobjHandle;
	uint32_t boneIndex;
};

struct FxBoltFrame
{
	uint32_t mRefCount;
	uint32_t mTimeStamp;
	orientation_t mOrient;
	int32_t mNextFrame;
	FxBoltInfo mBolt;
};

struct TMediaList
{
	int32_t elements;
	uint16_t size;
	uint16_t maxSize;
};

struct MediaHandles
{
	TMediaList mMediaList;
};

struct FxRange
{
	int32_t mMin;
	int32_t mMax;
};

struct PrimitiveTemplate
{
	char mName[32];
	uint8_t mMaterialImpact[32];
	int32_t mType;
	uint32_t mParentPrimIndex;
	FxRange mSpawnDelay;
	uint64_t mSpawnCount;
	uint64_t mLife;
	uint64_t mSpawnRange;
	MediaHandles mMediaHandles;
	uint64_t mImpactFxHandles;
	uint64_t mDeathFxHandles;
	uint64_t mEmitterFxHandles;
	uint64_t mPlayFxHandles;
	uint32_t mAttributeFlags;
	uint32_t mSpawnFlags;
	uint32_t mGroupFlags;
	int8_t mNonUniformScale;
	uint8_t useLength;
	char pad0[2];
	vec3_t mMin;
	vec3_t mMax;
	uint64_t mOrigin1X;
	uint64_t mOrigin1Y;
	uint64_t mOrigin1Z;
	uint64_t mOrigin2X;
	uint64_t mOrigin2Y;
	uint64_t mOrigin2Z;
	uint64_t mRadius;
	uint64_t mHeight;
	uint64_t mWindModifier;
	uint8_t mFxChannels[288];
	uint64_t mRotation;
	double mAngle1;
	double mAngle2;
	double mAngle3;
	double mAngle1Delta;
	double mAngle2Delta;
	double mAngle3Delta;
	uint64_t mGravity;
	uint64_t mDensity;
	uint64_t mVariance;
	vec2_t mTexCoordS;
	vec2_t mTexCoordT;
	uint64_t mElasticity;
	int32_t mSequenceStartFrameMode;
	int32_t mSequenceFixedFrameValue;
	int32_t mSequencePlayRateMode;
	int32_t mSequenceFixedFpsValue;
	int32_t mSequenceLoopMode;
	uint32_t mSequenceLoopTimes;
	int32_t spawnFrustumCullRadius;
};

typedef enum
{
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

typedef enum
{
	SFM_FIXED_FRAME = 0,
	SFM_RANDOM = 1,
	SFM_INDEXED = 2,
	SFM_MODE_COUNT = 3
} StartFrameMode;

typedef enum
{
	PRM_FIXED_FPS = 0,
	PRM_SYNC_TO_PARTICLE_LIFETIME = 1,
	PRM_MODE_COUNT = 2
} PlayRateMode;

typedef enum
{
	LM_FOREVER = 0,
	LM_TIMES = 1,
	LM_MODE_COUNT = 2
} LoopMode;

typedef enum
{
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

struct FxCurveIterator
{
	int32_t master;
	uint32_t currentKeyIndex;
};

struct FxChannelInstance
{
	FxCurveIterator curveIterator;
	int32_t scale;
};

union EffectTemplateLoadPtr
{
	int32_t fx;
	char name[4];
};

union TMediaElement
{
	char model[4];
	int32_t material;
	EffectTemplateLoadPtr u;
	int32_t data;
};

struct FxChannel
{
	int32_t curve;
	uint64_t scaleRange;
};

struct BackCompatibleParameters
{
	uint8_t fxChannels[1536];
};

struct GPGroup
{
	char pad0[16];
	int32_t mPairs;
	int32_t mInOrderPairs;
	int32_t mCurrentPair;
	int32_t mSubGroups;
	int32_t mInOrderSubGroups;
	int32_t mCurrentSubGroup;
	int32_t mParent;
	int8_t mWriteable;
};

struct GPValue
{
	char pad0[16];
	int32_t mList;
};

struct FxFlagEntry
{
	int32_t flag;
	uint64_t masks;
};

struct GPObject
{
	char mName[4];
	int32_t mNext;
	int32_t mInOrderNext;
	int32_t mInOrderPrevious;
};

struct FxChannelBackwardCompatible
{
	vec3_t start[2];
	vec3_t end[2];
	uint64_t parm;
	uint32_t flags;
	int8_t containsData;
};

struct FxCurve
{
	uint32_t dimensionCount;
	uint32_t keyCount;
	int32_t keys;
};

struct TextPool
{
	int32_t mPool;
	int32_t mNext;
	uint32_t mSize;
	int32_t mUsed;
};

struct $_3580
{
	float fraction;
	vec3_t normal;
	uint32_t surfaceFlags;
	int32_t contents;
	int32_t material;
	uint16_t entityNum;
	char partName[2];
	int16_t partGroup;
	int8_t allsolid;
	int8_t startsolid;
};

struct ScheduledEffect
{
	int32_t mFx;
	uint32_t mPrimIndex;
	uint32_t mStartTime;
	FxBoltInfo mBolt;
	vec3_t mOrigin;
	vec3_t mAxis[3];
	int32_t mSeed;
	uint32_t mIndexInBatch;
	int32_t mScheduledNext;
};

struct EffectVisInfo
{
	vec3_t origin;
	int32_t distSq;
	int32_t vis;
};

struct EffectPrimitive
{
	int32_t fx;
	int32_t primTemp;
	int32_t boltFrame;
};

struct Particle
{
	char pad0[196];
	vec3_t mImpactVector;
	vec3_t mAxis[3];
	int32_t mGravity;
	int32_t mWindWeight;
	int32_t mCurrentRotation;
	int32_t mElasticity;
	int8_t mNonUniformScale;
	char pad1[3];
	int32_t mStartFrame;
	int32_t mPlayRate;
	int32_t mLoopMode;
	uint32_t mLoopTimes;
	int32_t mRandomColorsWeight;
	int32_t mRandomAlphaWeight;
	uint32_t mRandomSizeWeight;
	uint32_t mRandomSize2Weight;
	int32_t mRandomRotationDeltaWeight;
	vec3_t mRandomVelocityWeights;
	vec3_t mRandomVelocity2Weights;
	vec3_t colorChannelInstance;
	vec3_t colorRandChannelInstance;
	vec3_t alphaChannelInstance;
	vec3_t alphaRandChannelInstance;
	vec3_t sizeChannelInstance;
	vec3_t sizeRandChannelInstance;
	vec3_t size2ChannelInstance;
	vec3_t size2RandChannelInstance;
	vec3_t rotationDeltaChannelInstance;
	vec3_t rotationDeltaRandChannelInstance;
	vec3_t velocityXChannelInstance;
	vec3_t velocityYChannelInstance;
	vec3_t velocityZChannelInstance;
	vec3_t velocityXRandChannelInstance;
	vec3_t velocityYRandChannelInstance;
	vec3_t velocityZRandChannelInstance;
	vec3_t velocity2XChannelInstance;
	vec3_t velocity2YChannelInstance;
	vec3_t velocity2ZChannelInstance;
	vec3_t velocity2XRandChannelInstance;
	vec3_t velocity2YRandChannelInstance;
	vec3_t velocity2ZRandChannelInstance;
};

struct SortedCluster
{
	uint32_t clusterId;
	int32_t distSq;
};

struct Cloud
{
	char pad0[588];
	vec3_t tumbleAxis;
	uint32_t length;
	uint8_t useLength;
	char pad1[3];
	uint32_t randomLengthWeight;
	vec3_t lengthChannelInstance;
	vec3_t lengthRandChannelInstance;
};

struct Flash
{
};

struct Light
{
	char pad0[196];
	int32_t mRandomColorsWeight;
	uint32_t mRandomSizeWeight;
	vec3_t colorChannelInstance;
	vec3_t colorRandChannelInstance;
	vec3_t sizeChannelInstance;
	vec3_t sizeRandChannelInstance;
};

struct Cylinder
{
};

struct Tail
{
	char pad0[588];
	vec3_t mOldOrigin;
	uint32_t length;
	uint32_t randomLengthWeight;
	vec3_t lengthChannelInstance;
	vec3_t lengthRandChannelInstance;
};

struct Line
{
	char pad0[588];
	vec3_t mOrigin2;
};

struct Emitter
{
	char pad0[588];
	vec3_t mOldOrigin;
	vec3_t mOldVelocity;
	vec3_t mOldBindOrg;
	uint32_t mOldTime;
	int32_t mStep;
	vec3_t mAngles;
	vec3_t mAngleDelta;
	int32_t mEmitterFx;
	int32_t mDensity;
	int32_t mVariance;
};

struct OrientedParticle
{
	char pad0[588];
	vec3_t mNormal;
};

struct FxCamera
{
	vec3_t vieworg;
	vec3_t frustum[8];
	uint32_t numPlanes;
};

struct FxHelper
{
	uint32_t time;
	uint32_t mTime;
	uint32_t mOldTime;
	uint32_t mFrameTime;
	uint32_t mTimeFrozen;
	FxCamera mCamera;
	uint8_t mPrevCamera[112];
	int32_t mSeed;
	float adsZoomFactor;
};

struct GfxEntity
{
	int32_t reType;
	uint32_t renderFxFlags;
	$_3621 lighting;
	vec3_t axis[3];
	int32_t scale;
	vec3_t origin;
	vec3_t endpos;
	int32_t customMaterial;
	int32_t materialRGBA;
	uint32_t materialTime;
	uint32_t materialSubimageIndex;
	uint64_t radius;
	int32_t rotation;
	int32_t minScreenRadius;
};

struct refdef_s
{
	int32_t x;
	int32_t y;
	uint32_t width;
	int32_t height;
	int32_t fov_x;
	int32_t fov_y;
	vec3_t vieworg;
	vec3_t viewaxis[3];
	uint32_t time;
	int32_t zNear;
	int32_t blurRadius;
	uint32_t viewIndex;
};

typedef enum
{
	RT_DOBJ = 0,
	RT_XMODEL = 1,
	RT_STATICMODEL = 2,
	RT_BRUSHMODEL = 3,
	RT_SPRITE = 4,
	RT_RAIL_CORE = 5,
	RT_PARTICLE_CLOUD = 6,
	RT_ORIENTED_QUAD = 7,
	RT_LINE = 8,
	RT_CYLINDER = 9,
	RT_MAX_REF_ENTITY_TYPE = 10
} refEntityType_t;

struct $_3666
{
	uint8_t extents[36];
	uint32_t passEntityNum;
	uint32_t passOwnerNum;
	uint32_t contentmask;
	int32_t bLocational;
	int32_t priorityMap;
};

union GfxColor
{
	int32_t packed;
	int32_t array;
};

struct GfxWorldVertex
{
	vec3_t xyz;
	vec3_t normal;
	GfxColor color;
	vec2_t texCoord;
	vec2_t lmapCoord;
	vec3_t binormal;
	vec3_t tangent;
};

struct $_3667
{
	vec3_t start;
	vec3_t end;
	uint64_t passEntityNum;
	uint32_t contentmask;
	int32_t locational;
};

struct EffectCluster
{
	vec3_t origin;
	uint32_t refCount;
};

struct SortedEffect
{
	int32_t effect;
	int32_t distSq;
};

struct GenericParser2
{
	uint8_t mTopLevel[48];
	char mTextPool[4];
	int8_t mWriteable;
};

struct FxScheduler
{
	int32_t mSeed;
	int32_t mScheduledHead;
	uint32_t mScheduledCount;
};

typedef enum
{
	MEDIA_MATERIALS = 0,
	MEDIA_MODELS = 1,
	MEDIA_EFFECTS = 2
} EMediaTypes;

struct cLeaf_t
{
	uint16_t firstCollAabbIndex;
	uint16_t collAabbCount;
	int32_t brushContents;
	int32_t terrainContents;
	vec3_t mins;
	vec3_t maxs;
	int32_t leafBrushNode;
	int16_t cluster;
};

struct cmodel_t
{
	vec3_t mins;
	vec3_t maxs;
	int32_t radius;
	cLeaf_t leaf;
};

struct traceWork_t
{
	TraceExtents extents;
	vec3_t delta;
	uint32_t deltaLen;
	uint32_t deltaLenSq;
	vec3_t midpoint;
	vec3_t halfDelta;
	vec3_t halfDeltaAbs;
	vec3_t size;
	vec3_t bounds[2];
	int32_t contents;
	int32_t isPoint;
	int32_t axialCullOnly;
	int32_t radius;
	uint32_t offsetZ;
	vec3_t radiusOffset;
	TraceThreadInfo threadInfo;
};

struct cLeafBrushNodeChildren_t
{
	int32_t dist;
	int32_t range;
	uint32_t childOffset;
};

struct cLeafBrushNodeLeaf_t
{
	int32_t brushes;
};

union cLeafBrushNodeData_t
{
	cLeafBrushNodeLeaf_t leaf;
	cLeafBrushNodeChildren_t children;
};

struct cLeafBrushNode_s
{
	int8_t axis;
	char pad0[1];
	uint16_t leafBrushCount;
	int32_t contents;
	cLeafBrushNodeData_t data;
};

struct cbrush_t
{
	vec3_t mins;
	int32_t contents;
	vec3_t maxs;
	uint32_t numsides;
	uint32_t sides;
	vec3_t axialMaterialNum;
};

struct cbrushside_t
{
	int32_t plane;
	uint32_t materialNum;
};

struct $_3681
{
	int32_t plane;
	int32_t children;
};

struct leafList_s
{
	uint32_t count;
	uint32_t maxcount;
	int32_t overflowed;
	int32_t list;
	vec3_t bounds[2];
	int32_t lastLeaf;
};

struct CollisionTriangle
{
	vec4_t plane;
	uint8_t svec[16];
	uint8_t tvec[16];
	vec3_t verts;
	vec3_t edges;
};

struct $_3684
{
	vec3_t origin;
	vec3_t axis[3];
};

union CollisionAabbTreeIndex
{
	uint32_t firstChildIndex;
	uint32_t partitionIndex;
};

struct CollisionAabbTree
{
	vec3_t origin;
	vec3_t halfSize;
	uint16_t materialIndex;
	uint16_t childCount;
	CollisionAabbTreeIndex u;
};

struct $_3687
{
	uint8_t triCount;
	uint8_t borderCount;
	char pad0[2];
	int32_t tris;
	int32_t borders;
};

struct CollisionBorder
{
	vec3_t distEq;
	int32_t zBase;
	int32_t zSlope;
	int32_t start;
	uint32_t length;
};

struct $_3682
{
	uint8_t eval_stack[16];
	char dialog_error_message[4];
	int32_t loading;
	uint32_t starttime;
	uint8_t localVarsStack[8192];
};

struct $_3593
{
	uint8_t current[3968];
	uint8_t archival[3968];
};

struct MantleState
{
	int32_t yaw;
	uint32_t timer;
	uint32_t transIndex;
	uint32_t flags;
};

struct playerState_s
{
	char commandTime[4];
	int32_t pm_type;
	int32_t bobCycle;
	uint32_t pm_flags;
	uint32_t pm_time;
	vec3_t origin;
	vec3_t velocity;
	uint64_t oldVelocity;
	uint32_t weaponTime;
	int32_t weaponDelay;
	uint32_t grenadeTimeLeft;
	uint32_t weaponRestrictKickTime;
	char foliageSoundTime[4];
	int32_t gravity;
	int32_t leanf;
	float speed;
	vec3_t delta_angles;
	uint32_t groundEntityNum;
	vec3_t vLadderVec;
	uint32_t jumpTime;
	int32_t jumpOriginZ;
	uint32_t legsTimer;
	int32_t legsAnim;
	uint32_t torsoTimer;
	int32_t torsoAnim;
	int32_t legsAnimDuration;
	int32_t torsoAnimDuration;
	uint32_t damageTimer;
	int32_t damageDuration;
	int32_t flinchYaw;
	int32_t movementDir;
	uint32_t eFlags;
	int32_t eventSequence;
	uint8_t events[16];
	uint8_t eventParms[16];
	int32_t oldEventSequence;
	uint32_t clientNum;
	uint32_t offHandIndex;
	int32_t weapon;
	int32_t weaponstate;
	float fWeaponPosFrac;
	uint32_t adsDelayTime;
	char viewmodelIndex[4];
	vec3_t viewangles;
	int32_t viewHeightTarget;
	int32_t viewHeightCurrent;
	uint32_t viewHeightLerpTime;
	int32_t viewHeightLerpTarget;
	int32_t viewHeightLerpDown;
	uint32_t viewHeightLerpPosAdj;
	double viewAngleClampBase;
	double viewAngleClampRange;
	int32_t damageEvent;
	int32_t damageYaw;
	int32_t damagePitch;
	uint32_t damageCount;
	uint8_t stats[24];
	uint8_t ammo[512];
	uint8_t ammoclip[512];
	uint8_t weapons[16];
	uint64_t weaponslots;
	uint8_t weaponrechamber[16];
	vec3_t mins;
	vec3_t maxs;
	int32_t proneDirection;
	int32_t proneDirectionPitch;
	int32_t proneTorsoPitch;
	int32_t viewlocked;
	uint32_t viewlocked_entNum;
	int32_t cursorHint;
	char cursorHintString[4];
	uint32_t cursorHintEntIndex;
	char iCompassFriendInfo[4];
	int32_t fTorsoHeight;
	int32_t fTorsoPitch;
	int32_t fWaistPitch;
	int32_t holdBreathScale;
	uint32_t holdBreathTimer;
	MantleState mantleState;
	int32_t entityEventSequence;
	int32_t weapAnim;
	int32_t aimSpreadScale;
	uint32_t shellshockIndex;
	uint32_t shellshockTime;
	int32_t shellshockDuration;
	uint8_t objective[448];
	uint32_t deltaTime;
	$_3593 hud;
};

struct objective_t
{
	int32_t state;
	vec3_t origin;
	uint32_t entNum;
	uint32_t teamNum;
	int32_t icon;
};

typedef enum
{
	OBJST_EMPTY = 0,
	OBJST_ACTIVE = 1,
	OBJST_INVISIBLE = 2,
	OBJST_DONE = 3,
	OBJST_CURRENT = 4,
	OBJST_FAILED = 5,
	OBJST_NUMSTATES = 6
} objectiveState_t;

struct $_3592
{
	int8_t r;
	int8_t g;
	int8_t b;
	int8_t a;
};

union hudelem_color_t
{
	$_3592 unnamed_field;
	int32_t rgba;
};

struct hudelem_s
{
	int32_t type;
	int32_t x;
	int32_t y;
	int32_t z;
	int32_t fontScale;
	int32_t font;
	int32_t alignOrg;
	int32_t alignScreen;
	hudelem_color_t color;
	int32_t fromColor;
	uint32_t fadeStartTime;
	uint32_t fadeTime;
	int32_t label;
	uint32_t width;
	int32_t height;
	uint32_t materialIndex;
	uint32_t fromWidth;
	int32_t fromHeight;
	uint32_t scaleStartTime;
	uint32_t scaleTime;
	int32_t fromX;
	int32_t fromY;
	int32_t fromAlignOrg;
	int32_t fromAlignScreen;
	uint32_t moveStartTime;
	uint32_t moveTime;
	uint32_t time;
	int32_t duration;
	int32_t value;
	char text[4];
	int32_t sort;
	int32_t foreground;
};

typedef enum
{
	HE_TYPE_FREE = 0,
	HE_TYPE_TEXT = 1,
	HE_TYPE_VALUE = 2,
	HE_TYPE_PLAYERNAME = 3,
	HE_TYPE_MAPNAME = 4,
	HE_TYPE_GAMETYPE = 5,
	HE_TYPE_MATERIAL = 6,
	HE_TYPE_TIMER_DOWN = 7,
	HE_TYPE_TIMER_UP = 8,
	HE_TYPE_TENTHS_TIMER_DOWN = 9,
	HE_TYPE_TENTHS_TIMER_UP = 10,
	HE_TYPE_CLOCK_DOWN = 11,
	HE_TYPE_CLOCK_UP = 12,
	HE_TYPE_WAYPOINT = 13,
	HE_TYPE_COUNT = 14
} he_type_t;

struct trajectory_t
{
	int32_t trType;
	uint32_t trTime;
	int32_t trDuration;
	vec3_t trBase;
	vec3_t trDelta;
};

union $_3597
{
	int32_t scale;
	int32_t eventParm2;
};

union $_3596
{
	char brushmodel[4];
	int32_t item;
	char xmodel[4];
};

struct entityState_s
{
	uint32_t number;
	int32_t eType;
	uint32_t eFlags;
	trajectory_t pos;
	uint8_t apos[36];
	uint32_t time;
	uint32_t time2;
	vec3_t origin2;
	vec3_t angles2;
	uint32_t otherEntityNum;
	uint32_t attackerEntityNum;
	uint32_t groundEntityNum;
	int32_t constantLight;
	char loopSound[4];
	int32_t surfType;
	$_3596 index;
	uint32_t clientNum;
	int32_t iHeadIcon;
	int32_t iHeadIconTeam;
	uint32_t solid;
	int32_t eventParm;
	int32_t eventSequence;
	uint8_t events[16];
	uint8_t eventParms[16];
	int32_t weapon;
	int32_t legsAnim;
	int32_t torsoAnim;
	int32_t leanf;
	$_3597 unnamed_field;
	uint32_t dmgFlags;
	int32_t animMovetype;
	int32_t fTorsoHeight;
	int32_t fTorsoPitch;
	int32_t fWaistPitch;
};

struct entityShared_t
{
	int8_t linked;
	int8_t bmodel;
	int8_t svFlags;
	char pad0[1];
	uint64_t clientMask;
	int8_t inuse;
	char pad1[3];
	uint32_t broadcastTime;
	vec3_t mins;
	vec3_t maxs;
	int32_t contents;
	vec3_t absmin;
	vec3_t absmax;
	vec3_t currentOrigin;
	vec3_t currentAngles;
	uint32_t ownerNum;
	uint32_t eventTime;
};
struct item_ent_t
{
	uint32_t count2;
	uint16_t index;
};
struct corpse_ent_t
{
	uint32_t deathAnimStartTime;
};

struct trigger_ent_t
{
	int32_t threshold;
	int32_t accumulate;
	uint32_t timestamp;
	uint32_t singleUserEntIndex;
};

struct grenade_ent_t
{
	uint32_t time;
};

struct mover_ent_t
{
	uint32_t decelTime;
	uint32_t aDecelTime;
	float speed;
	float aSpeed;
	uint32_t midTime;
	uint32_t aMidTime;
	vec3_t pos1;
	vec3_t pos2;
	vec3_t pos3;
	vec3_t apos1;
	vec3_t apos2;
	vec3_t apos3;
};
union $_3701
{
	item_ent_t item;
	trigger_ent_t trigger;
	mover_ent_t mover;
	corpse_ent_t corpse;
	grenade_ent_t grenade;
};
struct gentity_s
{
	entityState_s s;
	entityShared_t r;
	int32_t client;
	char pTurretInfo[4];
	int8_t physicsObject;
	int8_t takedamage;
	int8_t active;
	int8_t nopickup;
	int8_t model;
	int8_t attachIgnoreCollision;
	int8_t handler;
	int8_t team;
	char classname[2];
	int16_t target;
	char targetname[2];
	char pad0[2];
	uint32_t spawnflags;
	uint32_t flags;
	uint32_t eventTime;
	int32_t freeAfterEvent;
	int32_t unlinkAfterEvent;
	uint32_t clipmask;
	int32_t processedFrame;
	int32_t parent;
	int32_t nextthink;
	int32_t health;
	int32_t maxHealth;
	int32_t damage;
	uint32_t count;
	int32_t chain;
	$_3701 unnamed_field;
	char tagInfo[4];
	int32_t tagChildren;
	char attachModelNames[7];
	char pad1[1];
	char attachTagNames[14];
	char pad2[2];
	uint32_t useCount;
	int32_t nextFree;
};

typedef enum
{
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

typedef enum
{
	PCT_CLIENT = 0,
	PCT_ACTOR = 1
} proneCheckType_t;

struct pmove_t
{
	int32_t ps;
	char cmd[28];
	char oldcmd[28];
	uint32_t tracemask;
	uint32_t numtouch;
	uint8_t touchents[128];
	vec3_t mins;
	vec3_t maxs;
	float xyspeed;
	int32_t proneChange;
	int8_t handler;
	int8_t mantleStarted;
	char pad0[2];
	vec3_t mantleEndPos;
	int32_t mantleDuration;
};

struct usercmd_s
{
	uint32_t serverTime;
	int32_t buttons;
	int8_t weapon;
	uint8_t offHandIndex;
	char pad0[2];
	vec3_t angles;
	int8_t forwardmove;
	int8_t rightmove;
};

struct pml_t
{
	vec3_t forward;
	vec3_t right;
	vec3_t up;
	uint32_t frametime;
	int32_t msec;
	int32_t walking;
	int32_t groundPlane;
	int32_t almostGroundPlane;
	trace_t groundTrace;
	float impactSpeed;
	vec3_t previous_origin;
	vec3_t previous_velocity;
	int32_t previous_waterlevel;
};

struct viewLerpWaypoint_s
{
	float iFrac;
	int32_t fViewHeight;
	uint32_t iOffset;
};

typedef enum
{
	TEAM_FREE = 0,
	TEAM_AXIS = 1,
	TEAM_ALLIES = 2,
	TEAM_SPECTATOR = 3,
	TEAM_NUM_TEAMS = 4
} team_t;

struct animation_s
{
	char name[64];
	int32_t initialLerp;
	float moveSpeed;
	int32_t duration;
	char nameHash[4];
	uint32_t flags;
	uint64_t movetype;
	int32_t noteType;
};

struct pmoveHandler_t
{
	int32_t trace;
	int32_t pointcontents;
	int32_t playerEvent;
};

struct DObjModel_s
{
	char model[4];
	char boneName[4];
	int32_t ignoreCollision;
};

struct dheader_s
{
	uint32_t ident;
	char version[4];
	uint8_t lumps[312];
};

struct lump_t
{
	uint32_t filelen;
	int32_t fileofs;
};

struct clipMap_t
{
	char name[4];
	char numStaticModels[4];
	char staticModelList[4];
	uint32_t numMaterials;
	int32_t materials;
	uint32_t numBrushSides;
	uint32_t brushsides;
	uint32_t numNodes;
	int32_t nodes;
	uint32_t numLeafs;
	int32_t leafs;
	uint32_t leafbrushNodesCount;
	int32_t leafbrushNodes;
	uint32_t numLeafBrushes;
	int32_t leafbrushes;
	uint32_t numLeafSurfaces;
	int32_t leafsurfaces;
	uint32_t vertCount;
	int32_t verts;
	uint32_t edgeCount;
	int32_t edges;
	uint32_t triCount;
	int32_t tris;
	uint32_t borderCount;
	int32_t borders;
	uint32_t partitionCount;
	int32_t partitions;
	uint32_t aabbTreeCount;
	int32_t aabbTrees;
	char numSubModels[4];
	char cmodels[4];
	uint16_t numBrushes;
	char pad0[2];
	int32_t brushes;
	uint32_t numClusters;
	int32_t clusterBytes;
	int32_t visibility;
	int32_t vised;
	uint32_t numEntityChars;
	char entityString[4];
	int32_t box_brush;
	char box_model[72];
	char pathNodeCount[4];
	char pathNodes[4];
	uint32_t chainNodeCount;
	int32_t chainNodes;
	int32_t chainNodesRev;
	int32_t visBytes;
	char pathVis[4];
	uint32_t nodeTreeCount;
	int32_t nodeTree;
	int32_t checksum;
};

struct dmaterial_t
{
	uint8_t material[64];
	uint32_t surfaceFlags;
	uint32_t contentFlags;
};

struct cNode_t
{
	int32_t plane;
	int32_t children;
};

struct CollisionVertex
{
	vec3_t xyz;
};

struct CollisionEdge
{
	vec3_t origin;
	vec3_t axis[3];
};

struct CollisionPartition
{
	uint8_t triCount;
	uint8_t borderCount;
	char pad0[2];
	int32_t tris;
	int32_t borders;
};

struct cStaticModelWritable
{
	char nextModelInWorldSector[2];
};

struct cStaticModel_s
{
	cStaticModelWritable writable;
	char pad0[2];
	char xmodel[4];
	vec3_t origin;
	vec3_t invAxis[3];
	vec3_t absmin;
	vec3_t absmax;
};

struct DObjTrace_s
{
	float fraction;
	uint32_t surfaceflags;
	vec3_t normal;
	char partName[2];
	int16_t partGroup;
};

struct DSurface_s
{
	char modelIndex[2];
	uint16_t subMatIndex;
};

typedef enum
{
	LANGUAGE_ENGLISH = 0,
	LANGUAGE_FRENCH = 1,
	LANGUAGE_GERMAN = 2,
	LANGUAGE_ITALIAN = 3,
	LANGUAGE_SPANISH = 4,
	LANGUAGE_BRITISH = 5,
	LANGUAGE_RUSSIAN = 6,
	LANGUAGE_POLISH = 7,
	LANGUAGE_KOREAN = 8,
	LANGUAGE_TAIWANESE = 9,
	LANGUAGE_JAPANESE = 10,
	LANGUAGE_CHINESE = 11,
	LANGUAGE_THAI = 12,
	LANGUAGE_LEET = 13,
	MAX_LANGUAGES = 14
} language_t;

struct $_3799
{
	int32_t language;
	char strings[4];
};

struct $_3612
{
	vec3_t normal;
	int32_t dist;
};

union sval_u
{
	int32_t type;
	char stringValue[4];
	uint32_t idValue;
	float floatValue;
	int32_t intValue;
	int32_t node;
	uint32_t sourcePosValue;
	uint32_t codePosValue;
	char debugString[4];
	int32_t block;
};
struct $_3616
{
	sval_u val;
	uint32_t pos;
};

union $_3615
{
	uint32_t planeNum;
	int32_t bound;
};

struct $_3614
{
	$_3615 u;
	uint32_t materialNum;
};

struct $_3689
{
	vec3_t origin;
	vec3_t halfSize;
	uint16_t materialIndex;
	uint16_t childCount;
	CollisionAabbTreeIndex u;
};

union $_3652
{
	int16_t prev;
	int16_t prevSibling;
};

struct $_3651
{
	vec3_t origin;
	vec3_t halfSize;
	uint16_t materialIndex;
	uint16_t childCount;
	$_3652 u;
};

struct $_3629
{
	int32_t cluster;
	int32_t area;
	uint32_t firstCollAabbIndex;
	uint32_t collAabbCount;
	int32_t firstLeafBrush;
	uint32_t numLeafBrushes;
	uint32_t cellNum;
	uint32_t firstLightIndex;
	uint32_t numLights;
};

struct $_3610
{
	uint8_t token[1024];
	int32_t lines;
	int8_t ungetToken;
	int8_t spaceDelimited;
	int8_t keepStringQuotes;
	int8_t csv;
	uint8_t negativeNumbers;
	char pad0[3];
	void *errorPrefix;
	void *warningPrefix;
	int32_t backup_lines;
	char backup_text[4];
	uint8_t parseFile[64];
};

struct $_3613
{
	uint32_t planeNum;
	uint64_t children;
	vec3_t mins;
	vec3_t maxs;
};

struct loadAssets_t
{
	char menuEnterSound[4];
	char menuExitSound[4];
	char menuBuzzSound[4];
	int32_t fadeClamp;
	int32_t fadeCycle;
	int32_t fadeAmount;
	int32_t fadeInAmount;
	int32_t shadowX;
	int32_t shadowY;
	vec4_t shadowColor;
	int32_t shadowFadeClamp;
};

struct $_3683
{
	loadAssets_t loadAssets;
	uint64_t menuList;
	uint8_t items[1024];
	uint8_t menus[512];
};

struct $_3646
{
	int32_t checkStamp;
	vec3_t xyz;
};

struct $_3647
{
	int32_t checkStamp;
	vec3_t origin;
	vec3_t axis[3];
	uint32_t length;
};

struct $_3648
{
	vec4_t plane;
	uint8_t svec[16];
	uint8_t tvec[16];
	vec3_t vertIndices;
	vec3_t edgeIndices;
};

struct $_3686
{
	vec3_t distEq;
	int32_t zBase;
	int32_t zSlope;
	int32_t start;
	uint32_t length;
};

struct $_3649
{
	vec3_t distEq;
	int32_t zBase;
	int32_t zSlope;
	int32_t start;
	uint32_t length;
};

struct $_3650
{
	int16_t checkStamp;
	uint8_t triCount;
	uint8_t borderCount;
	uint32_t firstTriIndex;
	uint32_t firstBorderIndex;
};

struct $_3699
{
	vec3_t xyz;
	vec4_t color;
	int32_t scale;
	char text[96];
};

struct WeaponDef
{
	char szInternalName[4];
	char szDisplayName[4];
	char szOverlayName[4];
	char szGunXModel[4];
	char szHandXModel[4];
	uint8_t szXAnims[92];
	char szModeName[4];
	int32_t playerAnimType;
	int32_t weapType;
	int32_t weapClass;
	int32_t weapSlot;
	int32_t offhandClass;
	int32_t bSlotStackable;
	int32_t stance;
	int32_t szViewFlashEffect;
	int32_t szWorldFlashEffect;
	char szPickupSound[4];
	char szAmmoPickupSound[4];
	char szProjectileSound[4];
	char szPullbackSound[4];
	char szFireSound[4];
	char szFireSoundPlayer[4];
	char szFireLoopSound[4];
	char szFireLoopSoundPlayer[4];
	char szFireStopSound[4];
	char szFireStopSoundPlayer[4];
	char szFireLastSound[4];
	char szFireLastSoundPlayer[4];
	char meleeSwipeSound[4];
	char szRechamberSound[4];
	char szRechamberSoundPlayer[4];
	char szReloadSound[4];
	char szReloadSoundPlayer[4];
	char szReloadEmptySound[4];
	char szReloadEmptySoundPlayer[4];
	char szReloadStartSound[4];
	char szReloadStartSoundPlayer[4];
	char szReloadEndSound[4];
	char szReloadEndSoundPlayer[4];
	char szRaiseSound[4];
	char szAltSwitchSound[4];
	char szPutawaySound[4];
	char szNoteTrackSoundA[4];
	char szNoteTrackSoundB[4];
	char szNoteTrackSoundC[4];
	char szNoteTrackSoundD[4];
	int32_t szShellEjectEffect;
	int32_t szLastShotEjectEffect;
	int32_t szReticleCenter;
	uint32_t szReticleSide;
	uint32_t iReticleCenterSize;
	uint32_t iReticleSideSize;
	int32_t iReticleMinOfs;
	vec3_t vStandMove;
	vec3_t vStandRot;
	vec3_t vDuckedOfs;
	vec3_t vDuckedMove;
	vec3_t vDuckedRot;
	vec3_t vProneOfs;
	vec3_t vProneMove;
	vec3_t vProneRot;
	uint32_t fPosMoveRate;
	uint32_t fPosProneMoveRate;
	float fStandMoveMinSpeed;
	float fDuckedMoveMinSpeed;
	float fProneMoveMinSpeed;
	uint32_t fPosRotRate;
	uint32_t fPosProneRotRate;
	float fStandRotMinSpeed;
	float fDuckedRotMinSpeed;
	float fProneRotMinSpeed;
	char szWorldModel[4];
	int32_t szHudIcon;
	int32_t szModeIcon;
	int32_t iStartAmmo;
	char szAmmoName[4];
	uint32_t iAmmoIndex;
	char szClipName[4];
	uint32_t iClipIndex;
	int32_t iMaxAmmo;
	uint32_t iClipSize;
	uint32_t shotCount;
	char szSharedAmmoCapName[4];
	uint32_t iSharedAmmoCapIndex;
	int32_t iSharedAmmoCap;
	int32_t damage;
	int32_t playerDamage;
	int32_t iMeleeDamage;
	uint32_t iDamageType;
	int32_t iFireDelay;
	int32_t iMeleeDelay;
	uint32_t iFireTime;
	uint32_t iRechamberTime;
	uint32_t iRechamberBoltTime;
	uint32_t iHoldFireTime;
	uint32_t iMeleeTime;
	uint32_t iReloadTime;
	uint32_t iReloadEmptyTime;
	uint32_t iReloadAddTime;
	uint32_t iReloadStartTime;
	uint32_t iReloadStartAddTime;
	uint32_t iReloadEndTime;
	uint32_t iDropTime;
	uint32_t iRaiseTime;
	uint32_t iAltDropTime;
	uint32_t iAltRaiseTime;
	uint32_t quickDropTime;
	uint32_t quickRaiseTime;
	uint32_t iFuseTime;
	int32_t autoAimRange;
	int32_t slowdownAimRange;
	int32_t slowdownAimRangeAds;
	int32_t lockonAimRange;
	int32_t lockonAimRangeAds;
	int32_t enemyCrosshairRange;
	float fMoveSpeedScale;
	int32_t fAdsZoomFov;
	float fAdsZoomInFrac;
	float fAdsZoomOutFrac;
	int32_t szOverlayMaterial;
	int32_t overlayReticle;
	uint32_t overlayWidth;
	int32_t overlayHeight;
	float fAdsBobFactor;
	int32_t fAdsViewBobMult;
	int32_t fHipSpreadStandMin;
	int32_t fHipSpreadDuckedMin;
	int32_t fHipSpreadProneMin;
	int32_t hipSpreadStandMax;
	int32_t hipSpreadDuckedMax;
	int32_t hipSpreadProneMax;
	int32_t fHipSpreadDecayRate;
	int32_t fHipSpreadFireAdd;
	int32_t fHipSpreadTurnAdd;
	int32_t fHipSpreadMoveAdd;
	int32_t fHipSpreadDuckedDecay;
	int32_t fHipSpreadProneDecay;
	uint32_t fHipReticleSidePos;
	uint32_t iAdsTransInTime;
	uint32_t iAdsTransOutTime;
	uint32_t fAdsIdleAmount;
	uint32_t fHipIdleAmount;
	float adsIdleSpeed;
	float hipIdleSpeed;
	float fIdleCrouchFactor;
	float fIdleProneFactor;
	int32_t fGunMaxPitch;
	int32_t fGunMaxYaw;
	float swayMaxAngle;
	float swayLerpSpeed;
	int32_t swayPitchScale;
	int32_t swayYawScale;
	int32_t swayHorizScale;
	int32_t swayVertScale;
	int32_t swayShellShockScale;
	float adsSwayMaxAngle;
	float adsSwayLerpSpeed;
	int32_t adsSwayPitchScale;
	int32_t adsSwayYawScale;
	int32_t adsSwayHorizScale;
	int32_t adsSwayVertScale;
	int32_t bRifleBullet;
	int32_t armorPiercing;
	int32_t bSemiAuto;
	int32_t bBoltAction;
	char bADSPositionInfo[4];
	int32_t bRechamberWhileAds;
	int32_t adsViewErrorMin;
	int32_t adsViewErrorMax;
	int32_t bCookOffHold;
	int32_t bClipOnly;
	uint32_t bWideListIcon;
	int32_t bADSFire;
	int32_t killIcon;
	uint32_t wideKillIcon;
	int32_t flipKillIcon;
	int32_t bNoPartialReload;
	int32_t bSegmentedReload;
	int32_t iReloadAmmoAdd;
	int32_t iReloadStartAdd;
	char szAltWeaponName[4];
	uint32_t iAltWeaponIndex;
	uint32_t iDropAmmoMin;
	uint32_t iDropAmmoMax;
	int32_t iExplosionRadius;
	int32_t iExplosionInnerDamage;
	int32_t iExplosionOuterDamage;
	float iProjectileSpeed;
	float iProjectileSpeedUp;
	char szProjectileModel[4];
	int32_t projExplosion;
	int32_t szProjExplosionEffect;
	char szProjExplosionSound[4];
	int32_t bProjImpactExplode;
	uint8_t parallelBounce[92];
	uint8_t perpendicularBounce[92];
	int32_t szProjTrailEffect;
	int32_t iProjectileDLight;
	vec3_t vProjectileColor;
	int32_t fAdsAimPitch;
	float fAdsCrosshairInFrac;
	float fAdsCrosshairOutFrac;
	int32_t adsGunKickReducedKickBullets;
	int32_t adsGunKickReducedKickPercent;
	int32_t fAdsGunKickPitchMin;
	int32_t fAdsGunKickPitchMax;
	int32_t fAdsGunKickYawMin;
	int32_t fAdsGunKickYawMax;
	int32_t fAdsGunKickAccel;
	float fAdsGunKickSpeedMax;
	float fAdsGunKickSpeedDecay;
	int32_t fAdsGunKickStaticDecay;
	int32_t fAdsViewKickPitchMin;
	int32_t fAdsViewKickPitchMax;
	int32_t fAdsViewKickYawMin;
	int32_t fAdsViewKickYawMax;
	float fAdsViewKickCenterSpeed;
	int32_t fAdsViewScatterMin;
	int32_t fAdsViewScatterMax;
	int32_t fAdsSpread;
	int32_t hipGunKickReducedKickBullets;
	int32_t hipGunKickReducedKickPercent;
	int32_t fHipGunKickPitchMin;
	int32_t fHipGunKickPitchMax;
	int32_t fHipGunKickYawMin;
	int32_t fHipGunKickYawMax;
	int32_t fHipGunKickAccel;
	float fHipGunKickSpeedMax;
	float fHipGunKickSpeedDecay;
	int32_t fHipGunKickStaticDecay;
	int32_t fHipViewKickPitchMin;
	int32_t fHipViewKickPitchMax;
	int32_t fHipViewKickYawMin;
	int32_t fHipViewKickYawMax;
	float fHipViewKickCenterSpeed;
	int32_t fHipViewScatterMin;
	int32_t fHipViewScatterMax;
	int32_t fightDist;
	int32_t maxDist;
	char accuracyGraphName[8];
	uint64_t accuracyGraphKnots;
	uint64_t accuracyGraphKnotCount;
	uint32_t iPositionReloadTransTime;
	int32_t leftArc;
	int32_t rightArc;
	int32_t topArc;
	int32_t bottomArc;
	int32_t accuracy;
	int32_t aiSpread;
	int32_t playerSpread;
	double minTurnSpeed;
	double maxTurnSpeed;
	uint32_t pitchConvergenceTime;
	uint32_t yawConvergenceTime;
	uint32_t suppressTime;
	int32_t maxRange;
	int32_t fAnimHorRotateInc;
	uint32_t fPlayerPositionDist;
	char szUseHintString[4];
	char dropHintString[4];
	char iUseHintStringIndex[4];
	char dropHintStringIndex[4];
	int32_t horizViewJitter;
	int32_t vertViewJitter;
	char szScript[4];
	uint64_t fOOPosAnimLength;
	int32_t minDamage;
	int32_t minPlayerDamage;
	int32_t fMaxDamageRange;
	int32_t fMinDamageRange;
	uint32_t destabilizationBaseTime;
	uint32_t destabilizationTimeReductionRatio;
	float destabilizationAngleMax;
	int32_t destabilizeDistance;
	uint8_t locationDamageMultipliers[76];
	int32_t fireRumble;
	int32_t meleeImpactRumble;
};

typedef enum
{
	WEAPTYPE_BULLET = 0,
	WEAPTYPE_GRENADE = 1,
	WEAPTYPE_PROJECTILE = 2,
	WEAPTYPE_BINOCULARS = 3,
	WEAPTYPE_NUM = 4
} weapType_t;

typedef enum
{
	WEAPCLASS_RIFLE = 0,
	WEAPCLASS_MG = 1,
	WEAPCLASS_SMG = 2,
	WEAPCLASS_SPREAD = 3,
	WEAPCLASS_PISTOL = 4,
	WEAPCLASS_GRENADE = 5,
	WEAPCLASS_ROCKETLAUNCHER = 6,
	WEAPCLASS_TURRET = 7,
	WEAPCLASS_NON_PLAYER = 8,
	WEAPCLASS_ITEM = 9,
	WEAPCLASS_NUM = 10
} weapClass_t;

typedef enum
{
	WEAPSLOT_NONE = 0,
	WEAPSLOT_PRIMARY = 1,
	WEAPSLOT_PRIMARYB = 2,
	WEAPSLOT_NUM = 3
} weapSlot_t;

typedef enum
{
	OFFHAND_CLASS_NONE = 0,
	OFFHAND_CLASS_FRAG_GRENADE = 1,
	OFFHAND_CLASS_SMOKE_GRENADE = 2,
	OFFHAND_CLASS_COUNT = 3
} OffhandClass;

typedef enum
{
	WEAPSTANCE_STAND = 0,
	WEAPSTANCE_DUCK = 1,
	WEAPSTANCE_PRONE = 2,
	WEAPSTANCE_NUM = 3
} weapStance_t;

typedef enum
{
	WEAPOVERLAYRETICLE_NONE = 0,
	WEAPOVERLAYRETICLE_CROSSHAIR = 1,
	WEAPOVERLAYRETICLE_FG42 = 2,
	WEAPOVERLAYRETICLE_SPRINGFIELD = 3,
	WEAPOVERLAYRETICLE_BINOCULARS = 4,
	WEAPOVERLAYRETICLE_NUM = 5
} weapOverlayReticle_t;

typedef enum
{
	WEAPPROJEXP_GRENADE = 0,
	WEAPPROJEXP_ROCKET = 1,
	WEAPPROJEXP_NONE = 2,
	WEAPPROJEXP_NUM = 3
} weapProjExposion_t;

struct weaponState_t
{
	int32_t ps;
	float xyspeed;
	uint32_t frametime;
	vec3_t vLastMoveAng;
	float fLastIdleFactor;
	uint32_t time;
	uint32_t damageTime;
	int32_t v_dmg_pitch;
	int32_t v_dmg_roll;
	vec3_t vGunOffset;
	vec3_t vGunSpeed;
	vec3_t swayAngles;
	uint32_t weapIdleTime;
};

struct viewState_t
{
	int32_t ps;
	uint32_t damageTime;
	uint32_t time;
	int32_t v_dmg_pitch;
	int32_t v_dmg_roll;
	float xyspeed;
	uint32_t frametime;
	float fLastIdleFactor;
	uint32_t weapIdleTime;
};

struct VariableStackBuffer
{
	uint32_t pos;
	uint16_t size;
	uint16_t bufLen;
	uint16_t localId;
	int8_t time;
	int8_t buf;
};

union VariableUnion
{
	int32_t intValue;
	float floatValue;
	char stringValue[4];
	int32_t vectorValue;
	uint32_t codePosValue;
	int32_t pointerValue;
	int32_t stackValue;
	uint32_t entityOffset;
};

struct VariableValue_s
{
	VariableUnion u;
	int32_t type;
};

struct scr_entref_t
{
	uint16_t entnum;
	uint16_t classnum;
};

struct function_stack_t
{
	uint32_t pos;
	uint32_t localId;
	uint32_t localVarCount;
	int32_t top;
	int32_t startTop;
};

struct $_3635
{
	void *fieldBuffer;
	int32_t mark;
	uint16_t canonicalStrCount;
	int8_t developer;
	int8_t developer_script;
	int8_t evaluate;
	char pad0[3];
	char error_message[4];
	uint32_t error_index;
	uint32_t time;
	uint32_t timeArrayId;
	uint32_t pauseArrayId;
	uint32_t levelId;
	uint32_t gameId;
	uint32_t animId;
	int32_t freeEntList;
	int32_t tempVariable;
	int8_t bInited;
	char pad1[1];
	uint16_t savecount;
	int32_t checksum;
	uint32_t entId;
	char entFieldName[4];
	void *programBuffer;
	char endScriptBuffer[4];
	uint8_t saveIdMap[131068];
	uint8_t saveIdMapRev[131068];
};

struct function_frame_t
{
	uint8_t fs[20];
	int32_t topType;
};

struct $_3636
{
	int8_t dummy;
};

struct Variable
{
	uint16_t id;
	$_3652 u;
};

struct $_3656
{
	int32_t colorForDir;
	int32_t sunVisibility;
};

struct $_3654
{
	int32_t ps;
	uint32_t damageTime;
	uint32_t time;
	int32_t v_dmg_pitch;
	int32_t v_dmg_roll;
	float xyspeed;
	uint32_t frametime;
	float fLastIdleFactor;
	uint32_t weapIdleTime;
};

union $_3655
{
	$_3656 dx7;
	vec3_t baseCoords;
	vec3_t origin;
};

struct VariableValueInternal
{
	Variable hash;
	$_3654 u;
	$_3655 w;
	$_3656 v;
	int16_t nextSibling;
};

struct $_3653
{
	int32_t ps;
	float xyspeed;
	uint32_t frametime;
	vec3_t vLastMoveAng;
	float fLastIdleFactor;
	uint32_t time;
	uint32_t damageTime;
	int32_t v_dmg_pitch;
	int32_t v_dmg_roll;
	vec3_t vGunOffset;
	vec3_t vGunSpeed;
	vec3_t swayAngles;
	uint32_t weapIdleTime;
};

struct ObjectInfo
{
	uint16_t refCount;
	$_3653 u;
};

struct ThreadDebugInfo
{
	uint8_t pos[128];
	uint32_t posSize;
	int32_t varUsage;
	int32_t endonUsage;
};

struct $_3657
{
	uint8_t variableList[1048544];
};

struct scr_classStruct_t
{
	uint16_t id;
	uint16_t entArrayId;
	int8_t charId;
	char pad0[3];
	char name[4];
};

struct scr_block_s
{
	int32_t abortLevel;
	uint32_t localVarsCreateCount;
	uint32_t localVarsPublicCount;
	uint32_t localVarsCount;
	uint64_t localVarsInitBits;
	uint8_t localVars[256];
};

struct scr_localVar_t
{
	char name[4];
};

struct VariableCompileValue
{
	uint64_t value;
	uint32_t sourcePos;
};

struct ContinueStatementInfo
{
	uint32_t codePos;
	uint32_t nextCodePos;
	int32_t next;
};

struct BreakStatementInfo
{
	uint32_t codePos;
	uint32_t nextCodePos;
	int32_t next;
};

struct CaseStatementInfo
{
	char name[4];
	uint32_t codePos;
	uint32_t sourcePos;
	int32_t next;
};

struct PrecacheEntry
{
	char filename[2];
	int8_t include;
	char pad0[1];
	uint32_t sourcePos;
	int32_t next;
};

struct $_3620
{
	uint8_t msgs[22528];
	int32_t get;
	int32_t send;
};

struct $_3677
{
	int32_t header;
	uint32_t fileSize;
	int32_t checksum;
};

struct OpcodeLookup
{
	uint32_t codePos;
	uint32_t sourcePosIndex;
	uint32_t sourcePosCount;
	uint32_t profileTime;
	int32_t profileUsage;
};

struct SourceLookup
{
	uint32_t sourcePos;
	int32_t type;
};

struct SaveSourceBufferInfo
{
	void *sourceBuf;
	uint32_t len;
};

struct Scr_SourcePos_t
{
	uint32_t bufferIndex;
	uint32_t lineNum;
	uint32_t sourcePos;
};

struct $_3645
{
	uint32_t pos;
	uint32_t localId;
	uint32_t localVarCount;
	int32_t top;
	int32_t startTop;
};

struct $_3661
{
	int32_t opcodeLookup;
	uint32_t opcodeLookupMaxLen;
	uint32_t opcodeLookupLen;
	uint32_t sourcePosLookup;
	uint32_t sourcePosLookupMaxLen;
	uint32_t sourcePosLookupLen;
	uint32_t sourceBufferLookupMaxLen;
	uint32_t currentCodePos;
	uint32_t currentSourcePosCount;
	void *saveSourceBufferLookup;
	uint32_t saveSourceBufferLookupLen;
	uint32_t delayedSourceIndex;
	uint32_t threadStartSourceIndex;
};

struct shellshock_t
{
	int32_t parms;
	uint32_t startTime;
	int32_t duration;
	uint32_t loopEndTime;
	int32_t sensitivity;
	uint64_t viewDelta;
	int32_t hasSavedScreen;
};

struct MarkPoly
{
	int32_t prevMark;
	int32_t nextMark;
	int32_t lastFrameDrawn;
	vec3_t origin;
	int32_t radius;
	uint32_t mtlHandle;
	uint16_t lmapIndex;
	uint8_t vertCount;
	char pad0[1];
	uint8_t verts[612];
};

struct playerEntity_t
{
	float fLastWeaponPosFrac;
	uint32_t bPositionToADS;
	vec3_t vPositionLastOrg;
	float fLastIdleFactor;
	vec3_t vLastMoveOrg;
	vec3_t vLastMoveAng;
};

struct $_3725
{
	uint32_t time;
	int32_t duration;
};

struct bgs_t
{
	animScriptData_t animScriptData;
	$_3674 generic_human;
	uint32_t time;
	uint32_t latestSnapshotTime;
	uint32_t frametime;
	int32_t anim_user;
	char GetXModel[4];
	int32_t CreateDObj;
	int32_t SafeDObjFree;
	int32_t AllocXAnim;
	char clientinfo[77312];
};

struct $_3724
{
	int32_t clientFrame;
	uint32_t clientNum;
	char demoType[4];
	int32_t cubemapShot;
	uint32_t cubemapSize;
	int32_t renderScreen;
	uint32_t latestSnapshotNum;
	uint32_t latestSnapshotTime;
	int32_t snap;
	int32_t nextSnap;
	uint8_t activeSnapshots[154496];
	int32_t frameInterpolation;
	uint32_t frametime;
	uint32_t time;
	uint32_t oldTime;
	uint32_t physicsTime;
	int32_t mapRestart;
	int32_t renderingThirdPerson;
	uint8_t predictedPlayerState[9896];
	uint8_t predictedPlayerEntity[548];
	playerEntity_t playerEntity;
	uint32_t predictedErrorTime;
	vec3_t predictedError;
	int32_t stepChange;
	uint32_t stepTime;
	int32_t landChange;
	uint32_t landTime;
	vec3_t autoAnglesSlow;
	vec3_t autoAxisSlow[3];
	vec3_t autoAngles;
	vec3_t autoAxis[3];
	vec3_t autoAnglesFast;
	vec3_t autoAxisFast[3];
	refdef_s refdef;
	vec3_t refdefViewAngles;
	vec3_t swayViewAngles;
	vec3_t swayAngles;
	vec3_t swayOffset;
	uint8_t iEntityLastType[4096];
	char pEntityLastXModel[4096];
	int32_t zoomSensitivity;
	char infoScreenText[1024];
	char objectiveText[1024];
	char scriptMainMenu[256];
	uint32_t scoresRequestTime;
	uint32_t numScores;
	uint8_t teamScores[16];
	uint8_t teamPings[16];
	uint8_t teamPlayers[16];
	uint8_t scores[1536];
	int32_t showScores;
	uint32_t scoreFadeTime;
	int32_t scoresTop;
	int32_t scoresOffBottom;
	int32_t firstLineVisible;
	int32_t lastLineVisible;
	char killerName[32];
	char spectatorList[1024];
	char spectatorLen[4];
	char spectatorWidth[4];
	char spectatorTime[4];
	char spectatorPaintX[4];
	char spectatorPaintX2[4];
	char spectatorOffset[4];
	char spectatorPaintLen[4];
	int32_t showItems;
	uint32_t itemFadeTime;
	uint32_t centerPrintTime;
	uint32_t centerPrintCharWidth;
	uint8_t centerPrint[1024];
	int32_t centerPrintLines;
	int32_t centerPrintPriority;
	uint32_t fadeTime;
	int32_t fadeRate;
	vec4_t fadeColor1;
	vec4_t fadeColor2;
	int32_t drawHud;
	uint32_t crosshairClientNum;
	uint32_t crosshairClientTime;
	uint32_t crosshairPowerupNum;
	uint32_t crosshairPowerupTime;
	uint32_t identifyClientNum;
	uint32_t identifyClientHealth;
	uint32_t identifyNextTime;
	int32_t cursorHintIcon;
	uint32_t cursorHintTime;
	int32_t cursorHintFade;
	char cursorHintString[4];
	uint32_t lastClipFlashTime;
	uint32_t lastHealthPulseTime;
	int32_t lastHealthLerpDelay;
	int32_t lastHealthClient;
	int32_t lastHealth;
	int32_t healthOverlayFromAlpha;
	int32_t healthOverlayToAlpha;
	uint32_t healthOverlayPulseTime;
	int32_t healthOverlayPulseDuration;
	int32_t healthOverlayPulsePhase;
	int8_t healthOverlayHurt;
	char pad0[3];
	uint32_t healthOverlayLastHitTime;
	int32_t healthOverlayOldHealth;
	uint32_t healthOverlayPulseIndex;
	uint32_t proneBlockedEndTime;
	int32_t lastStance;
	uint32_t lastStanceChangeTime;
	uint32_t lastStanceFlashTime;
	int32_t powerupActive;
	uint32_t powerupTime;
	uint32_t attackerTime;
	uint32_t voiceTime;
	int32_t weaponSelect;
	uint32_t weaponSelectTime;
	int32_t weaponAnimation;
	uint32_t weaponAnimationTime;
	vec3_t fWeapSelectFrac;
	uint32_t iWeapSelectLastDrawTime;
	int32_t equippedOffHand;
	vec3_t viewDamage[8];
	uint32_t damageTime;
	int32_t damageX;
	int32_t damageY;
	int32_t damageValue;
	int32_t viewFade;
	int32_t nomarks;
	uint32_t weapIdleTime;
	int32_t headYaw;
	int32_t headEndPitch;
	int32_t headEndYaw;
	uint32_t headEndTime;
	int32_t headStartPitch;
	int32_t headStartYaw;
	uint32_t headStartTime;
	uint32_t v_dmg_time;
	int32_t v_dmg_pitch;
	int32_t v_dmg_roll;
	int32_t fBobCycle;
	float xyspeed;
	uint32_t nextOrbitTime;
	GfxEntity testModelEntity;
	char testModelName[64];
	int32_t testGun;
	char testFxName[64];
	vec3_t testFxPos;
	uint32_t testFxTime;
	uint32_t testFxRespawnTime;
	vec3_t kickAVel;
	vec3_t kickAngles;
	vec3_t offsetAngles;
	uint64_t vKickScatter;
	uint64_t vNewKickScatterChange;
	int32_t vKickScatterLerp;
	float vKickScatterFrac;
	int32_t iLastKickScatterDir;
	double vLastCompensationViewAngles;
	uint64_t vKickCompensation;
	uint64_t vKickCompensationCentering;
	uint64_t bManualKickCompensation;
	int32_t gunPitch;
	int32_t gunYaw;
	int32_t gunXOfs;
	int32_t gunYOfs;
	int32_t gunZOfs;
	vec3_t vGunOffset;
	vec3_t vGunSpeed;
	char viewModelOrigin[12];
	char viewModelAxis[36];
	char viewModelAngles[12];
	uint32_t oidTeam;
	uint32_t oidPrintTime;
	uint32_t oidPrintCharWidth;
	uint32_t oidPrintY;
	uint8_t oidPrint[1024];
	uint32_t oidPrintLines;
	uint8_t cameraShake[144];
	int32_t cameraShakePhase;
	int32_t rumbleScale;
	char latchVictorySound[4];
	uint32_t compassLastTime;
	int32_t compassNorthYaw;
	int32_t compassYaw;
	float compassSpeed;
	int32_t compPointerYaw;
	float compPointerSpeed;
	uint32_t compassFadeTime;
	uint32_t healthFadeTime;
	uint32_t ammoFadeTime;
	uint32_t stanceFadeTime;
	uint32_t offhandFadeTime;
	uint32_t offhandFlashTime;
	uint8_t compassActors[1792];
	shellshock_t shellshock;
	$_3725 testShock;
	uint32_t holdBreathTime;
	uint32_t holdBreathInTime;
	int32_t holdBreathDelay;
	float holdBreathFrac;
	int32_t adsViewErrorDone;
	int32_t inKillCam;
	bgs_t bgs;
	MarkPoly activeMarkPolys;
};

struct MantleResults
{
	vec3_t dir;
	vec3_t startPos;
	vec3_t ledgePos;
	vec3_t endPos;
	uint32_t flags;
	int32_t duration;
};

struct MantleAnimTransition
{
	uint32_t upAnimIndex;
	uint32_t overAnimIndex;
	int32_t height;
};

struct $_3660
{
	int32_t colorForDir;
	int32_t sunVisibility;
};

union $_3659
{
	$_3660 dx7;
	vec3_t baseCoords;
	vec3_t origin;
};

union GfxModel
{
	int32_t obj;
	char model[4];
	char bmodel[4];
	int32_t data;
};

struct g_sa_type
{
	uint8_t initialized[3];
	char pad0[1];
	int32_t randSeed;
	uint8_t pHash[4096];
	char aliasInfo[48];
	char soundFileInfo[24];
	char szLoadSpec[64];
	int8_t curvesInitialized;
	char pad1[3];
	uint8_t volumeFalloffCurves[1152];
	char volumeFalloffCurveNames[1024];
};

struct SoundFileInfo
{
	uint32_t count;
	int32_t files;
};

struct com_parse_mark_t
{
	int32_t lines;
	char text[4];
	int32_t ungetToken;
	int32_t backup_lines;
	char backup_text[4];
};

struct ParseThreadInfo
{
	char parseInfo[17856];
	char parseInfoNum[4];
	uint32_t tokenPos;
	uint32_t prevTokenPos;
	uint8_t line[1024];
};

struct statmonitor_s
{
	uint32_t endtime;
	int32_t material;
};

struct archivedEntityShared_t
{
	uint32_t svFlags;
	uint64_t clientMask;
	vec3_t absmin;
	vec3_t absmax;
};

struct archivedEntity_s
{
	uint8_t s[240];
	archivedEntityShared_t r;
};
struct svEntity_s
{
	int16_t worldSector;
	int16_t nextEntityInWorldSector;
	archivedEntity_s baseline;
	uint32_t numClusters;
	uint8_t clusternums[64];
	int32_t lastCluster;
	int32_t linkcontents;
	uint64_t linkmin;
	uint64_t linkmax;
};

struct worldContents_s
{
	char contentsStaticModels[4];
	int32_t contentsEntities;
	int16_t entities;
	char staticModels[2];
};

union $_3780
{
	int16_t parent;
	int16_t nextFree;
};
struct worldTree_s
{
	int32_t dist;
	int16_t axis;
	$_3780 u;
	int32_t child;
};
struct worldSector_s
{
	worldContents_s contents;
	worldTree_s tree;
};

struct areaParms_t
{
	int32_t start;
	int32_t mins;
	int32_t maxs;
	int32_t list;
	uint32_t count;
	uint32_t maxcount;
	uint32_t contentmask;
	int32_t results;
};

struct sightpointtrace_t
{
	vec3_t start;
	vec3_t end;
	uint64_t passEntityNum;
	uint32_t contentmask;
	int32_t locational;
};

struct staticmodeltrace_t
{
	TraceExtents extents;
	int32_t contents;
};

struct sightclip_t
{
	vec3_t mins;
	vec3_t maxs;
	vec3_t outerSize;
	vec3_t start;
	vec3_t end;
	uint64_t passEntityNum;
	uint32_t contentmask;
};

struct locTraceWork_t
{
	int32_t contents;
	uint8_t extents[36];
};

struct pointtrace_t
{
	uint8_t extents[36];
	uint32_t passEntityNum;
	uint32_t passOwnerNum;
	uint32_t contentmask;
	int32_t bLocational;
	int32_t priorityMap;
};

struct moveclip_t
{
	vec3_t mins;
	vec3_t maxs;
	vec3_t outerSize;
	uint8_t extents[36];
	uint32_t passEntityNum;
	uint32_t passOwnerNum;
	uint32_t contentmask;
};

struct cm_world_t
{
	vec3_t mins;
	vec3_t maxs;
	int8_t lockTree;
	char pad0[1];
	int16_t freeHead;
	uint8_t sectors[24576];
};

typedef enum
{
	FMV_IDLE = 0,
	FMV_PLAY = 1,
	FMV_EOF = 2,
	FMV_ID_BLT = 3,
	FMV_ID_IDLE = 4,
	FMV_LOOPED = 5,
	FMV_ID_WAIT = 6
} e_status;

struct $_3803
{
	uint8_t linbuf[2097152];
	uint8_t file[65536];
	uint8_t sqrTable[512];
	uint8_t mcomp[1024];
	char qStatus[262144];
	int32_t oldXOff;
	int32_t oldYOff;
	uint32_t oldysize;
	uint32_t oldxsize;
	uint32_t currentHandle;
};

struct cin_cache
{
	char fileName[256];
	uint32_t CIN_WIDTH;
	int32_t CIN_HEIGHT;
	uint32_t xpos;
	uint32_t ypos;
	uint32_t width;
	int32_t height;
	int32_t looping;
	int32_t holdAtEnd;
	int32_t dirty;
	int32_t alterGameState;
	uint32_t silent;
	int32_t material;
	int32_t letterBox;
	char sound[4];
	int32_t iFile;
	char status[4];
	uint32_t startTime;
	uint32_t lastFrameTime;
	uint32_t lastTime;
	int32_t tfps;
	int32_t RoQPlayed;
	uint32_t ROQSize;
	uint32_t RoQFrameSize;
	int32_t onQuad;
	uint32_t numQuads;
	int32_t samplesPerLine;
	uint32_t roq_id;
	int32_t screenDelta;
	int32_t VQ0;
	int32_t VQ1;
	int32_t VQNormal;
	void *VQBuffer;
	int32_t samplesPerPixel;
	int32_t gray;
	uint32_t xsize;
	uint32_t ysize;
	uint32_t maxsize;
	uint32_t minsize;
	int32_t half;
	int32_t smootheddouble;
	int32_t inMemory;
	void *normalBuffer0;
	uint32_t roq_flags;
	int32_t roqF0;
	int32_t roqF1;
	uint64_t t;
	int32_t roqFPS;
	int32_t playonwalls;
	void *buf;
	int32_t previousGameState;
};

typedef enum
{
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

struct MD4_CTX
{
	uint8_t state[16];
	uint64_t count;
	uint8_t buffer[64];
};

struct LegacyHacks
{
	int32_t cg_norender;
	int32_t cl_running;
	int32_t cl_stance;
	int32_t cl_stanceTemp;
	char cl_downloadSize[4];
	char cl_downloadCount[4];
	char cl_downloadTime[4];
	char cl_downloadName[64];
	uint8_t cl_serverloadmap[64];
	char cl_serverloadgametype[64];
	int8_t cl_serverloadwaiting;
	int8_t sv_killserver;
	uint8_t sv_killreason[256];
	char ui_scriptMenu[256];
	char pad0[2];
	char ui_scriptMenuIndex[4];
	char ui_newScriptMenu[256];
	char ui_newScriptMenuIndex[4];
	char ui_waitingScriptMenu[256];
	char ui_waitingScriptMenuIndex[4];
	int8_t ui_waitingScriptMenuNoMouse;
	int8_t ui_scriptMenuAllowResponse;
	char ui_savegameName[256];
	char ui_savegameInfo[256];
	int8_t winnt;
	char pad1[1];
	uint32_t persid;
};

struct TestLod
{
	int8_t enabled;
	char pad0[3];
	int32_t dist;
};

struct snd_alias_build_s
{
	uint8_t szSourceFile[64];
	char szAliasName[64];
	char szSecondaryAliasName[64];
	char subtitleText[4];
	int32_t iSequence;
	char szSoundFile[64];
	char permSoundFile[4];
	int32_t fVolMin;
	int32_t fVolMax;
	int32_t fVolMod;
	int32_t fPitchMin;
	int32_t fPitchMax;
	int32_t fDistMin;
	int32_t fDistMax;
	int32_t iChannel;
	int32_t eType;
	int32_t volumeFalloffCurve;
	int32_t fSlavePercentage;
	int32_t fProbability;
	int32_t fLfePercentage;
	int32_t startDelay;
	int8_t bLooping;
	int8_t bMaster;
	int8_t bSlave;
	int8_t bFullDryLevel;
	int8_t bNoWetLevel;
	int8_t error;
	int8_t keep;
	char pad0[1];
	char pSameSoundFile[4];
	int32_t pNext;
};

typedef enum
{
	SA_INVALID = 0,
	SA_NAME = 1,
	SA_SEQUENCE = 2,
	SA_FILE = 3,
	SA_SUBTITLE = 4,
	SA_VOL_MIN = 5,
	SA_VOL_MAX = 6,
	SA_VOL_MOD = 7,
	SA_PITCH_MIN = 8,
	SA_PITCH_MAX = 9,
	SA_DIST_MIN = 10,
	SA_DIST_MAX = 11,
	SA_CHANNEL = 12,
	SA_TYPE = 13,
	SA_LOOP = 14,
	SA_PROBABILITY = 15,
	SA_LOADSPEC = 16,
	SA_MASTERSLAVE = 17,
	SA_SECONDARYALIASNAME = 18,
	SA_VOLUMEFALLOFFCURVE = 19,
	SA_STARTDELAY = 20,
	SA_SPEAKERMAP = 21,
	SA_REVERB = 22,
	SA_LFEPERCENTAGE = 23,
	SA_NUMFIELDS = 24
} snd_alias_members_t;

struct saLoadObjGlob_type
{
	char tempAliases[4];
	char tempAliasCount[4];
	uint8_t volumeModGroups[2176];
	int8_t volumeModGroupsInitialized;
	int8_t refreshVolumeModGroupsCommandInitialized;
};

struct VolumeModGroup
{
	char name[64];
	int32_t value;
};

union $_3678
{
	int16_t b;
	int16_t s;
};

union $_3680
{
	int32_t b;
	int32_t f;
};

struct clientState_s
{
	uint32_t clientIndex;
	int32_t team;
	char modelindex[4];
	char attachModelIndex[24];
	uint8_t attachTagIndex[24];
	char name[32];
};
struct $_3696
{
	uint32_t snapFlags;
	int32_t ping;
	uint32_t serverTime;
	playerState_s ps;
	uint32_t numEntities;
	uint32_t numClients;
	entityState_s entities[256];
	clientState_s clients[64];
	char serverCommandSequence[4];
};

struct XModelConfigEntry
{
	char filename[1024];
	int32_t dist;
};

union $_3679
{
	int32_t b;
	int32_t i;
};

struct infoParm_t
{
	char name[4];
	uint32_t clearSolid;
	uint32_t surfaceFlags;
	int32_t contents;
	uint32_t toolFlags;
};

struct token_s
{
	char string[1024];
	int32_t type;
	int32_t subtype;
	int32_t intvalue;
	char pad0[4];
	uint8_t floatvalue[16];
	int32_t whitespace_p;
	int32_t endwhitespace_p;
	int32_t line;
	int32_t linescrossed;
	int32_t next;
};
struct source_s
{
	char filename[64];
	char includepath[64];
	int32_t punctuations;
	char scriptstack[4];
	int32_t tokens;
	int32_t defines;
	int32_t definehash;
	int32_t indentstack;
	int32_t skip;
	char pad0[4];
	token_s token;
};

struct punctuation_s
{
	int32_t p;
	int32_t n;
	int32_t next;
};

struct script_s
{
	char filename[64];
	void *buffer;
	char script_p[4];
	int32_t end_p;
	char lastscript_p[4];
	int32_t whitespace_p;
	int32_t endwhitespace_p;
	uint32_t length;
	int32_t line;
	int32_t lastline;
	int32_t tokenavailable;
	uint32_t flags;
	int32_t punctuations;
	int32_t punctuationtable;
	char pad0[12];
	token_s token;
	int32_t next;
};

struct define_s
{
	char name[4];
	uint32_t flags;
	int32_t builtin;
	uint32_t numparms;
	int32_t parms;
	int32_t tokens;
	int32_t next;
	int32_t hashnext;
};

struct indent_s
{
	int32_t type;
	int32_t skip;
	char script[4];
	int32_t next;
};

struct builtin_s
{
	char string[4];
	int32_t builtin;
};

struct operator_s
{
	int32_t op;
	int32_t priority;
	int32_t parentheses;
	int32_t prev;
	int32_t next;
};

struct value_s
{
	int32_t intvalue;
	double floatvalue;
	int32_t parentheses;
	int32_t prev;
	int32_t next;
};

struct pc_token_s
{
	int32_t type;
	int32_t subtype;
	int32_t intvalue;
	float floatvalue;
	char string[1024];
};

struct directive_s
{
	char name[4];
	int32_t func;
};

struct $_3782
{
	uint32_t evTime;
	int32_t evType;
	int32_t evValue;
	int32_t evValue2;
	uint32_t evPtrLength;
	void *evPtr;
};

struct $_3776
{
	int32_t type;
	int32_t ip;
	uint16_t port;
};

struct $_3798
{
	void *reflib_library;
	void *reflib_active;
	int32_t hWnd;
	int32_t hInstance;
	int32_t activeApp;
	int32_t isMinimized;
	uint32_t sysMsgTime;
};

struct dirent
{
	int32_t d_ino;
	uint16_t d_reclen;
	int8_t d_type;
	uint8_t d_namlen;
	char d_name[256];
};

struct GfxSceneEntity
{
	uint32_t refCount;
	GfxModel u;
	int32_t cent;
	int32_t cullState;
	uint32_t surfCount;
	vec3_t curMins;
	vec3_t curMaxs;
	int32_t materials;
	int32_t surfs;
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
	vec3_t bounds[2];
	uint32_t surfaceCount;
	uint32_t startSurfIndex;
};

struct MaterialInfoObj_s
{
	char name[4];
	char refImageName[4];
	uint16_t hashIndex;
	uint16_t sortedIndex;
	int8_t gameFlags;
	int8_t sortKey;
	uint8_t textureAtlasRowCount;
	uint8_t textureAtlasColumnCount;
	int32_t maxDeformMove;
	int8_t deformFlags;
	int8_t usage;
	int16_t toolFlags;
	int32_t locale;
	uint16_t autoTexScaleWidth;
	int16_t autoTexScaleHeight;
	uint32_t tessSize;
	uint32_t surfaceFlags;
	int32_t contents;
};
struct Material
{
	MaterialInfoObj_s info;
	uint64_t stateBits;
	char textureCount[2];
	uint16_t constantCount;
	int32_t techniqueSet;
	char textures[4];
	int32_t constants;
};

struct MaterialTechniqueSet
{
	char name[4];
	uint8_t techniques[136];
};

union MaterialTextureDefInfo
{
	int32_t image;
	int32_t water;
};

struct MaterialTextureDef
{
	char name[4];
	int8_t samplerState;
	int8_t semantic;
	int8_t unused_0;
	int8_t unused_1;
	MaterialTextureDefInfo u;
};

struct MaterialConstantDefObj
{
	char name[4];
	uint8_t literal[16];
};

union MaterialPassArray
{
	uint8_t dx7[92];
	uint8_t dx9[28];
};

struct MaterialTechnique
{
	char name[4];
	int16_t flags;
	uint16_t passCount;
	MaterialPassArray passArray;
};

struct Picmip
{
	int16_t platform;
};

union GfxTexture
{
	int32_t basemap;
	int32_t map;
	int32_t volmap;
	int32_t cubemap;
	int32_t loadDef;
};

struct CardMemory
{
	uint64_t platform;
};

struct GfxImage
{
	int32_t mapType;
	GfxTexture texture;
	Picmip picmip;
	int8_t semantic;
	int8_t noPicmip;
	int8_t track;
	char pad0[3];
	CardMemory cardMemory;
	uint16_t width;
	int16_t height;
	int16_t depth;
	int8_t category;
	char pad1[1];
	char name[4];
};

struct MaterialWaterDef
{
	char textureWidth[4];
	uint32_t horizontalWorldLength;
	uint32_t verticalWorldLength;
	int32_t amplitude;
	float windSpeed;
	uint64_t windDirection;
	int32_t map;
};

struct WaterWritable
{
	uint32_t frameCount;
};

struct water_t
{
	WaterWritable writable;
	int32_t H0;
	int32_t wTerm;
	int32_t M;
	int32_t N;
	int32_t Lx;
	int32_t Lz;
	int32_t gravity;
	int32_t windvel;
	uint64_t winddir;
	int32_t amplitude;
	uint8_t codeConstant[16];
	int32_t image;
};

struct MaterialPassDx7
{
	int32_t stateMap;
	int8_t gridLighting;
	int8_t projectToInfinity;
	int8_t ambientLighting;
	int8_t objectiveGlow;
	int8_t fogToBlack;
	int16_t genTexCoords;
	char pad0[1];
	uint8_t samplers[16];
	uint8_t colorStageBits[32];
	uint8_t alphaStageBits[32];
};

struct MaterialPassDx9
{
	int32_t stateMap;
	int32_t vertexDecl;
	int32_t vertexShader;
	int32_t pixelShader;
	uint16_t vertexArgCount;
	uint16_t pixelArgCount;
	int32_t vertexArgs;
	int32_t pixelArgs;
};

struct GfxImageLoadDef
{
	int8_t format;
	int8_t flags;
	uint8_t dimensions[6];
	int32_t data;
	uint32_t resourceSize;
};

struct MaterialStateMap
{
	char name[4];
	uint8_t ruleSet[44];
};

struct MaterialArgumentCodeConst
{
	uint16_t index;
	int8_t firstRow;
	uint8_t rowCount;
};

union MaterialArgumentDef
{
	int32_t literalConst;
	MaterialArgumentCodeConst codeConst;
	int32_t codeSampler;
	char name[4];
};

struct MaterialShaderArgument
{
	int16_t type;
	int16_t dest;
	MaterialArgumentDef u;
};

struct MaterialVertexDeclaration
{
	int32_t data;
	uint32_t streamCount;
	uint8_t decl[16];
};

union MaterialShaderPtr
{
	int32_t vs;
	int32_t ps;
};

struct MaterialShader
{
	char name[4];
	int32_t program;
	uint16_t programLen;
	int8_t shaderType;
	int8_t shaderVersion;
	MaterialShaderPtr u;
};

struct complex_s
{
	int32_t real;
	int32_t imag;
};

struct MaterialStreamRouting
{
	int8_t source;
	int8_t dest;
};

struct MaterialStateMapRuleSet
{
	uint32_t ruleCount;
	uint8_t rules[32];
};

struct MaterialStateMapRule
{
	uint64_t stateBitsMask;
	uint64_t stateBitsValue;
	uint64_t stateBitsSet;
	uint64_t stateBitsClear;
};

struct GfxDrawSurf
{
	int32_t sort;
	int32_t surface;
};

struct GfxViewParms
{
	vec3_t origin;
	vec3_t axis[3];
	D3DVIEWPORT9 viewport;
	D3DMATRIX viewMatrix;
	matrix4_t projectionMatrix;
	matrix4_t viewProjectionMatrix;
	matrix4_t inverseViewProjectionMatrix;
	int32_t depthHackNearClip;
};

typedef enum
{
	SHADOW_NONE = 0,
	SHADOW_COOKIE = 1
} ShadowType;

struct GfxPostProcessParms
{
	int32_t blurRadius;
	int8_t isRenderingFullScreen;
};

struct GfxLightDir
{
	vec3_t ambientColor;
};

union GfxLightInfo
{
	GfxLightDir dir;
};

struct GfxLight
{
	int32_t def;
	vec4_t position;
	vec3_t color;
	GfxLightInfo u;
};

struct GfxLightImage
{
	int32_t image;
	int8_t samplerState;
};

struct GfxLightDef
{
	int32_t type;
	GfxLightImage cookie;
	uint64_t attenuation;
	char name[4];
};

typedef enum
{
	GFX_LIGHT_TYPE_SUN = 0,
	GFX_LIGHT_TYPE_SKY = 1,
	GFX_LIGHT_TYPE_POINT = 2,
	GFX_LIGHT_TYPE_COUNT = 3
} GfxLightType;

struct GfxModelSurface
{
	int32_t surfType;
	int32_t xsurf;
};

struct XRigidSurface
{
	int32_t vb;
};

struct XSurface_s
{
	int8_t tileMode;
	char pad0[1];
	uint16_t vertCount;
	uint16_t triCount;
	uint16_t boneOffset;
	int32_t triIndices;
	int32_t verts;
	XRigidSurface surfRigid;
	uint32_t indexBuffer;
};

struct XVertexInfo_s
{
	vec3_t normal;
	int32_t color;
	vec3_t binormal;
	int32_t texCoordX;
	vec3_t tangent;
	int32_t texCoordY;
	vec3_t offset;
	uint8_t numWeights;
	int8_t boneWeight;
	uint16_t boneOffset;
};

struct XVertexBuffer
{
	XVertexInfo_s v;
	uint8_t w[16];
};

struct XBlendInfo_s
{
	vec3_t offset;
	uint16_t boneOffset;
	int16_t boneWeight;
};

struct $_3707
{
	int32_t main;
	char startupgametype[4];
	int32_t playerconnect;
	int32_t playerdisconnect;
	int32_t playerdamage;
	int32_t playerkilled;
	char votecalled[4];
	char playervote[4];
	char iNumGameTypes[4];
	uint8_t list[4224];
};

struct GfxSurface
{
	int32_t material;
	uint16_t lightmapIndex;
	int16_t sortGroup;
	$_3707 unnamed_field;
};

struct srfTriangles_t
{
	int32_t surfaceType;
	vec3_t bounds[2];
	int32_t firstVertex;
	uint16_t vertexCount;
	uint16_t indexCount;
	int32_t indices;
};

struct srfPoly_t
{
	int32_t surfaceType;
	int32_t material;
	uint16_t lmapIndex;
	uint16_t vertCount;
	int32_t verts;
};

struct PointLightPartition
{
	int32_t light;
	int32_t firstDrawSurf;
	uint32_t drawSurfCount;
};

struct GfxStaticModelInstance
{
	int32_t cullDist;
	vec3_t origin;
	char model[4];
	vec3_t mins;
	vec3_t maxs;
	vec3_t axis[3];
	int32_t scale;
	vec3_t baseLightingCoords;
};

struct GfxSceneDef
{
	uint32_t time;
	float floatTime;
	uint32_t entityCount;
	int32_t entities;
};

struct GfxScene
{
	uint32_t viewCount;
	GfxSceneDef def;
	uint32_t dlightCount;
	uint8_t dlights[1408];
	uint8_t dlightCulled[32];
	uint32_t drawSurfCount;
	int32_t drawSurfs;
	uint32_t polyCount;
	uint8_t sceneEnts[106392];
	uint32_t sceneEntMaterialCount;
	uint8_t sceneMaterials[16384];
};

struct trXSkin_t
{
	uint32_t materialHandles;
};

union $_3729
{
	int32_t verts;
	uint32_t blends;
};

struct $_3664
{
	vec3_t mins;
	vec3_t maxs;
	vec3_t outerSize;
	TraceExtents extents;
	uint32_t passEntityNum;
	uint32_t passOwnerNum;
	uint32_t contentmask;
};

struct $_3665
{
	vec3_t mins;
	vec3_t maxs;
	vec3_t outerSize;
	vec3_t start;
	vec3_t end;
	uint64_t passEntityNum;
	uint32_t contentmask;
};

struct $_3715
{
	uint32_t time;
	int32_t scale;
	uint32_t length;
	int32_t radius;
	vec3_t src;
	uint32_t size;
	int32_t rumbleScale;
};

struct GfxDebugPoly
{
	vec4_t color;
	int32_t firstVert;
	uint32_t vertCount;
};

struct trDebugString_t
{
	vec3_t xyz;
	vec4_t color;
	int32_t scale;
	char text[96];
};

struct trDebugLine_t
{
	vec3_t start;
	vec3_t end;
	vec4_t color;
	int32_t depthTest;
};

struct GfxDebugPlume
{
	vec3_t origin;
	vec4_t color;
	int32_t score;
	uint32_t startTime;
	int32_t duration;
};

struct GfxCmdHeader
{
	uint16_t id;
	uint16_t byteCount;
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

struct Font_s
{
	char name[4];
	int32_t pixelHeight;
	uint32_t glyphCount;
	int32_t material;
	int32_t glyphs;
};

struct Glyph
{
	int16_t letter;
	int8_t x0;
	int8_t y0;
	int8_t dx;
	int8_t pixelWidth;
	int8_t pixelHeight;
	char pad0[1];
	int32_t s0;
	int32_t t0;
	int32_t s1;
	int32_t t1;
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
	vec3_t origin;
	int32_t scale;
	int32_t bias;
};

struct GfxCmdDrawPoints
{
	int32_t header;
	uint16_t pointCount;
	uint16_t size;
	uint8_t verts[16];
};

struct GfxPointVertex
{
	vec3_t xyz;
	int32_t color;
};

struct GfxCmdDrawLines
{
	int32_t header;
	uint16_t lineCount;
	uint16_t width;
	uint8_t verts[32];
};

struct DebugGlobals
{
	int32_t verts;
	uint32_t vertCount;
	int32_t vertLimit;
	int32_t polys;
	uint32_t polyCount;
	int32_t polyLimit;
	char strings[4];
	char stringCount[4];
	char stringLimit[4];
	char externStrings[4];
	char externStringCount[4];
	char externMaxStringCount[4];
	int32_t lines;
	uint32_t lineCount;
	int32_t lineLimit;
	int32_t externLines;
	uint32_t externLineCount;
	uint32_t externMaxLineCount;
	int32_t plumes;
	uint32_t plumeCount;
	int32_t plumeLimit;
};

struct GfxCmdArray
{
	char cmds[196608];
	int32_t usedTotal;
	int32_t usedCritical;
	char lastCmd[4];
};

struct GfxFog
{
	uint32_t techniqueOffset;
	uint32_t startTime;
	uint32_t finishTime;
	int32_t color;
	int32_t fogStart;
	int32_t fogEnd;
	int32_t density;
	int8_t registered;
	int8_t drawSky;
	int8_t clearScreen;
};

struct GfxBackEndData
{
	uint32_t frameCount;
	uint32_t drawSurfCount;
	uint8_t drawSurfs[524288];
	uint32_t surfPos;
	uint8_t surfsBuffer[131072];
	uint32_t entityCount;
	uint8_t entities[949344];
	uint32_t polyCount;
	uint8_t polys[32768];
	uint32_t polyVertCount;
	uint8_t polyVerts[557056];
	int32_t skinnedCacheVb;
	uint32_t viewParmCount;
	uint8_t viewParms[8300];
	GfxFog fogSettings;
	GfxCmdArray commands;
	DebugGlobals debugGlobals;
};

union $_3714
{
	uint8_t dx7[12288];
	uint8_t dx9[32768];
};

struct SkinBuffers
{
	uint8_t matArrayBuf[8192];
	$_3714 verts;
};

struct r_vb_state_t
{
	int32_t used;
	int32_t total;
	void *buffer;
};

typedef enum
{
	FOG_OFFSET_NONE = 0,
	FOG_OFFSET_LINEAR = 1,
	FOG_OFFSET_EXP = 2,
	FOG_OFFSET_COUNT = 3
} GfxFogOffset;

struct DObjSkelMat_s
{
	vec3_t axis[4];
	uint8_t origin[16];
};

struct GfxSModelCachedVertexDx7
{
	vec3_t xyz;
	GfxColor color;
	vec2_t texCoord;
};

struct GfxSModelCachedVertex
{
	vec3_t xyz;
	vec3_t normal;
	int32_t color;
	vec2_t texCoord;
	int32_t baseLightingCoords;
	vec3_t binormal;
	vec3_t tangent;
};

struct GfxDebugFrameGlob
{
	char restoreCmdList[4];
	void *restoreFrontEndDataOut;
	int8_t restoreSkinnedCache;
	char pad0[3];
	uint8_t frontEndDataOut[2399596];
};

struct GfxPosTexVertex
{
	vec3_t xyz;
	vec2_t texCoord;
};

struct Image_MemUsage
{
	int32_t total;
	int32_t lightmap;
	char minspec[4];
};

struct trStatistics_t
{
	uint32_t c_indexes;
	uint32_t c_fxIndexes;
	uint32_t c_viewIndexes;
	uint32_t c_shadowIndexes;
	int32_t c_vertexes;
	int32_t c_batches;
	void *c_refents;
	int32_t dc;
	Image_MemUsage c_imageUsage;
};

struct refexport_t
{
	int32_t Shutdown;
	int32_t BeginRegistration;
	char RegisterModel[4];
	char RegisterInlineModel[4];
	int32_t RegisterMaterial;
	int32_t RegisterRawImage;
	int32_t Material_IsDefault;
	int32_t LoadWorld;
	int32_t GetWorldBounds;
	char FinishLoadingModels[4];
	int32_t SetIgnorePrecacheErrors;
	int32_t GetIgnorePrecacheErrors;
	char GetMinSpecImageMemory[4];
	char GetMaterialName[4];
	uint32_t GetMaterialSubimageCount;
	float IsMaterialRefractive;
	int32_t GetFarPlaneDist;
	int32_t EndRegistration;
	int32_t ClearScene;
	int32_t DefaultVertexFrames;
	int32_t AddPolyToScene;
	int32_t AddLightToScene;
	int32_t InterpretSunLightParseParams;
	int32_t ResetSunLightParseParams;
	int32_t SetCullDist;
	int32_t SetFog;
	int32_t SwitchFog;
	int32_t ArchiveFogState;
	int32_t ClearFogs;
	uint32_t SetSunLightOverride;
	uint32_t ResetSunLightOverride;
	int32_t RenderScene;
	int32_t BeginDelayedDrawing;
	int32_t EndDelayedDrawing;
	int32_t IssueDelayedDrawing;
	int32_t ClearFlares;
	int32_t SetMaterialColor;
	int32_t DrawStretchPic;
	int32_t DrawStretchPicRotate;
	int32_t DrawStretchRaw;
	int32_t DrawQuadPic;
	int32_t DrawSprite;
	int32_t BeginFrame;
	int32_t EndFrame;
	int32_t BeginDebugFrame;
	int32_t EndDebugFrame;
	int32_t EndView;
	int32_t DoneRenderingViews;
	int32_t SaveScreen;
	uint32_t BlendSavedScreen;
	int32_t ClearScreen;
	int32_t SetViewport;
	int32_t MarkFragments;
	char ModelBounds[4];
	int32_t TrackStatistics;
	int32_t PickMaterial;
	int32_t RegisterFont;
	int32_t ResetImageAllocations;
	int32_t FreeImageAllocations;
	int32_t BeginCubemapShot;
	int32_t EndCubemapShot;
	int32_t SaveCubemapShot;
	int32_t LightingFromCubemapShots;
	char LocateDebugStrings[4];
	int32_t LocateDebugLines;
	int32_t AddPlume;
	int32_t ShutdownDebug;
	int32_t UpdateColor;
	char NormalizedTextScale[4];
	char TextWidth[4];
	char TextHeight[4];
	char DrawText[4];
	char DrawTextInSpace[4];
	char ConsoleTextWidth[4];
	char DrawConsoleText[4];
	char DrawTextWithCursor[4];
	int32_t DObjGetSurfMaterials;
	int32_t DObjReplaceMaterial;
	int32_t ParseSunLight;
	int32_t Material_Duplicate;
	int32_t DuplicateFont;
	int8_t XModelAllowReadSurface;
	char pad0[3];
	int32_t SyncRenderThread;
	char AbortRenderCommands[4];
	int32_t IsGpuFenceFinished;
	int32_t SyncGpu;
	int32_t GpuWaited;
	int32_t SetLodOrigin;
};

struct refimport_t
{
	int32_t Printf;
	int32_t Error;
	int32_t Milliseconds;
	int32_t Hunk_AllocInternal;
	int32_t Hunk_AllocateTempMemoryInternal;
	int32_t Z_MallocInternal;
	int32_t Z_FreeInternal;
	int32_t Hunk_AllocAlignInternal;
	int32_t Z_VirtualReserveInternal;
	int32_t Z_VirtualCommitInternal;
	int32_t Z_VirtualDecommitInternal;
	int32_t Z_VirtualFreeInternal;
	int32_t Hunk_FreeTempMemory;
	int32_t Hunk_ClearTempMemory;
	uint32_t Hunk_HideTempMemory;
	int32_t Hunk_ShowTempMemory;
	int32_t Hunk_AllocateTempMemoryHighInternal;
	int32_t Hunk_ClearTempMemoryHigh;
	int32_t Sys_DirectXFatalError;
	int32_t Sys_ShowSplashWindow;
	uint32_t Sys_HideSplashWindow;
	int32_t Sys_LoadingKeepAlive;
	int32_t Dvar_RegisterBool;
	int32_t Dvar_RegisterInt;
	float Dvar_RegisterFloat;
	char Dvar_RegisterString[4];
	uint32_t Dvar_RegisterEnum;
	int32_t Dvar_RegisterColor;
	int32_t Dvar_RegisterVec2;
	int32_t Dvar_RegisterVec3;
	int32_t Dvar_RegisterVec4;
	int32_t Dvar_UnregisterSystem;
	int32_t Dvar_ChangeResetValue;
	int32_t Dvar_IsAtDefaultValue;
	int32_t Dvar_ClearModified;
	int32_t Dvar_SetModified;
	uint32_t Dvar_UpdateEnumDomain;
	int32_t Dvar_SetBool;
	int32_t Dvar_SetInt;
	float Dvar_SetFloat;
	char Dvar_SetString[4];
	int32_t Dvar_SetColor;
	int32_t Dvar_SetVec2;
	int32_t Dvar_SetVec3;
	int32_t Dvar_SetVec4;
	char Dvar_SetFromString[4];
	char Dvar_SetBoolByName[4];
	char Dvar_SetIntByName[4];
	float Dvar_SetFloatByName;
	char Dvar_SetStringByName[4];
	char Dvar_SetColorByName[4];
	char Dvar_SetVec2ByName[4];
	char Dvar_SetVec3ByName[4];
	char Dvar_SetVec4ByName[4];
	char Dvar_SetFromStringByName[4];
	int32_t Dvar_GetBool;
	int32_t Dvar_GetInt;
	float Dvar_GetFloat;
	char Dvar_GetString[4];
	char Dvar_GetVariantString[4];
	char Dvar_EnumToString[4];
	int32_t Dvar_Reset;
	char Cmd_AddCommand[4];
	char Cmd_RemoveCommand[4];
	char Cmd_Argc[4];
	char Cmd_Argv[4];
	char Cbuf_ExecuteText[4];
	void *Com_SaveDvarsToBuffer;
	void *Com_LoadDvarsFromBuffer;
	int32_t Com_GetBsp;
	char SEH_ReadCharFromString[4];
	int32_t CL_UpdateDebugData;
	int32_t CL_FlushDebugData;
	int32_t StatMon_Warning;
	int32_t FS_ReadFile;
	int32_t FS_FreeFile;
	int32_t FS_FOpenFileRead;
	int32_t FS_ListFiles;
	int32_t FS_FreeFileList;
	int32_t FS_FileExists;
	int32_t FS_WriteFile;
	int32_t FS_FOpenFileByMode;
	int32_t FS_FCloseFile;
	int32_t FS_Read;
	int32_t FS_Write;
	int32_t CM_SaveLump;
	int32_t CM_BoxTrace;
	int32_t CM_BoxSightTrace;
	float CM_RayTriangleIntersect;
	char XModelPrecache[4];
	char XModelGetSurfaces[4];
	char XModelBad[4];
	uint32_t Hunk_OverrideDataForFile;
	char XModelGetNumLods[4];
	char XModelSetTestLods[4];
	char XModelGetLodForDist[4];
	char XModelGetLodOutDist[4];
	char XModelGetSurfaceName[4];
	char XModelGetName[4];
	char XModelGetFlags[4];
	char XModelNumBones[4];
	char XModelGetSkins[4];
	char XModelGetMemUsage[4];
	char XModelGetLodName[4];
	char XModelGetBasePose[4];
	char XModelGetBasePoseBone[4];
	int32_t DObjBad;
	uint32_t DB_EnumXAssets;
	int32_t DObjGetBounds;
	int32_t DObjGetSurface;
	char DObjGetNumModels[4];
	uint32_t DObjGetNumSurfaces;
	int32_t DObjGetSurfaces;
	int32_t DObjGetPartBits;
	int32_t DObjGetRotTransArray;
	int32_t DObjSkelAreBonesUpToDate;
	uint32_t DObjGetMatOffset;
	char DObjGetModel[4];
	char DObjGetSurfaceName[4];
	int32_t DObjCreate;
	uint32_t DObjGetAllocSkelSize;
	int32_t DObjCreateSkel;
	int32_t DObjCalcAnim;
	int32_t DObjCalcSkel;
	uint32_t DObjNumBones;
	char DObjGetBoneInfo[4];
	int32_t DObjGetLodForDist;
	int32_t DObjGetLodOutDist;
	int32_t DObjCompleteHierarchyBits;
	char DObjSetModel[4];
	int32_t CIN_UploadCinematic;
	int32_t CIN_PlayCinematic;
	int32_t CIN_RunCinematic;
	uint32_t CG_DObjCalcPose;
	char CL_GetHudMsgIconMaterialName[4];
};

struct GfxGammaRamp
{
	uint8_t entries[512];
};

struct GfxWindowParms
{
	int32_t hwnd;
	int32_t hz;
	int8_t fullscreen;
	char pad0[3];
	int32_t x;
	int32_t y;
	uint32_t width;
	int32_t height;
	uint32_t tileCount;
	int32_t aaSamples;
};

struct vidConfig_t
{
	uint32_t width;
	int32_t height;
	int32_t displayFrequency;
	int32_t isFullscreen;
	char aspectRatioWindow[4];
	char aspectRatioPixel[4];
	char maxTextureSize[4];
	char maxTextureMaps[4];
	char maxTextureCoords[4];
	int32_t maxActiveLights;
	int8_t deviceSupportsGamma;
};

struct DxGlobals
{
	int32_t hinst;
	int32_t d3d9;
	int32_t device;
	uint32_t adapterIndex;
	void *backBufferFormat;
	uint32_t displayModeCount;
	uint8_t displayModes[4096];
	char resolutionNameTable[1028];
	char refreshRateNameTable[1028];
	char modeText[5120];
	int32_t gpuSync;
	int32_t multiSampleType;
	int32_t multiSampleQuality;
	int32_t sunSpriteSamples;
	uint8_t renderTargets[260];
	int32_t singleSampleDepthStencilSurface;
	int16_t cubemapShotRes;
	int16_t cubemapShotPixelBorder;
	int8_t deviceLost;
	int8_t inScene;
	uint16_t feedbackWidth;
	int16_t feedbackHeight;
	char pad0[2];
	uint32_t targetWindowIndex;
	uint32_t windowCount;
	uint8_t windows[16];
	int32_t flushGpuQuery;
	int32_t gpuSyncDelay;
	int32_t gpuSyncAlreadyWaited;
	int8_t flushGpuQueryIssued;
	char pad1[3];
	int32_t anisotropy;
	int32_t maxAnisotropy;
	int32_t maxClipPlanes;
	int8_t stencilTwoSided;
	int8_t stencilWrap;
	int8_t slopeScaleDepthBias;
	int8_t canMipCubemaps;
	uint8_t hasBlendOp;
	uint8_t hasSeparateAlphaBlend;
	int8_t hasTransparencyMsaa;
	char pad2[1];
	vec3_t dynamicIndexBufferPool;
	uint32_t dynamicIndexBuffer;
	uint8_t skinnedCacheVbPool[24];
	vec3_t dynamicVertexBufferPool;
	void *dynamicVertexBuffer;
	void *particleCloudVertexBuffer;
	uint32_t particleCloudIndexBuffer;
	int32_t skinnedCacheLockAddr;
	char smodelCacheVb[4];
	char smodelCacheIndices[4];
	void *dynamicBufferFrame;
	void *tempSkinBuf;
	uint32_t tempSkinPos;
};

struct GfxRenderTarget
{
	int32_t image;
	int32_t colorSurface;
	int32_t depthStencilSurface;
	uint32_t width;
	int32_t height;
};

struct GfxWindowTarget
{
	int32_t hwnd;
	int32_t swapChain;
	uint32_t width;
	int32_t height;
};

struct r_ib_state_t
{
	int32_t used;
	int32_t total;
	void *buffer;
};

struct r_global_permanent_t
{
	int32_t materialLoaded;
	uint32_t materialCount;
	uint8_t sortedMaterials[4096];
	int32_t whiteImage;
	int32_t blackImage;
	uint32_t identityNormalMapImage;
	char specularityImage[4];
	int32_t lightmapWeightsImage;
	uint64_t lightGridWeightsImage;
	int32_t outdoorImage;
	int32_t dlightDef;
	int32_t defaultMaterial;
	int32_t rawMaterial;
	int32_t stencilPlaneMaterial;
	int32_t whiteMaterial;
	int32_t additiveMaterial;
	int32_t pointMaterial;
	int32_t lineMaterial;
	int32_t clearAlphaStencilMaterial;
	int32_t shadowClearMaterial;
	int32_t shadowCookieOverlayMaterial;
	int32_t shadowCookieBlurMaterial;
	int32_t glareBlindMaterial;
	int32_t normalFillMaterial;
	uint32_t alphaBlendFillMaterial;
	int32_t alphaTestPassFillMaterial;
	int32_t alphaTestFailFillMaterial;
	int32_t additiveFillMaterial;
	int32_t depthOnlyFillMaterial;
	uint32_t stencilOneSideKeepFillMaterial;
	uint32_t stencilOneSideRejectFillMaterial;
	uint32_t stencilTwoSideKeepFillMaterial;
	uint32_t stencilTwoSideRejectFillMaterial;
	int32_t phongBumpFillMaterial;
	char phongBumpSpecFillMaterial[4];
	int32_t colorChannelMixerMaterial;
	int32_t frameColorDebugMaterial;
	int32_t frameAlphaDebugMaterial;
	int32_t rawImage;
	int32_t world;
	float sunHalfAngleImage;
	int32_t waterColorImage;
	int32_t feedbackReplaceMaterial;
	uint32_t feedbackBlendMaterial;
	uint8_t symmetricFilterMaterial[32];
	int32_t shellShockMaterial;
	int32_t glowSetupMaterial;
	int32_t glowApplySkyBleedMaterial;
	int32_t glowApplyBloomMaterial;
	uint32_t savedScreenTime;
	vec3_t rawTexdef;
};

struct sunflare_t
{
	int8_t hasValidData;
	char pad0[3];
	int32_t spriteMaterial;
	int32_t flareMaterial;
	uint32_t spriteSize;
	uint32_t flareMinSize;
	int32_t flareMinDot;
	uint32_t flareMaxSize;
	int32_t flareMaxDot;
	int32_t flareMaxAlpha;
	uint32_t flareFadeInTime;
	uint32_t flareFadeOutTime;
	int32_t blindMinDot;
	int32_t blindMaxDot;
	int32_t blindMaxDarken;
	uint32_t blindFadeInTime;
	uint32_t blindFadeOutTime;
	int32_t glareMinDot;
	int32_t glareMaxDot;
	int32_t glareMaxLighten;
	uint32_t glareFadeInTime;
	uint32_t glareFadeOutTime;
	vec3_t sunFxPosition;
};

struct GfxWorldVertexData
{
	int32_t vertices;
	int32_t worldVb;
};

struct GfxLightGrid
{
	uint32_t pointCount;
	int32_t points;
	uint32_t colorCount;
	int32_t colors;
};

struct SunLightParseParams
{
	char name[64];
	int32_t ambientScale;
	vec3_t ambientColor;
	float diffuseFraction;
	int32_t sunLight;
	vec3_t sunColor;
	vec3_t diffuseColor;
	int8_t diffuseColorHasBeenSet;
	char pad0[3];
	vec3_t angles;
};

struct GfxWorld
{
	char name[4];
	char baseName[4];
	uint32_t nodeCount;
	int32_t nodes;
	uint32_t surfaceCount;
	int32_t surfaces;
	uint32_t skySurfCount;
	int32_t skyStartSurfs;
	int32_t skyImage;
	int8_t skySamplerState;
	char pad0[3];
	uint32_t vertexCount;
	GfxWorldVertexData vd;
	SunLightParseParams sunParse;
	GfxLight sunLight;
	vec3_t sunColorFromBsp;
	uint32_t cullGroupCount;
	int32_t cullGroups;
	char smodelCount[4];
	char smodelInsts[4];
	uint32_t cellCount;
	int32_t cells;
	uint32_t lightmapCount;
	int32_t lightmaps;
	char smodelLightingImage[4];
	char smodelLightingLookupScale[12];
	GfxLightGrid lightGrid;
	char smodelLightingColorTable[4];
	char smodelLightingSunVisTable[4];
	char modelCount[4];
	char models[4];
	vec3_t mins;
	vec3_t maxs;
	int32_t checksum;
	uint32_t materialMemoryCount;
	int32_t materialMemory;
	sunflare_t sun;
	matrix4_t outdoorLookupMatrix;
	int32_t outdoorImage;
};

struct mnode_node_t
{
	int32_t plane;
	uint64_t children;
};

struct mnode_leaf_t
{
	int32_t cluster;
};

union mnode_info_t
{
	mnode_node_t node;
	mnode_leaf_t leaf;
};

struct mnode_t
{
	int32_t contents;
	int32_t parent;
	uint32_t cellIndex;
	mnode_info_t u;
};

struct GfxCullGroup
{
	vec3_t mins;
	vec3_t maxs;
	uint32_t surfaceCount;
	uint32_t startSurfIndex;
};

struct GfxCellWritable
{
	uint32_t markCount;
};

struct GfxCell
{
	GfxCellWritable writable;
	vec3_t mins;
	vec3_t maxs;
	int32_t aabbTree;
	uint32_t portalCount;
	int32_t portals;
	uint32_t cullGroupCount;
	int32_t cullGroups;
	uint32_t occluderCount;
	int32_t occluders;
	char modelRefs[4];
};

struct MaterialMemory
{
	int32_t material;
	int32_t memory;
};

struct GfxLightGridPoint
{
	int32_t xyzHighBits;
	int8_t xyzLowBitsAndSunVisible;
	int8_t needsTrace;
	uint16_t colorsIndex;
};

struct GfxLightGridColors
{
	uint8_t rgb[24];
};

struct GfxAabbTree
{
	vec3_t mins;
	vec3_t maxs;
	uint32_t surfaceCount;
	uint32_t startSurfIndex;
	char staticModelCount[4];
	char staticModels[4];
	uint32_t childCount;
	int32_t children;
};

union DpvsPlaneInfo
{
	int8_t frontal;
	int8_t ignoreStackLevel;
};

struct DpvsPlane
{
	uint8_t coeffs[16];
	uint8_t side[3];
	DpvsPlaneInfo u;
};

struct GfxPortalWritable
{
	int8_t isQueued;
	int8_t isAncestor;
	char pad0[2];
	int32_t queuedParent;
};

struct GfxPortal
{
	GfxPortalWritable writable;
	DpvsPlane plane;
	int32_t cell;
	int32_t vertices;
	uint8_t vertexCount;
	uint8_t hullPointCount;
	char pad0[2];
	int32_t hullPoints;
	uint8_t hullAxis[24];
};

struct GfxSceneModelCellRef
{
	uint32_t entIndex;
	vec3_t mins;
	vec3_t maxs;
	int32_t next;
};

struct GfxOccluder
{
	uint32_t planeCount;
	int32_t planes;
	uint32_t edgeCount;
	int32_t edges;
	uint32_t vertexCount;
	int32_t vertices;
	int32_t ignoreStackLevel;
	uint32_t viewPlaneCount;
	int32_t viewPlanes;
};

struct GfxOccluderEdge
{
	uint64_t plane;
	uint64_t vertex;
};

struct r_globals_t
{
	int8_t registered;
	int8_t forbidDelayLoadImages;
	int8_t ignorePrecacheErrors;
	char pad0[1];
	vec3_t viewOrg;
	vec3_t viewDir;
	uint32_t frameCountInternal;
	uint32_t markCount;
	int32_t totalImageMemory;
	uint8_t materialHashTable[4096];
	uint32_t sceneWaterMapSetupsCount;
	uint8_t sceneWaterMapSetups[1088];
	uint8_t fogSettings[160];
	uint32_t fogIndex;
	uint8_t sinTable[4096];
	uint8_t fftTrigTable[2048];
	uint8_t fftBitswap[1024];
	char modelDObj[4];
	char modelDObjBuf[100];
	int32_t stats;
	GfxLodParms lodParms;
	int32_t debugViewParms;
	char smodelDyncs[4];
	int32_t surfaces;
	int32_t cullGroups;
};

struct GfxStaticModelDynamic
{
	uint32_t viewCount;
	int32_t staticSurfs;
};

struct GfxSurfaceDynamic
{
	uint32_t viewCount;
};

struct GfxCullGroupDynamic
{
	uint32_t viewCount;
};

struct GfxStaticSurface
{
	uint8_t cachedLods[16];
};

struct GfxStaticModelSurfaceCached
{
	uint32_t baseVertIndex;
	char smodelIndex[4];
	int32_t xsurf;
	int32_t surface;
};

struct DxTextureStageEnums
{
	int32_t op;
	vec3_t arg;
};

struct DxTextureOpDecode
{
	uint32_t enumerant;
	int32_t usedArgs;
};

struct GfxCodeMatrix
{
	uint8_t matrix[256];
	uint32_t valid;
};

struct GfxCodeMatrices
{
	int32_t worldScale;
	char pad0[12];
	GfxCodeMatrix world;
	uint8_t normalizedWorld[272];
	uint8_t view[272];
	uint8_t projection[272];
	uint8_t worldView[272];
	uint8_t normalizedWorldView[272];
	uint8_t viewProjection[272];
	uint8_t worldViewProjection[272];
	uint8_t normalizedWorldViewProjection[272];
	uint8_t shadowLookupMatrix[272];
	uint8_t lightGridLookupMatrix[272];
	uint8_t worldOutdoorLookup[272];
	uint8_t OGLworldViewProjection[272];
};

struct GfxViewport
{
	int32_t x;
	int32_t y;
	uint32_t width;
	int32_t height;
};

struct jpeg_destination_mgr
{
	int32_t next_output_byte;
	void *free_in_buffer;
	int32_t init_destination;
	void *empty_output_buffer;
	int32_t term_destination;
};

struct $_3726
{
	jpeg_destination_mgr pub;
	int32_t outfile;
	uint32_t size;
};

struct DxState
{
	uint8_t vertexShaderConsts[4096];
	uint8_t pixelShaderConsts[4096];
	uint64_t refStateBits;
	uint64_t activeStateBits;
	void *stencilRefValue;
	uint8_t refColorStageBits[32];
	uint8_t refAlphaStageBits[32];
	uint8_t activeColorStageBits[32];
	uint8_t activeAlphaStageBits[32];
	int8_t gridLighting;
	int16_t genTexCoords;
	char pad0[1];
	uint32_t renderTargetId;
	uint32_t renderTargetWidth;
	int32_t renderTargetHeight;
	int32_t viewportBehavior;
	int32_t renderTargetSurface;
	int32_t depthStencilSurface;
	uint8_t viewport[24];
	int8_t viewportIsNull;
	char pad1[3];
	uint32_t indexBuffer;
	vec3_t streams;
	uint32_t indexBufferDeselecting;
	void *vertexBufferDeselecting;
	uint8_t samplerState[16];
	uint8_t samplerImage[64];
	char textureColorArg[4];
	int32_t pixelShader;
	int32_t vertexShader;
	int32_t vertexDecl;
	int32_t fvf;
	int8_t alphaRef;
	char pad2[3];
	float textureFactor;
	int32_t ambientColor;
	uint32_t clipPlaneCount;
	$_3726 fog;
};

typedef enum
{
	GFX_USE_VIEWPORT_FOR_VIEW = 0,
	GFX_USE_VIEWPORT_FULL = 1
} GfxViewportBehavior;

typedef enum
{
	D3DFOG_NONE = 0,
	D3DFOG_EXP = 1,
	D3DFOG_EXP2 = 2,
	D3DFOG_LINEAR = 3,
	D3DFOG_FORCE_DWORD = 2147483647
} D3DFOGMODE;

struct DxStencilDecode
{
	int32_t shift;
	int32_t renderState;
};

union XAssetHeader
{
	int32_t parts;
	char model[4];
	int32_t material;
	int32_t image;
	char sound[4];
	int32_t sndCurve;
	int32_t clipMap;
	int32_t world;
	int32_t lightDef;
	int32_t font;
	int32_t menuList;
	int32_t menu;
	int32_t localize;
	int32_t weapon;
	char sndDriverGlobals[4];
	int32_t fx;
	int32_t impactFx;
	int32_t rawfile;
	int32_t data;
};

typedef enum
{
	GFX_LOCK_BEGIN_FRAME = 0,
	GFX_LOCK_RESUME_FRAME = 1
} GfxLockType;

struct $_3720
{
	uint32_t fadeTime;
	uint32_t effectTime;
};

struct GfxModelSkinnedSurface
{
	GfxModelSurface surf;
	uint32_t skinnedCachedOffset;
	$_3720 skinnedVert;
};

struct GfxVertexDx7
{
	vec3_t xyz;
	vec3_t normal;
	GfxColor color;
	vec2_t texCoord;
};

struct GfxVertex
{
	uint8_t xyzw[16];
	vec3_t normal;
	int32_t color;
	vec2_t texCoord;
	vec3_t binormal;
	vec3_t tangent;
};

struct GfxModelRigidSurface
{
	uint64_t surf;
	vec3_t boneAxis[4];
};

struct SkinXModelCmd
{
	int32_t surfs;
	int32_t e;
	int32_t mat;
	uint8_t surfacePartBits[16];
	uint8_t surfCount;
	uint8_t boneCount;
	uint8_t matOffset[64];
};

struct SkinRigidXModelCmd
{
	int32_t surfs;
	uint32_t surfCount;
	int32_t e;
	uint8_t mat[32];
};

struct GfxStaticModelCachedSurface
{
	uint64_t surf;
	int32_t surface;
	int32_t ent;
};

struct $_3732
{
	int32_t history;
	uint32_t count;
};

union $_3734
{
	int32_t v;
	int32_t w;
};

struct stream_source_info_t
{
	int8_t Stream;
	int8_t Offset;
	int8_t Type;
};

struct stream_dest_info_t
{
	int8_t Usage;
	uint8_t UsageIndex;
};

typedef enum
{
	MTL_VERTEX_SHADER = 0,
	MTL_PIXEL_SHADER = 1
} MaterialShaderType;

struct $_3752
{
	uint32_t vertexDeclCount;
	uint8_t vertexDeclHashTable[768];
	uint32_t techniqueSetCount;
	uint8_t techniqueSetHashTable[4096];
	uint32_t techniqueCount;
	uint8_t techniqueHashTable[4096];
	uint32_t literalCount;
	uint8_t literalTable[256];
	uint32_t stateMapCount;
	uint8_t stateMapHashTable[128];
	char stringCount[4];
	char stringHashTable[256];
	uint32_t shaderCount;
	uint8_t shaderHashTable[1024];
};

struct BuiltInMaterialTable
{
	char name[4];
	int32_t material;
};

struct GfxRenderCommandExecState
{
	char cmd[4];
	uint32_t stackPos;
	char retCmd[8];
};

struct GfxCmdCall
{
	GfxCmdHeader header;
	char subCmd[4];
};

struct GfxCmdSetClipPlanes
{
	int32_t header;
	uint32_t clipPlaneCount;
	vec4_t clipPlanes;
};

struct GfxCmdStretchRaw
{
	int32_t header;
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
	int32_t cols;
	int32_t rows;
	int32_t data;
	int32_t client;
	int32_t dirty;
};

struct GfxCmdClearScreen
{
	int32_t header;
	int8_t whichToClear;
	int8_t stencil;
	char pad0[2];
	int32_t depth;
	vec4_t color;
};

struct GfxCmdSetMaterialColor
{
	int32_t header;
	vec4_t color;
};

struct GfxCmdSetLightProperties
{
	int32_t header;
	uint32_t lightIndex;
	vec4_t position;
	uint8_t ambient[16];
	vec4_t color;
	char specular[16];
	int32_t lightDef;
};

struct GfxCmdSetStencilRefValue
{
	int32_t header;
	void *refValue;
};

struct GfxCmdSetShadowCookie
{
	int32_t header;
	matrix4_t lookupMatrix;
	int32_t fade;
};

struct GfxCmdBeginView
{
	int32_t header;
	GfxSceneDef sceneDef;
	int32_t viewParms;
	GfxLodParms lodParms;
	uint32_t viewCount;
};

struct GfxCmdSetViewport
{
	int32_t header;
	vec4_t viewport;
};

struct GfxCmdSetRenderTarget
{
	int32_t header;
	uint32_t renderTargetId;
};

typedef enum
{
	GFX_DRAW_SURFS_ITER_FORWARD = 0,
	GFX_DRAW_SURFS_ITER_BACKWARD = 1
} GfxDrawSurfOrder;

struct GfxCmdDrawSurfs
{
	int32_t header;
	int32_t order;
	int32_t drawSurfs;
	uint32_t drawSurfCount;
	int32_t techType;
};

struct GfxCmdDrawSunPostEffects
{
	int32_t header;
	uint32_t viewIndex;
};

struct GfxCmdDrawTriangles
{
	int32_t header;
	int32_t material;
	int32_t techType;
	uint16_t indexCount;
	uint16_t vertexCount;
};

struct GfxCmdDrawSprite
{
	int32_t header;
	int32_t material;
	int32_t rgbaColor;
	vec3_t pos;
	int32_t radius;
	int32_t minScreenRadius;
	uint32_t renderFxFlags;
};

struct GfxCmdDrawTextInSpace
{
	int32_t header;
	vec3_t org;
	int32_t font;
	vec3_t xPixelStep;
	vec3_t yPixelStep;
	int32_t color;
	char text[4];
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
	int32_t header;
	int32_t material;
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
	int32_t s0;
	int32_t t0;
	int32_t s1;
	int32_t t1;
	int32_t color;
};

struct GfxCmdDrawFullScreenColoredQuad
{
	int32_t header;
	int32_t material;
	int32_t s0;
	int32_t t0;
	int32_t s1;
	int32_t t1;
	int32_t color;
};

struct GfxCmdBlendSavedScreen
{
	int32_t header;
	int32_t fadeMsec;
	int32_t material;
};

struct GfxCmdDrawText
{
	int32_t header;
	int32_t x;
	int32_t y;
	int32_t font;
	int32_t xScale;
	int32_t yScale;
	int32_t color;
	int32_t style;
	uint32_t cursorPos;
	int8_t cursor;
	char pad0[3];
	int32_t maxChars;
	char text[3];
};

struct GfxCmdApplyLatePostEffects
{
	int32_t header;
	int32_t blurRadius;
};

struct GfxCmdStretchPicRotate
{
	int32_t header;
	int32_t material;
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
	int32_t s0;
	int32_t t0;
	int32_t s1;
	int32_t t1;
	int32_t color;
	int32_t rotation;
};

struct GfxCmdDrawQuadPic
{
	int32_t header;
	int32_t material;
	uint8_t verts[32];
	int32_t color;
};

struct GfxCmdStencilPlanes
{
	int32_t header;
	int32_t nearDist;
	uint32_t planeCount;
	int32_t planeDists;
};

struct $_3718
{
	uint16_t entnum;
	uint16_t otherEntnum;
	uint32_t useCount;
	uint32_t otherUseCount;
};

struct materialCommands_t
{
	$_3718 verts;
	int32_t indices;
	int32_t optimizedIndices;
	int32_t optimizedVertexSource;
	int32_t material;
	int32_t techType;
	uint32_t lmapIndex;
	uint32_t materialTime;
	int32_t declType;
	uint32_t indexCount;
	uint32_t vertexCount;
	int32_t firstVertex;
	int32_t lastVertex;
	uint32_t optimizedIndexCount;
	uint32_t optimizedVertexCount;
	int32_t firstOptimizedVertex;
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

struct $_3719
{
	uint32_t fadeTime;
	int32_t kickRate;
	int32_t kickRadius;
};

struct GfxWorldVertexDx7
{
	vec3_t xyz;
	int32_t color;
	vec2_t texCoord;
	vec2_t lmapCoord;
};

struct r_backEndGlobals_t
{
	uint8_t codeConsts[944];
	uint32_t frameCount;
	uint32_t viewCount;
	uint8_t sceneDef[16];
	int32_t viewParms;
	uint8_t lodParms[20];
	vec4_t sceneViewport;
	matrix4_t viewProjectionMatrix;
	uint32_t tileIndex;
	uint32_t tileCount;
	uint32_t width;
	int32_t height;
	int32_t currentEntity;
	int32_t currentEntityLighting;
	uint8_t worldEntity[116];
	int8_t viewportIsDirty;
	int8_t projection2D;
	int8_t defaultSamplerState;
	char pad0[1];
	int32_t color_axis;
	int32_t color_allies;
	int32_t fogColor;
	uint32_t glowIndexFirst;
	uint32_t glowCount;
	uint64_t glowImage;
	int32_t texScrollAmountDx7;
	uint8_t codeMatrixStack[10656];
	int32_t codeMatrixStackLevel;
	uint32_t resolvedPostSunTarget;
	int32_t resolvedSceneTarget;
	int32_t currentFeedbackImage;
	uint8_t light[136];
	uint8_t entityLighting[212784];
	matrix4_t shadowLookupMatrix;
	int32_t debugFont;
};

struct GfxEntityLighting
{
	uint32_t viewCount;
	int32_t sunVisibility;
	uint8_t colorForDir[96];
};

struct GfxBackEndLightSettings
{
	vec4_t position;
	uint8_t ambient[16];
	vec4_t color;
	char specular[16];
	int32_t def;
};

struct SunFlareDynamic
{
	int32_t flareIntensity;
	int32_t currentBlind;
	int32_t currentGlare;
	uint32_t lastTime;
	int8_t error;
	char pad0[3];
	int32_t cumulVisibility;
	int32_t lastVisibility;
	int32_t lastDot;
	uint32_t hitNum;
	uint64_t sunQuery;
	int16_t sunQueryIssued;
};

struct static_model_tree_list_t
{
	int32_t prev;
	int32_t next;
};

struct static_model_tree_t
{
	static_model_tree_list_t usedlist;
	uint32_t frameCount;
	uint8_t nodes[124];
	uint8_t leafs[256];
};

struct static_model_node_t
{
	int16_t usedVerts;
	int8_t inuse;
	int8_t reserved;
};

struct static_model_node_list_t
{
	int32_t prev;
	int32_t next;
};

union static_model_leaf_t
{
	uint8_t surf[16];
	static_model_node_list_t freenode;
};

struct SkinStaticModelCachedCmd
{
	int32_t cached;
	char smodelIndex[4];
	int32_t material;
};

struct static_model_cache_t
{
	uint8_t trees[50176];
	uint8_t freelist[40];
	uint64_t usedlist;
	$_3719 stats;
};

struct GfxBspLoad
{
	int32_t header;
	int32_t fileBase;
	uint32_t fileSize;
	int32_t materials;
	uint32_t materialCount;
	char lmapMergeInfo[640];
};

struct r_lightmapMerge_t
{
	uint16_t index;
	char pad0[2];
	uint64_t shift;
	uint64_t scale;
};

struct dnode_t
{
	uint32_t planeNum;
	uint64_t children;
	vec3_t mins;
	vec3_t maxs;
};

struct dleaf_t
{
	int32_t cluster;
	int32_t area;
	int32_t firstLeafSurface;
	uint32_t numLeafSurfaces;
	int32_t firstLeafBrush;
	uint32_t numLeafBrushes;
	uint32_t cellNum;
	uint32_t firstLightIndex;
	uint32_t numLights;
};

struct DiskGfxPortal
{
	uint32_t planeIndex;
	uint32_t cellIndex;
	int32_t firstPortalVertex;
	uint32_t portalVertexCount;
};

struct DiskGfxCell
{
	vec3_t mins;
	vec3_t maxs;
	uint32_t aabbTreeIndex;
	int32_t firstPortal;
	uint32_t portalCount;
	int32_t firstCullGroup;
	uint32_t cullGroupCount;
	int32_t firstOccluder;
	uint32_t occluderCount;
};

struct DiskGfxAabbTree
{
	int32_t firstSurface;
	uint32_t surfaceCount;
	uint32_t childCount;
};

struct DiskGfxOccluder
{
	int32_t firstPlane;
	uint16_t planeCount;
	uint16_t edgeCount;
	int32_t firstEdge;
	int32_t firstPortalVertex;
	uint16_t portalVertexCount;
};

struct DiskGfxOccluderEdge
{
	uint16_t planeIndex;
	uint16_t vertexIndex;
};

struct DiskGfxCullGroup
{
	vec3_t mins;
	vec3_t maxs;
	int32_t firstSurface;
	uint32_t surfaceCount;
};

struct DiskTriangleSoup
{
	uint16_t materialIndex;
	uint16_t lightmapIndex;
	int32_t firstVertex;
	uint16_t vertexCount;
	uint16_t indexCount;
	uint32_t firstIndex;
};

struct DiskGfxVertex
{
	vec3_t xyz;
	vec3_t normal;
	int32_t color;
	vec2_t texCoord;
	vec2_t lmapCoord;
	vec3_t tangent;
	vec3_t binormal;
};

struct r_lightmapGroup_t
{
	uint32_t wideCount;
	uint32_t highCount;
};

struct dmodel_t
{
	vec3_t mins;
	vec3_t maxs;
	float firstTriangle;
	float numTriangles;
	int32_t firstSurface;
	uint32_t numSurfaces;
	int32_t firstBrush;
	uint32_t numBrushes;
};

struct r_globals_load_t
{
	int32_t occluderIndices;
	int32_t cullGroupIndices;
	int32_t occluders;
	int32_t portalVerts;
	int32_t aabbTrees;
	uint32_t aabbTreeCount;
};

struct ImageList
{
	uint32_t count;
	uint8_t image[8192];
};

struct $_3753
{
	uint8_t imageHashTable[8192];
	int32_t picmip;
	int32_t picmipBump;
	char picmipSpec[4];
	uint64_t totalMemory;
};

typedef enum
{
	CUBEMAPSHOT_NONE = 0,
	CUBEMAPSHOT_UP = 1,
	CUBEMAPSHOT_DOWN = 2,
	CUBEMAPSHOT_LEFT = 3,
	CUBEMAPSHOT_RIGHT = 4,
	CUBEMAPSHOT_FRONT = 5,
	CUBEMAPSHOT_BACK = 6,
	CUBEMAPSHOT_COUNT = 7
} CubemapShot;

typedef enum
{
	R_SCREENSHOT_JPG = 0,
	R_SCREENSHOT_TGA = 1
} GfxScreenshotType;

typedef enum
{
	RENDERTARGET_USAGE_RENDER = 0,
	RENDERTARGET_USAGE_TEXTURE = 1,
	RENDERTARGET_USAGE_READBACK = 2
} RenderTargetUsage;

struct $_3637
{
	int32_t xyzHighBits;
	int8_t xyzLowBitsAndSunVisible;
	int8_t needsTrace;
	uint16_t colorsIndex;
};

struct lightGlob_type
{
	uint32_t defCount;
	uint8_t defs[256];
};

typedef enum
{
	R_DRAWGROUP_GLUE_ISSUE = 0,
	R_DRAWGROUP_GLUE_SKIP = 1
} GfxDrawGroupGlueBehavior;

typedef enum
{
	R_DRAWGROUP_DEPTH_PREPASS = 0,
	R_DRAWGROUP_SHADOW_COOKIE = 1,
	R_DRAWGROUP_WORLD_SUN = 2,
	R_DRAWGROUP_WORLD_REMAINDER = 3,
	R_DRAWGROUP_POST_AA = 4,
	R_DRAWGROUP_COUNT = 5
} GfxDrawGroupType;

struct GfxDrawGroupCommands
{
	int8_t isIssuingGlue;
	char pad0[3];
	int32_t begin;
	uint8_t perView[16];
	int32_t end;
};

typedef enum
{
	DPVS_DONT_CLIP_CHILDREN = 0,
	DPVS_CLIP_CHILDREN = 1
} DpvsClipChildren;

struct PortalHeapNode
{
	int32_t portal;
	int32_t dist;
};

typedef enum
{
	DPVS_DONT_FORCE_BEVELS = 0,
	DPVS_FORCE_BEVELS = 1
} DpvsForceBevels;

struct DpvsScene
{
	char modelRefs[131072];
	char modelRefCount[4];
};

struct DpvsDebug
{
	int8_t drawWorld;
	int8_t drawEntities;
	int8_t drawSModels;
	int8_t drawXModels;
	int8_t drawBModels;
};

struct GfxMarkFragment
{
	int32_t markMaterial;
	uint16_t lmapIndex;
	uint8_t pointCount;
	char pad0[1];
	int32_t firstPoint;
};

struct GfxMarkPoint
{
	vec3_t xyz;
	vec2_t lmapCoord;
	vec3_t normal;
};

typedef enum
{
	DX_CAPS_RESPONSE_QUIT = 0,
	DX_CAPS_RESPONSE_WARN = 1,
	DX_CAPS_RESPONSE_INFO = 2,
	DX_CAPS_RESPONSE_FORBID_DX7 = 3,
	DX_CAPS_RESPONSE_FORBID_DX9 = 4
} DxCapsResponse;

struct DxCapsCheckBits
{
	uint32_t offset;
	int32_t setBits;
	int32_t clearBits;
	int32_t response;
	int32_t msg;
};

struct DxCapsCheckInteger
{
	uint32_t offset;
	int32_t min;
	int32_t max;
	int32_t response;
	int32_t msg;
};

struct GfxDrawPrimArgs
{
	int32_t firstVertexFromBase;
	uint32_t vertexCount;
	uint32_t primCount;
	$_3708 u;
};

struct GfxStateOverride
{
	uint64_t stateBitsMaskClear;
	uint64_t stateBitsMaskSet;
};

struct ShadowCandidate
{
	uint32_t entIndex;
	int32_t weight;
};

struct ShadowCookie
{
	int32_t firstCasterDrawSurf;
	int32_t firstReceiverDrawSurf;
	int32_t firstUnusedDrawSurf;
	matrix4_t shadowLookupMatrix;
	vec3_t boxMin;
	vec3_t boxMax;
	int32_t shadowViewParms;
	int32_t fade;
};

struct ShadowCookieList
{
	uint8_t cookies[2592];
	uint32_t cookieCount;
};

struct ShadowCookieGlob
{
	int32_t weightCap;
	uint32_t lastTime;
};

struct WaterGlob
{
	uint8_t H[131072];
	uint8_t pixels[65536];
};

typedef enum
{
	FOG_COLOR_SRC_UNSPECIFIED = 0,
	FOG_COLOR_SRC_STANDARD = 1,
	FOG_COLOR_SRC_BLACK = 2
} FogColorSrcEnum;

struct GfxImageFileHeader
{
	uint8_t tag[3];
	int8_t version;
	int8_t format;
	int8_t flags;
	uint8_t dimensions[6];
	uint8_t fileSizeForPicmip[16];
};

struct WaveletDecode
{
	int16_t value;
	int16_t bit;
	int32_t data;
	uint32_t width;
	int32_t height;
	int32_t channels;
	int32_t bpp;
	int32_t mipLevel;
	int8_t dataInitialized;
};

struct IncludeClass
{
};

struct ID3DXInclude
{
	void *_vptr$ID3DXInclude;
};

typedef enum
{
	D3DXINC_LOCAL = 0,
	D3DXINC_SYSTEM = 1,
	D3DXINC_FORCE_DWORD = 2147483647
} D3DXINCLUDE_TYPE;

struct MaterialObj
{
	MaterialInfoObj_s info;
	uint64_t stateBits;
	char textureCount[2];
	uint16_t constantCount;
	int32_t techniqueSet;
	char textures[4];
	int32_t constants;
};

struct GfxCachedShaderText
{
	char name[4];
	char text[4];
	char textSize[4];
};

struct ShaderConstantRouting
{
	char name[4];
	int8_t firstElem;
	uint8_t elemCount;
	char pad0[2];
	char constantInfo[4];
	char typeInfo[4];
};

struct CodeConstantSource
{
	char name[4];
	int8_t source;
	char pad0[3];
	int32_t subtable;
	uint32_t arrayCount;
	uint32_t arrayStride;
};

struct D3DXSHADER_CONSTANTINFO
{
	char Name[4];
	int16_t RegisterSet;
	uint16_t RegisterIndex;
	uint16_t RegisterCount;
	int16_t Reserved;
	char TypeInfo[4];
	int32_t DefaultValue;
};

struct D3DXSHADER_TYPEINFO
{
	int16_t Class;
	int16_t Type;
	int16_t Rows;
	int16_t Columns;
	int16_t Elements;
	int16_t StructMembers;
	char StructMemberInfo[4];
};

typedef enum
{
	MTL_TEXFUNC_VALID_COLOR = 1,
	MTL_TEXFUNC_VALID_ALPHA = 2,
	MTL_TEXFUNC_VALID_BOTH = 3
} MtlTextureFunctionValidDx7;

struct CodeSamplerSource
{
	char name[4];
	int32_t source;
	int32_t subtable;
	uint32_t arrayCount;
	uint32_t arrayStride;
};

typedef enum
{
	TEXTURE_SRC_CODE_BLACK = 0,
	TEXTURE_SRC_CODE_WHITE = 1,
	TEXTURE_SRC_CODE_IDENTITY_NORMAL_MAP = 2,
	TEXTURE_SRC_CODE_SPECULARITY = 3,
	TEXTURE_SRC_CODE_SMODEL_LIGHTING = 4,
	TEXTURE_SRC_CODE_LIGHT_GRID_WEIGHTS_0 = 5,
	TEXTURE_SRC_CODE_LIGHT_GRID_WEIGHTS_1 = 6,
	TEXTURE_SRC_CODE_LIGHTMAP_WEIGHTS = 7,
	TEXTURE_SRC_CODE_LIGHTMAP_0 = 8,
	TEXTURE_SRC_CODE_LIGHTMAP_1 = 9,
	TEXTURE_SRC_CODE_LIGHTMAP_2 = 10,
	TEXTURE_SRC_CODE_LIGHTMAP_3 = 11,
	TEXTURE_SRC_CODE_SHADOWCOOKIE = 12,
	TEXTURE_SRC_CODE_FEEDBACK = 13,
	TEXTURE_SRC_CODE_RESOLVED_POST_SUN = 14,
	TEXTURE_SRC_CODE_RESOLVED_SCENE = 15,
	TEXTURE_SRC_CODE_SKY = 16,
	TEXTURE_SRC_CODE_LIGHT0_ATTENUATION = 17,
	TEXTURE_SRC_CODE_LIGHT1_ATTENUATION = 18,
	TEXTURE_SRC_CODE_DYNAMIC_SHADOWS = 19,
	TEXTURE_SRC_CODE_OUTDOOR = 20,
	TEXTURE_SRC_CODE_FLOATZ = 21,
	TEXTURE_SRC_CODE_SUN_HALF_ANGLE = 22,
	TEXTURE_SRC_CODE_WATER_COLOR = 23
} MaterialTextureSource;

struct ID3DXConstantTable
{
};

struct D3DXCONSTANTTABLE_DESC
{
	int32_t Creator;
	char Version[4];
	int32_t Constants;
};

struct D3DXCONSTANT_DESC
{
	char Name[4];
	int32_t RegisterSet;
	uint32_t RegisterIndex;
	uint32_t RegisterCount;
	int32_t Class;
	int32_t Type;
	int32_t Rows;
	int32_t Columns;
	int32_t Elements;
	int32_t StructMembers;
	int32_t Bytes;
	int32_t DefaultValue;
};

typedef enum
{
	D3DXRS_BOOL = 0,
	D3DXRS_INT4 = 1,
	D3DXRS_FLOAT4 = 2,
	D3DXRS_SAMPLER = 3,
	D3DXRS_FORCE_DWORD = 2147483647
} D3DXREGISTER_SET;

typedef enum
{
	D3DXPC_SCALAR = 0,
	D3DXPC_VECTOR = 1,
	D3DXPC_MATRIX_ROWS = 2,
	D3DXPC_MATRIX_COLUMNS = 3,
	D3DXPC_OBJECT = 4,
	D3DXPC_STRUCT = 5,
	D3DXPC_FORCE_DWORD = 2147483647
} D3DXPARAMETER_CLASS;

typedef enum
{
	D3DXPT_VOID = 0,
	D3DXPT_BOOL = 1,
	D3DXPT_INT = 2,
	D3DXPT_FLOAT = 3,
	D3DXPT_STRING = 4,
	D3DXPT_TEXTURE = 5,
	D3DXPT_TEXTURE1D = 6,
	D3DXPT_TEXTURE2D = 7,
	D3DXPT_TEXTURE3D = 8,
	D3DXPT_TEXTURECUBE = 9,
	D3DXPT_SAMPLER = 10,
	D3DXPT_SAMPLER1D = 11,
	D3DXPT_SAMPLER2D = 12,
	D3DXPT_SAMPLER3D = 13,
	D3DXPT_SAMPLERCUBE = 14,
	D3DXPT_PIXELSHADER = 15,
	D3DXPT_VERTEXSHADER = 16,
	D3DXPT_PIXELFRAGMENT = 17,
	D3DXPT_VERTEXFRAGMENT = 18,
	D3DXPT_FORCE_DWORD = 2147483647
} D3DXPARAMETER_TYPE;

struct D3DXSHADER_CONSTANTTABLE
{
	uint32_t Size;
	int32_t Creator;
	char Version[4];
	int32_t Constants;
	char ConstantInfo[4];
	uint32_t Flags;
	int32_t Target;
};

typedef enum
{
	MTL_PARSE_SUCCESS = 0,
	MTL_PARSE_NO_MATCH = 1,
	MTL_PARSE_ERROR = 2
} MtlParseSuccess;

struct MtlStateMapBitName
{
	char name[4];
	int32_t bits;
};

struct MtlStateMapBitGroup
{
	char name[4];
	char bitNames[4];
	uint64_t stateBitsMask;
};

struct ID3DXBuffer
{
};

struct D3DXMACRO
{
	char Name[4];
	int32_t Definition;
};

struct $_3775
{
	uint32_t cachedShaderCount;
	char cachedShaderText[4];
};

struct MtlTextureFunctionDx7
{
	char name[4];
	uint32_t enumerant;
	uint32_t argCount;
	uint32_t valid;
};

struct PassOptionDx7
{
	char name[4];
	uint32_t valueOffset;
};

struct GfxImageFilterPass
{
	int32_t material;
	uint32_t srcWidth;
	int32_t srcHeight;
	uint32_t dstWidth;
	int32_t dstHeight;
	uint32_t tapHalfCount;
	uint8_t tapOffsetsAndWeights[128];
};

struct GfxImageFilter
{
	uint32_t passCount;
	uint8_t passes[2432];
	int32_t sourceImage;
	int32_t finalTarget;
	uint64_t pingPongTargets;
};

struct OutdoorGlob
{
	vec3_t bbox[2];
	vec3_t scale;
	vec3_t invScale;
	vec3_t add;
	int32_t pic;
};

struct WaveletHuffmanDecode
{
	int16_t value;
	int16_t bits;
};

struct CCallOfDutyEngine
{
	char pad0[32];
	int32_t mMouseButtonState;
};

struct yy_buffer_state
{
	int32_t yy_input_file;
	void *yy_ch_buf;
	uint32_t yy_buf_pos;
	uint32_t yy_buf_size;
	int32_t yy_n_chars;
	void *yy_is_our_buffer;
	int32_t yy_is_interactive;
	int32_t yy_at_bol;
	void *yy_fill_buffer;
	char yy_buffer_status[4];
};

struct CMutex
{
	pthread_mutex_t mMutex;
};

struct CSoundObject
{
	char _vptr$CSoundObject[4];
	int32_t mEngine;
	uint32_t mBusIndex;
	int8_t mIsAvailable;
	char pad0[3];
	char mSoundType[4];
	int8_t mIsBuffered;
	char pad1[3];
	uint32_t mSampleBufferIndex;
	int32_t mBytesPerSample;
	CMutex mMutex;
	uint8_t mPrivateSampleBuffer[16];
	uint32_t mPrivateSampleLength;
	char mssStatus[4];
	int32_t mssVolume;
	int32_t mssLeftLevel;
	int32_t mssRightLevel;
	int32_t mssPan;
	int32_t mssDryLevel;
	int32_t mssWetLevel;
	int32_t mssPlaybackRate;
	int32_t mssLoops;
	char mssSampleAddress[16];
	uint8_t mssSampleLength[16];
	uint32_t mssADPCMBlockSize;
	int32_t mssFormat;
	uint32_t mssCurrentPosition;
	uint32_t mssTotalLength;
	vec3_t mssPosition;
	vec3_t mssFace;
	vec3_t mssUp;
	int32_t mssMaxDistance;
	int32_t mssMinDistance;
};

struct CThread
{
	void *_vptr$CThread;
	int32_t mThread;
	int32_t mArg;
	uint8_t mMutex[44];
	int8_t mIsRunning;
};

struct Deque_impl
{
	int32_t _M_map;
	uint32_t _M_map_size;
	uint8_t _M_start[16];
	uint8_t _M_finish[16];
};

struct CAStreamBasicDescription
{
};

struct AudioStreamBasicDescription
{
	uint64_t mSampleRate;
	uint32_t mFormatID;
	uint32_t mFormatFlags;
	int32_t mBytesPerPacket;
	int32_t mFramesPerPacket;
	int32_t mBytesPerFrame;
	int32_t mChannelsPerFrame;
	int32_t mBitsPerChannel;
	int32_t mReserved;
};

struct CSampleSound
{
	char pad0[224];
	AudioStreamBasicDescription mSourceFormat;
	void *mConverterRef;
	int8_t mIsNativeFormat;
	int8_t mRenderProcsInstalled;
	int8_t mRemoveRenderProcs;
	int8_t mUpdateStreamFormat;
	int8_t mUpdate3DValues;
	uint8_t mOutputIsSilence;
	char pad1[2];
	uint32_t mFileHandle;
	int32_t mFileDataStart;
	int8_t mIsStreaming;
};

struct AudioBufferList
{
	uint32_t mNumberBuffers;
	vec3_t mBuffers;
};

struct AudioBuffer
{
	uint32_t mNumberChannels;
	uint32_t mDataByteSize;
	int32_t mData;
};

struct StMutexLock
{
	int32_t mMutex;
	int8_t mLocked;
};

struct AudioStreamPacketDescription
{
	vec2_t mStartOffset;
	int32_t mVariableFramesInPacket;
	uint32_t mDataByteSize;
};

struct SMPTETime
{
	int16_t mSubframes;
	int16_t mSubframeDivisor;
	uint32_t mCounter;
	int32_t mType;
	uint32_t mFlags;
	int16_t mHours;
	int16_t mMinutes;
	int16_t mSeconds;
	int16_t mFrames;
};

struct AudioTimeStamp
{
	uint64_t mSampleTime;
	uint64_t mHostTime;
	uint64_t mRateScalar;
	uint64_t mWordClockTime;
	SMPTETime mSMPTETime;
	uint32_t mFlags;
	int32_t mReserved;
};

struct AURenderCallbackStruct
{
	int32_t inputProc;
	void *inputProcRefCon;
};

struct MixerDistanceParams
{
	void *mReferenceDistance;
	int32_t mMaxDistance;
	int32_t mMaxAttenuation;
};

struct StThreadLock
{
	int32_t mThread;
	int8_t mLocked;
};

struct AudioChannelLayout
{
	int32_t mChannelLayoutTag;
	int32_t mChannelBitmap;
	char mNumberChannelDescriptions[4];
	char mChannelDescriptions[20];
};

struct AudioChannelDescription
{
	int32_t mChannelLabel;
	uint32_t mChannelFlags;
	vec3_t mCoordinates;
};

struct ComponentDescription
{
	int32_t componentType;
	int32_t componentSubType;
	int32_t componentManufacturer;
	uint32_t componentFlags;
	uint32_t componentFlagsMask;
};

struct ComponentRecord
{
	int32_t data;
};

struct CD3DXBuffer
{
	char pad0[4];
	uint32_t mRefCount;
	uint32_t mBufferLength;
	void *mpBuffer;
};

struct CD3DXConstantTable
{
	char pad0[4];
	uint32_t mRefCount;
	uint32_t mSize;
	int32_t mpConstantTable;
};

struct CStreamSound
{
	char pad0[224];
	int32_t mMovie;
	int32_t mTrack;
	int32_t mMedia;
	int32_t mMovieRate;
};

struct SoundDescription
{
	uint32_t descSize;
	int32_t dataFormat;
	int32_t resvd1;
	int16_t resvd2;
	uint16_t dataRefIndex;
	char version[2];
	int16_t revlevel;
	int32_t vendor;
	uint16_t numChannels;
	uint16_t sampleSize;
	uint16_t compressionID;
	uint16_t packetSize;
	int32_t sampleRate;
};

struct PlayerKeyState
{
	char chatField[280];
	char chat_team[4];
	int32_t key_overstrikeMode;
	int32_t anykeydown;
	uint8_t keys[3072];
};

struct qkey_t
{
	int32_t down;
	int32_t repeats;
	int32_t binding;
};

struct keyname_t
{
	char name[4];
	uint32_t keynum;
};

struct netadr_t
{
	int32_t type;
	int32_t ip;
	uint16_t port;
};

struct netchan_t
{
	int32_t outgoingSequence;
	int32_t sock;
	int32_t dropped;
	int32_t incomingSequence;
	netadr_t remoteAddress;
	int32_t qport;
	int32_t fragmentSequence;
	uint32_t fragmentLength;
	uint8_t fragmentBuffer[16384];
	int32_t unsentFragments;
	int32_t unsentFragmentStart;
	uint32_t unsentLength;
	uint8_t unsentBuffer[16384];
	int32_t pProf;
};

struct client_s
{
	int32_t state;
	int32_t sendAsActive;
	int32_t dropReason;
	char userinfo[1024];
	char reliableCommandInfo[132096];
	int32_t reliableSequence;
	int32_t reliableAcknowledge;
	int32_t reliableSent;
	char messageAcknowledge[4];
	char gamestateMessageNum[4];
	uint32_t challenge;
	usercmd_s lastUsercmd;
	char lastClientCommand[4];
	char lastClientCommandString[1024];
	int32_t gentity;
	char name[32];
	char downloadName[64];
	char download[4];
	char downloadSize[4];
	char downloadCount[4];
	char downloadClientBlock[4];
	char downloadCurrentBlock[4];
	char downloadXmitBlock[4];
	char downloadBlocks[32];
	char downloadBlockSize[32];
	char downloadEOF[4];
	char downloadSendTime[4];
	char deltaMessage[4];
	uint32_t nextReliableTime;
	uint32_t lastPacketTime;
	uint32_t lastConnectTime;
	uint32_t nextSnapshotTime;
	int32_t rateDelayed;
	uint32_t timeoutCount;
	uint8_t frames[317568];
	int32_t ping;
	int32_t rate;
	int32_t snapshotMsec;
	int32_t pureAuthentic;
	netchan_t netchan;
	uint32_t guid;
	char scriptId[2];
	char pad0[2];
	int32_t bIsTestClient;
	uint32_t serverId;
	uint8_t voicePackets[10440];
	uint32_t voicePacketCount;
	uint8_t muteList[64];
	int8_t sendVoice;
};

struct svscmd_info_t
{
	char cmd[1024];
	uint32_t time;
	int32_t type;
};

struct clientSnapshot_t
{
	playerState_s ps;
	uint32_t num_entities;
	uint32_t num_clients;
	int32_t first_entity;
	int32_t first_client;
	int32_t messageSent;
	int32_t messageAcked;
	int32_t messageSize;
};

typedef enum
{
	NS_CLIENT1 = 0,
	NS_SERVER = 1,
	NS_MAXCLIENTS = 1,
	NS_PACKET = 2
} netsrc_t;

struct VoicePacket_t
{
	int8_t talker;
	uint8_t data[256];
	uint32_t dataSize;
};

struct netProfileStream_t
{
	uint8_t packets[720];
	int32_t iCurrPacket;
	int32_t iBytesPerSecond;
	uint32_t iLastBPSCalcTime;
	uint32_t iCountedPackets;
	uint32_t iCountedFragments;
	int32_t iFragmentPercentage;
	int32_t iLargestPacket;
	int32_t iSmallestPacket;
};

struct netProfileInfo_t
{
	netProfileStream_t send;
	uint8_t recieve[752];
};

struct netProfilePacket_t
{
	uint32_t iTime;
	uint32_t iSize;
	int32_t bFragment;
};

struct MenuList
{
	uint32_t menuCount;
	int32_t menus;
};

struct windowDef_t
{
	uint8_t rect[96];
	uint8_t rectClient[96];
	char name[4];
	int32_t group;
	char cinematicName[4];
	int32_t cinematic;
	int32_t style;
	int32_t border;
	int32_t ownerDraw;
	uint32_t ownerDrawFlags;
	uint32_t borderSize;
	uint32_t staticFlags;
	uint8_t dynamicFlags[16];
	vec3_t rectEffects0[8];
	vec3_t rectEffects1[8];
	uint8_t offsetTime[16];
	uint32_t nextTime;
	vec4_t foreColor;
	vec4_t backColor;
	vec4_t borderColor;
	vec4_t outlineColor;
	int32_t background;
};
struct menuDef_t
{
	windowDef_t window;
	int32_t font;
	int32_t fullScreen;
	uint32_t itemCount;
	uint32_t fontIndex;
	uint8_t cursorItem[16];
	int32_t fadeCycle;
	int32_t fadeClamp;
	int32_t fadeAmount;
	int32_t fadeInAmount;
	int32_t blurRadius;
	int32_t onOpen;
	int32_t onClose;
	int32_t onESC;
	int32_t onKey;
	char soundName[4];
	int32_t imageTrack;
	vec4_t focusColor;
	vec4_t disableColor;
	int32_t items;
};

struct ItemKeyHandler
{
	int32_t key;
	int32_t action;
	int32_t next;
};

union itemDefData_t
{
	int32_t listBox;
	int32_t editField;
	int32_t multi;
	char enumDvarName[4];
	int32_t data;
};

struct itemDef_s
{
	uint8_t window[528];
	char textRect[96];
	int32_t type;
	int32_t dataType;
	int32_t alignment;
	uint32_t fontEnum;
	char textalignment[4];
	char textalignx[4];
	char textaligny[4];
	char textscale[4];
	char textStyle[4];
	char text[4];
	char textSavegameInfo[4];
	int32_t parent;
	char mouseEnterText[4];
	char mouseExitText[4];
	int32_t mouseEnter;
	int32_t mouseExit;
	int32_t action;
	int32_t onAccept;
	int32_t onFocus;
	int32_t leaveFocus;
	int32_t dvar;
	int32_t dvarTest;
	int32_t onKey;
	int32_t enableDvar;
	uint32_t dvarFlags;
	char focusSound[4];
	char special[4];
	uint8_t cursorPos[16];
	itemDefData_t typeData;
	int32_t imageTrack;
};

struct rectDef_s
{
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
	int32_t horzAlign;
	int32_t vertAlign;
};

struct listBoxDef_s
{
	uint8_t startPos[16];
	uint8_t endPos[16];
	int32_t drawPadding;
	uint8_t cursorPos[16];
	uint32_t elementWidth;
	int32_t elementHeight;
	int32_t elementStyle;
	uint32_t numColumns;
	char columnInfo[192];
	int32_t doubleClick;
	int32_t notselectable;
	int32_t noScrollBars;
};

struct editFieldDef_s
{
	int32_t minVal;
	int32_t maxVal;
	int32_t defVal;
	int32_t range;
	int32_t maxChars;
	int32_t maxCharsGotoNext;
	int32_t maxPaintChars;
	uint32_t paintOffset;
};

struct multiDef_s
{
	uint8_t dvarList[128];
	uint8_t dvarStr[128];
	uint8_t dvarValue[128];
	uint32_t count;
	int32_t strDef;
};

struct columnInfo_s
{
	uint32_t pos;
	uint32_t width;
	int32_t maxChars;
};

struct clientInfo_t
{
	char infoValid[4];
	uint32_t nextValid;
	uint32_t clientNum;
	char name[32];
	int32_t team;
	int32_t oldteam;
	int32_t score;
	int32_t location;
	int32_t health;
	char model[64];
	char attachModelNames[384];
	char attachTagNames[384];
	lerpFrame_t legs;
	uint8_t torso[48];
	int32_t lerpMoveDir;
	int32_t lerpLean;
	vec3_t playerAngles;
	int32_t leftHandGun;
	int32_t dobjDirty;
	vec3_t angles[6];
	vec3_t tag_origin_angles;
	vec3_t tag_origin_offset;
	vec3_t clientConditions[6];
	int32_t pXAnimTree;
	uint32_t iDObjWeapon;
	uint32_t stanceTransitionTime;
	uint32_t turnAnimEndTime;
	int8_t turnAnimType;
};

struct centity_s
{
	uint8_t currentState[240];
	uint8_t nextState[240];
	int8_t nextValid;
	int8_t cullIn;
	int8_t bMuzzleFlash;
	int8_t bTrailMade;
	int32_t previousEventSequence;
	uint32_t miscTime;
	vec3_t lerpOrigin;
	vec3_t lerpAngles;
	vec3_t lightingOrigin;
	uint32_t dl_time;
	char voiceChatSprite[4];
	char voiceChatSpriteTime[4];
	int32_t tree;
	uint32_t localClientNum;
};

struct weaponInfo_s
{
	char viewModelDObj[4];
	char viewModelAnimRates[92];
	char handModel[64];
	int32_t iPrevAnim;
	int32_t tree;
	int32_t registered;
	int32_t item;
	char pszTranslatedDisplayName[4];
	char pszTranslatedModename[4];
	char pszTranslatedAIOverlayDescription[4];
	char worldSurfModel[4];
	int32_t viewFlashEffect;
	int32_t worldFlashEffect;
	vec3_t weaponMidpoint;
	char missileSound[4];
	char pullbackSound[4];
	char flashSound[4];
	char flashSoundPlayer[4];
	char lastShotSound[4];
	char lastShotSoundPlayer[4];
	char meleeSwipeSound[4];
	char rechamberSound[4];
	char rechamberSoundPlayer[4];
	char reloadSound[4];
	char reloadSoundPlayer[4];
	char reloadEmptySound[4];
	char reloadEmptySoundPlayer[4];
	char reloadStartSound[4];
	char reloadStartSoundPlayer[4];
	char reloadEndSound[4];
	char reloadEndSoundPlayer[4];
	char raiseSound[4];
	char altSwitchSound[4];
	char putawaySound[4];
	char noteTrackSound[16];
	int32_t ammoIcon;
	int32_t hHudIcon;
	int32_t hModeIcon;
	char missileSurfModel[4];
	int32_t missileTrailFunc;
	int32_t missileDlight;
	vec3_t missileDlightColor;
	int32_t missileRenderfx;
	int32_t shellEjectEffect;
	int32_t lastShotEjectEffect;
	int32_t projExplosionEffect;
	char projExplosionSound[4];
	int32_t projTrailEffect;
	int32_t trailRadius;
	uint32_t wiTrailTime;
	int32_t hReticleCenter;
	uint32_t hReticleSide;
	int32_t hADSOverlay;
	vec3_t vPositionOrg[2];
	vec3_t vPositionAng[2];
};

struct $_3712
{
	int32_t registered;
	char models[8];
	uint8_t icons[16];
	char pickupSound[4];
	char ammoPickupSound[4];
};

struct $_3721
{
	int32_t use;
	uint32_t fadeInTime;
	uint32_t fadeOutTime;
	int32_t drylevel;
	int32_t wetlevel;
	uint8_t roomtype[16];
	uint8_t channelvolume[44];
	int32_t modEndDelay;
	uint32_t loopFadeTime;
	int32_t loopEndDelay;
};

struct shellshock_parms_t
{
	$_3719 view;
	$_3720 screenBlend;
	$_3721 sound;
	$_3722 mouse;
};

struct gameState_t
{
	char stringOffsets[8192];
	char stringData[16000];
	uint32_t dataCount;
};

struct cgMedia_t
{
	int32_t whiteMaterial;
	int32_t softLineMaterial;
	int32_t softLineHMaterial;
	char teamStatusBar[4];
	char voiceChatMaterial[4];
	int32_t balloonMaterial;
	int32_t connectionMaterial;
	int32_t youInKillCamMaterial;
	int32_t tracerMaterial;
	int32_t lagometerMaterial;
	uint8_t hintMaterials[532];
	uint8_t stanceMaterials[16];
	int32_t objectiveMaterials;
	uint64_t friendMaterials;
	int32_t damageMaterial;
	int32_t mantleHint;
	int32_t smallDevFont;
	int32_t bigDevFont;
	char noAmmoSound[4];
	char landDmgSound[4];
	char teleInSound[4];
	char grenadeBounceSound[92];
	char grenadeExplodeSound[92];
	char rocketExplodeSound[92];
	char bulletHitSmallSound[92];
	char shotgunHitSound[92];
	char bulletHitLargeSound[92];
	char stepRunSound[92];
	char stepRunSoundPlayer[92];
	char stepWalkSound[92];
	char stepWalkSoundPlayer[92];
	char stepProneSound[92];
	char stepProneSoundPlayer[92];
	char landSound[92];
	char landSoundPlayer[92];
	char runningEquipmentSound[4];
	char runningEquipmentSoundPlayer[4];
	char walkingEquipmentSound[4];
	char walkingEquipmentSoundPlayer[4];
	int32_t foliageMovement;
	int32_t bulletWhizby;
	int32_t meleeSwingLarge;
	int32_t meleeSwingSmall;
	int32_t meleeHit;
	int32_t meleeHitOther;
	char playerHeartBeatSound[4];
	char playerBreathInSound[4];
	char playerBreathOutSound[4];
	char playerBreathGaspSound[4];
	int32_t playerSwapOffhand;
	int32_t checkbox_clear;
	int32_t checkbox_checked;
	int32_t checkbox_fail;
	int32_t compassping_friendlyfiring;
	int32_t compassping_friendlyyelling;
	int32_t compassping_enemyfiring;
	int32_t compassping_enemyyelling;
	int32_t compassping_grenade;
	int32_t compassping_explosion;
	int32_t grenadeIcon;
	int32_t grenadePointer;
	int32_t fx;
	int32_t fxNoBloodFleshHit;
};

struct $_3727
{
	gameState_t gameState;
	int32_t viewX;
	int32_t viewY;
	uint32_t viewWidth;
	int32_t viewHeight;
	char viewAspect[4];
	char serverCommandSequence[4];
	uint32_t processedSnapshotNum;
	int32_t localServer;
	char gametype[32];
	char szHostName[256];
	int32_t maxclients;
	char mapname[64];
	uint8_t redTeam[64];
	uint8_t blueTeam[64];
	char voteTime[4];
	char voteYes[4];
	char voteNo[4];
	char voteString[256];
	char teamVoteTime[8];
	char teamVoteYes[8];
	char teamVoteNo[8];
	char teamVoteModified[8];
	char teamVoteString[512];
	uint32_t levelStartTime;
	uint64_t teamScores;
	char gameModels[1024];
	uint8_t fxs[256];
	int32_t smokeGrenadeFx;
	uint8_t shellshockParms[2112];
	shellshock_parms_t holdBreathParams;
	char numInlineModels[4];
	char inlineDrawModel[4092];
	char inlineModelMidpoints[12276];
	char teamChatMsgs[2168];
	char teamChatMsgTimes[32];
	char teamChatPos[4];
	char teamLastChatPos[4];
	cgMedia_t media;
	uint32_t compassWidth;
	int32_t compassHeight;
	int32_t compassY;
	char corpseinfo[9664];
};

struct FxImpactTable
{
	char name[4];
	int32_t table;
};

typedef enum
{
	DEMO_TYPE_NONE = 0,
	DEMO_TYPE_CLIENT = 1,
	DEMO_TYPE_SERVER = 2
} DemoType;

struct score_t
{
	int32_t client;
	int32_t score;
	int32_t ping;
	int32_t deaths;
	int32_t team;
	char hStatusIcon[4];
};

struct viewDamage_t
{
	uint32_t time;
	int32_t duration;
	int32_t yaw;
};

struct cameraShake_t
{
	uint32_t time;
	int32_t scale;
	uint32_t length;
	int32_t radius;
	vec3_t src;
	uint32_t size;
	int32_t rumbleScale;
};

struct compassactor_t
{
	int32_t iLastUpdate;
	uint64_t vLastPos;
	int32_t fLastYaw;
	uint32_t pingTime;
	uint32_t beginFadeTime;
	int8_t enemy;
};

struct animScript_t
{
	uint32_t numItems;
	uint8_t items[512];
};

struct animScriptItem_t
{
	uint32_t numConditions;
	uint8_t conditions[108];
	char numCommands[4];
	char commands[128];
};

struct animScriptCondition_t
{
	uint32_t index;
	uint64_t value;
};

struct animScriptCommand_t
{
	int32_t bodyPart;
	uint32_t animIndex;
	int32_t animDuration;
	char soundAlias[4];
};

struct displayContextDef_s
{
	int32_t bias;
	uint32_t realTime;
	uint32_t frameTime;
	int32_t cursorx;
	int32_t cursory;
	int32_t debug;
	uint32_t screenWidth;
	int32_t screenHeight;
	char screenAspect[4];
	int32_t FPS;
	int32_t blurRadiusOut;
	uint8_t Menus[512];
	uint32_t menuCount;
	uint8_t menuStack[64];
	uint32_t openMenuCount;
};

struct clSnapshot_t
{
	uint32_t valid;
	uint32_t snapFlags;
	uint32_t serverTime;
	char messageNum[4];
	uint32_t deltaNum;
	int32_t ping;
	char cmdNum[4];
	playerState_s ps;
	uint32_t numEntities;
	uint32_t numClients;
	uint32_t parseEntitiesNum;
	uint32_t parseClientsNum;
	char serverCommandNum[4];
};

struct $_3785
{
	int8_t active;
	char pad0[3];
	int32_t keyCatchers;
	int8_t displayHUDWithKeycatchUI;
	int8_t cgameInitialized;
	int8_t cgameInitCalled;
	int8_t usingAds;
	uint32_t frameActiveClientCount;
	uint32_t frameClientIndex;
	uint32_t timeoutcount;
	clSnapshot_t snap;
	uint32_t serverTime;
	uint32_t oldServerTime;
	uint32_t oldFrameServerTime;
	uint32_t serverTimeDelta;
	uint32_t oldSnapServerTime;
	int32_t extrapolatedSnapshot;
	int32_t newSnapshots;
	gameState_t gameState;
	char mapname[64];
	uint32_t parseEntitiesNum;
	uint32_t parseClientsNum;
	uint64_t mouseDx;
	uint64_t mouseDy;
	uint32_t mouseIndex;
	int8_t stanceHeld;
	char pad1[3];
	uint32_t stancePosition;
	uint32_t stanceTime;
	char cgameUserCmdValue[4];
	int32_t cgameUserHoldableValue;
	int32_t cgameInShellshock;
	int32_t cgameSensitivity;
	float cgameMaxPitchSpeed;
	float cgameMaxYawSpeed;
	vec3_t cgameKickAngles;
	vec3_t viewangles;
	uint32_t serverId;
	vec4_t color_allies;
	vec4_t color_axis;
	uint32_t skelTimeStamp;
	uint32_t skelMemPos;
	uint8_t skelMemory[262144];
	int32_t skelMemoryStart;
	int8_t allowedAllocSkel;
	char pad2[3];
	char cmds[3584];
	char cmdNumber[4];
	uint8_t outPackets[384];
	uint8_t snapshots[318208];
	uint8_t entityBaselines[245760];
	uint8_t parseEntities[491520];
	uint8_t parseClients[188416];
	int32_t corruptedTranslationFile;
	char translationVersion[256];
	uint8_t voicePackets[2600];
	uint32_t voicePacketCount;
	int32_t voicePacketLastTransmit;
};

struct outPacket_t
{
	char p_cmdNumber[4];
	uint32_t p_serverTime;
	uint32_t p_realtime;
};

struct ClientVoicePacket_t
{
	uint32_t dataSize;
	uint8_t data[256];
};

struct msg_t
{
	int32_t overflowed;
	int32_t data;
	uint32_t maxsize;
	uint32_t cursize;
	uint32_t readcount;
	int32_t bit;
};

struct $_3568
{
	int8_t talker;
	uint8_t data[256];
	uint32_t dataSize;
};

struct $_3702
{
	int16_t _;
	int16_t allies;
	int16_t axis;
	int16_t current;
	int16_t damage;
	int16_t death;
	int16_t dlight;
	int16_t done;
	int16_t empty;
	int16_t entity;
	int16_t failed;
	int16_t fraction;
	int16_t goal;
	int16_t grenade;
	char info_notnull[2];
	int16_t invisible;
	int16_t key1;
	int16_t key2;
	char killanimscript[2];
	int16_t left;
	int16_t movedone;
	int16_t noclass;
	int16_t normal;
	int16_t pistol;
	int16_t plane_waypoint;
	int16_t player;
	uint16_t position;
	int16_t primary;
	int16_t primaryb;
	int16_t prone;
	int16_t right;
	int16_t rocket;
	int16_t rotatedone;
	char script_brushmodel[2];
	char script_model[2];
	char script_origin[2];
	char spectator[2];
	int16_t stand;
	int16_t surfacetype;
	char target_script_trigger[2];
	int16_t tempEntity;
	int16_t touch;
	int16_t trigger;
	int16_t trigger_use;
	int16_t trigger_use_touch;
	int16_t trigger_damage;
	int16_t trigger_lookat;
	int16_t truck_cam;
	int16_t worldspawn;
	int16_t binocular_enter;
	int16_t binocular_exit;
	int16_t binocular_fire;
	int16_t binocular_release;
	int16_t binocular_drop;
	int16_t begin;
	int16_t intermission;
	int16_t menuresponse;
	int16_t playing;
	int16_t none;
	int16_t dead;
	int16_t auto_change;
	int16_t manual_change;
	int16_t freelook;
	char call_vote[2];
	char vote[2];
	int16_t snd_enveffectsprio_level;
	int16_t snd_enveffectsprio_shellshock;
	int16_t snd_channelvolprio_holdbreath;
	int16_t snd_channelvolprio_pain;
	int16_t snd_channelvolprio_shellshock;
	int16_t tag_flash;
	int16_t tag_flash_11;
	int16_t tag_flash_2;
	int16_t tag_flash_22;
	int16_t tag_brass;
	int16_t j_head;
	int16_t tag_weapon;
	int16_t tag_player;
	int16_t tag_camera;
	int16_t tag_aim;
	int16_t tag_aim_animated;
	int16_t tag_origin;
	int16_t tag_butt;
	int16_t tag_weapon_right;
	int16_t back_low;
	uint16_t back_mid;
	int16_t back_up;
	int16_t neck;
	int16_t head;
	int16_t pelvis;
};

struct $_3700
{
	vec3_t start;
	vec3_t end;
	vec4_t color;
	int32_t depthTest;
};

struct $_3788
{
	netadr_t adr;
	int8_t netType;
	int8_t clients;
	int8_t maxClients;
	int8_t dirty;
	int8_t allowAnonymous;
	int8_t bPassword;
	int8_t pure;
	int8_t friendlyfire;
	int8_t killcam;
	int8_t consoleDisabled;
	int8_t hardware;
	int8_t mod;
	int8_t voice;
	uint8_t requestCount;
	int16_t minPing;
	int16_t maxPing;
	int16_t ping;
	char hostName[32];
	char mapName[32];
	uint8_t game[24];
	char gameType[16];
};

struct $_3786
{
	int32_t state;
	int32_t qport;
	uint32_t clientNum;
	uint32_t lastPacketSentTime;
	uint32_t lastPacketTime;
	char serverAddress[12];
	uint32_t connectTime;
	uint32_t connectPacketCount;
	char serverMessage[256];
	uint32_t challenge;
	int32_t checksumFeed;
	int32_t reliableSequence;
	int32_t reliableAcknowledge;
	char reliableCommands[131072];
	char serverMessageSequence[4];
	char serverCommandSequence[4];
	char lastExecutedServerCommand[4];
	char serverCommands[131072];
	char download[4];
	char downloadTempName[256];
	char downloadName[256];
	char downloadNumber[4];
	char downloadBlock[4];
	char downloadCount[4];
	char downloadSize[4];
	char downloadList[1024];
	char downloadRestart[4];
	char demoName[64];
	char demorecording[4];
	char demoplaying[4];
	char isTimeDemo[4];
	char demowaiting[4];
	char firstDemoFrameSkipped[4];
	char demofile[4];
	char timeDemoLog[4];
	char timeDemoFrames[4];
	char timeDemoStart[4];
	char timeDemoPrev[4];
	char timeDemoBaseTime[4];
	netchan_t netchan;
	int32_t pOOBProf;
};

struct clientLogo_t
{
	uint32_t startTime;
	int32_t duration;
	int32_t fadein;
	int32_t fadeout;
	uint64_t material;
};

struct clientDebug_t
{
	char maxStrings[4];
	char numStrings[4];
	char strings[4];
	char stringFromServer[4];
	int32_t maxLines;
	uint32_t numLines;
	int32_t lines;
	int32_t lineFromServer;
	int32_t lineDuration;
};

struct $_3791
{
	int32_t quit;
	int32_t hunkUsersStarted;
	char servername[256];
	int32_t rendererStarted;
	char soundStarted[4];
	int32_t uiStarted;
	uint32_t frametime;
	uint32_t realtime;
	uint32_t realFrametime;
	clientLogo_t logo;
	uint32_t numlocalservers;
	uint8_t localServers[17408];
	int32_t waitglobalserverresponse;
	uint32_t numglobalservers;
	uint8_t globalServers[2720000];
	uint32_t numfavoriteservers;
	uint8_t favoriteServers[17408];
	int32_t pingUpdateSource;
	vec3_t authorizeServer;
	int32_t whiteMaterial;
	int32_t consoleMaterial;
	int32_t consoleFont;
	vidConfig_t vidConfig;
	clientDebug_t debug;
};

struct ping_t
{
	vec3_t adr;
	int32_t start;
	uint32_t time;
	char info[1024];
};

typedef enum
{
	SV_CMD_CAN_IGNORE = 0,
	SV_CMD_RELIABLE = 1
} svscmd_type;

struct serverStatusInfo_t
{
	char address[64];
	uint8_t lines[2048];
	char text[1024];
	uint8_t pings[192];
	uint32_t numLines;
};

typedef enum
{
	UIMENU_NONE = 0,
	UIMENU_MAIN = 1,
	UIMENU_INGAME = 2,
	UIMENU_NEED_CD = 3,
	UIMENU_BAD_CD_KEY = 4,
	UIMENU_TEAM = 5,
	UIMENU_PREGAME = 6,
	UIMENU_POSTGAME = 7,
	UIMENU_WM_QUICKMESSAGE = 8,
	UIMENU_SCRIPT_POPUP = 9,
	UIMENU_SCRIPT_POPUP_NO_MOUSE = 10,
	UIMENU_PLAYER_PROFILE = 11
} uiMenuCommand_t;

struct ConversionArguments
{
	uint32_t argCount;
	uint8_t args[36];
};

struct $_3706
{
	char levelscript[4];
	char gametypescript[4];
	$_3707 gametype;
	int32_t delete_;
	int32_t initstructs;
	int32_t createstruct;
	char playerCorpseInfo[9792];
};

struct serverStatus_s
{
	char string[8192];
	char address[12];
	uint32_t time;
	uint32_t startTime;
	int32_t pending;
	int32_t print;
	int32_t retrieved;
};

struct CachedAssets_t
{
	int32_t scrollBarArrowUp;
	int32_t scrollBarArrowDown;
	int32_t scrollBarArrowLeft;
	int32_t scrollBarArrowRight;
	int32_t scrollBar;
	int32_t scrollBarThumb;
	uint32_t sliderBar;
	uint32_t sliderThumb;
	int32_t whiteMaterial;
	int32_t cursor;
	int32_t bigFont;
	int32_t smallFont;
	int32_t consoleFont;
	int32_t boldFont;
	char textFont[4];
	int32_t extraBigFont;
	char itemFocusSound[4];
};

struct pendingServerStatus_t
{
	uint32_t num;
	uint8_t server[2240];
};

struct gameTypeInfo
{
	char gameType[4];
	char gameTypeName[4];
};

struct mapInfo
{
	char mapName[4];
	char mapLoadName[4];
	char imageName[4];
	char opponentName[4];
	int32_t teamMembers;
	int32_t typeBits;
	int32_t cinematic;
	uint8_t timeToBeat[128];
	int32_t levelShot;
	int32_t active;
};

struct modInfo_t
{
	char modName[4];
	int32_t modDescr;
};

struct pinglist_t
{
	uint8_t adrstr[64];
	int32_t start;
};

struct pendingServer_t
{
	uint8_t adrstr[64];
	char name[64];
	uint32_t startTime;
	uint32_t serverNum;
	uint32_t valid;
};

struct PlayerProfileStatus
{
	int32_t sortDir;
	uint8_t displayProfile[256];
};

struct serverFilter_s
{
	char description[4];
	int32_t basedir;
};

struct serverStatusDvar_t
{
	char name[4];
	char altName[4];
	int32_t type;
};

typedef enum
{
	SSC_STRING = 0,
	SSC_YESNO = 1
} sscType_t;

struct loopmsg_t
{
	uint8_t data[1400];
	uint32_t datalen;
	int32_t port;
};

struct challenge_t
{
	vec3_t adr;
	uint32_t challenge;
	uint32_t time;
	uint32_t pingTime;
	uint32_t firstTime;
	int32_t firstPing;
	int32_t connected;
	uint32_t guid;
};
struct $_3767
{
	int32_t initialized;
	uint32_t time;
	uint32_t snapFlagServerBit;
	int32_t clients;
	uint32_t numSnapshotEntities;
	uint32_t numSnapshotClients;
	int32_t nextSnapshotEntities;
	int32_t nextSnapshotClients;
	int32_t snapshotEntities;
	int32_t snapshotClients;
	int32_t archiveEnabled;
	int32_t nextArchivedSnapshotFrames;
	int32_t archivedSnapshotFrames;
	void *archivedSnapshotBuffer;
	void *nextArchivedSnapshotBuffer;
	int32_t nextCachedSnapshotEntities;
	int32_t nextCachedSnapshotClients;
	int32_t nextCachedSnapshotFrames;
	int32_t cachedSnapshotEntities;
	int32_t cachedSnapshotClients;
	int32_t cachedSnapshotFrames;
	uint32_t nextHeartbeatTime;
	char nextStatusResponseTime[4];
	challenge_t challenges[1024];
	char redirectAddress[12];
	char authorizeAddress[12];
	int32_t pOOBProf;
	uint8_t tempBans[128];
};

struct cachedSnapshot_t
{
	int32_t archivedFrame;
	uint32_t time;
	uint32_t num_entities;
	int32_t first_entity;
	uint32_t num_clients;
	int32_t first_client;
	int32_t usesDelta;
};

struct tempBanSlot_t
{
	uint32_t guid;
	uint32_t banTime;
};

struct archivedSnapshot_s
{
	int32_t start;
	uint32_t size;
};

struct cachedClient_s
{
	int32_t playerStateExists;
	clientState_s cs;
	playerState_s ps;
};

struct $_3759
{
	int32_t state;
	int32_t restarting;
	uint32_t start_frameTime;
	int32_t checksumFeed;
	uint32_t timeResidual;
	uint32_t nextFrameTime;
	char models[1024];
	char configstrings[8192];
	svEntity_s svEntities[1024];
	int32_t entityParsePoint;
	int32_t gentities;
	uint32_t gentitySize;
	uint32_t num_entities;
	int32_t gameClients;
	uint32_t gameClientSize;
	uint32_t skelTimeStamp;
	uint32_t skelMemPos;
	uint8_t bpsWindow[80];
	int32_t bpsWindowSteps;
	int32_t bpsTotalBytes;
	int32_t bpsMaxBytes;
	uint8_t ubpsWindow[80];
	int32_t ubpsTotalBytes;
	int32_t ubpsMaxBytes;
	int32_t ucompAve;
	uint32_t ucompNum;
	char gametype[64];
};

typedef enum
{
	SS_DEAD = 0,
	SS_LOADING = 1,
	SS_GAME = 2
} serverState_t;

struct MessageWindow
{
	int32_t lines;
	int32_t current_line;
	uint32_t count;
	int32_t padding;
	uint32_t scrolltime;
	int32_t fadein;
	int32_t fadeout;
};

struct MessageLine
{
	char textBuffer[156];
	uint32_t startTime;
	uint32_t endTime;
};

typedef enum
{
	MWM_TOPDOWN = 0,
	MWM_TOPDOWN_REVERSED = 1,
	MWM_BOTTOMUP = 2,
	MWM_BOTTOMUP_CENTERED = 3
} msgwnd_mode_t;

struct ConDrawInputGlob
{
	uint32_t matchCount;
	char inputText[4];
	char inputTextLen[4];
	int8_t hasExactMatch;
	char pad0[3];
	int32_t x;
	int32_t y;
	int32_t leftX;
	int32_t fontHeight;
};

struct Console
{
	int32_t initialized;
	char textBuffer[131072];
	int32_t currentLine;
	uint32_t lineOffset;
	int32_t display;
	int32_t prevType;
	uint32_t linewidth;
	int32_t totallines;
	int8_t outputVisible;
	char pad0[3];
	uint64_t screenMin;
	uint64_t screenMax;
	char messageBuffer[4];
	char messageBufferArray[20448];
	vec4_t color;
};

struct MessageBuffer
{
	uint8_t gamemsg[28];
	uint8_t gamemsg_lines[1312];
	uint8_t boldgamemsg[28];
	uint8_t boldgamemsg_lines[1312];
	uint8_t subtitle[28];
	uint8_t subtitle_lines[1312];
	uint8_t minicon[28];
	uint8_t minicon_lines[16400];
};

struct serverInfo_t
{
	netadr_t adr;
	int8_t netType;
	int8_t clients;
	int8_t maxClients;
	int8_t dirty;
	int8_t allowAnonymous;
	int8_t bPassword;
	int8_t pure;
	int8_t friendlyfire;
	int8_t killcam;
	int8_t consoleDisabled;
	int8_t hardware;
	int8_t mod;
	int8_t voice;
	uint8_t requestCount;
	int16_t minPing;
	int16_t maxPing;
	int16_t ping;
	char hostName[32];
	char mapName[32];
	uint8_t game[24];
	char gameType[16];
};

struct $_3787
{
	vec3_t adr;
	int32_t start;
	uint32_t time;
	char info[1024];
};

struct $_3812
{
	int32_t ip;
	uint16_t port;
};

struct $_3813
{
	char password[24];
	vec3_t host;
};

struct scrollInfo_s
{
	uint32_t nextScrollTime;
	uint32_t nextAdjustTime;
	int32_t adjustValue;
	int32_t scrollKey;
	int32_t xStart;
	int32_t yStart;
	int32_t item;
	int32_t scrollDir;
};

struct commandDef_t
{
	char name[4];
	uint32_t handler;
};

struct bind_t
{
	char command[4];
	int32_t defaultbind1;
	int32_t defaultbind2;
	int32_t bind1;
	int32_t bind2;
};

struct NetField
{
	char name[4];
	uint32_t offset;
	int32_t bits;
};

struct huff_t
{
	int32_t blocNode;
	void *blocPtrs;
	int32_t tree;
	int32_t lhead;
	int32_t ltail;
	uint8_t loc[1028];
	int32_t freelist;
	uint8_t nodeList[24576];
	uint8_t nodePtrs[3072];
};

struct $_3769
{
	huff_t compressor;
	uint8_t decompressor[28700];
};

struct nodetype
{
	int32_t left;
	int32_t right;
	int32_t parent;
	int32_t next;
	int32_t prev;
	int32_t head;
	int32_t weight;
	int32_t symbol;
};

struct $_3783
{
	uint32_t valid;
	uint32_t snapFlags;
	uint32_t serverTime;
	char messageNum[4];
	uint32_t deltaNum;
	int32_t ping;
	char cmdNum[4];
	playerState_s ps;
	uint32_t numEntities;
	uint32_t numClients;
	uint32_t parseEntitiesNum;
	uint32_t parseClientsNum;
	char serverCommandNum[4];
};

struct snapshot_t
{
	uint32_t snapFlags;
	int32_t ping;
	uint32_t serverTime;
	playerState_s ps;
	uint32_t numEntities;
	uint32_t numClients;
	entityState_s entities[256];
	clientState_s clients[64];
	char serverCommandSequence[4];
};

struct $_3765
{
	vec3_t adr;
	uint32_t challenge;
	uint32_t time;
	uint32_t pingTime;
	uint32_t firstTime;
	int32_t firstPing;
	int32_t connected;
	uint32_t guid;
};

struct ucmd_t
{
	char name[4];
	int32_t func;
};

struct uiClientState_t
{
	int32_t connState;
	uint32_t connectPacketCount;
	uint32_t clientNum;
	char servername[1024];
	char messageString[1024];
};

typedef enum
{
	ANIM_BP_UNUSED = 0,
	ANIM_BP_LEGS = 1,
	ANIM_BP_TORSO = 2,
	ANIM_BP_BOTH = 3,
	NUM_ANIM_BODYPARTS = 4
} animBodyPart_t;

typedef enum
{
	ANIM_ET_PAIN = 0,
	ANIM_ET_DEATH = 1,
	ANIM_ET_FIREWEAPON = 2,
	ANIM_ET_JUMP = 3,
	ANIM_ET_JUMPBK = 4,
	ANIM_ET_LAND = 5,
	ANIM_ET_DROPWEAPON = 6,
	ANIM_ET_RAISEWEAPON = 7,
	ANIM_ET_CLIMB_MOUNT = 8,
	ANIM_ET_CLIMB_DISMOUNT = 9,
	ANIM_ET_RELOAD = 10,
	ANIM_ET_CROUCH_TO_PRONE = 11,
	ANIM_ET_PRONE_TO_CROUCH = 12,
	ANIM_ET_STAND_TO_CROUCH = 13,
	ANIM_ET_CROUCH_TO_STAND = 14,
	ANIM_ET_STAND_TO_PRONE = 15,
	ANIM_ET_PRONE_TO_STAND = 16,
	ANIM_ET_MELEEATTACK = 17,
	ANIM_ET_SHELLSHOCK = 18,
	NUM_ANIM_EVENTTYPES = 19
} scriptAnimEventTypes_t;

struct $_3668
{
	scr_anim_s anim;
	char iNameHash[4];
	char szAnimName[64];
};

struct animStringItem_t
{
	char string[4];
	int32_t hash;
};

typedef enum
{
	AISTATE_NULL = -1,
	AISTATE_RELAXED = 0,
	AISTATE_QUERY = 1,
	AISTATE_ALERT = 2,
	AISTATE_COMBAT = 3,
	MAX_AISTATES = 4
} aistateEnum_t;

typedef enum
{
	ANIM_MT_UNUSED = 0,
	ANIM_MT_IDLE = 1,
	ANIM_MT_IDLECR = 2,
	ANIM_MT_IDLEPRONE = 3,
	ANIM_MT_WALK = 4,
	ANIM_MT_WALKBK = 5,
	ANIM_MT_WALKCR = 6,
	ANIM_MT_WALKCRBK = 7,
	ANIM_MT_WALKPRONE = 8,
	ANIM_MT_WALKPRONEBK = 9,
	ANIM_MT_RUN = 10,
	ANIM_MT_RUNBK = 11,
	ANIM_MT_RUNCR = 12,
	ANIM_MT_RUNCRBK = 13,
	ANIM_MT_TURNRIGHT = 14,
	ANIM_MT_TURNLEFT = 15,
	ANIM_MT_TURNRIGHTCR = 16,
	ANIM_MT_TURNLEFTCR = 17,
	ANIM_MT_CLIMBUP = 18,
	ANIM_MT_CLIMBDOWN = 19,
	ANIM_MT_MANTLE_ROOT = 20,
	ANIM_MT_MANTLE_UP_57 = 21,
	ANIM_MT_MANTLE_UP_51 = 22,
	ANIM_MT_MANTLE_UP_45 = 23,
	ANIM_MT_MANTLE_UP_39 = 24,
	ANIM_MT_MANTLE_UP_33 = 25,
	ANIM_MT_MANTLE_UP_27 = 26,
	ANIM_MT_MANTLE_UP_21 = 27,
	ANIM_MT_MANTLE_OVER_HIGH = 28,
	ANIM_MT_MANTLE_OVER_MID = 29,
	ANIM_MT_MANTLE_OVER_LOW = 30,
	ANIM_MT_FLINCH_FORWARD = 31,
	ANIM_MT_FLINCH_BACKWARD = 32,
	ANIM_MT_FLINCH_LEFT = 33,
	ANIM_MT_FLINCH_RIGHT = 34,
	ANIM_MT_STUMBLE_FORWARD = 35,
	ANIM_MT_STUMBLE_BACKWARD = 36,
	ANIM_MT_STUMBLE_WALK_FORWARD = 37,
	ANIM_MT_STUMBLE_WALK_BACKWARD = 38,
	ANIM_MT_STUMBLE_CROUCH_FORWARD = 39,
	ANIM_MT_STUMBLE_CROUCH_BACKWARD = 40,
	NUM_ANIM_MOVETYPES = 41
} scriptAnimMoveTypes_t;

struct animConditionTable_t
{
	int32_t type;
	int32_t values;
};

typedef enum
{
	ANIM_CONDTYPE_BITFLAGS = 0,
	ANIM_CONDTYPE_VALUE = 1,
	NUM_ANIM_CONDTYPES = 2
} animScriptConditionTypes_t;

struct kbutton_t
{
	uint64_t down;
	uint32_t downtime;
	int32_t msec;
	int8_t active;
	int8_t wasPressed;
};

struct ScreenPlacementGlob
{
	uint64_t scaleVirtualToReal;
	uint64_t scaleVirtualToFull;
	uint64_t scaleRealToVirtual;
	uint32_t virtualScreenOffsetX;
	uint64_t virtualViewableMin;
	uint64_t virtualViewableMax;
	vec2_t realViewportSize;
	uint64_t realViewableMin;
	uint64_t realViewableMax;
	int32_t subScreenLeft;
};

struct $_3716
{
	int32_t iLastUpdate;
	uint64_t vLastPos;
	int32_t fLastYaw;
	uint32_t pingTime;
	uint32_t beginFadeTime;
	int8_t enemy;
};

struct huffman_t
{
	huff_t compressor;
	uint8_t decompressor[28700];
};

struct stringDef_s
{
	int32_t next;
	int32_t str;
};

struct playerTeamState_t
{
	int32_t location;
};

struct clientSession_t
{
	int32_t sessionState;
	char forceSpectatorClient[4];
	char status_icon[4];
	uint32_t archiveTime;
	int32_t score;
	int32_t deaths;
	char scriptPersId[2];
	char pad0[2];
	int32_t connected;
	usercmd_s cmd;
	char oldcmd[28];
	int32_t localClient;
	int32_t predictItemPickup;
	char newnetname[32];
	int32_t maxHealth;
	uint32_t enterTime;
	playerTeamState_t teamState;
	char voteCount[4];
	char teamVoteCount[4];
	char viewmodelIndex[4];
	char noSpectate[4];
	char teamInfo[4];
	clientState_s cs;
	uint32_t psOffsetTime;
};

struct gclient_s
{
	playerState_s ps;
	clientSession_t sess;
	char spectatorClient[4];
	int32_t noclip;
	int32_t ufo;
	int32_t bFrozen;
	char lastCmdTime[4];
	int32_t buttons;
	int32_t oldbuttons;
	int32_t latched_buttons;
	int32_t buttonsSinceLastFrame;
	vec3_t oldOrigin;
	int32_t fGunPitch;
	int32_t fGunYaw;
	int32_t damage_blood;
	vec3_t damage_from;
	int32_t damage_fromWorld;
	uint32_t accurateCount;
	int32_t accuracy_shots;
	int32_t accuracy_hits;
	uint32_t inactivityTime;
	int32_t inactivityWarning;
	uint32_t lastVoiceTime;
	uint32_t switchTeamTime;
	int32_t currentAimSpreadScale;
	int32_t persistantPowerup;
	uint32_t portalID;
	uint32_t dropWeaponTime;
	uint32_t sniperRifleFiredTime;
	int32_t sniperRifleMuzzleYaw;
	char PCSpecialPickedUpCount[4];
	int32_t pLookatEnt;
	int32_t useHoldEntity;
	uint32_t useHoldTime;
	char iLastCompassFriendlyInfoEnt[4];
	uint32_t compassPingTime;
	uint32_t damageTime;
	int32_t v_dmg_roll;
	int32_t v_dmg_pitch;
	vec3_t swayViewAngles;
	vec3_t swayOffset;
	vec3_t swayAngles;
	vec3_t vLastMoveAng;
	float fLastIdleFactor;
	vec3_t vGunOffset;
	vec3_t vGunSpeed;
	uint32_t weapIdleTime;
	uint32_t lastServerTime;
	uint32_t lastSpawnTime;
};

struct turretInfo_s
{
	int32_t inuse;
	uint32_t flags;
	uint32_t fireTime;
	uint64_t arcmin;
	uint64_t arcmax;
	int32_t dropPitch;
	int32_t stance;
	int32_t prevStance;
	int32_t fireSndDelay;
	vec3_t userOrigin;
	int32_t playerSpread;
	int32_t pitchCap;
	int8_t fireSnd;
	int8_t fireSndPlayer;
	int8_t stopSnd;
	int8_t stopSndPlayer;
};

struct tagInfo_s
{
	int32_t parent;
	int32_t next;
	char name[2];
	char pad0[2];
	uint32_t index;
	vec3_t axis[4];
	vec3_t parentInvAxis[4];
};

typedef enum
{
	SESS_STATE_PLAYING = 0,
	SESS_STATE_DEAD = 1,
	SESS_STATE_SPECTATOR = 2,
	SESS_STATE_INTERMISSION = 3
} sessionState_t;

typedef enum
{
	CON_DISCONNECTED = 0,
	CON_CONNECTING = 1,
	CON_CONNECTED = 2
} clientConnected_t;

struct $_3761
{
	int32_t archivedFrame;
	uint32_t time;
	uint32_t num_entities;
	int32_t first_entity;
	uint32_t num_clients;
	int32_t first_client;
	int32_t usesDelta;
};

struct $_3772
{
	uint32_t numSnapshotEntities;
	int32_t snapshotEntities[1024];
};

typedef enum
{
	HITLOC_NONE = 0,
	HITLOC_HELMET = 1,
	HITLOC_HEAD = 2,
	HITLOC_NECK = 3,
	HITLOC_TORSO_UPR = 4,
	HITLOC_TORSO_LWR = 5,
	HITLOC_R_ARM_UPR = 6,
	HITLOC_L_ARM_UPR = 7,
	HITLOC_R_ARM_LWR = 8,
	HITLOC_L_ARM_LWR = 9,
	HITLOC_R_HAND = 10,
	HITLOC_L_HAND = 11,
	HITLOC_R_LEG_UPR = 12,
	HITLOC_L_LEG_UPR = 13,
	HITLOC_R_LEG_LWR = 14,
	HITLOC_L_LEG_LWR = 15,
	HITLOC_R_FOOT = 16,
	HITLOC_L_FOOT = 17,
	HITLOC_GUN = 18,
	HITLOC_NUM = 19
} hitLocation_t;

struct corpseInfo_t
{
	int32_t tree;
	uint32_t entnum;
	uint32_t time;
	clientInfo_t ci;
	int8_t falling;
};

struct BuiltinFunctionDef
{
	char actionString[4];
	int32_t actionFunc;
	int32_t type;
};

struct BuiltinMethodDef
{
	char actionString[4];
	int32_t actionFunc;
	int32_t type;
};

struct game_hudelem_s
{
	hudelem_s elem;
	uint32_t clientNum;
	int32_t team;
	int32_t archived;
};

typedef enum
{
	F_INT = 0,
	F_FLOAT = 1,
	F_LSTRING = 2,
	F_STRING = 3,
	F_VECTOR = 4,
	F_ENTITY = 5,
	F_VECTORHACK = 6,
	F_OBJECT = 7,
	F_MODEL = 8
} fieldtype_t;

struct ent_field_t
{
	char name[4];
	int32_t ofs;
	int32_t type;
	int32_t callback;
};

struct spawn_t
{
	char name[4];
	int32_t spawn;
};

struct keywordHash_s
{
	int32_t keyword;
	int32_t func;
	int32_t next;
};

struct entityHandler_t
{
	int32_t think;
	int32_t reached;
	int32_t blocked;
	int32_t touch;
	int32_t use;
	int32_t pain;
	int32_t die;
	int32_t controller;
	int32_t methodOfDeath;
	int32_t splashMethodOfDeath;
};

struct SpawnVar
{
	int8_t spawnVarsValid;
	char pad0[3];
	uint32_t numSpawnVars;
	uint8_t spawnVars[512];
	uint32_t numSpawnVarChars;
	uint8_t spawnVarChars[2048];
};

struct $_3703
{
	int32_t tree;
	uint32_t entnum;
	uint32_t time;
	clientInfo_t ci;
	int8_t falling;
};

struct game_hudelem_field_t
{
	char name[4];
	int32_t ofs;
	int32_t type;
	uint32_t mask;
	int32_t shift;
	int32_t setter;
	int32_t getter;
};

typedef enum
{
	HUDELEM_UPDATE_ARCHIVAL = 1,
	HUDELEM_UPDATE_CURRENT = 2,
	HUDELEM_UPDATE_ARCHIVAL_AND_CURRENT = 3
} hudelem_update_t;

struct UI_Component
{
	void *_vptr$UI_Component;
	vec2_t size;
	int32_t selectionParent;
};

struct UI_Component_data_t
{
	uint32_t screenWidth;
	int32_t screenHeight;
	uint32_t charWidth;
	int32_t charHeight;
	uint32_t scrollBarSize;
	int32_t cursor;
	uint64_t cursorPos;
	uint32_t hideCursor;
	int32_t filledCircle;
	int32_t consoleReason;
	char findText[128];
};

struct UI_ScrollPane
{
	char pad0[16];
	int32_t comp;
	int8_t forceHorScoll;
	char pad1[3];
	uint64_t mouseHeldScale;
	uint64_t mouseHeldPos;
	uint64_t mouseHeldCompPos;
	int16_t mouseWasDown;
};

struct UI_LinesComponent
{
	char pad0[16];
	int32_t selectedLine;
	int8_t focusOnSelectedLine;
	int8_t focusOnSelectedLineUser;
	char pad1[2];
	uint32_t numLines;
	uint64_t pos;
};

struct UI_VerticalDivider
{
	char pad0[16];
	int32_t topComp;
	int32_t bottomComp;
	uint32_t posY;
};

struct client_fields_s
{
	char name[4];
	int32_t ofs;
	int32_t type;
	int32_t setter;
	int32_t getter;
};

struct $_3717
{
	int32_t ent;
	vec3_t origin;
	vec3_t angles;
	int32_t deltayaw;
};

typedef enum
{
	HITLOC_NONE = 0,
	HITLOC_HELMET = 1,
	HITLOC_HEAD = 2,
	HITLOC_NECK = 3,
	HITLOC_TORSO_UPR = 4,
	HITLOC_TORSO_LWR = 5,
	HITLOC_R_ARM_UPR = 6,
	HITLOC_L_ARM_UPR = 7,
	HITLOC_R_ARM_LWR = 8,
	HITLOC_L_ARM_LWR = 9,
	HITLOC_R_HAND = 10,
	HITLOC_L_HAND = 11,
	HITLOC_R_LEG_UPR = 12,
	HITLOC_L_LEG_UPR = 13,
	HITLOC_R_LEG_LWR = 14,
	HITLOC_L_LEG_LWR = 15,
	HITLOC_R_FOOT = 16,
	HITLOC_L_FOOT = 17,
	HITLOC_GUN = 18,
	HITLOC_NUM = 19
} $_3579;

struct sbpicinfo_t
{
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
};

struct listColumnInfo_t
{
	int32_t type;
	uint32_t fWidth;
	char pszName[4];
	int32_t iAlignment;
};

typedef enum
{
	LCT_NAME = 0,
	LCT_CLAN = 1,
	LCT_SCORE = 2,
	LCT_DEATHS = 3,
	LCT_PING = 4,
	LCT_STATUS_ICON = 5,
	LCT_TALKING_ICON = 6,
	LCT_NUM = 7
} listColumnTypes_t;

struct weaponParms
{
	vec3_t forward;
	vec3_t right;
	vec3_t up;
	vec3_t muzzleTrace;
	vec3_t gunForward;
	int32_t weapDef;
};

struct AntilagClientStore
{
	uint8_t realClientPositions[768];
	uint8_t clientMoved[64];
};

struct ipFilter_s
{
	uint32_t mask;
	int32_t compare;
};

struct useList_t
{
	int32_t ent;
	int32_t score;
};

struct $_3731
{
	uint8_t rect[96];
	uint8_t rectClient[96];
	char name[4];
	int32_t group;
	char cinematicName[4];
	int32_t cinematic;
	int32_t style;
	int32_t border;
	int32_t ownerDraw;
	uint32_t ownerDrawFlags;
	uint32_t borderSize;
	uint32_t staticFlags;
	uint8_t dynamicFlags[16];
	vec3_t rectEffects0[8];
	vec3_t rectEffects1[8];
	uint8_t offsetTime[16];
	uint32_t nextTime;
	vec4_t foreColor;
	vec4_t backColor;
	vec4_t borderColor;
	vec4_t outlineColor;
	int32_t background;
};

struct $_3627
{
	uint32_t c_indexes;
	uint32_t c_fxIndexes;
	uint32_t c_viewIndexes;
	uint32_t c_shadowIndexes;
	int32_t c_vertexes;
	int32_t c_batches;
	void *c_refents;
	int32_t dc;
	Image_MemUsage c_imageUsage;
};

struct $_3826
{
	uint8_t frameSamples[512];
	uint32_t frameCount;
	uint8_t snapshotFlags[512];
	uint8_t snapshotSamples[512];
	uint32_t snapshotCount;
};

struct consoleCommand_t
{
	char cmd[4];
	int32_t function;
};

struct localEntity_s
{
	int32_t prev;
	int32_t next;
	int32_t leType;
	uint32_t endTime;
	trajectory_t pos;
	vec4_t color;
	int32_t tracerClipDist;
	GfxEntity refEntity;
};

typedef enum
{
	LE_MOVING_TRACER = 0
} leType_t;

struct cg_hudelem_t
{
	int32_t x;
	int32_t y;
	int32_t z;
	uint32_t width;
	int32_t height;
	uint8_t hudElemLabel[256];
	uint32_t labelWidth;
	char hudElemText[256];
	char textWidth[4];
	int32_t font;
	int32_t fontScale;
	int32_t fontHeight;
	vec4_t color;
};

struct hostent
{
	char h_name[4];
	char h_aliases[4];
	int32_t h_addrtype;
	uint32_t h_length;
	int32_t h_addr_list;
};

struct sockaddr
{
	uint8_t sa_len;
	int8_t sa_family;
	uint8_t sa_data[14];
};

struct timeval
{
	int32_t tv_sec;
	int32_t tv_usec;
};

struct fd_set
{
	uint8_t fds_bits[128];
};

struct in_addr
{
	int32_t s_addr;
};

struct sockaddr_in
{
	uint8_t sin_len;
	int8_t sin_family;
	uint16_t sin_port;
	in_addr sin_addr;
	uint64_t sin_zero;
};

struct jpeg_alloc
{
	int32_t malloc;
	int32_t free;
};

struct jpeg_compress_struct
{
	int32_t err;
	int32_t mem;
	int32_t progress;
	int32_t client_data;
	int8_t is_decompressor;
	char pad0[3];
	int32_t global_state;
	jpeg_alloc alloc;
	int32_t dest;
	uint32_t image_width;
	int32_t image_height;
	int32_t input_components;
	int32_t in_color_space;
	uint64_t input_gamma;
	int32_t data_precision;
	uint32_t num_components;
	int32_t jpeg_color_space;
	char comp_info[4];
	uint8_t quant_tbl_ptrs[16];
	uint8_t dc_huff_tbl_ptrs[16];
	uint8_t ac_huff_tbl_ptrs[16];
	uint8_t arith_dc_L[16];
	uint8_t arith_dc_U[16];
	uint8_t arith_ac_K[16];
	uint32_t num_scans;
	char scan_info[4];
	int8_t raw_data_in;
	int8_t arith_code;
	int8_t optimize_coding;
	int8_t CCIR601_sampling;
	float smoothing_factor;
	int32_t dct_method;
	int32_t restart_interval;
	int32_t restart_in_rows;
	int8_t write_JFIF_header;
	int8_t JFIF_major_version;
	int8_t JFIF_minor_version;
	int8_t density_unit;
	int16_t X_density;
	int16_t Y_density;
	int8_t write_Adobe_marker;
	char pad1[3];
	int32_t next_scanline;
	int8_t progressive_mode;
	char pad2[3];
	float max_h_samp_factor;
	float max_v_samp_factor;
	int32_t total_iMCU_rows;
	int32_t comps_in_scan;
	char cur_comp_info[16];
	int32_t MCUs_per_row;
	int32_t MCU_rows_in_scan;
	int32_t blocks_in_MCU;
	uint8_t MCU_membership[40];
	int32_t Ss;
	int32_t Se;
	int32_t Ah;
	int32_t Al;
	int32_t master;
	int32_t main;
	int32_t prep;
	int32_t coef;
	int32_t marker;
	int32_t cconvert;
	int32_t downsample;
	int32_t fdct;
	int32_t entropy;
	char script_space[4];
	char script_space_size[4];
};

typedef enum
{
	JCS_UNKNOWN = 0,
	JCS_GRAYSCALE = 1,
	JCS_RGB = 2,
	JCS_YCbCr = 3,
	JCS_CMYK = 4,
	JCS_YCCK = 5
} J_COLOR_SPACE;

typedef enum
{
	JDCT_ISLOW = 0,
	JDCT_IFAST = 1,
	JDCT_FLOAT = 2
} J_DCT_METHOD;

struct jpeg_error_mgr
{
	int32_t error_exit;
	char emit_message[4];
	char output_message[4];
	char format_message[4];
	int32_t reset_error_mgr;
	int32_t msg_code;
	uint8_t msg_parm[80];
	int32_t trace_level;
	uint32_t num_warnings;
	char jpeg_message_table[4];
	char last_jpeg_message[4];
	char addon_message_table[4];
	char first_addon_message[4];
	char last_addon_message[4];
	int32_t exit;
	int32_t printf;
};

struct jpeg_memory_mgr
{
	int32_t alloc_small;
	int32_t alloc_large;
	int32_t alloc_sarray;
	int32_t alloc_barray;
	int32_t request_virt_sarray;
	int32_t request_virt_barray;
	int32_t realize_virt_arrays;
	int32_t access_virt_sarray;
	int32_t access_virt_barray;
	int32_t free_pool;
	int32_t self_destruct;
	int32_t max_memory_to_use;
	int32_t max_alloc_chunk;
};

struct jpeg_progress_mgr
{
	int32_t progress_monitor;
	uint32_t pass_counter;
	int32_t pass_limit;
	int32_t completed_passes;
	int32_t total_passes;
};

struct jpeg_component_info
{
	uint32_t component_id;
	uint32_t component_index;
	float h_samp_factor;
	float v_samp_factor;
	int32_t quant_tbl_no;
	int32_t dc_tbl_no;
	int32_t ac_tbl_no;
	uint32_t width_in_blocks;
	int32_t height_in_blocks;
	uint32_t DCT_scaled_size;
	uint32_t downsampled_width;
	int32_t downsampled_height;
	int8_t component_needed;
	char pad0[3];
	uint32_t MCU_width;
	int32_t MCU_height;
	int32_t MCU_blocks;
	uint32_t MCU_sample_width;
	uint32_t last_col_width;
	int32_t last_row_height;
	int32_t quant_table;
	int32_t dct_table;
};

struct jpeg_comp_master
{
	int32_t prepare_for_pass;
	int32_t pass_startup;
	int32_t finish_pass;
	int8_t call_pass_startup;
	int8_t is_last_pass;
};

struct jpeg_c_main_controller
{
	int32_t start_pass;
	int32_t process_data;
};

struct jpeg_c_prep_controller
{
	int32_t start_pass;
	int32_t pre_process_data;
};

struct jpeg_c_coef_controller
{
	int32_t start_pass;
	int32_t compress_data;
};

struct jpeg_marker_writer
{
	int32_t write_file_header;
	int32_t write_frame_header;
	int32_t write_scan_header;
	int32_t write_file_trailer;
	int32_t write_tables_only;
	int32_t write_marker_header;
	int32_t write_marker_byte;
};

struct jpeg_color_converter
{
	int32_t start_pass;
	int32_t color_convert;
};

struct jpeg_downsampler
{
	int32_t start_pass;
	int32_t downsample;
	int8_t need_context_rows;
};

struct jpeg_forward_dct
{
	int32_t start_pass;
	int32_t forward_DCT;
};

struct jpeg_entropy_encoder
{
	int32_t start_pass;
	int32_t encode_mcu;
	int32_t finish_pass;
};

struct jpeg_scan_info
{
	int32_t comps_in_scan;
	uint8_t component_index[16];
	int32_t Ss;
	int32_t Se;
	int32_t Ah;
	int32_t Al;
};

union $_3723
{
	uint8_t i[32];
	uint8_t s[80];
};

struct JQUANT_TBL
{
	uint8_t quantval[128];
	int8_t sent_table;
};

struct JHUFF_TBL
{
	uint8_t bits[17];
	uint8_t huffval[256];
	int8_t sent_table;
};

struct jpeg_decompress_struct
{
	int32_t err;
	int32_t mem;
	int32_t progress;
	int32_t client_data;
	int8_t is_decompressor;
	char pad0[3];
	int32_t global_state;
	jpeg_alloc alloc;
	int32_t src;
	uint32_t image_width;
	int32_t image_height;
	uint32_t num_components;
	int32_t jpeg_color_space;
	int32_t out_color_space;
	uint32_t scale_num;
	int32_t scale_denom;
	uint64_t output_gamma;
	int8_t buffered_image;
	int8_t raw_data_out;
	char pad1[2];
	int32_t dct_method;
	int8_t do_fancy_upsampling;
	int8_t do_block_smoothing;
	int8_t quantize_colors;
	char pad2[1];
	int32_t dither_mode;
	int8_t two_pass_quantize;
	char pad3[3];
	uint32_t desired_number_of_colors;
	int8_t enable_1pass_quant;
	int8_t enable_external_quant;
	int8_t enable_2pass_quant;
	char pad4[1];
	uint32_t output_width;
	int32_t output_height;
	int32_t out_color_components;
	int32_t output_components;
	void *rec_outbuf_height;
	uint32_t actual_number_of_colors;
	int32_t colormap;
	int32_t output_scanline;
	uint32_t input_scan_number;
	int32_t input_iMCU_row;
	uint32_t output_scan_number;
	int32_t output_iMCU_row;
	int32_t coef_bits;
	uint8_t quant_tbl_ptrs[16];
	uint8_t dc_huff_tbl_ptrs[16];
	uint8_t ac_huff_tbl_ptrs[16];
	int32_t data_precision;
	char comp_info[4];
	int8_t progressive_mode;
	int8_t arith_code;
	uint8_t arith_dc_L[16];
	uint8_t arith_dc_U[16];
	uint8_t arith_ac_K[16];
	char pad5[2];
	int32_t restart_interval;
	int8_t saw_JFIF_marker;
	int8_t JFIF_major_version;
	int8_t JFIF_minor_version;
	int8_t density_unit;
	int16_t X_density;
	int16_t Y_density;
	int8_t saw_Adobe_marker;
	int8_t Adobe_transform;
	int8_t CCIR601_sampling;
	char pad6[1];
	int32_t marker_list;
	float max_h_samp_factor;
	float max_v_samp_factor;
	uint32_t min_DCT_scaled_size;
	int32_t total_iMCU_rows;
	int32_t sample_range_limit;
	int32_t comps_in_scan;
	char cur_comp_info[16];
	int32_t MCUs_per_row;
	int32_t MCU_rows_in_scan;
	int32_t blocks_in_MCU;
	uint8_t MCU_membership[40];
	int32_t Ss;
	int32_t Se;
	int32_t Ah;
	int32_t Al;
	int32_t unread_marker;
	int32_t master;
	int32_t main;
	int32_t coef;
	uint32_t post;
	int32_t inputctl;
	int32_t marker;
	int32_t entropy;
	uint32_t idct;
	int32_t upsample;
	int32_t cconvert;
	int32_t cquantize;
};

typedef enum
{
	JDITHER_NONE = 0,
	JDITHER_ORDERED = 1,
	JDITHER_FS = 2
} J_DITHER_MODE;

struct jpeg_source_mgr
{
	int32_t next_input_byte;
	void *bytes_in_buffer;
	int32_t init_source;
	void *fill_input_buffer;
	int32_t skip_input_data;
	int32_t resync_to_restart;
	int32_t term_source;
};

struct jpeg_marker_struct
{
	int32_t next;
	int8_t marker;
	char pad0[3];
	uint32_t original_length;
	uint32_t data_length;
	int32_t data;
};

struct jpeg_decomp_master
{
	int32_t prepare_for_output_pass;
	int32_t finish_output_pass;
	int8_t is_dummy_pass;
};

struct jpeg_d_main_controller
{
	int32_t start_pass;
	int32_t process_data;
};

struct jpeg_d_coef_controller
{
	int32_t start_input_pass;
	int32_t consume_data;
	int32_t start_output_pass;
	int32_t decompress_data;
	int32_t coef_arrays;
};

struct jpeg_d_post_controller
{
	int32_t start_pass;
	uint32_t post_process_data;
};

struct jpeg_input_controller
{
	int32_t consume_input;
	int32_t reset_input_controller;
	int32_t start_input_pass;
	int32_t finish_input_pass;
	int8_t has_multiple_scans;
	int8_t eoi_reached;
};

struct jpeg_marker_reader
{
	int32_t reset_marker_reader;
	int32_t read_markers;
	int32_t read_restart_marker;
	int8_t saw_SOI;
	int8_t saw_SOF;
	char pad0[2];
	uint32_t next_restart_num;
	int32_t discarded_bytes;
};

struct jpeg_entropy_decoder
{
	int32_t start_pass;
	int32_t decode_mcu;
	int8_t insufficient_data;
};

struct jpeg_inverse_dct
{
	int32_t start_pass;
	uint8_t inverse_DCT[40];
};

struct jpeg_upsampler
{
	int32_t start_pass;
	int32_t upsample;
	int8_t need_context_rows;
};

struct jpeg_color_deconverter
{
	int32_t start_pass;
	int32_t color_convert;
};

struct jpeg_color_quantizer
{
	int32_t start_pass;
	int32_t color_quantize;
	int32_t finish_pass;
	int32_t new_color_map;
};

struct $_3831
{
	int32_t mssSample;
	void *mssBuffer;
	int32_t frequency;
	int32_t volume;
	int32_t pan;
	int32_t channels;
	int8_t playing;
	char pad0[3];
	int32_t channel;
	int8_t playMode;
};

struct dsound_sample_t
{
	int32_t mssSample;
	void *mssBuffer;
	int32_t frequency;
	int32_t volume;
	int32_t pan;
	int32_t channels;
	int8_t playing;
	char pad0[3];
	int32_t channel;
	int8_t playMode;
};

struct audioSample_t
{
	void *buffer;
	uint32_t lengthInBytes;
	uint32_t lengthInSamples;
	int32_t bytesPerSample;
	int32_t frequency;
	int8_t stereo;
	char pad0[3];
	int32_t channels;
	uint32_t sampleOffset;
};

struct SpeexMode
{
	int32_t mode;
	int32_t query;
	char modeName[4];
	uint32_t modeID;
	char bitstream_version[4];
	int32_t enc_init;
	int32_t enc_destroy;
	int32_t enc;
	int32_t dec_init;
	int32_t dec_destroy;
	int32_t dec;
	int32_t enc_ctl;
	int32_t dec_ctl;
};

struct SpeexBits
{
	int32_t chars;
	int32_t nbBits;
	void *charPtr;
	void *bitPtr;
	int32_t owner;
	int32_t overflow;
	uint32_t buf_size;
	int32_t reserved1;
	int32_t reserved2;
};

struct ltp_params
{
	int32_t gain_cdbk;
	int32_t gain_bits;
	int32_t pitch_bits;
};

struct split_cb_params
{
	uint32_t subvect_size;
	int32_t nb_subvect;
	int32_t shape_cb;
	int32_t shape_bits;
	int32_t have_sign;
};

struct SpeexSubmode
{
	int32_t lbr_pitch;
	int32_t forced_pitch_gain;
	int32_t have_subframe_gain;
	int32_t double_codebook;
	int32_t lsp_quant;
	int32_t lsp_unquant;
	int32_t ltp_quant;
	int32_t ltp_unquant;
	int32_t ltp_params;
	int32_t innovation_quant;
	int32_t innovation_unquant;
	int32_t innovation_params;
	int32_t lpc_enh_k1;
	int32_t lpc_enh_k2;
	int32_t lpc_enh_k3;
	int32_t comb_gain;
	int32_t bits_per_frame;
};

struct SpeexNBMode
{
	uint32_t frameSize;
	uint32_t subframeSize;
	uint32_t lpcSize;
	int32_t pitchStart;
	int32_t pitchEnd;
	int32_t gamma1;
	int32_t gamma2;
	float lag_factor;
	int32_t lpc_floor;
	uint8_t submodes[64];
	int32_t defaultSubmode;
	uint8_t quality_map[44];
};

struct SpeexSBMode
{
	int32_t nb_mode;
	uint32_t frameSize;
	uint32_t subframeSize;
	uint32_t lpcSize;
	uint32_t bufSize;
	int32_t gamma1;
	int32_t gamma2;
	float lag_factor;
	int32_t lpc_floor;
	int32_t folding_gain;
	uint8_t submodes[32];
	int32_t defaultSubmode;
	uint8_t low_quality_map[44];
	uint8_t quality_map[44];
	int32_t vbr_thresh;
	int32_t nb_modes;
};

struct SBEncState
{
	int32_t mode;
	int32_t st_low;
	uint32_t full_frame_size;
	uint32_t frame_size;
	uint32_t subframeSize;
	int32_t nbSubframes;
	uint32_t windowSize;
	uint32_t lpcSize;
	uint32_t bufSize;
	int32_t first;
	float lag_factor;
	int32_t lpc_floor;
	int32_t gamma1;
	int32_t gamma2;
	int32_t stack;
	int32_t x0d;
	int32_t x1d;
	int32_t high;
	int32_t y0;
	int32_t y1;
	int32_t h0_mem;
	int32_t h1_mem;
	int32_t g0_mem;
	int32_t g1_mem;
	void *excBuf;
	int32_t exc;
	void *buf;
	int32_t res;
	int32_t sw;
	int32_t target;
	int32_t window;
	int32_t lagWindow;
	int32_t autocorr;
	int32_t lpc;
	int32_t lsp;
	int32_t qlsp;
	int32_t old_lsp;
	int32_t old_qlsp;
	int32_t interp_lsp;
	int32_t interp_qlsp;
	int32_t interp_lpc;
	int32_t interp_qlpc;
	int32_t bw_lpc1;
	int32_t bw_lpc2;
	int32_t mem_sp;
	int32_t mem_sp2;
	int32_t mem_sw;
	int32_t pi_gain;
	int32_t vbr_quality;
	int32_t vbr_enabled;
	int32_t abr_enabled;
	int32_t abr_drift;
	int32_t abr_drift2;
	uint32_t abr_count;
	int32_t vad_enabled;
	int32_t relative_quality;
	int32_t encode_submode;
	int32_t submodes;
	uint32_t submodeID;
	int32_t submodeSelect;
	int32_t complexity;
	int32_t sampling_rate;
};

struct SBDecState
{
	int32_t mode;
	int32_t st_low;
	uint32_t full_frame_size;
	uint32_t frame_size;
	uint32_t subframeSize;
	int32_t nbSubframes;
	uint32_t lpcSize;
	int32_t first;
	int32_t sampling_rate;
	int32_t lpc_enh_enabled;
	int32_t stack;
	int32_t x0d;
	int32_t x1d;
	int32_t high;
	int32_t y0;
	int32_t y1;
	int32_t g0_mem;
	int32_t g1_mem;
	int32_t exc;
	int32_t qlsp;
	int32_t old_qlsp;
	int32_t interp_qlsp;
	int32_t interp_qlpc;
	int32_t mem_sp;
	int32_t pi_gain;
	int32_t encode_submode;
	int32_t submodes;
	uint32_t submodeID;
};

struct CombFilterMem
{
	int32_t last_pitch;
	vec3_t last_pitch_gain;
	int32_t smooth_gain;
};

struct EncState
{
	int32_t mode;
	int32_t first;
	uint32_t frameSize;
	uint32_t subframeSize;
	int32_t nbSubframes;
	uint32_t windowSize;
	uint32_t lpcSize;
	int32_t min_pitch;
	int32_t max_pitch;
	int32_t safe_pitch;
	int32_t bounded_pitch;
	int32_t ol_pitch;
	int32_t ol_voiced;
	int32_t pitch;
	int32_t gamma1;
	int32_t gamma2;
	float lag_factor;
	int32_t lpc_floor;
	int32_t stack;
	void *inBuf;
	int32_t frame;
	void *excBuf;
	int32_t exc;
	void *swBuf;
	int32_t sw;
	int32_t innov;
	int32_t window;
	int32_t autocorr;
	int32_t lagWindow;
	int32_t lpc;
	int32_t lsp;
	int32_t qlsp;
	int32_t old_lsp;
	int32_t old_qlsp;
	int32_t interp_lsp;
	int32_t interp_qlsp;
	int32_t interp_lpc;
	int32_t interp_qlpc;
	int32_t bw_lpc1;
	int32_t bw_lpc2;
	int32_t mem_sp;
	int32_t mem_sw;
	int32_t mem_sw_whole;
	int32_t mem_exc;
	int32_t pi_gain;
	int32_t vbr;
	int32_t vbr_quality;
	int32_t relative_quality;
	int32_t vbr_enabled;
	int32_t vad_enabled;
	int32_t dtx_enabled;
	uint32_t dtx_count;
	int32_t abr_enabled;
	int32_t abr_drift;
	int32_t abr_drift2;
	uint32_t abr_count;
	int32_t complexity;
	int32_t sampling_rate;
	int32_t plc_tuning;
	int32_t encode_submode;
	int32_t submodes;
	uint32_t submodeID;
	int32_t submodeSelect;
};

struct VBRState
{
	int32_t energy_alpha;
	int32_t average_energy;
	int32_t last_energy;
	uint8_t last_log_energy[20];
	int32_t accum_sum;
	int32_t last_pitch_coef;
	int32_t soft_pitch;
	int32_t last_quality;
	int32_t noise_level;
	int32_t noise_accum;
	uint32_t noise_accum_count;
	int32_t consec_noise;
};

struct SpeexCallback
{
	uint32_t callback_id;
	int32_t func;
	int32_t data;
	int32_t reserved1;
	int32_t reserved2;
};

struct DecState
{
	int32_t mode;
	int32_t first;
	uint32_t count_lost;
	uint32_t frameSize;
	uint32_t subframeSize;
	int32_t nbSubframes;
	uint32_t lpcSize;
	int32_t min_pitch;
	int32_t max_pitch;
	int32_t sampling_rate;
	int32_t last_ol_gain;
	int32_t stack;
	void *inBuf;
	int32_t frame;
	void *excBuf;
	int32_t exc;
	int32_t innov;
	int32_t qlsp;
	int32_t old_qlsp;
	int32_t interp_qlsp;
	int32_t interp_qlpc;
	int32_t mem_sp;
	int32_t pi_gain;
	int32_t last_pitch;
	int32_t last_pitch_gain;
	vec3_t pitch_gain_buf;
	void *pitch_gain_buf_idx;
	int32_t encode_submode;
	int32_t submodes;
	uint32_t submodeID;
	int32_t lpc_enh_enabled;
	int32_t comb_mem;
	uint8_t speex_callbacks[320];
	SpeexCallback user_callback;
	int32_t voc_m1;
	int32_t voc_m2;
	int32_t voc_mean;
	uint32_t voc_offset;
	int32_t dtx_enabled;
};

struct CCircularBuffer
{
	void *mBuffer;
	uint32_t mBufferSize;
	uint32_t mReadPosition;
	uint32_t mReadSize;
	uint32_t mWritePosition;
};

struct $_3658
{
	void *buffer;
	uint32_t lengthInBytes;
	uint32_t lengthInSamples;
	int32_t bytesPerSample;
	int32_t frequency;
	int8_t stereo;
	char pad0[3];
	int32_t channels;
	uint32_t sampleOffset;
};

struct CAudioRecorder
{
	uint64_t mSampleRate;
	uint32_t mNumChannels;
	int32_t mBitsPerChannel;
	int32_t mInputDevice;
	int32_t mInputUnit;
	int8_t mRecording;
	int8_t mMuteInput;
	char pad0[2];
	int32_t mInputVolume;
	CMutex mMutex;
	void *mConverterRef;
	void *mConvertBuffer;
	uint32_t mConvertBufferSize;
	void *mRenderBuffer;
	uint32_t mRenderBufferSize;
	CCircularBuffer mBuffer;
	int8_t mBufferIsFull;
};

struct internal_state
{
	int32_t dummy;
};

struct inflate_blocks_state
{
	int32_t mode;
	uint8_t sub[20];
	int32_t last;
	int32_t bitk;
	int32_t bitb;
	int32_t hufts;
	int32_t window;
	int32_t end;
	int32_t read;
	int32_t write;
	int32_t checkfn;
	int32_t check;
};

struct jpeg_common_struct
{
	int32_t err;
	int32_t mem;
	int32_t progress;
	int32_t client_data;
	int8_t is_decompressor;
	char pad0[3];
	int32_t global_state;
	jpeg_alloc alloc;
};

struct inflate_huft_s
{
	int32_t word;
	int32_t base;
};

struct inflate_codes_state
{
	int32_t dummy;
};

typedef enum
{
	JBUF_PASS_THRU = 0,
	JBUF_SAVE_SOURCE = 1,
	JBUF_CRANK_DEST = 2,
	JBUF_SAVE_AND_PASS = 3
};

union small_pool_struct
{
	vec3_t hdr;
	uint64_t dummy;
};

struct jvirt_barray_control
{
	void *mem_buffer;
	int32_t rows_in_array;
	int32_t blocksperrow;
	int32_t maxaccess;
	int32_t rows_in_mem;
	int32_t rowsperchunk;
	int32_t cur_start_row;
	int32_t first_undef_row;
	int8_t pre_zero;
	int8_t dirty;
	int8_t b_s_open;
	char pad0[1];
	int32_t next;
	char b_s_info[80];
};

struct backing_store_struct
{
	int32_t read_backing_store;
	int32_t write_backing_store;
	int32_t close_backing_store;
	int32_t temp_file;
	char temp_name[64];
};

union large_pool_struct
{
	vec3_t hdr;
	uint64_t dummy;
};

#pragma pack(pop)
