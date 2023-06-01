#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;
int p[1000000];

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    else 
    return p[x];
}

struct Data
{
    int a, b, c;

    // 自定义比较函数，按最后一个数的值进行升序排序
    bool operator<(const Data &other) const
    {
        return c < other.c;
    }
};


int main()
{
    vector<Data> data;
    string line;
    while (getline(cin, line) && line != "end")
    {
        istringstream iss(line);
        Data d;
        if (iss >> d.a >> d.b >> d.c)
        {
            data.push_back(d);
        }
    }
    sort(data.begin(), data.end());
}





