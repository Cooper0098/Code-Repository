#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map>//哈希表
#include <stack>//栈
#include <string>
using namespace std;

//括号匹配,用栈

int main()
{
    unordered_map<char, int> mp{
        {'<', 1},
        {'(', 2},
        {'{', 3},
        {'[', 4},
        {'>', -1},
        {')', -2},
        {'}', -3},
        {']', -4},

    };
    string str;
    cin >> str;

    bool res = true;
    stack <int> stk;

    for(auto c : str)
    {
        int t = mp[c];
        if (t > 0 )
        {
            stk.push(t);
        }
        else
        {
            if (stk.size() && stk.top() == -t)
            {
                stk.pop();
            }
            else{
                res = false;
                break;
            }
        }
    }

    if (stk.size())
        res = false;


    if (res )
        cout << "yes" << endl;
        else
            cout << "no" << endl;

    return 0;
}
