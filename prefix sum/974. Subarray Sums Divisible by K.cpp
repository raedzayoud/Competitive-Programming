class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = ((sum % k)+k)%k;// to handle the negative number
            if (mp.find(ans) != mp.end()) {
                res += mp[ans];
            }
            mp[ans]++;
        }
        return res;
    }
};