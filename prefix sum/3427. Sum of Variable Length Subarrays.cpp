#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int subarraySum(vector<int> &nums)
{
    int sum = 0;
    int start = 0;
    for (int j = 0; j < nums.size();j++)
    {
        start = max(0, j - nums[j]);
        for (int i = start; i <= j; i++)
        {
            sum += nums[i];
        }
       // j++;
    }
    return sum;
}

int main()
{
    vector<int> nums{2, 5, 1, 5};
    cout << subarraySum(nums);
}