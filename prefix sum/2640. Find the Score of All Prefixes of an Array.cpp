#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

vector<long long> findPrefixScore(vector<int> &nums)
{
    vector<long long> v;
    vector<long long> v1(nums.size());
    v1[0]=nums[0] + nums[0];
    long long sum = 0;
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        res=max(res,nums[i]);
        sum += nums[i] + res + v1[i - 1];
        v1[i]=sum;
        sum = 0;
    }
    return v1;
}
int main()
{
    vector<int>nums={2,3,7,5,10};
    vector<long long> a = findPrefixScore(nums);
    cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}