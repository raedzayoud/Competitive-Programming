#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void backtrak(vector<vector<int>> &v, vector<int> v1,vector<int>& v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        v2.push_back(v1[i]);
        v.push_back(v2);
        backtrak(v, v1,v2);
        v2.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> v1;
    vector<int> v2;
    backtrak(v1, nums,v2);
    return v1;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsetsResult = subsets(nums);

    cout << "Subsets of [1, 2, 3]:" << endl;
    for (auto subset : subsetsResult)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i)
        {
            cout << subset[i];
            if (i != subset.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}