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

class MagicDictionary
{
public:
    const int N = 10010;
    int son[10010][26];
    int idx;
    bool is_end[10010];

    void insert(string &s)
    {
        int p = 0;
        for (auto c : s)
        {
            int u = c - 'a';
            if (!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
        }
        is_end[p] = true;
    }

    MagicDictionary()
    {
        memset(son, 0, sizeof son);
        idx = 0;
        memset(is_end, 0, sizeof is_end);
    }

    void buildDict(vector<string> dictionary)
    {
        for (auto &s : dictionary)
            insert(s);
    }

    bool dfs(string &s, int p, int u, int c)
    {
        if (is_end[p] && u == s.size() && c == 1)
            return true;
        if (c > 1 || u == s.size())
            return false;
        for (int i = 0; i < 26; i++)
        {
            if (!son[p][i])
                continue;
            if (dfs(s, son[p][i], u + 1, c + (s[u] - 'a' != i)))
                return true;
        }
        return false;
    }

    bool search(string searchWord)
    {
        return dfs(searchWord, 0, 0, 0);
    }
};

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

private:
    bool ans = false;
    const int P = 149, Q = 151, MOD = 1e6 + 7, U = 10000;
    int T = INT_MIN;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 12345;
        int left = dfs(root->left), right = dfs(root->right);
        int x = (root->val % MOD + MOD) % MOD;
        if (left == T || right == T)
            ans = true;
        return (x + left * P % MOD + right * Q + U) % MOD;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        T = dfs(subRoot);
        if (T == dfs(root))
            ans = true;
        return ans;
    }

public:
    int findIntegers(int n)
    {
        vector<int> num;
        while (n)
            num.push_back(n % 2), n /= 2;

        vector<vector<int>> f(num.size() + 1, vector<int>(2));
        f[1][0] = f[1][1] = 1;
        for (int i = 2; i <= num.size(); i++)
        {
            f[i][0] = f[i - 1][0] + f[i - 1][1];
            f[i][1] = f[i - 1][0];
        }
        int res = 0;

        for (int i = num.size(), last = 0; i; i--)
        {
            int x = num[i - 1];
            if (x)
            {
                res += f[i][0];
                if (last)
                    return res;
            }
            last = x;
        }
        return res + 1;
    }

    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return nums2[0] - nums1[0];
    }

    bool isSubsequence(string s, string t)
    {
        int k = 0;
        for (auto c : t)
        {
            if (k < s.size() && c == s[k])
                k++;
        }

        return k == s.size();
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)

            for (int j = 1; j <= m; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i - 1] == text2[j - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }

        return f[n][m];
    }

    bool isArraySpecial(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int cnt = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int a = nums[i] + nums[i - 1];
            if (a % 2 != 0)
                cnt++;
        }
        if (cnt == nums.size() - 1)
            return true;
        return false;
    }

    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<bool> ans;
        vector<int> meber;
        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < queries[0].size(); j++)
            {
                meber.push_back(queries[i][j]);
            }
        }
        for (int i = 0; i < meber.size(); i += 2)
        {
            int l, r;
            l = meber[i];
            r = meber[i + 1];
            vector<int> newnum;
            for (int j = l; j <= r; j++)
            {
                newnum.push_back(nums[j]);
            }
            bool a = isArraySpecial(newnum);
            ans.push_back(a);
        }
        return ans;
    }

    bool checkRecord(string s)
    {
        bool ans = true;
        int cntA = 0;
        s = s + "AA";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                cntA++;
            }
            if (cntA >= 2)
                return false;
            if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
                return false;
        }

        return ans;
    }

    long long findMaximumNumber(long long k, int x)
    {
        long long num = 0, pre1 = 0;
        for (long long i = __lg((k + 1) << x); i >= 0; i--)
        {
            long long cnt = (pre1 << i) + (i / x << i >> 1);
            if (cnt <= k)
            {
                k -= cnt;
                num |= 1LL << i;
                pre1 += (i + 1) % x == 0;
            }
        }
        return num - 1;
    }

    int findPermutationDifference(string s, string t)
    {
        int ans = 0;
        int n = s.size();
        unordered_map<char, int> myMap;

        for (size_t i = 0; i < n; i++)
        {
            myMap[s[i]] = static_cast<int>(i);
        }
        for (int i = 0; i < n; i++)
        {

            int cnt = myMap[t[i]];

            ans += abs(cnt - i);
        }
        return ans;
    }

    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        bool ans = true;

        for (int i = 0; i < grid.size(); i++)

            for (int j = 0; j < grid[i].size(); j++)
            {

                if (i + 1 < grid.size() && grid[i][j] != grid[i + 1][j])
                {
                    ans = false;
                }
                if (j + 1 < grid[i].size() && grid[i][j] == grid[i][j + 1])
                {
                    ans = false;
                }
            }

        return ans;
    }

    bool canMakeSquare(vector<vector<char>> &grid)
    {
        int ans = false;
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
            {

                int s1 = grid[i][j];
                int s2 = grid[i][j + 1];
                int s3 = grid[i + 1][j];
                int s4 = grid[i + 1][j + 1];
                int total = s1 + s2 + s3 + s4;
                if (total == 4 * 'B' || total == 4 * 'W' || total == 3 * 'B' + 'W' || total == 3 * 'W' + 'B')
                {
                    return true;
                }
            }

        return ans;
    }

    long long maxStrength(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        long all = 1;
        vector<long> negtive;
        vector<int> zero;
        vector<long> unnegtive;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                all *= nums[i];
            else
                zero.push_back(nums[i]);

            if (nums[i] < 0)
                negtive.push_back(nums[i]);
            if (nums[i] > 0)
                unnegtive.push_back(nums[i]);
        }
        if (all >= 0 && nums.size() == 1)
            return nums[0];

        if (all >= 0 && zero.size() > 0 && unnegtive.size() == 0 &&
            negtive.size() % 2 != 0)
        {
            return 0;
        }
        if (nums.size() == zero.size())
            return 0;

        if (all < 0)
        {
            if (negtive.size() == 1 && nums.size() == 1)
                return nums[0];
            int n = negtive.size();
            all = all / negtive[n - 1];
            if (negtive.size() == 1 && zero.size() > 0 &&
                unnegtive.size() == 0)
            {
                all = 0;
            }
        }
        return all;
    }

    string clearDigits(string s)
    {
        string stk;
        for (char c : s)
        {
            if (isdigit(c))
                stk.pop_back();
            else
                stk.push_back(c);
        }
        return stk;
    }

    vector<int> sortedSquares(vector<int> &nums)
    {
        int idx = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                idx = i;
                break;
            }
        }
        for (int i = idx - 1; i >= 0; i--)
        {
            ans.push_back(nums[i] * nums[i]);
        }
        for (int i = idx; i < nums.size(); i++)
        {
            ans.push_back(nums[i] * nums[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *left = nullptr, *right = nullptr;
        left = head->next;
        while (left) // 遍历链表
        {
            right = left->next;
            while (right->val)
            {
                left->val += right->val;
                right = right->next;
            }
            left->next = right->next;
            left = left->next;
        }
        return head->next;
    }

    bool find132pattern(vector<int> &nums)
    {
        int right = INT_MIN;
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0;i--)
        {
            if(nums[i] < right )
                return true;
                while(stk.size()&& stk.top() <nums[i] )
                {
                    right = max(right, stk.top());
                    stk.pop();
                }
                stk.push(nums[i]);
        }
        return false;
    }

    // -----------------------------------Cpp-----------------------------------//
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
    /////////////
    int sss = 'B';
    cout << "sss = " << 4 * sss << endl;
    /////////////////////
    cout << endl;
    char ch1 = '5';
    char ch2 = 'a';
    char ch3 = '0';

    // 检查字符是否为数字
    std::cout << ch1 << " is digit? " << (isdigit(ch1) ? "Yes" : "No") << std::endl;
    std::cout << ch2 << " is digit? " << (isdigit(ch2) ? "Yes" : "No") << std::endl;
    std::cout << ch3 << " is digit? " << (isdigit(ch3) ? "Yes" : "No") << std::endl;

    return 0;
}