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
// �ݹ����
struct TreeNode* recursiveSearch(struct TreeNode* root, int key) {
    // ������������ڵ�Ϊ�ջ���ڵ��ֵ����Ҫ���ҵ�ֵ
    if (root == NULL || root->val == key)
        return root;
    
    // Ҫ���ҵ�ֵС�ڸ��ڵ��ֵ�����������в���
    if (key < root->val)
        return recursiveSearch(root->left, key);
    
    // Ҫ���ҵ�ֵ���ڸ��ڵ��ֵ�����������в���
    return recursiveSearch(root->right, key);
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
    struct TreeNode* result = recursiveSearch(root, key);
    if (result != NULL) {
        printf("�ҵ��ڵ�: %d\n", result->val);
    } else {
        printf("δ�ҵ��ڵ�\n");
    }

    return 0;
}
