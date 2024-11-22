#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <iostream>      // cin/cout
#include <cstdio>        // printf/scanf

using namespace std;

typedef long long ll;       // long long为ll
typedef long double ld;     // long doubleld
typedef pair<int, int> pii; // pair<int, int>pii
typedef pair<ll, ll> pll;   // pair<ll, ll>pll
typedef vector<int> vi;     // vector<int>vi

const long long inf = numeric_limits<long long>::max(); // 无穷大
const int N = 100100; // 100100 十万 , 1100100 一百万 , 100100100 一亿


//-------------------------------------------------------------------------//

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int n, int H, int A, vector<int> h, vector<int> a)
{
    // write code here

    int ans = 0;

    unordered_map<int, int> hashMap;

    vector<int> Maxnum;

    for (int i = 0; i < n; i++)
    {
        Maxnum.push_back(max(h[i], a[i]));
    }

    for (int i = 0; i < n; i++)
    {
        hashMap[i] = Maxnum[i];
    }

    auto E_min = min(H, A);

    auto X_maxxxx = max_element(hashMap.begin(), hashMap.end());

    for (auto x = hashMap.begin(); x != hashMap.end(); ++x)
    {
        if (E_min < x->second)
        {
            hashMap.erase(x->first);
        }
    }

    int haN = hashMap.size();
    // cout << haN << endl;
    for (int i = 0; i < haN; i++)
    {
        auto X_max = max_element(hashMap.begin(), hashMap.end());

        int idx = X_max->first, b = X_max->second;

        if (E_min < b)
        {
            // hashMap.erase(idx);
            continue;

            // X_max = max_element(hashMap.begin(), hashMap.end());
            // b = X_max->second;
        }

        // if (E_min >= b)
        else
        {
            E_min = min(h[idx], a[idx]);
            ans++;
            //   cout << E_min << endl;
            //   cout << idx + 100 << endl;
            hashMap.erase(idx);
        }
    }

    return ans;
}

int main()
{
    cout << (solution(3, 4, 5, {1, 2, 3}, {3, 2, 1}) == 1) << endl;
    cout << (solution(5, 10, 10, {6, 9, 12, 4, 7}, {8, 9, 10, 2, 5}) == 2) << endl;
    cout << (solution(4, 20, 25, {10, 15, 18, 22}, {12, 18, 20, 26}) == 3) << endl;
    return 0;
}