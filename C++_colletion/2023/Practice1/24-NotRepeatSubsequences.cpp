// ����һ������Ϊ n���������У����ҳ���Ĳ������ظ��������������䣬������ĳ��ȡ�
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
int n;
int a[N], s[N];

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++; // Ĭ��ȫ��Ϊ0,���λ�ñ��1  ��¼����a[i]��ÿ�������ֵĴ���
        while (s[a[i]] > 1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;

    return 0;
}