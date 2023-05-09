#include <stdint.h>

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
} _D3DQUERYTYPE;

