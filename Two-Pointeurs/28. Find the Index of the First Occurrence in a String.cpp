class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int index = -1;

        for (int i = 0; i < haystack.size(); i++)
        {
            bool test = false;
            if (haystack[i] == needle[0])
            {
                int j = i;
                int o = 0;
                while (j < j + needle.size() && o < needle.size())
                {
                    if (haystack[j] != needle[o])
                    {
                        test = true;
                        break;
                    }
                    j++;
                    o++;
                }
                if (!test)
                {
                    index = i;
                    return index;
                    break;
                }
            }
        }
        return index;
    }
};