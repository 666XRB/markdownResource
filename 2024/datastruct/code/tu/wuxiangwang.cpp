#include <iostream>
using namespace std;

#define MaxInt 999999 // ����MaxInt����Ȩֵ�����ֵ
#define MVNum 100 // ��󶥵���

typedef char VerTexType; // ������������
typedef int ArcType; // ��Ȩֵ��������

typedef struct {
    VerTexType vexs[MVNum];       // ��������
    ArcType arcs[MVNum][MVNum];    // �ڽӾ���
    int vexnum, arcnum; // �������ͱ���
} AMGraph;

// ����״̬
enum Status { OK };

// ���Ҷ���λ��
int LocateVex(AMGraph G, VerTexType v) {
    for(int i = 0; i < G.vexnum; ++i) {
        if(G.vexs[i] == v)
            return i; // ����ҵ����㣬�������±�
    }
    return -1; // ���û�ҵ�������-1
}

// ����������
Status CreateUDN(AMGraph &G) {
    cout << "�����ܶ��������ܱ���: ";
    cin >> G.vexnum >> G.arcnum; // �����ܶ��������ܱ���
    
    cout << "����ÿ���������Ϣ:" << endl;
    for(int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i]; // ��������ÿ���������Ϣ
    
    // ��ʼ���ڽӾ���
    for(int i = 0; i < G.vexnum; ++i)
        for(int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt; // ���ߵ�Ȩֵ��ʼ��Ϊһ���ܴ��ֵ
    
    VerTexType v1, v2;
    ArcType w;
    int i, j;

    cout << "����ÿ���ߵ���Ϣ������1 ����2 Ȩֵ��:" << endl;
    for(int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2 >> w; // ����ÿ���ߵ���Ϣ
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if(i != -1 && j != -1) { // ����ҵ�����������
            G.arcs[i][j] = w; // ���ñ�<v1, v2>��Ȩֵ
            // G.arcs[j][i] = G.arcs[i][j]; // ���öԳƱ�<v2, v1>��Ȩֵ
        }
        // ������û�ҵ������
    }
    
    return OK; // ����ͼ�ɹ�������OK״̬
}

int main() {
    AMGraph G;
    Status result = CreateUDN(G);
    if (result == OK) {
        cout << "�����������ɹ���" << endl;
        cout << "�ڽӾ����ʾΪ��" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            for (int j = 0; j < G.vexnum; ++j) {
                cout << G.arcs[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "����������ʧ�ܣ�" << endl;
    }
    return 0;
}
