class Solution {
public:
   
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0;
        int res=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]%2;
            if(mp.find(sum-k)!=mp.end()){
               res+=mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};