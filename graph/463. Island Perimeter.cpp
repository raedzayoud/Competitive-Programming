class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &grid,
            vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 1;
        }
        if (vis[i][j])
        {
            return 0;
        }
        vis[i][j] = true;
        int count = 0;
        count += dfs(i + 1, j, grid, vis);
        count += dfs(i - 1, j, grid, vis);
        count += dfs(i, j + 1, grid, vis);
        count += dfs(i, j - 1, grid, vis);
        return count;
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                    count += dfs(i, j, grid, vis);
            }
        }
        return count;
    }
};