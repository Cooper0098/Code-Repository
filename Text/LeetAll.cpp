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
    ///////////24-7-16

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
    ///////////24-7-17





};

int main()
{

    Solution solution1;

    // Test case 1
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2};
    vector<int> result1 = solution1.findIntersectionValues(nums1_1, nums2_1);
    cout << "Test Case 1: [" << result1[0] << ", " << result1[1] << "]" << endl; // Expected output: [2, 2]

    

    return 0;
}