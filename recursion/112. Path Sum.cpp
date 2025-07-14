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
class Solution {
public:
    bool iscontain(int sum, int targetSum, TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }
        bool left = iscontain(sum, targetSum, root->left);
        bool right = iscontain(sum, targetSum, root->right);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return iscontain(0, targetSum, root);
    }
};