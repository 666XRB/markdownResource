#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 计算二叉树的深度
int TreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    } else {
        // 递归计算左子树的深度
        int leftDepth = TreeDepth(T->lchild);
        // 递归计算右子树的深度
        int rightDepth = TreeDepth(T->rchild);
        // 返回左右子树深度的较大值加上根节点的深度（1）
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
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

    // 计算二叉树的深度并输出结果
    printf("二叉树的深度为：%d\n", TreeDepth(T));

    // 释放二叉树的内存
    free(T->lchild);
    free(T->rchild);
    free(T);

    return 0;
}
