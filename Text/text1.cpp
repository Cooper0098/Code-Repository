#include <iostream>
#include <vector>

using namespace std;

// 三分检索算法
int ternarySearch(const vector<int> &arr, int target)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;  // 第一个中间位置
        int mid2 = right - (right - left) / 3; // 第二个中间位置

        if (arr[mid1] == target)
        { // 目标元素在第一个中间位置
            return mid1;
        }

        if (arr[mid2] == target)
        { // 目标元素在第二个中间位置
            return mid2;
        }

        if (target < arr[mid1])
        { // 目标元素在第一个中间位置的左侧
            right = mid1 - 1;
        }
        else if (target > arr[mid2])
        { // 目标元素在第二个中间位置的右侧
            left = mid2 + 1;
        }
        else
        { // 目标元素在两个中间位置之间
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1; // 目标元素未找到
}

int main()
{
    int n;
    cout << "请输入元素数量: ";
    cin >> n;

    vector<int> arr(n);
    cout << "请输入元素值: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int target;
    cout << "输入要搜索的目标元素: ";
    cin >> target;

    int index = ternarySearch(arr, target);

    if (index != -1)
    {
        cout << "元素 " << target << " 的下标为: " << index << endl;
    }
    else
    {
        cout << "元素 " << target << " 不在数组中" << endl;
    }

    return 0;
}
