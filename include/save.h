#ifndef SAVE_H
#define SAVE_H

#include "types.h"

/*******************************/
/* Save data related functions */
/* and structs/globals/enums   */
/* If you add more functions,  */
/* please commit them to the   */
/* repo                        */
/*******************************/

struct save_dex_data
{
	u32 unk0;
	u32 get_flag[32];
	u32 see_flag[32];
	u32 unk1;
	u8 unk2;
	u8 unk3;
	u8 unk4;
	u8 unk5;
	u8 unk6[28];
	u8 TextVersionUp[496];
	u8 GraphicVersionUp;
	u8 unk7;
	u8 dex_get;
    u8 unk8;
	u32 unk9;		
	u8 unk10;
	u8 unk11;
	u8 unused;
    u8 repel;
};

void *__attribute__((long_call)) SaveData_GetEventWork(void *);
struct save_dex_data *__attribute__((long_call)) SaveData_GetDexPtr(void *);
u16 *__attribute__((long_call)) GetEventVar(void *a1, u16 work_no);
u8 *__attribute__((long_call)) SaveData_GetRepelPtr(void *a1);
void *__attribute__((long_call)) GetSaveDataPtr(void *a1);

#endif
