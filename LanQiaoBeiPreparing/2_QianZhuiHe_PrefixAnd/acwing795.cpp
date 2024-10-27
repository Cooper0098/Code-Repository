#include <iostream>

using namespace std;

const int N = 100001;

int n, m;
int arry[N], s[N]; // s是前缀和

int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arry[i];
    }

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + arry[i];
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
