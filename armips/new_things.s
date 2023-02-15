.nds
.thumb


.include "armips/nop_verification.s"


.open "build/data/weather_sys.narc_65", 0x023C8000

.org 0x023CB01C // smack dab in the middle of the last routine
    bl toggleRunForSurf


.orga 0x13CD0

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
