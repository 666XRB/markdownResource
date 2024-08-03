#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF 999999

// �ṹ�嶨�壺ͼ�ı�
typedef struct {
    int start;
    int end;
    int length;
    int speed;
} Edge;

// �ṹ�嶨�壺ͼ
typedef struct {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_VERTICES];
} Graph;

// ��������
Graph createGraph(int num_vertices, int num_edges);
void addEdge(Graph *graph, int start, int end, int length, int speed);
void displayGraph(Graph graph);
int shortestPath(Graph graph, int source, int target, int choice);

// ������
int main() {
    Graph city_graph;
    int num_vertices = 4;  // ������4���ڵ�
    int num_edges = 11;     // ������11����

    city_graph = createGraph(num_vertices, num_edges);

    // ��ӱ���Ϣ
    addEdge(&city_graph, 0, 1, 12, 40);
    addEdge(&city_graph, 0, 2, 8, 50);
    addEdge(&city_graph, 0, 3, 6, 60);
    addEdge(&city_graph, 1, 2, 5, 20);
    addEdge(&city_graph, 1, 3, 8, 25);
    addEdge(&city_graph, 2, 3, 7, 55);
    addEdge(&city_graph, 2, 0, 5, 20);
    addEdge(&city_graph, 2, 1, 6, 20);
    addEdge(&city_graph, 3, 0, 10, 40);
    addEdge(&city_graph, 3, 1, 6, 30);
    addEdge(&city_graph, 3, 2, 8, 25);

    printf("����·��ͼ��Ϣ��\n");
    displayGraph(city_graph);

    // �û���������غ�Ŀ�ĵ�
    int source, target;
    printf("\n����������ص� (0-%d)��", num_vertices - 1);
    scanf("%d", &source);
    printf("������Ŀ�ĵص� (0-%d)��", num_vertices - 1);
    scanf("%d", &target);

    if (source < 0 || source >= num_vertices || target < 0 || target >= num_vertices) {
        printf("����ĵص㲻�ڷ�Χ�ڣ�\n");
        return 1;
    }

    // �û�ѡ��·�߹滮��ʽ
    int choice;
    printf("��ѡ��·�߹滮��ʽ (1. ���·�� 2. ��ʡʱ·��)��");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("��Ч��ѡ��\n");
        return 1;
    }

    // ����·����������
    int length = shortestPath(city_graph, source, target, choice);
    if (choice == 1) {
        printf("���·������Ϊ��%d\n", length);
    } else {
        printf("��ʡʱ·������Ϊ��%d\n", length);
    }

    return 0;
}

// ����ͼ
Graph createGraph(int num_vertices, int num_edges) {
    Graph graph;
    graph.num_vertices = num_vertices;
    graph.num_edges = num_edges;
    return graph;
}

// ��ӱ�
void addEdge(Graph *graph, int start, int end, int length, int speed) {
    if (graph->num_edges >= MAX_VERTICES) {
        printf("�ߵ�����������������ƣ�\n");
        return;
    }
    graph->edges[graph->num_edges].start = start;
    graph->edges[graph->num_edges].end = end;
    graph->edges[graph->num_edges].length = length;
    graph->edges[graph->num_edges].speed = speed;
    graph->num_edges++;
}

// ��ʾͼ����Ϣ
void displayGraph(Graph graph) {
    printf("�ڵ�����%d��������%d\n", graph.num_vertices, graph.num_edges);
    printf("�ߵ���Ϣ��\n");
    printf("��� �յ� ���� �ٶ�\n");
    for (int i = 0; i < graph.num_edges; i++) {
        printf("%d     %d    %d    %d\n", graph.edges[i].start, graph.edges[i].end, graph.edges[i].length, graph.edges[i].speed);
    }
}

// �������·������ʡʱ·��
int shortestPath(Graph graph, int source, int target, int choice) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int i, v, w, min_dist;

    // ��ʼ��
    for (i = 0; i < graph.num_vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    // �������·������ʡʱ·��
    for (i = 0; i < graph.num_vertices - 1; i++) {
        min_dist = INF;
        for (w = 0; w < graph.num_vertices; w++) {
            if (!visited[w] && dist[w] < min_dist) {
                v = w;
                min_dist = dist[w];
            }
        }
        visited[v] = 1;

        for (w = 0; w < graph.num_edges; w++) {
            if (graph.edges[w].start == v) {
                int cost;
                if (choice == 1) {
                    cost = graph.edges[w].length;
                } else {
                    cost = (int)((float)graph.edges[w].length / graph.edges[w].speed * 60);
                }
                if (!visited[graph.edges[w].end] && dist[graph.edges[w].end] > dist[v] + cost) {
                    dist[graph.edges[w].end] = dist[v] + cost;
                }
            }
        }
    }

    return dist[target];
}
