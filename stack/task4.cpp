#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{

    string k;
    k = "";
    string s;
    cin >> s;
    int open = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open++;
        }
        else
        {
            if (open == 0 && s[i] == ')')
            {
                continue;
            }
            if (s[i] == ')')
                open--;
        }
        k.push_back(s[i]);
    }
    string y;
    y = "";
    for (int i = k.size() - 1; i >= 0; i--)
    {
        if (k[i] == '(' && open > 0)
        {
            open--;
            continue;
        }
        y.push_back(k[i]);
    }
    //cout << y;
    // reverse y
    reverse(y.begin(), y.end());
    cout << y;

    return 0;
}
