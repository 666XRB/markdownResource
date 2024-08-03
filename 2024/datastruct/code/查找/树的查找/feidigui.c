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
// 非递归查找
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
    // 创建一个示例二叉排序树
    struct TreeNode* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    // 查找值为 40 的节点
    int key = 40;
    struct TreeNode* result = iterativeSearch(root, key);
    if (result != NULL) {
        printf("找到节点: %d\n", result->val);
    } else {
        printf("未找到节点\n");
    }

    return 0;
}
