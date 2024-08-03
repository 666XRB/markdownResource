#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ջ�Ľṹ��
typedef struct {
    char *items;     // �洢ջԪ�ص�����ָ��
    int maxSize;    // ջ���������
    int top;        // ջ��ָ�룬ָ��ջ��Ԫ�ص�λ��
} Stack;

// ��ʼ��ջ
void initializeStack(Stack *stack, int maxSize) {
    stack->top = -1;  // ��ջʱ��top��ʼ��Ϊ-1
    stack->maxSize = maxSize;
    stack->items = (char *)malloc(maxSize * sizeof(char));  // �����ڴ�
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
void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("ջ�������޷���ջ\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// ��ջ��Ԫ�س�ջ
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷���ջ\n");
        exit(1);
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}

// ��ȡջ��Ԫ��
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// ��ȡ���������ȼ�
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// ��׺���ʽת��׺���ʽ
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initializeStack(&stack, strlen(infix));
    int postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9') {
            postfix[postfixIndex++] = ch; // ����ֱ���������׺���ʽ
        } else if (ch == '(') {
            push(&stack, ch); // ������ֱ����ջ
        } else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[postfixIndex++] = pop(&stack); // ��ջ�ڵ�������������׺���ʽ��ֱ������������
            }
            pop(&stack); // ����������
        } else { // �����
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack))) {
                postfix[postfixIndex++] = pop(&stack); // �������ȼ����ڵ�ǰ������������
            }
            push(&stack, ch); // ��ǰ�������ջ
        }
    }

    // ��ջ��ʣ���������������׺���ʽ
    while (!isEmpty(&stack)) {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0'; // �ں�׺���ʽĩβ����ַ���������
}

// ������׺ת��׺����
int main() {
    char infix[100];
    char postfix[100];

    printf("������һ����׺���ʽ�������ո񣩣�");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("��Ӧ�ĺ�׺���ʽΪ��%s\n", postfix);

    return 0;
}