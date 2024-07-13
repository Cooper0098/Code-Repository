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
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> seq;
        seq = nums;
        sort(seq.begin(), seq.end());
        vector<int> aa, bb, arr;
        if (nums.size() == 1)
        {
            return nums;
        }

        for (int i = 1, j =0; i < nums.size(); i = i+2, j ++)
        {
            aa.push_back(seq[i - 1]);
            bb.push_back(seq[i]);
            arr.push_back(bb[j]);
            arr.push_back(aa[j]);
            

        }

            return arr;
    }
};

int main()
{

    return 0;
}