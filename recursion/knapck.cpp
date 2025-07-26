#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxSum = 0;

void Backtrack(int start,
               vector<pair<int, int>> v, int sum, int n, int count)
{
    if (start == v.size())
    {
        maxSum = max(sum, maxSum);
        return;
    }
    Backtrack(start + 1, v, sum, n, count);
    if (count + v[start].first <= n)
    {
        Backtrack(start + 1, v, sum + v[start].second, n, count + v[start].first);
    }
}

int main()
{

    int n, maxNumber;
    cin >> n >> maxNumber;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    Backtrack(0, v, 0, maxNumber, 0);
    cout << maxSum;
}