#include <iostream>
using namespace std;

typedef char VerTexType; // ������������
typedef int ArcType;     // ��Ȩֵ��������

#define MVNum 100

typedef struct ArcNode {
    int adjvex;             // �ڽӶ����±�
    ArcType weight;         // ��Ȩֵ
    struct ArcNode *next;   // ָ����һ���ߵ�ָ��
} ArcNode;

typedef struct VNode {
    VerTexType data;        // ������Ϣ
    ArcNode *firstarc;      // ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MVNum];

typedef struct {
    AdjList vertices;   // vertices��ʾ����ĸ�����ʽ
    int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
} ALGraph;

enum Status { OK };

int LocateVex(ALGraph G, VerTexType v) {
    for(int i = 0; i < G.vexnum; ++i) {
        if(G.vertices[i].data == v)
            return i; // ����ҵ����㣬�������±�
    }
    return -1; // ���û�ҵ�������-1
}

Status CreateUDN(ALGraph &G) {
    cout << "�����ܶ��������ܱ���: ";
    cin >> G.vexnum >> G.arcnum; // �����ܶ��������ܱ���
    
    // ������㣬�����ͷ����
    for (int i = 0; i < G.vexnum; ++i) {
        cout << "���붥��" << i << "��ֵ: ";
        cin >> G.vertices[i].data; // ���붥��ֵ
        G.vertices[i].firstarc = NULL; // ��ʼ����ͷ����ָ����
    }

    VerTexType v1, v2;
    ArcType w;
    int i, j;

    // ������ߣ������ڽӱ�
    for (int k = 0; k < G.arcnum; ++k) {
        cout << "����һ�����������������㼰Ȩֵ: ";
        cin >> v1 >> v2 >> w; // ����һ�����������������㼰Ȩֵ
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        
        // ����һ���µı߽��*p1��������붥��vi�ı߱�ͷ��
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j; // �ڽӵ����Ϊj
        p1->weight = w; // ��ȨֵΪw
        p1->next = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        // // ������һ���ԳƵ��µı߽��*p2��������붥��vj�ı߱�ͷ��
        // ArcNode *p2 = new ArcNode;
        // p2->adjvex = i; // �ڽӵ����Ϊi
        // p2->weight = w; // ��ȨֵΪw
        // p2->next = G.vertices[j].firstarc;
        // G.vertices[j].firstarc = p2;
    }

    return OK;
}

int main() {
    ALGraph G;
    Status result = CreateUDN(G);
    if (result == OK) {
        cout << "�����������ɹ���" << endl;
        cout << "�ڽӱ��ʾΪ��" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            cout << "����" << G.vertices[i].data << ": ";
            ArcNode *p = G.vertices[i].firstarc;
            while (p) {
                cout << "(" << G.vertices[i].data << ", " << G.vertices[p->adjvex].data << ", " << p->weight << ") ";
                p = p->next;
            }
            cout << endl;
        }
    } else {
        cout << "����������ʧ�ܣ�" << endl;
    }
    return 0;
}
