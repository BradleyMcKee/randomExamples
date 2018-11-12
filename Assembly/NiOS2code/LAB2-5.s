.text/* executable code follows */

.global _start

_start:

 /* initialize base addresses of parallel ports */
movia r16, 0x10000010   /* green LED base address */

movia r15, 0x10000040   /* SW slider switch (DIP switches) base address */

movia r17, 0x10000050   /* pushbutton KEY base address */

DO_DISPLAY:


ldwio r4, 0(r15)           /* load slider (DIP) switches */

mov r6, r4                            /* use SW (DIP switch) values on LEDG */   

stwio r6, 0(r16)            /* store to LEDG */

movia r7, 150000        /* delay counter */

WAIT:
    
ldwio r5, 0(r17) /* load pushbuttons */

mov r8, r5

beq r8, r0, WAIT

DELAY:

subi r7, r7, 1

bne r7, r0, DELAY

br DO_DISPLAY

.data                               /* data follows */

.end 