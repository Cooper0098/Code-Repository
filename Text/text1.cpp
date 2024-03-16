#include <iostream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



void quick_sort(vector<int> &q, int l, int r)
{

    if (l >= r)
        return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1]; // x为随机数
    while (i < j)
    {
        do
            i++;
        while (x > q[i]);
        do
            j--;
        while (x < q[j]);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{

    return 0;
}
