#include <stdio.h>
#include <stdlib.h>

// 定义栈的结构体
typedef struct {
    int *items;     // 存储栈元素的数组指针
    int maxSize;    // 栈的最大容量
    int top;        // 栈顶指针，指向栈顶元素的位置
} Stack;

// 初始化栈
void initializeStack(Stack *stack, int maxSize) {
    stack->maxSize = maxSize;
    stack->top = -1;  // 空栈时，top初始化为-1
    stack->items = (int *)malloc(maxSize * sizeof(int));
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
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// 将元素出栈
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        exit(1);
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// 获取栈顶元素
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// 清空栈
void clearStack(Stack *stack) {
    free(stack->items);
    stack->top = -1;
}

// 测试栈的功能
int main() {
    Stack stack;
    initializeStack(&stack, 5);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("栈顶元素：%d\n", peek(&stack));

    printf("出栈：%d\n", pop(&stack));
    printf("出栈：%d\n", pop(&stack));

    printf("栈是否为空：%d\n", isEmpty(&stack));

    clearStack(&stack);

    return 0;
}
