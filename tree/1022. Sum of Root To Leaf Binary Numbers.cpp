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
#include <string>
class Solution
{
public:
    int sum = 0;
    void dfs(string s, TreeNode *root)
    {
        if (!root)
            return;

        s.push_back(root->val + '0');

        // if leaf, convert the path to number
        if (!root->left && !root->right)
        {
            int number = stoi(s, nullptr, 2);
            sum += number;
        }

        dfs(s, root->left);
        dfs(s, root->right);

        s.pop_back();
    }

    int sumRootToLeaf(TreeNode *root)
    {
        dfs("", root);
        return sum;
    }
};