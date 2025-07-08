#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int area1 = 0;
    int area = 0;
    while (left <= right)
    {
        area1 = min(height[left], height[right]) * (right - left);
        if (height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
        area = max(area1, area);
    }
    return area;
}
int main()
{
    vector<int> nums{8, 7, 2, 1};
    cout
        << maxArea(nums);
}