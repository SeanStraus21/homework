.data
arrayA: .space 64

.text
j MAIN

MAIN:
la $s0, arrayA

li $t0, 16		# i=16
LOOP:
li $v0, 42		#set syscall to random number generation
li $a0, 0		#set id of random number generator
li $a1, 500		#set max range
syscall			#generate the random number
sw $a0, ($s0)	#store that number in the array
addi $t0, $t0, 1	#i++
addi $s0, $s0, 4 	
bne $t0, 20, LOOP 	# while i != 20

la $a0, arrayA
li $a1, 4 #arg1 = size
jal SUM #sum(arg0,arg1)

BACK:
addi $a0, $v0, 0
li $v0, 1
syscall

j EXIT


#$a0 = array.address
#$a1 = array.size
SUM:
li $t0, 0 #i = 0
li $s1, 0
SUM_LOOP:
lw $t1, ($a0)
add $s1, $s1, $t1 #output + arrayA[i]
addi $a0, $a0, 4 #address += 4
addi $t0, $t0, 1 #i++
bne $t0, $a1, SUM_LOOP
addi $v0, $s1, 0
j BACK

EXIT:
