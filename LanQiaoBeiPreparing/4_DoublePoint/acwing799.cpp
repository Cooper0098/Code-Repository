#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100100;

int a[N], b[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0, j = 0; i < n; i++)
    {
        b[a[i]]++;
        while (b[a[i]] > 1)
        {
            b[a[j]]--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;

    return 0;
}
