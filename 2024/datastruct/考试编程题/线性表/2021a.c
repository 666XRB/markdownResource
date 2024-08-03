#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ���嵥����ڵ�ṹ
typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

// ����һ���µĽڵ�
Lnode* createNode(int data) {
    Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ɾ��������ֵ���� min ��С�� max �����нڵ�
void Delete(LinkList head, int min, int max) {
    // ��ʼ��ָ�� p �� q���ֱ�ָ��ǰ�ڵ����ǰ���ڵ�
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

// ���������е���Сֵ
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

// ���������е����ֵ
int findMax(LinkList head) {
    if (head->next == NULL) {
        return INT_MIN; // �������Ϊ�գ����� INT_MIN
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

// ��ӡ����
void printList(LinkList head) {
    Lnode* p = head->next;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // ������ͷ���ĵ�����
    Lnode* head = createNode(0);
    Lnode* p = head;
    
    // �����������
    int values[] = {1, 3, 5, 7, 9, 11};
    for (int i = 0; i < 6; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // ��ӡԭ����
    printf("��ʼ������");
    printList(head);
    
    // ���������е���Сֵ�����ֵ
    int min = findMin(head);
    int max = findMax(head);
    printf("��С value: %d\n", min);
    printf("��� value: %d\n", max);
    
    // ɾ��ֵ�� 3 �� 9 ֮��Ľڵ�
    Delete(head, 3, 9);
    
    // ��ӡ�޸ĺ������
    printf("ɾ����� List: ");
    printList(head);
    
    return 0;
}
