#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int max_sum = gain[0];
    for (int i = 1; i < gain.size(); i++)
    {
        gain[i] += gain[i - 1];
        max_sum = max(gain[i], max_sum);
    }
   return max(max_sum,0);
}

int main()
{
    vector<int> nums{52,-91,72};
    cout << largestAltitude(nums);
}