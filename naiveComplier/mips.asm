.data
fangkedong_str51:  .asciiz"Test 1:"
fangkedong_str52:  .asciiz"left_index="
fangkedong_str53:  .asciiz"right_index="
fangkedong_str54:  .asciiz"Subarray sum="
fangkedong_str58:  .asciiz"Test 1 passed!"
fangkedong_str59:  .asciiz"Test 1 failed!"
fangkedong_str82:  .asciiz"Test 2:"
fangkedong_str83:  .asciiz"left_index="
fangkedong_str84:  .asciiz"right_index="
fangkedong_str85:  .asciiz"Subarray sum="
fangkedong_str89:  .asciiz"Test 2 passed!"
fangkedong_str90:  .asciiz"Test 2 failed!"
fangkedong_str107:  .asciiz"Test 3:"
fangkedong_str108:  .asciiz"left_index="
fangkedong_str109:  .asciiz"right_index="
fangkedong_str110:  .asciiz"Subarray sum="
fangkedong_str114:  .asciiz"Test 3 passed!"
fangkedong_str115:  .asciiz"Test 3 failed!"
fangkedong_str116:  .asciiz"Please input your choice number:(<0>quit <1>Test 1 <2>Test 2 <3>Test 3)"
fangkedong_str122:  .asciiz"Quit Test..."
.text
ori $t3 $0 1
lui $gp 4096
lui $fp 4100
lui $sp 32767
addi $sp $sp 61436
lui $t9 4096
addi $t9 $t9 4096
j main
find_max_crossing_subarray:
sw $ra 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 72($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 76($fp)
lw $t1 76($fp)
lw $t0 72($fp)
add $t2 $t0 $t1
sw $t2 100($fp)
addi $t1 $0 2
lw $t0 100($fp)
div $t0 $t1
mflo $t0
sw $t0 104($fp)
lw $t0 104($fp)
sw $t0 92($fp)
addi $t0 $0 -100000
sw $t0 80($fp)
addi $t0 $0 0
sw $t0 88($fp)
lw $t0 92($fp)
sw $t0 96($fp)
fkd_dobegin2:
addi $t1 $0 0
lw $t2 96($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
lw $t0 0($t1)
sw $t0 108($fp)
lw $t1 108($fp)
lw $t0 88($fp)
add $t2 $t0 $t1
sw $t2 112($fp)
lw $t0 112($fp)
sw $t0 88($fp)
lw $t1 80($fp)
lw $t0 88($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend5
lw $t0 88($fp)
sw $t0 80($fp)
lw $t0 96($fp)
sw $t0 400($t9)
fangkd_ifend5:
addi $t1 $0 1
lw $t0 96($fp)
sub $t2 $t0 $t1
sw $t2 116($fp)
lw $t0 116($fp)
sw $t0 96($fp)
lw $t1 72($fp)
lw $t0 96($fp)
slt $t0 $t0 $t1
subu $t0 $t3 $t0
bne $t0 $0 fkd_dobegin2
addi $t0 $0 -100000
sw $t0 84($fp)
addi $t0 $0 0
sw $t0 88($fp)
addi $t1 $0 1
lw $t0 92($fp)
add $t2 $t0 $t1
sw $t2 120($fp)
lw $t0 120($fp)
sw $t0 96($fp)
fkd_dobegin8:
addi $t1 $0 0
lw $t2 96($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
lw $t0 0($t1)
sw $t0 124($fp)
lw $t1 124($fp)
lw $t0 88($fp)
add $t2 $t0 $t1
sw $t2 128($fp)
lw $t0 128($fp)
sw $t0 88($fp)
lw $t1 84($fp)
lw $t0 88($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend11
lw $t0 88($fp)
sw $t0 84($fp)
lw $t0 96($fp)
sw $t0 404($t9)
fangkd_ifend11:
addi $t1 $0 1
lw $t0 96($fp)
add $t2 $t0 $t1
sw $t2 132($fp)
lw $t0 132($fp)
sw $t0 96($fp)
lw $t1 76($fp)
lw $t0 96($fp)
slt $t0 $t1 $t0
subu $t0 $t3 $t0
bne $t0 $0 fkd_dobegin8
lw $t1 84($fp)
lw $t0 80($fp)
add $t2 $t0 $t1
sw $t2 136($fp)
lw $t0 136($fp)
sw $t0 408($t9)
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
find_maximum_subarray:
sw $ra 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 72($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 76($fp)
lw $t1 76($fp)
lw $t0 72($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend14
lw $t0 72($fp)
sw $t0 400($t9)
lw $t0 76($fp)
sw $t0 404($t9)
addi $t1 $0 0
lw $t2 72($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
lw $t0 0($t1)
sw $t0 128($fp)
lw $v0 128($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
fangkd_ifend14:
lw $t1 76($fp)
lw $t0 72($fp)
add $t2 $t0 $t1
sw $t2 132($fp)
addi $t1 $0 2
lw $t0 132($fp)
div $t0 $t1
mflo $t0
sw $t0 136($fp)
lw $t0 136($fp)
sw $t0 80($fp)
lw $t0 80($fp)
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 72($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 144
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 112($fp)
lw $t0 400($t9)
sw $t0 88($fp)
lw $t0 404($t9)
sw $t0 92($fp)
addi $t1 $0 1
lw $t0 80($fp)
add $t2 $t0 $t1
sw $t2 140($fp)
lw $t0 76($fp)
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 140($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 144
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 116($fp)
lw $t0 400($t9)
sw $t0 96($fp)
lw $t0 404($t9)
sw $t0 100($fp)
lw $t0 76($fp)
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 72($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 144
sw $t0 0($fp)
jal find_max_crossing_subarray
lw $t0 408($t9)
sw $t0 120($fp)
lw $t0 400($t9)
sw $t0 104($fp)
lw $t0 404($t9)
sw $t0 108($fp)
addi $t0 $0 108
sw $t0 124($fp)
lw $t0 112($fp)
sw $t0 84($fp)
lw $t1 84($fp)
lw $t0 116($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend19
lw $t0 116($fp)
sw $t0 84($fp)
addi $t0 $0 114
sw $t0 124($fp)
fangkd_ifend19:
lw $t1 84($fp)
lw $t0 120($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend20
lw $t0 120($fp)
sw $t0 84($fp)
addi $t0 $0 109
sw $t0 124($fp)
fangkd_ifend20:
addi $t1 $0 108
lw $t0 124($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase22
lw $t0 88($fp)
sw $t0 400($t9)
lw $t0 92($fp)
sw $t0 404($t9)
lw $v0 84($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
j fkd_switchend21
fkd_nextcase22:
addi $t1 $0 109
lw $t0 124($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase23
lw $t0 104($fp)
sw $t0 400($t9)
lw $t0 108($fp)
sw $t0 404($t9)
lw $v0 84($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
j fkd_switchend21
fkd_nextcase23:
addi $t1 $0 114
lw $t0 124($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase24
lw $t0 96($fp)
sw $t0 400($t9)
lw $t0 100($fp)
sw $t0 404($t9)
lw $v0 84($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
j fkd_switchend21
fkd_nextcase24:
fkd_switchend21:
test1:
sw $ra 8($fp)
addi $t0 $0 0
sw $t0 76($fp)
addi $t0 $0 13
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 84($fp)
lw $t0 84($fp)
sw $t0 76($fp)
addi $t1 $0 3
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 88($fp)
lw $t0 88($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 92($fp)
lw $t0 92($fp)
sw $t0 76($fp)
addi $t1 $0 25
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 96($fp)
lw $t0 96($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 100($fp)
lw $t0 100($fp)
sw $t0 76($fp)
addi $t0 $0 20
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 104($fp)
lw $t0 104($fp)
sw $t0 76($fp)
addi $t1 $0 3
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 108($fp)
lw $t0 108($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 112($fp)
lw $t0 112($fp)
sw $t0 76($fp)
addi $t1 $0 16
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 116($fp)
lw $t0 116($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 120($fp)
lw $t0 120($fp)
sw $t0 76($fp)
addi $t1 $0 23
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 124($fp)
lw $t0 124($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 128($fp)
lw $t0 128($fp)
sw $t0 76($fp)
addi $t0 $0 18
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 132($fp)
lw $t0 132($fp)
sw $t0 76($fp)
addi $t0 $0 20
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 136($fp)
lw $t0 136($fp)
sw $t0 76($fp)
addi $t1 $0 7
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 140($fp)
lw $t0 140($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 144($fp)
lw $t0 144($fp)
sw $t0 76($fp)
addi $t0 $0 12
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 148($fp)
lw $t0 148($fp)
sw $t0 76($fp)
addi $t1 $0 5
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 152($fp)
lw $t0 152($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 156($fp)
lw $t0 156($fp)
sw $t0 76($fp)
addi $t1 $0 22
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 160($fp)
lw $t0 160($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 164($fp)
lw $t0 164($fp)
sw $t0 76($fp)
addi $t0 $0 15
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 168($fp)
lw $t0 168($fp)
sw $t0 76($fp)
addi $t1 $0 4
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 172($fp)
lw $t0 172($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 176($fp)
lw $t0 176($fp)
sw $t0 76($fp)
addi $t0 $0 7
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 180($fp)
lw $t0 180($fp)
sw $t0 76($fp)
addi $t1 $0 1
lw $t0 76($fp)
sub $t2 $t0 $t1
sw $t2 184($fp)
lw $t0 184($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $0 0
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 188
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 80($fp)
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 0
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 8
syscall
addi $v0 $0 1
lw $a0 400($t9)
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 20
syscall
addi $v0 $0 1
lw $a0 404($t9)
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 33
syscall
addi $v0 $0 1
lw $a0 80($fp)
syscall
addi $t1 $0 43
lw $t0 80($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend55
addi $t1 $0 7
lw $t0 400($t9)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend56
lw $t1 404($t9)
addi $t0 $0 10
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend57
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 47
syscall
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
fangkd_ifend57:
fangkd_ifend56:
fangkd_ifend55:
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 62
syscall
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
test2:
sw $ra 8($fp)
addi $t0 $0 0
sw $t0 76($fp)
addi $t0 $0 3
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 84($fp)
lw $t0 84($fp)
sw $t0 76($fp)
addi $t0 $0 5
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 88($fp)
lw $t0 88($fp)
sw $t0 76($fp)
addi $t1 $0 2
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 92($fp)
lw $t0 92($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 96($fp)
lw $t0 96($fp)
sw $t0 76($fp)
addi $t1 $0 6
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 100($fp)
lw $t0 100($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 104($fp)
lw $t0 104($fp)
sw $t0 76($fp)
addi $t1 $0 5
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 108($fp)
lw $t0 108($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 112($fp)
lw $t0 112($fp)
sw $t0 76($fp)
addi $t0 $0 8
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 116($fp)
lw $t0 116($fp)
sw $t0 76($fp)
addi $t0 $0 12
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 120($fp)
lw $t0 120($fp)
sw $t0 76($fp)
addi $t1 $0 5
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 124($fp)
lw $t0 124($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 128($fp)
lw $t0 128($fp)
sw $t0 76($fp)
addi $t1 $0 6
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 132($fp)
lw $t0 132($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 136($fp)
lw $t0 136($fp)
sw $t0 76($fp)
addi $t0 $0 24
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 140($fp)
lw $t0 140($fp)
sw $t0 76($fp)
addi $t0 $0 8
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 144($fp)
lw $t0 144($fp)
sw $t0 76($fp)
addi $t0 $0 6
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 148($fp)
lw $t0 148($fp)
sw $t0 76($fp)
addi $t1 $0 8
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 152($fp)
lw $t0 152($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 156($fp)
lw $t0 156($fp)
sw $t0 76($fp)
addi $t1 $0 7
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 160($fp)
lw $t0 160($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 164($fp)
lw $t0 164($fp)
sw $t0 76($fp)
addi $t1 $0 1
lw $t0 76($fp)
sub $t2 $t0 $t1
sw $t2 168($fp)
lw $t0 168($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $0 0
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 172
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 80($fp)
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 77
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 85
syscall
addi $v0 $0 1
lw $a0 400($t9)
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 97
syscall
addi $v0 $0 1
lw $a0 404($t9)
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 110
syscall
addi $v0 $0 1
lw $a0 80($fp)
syscall
addi $t1 $0 47
lw $t0 80($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend86
addi $t1 $0 5
lw $t0 400($t9)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend87
lw $t1 404($t9)
addi $t0 $0 11
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend88
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 124
syscall
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
fangkd_ifend88:
fangkd_ifend87:
fangkd_ifend86:
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 139
syscall
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
test3:
sw $ra 8($fp)
addi $t0 $0 0
sw $t0 76($fp)
addi $t0 $0 1
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 84($fp)
lw $t0 84($fp)
sw $t0 76($fp)
addi $t1 $0 1
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 88($fp)
lw $t0 88($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 92($fp)
lw $t0 92($fp)
sw $t0 76($fp)
addi $t0 $0 2
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 96($fp)
lw $t0 96($fp)
sw $t0 76($fp)
addi $t1 $0 2
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 100($fp)
lw $t0 100($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 104($fp)
lw $t0 104($fp)
sw $t0 76($fp)
addi $t0 $0 3
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 108($fp)
lw $t0 108($fp)
sw $t0 76($fp)
addi $t1 $0 3
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 112($fp)
lw $t0 112($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 116($fp)
lw $t0 116($fp)
sw $t0 76($fp)
addi $t0 $0 4
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 120($fp)
lw $t0 120($fp)
sw $t0 76($fp)
addi $t1 $0 4
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 124($fp)
lw $t0 124($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 128($fp)
lw $t0 128($fp)
sw $t0 76($fp)
addi $t0 $0 5
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 132($fp)
lw $t0 132($fp)
sw $t0 76($fp)
addi $t1 $0 5
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 136($fp)
lw $t0 136($fp)
addi $t1 $0 0
lw $t2 76($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 76($fp)
add $t2 $t0 $t1
sw $t2 140($fp)
lw $t0 140($fp)
sw $t0 76($fp)
addi $t1 $0 1
lw $t0 76($fp)
sub $t2 $t0 $t1
sw $t2 144($fp)
lw $t0 144($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $0 0
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 148
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 80($fp)
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 154
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 162
syscall
addi $v0 $0 1
lw $a0 400($t9)
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 174
syscall
addi $v0 $0 1
lw $a0 404($t9)
syscall
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 187
syscall
addi $v0 $0 1
lw $a0 80($fp)
syscall
addi $t1 $0 5
lw $t0 80($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend111
addi $t1 $0 8
lw $t0 400($t9)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend112
lw $t1 404($t9)
addi $t0 $0 8
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fangkd_ifend113
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 201
syscall
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
fangkd_ifend113:
fangkd_ifend112:
fangkd_ifend111:
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 216
syscall
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
lw $ra 8($fp)
lw $fp 0($fp)
jr $ra
main:
sw $ra 8($fp)
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 231
syscall
addi $v0 $0 12
syscall
sw $v0 0($fp)
addi $t1 $0 48
lw $t0 0($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase118
j fkd_switchend117
fkd_nextcase118:
addi $t1 $0 49
lw $t0 0($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase119
addi $t0 $fp 0
addi $fp $fp 4
sw $t0 0($fp)
jal test1
j fkd_switchend117
fkd_nextcase119:
addi $t1 $0 50
lw $t0 0($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase120
addi $t0 $fp 0
addi $fp $fp 4
sw $t0 0($fp)
jal test2
j fkd_switchend117
fkd_nextcase120:
addi $t1 $0 51
lw $t0 0($fp)
subu $t0 $t0 $t1
sltiu $t0 $t0 1
beq $t0 $0 fkd_nextcase121
addi $t0 $fp 0
addi $fp $fp 4
sw $t0 0($fp)
jal test3
j fkd_switchend117
fkd_nextcase121:
fkd_switchend117:
addi $v0 $0 4
lui $k0 4097
addi $a0 $k0 303
syscall
j fkd_program_end
fkd_program_end:
