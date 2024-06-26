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
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
//--------------------------------模板--------------------------------//N叉树

class Solution
{
public:
    long long maxScore(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<long long> f(2, INT_MIN);
        long long res = nums[0];
        f[nums[0] % 2] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pa = nums[i] % 2;
            long long cur = max(f[pa] + nums[i], nums[i] - x + f[1 - pa]);
            res = max(res, cur);
            f[pa] = res;
        }
        
        return res;
    }
};