#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers; // 创建一个整数向量

    numbers.push_back(10); // 向向量中添加元素
    numbers.push_back(20);
    numbers.push_back(30);

    // 打印向量中的元素
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }

    return 0;
}