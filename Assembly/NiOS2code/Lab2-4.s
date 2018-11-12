
.equ JP1,  0x10000060
.equ JP2,  0x10000070
.equ JP3,  0x10000080
.equ LEDG, 0x10000010
.equ DJP1, 0b11111111 	 /* Output direction = 1 */
.equ DJP2, 0b00000000	 /* Output direction = 0 */

.equ zero,  0b10111111	 /* bit patterns for 0 - 9*/
.equ one,   0b00000110    
.equ two,   0b01101101
.equ three, 0b01111001
.equ four,  0b11110010
.equ five,  0b11011011
.equ six,   0b11011111
.equ seven, 0b10110001
.equ eight, 0b11111111
.equ nine,  0b11111011  

.global _start

_start:

	movia r15, JP1        /* JP1 base address */
	movia r17, JP2        /* JP2 base address */
	
	movia r8, DJP2
	stbio r8, 4(r15)
	
	movia r9, DJP1
	stbio r9, 4(r17)
	
	movia r3, 8
	movia r16, 0x00000001
	movia r12,  0x00000080
#	mov r10, r16

DO_DISPLAY:
	ldbio r4, 0(r15)
	mov r10, r16
	mov r5, r0
back:
	and r11, r4, r10
	bne r11, r0, increment
	beq r10, r12, Done
	slli r10, r10, 1
	br back
#	stwio r4, 0(r17)
Done: 
	br get_pattern
LOOP2:
	stbio r4, 0(r17)	
	movia r7, 150000

DELAY:
	subi r7, r7, 1
	bne r7, r0, DELAY
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
	
	movia r4, zero
	br LOOP2
	
ONE:
	
	movia r4, one
	br LOOP2
	
TWO:

	movia r4, two
	br LOOP2
	
THREE:

	movia r4, three
	br LOOP2
	
FOUR:

	movia r4, four
	br LOOP2
	
FIVE:

	movia r4, five
	br LOOP2
	
SIX:

	movia r4, six
	br LOOP2
	
SEVEN:

	movia r4, seven
	br LOOP2
	
EIGHT:

	movia r4, eight
	br LOOP2
	
NINE:

	movia r4, nine
	br LOOP2
	
	
increment:
	beq  r5, r3, Done
	addi r5, r5, 1
	beq r10, r12, Done
	slli r10, r10, 1
	br back
	