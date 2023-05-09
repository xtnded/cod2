#include <stdint.h>

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

