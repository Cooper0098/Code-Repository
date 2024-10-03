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

//--------------------------------模板--------------------------------//

// class Solution
// {
// public:
// };
int ans = 0; // 最大价值
const int maxN = 1006;

int f[maxN][maxN]; //
int volume[maxN];
int weight[maxN];

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> volume[i] >> weight[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j < volume[i])//  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            {
                f[i][j] = f[i - 1][j];
            }
            else
            {
                   // 能装，需进行决策是否选择第i个物品
                f[i][j] = max(f[i - 1][j], f[i - 1][j - volume[i]] + weight[i]);// j - 容量 = 能装载的东西 
            }
        }
    ans = f[n][m];

    cout << ans << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << f[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}