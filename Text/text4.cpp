#include <iostream>

using namespace std;

int main()
{
    int n, m = 0;
    cin >> n;
    if (n < 2)
    {
        cout << 0;
    }

    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0 && i % 3 != 0)
            {
                m++;
            }
        }
        cout << m;
    }

    return 0;
}