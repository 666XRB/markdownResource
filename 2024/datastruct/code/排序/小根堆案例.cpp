#include <iostream>
#include <vector>

using namespace std;

// ��������Ԫ�ص�ֵ
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ����ΪС����
void HeapAdjust(vector<int> &R, int s, int m, vector<vector<int>> &result) {
    int rc = R[s];  // �� rc �ݴ� R[s] ��ֵ
    for (int j = 2 * s; j <= m; j *= 2) {  // �� key ��С���ӽڵ�����ɸѡ
        if (j < m && R[j] > R[j + 1]) {
            ++j;  // ������ӽڵ������С�����ӽڵ㣬�� j ָ�����ӽڵ�
        }
        if (rc <= R[j]) {
            break;  // ��� rc С�ڵ�����С���ӽڵ㣬ɸѡ����
        }
        R[s] = R[j];  // ���򣬽��ӽڵ�����
        s = j;  // ��������ɸѡ
    }
    R[s] = rc;  // �� rc �ŵ�����λ��
    
    // ����ǰ״̬��������
    result.push_back(R);
}

// ����С����
void BuildMinHeap(vector<int> &R, int n, vector<vector<int>> &result) {
    for (int i = n / 2; i >= 1; --i) {
        HeapAdjust(R, i, n, result);
    }
}

// ��ӡ����
void PrintArray(const vector<int> &R) {
    for (size_t i = 1; i < R.size(); ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> R = {-1, 49, 38, 65, 97, 76, 13, 27, 49}; // ʹ�ô�����1��ʼ������
    int n = R.size() - 1; // ����Ĵ�С��ȥ1����Ϊ��һ��Ԫ����ռλ��
    
    vector<vector<int>> result;
    result.push_back(R); // �����ʼ״̬
    
    BuildMinHeap(R, n, result);
    
    // ���ÿ�ν�����������״̬
    for (size_t i = 1; i < result.size(); ++i) {
        PrintArray(result[i]);
    }
    
    return 0;
}
