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

class Solution
{
public:
    //---------------------------------------------//

    vector<int> twoSum(vector<int> &nums, int target)
    {
        // https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked
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

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked

        // https://www.acwing.com/video/1381/

        // 将不同状态的字符串, 变成同一个近似的字符串 来判断

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hamap;

        for (auto &x : strs)
        {
            string new_str = x;

            sort(new_str.begin(), new_str.end()); // 给字符串排序

            hamap[new_str].push_back(x);
        }

        for (auto &y : hamap)
        {

            ans.push_back(y.second); //  y 会引用 hamap 中的一个元素，具体说就是一个 pair<string, vector<string>>
        }
        return ans;
    }

    int longestConsecutive(vector<int> &nums)
    {
        // https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked

        int  ans;

        
        
        
        
        return ans;


        
    }

    

    //---------------C++---------------//
    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //---------优化

    Solution solution_USE;

    //-------------------------------

    // vector<int> tx = {1, 2, 2, 4, 5};
    // vector<int> ans = solution_USE.twoSum(tx, 4);

    // for (int &x : ans)
    //     cout << x << endl;

    cout
        << endl;

    //-------------------------------
    cout << (8 - '1' + '0') << endl;

    cout << ('h' - 'a');

    cout << endl;

    //-------------------------------

    cout << ' ' << endl;

    //-------------------------------

    return 0;
}
