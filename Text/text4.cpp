#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map> // 使用哈希表
#include <stack>         // 使用栈
#include <string>        // 使用字符串
#include <utility>
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
//--------------------------------模板--------------------------------//N叉树

class Solution
{
public:
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>> &grid)

    {
        // flood fill算法 --- bfs算法
        g = grid;
        int cnt = 0;
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (g[i][j] == '1') // 注意是字符串
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void dfs(int x, int y)
    {
        g[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[a].size() && g[a][b] == '1')//注意是字符串
                dfs(a, b);
        }
    }
};