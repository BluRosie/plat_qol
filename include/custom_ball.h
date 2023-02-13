#include "types.h"

#define CB_DEF_SEAL_MAX (8)

typedef struct _CUSTOM_BALL_CORE		CB_CORE;
typedef struct _CUSTOM_BALL_SEAL		CB_SEAL;

struct __attribute__((packed)) _CUSTOM_BALL_SEAL {
	
	u8	seal_id;		///< シール番号
	u8	x;				///< x 座標
	u8	y;				///< y 座標
	
};

struct __attribute__((packed)) _CUSTOM_BALL_CORE {

	CB_SEAL	cb_seal[ CB_DEF_SEAL_MAX ];

};

void __attribute__((long_call))CB_Tool_CoreData_Copy(const CB_CORE* from, CB_CORE* to);
