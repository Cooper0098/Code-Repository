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

    for(auto num:nums)                   
        {
            if(ed<num.first)                            //情况1：两个区间无法合并
            {
                if(ed!=-2e9) res.push_back({st,ed}) ;   //区间1放进res数组
                st=num.first,ed=num.second ;            //维护区间2
            }
            //情况2：两个区间可以合并，且区间1不包含区间2，区间2不包含区间1
            else if(ed<num.second)  
                ed=num.second ;                         //区间合并
        }  
    //(实际上也有情况3：区间1包含区间2，此时不需要任何操作，可以省略)

    //注：排过序之后，不可能有区间2包含区间1

    
    if(st != -2e9)
    res.push_back({st,ed});

    //考虑循环结束时的st,ed变量，此时的st,ed变量不需要继续维护，只需要放进res数组即可。
    //因为这是最后的一个序列，所以不可能继续进行合并。



    printf("%d", res.size()); // 输出合并后的区间个数

    return 0;
}