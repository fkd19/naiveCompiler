#pragma once
#include "define.h"

class mips_code
{
public:
    mips_code(void);
    ~mips_code(void);

    char* op;
    char* rs;
    char* rt;
    char* rd;
    char* imm;
    char* target;

};

