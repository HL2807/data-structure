//
// Created by lqs on 2022/9/8.
//

#ifndef DATA_STRUCTURE_STATIC_LINKED_LIST_FUNCTION_H
#define DATA_STRUCTURE_STATIC_LINKED_LIST_FUNCTION_H

#endif //DATA_STRUCTURE_STATIC_LINKED_LIST_FUNCTION_H

/*
 * TODO 什么是静态链表
 *  单链表：
 *      各个节点在内存中星罗棋布、散落天涯
 *  静态链表；
 *      分片一整片连续的内存空间，各个节点集中安置
 *      静态链表相当于定义了一个长度为n的Node型数组
 *
 *  TODO 用代码定义一个静态链表
 *
 *  TODO 查找
 *      从头结点出发，挨个向后遍历节点
 *
 *  TODO 插入
 *      插入下标为i的结点的方法：
 *          a、找到一个空的结点，存入数据元素
 *          b、从头结点出发找到位序为i-1的结点
 *          c、修改新节点的next
 *          d、修改i-1号结点的next
 *
 *  TODO 删除某个节点：
 *      a、从头结点出发找到前驱节点
 *      b、修改前驱结点的游标
 *      c、被删除的结点的next设置为-2表示已经删除
 *
 *  TODO 总结：
 *      静态链表：
 *          用数组的方式实现的链表
 *          优点：
 *              增、删操作不需要移动大量的元素
 *          缺点：
 *              a、不能随机存取，只能从头结点开始依次往后查找
 *              b、容量固定不可变
 *      适用场景；
 *          a、不支持指针的低级语言
 *          b、数据元素数量固定不变的场景
 *              例如：操作系统的文件分配表FAT
 */
#define MaxSize 10 //静态链表的最大长度
typedef struct {//静态链表结构类型定义
    int data;//存储数据元素
    int next;//下一个元素的数组下标
}SLinkList[MaxSize];
//TODO 第二种定义方式
struct Node{
    int data;
    int next;
};
typedef struct Node SLinkList2[MaxSize];

/**
 * TODO 初始化静态链表
 *  把a[0]的next初始化为-1，其他节点的next初始化为一个特殊的值来表示结点空闲，这里初始化为-2，其它也可以
 * @param SL 需要初始化的静态链表
 * @return 初始化成功返回true，否则返回false
 */
bool InitStaticLinkedList(Node SL[]){
    if(SL[0].next==-1)
        return false;
    SL[0].next=-1;
    int i=1;
    for (;i<MaxSize;i++ ) {
        SL[i].next=-2;
    }
    return true;
}