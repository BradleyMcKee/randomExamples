#Question 4d
li $t0, 0x1234ABCD
lui $t2, 0x1001
sw $t0, 0($t2)
lb $s0, 2($t2) 

lbu $t3, 0xb($t2)
lbu $t4, 0xa($t2)
lbu $t5, 0x9($t2)
lbu $t6, 0x8($t2)
sll $t4,$t4,8
sll $t5,$t5,16
sll $t6,$t6,24
add $t7,$t6,$t5
add $t7,$t7,$t4
add $t7,$t7,$t3
sw $t1,20($t2)
