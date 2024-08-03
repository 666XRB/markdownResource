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
// 递归查找
struct TreeNode* recursiveSearch(struct TreeNode* root, int key) {
    // 基本情况：根节点为空或根节点的值等于要查找的值
    if (root == NULL || root->val == key)
        return root;
    
    // 要查找的值小于根节点的值，在左子树中查找
    if (key < root->val)
        return recursiveSearch(root->left, key);
    
    // 要查找的值大于根节点的值，在右子树中查找
    return recursiveSearch(root->right, key);
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
    struct TreeNode* result = recursiveSearch(root, key);
    if (result != NULL) {
        printf("找到节点: %d\n", result->val);
    } else {
        printf("未找到节点\n");
    }

    return 0;
}
