.text
.align 2
.thumb

.global SetReq_hook
// r0 needs to be req (originally r0, now stored in r5), r1 needs to be trg (originally r2, now r6)
SetReq_hook:
	push {r0-r7}
	mov r0, r5
	mov r1, r6
	bl SetReq
	pop {r0-r7}

	mov r0, #0x1
	lsl r0, r0, #10
	tst r0, r6
	beq _return_to_21d1cf2
	ldrh r1, [r5, #0x0]
	mov r0, #0x4
	orr r0, r1
	strh r0, [r5, #0x0]

_return_to_21d1cf2:
	ldr r0, =(0x21d1cf2) | 1
	bx r0

.pool	


.global CheckReq_hook
CheckReq_hook:
	push {r0-r7}
	bl CheckReq
	cmp r0, #1
	beq _return_1
	pop {r0-r7}
	add sp, #-0x10
	mov r5, r0
	ldrh r0, [r5, #0x0]
	mov r4, r1
	lsl r0, r0, #20
	ldr r1, =(0x21d1da4+0xc) | 1
	bx r1

_return_1:
	pop {r0-r7}
	mov r0, #1
	pop {r3-r7, pc}

.pool
