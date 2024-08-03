// 已知一个带头结点的单链表，其结点的定义如下：
// Typedef struct Lnode
// {
// 	 elemtype data;
// 	 struct Lnode *next;
// }Lnode,*LinkList;
// 请设计一个算法int judge(LinkList L)：判断该表各结点值是否非递减有序。
// (注：要有适当的注释！)
#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

// 判断链表是否非递减有序
int judge(LinkList L) {
    // 如果链表为空或只有一个节点，则认为是有序的
    if (L == NULL || L->next == NULL) {
        return 1; // 有序
    }
    
    Lnode *p = L->next; // 从第一个节点开始判断

    while (p->next != NULL) {
        // 如果当前节点值大于下一个节点值，则不是非递减有序
        if (p->data > p->next->data) {
            return 0; // 无序
        }
        p = p->next; // 移动到下一个节点
    }
    return 1; // 有序
}

// 创建一个新的节点
Lnode* createNode(int data) {
    Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(LinkList L) {
    Lnode* p = L->next; // 跳过头结点
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建带头结点的单链表
    Lnode* head = createNode(0); // 头结点
    Lnode* p = head;
    
    // 插入测试数据，保证链表非递减有序
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // 打印链表
    printf("List: ");
    printList(head);
    
    // 判断链表是否非递减有序
    if (judge(head)) {
        printf("递增序\n");
    } else {
        printf("非递增\n");
    }
    
    // 释放链表内存
    p = head;
    while (p != NULL) {
        Lnode* tmp = p;
        p = p->next;
        free(tmp);
    }
    
    return 0;
}
