#include "../include/types.h"
#include "../include/field_sys.h"
#include "../include/pad.h"


u32 runToggle = 0;

int Player_KeyDashCheck(void *jiki, u16 prs)
{
    return runToggle;
}


int Jiki_InputKeyDirGet(void *jiki, u16 key_trg, u16 key_prs)
{
    int key_dir_x = Jiki_KeyDirXGet(key_prs);
    int key_dir_z = Jiki_KeyDirZGet(key_prs);

    if (key_trg & PAD_BUTTON_B)
    {
        runToggle ^= 1;

        //u8 buf[32];
        //sprintf(buf, "Run toggled %s.\n", runToggle ? "on" : "off");
        //debugsyscall(buf);
    }

    if (key_dir_x == -1){
        return(key_dir_z);
    }

    if (key_dir_z == -1){
        return(key_dir_x);
    }

    {
        int move_dir = Player_DirMoveGet(jiki);
        int input_x = Player_InputKeyDirXGet(jiki);
        int input_z = Player_InputKeyDirZGet(jiki);

        if (move_dir != -1){
            if (key_dir_x == input_x && key_dir_z == input_z){
                return(move_dir);
            }

            if (key_dir_z != input_z){
                return(key_dir_z);
            }

            return(key_dir_x);
        }

        return(key_dir_z);
    }

    return(-1);
}


void Jiki_MoveNormalWalk(void *jiki, void *fldobj, int dir, u16 trg, u16 prs)
{
    u32 ret;
    int code;
    u32 type;

    ret = Player_MoveHitCheck(jiki, fldobj, dir);
    
    debugsyscall("This was run!  Jiki_MoveNormalWalk\n");

    if (Player_FormGet(jiki) != 2)
    {
        if ((ret & JIKI_MOVE_HIT_BIT_JUMP))
        {
            code = AC_JUMP_U_2G_16F;
            type = HEROACTYPE_WALK_16F;
        }
        else if ((ret & JIKI_MOVE_HIT_BIT_JUMP_3G))
        {
            code = AC_JUMP_U_3G_24F;
            type = HEROACTYPE_WALK_32F;
        }
        else if (ret != JIKI_MOVE_HIT_BIT_NON)
        {
            code = AC_STAY_WALK_U_16F;
            type = HEROACTYPE_STOP;

            if ((ret & JIKI_MOVE_HIT_BIT_EXIT) == 0)
            {
                Snd_SePlay(1537);
            }

            FieldOBJ_DirMoveSet(fldobj, dir);
        }
        else
        {
            code = AC_WALK_U_8F;
            type = HEROACTYPE_WALK_8F;

            {
                void *save = Player_SaveDataPtrGet(jiki);

                if (Player_SaveDataDashCheck(save) == TRUE){
                    if (Player_KeyDashCheck(jiki, prs) == TRUE){
                        code = AC_WALK_U_2F;
                        type = HEROACTYPE_WALK_2F;
                    }
                }
            }

            code = Jiki_MoveNormalAttrAcmdWalkGet(fldobj, FieldOBJ_NowMapAttrGet(fldobj), code);
            Jiki_WalkCount(jiki);
            Player_MoveBitSet_StepON(jiki);
        }
    }
    else
    {
        if (ret == JIKI_MOVE_HIT_BIT_NON || ret == JIKI_MOVE_HIT_BIT_WATER)
        {
            code = AC_WALK_U_2F;
            type = HEROACTYPE_WALK_2F;
            //code = JIKI_WALK_AC_SWIM_U;
            //code = Jiki_MoveNormalSwimAttrAcmdWalkGet(fldobj, FieldOBJ_NowMapAttrGet(fldobj), code);
            Jiki_WalkCount(jiki);
            Player_MoveBitSet_StepON(jiki);
        }
        else
        {
            code = AC_STAY_WALK_U_16F;
            type = HEROACTYPE_STOP;

            if ((ret & JIKI_MOVE_HIT_BIT_EXIT) == 0)
            {
                Snd_SePlay(1537);
            }

            FieldOBJ_DirMoveSet(fldobj, dir);
        }
    }

    code = FieldOBJ_AcmdCodeDirChange(dir, code);
    Jiki_AcmdSet(jiki, fldobj, code, type);
}


u32 Player_KeyMoveSelectAcmdCodeGet(void *jiki, u16 trg, u16 prs, int speed, int dash, int hit)
{
    u32 code;
    int dir = Jiki_InputKeyDirGet(jiki, trg, prs);
    int val = Player_MoveSelectValueCheck(jiki, dir);
    
    Player_MoveValueSet(jiki, val);
    
    debugsyscall("This was run!  Player_KeyMoveSelectAcmdCodeGet\n");
    
    if (val == 0)
    {
        dir = Player_DirGet(jiki);
        code = FieldOBJ_AcmdCodeDirChange(dir, AC_DIR_U);
        return(code);
    }
    
    if (val == 2)
    {
        code = FieldOBJ_AcmdCodeDirChange(dir, AC_STAY_WALK_U_2F);
        return(code);
    }
    
    {
        void *fldobj = Player_FieldOBJGet(jiki);
        u32 ret = hit;
        //Player_MoveHitCheck(jiki, fldobj, dir);
        
        if ((ret & JIKI_MOVE_HIT_BIT_JUMP))
        {
            code = AC_JUMP_U_2G_16F;
        }
        else if ((ret & JIKI_MOVE_HIT_BIT_JUMP_3G))
        {
            code = AC_JUMP_U_3G_24F;
        }
        else if (ret != JIKI_MOVE_HIT_BIT_NON)
        {
            code = AC_STAY_WALK_U_16F;
            
            if ((ret & JIKI_MOVE_HIT_BIT_EXIT) == 0)
            {
                Snd_SePlay(1537);
            }
        }
        else
        {
            switch(speed)
            {
                case 0:  code = AC_WALK_U_32F; break;
                case 1:  code = AC_WALK_U_16F; break;
                case 2:  code =  AC_WALK_U_8F; break;
                case 3:  code =  AC_WALK_U_6F; break;
                case 4:  code =  AC_WALK_U_4F; break;
                case 5:  code =  AC_WALK_U_2F; break;
                default: code = AC_WALK_U_32F;
            }
            
            if (dash == TRUE && Player_KeyDashCheck(jiki, prs) == TRUE)
            {
                code = AC_WALK_U_2F;//AC_DASH_U_4F;
            }
        }
        code = FieldOBJ_AcmdCodeDirChange(dir, code);
        return(code);
    }
    return 0xFF;
}
