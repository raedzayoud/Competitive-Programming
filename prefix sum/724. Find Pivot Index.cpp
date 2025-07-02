#include <algorithm>
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        std::reverse(arr.begin(), arr.end());
    }

    int pivotIndex(vector<int>& nums) {
        vector<int> v = nums;
        vector<int> v1 = nums;
        reverseArray(v1);
        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
        for (int i = 1; i < v1.size(); i++) {
            v1[i] += v1[i - 1];
        }
        reverseArray(v1);
        for (int i = 0; i < v.size(); i++) {
            int left = (i > 0) ? v[i - 1] : 0;
            int right = (i < v1.size() - 1) ? v1[i + 1] : 0;
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};