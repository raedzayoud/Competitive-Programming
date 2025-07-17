class Solution {
public:
    void backtrack(set<vector<int>>& resultSet, vector<int>& nums,
                   vector<int>& subset, int start) {
        resultSet.insert(subset); 

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(resultSet, nums, subset, i + 1);
            subset.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        set<vector<int>> resultSet;
        vector<int> subset;

        backtrack(resultSet, nums, subset, 0);

        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};