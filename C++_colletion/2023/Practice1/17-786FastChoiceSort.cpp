#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; // 快速选择算法           给定一个长度为 n的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k个数。



const int N = 1000010;

int n, k;
int q[N];


int quick_select(int l,int r,int k)
{

    if (l== r)
    {
        return q[l];
    }


    int x = q[l], i = l - 1, j = r + 1;
    while (i<j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
        {
            swap(q[i], q[j]);
        }
            
    }
    int sl = j - l + 1; // 修改此行，计算小于等于x的元素个数 注意边界范围!!!!
    if (k<=sl)
    {
        return quick_select(l, j, k);
    }
    else
    {
        return quick_select(j+1, r, k-sl);
    }
                       
} 

int main()
{
  
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }



    printf("%d", quick_select(0, n - 1, k));

    return 0;
}
