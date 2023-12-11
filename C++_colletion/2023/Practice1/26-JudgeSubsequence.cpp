#include <iostream>
#include <algorithm>

using namespace std; 

// 给定一个长度为 n的整数序列 a1,a2,…,an 以及一个长度为 m的整数序列 b1,b2,…,bm
// 请你判断 a序列是否为 b序列的子序列。
// 子序列指序列的一部分项按原有次序排列而得的序列，例如序列 {a1,a3,a5}是序列 {a1,a2,a3,a4,a5}的一个子序列。

const int N = 100100;
int a[N] , b[N]; 

int main()
{
    int n,m;
    cin >> n >> m;

    for (int i=0; i < n;i++)
        cin >> a[i];

    for (int i = 0; i < m;i++)
        cin >> b[i];

    int i=0;
    for (int j = 0; j < m;j++)
    {
        if(a[i] == b[j] && i <n)
        {
            i++;
        }
    }

        if (i == n )
            printf("Yes");
        else
            printf("No");

    return 0;
}