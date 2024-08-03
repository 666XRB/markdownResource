#include <iostream>
using namespace std;

#define MaxInt 999999 // ����MaxInt����Ȩֵ�����ֵ
#define MVNum 100 // ��󶥵���

typedef char VerTexType; // ������������
typedef bool ArcType; // �ߴ��������������ͣ�����ͼ�п����ò���ֵ��ʾ�ߵĴ������

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

// ��������ͼ
Status CreateUDG(AMGraph &G) {
    cout << "�����ܶ��������ܱ���: ";
    cin >> G.vexnum >> G.arcnum; // �����ܶ��������ܱ���
    
    cout << "����ÿ���������Ϣ:" << endl;
    for(int i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i]; // ��������ÿ���������Ϣ
    // ��ʼ���ڽӾ���
    for(int i = 0; i < G.vexnum; ++i)
        for(int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = false; // ���ߵĴ�������ʼ��Ϊfalse
    
    VerTexType v1, v2;
    int i, j;

    cout << "����ÿ����������������ȷ���ģ�����1 ����2��:" << endl;
    for(int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2; // ����ÿ���ߵ���Ϣ
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if(i != -1 && j != -1) { // ����ҵ�����������
            G.arcs[i][j] = true; // ���ñ�<v1, v2>�Ĵ���
            // G.arcs[j][i] = true; // ���öԳƱ�<v2, v1>�Ĵ��ڣ�����ͼ��
        }
        // ������û�ҵ������
    }
    
    return OK; // ����ͼ�ɹ�������OK״̬
}

int main() {
    AMGraph G;
    Status result = CreateUDG(G);
    if (result == OK) {
        cout << "����ͼ�����ɹ���" << endl;
        cout << "�ڽӾ����ʾΪ��" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            for (int j = 0; j < G.vexnum; ++j) {
                cout << G.arcs[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "��������ͼʧ�ܣ�" << endl;
    }
    return 0;
}
