#include <iostream> // 输入输出 cin/cout
#include <cstdio>   // 输入输出 printf/scanf
//--------------------------------------------//
#include <algorithm>     // 算法, 用于操作容器, 可以用于排序、查找、修改和管理数据
#include <vector>        // 容器
#include <string>        // 字符串
#include <stack>         // 栈, 后进先出
#include <queue>         // 队列, 先进先出
#include <unordered_map> // 哈希表, 存储的是键值对. 每个元素由一个键和一个与之关联的值组成, 键是唯一的, 但值可以重复. 适合用于需要根据键快速查找值的场景
#include <unordered_set> // 哈希表,存储的是唯一元素的集合. 每个元素都是值, 不关联任何其他数据. 适合用于需要存储不重复的元素的场景
//--------------------------------------------//
#include <cstring> // 有memset将一块内存区域设置为特定的值.  strcpy：复制一个字符串.strcat：连接两个字符串.  strlen：获取字符串的长度.  strcmp：比较两个字符串.
#include <functional>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//


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
            if (j < volume[i]) //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            {
                f[i][j] = f[i - 1][j];
            }
            else
            {
                // 能装，需进行决策是否选择第i个物品
                f[i][j] = max(f[i - 1][j], f[i - 1][j - volume[i]] + weight[i]); // j - 容量 = 能装载的东西
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