class Solution
{
public:
    void dfsGraph(int pos, vector<vector<int>> adj, vector<bool> &v, vector<int> &ans)
    {
        v[pos] = true;
        ans.push_back(pos);
        for (int i = 0; i < adj[pos].size(); i++)
        {
            int y = adj[pos][i];
            if (!v[y])
            {
                dfsGraph(y, adj, v, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        vector<bool> v(adj.size(), false);
        vector<int> ans;
        dfsGraph(0, adj, v, ans);
        return ans;
    }
};