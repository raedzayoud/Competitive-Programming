class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        vector<int> v(nums.size());
        v = nums;
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        reverse(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++)
        {
            v[i] += v[i - 1];
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == nums[i])
            {
                return i;
            }
        }
        return -1;
    }
};