.text
.equ LEDs, 0x10000010
.equ SWITCHES, 0x10000040

.global _start

_start:

movia r2, LEDs # Address of red LEDs. */
movia r3, SWITCHES # Address of switches. */

LOOP: ldw r4, (r3) # Read the state of switches. */

stw r4, 0(r2) # Display the state on LEDs. */

br LOOP

.end