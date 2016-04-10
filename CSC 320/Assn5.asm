.data
array: .space 64
input: .space 64
str0: .asciiz "Input a string \n"
str1: .asciiz "The string is a Palindrome\n"
str2: .asciiz "The string is not a Palindrome\n"
str3: .asciiz "Would you like to check a new string? (y for yes, n for no)\n"

.text

j main

main:
addi $s0, $zero, 89 #continue flag = 'y'

main_loop:
	bne $s0, 89, main_break
	
	#show prompt
	addi $v0, $zero, 4
	la $a0, str0
	syscall
	
	#read string
	addi $v0, $zero, 8
	la $a0, input
	addi $a1, $zero, 64
	syscall
	
	#initialize loop
	addi $s1, $zero, 0 #i=0
	addi $s2, $zero, 0 #size=0
	loop_0:
		lb $t0, input($s1)
		beq $t0, 0, break_0#break if null character
		bgt $t0, 122, if_1#skip if greater than valid range
		blt $t0, 48, if_1#skip if less than valid range
			blt $t0, 91, if_2#skip if already uppercase
				blt $t0, 97, if_1#skip if invalid
				addi $t0, $t0, -32#convert to uppercase
			if_2:
			sb $t0, array($s2)#store valid, formatted character in array
			addi $s2, $s2, 1#increment size
		if_1:
		addi $s1, $s1, 1
		j loop_0
	break_0:
	
	addi $s3, $zero, 1 #flag = true
	addi $s1, $zero, 0 #i = 0
	loop_1:
		beq $s1, $s2, break_1
		sub $t2, $s2, $s1 #t2 = size - i
		addi $t2, $t2, -1 #offset by one byte
		lb $t0, array($s1) #get array[i]
		lb $t1, array($t2) #get array[array.size() - i]
		beq $t0, $t1, if_3#if they are not the same
			addi $s3, $zero, 0#flag = false
			j break_1#break
		if_3:
		addi $s1, $s1, 1
		j loop_1
	break_1:
	
	la $a0, str1 #default: show is-palindrome string
	beq $s3, 1, if_4
		la $a0, str2 #if flag == false: show non-palindrome string
	if_4:
	addi $v0, $zero, 4
	syscall
	
	#prompt for continue
	addi $v0, $zero, 4
	la $a0, str3
	syscall
	#get character
	addi $v0, $zero, 12
	syscall
	addi $s0, $v0, 0
	bne $s0, 121, if_0
		addi $s0, $zero, 89 #convert to uppercase if input = y
	if_0:
	j main_loop
main_break:
