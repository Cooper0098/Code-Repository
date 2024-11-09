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

//-------------------------------------------------------------------------//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, int k, const std::vector<int> &nums)
{
    // Edit your code here

    unordered_map<int, int> hashMap;

    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]] = i;
    }

    vector<int> copyNum(nums);

    auto minX = min_element(copyNum.begin(), copyNum.end());
    int idx = distance(copyNum.begin(), minX);

    copyNum.erase(copyNum.begin() + idx);

    // int ans = INT_MIN;

    // for (int i = k - 1; i < copyNum.size(); i++)
    // {
    //     int cnt = 0;

    //     for (int j = i - k + 1; j < k - 1; j++)
    //     {
    //         cnt += copyNum[j];
    //     }
    //     ans = max(ans, cnt);
    // }

    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += copyNum[i];
    }

    int ans = window_sum;

    // 滑动窗口，移动窗口的右端
    for (int i = k; i < copyNum.size(); i++)
    {
        // 将窗口向右滑动，减去左边的元素，加入右边的新元素
        window_sum += copyNum[i] - copyNum[i - k];
        ans = std::max(ans, window_sum); // 更新最大值
    }

    return ans;
}

int main()
{
    // Add your test cases here
    std::cout << (solution(5, 3, {2, 1, 3, -1, 4}) == 8) << std::endl;

    return 0;
}