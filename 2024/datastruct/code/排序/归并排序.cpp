#include <iostream>
#include <vector>

using namespace std;

// 合并两个已排序的子数组 R[low..mid] 和 R[mid+1..high]
void Merge(vector<int>& R, int low, int mid, int high) {
    int n1 = mid - low + 1;     // 左子数组的大小
    int n2 = high - mid;        // 右子数组的大小
    
    // 创建临时数组 L 和 R2
    vector<int> L(n1);
    vector<int> R2(n2);
    
    // 将数据复制到临时数组 L 和 R2 中
    for (int i = 0; i < n1; i++)
        L[i] = R[low + i];
    for (int j = 0; j < n2; j++)
        R2[j] = R[mid + 1 + j];
    
    // 合并临时数组 L 和 R2 到 R[low..high]
    int i = 0;  // 初始化左子数组的索引
    int j = 0;  // 初始化右子数组的索引
    int k = low;  // 初始化合并后数组的索引
    
    while (i < n1 && j < n2) {
        if (L[i] <= R2[j]) {
            R[k] = L[i];
            i++;
        } else {
            R[k] = R2[j];
            j++;
        }
        k++;
    }
    
    // 复制剩余的元素，如果有的话
    while (i < n1) {
        R[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        R[k] = R2[j];
        j++;
        k++;
    }
}

int main() {
    vector<int> R = {3, 9, 10, 27, 38, 43, 82}; // 示例已排序数组
    int low = 0;
    int high = R.size() - 1;
    int mid = (low + high) / 2; // 示例中间索引
    
    // 合并两个已排序的子数组 R[low..mid] 和 R[mid+1..high]
    Merge(R, low, mid, high);
    
    // 打印合并后的数组
    for (int num : R) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
