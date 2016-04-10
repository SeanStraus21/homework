.data
array: .space 64
text: .asciiz "Type the string you wish to invert (max chars = 50)"
.text

addi $s2, $zero, 50 #set max
la $a0, text
la $a1, array
addi $a2, $s2, 0
addi $v0, $zero, 54
syscall

beq $a1, -3, EXIT
beq $a1, -2, EXIT
beq $a1, -4, LOOP_1 #if max, skip finding the size

addi $s0, $zero, 0 #i = 0
#find size
LOOP_0:
	lb $s1, array($s0)
	beq $s1, 0, BREAK_0
	beq $s1, 10, BREAK_0
	addi $s0, $s0, 1
	j LOOP_0
BREAK_0:
addi $s2, $s0, 0

LOOP_1:
	blt $s2, 0, EXIT
	lb $a0, array($s2)
	addi $v0, $zero, 11
	syscall
	addi $s2, $s2, -1
	j LOOP_1
EXIT: