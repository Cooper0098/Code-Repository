#include <iostream>
#include <vector>

using namespace std; // ָ����ʲô

int main()
{
    int num = 10; // ����һ����������
    int *ptr;     // ����һ������ָ�����

    // ptr ���ַ  , *ptr ���ַ�ϵ�ֵ

    ptr = &num; // ������ num �ĵ�ַ��ֵ��ָ�� ptr

    cout << "Value of num: " << num << endl;                    // 10
    cout << "Address of num: " << &num << endl;                 // address
    cout << "Value of ptr: " << ptr << endl;                    // address
    cout << "Value at address stored in ptr: " << *ptr << endl; // 10

    *ptr = 20; // �޸�ָ��ָ����ڴ�λ�õ�ֵ

    cout << "Value of num after modification: " << num << endl;

    return 0;
}
