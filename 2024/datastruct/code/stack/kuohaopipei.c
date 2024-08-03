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

// ��������ƥ�䣬������ƥ��ʧ�ܵ�ԭ�������
int checkParentheses(char *expression) {
    Stack stack;
    initializeStack(&stack, strlen(expression));

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(&stack)) {
                return 1;  // �����Ŷ���
            }
            char left = pop(&stack);
            if ((expression[i] == ')' && left != '(') ||
                (expression[i] == '}' && left != '{') ||
                (expression[i] == ']' && left != '[')) {
                return 2;  // �������Ͳ�ƥ��
            }
        }
    }

    return isEmpty(&stack) ? 0 : 3;  // 0��ʾƥ��ɹ���3��ʾ�����Ŷ���
}

// ��ӡ����ƥ��ʧ�ܵ�ԭ�������
void printFailureReason(int reason) {
    switch (reason) {
        case 1:
            printf("����ƥ��ʧ�ܣ������Ŷ���\n");
            break;
        case 2:
            printf("����ƥ��ʧ�ܣ��������Ͳ�ƥ��\n");
            break;
        case 3:
            printf("����ƥ��ʧ�ܣ������Ŷ���\n");
            break;
        default:
            printf("����ƥ��ɹ�\n");
    }
}

// ��������ƥ�书��
int main() {
    char expression[100];
    int continue_flag = 1;

    while (continue_flag) {
        printf("������һ���������ŵı��ʽ��\n");
        scanf("%s", expression);

        int result = checkParentheses(expression);
        printFailureReason(result);

        printf("�Ƿ������1��ʾ�ǣ�0��ʾ�񣩣�");
        scanf("%d", &continue_flag);
    }

    return 0;
}
