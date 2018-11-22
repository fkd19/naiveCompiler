#include "NaiveCompiler.h"

using namespace std;

int main(int args, char* argv[])//main
{
    NaiveCompiler compiler;
    char sourcefile[ALNG];
    printf("请输入需要编译的文件名：\n");
    scanf("%s", &sourcefile);
    compiler.fin.open(sourcefile, ios_base::in);
    if (!compiler.fin)
    {
        printf("需要编译的文件不存在\n");
        exit(0);
        return 0;
    }
    compiler.fout.open("result.txt", ios_base::out);
    //进入所有非终结符处理程序之前都要先读好一个symbol
    compiler.insymbol(compiler.symbols[0]);//预先读一个符号
    printf("开始生成中间代码……\n");
    compiler.program();//处理 “程序”
    if (!compiler.errors.empty())
    {
        //compiler.errormsg();
        printf("出现错误，具体错误信息请查看result.txt\n");
        compiler.fin.close();
        compiler.fout.close();
        exit(0);
        return 0;
    }

    printf("中间代码生成完毕\n");

    int mode = -1;
    printf("请输入编译选项：(1表示做优化且全局寄存器分配使用图着色法，2表示做优化且全局寄存器分配使用引用计数，其他数字表示不做优化)\n");
    scanf("%d", &mode);
    compiler.opt_sign = (mode == 1 || mode == 2);


    int delay;
    printf("请选择是否支持延迟槽？0表示忽略，其余数字表示不忽略：\n");
    scanf("%d", &delay);
    compiler.delay_mode = (delay != 0);
    int machineCodeEn;
    printf("请选择是否生成机器码？1表示mars模式，2表示计组cpu模式，3表示龙芯cpu模式，其余数字表示否：\n");
    scanf("%d", &machineCodeEn);

    if (mode == 1)
    {
        compiler.intcon2ints();
        printf("开始删除公共子表达式……\n");
        compiler.del_common_subexpression();
        compiler.del_common_expression();
        compiler.print_optimized_midcode("opt_midcode.txt");
        printf("公共子表达式删除完毕……\n");
        printf("开始进行活跃变量分析，建立冲突图并使用图着色算法分配全局寄存器……\n");
        compiler.activeVarAnalysis();
        printf("分配全局寄存器完毕……\n");
        compiler.midcode2mips();
    }
    else if (mode == 2)
    {
        compiler.intcon2ints();
        printf("开始删除公共子表达式……\n");
        compiler.del_common_subexpression();
        compiler.del_common_expression();
        compiler.print_optimized_midcode("opt_midcode.txt");
        printf("公共子表达式删除完毕……\n");
        printf("开始使用引用计数全局寄存器分配……\n");
        compiler.ref_count();
        printf("全局寄存器分配完毕……\n");
        compiler.midcode2mips();
    }
    else
    {
        cout << "进入不优化模式……" << endl;
        compiler.midcode2mips();
    }

    if (machineCodeEn == 1)
    {
        printf("开始生成机器码……\n");
        compiler.mips2machineCode(0x00400000);
        printf("生成机器码完毕……\n");
    }
    else if (machineCodeEn == 2)
    {
        printf("开始生成机器码……\n");
        compiler.mips2machineCode(0x00003000);
        printf("生成机器码完毕……\n");
    }
    else if (machineCodeEn == 2)
    {
        printf("开始生成机器码……\n");
        compiler.mips2machineCode(0xbfc00000);
        printf("生成机器码完毕……\n");
    }

    printf("编译完成！\n");

    compiler.fin.close();
    compiler.fout.close();
    return 0;
}

