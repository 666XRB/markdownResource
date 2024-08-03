#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct BiTNode {
    int data; // �ڵ�����
    struct BiTNode *lchild; // ���ӽڵ�
    struct BiTNode *rchild; // ���ӽڵ�
} BiTNode, *BiTree;

// �����������Ҷ�ӽڵ����Ŀ
int LeafCount_BiTree(BiTree T) {
    // �����Ϊ�գ���û��Ҷ�ӽڵ�
    if(!T)
    return 0;

    if(T->lchild==NULL && T->rchild==NULL)
    {
        return 1;
    }

    return LeafCount_BiTree(T->lchild)+LeafCount_BiTree(T->rchild);
}

// ����һ���µĶ������ڵ�
BiTNode* createNode(int data) {
    BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// ����ʾ��������
BiTree createSampleTree() {
    BiTree root = createNode(1);
    
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->rchild = createNode(6);
    return root;
}

int main() {
    // ����ʾ��������
    BiTree T = createSampleTree();
    
    // ���㲢��ӡҶ�ӽڵ����Ŀ
    int leafCount = LeafCount_BiTree(T);
    printf("Number of leaf nodes: %d\n", leafCount);
    
    return 0;
}
