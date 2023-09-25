#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <cmath>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <cstdio>

using namespace std; // 给你一个整数数组 nums，请你将该数组升序排列。

//归并排序

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
void msort(int arr[], int tempArr[], int left, int right)//划分

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
    int arr[] = {19, 8, 4, 74, 87, 7};
    int n = 6;
    
    print_arr(arr, n);

    merge_sort(arr, n);
    print_arr(arr, n);
    return 0;
}

// #include <iostream>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// #include <chrono>
// #include <cstdlib>
// #include <cstdio>

// using namespace std; // 归并排序.请你使用归并排序对数列按照从小到大进行排序。并将排好序的数列按顺序输出。

// const int N = 100010;

// int n;
// int q[N], tmp[N];

// void merge_sort(int q[], int l, int r)
// {
//     if (l >= r)
//     {
//         return;
//     }

//     int mid = l + r >> 1; // 将相加的结果右移一位（相当于除以2)

//     merge_sort(q, l, mid);
//     merge_sort(q, mid + 1, r);

//     int k = 0, i = l, j = mid + 1;
//     while (i <= mid && j <= r)
//     {
//         if (q[i] < q[j])
//         {
//             tmp[k++] = q[i++];
//         }
//         else
//         {
//             tmp[k++] = q[j++];
//         }
//     }
//     while (i <= mid)
//     {
//         tmp[k++] = q[i++];
//     }

//     while (j <= r)
//     {
//         tmp[k++] = q[j++];
//     }

//     for (i = l, j = 0; i <= r; i++, j++)
//     {
//         q[i] = tmp[j];
//     }
// }

// int main()
// {

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &q[i]);
//     }
//     merge_sort(q, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", q[i]);
//     }

//     return 0;
// }