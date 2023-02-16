.nds
.thumb


.include "armips/nop_verification.s"



.open "base/overlay/overlay_0016.bin", 0x0223B140

.org 0x0226CC98
	ldr r3, =(mapBToRun | 1)
	bx r3

.pool



.close



.open "build/data/weather_sys.narc_65", 0x023C8000


.org 0x023CB01C // smack dab in the middle of the last routine
    bl toggleRunForSurf


.orga 0x13CD0

// r1 is sys.trg
// r5 is PAD_BUTTON_A
// r7 is PAD_BUTTON_B
// r0 is &move, #1 is y_menu, #2 is x_menu
// r5 needs to be ret_key upon return
mapBToRun:

mov r3, r1
tst r3, r5
bne @@returnback
tst r1, r7
beq @@retzero

	ldrb r3, [r0, #1] // offset of y_menu
	cmp r3, #1
	beq @@checkXCoord
@@setToRun:
	mov r3, #1
	strb r3, [r0, #1]
	strb r3, [r0, #2]
	mov r5, #2
	b @@returnback

@@checkXCoord:
	ldrb r3, [r0, #2]
	cmp r3, #1
	bne @@setToRun
	mov r5, #1 // return select

@@returnback:
	ldr r3, =0x0226CCAA | 1
	b call_via_r3

@@retzero:
	ldr r3, =0x0226CCA6 | 1
call_via_r3:
	bx r3

.pool




toggleRunForSurf:
    push {lr}
    //bl 0x020613FC // Player_KeyDashCheck
    ldr r0, =0x020613FD
    bl call_via_r0
    cmp r0, #1
    beq @@_isRunning
    mov r0, #0x10
    pop {pc}

@@_isRunning:
    mov r0, #0x14
    pop {pc}

.pool




call_via_r0:
    bx r0


.close
