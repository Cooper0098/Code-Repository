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

class Solution
{
public:
};

int main()
{
    // std::vector<int> arr = {5, 3, 8, 1, 2};

    // std::sort(arr.begin(), arr.end(), std::greater<int>());

    // for (int num : arr)
    // {
    //     std::cout << num << " "<<endl;
    // }

    int *a;

    int b = 100;
    a = &b;

    int c = 0;

    cout << *a << endl;
    cout << a << endl;
    *a = 90;
    // a = a + 1;
    cout << *a  << endl;
    cout << b << endl;

    return 0;
}