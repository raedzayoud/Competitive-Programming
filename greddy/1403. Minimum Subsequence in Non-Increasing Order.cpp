#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> minSubsequence(vector<int> &nums)
{
    vector<int> a;
    vector<int> v = nums;
    sort(v.begin(), v.end());
    sort(nums.begin(), nums.end(), greater<int>());
    int i = 0;
    int j = 0;
    int sum = 0;
    int sum1 = 0;
    while (i < nums.size())
    {
        sum += nums[i];
        while (j < v.size() - i - 1)
        {
            sum1 += v[j];
            j++;
        }
        j = 0;

        if (sum == sum1)
        {
            a.push_back(nums[i]);
            sum1 = 0;
            i++;
            continue;
        }

        if (sum > sum1)
        {
            a.push_back(nums[i]);
            break;
        }
        sum1 = 0;
        a.push_back(nums[i]);

        i++;
    }
    return a;
}

int main()
{
    vector<int> nums = {4, 4, 7, 6, 7};
    vector<int> result = minSubsequence(nums);
    for (int n : result)
        cout << n << " ";
    cout << endl;
    return 0;
}