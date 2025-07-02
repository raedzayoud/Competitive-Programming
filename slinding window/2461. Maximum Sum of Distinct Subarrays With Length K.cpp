class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long max_sum = 0;
        map<int, int> mp;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            sum += nums[i];

            while (mp[nums[i]] > 1 || (i - left + 1) > k) {
                sum -= nums[left];
                mp[nums[left]]--;
                left++;
            }
            if ((i - left + 1) == k) {
                max_sum = max(sum, max_sum);
            }
        }
        return max_sum;
    }
};