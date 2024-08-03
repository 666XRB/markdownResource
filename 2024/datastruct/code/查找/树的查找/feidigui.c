#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ��
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// �����½ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// �ǵݹ����
struct TreeNode* iterativeSearch(struct TreeNode* root, int key) {
    while (root != NULL && root->val != key) {
        if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
int main() {
    // ����һ��ʾ������������
    struct TreeNode* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    // ����ֵΪ 40 �Ľڵ�
    int key = 40;
    struct TreeNode* result = iterativeSearch(root, key);
    if (result != NULL) {
        printf("�ҵ��ڵ�: %d\n", result->val);
    } else {
        printf("δ�ҵ��ڵ�\n");
    }

    return 0;
}
