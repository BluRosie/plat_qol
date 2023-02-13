#ifndef PAD_H
#define PAD_H

#define PAD_BUTTON_A            0x0001 // A
#define PAD_BUTTON_B            0x0002 // B
#define PAD_BUTTON_SELECT       0x0004 // SELECT
#define PAD_BUTTON_START        0x0008 // START
#define PAD_KEY_RIGHT           0x0010 // RIGHT of cross key
#define PAD_KEY_LEFT            0x0020 // LEFT  of cross key
#define PAD_KEY_UP              0x0040 // UP    of cross key
#define PAD_KEY_DOWN            0x0080 // DOWN  of cross key
#define PAD_BUTTON_R            0x0100 // R
#define PAD_BUTTON_L            0x0200 // L
#define PAD_BUTTON_X            0x0400 // X
#define PAD_BUTTON_Y            0x0800 // Y
#define PAD_BUTTON_DEBUG        0x2000 // Debug button


#define	ALL_KEY		( PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT )

#define	PAD_BUTTON_MENU		( PAD_BUTTON_X )	
#define	PAD_BUTTON_BENRI	( PAD_BUTTON_Y )		
#define	PAD_BUTTON_DECIDE	( PAD_BUTTON_A )	
#define	PAD_BUTTON_CANCEL	( PAD_BUTTON_B )

#define	ALL_DIRECTION_KEY     ( PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT )

#endif
