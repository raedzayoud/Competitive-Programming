class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        vector<string> v;
        string s = "";
        int nb = 0;
        bool test = false;
        for (int i = 0; i < text.size(); i++)
        {
            s += text[i];
            if (brokenLetters.find(text[i]) != string::npos)
            {
                test = true;
            }
            if (text[i] == ' ')
            {
                if (test)
                {
                    nb++;
                    test = false;
                }
                v.push_back(s);
                s = "";
                continue;
            }
        }
        if (test)
        {
            nb++;
            test = false;
        }
        v.push_back(s);
        return v.size() - nb;
    }
};