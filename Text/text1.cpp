#include <iostream>
using namespace std;

// 合并两个已排序的子数组
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 复制数据到临时数组 L 和 R
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 归并临时数组到 arr[]
    
    i = 0;    // 初始化第一个子数组的索引
    j = 0;    // 初始化第二个子数组的索引
    k = left; // 初始化合并子数组的索引
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制 L[] 的剩余元素
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序主函数
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // 分割数组并递归调用 mergeSort()
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并两个子数组
        merge(arr, left, mid, right);
    }
}

// 测试 //测试
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "原始数组：";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "排序后的数组：";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}