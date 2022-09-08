//
// Created by lqs on 2022/9/6.
//

#include <cstdlib>

#ifndef DATA_STRUCTURE_DOUBLE_TABLE_FUNCTION_H
#define DATA_STRUCTURE_DOUBLE_TABLE_FUNCTION_H

#endif //DATA_STRUCTURE_DOUBLE_TABLE_FUNCTION_H

//TODO 双链表的初始化与判空

/**
* 定义一个双链表的结构体
*/
typedef struct DNode{
    int data;
    struct DNode *prior,*next;//TODO prior:表示前驱指针，next:表示后驱指针
}DNode,*DLinkList;

bool DeleteNextDNode(DNode *P);

/**
 * 初始化一个双链表（带头节点）
 * @param L 被初始化的双链表
 * @return 初始化成功返回true，失败返回false
 */
bool InitDLinkList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));//分配一个头节点
    if(L== nullptr)
        return false;//内存不足，新节点空间分配失败
    L->prior= nullptr;
    L->next= nullptr;
    return true;
}

/**
 * 判断双链表是否为空
 * @param L 需要判断的双链表
 * @return 为空返回true，否则返回false
 */
bool Empty(DLinkList L){
    if(L->prior== nullptr && L->next== nullptr)
        return true;
    else
        return false;
}

//TODO 双链表的插入

/**
 * 在p节点之后插入s节点
 * @param p p节点
 * @param s s节点
 * @return 插入成功返回true，否则返回false
 */
bool InsertNextNode(DNode *p,DNode *s){
    if(p== nullptr || s == nullptr)
        return false;
    s->next=p->next;//s的后驱节点指向p后驱节点
    if(p->next!= nullptr)//判断p节点不是最后一个节点
        p->next->prior=s;//TODO s的后一个节点的前驱指向s节点
    s->prior=p;//s的前驱节点指向p
    p->next=s;//p的后驱节点指向s
    return true;
}

//TODO 双链表的删除
/**
 * 双链表的删除
 * @param L 被删除的双链表
 */
void DestoryList(DLinkList &L){
    //循环释放各个数据节点
    while (L->next!= nullptr)
        DeleteNextDNode(L);
    //{
    //    if(L== nullptr)
    //        return;
    //    DNode *q=L->next;//找到p的后继节点q
    //    if(q== nullptr)
    //        return;
    //    L->next=q->next;
    //    if(q->next!= nullptr) //q节点不是最后一个节点
    //        q->next->prior= L;
    //    free(q);
    //    return;
    //}

    free(L);//释放头结点
    L= nullptr;//头指针指向null
}

bool DeleteNextDNode(DNode *p){
    if(p== nullptr)//如果当前节点为空，则直接返回false
        return false;
    DNode *q=p->next;//找到p的后继节点q
    if(q== nullptr)//当前节点下一个节点为空，也直接返回false
        return false;
    p->next=q->next;//当前节点下一个节点的值赋值给当前节点
    if(q->next!= nullptr)//当前节点的下一个节点指向不为空，则删除当前节点
        q->next->prior=p;
    free(q);
    return true;
}

//TODO 双链表的便利
/**
 * 双链表的便利
 * @param p 需要便利的双链表
 * @param state 状态码。1表示向前遍历，2表示向后遍历，3表示跳过头结点向前遍历
 */
void TraverseDLinkList(DLinkList p,int state){
    if(state==1){
        while (p!= nullptr)//向前遍历
            p=p->prior;
    } else if(state==2){
        while (p!= nullptr)//向后遍历
            p=p->next;
    } else if(state==3){
        while (p->prior!= nullptr)//跳过头结点，并向前遍历
            p=p->prior;
    }
}