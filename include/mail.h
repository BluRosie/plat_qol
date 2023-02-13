#include "types.h"
#include "pokemon.h"

#define MAILDAT_ICONMAX (3)
#define MAILDAT_MSGMAX (3)
#define PMS_WORD_MAX (2)
#define EOM_SIZE 1
#define PERSON_NAME_SIZE 7
typedef struct _MAIL_DATA MAIL_DATA;

typedef union _MAIL_ICON{
	struct{
		u16	cgxID:12;	///<ポケモンアイコンキャラクタCgxID
		u16	palID:4;	///<ポケモンアイコンパレットID
	};
	u16	dat;
}MAIL_ICON;

//maybe move that to a pms include, not mandatory
typedef struct {
	u16				sentence_type;			///< 文章タイプ
	u16				sentence_id;			///< タイプ内ID
	PMS_WORD		word[PMS_WORD_MAX];		///< 単語ID
} __attribute__((packed)) PMS_DATA;

typedef struct _MAIL_DATA{
	u32	writerID;	//<トレーナーID 4
	u8	sex;	//<主人公の性別 1
	u8	region;	//<国コード 1
	u8	version;	//<カセットバージョン 1
	u8	design;	//<デザインナンバー 1
	STRCODE name[PERSON_NAME_SIZE+EOM_SIZE]; // 16
	MAIL_ICON	icon[MAILDAT_ICONMAX];	//<アイコンNO格納場所[]
	u16 form_bit;	//padding領域をプラチナから3体のポケモンのフォルム番号として使用(5bit単位)
	PMS_DATA	msg[MAILDAT_MSGMAX];	//<文章データ
} __attribute__((packed)) _MAIL_DATA;

void __attribute__((long_call))MailData_Copy(MAIL_DATA* src,MAIL_DATA* dest);
MAIL_DATA* __attribute__((long_call))MailData_CreateWork(int heapID);