#include <iostream>
using namespace std;

#define MaxInt 999999 // 假设MaxInt代表权值的最大值
#define MVNum 100 // 最大顶点数

typedef char VerTexType; // 顶点数据类型
typedef bool ArcType; // 边存在与否的数据类型（无向图中可以用布尔值表示边的存在与否）

typedef struct {
    VerTexType vexs[MVNum];       // 顶点数组
    ArcType arcs[MVNum][MVNum];    // 邻接矩阵
    int vexnum, arcnum; // 顶点数和边数
} AMGraph;

// 定义状态
enum Status { OK };

// 查找顶点位置
int LocateVex(AMGraph G, VerTexType v) {
    for(int i = 0; i < G.vexnum; ++i) {
        if(G.vexs[i] == v)
            return i; // 如果找到顶点，返回其下标
    }
    return -1; // 如果没找到，返回-1
}

// 创建无向图
Status CreateUDG(AMGraph &G) {
    cout << "输入总顶点数和总边数: ";
    cin >> G.vexnum >> G.arcnum; // 输入总顶点数和总边数
    
    cout << "输入每个顶点的信息:" << endl;
    for(int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i]; // 依次输入每个顶点的信息
    // 初始化邻接矩阵
    for(int i = 0; i < G.vexnum; ++i)
        for(int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = false; // 将边的存在与否初始化为false
    
    VerTexType v1, v2;
    int i, j;

    cout << "输入每条边是哪两个顶点确定的（顶点1 顶点2）:" << endl;
    for(int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2; // 输入每条边的信息
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if(i != -1 && j != -1) { // 如果找到了两个顶点
            G.arcs[i][j] = true; // 设置边<v1, v2>的存在
            // G.arcs[j][i] = true; // 设置对称边<v2, v1>的存在（无向图）
        }
        // 处理顶点没找到的情况
    }
    
    return OK; // 创建图成功，返回OK状态
}

int main() {
    AMGraph G;
    Status result = CreateUDG(G);
    if (result == OK) {
        cout << "有向图创建成功！" << endl;
        cout << "邻接矩阵表示为：" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            for (int j = 0; j < G.vexnum; ++j) {
                cout << G.arcs[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "创建有向图失败！" << endl;
    }
    return 0;
}
