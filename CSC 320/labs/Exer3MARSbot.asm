# An example MIPSbot program that shows controlling MIPSbot's velocity
# and orientation.


.data
coordinates: .word
	#start Initials
	0,50,120 #start position
	1,80,120
	1,90,100
	1,50,70
	1,60,50
	1,80,50
	0,120,120 #move to next letter
	1,150,120
	1,160,100
	1,120,70
	1,130,50
	1,150,50
	#END
.text

  # Register usage:
  # $a0 -- address for memory-mapped IO heading value  0xffff8010
  # $a1 -- address for memory-mapped IO "leave a track" value  0xffff8020;
  # $a2 -- address for memory-mapped IO "Where are we X" value   0xffff8030;
  # $a3 -- address for memory-mapped IO "Where are we Y" value    0xffff8040;
  # $v0 -- address for memory-mapped IO "Move" value    0xffff8050;
  lui $a0, 0xffff
  ori $a0, $a0, 0x8010
  addi $a1, $a0, 0x10
  addi $a2, $a1, 0x10
  addi $a3, $a2, 0x10
  addi $v0, $a3, 0x10
  addi $t1, $zero, 1
  
  lw $s0, 0($a2)  # Find initial bot (X,Y) location
  lw $s3, 0($a3)
  
  #main loop
  
  lw $s0, 0($a2)  # initial coordinates are 0,0
  lw $s3, 0($a3)
  
  la $t2, coordinates
  
LOOP_MAIN:
  #Load coordinates of initial goal
  lw $s6, 0($t2)
  lw $s2, 4($t2)
  lw $s5, 8($t2) 
  
  addi $t2, $t2, 12  #i+=3
  
  sw $s6, 0($a1) #bool track = true;
  
#move on x axis

  beq $s0, $s2, END_X # if (x0 == x1) break;
  blt $s0, $s2, EAST # elif (x0 < x1) goto east(90)
    # else west(270).
    li	$t0, 270   # a = 270
    sw $t0, 0($a0) 
    sw $t1, 0($v0) # bool move = true
    MOVE_E:
      lw $s1, 0($a2)  # Read X current value
      ble $s1, $s2, END_X # while (x0 > x1)
      j MOVE_E
  EAST:
    li	$t0, 90   # angle of movement
    sw $t0, 0($a0) # store at command slot
    sw $t1, 0($v0) # bool move = true
    MOVE_W:
      lw $s1, 0($a2)
      bge $s1, $s2, END_X # while (x0 < x1) 
      j MOVE_W
END_X:

#move on y axis
  beq $s3, $s5, END_Y # if (y0 == y1) break;
  blt $s3, $s5, SOUTH # elif (x0 < x1) goto South (180)
    # Else go north (0)
    li	$t0, 0   # a = 0
    sw $t0, 0($a0) # store at command slot
    sw $t1, 0($v0) # bool move = true
    MOVE_N:
      lw $s4, 0($a3) 
      ble $s4, $s5, END_Y # while y1 > y0
      j MOVE_N
  SOUTH:
    # Else go south (180)
    li	$t0, 180   # a = 180
    sw $t0, 0($a0) # store at command slot
    sw $t1, 0($v0) # bool move = true;
    MOVE_S:
      lw $s4, 0($a3)
      bge $s4, $s5, END_Y # while y1 < y0
      j MOVE_S

END_Y:#end of loop, iterate forward
  sw $zero, 0($a1) # bool track = false;
  add $s0, $zero, $s2  # x0 = x1;
  add $s3, $zero, $s5  # y0 = y1;
  j LOOP_MAIN


  sw $zero, 0($v0) # bool move = false;

