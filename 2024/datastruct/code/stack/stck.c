#include <stdio.h>
#include <stdlib.h>

// ����ջ�Ľṹ��
typedef struct {
    int *items;     // �洢ջԪ�ص�����ָ��
    int maxSize;    // ջ���������
    int top;        // ջ��ָ�룬ָ��ջ��Ԫ�ص�λ��
} Stack;

// ��ʼ��ջ
void initializeStack(Stack *stack, int maxSize) {
    stack->maxSize = maxSize;
    stack->top = -1;  // ��ջʱ��top��ʼ��Ϊ-1
    stack->items = (int *)malloc(maxSize * sizeof(int));
    if (stack->items == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

// ��Ԫ����ջ
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("ջ�������޷���ջ\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// ��Ԫ�س�ջ
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷���ջ\n");
        exit(1);
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// ��ȡջ��Ԫ��
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// ���ջ
void clearStack(Stack *stack) {
    free(stack->items);
    stack->top = -1;
}

// ����ջ�Ĺ���
int main() {
    Stack stack;
    initializeStack(&stack, 5);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("ջ��Ԫ�أ�%d\n", peek(&stack));

    printf("��ջ��%d\n", pop(&stack));
    printf("��ջ��%d\n", pop(&stack));

    printf("ջ�Ƿ�Ϊ�գ�%d\n", isEmpty(&stack));

    clearStack(&stack);

    return 0;
}
