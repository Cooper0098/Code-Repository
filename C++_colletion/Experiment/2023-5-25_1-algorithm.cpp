#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// 带有压缩规则和加权规则的Find和Union算法
// 并查集
// 将两个集合合并
// 询问两个元素是否在1个集合中

int path[10000];


int find(int x)
{
    if (path[x] != x)
    {
        path[x] = find(path[x]);
    }
    return path[x];
}

int union_ (int a,int b)
{
    path[a] = find(path[b]);
    return path[a];
}

int main()
{
    for (int i = 0; i <= 10000; i++)
    {
        path[i] = i;
    }
    path[3] = 0;
    int n;
    cin >> n;

    cout << "n的根节点:"<<find(n) << endl;
    int a, b;
    cout << "hebin" << endl;
    cin >> a >> b;
    cout << union_(a,b);


    return 0;
}