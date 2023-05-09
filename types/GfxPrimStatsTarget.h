#include <stdint.h>

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

