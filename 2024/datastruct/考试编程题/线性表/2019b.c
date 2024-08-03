#include <stdio.h>
#include <stdlib.h>

// 定义线性表节点结构
typedef struct LinearNode {
    int data;
    struct LinearNode *next;
} LinearNode, *List;

// 删除值为 e 的所有节点，返回被删除节点的个数
int DeleteNodes(List L, int e) {
    if(L==NULL||L->next==NULL)
    {
        return 0;
    }
    
    LinearNode *prev=L;
    LinearNode *curr=L->next;
    int count=0;

    while (curr)
    {
        /* code */
        if(curr->data==e)
        {
            prev->next=curr->next;

            free(curr);

            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return count;
    
    
}

// 创建一个新的节点
LinearNode* createNode(int data) {
    LinearNode* newNode = (LinearNode*)malloc(sizeof(LinearNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(List L) {
    LinearNode* p = L->next; // 跳过头结点
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建带头结点的单链表
    LinearNode* head = createNode(0); // 头结点
    LinearNode* p = head;
    
    // 插入测试数据
    int values[] = {1, 2, 3, 2, 4, 2, 5};
    for (int i = 0; i < 7; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // 打印原链表
    printf("Original List: ");
    printList(head);
    
    // 删除值为 2 的节点
    int deletedCount = DeleteNodes(head, 2);
    
    // 打印删除后的链表
    printf("List after deletion: ");
    printList(head);
    
    // 打印被删除节点的个数
    printf("Number of deleted nodes: %d\n", deletedCount);
    
    // 释放链表内存
    p = head;
    while (p != NULL) {
        LinearNode* tmp = p;
        p = p->next;
        free(tmp);
    }
    
    return 0;
}
