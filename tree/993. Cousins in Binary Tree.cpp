class Solution
{
public:
    // v[i] = {parent, depth}
    vector<pair<int, int>> v;

    void getDepth(TreeNode *root, int val, int depth)
    {
        if (root == nullptr)
            return;

        if (root->left && root->left->val == val)
        {
            v.push_back({root->val, depth + 1});
            return;
        }
        if (root->right && root->right->val == val)
        {
            v.push_back({root->val, depth + 1});
            return;
        }
        getDepth(root->left, val, depth + 1);
        getDepth(root->right, val, depth + 1);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        v.clear();
        getDepth(root, x, 0);
        getDepth(root, y, 0);

        if (v.size() < 2)
            return false;

        return (v[0].second == v[1].second && v[0].first != v[1].first);
    }
};
