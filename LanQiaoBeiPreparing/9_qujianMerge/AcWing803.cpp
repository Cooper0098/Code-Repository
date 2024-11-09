#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

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