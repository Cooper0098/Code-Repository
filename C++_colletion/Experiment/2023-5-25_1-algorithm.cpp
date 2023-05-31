#include <iostream>
#include <cstdio>
#include <vector>

// 带有压缩规则和加权规则的Find和Union算法
// 并查集
// 将两个集合合并
// 询问两个元素是否在1个集合中

int p[1000000];

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    else 
    return p[x];
}

int uinon(int a,int b)
{
    p[a] = find(p[b]); // 将a的父节点改为b的父节点,及把a-->b
    return p[a];
}


int main()
{
    int n, m;
    std::cout << "数组的大小:\n";
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        p[i] = i;
    }//先定义每个节点的父节点为自己

    std::cout << "需要进行多少次操作:\n";
    scanf("%d", &m);
    while(m--)
    {
        char op[2];
        int a, b;
        std::cout << "请输入操作符(f/u)   (f为查找;u为将第二个数的父节点赋予第一个数):\n"   ;
        scanf("%s", op);
        std::cout << "请输入2个操作数:\n";
        scanf("%d%d", &a, &b);

        if (op[0] == 'u')
        {
            uinon(a, b);
        }

        else
        {
            int c, d;
            c = find(a);
            d = find(b);
            if(find(a) == find(b))
            {
                printf("%d和%d的父节点相同,都为%d\n", a, b, c);
            }
            else
            {
                printf("%d的父节点为%d\n%d的父节点为%d\n", a, c, b, d);
            }

            std::cout << "数组存储的父节点为:";
            for (int i = 1; i <= n;i++)
                {
                std::cout  << p[i] << ' ';
                }
                std::cout << std::endl;
        }
    }

    return 0;
}