.equ B, 4
.equ D, 4
.equ DIP, 0x10000060 

.global _start

.text

_start:	
		
	movi r15,15
	movia r2, DIP
	ldbio r4, 0(r2)
	srli r6,r4,4
	and r6,r6,r15 ##C
	and r4,r4,r15 ##A
		

	movi r5, B
	movi r7, D
	br MULT

MULT:
	add r8, r8, r4
	addi r9, r9, 1
	beq r9, r5, DIV
	br MULT

DIV:
	movia r12, DIP
	add r10, r10, r7
	addi r11, r11, 1
	beq r10, r6, ADD
	br DIV
ADD:
	add r13, r8, r11
	br _start
.data