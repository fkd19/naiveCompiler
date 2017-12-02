#pragma once
#include "define.h"
#include <string.h>

using namespace std;

class symbol_record
{
public:
    symbol_record(void);
    ~symbol_record(void);
    long long inum;//insymbol函数得到的整数值
    char chval;//insymbol函数读出的字符型常量的值
    int sleng;//字符串长度
    char id[ALNG];
    symbol sy;//insymbol函数得到的最后一个符号
    char strval[600];

    void clear();
    void copy(symbol_record (&dest));//将本symbol_record的内容复制到dest中
};

