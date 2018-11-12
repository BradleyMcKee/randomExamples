.global _start
.text

_start:

	movi r9,4 #4 bit shift
	movi r8,8 #8 bit shift
	movia r7, DECOMPRESSED
	movia r6, COMPRESSED
			
LOAD:
	ldw r3, 0(r6) 
	beq r3, r0, NONEFOUND
	ldw r4, 4(r6) 
STORE:
	stw r4, 0(r7)
	add r7, r7, r9
	subi r3, r3, 1
	bne r3, r0,STORE
	br NEXT
NEXT:
	add r6, r6, r8
	br LOAD
NONEFOUND: 
	br NONEFOUND
		
.data
COMPRESSED:
.word 3, 0xEECE, 2, 0x0259, 4, 0xF00D, 5, 0xCAFE, 0
DECOMPRESSED:
.skip 4*(3+2+4+5)	