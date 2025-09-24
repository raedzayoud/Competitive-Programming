class Solution
{
public:
    void dfs(vector<vector<bool>> &vis, vector<vector<char>> &board, int i,
             int j, bool &near)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            vis[i][j] || board[i][j] == 'X')
        {
            return;
        }
        if (board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size() - 1 ||
                                   j == board[0].size() - 1))
        {
            near = true;
        }
        if (board[i][j] == 'O')
        {
            vis[i][j] = true;
        }
        dfs(vis, board, i + 1, j, near);
        dfs(vis, board, i, j - 1, near);
        dfs(vis, board, i, j + 1, near);
        dfs(vis, board, i - 1, j, near);
    }

    void pp(vector<vector<bool>> &vis, vector<vector<char>> &board, int i,
            int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            !vis[i][j] || board[i][j] == 'X')
        {
            return;
        }

        vis[i][j] = false;
        board[i][j] = 'X';

        pp(vis, board, i + 1, j);
        pp(vis, board, i, j - 1);
        pp(vis, board, i, j + 1);
        pp(vis, board, i - 1, j);
    }
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int colum = board[0].size();
        bool near = false;
        vector<vector<bool>> vis(rows, vector<bool>(colum, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colum; j++)
            {
                near = false;
                if (!vis[i][j])
                {
                    if (board[i][j] == 'O')
                    {

                        dfs(vis, board, i, j, near);

                        if (!near)
                        {
                            cout << "zaza" << endl;
                            pp(vis, board, i, j);
                        }
                    }
                }
            }
        }
    };
};