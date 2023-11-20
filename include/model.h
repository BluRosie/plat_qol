#ifndef MODEL_H
#define MODEL_H

#include "types.h"

typedef struct FLDMAPFUNC_WORK FLDMAPFUNC_WORK;

typedef struct QUICK_SAND_POS_INFO_tag
{
	int GridX;
	int GridZ;
}QUICK_SAND_POS_INFO;

typedef void (*FLDMAPFUNC_UPDATE)(FLDMAPFUNC_WORK *, struct FIELDSYS_WORK *, void *);
typedef void (*FLDMAPFUNC_DRAW3D)(FLDMAPFUNC_WORK *, struct FIELDSYS_WORK *, void *);
typedef void (*FLDMAPFUNC_CREATE)(FLDMAPFUNC_WORK *, struct FIELDSYS_WORK *, void *);
typedef void (*FLDMAPFUNC_DELETE)(FLDMAPFUNC_WORK *, struct FIELDSYS_WORK *, void *);

//------------------------------------------------------------------
/**
 * @brief	FLDMAPFUNC�𐶐�����̂ɕK�v�ȃf�[�^��`
 */
//------------------------------------------------------------------
typedef struct {
	u32 pri;
	u16 work_size;
	FLDMAPFUNC_CREATE create_func;
	FLDMAPFUNC_DELETE delete_func;
	FLDMAPFUNC_UPDATE update_func;
	FLDMAPFUNC_DRAW3D draw3d_func;
}FLDMAPFUNC_DATA;




void LONG_CALL MPTL_MakeTargetRect(	const int inGridX,const int inGridZ, 
	    		    				const int inOfsX, const int inOfsZ,
    				    			const u32 inW, const u32 inH,
		    			    		void *outRect );

BOOL LONG_CALL MPTL_CheckPluralMap3DObjInRect(	const struct FIELDSYS_WORK *fsys,
			    						    	const int* inTargetObjIDList,
				    						    const u8 inListNum,
    				    						const /*TARGET_RECT*/ void *inRect,
	    				    					/*M3DO_PTR*/ void *outObjData,
		    				    				int *outObjID);

void *LONG_CALL M3DO_GetRenderObj(void *inMap3DObjData);

BOOL LONG_CALL F3DA_SetFld3DAnime(	const int inObjID,
								    const int inAnimeNo,
							    	const BOOL inConditional,
								    void *objectdata,
								    void *field_3d_anime_ptr);

void *LONG_CALL F3DA_GetFld3DAnmPtr(const int inObjID, const int inAnimeNo,
									void *field_3d_anime_ptr);

void LONG_CALL F3DA_SetStartFrame(void *outAnimeData);

void LONG_CALL F3DA_SetStopFlg(void *inAnimePtr, const BOOL inFlg);

void LONG_CALL F3DA_MoveAnime(void *inAnimePtr);

void *LONG_CALL FLDMAPFUNC_Create(void * sys, const void * data);



void Fld3DAnm_StartQuickSandAnime(	const int inGridX,
									const int inGridZ,
									const int inAnmNo,
									struct FIELDSYS_WORK * fsys);

void QuickSand_CheckTask(struct FIELDSYS_WORK *fsys);



#endif
