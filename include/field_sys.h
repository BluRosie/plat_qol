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


#define JIKI_MOVE_HIT_BIT_NON       (0)
#define JIKI_MOVE_HIT_BIT_ATTR      (1<<0)
#define JIKI_MOVE_HIT_BIT_OBJ       (1<<1)
#define JIKI_MOVE_HIT_BIT_JUMP      (1<<2)
#define JIKI_MOVE_HIT_BIT_EXIT      (1<<3)
#define JIKI_MOVE_HIT_BIT_TAKE_OFF  (1<<4)
#define JIKI_MOVE_HIT_BIT_WATER     (1<<5)
#define JIKI_MOVE_HIT_BIT_BRIDGEHV  (1<<6)
#define JIKI_MOVE_HIT_BIT_JUMP_3G   (1<<7)


#define AC_DIR_U                0x00
#define AC_DIR_D                0x01
#define AC_DIR_L                0x02
#define AC_DIR_R                0x03
#define AC_WALK_U_32F           0x04
#define AC_WALK_D_32F           0x05
#define AC_WALK_L_32F           0x06
#define AC_WALK_R_32F           0x07
#define AC_WALK_U_16F           0x08
#define AC_WALK_D_16F           0x09
#define AC_WALK_L_16F           0x0a
#define AC_WALK_R_16F           0x0b
#define AC_WALK_U_8F            0x0c
#define AC_WALK_D_8F            0x0d
#define AC_WALK_L_8F            0x0e
#define AC_WALK_R_8F            0x0f
#define AC_WALK_U_4F            0x10
#define AC_WALK_D_4F            0x11
#define AC_WALK_L_4F            0x12
#define AC_WALK_R_4F            0x13
#define AC_WALK_U_2F            0x14
#define AC_WALK_D_2F            0x15
#define AC_WALK_L_2F            0x16
#define AC_WALK_R_2F            0x17
#define AC_STAY_WALK_U_32F      0x18
#define AC_STAY_WALK_D_32F      0x19
#define AC_STAY_WALK_L_32F      0x1a
#define AC_STAY_WALK_R_32F      0x1b
#define AC_STAY_WALK_U_16F      0x1c
#define AC_STAY_WALK_D_16F      0x1d
#define AC_STAY_WALK_L_16F      0x1e
#define AC_STAY_WALK_R_16F      0x1f
#define AC_STAY_WALK_U_8F       0x20
#define AC_STAY_WALK_D_8F       0x21
#define AC_STAY_WALK_L_8F       0x22
#define AC_STAY_WALK_R_8F       0x23
#define AC_STAY_WALK_U_4F       0x24
#define AC_STAY_WALK_D_4F       0x25
#define AC_STAY_WALK_L_4F       0x26
#define AC_STAY_WALK_R_4F       0x27
#define AC_STAY_WALK_U_2F       0x28
#define AC_STAY_WALK_D_2F       0x29
#define AC_STAY_WALK_L_2F       0x2a
#define AC_STAY_WALK_R_2F       0x2b
#define AC_STAY_JUMP_U_16F      0x2c
#define AC_STAY_JUMP_D_16F      0x2d
#define AC_STAY_JUMP_L_16F      0x2e
#define AC_STAY_JUMP_R_16F      0x2f
#define AC_STAY_JUMP_U_8F       0x30
#define AC_STAY_JUMP_D_8F       0x31
#define AC_STAY_JUMP_L_8F       0x32
#define AC_STAY_JUMP_R_8F       0x33
#define AC_JUMP_U_1G_8F         0x34
#define AC_JUMP_D_1G_8F         0x35
#define AC_JUMP_L_1G_8F         0x36
#define AC_JUMP_R_1G_8F         0x37
#define AC_JUMP_U_2G_16F        0x38
#define AC_JUMP_D_2G_16F        0x39
#define AC_JUMP_L_2G_16F        0x3a
#define AC_JUMP_R_2G_16F        0x3b
#define AC_WAIT_1F              0x3c
#define AC_WAIT_2F              0x3d
#define AC_WAIT_4F              0x3e
#define AC_WAIT_8F              0x3f
#define AC_WAIT_15F             0x40
#define AC_WAIT_16F             0x41
#define AC_WAIT_32F             0x42
#define AC_WARP_UP              0x43
#define AC_WARP_DOWN            0x44
#define AC_VANISH_ON            0x45
#define AC_VANISH_OFF           0x46
#define AC_DIR_PAUSE_ON         0x47
#define AC_DIR_PAUSE_OFF        0x48
#define AC_ANM_PAUSE_ON         0x49
#define AC_ANM_PAUSE_OFF        0x4a
#define AC_MARK_GYOE            0x4b
#define AC_WALK_U_6F            0x4c
#define AC_WALK_D_6F            0x4d
#define AC_WALK_L_6F            0x4e
#define AC_WALK_R_6F            0x4f
#define AC_WALK_U_3F            0x50
#define AC_WALK_D_3F            0x51
#define AC_WALK_L_3F            0x52
#define AC_WALK_R_3F            0x53
#define AC_WALK_U_1F            0x54
#define AC_WALK_D_1F            0x55
#define AC_WALK_L_1F            0x56
#define AC_WALK_R_1F            0x57
#define AC_DASH_U_4F            0x58
#define AC_DASH_D_4F            0x59
#define AC_DASH_L_4F            0x5a
#define AC_DASH_R_4F            0x5b
#define AC_JUMPHI_L_1G_16F      0x5c
#define AC_JUMPHI_R_1G_16F      0x5d
#define AC_JUMPHI_L_3G_32F      0x5e
#define AC_JUMPHI_R_3G_32F      0x5f
#define AC_WALK_U_7F            0x60
#define AC_WALK_D_7F            0x61
#define AC_WALK_L_7F            0x62
#define AC_WALK_R_7F            0x63
#define AC_PC_BOW               0x64
#define AC_HIDE_PULLOFF         0x65
#define AC_HERO_BANZAI          0x66
#define AC_MARK_SAISEN          0x67
#define AC_HERO_BANZAI_UKE      0x68
#define AC_WALKGL_U_8F          0x69
#define AC_WALKGL_D_8F          0x6a
#define AC_WALKGL_L_8F          0x6b
#define AC_WALKGL_R_8F          0x6c
#define AC_WALKGR_U_8F          0x6d
#define AC_WALKGR_D_8F          0x6e
#define AC_WALKGR_L_8F          0x6f
#define AC_WALKGR_R_8F          0x70
#define AC_WALKGU_U_8F          0x71
#define AC_WALKGU_D_8F          0x72
#define AC_WALKGU_L_8F          0x73
#define AC_WALKGU_R_8F          0x74
#define AC_JUMP_U_3G_24F        0x75
#define AC_JUMP_D_3G_24F        0x76
#define AC_JUMP_L_3G_24F        0x77
#define AC_JUMP_R_3G_24F        0x78
#define AC_DASHGL_U_4F          0x79
#define AC_DASHGL_D_4F          0x7a
#define AC_DASHGL_L_4F          0x7b
#define AC_DASHGL_R_4F          0x7c
#define AC_DASHGR_U_4F          0x7d
#define AC_DASHGR_D_4F          0x7e
#define AC_DASHGR_L_4F          0x7f
#define AC_DASHGR_R_4F          0x80
#define AC_DASHGU_U_4F          0x81
#define AC_DASHGU_D_4F          0x82
#define AC_DASHGU_L_4F          0x83
#define AC_DASHGU_R_4F          0x84

#define AC_JUMPGL_U_1G_8F       0x85
#define AC_JUMPGL_D_1G_8F       0x86
#define AC_JUMPGL_L_1G_8F       0x87
#define AC_JUMPGL_R_1G_8F       0x88
#define AC_JUMPGR_U_1G_8F       0x89
#define AC_JUMPGR_D_1G_8F       0x8a
#define AC_JUMPGR_L_1G_8F       0x8b
#define AC_JUMPGR_R_1G_8F       0x8c
#define AC_JUMPGU_U_1G_8F       0x8d
#define AC_JUMPGU_D_1G_8F       0x8e
#define AC_JUMPGU_L_1G_8F       0x8f
#define AC_JUMPGU_R_1G_8F       0x90
#define AC_WALKGU_U_4F          0x91
#define AC_WALKGU_D_4F          0x92
#define AC_WALKGU_L_4F          0x93
#define AC_WALKGU_R_4F          0x94
#define AC_WALKGU_U_2F          0x95
#define AC_WALKGU_D_2F          0x96
#define AC_WALKGU_L_2F          0x97
#define AC_WALKGU_R_2F          0x98
#define AC_MARK_GYOE_TWAIT      0x99


enum
{
	HEROACTYPE_NON = 0,
	HEROACTYPE_STOP,
	HEROACTYPE_WALK_32F,
	HEROACTYPE_WALK_16F,
	HEROACTYPE_WALK_8F,
	HEROACTYPE_WALK_4F,
	HEROACTYPE_WALK_2F,
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
void * __attribute__((long_call)) Player_FieldOBJGet(void *jiki);
void * __attribute__((long_call)) SaveData_GetMyStatus(void *savedata);
u32 __attribute__((long_call)) Player_TwThinkNowAttrGet(void *player);
u32 __attribute__((long_call)) Player_EventAttrCheck_Naminori(void *player, u32 natr, void *matr);
u32 __attribute__((long_call)) MyStatus_GetBadgeFlag(void *mystatus, u32 badge_id);
u32 __attribute__((long_call)) EvPoke_CheckWaza(void *party, u32 move_id);
void * __attribute__((long_call)) SaveData_GetTemotiPokemon(void *savedata);
u32 __attribute__((long_call)) MyItem_CheckItem(void *myitem, u32 item, u32 quantity, u32 heapid);
void * __attribute__((long_call)) SaveData_GetMyItem(void *savedata);
u32 __attribute__((long_call)) BtlTower_IsSalon(void *fsys);


void __attribute__((long_call)) Jiki_MoveNormal(void *, void *, void *, int, u16, u16);
void __attribute__((long_call)) Jiki_MoveCycle(void *, void *, void *, int, u16, u16);
void __attribute__((long_call)) Jiki_MoveCycle4(void *, void *, void *, int, u16, u16);
u32 __attribute__((long_call)) Player_MoveSpeedAdd(void *, u32, u32);
u32 __attribute__((long_call)) Player_MoveHitCheck(void *jiki, void *fldobj, int dir);
void __attribute__((long_call)) FieldOBJ_DirMoveSet(void *fldobj, int dir);
void Snd_SePlay(u32 id);
void * __attribute__((long_call)) Player_SaveDataPtrGet(void *jiki);
u32 __attribute__((long_call)) Player_SaveDataDashCheck(void *savedata);
u32 __attribute__((long_call)) Jiki_MoveNormalAttrAcmdWalkGet(void *fldobj, u32 attr, u32 code);
u32 __attribute__((long_call)) FieldOBJ_NowMapAttrGet(void *fldobj);
void __attribute__((long_call)) Jiki_WalkCount(void *jiki);
void __attribute__((long_call)) Player_MoveBitSet_StepON(void *jiki);
u32 __attribute__((long_call)) FieldOBJ_AcmdCodeDirChange(u32 dir, u32 code);
void __attribute__((long_call)) Jiki_AcmdSet(void *jiki, void *fldobj, u32 code, u32 type);
int __attribute__((long_call)) Player_MoveSelectValueCheck(void *jiki, int dir);
void __attribute__((long_call)) Player_MoveValueSet(void *jiki, int value);


#endif // FIELD_SYS_INCLUDE
