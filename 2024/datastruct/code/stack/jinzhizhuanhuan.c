#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100   // ����ջ���������

// ����ջ�Ľṹ��
typedef struct {
    int *items;     // �洢ջԪ�ص�����ָ��
    int maxSize;    // ջ���������
    int top;        // ջ��ָ�룬ָ��ջ��Ԫ�ص�λ��
} Stack;

// ��ʼ��ջ
void initializeStack(Stack *stack, int maxSize) {
    stack->top = -1;  // ��ջʱ��top��ʼ��Ϊ-1
    stack->maxSize = maxSize;
    stack->items = (int *)malloc(maxSize * sizeof(int));  // �����ڴ�
    if (stack->items == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// ��Ԫ����ջ
void push(Stack *stack, int item) {
    stack->top++;
    stack->items[stack->top] = item;
}

// ��ջ��Ԫ�س�ջ
int pop(Stack *stack) {
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// ʮ����ת��Ϊ�������
void decimalToBase(int decimal, int base) {
    Stack stack;
    initializeStack(&stack, MAX_SIZE);

    // ��ÿһλ��������ջ��ֱ����Ϊ0
    while (decimal > 0) {
        int remainder = decimal % base;
        push(&stack, remainder);
        decimal = decimal / base;
    }

    // ��ջ����ӡ���õ�Ŀ�������
    printf("%d���Ʊ�ʾ��", base);
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        // ����Ǵ���10�����֣���ʹ����ĸ��ʾ
        if (digit >= 10) {
            printf("%c", 'A' + (digit - 10));
        } else {
            printf("%d", digit);
        }
    }
    printf("\n");
}

// ���Խ���ת������
int main() {
    int decimal, base;
    printf("������һ��ʮ��������");
    scanf("%d", &decimal);
    printf("������Ŀ���������2~16����");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Ŀ�������������2��16֮��\n");
        return 1;
    }

    decimalToBase(decimal, base);

    return 0;
}
