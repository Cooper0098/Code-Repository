#include <iostream>
#include <vector>

using namespace std;

// 动态规划解决0-1背包问题
void knapsack(int M, const vector<int> &P, const vector<int> &W) // m是背包容量, p是物品的价值, w是物品的重量
{
    int n = P.size();//n是物品个数

    // 创建动态规划表格
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    // 填充dp动态规划表格
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (W[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], P[i - 1] + dp[i - 1][j - W[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 输出最优解
    cout << "最优解：" << dp[n][M] << endl;

    // 输出解向量
    cout << "解向量：";
    int i = n, j = M;
    vector<int> solution;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            solution.push_back(1);
            j -= W[i - 1];
        }
        else
        {
            solution.push_back(0);
        }
        i--;
    }
    for (int k = solution.size() - 1; k >= 0; k--)
    {
        cout << solution[k] << " ";
    }
    cout << endl;
}

int main()
{
    int M, n;
    cout << "请输入背包容量 M 和物品数量 n:";
    cin >> M >> n;

    vector<int> P(n), W(n);
    cout << "请依次输入物品的价值 P 和重量 W:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> P[i] >> W[i];
    }

    knapsack(M, P, W);

    return 0;
}
