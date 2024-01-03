#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����һ������������ʵ�ִ���������
vector<int> div_(vector<int> &A, int b, int &r)
{
    vector<int> C; // �洢�̵�����

    // �Ӵ����������λ��ʼ���г�������
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];  // ����������10�ټ��ϵ�ǰλ��ֵ
        C.push_back(r / b); // ���̼��뵽����C��
        r %= b;             // ��������
    }

    reverse(C.begin(), C.end()); // ��ת����C��ʹ�ø�λ��ǰ����λ�ں�
    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); // ȥ����λ��0
    return C;         // �����̵�����C
}

int main()
{
    string a;
    int b;
    cin >> a >> b; // ���뱻����a�ͳ���b

    vector<int> A; // �洢������������

    // ��������a��ÿһλת��Ϊ�������洢������A��
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    int r = 0;              // ����
    auto C = div_(A, b, r); // ����div_�������г������㣬�õ��̵�����C������r

    // ����̵�����C
    for (int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    cout << endl
         << r << endl; // �������r

    return 0;
}