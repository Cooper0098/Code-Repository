#include<iostream>
#include<vector>
using namespace std; // 高精度加法   给定两个正整数（不含前导 0），计算它们的和。

const int N = 1e6+10;

vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size()|| i < B.size();i++)
    {
        if (i < A.size())
        {
            t += A[i];
        
        }
        if ( i <B.size())
        {
            t += B[i];
        }
        C.push_back(t % 10);
        t /= 10;
        
    }

    if (t) // 变量t的值不为0，执行代码
        C.push_back(1);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;//自适应数组


    cin >> a>>b ; //a = 123456

    //存放时,低位在前123 ---> 存321,因为这样方便进位
    for (int i = a.size() - 1; i >= 0;i--)
    {
        A.push_back(a[i] - '0'); // a[i] - '0'是将字符数组（或字符串）中的字符转换为对应的整数值的常见方法。在C++中，字符的ASCII码值可以通过减去字符'0'的ASCII码值来得到对应的整数值。
        //A = [6,5,4,3,2,1]
    }
    for (int i = b.size() - 1; i>= 0;i--)
    {
        B.push_back(b[i] - '0');
    }

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0;i--)
    {
        printf("%d", C[i]);
    }
        return 0;
}