#include <iostream>
using namespace std;
int BinarySearch(int arr[], int size, int key);
int BinarySearchRecursive(int arr[], int left, int right, int key);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin>>key;

    int result = BinarySearch(arr, size, key);
    if (result != -1) {
        std::cout << "�ɹ��ҵ����±�Ϊ" << result << std::endl;
    } else {
        std::cout << "û�ҵ���" << std::endl;
    }

    result = BinarySearchRecursive(arr, 0, size - 1, key);
    if (result != -1) {
        std::cout << "�ɹ��ҵ����±�Ϊ" << result << std::endl;
    } else {
        std::cout << "û�ҵ���" << std::endl;
    }

    return 0;
}

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

int BinarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // ��ֹ���

        if (arr[mid] == key) {
            return mid;  // �ҵ�Ŀ��ֵ������������
        } else if (arr[mid] < key) {
            left = mid + 1;  // ���Ұ벿�ּ�������
        } else {
            right = mid - 1;  // ����벿�ּ�������
        }
    }

    return -1;  // δ�ҵ�Ŀ��ֵ������ -1
}


