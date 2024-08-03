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

// 检验括号匹配，并返回匹配失败的原因和种类
int checkParentheses(char *expression) {
    Stack stack;
    initializeStack(&stack, strlen(expression));

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(&stack)) {
                return 1;  // 右括号多余
            }
            char left = pop(&stack);
            if ((expression[i] == ')' && left != '(') ||
                (expression[i] == '}' && left != '{') ||
                (expression[i] == ']' && left != '[')) {
                return 2;  // 括号类型不匹配
            }
        }
    }

    return isEmpty(&stack) ? 0 : 3;  // 0表示匹配成功，3表示左括号多余
}

// 打印括号匹配失败的原因和种类
void printFailureReason(int reason) {
    switch (reason) {
        case 1:
            printf("括号匹配失败：右括号多余\n");
            break;
        case 2:
            printf("括号匹配失败：括号类型不匹配\n");
            break;
        case 3:
            printf("括号匹配失败：左括号多余\n");
            break;
        default:
            printf("括号匹配成功\n");
    }
}

// 测试括号匹配功能
int main() {
    char expression[100];
    int continue_flag = 1;

    while (continue_flag) {
        printf("请输入一个包含括号的表达式：\n");
        scanf("%s", expression);

        int result = checkParentheses(expression);
        printFailureReason(result);

        printf("是否继续（1表示是，0表示否）：");
        scanf("%d", &continue_flag);
    }

    return 0;
}
