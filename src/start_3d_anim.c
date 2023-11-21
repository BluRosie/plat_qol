#include "../include/types.h"
#include "../include/pad.h"
#include "../include/common_scr_def.h"
#include "../include/ev_check.h"
#include "../include/field_sys.h"
#include "../include/item.h"
#include "../include/model.h"
#include "../include/moves.h"
#include "../include/pokemon.h"


/*void LONG_CALL Fld3DAnm_StartQuickSandAnime(	const int inGridX,
									const int inGridZ,
									const int inAnmNo,
									struct FIELDSYS_WORK * fsys);*/


void Fld3DAnm_StartQuickSandAnime(	const int inGridX,
									const int inGridZ,
									const int inAnmNo,
									struct FIELDSYS_WORK * fsys)
{

	BOOL rc;
	void *obj_ptr;
	void *rect;
	int obj_id;
	int list[] = {303, 304};
		
	MPTL_MakeTargetRect( inGridX, inGridZ, 0, -1, 1, 3, &rect );
	rc = MPTL_CheckPluralMap3DObjInRect(fsys,
										list,
										NELEMS(list),
										&rect,
										&obj_ptr,
										&obj_id);
	{
		void *render_obj;
		render_obj = M3DO_GetRenderObj(obj_ptr);
		rc =	F3DA_SetFld3DAnime(	obj_id, inAnmNo, TRUE,
									render_obj,
									fsys->field_3d_anime );
	}
	{
		void *anime;
		anime = F3DA_GetFld3DAnmPtr(obj_id, inAnmNo, fsys->field_3d_anime);
		F3DA_SetStartFrame(anime);
		F3DA_SetStopFlg(anime, FALSE);
		F3DA_MoveAnime(anime);
	}
}

void QuickSand_Update(FLDMAPFUNC_WORK * fwk, struct FIELDSYS_WORK * fsys, void * work)
{
	u8 attr;
	int x,z;
	u8 anime_no;
	QUICK_SAND_POS_INFO *info = (QUICK_SAND_POS_INFO*)work;
	
	if (~(*(u16*)0x04000130) & PAD_BUTTON_R)
	{
		x = 306;
		z = 718;
		if ((info->GridX == x)&&(info->GridZ == z)){
			return;
		}

		info->GridX = x;
		info->GridZ = z;
		anime_no = 1;
	}
	else {
		x = Player_NowGPosXGet(fsys->player);
		z = Player_NowGPosZGet(fsys->player);

		if ((info->GridX == x)&&(info->GridZ == z)){
			return;
		}

		info->GridX = x;
		info->GridZ = z;

		attr = GetAttributeLSB(fsys, x, z);
		
		if (attr == 0xDA){
			anime_no = 0;
		}else if (attr == 0xD9){
			anime_no = 1;
		}else{
			return;
		}

	}
	Fld3DAnm_StartQuickSandAnime(x, z, anime_no, fsys);
}


const FLDMAPFUNC_DATA QuickSandData = {
	2,
	sizeof(QUICK_SAND_POS_INFO),
	(void *)0x021EE75D,
	(void *)0x021EE765,
	//(void *)0x021EE769,
	QuickSand_Update,
	NULL
};

void QuickSand_CheckTask(struct FIELDSYS_WORK *fsys)
{
	FLDMAPFUNC_Create(fsys->fldmap->fmapfunc_sys, &QuickSandData);
}
