#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TNode {
    int data;
    struct TNode *lchild, *rchild;
} TNode, *BiTree;

// 定义队列节点结构
typedef struct queuenode {
    BiTree ch;
    struct queuenode *next;
} queuenode, *queueptr;

// 定义队列结构
typedef struct {
    queueptr front;
    queueptr rear;
} linkqueue;

// 进队函数
void enqueue(linkqueue &q, BiTree p) {
    queueptr newNode = (queueptr)malloc(sizeof(queuenode));
    newNode->ch = p;
    newNode->next = NULL;
    if (q.rear == NULL) {
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

// 出队函数
void dequeue(linkqueue &q, BiTree &p) {
    if (q.front == NULL) {
        p = NULL;
    } else {
        queueptr temp = q.front;
        p = temp->ch;
        q.front = temp->next;
        if (q.front == NULL) {
            q.rear = NULL;
        }
        free(temp);
    }
}

// 借助队列实现二叉树的层次遍历
void traverse(BiTree bt) {
    if (bt == NULL) {
        return;
    }
    
    linkqueue q;
    q.front = NULL;
    q.rear = NULL;
    
    // 根节点入队
    enqueue(q, bt);
    
    while (q.front != NULL) {
        // 出队并访问当前节点
        dequeue(q, bt);
        printf("%d ", bt->data);
        
        // 左子树入队
        if (bt->lchild != NULL) {
            enqueue(q, bt->lchild);
        }
        
        // 右子树入队
        if (bt->rchild != NULL) {
            enqueue(q, bt->rchild);
        }
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
    
    // 层次遍历二叉树
    printf("Level Order Traversal: ");
    traverse(root);
    printf("\n");
    
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
