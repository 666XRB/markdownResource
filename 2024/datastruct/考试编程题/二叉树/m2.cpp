#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TNode {
    int data;
    struct TNode *lchild, *rchild;
} TNode, *BiTree;

// ������нڵ�ṹ
typedef struct queuenode {
    BiTree ch;
    struct queuenode *next;
} queuenode, *queueptr;

// ������нṹ
typedef struct {
    queueptr front;
    queueptr rear;
} linkqueue;

// ���Ӻ���
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

// ���Ӻ���
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

// ��������ʵ�ֶ������Ĳ�α���
void traverse(BiTree bt) {
    if (bt == NULL) {
        return;
    }
    
    linkqueue q;
    q.front = NULL;
    q.rear = NULL;
    
    // ���ڵ����
    enqueue(q, bt);
    
    while (q.front != NULL) {
        // ���Ӳ����ʵ�ǰ�ڵ�
        dequeue(q, bt);
        printf("%d ", bt->data);
        
        // ���������
        if (bt->lchild != NULL) {
            enqueue(q, bt->lchild);
        }
        
        // ���������
        if (bt->rchild != NULL) {
            enqueue(q, bt->rchild);
        }
    }
}

// ����һ���µĶ������ڵ�
BiTree createNode(int data) {
    BiTree newNode = (BiTree)malloc(sizeof(TNode));
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
    
    // ��α���������
    printf("Level Order Traversal: ");
    traverse(root);
    printf("\n");
    
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
