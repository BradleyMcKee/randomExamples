.equ Fibonacci, 0X00001000   
.equ GLED,  0X10000010  
.equ DIP,  0x10000040   
.equ KEY1,  0X10000050   

.text
.global _start


_start:
	movia r2, GLED 
	movia r3, DIP      
	movia r4, KEY1     
	movi r13, 1        
	movi r10, 2
	movi r19, Fibonacci 

START:
	movi r5, 0	   	
	movi r6, 1	    
	movi r7, 0	    
	ldbu r11, 0(r3)     
	ldbu r12, 0(r4)	    	
	bne r12, r10, START 
	
CALCULATE:

	beq r11, r0, DISPLAY
	add r7, r5, r6      
	stw r5, 0(r19)
	stw r6, 4(r19)
	stw r7, 8(r19)
	sub r5, r5, r5
	add r5, r6, r0
	sub r6, r6, r8
	add r6, r7, r0
	addi r11, r11, -1     
	bgtu r11, r13, CALCULATE 
DISPLAY:
	stw r7, 0(r2)       
	br START            