//  ��֪���������ö�������洢����֪���¼������ṹ���壺
//     typedef struct TNode{
//   ElmType data��
//     struct TNode *lchild��*rchild��
// }*BiTree��                    //�����ṹ
// typedef struct queuenode{
//  Bitree ch;
//  struct queuenode *next;
//  }queuenode,*queueptr;                   //������н��ṹ
// typedef struct{
//  queueptr front;
//  queueptr rear;
//  }linkqueue;                         //�������ָ��
//    ��������������㷨��
// (1) ��������������нڵ�Ԫ��ֵ֮�ͣ�����ԭ��Ϊ��void sum(Bitree bt, int &e); (4��)
// (2) ��������ʵ�ֶ������Ĳ�α���������ԭ��Ϊ��void traverse(Bitree bt);��֪���еĽ��Ӻ�����void enqueue(linkqueue &q,Bitree p),���Ӻ�����void dequeue(linkqueue &q,bitree &p)����������������ֱ�ӵ��á�(6��)
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TNode {
    int data;
    struct TNode *lchild, *rchild;
} TNode, *BiTree;

// ��������������нڵ�Ԫ��ֵ֮��
void sum(BiTree bt, int &e) {
    if (bt != NULL) {
        // �ۼӵ�ǰ�ڵ��ֵ
        e += bt->data;
        // �ݹ�������������������Ľڵ�ֵ֮��
        sum(bt->lchild, e);
        sum(bt->rchild, e);
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
    
    // ��������������нڵ�Ԫ��ֵ֮��
    int totalSum = 0;
    sum(root, totalSum);
    
    // ��ӡ���
    printf("Sum of all elements in the binary tree: %d\n", totalSum);
    
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
