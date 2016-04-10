.data
arrayA: .word 1, 1, 0, 0
arrayB: .word 0xffff, 0xffff, 0xffff, 0xffff
.text

addi $s0, $zero, 1  # This is a common way to initialize a register: addi the desired value to $zero
#I changed the setup a little bit to improve readability. I also used the label instead of la to save time
#I hope this isn't a problem
top: 	addi $s0, $s0, 1 #increment counter
	subi $t1, $s0, 1 # i-1
	subi $t2, $s0, 2 # i-2
	sll $t0, $s0, 2 #address + i*4
	sll $t1, $t1, 2 #address + (i-1)*4
	sll $t2, $t2, 2 #address + (i-2)*4
	lw $s1, arrayA($t1) # load fib(i-1)
	lw $s2, arrayA($t2) # load fib(i-2)
	add $t3, $s1, $s2 #fib(i) = fib(i-1) + fib(i-2)
	sw $t3, arrayA($t0)
	bne $s0, 15, top # while i<=6

addi $s0, $zero, 0 #i=0
LOOP_1:
	sll $t0, $s0, 2 #address + i*4
	addi $a0, $zero, 1
	addi $v0, $zero, 41
	syscall
	sw $a0, arrayB($t0)
	addi $s0, $s0, 1 #i++
	bne $s0, 6, LOOP_1 #while (i != 6)

