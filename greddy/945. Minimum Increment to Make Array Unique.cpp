class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int mx = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mx >= nums[i])
            {
                mx++;
                sum += mx - nums[i];
            }
            else
            {
                mx = nums[i];
            }
        }
        return sum;
    }
};