#include <stdio.h>
#include <iostream>
// 定义顺序表的最大长度
#define MAXSIZE 100

// 定义元素类型
typedef struct {
    int key;
} ElemType;

// 定义顺序表类型
typedef struct {
    ElemType r[MAXSIZE + 1]; // 多一个哨兵位置
    int length;
} SqList;

// 折半插入排序算法
void BInsertSort(SqList &L) {
    int i, j, low, high, mid;
    ElemType temp;

    for (i = 2; i <= L.length; ++i) {
        L.r[0] = L.r[i]; // 当前插入元素存到“哨兵”位置
        low = 1;
        high = i - 1;

        // 采用二分查找法查找插入位置
        while (low <= high) {
            mid = (low + high) / 2;
            if (L.r[0].key < L.r[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 循环结束，high+1则为插入位置
        for (j = i - 1; j >= high + 1; --j) {
            L.r[j + 1] = L.r[j]; // 移动元素
        }

        L.r[high + 1] = L.r[0]; // 插入到正确位置
    }
}

// 打印顺序表函数
void printList(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key);
    }
    printf("\n");
}

// 主函数：测试代码
int main() {
    // 定义并初始化顺序表
    SqList L = {{{0}, {3}, {1}, {5}, {7}, {2}, {4}, {9}, {6}}, 8};
    
    printf("排序前数组: \n");
    printList(L);

    // 调用折半插入排序算法
    BInsertSort(L);

    printf("排序后数组: \n");
    printList(L);

    return 0;
}
