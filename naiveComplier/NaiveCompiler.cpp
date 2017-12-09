#include "NaiveCompiler.h"

NaiveCompiler::NaiveCompiler()
{
    ch = ' ';
    cc = 0;
    ll = 0;
    memset(line, 0, sizeof(line));
    end = 0;
    t = -1;
    a = -1;
    display[0] = 1;
    dx = 0;
    ln = 0;
    mid_counter = 0;
    mips_counter = -1;

    midcodefile.open("midcode.txt", ios_base::out);
    programma_info.open("programma_analysis.txt", ios_base::out);
    mipsfile.open("mips.asm", ios_base::out);

    f = -1;

    strcpy_s(string_global, "global");
    strcpy_s(string_main, "main");
    strcpy_s(reg_sp, "$sp");
    strcpy_s(reg_fp, "$fp");
    strcpy_s(reg_gp, "$gp");
    strcpy_s(reg_t9, "$t9");

    strcpy_s(key[0], "case");
    strcpy_s(key[1], "char");
    strcpy_s(key[2], "const");
    strcpy_s(key[3], "do");
    strcpy_s(key[4], "if");
    strcpy_s(key[5], "int");
    strcpy_s(key[6], "main");
    strcpy_s(key[7], "printf");
    strcpy_s(key[8], "return");
    strcpy_s(key[9], "scanf");
    strcpy_s(key[10],"switch");
    strcpy_s(key[11],"void");
    strcpy_s(key[12],"while");

    ksy[0]=casesy;
    ksy[1]=charsy;
    ksy[2]=constsy;
    ksy[3]=dosy;
    ksy[4]=ifsy;
    ksy[5]=intsy;
    ksy[6]=mainsy;
    ksy[7]=printfsy;
    ksy[8]=returnsy;
    ksy[9]=scanfsy;
    ksy[10]=switchsy;
    ksy[11]=voidsy;
    ksy[12]=whilesy;

    f_assign.insert(ident);

    f_call_return_func.insert(ident);

    f_call_void_func.insert(ident);

    f_case.insert(casesy);

    f_caselist.insert(casesy);

    f_condition.insert(plussy);
    f_condition.insert(minussy);
    f_condition.insert(ident);
    f_condition.insert(intcon);
    f_condition.insert(charcon);
    f_condition.insert(lparent);

    f_const.insert(plussy);
    f_const.insert(minussy);
    f_const.insert(intcon);
    f_const.insert(charcon);

    f_const_declare.insert(constsy);

    f_const_define.insert(intsy);
    f_const_define.insert(charsy);

    f_do_while.insert(dosy);

    f_expression.insert(plussy);
    f_expression.insert(minussy);
    f_expression.insert(ident);
    f_expression.insert(intcon);
    f_expression.insert(charcon);
    f_expression.insert(lparent);

    f_factor.insert(ident);
    f_factor.insert(plussy);
    f_factor.insert(minussy);
    f_factor.insert(intcon);
    f_factor.insert(charcon);
    f_factor.insert(lparent);

    f_if.insert(ifsy);

    f_integer.insert(plussy);
    f_integer.insert(minussy);
    f_integer.insert(intcon);

    f_item.insert(ident);
    f_item.insert(plussy);
    f_item.insert(minussy);
    f_item.insert(intcon);
    f_item.insert(charcon);
    f_item.insert(lparent);

    f_main.insert(voidsy);

    f_printf.insert(printfsy);

    f_program.insert(constsy);
    f_program.insert(intsy);
    f_program.insert(charsy);
    f_program.insert(voidsy);

    f_return.insert(returnsy);

    f_return_func_declare.insert(intsy);
    f_return_func_declare.insert(charsy);

    f_scanf.insert(scanfsy);

    f_statement.insert(ifsy);
    f_statement.insert(dosy);
    f_statement.insert(switchsy);
    f_statement.insert(lbrack);
    f_statement.insert(ident);
    f_statement.insert(scanfsy);
    f_statement.insert(printfsy);
    f_statement.insert(semicomma);
    f_statement.insert(returnsy);

    f_switch.insert(switchsy);

    f_var_declare.insert(intsy);
    f_var_declare.insert(charsy);

    f_var_define.insert(intsy);
    f_var_define.insert(charsy);

    f_void_func_declare.insert(voidsy);
}
NaiveCompiler::~NaiveCompiler()
{
}
void NaiveCompiler::allocHelpVar(char (&ans)[ALNG])
{
    f += 1;
    strcpy_s(ans, "fangkedongt");
    _itoa_s(f, &ans[11], ALNG-12, 10);
}
void NaiveCompiler::append_midcode(char* op, char* rd, char* rs, char* rt)
{
    if (mid_counter < MID_CODE_SIZE)
    {
        strcpy_s(midcode[mid_counter].op, op);
        if (rd != nullptr)
            strcpy_s(midcode[mid_counter].rd, rd);
        if (rs != nullptr)
            strcpy_s(midcode[mid_counter].rs, rs);
        if (rt != nullptr)
            strcpy_s(midcode[mid_counter].rt, rt);
        mid_counter += 1;
    }
    else
        fatal("中间代码表容量不足");

    if (strcmp(op, "func_def") == 0)
        midcodefile << rs << " " << rt << "()" << endl;
    else if (strcmp(op, "para") == 0)
        midcodefile << op << " " << rs << " " << rt << endl;
    else if (strcmp(op, "push") == 0)
        midcodefile << op << " " << rs << endl;
    else if (strcmp(op, "call") == 0)
        midcodefile << op << " " << rs << endl;
    else if (strcmp(op, "=") == 0)
        midcodefile << rd << " " << op << " " << rs << endl;
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0
         ||  strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
        midcodefile << rd << "=" << rs << " " << op << " " << rt << endl;
    else if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0
         ||  strcmp(op, ">") == 0 || strcmp(op, ">=") == 0
         ||  strcmp(op, "<") == 0 || strcmp(op, "<=") == 0)
        midcodefile << rs << " " << op << " " << rt << endl;
    else if (strcmp(op, "BNZ") == 0)
        midcodefile << "BNZ " << rd << endl;
    else if (strcmp(op, "BZ") == 0)
        midcodefile << "BZ " << rd << endl;
    else if (strcmp(op, "ret") == 0)
    {
        if (rs == nullptr)
            midcodefile << op << endl;
        else
            midcodefile << op << " " << rs << endl;
    }
        
    else if (strcmp(op, "GOTO") == 0)
        midcodefile << "GOTO " << rs << endl;
    else if (strcmp(op, "=[]") == 0)
        midcodefile << rd << "=" << rs << "[" << rt << "]" << endl;
    else if (strcmp(op, "[]=") == 0)
        midcodefile << rs << "[" << rt << "]=" << rd << endl;
    else if (strcmp(op, "prt") == 0)
        midcodefile << op << " " << rs << endl;
    else if (strcmp(op, "scf") == 0)
        midcodefile << op << " " << rd << endl;
    else
        midcodefile << op << ":" << endl;
}
void NaiveCompiler::assign_statement(char (&parent)[ALNG])
{
    
    types typ;
    char rs[ALNG];
    char rt[ALNG];
    char rd[ALNG];
    int index;
    //查找标志符
    index = getIndexByNameAndParent(parent, symbols[0].id, search_mode);
    if (index == -1)
    {
        //标识符不存在
        string msg = symbols[0].id;
        msg.append("不存在");
        error(msg);
        /*set<symbol> begin_symbol_set;
        begin_symbol_set.insert(semicomma);
        skip(begin_symbol_set);
        return ;*/
    }

    if (tab[index].obj != var && tab[index].obj != arr && tab[index].obj != para)
    {
        //标识符不是变量
        string msg = symbols[0].id;
        msg.append("的值不可修改");
        error(msg);
        /*set<symbol> begin_symbol_set;
        begin_symbol_set.insert(semicomma);
        skip(begin_symbol_set);
        return ;*/
    }

    strcpy_s(rs, symbols[0].id);

    if (end == 1)
    {
        symbols[1].copy(symbols[0]);
        symbols[1].clear();
        end = 0;
    }
    else
        insymbol(symbols[0]);

    if (symbols[0].sy == lsquare)
    {
        //说明是数组元素赋值
        //检查标识符的种类为数组
        if (tab[index].obj != arr)
        {
            //报错，类型不符
            string msg = tab[index].name;
            msg.append("不是数组，类型不符");
            error(msg);
            /*set<symbol> begin_symbol_set;
            begin_symbol_set.insert(semicomma);
            skip(begin_symbol_set);
            return ;*/
        }

        typ = atab[tab[index].ref].elementType;
        insymbol(symbols[0]);
        if (f_expression.count(symbols[0].sy))
        {
            types indexType;
            expression(parent, rt, indexType);
            if (indexType == chars)
            {
                int value = (int)rt[0];
                memset(rt, 0, sizeof(rt));
                _itoa_s(value, rt, 10);
                error("数组索引应为整型");
            }
            else if (atoi(rt) >= atab[tab[index].ref].size)
                error("索引超过数组上界");
            else if (atoi(rt) < 0)
                error("索引超过数组下界");
        }
        else
            error("‘[’ 后面不是表达式");

        if (symbols[0].sy == rsquare)
            insymbol(symbols[0]);
        else
            error("缺少 ]");
    }
    else
        typ = tab[index].typ;

    if (symbols[0].sy == becomesy)
        insymbol(symbols[0]);
    else
        error("缺少 =");

    if (f_expression.count(symbols[0].sy))
    {
        types valueType;
        expression(parent, rd, valueType);
        if (typ == ints && valueType == chars)
        {
            int value = (int)rt[0];
            memset(rd, 0, sizeof(rd));
            _itoa_s(value, rd, 10);
            error("赋值类型与目标类型不一致");
        }
        else if (typ == chars && valueType == ints)
        {
            error("将整型赋给字符型，有越界的风险");
            /*int value = atoi(rd);
            if (value == '+' || value == '-' || value == '*' || value == '/'
             || isdigit(value || islower(value) || isupper(value) || value == '_')
            {
                memset(rd, 0, sizeof(rd));
                rd[0] = value;
                rd[1] = 9;
                rd[2] = '\0';
            }
            else
                error("值越界，无法将");*/
        }

        if (tab[index].obj == arr)
        {
            append_midcode("[]=", rd, rs, rt);//反向赋值，把普通标识符的值赋给数组元素
        }
        else
        {
            //和之前有点不一样，rs是第一个标志符，即被赋值的一方，rd是最后一个表达式，是赋值的一方
            append_midcode("=", rs, rd);
        }
    }
    else
    {
        //报错
        error("等号右侧不是表达式");
        /*set<symbol> begin_symbol_set;
        begin_symbol_set.insert(semicomma);
        skip(begin_symbol_set);
        return ;*/
    }
    programma_info << "这是一个“赋值语句”" << endl;

}
//有可能是因子，也有可能是语句，很难把握跳到哪比较好，暂时先不跳
void NaiveCompiler::call_return_func(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ))//注意给返回值留位置
{
    
    int index;//用于保存标记符在符号表中的索引
    //处理symbols[0]的标记符名称
    index = getIndexByNameAndParent(string_global, symbols[0].id, search_mode);
    if (index == -1)
    {
        //标识符不存在
        string msg = symbols[0].id;
        msg.append("不存在");
        error(msg);
    }

    //验证标识符的种类是不是函数
    if (tab[index].obj != func)
    {
        //报错，类型不符
        string msg = tab[index].name;
        msg.append("不是函数，类型不符");
        error(msg);
    }

    if (tab[index].typ == notyp)
    {
        //这里调用的是有返回值函数，无返回值要报错
        string msg = tab[index].name;
        msg.append("无返回值");
        error(msg);
    }

    if (end == 1)
    {
        symbols[0].clear();
        symbols[1].clear();
        end = 0;
        insymbol(symbols[0]);
    }
    else
    {
        insymbol(symbols[0]);
        if (symbols[0].sy == lparent)
            insymbol(symbols[0]);
        else
            error("缺少 (");
    }

    append_midcode("aar");

    value_parameter_list(parent, tab[index].name);//可能为空，故不必验证开始符号集

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    append_midcode("call", nullptr, tab[index].name);
    strcpy_s(rd, "ret");
    programma_info << "这是一个“有返回值函数调用语句”" << endl;
}
void NaiveCompiler::call_void_func(char (&parent)[ALNG])
{
    
    int index;//用于保存标记符在符号表中的索引
    //处理symbols[0]的标记符名称
    index = getIndexByNameAndParent(string_global, symbols[0].id, search_mode);
    //statement函数已经验证过存在了，而且种类是func

    //无返回值函数只能由statement函数调用，须超前查看一个字符判断以排除赋值语句，故end必为1
    symbols[0].clear();
    symbols[1].clear();
    end = 0;
    insymbol(symbols[0]);

    append_midcode("aar");

    value_parameter_list(parent, tab[index].name);//可能为空，故不必验证开始符号集

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    append_midcode("call", nullptr, tab[index].name);
    programma_info << "这是一个“无返回值函数调用语句”" << endl;
}
void NaiveCompiler::caselist(char (&parent)[ALNG], types typ, char (&rs)[ALNG])
{
    set <int> exist_const;
    char end[ALNG];
    strcpy_s(end, "fkd_switchend");
    f += 1;
    _itoa_s(f, &end[13], ALNG-14, 10);

    one_case(parent, typ, end, rs, exist_const);

    while (f_case.count(symbols[0].sy))
        one_case(parent, typ, end, rs, exist_const);

    append_midcode(end);
    programma_info << "这是一个“情况表”" << endl;
}
void NaiveCompiler::compound_statement(char (&parent)[ALNG], bool &has_return)
{
    
    //处理“常量声明”
    if (f_const_declare.count(symbols[0].sy))//count返回值大于0说明sy属于集合
        const_declare(parent);

    //处理“变量声明”
    if (f_var_declare.count(symbols[0].sy))
        var_declare(parent);

    int index = getIndexByNameAndParent(string_global, parent, search_mode);
    if (index != -1)
    {
        tab[index].value = dx;
    }

    statement_column(parent, has_return);//语句列可能为空，不需要判断开始符号集
    programma_info << "这是一个“复合语句”" << endl;
}
void NaiveCompiler::condition(char (&parent)[ALNG], char (&label)[ALNG], bool jump)
{
    char rs[ALNG];
    char rt[ALNG];
    char op[ALNG];
    //条件和表达式的开始符号集一样，不必重新判断
    types typ;
    expression(parent, rs, typ);

    //更新跳转标记

    if (symbols[0].sy == beq || symbols[0].sy == bne || symbols[0].sy == bgt
        || symbols[0].sy == bge || symbols[0].sy == blt || symbols[0].sy == ble)
    {
        switch(symbols[0].sy)
        {
        case beq:   strcpy_s(op, "==");    break;
        case bne:   strcpy_s(op, "!=");    break;
        case bgt:   strcpy_s(op, ">");    break;
        case bge:   strcpy_s(op, ">=");    break;
        case ble:   strcpy_s(op, "<=");    break;
        case blt:   strcpy_s(op, "<");    break;
        }
        
        insymbol(symbols[0]);

        if (f_expression.count(symbols[0].sy))
        {
            expression(parent, rt, typ);
            append_midcode(op, nullptr, rs, rt);
            if (jump)
                append_midcode("BNZ", label);
            else
                append_midcode("BZ", label);
        }
        else
            error("关系符号右侧缺少表达式");
    }
    //可以只有一个表达式，没有关系运算符
    else
    {
        append_midcode("!=", nullptr, rs, "0");
        if (jump)
            append_midcode("BNZ", label);
        else
            append_midcode("BZ", label);
    }
    programma_info << "这是一个“条件”" << endl;
}
int NaiveCompiler::constant(types typ)
{
    
    int value = 0;
    if (symbols[0].sy == charcon)
    {
        //是字符
        if (typ == ints)
            error("情况常量与情况变量类型不一致");

        value = (int)symbols[0].chval;
        insymbol(symbols[0]);
        programma_info << "这是一个“常量”" << endl;
        return value;
    }
    else
    {
        //否则是整数
        if (typ == chars)
            error("情况常量与情况变量类型不一致");
        value = integer();
        programma_info << "这是一个“常量”" << endl;
        return value;
    }
    
}
void NaiveCompiler::const_declare(char (&parent)[ALNG])
{
    
    while (symbols[0].sy == constsy)
    {
        insymbol(symbols[0]);

        if (f_var_define.count(symbols[0].sy))
        {
            const_define(parent);
        }
        else
        {
            //报错，缺少常量定义
            error("常量类型错误");
            /*set<symbol> begin_symbol_set;
            begin_symbol_set.insert(semicomma);
            skip(begin_symbol_set);*/
        }

        if (symbols[0].sy == semicomma)
            insymbol(symbols[0]);
        else
            error("缺少 ;");
    }
    programma_info << "这是一个“常量说明”" << endl;
}
void NaiveCompiler::const_define(char (&parent)[ALNG])
{
    
    char const_name[ALNG] = "";
    int value = 0;
    if (symbols[0].sy == intsy)
    {
        insymbol(symbols[0]);
intsy_label_1:
        if (symbols[0].sy == ident)
        {
            //登记常量名称
            strcpy_s(const_name, symbols[0].id);
            insymbol(symbols[0]);
        }
        else
            error("常量名称不合法");

        if (symbols[0].sy == becomesy)
            insymbol(symbols[0]);
        else
            error("缺少 =");

        if (f_integer.count(symbols[0].sy))
        {
            value = integer();
        }
        else
            error("常量是int型的，值也应该是int型的");

        //若变量名有效，类型不为空,则登记到表中
        if (strcmp(const_name, ""))
        {
            if (getIndexByNameAndParent(parent, const_name, declare_mode) == -1)
            {
                if (t == TABLE_SIZE - 1)
                {
                    //报错，符号表容量不够，fatal，退出程序
                    fatal("符号表容量不足");
                }

                t += 1;
                strcpy_s(tab[t].name, const_name);
                tab[t].obj = con;
                tab[t].typ = ints;
                tab[t].value = value;
                strcpy_s(tab[t].parent, parent);

                midcodefile << "const int " << const_name << " = " << value << endl;
            }
            else
            {
                //重复声明，报错
                string msg = const_name;
                msg.append("重复声明");
                error(msg);
                /*set<symbol> begin_symbol_set;
                begin_symbol_set.insert(semicomma);
                begin_symbol_set.insert(comma);
                skip(begin_symbol_set);*/
            }
        }
        //非法变量名则不登入符号表

        if (symbols[0].sy == comma)
        {
            insymbol(symbols[0]);
            goto intsy_label_1;
        }

    }
    else if (symbols[0].sy == charsy)
    {
        insymbol(symbols[0]);
charsy_label_1:
        if (symbols[0].sy == ident)
        {
            //登记常量名称
            strcpy_s(const_name, symbols[0].id);
            insymbol(symbols[0]);
        }
        else
            error("常量名称不合法");

        if (symbols[0].sy == becomesy)
            insymbol(symbols[0]);
        else
            error("缺少 =");

        if (symbols[0].sy == charcon)
        {
            //登记常量的值
            value = symbols[0].chval;
            insymbol(symbols[0]);
        }
        else
            error("常量是char型的，值也应该是char型的");

        //若变量名有效，类型不为空,则登记到表中
        if (strcmp(const_name, ""))
        {
            if (getIndexByNameAndParent(parent, const_name, declare_mode) == -1)
            {
                if (t == TABLE_SIZE - 1)
                {
                    //报错，符号表容量不够，fatal，退出程序
                    fatal("符号表容量不够");
                }

                t += 1;
                strcpy_s(tab[t].name, const_name);
                tab[t].obj = con;
                tab[t].typ = chars;
                tab[t].value = value;
                strcpy_s(tab[t].parent, parent);

                midcodefile << "const char " << const_name << " = " << value << endl;
            }
            else
            {
                //重复声明，报错
                string msg = const_name;
                msg.append("重复声明");
                error(msg);
                /*set<symbol> begin_symbol_set;
                begin_symbol_set.insert(semicomma);
                begin_symbol_set.insert(comma);
                skip(begin_symbol_set);*/
            }
        }
        //非法变量名则不登入符号表

        if (symbols[0].sy == comma)
        {
            insymbol(symbols[0]);
            goto charsy_label_1;
        }
    }
    programma_info << "这是一个“常量定义”" << endl;
}
void NaiveCompiler::do_while_statement(char (&parent)[ALNG])
{
    
    char label[ALNG];
    insymbol(symbols[0]);
    if (f_statement.count(symbols[0].sy))
    {
        strcpy_s(label, "fkd_dobegin");
        f += 1;
        _itoa_s(f, &label[11], ALNG-12, 10);
        append_midcode(label);
        bool has_return=false;
        statement(parent, has_return);
    }
    else
        error("缺少合法的语句");

    if (symbols[0].sy == whilesy)
        insymbol(symbols[0]);
    else
        error("缺少 while");

    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    if (f_condition.count(symbols[0].sy))
    {
        condition(parent, label, true);
    }
    else
        error("循环语句缺少条件");

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    programma_info << "这是一个“循环语句”" << endl;
}
void NaiveCompiler::error(string content)
{
    pair<int, string> a(ln, content);
    errors.push_back(a);
    fout << "第" << ln << "行：" << content << endl;
}
/*void NaiveCompiler::errormsg()
{
    list<pair<int, string>>::iterator iter;
    for (iter = errors.begin(); iter != errors.end(); iter++)
        
    
}*/
void NaiveCompiler::expression(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ))
{
    
    int numSym = 1;
    char rs[ALNG];
    char rt[ALNG];
    char op[ALNG];

    if (symbols[0].sy == plussy)
    {
        insymbol(symbols[0]);
    }
    else if (symbols[0].sy == minussy)
    {
        //更新整数符号为负
        numSym = -1;
        insymbol(symbols[0]);
    }

    if (f_item.count(symbols[0].sy))
    {
        item(parent, rs, typ);
        if (numSym == -1)
        {
            allocHelpVar(rd);
            append_midcode("-", rd, "0", rs);//取相反数，rs代替rt位
            strcpy_s(rs, rd);
        }
    }
    else
        error("表达式中存在非法符号");

    bool flag = false;
    while (symbols[0].sy == plussy || symbols[0].sy == minussy)
    {
        flag = true;
        //处理加法运算符
        if (symbols[0].sy == plussy)
            strcpy_s(op, "+");
        else
            strcpy_s(op, "-");

        insymbol(symbols[0]);
        if (f_item.count(symbols[0].sy))
        {
            item(parent, rt, typ);
        }
        else
            error("表达式中存在非法符号");

        allocHelpVar(rd);

        append_midcode(op, rd, rs, rt);
        strcpy_s(rs, rd);
        typ = ints;
    }

    if (flag == false)
        strcpy_s(rd, rs);

    programma_info << "这是一个“表达式”" << endl;
}
void NaiveCompiler::factor(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ))
{
    
    int index;
    char rt[ALNG];
    typ = ints;
    if (symbols[0].sy ==ident)
    {
        index = getIndexByNameAndParent(parent, symbols[0].id, search_mode);
        if (index == -1)
        {
            //找不到，报错
            string msg = symbols[0].id;
            msg.append("不存在");
            error(msg);
        }

        insymbol(symbols[1]);
        end = 1;
        if (symbols[1].sy == lsquare)
        {
            //处理数组元素
            //验证之前的标识符的种类是数组
            if (tab[index].obj != arr)
            {
                //报错，类型不符
                string msg = tab[index].name;
                msg.append("不是数组，类型不符");
                error(msg);
            }

            typ = atab[tab[index].ref].elementType;

            symbols[0].clear();
            symbols[1].clear();
            end = 0;
            insymbol(symbols[0]);

            if (f_expression.count(symbols[0].sy))
            {
                types indexType;
                expression(parent, rt, indexType);
                if (indexType == chars)
                {
                    int value = (int)rt[0];
                    memset(rt, 0, sizeof(rt));
                    _itoa_s(value, rt, 10);
                    error("数组索引应为整型");
                }
                else if (atoi(rt) >= atab[tab[index].ref].size)
                    error("索引超过数组上界");
                else if (atoi(rt) < 0)
                    error("索引超过数组下界");
                    
                allocHelpVar(rd);
                append_midcode("=[]", rd, tab[index].name, rt);
            }
            else
                error("[ 后面不是表达式");

            
            if (symbols[0].sy == rsquare)
            {
                insymbol(symbols[0]);
            }
            else
                error("缺少 ]");
        }
        else if (symbols[1].sy == lparent)
        {
            call_return_func(parent, rd, typ);
        }
        else
        {
            //处理标识符
            strcpy_s(rd, symbols[0].id);
            typ = tab[index].typ;
            symbols[1].copy(symbols[0]);
            symbols[1].clear();
            end = 0;
        }
    }
    else if (f_integer.count(symbols[0].sy))
    {
        _itoa_s(integer(), rd, 10);
    }
    else if (symbols[0].sy == charcon)
    {
        //处理字符的值
        typ = chars;
        _itoa_s(symbols[0].chval, rd, 10);
        insymbol(symbols[0]);
    }
    else if (symbols[0].sy == lparent)
    {
        insymbol(symbols[0]);
        if (f_expression.count(symbols[0].sy))
        {
            expression(parent, rd, typ);
        }
        else
            error("( 后面不是表达式");

        if (symbols[0].sy == rparent)
            insymbol(symbols[0]);
        else
            error("缺少 )");
    }
    programma_info << "这是一个“因子”" << endl;
}
void NaiveCompiler::fatal(string content)
{
    fout << content << endl;
    //errormsg();
    exit(0);
}
//查到则返回>=0,查不到返回-1
int NaiveCompiler::getIndexByNameAndParent(char (&parent)[ALNG], char (&name)[ALNG], operate_table_mode mode)
{
    if (mode == declare_mode)
    {
        for (int i = 0; i <= t; i++)
        {
            if (strcmp(tab[i].parent, parent) == 0)
            {
                if (strcmp(tab[i].name, name) == 0)
                    return i;
            }
        }
        return -1;
    }
    else if (mode == search_mode)
    {
        for (int i = 0; i <= t; i++)
        {
            if (strcmp(tab[i].parent, parent) == 0)
            {
                if (strcmp(tab[i].name, name) == 0)
                    return i;
            }
        }

        for (int i = 0; i <= t; i++)
        {
            if (strcmp(tab[i].parent, string_global) == 0)
            {
                if (strcmp(tab[i].name, name) == 0)
                    return i;
            }
        }
        return -1;
    }
    return -1;
}
int NaiveCompiler::getAddrByName(char* name)
{
    int addr = -1;
    list<pair<char* , int>>::iterator ptr;
    ptr = data_stack.begin();
    for (; ptr != data_stack.end(); ptr++)
    {
        if (strcmp(ptr->first, name) == 0)
        {
            addr = ptr->second;
            break;
        }
    }
    return addr;
}
void NaiveCompiler::if_statement(char (&parent)[ALNG])
{
    
    char label[ALNG] = {};
    strcpy_s(label, "fangkd_ifend");
    f += 1;
    _itoa_s(f, &label[12], ALNG-13, 10);

    insymbol(symbols[0]);
    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 (");

    if (f_condition.count(symbols[0].sy))
    {
        condition(parent, label, false);
    }
    else
        error("if语句缺少条件");

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    if (f_statement.count(symbols[0].sy))
    {
        bool has_return=false;
        statement(parent, has_return);
    }
    else
        error("存在非法语句");

    
    append_midcode(label);//将标签加到最后
    programma_info << "这是一个“条件语句”" << endl;
}
void NaiveCompiler::insymbol(symbol_record (&aim))
{
    int i, j, k;
label_1:  
    aim.clear();
    while(ch == ' ' || ch == 9)
        nextch();

    if ((ch == '_') || islower(ch) || isupper(ch))
    {
        // key words and ident
        k = 1;
        memset(aim.id, 0, sizeof(aim.id));
        aim.id[0] = tolower(ch);
        nextch();
        while(isdigit(ch) || islower(ch) || isupper(ch) || ch == '_')
        {
            if (k < ALNG)
            {
                aim.id[k] = tolower(ch);
                k += 1;
            }
            nextch();
        }

        i = 0;
        j = NKW - 1;
        while(i <= j){
            k = (i + j) / 2;
            if (strcmp(aim.id, key[k]) == 0)
                break;
            if (strcmp(aim.id, key[k]) < 0)
                j = k - 1;
            if (strcmp(aim.id, key[k]) > 0)
                i = k + 1;
        }

        if (i <= j)//前面break了
            aim.sy = ksy[k];
        else
            aim.sy = ident;

    }
    else if (isdigit(ch))
    {
        // int
        i = 0;
        aim.inum = 0;
        aim.sy = intcon;

        if (ch == '0') // 0 一位
        {
            nextch();
            if (isdigit(ch))
            {
                while (isdigit(ch))
                    nextch();

                // 无符号整数不应以0开头，报错
                printf("无符号整数不应以0开头，报错 \n");
            }

        }
        else // 无符号整数，可多位
        {
            aim.inum = ch - '0';
            k = 1;
            nextch();
            while (isdigit(ch))
            {
                aim.inum = aim.inum * 10 + ch -'0';
                k += 1;
                nextch();
            }
            if (aim.inum > UINT32_MAX)
            {
                //数值超过无符号整数上界，报错
                printf("数值超过无符号整数上界，报错 \n");

                aim.inum = 0;
                k = 0;
            }

        }
    }
    else if (ch == '\'')
    {
        // charcon
        aim.sy = charcon;
        nextch();
        if (islower(ch) || isupper(ch) || isdigit(ch) || (ch == '_') 
            || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
        {
            aim.chval = ch;
            nextch();
            if (ch != '\'')
            {
                //字符最后不是单引号，报错
                printf("字符最后不是单引号，报错\n");
                aim.sy = nosy;
                goto label_1;
            }
            else
                nextch();
        }
        else
        {
            //单引号后面接的不是字母，数字或加减乘除符号，报错
            printf("单引号后面接的不是字母，数字或加减乘除符号，报错\n");
            aim.sy = nosy;
            goto label_1;
        }

    }
    else if (ch == '\"')
    {
        // stringcon
        memset(aim.strval, 0, sizeof(aim.strval));
        k = 0;
label_2:
        nextch();
        if (ch == '\"')
            goto label_3;

        //字符串合法内容的ascii码为32，33,35-126
        if (ch >= 32 && ch <= 126 && ch != 34)
        {
            aim.strval[k] = ch;
            k += 1;
            goto label_2;
        }
        else
        {
            printf("字符串内容不合法\n");
            //error
            goto label_1;
        }

label_3:
        aim.sy = stringcon;
        aim.sleng = k;
        nextch();
    }
    else if (ch == '=')
    {
        nextch();
        if (ch == '=')
        {
            // ==
            aim.sy = beq;
            nextch();
        }
        else
        {
            // = 
            aim.sy = becomesy;
        }
    }
    else if (ch == '>')
    {
        nextch();
        if (ch == '=')
        {
            // >=
            aim.sy = bge;
            nextch();
        }
        else
        {
            // >
            aim.sy = bgt;
        }
    }
    else if (ch == '<')
    {
        nextch();
        if (ch == '=')
        {
            // <=
            aim.sy = ble;
            nextch();
        }
        else
        {
            // <
            aim.sy = blt;
        }
    }
    else if (ch == '!')
    {
        nextch();
        if (ch == '=')
        {
            // != 
            aim.sy = bne;
            nextch();
        }
        else 
        {
            //错误处理
            printf(" ! 是不合法的 \n");
            aim.sy = nosy;
            goto label_1;
        }
    }
    else if (ch == '+')
    {
        // +
        aim.sy = plussy;
        nextch();
    }
    else if (ch == '-')
    {
        // -
        aim.sy = minussy;
        nextch();
    }
    else if (ch == '*')
    {
        // *
        aim.sy = multsy;
        nextch();
    }
    else if (ch == '/')
    {
        // /
        aim.sy = divsy;
        nextch();
    }
    else if (ch == ',')
    {
        // ,
        aim.sy = comma;
        nextch();
    }
    else if (ch == ';')
    {
        // ;
        aim.sy = semicomma;
        nextch();
    }
    else if (ch == ':')
    {
        // :
        aim.sy = colon;
        nextch();
    }
    else if (ch == '(')
    {
        // ( lparent
        aim.sy = lparent;
        nextch();
    }
    else if (ch == ')')
    {
        // ) rparent
        aim.sy = rparent;
        nextch();
    }
    else if (ch == '[')
    {
        // [ lsquare
        aim.sy = lsquare;
        nextch();
    }
    else if (ch == ']')
    {
        // ] rsquare
        aim.sy = rsquare;
        nextch();
    }
    else if (ch == '{')
    {
        // { lbrack
        aim.sy = lbrack;
        nextch();
    }
    else if (ch == '}')
    {
        // } rbrack
        aim.sy = rbrack;
        nextch();
    }
    else 
    {
        //处理非法符号
        printf(" 读入非法符号 \n");
        nextch();
        goto label_1;
    }
}
int NaiveCompiler::integer()
{
    
    int sym = 1;//1表示正号，-1表示负号
    int value = 0;

    if (symbols[0].sy == intcon && symbols[0].inum == 0)
    {
        insymbol(symbols[0]);
        return 0;
    }
    else
    {
        if (symbols[0].sy == plussy)
        {
            insymbol(symbols[0]);
        }
        else if (symbols[0].sy == minussy)
        {
            //更新整数符号为负
            sym = -1;
            insymbol(symbols[0]);
        }

        if (symbols[0].sy == intcon)
        {
            //登记整数的值
            value = (int)symbols[0].inum;
            insymbol(symbols[0]);
            value = sym * value;
            return value;
        }
        else
            error("分析到非法的整数值");
    }
    return 0;
    programma_info << "这是一个“整数”" << endl;
}
void NaiveCompiler::item(char (&parent)[ALNG], char (&rd)[ALNG], types (&typ))
{
    
    char rs[ALNG];
    char rt[ALNG];
    char op[ALNG];
    factor(parent, rs, typ);
    

    bool flag = false;
    while (symbols[0].sy == multsy || symbols[0].sy == divsy)
    {
        flag = true;
        //登记乘法运算符
        if (symbols[0].sy == multsy)
            strcpy_s(op, "*");
        else
            strcpy_s(op, "/");

        insymbol(symbols[0]);
        if (f_factor.count(symbols[0].sy))
        {
            factor(parent, rt, typ);
        }
        else
            error("运算符后面供运算的值");

        allocHelpVar(rd);
        append_midcode(op, rd, rs, rt);
        strcpy_s(rs, rd);
        typ = ints;
    }

    if (flag == false)
        strcpy_s(rd, rs);

    programma_info << "这是一个“项”" << endl;
}
void NaiveCompiler::loadValue2reg(char (&parent)[ALNG], char (&name)[ALNG], char* tar_reg)
{
    if (isdigit(name[0]))//标识符不可能是数字开头，所以数字开头的一定是常数
    {
        //如果是数字
        addi(tar_reg, "$0", atoi(name));
        return ;
    }

    int index;
    index = getIndexByNameAndParent(parent, name, search_mode);
    if (index == -1)
    {
        //说明不是局部变量或全局变量，而是辅助变量，在栈顶。
        lw(tar_reg, reg_sp, 4);
        addi(reg_sp, reg_sp, 4);
    }
    else
    {
        if (strcmp(tab[index].parent, string_global) == 0)
        {
            if (tab[index].obj == con)
                addi(tar_reg, "$0", tab[index].value);
            else
                lw(tar_reg, reg_t9, tab[index].address);
        } 
        else
        {
            if (tab[index].obj == con)
                addi(tar_reg, "$0", tab[index].value);
            else
                lw(tar_reg, reg_fp, tab[index].address);
        } 

    }

}
void NaiveCompiler::midcode2mips()
{
    char parent[ALNG];
    strcpy_s(parent, string_global);
    lui(reg_gp, 0x1000);//初始化参数栈首地址，向上增长
    lui(reg_fp, 0x1004);//初始化运行栈首地址，向上增长
    lui(reg_sp, 0x7fff);//初始化运算栈首地址，向下增长
    addi(reg_sp, "$sp", 0xeffc);
    lui(reg_t9, 0x1001);//初始化全局变量首地址
    _j("main");
    //addi("$t9", "$0", 0x27fc);//$t9保存参数栈指针
    for (int i = 0; i<mid_counter; i++)
    {
        if (strcmp(midcode[i].op, "+") == 0)
        {
            //lw lw add sw
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            add("$t2", "$t0", "$t1");
            saveValue2mem(parent, midcode[i].rd, "$t2");
        }
        else if (strcmp(midcode[i].op, "-") == 0)
        {
            //lw lw sub sw
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            sub("$t2", "$t0", "$t1");
            saveValue2mem(parent, midcode[i].rd, "$t2");
        }
        else if (strcmp(midcode[i].op, "*") == 0)
        {
            // lw lw mult mflo
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            mult("$t0", "$t1");
            saveValue2mem(parent, midcode[i].rd, "lo");
        }
        else if (strcmp(midcode[i].op, "/") == 0)
        {
            // lw lw div mflo
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            div("$t0", "$t1");
            saveValue2mem(parent, midcode[i].rd, "lo");
        }
        else if (strcmp(midcode[i].op, "aar") == 0)
        {
            //暂不处理
        }
        else if (strcmp(midcode[i].op, "push") == 0)
        {
            //lw sw
            //addi $sp $sp 4
            loadValue2reg(parent, midcode[i].rs, "$t0");
            sw("$t0", reg_gp, 0);
            addi(reg_gp, reg_gp, 4);
        }
        else if (strcmp(midcode[i].op, "call") == 0)
        {
            //jal
            int index = getIndexByNameAndParent(string_global, parent, search_mode);
            addi("$t0", reg_fp, 0);
            addi(reg_fp, reg_fp, tab[index].value);
            sw("$t0", reg_fp, 0);//保存上一级fp
            /*sw("$s0", reg_fp, 12);//保存$s0
            sw("$s1", reg_fp, 16);//保存$s1
            sw("$s2", reg_fp, 20);//保存$s2
            sw("$s3", reg_fp, 24);//保存$s3
            sw("$s4", reg_fp, 28);//保存$s4
            sw("$s5", reg_fp, 32);//保存$s5
            sw("$s6", reg_fp, 36);//保存$s6
            sw("$s7", reg_fp, 40);//保存$s7*/
            jal(midcode[i].rs);
        }
        else if (strcmp(midcode[i].op, "=") == 0)
        {
            //lw, sw
            loadValue2reg(parent, midcode[i].rs, "$t0");
            saveValue2mem(parent, midcode[i].rd, "$t0");
        }
        else if (strcmp(midcode[i].op, "==") == 0)
        {
            //lw lw beq
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            slt("$t2", "$t0", "$t1");
            slt("$t3", "$t1", "$t0");
            _nor("$t0", "$t2", "$t3");
            andi("$t0", "$t0", 0x1);
        }
        else if (strcmp(midcode[i].op, "!=") == 0)
        {
            //lw lw bne
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            slt("$t2", "$t0", "$t1");
            slt("$t3", "$t1", "$t0");
            _or("$t0", "$t2", "$t3");
        }
        else if (strcmp(midcode[i].op, ">") == 0)
        {
            //lw lw bgt
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            slt("$t2", "$t0", "$t1");
            slt("$t3", "$t1", "$t0");
            _nor("$t4", "$t2", "$t3");
            andi("$t4", "$t4", 0x1);
            _nor("$t0", "$t2", "$t4");
            andi("$t0", "$t0", 0x1);
        }
        else if (strcmp(midcode[i].op, ">=") == 0)
        {
            //lw lw bge
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            slt("$t0", "$t1", "$t0");
        }
        else if (strcmp(midcode[i].op, "<") == 0)
        {
            //lw lw blt
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            slt("$t0", "$t0", "$t1");
        }
        else if (strcmp(midcode[i].op, "<=") == 0)
        {
            //lw lw ble
            loadValue2reg(parent, midcode[i].rt, "$t1");
            loadValue2reg(parent, midcode[i].rs, "$t0");
            slt("$t2", "$t0", "$t1");
            slt("$t3", "$t1", "$t0");
            _nor("$t4", "$t2", "$t3");
            andi("$t4", "$t4", 0x1);
            _or("$t0", "$t2", "$t4");
        }
        else if (strcmp(midcode[i].op, "BNZ") == 0)
        {
            _bne("$t0", "$0", midcode[i].rd);
        }
        else if (strcmp(midcode[i].op, "BZ") == 0)
        {
            _beq("$t0", "$0", midcode[i].rd);
        }
        else if (strcmp(midcode[i].op, "GOTO") == 0)
        {
            //j
            _j(midcode[i].rs);
        }
        else if (strcmp(midcode[i].op, "ret") == 0)
        {
            //jr $ra
            if (midcode[i].rs[0] != '\0')
            {
                loadValue2reg(parent, midcode[i].rs, "$v0");
                sw("$v0", reg_sp, 0);
                addi("$sp", reg_sp, -4);
            }
            
            lw("$31", reg_fp, 8);
            lw(reg_fp, reg_fp, 0);
            jr(31);
        }
        else if (strcmp(midcode[i].op, "[]=") == 0)
        {
            //查找数组首地址，根据索引计算偏移，lw sw
            //赋值方向：简单值->数组元素
            int index = getIndexByNameAndParent(parent, midcode[i].rs, search_mode);
            int baseAddr = tab[index].address;
            addi("$t1", "$0", baseAddr);
            loadValue2reg(parent, midcode[i].rt, "$t2");
            //int element_offset = baseAddr + 4 * offset;
            sll("$t2", "$t2", 2);
            add("$t1", "$t1", "$t2");
            loadValue2reg(parent, midcode[i].rd, "$t0");
            if (strcmp(tab[index].parent, string_global) == 0)
                add("$t1", "$t1", reg_t9);
            else
                add("$t1", "$t1", reg_fp);
            sw("$t0", "$t1", 0);
        }
        else if (strcmp(midcode[i].op, "=[]") == 0)
        {
            //查找数组首地址，根据索引计算偏移，lw sw
            //赋值方向：数组元素->简单值
            int index = getIndexByNameAndParent(parent, midcode[i].rs, search_mode);
            int baseAddr = tab[index].address;
            addi("$t1", "$0", baseAddr);
            loadValue2reg(parent, midcode[i].rt, "$t2");
            //int element_offset = baseAddr + 4 * offset;
            sll("$t2", "$t2", 2);
            add("$t1", "$t1", "$t2");
            if (strcmp(tab[index].parent, string_global) == 0)
                add("$t1", "$t1", reg_t9);
            else
                add("$t1", "$t1", reg_fp);
            lw("$t0", "$t1", 0);
            saveValue2mem(parent, midcode[i].rd, "$t0");
        }
        else if (strcmp(midcode[i].op, "prt") == 0)
        {
            //addi $v0 $0 [数字]（输出模式：字符or数字）
            //lw
            //syscall
            if (strcmp(midcode[i].rt, "char") == 0)
                addi("$v0", "$0", 11);
            else
                addi("$v0", "$0", 1);

            loadValue2reg(parent, midcode[i].rs, "$a0");
            syscall();
        }
        else if (strcmp(midcode[i].op, "scf") == 0)//rd字段表示待赋值变量，rs字段表示读入类型
        {
            //addi $v0 $0 [数字]（输入模式：字符or数字）
            //syscall
            if (strcmp(midcode[i].rs, "char") == 0)
                addi("$v0", "$0", 12);
            else
                addi("$v0", "$0", 5);

            syscall();
            saveValue2mem(parent, midcode[i].rd, "$v0");
        }
        else if (strcmp(midcode[i].op, "func_def") == 0)
        {
            //label:
            memset(parent, 0, sizeof(parent));
            strcpy_s(parent, midcode[i].rt);
            generate_label(midcode[i].rt);
            sw("$31", reg_fp, 8);//保存返回地址，main函数没关系，后申请的变量会把这覆盖掉，反正main不需要保存返回值
        }
        else if (strcmp(midcode[i].op, "para") == 0)
        {
            //lw sw 
            //addi $sp $sp -4
            int index = getIndexByNameAndParent(parent, midcode[i].rt, search_mode);
            lw("$t0", reg_gp, -4);
            addi(reg_gp, reg_gp, -4);
            sw("$t0", reg_fp, tab[index].address);
        }
        else
        {
            //输出标签
            generate_label(midcode[i].op);
        }
    }
}
void NaiveCompiler::nextch()
{
    if (cc == ll)
    {
        if (fin.eof())
        {
            //fout << "incomplete program" << endl;
            //errormsg();
            exit(0);
        }

        ll = -1;
        cc = -1;
        memset(line, ' ', sizeof(line));
        fin.getline(line, sizeof(line));
        ln += 1;
        if (fin.fail())
        {
            //printf("读取失败 \n");
        }
        while (ll < LLNG)
        {
            ll += 1;
            if ((line[ll] == '\0') || (line[ll] == '\n'))
            {
                line[ll] = ' ';
                break;
            }
                
        }
    }

    cc += 1;
    ch = line[cc];
}
void NaiveCompiler::one_case(char (&parent)[ALNG], types typ, char (&end)[ALNG], char (&rs)[ALNG], set<int> (&exist_const))
{
    
    char nextCase[ALNG];
    char rt[ALNG];
    strcpy_s(nextCase, "fkd_nextcase");
    f += 1;
    _itoa_s(f, &nextCase[12], ALNG-13, 10);

    int const_value = 0;
    insymbol(symbols[0]);

    if (f_const.count(symbols[0].sy))
    {
        const_value = constant(typ);
        _itoa_s(const_value, rt, 10);
        if (exist_const.count(const_value))
            error("检测到case语句中出现重复的常量值");
        else
            exist_const.insert(const_value);
    }
    else
        error("case后面应该接常量");

    append_midcode("==", nullptr, rs, rt);
    append_midcode("BZ", nextCase);

    if (symbols[0].sy == colon)
        insymbol(symbols[0]);
    else
        error("缺少 :");

    if (f_statement.count(symbols[0].sy))
    {
        bool has_return=false;
        statement(parent, has_return);
        append_midcode("GOTO", nullptr, end);
    }
    else
        error("存在非法语句");

    append_midcode(nextCase);
    programma_info << "这是一个“情况子语句”" << endl;
}
void NaiveCompiler::parameter_list(char (&parent)[ALNG])
{
    
    types typ = notyp;
    char para_name[ALNG] = "";

    if (symbols[0].sy == intsy || symbols[0].sy == charsy)
    {
        //登记参数类型
        typ = symbols[0].sy == intsy  ? ints  :
              symbols[0].sy == charsy ? chars : notyp ;
        insymbol(symbols[0]);
        if (symbols[0].sy == ident)
        {

            //登记参数名
            strcpy_s(para_name, symbols[0].id);
            insymbol(symbols[0]);
        }
        else
            error("参数名称不合法");

        //登入符号表
        if (strcmp(para_name, "") && typ != notyp)
        {
            if (t == TABLE_SIZE - 1)
            {
                //fatal
                fatal("符号表容量不够");
            }
            t += 1;

            strcpy_s(tab[t].name, para_name);
            tab[t].obj = para;
            tab[t].typ = typ;
            strcpy_s(tab[t].parent, parent);
            tab[t].address = dx;
            dx += 4;

            //对应函数的参数个数+1
            int func_index = getIndexByNameAndParent(string_global, parent, search_mode);
            if (func_index == -1)
                error("找不到函数");
            else
                tab[func_index].ref += 1;

            if (typ == ints)
                append_midcode("para", nullptr, "int", para_name);
            else if (typ == chars)
                append_midcode("para", nullptr, "char", para_name);
        }

        while (symbols[0].sy == comma)
        {
            strcpy_s(para_name, "");
            typ = notyp;

            insymbol(symbols[0]);
            if (symbols[0].sy == intsy || symbols[0].sy == charsy)
            {
                //登记参数类型
                typ = symbols[0].sy == intsy  ? ints  :
                    symbols[0].sy == charsy ? chars : notyp ;
                insymbol(symbols[0]);
                if (symbols[0].sy == ident)
                {
                    //登记参数名
                    strcpy_s(para_name, symbols[0].id);
                    insymbol(symbols[0]);
                    
                }
                else
                    error("参数名称不合法");

                if (getIndexByNameAndParent(parent, symbols[0].id, declare_mode) == -1)
                {
                    //登入符号表
                    if (strcmp(para_name, "") && typ != notyp)
                    {
                        if (t == TABLE_SIZE - 1)
                        {
                            //fatal
                            fatal("符号表容量不够");
                        }
                        t += 1;

                        strcpy_s(tab[t].name, para_name);
                        tab[t].obj = para;
                        tab[t].typ = typ;
                        strcpy_s(tab[t].parent, parent);
                        tab[t].address = dx;
                        dx += 4;

                        //对应函数的参数个数+1
                        int func_index = getIndexByNameAndParent(string_global, parent, search_mode);
                        if (func_index == -1)
                            error("找不到函数");
                        else
                            tab[func_index].ref += 1;

                        if (typ == ints)
                            append_midcode("para", nullptr, "int", para_name);
                        else if (typ == chars)
                            append_midcode("para", nullptr, "char", para_name);

                    }
                }
                else
                    error("参数名重复");
            }
            else
                error("逗号后面出现非法类型的参数");
        }
    }
    //不需要else，因为参数表可能为空

    programma_info << "这是一个“参数表”" << endl;
}
void NaiveCompiler::printf_statement(char (&parent)[ALNG])
{
    
    types typ;
    char rs[ALNG];
    char rt[ALNG];
    insymbol(symbols[0]);
    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 (");

    if (symbols[0].sy == stringcon)
    {
        //输出字符串内容
        for (int i = 0; i < symbols[0].sleng; i++)
        {
            _itoa_s(symbols[0].strval[i], rs, 10);
            strcpy_s(rt, "char");
            append_midcode("prt", nullptr, rs, rt);
        }
        
        //取消stab，将字符串内容保存在symbol_record对象中，需要时直接输出。
        insymbol(symbols[0]);
        if (symbols[0].sy == comma)
        {
            insymbol(symbols[0]);
            if (f_expression.count(symbols[0].sy))
            {
                expression(parent, rs, typ);
                if (typ == chars)
                    strcpy_s(rt, "char");
                else
                    strcpy_s(rt, "int");
                append_midcode("prt", nullptr, rs, "int");
            }
            else
                error("发现非法的表达式");
        }
        //可以没有逗号和表达式，只有字符串

        if (symbols[0].sy == rparent)
            insymbol(symbols[0]);
        else
            error("缺少 )");
    }
    else if (f_expression.count(symbols[0].sy))
    {
        expression(parent, rs, typ);
        if (typ == chars)
            strcpy_s(rt, "char");
        else
            strcpy_s(rt, "int");
        append_midcode("prt", nullptr, rs, rt);

        if (symbols[0].sy == rparent)
            insymbol(symbols[0]);
        else
            error("缺少 )");
    }
    else
        error("检测到非法的输出内容");

    programma_info << "这是一个“输出语句”" << endl;
}
void NaiveCompiler::program()
{
    dx = 0;
    //处理“常量声明”
    if (f_const_declare.count(symbols[0].sy))//count返回值大于0说明sy属于集合
        const_declare(string_global);

    //处理“变量声明”，须向前看两个符号，查看是变量声明还是有返回值的函数定义
    if (f_var_declare.count(symbols[0].sy))
    {
        insymbol(symbols[1]);
        end++;
        if (symbols[1].sy != ident)
            error("检测到非法的函数名/变量名");
        insymbol(symbols[2]);
        end++;
        

        if (symbols[2].sy == semicomma || symbols[2].sy == comma || symbols[2].sy == lsquare)
        {
            //处理“变量声明”，此时已读入三个字符
            var_declare(string_global);
        }

        if (end == 2)
        {
            //兼顾变量声明为空和变量声明后紧接着就是有返回值函数定义两种情况，两种情况均已提前读入3个symbol
            if (symbols[2].sy == lparent)
            {
                return_func_declare();
            }
            else
            {
                //清理残留值确保进入下一个语句块时只有symbols[0]的值是有效的
                symbols[0].clear();
                symbols[1].clear();
                symbols[2].clear();
                end = 0;
                insymbol(symbols[0]);
            }
        }
        else if (end == 0)
        {

        }
        else
            error("program处理程序中遇到未考虑的情况");
        
    }

    while (f_return_func_declare.count(symbols[0].sy)
        || f_void_func_declare.count(symbols[0].sy))
    {
        if (symbols[0].sy == intsy || symbols[0].sy == charsy)
            return_func_declare();
        else
        {
            insymbol(symbols[1]);
            end = 1;
            if (symbols[1].sy == mainsy)
                break;
            else if (symbols[1].sy == ident)
                void_func_declare();
            else
                error("检测到非法的函数名");
        }
    }

    if (symbols[0].sy == voidsy && symbols[1].sy == mainsy)
    {
        void_main();
    }
    else
        error("缺少主函数");
    programma_info << "这是一个“程序”" << endl;
}
void NaiveCompiler::return_func_declare()
{
    
    dx = 44;//有返回值函数的形式参数区包括上级fp，返回值，返回地址，每个占4字节，共占12字节。还有s0到s7共八个寄存器要保存
    char func_name[ALNG] = "";
    types return_type = notyp;
    bool has_return = false;

    if (end == 2)
    {
        //登记函数名和返回值类型
        strcpy_s(func_name, symbols[1].id);
        return_type = symbols[0].sy == intsy  ? ints  :
                      symbols[0].sy == charsy ? chars : notyp ;
        symbols[0].clear();
        symbols[1].clear();
        symbols[2].clear();
        end = 0;
        insymbol(symbols[0]);
    }
    else
    {
        //登记返回值类型
        return_type = symbols[0].sy == intsy  ? ints  :
                      symbols[0].sy == charsy ? chars : notyp ;
        insymbol(symbols[0]);
        if (symbols[0].sy == ident)
        {
            //登记函数名称
            strcpy_s(func_name, symbols[0].id);
            insymbol(symbols[0]);
        }
        else
            error("检测到非法的函数名");

        if (symbols[0].sy == lparent)
            insymbol(symbols[0]);
        else
            error("缺少 (");
    }

    if (strcmp(func_name, "") && return_type != notyp 
     && getIndexByNameAndParent(string_global, func_name, declare_mode) == -1)
    {
        //登记函数名称和返回值
        if (t == TABLE_SIZE - 1)
        {
            //fatal,符号表容量不够，退出
            fatal("符号表容量不够");
        }
        t += 1;

        strcpy_s(tab[t].name, func_name);
        tab[t].obj = func;
        tab[t].typ = return_type;
        strcpy_s(tab[t].parent, string_global);
        tab[t].ref = 0;//初始化参数个数，读参数表时计数

        if (return_type == ints)
            append_midcode("func_def", nullptr, "int", func_name);
        else if (return_type == chars)
            append_midcode("func_def", nullptr, "char", func_name);
        
    }

    parameter_list(func_name);//可能为空，故不必判断开始符号集

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    if (symbols[0].sy == lbrack)
        insymbol(symbols[0]);
    else
        error("缺少 {");

    compound_statement(func_name, has_return);
    if (has_return == false)
        error("函数缺少返回值");


    if (symbols[0].sy == rbrack)
        insymbol(symbols[0]);
    else
        error("缺少 }");

    programma_info << "这是一个“有返回值函数声明”" << endl;
}
void NaiveCompiler::return_statement(char (&parent)[ALNG])
{
    
    types typ;
    char rs[ALNG];
    insymbol(symbols[0]);
    if (symbols[0].sy == lparent)
    {
        insymbol(symbols[0]);
        if (f_expression.count(symbols[0].sy))
        {
            expression(parent, rs, typ);
            append_midcode("ret", nullptr, rs);
        }
        else
            error("检测到非法的表达式");

        if (symbols[0].sy == rparent)
            insymbol(symbols[0]);
        else
            error("缺少 )");
    }
    else if (symbols[0].sy == semicomma)
    {
        if (strcmp(parent, string_main) == 0)//如果是主函数，就没有上一级函数了，直接跳到程序末端
            append_midcode("GOTO", nullptr, "fkd_program_end");
        else
            append_midcode("ret");
    }
        
    //可能只有一个return，再读一个字符已经出返回语句的范围了，所以不用报错
    programma_info << "这是一个“返回语句”" << endl;
}
void NaiveCompiler::saveValue2mem(char (&parent)[ALNG], char (&name)[ALNG], char* src_reg)
{
    char src[ALNG];
    if (strcmp(src_reg, "lo") == 0)
    {
        mflo("$t0");
        strcpy_s(src, "$t0");
    }
    else
        strcpy_s(src, src_reg);

    int index;
    index = getIndexByNameAndParent(parent, name, search_mode);
    if (index == -1)
    {
        //说明不是局部变量或全局变量，而是辅助变量，在栈顶。
        sw(src, reg_sp, 0);
        addi(reg_sp, reg_sp, -4);
    }
    else
    {
        if (strcmp(tab[index].parent, string_global) == 0)
            sw(src, reg_t9, tab[index].address);
        else
            sw(src, reg_fp, tab[index].address);
    }
}
void NaiveCompiler::scanf_statement(char (&parent)[ALNG])
{
    
    char rd[ALNG];
    char rs[ALNG];
    int index = 0;
    insymbol(symbols[0]);
    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 (");

    if (symbols[0].sy == ident)
    {
        //处理标识符
        index = getIndexByNameAndParent(parent, symbols[0].id, search_mode);
        if (index == -1)
        {
            string msg = symbols[0].id;
            msg.append("不存在");
            error(msg);
        }

        if (tab[index].obj != var)
        {
            //报错，不是变量
            string msg = tab[index].name;
            msg.append("不是变量");
            error(msg);
        }

        if (tab[index].typ == chars)
            strcpy_s(rs, "char");
        else if (tab[index].typ == ints)
            strcpy_s(rs, "int");
        else
        {
            string msg = tab[index].name;
            msg.append("既不是字符型也不是整型，输入语句无法为之赋值");
            error(msg);
        }

        strcpy_s(rd, tab[index].name);
        append_midcode("scf", rd, rs);

        insymbol(symbols[0]);
        while (symbols[0].sy == comma)
        {
            insymbol(symbols[0]);
            if (symbols[0].sy == ident)
            {
                //处理标识符
                index = getIndexByNameAndParent(parent, symbols[0].id, search_mode);
                if (index == -1)
                {
                    string msg = symbols[0].id;
                    msg.append("不存在");
                    error(msg);
                }

                if (tab[index].obj != var)
                {
                    string msg = tab[index].name;
                    msg.append("不是变量");
                    error(msg);
                }

                if (tab[index].typ == chars)
                    strcpy_s(rs, "char");
                else if (tab[index].typ == ints)
                    strcpy_s(rs, "int");
                else
                {
                    string msg = tab[index].name;
                    msg.append("既不是字符型也不是整型，输入语句无法为之赋值");
                    error(msg);
                }

                strcpy_s(rd, tab[index].name);
                append_midcode("scf", rd, rs);

                insymbol(symbols[0]);
            }
            else
            {
                //报错
                error("逗号后面缺少参数");
            }
        }
    }
    else
        error("scanf应至少有一个参数");

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    programma_info << "这是一个“输入语句”" << endl;
}
void NaiveCompiler::skip(set<symbol> begin_symbol_set)
{
    while (begin_symbol_set.count(symbols[0].sy) == 0)
        insymbol(symbols[0]);
}
void NaiveCompiler::statement(char (&parent)[ALNG], bool &has_return)
{
    
    if (f_if.count(symbols[0].sy))
    {
        //处理条件语句
        if_statement(parent);
    }
    else if (f_do_while.count(symbols[0].sy))
    {
        //处理循环语句
        do_while_statement(parent);
    }
    else if (f_switch.count(symbols[0].sy))
    {
        //处理情况语句
        switch_statement(parent);
    }
    else if (symbols[0].sy == lbrack)
    {
        insymbol(symbols[0]);
        bool has_return=false;
        statement_column(parent, has_return);
        if (symbols[0].sy == rbrack)
        {
            insymbol(symbols[0]);
        }
        else
            error("缺少 }");
    }
    else if (symbols[0].sy == ident)
    {
        insymbol(symbols[1]);
        end = 1;
        if (symbols[1].sy == becomesy || symbols[1].sy == lsquare)
        {
            //处理赋值语句
            assign_statement(parent);
        }
        else if (symbols[1].sy == lparent)
        {
            int index = 0;
            //处理有返回值调用语句和无返回值调用语句
            //须查表得到返回值类型
            index = getIndexByNameAndParent(string_global, symbols[0].id, search_mode);
            if (index == -1)
            {
                //报错，不存在
                string msg = tab[index].name;
                msg.append("不存在");
                error(msg);
            }
            else if (tab[index].obj != func)
            {
                //报错，不是函数
                string msg = tab[index].name;
                msg.append("不是函数，类型不符");
                error(msg);
            }
            else
            {
                //如果是void
                //call_void_func();
                //如果不是void
                //call_return_func();
                if (tab[index].typ == notyp)
                {
                    call_void_func(parent);
                }
                else
                {
                    char rd[ALNG];
                    types typ;
                    call_return_func(parent, rd, typ);
                }
            }
        }
        else
            error("检测到非法语句");

        if (symbols[0].sy == semicomma)
            insymbol(symbols[0]);
        else
            error("缺少 ;");
    }
    else if (f_scanf.count(symbols[0].sy))
    {
        //处理读语句
        scanf_statement(parent);

        if (symbols[0].sy == semicomma)
            insymbol(symbols[0]);
        else
            error("缺少 ;");
    }
    else if (f_printf.count(symbols[0].sy))
    {
        //处理写语句
        printf_statement(parent);

        if (symbols[0].sy == semicomma)
            insymbol(symbols[0]);
        else
            error("缺少 ;");
    }
    else if (f_return.count(symbols[0].sy))
    {
        //处理返回语句
        return_statement(parent);
        has_return = true;
        if (symbols[0].sy == semicomma)
            insymbol(symbols[0]);
        else
            error("缺少 ;");
    }
    else if (symbols[0].sy == semicomma)
    {
        //空语句
        programma_info << "这是一个“空语句”" << endl;
        insymbol(symbols[0]);
    }
    else
        error("检测到非法语句");

    programma_info << "这是一个“语句”" << endl;
}
void NaiveCompiler::statement_column(char (&parent)[ALNG], bool &has_return)
{
    
    while (f_statement.count(symbols[0].sy))
    {
        statement(parent, has_return);

    }
    //有可能为空，不需要else报错

    programma_info << "这是一个“语句列”" << endl;
}
void NaiveCompiler::switch_statement(char (&parent)[ALNG])
{
    
    types typ;
    char rs[ALNG];
    insymbol(symbols[0]);
    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 (");

    if (f_expression.count(symbols[0].sy))
    {
        expression(parent, rs, typ);
    }
    else
        error("检测到非法表达式");

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    if (symbols[0].sy == lbrack)
        insymbol(symbols[0]);
    else
        error("缺少 {");

    if (f_caselist.count(symbols[0].sy))
    {
        caselist(parent, typ, rs);
    }
    else
        error("检测到非法的情况表");

    if (symbols[0].sy == rbrack)
        insymbol(symbols[0]);
    else
        error("缺少 }");

    programma_info << "这是一个“情况语句”" << endl;
}
void NaiveCompiler::value_parameter_list(char (&parent)[ALNG], char (&called_func)[ALNG])
{
    int count = 0;
    types typ;
    char rs[20][ALNG];

    int func_index = getIndexByNameAndParent(string_global, called_func, search_mode);
    if (func_index == -1)
        error("找不到值参数所属的函数");
    

    if (f_expression.count(symbols[0].sy))
    {
        //处理表达式
        expression(parent, rs[count], typ);
        count += 1;
        if (count <= tab[func_index].ref)
        {
            if (tab[func_index+count].typ != typ)
                error("实参与形参类型不符");
        }
        else
            error("实参个数过多");
        
        //append_midcode("push", nullptr, rs);
        
        while (symbols[0].sy == comma)
        {
            insymbol(symbols[0]);
            if (f_expression.count(symbols[0].sy))
            {
                expression(parent, rs[count], typ);
                count += 1;
                if (count <= tab[func_index].ref)
                {
                    if (tab[func_index+count].typ == chars && typ == ints)
                        error("不能将整型的值赋给字符型的参数");
                }
                else
                    error("实参个数过多");
                //append_midcode("push", nullptr, rs);
            }
            else
                error("检测到非法表达式");
        }

        for (int i=count-1; i>=0; i--)
            append_midcode("push", nullptr, rs[i]);
    }
    //可能为空,故不必报错

    //检查形参个数与实参个数是否相等
    if (func_index != -1)
    {
        if (count < tab[func_index].ref)
            error("调用时传递的参数过少");
    }
    programma_info << "这是一个“值参数表”" << endl;
}
//每次处理完一个变量定义，都要向前看3个symbol，如果发现是有返回值函数，立即跳出，如果发现是无返回值函数，直接返回，不必再向前读3个symbol
void NaiveCompiler::var_declare(char (&parent)[ALNG])
{
    
var_declare_label:
    var_define(parent);//var_declare和var_define的开始符号集一致，无需再判断
    
    if (end == 0)
    {
        //处理没有预读三个的情况
        if (symbols[0].sy == semicomma)
            insymbol(symbols[0]);
        else
            error("缺少 ;");
    }
    else
        error("遇到未考虑的情况");

    if (f_var_define.count(symbols[0].sy))
    {
        insymbol(symbols[1]);
        end++;
        if (symbols[1].sy != ident)
            error("检测到非法的函数名/变量名");
        insymbol(symbols[2]);
        end++;

        if (symbols[2].sy == semicomma || symbols[2].sy == comma || symbols[2].sy == lsquare)
        {
            goto var_declare_label;
        }
    }
    programma_info << "这是一个“变量说明”" << endl;
}
void NaiveCompiler::var_define(char (&parent)[ALNG])
{
    
    types typ = notyp;
    char var_name[ALNG] = "";
    objecttyp obj = var;//有可能是var（简单变量）或array（数组）
    int array_size = 0;

    if (end == 2)
    {
        //登记符号表,名字和类型
        typ = symbols[0].sy == charsy   ? chars :
              symbols[0].sy == intsy    ? ints  : notyp ;
        symbols[0].clear();

        strcpy_s(var_name, symbols[1].id);
        symbols[1].clear();

        if (symbols[2].sy == lsquare)
        {
            //若symbols[2].sy == lsquare, 登记类型为数组
            obj = arr;
            symbols[2].clear();
            end = 0;
            insymbol(symbols[0]);
            if (symbols[0].sy == intcon)
            {
                if (symbols[0].inum != 0)
                {
                    //登记数组size
                    array_size = (int)symbols[0].inum;
                    insymbol(symbols[0]);
                }
                else
                    error("数组包含元素数目为0");
            }
            else
                error("检测到非法的数组元素个数");

            if (symbols[0].sy == rsquare)
                insymbol(symbols[0]);
            else
                error("缺少 ]");
        }

        //登入符号表
        if (strcmp(var_name, "") && typ != notyp)
        {
            if (getIndexByNameAndParent(parent, var_name, declare_mode) == -1)
            {
                if (t == TABLE_SIZE - 1)
                {
                    //fatal,符号表容量不够
                    fatal("符号表容量不够");
                }

                t += 1;
                if (obj == arr)
                {
                    if (a == ARRAY_TABLE_SIZE - 1)
                    {
                        //fatal，数组表容量不够
                        fatal("数组表容量不够");
                    }
                    //录入符号表
                    strcpy_s(tab[t].name, var_name);
                    tab[t].obj = obj;
                    strcpy_s(tab[t].parent, parent);
                    
                    //录入数组表
                    a += 1;
                    tab[t].ref = a;//保存在数组表中的索引
                    atab[a].size = array_size;
                    atab[a].elementType = typ;
                    atab[a].elementSize = typ == ints ? 4 : 1 ;//int : 4 bytes ; char : 1 byte
                    /*if (typ == ints)//整型要4个字节，所以要对齐；字符型一个字节，一直是对齐的。
                        {
                            dx = (dx + 3) / 4;
                        }*/
                    tab[t].address = dx;
                    dx = dx + 4 * array_size;

                    if (typ == chars)
                        midcodefile << "var char " << var_name << "[" << array_size << "]" << endl;
                    else if (typ == ints)
                        midcodefile << "var int " << var_name << "[" << array_size << "]" << endl;
                }
                else//obj == var
                {
                    strcpy_s(tab[t].name, var_name);
                    tab[t].obj = obj;
                    tab[t].typ = typ;
                    strcpy_s(tab[t].parent, parent);
                    /*if (typ == ints)//整型要4个字节，所以要对齐；字符型一个字节，一直是对齐的。
                        {
                            dx = (dx + 3) / 4;
                        }*/
                    tab[t].address = dx;
                    dx = dx + 4;

                    if (typ == chars)
                        midcodefile << "var char " << var_name << endl;
                    else if (typ == ints)
                        midcodefile << "var int " << var_name << endl;
                }
            }
            else
            {
                string msg = var_name;
                msg.append("重复声明");
                error(msg);
            }
        }

        if (obj == arr)
        {
            if (symbols[0].sy == comma)
            {
                insymbol(symbols[0]);
                goto var_define_label;
            }
            //else的情况为分号，直接退出即可
        }
        else if (symbols[2].sy == comma)
        {
            symbols[2].clear();
            end = 0;
            insymbol(symbols[0]);
            goto var_define_label;
        }
        //else的情况为分号，直接退出即可
        else
        {
            symbols[2].copy(symbols[0]);
            end = 0;
            symbols[2].clear();
        }
    }
    else//end == 0
    {
        //登记符号类型
        typ = symbols[0].sy == charsy   ? chars :
              symbols[0].sy == intsy    ? ints  : notyp ;
        insymbol(symbols[0]);

var_define_label:
        obj = var;
        memset(var_name, 0, sizeof(var_name));
        if (symbols[0].sy == ident)
        {
            //登记符号名称
            strcpy_s(var_name, symbols[0].id);
            insymbol(symbols[0]);
        }
        else
            error("检测到非法的变量名");

        if (symbols[0].sy == lsquare)
        {
            //登记数组
            obj = arr;
            insymbol(symbols[0]);
            if (symbols[0].sy == intcon)
            {
                if (symbols[0].inum != 0)
                {
                    //登记数组size
                    array_size = (int)symbols[0].inum;
                    insymbol(symbols[0]);
                }
                else
                    error("数组包含元素数目为0");
            }
            else
                error("检测到非法的数组元素个数");

            if (symbols[0].sy == rsquare)
                insymbol(symbols[0]);
            else
                error("缺少 ]");
        }

        //登入符号表
        if (strcmp(var_name, "") && typ != notyp)
        {
            if (getIndexByNameAndParent(parent, var_name, declare_mode) == -1)
            {
                if (t == TABLE_SIZE - 1)
                {
                    //fatal,符号表容量不够
                    fatal("符号表容量不够");
                }

                t += 1;
                if (obj == arr)
                {
                    if (a == ARRAY_TABLE_SIZE - 1)
                    {
                        //fatal，数组表容量不够
                        fatal("数组表容量不够");
                    }
                    //录入符号表
                    strcpy_s(tab[t].name, var_name);
                    tab[t].obj = obj;
                    strcpy_s(tab[t].parent, parent);

                    //录入数组表
                    a += 1;
                    tab[t].ref = a;//保存在数组表中的索引
                    atab[a].size = array_size;
                    atab[a].elementType = typ;
                    atab[a].elementSize = typ == ints ? 4 : 1 ;//int : 4 bytes ; char : 1 byte
                    /*if (typ == ints)//整型要4个字节，所以要对齐；字符型一个字节，一直是对齐的。
                        {
                            dx = (dx + 3) / 4;
                        }*/
                    tab[t].address = dx;
                    dx = dx + 4 * array_size;

                    if (typ == chars)
                        midcodefile << "var char " << var_name << "[" << array_size << "]" << endl;
                    else if (typ == ints)
                        midcodefile << "var int " << var_name << "[" << array_size << "]" << endl;
                }
                else//obj == var
                {
                    strcpy_s(tab[t].name, var_name);
                    tab[t].obj = obj;
                    tab[t].typ = typ;
                    strcpy_s(tab[t].parent, parent);
                    /*if (typ == ints)//整型要4个字节，所以要对齐；字符型一个字节，一直是对齐的。
                        {
                            dx = (dx + 3) / 4;
                        }*/
                    tab[t].address = dx;
                    dx = dx + 4;

                    if (typ == chars)
                        midcodefile << "var char " << var_name << endl;
                    else if (typ == ints)
                        midcodefile << "var int " << var_name << endl;
                }
            }
            else
            {
                string msg = var_name;
                msg.append("重复声明");
                error(msg);
            }
        }

        if (symbols[0].sy == comma)
        {
            insymbol(symbols[0]);
            goto var_define_label;
        }
    }
    programma_info << "这是一个“变量定义”" << endl;
}
void NaiveCompiler::void_func_declare()
{
    
    dx = 44;//有返回值函数的形式参数区包括上级fp，返回值，返回地址，每个占4字节，共占12字节。还有s0到s7共八个寄存器要保存
    char func_name[ALNG] = "";

    if (end == 1)
    {
        //登记函数名称
        strcpy_s(func_name, symbols[1].id);
        symbols[0].clear();
        symbols[1].clear();
        end = 0;
        insymbol(symbols[0]);
    }
    else
    {
        insymbol(symbols[0]);
        if (symbols[0].sy == ident)
        {
            //登记函数名称
            strcpy_s(func_name, symbols[0].id);
            insymbol(symbols[0]);
        }
        else
            error("检测到非法的函数名");
    }
    
    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 (");

    if (strcmp(func_name, "") 
        && getIndexByNameAndParent(string_global, func_name, declare_mode) == -1)
    {
        //登记函数名称和返回值
        if (t == TABLE_SIZE - 1)
        {
            //fatal,符号表容量不够，退出
            fatal("符号表容量不够");
        }
        t += 1;

        strcpy_s(tab[t].name, func_name);
        tab[t].obj = func;
        tab[t].typ = notyp;
        strcpy_s(tab[t].parent, string_global);
        tab[t].ref = 0;//初始化参数个数，读参数表时计数

        append_midcode("func_def", nullptr, "void", func_name);
    }

    parameter_list(func_name);//可能为空，故不必判断开始符号集

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    if (symbols[0].sy == lbrack)
        insymbol(symbols[0]);
    else
        error("缺少 {");

    bool has_return=false;
    compound_statement(func_name, has_return);
    if (has_return == false)
        append_midcode("ret");

    

    if (symbols[0].sy == rbrack)
        insymbol(symbols[0]);
    else
        error("缺少 }");

    programma_info << "这是一个“无返回值函数声明”" << endl;
}
void NaiveCompiler::void_main()
{
    dx = 0;
    if (end == 1)
    {
        symbols[0].clear();
        symbols[1].clear();
        end = 0;
        append_midcode("func_def", nullptr, "void", string_main);
        insymbol(symbols[0]);
    }
    else
    {
        insymbol(symbols[0]);
        if (symbols[0].sy == mainsy)
        {
            append_midcode("func_def", nullptr, "void", string_main);
            insymbol(symbols[0]);
        }
        else
            error("缺少 main");
    }

    //登记函数名称和返回值
    if (t == TABLE_SIZE - 1)
    {
        //fatal,符号表容量不够，退出
        fatal("符号表容量不够");
    }
    t += 1;

    strcpy_s(tab[t].name, string_main);
    tab[t].obj = func;
    tab[t].typ = notyp;
    strcpy_s(tab[t].parent, string_global);
    tab[t].ref = 0;

    if (symbols[0].sy == lparent)
        insymbol(symbols[0]);
    else
        error("缺少 (");

    if (symbols[0].sy == rparent)
        insymbol(symbols[0]);
    else
        error("缺少 )");

    if (symbols[0].sy == lbrack)
        insymbol(symbols[0]);
    else
        error("缺少 {");

    bool has_return=false;
    compound_statement(string_main, has_return);
    append_midcode("fkd_program_end");

    if (symbols[0].sy == rbrack)
    {
        //程序到此为止了，编译结束了
    }
    else
        error("缺少 }");

    programma_info << "这是一个“主函数”" << endl;
}
//以下为mips代码的生成函数，每条指令一个生成函数
void NaiveCompiler::add(char* rd, char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "add");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::addi(char* rt, char* rs, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "addi");
        strcpy_s(mips[mips_counter].rs, rs);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << rs << " " << imm << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_and(char* rd, char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "and");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::andi(char* rt, char* rs, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "andi");
        strcpy_s(mips[mips_counter].rs, rs);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << rs << " " << imm << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_beq(char* rs, char* rt, char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "beq");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].target, label);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << " " << label << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_bge(char* rs, char* rt, char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "bge");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].target, label);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << " " << label << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_bgt(char* rs, char* rt, char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "bgt");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].target, label);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << " " << label << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_ble(char* rs, char* rt, char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "ble");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].target, label);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << " " << label << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_blt(char* rs, char* rt, char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "blt");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].target, label);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << " " << label << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_bne(char* rs, char* rt, char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "bne");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].target, label);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << " " << label << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::div(char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "div");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::generate_label(char* label)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, label);
        mipsfile << mips[mips_counter].op << ":" << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_j(char* target)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "j");
        strcpy_s(mips[mips_counter].target, target);
        mipsfile << mips[mips_counter].op << " " << target << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::jal(char* target)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "jal");
        strcpy_s(mips[mips_counter].target, target);
        mipsfile << mips[mips_counter].op << " " << target << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::jr(int target_register)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "jr");
        mips[mips_counter].target[0] = '$';
        _itoa_s(target_register, &mips[mips_counter].target[1], ALNG-2, 10);
        mipsfile << mips[mips_counter].op << " " << mips[mips_counter].target << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::lui(char* rt, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "lui");
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << imm << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::lw(char* rt, char* rs, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "lw");
        strcpy_s(mips[mips_counter].rs, rs);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << imm << "(" << rs << ")" << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::mflo(char* rd)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "mflo");
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::mult(char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "mult");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_nor(char* rd, char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "nor");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::_or(char* rd, char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "or");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::ori(char* rt, char* rs, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "ori");
        strcpy_s(mips[mips_counter].rs, rs);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << rs << " " << imm << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::sll(char* rd, char* rt, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "sll");
        strcpy_s(mips[mips_counter].rd, rd);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rt << " " << imm << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::slt(char* rd, char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "slt");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::sub(char* rd, char* rs, char* rt)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "sub");
        strcpy_s(mips[mips_counter].rs, rs);
        strcpy_s(mips[mips_counter].rt, rt);
        strcpy_s(mips[mips_counter].rd, rd);
        mipsfile << mips[mips_counter].op << " " << rd << " " << rs << " " << rt << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::subi(char* rt, char* rs, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "subi");
        strcpy_s(mips[mips_counter].rs, rs);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << rs << " " << imm << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::sw(char* rt, char* rs, int imm)
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "sw");
        strcpy_s(mips[mips_counter].rs, rs);
        _itoa_s(imm, mips[mips_counter].imm, 10);
        strcpy_s(mips[mips_counter].rt, rt);
        mipsfile << mips[mips_counter].op << " " << rt << " " << imm << "(" << rs << ")" << endl;
    }
    else
        error("mips代码数组容量不足");
}
void NaiveCompiler::syscall()
{
    if (mips_counter < MIPS_CODE_SIZE - 1)
    {
        mips_counter += 1;
        strcpy_s(mips[mips_counter].op, "syscall");
        mipsfile << mips[mips_counter].op << endl;
    }
    else
        error("mips代码数组容量不足");
}

