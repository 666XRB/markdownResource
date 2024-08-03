#include <stdio.h>
#include <iostream>
// ����˳������󳤶�
#define MAXSIZE 100

// ����Ԫ������
typedef struct {
    int key;
} ElemType;

// ����˳�������
typedef struct {
    ElemType r[MAXSIZE + 1]; // ��һ���ڱ�λ��
    int length;
} SqList;

// �۰���������㷨
void BInsertSort(SqList &L) {
    int i, j, low, high, mid;
    ElemType temp;

    for (i = 2; i <= L.length; ++i) {
        L.r[0] = L.r[i]; // ��ǰ����Ԫ�ش浽���ڱ���λ��
        low = 1;
        high = i - 1;

        // ���ö��ֲ��ҷ����Ҳ���λ��
        while (low <= high) {
            mid = (low + high) / 2;
            if (L.r[0].key < L.r[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // ѭ��������high+1��Ϊ����λ��
        for (j = i - 1; j >= high + 1; --j) {
            L.r[j + 1] = L.r[j]; // �ƶ�Ԫ��
        }

        L.r[high + 1] = L.r[0]; // ���뵽��ȷλ��
    }
}

// ��ӡ˳�����
void printList(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key);
    }
    printf("\n");
}

// �����������Դ���
int main() {
    // ���岢��ʼ��˳���
    SqList L = {{{0}, {3}, {1}, {5}, {7}, {2}, {4}, {9}, {6}}, 8};
    
    printf("����ǰ����: \n");
    printList(L);

    // �����۰���������㷨
    BInsertSort(L);

    printf("���������: \n");
    printList(L);

    return 0;
}
