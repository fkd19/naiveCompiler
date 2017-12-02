#pragma once
#define NKW 13//keyword数量
#define ALNG    51//identfier的有效字符数量
#define LLNG    501//输入行的长度
#define LMAX    7//level max 最大层数
#define TABLE_SIZE  300//符号表大小，可容纳的符号数量
#define ARRAY_TABLE_SIZE    100//数组表大小，可容纳多少数组
#define MID_CODE_SIZE   3000//中间代码最大规模
#define MIPS_CODE_SIZE  3000//mips代码最大规模

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

