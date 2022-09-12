//
// Created by lqs on 2022/9/12.
//TODO 链栈
//

#include <cstdlib>

#ifndef DATA_STRUCTURE_CHAIN_STACK_H
#define DATA_STRUCTURE_CHAIN_STACK_H

#endif //DATA_STRUCTURE_CHAIN_STACK_H

/*
 * TODO 链栈的实现
 *  定义：
 *      用链式存储结构实现的栈
 *  基本操作：
 *      创（初始化）、增（进栈）、删（出栈）、查（获取栈顶元素）、判空、判满
 */

//TODO 栈的定义
typedef struct LinkNode{
    int data;
    struct LinkNode *next;  //指针域
}*LiStack;  //栈类型定义

//TODO 初始链栈,带头结点
bool InitLiStack(LiStack &LS){
    LinkNode *s;
    s=(LinkNode *)malloc(sizeof(LinkNode));
    if(s== nullptr)
        return false;
    s->next= nullptr;
    LS=s;
    return true;
}

//TODO 初始化栈，不带头结点
bool InitLiStackNotHead(LiStack &LS){
    LS= nullptr;
    return true;
}

//TODO 增（进栈）
//TODO 实际是在LS节点后插入元素e
/**
 * 进栈操作，实际上就是在LS节点后插入元素e
 * @param p 需要被在后面被插入的节点
 * @param e 插入的值
 * @return 插入成功返回true，否则返回false
 */
bool InsertNextLiStack(LiStack &p,int e){
    if(p== nullptr)
        return false;
    LinkNode *s=(LinkNode *) malloc(sizeof(LinkNode));
    if(s== nullptr)
        return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//TODO 删（出栈）
//TODO 出栈其实就是链表的删除过程
bool PopNextLiStack(LiStack &p,int value){
    if(p== nullptr)
        return false;
    LinkNode *q=p->next;
    value=q->data;
    p->data=p->next->data;
    p->next=q->next;
    free(q);
    return true;
}

//TODO 查（获取栈顶元素）
bool GetTop(LiStack LS,int value){
    if(LS== nullptr)
        return false;
    value=LS->data;
    return true;
}
//TODO 判空
//TODO 判满