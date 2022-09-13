//
// Created by lqs on 2022/9/13.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#endif //DATA_STRUCTURE_QUEUE_H

/*
 * TODO 数据结构三要素：
 *      逻辑结构、数据的运算、存储结构（物理结构）
 *  对列的定义：
 *      线性表是具有相同数据的n(n>=0)个数据元素的有限队列，其中n为表长，当n=0时线性表是一个空表。若用L命名线性表
 *      ，则其一般表示为：
 *          L=(a1,a2,...,ai,ai+1,...,an)
 *      栈(Stack)：
 *          是只允许在一端进行插入/进栈或删除/出栈的线性表
 *          特点：
 *              先进后出
 *      队列(Queue)：
 *          是只允许在一端进行插入/入队，在另一端删除/出队的线性表
 *          特点；
 *              先进先出
 *          重要术语：
 *              对头、对尾、空队列
 *  队列的基本操作
 *      InitQueue(&Q)：初始化队列，构造一个空队列
 *      DestroyQueue(&Q)；销毁队列，销毁并释放队列Q所占用的内存空间
 *      EnQueue(&Q,x)：入队，若队列Q未满，将x加入，使之成为新的队尾
 *      DeQueue(&Q,&value)：出队，若队列Q非空，删除对头元素，并用value返回
 *      GetHead(Q,&value)：读取对头元素，若队列Q非空，则将对头元素赋值给value
 *      其他常用操作：
 *          QueueEmpty(Q)：判断队列是否为空，若队列为空，返回true，否则返回false
 *
 */

//TODO 队列的顺序实现
#define MaxSize 10  //定义队列中元素的最大个数
typedef struct {
    int data[MaxSize];  //用静态数组存放队列元素
    int front, rear; //对头指针和队尾指针
    //int size;   //用来统计当前队列的长度，判断队空或者队满。入队++，出队--
    int tag;   //用来统计当前元素节点是删除还是入队，判断队空或者队满。入队成功tag=1，出对成功tag=0-
} SqQueue;  //Sq<=>sequence

//TODO 初始化队列
void InitQueue(SqQueue &Q) {
    //初始化时，对头、队尾指针都指向0
    Q.front = Q.rear = 0;
}

//TODO 入队操作
/**
 * 队列的入队操作
 * @param Q 需要被入队的队列
 * @param x 入队1的值
 * @return 入队成功返回true，否则返回false
 */
bool EnQueue(SqQueue &Q, int x) {
    if (Q.rear == MaxSize - 1)//队列已满，则报错
        return false;
    //Q.data[Q.rear]=x;   //将x插入队尾
    //Q.rear=Q.rear+1;    //队尾指针后移
    Q.data[Q.rear++] = x;
    //变环状队列
    //Q.data[Q.rear] = x;   //将x插入队尾
    //Q.rear = (Q.rear + 1) % MaxSize;  //队尾指针加1取模
    //Q.size++;
    Q.tag=1;
    return true;
}

//TODO 判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//TODO 循环队列入队操作
/**
 * 循环队列入队操作
 * @param Q 被操作的循环队列
 * @param x 需要入队的值
 * @return 入队成功返回true，否则返回false
 */
bool EnCycleQueue(SqQueue &Q,int x){
    if((Q.rear+1)%MaxSize==Q.front)
        return false;   //队满了，不能继续入队，报错
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    //Q.size++;
    Q.tag=1;
    return true;
}

//TODO 循环队列出队操作
/**
 * 循环队列出队操作，即删除一个对头元素，并用value返回
 * @param Q 被操作的循环队列
 * @param value 出队列的值
 * @return 出队成功返回true，否则返回false
 */
bool DeCycleQueue(SqQueue &Q,int &value){
    if(Q.front==Q.rear)
        return false;
    value=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    //Q.size--;
    Q.tag=0;
    return true;
}

//TODO 循环队列判空操作
bool CycleQueueEmpty(SqQueue Q){
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}

bool CycleQueueEmptyTag(SqQueue Q){
    if(Q.front==Q.rear && Q.tag==0)
        return true;
    else
        return false;
}