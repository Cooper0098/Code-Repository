#include <algorithm>
#include <vector>
#include<iostream>
#include<unordered_set>

using namespace std; //  图的深度优先遍历算法输出深度优先生成树中的边

vector<vector<int>> graph = {
    {2, 3, 5}, // 节点1的邻居节点
    {1, 4},    // 节点2的邻居节点
    {1, 4},    // 节点3的邻居节点
    {2, 3},    // 节点4的邻居节点
    {1, 6, 7}, // 节点5的邻居节点
    {5, 8},    // 节点6的邻居节点
    {5, 8},    // 节点7的邻居节点
    {6, 7}     // 节点8的邻居节点
};

void deepfirst(int node, unordered_set<int> &visit) // unordered_set存储唯一的元素集合
{
    visit.insert(node );  // 将当前节点标记为已访问
    cout << node << ' '; // 输出当前节点

    // 遍历当前节点的邻居节点
    for (int neighbor : graph[node - 1])
    {
        if (visit.find(neighbor)==visit.end())
        {
            deepfirst(neighbor, visit); // 递归遍历未访问的邻居节点
        }
    }
}
void depthFirstSearch()
{
    unordered_set<int> visited;

    // 对每个节点进行深度优先遍历
    for (int i = 1; i <= graph.size(); i++)
    {
        if (visited.find(i) == visited.end())
        {
            //deepfirst(i, visited);
            deepfirst(i, visited);
        }
    }
}

int main()
{
    cout << "深度优先遍历结果: ";
    depthFirstSearch();
    cout << endl;

    return 0;
}