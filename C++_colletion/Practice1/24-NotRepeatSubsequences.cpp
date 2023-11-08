// 给定一个长度为 n的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。
#include <iostream>
#include <algorithm>


using namespace std;

const int N = 1000010;
int n ;
int a[N], s[N];

int main()
{ 
    
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0, j = 0; i < n;i++)
    {
        s[a[i]]++;//默认全部为0,这个位置变成1  记录数组a[i]中每个数出现的次数
        while (s[a[i]] > 1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;

    return 0;
}