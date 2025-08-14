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
    int min_val = INT_MAX;
    void dfs(TreeNode *root, int nb)
    {

        if (root == NULL)
        {

            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            min_val = min(nb + 1, min_val);
            return;
        }
        dfs(root->left, nb + 1);
        dfs(root->right, nb + 1);
    }
    int minDepth(TreeNode *root)
    {
        dfs(root, 0);

        return min_val == 2147483647 ? 0 : min_val;
    }
};