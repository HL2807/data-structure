//
// Created by lqs on 2022/9/12.
//

#ifndef DATA_STRUCTURE_SEQUENTIAL_STACK_H
#define DATA_STRUCTURE_SEQUENTIAL_STACK_H

#endif //DATA_STRUCTURE_SEQUENTIAL_STACK_H

/*
 * TODO 顺序栈的实现
 *  定义：
 *      用顺序存储结构实现的栈
 *  基本操作：
 *      创（初始化）、增（进栈）、删（出栈）、查（获取栈顶元素）、判空、判满
 */

//TODO 顺序栈的定义
#define MaxSize 10
typedef struct{
    int data[MaxSize];  //静态数组存放栈中元素
    int top;    //栈顶指针
}SqStack;

//TODO 进栈操作
/**
 * 新元素进栈
 * @param S 被操作的栈
 * @param x 需要进入栈的元素
 * @return 进栈成功返回true，否则返回false
 */
bool Push(SqStack &S,int x){
    if(S.top==MaxSize-1)    //栈满，进栈失败
        return false;
    //S.top=S.top+1;    //指针先加
    S.data[++S.top]=x;//新元素入栈
    return true;
}


//TODO 出栈操作
/**
 * 对顺序栈进行出栈操作
 * @param S 被操作的顺序栈
 * @param value 出栈的值
 * @return 出栈成功返回true，否则返回false
 */
bool Pop(SqStack &S,int &value){
    if(S.top==-1)   //栈空，出栈失败
        return false;
    //value=S.data[S.top];    //栈顶元素先出栈
    //S.top=S.top-1;  //指针再减1
    value=S.data[S.top--];  //先出后减
    return true;
}

//TODO 读取栈顶元素
bool GetTop(SqStack S,int value){
    if(S.top==-1)
        return false;
    value=S.data[S.top];    //value记录栈顶元素
    return true;
}

//TODO 共享栈
typedef struct {
    int data[MaxSize];
    int top0;   //0号栈栈顶指针
    int top1;   //1号栈栈顶指针
}ShStack;

//TODO 初始化栈
void InitStack(ShStack &S){
    S.top0=-1;
    S.top1=MaxSize;
}

//TODO 判断栈是否是满栈
bool InitStack(ShStack S){
    if(++S.top0==S.top1)    //栈满返回true
        return true;
    else
        return false;   //栈空返回false
}