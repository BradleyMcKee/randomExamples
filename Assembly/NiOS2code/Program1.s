.equ B, 4
.equ D, 5
.equ DIP, 0x10000060

.global _start
.text

_start:	
		
	movia r2, A
	ldw r2, 0(r2)

	movi r3, B
	
	movia r4, C
	ldw r4, 0(r4)

	movi r5, D

	mov r6, r0
	mov r7, r0
	br MULT

ADD:
	add r8, r6, r11
	br STOP
MULT:	
	add r6, r6, r2
	addi r9, r9, 1
	beq r9, r3, DIV
	br MULT
DIV:
	add r10, r10, r5
	addi r11, r11, 1
	beq r10, r4, ADD
	br DIV
STOP:
	br STOP	
	
.data
A:
.word 6
C:
.word 30
