#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c;
    cout << "输入当前票价：" << endl;
    cin >> a;

    cout << "输入总的份额：" << endl;
    cin >> b;


    // cout << "卖出3%价格：" << a * 1.03 << " -->卖出份额: " << b * 0.074 << " -->卖出金额: " << b * a * 0.074 << endl;  // 7.4
    // cout << "卖出7%价格：" << a * 1.07 << " -->卖出份额: " << b * 0.074 << " -->卖出金额: " << b * a * 0.074 << endl;  // 7.4
    // cout << "卖出10%价格：" << a * 1.1 << " -->卖出份额: " << b * 0.111 << " -->卖出金额: " << b * a * 0.111 << endl;  // 11.1
    // cout << "卖出20%价格：" << a * 1.2 << " -->卖出份额: " << b * 0.149 << " -->卖出金额: " << b * a * 0.149 << endl;  // 14.9
    // cout << "卖出27%价格：" << a * 1.27 << " -->卖出份额: " << b * 0.222 << " -->卖出金额: " << b * a * 0.222 << endl; // 22.2
    // cout << "卖出30%价格：" << a * 1.3 << " -->卖出份额: " << b * 0.111 << " -->卖出金额: " << b * a * 0.111 << endl;  // 11.1
    // cout << "卖出35%价格：" << a * 1.35 << " -->卖出份额: " << b * 0.111 << " -->卖出金额: " << b * a * 0.111 << endl; // 11.1
    // cout << "卖出38%价格：" << a * 1.38 << " -->卖出份额: " << b * 0.111 << " -->卖出金额: " << b * a * 0.111 << endl; // 11.1
    // cout << "卖出40%价格：" << a * 1.4 << " -->卖出份额: " << b * 0.037 << " -->卖出金额: " << b * a * 0.037 << endl;  // 3.7

    return 0;
}
