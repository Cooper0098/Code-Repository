#include <iostream>
#include <algorithm>
// #include <climits>

using namespace std;


//模拟队列



const int N = 1e5 + 10;
int q[N];

int hh = 0;
int tt = -1;

int m;

string s;

void push(int x)
{

    q[++tt] = x;
}

void pop()
{
    hh++;
}

void empty()
{
    if (tt >= hh)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

void query()
{
    cout << q[hh] << endl;
}

int main()
{

    cin >> m;
    while (m--)
    {
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            push(x);
        }

        if (s == "pop")
        {
            pop();
        }

        if (s == "empty")
        {
            empty();
        }

        if (s == "query")
        {
            query();
        }
    }

    return 0;
}