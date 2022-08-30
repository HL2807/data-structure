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
 *      5、表中元素具有抽象性，即仅讨论元素建的逻辑关系，而不考虑元素究竟是表示什么内容
 *      注意：
 *          线性表是一种逻辑结构，表示元素之间一对一的相邻关系，顺序表和链表是指存储结构，两者属于不同层面的概念
 */

#include <cstdio>
#include <cstdlib>

#ifndef DATA_STRUCTURE_LINEAR_TABLE_POINTER_FUNCTION_H
#define DATA_STRUCTURE_LINEAR_TABLE_POINTER_FUNCTION_H

#endif //DATA_STRUCTURE_LINEAR_TABLE_POINTER_FUNCTION_H

//TODO 顺序表所有操作函数定义
#define InitSize 12
typedef struct {
    int *data;//指示动态分配数组的指针
    int MaxSizePointer;//顺序表的最大容量
    int length;//顺序表的当前容量
} SeqList;

/**
 * 动态分配数组，通过指针的方式
 * @param L
 */
void InitListP(SeqList &L) {
    //TODO 用malloc函数来动态申请一片连续的存储空间
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSizePointer = InitSize;
    //赋值
    for (int i = 0; i < L.MaxSizePointer; ++i) {
        L.data[i]=666;
    }
    L.length=sizeof(L.data);
}

/**
 * 动态增加数组的长度
 * @param L 结构体引用参数
 * @param len 需要增加的长度
 */
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSizePointer + len) * sizeof(int));
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];//将数据复制到新区域
    }
    L.MaxSizePointer = L.MaxSizePointer + len;//顺序表最大长度增加len
    free(p);//释放原来的内存空间
}

/*
 * 线性表的顺序存储结构，也叫顺序表
 *      特点：
 *          表中元素的逻辑与其物理顺序相同
 */
void allOperationsInTheSequenceTableP() {
    //TODO 初始化表，构造一个空的线性表
    SeqList LP;//声明一个顺序表
    InitListP(LP);
    IncreaseSize(LP,2);
    for (int i = 0; i < LP.MaxSizePointer; ++i) {
        printf("LP.data[%d]=%d\n",i,LP.data[i]);
    }
}



