#include <iostream>

#include <cmath>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{

    int max = 10000;
    for (int i = 1000; i <= max; i++)
    {
        int in = i * 4;
        int a, b, c, d;
        a = i / 1000;
        b = (i - a * 1000) / 100;
        c = (i - (a * 1000 + b * 100)) / 10;
        d = i - (a * 1000 + b * 100 + c * 10);

        int out = d * 1000 + c * 100 + b * 10 + a;

        if (out == in)
        {
            cout << out;
            cout << ' ';
            cout << in / 4;
        }
    }

    return 0;
}