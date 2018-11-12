/* Fibonnacci*/
.equ  Fibonacci, 0X00001000   #ADDRESS OF FIBONNACCI
.equ GREENLEDS,  0X10000010   #ADDRESS OF GREEN LEDs
.equ        SW,  0x10000040   #ADDRESS OF SW
.equ      KEY1,  0X10000050   #ADDRESS OF KEY1

.text
.global _main


_main:
	movia r4, GREENLEDS #Outputs the value of the Fibonnacci Sequence
	movia r5, SW        #Sets the value of N
	movia r6, KEY1      #Starting push button
	movi r23, 1         #Register equal to '1' for boolean
	movi r20, 2
	movi r19, Fibonacci 

start:
	movi r7, 0	    #First value of Fibonnacci Sequence 	
	movi r8, 1	    #Second value of Fibonnacci Sequence
	movi r9, 0	    #Output of Fibonnacci Sequence
	ldbu r21, 0(r5)     #Value of switch
	ldbu r22, 0(r6)	    #Value of KEY1	
	bne r22, r20, start #If KEY1 is pressed then continue
	
CALC:

	beq r21, r0, LED
	add r9, r7, r8      #Fibonnacci equation
	stw r7, 0(r19)
	stw r8, 4(r19)
	stw r9, 8(r19)
	sub r7, r7, r7
	add r7, r8, r0
	sub r8, r8, r8
	add r8, r9, r0
	addi r21, r21, -1     #Loop completed N-1
	bgtu r21, r23, CALC #Continue loop until N = 1
LED:
	stw r9, 0(r4)       #Store value of r9 into LEDs
	br start            #Reset system to run program again