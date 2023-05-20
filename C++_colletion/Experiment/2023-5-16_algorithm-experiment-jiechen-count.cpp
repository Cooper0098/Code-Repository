#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;
double a[10001], b[10001];

int function_1(int m) // 阶乘
{
	double fator = 1;
	for (int i = 1; i <= m; i++)
	{
		fator = fator * i;
	}
	return fator;
}

int main()
{
	int m;
	cin >> m;
	int count = 0; // 统计奇数的个数
	for (int i = 1; i <= m; i += 2)
	{
		a[count] = i; // 把奇数加进数组a
		int xcount = count;
		count++;
		double result = pow(-1, xcount); // 将分子放入b数组
		b[xcount] = result;
	}

	auto start_time = std::chrono::high_resolution_clock::now(); // 计算程序执行时间,要放在cin后面

	double sum = 0.0; // 求数组对应元素相除后的和
	for (int i = 0; i < m; i++)
	{
		double p = b[i] / function_1(a[i]);
		sum += p;
		// printf("%.16lf\n", p);
	}
	printf("数组对应元素相除后的和为：%.9lf\n", sum);

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	printf("程序运行时间为 %d ms", duration.count()); // 程序运行时间
	return 0;
}
