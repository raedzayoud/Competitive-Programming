#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int neigh : adj[node])
    {
        if (!visited[neigh])
        {
            dfs(neigh, adj, visited, st);
        }
    }
    st.push(node); // on empile après avoir exploré tous les voisins
}

vector<int> topoSortDFS(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main()
{
    int V = 6;
    vector<int> adj[V];

    // Exemple de graphe dirigé (DAG)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSortDFS(V, adj);

    cout << "Topological Sort (DFS): ";
    for (int x : topo)
        cout << x << " ";
    cout << endl;

    return 0;
}
