.data

arrayf: .space 64

.text

main:

addi $s0, $zero, 0
LOOP1:
beq $s0, 60, END1
#generate random float
addi $v0, $zero, 43
syscall
s.s $f0, arrayf($s0)
#push
addi $s0, $s0, 4
j LOOP1
END1:

addi $s0, $zero, 0
LOOP2:
beq $s0, 5, END2
add.s $f1, $f2, $f2
addi $s1, $zero, 0
	INNER_LOOP2:
	beq $s1, 3, INNER_END2
	#get address
	mul $t0, $s1, 5
	add $t0, $s0, $t0
	mul $t0, $t0, 4
	#add to buffer
	l.s $f0, arrayf($t0)
	add.s $f1, $f1, $f0
	#increment j++
	addi $s1, $s1, 1
	j INNER_LOOP2
	INNER_END2:
#print float
addi $v0, $zero, 2
add.s $f12, $f1, $f2
syscall

#print semi-colon for readability
addi $v0, $zero, 11
addi $a0, $zero, 32
syscall
#increment i++
addi $s0, $s0, 1
j LOOP2
END2: