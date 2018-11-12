#Question 2
addi $t0,$0,0
addi $t1,$0,1
second:
slt $t2,$a0,$t1
bne $t2, $0,pass
add $t0, $t0, $t1
addi $t1,$t1,2
j second
pass:
add $v0, $t0,$0
jr $ra


