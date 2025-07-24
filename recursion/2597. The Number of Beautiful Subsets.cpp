class Solution
{
public:
    void backtrack(vector<int> &nums, int k, int &count, int index,
                   map<int, int> &mp)
    {
        if (index == nums.size())
        {
            return;
        }
        backtrack(nums, k, count, index + 1, mp);
        if (mp[nums[index] - k] == 0 && mp[nums[index] + k] == 0)
        {
            mp[nums[index]]++;
            count++;
            backtrack(nums, k, count, index + 1, mp);
            mp[nums[index]]--;
        }
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {
        vector<int> v;
        map<int, int> mp;
        int count = 0;
        backtrack(nums, k, count, 0, mp);
        return count;
    }
};