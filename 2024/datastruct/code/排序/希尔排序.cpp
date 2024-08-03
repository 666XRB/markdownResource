#include <stdio.h>

#define MAXSIZE 100

// ����˳�������
typedef struct {
    int r[MAXSIZE + 1]; // r[0] ��Ϊ�ݴ浥Ԫ���ڱ�
    int length;
} SqList;

// һ������Ϊdk�Ĳ�������
void ShellInsert(SqList &L, int dk) {
    int i, j;
    for (i = dk + 1; i <= L.length; ++i) {
        if (L.r[i] < L.r[i - dk]) {
            L.r[0] = L.r[i]; // �ݴ������Ԫ��
            for (j = i - dk; j > 0 && L.r[0] < L.r[j]; j -= dk) {
                L.r[j + dk] = L.r[j];
            }
            L.r[j + dk] = L.r[0];
        }
    }
}

// ����������dlta[0..t-1]��˳���L��ϣ������
void ShellSort(SqList &L, int dlta[], int t) {
    for (int k = 0; k < t; ++k) {
        ShellInsert(L, dlta[k]); // һ������Ϊdlta[k]�Ĳ�������
    }
}

// ��ӡ˳�����
void printList(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i]);
    }
    printf("\n");
}

// �����������Դ���
int main() {
    // ���岢��ʼ��˳���
    SqList L = {{0, 22, 5, 11, 17, 8, 14, 3, 9, 6}, 9};
    // ������������
    int dlta[] = {5, 3, 1};
    int t = sizeof(dlta) / sizeof(dlta[0]);

    printf("����ǰ����: \n");
    printList(L);

    // ����ϣ�������㷨
    ShellSort(L, dlta, t);

    printf("���������: \n");
    printList(L);

    return 0;
}
