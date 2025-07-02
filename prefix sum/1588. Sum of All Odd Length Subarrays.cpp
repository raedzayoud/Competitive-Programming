class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int asnwer = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                sum += arr[j];
                asnwer += ((j - i) % 2 == 0) ? sum : 0;
            }
            sum = 0;
        }
        return asnwer;
    }
};