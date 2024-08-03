#include <stdio.h>

#define MAXSIZE 20 // ���¼������20��

typedef int KeyType; // ��ؼ���Ϊ������(int��)

typedef struct { // ����ÿ����¼(����Ԫ��)�Ľṹ
    KeyType key; // �ؼ���
    // ������������������������
} RedType; // ��¼����

typedef struct { // ����˳���Ľṹ
    RedType r[MAXSIZE + 1]; // �洢˳�������飬r[0]һ�����ڱ��򻺳���
    int length; // ˳���ĳ���
} SqList; // ˳�������

// ֱ�Ӳ��������㷨
void InsertSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) { // �ӵڶ���Ԫ�ؿ�ʼ����
        if (L->r[i].key < L->r[i - 1].key) { // ��Ҫ�����Ԫ�ر�ǰһ��Ԫ��С
            L->r[0] = L->r[i]; // �����ڱ�
            for (j = i - 1; L->r[0].key < L->r[j].key; j--) { // ���Ҳ���λ��
                L->r[j + 1] = L->r[j]; // Ԫ�غ���
            }
            L->r[j + 1] = L->r[0]; // ���뵽��ȷλ��
        }
    }
}

void PrintList(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key);
    }
    printf("\n");
}

int main() {
    SqList L = {
        .r = {{0}, {5}, {3}, {8}, {6}, {2}, {7}, {4}, {1}, {0}},
        .length = 9
    };

    printf("����ǰ:\n");
    PrintList(L);

    InsertSort(&L);

    printf("�����:\n");
    PrintList(L);

    return 0;
}
