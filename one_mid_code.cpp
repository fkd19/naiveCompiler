#include "one_mid_code.h"
#include <string.h>

one_mid_code::one_mid_code(void)
{
    memset(op, 0, sizeof(op));
    memset(rs, 0, sizeof(rs));
    memset(rt, 0, sizeof(rt));
    memset(rd, 0, sizeof(rd));
}


one_mid_code::~one_mid_code(void)
{
}
