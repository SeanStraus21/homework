
# Computing the i-th Fibonacci number using the stack


.data            # Put any data initializations between .data and .text (before or after __start)

str1:	.asciiz "Which Fibonacci number do you want? "
str2:	.asciiz "The Fibonacci number is "

.text
 
		addi $v0, $zero, 4  # li $v0,4  # Set up the system call for print string
		lui $a0, 0x1001      # Hardcoded address. String is expected at 0x10010000
                            # The lui instruction sets the lower 16 bits to zero.
		syscall        # Display the prompt

		addi $v0, $zero, 5  # li $v0, 5 # Set up the system call for read integer
		syscall        # Read the integer into $v0.

		add $s0, $zero, $zero  # li 	$s0, 0		# s0 will hold the i-th Fibonacci number
		add $s1, $zero, $zero  # li	$s1, 0		  # s1 is the count of items on the stack

		addi $sp, $sp, -4	# adjust stack prior to push (add -4)
		sw   $v0, 0($sp)	# Push number onto stack (the i-th Fib. number desired)
		addi $s1, $s1, 1	# count of number of items on stack
		
		addi $v0, $zero, 30  # li $v0, 30 # Set up the system call for time collection
		syscall        # Read the integer into $v0.
		addi $s3, $a0, 0

loop:	lw $t0, 0($sp)		# Pop one item off stack
		addi $sp, $sp, 4	# adjust stack pointer after pop (add +4)
		addi $s1, $s1, -1	# count of number of items on stack

		addi $t7, $t0, -1  	# $t7 = (i-1)
		bgtz $t7, notbase  	# if ( (i-1) > 0) then put other elements on stack because F_i is not yet base case
base:	addi $s0, $s0, 1	# This is Fib. base case, either F_1 = 1 or F_0 = 1
							# Add one to the accumulating Fibonnaci number contained in $s0
		j loopbot			

notbase:
		addi $t0, $t0, -1	# This gives the value of (i-1) so we can find F_(i-1)
		addi $sp, $sp, -4	# adjust stack prior to push (add -4)
		sw   $t0, 0($sp)	# Push number onto stack (the i-th Fib. number desired)
		addi $s1, $s1, 1	# count of number of items on stack
		addi $t0, $t0, -1	# This gives the value of (i-2) so we can find F_(i-2)
		addi $sp, $sp, -4	# adjust stack prior to push (add -4)
		sw   $t0, 0($sp)	# Push number onto stack (the i-th Fib. number desired)
		addi $s1, $s1, 1	# count of number of items on stack
loopbot:bne $s1, $zero, loop

		addi $v0, $zero, 4  # li $v0,4  # Set up the system call for print string
		la   $a0, str2      # la is a pseudoinstruction, will be expanded to two MIPS instructions
		syscall        # Display the prompt

		addi $v0, $zero, 1 # Set up the system call for print integer
		add $a0, $s0, $zero # Set up the system call for print integer
		syscall        # Print the integer
		
		addi $v0, $zero, 30  # li $v0, 30 # Set up the system call for time collection
		syscall        # Read the integer into $v0.
		addi $s4, $a0, 0

		sub $s5, $s4, $s3
