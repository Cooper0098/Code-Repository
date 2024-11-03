#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 10010;
int a[N], b[N], c[N];

vector<vector<int>> matx;

typedef pair<int, int> PII;

int m, n;

void merge()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    for (int i = 0; i < n; i++)
        heap.push({a[0] + b[i], 0});

    for (int i = 0; i < n; i++)
    {
        auto t = heap.top();
        heap.pop();
        int s = t.first, p = t.second;
        c[i] = s;
        heap.push({s - a[p] + a[p + 1], p + 1});
    }

    for (int i = 0; i < n; i++)
        a[i] = c[i];
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);

        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%d", &b[j]);

            merge();
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d", a[i]);
            cout << ' ';
        }
        cout << endl;
    }
}