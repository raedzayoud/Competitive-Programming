class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited,
             vector<int> &indices)
    {

        indices.push_back(node);
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int x = adj[node][i];
            if (!visited[x])
            {
                dfs(x, adj, visited, indices);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        vector<vector<int>> adj(n);
        for (auto c : pairs)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> indices;

                dfs(i, adj, visited, indices);

                string chars = "";
                for (int c : indices)
                {
                    chars += s[c];
                }
                sort(chars.begin(), chars.end());
                sort(indices.begin(), indices.end());
                for (int k = 0; k < indices.size(); k++)
                {
                    s[indices[k]] = chars[k];
                }
            }
        }
        return s;
    }
};