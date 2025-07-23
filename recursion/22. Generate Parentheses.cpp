class Solution
{
public:
    void backtrack(int n, int open, int close, vector<string> &v, string s)
    {
        if (s.size() == 2 * n)
        {
            v.push_back(s);
            return;
        }
        if (open < n)
        {
            backtrack(n, open + 1, close, v, s + "(");
        }
        if (close < open)
        {
            backtrack(n, open, close + 1, v, s + ")");
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        string s;
        backtrack(n, 0, 0, v, s);
        return v;
    }
};