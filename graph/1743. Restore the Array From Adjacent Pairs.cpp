class Solution
{
public:
    void dfs(int node, map<int, vector<int>> &mp, set<int> &st,
             vector<int> &ans)
    {
        st.insert(node);
        ans.push_back(node);
        for (int i = 0; i < mp[node].size(); i++)
        {
            int neigbor = mp[node][i];
            if (st.count(neigbor) == 0)
            {
                dfs(neigbor, mp, st, ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            vector<int> v = adjacentPairs[i];
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }
        int start = 0;
        vector<int> v;
        for (auto x : mp)
        {
            if (x.second.size() == 1)
            {
                start = x.first;
                break;
            }
        }
        cout << start;
        set<int> st;
        vector<int> ans;
        dfs(start, mp, st, ans);
        return ans;
    }
};