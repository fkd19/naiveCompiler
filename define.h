#pragma once
#define NKW 13//keyword数量
#define ALNG    28//identfier的有效字符数量
#define LLNG    320//输入行的长度
#define TABLE_SIZE  400//符号表大小，可容纳的符号数量
#define ARRAY_TABLE_SIZE    50//数组表大小，可容纳多少数组
#define FUNC_TABLE_SIZE     30//函数表大小，可容纳多少函数
#define MID_CODE_SIZE   2000//中间代码最大规模
#define MIPS_CODE_SIZE  4000//mips代码最大规模
#define MAX_DAG_POINT   100//DAG图节点最大规模
#define REG_NAME_SIZE   4//寄存器名长度
#define MAX_VAR_IN_FUNC 100//函数中变量最大数目
#define GLOABL_REG_NUMBER   15//全局寄存器数目
#define RESERVE_SPACE   (3 + GLOABL_REG_NUMBER) * 4//函数预留空间
#define STRING_TABLE_SIZE   300//数组表大小

#define str_char "char"
#define str_int "int"
#define str_string "string"
#define str_prt "prt"
#define str_scf "scf"
#define str_func_def "func_def"
#define str_para "para"
#define str_push "push"
#define str_call "call"
#define str_BNZ "BNZ"
#define str_BZ "BZ"
#define str_ret "ret"
#define str_GOTO "GOTO"
//下面两个由中间代码和mips汇编共用
#define str_label "label"
#define str_nop "nop"

#define str_add     "add"
#define str_addi    "addi"
#define str_and     "and"
#define str_andi    "andi"
#define str_beq     "beq"
#define str_bne     "bne"
#define str_div     "div"
#define str_j       "j"
#define str_jal     "jal"
#define str_jr      "jr"
#define str_la      "la"
#define str_lui     "lui"
#define str_lw      "lw"
#define str_mflo    "mflo"
#define str_mult    "mult"
#define str_or      "or"
#define str_ori     "ori"
#define str_nor     "nor"
#define str_sll     "sll"
#define str_slt     "slt"
#define str_sltu    "sltu"
#define str_slti    "slti"
#define str_sltiu   "sltiu"
#define str_sub     "sub"
#define str_subu    "subu"
#define str_sw      "sw"
#define str_syscall "syscall"

#define reg_$0 "$0"
#define reg_$1 "$1"
#define reg_v0 "$v0"
#define reg_v1 "$v1"
#define reg_a0 "$a0"
#define reg_a1 "$a1"
#define reg_a2 "$a2"
#define reg_a3 "$a3"
#define reg_t0 "$t0"
#define reg_t1 "$t1"
#define reg_t2 "$t2"
#define reg_t3 "$t3"
#define reg_t4 "$t4"
#define reg_t5 "$t5"
#define reg_t6 "$t6"
#define reg_t7 "$t7"
#define reg_t8 "$t8"
#define reg_s0 "$s0"
#define reg_s1 "$s1"
#define reg_s2 "$s2"
#define reg_s3 "$s3"
#define reg_s4 "$s4"
#define reg_s5 "$s5"
#define reg_s6 "$s6"
#define reg_s7 "$s7"
#define reg_ra "$ra"
#define reg_sp "$sp"//运算栈
#define reg_fp "$fp"//运行栈
#define reg_gp "$gp"//参数栈
#define reg_t9 "$t9"//全局变量区首地址
#define reg_lo "lo"
#define reg_k0 "$k0"
#define reg_k1 "$k1"
#define sa_base 6
#define rd_base 11
#define rt_base 16
#define rs_base 21
#define base_base 21
#define op_base 26

#define e1 "中间代码表容量不足"
#define e2 "标识符不存在"
#define e3 "被赋值对象的值不可修改"
#define e4 "类型不符"
#define e5 "检测到数组索引为字符型，数组索引应为整型，已做自动转换"
#define e6 "数组索引越界"
#define e7 "符号表容量不足"
#define e8 "语法成分缺失"
#define e9 "常/变量名称与所在函数相同"
#define e10 "查找不到标识符"
#define e11 "无符号整数以0开头"
#define e12 "整数越界"
#define e13 "常量值重复"
#define e14 "参数个数不匹配"

enum symbol
{
constsy,intsy,charsy,voidsy,mainsy,ifsy,dosy,whilesy,switchsy,casesy,printfsy,scanfsy,returnsy, 
//+			-		*		/	==	  !=   >	>=   <   <=	   ,        ;        =     非法符号 
plussy, minussy, multsy, divsy, beq, bne, bgt, bge, blt, ble, comma, semicomma, becomesy, nosy,
//int     char     string     (         )        [       ]		  {        }    标识符  冒号
intcon, charcon, stringcon, lparent, rparent, lsquare, rsquare, lbrack, rbrack, ident, colon
};

enum objecttyp{con, var, para, func, arr};
enum types{notyp, ints, bools, chars, arrays};
enum operate_table_mode{declare_mode, search_mode};
// declare_mode 查表模式：声明，要求同一层不冲突即可
// SEARCH_MODE  查表模式：搜索，现在本层找，找不到则去上一层找


