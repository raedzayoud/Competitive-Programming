class Solution {
public:
    void Backtrack(vector<vector<int>>& v1, int n, vector<int>& v, int start,
                   int k) {
        for (int i = start; i <= n; i++) {
            v.push_back(i);
            if (v.size() > k) {
                v.pop_back();
                return;
            }
            if (v.size() == k) {
                v1.push_back(v);
            }
            Backtrack(v1, n, v, i + 1, k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v1;
        vector<int> v;
        Backtrack(v1, n, v, 1, k);
        return v1;
    }
};