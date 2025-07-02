#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int sum = 0;
    // int max_sum=0;
    vector<int> v;
    int reduce = k;
    for (int i = cardPoints.size() - k; i < cardPoints.size(); i++)
    {
        v.push_back(cardPoints[i]);
        reduce--;
        if (reduce == 0)
        {
            break;
        }
    }

    reduce = k;
    for (int i = 0; i < cardPoints.size(); i++)
    {
        v.push_back(cardPoints[i]);
        reduce--;
        if (reduce == 0)
        {
            break;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    int max_sum = sum;
    for (int i = k; i < v.size(); i++)
    {
        sum += v[i];
        sum -= v[i - k];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
int main()
{
    vector<int> nums{100, 40, 17, 9, 73, 75};
    cout << maxScore(nums, 3);
}