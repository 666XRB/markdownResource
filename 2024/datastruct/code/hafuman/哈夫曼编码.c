#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��㶨��
struct Node {
    char data;
    int frequency;
    struct Node* left;
    struct Node* right;
};

// ջ����
struct StackNode {
    struct Node* node;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

// �����½��
struct Node* create_node(char data, int frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ��ʼ��ջ
struct Stack* init_stack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int is_empty(struct Stack* stack) {
    return stack->top == NULL;
}

// ��ջ
void push(struct Stack* stack, struct Node* node) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

// ��ջ
struct Node* pop(struct Stack* stack) {
    if (is_empty(stack)) {
        return NULL;
    }
    struct StackNode* temp = stack->top;
    struct Node* node = temp->node;
    stack->top = temp->next;
    free(temp);
    return node;
}

// ����������
void huffman_encoding(struct Node* root, char* code, char** codes) {
    if (root) {
        if (!root->left && !root->right) {
            codes[root->data] = strdup(code);
        }
        char left_code[100], right_code[100];
        strcpy(left_code, code);
        strcpy(right_code, code);
        strcat(left_code, "0");
        strcat(right_code, "1");
        huffman_encoding(root->left, left_code, codes);
        huffman_encoding(root->right, right_code, codes);
    }
}

// �����ı�
char* encode_text(char* text, char** codes) {
    int len = strlen(text);
    char* encoded_text = (char*)malloc(len * 100); // Ԥ���㹻��Ŀռ�
    encoded_text[0] = '\0';
    for (int i = 0; i < len; i++) {
        strcat(encoded_text, codes[text[i]]);
    }
    return encoded_text;
}

int main() {
    char text[] = "hello";
    int frequencies[256] = {0}; // �����ַ���Ϊ ASCII �룬�� 256 ���ַ�
    for (int i = 0; i < strlen(text); i++) {
        frequencies[text[i]]++;
    }

    // ����������������ȡ����
    struct Node* root = NULL;
    struct Stack* stack = init_stack();
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            struct Node* node = create_node(i, frequencies[i]);
            push(stack, node);
        }
    }
    while (stack->top->next) {
        struct Node* node1 = pop(stack);
        struct Node* node2 = pop(stack);
        struct Node* merged_node = create_node('\0', node1->frequency + node2->frequency);
        merged_node->left = node1;
        merged_node->right = node2;
        push(stack, merged_node);
    }
    root = pop(stack);

    // ��ȡ����
    char* codes[256] = {NULL};
    huffman_encoding(root, "", codes);

    // �����ı�
    char* encoded_text = encode_text(text, codes);

    // ������
    printf("Huffman Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i]) {
            printf("%c: %s\n", i, codes[i]);
        }
    }
    printf("Encoded Text: %s\n", encoded_text);

    // �ͷ��ڴ�
    free(encoded_text);
    return 0;
}
