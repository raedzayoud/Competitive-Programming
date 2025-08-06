class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &board,
             vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            vis[i][j])
        {
            return;
        }
        if (board[i][j] != 'X')
        {
            return;
        }
        vis[i][j] = true;
        dfs(i + 1, j, board, vis);
        dfs(i - 1, j, board, vis);
        dfs(i, j + 1, board, vis);
        dfs(i, j - 1, board, vis);
    }
    int countBattleships(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        int count = 0;
        vector<vector<bool>> v(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!v[i][j] && board[i][j] == 'X')
                {
                    dfs(i, j, board, v);
                    count++;
                }
            }
        }
        return count;
    }
};