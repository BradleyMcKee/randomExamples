#Question 4c
li $t0, 0x1234ABCD
lui $t2, 0x1001
sw $t0, 0($t2)
lb $s0, 2($t2) 


lbu $s2, 0xb($t2)
sll $s2, $s2, 24


