#include <iostream>

struct RedType {
    int key; // 可以根据需要添加其他成员
};

struct SqList {
    RedType *r; // 动态数组指针
    int length; // 数组长度
};

void bubble_sort(SqList &L) {
    int m, j;
    RedType x; // 交换时临时存储
    for (m = 1; m < L.length; ++m) { // 总共需进行 length-1 趟排序
        for (j = 0; j < L.length - m; ++j) { // 每趟需要比较的范围逐渐减小
            if (L.r[j].key > L.r[j + 1].key) { // 如果前一个元素大于后一个元素
                x = L.r[j]; // 交换它们
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = x;
            }
        }
    }
}

int main() {
    int n = 5; // 假设排序的元素个数为5
    SqList L;
    L.length = n;
    L.r = new RedType[n];

    // 初始化测试数据
    L.r[0].key = 5;
    L.r[1].key = 3;
    L.r[2].key = 8;
    L.r[3].key = 6;
    L.r[4].key = 2;

    // 输出排序前的数组
    std::cout << "排序前" << std::endl;
    for (int i = 0; i < L.length; ++i) {
        std::cout << L.r[i].key << " ";
    }
    std::cout << std::endl;

    // 进行冒泡排序
    bubble_sort(L);

    // 输出排序后的数组
    std::cout << "冒泡排序后" << std::endl;
    for (int i = 0; i < L.length; ++i) {
        std::cout << L.r[i].key << " ";
    }
    std::cout << std::endl;

    // 释放动态分配的内存
    delete[] L.r;

    return 0;
}
