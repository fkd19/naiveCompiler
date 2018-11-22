#include "DAG_point.h"
#include <string.h>

DAG_point::DAG_point(void)
{
    memset(op, 0, sizeof(op));
    memset(name, 0, sizeof(name));
    isLeaf = false;
    left_child_num = -1;
    right_child_num = -1;
}


DAG_point::~DAG_point(void)
{
}
