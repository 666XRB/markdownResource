// ��֪һ����ͷ���ĵ���������Ķ������£�
// Typedef struct Lnode
// {
// 	 elemtype data;
// 	 struct Lnode *next;
// }Lnode,*LinkList;
// �����һ���㷨int judge(LinkList L)���жϸñ�����ֵ�Ƿ�ǵݼ�����
// (ע��Ҫ���ʵ���ע�ͣ�)
#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ
typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

// �ж������Ƿ�ǵݼ�����
int judge(LinkList L) {
    // �������Ϊ�ջ�ֻ��һ���ڵ㣬����Ϊ�������
    if (L == NULL || L->next == NULL) {
        return 1; // ����
    }
    
    Lnode *p = L->next; // �ӵ�һ���ڵ㿪ʼ�ж�

    while (p->next != NULL) {
        // �����ǰ�ڵ�ֵ������һ���ڵ�ֵ�����Ƿǵݼ�����
        if (p->data > p->next->data) {
            return 0; // ����
        }
        p = p->next; // �ƶ�����һ���ڵ�
    }
    return 1; // ����
}

// ����һ���µĽڵ�
Lnode* createNode(int data) {
    Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(LinkList L) {
    Lnode* p = L->next; // ����ͷ���
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    // ������ͷ���ĵ�����
    Lnode* head = createNode(0); // ͷ���
    Lnode* p = head;
    
    // ����������ݣ���֤����ǵݼ�����
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        p->next = createNode(values[i]);
        p = p->next;
    }
    
    // ��ӡ����
    printf("List: ");
    printList(head);
    
    // �ж������Ƿ�ǵݼ�����
    if (judge(head)) {
        printf("������\n");
    } else {
        printf("�ǵ���\n");
    }
    
    // �ͷ������ڴ�
    p = head;
    while (p != NULL) {
        Lnode* tmp = p;
        p = p->next;
        free(tmp);
    }
    
    return 0;
}
