#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

string removeDuplicateLetters(string s)
{
    vector<int> last(26, -1);
    vector<bool> vis(26, false);
    for (int i = 0; i < s.size(); i++)
    {
        last[s[i] - 'a'] = i;
    }
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (vis[c - 'a'])
            continue;
        while (!ans.empty() && ans.back() > c &&
               last[ans.back() - 'a'] > i)
        {
            vis[ans.back() - 'a'] = false;
            ans.pop_back();
        }
        ans += c;
        vis[c - 'a'] = true;
    }
    return ans;
}
int main()
{
    string s = "cbacdcbc";
    cout << 'a' - 'a';
    return 0;
}