#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1000000;

int p[N];
int n, m;

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
}