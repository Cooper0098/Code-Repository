#include <iostream>
#include<cstring>
#include <cmath>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <cstdio>

using namespace std; // 模拟散列表     现在要进行N次操作，对于每个询问操作输出对应的结果。  哈希表

const int N = 100003;

int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N; // 计算哈希值
    e[idx] = x;              // 将元素 x 存入数组 e 中
    ne[idx] = h[k];          // 将当前位置的 ne 指向哈希表中已有元素的位置
    h[k] = idx++;            // 更新哈希表中位置 k 的头结点为当前插入元素的位置
}

bool find(int x)
{
    int k = (x % N + N) % N; // 计算哈希值
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
        {
            return true; // 在哈希表中找到了元素 x，返回 true
        }
    }
    return false; // 在哈希表中未找到元素 x，返回 false
}

int main()
{
    int n;
    scanf("%d", &n); // 输入操作的次数

    memset(h, -1, sizeof h); // 初始化哈希表 h，将所有头结点的值设为 -1

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x); // 输入操作类型和操作数

        if (*op == 'I') // 如果操作类型为 'I'，表示插入操作 ---- *op 表示对这个字符数组的第一个字符的引用
        {
            insert(x); // 调用插入函数将 x 插入哈希表
        }
        else // 否则为查找操作
        {
            if (find(x)) // 调用查找函数查找 x 是否存在于哈希表中
            {
                puts("Yes"); // 如果存在，输出 "Yes"
            }
            else
            {
                puts("No"); // 如果不存在，输出 "No"
            }
        }
    }

    return 0;
}