#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day(int n)
{
    int y = n / 10000;       // 年
    int m = n % 10000 / 100; // 月
    int d = n % 10000 % 100; // 日
    // 首先更新一下计算年份的二月天数有多少
    // 闰年包括普通闰年和世纪闰年
    // 普通闰年年分是4倍数不是100倍数（），世纪闰年是400的倍数，
    // 即100的倍数不是4的倍数不是闰年，如1900
    // 判断闰年
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        months[2] = 29;
    else // 不加这个会错
        months[2] = 28;

    while (m--)
        d += months[m];
    while (y--)
    {
        d += (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? 366 : 365); // 闰年366天，平年365天
    }
    return d;
}

int main()
{
    int a, b;

    while (cin >> a >> b)
        cout << abs(day(a) - day(b)) + 1 << endl;
    // 由题所示“如果两个日期是连续的我们规定他们之间的天数为两天”，因此我们加一

    return 0;
}