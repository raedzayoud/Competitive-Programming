class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> v(nums.size());
        int res = nums[0];
        v[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            v[i] = max(nums[i], nums[i] + v[i - 1]);
            res = max(res, v[i]);
        }
        return res;
    }
};