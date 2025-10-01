#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int sum = numBottles;
        int empty = numBottles;
        int new_bullet = 0;
        while (empty >= numExchange)
        {
            new_bullet = empty / numExchange;
            sum += new_bullet;
            empty = (empty % numExchange) + new_bullet;
        }

        return sum;
    }
};
int main()
{
    vector<int> nums{8, 7, 2, 1};
    cout
        << numWaterBottles(9, 3);
}