#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;//回溯法

void backtrack(vector<int> &nums, int target, vector<int> &subset, int start, int sum)
{
    if (sum == target)
    {
        // 输出当前满足条件的子集
        cout << "满足条件的子集：";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }

        // 输出对应的解向量
        cout << "   其对应的解向量：";
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(subset.begin(), subset.end(), nums[i]) != subset.end())
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    for (int i = start; i < nums.size(); i++)
    {
        // 选择将当前数字加入子集
        subset.push_back(nums[i]);
        sum += nums[i];

        // 递归调用，从下一位置开始继续构建子集
        backtrack(nums, target, subset, i + 1, sum);

        // 回溯操作，将当前数字从子集中移除，减去当前数字的值
        subset.pop_back();
        sum -= nums[i];
    }
}

void subsetSum(vector<int> &nums, int target)
{
    vector<int> subset; // 存储当前子集
    int sum = 0;        // 当前和
    int start = 0;      // 起始位置

    backtrack(nums, target, subset, start, sum);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;

    subsetSum(nums, target);

    return 0;
}
