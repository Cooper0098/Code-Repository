#include <iostream>
#include <vector>

using namespace std; // 指针是什么

int main()
{
    int num = 10; // 声明一个整数变量
    int *ptr;     // 声明一个整型指针变量

    // ptr 存地址  , *ptr 存地址上的值

    ptr = &num; // 将变量 num 的地址赋值给指针 ptr

    cout << "Value of num: " << num << endl;                    // 10
    cout << "Address of num: " << &num << endl;                 // address
    cout << "Value of ptr: " << ptr << endl;                    // address
    cout << "Value at address stored in ptr: " << *ptr << endl; // 10

    *ptr = 20; // 修改指针指向的内存位置的值

    cout << "Value of num after modification: " << num << endl;

    return 0;
}
