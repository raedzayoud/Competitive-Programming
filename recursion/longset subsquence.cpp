class Solution {
public:
    int backtrack(vector<int>& nums, int i, int last) {
        if (i == nums.size()) {
            return 0;
        }
        int leave = backtrack(nums, i + 1, last);
        int take = 0;
        if (nums[i] > last) {
            take = backtrack(nums, i + 1, nums[i]) + 1;
        }
        return max(leave, take);
    }
    int lengthOfLIS(vector<int>& nums) { return backtrack(nums, 0, INT_MIN); }
};