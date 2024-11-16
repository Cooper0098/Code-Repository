#include <iostream> // 输入输出 cin/cout
#include <cstdio>   // 输入输出 printf/scanf
//------------------------------------------//
#include <algorithm>     // 算法, 用于操作容器, 可以用于排序、查找、修改和管理数据
#include <vector>        // 容器
#include <string>        // 字符串
#include <stack>         // 栈, 后进先出
#include <queue>         // 队列, 先进先出
#include <unordered_map> // 哈希表, 存储的是键值对. 每个元素由一个键和一个与之关联的值组成, 键是唯一的, 但值可以重复. 适合用于需要根据键快速查找值的场景
#include <unordered_set> // 哈希表,存储的是唯一元素的集合. 每个元素都是值, 不关联任何其他数据. 适合用于需要存储不重复的元素的场景
//------------------------------------------//
#include <memory> // 智能指针
#include <functional>
#include <numeric>
#include <ranges>
#include <cstring> // 有memset将一块内存区域设置为特定的值。 strcpy：复制一个字符串。strcat：连接两个字符串。strlen：获取字符串的长度。strcmp：比较两个字符串。
#include <bitset>
#include <cmath>
using namespace std;

// typedef long long ll;       // 定义long long类型的简写为ll
// typedef long double ld;     // 定义long double类型的简写为ld
// typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
// typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
// typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
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

public:
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

private:
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

public:
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
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < right)
                return true;
            while (stk.size() && stk.top() < nums[i])
            {
                right = max(right, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }

    int maxNumOfMarkedIndices(vector<int> &nums) // 没写好, 最后2个样例没过. 2576. 求出最多标记下标
    {
        int ans = 0;
        sort(nums.begin(), nums.end());

        int jj = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int num2;
            num2 = nums[i] * 2;

            if (num2 <= nums[jj])
            {
                nums[jj] = 0;
                jj--;
                nums[i] = 0;
                ans += 2;
            }
        }
        return ans;
    }

    string removeStars(string s)
    {

        string ans;
        for (char c : s)
        {
            if (c != '*')
            {
                ans.push_back(c);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> ans;
        if (intervals.empty())
            return ans;

        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0], r = intervals[0][1]; // 左右端点

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > r)
            {
                ans.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
            else
            {
                r = max(r, intervals[i][1]);
            }
        }
        ans.push_back({l, r});
        return ans;
    }

    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int ans = 0;

        if (start > destination)
            swap(start, destination);
        int sum = 0;
        for (auto x : distance)
            sum += x;
        for (int i = start; i < destination; i++)
            ans += distance[i];

        ans = min(ans, sum - ans);

        return ans;
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        int ans = 0;
        int n = routes.size();
        unordered_map<int, vector<int>> g;
        vector<int> dist(n, 1e8);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (int x : routes[i])
            {
                if (x == source)
                {
                    dist[i] = 1;
                    q.push(i);
                }
                g[x].push_back(i);
            }
        }
        while (q.size())
        {
            int t = q.front();
            q.pop();
            for (auto x : routes[t])
            {
                if (x == target)
                    return dist[t];
                for (auto y : g[x])
                {
                    if (dist[y] > dist[t] + 1)
                    {
                        dist[y] = dist[t] + 1;
                        q.push(y);
                    }
                }
                g.erase(x);
            }
        }
        return -1;
    }

    int longestContinuousSubstring(string s)
    {

        int ans = 1;
        int left = 1;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] + 1 == s[i])
            {
                left++;
            }
            else
            {
                left = 1;
            }
            ans = max(ans, left);
        }

        return ans;
    }

    int edgeScore(vector<int> &edges)
    {
        int ans = 0;
        int n = edges.size();
        vector<long> score(n);
        for (int i = 0; i < n; i++)
        {
            int t = edges[i];
            score[t] += i;

            if (score[t] > score[ans] || score[t] == score[ans] && t < ans)
                ans = t;
        }
        return ans;
    }

    bool reportSpam(vector<string> &message, vector<string> &bannedWords)
    {

        unordered_set<string> banSet(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (const auto &word : message)
        {
            if (banSet.count(word) > 0)
            {
                cnt++;
            }
            if (cnt >= 2)
            {
                return true;
            }
        }
        return false;
    }

    int maxScoreSightseeingPair(vector<int> &values)
    {

        int ans = 0;
        int maxv = values[0];

        for (int i = 1; i < values.size(); i++)
        {
            ans = max(values[i] - i + maxv, ans);
            maxv = max(maxv, values[i] + i);
        }
        return ans;
    }

    int differenceOfSum(vector<int> &nums)
    {

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i];
            while (nums[i])
            {
                ans -= nums[i] % 10;
                nums[i] /= 10;
            }
        }
        return ans;
    }

    int timeRequiredToBuy(vector<int> &tickets, int k)
    {

        int i = 0, ans = 0;

        while (tickets[k] != 0)
        {
            if (tickets[i] != 0)
            {
                tickets[i]--;
                ans++;
            }

            i = (i + 1) % tickets.size();
        }
        return ans;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int current = 0;
        int cntSum = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            current += gas[i] - cost[i];
            cntSum += gas[i] - cost[i];

            if (current < 0)
            {
                start = (i + 1) % gas.size();

                current = 0;
            }
        }
        if (cntSum < 0)
        {
            return -1;
        }
        return start;
    }

    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int ans = 0;
        int n = nums1.size(), m = nums2.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] % (nums2[j] * k) == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }

    long long numberOfPairs_2(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<int, int> cnt;
        for (int x : nums1)
        {
            if (x % k)
                continue;
            x = x / k;
            for (int d = 1; d * d <= x; d++)
            {
                if (x % d)
                    continue;

                cnt[d]++;
                if (d * d < x)
                    cnt[x / d]++;
            }
        }

        long long ans = 0;
        for (int x : nums2)
        {

            auto it = cnt.find(x);
            ans += (it != cnt.end()) ? cnt[x] : 0;
        }
        return ans;
    }

    int duplicateNumbersXOR(vector<int> &nums)
    {

        unordered_set<int> mapp;

        int ans = 0;

        for (auto x : nums)
        {
            if (mapp.find(x) != mapp.end())
            {
                ans ^= x;
            }
            else
            {
                mapp.emplace(x);
            }
        }
        return ans;
    }

    int superEggDrop(int k, int n) // 扔鸡蛋楼层
    {

        // f[i][j]  用j枚鸡蛋仍i次, 能得到的答案的最大高度 , f[i][j]累加高度, 直到刚好超过高度n

        int f[10010][110];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                f[i][j] = f[i - 1][j - 1] + 1 + f[i - 1][j];
            }
            if (f[i][k] >= n)
                return i;
        }

        return -1;
    }

    int maxHeightOfTriangle(int red, int blue)
    {

        int ans = 0;

        for (int d = 0; d < 2; d++)
        {
            int cnt[2] = {red, blue};
            for (int i = 1, now = d;; i++, now ^= 1)
            {
                if (cnt[now] < i)
                    break;
                ans = max(ans, i);
                cnt[now] -= i;
            }
        }
        return ans;
    }

    double minimumAverage(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<double> container;

        int n = nums.size();

        int l = 0, r = n - 1;
        for (int i = 0; i < (n / 2); i++)
        {
            container.push_back((nums[l] + nums[r]));
            l++, r--;
        }
        sort(container.begin(), container.end());

        return container[0] / 2.0;
    }

    int smallestRangeI(vector<int> &nums, int k)
    {
        int ans = 0;
        // int negK = 0-k;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        ans = nums[n - 1] - nums[0] - 2 * k;
        if (ans <= 0)
            ans = 0;

        return ans;
    }

    int smallestRangeII(vector<int> &nums, int k)
    {

        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; i++)
        {
            int mXnum = max(nums[i - 1] + k, nums[n - 1] - k);
            int mInum = min(nums[0] + k, nums[i] - k);
            ans = min(ans, mXnum - mInum);
        }

        return ans;
    }

    int countCompleteDayPairs(vector<int> &hours)
    {
        int ans = 0;
        int j = 1;

        for (int i = 0; i < hours.size(); i++)
        {
            j = i + 1;
            for (; j < hours.size(); j++)
            {
                if ((hours[i] + hours[j]) % 24 == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }

private:
    vector<int> p;

    int find(int x)
    {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        p.resize(n + 1);

        for (int i = 1; i <= n; i++)
            p[i] = i;

        for (auto &e : edges)
        {
            int a = find(e[0]), b = find(e[1]);
            if (a != b)
                p[a] = p[b];
            else
                return e;
        }
        return {};
    }

public:
    string getSmallestString(string s)
    {

        for (int i = 1; i < s.size(); i++)
        {
            int r = s[i] - '0';
            int l = s[i - 1] - '0';
            if ((l % 2 == 0) ^ (r % 2 == 0))
            {

                continue;
            }
            else
            {

                if (l > r)
                {
                    // char cur;
                    // cur = s[i];

                    // s[i] = s[i - 1];
                    // s[i - 1] = cur;

                    swap(s[i - 1], s[i]);
                    break;
                }
                else
                    continue;
            }
        }
        return s;
    }

    int minChanges(int n, int k)
    {
        int ans = 0; // 初始值设为0

        // 将 n 和 k 转换为 64 位二进制
        std::bitset<64> binaryN(n);
        std::bitset<64> binaryK(k);

        for (int i = 0; i < 64; i++)
        {
            // 如果 binaryN[i] 和 binaryK[i] 不同，并且 binaryN[i] 为 1
            if ((binaryN[i] ^ binaryK[i]) && binaryN[i])
            {
                binaryN[i] = 0; // 将 binaryN[i] 置为 0
                ans++;
            }
        }

        // 检查修改后的 binaryN 是否等于 binaryK
        if (binaryN != binaryK)
            return -1;

        return ans;
    }

    bool MyisPerfer_Square(long long n)
    {
        long long sq = sqrt(n);
        if (sq * sq == n)
            return true;

        return false;
    }

    bool judgeSquareSum(int c)
    {

        bool ans = false;

        long long a;

        for (a = 0; a * a <= c; a++)
        {

            long long n = c - (a * a);

            if (MyisPerfer_Square(n))
            {
                ans = true;
            }
        }

        return ans;
    }

    string losingPlayer(int x, int y)
    {
        string a = "Alice";
        string b = "Bob";
        int flag = 1;

        while (x--)
        {
            y = y - 4;
            if (y >= 0)
            {
                flag *= -1;
            }
        }
        if (flag > 0)
            return b;
        else
            return a;

        return a;
    }

    vector<int> resultsArray(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> ans;
        vector<int> f(n);
        f[0] = 1;

        for (int i = 1; i < n; i++)
        {

            //  f[i] = (nums[i] == nums[i - 1] + 1) ? (f[i - 1] + 1) : 1;

            if (nums[i] == nums[i - 1] + 1)
            {
                f[i] = f[i - 1] + 1;
            }
            else
            {
                f[i] = 1;
            }
        }

        for (int i = k - 1; i < n; i++)
        {
            ans.push_back(f[i] >= k ? nums[i] : -1);
        }
        return ans;
    }

    int singleNonDuplicate(vector<int> &nums)
    {
        nums.push_back(nums.back() + 1);

        int l = 0, r = nums.size() / 2 - 1; // 按照2个一组的组号来二分

        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid * 2] != nums[mid * 2 + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r * 2];
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

class NeighborSum
{
private:
    vector<vector<int>> grid;                       // 存储原始的二维数组
    unordered_map<int, pair<int, int>> positionMap; // 记录每个值的坐标位置

public:
    NeighborSum(vector<vector<int>> &grid)
    {
        this->grid = grid;
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                positionMap[grid[i][j]] = {i, j}; // 存储每个值的坐标
            }
        }
    }

    int adjacentSum(int value)
    {
        if (positionMap.find(value) == positionMap.end())
            return 0;
        auto [x, y] = positionMap[value];
        int n = grid.size();
        int sum = 0;

        // 上下左右相邻位置
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx, dy] : directions)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                sum += grid[nx][ny];
            }
        }
        return sum;
    }

    int diagonalSum(int value)
    {
        if (positionMap.find(value) == positionMap.end())
            return 0;
        auto [x, y] = positionMap[value];
        int n = grid.size();
        int sum = 0;

        // 左上、右上、左下、右下对角线相邻位置
        vector<pair<int, int>> diagonals = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto [dx, dy] : diagonals)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                sum += grid[nx][ny];
            }
        }
        return sum;
    }

    //    使用方法：
    //    NeighborSum* obj = new NeighborSum(grid);
    //    int adjSum = obj->adjacentSum(value);
    //    int diagSum = obj->diagonalSum(value);
};

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
// -----------------------------------Cpp-----------------------------------//


int main()
{

    Solution solutionTest;
    cout << "-------------------------------" << endl;

    int fibnums = solutionTest.fib(3); // 第几个斐波那契数是什么
    cout << fibnums << endl;

    double powNums = solutionTest.myPow(2, 3); // 求解快速幂次方
    cout << powNums << endl;

    cout << "-----------------------------" << endl;

    vector<string> message = {"hello", "world", "leetcode"};
    vector<string> bannedWords = {"world", "hello"};

    bool Spamresult = solutionTest.reportSpam(message, bannedWords);
    cout << boolalpha << Spamresult << endl; // 输出: true

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    cout << "------------------------------" << endl;

    // cout << "--------------------------------" << endl;

    // cout << "--------------------------------" << endl;

    // cout << "--------------------------------" << endl;
    return 0;
}