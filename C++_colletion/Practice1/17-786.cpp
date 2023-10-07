#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; // 快速选择算法           给定一个长度为 n的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k个数。



const int N = 1000000;
int x;
int q[N];


void quick_select(int q[],int l,int r)
{
    

}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    int result = quick_select(q, 0, n - 1, k);

    printf("%d", result);

    return 0;
}
