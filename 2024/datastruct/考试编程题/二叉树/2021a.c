#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTNode {
    int data; // 节点数据
    struct BiTNode *lchild; // 左子节点
    struct BiTNode *rchild; // 右子节点
} BiTNode, *BiTree;

// 计算二叉树中叶子节点的数目
int LeafCount_BiTree(BiTree T) {
    // 如果树为空，则没有叶子节点
    if(!T)
    return 0;

    if(T->lchild==NULL && T->rchild==NULL)
    {
        return 1;
    }

    return LeafCount_BiTree(T->lchild)+LeafCount_BiTree(T->rchild);
}

// 创建一个新的二叉树节点
BiTNode* createNode(int data) {
    BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// 构建示例二叉树
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
    // 创建示例二叉树
    BiTree T = createSampleTree();
    
    // 计算并打印叶子节点的数目
    int leafCount = LeafCount_BiTree(T);
    printf("Number of leaf nodes: %d\n", leafCount);
    
    return 0;
}
