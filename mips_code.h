#pragma once
#include "define.h"

class mips_code
{
public:
    mips_code(void);
    ~mips_code(void);

    char op[ALNG];
    char rs[ALNG];
    char rt[ALNG];
    char rd[ALNG];
    char imm[ALNG];
    char target[ALNG];
    int instruction_addr;
};

