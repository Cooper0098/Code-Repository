#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <iostream> // cin/cout
#include <cstdio>   // printf/scanf

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const long long inf = numeric_limits<long long>::max(); // 无穷大
const int N = 100100;                                   // 100100 十万 , 1100100 一百万 , 100100100 一亿

void Mysolve()
{
}

struct Point
{
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //---------优化

    Point *p = new Point{10, 20};
    std::cout << p->x << ", " << p->y << std::endl; // 访问成员
    delete p;                                       // 记得释放内存

    Mysolve();

    return 0;
}
