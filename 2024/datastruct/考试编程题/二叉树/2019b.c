// 2����֪���������ö�������洢������ṹ�������£�
//  typedef struct TreeNode{ 
//  ElmType data��
//  struct TreeNode *lchild��*rchild��
//  }*BiTree��
// ���д�ݹ麯�� int SumNodes(BiTree T)�����ض����� T �Ľ������

#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *BiTree;

// ����������Ľڵ�����
int SumNodes(BiTree T) {
    if (T == NULL) {
        return 0; // ���������Ϊ�գ���ڵ���Ϊ 0
    } else {
        // �ݹ�������������Ľڵ����������ϸ��ڵ�����
        return 1 + SumNodes(T->lchild) + SumNodes(T->rchild);
    }
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
    BiTree root = createSampleTree();
    
    // ����������Ľڵ�����
    int totalNodes = SumNodes(root);
    
    // ��ӡ���
    printf("Total number of nodes in the binary tree: %d\n", totalNodes);
    
    // �ͷŶ��������ڴ�
    // ʵ��Ӧ������Ҫдһ���ͷ��ڴ�ĺ����������Ϊʾ��
    free(root->lchild->lchild);
    free(root->lchild->rchild);
    free(root->rchild->rchild);
    free(root->lchild);
    free(root->rchild);
    free(root);
    
    return 0;
}
