#include <iostream>
#include <vector>
using namespace std; // 高精度减法   给定两个正整数（不含前导 0），计算它们的差。计算结果可能为负数。



bool cmp(vector<int> &A,vector<int> &B)
{
    if (A.size() != B.size())
    return A.size() > B.size();
        
    
    for (int i = A.size() - 1; i >= 0;i--)//高位开始比较
    if (A[i] != B[i])
        return A[i] > B[i];//判断
    return true;
}


vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size();i++)
    {
        t = A[i] - t;
        if (i <B.size())
            t = t -  B[i]; 
            
        C.push_back((t + 10) % 10);//小数值%大数值 等于 小数值自己   妙啊
    
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size()>1 && C.back() == 0)
    {
        C.pop_back();
    }
    

        return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');



    if (cmp(A,B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d", C[i]);
        }
    }
    else
    {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d", C[i]);
        }
    }
    

    

    return 0;
}
