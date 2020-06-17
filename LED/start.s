.global delay_1s
.text
.global _start
_start:
	b reset
	ldr pc,_undefined_instruction
	ldr pc,_software_interrupt
	ldr pc,_prefeteh_abort
	ldr pc,_data_abort
	ldr pc,_not_used
	ldr pc,_irq
	ldr pc,_fiq
_undefined_instruction: .word _undefined_instruction
_software_interrupt: .word _software_interrupt
_prefeteh_abort: .word _prefeteh_abort
_data_abort: .word _data_abort
_not_used: .word _not_used
_irq: .word _irq
_fiq: .word _fiq
reset:
	ldr r0,=0x40008000
	mcr p15,0,r0,c12,c0,0
init_stack:
	ldr r0,stacktop

	mov sp,r0
	sub r0,#128*4

	msr cpsr,#0xd2
	mov sp,r0
	sub r0,#128*4
	
	msr cpsr,#0xd1
	mov sp,r0
	sub r0,#128*4
	
	msr cpsr,#0xd7
	mov sp,r0
	sub r0,#0

	msr cpsr,#0xdb
	mov sp,r0
	sub r0,#0

	msr cpsr,#0x10
	mov sp,r0
b main

delay_1s:
	ldr r4,=0x1fffffff
delay_loop:
	sub r4,r4,#1
	cmp r4,#0
	bne delay_loop
	mov pc,lr
.align 4
stacktop: .word stack+4*512
.data
	stack:
		.space 4*512
.end
