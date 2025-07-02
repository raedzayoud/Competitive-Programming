#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int add = k;
        int remo = 0;
        double mx = sum;
        

        for (int i = add; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[remo];
            remo++;

            mx = max(sum, mx);
        }
        return mx/k;
    }
};