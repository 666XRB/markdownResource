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


// �����½ڵ�
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    // �����Ϊ�գ�����һ���½ڵ���Ϊ���ڵ�
    if (root == NULL) {
        return createNode(val);
    }

    // ���򣬵ݹ�ز���ڵ�
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    // ���ظ��ڵ㣨δ�ı䣩
    return root;
}
// �������
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}
int main() {
    struct TreeNode* root = NULL;

    // ����ڵ�
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // �������������Ľڵ�
    printf("����������: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
