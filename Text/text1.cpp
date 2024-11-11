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

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int n, int H, int A, vector<int> h, vector<int> a)
{
    // write code here

    int ans = 0;

    unordered_map<int, int> hashMap;

    vector<int> Maxnum;

    for (int i = 0; i < n; i++)
    {
        Maxnum.push_back(max(h[i], a[i]));
    }

    for (int i = 0; i < n; i++)
    {
        hashMap[i] = Maxnum[i];
    }

    auto E_min = min(H, A);

    auto X_maxxxx = max_element(hashMap.begin(), hashMap.end());

    for (auto x = hashMap.begin(); x != hashMap.end(); ++x)
    {
        if (E_min < x->second)
        {
            hashMap.erase(x->first);
        }
    }

    int haN = hashMap.size();
    // cout << haN << endl;
    for (int i = 0; i < haN; i++)
    {
        auto X_max = max_element(hashMap.begin(), hashMap.end());

        int idx = X_max->first, b = X_max->second;

        if (E_min < b)
        {
            // hashMap.erase(idx);
            continue;

            // X_max = max_element(hashMap.begin(), hashMap.end());
            // b = X_max->second;
        }

        // if (E_min >= b)
        else
        {
            E_min = min(h[idx], a[idx]);
            ans++;
            //   cout << E_min << endl;
            //   cout << idx + 100 << endl;
            hashMap.erase(idx);
        }
    }

    return ans;
}

int main()
{
    cout << (solution(3, 4, 5, {1, 2, 3}, {3, 2, 1}) == 1) << endl;
    cout << (solution(5, 10, 10, {6, 9, 12, 4, 7}, {8, 9, 10, 2, 5}) == 2) << endl;
    cout << (solution(4, 20, 25, {10, 15, 18, 22}, {12, 18, 20, 26}) == 3) << endl;
    return 0;
}