#include "types.h"

typedef enum {
	HEAPID_BASE_SYSTEM,
	HEAPID_BASE_SAVE,
	_HEAPID_BASE_DEBUG,
	HEAPID_BASE_APP,

	HEAPID_BASE_MAX,
}BASE_HEAPID;

void* __attribute__((long_call)) sys_AllocMemory( u32 heapID, u32 size );
void __attribute__((long_call)) sys_FreeMemoryEz( void* memory );
void __attribute__((long_call)) MIi_CpuClearFast(u32 data, void *destp, u32 size);