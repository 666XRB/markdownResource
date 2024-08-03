#include <stdio.h>
#include <stdlib.h>
#include <iostream>
typedef int elemtype;

// 定义顺序表的结构
typedef struct {
    elemtype *elem; // 动态分配的数组
    int length;     // 顺序表的当前长度
} SqList;

// 初始化顺序表
void initList(SqList &L, int size) {
    L.elem = (elemtype*)malloc(size * sizeof(elemtype));
    L.length = 0;
}

// 插入一个值为 x 的节点，使表中各节点值仍然非递减
void insert(SqList &L, elemtype x) {

    int i=0;
    while (i<L.length&&L.elem[i]<x)
    {
        i++;
    }


    for(int j=L.length;j>=i+1;j--)
    {
        L.elem[j]=L.elem[j-1];
    };

    L.elem[i]=x;
    L.length++;
    
}

// 打印顺序表
void printList(const SqList &L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main() {
    // 初始化顺序表
    SqList L;
    initList(L, 10);
    
    // 插入一些元素
    insert(L, 1);
    insert(L, 3);
    insert(L, 5);
    insert(L, 7);
    
    // 打印顺序表
    printf("List before insertion: ");
    printList(L);
    
    // 插入新元素
    insert(L, 4);
    
    // 打印顺序表
    printf("List after insertion: ");
    printList(L);
    
    // 释放动态分配的内存
    free(L.elem);
    
    return 0;
}
