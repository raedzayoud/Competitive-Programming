class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &prerequisites, stack<int> &st,
             vector<int> &vis)
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
                if (dfs(neigh, prerequisites, st, vis))
                    return true;
            }
        }
        vis[node] = 2; // finished
        st.push(node);
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // vector<int>adj[prerequisites.size()];
        // for(int i=0;i<prerequisites.size();i++){
        //     vector<int>v=prerequisites[i];
        //     adj[v[1]].push_back(v[0]);
        // }
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
        }
        vector<int> vis(numCourses, 0);
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, st, vis))
                {
                    return false;
                }
            }
        }
        return true;
    }
};