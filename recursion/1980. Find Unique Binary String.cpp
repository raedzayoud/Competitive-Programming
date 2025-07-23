// Recursion
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

// Backtracking

class Solution
{
public:
    bool solve(vector<string> &nums, string &s)
    {
        if (s.size() == nums.size())
        {
            return find(nums.begin(), nums.end(), s) == nums.end();
        }
        s.push_back('0');
        if (solve(nums, s))
        {
            return true;
        }
        s.pop_back();

        s.push_back('1');
        if (solve(nums, s))
        {
            return true;
        }
        s.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        string s;
        solve(nums, s);
        return s;
    }
};