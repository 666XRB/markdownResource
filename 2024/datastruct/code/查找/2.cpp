#include <iostream>
using namespace std;
int BinarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;  // ���������δ�ҵ�Ŀ��ֵ
    }

    int mid = left + (right - left) / 2;  // ��ֹ���

    if (arr[mid] == key) {
        return mid;  // �ҵ�Ŀ��ֵ������������
    } else if (arr[mid] < key) {
        return BinarySearchRecursive(arr, mid + 1, right, key);  // ���Ұ벿�ּ�������
    } else {
        return BinarySearchRecursive(arr, left, mid - 1, key);  // ����벿�ּ�������
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
        std::cout << "�ɹ��ҵ����±�Ϊ" << result << std::endl;
    } else {
        std::cout << "û�ҵ���" << std::endl;
    }

    return 0;
}

