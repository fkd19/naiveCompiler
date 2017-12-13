lui $gp 4096
lui $fp 4100
lui $sp 32767
addi $sp $sp 61436
lui $t9 4097
j main
find_max_subarray:
sw $ra 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 44($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 48($fp)
lw $t1 48($fp)
lw $t0 44($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t1 $0 2
lw $t0 4($sp)
addi $sp $sp 4
div $t0 $t1
mflo $t0
sw $t0 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 64($fp)
addi $t0 $0 -100000
sw $t0 52($fp)
addi $t0 $0 0
sw $t0 60($fp)
lw $t0 64($fp)
sw $t0 68($fp)
fkd_dobegin2:
addi $t1 $0 0
lw $t2 68($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
lw $t0 0($t1)
sw $t0 0($sp)
addi $sp $sp -4
lw $t1 4($sp)
addi $sp $sp 4
lw $t0 60($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 60($fp)
lw $t1 52($fp)
lw $t0 60($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend5
lw $t0 60($fp)
sw $t0 52($fp)
lw $t0 68($fp)
sw $t0 400($t9)
fangkd_ifend5:
addi $t1 $0 1
lw $t0 68($fp)
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 68($fp)
lw $t1 44($fp)
lw $t0 68($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t4 $t2 $t3
andi $t4 $t4 1
or $t0 $t4 $t3
bne $t0 $0 fkd_dobegin2
addi $t0 $0 -100000
sw $t0 56($fp)
addi $t0 $0 0
sw $t0 60($fp)
addi $t1 $0 1
lw $t0 64($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 68($fp)
fkd_dobegin8:
addi $t1 $0 0
lw $t2 68($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
lw $t0 0($t1)
sw $t0 0($sp)
addi $sp $sp -4
lw $t1 4($sp)
addi $sp $sp 4
lw $t0 60($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 60($fp)
lw $t1 56($fp)
lw $t0 60($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend11
lw $t0 60($fp)
sw $t0 56($fp)
lw $t0 68($fp)
sw $t0 404($t9)
fangkd_ifend11:
addi $t1 $0 1
lw $t0 68($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 68($fp)
lw $t1 48($fp)
lw $t0 68($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t4 $t2 $t3
andi $t4 $t4 1
or $t0 $t2 $t4
bne $t0 $0 fkd_dobegin8
lw $t1 56($fp)
lw $t0 52($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 408($t9)
lw $ra 8($fp)
lw $fp 0($fp)
jr $31
lw $ra 8($fp)
lw $fp 0($fp)
jr $31
find_maximum_subarray:
sw $ra 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 44($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 48($fp)
lw $t1 48($fp)
lw $t0 44($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fangkd_ifend14
lw $t0 44($fp)
sw $t0 400($t9)
lw $t0 48($fp)
sw $t0 404($t9)
addi $t1 $0 0
lw $t2 44($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
lw $t0 0($t1)
sw $t0 0($sp)
addi $sp $sp -4
lw $v0 4($sp)
addi $sp $sp 4
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $31
fangkd_ifend14:
lw $t1 48($fp)
lw $t0 44($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t1 $0 2
lw $t0 4($sp)
addi $sp $sp 4
div $t0 $t1
mflo $t0
sw $t0 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 52($fp)
lw $t0 52($fp)
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 44($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 100
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 84($fp)
lw $t0 400($t9)
sw $t0 60($fp)
lw $t0 404($t9)
sw $t0 64($fp)
addi $t1 $0 1
lw $t0 52($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 48($fp)
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 100
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 88($fp)
lw $t0 400($t9)
sw $t0 68($fp)
lw $t0 404($t9)
sw $t0 72($fp)
lw $t0 48($fp)
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 44($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 100
sw $t0 0($fp)
jal find_max_subarray
lw $t0 408($t9)
sw $t0 92($fp)
lw $t0 400($t9)
sw $t0 76($fp)
lw $t0 404($t9)
sw $t0 80($fp)
addi $t0 $0 108
sw $t0 96($fp)
lw $t0 84($fp)
sw $t0 56($fp)
lw $t1 56($fp)
lw $t0 88($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend19
lw $t0 88($fp)
sw $t0 56($fp)
addi $t0 $0 114
sw $t0 96($fp)
fangkd_ifend19:
lw $t1 56($fp)
lw $t0 92($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend20
lw $t0 92($fp)
sw $t0 56($fp)
addi $t0 $0 109
sw $t0 96($fp)
fangkd_ifend20:
addi $t1 $0 108
lw $t0 96($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase22
lw $t0 60($fp)
sw $t0 400($t9)
lw $t0 64($fp)
sw $t0 404($t9)
lw $v0 56($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $31
j fkd_switchend21
fkd_nextcase22:
addi $t1 $0 109
lw $t0 96($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase23
lw $t0 76($fp)
sw $t0 400($t9)
lw $t0 80($fp)
sw $t0 404($t9)
lw $v0 56($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $31
j fkd_switchend21
fkd_nextcase23:
addi $t1 $0 114
lw $t0 96($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase24
lw $t0 68($fp)
sw $t0 400($t9)
lw $t0 72($fp)
sw $t0 404($t9)
lw $v0 56($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $ra 8($fp)
lw $fp 0($fp)
jr $31
j fkd_switchend21
fkd_nextcase24:
fkd_switchend21:
main:
sw $ra 8($fp)
addi $v0 $0 11
addi $a0 $0 77
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 120
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 83
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 121
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 80
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 80
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 112
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 121
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 122
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 5
syscall
sw $v0 0($fp)
addi $t1 $0 100
lw $t0 0($fp)
slt $t0 $t1 $t0
beq $t0 $0 fangkd_ifend25
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 121
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 122
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
j fkd_program_end
fangkd_ifend25:
addi $t0 $0 0
sw $t0 4($fp)
fkd_dobegin26:
addi $v0 $0 5
syscall
sw $v0 12($fp)
lw $t0 12($fp)
addi $t1 $0 0
lw $t2 4($fp)
sll $t2 $t2 2
add $t1 $t1 $t2
add $t1 $t1 $t9
sw $t0 0($t1)
addi $t1 $0 1
lw $t0 4($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 4($fp)
lw $t1 0($fp)
lw $t0 4($fp)
slt $t0 $t0 $t1
bne $t0 $0 fkd_dobegin26
addi $t1 $0 1
lw $t0 0($fp)
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $0 0
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 16
sw $t0 0($fp)
jal find_maximum_subarray
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 8($fp)
addi $v0 $0 11
addi $a0 $0 77
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 120
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 83
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 121
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 102
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 95
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 120
syscall
addi $v0 $0 11
addi $a0 $0 61
syscall
addi $v0 $0 1
lw $a0 400($t9)
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 104
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 95
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 120
syscall
addi $v0 $0 11
addi $a0 $0 61
syscall
addi $v0 $0 1
lw $a0 404($t9)
syscall
addi $v0 $0 11
addi $a0 $0 83
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 121
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 61
syscall
addi $v0 $0 1
lw $a0 8($fp)
syscall
j fkd_program_end
fkd_program_end:
