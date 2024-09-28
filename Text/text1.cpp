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
// #include "example.h"
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// //--------------------------------模板--------------------------------// 链表
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(1), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// //--------------------------------模板--------------------------------// 二叉树
// class Solution
// {
// public:
//     vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
//     {

//         vector<int> ans(2);
//         unordered_set<int> aa(nums1.begin(),nums1.end());
//         unordered_set<int> bb(nums2.begin(), nums2.end());
//         int n = nums1.size();
//         int m = nums2.size();

//         for (int x : nums1)
//         {
//             if(bb.count(x))
//             {
//                 ans[0]++;
//             }
//         }
//         for (int x: nums2)
//         {
//             if(aa.count(x))
//             {
//                 ans[1]++;
//             }
//         }

//             return ans;
//     }
// };

#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num; // 存储数字的栈
stack<int> op; // 存储操作符的栈


void eval()
{
    auto b = num.top(); // 取出栈顶的数字b
    num.pop(); // 弹出栈顶的数字b
    auto a = num.top(); // 取出栈顶的数字a
    num.pop(); // 弹出栈顶的数字a
    auto c = op.top(); // 取出栈顶的操作符c
    op.pop(); // 弹出栈顶的操作符c

    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x); // 将计算结果压入数字栈
}



int solution(std::string expression) {
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // 定义操作符的优先级，用unordered_map存储

    // string str;
    // cin >> expression; // 输入表达式字符串
    for (int i = 0; i < expression.size(); i++)
    {
        auto c = expression[i]; // 取出当前字符
        if (isdigit(c)) // 如果是数字
        {
            int x = 0, j = i;
            while (j < expression.size() && isdigit(expression[j])) // 将连续的数字字符转换为整数
                x = x * 10 + expression[j++] - '0';
            i = j - 1; // 更新i的值
            num.push(x); // 将数字压入数字栈
        }
        else if (c == '(') // 如果是左括号
            op.push(c); // 将左括号压入操作符栈
        else if (c == ')') // 如果是右括号
        {
            while (op.top() != '(') // 循环执行计算，直到遇到左括号
                eval();
            op.pop(); // 弹出左括号
        }
        else // 如果是操作符
        {
            while (op.size() && pr[op.top()] >= pr[c]) // 当前操作符的优先级小于等于栈顶操作符的优先级时，执行计算
                eval();
            op.push(c); // 将当前操作符压入操作符栈
        }
    }
    while (op.size()) // 循环执行计算，直到操作符栈为空
        eval();
    // cout << num.top() << endl; // 输出最终结果
    return num.top();
}

int main() {
    // You can add more test cases here
    std::cout << (solution("1+1") == 2) << std::endl;
    std::cout << (solution("3+4*5/(3+2)") == 7) << std::endl;
    std::cout << (solution("4+2*5-2/1") == 12) << std::endl;
    std::cout << (solution("(1+(4+5+2)-3)+(6+8)") == 23) << std::endl;
    return 0;
}