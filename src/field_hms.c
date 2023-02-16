#include "../include/types.h"
#include "../include/pad.h"
#include "../include/common_scr_def.h"
#include "../include/ev_check.h"
#include "../include/field_sys.h"
#include "../include/pokemon.h"
#include "../include/moves.h"
#include "../include/item.h"


u16 EvCheck_TalkMapAttr(struct FIELDSYS_WORK *repw, void *matr)
{
    int dir = Player_DirGet(repw->player);

    if (MATR_IsPC(matr) && dir == 0) { // facing up
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
    }else if (MATR_IsTV(matr) && dir == 0) {
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


void ClearReq(EV_REQUEST *req)
{
    req->TalkCheck  = FALSE;
    req->StepCheck  = FALSE;
    req->MenuOpen   = FALSE;
    req->CnvButton  = FALSE;
    req->MatCheck   = FALSE;
    req->PushCheck  = FALSE;
    req->MoveCheck  = FALSE;
    req->FloatCheck = FALSE;
    req->FlyCheck   = FALSE; // check if fly needs to be open

    req->DebugMenu   = FALSE;
    req->DebugBattle = FALSE;

    req->DebugHook = FALSE;
    req->DebugKeyPush = FALSE;
    
    req->Site = DIR_NOT;
    req->PushSite = DIR_NOT;
}

void SetReq(EV_REQUEST *req, u16 trg)
{
    if( trg & PAD_BUTTON_SELECT ){
        req->FlyCheck = TRUE;
    }
}

int CheckReq(const EV_REQUEST *req, struct FIELDSYS_WORK *repw)
{
    if( req->FlyCheck )
    {
        EventSet_Script(repw, SCRID_PC_ON, NULL);
        return TRUE;
    }
    return FALSE;
}


struct HM_LIST_PRIORITY
{
    u16 move;
    u16 distance;
};

// prioritize listing fly and defog over all else because those can't actually be selected from the overworld
struct HM_LIST_PRIORITY HMList[] =
{
    {MOVE_FLY, 1},
    {MOVE_DEFOG, 4},
    {MOVE_CUT, 0},
    {MOVE_SURF, 2},
    {MOVE_STRENGTH, 3},
    {MOVE_ROCK_SMASH, 5},
    {MOVE_WATERFALL, 6},
    {MOVE_ROCK_CLIMB, 7},
};


u32 __attribute__((long_call)) PokeList_WazaMenuIDGet(u16 move);
void __attribute__((long_call)) PokeList_WazaMenuStrGet(struct PLIST_WORK *wk, u32 move, u32 index);

u8 FieldModeMenuMake(struct PLIST_WORK *wk, u8 *prm)
{
    POKEMON_PARAM * pp = PokeParty_GetMemberPointer(wk->dat->pp, wk->pos);
    u16 waza;
    u8  h=0, i, j=0, mid;
    u8 buf[64];

    prm[j] = 1; // status
    j++;
    if (BtlTower_IsSalon(wk->dat->fsys) == FALSE)
    {
        if (wk->panel[wk->pos].egg == 0)
        {
            //for( i=0; i<4; i++ ){
            //    waza = (u16)PokeParaGet( pp, ID_PARA_waza1+i, NULL );
            //    if( waza == 0 ){ break; }
            //    mid = PokeList_WazaMenuIDGet( waza );
            //
            //    if( mid != 0xff ){
            //        prm[j] = mid;
            //        j++;
            //        PokeList_WazaMenuStrGet( wk, waza, h );
            //        h++;
            //    }
            //}
            u32 species = PokeParaGet(pp, ID_PARA_monsno, NULL);
            u32 form = PokeParaGet(pp, ID_PARA_form_no, NULL);
            for (i = 0; i < 8; i++)
            {
                if (PokeWazaMachineCheck(species, form, 92+HMList[i].distance) != 0) // hm01 = tm93
                {
                    waza = HMList[i].move;
                    mid = PokeList_WazaMenuIDGet(waza);
                    if (mid != 0xFF)
                    {
                        prm[j] = mid;
                        j++;
                        PokeList_WazaMenuStrGet(wk, waza, h);
                        h++;
                    }
                    if (h == 4) break;
                }
            }
            prm[j] = 0;
            j++;
            if (ItemMailCheck(wk->panel[wk->pos].item ) == TRUE)
            {
                prm[j] = 5; // mail
            }
            else
            {
                prm[j] = 2; // item
            }
            j++;
        }
        else
        {
            prm[j] = 0; // row
            j++;
        }
    }
    prm[j] = 9; // cancel
    j++;

    return (j);
}
