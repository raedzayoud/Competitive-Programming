#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &v, vector<int> res,
                   vector<int> &candidates, int target, int sum, int start)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            v.push_back(res);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            sum += candidates[i];
            res.push_back(candidates[i]);

            backtrack(v, res, candidates, target, sum, i); // i (not i+1) to reuse same number
            res.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> res;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        backtrack(result, res, nums, used);

        set<vector<int>> unique_result;
        for (auto &vec : result)
        {
            unique_result.insert(vec);
        }

        return vector<vector<int>>(unique_result.begin(), unique_result.end());
    }
};

int main()
{
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> combinations = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto &combo : combinations)
    {
        cout << "[ ";
        for (int num : combo)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
