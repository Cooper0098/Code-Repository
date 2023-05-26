#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 100000; // const 是一个关键字，用于声明常量。通过使用 const 关键字，可以将变量标记为不可修改的，即其值在声明后不能被修改。

int p[N]; // 声明了一个整型数组 p，用于存储每个元素的父节点。
int n, m; // 分别表示并查集的元素数量和操作次数

int find(int x) // 返回x的祖宗节点 + 路径压缩
{
    if(p[x] != x)
    {
        p[x] = find(p[x]); 
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
    {
        p[i] = i;
    }

    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b); //op是小技巧可以避免多输入空格或回车

        if(op[0] == 'M' )
        {
            p[find(a)] = find(b);
        }
        else 
        {
            if (find(a) ==find(b) )
            {
                puts("yes");
            
            }
            else
            {
                puts("no");
            }
        }
    }
    return 0;
}