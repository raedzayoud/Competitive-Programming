class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> v(34, vector<int>(0));
        for (int i = 0; i < 34; i++)
        {
            v[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v[rowIndex];
    }
};