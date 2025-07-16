#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
// Exemple de fonction récursive : calcul de la factorielle
int nb = 0;
// Question 1

// void GetNumber(int start, int end)
// {
//     if (start > end)
//     {
//         return;
//     }

//     if (start == end)
//     {
//         nb++;
//         return;
//     }
//     GetNumber(start + 1, end);
//     GetNumber(start + 2, end);
// }
// //Question 2
// int GetNumber(int start, int end)
// {
//     if (start > end)
//     {
//         return 0;
//     }

//     if (start == end)
//     {

//         return 1;
//     }
//     int left = GetNumber(start + 1, end);
//     int right = GetNumber(start + 2, end);

//     return left + right;
// }

// // Question 3

int calc(vector<vector<bool>> &vis, vector<vector<char>> &s, int sx, int sy, int ex, int ey)
{
    int n = s.size();
    int m = s[0].size();

    // Boundary check and visited check
    if (sx < 0 || sy < 0 || sx >= n || sy >= m || vis[sx][sy] || s[sx][sy] == '#')
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
    vis[sx][sy] = false;
    return left + right + up + down;
}

// count Value
set<int> st;
void countSubset(vector<int> v, int i, int sum)
{
    if (i == v.size())
    {
        st.insert(sum);
        return;
    }

    countSubset(v, i + 1, sum);
    countSubset(v, i + 1, sum + v[i]);
}

int ans = 0;
// void Lucky(int n, int target, int index)
// {
//     if (n >= target)
//     {
//         ans = index;
//         return;
//     }
//     Lucky((n * 10) + 4, target, (index * 2) + 1);
//     Lucky((n * 10) + 7, target, (index * 2) + 2);
// }

// int lucky(int n, int target, int index)
// {
//     if (n > target)
//     {
//         return INT_MIN;
//     }
//     if (n == target)
//     {
//         return index;
//     }
//     int left = lucky((n * 10) + 4, target, (index * 2) + 1);
//     int right = lucky((n * 10) + 7, target, (index * 2) + 2);
//     return max(left, right);
// }

int backtrack(vector<vector<bool>> &vis, vector<vector<int>> v, int i, int j, int ex, int ey)
{
    if (i == ex && j == ey)
    {
        return v[i][j];
    }
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || vis[i][j])
    {
        return -1e7;
    }
    vis[i][j] = true;
    int left = backtrack(vis, v, i + 1, j, ex, ey);
    int right = backtrack(vis, v, i, j + 1, ex, ey);
    vis[i][j] = false;
    return v[i][j] + max(left, right);
}



int main()
{
  
    return 0;
}