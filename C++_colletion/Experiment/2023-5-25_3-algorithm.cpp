#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;//贪心求解背包问题

struct Item
{
    int weight;
    int profit;
};

bool compare(Item a, Item b)
{
    // 自定义比较函数，按照单位重量的利润比率进行排序
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB; // 按照降序排序
}

double knapsack(int n, int capacity, vector<int> &weights, vector<int> &profits)
{
    vector<Item> items;

    // 构造物品列表
    for (int i = 0; i < n; i++)
    {
        Item item;
        item.weight = weights[i];
        item.profit = profits[i];
        items.push_back(item);
    }

    // 按照单位重量的利润比率进行排序
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int currentWeight = 0;

    // 逐个选择物品放入背包
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            totalProfit += items[i].profit;
            currentWeight += items[i].weight;
        }
        else
        {
            // 当前物品不能完整放入背包，计算部分放入的利润
            int remainingWeight = capacity - currentWeight;
            totalProfit += (double)remainingWeight * items[i].profit / items[i].weight;
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;
    cin >> n >> capacity;

    vector<int> weights(n);
    vector<int> profits(n);

    // 读取物品利润
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }

    // 读取物品重量
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    // 调用背包问题求解函数，得到最大利润
    double maxProfit = knapsack(n, capacity, weights, profits);

    // 输出最大利润
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
