class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);
        vector<int> hashP(26, 0);
        if (s1.size() > s2.size())
            return false;
        for (int i = 0; i < s1.size(); i++) {
            hash[s1[i] - 'a']++;
            hashP[s2[i] - 'a']++;
        }
        if (hash == hashP) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            hashP[s2[i] - 'a']++;
            hashP[s2[i-s1.size()] - 'a']--;
            if (hashP == hash) {
                return true;
            }
        }
        return false;
    }
};