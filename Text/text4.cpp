#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <cmath>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <cstdio>

using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    cout << "\n";
}

// 合并
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
    // 标记左半区的第一个
    int l_pos = left;
    // 标记右半区的第一个
    int r_pos = mid + 1;

    // 临时数组的下标
    int pos = left;

    // 合并
    while (l_pos <= mid && r_pos <= right)
    {
        if (arr[l_pos] < arr[r_pos])
        {
            tempArr[pos++] = arr[l_pos++];
        }
        else
        {
            tempArr[pos++] = arr[r_pos++];
        }
    }

    // 合并左半区剩余元素
    while (l_pos <= mid)
    {
        tempArr[pos++] = arr[l_pos++];
    }

    // 合并右半区剩余元素
    while (r_pos <= right)
    {
        tempArr[pos++] = arr[r_pos++];
    }

    // 把临时数组返回原数组
    while (left <= right)
    {
        arr[left] = tempArr[left];
        left++;
    }
}



// 归并排序
void msort(int arr[], int tempArr[], int left, int right)
{
    // 如果只有一个元素,那么不需要进行划分,直接归并即可
    if (left < right)
    {
        int mid = (left + right) / 2;
        msort(arr, tempArr, left, mid);      // 划分左半区
        msort(arr, tempArr, mid + 1, right); // 划分右半边

        // 合并
        merge(arr, tempArr, left, mid, right);
    }
}

void merge_sort(int arr[], int n) // 归并排序入口
{
    int *tempArr = new int[n];
    if (tempArr) // 辅助数组
    {
        msort(arr, tempArr, 0, n - 1);
        delete[] tempArr;
    }

    else
    {
        printf("error:failed");
    }
}

int main()
{
    int arr[] = {9, 8, 4, 4, 87, 47};
    int n = 6;
    print_arr(arr, n);

    merge_sort(arr, n);
    print_arr(arr, n);
    return 0;
}