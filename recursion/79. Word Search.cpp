class Solution
{
public:
    bool backtrack(vector<vector<char>> &board, string word, int index,
                   int posx, int posy, vector<vector<bool>> &vis)
    {

        int m = board.size(), n = board[0].size();
        // base case
        if (posx < 0 || posy < 0 || posx >= m || posy >= n || vis[posx][posy] ||
            board[posx][posy] != word[index])
        {
            return false;
        }
        if (index == word.size() - 1)
        {
            return true;
        }
        vis[posx][posy] = true;
        int left = backtrack(board, word, index + 1, posx - 1, posy, vis);
        int left1 = backtrack(board, word, index + 1, posx, posy + 1, vis);
        int left2 = backtrack(board, word, index + 1, posx, posy - 1, vis);
        int left3 = backtrack(board, word, index + 1, posx + 1, posy, vis);
        vis[posx][posy] = false;
        return left || left1 || left2 || left3;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int index = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (backtrack(board, word, index, i, j, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};