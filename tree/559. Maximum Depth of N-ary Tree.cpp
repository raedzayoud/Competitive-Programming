/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int max_val = 0;
    void dfs(Node *root, int nb)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->children.size() == 0)
        {
            max_val = max(max_val, nb + 1);
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            dfs(root->children[i], nb + 1);
        }
    }
    int maxDepth(Node *root)
    {
        dfs(root, 0);
        return max_val;
    }
};