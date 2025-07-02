class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        vector<int> right = nums;
        vector<int> left = nums;
        left.pop_back();
        for (int i = 1; i < left.size(); i++)
        {
            left[i] += left[i - 1];
        }
        left.insert(left.begin(), 0);
        reverse(right.begin(), right.end());
        right.pop_back();
        for (int i = 1; i < right.size(); i++)
        {
            right[i] += right[i - 1];
        }
        reverse(right.begin(), right.end());
        right.push_back(0);
        vector<int> res;
        for (int i = 0; i < left.size(); i++)
        {
            res.push_back(abs(left[i] - right[i]));
        }

        return res;
    }
};