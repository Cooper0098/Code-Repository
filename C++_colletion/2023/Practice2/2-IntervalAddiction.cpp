#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;//区间和


// 假定有一个无限长的数轴，数轴上每个坐标上的数都是 0
// 现在，我们首先进行 n次操作，每次操作将某一位置 x上的数加 c
// 接下来，进行 m次询问，每个询问包含两个整数 l和 r
// 你需要求出在区间 [l,r]之间的所有数的和。

const int N = 1e9;
typedef pair<int, int> pii;
vector<pii> aa, bb;
int alls[N+10] = {0};

int main()
{
    int n , m;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        aa.push_back({x, c});
    }
    for (int i = 0; i < m;i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        bb.push_back({l, r});
    }

    for (auto a :aa)
    {
        int numf = a.first;
        int nums = a.second;
        //  for  (int i = 0; i < n;i++)

        alls[numf] =alls[nums]+ nums;
    }
    

    for(auto b : bb)
    {
        int l = b.first;
        int r = b.second;
        int sums=0;
        for (int i = l; i < r;i++)
        {
            
            sums = alls[i] + sums;
        }
        cout << sums << ends;
    }

        return 0;
}