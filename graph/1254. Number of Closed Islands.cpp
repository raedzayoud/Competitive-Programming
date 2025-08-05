class Solution
{
public:
    // dfs ala zero vis =true;
    bool dfs(int i, int j, vector<vector<int>> &grid,
             vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return 0;
        }
        if (grid[i][j] == 1 || vis[i][j])
        {
            return 1;
        }
        vis[i][j] = true;
        int a = dfs(i + 1, j, grid, vis);
        int b = dfs(i - 1, j, grid, vis);
        int c = dfs(i, j + 1, grid, vis);
        int d = dfs(i, j - 1, grid, vis);
        return a && b && c && d;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int count = 0;

        int rows = grid.size();
        int colum = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(colum, false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < colum; j++)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    count += dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};