#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100   // 定义栈的最大容量

// 定义栈的结构体
typedef struct {
    int *items;     // 存储栈元素的数组指针
    int maxSize;    // 栈的最大容量
    int top;        // 栈顶指针，指向栈顶元素的位置
} Stack;

// 初始化栈
void initializeStack(Stack *stack, int maxSize) {
    stack->top = -1;  // 空栈时，top初始化为-1
    stack->maxSize = maxSize;
    stack->items = (int *)malloc(maxSize * sizeof(int));  // 分配内存
    if (stack->items == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
}

// 判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 将元素入栈
void push(Stack *stack, int item) {
    stack->top++;
    stack->items[stack->top] = item;
}

// 将栈顶元素出栈
int pop(Stack *stack) {
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// 十进制转换为任意进制
void decimalToBase(int decimal, int base) {
    Stack stack;
    initializeStack(&stack, MAX_SIZE);

    // 将每一位的余数入栈，直到商为0
    while (decimal > 0) {
        int remainder = decimal % base;
        push(&stack, remainder);
        decimal = decimal / base;
    }

    // 出栈并打印，得到目标进制数
    printf("%d进制表示：", base);
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        // 如果是大于10的数字，则使用字母表示
        if (digit >= 10) {
            printf("%c", 'A' + (digit - 10));
        } else {
            printf("%d", digit);
        }
    }
    printf("\n");
}

// 测试进制转换功能
int main() {
    int decimal, base;
    printf("请输入一个十进制数：");
    scanf("%d", &decimal);
    printf("请输入目标进制数（2~16）：");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("目标进制数必须在2到16之间\n");
        return 1;
    }

    decimalToBase(decimal, base);

    return 0;
}
