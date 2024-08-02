#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map> // 使用哈希表
#include <unordered_set>
#include <stack>  // 使用栈
#include <string> // 使用字符串
#include <utility>
#include <cstring> // 有memset将一块内存区域设置为特定的值。 strcpy：复制一个字符串。strcat：连接两个字符串。strlen：获取字符串的长度。strcmp：比较两个字符串。
#include <functional>
#include <numeric>
#include <ranges>
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//--------------------------------模板--------------------------------// 链表
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//--------------------------------模板--------------------------------// 二叉树

class Solution
{
public:
    ///////////24-7-16
    int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
    {
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask)
        {
            int g[n][n];
            memset(g, 0x3f, sizeof(g));
            for (auto &e : roads)
            {
                int u = e[0], v = e[1], w = e[2];
                if ((mask >> u & 1) & (mask >> v & 1))
                {
                    g[u][v] = min(g[u][v], w);
                    g[v][u] = min(g[v][u], w);
                }
            }
            for (int k = 0; k < n; ++k)
            {
                if (mask >> k & 1)
                {
                    g[k][k] = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < n; ++j)
                        {
                            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                        }
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < n && ok == 1; ++i)
            {
                for (int j = 0; j < n && ok == 1; ++j)
                {
                    if ((mask >> i & 1) & (mask >> j & 1) && g[i][j] > maxDistance)
                    {
                        ok = 0;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }

    ///////////24-7-17
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ans(2);
        unordered_set<int> aa(nums1.begin(), nums1.end());
        unordered_set<int> bb(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();

        for (int x : nums1)
        {
            if (bb.count(x))
            {
                ans[0]++;
            }
        }
        for (int x : nums2)
        {
            if (aa.count(x))
            {
                ans[1]++;
            }
        }

        return ans;
    }

    int fib(int n)
    {
        int ans = 0;

        if (n <= 1)
            return n;
        else
        {
            ans = fib(n - 1) + fib(n - 2);
        }
        return ans;
    }

    int maximumSum(vector<int> &arr) // dp-algorithm
    {
        int ans = INT_MIN, n = arr.size();
        vector<vector<int>> memo(n + 1, vector<int>(2, INT_MIN));
        auto dfs = [&](auto &&dfs, int i, int j) -> int
        {
            if (i < 0)
                return INT_MIN / 2;
            int &res = memo[i][j];
            if (res != INT_MIN)
                return res;
            if (j == 0)
                return res = max(dfs(dfs, i - 1, 0), 0) + arr[i];
            return res = max(dfs(dfs, i - 1, 1) + arr[i], dfs(dfs, i - 1, 0));
        };
        for (int i = 0; i < n; i++)
            ans = max(ans, max(dfs(dfs, i, 0), dfs(dfs, i, 1)));
        return ans;
    }

    int minimumOperations(string num)
    {

        int n = num.size();
        bool found0 = false, found5 = false;

        for (int i = n - 1; i >= 0; i--)
        {
            char c = num[i];

            if (found0 && (c == '0' || c == '5') || found5 && (c == '2' || c == '7'))

            // if (found0 && (c == '0' || '5') || found5 && (c == '2' || c == '7'))
            {
                return n - i - 2;
            }

            if (c == '0')
            {
                found0 = true;
            }
            else if (c == '5')
            {
                found5 = true;
            }
        }
        return n - found0;
    }

    int findValueOfPartition(vector<int> &nums)
    {
        int ans = INT_MAX;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }

        return ans;
    }

    string getSmallestString(string s, int k)
    {
        for (int i = 0; i < s.size(); i++)
        {
            int dis = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dis <= k)
            {
                s[i] = 'a';
                k -= dis;
            }
            else
            {
                s[i] = s[i] - k;
                break;
            }
        }
        return s;
    }

    int calPoints(vector<string> &operations)
    {
        // vector<int> arr;
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < operations.size(); i++)
        {
            string opt = operations[i];
            if (opt == "C")
            {
                stk.pop();
            }
            else if (opt == "D")
            {

                stk.push(stk.top() * 2);
            }
            else if (opt == "+")
            {

                int a = stk.top();
                stk.pop();
                int cum = a + stk.top();
                stk.push(a);
                stk.push(cum);
            }
            else
            {
                int num = stoi(operations[i]);
                stk.push(num);
            }
        }
        while (!stk.empty())
        {
            int a = stk.top();
            ans += a;
            stk.pop();
        }

        return ans;
    }

    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++)
        {
            auto &v = variables[i];
            if (pow(pow(v[0], v[1], 10), v[2], v[3]) == target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

private:
    int pow(int x, int n, int mod) // 快速幂
    {
        int res = 1;
        while (n)
        {
            if (n & 1)
            {
                res = res * x % mod;
            }

            x = x * x % mod;
            n = n >> 1;
        }
        return res;
    }

public:
    double myPow(double x, int N)
    {
        double ans = 1;
        long long n = N;

        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        while (n)
        {
            if (n & 1)
                ans *= x;

            x *= x;
            n >>= 1;
        }
        return ans;
    }

    int maxmiumScore(vector<int> &cards, int cnt)
    {
        int ans = 0, lastodd = 0, lasteven = 0;

        sort(cards.begin(), cards.end(), std::greater<int>());

        for (int i = 0; i < cnt; i++)
        {

            ans += cards[i];
            if (cards[i] % 2 == 1)
                lastodd = cards[i];
            else
                lasteven = cards[i];
        }
        if (ans % 2 == 0)
            return ans;

        int max1 = 0, max2 = 0;

        for (int i = cnt; i < cards.size(); i++)
        {
            if (lasteven && max1 == 0 && cards[i] % 2)
                max1 = ans - lasteven + cards[i];
            if (lastodd && max2 == 0 && cards[i] % 2 == 0)
                max2 = ans - lastodd + cards[i];
        }
        return max(max1, max2);
    }

    // --------------------------------------Cpp-------------------------------------//
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
};

// -----------------------------------------C++--------------------------------------//

int main()
{

    Solution solutionTest;

    // Test case 1
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2};
    vector<int> result1 = solutionTest.findIntersectionValues(nums1_1, nums2_1);
    cout << "Test Case 1: [" << result1[0] << ", " << result1[1] << "]" << endl; // Expected output: [2, 2]

    int a = solutionTest.fib(2);
    cout << a << endl;

    double b = solutionTest.myPow(2, 3);
    cout << b << endl;

    return 0;
}