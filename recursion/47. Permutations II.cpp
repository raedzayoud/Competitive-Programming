class Solution {
public:
    void backtrack(vector<vector<int>>& v, vector<int> res,
                   vector<int>& candidates, vector<bool>& test) {

        if (res.size() == candidates.size()) {
            v.push_back(res);
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            if (test[i]) {
                continue;
            }
            test[i] = true;
            res.push_back(candidates[i]);
            backtrack(v, res, candidates, test);
            test[i] = false;
            res.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> res;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        backtrack(result, res, nums, used);

        set<vector<int>> unique_result;
        for (auto& vec : result) {
            unique_result.insert(vec);
        }

        return vector<vector<int>>(unique_result.begin(), unique_result.end());
    }
};