#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

// 定义哈夫曼树的结点结构体
typedef struct {
    char data; // 字符数据
    int weight; // 权重
    int parent, lchild, rchild; // 双亲、左孩子、右孩子的下标
} HuffmanNode, *HuffmanTree;

// 创建哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, unordered_map<char, int> &freq_map) {
    int n = freq_map.size();
    if (n <= 1) return;

    int m = 2 * n - 1; // 哈夫曼树的总结点数
    HT = new HuffmanNode[m + 1]; // 分配存储空间

    // 初始化叶子结点
    int i = 1;
    for (auto &entry : freq_map) {
        HT[i].data = entry.first;
        HT[i].weight = entry.second;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        i++;
    }

    // 初始化非叶子结点
    for (; i <= m; i++) {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // 构建哈夫曼树
    for (int i = n + 1; i <= m; i++) {
        int s1, s2;
        int min1 = INT_MAX, min2 = INT_MAX; // 寻找权重最小的两个结点
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

// 创建哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, char **&HC, unordered_map<char, string> &code_map, int n) {
    HC = new char*[n + 1]; // 分配 n 个字符编码的头指针矢量
    char *cd = new char[n]; // 分配临时存放编码的动态数组空间
    cd[n - 1] = '\0'; // 编码结束符

    for (int i = 1; i <= n; i++) {
        int start = n - 1;
        int c = i;
        int f = HT[i].parent;
        while (f != 0) {
            --start; // 回溯一次，start 向前指一个位置
            if (HT[f].lchild == c)
                cd[start] = '0'; // 结点 c 是 f 的左孩子，则生成代码 '0'
            else
                cd[start] = '1'; // 结点 c 是 f 的右孩子，则生成代码 '1'
            c = f;
            f = HT[f].parent; // 继续向上回溯
        }
        // 求出第 i 个字符的编码
        HC[i] = new char[n - start]; // 为第 i 个字符串编码分配空间
        strcpy(HC[i], &cd[start]); // 将求得的编码从临时空间 cd 复制到 HC 的当前行中

        // 将编码存入哈希表中
        code_map[HT[i].data] = string(HC[i]);
    }

    delete[] cd; // 释放临时空间
}

// 获取字符串中每个字符的频率
unordered_map<char, int> getFrequency(const string &str) {
    unordered_map<char, int> freq_map;
    for (char c : str) {
        freq_map[c]++;
    }
    return freq_map;
}

// 将字符串编码为哈夫曼编码
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

    // 输出哈夫曼编码
    cout << "Huffman Codes:" << endl;
    for (auto &entry : code_map) {
        cout << "Character " << entry.first << ": " << entry.second << endl;
    }

    // 将字符串编码为哈夫曼编码
    string encoded_str = encodeString(str, code_map);
    cout << "Encoded String: " << encoded_str << endl;

    // 释放内存
    for (int i = 1; i <= freq_map.size(); i++) {
        delete[] HC[i];
    }
    delete[] HC;
    delete[] HT;

    return 0;
}
