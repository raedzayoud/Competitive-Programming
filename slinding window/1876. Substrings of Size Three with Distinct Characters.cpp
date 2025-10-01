class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        string k = "";
        for (int i = 0; i < 3; i++)
        {
            k += s[i];
        }
        int nb = 0;
        map<char, int> mp;
        bool test = false;
        for (int j = 0; j < k.size(); j++)
        {
            mp[k[j]]++;
        }
        for (auto c : mp)
        {
            if (c.second > 1)
            {
                test = true;
            }
        }
        mp.clear();

        if (!test)
        {
            nb++;
        }

        for (int i = 3; i < s.size(); i++)
        {
            test = false;
            k += s[i];
            k.erase(k.begin());
            for (int j = 0; j < k.size(); j++)
            {
                mp[k[j]]++;
            }
            for (auto c : mp)
            {
                if (c.second > 1)
                {
                    test = true;
                }
            }
            if (!test)
            {
                nb++;
            }
            mp.clear();
        }
        return nb;
    }
};