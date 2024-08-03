#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

// ������������Ľ��ṹ��
typedef struct {
    char data; // �ַ�����
    int weight; // Ȩ��
    int parent, lchild, rchild; // ˫�ס����ӡ��Һ��ӵ��±�
} HuffmanNode, *HuffmanTree;

// ������������
void CreateHuffmanTree(HuffmanTree &HT, unordered_map<char, int> &freq_map) {
    int n = freq_map.size();
    if (n <= 1) return;

    int m = 2 * n - 1; // �����������ܽ����
    HT = new HuffmanNode[m + 1]; // ����洢�ռ�

    // ��ʼ��Ҷ�ӽ��
    int i = 1;
    for (auto &entry : freq_map) {
        HT[i].data = entry.first;
        HT[i].weight = entry.second;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        i++;
    }

    // ��ʼ����Ҷ�ӽ��
    for (; i <= m; i++) {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // ������������
    for (int i = n + 1; i <= m; i++) {
        int s1, s2;
        int min1 = INT_MAX, min2 = INT_MAX; // Ѱ��Ȩ����С���������
        for (int j = 1; j < i; j++) {
            if (HT[j].parent == 0 && HT[j].weight < min1) {
                min2 = min1;
                s2 = s1;
                min1 = HT[j].weight;
                s1 = j;
            } else if (HT[j].parent == 0 && HT[j].weight < min2) {
                min2 = HT[j].weight;
                s2 = j;
            }
        }
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = min1 + min2;
    }
}

// ��������������
void CreateHuffmanCode(HuffmanTree HT, char **&HC, unordered_map<char, string> &code_map, int n) {
    HC = new char*[n + 1]; // ���� n ���ַ������ͷָ��ʸ��
    char *cd = new char[n]; // ������ʱ��ű���Ķ�̬����ռ�
    cd[n - 1] = '\0'; // ���������

    for (int i = 1; i <= n; i++) {
        int start = n - 1;
        int c = i;
        int f = HT[i].parent;
        while (f != 0) {
            --start; // ����һ�Σ�start ��ǰָһ��λ��
            if (HT[f].lchild == c)
                cd[start] = '0'; // ��� c �� f �����ӣ������ɴ��� '0'
            else
                cd[start] = '1'; // ��� c �� f ���Һ��ӣ������ɴ��� '1'
            c = f;
            f = HT[f].parent; // �������ϻ���
        }
        // ����� i ���ַ��ı���
        HC[i] = new char[n - start]; // Ϊ�� i ���ַ����������ռ�
        strcpy(HC[i], &cd[start]); // ����õı������ʱ�ռ� cd ���Ƶ� HC �ĵ�ǰ����

        // ����������ϣ����
        code_map[HT[i].data] = string(HC[i]);
    }

    delete[] cd; // �ͷ���ʱ�ռ�
}

// ��ȡ�ַ�����ÿ���ַ���Ƶ��
unordered_map<char, int> getFrequency(const string &str) {
    unordered_map<char, int> freq_map;
    for (char c : str) {
        freq_map[c]++;
    }
    return freq_map;
}

// ���ַ�������Ϊ����������
string encodeString(const string &str, unordered_map<char, string> &code_map) {
    string encoded_str;
    for (char c : str) {
        encoded_str += code_map[c];
    }
    return encoded_str;
}

int main() {
    string str = "hello";
    unordered_map<char, int> freq_map = getFrequency(str);

    HuffmanTree HT;
    CreateHuffmanTree(HT, freq_map);

    char **HC;
    unordered_map<char, string> code_map;
    CreateHuffmanCode(HT, HC, code_map, freq_map.size());

    // �������������
    cout << "Huffman Codes:" << endl;
    for (auto &entry : code_map) {
        cout << "Character " << entry.first << ": " << entry.second << endl;
    }

    // ���ַ�������Ϊ����������
    string encoded_str = encodeString(str, code_map);
    cout << "Encoded String: " << encoded_str << endl;

    // �ͷ��ڴ�
    for (int i = 1; i <= freq_map.size(); i++) {
        delete[] HC[i];
    }
    delete[] HC;
    delete[] HT;

    return 0;
}
