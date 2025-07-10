class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum=0;
        for(vector<int>c:grid){
            for(int i=0;i<c.size();i++){
                if(c[i]<0){
                  sum+=c.size()-i;
                  break;
                }
            }
        }
        return sum;
    }
};