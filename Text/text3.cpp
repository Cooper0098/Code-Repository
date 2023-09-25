class Solution
{
    const int N = 1000010;

    void merge_sort(int nums[], int l, int r)
    {

        int tmp[N];
        if (l >= r)
            return;

        int mid = l + r >> 1;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (nums[i] < nums[j])
            {
                tmp[k++] = nums[i++];
            }
            else
            {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid)
            tmp[k++] = nums[i++];
        while (j <= r)
            tmp[k++] = nums[j++];

        for (i = l, j = 0; i <= r; i++, j++)
            nums[i] = tmp[j];
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n;
        n = nums.size();
        merge_sort(nums, 0, n - 1);
        return nums;
    }
};