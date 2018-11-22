#pragma once
#include "define.h"
#include <bitset>
#include <set>

using namespace std;

class func_tab_entry
{
public:
    func_tab_entry(void);
    ~func_tab_entry(void);
    int paraNum;
    int space;
    bitset<GLOABL_REG_NUMBER> alloc_reg;

    void refresh(int address);
};

