#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 复制二叉树
int Copy(BiTree T, BiTree *NewT) {
    if (T == NULL) { // 如果是空树返回0
        *NewT = NULL;
        return 0;
    } else {
        *NewT = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*NewT) {
            exit(EXIT_FAILURE);
        }
        (*NewT)->data = T->data;
        // 复制左子树
        Copy(T->lchild, &(*NewT)->lchild);
        // 复制右子树
        Copy(T->rchild, &(*NewT)->rchild);
    }
    return 0;
}

// 销毁二叉树
void DestroyBiTree(BiTree *T) {
    if (*T) {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

// 中序遍历二叉树
void InOrderTraversal(BiTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        printf("%c ", T->data);
        InOrderTraversal(T->rchild);
    }
}

int main() {
    BiTree T = NULL;
    // 创建一棵示例二叉树
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = 'A';
    T->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    T->lchild->data = 'B';
    T->lchild->lchild = NULL;
    T->lchild->rchild =(BiTNode *)malloc(sizeof(BiTNode));
    T->lchild->rchild->data = 'D'; // 将 'D' 作为 'B' 的右孩子
    
    T->lchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild = NULL;
    
    T->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    T->rchild->data = 'C';
    T->rchild->lchild = NULL;
    T->rchild->rchild = NULL;

    // 复制二叉树
    BiTree NewT = NULL;
    Copy(T, &NewT);

    printf("原二叉树中序遍历结果：");
    InOrderTraversal(T);
    printf("\n");

    printf("复制的二叉树中序遍历结果：");
    InOrderTraversal(NewT);
    printf("\n");

    // 销毁原二叉树释放内存
    DestroyBiTree(&T);

    // 销毁复制的二叉树释放内存
    DestroyBiTree(&NewT);

    return 0;
}
