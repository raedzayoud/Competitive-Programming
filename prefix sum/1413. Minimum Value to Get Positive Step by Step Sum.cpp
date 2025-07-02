class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
            min_sum = min(min_sum, nums[i]);
        }
        return min_sum < 0 ? (1 - (min_sum)) : min_sum > 1 ? 1 : 1;
    }
};