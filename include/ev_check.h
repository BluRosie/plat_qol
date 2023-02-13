#ifndef EV_CHECH_H
#define EV_CHECH_H

#include "types.h"

#define SP_SCRID_SCENE_CHANGE (1)
#define FLD_GIMMICK_GHOST_GYM (2)
#define EV_TYPE_MSG (9)
#define SCRID_COMMON_MSG (0)
#define EVENT_ID_NONE (65535)
#define SE_WIN_OPEN (1533)
#define SCRID_PC_ON (2018)
#define FLD_GIMMICK_TORNWORLD (9)
#define WAZANO_TAKINOBORI (127)
#define FLDOBJ_MOVE_WORK_SIZE (16)
#define FLDOBJ_MOVE_SUB_WORK_SIZE (16)
#define FLDOBJ_MOVE_CMD_WORK_SIZE (16)
#define FLDOBJ_DRAW_WORK_SIZE (32)

typedef struct {
    u16 TalkCheck:1;
    u16 StepCheck:1;
    u16 MenuOpen:1;
    u16 CnvButton:1;
    u16 MatCheck:1;
    u16 PushCheck:1;
    u16 MoveCheck:1;
    u16 FloatCheck:1;

    u16 DebugMenu:1;
    u16 DebugBattle:1;
    u16 DebugHook:1;
    u16 DebugKeyPush:1;
    u16 OpenPCCheck:1;
    u16 Unused:3;
    u8 Site;
    s8 PushSite;
    u16 trg;
    u16 cont;
} __attribute__((packed)) EV_REQUEST;

typedef enum {
	FIELD_SUBSCRN_POKETCH = 1,		///<通常（ポケッチ）
	FIELD_SUBSCRN_UNDER,			///<炭鉱（レーダー画面）
	FIELD_SUBSCRN_UNION,			///<ユニオンルーム (掲示板画面)
	FIELD_SUBSCRN_NO_POKETCH,		///<ポケッチなし、ボールのみ画面

	FIELD_SUBSCRN_MAX,
}FIELD_SUBSCRN_TYPE;

typedef enum
{
	FIELD_CAMERA_NORMAL = 0,
	FIELD_CAMERA_LOOKAT_Z,
}FIELD_CAMERA_TYPE;

typedef struct {
	void *ctrl; //CONTROL_WORK * ctrl;	///<制御用ワーク

	void *fldmap; //FIELDMAP_WORK * fldmap;

	void *bg1; //GF_BGL_INI * bgl;		///<BGLデータ

	void *savedata; //SAVEDATA * savedata;	///<セーブされるゲーム進行データ

	void *event; //GMEVENT_CONTROL * event;	///<イベント制御

	void *eventdata; //EVENT_DATA * eventdata;		///<ゾーン毎イベントデータ

	FIELD_SUBSCRN_TYPE subscreen;	///<サブ画面の種類指定
	//fldmapに移動	POKETCH_WORK * poketch;

	void *location; //LOCATION_WORK * location;		///<位置情報
	
	FIELD_CAMERA_TYPE camera_type;	//カメラタイプ test kaga 070927
	void *camera_ptr; //GF_CAMERA_PTR	camera_ptr;		//カメラポインタ
	void * map_cont_dat; //DMC_PTR	map_cont_dat;	//分割ロード構造体の経由参照用ポインタ
	
	void *World; //WORLD_MAP_PTR World;

	void *MapResource; //MAP_RESOURCE_PTR MapResource;	//フィールド表示リソース参照用ポインタ
	void *mmdl; //MMDL_WORK * mmdl;			///<エリア別動作モデルリストデータへのポインタ
	
	void *player_cont_dat; //PCD_PTR player_cont_dat;//自機座標構造体の経由参照用ポインタ
	void *fldobjsys; //FIELD_OBJ_SYS_PTR fldobjsys;	//フィールドOBJ参照*
	void *player; //PLAYER_STATE_PTR * player;	//自機情報参照ポインタ
} __attribute__((packed)) FIELDSYS_WORK;

typedef enum
{
	HERO_EVBIT_NON               = 0,			///<イベント指定　無し
	HERO_EVBIT_PERMIT_KAIRIKI    = (1<<0),		///<怪力イベントを許可
	HERO_EVBIT_PREMIT_TAKINOBORI = (1<<1),		///<滝登りイベントを許可
	HERO_EVBIT_TORNWORLD         = (1<<2),		///<破れた世界イベントを許可
}HERO_EVBIT;

typedef enum
{
	HEROTWTYPE_NON = 0,		///<破れた世界ではない
	HEROTWTYPE_ON,			///<破れた世界である
	HEROTWTYPE_GROUND,		///<破れた世界 特殊地形移動
	HEROTWTYPE_WLEFT,		///<破れた世界 左壁移動
	HEROTWTYPE_WRIGHT,		///<破れた世界 右壁移動
	HEROTWTYPE_ROOF,		///<破れた世界 天井移動
	HEROTWTYPE_MAX,			///<最大
}HEROTWTYPE;

typedef struct _TAG_FIELD_OBJ
{
	u32 status_bit;											///<ステータスビット
	u32 move_bit;											///<動作ビット
	u32 obj_id;												///<OBJ ID
	u32 zone_id;											///<ゾーン ID
	u32 obj_code;											///<OBJコード
	u32 move_code;											///<動作コード
	u32 event_type;											///<イベントタイプ
	u32 event_flag;											///<イベントフラグ
	u32 event_id;											///<イベントID
	int dir_head;											///<FIELD_OBJ_H指定方向
	int dir_disp;											///<現在向いている方向
	int dir_move;											///<現在動いている方向
	int dir_disp_old;										///<過去の動いていた方向
	int dir_move_old;										///<過去の動いていた方向
	int param0;												///<ヘッダ指定パラメタ
	int param1;												///<ヘッダ指定パラメタ
	int param2;												///<ヘッダ指定パラメタ
	int move_limit_x;										///<X方向移動制限
	int move_limit_z;										///<Z方向移動制限
	int gx_init;											///<初期グリッドX
	int gy_init;											///<初期グリッドY
	int gz_init;											///<初期グリッドZ
	int gx_old;												///<過去グリッドX
	int gy_old;												///<過去グリッドY
	int gz_old;												///<過去グリッドZ
	int gx_now;												///<現在グリッドX
	int gy_now;												///<現在グリッドY
	int gz_now;												///<現在グリッドZ
	VecFx32 vec_pos_now;									///<現在実数座標
	VecFx32 vec_draw_offs;									///<表示座標オフセット
	VecFx32 vec_draw_offs_outside;							///<外部指定表示座標オフセット
	VecFx32 vec_attr_offs;								///<アトリビュートによる座標オフセット
	u32 draw_status;										///<描画ステータス
	int acmd_code;											///<アニメーションコマンドコード
	int acmd_seq;											///<アニメーションコマンドシーケンス
	u16 now_attr;											///<現在のマップアトリビュート
	u16 old_attr;											///<過去のマップアトリビュート
	
	void *tcb; //TCB_PTR tcb;											///<動作関数TCB*
	void *fldobj_sys; //CONST_FIELD_OBJ_SYS_PTR fldobj_sys;						///<FIELD_OBJ_SYSへの *
	
	void * /*FIELD_OBJ_MOVE_PROC_INIT*/ move_init_proc;				///<初期化関数
	void * /*FIELD_OBJ_MOVE_PROC*/ move_proc;							///<動作関数
	void * /*FIELD_OBJ_MOVE_PROC_DEL*/ move_delete_proc;				///<削除関数
	void * /*FIELD_OBJ_DRAW_PROC_INIT*/ draw_init_proc;				///<描画初期化関数
	void * /*FIELD_OBJ_DRAW_PROC*/ draw_proc;							///<描画関数
	void * /*FIELD_OBJ_DRAW_PROC_DEL*/ draw_delete_proc;				///<描画削除関数
	void * /*FIELD_OBJ_DRAW_PROC_PUSH*/ draw_push_proc;				///<描画退避関数
	void * /*FIELD_OBJ_DRAW_PROC_POP*/ draw_pop_proc;					///<描画復帰関数
	
	u8 move_proc_work[FLDOBJ_MOVE_WORK_SIZE];				///<動作関数用ワーク
	u8 move_sub_proc_work[FLDOBJ_MOVE_SUB_WORK_SIZE];		///<動作サブ関数用ワーク
	u8 move_cmd_proc_work[FLDOBJ_MOVE_CMD_WORK_SIZE];		///<動作コマンド用ワーク
	u8 draw_proc_work[FLDOBJ_DRAW_WORK_SIZE];				///<描画関数用ワーク
} __attribute__((packed)) FIELD_OBJ;

typedef struct _TAG_FIELD_OBJ * FIELD_OBJ_PTR;

typedef struct {
//	FIELD_OBJ_PTR targetobj;
	u32 targetbg;
//	void * targetobj;
}EVENT_WORK;

// also need to get function definitions + rom.ld entries for the following:

int __attribute__((long_call)) Player_MoveStateGet( const void *jiki ); // int Player_MoveStateGet( const PLAYER_STATE_PTR jiki );
int __attribute__((long_call)) Player_MoveValueGet(const void *jiki);
int __attribute__((long_call)) Player_DirGet(const void * jiki);
int __attribute__((long_call)) Player_KeyDirGet(void * jiki, u16 key_trg, u16 key_prs);
void __attribute__((long_call)) EventSet_Script(FIELDSYS_WORK *fsys, u16 scr_id, void * obj);

#endif
