class Solution
{
public:
    bool detechCycle(int node, vector<vector<int>> &prerequisites,
                     stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1; // visited
        for (int i = 0; i < prerequisites[node].size(); i++)
        {
            int neigh = prerequisites[node][i];
            if (vis[neigh] == 1)
            {
                return true; // cycle
            }
            if (vis[neigh] == 0)
            {
                if (detechCycle(neigh, prerequisites, st, vis))
                    return true;
            }
        }
        vis[node] = 2; // finished
        st.push(node);
        return false;
    }
    void dfs(int node, vector<vector<int>> adj, vector<bool> &v,
             stack<int> &st)
    {
        v[node] = true;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int neigh = adj[node][i];
            if (!v[neigh])
            {
                dfs(neigh, adj, v, st);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        for (auto &p : prerequisites)
        {
            int x = p[0];
            int y = p[1];
            adj[y].push_back(x);
        }

        vector<int> vis(numCourses, 0);
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (detechCycle(i, adj, st, vis))
                {
                    return {};
                }
            }
        }
        while (!st.empty())
        {
            st.pop();
        }
        vector<bool> vis1(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis1[i])
            {
                dfs(i, adj, vis1, st);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};