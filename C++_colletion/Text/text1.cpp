#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void permute(string& str, int startIndex)
{
    if (startIndex == str.size() - 1)
    {
        cout << str << endl;
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
    for (string& str : strings)
    {
        permute(str, 0);
        cout << endl;
    }

    return 0;
}
