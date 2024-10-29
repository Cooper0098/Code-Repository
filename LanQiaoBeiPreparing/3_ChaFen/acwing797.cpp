

#include <iostream>

using namespace std;

const int N = 100100;

int arr[N], b[N]; // arr 是原数组 , b 是差分数组

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        b[i] = arr[i] - arr[i - 1]; // 差分数组
    }
    int l, r, c;
    while (m--)
    {

        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';

    return 0;
}