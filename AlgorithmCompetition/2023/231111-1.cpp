#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main()
{
    string s;
    cin >> s;
    vector<char> a;
    for (int i = s.size() - 1; i >= 0;i--)
    {
        a.push_back(s[i]);
   
    }
    for (int i = 0; i < s.size();i++)
        cout << a[i];

        return 0;
}
