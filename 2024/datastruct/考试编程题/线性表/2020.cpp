#include <stdio.h>
#include <stdlib.h>
#include <iostream>
typedef int elemtype;

// ����˳���Ľṹ
typedef struct {
    elemtype *elem; // ��̬���������
    int length;     // ˳���ĵ�ǰ����
} SqList;

// ��ʼ��˳���
void initList(SqList &L, int size) {
    L.elem = (elemtype*)malloc(size * sizeof(elemtype));
    L.length = 0;
}

// ����һ��ֵΪ x �Ľڵ㣬ʹ���и��ڵ�ֵ��Ȼ�ǵݼ�
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

// ��ӡ˳���
void printList(const SqList &L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main() {
    // ��ʼ��˳���
    SqList L;
    initList(L, 10);
    
    // ����һЩԪ��
    insert(L, 1);
    insert(L, 3);
    insert(L, 5);
    insert(L, 7);
    
    // ��ӡ˳���
    printf("List before insertion: ");
    printList(L);
    
    // ������Ԫ��
    insert(L, 4);
    
    // ��ӡ˳���
    printf("List after insertion: ");
    printList(L);
    
    // �ͷŶ�̬������ڴ�
    free(L.elem);
    
    return 0;
}
