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
    vector<vector<int>> bfs(TreeNode *root)
    {
        vector<vector<int>> v;

        if (root == NULL)
        {
            return v;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> ans;
            int x = q.size();
            for (int i = 0; i < x; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                ans.push_back(node->val);
                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            if (!ans.empty())
            {
                v.push_back(ans);
            }
        }
        return v;
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> v = bfs(root);
        reverse(v.begin(), v.end());
        return v;
    }
};