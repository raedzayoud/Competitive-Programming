class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int currSum = 0;
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1; 

        for (int num : nums) {
            currSum += num;

            if (prefixSumFreq.find(currSum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[currSum - k];
            }

            prefixSumFreq[currSum]++;
        }

        return count;
    }
};



