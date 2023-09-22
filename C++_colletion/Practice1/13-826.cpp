#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <cstdio>

using namespace std; // 实现一个单链表，链表初始为空，支持三种操作：向链表头插入一个数；
// 删除第 k个插入的数后面的数；
// 在第 k个插入的数后插入一个数。现在要对该链表进行m次操作，进行完所有操作后，从头到尾输出整个链表。
const int N = 100203;

int head, e[N], ne[N], idx;
int cnt = 0;

void init()
{
    head = -1;
    idx = 0;
}

void insert(int k, int x) // 将x加到下标是k的点后面
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
void add_head(int x)
{
    e[idx] = x;
    ne[idx] = head; // 存的是下一个的指针
    head = idx;     // 更新新的头节点
    idx++;
}

void del(int k) // 将下标是k的点删除
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;
    init();

    while(m--)
    {
        int k, x;
        char op[2];

        cin >> op;

        if (*op == 'H')
        {
            cin >> x;
            add_head(x);
        }

        else if(*op== 'D')
        {
            cin >> k;
            if (!k)
            {
                head = ne[head];
            }
            else
            {
                del(k - 1);

            }

        }
        else
        {
            cin >> k >> x;
            insert(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) // 遍历链表，从头到尾输出链表中的所有元素 ;i = ne[i]能够指向链表的下一个
    {
        cout << e[i] << ' ';
    }
    cout << endl;

    return 0;
}