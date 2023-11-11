
#include <iostream>
#include <algorithm>

using namespace std; // 给定两个升序排序的有序数组 A和 B，以及一个目标值 x; 数组下标从 0开始。请你求出满足 A[i]+B[j]=x的数对 (i,j)   数据保证有唯一解。

const int N = 100100;
int a[N] , b[N]; 

int main()
{
    int n , m ,x;
    cin >> n, m, x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m;i++)
        cin >> b[i];
    return 0;
}