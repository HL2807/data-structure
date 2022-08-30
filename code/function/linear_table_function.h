//
// Created by lqs on 2022/8/13.
//线性表相关代码实现
//
/*
 * 线性表的特点：
 *      1、表中元素的个数是有限个
 *      2、表中元素具有逻辑上的顺序性，表中元素有其先后次序
 *      3、表中元素都是数据元素，每个元素都是单个元素
 *      4、表中元素的数据类型都相同，即每个元素占有相同大小的存储空间
 *      5、表中元素具有抽象性，即仅讨论元素间的逻辑关系，而不考虑元素究竟是表示什么内容
 *      注意：
 *          线性表是一种逻辑结构，表示元素之间一对一的相邻关系，顺序表和链表是指存储结构，两者属于不同层面的概念
 */

#include <cstdio>
#include <cstdlib>

#ifndef DATA_STRUCTURE_LINEAR_TABLE_FUNCTION_H
#define DATA_STRUCTURE_LINEAR_TABLE_FUNCTION_H

#endif //DATA_STRUCTURE_LINEAR_TABLE_FUNCTION_H

//TODO 普通定义一个结构体
typedef struct {
    int num;//号数
    int people;//人数
} Customer;

//TODO 定义一个数组结构的结构体来存储数据
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//TODO 顺序表所有操作函数定义
/**
 * 初始化顺序表
 * @param L 结构体引用参数，C语言用*
 */
void InitList(SqList &L) {
    for (int &i: L.data)
        i = 0;
    L.length = 1;
}

/**
 * 在顺序表中指定位置插入指定的值，并返回是否插入成功
 * @param L 需要操作的顺序表
 * @param move 需要插入的位置
 * @param insertValue 需要插入的值
 * @return TRUE代表插入成功，否则插入失败
 */
bool ListInsert(SqList &L, int move, int insertValue) {
    if (move < 1 || move > L.length + 1) {  //判断move的范围是否有效
        return false;
    } else if (L.length >= MaxSize) {    //当前的存储空间已经满了
        return false;
    } else {
        for (int i = L.length; i >= move; i--) {//将第i个元素及之后的元素后移
            L.data[i] = L.data[i - 1];
        }
        L.data[move - 1] = insertValue;//在指定位置插上指定的值
        L.length++;//顺序表的长度要+1
        return true;
    }
}

/**
 * 删除指定索引位置的值，并将索引对应的值赋值给deletedValue
 * @param L 需要操作的顺序表
 * @param deleteMove 需要删除的索引
 * @param deletedValue 被删除索引下标对应的值
 * @return 删除是否成功，成功则返回true
 */
bool ListDelete(SqList &L, int deleteMove, int &deletedValue) {
    if (deleteMove < 1 || deleteMove > L.length + 1) {
        return false;
    } else if (L.length == 0) {
        return false;
    } else {
        deletedValue = L.data[deleteMove - 1];//将删除位置的值赋值给deletedValue
        for (int i = deleteMove; i < L.length; i++) {//将删除位置后的数据往前移动
            L.data[i - 1] = L.data[i];
        }
        L.length--;//长度-1
        return true;
    }
}

/**
 * 按照指定索引去顺序表中找值
 * @param L 需要查询的顺序表
 * @param index 索引
 * @return 查到直接返回索引对应的值，否则返回-1表示没有找到该索引
 */
int getValue(SqList L, int index) {
    if (L.length > 0 && index < L.length) {
        return L.data[index - 1];
    } else {
        return -1;
    }
}

/**
 * 按照值去顺序表中找到对应的索引
 * @param L 需要查找的顺序表
 * @param value 需要找对应value的顺序表索引
 * @return 找到返回对应的索引，否则返回-1代表查询失败
 */
int getValueToIndex(SqList L, int value) {
    for (int i = 0; i < L.length; ++i) {
        if (value == L.data[i]) {
            return i + 1;
        }
    }
    return -1;
}

void printfO(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("L.data[%d]=%d\n", 1 + i, L.data[i]);
    }
}

/*
 * 顺序表相关操作
 * 线性表的顺序存储结构，也叫顺序表
 *      特点：
 *          表中元素的逻辑与其物理顺序相同
 */
void allOperationsInTheSequenceTable() {

    //TODO 初始化表，构造一个空的顺序表
    SqList L;
    InitList(L);
    for (int i: L.data) {
        printf("%d\n", i);
    }
    ListInsert(L, 1, 666);

    //调用自己写的输出方法
    printfO(L);

    //int deletedValue;
    //if(ListDelete(L,1,deletedValue)){
    //    printf("索引%d被删除成功，被删除索引对应的值是:%d\n",1,deletedValue);
    //} else{
    //    printf("索引%d被删除失败\n",1);
    //}
    int result = getValue(L, 1);
    printf("%d\n", result);
    printf("您所查询的值在顺序表中的位置是：%d\n", getValueToIndex(L, 666));
    printfO(L);

}

/*
 * 定义一个单链表结构体
 */
typedef struct LNode {
    int data;//每个节点用于存放数据
    struct LNode *next;//指针指向下一个节点
} LNode, *LinkList;//强调是一个单链表，使用LinkList，强调是一个节点，使用LNode*

/*
 * 初始化一个空的单链表
 */
bool InitSingleList(LinkList &L) {
    L = nullptr;//空表，暂时还没有任何节点，这样是为了防止脏数据和指针异常
    return true;
}

/**
 * 判断不带头结点的单链表是否为空
 * @param L 单链表
 * @return 为空返回true
 */
bool isEmpty(LinkList L) {
    if (L == nullptr) {
        return true;
    } else {
        return false;
    }
}

/**
 * 初始化一个带头结点的单链表
 * @param L 需要初始化的单链表
 * @return 返回带头结点的单链表，但是头结点后面就没有节点
 */
bool IniSingleList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == nullptr)
        return false;
    L->next = nullptr;
    return true;
}

/**
 * 判断带头结点的单链表是否为空
 * @param L 带头结点单链表
 * @return 如果头结点的next为空，返回true，否则返回FALSE
 */
bool isEmptyToHeadSingleList(LinkList &L) {
    if (L->next == nullptr) {
        return true;
    } else
        return false;
}

/**
 * 头插法建立单链表
 * @param L 单链表
 * @return 返回建立号的单链表
 */
LinkList SingleListHeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));//创建头结点
    L->next = nullptr;//初始为空链表
    scanf("请输入一个整数:%d", &x);
    while (x != 9999) {//输入为9999代表输入结束
        s = (LNode *) malloc(sizeof(LNode));//创建新节点
        s->data = x;
        s->next = L->next;//TODO 注意:L->next=NULL的，即s->next=L->next=NULL
        L->next = s;
        scanf("请输入一个整数:%d", &x);
    }
    free(s);
    return L;
}

/**
 * 带头节点的单链表按序插入操作
 * @param L 需要操作的单链表
 * @param index 需要插入的位置
 * @param value 需要插入的值
 * @return 插入成功返回true，否则反回false
 */
bool SingleListHaveHeadNodeInsert(LinkList &L, int index, int value) {
    if (index < 1)
        return false;
    LNode *p;//指针p指向当前扫描到的节点
    int j = 0;//当前p指向的是第几的个节点
    p = L;//L指向头节点，头节点是第0个节点(不存数据)
    while (p != nullptr && j < index - 1) {//循环找到第index-1的个节点
        p = p->next;
        j++;
    }
    if (p == nullptr)//index的值不合法，用数组的思维来说就是“越界”了
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;//将节点s连接到p之后
    free(p);
    return true;
}

/**
 * 不带头节点的单链表按序插入操作
 * @param L 需要操作的单链表
 * @param index 需要插入的位置
 * @param value 需要插入的值
 * @return 插入成功返回true，否则返回false
 */
bool SingListNotHaveHeadNodeInsert(LinkList &L, int index, int value) {
    if (index < 1) {
        return false;
    } else if (index == 1) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = value;
        s->next = L;
        L = s;//TODO 头指针指向新的节点
    }
    LNode *p;//指针指向当前扫描到的节点
    int j = 1;//当前p指向的是第几个节点
    p = L;//p指向的是第一个节点，但不是头结点，这里
    while (p != nullptr && j < index - 1) {//循环找到第index-1个节点
        p = p->next;
        j++;
    }
    if (p == nullptr)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 指定节点后插操作
 * @param p 指定后插节点
 * @param value 需要插入的值
 * @return 插入成功返回true，否则返回false
 */
bool InsertNextNode(LNode *p,int value){
    if(p== nullptr)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=value;//用节点s保存元素value
    s->next=p->next;
    p->next=s;//将节点s连接到p之后
    return true;
}

/**
 * 指定节点前插操作
 * @param p 指定节点
 * @param value 插入的值
 * @return 插入成功返回true，否则返回false
 */
bool InsertPrecedingNode(LNode *p,int value){
    if(p== nullptr){
        return false;
    }
    LNode *s=(LNode *) malloc(sizeof(LNode));
    s->next=p->next;
    p->next=s;//新节点连接到p之后
    s->data=p->data;//将p中元素data复制到s中元素data中
    p->data=value;//p中元素覆盖为e
    return true;
}

/**
 * 带头节点的单链表按序删除
 * @param L 需要操作的链表
 * @param index 需要删除的索引
 * @param nodeValue 被删除节点的值
 * @return 删除成功返回true，否则返回false
 */
bool SingleListDeleteNode(LinkList &L,int index,int &nodeValue){
    if(index<1)
        return false;
    LNode *p;
    int j=0;
    p=L;
    while (p!= nullptr && j<index-1){
        p=p->next;
        j++;
    }
    if(p== nullptr)
        return false;
    if(p->next== nullptr)//第index-1个节点之后已无其他节点
        return false;
    LNode *q=p->next;//令q指向被删除节点
    nodeValue=q->data;//用nodeValue返回删除节点元素的值
    p->next=q->next;//将*q节点从链中“丢弃”
    free(q);//释放被删除节点的空间
    return true;//删除成功
}

/**
 * 删除指定节点p
 * @param p 要删除的节点
 * @return 删除成功返回true，否则返回false
 */
bool DeleteNode(LNode *p){
    if(p== nullptr)
        return false;
    LNode *q=p->next;//令q指向被删除节点
    p->data=p->next->data;//和后继节点交换数据域
    p->next=q->next;//将*q节点从链表中断开
    free(q);//释放后继节点的存储空间
    return true;
}

//TODO 单链表查找相关的操作
//TODO 按位查找

LNode * GetElem(LinkList L,int index){
    if(index<0)
        return nullptr;
    LNode *p;   //指针p指向当前扫描到的节点
    int j=0;
    p=L;
    while (p!= nullptr && j<index){
        p=p->next;
        j++;
    }

}

//TODO 按值查找

/**
 * 单链表相关操作
 */
void allOperationsInTheSingleList() {
    LinkList L;//声明一个指向单链表的指针
    //初始化一个空链表
    InitSingleList(L);
    SingleListHeadInsert(L);

}



