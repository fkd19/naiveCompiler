#pragma once
#include "define.h"

using namespace std;

class func_tab_entry
{
public:
    func_tab_entry(void);
    ~func_tab_entry(void);
    int parameter_number;//形参个数
    int level;
    symbol return_type;
    //可能还要记录局部变量所占空间大小
};

