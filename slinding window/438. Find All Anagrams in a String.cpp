#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) {
            return ans;
        }
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        for (int i = 0; i < p.size(); i++) {
            hash[p[i] - 'a']++;
            phash[s[i] - 'a']++;
        }
        if (hash == phash) {
            ans.push_back(0);
        }
        for (int i = p.size(); i < s.size(); i++) {
            phash[s[i] - 'a']++;
            phash[s[i - p.size()] - 'a']--;
            if (hash == phash) {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};