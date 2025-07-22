class Solution
{
public:
    string solve(vector<string> &nums, string s)
    {
        if (s.size() == nums.size())
        {
            if (find(nums.begin(), nums.end(), s) == nums.end())
            {
                return s;
            }
            return "";
        }
        string addbyzero = solve(nums, s + "0");
        string addbyone = solve(nums, s + "1");
        return max(addbyzero, addbyone);
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        string s;
        return solve(nums, s);
    }
};