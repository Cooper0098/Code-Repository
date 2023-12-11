
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50;

int n, k, m;
int w[N];

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    int sum = 0;
    for (int i = 0; i < k; i ++ ) scanf("%d", &w[i]), sum += w[i];

    sort(w, w + k);

    int res = 0;
    for (int i = 0; i <= n; i ++ )
    {
        int cost = i * sum;
        if (cost > m) break;
        int score = (k + 1) * i;
        for (int j = 0; j < k; j ++ )
        {
            int t = w[j] * (n - i);
            if (cost + t <= m) cost += t, score += n - i;
            else
            {
                int x = (m - cost) / w[j];
                score += x;
                cost += x * w[j];
            }
        }
        res = max(res, score);
    }

    printf("%d\n", res);
    return 0;
}
