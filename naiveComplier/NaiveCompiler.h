#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <set>
#include <tchar.h>
#include <string.h>
#include <stdint.h>
#include "define.h"
#include "array_tab_entry.h"
#include "tab_entry.h"
#include "symbol_record.h"
#include "one_mid_code.h"
#include "mips_code.h"

using namespace std;

class NaiveCompiler
{
public:
    NaiveCompiler();
    ~NaiveCompiler();
    //超前查看的符号缓冲区，目前已知为最多须向前查看3个符号。结合insymbol函数，扩展成任意数字很容易
    //在不需要超前查看的时候，只使用symbols[0],超前查看完以后，务必手动调用clear函数清除无用数据。
    symbol_record symbols[3];
    int end;//队列尾指针，维护符号缓冲区队列使用,缓冲区内容为以[0, end]为索引的symbols数组对象。end不为0时，当前symbol从指定处取，end为0时，当前symbol从0处取
    char ch;//从源文件中读出的最后一个字符
    char key[NKW][ALNG];//保留字数组
    int cc; //charactor counter
    int ll; //length of current line
    char line[LLNG];
    fstream fin;
    fstream fout;
    fstream midcodefile;
    fstream programma_info;
    fstream mipsfile;
    symbol ksy[NKW];
    tab_entry tab[TABLE_SIZE];
    int t;//tab的索引
    array_tab_entry atab[ARRAY_TABLE_SIZE];
    int a;//atab的索引
    int display[LMAX];
    bool iflag, oflag;//scanf printf 用到的标记
    int dx;//data alloction index 永远指向可以申请的下一个数据地址,供全局变量使用时，表示绝对地址，供局部变量使用时，表示相对于函数开始地址的偏移
    int ln;//行号，输出错误发生的行。

    char string_global[ALNG];
    char string_main[ALNG];
    int mid_counter;
    one_mid_code midcode[MID_CODE_SIZE];
    int f;

    mips_code mips[MIPS_CODE_SIZE];
    int mips_counter;

    list<pair<int, string>> errors;

    set<symbol> f_assign;
    set<symbol> f_call_return_func;
    set<symbol> f_call_void_func;
    set<symbol> f_case;
    set<symbol> f_caselist;
    set<symbol> f_condition;
    set<symbol> f_const;
    set<symbol> f_const_declare;
    set<symbol> f_const_define;
    set<symbol> f_do_while;
    set<symbol> f_expression;
    set<symbol> f_factor;
    set<symbol> f_if;
    set<symbol> f_integer;
    set<symbol> f_item;
    set<symbol> f_main;
    set<symbol> f_printf;
    set<symbol> f_program;
    set<symbol> f_return;
    set<symbol> f_return_func_declare;
    set<symbol> f_scanf;
    set<symbol> f_statement;
    set<symbol> f_switch;
    set<symbol> f_var_declare;
    set<symbol> f_var_define;
    set<symbol> f_void_func_declare;
    
    void assign_statement(char (&parent)[ALNG]);//处理“赋值语句”
    void call_return_func(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ));//处理“有返回值函数调用语句”
    void call_void_func(char (&parent)[ALNG]);//处理“无返回值函数调用语句”
    void caselist(char (&parent)[ALNG], types typ, char (&rs)[ALNG]);//处理“情况表”
    void compound_statement(char (&parent)[ALNG], bool &has_return);//处理“复合语句”
    void condition(char (&parent)[ALNG], char (&label)[ALNG], bool jump);//处理“条件”,jump表示条件成立跳转还是条件不成立跳转
    int constant(types typ);//处理“常量”，仅用于case语句中
    void const_declare(char (&parent)[ALNG]);//处理“常量声明”
    void const_define(char (&parent)[ALNG]);//处理“常量定义”
    void do_while_statement(char (&parent)[ALNG]);//处理“循环语句”
    void expression(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ));//处理“表达式”
    void factor(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ));//处理“因子”
    void if_statement(char (&parent)[ALNG]);//处理“条件语句”
    void insymbol(symbol_record &aim);//将读到的内容保存到aim中
    int integer();//处理“整数”
    void item(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ));//处理“项”
    void nextch();//从源文件获取下一个字符
    void one_case(char (&parent)[ALNG], types typ, char (&end)[ALNG], char (&rs)[ALNG], set<int> &exist_const);//处理“情况子语句”，即1个case语句
    void parameter_list(char (&parent)[ALNG]);//处理“参数表”
    void printf_statement(char (&parent)[ALNG]);//处理“写语句”
    void program();//处理“程序”
    void return_func_declare();//处理“有返回值函数定义”,需要考虑预先读入3个字符和预先读入1个字符，共两种情况。
    void return_statement(char (&parent)[ALNG]);//处理“返回语句”
    void scanf_statement(char (&parent)[ALNG]);//处理“读语句”
    void statement(char (&parent)[ALNG], bool &has_return);//处理“语句”
    void statement_column(char (&parent)[ALNG], bool &has_return);//处理“语句列”
    void switch_statement(char (&parent)[ALNG]);//处理“情况语句”
    void value_parameter_list(char (&parent)[ALNG], char (&called_func)[ALNG]);//处理“值参数表”
    void var_declare(char (&parent)[ALNG]);//处理“变量声明”
    void var_define(char (&parent)[ALNG]);//处理“变量定义”
    void void_func_declare();//处理“无返回值函数定义”
    void void_main();//处理“主函数”

    void error(string content);//ln：错误所在行号      content：错误内容
    void errormsg();//集中打印错误信息
    void fatal(string content);//严重错误，进入后直接退出
    //根据标识符名称查找，返回标识符索引
    int getIndexByNameAndParent(char (&parent)[ALNG], char (&name)[ALNG], operate_table_mode mode);
    void skip(set<symbol> begin_symbol_set);
    void append_midcode(char* op, char* rd = nullptr, char* rs = nullptr, char* rt = nullptr);//添加中间代码
    void allocHelpVar(char* ans);//分配一个空闲的变量名，用于四元式的生成

    void midcode2mips();

    void add(char* rd, char* rs, char* rt);
    void addi(char* rd, char* rs, int imm);
    void div(char* rs, char* rt);
    void mult(char* rs, char* rt);
    void sub(char* rd, char* rs, char* rt);
    void subi(char* rd, char* rs, int imm);
    void syscall();
    
};
