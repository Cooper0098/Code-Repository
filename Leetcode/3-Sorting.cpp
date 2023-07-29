#include <algorithm>
#include <vector>

using namespace std; //  快速排序数组 最坏情况t =  n^2

class Solution
{

    int soting(vector<int> &nums, int low, int high)
    {
        int l = nums.size();
        // low =0;
        // high =l-1;
        int point = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= point)
            {
                high--;
            }
            nums[low] = nums[high];

            while (low < high && nums[low] <= point)
            {
                low++;
            }
            nums[high] = nums[low];
        }

        if (low == high)
        {
            nums[low] = point;
        }
        return low;
    }

    void qsort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int project = soting(nums, low, high);
            qsort(nums, low, project - 1);
            qsort(nums, project + 1, high);
        }
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {

        //srand((unsigned)time(NULL));
        qsort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

int main()
{
    
}