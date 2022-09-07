//
// Created by lqs on 2022/9/7.
// 循环链表
//


#include <cstdlib>

#ifndef DATA_STRUCTURE_CIRCULAR_LINKED_LIST_H
#define DATA_STRUCTURE_CIRCULAR_LINKED_LIST_H

#endif //DATA_STRUCTURE_CIRCULAR_LINKED_LIST_H

//TODO 循环单链表
//TODO 单链表：表尾节点的next指针指向null
//TODO 循环单链表：表尾节点的next指针指向头结点
//TODO 特点：
//TODO 单链表：从一个节点出发只能找到后继的各个节点
//TODO 循环单链表：从一个节点出发可以找到其他任何一个节点
/*
 * 定义单链表节点类型
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 初始化一个循环单链表
 * @param L 需要初始化的链表
 * @return 初始化成功返回true，否则返回false
 */
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));//分配一个头结点
    if (L == nullptr)//内存不足，分配失败
        return false;
    L->next = L;//头节点next指向头结点
    return true;
}

/**
 * 判断节点p是否为循环单链表的表尾节点
 * @param L 链表
 * @param p 节点
 * @return 节点p是循环链表的表尾节点则返回true，否则返回false
 */
bool isTail(LinkList L, LNode *p) {
    if (p->next == L)
        return true;
    return false;
}

//TODO 循环双链表
//TODO 双链表：表头节点的prior指向null，表尾节点的next指向null
//TODO 循环双链表：表头节点的prior指向表尾节点，表尾节点的next指向头节点

//TODO 循环双链表的初始化
/*
 * 定义一个双链表的结构体
 */
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 初始化一个循环双链表
 * @param L 需要初始化的双链表
 * @return 初始化成功返回true，否则返回false
 */
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if(L== nullptr)
        return false;//内存不足，分配失败
    L->prior=L;//头节点prior指向头结点
    L->next=L;//尾节点next指向头结点
    return true;
}

/**
 * 判断循环双链表是否为空
 * @param L 需要判断的链表
 * @return 为空返回true，否则返回false
 */
bool Empty(DLinkList L){
    if(L->next==L)
        return true;
    return false;
}

/**
 * 判断p节点是否为循环双链表的表尾节点
 * @param L 双链表
 * @param p 被判断的节点
 * @return p节点是循环双链表的尾结点则返回true，否则返回false
 */
bool isTail(DLinkList L,DNode *p){
    if(p->next==L)
        return true;
    return false;
}

/**
 * 在p节点之后插入s节点
 * @param p 节点p
 * @param s 节点s
 * @return 插入成功返回true，否则返回false
 */
bool InsertNextNode(DNode *p,DNode *s){
    if(p->next== nullptr)//不是循环双链表，插入失败
        return false;
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}