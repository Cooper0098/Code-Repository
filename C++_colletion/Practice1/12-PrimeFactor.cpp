#include <iostream>

#include <cmath>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <cstdio>

using namespace std; // 求质数 质数因子算法



int main()
{
    for (int i = 12;; i++)
    {
        bool flag = true;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                flag = false;
                break;
            }

        if (flag)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}