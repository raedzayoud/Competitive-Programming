// BFS FOR TREE
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void bfs(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        cout << node->val << " "; // visite du noeud

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

int main()
{
    // Créons l’arbre
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    bfs(root); // sortie: 1 2 3 4 5 6 7
    return 0;
}

// BFS FOR GRAPH
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        vector<bool> v(adj.size(), false);

        int pos = 0; // on part du nœud 0
        queue<int> q;
        q.push(pos);
        v[pos] = true;      // marquer comme visité
        ans.push_back(pos); // ajouter dans la réponse

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (int i = 0; i < adj[x].size(); i++)
            {
                int neigh = adj[x][i];
                if (!v[neigh])
                {
                    v[neigh] = true;
                    ans.push_back(neigh);
                    q.push(neigh);
                }
            }
        }
        return ans;
    }
};
