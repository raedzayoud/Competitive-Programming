class Solution {
public:
    
vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    vector<int> result;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }

    for (int i = 0; i < queries.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] <= queries[i]) {
                count = j + 1;
            } else {
                break; 
            }
        }
        result.push_back(count);
    }

    return result;
}
};


