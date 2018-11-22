#pragma once
#include "define.h"
class str_tab_entry
{
public:
    str_tab_entry(void);
    ~str_tab_entry(void);

    char name[ALNG];
    int length;
    int address;
};

