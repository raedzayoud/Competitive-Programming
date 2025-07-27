#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Backtrack(int sum, vector<int> v, int start, int goal)
{

    if (start == v.size())
    {
        if (sum == goal)
        {
            return 1;
        }
        return 0;
    }
    int neg = Backtrack(sum + (-1 * v[start]), v, start + 1, goal);
    int pos = Backtrack(sum + (v[start]), v, start + 1, goal);
    return neg || pos;
}

int main()
{
    int n, z;
    cin >> n >> z;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << (Backtrack(v[0], v, 1, z) == 1 ? "YES" : "NO");
    return 0;
}