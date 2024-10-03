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
#include <memory> // 内存管理
#include <functional>
#include <numeric>
#include <ranges>
#include <cstring> // 有memset将一块内存区域设置为特定的值。 strcpy：复制一个字符串。strcat：连接两个字符串。strlen：获取字符串的长度。strcmp：比较两个字符串。
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//



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