#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int countPartitions(vector<int> &nums)
{
    int sumLeft = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sumLeft += nums[i];
        int sumRight = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            sumRight += nums[j];
        }
        if (i + 1 < nums.size())
        {

            if ((sumLeft - sumRight) % 2 == 0)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums{1,2,2};
    cout << countPartitions(nums);
}