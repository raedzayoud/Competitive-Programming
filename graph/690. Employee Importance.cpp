/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int count = 0;
    map<int, Employee *> mp;
    void dfs(int id)
    {
        Employee *v = mp[id];
        count += v->importance;
        for (int i = 0; i < v->subordinates.size(); i++)
        {
            dfs(v->subordinates[i]);
        }
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto e : employees)
        {

            mp[e->id] = e;
        }

        dfs(id);
        return count;
    }
};