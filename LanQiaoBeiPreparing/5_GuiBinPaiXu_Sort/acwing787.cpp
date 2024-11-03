#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N], w[N];

void merge_sort(int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;

    merge_sort(l, mid), merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (q[i] < q[j])
            w[k++] = q[i++];
        else
            w[k++] = q[j++];
    while (i <= mid)
        w[k++] = q[i++];
    while (j <= r)
        w[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = w[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}
