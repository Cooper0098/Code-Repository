#include <iostream>
#include <algorithm>

using namespace std; // 给定两个升序排序的有序数�? A�? B，以及一�?�?标�? x; 数组下标�? 0开始。�?�你求出满足 A[i]+B[j]=x的数�? (i,j)       数据保证有唯一解�?

const int N = 100100;
int a[N], b[N];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (a[i] + b[j] > x && j >= 0)
        {
            j--;
        }
        if (a[i] + b[j] == x)
        {
            cout << i << " " << j;
            break;
        }
    }

    return 0;
}