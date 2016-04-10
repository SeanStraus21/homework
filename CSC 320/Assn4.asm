.data
array: .space 64
str1: .asciiz "Input First Positive Integer \n"
str2: .asciiz "Input Second Positive Integer \n"
.text

j main

#Peasant Multiplication
peasant_mult:
addi $v0, $zero, 0
begin:
beq $a1, 1, end
	andi $t0, $a1, 1 #skip if even
	beq $t0, 0, else
		#if odd
	add $v0, $v0, $a0
	else:
	sll $a0, $a0, 1
	srl $a1, $a1, 1
j begin
end:
add $v0, $v0, $a0
jr $ra

main:
#prompt 1
addi $v0, $zero, 4
la $t0, str1
addi $a0, $t0, 0
syscall
#get int1
addi $v0, $zero, 5
syscall
addi $s0, $v0, 0
#prompt 1
addi $v0, $zero, 4
la $t0, str2
addi $a0, $t0, 0
syscall
#get int1
addi $v0, $zero, 5
syscall
addi $s1, $v0, 0
#peasant algorithm
addi $a0, $s0, 0 #load parameter 1
addi $a1, $s1, 0 #load parameter 2
jal peasant_mult
addi $s0, $v0, 0 #store result
#print result
addi $v0, $zero, 1
addi $a0, $s0, 0
syscall