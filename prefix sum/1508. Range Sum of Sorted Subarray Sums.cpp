#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int rangeSum(vector<int> &nums, int n, int left, int right)
{
    vector<int> v;
   // v.push_back(nums[0]);
    const int MOD = 1e9 + 7;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            v.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    long long sum = 0;
    for (int i = left == 0 ? 0 : left - 1; i < right; i++)
    {
        if (i >= v.size())
        {
            break;
        }
        sum = (sum + v[i]) % MOD;
    }
    return sum;
}
int main()
{
    vector<int> nums{1, 2, 3, 4};
    cout << rangeSum(nums, nums.size(), 1, 5);
}