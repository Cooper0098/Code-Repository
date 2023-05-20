#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void permute(string str, vector<string>& permutations)
{
    sort(str.begin(), str.end());  // 排序输入字符串

    do {
        permutations.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
}

int main()
{
    vector<string> strings;
    string input;

    cout << "请输入:" << endl;
    while (true) {
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        strings.push_back(input);
    }

    // 对每个字符串进行全排列
    for (const auto& str : strings) {
        vector<string> result;
        permute(str, result);
        cout << "全排列结果：" << endl;
        for (const auto& permutation : result) {
            cout << permutation << endl;
        }
        cout << endl;
    }

    return 0;
}
