#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        int ctn=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty()&& st.top()=='[' && s[i]==']'){
                st.pop();
            }
            else{
                ctn++;
            }
        }
        cout<<ctn;
        if(ctn%2==0){
            return ctn/2;
        }
        else{
            return (ctn+1)/2;
        }
    }
};