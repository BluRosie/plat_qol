	.text
	.align 1
    
    .force_thumb
    .syntax unified
    .global __aeabi_idiv
    .thumb_func
    .type __aeabi_idiv,function
__aeabi_idiv:
    push {lr}
    blx  0x020E1F6C
    pop {pc}
	.size __aeabi_idiv, . - __aeabi_idiv

    .force_thumb
	.syntax unified
	.global __gnu_thumb1_case_uqi
	.thumb_func
	.type __gnu_thumb1_case_uqi,function
__gnu_thumb1_case_uqi:
	push	{r1}
	mov	r1, lr
	lsrs	r1, r1, #1
	lsls	r1, r1, #1
	ldrb	r1, [r1, r0]
	lsls	r1, r1, #1
	add	lr, lr, r1
	pop	{r1}
	bx	lr
	.size __gnu_thumb1_case_uqi, . - __gnu_thumb1_case_uqi

    .force_thumb
    .syntax unified
    .global __aeabi_uidivmod
    .thumb_func
    .type __aeabi_uidivmod,function
__aeabi_uidivmod:
    push {lr}
    blx  0x020E1F6C
    pop {pc}
	.size __aeabi_uidivmod, . - __aeabi_uidivmod


    .force_thumb
    .syntax unified
    .global __gnu_thumb1_case_sqi
    .thumb_func
    .type __gnu_thumb1_case_sqi,function
__gnu_thumb1_case_sqi:
     push    {r1}
     mov r1, lr
     lsrs    r1, r1, #1
     lsls    r1, r1, #1
     ldrsb   r1, [r1, r0]
     lsls    r1, r1, #1
     add lr, r1
     pop {r1}
     bx  lr
    .size __gnu_thumb1_case_sqi, . - __gnu_thumb1_case_sqi

.global __gnu_thumb1_case_uhi
.thumb_func
.type __gnu_thumb1_case_uhi,function
__gnu_thumb1_case_uhi:
    push    {r0, r1}
    mov     r1, lr
    lsrs    r1, r1, #1
    lsls    r0, r0, #1
    lsls    r1, r1, #1
    ldrh    r1, [r1, r0]
    lsls    r1, r1, #1
    add     lr, lr, r1
    pop     {r0, r1}
    bx      lr
    .size __gnu_thumb1_case_uhi, . - __gnu_thumb1_case_uhi

    .force_thumb
    .syntax unified
    .global __aeabi_llsl
    .thumb_func
    .type __aeabi_llsl,function
__aeabi_llsl:
    cmp    r2, #31
    bhi    _higher
    
    movs    r3, r1        @ n < 32:
    lsls    r0, r2        @ lo = lo << n
    lsls    r1, r2
    rsbs    r2, r2, #0
    adds    r2, #32
    lsrs    r3, r2
    orrs    r1, r3        @ hi = hi << n | lo >> (32-n)
    bx    lr

    .force_thumb
    .syntax unified
    .global __higher
    .thumb_func
    .type __higher,function
_higher:    sub    r2, #32        @ n >= 32:
    movs    r1, r0
    lsls    r1, r2        @ hi = lo << (n-32)
    movs    r0, #0        @ lo = 0
    bx    lr