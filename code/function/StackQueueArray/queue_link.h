//
// Created by lqs on 2022/9/13.
//

#include <cstdlib>

#ifndef DATA_STRUCTURE_QUEUE_LINK_H
#define DATA_STRUCTURE_QUEUE_LINK_H

#endif //DATA_STRUCTURE_QUEUE_LINK_H

//TODO 链式队列的实现

/*
 * TODO 链式队列
 *  存储实现方式；
 *      链式存储结构
 *      区分：
 *          带头结点与不带头结点
 *  基本操作：
 *      创（初始化）、增（入队）、删（出队）、查（获取对头元素）、判空、判满（进行增/删/查操作前的必要判断）
 *
 */

//TODO 队列的链式实现
typedef struct LinkNode{    //链式队列节点
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct {    //链式队列
    LinkNode *front,*rear;  //队列的队头和队尾指针
} LinkQueue;

//TODO 初始化（带头结点）
void InitQueue(LinkQueue &q){
    //TODO 初始化时front、rear都指向头节点
    q.front=q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    q.front->next= nullptr;
}

//TODO 入队，带头结点
void EnQueue(LinkQueue &q,int x){
    auto *s=(LinkNode *) malloc(sizeof(LinkNode));
    s->data=x;
    s->next= nullptr;
    q.rear->next=s; //新节点插入到rear之后
    q.rear=s;   //修改表尾指针，重新指向队尾
}

//TODO 出队，带头结点
bool DeQueue(LinkQueue &q,int &value){
    if(q.front==q.rear)
        return false;   //空链队
    LinkNode *p=q.front->next;
    value=p->data;  //用变量value返回队头元素
    q.front->next=p->next;  //修改头结点的next指针
    if(q.rear==p)
        q.rear=q.front; //修改rear指针
    free(p);
    return true;
}

//TODO 判断队列是否为空(带头结点）
bool IsEmpty(LinkQueue q){
    if(q.front==q.rear)
        return true;
    else
        return false;
}




//TODO 初始化队列，不带头结点
void InitNotHeadQueue(LinkQueue &q){
    //初始化时，front、rear都指向null
    q.front=q.rear= nullptr;
}

//TODO 入队，不带头结点
void EnNotHeatQueue(LinkQueue &q,int x){
    auto *s=(LinkNode *) malloc(sizeof(LinkNode));
    s->data=x;
    s->next= nullptr;
    if(q.front== nullptr){  //在空队列中插入第一个元素
        q.front=s;  //修改队头队尾指针
        q.rear=s;
        //TODO 注意：不带头结点的队列，第一个元素入队时需要特别处理
    } else{
        q.rear->next=s; //新节点插入到rear节点之后
        q.rear=s;   //修改rear指针
    }
}

//TODO 出队，不带头结点
bool DeNotHeadQueue(LinkQueue &q,int &value){
    if(q.front== nullptr)
        return false;
    LinkNode *p=q.front;    //p指向此次出队的节点
    value=p->data;
    q.front=p->next;    //修改front指针
    if(q.rear==p){  //此次是最后一个节点出队
        q.front= nullptr;
        q.rear= nullptr;
    }
    free(p);
    return true;
}

//TODO 判断队列是否为空，不带头结点
bool isEmptyToNotHead(LinkQueue q){
    if(q.front== nullptr)
        return true;
    else
        return false;
}

