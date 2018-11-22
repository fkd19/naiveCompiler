#include "tab_entry.h"
#include <string.h>

tab_entry::tab_entry(void)
{
    memset(name, 0, sizeof(name));
    memset(parent, 0, sizeof(parent));
    value = 0;
    memset(reg, 0, sizeof(reg));
}


tab_entry::~tab_entry(void)
{
}
