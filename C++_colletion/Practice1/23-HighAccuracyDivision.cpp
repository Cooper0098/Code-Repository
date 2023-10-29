#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个函数，用于实现大整数除法
vector<int> div_(vector<int> &A, int b, int &r)
{
    vector<int> C; // 存储商的向量

    // 从大整数的最高位开始进行除法运算
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];  // 将余数乘以10再加上当前位的值
        C.push_back(r / b); // 将商加入到向量C中
        r %= b;             // 更新余数
    }

    reverse(C.begin(), C.end()); // 反转向量C，使得高位在前，低位在后
    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); // 去除高位的0
    return C;         // 返回商的向量C
}

int main()
{
    string a;
    int b;
    cin >> a >> b; // 输入被除数a和除数b

    vector<int> A; // 存储被除数的向量

    // 将被除数a的每一位转换为整数并存储到向量A中
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    int r = 0;              // 余数
    auto C = div_(A, b, r); // 调用div_函数进行除法运算，得到商的向量C和余数r

    // 输出商的向量C
    for (int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    cout << endl
         << r << endl; // 输出余数r

    return 0;
}