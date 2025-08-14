// This solution will give you a TLE (Time Limit Exceeded) error for large inputs.
// It uses DFS to explore all paths, which is not efficient for this problem.
class Solution
{
public:
    int minHeight = INT_MAX;
    void dfs(int i, int j, vector<vector<int>> &heights,
             vector<vector<bool>> &vis, int currEffort, int prevHeight)
    {
        int m = heights.size();
        int n = heights[0].size();

        // base case: out of bounds or visited
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j])
        {
            return;
        }

        int effort = prevHeight == -1 ? 0 : abs(heights[i][j] - prevHeight);
        currEffort = max(currEffort, effort);

        // if we reached the last cell
        if (i == m - 1 && j == n - 1)
        {
            minHeight = min(minHeight, currEffort);
        }

        vis[i][j] = true;

        // explore in all 4 directions
        dfs(i + 1, j, heights, vis, currEffort, heights[i][j]);
        dfs(i - 1, j, heights, vis, currEffort, heights[i][j]);
        dfs(i, j + 1, heights, vis, currEffort, heights[i][j]);
        dfs(i, j - 1, heights, vis, currEffort, heights[i][j]);

        vis[i][j] = false; // backtrack
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        vector<vector<int>> ans;
        vector<int> v;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dfs(0, 0, heights, vis, 0, -1);

        return minHeight;
    }
};