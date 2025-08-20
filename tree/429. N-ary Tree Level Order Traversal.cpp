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
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {}; // early exit if empty tree
        queue<Node *> q;
        vector<vector<int>> v;
        vector<int> ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *a = q.front();
                q.pop();
                ans.push_back(a->val);
                for (int j = 0; j < a->children.size(); j++)
                {
                    q.push(a->children[j]);
                }
            }
            v.push_back(ans);
            ans.clear();
        }
        return v;
    }
};