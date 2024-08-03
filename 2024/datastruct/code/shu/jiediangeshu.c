#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ����������ڵ�����
int CountNodes(BiTree T) {
    if (T == NULL) {
        return 0; // �����Ϊ�գ���ڵ�����Ϊ0
    } else {
        // �ڵ�����Ϊ���ڵ��ֵ�����������Ľڵ��������������Ľڵ�����֮��
        return 1 + CountNodes(T->lchild) + CountNodes(T->rchild);
    }
}

int main() {
    // ����һ��ʾ��������
    BiTree T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = 'A';
    T->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    T->lchild->data = 'B';
    T->lchild->lchild = NULL;
    T->lchild->rchild = NULL;
    T->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    T->rchild->data = 'C';
    T->rchild->lchild = NULL;
    T->rchild->rchild = NULL;

    // ����������ڵ�������������
    printf("�������ڵ�����Ϊ��%d\n", CountNodes(T));

    // �ͷŶ��������ڴ�
    free(T->lchild);
    free(T->rchild);
    free(T);

    return 0;
}
