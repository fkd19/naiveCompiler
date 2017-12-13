#pragma once
#define NKW 13//keyword数量
#define ALNG    26//identfier的有效字符数量
#define LLNG    320//输入行的长度
#define LMAX    7//level max 最大层数
#define TABLE_SIZE  300//符号表大小，可容纳的符号数量
#define ARRAY_TABLE_SIZE    100//数组表大小，可容纳多少数组
#define MID_CODE_SIZE   2000//中间代码最大规模
#define MIPS_CODE_SIZE  4000//mips代码最大规模


#define str_char "char"
#define str_int "int"
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

#define reg_$0 "$0"
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
#define reg_ra "$ra"
#define reg_sp "$sp"//运算栈
#define reg_fp "$fp"//运行栈
#define reg_gp "$gp"//参数栈
#define reg_t9 "$t9"//全局变量区首地址
#define reg_lo "lo"

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

//dag图的节点中只保留它的两个子节点，每次搜索从顶端节点列表（可能有好几个顶端节点）开始搜索
struct DAG_point{
    char value[ALNG];
    struct DAG_point* left_num;
    struct DAG_point* right_num;
    struct DAG_point* next;//用于顶端节点列表，寻找下一个节点
};
