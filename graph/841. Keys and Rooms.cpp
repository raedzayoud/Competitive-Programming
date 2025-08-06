#include <iostream>
#include <vector>
using namespace std;

void dfs(int index, vector<vector<int>> &rooms,
         vector<bool> &vis)
{

    if (vis[index])
    {
        return;
    }
    vis[index] = true;
    for (int i = 0; i < rooms[index].size(); i++)
    {
        int key = rooms[index][i];
        dfs(key, rooms, vis);
    }
}
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    vector<bool> vis(rooms.size(), false);
    dfs(0, rooms, vis);
    for (int i = 0; i < vis.size(); i++)
    {
        if (vis[i] == false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> rooms = {
        {1}, // Room 0 has key to room 1
        {2}, // Room 1 has key to room 2
        {3}, // Room 2 has key to room 3
        {}   // Room 3 has no keys
    };
    if (canVisitAllRooms(rooms))
    {
        cout << "Can visit all rooms" << endl;
    }
    else
    {
        cout << "Cannot visit all rooms" << endl;
    }
    return 0;
}