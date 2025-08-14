/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void dfs(vector<int> &v, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        v.push_back(root->val);
        dfs(v, root->left);
        dfs(v, root->right);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        vector<int> v;
        dfs(v, root);
        set<int> st(v.begin(), v.end());
        int nb = 0;
        for (int c : st)
        {
            nb++;
            if (nb == 2)
            {
                return c;
            }
        }
        return -1;
    }
};