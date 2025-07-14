#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Exemple de fonction récursive : calcul de la factorielle
int nb = 0;
// Question 1

void GetNumber(int start, int end)
{
    if (start > end)
    {
        return;
    }

    if (start == end)
    {
        nb++;
        return;
    }
    GetNumber(start + 1, end);
    GetNumber(start + 2, end);
}
//Question 2
int GetNumber(int start, int end)
{
    if (start > end)
    {
        return 0;
    }

    if (start == end)
    {

        return 1;
    }
    int left = GetNumber(start + 1, end);
    int right = GetNumber(start + 2, end);

    return left + right;
}

// // Question 3

int calc(vector<vector<bool>> &vis, vector<vector<char>> &s, int sx, int sy, int ex, int ey)
{
    int n = s.size();
    int m = s[0].size();

    // Boundary check and visited check
    if (sx < 0 || sy < 0 || sx >= n || sy >= m || vis[sx][sy])
    {
        return 0;
    }

    if (sx == ex && sy == ey)
    {
        return 1; // Reached destination
    }

    vis[sx][sy] = true;

    int left = calc(vis, s, sx + 1, sy, ex, ey);
    int right = calc(vis, s, sx, sy + 1, ex, ey);
    int up = calc(vis, s, sx - 1, sy, ex, ey);
    int down = calc(vis, s, sx, sy - 1, ex, ey);

    return left + right + up + down;
}

int main()
{
    vector<vector<char>> s = {
        {'.', '#', '.', '.', '.'},
        {'.', '#', '.', '#', '#'},
        {'.', '#', '.', '.', '.'},
        {'.', '#', '#', '.', '.'},
        {'.', '.', '.', '.', '.'}};

    vector<vector<bool>> vis(s.size(), vector<bool>(s[0].size(), false));

    int result = calc(vis, s, 0, 0, 0, 4); 

    cout << result << endl;

    return 0;
}