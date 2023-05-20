#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
// 计算完数
vector<int> getFactors(int n)
{
    vector<int> factors;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
        }
    }
    return factors;
}

int main()
{
    int m; // 定义好不可修改,定义范围
    cin >> m;
    auto start_time = std::chrono::high_resolution_clock::now(); // 计算程序执行时间,要放在cin后面

    for (int i = 2; i <= m; i++)
    {
        vector<int> factor = getFactors(i);
        int sum = 0;
        for (int k = 0; k < factor.size(); k++)
        {
            sum += factor[k];
        }

        if (sum == i) // 判断完数
        {
            cout << "完数: " << i << endl;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    printf("程序运行时间为 %d ms", duration.count()); // 程序运行时间
    return 0;
}
