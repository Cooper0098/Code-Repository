#include <iostream>
#include <vector>

using namespace std;

// 获取斐波那契数列中第n个数的值
int fibonacci(int n)
{
    if (n <= 1)
        return n;

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

// 斐波那契二分检索
int fibonacciBinarySearch(const vector<int> &arr, int target)
{
    int n = arr.size();//n为数组的大小

    // 查找斐波那契数列中最接近或稍大于等于n的数
    int fibN = 0;
    while (fibonacci(fibN) < n)
    {
        fibN++;
    }

    int offset = -1;   // 记录偏移量
    int left = 0;      // 左边界
    int right = n - 1; // 右边界

    while (fibN > 1)
    {
        int mid = left + fibonacci(fibN - 2); // 计算中间位置

        // 如果中间元素大于目标元素，则在左侧继续查找
        if (arr[mid] > target)
        {
            fibN -= 1;       // 斐波那契数列向前移动
            right = mid - 1; // 更新右边界
        }
        // 如果中间元素小于目标元素，则在右侧继续查找
        else if (arr[mid] < target)
        {
            fibN -= 2;      // 斐波那契数列向前移动
            left = mid + 1; // 更新左边界
            offset = mid;   // 记录偏移量
        }
        // 目标元素与中间元素相等，找到目标元素
        else
        {
            return mid;
        }
    }

    // 对剩余的两个元素进行判断
    if (fibonacci(1) == 1 && arr[left] == target)
    {
        return left;
    }
    else if (fibonacci(0) == 0 && arr[right] == target)
    {
        return right;
    }

    // 目标元素不存在，返回-1
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int index = fibonacciBinarySearch(arr, target);

    if (index != -1)
    {
        cout << "Element " << target << " found at index " << index << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
