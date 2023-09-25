#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <cstdio>

using namespace std; // 归并排序.请你使用归并排序对数列按照从小到大进行排序。并将排好序的数列按顺序输出。 


const int N = 100010;  

int n ;
int q[N],tmp[N];

void merge_sort(int q[], int l , int r)
{
    if (l >= r)
    {
        return;
    }
        
    int mid = l+r >> 1;//将相加的结果右移一位（相当于除以2)

    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j])
        {
            tmp[k++] = q[i++];
        }
        else
        {
            tmp[k++] = q[j++];
    
        }

    }
    while (i <= mid)
    {
        tmp[k++] = q[i++];
    }
        
    while (j<= r)
    {
        tmp[k++] = q[j++];
    }
        

    for (i = l, j = 0; i <= r; i++,j++)
    {
        q[i] = tmp[j];
    }
        
}




int main()
{

    
    scanf("%d", &n);

    for (int i = 0; i < n;i++)
    {
        scanf("%d", &q[i]);
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n;i++)
    {
        printf("%d ", q[i]);
    }

        return 0;
}