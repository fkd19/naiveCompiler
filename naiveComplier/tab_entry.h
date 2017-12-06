#pragma once
#include "define.h"

using namespace std;

class tab_entry
{
public:
    tab_entry(void);
    ~tab_entry(void);
    char name[ALNG];
    char parent[ALNG];//标志符所属的函数，全局的就写global
    objecttyp obj;//种类
    types typ;//类型
    int value;//如果是函数类型，则保存函数需要的内存空间
    int ref;//如果是函数类型，则保存函数参数个数
    int address;//变量分配单元的首地址,也表示需要占用的空间大小
};

