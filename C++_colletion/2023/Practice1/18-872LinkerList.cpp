#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; // 实现一个双链表，双链表初始为空，支持 5种操作：
// 在最左侧插入一个数；
// 在最右侧插入一个数；
// 将第 k个插入的数删除；
// 在第 k个插入的数左侧插入一个数；
// 在第 k个插入的数右侧插入一个数
// 现在要对该链表进行 M次操作，进行完所有操作后，从左到右输出整个链表。

const int N = 100010;
int m;
int e[N], l[N], r[N], idx; // e是值,l是左指针,r是右指针,idx是下标

void init()
{
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}

void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[r[k]] = idx;
    l[idx] = k;
    r[k] = idx;
    idx++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int m, k, x;
    scanf("%d", &m);

    init();
    while (m--)
    {
        string op;
        cin >> op;

        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }

        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << ' ';
        // cout << endl;
    }

    return 0;
}