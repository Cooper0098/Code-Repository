#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map> // 使用哈希�?
#include <stack>         // 使用�?
#include <string>        // 使用字符�?
#include <utility>
#include <cstring> // 有memset将一块内存区域设置为特定的值�? strcpy：复制一个字符串。strcat：连接两个字符串。strlen：获取字符串的长度。strcmp：比较两个字符串�?
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
//--------------------------------妯℃�?--------------------------------// 浜屽弶鏍�?

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        // int ii, jj = 0;
        int n = nums.size();
        if(n == 1)
        {
            return 0;
        }
        int lcnt = 0;
        int rcnt = 0 ;
        for (int i = 1; i < n; i++) {
            rcnt += nums[i];
        }
        lcnt = rcnt - nums[n - 1] + nums[0];

        if (rcnt == 0) {
            ans = 0;
            return ans;
        }
        if (lcnt == 0) {
            ans = n - 1;
            return ans;
        }


        int cnt = 0;
        vector<int> arr;
        for (int i = 1; i < n - 1; i++) {
            rcnt = rcnt - nums[i];
            cnt = cnt + nums[i - 1];
            if (cnt == rcnt) {

                arr.push_back(i);
                // ans = arr[0];
            }
            if(!arr.empty())
            {
                ans = arr[0];
                return ans;
            }
            // return ans;
        }

        

        return -1;
    }
};

int main()
{
    Solution a;
     vector<int> nums = {-1, -1, 1, 1, 0, 0};
    int result = a.pivotIndex(nums);
    cout << "Pivot Index: " << result << endl;


    return 0;
}