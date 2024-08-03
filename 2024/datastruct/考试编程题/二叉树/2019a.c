// 已知二叉树采用二叉链表存储，其结点结构定义如下：
//  Typedef struct TreeNode{ 
//  ElmType data；
//  struct TreeNode *lchild，*rchild；
//  }*BiTree；
// 请设计算法 Void CountNodes(BiTree t)分别求出二叉树的叶结点、度为 1的结点、度
// 为 2 的结点的个数。(注：要有适当的注释！)
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *BiTree;

// 辅助函数：递归计算二叉树的节点个数
void CountNodesHelper(BiTree t, int *leafCount, int *degree1Count, int *degree2Count) {
    if (t == NULL) {
        return;
    }
    
    // 叶结点
    if (t->lchild == NULL && t->rchild == NULL) {
        (*leafCount)++;
    }
    // 度为 2 的结点
    else if (t->lchild != NULL && t->rchild != NULL) {
        (*degree2Count)++;
    }
    // 度为 1 的结点
    else {
        (*degree1Count)++;
    }
    
    // 递归遍历左右子树
    CountNodesHelper(t->lchild, leafCount, degree1Count, degree2Count);
    CountNodesHelper(t->rchild, leafCount, degree1Count, degree2Count);
}

// 计算二叉树的叶结点、度为 1 的结点、度为 2 的结点的个数
void CountNodes(BiTree t, int *leafCount, int *degree1Count, int *degree2Count) {
    *leafCount = 0;
    *degree1Count = 0;
    *degree2Count = 0;
    CountNodesHelper(t, leafCount, degree1Count, degree2Count);
}

// 创建一个新的二叉树节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// 构建示例二叉树
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
    // 创建示例二叉树
    BiTree root = createSampleTree();
    
    // 变量用于存储叶结点、度为 1 的结点、度为 2 的结点的个数
    int leafCount, degree1Count, degree2Count;
    
    // 计算节点个数
    CountNodes(root, &leafCount, &degree1Count, &degree2Count);
    
    // 打印结果
    printf("度为 0 nodes: %d\n", leafCount);
    printf("度为 1 nodes: %d\n", degree1Count);
    printf("度为 2 nodes: %d\n", degree2Count);
    
    return 0;
}
