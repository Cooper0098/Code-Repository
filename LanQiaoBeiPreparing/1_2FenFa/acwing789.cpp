#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;

    cin >> n >> q;

    vector<int> nums(100001);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    while (q--)
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= x)
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        //
        if (nums[l] != x)
            cout << "-1 -1" << endl;

        //
        else
        {
            cout << l << ' '; // 左坐标

            int l = 0, r = n - 1; // 右坐标

            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }

    return 0;
}

