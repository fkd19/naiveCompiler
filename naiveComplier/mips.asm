lui $gp 4096
lui $fp 4100
lui $sp 32767
addi $sp $sp 61436
lui $t9 4097
j main
factorial:
sw $31 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 44($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 48($fp)
addi $t1 $0 0
lw $t0 44($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fangkd_ifend0
addi $v0 $0 1
sw $v0 0($sp)
addi $sp $sp -4
lw $31 8($fp)
lw $fp 0($fp)
jr $31
fangkd_ifend0:
addi $t1 $0 0
lw $t0 44($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
or $t0 $t2 $t3
beq $t0 $0 fangkd_ifend1
addi $t1 $0 1
lw $t0 44($fp)
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t0 $0 0
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 56
sw $t0 0($fp)
jal factorial
lw $t1 4($sp)
addi $sp $sp 4
lw $t0 44($fp)
mult $t0 $t1
mflo $t0
sw $t0 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 52($fp)
fangkd_ifend1:
lw $v0 52($fp)
sw $v0 0($sp)
addi $sp $sp -4
lw $31 8($fp)
lw $fp 0($fp)
jr $31
getresult:
sw $31 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 44($fp)
addi $t0 $0 0
sw $t0 0($gp)
addi $gp $gp 4
lw $t0 44($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 52
sw $t0 0($fp)
jal factorial
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 0($t9)
lw $31 8($fp)
lw $fp 0($fp)
jr $31
count:
sw $31 8($fp)
lw $t0 -4($gp)
addi $gp $gp -4
sw $t0 44($fp)
addi $t0 $0 0
sw $t0 48($fp)
addi $t1 $0 0
lw $t0 44($fp)
slt $t0 $t0 $t1
beq $t0 $0 fangkd_ifend4
lw $t1 44($fp)
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 44($fp)
fangkd_ifend4:
addi $t1 $0 10
lw $t0 44($fp)
slt $t0 $t0 $t1
beq $t0 $0 fangkd_ifend6
addi $v0 $0 1
sw $v0 0($sp)
addi $sp $sp -4
lw $31 8($fp)
lw $fp 0($fp)
jr $31
fangkd_ifend6:
fkd_dobegin7:
lw $t1 48($fp)
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t1 4($sp)
addi $sp $sp 4
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t1 $0 1
lw $t0 4($sp)
addi $sp $sp 4
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 48($fp)
addi $t1 $0 10
lw $t0 44($fp)
div $t0 $t1
mflo $t0
sw $t0 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 44($fp)
addi $t1 $0 10
lw $t0 44($fp)
slt $t0 $t1 $t0
bne $t0 $0 fkd_dobegin7
addi $t1 $0 1
lw $t0 48($fp)
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $v0 4($sp)
addi $sp $sp 4
sw $v0 0($sp)
addi $sp $sp -4
lw $31 8($fp)
lw $fp 0($fp)
jr $31
print_start:
sw $31 8($fp)
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 112
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
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
lw $31 8($fp)
lw $fp 0($fp)
jr $31
test_empty:
sw $31 8($fp)
lw $31 8($fp)
lw $fp 0($fp)
jr $31
main:
sw $31 8($fp)
addi $t0 $0 67
sw $t0 16($fp)
addi $t1 $0 1
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 0($fp)
addi $t1 $0 3
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t1 $0 1
lw $t0 4($sp)
addi $sp $sp 4
add $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 4($t9)
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 118
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 102
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 118
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 91
syscall
addi $v0 $0 11
addi $a0 $0 48
syscall
addi $v0 $0 11
addi $a0 $0 93
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
lw $t0 4($t9)
sw $t0 0($sp)
addi $sp $sp -4
addi $v0 $0 1
lw $a0 4($sp)
addi $sp $sp 4
syscall
addi $t1 $0 67
lw $t0 16($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase18
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 118
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 102
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 99
syscall
addi $v0 $0 11
addi $a0 $0 104
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 118
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 95
syscall
addi $v0 $0 11
addi $a0 $0 102
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
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
lw $a0 16($fp)
syscall
j fkd_switchend17
fkd_nextcase18:
fkd_switchend17:
addi $t1 $0 0
lw $t0 0($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
or $t0 $t2 $t3
beq $t0 $0 fangkd_ifend19
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
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 118
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 102
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($fp)
syscall
fangkd_ifend19:
addi $t0 $fp 0
addi $fp $fp 20
sw $t0 0($fp)
jal print_start
fkd_dobegin20:
addi $v0 $0 5
syscall
sw $v0 0($fp)
lw $t1 0($fp)
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t1 $0 0
lw $t0 4($sp)
addi $sp $sp 4
slt $t0 $t1 $t0
bne $t0 $0 fkd_dobegin20
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 112
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
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 119
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 97
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 110
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 44
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 104
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 121
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 119
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 98
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 111
syscall
addi $v0 $0 11
addi $a0 $0 109
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 5
syscall
sw $v0 8($fp)
addi $v0 $0 5
syscall
sw $v0 12($fp)
fkd_dobegin22:
lw $t1 0($fp)
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
addi $t1 $0 13
addi $t0 $0 0
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t1 4($sp)
addi $sp $sp 4
lw $t0 4($sp)
addi $sp $sp 4
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t4 $t2 $t3
andi $t4 $t4 1
or $t0 $t2 $t4
beq $t0 $0 fangkd_ifend23
addi $t1 $0 13
lw $t0 0($fp)
sub $t2 $t0 $t1
sw $t2 0($sp)
addi $sp $sp -4
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 0($fp)
fangkd_ifend23:
addi $t1 $0 12
lw $t0 0($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t4 $t2 $t3
andi $t4 $t4 1
nor $t0 $t2 $t4
andi $t0 $t0 1
bne $t0 $0 fkd_dobegin22
lw $t0 0($fp)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 20
sw $t0 0($fp)
jal getresult
lw $t0 0($t9)
sw $t0 0($gp)
addi $gp $gp 4
addi $t0 $fp 0
addi $fp $fp 20
sw $t0 0($fp)
jal count
lw $t0 4($sp)
addi $sp $sp 4
sw $t0 4($fp)
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 114
syscall
addi $v0 $0 11
addi $a0 $0 101
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 117
syscall
addi $v0 $0 11
addi $a0 $0 108
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $t1 $0 1
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase28
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 49
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase28:
addi $t1 $0 2
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase29
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 50
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase29:
addi $t1 $0 3
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase30
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 51
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase30:
addi $t1 $0 4
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase31
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 52
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase31:
addi $t1 $0 5
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase32
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 53
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase32:
addi $t1 $0 6
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase33
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 54
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase33:
addi $t1 $0 7
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase34
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 55
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase34:
addi $t1 $0 8
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase35
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 56
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase35:
addi $t1 $0 9
lw $t0 4($fp)
slt $t2 $t0 $t1
slt $t3 $t1 $t0
nor $t0 $t2 $t3
andi $t0 $t0 1
beq $t0 $0 fkd_nextcase36
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 57
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 11
addi $a0 $0 100
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 103
syscall
addi $v0 $0 11
addi $a0 $0 105
syscall
addi $v0 $0 11
addi $a0 $0 116
syscall
addi $v0 $0 11
addi $a0 $0 115
syscall
addi $v0 $0 11
addi $a0 $0 58
syscall
addi $v0 $0 11
addi $a0 $0 32
syscall
addi $v0 $0 1
lw $a0 0($t9)
syscall
j fkd_switchend27
fkd_nextcase36:
fkd_switchend27:
addi $t0 $fp 0
addi $fp $fp 20
sw $t0 0($fp)
jal test_empty
j fkd_program_end
fkd_program_end:
