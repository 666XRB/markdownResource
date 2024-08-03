#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义单链表节点结构
typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

// 创建一个新的节点
Lnode* createNode(int data) {
    Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 删除链表中值大于 min 且小于 max 的所有节点
void Delete(LinkList head, int min, int max) {
    // 初始化指针 p 和 q，分别指向当前节点和其前驱节点
    Lnode *p;
    Lnode *q;
    q=head;
    p=head->next;

    while (p)
    {
        if(p->data>min&&p->data<max)
        {

            q->next=p->next;
            free(p);
            p=q->next;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    
}

// 查找链表中的最小值
int findMin(LinkList head) {
    if(!head->next)
    {
        return INT_MAX;
    }

    int min=head->next->data;
    Lnode *p=head->next->next;

    while (p)
    {
        /* code */
        if(p->data<min)
        {
            min=p->data;
        }
        else
        {
            p=p->next;
        }
    }
    return min;
    
}

// 查找链表中的最大值
int findMax(LinkList head) {
    if (head->next == NULL) {
        return INT_MIN; // 如果链表为空，返回 INT_MIN
    }
    int max = head->next->data;
    Lnode* p = head->next->next;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// 打印链表
void printList(LinkList head) {
    Lnode* p = head->next;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建带头结点的单链表
    Lnode* head = createNode(0);
    Lnode* p = head;
    
    // 插入测试数据
    int values[] = {1, 3, 5, 7, 9, 11};
    for (int i = 0; i < 6; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // 打印原链表
    printf("初始的链表");
    printList(head);
    
    // 查找链表中的最小值和最大值
    int min = findMin(head);
    int max = findMax(head);
    printf("最小 value: %d\n", min);
    printf("最大 value: %d\n", max);
    
    // 删除值在 3 和 9 之间的节点
    Delete(head, 3, 9);
    
    // 打印修改后的链表
    printf("删除后的 List: ");
    printList(head);
    
    return 0;
}
