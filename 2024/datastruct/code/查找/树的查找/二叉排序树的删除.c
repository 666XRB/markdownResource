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
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }
    return root;
}
// Ѱ����Сֵ�ڵ�
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// ɾ���ڵ�
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // �ҵ�Ҫɾ���Ľڵ�
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // �������ӽڵ㣬�������̣�����������С�ڵ㣩
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
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

    // ɾ���ڵ�
    root = deleteNode(root, 20);  // ɾ��Ҷ�ڵ�
    root = deleteNode(root, 30);  // ɾ��ֻ��һ���ӽڵ�Ľڵ�
    root = deleteNode(root, 50);  // ɾ���������ӽڵ�Ľڵ�

    // �������������Ľڵ�
    printf("ɾ���������������: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
