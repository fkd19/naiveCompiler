#pragma once
#include "define.h"
#include "tab_entry.h"

using namespace std;

class array_tab_entry
{
public:
    array_tab_entry(void);
    ~array_tab_entry(void);
    types elementType;
    int size;
    int elementSize;//每个元素占空间的大小

};

