// ��֪���������ö�������洢������ṹ�������£�
//  Typedef struct TreeNode{ 
//  ElmType data��
//  struct TreeNode *lchild��*rchild��
//  }*BiTree��
// ������㷨 Void CountNodes(BiTree t)�ֱ������������Ҷ��㡢��Ϊ 1�Ľ�㡢��
// Ϊ 2 �Ľ��ĸ�����(ע��Ҫ���ʵ���ע�ͣ�)
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *BiTree;

// �����������ݹ����������Ľڵ����
void CountNodesHelper(BiTree t, int *leafCount, int *degree1Count, int *degree2Count) {
    if (t == NULL) {
        return;
    }
    
    // Ҷ���
    if (t->lchild == NULL && t->rchild == NULL) {
        (*leafCount)++;
    }
    // ��Ϊ 2 �Ľ��
    else if (t->lchild != NULL && t->rchild != NULL) {
        (*degree2Count)++;
    }
    // ��Ϊ 1 �Ľ��
    else {
        (*degree1Count)++;
    }
    
    // �ݹ������������
    CountNodesHelper(t->lchild, leafCount, degree1Count, degree2Count);
    CountNodesHelper(t->rchild, leafCount, degree1Count, degree2Count);
}

// �����������Ҷ��㡢��Ϊ 1 �Ľ�㡢��Ϊ 2 �Ľ��ĸ���
void CountNodes(BiTree t, int *leafCount, int *degree1Count, int *degree2Count) {
    *leafCount = 0;
    *degree1Count = 0;
    *degree2Count = 0;
    CountNodesHelper(t, leafCount, degree1Count, degree2Count);
}

// ����һ���µĶ������ڵ�
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// ����ʾ��������
BiTree createSampleTree() {
    TreeNode* root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->rchild = createNode(6);
    return root;
}

int main() {
    // ����ʾ��������
    BiTree root = createSampleTree();
    
    // �������ڴ洢Ҷ��㡢��Ϊ 1 �Ľ�㡢��Ϊ 2 �Ľ��ĸ���
    int leafCount, degree1Count, degree2Count;
    
    // ����ڵ����
    CountNodes(root, &leafCount, &degree1Count, &degree2Count);
    
    // ��ӡ���
    printf("��Ϊ 0 nodes: %d\n", leafCount);
    printf("��Ϊ 1 nodes: %d\n", degree1Count);
    printf("��Ϊ 2 nodes: %d\n", degree2Count);
    
    return 0;
}
