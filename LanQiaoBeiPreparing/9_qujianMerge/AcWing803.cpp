
#pragma GCC optimize("O2")

#include<bits/stdc++.h>
#include <iostream>      // cin/cout
#include <cstdio>        // printf/scanf
#include <algorithm>
#include <vector>        // 容器
#include <string>        // 字符串
#include <stack>         // 栈
#include <queue>         // 队列
#include <unordered_map> // 哈希表
#include <unordered_set> // 哈希表 set
#include <memory>        // 智能指针
#include <functional>
#include <numeric>
#include <ranges>
#include <cstring> 
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;       // long long为ll
typedef long double ld;     // long doubleld
typedef pair<int, int> pii; // pair<int, int>pii
typedef pair<ll, ll> pll;   // pair<ll, ll>pll
typedef vector<int> vi;     // vector<int>vi

const long long inf = numeric_limits<long long>::max(); // 无穷大




using namespace std; // https://www.acwing.com/problem/content/805/

typedef pair<int, int> Pii;

vector<Pii> container;

const int N = 100100;

void merge(vector<Pii> &segment)
{
    vector<Pii> ans;

    sort(segment.begin(), segment.end()); // 默认排序左端点

    int start = -2e9, end = -2e9;

    for (auto seg : segment)
    {
        if (end < seg.first)
        {
            if (start != -2e9) // 没有交集
                ans.push_back({start, end});
            start = seg.first, end = seg.second;
        }
        else
        {
            end = max(end, seg.second); //合并情况不添加ans
        }
    }
    if (start != -2e9) // 防止vector是空集 , 空集就是也是一个区间
        ans.push_back({start, end});
    segment = ans;
}

int main()
{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        int l, r;
        cin >> l >> r;
        container.push_back({l, r});
    }

    merge(container);

    cout << container.size();
}