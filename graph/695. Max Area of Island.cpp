#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &board,
        vector<vector<bool>> &vis)
{
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        vis[i][j])
    {
        return 0;
    }
    if (board[i][j] == 0)
    {
        return 0;
    }
    vis[i][j] = true;
    int res = 1;
    res += dfs(i + 1, j, board, vis);
    res += dfs(i - 1, j, board, vis);
    res += dfs(i, j + 1, board, vis);
    res += dfs(i, j - 1, board, vis);

    return res;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    int res = 0;
    vector<vector<bool>> v(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!v[i][j] && grid[i][j] == 1)
            {

                count = max(count, dfs(i, j, grid, v));
                res = 0;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout
        << "Max Area of Island: " << maxAreaOfIsland(grid) << endl;
    return 0;
}