#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; // 实现一个栈，栈初始为空，支持四种操作：push x – 向栈顶插入一个数 x；pop – 从栈顶弹出一个数；empty – 判断栈是否为空；query – 查询栈顶元素。

//先进后出

const int N =100010;

int stk[N], tt=0;

void add(int x)
{
    stk[++tt] = x;
}

void pop()
{
    tt--;
}

void emp()
{
    if(tt>0)
    {
        cout << "NO"<< endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

void q()
{
    cout << stk[tt] << endl;
}

int main()
{
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m;i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            add(x);
        }
        else if (op == "pop")
        {
            pop();
        }
        else if (op == "empty")
        {
            emp();
        }
        else
        {
            q();
        }
        
    }

        return 0;
}