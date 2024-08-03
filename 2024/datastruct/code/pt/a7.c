#include <stdio.h>

#define MAXSIZE 20 // 设记录不超过20个

typedef int KeyType; // 设关键字为整型量(int型)

typedef struct { // 定义每个记录(数据元素)的结构
    KeyType key; // 关键字
    // 如果有其它数据项，定义在这里
} RedType; // 记录类型

typedef struct { // 定义顺序表的结构
    RedType r[MAXSIZE + 1]; // 存储顺序表的数组，r[0]一般作哨兵或缓冲区
    int length; // 顺序表的长度
} SqList; // 顺序表类型

// 直接插入排序算法
void InsertSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) { // 从第二个元素开始插入
        if (L->r[i].key < L->r[i - 1].key) { // 需要插入的元素比前一个元素小
            L->r[0] = L->r[i]; // 设置哨兵
            for (j = i - 1; L->r[0].key < L->r[j].key; j--) { // 查找插入位置
                L->r[j + 1] = L->r[j]; // 元素后移
            }
            L->r[j + 1] = L->r[0]; // 插入到正确位置
        }
    }
}

void PrintList(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key);
    }
    printf("\n");
}

int main() {
    SqList L = {
        .r = {{0}, {5}, {3}, {8}, {6}, {2}, {7}, {4}, {1}, {0}},
        .length = 9
    };

    printf("排序前:\n");
    PrintList(L);

    InsertSort(&L);

    printf("排序后:\n");
    PrintList(L);

    return 0;
}
