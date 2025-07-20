class Solution {
public:
    void backtrack(vector<vector<int>>& v, vector<int> res,
                   vector<int>& candidates,vector<bool>&test) {

        if (res.size() == candidates.size()) {
            v.push_back(res);
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            if(test[i]){
                continue;
            }
            test[i]=true;
            res.push_back(candidates[i]);
            backtrack(v, res, candidates,test);
            test[i]=false;
            res.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<bool> test(nums.size(),false);
        vector<vector<int>> v;
        backtrack(v, res, nums,test);
        return v;
    }
};