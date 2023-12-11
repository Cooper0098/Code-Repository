#include <iostream>
#include <cstdio>

// using namespace std;  //工程一般不用

// 标准输入输出：std::cout、std::cin、std::endl等用于控制台输入输出的对象和操作符需要使用std::前缀。

//     容器和算法：标准库中的容器类（例如std::vector、std::list等）和算法（例如std::sort、std::find等）需要使用std::前缀。

//         字符串操作：标准库中的字符串类std::string和字符串处理函数（例如std::getline、std::stoi等）需要使用std::前缀。

//             文件操作：标准库中的文件流类（例如std::ifstream、std::ofstream等）和文件处理函数（例如std::getline、std::remove等）需要使用std::前缀。

//                 其他库组件：除了标准库之外，其他库的组件也需要使用相应的前缀，如Boost库的组件需要使用boost::前缀。

// 



int gcd(int a, int b)
{
    int c;
    if(a<= b)
    {
        c = a;
        a = b;
        b = c;
    }

    while (b != 0) // 欧几里得算法 求最大公约数
    {
        int r = a % b;
        a = b;
        b = r;
        }
        return a;
}

int main()
{
        int a, b;
        std::cin >> a >> b;
        
        std::cout << gcd(a, b)<<std::endl;
        return 0;
}