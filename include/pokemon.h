#ifndef POKEMON_H
#define POKEMON_H

/*************************************/
/* Pokemon struct related functions  */
/* If you add more to this header,   */
/* Please commit them to the repo.   */
/* Make syre you also input correct  */
/* offsets in rom.ld                 */
/*************************************/

#include "types.h"
#include "mail.h"
#include "custom_ball.h"
#include "monsno.h"

#define	WAZA_TEMOTI_MAX		(4)		///<1体のポケモンがもてる技の最大値
#define MONS_NAME_SIZE  10
#define EOM_SIZE 1
#define PERSON_NAME_SIZE 7
#define	ID_TOOIBASYO	(3002)
#define	ID_PER_type1		(6) //outside of enum cause not same purpose

#define	NORMAL_TYPE			(0)
#define	BATTLE_TYPE			(1)
#define	HIKOU_TYPE			(2)
#define	POISON_TYPE			(3)
#define	JIMEN_TYPE			(4)
#define	IWA_TYPE			(5)
#define	MUSHI_TYPE			(6)
#define	GHOST_TYPE			(7)
#define	METAL_TYPE			(8)
#define	HATE_TYPE			(9)
#define	FIRE_TYPE			(10)
#define	WATER_TYPE			(11)
#define	KUSA_TYPE			(12)
#define	ELECTRIC_TYPE		(13)
#define	SP_TYPE				(14)
#define	KOORI_TYPE			(15)
#define	DRAGON_TYPE			(16)
#define	AKU_TYPE			(17)

typedef struct pokemon_param POKEMON_PARAM;
typedef struct pokemon_calc_param POKEMON_CALC_PARAM;
typedef struct pokemon_paso_param POKEMON_PASO_PARAM;
typedef struct pokemon_paso_param1 POKEMON_PASO_PARAM1;
typedef struct pokemon_paso_param2 POKEMON_PASO_PARAM2;
typedef struct pokemon_paso_param3 POKEMON_PASO_PARAM3;
typedef struct pokemon_paso_param4 POKEMON_PASO_PARAM4;
typedef struct pokemon_personal_data POKEMON_PERSONAL_DATA;

//POKEMON_PERSONAL_DATA struct
struct pokemon_personal_data
{
	u8		basic_hp;			//基本ＨＰ
	u8		basic_pow;			//基本攻撃力
	u8		basic_def;			//基本防御力
	u8		basic_agi;			//基本素早さ

	u8		basic_spepow;		//基本特殊攻撃力
	u8		basic_spedef;		//基本特殊防御力
	u8		type1;				//属性１
	u8		type2;				//属性２

	u8		get_rate;			//捕獲率
	u8		give_exp;			//贈与経験値

	u16		pains_hp	:2;		//贈与努力値ＨＰ
	u16		pains_pow	:2;		//贈与努力値攻撃力
	u16		pains_def	:2;		//贈与努力値防御力
	u16		pains_agi	:2;		//贈与努力値素早さ
	u16		pains_spepow:2;		//贈与努力値特殊攻撃力
	u16		pains_spedef:2;		//贈与努力値特殊防御力
	u16					:4;		//贈与努力値予備

	u16		item1;				//アイテム１
	u16		item2;				//アイテム２

	u8		sex;				//性別ベクトル
	u8		egg_birth;			//タマゴの孵化歩数
	u8		friend;				//なつき度初期値
	u8		grow;				//成長曲線識別

	u8		egg_group1;			//こづくりグループ1
	u8		egg_group2;			//こづくりグループ2
	u8		speabi1;			//特殊能力１
	u8		speabi2;			//特殊能力２

	u8		escape;				//逃げる率
	u8		color	:7;			//色（図鑑で使用）
	u8		reverse	:1;			//反転フラグ
	u32		machine1;			//技マシンフラグ１
	u32		machine2;			//技マシンフラグ２
	u32		machine3;			//技マシンフラグ２
	u32		machine4;			//技マシンフラグ２
};

//Start of POKEMON_PARAM struct shit

struct pokemon_calc_param
{
	u32			condition;							//04h	コンディション
	uint8_t			level;								//05h	レベル
	uint8_t			cb_id;								//06h	カスタムボールID
	u16			hp;									//08h	HP
	u16			hpmax;								//0ah	HPMAX
	u16			pow;								//0ch	攻撃力
	u16			def;								//0eh	防御力
	u16			agi;								//10h	素早さ
	u16			spepow;								//12h	特攻
	u16			spedef;								//14h	特防
	_MAIL_DATA	mail_data;							//3ch	ポケモンにもたせるメールデータ
	CB_CORE		cb_core;							//54h	カスタムボール
};

struct pokemon_paso_param1
{
	u16	monsno;								//02h	モンスターナンバー
	u16 item;								//04h	所持アイテムナンバー
	u32	id_no;								//08h	IDNo
	u32	exp;								//0ch	経験値
	uint8_t	friend;								//0dh	なつき度
	uint8_t	speabino;							//0eh	特殊能力
	uint8_t	mark;								//0fh	ポケモンにつけるマーク（ボックス）
	uint8_t	country_code;						//10h	国コード
	uint8_t	hp_exp;								//11h	HP努力値
	uint8_t	pow_exp;							//12h	攻撃力努力値
	uint8_t	def_exp;							//13h	防御力努力値
	uint8_t	agi_exp;							//14h	素早さ努力値
	uint8_t	spepow_exp;							//15h	特攻努力値
	uint8_t	spedef_exp;							//16h	特防努力値
	uint8_t	style;								//17h	かっこよさ
	uint8_t	beautiful;							//18h	うつくしさ
	uint8_t	cute;								//19h	かわいさ
	uint8_t	clever;								//1ah	かしこさ
	uint8_t	strong;								//1bh	たくましさ
	uint8_t	fur;								//1ch	毛艶
	u32	sinou_ribbon;						//20h	シンオウ系リボン（ビットフィールドでアクセスするとプログラムメモリを消費するので、ビットシフトに変更）
};

struct pokemon_paso_param2
{
	u16	waza[WAZA_TEMOTI_MAX];				//08h	所持技
	uint8_t	pp[WAZA_TEMOTI_MAX];				//0ch	所持技PP
	uint8_t	pp_count[WAZA_TEMOTI_MAX];			//10h	所持技PP_COUNT
	u32	hp_rnd			:5;					//		HP乱数
	u32	pow_rnd			:5;					//		攻撃力乱数
	u32	def_rnd			:5;					//		防御力乱数
	u32	agi_rnd			:5;					//		素早さ乱数
	u32	spepow_rnd		:5;					//		特攻乱数
	u32	spedef_rnd		:5;					//		特防乱数
	u32	tamago_flag		:1;					//		タマゴフラグ（0:タマゴじゃない　1:タマゴだよ）
	u32	nickname_flag	:1;					//14h	ニックネームをつけたかどうかフラグ（0:つけていない　1:つけた）

	u32	old_ribbon;							//18h	過去作のリボン系（ビットフィールドでアクセスするとプログラムメモリを消費するので、ビットシフトに変更）

	uint8_t	event_get_flag	:1;					//		イベントで配布したことを示すフラグ
	uint8_t	sex				:2;					//   	ポケモンの性別
	uint8_t	form_no			:5;					//19h	形状ナンバー（アンノーン、デオキシス、ミノメスなど用）
	uint8_t	dummy_p2_1;							//1ah	あまり
	u16	dummy_p2_2;							//1ch	あまり
	u16	new_get_place;						//1eh	捕まえた場所（なぞの場所対応用）
	u16	new_birth_place;					//20h	生まれた場所（なぞの場所対応用）
};

struct pokemon_paso_param3
{
	STRCODE	nickname[MONS_NAME_SIZE+EOM_SIZE];	//16h	ニックネーム(MONS_NAME_SIZE=10)+(EOM_SIZE=1)=11
	uint8_t	pref_code;								//18h	都道府県コード
	uint8_t	get_cassette;							//		捕まえたカセットバージョン
	u64	new_ribbon;								//20h	新リボン系（ビットフィールドでアクセスするとプログラムメモリを消費するので、ビットシフトに変更）
};

struct pokemon_paso_param4
{
	STRCODE	oyaname[7+EOM_SIZE];				//10h	親の名前(PERSON_NAME_SIZE=7)+(EOM_SIZE_=1)=8*2(STRCODE=u16)

	uint8_t	get_year;								//11h	捕まえた年
	uint8_t	get_month;								//12h	捕まえた月
	uint8_t	get_day;								//13h	捕まえた日
	uint8_t	birth_year;								//14h	生まれた年

	uint8_t	birth_month;							//15h	生まれた月
	uint8_t	birth_day;								//16h	生まれた日
	u16	get_place;								//18h	捕まえた場所

	u16	birth_place;							//1ah	生まれた場所
	uint8_t	pokerus;								//1bh	ポケルス
	uint8_t	get_ball;								//1ch	捕まえたボール

	uint8_t	get_level		:7;						//1dh	捕まえたレベル
	uint8_t	oyasex			:1;						//1dh	親の性別
	uint8_t	get_ground_id;							//1eh	捕まえた場所の地形アトリビュート（ミノッチ用）
	u16	dummy_p4_1;								//20h	あまり
};
//PASO structs are always retained when interacting with the PC
struct pokemon_paso_param
{
	u32	personal_rnd;							//04h	個性乱数
	u16	pp_fast_mode		:1;					//06h	暗号／復号／チェックサム生成を後回しにして、処理を高速化モード
	u16	ppp_fast_mode		:1;					//06h	暗号／復号／チェックサム生成を後回しにして、処理を高速化モード
	u16	fusei_tamago_flag	:1;					//06h	ダメタマゴフラグ
	u16						:13;				//06h
	u16	checksum;								//08h	チェックサム

	uint8_t	paradata[sizeof(POKEMON_PASO_PARAM1)+
				 sizeof(POKEMON_PASO_PARAM2)+
				 sizeof(POKEMON_PASO_PARAM3)+
				 sizeof(POKEMON_PASO_PARAM4)];	//88h
};

struct pokemon_param
{
	POKEMON_PASO_PARAM	ppp;				//88h
	POKEMON_CALC_PARAM	pcp;				//dch 220
};

//Enum list for pokeparaget/pokeparaset stuff
enum{
	ID_PARA_personal_rnd=0,						//個性乱数
	ID_PARA_pp_fast_mode,						//
	ID_PARA_ppp_fast_mode,						//
	ID_PARA_fusei_tamago_flag,					//ダメタマゴフラグ
	ID_PARA_checksum,							//チェックサム

	ID_PARA_monsno,								//モンスターナンバー
	ID_PARA_item,								//所持アイテムナンバー
	ID_PARA_id_no,								//IDNo
	ID_PARA_exp,								//経験値
	ID_PARA_friend,								//なつき度
	ID_PARA_speabino,							//特殊能力
	ID_PARA_mark,								//ポケモンにつけるマーク（ボックス）
	ID_PARA_country_code,						//国コード
	ID_PARA_hp_exp,								//HP努力値
	ID_PARA_pow_exp,							//攻撃力努力値
	ID_PARA_def_exp,							//防御力努力値
	ID_PARA_agi_exp,							//素早さ努力値
	ID_PARA_spepow_exp,							//特攻努力値
	ID_PARA_spedef_exp,							//特防努力値
	ID_PARA_style,								//かっこよさ
	ID_PARA_beautiful,							//うつくしさ
	ID_PARA_cute,								//かわいさ
	ID_PARA_clever,								//かしこさ
	ID_PARA_strong,								//たくましさ
	ID_PARA_fur,								//毛艶
	ID_PARA_sinou_champ_ribbon,					//シンオウチャンプリボン
	ID_PARA_sinou_battle_tower_ttwin_first,		//シンオウバトルタワータワータイクーン勝利1回目
	ID_PARA_sinou_battle_tower_ttwin_second,	//シンオウバトルタワータワータイクーン勝利2回目
	ID_PARA_sinou_battle_tower_2vs2_win50,		//シンオウバトルタワータワーダブル50連勝
	ID_PARA_sinou_battle_tower_aimulti_win50,	//シンオウバトルタワータワーAIマルチ50連勝
	ID_PARA_sinou_battle_tower_siomulti_win50,	//シンオウバトルタワータワー通信マルチ50連勝
	ID_PARA_sinou_battle_tower_wifi_rank5,		//シンオウバトルタワーWifiランク５入り
	ID_PARA_sinou_syakki_ribbon,				//シンオウしゃっきリボン
	ID_PARA_sinou_dokki_ribbon,					//シンオウどっきリボン
	ID_PARA_sinou_syonbo_ribbon,				//シンオウしょんぼリボン
	ID_PARA_sinou_ukka_ribbon,					//シンオウうっかリボン
	ID_PARA_sinou_sukki_ribbon,					//シンオウすっきリボン
	ID_PARA_sinou_gussu_ribbon,					//シンオウぐっすリボン
	ID_PARA_sinou_nikko_ribbon,					//シンオウにっこリボン
	ID_PARA_sinou_gorgeous_ribbon,				//シンオウゴージャスリボン
	ID_PARA_sinou_royal_ribbon,					//シンオウロイヤルリボン
	ID_PARA_sinou_gorgeousroyal_ribbon,			//シンオウゴージャスロイヤルリボン
	ID_PARA_sinou_ashiato_ribbon,				//シンオウあしあとリボン
	ID_PARA_sinou_record_ribbon,				//シンオウレコードリボン
	ID_PARA_sinou_history_ribbon,				//シンオウヒストリーリボン
	ID_PARA_sinou_legend_ribbon,				//シンオウレジェンドリボン
	ID_PARA_sinou_red_ribbon,					//シンオウレッドリボン
	ID_PARA_sinou_green_ribbon,					//シンオウグリーンリボン
	ID_PARA_sinou_blue_ribbon,					//シンオウブルーリボン
	ID_PARA_sinou_festival_ribbon,				//シンオウフェスティバルリボン
	ID_PARA_sinou_carnival_ribbon,				//シンオウカーニバルリボン
	ID_PARA_sinou_classic_ribbon,				//シンオウクラシックリボン
	ID_PARA_sinou_premiere_ribbon,				//シンオウプレミアリボン
	ID_PARA_sinou_amari_ribbon,					//あまり

	ID_PARA_waza1,								//所持技1
	ID_PARA_waza2,								//所持技2
	ID_PARA_waza3,								//所持技3
	ID_PARA_waza4,								//所持技4
	ID_PARA_pp1,								//所持技PP1
	ID_PARA_pp2,								//所持技PP2
	ID_PARA_pp3,								//所持技PP3
	ID_PARA_pp4,								//所持技PP4
	ID_PARA_pp_count1,							//所持技PP_COUNT1
	ID_PARA_pp_count2,							//所持技PP_COUNT2
	ID_PARA_pp_count3,							//所持技PP_COUNT3
	ID_PARA_pp_count4,							//所持技PP_COUNT4
	ID_PARA_pp_max1,							//所持技PPMAX1
	ID_PARA_pp_max2,							//所持技PPMAX2
	ID_PARA_pp_max3,							//所持技PPMAX3
	ID_PARA_pp_max4,							//所持技PPMAX4
	ID_PARA_hp_rnd,								//HP乱数
	ID_PARA_pow_rnd,							//攻撃力乱数
	ID_PARA_def_rnd,							//防御力乱数
	ID_PARA_agi_rnd,							//素早さ乱数
	ID_PARA_spepow_rnd,							//特攻乱数
	ID_PARA_spedef_rnd,							//特防乱数
	ID_PARA_tamago_flag,						//タマゴフラグ
	ID_PARA_nickname_flag,						//ニックネームをつけたかどうかフラグ
	ID_PARA_stylemedal_normal,					//かっこよさ勲章(ノーマル)AGBコンテスト
	ID_PARA_stylemedal_super,					//かっこよさ勲章(スーパー)AGBコンテスト
	ID_PARA_stylemedal_hyper,					//かっこよさ勲章(ハイパー)AGBコンテスト
	ID_PARA_stylemedal_master,					//かっこよさ勲章(マスター)AGBコンテスト
	ID_PARA_beautifulmedal_normal,				//うつくしさ勲章(ノーマル)AGBコンテスト
	ID_PARA_beautifulmedal_super,				//うつくしさ勲章(スーパー)AGBコンテスト
	ID_PARA_beautifulmedal_hyper,				//うつくしさ勲章(ハイパー)AGBコンテスト
	ID_PARA_beautifulmedal_master,				//うつくしさ勲章(マスター)AGBコンテスト
	ID_PARA_cutemedal_normal,					//かわいさ勲章(ノーマル)AGBコンテスト
	ID_PARA_cutemedal_super,					//かわいさ勲章(スーパー)AGBコンテスト
	ID_PARA_cutemedal_hyper,					//かわいさ勲章(ハイパー)AGBコンテスト
	ID_PARA_cutemedal_master,					//かわいさ勲章(マスター)AGBコンテスト
	ID_PARA_clevermedal_normal,					//かしこさ勲章(ノーマル)AGBコンテスト
	ID_PARA_clevermedal_super,					//かしこさ勲章(スーパー)AGBコンテスト
	ID_PARA_clevermedal_hyper,					//かしこさ勲章(ハイパー)AGBコンテスト
	ID_PARA_clevermedal_master,					//かしこさ勲章(マスター)AGBコンテスト
	ID_PARA_strongmedal_normal,					//たくましさ勲章(ノーマル)AGBコンテスト
	ID_PARA_strongmedal_super,					//たくましさ勲章(スーパー)AGBコンテスト
	ID_PARA_strongmedal_hyper,					//たくましさ勲章(ハイパー)AGBコンテスト
	ID_PARA_strongmedal_master,					//たくましさ勲章(マスター)AGBコンテスト
	ID_PARA_champ_ribbon,						//チャンプリボン
	ID_PARA_winning_ribbon,						//ウィニングリボン
	ID_PARA_victory_ribbon,						//ビクトリーリボン
	ID_PARA_bromide_ribbon,						//ブロマイドリボン
	ID_PARA_ganba_ribbon,						//がんばリボン
	ID_PARA_marine_ribbon,						//マリンリボン
	ID_PARA_land_ribbon,						//ランドリボン
	ID_PARA_sky_ribbon,							//スカイリボン
	ID_PARA_country_ribbon,						//カントリーリボン
	ID_PARA_national_ribbon,					//ナショナルリボン
	ID_PARA_earth_ribbon,						//アースリボン
	ID_PARA_world_ribbon,						//ワールドリボン
	ID_PARA_event_get_flag,						//イベントで配布されたことを示すフラグ
	ID_PARA_sex,								//性別
	ID_PARA_form_no,							//形状ナンバー（アンノーン、デオキシス、ミノメスなど用）
	ID_PARA_dummy_p2_1,							//あまり
	ID_PARA_dummy_p2_2,							//あまり
	ID_PARA_new_get_place,						//1eh	捕まえた場所（なぞの場所対応用）
	ID_PARA_new_birth_place,					//20h	生まれた場所（なぞの場所対応用）

	ID_PARA_nickname,							//ニックネーム
	ID_PARA_nickname_code_flag,					//ニックネーム（STRCODE使用,nickname_flagもオンにする）
	ID_PARA_nickname_buf,						//ニックネーム（STRBUF使用）
	ID_PARA_nickname_buf_flag,					//ニックネーム（STRBUF使用,nickname_flagもオンにする）
	ID_PARA_pref_code,							//都道府県コード
	ID_PARA_get_cassette,						//捕まえたカセット（カラーバージョン）
	ID_PARA_trial_stylemedal_normal,			//かっこよさ勲章(ノーマル)トライアル
	ID_PARA_trial_stylemedal_super,				//かっこよさ勲章(スーパー)トライアル
	ID_PARA_trial_stylemedal_hyper,				//かっこよさ勲章(ハイパー)トライアル
	ID_PARA_trial_stylemedal_master,			//かっこよさ勲章(マスター)トライアル
	ID_PARA_trial_beautifulmedal_normal,		//うつくしさ勲章(ノーマル)トライアル
	ID_PARA_trial_beautifulmedal_super,			//うつくしさ勲章(スーパー)トライアル
	ID_PARA_trial_beautifulmedal_hyper,			//うつくしさ勲章(ハイパー)トライアル
	ID_PARA_trial_beautifulmedal_master,		//うつくしさ勲章(マスター)トライアル
	ID_PARA_trial_cutemedal_normal,				//かわいさ勲章(ノーマル)トライアル
	ID_PARA_trial_cutemedal_super,				//かわいさ勲章(スーパー)トライアル
	ID_PARA_trial_cutemedal_hyper,				//かわいさ勲章(ハイパー)トライアル
	ID_PARA_trial_cutemedal_master,				//かわいさ勲章(マスター)トライアル
	ID_PARA_trial_clevermedal_normal,			//かしこさ勲章(ノーマル)トライアル
	ID_PARA_trial_clevermedal_super,			//かしこさ勲章(スーパー)トライアル
	ID_PARA_trial_clevermedal_hyper,			//かしこさ勲章(ハイパー)トライアル
	ID_PARA_trial_clevermedal_master,			//かしこさ勲章(マスター)トライアル
	ID_PARA_trial_strongmedal_normal,			//たくましさ勲章(ノーマル)トライアル
	ID_PARA_trial_strongmedal_super,			//たくましさ勲章(スーパー)トライアル
	ID_PARA_trial_strongmedal_hyper,			//たくましさ勲章(ハイパー)トライアル
	ID_PARA_trial_strongmedal_master,			//たくましさ勲章(マスター)トライアル
	ID_PARA_amari_ribbon,						//余りリボン

	ID_PARA_oyaname,							//親の名前
	ID_PARA_oyaname_buf,						//親の名前（STRBUF使用）
	ID_PARA_get_year,							//捕まえた年
	ID_PARA_get_month,							//捕まえた月
	ID_PARA_get_day,							//捕まえた日
	ID_PARA_birth_year,							//生まれた年
	ID_PARA_birth_month,						//生まれた月
	ID_PARA_birth_day,							//生まれた日
	ID_PARA_get_place,							//捕まえた場所
	ID_PARA_birth_place,						//生まれた場所
	ID_PARA_pokerus,							//ポケルス
	ID_PARA_get_ball,							//捕まえたボール
	ID_PARA_get_level,							//捕まえたレベル
	ID_PARA_oyasex,								//親の性別
	ID_PARA_get_ground_id,						//捕まえた場所の地形アトリビュート（ミノッチ用）
	ID_PARA_dummy_p4_1,							//あまり

	ID_PARA_condition,							//コンディション
	ID_PARA_level,								//レベル
	ID_PARA_cb_id,								//カスタムボールID
	ID_PARA_hp,									//HP
	ID_PARA_hpmax,								//HPMAX
	ID_PARA_pow,								//攻撃力
	ID_PARA_def,								//防御力
	ID_PARA_agi,								//素早さ
	ID_PARA_spepow,								//特攻
	ID_PARA_spedef,								//特防
	ID_PARA_mail_data,							//メールデータ
	ID_PARA_cb_core,							//カスタムボールデータ
	
	ID_PARA_poke_exist,							//ポケモン存在フラグ
	ID_PARA_tamago_exist,						//タマゴ存在フラグ

	ID_PARA_monsno_egg,							//タマゴかどうかも同時にチェック

	ID_PARA_power_rnd,							//パワー乱数をu32で扱う
	ID_PARA_nidoran_nickname,					//モンスターナンバーがニドランの時にnickname_flagが立っているかチェック

	ID_PARA_type1,								//ポケモンのタイプ１を取得（アウス、マルチタイプチェックもあり）
	ID_PARA_type2,								//ポケモンのタイプ２を取得（アウス、マルチタイプチェックもあり）

	ID_PARA_default_name,						//ポケモンのデフォルト名

	ID_PARA_end									//パラメータを追加するときは、ここから上に追加
};

u32 __attribute__((long_call)) PokeParaGet(POKEMON_PARAM * pp,int id,void *buf);
void * __attribute__((long_call)) PokeStatusGet(void* a1);
void * __attribute__((long_call)) PokemonAlloc(u32 heap);
//void __attribute__((long_call)) PokeReplace(void*,void*);
void __attribute__((long_call)) FreeSystem(void*);
void __attribute__((long_call)) FillWindowPixelBuffer(void*,uint8_t);
void __attribute__((long_call)) ConvertNumToString(void*,u32,u32,uint8_t,uint8_t);
void __attribute__((long_call)) StringPut(void*,void*,u32,u32);
void __attribute__((long_call)) PutWindows(void*);
void __attribute__((long_call)) PokeParaPut(POKEMON_PARAM *pp,int id,const void *buf);
void __attribute__((long_call)) PokePasoParaPutAct(POKEMON_PASO_PARAM *ppp,int id,const void *buf);
BOOL  __attribute__((long_call)) PokeParaFastModeOn(POKEMON_PARAM *pp);
BOOL  __attribute__((long_call)) PokeParaFastModeOff(POKEMON_PARAM *pp,BOOL flag);
BOOL __attribute__((long_call))	PokePasoParaFastModeOn(POKEMON_PASO_PARAM *ppp);
BOOL __attribute__((long_call))	PokePasoParaFastModeOff(POKEMON_PASO_PARAM *ppp,BOOL flag);
void __attribute__((long_call)) PokeFormNoPersonalDataGet(int mons_no,int form_no,POKEMON_PERSONAL_DATA *ppd);
u16	__attribute__((long_call)) PokeChrAbiCalc(uint8_t chr,u16 para,uint8_t cond);
uint8_t	__attribute__((long_call)) PokeSeikakuGet(POKEMON_PARAM *pp);
void __attribute__((long_call))	PokePasoParaSet(POKEMON_PASO_PARAM *ppp,int mons_no,int level,int pow,int rndflag,u32 rnd,int idflag,u32 id);
void __attribute__((long_call))	PokeParaInit(POKEMON_PARAM *pp);
void __attribute__((long_call))	PokeParaCoded(void *data,u32 size,u32 code);
void __attribute__((long_call))	PokeParaCalc(POKEMON_PARAM *pp);
u32 __attribute__((long_call))	PokeLevelCalc(u16 mons_no,u32 exp);
u32 __attribute__((long_call)) PokePasoParaGet(POKEMON_PASO_PARAM *ppp,int id,void *buf);
void __attribute__((long_call))	PokePasoParaPut(POKEMON_PASO_PARAM *ppp,int id,const void *buf);
u8	__attribute__((long_call)) AusuTypeGet(u16	item_param);
void * __attribute__((long_call)) PokeParaAdrsGet(POKEMON_PASO_PARAM *ppp,u32 rnd,u8 id);
void __attribute__((long_call))	PokePasoParaSpeabiSet(POKEMON_PASO_PARAM *ppp);
u8 __attribute__((long_call)) WT_PPMaxGet(u16 wazano,u8 maxupcnt); //need to move this one to another include
u8 __attribute__((long_call))	PokeSexGetMonsNo(u16 monsno,u32 rnd);
u16	__attribute__((long_call)) PokeParaCheckSum(void *data,u32	size);

/*Message func, will also need to move them elsewhere*/
void __attribute__((long_call)) MSGDAT_MonsNameGet( u32 monsno, u32 heapID, STRCODE* dst );
STRBUF* __attribute__((long_call)) MSGDAT_UTIL_GetMonsName( u32 monsno, u32 heapID );
void __attribute__((long_call)) STRBUF_Copy( STRBUF* dst, const STRBUF* src );
void __attribute__((long_call)) STRBUF_Delete( STRBUF* strbuf );
void __attribute__((long_call)) STRBUF_SetStringCode( STRBUF* strbuf, const STRCODE* sz );
u32	__attribute__((long_call))	PokeFormNoPersonalParaGet(int mons_no,int form_no,int para);
#endif
