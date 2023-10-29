#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;
    map<long long, vector<tuple<long long, long long, long long>>> t;
    for (long long i = 0; i < n; i++)
    {
        long long f, s, k;
        cin >> f >> s >> k;
        if (t.find(f) == t.end())
        {
            t[f] = {make_tuple(i + 1, s, k)};
        }
        else
        {
            t[f].push_back(make_tuple(i + 1, s, k));
        }
    }
    long long res = 0;
    priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>> pq;
    auto [f, s, k] = t[0][0];
    pq.push(make_tuple(k, 1, s));
    if (p < k)
    {
        cout << 0 << endl;
    }
    else
    {
        while (!pq.empty())
        {
            auto [k, node, s] = pq.top();
            pq.pop();
            if (p >= k)
            {
                p += s;
                res += 1;
                if (t.find(node) != t.end())
                {
                    for (auto [nod, s, core] : t[node])
                    {
                        pq.push(make_tuple(core, nod, s));
                    }
                }
            }
            else
            {
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}