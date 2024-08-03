#include <iostream>
#include <vector>

using namespace std;

// �ϲ������������������ R[low..mid] �� R[mid+1..high]
void Merge(vector<int>& R, int low, int mid, int high) {
    int n1 = mid - low + 1;     // ��������Ĵ�С
    int n2 = high - mid;        // ��������Ĵ�С
    
    // ������ʱ���� L �� R2
    vector<int> L(n1);
    vector<int> R2(n2);
    
    // �����ݸ��Ƶ���ʱ���� L �� R2 ��
    for (int i = 0; i < n1; i++)
        L[i] = R[low + i];
    for (int j = 0; j < n2; j++)
        R2[j] = R[mid + 1 + j];
    
    // �ϲ���ʱ���� L �� R2 �� R[low..high]
    int i = 0;  // ��ʼ���������������
    int j = 0;  // ��ʼ���������������
    int k = low;  // ��ʼ���ϲ������������
    
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
    
    // ����ʣ���Ԫ�أ�����еĻ�
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
    vector<int> R = {3, 9, 10, 27, 38, 43, 82}; // ʾ������������
    int low = 0;
    int high = R.size() - 1;
    int mid = (low + high) / 2; // ʾ���м�����
    
    // �ϲ������������������ R[low..mid] �� R[mid+1..high]
    Merge(R, low, mid, high);
    
    // ��ӡ�ϲ��������
    for (int num : R) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
