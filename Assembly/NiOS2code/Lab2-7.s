.equ zero,  0b10111111	 /* (7-seg) bit patterns for 0 - 9*/
.equ one,   0b00000110    
.equ two,   0b01101101
.equ three, 0b01111001
.equ four,  0b11110010
.equ five,  0b11011011
.equ six,   0b11011111
.equ seven, 0b10110001
.equ eight, 0b11111111
.equ nine,  0b11111011

.equ JP2,  0x10000070
.equ DJP2, 0b00000000	 /* Output direction = 0 */
.equ DJP1, 0b11111111 

.text /* executable code follows */
.global _start

_start:
	/* initialize base addresses of parallel ports */
	movia r16, 0x10000010 /* green LED base address */
	movia r15, 0x10000040 /* SW slider switch (DIP switches) base address */
	movia r17, 0x0000000F
	movia r12, 0x00000001
	movia r19, JP2        /* JP2 base address */
	movi r10, 10
	
	movia r2, DJP2
	stbio r2, 4(r15)
	
	movia r11, DJP1
	stbio r11, 4(r19)

DO_DISPLAY:
	ldwio r4, 0(r15) /* load slider (DIP) switches */
	and r8, r4, r12 
	beq r9, r0, check_new
	mov r9, r8 
	
	
	#or r5, r4, r5
	#and r18, r5, r17

LOOP2:
#	mov r6, r18 /* use SW (DIP switch) values on LEDG */
	stbio r6, 0(r19) 
#	movia r7, 150000

#DELAY:
#	subi r7, r7, 1
#	bne r7, r0, DELAY
	br DO_DISPLAY


check_new:
	bne r8, r0, increment
	mov r9, r8 
	br DO_DISPLAY

	
get_pattern:
	
	beq r5,r0,ZERO		/* if r3 is 0, branch to ZERO */
	
	cmpeqi r18,r5,0x01	/* compare r3 with 0x1 */
	bne r18,r0,ONE		/* if r3 is 1, branch to ONE */
	
	cmpeqi r18,r5,0x02	/* compare r3 with 0x2 */
	bne r18,r0,TWO		/* if r3 is 1, branch to TWO */
	
	cmpeqi r18,r5,0x03	/* compare r3 with 0x3 */
	bne r18,r0,THREE		/* if r3 is 1, branch to THREE */
	
	cmpeqi r18,r5,0x04	/* compare r3 with 0x4 */
	bne r18,r0,FOUR		/* if r3 is 1, branch to FOUR */
	
	cmpeqi r18,r5,0x05	/* compare r3 with 0x5 */
	bne r18,r0,FIVE		/* if r3 is 1, branch to FIVE */
	
	cmpeqi r18,r5,0x06	/* compare r3 with 0x6 */
	bne r18,r0,SIX		/* if r3 is 1, branch to SIX */
	
	cmpeqi r18,r5,0x07	/* compare r3 with 0x7 */
	bne r18,r0,SEVEN		/* if r3 is 1, branch to SEVEN */
	
	cmpeqi r18,r5,0x08	/* compare r3 with 0x8 */
	bne r18,r0,EIGHT		/* if r3 is 1, branch to EIGHT */
	
	cmpeqi r18,r5,0x09	/* compare r3 with 0x9 */
	bne r18,r0,NINE		/* if r3 is 1, branch to NINE */

	
ZERO:
	
	movia r6, zero
	br LOOP2
	
ONE:
	
	movia r6, one
	br LOOP2
	
TWO:

	movia r6, two
	br LOOP2
	
THREE:

	movia r6, three
	br LOOP2
	
FOUR:

	movia r6, four
	br LOOP2
	
FIVE:

	movia r6, five
	br LOOP2
	
SIX:

	movia r6, six
	br LOOP2
	
SEVEN:

	movia r6, seven
	br LOOP2
	
EIGHT:

	movia r6, eight
	br LOOP2
	
NINE:

	movia r6, nine
	br LOOP2
	
	
increment:
	beq r5, r10, RESET
	addi r5, r5, 1
	mov r9, r8 
	br Done
	

Done:
	br get_pattern
	
	
RESET:
	mov r5, r0
	br Done