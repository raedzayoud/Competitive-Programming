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
    bool evaluateTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr &&
            root->val == 0)
        {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr &&
            root->val == 1)
        {
            return true;
        }

        int left = evaluateTree(root->left);
        int right = evaluateTree(root->right);

        if (root->left != nullptr && root->right != nullptr)
        {
            if (root->val == 2)
            {
                return left || right;
            }
        }

        if (root->left != nullptr && root->right != nullptr)
        {
            if (root->val == 3)
            {
                return left && right;
            }
        }

        return false;
    }
};