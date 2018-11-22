#pragma once

#include "define.h"
#include <list>
#include <bitset>
using namespace std;

class basicBlockPoint
{
public:
    basicBlockPoint(void);
    ~basicBlockPoint(void);
    void clear();

    int start_line;
    int end_line;
    list<int> _next;
    bitset<MAX_VAR_IN_FUNC> _in;
    bitset<MAX_VAR_IN_FUNC> out;
    bitset<MAX_VAR_IN_FUNC> def;
    bitset<MAX_VAR_IN_FUNC> use;
};

