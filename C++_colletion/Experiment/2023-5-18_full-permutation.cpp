#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n = 0;

void permute(string &str, int startIndex)
{
    if (startIndex == str.size() - 1)
    {
        cout << str << endl;
        n++;
        return;
    }

    for (int i = startIndex; i < str.size(); i++)
    {
        swap(str[startIndex], str[i]);
        permute(str, startIndex + 1);
        swap(str[startIndex], str[i]);
    }
}

int main()
{
    vector<string> strings;
    string input;

    cout << "请输入:" << endl;
    while (true)
    {
        getline(cin, input);
        if (input.empty())
        {
            break;
        }
        strings.push_back(input);
    }

    // 对每个字符串进行全排列
    cout << "下面是全排列结果:" << endl;
    for (string &str : strings)
    {
        permute(str, 0);
        printf("一共有%d种排列组合", n);
    }
    return 0;
}