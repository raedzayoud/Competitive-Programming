class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for (int i = 0; i < nums1.size(); i++) {
            v.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            v.push_back(nums2[i]);
        }
        sort(v.begin(), v.end());
        int left = 0;
        int right = v.size() - 1;
        if (v.size() % 2 != 0) {
            return v[right / 2];
        }
        if (v.size() % 2 == 0) {
            return (double)(v[right / 2] + v[(right / 2) + 1]) / 2;
        }
        return 0;
    }
};