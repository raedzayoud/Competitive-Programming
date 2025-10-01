class Solution
{
public:
    bool dfs(vector<bool> &vis, vector<vector<int>> &v, int pos)
    {
        if (vis[pos])
        {
            return false; // already visited
        }
        vis[pos] = true;

        for (int x : v[pos])
        {
            if (x == -1)
                continue;
            if (!dfs(vis, v, x))
                return false; // cycle or revisited
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                                 vector<int> &rightChild)
    {

        vector<vector<int>> v(n);
        vector<int> parentCount(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                v[i].push_back(leftChild[i]);
                if (++parentCount[leftChild[i]] > 1)
                {
                    return false;
                }
            }
            if (rightChild[i] != -1)
            {
                v[i].push_back(rightChild[i]);
                if (++parentCount[rightChild[i]] > 1)
                {
                    return false;
                }
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (parentCount[i] == 0)
            {
                if (root != -1)
                {
                    return false;
                }
                root = i;
            }
        }
        if (root == -1)
        {
            return false; // no root found
        }
        vector<bool> vis(n, false);
        if (!dfs(vis, v, root))
            return false;
        for (bool x : vis)
        {
            if (!x)
            {
                return false;
            }
        }
        return true;
    }
};