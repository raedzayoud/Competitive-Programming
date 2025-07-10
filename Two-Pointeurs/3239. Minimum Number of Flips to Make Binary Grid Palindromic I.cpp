#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int minFlips(vector<vector<int>> &grid)
{
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> v = grid[i];
        int left = 0;
        int right = v.size() - 1;
        while (left <= right)
        {
            if (v[left] != v[right])
            {
                res++;
            }
            left++;
            right--;
        }
    }

    int res2 = 0;
    int m = grid.size();    // nombre de lignes
    int n = grid[0].size(); // nombre de colonnes
    cout<<m<<" "<<n;
    cout<<endl;
    for (int j = 0; j < n; j++) 
    {
        for (int i = 0; i < m/2; i++)
        {
            if (grid[i][j] != grid[m - 1 - i][j])
            {
                res2++;
            }
        }
    }

    return min(res, res2);
}
int main()
{
    vector<vector<int>> nums{
        {0, 1},
        {0, 1},
        {0, 0}};

    cout << minFlips(nums) << endl;
    return 0;
}