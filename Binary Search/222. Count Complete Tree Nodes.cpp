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
    int countWithoutRoot(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        int left = 0;
        int right = 0;

        if (root->left != NULL) {
            left = countWithoutRoot(root->left);
        }
        if (root->right != NULL) {
            right = countWithoutRoot(root->right);
        }
        ans = left + right+1;
        return ans;
    }
    int countNodes(TreeNode* root) {
        int x= countWithoutRoot(root);
        return x;
        
    }
};