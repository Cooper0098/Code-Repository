#include <iostream>
#include <cstdio>
#include <vector>

// 使用并查集的思想求解最小生成树问题

int p[100000];

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    else
        return p[x];
}

int uinon(int a, int b,int c)
{
    p[a] = find(p[b]); // 将a的父节点改为b的父节点,及把a-->b
    return p[a];
}

int main()
{
    int n, m;
    std::cout << "输入端点数量n、边的数量m";
    scanf("%d%d", &n, &m);

    return 0;
}