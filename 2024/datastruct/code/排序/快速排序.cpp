#include <iostream>
#include <vector>

// ����˳���ṹ
struct SqList {
    std::vector<int> r; // �������洢Ԫ��
};

// �ָ������˳���ָ����������λ��
int Partition(SqList &L, int low, int high) {
    // L.r[0] = L.r[low]; // ʹ���ڱ����洢����
    int pivotkey = L.r[low]; // ����ؼ���
    while (low < high) {
        while (low < high && L.r[high] >= pivotkey) --high;
        L.r[low] = L.r[high]; // ��������С��Ԫ���Ƶ��Ͷ�
        while (low < high && L.r[low] <= pivotkey) ++low;
        L.r[high] = L.r[low]; // ����������Ԫ���Ƶ��߶�
    }
    // L.r[low] = L.r[0]; // ����Ԫ�ع�λ
    return low; // ��������λ��
}

// ����������
void QSort(SqList &L, int low, int high) {
    if (low < high) { // �ӱ��ȴ���1
        int pivotloc = Partition(L, low, high); // �ָ�
        QSort(L, low, pivotloc - 1); // �ݹ�������ӱ�
        QSort(L, pivotloc + 1, high); // �ݹ�������ӱ�
    }
}

int main() {
    // ʾ��ʹ��
    SqList L = { {34, 7, 23, 32, 5, 62} }; // ��ʼ��˳���

        // ��ӡ������˳���
    for (int i : L.r) {
        std::cout << i << " ";
    }
    QSort(L, 0, L.r.size() - 1); // ��˳�����п�������

    std::cout<<std::endl;
    // ��ӡ������˳���
    for (int i : L.r) {
        std::cout << i << " ";
    }

    return 0;
}
