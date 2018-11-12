.equ GREENLEDS, 0x10000010 #memory location of LEDs
.text
.global main

main: 
	movia r5, GREENLEDS #store memory location of LEDs
    movi r1, 0b00001000 #store mask for checking terminal LED
	movi r2, 0b00010000 #store mask for checking terminal LED 
    movi r8, 0x7FFF #store mask for checking terminal count delay
	addi r10,r10,1 #placeholder for ror r10 = 1 bit
	add r8, r8, r8 #double mask to increase delay
	add r8, r8, r8 
#LEDS THAT SHOW UP, 0,1,2,3,7
loadL: movi r4, 0b00000001#LSB
loadR: movi r4, 0b10000000#MSB
	
loop: 
	stw r4,0(r5)
	mov r7,r0

countL:
	addi r7,r7,1
	bne r7,r8,countL
	beq r1,r4,loadR
	roli r4,r4,1 #rC,rA,IMMED5
	br loop
	
countR:
	addi r7,r7,1
	bne r7,r8,countR
	beq r2,r4,loadL
	ror r4,r4,r10 #rC,rA,rB r10=1
	br loop
	