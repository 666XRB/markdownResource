#include <iostream>
using namespace std;

#define MaxInt 999999 // 假设MaxInt代表权值的最大值
#define MVNum 100 // 最大顶点数

typedef char VerTexType; // 顶点数据类型
typedef int ArcType; // 边权值数据类型

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

// 创建无向网
Status CreateUDN(AMGraph &G) {
    cout << "输入总顶点数和总边数: ";
    cin >> G.vexnum >> G.arcnum; // 输入总顶点数和总边数
    
    cout << "输入每个顶点的信息:" << endl;
    for(int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i]; // 依次输入每个顶点的信息
    
    // 初始化邻接矩阵
    for(int i = 0; i < G.vexnum; ++i)
        for(int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt; // 将边的权值初始化为一个很大的值
    
    VerTexType v1, v2;
    ArcType w;
    int i, j;

    cout << "输入每条边的信息（顶点1 顶点2 权值）:" << endl;
    for(int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2 >> w; // 输入每条边的信息
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if(i != -1 && j != -1) { // 如果找到了两个顶点
            G.arcs[i][j] = w; // 设置边<v1, v2>的权值
            // G.arcs[j][i] = G.arcs[i][j]; // 设置对称边<v2, v1>的权值
        }
        // 处理顶点没找到的情况
    }
    
    return OK; // 创建图成功，返回OK状态
}

int main() {
    AMGraph G;
    Status result = CreateUDN(G);
    if (result == OK) {
        cout << "有向网创建成功！" << endl;
        cout << "邻接矩阵表示为：" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            for (int j = 0; j < G.vexnum; ++j) {
                cout << G.arcs[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "创建有向网失败！" << endl;
    }
    return 0;
}
