#include <iostream>
#include <vector>

// 定义顺序表结构
struct SqList {
    std::vector<int> r; // 用向量存储元素
};

// 分割函数，将顺序表分割，并返回枢轴位置
int Partition(SqList &L, int low, int high) {
    // L.r[0] = L.r[low]; // 使用哨兵，存储枢轴
    int pivotkey = L.r[low]; // 枢轴关键字
    while (low < high) {
        while (low < high && L.r[high] >= pivotkey) --high;
        L.r[low] = L.r[high]; // 将比枢轴小的元素移到低端
        while (low < high && L.r[low] <= pivotkey) ++low;
        L.r[high] = L.r[low]; // 将比枢轴大的元素移到高端
    }
    // L.r[low] = L.r[0]; // 枢轴元素归位
    return low; // 返回枢轴位置
}

// 快速排序函数
void QSort(SqList &L, int low, int high) {
    if (low < high) { // 子表长度大于1
        int pivotloc = Partition(L, low, high); // 分割
        QSort(L, low, pivotloc - 1); // 递归排序低子表
        QSort(L, pivotloc + 1, high); // 递归排序高子表
    }
}

int main() {
    // 示例使用
    SqList L = { {34, 7, 23, 32, 5, 62} }; // 初始化顺序表

        // 打印排序后的顺序表
    for (int i : L.r) {
        std::cout << i << " ";
    }
    QSort(L, 0, L.r.size() - 1); // 对顺序表进行快速排序

    std::cout<<std::endl;
    // 打印排序后的顺序表
    for (int i : L.r) {
        std::cout << i << " ";
    }

    return 0;
}
