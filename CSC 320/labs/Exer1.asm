.data
str1:	.asciiz "The  number was:  "

.text
addi $s0, $zero, 2   # insert your chosen number in that blank
sll $s0, $s0, 1
addi $s0, $s0, 5
sll $t0, $s0, 5 #32
sll $t1, $s0, 4 #16
sll $t2, $s0, 1 #2
add $s0, $t0, $t1 #s0 = 32 + 16 
add $s0, $s0, $t2 #s0 = s0 + 2
addi $s0, $s0, 2015 #s0 = s0 + 2015
subi $s0, $s0, 250 #s0 = s0 - 250
subi $s0, $s0, 1992 #s0 = s0 - 1992

li $v0,4		# system call code for print string
la $a0, str1		# address of string to be printed
syscall			# Call the OS to print the string
li $v0, 1		# system call code for print int
add $a0, $zero, $s0   # Copy the value to be printed to $a0
syscall			# Call the OS to print the integer
