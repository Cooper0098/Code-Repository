#include <iostream>
#include <cstdio>

using namespace std;
int cont = 0;

void move(char x, char y)
{

    printf("%c柱上圆盘 ===> %c柱\n", x, y);
    cont = cont + 1;
}

void han(int n, char a, char b, char c)
{

    if (n == 1)
    {
        move(a, c);
    }

    else
    {
        han(n - 1, a, c, b);
        move(a, c);

        han(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    cout << "请输入圆盘数:" << endl;
    cin >>  n;
    han(n, 'A', 'B', 'C');
    printf("一共移动了%d步", cont);
    return 0;
}