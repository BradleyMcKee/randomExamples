.text
.equ LEDs, 0x10000010
.equ SWITCHES, 0x10000040

.global _start

_start:

movia r2, LEDs # Address of red LEDs. */
movia r3, SWITCHES # Address of switches. */

movi r5, 0b00001111

LOOP: #ldw r4, (r3) # Read the state of switches. */
stw r5, 0(r2) # Display the state on LEDs. */

br LOOP

.end