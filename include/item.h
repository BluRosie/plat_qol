#ifndef ITEM_H
# define ITEM_H

//various item defines

#define ITEM_HAKKINDAMA (112) //griseous orb

//item parameter enum
enum {
	ITEM_PRM_PRICE,					// 買値
	ITEM_PRM_EQUIP,					// 装備効果
	ITEM_PRM_ATTACK,				// 威力
	ITEM_PRM_EVENT,					// 重要
	ITEM_PRM_CNV,					// 便利ボタン
	ITEM_PRM_POCKET,				// 保存先（ポケット番号）
	ITEM_PRM_FIELD,					// field機能 
	ITEM_PRM_BATTLE,				// battle機能 
	ITEM_PRM_TUIBAMU_EFF,			// ついばむ効果
	ITEM_PRM_NAGETUKERU_EFF,		// なげつける効果
	ITEM_PRM_NAGETUKERU_ATC,		// なげつける威力
	ITEM_PRM_SIZENNOMEGUMI_ATC,		// しぜんのめぐみ威力
	ITEM_PRM_SIZENNOMEGUMI_TYPE,	// しぜんのめぐみタイプ
	ITEM_PRM_BTL_POCKET,			// 戦闘保存先（ポケット番号）
	ITEM_PRM_W_TYPE,				// ワークタイプ
	ITEM_PRM_SLEEP_RCV,				// 眠り回復
	ITEM_PRM_POISON_RCV,			// 毒回復
	ITEM_PRM_BURN_RCV,				// 火傷回復
	ITEM_PRM_ICE_RCV,				// 氷回復
	ITEM_PRM_PARALYZE_RCV,			// 麻痺回復
	ITEM_PRM_PANIC_RCV,				// 混乱回復
	ITEM_PRM_MEROMERO_RCV,			// メロメロ回復
	ITEM_PRM_ABILITY_GUARD,			// 能力ガード
	ITEM_PRM_DEATH_RCV,				// 瀕死回復
	ITEM_PRM_ALL_DEATH_RCV,			// 全員瀕死回復
	ITEM_PRM_LV_UP,					// レベルアップ
	ITEM_PRM_EVOLUTION,				// 進化
	ITEM_PRM_ATTACK_UP,				// 攻撃力アップ
	ITEM_PRM_DEFENCE_UP,			// 防御力アップ
	ITEM_PRM_SP_ATTACK_UP,			// 特攻アップ
	ITEM_PRM_SP_DEFENCE_UP,			// 特防アップ
	ITEM_PRM_AGILITY_UP,			// 素早さアップ
	ITEM_PRM_HIT_UP,				// 命中率アップ
	ITEM_PRM_CRITICAL_UP,			// クリティカル率アップ
	ITEM_PRM_PP_UP,					// PPアップ
	ITEM_PRM_PP_3UP,				// PPアップ（３段階）
	ITEM_PRM_PP_RCV,				// PP回復
	ITEM_PRM_ALL_PP_RCV,			// PP回復（全ての技）
	ITEM_PRM_HP_RCV,				// HP回復
	ITEM_PRM_HP_EXP,				// HP努力値アップ
	ITEM_PRM_POWER_EXP,				// 攻撃努力値アップ
	ITEM_PRM_DEFENCE_EXP,			// 防御努力値アップ
	ITEM_PRM_AGILITY_EXP,			// 素早さ努力値アップ
	ITEM_PRM_SP_ATTACK_EXP,			// 特攻努力値アップ
	ITEM_PRM_SP_DEFENCE_EXP,		// 特防努力値アップ
	ITEM_PRM_FRIEND1,				// なつき度１
	ITEM_PRM_FRIEND2,				// なつき度２
	ITEM_PRM_FRIEND3,				// なつき度３
	ITEM_PRM_HP_EXP_POINT,			// HP努力値の値
	ITEM_PRM_POWER_EXP_POINT,		// 攻撃努力値の値
	ITEM_PRM_DEFENCE_EXP_POINT,		// 防御努力値の値
	ITEM_PRM_AGILITY_EXP_POINT,		// 素早さ努力値の値
	ITEM_PRM_SP_ATTACK_EXP_POINT,	// 特攻努力値の値
	ITEM_PRM_SP_DEFENCE_EXP_POINT,	// 特防努力値の値
	ITEM_PRM_HP_RCV_POINT,			// HP回復値の値
	ITEM_PRM_PP_RCV_POINT,			// pp回復値の値
	ITEM_PRM_FRIEND1_POINT,			// なつき度1の値
	ITEM_PRM_FRIEND2_POINT,			// なつき度2の値
	ITEM_PRM_FRIEND3_POINT,			// なつき度3の値
};

s32 __attribute((long_call)) ItemParamGet( u16 item, u16 param, u32 heap_id );
#endif