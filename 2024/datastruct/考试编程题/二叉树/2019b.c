// 2．已知二叉树采用二叉链表存储，其结点结构定义如下：
//  typedef struct TreeNode{ 
//  ElmType data；
//  struct TreeNode *lchild，*rchild；
//  }*BiTree；
// 请编写递归函数 int SumNodes(BiTree T)，返回二叉树 T 的结点总数

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *BiTree;

// 计算二叉树的节点总数
int SumNodes(BiTree T) {
    if (T == NULL) {
        return 0; // 如果二叉树为空，则节点数为 0
    } else {
        // 递归计算左右子树的节点数，并加上根节点自身
        return 1 + SumNodes(T->lchild) + SumNodes(T->rchild);
    }
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
    BiTree root = createSampleTree();
    
    // 计算二叉树的节点总数
    int totalNodes = SumNodes(root);
    
    // 打印结果
    printf("Total number of nodes in the binary tree: %d\n", totalNodes);
    
    // 释放二叉树的内存
    // 实际应用中需要写一个释放内存的函数，这里简化为示例
    free(root->lchild->lchild);
    free(root->lchild->rchild);
    free(root->rchild->rchild);
    free(root->lchild);
    free(root->rchild);
    free(root);
    
    return 0;
}
