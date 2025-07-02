#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> mp;
        int max_sel = 0;
        mp[0] = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
            {
                nums[i] = -1;
            }
            if (i)
            {
                nums[i] += nums[i - 1];
            }
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = i;
            }
            else
            {
                ans = max(ans, i - mp[nums[i]]);
            }
        }
        return ans;
    }
};