//  已知二叉树采用二叉链表存储，已知以下几个结点结构定义：
//     typedef struct TNode{
//   ElmType data；
//     struct TNode *lchild，*rchild；
// }*BiTree；                    //树结点结构
// typedef struct queuenode{
//  Bitree ch;
//  struct queuenode *next;
//  }queuenode,*queueptr;                   //定义队列结点结构
// typedef struct{
//  queueptr front;
//  queueptr rear;
//  }linkqueue;                         //定义队列指针
//    请设计以下两个算法：
// (1) 计算二叉树中所有节点元素值之和，函数原型为：void sum(Bitree bt, int &e); (4分)
// (2) 借助队列实现二叉树的层次遍历，函数原型为：void traverse(Bitree bt);已知队列的进队函数是void enqueue(linkqueue &q,Bitree p),出队函数是void dequeue(linkqueue &q,bitree &p)，这两个函数可以直接调用。(6分)
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TNode {
    int data;
    struct TNode *lchild, *rchild;
} TNode, *BiTree;

// 计算二叉树中所有节点元素值之和
void sum(BiTree bt, int &e) {
    if (bt != NULL) {
        // 累加当前节点的值
        e += bt->data;
        // 递归计算左子树和右子树的节点值之和
        sum(bt->lchild, e);
        sum(bt->rchild, e);
    }
}

// 创建一个新的二叉树节点
BiTree createNode(int data) {
    BiTree newNode = (BiTree)malloc(sizeof(TNode));
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
    
    // 计算二叉树中所有节点元素值之和
    int totalSum = 0;
    sum(root, totalSum);
    
    // 打印结果
    printf("Sum of all elements in the binary tree: %d\n", totalSum);
    
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
