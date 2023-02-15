.text
.align 2
.thumb

.global Jiki_MoveNormalWalk_hook
Jiki_MoveNormalWalk_hook:
ldr r5, =Jiki_MoveNormalWalk_return_address
mov r6, lr
str r6, [r5]
pop {r5-r6}
bl Jiki_MoveNormalWalk
ldr r1, =Jiki_MoveNormalWalk_return_address
ldr r1, [r1]
mov pc, r1

.pool

Jiki_MoveNormalWalk_return_address:
.word 0

.global Player_KeyMoveSelectAcmdCodeGet_hook
Player_KeyMoveSelectAcmdCodeGet_hook:
ldr r5, =Player_KeyMoveSelectAcmdCodeGet_return_address
mov r6, lr
str r6, [r5]
pop {r5-r6}
bl Player_KeyMoveSelectAcmdCodeGet
ldr r1, =Player_KeyMoveSelectAcmdCodeGet_return_address
ldr r1, [r1]
mov pc, r1

.pool

Player_KeyMoveSelectAcmdCodeGet_return_address:
.word 0
