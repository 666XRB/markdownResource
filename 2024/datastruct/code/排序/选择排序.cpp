#include <iostream>
using namespace std;

struct SqList {
    int* r; // 数组指针
    int length; // 数组长度
};

void SelectSort(SqList &L) {
    int i, j, k;
    for (i = 0; i < L.length - 1; ++i) {
        k = i;
        for (j = i + 1; j < L.length; ++j) {
            if (L.r[j] < L.r[k]) {
                k = j; // 记录最小值位置
            }
        }
        if (k != i) {
            swap(L.r[i], L.r[k]); // 交换
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    SqList L = {arr, 5};

    for (int i = 0; i < L.length; i++) {
        cout << L.r[i] << " ";
    }
    cout<<endl;
    SelectSort(L);
    
    for (int i = 0; i < L.length; i++) {
        cout << L.r[i] << " ";
    }
    return 0;
}
