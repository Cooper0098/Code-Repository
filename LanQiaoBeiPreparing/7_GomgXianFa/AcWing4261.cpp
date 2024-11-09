

#include <iostream>

using namespace std;

const int N = 1001000;

typedef long long LL;

char str[N];

int l[N], r[N];

int main()
{
    int n;

    scanf("%d%s", &n, str);

    for (int i = 0, sh = 0, sg = 0; i < n; i++)
    {
        if (str[i] == 'G')
            l[i] = sh, sg++, sh = 0;
        else
            l[i] = sg, sh++, sg = 0;
    }

    for (int i = n - 1, sh = 0, sg = 0; i >= 0; i--)
    {
        if (str[i] == 'G')
            r[i] = sh, sg++, sh = 0;
        else
            r[i] = sg, sh++, sg = 0;
    }

    LL res = 0;

    for (int i = 0; i < n; i++)
        res += (LL)l[i] * r[i] + max(r[i] - 1, 0) + max(l[i] - 1, 0);

    printf("%lld\n", res);
    return 0;
}