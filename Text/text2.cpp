#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;
int p[1000000];

int fibonaci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        int a = 0;
        int b = 1;
        int c;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main()
{
    int n;
    cin >> n;
    cout<<fibonaci(n);
    
}







int binSearch(const vector<int> &arr, int target)
{
    int n = arr.size();        // 数组的大小
    int fibn = 0;              // 斐波那契数列中的索引
    while (fibonaci(fibn) < n) // 找到大于等于数组大小的最小斐波那契数
    {
        fibn++;
    }

    int offset = -1;   // 偏移量
    int left = 0;      // 左边界
    int right = n - 1; // 右边界
    while (fibn > 1)   // 斐波那契数列索引大于1时继续循环
    {
        int mid = left + fibonaci(fibn - 2); // 计算中间位置
        if (arr[mid] > target)               // 如果中间元素大于目标元素
        {
            fibn = fibn - 1; // 更新斐波那契数列索引为前一个数
            right = mid - 1; // 更新右边界为中间位置的前一个位置
        }
        else if (arr[mid] < target) // 如果中间元素小于目标元素
        {
            fibn = fibn - 2; // 更新斐波那契数列索引为前两个数
            left = mid + 1;  // 更新左边界为中间位置的后一个位置
            offset = mid;    // 记录中间位置，用于最后剩余两个元素的判断
        }
        else // 中间元素等于目标元素，找到目标元素，返回索引
        {
            return mid;
        }
    }

    // 对剩余的两个元素进行判断
    if (fibonaci(1) == 1 && arr[left] == target) // 如果斐波那契数列第2个数为1且左边界元素等于目标元素
    {
        return left; // 返回左边界索引
    }
    else if (fibonaci(0) == 0 && arr[right] == target) // 如果斐波那契数列第1个数为0且右边界元素等于目标元素
    {
        return right; // 返回右边界索引
    }

    return -1; // 目标元素不存在于数组中，返回-1
}
