#include <iostream>
#include<cstdio>

using namespace std; // 快速排序....请你使用快速排序对这个数列按照从小到大进行排序。并将排好序的数列按顺序输出。

const int N = 1e6+10;

int n;
int q[N];

void quick_sort(int q[],int l,int r)
{
    if (l >= r) return;

    int x = q[l + r >> 1];//数据增强了,随机选取一个数,或者选择中间值,因为如果排序是倒序,时间复杂度就要n^2 
    int i = l - 1, j = r + 1; // 向外扩一格i从-1,j从n+1开始
    while(i < j)
    {
        do
            i++;
        while (q[i] < x); // 满足q[i] < x继续,不满足结束

        do
            j--;
        while (q[j] > x);

        if (i<j)
        
            swap(q[i], q[j]);
        
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i=0  ; i < n;i++)
        scanf("%d", &q[i]);


 quick_sort(q, 0, n-1);

    for (int i = 0; i < n;i++)
        printf("%d ", q[i]);
    return 0;
}