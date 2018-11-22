#include "basicBlockPoint.h"


basicBlockPoint::basicBlockPoint(void)
{
    clear();
}


basicBlockPoint::~basicBlockPoint(void)
{
}

void basicBlockPoint::clear()
{
    start_line = -1;
    end_line = -1;
    _next.clear();
    _in.reset();
    out.reset();
    def.reset();
    use.reset();
}
