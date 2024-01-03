#include <iostream>
#include <vector>
using namespace std; // ����һ������������ʵ�ִ������˷�

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C; // �洢�˻�������
    int t = 0;     // ��λ
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;   // ����ǰλ�����b��˲����Ͻ�λ
        C.push_back(t % 10); // ���˻��ĸ�λ�����뵽����C��
        t = t / 10;          // ���½�λ
    }
    return C; // ���س˻�������C
}

int main()
{
    string a;
    int b;
    vector<int> A; // �洢������������

    cin >> a >> b; // ���뱻����a�ͳ���b

    // ��������a��ÿһλת��Ϊ�������洢������A��
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    auto C = mul(A, b); // ����mul�������г˷����㣬�õ��˻�������C

    if (a.size() == 1 && a[0] == 0)
        printf("0"); // ���������Ϊ0�������0
    else if (b == 0)
        printf("0"); // �������Ϊ0�������0
    else
    {
        for (int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d", C[i]); // ����˻���ÿһλ
        }
    }

    return 0;
}