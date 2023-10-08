#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1000010;

int n, k;
int q[N];

int quick_select(int l, int r, int k)
{
    if (l == r)
    {
        return q[l];
    }

    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (q[i] < x);
        do
        {
            j--;
        } while (q[j] > x);
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    int sl = j - l + 1; // 修改此行，计算小于等于x的元素个数

    if (k <= sl)
    {
        return quick_select(l, j, k);
    }
    else
    {
        return quick_select(j + 1, r, k - sl); // 修改此行，减去小于等于x的元素个数
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
