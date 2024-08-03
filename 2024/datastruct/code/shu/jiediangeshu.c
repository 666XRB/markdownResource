#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 计算二叉树节点总数
int CountNodes(BiTree T) {
    if (T == NULL) {
        return 0; // 如果树为空，则节点总数为0
    } else {
        // 节点总数为根节点的值加上左子树的节点总数和右子树的节点总数之和
        return 1 + CountNodes(T->lchild) + CountNodes(T->rchild);
    }
}

int main() {
    // 创建一棵示例二叉树
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

    // 计算二叉树节点总数并输出结果
    printf("二叉树节点总数为：%d\n", CountNodes(T));

    // 释放二叉树的内存
    free(T->lchild);
    free(T->rchild);
    free(T);

    return 0;
}
