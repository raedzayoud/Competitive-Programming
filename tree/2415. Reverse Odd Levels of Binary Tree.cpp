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
    void dfs(TreeNode *root, TreeNode *root1, int i)
    {
        if (!root || !root1)
            return;

        if (i % 2 != 0)
        {
            swap(root->val, root1->val);
        }

        dfs(root->left, root1->right, i + 1);
        dfs(root->right, root1->left, i + 1);
    }

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return nullptr;
        ;
        dfs(root->left, root->right, 1);
        return root;
    }
};