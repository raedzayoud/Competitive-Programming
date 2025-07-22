class Solution
{
public:
    int backtrack(vector<int> &nums, int target, int sum, int start)
    {
        if (nums.size() == start)
        {
            if (sum == target)
            {
                return 1;
            }
            return 0;
        }

        int neg = backtrack(nums, target, sum + (-1 * nums[start]), start + 1);
        int pos = backtrack(nums, target, sum + (nums[start]), start + 1);
        return neg + pos;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return backtrack(nums, target, 0, 0);
    }
};