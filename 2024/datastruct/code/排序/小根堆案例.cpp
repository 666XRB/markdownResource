#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素的值
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 调整为小根堆
void HeapAdjust(vector<int> &R, int s, int m, vector<vector<int>> &result) {
    int rc = R[s];  // 用 rc 暂存 R[s] 的值
    for (int j = 2 * s; j <= m; j *= 2) {  // 沿 key 较小的子节点向下筛选
        if (j < m && R[j] > R[j + 1]) {
            ++j;  // 如果右子节点存在且小于左子节点，则 j 指向右子节点
        }
        if (rc <= R[j]) {
            break;  // 如果 rc 小于等于最小的子节点，筛选结束
        }
        R[s] = R[j];  // 否则，将子节点上移
        s = j;  // 继续向下筛选
    }
    R[s] = rc;  // 将 rc 放到最终位置
    
    // 将当前状态存入结果中
    result.push_back(R);
}

// 建立小根堆
void BuildMinHeap(vector<int> &R, int n, vector<vector<int>> &result) {
    for (int i = n / 2; i >= 1; --i) {
        HeapAdjust(R, i, n, result);
    }
}

// 打印数组
void PrintArray(const vector<int> &R) {
    for (size_t i = 1; i < R.size(); ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> R = {-1, 49, 38, 65, 97, 76, 13, 27, 49}; // 使用从索引1开始的数组
    int n = R.size() - 1; // 数组的大小减去1，因为第一个元素是占位符
    
    vector<vector<int>> result;
    result.push_back(R); // 存入初始状态
    
    BuildMinHeap(R, n, result);
    
    // 输出每次交换完后的数组状态
    for (size_t i = 1; i < result.size(); ++i) {
        PrintArray(result[i]);
    }
    
    return 0;
}
