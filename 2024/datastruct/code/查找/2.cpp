#include <iostream>
using namespace std;
int BinarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;  // 基本情况：未找到目标值
    }

    int mid = left + (right - left) / 2;  // 防止溢出

    if (arr[mid] == key) {
        return mid;  // 找到目标值，返回其索引
    } else if (arr[mid] < key) {
        return BinarySearchRecursive(arr, mid + 1, right, key);  // 在右半部分继续查找
    } else {
        return BinarySearchRecursive(arr, left, mid - 1, key);  // 在左半部分继续查找
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin>>key;
    int result;
    result = BinarySearchRecursive(arr, 0, size - 1, key);
    if (result != -1) {
        std::cout << "成功找到，下标为" << result << std::endl;
    } else {
        std::cout << "没找到！" << std::endl;
    }

    return 0;
}

