#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Backtrack(string res, string current, vector<string> &v, int start)
{
    for (int i = start; i < res.size(); i++)
    {
        current.push_back(res[i]);
        v.push_back(current); // store the current subsequence
        Backtrack(res, current, v, i + 1);
        current.pop_back(); // backtrack
    }
}

int main()
{
    vector<string> v;
    string input;
    cin >> input;

    Backtrack(input, "", v, 0);

    // sort the subsequences lexicographically
    sort(v.begin(), v.end());

    for (const auto &subseq : v)
    {
        cout << subseq << '\n';
    }

    return 0;
}