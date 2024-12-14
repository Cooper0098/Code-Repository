#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <iostream> // cin/cout
#include <cstdio>   // printf/scanf

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const long long inf = numeric_limits<long long>::max(); // 无穷大
const int N = 100100;                                   // 100100 十万 , 1100100 一百万 , 100100100 一亿

class Solution
{
public:
    //-----------------------//

    int numRookCaptures(vector<vector<char>> &board)
    {
        int ans = 0;

        int row = board.size(), list = board[0].size();

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 关键点 dx是行 , dy是列

        int x, y;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < list; j++)
            {
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int xx = x, yy = y;
            while (true)
            {
                xx += dx[i];
                yy += dy[i];
                if (xx < 0 || xx >= row || yy >= list || yy < 0)
                    break;
                if (board[xx][yy] == 'B')
                    break;
                if (board[xx][yy] == 'K')
                    break;
                if (board[xx][yy] == 'Q')
                    break;

                if (board[xx][yy] == 'P')
                    break;
                if (board[xx][yy] == 'p')
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }

    bool squareIsWhite(string coordinates)
    {

        bool ans = false;

        int x = 8 - coordinates[1] + '0';

        int y = coordinates[0] - 'a';

        int arr[8][8];

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {

                if (i % 2 == 0)

                {
                    if (j % 2 != 0)
                        arr[i][j] = 1;
                }
                else
                {
                    if (j % 2 == 0)
                        arr[i][j] = 1;
                }
            }

        if (arr[x][y] == 0)
            return true;
        return ans;
    }

    int semiOrderedPermutation(vector<int> &nums)
    {

        int ans = 0;

        int id1, idn;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            if (nums[i] == 1)
                id1 = i;
            if (nums[i] == n)
                idn = i;
        }

        if (id1 < idn)
            ans = id1 + (n - 1 - idn);

        if (id1 > idn)
            ans = id1 + (n - 1 - idn - 1);

        return ans;
    }

    // ------------------Cpp-------------------//
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //---------优化
    Solution solution_Test;

    cout << "---------------------" << endl;

    cout << "---------------------" << endl;

    return 0;
}

// <-- 600