#pragma once
#include "define.h"
#include <set>

using namespace std;

class conflictPoint
{
public:
    conflictPoint(void);
    ~conflictPoint(void);
    void initializer();
    
    char name[ALNG];
    int number;//变量在函数中的序号
    int reg_number;//寄存器序号
    //寄存器序号：0-14对应$s0-$s7,$a1-$a3,$t5-t8
    bool enable;
    int weight;//权重，用于区别点删除的顺序
    set<int> neighbours;
};

