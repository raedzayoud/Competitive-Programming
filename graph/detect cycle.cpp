class Solution
{
public:
    bool dfs(vector<bool> &anc, vector<bool> &v, vector<vector<int>> &edges, int pos)
    {
        anc[pos] = true;
        v[pos] = true;
        for (int i = 0; i < edges[pos].size(); i++)
        {
            int x = edges[pos][i];
            if (v[x] && anc[x])
            {
                return true;
            }
            if (!v[x] && dfs(anc, v, edges, x))
            {
                return true;
            }
        }
        anc[pos] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<bool> anc(V, false);
        vector<bool> v(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!v[i])
            {

                if (dfs(anc, v, edges, i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};