#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int ctnopen=0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } 
            else{
              if(!st.empty()){
                st.pop();
              }
              else{
                ctnopen++;
              }
            }
        }
        return st.size()+ctnopen;
    }
};