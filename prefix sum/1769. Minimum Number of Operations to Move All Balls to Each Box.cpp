#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

vector<int> minOperations(string boxes)
{
    vector<int> v;
    vector<int> ans;
    for (int i = 0; i < boxes.size(); i++)
    {
        if (boxes[i] == '1')
        {
            v.push_back(i);
        }
    }
    // brute force valeu absolue
    for (int i = 0; i < boxes.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < v.size(); j++)
        {
            sum += abs(v[j] - i);
        }
        ans.push_back(sum);
    }
    return ans;
}
int main()
{
    string s = "110";
    vector<int> a = minOperations(s);
    cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}