#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map> // 使用哈希表
#include <stack>         // 使用栈
#include <string>        // 使用字符串
#include <utility>
#include <cstring> // 有memset将一块内存区域设置为特定的值。 strcpy：复制一个字符串。strcat：连接两个字符串。strlen：获取字符串的长度。strcmp：比较两个字符串。
#include <functional>
using namespace std;        // 别删
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;
//--------------------------------模板--------------------------------//

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
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 1; i <= n; i++)
            a[i] = nums[i - 1];
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 3; len <= n + 2; len++)
            for (int i = 0; i + len - 1 <= n + 1; i++)
            {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++)
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
            }

        return f[0][n + 1];
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 1, 5, 8}; // 示例输入硬币数组

    cout << "Input coins: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int maxCoinsResult = solution.maxCoins(nums); // 调用 maxCoins 方法

    cout << "Maximum coins that can be collected: " << maxCoinsResult << endl;

    return 0;
}