class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &grid,
             vector<vector<bool>> &v)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }
        if (grid[i][j] == '0' || v[i][j])
        {
            return;
        }

        v[i][j] = true;

        dfs(i + 1, j, grid, v);
        dfs(i - 1, j, grid, v);
        dfs(i, j + 1, grid, v);
        dfs(i, j - 1, grid, v);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<bool>> v(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!v[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, v);
                    count++;
                }
            }
        }
        return count;
    }
};