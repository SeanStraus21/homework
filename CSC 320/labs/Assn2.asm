.data
array: .word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

.text
j MAIN

#POW(x, exponent)
POW: # multiplies $a1 by itself $a0 times and stores the result in $v0. jumps back
addi $v0, $zero, 1
addi $t0, $zero, 0
POW_LOOP:
beq $t0, $a0, POW_BREAK
mult $v0,$a1
mflo $v0
addi $t0, $t0, 1
j POW_LOOP
POW_BREAK:
jr $ra

MAIN:
la $s0, array
addi $s1, $zero, 0#i=0
OUTER_LOOP: # outer loop goes through each chunk of memory
	addi $s2, $zero, 8#j=8
	INNER_LOOP: #inner loop changes the number stored in the current address
		li $a1, 16
		addi $a0, $s2, 0
		jal POW
		addi $s3, $v0, 0
		sw $s3, ($s0) #store the generated number ($s3) at the current indice ($s0)
	subi $s2, $s2, 1#j--
	bne $s2, -1, INNER_LOOP
	sw $zero, ($s0)
	addi $s1, $s1, 1 #i++
	addi $s0, $s0, 4 #address += word
bne $s1, 8, OUTER_LOOP
j END

END:


