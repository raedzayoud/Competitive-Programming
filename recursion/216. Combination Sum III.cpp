class Solution
{
public:
    void backtrack(vector<vector<int>> &v, int k, vector<int> &candidates,
                   int n, int sum, int start)
    {
        if (candidates.size() == k && sum == n)
        {
            v.push_back(candidates);
            return;
        }
        for (int i = start; i < 10; i++)
        {
            candidates.push_back(i);
            backtrack(v, k, candidates, n, sum + i, i + 1);
            candidates.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> v;
        vector<int> candidates;
        backtrack(v, k, candidates, n, 0, 1);
        return v;
    }
};