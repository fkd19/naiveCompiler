#include "symbol_record.h"


symbol_record::symbol_record(void)
{
    inum = 0;
    chval = 0;
    sleng = 0;
    memset(id, 0, sizeof(id));
    sy = nosy;
    memset(strval, 0, sizeof(strval));
}


symbol_record::~symbol_record(void)
{
}

void symbol_record::clear()
{
    inum = 0;
    chval = 0;
    sleng = 0;
    memset(id, 0, sizeof(id));
    memset(strval, 0, sizeof(strval));
    sy = nosy;
}

void symbol_record::copy(symbol_record (&dest))
{
    dest.inum = inum;
    dest.chval = chval;
    dest.sleng = sleng;
    memset(dest.id, 0, sizeof(dest.id));
    strcpy_s(dest.id, id);
    dest.sy = sy;
}