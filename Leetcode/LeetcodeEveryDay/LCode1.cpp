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

    int minSetSize(vector<int> &arr)
    {

        int ans = 0;

        unordered_map<int, int> hamap;

        for (int i = 0; i < arr.size(); i++)
        {
            hamap[arr[i]]++;
        }

        int n = arr.size();

        vector<int> cnt;

        for (auto x = hamap.begin(); x != hamap.end(); x++)
        {
            cnt.push_back(x->second);
        }

        sort(cnt.begin(), cnt.end());

        int temp = 0;
        for (int i = hamap.size() - 1; i >= 0; i--)
        {
            temp = cnt[i] + temp;
            ans++;
            if (temp >= n / 2)
            {
                return ans;
            }
        }

        return ans;
    }

    vector<int> stableMountains(vector<int> &height, int threshold)
    {

        vector<int> ans;

        for (int i = 1; i < height.size(); i++)
        {
            if (height[i - 1] > threshold)
                ans.push_back(i);
        }

        return ans;
    }

    bool isSubstringPresent(string s)
    {

        bool ans = true;

        int n = s.size();

        unordered_set<string> haset;

        for (int i = 1; i < n; i++)
        {
            haset.insert(s.substr(i - 1, 2));
        }

        string rever_s = string(s.rbegin(), s.rend());

        for (int i = 1; i < n; i++)
        {
            if (haset.count(rever_s.substr(i - 1, 2)))
            {
                return ans;
            }
        }

        return false;
    }

    bool isPossibleToSplit(vector<int> &nums)
    {

        bool ans = true;

        unordered_map<int, int> hamap;

        for (int i = 0; i < nums.size(); i++)
        {
            hamap[nums[i]]++;
        }

        for (const auto x : hamap)
        {
            if (x.second > 2)
                return false;
        }
        return ans;
    }

    string binary(int x)
    {
        string s;
        while (x)
        {
            s.push_back('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string convertDateToBinary(string date)
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return binary(year) + "-" + binary(month) + "-" + binary(day);
    }


    

    // ------------------Cpp-------------------//
    // <-- 600
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
