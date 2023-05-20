#include <iostream>

using namespace std;

int fact(int n)
{
    double fator = 1;
    for (int i = 1; i <= n; i++)
    {
        fator = fator * i;
    }

    return fator;
}

int main()
{
    int n, a;
    cin >> n;
    a = fact(n);
    cout << a << endl;
}