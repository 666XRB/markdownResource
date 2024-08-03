#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF 999999

// 结构体定义：图的边
typedef struct {
    int start;
    int end;
    int length;
    int speed;
} Edge;

// 结构体定义：图
typedef struct {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_VERTICES];
} Graph;

// 函数声明
Graph createGraph(int num_vertices, int num_edges);
void addEdge(Graph *graph, int start, int end, int length, int speed);
void displayGraph(Graph graph);
int shortestPath(Graph graph, int source, int target, int choice);

// 主函数
int main() {
    Graph city_graph;
    int num_vertices = 4;  // 假设有4个节点
    int num_edges = 11;     // 假设有11条边

    city_graph = createGraph(num_vertices, num_edges);

    // 添加边信息
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

    printf("城市路网图信息：\n");
    displayGraph(city_graph);

    // 用户输入出发地和目的地
    int source, target;
    printf("\n请输入出发地点 (0-%d)：", num_vertices - 1);
    scanf("%d", &source);
    printf("请输入目的地点 (0-%d)：", num_vertices - 1);
    scanf("%d", &target);

    if (source < 0 || source >= num_vertices || target < 0 || target >= num_vertices) {
        printf("输入的地点不在范围内！\n");
        return 1;
    }

    // 用户选择路线规划方式
    int choice;
    printf("请选择路线规划方式 (1. 最短路径 2. 最省时路径)：");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("无效的选择！\n");
        return 1;
    }

    // 计算路径并输出结果
    int length = shortestPath(city_graph, source, target, choice);
    if (choice == 1) {
        printf("最短路径长度为：%d\n", length);
    } else {
        printf("最省时路径长度为：%d\n", length);
    }

    return 0;
}

// 创建图
Graph createGraph(int num_vertices, int num_edges) {
    Graph graph;
    graph.num_vertices = num_vertices;
    graph.num_edges = num_edges;
    return graph;
}

// 添加边
void addEdge(Graph *graph, int start, int end, int length, int speed) {
    if (graph->num_edges >= MAX_VERTICES) {
        printf("边的数量超过了最大限制！\n");
        return;
    }
    graph->edges[graph->num_edges].start = start;
    graph->edges[graph->num_edges].end = end;
    graph->edges[graph->num_edges].length = length;
    graph->edges[graph->num_edges].speed = speed;
    graph->num_edges++;
}

// 显示图的信息
void displayGraph(Graph graph) {
    printf("节点数：%d，边数：%d\n", graph.num_vertices, graph.num_edges);
    printf("边的信息：\n");
    printf("起点 终点 长度 速度\n");
    for (int i = 0; i < graph.num_edges; i++) {
        printf("%d     %d    %d    %d\n", graph.edges[i].start, graph.edges[i].end, graph.edges[i].length, graph.edges[i].speed);
    }
}

// 计算最短路径或最省时路径
int shortestPath(Graph graph, int source, int target, int choice) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int i, v, w, min_dist;

    // 初始化
    for (i = 0; i < graph.num_vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    // 计算最短路径或最省时路径
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
