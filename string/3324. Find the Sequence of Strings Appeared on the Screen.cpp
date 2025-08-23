#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

vector<string> stringSequence(string target)
{
    vector<string> v;
    string s = "";

    for (int i = 0; i < target.size(); i++)
    {
        char c = target[i];
        char f = 'a';
        for (int i = 0; i < 26; i++)
        {
            if (f == c)
            {
                s.push_back(c);
                break;
            }
            s.push_back(f);
            f++;
            v.push_back(s);
            s.pop_back();
        }
        v.push_back(s);
    }
    return v;
}
int main()
{
    vector<string> v = stringSequence("he");
    for (string c : v)
    {
        cout << c << " ";
    }
    return 0;
}