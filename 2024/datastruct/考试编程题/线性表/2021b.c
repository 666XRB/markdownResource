// 8������������ṹ���£�
// typedef struct LNode {
// ElemType data;
// struct LNode *next;
// } LNode, *LinkList;
// ��֪��������L����ͷ�ڵ㣬д�������������еİ������ݵĽڵ㣬ͷ���λ�ò��䣬����ԭ�����£�int reverseLink(LinkList L)����10�֣�
#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// ���õ��������еİ������ݵĽڵ㣬ͷ���λ�ò���
int reverseLink(LinkList L) {
    if(L==NULL||L->next==NULL)
    {
        return 0;
    }
    LNode *prev;
    LNode *curr=L->next;
    LNode *next;

    while (!curr)
    {
        /* code */

        next=curr->next;
        
        curr->next=prev;

        prev=curr;

        curr=next;
    }
    L->next=prev;
    

    return 1; // �ɹ�����
}

// ����һ���µĽڵ�
LNode* createNode(int data) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(LinkList L) {
    LNode* p = L->next; // ����ͷ���
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // ������ͷ���ĵ�����
    LNode* head = createNode(0); // ͷ���
    LNode* p = head;
    
    // �����������
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // ��ӡԭ����
    printf("Original List: ");
    printList(head);
    
    // ��������
    reverseLink(head);
    
    // ��ӡ���ú������
    printf("Reversed List: ");
    printList(head);
    
    // �ͷ������ڴ�
    p = head;
    while (p != NULL) {
        LNode* tmp = p;
        p = p->next;
        free(tmp);
    }
    
    return 0;
}
