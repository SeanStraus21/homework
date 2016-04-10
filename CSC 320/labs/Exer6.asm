.data
array: .space 64

.text
j MAIN

# test_prime(n): returns 1 if n is prime, else returns 0
#$a0 = n
TEST_PRIME:
addi $t0, $zero, 2
addi $v0, $zero, 1 #output = true
PRIME_LOOP:
	beq $t0, $a0, PRIME_BREAK #while i != n
	div $a0, $t0 #hi = n mod i
	mfhi $t1 # temp = hi
	beq $t1, 0, PRIME_FAIL #if divisible, fail
	addi $t0, $t0, 1 #i++
	j PRIME_LOOP
	PRIME_FAIL:
	addi $v0, $zero, 0 #output = false, break;
PRIME_BREAK:
jr $ra


MAIN:
la $s0, array #get address of array
addi $s1, $zero, 2#i = 2
addi $s2, $zero, 0#prime_count = 0
LOOP_0:
	beq $s2, 100, BREAK_0 #while prime_count < 100
	addi $a0, $s1, 0 #n=i
	jal TEST_PRIME
	beq $v0, 0, NOT_PRIME#if i is not prime, skip to NOT_PRIME, else:
		addi $s2, $s2, 1#prime_counter++
		sw $s1, ($s0) #array[array_index] = i
		addi $s0, $s0, 4#array_index += word_length
	NOT_PRIME:
	addi, $s1, $s1, 1 #i++
	j LOOP_0
BREAK_0:
la $s0, array #get the address of array
addi $s1, $zero, 0 #i = 0
LOOP_1:
	beq $s1, 100, BREAK_1
	#PRINT STUFF HERE
	lw $a0,($s0)
	addi $v0, $zero, 1
	syscall
	addi $a0,$zero, 32 #char = space (32 in ASCII)
	addi $v0, $zero, 11
	syscall
	#PRINT STUFF HERE
	addi $s0, $s0, 4
	addi $s1, $s1, 1
	j LOOP_1
BREAK_1: