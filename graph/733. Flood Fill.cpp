class Solution
{
public:
    void dfs(vector<vector<bool>> &vis, vector<vector<int>> &v,
             vector<vector<int>> &image, int sr, int sc, int color, int x)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
            vis[sr][sc] || image[sr][sc] != x)
        {
            return;
        }
        vis[sr][sc] = true;
        image[sr][sc] = color;
        dfs(vis, v, image, sr + 1, sc, color, x);
        dfs(vis, v, image, sr - 1, sc, color, x);
        dfs(vis, v, image, sr, sc + 1, color, x);
        dfs(vis, v, image, sr, sc - 1, color, x);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,

                                  int color)
    {
        vector<vector<int>> v;
        int rows = image.size();
        int cols = image[0].size();
        int x = image[sr][sc];
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        dfs(vis, v, image, sr, sc, color, x);
        return image;
    }
};