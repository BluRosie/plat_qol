#ifndef FIELD_SYS_INCLUDE
#define FIELD_SYS_INCLUDE

// from https://github.com/gainax3/retsam_00jupc/blob/main/src/field/fieldsys.h

struct FIELDSYS_WORK
{
    u8 pad_x0[0xC];
    //CONTROL_WORK * ctrl;
    //FIELDMAP_WORK * fldmap;
    //GF_BGL_INI * bgl;
    void *savedata;
    u8 pad_x10[0x2C];
    //GMEVENT_CONTROL * event;
    //EVENT_DATA * eventdata;
    //FIELD_SUBSCRN_TYPE subscreen;
    //LOCATION_WORK * location;
    //FIELD_CAMERA_TYPE camera_type;
    //GF_CAMERA_PTR   camera_ptr;
    //DMC_PTR map_cont_dat;
    //WORLD_MAP_PTR World;
    //MAP_RESOURCE_PTR MapResource;
    //MMDL_WORK * mmdl;
    //FIELD_OBJ_SYS_PTR fldobjsys;
    void *player;
    //u8 pad_x40[];
    //FE_SYS *fes;
    //GLST_DATA_PTR       glst_data;
    //FOG_DATA_PTR        fog_data;
    //LIGHT_CONT_PTR      light_cont_data;
    //FLD_3D_ANM_MNG_PTR  field_3d_anime;
    //ANIME_CONT_MNG_PTR  AnimeContMng;
    //SMD_PTR             SpMatData;
    //MTL_CONST_PTR       map_tool_list;
    //DIV_MAP_MODE        DivMapMode;
    //BOARD_WORK * board;
    //BOOL    main_mode_flag;
    //UG_RADAR_WORK    *UnderGroundRadar;
    //MAP_MODE MapMode;
    //const MAP_MODE_DATA * MapModeData;
    //ENCOUNT_CHECK   encount;
    //COMM_UNIONROOM_WORK *union_work;
    //COMM_UNIONROOM_VIEW *union_view;
    //UNION_BOARD_WORK    *union_board;
    //TRADELIST_WORK      *tradelist_work;
    //TP_TO_3D_PTR        TpTo3DPtr;
    //int startmenu_pos;
    //SWAY_GRASS_PTR SwayGrass;
    //BAG_CURSOR * bag_cursor;
    //FNOTE_DATA * fnote;
    //EHL_PTR ExHeightList;
    //M3DOL_PTR Map3DObjExp;
    //HTD_PTR HoneyTreePtr;
    //BTOWER_SCRWORK* btower_wk;
    //const REGULATION* regulation;
    //ZKN_DATA_WORK*  p_zukandata;
    //BOOL scope_mode_flag;
    //BATTLE_CURSOR_DISP *battle_cursor;
    //u32 fldmap_update_msk;
    //WFLBY_COUNTER_TIME  wflby_counter;
};


u32 __attribute__((long_call)) Player_DirGet(void *player);
u32 __attribute__((long_call)) MATR_IsPC(void *matr);
u32 __attribute__((long_call)) MATR_IsLittleBookRack01(void *matr);
u32 __attribute__((long_call)) MATR_IsLittleBookRack02(void *matr);
u32 __attribute__((long_call)) MATR_IsBookRack01(void *matr);
u32 __attribute__((long_call)) MATR_IsBookRack02(void *matr);
u32 __attribute__((long_call)) MATR_IsTrashBox(void *matr);
u32 __attribute__((long_call)) MATR_IsShopBookRack01(void *matr);
u32 __attribute__((long_call)) MATR_IsShopBookRack02(void *matr);
u32 __attribute__((long_call)) MATR_IsShopBookRack03(void *matr);
u32 __attribute__((long_call)) MATR_IsWaterFall(void *matr);
u32 __attribute__((long_call)) MATR_IsMap(void *matr);
u32 __attribute__((long_call)) MATR_IsBumpPost(void *matr);
u32 __attribute__((long_call)) MATR_IsTV(void *matr);
u32 __attribute__((long_call)) Player_EventAttrCheck_KabeNobori(void *matr, u32 dir);
u32 __attribute__((long_call)) Player_FormGet(void *player);
void * __attribute__((long_call)) SaveData_GetMyStatus(void *savedata);
u32 __attribute__((long_call)) Player_TwThinkNowAttrGet(void *player);
u32 __attribute__((long_call)) Player_EventAttrCheck_Naminori(void *player, u32 natr, void *matr);
u32 __attribute__((long_call)) MyStatus_GetBadgeFlag(void *mystatus, u32 badge_id);
u32 __attribute__((long_call)) EvPoke_CheckWaza(void *party, u32 move_id);
void * __attribute__((long_call)) SaveData_GetTemotiPokemon(void *savedata);
u32 __attribute__((long_call)) MyItem_CheckItem(void *myitem, u32 item, u32 quantity, u32 heapid);
void * __attribute__((long_call)) SaveData_GetMyItem(void *savedata);
u32 __attribute__((long_call)) BtlTower_IsSalon(void *fsys);


#endif // FIELD_SYS_INCLUDE
