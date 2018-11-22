#pragma once
#include "define.h"
#include <list>
using namespace std;
class DAG_point
{
public:
    DAG_point(void);
    ~DAG_point(void);

    char op[ALNG];//²Ù×÷·û
    char name[ALNG];
    int left_child_num;
    int right_child_num;
    bool isLeaf;
    list<int> parents;
};

