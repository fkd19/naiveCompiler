#include "conflictPoint.h"
#include <string.h>

conflictPoint::conflictPoint(void)
{
    initializer();
}


conflictPoint::~conflictPoint(void)
{
}

void conflictPoint::initializer()
{
    memset(name, 0, sizeof(name));
    number = -1;
    reg_number = -1;
    enable = true;
    weight = -1;
    neighbours.clear();
}
