#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;//最小生成树问题

const int INF = 1e9; // 无穷大值，表示两个顶点之间没有边

int main()
{
    int n, m;
    cin >> n >> m; // 输入顶点数量和边的数量

    vector<vector<int>> graph(n, vector<int>(n, INF)); // 创建邻接矩阵，初始化为无穷大

    // 输入每条边的信息，并更新邻接矩阵
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = weight; // 无向图，更新对称位置
    }

    // Prim's 算法求解最小生成树
    vector<bool> visited(n, false); // 记录顶点是否被访问过
    vector<int> dist(n, INF);       // 记录顶点到最小生成树的距离
    vector<int> parent(n, -1);      // 记录顶点的父节点
    dist[0] = 0;                    // 选择第一个顶点作为起点

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j; // 找到距离最小的未访问顶点
            }
        }

        visited[u] = true; // 将该顶点标记为已访问

        // 更新相邻顶点的距离和父节点
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != INF && graph[u][v] < dist[v])
            {
                dist[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // 输出最小生成树的边
    cout << endl;
    int con = 0;
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] + 1 << " " << i + 1 << " " << graph[i][parent[i]] << endl;
        con = graph[i][parent[i]] + con;
    }
    cout << "生成树的权值之和:" << con;

    return 0;
}
