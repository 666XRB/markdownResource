#include <iostream>
using namespace std;

typedef char VerTexType; // 顶点数据类型
#define MVNum 100

typedef struct ArcNode {
    int adjvex;             // 邻接顶点下标
    struct ArcNode *next;   // 指向下一条边的指针
} ArcNode;

typedef struct VNode {
    VerTexType data;        // 顶点信息
    ArcNode *firstarc;      // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum];

typedef struct {
    AdjList vertices;   // vertices表示顶点的复数形式
    int vexnum, arcnum; // 图的当前顶点数和弧数
} ALGraph;

enum Status { OK };

int LocateVex(ALGraph G, VerTexType v) {
    for(int i = 0; i < G.vexnum; ++i) {
        if(G.vertices[i].data == v)
            return i; // 如果找到顶点，返回其下标
    }
    return -1; // 如果没找到，返回-1
}

Status CreateUDG(ALGraph &G) {
    cout << "输入总顶点数和总边数: ";
    cin >> G.vexnum >> G.arcnum; // 输入总顶点数和总边数
    
    // 输入各点，构造表头结点表
    for (int i = 0; i < G.vexnum; ++i) {
        cout << "输入顶点" << i << "的值: ";
        cin >> G.vertices[i].data; // 输入顶点值
        G.vertices[i].firstarc = NULL; // 初始化表头结点的指针域
    }


    VerTexType v1, v2;
    int i, j;

    // 输入各边，构造邻接表
    for (int k = 0; k < G.arcnum; ++k) {
        cout << "输入一条边依附的两个顶点: ";
        cin >> v1 >> v2; // 输入一条边依附的两个顶点
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        
        // 生成一个新的边结点*p1，将其插入顶点vi的边表头部
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j; // 邻接点序号为j
        p1->next = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        // // 生成另一个对称的新的边结点*p2，将其插入顶点vj的边表头部
        // ArcNode *p2 = new ArcNode;
        // p2->adjvex = i; // 邻接点序号为i
        // p2->next = G.vertices[j].firstarc;
        // G.vertices[j].firstarc = p2;
    }

    return OK;
}

int main() {
    ALGraph G;
    Status result = CreateUDG(G);
    if (result == OK) {
        cout << "有向图创建成功！" << endl;
        cout << "邻接表表示为：" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            cout << "顶点 " << G.vertices[i].data << ": ";
            ArcNode *p = G.vertices[i].firstarc;
            while (p) {
                cout << G.vertices[p->adjvex].data << " ";
                p = p->next;
            }
            cout << endl;
        }
    } else {
        cout << "创建有向图失败！" << endl;
    }
    return 0;
}
