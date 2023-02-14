#include "../include/types.h"
#include "../include/pad.h"


u32 runToggle = 0;

int Player_KeyDashCheck(void *jiki, u16 prs)
{
    return runToggle;
}


int Jiki_InputKeyDirGet( void *jiki, u16 key_trg, u16 key_prs )
{
	int key_dir_x = Jiki_KeyDirXGet( key_prs );
	int key_dir_z = Jiki_KeyDirZGet( key_prs );
    
    if (key_trg & PAD_BUTTON_B)
    {
        runToggle ^= 1;
        
        //u8 buf[32];
        //sprintf(buf, "Run toggled %s.\n", runToggle ? "on" : "off");
        //debugsyscall(buf);
    }
	
	if( key_dir_x == -1 ){
		return( key_dir_z );
	}
	
	if( key_dir_z == -1 ){
		return( key_dir_x );
	}
	
	{
		int move_dir = Player_DirMoveGet( jiki );
		int input_x = Player_InputKeyDirXGet( jiki );
		int input_z = Player_InputKeyDirZGet( jiki );
		
		if( move_dir != -1 ){
			if( key_dir_x == input_x && key_dir_z == input_z ){
				return( move_dir );
			}
			
			if( key_dir_z != input_z ){
				return( key_dir_z );
			}
			
			return( key_dir_x );
		}
		
		return( key_dir_z );
	}
	
	return( -1 );
}
