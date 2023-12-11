#include <iostream>

using namespace std;

int max(int x, int y)
{

    if (x - y >= 0)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << max(x, y) << endl;
}