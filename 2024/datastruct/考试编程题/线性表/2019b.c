#include <stdio.h>
#include <stdlib.h>

// �������Ա�ڵ�ṹ
typedef struct LinearNode {
    int data;
    struct LinearNode *next;
} LinearNode, *List;

// ɾ��ֵΪ e �����нڵ㣬���ر�ɾ���ڵ�ĸ���
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

// ����һ���µĽڵ�
LinearNode* createNode(int data) {
    LinearNode* newNode = (LinearNode*)malloc(sizeof(LinearNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(List L) {
    LinearNode* p = L->next; // ����ͷ���
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // ������ͷ���ĵ�����
    LinearNode* head = createNode(0); // ͷ���
    LinearNode* p = head;
    
    // �����������
    int values[] = {1, 2, 3, 2, 4, 2, 5};
    for (int i = 0; i < 7; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // ��ӡԭ����
    printf("Original List: ");
    printList(head);
    
    // ɾ��ֵΪ 2 �Ľڵ�
    int deletedCount = DeleteNodes(head, 2);
    
    // ��ӡɾ���������
    printf("List after deletion: ");
    printList(head);
    
    // ��ӡ��ɾ���ڵ�ĸ���
    printf("Number of deleted nodes: %d\n", deletedCount);
    
    // �ͷ������ڴ�
    p = head;
    while (p != NULL) {
        LinearNode* tmp = p;
        p = p->next;
        free(tmp);
    }
    
    return 0;
}
