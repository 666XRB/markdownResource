#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ���ƶ�����
int Copy(BiTree T, BiTree *NewT) {
    if (T == NULL) { // ����ǿ�������0
        *NewT = NULL;
        return 0;
    } else {
        *NewT = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*NewT) {
            exit(EXIT_FAILURE);
        }
        (*NewT)->data = T->data;
        // ����������
        Copy(T->lchild, &(*NewT)->lchild);
        // ����������
        Copy(T->rchild, &(*NewT)->rchild);
    }
    return 0;
}

// ���ٶ�����
void DestroyBiTree(BiTree *T) {
    if (*T) {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

// �������������
void InOrderTraversal(BiTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        printf("%c ", T->data);
        InOrderTraversal(T->rchild);
    }
}

int main() {
    BiTree T = NULL;
    // ����һ��ʾ��������
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = 'A';
    T->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    T->lchild->data = 'B';
    T->lchild->lchild = NULL;
    T->lchild->rchild =(BiTNode *)malloc(sizeof(BiTNode));
    T->lchild->rchild->data = 'D'; // �� 'D' ��Ϊ 'B' ���Һ���
    
    T->lchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild = NULL;
    
    T->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    T->rchild->data = 'C';
    T->rchild->lchild = NULL;
    T->rchild->rchild = NULL;

    // ���ƶ�����
    BiTree NewT = NULL;
    Copy(T, &NewT);

    printf("ԭ������������������");
    InOrderTraversal(T);
    printf("\n");

    printf("���ƵĶ�����������������");
    InOrderTraversal(NewT);
    printf("\n");

    // ����ԭ�������ͷ��ڴ�
    DestroyBiTree(&T);

    // ���ٸ��ƵĶ������ͷ��ڴ�
    DestroyBiTree(&NewT);

    return 0;
}
