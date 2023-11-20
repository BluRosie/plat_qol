#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <sys/types.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t    s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef volatile u8   vu8;
typedef volatile uint16_t vu16;
typedef volatile uint32_t vu32;
typedef volatile u64 vu64;
typedef volatile s8   vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

#define NULL                ((void *)0)

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

typedef float  f32;
typedef double f64;
typedef s32 fx32;

typedef u8  bool8;
typedef int  BOOL;
typedef u16 bool16;
typedef u32 bool32;

typedef u16 species_t;
typedef u16 move_t;
typedef u8  ability_t;
typedef u16 item_t;
typedef u8  item_effect_t;
typedef u8  bank_t;
typedef u8  move_effect_t;

typedef struct
{
    fx32    x;
    fx32    y;
    fx32    z;
}
VecFx32;

typedef u16 STRCODE;
typedef	u16		PMS_WORD;

typedef enum NNSSndArcStrmCallbackStatus
{
    NNS_SND_ARC_STRM_CALLBACK_DATA_END
} NNSSndArcStrmCallbackStatus;

typedef struct NNSSndArcStrmCallbackInfo
{
    int playerNo;
    int strmNo;
} NNSSndArcStrmCallbackInfo;

typedef struct NNSSndArcStrmCallbackParam
{
    int strmNo;
    u32 offset;
} NNSSndArcStrmCallbackParam;

typedef struct _STRBUF	STRBUF;
struct _STRBUF {
	u16  size;			
	u16  strlen;		
	u32  magicNumber;	///< 正常に初期化済みであることをチェックするためのナンバー

	STRCODE  buffer[1];	
};
#define EOM_			0xff

#define FALSE           (0)
#define TRUE            (1)


#define LONG_CALL __attribute__((long_call))


#endif
