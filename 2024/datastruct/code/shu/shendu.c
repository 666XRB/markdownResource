#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ��������������
int TreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    } else {
        // �ݹ���������������
        int leftDepth = TreeDepth(T->lchild);
        // �ݹ���������������
        int rightDepth = TreeDepth(T->rchild);
        // ��������������ȵĽϴ�ֵ���ϸ��ڵ����ȣ�1��
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
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

    // �������������Ȳ�������
    printf("�����������Ϊ��%d\n", TreeDepth(T));

    // �ͷŶ��������ڴ�
    free(T->lchild);
    free(T->rchild);
    free(T);

    return 0;
}
