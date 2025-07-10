class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j <= k) {
                if (i != j && i != k && j != k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        v1.push_back(nums[i]);
                        v1.push_back(nums[j]);
                        v1.push_back(nums[k]);
                        v.push_back(v1);
                        k--;
                        j++;
                        v1.clear();
                    } else if (nums[i] + nums[j] + nums[k] > 0) {
                        k--;
                    } else if (nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    }
                } else {
                    break;
                }
            }
        }
        set<vector<int>> st;
        for (vector<int> c : v) {
            st.insert(c);
        }
        v.clear();
        for (auto a : st) {
            v.push_back(a);
        }
        return v;
    }
};