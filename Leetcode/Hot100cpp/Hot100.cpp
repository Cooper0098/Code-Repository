#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#include <iostream> // cin/cout
#include <cstdio>   // printf/scanf
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
const int N = 100100;                                   // 100 百 , 100100 十万 , 1100100 一百万 , 100100100 一亿

//-------------------------------------------//

class Solution
{
public:
    //---------------------------------------------//

    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;

        int n = nums.size();

        unordered_map<int, int> hashmap;

        for (int i = 0; i < n; i++)
        {
            hashmap[i] = nums[i];
        }
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            int x = target - nums[i];
            hashmap.erase(i);

            if (flag == true)
            {
                for (const auto &pair : hashmap)
                {
                    if (pair.second == x)
                    {
                        ans.push_back(i);
                        ans.push_back(pair.first);
                        flag = false;
                    }
                }
            }
            hashmap[i] = nums[i];
        }

        return ans;
    }

    //-------------------------C++-------------------------//
};

int main()
{
    cout << "aaaaaaaaa1111" << endl;
}

//-----------------------------------------------------------------------------//
