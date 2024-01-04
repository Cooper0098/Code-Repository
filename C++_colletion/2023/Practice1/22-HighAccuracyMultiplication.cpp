#include <iostream>
#include <vector>
using namespace std; // 定义一个函数，用于实现大整数乘法

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C; // 存储乘积的向量
    int t = 0;     // 进位
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;   // 将当前位与乘数b相乘并加上进位
        C.push_back(t % 10); // 将乘积的个位数加入到向量C中
        t = t / 10;          // 更新进位
    }
    return C; // 返回乘积的向量C
}

int main()
{
    string a;
    int b;
    vector<int> A; // 存储被乘数的向量

    cin >> a >> b; // 输入被乘数a和乘数b

    // 将被乘数a的每一位转换为整数并存储到向量A中
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    auto C = mul(A, b); // 调用mul函数进行乘法运算，得到乘积的向量C

    if (a.size() == 1 && a[0] == 0)
        printf("0"); // 如果被乘数为0，则输出0
    else if (b == 0)
        printf("0"); // 如果乘数为0，则输出0
    else
    {
        for (int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d", C[i]); // 输出乘积的每一位
        }
    }

    return 0;
}