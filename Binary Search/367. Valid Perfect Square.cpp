#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

bool isPerfectSquare(int num)
{
    int left = 0;
    int right = num;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (mid * mid == num)
        {
            return true;
        }
        else if (mid * mid < num)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return false;
}
int main()
{
    vector<int> nums{100, 40, 17, 9, 73, 75};
    cout << isPerfectSquare(16);
}