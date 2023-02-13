#ifndef TRAINERCLASS_H
# define TRAINERCLASS_H

typedef struct {
	u16 effect_no;
	u16 bgm_no;
} FLD_ENCEFF_SP_DATA;

#define ENCOUNT_EFFECT_SEARCH	( 0xffff )

enum{
	// フィールド
	ENCOUNT_FIELD_GRASS_LEVEL_LOW,	// 草　レベル低い
	ENCOUNT_FIELD_GRASS_LEVEL_HIGH,	// 草　レベル高い
	ENCOUNT_FIELD_WATER_LEVEL_LOW,	// 水　レベル低い
	ENCOUNT_FIELD_WATER_LEVEL_HIGH,	// 水　レベル高い
	ENCOUNT_FIELD_DAN_LEVEL_LOW,	// ダンジョン　レベル低い
	ENCOUNT_FIELD_DAN_LEVEL_HIGH,	// ダンジョン　レベル高い

	// トレーナー
	ENCOUNT_TRAINER_GRASS_LEVEL_LOW,	// 草　レベル低い
	ENCOUNT_TRAINER_GRASS_LEVEL_HIGH,	// 草　レベル高い
	ENCOUNT_TRAINER_WATER_LEVEL_LOW,	// 水　レベル低
	ENCOUNT_TRAINER_WATER_LEVEL_HIGH,	// 水　レベル高い
	ENCOUNT_TRAINER_DAN_LEVEL_LOW,		// ダン　レベル低
	ENCOUNT_TRAINER_DAN_LEVEL_HIGH,		// ダン　レベル高い

	// ジム　
	ENCOUNT_SPTR_KUROGANE_GYM,		// クロガネジム
	ENCOUNT_SPTR_HAKUTAI_GYM,		// ハクタイジム
	ENCOUNT_SPTR_NOMOSE_GYM,		// ノモセジム
	ENCOUNT_SPTR_TOBARI_GYM,		// トバリジム
	ENCOUNT_SPTR_YOSUGA_GYM,		// ヨスガトジム
	ENCOUNT_SPTR_KISSAKI_GYM,		// キッサキジム
	ENCOUNT_SPTR_MIO_GYM,			// ミオジム
	ENCOUNT_SPTR_NAGISA_GYM,		// ナギサジム
	
	// 四天王
	ENCOUNT_SPTR_SITEN_00,
	ENCOUNT_SPTR_SITEN_01,
	ENCOUNT_SPTR_SITEN_02,
	ENCOUNT_SPTR_SITEN_03,
	
	// チャンピオン
	ENCOUNT_SPTR_CHANPION,
	
	// 伝説　パッケージ
	ENCOUNT_LEGEND_NORMAL,		// 伝説ポケモン
	ENCOUNT_LEGEND_PACKAGE,		// PACKAGEポケモン
	
	// 銀河団
	ENCOUNT_GINGA_NORMAL,		// 銀河団通常
	ENCOUNT_GINGA_SPECIAL,		// 銀河団幹部

	// 特殊
	ENCOUNT_SPECIAL_TOWER,		// バトルタワー　フロント
	ENCOUNT_SPECIAL_DOUBLE,		// ダブルバトル

	ENCOUNT_NUM

};

enum{
	// GYM
	FLD_ENCEFF_SP_GYM_KUROGANE,			// クロガネジム
	FLD_ENCEFF_SP_GYM_HAKUTAI,			// ハクタイジム
	FLD_ENCEFF_SP_GYM_NOMOSE,			// ノモセジム
	FLD_ENCEFF_SP_GYM_TOBARI,			// トバリジム
	FLD_ENCEFF_SP_GYM_YOSUGA,			// ヨスガトジム
	FLD_ENCEFF_SP_GYM_KISSAKI,			// キッサキジム
	FLD_ENCEFF_SP_GYM_MIO,				// ミオジム
	FLD_ENCEFF_SP_GYM_NAGISA,			// ナギサジム
	// 四天王
	FLD_ENCEFF_SP_BIGFOUR_00,
	FLD_ENCEFF_SP_BIGFOUR_01,
	FLD_ENCEFF_SP_BIGFOUR_02,
	FLD_ENCEFF_SP_BIGFOUR_03,
	// チャンピオン
	FLD_ENCEFF_SP_CHANPION,
	// ライバル
	FLD_ENCEFF_SP_RIVAL,
	// 特殊ポケモン
	FLD_ENCEFF_SP_LEGEND_POKE00,	// シェイミ
	FLD_ENCEFF_SP_PACKAGE_POKE00,	// イア、エア
	FLD_ENCEFF_SP_REIHAI_POKE00,	// レイ　ハイ
	FLD_ENCEFF_SP_AI_POKE00,		// アイ
	FLD_ENCEFF_SP_ARUSEUSU,			// アルセウス
	FLD_ENCEFF_SP_LEGEND_POKE01,	// ﾚｼﾞｷﾞｶﾞｽ、ヒードラン、ダーくらい
	FLD_ENCEFF_SP_LEGEND_POKE02,	// クレセリア
	FLD_ENCEFF_SP_PACKAGE_POKE01,	// ファイアー、サンダー、フリーザー
	FLD_ENCEFF_SP_LEGEND_POKE03,	// キマイラン
	FLD_ENCEFF_SP_LEGEND_POKE04,	// レジスチル、レジアイス、レジロック
	
	// 銀河団
	FLD_ENCEFF_SP_GINGA_NORMAL,		// 通常メンバー
	FLD_ENCEFF_SP_GINGA_SPECIAL,	// 幹部クラス
	FLD_ENCEFF_SP_GINGA_BOSU,	// ボス
	// その他特殊バトル
	FLD_ENCEFF_SP_BATTLE_TOWER,		// バトルタワー
	FLD_ENCEFF_SP_BATTLE_COMMU,		// 通信バトル
	FLD_ENCEFF_SP_BATTLE_DOUBLE,		// ダブルバトルトレーナー
	FLD_ENCEFF_SP_BATTLE_DOUBLE_YASEI,	// ダブルバトルやせい
//	FLD_ENCEFF_SP_BATTLE_TOWER_TAIKUUN,	// タワータイクーン
	FLD_ENCEFF_SP_BATTLE_FRONTIER_BRAIN,// フロンティアブレーン
	FLD_ENCEFF_SP_BATTLE_DOUBLE_GYM,	// ダブルバトルジム

	// ノーマル	
	FLD_ENCEFF_SP_NORMAL_TRAINER,	// トレーナー
	FLD_ENCEFF_SP_NORMAL_FIELD,		// 野生

    FLD_ENCEFF_SP_BATTLE_HACKER,
	FLD_ENCEFF_SP_MAX,	// 特殊エンカウント数
};
//Will need to translate all that shit sometimes
#define	TRTYPE_BOY						(0)
#define	TRTYPE_GIRL						(1)
#define	TRTYPE_TANPAN				(2)		//たんパンこぞう
#define	TRTYPE_MINI					(3)		//ミニスカート
#define	TRTYPE_CAMPB				(4)		//キャンプボーイ
#define	TRTYPE_PICNICG				(5)		//ピクニックガール
#define	TRTYPE_MUSHI				(6)		//むしとりしょうねん
#define	TRTYPE_AROMA				(7)		//アロマなおねえさん
#define	TRTYPE_FUTAGO				(8)		//ふたごちゃん
#define	TRTYPE_MOUNT				(9)		//やまおとこ
#define	TRTYPE_BATTLEG				(10)		//バトルガール
#define	TRTYPE_FISHING				(11)		//つりびと
#define	TRTYPE_CYCLINGM				(12)		//サイクリング
#define	TRTYPE_CYCLINGW				(13)		//サイクリング
#define	TRTYPE_KARATE				(14)		//からておう
#define	TRTYPE_ARTIST				(15)		//げいじゅつか
#define	TRTYPE_BREEDERM				(16)		//ポケモンブリーダー
#define	TRTYPE_BREEDERW				(17)		//ポケモンブリーダー
#define	TRTYPE_COWGIRL				(18)		//カウガール
#define	TRTYPE_JOGGER				(19)		//ジョギング
#define	TRTYPE_DAISUKIM				(20)		//だいすきクラブ
#define	TRTYPE_DAISUKIW				(21)		//だいすきクラブ
#define	TRTYPE_POKEGIRL				(22)		//ポケモンごっこ
#define	TRTYPE_LOVELOVE				(23)		//ラブラブカップル
#define	TRTYPE_ELITEM				(24)		//エリートトレーナー
#define	TRTYPE_ELITEW				(25)		//エリートトレーナー
#define	TRTYPE_WAITRESS				(26)		//ウエートレス
#define	TRTYPE_VETERAN				(27)		//ベテラントレーナー
#define	TRTYPE_SHINOBI				(28)		//にんじゃごっこ
#define	TRTYPE_DRAGON				(29)		//ドラゴンつかい
#define	TRTYPE_BIRD					(30)		//とりつかい
#define	TRTYPE_DOUBLETEAM			(31)		//ダブルチーム
#define	TRTYPE_PRINCE				(32)		//おぼっちゃま
#define	TRTYPE_PRINCESS				(33)		//おじょうさま
#define	TRTYPE_GENTLE				(34)		//ジェントルマン
#define	TRTYPE_MADAM				(35)		//マダム
#define	TRTYPE_SISTER				(36)		//おとなのおねえさん
#define	TRTYPE_COLLECTOR			(37)		//ポケモンコレクター
#define	TRTYPE_POLICE				(38)		//おまわりさん
#define	TRTYPE_RANGERM				(39)		//ポケモンレンジャー
#define	TRTYPE_RANGERW				(40)		//ポケモンレンジャー
#define	TRTYPE_SCIENTIST			(41)		//けんきゅういん
#define	TRTYPE_SWIMMERM				(42)		//かいパンやろう
#define	TRTYPE_SWIMMERW				(43)		//ビキニのおねえさん
#define	TRTYPE_UKIWAB				(44)		//うきわボーイ
#define	TRTYPE_UKIWAG				(45)		//うきわガール
#define	TRTYPE_SAILOR				(46)		//ふなのり
#define	TRTYPE_ANEOTOUTO			(47)		//うみきょうだい
#define	TRTYPE_ISEKI				(48)		//いせきマニア
#define	TRTYPE_ESPM					(49)		//サイキッカー
#define	TRTYPE_ESPW					(50)		//サイキッカー
#define	TRTYPE_GAMBLER				(51)		//ギャンブラー
#define	TRTYPE_GUITARIST			(52)		//ギタリスト
#define	TRTYPE_COLDELITEM			(53)		//エリートトレーナー
#define	TRTYPE_COLDELITEW			(54)		//エリートトレーナー
#define	TRTYPE_SKIERM				(55)		//スキーヤー
#define	TRTYPE_SKIERW				(56)		//スキーヤー
#define	TRTYPE_HEADS				(57)		//スキンヘッズ
#define	TRTYPE_PIERROT				(58)		//ピエロ
#define	TRTYPE_WORKER				(59)		//さぎょういん
#define	TRTYPE_SCHOOLB				(60)		//じゅくがえり
#define	TRTYPE_SCHOOLG				(61)		//じゅくがえり
#define	TRTYPE_LEADER1				(62)		//ジムリーダー
#define	TRTYPE_RIVAL				(63)		//ポケモントレーナー
#define	TRTYPE_LEADER7				(64)		//ジムリーダー
#define	TRTYPE_BIGFOUR1				(65)		//してんのう
#define	TRTYPE_BIGFOUR2				(66)		//してんのう
#define	TRTYPE_BIGFOUR3				(67)		//してんのう
#define	TRTYPE_BIGFOUR4				(68)		//してんのう
#define	TRTYPE_CHAMPION				(69)		//チャンピオン
#define	TRTYPE_FAMILY				(70)		//ぼくじょうおやこ
#define	TRTYPE_FARMER				(71)		//ぼくじょうおじさん
#define	TRTYPE_GINGALEADER1			(72)		//ギンガだんかんぶ
#define	TRTYPE_GINGAM				(73)		//ギンガだん
#define	TRTYPE_LEADER2				(74)		//ジムリーダー
#define	TRTYPE_LEADER3				(75)		//ジムリーダー
#define	TRTYPE_LEADER4				(76)		//ジムリーダー
#define	TRTYPE_LEADER5				(77)		//ジムリーダー
#define	TRTYPE_LEADER6				(78)		//ジムリーダー
#define	TRTYPE_LEADER8				(79)		//ジムリーダー
#define	TRTYPE_PARASOL				(80)		//パラソルおねえさん
#define	TRTYPE_WAITER				(81)		//ウエーター
#define	TRTYPE_INTERVIEW			(82)		//インタビュアー
#define	TRTYPE_CAMERAMAN			(83)		//カメラマン
#define	TRTYPE_REPORTER				(84)		//レポーター
#define	TRTYPE_IDOL					(85)		//アイドル
#define	TRTYPE_GINGALBOSS			(86)		//ギンガだんボス
#define	TRTYPE_GINGALEADER2			(87)		//ギンガだんかんぶ
#define	TRTYPE_GINGALEADER3			(88)		//ギンガだんかんぶ
#define	TRTYPE_GINGAW				(89)		//ギンガだん
#define	TRTYPE_BTFIVE1				(90)		//ポケモントレーナー
#define	TRTYPE_BTFIVE2				(91)		//ポケモントレーナー
#define	TRTYPE_BTFIVE3				(92)		//ポケモントレーナー
#define	TRTYPE_BTFIVE4				(93)		//ポケモントレーナー
#define	TRTYPE_BTFIVE5				(94)		//ポケモントレーナー
#define	TRTYPE_HERO					(95)		//ポケモントレーナー
#define	TRTYPE_HEROINE				(96)		//ポケモントレーナー
#define	TRTYPE_KUROTUGU				(97)		//タワータイクーン
#define	TRTYPE_MAID					(98)		//メイド
#define	TRTYPE_FBOSS1				(99)		//ステージマドンナ
#define	TRTYPE_FBOSS2				(100)		//ファクトリーヘッド
#define	TRTYPE_FBOSS3				(101)		//ルーレットゴッデス
#define	TRTYPE_FBOSS4				(102)		//キャッスルバトラー
#define	TRTYPE_BOY_DP				(103)
#define	TRTYPE_GIRL_DP				(104)
#define TRTYPE_HACKER               (105) //new class baby
#define	TRTYPE_MAX					(105)

#define SEQ_EYE_BOY	1100
#define SEQ_EYE_KID	1101
#define SEQ_EYE_FIGHT	1102
#define SEQ_EYE_GINGA	1103
#define SEQ_EYE_LADY	1104
#define SEQ_EYE_MOUNT	1105
#define SEQ_EYE_RICH	1106
#define SEQ_EYE_ENKA	1107
#define SEQ_EYE_MYS	1108
#define SEQ_EYE_ELITE	1109
#define SEQ_EYE_GIRL	1110
#define SEQ_EYE_SPORT	1111
#define SEQ_EYE_FUN	1112
#define SEQ_EYE_TENNO	1113
#define SEQ_EYE_CHAMP	1114
#define TRTYPE_BGM_TBL_MAX	(80)
u32 __attribute__((long_call))	TT_TrainerDataParaGet(int tr_id,int id);
u32 __attribute__((long_call)) ENCEFF_GetEffectNo( const void * p_battleparam );
#endif