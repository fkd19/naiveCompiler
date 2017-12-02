#include "NaiveCompiler.h"

using namespace std;

/*
int main()
{

    return 0;
}*/


int main(int args, char* argv[])//main
{
    NaiveCompiler compiler;
    char sourcefile[ALNG];
    printf("请输入需要编译的文件名：\n");
    scanf("%s", &sourcefile);
    compiler.fin.open(sourcefile, ios_base::in);
    compiler.fout.open("result.txt", ios_base::out);
    //进入所有非终结符处理程序之前都要先读好一个symbol
    compiler.insymbol(compiler.symbols[0]);//预先读一个符号
    compiler.program();//处理 “程序”
    if (!compiler.errors.empty())
    {
        compiler.errormsg();
        compiler.fin.close();
        compiler.fout.close();
        return 0;
    }
    
    //compiler.midcode2mips();

    compiler.fin.close();
    compiler.fout.close();
    return 0;
}

// test insymbol



/*
int main()
{
    int k = 0;
    NaiveCompiler compiler;
    //compiler.fin.open("testInsymbol.c", ios_base::in);
    compiler.fin.open("15061188_test.txt", ios_base::in);
    compiler.fout.open("result.txt", ios_base::out);
    while (!compiler.fin.eof())
    {
        compiler.insymbol(compiler.symbols[0]);
        k++;
        switch(compiler.symbols[0].sy)
        {
        case casesy:    compiler.fout << k << " " << "case" << endl;    break;
        case charsy:    compiler.fout << k << " " << "char" << endl;    break;
        case constsy:   compiler.fout << k << " " << "const" << endl;   break;
        case dosy:      compiler.fout << k << " " << "do" << endl;      break;
        case ifsy:      compiler.fout << k << " " << "if" << endl;      break;
        case intsy:     compiler.fout << k << " " << "int" << endl;     break;
        case mainsy:    compiler.fout << k << " " << "main" << endl;    break;
        case returnsy:  compiler.fout << k << " " << "return" << endl;  break;
        case printfsy:  compiler.fout << k << " " << "printf" << endl;  break;
        case scanfsy:   compiler.fout << k << " " << "scanf" << endl;   break;
        case switchsy:  compiler.fout << k << " " << "switch" << endl;  break;
        case voidsy:    compiler.fout << k << " " << "void" << endl;    break;
        case whilesy:   compiler.fout << k << " " << "while" << endl;   break;
        case plussy:    compiler.fout << k << " " << "plus +" << endl;  break;
        case minussy:   compiler.fout << k << " " << "minus -" << endl; break;
        case multsy:    compiler.fout << k << " " << "mult *" << endl;  break;
        case divsy:     compiler.fout << k << " " << "div /" << endl;   break;
        case becomesy:  compiler.fout << k << " " << "become =" << endl;break;
        case comma:     compiler.fout << k << " " << "comma ," << endl; break;
        case semicomma: compiler.fout << k << " " << "semicomma ;" << endl; break;
        case colon:     compiler.fout << k << " " << "colon :" << endl; break;
        case beq:       compiler.fout << k << " " << "beq ==" << endl;  break;
        case bne:       compiler.fout << k << " " << "bne !=" << endl;  break;
        case bge:       compiler.fout << k << " " << "bge >=" << endl;  break;
        case bgt:       compiler.fout << k << " " << "bgt >" << endl;   break;
        case ble:       compiler.fout << k << " " << "ble <=" << endl;  break;
        case blt:       compiler.fout << k << " " << "blt <" << endl;   break;
        case charcon:compiler.fout << k << " " << "charcon " << compiler.symbols[0].chval << endl;break;
        case intcon:compiler.fout << k << " " << "intcon " << compiler.symbols[0].inum << endl;break;
        case stringcon:
            {
                compiler.fout << k << " " << "stringcon " << compiler.symbols[0].strval << endl;
                break;
            }
        case lparent:   compiler.fout << k << " " << "lparent (" << endl;   break;
        case rparent:   compiler.fout << k << " " << "rparent )" << endl;   break;
        case lsquare:   compiler.fout << k << " " << "lsquare [" << endl;   break;
        case rsquare:   compiler.fout << k << " " << "raquare ]" << endl;   break;
        case lbrack:    compiler.fout << k << " " << "lbrack {" << endl;    break;
        case rbrack:    compiler.fout << k << " " << "rbrack }" << endl;    break;
        case ident:     compiler.fout << k << " " << "identity " << compiler.symbols[0].id << endl;break;
        default:    compiler.fout << k << " " << "ERROR sy" << endl;break;
        }
        
    }
    compiler.fin.close();
    compiler.fout.close();
    return 0;
}*/