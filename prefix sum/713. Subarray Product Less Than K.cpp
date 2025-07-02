#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for std::max

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int left=0;
      int right=0;
      int prod=1;
      int result=0;
      while(right<nums.size()){ 
          prod*=nums[right];
          while(prod>=k &&  left <= right){
            prod= prod/ nums[left];
            left++;
          }
          result+=(right-left+1);
          cout<<result<<" ";
          right++;
      }
      return result;
    }

int main()
{
    vector<int> nums{10,5,2,6};
    cout << numSubarrayProductLessThanK(nums, 100);
}