#include <iostream>
#include <algorithm>

using namespace std; // �����������������������?? A?? B���Լ�һ????��?? x; �����±�?? 0��ʼ��???��������� A[i]+B[j]=x����?? (i,j)       ���ݱ�֤��Ψһ��??

const int N = 100100;
int a[N], b[N];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (a[i] + b[j] > x && j >= 0)
        {
            j--;
        }
        if (a[i] + b[j] == x)
        {
            cout << i << " " << j;
            break;
        }
    }

    return 0;
}