class Solution
{
public:
    vector<int> res;

    bool dfs(int u, int v, map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[u] = true;
        if (u == v)
            return true;
        for (auto &nei : adj[u])
        {
            if (!visited[nei])
            {
                if (dfs(nei, v, adj, visited))
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        map<int, vector<int>> adj;
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool> visited(n, false);
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                dfs(u, v, adj, visited))
            {
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};