#include <cstdio>
#include "code/function/linear_table_function.h"
#include "code/function/linear_table_pointer_function.h"


int max(int x,int y)
{
    int t;
    t=x>y?x:y;
    return t;
}

int main() {
    system("chcp 65001");//解决控制台乱码问题
    printf("************普通类型操作************\n");
    //TODO 线性表的顺序表相关操作
    //allOperationsInTheSequenceTable();
    //TODO 线性表的链表相关操作
    allOperationsInTheSingleList();
    //printf("************指针类型操作************\n");
    //allOperationsInTheSequenceTableP();//指针类型的操作
    return 0;
}
