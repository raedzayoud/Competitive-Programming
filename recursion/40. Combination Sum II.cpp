class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& temp,
                   vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // skip dublication
            if(i>start && candidates[i]==candidates[i-1])continue;
            if (candidates[i] > target) {
                break;
            }
            temp.push_back(candidates[i]);
            backtrack(result, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); 
        backtrack(result, temp, candidates, target, 0);
        return result;
    }
};