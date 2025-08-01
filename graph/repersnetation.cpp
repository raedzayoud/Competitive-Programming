#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Matrix D adjacent
    int N = 1000;
    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int na, nb;
        cin >> na >> nb;
        adjMatrix[na][nb] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }

    // adjacent List

    int n, e;
    cin >> n >> e;
    vector<int> graph[n];
    for (int i = 0; i < e; i++)
    {
        int na, ne;
        cin >> na >> ne;
        graph[na].push_back(ne);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            int x = graph[i][j];
            cout << x << " ";
        }
        cout << endl;
    }
}