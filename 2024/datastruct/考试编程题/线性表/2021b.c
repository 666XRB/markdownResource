// 8、单向链表结点结构如下：
// typedef struct LNode {
// ElemType data;
// struct LNode *next;
// } LNode, *LinkList;
// 已知单向链表L包含头节点，写函数倒置链表中的包含数据的节点，头结点位置不变，函数原型如下：int reverseLink(LinkList L)。（10分）
#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 倒置单向链表中的包含数据的节点，头结点位置不变
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
    

    return 1; // 成功倒置
}

// 创建一个新的节点
LNode* createNode(int data) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(LinkList L) {
    LNode* p = L->next; // 跳过头结点
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建带头结点的单链表
    LNode* head = createNode(0); // 头结点
    LNode* p = head;
    
    // 插入测试数据
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // 打印原链表
    printf("Original List: ");
    printList(head);
    
    // 倒置链表
    reverseLink(head);
    
    // 打印倒置后的链表
    printf("Reversed List: ");
    printList(head);
    
    // 释放链表内存
    p = head;
    while (p != NULL) {
        LNode* tmp = p;
        p = p->next;
        free(tmp);
    }
    
    return 0;
}
