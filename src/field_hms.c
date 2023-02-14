#include "../include/types.h"
#include "../include/common_scr_def.h"
#include "../include/field_sys.h"


u16 EvCheck_TalkMapAttr(struct FIELDSYS_WORK *repw, void *matr)
{
    int dir = Player_DirGet(repw->player);

    if (MATR_IsPC(matr) && dir == 2) { // facing up
        return SCRID_PC_ON;
    }else if (MATR_IsLittleBookRack01(matr)) {
        return SCRID_LITTLE_RACK1;
    }else if (MATR_IsLittleBookRack02(matr)) {
        return SCRID_LITTLE_RACK2;
    }else if (MATR_IsBookRack01(matr)) {
        return SCRID_RACK1;
    }else if (MATR_IsBookRack02(matr)) {
        return SCRID_RACK2;
    }else if (MATR_IsTrashBox(matr)) {
        return SCRID_TRASH_BOX;
    }else if (MATR_IsShopBookRack01(matr)) {
        return SCRID_SHOP_RACK1;
    }else if (MATR_IsShopBookRack02(matr)) {
        return SCRID_SHOP_RACK2;
    }else if (MATR_IsShopBookRack03(matr)) {
        return SCRID_SHOP_RACK3;
    }else if (MATR_IsWaterFall(matr)) {
        return SCRID_HIDEN_TAKINOBORI;
    }else if (MATR_IsMap(matr)) {
        return SCRID_TMAP_BG;
    }else if (MATR_IsBumpPost(matr)) {
        return SCRID_BUMP_POST;
    }else if (MATR_IsTV(matr) && dir == 2) {
        return SCRID_TV;
    }

    if (Player_EventAttrCheck_KabeNobori(matr,dir))
	{
        return SCRID_HIDEN_KABENOBORI;
    }

    if (Player_FormGet(repw->player) != 2) // if player is not surfing
	{
        void *mystatus = SaveData_GetMyStatus(repw->savedata);
        u32 natr = Player_TwThinkNowAttrGet(repw->player);
        if (Player_EventAttrCheck_Naminori(repw->player, natr, matr)
         && MyStatus_GetBadgeFlag(mystatus, 3)) // badge 6
		{
            //if (EvPoke_CheckWaza(SaveData_GetTemotiPokemon(repw->savedata), 57) != 0xff) // check if party knows surf
			if (MyItem_CheckItem(SaveData_GetMyItem(repw->savedata), 422, 1, 0) != 0)
			{
                return SCRID_HIDEN_NAMINORI;
            }
        }
    }
    
    return (u16)~0;
}
