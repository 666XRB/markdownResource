#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建新节点
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// 插入新节点
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    // 如果树为空，创建一个新节点作为根节点
    if (root == NULL) {
        return createNode(val);
    }

    // 否则，递归地插入节点
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    // 返回根节点（未改变）
    return root;
}
// 中序遍历
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}
int main() {
    struct TreeNode* root = NULL;

    // 插入节点
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // 中序遍历输出树的节点
    printf("中序遍历结果: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
