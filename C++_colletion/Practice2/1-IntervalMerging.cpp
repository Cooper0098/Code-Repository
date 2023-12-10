#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

//合并区间

using namespace std;//给定 n个区间 [li,ri]，要求合并所有有交集的区间。注意如果在端点处相交，也算有交集。输出合并完成后的区间个数。     例如：[1,3]和 [2,6]可以合并为一个区间 [1,6]


// 合并区间

const int N = 100010;
int n;

typedef pair<int, int> pii;
vector<pii> nums, res; // 存储区间的vector，nums是输入的区间，res是合并后的结果

int main()
{
    int st = -2e9, ed = -2e9; // 初始化当前合并区间的起始和结束位置
    int n;
    scanf("%d", &n); // 输入待合并的区间个数
    while (n--)
    {
        int l, r;
        scanf("%d%d", &l, &r); // 输入每个区间的起始和结束位置
        nums.push_back({l, r}); // 将区间存储到nums中
    }
    sort(nums.begin(), nums.end()); // 对nums中的区间按照起始位置进行排序

    for (auto num : nums)
    {
        if (ed < num.first) // 如果当前区间的起始位置大于前一个合并区间的结束位置
        {
            if (ed != -2e9) // 如果不是第一个合并区间
                res.push_back({st, ed}); // 将前一个合并区间存储到res中
            st = num.first, ed = num.second; // 更新当前合并区间的起始和结束位置
        }
        else if (ed < num.second) // 如果当前区间的结束位置大于前一个合并区间的结束位置
            ed = num.second; // 更新当前合并区间的结束位置
    }

    res.push_back({st, ed}); // 将最后一个合并区间存储到res中

    printf("%d", res.size()); // 输出合并后的区间个数

    return 0;
}