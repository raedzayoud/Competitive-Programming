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
void Lucky(int n, int target, int index)
{
    if (n >= target)
    {
        ans = index;
        return;
    }
    Lucky((n * 10) + 4, target, (index * 2) + 1);
    Lucky((n * 10) + 7, target, (index * 2) + 2);
}

int main()
{
    Lucky(0, 77, 0);
    cout << ans;
    return 0;
}