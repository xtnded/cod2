#include <stdio.h>
#include <stddef.h>

struct msg_t {
  int overflowed;
  int data;
  int maxsize;
  int cursize;
  int readcount;
  int bit;
};

typedef enum {
  NA_BOT = 0,
  NA_BAD = 1,
  NA_LOOPBACK = 2,
  NA_BROADCAST = 3,
  NA_IP = 4
} netadrtype_t;
typedef enum {
  NS_CLIENT1 = 0,
  NS_SERVER = 1,
  NS_MAXCLIENTS = 1,
  NS_PACKET = 2
} netsrc_t;
struct netadr_t {
  netadrtype_t type;
  int ip;
  short port;
};
struct netchan_t {
  int outgoingSequence;
  netsrc_t sock;
  int dropped;
  int incomingSequence;
  netadr_t remoteAddress;
  int qport;
  int fragmentSequence;
  int fragmentLength;
  char fragmentBuffer[16384];
  int unsentFragments;
  int unsentFragmentStart;
  int unsentLength;
  char unsentBuffer[16384];
  int pProf;
};
struct field_t {
  int cursor;
  int scroll;
  int drawWidth;
  int widthInPixels;
  int charHeight;
  int fixedSize;
  char buffer[256];
};
struct sysEvent_t //_3728
{
  int evTime;
  sysEventType_t evType;
  int evValue;
  int evValue2;
  int evPtrLength;
  int evPtr;
};

typedef enum {
  SE_NONE = 0,
  SE_KEY = 1,
  SE_CHAR = 2,
  SE_GAMEPAD_AXIS = 3,
  SE_CONSOLE = 4,
  SE_PACKET = 5
} sysEventType_t;

typedef struct nodetype {
  int left;
  int right;
  int parent;
  int next;
  int prev;
  int head;
  int weight;
  int symbol;
} node_t;

#define HMAX 256 /* Maximum symbol */

typedef struct {
  int blocNode;
  int blocPtrs;
  int tree;
  int lhead;
  int ltail;
  char loc[1028];
  int freelist;
  char nodeList[24576];
  node_t *nodePtrs[768]; // char nodePtrs[3072];
} huff_t;

typedef struct {
  huff_t compressor;
  huff_t decompressor; // char decompressor[28700];
} huffman_t;


#define THREAD_CONTEXT_MAIN 0
#define THREAD_CONTEXT_DATABASE 1
enum ThreadValue
{
	THREAD_VALUE_PROF_STACK,
	THREAD_VALUE_VA,
	THREAD_VALUE_COM_ERROR,
	THREAD_VALUE_TRACE,
	THREAD_VALUE_COUNT
};

size_t FS_FileRead(void *buffer, size_t size, size_t count, FILE *stream);
size_t FS_FileWrite(const void *buffer, size_t size, size_t count, FILE *stream);
FILE *FS_FileOpen(const char *filename, const char *mode);
int FS_FileClose(FILE *stream);
int FS_FileSeek(FILE *stream, long offset, int origin);
