#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MAX;
        bool x = false;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target)
            {
                ans = min(right - left + 1, ans);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return ans == 2147483647 ? 0 : ans;
    }
};
