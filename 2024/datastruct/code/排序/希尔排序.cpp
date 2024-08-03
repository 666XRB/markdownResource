#include <stdio.h>

#define MAXSIZE 100

// 定义顺序表类型
typedef struct {
    int r[MAXSIZE + 1]; // r[0] 作为暂存单元或哨兵
    int length;
} SqList;

// 一趟增量为dk的插入排序
void ShellInsert(SqList &L, int dk) {
    int i, j;
    for (i = dk + 1; i <= L.length; ++i) {
        if (L.r[i] < L.r[i - dk]) {
            L.r[0] = L.r[i]; // 暂存待插入元素
            for (j = i - dk; j > 0 && L.r[0] < L.r[j]; j -= dk) {
                L.r[j + dk] = L.r[j];
            }
            L.r[j + dk] = L.r[0];
        }
    }
}

// 按增量序列dlta[0..t-1]对顺序表L作希尔排序
void ShellSort(SqList &L, int dlta[], int t) {
    for (int k = 0; k < t; ++k) {
        ShellInsert(L, dlta[k]); // 一趟增量为dlta[k]的插入排序
    }
}

// 打印顺序表函数
void printList(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i]);
    }
    printf("\n");
}

// 主函数：测试代码
int main() {
    // 定义并初始化顺序表
    SqList L = {{0, 22, 5, 11, 17, 8, 14, 3, 9, 6}, 9};
    // 定义增量序列
    int dlta[] = {5, 3, 1};
    int t = sizeof(dlta) / sizeof(dlta[0]);

    printf("排序前数组: \n");
    printList(L);

    // 调用希尔排序算法
    ShellSort(L, dlta, t);

    printf("排序后数组: \n");
    printList(L);

    return 0;
}
