#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;// 给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

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

int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // 定义操作符的优先级，用unordered_map存储

    string str;
    cin >> str; // 输入表达式字符串
    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i]; // 取出当前字符
        if (isdigit(c)) // 如果是数字
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j])) // 将连续的数字字符转换为整数
                x = x * 10 + str[j++] - '0';
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
    cout << num.top() << endl; // 输出最终结果
    return 0;
}