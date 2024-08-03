#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义栈的结构体
typedef struct {
    char *items;     // 存储栈元素的数组指针
    int maxSize;    // 栈的最大容量
    int top;        // 栈顶指针，指向栈顶元素的位置
} Stack;

// 初始化栈
void initializeStack(Stack *stack, int maxSize) {
    stack->top = -1;  // 空栈时，top初始化为-1
    stack->maxSize = maxSize;
    stack->items = (char *)malloc(maxSize * sizeof(char));  // 分配内存
    if (stack->items == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
}

// 判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

// 将元素入栈
void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// 将栈顶元素出栈
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        exit(1);
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}

// 获取栈顶元素
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// 获取操作符优先级
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

// 中缀表达式转后缀表达式
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initializeStack(&stack, strlen(infix));
    int postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9') {
            postfix[postfixIndex++] = ch; // 数字直接输出到后缀表达式
        } else if (ch == '(') {
            push(&stack, ch); // 左括号直接入栈
        } else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[postfixIndex++] = pop(&stack); // 将栈内的运算符输出到后缀表达式，直到遇到左括号
            }
            pop(&stack); // 弹出左括号
        } else { // 运算符
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack))) {
                postfix[postfixIndex++] = pop(&stack); // 弹出优先级高于当前运算符的运算符
            }
            push(&stack, ch); // 当前运算符入栈
        }
    }

    // 将栈中剩余的运算符输出到后缀表达式
    while (!isEmpty(&stack)) {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0'; // 在后缀表达式末尾添加字符串结束符
}

// 测试中缀转后缀功能
int main() {
    char infix[100];
    char postfix[100];

    printf("请输入一个中缀表达式（不含空格）：");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("对应的后缀表达式为：%s\n", postfix);

    return 0;
}