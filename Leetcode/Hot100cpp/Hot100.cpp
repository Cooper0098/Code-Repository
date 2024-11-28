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

    
    }

    //-------------------------C++-------------------------//
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //---------优化

    Solution solution;

    //-------------------------------

    // vector<int> nums1 = {2, 7, 11, 15};
    // int target1 = 9;

    // vector<int> result1 = solution.twoSum(nums1, target1);
    // cout << "示例 输出: ";
    // for (int index : result1)
    // {
    //     cout << index << " ";
    // }
    cout << endl;

    //-------------------------------

    //-------------------------------

    //-------------------------------

    //-------------------------------

    //-------------------------------

    //-------------------------------

    //-------------------------------

    //-------------------------------

    //-------------------------------

    return 0;
}
