#include <iostream>
using namespace std;
int BinarySearch(int arr[], int size, int key);
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout<<"输入要查找的key"<<endl;
    cin>>key;

    int result = BinarySearch(arr, size, key);
    if (result != -1) {
        std::cout << "成功找到，下标为" << result << std::endl;
    } else {
        std::cout << "没找到！" << std::endl;
    }
    return 0;
}

int BinarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢出

        if (arr[mid] == key) {
            return mid;  // 找到目标值，返回其索引
        } else if (arr[mid] < key) {
            left = mid + 1;  // 在右半部分继续查找
        } else {
            right = mid - 1;  // 在左半部分继续查找
        }
    }

    return -1;  // 未找到目标值，返回 -1
}
