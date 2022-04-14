/** WARNING:
 * Only include this header file from assembly code!!!
 */

.syntax unified
.cpu cortex-m0plus
.thumb

.section .vectors, "ax"
.align 2

.global vector_table
vector_table:
.word _stack
.word _reset
.word NMI_Handler
.word HardFault_Handler
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word SVCall_Handler
.word isr_invalid // Reserved, should never fire
.word isr_invalid // Reserved, should never fire
.word PendSV_Handler
.word SysTick_Handler
.word isr_irq0
.word isr_irq1
.word isr_irq2
.word isr_irq3
.word isr_irq4
.word isr_irq5
.word isr_irq6
.word isr_irq7
.word isr_irq8
.word isr_irq9
.word isr_irq10
.word isr_irq11
.word isr_irq12
.word isr_irq13
.word isr_irq14
.word isr_irq15
.word isr_irq16
.word isr_irq17
.word isr_irq18
.word isr_irq19
.word isr_irq20
.word isr_irq21
.word isr_irq22
.word isr_irq23
.word isr_irq24
.word isr_irq25
.word isr_irq26
.word isr_irq27
.word isr_irq28
.word isr_irq29
.word isr_irq30
.word isr_irq31

// all default exception handlers do nothing, and we can check for them being set to our
// default values by seeing if they point to somewhere between __defaults_isrs_start and __default_isrs_end
.global __default_isrs_start
__default_isrs_start:

// Declare a weak symbol for each ISR.
// By default, they will fall through to the undefined IRQ handler below (breakpoint),
// but can be overridden by C functions with correct name.

.macro decl_isr_bkpt name
.global \name
.weak \name
.type \name,%function
.thumb_func
\name:
	bkpt #0
.endm

// these are separated out for clarity
@ decl_isr_bkpt isr_invalid
@ decl_isr_bkpt NMI_Handler
@ decl_isr_bkpt HardFault_Handler
@ decl_isr_bkpt SVCall_Handler
@ decl_isr_bkpt PendSV_Handler
@ decl_isr_bkpt SysTick_Handler
decl_isr_bkpt isr_invalid
.extern NMI_Handler
.extern HardFault_Handler
.extern SVCall_Handler
.extern PendSV_Handler
.extern SysTick_Handler

.global __default_isrs_end
__default_isrs_end:

.macro decl_isr name
.weak \name
.type \name,%function
.thumb_func
\name:
.endm

decl_isr isr_irq0
decl_isr isr_irq1
decl_isr isr_irq2
decl_isr isr_irq3
decl_isr isr_irq4
decl_isr isr_irq5
decl_isr isr_irq6
decl_isr isr_irq7
decl_isr isr_irq8
decl_isr isr_irq9
decl_isr isr_irq10
decl_isr isr_irq11
decl_isr isr_irq12
decl_isr isr_irq13
decl_isr isr_irq14
decl_isr isr_irq15
decl_isr isr_irq16
decl_isr isr_irq17
decl_isr isr_irq18
decl_isr isr_irq19
decl_isr isr_irq20
decl_isr isr_irq21
decl_isr isr_irq22
decl_isr isr_irq23
decl_isr isr_irq24
decl_isr isr_irq25
decl_isr isr_irq26
decl_isr isr_irq27
decl_isr isr_irq28
decl_isr isr_irq29
decl_isr isr_irq30
decl_isr isr_irq31

// All unhandled USER IRQs fall through to here
.global __unhandled_user_irq
.thumb_func
__unhandled_user_irq:
	bl __get_current_exception
	subs r0, #16
.global unhandled_user_irq_num_in_r0
unhandled_user_irq_num_in_r0:
	bkpt #0

.global __get_current_exception
.thumb_func
__get_current_exception:
	mrs r0, ipsr
	uxtb r0, r0
	bx lr

